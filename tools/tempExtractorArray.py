def sign(value):
    if value > 0x7FFF:
        value = -(0x10000 - value)

    return value

file = open("../baserom_us.gba", "rb")

def Func():
    inputValue = input("Address : ")
    size = int(input("Size : "))

    addr = int(inputValue, 16)

    file.seek(addr)

    result = ""

    for x in range(1, size + 1):
        result += str(sign(int.from_bytes(file.read(2), "little")))

        #if x % 3 == 0 and x != 0:
        #    result += ",\n"
        #else:
        result += ", "

    print(result)
    Func()

Func()