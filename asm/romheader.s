    .include "asm/macros.inc"

    arm_func_start start_code
start_code:
    b _start

header:
nintendo_logo:
    .space (0xa0 - 0x04)
game_title:
    .space 12
game_code:
    .space 4
maker_code:
    .space 2
magic_byte:
    .space 1
main_unit_code:
    .space 1
device_type:
    .space 1
reserved_1:
    .space 7
game_version:
    .space 1
complement_check:
    .space 1
reserved_2:
    .space 1
