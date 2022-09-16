from io import BufferedReader

def extractDoorType(file: BufferedReader):
    result = ""

    types = ["DOOR_TYPE_NONE", "DOOR_TYPE_AREA_CONNECTION", "DOOR_TYPE_NO_HATCH",
        "DOOR_TYPE_OPEN_HATCH", "DOOR_TYPE_CLOSED_HATCH", "DOOR_TYPE_REMOVE_MOTHER_SHIP",
        "DOOR_TYPE_SET_MOTHER_SHIP", "DOOR_TYPE_SET_MOTHER_SHIP"]

    value = int.from_bytes(file.read(1), "little")

    result += types[value & 0xF]
    result += " | DOOR_TYPE_EXISTS"

    if (value & 0x20):
        result += " | DOOR_TYPE_LOAD_EVENT_BASED_ROOM"

    if (value & 0x40):
        result += " | DOOR_TYPE_DISPLAYS_ROOM_LOCATION"

    return result

def extractDoor(file: BufferedReader):
    result = "{\n\t.type = "
    result += extractDoorType(file)
    result += ",\n\t.sourceRoom = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.xStart = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.xEnd = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.yStart = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.yEnd = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.destinationDoor = "
    result += str(int.from_bytes(file.read(1), "little"))
    result += ",\n\t.xExit = "
    result += str(sign(int.from_bytes(file.read(1), "little"), 1))
    result += ",\n\t.yExit = "
    result += str(sign(int.from_bytes(file.read(1), "little"), 1))
    result += "\n},\n"

    file.read(3) # padding

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

file = open("../baserom_us.gba", "rb")
def Func():
    #inputValue = input("Address : ")
    size = 246#int(input("Size : "))

    addr = 0x33fe14#int(inputValue, 16)

    file.seek(addr)

    result = ""
    for x in range(0, size):
        result += extractDoor(file)

    return result


f = open("doors.txt", "a")
f.write(Func())
f.close()

file.close()