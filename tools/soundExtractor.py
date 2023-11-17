from io import BufferedReader
import os
import shutil

file: BufferedReader = open("../mzm_us_baserom.gba", "rb")

def ReadPtr(f: BufferedReader) -> int:
    value: int = int.from_bytes(f.read(4), "little")
    return value - 0x8000000

voiceGroupsAddr = [
    0x8cf70,
    0x8d444,
    0x8d720,
    0x8d8f4,
    0x8dbac,
    0x8ddec,
    0x8df24,
    0x8dfc0,
    0x8e038,
    0x8e098,
    0x8e164,
    0x8e26c,
    0x8e320,
    0x8e3a4,
    0x8e4ac,
    0x8e59c,
    0x8e5d8,
    0x8e698,
    0x8e77c,
    0x8e920,
    0x8eae8,
    0x8f004,
    0x8f070,
]

voiceGroupsSizes = [
    103,
    61,
    39,
    58,
    48,
    26,
    13,
    10,
    8,
    17,
    22,
    15,
    11,
    22,
    20,
    5,
    16,
    19,
    35,
    38,
    109,
    9,
    39
]

extractedSamples = [
    0x8f244
]

def ExtractVoiceGroups(f: BufferedReader):
    for x in range(0, len(voiceGroupsAddr)):
        f.seek(voiceGroupsAddr[x])

        name: str = "voice_group" + str(x)

        filePath: str = "../audio/voice_groups/" + name + ".s"

        if os.path.exists(filePath):
            os.remove(filePath)

        output = open(filePath, "w")
        content = ".align 2\n\n.section .rodata\n.global " + name + "\n\n" + name + ":\n"

        for y in range(0, voiceGroupsSizes[x]):
            instrType: int = int.from_bytes(f.read(1), "little")
            pitch: int = int.from_bytes(f.read(1), "little")
            unk_2: int = int.from_bytes(f.read(1), "little")
            unk_3: int = int.from_bytes(f.read(1), "little")
            sample: int = ReadPtr(f)
            attack: int = int.from_bytes(f.read(1), "little")
            decay: int = int.from_bytes(f.read(1), "little")
            sustain: int = int.from_bytes(f.read(1), "little")
            release: int = int.from_bytes(f.read(1), "little")

            content += "\t.byte " + str(instrType) + ", " + str(pitch) + ", " + str(unk_2) + ", " + str(unk_3) + "\n\t"
            
            if sample < 0:
                content += ".word " + str(sample + 0x8000000) +"\n\t"
            else:
                content += ".word sample_" + hex(sample) + "\n\t"
            content += ".byte " + str(attack) + ", " + str(decay) + ", " + str(sustain) + ", " + str(release) + "\n\n"

        output.write(content)
        output.close()

def ExtractSample(f: BufferedReader, addr: int):
    if addr <= 0:
        return
    
    if addr in extractedSamples:
        return
    
    extractedSamples.append(addr)
    
    f.seek(addr)

    name: str = "sample_" + hex(addr)
    filePath: str = "../audio/samples/" + name + ".s"

    if os.path.exists(filePath):
        os.remove(filePath)

    output = open(filePath, "w")
    content = ".align 2\n\n.section .rodata\n.global " + name + "\n\n" + name + ":\n"

    content += "\t.byte " + str(int.from_bytes(f.read(1), "little")) + "\n"
    content += "\t.byte " + str(int.from_bytes(f.read(1), "little")) + "\n"
    content += "\t.byte " + str(int.from_bytes(f.read(1), "little")) + "\n"
    content += "\t.byte " + str(int.from_bytes(f.read(1), "little")) + "\n"
    content += "\t.word " + str(int.from_bytes(f.read(4), "little")) + "\n"
    content += "\t.word " + str(int.from_bytes(f.read(4), "little")) + "\n"
    size: int = int.from_bytes(f.read(4), "little") + 1
    content += "\t.word " + str(size - 1) + "\n"

    data: bytearray = bytearray(f.read(size))
    # print(data)

    size8: int = size // 8

    for x in range(0, size8):
        content += "\t.byte " + str(data[x * 8 + 0]) + ", " + str(data[x * 8 + 1]) + ", " + str(data[x * 8 + 2]) + ", " + str(data[x * 8 + 3]) + ", " + str(data[x * 8 + 4]) + ", " + str(data[x * 8 + 5]) + ", " + str(data[x * 8 + 6]) + ", " + str(data[x * 8 + 7]) + "\n"

    content += "\t.byte "

    remaining: int = size % 8
    for x in range(0, remaining):
        content += str(data[size8 * 8 + x])
        if x != remaining - 1:
            content += ", "

    content += "\n\n.align 2\n"
    output.write(content)
    output.close()

