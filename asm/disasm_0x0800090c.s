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

    thumb_func_start update_input
update_input: @ 0x08000968
    push {r4, lr}
    ldr r0, lbl_0800098c @ =0x04000130
    ldrh r0, [r0]
    ldr r2, lbl_08000990 @ =0x000003ff
    adds r1, r2, #0
    bics r1, r0
    ldr r4, lbl_08000994 @ =0x03001380
    ldr r3, lbl_08000998 @ =0x0300137e
    ldrh r2, [r3]
    adds r0, r1, #0
    bics r0, r2
    strh r0, [r4]
    ldr r0, lbl_0800099c @ =0x0300137c
    strh r1, [r0]
    strh r1, [r3]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800098c: .4byte 0x04000130
lbl_08000990: .4byte 0x000003ff
lbl_08000994: .4byte 0x03001380
lbl_08000998: .4byte 0x0300137e
lbl_0800099c: .4byte 0x0300137c
