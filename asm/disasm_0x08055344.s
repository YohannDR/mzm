    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start ScreenShakeStartVertical
ScreenShakeStartVertical: @ 0x08055344
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_08055370 @ =gScreenShakeY
    cmp r2, #0
    beq lbl_08055368
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_08055368
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r4, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_08055374 @ =gScreenShakeYOffset
    strb r1, [r0]
lbl_08055368:
    ldrb r0, [r3]
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08055370: .4byte gScreenShakeY
lbl_08055374: .4byte gScreenShakeYOffset

    thumb_func_start ScreenShakeStartHorizontal
ScreenShakeStartHorizontal: @ 0x08055378
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_080553a4 @ =gScreenShakeX
    cmp r2, #0
    beq lbl_0805539c
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_0805539c
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r4, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_080553a8 @ =gScreenShakeXOffset
    strb r1, [r0]
lbl_0805539c:
    ldrb r0, [r3]
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080553a4: .4byte gScreenShakeX
lbl_080553a8: .4byte gScreenShakeXOffset

    thumb_func_start ScreenShakeStartHorizontal_unused
ScreenShakeStartHorizontal_unused: @ 0x080553ac
    push {lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r3, lbl_080553d4 @ =gScreenShakeX
    cmp r2, #0
    beq lbl_080553cc
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_080553cc
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r1, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_080553d8 @ =gScreenShakeXOffset
    strb r1, [r0]
lbl_080553cc:
    ldrb r0, [r3]
    pop {r1}
    bx r1
    .align 2, 0
lbl_080553d4: .4byte gScreenShakeX
lbl_080553d8: .4byte gScreenShakeXOffset

    thumb_func_start update_vertical_screen_shake
update_vertical_screen_shake: @ 0x080553dc
    push {r4, r5, r6, lr}
    movs r2, #0
    ldr r6, lbl_080553f4 @ =gScreenShakeYOffset
    strb r2, [r6]
    ldr r4, lbl_080553f8 @ =gScreenShakeY
    ldrb r0, [r4]
    adds r3, r4, #0
    cmp r0, #0
    bne lbl_080553fc
    movs r0, #0
    b lbl_0805543e
    .align 2, 0
lbl_080553f4: .4byte gScreenShakeYOffset
lbl_080553f8: .4byte gScreenShakeY
lbl_080553fc:
    subs r5, r0, #1
    strb r5, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #1
    bhi lbl_0805540e
    adds r0, #1
    strb r0, [r3, #1]
    movs r0, #0
    b lbl_0805543e
lbl_0805540e:
    strb r2, [r3, #1]
    ldrb r0, [r3, #2]
    movs r1, #0x7f
    ands r1, r0
    movs r2, #2
    rsbs r2, r2, #0
    ldrb r3, [r3, #3]
    cmp r3, #0
    beq lbl_0805542a
    movs r2, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r2, r0
lbl_0805542a:
    movs r0, #1
    eors r0, r3
    strb r0, [r4, #3]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bhi lbl_0805543a
    asrs r2, r2, #1
lbl_0805543a:
    strb r2, [r6]
    adds r0, r2, #0
lbl_0805543e:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start update_horizontal_screen_shake
update_horizontal_screen_shake: @ 0x08055444
    push {r4, r5, r6, lr}
    movs r2, #0
    ldr r6, lbl_0805545c @ =gScreenShakeXOffset
    strb r2, [r6]
    ldr r4, lbl_08055460 @ =gScreenShakeX
    ldrb r0, [r4]
    adds r3, r4, #0
    cmp r0, #0
    bne lbl_08055464
    movs r0, #0
    b lbl_080554a6
    .align 2, 0
lbl_0805545c: .4byte gScreenShakeXOffset
lbl_08055460: .4byte gScreenShakeX
lbl_08055464:
    subs r5, r0, #1
    strb r5, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #1
    bhi lbl_08055476
    adds r0, #1
    strb r0, [r3, #1]
    movs r0, #0
    b lbl_080554a6
lbl_08055476:
    strb r2, [r3, #1]
    ldrb r0, [r3, #2]
    movs r1, #0x7f
    ands r1, r0
    movs r2, #2
    rsbs r2, r2, #0
    ldrb r3, [r3, #3]
    cmp r3, #0
    beq lbl_08055492
    movs r2, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r2, r0
lbl_08055492:
    movs r0, #1
    eors r0, r3
    strb r0, [r4, #3]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bhi lbl_080554a2
    asrs r2, r2, #1
lbl_080554a2:
    strb r2, [r6]
    adds r0, r2, #0
lbl_080554a6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
