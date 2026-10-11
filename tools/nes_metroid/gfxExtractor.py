import argparse
from pathlib import Path

from lz import *


"""
087F3398: decompress 087F33FC to 020350E0(size 07B0) (06:90e0, GFX_SamusSuitless)
087F339C: decompress 087F3A08 to 02034000(size 09A0) (06:8000, GFX_Samus)
087F33A0: decompress 087F4248 to 0202CD60(size 0520) (04:8d60, GFX_EndingSprites)
087F33A4: decompress 087F4540 to 02024D60(size 0400) (02:8d60, GFX_NorfairSprites)
087F33A8: decompress 087F4828 to 02021160(size 0400) (01:9160, GFX_BrinstarSprites)
087F33AC: decompress 087F4B88 to 02028D60(size 0400) (03:8d60, GFX_KraidSprites)
087F33B0: decompress 087F4F18 to 02029160(size 0400) (03:9160, GFX_RidleySprites)
087F33B4: decompress 087F524C to 02025160(size 0400) (02:9160, GFX_TourianSprites)
087F33B8: decompress 087F5574 to 02036CA0(size 0600) (06:aca0, GFX_TourBG)
087F33BC: decompress 087F59FC to 020372A0(size 0090) (06:b2a0, GFX_Zebetite)
087F33C0: decompress 087F5A8C to 02035EF0(size 0800) (06:9ef0, GFX_CREBG2)
087F33C4: decompress 087F5FA8 to 020373F0(size 00C0) (06:b3f0, GFX_RidlBG)
087F33C8: decompress 087F6068 to 0202D360(size 0200) (04:9360, GFX_KraiBG3)
087F33CC: decompress 087F61B4 to 02037330(size 00C0) (06:b330, GFX_KraiBG2)
087F33D0: decompress 087F6268 to 020369C0(size 02E0) (06:a9c0, GFX_BossBG)
087F33D4: decompress 087F6520 to 020366F0(size 0260) (06:a6f0, GFX_NorfBG1)
087F33D8: decompress 087F6760 to 02030D60(size 0450) (05:8d60, GFX_CREBG1)
087F33DC: decompress 087F6B18 to 02036950(size 0070) (06:a950, GFX_NorfBG2)
087F33E0: decompress 087F6B94 to 020374C0(size 0400) (06:b4c0, GFX_Font)
087F33E4: decompress 087F6D98 to 02020D60(size 0400) (01:8d60, GFX_TheEndFont)
087F33E8: decompress 087F7018 to 02035890(size 0010) (06:9890, GFX_ExclamationPoint)
087F33EC: decompress 087F7028 to 02034BE0(size 0500) (06:8be0, GFX_Title)
087F33F0: decompress 087F7344 to 020349A0(size 0100) (06:89a0, GFX_IntroSprites)
087F33F4: decompress 087F73F8 to 02035DA0(size 0150) (06:9da0, GFX_BrinBG1)
087F33F8: decompress 087F7544 to 02035980(size 0040) (06:9980, GFX_Solid)
"""

GFX_ENTRY_TABLE_PTR_ADDR = 0x7D80CC
GFX_ENTRY_NAMES = [
    "GFX_SamusSuitless",
    "GFX_Samus",
    "GFX_EndingSprites",
    "GFX_NorfairSprites",
    "GFX_BrinstarSprites",
    "GFX_KraidSprites",
    "GFX_RidleySprites",
    "GFX_TourianSprites",
    "GFX_TourBG",
    "GFX_Zebetite",
    "GFX_CREBG2",
    "GFX_RidlBG",
    "GFX_KraiBG3",
    "GFX_KraiBG2",
    "GFX_BossBG",
    "GFX_NorfBG1",
    "GFX_CREBG1",
    "GFX_NorfBG2",
    "GFX_Font",
    "GFX_TheEndFont",
    "GFX_ExclamationPoint",
    "GFX_Title",
    "GFX_IntroSprites",
    "GFX_BrinBG1",
    "GFX_Solid",
]
WRAM_NES_ROM_ADDR = 0x0201C000


def get_gfx_entry_data(zm_path):
    with open(zm_path, "rb") as f:
        f.seek(GFX_ENTRY_TABLE_PTR_ADDR)
        gfx_entry_table_addr = int.from_bytes(f.read(4), byteorder='little') - 0x08000000
        gfx_entry_end_addr = int.from_bytes(f.read(4), byteorder='little') - 0x08000000
        f.seek(gfx_entry_table_addr)
        gfx_entry_data = f.read(gfx_entry_end_addr - gfx_entry_table_addr)
    return gfx_entry_data, gfx_entry_table_addr


def extract_gfx(zm_path):
    gfx_entry_data, gfx_entry_table_addr = get_gfx_entry_data(zm_path)
    
    gfx_source_addr_rel = len(GFX_ENTRY_NAMES) * 2 * 2
    
    gfx_entry_decomp_bytes_list = []
    gfx_entry_comp_bytes_list = []
    
    for i, gfx_entry_name in enumerate(GFX_ENTRY_NAMES):
        gfx_entry_addr_rel = i * 2 * 2
        
        # unused
        gfx_destination_addr = WRAM_NES_ROM_ADDR + (int.from_bytes(
            gfx_entry_data[gfx_entry_addr_rel:gfx_entry_addr_rel+2],
            byteorder='little', signed=True) << 4)
        
        gfx_entry_decomp_bytes, gfx_comp_size = decomp_lz_bios(gfx_entry_data, gfx_source_addr_rel)
        gfx_entry_decomp_bytes_list.append(gfx_entry_decomp_bytes)
        gfx_entry_comp_bytes_list.append(gfx_entry_data[gfx_source_addr_rel:gfx_source_addr_rel+gfx_comp_size])
        
        gfx_source_next_offset = int.from_bytes(
            gfx_entry_data[gfx_entry_addr_rel+2:gfx_entry_addr_rel+4],
            byteorder='little', signed=True)
        assert gfx_source_next_offset == (gfx_comp_size + 3) & 0xfffc
        
        gfx_source_addr_rel += gfx_source_next_offset
    
    return gfx_entry_decomp_bytes_list, gfx_entry_comp_bytes_list


def save_gfx(output_folder, gfx_entry_comp_bytes_list):
    output_folder_obj = Path(output_folder)
    output_folder_obj.mkdir(parents=True, exist_ok=True)
    for name, decomp_bytes in zip(GFX_ENTRY_NAMES, gfx_entry_comp_bytes_list):
        with open(Path(args.output_folder, name + ".nes.lz"), "wb") as f:
            f.write(decomp_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("zm_path", type=str, help="Path to a Zero Mission ROM")
    parser.add_argument("output_folder", type=str, help="Folder where output LZ-compressed graphics should be written")
    
    args = parser.parse_args()
    
    _, gfx_entry_comp_bytes_list = extract_gfx(args.zm_path)
    save_gfx(args.output_folder, gfx_entry_comp_bytes_list)
    
