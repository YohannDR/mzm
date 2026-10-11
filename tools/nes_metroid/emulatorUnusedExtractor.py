import argparse

from lz import *


# unused partial copy of emulator part 6


NESTROID_EMULATOR_UNUSED_ADDR_REL = -0x1EC
NESTROID_EMULATOR_UNUSED_SIZE = 0x1B0


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("emulator_path", type=str, help="Path to built emulator binary")
    parser.add_argument("output_path", type=str, help="Path where output unused emulator data should be written")
    
    args = parser.parse_args()
    
    with open(args.emulator_path, "rb") as f:
        f.seek(NESTROID_EMULATOR_UNUSED_ADDR_REL, 2) # relative to file end
        data = f.read(NESTROID_EMULATOR_UNUSED_SIZE)
    
    with open(args.output_path, "wb") as f:
        f.write(data)
    
