import argparse
from pathlib import Path

from lz import *


# decompress 087D8150-087D8355 to 03007400-0300761F


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("payload_path", type=str, help="Path to payload binary")
    
    args = parser.parse_args()
    payload_path = args.payload_path
    
    with open(payload_path, "rb") as f:
        decomp_bytes = f.read()
    
    comp_bytes = comp_lz_bios(decomp_bytes)
    
    with open(payload_path + ".lz", "wb") as f:
        f.write(comp_bytes)
    
