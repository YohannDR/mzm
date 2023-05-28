from io import BufferedReader
from array import array

types: array = [
    "CREDIT_LINE_TYPE_BLUE",
    "CREDIT_LINE_TYPE_RED",
    "CREDIT_LINE_TYPE_WHITE_BIG",
    "CREDIT_LINE_TYPE_WHITE_SMALL",
    "",
    "CREDIT_LINE_TYPE_UNK_5",
    "CREDIT_LINE_TYPE_END",
    "",
    "",
    "",
    "CREDIT_LINE_TYPE_ALL_RIGHTS",
    "CREDIT_LINE_TYPE_THE_COPYRIGHT",
    "CREDIT_LINE_TYPE_SCENARIO",
    "CREDIT_LINE_TYPE_RESERVED"
]

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    addr = 0x54c10c

    file.seek(addr)


    result = ""
    for x in range(0, 240):
        result += "["+str(x)+"] = {\n\t.type = "

        offset: int = int.from_bytes(file.read(1), "little")
        result += types[offset]

        txt:str = file.read(35).decode("ascii").strip('\0')
        result += ",\n\t.text = \""+txt+"\"\n},\n"

    return result

f = open("credits.txt", "w")
f.write(Func())
f.close()

Func()