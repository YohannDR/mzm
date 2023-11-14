from io import BufferedReader
import os

file: BufferedReader = open("../mzm_us_baserom.gba", "rb")
header: BufferedReader = open("../include/data/rooms/tourian_rooms_data.h", "r")

def ExtractScroll(f: BufferedReader, size: int):
    result: str = "\t"

    result += str(int.from_bytes(f.read(1), "little"))
    result += ", // Room\n\t"

    s: int = int.from_bytes(f.read(1), "little")

    if s != size:
        raise Exception("Scroll size isn't valid at " + hex(f.tell()))
    
    result += str(s)
    result += ", // Number of scrolls\n\t"

    for x in range(0, s):
        result += "\n\t// Scroll " + str(x)+ "\n\t"

        result += str(int.from_bytes(f.read(1), "little")) + ", " + str(int.from_bytes(f.read(1), "little")) + ", // X bounds\n\t"
        result += str(int.from_bytes(f.read(1), "little")) + ", " + str(int.from_bytes(f.read(1), "little")) + ", // Y bounds\n\t"

        b: int = int.from_bytes(f.read(1), "little")

        if b == 255:
            result += "UCHAR_MAX, UCHAR_MAX, // Breakeable block position\n\t"
            
            file.read(1)
        else:
            result += str(b) + ", " + str(int.from_bytes(f.read(1), "little")) + ", // Breakeable block position\n\t"

        b = int.from_bytes(f.read(1), "little")

        if b == 255:
            result += "UCHAR_MAX, // Breakeable block direction\n\t"
            result += "UCHAR_MAX, // Breakeable block Y bound extension\n"

            file.read(1)
        else:
            result += str(b) + ", // Breakeable block direction\n\t"
            result += str(int.from_bytes(f.read(1), "little")) + ", // Breakeable block Y bound extension\n"

    return result

def ExtractSpriteData(f: BufferedReader, size: int):
    result = "\t"
    
    for x in range(0, size - 1):
        result += str(int.from_bytes(f.read(1), "little")) + ", " + str(int.from_bytes(f.read(1), "little")) + ", " + str(int.from_bytes(f.read(1), "little")) + ",\n\t"

    f.read(3)
    result += "ROOM_SPRITE_DATA_TERMINATOR\n"

    return result

def Align(f: BufferedReader):
    addr: int = f.tell()

    # print("Align from : " + hex(addr))

    while addr % 4 != 0:
        f.read(1)
        addr += 1

def Func():
    addr = 0x6ba8d4

    currentRoom: int = 0
    prevIsScroll: bool = False

    cFileName: str = "Tourian_" + str(currentRoom) + ".c"

    if os.path.exists(cFileName):
        os.remove(cFileName)

    f = open(cFileName, "w")
    f.write('#include "data/rooms/tourian_rooms_data.h"\n#include "macros.h"\n\n')

    file.seek(addr)

    result: str = ""
    
    line: str = header.readline()
    while line != '':
        actualRoom: int = currentRoom
        if line.find("extern") != -1:
            if line.find("Bg3") == -1:
                actualRoom = int(line.split("_")[1])

            if line.find("SCROLL_DATA_SIZE") != -1:
                prevIsScroll = True

        if currentRoom != actualRoom:
            if not f.closed:
                # print("Closing file " + f.name)
                f.write(result)
                f.close()

                result = ""

                if line.find("// NO ALIGN") == -1:
                    Align(file)

                print("")

            if not prevIsScroll:
                currentRoom = actualRoom

                cFileName = "Tourian_" + str(currentRoom) + ".c"

                if os.path.exists(cFileName):
                    os.remove(cFileName)

                f = open(cFileName, "w")
                f.write('#include "data/rooms/tourian_rooms_data.h"\n#include "macros.h"\n\n')

        prevIsScroll = False

        if line.find("SCROLL_DATA_SIZE") != -1:
            prevIsScroll = True

            # print(hex(file.tell()))

            splitted = line.split("[SCROLL_DATA_SIZE(")
            size: str = splitted[1].split(")")[0]

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = {\n')

            parsed: str = ExtractScroll(file, int(size))

            result += parsed + "};\n\n"

        elif line.find("ENEMY_ROOM_DATA_ARRAY_SIZE") != -1:
            splitted = line.split("[ENEMY_ROOM_DATA_ARRAY_SIZE(")
            size: str = splitted[1].split(")")[0]

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = {\n')

            parsed: str = ExtractSpriteData(file, int(size))

            result += parsed + "};\n\n"

        elif line.find("Bg3") != -1:
            splitted = line.split("[")
            size = int(splitted[1].split("]")[0])
            name = splitted[0].split("u8 s")[1]

            addr = file.tell()

            #print(name)

            folderName: str = "rooms/tourian/"

            name = name.replace("extern ", "", 1)
            name = name.__add__(".gfx")

            fileName: str = folderName.__add__(name)

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = INCBIN_U8("data/').__add__(fileName).__add__('");\n\n')

            dbEntry: str = fileName.__add__(";").__add__(str(size)).__add__(";").__add__(hex(addr)).__add__(";1")

            # print()
            print(dbEntry)
            # print("Before : " + hex(addr))

            addr += size
            file.seek(addr)
            # print("After : " + hex(addr))

            #print(size)

        elif line.find("_Clipdata") != -1 or line.find("_Bg") != -1:
            splitted = line.split("[")
            size = int(splitted[1].split("]")[0])
            name = splitted[0].split("u8 s")[1]

            addr = file.tell()

            #print(name)

            folderName: str = "rooms/tourian/"

            name = name.replace("extern ", "", 1)
            name = name.__add__(".gfx")

            fileName: str = folderName.__add__(name)

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = INCBIN_U8("data/').__add__(fileName).__add__('");\n\n')

            dbEntry: str = fileName.__add__(";").__add__(str(size)).__add__(";").__add__(hex(addr)).__add__(";1")

            # print()
            print(dbEntry)
            # print("Before : " + hex(addr))

            addr += size
            file.seek(addr)
            # print("After : " + hex(addr))

            #print(size)

        line = header.readline()

    f.write(result)

Func()
