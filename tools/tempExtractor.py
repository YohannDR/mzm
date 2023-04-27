from io import BufferedReader

def sign(value):
    if value > 0x7FFF:
        value = -(0x10000 - value)

    return value

def extractInput(value):
    result = ""

    if value & 0x1:
        result = "KEY_A"

    if value & 0x2:
        if result == "":
            result = "KEY_B"
        else:
            result += " | KEY_B"

    if value & 0x4:
        if result == "":
            result = "KEY_SELECT"
        else:
            result += " | KEY_SELECT"

    if value & 0x8:
        if result == "":
            result = "KEY_START"
        else:
            result += " | KEY_START"

    if value & 0x10:
        if result == "":
            result = "KEY_RIGHT"
        else:
            result += " | KEY_RIGHT"

    if value & 0x20:
        if result == "":
            result = "KEY_LEFT"
        else:
            result += " | KEY_LEFT"

    if value & 0x40:
        if result == "":
            result = "KEY_UP"
        else:
            result += " | KEY_UP"

    if value & 0x80:
        if result == "":
            result = "KEY_DOWN"
        else:
            result += " | KEY_DOWN"

    if value & 0x100:
        if result == "":
            result = "KEY_R"
        else:
            result += " | KEY_R"

    if value & 0x200:
        if result == "":
            result = "KEY_L"
        else:
            result += " | KEY_L"

    if result == "":
        result = "KEY_NONE"

    return result

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    addr = 0x3603e8

    file.seek(addr)

    sizes = [104, 88, 80, 64, 64, 40, 32, 40, 136, 48, 88, 32, 48, 40, 24, 96]

    result = ""
    for x in range(0, len(sizes)):

        result += "static const u16 sDemo"
        result += str(x)
        result += "_Inputs[] = {\n\t"

        for y in range(0, sizes[x]):
            result += extractInput(int.from_bytes(file.read(2), "little"))
            result += ",\n\t"
        
        result += "};\n\n"

        result += "static const u16 sDemo"
        result += str(x)
        result += "_Durations[ARRAY_SIZE(sDemo"
        result += str(x)
        result += "_Inputs)"
        result += "] = {\n\t"

        for y in range(0, sizes[x]):
            result += str(int.from_bytes(file.read(2), "little"))
            result += ",\n\t"
        
        result += "};\n\n"

    return result

f = open("demos.txt", "w")
f.write(Func())
f.close()

Func()