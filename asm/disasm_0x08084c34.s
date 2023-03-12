    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_08084c34
sub_08084c34: @ 0x08084c34
    push {r4, r5, lr}
    adds r3, r0, #0
    ldr r1, lbl_08084c78 @ =0x08754bc4
    ldr r2, [r1]
    movs r4, #0x92
    lsls r4, r4, #1
    adds r0, r2, r4
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08084c72
    movs r5, #0xa1
    lsls r5, r5, #1
    adds r0, r2, r5
    adds r2, r0, r3
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08084c72
    subs r0, #1
    strb r0, [r2]
    ldr r1, [r1]
    adds r0, r1, r5
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08084c72
    adds r1, r1, r4
    adds r1, r1, r3
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08084c72:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08084c78: .4byte 0x08754bc4

    thumb_func_start sub_08084c7c
sub_08084c7c: @ 0x08084c7c
    push {r4, r5, r6, r7, lr}
    adds r2, r0, #0
    ldr r3, lbl_08084d04 @ =0x08754bc4
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x9a
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08084d80
    cmp r2, #0
    bne lbl_08084d0c
    adds r1, #0x9b
    movs r0, #0xc
    strb r0, [r1]
    movs r4, #0
    adds r6, r3, #0
    movs r7, #0x18
    movs r5, #0xc
    ldr r3, lbl_08084d08 @ =0x0854bfa0
