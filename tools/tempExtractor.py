from io import BufferedReader

def extractBgProp(file: BufferedReader):
    result = ""

    value = int.from_bytes(file.read(1), "little")

    if value == 0x0:
        return "BG_PROP_NONE"

    if value == 0x10:
        return "BG_PROP_RLE_COMPRESSED"

    if value == (0x10 | 2):
        return "BG_PROP_DISABLE_TRANSPARENCY"

    if value == 0x31:
        return "BG_PROP_MOVING"

    if value == 0x40:
        return "BG_PROP_LZ77_COMPRESSED"

    if value == (0x40 | 1):
        return "BG_PROP_CLOSE_UP"

    if value == (0x40 | 5):
        return "BG_PROP_DARK_ROOM"

    if value == (0x40 | 6):
        return "BG_PROP_STARTS_FROM_BOTTOM"

    return result

def extractSpriteData(file):
    value = int.from_bytes(file.read(4), "little")

    if value == 0x833dfd8:
        return "sEnemyRoomData_Empty"
    
    return "(const u8*)" + hex(value)
    
def extractEffectPosition(file):
    value = int.from_bytes(file.read(1), "little")

    if value == 0xFF:
        return "UCHAR_MAX"
    
    return str(value)

def extractMusicTrack(file):
    value = int.from_bytes(file.read(2), "little")
    
    if value ==  0x0:
        return "MUSIC_NONE"
    
    if value ==  0x1:
        return "MUSIC_BRINSTAR"
    
    if value ==  0x2:
        return "MUSIC_TITLE_SCREEN"
    
    if value ==  0x3:
        return "MUSIC_SAVE_ELEVATOR_ROOM"
    
    if value ==  0x4:
        return "MUSIC_INTRO"
    
    if value ==  0x5:
        return "MUSIC_CHOZO_STATUE_HINT"
    
    if value ==  0x6:
        return "MUSIC_NORFAIR"
    
    if value ==  0x7:
        return "MUSIC_KRAID"
    
    if value ==  0x8:
        return "MUSIC_ESCAPE"
    
    if value ==  0x9:
        return "MUSIC_FILE_SELECT"
    
    if value ==  0xA:
        return "MUSIC_STATUE_ROOM"
    
    if value ==  0xB:
        return "MUSIC_BOSS_KILLED"
    
    if value ==  0xC:
        return "MUSIC_MAP_ROOM"
    
    if value ==  0xD:
        return "MUSIC_CHOZO_RUINS_DEPTH"
    
    if value ==  0xE:
        return "MUSIC_CHOZO_RUINS"
    
    if value ==  0xF:
        return "MUSIC_CHOZO_RUINS_LIGHT"
    
    if value ==  0x10:
        return "MUSIC_RIDLEY_IN_SPACE"
    
    if value ==  0x11:
        return "MUSIC_RIDLEY_LANDING"
    
    if value ==  0x12:
        return "MUSIC_CHOZO_STATUE_HINT_DELAY"
    
    if value ==  0x13:
        return "MUSIC_GETTING_FULLY_POWERED_SUIT_CUTSCENE"
    
    if value ==  0x14:
        return "MUSIC_ESCAPING_ZEBES_CUTSCENE"
    
    if value ==  0x15:
        return "MUSIC_CHOZO_VOICE_1"
    
    if value ==  0x16:
        return "MUSIC_CHOZO_VOICE_2"
    
    if value ==  0x17:
        return "MUSIC_BEFORE_RUINS_TEST_UNUSED"
    
    if value ==  0x18:
        return "MUSIC_ELEVATOR_ROOM"
    
    if value ==  0x19:
        return "MUSIC_BRINSTAR_REMIX"
    
    if value ==  0x1A:
        return "MUSIC_ESCAPE_SUCCESFUL"
    
    if value ==  0x1B:
        return "MUSIC_CREDITS"
    
    if value ==  0x1C:
        return "MUSIC_STATUE_ROOM_OPENED"
    
    if value ==  0x32:
        return "MUSIC_RIDLEY"
    
    if value ==  0x34:
        return "MUSIC_KRAID_BATTLE_WITH_INTRO"
    
    if value ==  0x35:
        return "MUSIC_RIDLEY_BATTLE"
    
    if value ==  0x36:
        return "MUSIC_LOADING_JINGLE"
    
    if value ==  0x37:
        return "MUSIC_GETTING_ITEM_JINGLE"
    
    if value ==  0x39:
        return "MUSIC_UNUSED"
    
    if value ==  0x3A:
        return "MUSIC_GETTING_TANK_JINGLE"
    
    if value ==  0x3B:
        return "MUSIC_TOURIAN"
    
    if value ==  0x3C:
        return "MUSIC_WORMS_BATTLE"
    
    if value ==  0x3D:
        return "MUSIC_MOTHER_BRAIN_BATTLE"
    
    if value ==  0x3E:
        return "MUSIC_CATTERPILLARS_BATTLE"
    
    if value ==  0x3F:
        return "MUSIC_IMAGO_COCOON_BATTLE"
    
    if value ==  0x40:
        return "MUSIC_IMAGO_BATTLE"
    
    if value ==  0x41:
        return "MUSIC_MECHA_RIDLEY_BATTLE"
    
    if value ==  0x42:
        return "MUSIC_GETTING_UNKNOWN_ITEM_JINGLE"
    
    if value ==  0x43:
        return "MUSIC_RUINS_TEST_BATTLE_WITH_INTRO"
    
    if value ==  0x44:
        return "MUSIC_ENTERING_TOURIAN_CUTSCENE"
    
    if value ==  0x45:
        return "MUSIC_ALARM_ACTIVATED"
    
    if value ==  0x46:
        return "MUSIC_STEALTH"
    
    if value ==  0x48:
        return "MUSIC_ENTERING_NORFAIR_CUTSCENE"
    
    if value ==  0x49:
        return "MUSIC_CHOZODIA_DETECTED"
    
    if value ==  0x4A:
        return "MUSIC_GETTING_FULLY_POWERED_SUIT_JINGLE"
    
    if value ==  0x4B:
        return "MUSIC_KRAID_BATTLE"
    
    if value ==  0x4C:
        return "MUSIC_RIDLEY_BATTLE_2"
    
    if value ==  0x4D:
        return "MUSIC_MECHA_RIDLEY_BATTLE_2"
    
    if value ==  0x4E:
        return "MUSIC_RUINS_TEST_BATTLE"
    
    if value ==  0x4F:
        return "MUSIC_CATTERPILLARS_BATTLE_2"
    
    if value ==  0x50:
        return "MUSIC_CRATERIA"
    
    if value ==  0x53:
        return "MUSIC_GAME_OVER"
    
    if value ==  0x54:
        return "MUSIC_UNKNOWN"
    
    if value ==  0x5A:
        return "MUSIC_CHOZODIA_SURFACE"
    
    if value ==  0x5B:
        return "MUSIC_MAP_ROOM_2"
    
    if value ==  0x5C:
        return "MUSIC_SAVE_ELEVATOR_ROOM_2"
    
    if value ==  0x5D:
        return "MUSIC_BEFORE_RUINS_TEST_ROOM"
    
    if value ==  0x5E:
        return "MUSIC_STEALTH_2"
    
    print("Music " + hex(value) + " doesn't exist")
    return "MUSIC_" + hex(value)

