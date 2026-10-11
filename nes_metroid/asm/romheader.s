    .include "asm/macros.inc"

    .syntax unified

    arm_func_start start_code
start_code:
    bl _start

header:
nintendo_logo:
    .space (0xa0 - 0x04)
game_title:
    .space 12

    .global game_code
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

    .global game_version
game_version:
    .space 1
complement_check:
    .space 1
reserved_2:
    .space 1

@ Referenced in part5 by sub_0600E4D0, sub_0600E7B8
    .space 1
    .byte 0x11, 0x19, 0x19, '0', 'R', 'O', 'I', 'D', '_', '3', '_', 'B'
    .word sUnk_087F3398
    .word sUnk_087F7558

