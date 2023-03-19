from io import BufferedReader

file: BufferedReader = open("../mzm_us_baserom.gba", "rb")
header: BufferedReader = open("../include/data/samus/samus_graphics.h", "r")

def ParsePart0(value):
    result = ""

    if value & 0x100:
        result = "OBJ_ROTATION_SCALING"

    if value & 0x200:
        if result != "":
            result += " | OBJ_DOUBLE_SIZE"
        else:
            result = "OBJ_DISABLE"

    if value & 0x400:
        if result != "":
            result += " | "
        result += "OBJ_MODE_SEMI_TRANSPARENT"
    
    if value & 0x1000:
        if result != "":
            result += " | "
        result += "OBJ_MOSAIC"

    if value & 0x2000:
        if result != "":
            result += " | "
        result += "OBJ_COLOR_256_1"

    if value & 0x4000:
        if result != "":
            result += " | "
        result += "OBJ_SHAPE_HORIZONTAL"

    if value & 0x8000:
        if result != "":
            result += " | "
        result += "OBJ_SHAPE_VERTICAL"

    if result != "":
        result += " | "
    
    result += hex(value & 0xFF)

    return result

def ParsePart1(part0, value):
    result = ""
    sizes = ["OBJ_SIZE_16x16", "OBJ_SIZE_32x32", "OBJ_SIZE_64x64"]

    if part0.__contains__("OBJ_ROTATION_SCALING"):
        result = hex(value & 0x3E00)
    else:
        if value & 0x1000:
            result = "OBJ_X_FLIP"
        
        if value & 0x2000:
            if result != "":
                result += " | "
            result += "OBJ_Y_FLIP"

    if part0.__contains__("OBJ_SHAPE_HORIZONTAL"):
        sizes = ["OBJ_SIZE_32x8", "OBJ_SIZE_32x16", "OBJ_SIZE_64x32"]
    elif part0.__contains__("OBJ_SHAPE_VERTICAL"):
        sizes = ["OBJ_SIZE_8x32", "OBJ_SIZE_16x32", "OBJ_SIZE_32x64"]
        
    if value >> 14 & 3 != 0:
        if result != "":
            result += " | "
        result += sizes[(value >> 14 & 3) - 1]


    if result != "":
        result += " | "
    
    result += hex(value & 0x1FF)

    return result

def ParsePart2(value):
    result = ""

    if value & 0x8000:
        result = "OBJ_SPRITE_OAM | "
    
    result += hex(value & ~0x8000)

    return result

