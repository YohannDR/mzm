import argparse
from pathlib import Path

from lz import *


# decompress 087D8360-087DCDAF to 06000000-06008524
# decompress 087DCDB0-087DCEE0 to nothing


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("emulator_path", type=str, help="Path to emulator binary")
    parser.add_argument("output_path", type=str, help="Path to output binary")
    
    args = parser.parse_args()
    
    with open(args.emulator_path, "rb") as f:
        decomp_bytes = f.read()
    
    comp_bytes = comp_lz_custom(decomp_bytes)
    
    with open(args.output_path, "wb") as f:
        f.write(comp_bytes)
    
