    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start MetroidCheckAirCollision
MetroidCheckAirCollision: @ 0x08035360
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r6, r4, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r7, #0
    ldr r0, lbl_0803539c @ =0x03001588
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_080353a4
    adds r0, r4, #0
    subs r0, #0x30
    adds r5, r1, #0
    adds r5, #0x3c
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_080353a0 @ =0x030007f1
    ldrb r0, [r6]
    cmp r0, #0
    bne lbl_080353ce
    adds r0, r4, #0
    adds r0, #0x10
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    b lbl_080353ca
    .align 2, 0
lbl_0803539c: .4byte 0x03001588
lbl_080353a0: .4byte 0x030007f1
lbl_080353a4:
    cmp r0, #1
    bne lbl_080353d0
    adds r0, r4, #0
    subs r0, #0x30
    adds r4, r1, #0
    subs r4, #0x3c
    adds r1, r4, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_080353d8 @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_080353ce
    adds r0, r6, #0
    adds r0, #0x10
    adds r1, r4, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r5]
lbl_080353ca:
    cmp r0, #0
    beq lbl_080353d0
lbl_080353ce:
    movs r7, #1
lbl_080353d0:
    adds r0, r7, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080353d8: .4byte 0x030007f1

    thumb_func_start MetroidMove
MetroidMove: @ 0x080353dc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    ldr r4, [sp, #0x34]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #4]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    str r2, [sp, #8]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0xc]
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    mov sb, r4
    movs r0, #0
    str r0, [sp, #0x10]
    mov sl, r0
    ldr r0, lbl_08035454 @ =0x03000738
    ldrh r6, [r0, #2]
    ldrh r7, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803545c
    adds r4, r6, #0
    subs r4, #0x30
    adds r5, r7, #0
    adds r5, #0x3c
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r1, lbl_08035458 @ =0x030007f1
    mov r8, r1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0803544c
    adds r0, r6, #0
    adds r0, #0x10
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    mov r1, r8
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08035496
lbl_0803544c:
    movs r3, #1
    str r3, [sp, #0x10]
    b lbl_08035496
    .align 2, 0
lbl_08035454: .4byte 0x03000738
lbl_08035458: .4byte 0x030007f1
lbl_0803545c:
    adds r4, r6, #0
    subs r4, #0x30
    adds r5, r7, #0
    subs r5, #0x3c
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803547c @ =0x030007f1
    mov r8, r0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08035480
    movs r1, #1
    str r1, [sp, #0x10]
    b lbl_08035496
    .align 2, 0
lbl_0803547c: .4byte 0x030007f1
lbl_08035480:
    adds r0, r6, #0
    adds r0, #0x10
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    mov r3, r8
    ldrb r0, [r3]
    cmp r0, #0
    beq lbl_08035496
    movs r0, #1
    str r0, [sp, #0x10]
lbl_08035496:
    ldr r0, lbl_08035514 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_080354a8
    adds r4, r6, #0
    adds r4, #0x18
lbl_080354a8:
    adds r1, r7, #0
    subs r1, #0x20
    adds r0, r4, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_08035518 @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_080354ca
    adds r1, r7, #0
    adds r1, #0x20
    adds r0, r4, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_080354d4
lbl_080354ca:
    mov r0, sl
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sl, r0
lbl_080354d4:
    movs r5, #0
    ldr r2, lbl_08035514 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08035548
    ldr r1, [sp, #0x10]
    cmp r1, #0
    bne lbl_08035544
    adds r4, r2, #0
    adds r4, #0x2d
    ldrb r3, [r4]
    cmp r3, #0
    bne lbl_0803551c
    ldrh r1, [r2, #4]
    ldr r0, [sp, #4]
    subs r0, #4
    cmp r1, r0
    bgt lbl_08035562
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    ldr r3, [sp, #0xc]
    cmp r0, r3
    bhs lbl_0803550e
    adds r0, #1
    strb r0, [r1]
lbl_0803550e:
    ldrb r0, [r1]
    b lbl_08035532
    .align 2, 0
lbl_08035514: .4byte 0x03000738
lbl_08035518: .4byte 0x030007f1
lbl_0803551c:
    ldr r0, lbl_08035540 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0803552c
    subs r0, r3, #1
    strb r0, [r4]
lbl_0803552c:
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080355ac
lbl_08035532:
    mov r1, sb
    asrs r0, r1
    ldrh r3, [r2, #4]
    adds r0, r0, r3
    strh r0, [r2, #4]
    b lbl_080355b2
    .align 2, 0
lbl_08035540: .4byte 0x03000c77
lbl_08035544:
    movs r5, #2
    b lbl_080355b6
lbl_08035548:
    ldr r0, [sp, #0x10]
    cmp r0, #0
    bne lbl_080355b0
    adds r4, r2, #0
    adds r4, #0x2d
    ldrb r3, [r4]
    cmp r3, #0
    bne lbl_08035584
    ldrh r1, [r2, #4]
    ldr r0, [sp, #4]
    adds r0, #4
    cmp r1, r0
    bge lbl_0803556c
lbl_08035562:
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r4]
    b lbl_080355b2
lbl_0803556c:
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    ldr r3, [sp, #0xc]
    cmp r0, r3
    bhs lbl_0803557c
    adds r0, #1
    strb r0, [r1]
lbl_0803557c:
    ldrb r1, [r1]
    mov r0, sb
    asrs r1, r0
    b lbl_080355a0
lbl_08035584:
    ldr r0, lbl_080355a8 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08035594
    subs r0, r3, #1
    strb r0, [r4]
lbl_08035594:
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080355ac
    adds r1, r0, #0
    mov r3, sb
    asrs r1, r3
lbl_080355a0:
    ldrh r0, [r2, #4]
    subs r0, r0, r1
    strh r0, [r2, #4]
    b lbl_080355b2
    .align 2, 0
lbl_080355a8: .4byte 0x03000c77
lbl_080355ac:
    movs r5, #1
    b lbl_080355b6
lbl_080355b0:
    movs r5, #2
lbl_080355b2:
    cmp r5, #0
    beq lbl_080355dc
lbl_080355b6:
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    cmp r5, #2
    bne lbl_080355d4
    adds r1, r2, #0
    adds r1, #0x2d
    movs r0, #0
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x10
    b lbl_080355da
lbl_080355d4:
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #1
lbl_080355da:
    strb r0, [r1]
lbl_080355dc:
    movs r5, #0
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08035644
    mov r0, sl
    cmp r0, #0
    bne lbl_08035640
    adds r4, r2, #0
    adds r4, #0x2c
    ldrb r3, [r4]
    cmp r3, #0
    bne lbl_08035618
    ldrh r1, [r2, #2]
    ldr r0, [sp]
    subs r0, #4
    cmp r1, r0
    bgt lbl_0803565e
    adds r1, r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    ldr r3, [sp, #8]
    cmp r0, r3
    bhs lbl_08035614
    adds r0, #1
    strb r0, [r1]
lbl_08035614:
    ldrb r0, [r1]
    b lbl_0803562e
lbl_08035618:
    ldr r0, lbl_0803563c @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08035628
    subs r0, r3, #1
    strb r0, [r4]
lbl_08035628:
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080356a8
lbl_0803562e:
    mov r1, sb
    asrs r0, r1
    ldrh r3, [r2, #2]
    adds r0, r0, r3
    strh r0, [r2, #2]
    b lbl_080356ae
    .align 2, 0
lbl_0803563c: .4byte 0x03000c77
lbl_08035640:
    movs r5, #2
    b lbl_080356b2
lbl_08035644:
    mov r0, sl
    cmp r0, #0
    bne lbl_080356ac
    adds r4, r2, #0
    adds r4, #0x2c
    ldrb r3, [r4]
    cmp r3, #0
    bne lbl_08035680
    ldrh r1, [r2, #2]
    ldr r0, [sp]
    adds r0, #4
    cmp r1, r0
    bge lbl_08035668
lbl_0803565e:
    adds r0, r2, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r4]
    b lbl_080356ae
lbl_08035668:
    adds r1, r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    ldr r3, [sp, #8]
    cmp r0, r3
    bhs lbl_08035678
    adds r0, #1
    strb r0, [r1]
lbl_08035678:
    ldrb r1, [r1]
    mov r0, sb
    asrs r1, r0
    b lbl_0803569c
lbl_08035680:
    ldr r0, lbl_080356a4 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08035690
    subs r0, r3, #1
    strb r0, [r4]
lbl_08035690:
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080356a8
    adds r1, r0, #0
    mov r3, sb
    asrs r1, r3
lbl_0803569c:
    ldrh r0, [r2, #2]
    subs r0, r0, r1
    strh r0, [r2, #2]
    b lbl_080356ae
    .align 2, 0
lbl_080356a4: .4byte 0x03000c77
lbl_080356a8:
    movs r5, #1
    b lbl_080356b2
lbl_080356ac:
    movs r5, #2
lbl_080356ae:
    cmp r5, #0
    beq lbl_080356d8
lbl_080356b2:
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    cmp r5, #2
    bne lbl_080356d0
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0
    strb r0, [r1]
    adds r1, #3
    movs r0, #0x10
    b lbl_080356d6
lbl_080356d0:
    adds r1, r2, #0
    adds r1, #0x2f
    movs r0, #1
lbl_080356d6:
    strb r0, [r1]
lbl_080356d8:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start MetroidBombDetection
MetroidBombDetection: @ 0x080356e8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    ldr r2, lbl_08035780 @ =0x03000738
    ldrh r1, [r2, #2]
    ldrh r3, [r2, #4]
    ldrh r0, [r2, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x10]
    ldrh r0, [r2, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sl, r1
    ldrh r0, [r2, #0xe]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrh r0, [r2, #0x10]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r8, r3
    movs r7, #0x11
    movs r6, #0
lbl_08035726:
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #2
    ldr r1, lbl_08035784 @ =0x03000a2c
    adds r5, r0, r1
    ldrb r0, [r5, #0xf]
    cmp r0, #0xe
    bne lbl_08035788
    ldrb r0, [r5]
    ands r0, r7
    cmp r0, r7
    bne lbl_08035788
    ldrh r3, [r5, #8]
    ldrh r4, [r5, #0xa]
    ldrh r2, [r5, #0x14]
    adds r2, r3, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrh r0, [r5, #0x16]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrh r1, [r5, #0x18]
    adds r1, r4, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r0, [r5, #0x1a]
    adds r4, r4, r0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    str r2, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r4, [sp, #0xc]
    ldr r0, [sp, #0x10]
    mov r1, sl
    mov r2, sb
    mov r3, r8
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_08035788
    movs r0, #1
    b lbl_08035794
    .align 2, 0
lbl_08035780: .4byte 0x03000738
lbl_08035784: .4byte 0x03000a2c
lbl_08035788:
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0xf
    bls lbl_08035726
    movs r0, #0
lbl_08035794:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start MetroidCheckBouncingOnMetroid
MetroidCheckBouncingOnMetroid: @ 0x080357a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldr r1, lbl_080357ec @ =0x03000738
    ldrh r0, [r1, #2]
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r0, [r1, #4]
    str r0, [sp]
    movs r7, #0x20
    movs r2, #9
    mov ip, r2
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #9
    bne lbl_080357f0
    adds r0, r1, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080357f0
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    b lbl_080357f2
    .align 2, 0
lbl_080357ec: .4byte 0x03000738
lbl_080357f0:
    movs r5, #0
lbl_080357f2:
    cmp r5, #0x17
    bls lbl_080357f8
    b lbl_0803594c
lbl_080357f8:
    mov r0, r8
    lsls r0, r0, #4
    mov sb, r0
lbl_080357fe:
    lsls r0, r5, #3
    subs r1, r0, r5
    lsls r1, r1, #3
    ldr r2, lbl_08035890 @ =0x030001ac
    adds r4, r1, r2
    ldrh r1, [r4]
    movs r2, #1
    ands r1, r2
    mov sl, r0
    cmp r1, #0
    bne lbl_08035816
    b lbl_08035940
lbl_08035816:
    adds r0, r4, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, #0x18
    beq lbl_08035822
    b lbl_08035940
lbl_08035822:
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803582e
    b lbl_08035940
lbl_0803582e:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, ip
    beq lbl_0803583a
    b lbl_08035940
lbl_0803583a:
    ldrh r0, [r4, #2]
    movs r1, #0x10
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldrh r6, [r4, #4]
    adds r1, r3, r7
    subs r0, r2, r7
    cmp r1, r0
    ble lbl_08035940
    subs r1, r3, r7
    adds r0, r2, r7
    cmp r1, r0
    bge lbl_08035940
    ldr r0, [sp]
    adds r1, r0, r7
    subs r0, r6, r7
    cmp r1, r0
    ble lbl_08035940
    ldr r0, [sp]
    subs r1, r0, r7
    adds r0, r6, r7
    cmp r1, r0
    bge lbl_08035940
    cmp r3, r2
    bls lbl_08035898
    ldrh r0, [r4, #2]
    subs r0, r0, r7
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_080358c6
    ldrh r0, [r4, #2]
    mov r1, r8
    subs r0, r0, r1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldr r2, lbl_08035894 @ =0x0000fbff
    adds r1, r2, #0
    ands r0, r1
    b lbl_080358b6
    .align 2, 0
lbl_08035890: .4byte 0x030001ac
lbl_08035894: .4byte 0x0000fbff
lbl_08035898:
    ldrh r0, [r4, #2]
    adds r0, r0, r7
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_080358c6
    ldrh r0, [r4, #2]
    add r0, r8
    strh r0, [r4, #2]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
lbl_080358b6:
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x2c
    movs r1, #0
    strb r1, [r0]
    adds r0, #3
    mov r2, sb
    strb r2, [r0]
lbl_080358c6:
    ldr r0, [sp]
    cmp r0, r6
    bls lbl_08035900
    mov r1, sl
    subs r0, r1, r5
    lsls r0, r0, #3
    ldr r2, lbl_080358f8 @ =0x030001ac
    adds r4, r0, r2
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, r1, r7
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803594c
    ldrh r0, [r4, #4]
    mov r1, r8
    subs r0, r0, r1
    strh r0, [r4, #4]
    ldrh r0, [r4]
    ldr r2, lbl_080358fc @ =0x0000fdff
    adds r1, r2, #0
    ands r0, r1
    b lbl_08035928
    .align 2, 0
lbl_080358f8: .4byte 0x030001ac
lbl_080358fc: .4byte 0x0000fdff
lbl_08035900:
    mov r1, sl
    subs r0, r1, r5
    lsls r0, r0, #3
    ldr r2, lbl_0803593c @ =0x030001ac
    adds r4, r0, r2
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, r1, r7
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803594c
    ldrh r0, [r4, #4]
    add r0, r8
    strh r0, [r4, #4]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
lbl_08035928:
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x2d
    movs r1, #0
    strb r1, [r0]
    adds r0, #1
    mov r2, sb
    strb r2, [r0]
    b lbl_0803594c
    .align 2, 0
lbl_0803593c: .4byte 0x030001ac
lbl_08035940:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0x17
    bhi lbl_0803594c
    b lbl_080357fe
lbl_0803594c:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start MetroidCheckSamusGrabbed
MetroidCheckSamusGrabbed: @ 0x0803595c
    push {r4, lr}
    movs r3, #0
    ldr r4, lbl_0803598c @ =0x030001ac
lbl_08035962:
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r2, r0, r4
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08035990
    adds r0, r2, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, #0x18
    bne lbl_08035990
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #9
    beq lbl_08035990
    movs r0, #1
    b lbl_0803599c
    .align 2, 0
lbl_0803598c: .4byte 0x030001ac
lbl_08035990:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0x17
    bls lbl_08035962
    movs r0, #0
lbl_0803599c:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080359a4
sub_080359a4: @ 0x080359a4
    push {lr}
    ldr r1, lbl_080359cc @ =0x03000738
    ldrh r0, [r1, #0x16]
    cmp r0, #0
    bne lbl_080359c6
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_080359c6
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080359c6
    movs r0, #0xb8
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_080359c6:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080359cc: .4byte 0x03000738

    thumb_func_start MetroidInit
MetroidInit: @ 0x080359d0
    push {r4, r5, r6, lr}
    sub sp, #0xc
    movs r4, #0
    ldr r0, lbl_080359ec @ =0x03000055
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #0x12
    bhi lbl_08035a72
    lsls r0, r0, #2
    ldr r1, lbl_080359f0 @ =lbl_080359f4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080359ec: .4byte 0x03000055
lbl_080359f0: .4byte lbl_080359f4
lbl_080359f4: @ jump table
    .4byte lbl_08035a46 @ case 0
    .4byte lbl_08035a4c @ case 1
    .4byte lbl_08035a72 @ case 2
    .4byte lbl_08035a72 @ case 3
    .4byte lbl_08035a72 @ case 4
    .4byte lbl_08035a72 @ case 5
    .4byte lbl_08035a72 @ case 6
    .4byte lbl_08035a72 @ case 7
    .4byte lbl_08035a72 @ case 8
    .4byte lbl_08035a72 @ case 9
    .4byte lbl_08035a72 @ case 10
    .4byte lbl_08035a72 @ case 11
    .4byte lbl_08035a72 @ case 12
    .4byte lbl_08035a40 @ case 13
    .4byte lbl_08035a52 @ case 14
    .4byte lbl_08035a58 @ case 15
    .4byte lbl_08035a72 @ case 16
    .4byte lbl_08035a72 @ case 17
    .4byte lbl_08035a5e @ case 18
lbl_08035a40:
    movs r0, #3
    movs r1, #0x37
    b lbl_08035a62
lbl_08035a46:
    movs r0, #3
    movs r1, #0x38
    b lbl_08035a62
lbl_08035a4c:
    movs r0, #3
    movs r1, #0x39
    b lbl_08035a62
lbl_08035a52:
    movs r0, #3
    movs r1, #0x3a
    b lbl_08035a62
lbl_08035a58:
    movs r0, #3
    movs r1, #0x3b
    b lbl_08035a62
lbl_08035a5e:
    movs r0, #3
    movs r1, #0x3c
lbl_08035a62:
    bl EventFunction
    cmp r0, #0
    bne lbl_08035a74
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    b lbl_08035a74
lbl_08035a72:
    movs r4, #2
lbl_08035a74:
    cmp r4, #0
    bne lbl_08035a84
    ldr r0, lbl_08035a80 @ =0x03000738
    strh r4, [r0]
    b lbl_08035b38
    .align 2, 0
lbl_08035a80: .4byte 0x03000738
lbl_08035a84:
    cmp r4, #1
    bne lbl_08035a8c
    ldr r0, lbl_08035b40 @ =0x0300007b
    strb r4, [r0]
lbl_08035a8c:
    ldr r5, lbl_08035b44 @ =0x03000738
    ldrh r1, [r5]
    movs r0, #0x20
    movs r6, #0
    orrs r0, r1
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r0, r1
    movs r4, #0
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r5]
    movs r0, #0x40
    strh r0, [r5, #0x12]
    adds r0, r5, #0
    adds r0, #0x2a
    strb r4, [r0]
    subs r0, #3
    movs r1, #6
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r5, #0
    adds r1, #0x29
    movs r0, #5
    strb r0, [r1]
    ldr r1, lbl_08035b48 @ =0x0000ffd8
    strh r1, [r5, #0xa]
    movs r0, #0x20
    strh r0, [r5, #0xc]
    strh r1, [r5, #0xe]
    movs r0, #0x28
    strh r0, [r5, #0x10]
    ldr r0, lbl_08035b4c @ =0x082edd20
    str r0, [r5, #0x18]
    strb r4, [r5, #0x1c]
    strh r6, [r5, #0x16]
    ldr r2, lbl_08035b50 @ =0x082b0d68
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r5, #0x14]
    strh r0, [r5, #6]
    adds r0, r5, #0
    adds r0, #0x25
    strb r4, [r0]
    bl SpriteUtilMakeSpriteFaceSamusDirection
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #1
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x2e
    strb r4, [r0]
    adds r0, #1
    strb r4, [r0]
    subs r1, #2
    movs r0, #0xc
    strb r0, [r1]
    ldrb r1, [r5, #0x1e]
    ldrb r2, [r5, #0x1f]
    adds r0, r5, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r5, #2]
    str r0, [sp]
    ldrh r0, [r5, #4]
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x1a
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xff
    bne lbl_08035b30
    strh r6, [r5]
lbl_08035b30:
    adds r1, r5, #0
    adds r1, #0x20
    movs r0, #3
    strb r0, [r1]
lbl_08035b38:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08035b40: .4byte 0x0300007b
lbl_08035b44: .4byte 0x03000738
lbl_08035b48: .4byte 0x0000ffd8
lbl_08035b4c: .4byte 0x082edd20
lbl_08035b50: .4byte 0x082b0d68

    thumb_func_start metroid_gfx_init
metroid_gfx_init: @ 0x08035b54
    push {lr}
    ldr r2, lbl_08035b90 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08035b8a
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #2
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x29
    movs r0, #0x14
    strb r0, [r1]
    ldr r0, lbl_08035b94 @ =0x0300083c
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, #1
    adds r1, #3
    strb r0, [r1]
lbl_08035b8a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08035b90: .4byte 0x03000738
lbl_08035b94: .4byte 0x0300083c

    thumb_func_start MetroidSpawning
MetroidSpawning: @ 0x08035b98
    push {r4, r5, r6, r7, lr}
    ldr r3, lbl_08035c00 @ =0x03000738
    movs r0, #0x2f
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    ldr r4, lbl_08035c04 @ =0x082ecb60
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r5, lbl_08035c08 @ =0x00007fff
    cmp r1, r5
    bne lbl_08035bba
    movs r7, #0
    ldrsh r1, [r4, r7]
    movs r2, #0
lbl_08035bba:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #2]
    adds r0, r0, r1
    movs r6, #0
    strh r0, [r3, #2]
    movs r7, #0x2e
    adds r7, r7, r3
    mov ip, r7
    ldrb r2, [r7]
    ldr r4, lbl_08035c0c @ =0x082ecbe2
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r7, #0
    ldrsh r1, [r0, r7]
    cmp r1, r5
    bne lbl_08035be4
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0
lbl_08035be4:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #4]
    adds r0, r0, r1
    strh r0, [r3, #4]
    adds r1, r3, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r4, r0, #0
    cmp r4, #0
    beq lbl_08035c10
    subs r0, #1
    b lbl_08035c62
    .align 2, 0
lbl_08035c00: .4byte 0x03000738
lbl_08035c04: .4byte 0x082ecb60
lbl_08035c08: .4byte 0x00007fff
lbl_08035c0c: .4byte 0x082ecbe2
lbl_08035c10:
    ldrh r0, [r3, #0x12]
    cmp r0, #0xff
    bhi lbl_08035c36
    adds r0, #4
    strh r0, [r3, #0x12]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xd0
    bls lbl_08035c2a
    adds r1, r3, #0
    adds r1, #0x20
    movs r0, #1
    b lbl_08035c62
lbl_08035c2a:
    cmp r0, #0xa0
    bls lbl_08035c64
    adds r1, r3, #0
    adds r1, #0x20
    movs r0, #2
    b lbl_08035c62
lbl_08035c36:
    adds r0, r3, #0
    adds r0, #0x20
    strb r6, [r0]
    ldrh r0, [r3]
    ldr r1, lbl_08035c6c @ =0x0000ff7f
    ands r1, r0
    adds r2, r3, #0
    adds r2, #0x24
    movs r0, #8
    strb r0, [r2]
    ldr r0, lbl_08035c70 @ =0x082edc20
    str r0, [r3, #0x18]
    strb r6, [r3, #0x1c]
    strh r4, [r3, #0x16]
    ands r1, r5
    strh r1, [r3]
    adds r1, r3, #0
    adds r1, #0x25
    movs r0, #0x18
    strb r0, [r1]
    subs r1, #3
    movs r0, #4
lbl_08035c62:
    strb r0, [r1]
lbl_08035c64:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08035c6c: .4byte 0x0000ff7f
lbl_08035c70: .4byte 0x082edc20

    thumb_func_start MetroidMovingInit
MetroidMovingInit: @ 0x08035c74
    ldr r3, lbl_08035ca0 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #9
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r0, #1
    movs r1, #1
    strb r1, [r0]
    subs r0, #2
    strb r2, [r0]
    adds r0, #3
    strb r1, [r0]
    ldr r0, lbl_08035ca4 @ =0x082edc20
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r2, [r3, #0x16]
    bx lr
    .align 2, 0
lbl_08035ca0: .4byte 0x03000738
lbl_08035ca4: .4byte 0x082edc20

    thumb_func_start MetroidMovement
MetroidMovement: @ 0x08035ca8
    push {r4, lr}
    sub sp, #4
    bl sub_080359a4
    ldr r4, lbl_08035cd4 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08035cf2
    bl MetroidCheckSamusGrabbed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08035cdc
    ldrh r1, [r4]
    ldr r0, lbl_08035cd8 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r4]
    b lbl_08035cf2
    .align 2, 0
lbl_08035cd4: .4byte 0x03000738
lbl_08035cd8: .4byte 0x0000f7ff
lbl_08035cdc:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    b lbl_08035d16
lbl_08035cf2:
    movs r0, #1
    bl MetroidCheckBouncingOnMetroid
    ldr r1, lbl_08035d20 @ =0x030013d4
    ldr r0, lbl_08035d24 @ =0x03001588
    adds r0, #0x70
    ldrh r0, [r0]
    ldrh r2, [r1, #0x14]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r1, #0x12]
    movs r2, #2
    str r2, [sp]
    movs r2, #0x1e
    movs r3, #0x28
    bl MetroidMove
lbl_08035d16:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08035d20: .4byte 0x030013d4
lbl_08035d24: .4byte 0x03001588

    thumb_func_start MetroidSamusGrabbedInit
MetroidSamusGrabbedInit: @ 0x08035d28
    ldr r0, lbl_08035d60 @ =0x03000738
    mov ip, r0
    mov r1, ip
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x43
    strb r0, [r1]
    ldr r0, lbl_08035d64 @ =0x082edca8
    mov r1, ip
    str r0, [r1, #0x18]
    strb r2, [r1, #0x1c]
    movs r3, #0
    strh r2, [r1, #0x16]
    adds r1, #0x2c
    movs r0, #4
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    adds r1, #6
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2a
    strb r3, [r0]
    ldr r1, lbl_08035d68 @ =0x03001530
    movs r0, #1
    strb r0, [r1, #0x13]
    bx lr
    .align 2, 0
lbl_08035d60: .4byte 0x03000738
lbl_08035d64: .4byte 0x082edca8
lbl_08035d68: .4byte 0x03001530

    thumb_func_start MetroidSamusGrabbed
MetroidSamusGrabbed: @ 0x08035d6c
    push {r4, r5, lr}
    bl sub_080359a4
    movs r0, #2
    bl MetroidCheckBouncingOnMetroid
    ldr r3, lbl_08035dd0 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_08035db8
    movs r0, #4
    strb r0, [r1]
    adds r1, #1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bls lbl_08035da2
    strb r2, [r1]
lbl_08035da2:
    ldr r2, lbl_08035dd4 @ =0x040000d4
    ldrb r0, [r1]
    lsls r0, r0, #5
    ldr r1, lbl_08035dd8 @ =0x082ed988
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_08035ddc @ =0x05000380
    str r0, [r2, #4]
    ldr r0, lbl_08035de0 @ =0x80000008
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_08035db8:
    ldr r4, lbl_08035dd0 @ =0x03000738
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl MetroidCheckAirCollision
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08035de8
    ldr r1, lbl_08035de4 @ =0x030013d4
    ldrh r0, [r4, #4]
    strh r0, [r1, #0x12]
    b lbl_08035dee
    .align 2, 0
lbl_08035dd0: .4byte 0x03000738
lbl_08035dd4: .4byte 0x040000d4
lbl_08035dd8: .4byte 0x082ed988
lbl_08035ddc: .4byte 0x05000380
lbl_08035de0: .4byte 0x80000008
lbl_08035de4: .4byte 0x030013d4
lbl_08035de8:
    ldr r1, lbl_08035e5c @ =0x030013d4
    ldrh r0, [r1, #0x12]
    strh r0, [r4, #4]
lbl_08035dee:
    ldr r4, lbl_08035e60 @ =0x03000738
    ldr r0, lbl_08035e64 @ =0x03001588
    adds r0, #0x70
    ldrh r0, [r0]
    ldrh r1, [r1, #0x14]
    adds r0, r0, r1
    movs r5, #0
    strh r0, [r4, #2]
    bl MetroidBombDetection
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08035e78
    ldr r0, lbl_08035e68 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    movs r2, #0x10
    cmp r0, #0
    beq lbl_08035e18
    movs r2, #0x1c
lbl_08035e18:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x20
    strb r5, [r0]
    adds r1, #2
    movs r0, #0xf
    strb r0, [r1]
    ldrh r1, [r4]
    ldr r0, lbl_08035e6c @ =0x00007bff
    ands r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x2c
    strb r5, [r0]
    adds r0, #3
    strb r2, [r0]
    subs r0, #2
    strb r5, [r0]
    adds r0, #1
    strb r2, [r0]
    ldr r0, lbl_08035e70 @ =0x082edc20
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r0, #0
    strh r0, [r4, #0x16]
    adds r0, r4, #0
    adds r0, #0x33
    strb r5, [r0]
    ldr r0, lbl_08035e74 @ =0x03001530
    strb r5, [r0, #0x13]
    b lbl_08035eca
    .align 2, 0
lbl_08035e5c: .4byte 0x030013d4
lbl_08035e60: .4byte 0x03000738
lbl_08035e64: .4byte 0x03001588
lbl_08035e68: .4byte 0x0300083c
lbl_08035e6c: .4byte 0x00007bff
lbl_08035e70: .4byte 0x082edc20
lbl_08035e74: .4byte 0x03001530
lbl_08035e78:
    adds r0, r4, #0
    adds r0, #0x2a
    ldrb r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_08035ec0
    movs r0, #0x81
    bl SoundPlayNotAlreadyPlaying
    ldr r0, lbl_08035ea0 @ =0x03001530
    ldrb r0, [r0, #0xf]
    movs r2, #0x30
    ands r2, r0
    cmp r2, #0
    bne lbl_08035ea8
    ldr r0, lbl_08035ea4 @ =0x0000016d
    bl SoundPlay
    b lbl_08035ec0
    .align 2, 0
lbl_08035ea0: .4byte 0x03001530
lbl_08035ea4: .4byte 0x0000016d
lbl_08035ea8:
    cmp r2, #0x30
    bne lbl_08035eb8
    ldr r0, lbl_08035eb4 @ =0x0000016f
    bl SoundPlay
    b lbl_08035ec0
    .align 2, 0
lbl_08035eb4: .4byte 0x0000016f
lbl_08035eb8:
    movs r0, #0xb7
    lsls r0, r0, #1
    bl SoundPlay
lbl_08035ec0:
    ldr r1, lbl_08035ed0 @ =0x03000738
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08035eca:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08035ed0: .4byte 0x03000738

    thumb_func_start MetroidDeath
MetroidDeath: @ 0x08035ed4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_08035ef0 @ =0x0300083c
    ldrb r2, [r0]
    ldr r0, lbl_08035ef4 @ =0x03000738
    ldrh r3, [r0, #2]
    ldrh r4, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08035f00
    adds r0, r3, r2
    b lbl_08035f02
    .align 2, 0
lbl_08035ef0: .4byte 0x0300083c
lbl_08035ef4: .4byte 0x03000738
lbl_08035ef8:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    b lbl_08035f60
lbl_08035f00:
    subs r0, r3, r2
lbl_08035f02:
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    adds r2, r4, #0
    adds r2, #0x24
    movs r0, #0x29
    str r0, [sp]
    movs r0, #0
    adds r1, r3, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    movs r0, #0x64
    mov ip, r0
    movs r7, #0x65
    movs r6, #0x62
    movs r5, #1
    movs r4, #0x80
    movs r3, #0
    ldr r1, lbl_08035f78 @ =0x030001ac
    movs r2, #0xa8
    lsls r2, r2, #3
    adds r0, r1, r2
    cmp r1, r0
    bhs lbl_08035f60
    adds r2, r1, #0
    adds r2, #0x24
lbl_08035f36:
    ldrh r0, [r1]
    ands r0, r5
    cmp r0, #0
    beq lbl_08035f56
    ldrb r0, [r2, #0xe]
    ands r0, r4
    cmp r0, #0
    bne lbl_08035f56
    ldrb r0, [r1, #0x1d]
    cmp r0, ip
    beq lbl_08035f50
    cmp r0, r7
    bne lbl_08035f56
lbl_08035f50:
    ldrb r0, [r2]
    cmp r0, r6
    blo lbl_08035ef8
lbl_08035f56:
    adds r2, #0x38
    adds r1, #0x38
    ldr r0, lbl_08035f7c @ =0x030006ec
    cmp r1, r0
    blo lbl_08035f36
lbl_08035f60:
    cmp r3, #0
    bne lbl_08036004
    ldr r0, lbl_08035f80 @ =0x03000055
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #0x12
    bhi lbl_08036004
    lsls r0, r0, #2
    ldr r1, lbl_08035f84 @ =lbl_08035f88
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08035f78: .4byte 0x030001ac
lbl_08035f7c: .4byte 0x030006ec
lbl_08035f80: .4byte 0x03000055
lbl_08035f84: .4byte lbl_08035f88
lbl_08035f88: @ jump table
    .4byte lbl_08035fda @ case 0
    .4byte lbl_08035fe0 @ case 1
    .4byte lbl_08036004 @ case 2
    .4byte lbl_08036004 @ case 3
    .4byte lbl_08036004 @ case 4
    .4byte lbl_08036004 @ case 5
    .4byte lbl_08036004 @ case 6
    .4byte lbl_08036004 @ case 7
    .4byte lbl_08036004 @ case 8
    .4byte lbl_08036004 @ case 9
    .4byte lbl_08036004 @ case 10
    .4byte lbl_08036004 @ case 11
    .4byte lbl_08036004 @ case 12
    .4byte lbl_08035fd4 @ case 13
    .4byte lbl_08035fe6 @ case 14
    .4byte lbl_08035fec @ case 15
    .4byte lbl_08036004 @ case 16
    .4byte lbl_08036004 @ case 17
    .4byte lbl_08035ff2 @ case 18
lbl_08035fd4:
    movs r0, #1
    movs r1, #0x37
    b lbl_08035ff6
lbl_08035fda:
    movs r0, #1
    movs r1, #0x38
    b lbl_08035ff6
lbl_08035fe0:
    movs r0, #1
    movs r1, #0x39
    b lbl_08035ff6
lbl_08035fe6:
    movs r0, #1
    movs r1, #0x3a
    b lbl_08035ff6
lbl_08035fec:
    movs r0, #1
    movs r1, #0x3b
    b lbl_08035ff6
lbl_08035ff2:
    movs r0, #1
    movs r1, #0x3c
lbl_08035ff6:
    bl EventFunction
    ldr r1, lbl_0803600c @ =0x0300007b
    movs r2, #0x14
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
lbl_08036004:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803600c: .4byte 0x0300007b

    thumb_func_start Metroid
Metroid: @ 0x08036010
    push {r4, lr}
    ldr r1, lbl_08036040 @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x32
    ldrb r2, [r3]
    movs r4, #2
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08036044
    movs r0, #0xfd
    ands r0, r2
    strb r0, [r3]
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08036072
    movs r0, #0xb9
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    b lbl_08036072
    .align 2, 0
lbl_08036040: .4byte 0x03000738
lbl_08036044:
    adds r0, r1, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    movs r2, #0x7f
    ands r2, r0
    cmp r2, #2
    bne lbl_08036072
    ldrh r0, [r1, #0x14]
    ldrh r3, [r1, #6]
    cmp r0, r3
    bne lbl_08036070
    ldrh r0, [r1]
    ands r2, r0
    cmp r2, #0
    beq lbl_08036072
    ldr r0, lbl_0803606c @ =0x00000171
    bl SoundPlayNotAlreadyPlaying
    b lbl_08036072
    .align 2, 0
lbl_0803606c: .4byte 0x00000171
lbl_08036070:
    strh r0, [r1, #6]
lbl_08036072:
    ldr r2, lbl_080360a4 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080360c4
    ldr r0, lbl_080360a8 @ =0x0000ffd0
    strh r0, [r2, #0xa]
    movs r0, #0x28
    strh r0, [r2, #0xc]
    ldr r0, lbl_080360ac @ =0x0000ffc0
    strh r0, [r2, #0xe]
    movs r0, #0x40
    strh r0, [r2, #0x10]
    movs r0, #1
    bl MetroidCheckBouncingOnMetroid
    ldr r0, lbl_080360b0 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080360b4
    bl SpriteUtilUnfreezeAnimEasy
    b lbl_080360b8
    .align 2, 0
lbl_080360a4: .4byte 0x03000738
lbl_080360a8: .4byte 0x0000ffd0
lbl_080360ac: .4byte 0x0000ffc0
lbl_080360b0: .4byte 0x0300002c
lbl_080360b4:
    bl SpriteUtilMetroidUnfreezeAnim
lbl_080360b8:
    ldr r1, lbl_080360c0 @ =0x03000738
    movs r0, #0x65
    strb r0, [r1, #0x1d]
    b lbl_08036162
    .align 2, 0
lbl_080360c0: .4byte 0x03000738
lbl_080360c4:
    ldrb r0, [r2, #0x1d]
    cmp r0, #0x65
    bne lbl_080360ea
    ldr r1, lbl_08036108 @ =0x0000ffd8
    strh r1, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
    movs r0, #0x28
    strh r0, [r2, #0x10]
    movs r0, #0x64
    strb r0, [r2, #0x1d]
    adds r1, r2, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x61
    bhi lbl_080360ea
    movs r0, #8
    strb r0, [r1]
lbl_080360ea:
    ldr r0, lbl_0803610c @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #8
    beq lbl_08036140
    cmp r0, #8
    bgt lbl_08036116
    cmp r0, #1
    beq lbl_08036134
    cmp r0, #1
    bgt lbl_08036110
    cmp r0, #0
    beq lbl_0803612e
    b lbl_08036158
    .align 2, 0
lbl_08036108: .4byte 0x0000ffd8
lbl_0803610c: .4byte 0x03000738
lbl_08036110:
    cmp r0, #2
    beq lbl_0803613a
    b lbl_08036158
lbl_08036116:
    cmp r0, #0x42
    beq lbl_0803614a
    cmp r0, #0x42
    bgt lbl_08036124
    cmp r0, #9
    beq lbl_08036144
    b lbl_08036158
lbl_08036124:
    cmp r0, #0x43
    beq lbl_0803614e
    cmp r0, #0x62
    beq lbl_08036154
    b lbl_08036158
lbl_0803612e:
    bl MetroidInit
    b lbl_08036158
lbl_08036134:
    bl metroid_gfx_init
    b lbl_08036158
lbl_0803613a:
    bl MetroidSpawning
    b lbl_08036158
lbl_08036140:
    bl MetroidMovingInit
lbl_08036144:
    bl MetroidMovement
    b lbl_08036158
lbl_0803614a:
    bl MetroidSamusGrabbedInit
lbl_0803614e:
    bl MetroidSamusGrabbed
    b lbl_08036158
lbl_08036154:
    bl MetroidDeath
lbl_08036158:
    ldr r2, lbl_08036168 @ =0x03000738
    ldrh r1, [r2]
    ldr r0, lbl_0803616c @ =0x0000f7ff
    ands r0, r1
    strh r0, [r2]
lbl_08036162:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08036168: .4byte 0x03000738
lbl_0803616c: .4byte 0x0000f7ff

    thumb_func_start MetroidShell
MetroidShell: @ 0x08036170
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r3, lbl_080361b8 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r6, [r0]
    adds r1, r3, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldr r2, lbl_080361bc @ =0x030001ac
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r5, r0, r2
    adds r0, r5, #0
    adds r0, #0x20
    ldrb r1, [r0]
    adds r0, r3, #0
    adds r0, #0x20
    strb r1, [r0]
    ldrh r0, [r5, #0x14]
    mov ip, r2
    cmp r0, #0
    bne lbl_080361ee
    ldr r0, lbl_080361c0 @ =0x0300083c
    ldrb r2, [r0]
    ldrh r4, [r3, #2]
    ldrh r6, [r3, #4]
    ldrh r1, [r5]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080361c4
    subs r0, r4, r2
    b lbl_080361c6
    .align 2, 0
lbl_080361b8: .4byte 0x03000738
lbl_080361bc: .4byte 0x030001ac
lbl_080361c0: .4byte 0x0300083c
lbl_080361c4:
    adds r0, r4, r2
lbl_080361c6:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0x64
    strb r0, [r3, #0x1d]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r2]
    adds r2, r6, #0
    subs r2, #0x24
    movs r0, #0x29
    str r0, [sp]
    movs r0, #0
    adds r1, r4, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    b lbl_0803625e
lbl_080361ee:
    adds r7, r3, #0
    adds r7, #0x24
    ldrb r4, [r7]
    cmp r4, #0
    bne lbl_08036234
    adds r0, r3, #0
    adds r0, #0x25
    strb r4, [r0]
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x14
    strb r0, [r1]
    adds r1, #1
    movs r0, #0xa
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    movs r2, #0
    ldr r1, lbl_08036268 @ =0x0000fffc
    strh r1, [r3, #0xa]
    movs r0, #4
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    movs r0, #9
    strb r0, [r7]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    ldr r0, lbl_0803626c @ =0x082edc08
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r4, [r3, #0x16]
lbl_08036234:
    ldrh r2, [r3]
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_0803624e
    ldrh r1, [r5]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0803624e
    ldr r0, lbl_08036270 @ =0x0000fffb
    ands r0, r2
    strh r0, [r3]
lbl_0803624e:
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    add r0, ip
    ldrh r1, [r0, #2]
    strh r1, [r3, #2]
    ldrh r0, [r0, #4]
    strh r0, [r3, #4]
lbl_0803625e:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08036268: .4byte 0x0000fffc
lbl_0803626c: .4byte 0x082edc08
lbl_08036270: .4byte 0x0000fffb

    thumb_func_start MetroidDoorLock
MetroidDoorLock: @ 0x08036274
    push {r4, r5, r6, lr}
    ldr r4, lbl_080362cc @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x26
    movs r5, #1
    strb r5, [r0]
    adds r6, r4, #0
    adds r6, #0x24
    ldrb r3, [r6]
    cmp r3, #0
    bne lbl_080362e0
    ldrh r1, [r4]
    ldr r2, lbl_080362d0 @ =0x00008004
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x25
    strb r2, [r0]
    adds r0, #2
    strb r5, [r0]
    adds r0, #1
    strb r5, [r0]
    adds r0, #1
    strb r5, [r0]
    strh r3, [r4, #0xa]
    strh r3, [r4, #0xc]
    strh r3, [r4, #0xe]
    strh r3, [r4, #0x10]
    movs r0, #8
    strb r0, [r6]
    ldr r0, lbl_080362d4 @ =0x082b2750
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    movs r0, #0x64
    bl SpriteUtilCountPrimarySprites
    cmp r0, #0
    beq lbl_080362dc
    ldr r0, lbl_080362d8 @ =0x0300007b
    strb r5, [r0]
    b lbl_08036300
    .align 2, 0
lbl_080362cc: .4byte 0x03000738
lbl_080362d0: .4byte 0x00008004
lbl_080362d4: .4byte 0x082b2750
lbl_080362d8: .4byte 0x0300007b
lbl_080362dc:
    strh r0, [r4]
    b lbl_08036300
lbl_080362e0:
    movs r0, #0x64
    bl SpriteUtilCountPrimarySprites
    cmp r0, #0
    bne lbl_08036300
    movs r0, #0x65
    bl SpriteUtilCountPrimarySprites
    cmp r0, #0
    bne lbl_08036300
    strh r0, [r4]
    ldr r1, lbl_08036308 @ =0x0300007b
    movs r2, #0x14
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
lbl_08036300:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08036308: .4byte 0x0300007b
