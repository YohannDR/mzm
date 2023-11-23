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

waitCommand = [
    "W00",
    "W01",
	"W02",
	"W03",
	"W04",
	"W05",
	"W06",
	"W07",
	"W08",
	"W09",
	"W10",
	"W11",
	"W12",
	"W13",
	"W14",
	"W15",
	"W16",
	"W17",
	"W18",
	"W19",
	"W20",
	"W21",
	"W22",
	"W23",
	"W24",
	"W28",
	"W30",
	"W32",
	"W36",
	"W40",
	"W42",
	"W44",
	"W48",
	"W52",
	"W54",
	"W56",
	"W60",
	"W64",
	"W66",
	"W68",
	"W72",
	"W76",
	"W78",
	"W80",
	"W84",
	"W88",
	"W90",
	"W92",
	"W96",
]

codeCommands = [
    "FINE", # 0xb1
    "GOTO", # 0xb2
    "PATT", # 0xb3
    "PEND", # 0xb4
    "REPT", # 0xb5
    "0xB6", # 0xb6
    "0xB7", # 0xb7
    "0xB8", # 0xb8
    "MEMACC", # 0xb9
    "PRIO", # 0xba
    "TEMPO", # 0xbb
    "KEYSH", # 0xbc
    "VOICE", # 0xbd
    "VOL", # 0xbe
    "PAN", # 0xbf
    "BEND", # 0xc0
    "BENDR", # 0xc1
    "LFOS", # 0xc2
    "LFODL", # 0xc3
    "MOD", # 0xc4
    "MODT", # 0xc5
    "0xc6", # 0xc6
    "0xc7", # 0xc7
    "TUNE", # 0xc8
    "0xc9", # 0xc9
    "0xca", # 0xca
    "0xcb", # 0xcb
    "0xcc", # 0xcc
    "XCMD", # 0xcd
    "EOT", # 0xce
]

PARAM_TYPE_NONE = 0
PARAM_TYPE_BYTE = 1
PARAM_TYPE_C_V = 2
PARAM_TYPE_MEM = 3
PARAM_TYPE_MODT = 4
PARAM_TYPE_XCMD = 5
PARAM_TYPE_EOT = 6
PARAM_TYPE_PTR = 7
codeCommandsParamType = [
    PARAM_TYPE_NONE, # FINE
    PARAM_TYPE_PTR, # GOTO
    PARAM_TYPE_PTR, # PATT
    PARAM_TYPE_NONE, # PEND
    PARAM_TYPE_PTR, # REPT
    PARAM_TYPE_NONE, # 0xB6
    PARAM_TYPE_NONE, # 0xB7
    PARAM_TYPE_NONE, # 0xB8
    PARAM_TYPE_MEM, # MEMACC
    PARAM_TYPE_BYTE, # PRIO
    PARAM_TYPE_BYTE, # TEMPO
    PARAM_TYPE_BYTE, # KEYSH
    PARAM_TYPE_BYTE, # VOICE
    PARAM_TYPE_BYTE, # VOL
    PARAM_TYPE_C_V, # PAN
    PARAM_TYPE_C_V, # BEND
    PARAM_TYPE_BYTE, # BENDR
    PARAM_TYPE_BYTE, # LFOS
    PARAM_TYPE_BYTE, # LFODL
    PARAM_TYPE_BYTE, # MOD
    PARAM_TYPE_MODT, # MODT
    PARAM_TYPE_NONE, # 0xc6
    PARAM_TYPE_NONE, # 0xc7
    PARAM_TYPE_C_V, # TUNE
    PARAM_TYPE_NONE, # 0xc9
    PARAM_TYPE_NONE, # 0xca
    PARAM_TYPE_NONE, # 0xcb
    PARAM_TYPE_NONE, # 0xcc
    PARAM_TYPE_XCMD, # XCMD
    PARAM_TYPE_EOT, # EOT
]

memParams = [
    "mem_set",
    "mem_add",
    "mem_sub",
    "mem_mem_set",
    "mem_mem_add",
    "mem_mem_sub",
    "mem_beq",
    "mem_bne",
    "mem_bhi",
    "mem_bhs",
    "mem_bls",
    "mem_blo",
    "mem_mem_beq",
    "mem_mem_bne",
    "mem_mem_bhi",
    "mem_mem_bhs",
    "mem_mem_bls",
    "mem_mem_blo",
]

