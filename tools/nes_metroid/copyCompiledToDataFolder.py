import argparse
from pathlib import Path



def copy_compiled_to_data_folder(nes_metroid_path, decomp_path):
    with open(nes_metroid_path, "rb") as f:
        nes_metroid_data = f.read()
    
    with open(Path(decomp_path) / "data/nes_metroid.bin", "wb") as f:
        f.write(nes_metroid_data)
    with open(Path(decomp_path) / "include/extracted/data/nes_metroid.bin.inc", "w") as f:
        f.write(",".join([f"{b}u" for b in nes_metroid_data]))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("nes_metroid_path", type=str, help="Path to compiled NES Metroid binary")
    parser.add_argument("decomp_path", type=str, help="Decomp root folder")
    
    args = parser.parse_args()
    
    copy_compiled_to_data_folder(args.nes_metroid_path, args.decomp_path)
    
