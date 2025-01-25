from array import array
from io import BufferedReader, BytesIO
import shutil
import os
from fractions import Fraction
from decimal import Decimal
from math import modf

rom: BufferedReader = open("../mzm_us_baserom.gba", "rb")

DATA_PATH = "../src/data/"
FOLDER_PATH = ""
FILE_NAME = "particle_data.c"
FILE_PATH = DATA_PATH + FOLDER_PATH + FILE_NAME
db: BufferedReader = open(FILE_PATH, "r")

def GetOamDataSize(oam_frame_length: int) -> int:
    oam_data_size = int((oam_frame_length - 1) / 3)
    return oam_data_size

def GetSeconds(timer: int) -> Fraction:
    if timer == 0:
        return 0
    seconds: Fraction = Fraction(timer, 60)
    return seconds

def PrintSeconds(timer: str):
    timer_str: str = ""
    if "SECOND" in timer :
        timer_str = timer
    
    else:
        seconds: Fraction = GetSeconds(int(timer, 0))
        seconds_str: str = str(float(seconds))

        decimal, whole = modf(seconds)

        if seconds == Fraction(20, 60):
            timer_str = f"ONE_THIRD_SECOND"
        elif seconds == Fraction(40, 60):
            timer_str = f"TWO_THIRD_SECOND"
        elif seconds == Fraction(255, 60):
            timer_str = f"UCHAR_MAX"
        elif "." in seconds_str and len(seconds_str.split(".")[1]) < 4:
            timer_str = f"CONVERT_SECONDS({float(seconds)}f)"
        else:
            numer = seconds.numerator
            denom = seconds.denominator
            if numer > denom:
                timer_str = f"CONVERT_SECONDS({int(whole)}.f) + CONVERT_SECONDS({numer - int(whole) * denom}.f / {denom})"
            else:
                timer_str = f"CONVERT_SECONDS({numer}.f / {denom})"

    print(f"        .timer = {timer_str}")
    return

def OamDataSizeCleanup(line: str) -> str:
    before_size: array = line.split("[")
    after_size: array = before_size[1].split("]")
    oam_frame_length: int = int(after_size[0])
    oam_data_size: int = GetOamDataSize(oam_frame_length)
    oam_data_size_macro: str = f'OAM_DATA_SIZE({oam_data_size})'
    new_line: str = f'{before_size[0]}[{oam_data_size_macro}]{after_size[1]}'
    return new_line

def OamFrameDataCleanup(line: str) -> str:
    print(line, end="")
    line = db.readline()
    frames: array = []
    timers: array = []
    while ";" not in line:
        frame: str = line.strip().rstrip(",")
        timer: str = db.readline().strip().rstrip(",")
        frames.append(frame)
        if "UCHAR_MAX" in timer:
            timer = "0xFF"
        timers.append(timer)
        line = db.readline()
    for index in range(len(frames)):
        if "NULL" in frames[index]:
            print(f"    [{index}] = FRAME_DATA_TERMINATOR")
            continue
        print(f"    [{index}] = {'{'}")
        print(f"        .pFrame = {frames[index]},")
        PrintSeconds(timers[index])
        print(f"    {'}'},")
    print(line, end="")
    return

def OamCleanup():
    line: str = db.readline()
    while line != '':
        if "oam" in line.lower() and "FrameData" not in line and "Frame" in line and "[" in line and "OAM_DATA_SIZE" not in line:
            line = OamDataSizeCleanup(line)
        elif "FrameData" in line:
            OamFrameDataCleanup(line)
            line = ""
            #pass
        print(line, end="")
            
        line = db.readline()
    return

OamCleanup()
rom.close()
db.close()