    .include "asm/macros.inc"
    .include "asm/constants.inc"

    .syntax unified

    thumb_func_start cpu_fast_set
cpu_fast_set: @ 0x08005190
    swi SYSCALL_CPUSetFast
    bx lr

    thumb_func_start cpu_set
cpu_set: @ 0x08005194
    swi SYSCALL_CPUSet
    bx lr

    thumb_func_start divarm_div
divarm_div: @ 0x08005198
    swi SYSCALL_DivArm
    bx lr

    thumb_func_start divarm_mod
divarm_mod: @ 0x0800519c
    swi SYSCALL_DivArm
    adds r0, r1, 0
    bx lr

    thumb_func_start LZ77_uncomp_vram
LZ77_uncomp_vram: @ 0x080051a4
    swi SYSCALL_LZ77UnCompVRAM
    bx lr

    thumb_func_start LZ77_uncomp_wram
LZ77_uncomp_wram: @ 0x080051a8
    swi SYSCALL_LZ77UnCompWRAM
    bx lr

    thumb_func_start midikey2freq
midikey2freq: @ 0x080051ac
    swi SYSCALL_MIDIKey2Freq
    bx lr

    thumb_func_start multiboot
multiboot: @ 0x080051b0
    movs r1, 1
    swi SYSCALL_MultiBoot
    bx lr

    thumb_func_start soundbias_0
soundbias_0: @ 0x080051b8
    movs r0, 0
    swi SYSCALL_SoundBiasChange
    bx lr

    thumb_func_start soundbias_200
soundbias_200: @ 0x080051c0
    movs r0, 1
    swi SYSCALL_SoundBiasChange
    bx lr

    thumb_func_start Sqrt
Sqrt: @ 0x080051c8
    swi SYSCALL_Sqrt
    bx lr

    thumb_func_start vblankintrwait
vblankintrwait: @ 0x080051cc
    movs r2, 0
    swi SYSCALL_VBlankIntrWait
    bx lr

    .align 2, 0 @ don't insert nops
