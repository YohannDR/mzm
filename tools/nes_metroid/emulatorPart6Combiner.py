import argparse
from pathlib import Path


# Replaces part 6 built with the rest of emulator with part 6 built alone
# This duplicates the *libgcc.a:_call_via_rX.o(.text), as is required to match


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("emulator_path", type=str, help="Path to emulator binary")
    parser.add_argument("emulator_map_path", type=str, help="Path to emulator symbol file")
    parser.add_argument("emulator_part6_path", type=str, help="Path to emulator part6 binary")
    parser.add_argument("output_path", type=str, help="Path to output binary")
    
    args = parser.parse_args()
    
    with open(args.emulator_path, "rb") as f:
        emulator_bytes = f.read()
    with open(args.emulator_part6_path, "rb") as f:
        emulator_part6_bytes = f.read()
    
    with open(args.emulator_map_path, "r") as f:
        emulator_map_lines = f.readlines()
    
    for i, l in enumerate(emulator_map_lines):
        if l.strip().startswith("src/part6.o"):
            break
    load_address_line = emulator_map_lines[i-1]
    load_address_line = load_address_line[load_address_line.index("load address"):]
    load_address_line = load_address_line.split(" ")
    load_address = load_address_line[2]
    load_address = int(load_address, 16) - 0x08000000
    
    # assumes part 6 is the last thing in emulator
    emulator_bytes = emulator_bytes[:load_address] + emulator_part6_bytes
    
    with open(args.output_path, "wb") as f:
        f.write(emulator_bytes)
    
