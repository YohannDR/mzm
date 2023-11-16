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
    0x8dbac,
    0x8ddec,
    0x8dfc0,
    0x8e3a4,
    0x8e77c,
    0x8f070,
]

voiceGroupsSizes = [
    103,
    61,
    97,
    48,
    39,
    83,
    82,
    191,
    39
]

extractedSamples = [
    0x8f244
]

def ExtractVoiceGroups(f: BufferedReader):
    for x in range(0, len(voiceGroupsAddr)):
        f.seek(voiceGroupsAddr[x])

        name: str = "voice_group" + str(x)
        output = open("../audio/voice_groups/" + name + ".s", "w")
        content = ".align 4\n\n.section .rodata\n.global " + name + "\n\n" + name + ":\n"

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
            
            #if sample < 0:
            content += ".word " + str(sample + 0x8000000) +"\n\t"
            #else:
            #    content += ".word sample_" + hex(sample) + "\n\t"
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

def Func():
    # TODO use sample symbols in voice groups
    ExtractSamples(file)

Func()
