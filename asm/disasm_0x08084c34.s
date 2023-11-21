    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_08084c34
sub_08084c34: @ 0x08084c34
    push {r4, r5, lr}
    adds r3, r0, #0
    ldr r1, lbl_08084c78 @ =sNonGameplayRamPointer
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
lbl_08084c78: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08084c7c
sub_08084c7c: @ 0x08084c7c
    push {r4, r5, r6, r7, lr}
    adds r2, r0, #0
    ldr r3, lbl_08084d04 @ =sNonGameplayRamPointer
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
lbl_08084d04: .4byte sNonGameplayRamPointer
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
    ldr r1, lbl_08084f08 @ =sNonGameplayRamPointer
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
lbl_08084f08: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_080850c8 @ =gInGameTimer
    ldrb r4, [r0]
    ldr r6, lbl_080850cc @ =0x085a0a30
    ldr r7, lbl_080850d0 @ =0x085a0cb0
    ldr r2, lbl_080850d4 @ =sNonGameplayRamPointer
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
lbl_080850c8: .4byte gInGameTimer
lbl_080850cc: .4byte 0x085a0a30
lbl_080850d0: .4byte 0x085a0cb0
lbl_080850d4: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08085218 @ =gOamData
    str r0, [r6]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r6, #4]
    ldr r0, lbl_0808521c @ =0x84000100
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    ldr r0, lbl_08085220 @ =sNonGameplayRamPointer
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
lbl_08085218: .4byte gOamData
lbl_0808521c: .4byte 0x84000100
lbl_08085220: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_080852fc @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_08085300 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_08085304 @ =0x04000054
    ldr r0, lbl_08085308 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0x42
    ldr r0, lbl_0808530c @ =gBg0YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #4
    subs r3, #0xc1
    adds r2, r3, #0
    ands r0, r2
    strh r0, [r1]
    adds r1, #4
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_08085310 @ =gBg2YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #4
    ands r0, r2
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_08085314 @ =gBg3YPosition
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
lbl_080852fc: .4byte gWrittenToBLDALPHA_H
lbl_08085300: .4byte gWrittenToBLDALPHA_L
lbl_08085304: .4byte 0x04000054
lbl_08085308: .4byte gWrittenToBLDY_NonGameplay
lbl_0808530c: .4byte gBg0YPosition
lbl_08085310: .4byte gBg2YPosition
lbl_08085314: .4byte gBg3YPosition

    thumb_func_start vblank_code_during_end_screen
vblank_code_during_end_screen: @ 0x08085318
    ldr r1, lbl_08085384 @ =0x040000d4
    ldr r0, lbl_08085388 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0808538c @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldr r0, lbl_08085390 @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08085398 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0808539c @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_080853a0 @ =0x04000054
    ldr r0, lbl_080853a4 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_080853a8 @ =0x04000014
    ldr r0, lbl_080853ac @ =gBg1XPosition
    ldrh r2, [r0]
    ldr r1, lbl_080853b0 @ =0x000001ff
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    adds r3, #4
    ldr r0, lbl_080853b4 @ =gBg2XPosition
    ldrh r2, [r0]
    adds r0, r1, #0
    ands r0, r2
    strh r0, [r3]
    ldr r2, lbl_080853b8 @ =0x0400001c
    ldr r0, lbl_080853bc @ =gBg3XPosition
    ldrh r0, [r0]
    ands r1, r0
    strh r1, [r2]
    bx lr
    .align 2, 0
lbl_08085384: .4byte 0x040000d4
lbl_08085388: .4byte gOamData
lbl_0808538c: .4byte 0x84000100
lbl_08085390: .4byte sNonGameplayRamPointer
lbl_08085394: .4byte 0x000002c2
lbl_08085398: .4byte gWrittenToBLDALPHA_H
lbl_0808539c: .4byte gWrittenToBLDALPHA_L
lbl_080853a0: .4byte 0x04000054
lbl_080853a4: .4byte gWrittenToBLDY_NonGameplay
lbl_080853a8: .4byte 0x04000014
lbl_080853ac: .4byte gBg1XPosition
lbl_080853b0: .4byte 0x000001ff
lbl_080853b4: .4byte gBg2XPosition
lbl_080853b8: .4byte 0x0400001c
lbl_080853bc: .4byte gBg3XPosition

    thumb_func_start vblank_code_during_unlocked_options
