    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start softreset
softreset: @ 0x08000804
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    bl sub_0805d034
    bl sub_080033dc
    ldr r0, lbl_080008c4 @ =0x04000208
    mov sb, r0
    movs r4, #0
    strh r4, [r0]
    ldr r6, lbl_080008c8 @ =0x04000200
    strh r4, [r6]
    ldr r1, lbl_080008cc @ =0x04000004
    mov r8, r1
    strh r4, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    strh r4, [r0]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r4, [r0]
    adds r1, #0x50
    movs r0, #0x10
    strh r0, [r1]
    subs r1, #4
    movs r0, #0xff
    strh r0, [r1]
    movs r5, #0
    str r5, [sp]
    ldr r0, lbl_080008d0 @ =0x040000d4
    mov r3, sp
    str r3, [r0]
    movs r1, #0x80
    lsls r1, r1, #0x12
    str r1, [r0, #4]
    ldr r1, lbl_080008d4 @ =0x85010000
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r3, [r0]
    movs r1, #0xc0
    lsls r1, r1, #0x12
    str r1, [r0, #4]
    ldr r1, lbl_080008d8 @ =0x85001f80
    str r1, [r0, #8]
    ldr r0, [r0, #8]
    bl clear_ram
    bl load_intr_code
    ldr r0, lbl_080008dc @ =softreset_vblank_callback
    bl set_vblank_callback
    bl read_sram
    bl init_sound
    ldr r1, lbl_080008e0 @ =0x00002401
    adds r0, r1, #0
    strh r0, [r6]
    movs r0, #8
    mov r3, r8
    strh r0, [r3]
    ldr r0, lbl_080008e4 @ =0x03000c70
    movs r2, #1
    strh r2, [r0]
    ldr r0, lbl_080008e8 @ =0x03000c72
    strh r5, [r0]
    ldr r0, lbl_080008ec @ =0x03000c74
    strb r4, [r0]
    ldr r0, lbl_080008f0 @ =0x0300003c
    strb r4, [r0]
    ldr r0, lbl_080008f4 @ =0x03000004
    strb r4, [r0]
    ldr r0, lbl_080008f8 @ =0x0300137c
    strh r5, [r0]
    ldr r0, lbl_080008fc @ =0x0300137e
    strh r5, [r0]
    ldr r0, lbl_08000900 @ =0x03001380
    strh r5, [r0]
    ldr r1, lbl_08000904 @ =0x04000202
    ldr r3, lbl_08000908 @ =0x0000ffff
    adds r0, r3, #0
    strh r0, [r1]
    mov r0, sb
    strh r2, [r0]
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080008c4: .4byte 0x04000208
lbl_080008c8: .4byte 0x04000200
lbl_080008cc: .4byte 0x04000004
lbl_080008d0: .4byte 0x040000d4
lbl_080008d4: .4byte 0x85010000
lbl_080008d8: .4byte 0x85001f80
lbl_080008dc: .4byte softreset_vblank_callback
lbl_080008e0: .4byte 0x00002401
lbl_080008e4: .4byte 0x03000c70
lbl_080008e8: .4byte 0x03000c72
lbl_080008ec: .4byte 0x03000c74
lbl_080008f0: .4byte 0x0300003c
lbl_080008f4: .4byte 0x03000004
lbl_080008f8: .4byte 0x0300137c
lbl_080008fc: .4byte 0x0300137e
lbl_08000900: .4byte 0x03001380
lbl_08000904: .4byte 0x04000202
lbl_08000908: .4byte 0x0000ffff

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
