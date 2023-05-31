    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start get_chararcter_width
get_chararcter_width: @ 0x0806e460
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_0806e474 @ =0x0000049f
    cmp r1, r0
    bhi lbl_0806e47c
    ldr r0, lbl_0806e478 @ =0x0840d7b0
    adds r0, r1, r0
    ldrb r0, [r0]
    b lbl_0806e47e
    .align 2, 0
lbl_0806e474: .4byte 0x0000049f
lbl_0806e478: .4byte 0x0840d7b0
lbl_0806e47c:
    movs r0, #0xa
lbl_0806e47e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start draw_character_for_text
draw_character_for_text: @ 0x0806e484
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e550 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov sl, r0
lbl_0806e4c4:
    ldr r5, lbl_0806e550 @ =0x02027700
    mov r1, sl
    cmp r1, #0
    beq lbl_0806e4ce
    adds r5, #0x40
lbl_0806e4ce:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, sl
    lsls r1, r3, #0xa
    adds r4, r0, r1
    ldr r0, lbl_0806e554 @ =0x08415460
    adds r6, r4, r0
    movs r0, #8
    str r0, [sp, #0x14]
    str r1, [sp, #0x24]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bls lbl_0806e4ec
    movs r2, #0x10
    str r2, [sp, #0x14]
lbl_0806e4ec:
    ldr r3, [sp, #0x10]
    cmp r3, #0
    bne lbl_0806e4f4
    b lbl_0806e614
lbl_0806e4f4:
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #8
    mov ip, r0
    mov r1, sl
    adds r1, #1
    str r1, [sp, #0x28]
    ldr r2, [sp, #0x14]
    cmp r2, #0
    bgt lbl_0806e508
    b lbl_0806e632
lbl_0806e508:
    ldr r3, lbl_0806e558 @ =0x08760338
    mov r8, r3
    ldr r7, lbl_0806e55c @ =0x08760398
    mov sb, r2
lbl_0806e510:
    ldr r4, [r6]
    cmp r4, #0
    beq lbl_0806e600
    movs r1, #0
    movs r3, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e522
    adds r3, r0, #0
lbl_0806e522:
    mov r0, r8
    ldr r2, [r0]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e538
    ldr r0, [r7]
    ands r0, r2
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_0806e538
    adds r1, r3, #0
lbl_0806e538:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #4]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e562
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e560
    orrs r1, r3
    b lbl_0806e562
    .align 2, 0
lbl_0806e550: .4byte 0x02027700
lbl_0806e554: .4byte 0x08415460
lbl_0806e558: .4byte 0x08760338
lbl_0806e55c: .4byte 0x08760398
lbl_0806e560:
    orrs r1, r2
lbl_0806e562:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #8]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e57c
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e57a
    orrs r1, r3
    b lbl_0806e57c
lbl_0806e57a:
    orrs r1, r2
lbl_0806e57c:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0xc]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e596
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e594
    orrs r1, r3
    b lbl_0806e596
lbl_0806e594:
    orrs r1, r2
lbl_0806e596:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x10]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5b0
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5ae
    orrs r1, r3
    b lbl_0806e5b0
lbl_0806e5ae:
    orrs r1, r2
lbl_0806e5b0:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x14]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5ca
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5c8
    orrs r1, r3
    b lbl_0806e5ca
lbl_0806e5c8:
    orrs r1, r2
lbl_0806e5ca:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x18]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5e4
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5e2
    orrs r1, r3
    b lbl_0806e5e4
lbl_0806e5e2:
    orrs r1, r2
lbl_0806e5e4:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x1c]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5fe
    ldr r0, [r7, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5fc
    orrs r1, r3
    b lbl_0806e5fe
lbl_0806e5fc:
    orrs r1, r2
lbl_0806e5fe:
    str r1, [r5]
lbl_0806e600:
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    adds r5, #4
    adds r6, #4
    mov r2, sb
    cmp r2, #0
    beq lbl_0806e612
    b lbl_0806e510
lbl_0806e612:
    b lbl_0806e632
lbl_0806e614:
    ldr r0, [sp, #0x14]
    lsls r3, r0, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r2, r5, #0
    bl DMATransfer
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    mov ip, r1
    mov r2, sl
    adds r2, #1
    str r2, [sp, #0x28]
lbl_0806e632:
    movs r0, #0xff
    ldr r3, [sp, #0xc]
    ands r0, r3
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r1, [sp, #8]
    adds r0, r1, r0
    ldr r2, [sp, #0x24]
    adds r5, r0, r2
    mov r3, ip
    lsls r0, r3, #0xb
    adds r5, r5, r0
    ldr r6, lbl_0806e7f8 @ =0x02027700
    mov r0, sl
    cmp r0, #0
    beq lbl_0806e654
    adds r6, #0x40
lbl_0806e654:
    movs r3, #7
    ldr r1, [sp, #0xc]
    ands r3, r1
    cmp r3, #0
    bne lbl_0806e660
    b lbl_0806e89a
lbl_0806e660:
    lsls r4, r3, #2
    movs r0, #0x20
    subs r0, r0, r4
    str r0, [sp, #0x14]
    ldr r2, [sp, #0x18]
    adds r3, r3, r2
    str r3, [sp, #0x1c]
    cmp r3, #8
    bgt lbl_0806e674
    b lbl_0806e848
lbl_0806e674:
    ldr r2, [r6]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r3, [r5, #0x20]
    orrs r3, r2
    str r3, [r5, #0x20]
    ldr r2, [r6, #4]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r7, [r5, #0x24]
    orrs r7, r2
    str r7, [r5, #0x24]
    ldr r2, [r6, #8]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x28]
    mov ip, r0
    mov r1, ip
    orrs r1, r2
    mov ip, r1
    str r1, [r5, #0x28]
    ldr r2, [r6, #0xc]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x2c]
    mov r8, r1
    mov r0, r8
    orrs r0, r2
    mov r8, r0
    str r0, [r5, #0x2c]
    ldr r2, [r6, #0x10]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x30]
    mov sb, r0
    mov r1, sb
    orrs r1, r2
    mov sb, r1
    str r1, [r5, #0x30]
    ldr r2, [r6, #0x14]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x34]
    mov sl, r1
    mov r0, sl
    orrs r0, r2
    mov sl, r0
    str r0, [r5, #0x34]
    ldr r2, [r6, #0x18]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x38]
    orrs r0, r2
    str r0, [sp, #0x20]
    str r0, [r5, #0x38]
    ldr r2, [r6, #0x1c]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r1, [r5, #0x3c]
    orrs r1, r2
    str r1, [r5, #0x3c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bhi lbl_0806e746
    b lbl_0806e920
lbl_0806e746:
    ldr r0, [sp, #0x1c]
    cmp r0, #0x10
    ble lbl_0806e7fc
    ldr r2, [r6, #0x20]
    adds r0, r2, #0
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r5, #0x40]
    orrs r0, r2
    str r0, [r5, #0x40]
    ldr r2, [r6, #0x24]
    adds r0, r2, #0
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    lsrs r2, r3
    ldr r0, [r5, #0x44]
    orrs r0, r2
    str r0, [r5, #0x44]
    ldr r2, [r6, #0x28]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, ip
    orrs r3, r0
    str r3, [r5, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x48]
    orrs r0, r2
    str r0, [r5, #0x48]
    ldr r2, [r6, #0x2c]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x4c]
    orrs r0, r2
    str r0, [r5, #0x4c]
    ldr r2, [r6, #0x30]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sb
    orrs r3, r0
    str r3, [r5, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x50]
    orrs r0, r2
    str r0, [r5, #0x50]
    ldr r2, [r6, #0x34]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x54]
    orrs r0, r2
    str r0, [r5, #0x54]
    ldr r2, [r6, #0x38]
    adds r0, r2, #0
    lsls r0, r4
    ldr r3, [sp, #0x20]
    orrs r3, r0
    str r3, [r5, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x58]
    orrs r0, r2
    str r0, [r5, #0x58]
    ldr r2, [r6, #0x3c]
    adds r0, r2, #0
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x5c]
    orrs r0, r2
    str r0, [r5, #0x5c]
    b lbl_0806e920
    .align 2, 0
lbl_0806e7f8: .4byte 0x02027700
lbl_0806e7fc:
    ldr r0, [r6, #0x20]
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r0, [r6, #0x24]
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    ldr r0, [r6, #0x28]
    lsls r0, r4
    mov r2, ip
    orrs r2, r0
    str r2, [r5, #0x28]
    ldr r0, [r6, #0x2c]
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [r6, #0x30]
    lsls r0, r4
    mov r2, sb
    orrs r2, r0
    str r2, [r5, #0x30]
    ldr r0, [r6, #0x34]
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [r6, #0x38]
    lsls r0, r4
    ldr r2, [sp, #0x20]
    orrs r2, r0
    str r2, [r5, #0x38]
    ldr r0, [r6, #0x3c]
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    b lbl_0806e920
lbl_0806e848:
    ldr r1, [r6]
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r1, [r6, #4]
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r1, [r6, #8]
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [r6, #0xc]
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r1, [r6, #0x10]
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [r6, #0x14]
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r1, [r6, #0x18]
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [r6, #0x1c]
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    b lbl_0806e920
lbl_0806e89a:
    ldr r0, [r5]
    ldr r1, [r6]
    orrs r0, r1
    str r0, [r5]
    ldr r0, [r5, #4]
    ldr r1, [r6, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [r5, #8]
    ldr r1, [r6, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r0, [r5, #0xc]
    ldr r1, [r6, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [r5, #0x10]
    ldr r1, [r6, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r0, [r5, #0x14]
    ldr r1, [r6, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [r5, #0x18]
    ldr r1, [r6, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r0, [r5, #0x1c]
    ldr r1, [r6, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r3, [sp, #0x18]
    cmp r3, #8
    bls lbl_0806e920
    ldr r0, [r5, #0x20]
    ldr r1, [r6, #0x20]
    orrs r0, r1
    str r0, [r5, #0x20]
    ldr r0, [r5, #0x24]
    ldr r1, [r6, #0x24]
    orrs r0, r1
    str r0, [r5, #0x24]
    ldr r0, [r5, #0x28]
    ldr r1, [r6, #0x28]
    orrs r0, r1
    str r0, [r5, #0x28]
    ldr r0, [r5, #0x2c]
    ldr r1, [r6, #0x2c]
    orrs r0, r1
    str r0, [r5, #0x2c]
    ldr r0, [r5, #0x30]
    ldr r1, [r6, #0x30]
    orrs r0, r1
    str r0, [r5, #0x30]
    ldr r0, [r5, #0x34]
    ldr r1, [r6, #0x34]
    orrs r0, r1
    str r0, [r5, #0x34]
    ldr r0, [r5, #0x38]
    ldr r1, [r6, #0x38]
    orrs r0, r1
    str r0, [r5, #0x38]
    ldr r0, [r5, #0x3c]
    ldr r1, [r6, #0x3c]
    orrs r0, r1
    str r0, [r5, #0x3c]
lbl_0806e920:
    ldr r0, [sp, #0x28]
    mov sl, r0
    cmp r0, #1
    bgt lbl_0806e92a
    b lbl_0806e4c4
lbl_0806e92a:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start draw_character_for_message
draw_character_for_message: @ 0x0806e93c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e9e8 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov ip, r0
lbl_0806e97c:
    ldr r4, lbl_0806e9e8 @ =0x02027700
    mov r1, ip
    cmp r1, #0
    beq lbl_0806e986
    adds r4, #0x40
lbl_0806e986:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, ip
    lsls r1, r3, #0xa
    adds r3, r0, r1
    ldr r0, lbl_0806e9ec @ =0x08415460
    adds r5, r3, r0
    movs r6, #8
    str r6, [sp, #0x14]
    str r1, [sp, #0x34]
    ldr r7, [sp, #0x18]
    cmp r7, #8
    bls lbl_0806e9a4
    movs r0, #0x10
    str r0, [sp, #0x14]
lbl_0806e9a4:
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    str r1, [sp, #0x30]
    mov r2, ip
    adds r2, #1
    str r2, [sp, #0x38]
    ldr r3, [sp, #0x14]
    cmp r3, #0
    bgt lbl_0806e9b8
    b lbl_0806eb28
lbl_0806e9b8:
    ldr r6, lbl_0806e9f0 @ =0x08760338
    mov sb, r6
    ldr r7, lbl_0806e9f4 @ =0x08760398
    mov r8, r7
    mov sl, r3
lbl_0806e9c2:
    ldr r6, [r5]
    movs r1, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e9ce
    adds r1, r0, #0
lbl_0806e9ce:
    mov r3, sb
    ldr r2, [r3]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806e9f8
    mov r7, r8
    ldr r0, [r7]
    ands r0, r2
    adds r3, r2, #0
    cmp r0, #0
    beq lbl_0806e9fc
    adds r3, r1, #0
    b lbl_0806e9fc
    .align 2, 0
lbl_0806e9e8: .4byte 0x02027700
lbl_0806e9ec: .4byte 0x08415460
lbl_0806e9f0: .4byte 0x08760338
lbl_0806e9f4: .4byte 0x08760398
lbl_0806e9f8:
    ldr r0, lbl_0806ea18 @ =0x087603b8
    ldr r3, [r0]
lbl_0806e9fc:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #4]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea20
    mov r7, r8
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea1c
    orrs r3, r1
    b lbl_0806ea26
    .align 2, 0
lbl_0806ea18: .4byte 0x087603b8
lbl_0806ea1c:
    orrs r3, r2
    b lbl_0806ea26
lbl_0806ea20:
    ldr r2, lbl_0806ea40 @ =0x087603b8
    ldr r0, [r2, #4]
    orrs r3, r0
lbl_0806ea26:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #8]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea48
    mov r7, r8
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea44
    orrs r3, r1
    b lbl_0806ea4e
    .align 2, 0
lbl_0806ea40: .4byte 0x087603b8
lbl_0806ea44:
    orrs r3, r2
    b lbl_0806ea4e
lbl_0806ea48:
    ldr r2, lbl_0806ea68 @ =0x087603b8
    ldr r0, [r2, #8]
    orrs r3, r0
lbl_0806ea4e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0xc]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea70
    mov r7, r8
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea6c
    orrs r3, r1
    b lbl_0806ea76
    .align 2, 0
lbl_0806ea68: .4byte 0x087603b8
lbl_0806ea6c:
    orrs r3, r2
    b lbl_0806ea76
lbl_0806ea70:
    ldr r2, lbl_0806ea90 @ =0x087603b8
    ldr r0, [r2, #0xc]
    orrs r3, r0
lbl_0806ea76:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x10]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea98
    mov r7, r8
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea94
    orrs r3, r1
    b lbl_0806ea9e
    .align 2, 0
lbl_0806ea90: .4byte 0x087603b8
lbl_0806ea94:
    orrs r3, r2
    b lbl_0806ea9e
lbl_0806ea98:
    ldr r2, lbl_0806eab8 @ =0x087603b8
    ldr r0, [r2, #0x10]
    orrs r3, r0
lbl_0806ea9e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x14]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eac0
    mov r7, r8
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eabc
    orrs r3, r1
    b lbl_0806eac6
    .align 2, 0
lbl_0806eab8: .4byte 0x087603b8
lbl_0806eabc:
    orrs r3, r2
    b lbl_0806eac6
lbl_0806eac0:
    ldr r2, lbl_0806eae0 @ =0x087603b8
    ldr r0, [r2, #0x14]
    orrs r3, r0
lbl_0806eac6:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x18]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eae8
    mov r7, r8
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eae4
    orrs r3, r1
    b lbl_0806eaee
    .align 2, 0
lbl_0806eae0: .4byte 0x087603b8
lbl_0806eae4:
    orrs r3, r2
    b lbl_0806eaee
lbl_0806eae8:
    ldr r2, lbl_0806eb08 @ =0x087603b8
    ldr r0, [r2, #0x18]
    orrs r3, r0
lbl_0806eaee:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x1c]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eb10
    mov r6, r8
    ldr r0, [r6, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eb0c
    orrs r3, r1
    b lbl_0806eb16
    .align 2, 0
lbl_0806eb08: .4byte 0x087603b8
lbl_0806eb0c:
    orrs r3, r2
    b lbl_0806eb16
lbl_0806eb10:
    ldr r7, lbl_0806ed90 @ =0x087603b8
    ldr r0, [r7, #0x1c]
    orrs r3, r0
lbl_0806eb16:
    stm r4!, {r3}
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    adds r5, #4
    mov r1, sl
    cmp r1, #0
    beq lbl_0806eb28
    b lbl_0806e9c2
lbl_0806eb28:
    movs r0, #0xff
    ldr r2, [sp, #0xc]
    ands r0, r2
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r3, [sp, #8]
    adds r0, r3, r0
    ldr r6, [sp, #0x34]
    adds r4, r0, r6
    ldr r7, [sp, #0x30]
    lsls r0, r7, #0xb
    adds r4, r4, r0
    ldr r5, lbl_0806ed94 @ =0x02027700
    mov r0, ip
    cmp r0, #0
    beq lbl_0806eb4a
    adds r5, #0x40
lbl_0806eb4a:
    movs r1, #7
    ldr r2, [sp, #0xc]
    ands r1, r2
    cmp r1, #0
    bne lbl_0806eb56
    b lbl_0806ee8c
lbl_0806eb56:
    lsls r3, r1, #2
    movs r0, #8
    subs r0, r0, r1
    mov sl, r0
    movs r0, #0x20
    subs r0, r0, r3
    str r0, [sp, #0x14]
    ldr r6, [sp, #0x18]
    adds r1, r1, r6
    str r1, [sp, #0x1c]
    cmp r1, #8
    bgt lbl_0806eb70
    b lbl_0806ee12
lbl_0806eb70:
    ldr r2, [r5]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, lbl_0806ed98 @ =0x087602f0
    adds r6, r3, r0
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r7, [sp, #0x14]
    lsrs r2, r7
    ldr r1, lbl_0806ed9c @ =0x08760314
    mov r7, sl
    lsls r0, r7, #2
    adds r7, r0, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x20]
    mov ip, r0
    mov r1, ip
    ands r1, r2
    mov ip, r1
    str r1, [r4, #0x20]
    ldr r2, [r5, #4]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x24]
    mov r8, r1
    mov r0, r8
    ands r0, r2
    mov r8, r0
    str r0, [r4, #0x24]
    ldr r2, [r5, #8]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x28]
    mov sb, r0
    mov r1, sb
    ands r1, r2
    mov sb, r1
    str r1, [r4, #0x28]
    ldr r2, [r5, #0xc]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x2c]
    mov sl, r1
    mov r0, sl
    ands r0, r2
    mov sl, r0
    str r0, [r4, #0x2c]
    ldr r2, [r5, #0x10]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x30]
    ands r0, r2
    str r0, [sp, #0x20]
    str r0, [r4, #0x30]
    ldr r2, [r5, #0x14]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x34]
    ands r0, r2
    str r0, [sp, #0x24]
    str r0, [r4, #0x34]
    ldr r2, [r5, #0x18]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x38]
    ands r0, r2
    str r0, [sp, #0x28]
    str r0, [r4, #0x38]
    ldr r2, [r5, #0x1c]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x3c]
    ands r0, r2
    str r0, [sp, #0x2c]
    str r0, [r4, #0x3c]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bhi lbl_0806ec94
    b lbl_0806ef12
lbl_0806ec94:
    ldr r2, [sp, #0x1c]
    cmp r2, #0x10
    bgt lbl_0806ec9c
    b lbl_0806eda0
lbl_0806ec9c:
    ldr r2, [r5, #0x20]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, ip
    ands r1, r0
    str r1, [r4, #0x20]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x40]
    ands r0, r2
    str r0, [r4, #0x40]
    ldr r2, [r5, #0x24]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x44]
    ands r0, r2
    str r0, [r4, #0x44]
    ldr r2, [r5, #0x28]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sb
    ands r1, r0
    str r1, [r4, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x48]
    ands r0, r2
    str r0, [r4, #0x48]
    ldr r2, [r5, #0x2c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sl
    ands r1, r0
    str r1, [r4, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x4c]
    ands r0, r2
    str r0, [r4, #0x4c]
    ldr r2, [r5, #0x30]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x50]
    ands r0, r2
    str r0, [r4, #0x50]
    ldr r2, [r5, #0x34]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x24]
    ands r1, r0
    str r1, [r4, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x54]
    ands r0, r2
    str r0, [r4, #0x54]
    ldr r2, [r5, #0x38]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x28]
    ands r1, r0
    str r1, [r4, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x58]
    ands r0, r2
    str r0, [r4, #0x58]
    ldr r2, [r5, #0x3c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x5c]
    ands r0, r2
    str r0, [r4, #0x5c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ed90: .4byte 0x087603b8
lbl_0806ed94: .4byte 0x02027700
lbl_0806ed98: .4byte 0x087602f0
lbl_0806ed9c: .4byte 0x08760314
lbl_0806eda0:
    ldr r0, [r5, #0x20]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, ip
    ands r7, r0
    str r7, [r4, #0x20]
    ldr r0, [r5, #0x24]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [r5, #0x28]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r2, sb
    ands r2, r0
    str r2, [r4, #0x28]
    ldr r0, [r5, #0x2c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, sl
    ands r7, r0
    str r7, [r4, #0x2c]
    ldr r0, [r5, #0x30]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [r5, #0x34]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r2, [sp, #0x24]
    ands r2, r0
    str r2, [r4, #0x34]
    ldr r0, [r5, #0x38]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r7, [sp, #0x28]
    ands r7, r0
    str r7, [r4, #0x38]
    ldr r0, [r5, #0x3c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    b lbl_0806ef12
lbl_0806ee12:
    ldr r1, [r5]
    lsls r1, r3
    ldr r2, lbl_0806ee88 @ =0x087602f0
    adds r2, r3, r2
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r1, [r5, #4]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r1, [r5, #8]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [r5, #0xc]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r1, [r5, #0x10]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [r5, #0x14]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [r5, #0x18]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [r5, #0x1c]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ee88: .4byte 0x087602f0
lbl_0806ee8c:
    ldr r0, [r4]
    ldr r1, [r5]
    ands r0, r1
    str r0, [r4]
    ldr r0, [r4, #4]
    ldr r1, [r5, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [r4, #8]
    ldr r1, [r5, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r0, [r4, #0xc]
    ldr r1, [r5, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [r4, #0x10]
    ldr r1, [r5, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r0, [r4, #0x14]
    ldr r1, [r5, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r0, [r4, #0x18]
    ldr r1, [r5, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r0, [r4, #0x1c]
    ldr r1, [r5, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bls lbl_0806ef12
    ldr r0, [r4, #0x20]
    ldr r1, [r5, #0x20]
    ands r0, r1
    str r0, [r4, #0x20]
    ldr r0, [r4, #0x24]
    ldr r1, [r5, #0x24]
    ands r0, r1
    str r0, [r4, #0x24]
    ldr r0, [r4, #0x28]
    ldr r1, [r5, #0x28]
    ands r0, r1
    str r0, [r4, #0x28]
    ldr r0, [r4, #0x2c]
    ldr r1, [r5, #0x2c]
    ands r0, r1
    str r0, [r4, #0x2c]
    ldr r0, [r4, #0x30]
    ldr r1, [r5, #0x30]
    ands r0, r1
    str r0, [r4, #0x30]
    ldr r0, [r4, #0x34]
    ldr r1, [r5, #0x34]
    ands r0, r1
    str r0, [r4, #0x34]
    ldr r0, [r4, #0x38]
    ldr r1, [r5, #0x38]
    ands r0, r1
    str r0, [r4, #0x38]
    ldr r0, [r4, #0x3c]
    ldr r1, [r5, #0x3c]
    ands r0, r1
    str r0, [r4, #0x3c]
lbl_0806ef12:
    ldr r3, [sp, #0x38]
    mov ip, r3
    cmp r3, #1
    bgt lbl_0806ef1c
    b lbl_0806e97c
lbl_0806ef1c:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start draw_location_text_characters
draw_location_text_characters: @ 0x0806ef2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r1, #0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0806ef48
    movs r0, #0x80
    lsls r0, r0, #0x12
    mov sl, r0
    b lbl_0806ef72
lbl_0806ef48:
    cmp r0, #2
    bne lbl_0806f00a
    ldr r1, lbl_0806efa8 @ =0x02000800
    mov sl, r1
    ldr r2, [r6]
    ldrh r0, [r2]
    movs r1, #0xfe
    lsls r1, r1, #8
    cmp r0, r1
    beq lbl_0806ef6c
    adds r3, r1, #0
lbl_0806ef5e:
    adds r0, r2, #0
    adds r1, r0, #2
    adds r2, r1, #0
    ldrh r0, [r0, #2]
    cmp r0, r3
    bne lbl_0806ef5e
    str r1, [r6]
lbl_0806ef6c:
    ldr r0, [r6]
    adds r0, #2
    str r0, [r6]
lbl_0806ef72:
    movs r7, #0
    movs r0, #0
    mov r8, r0
    ldr r3, [r6]
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r3]
    cmp r1, ip
    beq lbl_0806f00a
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806f00a
    movs r0, #0xff
    mov sb, r0
lbl_0806ef92:
    movs r5, #1
    ldrh r2, [r3]
    mov r1, ip
    ands r1, r2
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efac
    mov r4, sb
    ands r4, r2
    b lbl_0806efec
    .align 2, 0
lbl_0806efa8: .4byte 0x02000800
lbl_0806efac:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efbc
    movs r4, #0
    mov r7, sb
    ands r7, r2
    b lbl_0806efec
lbl_0806efbc:
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efd0
    movs r4, #0
    mov r8, sb
    mov r1, r8
    ands r1, r2
    mov r8, r1
    movs r5, #0
lbl_0806efd0:
    cmp r5, #0
    beq lbl_0806efec
    ldrh r0, [r3]
    bl get_chararcter_width
    adds r4, r0, #0
    ldr r0, [r6]
    ldrh r0, [r0]
    lsls r2, r7, #0x10
    lsrs r2, r2, #0x10
    mov r3, r8
    mov r1, sl
    bl draw_character_for_message
lbl_0806efec:
    ldr r0, [r6]
    adds r2, r0, #2
    str r2, [r6]
    adds r7, r7, r4
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r0, #2]
    cmp r1, ip
    beq lbl_0806f00a
    adds r3, r2, #0
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806ef92
lbl_0806f00a:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start draw_location_text
draw_location_text: @ 0x0806f018
    push {r4, r5, r6, lr}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    ldr r1, lbl_0806f088 @ =0x0000ffff
    movs r6, #0x80
    lsls r6, r6, #0x12
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    bl BitFill
    ldr r1, lbl_0806f08c @ =0x08760764
    ldr r0, lbl_0806f090 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    lsls r4, r4, #2
    adds r4, r4, r0
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r0, #1
    add r1, sp, #4
    bl draw_location_text_characters
    ldr r0, lbl_0806f094 @ =0x040000d4
    str r6, [r0]
    lsls r5, r5, #0xb
    ldr r2, lbl_0806f098 @ =0x06014000
    adds r1, r5, r2
    str r1, [r0, #4]
    ldr r2, lbl_0806f09c @ =0x840000e0
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0806f0a0 @ =0x02000400
    str r1, [r0]
    ldr r1, lbl_0806f0a4 @ =0x06014400
    adds r5, r5, r1
    str r5, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    add sp, #8
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f088: .4byte 0x0000ffff
lbl_0806f08c: .4byte 0x08760764
lbl_0806f090: .4byte gLanguage
lbl_0806f094: .4byte 0x040000d4
lbl_0806f098: .4byte 0x06014000
lbl_0806f09c: .4byte 0x840000e0
lbl_0806f0a0: .4byte 0x02000400
lbl_0806f0a4: .4byte 0x06014400

    thumb_func_start sub_0806f0a8
sub_0806f0a8: @ 0x0806f0a8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov ip, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r7, lbl_0806f0ec @ =gCurrentMessage
    cmp r2, #0xf
    bne lbl_0806f0da
    adds r0, r7, #0
    ldr r1, lbl_0806f0f0 @ =0x0840dc50
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    adds r0, r3, #0
    cmp r3, #0x23
    bls lbl_0806f0d4
    movs r0, #0x23
lbl_0806f0d4:
    strb r0, [r7, #0xa]
    mov r0, ip
    strb r0, [r7, #0xb]
lbl_0806f0da:
    ldrb r0, [r7, #0xc]
    cmp r0, #4
    bls lbl_0806f0e2
    b lbl_0806f23e
lbl_0806f0e2:
    lsls r0, r0, #2
    ldr r1, lbl_0806f0f4 @ =lbl_0806f0f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f0ec: .4byte gCurrentMessage
lbl_0806f0f0: .4byte 0x0840dc50
lbl_0806f0f4: .4byte lbl_0806f0f8
lbl_0806f0f8: @ jump table
    .4byte lbl_0806f10c @ case 0
    .4byte lbl_0806f13c @ case 1
    .4byte lbl_0806f180 @ case 2
    .4byte lbl_0806f218 @ case 3
    .4byte lbl_0806f23e @ case 4
lbl_0806f10c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f134 @ =0x06014000
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f138 @ =0x06014400
    b lbl_0806f160
    .align 2, 0
lbl_0806f134: .4byte 0x06014000
lbl_0806f138: .4byte 0x06014400
lbl_0806f13c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f178 @ =0x06014800
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f17c @ =0x06014c00
lbl_0806f160:
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f24c
    .align 2, 0
lbl_0806f178: .4byte 0x06014800
lbl_0806f17c: .4byte 0x06014c00
lbl_0806f180:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f18e
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f196
lbl_0806f18e:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f196:
    cmp r2, #1
    bne lbl_0806f1a2
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f1a2:
    cmp r5, #0
    beq lbl_0806f24c
    ldr r4, lbl_0806f1e8 @ =gCurrentMessage
    ldr r6, lbl_0806f1ec @ =0x08760780
lbl_0806f1aa:
    ldr r0, lbl_0806f1f0 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f1f4 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f1fe
    cmp r0, #2
    bgt lbl_0806f1f8
    cmp r0, #1
    beq lbl_0806f204
    b lbl_0806f20a
    .align 2, 0
lbl_0806f1e8: .4byte gCurrentMessage
lbl_0806f1ec: .4byte 0x08760780
lbl_0806f1f0: .4byte gLanguage
lbl_0806f1f4: .4byte 0x06014000
lbl_0806f1f8:
    cmp r0, #4
    beq lbl_0806f204
    b lbl_0806f20a
lbl_0806f1fe:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f204:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f24c
lbl_0806f20a:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f24c
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f1aa
    b lbl_0806f24c
lbl_0806f218:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f234
    ldr r0, lbl_0806f248 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f234
    bl finish_collecting_ability
lbl_0806f234:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f23e:
    ldrb r0, [r7, #7]
    b lbl_0806f24e
    .align 2, 0
lbl_0806f244: .4byte gCurrentMessage
lbl_0806f248: .4byte gCurrentItemBeingAcquired
lbl_0806f24c:
    movs r0, #0
lbl_0806f24e:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start start_message
start_message: @ 0x0806f258
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_0806f284 @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f288 @ =0x0840dc50
    ldm r1!, {r5, r6, r7}
    stm r2!, {r5, r6, r7}
    ldr r1, [r1]
    str r1, [r2]
    adds r1, r0, #0
    cmp r0, #0x23
    bls lbl_0806f278
    movs r1, #0x23
lbl_0806f278:
    strb r1, [r3, #0xa]
    strb r4, [r3, #0xb]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f284: .4byte gCurrentMessage
lbl_0806f288: .4byte 0x0840dc50

    thumb_func_start process_item_banner_text
process_item_banner_text: @ 0x0806f28c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f2a8 @ =gCurrentMessage
    ldrb r2, [r0, #0xc]
    adds r7, r0, #0
    cmp r2, #4
    bls lbl_0806f29c
    b lbl_0806f3ea
lbl_0806f29c:
    lsls r0, r2, #2
    ldr r1, lbl_0806f2ac @ =lbl_0806f2b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f2a8: .4byte gCurrentMessage
lbl_0806f2ac: .4byte lbl_0806f2b0
lbl_0806f2b0: @ jump table
    .4byte lbl_0806f2c4 @ case 0
    .4byte lbl_0806f2f4 @ case 1
    .4byte lbl_0806f338 @ case 2
    .4byte lbl_0806f3c4 @ case 3
    .4byte lbl_0806f3ea @ case 4
lbl_0806f2c4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f2ec @ =0x06014000
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f2f0 @ =0x06014400
    b lbl_0806f318
    .align 2, 0
lbl_0806f2ec: .4byte 0x06014000
lbl_0806f2f0: .4byte 0x06014400
lbl_0806f2f4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f330 @ =0x06014800
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f334 @ =0x06014c00
lbl_0806f318:
    adds r2, r2, r3
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f3f8
    .align 2, 0
lbl_0806f330: .4byte 0x06014800
lbl_0806f334: .4byte 0x06014c00
lbl_0806f338:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f346
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f34e
lbl_0806f346:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f34e:
    cmp r5, #0
    beq lbl_0806f3f8
    ldr r4, lbl_0806f394 @ =gCurrentMessage
    ldr r6, lbl_0806f398 @ =0x08760780
lbl_0806f356:
    ldr r0, lbl_0806f39c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f3a0 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f3aa
    cmp r0, #2
    bgt lbl_0806f3a4
    cmp r0, #1
    beq lbl_0806f3b0
    b lbl_0806f3b6
    .align 2, 0
lbl_0806f394: .4byte gCurrentMessage
lbl_0806f398: .4byte 0x08760780
lbl_0806f39c: .4byte gLanguage
lbl_0806f3a0: .4byte 0x06014000
lbl_0806f3a4:
    cmp r0, #4
    beq lbl_0806f3b0
    b lbl_0806f3b6
lbl_0806f3aa:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f3b0:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f3f8
lbl_0806f3b6:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f3f8
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f356
    b lbl_0806f3f8
lbl_0806f3c4:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f3e0
    ldr r0, lbl_0806f3f4 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f3e0
    bl finish_collecting_ability
lbl_0806f3e0:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f3ea:
    ldrb r0, [r7, #7]
    b lbl_0806f3fa
    .align 2, 0
lbl_0806f3f0: .4byte gCurrentMessage
lbl_0806f3f4: .4byte gCurrentItemBeingAcquired
lbl_0806f3f8:
    movs r0, #0
lbl_0806f3fa:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TextStartStory
TextStartStory: @ 0x0806f404
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f41c @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f420 @ =0x0840dc60
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f41c: .4byte gCurrentMessage
lbl_0806f420: .4byte 0x0840dc60

    thumb_func_start TextProcessStory
TextProcessStory: @ 0x0806f424
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f440 @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r6, r0, #0
    cmp r1, #4
    bls lbl_0806f434
    b lbl_0806f594
lbl_0806f434:
    lsls r0, r1, #2
    ldr r1, lbl_0806f444 @ =lbl_0806f448
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f440: .4byte gCurrentMessage
lbl_0806f444: .4byte lbl_0806f448
lbl_0806f448: @ jump table
    .4byte lbl_0806f45c @ case 0
    .4byte lbl_0806f49c @ case 1
    .4byte lbl_0806f4d4 @ case 2
    .4byte lbl_0806f588 @ case 3
    .4byte lbl_0806f594 @ case 4
lbl_0806f45c:
    ldrb r1, [r6, #0xa]
    cmp r1, #1
    bne lbl_0806f46a
    movs r0, #2
    strb r0, [r6, #0xc]
    strb r1, [r6, #0xb]
    b lbl_0806f598
lbl_0806f46a:
    ldr r2, lbl_0806f494 @ =0x06007000
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f498 @ =0x06007400
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    movs r0, #1
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f494: .4byte 0x06007000
lbl_0806f498: .4byte 0x06007400
lbl_0806f49c:
    ldr r2, lbl_0806f4c8 @ =0x06007800
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f4cc @ =0x06007c00
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r1, lbl_0806f4d0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f4c8: .4byte 0x06007800
lbl_0806f4cc: .4byte 0x06007c00
lbl_0806f4d0: .4byte gCurrentMessage
lbl_0806f4d4:
    movs r7, #6
    ldrb r0, [r6, #0xb]
    cmp r0, #0
    beq lbl_0806f4f4
    ldrb r0, [r6, #7]
    cmp r0, #9
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f4f0 @ =0x06013000
    b lbl_0806f506
    .align 2, 0
lbl_0806f4f0: .4byte 0x06013000
lbl_0806f4f4:
    ldrb r0, [r6, #7]
    cmp r0, #1
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f514 @ =0x06007000
lbl_0806f506:
    adds r5, r0, r1
    cmp r7, #0
    bne lbl_0806f518
lbl_0806f50c:
    movs r0, #3
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f514: .4byte 0x06007000
lbl_0806f518:
    ldr r4, lbl_0806f54c @ =gCurrentMessage
    ldr r6, lbl_0806f550 @ =0x0875fee0
lbl_0806f51c:
    ldr r0, lbl_0806f554 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #2
    beq lbl_0806f55e
    cmp r1, #2
    bgt lbl_0806f558
    cmp r1, #1
    beq lbl_0806f564
    b lbl_0806f56a
    .align 2, 0
lbl_0806f54c: .4byte gCurrentMessage
lbl_0806f550: .4byte 0x0875fee0
lbl_0806f554: .4byte gLanguage
lbl_0806f558:
    cmp r1, #4
    beq lbl_0806f564
    b lbl_0806f56a
lbl_0806f55e:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f564:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f598
lbl_0806f56a:
    ldr r2, lbl_0806f584 @ =gCurrentMessage
    ldrb r0, [r2, #0xb]
    movs r1, #2
    cmp r0, #0
    beq lbl_0806f576
    movs r1, #0xa
lbl_0806f576:
    ldrb r0, [r2, #7]
    cmp r0, r1
    bge lbl_0806f598
    subs r7, #1
    cmp r7, #0
    bne lbl_0806f51c
    b lbl_0806f598
    .align 2, 0
lbl_0806f584: .4byte gCurrentMessage
lbl_0806f588:
    ldrb r0, [r6, #7]
    adds r0, #1
    strb r0, [r6, #7]
    ldrb r0, [r6, #0xc]
    adds r0, #1
    strb r0, [r6, #0xc]
lbl_0806f594:
    ldrb r0, [r6, #7]
    b lbl_0806f59a
lbl_0806f598:
    movs r0, #0
lbl_0806f59a:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start start_file_screen_text
start_file_screen_text: @ 0x0806f5a4
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f5bc @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f5c0 @ =0x0840dc70
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f5bc: .4byte gCurrentMessage
lbl_0806f5c0: .4byte 0x0840dc70

    thumb_func_start sub_0806f5c4
sub_0806f5c4: @ 0x0806f5c4
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806f5ec @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_0806f668
    cmp r1, #1
    bgt lbl_0806f674
    cmp r1, #0
    bne lbl_0806f674
    movs r5, #8
    ldrb r0, [r2, #7]
    cmp r0, #3
    bhi lbl_0806f5e6
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    beq lbl_0806f5f0
lbl_0806f5e6:
    movs r0, #1
    strb r0, [r2, #0xc]
    b lbl_0806f678
    .align 2, 0
lbl_0806f5ec: .4byte gCurrentMessage
lbl_0806f5f0:
    ldrb r0, [r2, #7]
    lsls r0, r0, #0xb
    movs r1, #0xc0
    lsls r1, r1, #0x13
    adds r6, r0, r1
lbl_0806f5fa:
    ldr r4, lbl_0806f630 @ =gCurrentMessage
    ldr r1, lbl_0806f634 @ =0x0876079c
    ldr r0, lbl_0806f638 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r6, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f642
    cmp r0, #2
    bgt lbl_0806f63c
    cmp r0, #1
    beq lbl_0806f648
    b lbl_0806f654
    .align 2, 0
lbl_0806f630: .4byte gCurrentMessage
lbl_0806f634: .4byte 0x0876079c
lbl_0806f638: .4byte gLanguage
lbl_0806f63c:
    cmp r0, #4
    beq lbl_0806f648
    b lbl_0806f654
lbl_0806f642:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f648:
    ldr r1, lbl_0806f650 @ =gCurrentMessage
    movs r0, #0
    strh r0, [r1, #2]
    b lbl_0806f678
    .align 2, 0
lbl_0806f650: .4byte gCurrentMessage
lbl_0806f654:
    ldr r0, lbl_0806f664 @ =gCurrentMessage
    ldrb r0, [r0, #7]
    cmp r0, #3
    bhi lbl_0806f678
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f5fa
    b lbl_0806f678
    .align 2, 0
lbl_0806f664: .4byte gCurrentMessage
lbl_0806f668:
    ldrb r0, [r2, #7]
    adds r0, #1
    strb r0, [r2, #7]
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
lbl_0806f674:
    ldrb r0, [r2, #7]
    b lbl_0806f67a
lbl_0806f678:
    movs r0, #0
lbl_0806f67a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sub_0806f680
sub_0806f680: @ 0x0806f680
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r1, lbl_0806f6e4 @ =sNonGameplayRamPointer
    ldr r3, [r1]
    adds r0, r3, #0
    adds r0, #0x57
    adds r2, r3, #0
    adds r2, #0xc1
    ldrb r0, [r0]
    adds r6, r1, #0
    ldrb r2, [r2]
    cmp r0, r2
    beq lbl_0806f6cc
    ldr r0, lbl_0806f6e8 @ =0x00000123
    adds r2, r3, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    adds r0, #0x56
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    adds r0, #0x57
    strb r1, [r0]
    ldr r0, [r6]
    adds r0, #0x58
    strb r2, [r0]
    ldr r1, lbl_0806f6ec @ =gCurrentMessage
    ldr r0, lbl_0806f6f0 @ =0x0840dc80
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldr r0, [r0]
    str r0, [r1]
lbl_0806f6cc:
    ldr r0, [r6]
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #6
    bls lbl_0806f6d8
    b lbl_0806f974
lbl_0806f6d8:
    lsls r0, r0, #2
    ldr r1, lbl_0806f6f4 @ =lbl_0806f6f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f6e4: .4byte sNonGameplayRamPointer
lbl_0806f6e8: .4byte 0x00000123
lbl_0806f6ec: .4byte gCurrentMessage
lbl_0806f6f0: .4byte 0x0840dc80
lbl_0806f6f4: .4byte lbl_0806f6f8
lbl_0806f6f8: @ jump table
    .4byte lbl_0806f714 @ case 0
    .4byte lbl_0806f758 @ case 1
    .4byte lbl_0806f794 @ case 2
    .4byte lbl_0806f87e @ case 3
    .4byte lbl_0806f8dc @ case 4
    .4byte lbl_0806f930 @ case 5
    .4byte lbl_0806f974 @ case 6
lbl_0806f714:
    ldr r0, [r6]
    adds r0, #0x57
    ldrb r0, [r0]
    bl get_current_equipment_selected
    ldr r1, [r6]
    adds r1, #0x58
    strb r0, [r1]
    ldr r2, lbl_0806f74c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x58
    ldrb r0, [r0]
    cmp r0, #0x12
    bhi lbl_0806f750
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806f974
    .align 2, 0
lbl_0806f74c: .4byte 0x06007800
lbl_0806f750:
    adds r1, #0x56
    movs r0, #0x80
    strb r0, [r1]
    b lbl_0806f974
lbl_0806f758:
    ldr r2, lbl_0806f78c @ =gCurrentMessage
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r5, [r2, #9]
    cmp r0, r5
    bhi lbl_0806f778
    ldr r0, lbl_0806f790 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f778
    b lbl_0806f974
lbl_0806f778:
    movs r0, #0
    strb r0, [r2, #9]
    ldr r1, [r6]
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    strh r0, [r2, #4]
    b lbl_0806f974
    .align 2, 0
lbl_0806f78c: .4byte gCurrentMessage
lbl_0806f790: .4byte gChangedInput
lbl_0806f794:
    ldr r5, lbl_0806f7d4 @ =gCurrentMessage
    ldr r2, lbl_0806f7d8 @ =0x087602d4
    ldr r0, lbl_0806f7dc @ =gLanguage
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldr r0, [r6]
    adds r0, #0x58
    ldrb r0, [r0]
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, lbl_0806f7e0 @ =0x06007800
    adds r0, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #2
    bne lbl_0806f7f0
    ldrb r0, [r5, #7]
    cmp r0, #0
    beq lbl_0806f7e4
    movs r4, #5
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #4
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f7d4: .4byte gCurrentMessage
lbl_0806f7d8: .4byte 0x087602d4
lbl_0806f7dc: .4byte gLanguage
lbl_0806f7e0: .4byte 0x06007800
lbl_0806f7e4:
    movs r4, #0
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #6
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f7f0:
    cmp r4, #1
    bne lbl_0806f81a
    movs r4, #4
    movs r0, #0
    strh r0, [r5, #4]
    ldr r0, lbl_0806f80c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f810
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #5
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f80c: .4byte gDemoState
lbl_0806f810:
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #3
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f81a:
    movs r4, #0
lbl_0806f81c:
    cmp r4, #0
    bne lbl_0806f822
    b lbl_0806f974
lbl_0806f822:
    ldr r1, lbl_0806f84c @ =sNonGameplayRamPointer
    ldr r3, [r1]
    ldr r0, lbl_0806f850 @ =gCurrentMessage
    ldrh r0, [r0, #2]
    adds r0, #0xa
    lsls r0, r0, #2
    movs r5, #0x8d
    lsls r5, r5, #1
    adds r2, r3, r5
    strh r0, [r2]
    adds r6, r1, #0
    cmp r4, #4
    bne lbl_0806f854
    movs r0, #0x8c
    lsls r0, r0, #1
    adds r1, r3, r0
    movs r0, #0x90
    lsls r0, r0, #2
    strh r0, [r1]
    b lbl_0806f86e
    .align 2, 0
lbl_0806f84c: .4byte sNonGameplayRamPointer
lbl_0806f850: .4byte gCurrentMessage
lbl_0806f854:
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x89
    lsls r0, r0, #2
    strh r0, [r1]
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f86e
    movs r4, #0
lbl_0806f86e:
    ldr r0, [r6]
    movs r3, #0x8c
    lsls r3, r3, #1
    adds r0, r0, r3
    adds r1, r4, #0
    bl UpdateMenuOamDataID
    b lbl_0806f974
lbl_0806f87e:
    ldr r0, lbl_0806f8c4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f892
    ldr r0, lbl_0806f8c8 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f974
lbl_0806f892:
    ldr r2, lbl_0806f8cc @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r3, lbl_0806f8d0 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0x56
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_0806f8d4 @ =gCurrentMessage
    strh r2, [r0, #4]
    strh r2, [r0, #2]
    movs r1, #0xa
    strb r1, [r0, #9]
    ldr r0, [r3]
    ldr r4, lbl_0806f8d8 @ =0x00000123
    adds r2, r0, r4
    b lbl_0806f96c
    .align 2, 0
lbl_0806f8c4: .4byte gChangedInput
lbl_0806f8c8: .4byte gDemoState
lbl_0806f8cc: .4byte 0x06007800
lbl_0806f8d0: .4byte sNonGameplayRamPointer
lbl_0806f8d4: .4byte gCurrentMessage
lbl_0806f8d8: .4byte 0x00000123
lbl_0806f8dc:
    ldr r0, lbl_0806f918 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f974
    ldr r2, lbl_0806f91c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f920 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_0806f924 @ =gCurrentMessage
    ldr r0, lbl_0806f928 @ =0x0840dc80
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r2]
    ldr r5, lbl_0806f92c @ =0x00000123
    adds r2, r0, r5
    b lbl_0806f96c
    .align 2, 0
lbl_0806f918: .4byte gChangedInput
lbl_0806f91c: .4byte 0x06007800
lbl_0806f920: .4byte sNonGameplayRamPointer
lbl_0806f924: .4byte gCurrentMessage
lbl_0806f928: .4byte 0x0840dc80
lbl_0806f92c: .4byte 0x00000123
lbl_0806f930:
    ldr r4, lbl_0806f97c @ =gCurrentMessage
    ldrh r0, [r4, #4]
    adds r0, #1
    movs r5, #0
    strh r0, [r4, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bls lbl_0806f974
    ldr r2, lbl_0806f980 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f984 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    strh r5, [r4, #4]
    strh r5, [r4, #2]
    movs r0, #0xa
    strb r0, [r4, #9]
    ldr r0, [r2]
    ldr r1, lbl_0806f988 @ =0x00000123
    adds r2, r0, r1
lbl_0806f96c:
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
lbl_0806f974:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f97c: .4byte gCurrentMessage
lbl_0806f980: .4byte 0x06007800
lbl_0806f984: .4byte sNonGameplayRamPointer
lbl_0806f988: .4byte 0x00000123

    thumb_func_start TextProcessCurrentMessage
TextProcessCurrentMessage: @ 0x0806f98c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    adds r6, r1, #0
    mov r8, r2
    movs r5, #1
    rsbs r5, r5, #0
    ldrh r0, [r4, #4]
    adds r2, r0, #1
    strh r2, [r4, #4]
    ldr r0, lbl_0806fa04 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f9c4
    ldrb r1, [r4, #9]
    lsls r0, r2, #0x10
    lsrs r2, r0, #0x10
    cmp r1, r2
    bls lbl_0806f9bc
    movs r5, #0
lbl_0806f9bc:
    ldrb r0, [r4, #8]
    cmp r0, r2
    bls lbl_0806f9c4
    movs r5, #0
lbl_0806f9c4:
    cmp r5, #0
    bge lbl_0806faba
    movs r0, #0
    strb r0, [r4, #9]
    strh r0, [r4, #4]
    ldrh r0, [r4]
    lsls r0, r0, #1
    adds r6, r6, r0
    movs r0, #0xff
    lsls r0, r0, #8
    mov sb, r0
lbl_0806f9da:
    movs r7, #0
    ldrh r2, [r6]
    mov r1, sb
    ands r1, r2
    movs r0, #0xe1
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa48
    cmp r1, r0
    bgt lbl_0806fa12
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa44
    cmp r1, r0
    bgt lbl_0806fa08
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa36
    b lbl_0806fa60
    .align 2, 0
lbl_0806fa04: .4byte gButtonInput
lbl_0806fa08:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa3c
    b lbl_0806fa60
lbl_0806fa12:
    movs r0, #0xfd
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa50
    cmp r1, r0
    bgt lbl_0806fa28
    movs r0, #0xfc
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa54
    b lbl_0806fa60
lbl_0806fa28:
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa4c
    cmp r1, sb
    beq lbl_0806fa58
    b lbl_0806fa60
lbl_0806fa36:
    movs r7, #0xff
    ands r7, r2
    b lbl_0806fa6a
lbl_0806fa3c:
    movs r0, #0xff
    ands r0, r2
    strh r0, [r4, #2]
    b lbl_0806fa6a
lbl_0806fa44:
    strb r2, [r4, #6]
    b lbl_0806fa6a
lbl_0806fa48:
    strb r2, [r4, #9]
    b lbl_0806fa6a
lbl_0806fa4c:
    movs r5, #1
    b lbl_0806fa6a
lbl_0806fa50:
    movs r5, #4
    b lbl_0806fa6a
lbl_0806fa54:
    movs r5, #3
    b lbl_0806fa6a
lbl_0806fa58:
    movs r0, #1
    strb r0, [r4, #0xe]
    movs r5, #2
    b lbl_0806fa6a
lbl_0806fa60:
    ldrh r0, [r6]
    bl get_chararcter_width
    adds r7, r0, #0
    movs r5, #0
lbl_0806fa6a:
    ldrh r2, [r4, #2]
    adds r0, r2, r7
    cmp r0, #0xe0
    ble lbl_0806fa76
    movs r5, #1
    b lbl_0806faba
lbl_0806fa76:
    cmp r5, #0
    bge lbl_0806fa7e
    adds r6, #2
    b lbl_0806faaa
lbl_0806fa7e:
    cmp r5, #0
    bne lbl_0806faa0
    ldrb r0, [r4, #0xd]
    cmp r0, #0
    beq lbl_0806fa94
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_message
    b lbl_0806faaa
lbl_0806fa94:
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_text
    b lbl_0806faaa
lbl_0806faa0:
    cmp r5, #2
    beq lbl_0806faaa
    ldrb r0, [r4, #7]
    adds r0, #1
    strb r0, [r4, #7]
lbl_0806faaa:
    ldrh r0, [r4, #2]
    adds r0, r0, r7
    strh r0, [r4, #2]
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    cmp r5, #0
    blt lbl_0806f9da
lbl_0806faba:
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806facc
sub_0806facc: @ 0x0806facc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r1, lbl_0806fb48 @ =0x0000ffff
    ldr r0, lbl_0806fb4c @ =sEwramPointer
    ldr r2, [r0]
    movs r0, #0x80
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0xa0
    lsls r3, r3, #6
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r0, lbl_0806fb50 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0
    strb r1, [r0]
    ldr r1, lbl_0806fb54 @ =0x08760780
    ldr r0, lbl_0806fb58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    adds r0, #0x98
    ldr r4, [r0]
    ldr r5, lbl_0806fb5c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl BitFill
    ldrh r1, [r4]
    movs r0, #0xff
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fba8
    movs r2, #0xfe
    lsls r2, r2, #8
    mov r8, r2
    adds r7, r0, #0
    movs r6, #0x81
    lsls r6, r6, #8
lbl_0806fb34:
    movs r2, #1
    cmp r1, r8
    bne lbl_0806fb60
    ldr r1, lbl_0806fb5c @ =gCurrentMessage
    ldrh r0, [r1, #2]
    cmp r0, #0x70
    bhi lbl_0806fba8
    movs r0, #0x70
    strh r0, [r1, #2]
    b lbl_0806fba0
    .align 2, 0
lbl_0806fb48: .4byte 0x0000ffff
lbl_0806fb4c: .4byte sEwramPointer
lbl_0806fb50: .4byte sNonGameplayRamPointer
lbl_0806fb54: .4byte 0x08760780
lbl_0806fb58: .4byte gLanguage
lbl_0806fb5c: .4byte gCurrentMessage
lbl_0806fb60:
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806fb7c
    movs r2, #0xff
    lsls r2, r2, #8
    adds r0, r2, #0
    ands r0, r1
    cmp r0, r6
    bne lbl_0806fb7a
    strb r1, [r5, #6]
lbl_0806fb7a:
    movs r2, #0
lbl_0806fb7c:
    cmp r2, #0
    beq lbl_0806fba0
    ldrh r0, [r4]
    ldr r1, lbl_0806fbb4 @ =sEwramPointer
    ldr r1, [r1]
    movs r3, #0xc0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldrh r2, [r5, #2]
    ldrb r3, [r5, #6]
    bl draw_character_for_message
    ldrh r0, [r4]
    bl get_chararcter_width
    ldrh r1, [r5, #2]
    adds r1, r1, r0
    strh r1, [r5, #2]
lbl_0806fba0:
    adds r4, #2
    ldrh r1, [r4]
    cmp r1, r7
    bne lbl_0806fb34
lbl_0806fba8:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fbb4: .4byte sEwramPointer

    thumb_func_start sub_0806fbb8
sub_0806fbb8: @ 0x0806fbb8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r5, lbl_0806fbd4 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0xe9
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0806fc02
    cmp r0, #1
    bgt lbl_0806fbd8
    cmp r0, #0
    beq lbl_0806fbe2
    b lbl_0806fce8
    .align 2, 0
lbl_0806fbd4: .4byte sNonGameplayRamPointer
lbl_0806fbd8:
    cmp r0, #2
    beq lbl_0806fc80
    cmp r0, #3
    beq lbl_0806fca0
    b lbl_0806fce8
lbl_0806fbe2:
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fc02:
    movs r5, #3
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    ldr r7, lbl_0806fc50 @ =0x08760780
    ldr r6, lbl_0806fc54 @ =sEwramPointer
lbl_0806fc0a:
    ldr r0, lbl_0806fc58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x90
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0x80
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fc40
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc5c
lbl_0806fc40:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fc0a
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc4c: .4byte gCurrentMessage
lbl_0806fc50: .4byte 0x08760780
lbl_0806fc54: .4byte sEwramPointer
lbl_0806fc58: .4byte gLanguage
lbl_0806fc5c:
    ldr r0, lbl_0806fc6c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc6c: .4byte sNonGameplayRamPointer
lbl_0806fc70:
    ldr r0, lbl_0806fc7c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0x80
    strb r1, [r0]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc7c: .4byte sNonGameplayRamPointer
lbl_0806fc80:
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fca0:
    movs r5, #3
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    ldr r7, lbl_0806fcf4 @ =0x08760780
    ldr r6, lbl_0806fcf8 @ =sEwramPointer
lbl_0806fca8:
    ldr r0, lbl_0806fcfc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x94
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0xa0
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fcde
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc70
lbl_0806fcde:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fca8
lbl_0806fce8:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fcf0: .4byte gCurrentMessage
lbl_0806fcf4: .4byte 0x08760780
lbl_0806fcf8: .4byte sEwramPointer
lbl_0806fcfc: .4byte gLanguage

    thumb_func_start update_minimap_anim_palette
update_minimap_anim_palette: @ 0x0806fd00
    push {r4, r5, lr}
    ldr r0, lbl_0806fdf4 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    ldrb r4, [r3, #0x11]
    adds r5, r0, #0
    cmp r4, #0
    bne lbl_0806fd86
    ldrh r0, [r3, #0x18]
    adds r0, #1
    strh r0, [r3, #0x18]
    ldr r2, lbl_0806fdf8 @ =0x0840dcf0
    movs r1, #0x1a
    ldrsb r1, [r3, r1]
    adds r1, r1, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fd86
    strh r4, [r3, #0x18]
    ldrb r0, [r3, #0x1a]
    adds r0, #1
    strb r0, [r3, #0x1a]
    ldr r1, [r5]
    ldrb r0, [r1, #0x1a]
    cmp r0, #3
    bls lbl_0806fd3a
    movs r0, #0
    strb r0, [r1, #0x1a]
lbl_0806fd3a:
    ldr r1, lbl_0806fdfc @ =0x0840dcb0
    ldr r2, [r5]
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    mov ip, r0
    strh r3, [r0, #0x24]
    strh r3, [r0, #0x26]
    ldr r1, lbl_0806fe04 @ =0x0840dc90
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x64
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    ldr r1, lbl_0806fe08 @ =0x0840dcd0
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x44
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    adds r0, #0x3e
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
lbl_0806fd86:
    adds r4, r5, #0
    ldr r2, [r4]
    ldrb r0, [r2, #0x12]
    cmp r0, #7
    bhi lbl_0806fdee
    ldrh r0, [r2, #0x1c]
    adds r0, #1
    strh r0, [r2, #0x1c]
    movs r3, #0x1e
    ldrsb r3, [r2, r3]
    cmp r3, #0
    bge lbl_0806fda0
    rsbs r3, r3, #0
lbl_0806fda0:
    ldr r1, lbl_0806fe0c @ =0x0840dcf4
    adds r1, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fdee
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1e]
    adds r0, #1
    strb r0, [r2, #0x1e]
    ldr r1, [r4]
    movs r0, #0x1e
    ldrsb r0, [r1, r0]
    cmp r0, #0x10
    blt lbl_0806fdc8
    movs r0, #0xe
    rsbs r0, r0, #0
    strb r0, [r1, #0x1e]
lbl_0806fdc8:
    ldr r0, [r5]
    movs r3, #0x1e
    ldrsb r3, [r0, r3]
    cmp r3, #0
    bge lbl_0806fdd4
    rsbs r3, r3, #0
lbl_0806fdd4:
    ldr r1, lbl_0806fe10 @ =0x0840dd04
    ldrb r0, [r0, #0x12]
    adds r0, r0, r1
    ldrb r1, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r1, r1, r0
    ldr r2, lbl_0806fe14 @ =0x083fd2f0
    lsls r0, r3, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fdee:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fdf4: .4byte sNonGameplayRamPointer
lbl_0806fdf8: .4byte 0x0840dcf0
lbl_0806fdfc: .4byte 0x0840dcb0
lbl_0806fe00: .4byte 0x08754bb8
lbl_0806fe04: .4byte 0x0840dc90
lbl_0806fe08: .4byte 0x0840dcd0
lbl_0806fe0c: .4byte 0x0840dcf4
lbl_0806fe10: .4byte 0x0840dd04
lbl_0806fe14: .4byte 0x083fd2f0

    thumb_func_start LoadPauseScreenBgPalette
LoadPauseScreenBgPalette: @ 0x0806fe18
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806fecc @ =0x083fcef0
    adds r0, #0x9e
    ldrh r1, [r0]
    ldr r3, lbl_0806fed0 @ =sEwramPointer
    ldr r0, lbl_0806fed4 @ =0x0840dd04
    ldrb r0, [r0, #8]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r3]
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl BitFill
    movs r3, #0
    ldr r0, lbl_0806fed8 @ =sNonGameplayRamPointer
    mov ip, r0
    movs r5, #1
lbl_0806fe48:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xba
    ldrb r2, [r0]
    asrs r2, r3
    ands r2, r5
    ldr r4, lbl_0806fed0 @ =sEwramPointer
    ldr r6, lbl_0806fed4 @ =0x0840dd04
    cmp r2, #0
    bne lbl_0806fe6e
    ldr r0, [r4]
    adds r1, r3, r6
    ldrb r1, [r1]
    lsls r1, r1, #1
    movs r7, #0xd8
    lsls r7, r7, #7
    adds r0, r0, r7
    adds r0, r0, r1
    strh r2, [r0]
lbl_0806fe6e:
    adds r3, #1
    cmp r3, #6
    ble lbl_0806fe48
    ldr r2, lbl_0806fedc @ =gCurrentArea
    ldrb r0, [r2]
    cmp r0, #7
    bhi lbl_0806fe92
    ldr r1, [r4]
    adds r0, r0, r6
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r1, r1, r2
    adds r1, r1, r0
    ldr r0, lbl_0806fee0 @ =0x083fd2f0
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fe92:
    ldr r1, [r4]
    ldrb r0, [r6, #7]
    lsls r0, r0, #1
    movs r4, #0xd8
    lsls r4, r4, #7
    adds r3, r1, r4
    adds r0, r3, r0
    movs r5, #0
    strh r5, [r0]
    ldrb r2, [r6, #8]
    lsls r2, r2, #1
    adds r3, r3, r2
    strh r5, [r3]
    adds r4, r2, r4
    adds r1, r1, r4
    movs r0, #0xa0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl DMATransfer
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fecc: .4byte 0x083fcef0
lbl_0806fed0: .4byte sEwramPointer
lbl_0806fed4: .4byte 0x0840dd04
lbl_0806fed8: .4byte sNonGameplayRamPointer
lbl_0806fedc: .4byte gCurrentArea
lbl_0806fee0: .4byte 0x083fd2f0

    thumb_func_start update_suitType
update_suitType: @ 0x0806fee4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r2, lbl_0806ff04 @ =gEquipment
    ldrb r0, [r2, #0x12]
    cmp r0, r1
    beq lbl_0806fef4
    strb r1, [r2, #0x12]
lbl_0806fef4:
    ldrb r0, [r2, #0x12]
    cmp r0, #1
    beq lbl_0806ff24
    cmp r0, #1
    bgt lbl_0806ff08
    cmp r0, #0
    beq lbl_0806ff0e
    b lbl_0806ff48
    .align 2, 0
lbl_0806ff04: .4byte gEquipment
lbl_0806ff08:
    cmp r0, #2
    beq lbl_0806ff3c
    b lbl_0806ff48
lbl_0806ff0e:
    ldrh r0, [r2]
    strh r0, [r2, #6]
    ldrb r1, [r2, #0xc]
    movs r0, #0xf7
    ands r0, r1
    strb r0, [r2, #0xd]
    ldrb r1, [r2, #0xe]
    movs r0, #0xdb
    ands r0, r1
    strb r0, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff24:
    ldrh r0, [r2]
    movs r1, #0
    strh r0, [r2, #6]
    ldrh r0, [r2, #2]
    strh r0, [r2, #8]
    ldrb r0, [r2, #4]
    strb r0, [r2, #0xa]
    ldrb r0, [r2, #5]
    strb r0, [r2, #0xb]
    strb r1, [r2, #0xd]
    strb r1, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff3c:
    movs r0, #0x63
    strh r0, [r2, #6]
    movs r0, #0x80
    strb r0, [r2, #0xf]
    movs r0, #0x11
    strb r0, [r2, #0xd]
lbl_0806ff48:
    pop {r0}
    bx r0

    thumb_func_start draw_status_screen_item
draw_status_screen_item: @ 0x0806ff4c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #7
    bls lbl_0806ff64
    movs r0, #1
    b lbl_0806fff4
lbl_0806ff64:
    movs r4, #0
    ldr r0, lbl_08070004 @ =0x087603d8
    mov sb, r0
    ldr r1, lbl_08070008 @ =0x0840de50
    mov sl, r1
lbl_0806ff6e:
    lsls r1, r4, #1
    cmp r7, #0
    bne lbl_0806ff80
    adds r0, r1, r4
    add r0, sb
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, #2
    beq lbl_0806ffe4
lbl_0806ff80:
    adds r2, r1, r4
    mov r3, sb
    adds r0, r2, r3
    ldrb r0, [r0]
    lsls r1, r0, #2
    adds r1, r1, r0
    mov r5, sl
    adds r0, r1, r5
    ldrb r0, [r0]
    adds r0, r0, r7
    ldr r3, lbl_0807000c @ =0x0840de52
    adds r1, r1, r3
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r3, r0, r1
    ldr r5, lbl_08070010 @ =0x087603d9
    adds r0, r2, r5
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, r7
    bls lbl_0806ffe4
    movs r4, #0
    ldr r1, lbl_08070014 @ =0x087603da
    adds r0, r2, r1
    ldrb r5, [r0]
    cmp r4, r5
    bge lbl_0806ffe4
    ldr r1, lbl_08070018 @ =sEwramPointer
    mov r8, r1
    movs r5, #0xe0
    lsls r5, r5, #7
    mov ip, r5
    str r0, [sp]
    lsls r0, r3, #1
    ldr r1, lbl_0807001c @ =0x0600c000
    adds r2, r0, r1
lbl_0806ffc8:
    lsls r0, r3, #1
    mov r5, r8
    ldr r1, [r5]
    add r1, ip
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
    adds r4, #1
    adds r2, #2
    adds r3, #1
    ldr r0, [sp]
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0806ffc8
lbl_0806ffe4:
    adds r4, r6, #0
    cmp r4, #5
    ble lbl_0806ff6e
    movs r4, #0
    cmp r7, #6
    bls lbl_0806fff2
    movs r4, #1
lbl_0806fff2:
    adds r0, r4, #0
lbl_0806fff4:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08070004: .4byte 0x087603d8
lbl_08070008: .4byte 0x0840de50
lbl_0807000c: .4byte 0x0840de52
lbl_08070010: .4byte 0x087603d9
lbl_08070014: .4byte 0x087603da
lbl_08070018: .4byte sEwramPointer
lbl_0807001c: .4byte 0x0600c000

    thumb_func_start sub_08070020
sub_08070020: @ 0x08070020
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r2, r1, #0x18
    cmp r2, #0x15
    bhi lbl_08070062
    mov r0, ip
    cmp r0, #0
    bne lbl_0807004c
    ldr r0, lbl_08070048 @ =0x0840df0c
    lsls r1, r2, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    b lbl_08070172
    .align 2, 0
lbl_08070048: .4byte 0x0840df0c
lbl_0807004c:
    mov r0, ip
    cmp r0, #1
    bne lbl_0807006c
    ldr r1, lbl_08070068 @ =0x0840df0c
    lsls r2, r2, #2
    adds r0, r2, r1
    ldrb r0, [r0]
    mov sb, r1
    adds r7, r2, #0
    cmp r0, #1
    bhi lbl_08070084
lbl_08070062:
    movs r0, #0
    b lbl_08070172
    .align 2, 0
lbl_08070068: .4byte 0x0840df0c
lbl_0807006c:
    ldr r0, lbl_08070080 @ =0x0840df0c
    lsls r1, r2, #2
    adds r3, r1, r0
    ldrb r2, [r3]
    mov sb, r0
    adds r7, r1, #0
    cmp r2, #3
    beq lbl_08070084
    ldrb r0, [r3, #3]
    b lbl_08070172
    .align 2, 0
lbl_08070080: .4byte 0x0840df0c
lbl_08070084:
    movs r5, #0
    mov r0, sb
    adds r2, r7, r0
    ldrb r6, [r2, #3]
    ldrb r0, [r2, #1]
    cmp r0, #1
    beq lbl_080700c8
    cmp r0, #1
    bgt lbl_0807009c
    cmp r0, #0
    beq lbl_080700a6
    b lbl_08070120
lbl_0807009c:
    cmp r0, #2
    beq lbl_080700e8
    cmp r0, #3
    beq lbl_0807010c
    b lbl_08070120
lbl_080700a6:
    ldr r1, lbl_080700bc @ =0x0840d0f0
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700c0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc4
    ldr r2, lbl_080700c4 @ =gEquipment+0xD
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_080700bc: .4byte 0x0840d0f0
lbl_080700c0: .4byte sNonGameplayRamPointer
lbl_080700c4: .4byte gEquipment+0xD
lbl_080700c8:
    ldr r1, lbl_080700dc @ =0x0840d0f5
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700e0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xd1
    ldr r0, lbl_080700e4 @ =gEquipment+0xD
    b lbl_0807011e
    .align 2, 0
lbl_080700dc: .4byte 0x0840d0f5
lbl_080700e0: .4byte sNonGameplayRamPointer
lbl_080700e4: .4byte gEquipment+0xD
lbl_080700e8:
    ldr r1, lbl_08070100 @ =0x0840d0f6
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070104 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc9
    ldr r2, lbl_08070108 @ =gEquipment+0xF
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_08070100: .4byte 0x0840d0f6
lbl_08070104: .4byte sNonGameplayRamPointer
lbl_08070108: .4byte gEquipment+0xF
lbl_0807010c:
    ldr r1, lbl_0807013c @ =0x0840d0f8
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070140 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xcb
    ldr r0, lbl_08070144 @ =gEquipment+0xF
lbl_0807011e:
    mov r8, r0
lbl_08070120:
    mov r2, ip
    cmp r2, #1
    bne lbl_08070148
    mov r0, r8
    ldrb r2, [r0]
    adds r1, r5, #0
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    bics r2, r5
    mov r0, r8
    strb r2, [r0]
    b lbl_08070170
    .align 2, 0
lbl_0807013c: .4byte 0x0840d0f8
lbl_08070140: .4byte sNonGameplayRamPointer
lbl_08070144: .4byte gEquipment+0xF
lbl_08070148:
    movs r3, #0
    ldr r1, lbl_08070158 @ =0x0840d0fe
    mov r2, sb
    adds r0, r7, r2
    ldrb r0, [r0, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    b lbl_08070166
    .align 2, 0
lbl_08070158: .4byte 0x0840d0fe
lbl_0807015c:
    adds r4, #1
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r3, #1
lbl_08070166:
    cmp r3, r1
    bge lbl_08070170
    ldrb r0, [r4]
    cmp r0, r5
    bne lbl_0807015c
lbl_08070170:
    adds r0, r6, #0
lbl_08070172:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start draw_status_screen_tanks_amounts
draw_status_screen_tanks_amounts: @ 0x08070180
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    ldr r6, lbl_080701e0 @ =gEquipment
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_080701ec
    ldr r5, lbl_080701e4 @ =sEwramPointer
    ldr r2, [r5]
    movs r0, #0x80
    lsls r0, r0, #8
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_080701e8 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070324
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    b lbl_08070314
    .align 2, 0
lbl_080701e0: .4byte gEquipment
lbl_080701e4: .4byte sEwramPointer
lbl_080701e8: .4byte sNonGameplayRamPointer
lbl_080701ec:
    ldr r5, lbl_0807031c @ =sEwramPointer
    ldr r2, [r5]
    movs r0, #0xf0
    lsls r0, r0, #7
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    add r1, sp, #4
    ldr r7, lbl_08070320 @ =sNonGameplayRamPointer
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0xc2
    ldrb r0, [r0]
    strb r0, [r1, #1]
    adds r0, r2, #0
    adds r0, #0xc3
    ldrb r0, [r0]
    strb r0, [r1, #2]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070534
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_080706a4
    ldr r0, [r5]
    adds r0, r0, r4
    bl set_status_screen_bomb_visibilty
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070810
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070c2c
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    ldrh r0, [r6, #2]
    cmp r0, #0
    beq lbl_08070296
    ldrh r1, [r6, #8]
    movs r0, #7
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6, #2]
    movs r0, #8
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_08070296:
    ldrb r0, [r6, #4]
    cmp r0, #0
    beq lbl_080702b4
    ldrb r1, [r6, #0xa]
    movs r0, #9
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #4]
    movs r0, #0xa
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702b4:
    ldrb r0, [r6, #5]
    cmp r0, #0
    beq lbl_080702d2
    ldrb r1, [r6, #0xb]
    movs r0, #0xb
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #5]
    movs r0, #0xc
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702d2:
    add r0, sp, #4
    ldrb r0, [r0]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702e8
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1]
    adds r0, #0xc1
    strb r1, [r0]
lbl_080702e8:
    add r0, sp, #4
    ldrb r0, [r0, #1]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702fe
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #1]
    adds r0, #0xc2
    strb r1, [r0]
lbl_080702fe:
    add r0, sp, #4
    ldrb r0, [r0, #2]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_08070314
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #2]
    adds r0, #0xc3
    strb r1, [r0]
lbl_08070314:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807031c: .4byte sEwramPointer
lbl_08070320: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08070324
sub_08070324: @ 0x08070324
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    mov r8, r0
    movs r0, #0
    mov ip, r0
    ldr r5, lbl_08070404 @ =sNonGameplayRamPointer
    ldr r3, [r5]
    adds r3, #0xc4
    ldr r2, lbl_08070408 @ =0x0840de50
    ldrb r0, [r2]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r4, [r2, #2]
    adds r7, r0, r4
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldr r0, lbl_08070410 @ =0x087601dc
    ldr r0, [r0]
    ldrb r0, [r0]
    strb r0, [r3]
    ldrb r0, [r2, #3]
    subs r1, r0, r4
    mov sb, r5
    cmp r1, #0
    blt lbl_0807037a
    lsls r0, r6, #1
    mov r2, r8
    adds r3, r0, r2
    lsls r0, r7, #1
    adds r2, r0, r2
    adds r1, #1
lbl_0807036c:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_0807036c
lbl_0807037a:
    mov r5, sb
    ldr r0, [r5]
    ldrh r0, [r0]
    lsrs r0, r0, #9
    movs r6, #1
    mov r4, ip
    adds r4, #1
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    adds r2, r6, #0
    bics r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080703aa
    movs r0, #0x80
    strb r0, [r1]
lbl_080703aa:
    mov r3, sb
    ldr r0, [r3]
    adds r5, r0, #0
    adds r5, #0xc1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_080703ba
    strb r6, [r5]
lbl_080703ba:
    ldr r2, lbl_08070408 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r4, [r2]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r7, r0, r3
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldrb r0, [r2, #3]
    subs r1, r0, r3
    cmp r1, #0
    blt lbl_080703f8
    lsls r0, r6, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r7, #1
    adds r4, r0, r3
    adds r1, #1
lbl_080703ea:
    ldrh r0, [r2]
    strh r0, [r4]
    adds r2, #2
    adds r4, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_080703ea
lbl_080703f8:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070404: .4byte sNonGameplayRamPointer
lbl_08070408: .4byte 0x0840de50
lbl_0807040c: .4byte 0x0840de91
lbl_08070410: .4byte 0x087601dc

    thumb_func_start draw_status_screen_single_tank_amount
draw_status_screen_single_tank_amount: @ 0x08070414
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov sb, r2
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #4]
    subs r0, r4, #5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r1, lbl_080704c0 @ =0x0000b08c
    str r1, [sp, #8]
    cmp r0, #1
    bhi lbl_0807044a
    ldr r2, lbl_080704c4 @ =0x0000b2e0
    str r2, [sp, #8]
lbl_0807044a:
    ldr r0, lbl_080704c8 @ =sEwramPointer
    ldr r0, [r0]
    movs r3, #0xe0
    lsls r3, r3, #7
    adds r7, r0, r3
    ldr r3, lbl_080704cc @ =0x0840de50
    lsls r2, r4, #2
    adds r2, r2, r4
    adds r0, r2, r3
    ldrb r1, [r0]
    lsls r1, r1, #5
    adds r0, r3, #2
    adds r0, r2, r0
    ldrb r4, [r0]
    adds r1, r1, r4
    lsls r1, r1, #1
    adds r7, r7, r1
    adds r3, #3
    adds r2, r2, r3
    ldrb r0, [r2]
    subs r6, r0, r4
    ldr r1, lbl_080704d0 @ =0x0840d102
    lsls r0, r6, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    adds r6, #1
    movs r0, #0
    mov r8, r0
    movs r5, #0
    cmp r4, #0
    ble lbl_08070502
    ldr r2, lbl_080704d4 @ =0x00000fff
    adds r1, r2, #0
    ldr r0, [sp, #8]
    ands r0, r1
    lsls r0, r0, #0x10
    mov sl, r0
lbl_08070494:
    ldr r0, [sp]
    adds r1, r4, #0
    bl __divsi3
    movs r1, #0xa
    bl __modsi3
    adds r2, r0, #0
    cmp r2, #0
    bne lbl_080704d8
    movs r2, #0x80
    cmp r4, #1
    beq lbl_080704de
    mov r3, r8
    cmp r3, #0
    bne lbl_080704de
    ldr r0, [sp, #4]
    cmp r0, #0
    bne lbl_080704f0
    mov r1, sl
    lsrs r2, r1, #0x10
    b lbl_080704de
    .align 2, 0
lbl_080704c0: .4byte 0x0000b08c
lbl_080704c4: .4byte 0x0000b2e0
lbl_080704c8: .4byte sEwramPointer
lbl_080704cc: .4byte 0x0840de50
lbl_080704d0: .4byte 0x0840d102
lbl_080704d4: .4byte 0x00000fff
lbl_080704d8:
    movs r3, #1
    mov r8, r3
    adds r2, #0x80
lbl_080704de:
    cmp r2, #0
    beq lbl_080704f0
    lsls r1, r5, #1
    adds r1, r1, r7
    mov r3, sb
    lsls r0, r3, #0xc
    orrs r0, r2
    strh r0, [r1]
    b lbl_080704f2
lbl_080704f0:
    subs r5, #1
lbl_080704f2:
    adds r0, r4, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, r0, #0
    adds r5, #1
    cmp r4, #0
    bgt lbl_08070494
lbl_08070502:
    cmp r6, r5
    beq lbl_08070520
    ldr r1, lbl_08070530 @ =0x00000fff
    ldr r0, [sp, #8]
    ands r1, r0
    mov r2, sb
    lsls r0, r2, #0xc
    orrs r1, r0
    lsls r0, r5, #1
    adds r0, r0, r7
lbl_08070516:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r6, r5
    bne lbl_08070516
lbl_08070520:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070530: .4byte 0x00000fff

    thumb_func_start sub_08070534
sub_08070534: @ 0x08070534
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_08070684 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc4
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08070562
    movs r2, #0
lbl_08070556:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_08070556
lbl_08070562:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3]
    cmp ip, r3
    bge lbl_08070612
lbl_0807056c:
    adds r3, r4, #0
    movs r7, #0
    ldr r0, lbl_0807068c @ =0x087601dc
    ldr r0, [r0]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_08070690 @ =gEquipment
    cmp r0, #8
    bne lbl_08070594
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_08070590
    ldr r0, lbl_08070694 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070594
lbl_08070590:
    movs r3, #9
    movs r7, #0xa
lbl_08070594:
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    adds r7, r7, r0
    ldr r3, lbl_0807069c @ =0x0840de50
    ldrb r0, [r3]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #2]
    adds r6, r0, r2
    ldr r1, lbl_0807068c @ =0x087601dc
    ldr r0, [r1]
    adds r0, r0, r4
    ldrb r1, [r5, #0xc]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070608
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #3]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_080705f2
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_080705e4:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080705e4
lbl_080705f2:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_080706a0 @ =gEquipment+0xD
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070608:
    mov r4, r8
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0807056c
lbl_08070612:
    mov r4, ip
    cmp r4, #0
    beq lbl_08070676
    ldr r2, lbl_08070684 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807062a
    movs r0, #0x80
    strb r0, [r1]
lbl_0807062a:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807063a
    movs r0, #1
    strb r0, [r1]
lbl_0807063a:
    ldr r2, lbl_0807069c @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r6, r0, r3
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1, #1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r7, r0, r1
    ldrb r0, [r2, #3]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_08070676
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_08070668:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_08070668
lbl_08070676:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070684: .4byte sNonGameplayRamPointer
lbl_08070688: .4byte 0x0840d0fe
lbl_0807068c: .4byte 0x087601dc
lbl_08070690: .4byte gEquipment
lbl_08070694: .4byte gPauseScreenFlag
lbl_08070698: .4byte 0x0840de91
lbl_0807069c: .4byte 0x0840de50
lbl_080706a0: .4byte gEquipment+0xD

    thumb_func_start sub_080706a4
sub_080706a4: @ 0x080706a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_080707f0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc9
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r1, [r0, #2]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_080706d2
    movs r2, #0
lbl_080706c6:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_080706c6
lbl_080706d2:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3, #2]
    cmp ip, r3
    bge lbl_0807077c
lbl_080706dc:
    adds r3, r4, #0
    ldr r0, lbl_080707f8 @ =0x087601dc
    ldr r0, [r0, #8]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_080707fc @ =gEquipment
    cmp r0, #0x20
    bne lbl_08070700
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_080706fe
    ldr r0, lbl_08070800 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070700
lbl_080706fe:
    movs r3, #3
lbl_08070700:
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xa]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldr r3, lbl_08070808 @ =0x0840de50
    ldrb r0, [r3, #0xa]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #0xc]
    adds r7, r0, r2
    ldr r1, lbl_080707f8 @ =0x087601dc
    ldr r0, [r1, #8]
    adds r0, r0, r4
    ldrb r1, [r5, #0xe]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070772
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #0xd]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_0807075c
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_0807074e:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0807074e
lbl_0807075c:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_0807080c @ =gEquipment+0xF
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #2
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070772:
    mov r4, r8
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r0, [r0, #2]
    cmp r4, r0
    blt lbl_080706dc
lbl_0807077c:
    mov r4, ip
    cmp r4, #0
    beq lbl_080707e0
    ldr r2, lbl_080707f0 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070794
    movs r0, #0x82
    strb r0, [r1]
lbl_08070794:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080707a4
    movs r0, #0xa
    strb r0, [r1]
lbl_080707a4:
    ldr r2, lbl_08070808 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2, #0xa]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #0xc]
    adds r7, r0, r3
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xb]
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldrb r0, [r2, #0xd]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_080707e0
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_080707d2:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080707d2
lbl_080707e0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080707f0: .4byte sNonGameplayRamPointer
lbl_080707f4: .4byte 0x0840d0fe
lbl_080707f8: .4byte 0x087601dc
lbl_080707fc: .4byte gEquipment
lbl_08070800: .4byte gPauseScreenFlag
lbl_08070804: .4byte 0x0840de91
lbl_08070808: .4byte 0x0840de50
lbl_0807080c: .4byte gEquipment+0xF

    thumb_func_start sub_08070810
sub_08070810: @ 0x08070810
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov sb, r0
    movs r3, #0
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r1, [r0, #3]
    adds r5, r0, #0
    cmp r3, r1
    bge lbl_0807083c
    ldr r4, lbl_080709a8 @ =sNonGameplayRamPointer
    movs r2, #0
lbl_0807082e:
    ldr r0, [r4]
    adds r0, #0xcb
    adds r0, r0, r3
    strb r2, [r0]
    adds r3, #1
    cmp r3, r1
    blt lbl_0807082e
lbl_0807083c:
    movs r3, #0
    mov ip, r3
    ldrb r5, [r5, #3]
    cmp ip, r5
    bge lbl_080708f4
lbl_08070846:
    adds r2, r3, #1
    ldr r0, lbl_080709ac @ =0x087601dc
    ldr r0, [r0, #0xc]
    adds r0, r0, r3
    ldrb r0, [r0]
    str r2, [sp]
    ldr r1, lbl_080709b0 @ =gEquipment
    mov sl, r1
    cmp r0, #4
    bne lbl_08070870
    ldrb r0, [r1, #0x12]
    cmp r0, #1
    bne lbl_0807086c
    ldr r0, lbl_080709b4 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070870
lbl_0807086c:
    movs r2, #1
    rsbs r2, r2, #0
lbl_08070870:
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    adds r0, r0, r2
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r5, r0, r1
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r4, [r2, #0x11]
    adds r7, r0, r4
    ldr r1, lbl_080709ac @ =0x087601dc
    ldr r0, [r1, #0xc]
    adds r0, r0, r3
    mov r3, sl
    ldrb r1, [r3, #0xe]
    ldrb r3, [r0]
    ands r1, r3
    cmp r1, #0
    beq lbl_080708ea
    ldr r0, lbl_080709a8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xcb
    add r1, ip
    strb r3, [r1]
    ldrb r1, [r2, #0x12]
    subs r2, r1, r4
    adds r6, r0, #0
    mov r4, ip
    adds r4, #1
    cmp r2, #0
    blt lbl_080708ce
    lsls r0, r5, #1
    mov r5, sb
    adds r1, r0, r5
    lsls r0, r7, #1
    adds r3, r0, r5
    adds r2, #1
lbl_080708c0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_080708c0
lbl_080708ce:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r0, [r6]
    adds r0, #0xcb
    add r0, ip
    mov r2, sl
    ldrb r3, [r2, #0xf]
    ldrb r2, [r0]
    ands r2, r3
    movs r0, #3
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_080708ea:
    ldr r3, [sp]
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r0, [r0, #3]
    cmp r3, r0
    blt lbl_08070846
lbl_080708f4:
    mov r3, ip
    cmp r3, #0
    beq lbl_08070994
    ldr r2, lbl_080709a8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807090c
    movs r0, #0x83
    strb r0, [r1]
lbl_0807090c:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807091c
    movs r0, #0xc
    strb r0, [r1]
lbl_0807091c:
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r7, r0, r3
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    lsls r0, r0, #5
    ldrb r4, [r1, #0x11]
    adds r5, r0, r4
    ldrb r0, [r2, #0x12]
    subs r6, r0, r3
    mov sl, r1
    mov r8, r2
    mov r4, ip
    adds r4, #1
    cmp r6, #0
    blt lbl_0807095a
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, r6, #1
lbl_0807094c:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_0807094c
lbl_0807095a:
    mov r1, r8
    ldrb r0, [r1, #0xf]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r7, r0, r1
    mov r2, sl
    ldrb r0, [r2, #0x10]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r5, r0, r3
    mov r4, r8
    ldrb r0, [r4, #0x12]
    subs r2, r0, r1
    cmp r2, #0
    blt lbl_08070994
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, #1
lbl_08070986:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070986
lbl_08070994:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080709a4: .4byte 0x0840d0fe
lbl_080709a8: .4byte sNonGameplayRamPointer
lbl_080709ac: .4byte 0x087601dc
lbl_080709b0: .4byte gEquipment
lbl_080709b4: .4byte gPauseScreenFlag
lbl_080709b8: .4byte 0x0840de91
lbl_080709bc: .4byte 0x0840de50

    thumb_func_start set_status_screen_bomb_visibilty
set_status_screen_bomb_visibilty: @ 0x080709c0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    str r0, [sp]
    str r0, [sp, #4]
    ldr r2, lbl_08070ae8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xd1
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xd2
    strb r1, [r0]
    movs r7, #0
    ldr r3, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r3, #0xc]
    ldrb r0, [r0]
    ands r0, r1
    mov ip, r2
    cmp r0, #0
    beq lbl_08070a02
    movs r7, #2
    ldr r0, [r2]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a02:
    cmp r7, #0
    bne lbl_08070a08
    b lbl_08070bfe
lbl_08070a08:
    ldrb r0, [r3, #5]
    cmp r0, #0
    beq lbl_08070a1e
    movs r7, #3
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd2
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a1e:
    movs r6, #0
    cmp r6, r7
    blt lbl_08070a26
    b lbl_08070ba6
lbl_08070a26:
    ldr r2, lbl_08070af4 @ =0x0840de50
    mov r8, r2
    ldrb r3, [r2, #7]
    mov sl, r3
    ldrb r0, [r2, #8]
    subs r3, r0, r3
    str r3, [sp, #0xc]
    ldr r4, lbl_08070af8 @ =0x0840de91
    ldrb r4, [r4, #7]
    str r4, [sp, #8]
lbl_08070a3a:
    mov r1, r8
    ldrb r0, [r1, #5]
    adds r0, r0, r6
    lsls r0, r0, #5
    mov r2, sl
    adds r5, r0, r2
    ldr r3, lbl_08070af8 @ =0x0840de91
    ldrb r1, [r3, #5]
    ldr r0, lbl_08070afc @ =0x087603ea
    adds r0, r6, r0
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r3, r1, #5
    ldr r4, [sp, #8]
    adds r3, r3, r4
    adds r0, r6, #1
    mov sb, r0
    ldr r1, [sp, #0xc]
    cmp r1, #0
    blt lbl_08070a86
    mov r2, r8
    ldrb r1, [r2, #8]
    ldrb r0, [r2, #7]
    subs r1, r1, r0
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r4, r0, r3
    lsls r0, r5, #1
    ldr r2, [sp]
    adds r3, r0, r2
    adds r2, r1, #1
lbl_08070a78:
    ldrh r0, [r4]
    strh r0, [r3]
    adds r4, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070a78
lbl_08070a86:
    movs r2, #0
    cmp r6, #1
    bne lbl_08070b00
    ldr r0, lbl_08070ae8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd1
    ldrb r2, [r3]
    adds r1, r6, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070ade
    ldr r4, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ab6
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070ab6:
    mov r3, ip
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #4
    movs r3, #0
    orrs r0, r2
    strb r0, [r1]
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ade
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070ade:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd1
    b lbl_08070b60
    .align 2, 0
lbl_08070ae8: .4byte sNonGameplayRamPointer
lbl_08070aec: .4byte gEquipment
lbl_08070af0: .4byte 0x087601dc
lbl_08070af4: .4byte 0x0840de50
lbl_08070af8: .4byte 0x0840de91
lbl_08070afc: .4byte 0x087603ea
lbl_08070b00:
    cmp r6, #2
    bne lbl_08070b62
    ldr r0, lbl_08070c10 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd2
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070b5a
    ldr r4, lbl_08070c14 @ =gEquipment
    ldr r0, lbl_08070c18 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b2e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070b2e:
    ldrb r0, [r4, #0xb]
    cmp r0, #0
    beq lbl_08070b42
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #4
    orrs r1, r2
    strb r1, [r0]
lbl_08070b42:
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b5a
    mov r3, ip
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070b5a:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd2
lbl_08070b60:
    ldrb r2, [r0]
lbl_08070b62:
    cmp r2, #0
    beq lbl_08070b9e
    movs r0, #0
    cmp r2, #0xf
    bne lbl_08070b6e
    movs r0, #1
lbl_08070b6e:
    adds r2, r0, #0
    ldr r0, lbl_08070c1c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070b8e
    ldr r0, lbl_08070c20 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bne lbl_08070b8e
    cmp r6, #2
    bne lbl_08070b8e
    movs r2, #0
lbl_08070b8e:
    lsls r1, r6, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #1
    movs r3, #0
    bl sub_08070e1c
lbl_08070b9e:
    mov r6, sb
    cmp r6, r7
    bge lbl_08070ba6
    b lbl_08070a3a
lbl_08070ba6:
    ldr r2, lbl_08070c24 @ =0x0840de50
    ldrb r0, [r2, #5]
    adds r0, r0, r7
    lsls r0, r0, #5
    ldrb r4, [r2, #7]
    adds r5, r0, r4
    cmp r7, #2
    beq lbl_08070bb8
    adds r7, #1
lbl_08070bb8:
    ldr r0, lbl_08070c28 @ =0x0840de91
    ldrb r1, [r0, #5]
    adds r1, r1, r7
    lsls r1, r1, #5
    ldrb r0, [r0, #7]
    adds r3, r1, r0
    ldrb r0, [r2, #8]
    subs r2, r0, r4
    ldr r0, lbl_08070c10 @ =sNonGameplayRamPointer
    mov ip, r0
    cmp r2, #0
    blt lbl_08070bec
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r1, r0, r3
    lsls r0, r5, #1
    ldr r4, [sp]
    adds r3, r0, r4
    adds r2, #1
lbl_08070bde:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070bde
lbl_08070bec:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070bfe
    movs r0, #8
    strb r0, [r1]
lbl_08070bfe:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070c10: .4byte sNonGameplayRamPointer
lbl_08070c14: .4byte gEquipment
lbl_08070c18: .4byte 0x087601dc
lbl_08070c1c: .4byte gPauseScreenFlag
lbl_08070c20: .4byte gCurrentItemBeingAcquired
lbl_08070c24: .4byte 0x0840de50
lbl_08070c28: .4byte 0x0840de91

    thumb_func_start sub_08070c2c
sub_08070c2c: @ 0x08070c2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov r8, r0
    movs r0, #0
    mov sl, r0
    ldr r3, lbl_08070d08 @ =gEquipment
    ldrh r0, [r3, #2]
    cmp r0, #0
    beq lbl_08070c58
    movs r1, #3
    mov sl, r1
    ldr r0, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0xd3
    ldrb r2, [r1]
    movs r0, #1
    orrs r0, r2
    strb r0, [r1]
lbl_08070c58:
    ldrb r0, [r3, #4]
    cmp r0, #0
    beq lbl_08070c7a
    movs r3, #5
    mov sl, r3
    ldr r3, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0xd4
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
    ldr r0, [r3]
    adds r0, #0xd3
    ldrb r1, [r0]
    orrs r2, r1
    strb r2, [r0]
lbl_08070c7a:
    mov r4, sl
    cmp r4, #0
    bne lbl_08070c82
    b lbl_08070e00
lbl_08070c82:
    movs r5, #0
    cmp r5, sl
    blt lbl_08070c8a
    b lbl_08070db2
lbl_08070c8a:
    ldr r7, lbl_08070d10 @ =0x0840de50
    ldrb r0, [r7, #0x16]
    str r0, [sp]
    ldrb r0, [r7, #0x17]
    ldr r1, [sp]
    subs r0, r0, r1
    str r0, [sp, #4]
lbl_08070c98:
    ldrb r0, [r7, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldr r3, [sp]
    adds r6, r0, r3
    ldr r1, lbl_08070d14 @ =0x0840de91
    ldrb r0, [r1, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    adds r0, r5, #1
    mov sb, r0
    ldr r1, [sp, #4]
    cmp r1, #0
    blt lbl_08070cd8
    ldrb r1, [r7, #0x17]
    ldrb r0, [r7, #0x16]
    subs r1, r1, r0
    lsls r0, r4, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r6, #1
    adds r3, r0, r3
    adds r4, r1, #1
lbl_08070cca:
    ldrh r0, [r2]
    strh r0, [r3]
    adds r2, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070cca
lbl_08070cd8:
    movs r4, #0
    cmp r5, #1
    bne lbl_08070d18
    ldr r0, lbl_08070d0c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd3
    ldrb r2, [r3]
    adds r1, r5, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d00
    ldr r0, lbl_08070d08 @ =gEquipment
    ldrh r0, [r0, #8]
    cmp r0, #0
    beq lbl_08070d00
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d00:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd3
    b lbl_08070d44
    .align 2, 0
lbl_08070d08: .4byte gEquipment
lbl_08070d0c: .4byte sNonGameplayRamPointer
lbl_08070d10: .4byte 0x0840de50
lbl_08070d14: .4byte 0x0840de91
lbl_08070d18:
    cmp r5, #3
    bne lbl_08070d46
    ldr r0, lbl_08070d84 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd4
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d3e
    ldr r0, lbl_08070d88 @ =gEquipment
    ldrb r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_08070d3e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d3e:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd4
lbl_08070d44:
    ldrb r4, [r0]
lbl_08070d46:
    cmp r4, #0
    beq lbl_08070daa
    movs r0, #0
    cmp r4, #3
    bne lbl_08070d52
    movs r0, #1
lbl_08070d52:
    adds r4, r0, #0
    ldr r0, lbl_08070d8c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070d94
    cmp r5, #1
    bne lbl_08070d70
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #3
    beq lbl_08070d98
lbl_08070d70:
    cmp r5, #3
    bne lbl_08070d9a
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    bne lbl_08070d9a
    b lbl_08070d98
    .align 2, 0
lbl_08070d84: .4byte sNonGameplayRamPointer
lbl_08070d88: .4byte gEquipment
lbl_08070d8c: .4byte gPauseScreenFlag
lbl_08070d90: .4byte gCurrentItemBeingAcquired
lbl_08070d94:
    cmp r0, #8
    bne lbl_08070d9a
lbl_08070d98:
    movs r4, #0
lbl_08070d9a:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r4, #0x18
    lsrs r2, r2, #0x18
    movs r0, #4
    movs r3, #0
    bl sub_08070e1c
lbl_08070daa:
    mov r5, sb
    cmp r5, sl
    bge lbl_08070db2
    b lbl_08070c98
lbl_08070db2:
    ldr r2, lbl_08070e10 @ =0x0840de50
    ldrb r0, [r2, #0x14]
    add r0, sl
    lsls r0, r0, #5
    ldrb r3, [r2, #0x16]
    adds r6, r0, r3
    ldr r1, lbl_08070e14 @ =0x0840de91
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    ldrb r0, [r2, #0x17]
    subs r2, r0, r3
    ldr r3, lbl_08070e18 @ =sNonGameplayRamPointer
    mov ip, r3
    cmp r2, #0
    blt lbl_08070dee
    lsls r0, r4, #1
    mov r4, r8
    adds r1, r0, r4
    lsls r0, r6, #1
    adds r3, r0, r4
    adds r4, r2, #1
lbl_08070de0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070de0
lbl_08070dee:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070e00
    movs r0, #6
    strb r0, [r1]
lbl_08070e00:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070e10: .4byte 0x0840de50
lbl_08070e14: .4byte 0x0840de91
lbl_08070e18: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08070e1c
sub_08070e1c: @ 0x08070e1c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsls r2, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov ip, r3
    ldr r4, lbl_08070eac @ =0x0840de50
    lsls r3, r0, #2
    adds r3, r3, r0
    adds r0, r3, r4
    lsrs r1, r1, #0x18
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r0, r4, #2
    adds r0, r3, r0
    ldrb r5, [r0]
    adds r1, r1, r5
    adds r4, #3
    adds r3, r3, r4
    ldrb r0, [r3]
    subs r4, r0, r5
    movs r0, #0xc0
    lsls r0, r0, #8
    cmp r2, #0
    beq lbl_08070e58
    movs r0, #0xb0
    lsls r0, r0, #8
lbl_08070e58:
    adds r5, r0, #0
    ldr r0, lbl_08070eb0 @ =sEwramPointer
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r0, r1, r0
    ldr r3, lbl_08070eb4 @ =0x00007002
    adds r2, r0, r3
    adds r7, r1, #0
    cmp r4, #1
    ble lbl_08070e82
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e70:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e70
lbl_08070e82:
    mov r0, ip
    cmp r0, #0
    beq lbl_08070ea6
    ldr r3, lbl_08070ebc @ =0x0600c002
    adds r2, r7, r3
    cmp r4, #1
    ble lbl_08070ea6
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e94:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e94
lbl_08070ea6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070eac: .4byte 0x0840de50
lbl_08070eb0: .4byte sEwramPointer
lbl_08070eb4: .4byte 0x00007002
lbl_08070eb8: .4byte 0x00000fff
lbl_08070ebc: .4byte 0x0600c002

    thumb_func_start sub_08070ec0
sub_08070ec0: @ 0x08070ec0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    cmp r4, #0
    beq lbl_08070eda
    cmp r4, #0
    blt lbl_08070ef8
    cmp r4, #3
    bgt lbl_08070ef8
    cmp r4, #2
    blt lbl_08070ef8
lbl_08070eda:
    ldr r2, lbl_08070ef4 @ =0x0840de91
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    subs r0, #1
    adds r2, #2
    adds r1, r1, r2
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r5, r0, r1
    b lbl_08070efa
    .align 2, 0
lbl_08070ef4: .4byte 0x0840de91
lbl_08070ef8:
    movs r5, #0
lbl_08070efa:
    cmp r5, #0
    beq lbl_08070f46
    ldr r3, lbl_08070f4c @ =0x0840de50
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r1, r3
    ldrb r2, [r0]
    adds r2, r2, r6
    lsls r2, r2, #5
    adds r0, r3, #2
    adds r0, r1, r0
    ldrb r4, [r0]
    adds r2, r2, r4
    adds r3, #3
    adds r1, r1, r3
    ldrb r0, [r1]
    subs r1, r0, r4
    lsls r0, r2, #1
    ldr r2, lbl_08070f50 @ =0x0600c002
    adds r3, r0, r2
    adds r5, #1
    cmp r1, #1
    ble lbl_08070f46
    ldr r6, lbl_08070f54 @ =sEwramPointer
    movs r4, #0xe0
    lsls r4, r4, #7
    subs r2, r1, #1
lbl_08070f30:
    ldr r0, [r6]
    lsls r1, r5, #1
    adds r0, r0, r4
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r3]
    subs r2, #1
    adds r3, #2
    adds r5, #1
    cmp r2, #0
    bne lbl_08070f30
lbl_08070f46:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070f4c: .4byte 0x0840de50
lbl_08070f50: .4byte 0x0600c002
lbl_08070f54: .4byte sEwramPointer

    thumb_func_start check_select_pressed_on_status_screen
check_select_pressed_on_status_screen: @ 0x08070f58
    ldr r1, lbl_08070f68 @ =gChangedInput
    ldrh r1, [r1]
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    bx lr
    .align 2, 0
lbl_08070f68: .4byte gChangedInput

    thumb_func_start sub_08070f6c
sub_08070f6c: @ 0x08070f6c
    push {r4, lr}
    ldr r4, lbl_08070fac @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08070fa6
    bl sub_08071a3c
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08070f9a
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
lbl_08070f9a:
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
lbl_08070fa6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070fac: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08070fb0
sub_08070fb0: @ 0x08070fb0
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_08070fdc @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #8]
    adds r4, r0, #0
    cmp r1, #5
    bls lbl_08070fca
    ldr r0, lbl_08070fe0 @ =gUnk_3005804
    ldrh r1, [r0]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r5, r0, #0x1f
lbl_08070fca:
    cmp r5, #0
    beq lbl_08070fd0
    b lbl_080711c8
lbl_08070fd0:
    ldrb r0, [r2, #0xc]
    cmp r0, #0
    beq lbl_08070fe4
    bl sub_08068ec0
    b lbl_080711c8
    .align 2, 0
lbl_08070fdc: .4byte sNonGameplayRamPointer
lbl_08070fe0: .4byte gUnk_3005804
lbl_08070fe4:
    ldrb r0, [r2, #8]
    cmp r0, #7
    bls lbl_08070fec
    b lbl_080711c8
lbl_08070fec:
    lsls r0, r0, #2
    ldr r1, lbl_08070ff8 @ =lbl_08070ffc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08070ff8: .4byte lbl_08070ffc
lbl_08070ffc: @ jump table
    .4byte lbl_0807101c @ case 0
    .4byte lbl_08071098 @ case 1
    .4byte lbl_08071158 @ case 2
    .4byte lbl_0807117a @ case 3
    .4byte lbl_0807119a @ case 4
    .4byte lbl_080711a6 @ case 5
    .4byte lbl_080711c4 @ case 6
    .4byte lbl_080711c8 @ case 7
lbl_0807101c:
    ldr r2, [r4]
    ldrh r0, [r2, #0xa]
    cmp r0, #0x10
    bhi lbl_08071026
    b lbl_080711c8
lbl_08071026:
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071080
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #2
    bl sub_08071b2c
    cmp r0, #0
    bge lbl_08071066
    ldr r0, lbl_0807105c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071060
    ldr r1, [r4]
    movs r0, #3
    b lbl_0807106a
    .align 2, 0
lbl_0807105c: .4byte gDemoState
lbl_08071060:
    ldr r1, [r4]
    movs r0, #5
    b lbl_0807106a
lbl_08071066:
    ldr r1, [r4]
    movs r0, #1
lbl_0807106a:
    strb r0, [r1, #8]
    ldr r1, lbl_08071078 @ =gCurrentMessage
    movs r0, #0
    strb r0, [r1, #0xe]
    ldr r4, lbl_0807107c @ =sNonGameplayRamPointer
    b lbl_0807108a
    .align 2, 0
lbl_08071078: .4byte gCurrentMessage
lbl_0807107c: .4byte sNonGameplayRamPointer
lbl_08071080:
    ldr r0, lbl_08071094 @ =gCurrentMessage
    movs r1, #1
    strb r1, [r0, #0xe]
    movs r0, #7
    strb r0, [r2, #8]
lbl_0807108a:
    ldr r1, [r4]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080711c8
    .align 2, 0
lbl_08071094: .4byte gCurrentMessage
lbl_08071098:
    ldr r1, [r4]
    ldrh r0, [r1, #0xa]
    cmp r0, #8
    bhi lbl_080710a2
    b lbl_080711c8
lbl_080710a2:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    ldr r0, lbl_080710c8 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    subs r0, #3
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0x11
    bhi lbl_0807113e
    lsls r0, r0, #2
    ldr r1, lbl_080710cc @ =lbl_080710d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080710c8: .4byte gCurrentItemBeingAcquired
lbl_080710cc: .4byte lbl_080710d0
lbl_080710d0: @ jump table
    .4byte lbl_08071124 @ case 0
    .4byte lbl_0807113e @ case 1
    .4byte lbl_08071124 @ case 2
    .4byte lbl_0807113e @ case 3
    .4byte lbl_08071124 @ case 4
    .4byte lbl_0807113e @ case 5
    .4byte lbl_0807113e @ case 6
    .4byte lbl_0807113e @ case 7
    .4byte lbl_0807113e @ case 8
    .4byte lbl_08071118 @ case 9
    .4byte lbl_0807113e @ case 10
    .4byte lbl_0807113e @ case 11
    .4byte lbl_08071118 @ case 12
    .4byte lbl_0807113e @ case 13
    .4byte lbl_0807113e @ case 14
    .4byte lbl_0807113e @ case 15
    .4byte lbl_0807113e @ case 16
    .4byte lbl_08071118 @ case 17
lbl_08071118:
    ldr r0, lbl_08071120 @ =0x0000020f
    bl SoundPlay
    b lbl_08071144
    .align 2, 0
lbl_08071120: .4byte 0x0000020f
lbl_08071124:
    ldr r2, lbl_0807114c @ =0x0840dec4
    ldr r0, lbl_08071150 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
lbl_0807113e:
    ldr r0, lbl_08071154 @ =0x000001f7
    bl SoundPlay
lbl_08071144:
    ldr r0, lbl_08071150 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08071184
    .align 2, 0
lbl_0807114c: .4byte 0x0840dec4
lbl_08071150: .4byte sNonGameplayRamPointer
lbl_08071154: .4byte 0x000001f7
lbl_08071158:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    bne lbl_080711c8
    strh r0, [r1, #0xa]
    ldr r0, lbl_08071170 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071174
    movs r0, #3
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071170: .4byte gDemoState
lbl_08071174:
    movs r0, #5
    strb r0, [r1, #8]
    b lbl_080711c8
lbl_0807117a:
    ldr r0, lbl_08071190 @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_08071194
    ldr r1, [r4]
lbl_08071184:
    movs r0, #0
    strh r0, [r1, #0xa]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071190: .4byte gCurrentMessage
lbl_08071194:
    bl sub_0806f680
    b lbl_080711c8
lbl_0807119a:
    ldr r0, [r4]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x1e
    bls lbl_080711c8
    movs r5, #1
    b lbl_080711c8
lbl_080711a6:
    bl sub_0806f680
    ldr r0, lbl_080711bc @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_080711c8
    ldr r0, lbl_080711c0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #7
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_080711bc: .4byte gCurrentMessage
lbl_080711c0: .4byte sNonGameplayRamPointer
lbl_080711c4:
    bl sub_0806f680
lbl_080711c8:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_080711d0
sub_080711d0: @ 0x080711d0
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldr r3, lbl_080711e8 @ =sNonGameplayRamPointer
lbl_080711d8:
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r0, [r2]
    cmp r0, #0x11
    bls lbl_080711ec
    movs r0, #2
    b lbl_0807128a
    .align 2, 0
lbl_080711e8: .4byte sNonGameplayRamPointer
lbl_080711ec:
    ldr r1, lbl_08071208 @ =0x0840dec4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #4
    bhi lbl_08071256
    lsls r0, r0, #2
    ldr r1, lbl_0807120c @ =lbl_08071210
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071208: .4byte 0x0840dec4
lbl_0807120c: .4byte lbl_08071210
lbl_08071210: @ jump table
    .4byte lbl_08071224 @ case 0
    .4byte lbl_08071238 @ case 1
    .4byte lbl_08071242 @ case 2
    .4byte lbl_0807124c @ case 3
    .4byte lbl_0807122e @ case 4
lbl_08071224:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc4
    movs r2, #8
    b lbl_0807125a
lbl_0807122e:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd3
    movs r2, #0xff
    b lbl_0807125a
lbl_08071238:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd1
    movs r2, #0xff
    b lbl_0807125a
lbl_08071242:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc9
    movs r2, #0x20
    b lbl_0807125a
lbl_0807124c:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xcb
    movs r2, #4
    b lbl_0807125a
lbl_08071256:
    movs r0, #0
    b lbl_0807128a
lbl_0807125a:
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #1]
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807127e
    cmp r5, #0
    bne lbl_0807127a
    cmp r0, r2
    beq lbl_0807127e
lbl_08071276:
    movs r0, #1
    b lbl_0807128a
lbl_0807127a:
    cmp r0, r2
    beq lbl_08071276
lbl_0807127e:
    ldr r1, [r3]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080711d8
lbl_0807128a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08071290
sub_08071290: @ 0x08071290
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    movs r6, #0
    ldr r5, lbl_080712b8 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    ldrh r0, [r1, #0x20]
    adds r3, r0, #1
    movs r7, #0
    strh r3, [r1, #0x20]
    cmp r2, #1
    beq lbl_080712d8
    cmp r2, #1
    bgt lbl_080712bc
    cmp r2, #0
    beq lbl_080712c8
    b lbl_08071414
    .align 2, 0
lbl_080712b8: .4byte sNonGameplayRamPointer
lbl_080712bc:
    cmp r4, #2
    beq lbl_08071368
    cmp r4, #3
    bne lbl_080712c6
    b lbl_080713c8
lbl_080712c6:
    b lbl_08071414
lbl_080712c8:
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    strb r7, [r0]
    ldr r0, [r5]
    adds r0, #0x23
    strb r7, [r0]
    b lbl_08071414
lbl_080712d8:
    movs r2, #0
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_0807131c
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_08071314
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x22
    strb r7, [r0]
lbl_08071314:
    ldr r1, lbl_08071318 @ =0x0840df64
    b lbl_0807134c
    .align 2, 0
lbl_08071318: .4byte 0x0840df64
lbl_0807131c:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #2
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #5
    bls lbl_0807134a
    movs r0, #5
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x23
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r6, #1
lbl_0807134a:
    ldr r1, lbl_08071364 @ =0x0840df6c
lbl_0807134c:
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r2, r0, #4
lbl_0807135c:
    cmp r2, #0
    beq lbl_08071414
    lsls r1, r2, #1
    b lbl_0807139e
    .align 2, 0
lbl_08071364: .4byte 0x0840df6c
lbl_08071368:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0807138c
    strb r7, [r1]
    movs r6, #1
lbl_0807138c:
    ldr r1, lbl_080713bc @ =0x0840df6c
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
lbl_0807139e:
    ldr r0, lbl_080713c0 @ =0x0840dd10
    adds r1, r1, r0
    ldr r0, lbl_080713c4 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_08071414
    .align 2, 0
lbl_080713bc: .4byte 0x0840df6c
lbl_080713c0: .4byte 0x0840dd10
lbl_080713c4: .4byte 0x08754bbc
lbl_080713c8:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #3
    bls lbl_080713e8
    strb r7, [r1]
lbl_080713e8:
    ldr r1, lbl_08071420 @ =0x0840df72
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
    ldr r0, lbl_08071424 @ =0x0840ddd0
    adds r1, r1, r0
    ldr r0, lbl_08071428 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_08071414:
    adds r0, r6, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071420: .4byte 0x0840df72
lbl_08071424: .4byte 0x0840ddd0
lbl_08071428: .4byte 0x08754bbc

    thumb_func_start sub_0807142c
sub_0807142c: @ 0x0807142c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_08071448 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrb r1, [r2, #0xc]
    adds r7, r0, #0
    cmp r1, #0
    beq lbl_0807144c
    bl sub_08068ec0
    b lbl_080717f0
    .align 2, 0
lbl_08071448: .4byte sNonGameplayRamPointer
lbl_0807144c:
    ldrb r0, [r2, #8]
    cmp r0, #0xb
    bls lbl_08071454
    b lbl_080717ec
lbl_08071454:
    lsls r0, r0, #2
    ldr r1, lbl_08071460 @ =lbl_08071464
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071460: .4byte lbl_08071464
lbl_08071464: @ jump table
    .4byte lbl_08071494 @ case 0
    .4byte lbl_080714ac @ case 1
    .4byte lbl_080714d2 @ case 2
    .4byte lbl_0807150c @ case 3
    .4byte lbl_0807159c @ case 4
    .4byte lbl_080715e4 @ case 5
    .4byte lbl_08071680 @ case 6
    .4byte lbl_08071724 @ case 7
    .4byte lbl_08071684 @ case 8
    .4byte lbl_08071744 @ case 9
    .4byte lbl_080717a6 @ case 10
    .4byte lbl_080717ec @ case 11
lbl_08071494:
    ldr r0, [r7]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x32
    bhi lbl_0807149e
    b lbl_080717f0
lbl_0807149e:
    movs r0, #2
    bl sub_08068dbc
    ldr r1, [r7]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080714ca
lbl_080714ac:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #0x1e
    bhi lbl_080714b6
    b lbl_080717f0
lbl_080714b6:
    adds r0, r1, #0
    adds r0, #0xc1
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xea
    strb r1, [r0]
    ldr r1, [r7]
    strh r2, [r1, #0xa]
lbl_080714ca:
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080717f0
lbl_080714d2:
    movs r0, #0
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_080714fa
    ldr r2, lbl_08071504 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xc1
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080714fa
    ldr r0, lbl_08071508 @ =0x00000215
    movs r1, #0xf
    bl SoundFade
lbl_080714fa:
    ldr r3, lbl_08071504 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, r0, r5
    b lbl_08071736
    .align 2, 0
lbl_08071504: .4byte sNonGameplayRamPointer
lbl_08071508: .4byte 0x00000215
lbl_0807150c:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #6
    bhi lbl_08071516
    b lbl_080717f0
lbl_08071516:
    ldr r2, lbl_08071558 @ =0x0840dec4
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
    ldr r0, [r7]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0xd
    bl UpdateMenuOamDataID
    ldr r0, [r7]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r1, [r2]
    cmp r1, #7
    bls lbl_0807155c
    adds r0, #0xc3
    b lbl_0807155e
    .align 2, 0
lbl_08071558: .4byte 0x0840dec4
lbl_0807155c:
    adds r0, #0xc2
lbl_0807155e:
    strb r1, [r0]
    ldr r4, lbl_08071594 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807157a
    ldr r0, lbl_08071598 @ =0x00000215
    bl SoundPlay
    ldr r0, [r4]
    adds r0, #0xea
    movs r1, #0
    strb r1, [r0]
lbl_0807157a:
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071594: .4byte sNonGameplayRamPointer
lbl_08071598: .4byte 0x00000215
lbl_0807159c:
    movs r0, #1
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080715cc
    ldr r2, lbl_080715c4 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r0, lbl_080715c8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    b lbl_080715d2
    .align 2, 0
lbl_080715c4: .4byte 0x06007800
lbl_080715c8: .4byte sNonGameplayRamPointer
lbl_080715cc:
    ldr r0, lbl_080715e0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xa
lbl_080715d2:
    strb r0, [r1, #8]
    ldr r0, lbl_080715e0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_080715e0: .4byte sNonGameplayRamPointer
lbl_080715e4:
    ldr r0, lbl_08071678 @ =0x0840dec4
    ldr r1, [r7]
    adds r1, #0xc1
    ldrb r1, [r1]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    movs r5, #0x2f
    cmp r0, #0
    beq lbl_08071600
    movs r5, #0x31
    cmp r0, #2
    bne lbl_08071600
    movs r5, #0x33
lbl_08071600:
    ldr r0, [r7]
    movs r4, #0xd4
    lsls r4, r4, #1
    adds r0, r0, r4
    adds r1, r5, #0
    bl UpdateMenuOamDataID
    ldr r5, [r7]
    ldr r3, lbl_0807167c @ =0x0840de50
    ldr r6, lbl_08071678 @ =0x0840dec4
    movs r2, #0xc1
    adds r2, r2, r5
    mov ip, r2
    ldrb r1, [r2]
    lsls r1, r1, #2
    adds r1, r1, r6
    ldrb r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r2
    adds r0, r0, r3
    ldrb r0, [r0]
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r4, r5, r4
    movs r1, #0
    mov r8, r1
    strh r0, [r4]
    mov r2, ip
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r3, #2
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #5
    movs r2, #0xd5
    lsls r2, r2, #1
    adds r1, r5, r2
    strh r0, [r1]
    movs r0, #0
    bl sub_08071290
    movs r0, #0x85
    lsls r0, r0, #2
    bl SoundPlay
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r7]
    mov r1, r8
    strh r1, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071678: .4byte 0x0840dec4
lbl_0807167c: .4byte 0x0840de50
lbl_08071680:
    movs r0, #1
    b lbl_08071726
lbl_08071684:
    ldr r2, lbl_080716c8 @ =0x0840dec4
    ldr r4, lbl_080716cc @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    bl sub_08070ec0
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, lbl_080716d0 @ =0x000001f7
    bl SoundPlay
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    cmp r1, #7
    bls lbl_080716d4
    adds r0, #0xc3
    b lbl_080716d6
    .align 2, 0
lbl_080716c8: .4byte 0x0840dec4
lbl_080716cc: .4byte sNonGameplayRamPointer
lbl_080716d0: .4byte 0x000001f7
lbl_080716d4:
    adds r0, #0xc2
lbl_080716d6:
    strb r1, [r0]
    ldr r3, lbl_08071718 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    movs r2, #0xd9
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, lbl_0807171c @ =0x0840dec4
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_080717f0
    ldr r0, lbl_08071720 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0, #0xf]
    movs r0, #2
    bl sub_08068dbc
    b lbl_080717f0
    .align 2, 0
lbl_08071718: .4byte sNonGameplayRamPointer
lbl_0807171c: .4byte 0x0840dec4
lbl_08071720: .4byte gEquipment
lbl_08071724:
    movs r0, #2
lbl_08071726:
    bl sub_08071290
    cmp r0, #0
    beq lbl_080717f0
    ldr r3, lbl_08071740 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
lbl_08071736:
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071740: .4byte sNonGameplayRamPointer
lbl_08071744:
    movs r0, #3
    bl sub_08071290
    ldr r3, lbl_08071794 @ =gCurrentMessage
    ldrb r0, [r3, #0xe]
    cmp r0, #0
    beq lbl_080717a0
    ldr r0, lbl_08071798 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080717f0
    ldr r4, lbl_0807179c @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    strb r2, [r3, #0xe]
    ldr r0, [r4]
    movs r1, #0xd4
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    movs r0, #4
    strb r0, [r1, #8]
    b lbl_080717f0
    .align 2, 0
lbl_08071794: .4byte gCurrentMessage
lbl_08071798: .4byte gChangedInput
lbl_0807179c: .4byte sNonGameplayRamPointer
lbl_080717a0:
    bl sub_0806f680
    b lbl_080717f0
lbl_080717a6:
    ldr r0, lbl_080717c0 @ =gEquipment
    ldrb r1, [r0, #0xc]
    strb r1, [r0, #0xd]
    ldrb r1, [r0, #0xe]
    strb r1, [r0, #0xf]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xc3
    ldrb r2, [r0]
    cmp r2, #0
    beq lbl_080717c4
    subs r0, #2
    b lbl_080717da
    .align 2, 0
lbl_080717c0: .4byte gEquipment
lbl_080717c4:
    adds r0, r1, #0
    adds r0, #0xc2
    ldrb r3, [r0]
    adds r2, r3, #0
    cmp r2, #0
    beq lbl_080717d6
    subs r0, #1
    strb r3, [r0]
    b lbl_080717dc
lbl_080717d6:
    adds r0, r1, #0
    adds r0, #0xc1
lbl_080717da:
    strb r2, [r0]
lbl_080717dc:
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r7]
    strh r2, [r0, #0xa]
    b lbl_080717f0
lbl_080717ec:
    movs r0, #1
    b lbl_080717f2
lbl_080717f0:
    movs r0, #0
lbl_080717f2:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08071800
sub_08071800: @ 0x08071800
    push {r4, lr}
    ldr r0, lbl_0807182c @ =gChangedInput
    ldrh r1, [r0]
    ldr r0, lbl_08071830 @ =0x00000302
    ands r0, r1
    ldr r4, lbl_08071834 @ =sNonGameplayRamPointer
    cmp r0, #0
    beq lbl_08071838
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne lbl_08071838
    ldrb r2, [r1, #0xc]
    cmp r2, #0
    bne lbl_08071840
    movs r0, #0xc
    strb r0, [r1, #4]
    ldr r0, [r4]
    movs r1, #0
    strh r2, [r0, #0xa]
    strb r1, [r0, #8]
    b lbl_0807188e
    .align 2, 0
lbl_0807182c: .4byte gChangedInput
lbl_08071830: .4byte 0x00000302
lbl_08071834: .4byte sNonGameplayRamPointer
lbl_08071838:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    beq lbl_08071846
lbl_08071840:
    bl sub_08068ec0
    b lbl_0807188a
lbl_08071846:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807188a
    movs r0, #4
    bl check_select_pressed_on_status_screen
    cmp r0, #0
    beq lbl_08071886
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    cmp r0, #1
    bne lbl_08071878
    ldr r0, lbl_08071874 @ =0x000001f7
    bl SoundPlay
    b lbl_0807188a
    .align 2, 0
lbl_08071874: .4byte 0x000001f7
lbl_08071878:
    cmp r0, #0
    bne lbl_0807188a
    movs r0, #0xfc
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0807188a
lbl_08071886:
    bl sub_08071dc0
lbl_0807188a:
    bl sub_0806f680
lbl_0807188e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start get_current_equipment_selected
get_current_equipment_selected: @ 0x08071894
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    movs r3, #0x80
    lsrs r2, r0, #0x18
    movs r1, #0xff
    lsls r1, r1, #0x18
    adds r0, r0, r1
    lsrs r0, r0, #0x18
    cmp r0, #0x10
    bls lbl_080718ac
    movs r0, #0x80
    b lbl_08071a34
lbl_080718ac:
    ldr r0, lbl_080718d4 @ =gEquipment
    ldrb r1, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, #2
    bne lbl_080718b8
    b lbl_08071a30
lbl_080718b8:
    ldr r0, lbl_080718d8 @ =0x0840dec4
    lsls r2, r2, #2
    adds r1, r2, r0
    ldrb r1, [r1]
    adds r4, r0, #0
    cmp r1, #4
    bls lbl_080718c8
    b lbl_08071a32
lbl_080718c8:
    lsls r0, r1, #2
    ldr r1, lbl_080718dc @ =lbl_080718e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080718d4: .4byte gEquipment
lbl_080718d8: .4byte 0x0840dec4
lbl_080718dc: .4byte lbl_080718e0
lbl_080718e0: @ jump table
    .4byte lbl_080718f4 @ case 0
    .4byte lbl_08071970 @ case 1
    .4byte lbl_08071990 @ case 2
    .4byte lbl_080719c8 @ case 3
    .4byte lbl_08071950 @ case 4
lbl_080718f4:
    ldr r0, lbl_08071914 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc4
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_08071908
    b lbl_08071a32
lbl_08071908:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071918
    movs r3, #0
    b lbl_08071a32
    .align 2, 0
lbl_08071914: .4byte sNonGameplayRamPointer
lbl_08071918:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071924
    movs r3, #1
    b lbl_08071a32
lbl_08071924:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071930
    movs r3, #2
    b lbl_08071a32
lbl_08071930:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0807193c
    movs r3, #3
    b lbl_08071a32
lbl_0807193c:
    movs r0, #8
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #4
    b lbl_08071a32
lbl_08071950:
    ldr r0, lbl_0807196c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd3
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #6
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #5
    b lbl_08071a32
    .align 2, 0
lbl_0807196c: .4byte sNonGameplayRamPointer
lbl_08071970:
    ldr r0, lbl_0807198c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd1
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #8
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #7
    b lbl_08071a32
    .align 2, 0
lbl_0807198c: .4byte sNonGameplayRamPointer
lbl_08071990:
    ldr r0, lbl_080719b0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc9
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080719b4
    movs r3, #9
    b lbl_08071a32
    .align 2, 0
lbl_080719b0: .4byte sNonGameplayRamPointer
lbl_080719b4:
    movs r0, #0x20
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0xa
    b lbl_08071a32
lbl_080719c8:
    ldr r0, lbl_080719e8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xcb
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080719ec
    movs r3, #0xb
    b lbl_08071a32
    .align 2, 0
lbl_080719e8: .4byte sNonGameplayRamPointer
lbl_080719ec:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080719f8
    movs r3, #0xc
    b lbl_08071a32
lbl_080719f8:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a04
    movs r3, #0xd
    b lbl_08071a32
lbl_08071a04:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a10
    movs r3, #0xe
    b lbl_08071a32
lbl_08071a10:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a1c
    movs r3, #0xf
    b lbl_08071a32
lbl_08071a1c:
    movs r0, #4
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0x10
    b lbl_08071a32
lbl_08071a30:
    movs r3, #0x12
lbl_08071a32:
    adds r0, r3, #0
lbl_08071a34:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08071a3c
sub_08071a3c: @ 0x08071a3c
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    ldr r3, lbl_08071a80 @ =0x0840de50
    ldr r1, lbl_08071a84 @ =0x0840dec4
    lsrs r0, r0, #0x16
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r2, r1, #2
    adds r2, r2, r1
    adds r1, r2, r3
    ldrb r4, [r1]
    ldrb r0, [r0, #2]
    adds r4, r4, r0
    adds r3, #2
    adds r2, r2, r3
    ldrb r0, [r2]
    adds r0, #1
    ldr r1, lbl_08071a88 @ =sNonGameplayRamPointer
    ldr r3, [r1]
    lsls r2, r4, #5
    movs r5, #0x84
    lsls r5, r5, #1
    adds r1, r3, r5
    strh r2, [r1]
    lsls r1, r0, #5
    adds r5, #2
    adds r2, r3, r5
    strh r1, [r2]
    lsls r0, r0, #0x10
    orrs r0, r4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071a80: .4byte 0x0840de50
lbl_08071a84: .4byte 0x0840dec4
lbl_08071a88: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071a8c
sub_08071a8c: @ 0x08071a8c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r4, #0
    ldr r1, lbl_08071aac @ =0x0840dec4
    lsls r0, r2, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r3, r1, #0
    cmp r0, #4
    bhi lbl_08071b1e
    lsls r0, r0, #2
    ldr r1, lbl_08071ab0 @ =lbl_08071ab4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071aac: .4byte 0x0840dec4
lbl_08071ab0: .4byte lbl_08071ab4
lbl_08071ab4: @ jump table
    .4byte lbl_08071ac8 @ case 0
    .4byte lbl_08071ae8 @ case 1
    .4byte lbl_08071af8 @ case 2
    .4byte lbl_08071b08 @ case 3
    .4byte lbl_08071ad8 @ case 4
lbl_08071ac8:
    ldr r0, lbl_08071ad4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc4
    b lbl_08071b12
    .align 2, 0
lbl_08071ad4: .4byte sNonGameplayRamPointer
lbl_08071ad8:
    ldr r0, lbl_08071ae4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd3
    b lbl_08071b12
    .align 2, 0
lbl_08071ae4: .4byte sNonGameplayRamPointer
lbl_08071ae8:
    ldr r0, lbl_08071af4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd1
    b lbl_08071b12
    .align 2, 0
lbl_08071af4: .4byte sNonGameplayRamPointer
lbl_08071af8:
    ldr r0, lbl_08071b04 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc9
    b lbl_08071b12
    .align 2, 0
lbl_08071b04: .4byte sNonGameplayRamPointer
lbl_08071b08:
    ldr r0, lbl_08071b28 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xcb
lbl_08071b12:
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08071b1e
    movs r4, #1
lbl_08071b1e:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071b28: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071b2c
sub_08071b2c: @ 0x08071b2c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    movs r6, #0
    ldr r1, lbl_08071b58 @ =0x0840dec4
    lsls r0, r4, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    mov ip, r1
    ldr r2, lbl_08071b5c @ =sNonGameplayRamPointer
    cmp r0, #4
    bhi lbl_08071c1a
    lsls r0, r0, #2
    ldr r1, lbl_08071b60 @ =lbl_08071b64
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071b58: .4byte 0x0840dec4
lbl_08071b5c: .4byte sNonGameplayRamPointer
lbl_08071b60: .4byte lbl_08071b64
lbl_08071b64: @ jump table
    .4byte lbl_08071b78 @ case 0
    .4byte lbl_08071b9c @ case 1
    .4byte lbl_08071bc8 @ case 2
    .4byte lbl_08071bfc @ case 3
    .4byte lbl_08071c1a @ case 4
lbl_08071b78:
    ldr r2, lbl_08071b94 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc4
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071b98 @ =gEquipment+0xD
    cmp r6, #8
    bne lbl_08071c1a
    ldrb r0, [r5, #5]
    b lbl_08071c14
    .align 2, 0
lbl_08071b94: .4byte sNonGameplayRamPointer
lbl_08071b98: .4byte gEquipment+0xD
lbl_08071b9c:
    ldr r2, lbl_08071bc0 @ =sNonGameplayRamPointer
    cmp r4, #8
    bne lbl_08071c1a
    ldr r3, lbl_08071bc4 @ =gEquipment
    ldrb r1, [r3, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071c1a
    ldrb r1, [r3, #0xd]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c1a
    movs r6, #0x80
    adds r5, r3, #0
    adds r5, #0xd
    b lbl_08071c1a
    .align 2, 0
lbl_08071bc0: .4byte sNonGameplayRamPointer
lbl_08071bc4: .4byte gEquipment
lbl_08071bc8:
    ldr r2, lbl_08071bf4 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc9
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071bf8 @ =gEquipment+0xF
    cmp r6, #0x20
    bne lbl_08071be6
    ldrb r0, [r5, #3]
    cmp r0, #1
    beq lbl_08071be6
    movs r6, #0
lbl_08071be6:
    cmp r6, #0
    beq lbl_08071c1a
    ldrb r0, [r5]
    ands r0, r6
    cmp r0, #0
    beq lbl_08071c1a
    b lbl_08071c18
    .align 2, 0
lbl_08071bf4: .4byte sNonGameplayRamPointer
lbl_08071bf8: .4byte gEquipment+0xF
lbl_08071bfc:
    ldr r2, lbl_08071c40 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xcb
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071c44 @ =gEquipment+0xF
    cmp r6, #4
    bne lbl_08071c1a
    ldrb r0, [r5, #3]
lbl_08071c14:
    cmp r0, #1
    beq lbl_08071c1a
lbl_08071c18:
    movs r6, #0
lbl_08071c1a:
    ldr r0, [r2]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c36
    ldr r0, lbl_08071c48 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    beq lbl_08071c36
    movs r6, #0
lbl_08071c36:
    cmp r6, #0
    bne lbl_08071c4c
    movs r3, #0
    movs r7, #0xff
    b lbl_08071d8a
    .align 2, 0
lbl_08071c40: .4byte sNonGameplayRamPointer
lbl_08071c44: .4byte gEquipment+0xF
lbl_08071c48: .4byte gPauseScreenFlag
lbl_08071c4c:
    cmp r7, #0
    beq lbl_08071c54
    cmp r7, #2
    bne lbl_08071c64
lbl_08071c54:
    ldrb r1, [r5]
    ands r1, r6
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r8, r4
    b lbl_08071d5a
lbl_08071c64:
    ldrb r1, [r5]
    adds r0, r6, #0
    eors r0, r1
    strb r0, [r5]
    adds r1, r6, #0
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r1, ip
    adds r0, r4, r1
    ldrb r5, [r0]
    ldrb r1, [r0, #2]
    adds r0, r5, #0
    adds r2, r7, #0
    movs r3, #1
    bl sub_08070e1c
    mov r8, r4
    cmp r5, #2
    beq lbl_08071cfc
    cmp r5, #2
    bgt lbl_08071c9a
    cmp r5, #1
    beq lbl_08071d04
    b lbl_08071d5a
lbl_08071c9a:
    cmp r5, #3
    bne lbl_08071d5a
    movs r0, #0x40
    ands r0, r6
    cmp r0, #0
    beq lbl_08071d5a
    movs r3, #0
    ldr r4, lbl_08071cf8 @ =sNonGameplayRamPointer
lbl_08071caa:
    ldr r0, [r4]
    adds r0, #0xd1
    adds r2, r0, r3
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    adds r5, r3, #1
    cmp r0, #0
    beq lbl_08071cec
    movs r0, #7
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r4]
    adds r2, #0xd1
    adds r2, r2, r3
    lsls r0, r7, #3
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
    movs r2, #0
    ldr r0, [r4]
    adds r0, #0xd1
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071ce0
    movs r2, #1
lbl_08071ce0:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #1
    movs r3, #1
    bl sub_08070e1c
lbl_08071cec:
    lsls r0, r5, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_08071caa
    b lbl_08071d5a
    .align 2, 0
lbl_08071cf8: .4byte sNonGameplayRamPointer
lbl_08071cfc:
    movs r0, #2
    bl sub_08068dbc
    b lbl_08071d5a
lbl_08071d04:
    ldr r3, lbl_08071db4 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #0xd
    mov ip, r0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xd1
    lsls r4, r7, #1
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xd2
    ldrb r1, [r2]
    ands r5, r1
    cmp r5, #0
    beq lbl_08071d5a
    mov r0, ip
    ands r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r1, #0xd2
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    movs r2, #0
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071d50
    movs r2, #1
lbl_08071d50:
    movs r0, #1
    movs r1, #2
    movs r3, #1
    bl sub_08070e1c
lbl_08071d5a:
    ldr r0, lbl_08071db8 @ =0x0840dec4
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #1
    blt lbl_08071d7a
    cmp r0, #2
    ble lbl_08071d78
    cmp r0, #3
    bne lbl_08071d7a
    cmp r6, #4
    bne lbl_08071d7a
    ldr r0, lbl_08071dbc @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #1
    beq lbl_08071d7a
lbl_08071d78:
    movs r7, #0xff
lbl_08071d7a:
    movs r3, #0x11
    ldr r2, lbl_08071db4 @ =sNonGameplayRamPointer
    cmp r7, #1
    beq lbl_08071d8a
    movs r3, #0
    cmp r7, #0
    bne lbl_08071d8a
    movs r3, #0x12
lbl_08071d8a:
    ldr r2, [r2]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071d9a
    movs r3, #0
lbl_08071d9a:
    movs r1, #0x8b
    lsls r1, r1, #3
    adds r0, r2, r1
    adds r1, r3, #0
    bl UpdateMenuOamDataID
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071db4: .4byte sNonGameplayRamPointer
lbl_08071db8: .4byte 0x0840dec4
lbl_08071dbc: .4byte gEquipment

    thumb_func_start sub_08071dc0
sub_08071dc0: @ 0x08071dc0
    push {r4, lr}
    ldr r0, lbl_08071dec @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #6
    beq lbl_08071e70
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r2, [r0]
    ldr r0, lbl_08071df0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071df4
    movs r3, #1
    rsbs r3, r3, #0
    b lbl_08071e26
    .align 2, 0
lbl_08071dec: .4byte sNonGameplayRamPointer
lbl_08071df0: .4byte gChangedInput
lbl_08071df4:
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    rsbs r0, r0, #0
    lsrs r3, r0, #0x1f
    cmp r3, #0
    bne lbl_08071e26
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_08071e18
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
    b lbl_08071e26
lbl_08071e18:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
lbl_08071e22:
    cmp r3, #0
    beq lbl_08071e36
lbl_08071e26:
    ldr r0, lbl_08071e78 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    adds r0, r3, #0
    bl sub_08071e7c
    adds r2, r0, #0
lbl_08071e36:
    ldr r4, lbl_08071e78 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, r2
    beq lbl_08071e70
    strb r2, [r1]
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    bl sub_08071a3c
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
    ldr r0, [r4]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    movs r0, #0xfb
    lsls r0, r0, #1
    bl SoundPlay
lbl_08071e70:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08071e78: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08071e7c
sub_08071e7c: @ 0x08071e7c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x18
    asrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    mov r8, r4
    cmp r5, #0
    beq lbl_08071f62
    cmp r5, #1
    ble lbl_08071f26
    cmp r4, #7
    bls lbl_08071ea8
    ldr r1, lbl_08071ea4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xc3
    b lbl_08071eae
    .align 2, 0
lbl_08071ea4: .4byte sNonGameplayRamPointer
lbl_08071ea8:
    ldr r1, lbl_08071ed4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xc2
lbl_08071eae:
    strb r4, [r0]
    mov r0, r8
    cmp r0, #7
    bls lbl_08071edc
    ldr r0, [r1]
    adds r0, #0xc2
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #7
    movs r7, #1
    mov r0, r8
    cmp r0, #0xb
    bls lbl_08071ed8
    movs r4, #6
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
    .align 2, 0
lbl_08071ed4: .4byte sNonGameplayRamPointer
lbl_08071ed8:
    movs r4, #1
    b lbl_08071efa
lbl_08071edc:
    ldr r0, [r1]
    adds r0, #0xc3
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #0x11
    movs r7, #8
    mov r0, r8
    cmp r0, #5
    bls lbl_08071ef8
    movs r4, #0xc
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
lbl_08071ef8:
    movs r4, #8
lbl_08071efa:
    movs r5, #1
lbl_08071efc:
    adds r6, r4, #0
lbl_08071efe:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    bne lbl_08071f62
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f18
    adds r4, r1, #0
    b lbl_08071f1e
lbl_08071f18:
    cmp r4, r1
    ble lbl_08071f1e
    adds r4, r7, #0
lbl_08071f1e:
    cmp r4, r6
    bne lbl_08071efe
lbl_08071f22:
    mov r4, r8
    b lbl_08071f62
lbl_08071f26:
    cmp r4, #7
    bls lbl_08071f30
    movs r1, #0x11
    movs r7, #8
    b lbl_08071f34
lbl_08071f30:
    movs r1, #7
    movs r7, #1
lbl_08071f34:
    cmp r5, #1
    beq lbl_08071f3c
    movs r0, #1
    rsbs r0, r0, #0
lbl_08071f3c:
    adds r6, r4, #0
lbl_08071f3e:
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f48
    adds r4, r1, #0
    b lbl_08071f4e
lbl_08071f48:
    cmp r4, r1
    ble lbl_08071f4e
    adds r4, r7, #0
lbl_08071f4e:
    cmp r4, r6
    beq lbl_08071f22
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    beq lbl_08071f3e
lbl_08071f62:
    adds r0, r4, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start easy_sleep_menu_subroutine
easy_sleep_menu_subroutine: @ 0x08071f70
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    ldr r1, lbl_08071f94 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #5
    bls lbl_08071f88
    b lbl_08072110
lbl_08071f88:
    lsls r0, r0, #2
    ldr r1, lbl_08071f98 @ =lbl_08071f9c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071f94: .4byte sNonGameplayRamPointer
lbl_08071f98: .4byte lbl_08071f9c
lbl_08071f9c: @ jump table
    .4byte lbl_08071fb4 @ case 0
    .4byte lbl_08072000 @ case 1
    .4byte lbl_08072068 @ case 2
    .4byte lbl_0807207e @ case 3
    .4byte lbl_08072094 @ case 4
    .4byte lbl_08072104 @ case 5
lbl_08071fb4:
    ldr r0, lbl_08071fcc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071fd4
    ldr r0, lbl_08071fd0 @ =0x00000209
    bl SoundPlay
    movs r7, #2
    b lbl_08072114
    .align 2, 0
lbl_08071fcc: .4byte gChangedInput
lbl_08071fd0: .4byte 0x00000209
lbl_08071fd4:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08072058
    ldr r0, lbl_08071ff8 @ =0x00000207
    bl SoundPlay
    ldr r2, lbl_08071ffc @ =sNonGameplayRamPointer
    ldr r1, [r2]
    movs r0, #1
    strb r0, [r1, #8]
    ldr r0, [r2]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0xd0
    strh r0, [r1]
    b lbl_08072110
    .align 2, 0
lbl_08071ff8: .4byte 0x00000207
lbl_08071ffc: .4byte sNonGameplayRamPointer
lbl_08072000:
    ldr r0, lbl_08072024 @ =gChangedInput
    ldrh r1, [r0]
    movs r4, #1
    ands r4, r1
    cmp r4, #0
    beq lbl_0807202c
    movs r0, #0x82
    lsls r0, r0, #2
    bl SoundPlay
    ldr r2, lbl_08072028 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    movs r3, #0
    movs r0, #2
    strb r0, [r1, #8]
    ldr r0, [r2]
    strh r3, [r0, #0xa]
    b lbl_08072110
    .align 2, 0
lbl_08072024: .4byte gChangedInput
lbl_08072028: .4byte sNonGameplayRamPointer
lbl_0807202c:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08072058
    ldr r0, lbl_08072050 @ =0x00000207
    bl SoundPlay
    ldr r1, lbl_08072054 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    strb r4, [r0, #8]
    ldr r0, [r1]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0x84
    lsls r0, r0, #2
    strh r0, [r1]
    b lbl_08072110
    .align 2, 0
lbl_08072050: .4byte 0x00000207
lbl_08072054: .4byte sNonGameplayRamPointer
lbl_08072058:
    ldr r0, lbl_08072064 @ =0x00000302
    ands r0, r1
    cmp r0, #0
    beq lbl_08072110
    movs r7, #1
    b lbl_08072114
    .align 2, 0
lbl_08072064: .4byte 0x00000302
lbl_08072068:
    ldr r3, [r2]
    ldrh r0, [r3, #0xa]
    cmp r0, #0x1e
    bls lbl_08072110
    ldrb r0, [r3, #8]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    b lbl_08072110
lbl_0807207e:
    ldr r2, [r2]
    adds r3, r2, #0
    adds r3, #0x5c
    ldrh r0, [r3]
    movs r1, #0x80
    eors r0, r1
    strh r0, [r3]
    ldrb r0, [r2, #8]
    adds r0, #1
    strb r0, [r2, #8]
    b lbl_08072110
lbl_08072094:
    ldr r1, lbl_080720f0 @ =0x04000132
    ldr r2, lbl_080720f4 @ =0x0000c304
    adds r0, r2, #0
    strh r0, [r1]
    ldr r6, lbl_080720f8 @ =0x04000208
    movs r0, #0
    mov sb, r0
    strh r0, [r6]
    ldr r5, lbl_080720fc @ =0x04000200
    ldrh r4, [r5]
    movs r1, #0xc0
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r5]
    movs r2, #1
    mov r8, r2
    strh r2, [r6]
    bl SoundBias0
    svc #3
    bl SoundBias200
    mov r0, sb
    strh r0, [r6]
    strh r4, [r5]
    mov r1, r8
    strh r1, [r6]
    ldr r0, lbl_08072100 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r0, [r2]
    movs r1, #0x80
    eors r0, r1
    strh r0, [r2]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x84
    lsls r0, r0, #2
    strh r0, [r1]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    b lbl_08072110
    .align 2, 0
lbl_080720f0: .4byte 0x04000132
lbl_080720f4: .4byte 0x0000c304
lbl_080720f8: .4byte 0x04000208
lbl_080720fc: .4byte 0x04000200
lbl_08072100: .4byte sNonGameplayRamPointer
lbl_08072104:
    ldr r0, lbl_08072138 @ =gButtonInput
    ldrh r1, [r0]
    cmp r1, #0
    bne lbl_08072110
    ldr r0, [r2]
    strb r1, [r0, #8]
lbl_08072110:
    cmp r7, #0
    beq lbl_0807212a
lbl_08072114:
    ldr r2, lbl_0807213c @ =sNonGameplayRamPointer
    ldr r0, [r2]
    movs r1, #0
    strb r1, [r0, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    cmp r7, #1
    bne lbl_0807212a
    ldr r0, lbl_08072140 @ =0x00000206
    bl SoundPlay
lbl_0807212a:
    adds r0, r7, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08072138: .4byte gButtonInput
lbl_0807213c: .4byte sNonGameplayRamPointer
lbl_08072140: .4byte 0x00000206

    thumb_func_start sub_08072144
sub_08072144: @ 0x08072144
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    movs r7, #0xd
    ldrsb r7, [r4, r7]
    cmp r7, #0
    beq lbl_08072196
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #6]
    cmp r0, r1
    beq lbl_08072192
    movs r0, #0xa
    ldrsh r1, [r4, r0]
    ldrh r0, [r4, #0x10]
    muls r1, r0, r1
    ldrh r0, [r4, #0x12]
    muls r0, r1, r0
    lsls r0, r0, #8
    ldrh r1, [r4, #0xe]
    bl __divsi3
    adds r6, r0, #0
    ldrh r2, [r4, #2]
    cmp r6, #0
    bge lbl_08072176
    adds r0, #0xff
lbl_08072176:
    asrs r0, r0, #8
    movs r1, #0xd
    ldrsb r1, [r4, r1]
    muls r0, r1, r0
    adds r6, r2, r0
    cmp r7, #0
    ble lbl_0807218c
    ldrh r0, [r4, #6]
    cmp r0, r6
    bge lbl_08072196
    b lbl_08072192
lbl_0807218c:
    ldrh r0, [r4, #6]
    cmp r0, r6
    ble lbl_08072196
lbl_08072192:
    movs r0, #0
    strb r0, [r4, #0xd]
lbl_08072196:
    movs r7, #0xc
    ldrsb r7, [r4, r7]
    cmp r7, #0
    beq lbl_080721e4
    ldrh r0, [r4]
    ldrh r1, [r4, #4]
    cmp r0, r1
    beq lbl_080721e0
    movs r0, #8
    ldrsh r1, [r4, r0]
    ldrh r0, [r4, #0x10]
    muls r1, r0, r1
    ldrh r0, [r4, #0x12]
    muls r0, r1, r0
    lsls r0, r0, #8
    ldrh r1, [r4, #0xe]
    bl __divsi3
    adds r5, r0, #0
    ldrh r2, [r4]
    cmp r5, #0
    bge lbl_080721c4
    adds r0, #0xff
lbl_080721c4:
    asrs r0, r0, #8
    movs r1, #0xc
    ldrsb r1, [r4, r1]
    muls r0, r1, r0
    adds r5, r2, r0
    cmp r7, #0
    ble lbl_080721da
    ldrh r0, [r4, #4]
    cmp r0, r5
    bge lbl_080721e4
    b lbl_080721e0
lbl_080721da:
    ldrh r0, [r4, #4]
    cmp r0, r5
    ble lbl_080721e4
lbl_080721e0:
    movs r0, #0
    strb r0, [r4, #0xc]
lbl_080721e4:
    movs r0, #0xd
    ldrsb r0, [r4, r0]
    cmp r0, #0
    bne lbl_080721ee
    ldrh r6, [r4, #6]
lbl_080721ee:
    movs r0, #0xc
    ldrsb r0, [r4, r0]
    cmp r0, #0
    bne lbl_080721f8
    ldrh r5, [r4, #4]
lbl_080721f8:
    lsls r0, r5, #0x10
    orrs r0, r6
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start chozo_statue_hint_movement
chozo_statue_hint_movement: @ 0x08072204
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_08072220 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x47
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #6
    bls lbl_08072216
    b lbl_08072664
lbl_08072216:
    lsls r0, r0, #2
    ldr r1, lbl_08072224 @ =lbl_08072228
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08072220: .4byte sNonGameplayRamPointer
lbl_08072224: .4byte lbl_08072228
lbl_08072228: @ jump table
    .4byte lbl_08072664 @ case 0
    .4byte lbl_08072244 @ case 1
    .4byte lbl_080723f4 @ case 2
    .4byte lbl_08072414 @ case 3
    .4byte lbl_080725b0 @ case 4
    .4byte lbl_08072600 @ case 5
    .4byte lbl_0807262e @ case 6
lbl_08072244:
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r2, [r1]
    movs r0, #1
    orrs r0, r2
    strb r0, [r1]
    ldr r3, [r5]
    ldrb r0, [r3, #0x13]
    lsls r0, r0, #5
    adds r4, r3, #0
    adds r4, #0x8e
    strh r0, [r4]
    ldrb r0, [r3, #0x14]
    lsls r0, r0, #5
    adds r2, r3, #0
    adds r2, #0x8c
    strh r0, [r2]
    ldrb r0, [r3, #0x15]
    lsls r0, r0, #5
    adds r1, r3, #0
    adds r1, #0x92
    strh r0, [r1]
    ldrb r0, [r3, #0x16]
    lsls r0, r0, #5
    subs r1, #2
    strh r0, [r1]
    ldrh r1, [r2]
    movs r2, #0xea
    lsls r2, r2, #2
    adds r0, r3, r2
    strh r1, [r0]
    ldrh r1, [r4]
    ldr r4, lbl_080722cc @ =0x000003aa
    adds r0, r3, r4
    strh r1, [r0]
    ldr r2, lbl_080722d0 @ =0x0840df78
    adds r0, r3, #0
    adds r0, #0x40
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r1, [r0, #5]
    ldr r7, lbl_080722d4 @ =0x000003b2
    adds r0, r3, r7
    strb r1, [r0]
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0x92
    adds r1, r3, #0
    adds r1, #0x8e
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r2, r3, #0
    adds r2, #0x96
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_080722d8
    adds r1, r3, #0
    adds r1, #0x98
    movs r0, #0
    strb r0, [r1]
    b lbl_08072300
    .align 2, 0
lbl_080722cc: .4byte 0x000003aa
lbl_080722d0: .4byte 0x0840df78
lbl_080722d4: .4byte 0x000003b2
lbl_080722d8:
    movs r2, #1
    rsbs r2, r2, #0
    adds r1, r2, #0
    cmp r0, #0
    ble lbl_080722e4
    movs r1, #1
lbl_080722e4:
    adds r0, r3, #0
    adds r0, #0x99
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0x96
    adds r0, #0x99
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_08072300:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x90
    adds r1, r2, #0
    adds r1, #0x8c
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r1, r2, #0
    adds r1, #0x94
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072326
    adds r1, #4
    movs r0, #0
    strb r0, [r1]
    b lbl_0807234e
lbl_08072326:
    movs r4, #1
    rsbs r4, r4, #0
    adds r1, r4, #0
    cmp r0, #0
    ble lbl_08072332
    movs r1, #1
lbl_08072332:
    adds r0, r2, #0
    adds r0, #0x98
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0x94
    adds r0, #0x98
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r7, r0, #0
    muls r7, r1, r7
    adds r0, r7, #0
    strh r0, [r2]
lbl_0807234e:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x96
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r0, #0
    muls r3, r0, r3
    adds r0, r3, #0
    adds r1, #0x94
    movs r4, #0
    ldrsh r1, [r1, r4]
    adds r7, r1, #0
    muls r7, r1, r7
    adds r1, r7, #0
    adds r0, r0, r1
    lsls r0, r0, #2
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x12
    cmp r4, #0
    bne lbl_08072386
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x99
    strb r4, [r1]
    adds r0, #0x98
    strb r4, [r0]
lbl_08072386:
    ldr r0, [r5]
    mov ip, r0
    adds r0, #0x9a
    movs r3, #0
    movs r2, #0
    strh r4, [r0]
    mov r1, ip
    adds r1, #0x9c
    movs r0, #1
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x9e
    strh r2, [r0]
    subs r0, #0x56
    strb r3, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bgt lbl_080723cc
    ldr r3, lbl_080723c8 @ =0x000003b3
    adds r2, r1, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    b lbl_080725ec
    .align 2, 0
lbl_080723c8: .4byte 0x000003b3
lbl_080723cc:
    adds r0, r1, #0
    adds r0, #0x41
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080723de
    adds r1, #0x47
    movs r0, #6
    strb r0, [r1]
    b lbl_08072664
lbl_080723de:
    ldr r4, lbl_080723f0 @ =0x000003b3
    adds r2, r1, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    b lbl_080725ec
    .align 2, 0
lbl_080723f0: .4byte 0x000003b3
lbl_080723f4:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x3c
    bhi lbl_0807240c
    b lbl_08072664
lbl_0807240c:
    adds r1, #0x49
    movs r0, #1
    strb r0, [r1]
    b lbl_080725e4
lbl_08072414:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x92
    ldrh r1, [r0]
    ldr r7, lbl_08072470 @ =0x000003aa
    adds r0, r2, r7
    movs r3, #0
    ldrsh r0, [r0, r3]
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x99
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r4, r1, #0
    muls r4, r0, r4
    adds r0, r2, #0
    adds r0, #0x90
    ldrh r1, [r0]
    subs r7, #2
    adds r0, r2, r7
    movs r3, #0
    ldrsh r0, [r0, r3]
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x98
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    muls r1, r0, r1
    cmp r1, r4
    bge lbl_08072460
    adds r1, r4, #0
lbl_08072460:
    asrs r4, r1, #2
    cmp r4, #0x20
    bgt lbl_08072474
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #2
    b lbl_08072498
    .align 2, 0
lbl_08072470: .4byte 0x000003aa
lbl_08072474:
    cmp r4, #0x40
    bgt lbl_08072482
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #3
    b lbl_08072498
lbl_08072482:
    cmp r4, #0x60
    bgt lbl_08072490
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #4
    b lbl_08072498
lbl_08072490:
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #5
lbl_08072498:
    strh r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x48
    ldrb r1, [r0]
    movs r6, #7
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807253a
    lsrs r4, r1, #3
    movs r0, #3
    ands r4, r0
    adds r4, #1
    lsls r3, r4, #4
    adds r1, r2, r3
    movs r0, #0xea
    lsls r0, r0, #2
    adds r1, r1, r0
    adds r0, r2, r0
    ldm r0!, {r2, r4, r7}
    stm r1!, {r2, r4, r7}
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bgt lbl_080724fc
    adds r0, r2, r3
    ldr r4, lbl_080724f4 @ =0x000003b2
    adds r0, r0, r4
    strb r6, [r0]
    ldr r2, [r5]
    adds r2, r2, r3
    ldr r7, lbl_080724f8 @ =0x000003b3
    adds r2, r2, r7
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    b lbl_08072536
    .align 2, 0
lbl_080724f4: .4byte 0x000003b2
lbl_080724f8: .4byte 0x000003b3
lbl_080724fc:
    movs r1, #0xf
    cmp r0, #8
    bne lbl_08072504
    movs r1, #0xb
lbl_08072504:
    adds r0, r2, r3
    ldr r2, lbl_0807259c @ =0x000003b2
    adds r0, r0, r2
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, r0, r3
    movs r4, #0xec
    lsls r4, r4, #2
    adds r0, r0, r4
    movs r1, #3
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, r0, r3
    ldr r7, lbl_080725a0 @ =0x000003b1
    adds r0, r0, r7
    movs r1, #5
    strb r1, [r0]
    ldr r2, [r5]
    adds r2, r2, r3
    ldr r0, lbl_080725a4 @ =0x000003b3
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
lbl_08072536:
    orrs r0, r1
    strb r0, [r2]
lbl_0807253a:
    ldr r0, [r5]
    adds r0, #0x8c
    bl sub_08072144
    adds r4, r0, #0
    asrs r1, r4, #0x10
    ldr r0, lbl_080725a8 @ =0x0000ffff
    ands r4, r0
    ldr r2, [r5]
    movs r3, #0xea
    lsls r3, r3, #2
    adds r0, r2, r3
    movs r6, #0
    strh r1, [r0]
    ldr r7, lbl_080725ac @ =0x000003aa
    adds r0, r2, r7
    strh r4, [r0]
    movs r3, #0
    adds r0, r2, #0
    adds r0, #0x90
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0807256a
    movs r3, #1
lbl_0807256a:
    adds r1, r3, #0
    movs r3, #0
    adds r0, r2, #0
    adds r0, #0x92
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_0807257a
    movs r3, #1
lbl_0807257a:
    adds r4, r3, #0
    cmp r1, #0
    beq lbl_08072586
    adds r0, r2, #0
    adds r0, #0x98
    strb r6, [r0]
lbl_08072586:
    cmp r4, #0
    beq lbl_08072664
    ldr r0, [r5]
    adds r0, #0x99
    strb r6, [r0]
    cmp r1, #0
    beq lbl_08072664
    ldr r0, [r5]
    adds r0, #0x48
    strb r6, [r0]
    b lbl_080725ec
    .align 2, 0
lbl_0807259c: .4byte 0x000003b2
lbl_080725a0: .4byte 0x000003b1
lbl_080725a4: .4byte 0x000003b3
lbl_080725a8: .4byte 0x0000ffff
lbl_080725ac: .4byte 0x000003aa
lbl_080725b0:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x14
    bls lbl_08072664
    ldr r0, lbl_080725f8 @ =0x00000303
    adds r3, r3, r0
    ldrb r1, [r3]
    movs r2, #0x3f
    adds r0, r2, #0
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r3]
    ldr r0, [r5]
    ldr r1, lbl_080725fc @ =0x000003b3
    adds r0, r0, r1
    ldrb r1, [r0]
    ands r2, r1
    strb r2, [r0]
lbl_080725e4:
    ldr r0, [r5]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
lbl_080725ec:
    ldr r1, [r5]
    adds r1, #0x47
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08072664
    .align 2, 0
lbl_080725f8: .4byte 0x00000303
lbl_080725fc: .4byte 0x000003b3
lbl_08072600:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x48
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_08072664
    strb r2, [r1]
    ldr r0, [r5]
    adds r0, #0x47
    strb r2, [r0]
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r0, [r1]
    movs r2, #1
    eors r0, r2
    strb r0, [r1]
    b lbl_08072664
lbl_0807262e:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x3c
    bls lbl_08072664
    ldr r3, lbl_0807266c @ =0x000003b3
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x47
    movs r1, #2
    strb r1, [r0]
lbl_08072664:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807266c: .4byte 0x000003b3

    thumb_func_start chozo_statue_hint_scrolling
chozo_statue_hint_scrolling: @ 0x08072670
    push {r4, r5, r6, lr}
    ldr r1, lbl_0807268c @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x49
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #4
    bls lbl_08072682
    b lbl_080728b0
lbl_08072682:
    lsls r0, r0, #2
    ldr r1, lbl_08072690 @ =lbl_08072694
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807268c: .4byte sNonGameplayRamPointer
lbl_08072690: .4byte lbl_08072694
lbl_08072694: @ jump table
    .4byte lbl_080728b0 @ case 0
    .4byte lbl_080726a8 @ case 1
    .4byte lbl_080727e2 @ case 2
    .4byte lbl_08072806 @ case 3
    .4byte lbl_08072884 @ case 4
lbl_080726a8:
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r2, [r1]
    movs r0, #2
    orrs r0, r2
    strb r0, [r1]
    ldr r3, [r5]
    ldrb r1, [r3, #0x16]
    movs r0, #0xa
    subs r0, r0, r1
    lsls r0, r0, #3
    movs r2, #0x81
    lsls r2, r2, #2
    subs r0, r2, r0
    lsls r0, r0, #2
    adds r1, r3, #0
    adds r1, #0xa4
    strh r0, [r1]
    ldrb r1, [r3, #0x15]
    movs r0, #0xf
    subs r0, r0, r1
    lsls r0, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #2
    adds r4, r3, #0
    adds r4, #0xa6
    strh r2, [r4]
    ldr r0, lbl_0807270c @ =gBG3VOFS_NonGameplay
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xa0
    strh r1, [r0]
    ldr r0, lbl_08072710 @ =gBG3HOFS_NonGameplay
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xa2
    strh r1, [r0]
    ldrh r0, [r4]
    subs r0, r0, r1
    adds r1, r3, #0
    adds r1, #0xaa
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072714
    adds r1, #2
    movs r0, #0
    strb r0, [r1]
    b lbl_0807273c
    .align 2, 0
lbl_0807270c: .4byte gBG3VOFS_NonGameplay
lbl_08072710: .4byte gBG3HOFS_NonGameplay
lbl_08072714:
    movs r2, #1
    rsbs r2, r2, #0
    adds r1, r2, #0
    cmp r0, #0
    ble lbl_08072720
    movs r1, #1
lbl_08072720:
    adds r0, r3, #0
    adds r0, #0xad
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xaa
    adds r0, #0xad
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_0807273c:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0xa4
    adds r1, r2, #0
    adds r1, #0xa0
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r1, r2, #0
    adds r1, #0xa8
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072762
    adds r1, #4
    movs r0, #0
    strb r0, [r1]
    b lbl_0807278a
lbl_08072762:
    movs r3, #1
    rsbs r3, r3, #0
    adds r1, r3, #0
    cmp r0, #0
    ble lbl_0807276e
    movs r1, #1
lbl_0807276e:
    adds r0, r2, #0
    adds r0, #0xac
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xa8
    adds r0, #0xac
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_0807278a:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xaa
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r0, #0
    muls r3, r0, r3
    adds r0, r3, #0
    adds r1, #0xa8
    movs r2, #0
    ldrsh r1, [r1, r2]
    adds r3, r1, #0
    muls r3, r1, r3
    adds r1, r3, #0
    adds r0, r0, r1
    lsls r0, r0, #2
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x12
    cmp r4, #0
    bne lbl_080727c2
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0xad
    strb r4, [r1]
    adds r0, #0xac
    strb r4, [r0]
lbl_080727c2:
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0xae
    movs r2, #0
    strh r4, [r0]
    adds r1, r3, #0
    adds r1, #0xb0
    movs r0, #1
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0xb2
    strh r2, [r0]
    subs r1, #0x67
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
lbl_080727e2:
    ldr r1, [r5]
    adds r1, #0x4a
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x4a
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_080728b0
    movs r0, #0
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x49
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
lbl_08072806:
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xb2
    ldrh r1, [r2]
    adds r1, #4
    movs r6, #0
    strh r1, [r2]
    adds r0, #0xa0
    bl sub_08072144
    adds r4, r0, #0
    asrs r2, r4, #0x10
    ldr r0, lbl_08072878 @ =0x0000ffff
    ands r4, r0
    ldr r0, lbl_0807287c @ =gBG3VOFS_NonGameplay
    strh r2, [r0]
    ldr r0, lbl_08072880 @ =gBG3HOFS_NonGameplay
    strh r4, [r0]
    movs r3, #0
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xa4
    ldrh r0, [r0]
    cmp r2, r0
    bne lbl_0807283a
    movs r3, #1
lbl_0807283a:
    adds r2, r3, #0
    movs r3, #0
    adds r0, r1, #0
    adds r0, #0xa6
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_0807284a
    movs r3, #1
lbl_0807284a:
    adds r4, r3, #0
    cmp r2, #0
    beq lbl_08072856
    adds r0, r1, #0
    adds r0, #0xac
    strb r6, [r0]
lbl_08072856:
    cmp r4, #0
    beq lbl_08072860
    ldr r0, [r5]
    adds r0, #0xad
    strb r6, [r0]
lbl_08072860:
    cmp r2, #0
    beq lbl_080728b0
    cmp r4, #0
    beq lbl_080728b0
    ldr r0, [r5]
    adds r0, #0x4a
    strb r6, [r0]
    ldr r1, [r5]
    adds r1, #0x49
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
    .align 2, 0
lbl_08072878: .4byte 0x0000ffff
lbl_0807287c: .4byte gBG3VOFS_NonGameplay
lbl_08072880: .4byte gBG3HOFS_NonGameplay
lbl_08072884:
    ldr r1, [r5]
    adds r1, #0x4a
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x4a
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_080728b0
    strb r2, [r1]
    ldr r0, [r5]
    adds r0, #0x49
    strb r2, [r0]
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r0, [r1]
    movs r2, #2
    eors r0, r2
lbl_080728ae:
    strb r0, [r1]
lbl_080728b0:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start chozo_statue_hint_subroutine
chozo_statue_hint_subroutine: @ 0x080728b8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    bl chozo_statue_hint_movement
    bl chozo_statue_hint_scrolling
    ldr r0, lbl_080728e4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #8]
    cmp r0, #9
    bls lbl_080728d8
    b lbl_08072afe
lbl_080728d8:
    lsls r0, r0, #2
    ldr r1, lbl_080728e8 @ =lbl_080728ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080728e4: .4byte sNonGameplayRamPointer
lbl_080728e8: .4byte lbl_080728ec
lbl_080728ec: @ jump table
    .4byte lbl_08072ab8 @ case 0
    .4byte lbl_08072914 @ case 1
    .4byte lbl_08072928 @ case 2
    .4byte lbl_0807294c @ case 3
    .4byte lbl_08072974 @ case 4
    .4byte lbl_080729a0 @ case 5
    .4byte lbl_080729e0 @ case 6
    .4byte lbl_08072a58 @ case 7
    .4byte lbl_08072ab8 @ case 8
    .4byte lbl_08072ad4 @ case 9
lbl_08072914:
    ldr r2, lbl_08072924 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x47
    movs r3, #0
    movs r1, #1
    strb r1, [r0]
    b lbl_080729ce
    .align 2, 0
lbl_08072924: .4byte sNonGameplayRamPointer
lbl_08072928:
    ldr r3, lbl_08072948 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x46
    ldrb r0, [r0]
    movs r2, #3
    ands r2, r0
    cmp r2, #0
    beq lbl_0807293c
    b lbl_08072afe
lbl_0807293c:
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072948: .4byte sNonGameplayRamPointer
lbl_0807294c:
    ldr r1, lbl_08072964 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    blt lbl_08072968
    ldrb r0, [r2, #8]
    adds r0, #1
    b lbl_0807296a
    .align 2, 0
lbl_08072964: .4byte sNonGameplayRamPointer
lbl_08072968:
    movs r0, #8
lbl_0807296a:
    strb r0, [r2, #8]
    ldr r1, [r1]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_08072afe
lbl_08072974:
    ldr r5, lbl_0807299c @ =sNonGameplayRamPointer
    ldr r3, [r5]
    ldrh r0, [r3, #0xa]
    cmp r0, #0x3c
    bhi lbl_08072980
    b lbl_08072afe
lbl_08072980:
    adds r4, r3, #0
    adds r4, #0x66
    ldrh r1, [r4]
    movs r0, #0x18
    movs r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    ldr r0, [r5]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_0807299c: .4byte sNonGameplayRamPointer
lbl_080729a0:
    ldr r4, lbl_080729c4 @ =gWrittenToBLDALPHA_H
    ldrh r1, [r4]
    ldr r2, lbl_080729c8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r2]
    adds r3, r1, r0
    cmp r3, #0
    beq lbl_080729cc
    cmp r1, #0
    beq lbl_080729b6
    subs r0, r1, #1
    strh r0, [r4]
lbl_080729b6:
    ldrh r0, [r2]
    cmp r0, #0
    bne lbl_080729be
    b lbl_08072afe
lbl_080729be:
    subs r0, #1
    strh r0, [r2]
    b lbl_08072afe
    .align 2, 0
lbl_080729c4: .4byte gWrittenToBLDALPHA_H
lbl_080729c8: .4byte gWrittenToBLDALPHA_L
lbl_080729cc:
    ldr r2, lbl_080729dc @ =sNonGameplayRamPointer
lbl_080729ce:
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r2]
    strh r3, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_080729dc: .4byte sNonGameplayRamPointer
lbl_080729e0:
    ldr r4, lbl_08072a4c @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0x41
    ldrb r0, [r1]
    adds r0, #1
    movs r5, #0
    strb r0, [r1]
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrb r0, [r0]
    strb r0, [r1, #0x12]
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r0, #0x12]
    lsls r0, r0, #0xb
    ldr r1, [r1]
    adds r1, r1, r0
    ldr r2, lbl_08072a50 @ =0x0600e000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #1
    bl ChozoHintDeterminePath
    movs r0, #1
    bl unk_6db58
    ldr r1, [r4]
    movs r2, #0x85
    lsls r2, r2, #3
    adds r0, r1, r2
    ldr r2, lbl_08072a54 @ =0x0840d180
    ldrb r1, [r1, #0x12]
    adds r1, r1, r2
    ldrb r1, [r1]
    bl UpdateMenuOamDataID
    bl PauseScreenUpdateBossIcons
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    strh r5, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072a4c: .4byte sNonGameplayRamPointer
lbl_08072a50: .4byte 0x0600e000
lbl_08072a54: .4byte 0x0840d180
lbl_08072a58:
    ldr r0, lbl_08072a8c @ =sNonGameplayRamPointer
    mov ip, r0
    ldr r3, [r0]
    adds r6, r3, #0
    adds r6, #0x68
    ldrh r4, [r6]
    ldr r7, lbl_08072a90 @ =gWrittenToBLDALPHA_H
    ldrh r2, [r7]
    lsls r0, r2, #8
    ldr r5, lbl_08072a94 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r5]
    orrs r0, r1
    cmp r4, r0
    beq lbl_08072a98
    lsrs r0, r4, #8
    cmp r0, r2
    bls lbl_08072a7e
    adds r0, r2, #1
    strh r0, [r7]
lbl_08072a7e:
    ldrh r1, [r5]
    ldrb r0, [r6]
    cmp r0, r1
    bls lbl_08072afe
    adds r0, r1, #1
    strh r0, [r5]
    b lbl_08072afe
    .align 2, 0
lbl_08072a8c: .4byte sNonGameplayRamPointer
lbl_08072a90: .4byte gWrittenToBLDALPHA_H
lbl_08072a94: .4byte gWrittenToBLDALPHA_L
lbl_08072a98:
    adds r4, r3, #0
    adds r4, #0x66
    ldrh r1, [r4]
    ldr r0, lbl_08072ab4 @ =0x0000ffe7
    ands r0, r1
    movs r1, #0
    movs r2, #0
    strh r0, [r4]
    strb r1, [r3, #8]
    mov r1, ip
    ldr r0, [r1]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072ab4: .4byte 0x0000ffe7
lbl_08072ab8:
    ldr r3, lbl_08072ad0 @ =sNonGameplayRamPointer
    ldr r2, [r3]
    ldrh r0, [r2, #0xa]
    cmp r0, #0x28
    bls lbl_08072afe
    ldrb r0, [r2, #8]
    adds r0, #1
    movs r1, #0
    strb r0, [r2, #8]
    ldr r0, [r3]
    strh r1, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072ad0: .4byte sNonGameplayRamPointer
lbl_08072ad4:
    ldr r0, lbl_08072ae4 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08072ae8
    movs r2, #1
    mov r8, r2
    b lbl_08072afe
    .align 2, 0
lbl_08072ae4: .4byte gDemoState
lbl_08072ae8:
    ldr r2, lbl_08072b0c @ =gChangedInput
    ldr r0, lbl_08072b10 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #1
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08072afe
    movs r0, #1
    mov r8, r0
lbl_08072afe:
    mov r0, r8
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08072b0c: .4byte gChangedInput
lbl_08072b10: .4byte gButtonAssignments

    thumb_func_start chozo_statue_hint_change_area
chozo_statue_hint_change_area: @ 0x08072b14
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r6, r1, #0
    ldr r7, lbl_08072b70 @ =0x08345934
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    mov ip, r0
    ldr r0, lbl_08072b74 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    mov r5, ip
    ldrb r1, [r5]
    ldrb r5, [r0, #0x12]
    cmp r1, r5
    bne lbl_08072b78
    mov r5, ip
    ldrb r1, [r5, #4]
    adds r0, #0x42
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #2]
    strb r0, [r4]
    ldrb r0, [r4]
    lsls r0, r0, #5
    strh r0, [r2, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #3]
    strb r0, [r6]
    ldrb r0, [r6]
    adds r0, #4
    lsls r0, r0, #5
    strh r0, [r2]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072bae
    movs r0, #2
    b lbl_08072bb0
    .align 2, 0
lbl_08072b70: .4byte 0x08345934
lbl_08072b74: .4byte sNonGameplayRamPointer
lbl_08072b78:
    adds r0, #0x42
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #6]
    strb r0, [r4]
    ldrb r0, [r4]
    lsls r0, r0, #5
    strh r0, [r2, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #7]
    strb r0, [r6]
    ldrb r0, [r6]
    subs r0, #3
    lsls r0, r0, #5
    strh r0, [r2]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072bae
    movs r0, #2
    b lbl_08072bb0
lbl_08072bae:
    movs r0, #3
lbl_08072bb0:
    strb r0, [r2, #0xa]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ChozoHintDeterminePath
ChozoHintDeterminePath: @ 0x08072bb8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x14
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r1, lbl_08072bf4 @ =0x0840d038
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    add r2, sp, #4
    movs r3, #0x10
    bl DMATransfer
    ldr r0, lbl_08072bf8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08072bfc
    add r2, sp, #4
    ldrb r1, [r2, #0xb]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2, #0xb]
    b lbl_08072c06
    .align 2, 0
lbl_08072bf4: .4byte 0x0840d038
lbl_08072bf8: .4byte sNonGameplayRamPointer
lbl_08072bfc:
    add r0, sp, #4
    ldrb r1, [r0, #0xb]
    movs r2, #3
    orrs r1, r2
    strb r1, [r0, #0xb]
lbl_08072c06:
    cmp r7, #0
    bne lbl_08072c80
    ldr r0, lbl_08072c74 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0xba
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #0xb
lbl_08072c18:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c18
    ldr r0, lbl_08072c74 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0xea
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #4
lbl_08072c3c:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c3c
    ldr r2, lbl_08072c74 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x41
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x40
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x42
    movs r1, #1
    rsbs r1, r1, #0
    strb r1, [r0]
    bl check_activated_targets
    b lbl_08072cc8
    .align 2, 0
lbl_08072c74: .4byte sNonGameplayRamPointer
lbl_08072c78:
    adds r0, r2, #0
    adds r0, #0x40
    strb r5, [r0]
    b lbl_08072d42
lbl_08072c80:
    ldr r0, lbl_08072d9c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0xba
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #0xb
lbl_08072c8e:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c8e
    ldr r0, lbl_08072d9c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0xea
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #4
lbl_08072cb2:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072cb2
lbl_08072cc8:
    ldr r2, lbl_08072d9c @ =sNonGameplayRamPointer
    ldr r3, [r2]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r4, r3, r0
    ldr r6, lbl_08072da0 @ =0x0840e02c
    ldrh r1, [r3]
    movs r0, #0x10
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    bne lbl_08072ce2
    b lbl_08072e96
lbl_08072ce2:
    movs r1, #0xbe
    lsls r1, r1, #2
    adds r1, r1, r3
    mov sb, r1
    subs r6, #0xb4
    mov ip, r6
    cmp r7, #0
    bne lbl_08072d42
    movs r5, #0
    movs r0, #0xbe
    lsls r0, r0, #2
    adds r0, r0, r3
    mov sb, r0
    adds r2, r3, #0
    adds r0, r2, #0
    adds r0, #0x44
    ldrh r7, [r0]
    movs r3, #0
lbl_08072d06:
    adds r0, r7, #0
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08072d3a
    mov r1, ip
    adds r6, r3, r1
    ldrb r0, [r6]
    ldrb r1, [r2, #0x12]
    cmp r0, r1
    bne lbl_08072d3a
    ldrb r0, [r6, #3]
    ldrb r1, [r2, #0x14]
    cmp r0, r1
    bhi lbl_08072d3a
    ldrb r0, [r6, #4]
    cmp r1, r0
    bhi lbl_08072d3a
    ldrb r0, [r6, #1]
    ldrb r1, [r2, #0x13]
    cmp r0, r1
    bhi lbl_08072d3a
    ldrb r6, [r6, #2]
    cmp r1, r6
    bls lbl_08072c78
lbl_08072d3a:
    adds r3, #0xc
    adds r5, #1
    cmp r5, #0xf
    ble lbl_08072d06
lbl_08072d42:
    ldr r1, lbl_08072d9c @ =sNonGameplayRamPointer
    mov r8, r1
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0x40
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    mov r1, ip
    adds r6, r0, r1
    ldrb r3, [r6]
    ldrb r0, [r6, #6]
    cmp r3, r0
    bne lbl_08072da4
    ldrb r0, [r2, #0x13]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r2, #0x14]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #5]
    strb r0, [r4, #0xa]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #7]
    strb r0, [r1, #0x15]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #8]
    strb r0, [r1, #0x16]
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r1, #0x16]
    lsls r0, r0, #5
    strh r0, [r4]
    adds r4, #0x10
    b lbl_08072fda
    .align 2, 0
lbl_08072d9c: .4byte sNonGameplayRamPointer
lbl_08072da0: .4byte 0x0840e02c
lbl_08072da4:
    ldr r1, lbl_08072de4 @ =0x087603f0
    ldr r0, lbl_08072de8 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r7, [r0]
    ldrb r1, [r6, #6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r7, r7, r0
    ldrb r0, [r2, #0x12]
    cmp r0, r3
    bne lbl_08072dec
    ldrb r0, [r2, #0x13]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r2, #0x14]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #5]
    strb r0, [r4, #0xa]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x15
    adds r1, #0x16
    adds r2, r4, #0
    adds r3, r7, #0
    b lbl_08072e8e
    .align 2, 0
lbl_08072de4: .4byte 0x087603f0
lbl_08072de8: .4byte gCurrentArea
lbl_08072dec:
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, r1
    bne lbl_08072e50
    adds r0, r2, #0
    adds r0, #0x41
    ldrb r0, [r0]
    subs r0, #1
    lsls r5, r0, #1
    adds r0, r2, #0
    adds r0, #0x13
    adds r1, r2, #0
    adds r1, #0x14
    adds r3, r7, r5
    adds r2, r4, #0
    bl chozo_statue_hint_change_area
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #7]
    strb r0, [r1, #0x15]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #8]
    strb r0, [r1, #0x16]
    ldrb r0, [r6, #7]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r6, #8]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    adds r4, #0x10
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x42
    movs r1, #0xff
    strb r1, [r0]
    b lbl_08072fda
lbl_08072e50:
    adds r0, r2, #0
    adds r0, #0x41
    ldrb r0, [r0]
    subs r0, #1
    lsls r5, r0, #1
    adds r0, r2, #0
    adds r0, #0x13
    adds r1, r2, #0
    adds r1, #0x14
    adds r3, r7, r5
    adds r2, r4, #0
    bl chozo_statue_hint_change_area
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x41
    ldrb r0, [r0]
    lsls r5, r0, #1
    adds r0, r1, #0
    adds r0, #0x15
    adds r1, #0x16
    adds r3, r7, r5
    adds r2, r4, #0
lbl_08072e8e:
    bl chozo_statue_hint_change_area
    adds r4, #0x10
    b lbl_08072fda
lbl_08072e96:
    adds r2, r3, #0
    adds r2, #0x44
    ldrh r0, [r2]
    cmp r0, #0
    bne lbl_08072ea2
    b lbl_08072fda
lbl_08072ea2:
    ldr r3, lbl_08072f70 @ =gCurrentArea
    ldrb r0, [r3]
    cmp r0, #5
    bls lbl_08072eac
    b lbl_08072fda
lbl_08072eac:
    ldr r1, lbl_08072f74 @ =0x087603f0
    ldrb r0, [r3]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r7, [r0]
    cmp r7, #0
    bne lbl_08072ebc
    b lbl_08072fda
lbl_08072ebc:
    movs r5, #0
    ldrh r0, [r2]
    movs r1, #1
    ands r0, r1
    subs r6, #0xb4
    mov ip, r6
    cmp r0, #0
    beq lbl_08072ede
    ldr r6, lbl_08072f78 @ =0x0840e038
    ldrb r0, [r6]
    movs r3, #0
    cmp r0, #0
    beq lbl_08072f04
lbl_08072ed6:
    adds r0, r3, r6
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_08072f04
lbl_08072ede:
    adds r5, #1
    cmp r5, #0xe
    bgt lbl_08072f04
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08072ede
    ldr r6, lbl_08072f78 @ =0x0840e038
    lsls r0, r5, #1
    adds r1, r0, r6
    ldrb r1, [r1]
    adds r3, r0, #0
    cmp r1, #0
    bne lbl_08072ed6
lbl_08072f04:
    lsls r0, r5, #1
    adds r0, r0, r5
    lsls r0, r0, #2
    mov r1, ip
    adds r6, r0, r1
    ldrb r0, [r6, #6]
    cmp r0, #2
    bhi lbl_08072fda
    adds r1, r0, #0
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r7, r7, r0
    ldr r5, lbl_08072f7c @ =0x08345934
    mov ip, r5
    ldr r0, lbl_08072f80 @ =sNonGameplayRamPointer
    mov r8, r0
    adds r3, r7, #0
    movs r1, #0x3f
    mov sb, r1
    movs r6, #0x40
lbl_08072f2e:
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    mov r1, ip
    adds r2, r0, r1
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r2]
    ldrb r1, [r1, #0x12]
    cmp r0, r1
    bne lbl_08072f8a
    ldrb r0, [r2, #2]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #3]
    adds r0, #4
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    mov r0, sb
    ands r0, r1
    orrs r0, r6
    strb r0, [r4, #0xb]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072f84
    movs r0, #2
    b lbl_08072f86
    .align 2, 0
lbl_08072f70: .4byte gCurrentArea
lbl_08072f74: .4byte 0x087603f0
lbl_08072f78: .4byte 0x0840e038
lbl_08072f7c: .4byte 0x08345934
lbl_08072f80: .4byte sNonGameplayRamPointer
lbl_08072f84:
    movs r0, #3
lbl_08072f86:
    strb r0, [r4, #0xa]
    adds r4, #0x10
lbl_08072f8a:
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    mov r1, ip
    adds r2, r0, r1
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r2, #4]
    ldrb r1, [r1, #0x12]
    cmp r0, r1
    bne lbl_08072fd2
    ldrb r0, [r2, #6]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #7]
    subs r0, #3
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    mov r0, sb
    ands r0, r1
    orrs r0, r6
    strb r0, [r4, #0xb]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072fcc
    movs r0, #2
    b lbl_08072fce
lbl_08072fcc:
    movs r0, #3
lbl_08072fce:
    strb r0, [r4, #0xa]
    adds r4, #0x10
lbl_08072fd2:
    adds r3, #2
    adds r0, r7, #5
    cmp r3, r0
    ble lbl_08072f2e
lbl_08072fda:
    movs r5, #0
    ldr r1, lbl_08073048 @ =sNonGameplayRamPointer
    mov r8, r1
    movs r7, #0
lbl_08072fe2:
    mov r0, r8
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r5, r0
    beq lbl_0807302e
    adds r0, r3, #0
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807302e
    ldr r0, lbl_0807304c @ =0x0840df78
    adds r6, r7, r0
    ldrb r0, [r6, #6]
    ldrb r3, [r3, #0x12]
    cmp r0, r3
    bne lbl_0807302e
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    ldrb r0, [r6, #7]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r6, #8]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    adds r4, #0x10
lbl_0807302e:
    adds r7, #0xc
    adds r5, #1
    cmp r5, #0xf
    ble lbl_08072fe2
    bl draw_boss_flames
    add sp, #0x14
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073048: .4byte sNonGameplayRamPointer
lbl_0807304c: .4byte 0x0840df78

    thumb_func_start chozo_statue_hint_check_events_flags
chozo_statue_hint_check_events_flags: @ 0x08073050
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #1
    rsbs r4, r4, #0
    ldr r0, lbl_08073080 @ =0x0840e058
    adds r0, r5, r0
    ldrb r1, [r0]
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_080730c4
    ldr r3, lbl_08073084 @ =0x0840e038
    lsls r2, r5, #1
    adds r0, r2, r3
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807308c
    ldr r1, lbl_08073088 @ =gEquipment
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r2, [r1, #0xc]
    b lbl_08073098
    .align 2, 0
lbl_08073080: .4byte 0x0840e058
lbl_08073084: .4byte 0x0840e038
lbl_08073088: .4byte gEquipment
lbl_0807308c:
    cmp r0, #1
    bne lbl_080730a8
    ldr r1, lbl_080730a4 @ =gEquipment
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r2, [r1, #0xe]
lbl_08073098:
    ldrb r1, [r0]
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    b lbl_080730bc
    .align 2, 0
lbl_080730a4: .4byte gEquipment
lbl_080730a8:
    cmp r0, #2
    bne lbl_080730bc
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r1, [r0]
    movs r0, #3
    bl EventFunction
    lsls r0, r0, #0x18
    asrs r4, r0, #0x18
lbl_080730bc:
    cmp r4, #0
    blt lbl_080730c4
    movs r0, #1
    eors r4, r0
lbl_080730c4:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start check_activated_targets
check_activated_targets: @ 0x080730cc
    push {r4, lr}
    ldr r0, lbl_08073104 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x44
    movs r1, #0
    strh r1, [r0]
    movs r4, #0
lbl_080730da:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    bl chozo_statue_hint_check_events_flags
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_080730f8
    ldr r0, lbl_08073104 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r2, #0x44
    movs r0, #1
    lsls r0, r4
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
lbl_080730f8:
    adds r4, #1
    cmp r4, #0xf
    ble lbl_080730da
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073104: .4byte sNonGameplayRamPointer

    thumb_func_start check_non_explored_area_has_hint
check_non_explored_area_has_hint: @ 0x08073108
    push {r4, r5, lr}
    ldr r0, lbl_08073148 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xb9
    movs r1, #0
    strb r1, [r0]
    movs r4, #0
    ldr r5, lbl_0807314c @ =0x0840df78
lbl_08073118:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    bl chozo_statue_hint_check_events_flags
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_08073138
    ldr r0, lbl_08073148 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r2, #0xb9
    movs r0, #1
    ldrb r1, [r5, #6]
    lsls r0, r1
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
lbl_08073138:
    adds r5, #0xc
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08073118
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073148: .4byte sNonGameplayRamPointer
lbl_0807314c: .4byte 0x0840df78

    thumb_func_start draw_boss_flames
draw_boss_flames: @ 0x08073150
    push {r4, r5, lr}
    sub sp, #4
    ldr r4, lbl_080731c4 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    adds r2, #0xec
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r1, [r4]
    ldrb r0, [r1, #0x12]
    adds r5, r4, #0
    cmp r0, #0
    bne lbl_0807323e
    adds r0, r1, #0
    adds r0, #0x44
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080731d6
    movs r1, #0
lbl_08073184:
    ldr r2, [r5]
    lsls r4, r1, #4
    adds r0, r2, r4
    ldr r3, lbl_080731c8 @ =0x000002f2
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xa
    bne lbl_080731d0
    adds r0, r2, #0
    adds r0, #0xef
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0xf1
    movs r1, #1
    strb r1, [r0]
    ldr r3, [r5]
    adds r2, r3, r4
    ldr r4, lbl_080731cc @ =0x000002ea
    adds r0, r2, r4
    ldrh r1, [r0]
    subs r1, #8
    strh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xf4
    strh r1, [r0]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrh r0, [r2]
    adds r3, #0xf6
    strh r0, [r3]
    b lbl_080731d6
    .align 2, 0
lbl_080731c4: .4byte sNonGameplayRamPointer
lbl_080731c8: .4byte 0x000002f2
lbl_080731cc: .4byte 0x000002ea
lbl_080731d0:
    adds r1, #1
    cmp r1, #0xb
    ble lbl_08073184
lbl_080731d6:
    ldr r0, [r5]
    adds r0, #0x44
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807323e
    movs r1, #0
lbl_080731e8:
    ldr r2, [r5]
    lsls r4, r1, #4
    adds r0, r2, r4
    ldr r3, lbl_08073230 @ =0x000002f2
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xe
    bne lbl_08073238
    adds r0, r2, #0
    adds r0, #0xfb
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0xfd
    movs r1, #1
    strb r1, [r0]
    ldr r3, [r5]
    adds r2, r3, r4
    ldr r4, lbl_08073234 @ =0x000002ea
    adds r0, r2, r4
    ldrh r1, [r0]
    adds r1, #8
    strh r1, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r3, r4
    strh r1, [r0]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrh r0, [r2]
    movs r2, #0x81
    lsls r2, r2, #1
    adds r1, r3, r2
    strh r0, [r1]
    b lbl_0807323e
    .align 2, 0
lbl_08073230: .4byte 0x000002f2
lbl_08073234: .4byte 0x000002ea
lbl_08073238:
    adds r1, #1
    cmp r1, #0xb
    ble lbl_080731e8
lbl_0807323e:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08073248
sub_08073248: @ 0x08073248
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #2]
    cmp r0, #0
    beq lbl_08073292
    movs r0, #5
    ldrsb r0, [r2, r0]
    ldrh r3, [r2]
    adds r1, r0, r3
    strh r1, [r2]
    ldrb r3, [r2, #5]
    cmp r0, #0
    ble lbl_0807326e
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x3e
    bls lbl_08073278
    movs r0, #0xff
    b lbl_08073276
lbl_0807326e:
    lsls r0, r1, #0x10
    cmp r0, #0
    bne lbl_08073278
    movs r0, #1
lbl_08073276:
    strb r0, [r2, #5]
lbl_08073278:
    ldr r0, lbl_08073298 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r2, #3]
    lsls r0, r0, #4
    adds r1, r1, r0
    ldrh r0, [r2]
    lsrs r0, r0, #2
    ldrh r2, [r2, #0xa]
    adds r0, r0, r2
    movs r2, #0xba
    lsls r2, r2, #2
    adds r1, r1, r2
    strh r0, [r1]
lbl_08073292:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073298: .4byte sNonGameplayRamPointer

    thumb_func_start SramRead_All
SramRead_All: @ 0x0807329c
    push {r4, r5, lr}
    movs r4, #3
    ldr r5, lbl_080732b8 @ =gSramCorruptFlag
lbl_080732a2:
    cmp r4, #0
    beq lbl_080732b2
    bl sub_08074304
    ldrb r0, [r5]
    subs r4, #1
    cmp r0, #0
    bne lbl_080732a2
lbl_080732b2:
    movs r4, #3
    b lbl_080732c2
    .align 2, 0
lbl_080732b8: .4byte gSramCorruptFlag
lbl_080732bc:
    subs r4, #1
    cmp r4, #0
    beq lbl_080732d2
lbl_080732c2:
    movs r0, #0xe
    bl DoSramOperation
    movs r0, #0x10
    bl DoSramOperation
    cmp r0, #0
    bne lbl_080732bc
lbl_080732d2:
    bl sub_08073394
    bl sub_080743a4
    bl sub_08074a7c
    bl sub_08075010
    bl sub_08074da4
    cmp r0, #0
    beq lbl_080732f4
    ldr r1, lbl_080732fc @ =gLanguage
    movs r0, #2
    strb r0, [r1]
    bl SramWrite_Language
lbl_080732f4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080732fc: .4byte gLanguage

    thumb_func_start SramWrite_FileScreenOptionsUnlocked
SramWrite_FileScreenOptionsUnlocked: @ 0x08073300
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073388 @ =0x08754bc8
    ldr r4, [r2]
    movs r0, #0x30
    strb r0, [r4, #8]
    movs r0, #0x31
    strb r0, [r4, #9]
    ldrh r0, [r4, #0xa]
    adds r0, #1
    strh r0, [r4, #0xa]
    ldr r1, lbl_0807338c @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1]
    strh r0, [r4, #0xc]
    ldrb r0, [r1, #4]
    strb r0, [r4, #0xe]
    movs r0, #2
    strb r0, [r4, #0xf]
    movs r0, #0x34
    strb r0, [r4, #0x10]
    ldrb r0, [r1, #5]
    strb r0, [r4, #0x11]
    ldrb r0, [r1, #6]
    strb r0, [r4, #0x12]
    ldrb r0, [r1, #7]
    strb r0, [r4, #0x13]
    ldrh r0, [r1, #2]
    strh r0, [r4, #0x14]
    ldr r0, [r1, #8]
    str r0, [r4, #0x18]
    movs r3, #0
    adds r6, r2, #0
    adds r2, r4, #0
    adds r2, #0x1c
    ldr r5, lbl_08073390 @ =0x08411468
lbl_08073344:
    adds r0, r2, r3
    adds r1, r3, r5
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073344
    movs r0, #0
    str r0, [r4]
    subs r0, #1
    str r0, [r4, #4]
    ldr r2, [r6]
    movs r1, #0
    movs r3, #3
lbl_08073360:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073360
    str r1, [r4]
    mvns r0, r1
    str r0, [r4, #4]
    movs r0, #0
    bl DoSramOperation
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073388: .4byte 0x08754bc8
lbl_0807338c: .4byte gFileScreenOptionsUnlocked
lbl_08073390: .4byte 0x08411468

    thumb_func_start sub_08073394
sub_08073394: @ 0x08073394
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #8
    movs r0, #0
    bl sub_080734e8
    adds r6, r0, #0
    movs r0, #1
    bl sub_080734e8
    mov r8, r0
    movs r0, #2
    bl sub_080734e8
    adds r7, r0, #0
    cmp r6, #0
    beq lbl_08073470
    add r0, sp, #4
    ldr r1, lbl_08073404 @ =0x0000ffff
    adds r5, r1, #0
    strh r5, [r0]
    ldr r1, lbl_08073408 @ =0x040000d4
    str r0, [r1]
    ldr r3, lbl_0807340c @ =0x08754bc8
    mov sb, r3
    ldr r2, [r3]
    str r2, [r1, #4]
    ldr r4, lbl_08073410 @ =0x81000020
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    cmp r7, #0
    beq lbl_08073432
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    ldr r3, lbl_08073414 @ =0x00006d40
    adds r0, r2, r3
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    adds r3, r2, #0
    mov r0, r8
    cmp r0, #0
    beq lbl_08073418
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    adds r0, r3, #0
    adds r0, #0x40
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_080734a4
    .align 2, 0
lbl_08073404: .4byte 0x0000ffff
lbl_08073408: .4byte 0x040000d4
lbl_0807340c: .4byte 0x08754bc8
lbl_08073410: .4byte 0x81000020
lbl_08073414: .4byte 0x00006d40
lbl_08073418:
    adds r1, r2, #0
    adds r1, #0x40
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r6, #0
    movs r0, #0
    bl DoSramOperation
    b lbl_080734a4
lbl_08073432:
    ldr r3, lbl_0807346c @ =0x00006d40
    adds r1, r2, r3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r6, #0
    movs r0, #0
    bl DoSramOperation
    mov r0, r8
    cmp r0, #0
    beq lbl_080734a4
    mov r3, sb
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0x40
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #1
    bl DoSramOperation
    b lbl_080734a4
    .align 2, 0
lbl_0807346c: .4byte 0x00006d40
lbl_08073470:
    ldr r4, lbl_080734b0 @ =0x08754bc8
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x40
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #1
    bl DoSramOperation
    cmp r7, #0
    beq lbl_080734a4
    ldr r1, [r4]
    ldr r0, lbl_080734b4 @ =0x00006d40
    adds r2, r1, r0
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #2
    bl DoSramOperation
lbl_080734a4:
    cmp r6, #0
    bne lbl_080734b8
    bl sub_08073584
    b lbl_080734d0
    .align 2, 0
lbl_080734b0: .4byte 0x08754bc8
lbl_080734b4: .4byte 0x00006d40
lbl_080734b8:
    bl EraseSram
    ldr r1, lbl_080734e0 @ =0x0841147c
    ldr r2, lbl_080734e4 @ =gFileScreenOptionsUnlocked
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0xc
    bl DMATransfer
    bl SramWrite_FileScreenOptionsUnlocked
lbl_080734d0:
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080734e0: .4byte 0x0841147c
lbl_080734e4: .4byte gFileScreenOptionsUnlocked

    thumb_func_start sub_080734e8
sub_080734e8: @ 0x080734e8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r4, #0
    cmp r0, #2
    bne lbl_08073508
    ldr r0, lbl_08073500 @ =0x08754bc8
    ldr r0, [r0]
    ldr r1, lbl_08073504 @ =0x00006d40
    adds r0, r0, r1
    b lbl_0807351c
    .align 2, 0
lbl_08073500: .4byte 0x08754bc8
lbl_08073504: .4byte 0x00006d40
lbl_08073508:
    cmp r0, #1
    bne lbl_08073518
    ldr r0, lbl_08073514 @ =0x08754bc8
    ldr r0, [r0]
    adds r0, #0x40
    b lbl_0807351c
    .align 2, 0
lbl_08073514: .4byte 0x08754bc8
lbl_08073518:
    ldr r0, lbl_0807357c @ =0x08754bc8
    ldr r0, [r0]
lbl_0807351c:
    movs r2, #0
    adds r1, r0, #0
    ldr r7, [r1]
    adds r5, r1, #0
    adds r5, #0x1c
    ldr r0, [r1, #4]
    mov ip, r0
    movs r3, #3
lbl_0807352c:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_0807352c
    cmp r7, r2
    beq lbl_0807354a
    movs r0, #1
    orrs r4, r0
lbl_0807354a:
    movs r3, #0
    adds r2, r5, #0
    ldr r6, lbl_08073580 @ =0x08411468
    movs r5, #2
lbl_08073552:
    adds r0, r2, r3
    adds r1, r3, r6
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08073560
    orrs r4, r5
lbl_08073560:
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073552
    mov r1, ip
    mvns r0, r1
    cmp r7, r0
    beq lbl_08073572
    movs r0, #4
    orrs r4, r0
lbl_08073572:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807357c: .4byte 0x08754bc8
lbl_08073580: .4byte 0x08411468

    thumb_func_start sub_08073584
sub_08073584: @ 0x08073584
    ldr r0, lbl_080735a8 @ =0x08754bc8
    ldr r1, [r0]
    ldr r2, lbl_080735ac @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1, #0xc]
    strh r0, [r2]
    ldrb r0, [r1, #0xe]
    strb r0, [r2, #4]
    ldrb r0, [r1, #0x11]
    strb r0, [r2, #5]
    ldrb r0, [r1, #0x12]
    strb r0, [r2, #6]
    ldrb r0, [r1, #0x13]
    strb r0, [r2, #7]
    ldrh r0, [r1, #0x14]
    strh r0, [r2, #2]
    ldr r0, [r1, #0x18]
    str r0, [r2, #8]
    bx lr
    .align 2, 0
lbl_080735a8: .4byte 0x08754bc8
lbl_080735ac: .4byte gFileScreenOptionsUnlocked

    thumb_func_start SramProcessIntroSave
SramProcessIntroSave: @ 0x080735b0
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_080735d8 @ =gDisableSoftreset
    ldrb r0, [r1]
    ldr r2, lbl_080735dc @ =gSramOperationStage
    cmp r0, #0
    bne lbl_080735c4
    strb r0, [r2]
    movs r0, #1
    strb r0, [r1]
lbl_080735c4:
    ldrb r0, [r2]
    cmp r0, #4
    bls lbl_080735cc
    b lbl_080736bc
lbl_080735cc:
    lsls r0, r0, #2
    ldr r1, lbl_080735e0 @ =lbl_080735e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080735d8: .4byte gDisableSoftreset
lbl_080735dc: .4byte gSramOperationStage
lbl_080735e0: .4byte lbl_080735e4
lbl_080735e4: @ jump table
    .4byte lbl_080735f8 @ case 0
    .4byte lbl_08073658 @ case 1
    .4byte lbl_08073668 @ case 2
    .4byte lbl_08073674 @ case 3
    .4byte lbl_080736bc @ case 4
lbl_080735f8:
    ldr r5, lbl_08073648 @ =gGameCompletion
    movs r3, #1
    strb r3, [r5, #1]
    ldr r4, lbl_0807364c @ =gSaveFilesInfo
    ldr r2, lbl_08073650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    strb r3, [r0, #0x12]
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    ldrb r0, [r0, #0x11]
    strb r0, [r5]
    ldr r3, lbl_08073654 @ =0x08754bc8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r3]
    adds r2, r2, r0
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    b lbl_080736a2
    .align 2, 0
lbl_08073648: .4byte gGameCompletion
lbl_0807364c: .4byte gSaveFilesInfo
lbl_08073650: .4byte gMostRecentSaveFile
lbl_08073654: .4byte 0x08754bc8
lbl_08073658:
    bl sub_080736d8
    ldr r1, lbl_08073664 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    b lbl_080736a2
    .align 2, 0
lbl_08073664: .4byte gUnk_3000c20
lbl_08073668:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_080736c4
    b lbl_080736a2
lbl_08073674:
    ldr r2, lbl_080736ac @ =0x08754bc8
    ldr r0, lbl_080736b0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080736b4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_080736a2:
    ldr r1, lbl_080736b8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080736c4
    .align 2, 0
lbl_080736ac: .4byte 0x08754bc8
lbl_080736b0: .4byte gMostRecentSaveFile
lbl_080736b4: .4byte 0x000036e0
lbl_080736b8: .4byte gSramOperationStage
lbl_080736bc:
    ldr r1, lbl_080736d4 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r2]
lbl_080736c4:
    ldr r0, lbl_080736d4 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080736d4: .4byte gDisableSoftreset

    thumb_func_start sub_080736d8
sub_080736d8: @ 0x080736d8
    push {r4, lr}
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_080737ac @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_080737b0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r1, lbl_080737b4 @ =gGameCompletion
    ldrb r0, [r1, #1]
    strb r0, [r4, #0x19]
    ldrb r0, [r1]
    strb r0, [r4, #0x18]
    ldr r0, lbl_080737b8 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_080737bc @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3e
    strb r0, [r1]
    ldr r0, lbl_080737c0 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r4, #0x1a]
    ldr r2, lbl_080737c4 @ =gBestCompletionTimes
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_0807373e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_0807373e
    movs r1, #0x94
    lsls r1, r1, #2
    adds r0, r4, r1
    ldr r1, lbl_080737c8 @ =0x08411430
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073772:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073772
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080737a4: .4byte 0x08754bc8
lbl_080737a8: .4byte gMostRecentSaveFile
lbl_080737ac: .4byte 0x08411410
lbl_080737b0: .4byte 0x08411420
lbl_080737b4: .4byte gGameCompletion
lbl_080737b8: .4byte gDifficulty
lbl_080737bc: .4byte gTimeAttackFlag
lbl_080737c0: .4byte gLanguage
lbl_080737c4: .4byte gBestCompletionTimes
lbl_080737c8: .4byte 0x08411430

    thumb_func_start SramProcessEndingSave
SramProcessEndingSave: @ 0x080737cc
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_080737e8 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_080737de
    b lbl_080738e0
lbl_080737de:
    lsls r0, r1, #2
    ldr r1, lbl_080737ec @ =lbl_080737f0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080737e8: .4byte gSramOperationStage
lbl_080737ec: .4byte lbl_080737f0
lbl_080737f0: @ jump table
    .4byte lbl_08073808 @ case 0
    .4byte lbl_0807381c @ case 1
    .4byte lbl_08073828 @ case 2
    .4byte lbl_08073868 @ case 3
    .4byte lbl_08073898 @ case 4
    .4byte lbl_080738e0 @ case 5
lbl_08073808:
    ldr r1, lbl_08073818 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_080738e6
    .align 2, 0
lbl_08073818: .4byte gUnk_3000c20
lbl_0807381c:
    movs r0, #2
    bl unk_fbc
    cmp r0, #0
    beq lbl_080738e6
    b lbl_080738c6
lbl_08073828:
    movs r2, #1
    ldr r0, lbl_08073858 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073838
    movs r2, #8
lbl_08073838:
    ldr r1, lbl_0807385c @ =gGameCompletion
    ldr r0, lbl_08073860 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl check_set_new_best_completion_time
    bl sub_080739e8
    ldr r0, lbl_08073864 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_080738c6
    .align 2, 0
lbl_08073858: .4byte gLanguage
lbl_0807385c: .4byte gGameCompletion
lbl_08073860: .4byte gDifficulty
lbl_08073864: .4byte gUnk_3000c20
lbl_08073868:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_080738e6
    ldr r2, lbl_0807388c @ =gSaveFilesInfo
    ldr r0, lbl_08073890 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073894 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_080738c6
    .align 2, 0
lbl_0807388c: .4byte gSaveFilesInfo
lbl_08073890: .4byte gMostRecentSaveFile
lbl_08073894: .4byte gGameCompletion
lbl_08073898:
    ldr r2, lbl_080738d0 @ =0x08754bc8
    ldr r0, lbl_080738d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080738d8 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_080738c6:
    ldr r1, lbl_080738dc @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080738e6
    .align 2, 0
lbl_080738d0: .4byte 0x08754bc8
lbl_080738d4: .4byte gMostRecentSaveFile
lbl_080738d8: .4byte 0x000036e0
lbl_080738dc: .4byte gSramOperationStage
lbl_080738e0:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_080738e6:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start check_set_new_best_completion_time
check_set_new_best_completion_time: @ 0x080738f0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080739cc @ =0x083459a0
    mov r8, r0
    ldrb r4, [r0, #0x1c]
    ldr r7, lbl_080739d0 @ =gEquipment
    ldrh r0, [r7]
    ldr r2, lbl_080739d4 @ =0x083459c4
    ldr r1, lbl_080739d8 @ =gDifficulty
    ldrb r1, [r1]
    mov sb, r1
    lsls r1, r1, #2
    adds r6, r1, r2
    ldrb r1, [r6]
    bl __divsi3
    eors r0, r4
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    mov r2, r8
    ldrb r4, [r2, #0x1d]
    ldrh r0, [r7, #2]
    ldrb r1, [r6, #1]
    bl __divsi3
    cmp r4, r0
    beq lbl_08073930
    movs r0, #2
    orrs r5, r0
lbl_08073930:
    ldrb r0, [r7, #4]
    ldrb r1, [r6, #2]
    bl __udivsi3
    mov r3, r8
    ldrb r1, [r3, #0x1e]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073948
    movs r0, #4
    orrs r5, r0
lbl_08073948:
    ldrb r0, [r7, #5]
    ldrb r1, [r6, #3]
    bl __udivsi3
    mov r2, r8
    ldrb r1, [r2, #0x1f]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073960
    movs r0, #8
    orrs r5, r0
lbl_08073960:
    movs r0, #0
    cmp r5, #0
    bne lbl_08073968
    movs r0, #6
lbl_08073968:
    adds r5, r0, #0
    ldr r0, lbl_080739dc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08073978
    adds r5, #3
lbl_08073978:
    add r5, sb
    ldr r1, lbl_080739e0 @ =gBestCompletionTimes
    lsls r0, r5, #2
    adds r4, r0, r1
    ldrb r0, [r4]
    lsls r2, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #5
    adds r2, r2, r0
    lsls r2, r2, #4
    ldrb r1, [r4, #1]
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrb r3, [r4, #2]
    adds r2, r2, r3
    ldr r5, lbl_080739e4 @ =gInGameTimer
    ldrb r0, [r5]
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #5
    adds r1, r1, r0
    lsls r1, r1, #4
    ldrb r3, [r5, #1]
    lsls r0, r3, #4
    subs r0, r0, r3
    lsls r0, r0, #2
    adds r1, r1, r0
    ldrb r0, [r5, #2]
    adds r1, r1, r0
    cmp r2, r1
    ble lbl_080739be
    ldr r0, [r5]
    str r0, [r4]
lbl_080739be:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080739cc: .4byte 0x083459a0
lbl_080739d0: .4byte gEquipment
lbl_080739d4: .4byte 0x083459c4
lbl_080739d8: .4byte gDifficulty
lbl_080739dc: .4byte gLanguage
lbl_080739e0: .4byte gBestCompletionTimes
lbl_080739e4: .4byte gInGameTimer

    thumb_func_start sub_080739e8
sub_080739e8: @ 0x080739e8
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073a74 @ =0x08754bc8
    ldr r3, lbl_08073a78 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073a7c @ =gGameCompletion
    ldrb r0, [r0]
    strb r0, [r4, #0x18]
    adds r6, r2, #0
    adds r5, r3, #0
    ldr r2, lbl_08073a80 @ =gBestCompletionTimes
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_08073a1e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a1e
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r1, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #4
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r1, #0x80
    ldr r0, [r6]
    adds r2, r0, r1
    movs r1, #0
    movs r3, #0x90
lbl_08073a40:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a40
    str r1, [r4, #0x10]
    mvns r0, r1
    str r0, [r4, #0x14]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073a74: .4byte 0x08754bc8
lbl_08073a78: .4byte gMostRecentSaveFile
lbl_08073a7c: .4byte gGameCompletion
lbl_08073a80: .4byte gBestCompletionTimes

    thumb_func_start sub_08073a84
sub_08073a84: @ 0x08073a84
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_08073aa0 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_08073a96
    b lbl_08073b94
lbl_08073a96:
    lsls r0, r1, #2
    ldr r1, lbl_08073aa4 @ =lbl_08073aa8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073aa0: .4byte gSramOperationStage
lbl_08073aa4: .4byte lbl_08073aa8
lbl_08073aa8: @ jump table
    .4byte lbl_08073ac0 @ case 0
    .4byte lbl_08073ad4 @ case 1
    .4byte lbl_08073ae0 @ case 2
    .4byte lbl_08073b1c @ case 3
    .4byte lbl_08073b4c @ case 4
    .4byte lbl_08073b94 @ case 5
lbl_08073ac0:
    ldr r1, lbl_08073ad0 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_08073b9a
    .align 2, 0
lbl_08073ad0: .4byte gUnk_3000c20
lbl_08073ad4:
    movs r0, #2
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073b9a
    b lbl_08073b7a
lbl_08073ae0:
    movs r2, #1
    ldr r0, lbl_08073b0c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073af0
    movs r2, #8
lbl_08073af0:
    ldr r1, lbl_08073b10 @ =gGameCompletion
    ldr r0, lbl_08073b14 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl sub_080739e8
    ldr r0, lbl_08073b18 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b0c: .4byte gLanguage
lbl_08073b10: .4byte gGameCompletion
lbl_08073b14: .4byte gDifficulty
lbl_08073b18: .4byte gUnk_3000c20
lbl_08073b1c:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073b9a
    ldr r2, lbl_08073b40 @ =gSaveFilesInfo
    ldr r0, lbl_08073b44 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073b48 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b40: .4byte gSaveFilesInfo
lbl_08073b44: .4byte gMostRecentSaveFile
lbl_08073b48: .4byte gGameCompletion
lbl_08073b4c:
    ldr r2, lbl_08073b84 @ =0x08754bc8
    ldr r0, lbl_08073b88 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073b8c @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_08073b7a:
    ldr r1, lbl_08073b90 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08073b9a
    .align 2, 0
lbl_08073b84: .4byte 0x08754bc8
lbl_08073b88: .4byte gMostRecentSaveFile
lbl_08073b8c: .4byte 0x000036e0
lbl_08073b90: .4byte gSramOperationStage
lbl_08073b94:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_08073b9a:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start SramSaveFile
SramSaveFile: @ 0x08073ba4
    push {lr}
    sub sp, #4
    ldr r1, lbl_08073bd4 @ =gDisableSoftreset
    ldrb r2, [r1]
    ldr r3, lbl_08073bd8 @ =gSramOperationStage
    cmp r2, #0
    bne lbl_08073bc0
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_08073bdc @ =gHasSaved
    strb r0, [r1]
    strb r2, [r3]
    ldr r0, lbl_08073be0 @ =gUnk_3000c20
    strb r2, [r0]
lbl_08073bc0:
    ldrb r0, [r3]
    cmp r0, #5
    bls lbl_08073bc8
    b lbl_08073ccc
lbl_08073bc8:
    lsls r0, r0, #2
    ldr r1, lbl_08073be4 @ =lbl_08073be8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073bd4: .4byte gDisableSoftreset
lbl_08073bd8: .4byte gSramOperationStage
lbl_08073bdc: .4byte gHasSaved
lbl_08073be0: .4byte gUnk_3000c20
lbl_08073be4: .4byte lbl_08073be8
lbl_08073be8: @ jump table
    .4byte lbl_08073c00 @ case 0
    .4byte lbl_08073c18 @ case 1
    .4byte lbl_08073c34 @ case 2
    .4byte lbl_08073c50 @ case 3
    .4byte lbl_08073c84 @ case 4
    .4byte lbl_08073ccc @ case 5
lbl_08073c00:
    movs r0, #4
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r1, lbl_08073c14 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c14: .4byte gSramOperationStage
lbl_08073c18:
    bl write_sram_arrays
    ldr r1, lbl_08073c2c @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c30 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c2c: .4byte gUnk_3000c20
lbl_08073c30: .4byte gSramOperationStage
lbl_08073c34:
    bl write_sram
    ldr r1, lbl_08073c48 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c4c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c48: .4byte gUnk_3000c20
lbl_08073c4c: .4byte gSramOperationStage
lbl_08073c50:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r2, lbl_08073c78 @ =gSaveFilesInfo
    ldr r0, lbl_08073c7c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_08073c80 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c78: .4byte gSaveFilesInfo
lbl_08073c7c: .4byte gMostRecentSaveFile
lbl_08073c80: .4byte gSramOperationStage
lbl_08073c84:
    ldr r2, lbl_08073cbc @ =0x08754bc8
    ldr r0, lbl_08073cc0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073cc4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_08073cc8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073cbc: .4byte 0x08754bc8
lbl_08073cc0: .4byte gMostRecentSaveFile
lbl_08073cc4: .4byte 0x000036e0
lbl_08073cc8: .4byte gSramOperationStage
lbl_08073ccc:
    ldr r1, lbl_08073ce0 @ =gDisableSoftreset
    movs r0, #0
lbl_08073cd0:
    strb r0, [r1]
lbl_08073cd2:
    ldr r0, lbl_08073ce0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r1}
    bx r1
    .align 2, 0
lbl_08073ce0: .4byte gDisableSoftreset

    thumb_func_start write_sram
write_sram: @ 0x08073ce4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r3, lbl_08073f80 @ =gMusicInfo
    ldrh r1, [r3, #0x1c]
    ldr r0, lbl_08073f84 @ =0xffff0000
    ands r0, r5
    orrs r0, r1
    ldrh r1, [r3, #0x1e]
    lsls r1, r1, #0x10
    ldr r2, lbl_08073f88 @ =0x0000ffff
    ands r0, r2
    adds r5, r0, #0
    orrs r5, r1
    adds r0, r3, #0
    adds r0, #0x20
    ldrb r1, [r0]
    ldr r0, lbl_08073f8c @ =0xffffff00
    ands r0, r6
    orrs r0, r1
    adds r3, #0x21
    ldrb r1, [r3]
    lsls r1, r1, #8
    ldr r2, lbl_08073f90 @ =0xffff00ff
    ands r0, r2
    adds r6, r0, #0
    orrs r6, r1
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08073f9c @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_08073fa0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073fa4 @ =gGameCompletion
    ldr r0, [r0]
    str r0, [r4, #0x18]
    ldr r0, lbl_08073fa8 @ =gHasSaved
    ldrb r0, [r0]
    strb r0, [r4, #0x1c]
    ldr r0, lbl_08073fac @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r4, #0x1d]
    ldr r0, lbl_08073fb0 @ =gCurrentRoom
    ldrb r0, [r0]
    strb r0, [r4, #0x1e]
    ldr r0, lbl_08073fb4 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #0x1f]
    ldr r0, lbl_08073fb8 @ =gMinimapX
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x20
    strb r1, [r0]
    ldr r0, lbl_08073fbc @ =gMinimapY
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x21
    strb r0, [r1]
    ldr r0, lbl_08073fc0 @ =gCamera
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r0, lbl_08073fc4 @ =gBG0XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2c]
    ldr r0, lbl_08073fc8 @ =gBG0YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2e]
    ldr r0, lbl_08073fcc @ =gBG1XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x30]
    ldr r0, lbl_08073fd0 @ =gBG1YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x32]
    ldr r0, lbl_08073fd4 @ =gBG2XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x34]
    ldr r0, lbl_08073fd8 @ =gBG2YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x36]
    ldr r0, lbl_08073fdc @ =gBG3XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x38]
    ldr r0, lbl_08073fe0 @ =gBG3YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x3a]
    ldr r0, lbl_08073fe4 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_08073fe8 @ =gUseMotherShipDoors
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3d
    strb r0, [r1]
    ldr r0, lbl_08073fec @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, #1
    strb r0, [r1]
    movs r3, #0
    adds r2, r4, #0
    adds r2, #0x3f
    ldr r7, lbl_08073ff0 @ =gNumberOfNeverReformBlocks
lbl_08073de4:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073de4
    movs r3, #0
    ldr r0, lbl_08073ff4 @ =gSamusData
    mov sl, r0
    movs r2, #0x60
    adds r2, r2, r4
    mov ip, r2
    movs r7, #0x80
    adds r7, r7, r4
    mov r8, r7
    movs r0, #0x88
    adds r0, r0, r4
    mov sb, r0
    adds r2, r4, #0
    adds r2, #0x47
    ldr r7, lbl_08073ff8 @ =gNumberOfItemsCollected
lbl_08073e10:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073e10
    mov r1, ip
    mov r0, sl
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r7, lbl_08073ffc @ =gSamusWeaponInfo
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r2, r8
    str r0, [r2]
    str r1, [r2, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sb
    ldr r1, lbl_08074000 @ =gSamusEcho
    bl memcpy
    movs r3, #0xca
    lsls r3, r3, #1
    adds r2, r4, r3
    ldr r0, lbl_08074004 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r7, #0xce
    lsls r7, r7, #1
    adds r1, r4, r7
    ldr r0, lbl_08074008 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    movs r7, #0xd8
    lsls r7, r7, #1
    adds r2, r4, r7
    ldr r0, lbl_0807400c @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r0, #0xdc
    lsls r0, r0, #1
    adds r1, r4, r0
    ldr r0, lbl_08074010 @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xe2
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r3, #0xe8
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r7, #0xee
    lsls r7, r7, #1
    adds r1, r4, r7
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xf4
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldr r0, lbl_08074014 @ =gPreventMovementTimer
    ldrh r1, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r4, r3
    strh r1, [r0]
    ldr r0, lbl_08074018 @ =gDisableDrawingSamusAndScrolling
    ldrb r0, [r0]
    movs r7, #0xfb
    lsls r7, r7, #1
    adds r1, r4, r7
    strb r0, [r1]
    ldr r0, lbl_0807401c @ =gAlarmTimer
    ldrh r1, [r0]
    movs r2, #0xfc
    lsls r2, r2, #1
    adds r0, r4, r2
    strh r1, [r0]
    adds r3, #8
    adds r1, r4, r3
    ldr r0, lbl_08074020 @ =gInGameTimer
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, lbl_08074024 @ =gBestCompletionTimes
    adds r7, #0xa
    adds r1, r4, r7
    movs r3, #0xb
lbl_08073ee0:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ee0
    ldr r1, lbl_08074028 @ =0x08411430
    ldr r7, lbl_0807402c @ =gInGameTimerAtBosses
    movs r0, #0x8c
    lsls r0, r0, #2
    adds r2, r4, r0
    movs r3, #4
lbl_08073ef6:
    ldm r7!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ef6
    movs r2, #0x91
    lsls r2, r2, #2
    adds r0, r4, r2
    str r5, [r0]
    str r6, [r0, #4]
    ldr r5, lbl_08074030 @ =gInGameCutscenesTriggered
    movs r3, #0x93
    lsls r3, r3, #2
    adds r2, r4, r3
    movs r3, #0
lbl_08073f14:
    ldm r5!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f14
    movs r7, #0x94
    lsls r7, r7, #2
    adds r0, r4, r7
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073f46:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f46
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073f80: .4byte gMusicInfo
lbl_08073f84: .4byte 0xffff0000
lbl_08073f88: .4byte 0x0000ffff
lbl_08073f8c: .4byte 0xffffff00
lbl_08073f90: .4byte 0xffff00ff
lbl_08073f94: .4byte 0x08754bc8
lbl_08073f98: .4byte gMostRecentSaveFile
lbl_08073f9c: .4byte 0x08411410
lbl_08073fa0: .4byte 0x08411420
lbl_08073fa4: .4byte gGameCompletion
lbl_08073fa8: .4byte gHasSaved
lbl_08073fac: .4byte gCurrentArea
lbl_08073fb0: .4byte gCurrentRoom
lbl_08073fb4: .4byte gLastDoorUsed
lbl_08073fb8: .4byte gMinimapX
lbl_08073fbc: .4byte gMinimapY
lbl_08073fc0: .4byte gCamera
lbl_08073fc4: .4byte gBG0XPosition
lbl_08073fc8: .4byte gBG0YPosition
lbl_08073fcc: .4byte gBG1XPosition
lbl_08073fd0: .4byte gBG1YPosition
lbl_08073fd4: .4byte gBG2XPosition
lbl_08073fd8: .4byte gBG2YPosition
lbl_08073fdc: .4byte gBG3XPosition
lbl_08073fe0: .4byte gBG3YPosition
lbl_08073fe4: .4byte gDifficulty
lbl_08073fe8: .4byte gUseMotherShipDoors
lbl_08073fec: .4byte gTimeAttackFlag
lbl_08073ff0: .4byte gNumberOfNeverReformBlocks
lbl_08073ff4: .4byte gSamusData
lbl_08073ff8: .4byte gNumberOfItemsCollected
lbl_08073ffc: .4byte gSamusWeaponInfo
lbl_08074000: .4byte gSamusEcho
lbl_08074004: .4byte gScrewSpeedAnimation
lbl_08074008: .4byte gEquipment
lbl_0807400c: .4byte gSamusHazardDamage
lbl_08074010: .4byte gSamusEnvironmentalEffects
lbl_08074014: .4byte gPreventMovementTimer
lbl_08074018: .4byte gDisableDrawingSamusAndScrolling
lbl_0807401c: .4byte gAlarmTimer
lbl_08074020: .4byte gInGameTimer
lbl_08074024: .4byte gBestCompletionTimes
lbl_08074028: .4byte 0x08411430
lbl_0807402c: .4byte gInGameTimerAtBosses
lbl_08074030: .4byte gInGameCutscenesTriggered

    thumb_func_start load_sram_data
load_sram_data: @ 0x08074034
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r2, lbl_08074248 @ =0x08754bc8
    ldr r0, lbl_0807424c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08074250 @ =gGameCompletion
    ldr r0, [r4, #0x18]
    str r0, [r1]
    ldr r1, lbl_08074254 @ =gHasSaved
    ldrb r0, [r4, #0x1c]
    strb r0, [r1]
    ldr r1, lbl_08074258 @ =gCurrentArea
    ldrb r0, [r4, #0x1d]
    strb r0, [r1]
    ldr r1, lbl_0807425c @ =gCurrentRoom
    ldrb r0, [r4, #0x1e]
    strb r0, [r1]
    ldr r1, lbl_08074260 @ =gLastDoorUsed
    ldrb r0, [r4, #0x1f]
    strb r0, [r1]
    ldr r1, lbl_08074264 @ =gMinimapX
    adds r0, r4, #0
    adds r0, #0x20
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074268 @ =gMinimapY
    adds r0, r4, #0
    adds r0, #0x21
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r2, lbl_0807426c @ =gCamera
    ldr r0, [r4, #0x24]
    ldr r1, [r4, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08074270 @ =gBG0XPosition
    ldrh r0, [r4, #0x2c]
    strh r0, [r1]
    ldr r1, lbl_08074274 @ =gBG0YPosition
    ldrh r0, [r4, #0x2e]
    strh r0, [r1]
    ldr r1, lbl_08074278 @ =gBG1XPosition
    ldrh r0, [r4, #0x30]
    strh r0, [r1]
    ldr r1, lbl_0807427c @ =gBG1YPosition
    ldrh r0, [r4, #0x32]
    strh r0, [r1]
    ldr r1, lbl_08074280 @ =gBG2XPosition
    ldrh r0, [r4, #0x34]
    strh r0, [r1]
    ldr r1, lbl_08074284 @ =gBG2YPosition
    ldrh r0, [r4, #0x36]
    strh r0, [r1]
    ldr r1, lbl_08074288 @ =gBG3XPosition
    ldrh r0, [r4, #0x38]
    strh r0, [r1]
    ldr r1, lbl_0807428c @ =gBG3YPosition
    ldrh r0, [r4, #0x3a]
    strh r0, [r1]
    ldr r1, lbl_08074290 @ =gDifficulty
    adds r0, r4, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074294 @ =gUseMotherShipDoors
    adds r0, r4, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074298 @ =gTimeAttackFlag
    adds r0, r4, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    strb r0, [r1]
    movs r2, #0
    ldr r0, lbl_0807429c @ =gSamusData
    mov r8, r0
    ldr r1, lbl_080742a0 @ =gSamusWeaponInfo
    mov sb, r1
    ldr r3, lbl_080742a4 @ =gSamusEcho
    mov sl, r3
    ldr r5, lbl_080742a8 @ =gNumberOfNeverReformBlocks
    adds r3, r4, #0
    adds r3, #0x3f
lbl_080740f4:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_080740f4
    movs r2, #0
    adds r6, r4, #0
    adds r6, #0x60
    adds r7, r4, #0
    adds r7, #0x80
    movs r5, #0x88
    adds r5, r5, r4
    mov ip, r5
    ldr r5, lbl_080742ac @ =gNumberOfItemsCollected
    adds r3, r4, #0
    adds r3, #0x47
lbl_08074118:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_08074118
    mov r1, r8
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r5, sb
    str r0, [r5]
    str r1, [r5, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sl
    mov r1, ip
    bl memcpy
    ldr r2, lbl_080742b0 @ =gScrewSpeedAnimation
    movs r1, #0xca
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_080742b4 @ =gEquipment
    movs r2, #0xce
    lsls r2, r2, #1
    adds r0, r4, r2
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    ldr r2, lbl_080742b8 @ =gSamusHazardDamage
    movs r1, #0xd8
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_080742bc @ =gSamusEnvironmentalEffects
    movs r2, #0xdc
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xe2
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r5, #0xe8
    lsls r5, r5, #1
    adds r1, r4, r5
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r2, #0xee
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xf4
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, lbl_080742c0 @ =gPreventMovementTimer
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r4, r5
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742c4 @ =gDisableDrawingSamusAndScrolling
    movs r2, #0xfb
    lsls r2, r2, #1
    adds r0, r4, r2
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_080742c8 @ =gAlarmTimer
    movs r3, #0xfc
    lsls r3, r3, #1
    adds r0, r4, r3
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742cc @ =gInGameTimer
    adds r5, #8
    adds r0, r4, r5
    ldr r0, [r0]
    str r0, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742d0 @ =gBestCompletionTimes
    movs r2, #0xb
lbl_080741e8:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741e8
    ldr r7, lbl_080742d4 @ =gMusicInfo
    movs r2, #0x8c
    lsls r2, r2, #2
    adds r1, r4, r2
    ldr r3, lbl_080742d8 @ =gInGameTimerAtBosses
    movs r2, #4
lbl_080741fe:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741fe
    movs r3, #0x91
    lsls r3, r3, #2
    adds r0, r4, r3
    ldr r5, [r0]
    ldr r6, [r0, #4]
    movs r0, #0x93
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742dc @ =gInGameCutscenesTriggered
    movs r2, #0
lbl_0807421c:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_0807421c
    strh r5, [r7, #0x1c]
    lsrs r0, r5, #0x10
    strh r0, [r7, #0x1e]
    adds r0, r7, #0
    adds r0, #0x20
    strb r6, [r0]
    lsrs r1, r6, #8
    adds r0, #1
    strb r1, [r0]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074248: .4byte 0x08754bc8
lbl_0807424c: .4byte gMostRecentSaveFile
lbl_08074250: .4byte gGameCompletion
lbl_08074254: .4byte gHasSaved
lbl_08074258: .4byte gCurrentArea
lbl_0807425c: .4byte gCurrentRoom
lbl_08074260: .4byte gLastDoorUsed
lbl_08074264: .4byte gMinimapX
lbl_08074268: .4byte gMinimapY
lbl_0807426c: .4byte gCamera
lbl_08074270: .4byte gBG0XPosition
lbl_08074274: .4byte gBG0YPosition
lbl_08074278: .4byte gBG1XPosition
lbl_0807427c: .4byte gBG1YPosition
lbl_08074280: .4byte gBG2XPosition
lbl_08074284: .4byte gBG2YPosition
lbl_08074288: .4byte gBG3XPosition
lbl_0807428c: .4byte gBG3YPosition
lbl_08074290: .4byte gDifficulty
lbl_08074294: .4byte gUseMotherShipDoors
lbl_08074298: .4byte gTimeAttackFlag
lbl_0807429c: .4byte gSamusData
lbl_080742a0: .4byte gSamusWeaponInfo
lbl_080742a4: .4byte gSamusEcho
lbl_080742a8: .4byte gNumberOfNeverReformBlocks
lbl_080742ac: .4byte gNumberOfItemsCollected
lbl_080742b0: .4byte gScrewSpeedAnimation
lbl_080742b4: .4byte gEquipment
lbl_080742b8: .4byte gSamusHazardDamage
lbl_080742bc: .4byte gSamusEnvironmentalEffects
lbl_080742c0: .4byte gPreventMovementTimer
lbl_080742c4: .4byte gDisableDrawingSamusAndScrolling
lbl_080742c8: .4byte gAlarmTimer
lbl_080742cc: .4byte gInGameTimer
lbl_080742d0: .4byte gBestCompletionTimes
lbl_080742d4: .4byte gMusicInfo
lbl_080742d8: .4byte gInGameTimerAtBosses
lbl_080742dc: .4byte gInGameCutscenesTriggered

    thumb_func_start write_string
write_string: @ 0x080742e0
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r3, #0
    cmp r3, r2
    bge lbl_080742fe
lbl_080742f0:
    adds r0, r5, r3
    adds r1, r4, r3
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, r2
    blt lbl_080742f0
lbl_080742fe:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08074304
sub_08074304: @ 0x08074304
    push {r4, r5, lr}
    sub sp, #0x10
    movs r5, #0
    ldr r0, lbl_08074364 @ =gSramCorruptFlag
    strb r5, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    ldr r4, lbl_0807436c @ =0x0e007f80
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
lbl_0807432c:
    mov r0, sp
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r2, #1
    cmp r2, #0xf
    ble lbl_0807432c
    ldr r4, lbl_0807436c @ =0x0e007f80
    mov r0, sp
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    cmp r0, #0
    beq lbl_08074350
    movs r0, #2
    orrs r5, r0
lbl_08074350:
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
    mov r0, sp
    ldrb r1, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    b lbl_08074380
    .align 2, 0
lbl_08074364: .4byte gSramCorruptFlag
lbl_08074368: .4byte 0x08411400
lbl_0807436c: .4byte 0x0e007f80
lbl_08074370:
    adds r2, #1
    cmp r2, #0xf
    bgt lbl_0807438c
    mov r1, sp
    adds r0, r1, r2
    ldrb r1, [r0]
    ldr r0, lbl_0807439c @ =0x08411400
    adds r0, r2, r0
lbl_08074380:
    ldrb r0, [r0]
    adds r0, #1
    cmp r1, r0
    beq lbl_08074370
    movs r0, #4
    orrs r5, r0
lbl_0807438c:
    cmp r5, #0
    beq lbl_08074394
    ldr r0, lbl_080743a0 @ =gSramCorruptFlag
    strb r5, [r0]
lbl_08074394:
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807439c: .4byte 0x08411400
lbl_080743a0: .4byte gSramCorruptFlag

    thumb_func_start sub_080743a4
sub_080743a4: @ 0x080743a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08074440 @ =gMostRecentSaveFile
    mov r8, r0
    ldr r1, lbl_08074444 @ =gIsLoadingFile
    mov sb, r1
    ldr r3, lbl_08074448 @ =0x08760408
    ldr r2, lbl_0807444c @ =gSaveFilesInfo
    movs r5, #2
lbl_080743be:
    adds r1, r2, #0
    adds r0, r3, #0
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    adds r2, #0x18
    subs r5, #1
    cmp r5, #0
    bge lbl_080743be
    movs r0, #0
    mov r1, r8
    strb r0, [r1]
    mov r2, sb
    strb r0, [r2]
    movs r5, #0
    ldr r7, lbl_08074450 @ =0x08754bc8
    movs r6, #0x10
    ldr r3, lbl_0807444c @ =gSaveFilesInfo
    str r3, [sp, #4]
    ldr r4, lbl_08074454 @ =0x0000ffff
    mov sl, r4
    movs r0, #0x91
    lsls r0, r0, #5
    mov sb, r0
lbl_080743f0:
    mov r1, r8
    strb r5, [r1]
    bl sub_08074574
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r3, lbl_0807444c @ =gSaveFilesInfo
    adds r0, r0, r3
    ldrb r4, [r0, #1]
    cmp r4, #0
    bne lbl_0807445c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r7]
    adds r1, r2, r1
    ldr r4, lbl_08074458 @ =0x000036e0
    adds r0, r0, r4
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DMATransfer
    movs r0, #4
    bl DoSramOperation
    movs r0, #1
    ldr r1, [sp, #4]
    strb r0, [r1]
    b lbl_0807454a
    .align 2, 0
lbl_08074440: .4byte gMostRecentSaveFile
lbl_08074444: .4byte gIsLoadingFile
lbl_08074448: .4byte 0x08760408
lbl_0807444c: .4byte gSaveFilesInfo
lbl_08074450: .4byte 0x08754bc8
lbl_08074454: .4byte 0x0000ffff
lbl_08074458: .4byte 0x000036e0
lbl_0807445c:
    cmp r4, #1
    bne lbl_0807448c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r2, lbl_08074488 @ =0x000036e0
    adds r1, r0, r2
    ldr r2, [r7]
    adds r1, r2, r1
    adds r0, #0x80
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DMATransfer
    ldr r3, [sp, #4]
    strb r4, [r3]
    b lbl_0807454a
    .align 2, 0
lbl_08074488: .4byte 0x000036e0
lbl_0807448c:
    cmp r4, #2
    bne lbl_080744d8
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080744d4 @ =0x000036e0
    adds r0, r0, r1
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    b lbl_0807454a
    .align 2, 0
lbl_080744d4: .4byte 0x000036e0
lbl_080744d8:
    cmp r4, #2
    bls lbl_08074548
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #3
    bl DoSramOperation
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r3, lbl_08074540 @ =0x000036e0
    adds r0, r0, r3
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #4
    bl DoSramOperation
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r1, lbl_08074544 @ =gSaveFilesInfo
    adds r0, r0, r1
    movs r1, #0
    strb r1, [r0, #1]
    b lbl_0807454a
    .align 2, 0
lbl_08074540: .4byte 0x000036e0
lbl_08074544: .4byte gSaveFilesInfo
lbl_08074548:
    b lbl_08074548
lbl_0807454a:
    ldr r2, [sp, #4]
    adds r2, #0x18
    str r2, [sp, #4]
    adds r5, #1
    cmp r5, #2
    bgt lbl_08074558
    b lbl_080743f0
lbl_08074558:
    movs r1, #0
    ldr r0, lbl_08074570 @ =gMostRecentSaveFile
    strb r1, [r0]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074570: .4byte gMostRecentSaveFile

    thumb_func_start sub_08074574
sub_08074574: @ 0x08074574
    push {r4, r5, lr}
    movs r0, #0
    bl sub_08074624
    adds r4, r0, #0
    movs r0, #1
    bl sub_08074624
    adds r2, r0, #0
    cmp r4, #0
    bne lbl_080745a8
    ldr r2, lbl_080745a0 @ =gSaveFilesInfo
    ldr r0, lbl_080745a4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    strb r4, [r0, #1]
    b lbl_0807461c
    .align 2, 0
lbl_080745a0: .4byte gSaveFilesInfo
lbl_080745a4: .4byte gMostRecentSaveFile
lbl_080745a8:
    cmp r4, #1
    bne lbl_080745d8
    ldr r5, lbl_080745d0 @ =gSaveFilesInfo
    ldr r3, lbl_080745d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r5
    strb r4, [r0, #1]
    cmp r2, #0
    beq lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r5
    b lbl_08074618
    .align 2, 0
lbl_080745d0: .4byte gSaveFilesInfo
lbl_080745d4: .4byte gMostRecentSaveFile
lbl_080745d8:
    ldr r4, lbl_08074600 @ =gSaveFilesInfo
    ldr r3, lbl_08074604 @ =gMostRecentSaveFile
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #3
    strb r0, [r1, #1]
    cmp r2, #0
    bne lbl_08074608
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #1
    b lbl_0807461a
    .align 2, 0
lbl_08074600: .4byte gSaveFilesInfo
lbl_08074604: .4byte gMostRecentSaveFile
lbl_08074608:
    cmp r2, #1
    bne lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
lbl_08074618:
    movs r0, #2
lbl_0807461a:
    strb r0, [r1, #1]
lbl_0807461c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08074624
sub_08074624: @ 0x08074624
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08074654
    ldr r2, lbl_0807464c @ =0x08754bc8
    ldr r0, lbl_08074650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    b lbl_0807466a
    .align 2, 0
lbl_0807464c: .4byte 0x08754bc8
lbl_08074650: .4byte gMostRecentSaveFile
lbl_08074654:
    ldr r2, lbl_080746d8 @ =0x08754bc8
    ldr r0, lbl_080746dc @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080746e0 @ =0x000036e0
    adds r0, r0, r1
lbl_0807466a:
    ldr r1, [r2]
    adds r4, r1, r0
    adds r1, r4, #0
    movs r2, #0
    ldr r6, [r4, #0x10]
    mov ip, r6
    ldr r7, lbl_080746e4 @ =0x08411410
    ldrb r0, [r4]
    mov sb, r0
    ldr r6, lbl_080746e8 @ =0x08411420
    mov r8, r6
    adds r6, r4, #0
    adds r6, #0x4f
    ldr r0, lbl_080746ec @ =0x08411430
    mov sl, r0
    movs r0, #0x94
    lsls r0, r0, #2
    adds r0, r4, r0
    str r0, [sp, #4]
    movs r3, #0x90
lbl_08074692:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08074692
    movs r5, #0
    cmp ip, r2
    bne lbl_080746c6
    ldr r0, [r4, #0x14]
    mvns r0, r0
    cmp r2, r0
    beq lbl_080746c8
lbl_080746c6:
    movs r5, #1
lbl_080746c8:
    movs r2, #0
    movs r3, #0
    ldrb r0, [r7]
    cmp r0, sb
    beq lbl_080746f0
    movs r2, #1
    b lbl_08074706
    .align 2, 0
lbl_080746d8: .4byte 0x08754bc8
lbl_080746dc: .4byte gMostRecentSaveFile
lbl_080746e0: .4byte 0x000036e0
lbl_080746e4: .4byte 0x08411410
lbl_080746e8: .4byte 0x08411420
lbl_080746ec: .4byte 0x08411430
lbl_080746f0:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074706
    adds r0, r3, r7
    adds r1, r4, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080746f0
    movs r0, #1
    orrs r2, r0
lbl_08074706:
    movs r3, #0
    mov r1, r8
    ldrb r0, [r1]
    ldrb r1, [r6]
    b lbl_08074720
lbl_08074710:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074728
    mov r1, r8
    adds r0, r3, r1
    adds r1, r6, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
lbl_08074720:
    cmp r0, r1
    beq lbl_08074710
    movs r0, #2
    orrs r2, r0
lbl_08074728:
    movs r3, #0
    mov r6, sl
    ldrb r0, [r6]
    ldr r1, [sp, #4]
    b lbl_08074746
lbl_08074732:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074750
    mov r6, sl
    adds r0, r3, r6
    movs r6, #0x94
    lsls r6, r6, #2
    adds r1, r4, r6
    adds r1, r1, r3
    ldrb r0, [r0]
lbl_08074746:
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074732
    movs r0, #4
    orrs r2, r0
lbl_08074750:
    cmp r2, #0
    beq lbl_08074760
    cmp r2, #7
    bne lbl_0807475c
    movs r0, #2
    b lbl_0807475e
lbl_0807475c:
    movs r0, #1
lbl_0807475e:
    orrs r5, r0
lbl_08074760:
    cmp r5, #1
    ble lbl_08074776
    ldr r1, lbl_08074788 @ =0x0000ffff
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
lbl_08074776:
    adds r0, r5, #0
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074788: .4byte 0x0000ffff

    thumb_func_start sub_0807478c
sub_0807478c: @ 0x0807478c
    push {lr}
    ldr r0, lbl_080747a8 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_080747a2
    bl load_sram_data
    bl load_sram_arrays
lbl_080747a2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080747a8: .4byte gIsLoadingFile

    thumb_func_start sub_080747ac
sub_080747ac: @ 0x080747ac
    push {lr}
    bl load_sram_data
    bl load_sram_arrays
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start write_sram_arrays
write_sram_arrays: @ 0x080747bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_08074898 @ =0x08754bc8
    ldr r0, lbl_0807489c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r1, lbl_080748a0 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r2, r8
    bl DMATransfer
    ldr r1, lbl_080748a4 @ =0x02037c00
    movs r0, #0x88
    lsls r0, r0, #5
    adds r2, r4, r0
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_080748a8 @ =0x02037e00
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    str r5, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0x20
    bl DMATransfer
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748ac @ =0x02035c00
lbl_08074824:
    ldr r0, lbl_080748b0 @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08074848
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r6, r6, r4
lbl_08074848:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074824
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748b4 @ =0x02036c00
lbl_0807485a:
    ldr r0, lbl_080748b8 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_0807487e
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r6, r6, r4
lbl_0807487e:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807485a
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074898: .4byte 0x08754bc8
lbl_0807489c: .4byte gMostRecentSaveFile
lbl_080748a0: .4byte 0x02037400
lbl_080748a4: .4byte 0x02037c00
lbl_080748a8: .4byte 0x02037e00
lbl_080748ac: .4byte 0x02035c00
lbl_080748b0: .4byte gNumberOfNeverReformBlocks
lbl_080748b4: .4byte 0x02036c00
lbl_080748b8: .4byte gNumberOfItemsCollected

    thumb_func_start load_sram_arrays
load_sram_arrays: @ 0x080748bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_080749bc @ =0x08754bc8
    ldr r0, lbl_080749c0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r2, lbl_080749c4 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r1, r8
    bl DMATransfer
    movs r0, #0x88
    lsls r0, r0, #5
    adds r1, r4, r0
    ldr r2, lbl_080749c8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    ldr r2, lbl_080749cc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    movs r3, #0x20
    bl DMATransfer
    ldr r4, lbl_080749d0 @ =0x0000ffff
    ldr r6, lbl_080749d4 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r2, r6, #0
    bl BitFill
    ldr r2, lbl_080749d8 @ =0x02036c00
    movs r3, #0x80
    lsls r3, r3, #4
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    movs r7, #0
    movs r5, #0
lbl_08074946:
    ldr r0, lbl_080749dc @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807496a
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r7, r7, r4
lbl_0807496a:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074946
    movs r7, #0
    movs r5, #0
    ldr r6, lbl_080749d8 @ =0x02036c00
lbl_0807497c:
    ldr r0, lbl_080749e0 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_080749a0
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r7, r7, r4
lbl_080749a0:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807497c
    bl load_minimap_tiles_with_obtained_items
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080749bc: .4byte 0x08754bc8
lbl_080749c0: .4byte gMostRecentSaveFile
lbl_080749c4: .4byte 0x02037400
lbl_080749c8: .4byte 0x02037c00
lbl_080749cc: .4byte 0x02037e00
lbl_080749d0: .4byte 0x0000ffff
lbl_080749d4: .4byte 0x02035c00
lbl_080749d8: .4byte 0x02036c00
lbl_080749dc: .4byte gNumberOfNeverReformBlocks
lbl_080749e0: .4byte gNumberOfItemsCollected

    thumb_func_start sub_080749e4
sub_080749e4: @ 0x080749e4
    push {r4, r5, lr}
    ldr r0, lbl_08074a68 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdb
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1e
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074a6c @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074a70 @ =gMostRecentSaveFile
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074a74 @ =0x08411488
    ldr r0, lbl_08074a78 @ =0x00006d86
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074a12:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a12
    movs r1, #0
    movs r4, #7
lbl_08074a28:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a28
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #5
    bl DoSramOperation
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074a68: .4byte 0x08754bc8
lbl_08074a6c: .4byte 0x0000ffff
lbl_08074a70: .4byte gMostRecentSaveFile
lbl_08074a74: .4byte 0x08411488
lbl_08074a78: .4byte 0x00006d86

    thumb_func_start sub_08074a7c
sub_08074a7c: @ 0x08074a7c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074b28 @ =0x08754bc8
    ldr r0, [r2]
    movs r1, #0xdb
    lsls r1, r1, #7
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1e
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074b2c @ =gMostRecentSaveFile
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074aa8:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074aa8
    cmp r5, r2
    beq lbl_08074adc
    movs r4, #2
lbl_08074adc:
    cmp r4, #0
    bne lbl_08074b34
    movs r3, #0
    ldr r0, lbl_08074b30 @ =0x08411488
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074b34
lbl_08074af0:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074b34
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074b1c
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074af0
    movs r4, #3
lbl_08074b1c:
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074b54
    .align 2, 0
lbl_08074b28: .4byte 0x08754bc8
lbl_08074b2c: .4byte gMostRecentSaveFile
lbl_08074b30: .4byte 0x08411488
lbl_08074b34:
    mov r1, sp
    ldr r2, lbl_08074b60 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074b64 @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    movs r2, #0xdb
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074b68 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074b54:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074b60: .4byte 0x0000ffff
lbl_08074b64: .4byte 0x040000d4
lbl_08074b68: .4byte 0x81000020

    thumb_func_start sub_08074b6c
sub_08074b6c: @ 0x08074b6c
    push {r4, r5, lr}
    ldr r0, lbl_08074bf0 @ =0x08754bc8
    ldr r2, [r0]
    ldr r0, lbl_08074bf4 @ =0x00006e40
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074bf8 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074bfc @ =gStereoFlag
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074c00 @ =0x084114a8
    ldr r0, lbl_08074c04 @ =0x00006e46
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074b98:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074b98
    movs r1, #0
    movs r4, #7
lbl_08074bae:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074bae
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #8
    bl DoSramOperation
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074bf0: .4byte 0x08754bc8
lbl_08074bf4: .4byte 0x00006e40
lbl_08074bf8: .4byte 0x0000ffff
lbl_08074bfc: .4byte gStereoFlag
lbl_08074c00: .4byte 0x084114a8
lbl_08074c04: .4byte 0x00006e46

    thumb_func_start sub_08074c08
sub_08074c08: @ 0x08074c08
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074cb0 @ =0x08754bc8
    ldr r0, [r2]
    ldr r1, lbl_08074cb4 @ =0x00006e40
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074cb8 @ =gStereoFlag
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074c32:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074c32
    cmp r5, r2
    beq lbl_08074c66
    movs r4, #2
lbl_08074c66:
    cmp r4, #0
    bne lbl_08074cc0
    movs r3, #0
    ldr r0, lbl_08074cbc @ =0x084114a8
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074cc0
lbl_08074c7a:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074cc0
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074ca6
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074c7a
    movs r4, #3
lbl_08074ca6:
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074cde
    .align 2, 0
lbl_08074cb0: .4byte 0x08754bc8
lbl_08074cb4: .4byte 0x00006e40
lbl_08074cb8: .4byte gStereoFlag
lbl_08074cbc: .4byte 0x084114a8
lbl_08074cc0:
    mov r1, sp
    ldr r2, lbl_08074ce8 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074cec @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    ldr r2, lbl_08074cf0 @ =0x00006e40
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074cf4 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074cde:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ce8: .4byte 0x0000ffff
lbl_08074cec: .4byte 0x040000d4
lbl_08074cf0: .4byte 0x00006e40
lbl_08074cf4: .4byte 0x81000020

    thumb_func_start SramWrite_Language
SramWrite_Language: @ 0x08074cf8
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074d88 @ =0x08754bc8
    ldr r4, [r0]
    ldr r0, lbl_08074d8c @ =0x00006dc0
    adds r5, r4, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074d90 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074d94 @ =gLanguage
    movs r2, #0
    ldrsb r2, [r0, r2]
    cmp r2, #6
    bls lbl_08074d22
    movs r2, #2
lbl_08074d22:
    strb r2, [r5, #0x16]
    movs r2, #0
    ldr r1, lbl_08074d98 @ =0x00006dc6
    adds r7, r4, r1
    ldr r0, lbl_08074d9c @ =0x00006dd7
    adds r6, r4, r0
    ldr r4, lbl_08074da0 @ =0x084114c8
lbl_08074d30:
    adds r1, r7, r2
    ldrb r0, [r4]
    strb r0, [r1]
    adds r1, r6, r2
    ldrb r0, [r4, #0x10]
    strb r0, [r1]
    adds r4, #1
    adds r2, #1
    cmp r2, #0xf
    ble lbl_08074d30
    movs r1, #0
    movs r2, #7
lbl_08074d48:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bge lbl_08074d48
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #6
    bl DoSramOperation
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074d88: .4byte 0x08754bc8
lbl_08074d8c: .4byte 0x00006dc0
lbl_08074d90: .4byte 0x0000ffff
lbl_08074d94: .4byte gLanguage
lbl_08074d98: .4byte 0x00006dc6
lbl_08074d9c: .4byte 0x00006dd7
lbl_08074da0: .4byte 0x084114c8

    thumb_func_start sub_08074da4
sub_08074da4: @ 0x08074da4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08074e2c @ =0x08754bc8
    mov sb, r1
    ldr r6, lbl_08074e30 @ =0x040000d4
    ldr r2, lbl_08074e34 @ =0x81000020
    mov sl, r2
lbl_08074dbe:
    mov r1, r8
    lsls r0, r1, #6
    ldr r2, lbl_08074e38 @ =0x00006dc0
    adds r0, r0, r2
    mov r2, sb
    ldr r1, [r2]
    adds r5, r1, r0
    adds r2, r5, #0
    ldrb r1, [r5]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    cmp r4, #0
    bne lbl_08074e6e
    movs r1, #0
    ldrh r7, [r5, #2]
    movs r3, #7
lbl_08074de4:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074de4
    cmp r7, r1
    beq lbl_08074e18
    movs r4, #2
lbl_08074e18:
    cmp r4, #0
    bne lbl_08074e6e
    movs r3, #0
    ldr r0, lbl_08074e3c @ =0x084114c8
    ldrb r1, [r5, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    beq lbl_08074e44
    b lbl_08074e6c
    .align 2, 0
lbl_08074e2c: .4byte 0x08754bc8
lbl_08074e30: .4byte 0x040000d4
lbl_08074e34: .4byte 0x81000020
lbl_08074e38: .4byte 0x00006dc0
lbl_08074e3c: .4byte 0x084114c8
lbl_08074e40:
    movs r4, #4
    b lbl_08074e6e
lbl_08074e44:
    adds r0, r5, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074e40
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074e6e
    adds r0, r5, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074e44
lbl_08074e6c:
    movs r4, #3
lbl_08074e6e:
    mov r1, r8
    cmp r1, #0
    bne lbl_08074ea0
    cmp r4, #0
    bne lbl_08074ee2
    mov r2, sb
    ldr r1, [r2]
    ldr r2, lbl_08074e98 @ =0x00006dc0
    adds r0, r1, r2
    str r0, [r6]
    movs r0, #0xdc
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r6, #4]
    ldr r0, lbl_08074e9c @ =0x80000020
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl DoSramOperation
    b lbl_08074eee
    .align 2, 0
lbl_08074e98: .4byte 0x00006dc0
lbl_08074e9c: .4byte 0x80000020
lbl_08074ea0:
    cmp r4, #0
    beq lbl_08074f04
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, lbl_08074efc @ =0x00006dc0
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #6
    bl DoSramOperation
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    movs r1, #0xdc
    lsls r1, r1, #7
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl DoSramOperation
lbl_08074ee2:
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #1
    bgt lbl_08074eee
    b lbl_08074dbe
lbl_08074eee:
    cmp r4, #0
    beq lbl_08074f3c
    ldr r1, lbl_08074f00 @ =gLanguage
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    b lbl_08074f44
    .align 2, 0
lbl_08074efc: .4byte 0x00006dc0
lbl_08074f00: .4byte gLanguage
lbl_08074f04:
    ldr r1, lbl_08074f2c @ =0x040000d4
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    movs r2, #0xdc
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    ldr r2, lbl_08074f34 @ =0x00006dc0
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074f38 @ =0x80000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #6
    bl DoSramOperation
    b lbl_08074eee
    .align 2, 0
lbl_08074f2c: .4byte 0x040000d4
lbl_08074f30: .4byte 0x08754bc8
lbl_08074f34: .4byte 0x00006dc0
lbl_08074f38: .4byte 0x80000020
lbl_08074f3c:
    ldr r1, lbl_08074f54 @ =gLanguage
    ldrb r0, [r5, #0x16]
    strb r0, [r1]
    movs r0, #0
lbl_08074f44:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074f54: .4byte gLanguage

    thumb_func_start backup_time_attack_for_sram
backup_time_attack_for_sram: @ 0x08074f58
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074ff4 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdd
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x40
    strb r0, [r5]
    ldrb r0, [r5, #0x16]
    adds r0, #1
    strb r0, [r5, #0x16]
    strh r1, [r5, #0x12]
    ldr r0, lbl_08074ff8 @ =0x0000ffff
    strh r0, [r5, #0x14]
    ldr r4, lbl_08074ffc @ =0x00006ea8
    adds r1, r2, r4
    ldr r0, lbl_08075000 @ =gTimeAttackRecord
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    movs r4, #0
    ldr r6, lbl_08075004 @ =0x00006e97
    adds r7, r2, r6
    ldr r0, lbl_08075008 @ =0x00006ed8
    adds r6, r2, r0
    ldr r2, lbl_0807500c @ =0x084114e8
lbl_08074f9a:
    adds r1, r7, r4
    ldrb r0, [r2]
    strb r0, [r1]
    adds r1, r6, r4
    ldrb r0, [r2, #0x10]
    strb r0, [r1]
    adds r2, #1
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08074f9a
    movs r1, #0
    movs r4, #0x1f
lbl_08074fb2:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r6, [r3]
    adds r0, r0, r6
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r7, [r3]
    adds r0, r0, r7
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074fb2
    strh r1, [r5, #0x12]
    mvns r0, r1
    strh r0, [r5, #0x14]
    movs r0, #9
    bl DoSramOperation
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ff4: .4byte 0x08754bc8
lbl_08074ff8: .4byte 0x0000ffff
lbl_08074ffc: .4byte 0x00006ea8
lbl_08075000: .4byte gTimeAttackRecord
lbl_08075004: .4byte 0x00006e97
lbl_08075008: .4byte 0x00006ed8
lbl_0807500c: .4byte 0x084114e8

    thumb_func_start sub_08075010
sub_08075010: @ 0x08075010
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08075098 @ =0x08754bc8
    mov sb, r1
    ldr r2, lbl_0807509c @ =0x040000d4
    mov sl, r2
lbl_08075028:
    mov r3, r8
    lsls r0, r3, #8
    movs r4, #0xdd
    lsls r4, r4, #7
    adds r0, r0, r4
    mov r2, sb
    ldr r1, [r2]
    adds r7, r1, r0
    adds r2, r7, #0
    ldrb r1, [r7]
    movs r0, #0x40
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    cmp r6, #0
    bne lbl_080750d4
    movs r1, #0
    ldrh r4, [r7, #0x12]
    movs r3, #0x1f
lbl_08075050:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08075050
    cmp r4, r1
    beq lbl_08075084
    movs r6, #2
lbl_08075084:
    cmp r6, #0
    bne lbl_080750d4
    movs r3, #0
    ldr r0, lbl_080750a0 @ =0x084114e8
    ldrb r1, [r7, #0x17]
    adds r2, r0, #0
    ldrb r4, [r2]
    cmp r1, r4
    beq lbl_080750a8
    b lbl_080750d2
    .align 2, 0
lbl_08075098: .4byte 0x08754bc8
lbl_0807509c: .4byte 0x040000d4
lbl_080750a0: .4byte 0x084114e8
lbl_080750a4:
    movs r6, #4
    b lbl_080750d4
lbl_080750a8:
    adds r0, r7, #0
    adds r0, #0x58
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080750a4
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_080750d4
    adds r0, r7, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080750a8
lbl_080750d2:
    movs r6, #3
lbl_080750d4:
    mov r0, r8
    cmp r0, #0
    bne lbl_08075108
    cmp r6, #0
    bne lbl_0807514a
    mov r2, sb
    ldr r1, [r2]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r1, r3
    mov r4, sl
    str r0, [r4]
    movs r0, #0xdf
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r4, #4]
    ldr r0, lbl_08075104 @ =0x80000080
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    movs r0, #0xa
    bl DoSramOperation
    b lbl_08075156
    .align 2, 0
lbl_08075104: .4byte 0x80000080
lbl_08075108:
    cmp r6, #0
    beq lbl_0807517c
    mov r1, sb
    ldr r2, [r1]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r5, #0x80
    lsls r5, r5, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #9
    bl DoSramOperation
    mov r0, sb
    ldr r2, [r0]
    movs r1, #0xdf
    lsls r1, r1, #7
    adds r2, r2, r1
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #0xa
    bl DoSramOperation
lbl_0807514a:
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #1
    bgt lbl_08075156
    b lbl_08075028
lbl_08075156:
    cmp r6, #0
    bne lbl_080751b0
    ldr r1, lbl_08075178 @ =gTimeAttackRecord
    adds r0, r7, #0
    adds r0, #0x28
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    b lbl_080751c0
    .align 2, 0
lbl_08075174: .4byte 0x0000ffff
lbl_08075178: .4byte gTimeAttackRecord
lbl_0807517c:
    ldr r1, lbl_080751a4 @ =0x040000d4
    ldr r4, lbl_080751a8 @ =0x08754bc8
    ldr r0, [r4]
    movs r2, #0xdf
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r0, [r4]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [r1, #4]
    ldr r0, lbl_080751ac @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #9
    bl DoSramOperation
    b lbl_08075156
    .align 2, 0
lbl_080751a4: .4byte 0x040000d4
lbl_080751a8: .4byte 0x08754bc8
lbl_080751ac: .4byte 0x80000080
lbl_080751b0:
    ldr r1, lbl_080751d0 @ =0x0000ffff
    ldr r2, lbl_080751d4 @ =gTimeAttackRecord
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x30
    bl BitFill
lbl_080751c0:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080751d0: .4byte 0x0000ffff
lbl_080751d4: .4byte gTimeAttackRecord

    thumb_func_start sub_080751d8
sub_080751d8: @ 0x080751d8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r1, lbl_08075314 @ =0x0000ffff
    ldr r4, lbl_08075318 @ =0x0203f800
    movs r3, #0xa0
    lsls r3, r3, #2
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
    ldr r5, lbl_0807531c @ =gCurrentArea
    ldrb r0, [r5]
    strb r0, [r4]
    ldr r0, lbl_08075320 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #1]
    adds r1, r4, #4
    ldr r0, lbl_08075324 @ =gSamusData
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, lbl_08075328 @ =gSamusWeaponInfo
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r1, lbl_0807532c @ =gSamusEcho
    adds r0, r4, #0
    adds r0, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    movs r2, #0x9c
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075330 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xa0
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_08075334 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r7}
    stm r1!, {r2, r7}
    movs r2, #0xaa
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075338 @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xae
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_0807533c @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xb4
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xba
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc0
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc6
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldrb r1, [r5]
    lsls r1, r1, #7
    ldr r3, lbl_08075340 @ =0x02037400
    adds r1, r1, r3
    movs r2, #0xcc
    lsls r2, r2, #1
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    ldrb r1, [r5]
    lsls r1, r1, #5
    ldr r7, lbl_08075344 @ =0x02037c00
    adds r1, r1, r7
    movs r2, #0x86
    lsls r2, r2, #2
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    movs r0, #0x8e
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r1, #0x41
    strb r1, [r0]
    ldr r0, lbl_08075348 @ =0x00000239
    adds r0, r4, r0
    movs r1, #0x54
    strb r1, [r0]
    ldr r0, lbl_0807534c @ =0x0000023a
    adds r0, r4, r0
    movs r1, #0x52
    strb r1, [r0]
    ldr r0, lbl_08075350 @ =0x0000023b
    adds r0, r4, r0
    movs r1, #0x55
    strb r1, [r0]
    movs r0, #0x8f
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r2, #0x4e
    strb r2, [r0]
    ldr r0, lbl_08075354 @ =0x0000023d
    adds r0, r4, r0
    movs r1, #0x45
    strb r1, [r0]
    ldr r0, lbl_08075358 @ =0x0000023e
    adds r0, r4, r0
    strb r2, [r0]
    ldr r0, lbl_0807535c @ =0x0000023f
    adds r0, r4, r0
    movs r1, #0x44
    strb r1, [r0]
    ldr r0, lbl_08075360 @ =gUseMotherShipDoors
    ldrb r1, [r0]
    movs r0, #0x90
    lsls r0, r0, #2
    adds r4, r4, r0
    strb r1, [r4]
    movs r0, #0xd
    bl DoSramOperation
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075314: .4byte 0x0000ffff
lbl_08075318: .4byte 0x0203f800
lbl_0807531c: .4byte gCurrentArea
lbl_08075320: .4byte gLastDoorUsed
lbl_08075324: .4byte gSamusData
lbl_08075328: .4byte gSamusWeaponInfo
lbl_0807532c: .4byte gSamusEcho
lbl_08075330: .4byte gScrewSpeedAnimation
lbl_08075334: .4byte gEquipment
lbl_08075338: .4byte gSamusHazardDamage
lbl_0807533c: .4byte gSamusEnvironmentalEffects
lbl_08075340: .4byte 0x02037400
lbl_08075344: .4byte 0x02037c00
lbl_08075348: .4byte 0x00000239
lbl_0807534c: .4byte 0x0000023a
lbl_08075350: .4byte 0x0000023b
lbl_08075354: .4byte 0x0000023d
lbl_08075358: .4byte 0x0000023e
lbl_0807535c: .4byte 0x0000023f
lbl_08075360: .4byte gUseMotherShipDoors

    thumb_func_start SramLoad_DemoRamValues
SramLoad_DemoRamValues: @ 0x08075364
    push {r4, r5, r6, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    ldr r0, lbl_080753c8 @ =0x0875fdfc
    lsrs r1, r1, #0x16
    adds r1, r1, r0
    ldr r6, [r1]
    cmp r2, #0
    bne lbl_080753e0
    ldr r4, lbl_080753cc @ =gCurrentArea
    ldrb r0, [r6]
    strb r0, [r4]
    ldr r1, lbl_080753d0 @ =gLastDoorUsed
    ldrb r0, [r6, #1]
    strb r0, [r1]
    ldr r1, lbl_080753d4 @ =gUseMotherShipDoors
    movs r2, #0x90
    lsls r2, r2, #2
    adds r0, r6, r2
    ldrb r0, [r0]
    strb r0, [r1]
    movs r3, #0xcc
    lsls r3, r3, #1
    adds r1, r6, r3
    ldrb r2, [r4]
    lsls r2, r2, #7
    ldr r0, lbl_080753d8 @ =0x02037400
    adds r2, r2, r0
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    movs r2, #0x86
    lsls r2, r2, #2
    adds r1, r6, r2
    ldrb r2, [r4]
    lsls r2, r2, #5
    ldr r3, lbl_080753dc @ =0x02037c00
    adds r2, r2, r3
    str r5, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_08075470
    .align 2, 0
lbl_080753c8: .4byte 0x0875fdfc
lbl_080753cc: .4byte gCurrentArea
lbl_080753d0: .4byte gLastDoorUsed
lbl_080753d4: .4byte gUseMotherShipDoors
lbl_080753d8: .4byte 0x02037400
lbl_080753dc: .4byte 0x02037c00
lbl_080753e0:
    cmp r2, #1
    bne lbl_08075470
    ldr r1, lbl_08075478 @ =gSamusData
    adds r0, r6, #4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r4}
    stm r1!, {r2, r4}
    ldr r2, lbl_0807547c @ =gSamusWeaponInfo
    ldr r0, [r6, #0x24]
    ldr r1, [r6, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075480 @ =gSamusEcho
    adds r1, r6, #0
    adds r1, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    ldr r2, lbl_08075484 @ =gScrewSpeedAnimation
    movs r3, #0x9c
    lsls r3, r3, #1
    adds r0, r6, r3
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08075488 @ =gEquipment
    movs r4, #0xa0
    lsls r4, r4, #1
    adds r0, r6, r4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r2, lbl_0807548c @ =gSamusHazardDamage
    movs r4, #0xaa
    lsls r4, r4, #1
    adds r0, r6, r4
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075490 @ =gSamusEnvironmentalEffects
    movs r2, #0xae
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xb4
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r4, #0xba
    lsls r4, r4, #1
    adds r1, r6, r4
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r2, #0xc0
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xc6
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
lbl_08075470:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075478: .4byte gSamusData
lbl_0807547c: .4byte gSamusWeaponInfo
lbl_08075480: .4byte gSamusEcho
lbl_08075484: .4byte gScrewSpeedAnimation
lbl_08075488: .4byte gEquipment
lbl_0807548c: .4byte gSamusHazardDamage
lbl_08075490: .4byte gSamusEnvironmentalEffects

    thumb_func_start sub_08075494
sub_08075494: @ 0x08075494
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r5, lbl_080754c0 @ =0x02038000
    ldr r2, lbl_080754c4 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r4, lbl_080754c8 @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080754ae
    movs r0, #1
    strb r0, [r2]
    strb r1, [r4]
lbl_080754ae:
    ldrb r0, [r4]
    cmp r0, #4
    bhi lbl_08075588
    lsls r0, r0, #2
    ldr r1, lbl_080754cc @ =lbl_080754d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080754c0: .4byte 0x02038000
lbl_080754c4: .4byte gDisableSoftreset
lbl_080754c8: .4byte gSramOperationStage
lbl_080754cc: .4byte lbl_080754d0
lbl_080754d0: @ jump table
    .4byte lbl_080754e4 @ case 0
    .4byte lbl_08075530 @ case 1
    .4byte lbl_0807553c @ case 2
    .4byte lbl_08075568 @ case 3
    .4byte lbl_08075588 @ case 4
lbl_080754e4:
    ldr r0, lbl_08075520 @ =gSaveFilesInfo
    lsls r2, r3, #1
    adds r2, r2, r3
    lsls r2, r2, #3
    adds r2, r2, r0
    adds r1, r2, #0
    ldr r0, lbl_08075524 @ =0x08760408
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldr r0, lbl_08075528 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r2, #0x13]
    ldr r1, lbl_0807552c @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075520: .4byte gSaveFilesInfo
lbl_08075524: .4byte 0x08760408
lbl_08075528: .4byte gLanguage
lbl_0807552c: .4byte 0x0000ffff
lbl_08075530:
    ldr r0, lbl_08075538 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #0
    b lbl_0807556e
    .align 2, 0
lbl_08075538: .4byte gMostRecentSaveFile
lbl_0807553c:
    ldr r1, lbl_08075560 @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    ldr r0, lbl_08075564 @ =0x000036e0
    adds r2, r2, r0
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075560: .4byte 0x0000ffff
lbl_08075564: .4byte 0x000036e0
lbl_08075568:
    ldr r0, lbl_08075580 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #1
lbl_0807556e:
    bl unk_fbc
    cmp r0, #0
    beq lbl_08075590
lbl_08075576:
    ldr r1, lbl_08075584 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08075590
    .align 2, 0
lbl_08075580: .4byte gMostRecentSaveFile
lbl_08075584: .4byte gSramOperationStage
lbl_08075588:
    ldr r1, lbl_080755a0 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r4]
lbl_08075590:
    ldr r0, lbl_080755a0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080755a0: .4byte gDisableSoftreset

    thumb_func_start sub_080755a4
sub_080755a4: @ 0x080755a4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    ldr r6, lbl_080755d4 @ =0x02038000
    ldr r2, lbl_080755d8 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r5, lbl_080755dc @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080755c2
    movs r0, #1
    strb r0, [r2]
    strb r1, [r5]
lbl_080755c2:
    ldrb r0, [r5]
    cmp r0, #4
    bhi lbl_080756a4
    lsls r0, r0, #2
    ldr r1, lbl_080755e0 @ =lbl_080755e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080755d4: .4byte 0x02038000
lbl_080755d8: .4byte gDisableSoftreset
lbl_080755dc: .4byte gSramOperationStage
lbl_080755e0: .4byte lbl_080755e4
lbl_080755e4: @ jump table
    .4byte lbl_080755f8 @ case 0
    .4byte lbl_08075634 @ case 1
    .4byte lbl_08075640 @ case 2
    .4byte lbl_08075680 @ case 3
    .4byte lbl_080756a4 @ case 4
lbl_080755f8:
    ldr r2, lbl_08075630 @ =gSaveFilesInfo
    lsls r1, r3, #1
    adds r1, r1, r3
    lsls r1, r1, #3
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #3
    adds r1, r1, r2
    adds r0, r0, r2
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    adds r1, #0x80
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    b lbl_0807565c
    .align 2, 0
lbl_08075630: .4byte gSaveFilesInfo
lbl_08075634:
    ldr r5, lbl_0807563c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #0
    b lbl_08075686
    .align 2, 0
lbl_0807563c: .4byte gMostRecentSaveFile
lbl_08075640:
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    ldr r0, lbl_08075678 @ =0x000036e0
    adds r1, r1, r0
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, r2, r0
lbl_0807565c:
    adds r2, r6, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0807567c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080756ac
    .align 2, 0
lbl_08075678: .4byte 0x000036e0
lbl_0807567c: .4byte gSramOperationStage
lbl_08075680:
    ldr r5, lbl_0807569c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #1
lbl_08075686:
    bl unk_fbc
    cmp r0, #0
    beq lbl_08075696
    ldr r1, lbl_080756a0 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08075696:
    strb r4, [r5]
    b lbl_080756ac
    .align 2, 0
lbl_0807569c: .4byte gMostRecentSaveFile
lbl_080756a0: .4byte gSramOperationStage
lbl_080756a4:
    ldr r1, lbl_080756bc @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r5]
lbl_080756ac:
    ldr r0, lbl_080756bc @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080756bc: .4byte gDisableSoftreset

    thumb_func_start sub_080756c0
sub_080756c0: @ 0x080756c0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0807574c @ =0x02038000
    movs r6, #0
    ldr r1, lbl_08075750 @ =gSaveFilesInfo
    adds r5, r0, #0
    adds r5, #0xbc
    adds r4, r0, #0
    adds r4, #0x98
    adds r3, r0, #0
    adds r3, #0x80
    movs r0, #0x91
    lsls r0, r0, #5
    mov ip, r0
    movs r7, #2
    mov r8, r7
lbl_080756e2:
    ldrb r0, [r4, #5]
    strb r0, [r1, #2]
    ldrb r2, [r1]
    cmp r2, #1
    bne lbl_08075756
    movs r7, #0xd1
    lsls r7, r7, #1
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #4]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #6]
    adds r7, #8
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #8]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    adds r7, #0x10
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xc]
    adds r7, #0x4e
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xd]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xe]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xf]
    ldrb r0, [r4, #4]
    strb r0, [r1, #0x10]
    ldrb r0, [r4]
    strb r0, [r1, #0x11]
    ldrb r0, [r4, #1]
    strb r0, [r1, #0x12]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_08075754
    strb r2, [r1, #0x14]
    b lbl_08075756
    .align 2, 0
lbl_0807574c: .4byte 0x02038000
lbl_08075750: .4byte gSaveFilesInfo
lbl_08075754:
    strb r0, [r1, #0x14]
lbl_08075756:
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08075762
    ldrb r0, [r1, #0x10]
    cmp r0, #0
    bne lbl_080757a4
lbl_08075762:
    strb r6, [r1]
    strb r6, [r1, #2]
    movs r2, #0
    strh r6, [r1, #4]
    strh r6, [r1, #6]
    strh r6, [r1, #8]
    strh r6, [r1, #0xa]
    strb r2, [r1, #0xc]
    strb r2, [r1, #0xd]
    strb r2, [r1, #0xe]
    strb r2, [r1, #0xf]
    ldr r0, lbl_080757c4 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r1, #0x13]
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_080757a4
    movs r0, #5
    strb r0, [r1, #2]
    movs r0, #0x63
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strb r2, [r1, #0x14]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_0807579a
    movs r0, #1
lbl_0807579a:
    strb r0, [r1, #0x14]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
lbl_080757a4:
    adds r1, #0x18
    add r5, ip
    add r4, ip
    add r3, ip
    movs r0, #1
    rsbs r0, r0, #0
    add r8, r0
    mov r7, r8
    cmp r7, #0
    bge lbl_080756e2
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080757c4: .4byte gLanguage

    thumb_func_start sub_080757c8
sub_080757c8: @ 0x080757c8
    push {r4, lr}
    ldr r1, lbl_080757f4 @ =gMostRecentSaveFile
    movs r4, #0
    ldrsb r4, [r1, r4]
    strb r0, [r1]
    ldr r2, lbl_080757f8 @ =gSaveFilesInfo
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #1]
    cmp r0, #4
    bhi lbl_08075828
    lsls r0, r0, #2
    ldr r1, lbl_080757fc @ =lbl_08075800
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080757f4: .4byte gMostRecentSaveFile
lbl_080757f8: .4byte gSaveFilesInfo
lbl_080757fc: .4byte lbl_08075800
lbl_08075800: @ jump table
    .4byte lbl_08075828 @ case 0
    .4byte lbl_08075814 @ case 1
    .4byte lbl_0807581c @ case 2
    .4byte lbl_08075828 @ case 3
    .4byte lbl_08075828 @ case 4
lbl_08075814:
    movs r0, #3
    bl DoSramOperation
    b lbl_08075828
lbl_0807581c:
    movs r0, #3
    bl DoSramOperation
    movs r0, #4
    bl DoSramOperation
lbl_08075828:
    ldr r3, lbl_08075844 @ =gSaveFilesInfo
    ldr r2, lbl_08075848 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    movs r1, #0
    strb r1, [r0, #1]
    strb r4, [r2]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075844: .4byte gSaveFilesInfo
lbl_08075848: .4byte gMostRecentSaveFile

    thumb_func_start unk_7584c
unk_7584c: @ 0x0807584c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_08075880 @ =gButtonAssignments
    ldr r0, lbl_08075884 @ =0x08411510
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r7, lbl_08075888 @ =gMaxInGameTimerFlag
    movs r1, #0
    strb r1, [r7]
    ldr r0, lbl_0807588c @ =gShipLandingFlag
    strb r1, [r0]
    ldr r0, lbl_08075890 @ =gColorFading
    movs r5, #0
    movs r6, #2
    strb r6, [r0]
    cmp r4, #1
    beq lbl_080758b4
    cmp r4, #1
    bgt lbl_08075894
    cmp r4, #0
    beq lbl_0807589e
    b lbl_08075918
    .align 2, 0
lbl_08075880: .4byte gButtonAssignments
lbl_08075884: .4byte 0x08411510
lbl_08075888: .4byte gMaxInGameTimerFlag
lbl_0807588c: .4byte gShipLandingFlag
lbl_08075890: .4byte gColorFading
lbl_08075894:
    cmp r4, #2
    beq lbl_08075918
    cmp r4, #3
    beq lbl_080758f4
    b lbl_08075918
lbl_0807589e:
    ldr r1, lbl_080758ac @ =gStartingInfo
    ldr r0, lbl_080758b0 @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl check_load_save_file
    b lbl_08075914
    .align 2, 0
lbl_080758ac: .4byte gStartingInfo
lbl_080758b0: .4byte 0x08411524
lbl_080758b4:
    ldr r1, lbl_080758d8 @ =gStartingInfo
    ldr r0, lbl_080758dc @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl init_save_file
    ldr r0, lbl_080758e0 @ =gCurrentRoom
    strb r5, [r0]
    ldr r0, lbl_080758e4 @ =gLastDoorUsed
    strb r5, [r0]
    strb r4, [r7]
    ldr r0, lbl_080758e8 @ =gSkipDoorTransition
    strb r5, [r0]
    ldr r0, lbl_080758ec @ =gDebugFlag
    strb r5, [r0]
    ldr r0, lbl_080758f0 @ =gLanguage
    strb r6, [r0]
    b lbl_08075914
    .align 2, 0
lbl_080758d8: .4byte gStartingInfo
lbl_080758dc: .4byte 0x08411524
lbl_080758e0: .4byte gCurrentRoom
lbl_080758e4: .4byte gLastDoorUsed
lbl_080758e8: .4byte gSkipDoorTransition
lbl_080758ec: .4byte gDebugFlag
lbl_080758f0: .4byte gLanguage
lbl_080758f4:
    ldr r3, lbl_08075940 @ =gIsLoadingFile
    ldr r2, lbl_08075944 @ =gSaveFilesInfo
    ldr r0, lbl_08075948 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08075914
    bl sub_0807478c
lbl_08075914:
    ldr r0, lbl_0807594c @ =gCurrentCutscene
    strb r5, [r0]
lbl_08075918:
    ldr r0, lbl_08075950 @ =gGameModeSub3
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08075954 @ =gMonochromeBgFading
    strb r1, [r0]
    ldr r0, lbl_08075958 @ =gDisableSoftreset
    strb r1, [r0]
    ldr r0, lbl_0807595c @ =gSubGameModeStage
    strb r1, [r0]
    ldr r0, lbl_08075960 @ =gPauseScreenFlag
    strb r1, [r0]
    ldr r0, lbl_08075964 @ =gDisablePause
    strb r1, [r0]
    ldr r1, lbl_08075968 @ =gSamusDoorPositionOffset
    movs r0, #0
    strh r0, [r1]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075940: .4byte gIsLoadingFile
lbl_08075944: .4byte gSaveFilesInfo
lbl_08075948: .4byte gMostRecentSaveFile
lbl_0807594c: .4byte gCurrentCutscene
lbl_08075950: .4byte gGameModeSub3
lbl_08075954: .4byte gMonochromeBgFading
lbl_08075958: .4byte gDisableSoftreset
lbl_0807595c: .4byte gSubGameModeStage
lbl_08075960: .4byte gPauseScreenFlag
lbl_08075964: .4byte gDisablePause
lbl_08075968: .4byte gSamusDoorPositionOffset

    thumb_func_start check_load_save_file
check_load_save_file: @ 0x0807596c
    push {r4, r5, r6, lr}
    ldr r2, lbl_08075a10 @ =gIsLoadingFile
    ldr r6, lbl_08075a14 @ =gSaveFilesInfo
    ldr r5, lbl_08075a18 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0]
    strb r0, [r2]
    lsls r0, r0, #0x18
    asrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_08075a4c
    bl init_save_file
    ldr r1, lbl_08075a1c @ =gColorFading
    movs r0, #0x15
    strb r0, [r1]
    ldr r0, lbl_08075a20 @ =gEquipment
    strb r4, [r0, #0x10]
    ldr r2, lbl_08075a24 @ =gCurrentArea
    ldr r0, lbl_08075a28 @ =gStartingInfo
    ldrb r1, [r0]
    strb r1, [r2]
    ldr r0, lbl_08075a2c @ =gAreaBeforeTransition
    strb r1, [r0]
    ldr r0, lbl_08075a30 @ =gCurrentRoom
    strb r4, [r0]
    ldr r0, lbl_08075a34 @ =gLastDoorUsed
    strb r4, [r0]
    ldr r2, lbl_08075a38 @ =gGameCompletion
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x11]
    strb r0, [r2]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x12]
    strb r0, [r2, #1]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x13]
    strb r0, [r2, #2]
    ldr r2, lbl_08075a3c @ =gDifficulty
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x14]
    strb r0, [r2]
    ldr r2, lbl_08075a40 @ =gTimeAttackFlag
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x15]
    strb r0, [r2]
    ldr r0, lbl_08075a44 @ =gUseMotherShipDoors
    strb r4, [r0]
    ldr r1, lbl_08075a48 @ =gShipLandingFlag
    movs r0, #1
    strb r0, [r1]
    b lbl_08075a50
    .align 2, 0
lbl_08075a10: .4byte gIsLoadingFile
lbl_08075a14: .4byte gSaveFilesInfo
lbl_08075a18: .4byte gMostRecentSaveFile
lbl_08075a1c: .4byte gColorFading
lbl_08075a20: .4byte gEquipment
lbl_08075a24: .4byte gCurrentArea
lbl_08075a28: .4byte gStartingInfo
lbl_08075a2c: .4byte gAreaBeforeTransition
lbl_08075a30: .4byte gCurrentRoom
lbl_08075a34: .4byte gLastDoorUsed
lbl_08075a38: .4byte gGameCompletion
lbl_08075a3c: .4byte gDifficulty
lbl_08075a40: .4byte gTimeAttackFlag
lbl_08075a44: .4byte gUseMotherShipDoors
lbl_08075a48: .4byte gShipLandingFlag
lbl_08075a4c:
    bl sub_0807478c
lbl_08075a50:
    ldr r3, lbl_08075a7c @ =gGameCompletion
    ldr r2, lbl_08075a80 @ =gSaveFilesInfo
    ldr r0, lbl_08075a84 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r0, #0x13]
    movs r2, #0
    strb r1, [r3, #2]
    ldr r0, lbl_08075a88 @ =gLanguage
    strb r1, [r0]
    ldr r0, lbl_08075a8c @ =gSkipDoorTransition
    strb r2, [r0]
    ldr r0, lbl_08075a90 @ =gDebugFlag
    strb r2, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075a7c: .4byte gGameCompletion
lbl_08075a80: .4byte gSaveFilesInfo
lbl_08075a84: .4byte gMostRecentSaveFile
lbl_08075a88: .4byte gLanguage
lbl_08075a8c: .4byte gSkipDoorTransition
lbl_08075a90: .4byte gDebugFlag

    thumb_func_start init_save_file
init_save_file: @ 0x08075a94
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r2, lbl_08075ba8 @ =0x02037400
    movs r6, #0x80
    lsls r6, r6, #4
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    ldr r4, lbl_08075bac @ =0x0000ffff
    ldr r2, lbl_08075bb0 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bb4 @ =0x02036c00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r3, r6, #0
    bl BitFill
    ldr r2, lbl_08075bb8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #2
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bbc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x20
    bl BitFill
    ldr r2, lbl_08075bc0 @ =0x02033800
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    movs r1, #0
    ldr r4, lbl_08075bc4 @ =gNumberOfNeverReformBlocks
    movs r2, #0
    ldr r3, lbl_08075bc8 @ =gNumberOfItemsCollected
lbl_08075b08:
    adds r0, r1, r4
    strb r2, [r0]
    adds r0, r1, r3
    strb r2, [r0]
    adds r1, #1
    cmp r1, #7
    ble lbl_08075b08
    ldr r1, lbl_08075bcc @ =gInGameTimer
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_08075bd4 @ =gDisableDrawingSamusAndScrolling
    mov r8, r0
    ldr r1, lbl_08075bd8 @ =gDifficulty
    mov sl, r1
    ldr r2, lbl_08075bdc @ =gIsLoadingFile
    mov sb, r2
    ldr r2, lbl_08075be0 @ =gBestCompletionTimes
    ldr r0, lbl_08075be4 @ =0x0841151c
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x2c
lbl_08075b34:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b34
    ldr r2, lbl_08075be8 @ =gInGameTimerAtBosses
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x10
lbl_08075b46:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b46
    movs r1, #0
    ldr r0, lbl_08075bec @ =0x083602e8
    mov ip, r0
    ldr r7, lbl_08075bf0 @ =gInGameCutscenesTriggered
lbl_08075b56:
    movs r3, #0
    movs r4, #0
    adds r6, r1, #1
    lsls r5, r1, #2
    lsls r0, r1, #8
    mov r1, ip
    adds r2, r0, r1
lbl_08075b64:
    ldrb r1, [r2]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    lsls r0, r3
    orrs r4, r0
    adds r2, #8
    adds r3, #1
    cmp r3, #0x1f
    ble lbl_08075b64
    adds r0, r5, r7
    str r4, [r0]
    adds r1, r6, #0
    cmp r1, #0
    ble lbl_08075b56
    movs r1, #0
    mov r2, r8
    strb r1, [r2]
    movs r0, #1
    mov r2, sl
    strb r0, [r2]
    ldr r0, lbl_08075bf4 @ =gTimeAttackFlag
    strb r1, [r0]
    mov r2, sb
    strb r1, [r2]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075ba8: .4byte 0x02037400
lbl_08075bac: .4byte 0x0000ffff
lbl_08075bb0: .4byte 0x02035c00
lbl_08075bb4: .4byte 0x02036c00
lbl_08075bb8: .4byte 0x02037c00
lbl_08075bbc: .4byte 0x02037e00
lbl_08075bc0: .4byte 0x02033800
lbl_08075bc4: .4byte gNumberOfNeverReformBlocks
lbl_08075bc8: .4byte gNumberOfItemsCollected
lbl_08075bcc: .4byte gInGameTimer
lbl_08075bd0: .4byte 0x08411518
lbl_08075bd4: .4byte gDisableDrawingSamusAndScrolling
lbl_08075bd8: .4byte gDifficulty
lbl_08075bdc: .4byte gIsLoadingFile
lbl_08075be0: .4byte gBestCompletionTimes
lbl_08075be4: .4byte 0x0841151c
lbl_08075be8: .4byte gInGameTimerAtBosses
lbl_08075bec: .4byte 0x083602e8
lbl_08075bf0: .4byte gInGameCutscenesTriggered
lbl_08075bf4: .4byte gTimeAttackFlag
lbl_08075bf8:
    .byte 0x81, 0xB0, 0x69, 0x46, 0x00, 0x20, 0x08, 0x70
    .byte 0x01, 0xB0, 0x70, 0x47

    thumb_func_start unk_75c04
unk_75c04: @ 0x08075c04
    push {r4, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r0, lbl_08075c28 @ =0x08075bf9
    bl CallbackSetVBlank
    adds r0, r4, #0
    bl unk_7584c
    ldr r0, lbl_08075c2c @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08075c28: .4byte 0x08075bf9
lbl_08075c2c: .4byte gIsLoadingFile
