from io import BufferedReader

file: BufferedReader = open("../mzm_us_baserom.gba", "rb")
header: BufferedReader = open("../include/data/samus/arm_cannon_data.h", "r")

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
    addr = 0x2320ec

    file.seek(addr)

    result: str = ""
    
    line: str = header.readline()
    while line != '':
        if line.find("u8 sArmCannonGfx") != -1:
            # Generate graphics
            splitted = line.split("[SAMUS_ARM_CANNON_GFX_SIZE")
            name: str = splitted[0].split("extern const u8 sArmCannonGfx_")[1]

            folderName: str = "samus/graphics/arm_cannon/"

            name = name.replace("extern ", "", 1)
            name = name.__add__(".gfx")

            fileName: str = folderName.__add__(name)

            size: int = 64

            result += line.replace("extern ", "").replace(";\n", "").__add__(' = INCBIN_U8("data/').__add__(fileName).__add__('");')

            dbEntry: str = fileName.__add__(";").__add__(str(size)).__add__(";").__add__(hex(addr)).__add__(";1")

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


        line = header.readline()

        result += "\n"
    return result

f = open("arm_cannon_data.txt", "w")
f.write(Func())
f.close()
