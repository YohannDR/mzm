    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start call_LZ77_uncomp_vram
call_LZ77_uncomp_vram: @ 0x0800090c
    push {lr}
    bl LZ77_uncomp_vram
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start call_LZ77_uncomp_wram
call_LZ77_uncomp_wram: @ 0x08000918
    push {lr}
    bl LZ77_uncomp_wram
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start maybe_test_divarm_sqrt
maybe_test_divarm_sqrt: @ 0x08000924
    push {lr}
    movs r0, #1
    movs r1, #1
    bl divarm_div
    movs r0, #1
    movs r1, #1
    bl divarm_mod
    movs r0, #2
    bl sqrt
    pop {r0}
    bx r0

    thumb_func_start call_soundbias
call_soundbias: @ 0x08000940
    push {lr}
    bl soundbias_0
    svc #3
    bl soundbias_200
    pop {r0}
    bx r0

    thumb_func_start call_multiboot
call_multiboot: @ 0x08000950
    push {lr}
    bl multiboot
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start call_vblankintrwait
call_vblankintrwait: @ 0x0800095c
    push {lr}
    bl vblankintrwait
    pop {r0}
    bx r0
    .align 2, 0
