from array import array
from io import BufferedReader
import os
import shutil

DATA_PATH = "../data/"
subDirs: array = [
    "Sprites/"
]

shutil.rmtree(DATA_PATH, ignore_errors=False, onerror=None)

if not os.path.exists(DATA_PATH):
    # Create directories
    os.mkdir(DATA_PATH)
    for dir in subDirs:
        os.mkdir(DATA_PATH.__add__(dir))


rom: BufferedReader = open("../mzm_us_baserom.gba", "rb")
db: BufferedReader = open("../database.txt", "r")

line: str = db.readline()
while line != '':
    # Formatted as follows : name;size;address
    info: array = line.split(";")
    rom.seek(int(info[2], 16))
    data = rom.read(int(info[1]))
    
    output: BufferedReader = open("../data/".__add__(info[0]), "wb")
    output.write(bytearray(data))
    output.close()
    line = db.readline()

rom.close()