modtParams = [
    "mod_vib",
    "mod_tre",
    "mod_pan",
]

notesTieEot = [
    "CnM2",
    "CsM2",
    "DnM2",
    "DsM2",
    "EnM2",
    "FnM2",
    "FsM2",
    "GnM2",
    "GsM2",
    "AnM2",
    "AsM2",
    "BnM2",
    "CnM1",
    "CsM1",
    "DnM1",
    "DsM1",
    "EnM1",
    "FnM1",
    "FsM1",
    "GnM1",
    "GsM1",
    "AnM1",
    "AsM1",
    "BnM1",
    "Cn0",
    "Cs0",
    "Dn0",
    "Ds0",
    "En0",
    "Fn0",
    "Fs0",
    "Gn0",
    "Gs0",
    "An0",
    "As0",
    "Bn0",
    "Cn1",
    "Cs1",
    "Dn1",
    "Ds1",
    "En1",
    "Fn1",
    "Fs1",
    "Gn1",
    "Gs1",
    "An1",
    "As1",
    "Bn1",
    "Cn2",
    "Cs2",
    "Dn2",
    "Ds2",
    "En2",
    "Fn2",
    "Fs2",
    "Gn2",
    "Gs2",
    "An2",
    "As2",
    "Bn2",
    "Cn3",
    "Cs3",
    "Dn3",
    "Ds3",
    "En3",
    "Fn3",
    "Fs3",
    "Gn3",
    "Gs3",
    "An3",
    "As3",
    "Bn3",
    "Cn4",
    "Cs4",
    "Dn4",
    "Ds4",
    "En4",
    "Fn4",
    "Fs4",
    "Gn4",
    "Gs4",
    "An4",
    "As4",
    "Bn4",
    "Cn5",
    "Cs5",
    "Dn5",
    "Ds5",
    "En5",
    "Fn5",
    "Fs5",
    "Gn5",
    "Gs5",
    "An5",
    "As5",
    "Bn5",
    "Cn6",
    "Cs6",
    "Dn6",
    "Ds6",
    "En6",
    "Fn6",
    "Fs6",
    "Gn6",
    "Gs6",
    "An6",
    "As6",
    "Bn6",
    "Cn7",
    "Cs7",
    "Dn7",
    "Ds7",
    "En7",
    "Fn7",
    "Fs7",
    "Gn7",
    "Gs7",
    "An7",
    "As7",
    "Bn7",
    "Cn8",
    "Cs8",
    "Dn8",
    "Ds8",
    "En8",
    "Fn8",
    "Fs8",
    "Gn8",
]

notes = [
    "TIE",
    "N01",
    "N02",
    "N03",
    "N04",
    "N05",
    "N06",
    "N07",
    "N08",
    "N09",
    "N10",
    "N11",
    "N12",
    "N13",
    "N14",
    "N15",
    "N16",
    "N17",
    "N18",
    "N19",
    "N20",
    "N21",
    "N22",
    "N23",
    "N24",
    "N28",
    "N30",
    "N32",
    "N36",
    "N40",
    "N42",
    "N44",
    "N48",
    "N52",
    "N54",
    "N56",
    "N60",
    "N64",
    "N66",
    "N68",
    "N72",
    "N76",
    "N78",
    "N80",
    "N84",
    "N88",
    "N90",
    "N92",
    "N96",
]

def ExtractCommandParam(f: BufferedReader, type: int, name: str) -> str:
    if type == PARAM_TYPE_NONE:
        return ""
    
    if type == PARAM_TYPE_BYTE:
        value: int = int.from_bytes(f.read(1), "little")
        return ", " + str(value)

    if type == PARAM_TYPE_C_V:
        value: int = int.from_bytes(f.read(1), "little")
        result = ", c_v"
        if value == 0x40:
            return result
        
        if value > 0x40:
            return result + "+" + str(value - 0x40)
        
        if value < 0x40:
            return result + "-" + str(0x40 - value)

    if type == PARAM_TYPE_MEM:
        value: int = int.from_bytes(f.read(1), "little")
        return ", " + memParams[value]

    if type == PARAM_TYPE_MODT:
        value: int = int.from_bytes(f.read(1), "little")
        return ", " + modtParams[value]

    if type == PARAM_TYPE_XCMD:
        value: int = int.from_bytes(f.read(1), "little")

        if value == 8:
            return ", xIECV"

        if value == 9:
            return ", xIECL"

    if type == PARAM_TYPE_EOT:
        value: int = int.from_bytes(f.read(1), "little")

        if value <= 127:
            return ", " + notesTieEot[value]
        else:
            f.seek(f.tell() - 1)
            return ""

    if type == PARAM_TYPE_PTR:
        ptr = ReadPtr(f)

        return "\n\t\t.word " + name + hex(ptr).split("0x")[1]


