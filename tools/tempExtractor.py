from io import BufferedReader

sprites = [
    "SSPRITE_CHOZO_BALL",
    "SSPRITE_CHOZO_STATUE_PART",
    "SSPRITE_CHOZO_STATUE_REFILL",
    "SSPRITE_KRAID_PART",
    "SSPRITE_CHOZO_STATUE_MOVEMENT",
    "SSPRITE_CHARGE_BEAM_GLOW",
    "SSPRITE_WINGED_RIPPER",
    "SSPRITE_MULTIVIOLA_UNUSED",
    "SSPRITE_DRAGON_FIREBALL",
    "SSPRITE_DEOREM_SEGMENT",
    "SSPRITE_DEOREM_EYE",
    "SSPRITE_DEOREM_THORN",
    "SSPRITE_SKREE_EXPLOSION",
    "SSPRITE_SAVE_PLATFORM_PART",
    "SSPRITE_SAVE_YES_NO_CURSOR",
    "SSPRITE_BLUE_SKREE_EXPLOSION",
    "SSPRITE_ZEELA_EYES",
    "SSPRITE_HIVE_ROOTS",
    "SSPRITE_IMAGO_LARVA_PART",
    "SSPRITE_MORPH_BALL_OUTSIDE",
    "SSPRITE_IMAGO_COCOON_VINE",
    "SSPRITE_IMAGO_COCOON_SPORE",
    "SSPRITE_SPACE_PIRATE_LASER",
    "SSPRITE_RIDLEY_PART",
    "SSPRITE_RIDLEY_TAIL",
    "SSPRITE_SEARCHLIGHT_EYE_BEAM",
    "SSPRITE_METROID_SHELL",
    "SSPRITE_POLYP_PROJECTILE",
    "SSPRITE_KRAID_SPIKE",
    "SSPRITE_KRAID_NAIL",
    "SSPRITE_ZIPLINE_GENERATOR_PART",
    "SSPRITE_ATOMIC_ELECTRICITY",
    "SSPRITE_MOTHER_BRAIN_PART",
    "SSPRITE_RIDLEY_FIREBALL",
    "SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART",
    "SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_REFILL",
    "SSPRITE_MORPH_BALL_LAUNCHER_PART",
    "SSPRITE_ACID_WORM_BODY",
    "SSPRITE_ACID_WORM_SPIT",
    "SSPRITE_CANNON_BULLET",
    "SSPRITE_CROCOMIRE_PART",
    "SSPRITE_IMAGO_PART",
    "SSPRITE_DEFEATED_IMAGO_COCOON",
    "SSPRITE_IMAGO_CEILING_VINE",
    "SSPRITE_SEARCHLIGHT_EYE_BEAM2",
    "SSPRITE_TANGLE_VINE_GERUTA_PART",
    "SSPRITE_CHOZODIA_SAVE_PLATFORM_PART",
    "SSPRITE_IMAGO_NEEDLE",
    "SSPRITE_ELEVATOR_STATUE_DEBRIS",
    "SSPRITE_IMAGO_DAMAGED_STINGER",
    "SSPRITE_GUNSHIP_PART",
    "SSPRITE_IMAGO_EGG",
    "SSPRITE_MAP_STATION_PART",
    "SSPRITE_CHOZO_PILLAR_PLATFORM",
    "SSPRITE_GADORA_EYE",
    "SSPRITE_GADORA_BEAM",
    "SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT",
    "SSPRITE_SEARCHLIGHT_EYE_PROJECTILE",
    "SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW",
    "SSPRITE_RUINS_TEST_SYMBOL",
    "SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START",
    "SSPRITE_RUINS_TEST_REFLECTION_COVER",
    "SSPRITE_RUINS_TEST_GHOST_OUTLINE",
    "SSPRITE_RUINS_TEST_GHOST",
    "SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL",
    "SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END",
    "SSPRITE_RUINS_TEST_LIGHTNING",
    "SSPRITE_RIDLEY_BIG_FIREBALL",
    "SSPRITE_MECHA_RIDLEY_PART",
    "SSPRITE_ESCAPE_SHIP_PART",
    "SSPRITE_POWER_GRIP_GLOW",
    "SSPRITE_MECHA_RIDLEY_LASER",
    "SSPRITE_MECHA_RIDLEY_MISSILE",
    "SSPRITE_MECHA_RIDLEY_FIREBALL",
    "SSPRITE_MOTHER_BRAIN_BEAM",
    "SSPRITE_MOTHER_BRAIN_BLOCK",
    "SSPRITE_MOTHER_BRAIN_GLASS_BREAKING",
]

def sign(value):
    if value > 0x7FFF:
        value = -(0x10000 - value)

    return value

def extractWeakness(value):
    result = ""
    
    if value == 0:
        return "WEAKNESS_NONE"

    if value & 0x1:
        result += "WEAKNESS_CHARGE_BEAM_PISTOL"
    
    if value & 0x2:
        if result != "":
            result += " | WEAKNESS_BEAM_BOMBS"
        else:
            result = "WEAKNESS_BEAM_BOMBS"

    if value & 0x4:
        if result != "":
            result += " | WEAKNESS_SUPER_MISSILES"
        else:
            result = "WEAKNESS_SUPER_MISSILES"

    if value & 0x8:
        if result != "":
            result += " | WEAKNESS_MISSILES"
        else:
            result = "WEAKNESS_MISSILES"

    if value & 0x10:
        if result != "":
            result += " | WEAKNESS_POWER_BOMB"
        else:
            result = "WEAKNESS_POWER_BOMB"

    if value & 0x20:
        if result != "":
            result += " | WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK"
        else:
            result = "WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK"

    if value & 0x40:
        if result != "":
            result += " | WEAKNESS_CAN_BE_FROZEN"
        else:
            result = "WEAKNESS_CAN_BE_FROZEN"

    return result

def extractStats(file: BufferedReader):
    result = "{\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += extractWeakness(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += ",\n\t"
    result += str(int.from_bytes(file.read(2), "little"))
    result += "\n},\n"
    
    return result

file = open("../baserom_us.gba", "rb")

def Func():
    inputValue = input("Address : ")
    size = int(input("Size : "))

    addr = int(inputValue, 16)

    file.seek(addr)

    result = ""
    
    for x in range(0, size):
        result += "["
        result += sprites[x]
        result += "] = "
        result += extractStats(file)

    return result

f = open("AC.txt", "a")
f.write(Func())
f.close()

Func()