vblank_code_during_unlocked_options: @ 0x080853c0
    push {r4, lr}
    ldr r1, lbl_0808543c @ =0x040000d4
    ldr r0, lbl_08085440 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_08085444 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_08085448 @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08085454 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_08085458 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0808545c @ =0x04000054
    ldr r0, lbl_08085460 @ =gWrittenToBLDY_NonGameplay
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
lbl_08085440: .4byte gOamData
lbl_08085444: .4byte 0x84000100
lbl_08085448: .4byte sNonGameplayRamPointer
lbl_0808544c: .4byte 0x000002c2
lbl_08085450: .4byte 0x04000052
lbl_08085454: .4byte gWrittenToBLDALPHA_H
lbl_08085458: .4byte gWrittenToBLDALPHA_L
lbl_0808545c: .4byte 0x04000054
lbl_08085460: .4byte gWrittenToBLDY_NonGameplay

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
    ldr r0, lbl_080855cc @ =gNonGameplayRAM
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
    ldr r0, lbl_08085618 @ =gNextOamSlot
    strb r6, [r0]
    bl ResetFreeOam
    ldr r0, lbl_0808561c @ =gBg0XPosition
    strh r5, [r0]
    ldr r0, lbl_08085620 @ =gBg0YPosition
    movs r1, #0x80
    lsls r1, r1, #5
    adds r2, r1, #0
    strh r2, [r0]
    ldr r0, lbl_08085624 @ =gBg1XPosition
    strh r5, [r0]
    ldr r0, lbl_08085628 @ =gBg1YPosition
    strh r2, [r0]
    ldr r0, lbl_0808562c @ =gBg2XPosition
    strh r5, [r0]
    ldr r0, lbl_08085630 @ =gBg2YPosition
    strh r5, [r0]
    ldr r0, lbl_08085634 @ =gBg3XPosition
    strh r5, [r0]
    ldr r0, lbl_08085638 @ =gBg3YPosition
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
    ldr r0, lbl_08085648 @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08085650 @ =gWrittenToBLDALPHA_L
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08085654 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    ldr r0, lbl_08085658 @ =gWrittenToBLDY_NonGameplay
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
lbl_080855cc: .4byte gNonGameplayRAM
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
lbl_08085618: .4byte gNextOamSlot
lbl_0808561c: .4byte gBg0XPosition
lbl_08085620: .4byte gBg0YPosition
lbl_08085624: .4byte gBg1XPosition
lbl_08085628: .4byte gBg1YPosition
lbl_0808562c: .4byte gBg2XPosition
lbl_08085630: .4byte gBg2YPosition
lbl_08085634: .4byte gBg3XPosition
lbl_08085638: .4byte gBg3YPosition
lbl_0808563c: .4byte 0x04000010
lbl_08085640: .4byte 0x04000014
lbl_08085644: .4byte 0x04000016
lbl_08085648: .4byte sNonGameplayRamPointer
lbl_0808564c: .4byte 0x000002c2
lbl_08085650: .4byte gWrittenToBLDALPHA_L
lbl_08085654: .4byte gWrittenToBLDALPHA_H
lbl_08085658: .4byte gWrittenToBLDY_NonGameplay

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
    ldr r5, lbl_080856cc @ =sNonGameplayRamPointer
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
lbl_080856cc: .4byte sNonGameplayRamPointer
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
    ldr r3, lbl_0808577c @ =sNonGameplayRamPointer
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
lbl_0808577c: .4byte sNonGameplayRamPointer
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
    ldr r3, lbl_08085820 @ =sNonGameplayRamPointer
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
lbl_08085820: .4byte sNonGameplayRamPointer
lbl_08085824:
    movs r6, #0
    mov r0, ip
    adds r0, #0xe0
    ldr r3, lbl_0808584c @ =sNonGameplayRamPointer
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
lbl_0808584c: .4byte sNonGameplayRamPointer
lbl_08085850:
    movs r6, #0
    ldr r3, lbl_08085878 @ =sNonGameplayRamPointer
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
lbl_08085878: .4byte sNonGameplayRamPointer
lbl_0808587c:
    movs r6, #0
    ldr r3, lbl_080858a4 @ =sNonGameplayRamPointer
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
lbl_080858a4: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08085928 @ =sNonGameplayRamPointer
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
lbl_08085928: .4byte sNonGameplayRamPointer
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

    thumb_func_start CreditsDisplay
CreditsDisplay: @ 0x080859f4
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08085a24 @ =sNonGameplayRamPointer
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
lbl_08085a24: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08085a54 @ =gWrittenToBLDY_NonGameplay
    strh r4, [r0]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    b lbl_08085a6c
    .align 2, 0
lbl_08085a4c: .4byte 0x000002c2
lbl_08085a50: .4byte 0x00000441
lbl_08085a54: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r1, lbl_08085a98 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085acc
    subs r0, #1
    strh r0, [r1]
    b lbl_08085acc
    .align 2, 0
