from typing import Tuple, Optional


MIN_MATCH_SIZE = 2
MIN_WINDOW_SIZE = 1

MAX_MATCH_SIZE = (1 << 8) - 1 + 0x10 + MIN_MATCH_SIZE
MAX_WINDOW_SIZE = (1 << 12) - 1 + MIN_WINDOW_SIZE


def decomp_lz_custom(src: bytes, idx: int, decomp_size: int) -> Tuple[bytes, int]:
    output = bytearray(decomp_size)

    start = idx
    dst = 0

    while (True):
        cflag = src[idx]
        idx += 1

        for _ in range(8):
            if (cflag & 0x80) != 0:
                # Uncompressed
                output[dst] = src[idx]
                idx += 1
                dst += 1
            else:
                # Compressed
                amount_to_copy = (src[idx] >> 4)
                window = ((src[idx] & 0xF) << 8) + src[idx + 1] + 1
                idx += 2
                if amount_to_copy == 0:
                    amount_to_copy = 0x10 + src[idx]
                    idx += 1
                amount_to_copy += MIN_MATCH_SIZE

                for _ in range(amount_to_copy):
                    output[dst] = output[dst - window]
                    dst += 1

            if dst >= decomp_size:
                if dst > decomp_size:
                    raise ValueError("Too many bytes copied at end")
                comp_size = idx - start
                return bytes(output), comp_size
            cflag <<= 1


# svc #$11
def decomp_lz_bios(src: bytes, idx: int) -> Tuple[bytes, int]:
    magic = src[idx]
    assert magic == 0x10
    
    decomp_size = int.from_bytes(src[idx+1:idx+4], byteorder='little', signed=True)
    
    output = bytearray(decomp_size)

    start = idx
    dst = 0
    
    idx += 4

    while (True):
        cflag = src[idx]
        idx += 1

        for _ in range(8):
            if (cflag & 0x80) == 0:
                # Uncompressed
                output[dst] = src[idx]
                idx += 1
                dst += 1
            else:
                # Compressed
                amount_to_copy = (src[idx] >> 4) + 3
                window = ((src[idx] & 0xF) << 8) + src[idx + 1] + 1
                idx += 2

                for _ in range(amount_to_copy):
                    output[dst] = output[dst - window]
                    dst += 1

            if dst >= decomp_size:
                if dst > decomp_size:
                    raise ValueError("Too many bytes copied at end")
                comp_size = idx - start
                return bytes(output), comp_size
            cflag <<= 1


def find_longest_match_custom(decomp_bytes: bytes, i: int, triplets: dict[int, list[int]]) -> Optional[tuple[int, int]]:
    decomp_size = len(decomp_bytes)
    if i > decomp_size - 3:
        return None

    # Get triplet at current position
    triplet = decomp_bytes[i] | (decomp_bytes[i + 1] << 8) | (decomp_bytes[i + 2] << 16)

    # Check if triplet has no match
    indexes = triplets.get(triplet)
    if indexes is None:
        triplets[triplet] = [i]
        return None

    window_start = max(i - MAX_WINDOW_SIZE, 0)
    max_size = min(MAX_MATCH_SIZE, decomp_size - i)
    longest_len = 0
    longest_idx = -1

    j = 0
    # Try each index to find the longest match
    while j < len(indexes):
        idx = indexes[j]
        # remove if past window
        if idx < window_start:
            indexes.pop(j)
            # dont inc j
            continue

        # Find length of match
        match_len = 3
        while match_len < max_size:
            if decomp_bytes[idx + match_len] != decomp_bytes[i + match_len]:
                break
            match_len += 1
        
        # Update longest match
        if match_len > longest_len:
            longest_len = match_len
            longest_idx = idx

            # Stop looking if max size
            if longest_len == max_size:
                break
        
        j += 1

    indexes.append(i)
    if longest_len >= 3:
        return (longest_len, longest_idx)

    return None


