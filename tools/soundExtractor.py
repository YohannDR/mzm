from io import BufferedReader
import os

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
    return


def Func():
    addr: int = 0x8f2c0
    file.seek(addr)
    
    ExtractVoiceGroups(file)

Func()