events = [
    "EVENT_NONE",
    "EVENT_EASY",
    "EVENT_HARD",
    "EVENT_ENTER_NORFAIR_DEMO_PLAYED",
    "EVENT_EXIT_KRAID_DEMO_PLAYED",
    "EVENT_ENTER_RIDLEY_DEMO_PLAYED",
    "EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED",
    "EVENT_ENTER_TOURIAN_DEMO_PLAYED",
    "EVENT_STATUE_LONG_BEAM_GRABBED",
    "EVENT_STATUE_BOMBS_GRABBED",
    "EVENT_STATUE_ICE_BEAM_GRABBED",
    "EVENT_STATUE_SPEEDBOOSTER_GRABBED",
    "EVENT_STATUE_HIGH_JUMP_GRABBED",
    "EVENT_STATUE_VARIA_SUIT_GRABBED",
    "EVENT_STATUE_WAVE_BEAM_GRABBED",
    "EVENT_STATUE_SCREW_ATTACK_GRABBED",
    "EVENT_POWER_GRIP_OBTAINED",
    "EVENT_CHOZO_PILLAR_FULLY_EXTENDED",
    "EVENT_HIGH_JUMP_OBTAINED",
    "EVENT_VARIA_SUIT_OBTAINED",
    "EVENT_CHARGE_BEAM_OBTAINED",
    "EVENT_SCREW_ATTACK_OBTAINED",
    "EVENT_SPACE_JUMP_OBTAINED",
    "EVENT_GRAVITY_SUIT_OBTAINED",
    "EVENT_PLASMA_BEAM_OBTAINED",
    "EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED",
    "EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED",
    "EVENT_DEOREM_KILLED_AT_SECOND_LOCATION",
    "EVENT_ACID_WORM_KILLED",
    "EVENT_KRAID_GADORA_KILLED",
    "EVENT_KRAID_KILLED",
    "EVENT_KRAID_ELEVATOR_STATUE_DESTROYED",
    "EVENT_CATERPILLAR_KILLED",
    "EVENT_IMAGO_TUNNEL_DISCOVERED",
    "EVENT_IMAGO_COCOON_KILLED",
    "EVENT_IMAGO_KILLED",
    "EVENT_RIDLEY_GADORA_KILLED",
    "EVENT_RIDLEY_KILLED",
    "EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED",
    "EVENT_MOTHER_BRAIN_KILLED",
    "EVENT_CROCOMIRE_KILLED",
    "EVENT_REPEL_MACHINE_KILLED",
    "EVENT_VIEWED_STATUE_ROOM",
    "EVENT_LONG_BEAM_DESSGEEGA_KILLED",
    "EVENT_THREE_HIVES_DESTROYED",
    "EVENT_BUGS_KILLED",
    "EVENT_ZIPLINES_ACTIVATED",
    "EVENT_PLANT_DESTROYED_LAVA",
    "EVENT_PLANT_DESTROYED_POST_VARIA",
    "EVENT_PLANT_DESTROYED_VARIA2",
    "EVENT_PLANT_DESTROYED_VARIA3",
    "EVENT_PLANT_DESTROYED_VARIA1",
    "EVENT_KRAID_BARISTUTES_KILLED",
    "EVENT_KRAID_STATUE_OPENED",
    "EVENT_RIDLEY_STATUE_OPENED",
    "EVENT_FIRST_METROID_ROOM_CLEARED",
    "EVENT_THIRD_METROID_ROOM_CLEARED",
    "EVENT_FIFTH_METROID_ROOM_CLEARED",
    "EVENT_SECOND_METROID_ROOM_CLEARED",
    "EVENT_SIXTH_METROID_ROOM_CLEARED",
    "EVENT_FOURTH_METROID_ROOM_CLEARED",
    "EVENT_ZEBETITE_ONE_DESTROYED",
    "EVENT_ZEBETITE_TWO_DESTROYED",
    "EVENT_ZEBETITE_THREE_DESTROYED",
    "EVENT_ZEBETITE_FOUR_DESTROYED",
    "EVENT_ESCAPED_ZEBES",
    "EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP",
    "EVENT_FULLY_POWERED_SUIT_OBTAINED",
    "EVENT_SKIPPED_VARIA_SUIT",
    "EVENT_CHOZOBLOCK",
    "EVENT_POWER_BOMB_STOLEN",
    "EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE",
    "EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO",
    "EVENT_GLASS_TUBE_BROKEN",
    "EVENT_MECHA_RIDLEY_KILLED",
    "EVENT_ESCAPED_CHOZODIA",
    "EVENT_AKI",
    "EVENT_BOMBATE",
    "EVENT_END_UNUSED",
]