def comp_lz_custom(decomp_bytes: bytes) -> bytes:
    # Assumes input stream starts at 0
    decomp_size = len(decomp_bytes)
    idx = 0
    triplets: dict[int, list[int]] = {}

    output = bytearray()

    _match_next = None

    while idx < decomp_size:
        # Get index of new compression flag
        flag = len(output)
        output.append(0)

        for i in range(8):
            if _match_next is not None:
                _match = _match_next
                _match_next = None
            else:
                # Find longest match at current position
                _match = find_longest_match_custom(decomp_bytes, idx, triplets)
                
                if _match is not None:
                    match_len, _ = _match
                    
                    _match_next = find_longest_match_custom(decomp_bytes, idx+1, triplets)

                    if _match_next is not None:
                        match_next_len, _ = _match_next
                        # for match_next to be better than match, its length must be better 
                        # even while compensating for the uncompressed byte instruction before it
                        if match_next_len - (1 + 1/8) > match_len:
                            _match = None
                        else:
                            _match_next = None

            if _match is not None:
                # Compressed
                match_len, match_idx = _match

                for j in range(idx+1, min(idx+match_len, decomp_size-3+1)):
                    # Get triplet at current position
                    triplet = decomp_bytes[j] | (decomp_bytes[j + 1] << 8) | (decomp_bytes[j + 2] << 16)

                    # Check if triplet has no match
                    indexes = triplets.get(triplet)
                    if indexes is None:
                        triplets[triplet] = [j]
                    else:
                        indexes.append(j)
                
                match_offset = idx - match_idx - MIN_WINDOW_SIZE
                if match_len - MIN_MATCH_SIZE < 0x10:
                    output.append(((match_len - MIN_MATCH_SIZE) << 4) | (match_offset >> 8))
                    output.append(match_offset & 0xFF)
                else:
                    output.append(match_offset >> 8)
                    output.append(match_offset & 0xFF)
                    output.append(match_len - 0x10 - MIN_MATCH_SIZE)
                idx += match_len
            else:
                # Uncompressed
                output.append(decomp_bytes[idx])
                idx += 1
                output[flag] |= 0x80 >> i

            # Check if at end
            if idx >= decomp_size:
                return bytes(output)
    
    raise Exception("LZ77 compression error")


def find_longest_match_bios(decomp_bytes: bytes, i: int, triplets: dict[int, list[int]]) -> Optional[tuple[int, int]]:
    decomp_size = len(decomp_bytes)
    if i > decomp_size - 3:
        return None

    # Get triplet at current position
    triplet = decomp_bytes[i] | (decomp_bytes[i + 1] << 8) | (decomp_bytes[i + 2] << 16)

    # Check if triplet has no match
    indexes = triplets.get(triplet)
    if indexes is None:
        triplets[triplet] = [i]
        return None

    window_start = max(i - (0xFFF + 1), 0)
    max_size = min(15 + 3, decomp_size - i)
    longest_len = 0
    longest_idx = -1

    # Skip first index if one byte behind current position
    # (why? can't repeat 1 byte over and over unless you write it twice?)
    # (strangely yes, confirmed in bios compressed files)
    j = len(indexes) - 1
    if indexes[j] >= i - 1:
        j -= 1

    # Try each index to find the longest match
    while j >= 0:
        idx = indexes[j]
        # Stop if past window
        if idx < window_start:
            break

        # Find length of match
        match_len = 3
        while match_len < max_size:
            if decomp_bytes[idx + match_len] != decomp_bytes[i + match_len]:
                break
            match_len += 1
        
        # Update longest match
        if match_len > longest_len:
            longest_len = match_len
            longest_idx = idx

            # Stop looking if max size
            if longest_len == max_size:
                break
        
        j -= 1

    indexes.append(i)
    if longest_len >= 3:
        return (longest_len, longest_idx)

    return None


def comp_lz_bios(decomp_bytes: bytes) -> bytes:
    decomp_size = len(decomp_bytes)
    assert decomp_size <= 0xFFFFFF
    
    # Assumes input stream starts at 0
    idx = 0
    triplets: dict[int, list[int]] = {}

    output = bytearray()
    output.append(0x10)
    output.append(decomp_size & 0xFF)
    output.append((decomp_size >> 8) & 0xFF)
    output.append((decomp_size >> 16) & 0xFF)
    
    while idx < decomp_size:
        # Get index of new compression flag
        flag = len(output)
        output.append(0)

        for i in range(8):
            # Find longest match at current position
            _match = find_longest_match_bios(decomp_bytes, idx, triplets)
            if _match is not None:
                # Compressed
                match_len, match_idx = _match

                for j in range(idx+1, min(idx+match_len, decomp_size-3+1)):
                    # Get triplet at current position
                    triplet = decomp_bytes[j] | (decomp_bytes[j + 1] << 8) | (decomp_bytes[j + 2] << 16)

                    # Check if triplet has no match
                    indexes = triplets.get(triplet)
                    if indexes is None:
                        triplets[triplet] = [j]
                    else:
                        indexes.append(j)
                
                match_offset = idx - match_idx - 1
                
                output.append(((match_len - 3) << 4) | (match_offset >> 8))
                output.append(match_offset & 0xFF)
                
                idx += match_len
                output[flag] |= 0x80 >> i
            else:
                # Uncompressed
                output.append(decomp_bytes[idx])
                idx += 1

            # Check if at end
            if idx >= decomp_size:
                return bytes(output)
    
    raise Exception("LZ77 compression error")


