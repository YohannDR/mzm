from io import BufferedReader

def sign(value):
    if value > 0x7FFF:
        value = -(0x10000 - value)

    return value

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    addr = 0x3461fc

    file.seek(addr)

    result = "const i16* const sHaze_PowerBomb_WindowValuesPointers[161] = {\n\t"
    
    for x in range(5, 161):
        result += "sHaze_PowerBomb_Values"
        result += str(x)
        result += ",\n\t"

    result += "};"

    return result

f = open("haze.txt", "w")
f.write(Func())
f.close()

Func()