import argparse
from pathlib import Path

from lz import *


NESTROID_ROM_COMP_END_PTR_ADDR = 0x7D80CC

NESTROID_ROM_COMP_SIZE = 0x16437
NESTROID_ROM_DECOMP_SIZE = 0x20000
NESTROID_ROM_INES_HEADER = bytes([int(b, 16) for b in "4E 45 53 1A 08 00 11 00 00 00 4E 49 20 31 2E 33".split()])


def extract_rom(zm_path):
    with open(zm_path, "rb") as f:
        f.seek(NESTROID_ROM_COMP_END_PTR_ADDR)
        nestroid_rom_comp_end_addr = int.from_bytes(f.read(4), byteorder='little') - 0x08000000
        f.seek((nestroid_rom_comp_end_addr - NESTROID_ROM_COMP_SIZE) & 0xfffffc)
        comp_bytes = f.read(NESTROID_ROM_COMP_SIZE)
    
    decomp_bytes, comp_size = decomp_lz_custom(comp_bytes, 0, NESTROID_ROM_DECOMP_SIZE)
    
    return decomp_bytes, comp_bytes


def save_rom(output_path, decomp_bytes):
    decomp_bytes_headered = NESTROID_ROM_INES_HEADER + decomp_bytes
    
    with open(args.output_path, "wb") as f:
        f.write(decomp_bytes_headered)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("zm_path", type=str, help="Path to a Zero Mission ROM")
    parser.add_argument("output_path", type=str, help="Path where output NES ROM should be written")
    
    args = parser.parse_args()
    
    decomp_bytes, comp_bytes = extract_rom(args.zm_path)
    save_rom(args.output_path, decomp_bytes)
    