lbl_08084ca2:
    ldr r1, [r6]
    adds r2, r4, #6
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r1, r0
    adds r1, r1, r2
    ldrb r0, [r3]
    strb r0, [r1]
    ldr r0, [r6]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #1]
    strb r1, [r0]
    ldr r0, [r6]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #2]
    strb r1, [r0]
    ldr r2, [r6]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #4]
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #6]
    strh r1, [r0]
    movs r1, #0xfc
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r7
    ldr r1, [r3, #8]
    str r1, [r0]
    adds r7, #4
    adds r5, #2
    adds r3, #0xc
    adds r4, #1
    cmp r4, #5
    ble lbl_08084ca2
    b lbl_08084ede
    .align 2, 0
lbl_08084d04: .4byte 0x08754bc4
lbl_08084d08: .4byte 0x0854bfa0
lbl_08084d0c:
    adds r1, #0x9b
    movs r0, #0x11
    strb r0, [r1]
    movs r4, #0
    adds r6, r3, #0
    movs r7, #0x18
    movs r5, #0xc
    ldr r3, lbl_08084d7c @ =0x0854bfe8
lbl_08084d1c:
    ldr r1, [r6]
    adds r2, r4, #6
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r1, r0
    adds r1, r1, r2
    ldrb r0, [r3]
    strb r0, [r1]
    ldr r0, [r6]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #1]
    strb r1, [r0]
    ldr r0, [r6]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #2]
    strb r1, [r0]
    ldr r2, [r6]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #4]
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #6]
    strh r1, [r0]
    movs r1, #0xfc
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r7
    ldr r1, [r3, #8]
    str r1, [r0]
    adds r7, #4
    adds r5, #2
    adds r3, #0xc
    adds r4, #1
    cmp r4, #0xa
    ble lbl_08084d1c
    b lbl_08084ede
    .align 2, 0
lbl_08084d7c: .4byte 0x0854bfe8
lbl_08084d80:
    cmp r2, #0
    bne lbl_08084df8
    adds r1, #0x9b
    movs r0, #0xf
    strb r0, [r1]
    movs r4, #0
    adds r6, r3, #0
    movs r7, #0x18
    movs r5, #0xc
    ldr r3, lbl_08084df4 @ =0x0854bd9c
lbl_08084d94:
    ldr r1, [r6]
    adds r2, r4, #6
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r1, r0
    adds r1, r1, r2
    ldrb r0, [r3]
    strb r0, [r1]
    ldr r0, [r6]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #1]
    strb r1, [r0]
    ldr r0, [r6]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #2]
    strb r1, [r0]
    ldr r2, [r6]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #4]
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #6]
    strh r1, [r0]
    movs r1, #0xfc
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r7
    ldr r1, [r3, #8]
    str r1, [r0]
    adds r7, #4
    adds r5, #2
    adds r3, #0xc
    adds r4, #1
    cmp r4, #8
    ble lbl_08084d94
    b lbl_08084ede
    .align 2, 0
lbl_08084df4: .4byte 0x0854bd9c
lbl_08084df8:
    cmp r2, #1
    bne lbl_08084e70
    adds r1, #0x9b
    movs r0, #0x11
    strb r0, [r1]
    movs r4, #0
    adds r6, r3, #0
    movs r7, #0x18
    movs r5, #0xc
    ldr r3, lbl_08084e6c @ =0x0854be08
lbl_08084e0c:
    ldr r1, [r6]
    adds r2, r4, #6
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r1, r0
    adds r1, r1, r2
    ldrb r0, [r3]
    strb r0, [r1]
    ldr r0, [r6]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #1]
    strb r1, [r0]
    ldr r0, [r6]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #2]
    strb r1, [r0]
    ldr r2, [r6]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #4]
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #6]
    strh r1, [r0]
    movs r1, #0xfc
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r7
    ldr r1, [r3, #8]
    str r1, [r0]
    adds r7, #4
    adds r5, #2
    adds r3, #0xc
    adds r4, #1
    cmp r4, #0xa
    ble lbl_08084e0c
    b lbl_08084ede
    .align 2, 0
lbl_08084e6c: .4byte 0x0854be08
lbl_08084e70:
    adds r1, #0x9b
    movs r0, #0x17
    strb r0, [r1]
    movs r4, #0
    adds r6, r3, #0
    movs r7, #0x18
    movs r5, #0xc
    ldr r3, lbl_08084ee4 @ =0x0854be8c
lbl_08084e80:
    ldr r1, [r6]
    adds r2, r4, #6
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r1, r0
    adds r1, r1, r2
    ldrb r0, [r3]
    strb r0, [r1]
    ldr r0, [r6]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #1]
    strb r1, [r0]
    ldr r0, [r6]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r2
    ldrb r1, [r3, #2]
    strb r1, [r0]
    ldr r2, [r6]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #4]
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r5
    ldrh r1, [r3, #6]
    strh r1, [r0]
    movs r1, #0xfc
    lsls r1, r1, #1
    adds r0, r2, r1
    adds r0, r0, r7
    ldr r1, [r3, #8]
    str r1, [r0]
    adds r7, #4
    adds r5, #2
    adds r3, #0xc
    adds r4, #1
    cmp r4, #0x10
    ble lbl_08084e80
lbl_08084ede:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08084ee4: .4byte 0x0854be8c

    thumb_func_start sub_08084ee8
sub_08084ee8: @ 0x08084ee8
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    ldr r1, lbl_08084f08 @ =0x08754bc4
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0x9a
    ldrb r0, [r0]
    adds r7, r1, #0
    cmp r0, #1
    bne lbl_08084f10
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r2, r0
    adds r1, r1, r6
    ldr r5, lbl_08084f0c @ =0x0854bf58
    b lbl_08084f1a
    .align 2, 0
lbl_08084f08: .4byte 0x08754bc4
lbl_08084f0c: .4byte 0x0854bf58
lbl_08084f10:
    movs r0, #0x92
    lsls r0, r0, #1
    adds r1, r2, r0
    adds r1, r1, r6
    ldr r5, lbl_08084fac @ =0x0854bd54
lbl_08084f1a:
    lsls r4, r6, #1
    adds r3, r4, r6
    lsls r3, r3, #2
    adds r2, r3, r5
    ldrb r0, [r2]
    strb r0, [r1]
    ldr r0, [r7]
    movs r1, #0xa1
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r6
    ldrb r1, [r2, #1]
    strb r1, [r0]
    ldr r0, [r7]
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r6
    ldrb r1, [r2, #2]
    strb r1, [r0]
    ldr r0, [r7]
    mov ip, r0
    movs r0, #0xbf
    lsls r0, r0, #1
    add r0, ip
    adds r0, r0, r4
    ldrh r1, [r2, #4]
    strh r1, [r0]
    movs r0, #0xdd
    lsls r0, r0, #1
    add r0, ip
    adds r0, r0, r4
    ldrh r1, [r2, #6]
    strh r1, [r0]
    lsls r0, r6, #2
    movs r1, #0xfc
    lsls r1, r1, #1
    add r1, ip
    adds r1, r1, r0
    adds r5, #8
    adds r3, r3, r5
    ldr r0, [r3]
    str r0, [r1]
    movs r2, #0
    ldr r0, [r7]
    adds r0, #0x9b
    ldrb r0, [r0]
    subs r0, #6
    cmp r2, r0
    bge lbl_08084f9e
    adds r3, r7, #0
    movs r5, #0x92
    lsls r5, r5, #1
    movs r4, #0
lbl_08084f86:
    ldr r0, [r3]
    adds r1, r2, #6
    adds r0, r0, r5
    adds r0, r0, r1
    strb r4, [r0]
    adds r2, #1
    ldr r0, [r3]
    adds r0, #0x9b
    ldrb r0, [r0]
    subs r0, #6
    cmp r2, r0
    blt lbl_08084f86
lbl_08084f9e:
    ldr r0, [r7]
    adds r0, #0x9b
    movs r1, #6
    strb r1, [r0]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08084fac: .4byte 0x0854bd54

    thumb_func_start load_in_game_timer_ending_graphics
load_in_game_timer_ending_graphics: @ 0x08084fb0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    movs r1, #0
    ldr r0, lbl_080850c8 @ =0x03000150
    ldrb r4, [r0]
    ldr r6, lbl_080850cc @ =0x085a0a30
    ldr r7, lbl_080850d0 @ =0x085a0cb0
    ldr r2, lbl_080850d4 @ =0x08754bc4
    mov sl, r2
    cmp r4, #9
    ble lbl_08084fd4
lbl_08084fcc:
    subs r4, #0xa
    adds r1, #1
    cmp r4, #9
    bgt lbl_08084fcc
lbl_08084fd4:
    movs r5, #0
    ldrb r2, [r0, #1]
    lsls r4, r4, #6
    mov r8, r4
    cmp r2, #9
    ble lbl_08084fe8
lbl_08084fe0:
    subs r2, #0xa
    adds r5, #1
    cmp r2, #9
    bgt lbl_08084fe0
lbl_08084fe8:
    movs r3, #0
    mov ip, r3
    ldrb r4, [r0, #2]
    lsls r5, r5, #6
    lsls r2, r2, #6
    mov sb, r2
    cmp r4, #9
    ble lbl_08085002
lbl_08084ff8:
    subs r4, #0xa
    movs r0, #1
    add ip, r0
    cmp r4, #9
    bgt lbl_08084ff8
lbl_08085002:
    cmp r1, #0
    beq lbl_08085024
    lsls r3, r1, #6
    ldr r0, lbl_080850d8 @ =0x040000d4
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080850dc @ =0x06010000
    str r1, [r0, #4]
    ldr r2, lbl_080850e0 @ =0x80000020
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080850e4 @ =0x06010400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_08085024:
    mov r3, r8
    ldr r0, lbl_080850d8 @ =0x040000d4
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080850e8 @ =0x06010040
    str r1, [r0, #4]
    ldr r2, lbl_080850e0 @ =0x80000020
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080850ec @ =0x06010440
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r3, r5, #0
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080850f0 @ =0x060100a0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080850f4 @ =0x060104a0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    mov r3, sb
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080850f8 @ =0x060100e0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080850fc @ =0x060104e0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    mov r1, ip
    lsls r3, r1, #6
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_08085100 @ =0x06010140
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_08085104 @ =0x06010540
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    lsls r3, r4, #6
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_08085108 @ =0x06010180
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_0808510c @ =0x06010580
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r1, #0
    movs r4, #0
    mov r2, sl
    ldr r0, [r2]
    adds r0, #0x99
    ldrb r5, [r0]
    cmp r5, #0x63
    ble lbl_08085114
lbl_080850bc:
    subs r5, #0x64
    adds r1, #1
    cmp r5, #0x63
    bgt lbl_080850bc
    b lbl_08085114
    .align 2, 0
lbl_080850c8: .4byte 0x03000150
lbl_080850cc: .4byte 0x085a0a30
lbl_080850d0: .4byte 0x085a0cb0
lbl_080850d4: .4byte 0x08754bc4
lbl_080850d8: .4byte 0x040000d4
lbl_080850dc: .4byte 0x06010000
lbl_080850e0: .4byte 0x80000020
lbl_080850e4: .4byte 0x06010400
lbl_080850e8: .4byte 0x06010040
lbl_080850ec: .4byte 0x06010440
lbl_080850f0: .4byte 0x060100a0
lbl_080850f4: .4byte 0x060104a0
lbl_080850f8: .4byte 0x060100e0
lbl_080850fc: .4byte 0x060104e0
lbl_08085100: .4byte 0x06010140
lbl_08085104: .4byte 0x06010540
lbl_08085108: .4byte 0x06010180
lbl_0808510c: .4byte 0x06010580
lbl_08085110:
    subs r5, #0xa
    adds r4, #1
lbl_08085114:
    cmp r5, #9
    bgt lbl_08085110
    cmp r1, #0
    beq lbl_0808514c
    lsls r3, r1, #6
    ldr r0, lbl_0808513c @ =0x040000d4
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_08085140 @ =0x060101c0
    str r1, [r0, #4]
    ldr r2, lbl_08085144 @ =0x80000020
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_08085148 @ =0x060105c0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    b lbl_08085150
    .align 2, 0
lbl_0808513c: .4byte 0x040000d4
lbl_08085140: .4byte 0x060101c0
lbl_08085144: .4byte 0x80000020
lbl_08085148: .4byte 0x060105c0
lbl_0808514c:
    cmp r4, #0
    beq lbl_0808516e
lbl_08085150:
    lsls r3, r4, #6
    ldr r0, lbl_0808519c @ =0x040000d4
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080851a0 @ =0x06010200
    str r1, [r0, #4]
    ldr r2, lbl_080851a4 @ =0x80000020
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080851a8 @ =0x06010600
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_0808516e:
    lsls r3, r5, #6
    ldr r0, lbl_0808519c @ =0x040000d4
    adds r1, r3, r6
    str r1, [r0]
    ldr r1, lbl_080851ac @ =0x06010240
    str r1, [r0, #4]
    ldr r2, lbl_080851a4 @ =0x80000020
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    adds r1, r3, r7
    str r1, [r0]
    ldr r1, lbl_080851b0 @ =0x06010640
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808519c: .4byte 0x040000d4
lbl_080851a0: .4byte 0x06010200
lbl_080851a4: .4byte 0x80000020
lbl_080851a8: .4byte 0x06010600
lbl_080851ac: .4byte 0x06010240
lbl_080851b0: .4byte 0x06010640

    thumb_func_start vblank_code_during_gallery
vblank_code_during_gallery: @ 0x080851b4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r6, lbl_08085214 @ =0x040000d4
    ldr r0, lbl_08085218 @ =0x03000e7c
    str r0, [r6]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r6, #4]
    ldr r0, lbl_0808521c @ =0x84000100
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    ldr r0, lbl_08085220 @ =0x08754bc4
    ldr r3, [r0]
    ldrb r2, [r3, #6]
    adds r7, r0, #0
    cmp r2, #1
    bne lbl_0808522c
    adds r0, r3, #0
    adds r0, #0x10
    str r0, [r6]
    adds r5, r3, #0
    adds r5, #0x90
    ldr r0, [r5]
    movs r2, #0xc0
    lsls r2, r2, #0x13
    adds r0, r0, r2
    str r0, [r6, #4]
    ldr r1, lbl_08085224 @ =0x80000020
    str r1, [r6, #8]
    ldr r0, [r6, #8]
    adds r0, r3, #0
    adds r0, #0x50
    str r0, [r6]
    adds r4, r3, #0
    adds r4, #0x94
    ldr r0, [r4]
    adds r0, r0, r2
    str r0, [r6, #4]
    str r1, [r6, #8]
    ldr r0, [r6, #8]
    movs r3, #0
    str r3, [sp]
    mov r0, sp
    str r0, [r6]
    ldr r0, [r5]
    ldr r2, lbl_08085228 @ =0x06000800
    b lbl_0808526a
    .align 2, 0
lbl_08085214: .4byte 0x040000d4
lbl_08085218: .4byte 0x03000e7c
lbl_0808521c: .4byte 0x84000100
lbl_08085220: .4byte 0x08754bc4
lbl_08085224: .4byte 0x80000020
lbl_08085228: .4byte 0x06000800
lbl_0808522c:
    cmp r2, #0
    beq lbl_08085284
    adds r0, r3, #0
    adds r0, #0x10
    str r0, [r6]
    adds r5, r3, #0
    adds r5, #0x90
    ldr r0, [r5]
    ldr r2, lbl_080852ec @ =0x06000800
    adds r0, r0, r2
    str r0, [r6, #4]
    ldr r1, lbl_080852f0 @ =0x80000020
    str r1, [r6, #8]
    ldr r0, [r6, #8]
    adds r0, r3, #0
    adds r0, #0x50
    str r0, [r6]
    adds r4, r3, #0
    adds r4, #0x94
    ldr r0, [r4]
    adds r0, r0, r2
    str r0, [r6, #4]
    str r1, [r6, #8]
    ldr r0, [r6, #8]
    movs r3, #0
    str r3, [sp]
    mov r0, sp
    str r0, [r6]
    ldr r0, [r5]
    movs r2, #0xc0
    lsls r2, r2, #0x13
lbl_0808526a:
    adds r0, r0, r2
    str r0, [r6, #4]
    ldr r1, lbl_080852f4 @ =0x85000010
    str r1, [r6, #8]
    ldr r0, [r6, #8]
    str r3, [sp]
    mov r3, sp
    str r3, [r6]
    ldr r0, [r4]
    adds r0, r0, r2
    str r0, [r6, #4]
    str r1, [r6, #8]
    ldr r0, [r6, #8]
lbl_08085284:
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldr r1, [r7]
    movs r3, #0xb0
    lsls r3, r3, #2
    adds r0, r1, r3
    ldrh r0, [r0]
    strh r0, [r2]
    adds r2, #0x50
    ldr r0, lbl_080852f8 @ =0x000002c2
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_080852fc @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_08085300 @ =0x030013b0
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_08085304 @ =0x04000054
    ldr r0, lbl_08085308 @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0x42
    ldr r0, lbl_0808530c @ =0x030013b6
    ldrh r0, [r0]
    lsrs r0, r0, #4
    subs r3, #0xc1
    adds r2, r3, #0
    ands r0, r2
    strh r0, [r1]
    adds r1, #4
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_08085310 @ =0x030013be
    ldrh r0, [r0]
    lsrs r0, r0, #4
    ands r0, r2
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_08085314 @ =0x030013c2
    ldrh r0, [r0]
    lsrs r0, r0, #4
    ands r0, r2
    strh r0, [r1]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080852ec: .4byte 0x06000800
lbl_080852f0: .4byte 0x80000020
lbl_080852f4: .4byte 0x85000010
lbl_080852f8: .4byte 0x000002c2
lbl_080852fc: .4byte 0x030013b2
lbl_08085300: .4byte 0x030013b0
lbl_08085304: .4byte 0x04000054
lbl_08085308: .4byte 0x030013ae
lbl_0808530c: .4byte 0x030013b6
lbl_08085310: .4byte 0x030013be
lbl_08085314: .4byte 0x030013c2

    thumb_func_start vblank_code_during_end_screen
vblank_code_during_end_screen: @ 0x08085318
    ldr r1, lbl_08085384 @ =0x040000d4
    ldr r0, lbl_08085388 @ =0x03000e7c
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0808538c @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldr r0, lbl_08085390 @ =0x08754bc4
    ldr r1, [r0]
    movs r3, #0xb0
    lsls r3, r3, #2
    adds r0, r1, r3
    ldrh r0, [r0]
    strh r0, [r2]
    adds r2, #0x50
    ldr r0, lbl_08085394 @ =0x000002c2
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_08085398 @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0808539c @ =0x030013b0
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080853a0 @ =0x04000054
    ldr r0, lbl_080853a4 @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_080853a8 @ =0x04000014
    ldr r0, lbl_080853ac @ =0x030013b8
    ldrh r2, [r0]
    ldr r1, lbl_080853b0 @ =0x000001ff
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    adds r3, #4
    ldr r0, lbl_080853b4 @ =0x030013bc
    ldrh r2, [r0]
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_080853b8 @ =0x0400001c
    ldr r0, lbl_080853bc @ =0x030013c0
    ldrh r0, [r0]
    ands r1, r0
    strh r1, [r2]
    bx lr
    .align 2, 0
lbl_08085384: .4byte 0x040000d4
lbl_08085388: .4byte 0x03000e7c
lbl_0808538c: .4byte 0x84000100
lbl_08085390: .4byte 0x08754bc4
lbl_08085394: .4byte 0x000002c2
lbl_08085398: .4byte 0x030013b2
lbl_0808539c: .4byte 0x030013b0
lbl_080853a0: .4byte 0x04000054
lbl_080853a4: .4byte 0x030013ae
lbl_080853a8: .4byte 0x04000014
lbl_080853ac: .4byte 0x030013b8
lbl_080853b0: .4byte 0x000001ff
lbl_080853b4: .4byte 0x030013bc
lbl_080853b8: .4byte 0x0400001c
lbl_080853bc: .4byte 0x030013c0

    thumb_func_start vblank_code_during_unlocked_options
vblank_code_during_unlocked_options: @ 0x080853c0
    push {r4, lr}
    ldr r1, lbl_0808543c @ =0x040000d4
    ldr r0, lbl_08085440 @ =0x03000e7c
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08085444 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_08085448 @ =0x08754bc4
    ldr r3, [r0]
    movs r2, #0xb0
    lsls r2, r2, #2
    adds r0, r3, r2
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x50
    ldr r4, lbl_0808544c @ =0x000002c2
    adds r0, r3, r4
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_08085450 @ =0x04000052
    ldr r0, lbl_08085454 @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_08085458 @ =0x030013b0
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0808545c @ =0x04000054
    ldr r0, lbl_08085460 @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    subs r2, #0x12
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r3, r1
    ldrh r0, [r0]
    lsls r0, r0, #8
    movs r4, #0xc0
    lsls r4, r4, #1
    adds r1, r3, r4
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    adds r2, #4
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r3, r1
    ldrh r0, [r0]
    lsls r0, r0, #8
    adds r4, #0x3c
    adds r1, r3, r4
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808543c: .4byte 0x040000d4
lbl_08085440: .4byte 0x03000e7c
lbl_08085444: .4byte 0x84000100
lbl_08085448: .4byte 0x08754bc4
lbl_0808544c: .4byte 0x000002c2
lbl_08085450: .4byte 0x04000052
lbl_08085454: .4byte 0x030013b2
lbl_08085458: .4byte 0x030013b0
lbl_0808545c: .4byte 0x04000054
lbl_08085460: .4byte 0x030013ae

    thumb_func_start credits_init
credits_init: @ 0x08085464
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    sub sp, #4
    ldr r4, lbl_080855ac @ =0x04000208
    movs r6, #0
    strh r6, [r4]
    ldr r2, lbl_080855b0 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_080855b4 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_080855b8 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_080855bc @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_080855c0 @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r5, #1
    strh r5, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r6, [r0]
    strh r6, [r4]
    ldr r0, lbl_080855c4 @ =vblank_code_during_gallery
    mov r8, r0
    bl CallbackSetVBlank
    strh r5, [r4]
    movs r5, #0
    str r5, [sp]
    ldr r4, lbl_080855c8 @ =0x040000d4
    mov r1, sp
    str r1, [r4]
    ldr r0, lbl_080855cc @ =0x030016c4
    str r0, [r4, #4]
    ldr r0, lbl_080855d0 @ =0x8500018a
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    bl ClearGfxRam
    ldr r0, lbl_080855d4 @ =0x085b2aa0
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_080855d8 @ =0x085ba318
    ldr r1, lbl_080855dc @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r0, lbl_080855e0 @ =0x085be8c8
    ldr r1, lbl_080855e4 @ =0x0600d800
    bl LZ77UncompVRAM
    ldr r0, lbl_080855e8 @ =0x0854e2f0
    ldr r1, lbl_080855ec @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_080855f0 @ =0x0854a734
    str r0, [r4]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r4, #4]
    ldr r0, lbl_080855f4 @ =0x800000f0
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r0, lbl_080855f8 @ =0x0854a6d4
    str r0, [r4]
    ldr r0, lbl_080855fc @ =0x050001a0
    str r0, [r4, #4]
    ldr r0, lbl_08085600 @ =0x80000030
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, lbl_08085604 @ =0x04000008
    ldr r2, lbl_08085608 @ =0x00001e08
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_0808560c @ =0x00001f09
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08085610 @ =0x00009c02
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08085614 @ =0x00009a0b
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08085618 @ =0x03001382
    strb r6, [r0]
    bl ResetFreeOAM
    ldr r0, lbl_0808561c @ =0x030013b4
    strh r5, [r0]
    ldr r0, lbl_08085620 @ =0x030013b6
    movs r1, #0x80
    lsls r1, r1, #5
    adds r2, r1, #0
    strh r2, [r0]
    ldr r0, lbl_08085624 @ =0x030013b8
    strh r5, [r0]
    ldr r0, lbl_08085628 @ =0x030013ba
    strh r2, [r0]
    ldr r0, lbl_0808562c @ =0x030013bc
    strh r5, [r0]
    ldr r0, lbl_08085630 @ =0x030013be
    strh r5, [r0]
    ldr r0, lbl_08085634 @ =0x030013c0
    strh r5, [r0]
    ldr r0, lbl_08085638 @ =0x030013c2
    strh r5, [r0]
    ldr r0, lbl_0808563c @ =0x04000010
    strh r5, [r0]
    adds r0, #2
    strh r2, [r0]
    ldr r1, lbl_08085640 @ =0x04000014
    movs r0, #4
    strh r0, [r1]
    ldr r0, lbl_08085644 @ =0x04000016
    strh r2, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    ldr r0, lbl_08085648 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0x80
    strh r0, [r1, #0xe]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r0, #0xf0
    lsls r0, r0, #4
    strh r0, [r2]
    ldr r2, lbl_0808564c @ =0x000002c2
    adds r1, r1, r2
    movs r0, #0xc4
    strh r0, [r1]
    ldr r0, lbl_08085650 @ =0x030013b0
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08085654 @ =0x030013b2
    strh r5, [r0]
    ldr r0, lbl_08085658 @ =0x030013ae
    strh r1, [r0]
    bl _call_via_r8
    movs r0, #0x1b
    movs r1, #0
    bl PlayMusic
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080855ac: .4byte 0x04000208
lbl_080855b0: .4byte 0x04000004
lbl_080855b4: .4byte 0x0000ffef
lbl_080855b8: .4byte 0x04000200
lbl_080855bc: .4byte 0x0000fffd
lbl_080855c0: .4byte 0x04000202
lbl_080855c4: .4byte vblank_code_during_gallery
lbl_080855c8: .4byte 0x040000d4
lbl_080855cc: .4byte 0x030016c4
lbl_080855d0: .4byte 0x8500018a
lbl_080855d4: .4byte 0x085b2aa0
lbl_080855d8: .4byte 0x085ba318
lbl_080855dc: .4byte 0x0600e000
lbl_080855e0: .4byte 0x085be8c8
lbl_080855e4: .4byte 0x0600d800
lbl_080855e8: .4byte 0x0854e2f0
lbl_080855ec: .4byte 0x06008000
lbl_080855f0: .4byte 0x0854a734
lbl_080855f4: .4byte 0x800000f0
lbl_080855f8: .4byte 0x0854a6d4
lbl_080855fc: .4byte 0x050001a0
lbl_08085600: .4byte 0x80000030
lbl_08085604: .4byte 0x04000008
lbl_08085608: .4byte 0x00001e08
lbl_0808560c: .4byte 0x00001f09
lbl_08085610: .4byte 0x00009c02
lbl_08085614: .4byte 0x00009a0b
lbl_08085618: .4byte 0x03001382
lbl_0808561c: .4byte 0x030013b4
lbl_08085620: .4byte 0x030013b6
lbl_08085624: .4byte 0x030013b8
lbl_08085628: .4byte 0x030013ba
lbl_0808562c: .4byte 0x030013bc
lbl_08085630: .4byte 0x030013be
lbl_08085634: .4byte 0x030013c0
lbl_08085638: .4byte 0x030013c2
lbl_0808563c: .4byte 0x04000010
lbl_08085640: .4byte 0x04000014
lbl_08085644: .4byte 0x04000016
lbl_08085648: .4byte 0x08754bc4
lbl_0808564c: .4byte 0x000002c2
lbl_08085650: .4byte 0x030013b0
lbl_08085654: .4byte 0x030013b2
lbl_08085658: .4byte 0x030013ae

    thumb_func_start display_credit_line
display_credit_line: @ 0x0808565c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, lbl_080856c8 @ =0x0854c10c
    lsls r1, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r4, r1, r4
    movs r6, #0
    ldr r5, lbl_080856cc @ =0x08754bc4
    movs r3, #0
lbl_08085676:
    ldr r1, [r5]
    lsls r2, r6, #1
    adds r0, r1, #0
    adds r0, #0x10
    adds r0, r0, r2
    strh r3, [r0]
    adds r1, #0x50
    adds r1, r1, r2
    strh r3, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x1f
    bls lbl_08085676
    ldrb r0, [r4]
    movs r1, #0xe0
    lsls r1, r1, #8
    mov ip, r1
    cmp r0, #0
    beq lbl_080856ae
    movs r1, #0xd0
    lsls r1, r1, #8
    mov ip, r1
    cmp r0, #1
    bne lbl_080856ae
    movs r0, #0xf0
    lsls r0, r0, #8
    mov ip, r0
lbl_080856ae:
    movs r2, #0
    mov sl, r2
    movs r6, #0
    ldrb r0, [r4]
    cmp r0, #0xd
    bls lbl_080856bc
    b lbl_080859de
lbl_080856bc:
    lsls r0, r0, #2
    ldr r1, lbl_080856d0 @ =lbl_080856d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080856c8: .4byte 0x0854c10c
lbl_080856cc: .4byte 0x08754bc4
lbl_080856d0: .4byte lbl_080856d4
lbl_080856d4: @ jump table
    .4byte lbl_0808570c @ case 0
    .4byte lbl_0808570c @ case 1
    .4byte lbl_080858a8 @ case 2
    .4byte lbl_0808570c @ case 3
    .4byte lbl_080859de @ case 4
    .4byte lbl_08085846 @ case 5
    .4byte lbl_080857f2 @ case 6
    .4byte lbl_080859de @ case 7
    .4byte lbl_080859de @ case 8
    .4byte lbl_080859de @ case 9
    .4byte lbl_080857f6 @ case 10
    .4byte lbl_08085824 @ case 11
    .4byte lbl_08085850 @ case 12
    .4byte lbl_0808587c @ case 13
lbl_0808570c:
    movs r7, #0
    ldrb r0, [r4, #1]
    adds r1, r4, #1
    cmp r0, #0
    beq lbl_0808572a
    adds r2, r1, #0
lbl_08085718:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x1d
    bhi lbl_0808572a
    adds r0, r2, r7
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08085718
lbl_0808572a:
    movs r0, #1
    ands r0, r7
    cmp r0, #0
    beq lbl_0808573c
    movs r4, #0x80
    mov sl, r4
    subs r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0808573c:
    movs r0, #0x1e
    subs r0, r0, r7
    asrs r0, r0, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r1, r6
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08085846
    adds r4, r1, #0
    ldr r3, lbl_0808577c @ =0x08754bc4
    ldr r0, lbl_08085780 @ =0x0000ffc0
    add r0, ip
    mov r8, r0
    ldr r5, lbl_08085784 @ =0x0000ffbf
    add r5, ip
lbl_0808575c:
    adds r2, r4, r6
    ldrb r1, [r2]
    adds r0, r1, #0
    subs r0, #0x41
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x19
    bhi lbl_08085788
    ldr r0, [r3]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    ldrb r1, [r2]
    add r1, r8
    b lbl_080857da
    .align 2, 0
lbl_0808577c: .4byte 0x08754bc4
lbl_08085780: .4byte 0x0000ffc0
lbl_08085784: .4byte 0x0000ffbf
lbl_08085788:
    adds r0, r1, #0
    subs r0, #0x61
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x19
    bhi lbl_080857a2
    ldr r0, [r3]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    ldrb r1, [r2]
    adds r1, r1, r5
    b lbl_080857da
lbl_080857a2:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x2e
    bne lbl_080857b8
    ldr r0, [r3]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x1b
    b lbl_080857da
lbl_080857b8:
    cmp r0, #0x2c
    bne lbl_080857ca
    ldr r0, [r3]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x1c
    b lbl_080857da
lbl_080857ca:
    cmp r0, #0x26
    bne lbl_080857dc
    ldr r0, [r3]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x1d
lbl_080857da:
    strh r1, [r0]
lbl_080857dc:
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r4, r6
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0808575c
    b lbl_08085846
lbl_080857f2:
    movs r2, #9
    b lbl_080859de
lbl_080857f6:
    movs r6, #0
    mov r0, ip
    adds r0, #0xc0
    ldr r3, lbl_08085820 @ =0x08754bc4
    adds r2, r0, #0
lbl_08085800:
    ldr r1, [r3]
    adds r0, r6, #5
    lsls r0, r0, #1
    adds r1, #0x10
    adds r1, r1, r0
    adds r0, r6, r2
    strh r0, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x13
    bls lbl_08085800
    movs r2, #1
    movs r1, #0x10
    mov sl, r1
    b lbl_080859de
    .align 2, 0
lbl_08085820: .4byte 0x08754bc4
lbl_08085824:
    movs r6, #0
    mov r0, ip
    adds r0, #0xe0
    ldr r3, lbl_0808584c @ =0x08754bc4
    adds r2, r0, #0
lbl_0808582e:
    ldr r1, [r3]
    adds r0, r6, #5
    lsls r0, r0, #1
    adds r1, #0x10
    adds r1, r1, r0
    adds r0, r6, r2
    strh r0, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x13
    bls lbl_0808582e
lbl_08085846:
    movs r2, #1
    b lbl_080859de
    .align 2, 0
lbl_0808584c: .4byte 0x08754bc4
lbl_08085850:
    movs r6, #0
    ldr r3, lbl_08085878 @ =0x08754bc4
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r4, #0
    mov r1, ip
    adds r2, r1, r0
lbl_0808585e:
    ldr r1, [r3]
    adds r0, r6, #5
    lsls r0, r0, #1
    adds r1, #0x10
    adds r1, r1, r0
    adds r0, r6, r2
    strh r0, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x13
    bls lbl_0808585e
    b lbl_08085846
    .align 2, 0
lbl_08085878: .4byte 0x08754bc4
lbl_0808587c:
    movs r6, #0
    ldr r3, lbl_080858a4 @ =0x08754bc4
    movs r4, #0x90
    lsls r4, r4, #1
    adds r0, r4, #0
    mov r1, ip
    adds r2, r1, r0
lbl_0808588a:
    ldr r1, [r3]
    adds r0, r6, #5
    lsls r0, r0, #1
    adds r1, #0x10
    adds r1, r1, r0
    adds r0, r6, r2
    strh r0, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x13
    bls lbl_0808588a
    b lbl_08085846
    .align 2, 0
lbl_080858a4: .4byte 0x08754bc4
lbl_080858a8:
    movs r7, #0
    ldrb r0, [r4, #1]
    adds r1, r4, #1
    cmp r0, #0
    beq lbl_080858c6
    adds r2, r1, #0
lbl_080858b4:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x1d
    bhi lbl_080858c6
    adds r0, r2, r7
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080858b4
lbl_080858c6:
    movs r0, #1
    ands r0, r7
    cmp r0, #0
    beq lbl_080858d8
    movs r4, #0x80
    mov sl, r4
    subs r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_080858d8:
    movs r0, #0x1e
    subs r0, r0, r7
    asrs r0, r0, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r1, r6
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080859dc
    ldr r0, lbl_08085928 @ =0x08754bc4
    mov r8, r0
    mov sb, r1
lbl_080858f0:
    mov r1, sb
    adds r5, r1, r6
    ldrb r1, [r5]
    adds r0, r1, #0
    subs r0, #0x41
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x19
    bhi lbl_08085930
    mov r4, r8
    ldr r2, [r4]
    lsls r3, r7, #1
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r1, r3
    ldr r0, lbl_0808592c @ =0x0000ffff
    add r0, ip
    ldrb r4, [r5]
    adds r0, r0, r4
    strh r0, [r1]
    adds r2, #0x50
    adds r2, r2, r3
    ldrb r0, [r5]
    mov r1, ip
    adds r1, #0x1f
    adds r0, r0, r1
    b lbl_080859c4
    .align 2, 0
lbl_08085928: .4byte 0x08754bc4
lbl_0808592c: .4byte 0x0000ffff
lbl_08085930:
    adds r0, r1, #0
    subs r0, #0x61
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x19
    bhi lbl_08085960
    mov r0, r8
    ldr r3, [r0]
    lsls r4, r7, #1
    adds r2, r3, #0
    adds r2, #0x10
    adds r2, r2, r4
    ldrb r0, [r5]
    mov r1, ip
    adds r1, #0x1f
    adds r0, r0, r1
    strh r0, [r2]
    adds r3, #0x50
    adds r3, r3, r4
    ldrb r0, [r5]
    adds r1, #0x20
    adds r0, r0, r1
    strh r0, [r3]
    b lbl_080859c6
lbl_08085960:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x2e
    bne lbl_0808597a
    mov r1, r8
    ldr r0, [r1]
    lsls r1, r7, #1
    adds r0, #0x50
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x7b
    strh r1, [r0]
    b lbl_080859c6
lbl_0808597a:
    cmp r0, #0x2c
    bne lbl_08085990
    mov r4, r8
    ldr r0, [r4]
    lsls r1, r7, #1
    adds r0, #0x50
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x7c
    strh r1, [r0]
    b lbl_080859c6
lbl_08085990:
    cmp r0, #0x2d
    bne lbl_080859a6
    mov r1, r8
    ldr r0, [r1]
    lsls r1, r7, #1
    adds r0, #0x10
    adds r0, r0, r1
    mov r1, ip
    adds r1, #0x5a
    strh r1, [r0]
    b lbl_080859c6
lbl_080859a6:
    cmp r0, #0x2b
    bne lbl_080859c6
    mov r4, r8
    ldr r2, [r4]
    lsls r3, r7, #1
    adds r0, r2, #0
    adds r0, #0x10
    adds r0, r0, r3
    mov r1, ip
    adds r1, #0x9a
    strh r1, [r0]
    adds r2, #0x50
    adds r2, r2, r3
    mov r0, ip
    adds r0, #0xba
lbl_080859c4:
    strh r0, [r2]
lbl_080859c6:
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov r1, sb
    adds r0, r1, r6
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080858f0
lbl_080859dc:
    movs r2, #2
lbl_080859de:
    mov r4, sl
    orrs r2, r4
    adds r0, r2, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start display_credits
display_credits: @ 0x080859f4
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08085a24 @ =0x08754bc4
    ldr r2, [r0]
    ldrb r3, [r2, #1]
    adds r7, r0, #0
    cmp r3, #0
    beq lbl_08085ad0
    movs r4, #0
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r0, #0x84
    lsls r0, r0, #2
    cmp r1, r0
    beq lbl_08085a38
    cmp r1, r0
    bgt lbl_08085a28
    subs r0, #0x40
    cmp r1, r0
    beq lbl_08085a32
    b lbl_08085a6c
    .align 2, 0
lbl_08085a24: .4byte 0x08754bc4
lbl_08085a28:
    movs r0, #0x8c
    lsls r0, r0, #2
    cmp r1, r0
    beq lbl_08085a58
    b lbl_08085a6c
lbl_08085a32:
    adds r0, r3, #1
    strb r0, [r2, #1]
    b lbl_08085a6c
lbl_08085a38:
    ldr r0, lbl_08085a4c @ =0x000002c2
    adds r1, r2, r0
    ldr r0, lbl_08085a50 @ =0x00000441
    strh r0, [r1]
    ldr r0, lbl_08085a54 @ =0x030013ae
    strh r4, [r0]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    b lbl_08085a6c
    .align 2, 0
lbl_08085a4c: .4byte 0x000002c2
lbl_08085a50: .4byte 0x00000441
lbl_08085a54: .4byte 0x030013ae
lbl_08085a58:
    movs r1, #0xb0
    lsls r1, r1, #2
    adds r0, r2, r1
    movs r1, #0xc0
    lsls r1, r1, #4
    strh r1, [r0]
    ldr r1, lbl_08085a94 @ =0x000002c2
    adds r0, r2, r1
    strh r4, [r0]
    movs r4, #1
lbl_08085a6c:
    ldr r2, [r7]
    ldrb r3, [r2, #1]
    adds r0, r3, #0
    cmp r0, #2
    bne lbl_08085a9c
    ldrb r1, [r2, #2]
    adds r0, r1, #1
    strb r0, [r2, #2]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08085acc
    ldr r1, lbl_08085a98 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085acc
    subs r0, #1
    strh r0, [r1]
    b lbl_08085acc
    .align 2, 0
lbl_08085a94: .4byte 0x000002c2
lbl_08085a98: .4byte 0x030013ae
lbl_08085a9c:
    cmp r0, #3
    bne lbl_08085acc
    ldrh r1, [r2, #4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08085acc
    ldr r1, lbl_08085ac0 @ =0x030013b0
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085ac8
    subs r0, #1
    strh r0, [r1]
    ldr r2, lbl_08085ac4 @ =0x030013b2
    movs r1, #0x10
    subs r1, r1, r0
    strh r1, [r2]
    b lbl_08085acc
    .align 2, 0
lbl_08085ac0: .4byte 0x030013b0
lbl_08085ac4: .4byte 0x030013b2
lbl_08085ac8:
    adds r0, r3, #1
    strb r0, [r2, #1]
lbl_08085acc:
    adds r0, r4, #0
    b lbl_08085b72
lbl_08085ad0:
    ldrh r1, [r2, #0xe]
    cmp r1, #0x7f
    bls lbl_08085b60
    movs r0, #0x7f
    ands r0, r1
    strh r0, [r2, #0xe]
    ldrh r0, [r2, #8]
    ldrh r1, [r2, #0xa]
    cmp r0, r1
    bne lbl_08085b58
    ldrh r0, [r2, #0xc]
    bl display_credit_line
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r6, #0xf0
    ands r6, r4
    movs r0, #0xf
    ands r4, r0
    cmp r4, #9
    bne lbl_08085b02
    ldr r1, [r7]
    movs r0, #1
    strb r0, [r1, #1]
    b lbl_08085b58
lbl_08085b02:
    ldr r2, [r7]
    ldrh r0, [r2, #0xa]
    lsls r0, r0, #6
    movs r1, #0xa0
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r3, lbl_08085b78 @ =0x000007ff
    cmp r0, r3
    ble lbl_08085b16
    ands r0, r3
lbl_08085b16:
    adds r1, r2, #0
    adds r1, #0x90
    movs r5, #0xf0
    lsls r5, r5, #8
    adds r0, r0, r5
    str r0, [r1]
    ldrh r0, [r2, #0xa]
    lsls r0, r0, #6
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r0, r1
    cmp r0, r3
    ble lbl_08085b32
    ands r0, r3
lbl_08085b32:
    adds r1, r2, #0
    adds r1, #0x94
    adds r0, r0, r5
    str r0, [r1]
    ldrh r0, [r2, #0xa]
    adds r0, r0, r4
    strh r0, [r2, #0xa]
    ldrh r0, [r2, #0xc]
    adds r0, #1
    strh r0, [r2, #0xc]
    ldrb r0, [r2, #6]
    adds r0, #1
    strb r0, [r2, #6]
    cmp r6, #0x80
    bne lbl_08085b58
    ldr r1, [r7]
    ldrb r0, [r1, #6]
    adds r0, #1
    strb r0, [r1, #6]
lbl_08085b58:
    ldr r1, [r7]
    ldrh r0, [r1, #8]
    adds r0, #1
    strh r0, [r1, #8]
lbl_08085b60:
    ldr r1, [r7]
    ldrh r0, [r1, #0xe]
    adds r0, #7
    strh r0, [r1, #0xe]
    ldr r1, lbl_08085b7c @ =0x030013b6
    ldrh r0, [r1]
    adds r0, #7
    strh r0, [r1]
    movs r0, #0
lbl_08085b72:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08085b78: .4byte 0x000007ff
lbl_08085b7c: .4byte 0x030013b6

    thumb_func_start credits_chozo_wall_movement
credits_chozo_wall_movement: @ 0x08085b80
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_08085ba0 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #1
    beq lbl_08085bc0
    cmp r1, #1
    bgt lbl_08085ba4
    cmp r1, #0
    beq lbl_08085bae
    b lbl_08085bce
    .align 2, 0
lbl_08085ba0: .4byte 0x08754bc4
lbl_08085ba4:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    beq lbl_08085bc8
    b lbl_08085bce
lbl_08085bae:
    ldr r0, lbl_08085bb8 @ =0x085babb4
    ldr r1, lbl_08085bbc @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_08085bce
    .align 2, 0
lbl_08085bb8: .4byte 0x085babb4
lbl_08085bbc: .4byte 0x06008000
lbl_08085bc0:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    b lbl_08085bce
lbl_08085bc8:
    ldr r0, lbl_08085c00 @ =0x04000014
    strh r4, [r0]
    movs r4, #1
lbl_08085bce:
    ldr r0, lbl_08085c04 @ =0x08754bc4
    ldr r3, [r0]
    ldrb r0, [r3, #1]
    cmp r0, #0
    beq lbl_08085bf6
    ldr r0, lbl_08085c08 @ =0x030013be
    ldrh r1, [r0]
    adds r1, #8
    strh r1, [r0]
    ldr r2, lbl_08085c0c @ =0x030013c2
    ldrh r0, [r2]
    adds r0, #8
    strh r0, [r2]
    lsls r1, r1, #0x10
    movs r0, #0xe0
    lsls r0, r0, #0x14
    cmp r1, r0
    bne lbl_08085bf6
    movs r0, #0
    strb r0, [r3, #1]
lbl_08085bf6:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08085c00: .4byte 0x04000014
lbl_08085c04: .4byte 0x08754bc4
lbl_08085c08: .4byte 0x030013be
lbl_08085c0c: .4byte 0x030013c2

    thumb_func_start credits_chozo_wall_zoom
credits_chozo_wall_zoom: @ 0x08085c10
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_08085c3c @ =0x08754bc4
    ldr r2, [r4]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0xc1
    bne lbl_08085c28
    b lbl_08085d24
lbl_08085c28:
    cmp r1, #0xc1
    bgt lbl_08085c46
    cmp r1, #1
    beq lbl_08085cb0
    cmp r1, #1
    bgt lbl_08085c40
    cmp r1, #0
    beq lbl_08085c66
    b lbl_08085d80
    .align 2, 0
lbl_08085c3c: .4byte 0x08754bc4
lbl_08085c40:
    cmp r1, #0xc0
    beq lbl_08085cec
    b lbl_08085d80
lbl_08085c46:
    movs r0, #0xc8
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_08085c50
    b lbl_08085d64
lbl_08085c50:
    cmp r1, r0
    bgt lbl_08085c5a
    cmp r1, #0xc2
    beq lbl_08085d38
    b lbl_08085d80
lbl_08085c5a:
    movs r0, #0xf0
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_08085c64
    b lbl_08085d7e
lbl_08085c64:
    b lbl_08085d80
lbl_08085c66:
    ldr r0, lbl_08085c94 @ =0x085bed94
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r1, lbl_08085c98 @ =0x040000d4
    ldr r0, lbl_08085c9c @ =0x0854a734
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08085ca0 @ =0x800000f0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08085ca4 @ =0x030013b6
    strh r5, [r0]
    ldr r0, lbl_08085ca8 @ =0x030013b0
    strh r5, [r0]
    ldr r1, lbl_08085cac @ =0x030013b2
    movs r0, #0x10
    strh r0, [r1]
    b lbl_08085d80
    .align 2, 0
lbl_08085c94: .4byte 0x085bed94
lbl_08085c98: .4byte 0x040000d4
lbl_08085c9c: .4byte 0x0854a734
lbl_08085ca0: .4byte 0x800000f0
lbl_08085ca4: .4byte 0x030013b6
lbl_08085ca8: .4byte 0x030013b0
lbl_08085cac: .4byte 0x030013b2
lbl_08085cb0:
    ldr r0, lbl_08085cd8 @ =0x085c3e34
    ldr r1, lbl_08085cdc @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_08085ce0 @ =0x04000008
    movs r2, #0xf0
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, [r4]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r0, #0xd0
    lsls r0, r0, #4
    strh r0, [r2]
    ldr r0, lbl_08085ce4 @ =0x000002c2
    adds r2, r1, r0
    ldr r0, lbl_08085ce8 @ =0x00000c41
    b lbl_08085d52
    .align 2, 0
lbl_08085cd8: .4byte 0x085c3e34
lbl_08085cdc: .4byte 0x0600f000
lbl_08085ce0: .4byte 0x04000008
lbl_08085ce4: .4byte 0x000002c2
lbl_08085ce8: .4byte 0x00000c41
lbl_08085cec:
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r1]
    ldr r1, lbl_08085d14 @ =0x000002c2
    adds r0, r2, r1
    strh r5, [r0]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    ldr r0, lbl_08085d18 @ =0x030013ba
    strh r5, [r0]
    ldr r1, lbl_08085d1c @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08085d20 @ =0x030013b2
    strh r5, [r0]
    b lbl_08085d80
    .align 2, 0
lbl_08085d14: .4byte 0x000002c2
lbl_08085d18: .4byte 0x030013ba
lbl_08085d1c: .4byte 0x030013b0
lbl_08085d20: .4byte 0x030013b2
lbl_08085d24:
    ldr r0, lbl_08085d30 @ =0x085c43f4
    ldr r1, lbl_08085d34 @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_08085d80
    .align 2, 0
lbl_08085d30: .4byte 0x085c43f4
lbl_08085d34: .4byte 0x06008000
lbl_08085d38:
    ldr r0, lbl_08085d5c @ =0x085c8e7c
    ldr r1, lbl_08085d60 @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r1, [r4]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    adds r0, #0x40
    strh r0, [r2]
    subs r0, #0x3e
    adds r2, r1, r0
    subs r0, #0x81
lbl_08085d52:
    strh r0, [r2]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_08085d80
    .align 2, 0
lbl_08085d5c: .4byte 0x085c8e7c
lbl_08085d60: .4byte 0x0600f800
lbl_08085d64:
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r2, r0
    subs r0, #0xc0
    strh r0, [r1]
    adds r0, #0xc2
    adds r1, r2, r0
    movs r0, #0xff
    strh r0, [r1]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    b lbl_08085d80
lbl_08085d7e:
    movs r5, #2
lbl_08085d80:
    ldr r0, lbl_08085dac @ =0x08754bc4
    ldr r0, [r0]
    ldrb r1, [r0, #1]
    cmp r1, #1
    bne lbl_08085db8
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085db0 @ =0x030013b0
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08085da0
    adds r0, #1
    strh r0, [r1]
lbl_08085da0:
    ldr r1, lbl_08085db4 @ =0x030013b2
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085dfa
    subs r0, #1
    b lbl_08085df8
    .align 2, 0
lbl_08085dac: .4byte 0x08754bc4
lbl_08085db0: .4byte 0x030013b0
lbl_08085db4: .4byte 0x030013b2
lbl_08085db8:
    cmp r1, #3
    bne lbl_08085de0
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085dd8 @ =0x030013b0
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085dd2
    subs r0, #1
    strh r0, [r1]
lbl_08085dd2:
    ldr r1, lbl_08085ddc @ =0x030013b2
    b lbl_08085df0
    .align 2, 0
lbl_08085dd8: .4byte 0x030013b0
lbl_08085ddc: .4byte 0x030013b2
lbl_08085de0:
    cmp r1, #4
    bne lbl_08085dfa
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085e04 @ =0x030013ae
lbl_08085df0:
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08085dfa
    adds r0, #1
lbl_08085df8:
    strh r0, [r1]
lbl_08085dfa:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08085e04: .4byte 0x030013ae

    thumb_func_start end_screen_init
end_screen_init: @ 0x08085e08
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    sub sp, #8
    ldr r4, lbl_08085f88 @ =0x04000208
    movs r5, #0
    strh r5, [r4]
    ldr r2, lbl_08085f8c @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08085f90 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08085f94 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08085f98 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08085f9c @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r6, #1
    strh r6, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r5, [r0]
    strh r5, [r4]
    ldr r0, lbl_08085fa0 @ =vblank_code_during_end_screen
    mov r8, r0
    bl CallbackSetVBlank
    strh r6, [r4]
    ldr r0, lbl_08085fa4 @ =0x085a1298
    ldr r1, lbl_08085fa8 @ =0x06003000
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fac @ =0x085a46f0
    ldr r1, lbl_08085fb0 @ =0x0600b000
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fb4 @ =0x085a54d0
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fb8 @ =0x085a6f38
    ldr r1, lbl_08085fbc @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fc0 @ =0x085a4080
    ldr r1, lbl_08085fc4 @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fc8 @ =0x085a528c
    ldr r1, lbl_08085fcc @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fd0 @ =0x085a6bf4
    ldr r1, lbl_08085fd4 @ =0x0600d000
    bl LZ77UncompVRAM
    ldr r0, lbl_08085fd8 @ =0x085a87a0
    ldr r1, lbl_08085fdc @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r2, lbl_08085fe0 @ =0x0600d800
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    ldr r2, lbl_08085fe4 @ =0x0600e800
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    ldr r4, lbl_08085fe8 @ =0x040000d4
    ldr r0, lbl_08085fec @ =0x0854b914
    str r0, [r4]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r4, #4]
    ldr r0, lbl_08085ff0 @ =0x800000d0
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, lbl_08085ff4 @ =0x04000008
    ldr r2, lbl_08085ff8 @ =0x00001e08
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08085ffc @ =0x00005a01
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08086000 @ =0x00005c0a
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08086004 @ =0x00001f03
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08086008 @ =0x03001382
    strb r5, [r0]
    bl ResetFreeOAM
    ldr r0, lbl_0808600c @ =0x03000e7c
    str r0, [r4]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r4, #4]
    ldr r0, lbl_08086010 @ =0x84000100
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r0, lbl_08086014 @ =0x030013b4
    strh r5, [r0]
    ldr r0, lbl_08086018 @ =0x030013b6
    strh r5, [r0]
    ldr r0, lbl_0808601c @ =0x030013b8
    movs r2, #0x80
    lsls r2, r2, #1
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_08086020 @ =0x030013ba
    strh r5, [r0]
    ldr r0, lbl_08086024 @ =0x030013bc
    strh r1, [r0]
    ldr r0, lbl_08086028 @ =0x030013be
    strh r5, [r0]
    ldr r0, lbl_0808602c @ =0x030013c0
    strh r5, [r0]
    ldr r0, lbl_08086030 @ =0x030013c2
    strh r5, [r0]
    ldr r0, lbl_08086034 @ =0x04000010
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    movs r5, #0
    str r5, [sp, #4]
    add r0, sp, #4
    str r0, [r4]
    ldr r0, lbl_08086038 @ =0x030016c4
    str r0, [r4, #4]
    ldr r0, lbl_0808603c @ =0x8500018a
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    bl GetPercentAndEndingNumber
    ldr r3, lbl_08086040 @ =0x08754bc4
    ldr r1, [r3]
    movs r2, #7
    ands r0, r2
    adds r1, #0x98
    strb r0, [r1]
    ldr r0, [r3]
    movs r1, #0xb0
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #0xf0
    lsls r1, r1, #5
    strh r1, [r0]
    ldr r0, lbl_08086044 @ =0x030013b0
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086048 @ =0x030013b2
    strh r5, [r0]
    ldr r0, lbl_0808604c @ =0x030013ae
    strh r1, [r0]
    bl _call_via_r8
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08085f88: .4byte 0x04000208
lbl_08085f8c: .4byte 0x04000004
lbl_08085f90: .4byte 0x0000ffef
lbl_08085f94: .4byte 0x04000200
lbl_08085f98: .4byte 0x0000fffd
lbl_08085f9c: .4byte 0x04000202
lbl_08085fa0: .4byte vblank_code_during_end_screen
lbl_08085fa4: .4byte 0x085a1298
lbl_08085fa8: .4byte 0x06003000
lbl_08085fac: .4byte 0x085a46f0
lbl_08085fb0: .4byte 0x0600b000
lbl_08085fb4: .4byte 0x085a54d0
lbl_08085fb8: .4byte 0x085a6f38
lbl_08085fbc: .4byte 0x06008000
lbl_08085fc0: .4byte 0x085a4080
lbl_08085fc4: .4byte 0x0600f800
lbl_08085fc8: .4byte 0x085a528c
lbl_08085fcc: .4byte 0x0600f000
lbl_08085fd0: .4byte 0x085a6bf4
lbl_08085fd4: .4byte 0x0600d000
lbl_08085fd8: .4byte 0x085a87a0
lbl_08085fdc: .4byte 0x0600e000
lbl_08085fe0: .4byte 0x0600d800
lbl_08085fe4: .4byte 0x0600e800
lbl_08085fe8: .4byte 0x040000d4
lbl_08085fec: .4byte 0x0854b914
lbl_08085ff0: .4byte 0x800000d0
lbl_08085ff4: .4byte 0x04000008
lbl_08085ff8: .4byte 0x00001e08
lbl_08085ffc: .4byte 0x00005a01
lbl_08086000: .4byte 0x00005c0a
lbl_08086004: .4byte 0x00001f03
lbl_08086008: .4byte 0x03001382
lbl_0808600c: .4byte 0x03000e7c
lbl_08086010: .4byte 0x84000100
lbl_08086014: .4byte 0x030013b4
lbl_08086018: .4byte 0x030013b6
lbl_0808601c: .4byte 0x030013b8
lbl_08086020: .4byte 0x030013ba
lbl_08086024: .4byte 0x030013bc
lbl_08086028: .4byte 0x030013be
lbl_0808602c: .4byte 0x030013c0
lbl_08086030: .4byte 0x030013c2
lbl_08086034: .4byte 0x04000010
lbl_08086038: .4byte 0x030016c4
lbl_0808603c: .4byte 0x8500018a
lbl_08086040: .4byte 0x08754bc4
lbl_08086044: .4byte 0x030013b0
lbl_08086048: .4byte 0x030013b2
lbl_0808604c: .4byte 0x030013ae

    thumb_func_start end_screen_samus_posing
end_screen_samus_posing: @ 0x08086050
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r1, lbl_08086074 @ =0x08754bc4
    ldr r2, [r1]
    ldrb r0, [r2, #2]
    adds r0, #1
    strb r0, [r2, #2]
    ldr r0, [r1]
    ldrb r0, [r0, #1]
    adds r5, r1, #0
    cmp r0, #0xa
    bls lbl_0808606a
    b lbl_0808622a
lbl_0808606a:
    lsls r0, r0, #2
    ldr r1, lbl_08086078 @ =lbl_0808607c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08086074: .4byte 0x08754bc4
lbl_08086078: .4byte lbl_0808607c
lbl_0808607c: @ jump table
    .4byte lbl_080860ba @ case 0
    .4byte lbl_080860f0 @ case 1
    .4byte lbl_08086114 @ case 2
    .4byte lbl_080860f0 @ case 3
    .4byte lbl_080860a8 @ case 4
    .4byte lbl_080860f0 @ case 5
    .4byte lbl_08086114 @ case 6
    .4byte lbl_08086164 @ case 7
    .4byte lbl_08086186 @ case 8
    .4byte lbl_080861b8 @ case 9
    .4byte lbl_08086210 @ case 10
lbl_080860a8:
    ldr r0, [r5]
    ldrh r1, [r0, #4]
    adds r2, r1, #1
    strh r2, [r0, #4]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    cmp r1, #7
    bhi lbl_080860ba
    b lbl_0808622a
lbl_080860ba:
    ldr r2, lbl_080860e0 @ =0x030013b8
    ldrh r0, [r2]
    adds r0, #8
    strh r0, [r2]
    lsls r0, r0, #0x10
    ldr r1, lbl_080860e4 @ =0x01ff0000
    cmp r0, r1
    bhi lbl_080860cc
    b lbl_0808622a
lbl_080860cc:
    movs r0, #0
    strh r0, [r2]
    ldr r1, [r5]
    ldr r0, lbl_080860e8 @ =0x000002c2
    adds r2, r1, r0
    movs r3, #0
    ldr r0, lbl_080860ec @ =0x00000c42
    strh r0, [r2]
    strh r3, [r1, #4]
    b lbl_08086200
    .align 2, 0
lbl_080860e0: .4byte 0x030013b8
lbl_080860e4: .4byte 0x01ff0000
lbl_080860e8: .4byte 0x000002c2
lbl_080860ec: .4byte 0x00000c42
lbl_080860f0:
    ldr r2, [r5]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x18
    bhi lbl_08086102
    b lbl_0808622a
lbl_08086102:
    movs r3, #0x92
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r2, #0
    movs r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    strh r2, [r1, #4]
    b lbl_08086200
lbl_08086114:
    ldr r3, [r5]
    ldrh r0, [r3, #4]
    adds r1, r0, #1
    strh r1, [r3, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #7
    bhi lbl_08086126
    b lbl_0808622a
lbl_08086126:
    ldr r2, lbl_08086154 @ =0x030013bc
    ldrh r0, [r2]
    adds r0, #8
    strh r0, [r2]
    lsls r0, r0, #0x10
    ldr r1, lbl_08086158 @ =0x01ff0000
    cmp r0, r1
    bls lbl_0808622a
    movs r1, #0x80
    lsls r1, r1, #2
    adds r0, r1, #0
    strh r0, [r2]
    ldr r2, lbl_0808615c @ =0x000002c2
    adds r1, r3, r2
    movs r2, #0
    ldr r0, lbl_08086160 @ =0x00000a44
    strh r0, [r1]
    strh r2, [r3, #4]
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    b lbl_0808622a
    .align 2, 0
lbl_08086154: .4byte 0x030013bc
lbl_08086158: .4byte 0x01ff0000
lbl_0808615c: .4byte 0x000002c2
lbl_08086160: .4byte 0x00000a44
lbl_08086164:
    ldr r2, [r5]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x40
    bls lbl_0808622a
    movs r3, #0x92
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r2, #0
    movs r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    strh r2, [r1, #4]
    b lbl_08086200
lbl_08086186:
    ldr r2, [r5]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x17
    bls lbl_0808622a
    ldr r1, lbl_080861a4 @ =0x030013b8
    ldrh r0, [r1]
    cmp r0, #9
    bls lbl_080861a8
    subs r0, #0xa
    strh r0, [r1]
    b lbl_0808622a
    .align 2, 0
lbl_080861a4: .4byte 0x030013b8
lbl_080861a8:
    movs r0, #0
    strh r0, [r1]
    movs r0, #0
    strh r0, [r2, #4]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    b lbl_0808622a
lbl_080861b8:
    ldr r2, [r5]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1f
    bls lbl_0808622a
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r0, #0xe0
    lsls r0, r0, #4
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x98
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080861e8
    movs r3, #0x92
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r0, #3
    b lbl_080861f8
lbl_080861e8:
    ldr r0, lbl_08086208 @ =0x000002c2
    adds r1, r2, r0
    ldr r0, lbl_0808620c @ =0x00000c42
    strh r0, [r1]
    movs r3, #0x92
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r0, #1
lbl_080861f8:
    strb r0, [r1]
    ldr r1, [r5]
    movs r0, #0
    strh r0, [r1, #4]
lbl_08086200:
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_0808622a
    .align 2, 0
lbl_08086208: .4byte 0x000002c2
lbl_0808620c: .4byte 0x00000c42
lbl_08086210:
    ldr r2, [r5]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    movs r1, #0x90
    lsls r1, r1, #0x11
    cmp r0, r1
    bls lbl_0808622a
    ldr r0, lbl_08086248 @ =0x00000125
    adds r1, r2, r0
    movs r0, #0x20
    strb r0, [r1]
lbl_0808622a:
    ldr r0, [r5]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #4
    bls lbl_0808623c
    b lbl_08086388
lbl_0808623c:
    lsls r0, r0, #2
    ldr r1, lbl_0808624c @ =lbl_08086250
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08086248: .4byte 0x00000125
lbl_0808624c: .4byte lbl_08086250
lbl_08086250: @ jump table
    .4byte lbl_08086264 @ case 0
    .4byte lbl_080862b0 @ case 1
    .4byte lbl_080862d0 @ case 2
    .4byte lbl_08086328 @ case 3
    .4byte lbl_08086354 @ case 4
lbl_08086264:
    ldr r4, [r5]
    ldrb r1, [r4, #2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08086272
    b lbl_08086388
lbl_08086272:
    ldr r0, lbl_08086284 @ =0x030013b0
    ldrh r2, [r0]
    adds r3, r2, #0
    adds r1, r0, #0
    cmp r3, #0
    beq lbl_08086288
    subs r0, r2, #1
    strh r0, [r1]
    b lbl_0808629c
    .align 2, 0
lbl_08086284: .4byte 0x030013b0
lbl_08086288:
    movs r2, #0x92
    lsls r2, r2, #1
    adds r0, r4, r2
    strb r3, [r0]
    ldr r0, [r5]
    ldr r3, lbl_080862a8 @ =0x00000125
    adds r2, r0, r3
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
lbl_0808629c:
    ldr r2, lbl_080862ac @ =0x030013b2
    ldrh r1, [r1]
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    b lbl_08086388
    .align 2, 0
lbl_080862a8: .4byte 0x00000125
lbl_080862ac: .4byte 0x030013b2
lbl_080862b0:
    ldr r2, [r5]
    ldrb r0, [r2, #2]
    movs r1, #3
    ands r1, r0
    cmp r1, #0
    bne lbl_08086388
    ldr r3, lbl_080862cc @ =0x030013b0
    ldrh r0, [r3]
    cmp r0, #0xf
    bhi lbl_08086374
    adds r0, #1
    strh r0, [r3]
    b lbl_08086388
    .align 2, 0
lbl_080862cc: .4byte 0x030013b0
lbl_080862d0:
    ldr r1, [r5]
    movs r2, #0xb0
    lsls r2, r2, #1
    adds r1, r1, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, r2
    ldrb r0, [r1]
    lsls r3, r0, #0x18
    lsrs r0, r3, #0x18
    cmp r0, #0xf
    bls lbl_08086300
    movs r0, #0
    strb r0, [r1]
    ldr r0, [r5]
    ldr r3, lbl_080862fc @ =0x00000125
    adds r1, r0, r3
    movs r0, #0x10
    b lbl_08086386
    .align 2, 0
lbl_080862fc: .4byte 0x00000125
lbl_08086300:
    ldr r1, lbl_0808631c @ =0x040000d4
    ldr r2, lbl_08086320 @ =0x0854e2cc
    lsrs r0, r3, #0x1a
    lsls r0, r0, #2
    adds r0, r0, r2
    ldr r0, [r0]
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08086324 @ =0x80000050
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_08086388
    .align 2, 0
lbl_0808631c: .4byte 0x040000d4
lbl_08086320: .4byte 0x0854e2cc
lbl_08086324: .4byte 0x80000050
lbl_08086328:
    ldr r2, [r5]
    ldrb r1, [r2, #2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08086388
    ldr r1, lbl_08086344 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08086348
    adds r0, #1
    strh r0, [r1]
    b lbl_08086388
    .align 2, 0
lbl_08086344: .4byte 0x030013ae
lbl_08086348:
    ldr r0, lbl_08086350 @ =0x00000125
    adds r1, r2, r0
    b lbl_08086382
    .align 2, 0
lbl_08086350: .4byte 0x00000125
lbl_08086354:
    ldr r2, [r5]
    ldrb r1, [r2, #2]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08086388
    ldr r3, lbl_08086370 @ =0x030013ae
    ldrh r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08086374
    subs r0, #1
    strh r0, [r3]
    b lbl_08086388
    .align 2, 0
lbl_08086370: .4byte 0x030013ae
lbl_08086374:
    movs r3, #0x92
    lsls r3, r3, #1
    adds r0, r2, r3
    strb r1, [r0]
    ldr r0, [r5]
    ldr r2, lbl_080863a4 @ =0x00000125
    adds r1, r0, r2
lbl_08086382:
    ldrb r0, [r1]
    adds r0, #1
lbl_08086386:
    strb r0, [r1]
lbl_08086388:
    ldr r0, [r5]
    ldr r3, lbl_080863a4 @ =0x00000125
    adds r0, r0, r3
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #0x1f
    bls lbl_08086398
    b lbl_08086782
lbl_08086398:
    lsls r0, r0, #2
    ldr r1, lbl_080863a8 @ =lbl_080863ac
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080863a4: .4byte 0x00000125
lbl_080863a8: .4byte lbl_080863ac
lbl_080863ac: @ jump table
    .4byte lbl_0808642c @ case 0
    .4byte lbl_08086782 @ case 1
    .4byte lbl_080864a4 @ case 2
    .4byte lbl_08086782 @ case 3
    .4byte lbl_08086520 @ case 4
    .4byte lbl_08086782 @ case 5
    .4byte lbl_08086598 @ case 6
    .4byte lbl_08086782 @ case 7
    .4byte lbl_08086668 @ case 8
    .4byte lbl_08086782 @ case 9
    .4byte lbl_08086782 @ case 10
    .4byte lbl_08086782 @ case 11
    .4byte lbl_08086782 @ case 12
    .4byte lbl_08086782 @ case 13
    .4byte lbl_08086782 @ case 14
    .4byte lbl_080866b0 @ case 15
    .4byte lbl_08086782 @ case 16
    .4byte lbl_080866e8 @ case 17
    .4byte lbl_08086720 @ case 18
    .4byte lbl_08086782 @ case 19
    .4byte lbl_08086782 @ case 20
    .4byte lbl_08086782 @ case 21
    .4byte lbl_08086782 @ case 22
    .4byte lbl_08086782 @ case 23
    .4byte lbl_08086782 @ case 24
    .4byte lbl_08086782 @ case 25
    .4byte lbl_08086782 @ case 26
    .4byte lbl_08086782 @ case 27
    .4byte lbl_08086782 @ case 28
    .4byte lbl_08086782 @ case 29
    .4byte lbl_08086782 @ case 30
    .4byte lbl_08086758 @ case 31
lbl_0808642c:
    ldr r1, lbl_08086474 @ =0x0400000a
    ldr r2, lbl_08086478 @ =0x00005a02
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_0808647c @ =0x00005c09
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_08086480 @ =0x085a8b38
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_08086484 @ =0x085aa5f8
    ldr r1, lbl_08086488 @ =0x0600d000
    bl LZ77UncompVRAM
    ldr r0, lbl_0808648c @ =0x08754bc4
    ldr r3, [r0]
    ldr r1, lbl_08086490 @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086494 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08086498 @ =0x030013b2
    strh r2, [r0]
    ldr r1, lbl_0808649c @ =0x030013b8
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_080864a0 @ =0x00000125
    adds r1, r3, r0
    b lbl_0808673a
    .align 2, 0
lbl_08086474: .4byte 0x0400000a
lbl_08086478: .4byte 0x00005a02
lbl_0808647c: .4byte 0x00005c09
lbl_08086480: .4byte 0x085a8b38
lbl_08086484: .4byte 0x085aa5f8
lbl_08086488: .4byte 0x0600d000
lbl_0808648c: .4byte 0x08754bc4
lbl_08086490: .4byte 0x000002c2
lbl_08086494: .4byte 0x030013b0
lbl_08086498: .4byte 0x030013b2
lbl_0808649c: .4byte 0x030013b8
lbl_080864a0: .4byte 0x00000125
lbl_080864a4:
    ldr r1, lbl_080864ec @ =0x0400000a
    ldr r2, lbl_080864f0 @ =0x00005a01
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_080864f4 @ =0x00005c0a
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_080864f8 @ =0x085aa9b0
    ldr r1, lbl_080864fc @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086500 @ =0x085ac420
    ldr r1, lbl_08086504 @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086508 @ =0x08754bc4
    ldr r3, [r0]
    ldr r1, lbl_0808650c @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086510 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08086514 @ =0x030013b2
    strh r2, [r0]
    ldr r1, lbl_08086518 @ =0x030013bc
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0808651c @ =0x00000125
    adds r1, r3, r0
    b lbl_0808673a
    .align 2, 0
lbl_080864ec: .4byte 0x0400000a
lbl_080864f0: .4byte 0x00005a01
lbl_080864f4: .4byte 0x00005c0a
lbl_080864f8: .4byte 0x085aa9b0
lbl_080864fc: .4byte 0x06008000
lbl_08086500: .4byte 0x085ac420
lbl_08086504: .4byte 0x0600e000
lbl_08086508: .4byte 0x08754bc4
lbl_0808650c: .4byte 0x000002c2
lbl_08086510: .4byte 0x030013b0
lbl_08086514: .4byte 0x030013b2
lbl_08086518: .4byte 0x030013bc
lbl_0808651c: .4byte 0x00000125
lbl_08086520:
    ldr r1, lbl_08086568 @ =0x0400000a
    ldr r2, lbl_0808656c @ =0x00005a02
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08086570 @ =0x00005c09
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_08086574 @ =0x085ac794
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_08086578 @ =0x085adb90
    ldr r1, lbl_0808657c @ =0x0600d000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086580 @ =0x08754bc4
    ldr r3, [r0]
    ldr r1, lbl_08086584 @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086588 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_0808658c @ =0x030013b2
    strh r2, [r0]
    ldr r1, lbl_08086590 @ =0x030013b8
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08086594 @ =0x00000125
    adds r1, r3, r0
    b lbl_0808673a
    .align 2, 0
lbl_08086568: .4byte 0x0400000a
lbl_0808656c: .4byte 0x00005a02
lbl_08086570: .4byte 0x00005c09
lbl_08086574: .4byte 0x085ac794
lbl_08086578: .4byte 0x085adb90
lbl_0808657c: .4byte 0x0600d000
lbl_08086580: .4byte 0x08754bc4
lbl_08086584: .4byte 0x000002c2
lbl_08086588: .4byte 0x030013b0
lbl_0808658c: .4byte 0x030013b2
lbl_08086590: .4byte 0x030013b8
lbl_08086594: .4byte 0x00000125
lbl_08086598:
    ldr r1, lbl_080865c0 @ =0x0400000a
    ldr r2, lbl_080865c4 @ =0x00005a01
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_080865c8 @ =0x00005c0a
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_080865cc @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x98
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080865dc
    ldr r0, lbl_080865d0 @ =0x085af2bc
    ldr r1, lbl_080865d4 @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_080865d8 @ =0x085b0b10
    b lbl_080865ea
    .align 2, 0
lbl_080865c0: .4byte 0x0400000a
lbl_080865c4: .4byte 0x00005a01
lbl_080865c8: .4byte 0x00005c0a
lbl_080865cc: .4byte 0x08754bc4
lbl_080865d0: .4byte 0x085af2bc
lbl_080865d4: .4byte 0x06008000
lbl_080865d8: .4byte 0x085b0b10
lbl_080865dc:
    cmp r0, #1
    bne lbl_08086604
    ldr r0, lbl_080865f4 @ =0x085b0e98
    ldr r1, lbl_080865f8 @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_080865fc @ =0x085b2718
lbl_080865ea:
    ldr r1, lbl_08086600 @ =0x0600e000
    bl LZ77UncompVRAM
    b lbl_08086614
    .align 2, 0
lbl_080865f4: .4byte 0x085b0e98
lbl_080865f8: .4byte 0x06008000
lbl_080865fc: .4byte 0x085b2718
lbl_08086600: .4byte 0x0600e000
lbl_08086604:
    ldr r0, lbl_08086640 @ =0x085ade64
    ldr r1, lbl_08086644 @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086648 @ =0x085af0a0
    ldr r1, lbl_0808664c @ =0x0600e000
    bl LZ77UncompVRAM
lbl_08086614:
    ldr r0, lbl_08086650 @ =0x08754bc4
    ldr r3, [r0]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r3, r0
    movs r2, #0
    movs r0, #0xa0
    lsls r0, r0, #4
    strh r0, [r1]
    ldr r1, lbl_08086654 @ =0x000002c2
    adds r0, r3, r1
    strh r2, [r0]
    ldr r1, lbl_08086658 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_0808665c @ =0x030013b2
    strh r2, [r0]
    ldr r0, lbl_08086660 @ =0x030013bc
    strh r2, [r0]
    ldr r2, lbl_08086664 @ =0x00000125
    adds r1, r3, r2
    b lbl_0808673a
    .align 2, 0
lbl_08086640: .4byte 0x085ade64
lbl_08086644: .4byte 0x06008000
lbl_08086648: .4byte 0x085af0a0
lbl_0808664c: .4byte 0x0600e000
lbl_08086650: .4byte 0x08754bc4
lbl_08086654: .4byte 0x000002c2
lbl_08086658: .4byte 0x030013b0
lbl_0808665c: .4byte 0x030013b2
lbl_08086660: .4byte 0x030013bc
lbl_08086664: .4byte 0x00000125
lbl_08086668:
    ldr r4, lbl_0808669c @ =0x08754bc4
    ldr r2, [r4]
    movs r3, #0xb0
    lsls r3, r3, #2
    adds r1, r2, r3
    movs r3, #0
    movs r0, #0xd0
    lsls r0, r0, #4
    strh r0, [r1]
    ldr r0, lbl_080866a0 @ =0x000002c2
    adds r1, r2, r0
    ldr r0, lbl_080866a4 @ =0x00000c41
    strh r0, [r1]
    ldr r0, lbl_080866a8 @ =0x030013b0
    strh r3, [r0]
    ldr r1, lbl_080866ac @ =0x030013b2
    movs r0, #0x10
    strh r0, [r1]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r2, r2, r1
    movs r0, #2
    strb r0, [r2]
    ldr r0, [r4]
    b lbl_08086736
    .align 2, 0
lbl_0808669c: .4byte 0x08754bc4
lbl_080866a0: .4byte 0x000002c2
lbl_080866a4: .4byte 0x00000c41
lbl_080866a8: .4byte 0x030013b0
lbl_080866ac: .4byte 0x030013b2
lbl_080866b0:
    ldr r3, lbl_080866dc @ =0x08754bc4
    ldr r1, [r3]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r0, #0xe0
    lsls r0, r0, #4
    strh r0, [r2]
    ldr r0, lbl_080866e0 @ =0x000002c2
    adds r2, r1, r0
    movs r0, #0xbd
    strh r0, [r2]
    movs r2, #0x92
    lsls r2, r2, #1
    adds r1, r1, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r3]
    ldr r3, lbl_080866e4 @ =0x00000125
    adds r1, r0, r3
    b lbl_0808673a
    .align 2, 0
lbl_080866dc: .4byte 0x08754bc4
lbl_080866e0: .4byte 0x000002c2
lbl_080866e4: .4byte 0x00000125
lbl_080866e8:
    ldr r3, lbl_08086714 @ =0x08754bc4
    ldr r1, [r3]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r0, #0xc0
    lsls r0, r0, #4
    strh r0, [r2]
    ldr r0, lbl_08086718 @ =0x000002c2
    adds r2, r1, r0
    movs r0, #0xbf
    strh r0, [r2]
    movs r2, #0x92
    lsls r2, r2, #1
    adds r1, r1, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r3]
    ldr r3, lbl_0808671c @ =0x00000125
    adds r1, r0, r3
    b lbl_0808673a
    .align 2, 0
lbl_08086714: .4byte 0x08754bc4
lbl_08086718: .4byte 0x000002c2
lbl_0808671c: .4byte 0x00000125
lbl_08086720:
    ldr r1, lbl_08086744 @ =0x040000d4
    ldr r0, lbl_08086748 @ =0x0854b914
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0808674c @ =0x80000050
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08086750 @ =0x08754bc4
    ldr r0, [r0]
lbl_08086736:
    ldr r2, lbl_08086754 @ =0x00000125
    adds r1, r0, r2
lbl_0808673a:
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08086782
    .align 2, 0
lbl_08086744: .4byte 0x040000d4
lbl_08086748: .4byte 0x0854b914
lbl_0808674c: .4byte 0x80000050
lbl_08086750: .4byte 0x08754bc4
lbl_08086754: .4byte 0x00000125
lbl_08086758:
    ldr r0, lbl_080867a0 @ =0x08754bc4
    ldr r1, [r0]
    movs r3, #0xb0
    lsls r3, r3, #2
    adds r2, r1, r3
    movs r3, #0
    movs r0, #0xc0
    lsls r0, r0, #4
    strh r0, [r2]
    ldr r0, lbl_080867a4 @ =0x000002c2
    adds r1, r1, r0
    movs r0, #0xff
    strh r0, [r1]
    ldr r1, lbl_080867a8 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_080867ac @ =0x030013b2
    strh r3, [r0]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_08086782:
    ldr r0, lbl_080867a0 @ =0x08754bc4
    ldr r0, [r0]
    ldrb r1, [r0, #2]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08086798
    ldr r1, lbl_080867b0 @ =0x030013c0
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_08086798:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080867a0: .4byte 0x08754bc4
lbl_080867a4: .4byte 0x000002c2
lbl_080867a8: .4byte 0x030013b0
lbl_080867ac: .4byte 0x030013b2
lbl_080867b0: .4byte 0x030013c0

    thumb_func_start ending_image_init
ending_image_init: @ 0x080867b4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r4, lbl_080868cc @ =0x04000208
    movs r3, #0
    strh r3, [r4]
    ldr r2, lbl_080868d0 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_080868d4 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_080868d8 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_080868dc @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_080868e0 @ =0x04000202
    movs r1, #2
    strh r1, [r0]
    movs r5, #1
    strh r5, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r3, [r0]
    strh r3, [r4]
    ldr r0, lbl_080868e4 @ =vblank_code_during_gallery
    bl CallbackSetVBlank
    strh r5, [r4]
    movs r0, #0
    str r0, [sp, #4]
    ldr r6, lbl_080868e8 @ =0x040000d4
    add r2, sp, #4
    str r2, [r6]
    ldr r0, lbl_080868ec @ =0x030016c4
    str r0, [r6, #4]
    ldr r0, lbl_080868f0 @ =0x8500018a
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    bl GetPercentAndEndingNumber
    adds r4, r0, #0
    movs r0, #0xff
    lsrs r5, r4, #0x18
    lsrs r7, r4, #0x10
    ands r7, r0
    lsrs r3, r4, #0xc
    movs r0, #0xf
    ands r3, r0
    mov sl, r3
    lsrs r1, r4, #8
    ands r1, r0
    mov sb, r1
    lsrs r2, r4, #4
    ands r2, r0
    mov r8, r2
    ands r4, r0
    ldr r0, lbl_080868f4 @ =0x0854c06c
    lsls r4, r4, #2
    adds r0, r4, r0
    ldr r0, [r0]
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_080868f8 @ =0x0854c08c
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_080868fc @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086900 @ =0x0854c0ac
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_08086904 @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r0, lbl_08086908 @ =0x0854c0cc
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_0808690c @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r1, lbl_08086910 @ =0x04ff04ff
    ldr r2, lbl_08086914 @ =0x0600e800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r0, lbl_08086918 @ =0x0854c0ec
    adds r4, r4, r0
    ldr r0, [r4]
    str r0, [r6]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r6, #4]
    ldr r0, lbl_0808691c @ =0x80000100
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    ldr r4, lbl_08086920 @ =0x08754bc4
    ldr r0, [r4]
    adds r5, r5, r7
    add r5, sl
    add r5, sb
    add r5, r8
    adds r0, #0x99
    strb r5, [r0]
    ldr r0, lbl_08086924 @ =0x085a0f30
    ldr r1, lbl_08086928 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, [r4]
    ldr r2, lbl_0808692c @ =0x03000020
    ldrb r1, [r2]
    adds r0, #0x9a
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r0, #2
    ble lbl_080868b8
    ldr r0, [r4]
    adds r0, #0x9a
    movs r3, #2
    strb r3, [r0]
lbl_080868b8:
    ldr r0, [r4]
    adds r0, #0x9a
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08086938
    ldr r0, lbl_08086930 @ =0x085a0234
    ldr r1, lbl_08086934 @ =0x06011000
    bl LZ77UncompVRAM
    b lbl_08086940
    .align 2, 0
lbl_080868cc: .4byte 0x04000208
lbl_080868d0: .4byte 0x04000004
lbl_080868d4: .4byte 0x0000ffef
lbl_080868d8: .4byte 0x04000200
lbl_080868dc: .4byte 0x0000fffd
lbl_080868e0: .4byte 0x04000202
lbl_080868e4: .4byte vblank_code_during_gallery
lbl_080868e8: .4byte 0x040000d4
lbl_080868ec: .4byte 0x030016c4
lbl_080868f0: .4byte 0x8500018a
lbl_080868f4: .4byte 0x0854c06c
lbl_080868f8: .4byte 0x0854c08c
lbl_080868fc: .4byte 0x06008000
lbl_08086900: .4byte 0x0854c0ac
lbl_08086904: .4byte 0x0600e000
lbl_08086908: .4byte 0x0854c0cc
lbl_0808690c: .4byte 0x0600f800
lbl_08086910: .4byte 0x04ff04ff
lbl_08086914: .4byte 0x0600e800
lbl_08086918: .4byte 0x0854c0ec
lbl_0808691c: .4byte 0x80000100
lbl_08086920: .4byte 0x08754bc4
lbl_08086924: .4byte 0x085a0f30
lbl_08086928: .4byte 0x06010000
lbl_0808692c: .4byte 0x03000020
lbl_08086930: .4byte 0x085a0234
lbl_08086934: .4byte 0x06011000
lbl_08086938:
    ldr r0, lbl_080869f4 @ =0x0859f5a8
    ldr r1, lbl_080869f8 @ =0x06011000
    bl LZ77UncompVRAM
lbl_08086940:
    ldr r1, lbl_080869fc @ =0x040000d4
    ldr r0, lbl_08086a00 @ =0x08549b44
    str r0, [r1]
    ldr r0, lbl_08086a04 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_08086a08 @ =0x800000e0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    bl load_in_game_timer_ending_graphics
    ldr r1, lbl_08086a0c @ =0x04000008
    movs r2, #0x9c
    lsls r2, r2, #8
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08086a10 @ =0x00009e09
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_08086a14 @ =0x03001382
    movs r0, #0
    strb r0, [r1]
    bl ResetFreeOAM
    ldr r0, lbl_08086a18 @ =0x030013b4
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08086a1c @ =0x030013b6
    movs r3, #0x80
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r0]
    ldr r0, lbl_08086a20 @ =0x030013b8
    strh r1, [r0]
    ldr r0, lbl_08086a24 @ =0x030013ba
    strh r2, [r0]
    ldr r0, lbl_08086a28 @ =0x030013bc
    strh r1, [r0]
    ldr r0, lbl_08086a2c @ =0x030013be
    strh r1, [r0]
    ldr r0, lbl_08086a30 @ =0x030013c0
    strh r1, [r0]
    ldr r0, lbl_08086a34 @ =0x030013c2
    strh r1, [r0]
    ldr r0, lbl_08086a38 @ =0x04000010
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    ldr r0, lbl_08086a3c @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r3, #0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r2]
    ldr r2, lbl_08086a40 @ =0x000002c2
    adds r1, r1, r2
    movs r0, #0xff
    strh r0, [r1]
    ldr r0, lbl_08086a44 @ =0x030013b0
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086a48 @ =0x030013b2
    strh r3, [r0]
    ldr r0, lbl_08086a4c @ =0x030013ae
    strh r1, [r0]
    bl vblank_code_during_gallery
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080869f4: .4byte 0x0859f5a8
lbl_080869f8: .4byte 0x06011000
lbl_080869fc: .4byte 0x040000d4
lbl_08086a00: .4byte 0x08549b44
lbl_08086a04: .4byte 0x05000200
lbl_08086a08: .4byte 0x800000e0
lbl_08086a0c: .4byte 0x04000008
lbl_08086a10: .4byte 0x00009e09
lbl_08086a14: .4byte 0x03001382
lbl_08086a18: .4byte 0x030013b4
lbl_08086a1c: .4byte 0x030013b6
lbl_08086a20: .4byte 0x030013b8
lbl_08086a24: .4byte 0x030013ba
lbl_08086a28: .4byte 0x030013bc
lbl_08086a2c: .4byte 0x030013be
lbl_08086a30: .4byte 0x030013c0
lbl_08086a34: .4byte 0x030013c2
lbl_08086a38: .4byte 0x04000010
lbl_08086a3c: .4byte 0x08754bc4
lbl_08086a40: .4byte 0x000002c2
lbl_08086a44: .4byte 0x030013b0
lbl_08086a48: .4byte 0x030013b2
lbl_08086a4c: .4byte 0x030013ae

    thumb_func_start ending_image_display_text
ending_image_display_text: @ 0x08086a50
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r5, lbl_08086ab8 @ =0x03000e7c
    movs r0, #0
    mov sl, r0
    movs r7, #0
    movs r4, #0
    ldr r1, lbl_08086abc @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r7, r0
    blt lbl_08086a72
    b lbl_08086ba0
lbl_08086a72:
    ldr r2, lbl_08086abc @ =0x08754bc4
    ldr r1, [r2]
    movs r2, #0x92
    lsls r2, r2, #1
    adds r0, r1, r2
    adds r0, r0, r4
    ldrb r0, [r0]
    adds r2, r4, #1
    mov sb, r2
    cmp r0, #1
    bhi lbl_08086a8a
    b lbl_08086b90
lbl_08086a8a:
    movs r2, #0xb0
    lsls r2, r2, #1
    adds r0, r1, r2
    adds r1, r0, r4
    ldrb r0, [r1]
    cmp r0, #0x3f
    bhi lbl_08086a9c
    adds r0, #1
    strb r0, [r1]
lbl_08086a9c:
    movs r0, #0
    mov ip, r0
    cmp r4, #5
    ble lbl_08086ad2
    ldr r1, lbl_08086abc @ =0x08754bc4
    ldr r0, [r1]
    adds r0, r0, r2
    adds r0, r0, r4
    ldrb r0, [r0]
    cmp r0, #3
    bhi lbl_08086ac0
    movs r2, #0xb
    mov ip, r2
    b lbl_08086afa
    .align 2, 0
lbl_08086ab8: .4byte 0x03000e7c
lbl_08086abc: .4byte 0x08754bc4
lbl_08086ac0:
    cmp r0, #7
    bhi lbl_08086ac8
    movs r0, #0xc
    b lbl_08086af8
lbl_08086ac8:
    cmp r0, #0xb
    bhi lbl_08086afa
    movs r1, #0xd
    mov ip, r1
    b lbl_08086afa
lbl_08086ad2:
    cmp r4, #5
    bne lbl_08086afa
    ldr r2, lbl_08086c60 @ =0x08754bc4
    ldr r0, [r2]
    ldr r1, lbl_08086c64 @ =0x00000165
    adds r2, r0, r1
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r2, lbl_08086c60 @ =0x08754bc4
    ldr r0, [r2]
    ldr r1, lbl_08086c64 @ =0x00000165
    adds r0, r0, r1
    ldrb r0, [r0]
    lsrs r0, r0, #3
    ldr r2, lbl_08086c68 @ =0x0854e2dc
    adds r0, r0, r2
    ldrb r0, [r0]
lbl_08086af8:
    mov ip, r0
lbl_08086afa:
    ldr r1, lbl_08086c60 @ =0x08754bc4
    ldr r0, [r1]
    lsls r1, r4, #2
    movs r2, #0xfc
    lsls r2, r2, #1
    adds r0, r0, r2
    adds r0, r0, r1
    ldr r3, [r0]
    ldrh r2, [r3]
    adds r3, #2
    movs r0, #0xff
    ands r2, r0
    add sl, r2
    adds r0, r4, #1
    mov sb, r0
    cmp r7, sl
    bge lbl_08086b90
    ldr r1, lbl_08086c60 @ =0x08754bc4
    mov r8, r1
    lsls r6, r4, #1
    lsls r0, r7, #3
    ldr r2, lbl_08086c6c @ =0x03000e7c
    adds r4, r0, r2
    mov r0, ip
    lsls r0, r0, #4
    mov ip, r0
    mov r1, sl
    subs r7, r1, r7
lbl_08086b32:
    ldrh r2, [r3]
    adds r3, #2
    strh r2, [r5]
    adds r5, #2
    mov r1, r8
    ldr r0, [r1]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r6
    ldrb r0, [r0]
    adds r0, r0, r2
    strb r0, [r4]
    ldrh r2, [r3]
    adds r3, #2
    strh r2, [r5]
    adds r5, #2
    mov r1, r8
    ldr r0, [r1]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r0, r1
    adds r0, r0, r6
    ldrh r1, [r0]
    adds r1, r2, r1
    ldr r2, lbl_08086c70 @ =0x000001ff
    ands r1, r2
    ldrh r2, [r4, #2]
    ldr r0, lbl_08086c74 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r4, #2]
    ldrh r0, [r3]
    strh r0, [r5]
    adds r3, #2
    ldrb r1, [r4, #5]
    movs r0, #0xf
    ands r0, r1
    mov r1, ip
    orrs r0, r1
    strb r0, [r4, #5]
    adds r5, #4
    adds r4, #8
    subs r7, #1
    cmp r7, #0
    bne lbl_08086b32
    mov r7, sl
lbl_08086b90:
    mov r4, sb
    ldr r2, lbl_08086c60 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r4, r0
    bge lbl_08086ba0
    b lbl_08086a72
lbl_08086ba0:
    ldr r4, lbl_08086c60 @ =0x08754bc4
    ldr r1, [r4]
    ldr r2, lbl_08086c78 @ =0x00000141
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08086c4c
    ldr r3, lbl_08086c7c @ =0x0000017d
    adds r0, r1, r3
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #0x46
    bls lbl_08086bc8
    ldr r0, [r4]
    adds r1, r0, r3
    movs r0, #0
    strb r0, [r1]
lbl_08086bc8:
    ldr r4, lbl_08086c80 @ =0x0854e2e4
    ldr r1, lbl_08086c60 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, r0, r3
    ldrb r0, [r0]
    movs r1, #6
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r0, r0, r4
    ldrb r0, [r0]
    mov ip, r0
    ldr r3, lbl_08086c84 @ =0x08549eec
    ldrh r2, [r3]
    adds r3, #2
    movs r0, #0xff
    ands r2, r0
    add sl, r2
    cmp r7, sl
    bge lbl_08086c4c
    ldr r1, lbl_08086c6c @ =0x03000e7c
    ldr r2, lbl_08086c70 @ =0x000001ff
    mov r8, r2
    ldr r0, lbl_08086c74 @ =0xfffffe00
    mov sb, r0
    mov r2, ip
    lsls r6, r2, #4
    lsls r0, r7, #3
    adds r4, r0, r1
    mov r0, sl
    subs r7, r0, r7
lbl_08086c08:
    ldrh r2, [r3]
    adds r3, #2
    strh r2, [r5]
    adds r5, #2
    adds r0, r2, #0
    adds r0, #0x3b
    strb r0, [r4]
    ldrh r2, [r3]
    adds r3, #2
    strh r2, [r5]
    adds r5, #2
    adds r1, r2, #0
    adds r1, #0x30
    mov r2, r8
    ands r1, r2
    ldrh r2, [r4, #2]
    mov r0, sb
    ands r0, r2
    orrs r0, r1
    strh r0, [r4, #2]
    ldrh r0, [r3]
    strh r0, [r5]
    adds r3, #2
    ldrb r1, [r4, #5]
    movs r0, #0xf
    ands r0, r1
    orrs r0, r6
    strb r0, [r4, #5]
    adds r5, #4
    adds r4, #8
    subs r7, #1
    cmp r7, #0
    bne lbl_08086c08
    mov r7, sl
lbl_08086c4c:
    ldr r0, lbl_08086c88 @ =0x03001382
    strb r7, [r0]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08086c60: .4byte 0x08754bc4
lbl_08086c64: .4byte 0x00000165
lbl_08086c68: .4byte 0x0854e2dc
lbl_08086c6c: .4byte 0x03000e7c
lbl_08086c70: .4byte 0x000001ff
lbl_08086c74: .4byte 0xfffffe00
lbl_08086c78: .4byte 0x00000141
lbl_08086c7c: .4byte 0x0000017d
lbl_08086c80: .4byte 0x0854e2e4
lbl_08086c84: .4byte 0x08549eec
lbl_08086c88: .4byte 0x03001382

    thumb_func_start ending_image_display
ending_image_display: @ 0x08086c8c
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r4, lbl_08086cbc @ =0x08754bc4
    ldr r2, [r4]
    ldrh r3, [r2, #4]
    adds r0, r3, #1
    strh r0, [r2, #4]
    lsls r0, r3, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_08086cc0 @ =0x00000177
    cmp r1, r0
    beq lbl_08086d60
    cmp r1, r0
    bgt lbl_08086cd2
    cmp r1, #0x6e
    beq lbl_08086d26
    cmp r1, #0x6e
    bgt lbl_08086cc4
    cmp r1, #0
    beq lbl_08086d10
    cmp r1, #0x1e
    beq lbl_08086d18
    b lbl_08086dd6
    .align 2, 0
lbl_08086cbc: .4byte 0x08754bc4
lbl_08086cc0: .4byte 0x00000177
lbl_08086cc4:
    cmp r1, #0xb4
    beq lbl_08086d2e
    movs r0, #0xa5
    lsls r0, r0, #1
    cmp r1, r0
    beq lbl_08086d58
    b lbl_08086dd6
lbl_08086cd2:
    ldr r0, lbl_08086cec @ =0x00000212
    cmp r1, r0
    beq lbl_08086d9c
    cmp r1, r0
    bgt lbl_08086cf0
    subs r0, #0x96
    cmp r1, r0
    beq lbl_08086d7a
    adds r0, #0x50
    cmp r1, r0
    beq lbl_08086d94
    b lbl_08086dd6
    .align 2, 0
lbl_08086cec: .4byte 0x00000212
lbl_08086cf0:
    movs r0, #0xac
    lsls r0, r0, #3
    cmp r1, r0
    beq lbl_08086db6
    cmp r1, r0
    bgt lbl_08086d06
    movs r0, #0xc3
    lsls r0, r0, #2
    cmp r1, r0
    beq lbl_08086da4
    b lbl_08086dd6
lbl_08086d06:
    movs r0, #0xd0
    lsls r0, r0, #3
    cmp r1, r0
    beq lbl_08086dd4
    b lbl_08086dd6
lbl_08086d10:
    ldrh r0, [r2, #8]
    adds r0, #1
    strh r0, [r2, #8]
    b lbl_08086dd6
lbl_08086d18:
    movs r0, #0
    bl sub_08084c7c
    ldr r1, [r4]
    movs r0, #1
    strb r0, [r1, #1]
    b lbl_08086dd6
lbl_08086d26:
    movs r0, #0
    bl sub_08084ee8
    b lbl_08086dd6
lbl_08086d2e:
    movs r0, #1
    bl sub_08084ee8
    ldr r0, lbl_08086d50 @ =0x03001604
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08086dd6
    ldr r0, [r4]
    ldr r2, lbl_08086d54 @ =0x00000141
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08086dd6
    .align 2, 0
lbl_08086d50: .4byte 0x03001604
lbl_08086d54: .4byte 0x00000141
lbl_08086d58:
    movs r0, #1
    bl sub_08084c7c
    b lbl_08086dd6
lbl_08086d60:
    adds r0, r2, #0
    adds r0, #0x9a
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08086d72
    cmp r0, #2
    beq lbl_08086d72
    cmp r0, #5
    bne lbl_08086dd6
lbl_08086d72:
    movs r0, #2
    bl sub_08084ee8
    b lbl_08086dd6
lbl_08086d7a:
    adds r0, r2, #0
    adds r0, #0x9a
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08086d8c
    cmp r0, #2
    beq lbl_08086d8c
    cmp r0, #5
    bne lbl_08086dd6
lbl_08086d8c:
    movs r0, #2
    bl sub_08084c7c
    b lbl_08086dd6
lbl_08086d94:
    movs r0, #3
    bl sub_08084ee8
    b lbl_08086dd6
lbl_08086d9c:
    movs r0, #4
    bl sub_08084ee8
    b lbl_08086dd6
lbl_08086da4:
    adds r0, r2, #0
    adds r0, #0x9a
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_08086dd6
    movs r0, #5
    bl sub_08084ee8
    b lbl_08086dd6
lbl_08086db6:
    ldr r0, lbl_08086dcc @ =0x03001380
    ldrh r1, [r0]
    movs r0, #0xb
    ands r0, r1
    cmp r0, #0
    beq lbl_08086dd0
    movs r0, #0x80
    lsls r0, r0, #1
    bl FadeMusic
    b lbl_08086dd6
    .align 2, 0
lbl_08086dcc: .4byte 0x03001380
lbl_08086dd0:
    strh r3, [r2, #4]
    b lbl_08086dd6
lbl_08086dd4:
    movs r6, #1
lbl_08086dd6:
    ldr r0, lbl_08086df8 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2, #8]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08086e10
    ldr r1, lbl_08086dfc @ =0x030013b6
    ldrh r0, [r1]
    cmp r0, #6
    bls lbl_08086e04
    subs r0, #6
    strh r0, [r1]
    ldr r1, lbl_08086e00 @ =0x030013ba
    ldrh r0, [r1]
    subs r0, #6
    strh r0, [r1]
    b lbl_08086e10
    .align 2, 0
lbl_08086df8: .4byte 0x08754bc4
lbl_08086dfc: .4byte 0x030013b6
lbl_08086e00: .4byte 0x030013ba
lbl_08086e04:
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_08086e68 @ =0x030013ba
    strh r0, [r1]
    movs r0, #0
    strh r0, [r2, #8]
lbl_08086e10:
    ldr r0, [r3]
    ldrh r1, [r0, #4]
    ldr r0, lbl_08086e6c @ =0x00000564
    cmp r1, r0
    bhi lbl_08086e5e
    ldr r0, lbl_08086e70 @ =0x00000329
    cmp r1, r0
    bls lbl_08086e2e
    ldr r0, lbl_08086e74 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0xc0
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08086e5e
lbl_08086e2e:
    ldr r1, [r3]
    ldrb r0, [r1, #1]
    cmp r0, #1
    bne lbl_08086e5a
    movs r4, #6
    adds r0, r1, #0
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r4, r0
    bhs lbl_08086e5a
    adds r5, r3, #0
lbl_08086e44:
    adds r0, r4, #0
    bl sub_08084c34
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r0, [r5]
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r4, r0
    blo lbl_08086e44
lbl_08086e5a:
    bl ending_image_display_text
lbl_08086e5e:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08086e68: .4byte 0x030013ba
lbl_08086e6c: .4byte 0x00000564
lbl_08086e70: .4byte 0x00000329
lbl_08086e74: .4byte 0x0300137c

    thumb_func_start unlocked_options_init
unlocked_options_init: @ 0x08086e78
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #8
    ldr r4, lbl_08086f64 @ =0x04000208
    movs r0, #0
    mov r8, r0
    strh r0, [r4]
    ldr r2, lbl_08086f68 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08086f6c @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08086f70 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08086f74 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08086f78 @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r5, #1
    strh r5, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    mov r1, r8
    strh r1, [r0]
    strh r1, [r4]
    ldr r2, lbl_08086f7c @ =vblank_code_during_unlocked_options
    mov sb, r2
    mov r0, sb
    bl CallbackSetVBlank
    strh r5, [r4]
    movs r6, #0
    str r6, [sp, #4]
    ldr r4, lbl_08086f80 @ =0x040000d4
    add r0, sp, #4
    str r0, [r4]
    ldr r0, lbl_08086f84 @ =0x030016c4
    str r0, [r4, #4]
    ldr r0, lbl_08086f88 @ =0x8500018a
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    bl ClearGfxRam
    ldr r0, lbl_08086f8c @ =0x085c943c
    ldr r1, lbl_08086f90 @ =0x06008000
    bl LZ77UncompVRAM
    movs r1, #1
    rsbs r1, r1, #0
    ldr r2, lbl_08086f94 @ =0x06007fe0
    movs r5, #0x20
    str r5, [sp]
    movs r0, #3
    movs r3, #0x20
    bl BitFill
    ldr r1, lbl_08086f98 @ =0xf3fff3ff
    ldr r2, lbl_08086f9c @ =0x06008800
    movs r3, #0x80
    lsls r3, r3, #4
    str r5, [sp]
    movs r0, #3
    bl BitFill
    ldr r0, lbl_08086fa0 @ =0x0854bd34
    str r0, [r4]
    ldr r0, lbl_08086fa4 @ =0x050001e0
    str r0, [r4, #4]
    ldr r0, lbl_08086fa8 @ =0x80000010
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, lbl_08086fac @ =0x04000008
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_08086fb0 @ =0x00001101
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08086fb4 @ =0x03001382
    mov r1, r8
    strb r1, [r0]
    bl ResetFreeOAM
    ldr r0, lbl_08086fb8 @ =0x04000010
    strh r6, [r0]
    adds r0, #2
    strh r6, [r0]
    ldr r0, lbl_08086fbc @ =0x08754bc4
    ldr r0, [r0]
    movs r2, #0xb0
    lsls r2, r2, #2
    adds r1, r0, r2
    strh r6, [r1]
    ldr r1, lbl_08086fc0 @ =0x000002c2
    adds r0, r0, r1
    strh r6, [r0]
    ldr r0, lbl_08086fc4 @ =0x030013b0
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086fc8 @ =0x030013b2
    strh r6, [r0]
    ldr r0, lbl_08086fcc @ =0x030013ae
    strh r1, [r0]
    bl _call_via_r9
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08086f64: .4byte 0x04000208
lbl_08086f68: .4byte 0x04000004
lbl_08086f6c: .4byte 0x0000ffef
lbl_08086f70: .4byte 0x04000200
lbl_08086f74: .4byte 0x0000fffd
lbl_08086f78: .4byte 0x04000202
lbl_08086f7c: .4byte vblank_code_during_unlocked_options
lbl_08086f80: .4byte 0x040000d4
lbl_08086f84: .4byte 0x030016c4
lbl_08086f88: .4byte 0x8500018a
lbl_08086f8c: .4byte 0x085c943c
lbl_08086f90: .4byte 0x06008000
lbl_08086f94: .4byte 0x06007fe0
lbl_08086f98: .4byte 0xf3fff3ff
lbl_08086f9c: .4byte 0x06008800
lbl_08086fa0: .4byte 0x0854bd34
lbl_08086fa4: .4byte 0x050001e0
lbl_08086fa8: .4byte 0x80000010
lbl_08086fac: .4byte 0x04000008
lbl_08086fb0: .4byte 0x00001101
lbl_08086fb4: .4byte 0x03001382
lbl_08086fb8: .4byte 0x04000010
lbl_08086fbc: .4byte 0x08754bc4
lbl_08086fc0: .4byte 0x000002c2
lbl_08086fc4: .4byte 0x030013b0
lbl_08086fc8: .4byte 0x030013b2
lbl_08086fcc: .4byte 0x030013ae

    thumb_func_start unlocked_options_pop_up
unlocked_options_pop_up: @ 0x08086fd0
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r3, lbl_08086ff4 @ =0x08754bc4
    ldr r2, [r3]
    ldrh r1, [r2, #4]
    adds r0, r1, #1
    strh r0, [r2, #4]
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x20
    beq lbl_0808705c
    cmp r0, #0x20
    bgt lbl_08086ff8
    cmp r0, #0
    beq lbl_08086ffe
    b lbl_080870aa
    .align 2, 0
lbl_08086ff4: .4byte 0x08754bc4
lbl_08086ff8:
    cmp r0, #0x80
    beq lbl_080870a8
    b lbl_080870aa
lbl_08086ffe:
    movs r2, #0xc0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #6
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r0, lbl_08087024 @ =0x03001604
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08087028
    movs r1, #0x21
    b lbl_08087040
    .align 2, 0
lbl_08087024: .4byte 0x03001604
lbl_08087028:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08087034
    movs r1, #0x23
    b lbl_08087040
lbl_08087034:
    adds r0, r4, #0
    ands r0, r1
    movs r1, #0x24
    cmp r0, #0
    beq lbl_08087040
    movs r1, #0x22
lbl_08087040:
    adds r0, r1, #0
    bl start_file_screen_text
    ldr r0, lbl_08087058 @ =0x08754bc4
    ldr r0, [r0]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    strb r1, [r0]
    b lbl_080870aa
    .align 2, 0
lbl_08087058: .4byte 0x08754bc4
lbl_0808705c:
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r0, #0x88
    lsls r0, r0, #6
    strh r0, [r1]
    ldr r1, lbl_080870a0 @ =0x04000048
    movs r0, #3
    strh r0, [r1]
    ldr r0, lbl_080870a4 @ =0x0400004a
    strh r5, [r0]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    ldr r2, [r3]
    movs r1, #0xbf
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0x78
    strh r1, [r0]
    movs r3, #0xc0
    lsls r3, r3, #1
    adds r0, r2, r3
    strh r1, [r0]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0x50
    strh r1, [r0]
    adds r3, #0x3c
    adds r0, r2, r3
    strh r1, [r0]
    b lbl_080870aa
    .align 2, 0
lbl_080870a0: .4byte 0x04000048
lbl_080870a4: .4byte 0x0400004a
lbl_080870a8:
    strh r1, [r2, #4]
lbl_080870aa:
    ldr r4, lbl_08087108 @ =0x08754bc4
    ldr r0, [r4]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080870c8
    bl sub_0806f5c4
    ldr r1, [r4]
    movs r2, #0x92
    lsls r2, r2, #1
    adds r1, r1, r2
    strb r0, [r1]
lbl_080870c8:
    ldr r3, [r4]
    ldrb r0, [r3, #1]
    cmp r0, #1
    bne lbl_08087142
    movs r0, #0xbf
    lsls r0, r0, #1
    adds r0, r0, r3
    mov ip, r0
    ldrh r0, [r0]
    cmp r0, #0x30
    bls lbl_0808710c
    subs r0, #8
    mov r1, ip
    strh r0, [r1]
    movs r2, #0xc0
    lsls r2, r2, #1
    adds r1, r3, r2
    ldrh r0, [r1]
    adds r0, #8
    strh r0, [r1]
    movs r0, #0xdd
    lsls r0, r0, #1
    adds r1, r3, r0
    ldrh r0, [r1]
    subs r0, #4
    strh r0, [r1]
    adds r2, #0x3c
    adds r1, r3, r2
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    b lbl_080871d2
    .align 2, 0
lbl_08087108: .4byte 0x08754bc4
lbl_0808710c:
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r3, r0
    movs r0, #0x8c
    lsls r0, r0, #6
    strh r0, [r1]
    movs r2, #0x2c
    mov r1, ip
    strh r2, [r1]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r1, r3, r0
    movs r0, #0xbc
    strh r0, [r1]
    movs r1, #0xdd
    lsls r1, r1, #1
    adds r0, r3, r1
    strh r2, [r0]
    movs r2, #0xde
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x74
    strh r0, [r1]
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    b lbl_080871d2
lbl_08087142:
    cmp r0, #2
    bne lbl_08087174
    ldr r0, lbl_08087170 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080871d2
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r1, r3, r0
    movs r0, #0x88
    lsls r0, r0, #6
    strh r0, [r1]
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    ldr r1, [r4]
    ldrh r0, [r1, #4]
    adds r0, #1
    strh r0, [r1, #4]
    b lbl_080871d2
    .align 2, 0
lbl_08087170: .4byte 0x03001380
lbl_08087174:
    cmp r0, #3
    bne lbl_080871d2
    movs r2, #0xbf
    lsls r2, r2, #1
    adds r1, r3, r2
    ldrh r0, [r1]
    cmp r0, #0x6f
    bhi lbl_080871ac
    adds r0, #8
    strh r0, [r1]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r1, r3, r0
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
    adds r2, #0x3c
    adds r1, r3, r2
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    movs r0, #0xde
    lsls r0, r0, #1
    adds r1, r3, r0
    ldrh r0, [r1]
    subs r0, #4
    strh r0, [r1]
    b lbl_080871d2
lbl_080871ac:
    movs r2, #0xb0
    lsls r2, r2, #2
    adds r1, r3, r2
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_080871c8 @ =0x03001604
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080871cc
    adds r0, r5, #1
    b lbl_080871ce
    .align 2, 0
lbl_080871c8: .4byte 0x03001604
lbl_080871cc:
    adds r0, r5, #2
lbl_080871ce:
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_080871d2:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start credits_main
credits_main: @ 0x080871dc
    push {r4, r5, lr}
    movs r5, #0
    ldr r1, lbl_08087204 @ =0x08754bc4
    ldr r0, [r1]
    strb r5, [r0, #6]
    ldr r0, lbl_08087208 @ =0x03001382
    strb r5, [r0]
    ldr r0, lbl_0808720c @ =0x03000c72
    movs r2, #0
    ldrsh r3, [r0, r2]
    adds r4, r1, #0
    adds r2, r0, #0
    cmp r3, #0xf
    bls lbl_080871fa
    b lbl_080873d0
lbl_080871fa:
    lsls r0, r3, #2
    ldr r1, lbl_08087210 @ =lbl_08087214
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08087204: .4byte 0x08754bc4
lbl_08087208: .4byte 0x03001382
lbl_0808720c: .4byte 0x03000c72
lbl_08087210: .4byte lbl_08087214
lbl_08087214: @ jump table
    .4byte lbl_08087254 @ case 0
    .4byte lbl_08087360 @ case 1
    .4byte lbl_0808725a @ case 2
    .4byte lbl_08087360 @ case 3
    .4byte lbl_080872b0 @ case 4
    .4byte lbl_080872da @ case 5
    .4byte lbl_080872b6 @ case 6
    .4byte lbl_080872a0 @ case 7
    .4byte lbl_080872d4 @ case 8
    .4byte lbl_080872da @ case 9
    .4byte lbl_08087300 @ case 10
    .4byte lbl_080872a0 @ case 11
    .4byte lbl_08087378 @ case 12
    .4byte lbl_080872da @ case 13
    .4byte lbl_0808738c @ case 14
    .4byte lbl_08087354 @ case 15
lbl_08087254:
    bl credits_init
    b lbl_0808737c
lbl_0808725a:
    ldr r1, lbl_08087298 @ =0x08760cf8
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    beq lbl_0808734a
    ldr r2, [r4]
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #0
    strb r0, [r2]
    ldr r0, [r4]
    strb r1, [r0, #1]
    ldr r0, [r4]
    strb r1, [r0, #2]
    ldr r0, [r4]
    strh r1, [r0, #4]
    cmp r3, #1
    bls lbl_0808734a
lbl_0808728c:
    ldr r1, lbl_0808729c @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_0808734a
    .align 2, 0
lbl_08087298: .4byte 0x08760cf8
lbl_0808729c: .4byte 0x03000c72
lbl_080872a0:
    ldr r1, lbl_080872ac @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0xf
    bls lbl_08087380
    b lbl_08087360
    .align 2, 0
lbl_080872ac: .4byte 0x030013ae
lbl_080872b0:
    bl end_screen_init
    b lbl_0808737c
lbl_080872b6:
    ldr r1, lbl_080872d0 @ =0x08760d04
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080872ce
    b lbl_080873d0
lbl_080872ce:
    b lbl_0808737c
    .align 2, 0
lbl_080872d0: .4byte 0x08760d04
lbl_080872d4:
    bl ending_image_init
    b lbl_0808737c
lbl_080872da:
    ldr r3, lbl_080872ec @ =0x030013ae
    ldrh r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080872f0
    subs r0, #1
    strh r0, [r3]
    b lbl_080873d0
    .align 2, 0
lbl_080872ec: .4byte 0x030013ae
lbl_080872f0:
    ldr r0, [r4]
    ldr r3, lbl_080872fc @ =0x000002c2
    adds r0, r0, r3
    strh r1, [r0]
    b lbl_08087360
    .align 2, 0
lbl_080872fc: .4byte 0x000002c2
lbl_08087300:
    ldr r1, lbl_08087334 @ =0x08760d08
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0808734a
    ldr r0, lbl_08087338 @ =0x03001604
    ldrb r0, [r0]
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    beq lbl_08087344
    ldr r0, [r4]
    ldr r1, lbl_0808733c @ =0x000002c2
    adds r0, r0, r1
    movs r2, #0
    movs r1, #0xff
    strh r1, [r0]
    ldr r0, lbl_08087340 @ =0x030013ae
    strh r2, [r0]
    b lbl_0808728c
    .align 2, 0
lbl_08087334: .4byte 0x08760d08
lbl_08087338: .4byte 0x03001604
lbl_0808733c: .4byte 0x000002c2
lbl_08087340: .4byte 0x030013ae
lbl_08087344:
    ldr r0, lbl_08087350 @ =0x03000043
    strb r1, [r0]
    adds r5, #1
lbl_0808734a:
    bl ResetFreeOAM
    b lbl_080873d0
    .align 2, 0
lbl_08087350: .4byte 0x03000043
lbl_08087354:
    ldr r0, lbl_08087368 @ =0x03001604
    ldrb r0, [r0]
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    beq lbl_0808736c
lbl_08087360:
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    b lbl_080873d0
    .align 2, 0
lbl_08087368: .4byte 0x03001604
lbl_0808736c:
    ldr r0, lbl_08087374 @ =0x03000043
    strb r1, [r0]
    adds r5, #1
    b lbl_080873d0
    .align 2, 0
lbl_08087374: .4byte 0x03000043
lbl_08087378:
    bl unlocked_options_init
lbl_0808737c:
    ldr r1, lbl_08087388 @ =0x03000c72
    ldrh r0, [r1]
lbl_08087380:
    adds r0, #1
    strh r0, [r1]
    b lbl_080873d0
    .align 2, 0
lbl_08087388: .4byte 0x03000c72
lbl_0808738c:
    ldr r1, lbl_080873d8 @ =0x08760d0c
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    beq lbl_080873cc
    ldr r1, lbl_080873dc @ =0x03001604
    movs r0, #0
    strb r0, [r1]
    ldr r2, [r4]
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #0
    strb r0, [r2]
    ldr r0, [r4]
    strb r1, [r0, #1]
    ldr r0, [r4]
    strb r1, [r0, #2]
    ldr r0, [r4]
    strh r1, [r0, #4]
    cmp r3, #1
    bls lbl_080873cc
    ldr r1, lbl_080873e0 @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_080873cc:
    bl ResetFreeOAM
lbl_080873d0:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080873d8: .4byte 0x08760d0c
lbl_080873dc: .4byte 0x03001604
lbl_080873e0: .4byte 0x03000c72

    thumb_func_start gallery_init
gallery_init: @ 0x080873e4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r4, lbl_08087478 @ =0x04000208
    movs r3, #0
    strh r3, [r4]
    ldr r2, lbl_0808747c @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08087480 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08087484 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08087488 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0808748c @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r5, #1
    strh r5, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r3, [r0]
    strh r3, [r4]
    ldr r0, lbl_08087490 @ =vblank_code_during_gallery
    bl CallbackSetVBlank
    strh r5, [r4]
    ldr r0, lbl_08087494 @ =0x03000c72
    movs r1, #0
    ldrsh r4, [r0, r1]
    cmp r4, #0
    bne lbl_08087440
    bl ClearGfxRam
    str r4, [sp, #4]
    ldr r1, lbl_08087498 @ =0x040000d4
    add r2, sp, #4
    str r2, [r1]
    ldr r0, lbl_0808749c @ =0x030016c4
    str r0, [r1, #4]
    ldr r0, lbl_080874a0 @ =0x8500018a
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08087440:
    ldr r2, lbl_080874a4 @ =0x08754bc4
    ldr r3, [r2]
    adds r0, r3, #0
    adds r0, #0x98
    ldrb r4, [r0]
    movs r5, #0
    movs r0, #1
    lsls r0, r4
    ldr r6, lbl_080874a8 @ =0x03000014
    ldrh r1, [r6]
    ands r1, r0
    mov r8, r2
    ldr r0, lbl_080874ac @ =0x0854c06c
    mov ip, r0
    cmp r1, #0
    bne lbl_080874d0
    adds r0, r3, #0
    adds r0, #0x99
    ldrb r2, [r0]
    movs r7, #1
    adds r3, r6, #0
lbl_0808746a:
    cmp r2, #0
    beq lbl_080874b4
    cmp r4, #0
    beq lbl_080874b0
    subs r4, #1
    b lbl_080874be
    .align 2, 0
lbl_08087478: .4byte 0x04000208
lbl_0808747c: .4byte 0x04000004
lbl_08087480: .4byte 0x0000ffef
lbl_08087484: .4byte 0x04000200
lbl_08087488: .4byte 0x0000fffd
lbl_0808748c: .4byte 0x04000202
lbl_08087490: .4byte vblank_code_during_gallery
lbl_08087494: .4byte 0x03000c72
lbl_08087498: .4byte 0x040000d4
lbl_0808749c: .4byte 0x030016c4
lbl_080874a0: .4byte 0x8500018a
lbl_080874a4: .4byte 0x08754bc4
lbl_080874a8: .4byte 0x03000014
lbl_080874ac: .4byte 0x0854c06c
lbl_080874b0:
    movs r4, #7
    b lbl_080874be
lbl_080874b4:
    cmp r4, #6
    bhi lbl_080874bc
    adds r4, #1
    b lbl_080874be
lbl_080874bc:
    movs r4, #0
lbl_080874be:
    adds r5, #1
    cmp r5, #7
    bhi lbl_080874d0
    adds r1, r7, #0
    lsls r1, r4
    ldrh r0, [r3]
    ands r0, r1
    cmp r0, #0
    beq lbl_0808746a
lbl_080874d0:
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x98
    movs r5, #0
    strb r4, [r0]
    lsls r4, r4, #2
    mov r2, ip
    adds r0, r4, r2
    ldr r0, [r0]
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_080875c0 @ =0x0854c08c
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_080875c4 @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_080875c8 @ =0x0854c0ac
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_080875cc @ =0x0600e000
    bl LZ77UncompVRAM
    ldr r0, lbl_080875d0 @ =0x0854c0cc
    adds r0, r4, r0
    ldr r0, [r0]
    ldr r1, lbl_080875d4 @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r1, lbl_080875d8 @ =0x04ff04ff
    ldr r2, lbl_080875dc @ =0x0600e800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r1, lbl_080875e0 @ =0x040000d4
    ldr r0, lbl_080875e4 @ =0x0854c0ec
    adds r4, r4, r0
    ldr r0, [r4]
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080875e8 @ =0x80000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xcc
    movs r2, #0x9c
    lsls r2, r2, #8
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r2, lbl_080875ec @ =0x00009e09
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_080875f0 @ =0x03001382
    strb r5, [r0]
    bl ResetFreeOAM
    ldr r0, lbl_080875f4 @ =0x030013b4
    strh r5, [r0]
    ldr r0, lbl_080875f8 @ =0x030013b6
    movs r2, #0x80
    lsls r2, r2, #5
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_080875fc @ =0x030013b8
    strh r5, [r0]
    ldr r0, lbl_08087600 @ =0x030013ba
    strh r1, [r0]
    ldr r0, lbl_08087604 @ =0x030013bc
    strh r5, [r0]
    ldr r0, lbl_08087608 @ =0x030013be
    strh r5, [r0]
    ldr r0, lbl_0808760c @ =0x030013c0
    strh r5, [r0]
    ldr r0, lbl_08087610 @ =0x030013c2
    strh r5, [r0]
    ldr r0, lbl_08087614 @ =0x04000010
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    mov r0, r8
    ldr r1, [r0]
    strh r5, [r1, #8]
    movs r0, #0xb0
    lsls r0, r0, #2
    adds r2, r1, r0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r2]
    ldr r2, lbl_08087618 @ =0x000002c2
    adds r1, r1, r2
    movs r0, #0xff
    strh r0, [r1]
    bl vblank_code_during_gallery
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080875c0: .4byte 0x0854c08c
lbl_080875c4: .4byte 0x06008000
lbl_080875c8: .4byte 0x0854c0ac
lbl_080875cc: .4byte 0x0600e000
lbl_080875d0: .4byte 0x0854c0cc
lbl_080875d4: .4byte 0x0600f800
lbl_080875d8: .4byte 0x04ff04ff
lbl_080875dc: .4byte 0x0600e800
lbl_080875e0: .4byte 0x040000d4
lbl_080875e4: .4byte 0x0854c0ec
lbl_080875e8: .4byte 0x80000100
lbl_080875ec: .4byte 0x00009e09
lbl_080875f0: .4byte 0x03001382
lbl_080875f4: .4byte 0x030013b4
lbl_080875f8: .4byte 0x030013b6
lbl_080875fc: .4byte 0x030013b8
lbl_08087600: .4byte 0x030013ba
lbl_08087604: .4byte 0x030013bc
lbl_08087608: .4byte 0x030013be
lbl_0808760c: .4byte 0x030013c0
lbl_08087610: .4byte 0x030013c2
lbl_08087614: .4byte 0x04000010
lbl_08087618: .4byte 0x000002c2

    thumb_func_start gallery_display
gallery_display: @ 0x0808761c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, lbl_08087660 @ =0x08754bc4
    ldr r5, [r1]
    adds r0, r5, #0
    adds r0, #0x98
    ldrb r3, [r0]
    movs r0, #0x80
    lsls r0, r0, #0x11
    lsls r0, r3
    lsrs r6, r0, #0x18
    movs r0, #0
    mov r8, r0
    movs r4, #0
    mov ip, r4
    ldr r0, lbl_08087664 @ =0x03001380
    ldrh r2, [r0]
    movs r0, #2
    ands r0, r2
    adds r7, r1, #0
    cmp r0, #0
    beq lbl_08087670
    ldr r1, lbl_08087668 @ =0x000002c2
    adds r0, r5, r1
    movs r1, #0xff
    strh r1, [r0]
    ldr r0, lbl_0808766c @ =0x030013ae
    mov r1, r8
    strh r1, [r0]
    movs r0, #1
    mov r8, r0
    b lbl_080876b2
    .align 2, 0
lbl_08087660: .4byte 0x08754bc4
lbl_08087664: .4byte 0x03001380
lbl_08087668: .4byte 0x000002c2
lbl_0808766c: .4byte 0x030013ae
lbl_08087670:
    movs r0, #0x11
    ands r0, r2
    cmp r0, #0
    beq lbl_08087688
    cmp r3, #6
    bhi lbl_08087684
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    b lbl_080876a8
lbl_08087684:
    movs r3, #0
    b lbl_080876a8
lbl_08087688:
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_080876b2
    cmp r3, #0
    beq lbl_0808769c
    subs r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    b lbl_0808769e
lbl_0808769c:
    movs r3, #7
lbl_0808769e:
    mov r0, ip
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
lbl_080876a8:
    ldr r0, lbl_08087714 @ =0x03000014
    ldrh r0, [r0]
    cmp r0, r6
    bls lbl_080876b2
    adds r4, #1
lbl_080876b2:
    cmp r4, #0
    beq lbl_080876da
    ldr r0, [r7]
    adds r0, #0x98
    movs r2, #0
    strb r3, [r0]
    ldr r0, [r7]
    adds r0, #0x99
    mov r1, ip
    strb r1, [r0]
    ldr r0, [r7]
    ldr r1, lbl_08087718 @ =0x000002c2
    adds r0, r0, r1
    movs r1, #0xff
    strh r1, [r0]
    ldr r0, lbl_0808771c @ =0x030013ae
    strh r2, [r0]
    ldr r1, lbl_08087720 @ =0x03000c72
    movs r0, #5
    strh r0, [r1]
lbl_080876da:
    movs r4, #0
    movs r3, #8
    ldr r0, [r7]
    ldrh r0, [r0, #8]
    cmp r0, #0
    beq lbl_080876f8
    ldr r0, lbl_08087724 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    rsbs r0, r0, #0
    lsrs r4, r0, #0x1f
    movs r3, #0xc
lbl_080876f8:
    cmp r4, #0
    bne lbl_08087744
    ldr r1, lbl_08087728 @ =0x030013b6
    ldrh r0, [r1]
    cmp r0, r3
    ble lbl_08087730
    subs r0, r0, r3
    strh r0, [r1]
    ldr r1, lbl_0808772c @ =0x030013ba
    ldrh r0, [r1]
    subs r0, r0, r3
    strh r0, [r1]
    b lbl_08087764
    .align 2, 0
lbl_08087714: .4byte 0x03000014
lbl_08087718: .4byte 0x000002c2
lbl_0808771c: .4byte 0x030013ae
lbl_08087720: .4byte 0x03000c72
lbl_08087724: .4byte 0x0300137c
lbl_08087728: .4byte 0x030013b6
lbl_0808772c: .4byte 0x030013ba
lbl_08087730:
    strh r4, [r1]
    ldr r0, lbl_08087740 @ =0x030013ba
    strh r4, [r0]
    ldr r1, [r7]
    movs r0, #1
    strh r0, [r1, #8]
    b lbl_08087764
    .align 2, 0
lbl_08087740: .4byte 0x030013ba
lbl_08087744:
    ldr r4, lbl_08087770 @ =0x030013b6
    ldrh r1, [r4]
    adds r1, r1, r3
    strh r1, [r4]
    ldr r2, lbl_08087774 @ =0x030013ba
    ldrh r0, [r2]
    adds r0, r0, r3
    strh r0, [r2]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r0, #0x80
    lsls r0, r0, #5
    cmp r1, r0
    bls lbl_08087764
    strh r0, [r4]
    strh r0, [r2]
lbl_08087764:
    mov r0, r8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08087770: .4byte 0x030013b6
lbl_08087774: .4byte 0x030013ba

    thumb_func_start GallerySubroutine
GallerySubroutine: @ 0x08087778
    push {r4, r5, r6, r7, lr}
    movs r6, #0
    ldr r0, lbl_0808779c @ =0x08754bc4
    ldr r1, [r0]
    strb r6, [r1, #6]
    ldr r1, lbl_080877a0 @ =0x03000c72
    movs r3, #0
    ldrsh r2, [r1, r3]
    adds r7, r0, #0
    adds r4, r1, #0
    cmp r2, #5
    bhi lbl_08087844
    lsls r0, r2, #2
    ldr r1, lbl_080877a4 @ =lbl_080877a8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0808779c: .4byte 0x08754bc4
lbl_080877a0: .4byte 0x03000c72
lbl_080877a4: .4byte lbl_080877a8
lbl_080877a8: @ jump table
    .4byte lbl_080877c0 @ case 0
    .4byte lbl_080877d0 @ case 1
    .4byte lbl_080877f8 @ case 2
    .4byte lbl_08087810 @ case 3
    .4byte lbl_080877c0 @ case 4
    .4byte lbl_08087810 @ case 5
lbl_080877c0:
    bl gallery_init
    ldr r1, lbl_080877cc @ =0x03000c72
    movs r0, #1
    strh r0, [r1]
    b lbl_08087844
    .align 2, 0
lbl_080877cc: .4byte 0x03000c72
lbl_080877d0:
    ldr r2, lbl_080877e0 @ =0x030013ae
    ldrh r0, [r2]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080877e4
    subs r0, #1
    strh r0, [r2]
    b lbl_08087844
    .align 2, 0
lbl_080877e0: .4byte 0x030013ae
lbl_080877e4:
    ldr r0, [r7]
    ldr r2, lbl_080877f4 @ =0x000002c2
    adds r0, r0, r2
    strh r1, [r0]
    ldrh r0, [r4]
    adds r0, #1
    b lbl_08087842
    .align 2, 0
lbl_080877f4: .4byte 0x000002c2
lbl_080877f8:
    bl gallery_display
    cmp r0, #0
    beq lbl_08087844
    ldr r1, lbl_0808780c @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_08087844
    .align 2, 0
lbl_0808780c: .4byte 0x03000c72
lbl_08087810:
    ldr r5, lbl_08087830 @ =0x030013ae
    ldrh r3, [r5]
    cmp r3, #0xf
    bhi lbl_08087834
    ldr r1, [r7]
    ldrh r2, [r1, #4]
    adds r0, r2, #1
    strh r0, [r1, #4]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    beq lbl_08087844
    adds r0, r3, #1
    strh r0, [r5]
    b lbl_08087844
    .align 2, 0
lbl_08087830: .4byte 0x030013ae
lbl_08087834:
    movs r3, #0
    ldrsh r0, [r4, r3]
    cmp r0, #3
    bne lbl_08087840
    adds r6, #1
    b lbl_08087844
lbl_08087840:
    movs r0, #4
lbl_08087842:
    strh r0, [r4]
lbl_08087844:
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start vblank_during_chozodia_escape
vblank_during_chozodia_escape: @ 0x0808784c
    push {r4, lr}
    ldr r1, lbl_080878e0 @ =0x040000d4
    ldr r0, lbl_080878e4 @ =0x03000e7c
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080878e8 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_080878ec @ =0x08754bc4
    ldr r4, [r0]
    movs r2, #0xdc
    lsls r2, r2, #2
    adds r0, r4, r2
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x50
    adds r2, #2
    adds r0, r4, r2
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_080878f0 @ =0x04000052
    ldr r0, lbl_080878f4 @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_080878f8 @ =0x030013b0
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080878fc @ =0x04000054
    ldr r0, lbl_08087900 @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_08087904 @ =0x04000010
    ldr r0, lbl_08087908 @ =0x030013b4
    ldrh r2, [r0]
    ldr r1, lbl_0808790c @ =0x000001ff
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_08087910 @ =0x04000012
    ldr r0, lbl_08087914 @ =0x030013b6
    ldrb r0, [r0]
    strh r0, [r2]
    adds r3, #4
    ldr r0, lbl_08087918 @ =0x030013b8
    ldrh r2, [r0]
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_0808791c @ =0x04000016
    ldr r0, lbl_08087920 @ =0x030013ba
    ldrb r0, [r0]
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_08087924 @ =0x030013bc
    ldrh r0, [r0]
    ands r1, r0
    strh r1, [r2]
    ldr r1, lbl_08087928 @ =0x0400001a
    ldr r0, lbl_0808792c @ =0x030013be
    ldrb r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08087930 @ =0x0000036e
    adds r0, r4, r1
    ldrb r0, [r0]
    ldr r2, lbl_08087934 @ =0x0000036f
    adds r4, r4, r2
    strb r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080878e0: .4byte 0x040000d4
lbl_080878e4: .4byte 0x03000e7c
lbl_080878e8: .4byte 0x84000100
lbl_080878ec: .4byte 0x08754bc4
lbl_080878f0: .4byte 0x04000052
lbl_080878f4: .4byte 0x030013b2
lbl_080878f8: .4byte 0x030013b0
lbl_080878fc: .4byte 0x04000054
lbl_08087900: .4byte 0x030013ae
lbl_08087904: .4byte 0x04000010
lbl_08087908: .4byte 0x030013b4
lbl_0808790c: .4byte 0x000001ff
lbl_08087910: .4byte 0x04000012
lbl_08087914: .4byte 0x030013b6
lbl_08087918: .4byte 0x030013b8
lbl_0808791c: .4byte 0x04000016
lbl_08087920: .4byte 0x030013ba
lbl_08087924: .4byte 0x030013bc
lbl_08087928: .4byte 0x0400001a
lbl_0808792c: .4byte 0x030013be
lbl_08087930: .4byte 0x0000036e
lbl_08087934: .4byte 0x0000036f

    thumb_func_start sub_08087938
sub_08087938: @ 0x08087938
    push {r4, lr}
    ldr r0, lbl_08087964 @ =0x04000006
    ldrh r3, [r0]
    ldr r4, lbl_08087968 @ =0x04000040
    ldr r0, lbl_0808796c @ =0x08754bc4
    ldr r2, [r0]
    lsls r3, r3, #1
    ldr r1, lbl_08087970 @ =0x0000036f
    adds r0, r2, r1
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #6
    adds r3, r3, r0
    adds r2, #0xec
    adds r2, r2, r3
    ldrh r0, [r2]
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08087964: .4byte 0x04000006
lbl_08087968: .4byte 0x04000040
lbl_0808796c: .4byte 0x08754bc4
lbl_08087970: .4byte 0x0000036f

    thumb_func_start sub_08087974
sub_08087974: @ 0x08087974
    push {lr}
    ldr r2, lbl_08087998 @ =0x040000d4
    ldr r0, lbl_0808799c @ =sub_08087938
    str r0, [r2]
    ldr r0, lbl_080879a0 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x6c
    str r1, [r2, #4]
    ldr r1, lbl_080879a4 @ =0x80000020
    str r1, [r2, #8]
    ldr r1, [r2, #8]
    adds r0, #0x6d
    bl CallbackSetHBlank
    pop {r0}
    bx r0
    .align 2, 0
lbl_08087998: .4byte 0x040000d4
lbl_0808799c: .4byte sub_08087938
lbl_080879a0: .4byte 0x08754bc4
lbl_080879a4: .4byte 0x80000020

    thumb_func_start sub_080879a8
sub_080879a8: @ 0x080879a8
    ldr r1, lbl_080879f4 @ =0x04000040
    movs r0, #0
    strh r0, [r1]
    adds r1, #4
    movs r0, #0xa0
    strh r0, [r1]
    adds r1, #4
    movs r0, #0x3f
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x1f
    strh r0, [r1]
    ldr r0, lbl_080879f8 @ =0x08754bc4
    ldr r2, [r0]
    movs r0, #0xdc
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrh r0, [r2]
    ldr r3, lbl_080879fc @ =0x00002020
    adds r1, r3, #0
    orrs r0, r1
    movs r1, #0
    strh r0, [r2]
    ldr r3, lbl_08087a00 @ =0x04000208
    strh r1, [r3]
    ldr r2, lbl_08087a04 @ =0x04000004
    ldrh r0, [r2]
    movs r1, #0x10
    orrs r0, r1
    strh r0, [r2]
    ldr r2, lbl_08087a08 @ =0x04000200
    ldrh r0, [r2]
    movs r1, #2
    orrs r0, r1
    strh r0, [r2]
    movs r0, #1
    strh r0, [r3]
    bx lr
    .align 2, 0
lbl_080879f4: .4byte 0x04000040
lbl_080879f8: .4byte 0x08754bc4
lbl_080879fc: .4byte 0x00002020
lbl_08087a00: .4byte 0x04000208
lbl_08087a04: .4byte 0x04000004
lbl_08087a08: .4byte 0x04000200

    thumb_func_start sub_08087a0c
sub_08087a0c: @ 0x08087a0c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r2, lbl_08087a38 @ =0x08754bc4
    ldr r0, [r2]
    movs r1, #0xdb
    lsls r1, r1, #2
    adds r0, r0, r1
    ldrh r4, [r0]
    adds r5, r4, #0
    ldr r1, lbl_08087a3c @ =0x0835f570
    lsls r0, r4, #2
    adds r0, r0, r1
    ldr r7, [r0]
    mov sb, r2
    cmp r4, #3
    bhi lbl_08087a40
    movs r3, #0x4c
    movs r0, #0x54
    b lbl_08087a54
    .align 2, 0
lbl_08087a38: .4byte 0x08754bc4
lbl_08087a3c: .4byte 0x0835f570
lbl_08087a40:
    cmp r4, #0x50
    bhi lbl_08087a5a
    movs r0, #0x50
    subs r0, r0, r4
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
    adds r0, r4, #0
    adds r0, #0x50
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
lbl_08087a54:
    mov r8, r0
    movs r4, #0
    b lbl_08087a68
lbl_08087a5a:
    movs r3, #0
    movs r1, #0xa0
    mov r8, r1
    adds r0, r5, #0
    subs r0, #0x50
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
lbl_08087a68:
    mov r1, sb
    ldr r0, [r1]
    ldr r1, lbl_08087ae8 @ =0x0000036e
    adds r0, r0, r1
    ldrb r1, [r0]
    adds r1, #1
    movs r2, #1
    ands r1, r2
    strb r1, [r0]
    adds r6, r3, #0
    adds r0, r4, #0
    cmp r6, r8
    bge lbl_08087ada
    lsls r0, r0, #2
    adds r7, r0, r7
lbl_08087a86:
    movs r0, #0
    ldrsh r1, [r7, r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    movs r1, #0xa
    bl __divsi3
    movs r1, #0x78
    subs r1, r1, r0
    lsls r1, r1, #0x10
    asrs r5, r1, #0x10
    adds r0, #0x78
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    cmp r5, #0
    bge lbl_08087aaa
    movs r5, #0
lbl_08087aaa:
    cmp r4, #0xf0
    ble lbl_08087ab0
    movs r4, #0xf0
lbl_08087ab0:
    mov r1, sb
    ldr r2, [r1]
    lsls r3, r6, #1
    ldr r1, lbl_08087ae8 @ =0x0000036e
    adds r0, r2, r1
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #6
    adds r3, r3, r0
    adds r2, #0xec
    adds r2, r2, r3
    lsls r0, r5, #8
    orrs r4, r0
    strh r4, [r2]
    adds r0, r6, #1
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    adds r7, #4
    cmp r6, r8
    blt lbl_08087a86
lbl_08087ada:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08087ae8: .4byte 0x0000036e

    thumb_func_start GetPercentAndEndingNumber
GetPercentAndEndingNumber: @ 0x08087aec
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r0, lbl_08087bac @ =0x0300002c
    ldrb r6, [r0]
    ldr r5, lbl_08087bb0 @ =0x03001530
    ldrh r0, [r5]
    subs r0, #0x63
    ldr r1, lbl_08087bb4 @ =0x083459c4
    lsls r4, r6, #2
    adds r4, r4, r1
    ldrb r1, [r4]
    bl __divsi3
    mov sl, r0
    ldrh r0, [r5, #2]
    ldrb r1, [r4, #1]
    bl __divsi3
    mov sb, r0
    ldrb r0, [r5, #4]
    ldrb r1, [r4, #2]
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldrb r0, [r5, #5]
    ldrb r1, [r4, #3]
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    movs r4, #0
    movs r2, #1
    movs r1, #0
    ldrb r3, [r5, #0xe]
lbl_08087b3c:
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08087b46
    adds r4, #1
lbl_08087b46:
    lsls r2, r2, #1
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #7
    bls lbl_08087b3c
    movs r2, #1
    movs r1, #0
    mov r0, sl
    lsls r0, r0, #0x18
    str r0, [sp, #8]
    mov r3, sb
    lsls r3, r3, #0x10
    str r3, [sp, #4]
    mov r0, r8
    lsls r0, r0, #0xc
    str r0, [sp]
    lsls r3, r7, #8
    mov ip, r3
    ldr r0, lbl_08087bb0 @ =0x03001530
    ldrb r3, [r0, #0xc]
lbl_08087b70:
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08087b7a
    adds r4, #1
lbl_08087b7a:
    lsls r2, r2, #1
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #4
    bls lbl_08087b70
    ldrb r1, [r5, #0xc]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08087b92
    adds r4, #1
lbl_08087b92:
    mov r1, sl
    adds r0, r4, r1
    add r0, sb
    add r0, r8
    adds r0, r0, r7
    movs r2, #0
    cmp r6, #0
    beq lbl_08087be6
    cmp r0, #0xf
    bhi lbl_08087bb8
    adds r2, r6, #5
    b lbl_08087be6
    .align 2, 0
lbl_08087bac: .4byte 0x0300002c
lbl_08087bb0: .4byte 0x03001530
lbl_08087bb4: .4byte 0x083459c4
lbl_08087bb8:
    cmp r0, #0x63
    bls lbl_08087bd0
    ldr r0, lbl_08087bcc @ =0x03000150
    ldrb r0, [r0]
    adds r2, r6, #3
    cmp r0, #1
    bls lbl_08087be6
    movs r2, #3
    b lbl_08087be6
    .align 2, 0
lbl_08087bcc: .4byte 0x03000150
lbl_08087bd0:
    ldr r0, lbl_08087bdc @ =0x03000150
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_08087be0
    movs r2, #2
    b lbl_08087be6
    .align 2, 0
lbl_08087bdc: .4byte 0x03000150
lbl_08087be0:
    cmp r0, #3
    bhi lbl_08087be6
    movs r2, #1
lbl_08087be6:
    ldr r3, [sp, #8]
    ldr r1, [sp, #4]
    adds r0, r3, r1
    ldr r3, [sp]
    adds r0, r0, r3
    add r0, ip
    lsls r1, r4, #4
    adds r0, r0, r1
    adds r0, r0, r2
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start chozodia_escape_process_oam
chozodia_escape_process_oam: @ 0x08087c08
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r5, lbl_08087c70 @ =0x03000e7c
    movs r0, #0
    mov sl, r0
    movs r6, #0
    movs r7, #0
lbl_08087c1e:
    ldr r1, lbl_08087c74 @ =0x08754bc4
    ldr r2, [r1]
    adds r0, r2, #6
    adds r0, r0, r7
    ldrb r0, [r0]
    adds r3, r7, #1
    mov r8, r3
    cmp r0, #0
    beq lbl_08087cca
    mov ip, sl
    lsls r1, r7, #2
    adds r0, r2, #0
    adds r0, #0xc
    adds r0, r0, r1
    ldr r4, [r0]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov r3, ip
    adds r0, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    lsls r1, r7, #1
    adds r0, r2, #0
    adds r0, #0x2a
    adds r0, r0, r1
    ldrh r0, [r0]
    str r0, [sp]
    adds r0, r2, #0
    adds r0, #0x34
    adds r0, r0, r1
    ldrh r0, [r0]
    mov sb, r0
    cmp r6, sl
    bhs lbl_08087cca
    cmp r7, #4
    bne lbl_08087c78
    adds r0, r2, #0
    b lbl_08087cc0
    .align 2, 0
lbl_08087c70: .4byte 0x03000e7c
lbl_08087c74: .4byte 0x08754bc4
lbl_08087c78:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r0, lbl_08087ce8 @ =0x03000e7c
    adds r3, r3, r0
    mov r2, sb
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldr r0, [sp]
    adds r1, r1, r0
    ldr r0, lbl_08087cec @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_08087cf0 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, sl
    bhs lbl_08087cca
    cmp r7, #4
    bne lbl_08087c78
    ldr r1, lbl_08087cf4 @ =0x08754bc4
    ldr r0, [r1]
lbl_08087cc0:
    adds r0, #0x24
    ldrb r0, [r0]
    add r0, ip
    cmp r6, r0
    blt lbl_08087c78
lbl_08087cca:
    mov r2, r8
    lsls r0, r2, #0x10
    lsrs r7, r0, #0x10
    cmp r7, #4
    bls lbl_08087c1e
    ldr r3, lbl_08087cf8 @ =0x03001382
    strb r6, [r3]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08087ce8: .4byte 0x03000e7c
lbl_08087cec: .4byte 0x000001ff
lbl_08087cf0: .4byte 0xfffffe00
lbl_08087cf4: .4byte 0x08754bc4
lbl_08087cf8: .4byte 0x03001382

    thumb_func_start chozodia_escape_process_oam2
chozodia_escape_process_oam2: @ 0x08087cfc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r5, lbl_08087e38 @ =0x03000e7c
    movs r0, #0
    mov r8, r0
    movs r6, #0
    ldr r0, lbl_08087e3c @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_08087d8e
    ldr r4, [r1, #0xc]
    ldrh r2, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r2, r0
    mov r8, r2
    ldrh r7, [r1, #0x2a]
    mov ip, r7
    ldrh r7, [r1, #0x34]
    cmp r6, r8
    bhs lbl_08087d7c
    mov r0, ip
    lsls r0, r0, #0x10
    mov sb, r0
    lsls r7, r7, #0x10
lbl_08087d38:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    ldr r0, lbl_08087e3c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x62
    movs r1, #0
    ldrsh r0, [r0, r1]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r6, #0
    mov r2, sb
    asrs r1, r2, #0x10
    asrs r2, r7, #0x10
    movs r3, #0
    bl ProcessComplexOam
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r8
    blo lbl_08087d38
lbl_08087d7c:
    ldr r0, lbl_08087e3c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x62
    movs r7, #0
    ldrsh r1, [r0, r7]
    movs r0, #0
    movs r2, #0
    bl CalculateOamPart4
lbl_08087d8e:
    movs r3, #1
lbl_08087d90:
    ldr r0, lbl_08087e3c @ =0x08754bc4
    ldr r2, [r0]
    adds r0, r2, #6
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r1, r3, #1
    str r1, [sp, #0xc]
    cmp r0, #0
    beq lbl_08087e1a
    lsls r1, r3, #2
    adds r0, r2, #0
    adds r0, #0xc
    adds r0, r0, r1
    ldr r4, [r0]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    mov r7, r8
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    lsls r1, r3, #1
    adds r0, r2, #0
    adds r0, #0x2a
    adds r0, r0, r1
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r2, #0
    adds r0, #0x34
    adds r0, r0, r1
    ldrh r7, [r0]
    cmp r6, r8
    bhs lbl_08087e1a
    ldr r0, lbl_08087e40 @ =0x000001ff
    mov sb, r0
    ldr r1, lbl_08087e44 @ =0xfffffe00
    mov sl, r1
lbl_08087dde:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_08087e38 @ =0x03000e7c
    adds r3, r3, r2
    adds r0, r1, r7
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, ip
    mov r0, sb
    ands r1, r0
    ldrh r2, [r3, #2]
    mov r0, sl
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r8
    blo lbl_08087dde
lbl_08087e1a:
    ldr r1, [sp, #0xc]
    lsls r0, r1, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #2
    bls lbl_08087d90
    ldr r2, lbl_08087e48 @ =0x03001382
    strb r6, [r2]
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08087e38: .4byte 0x03000e7c
lbl_08087e3c: .4byte 0x08754bc4
lbl_08087e40: .4byte 0x000001ff
lbl_08087e44: .4byte 0xfffffe00
lbl_08087e48: .4byte 0x03001382

    thumb_func_start chozodia_escape_init
chozodia_escape_init: @ 0x08087e4c
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r4, lbl_0808802c @ =0x04000208
    movs r5, #0
    strh r5, [r4]
    ldr r2, lbl_08088030 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08088034 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08088038 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_0808803c @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08088040 @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r6, #1
    strh r6, [r4]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r5, [r0]
    strh r5, [r4]
    ldr r0, lbl_08088044 @ =vblank_during_chozodia_escape
    bl CallbackSetVBlank
    strh r6, [r4]
    bl ClearGfxRam
    ldr r0, lbl_08088048 @ =0x083ab6c0
    ldr r1, lbl_0808804c @ =0x06010000
    bl LZ77UncompVRAM
    ldr r0, lbl_08088050 @ =0x083a4878
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    ldr r0, lbl_08088054 @ =0x083a97a4
    ldr r1, lbl_08088058 @ =0x06008000
    bl LZ77UncompVRAM
    ldr r0, lbl_0808805c @ =0x083a9f18
    ldr r1, lbl_08088060 @ =0x0600c800
    bl LZ77UncompVRAM
    ldr r0, lbl_08088064 @ =0x083b557c
    ldr r1, lbl_08088068 @ =0x0600a000
    bl LZ77UncompVRAM
    ldr r0, lbl_0808806c @ =0x083b5168
    ldr r1, lbl_08088070 @ =0x0600a800
    bl LZ77UncompVRAM
    ldr r0, lbl_08088074 @ =0x083b4768
    ldr r1, lbl_08088078 @ =0x0600b000
    bl LZ77UncompVRAM
    ldr r2, lbl_0808807c @ =0x040000d4
    ldr r0, lbl_08088080 @ =0x083a0af4
    str r0, [r2]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r2, #4]
    ldr r0, lbl_08088084 @ =0x800000d0
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r0, lbl_08088088 @ =0x083a0c94
    str r0, [r2]
    ldr r0, lbl_0808808c @ =0x05000200
    str r0, [r2, #4]
    ldr r0, lbl_08088090 @ =0x80000050
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_08088094 @ =0x04000008
    ldr r3, lbl_08088098 @ =0x00001408
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_0808809c @ =0x00001509
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_080880a0 @ =0x00009602
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_080880a4 @ =0x030013b4
    strh r5, [r0]
    ldr r0, lbl_080880a8 @ =0x030013b6
    movs r1, #0x60
    strh r1, [r0]
    ldr r0, lbl_080880ac @ =0x030013b8
    strh r5, [r0]
    ldr r0, lbl_080880b0 @ =0x030013ba
    strh r1, [r0]
    ldr r0, lbl_080880b4 @ =0x030013bc
    strh r5, [r0]
    ldr r0, lbl_080880b8 @ =0x030013be
    movs r3, #0xa8
    strh r3, [r0]
    ldr r0, lbl_080880bc @ =0x030013c0
    strh r5, [r0]
    ldr r0, lbl_080880c0 @ =0x030013c2
    strh r5, [r0]
    ldr r0, lbl_080880c4 @ =0x04000010
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r1, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r3, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    movs r0, #0
    str r0, [sp]
    mov r0, sp
    str r0, [r2]
    ldr r0, lbl_080880c8 @ =0x030016c4
    str r0, [r2, #4]
    ldr r0, lbl_080880cc @ =0x8500018a
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r0, lbl_080880d0 @ =0x03001382
    strb r5, [r0]
    ldr r4, lbl_080880d4 @ =0x08754bc4
    ldr r1, [r4]
    ldr r0, lbl_080880d8 @ =0x085c9bb6
    str r0, [r1, #0xc]
    movs r3, #0x78
    strh r3, [r1, #0x2a]
    movs r0, #0x63
    strh r0, [r1, #0x34]
    adds r2, r1, #0
    adds r2, #0x4e
    movs r0, #8
    strh r0, [r2]
    adds r2, #0x14
    movs r0, #0x20
    strh r0, [r2]
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldr r1, [r4]
    ldr r0, lbl_080880dc @ =0x085c9bd8
    str r0, [r1, #0x10]
    strh r3, [r1, #0x2c]
    movs r2, #0x54
    strh r2, [r1, #0x36]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    ldr r1, lbl_080880e0 @ =0x085c9b78
    str r1, [r0, #0x14]
    strh r3, [r0, #0x2e]
    strh r2, [r0, #0x38]
    bl chozodia_escape_process_oam2
    bl ResetFreeOAM
    ldr r0, lbl_080880e4 @ =0x085c9958
    ldr r1, [r4]
    movs r2, #0xdd
    lsls r2, r2, #2
    adds r1, r1, r2
    movs r2, #0
    bl ApplyMonochromeToPalette
    ldr r2, lbl_080880e8 @ =0x03001604
    strb r5, [r2]
    ldr r3, lbl_080880ec @ =0x03000014
    ldrh r0, [r3]
    cmp r0, #0
    bne lbl_08087fbc
    movs r0, #0x80
    strb r0, [r2]
lbl_08087fbc:
    ldr r0, lbl_080880f0 @ =0x0300002c
    ldrb r1, [r0]
    adds r6, r0, #0
    cmp r1, #2
    bne lbl_08087fd8
    ldrb r1, [r3, #4]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_08087fd8
    ldrb r0, [r2]
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_08087fd8:
    ldr r5, lbl_080880ec @ =0x03000014
    movs r4, #1
    adds r0, r4, #0
    ldrb r6, [r6]
    lsls r0, r6
    ldrb r1, [r5, #4]
    orrs r0, r1
    strb r0, [r5, #4]
    bl sub_0807f3fc
    bl GetPercentAndEndingNumber
    movs r1, #0xf
    ands r1, r0
    lsls r4, r1
    ldrh r0, [r5]
    orrs r4, r0
    strh r4, [r5]
    ldr r0, lbl_080880f4 @ =0x0300002e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0808801a
    ldr r0, lbl_080880f8 @ =0x03001694
    ldrb r0, [r0, #0x14]
    cmp r0, #0x64
    bls lbl_08088016
    ldr r0, lbl_080880e8 @ =0x03001604
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_08088016:
    bl check_set_new_time_attack_record
lbl_0808801a:
    bl sub_08073300
    ldr r0, lbl_080880fc @ =0x03000028
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08088104
    ldr r1, lbl_08088100 @ =0x03000043
    movs r0, #0
    b lbl_08088108
    .align 2, 0
lbl_0808802c: .4byte 0x04000208
lbl_08088030: .4byte 0x04000004
lbl_08088034: .4byte 0x0000ffef
lbl_08088038: .4byte 0x04000200
lbl_0808803c: .4byte 0x0000fffd
lbl_08088040: .4byte 0x04000202
lbl_08088044: .4byte vblank_during_chozodia_escape
lbl_08088048: .4byte 0x083ab6c0
lbl_0808804c: .4byte 0x06010000
lbl_08088050: .4byte 0x083a4878
lbl_08088054: .4byte 0x083a97a4
lbl_08088058: .4byte 0x06008000
lbl_0808805c: .4byte 0x083a9f18
lbl_08088060: .4byte 0x0600c800
lbl_08088064: .4byte 0x083b557c
lbl_08088068: .4byte 0x0600a000
lbl_0808806c: .4byte 0x083b5168
lbl_08088070: .4byte 0x0600a800
lbl_08088074: .4byte 0x083b4768
lbl_08088078: .4byte 0x0600b000
lbl_0808807c: .4byte 0x040000d4
lbl_08088080: .4byte 0x083a0af4
lbl_08088084: .4byte 0x800000d0
lbl_08088088: .4byte 0x083a0c94
lbl_0808808c: .4byte 0x05000200
lbl_08088090: .4byte 0x80000050
lbl_08088094: .4byte 0x04000008
lbl_08088098: .4byte 0x00001408
lbl_0808809c: .4byte 0x00001509
lbl_080880a0: .4byte 0x00009602
lbl_080880a4: .4byte 0x030013b4
lbl_080880a8: .4byte 0x030013b6
lbl_080880ac: .4byte 0x030013b8
lbl_080880b0: .4byte 0x030013ba
lbl_080880b4: .4byte 0x030013bc
lbl_080880b8: .4byte 0x030013be
lbl_080880bc: .4byte 0x030013c0
lbl_080880c0: .4byte 0x030013c2
lbl_080880c4: .4byte 0x04000010
lbl_080880c8: .4byte 0x030016c4
lbl_080880cc: .4byte 0x8500018a
lbl_080880d0: .4byte 0x03001382
lbl_080880d4: .4byte 0x08754bc4
lbl_080880d8: .4byte 0x085c9bb6
lbl_080880dc: .4byte 0x085c9bd8
lbl_080880e0: .4byte 0x085c9b78
lbl_080880e4: .4byte 0x085c9958
lbl_080880e8: .4byte 0x03001604
lbl_080880ec: .4byte 0x03000014
lbl_080880f0: .4byte 0x0300002c
lbl_080880f4: .4byte 0x0300002e
lbl_080880f8: .4byte 0x03001694
lbl_080880fc: .4byte 0x03000028
lbl_08088100: .4byte 0x03000043
lbl_08088104:
    ldr r1, lbl_08088140 @ =0x03000043
    movs r0, #1
lbl_08088108:
    strb r0, [r1]
    ldr r0, lbl_08088144 @ =0x08754bc4
    ldr r1, [r0]
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r2, r1, r3
    movs r3, #0
    movs r0, #0xb8
    lsls r0, r0, #5
    strh r0, [r2]
    ldr r0, lbl_08088148 @ =0x00000372
    adds r1, r1, r0
    movs r0, #0xff
    strh r0, [r1]
    ldr r0, lbl_0808814c @ =0x030013b0
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08088150 @ =0x030013b2
    strh r3, [r0]
    ldr r0, lbl_08088154 @ =0x030013ae
    strh r1, [r0]
    bl vblank_during_chozodia_escape
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08088140: .4byte 0x03000043
lbl_08088144: .4byte 0x08754bc4
lbl_08088148: .4byte 0x00000372
lbl_0808814c: .4byte 0x030013b0
lbl_08088150: .4byte 0x030013b2
lbl_08088154: .4byte 0x030013ae

    thumb_func_start chozodia_escape_escape_ship_leaving
chozodia_escape_escape_ship_leaving: @ 0x08088158
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r3, lbl_08088178 @ =0x08754bc4
    ldr r2, [r3]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0xa0
    beq lbl_08088198
    cmp r1, #0xa0
    bgt lbl_0808817c
    cmp r1, #0
    beq lbl_0808818c
    b lbl_080881d6
    .align 2, 0
lbl_08088178: .4byte 0x08754bc4
lbl_0808817c:
    movs r0, #0x93
    lsls r0, r0, #1
    cmp r1, r0
    beq lbl_080881ac
    adds r0, #0x12
    cmp r1, r0
    beq lbl_080881d4
    b lbl_080881d6
lbl_0808818c:
    ldr r0, lbl_08088194 @ =0x00000255
    bl SoundPlay
    b lbl_080881d6
    .align 2, 0
lbl_08088194: .4byte 0x00000255
lbl_08088198:
    ldrb r0, [r2, #6]
    adds r0, #1
    strb r0, [r2, #6]
    ldr r0, lbl_080881a8 @ =0x00000256
    bl SoundPlay
    b lbl_080881d6
    .align 2, 0
lbl_080881a8: .4byte 0x00000256
lbl_080881ac:
    movs r0, #2
    strb r0, [r2, #6]
    ldr r1, [r3]
    ldr r0, lbl_080881cc @ =0x085c9bc4
    str r0, [r1, #0xc]
    movs r0, #0xb8
    strh r0, [r1, #0x34]
    adds r2, r1, #0
    adds r2, #0x4e
    ldr r0, lbl_080881d0 @ =0x0000fff0
    strh r0, [r2]
    adds r1, #0x62
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r1]
    b lbl_080881d6
    .align 2, 0
lbl_080881cc: .4byte 0x085c9bc4
lbl_080881d0: .4byte 0x0000fff0
lbl_080881d4:
    movs r6, #1
lbl_080881d6:
    ldr r0, lbl_08088200 @ =0x08754bc4
    ldr r2, [r0]
    ldrb r3, [r2, #6]
    adds r5, r0, #0
    cmp r3, #1
    bne lbl_0808822a
    adds r1, r2, #0
    adds r1, #0x62
    ldrh r0, [r1]
    adds r0, #5
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_08088204
    ldrh r1, [r2, #4]
    movs r0, #7
    b lbl_0808820c
    .align 2, 0
lbl_08088200: .4byte 0x08754bc4
lbl_08088204:
    cmp r1, #0x38
    bls lbl_0808821c
    ldrh r1, [r2, #4]
    movs r0, #3
lbl_0808820c:
    ands r0, r1
    cmp r0, #0
    bne lbl_0808821c
    adds r1, r2, #0
    adds r1, #0x4e
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0808821c:
    ldr r1, [r5]
    ldrh r0, [r1, #0x34]
    cmp r0, #0xb0
    bls lbl_08088240
    movs r0, #0
    strb r0, [r1, #6]
    b lbl_08088240
lbl_0808822a:
    cmp r3, #2
    bne lbl_08088240
    adds r1, r2, #0
    adds r1, #0x62
    ldrh r0, [r1]
    adds r0, #0x10
    strh r0, [r1]
    subs r1, #0x14
    ldrh r0, [r1]
    subs r0, #8
    strh r0, [r1]
lbl_08088240:
    ldr r1, [r5]
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0808826a
    adds r0, r1, #0
    adds r0, #0x4e
    movs r2, #0
    ldrsh r3, [r0, r2]
    adds r2, r1, #0
    adds r2, #0x62
    ldrh r0, [r2]
    movs r1, #0x80
    lsls r1, r1, #2
    cmp r0, r1
    bls lbl_08088260
    strh r1, [r2]
lbl_08088260:
    ldr r1, [r5]
    asrs r0, r3, #3
    ldrh r2, [r1, #0x34]
    adds r0, r0, r2
    strh r0, [r1, #0x34]
lbl_0808826a:
    ldr r2, [r5]
    ldrb r0, [r2, #7]
    cmp r0, #1
    bne lbl_080882cc
    adds r2, #0x26
    ldrb r1, [r2]
    adds r0, r1, #1
    strb r0, [r2]
    ldr r2, lbl_080882d8 @ =0x085c9ef4
    ldr r0, [r5]
    adds r4, r0, #0
    adds r4, #0x21
    ldrb r3, [r4]
    lsls r0, r3, #3
    adds r0, r0, r2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r0, [r0, #4]
    cmp r1, r0
    blo lbl_080882bc
    adds r0, r3, #1
    movs r1, #0
    strb r0, [r4]
    ldr r0, [r5]
    adds r0, #0x26
    strb r1, [r0]
    ldr r0, [r5]
    adds r3, r0, #0
    adds r3, #0x21
    ldrb r1, [r3]
    lsls r0, r1, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080882bc
    subs r0, r1, #1
    strb r0, [r3]
    ldr r1, [r5]
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
lbl_080882bc:
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x21
    ldrb r1, [r1]
    lsls r1, r1, #3
    adds r1, r1, r2
    ldr r1, [r1]
    str r1, [r0, #0x10]
lbl_080882cc:
    bl chozodia_escape_process_oam2
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080882d8: .4byte 0x085c9ef4

    thumb_func_start chozodia_escape_mother_ship_heating_up
chozodia_escape_mother_ship_heating_up: @ 0x080882dc
    push {r4, r5, lr}
    movs r5, #0
    ldr r3, lbl_080882fc @ =0x08754bc4
    ldr r2, [r3]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x98
    beq lbl_08088320
    cmp r0, #0x98
    bgt lbl_08088300
    cmp r0, #0
    beq lbl_0808830a
    b lbl_08088378
    .align 2, 0
lbl_080882fc: .4byte 0x08754bc4
lbl_08088300:
    cmp r0, #0xa0
    beq lbl_08088334
    cmp r0, #0xe0
    beq lbl_08088354
    b lbl_08088378
lbl_0808830a:
    movs r0, #1
    strb r0, [r2, #7]
    ldr r1, [r3]
    strb r0, [r1, #8]
    ldr r0, lbl_0808831c @ =0x00000257
    bl SoundPlay
    b lbl_08088378
    .align 2, 0
lbl_0808831c: .4byte 0x00000257
lbl_08088320:
    bl sub_08087974
    bl sub_080879a8
    ldr r1, lbl_08088330 @ =0x030013ae
    movs r0, #8
    strh r0, [r1]
    b lbl_08088378
    .align 2, 0
lbl_08088330: .4byte 0x030013ae
lbl_08088334:
    ldr r0, lbl_0808834c @ =0x00000372
    adds r1, r2, r0
    movs r0, #0xbf
    strh r0, [r1]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    ldr r0, lbl_08088350 @ =0x0000028b
    bl SoundPlay
    b lbl_08088378
    .align 2, 0
lbl_0808834c: .4byte 0x00000372
lbl_08088350: .4byte 0x0000028b
lbl_08088354:
    ldr r3, lbl_0808842c @ =0x04000208
    strh r5, [r3]
    ldr r2, lbl_08088430 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_08088434 @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_08088438 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_0808843c @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08088440 @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r0, #1
    strh r0, [r3]
    movs r5, #1
lbl_08088378:
    bl sub_08087a0c
    ldr r3, lbl_08088444 @ =0x08754bc4
    ldr r2, [r3]
    ldrb r0, [r2, #1]
    cmp r0, #0
    beq lbl_080883c2
    ldrb r0, [r2, #2]
    adds r1, r0, #1
    strb r1, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_080883a6
    ldr r1, lbl_08088448 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_080883a0
    adds r0, #1
    strh r0, [r1]
lbl_080883a0:
    ldr r1, [r3]
    movs r0, #0
    strb r0, [r1, #2]
lbl_080883a6:
    ldr r0, lbl_08088444 @ =0x08754bc4
    ldr r0, [r0]
    movs r2, #0xdb
    lsls r2, r2, #2
    adds r1, r0, r2
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xa0
    bls lbl_080883c2
    movs r0, #0xa0
    strh r0, [r1]
lbl_080883c2:
    ldr r4, lbl_08088444 @ =0x08754bc4
    ldr r0, [r4]
    ldrh r0, [r0, #4]
    lsls r1, r0, #0x10
    lsrs r0, r1, #0x10
    cmp r0, #0x7e
    bhi lbl_080883fa
    lsrs r2, r1, #0x14
    ldr r0, lbl_0808844c @ =0x085ca0bc
    adds r0, r2, r0
    ldrb r2, [r0]
    lsls r2, r2, #1
    ldr r1, lbl_08088450 @ =0x085c9638
    adds r1, r2, r1
    ldr r0, lbl_08088454 @ =0x085c9738
    adds r2, r2, r0
    ldr r0, lbl_08088458 @ =0x040000d4
    str r1, [r0]
    ldr r1, lbl_0808845c @ =0x05000200
    str r1, [r0, #4]
    ldr r3, lbl_08088460 @ =0x80000010
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    str r2, [r0]
    ldr r1, lbl_08088464 @ =0x05000280
    str r1, [r0, #4]
    str r3, [r0, #8]
    ldr r0, [r0, #8]
lbl_080883fa:
    ldr r1, [r4]
    ldrh r3, [r1, #4]
    adds r0, r3, #0
    cmp r0, #0x80
    bls lbl_08088468
    movs r2, #3
    ands r2, r3
    cmp r2, #1
    bne lbl_08088418
    ldrh r0, [r1, #0x36]
    subs r0, #1
    strh r0, [r1, #0x36]
    ldrh r0, [r1, #0x38]
    subs r0, #1
    strh r0, [r1, #0x38]
lbl_08088418:
    cmp r2, #3
    bne lbl_080884fa
    ldr r0, [r4]
    ldrh r1, [r0, #0x36]
    adds r1, #1
    strh r1, [r0, #0x36]
    ldrh r1, [r0, #0x38]
    adds r1, #1
    strh r1, [r0, #0x38]
    b lbl_080884fa
    .align 2, 0
lbl_0808842c: .4byte 0x04000208
lbl_08088430: .4byte 0x04000004
lbl_08088434: .4byte 0x0000ffef
lbl_08088438: .4byte 0x04000200
lbl_0808843c: .4byte 0x0000fffd
lbl_08088440: .4byte 0x04000202
lbl_08088444: .4byte 0x08754bc4
lbl_08088448: .4byte 0x030013ae
lbl_0808844c: .4byte 0x085ca0bc
lbl_08088450: .4byte 0x085c9638
lbl_08088454: .4byte 0x085c9738
lbl_08088458: .4byte 0x040000d4
lbl_0808845c: .4byte 0x05000200
lbl_08088460: .4byte 0x80000010
lbl_08088464: .4byte 0x05000280
lbl_08088468:
    cmp r0, #0x60
    bls lbl_080884ae
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08088482
    ldrh r0, [r1, #0x36]
    subs r0, #1
    strh r0, [r1, #0x36]
    ldrh r0, [r1, #0x38]
    subs r0, #1
    strh r0, [r1, #0x38]
lbl_08088482:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0808849a
    ldrh r0, [r1, #0x36]
    adds r0, #1
    strh r0, [r1, #0x36]
    ldrh r0, [r1, #0x38]
    adds r0, #1
    strh r0, [r1, #0x38]
lbl_0808849a:
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #7
    bls lbl_080884fa
    b lbl_080884f2
lbl_080884ae:
    cmp r0, #0x30
    bls lbl_080884fa
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_080884c8
    ldrh r0, [r1, #0x36]
    subs r0, #1
    strh r0, [r1, #0x36]
    ldrh r0, [r1, #0x38]
    subs r0, #1
    strh r0, [r1, #0x38]
lbl_080884c8:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #6
    bne lbl_080884e0
    ldrh r0, [r1, #0x36]
    adds r0, #1
    strh r0, [r1, #0x36]
    ldrh r0, [r1, #0x38]
    adds r0, #1
    strh r0, [r1, #0x38]
lbl_080884e0:
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #9
    bls lbl_080884fa
lbl_080884f2:
    ldr r0, [r4]
    adds r0, #0x26
    movs r1, #0
    strb r1, [r0]
lbl_080884fa:
    bl chozodia_escape_process_oam
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start chozodia_escape_mother_ship_blowing_up
chozodia_escape_mother_ship_blowing_up: @ 0x08088508
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    str r0, [sp]
    ldr r4, lbl_08088540 @ =0x08754bc4
    ldr r2, [r4]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0x20
    bne lbl_0808852c
    b lbl_08088674
lbl_0808852c:
    cmp r1, #0x20
    bgt lbl_0808854e
    cmp r1, #1
    beq lbl_0808858c
    cmp r1, #1
    bgt lbl_08088544
    cmp r1, #0
    beq lbl_0808857a
    b lbl_0808870a
    .align 2, 0
lbl_08088540: .4byte 0x08754bc4
lbl_08088544:
    cmp r1, #2
    beq lbl_080885a0
    cmp r1, #3
    beq lbl_080885b4
    b lbl_0808870a
lbl_0808854e:
    cmp r1, #0xb0
    bne lbl_08088554
    b lbl_080886b4
lbl_08088554:
    cmp r1, #0xb0
    bgt lbl_08088566
    cmp r1, #0x40
    bne lbl_0808855e
    b lbl_08088682
lbl_0808855e:
    cmp r1, #0x4c
    bne lbl_08088564
    b lbl_0808869c
lbl_08088564:
    b lbl_0808870a
lbl_08088566:
    movs r0, #0x90
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08088570
    b lbl_080886f8
lbl_08088570:
    adds r0, #0x10
    cmp r1, r0
    bne lbl_08088578
    b lbl_08088706
lbl_08088578:
    b lbl_0808870a
lbl_0808857a:
    ldr r0, lbl_08088588 @ =0x085ca118
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    b lbl_0808870a
    .align 2, 0
lbl_08088588: .4byte 0x085ca118
lbl_0808858c:
    ldr r0, lbl_08088598 @ =0x0847d014
    ldr r1, lbl_0808859c @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_0808870a
    .align 2, 0
lbl_08088598: .4byte 0x0847d014
lbl_0808859c: .4byte 0x06008000
lbl_080885a0:
    ldr r0, lbl_080885ac @ =0x08480148
    ldr r1, lbl_080885b0 @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_0808870a
    .align 2, 0
lbl_080885ac: .4byte 0x08480148
lbl_080885b0: .4byte 0x06010000
lbl_080885b4:
    ldr r0, lbl_08088638 @ =0x085cf2c4
    ldr r1, lbl_0808863c @ =0x0600e800
    bl LZ77UncompVRAM
    ldr r0, lbl_08088640 @ =0x0847f884
    ldr r1, lbl_08088644 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r1, lbl_08088648 @ =0x040000d4
    ldr r0, lbl_0808864c @ =0x085c9838
    str r0, [r1]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08088650 @ =0x80000070
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08088654 @ =0x08479520
    str r0, [r1]
    ldr r0, lbl_08088658 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_0808865c @ =0x80000060
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xcc
    ldr r2, lbl_08088660 @ =0x00001e08
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08088664 @ =0x00001d01
    adds r0, r3, #0
    strh r0, [r1]
    ldr r2, [r4]
    movs r0, #0xdc
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r0, #0x98
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r3, lbl_08088668 @ =0x00000372
    adds r1, r2, r3
    ldr r0, lbl_0808866c @ =0x00000241
    strh r0, [r1]
    ldr r0, lbl_08088670 @ =0x030013ae
    mov r1, sp
    ldrh r1, [r1]
    strh r1, [r0]
    ldrb r0, [r2, #6]
    adds r0, #1
    strb r0, [r2, #6]
    ldr r1, [r4]
    movs r3, #0x78
    strh r3, [r1, #0x2a]
    movs r2, #0x50
    strh r2, [r1, #0x34]
    ldrb r0, [r1, #9]
    adds r0, #1
    strb r0, [r1, #9]
    ldr r0, [r4]
    strh r3, [r0, #0x30]
    strh r2, [r0, #0x3a]
    movs r0, #0xa3
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0808870a
    .align 2, 0
lbl_08088638: .4byte 0x085cf2c4
lbl_0808863c: .4byte 0x0600e800
lbl_08088640: .4byte 0x0847f884
lbl_08088644: .4byte 0x0600f000
lbl_08088648: .4byte 0x040000d4
lbl_0808864c: .4byte 0x085c9838
lbl_08088650: .4byte 0x80000070
lbl_08088654: .4byte 0x08479520
lbl_08088658: .4byte 0x05000200
lbl_0808865c: .4byte 0x80000060
lbl_08088660: .4byte 0x00001e08
lbl_08088664: .4byte 0x00001d01
lbl_08088668: .4byte 0x00000372
lbl_0808866c: .4byte 0x00000241
lbl_08088670: .4byte 0x030013ae
lbl_08088674:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    movs r0, #0xf0
    bl FadeMusic
    b lbl_0808870a
lbl_08088682:
    ldrb r0, [r2, #7]
    adds r0, #1
    strb r0, [r2, #7]
    ldr r2, [r4]
    ldr r1, lbl_08088698 @ =0x085ca0d8
    ldrh r0, [r1]
    strh r0, [r2, #0x2c]
    ldrh r0, [r1, #2]
    strh r0, [r2, #0x36]
    b lbl_0808870a
    .align 2, 0
lbl_08088698: .4byte 0x085ca0d8
lbl_0808869c:
    ldrb r0, [r2, #8]
    adds r0, #1
    strb r0, [r2, #8]
    ldr r2, [r4]
    ldr r1, lbl_080886b0 @ =0x085ca0f8
    ldrh r0, [r1]
    strh r0, [r2, #0x2e]
    ldrh r0, [r1, #2]
    strh r0, [r2, #0x38]
    b lbl_0808870a
    .align 2, 0
lbl_080886b0: .4byte 0x085ca0f8
lbl_080886b4:
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r1, r2, r3
    movs r0, #0x90
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r0, lbl_080886e8 @ =0x00000372
    adds r1, r2, r0
    movs r0, #0xff
    strh r0, [r1]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    ldr r1, lbl_080886ec @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_080886f0 @ =0x030013b2
    mov r1, sp
    ldrh r1, [r1]
    strh r1, [r0]
    ldr r0, lbl_080886f4 @ =0x030013ae
    mov r2, sp
    ldrh r2, [r2]
    strh r2, [r0]
    b lbl_0808870a
    .align 2, 0
lbl_080886e8: .4byte 0x00000372
lbl_080886ec: .4byte 0x030013b0
lbl_080886f0: .4byte 0x030013b2
lbl_080886f4: .4byte 0x030013ae
lbl_080886f8:
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r0, r2, r3
    mov r1, sp
    ldrh r1, [r1]
    strh r1, [r0]
    b lbl_0808870a
lbl_08088706:
    movs r2, #1
    str r2, [sp]
lbl_0808870a:
    ldr r0, lbl_080887c8 @ =0x08754bc4
    ldr r3, [r0]
    ldrb r1, [r3, #1]
    adds r5, r0, #0
    cmp r1, #1
    bne lbl_08088740
    ldrb r0, [r3, #2]
    adds r1, r0, #1
    strb r1, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bls lbl_08088740
    ldr r1, lbl_080887cc @ =0x030013b0
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08088730
    subs r0, #1
    strh r0, [r1]
lbl_08088730:
    ldr r2, lbl_080887d0 @ =0x030013b2
    ldrh r1, [r1]
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    ldr r1, [r5]
    movs r0, #0
    strb r0, [r1, #2]
lbl_08088740:
    ldr r2, [r5]
    ldrb r0, [r2, #1]
    cmp r0, #2
    bne lbl_08088768
    ldrb r0, [r2, #2]
    adds r1, r0, #1
    strb r1, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_08088768
    ldr r1, lbl_080887d4 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08088762
    adds r0, #1
    strh r0, [r1]
lbl_08088762:
    ldr r1, [r5]
    movs r0, #0
    strb r0, [r1, #2]
lbl_08088768:
    ldr r2, [r5]
    ldrh r1, [r2, #4]
    movs r0, #3
    ands r0, r1
    adds r3, r0, #0
    cmp r3, #0
    bne lbl_08088784
    ldr r0, lbl_080887d8 @ =0x030013ba
    ldrh r1, [r0]
    subs r1, #1
    strh r1, [r0]
    ldrh r0, [r2, #0x3a]
    adds r0, #1
    strh r0, [r2, #0x3a]
lbl_08088784:
    cmp r3, #2
    bne lbl_08088798
    ldr r1, lbl_080887d8 @ =0x030013ba
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r1, #0x3a]
    subs r0, #1
    strh r0, [r1, #0x3a]
lbl_08088798:
    movs r4, #0
    ldr r3, lbl_080887dc @ =0x085ca0c4
    mov r8, r3
    ldr r0, lbl_080887e0 @ =0x085ca0f8
    mov sl, r0
    ldr r1, lbl_080887e4 @ =0x085ca0d8
    mov sb, r1
lbl_080887a6:
    ldr r1, [r5]
    adds r0, r1, #6
    adds r0, r0, r4
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080887b4
    b lbl_080888ce
lbl_080887b4:
    cmp r4, #0
    bne lbl_080887e8
    ldrb r0, [r1, #6]
    cmp r0, #1
    bls lbl_080887e8
    mov r2, r8
    ldr r6, [r2, #0x10]
    movs r7, #0
    b lbl_080887f2
    .align 2, 0
lbl_080887c8: .4byte 0x08754bc4
lbl_080887cc: .4byte 0x030013b0
lbl_080887d0: .4byte 0x030013b2
lbl_080887d4: .4byte 0x030013ae
lbl_080887d8: .4byte 0x030013ba
lbl_080887dc: .4byte 0x085ca0c4
lbl_080887e0: .4byte 0x085ca0f8
lbl_080887e4: .4byte 0x085ca0d8
lbl_080887e8:
    lsls r1, r4, #2
    mov r3, r8
    adds r0, r1, r3
    ldr r6, [r0]
    adds r7, r1, #0
lbl_080887f2:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x20
    adds r0, r0, r4
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r3, r6, r0
    adds r2, #0x25
    adds r2, r2, r4
    ldrb r0, [r2]
    adds r1, r0, #1
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r3, #4]
    cmp r0, r1
    blo lbl_080888c4
    ldr r1, [r5]
    adds r1, #0x20
    adds r1, r1, r4
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r0, #0x25
    adds r0, r0, r4
    strb r2, [r0]
    adds r3, #8
    ldrb r1, [r3, #4]
    cmp r1, #0
    bne lbl_080888c4
    cmp r4, #0
    bne lbl_08088844
    ldr r1, [r5]
    movs r0, #2
    strb r0, [r1, #6]
    ldr r0, [r5]
    adds r0, #0x20
    strb r4, [r0]
    b lbl_080888c2
lbl_08088844:
    cmp r4, #3
    bne lbl_08088854
    ldr r1, [r5]
    adds r1, #0x23
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    b lbl_080888c2
lbl_08088854:
    ldr r0, [r5]
    adds r0, #0x20
    adds r0, r0, r4
    strb r1, [r0]
    ldr r2, [r5]
    adds r2, #0x3e
    adds r2, r2, r4
    ldrb r0, [r2]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r2]
    cmp r4, #2
    bne lbl_08088894
    ldr r1, [r5]
    adds r2, r1, #0
    adds r2, #0x40
    ldrb r0, [r2]
    lsls r0, r0, #2
    add r0, sl
    ldrh r0, [r0]
    strh r0, [r1, #0x2e]
    ldrb r0, [r2]
    lsls r0, r0, #2
    ldr r2, lbl_08088890 @ =0x085ca0fa
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1, #0x38]
    b lbl_080888c2
    .align 2, 0
lbl_08088890: .4byte 0x085ca0fa
lbl_08088894:
    ldr r3, [r5]
    mov ip, r3
    lsls r3, r4, #1
    mov r1, ip
    adds r1, #0x2a
    adds r1, r1, r3
    mov r2, ip
    adds r2, #0x3e
    adds r2, r2, r4
    ldrb r0, [r2]
    lsls r0, r0, #2
    add r0, sb
    ldrh r0, [r0]
    strh r0, [r1]
    mov r1, ip
    adds r1, #0x34
    adds r1, r1, r3
    ldrb r0, [r2]
    lsls r0, r0, #2
    ldr r2, lbl_080888f0 @ =0x085ca0da
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
lbl_080888c2:
    adds r3, r6, #0
lbl_080888c4:
    ldr r0, [r5]
    adds r0, #0xc
    adds r0, r0, r7
    ldr r1, [r3]
    str r1, [r0]
lbl_080888ce:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bhi lbl_080888da
    b lbl_080887a6
lbl_080888da:
    bl chozodia_escape_process_oam
    ldr r0, [sp]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080888f0: .4byte 0x085ca0da

    thumb_func_start chozodia_escape_escape_ship_leaving_planet
chozodia_escape_escape_ship_leaving_planet: @ 0x080888f4
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_0808891c @ =0x08754bc4
    ldr r2, [r4]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #3
    beq lbl_08088984
    cmp r1, #3
    bgt lbl_08088920
    cmp r1, #1
    beq lbl_0808895c
    cmp r1, #1
    bgt lbl_08088970
    cmp r1, #0
    beq lbl_08088942
    b lbl_08088aae
    .align 2, 0
lbl_0808891c: .4byte 0x08754bc4
lbl_08088920:
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_0808892a
    b lbl_08088a5c
lbl_0808892a:
    cmp r1, r0
    bgt lbl_08088936
    cmp r1, #0xe0
    bne lbl_08088934
    b lbl_08088a58
lbl_08088934:
    b lbl_08088aae
lbl_08088936:
    movs r0, #0x8c
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08088940
    b lbl_08088aa0
lbl_08088940:
    b lbl_08088aae
lbl_08088942:
    ldr r0, lbl_08088958 @ =0x085d0ce8
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl LZ77UncompVRAM
    movs r0, #0x1a
    movs r1, #0
    bl PlayMusic
    b lbl_08088aae
    .align 2, 0
lbl_08088958: .4byte 0x085d0ce8
lbl_0808895c:
    ldr r0, lbl_08088968 @ =0x085d5ae8
    ldr r1, lbl_0808896c @ =0x06008000
    bl LZ77UncompVRAM
    b lbl_08088aae
    .align 2, 0
lbl_08088968: .4byte 0x085d5ae8
lbl_0808896c: .4byte 0x06008000
lbl_08088970:
    ldr r0, lbl_0808897c @ =0x085cf94c
    ldr r1, lbl_08088980 @ =0x06010000
    bl LZ77UncompVRAM
    b lbl_08088aae
    .align 2, 0
lbl_0808897c: .4byte 0x085cf94c
lbl_08088980: .4byte 0x06010000
lbl_08088984:
    ldr r0, lbl_08088a14 @ =0x085d0a28
    ldr r1, lbl_08088a18 @ =0x0600e800
    bl LZ77UncompVRAM
    ldr r0, lbl_08088a1c @ =0x085d5460
    ldr r1, lbl_08088a20 @ =0x0600f000
    bl LZ77UncompVRAM
    ldr r0, lbl_08088a24 @ =0x085d8514
    ldr r1, lbl_08088a28 @ =0x0600f800
    bl LZ77UncompVRAM
    ldr r0, lbl_08088a2c @ =0x040000d4
    ldr r3, lbl_08088a30 @ =0x085c9958
    str r3, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    str r1, [r0, #4]
    ldr r2, lbl_08088a34 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_08088a38 @ =0x05000200
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    ldr r1, [r4]
    ldrb r0, [r1, #6]
    adds r0, #1
    strb r0, [r1, #6]
    ldr r2, [r4]
    ldr r0, lbl_08088a3c @ =0x085c9fe8
    str r0, [r2, #0xc]
    movs r0, #0x28
    strh r0, [r2, #0x2a]
    movs r0, #0x70
    strh r0, [r2, #0x34]
    adds r1, r2, #0
    adds r1, #0x44
    movs r0, #4
    strh r0, [r1]
    adds r1, #0xa
    ldr r0, lbl_08088a40 @ =0x0000fffb
    strh r0, [r1]
    ldrh r0, [r2, #0x2a]
    lsls r0, r0, #3
    strh r0, [r2, #0x2c]
    ldrh r0, [r2, #0x34]
    lsls r0, r0, #3
    strh r0, [r2, #0x36]
    ldr r1, lbl_08088a44 @ =0x04000008
    ldr r3, lbl_08088a48 @ =0x00001f08
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08088a4c @ =0x00001d01
    adds r0, r3, #0
    strh r0, [r1]
    adds r1, #2
    ldr r3, lbl_08088a50 @ =0x00001e02
    adds r0, r3, #0
    strh r0, [r1]
    movs r0, #0xdc
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r0, #0xb0
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r1, lbl_08088a54 @ =0x030013b8
    movs r0, #0x10
    strh r0, [r1]
    b lbl_08088aae
    .align 2, 0
lbl_08088a14: .4byte 0x085d0a28
lbl_08088a18: .4byte 0x0600e800
lbl_08088a1c: .4byte 0x085d5460
lbl_08088a20: .4byte 0x0600f000
lbl_08088a24: .4byte 0x085d8514
lbl_08088a28: .4byte 0x0600f800
lbl_08088a2c: .4byte 0x040000d4
lbl_08088a30: .4byte 0x085c9958
lbl_08088a34: .4byte 0x80000100
lbl_08088a38: .4byte 0x05000200
lbl_08088a3c: .4byte 0x085c9fe8
lbl_08088a40: .4byte 0x0000fffb
lbl_08088a44: .4byte 0x04000008
lbl_08088a48: .4byte 0x00001f08
lbl_08088a4c: .4byte 0x00001d01
lbl_08088a50: .4byte 0x00001e02
lbl_08088a54: .4byte 0x030013b8
lbl_08088a58:
    strb r5, [r2, #6]
    b lbl_08088aae
lbl_08088a5c:
    movs r0, #2
    strb r0, [r2, #6]
    ldr r0, [r4]
    ldr r1, lbl_08088a98 @ =0x085c9ff0
    str r1, [r0, #0xc]
    adds r0, #0x25
    strb r5, [r0]
    ldr r2, [r4]
    movs r0, #0x94
    lsls r0, r0, #1
    strh r0, [r2, #0x2a]
    movs r0, #0x26
    strh r0, [r2, #0x34]
    adds r1, r2, #0
    adds r1, #0x44
    ldr r0, lbl_08088a9c @ =0x0000ffd9
    strh r0, [r1]
    adds r1, #0xa
    movs r0, #6
    strh r0, [r1]
    adds r1, #0x14
    movs r0, #0xe8
    strh r0, [r1]
    ldrh r0, [r2, #0x2a]
    lsls r0, r0, #3
    strh r0, [r2, #0x2c]
    ldrh r0, [r2, #0x34]
    lsls r0, r0, #3
    strh r0, [r2, #0x36]
    b lbl_08088aae
    .align 2, 0
lbl_08088a98: .4byte 0x085c9ff0
lbl_08088a9c: .4byte 0x0000ffd9
lbl_08088aa0:
    movs r3, #0xdc
    lsls r3, r3, #2
    adds r1, r2, r3
    movs r0, #0xe0
    lsls r0, r0, #3
    strh r0, [r1]
    movs r5, #1
lbl_08088aae:
    ldr r0, lbl_08088ad4 @ =0x08754bc4
    ldr r2, [r0]
    ldrb r3, [r2, #1]
    adds r4, r0, #0
    cmp r3, #0
    bne lbl_08088ae0
    ldrh r1, [r2, #4]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08088ae0
    ldr r1, lbl_08088ad8 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08088adc
    subs r0, #1
    strh r0, [r1]
    b lbl_08088ae0
    .align 2, 0
lbl_08088ad4: .4byte 0x08754bc4
lbl_08088ad8: .4byte 0x030013ae
lbl_08088adc:
    adds r0, r3, #1
    strb r0, [r2, #1]
lbl_08088ae0:
    adds r3, r4, #0
    ldr r1, [r3]
    ldrb r0, [r1, #6]
    cmp r0, #1
    bne lbl_08088b5c
    ldrh r0, [r1, #4]
    cmp r0, #0x5f
    bhi lbl_08088b04
    adds r0, r1, #0
    adds r0, #0x25
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #0xd
    bls lbl_08088b28
    b lbl_08088b16
lbl_08088b04:
    adds r0, r1, #0
    adds r0, #0x25
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #1
    bls lbl_08088b28
lbl_08088b16:
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0x44
    ldrh r0, [r2]
    adds r0, #1
    movs r3, #0
    strh r0, [r2]
    adds r1, #0x25
    strb r3, [r1]
lbl_08088b28:
    ldr r0, lbl_08088b58 @ =0x08754bc4
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0x44
    ldrh r1, [r0]
    ldrh r0, [r2, #0x2c]
    adds r1, r1, r0
    strh r1, [r2, #0x2c]
    adds r0, r2, #0
    adds r0, #0x4e
    ldrh r0, [r0]
    ldrh r3, [r2, #0x36]
    adds r0, r0, r3
    strh r0, [r2, #0x36]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x13
    strh r1, [r2, #0x2a]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x13
    strh r0, [r2, #0x34]
    bl chozodia_escape_process_oam
    b lbl_08088bce
    .align 2, 0
lbl_08088b58: .4byte 0x08754bc4
lbl_08088b5c:
    cmp r0, #2
    bne lbl_08088bce
    adds r1, #0x25
    ldrb r2, [r1]
    adds r0, r2, #1
    strb r0, [r1]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    beq lbl_08088b8c
    ldr r3, [r3]
    adds r1, r3, #0
    adds r1, #0x44
    ldrh r0, [r1]
    subs r0, #1
    movs r2, #0
    strh r0, [r1]
    adds r1, #0xa
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x25
    strb r2, [r0]
lbl_08088b8c:
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0x44
    ldrh r1, [r0]
    ldrh r0, [r2, #0x2c]
    adds r1, r1, r0
    strh r1, [r2, #0x2c]
    adds r0, r2, #0
    adds r0, #0x4e
    ldrh r0, [r0]
    ldrh r3, [r2, #0x36]
    adds r0, r0, r3
    strh r0, [r2, #0x36]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x13
    strh r1, [r2, #0x2a]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x13
    strh r0, [r2, #0x34]
    adds r1, r2, #0
    adds r1, #0x62
    ldrh r0, [r1]
    adds r0, #0xc
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0x80
    lsls r2, r2, #2
    cmp r0, r2
    bls lbl_08088bca
    strh r2, [r1]
lbl_08088bca:
    bl chozodia_escape_process_oam2
lbl_08088bce:
    ldr r0, lbl_08088bf4 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r1, [r0, #4]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_08088bec
    ldr r1, lbl_08088bf8 @ =0x030013b8
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    ldr r1, lbl_08088bfc @ =0x030013bc
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08088bec:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08088bf4: .4byte 0x08754bc4
lbl_08088bf8: .4byte 0x030013b8
lbl_08088bfc: .4byte 0x030013bc

    thumb_func_start chozodia_escape_mission_accomplished
chozodia_escape_mission_accomplished: @ 0x08088c00
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r4, lbl_08088c24 @ =0x08754bc4
    ldr r2, [r4]
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0x30
    beq lbl_08088c78
    cmp r1, #0x30
    bgt lbl_08088c28
    cmp r1, #0
    beq lbl_08088c36
    b lbl_08088cee
    .align 2, 0
lbl_08088c24: .4byte 0x08754bc4
lbl_08088c28:
    cmp r1, #0x40
    beq lbl_08088c9a
    movs r0, #0xec
    lsls r0, r0, #1
    cmp r1, r0
    beq lbl_08088ce0
    b lbl_08088cee
lbl_08088c36:
    ldr r0, lbl_08088c60 @ =0x085d8ad4
    ldr r1, lbl_08088c64 @ =0x06010000
    bl LZ77UncompVRAM
    ldr r1, lbl_08088c68 @ =0x040000d4
    ldr r0, lbl_08088c6c @ =0x085c9b58
    str r0, [r1]
    ldr r0, lbl_08088c70 @ =0x05000200
    str r0, [r1, #4]
    ldr r0, lbl_08088c74 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, [r4]
    movs r1, #0xdc
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #0xb8
    lsls r1, r1, #5
    strh r1, [r0]
    b lbl_08088cee
    .align 2, 0
lbl_08088c60: .4byte 0x085d8ad4
lbl_08088c64: .4byte 0x06010000
lbl_08088c68: .4byte 0x040000d4
lbl_08088c6c: .4byte 0x085c9b58
lbl_08088c70: .4byte 0x05000200
lbl_08088c74: .4byte 0x80000010
lbl_08088c78:
    movs r0, #0xdd
    lsls r0, r0, #2
    adds r1, r2, r0
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, [r4]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_08088cee
lbl_08088c9a:
    ldrb r0, [r2, #0xa]
    adds r0, #1
    strb r0, [r2, #0xa]
    ldr r0, lbl_08088cb4 @ =0x03000020
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08088cbc
    ldr r1, [r4]
    ldr r0, lbl_08088cb8 @ =0x085ca084
    b lbl_08088cc0
    .align 2, 0
lbl_08088cb4: .4byte 0x03000020
lbl_08088cb8: .4byte 0x085ca084
lbl_08088cbc:
    ldr r1, [r4]
    ldr r0, lbl_08088cd8 @ =0x085ca00a
lbl_08088cc0:
    str r0, [r1, #0x1c]
    ldr r2, lbl_08088cdc @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x24
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r2]
    movs r0, #0x78
    strh r0, [r1, #0x32]
    movs r0, #0x58
    strh r0, [r1, #0x3c]
    b lbl_08088cee
    .align 2, 0
lbl_08088cd8: .4byte 0x085ca00a
lbl_08088cdc: .4byte 0x08754bc4
lbl_08088ce0:
    ldr r1, lbl_08088d4c @ =0x00000372
    adds r0, r2, r1
    movs r1, #0xff
    strh r1, [r0]
    ldr r0, lbl_08088d50 @ =0x030013ae
    strh r5, [r0]
    movs r5, #2
lbl_08088cee:
    ldr r3, lbl_08088d54 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_08088d22
    adds r0, r1, #0
    adds r0, #0x29
    ldrb r1, [r0]
    adds r2, r1, #1
    strb r2, [r0]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #3
    bls lbl_08088d22
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x2f
    bhi lbl_08088d1a
    adds r0, #1
    strb r0, [r1]
lbl_08088d1a:
    ldr r0, [r3]
    adds r0, #0x29
    movs r1, #0
    strb r1, [r0]
lbl_08088d22:
    bl chozodia_escape_process_oam
    ldr r0, lbl_08088d54 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #1]
    cmp r0, #0
    bne lbl_08088d42
    ldrh r1, [r1, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08088d42
    ldr r1, lbl_08088d58 @ =0x030013bc
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_08088d42:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08088d4c: .4byte 0x00000372
lbl_08088d50: .4byte 0x030013ae
lbl_08088d54: .4byte 0x08754bc4
lbl_08088d58: .4byte 0x030013bc

    thumb_func_start chozodia_escape_main
chozodia_escape_main: @ 0x08088d5c
    push {r4, r5, r6, lr}
    movs r5, #0
    ldr r0, lbl_08088d78 @ =0x03001382
    strb r5, [r0]
    ldr r4, lbl_08088d7c @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #1
    beq lbl_08088d92
    cmp r0, #1
    bgt lbl_08088d80
    cmp r0, #0
    beq lbl_08088d8c
    b lbl_08088e96
    .align 2, 0
lbl_08088d78: .4byte 0x03001382
lbl_08088d7c: .4byte 0x03000c72
lbl_08088d80:
    cmp r0, #2
    beq lbl_08088dc0
    cmp r0, #3
    bne lbl_08088d8a
    b lbl_08088e80
lbl_08088d8a:
    b lbl_08088e96
lbl_08088d8c:
    bl chozodia_escape_init
    b lbl_08088dae
lbl_08088d92:
    ldr r1, lbl_08088da0 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08088da4
    subs r0, #1
    strh r0, [r1]
    b lbl_08088e96
    .align 2, 0
lbl_08088da0: .4byte 0x030013ae
lbl_08088da4:
    ldr r0, lbl_08088db8 @ =0x08754bc4
    ldr r0, [r0]
    ldr r1, lbl_08088dbc @ =0x00000372
    adds r0, r0, r1
    strh r5, [r0]
lbl_08088dae:
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    b lbl_08088e96
    .align 2, 0
lbl_08088db8: .4byte 0x08754bc4
lbl_08088dbc: .4byte 0x00000372
lbl_08088dc0:
    ldr r1, lbl_08088e58 @ =0x08760d14
    ldr r4, lbl_08088e5c @ =0x08754bc4
    ldr r0, [r4]
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #1
    bne lbl_08088e40
    ldr r1, [r4]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r4]
    strb r5, [r0, #1]
    ldr r0, [r4]
    strb r5, [r0, #2]
    ldr r0, [r4]
    strh r5, [r0, #4]
    movs r1, #0
    adds r3, r4, #0
    movs r2, #0
lbl_08088df4:
    ldr r0, [r3]
    adds r0, #6
    adds r0, r0, r1
    strb r2, [r0]
    ldr r0, [r3]
    adds r0, #0x20
    adds r0, r0, r1
    strb r2, [r0]
    ldr r0, [r3]
    adds r0, #0x25
    adds r0, r0, r1
    strb r2, [r0]
    ldr r0, [r3]
    adds r0, #0x3e
    adds r0, r0, r1
    strb r2, [r0]
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #4
    bls lbl_08088df4
    ldr r0, [r4]
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_08088e40
    ldr r0, lbl_08088e60 @ =0x030013b4
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08088e64 @ =0x030013b6
    strh r1, [r0]
    ldr r0, lbl_08088e68 @ =0x030013b8
    strh r1, [r0]
    ldr r0, lbl_08088e6c @ =0x030013ba
    strh r1, [r0]
    ldr r0, lbl_08088e70 @ =0x030013bc
    strh r1, [r0]
    ldr r0, lbl_08088e74 @ =0x030013be
    strh r1, [r0]
lbl_08088e40:
    cmp r6, #2
    bne lbl_08088e52
    ldr r1, lbl_08088e78 @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r1, lbl_08088e7c @ =0x03000c74
    movs r0, #0
    strb r0, [r1]
lbl_08088e52:
    bl ResetFreeOAM
    b lbl_08088e96
    .align 2, 0
lbl_08088e58: .4byte 0x08760d14
lbl_08088e5c: .4byte 0x08754bc4
lbl_08088e60: .4byte 0x030013b4
lbl_08088e64: .4byte 0x030013b6
lbl_08088e68: .4byte 0x030013b8
lbl_08088e6c: .4byte 0x030013ba
lbl_08088e70: .4byte 0x030013bc
lbl_08088e74: .4byte 0x030013be
lbl_08088e78: .4byte 0x03000c72
lbl_08088e7c: .4byte 0x03000c74
lbl_08088e80:
    ldr r1, lbl_08088e90 @ =0x030013ae
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08088e94
    adds r0, #1
    strh r0, [r1]
    b lbl_08088e96
    .align 2, 0
lbl_08088e90: .4byte 0x030013ae
lbl_08088e94:
    movs r5, #1
lbl_08088e96:
    adds r0, r5, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08088ea0
sub_08088ea0: @ 0x08088ea0
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_08088ec0 @ =0x03005808
    movs r1, #0
    strb r1, [r0, #0xb]
    ldrb r1, [r0, #9]
    adds r2, r0, #0
    cmp r1, #0xc
    bls lbl_08088eb4
    b lbl_08089100
lbl_08088eb4:
    lsls r0, r1, #2
    ldr r1, lbl_08088ec4 @ =lbl_08088ec8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08088ec0: .4byte 0x03005808
lbl_08088ec4: .4byte lbl_08088ec8
lbl_08088ec8: @ jump table
    .4byte lbl_08088efc @ case 0
    .4byte lbl_08088f14 @ case 1
    .4byte lbl_08088f48 @ case 2
    .4byte lbl_08088f98 @ case 3
    .4byte lbl_08089058 @ case 4
    .4byte lbl_08089088 @ case 5
    .4byte lbl_080890ae @ case 6
    .4byte lbl_080890c8 @ case 7
    .4byte lbl_080890bc @ case 8
    .4byte lbl_080890d4 @ case 9
    .4byte lbl_080890e4 @ case 10
    .4byte lbl_080890ea @ case 11
    .4byte lbl_08089100 @ case 12
lbl_08088efc:
    ldr r4, lbl_08088f10 @ =0x03005808
    movs r0, #0
    strh r0, [r4, #6]
    movs r0, #0x14
    bl FadeMusic
    ldrb r0, [r4, #9]
    adds r0, #1
    b lbl_080890fe
    .align 2, 0
lbl_08088f10: .4byte 0x03005808
lbl_08088f14:
    ldr r4, lbl_08088f40 @ =0x03005808
    ldrh r0, [r4, #6]
    adds r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bhi lbl_08088f26
    b lbl_08089100
lbl_08088f26:
    bl sub_08003458
    ldr r0, lbl_08088f44 @ =0x03001d00
    ldrh r1, [r0, #0x1c]
    strh r1, [r4, #0x12]
    adds r0, #0x21
    ldrb r0, [r0]
    strh r0, [r4, #0x14]
    movs r0, #0
    strh r0, [r4, #6]
    ldrb r0, [r4, #9]
    adds r0, #1
    b lbl_080890fe
    .align 2, 0
lbl_08088f40: .4byte 0x03005808
lbl_08088f44: .4byte 0x03001d00
lbl_08088f48:
    ldr r0, lbl_08088f78 @ =serial_communication_code_connecting
    bl CallbackSetSerialCommunication
    ldr r0, lbl_08088f7c @ =sub_08089bd4
    bl CallbackSetTimer3
    ldr r0, lbl_08088f80 @ =0x0300586c
    ldr r1, lbl_08088f84 @ =0x08754bd0
    str r1, [r0]
    ldr r2, lbl_08088f88 @ =0x03005870
    ldr r0, lbl_08088f8c @ =0x087566c4
    subs r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_08088f90 @ =0x03005820
    str r1, [r0, #0x28]
    adds r1, r0, #0
    adds r1, #0x4b
    movs r4, #0
    strb r4, [r1]
    bl sub_08089164
    ldr r1, lbl_08088f94 @ =0x03005808
    strh r4, [r1, #6]
    b lbl_08089068
    .align 2, 0
lbl_08088f78: .4byte serial_communication_code_connecting
lbl_08088f7c: .4byte sub_08089bd4
lbl_08088f80: .4byte 0x0300586c
lbl_08088f84: .4byte 0x08754bd0
lbl_08088f88: .4byte 0x03005870
lbl_08088f8c: .4byte 0x087566c4
lbl_08088f90: .4byte 0x03005820
lbl_08088f94: .4byte 0x03005808
lbl_08088f98:
    ldr r3, lbl_08089004 @ =0x03005808
    ldrh r0, [r3, #6]
    adds r0, #1
    movs r4, #0
    strh r0, [r3, #6]
    ldr r2, lbl_08089008 @ =0x03005820
    ldrb r1, [r2, #0x1e]
    movs r0, #0xe
    ands r0, r1
    cmp r0, #0
    beq lbl_08088fbe
    ldrb r0, [r2, #0x18]
    cmp r0, #0xd1
    bne lbl_08088fb6
    strh r4, [r3, #6]
lbl_08088fb6:
    ldrb r0, [r2, #0x18]
    cmp r0, #0xdf
    bls lbl_08088fbe
    strh r4, [r3, #6]
lbl_08088fbe:
    ldr r3, lbl_08089008 @ =0x03005820
    ldrb r0, [r3, #0x18]
    cmp r0, #0
    bne lbl_08088fe4
    ldrb r0, [r3, #0x1e]
    cmp r0, #0
    beq lbl_08088fe4
    ldr r0, lbl_0808900c @ =0x0300586c
    ldr r1, [r0]
    adds r1, #0xc0
    ldr r0, lbl_08089010 @ =0x03005870
    ldr r2, [r0]
    subs r2, #0xc0
    movs r0, #1
    str r0, [sp]
    adds r0, r3, #0
    movs r3, #4
    bl sub_08089600
lbl_08088fe4:
    ldr r4, lbl_08089008 @ =0x03005820
    adds r0, r4, #0
    bl sub_080891a0
    ldr r1, lbl_08089014 @ =0x03005874
    str r0, [r1]
    adds r0, r4, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_0808901c
    ldr r1, lbl_08089018 @ =0x03005884
    movs r0, #0
    strb r0, [r1]
    b lbl_08089066
    .align 2, 0
lbl_08089004: .4byte 0x03005808
lbl_08089008: .4byte 0x03005820
lbl_0808900c: .4byte 0x0300586c
lbl_08089010: .4byte 0x03005870
lbl_08089014: .4byte 0x03005874
lbl_08089018: .4byte 0x03005884
lbl_0808901c:
    ldrb r2, [r4, #0x18]
    cmp r2, #0xd1
    beq lbl_08089044
    ldr r0, lbl_0808903c @ =0x03001380
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08089044
    cmp r2, #0xdf
    bhi lbl_08089044
    ldr r1, lbl_08089040 @ =0x03005808
    movs r0, #8
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_0808903c: .4byte 0x03001380
lbl_08089040: .4byte 0x03005808
lbl_08089044:
    ldr r1, lbl_08089054 @ =0x03005808
    ldrh r0, [r1, #6]
    cmp r0, #0xb4
    bls lbl_08089100
    movs r0, #7
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089054: .4byte 0x03005808
lbl_08089058:
    ldr r0, lbl_08089070 @ =0x0875e6a8
    ldr r1, lbl_08089074 @ =0x087566c4
    subs r0, r0, r1
    bl sub_0808980c
    cmp r0, #0
    bne lbl_0808907c
lbl_08089066:
    ldr r1, lbl_08089078 @ =0x03005808
lbl_08089068:
    ldrb r0, [r1, #9]
    adds r0, #1
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089070: .4byte 0x0875e6a8
lbl_08089074: .4byte 0x087566c4
lbl_08089078: .4byte 0x03005808
lbl_0808907c:
    ldr r1, lbl_08089084 @ =0x03005808
    movs r0, #9
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_08089084: .4byte 0x03005808
lbl_08089088:
    ldr r0, lbl_0808909c @ =0x03005880
    ldr r0, [r0]
    cmp r0, #1
    beq lbl_080890a6
    cmp r0, #1
    blo lbl_080890a0
    cmp r0, #2
    beq lbl_080890aa
    b lbl_080890ae
    .align 2, 0
lbl_0808909c: .4byte 0x03005880
lbl_080890a0:
    ldrb r0, [r2, #9]
    adds r0, #1
    b lbl_080890ac
lbl_080890a6:
    movs r0, #8
    b lbl_080890ac
lbl_080890aa:
    movs r0, #9
lbl_080890ac:
    strb r0, [r2, #9]
lbl_080890ae:
    ldr r1, lbl_080890b8 @ =0x03005808
    movs r0, #0xa
    strb r0, [r1, #9]
    b lbl_08089100
    .align 2, 0
lbl_080890b8: .4byte 0x03005808
lbl_080890bc:
    ldr r0, lbl_080890c4 @ =0x03005808
    movs r1, #2
    b lbl_080890d8
    .align 2, 0
lbl_080890c4: .4byte 0x03005808
lbl_080890c8:
    ldr r0, lbl_080890d0 @ =0x03005808
    movs r1, #3
    b lbl_080890d8
    .align 2, 0
lbl_080890d0: .4byte 0x03005808
lbl_080890d4:
    ldr r0, lbl_080890e0 @ =0x03005808
    movs r1, #4
lbl_080890d8:
    strb r1, [r0, #0xb]
    movs r1, #0xb
    strb r1, [r0, #9]
    b lbl_08089100
    .align 2, 0
lbl_080890e0: .4byte 0x03005808
lbl_080890e4:
    ldr r1, lbl_0808910c @ =0x03005808
    movs r0, #2
    strb r0, [r1, #8]
lbl_080890ea:
    bl init_sound
    bl sub_08078228
    ldr r4, lbl_0808910c @ =0x03005808
    ldrh r0, [r4, #0x12]
    ldrb r1, [r4, #0x14]
    bl PlayMusic
    movs r0, #0xc
lbl_080890fe:
    strb r0, [r4, #9]
lbl_08089100:
    ldr r0, lbl_0808910c @ =0x03005808
    ldrb r0, [r0, #0xb]
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0808910c: .4byte 0x03005808

    thumb_func_start sub_08089110
sub_08089110: @ 0x08089110
    push {r4, lr}
    adds r4, r0, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r0, lbl_08089124 @ =0x03000001
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08089158
    b lbl_08089152
    .align 2, 0
lbl_08089124: .4byte 0x03000001
lbl_08089128:
    movs r3, #0x28
    cmp r0, #0x2f
    bls lbl_08089148
    cmp r0, #0x39
    bhi lbl_08089138
    ldrb r0, [r4]
    subs r0, #0x30
    b lbl_08089144
lbl_08089138:
    cmp r0, #0x5a
    bhi lbl_08089148
    ldr r3, lbl_08089160 @ =0x0000ffc9
    adds r0, r3, #0
    ldrb r3, [r4]
    adds r0, r0, r3
lbl_08089144:
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
lbl_08089148:
    lsls r0, r2, #0xc
    orrs r3, r0
    strh r3, [r1]
    adds r1, #2
    adds r4, #1
lbl_08089152:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_08089128
lbl_08089158:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089160: .4byte 0x0000ffc9

    thumb_func_start sub_08089164
sub_08089164: @ 0x08089164
    adds r2, r0, #0
    movs r1, #0
    strb r1, [r2, #0x1e]
    strb r1, [r2, #0x18]
    strb r1, [r2, #0x1d]
    adds r3, r2, #0
    adds r3, #0x4a
    movs r0, #0xf
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x48
    strb r1, [r0]
    strh r1, [r2, #0x16]
    ldr r0, lbl_08089190 @ =0x04000134
    strh r1, [r0]
    ldr r2, lbl_08089194 @ =0x04000128
    ldr r3, lbl_08089198 @ =0x00002003
    adds r0, r3, #0
    strh r0, [r2]
    ldr r0, lbl_0808919c @ =0x0400012a
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_08089190: .4byte 0x04000134
lbl_08089194: .4byte 0x04000128
lbl_08089198: .4byte 0x00002003
lbl_0808919c: .4byte 0x0400012a

    thumb_func_start sub_080891a0
sub_080891a0: @ 0x080891a0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r7, r0, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_080891b6
    b lbl_0808957e
lbl_080891b6:
    adds r0, r7, #0
    adds r0, #0x4a
    ldrb r1, [r0]
    mov sl, r0
    cmp r1, #0xf
    bls lbl_080891ca
    subs r0, r1, #1
    mov r1, sl
    strb r0, [r1]
    b lbl_0808957e
lbl_080891ca:
    adds r1, r7, #0
    adds r1, #0x48
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_080891f4
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_080891f0 @ =0x04000128
    ldrh r0, [r0]
    movs r5, #0xfc
    ands r5, r0
    cmp r5, #8
    beq lbl_080891f4
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #8
    eors r0, r5
    b lbl_08089580
    .align 2, 0
lbl_080891f0: .4byte 0x04000128
lbl_080891f4:
    ldrb r0, [r7, #0x18]
    cmp r0, #0xdf
    bls lbl_08089246
    adds r0, r7, #0
    bl sub_080896cc
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_08089208
    b lbl_08089580
lbl_08089208:
    adds r0, r7, #0
    adds r0, #0x4b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08089224
    ldrb r0, [r7, #0x18]
    cmp r0, #0xe1
    bls lbl_08089224
    adds r0, r7, #0
    bl sub_080896b8
    cmp r0, #0
    bne lbl_08089224
    b lbl_0808956e
lbl_08089224:
    adds r0, r7, #0
    bl sub_080896b8
    cmp r0, #0
    beq lbl_08089230
    b lbl_0808957e
lbl_08089230:
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_08089240
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x71
    b lbl_08089580
lbl_08089240:
    subs r0, #1
    strh r0, [r7, #0x16]
    b lbl_0808957e
lbl_08089246:
    ldrb r0, [r7, #0x18]
    cmp r0, #2
    bne lbl_0808924e
    b lbl_08089384
lbl_0808924e:
    cmp r0, #2
    bgt lbl_0808925c
    cmp r0, #0
    beq lbl_0808926a
    cmp r0, #1
    beq lbl_08089326
    b lbl_080894bc
lbl_0808925c:
    cmp r0, #0xd0
    bne lbl_08089262
    b lbl_080893d0
lbl_08089262:
    cmp r0, #0xd1
    bne lbl_08089268
    b lbl_0808946a
lbl_08089268:
    b lbl_080894bc
lbl_0808926a:
    movs r3, #0xe
    movs r5, #3
    ldr r0, lbl_080892b0 @ =0x04000120
    ldrh r0, [r0, #6]
    adds r1, r0, #0
    ldr r0, lbl_080892b4 @ =0x0000ffff
    ldrb r2, [r7, #0x1e]
    adds r6, r2, #0
    cmp r1, r0
    bne lbl_08089292
    adds r4, r1, #0
    ldr r1, lbl_080892b8 @ =0x04000126
lbl_08089282:
    asrs r3, r3, #1
    subs r1, #2
    subs r5, #1
    cmp r5, #0
    beq lbl_08089292
    ldrh r0, [r1]
    cmp r0, r4
    beq lbl_08089282
lbl_08089292:
    movs r0, #0xe
    ands r3, r0
    strb r3, [r7, #0x1d]
    movs r5, #3
    ldr r0, lbl_080892b0 @ =0x04000120
    ldrh r0, [r0, #6]
    adds r4, r0, #0
    asrs r0, r2, #3
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080892c0
    ldr r0, lbl_080892bc @ =0x00007208
    b lbl_080892e6
    .align 2, 0
lbl_080892b0: .4byte 0x04000120
lbl_080892b4: .4byte 0x0000ffff
lbl_080892b8: .4byte 0x04000126
lbl_080892bc: .4byte 0x00007208
lbl_080892c0:
    subs r5, #1
    cmp r5, #0
    beq lbl_080892ec
    lsls r0, r5, #1
    ldr r1, lbl_08089314 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r4, r0, #0
    adds r0, r2, #0
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080892c0
    adds r0, r1, #0
    lsls r0, r5
    movs r1, #0xe4
    lsls r1, r1, #7
    orrs r0, r1
lbl_080892e6:
    cmp r4, r0
    beq lbl_080892c0
    movs r3, #0
lbl_080892ec:
    adds r0, r3, #0
    ands r0, r6
    strb r0, [r7, #0x1e]
    cmp r3, #0
    bne lbl_080892fc
    movs r0, #0xf
    mov r2, sl
    strb r0, [r2]
lbl_080892fc:
    mov r1, sl
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08089318
    ldrb r0, [r7, #0x1d]
    ldrb r2, [r7, #0x1e]
    cmp r0, r2
    beq lbl_0808931e
    adds r0, r7, #0
    bl sub_080895dc
    b lbl_08089326
    .align 2, 0
lbl_08089314: .4byte 0x04000120
lbl_08089318:
    subs r0, #1
    mov r1, sl
    strb r0, [r1]
lbl_0808931e:
    ldrb r1, [r7, #0x1e]
    movs r2, #0xc4
    lsls r2, r2, #7
    b lbl_08089426
lbl_08089326:
    adds r1, r7, #0
    adds r1, #0x49
    movs r0, #0
    strb r0, [r1]
    movs r5, #3
    mov ip, r1
    ldr r3, lbl_0808937c @ =0x03005888
lbl_08089334:
    lsls r0, r5, #1
    ldr r2, lbl_08089380 @ =0x04000120
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, r0, #0
    asrs r0, r4, #8
    subs r2, r5, #1
    cmp r0, #0x72
    bne lbl_0808935e
    lsls r0, r2, #1
    adds r0, r0, r3
    strh r4, [r0]
    movs r0, #0xff
    ands r4, r0
    movs r0, #1
    lsls r0, r5
    cmp r4, r0
    bne lbl_0808935e
    ldrb r0, [r1]
    orrs r4, r0
    strb r4, [r1]
lbl_0808935e:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_08089334
    ldrb r0, [r7, #0x1d]
    mov r1, ip
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0808931e
    movs r0, #2
    strb r0, [r7, #0x18]
    mov r2, ip
    ldrb r1, [r2]
    movs r2, #0xc2
    lsls r2, r2, #7
    b lbl_08089426
    .align 2, 0
lbl_0808937c: .4byte 0x03005888
lbl_08089380: .4byte 0x04000120
lbl_08089384:
    movs r5, #3
    movs r0, #0x49
    adds r0, r0, r7
    mov ip, r0
    mov r4, ip
    movs r6, #1
    ldr r1, lbl_080893c8 @ =0x03005888
    mov sb, r1
    ldr r2, lbl_080893cc @ =0x04000120
    mov r8, r2
lbl_08089398:
    ldrb r3, [r4]
    adds r0, r3, #0
    asrs r0, r5
    ands r0, r6
    subs r2, r5, #1
    cmp r0, #0
    beq lbl_080893be
    lsls r0, r5, #1
    add r0, r8
    ldrh r1, [r0]
    lsls r0, r2, #1
    add r0, sb
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_080893be
    adds r0, r6, #0
    lsls r0, r5
    eors r3, r0
    strb r3, [r4]
lbl_080893be:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_08089398
    b lbl_08089524
    .align 2, 0
lbl_080893c8: .4byte 0x03005888
lbl_080893cc: .4byte 0x04000120
lbl_080893d0:
    movs r3, #1
    movs r5, #3
    movs r0, #0x49
    adds r0, r0, r7
    mov ip, r0
    adds r6, r7, #0
    adds r6, #0x19
    ldr r1, lbl_08089434 @ =0x03005888
    mov r8, r1
lbl_080893e2:
    lsls r0, r5, #1
    ldr r2, lbl_08089438 @ =0x04000120
    adds r0, r0, r2
    ldrh r0, [r0]
    adds r4, r0, #0
    subs r2, r5, #1
    adds r0, r6, r2
    strb r4, [r0]
    mov r0, ip
    ldrb r1, [r0]
    asrs r1, r5
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08089416
    asrs r0, r4, #8
    subs r0, #0x72
    cmp r0, #1
    bls lbl_0808940a
    b lbl_08089574
lbl_0808940a:
    lsls r0, r2, #1
    add r0, r8
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_08089416
    movs r3, #0
lbl_08089416:
    adds r5, r2, #0
    cmp r5, #0
    bne lbl_080893e2
    cmp r3, #0
    bne lbl_0808943c
    ldrb r1, [r7, #0x1c]
    movs r2, #0xc6
    lsls r2, r2, #7
lbl_08089426:
    adds r0, r2, #0
    orrs r1, r0
    adds r0, r7, #0
    bl sub_08089590
    b lbl_08089580
    .align 2, 0
lbl_08089434: .4byte 0x03005888
lbl_08089438: .4byte 0x04000120
lbl_0808943c:
    movs r0, #0xd1
    strb r0, [r7, #0x18]
    movs r3, #0x11
    movs r5, #3
    adds r1, r6, #2
lbl_08089446:
    ldrb r0, [r1]
    adds r3, r3, r0
    subs r1, #1
    subs r5, #1
    cmp r5, #0
    bne lbl_08089446
    strb r3, [r7, #0x14]
    movs r0, #0xff
    ands r3, r0
    movs r1, #0xc8
    lsls r1, r1, #7
    adds r0, r1, #0
    orrs r3, r0
    adds r0, r7, #0
    adds r1, r3, #0
    bl sub_08089590
    b lbl_08089580
lbl_0808946a:
    movs r5, #3
    movs r2, #0x49
    ldrb r1, [r2, r7]
    ldr r2, lbl_080894a8 @ =0x04000126
    movs r3, #1
lbl_08089474:
    ldrh r0, [r2]
    adds r4, r0, #0
    adds r0, r1, #0
    asrs r0, r5
    ands r0, r3
    cmp r0, #0
    beq lbl_08089488
    asrs r0, r4, #8
    cmp r0, #0x73
    bne lbl_08089574
lbl_08089488:
    subs r2, #2
    subs r5, #1
    cmp r5, #0
    bne lbl_08089474
    adds r0, r7, #0
    bl Multiboot
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_080894ac
    movs r0, #0xe0
    strb r0, [r7, #0x18]
    adds r0, #0xb0
    strh r0, [r7, #0x16]
    b lbl_0808957e
    .align 2, 0
lbl_080894a8: .4byte 0x04000126
lbl_080894ac:
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x1e
    mov r1, sl
    strb r0, [r1]
    movs r0, #0x70
    b lbl_08089580
lbl_080894bc:
    movs r5, #3
    movs r2, #0x49
    adds r2, r2, r7
    mov ip, r2
    mov r8, ip
    movs r0, #1
    mov sb, r0
lbl_080894ca:
    mov r1, r8
    ldrb r6, [r1]
    adds r0, r6, #0
    asrs r0, r5
    mov r2, sb
    ands r0, r2
    cmp r0, #0
    beq lbl_08089504
    lsls r0, r5, #1
    ldr r1, lbl_08089520 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r4, r0, #0
    asrs r2, r4, #8
    ldrb r0, [r7, #0x18]
    lsrs r0, r0, #1
    movs r1, #0x62
    subs r1, r1, r0
    mov r3, sb
    lsls r3, r5
    cmp r2, r1
    bne lbl_080894fe
    movs r0, #0xff
    ands r4, r0
    cmp r4, r3
    beq lbl_08089504
lbl_080894fe:
    eors r6, r3
    mov r2, r8
    strb r6, [r2]
lbl_08089504:
    subs r5, #1
    cmp r5, #0
    bne lbl_080894ca
    ldrb r0, [r7, #0x18]
    cmp r0, #0xc4
    bne lbl_08089524
    mov r0, ip
    ldrb r1, [r0]
    movs r0, #0xe
    ands r0, r1
    strb r0, [r7, #0x1e]
    strb r5, [r7, #0x18]
    b lbl_0808931e
    .align 2, 0
lbl_08089520: .4byte 0x04000120
lbl_08089524:
    mov r1, ip
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08089536
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x50
    b lbl_08089580
lbl_08089536:
    ldrb r0, [r7, #0x18]
    adds r0, #2
    strb r0, [r7, #0x18]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc4
    bne lbl_08089546
    b lbl_0808931e
lbl_08089546:
    ldrb r0, [r7, #0x18]
    ldr r1, [r7, #0x28]
    adds r0, r0, r1
    subs r1, r0, #3
    ldrb r2, [r1]
    lsls r2, r2, #8
    subs r0, #4
    ldrb r1, [r0]
    orrs r1, r2
    adds r0, r7, #0
    bl sub_08089590
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_08089580
    adds r0, r7, #0
    adds r0, #0x4b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0808957e
lbl_0808956e:
    bl sub_080897d0
    b lbl_080891ca
lbl_08089574:
    adds r0, r7, #0
    bl sub_08089164
    movs r0, #0x60
    b lbl_08089580
lbl_0808957e:
    movs r0, #0
lbl_08089580:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08089590
sub_08089590: @ 0x08089590
    push {r4, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r3, lbl_080895bc @ =0x04000128
    ldrh r0, [r3]
    movs r4, #0x8c
    ands r4, r0
    cmp r4, #8
    bne lbl_080895c8
    ldr r0, lbl_080895c0 @ =0x0400012a
    strh r1, [r0]
    ldr r1, lbl_080895c4 @ =0x00002083
    adds r0, r1, #0
    strh r0, [r3]
    adds r1, r2, #0
    adds r1, #0x48
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    b lbl_080895d4
    .align 2, 0
lbl_080895bc: .4byte 0x04000128
lbl_080895c0: .4byte 0x0400012a
lbl_080895c4: .4byte 0x00002083
lbl_080895c8:
    adds r0, r2, #0
    bl sub_08089164
    movs r0, #8
    eors r4, r0
    adds r0, r4, #0
lbl_080895d4:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080895dc
sub_080895dc: @ 0x080895dc
    push {lr}
    adds r1, r0, #0
    ldrb r0, [r1, #0x18]
    cmp r0, #0
    beq lbl_080895ee
    adds r0, r1, #0
    bl sub_08089164
    b lbl_080895fa
lbl_080895ee:
    adds r2, r1, #0
    adds r2, #0x4a
    strb r0, [r2]
    strb r0, [r1, #0x1e]
    movs r0, #1
    strb r0, [r1, #0x18]
lbl_080895fa:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08089600
sub_08089600: @ 0x08089600
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r7, r1, #0
    ldr r0, [sp, #0x14]
    lsls r3, r3, #0x18
    lsrs r6, r3, #0x18
    lsls r0, r0, #0x18
    asrs r3, r0, #0x18
    ldrb r0, [r5, #0x18]
    cmp r0, #0
    bne lbl_0808963a
    ldrb r0, [r5, #0x1e]
    cmp r0, #0
    beq lbl_0808963a
    adds r0, r5, #0
    adds r0, #0x4a
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0808963a
    str r7, [r5, #0x20]
    adds r2, #0xf
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r2, r0
    subs r0, #0xf0
    adds r1, r2, r0
    ldr r0, lbl_08089644 @ =0x0003ff00
    cmp r1, r0
    bls lbl_08089648
lbl_0808963a:
    adds r0, r5, #0
    bl sub_08089164
    b lbl_080896b0
    .align 2, 0
lbl_08089644: .4byte 0x0003ff00
lbl_08089648:
    adds r0, r7, r2
    str r0, [r5, #0x24]
    adds r0, r3, #4
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bhi lbl_0808969c
    lsls r0, r0, #2
    ldr r1, lbl_08089660 @ =lbl_08089664
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08089660: .4byte lbl_08089664
lbl_08089664: @ jump table
    .4byte lbl_08089688 @ case 0
    .4byte lbl_08089688 @ case 1
    .4byte lbl_08089688 @ case 2
    .4byte lbl_08089688 @ case 3
    .4byte lbl_08089690 @ case 4
    .4byte lbl_08089696 @ case 5
    .4byte lbl_08089696 @ case 6
    .4byte lbl_08089696 @ case 7
    .4byte lbl_08089696 @ case 8
lbl_08089688:
    lsls r4, r6, #3
    movs r0, #3
    subs r0, r0, r3
    b lbl_0808969a
lbl_08089690:
    movs r0, #0x38
    adds r4, r6, #0
    b lbl_0808969a
lbl_08089696:
    lsls r4, r6, #3
    subs r0, r3, #1
lbl_0808969a:
    orrs r4, r0
lbl_0808969c:
    movs r0, #0x3f
    ands r4, r0
    lsls r0, r4, #1
    movs r2, #0x7f
    rsbs r2, r2, #0
    adds r1, r2, #0
    orrs r0, r1
    strb r0, [r5, #0x1c]
    movs r0, #0xd0
    strb r0, [r5, #0x18]
lbl_080896b0:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080896b8
sub_080896b8: @ 0x080896b8
    push {lr}
    ldrb r0, [r0, #0x18]
    cmp r0, #0xe9
    beq lbl_080896c4
    movs r0, #0
    b lbl_080896c6
lbl_080896c4:
    movs r0, #1
lbl_080896c6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080896cc
sub_080896cc: @ 0x080896cc
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    ldrb r0, [r3, #0x18]
    cmp r0, #0xe0
    beq lbl_080896e8
    cmp r0, #0xe0
    blt lbl_080896f8
    cmp r0, #0xe8
    bgt lbl_080896f8
    cmp r0, #0xe7
    blt lbl_080896f8
    movs r4, #3
    ldrb r5, [r3, #0x1e]
    b lbl_08089758
lbl_080896e8:
    movs r1, #0
    movs r0, #0xe1
    strb r0, [r3, #0x18]
    str r1, [r3, #4]
    movs r0, #0x80
    lsls r0, r0, #0xd
    str r0, [r3]
    b lbl_0808974a
lbl_080896f8:
    movs r4, #3
    ldrb r5, [r3, #0x1e]
    movs r6, #1
    ldr r1, lbl_08089754 @ =0x04000126
lbl_08089700:
    ldrh r0, [r1]
    adds r2, r0, #0
    adds r0, r5, #0
    asrs r0, r4
    ands r0, r6
    cmp r0, #0
    beq lbl_08089714
    ldr r0, [r3, #4]
    cmp r2, r0
    bne lbl_080896e8
lbl_08089714:
    subs r1, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08089700
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
    ldr r1, [r3]
    ldrh r0, [r3]
    str r0, [r3, #4]
    cmp r1, #0
    bne lbl_08089742
    ldr r0, [r3, #0x28]
    adds r1, r0, #0
    adds r1, #0xac
    ldrb r1, [r1]
    adds r0, #0xad
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r1, r0
    str r1, [r3, #4]
    lsls r1, r1, #5
    str r1, [r3]
lbl_08089742:
    ldr r0, [r3]
    lsrs r0, r0, #5
    str r0, [r3]
lbl_08089748:
    ldrh r1, [r3]
lbl_0808974a:
    adds r0, r3, #0
    bl sub_08089590
    b lbl_080897b0
    .align 2, 0
lbl_08089754: .4byte 0x04000126
lbl_08089758:
    lsls r0, r4, #1
    ldr r1, lbl_080897a0 @ =0x04000120
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r2, r0, #0
    adds r0, r5, #0
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08089774
    ldr r0, [r3, #4]
    cmp r2, r0
    bne lbl_080897a4
lbl_08089774:
    subs r4, #1
    cmp r4, #0
    bne lbl_08089758
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xe9
    beq lbl_080897ae
    ldr r0, [r3, #0x28]
    adds r1, r0, #0
    adds r1, #0xae
    ldrb r1, [r1]
    adds r0, #0xaf
    ldrb r0, [r0]
    lsls r0, r0, #8
    orrs r1, r0
    str r1, [r3]
    str r1, [r3, #4]
    b lbl_08089748
    .align 2, 0
lbl_080897a0: .4byte 0x04000120
lbl_080897a4:
    adds r0, r3, #0
    bl sub_08089164
    movs r0, #0x71
    b lbl_080897b0
lbl_080897ae:
    movs r0, #0
lbl_080897b0:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080897b8
sub_080897b8: @ 0x080897b8
    mov r2, pc
    lsrs r2, r2, #0x18
    movs r1, #0xc
    cmp r2, #2
    beq lbl_080897ca
    movs r1, #0xd
    cmp r2, #8
    beq lbl_080897ca
    movs r1, #4
lbl_080897ca:
    subs r0, r0, r1
    bgt lbl_080897ca
    bx lr

    thumb_func_start sub_080897d0
sub_080897d0: @ 0x080897d0
    push {r4, r5, lr}
    movs r2, #0
    ldr r3, lbl_08089804 @ =0x04000128
    ldrh r1, [r3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080897f4
    ldr r5, lbl_08089808 @ =0x0000795c
    movs r4, #0x80
lbl_080897e4:
    adds r2, #1
    cmp r2, r5
    bgt lbl_080897f4
    ldrh r1, [r3]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_080897e4
lbl_080897f4:
    movs r0, #0x96
    lsls r0, r0, #2
    bl sub_080897b8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089804: .4byte 0x04000128
lbl_08089808: .4byte 0x0000795c

    thumb_func_start sub_0808980c
sub_0808980c: @ 0x0808980c
    push {r4, r5, lr}
    sub sp, #4
    adds r5, r0, #0
    adds r4, r1, #0
    bl sub_08089d98
lbl_08089818:
    movs r0, #1
    adds r1, r5, #0
    adds r2, r4, #0
    movs r3, #0
    bl sub_080899c8
    adds r1, r0, #0
    ldr r0, lbl_08089840 @ =0x030058a8
    strh r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08089844
    movs r0, #0xc
    ands r0, r1
    cmp r0, #0
    beq lbl_08089844
    movs r4, #0
    b lbl_08089894
    .align 2, 0
lbl_08089840: .4byte 0x030058a8
lbl_08089844:
    ldr r0, lbl_08089854 @ =0x030058a8
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08089858
    movs r4, #1
    b lbl_08089894
    .align 2, 0
lbl_08089854: .4byte 0x030058a8
lbl_08089858:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08089864
    movs r4, #2
    b lbl_08089894
lbl_08089864:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08089870
    movs r4, #3
    b lbl_08089894
lbl_08089870:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0808987c
    movs r4, #4
    b lbl_08089894
lbl_0808987c:
    ldr r0, lbl_08089890 @ =0x03005808
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_08089888
    bl _call_via_r0
lbl_08089888:
    bl VBlankIntrWait
    b lbl_08089818
    .align 2, 0
lbl_08089890: .4byte 0x03005808
lbl_08089894:
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_080898b0 @ =0x03005890
    ldr r2, lbl_080898b4 @ =0x05000006
    mov r0, sp
    bl CpuSet
    bl sub_08089dec
    adds r0, r4, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080898b0: .4byte 0x03005890
lbl_080898b4: .4byte 0x05000006

    thumb_func_start sub_080898b8
sub_080898b8: @ 0x080898b8
    push {lr}
    sub sp, #4
    ldr r1, lbl_080898ec @ =0x030058aa
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_080898f0 @ =0x030058ac
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_080898f4 @ =0x030058ae
    strb r1, [r0]
    ldr r0, lbl_080898f8 @ =0x030058af
    strb r1, [r0]
    ldr r0, lbl_080898fc @ =0x030058b0
    strb r1, [r0]
    ldr r0, lbl_08089900 @ =0x030058b1
    strb r1, [r0]
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_08089904 @ =0x03005890
    ldr r2, lbl_08089908 @ =0x05000006
    mov r0, sp
    bl CpuSet
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_080898ec: .4byte 0x030058aa
lbl_080898f0: .4byte 0x030058ac
lbl_080898f4: .4byte 0x030058ae
lbl_080898f8: .4byte 0x030058af
lbl_080898fc: .4byte 0x030058b0
lbl_08089900: .4byte 0x030058b1
lbl_08089904: .4byte 0x03005890
lbl_08089908: .4byte 0x05000006

    thumb_func_start sub_0808990c
sub_0808990c: @ 0x0808990c
    push {r4, lr}
    ldr r4, lbl_08089938 @ =0x04000208
    movs r3, #0
    strh r3, [r4]
    ldr r2, lbl_0808993c @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_08089940 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r2]
    movs r0, #1
    strh r0, [r4]
    ldr r0, lbl_08089944 @ =0x04000128
    strh r3, [r0]
    subs r0, #0x1a
    strh r3, [r0]
    ldr r1, lbl_08089948 @ =0x04000202
    movs r0, #0xc0
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089938: .4byte 0x04000208
lbl_0808993c: .4byte 0x04000200
lbl_08089940: .4byte 0x0000ff3f
lbl_08089944: .4byte 0x04000128
lbl_08089948: .4byte 0x04000202

    thumb_func_start sub_0808994c
sub_0808994c: @ 0x0808994c
    push {r4, r5, r6, r7, lr}
    ldr r5, lbl_0808998c @ =0x04000208
    movs r4, #0
    strh r4, [r5]
    ldr r3, lbl_08089990 @ =0x04000200
    ldrh r1, [r3]
    ldr r0, lbl_08089994 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r3]
    movs r6, #1
    strh r6, [r5]
    ldr r0, lbl_08089998 @ =0x04000134
    strh r4, [r0]
    ldr r2, lbl_0808999c @ =0x04000128
    movs r1, #0x80
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    ldr r7, lbl_080899a0 @ =0x00004003
    adds r1, r7, #0
    orrs r0, r1
    strh r0, [r2]
    strh r4, [r5]
    ldrh r0, [r3]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r3]
    strh r6, [r5]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808998c: .4byte 0x04000208
lbl_08089990: .4byte 0x04000200
lbl_08089994: .4byte 0x0000ff3f
lbl_08089998: .4byte 0x04000134
lbl_0808999c: .4byte 0x04000128
lbl_080899a0: .4byte 0x00004003

    thumb_func_start sub_080899a4
sub_080899a4: @ 0x080899a4
    ldr r1, lbl_080899c0 @ =0x04000134
    movs r0, #0
    strh r0, [r1]
    ldr r2, lbl_080899c4 @ =0x04000128
    movs r1, #0xa0
    lsls r1, r1, #7
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    movs r1, #8
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
lbl_080899c0: .4byte 0x04000134
lbl_080899c4: .4byte 0x04000128

    thumb_func_start sub_080899c8
sub_080899c8: @ 0x080899c8
    push {r4, r5, r6, lr}
    adds r4, r1, #0
    adds r5, r2, #0
    adds r6, r3, #0
    ldr r0, lbl_080899e4 @ =0x03005890
    ldrb r0, [r0, #1]
    cmp r0, #6
    bls lbl_080899da
    b lbl_08089b0c
lbl_080899da:
    lsls r0, r0, #2
    ldr r1, lbl_080899e8 @ =lbl_080899ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080899e4: .4byte 0x03005890
lbl_080899e8: .4byte lbl_080899ec
lbl_080899ec: @ jump table
    .4byte lbl_08089a08 @ case 0
    .4byte lbl_08089a20 @ case 1
    .4byte lbl_08089a60 @ case 2
    .4byte lbl_08089a74 @ case 3
    .4byte lbl_08089ab4 @ case 4
    .4byte lbl_08089ac4 @ case 5
    .4byte lbl_08089afc @ case 6
lbl_08089a08:
    bl sub_080898b8
    bl sub_0808994c
    ldr r1, lbl_08089a1c @ =0x03005890
    movs r0, #1
    strb r0, [r1, #3]
    strb r0, [r1, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089a1c: .4byte 0x03005890
lbl_08089a20:
    movs r0, #1
    bl sub_08089b3c
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_08089a30
    bl set_siocnt_start_bit_active
lbl_08089a30:
    ldr r2, lbl_08089a58 @ =0x03005890
    ldrb r0, [r2, #5]
    cmp r0, #0
    beq lbl_08089a3c
    movs r0, #6
    strb r0, [r2, #1]
lbl_08089a3c:
    ldr r1, lbl_08089a5c @ =0x030058ae
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1e
    bls lbl_08089b0c
    movs r0, #4
    strb r0, [r2, #5]
    movs r0, #6
    strb r0, [r2, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089a58: .4byte 0x03005890
lbl_08089a5c: .4byte 0x030058ae
lbl_08089a60:
    bl sub_080899a4
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl sub_08089b70
    ldr r1, lbl_08089a9c @ =0x03005890
    movs r0, #3
    strb r0, [r1, #1]
lbl_08089a74:
    ldr r4, lbl_08089a9c @ =0x03005890
    ldrb r0, [r4, #3]
    cmp r0, #2
    beq lbl_08089b0c
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_08089aa4
    ldr r1, lbl_08089aa0 @ =0x030058ac
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bls lbl_08089aa4
    bl set_siocnt_start_bit_active
    movs r0, #2
    b lbl_08089b0a
    .align 2, 0
lbl_08089a9c: .4byte 0x03005890
lbl_08089aa0: .4byte 0x030058ac
lbl_08089aa4:
    bl set_siocnt_start_bit_active
    ldr r1, lbl_08089ab0 @ =0x03005890
    movs r0, #2
    strb r0, [r1, #3]
    b lbl_08089b0c
    .align 2, 0
lbl_08089ab0: .4byte 0x03005890
lbl_08089ab4:
    bl sub_0808994c
    ldr r1, lbl_08089ac0 @ =0x03005890
    movs r0, #5
    strb r0, [r1, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089ac0: .4byte 0x03005890
lbl_08089ac4:
    ldr r0, lbl_08089af4 @ =0x03005890
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08089ad8
    ldr r0, lbl_08089af8 @ =0x030058ac
    ldrh r0, [r0]
    cmp r0, #9
    bls lbl_08089ad8
    bl set_siocnt_start_bit_active
lbl_08089ad8:
    ldr r1, lbl_08089af8 @ =0x030058ac
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bls lbl_08089b0c
    ldr r0, lbl_08089af4 @ =0x03005890
    movs r1, #1
    strb r1, [r0, #5]
    movs r1, #6
    strb r1, [r0, #1]
    b lbl_08089b0c
    .align 2, 0
lbl_08089af4: .4byte 0x03005890
lbl_08089af8: .4byte 0x030058ac
lbl_08089afc:
    ldr r4, lbl_08089b38 @ =0x03005890
    ldrb r0, [r4, #3]
    cmp r0, #0
    beq lbl_08089b0c
    bl sub_0808990c
    movs r0, #0
lbl_08089b0a:
    strb r0, [r4, #3]
lbl_08089b0c:
    ldr r4, lbl_08089b38 @ =0x03005890
    ldr r1, [r4, #0xc]
    movs r0, #0x64
    muls r0, r1, r0
    ldr r1, [r4, #0x10]
    bl __divsi3
    strb r0, [r4, #2]
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    lsls r1, r1, #2
    orrs r0, r1
    ldrb r1, [r4, #5]
    lsls r1, r1, #4
    orrs r0, r1
    ldrb r1, [r4, #2]
    lsls r1, r1, #8
    orrs r0, r1
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089b38: .4byte 0x03005890

    thumb_func_start sub_08089b3c
sub_08089b3c: @ 0x08089b3c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_08089b58 @ =0x04000128
    ldr r0, [r0]
    movs r1, #0xc
    ands r0, r1
    cmp r0, #8
    bne lbl_08089b60
    cmp r2, #0
    beq lbl_08089b60
    ldr r1, lbl_08089b5c @ =0x03005890
    movs r0, #1
    b lbl_08089b64
    .align 2, 0
lbl_08089b58: .4byte 0x04000128
lbl_08089b5c: .4byte 0x03005890
lbl_08089b60:
    ldr r1, lbl_08089b6c @ =0x03005890
    movs r0, #0
lbl_08089b64:
    strb r0, [r1]
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089b6c: .4byte 0x03005890

    thumb_func_start sub_08089b70
sub_08089b70: @ 0x08089b70
    push {r4, lr}
    ldr r4, lbl_08089b94 @ =0x04000128
    ldrh r2, [r4]
    movs r3, #1
    orrs r2, r3
    strh r2, [r4]
    ldr r2, lbl_08089b98 @ =0x03005890
    str r1, [r2, #8]
    ldr r1, lbl_08089b9c @ =0x04000120
    str r0, [r1]
    lsrs r0, r0, #2
    adds r0, #1
    str r0, [r2, #0x10]
    bl sub_08089ba0
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08089b94: .4byte 0x04000128
lbl_08089b98: .4byte 0x03005890
lbl_08089b9c: .4byte 0x04000120

    thumb_func_start sub_08089ba0
sub_08089ba0: @ 0x08089ba0
    ldr r1, lbl_08089bc4 @ =0x0400010c
    ldr r2, lbl_08089bc8 @ =0x0000ff9b
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08089bcc @ =0x0400010e
    movs r2, #0x40
    strh r2, [r0]
    ldr r3, lbl_08089bd0 @ =0x04000208
    movs r0, #0
    strh r0, [r3]
    adds r1, #0xf4
    ldrh r0, [r1]
    orrs r0, r2
    strh r0, [r1]
    movs r0, #1
    strh r0, [r3]
    bx lr
    .align 2, 0
lbl_08089bc4: .4byte 0x0400010c
lbl_08089bc8: .4byte 0x0000ff9b
lbl_08089bcc: .4byte 0x0400010e
lbl_08089bd0: .4byte 0x04000208

    thumb_func_start sub_08089bd4
sub_08089bd4: @ 0x08089bd4
    push {lr}
    bl sub_08089d74
    bl set_siocnt_start_bit_active
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start serial_communication_code_connecting
serial_communication_code_connecting: @ 0x08089be4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r0, lbl_08089c04 @ =0x04000128
    ldr r6, [r0]
    ldr r2, lbl_08089c08 @ =0x03005890
    ldrb r0, [r2, #1]
    adds r4, r2, #0
    cmp r0, #3
    beq lbl_08089c98
    cmp r0, #3
    bgt lbl_08089c0c
    cmp r0, #1
    beq lbl_08089c12
    b lbl_08089d56
    .align 2, 0
lbl_08089c04: .4byte 0x04000128
lbl_08089c08: .4byte 0x03005890
lbl_08089c0c:
    cmp r0, #5
    beq lbl_08089d00
    b lbl_08089d56
lbl_08089c12:
    ldr r1, lbl_08089c4c @ =0x0400012a
    ldr r2, lbl_08089c50 @ =0x00007c40
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_08089c54 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    movs r1, #0
    movs r3, #0
    movs r2, #0
    ldr r5, lbl_08089c58 @ =0x030058b0
    ldr r0, lbl_08089c5c @ =0x030058b1
    mov r8, r0
    lsls r6, r6, #0x1a
    ldr r0, lbl_08089c50 @ =0x00007c40
    mov ip, r0
    ldr r7, lbl_08089c60 @ =0x0000ffff
lbl_08089c38:
    lsls r0, r1, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r0, ip
    bne lbl_08089c64
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    b lbl_08089c6e
    .align 2, 0
lbl_08089c4c: .4byte 0x0400012a
lbl_08089c50: .4byte 0x00007c40
lbl_08089c54: .4byte 0x04000120
lbl_08089c58: .4byte 0x030058b0
lbl_08089c5c: .4byte 0x030058b1
lbl_08089c60: .4byte 0x0000ffff
lbl_08089c64:
    cmp r0, r7
    beq lbl_08089c6e
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_08089c6e:
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #3
    bls lbl_08089c38
    strb r3, [r5]
    lsrs r0, r6, #0x1e
    mov r1, r8
    strb r0, [r1]
    cmp r3, #2
    bhi lbl_08089c92
    cmp r3, #1
    bls lbl_08089d56
    cmp r2, #0
    bne lbl_08089d56
    movs r0, #2
    strb r0, [r4, #1]
    b lbl_08089d56
lbl_08089c92:
    movs r0, #8
    strb r0, [r4, #5]
    b lbl_08089d56
lbl_08089c98:
    ldr r2, lbl_08089cb8 @ =0x04000120
    ldr r0, [r2]
    ldr r1, [r4, #0xc]
    ldr r0, [r4, #0x10]
    cmp r1, r0
    bge lbl_08089cbc
    ldr r0, [r4, #8]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    str r0, [r2]
    ldr r0, [r4, #0x14]
    ldr r1, [r1]
    adds r0, r0, r1
    str r0, [r4, #0x14]
    b lbl_08089cc8
    .align 2, 0
lbl_08089cb8: .4byte 0x04000120
lbl_08089cbc:
    cmp r1, r0
    bne lbl_08089cc4
    ldr r0, [r4, #0x14]
    b lbl_08089cc6
lbl_08089cc4:
    movs r0, #0
lbl_08089cc6:
    str r0, [r2]
lbl_08089cc8:
    ldr r1, [r4, #0xc]
    adds r1, #1
    str r1, [r4, #0xc]
    ldr r0, lbl_08089ce8 @ =0x030058b0
    ldrb r2, [r0]
    ldr r0, [r4, #0x10]
    adds r0, r0, r2
    cmp r1, r0
    bge lbl_08089cf0
    ldr r0, lbl_08089cec @ =0x0400010e
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    b lbl_08089d56
    .align 2, 0
lbl_08089ce8: .4byte 0x030058b0
lbl_08089cec: .4byte 0x0400010e
lbl_08089cf0:
    movs r0, #0
    movs r1, #4
    strb r1, [r4, #1]
    ldr r1, lbl_08089cfc @ =0x030058ac
    strh r0, [r1]
    b lbl_08089d56
    .align 2, 0
lbl_08089cfc: .4byte 0x030058ac
lbl_08089d00:
    ldr r0, lbl_08089d30 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    movs r1, #1
    movs r3, #1
    ldr r0, lbl_08089d34 @ =0x030058b0
    adds r5, r0, #0
    ldrb r0, [r5]
    cmp r1, r0
    bhs lbl_08089d56
    movs r4, #6
lbl_08089d1a:
    lsls r0, r1, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r0, #1
    beq lbl_08089d38
    cmp r0, #2
    bne lbl_08089d3e
    strb r0, [r2, #4]
    strb r4, [r2, #1]
    b lbl_08089d56
    .align 2, 0
lbl_08089d30: .4byte 0x04000120
lbl_08089d34: .4byte 0x030058b0
lbl_08089d38:
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
lbl_08089d3e:
    ldrb r0, [r5]
    cmp r3, r0
    bne lbl_08089d4a
    movs r0, #1
    strb r0, [r2, #4]
    strb r4, [r2, #1]
lbl_08089d4a:
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrb r0, [r5]
    cmp r1, r0
    blo lbl_08089d1a
lbl_08089d56:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start set_siocnt_start_bit_active
set_siocnt_start_bit_active: @ 0x08089d64
    ldr r0, lbl_08089d70 @ =0x04000128
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_08089d70: .4byte 0x04000128

    thumb_func_start sub_08089d74
sub_08089d74: @ 0x08089d74
    ldr r2, lbl_08089d88 @ =0x0400010e
    ldrh r1, [r2]
    ldr r0, lbl_08089d8c @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08089d90 @ =0x0400010c
    ldr r2, lbl_08089d94 @ =0x0000ff9b
    adds r0, r2, #0
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089d88: .4byte 0x0400010e
lbl_08089d8c: .4byte 0x0000ff7f
lbl_08089d90: .4byte 0x0400010c
lbl_08089d94: .4byte 0x0000ff9b

    thumb_func_start sub_08089d98
sub_08089d98: @ 0x08089d98
    ldr r1, lbl_08089dc4 @ =0x030058b2
    ldr r0, lbl_08089dc8 @ =0x04000208
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089dcc @ =0x030058b4
    ldr r0, lbl_08089dd0 @ =0x04000200
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089dd4 @ =0x030058b6
    ldr r0, lbl_08089dd8 @ =0x0400010e
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089ddc @ =0x030058b8
    ldr r0, lbl_08089de0 @ =0x04000128
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08089de4 @ =0x030058ba
    ldr r0, lbl_08089de8 @ =0x04000134
    ldrh r0, [r0]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089dc4: .4byte 0x030058b2
lbl_08089dc8: .4byte 0x04000208
lbl_08089dcc: .4byte 0x030058b4
lbl_08089dd0: .4byte 0x04000200
lbl_08089dd4: .4byte 0x030058b6
lbl_08089dd8: .4byte 0x0400010e
lbl_08089ddc: .4byte 0x030058b8
lbl_08089de0: .4byte 0x04000128
lbl_08089de4: .4byte 0x030058ba
lbl_08089de8: .4byte 0x04000134

    thumb_func_start sub_08089dec
sub_08089dec: @ 0x08089dec
    ldr r1, lbl_08089e18 @ =0x04000208
    ldr r0, lbl_08089e1c @ =0x030058b2
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #8
    ldr r0, lbl_08089e20 @ =0x030058b4
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0xf2
    ldr r0, lbl_08089e24 @ =0x030058b6
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x1a
    ldr r0, lbl_08089e28 @ =0x030058b8
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0xc
    ldr r0, lbl_08089e2c @ =0x030058ba
    ldrh r0, [r0]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_08089e18: .4byte 0x04000208
lbl_08089e1c: .4byte 0x030058b2
lbl_08089e20: .4byte 0x030058b4
lbl_08089e24: .4byte 0x030058b6
lbl_08089e28: .4byte 0x030058b8
lbl_08089e2c: .4byte 0x030058ba

    thumb_func_start sub_08089e30
sub_08089e30: @ 0x08089e30
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_08089e54 @ =0x03005808
    movs r0, #0
    strb r0, [r1, #0xb]
    ldrh r0, [r1, #6]
    adds r0, #1
    strh r0, [r1, #6]
    ldrb r0, [r1, #0xa]
    cmp r0, #5
    bls lbl_08089e48
    b lbl_08089f82
lbl_08089e48:
    lsls r0, r0, #2
    ldr r1, lbl_08089e58 @ =lbl_08089e5c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08089e54: .4byte 0x03005808
lbl_08089e58: .4byte lbl_08089e5c
lbl_08089e5c: @ jump table
    .4byte lbl_08089e74 @ case 0
    .4byte lbl_08089f10 @ case 1
    .4byte lbl_08089f66 @ case 2
    .4byte lbl_08089f7c @ case 3
    .4byte lbl_08089f7c @ case 4
    .4byte lbl_08089f82 @ case 5
lbl_08089e74:
    mov r0, sp
    movs r4, #0
    strh r4, [r0]
    ldr r1, lbl_08089edc @ =0x040000d4
    str r0, [r1]
    ldr r0, lbl_08089ee0 @ =0x030058c0
    str r0, [r1, #4]
    ldr r0, lbl_08089ee4 @ =0x81000002
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    mov r0, sp
    strh r4, [r0]
    str r0, [r1]
    ldr r0, lbl_08089ee8 @ =0x030058c4
    str r0, [r1, #4]
    ldr r0, lbl_08089eec @ =0x81000004
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08089ef0 @ =0x030058bc
    movs r5, #0
    str r5, [r0]
    ldr r0, lbl_08089ef4 @ =0x030058cc
    strb r4, [r0]
    ldr r0, lbl_08089ef8 @ =0x030058cd
    strb r4, [r0]
    ldr r0, lbl_08089efc @ =0x030058ce
    strb r4, [r0]
    ldr r0, lbl_08089f00 @ =0x030058cf
    strb r4, [r0]
    ldr r0, lbl_08089f04 @ =sub_0808a7b0
    bl CallbackSetSerialCommunication
    ldr r0, lbl_08089f08 @ =sub_0808a7a0
    bl CallbackSetTimer3
    bl sub_0808a39c
    ldr r1, lbl_08089f0c @ =0x03005808
    movs r0, #0xaa
    lsls r0, r0, #7
    strh r0, [r1, #0xe]
    movs r0, #0xff
    strb r0, [r1, #0x11]
    movs r0, #1
    rsbs r0, r0, #0
    strb r0, [r1, #0x10]
    strb r4, [r1, #0xc]
    strh r5, [r1, #6]
    ldrb r0, [r1, #0xa]
    adds r0, #1
    strb r0, [r1, #0xa]
    b lbl_08089f82
    .align 2, 0
lbl_08089edc: .4byte 0x040000d4
lbl_08089ee0: .4byte 0x030058c0
lbl_08089ee4: .4byte 0x81000002
lbl_08089ee8: .4byte 0x030058c4
lbl_08089eec: .4byte 0x81000004
lbl_08089ef0: .4byte 0x030058bc
lbl_08089ef4: .4byte 0x030058cc
lbl_08089ef8: .4byte 0x030058cd
lbl_08089efc: .4byte 0x030058ce
lbl_08089f00: .4byte 0x030058cf
lbl_08089f04: .4byte sub_0808a7b0
lbl_08089f08: .4byte sub_0808a7a0
lbl_08089f0c: .4byte 0x03005808
lbl_08089f10:
    ldr r4, lbl_08089f2c @ =0x03005808
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08089f42
    bl sub_0808a260
    ldrh r1, [r4, #0xe]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    bne lbl_08089f30
    movs r0, #2
    strb r0, [r4, #0xa]
    b lbl_08089f82
    .align 2, 0
lbl_08089f2c: .4byte 0x03005808
lbl_08089f30:
    ldrb r0, [r4, #0xc]
    cmp r0, #0
    beq lbl_08089f3c
    movs r0, #3
    strb r0, [r4, #0xa]
    b lbl_08089f82
lbl_08089f3c:
    movs r0, #4
    strb r0, [r4, #0xa]
    b lbl_08089f82
lbl_08089f42:
    bl check_error
    ldrh r1, [r4, #0xe]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    beq lbl_08089f56
    ldrb r1, [r4, #0xc]
    cmp r1, #0
    beq lbl_08089f5c
lbl_08089f56:
    movs r0, #0
    strb r0, [r4, #4]
    b lbl_08089f82
lbl_08089f5c:
    ldrh r0, [r4, #6]
    cmp r0, #0xb4
    bls lbl_08089f82
    strb r1, [r4, #4]
    b lbl_08089f82
lbl_08089f66:
    ldr r2, lbl_08089f74 @ =0x03000014
    ldr r1, lbl_08089f78 @ =0x03005808
    movs r0, #0x10
    ldrsb r0, [r1, r0]
    strh r0, [r2, #2]
    movs r0, #1
    b lbl_08089f80
    .align 2, 0
lbl_08089f74: .4byte 0x03000014
lbl_08089f78: .4byte 0x03005808
lbl_08089f7c:
    ldr r1, lbl_08089f90 @ =0x03005808
    movs r0, #4
lbl_08089f80:
    strb r0, [r1, #0xb]
lbl_08089f82:
    ldr r0, lbl_08089f90 @ =0x03005808
    ldrb r0, [r0, #0xb]
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08089f90: .4byte 0x03005808

    thumb_func_start check_error
check_error: @ 0x08089f94
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_0808a0d0 @ =0x030058cc
    ldr r1, lbl_0808a0d4 @ =0x03000c77
    ldrb r2, [r1]
    movs r1, #1
    ands r1, r2
    strb r1, [r0]
    ldr r4, lbl_0808a0d8 @ =0x030058bc
    ldr r1, lbl_0808a0dc @ =0x030058c0
    ldr r2, lbl_0808a0e0 @ =0x030058c4
    bl detect_error
    adds r2, r0, #0
    str r2, [r4]
    ldr r3, lbl_0808a0e4 @ =0x030058ce
    movs r1, #3
    ands r1, r2
    strb r1, [r3]
    ldr r3, lbl_0808a0e8 @ =0x030058cd
    movs r1, #0x1c
    ands r1, r2
    lsrs r1, r1, #2
    strb r1, [r3]
    ldr r3, lbl_0808a0ec @ =0x030058cf
    movs r1, #0xe0
    lsls r1, r1, #4
    ands r1, r2
    lsrs r1, r1, #9
    strb r1, [r3]
    movs r1, #0x40
    ands r2, r1
    cmp r2, #0
    beq lbl_08089fe8
    ldr r0, lbl_0808a0f0 @ =0x03005808
    movs r1, #0
    strh r1, [r0, #6]
    ldrh r0, [r0, #0xe]
    bl sub_0808a12c
    bl sub_0808a1d4
lbl_08089fe8:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xf
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a008
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r0, [r2, #0xc]
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a0f4 @ =0x085d9174
    ldr r1, lbl_0808a0f8 @ =0x0600e304
    movs r2, #0xc
    bl sub_08089110
lbl_0808a008:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xa
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a028
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #2
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a0fc @ =0x085d9184
    ldr r1, lbl_0808a100 @ =0x0600e344
    movs r2, #0xc
    bl sub_08089110
lbl_0808a028:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #9
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a048
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #4
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a104 @ =0x085d9198
    ldr r1, lbl_0808a108 @ =0x0600e384
    movs r2, #0xc
    bl sub_08089110
lbl_0808a048:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xb
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a068
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #8
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a10c @ =0x085d91ac
    ldr r1, lbl_0808a110 @ =0x0600e3c4
    movs r2, #0xc
    bl sub_08089110
lbl_0808a068:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xc
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a088
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a114 @ =0x085d91c0
    ldr r1, lbl_0808a118 @ =0x0600e404
    movs r2, #0xc
    bl sub_08089110
lbl_0808a088:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xd
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a0a8
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a11c @ =0x085d91d4
    ldr r1, lbl_0808a120 @ =0x0600e444
    movs r2, #0xc
    bl sub_08089110
lbl_0808a0a8:
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #0xe
    ands r1, r2
    cmp r1, #0
    beq lbl_0808a0c8
    ldr r2, lbl_0808a0f0 @ =0x03005808
    ldrb r1, [r2, #0xc]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2, #0xc]
    ldr r0, lbl_0808a124 @ =0x085d91e8
    ldr r1, lbl_0808a128 @ =0x0600e484
    movs r2, #0xc
    bl sub_08089110
lbl_0808a0c8:
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0808a0d0: .4byte 0x030058cc
lbl_0808a0d4: .4byte 0x03000c77
lbl_0808a0d8: .4byte 0x030058bc
lbl_0808a0dc: .4byte 0x030058c0
lbl_0808a0e0: .4byte 0x030058c4
lbl_0808a0e4: .4byte 0x030058ce
lbl_0808a0e8: .4byte 0x030058cd
lbl_0808a0ec: .4byte 0x030058cf
lbl_0808a0f0: .4byte 0x03005808
lbl_0808a0f4: .4byte 0x085d9174
lbl_0808a0f8: .4byte 0x0600e304
lbl_0808a0fc: .4byte 0x085d9184
lbl_0808a100: .4byte 0x0600e344
lbl_0808a104: .4byte 0x085d9198
lbl_0808a108: .4byte 0x0600e384
lbl_0808a10c: .4byte 0x085d91ac
lbl_0808a110: .4byte 0x0600e3c4
lbl_0808a114: .4byte 0x085d91c0
lbl_0808a118: .4byte 0x0600e404
lbl_0808a11c: .4byte 0x085d91d4
lbl_0808a120: .4byte 0x0600e444
lbl_0808a124: .4byte 0x085d91e8
lbl_0808a128: .4byte 0x0600e484

    thumb_func_start sub_0808a12c
sub_0808a12c: @ 0x0808a12c
    push {lr}
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    movs r0, #0x88
    lsls r0, r0, #7
    cmp r3, r0
    beq lbl_0808a1a8
    cmp r3, r0
    bgt lbl_0808a148
    movs r0, #0x88
    lsls r0, r0, #6
    cmp r3, r0
    beq lbl_0808a1bc
    b lbl_0808a1ca
lbl_0808a148:
    movs r0, #0xaa
    lsls r0, r0, #7
    cmp r3, r0
    beq lbl_0808a18c
    movs r0, #0x88
    lsls r0, r0, #8
    cmp r3, r0
    bne lbl_0808a1ca
    ldr r2, lbl_0808a17c @ =0x030058c0
    ldrh r1, [r2]
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_0808a180 @ =0x0300137c
    ldrh r0, [r0]
    strh r0, [r2, #2]
    ldr r0, lbl_0808a184 @ =0x03001380
    ldrh r1, [r0]
    ldr r0, lbl_0808a188 @ =0x03000020
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    strh r0, [r2, #6]
    strh r1, [r2, #4]
    b lbl_0808a1ca
    .align 2, 0
lbl_0808a17c: .4byte 0x030058c0
lbl_0808a180: .4byte 0x0300137c
lbl_0808a184: .4byte 0x03001380
lbl_0808a188: .4byte 0x03000020
lbl_0808a18c:
    ldr r1, lbl_0808a1a0 @ =0x030058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r0, lbl_0808a1a4 @ =0x03000020
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    b lbl_0808a1c8
    .align 2, 0
lbl_0808a1a0: .4byte 0x030058c0
lbl_0808a1a4: .4byte 0x03000020
lbl_0808a1a8:
    ldr r1, lbl_0808a1b8 @ =0x030058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    movs r2, #0
    strh r0, [r1]
    strh r2, [r1, #2]
    b lbl_0808a1ca
    .align 2, 0
lbl_0808a1b8: .4byte 0x030058c0
lbl_0808a1bc:
    ldr r1, lbl_0808a1d0 @ =0x030058c0
    ldrh r2, [r1]
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    movs r0, #1
lbl_0808a1c8:
    strh r0, [r1, #2]
lbl_0808a1ca:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a1d0: .4byte 0x030058c0

    thumb_func_start sub_0808a1d4
sub_0808a1d4: @ 0x0808a1d4
    push {lr}
    ldr r0, lbl_0808a230 @ =0x030058bc
    ldr r0, [r0]
    movs r1, #0x80
    lsls r1, r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0808a256
    ldr r0, lbl_0808a234 @ =0x030058c4
    ldrh r2, [r0, #2]
    movs r1, #0xaa
    lsls r1, r1, #7
    adds r3, r0, #0
    cmp r2, r1
    bne lbl_0808a20e
    ldr r2, lbl_0808a238 @ =0x03005808
    ldrh r0, [r3, #6]
    strb r0, [r2, #0x11]
    ldr r1, lbl_0808a23c @ =0x03000020
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    cmp r0, r1
    bne lbl_0808a20e
    movs r0, #0x88
    lsls r0, r0, #7
    strh r0, [r2, #0xe]
lbl_0808a20e:
    ldrh r1, [r3, #2]
    movs r0, #0xcc
    lsls r0, r0, #7
    cmp r1, r0
    bne lbl_0808a248
    ldr r1, lbl_0808a238 @ =0x03005808
    ldrh r0, [r3, #6]
    strb r0, [r1, #0x10]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_0808a240
    movs r0, #0x88
    lsls r0, r0, #6
    strh r0, [r1, #0xe]
    b lbl_0808a248
    .align 2, 0
lbl_0808a230: .4byte 0x030058bc
lbl_0808a234: .4byte 0x030058c4
lbl_0808a238: .4byte 0x03005808
lbl_0808a23c: .4byte 0x03000020
lbl_0808a240:
    movs r0, #0
    strh r0, [r1, #0xe]
    movs r0, #5
    strb r0, [r1, #0xb]
lbl_0808a248:
    ldrh r1, [r3, #2]
    movs r0, #0xcc
    lsls r0, r0, #6
    cmp r1, r0
    bne lbl_0808a256
    ldr r0, lbl_0808a25c @ =0x03005808
    strh r1, [r0, #0xe]
lbl_0808a256:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a25c: .4byte 0x03005808

    thumb_func_start sub_0808a260
sub_0808a260: @ 0x0808a260
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0808a2a8 @ =0x030058d0
    ldr r2, lbl_0808a2ac @ =0x04000208
    ldrh r4, [r2]
    strh r4, [r0]
    movs r5, #0
    strh r5, [r2]
    ldr r3, lbl_0808a2b0 @ =0x04000200
    ldrh r1, [r3]
    ldr r0, lbl_0808a2b4 @ =0x0000ff3f
    ands r0, r1
    strh r0, [r3]
    strh r4, [r2]
    ldr r1, lbl_0808a2b8 @ =0x04000128
    movs r2, #0x80
    lsls r2, r2, #6
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0808a2bc @ =0x0400010e
    strh r5, [r0]
    adds r1, #0xda
    movs r0, #0xc0
    strh r0, [r1]
    movs r0, #0
    str r0, [sp]
    ldr r1, lbl_0808a2c0 @ =0x03005b60
    ldr r2, lbl_0808a2c4 @ =0x05000069
    mov r0, sp
    bl CpuSet
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a2a8: .4byte 0x030058d0
lbl_0808a2ac: .4byte 0x04000208
lbl_0808a2b0: .4byte 0x04000200
lbl_0808a2b4: .4byte 0x0000ff3f
lbl_0808a2b8: .4byte 0x04000128
lbl_0808a2bc: .4byte 0x0400010e
lbl_0808a2c0: .4byte 0x03005b60
lbl_0808a2c4: .4byte 0x05000069

    thumb_func_start sub_0808a2c8
sub_0808a2c8: @ 0x0808a2c8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r6, lbl_0808a350 @ =0x030058d0
    ldr r3, lbl_0808a354 @ =0x04000208
    ldrh r2, [r3]
    movs r4, #0
    strh r4, [r3]
    ldr r5, lbl_0808a358 @ =0x04000200
    ldrh r1, [r5]
    ldr r0, lbl_0808a35c @ =0x0000ff3f
    ands r0, r1
    strh r0, [r5]
    strh r2, [r3]
    ldr r0, lbl_0808a360 @ =0x04000134
    strh r4, [r0]
    ldr r2, lbl_0808a364 @ =0x04000128
    movs r1, #0x80
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r2]
    ldrh r0, [r2]
    ldr r7, lbl_0808a368 @ =0x00004003
    adds r1, r7, #0
    orrs r0, r1
    strh r0, [r2]
    ldrh r2, [r3]
    strh r2, [r6]
    strh r4, [r3]
    ldrh r0, [r5]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r5]
    strh r2, [r3]
    ldr r0, lbl_0808a36c @ =0x0400012a
    strh r4, [r0]
    ldr r2, lbl_0808a370 @ =0x04000120
    movs r0, #0
    movs r1, #0
    str r0, [r2]
    str r1, [r2, #4]
    movs r5, #0
    str r5, [sp]
    ldr r1, lbl_0808a374 @ =0x03005b60
    ldr r2, lbl_0808a378 @ =0x05000069
    mov r0, sp
    bl CpuSet
    ldr r0, lbl_0808a37c @ =0x030058d2
    strb r4, [r0]
    ldr r0, lbl_0808a380 @ =0x030058d3
    strb r4, [r0]
    ldr r0, lbl_0808a384 @ =0x030058d5
    strb r4, [r0]
    ldr r0, lbl_0808a388 @ =0x03005b50
    strb r4, [r0]
    ldr r0, lbl_0808a38c @ =0x03005b54
    strb r4, [r0]
    ldr r0, lbl_0808a390 @ =0x030058d6
    strb r4, [r0]
    ldr r0, lbl_0808a394 @ =0x030058d8
    strh r5, [r0]
    ldr r0, lbl_0808a398 @ =0x030058da
    strh r5, [r0]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a350: .4byte 0x030058d0
lbl_0808a354: .4byte 0x04000208
lbl_0808a358: .4byte 0x04000200
lbl_0808a35c: .4byte 0x0000ff3f
lbl_0808a360: .4byte 0x04000134
lbl_0808a364: .4byte 0x04000128
lbl_0808a368: .4byte 0x00004003
lbl_0808a36c: .4byte 0x0400012a
lbl_0808a370: .4byte 0x04000120
lbl_0808a374: .4byte 0x03005b60
lbl_0808a378: .4byte 0x05000069
lbl_0808a37c: .4byte 0x030058d2
lbl_0808a380: .4byte 0x030058d3
lbl_0808a384: .4byte 0x030058d5
lbl_0808a388: .4byte 0x03005b50
lbl_0808a38c: .4byte 0x03005b54
lbl_0808a390: .4byte 0x030058d6
lbl_0808a394: .4byte 0x030058d8
lbl_0808a398: .4byte 0x030058da

    thumb_func_start sub_0808a39c
sub_0808a39c: @ 0x0808a39c
    push {lr}
    bl sub_0808a2c8
    bl sub_0808a260
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start detect_error
detect_error: @ 0x0808a3ac
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r0, lbl_0808a3c8 @ =0x03005b60
    ldrb r0, [r0, #1]
    cmp r0, #4
    bhi lbl_0808a45e
    lsls r0, r0, #2
    ldr r1, lbl_0808a3cc @ =lbl_0808a3d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0808a3c8: .4byte 0x03005b60
lbl_0808a3cc: .4byte lbl_0808a3d0
lbl_0808a3d0: @ jump table
    .4byte lbl_0808a3e4 @ case 0
    .4byte lbl_0808a3f4 @ case 1
    .4byte lbl_0808a40c @ case 2
    .4byte lbl_0808a448 @ case 3
    .4byte lbl_0808a452 @ case 4
lbl_0808a3e4:
    bl sub_0808a260
    ldr r1, lbl_0808a3f0 @ =0x03005b60
    movs r0, #1
    strb r0, [r1, #1]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a3f0: .4byte 0x03005b60
lbl_0808a3f4:
    ldrb r0, [r4]
    cmp r0, #1
    bne lbl_0808a45e
    bl sub_0808a2c8
    ldr r1, lbl_0808a408 @ =0x03005b60
    movs r0, #2
    strb r0, [r1, #1]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a408: .4byte 0x03005b60
lbl_0808a40c:
    ldrb r1, [r4]
    cmp r1, #1
    beq lbl_0808a41c
    cmp r1, #2
    beq lbl_0808a434
    bl sub_0808a4cc
    b lbl_0808a45e
lbl_0808a41c:
    ldr r2, lbl_0808a430 @ =0x03005b60
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0808a45e
    ldrb r0, [r2, #3]
    cmp r0, #1
    bls lbl_0808a45e
    strb r1, [r2, #0x10]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a430: .4byte 0x03005b60
lbl_0808a434:
    ldr r0, lbl_0808a440 @ =0x03005b60
    movs r1, #0
    strb r1, [r0, #1]
    ldr r0, lbl_0808a444 @ =0x0400012a
    strh r1, [r0]
    b lbl_0808a45e
    .align 2, 0
lbl_0808a440: .4byte 0x03005b60
lbl_0808a444: .4byte 0x0400012a
lbl_0808a448:
    bl sub_0808a4f8
    ldr r1, lbl_0808a4a0 @ =0x03005b60
    movs r0, #4
    strb r0, [r1, #1]
lbl_0808a452:
    adds r0, r5, #0
    bl sub_0808a548
    adds r0, r6, #0
    bl sub_0808a628
lbl_0808a45e:
    movs r0, #0
    strb r0, [r4]
    ldr r1, lbl_0808a4a0 @ =0x03005b60
    ldrb r2, [r1, #2]
    ldrb r0, [r1, #3]
    lsls r0, r0, #2
    orrs r2, r0
    ldrb r0, [r1]
    cmp r0, #8
    bne lbl_0808a476
    movs r0, #0x20
    orrs r2, r0
lbl_0808a476:
    ldrb r0, [r1, #0xc]
    lsls r3, r0, #8
    ldrb r0, [r1, #0x11]
    lsls r4, r0, #9
    ldrb r0, [r1, #0x12]
    lsls r5, r0, #0x10
    ldrb r0, [r1, #0x13]
    lsls r6, r0, #0x11
    ldrb r0, [r1, #0x14]
    lsls r7, r0, #0x12
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #0x14
    mov ip, r0
    ldrb r0, [r1, #1]
    cmp r0, #4
    bne lbl_0808a4a4
    movs r0, #0x40
    orrs r0, r3
    orrs r0, r2
    b lbl_0808a4a8
    .align 2, 0
lbl_0808a4a0: .4byte 0x03005b60
lbl_0808a4a4:
    adds r0, r2, #0
    orrs r0, r3
lbl_0808a4a8:
    orrs r0, r4
    orrs r0, r5
    orrs r0, r6
    orrs r0, r7
    mov r2, ip
    orrs r0, r2
    adds r2, r0, #0
    ldrb r0, [r1, #2]
    cmp r0, #1
    bls lbl_0808a4c2
    movs r0, #0x80
    lsls r0, r0, #0xf
    orrs r2, r0
lbl_0808a4c2:
    adds r0, r2, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0808a4cc
sub_0808a4cc: @ 0x0808a4cc
    push {lr}
    ldr r0, lbl_0808a4e8 @ =0x04000128
    ldr r1, [r0]
    movs r0, #0xc
    ands r1, r0
    ldr r2, lbl_0808a4ec @ =0x03005b60
    cmp r1, #8
    bne lbl_0808a4f0
    ldrb r0, [r2, #2]
    cmp r0, #0
    bne lbl_0808a4f0
    strb r1, [r2]
    b lbl_0808a4f4
    .align 2, 0
lbl_0808a4e8: .4byte 0x04000128
lbl_0808a4ec: .4byte 0x03005b60
lbl_0808a4f0:
    movs r0, #0
    strb r0, [r2]
lbl_0808a4f4:
    pop {r0}
    bx r0

    thumb_func_start sub_0808a4f8
sub_0808a4f8: @ 0x0808a4f8
    push {r4, lr}
    ldr r0, lbl_0808a530 @ =0x03005b60
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0808a528
    ldr r1, lbl_0808a534 @ =0x0400010c
    ldr r2, lbl_0808a538 @ =0x0000ff7c
    adds r0, r2, #0
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x41
    strh r0, [r1]
    ldr r0, lbl_0808a53c @ =0x030058d0
    ldr r2, lbl_0808a540 @ =0x04000208
    ldrh r4, [r2]
    strh r4, [r0]
    movs r0, #0
    strh r0, [r2]
    ldr r3, lbl_0808a544 @ =0x04000200
    ldrh r0, [r3]
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r3]
    strh r4, [r2]
lbl_0808a528:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a530: .4byte 0x03005b60
lbl_0808a534: .4byte 0x0400010c
lbl_0808a538: .4byte 0x0000ff7c
lbl_0808a53c: .4byte 0x030058d0
lbl_0808a540: .4byte 0x04000208
lbl_0808a544: .4byte 0x04000200

    thumb_func_start sub_0808a548
sub_0808a548: @ 0x0808a548
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r4, r0, #0
    ldr r2, lbl_0808a5bc @ =0x030058d0
    ldr r1, lbl_0808a5c0 @ =0x04000208
    ldrh r0, [r1]
    strh r0, [r2]
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0808a5c4 @ =0x03005b60
    adds r0, r1, #0
    adds r0, #0x9d
    ldrb r3, [r0]
    mov sl, r2
    mov ip, r1
    cmp r3, #0x1f
    bhi lbl_0808a5d0
    mov r0, ip
    adds r0, #0x9c
    ldrb r0, [r0]
    adds r0, r3, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a586
    subs r0, #0x20
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
lbl_0808a586:
    movs r3, #0
    ldr r1, lbl_0808a5c8 @ =0x030058d8
    mov r8, r1
    ldr r2, lbl_0808a5cc @ =0x03005b50
    mov sb, r2
    mov r2, r8
    lsls r5, r0, #1
    mov r7, ip
    adds r7, #0x1c
    movs r6, #0
lbl_0808a59a:
    ldrh r0, [r2]
    ldrh r1, [r4]
    orrs r0, r1
    strh r0, [r2]
    lsls r0, r3, #6
    adds r0, r5, r0
    adds r0, r0, r7
    strh r1, [r0]
    strh r6, [r4]
    adds r4, #2
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_0808a59a
    b lbl_0808a5e4
    .align 2, 0
lbl_0808a5bc: .4byte 0x030058d0
lbl_0808a5c0: .4byte 0x04000208
lbl_0808a5c4: .4byte 0x03005b60
lbl_0808a5c8: .4byte 0x030058d8
lbl_0808a5cc: .4byte 0x03005b50
lbl_0808a5d0:
    mov r0, ip
    ldrb r1, [r0, #0x14]
    movs r0, #1
    orrs r0, r1
    mov r1, ip
    strb r0, [r1, #0x14]
    ldr r2, lbl_0808a61c @ =0x030058d8
    mov r8, r2
    ldr r0, lbl_0808a620 @ =0x03005b50
    mov sb, r0
lbl_0808a5e4:
    mov r1, r8
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0808a5fc
    mov r3, ip
    adds r3, #0x9d
    ldrb r0, [r3]
    adds r0, #1
    movs r1, #0
    strb r0, [r3]
    mov r2, r8
    strh r1, [r2]
lbl_0808a5fc:
    ldr r1, lbl_0808a624 @ =0x04000208
    mov r2, sl
    ldrh r0, [r2]
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x9d
    ldrb r0, [r0]
    mov r1, sb
    strb r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a61c: .4byte 0x030058d8
lbl_0808a620: .4byte 0x03005b50
lbl_0808a624: .4byte 0x04000208

    thumb_func_start sub_0808a628
sub_0808a628: @ 0x0808a628
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov ip, r0
    ldr r2, lbl_0808a68c @ =0x030058d0
    ldr r1, lbl_0808a690 @ =0x04000208
    ldrh r0, [r1]
    strh r0, [r2]
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_0808a694 @ =0x03005b60
    ldr r3, lbl_0808a698 @ =0x000001a1
    adds r1, r0, r3
    ldrb r1, [r1]
    mov sl, r2
    mov sb, r0
    cmp r1, #0
    bne lbl_0808a69c
    movs r1, #0
    mov r7, sb
    mov r4, sb
    ldrb r5, [r4, #3]
lbl_0808a658:
    movs r3, #0
    adds r6, r1, #1
    cmp r3, r5
    bhs lbl_0808a67a
    lsls r0, r1, #2
    mov r2, ip
    adds r1, r0, r2
    movs r4, #0
    ldrb r2, [r7, #3]
lbl_0808a66a:
    lsls r0, r3, #1
    adds r0, r0, r1
    strh r4, [r0]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r2
    blo lbl_0808a66a
lbl_0808a67a:
    lsls r0, r6, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808a658
    movs r0, #1
    mov r3, sb
    strb r0, [r3, #0xc]
    b lbl_0808a70e
    .align 2, 0
lbl_0808a68c: .4byte 0x030058d0
lbl_0808a690: .4byte 0x04000208
lbl_0808a694: .4byte 0x03005b60
lbl_0808a698: .4byte 0x000001a1
lbl_0808a69c:
    movs r1, #0
    mov r4, sb
    ldrb r4, [r4, #3]
    mov r8, r4
lbl_0808a6a4:
    movs r3, #0
    adds r6, r1, #1
    cmp r3, r8
    bhs lbl_0808a6de
    lsls r0, r1, #2
    mov r2, ip
    adds r7, r0, r2
    ldr r2, lbl_0808a724 @ =0x03005b60
    movs r4, #0xd0
    lsls r4, r4, #1
    adds r0, r2, r4
    ldrb r0, [r0]
    lsls r0, r0, #1
    lsls r1, r1, #6
    adds r5, r0, r1
    ldrb r4, [r2, #3]
    adds r2, #0xa0
lbl_0808a6c6:
    lsls r1, r3, #1
    adds r1, r1, r7
    lsls r0, r3, #7
    adds r0, r5, r0
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r4
    blo lbl_0808a6c6
lbl_0808a6de:
    lsls r0, r6, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808a6a4
    mov r2, sb
    ldr r0, lbl_0808a728 @ =0x000001a1
    adds r1, r2, r0
    ldrb r0, [r1]
    subs r0, #1
    movs r3, #0
    strb r0, [r1]
    movs r4, #0xd0
    lsls r4, r4, #1
    adds r1, r2, r4
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a70a
    strb r3, [r1]
lbl_0808a70a:
    mov r0, sb
    strb r3, [r0, #0xc]
lbl_0808a70e:
    ldr r1, lbl_0808a72c @ =0x04000208
    mov r2, sl
    ldrh r0, [r2]
    strh r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a724: .4byte 0x03005b60
lbl_0808a728: .4byte 0x000001a1
lbl_0808a72c: .4byte 0x04000208

    thumb_func_start sub_0808a730
sub_0808a730: @ 0x0808a730
    push {r4, lr}
    ldr r4, lbl_0808a758 @ =0x03005b60
    ldrb r3, [r4]
    cmp r3, #0
    beq lbl_0808a76a
    ldrb r0, [r4, #1]
    cmp r0, #2
    beq lbl_0808a764
    cmp r0, #4
    bne lbl_0808a796
    ldrb r0, [r4, #0xd]
    cmp r0, #2
    bhi lbl_0808a75c
    ldrb r0, [r4, #0x12]
    cmp r0, #0
    bne lbl_0808a764
    movs r0, #1
    strb r0, [r4, #0x15]
    b lbl_0808a796
    .align 2, 0
lbl_0808a758: .4byte 0x03005b60
lbl_0808a75c:
    ldrb r0, [r4, #0x15]
    cmp r0, #0
    bne lbl_0808a796
    strb r0, [r4, #0xd]
lbl_0808a764:
    bl set_siocnt_start_bit_active_duplicate
    b lbl_0808a796
lbl_0808a76a:
    ldrb r2, [r4, #1]
    cmp r2, #4
    beq lbl_0808a774
    cmp r2, #2
    bne lbl_0808a796
lbl_0808a774:
    ldr r1, lbl_0808a79c @ =0x030058d2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xa
    bls lbl_0808a796
    cmp r2, #4
    bne lbl_0808a78c
    movs r0, #2
    strb r0, [r4, #0x15]
lbl_0808a78c:
    cmp r2, #2
    bne lbl_0808a796
    strb r3, [r4, #2]
    strb r3, [r4, #3]
    strb r3, [r4, #0x11]
lbl_0808a796:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a79c: .4byte 0x030058d2

    thumb_func_start sub_0808a7a0
sub_0808a7a0: @ 0x0808a7a0
    push {lr}
    bl sub_0808aaf0
    bl set_siocnt_start_bit_active_duplicate
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0808a7b0
sub_0808a7b0: @ 0x0808a7b0
    push {r4, r5, lr}
    ldr r0, lbl_0808a7e4 @ =0x04000128
    ldr r1, [r0]
    ldr r5, lbl_0808a7e8 @ =0x03005b60
    lsls r0, r1, #0x1a
    lsrs r0, r0, #0x1e
    strb r0, [r5, #2]
    ldrb r4, [r5, #1]
    cmp r4, #2
    beq lbl_0808a7ec
    cmp r4, #4
    bne lbl_0808a808
    movs r0, #0x40
    ands r1, r0
    cmp r1, #0
    beq lbl_0808a7d4
    movs r0, #1
    strb r0, [r5, #0x12]
lbl_0808a7d4:
    bl sub_0808a94c
    bl sub_0808aa54
    bl sub_0808ab24
    b lbl_0808a808
    .align 2, 0
lbl_0808a7e4: .4byte 0x04000128
lbl_0808a7e8: .4byte 0x03005b60
lbl_0808a7ec:
    bl sub_0808a850
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0808a808
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0808a804
    movs r0, #3
    strb r0, [r5, #1]
    strb r4, [r5, #0xd]
    b lbl_0808a808
lbl_0808a804:
    movs r0, #4
    strb r0, [r5, #1]
lbl_0808a808:
    ldr r3, lbl_0808a830 @ =0x03005b60
    ldrb r0, [r3, #0xd]
    adds r0, #1
    movs r2, #0
    strb r0, [r3, #0xd]
    ldr r1, lbl_0808a834 @ =0x030058d2
    strb r2, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0808a828
    ldr r1, lbl_0808a838 @ =0x03005b54
    ldr r2, lbl_0808a83c @ =0x000001a1
    adds r0, r3, r2
    ldrb r0, [r0]
    strb r0, [r1]
lbl_0808a828:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808a830: .4byte 0x03005b60
lbl_0808a834: .4byte 0x030058d2
lbl_0808a838: .4byte 0x03005b54
lbl_0808a83c: .4byte 0x000001a1

    thumb_func_start set_siocnt_start_bit_active_duplicate
set_siocnt_start_bit_active_duplicate: @ 0x0808a840
    ldr r0, lbl_0808a84c @ =0x04000128
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
    bx lr
    .align 2, 0
lbl_0808a84c: .4byte 0x04000128

    thumb_func_start sub_0808a850
sub_0808a850: @ 0x0808a850
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    ldr r5, lbl_0808a86c @ =0x0000ffff
    ldr r0, lbl_0808a870 @ =0x03005b60
    ldrb r1, [r0, #0x10]
    adds r4, r0, #0
    cmp r1, #1
    bne lbl_0808a880
    ldr r1, lbl_0808a874 @ =0x0400012a
    ldr r2, lbl_0808a878 @ =0x00008fff
    b lbl_0808a884
    .align 2, 0
lbl_0808a86c: .4byte 0x0000ffff
lbl_0808a870: .4byte 0x03005b60
lbl_0808a874: .4byte 0x0400012a
lbl_0808a878: .4byte 0x00008fff
lbl_0808a87c:
    movs r7, #0
    b lbl_0808a902
lbl_0808a880:
    ldr r1, lbl_0808a8d4 @ =0x0400012a
    ldr r2, lbl_0808a8d8 @ =0x00007c40
lbl_0808a884:
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #0
    strb r0, [r4, #0x10]
    ldr r0, lbl_0808a8dc @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #4]
    str r1, [r4, #8]
    movs r3, #0
    ldr r0, lbl_0808a8e0 @ =0x030058d5
    mov sb, r0
    adds r6, r4, #0
    ldr r1, lbl_0808a8e4 @ =0x00008fff
    mov r8, r1
    ldr r2, lbl_0808a8e8 @ =0x0000ffff
    mov ip, r2
lbl_0808a8a6:
    lsls r0, r3, #1
    adds r1, r6, #4
    adds r0, r0, r1
    ldrh r2, [r0]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    ldr r1, lbl_0808a8d8 @ =0x00007c40
    cmp r0, r1
    beq lbl_0808a8c0
    adds r0, r2, #0
    cmp r0, r8
    bne lbl_0808a8ec
lbl_0808a8c0:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r2, #0
    cmp r5, r0
    bls lbl_0808a8f8
    cmp r0, #0
    beq lbl_0808a8f8
    adds r5, r2, #0
    b lbl_0808a8f8
    .align 2, 0
lbl_0808a8d4: .4byte 0x0400012a
lbl_0808a8d8: .4byte 0x00007c40
lbl_0808a8dc: .4byte 0x04000120
lbl_0808a8e0: .4byte 0x030058d5
lbl_0808a8e4: .4byte 0x00008fff
lbl_0808a8e8: .4byte 0x0000ffff
lbl_0808a8ec:
    cmp r0, ip
    bne lbl_0808a87c
    ldrb r0, [r6, #2]
    cmp r3, r0
    bne lbl_0808a8f8
    movs r7, #0
lbl_0808a8f8:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_0808a8a6
lbl_0808a902:
    strb r7, [r4, #3]
    adds r0, r7, #0
    cmp r0, #1
    bls lbl_0808a932
    mov r1, sb
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0808a924
    ldrh r1, [r4, #4]
    ldr r0, lbl_0808a920 @ =0x00008fff
    cmp r1, r0
    bne lbl_0808a924
    movs r0, #1
    b lbl_0808a93e
    .align 2, 0
lbl_0808a920: .4byte 0x00008fff
lbl_0808a924:
    ldrb r0, [r4, #3]
    cmp r0, #1
    bls lbl_0808a932
    movs r0, #3
    ands r5, r0
    adds r0, r5, #1
    b lbl_0808a934
lbl_0808a932:
    movs r0, #0
lbl_0808a934:
    strb r0, [r4, #0x11]
    ldrb r0, [r4, #3]
    mov r2, sb
    strb r0, [r2]
    movs r0, #0
lbl_0808a93e:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0808a94c
sub_0808a94c: @ 0x0808a94c
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    ldr r0, lbl_0808a9a0 @ =0x04000120
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [sp]
    str r1, [sp, #4]
    ldr r0, lbl_0808a9a4 @ =0x03005b60
    ldrb r1, [r0, #0x18]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_0808a9ac
    movs r3, #0
    ldr r7, lbl_0808a9a8 @ =0x030058d6
    ldrb r0, [r5, #3]
    cmp r3, r0
    bhs lbl_0808a996
    adds r6, r5, #0
    ldrh r1, [r5, #0x16]
    adds r4, r7, #0
    adds r2, r5, #0
lbl_0808a976:
    lsls r0, r3, #1
    add r0, sp
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0808a98a
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0808a98a
    movs r0, #1
    strb r0, [r6, #0x13]
lbl_0808a98a:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldrb r0, [r2, #3]
    cmp r3, r0
    blo lbl_0808a976
lbl_0808a996:
    movs r0, #0
    strh r0, [r5, #0x16]
    movs r0, #1
    strb r0, [r7]
    b lbl_0808aa44
    .align 2, 0
lbl_0808a9a0: .4byte 0x04000120
lbl_0808a9a4: .4byte 0x03005b60
lbl_0808a9a8: .4byte 0x030058d6
lbl_0808a9ac:
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r0, r5, r1
    ldr r2, lbl_0808aa10 @ =0x000001a1
    adds r1, r5, r2
    ldrb r1, [r1]
    ldrb r0, [r0]
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808a9ca
    subs r0, #0x20
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
lbl_0808a9ca:
    cmp r1, #0x1f
    bhi lbl_0808aa18
    movs r3, #0
    ldrb r1, [r5, #3]
    cmp r3, r1
    bhs lbl_0808aa20
    adds r4, r5, #0
    ldr r6, lbl_0808aa14 @ =0x030058da
    lsls r7, r0, #1
    movs r2, #0xa0
    adds r2, r2, r5
    mov ip, r2
lbl_0808a9e2:
    lsls r0, r3, #1
    add r0, sp
    ldrh r2, [r0]
    ldrh r1, [r4, #0x16]
    adds r0, r2, r1
    strh r0, [r4, #0x16]
    ldrh r0, [r6]
    orrs r0, r2
    strh r0, [r6]
    ldrb r0, [r4, #0x19]
    lsls r0, r0, #6
    adds r0, r7, r0
    lsls r1, r3, #7
    adds r0, r0, r1
    add r0, ip
    strh r2, [r0]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldrb r2, [r4, #3]
    cmp r3, r2
    blo lbl_0808a9e2
    b lbl_0808aa20
    .align 2, 0
lbl_0808aa10: .4byte 0x000001a1
lbl_0808aa14: .4byte 0x030058da
lbl_0808aa18:
    ldrb r1, [r5, #0x14]
    movs r0, #2
    orrs r0, r1
    strb r0, [r5, #0x14]
lbl_0808aa20:
    ldrb r0, [r5, #0x19]
    adds r0, #1
    strb r0, [r5, #0x19]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0808aa44
    ldr r2, lbl_0808aa4c @ =0x030058da
    ldrh r0, [r2]
    cmp r0, #0
    beq lbl_0808aa44
    ldr r0, lbl_0808aa50 @ =0x000001a1
    adds r1, r5, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    strh r0, [r2]
lbl_0808aa44:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808aa4c: .4byte 0x030058da
lbl_0808aa50: .4byte 0x000001a1

    thumb_func_start sub_0808aa54
sub_0808aa54: @ 0x0808aa54
    push {lr}
    ldr r0, lbl_0808aa8c @ =0x03005b60
    ldrb r1, [r0, #0x18]
    adds r3, r0, #0
    cmp r1, #2
    bne lbl_0808aa9e
    ldr r1, lbl_0808aa90 @ =0x0400012a
    ldrh r0, [r3, #0x16]
    strh r0, [r1]
    ldr r1, lbl_0808aa94 @ =0x030058d3
    ldrb r2, [r1]
    cmp r2, #0
    bne lbl_0808aa98
    adds r1, r3, #0
    adds r1, #0x9d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    subs r1, #1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1f
    bls lbl_0808aae8
    strb r2, [r1]
    b lbl_0808aae8
    .align 2, 0
lbl_0808aa8c: .4byte 0x03005b60
lbl_0808aa90: .4byte 0x0400012a
lbl_0808aa94: .4byte 0x030058d3
lbl_0808aa98:
    movs r0, #0
    strb r0, [r1]
    b lbl_0808aae8
lbl_0808aa9e:
    ldr r2, lbl_0808aac0 @ =0x030058d3
    cmp r1, #0
    bne lbl_0808aab2
    adds r0, r3, #0
    adds r0, #0x9d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0808aab2
    movs r0, #1
    strb r0, [r2]
lbl_0808aab2:
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0808aac8
    ldr r1, lbl_0808aac4 @ =0x0400012a
    movs r0, #0
    strh r0, [r1]
    b lbl_0808aae2
    .align 2, 0
lbl_0808aac0: .4byte 0x030058d3
lbl_0808aac4: .4byte 0x0400012a
lbl_0808aac8:
    ldr r2, lbl_0808aaec @ =0x0400012a
    adds r0, r3, #0
    adds r0, #0x9c
    ldrb r1, [r0]
    lsls r1, r1, #1
    ldrb r0, [r3, #0x18]
    lsls r0, r0, #6
    adds r1, r1, r0
    adds r0, r3, #0
    adds r0, #0x1c
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
lbl_0808aae2:
    ldrb r0, [r3, #0x18]
    adds r0, #1
    strb r0, [r3, #0x18]
lbl_0808aae8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808aaec: .4byte 0x0400012a

    thumb_func_start sub_0808aaf0
sub_0808aaf0: @ 0x0808aaf0
    push {lr}
    ldr r0, lbl_0808ab10 @ =0x03005b60
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0808ab0c
    ldr r2, lbl_0808ab14 @ =0x0400010e
    ldrh r1, [r2]
    ldr r0, lbl_0808ab18 @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0808ab1c @ =0x0400010c
    ldr r2, lbl_0808ab20 @ =0x0000ff7c
    adds r0, r2, #0
    strh r0, [r1]
lbl_0808ab0c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab10: .4byte 0x03005b60
lbl_0808ab14: .4byte 0x0400010e
lbl_0808ab18: .4byte 0x0000ff7f
lbl_0808ab1c: .4byte 0x0400010c
lbl_0808ab20: .4byte 0x0000ff7c

    thumb_func_start sub_0808ab24
sub_0808ab24: @ 0x0808ab24
    push {lr}
    ldr r1, lbl_0808ab38 @ =0x03005b60
    ldrb r0, [r1, #0x19]
    cmp r0, #2
    bne lbl_0808ab3c
    movs r0, #0
    strb r0, [r1, #0x18]
    strb r0, [r1, #0x19]
    b lbl_0808ab4c
    .align 2, 0
lbl_0808ab38: .4byte 0x03005b60
lbl_0808ab3c:
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0808ab4c
    ldr r0, lbl_0808ab50 @ =0x0400010e
    ldrh r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strh r1, [r0]
lbl_0808ab4c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab50: .4byte 0x0400010e

    thumb_func_start sub_0808ab54
sub_0808ab54: @ 0x0808ab54
    push {r4, r5, lr}
    ldr r2, lbl_0808ab94 @ =0x03005b60
    adds r0, r2, #0
    adds r0, #0x9d
    movs r1, #0
    strb r1, [r0]
    subs r0, #1
    strb r1, [r0]
    movs r0, #0
    adds r5, r2, #0
    adds r5, #0x1c
    ldr r4, lbl_0808ab98 @ =0x0000efff
lbl_0808ab6c:
    movs r1, #0
    adds r3, r0, #1
    lsls r2, r0, #6
lbl_0808ab72:
    lsls r0, r1, #1
    adds r0, r0, r2
    adds r0, r0, r5
    strh r4, [r0]
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x1f
    bls lbl_0808ab72
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_0808ab6c
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808ab94: .4byte 0x03005b60
lbl_0808ab98: .4byte 0x0000efff

    thumb_func_start sub_0808ab9c
sub_0808ab9c: @ 0x0808ab9c
    push {r4, r5, r6, r7, lr}
    ldr r2, lbl_0808abec @ =0x03005b60
    ldr r1, lbl_0808abf0 @ =0x000001a1
    adds r0, r2, r1
    movs r1, #0
    strb r1, [r0]
    movs r3, #0xd0
    lsls r3, r3, #1
    adds r0, r2, r3
    strb r1, [r0]
    adds r7, r2, #0
    adds r7, #0xa0
    ldr r6, lbl_0808abf4 @ =0x0000efff
lbl_0808abb6:
    movs r0, #0
    adds r5, r1, #1
    lsls r4, r1, #7
lbl_0808abbc:
    movs r1, #0
    adds r3, r0, #1
    lsls r2, r0, #6
lbl_0808abc2:
    lsls r0, r1, #1
    adds r0, r0, r2
    adds r0, r0, r4
    adds r0, r0, r7
    strh r6, [r0]
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x1f
    bls lbl_0808abc2
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_0808abbc
    lsls r0, r5, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0808abb6
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0808abec: .4byte 0x03005b60
lbl_0808abf0: .4byte 0x000001a1
lbl_0808abf4: .4byte 0x0000efff