def Func():
    addr = 0x23a5bc

    file.seek(addr)

    result: str = ""
    
    line: str = header.readline()
    while line != '':
        if line.find("u8 sSamusGfx") != -1 or line.find("u8 sSamusEffectGfx") != -1:
            # Generate graphics
            splitted = line.split("[SAMUS_GFX_SIZE(")
            name: str = ""
            try:
                name: str = splitted[0].split("extern const u8 sSamusGfx_")[1]
            except:
                name: str = splitted[0].split("extern const u8 sSamusEffectGfx_")[1]

            folderName: str = "samus/graphics/power_suit/"
            if name.find("FullSuit") != -1:
                folderName = "samus/graphics/full_suit/"
            elif name.find("Suitless") != -1:
                folderName = "samus/graphics/suitless/"
            elif line.find("sSamusEffectGfx") != -1:
                folderName = "samus/graphics/effects/"

            name = name.replace("_PowerSuit", "", 1)
            name = name.replace("_FullSuit", "", 1)
            name = name.replace("_Suitless", "", 1)
            name = name.replace("extern ", "", 1)
            name = name.__add__(".gfx")

            fileName: str = folderName.__add__(name)

            sizeInfo: str = splitted[1].split(")")[0].split(", ")
            size: int = 2 + int(sizeInfo[0]) * 32 + int(sizeInfo[1]) * 32

            size1: int = int.from_bytes(file.read(1), "little")
            size2: int = int.from_bytes(file.read(1), "little")

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = {\n\t').__add__(str(size1)).__add__(", ").__add__(str(size2)).__add__(',\n\t_INCBIN_U8("data/').__add__(fileName).__add__('")\n};\n')

            if int(sizeInfo[0]) != size1 or int(sizeInfo[1]) != size2:
                print("Wrong GFX size at : " + hex(addr) + " while reading " + line, end="")
                print("Got : " + str(sizeInfo[0]) + " and " + str(sizeInfo[1]) + ", expected : " + str(size1) + " and " + str(size2))
                return result

            dbEntry: str = fileName.__add__(";").__add__(str(size - 2)).__add__(";").__add__(hex(addr + 2)).__add__(";1")

            # print()
            print(dbEntry)
            # print("Before : " + hex(addr))

            addr += size
            file.seek(addr)
            # print("After : " + hex(addr))

        elif line.find("u16 sSamusOam") != -1 or line.find("u16 sSamusEffectOam") != -1:
            # Generate OAM
            # print("Reading OAM at : " + hex(addr) + " : " + line)
            size: str = int(line.split("[OAM_DATA_SIZE(")[1].split(")")[0])
            partCount: int = int.from_bytes(file.read(2), "little")
            oam: str = "\t" + hex(partCount) + ",\n\t"

            if partCount > 10 or partCount == 0:
                print("Part count abnormal : " + str(partCount))
                print("At : ", hex(addr))

                return result
            elif partCount != size:
                print("Wrong OAM size at : " + hex(addr) + " while reading " + line, end="")
                print("Got : " + str(size) + ", expected : " + str(partCount))

                return result

            addr += (size * 3 + 1) * 2

            for x in range(0, partCount):
                part0 = ParsePart0(int.from_bytes(file.read(2), "little"))
                oam += part0 + ", "
                oam += ParsePart1(part0, int.from_bytes(file.read(2), "little")) + ", "
                oam += ParsePart2(int.from_bytes(file.read(2), "little"))

                if x != partCount - 1:
                    oam += ",\n\t"
                else:
                    oam += "\n"

            name: str = line.replace("extern ", "", 1)

            result += name.replace(";\n", " = {\n").__add__(oam).__add__("};\n")

        elif line.find("struct SamusAnimationData sSamusAnim") != -1:
            # Generate anim data
            pad: int = addr % 4
            if pad != 0:
                addr += pad
                file.seek(addr)

            # print("Extracting anim at " + hex(addr))

            name: str = line.replace("extern ", "", 1)

            size: int = int(line.split("[")[1].split("]")[0])

            result += name.replace(";\n", " = {\n")

            body: str = " = {\n\t\t.pTopGfx = ,\n\t\t.pBottomGfx = ,\n\t\t.pOam = ,\n\t\t.timer = "

            for x in range(0, size):
                if x != size - 1:
                    file.read(12)
                    timer: int = int.from_bytes(file.read(1), "little")
                    file.read(3)
                    result = result.__add__("\t[").__add__(str(x)).__add__("]").__add__(body).__add__(str(timer)).__add__(",\n\t},\n")
                else:
                    file.read(16)
                    result = result.__add__("\t[").__add__(str(x)).__add__("] = SAMUS_ANIM_TERMINATOR\n")

            addr += size * 16
            file.seek(addr)

            result += "};"

        elif line.find("struct SamusEffectAnimationData sSamusEffectAnim") != -1:
            # Generate anim data
            pad: int = addr % 4
            if pad != 0:
                addr += pad
                file.seek(addr)

            # print("Extracting effect anim at " + hex(addr))

            name: str = line.replace("extern ", "", 1)

            size: int = int(line.split("[")[1].split("]")[0])

            result += name.replace(";\n", " = {\n")

            body: str = " = {\n\t\t.pGraphics = ,\n\t\t.pOam = ,\n\t\t.timer = "

            for x in range(0, size):
                if x != size - 1:
                    file.read(8)
                    timer: int = int.from_bytes(file.read(1), "little")
                    file.read(3)
                    result = result.__add__("\t[").__add__(str(x)).__add__("]").__add__(body).__add__(str(timer)).__add__(",\n\t},\n")
                else:
                    file.read(12)
                    result = result.__add__("\t[").__add__(str(x)).__add__("] = SAMUS_EFFECT_ANIM_TERMINATOR\n")

            addr += size * 12
            file.seek(addr)

            result += "};"

        line = header.readline()

        result += "\n"

    return result

f = open("samus_graphics.txt", "w")
f.write(Func())
f.close()
