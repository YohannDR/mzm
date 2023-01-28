from io import BufferedReader

def extractStats(file: BufferedReader):
    result = "{\n\t.pTileGraphics = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))
    result += ",\n\t.pPalette = (const u16*)"
    result += hex(int.from_bytes(file.read(4), "little"))
    result += ",\n\t.pBackgroundGraphics = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))
    result += ",\n\t.pTilemap = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))
    result += ",\n\t.animatedTileset = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.animatedPalette = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += "\n},\n"
    file.read(2)
    return result

file = open("../mzm_us_baserom.gba", "rb")

def Func():
    size = 79

    addr = 0x33dfdc

    file.seek(addr)

    result = ""
    
    for x in range(0, size):
        result += extractStats(file)

    return result

f = open("tilesets.txt", "w")
f.write(Func())
f.close()

Func()