lbl_08085a94: .4byte 0x000002c2
lbl_08085a98: .4byte gWrittenToBLDY_NonGameplay
lbl_08085a9c:
    cmp r0, #3
    bne lbl_08085acc
    ldrh r1, [r2, #4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08085acc
    ldr r1, lbl_08085ac0 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085ac8
    subs r0, #1
    strh r0, [r1]
    ldr r2, lbl_08085ac4 @ =gWrittenToBLDALPHA_H
    movs r1, #0x10
    subs r1, r1, r0
    strh r1, [r2]
    b lbl_08085acc
    .align 2, 0
lbl_08085ac0: .4byte gWrittenToBLDALPHA_L
lbl_08085ac4: .4byte gWrittenToBLDALPHA_H
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
    ldr r1, lbl_08085b7c @ =gBg0YPosition
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
lbl_08085b7c: .4byte gBg0YPosition

    thumb_func_start CreditsChozoWallMovement
CreditsChozoWallMovement: @ 0x08085b80
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_08085ba0 @ =sNonGameplayRamPointer
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
lbl_08085ba0: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08085c04 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrb r0, [r3, #1]
    cmp r0, #0
    beq lbl_08085bf6
    ldr r0, lbl_08085c08 @ =gBg2YPosition
    ldrh r1, [r0]
    adds r1, #8
    strh r1, [r0]
    ldr r2, lbl_08085c0c @ =gBg3YPosition
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
lbl_08085c04: .4byte sNonGameplayRamPointer
lbl_08085c08: .4byte gBg2YPosition
lbl_08085c0c: .4byte gBg3YPosition

    thumb_func_start CreditsChozoWallZoom
CreditsChozoWallZoom: @ 0x08085c10
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_08085c3c @ =sNonGameplayRamPointer
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
lbl_08085c3c: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08085ca4 @ =gBg0YPosition
    strh r5, [r0]
    ldr r0, lbl_08085ca8 @ =gWrittenToBLDALPHA_L
    strh r5, [r0]
    ldr r1, lbl_08085cac @ =gWrittenToBLDALPHA_H
    movs r0, #0x10
    strh r0, [r1]
    b lbl_08085d80
    .align 2, 0
lbl_08085c94: .4byte 0x085bed94
lbl_08085c98: .4byte 0x040000d4
lbl_08085c9c: .4byte 0x0854a734
lbl_08085ca0: .4byte 0x800000f0
lbl_08085ca4: .4byte gBg0YPosition
lbl_08085ca8: .4byte gWrittenToBLDALPHA_L
lbl_08085cac: .4byte gWrittenToBLDALPHA_H
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
    ldr r0, lbl_08085d18 @ =gBg1YPosition
    strh r5, [r0]
    ldr r1, lbl_08085d1c @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08085d20 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    b lbl_08085d80
    .align 2, 0
lbl_08085d14: .4byte 0x000002c2
lbl_08085d18: .4byte gBg1YPosition
lbl_08085d1c: .4byte gWrittenToBLDALPHA_L
lbl_08085d20: .4byte gWrittenToBLDALPHA_H
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
    ldr r0, lbl_08085dac @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r1, [r0, #1]
    cmp r1, #1
    bne lbl_08085db8
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085db0 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08085da0
    adds r0, #1
    strh r0, [r1]
lbl_08085da0:
    ldr r1, lbl_08085db4 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085dfa
    subs r0, #1
    b lbl_08085df8
    .align 2, 0
lbl_08085dac: .4byte sNonGameplayRamPointer
lbl_08085db0: .4byte gWrittenToBLDALPHA_L
lbl_08085db4: .4byte gWrittenToBLDALPHA_H
lbl_08085db8:
    cmp r1, #3
    bne lbl_08085de0
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085dd8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08085dd2
    subs r0, #1
    strh r0, [r1]
lbl_08085dd2:
    ldr r1, lbl_08085ddc @ =gWrittenToBLDALPHA_H
    b lbl_08085df0
    .align 2, 0
lbl_08085dd8: .4byte gWrittenToBLDALPHA_L
lbl_08085ddc: .4byte gWrittenToBLDALPHA_H
lbl_08085de0:
    cmp r1, #4
    bne lbl_08085dfa
    ldrh r1, [r0, #4]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08085dfa
    ldr r1, lbl_08085e04 @ =gWrittenToBLDY_NonGameplay
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
lbl_08085e04: .4byte gWrittenToBLDY_NonGameplay

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
    ldr r0, lbl_08086008 @ =gNextOamSlot
    strb r5, [r0]
    bl ResetFreeOam
    ldr r0, lbl_0808600c @ =gOamData
    str r0, [r4]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r4, #4]
    ldr r0, lbl_08086010 @ =0x84000100
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r0, lbl_08086014 @ =gBg0XPosition
    strh r5, [r0]
    ldr r0, lbl_08086018 @ =gBg0YPosition
    strh r5, [r0]
    ldr r0, lbl_0808601c @ =gBg1XPosition
    movs r2, #0x80
    lsls r2, r2, #1
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_08086020 @ =gBg1YPosition
    strh r5, [r0]
    ldr r0, lbl_08086024 @ =gBg2XPosition
    strh r1, [r0]
    ldr r0, lbl_08086028 @ =gBg2YPosition
    strh r5, [r0]
    ldr r0, lbl_0808602c @ =gBg3XPosition
    strh r5, [r0]
    ldr r0, lbl_08086030 @ =gBg3YPosition
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
    ldr r0, lbl_08086038 @ =gNonGameplayRAM
    str r0, [r4, #4]
    ldr r0, lbl_0808603c @ =0x8500018a
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    bl ChozodiaEscapeGetItemCountAndEndingNumber
    ldr r3, lbl_08086040 @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08086044 @ =gWrittenToBLDALPHA_L
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086048 @ =gWrittenToBLDALPHA_H
    strh r5, [r0]
    ldr r0, lbl_0808604c @ =gWrittenToBLDY_NonGameplay
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
lbl_08086008: .4byte gNextOamSlot
lbl_0808600c: .4byte gOamData
lbl_08086010: .4byte 0x84000100
lbl_08086014: .4byte gBg0XPosition
lbl_08086018: .4byte gBg0YPosition
lbl_0808601c: .4byte gBg1XPosition
lbl_08086020: .4byte gBg1YPosition
lbl_08086024: .4byte gBg2XPosition
lbl_08086028: .4byte gBg2YPosition
lbl_0808602c: .4byte gBg3XPosition
lbl_08086030: .4byte gBg3YPosition
lbl_08086034: .4byte 0x04000010
lbl_08086038: .4byte gNonGameplayRAM
lbl_0808603c: .4byte 0x8500018a
lbl_08086040: .4byte sNonGameplayRamPointer
lbl_08086044: .4byte gWrittenToBLDALPHA_L
lbl_08086048: .4byte gWrittenToBLDALPHA_H
lbl_0808604c: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start EndScreenSamusPosing
EndScreenSamusPosing: @ 0x08086050
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r1, lbl_08086074 @ =sNonGameplayRamPointer
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
lbl_08086074: .4byte sNonGameplayRamPointer
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
    ldr r2, lbl_080860e0 @ =gBg1XPosition
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
lbl_080860e0: .4byte gBg1XPosition
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
    ldr r2, lbl_08086154 @ =gBg2XPosition
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
lbl_08086154: .4byte gBg2XPosition
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
    ldr r1, lbl_080861a4 @ =gBg1XPosition
    ldrh r0, [r1]
    cmp r0, #9
    bls lbl_080861a8
    subs r0, #0xa
    strh r0, [r1]
    b lbl_0808622a
    .align 2, 0
lbl_080861a4: .4byte gBg1XPosition
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
    ldr r0, lbl_08086284 @ =gWrittenToBLDALPHA_L
    ldrh r2, [r0]
    adds r3, r2, #0
    adds r1, r0, #0
    cmp r3, #0
    beq lbl_08086288
    subs r0, r2, #1
    strh r0, [r1]
    b lbl_0808629c
    .align 2, 0
lbl_08086284: .4byte gWrittenToBLDALPHA_L
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
    ldr r2, lbl_080862ac @ =gWrittenToBLDALPHA_H
    ldrh r1, [r1]
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    b lbl_08086388
    .align 2, 0
lbl_080862a8: .4byte 0x00000125
lbl_080862ac: .4byte gWrittenToBLDALPHA_H
lbl_080862b0:
    ldr r2, [r5]
    ldrb r0, [r2, #2]
    movs r1, #3
    ands r1, r0
    cmp r1, #0
    bne lbl_08086388
    ldr r3, lbl_080862cc @ =gWrittenToBLDALPHA_L
    ldrh r0, [r3]
    cmp r0, #0xf
    bhi lbl_08086374
    adds r0, #1
    strh r0, [r3]
    b lbl_08086388
    .align 2, 0
lbl_080862cc: .4byte gWrittenToBLDALPHA_L
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
    ldr r1, lbl_08086344 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08086348
    adds r0, #1
    strh r0, [r1]
    b lbl_08086388
    .align 2, 0
lbl_08086344: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r3, lbl_08086370 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08086374
    subs r0, #1
    strh r0, [r3]
    b lbl_08086388
    .align 2, 0
lbl_08086370: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r0, lbl_0808648c @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldr r1, lbl_08086490 @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086494 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08086498 @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r1, lbl_0808649c @ =gBg1XPosition
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
lbl_0808648c: .4byte sNonGameplayRamPointer
lbl_08086490: .4byte 0x000002c2
lbl_08086494: .4byte gWrittenToBLDALPHA_L
lbl_08086498: .4byte gWrittenToBLDALPHA_H
lbl_0808649c: .4byte gBg1XPosition
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
    ldr r0, lbl_08086508 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldr r1, lbl_0808650c @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086510 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08086514 @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r1, lbl_08086518 @ =gBg2XPosition
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
lbl_08086508: .4byte sNonGameplayRamPointer
lbl_0808650c: .4byte 0x000002c2
lbl_08086510: .4byte gWrittenToBLDALPHA_L
lbl_08086514: .4byte gWrittenToBLDALPHA_H
lbl_08086518: .4byte gBg2XPosition
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
    ldr r0, lbl_08086580 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldr r1, lbl_08086584 @ =0x000002c2
    adds r0, r3, r1
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08086588 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_0808658c @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r1, lbl_08086590 @ =gBg1XPosition
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
lbl_08086580: .4byte sNonGameplayRamPointer
lbl_08086584: .4byte 0x000002c2
lbl_08086588: .4byte gWrittenToBLDALPHA_L
lbl_0808658c: .4byte gWrittenToBLDALPHA_H
lbl_08086590: .4byte gBg1XPosition
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
    ldr r0, lbl_080865cc @ =sNonGameplayRamPointer
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
lbl_080865cc: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08086650 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086658 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_0808665c @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r0, lbl_08086660 @ =gBg2XPosition
    strh r2, [r0]
    ldr r2, lbl_08086664 @ =0x00000125
    adds r1, r3, r2
    b lbl_0808673a
    .align 2, 0
lbl_08086640: .4byte 0x085ade64
lbl_08086644: .4byte 0x06008000
lbl_08086648: .4byte 0x085af0a0
lbl_0808664c: .4byte 0x0600e000
lbl_08086650: .4byte sNonGameplayRamPointer
lbl_08086654: .4byte 0x000002c2
lbl_08086658: .4byte gWrittenToBLDALPHA_L
lbl_0808665c: .4byte gWrittenToBLDALPHA_H
lbl_08086660: .4byte gBg2XPosition
lbl_08086664: .4byte 0x00000125
lbl_08086668:
    ldr r4, lbl_0808669c @ =sNonGameplayRamPointer
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
    ldr r0, lbl_080866a8 @ =gWrittenToBLDALPHA_L
    strh r3, [r0]
    ldr r1, lbl_080866ac @ =gWrittenToBLDALPHA_H
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
lbl_0808669c: .4byte sNonGameplayRamPointer
lbl_080866a0: .4byte 0x000002c2
lbl_080866a4: .4byte 0x00000c41
lbl_080866a8: .4byte gWrittenToBLDALPHA_L
lbl_080866ac: .4byte gWrittenToBLDALPHA_H
lbl_080866b0:
    ldr r3, lbl_080866dc @ =sNonGameplayRamPointer
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
lbl_080866dc: .4byte sNonGameplayRamPointer
lbl_080866e0: .4byte 0x000002c2
lbl_080866e4: .4byte 0x00000125
lbl_080866e8:
    ldr r3, lbl_08086714 @ =sNonGameplayRamPointer
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
lbl_08086714: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08086750 @ =sNonGameplayRamPointer
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
lbl_08086750: .4byte sNonGameplayRamPointer
lbl_08086754: .4byte 0x00000125
lbl_08086758:
    ldr r0, lbl_080867a0 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_080867a8 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_080867ac @ =gWrittenToBLDALPHA_H
    strh r3, [r0]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_08086782:
    ldr r0, lbl_080867a0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r1, [r0, #2]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08086798
    ldr r1, lbl_080867b0 @ =gBg3XPosition
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_08086798:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080867a0: .4byte sNonGameplayRamPointer
lbl_080867a4: .4byte 0x000002c2
lbl_080867a8: .4byte gWrittenToBLDALPHA_L
lbl_080867ac: .4byte gWrittenToBLDALPHA_H
lbl_080867b0: .4byte gBg3XPosition

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
    ldr r0, lbl_080868ec @ =gNonGameplayRAM
    str r0, [r6, #4]
    ldr r0, lbl_080868f0 @ =0x8500018a
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    bl ChozodiaEscapeGetItemCountAndEndingNumber
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
    ldr r4, lbl_08086920 @ =sNonGameplayRamPointer
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
    ldr r2, lbl_0808692c @ =gLanguage
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
lbl_080868ec: .4byte gNonGameplayRAM
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
lbl_08086920: .4byte sNonGameplayRamPointer
lbl_08086924: .4byte 0x085a0f30
lbl_08086928: .4byte 0x06010000
lbl_0808692c: .4byte gLanguage
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
    ldr r1, lbl_08086a14 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    bl ResetFreeOam
    ldr r0, lbl_08086a18 @ =gBg0XPosition
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08086a1c @ =gBg0YPosition
    movs r3, #0x80
    lsls r3, r3, #5
    adds r2, r3, #0
    strh r2, [r0]
    ldr r0, lbl_08086a20 @ =gBg1XPosition
    strh r1, [r0]
    ldr r0, lbl_08086a24 @ =gBg1YPosition
    strh r2, [r0]
    ldr r0, lbl_08086a28 @ =gBg2XPosition
    strh r1, [r0]
    ldr r0, lbl_08086a2c @ =gBg2YPosition
    strh r1, [r0]
    ldr r0, lbl_08086a30 @ =gBg3XPosition
    strh r1, [r0]
    ldr r0, lbl_08086a34 @ =gBg3YPosition
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
    ldr r0, lbl_08086a3c @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08086a44 @ =gWrittenToBLDALPHA_L
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086a48 @ =gWrittenToBLDALPHA_H
    strh r3, [r0]
    ldr r0, lbl_08086a4c @ =gWrittenToBLDY_NonGameplay
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
lbl_08086a14: .4byte gNextOamSlot
lbl_08086a18: .4byte gBg0XPosition
lbl_08086a1c: .4byte gBg0YPosition
lbl_08086a20: .4byte gBg1XPosition
lbl_08086a24: .4byte gBg1YPosition
lbl_08086a28: .4byte gBg2XPosition
lbl_08086a2c: .4byte gBg2YPosition
lbl_08086a30: .4byte gBg3XPosition
lbl_08086a34: .4byte gBg3YPosition
lbl_08086a38: .4byte 0x04000010
lbl_08086a3c: .4byte sNonGameplayRamPointer
lbl_08086a40: .4byte 0x000002c2
lbl_08086a44: .4byte gWrittenToBLDALPHA_L
lbl_08086a48: .4byte gWrittenToBLDALPHA_H
lbl_08086a4c: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start ending_image_display_text
ending_image_display_text: @ 0x08086a50
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r5, lbl_08086ab8 @ =gOamData
    movs r0, #0
    mov sl, r0
    movs r7, #0
    movs r4, #0
    ldr r1, lbl_08086abc @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r7, r0
    blt lbl_08086a72
    b lbl_08086ba0
lbl_08086a72:
    ldr r2, lbl_08086abc @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086abc @ =sNonGameplayRamPointer
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
lbl_08086ab8: .4byte gOamData
lbl_08086abc: .4byte sNonGameplayRamPointer
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
    ldr r2, lbl_08086c60 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldr r1, lbl_08086c64 @ =0x00000165
    adds r2, r0, r1
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r2, lbl_08086c60 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086c60 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086c60 @ =sNonGameplayRamPointer
    mov r8, r1
    lsls r6, r4, #1
    lsls r0, r7, #3
    ldr r2, lbl_08086c6c @ =gOamData
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
    ldr r2, lbl_08086c60 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x9b
    ldrb r0, [r0]
    cmp r4, r0
    bge lbl_08086ba0
    b lbl_08086a72
lbl_08086ba0:
    ldr r4, lbl_08086c60 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086c60 @ =sNonGameplayRamPointer
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
    ldr r1, lbl_08086c6c @ =gOamData
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
    ldr r0, lbl_08086c88 @ =gNextOamSlot
    strb r7, [r0]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08086c60: .4byte sNonGameplayRamPointer
lbl_08086c64: .4byte 0x00000165
lbl_08086c68: .4byte 0x0854e2dc
lbl_08086c6c: .4byte gOamData
lbl_08086c70: .4byte 0x000001ff
lbl_08086c74: .4byte 0xfffffe00
lbl_08086c78: .4byte 0x00000141
lbl_08086c7c: .4byte 0x0000017d
lbl_08086c80: .4byte 0x0854e2e4
lbl_08086c84: .4byte 0x08549eec
lbl_08086c88: .4byte gNextOamSlot

    thumb_func_start EndingImageDisplay
EndingImageDisplay: @ 0x08086c8c
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r4, lbl_08086cbc @ =sNonGameplayRamPointer
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
lbl_08086cbc: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08086d50 @ =gEndingFlags
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
lbl_08086d50: .4byte gEndingFlags
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
    ldr r0, lbl_08086dcc @ =gChangedInput
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
lbl_08086dcc: .4byte gChangedInput
lbl_08086dd0:
    strh r3, [r2, #4]
    b lbl_08086dd6
lbl_08086dd4:
    movs r6, #1
lbl_08086dd6:
    ldr r0, lbl_08086df8 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2, #8]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08086e10
    ldr r1, lbl_08086dfc @ =gBg0YPosition
    ldrh r0, [r1]
    cmp r0, #6
    bls lbl_08086e04
    subs r0, #6
    strh r0, [r1]
    ldr r1, lbl_08086e00 @ =gBg1YPosition
    ldrh r0, [r1]
    subs r0, #6
    strh r0, [r1]
    b lbl_08086e10
    .align 2, 0
lbl_08086df8: .4byte sNonGameplayRamPointer
lbl_08086dfc: .4byte gBg0YPosition
lbl_08086e00: .4byte gBg1YPosition
lbl_08086e04:
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_08086e68 @ =gBg1YPosition
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
    ldr r0, lbl_08086e74 @ =gButtonInput
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
lbl_08086e68: .4byte gBg1YPosition
lbl_08086e6c: .4byte 0x00000564
lbl_08086e70: .4byte 0x00000329
lbl_08086e74: .4byte gButtonInput

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
    ldr r0, lbl_08086f84 @ =gNonGameplayRAM
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
    ldr r0, lbl_08086fb4 @ =gNextOamSlot
    mov r1, r8
    strb r1, [r0]
    bl ResetFreeOam
    ldr r0, lbl_08086fb8 @ =0x04000010
    strh r6, [r0]
    adds r0, #2
    strh r6, [r0]
    ldr r0, lbl_08086fbc @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0xb0
    lsls r2, r2, #2
    adds r1, r0, r2
    strh r6, [r1]
    ldr r1, lbl_08086fc0 @ =0x000002c2
    adds r0, r0, r1
    strh r6, [r0]
    ldr r0, lbl_08086fc4 @ =gWrittenToBLDALPHA_L
    movs r1, #0x10
    strh r1, [r0]
    ldr r0, lbl_08086fc8 @ =gWrittenToBLDALPHA_H
    strh r6, [r0]
    ldr r0, lbl_08086fcc @ =gWrittenToBLDY_NonGameplay
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
lbl_08086f84: .4byte gNonGameplayRAM
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
lbl_08086fb4: .4byte gNextOamSlot
lbl_08086fb8: .4byte 0x04000010
lbl_08086fbc: .4byte sNonGameplayRamPointer
lbl_08086fc0: .4byte 0x000002c2
lbl_08086fc4: .4byte gWrittenToBLDALPHA_L
lbl_08086fc8: .4byte gWrittenToBLDALPHA_H
lbl_08086fcc: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start UnlockedOptionsPopUp
UnlockedOptionsPopUp: @ 0x08086fd0
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r3, lbl_08086ff4 @ =sNonGameplayRamPointer
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
lbl_08086ff4: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08087024 @ =gEndingFlags
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08087028
    movs r1, #0x21
    b lbl_08087040
    .align 2, 0
lbl_08087024: .4byte gEndingFlags
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
    bl TextStartFileScreen
    ldr r0, lbl_08087058 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    strb r1, [r0]
    b lbl_080870aa
    .align 2, 0
lbl_08087058: .4byte sNonGameplayRamPointer
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
    ldr r4, lbl_08087108 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080870c8
    bl TextProcessFileScreenPopUp
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
lbl_08087108: .4byte sNonGameplayRamPointer
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
    ldr r0, lbl_08087170 @ =gChangedInput
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
lbl_08087170: .4byte gChangedInput
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
    ldr r0, lbl_080871c8 @ =gEndingFlags
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080871cc
    adds r0, r5, #1
    b lbl_080871ce
    .align 2, 0
lbl_080871c8: .4byte gEndingFlags
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

    thumb_func_start CreditsSubroutine
CreditsSubroutine: @ 0x080871dc
    push {r4, r5, lr}
    movs r5, #0
    ldr r1, lbl_08087204 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    strb r5, [r0, #6]
    ldr r0, lbl_08087208 @ =gNextOamSlot
    strb r5, [r0]
    ldr r0, lbl_0808720c @ =gGameModeSub1
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
lbl_08087204: .4byte sNonGameplayRamPointer
lbl_08087208: .4byte gNextOamSlot
lbl_0808720c: .4byte gGameModeSub1
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
    ldr r1, lbl_0808729c @ =gGameModeSub1
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_0808734a
    .align 2, 0
lbl_08087298: .4byte 0x08760cf8
lbl_0808729c: .4byte gGameModeSub1
lbl_080872a0:
    ldr r1, lbl_080872ac @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r1]
    cmp r0, #0xf
    bls lbl_08087380
    b lbl_08087360
    .align 2, 0
lbl_080872ac: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r3, lbl_080872ec @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080872f0
    subs r0, #1
    strh r0, [r3]
    b lbl_080873d0
    .align 2, 0
lbl_080872ec: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r0, lbl_08087338 @ =gEndingFlags
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
    ldr r0, lbl_08087340 @ =gWrittenToBLDY_NonGameplay
    strh r2, [r0]
    b lbl_0808728c
    .align 2, 0
lbl_08087334: .4byte 0x08760d08
lbl_08087338: .4byte gEndingFlags
lbl_0808733c: .4byte 0x000002c2
lbl_08087340: .4byte gWrittenToBLDY_NonGameplay
lbl_08087344:
    ldr r0, lbl_08087350 @ =gDisableSoftreset
    strb r1, [r0]
    adds r5, #1
lbl_0808734a:
    bl ResetFreeOam
    b lbl_080873d0
    .align 2, 0
lbl_08087350: .4byte gDisableSoftreset
lbl_08087354:
    ldr r0, lbl_08087368 @ =gEndingFlags
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
lbl_08087368: .4byte gEndingFlags
lbl_0808736c:
    ldr r0, lbl_08087374 @ =gDisableSoftreset
    strb r1, [r0]
    adds r5, #1
    b lbl_080873d0
    .align 2, 0
lbl_08087374: .4byte gDisableSoftreset
lbl_08087378:
    bl unlocked_options_init
lbl_0808737c:
    ldr r1, lbl_08087388 @ =gGameModeSub1
    ldrh r0, [r1]
lbl_08087380:
    adds r0, #1
    strh r0, [r1]
    b lbl_080873d0
    .align 2, 0
lbl_08087388: .4byte gGameModeSub1
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
    ldr r1, lbl_080873dc @ =gEndingFlags
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
    ldr r1, lbl_080873e0 @ =gGameModeSub1
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_080873cc:
    bl ResetFreeOam
lbl_080873d0:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080873d8: .4byte 0x08760d0c
lbl_080873dc: .4byte gEndingFlags
lbl_080873e0: .4byte gGameModeSub1

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
    ldr r0, lbl_08087494 @ =gGameModeSub1
    movs r1, #0
    ldrsh r4, [r0, r1]
    cmp r4, #0
    bne lbl_08087440
    bl ClearGfxRam
    str r4, [sp, #4]
    ldr r1, lbl_08087498 @ =0x040000d4
    add r2, sp, #4
    str r2, [r1]
    ldr r0, lbl_0808749c @ =gNonGameplayRAM
    str r0, [r1, #4]
    ldr r0, lbl_080874a0 @ =0x8500018a
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08087440:
    ldr r2, lbl_080874a4 @ =sNonGameplayRamPointer
    ldr r3, [r2]
    adds r0, r3, #0
    adds r0, #0x98
    ldrb r4, [r0]
    movs r5, #0
    movs r0, #1
    lsls r0, r4
    ldr r6, lbl_080874a8 @ =gFileScreenOptionsUnlocked
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
lbl_08087494: .4byte gGameModeSub1
lbl_08087498: .4byte 0x040000d4
lbl_0808749c: .4byte gNonGameplayRAM
lbl_080874a0: .4byte 0x8500018a
lbl_080874a4: .4byte sNonGameplayRamPointer
lbl_080874a8: .4byte gFileScreenOptionsUnlocked
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
    ldr r0, lbl_080875f0 @ =gNextOamSlot
    strb r5, [r0]
    bl ResetFreeOam
    ldr r0, lbl_080875f4 @ =gBg0XPosition
    strh r5, [r0]
    ldr r0, lbl_080875f8 @ =gBg0YPosition
    movs r2, #0x80
    lsls r2, r2, #5
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_080875fc @ =gBg1XPosition
    strh r5, [r0]
    ldr r0, lbl_08087600 @ =gBg1YPosition
    strh r1, [r0]
    ldr r0, lbl_08087604 @ =gBg2XPosition
    strh r5, [r0]
    ldr r0, lbl_08087608 @ =gBg2YPosition
    strh r5, [r0]
    ldr r0, lbl_0808760c @ =gBg3XPosition
    strh r5, [r0]
    ldr r0, lbl_08087610 @ =gBg3YPosition
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
lbl_080875f0: .4byte gNextOamSlot
lbl_080875f4: .4byte gBg0XPosition
lbl_080875f8: .4byte gBg0YPosition
lbl_080875fc: .4byte gBg1XPosition
lbl_08087600: .4byte gBg1YPosition
lbl_08087604: .4byte gBg2XPosition
lbl_08087608: .4byte gBg2YPosition
lbl_0808760c: .4byte gBg3XPosition
lbl_08087610: .4byte gBg3YPosition
lbl_08087614: .4byte 0x04000010
lbl_08087618: .4byte 0x000002c2

    thumb_func_start gallery_display
gallery_display: @ 0x0808761c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, lbl_08087660 @ =sNonGameplayRamPointer
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
    ldr r0, lbl_08087664 @ =gChangedInput
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
    ldr r0, lbl_0808766c @ =gWrittenToBLDY_NonGameplay
    mov r1, r8
    strh r1, [r0]
    movs r0, #1
    mov r8, r0
    b lbl_080876b2
    .align 2, 0
lbl_08087660: .4byte sNonGameplayRamPointer
lbl_08087664: .4byte gChangedInput
lbl_08087668: .4byte 0x000002c2
lbl_0808766c: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r0, lbl_08087714 @ =gFileScreenOptionsUnlocked
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
    ldr r0, lbl_0808771c @ =gWrittenToBLDY_NonGameplay
    strh r2, [r0]
    ldr r1, lbl_08087720 @ =gGameModeSub1
    movs r0, #5
    strh r0, [r1]
lbl_080876da:
    movs r4, #0
    movs r3, #8
    ldr r0, [r7]
    ldrh r0, [r0, #8]
    cmp r0, #0
    beq lbl_080876f8
    ldr r0, lbl_08087724 @ =gButtonInput
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
    ldr r1, lbl_08087728 @ =gBg0YPosition
    ldrh r0, [r1]
    cmp r0, r3
    ble lbl_08087730
    subs r0, r0, r3
    strh r0, [r1]
    ldr r1, lbl_0808772c @ =gBg1YPosition
    ldrh r0, [r1]
    subs r0, r0, r3
    strh r0, [r1]
    b lbl_08087764
    .align 2, 0
lbl_08087714: .4byte gFileScreenOptionsUnlocked
lbl_08087718: .4byte 0x000002c2
lbl_0808771c: .4byte gWrittenToBLDY_NonGameplay
lbl_08087720: .4byte gGameModeSub1
lbl_08087724: .4byte gButtonInput
lbl_08087728: .4byte gBg0YPosition
lbl_0808772c: .4byte gBg1YPosition
lbl_08087730:
    strh r4, [r1]
    ldr r0, lbl_08087740 @ =gBg1YPosition
    strh r4, [r0]
    ldr r1, [r7]
    movs r0, #1
    strh r0, [r1, #8]
    b lbl_08087764
    .align 2, 0
lbl_08087740: .4byte gBg1YPosition
lbl_08087744:
    ldr r4, lbl_08087770 @ =gBg0YPosition
    ldrh r1, [r4]
    adds r1, r1, r3
    strh r1, [r4]
    ldr r2, lbl_08087774 @ =gBg1YPosition
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
lbl_08087770: .4byte gBg0YPosition
lbl_08087774: .4byte gBg1YPosition

    thumb_func_start GallerySubroutine
GallerySubroutine: @ 0x08087778
    push {r4, r5, r6, r7, lr}
    movs r6, #0
    ldr r0, lbl_0808779c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    strb r6, [r1, #6]
    ldr r1, lbl_080877a0 @ =gGameModeSub1
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
lbl_0808779c: .4byte sNonGameplayRamPointer
lbl_080877a0: .4byte gGameModeSub1
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
    ldr r1, lbl_080877cc @ =gGameModeSub1
    movs r0, #1
    strh r0, [r1]
    b lbl_08087844
    .align 2, 0
lbl_080877cc: .4byte gGameModeSub1
lbl_080877d0:
    ldr r2, lbl_080877e0 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r2]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080877e4
    subs r0, #1
    strh r0, [r2]
    b lbl_08087844
    .align 2, 0
lbl_080877e0: .4byte gWrittenToBLDY_NonGameplay
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
    ldr r1, lbl_0808780c @ =gGameModeSub1
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_08087844
    .align 2, 0
lbl_0808780c: .4byte gGameModeSub1
lbl_08087810:
    ldr r5, lbl_08087830 @ =gWrittenToBLDY_NonGameplay
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
lbl_08087830: .4byte gWrittenToBLDY_NonGameplay
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
