from io import BufferedReader
from array import array

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    addr = int(input("Address : "), 16)
    size = int(input("Size : "))

    file.seek(addr)
    data = bytearray(file.read(size))

    size8: int = size // 8
    result = ""

    for x in range(0, size8):
        result += "\t.byte " + str(data[x * 8 + 0]) + ", " + str(data[x * 8 + 1]) + ", " + str(data[x * 8 + 2]) + ", " + str(data[x * 8 + 3]) + ", " + str(data[x * 8 + 4]) + ", " + str(data[x * 8 + 5]) + ", " + str(data[x * 8 + 6]) + ", " + str(data[x * 8 + 7]) + "\n"

    result += "\t.byte "

    remaining: int = size % 8
    for x in range(0, remaining):
        result += str(data[size8 * 8 + x])
        if x != remaining - 1:
            result += ", "

    print(result)
    Func()

Func()