effects = [
    "EFFECT_NONE",
    "EFFECT_WATER",
    "EFFECT_STRONG_LAVA",
    "EFFECT_WEAK_LAVA",
    "EFFECT_STRONG_LAVA_HEAT_HAZE",
    "EFFECT_ACID",
    "EFFECT_SNOWFLAKES_COLD_KNOCKBACK",
    "EFFECT_SNOWFLAKES_COLD",
    "EFFECT_HEAT_BG3_HAZE",
    "EFFECT_HEAT_BG2_BG3_HAZE",
    "EFFECT_BG3_GRADIENT",
    "EFFECT_BG2_GRADIENT",
    "EFFECT_HAZE_BG1_BG2_BG3",
]

def extractRoomEntry(file: BufferedReader):
    result = "{\n\t.tileset = "
    result += str(int.from_bytes(file.read(1), "little"))

    result += ",\n\t.Bg0Prop = "
    result += extractBgProp(file)
    result += ",\n\t.Bg1Prop = "
    result += extractBgProp(file)
    result += ",\n\t.Bg2Prop = "
    result += extractBgProp(file)
    result += ",\n\t.Bg3Prop = "
    result += extractBgProp(file)

    file.read(3) # Padding

    result += ",\n\t.pBG0Data = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))

    result += ",\n\t.pBG1Data = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))

    result += ",\n\t.pBG2Data = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))

    result += ",\n\t.pClipData = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))

    result += ",\n\t.pBG3Data = (const u8*)"
    result += hex(int.from_bytes(file.read(4), "little"))

    result += ",\n\t.Bg3Scrolling = "
    result += str(int.from_bytes(file.read(1), "little"))

    result += ",\n\t.transparency = "
    result += str(int.from_bytes(file.read(1), "little"))

    file.read(2) # Padding

    result += ",\n\t.pDefaultSpriteData = "
    result += extractSpriteData(file)
    result += ",\n\t.defaultSpriteset = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.firstSpritesetEvent = "
    result += events[int.from_bytes(file.read(1), "little")]

    file.read(2) # Padding

    result += ",\n\t.pFirstSpriteData = "
    result += extractSpriteData(file)
    result += ",\n\t.firstSpriteset = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.secondSpritesetEvent = "
    result += events[int.from_bytes(file.read(1), "little")]

    file.read(2) # Padding

    result += ",\n\t.pSecondSpriteData = "
    result += extractSpriteData(file)
    result += ",\n\t.secondSpriteset = "
    result += str(int.from_bytes(file.read(1), "little"))

    result += ",\n\t.mapX = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.mapY = "
    result += str(int.from_bytes(file.read(1), "little"))

    result += ",\n\t.effect = "
    result += effects[int.from_bytes(file.read(1), "little")]

    result += ",\n\t.effectY = "
    result += extractEffectPosition(file)

    file.read(1) # padding

    result += ",\n\t.musicTrack = "
    result += extractMusicTrack(file)

    result += "\n},\n"

    return result

def sign(value, size):
    limit = 0
    max = 0
    if size == 1:
        limit = 0x7F
        max = 0x100
    elif size == 2:
        limit = 0x7FFF
        max = 0x10000
    elif size == 4:
        limit = 0x7FFFFFFF
        max = 0x100000000

    if value > limit:
        value = -(max - value)

    return value

file = open("../mzm_us_baserom.gba", "rb")
def Func():
    #inputValue = input("Address : ")
    size = 115#int(input("Size : "))

    addr = 0x343d74#int(inputValue, 16)

    file.seek(addr)

    result = ""
    for x in range(0, size):
        result += extractRoomEntry(file)

    return result


f = open("rooms.txt", "a")
f.write(Func())
f.close()

file.close()
