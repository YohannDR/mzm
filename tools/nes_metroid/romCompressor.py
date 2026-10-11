import argparse
from pathlib import Path

from lz import *


# decompress 087DCF60-087F3396 to 0201C000-0203BFFF


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("rom_path", type=str, help="Path to NES ROM")
    
    args = parser.parse_args()
    rom_path = args.rom_path
    
    with open(rom_path, "rb") as f:
        decomp_bytes = f.read()
    decomp_bytes = decomp_bytes[0x10:]
    
    comp_bytes = comp_lz_custom(decomp_bytes)
    
    with open(rom_path + ".lz", "wb") as f:
        f.write(comp_bytes)
    
