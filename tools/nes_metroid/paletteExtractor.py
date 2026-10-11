import argparse
from pathlib import Path

from lz import *


# decompress 087F7558-087F7731 to 0600B800-0600B9FF


NES_PALETTE_PTR_ADDR = 0x7D80D0


def extract_palette(zm_path):
    with open(zm_path, "rb") as f:
        f.seek(NES_PALETTE_PTR_ADDR)
        nes_palette_addr = int.from_bytes(f.read(4), byteorder='little') - 0x08000000
        f.seek(nes_palette_addr)
        nes_palette_data = f.read(0x1000)
    
    decomp_bytes, comp_size = decomp_lz_bios(nes_palette_data, 0)
    comp_bytes = nes_palette_data[:comp_size]
    
    return decomp_bytes, comp_bytes


def save_palette(output_path, comp_bytes):
    with open(output_path, "wb") as f:
        f.write(comp_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("zm_path", type=str, help="Path to a Zero Mission ROM")
    parser.add_argument("output_path", type=str, help="Folder where output LZ-compressed palette should be written")
    
    args = parser.parse_args()
    
    _, comp_bytes = extract_palette(args.zm_path)
    save_palette(args.output_path, comp_bytes)
    