def ExtractSamples(f: BufferedReader):
    addr: int = 0x8cf70

    f.seek(addr)

    for x in range(0, 743):
        f.read(4)

        currAddr: int = f.tell()
        ExtractSample(f, ReadPtr(f))

        f.seek(currAddr + 4)
        f.read(4)

    v = sorted(extractedSamples)
    for x in range(0, len(v)):
        print(hex(v[x]))

def ExtractSoundHeader(f: BufferedReader, addr: int, number: int):
    f.seek(addr)

    name: str = "track_" + str(number)
    filePath: str = "../audio/tracks/" + name + ".s"

    if os.path.exists(filePath):
        os.remove(filePath)

    output = open(filePath, "w")
    content = ".align 2\n\n.section .rodata\n.global " + name + "\n\n"

    nbrTracks: int = int.from_bytes(f.read(1), "little")
    unk_1: int = int.from_bytes(f.read(1), "little")
    priority: int = int.from_bytes(f.read(1), "little")
    echoFeedBack: int = int.from_bytes(f.read(1), "little")
    voice: int = ReadPtr(f)

    for x in range(0, nbrTracks):
        prevAddr: int = f.tell()
        ptr: int = ReadPtr(f)

        f.seek(ptr)
        content += name + "_" + str(x) + ":\n"

        value: int = int.from_bytes(f.read(1), "little")
        values = []

        while value != 0xB1 and value != 0xB6:
            values.append(value)
            value = int.from_bytes(f.read(1), "little")

        values.append(value)
        size8: int = len(values) // 8

        for y in range(0, size8):
            content += "\t.byte " + str(values[y * 8 + 0]) + ", " + str(values[y * 8 + 1]) + ", " + str(values[y * 8 + 2]) + ", " + str(values[y * 8 + 3]) + ", " + str(values[y * 8 + 4]) + ", " + str(values[y * 8 + 5]) + ", " + str(values[y * 8 + 6]) + ", " + str(values[y * 8 + 7]) + "\n"

        content += "\t.byte "

        remaining: int = len(values) % 8
        for y in range(0, remaining):
            content += str(values[size8 * 8 + y])
            if y != remaining - 1:
                content += ", "

        content += "\n\n"

        f.seek(prevAddr + 4)
    
    content += ".align 2\n\n"
    content += name + ":\n"
    content += "\t.byte " + str(nbrTracks)
    content += "\n\t.byte " + str(unk_1)
    content += "\n\t.byte " + str(priority)
    content += "\n\t.byte " + str(echoFeedBack)

    t: int = 0
    for x in range(0, len(voiceGroupsAddr)):
        if voiceGroupsAddr[x] == voice:
            content += "\n\t.word voice_group" + str(x)
            break
    
        t += 1

    if t == len(voiceGroupsAddr):
        raise Exception("Couldn't find voice group at " + hex(voice) + " ; " + str(number))

    for x in range(0, nbrTracks):
        content += "\n\t.word " + name + "_" + str(x)

    content += "\n\n.align 2\n"

    output.write(content)
    output.close()

existingHeaders = {}

def ExtractTracks(f: BufferedReader):
    output = open("../audio/sound_entries.s", "w")
    content = ".align 2\n\n.section .rodata\n.global sSoundDataEntries\n\nsSoundDataEntries:\n"

    for x in range(0, 708):
        currAddr: int = f.tell()

        addr: int = ReadPtr(f)

        if addr == 0x908e0:
            content += "\n\n\t.word track_0"
        else:
            content += "\n\n\t.word track_" + str(x)
            ExtractSoundHeader(f, addr, x)
            existingHeaders[addr] = x

        f.seek(currAddr + 4)
        
        content += "\n\t.short " + str(int.from_bytes(f.read(2), "little"))
        content += "\n\t.short " + str(int.from_bytes(f.read(2), "little"))

    output.write(content)
    output.close()

    sorted_dict = dict(sorted(existingHeaders.items()))

    for key, value in sorted_dict.items():
        print(value)

def Func():
    addr = 0x8cf70
    file.seek(addr)
    ExtractVoiceGroups(file)

    addr: int = 0x8f2c0
    file.seek(addr)
    
    # ExtractTracks(file)

Func()
