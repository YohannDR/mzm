from io import BufferedReader
from array import array

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    addr = int(input("Address : "), 16)

    file.seek(addr)

    result = ".y = C_S8_2_S16("

    v: int = int.from_bytes(file.read(2), "little")
    if v & 0x80:
        result += str(v - 0x100)
    else:
        result += str(v)

    result += "),\n.x = C_S9_2_S16("

    v = int.from_bytes(file.read(2), "little")
    if v & 0x100:
        result += str(v - 0x200)
    else:
        result += str(v)

    result += ")"

    print(result)
    Func()

Func()