def ExtractTrackCommands(f: BufferedReader, addr: int, trackNbr: int):
    f.seek(addr)
    value: int = int.from_bytes(f.read(1), "little")
    name = "track_" + str(trackNbr) + "_lbl_"
    result = ""

    while value != 0xB1:
        if value >= 0x80 and value <= 0xb0:
            # Wait command
            value -= 0x80
            result += "\t.byte " + waitCommand[value]
        elif value >= 0xb1 and value <= 0xce:
            # Code command
            value -= 0xb1
            result += "\t.byte " + codeCommands[value]

            ret = ExtractCommandParam(f, codeCommandsParamType[value], name)

            if codeCommandsParamType[value] == PARAM_TYPE_PTR:
                ptr = int(ret.split("lbl_")[1], 16)
                result = result.replace(hex(ptr), hex(ptr).replace("0x", ""))

            result += ret

        elif value >= 0xcf:
            # Note command
            result += "\t.byte " + notes[value - 0xcf]
            value: int = int.from_bytes(f.read(1), "little")

            if value >= 0xcf:
                result += ", " + notes[value - 0xcf]
                value: int = int.from_bytes(f.read(1), "little")

                if value >= 0xcf:
                    result += ", " + notes[value - 0xcf]
                    value: int = int.from_bytes(f.read(1), "little")
                        
                    if value >= 0xcf:
                        result += ", " + notes[value - 0xcf]
                        value: int = int.from_bytes(f.read(1), "little")
                        
                        if value >= 0xcf:
                            result += ", " + notes[value - 0xcf]
                        else:
                            f.seek(f.tell() - 1)
                    else:
                        f.seek(f.tell() - 1)
                else:
                    f.seek(f.tell() - 1)
            else:
                f.seek(f.tell() - 1)
        elif value < 0x80:
            # Raw note command
            result += "\t.byte " + notesTieEot[value]
            value: int = int.from_bytes(f.read(1), "little")

            if value < 0x80:
                result += ", " + notesTieEot[value]
                value: int = int.from_bytes(f.read(1), "little")

                if value < 0x80:
                    result += ", " + notesTieEot[value]
                    value: int = int.from_bytes(f.read(1), "little")
                        
                    if value < 0x80:
                        result += ", " + notesTieEot[value]
                        value: int = int.from_bytes(f.read(1), "little")
                        
                        if value < 0x80:
                            result += ", " + notesTieEot[value]
                        else:
                            f.seek(f.tell() - 1)
                    else:
                        f.seek(f.tell() - 1)
                else:
                    f.seek(f.tell() - 1)
            else:
                f.seek(f.tell() - 1)

        value = int.from_bytes(f.read(1), "little")
        result += "\n" + name + hex(f.tell()) + ":\n"

    splitted = result.split("\n")
    result = ""
    for x in splitted:
        if x.find("0x") == -1:
            result += x + "\n"

    result += "\t.byte FINE\n\n"
    return result

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

        content += name + "_" + str(x) + ":\n"

        content += ExtractTrackCommands(f, ptr, number)

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

    content += "\n"
    output.write(content)
    output.close()

    sorted_dict = dict(sorted(existingHeaders.items()))

    for key, value in sorted_dict.items():
        print(value)

def Func():
    addr = 0x8cf70
    file.seek(addr)
    # ExtractVoiceGroups(file)

    # result = ExtractTrackCommands(file, 0x20dbbc, 270)

    addr: int = 0x8f2c0
    file.seek(addr)
    ExtractTracks(file)

Func()
