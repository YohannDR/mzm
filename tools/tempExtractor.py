from io import BufferedReader

sprites = [
    "PSPRITE_UNUSED0",
    "PSPRITE_UNUSED1",
    "PSPRITE_UNUSED2",
    "PSPRITE_UNUSED3",
    "PSPRITE_UNUSED4",
    "PSPRITE_UNUSED5",
    "PSPRITE_UNUSED6",
    "PSPRITE_UNUSED7",
    "PSPRITE_UNUSED8",
    "PSPRITE_UNUSED9",
    "PSPRITE_UNUSED10",
    "PSPRITE_UNUSED11",
    "PSPRITE_UNUSED12",
    "PSPRITE_UNUSED13",
    "PSPRITE_UNUSED14",
    "PSPRITE_UNUSED15",
    "PSPRITE_UNUSED16",
    "PSPRITE_ITEM_BANNER",
    "PSPRITE_ZOOMER_YELLOW",
    "PSPRITE_ZOOMER_RED",
    "PSPRITE_ZEELA",
    "PSPRITE_ZEELA_RED",
    "PSPRITE_RIPPER_BROWN",
    "PSPRITE_RIPPER_PURPLE",
    "PSPRITE_ZEB",
    "PSPRITE_ZEB_BLUE",
    "PSPRITE_LARGE_ENERGY_DROP",
    "PSPRITE_SMALL_ENERGY_DROP",
    "PSPRITE_MISSILE_DROP",
    "PSPRITE_SUPER_MISSILE_DROP",
    "PSPRITE_POWER_BOMB_DROP",
    "PSPRITE_SKREE_GREEN",
    "PSPRITE_SKREE_BLUE",
    "PSPRITE_MORPH_BALL",
    "PSPRITE_CHOZO_STATUE_LONG_HINT",
    "PSPRITE_CHOZO_STATUE_LONG",
    "PSPRITE_CHOZO_STATUE_ICE_HINT",
    "PSPRITE_CHOZO_STATUE_ICE",
    "PSPRITE_CHOZO_STATUE_WAVE_HINT",
    "PSPRITE_CHOZO_STATUE_WAVE",
    "PSPRITE_CHOZO_STATUE_BOMB_HINT",
    "PSPRITE_CHOZO_STATUE_BOMB",
    "PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT",
    "PSPRITE_CHOZO_STATUE_SPEEDBOOSTER",
    "PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT",
    "PSPRITE_CHOZO_STATUE_HIGH_JUMP",
    "PSPRITE_CHOZO_STATUE_SCREW_HINT",
    "PSPRITE_CHOZO_STATUE_SCREW",
    "PSPRITE_CHOZO_STATUE_VARIA_HINT",
    "PSPRITE_CHOZO_STATUE_VARIA",
    "PSPRITE_SOVA_PURPLE",
    "PSPRITE_SOVA_ORANGE",
    "PSPRITE_MULTIVIOLA",
    "PSPRITE_MULTIPLE_LARGE_ENERGY",
    "PSPRITE_GERUTA_RED",
    "PSPRITE_GERUTA_GREEN",
    "PSPRITE_SQUEEPT",
    "PSPRITE_SQUEEPT_UNUSED",
    "PSPRITE_MAP_STATION",
    "PSPRITE_DRAGON",
    "PSPRITE_DRAGON_UNUSED",
    "PSPRITE_ZIPLINE",
    "PSPRITE_ZIPLINE_BUTTON",
    "PSPRITE_REO_GREEN_WINGS",
    "PSPRITE_REO_PURPLE_WINGS",
    "PSPRITE_GUNSHIP",
    "PSPRITE_DEOREM",
    "PSPRITE_DEOREM_SECOND_LOCATION",
    "PSPRITE_CHARGE_BEAM",
    "PSPRITE_SKULTERA",
    "PSPRITE_DESSGEEGA",
    "PSPRITE_DESSGEEGA_AFTER_LONG_BEAM",
    "PSPRITE_WAVER",
    "PSPRITE_WAVER_UNUSED",
    "PSPRITE_MELLOW",
    "PSPRITE_HIVE",
    "PSPRITE_POWER_GRIP",
    "PSPRITE_IMAGO_LARVA_RIGHT",
    "PSPRITE_MORPH_BALL_LAUNCHER",
    "PSPRITE_IMAGO_COCOON",
    "PSPRITE_ELEVATOR_PAD",
    "PSPRITE_SPACE_PIRATE",
    "PSPRITE_SPACE_PIRATE_WAITING1",
    "PSPRITE_SPACE_PIRATE_WAITING2",
    "PSPRITE_SPACE_PIRATE_WAITING3",
    "PSPRITE_SPACE_PIRATE2",
    "PSPRITE_GAMET_BLUE_SINGLE",
    "PSPRITE_GAMET_RED_SINGLE",
    "PSPRITE_CHOZO_STATUE_GRAVITY",
    "PSPRITE_CHOZO_STATUE_SPACE_JUMP",
    "PSPRITE_SECURITY_GATE_DEFAULT_OPEN",
    "PSPRITE_ZEBBO_GREEN",
    "PSPRITE_ZEBBO_YELLOW",
    "PSPRITE_WORKER_ROBOT",
    "PSPRITE_PARASITE_MULTIPLE",
    "PSPRITE_PARASITE",
    "PSPRITE_PISTON",
    "PSPRITE_RIDLEY",
    "PSPRITE_SECURITY_GATE_DEFAULT_CLOSED",
    "PSPRITE_ZIPLINE_GENERATOR",
    "PSPRITE_METROID",
    "PSPRITE_FROZEN_METROID",
    "PSPRITE_RINKA_ORANGE",
    "PSPRITE_POLYP",
    "PSPRITE_VIOLA_BLUE",
    "PSPRITE_VIOLA_ORANGE",
    "PSPRITE_GERON_NORFAIR",
    "PSPRITE_HOLTZ",
    "PSPRITE_GEKITAI_MACHINE",
    "PSPRITE_RUINS_TEST",
    "PSPRITE_SAVE_PLATFORM",
    "PSPRITE_KRAID",
    "PSPRITE_IMAGO_COCOON_AFTER_FIGHT",
    "PSPRITE_RIPPERII",
    "PSPRITE_MELLA",
    "PSPRITE_ATOMIC",
    "PSPRITE_AREA_BANNER",
    "PSPRITE_MOTHER_BRAIN",
    "PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER",
    "PSPRITE_ACID_WORM",
    "PSPRITE_ESCAPE_SHIP",
    "PSPRITE_SIDEHOPPER",
    "PSPRITE_GEEGA",
    "PSPRITE_GEEGA_WHITE",
    "PSPRITE_RINKA_MOTHER_BRAIN",
    "PSPRITE_ZEBETITE_ONE_AND_THREE",
    "PSPRITE_CANNON",
    "PSPRITE_IMAGO_LARVA_RIGHT_SIDE",
    "PSPRITE_TANGLE_VINE_TALL",
    "PSPRITE_TANGLE_VINE_MEDIUM",
    "PSPRITE_TANGLE_VINE_CURVED",
    "PSPRITE_TANGLE_VINE_SHORT",
    "PSPRITE_MELLOW_SWARM",
    "PSPRITE_MELLOW_SWARM_HEALTH_BASED",
    "PSPRITE_IMAGO",
    "PSPRITE_ZEBETITE_TWO_AND_FOUR",
    "PSPRITE_CANNON2",
    "PSPRITE_CANNON3",
    "PSPRITE_CROCOMIRE",
    "PSPRITE_IMAGO_LARVA_LEFT",
    "PSPRITE_GERON_BRINSTAR_ROOM_15",
    "PSPRITE_GERON_BRINSTAR_ROOM_1C",
    "PSPRITE_GERON_VARIA1",
    "PSPRITE_GERON_VARIA2",
    "PSPRITE_GERON_VARIA3",
    "PSPRITE_GLASS_TUBE",
    "PSPRITE_SAVE_PLATFORM_CHOZODIA",
    "PSPRITE_BARISTUTE",
    "PSPRITE_CHOZO_STATUE_PLASMA_BEAM",
    "PSPRITE_KRAID_ELEVATOR_STATUE",
    "PSPRITE_RIDLEY_ELEVATOR_STATUE",
    "PSPRITE_RISING_CHOZO_PILLAR",
    "PSPRITE_SECURITY_LASER_VERTICAL",
    "PSPRITE_SECURITY_LASER_HORIZONTAL",
    "PSPRITE_SECURITY_LASER_VERTICAL2",
    "PSPRITE_SECURITY_LASER_HORIZONTAL2",
    "PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED",
    "PSPRITE_GAMET_BLUE_LEADER",
    "PSPRITE_GAMET_BLUE_FOLLOWER",
    "PSPRITE_GEEGA_LEADER",
    "PSPRITE_GEEGA_FOLLOWER",
    "PSPRITE_ZEBBO_GREEN_LEADER",
    "PSPRITE_ZEBBO_GREEN_FOLLOWER",
    "PSPRITE_KRAID_STATUE",
    "PSPRITE_RIDLEY_STATUE",
    "PSPRITE_RINKA_GREEN",
    "PSPRITE_SEARCHLIGHT_EYE",
    "PSPRITE_SEARCHLIGHT_EYE2",
    "PSPRITE_STEAM_LARGE",
    "PSPRITE_STEAM_SMALL",
    "PSPRITE_PLASMA_BEAM_BLOCK",
    "PSPRITE_GRAVITY_SUIT_BLOCK",
    "PSPRITE_SPACE_JUMP_BLOCK",
    "PSPRITE_GADORA_KRAID",
    "PSPRITE_GADORA_RIDLEY",
    "PSPRITE_SEARCHLIGHT",
    "PSPRITE_SEARCHLIGHT2",
    "PSPRITE_SEARCHLIGHT3",
    "PSPRITE_SEARCHLIGHT4",
    "PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER",
    "PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER",
    "PSPRITE_FAKE_POWER_BOMB",
    "PSPRITE_SPACE_PIRATE_CARRYING_POWER_BOMB",
    "PSPRITE_TANGLE_VINE_RED_GARUTA",
    "PSPRITE_TANGLE_VINE_GERUTA",
    "PSPRITE_TANGLE_VINE_LARVA_RIGHT",
    "PSPRITE_TANGLE_VINE_LARVA_LEFT",
    "PSPRITE_WATER_DROP",
    "PSPRITE_FALLING_CHOZO_PILLAR",
    "PSPRITE_MECHA_RIDLEY",
    "PSPRITE_EXPLOSION_ZEBES_ESCAPE",
    "PSPRITE_STEAM_LARGE_DIAGONAL_UP",
    "PSPRITE_STEAM_SMALL_DIAGONAL_UP",
    "PSPRITE_STEAM_LARGE_DIAGONAL_DOWN",
    "PSPRITE_STEAM_SMALL_DIAGONAL_DOWN",
    "PSPRITE_BARISTUTE_KRAID_UPPER",
    "PSPRITE_ESCAPE_GATE1",
    "PSPRITE_ESCAPE_GATE2",
    "PSPRITE_BLACK_SPACE_PIRATE",
    "PSPRITE_ESCAPE_SHIP_SPACE_PIRATE",
    "PSPRITE_BARISTUTE_KRAID_LOWER",
    "PSPRITE_RINKA_MOTHER_BRAIN2",
    "PSPRITE_RINKA_MOTHER_BRAIN3",
    "PSPRITE_RINKA_MOTHER_BRAIN4",
    "PSPRITE_RINKA_MOTHER_BRAIN5",
    "PSPRITE_RINKA_MOTHER_BRAIN6",
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

    if value & 0x80:
        if result != "":
            result += " | 0x80"
        else:
            result = "0x80"

    if value & 0x100:
        if result != "":
            result += " | 0x100"
        else:
            result = "0x100"

    if value & 0x200:
        if result != "":
            result += " | 0x200"
        else:
            result = "0x200"

    if value & 0x400:
        if result != "":
            result += " | 0x400"
        else:
            result = "0x400"

    if value & 0x800:
        if result != "":
            result += " | 0x800"
        else:
            result = "0x800"

    if value & 0x1000:
        if result != "":
            result += " | 0x1000"
        else:
            result = "0x1000"

    if value & 0x2000:
        if result != "":
            result += " | 0x2000"
        else:
            result = "0x2000"

    if value & 0x4000:
        if result != "":
            result += " | 0x4000"
        else:
            result = "0x4000"

    if value & 0x8000:
        if result != "":
            result += " | 0x8000"
        else:
            result = "0x8000"

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

file = open("../mzm_us_baserom.gba", "rb")

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