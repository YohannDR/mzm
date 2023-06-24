    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_08068168
sub_08068168: @ 0x08068168
    push {r4, r5, r6, r7, lr}
    lsls r7, r0, #0x10
    lsrs r4, r7, #0x10
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    ldr r5, lbl_080681bc @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r3, r0, #0
    adds r3, #0x7c
    ldrb r0, [r3]
    adds r6, r0, #0
    cmp r6, #0
    bne lbl_080681c0
    cmp r1, #0
    beq lbl_080681c0
    adds r0, #1
    strb r0, [r3]
    ldr r0, [r5]
    adds r0, #0x7d
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x7f
    strb r2, [r0]
    ldr r0, [r5]
    movs r1, #0x1f
    ands r4, r1
    adds r0, #0x80
    strb r4, [r0]
    ldr r2, [r5]
    lsrs r0, r7, #0x18
    movs r1, #0x1f
    ands r0, r1
    adds r2, #0x81
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0x7e
    strb r6, [r0]
    movs r0, #1
    b lbl_080681c2
    .align 2, 0
lbl_080681bc: .4byte sNonGameplayRamPointer
lbl_080681c0:
    movs r0, #0
lbl_080681c2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_080681c8
sub_080681c8: @ 0x080681c8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r0, #0
    mov sb, r0
    ldr r0, lbl_0806823c @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r1, r2, #0
    adds r1, #0x7c
    ldrb r1, [r1]
    mov r8, r0
    cmp r1, #0
    beq lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x7e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0x7f
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, #0x7e
    ldrb r2, [r0]
    cmp r1, r2
    bgt lbl_080682dc
    mov r3, sb
    strb r3, [r0]
    ldr r0, lbl_08068240 @ =gWrittenToBLDALPHA_L
    mov r1, r8
    ldr r2, [r1]
    adds r6, r2, #0
    adds r6, #0x80
    ldrb r3, [r6]
    ldrh r5, [r0]
    adds r4, r5, #0
    adds r1, r3, #0
    mov ip, r0
    cmp r4, r1
    beq lbl_08068264
    cmp r4, r1
    bls lbl_0806824a
    ldrh r4, [r0]
    subs r1, r4, r3
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    cmp r1, r0
    ble lbl_08068244
    subs r0, r4, r0
    mov r2, ip
    strh r0, [r2]
    b lbl_08068264
    .align 2, 0
lbl_0806823c: .4byte sNonGameplayRamPointer
lbl_08068240: .4byte gWrittenToBLDALPHA_L
lbl_08068244:
    mov r0, ip
    strh r3, [r0]
    b lbl_08068264
lbl_0806824a:
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    adds r0, r5, r0
    mov r1, ip
    strh r0, [r1]
    ldrb r1, [r6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_08068264
    mov r2, ip
    strh r1, [r2]
lbl_08068264:
    ldr r0, lbl_08068294 @ =gWrittenToBLDALPHA_H
    mov r3, r8
    ldr r2, [r3]
    adds r6, r2, #0
    adds r6, #0x81
    ldrb r3, [r6]
    ldrh r5, [r0]
    adds r4, r5, #0
    adds r1, r3, #0
    adds r7, r0, #0
    cmp r4, r1
    beq lbl_080682b2
    cmp r4, r1
    bls lbl_0806829c
    ldrh r4, [r7]
    subs r1, r4, r3
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    cmp r1, r0
    ble lbl_08068298
    subs r0, r4, r0
    strh r0, [r7]
    b lbl_080682b2
    .align 2, 0
lbl_08068294: .4byte gWrittenToBLDALPHA_H
lbl_08068298:
    strh r3, [r7]
    b lbl_080682b2
lbl_0806829c:
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    adds r0, r5, r0
    strh r0, [r7]
    ldrb r1, [r6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_080682b2
    strh r1, [r7]
lbl_080682b2:
    mov r0, r8
    ldr r2, [r0]
    adds r1, r2, #0
    adds r1, #0x80
    mov r3, ip
    ldrh r0, [r3]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x81
    ldrh r0, [r7]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x7c
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    mov sb, r0
lbl_080682dc:
    mov r0, sb
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080682ec
sub_080682ec: @ 0x080682ec
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r7, lbl_0806831c @ =sNonGameplayRamPointer
    cmp r1, #0
    beq lbl_08068304
    ldr r0, [r7]
    adds r0, #0xbc
    strb r1, [r0]
lbl_08068304:
    ldr r0, [r7]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #5
    bls lbl_08068310
    b lbl_08068570
lbl_08068310:
    lsls r0, r0, #2
    ldr r1, lbl_08068320 @ =lbl_08068324
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806831c: .4byte sNonGameplayRamPointer
lbl_08068320: .4byte lbl_08068324
lbl_08068324: @ jump table
    .4byte lbl_08068570 @ case 0
    .4byte lbl_0806833c @ case 1
    .4byte lbl_08068358 @ case 2
    .4byte lbl_080683c0 @ case 3
    .4byte lbl_08068474 @ case 4
    .4byte lbl_080684b0 @ case 5
lbl_0806833c:
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0xbe
    ldrb r1, [r1]
    cmp r1, #0
    beq lbl_0806834a
    b lbl_0806857c
lbl_0806834a:
    adds r0, #0xbd
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xbc
    strb r1, [r0]
    movs r0, #1
    b lbl_080685a4
lbl_08068358:
    movs r6, #0xa0
    lsls r6, r6, #0x13
    ldr r0, lbl_080683b8 @ =sEwramPointer
    mov r8, r0
    ldr r2, [r0]
    movs r1, #0xd0
    lsls r1, r1, #7
    adds r2, r2, r1
    movs r5, #0x80
    lsls r5, r5, #3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl BitFill
    mov r3, r8
    ldr r2, [r3]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_080683bc @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xbd
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbc
    movs r1, #3
    b lbl_0806856e
    .align 2, 0
lbl_080683b8: .4byte sEwramPointer
lbl_080683bc: .4byte sNonGameplayRamPointer
lbl_080683c0:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080683ce
    b lbl_0806857c
lbl_080683ce:
    adds r0, r1, #0
    adds r0, #0xbd
    ldrb r0, [r0]
    cmp r0, #0x1f
    bhi lbl_08068450
    ldr r5, lbl_08068448 @ =sEwramPointer
    ldr r0, [r5]
    movs r2, #0xd0
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r0, [r7]
    adds r0, #0xbd
    ldrb r1, [r0]
    add r6, sp, #8
    ldr r4, lbl_0806844c @ =0x0000ffff
    str r4, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r5]
    movs r2, #0xd4
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xdc
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r0, [r7]
    adds r0, #0xbd
    ldrb r1, [r0]
    str r4, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r7]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0xbd
    ldrb r0, [r1]
    cmp r0, #0x1f
    beq lbl_0806852c
    ldrb r0, [r1]
    adds r0, #2
    cmp r0, #0x1f
    ble lbl_08068444
    b lbl_08068544
lbl_08068444:
    b lbl_0806852e
    .align 2, 0
lbl_08068448: .4byte sEwramPointer
lbl_0806844c: .4byte 0x0000ffff
lbl_08068450:
    ldr r0, lbl_08068470 @ =sEwramPointer
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r1, r2, r0
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_08068562
    .align 2, 0
lbl_08068470: .4byte sEwramPointer
lbl_08068474:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_080684a8 @ =sEwramPointer
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_080684ac @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0xbd
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbc
    movs r1, #5
    b lbl_0806856e
    .align 2, 0
lbl_080684a8: .4byte sEwramPointer
lbl_080684ac: .4byte sNonGameplayRamPointer
lbl_080684b0:
    mov r8, r7
    mov r2, r8
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806857c
    adds r2, r1, #0
    adds r2, #0xbd
    ldrb r0, [r2]
    cmp r0, #0x1f
    bhi lbl_08068548
    ldr r4, lbl_08068534 @ =sEwramPointer
    ldr r0, [r4]
    movs r3, #0xd0
    lsls r3, r3, #7
    adds r1, r0, r3
    str r1, [sp, #4]
    movs r1, #0xd8
    lsls r1, r1, #7
    adds r0, r0, r1
    str r0, [sp, #8]
    ldrb r1, [r2]
    add r6, sp, #8
    ldr r5, lbl_08068538 @ =0x0000ffff
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0xd4
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xdc
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0xbd
    ldrb r1, [r0]
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    mov r2, r8
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xbd
    ldrb r0, [r1]
    cmp r0, #0x1f
    bne lbl_0806853c
lbl_0806852c:
    adds r0, #1
lbl_0806852e:
    strb r0, [r1]
    b lbl_08068570
    .align 2, 0
lbl_08068534: .4byte sEwramPointer
lbl_08068538: .4byte 0x0000ffff
lbl_0806853c:
    ldrb r0, [r1]
    adds r0, #2
    cmp r0, #0x1f
    ble lbl_0806852e
lbl_08068544:
    movs r0, #0x1f
    b lbl_0806852e
lbl_08068548:
    ldr r0, lbl_080685b0 @ =sEwramPointer
    ldr r2, [r0]
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
lbl_08068562:
    ldr r0, [r7]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xbc
lbl_0806856e:
    strb r1, [r0]
lbl_08068570:
    ldr r0, lbl_080685b4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080685a2
lbl_0806857c:
    ldr r0, lbl_080685b0 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r1, r1, r0
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_080685b4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbe
    movs r1, #0
    strb r1, [r0]
lbl_080685a2:
    movs r0, #0
lbl_080685a4:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080685b0: .4byte sEwramPointer
lbl_080685b4: .4byte sNonGameplayRamPointer

    thumb_func_start sub_080685b8
sub_080685b8: @ 0x080685b8
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    sub sp, #4
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08068614
    movs r6, #0xa0
    lsls r6, r6, #0x13
    ldr r0, lbl_08068610 @ =sEwramPointer
    mov r8, r0
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r5, #0x80
    lsls r5, r5, #3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl BitFill
    mov r0, r8
    ldr r2, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    b lbl_08068630
    .align 2, 0
lbl_08068610: .4byte sEwramPointer
lbl_08068614:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_08068648 @ =sEwramPointer
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_08068630:
    ldr r0, lbl_0806864c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbc
    movs r1, #0
    strb r1, [r0]
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068648: .4byte sEwramPointer
lbl_0806864c: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08068650
sub_08068650: @ 0x08068650
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0806868c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08068684
    ldr r0, lbl_08068690 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r1, r1, r0
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, [r4]
    adds r0, #0xbe
    movs r1, #0
    strb r1, [r0]
lbl_08068684:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806868c: .4byte sNonGameplayRamPointer
lbl_08068690: .4byte sEwramPointer

    thumb_func_start sub_08068694
sub_08068694: @ 0x08068694
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_080687fc @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_080686a8
    b lbl_0806888e
lbl_080686a8:
    ldr r0, lbl_08068800 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r3, [r1, #4]
    movs r2, #1
    mov r8, r2
    adds r5, r0, #0
    cmp r3, #0
    beq lbl_080686cc
    movs r0, #0
    mov r8, r0
    cmp r3, #0xc
    bne lbl_080686c4
    movs r2, #2
    mov r8, r2
lbl_080686c4:
    mov r0, r8
    cmp r0, #0
    bne lbl_080686cc
    b lbl_0806880c
lbl_080686cc:
    ldr r2, [r5]
    movs r3, #0
    adds r1, r2, #0
    adds r1, #0x25
    adds r0, r2, #0
    adds r0, #0x28
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r1, r0
    ble lbl_080686ea
    movs r3, #1
lbl_080686ea:
    adds r0, r2, #0
    adds r0, #0x30
    strb r3, [r0]
    ldr r3, [r5]
    movs r4, #0
    adds r0, r3, #0
    adds r0, #0x29
    adds r2, r3, #0
    adds r2, #0x25
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806870a
    movs r4, #1
lbl_0806870a:
    adds r0, r3, #0
    adds r0, #0x31
    strb r4, [r0]
    ldr r3, [r5]
    movs r4, #0
    adds r0, r3, #0
    adds r0, #0x24
    adds r2, r3, #0
    adds r2, #0x27
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806872a
    movs r4, #1
lbl_0806872a:
    adds r0, r3, #0
    adds r0, #0x2f
    strb r4, [r0]
    ldr r2, [r5]
    movs r3, #0
    adds r1, r2, #0
    adds r1, #0x26
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r1, r0
    ble lbl_0806874e
    movs r3, #1
lbl_0806874e:
    adds r0, r2, #0
    adds r0, #0x2e
    strb r3, [r0]
    ldr r1, [r5]
    ldr r2, lbl_08068804 @ =0x0840d0d0
    mov ip, r2
    ldrh r0, [r2]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0806876c
    movs r2, #1
lbl_0806876c:
    ldr r6, lbl_08068808 @ =0x00000473
    adds r3, r3, r6
    movs r4, #1
    lsls r2, r2, #5
    ldrb r1, [r3]
    movs r7, #0x21
    rsbs r7, r7, #0
    adds r0, r7, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #8]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08068798
    movs r2, #1
lbl_08068798:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #0x10]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080687c0
    movs r2, #1
lbl_080687c0:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #0x18]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080687e8
    movs r2, #1
lbl_080687e8:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    b lbl_08068850
    .align 2, 0
lbl_080687fc: .4byte gPauseScreenFlag
lbl_08068800: .4byte sNonGameplayRamPointer
lbl_08068804: .4byte 0x0840d0d0
lbl_08068808: .4byte 0x00000473
lbl_0806880c:
    ldr r4, lbl_08068874 @ =0x0840d0d0
    ldrh r0, [r4]
    lsls r0, r0, #4
    adds r0, r1, r0
    ldr r3, lbl_08068878 @ =0x00000473
    adds r0, r0, r3
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
    ldr r1, [r5]
    ldrh r0, [r4, #8]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r4, #0x10]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r4, #0x18]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
lbl_08068850:
    mov r0, r8
    cmp r0, #1
    bne lbl_08068880
    ldr r2, [r5]
    ldrb r1, [r2, #0x11]
    rsbs r1, r1, #0
    ldr r0, lbl_0806887c @ =0x00000453
    adds r2, r2, r0
    lsrs r1, r1, #0x1f
    lsls r1, r1, #5
    ldrb r3, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    b lbl_0806888e
    .align 2, 0
lbl_08068874: .4byte 0x0840d0d0
lbl_08068878: .4byte 0x00000473
lbl_0806887c: .4byte 0x00000453
lbl_08068880:
    ldr r0, [r5]
    ldr r1, lbl_08068898 @ =0x00000453
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_0806888e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068898: .4byte 0x00000453

    thumb_func_start PauseScreenUpdateBossIcons
PauseScreenUpdateBossIcons: @ 0x0806889c
    push {r4, r5, r6, lr}
    ldr r0, lbl_08068904 @ =sNonGameplayRamPointer
    ldr r4, [r0]
    ldrb r1, [r4, #0x12]
    adds r6, r0, #0
    cmp r1, #6
    bhi lbl_0806894c
    ldr r5, lbl_08068908 @ =0x0840d200
    adds r0, r1, #0
    lsls r1, r0, #2
    adds r2, r1, r0
    adds r0, r2, r5
    ldrb r3, [r0]
    cmp r3, #0
    beq lbl_0806893a
    adds r0, r5, #2
    adds r0, r2, r0
    ldrb r1, [r0]
    lsls r1, r1, #5
    adds r0, r5, #4
    adds r0, r2, r0
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r1, r1, r0
    ldr r2, lbl_0806890c @ =0x0000040a
    adds r0, r4, r2
    strh r1, [r0]
    ldrb r1, [r4, #0x12]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r1, r5, #3
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #5
    subs r2, #2
    adds r1, r4, r2
    strh r0, [r1]
    adds r1, r3, #0
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_08068924
    ldr r1, [r6]
    ldrb r0, [r1, #0x12]
    cmp r0, #5
    beq lbl_08068914
    ldr r0, lbl_08068910 @ =0x00000412
    adds r1, r1, r0
    movs r0, #3
    strb r0, [r1]
    b lbl_08068938
    .align 2, 0
lbl_08068904: .4byte sNonGameplayRamPointer
lbl_08068908: .4byte 0x0840d200
lbl_0806890c: .4byte 0x0000040a
lbl_08068910: .4byte 0x00000412
lbl_08068914:
    ldr r2, lbl_08068920 @ =0x00000412
    adds r1, r1, r2
    movs r0, #0
    strb r0, [r1]
    movs r3, #0
    b lbl_0806893a
    .align 2, 0
lbl_08068920: .4byte 0x00000412
lbl_08068924:
    ldr r2, [r6]
    ldrb r1, [r2, #0x12]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r1, r5, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    ldr r1, lbl_08068954 @ =0x00000412
    adds r2, r2, r1
    strb r0, [r2]
lbl_08068938:
    movs r3, #2
lbl_0806893a:
    ldr r1, [r6]
    ldr r2, lbl_08068958 @ =0x00000413
    adds r1, r1, r2
    lsls r3, r3, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    orrs r0, r3
    strb r0, [r1]
lbl_0806894c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068954: .4byte 0x00000412
lbl_08068958: .4byte 0x00000413

    thumb_func_start draw_pause_screen_info
draw_pause_screen_info: @ 0x0806895c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r3, #0
    ldr r0, lbl_08068998 @ =gGameCompletion
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0806897a
    movs r3, #1
lbl_0806897a:
    ldr r5, lbl_0806899c @ =sNonGameplayRamPointer
    ldr r2, [r5]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806898a
    movs r3, #1
lbl_0806898a:
    cmp r3, #0
    beq lbl_080689a0
    adds r1, r2, #0
    adds r1, #0x34
    movs r0, #0
    strb r0, [r1]
    b lbl_08068a42
    .align 2, 0
lbl_08068998: .4byte gGameCompletion
lbl_0806899c: .4byte sNonGameplayRamPointer
lbl_080689a0:
    cmp r4, #0
    bne lbl_08068a42
    bl PauseScreenCountTanksInArea
    movs r0, #0
    movs r1, #0
    bl PauseScreenDrawIgtAndTanks
    movs r0, #0
    movs r1, #1
    bl PauseScreenDrawIgtAndTanks
    movs r6, #0
    ldr r0, lbl_08068a50 @ =0x08760190
    mov sl, r0
    ldr r2, lbl_08068a54 @ =0x00000113
    mov ip, r2
    movs r7, #3
    mov sb, r7
    mov r3, sl
    movs r4, #0
    movs r0, #4
    rsbs r0, r0, #0
    mov r8, r0
lbl_080689d0:
    ldr r1, [r5]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    mov r0, sl
    adds r0, #2
    adds r0, r4, r0
    ldrh r0, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r1, r1, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    add r1, ip
    ldrb r2, [r1]
    mov r0, r8
    ands r0, r2
    mov r7, sb
    orrs r0, r7
    strb r0, [r1]
    ldr r2, [r5]
    ldrh r1, [r3]
    lsls r1, r1, #4
    adds r1, r2, r1
    mov r0, sl
    adds r0, #4
    adds r0, r4, r0
    ldrh r0, [r0]
    movs r7, #0x85
    lsls r7, r7, #1
    adds r1, r1, r7
    strh r0, [r1]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r0, r2, r0
    ldrh r1, [r3, #6]
    subs r7, #2
    adds r0, r0, r7
    strh r1, [r0]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r2, r2, r0
    add r2, ip
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r3, #0xa
    adds r4, #0xa
    adds r6, #1
    cmp r6, #4
    bls lbl_080689d0
lbl_08068a42:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068a50: .4byte 0x08760190
lbl_08068a54: .4byte 0x00000113

    thumb_func_start sub_08068a58
sub_08068a58: @ 0x08068a58
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r3, r2, #0
    movs r4, #0
    ldr r0, lbl_08068a7c @ =gEquipment
    ldrb r1, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, #2
    bne lbl_08068a94
    cmp r2, #1
    beq lbl_08068a80
    cmp r2, #1
    bgt lbl_08068aea
    cmp r2, #0
    beq lbl_08068ae8
    b lbl_08068aea
    .align 2, 0
lbl_08068a7c: .4byte gEquipment
lbl_08068a80:
    ldr r0, lbl_08068a90 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0xa1
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0x29
    strb r0, [r1]
    b lbl_08068ae8
    .align 2, 0
lbl_08068a90: .4byte sNonGameplayRamPointer
lbl_08068a94:
    cmp r3, #6
    bhi lbl_08068aea
    lsls r0, r3, #2
    ldr r1, lbl_08068aa4 @ =lbl_08068aa8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068aa4: .4byte lbl_08068aa8
lbl_08068aa8: @ jump table
    .4byte lbl_08068ae8 @ case 0
    .4byte lbl_08068ae8 @ case 1
    .4byte lbl_08068ac4 @ case 2
    .4byte lbl_08068ace @ case 3
    .4byte lbl_08068ae8 @ case 4
    .4byte lbl_08068adc @ case 5
    .4byte lbl_08068aea @ case 6
lbl_08068ac4:
    ldrh r1, [r5, #2]
    ldrb r0, [r5, #4]
    cmn r1, r0
    beq lbl_08068aea
    b lbl_08068ae8
lbl_08068ace:
    ldr r0, lbl_08068ad8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xd1
    b lbl_08068ae2
    .align 2, 0
lbl_08068ad8: .4byte sNonGameplayRamPointer
lbl_08068adc:
    ldr r0, lbl_08068af4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xcb
lbl_08068ae2:
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08068aea
lbl_08068ae8:
    movs r4, #2
lbl_08068aea:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08068af4: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08068af8
sub_08068af8: @ 0x08068af8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08068b24 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    movs r2, #0x94
    lsls r2, r2, #1
    adds r4, r0, r2
    movs r6, #7
    adds r5, r1, #0
    cmp r3, #5
    bls lbl_08068b1a
    b lbl_08068d94
lbl_08068b1a:
    lsls r0, r3, #2
    ldr r1, lbl_08068b28 @ =lbl_08068b2c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068b24: .4byte sNonGameplayRamPointer
lbl_08068b28: .4byte lbl_08068b2c
lbl_08068b2c: @ jump table
    .4byte lbl_08068b44 @ case 0
    .4byte lbl_08068b9c @ case 1
    .4byte lbl_08068c20 @ case 2
    .4byte lbl_08068c74 @ case 3
    .4byte lbl_08068cc4 @ case 4
    .4byte lbl_08068d06 @ case 5
lbl_08068b44:
    movs r5, #0
    cmp r5, r6
    bge lbl_08068b8e
lbl_08068b4a:
    ldr r0, lbl_08068b98 @ =0x0840d10c
    lsls r1, r5, #4
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0xa]
    ldrh r0, [r1, #2]
    strh r0, [r4, #2]
    ldrh r0, [r1, #4]
    strh r0, [r4]
    movs r0, #3
    ldrb r2, [r1, #8]
    ands r2, r0
    lsls r2, r2, #2
    ldrb r0, [r4, #0xb]
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #0xb]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    bl sub_08068a58
    lsls r0, r0, #6
    ldrb r2, [r4, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r0
    strb r1, [r4, #0xb]
    adds r5, #1
    adds r4, #0x10
    cmp r5, r6
    blt lbl_08068b4a
lbl_08068b8e:
    movs r0, #0
    bl sub_08068dbc
    b lbl_08068d94
    .align 2, 0
lbl_08068b98: .4byte 0x0840d10c
lbl_08068b9c:
    movs r5, #0
    cmp r5, r6
    bge lbl_08068bea
lbl_08068ba2:
    ldr r0, lbl_08068c14 @ =0x0840d10c
    lsls r1, r5, #4
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0xa]
    ldrh r0, [r1, #6]
    ldrh r2, [r1, #2]
    adds r0, r0, r2
    strh r0, [r4, #2]
    ldrh r0, [r1, #4]
    strh r0, [r4]
    movs r0, #3
    ldrb r2, [r1, #8]
    ands r2, r0
    lsls r2, r2, #2
    ldrb r0, [r4, #0xb]
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #0xb]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    bl sub_08068a58
    lsls r0, r0, #6
    ldrb r2, [r4, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r0
    strb r1, [r4, #0xb]
    adds r5, #1
    adds r4, #0x10
    cmp r5, r6
    blt lbl_08068ba2
lbl_08068bea:
    movs r0, #1
    bl sub_08068dbc
    ldr r0, lbl_08068c18 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x5c
    ldrh r2, [r3]
    movs r4, #0x80
    lsls r4, r4, #8
    adds r0, r4, #0
    orrs r0, r2
    strh r0, [r3]
    ldr r0, lbl_08068c1c @ =0x00000403
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    b lbl_08068d94
    .align 2, 0
lbl_08068c14: .4byte 0x0840d10c
lbl_08068c18: .4byte sNonGameplayRamPointer
lbl_08068c1c: .4byte 0x00000403
lbl_08068c20:
    movs r1, #1
    mov r8, r1
    movs r5, #0
    subs r7, r6, #1
    cmp r5, r7
    blt lbl_08068c2e
    b lbl_08068d94
lbl_08068c2e:
    ldr r6, lbl_08068c70 @ =0x0840d10c
lbl_08068c30:
    ldrb r1, [r4, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068c62
    ldrh r2, [r4, #2]
    movs r3, #2
    ldrsh r0, [r4, r3]
    ldrh r1, [r6, #2]
    mov ip, r1
    movs r3, #2
    ldrsh r1, [r6, r3]
    cmp r0, r1
    beq lbl_08068c62
    movs r0, #0
    mov r8, r0
    adds r0, r2, #0
    subs r0, #0x40
    strh r0, [r4, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, r1
    bge lbl_08068c62
    mov r1, ip
    strh r1, [r4, #2]
lbl_08068c62:
    adds r6, #0x10
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068c30
    b lbl_08068d94
    .align 2, 0
lbl_08068c70: .4byte 0x0840d10c
lbl_08068c74:
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r4, #0xb]
    adds r4, #0x10
    movs r5, #1
    subs r7, r6, #1
    cmp r5, r7
    blt lbl_08068c88
    b lbl_08068d94
lbl_08068c88:
    ldr r0, lbl_08068cc0 @ =0x0840d10c
    adds r2, r0, #0
    adds r2, #0x1a
    movs r3, #0xc0
lbl_08068c90:
    ldrb r1, [r4, #0xb]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068cb2
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r4, #0xb]
    ldrb r0, [r4, #0xa]
    adds r0, #1
    strb r0, [r4, #0xa]
    ldrh r0, [r2]
    strh r0, [r4, #2]
    ldrh r0, [r2, #2]
    strh r0, [r4]
lbl_08068cb2:
    adds r2, #0x10
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068c90
    b lbl_08068d94
    .align 2, 0
lbl_08068cc0: .4byte 0x0840d10c
lbl_08068cc4:
    movs r5, #0
    subs r7, r6, #1
    cmp r5, r7
    bge lbl_08068d94
    movs r3, #0xd
    rsbs r3, r3, #0
    movs r2, #0
lbl_08068cd2:
    ldrb r1, [r4, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068cfc
    adds r0, r3, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r4, #0xb]
    cmp r5, #0
    beq lbl_08068cfc
    ldrb r0, [r4, #0xa]
    adds r0, #1
    strb r0, [r4, #0xa]
    strb r2, [r4, #8]
    ldrb r0, [r4, #9]
    cmp r0, #0
    beq lbl_08068cfc
    subs r0, #1
    strb r0, [r4, #9]
lbl_08068cfc:
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068cd2
    b lbl_08068d94
lbl_08068d06:
    ldr r0, [r5]
    ldr r2, lbl_08068da0 @ =0x00000133
    adds r3, r0, r2
    ldrb r2, [r3]
    movs r1, #0x3f
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r4, lbl_08068da4 @ =0x00000143
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068da8 @ =0x00000153
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068dac @ =0x00000173
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068db0 @ =0x00000193
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r2, [r5]
    adds r4, r2, #0
    adds r4, #0x5c
    ldrh r3, [r4]
    ldr r0, lbl_08068db4 @ =0x00007fff
    ands r0, r3
    strh r0, [r4]
    ldr r0, lbl_08068db8 @ =0x00000403
    adds r2, r2, r0
    ldrb r0, [r2]
    ands r1, r0
    movs r0, #0x80
    orrs r1, r0
    strb r1, [r2]
lbl_08068d94:
    mov r0, r8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08068da0: .4byte 0x00000133
lbl_08068da4: .4byte 0x00000143
lbl_08068da8: .4byte 0x00000153
lbl_08068dac: .4byte 0x00000173
lbl_08068db0: .4byte 0x00000193
lbl_08068db4: .4byte 0x00007fff
lbl_08068db8: .4byte 0x00000403

    thumb_func_start sub_08068dbc
sub_08068dbc: @ 0x08068dbc
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #2
    bne lbl_08068de0
    ldr r3, lbl_08068ddc @ =sNonGameplayRamPointer
    ldr r2, [r3]
    ldrb r1, [r2, #0xc]
    cmp r1, #0
    bne lbl_08068eb0
    movs r0, #1
    strb r0, [r2, #0xc]
    ldr r0, [r3]
    strh r1, [r0, #0xe]
    b lbl_08068eb0
    .align 2, 0
lbl_08068ddc: .4byte sNonGameplayRamPointer
lbl_08068de0:
    ldr r0, lbl_08068e6c @ =gEquipment
    ldrb r2, [r0, #0x12]
    movs r1, #0x2c
    adds r4, r0, #0
    cmp r2, #0
    beq lbl_08068dfa
    movs r1, #0x2d
    cmp r2, #1
    beq lbl_08068dfa
    movs r1, #0x2c
    cmp r2, #2
    bne lbl_08068dfa
    movs r1, #0x2e
lbl_08068dfa:
    cmp r3, #0
    bne lbl_08068e0c
    ldr r0, lbl_08068e70 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08068e0c
    movs r1, #0x2e
lbl_08068e0c:
    ldr r2, lbl_08068e74 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    movs r3, #0xc9
    lsls r3, r3, #1
    adds r0, r0, r3
    strb r1, [r0]
    ldr r0, [r2]
    ldr r1, lbl_08068e78 @ =0x00000193
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    mov r5, ip
    strb r0, [r5]
    ldr r0, [r2]
    movs r6, #0xcc
    lsls r6, r6, #1
    adds r1, r0, r6
    movs r7, #0xc4
    lsls r7, r7, #1
    adds r0, r0, r7
    ldm r0!, {r5, r6, r7}
    stm r1!, {r5, r6, r7}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r2]
    ldr r1, lbl_08068e7c @ =0x000001a3
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    mov r5, ip
    strb r0, [r5]
    movs r1, #0
    ldr r0, [r2]
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0x2e
    bne lbl_08068e80
    movs r1, #3
    b lbl_08068e98
    .align 2, 0
lbl_08068e6c: .4byte gEquipment
lbl_08068e70: .4byte gPauseScreenFlag
lbl_08068e74: .4byte sNonGameplayRamPointer
lbl_08068e78: .4byte 0x00000193
lbl_08068e7c: .4byte 0x000001a3
lbl_08068e80:
    ldrb r2, [r4, #0xf]
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_08068e8e
    movs r1, #2
    b lbl_08068e98
lbl_08068e8e:
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_08068e98
    movs r1, #1
lbl_08068e98:
    lsls r1, r1, #5
    ldr r0, lbl_08068eb8 @ =0x083fd310
    adds r1, r1, r0
    ldr r0, lbl_08068ebc @ =0x08754bbc
    ldr r2, [r0]
    adds r2, #0x80
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_08068eb0:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068eb8: .4byte 0x083fd310
lbl_08068ebc: .4byte 0x08754bbc

    thumb_func_start sub_08068ec0
sub_08068ec0: @ 0x08068ec0
    push {lr}
    ldr r2, lbl_08068ee0 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    ldrh r0, [r1, #0xe]
    adds r0, #1
    strh r0, [r1, #0xe]
    ldrb r0, [r1, #0xc]
    adds r3, r2, #0
    cmp r0, #6
    bls lbl_08068ed6
    b lbl_08068fc4
lbl_08068ed6:
    lsls r0, r0, #2
    ldr r1, lbl_08068ee4 @ =lbl_08068ee8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068ee0: .4byte sNonGameplayRamPointer
lbl_08068ee4: .4byte lbl_08068ee8
lbl_08068ee8: @ jump table
    .4byte lbl_08068fc4 @ case 0
    .4byte lbl_08068f04 @ case 1
    .4byte lbl_08068f28 @ case 2
    .4byte lbl_08068f4c @ case 3
    .4byte lbl_08068f64 @ case 4
    .4byte lbl_08068f72 @ case 5
    .4byte lbl_08068fb0 @ case 6
lbl_08068f04:
    ldr r2, [r3]
    adds r3, r2, #0
    adds r3, #0x66
    ldrh r1, [r3]
    ldr r0, lbl_08068f20 @ =0x0000fffb
    ands r0, r1
    strh r0, [r3]
    ldr r1, lbl_08068f24 @ =0x0400004b
    movs r0, #0xd0
    strb r0, [r1]
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
    b lbl_08068fc4
    .align 2, 0
lbl_08068f20: .4byte 0x0000fffb
lbl_08068f24: .4byte 0x0400004b
lbl_08068f28:
    ldr r1, lbl_08068f44 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08068f34
    adds r0, #2
    strh r0, [r1]
lbl_08068f34:
    ldrh r0, [r1]
    cmp r0, #0x10
    bls lbl_08068f3e
    movs r0, #0x10
    strh r0, [r1]
lbl_08068f3e:
    ldr r2, lbl_08068f48 @ =gWrittenToBLDALPHA_L
    b lbl_08068f8a
    .align 2, 0
lbl_08068f44: .4byte gWrittenToBLDALPHA_H
lbl_08068f48: .4byte gWrittenToBLDALPHA_L
lbl_08068f4c:
    movs r0, #1
    bl sub_08068dbc
    ldr r3, lbl_08068f60 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1, #0xc]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #0xc]
    b lbl_08068fa2
    .align 2, 0
lbl_08068f60: .4byte sNonGameplayRamPointer
lbl_08068f64:
    ldr r1, [r3]
    ldrb r0, [r1, #0xc]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #0xc]
    ldr r0, [r3]
    strh r2, [r0, #0xe]
lbl_08068f72:
    ldr r1, lbl_08068fa8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08068f7e
    adds r0, #2
    strh r0, [r1]
lbl_08068f7e:
    ldrh r0, [r1]
    cmp r0, #0x10
    bls lbl_08068f88
    movs r0, #0x10
    strh r0, [r1]
lbl_08068f88:
    ldr r2, lbl_08068fac @ =gWrittenToBLDALPHA_H
lbl_08068f8a:
    ldrh r1, [r1]
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    bne lbl_08068fc4
    ldr r0, [r3]
    ldrb r1, [r0, #0xc]
    adds r1, #1
    strb r1, [r0, #0xc]
lbl_08068fa2:
    ldr r0, [r3]
    strh r2, [r0, #0xe]
    b lbl_08068fc4
    .align 2, 0
lbl_08068fa8: .4byte gWrittenToBLDALPHA_L
lbl_08068fac: .4byte gWrittenToBLDALPHA_H
lbl_08068fb0:
    ldr r2, [r3]
    adds r1, r2, #0
    adds r1, #0x66
    movs r3, #0
    ldr r0, lbl_08068fc8 @ =0x00003c44
    strh r0, [r1]
    ldr r1, lbl_08068fcc @ =0x0400004b
    movs r0, #0x18
    strb r0, [r1]
    strb r3, [r2, #0xc]
lbl_08068fc4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068fc8: .4byte 0x00003c44
lbl_08068fcc: .4byte 0x0400004b

    thumb_func_start PauseScreenUpdateWorldMapHighlight
PauseScreenUpdateWorldMapHighlight: @ 0x08068fd0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #6
    bls lbl_08068fdc
    movs r4, #7
lbl_08068fdc:
    ldr r5, lbl_08069018 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    movs r1, #0x85
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, lbl_0806901c @ =0x0840d090
    lsls r4, r4, #3
    adds r4, r4, r1
    ldrb r1, [r4, #1]
    bl UpdateMenuOamDataID
    ldr r0, [r5]
    movs r6, #0x89
    lsls r6, r6, #3
    adds r0, r0, r6
    ldrb r1, [r4, #2]
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    ldrh r2, [r4, #4]
    ldr r3, lbl_08069020 @ =0x0000044a
    adds r0, r1, r3
    strh r2, [r0]
    ldrh r0, [r4, #6]
    adds r1, r1, r6
    strh r0, [r1]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069018: .4byte sNonGameplayRamPointer
lbl_0806901c: .4byte 0x0840d090
lbl_08069020: .4byte 0x0000044a

    thumb_func_start PauseScreenUpdateWorldMap
PauseScreenUpdateWorldMap: @ 0x08069024
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    cmp r0, #0
    bne lbl_08069124
    ldr r1, lbl_08069110 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    movs r2, #0x95
    lsls r2, r2, #3
    adds r3, r0, r2
    ldrb r0, [r3, #0xb]
    movs r5, #4
    rsbs r5, r5, #0
    adds r2, r5, #0
    ands r2, r0
    movs r0, #2
    orrs r2, r0
    strb r2, [r3, #0xb]
    ldr r0, lbl_08069114 @ =gEquipment
    ldrb r0, [r0, #0x12]
    movs r4, #0x10
    mov r8, r1
    cmp r0, #2
    bne lbl_08069060
    movs r4, #0x11
lbl_08069060:
    strb r4, [r3, #0xa]
    movs r0, #0x3f
    ands r2, r0
    movs r0, #0x40
    orrs r2, r0
    strb r2, [r3, #0xb]
    mov r7, r8
    ldr r0, [r7]
    movs r1, #0x97
    lsls r1, r1, #3
    adds r3, r0, r1
    ldr r2, lbl_08069118 @ =0x0840d188
    mov sb, r2
    ldr r7, lbl_0806911c @ =gCurrentArea
    mov sl, r7
    adds r6, r5, #0
    adds r2, #2
    movs r5, #2
    movs r4, #6
lbl_08069086:
    ldrh r0, [r2]
    strh r0, [r3, #2]
    ldrh r0, [r2, #2]
    strh r0, [r3]
    ldrb r1, [r3, #0xb]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strb r0, [r3, #0xb]
    adds r2, #8
    subs r4, #1
    adds r3, #0x10
    cmp r4, #0
    bge lbl_08069086
    mov r1, r8
    ldr r0, [r1]
    movs r2, #0xa5
    lsls r2, r2, #3
    adds r3, r0, r2
    movs r4, #0
    movs r6, #4
    rsbs r6, r6, #0
    ldr r5, lbl_08069120 @ =0x0840d1c0
lbl_080690b4:
    ldrh r0, [r5]
    strh r0, [r3, #2]
    ldrh r0, [r5, #2]
    strh r0, [r3]
    ldrb r0, [r3, #0xb]
    adds r2, r6, #0
    ands r2, r0
    movs r0, #2
    orrs r2, r0
    movs r0, #0x3f
    ands r2, r0
    strb r2, [r3, #0xb]
    mov r7, r8
    ldr r0, [r7]
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080690f2
    movs r0, #2
    ldrsh r1, [r3, r0]
    movs r7, #0
    ldrsh r0, [r3, r7]
    cmn r1, r0
    beq lbl_080690f2
    movs r1, #0x40
    adds r0, r2, #0
    orrs r0, r1
    strb r0, [r3, #0xb]
lbl_080690f2:
    ldrb r1, [r3, #0xb]
    movs r0, #0xc0
    ands r0, r1
    movs r1, #0
    cmp r0, #0
    beq lbl_08069100
    movs r1, #0xf
lbl_08069100:
    strb r1, [r3, #0xa]
    adds r5, #4
    adds r4, #1
    adds r3, #0x10
    cmp r4, #0xf
    ble lbl_080690b4
    b lbl_08069182
    .align 2, 0
lbl_08069110: .4byte sNonGameplayRamPointer
lbl_08069114: .4byte gEquipment
lbl_08069118: .4byte 0x0840d188
lbl_0806911c: .4byte gCurrentArea
lbl_08069120: .4byte 0x0840d1c0
lbl_08069124:
    ldr r0, lbl_08069164 @ =sNonGameplayRamPointer
    mov r8, r0
    ldr r1, lbl_08069168 @ =0x0840d188
    mov sb, r1
    ldr r2, lbl_0806916c @ =gCurrentArea
    mov sl, r2
    mov r7, ip
    cmp r7, #2
    bne lbl_08069182
    ldr r0, [r0]
    movs r1, #0xa5
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r4, #0
    movs r2, #0x3f
    mov r5, r8
lbl_08069144:
    ldr r0, [r5]
    adds r0, #0x44
    ldrh r1, [r0]
    asrs r1, r4
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08069170
    movs r0, #0xf
    strb r0, [r3, #0xa]
    ldrb r1, [r3, #0xb]
    adds r0, r2, #0
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    b lbl_08069178
    .align 2, 0
lbl_08069164: .4byte sNonGameplayRamPointer
lbl_08069168: .4byte 0x0840d188
lbl_0806916c: .4byte gCurrentArea
lbl_08069170:
    strb r1, [r3, #0xa]
    ldrb r1, [r3, #0xb]
    adds r0, r2, #0
    ands r0, r1
lbl_08069178:
    strb r0, [r3, #0xb]
    adds r4, #1
    adds r3, #0x10
    cmp r4, #0xf
    ble lbl_08069144
lbl_08069182:
    movs r7, #2
    mov r2, ip
    cmp r2, #0
    bne lbl_0806918c
    movs r7, #1
lbl_0806918c:
    mov r1, r8
    ldr r0, [r1]
    movs r2, #0x97
    lsls r2, r2, #3
    adds r3, r0, r2
    movs r4, #0
    mov r6, r8
    ldr r5, lbl_080691a8 @ =0x0840d188
lbl_0806919c:
    ldr r0, [r6]
    ldrb r0, [r0, #0x12]
    cmp r0, r4
    beq lbl_080691ac
    ldrb r0, [r5]
    b lbl_080691ae
    .align 2, 0
lbl_080691a8: .4byte 0x0840d188
lbl_080691ac:
    ldrb r0, [r5, #1]
lbl_080691ae:
    strb r0, [r3, #0xa]
    ldr r0, [r6]
    adds r0, #0xba
    ldrb r1, [r0]
    asrs r1, r4
    movs r0, #1
    ands r1, r0
    movs r2, #0
    cmp r1, #0
    beq lbl_080691c4
    adds r2, r7, #0
lbl_080691c4:
    lsls r2, r2, #6
    ldrb r1, [r3, #0xb]
    movs r0, #0x3f
    ands r0, r1
    orrs r0, r2
    strb r0, [r3, #0xb]
    adds r5, #8
    adds r4, #1
    adds r3, #0x10
    cmp r4, #6
    ble lbl_0806919c
    mov r7, r8
    ldr r0, [r7]
    movs r1, #0x95
    lsls r1, r1, #3
    adds r3, r0, r1
    mov r2, sl
    ldrb r0, [r2]
    lsls r0, r0, #3
    add r0, sb
    ldrh r0, [r0, #2]
    strh r0, [r3, #2]
    ldrb r0, [r2]
    lsls r0, r0, #3
    add r0, sb
    ldrh r0, [r0, #4]
    subs r0, #0x18
    strh r0, [r3]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0806920c
sub_0806920c: @ 0x0806920c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, lbl_080692a8 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r3, r0, r2
    adds r7, r1, #0
    ldr r4, lbl_080692ac @ =0x0840d028
    mov r8, r4
    movs r5, #0x16
lbl_08069224:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069224
    ldr r0, [r7]
    movs r6, #0x85
    lsls r6, r6, #3
    adds r3, r0, r6
    movs r5, #3
lbl_08069242:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069242
    ldr r0, [r7]
    movs r1, #0x8d
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r5, #3
lbl_08069260:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069260
    ldr r0, [r7]
    movs r1, #0x95
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r5, #0x17
lbl_0806927e:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_0806927e
    ldr r2, [r7]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080692b0
    movs r0, #0
    bl sub_08068af8
    b lbl_08069578
    .align 2, 0
lbl_080692a8: .4byte sNonGameplayRamPointer
lbl_080692ac: .4byte 0x0840d028
lbl_080692b0:
    ldr r0, lbl_08069340 @ =gEquipment
    ldrb r0, [r0, #0x12]
    movs r1, #2
    cmp r0, #2
    beq lbl_080692bc
    movs r1, #1
lbl_080692bc:
    ldr r3, lbl_08069344 @ =0x00000402
    adds r0, r2, r3
    strb r1, [r0]
    ldr r2, [r7]
    ldr r4, lbl_08069348 @ =0x00000403
    adds r2, r2, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    ldr r0, lbl_0806934c @ =gMinimapX
    ldrb r0, [r0]
    lsls r0, r0, #5
    ldr r6, lbl_08069350 @ =0x000003fa
    adds r1, r2, r6
    strh r0, [r1]
    ldr r0, lbl_08069354 @ =gMinimapY
    ldrb r0, [r0]
    lsls r0, r0, #5
    subs r3, #0xa
    adds r1, r2, r3
    strh r0, [r1]
    adds r4, #1
    adds r2, r2, r4
    ldrb r3, [r2]
    movs r1, #0x10
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r3
    movs r4, #3
    orrs r0, r4
    strb r0, [r2]
    ldr r0, [r7]
    adds r6, #0x1a
    adds r0, r0, r6
    ldrb r2, [r0]
    ands r1, r2
    orrs r1, r4
    strb r1, [r0]
    ldr r3, [r7]
    ldrh r1, [r3]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806935c
    ldr r0, lbl_08069348 @ =0x00000403
    adds r3, r3, r0
    ldrb r2, [r3]
    movs r1, #4
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r4, #1
    orrs r0, r4
    strb r0, [r3]
    ldr r0, [r7]
    ldr r2, lbl_08069358 @ =0x00000413
    adds r0, r0, r2
    ldrb r2, [r0]
    ands r1, r2
    orrs r1, r4
    strb r1, [r0]
    b lbl_08069372
    .align 2, 0
lbl_08069340: .4byte gEquipment
lbl_08069344: .4byte 0x00000402
lbl_08069348: .4byte 0x00000403
lbl_0806934c: .4byte gMinimapX
lbl_08069350: .4byte 0x000003fa
lbl_08069354: .4byte gMinimapY
lbl_08069358: .4byte 0x00000413
lbl_0806935c:
    ldr r6, lbl_080693fc @ =0x00000403
    adds r1, r3, r6
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
    ldr r1, [r7]
    ldr r0, lbl_08069400 @ =0x00000413
    adds r1, r1, r0
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
lbl_08069372:
    ldr r1, [r7]
    ldrb r0, [r1, #4]
    cmp r0, #1
    beq lbl_08069396
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    movs r1, #0
    strb r1, [r0]
    ldr r2, [r7]
    movs r3, #0x84
    lsls r3, r3, #1
    adds r0, r2, r3
    strh r1, [r0]
    movs r4, #0x85
    lsls r4, r4, #1
    adds r0, r2, r4
    strh r1, [r0]
lbl_08069396:
    ldr r2, [r7]
    ldrh r1, [r2]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08069418
    ldr r1, lbl_08069404 @ =0x0840d180
    ldrb r0, [r2, #0x12]
    adds r0, r0, r1
    ldrb r1, [r0]
    ldr r6, lbl_08069408 @ =0x00000432
    adds r0, r2, r6
    strb r1, [r0]
    ldr r1, [r7]
    ldr r3, lbl_0806940c @ =0x0840d17c
    ldrh r2, [r3, #2]
    movs r4, #0x85
    lsls r4, r4, #3
    adds r0, r1, r4
    strh r2, [r0]
    ldrh r2, [r3]
    subs r6, #8
    adds r0, r1, r6
    strh r2, [r0]
    ldr r3, lbl_08069410 @ =0x00000433
    adds r1, r1, r3
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r2, [r7]
    ldr r0, lbl_08069414 @ =0x00000434
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    b lbl_08069502
    .align 2, 0
lbl_080693fc: .4byte 0x00000403
lbl_08069400: .4byte 0x00000413
lbl_08069404: .4byte 0x0840d180
lbl_08069408: .4byte 0x00000432
lbl_0806940c: .4byte 0x0840d17c
lbl_08069410: .4byte 0x00000433
lbl_08069414: .4byte 0x00000434
lbl_08069418:
    movs r0, #0x20
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_08069474
    ldr r1, lbl_08069464 @ =gCurrentArea
    ldrb r0, [r1]
    movs r5, #7
    cmp r0, #6
    bhi lbl_08069430
    adds r5, r0, #0
lbl_08069430:
    movs r4, #0x85
    lsls r4, r4, #3
    adds r0, r2, r4
    ldr r2, lbl_08069468 @ =0x0840d090
    lsls r1, r5, #3
    adds r1, r1, r2
    ldrb r1, [r1]
    bl UpdateMenuOamDataID
    ldr r1, [r7]
    adds r4, r1, r4
    movs r0, #0xc
    strh r0, [r4]
    ldr r3, lbl_0806946c @ =0x0000042a
    adds r2, r1, r3
    movs r0, #0xe8
    lsls r0, r0, #1
    strh r0, [r2]
    ldr r4, lbl_08069470 @ =0x00000433
    adds r1, r1, r4
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    b lbl_08069502
    .align 2, 0
lbl_08069464: .4byte gCurrentArea
lbl_08069468: .4byte 0x0840d090
lbl_0806946c: .4byte 0x0000042a
lbl_08069470: .4byte 0x00000433
lbl_08069474:
    ldr r6, lbl_08069584 @ =0x00000442
    adds r0, r2, r6
    strb r1, [r0]
    ldr r1, [r7]
    movs r0, #0x87
    lsls r0, r0, #3
    adds r2, r1, r0
    movs r3, #0
    mov r8, r3
    movs r0, #0x18
    strh r0, [r2]
    ldr r4, lbl_08069588 @ =0x0000043a
    adds r0, r1, r4
    movs r6, #0xe8
    lsls r6, r6, #1
    strh r6, [r0]
    ldr r0, lbl_0806958c @ =0x00000443
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    movs r5, #1
    orrs r0, r5
    strb r0, [r1]
    ldr r0, lbl_08069590 @ =gCurrentArea
    ldrb r0, [r0]
    bl PauseScreenUpdateWorldMapHighlight
    ldr r1, [r7]
    movs r3, #0x85
    lsls r3, r3, #3
    adds r2, r1, r3
    movs r0, #0xc
    strh r0, [r2]
    ldr r2, lbl_08069594 @ =0x0000042a
    adds r0, r1, r2
    strh r6, [r0]
    adds r3, #0xb
    adds r1, r1, r3
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strb r0, [r1]
    ldr r0, [r7]
    ldr r6, lbl_08069598 @ =0x00000453
    adds r0, r0, r6
    ldrb r1, [r0]
    ands r4, r1
    orrs r4, r5
    strb r4, [r0]
    ldr r0, [r7]
    ldr r1, lbl_0806959c @ =0x00000462
    adds r0, r0, r1
    mov r2, r8
    strb r2, [r0]
    ldr r1, [r7]
    adds r3, #0x25
    adds r2, r1, r3
    movs r0, #0xcc
    lsls r0, r0, #1
    strh r0, [r2]
    ldr r4, lbl_080695a0 @ =0x0000045a
    adds r1, r1, r4
    adds r0, #0x88
    strh r0, [r1]
    movs r0, #0
    bl PauseScreenUpdateWorldMap
lbl_08069502:
    movs r0, #0
    bl draw_pause_screen_info
    ldr r7, lbl_080695a4 @ =sNonGameplayRamPointer
    ldr r6, lbl_080695a8 @ =0x0840d0d0
    ldr r0, lbl_080695ac @ =0x00000473
    mov r8, r0
    ldr r1, lbl_080695b0 @ =gPauseScreenFlag
    mov ip, r1
    adds r4, r6, #0
    adds r4, #0x20
    movs r5, #0x20
lbl_0806951a:
    subs r4, #8
    subs r5, #8
    mov r2, ip
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r0, #2
    bne lbl_0806953e
    ldr r2, [r7]
    ldrh r0, [r4]
    lsls r0, r0, #4
    adds r2, r2, r0
    add r2, r8
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_0806953e:
    ldr r1, [r7]
    ldrh r3, [r4]
    lsls r3, r3, #4
    adds r1, r1, r3
    adds r0, r6, #2
    adds r0, r5, r0
    ldrh r0, [r0]
    ldr r2, lbl_080695b4 @ =0x00000472
    adds r1, r1, r2
    strb r0, [r1]
    ldr r2, [r7]
    adds r2, r2, r3
    adds r0, r6, #4
    adds r0, r5, r0
    ldrh r1, [r0]
    ldr r3, lbl_080695b8 @ =0x0000046a
    adds r0, r2, r3
    strh r1, [r0]
    ldrh r1, [r4, #6]
    subs r3, #2
    adds r0, r2, r3
    strh r1, [r0]
    add r2, r8
    ldrb r0, [r2]
    movs r1, #3
    orrs r0, r1
    strb r0, [r2]
    cmp r4, r6
    bgt lbl_0806951a
lbl_08069578:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069584: .4byte 0x00000442
lbl_08069588: .4byte 0x0000043a
lbl_0806958c: .4byte 0x00000443
lbl_08069590: .4byte gCurrentArea
lbl_08069594: .4byte 0x0000042a
lbl_08069598: .4byte 0x00000453
lbl_0806959c: .4byte 0x00000462
lbl_080695a0: .4byte 0x0000045a
lbl_080695a4: .4byte sNonGameplayRamPointer
lbl_080695a8: .4byte 0x0840d0d0
lbl_080695ac: .4byte 0x00000473
lbl_080695b0: .4byte gPauseScreenFlag
lbl_080695b4: .4byte 0x00000472
lbl_080695b8: .4byte 0x0000046a

    thumb_func_start sub_080695bc
sub_080695bc: @ 0x080695bc
    push {r4, lr}
    ldr r1, lbl_080695f0 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r4, lbl_080695f4 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    movs r0, #0x85
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080695f8 @ =0x0840d3ec
    movs r0, #4
    bl process_menu_oam
    ldr r1, [r4]
    ldrb r0, [r1, #0x11]
    cmp r0, #0
    beq lbl_08069600
    movs r0, #0x95
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080695fc @ =0x0840d5dc
    movs r0, #0x18
    bl process_menu_oam
    b lbl_0806960e
    .align 2, 0
lbl_080695f0: .4byte gNextOamSlot
lbl_080695f4: .4byte sNonGameplayRamPointer
lbl_080695f8: .4byte 0x0840d3ec
lbl_080695fc: .4byte 0x0840d5dc
lbl_08069600:
    movs r0, #0x8d
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_08069690 @ =0x0840d4f4
    movs r0, #4
    bl process_menu_oam
lbl_0806960e:
    ldr r4, lbl_08069694 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    movs r0, #0x84
    lsls r0, r0, #1
    adds r1, r1, r0
    ldr r2, lbl_08069698 @ =0x0840d22c
    movs r0, #0x17
    bl process_menu_oam
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806963a
    movs r0, #0xea
    lsls r0, r0, #2
    adds r1, r2, r0
    ldr r2, lbl_0806969c @ =0x0840d55c
    movs r0, #5
    bl process_menu_oam
lbl_0806963a:
    ldr r2, [r4]
    ldrb r0, [r2, #0x11]
    cmp r0, #0
    bne lbl_08069684
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08069684
    ldr r1, lbl_080696a0 @ =gCurrentArea
    ldrb r0, [r2, #0x12]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08069664
    movs r0, #0xfe
    lsls r0, r0, #2
    adds r1, r2, r0
    ldr r2, lbl_080696a4 @ =0x0840d51c
    movs r0, #1
    bl process_menu_oam
lbl_08069664:
    ldr r1, [r4]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r1, r1, r0
    ldr r2, lbl_0806969c @ =0x0840d55c
    movs r0, #0xc
    bl process_menu_oam
    ldr r1, [r4]
    movs r0, #0x81
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080696a8 @ =0x0840d534
    movs r0, #1
    bl process_menu_oam
lbl_08069684:
    bl ResetFreeOAM
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069690: .4byte 0x0840d4f4
lbl_08069694: .4byte sNonGameplayRamPointer
lbl_08069698: .4byte 0x0840d22c
lbl_0806969c: .4byte 0x0840d55c
lbl_080696a0: .4byte gCurrentArea
lbl_080696a4: .4byte 0x0840d51c
lbl_080696a8: .4byte 0x0840d534

    thumb_func_start process_menu_oam
process_menu_oam: @ 0x080696ac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    adds r3, r1, #0
    str r2, [sp, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    ldr r0, lbl_08069740 @ =gOamData
    mov sb, r0
    ldr r1, lbl_08069744 @ =gNextOamSlot
    ldrb r2, [r1]
    str r2, [sp, #8]
    mov sl, r2
    lsls r0, r2, #3
    add sb, r0
    movs r0, #0
    str r0, [sp, #0xc]
    ldr r1, [sp]
    cmp r0, r1
    blt lbl_080696de
    b lbl_080699de
lbl_080696de:
    ldrb r0, [r3, #0xa]
    adds r6, r0, #0
    cmp r6, #0
    bne lbl_080696e8
    b lbl_080699ce
lbl_080696e8:
    ldrb r1, [r3, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_080696f4
    b lbl_080699ce
lbl_080696f4:
    cmp r0, #0x80
    bne lbl_08069708
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r3, #0xb]
    movs r0, #0
    strb r0, [r3, #8]
    strb r0, [r3, #9]
lbl_08069708:
    ldrb r1, [r3, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r3, #0xb]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #4]
    adds r4, r0, r2
    ldr r5, [r4]
    ldrb r2, [r3, #9]
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r1, [r3, #8]
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_0806972c
    b lbl_08069880
lbl_0806972c:
    ldrb r0, [r4, #4]
    cmp r0, #9
    bls lbl_08069734
    b lbl_08069880
lbl_08069734:
    lsls r0, r0, #2
    ldr r1, lbl_08069748 @ =lbl_0806974c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069740: .4byte gOamData
lbl_08069744: .4byte gNextOamSlot
lbl_08069748: .4byte lbl_0806974c
lbl_0806974c: @ jump table
    .4byte lbl_08069880 @ case 0
    .4byte lbl_08069774 @ case 1
    .4byte lbl_0806978e @ case 2
    .4byte lbl_08069794 @ case 3
    .4byte lbl_080697c2 @ case 4
    .4byte lbl_080697de @ case 5
    .4byte lbl_08069804 @ case 6
    .4byte lbl_0806981e @ case 7
    .4byte lbl_08069844 @ case 8
    .4byte lbl_0806985e @ case 9
lbl_08069774:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    strb r0, [r3, #9]
    b lbl_08069880
lbl_0806978e:
    movs r0, #0
    strb r0, [r3, #8]
    b lbl_08069880
lbl_08069794:
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    adds r0, r2, #1
    movs r4, #0
    strb r0, [r3, #9]
    ldrb r2, [r3, #9]
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080697be
    subs r0, r2, #1
    strb r0, [r3, #9]
    subs r0, r1, #1
    strb r0, [r3, #8]
    ldrb r0, [r3, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r3, #0xb]
    b lbl_08069880
lbl_080697be:
    strb r4, [r3, #8]
    b lbl_08069880
lbl_080697c2:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    strb r0, [r3, #0xa]
    strb r0, [r3, #9]
    b lbl_08069854
lbl_080697de:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069880
    adds r0, r6, #1
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #4]
    adds r0, r0, r1
    b lbl_0806987e
lbl_08069804:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r1, [r3, #9]
    adds r0, r1, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    adds r0, r6, #1
    b lbl_08069872
lbl_0806981e:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069880
    subs r0, r6, #1
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #4]
    adds r0, r0, r1
    b lbl_0806987e
lbl_08069844:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_0806986a
    strb r1, [r3, #0xa]
    strb r1, [r3, #9]
lbl_08069854:
    ldrb r1, [r3, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r3, #0xb]
    b lbl_080699ce
lbl_0806985e:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069870
lbl_0806986a:
    subs r0, #1
    strb r0, [r3, #9]
    b lbl_08069880
lbl_08069870:
    subs r0, r6, #1
lbl_08069872:
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #4]
    adds r0, r0, r2
lbl_0806987e:
    ldr r5, [r0]
lbl_08069880:
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    ldrb r1, [r3, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069892
    b lbl_080699ce
lbl_08069892:
    ldrb r0, [r3, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_080698b4
    ldr r0, lbl_080698ac @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698b0 @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698ac: .4byte gBG0HOFS_NonGameplay
lbl_080698b0: .4byte gBG0VOFS_NonGameplay
lbl_080698b4:
    cmp r1, #1
    bne lbl_080698d0
    ldr r0, lbl_080698c8 @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698cc @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698c8: .4byte gBG1HOFS_NonGameplay
lbl_080698cc: .4byte gBG1VOFS_NonGameplay
lbl_080698d0:
    cmp r1, #2
    bne lbl_080698ec
    ldr r0, lbl_080698e4 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698e8 @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698e4: .4byte gBG2HOFS_NonGameplay
lbl_080698e8: .4byte gBG2VOFS_NonGameplay
lbl_080698ec:
    cmp r1, #3
    bne lbl_08069908
    ldr r0, lbl_08069900 @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_08069904 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_08069900: .4byte gBG3HOFS_NonGameplay
lbl_08069904: .4byte gBG3VOFS_NonGameplay
lbl_08069908:
    movs r7, #0
    movs r6, #0
lbl_0806990c:
    ldrh r0, [r3]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r6, #2
    subs r0, r0, r1
    ldr r1, lbl_080699f8 @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r6, r1, r0
    ldrh r0, [r3, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_080699fc @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r5, r5, r0
    ldr r4, [r5]
    ldrh r0, [r4]
    ldr r1, [sp, #8]
    adds r0, r1, r0
    cmp r0, #0x7f
    bgt lbl_080699de
    str r0, [sp, #8]
    adds r4, #2
    cmp sl, r0
    bge lbl_080699ce
    movs r2, #3
    mov ip, r2
    movs r0, #0xd
    rsbs r0, r0, #0
    mov r8, r0
    ldr r1, lbl_08069a00 @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r5, r0, r1
lbl_08069960:
    ldrh r1, [r4]
    adds r4, #2
    mov r0, sb
    strh r1, [r0]
    movs r2, #2
    add sb, r2
    adds r0, r1, r6
    strb r0, [r5]
    ldrh r1, [r4]
    adds r4, #2
    mov r0, sb
    strh r1, [r0]
    add sb, r2
    adds r1, r1, r7
    ldr r0, lbl_08069a04 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r5, #2]
    ldr r0, lbl_08069a08 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r5, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    ldrb r1, [r3, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    mov r2, ip
    ands r1, r2
    lsls r1, r1, #2
    ldrb r2, [r5, #5]
    mov r0, r8
    ands r0, r2
    orrs r0, r1
    strb r0, [r5, #5]
    ldrb r1, [r3, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    mov r0, ip
    ands r1, r0
    lsls r1, r1, #2
    ldrb r2, [r5, #1]
    mov r0, r8
    ands r0, r2
    orrs r0, r1
    strb r0, [r5, #1]
    movs r1, #4
    add sb, r1
    adds r5, #8
    movs r2, #1
    add sl, r2
    ldr r0, [sp, #8]
    cmp sl, r0
    blt lbl_08069960
lbl_080699ce:
    ldr r1, [sp, #0xc]
    adds r1, #1
    str r1, [sp, #0xc]
    adds r3, #0x10
    ldr r2, [sp]
    cmp r1, r2
    bge lbl_080699de
    b lbl_080696de
lbl_080699de:
    mov r0, sp
    ldrb r1, [r0, #8]
    ldr r0, lbl_08069a0c @ =gNextOamSlot
    strb r1, [r0]
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080699f8: .4byte gOamYOffset_NonGameplay
lbl_080699fc: .4byte gOamXOffset_NonGameplay
lbl_08069a00: .4byte gOamData
lbl_08069a04: .4byte 0x000001ff
lbl_08069a08: .4byte 0xfffffe00
lbl_08069a0c: .4byte gNextOamSlot

    thumb_func_start ProcessComplexMenuOam
ProcessComplexMenuOam: @ 0x08069a10
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r5, r1, #0
    str r2, [sp, #0x10]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0xc]
    ldr r0, lbl_08069aa4 @ =gOamData
    mov sb, r0
    ldr r0, lbl_08069aa8 @ =gNextOamSlot
    ldrb r0, [r0]
    str r0, [sp, #0x14]
    mov sl, r0
    lsls r0, r0, #3
    add sb, r0
    movs r1, #0
    str r1, [sp, #0x18]
    ldr r2, [sp, #0xc]
    cmp r1, r2
    blt lbl_08069a42
    b lbl_08069da2
lbl_08069a42:
    ldrb r0, [r5, #0xa]
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_08069a4c
    b lbl_08069d92
lbl_08069a4c:
    ldrb r1, [r5, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_08069a58
    b lbl_08069d92
lbl_08069a58:
    cmp r0, #0x80
    bne lbl_08069a6c
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r5, #0xb]
    movs r0, #0
    strb r0, [r5, #8]
    strb r0, [r5, #9]
lbl_08069a6c:
    ldrb r1, [r5, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5, #0xb]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r3, r0, r1
    ldr r6, [r3]
    ldrb r2, [r5, #9]
    lsls r0, r2, #3
    adds r0, r0, r6
    ldrb r1, [r5, #8]
    adds r4, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_08069a92
    b lbl_08069be4
lbl_08069a92:
    ldrb r0, [r3, #4]
    cmp r0, #9
    bls lbl_08069a9a
    b lbl_08069be4
lbl_08069a9a:
    lsls r0, r0, #2
    ldr r1, lbl_08069aac @ =lbl_08069ab0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069aa4: .4byte gOamData
lbl_08069aa8: .4byte gNextOamSlot
lbl_08069aac: .4byte lbl_08069ab0
lbl_08069ab0: @ jump table
    .4byte lbl_08069be4 @ case 0
    .4byte lbl_08069ad8 @ case 1
    .4byte lbl_08069af2 @ case 2
    .4byte lbl_08069af8 @ case 3
    .4byte lbl_08069b26 @ case 4
    .4byte lbl_08069b42 @ case 5
    .4byte lbl_08069b5c @ case 6
    .4byte lbl_08069b82 @ case 7
    .4byte lbl_08069ba8 @ case 8
    .4byte lbl_08069bc2 @ case 9
lbl_08069ad8:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    strb r0, [r5, #9]
    b lbl_08069be4
lbl_08069af2:
    movs r0, #0
    strb r0, [r5, #8]
    b lbl_08069be4
lbl_08069af8:
    lsls r0, r4, #3
    adds r0, r0, r6
    ldrb r2, [r0, #4]
    adds r0, r4, #1
    movs r3, #0
    strb r0, [r5, #9]
    ldrb r1, [r5, #9]
    lsls r0, r1, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069b22
    subs r0, r1, #1
    strb r0, [r5, #9]
    subs r0, r2, #1
    strb r0, [r5, #8]
    ldrb r0, [r5, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069be4
lbl_08069b22:
    strb r3, [r5, #8]
    b lbl_08069be4
lbl_08069b26:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    strb r0, [r5, #0xa]
    strb r0, [r5, #9]
    b lbl_08069bb8
lbl_08069b42:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069be4
    adds r0, r7, #1
    b lbl_08069bd6
lbl_08069b5c:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r1, [r5, #9]
    adds r0, r1, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    adds r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r3, [sp, #0x10]
    adds r0, r0, r3
    b lbl_08069be2
lbl_08069b82:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069be4
    subs r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r0, r0, r1
    b lbl_08069be2
lbl_08069ba8:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08069bce
    strb r1, [r5, #0xa]
    strb r1, [r5, #9]
lbl_08069bb8:
    ldrb r1, [r5, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069d92
lbl_08069bc2:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069bd4
lbl_08069bce:
    subs r0, #1
    strb r0, [r5, #9]
    b lbl_08069be4
lbl_08069bd4:
    subs r0, r7, #1
lbl_08069bd6:
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #0x10]
    adds r0, r0, r2
lbl_08069be2:
    ldr r6, [r0]
lbl_08069be4:
    ldrb r0, [r5, #8]
    adds r0, #1
    strb r0, [r5, #8]
    ldrb r1, [r5, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069bf6
    b lbl_08069d92
lbl_08069bf6:
    ldrb r0, [r5, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_08069c18
    ldr r0, lbl_08069c10 @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c14 @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c10: .4byte gBG0HOFS_NonGameplay
lbl_08069c14: .4byte gBG0VOFS_NonGameplay
lbl_08069c18:
    cmp r1, #1
    bne lbl_08069c34
    ldr r0, lbl_08069c2c @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c30 @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c2c: .4byte gBG1HOFS_NonGameplay
lbl_08069c30: .4byte gBG1VOFS_NonGameplay
lbl_08069c34:
    cmp r1, #2
    bne lbl_08069c50
    ldr r0, lbl_08069c48 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c4c @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c48: .4byte gBG2HOFS_NonGameplay
lbl_08069c4c: .4byte gBG2VOFS_NonGameplay
lbl_08069c50:
    cmp r1, #3
    bne lbl_08069c6c
    ldr r0, lbl_08069c64 @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c68 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c64: .4byte gBG3HOFS_NonGameplay
lbl_08069c68: .4byte gBG3VOFS_NonGameplay
lbl_08069c6c:
    movs r3, #0
    mov r8, r3
    movs r7, #0
lbl_08069c72:
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_08069d0c @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrh r0, [r5, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    mov r2, r8
    asrs r1, r2, #2
    subs r0, r0, r1
    ldr r1, lbl_08069d10 @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r0
    mov r8, r1
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r6, r6, r0
    ldr r4, [r6]
    ldrh r0, [r4]
    ldr r3, [sp, #0x14]
    adds r0, r3, r0
    cmp r0, #0x7f
    bgt lbl_08069da2
    str r0, [sp, #0x14]
    adds r4, #2
    cmp sl, r0
    bge lbl_08069d92
    ldr r1, lbl_08069d14 @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r6, r0, r1
lbl_08069cc0:
    ldrb r1, [r5, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08069d20
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    movs r0, #2
    add sb, r0
    ldrh r2, [r4]
    adds r4, #2
    mov r1, sb
    strh r2, [r1]
    add sb, r0
    ldrh r0, [r4]
    mov r2, sb
    strh r0, [r2]
    adds r4, #2
    movs r3, #4
    add sb, r3
    ldr r0, lbl_08069d18 @ =gCurrentOamRotation
    ldrh r3, [r0]
    ldr r0, lbl_08069d1c @ =gCurrentOamScaling
    ldrh r0, [r0]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, sl
    mov r1, r8
    adds r2, r7, #0
    bl ProcessComplexOam
    b lbl_08069d58
    .align 2, 0
lbl_08069d0c: .4byte gOamYOffset_NonGameplay
lbl_08069d10: .4byte gOamXOffset_NonGameplay
lbl_08069d14: .4byte gOamData
lbl_08069d18: .4byte gCurrentOamRotation
lbl_08069d1c: .4byte gCurrentOamScaling
lbl_08069d20:
    ldrh r2, [r4]
    adds r4, #2
    mov r0, sb
    strh r2, [r0]
    movs r1, #2
    add sb, r1
    adds r0, r2, r7
    strb r0, [r6]
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    add sb, r1
    add r2, r8
    ldr r0, lbl_08069dbc @ =0x000001ff
    ands r2, r0
    ldrh r0, [r6, #2]
    ldr r3, lbl_08069dc0 @ =0xfffffe00
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r6, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    movs r2, #4
    add sb, r2
lbl_08069d58:
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    movs r3, #3
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #5]
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #1]
    adds r6, #8
    movs r0, #1
    add sl, r0
    ldr r1, [sp, #0x14]
    cmp sl, r1
    blt lbl_08069cc0
lbl_08069d92:
    ldr r2, [sp, #0x18]
    adds r2, #1
    str r2, [sp, #0x18]
    adds r5, #0x10
    ldr r3, [sp, #0xc]
    cmp r2, r3
    bge lbl_08069da2
    b lbl_08069a42
lbl_08069da2:
    ldr r0, lbl_08069dc4 @ =gNextOamSlot
    mov r1, sp
    ldrb r1, [r1, #0x14]
    strb r1, [r0]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069dbc: .4byte 0x000001ff
lbl_08069dc0: .4byte 0xfffffe00
lbl_08069dc4: .4byte gNextOamSlot

    thumb_func_start ProcessCutsceneOam
ProcessCutsceneOam: @ 0x08069dc8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r5, r1, #0
    str r2, [sp, #0x10]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0xc]
    ldr r0, lbl_08069e5c @ =gOamData
    mov sb, r0
    ldr r0, lbl_08069e60 @ =gNextOamSlot
    ldrb r0, [r0]
    str r0, [sp, #0x14]
    mov sl, r0
    lsls r0, r0, #3
    add sb, r0
    movs r1, #0
    str r1, [sp, #0x18]
    ldr r2, [sp, #0xc]
    cmp r1, r2
    blt lbl_08069dfa
    b lbl_0806a15a
lbl_08069dfa:
    ldrb r0, [r5, #0xa]
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_08069e04
    b lbl_0806a14a
lbl_08069e04:
    ldrb r1, [r5, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_08069e10
    b lbl_0806a14a
lbl_08069e10:
    cmp r0, #0x80
    bne lbl_08069e24
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r5, #0xb]
    movs r0, #0
    strb r0, [r5, #8]
    strb r0, [r5, #9]
lbl_08069e24:
    ldrb r1, [r5, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5, #0xb]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r3, r0, r1
    ldr r6, [r3]
    ldrb r2, [r5, #9]
    lsls r0, r2, #3
    adds r0, r0, r6
    ldrb r1, [r5, #8]
    adds r4, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_08069e4a
    b lbl_08069f9c
lbl_08069e4a:
    ldrb r0, [r3, #4]
    cmp r0, #9
    bls lbl_08069e52
    b lbl_08069f9c
lbl_08069e52:
    lsls r0, r0, #2
    ldr r1, lbl_08069e64 @ =lbl_08069e68
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069e5c: .4byte gOamData
lbl_08069e60: .4byte gNextOamSlot
lbl_08069e64: .4byte lbl_08069e68
lbl_08069e68: @ jump table
    .4byte lbl_08069f9c @ case 0
    .4byte lbl_08069e90 @ case 1
    .4byte lbl_08069eaa @ case 2
    .4byte lbl_08069eb0 @ case 3
    .4byte lbl_08069ede @ case 4
    .4byte lbl_08069efa @ case 5
    .4byte lbl_08069f14 @ case 6
    .4byte lbl_08069f3a @ case 7
    .4byte lbl_08069f60 @ case 8
    .4byte lbl_08069f7a @ case 9
lbl_08069e90:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    strb r0, [r5, #9]
    b lbl_08069f9c
lbl_08069eaa:
    movs r0, #0
    strb r0, [r5, #8]
    b lbl_08069f9c
lbl_08069eb0:
    lsls r0, r4, #3
    adds r0, r0, r6
    ldrb r2, [r0, #4]
    adds r0, r4, #1
    movs r3, #0
    strb r0, [r5, #9]
    ldrb r1, [r5, #9]
    lsls r0, r1, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069eda
    subs r0, r1, #1
    strb r0, [r5, #9]
    subs r0, r2, #1
    strb r0, [r5, #8]
    ldrb r0, [r5, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069f9c
lbl_08069eda:
    strb r3, [r5, #8]
    b lbl_08069f9c
lbl_08069ede:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    strb r0, [r5, #0xa]
    strb r0, [r5, #9]
    b lbl_08069f70
lbl_08069efa:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069f9c
    adds r0, r7, #1
    b lbl_08069f8e
lbl_08069f14:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r1, [r5, #9]
    adds r0, r1, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    adds r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r3, [sp, #0x10]
    adds r0, r0, r3
    b lbl_08069f9a
lbl_08069f3a:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069f9c
    subs r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r0, r0, r1
    b lbl_08069f9a
lbl_08069f60:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08069f86
    strb r1, [r5, #0xa]
    strb r1, [r5, #9]
lbl_08069f70:
    ldrb r1, [r5, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r5, #0xb]
    b lbl_0806a14a
lbl_08069f7a:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069f8c
lbl_08069f86:
    subs r0, #1
    strb r0, [r5, #9]
    b lbl_08069f9c
lbl_08069f8c:
    subs r0, r7, #1
lbl_08069f8e:
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #0x10]
    adds r0, r0, r2
lbl_08069f9a:
    ldr r6, [r0]
lbl_08069f9c:
    ldrb r0, [r5, #8]
    adds r0, #1
    strb r0, [r5, #8]
    ldrb r1, [r5, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069fae
    b lbl_0806a14a
lbl_08069fae:
    ldrb r0, [r5, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_08069fd0
    ldr r0, lbl_08069fc8 @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069fcc @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_08069fc8: .4byte gBG0HOFS_NonGameplay
lbl_08069fcc: .4byte gBG0VOFS_NonGameplay
lbl_08069fd0:
    cmp r1, #1
    bne lbl_08069fec
    ldr r0, lbl_08069fe4 @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069fe8 @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_08069fe4: .4byte gBG1HOFS_NonGameplay
lbl_08069fe8: .4byte gBG1VOFS_NonGameplay
lbl_08069fec:
    cmp r1, #2
    bne lbl_0806a008
    ldr r0, lbl_0806a000 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_0806a004 @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_0806a000: .4byte gBG2HOFS_NonGameplay
lbl_0806a004: .4byte gBG2VOFS_NonGameplay
lbl_0806a008:
    cmp r1, #3
    bne lbl_0806a024
    ldr r0, lbl_0806a01c @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_0806a020 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_0806a01c: .4byte gBG3HOFS_NonGameplay
lbl_0806a020: .4byte gBG3VOFS_NonGameplay
lbl_0806a024:
    movs r3, #0
    mov r8, r3
    movs r7, #0
lbl_0806a02a:
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_0806a0c4 @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrh r0, [r5, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    mov r2, r8
    asrs r1, r2, #2
    subs r0, r0, r1
    ldr r1, lbl_0806a0c8 @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r0
    mov r8, r1
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r6, r6, r0
    ldr r4, [r6]
    ldrh r0, [r4]
    ldr r3, [sp, #0x14]
    adds r0, r3, r0
    cmp r0, #0x7f
    bgt lbl_0806a15a
    str r0, [sp, #0x14]
    adds r4, #2
    cmp sl, r0
    bge lbl_0806a14a
    ldr r1, lbl_0806a0cc @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r6, r0, r1
lbl_0806a078:
    ldrb r1, [r5, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a0d8
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    movs r0, #2
    add sb, r0
    ldrh r2, [r4]
    adds r4, #2
    mov r1, sb
    strh r2, [r1]
    add sb, r0
    ldrh r0, [r4]
    mov r2, sb
    strh r0, [r2]
    adds r4, #2
    movs r3, #4
    add sb, r3
    ldr r0, lbl_0806a0d0 @ =gCurrentOamRotation
    ldrh r3, [r0]
    ldr r0, lbl_0806a0d4 @ =gCurrentOamScaling
    ldrh r0, [r0]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, sl
    mov r1, r8
    adds r2, r7, #0
    bl ProcessComplexOam
    b lbl_0806a110
    .align 2, 0
lbl_0806a0c4: .4byte gOamYOffset_NonGameplay
lbl_0806a0c8: .4byte gOamXOffset_NonGameplay
lbl_0806a0cc: .4byte gOamData
lbl_0806a0d0: .4byte gCurrentOamRotation
lbl_0806a0d4: .4byte gCurrentOamScaling
lbl_0806a0d8:
    ldrh r2, [r4]
    adds r4, #2
    mov r0, sb
    strh r2, [r0]
    movs r1, #2
    add sb, r1
    adds r0, r2, r7
    strb r0, [r6]
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    add sb, r1
    add r2, r8
    ldr r0, lbl_0806a174 @ =0x000001ff
    ands r2, r0
    ldrh r0, [r6, #2]
    ldr r3, lbl_0806a178 @ =0xfffffe00
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r6, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    movs r2, #4
    add sb, r2
lbl_0806a110:
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    movs r3, #3
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #5]
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #1]
    adds r6, #8
    movs r0, #1
    add sl, r0
    ldr r1, [sp, #0x14]
    cmp sl, r1
    blt lbl_0806a078
lbl_0806a14a:
    ldr r2, [sp, #0x18]
    adds r2, #1
    str r2, [sp, #0x18]
    adds r5, #0x20
    ldr r3, [sp, #0xc]
    cmp r2, r3
    bge lbl_0806a15a
    b lbl_08069dfa
lbl_0806a15a:
    ldr r0, lbl_0806a17c @ =gNextOamSlot
    mov r1, sp
    ldrb r1, [r1, #0x14]
    strb r1, [r0]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806a174: .4byte 0x000001ff
lbl_0806a178: .4byte 0xfffffe00
lbl_0806a17c: .4byte gNextOamSlot

    thumb_func_start map_screen_main
map_screen_main: @ 0x0806a180
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_0806a19c @ =gSubGameModeStage
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #8
    bls lbl_0806a190
    b lbl_0806a2ee
lbl_0806a190:
    lsls r0, r1, #2
    ldr r1, lbl_0806a1a0 @ =lbl_0806a1a4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806a19c: .4byte gSubGameModeStage
lbl_0806a1a0: .4byte lbl_0806a1a4
lbl_0806a1a4: @ jump table
    .4byte lbl_0806a1c8 @ case 0
    .4byte lbl_0806a248 @ case 1
    .4byte lbl_0806a1f6 @ case 2
    .4byte lbl_0806a248 @ case 3
    .4byte lbl_0806a234 @ case 4
    .4byte lbl_0806a248 @ case 5
    .4byte lbl_0806a260 @ case 6
    .4byte lbl_0806a248 @ case 7
    .4byte lbl_0806a2e8 @ case 8
lbl_0806a1c8:
    ldr r0, lbl_0806a1e0 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806a1ec
    ldr r2, lbl_0806a1e4 @ =gButtonInput
    ldr r1, lbl_0806a1e8 @ =gChangedInput
    movs r0, #0
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #5
    b lbl_0806a1ee
    .align 2, 0
lbl_0806a1e0: .4byte gDemoState
lbl_0806a1e4: .4byte gButtonInput
lbl_0806a1e8: .4byte gChangedInput
lbl_0806a1ec:
    movs r0, #1
lbl_0806a1ee:
    strb r0, [r3]
    bl map_screen_init
    b lbl_0806a2ee
lbl_0806a1f6:
    movs r0, #0
    bl sub_080682ec
    bl sub_0806b240
    cmp r0, #0
    beq lbl_0806a212
    movs r0, #4
    bl sub_080682ec
    ldr r1, lbl_0806a22c @ =gSubGameModeStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806a212:
    ldr r0, lbl_0806a230 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806a222
    bl update_minimap_anim_palette
lbl_0806a222:
    bl sub_08068694
    bl sub_080695bc
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a22c: .4byte gSubGameModeStage
lbl_0806a230: .4byte sNonGameplayRamPointer
lbl_0806a234:
    movs r0, #0
    strb r0, [r3]
    ldr r1, lbl_0806a244 @ =gGameModeSub2
    movs r0, #4
    strb r0, [r1]
    movs r4, #1
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a244: .4byte gGameModeSub2
lbl_0806a248:
    movs r0, #0
    bl sub_080682ec
    cmp r0, #0
    beq lbl_0806a2ee
    ldr r1, lbl_0806a25c @ =gSubGameModeStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a25c: .4byte gSubGameModeStage
lbl_0806a260:
    movs r0, #0
    bl sub_080682ec
    ldr r2, lbl_0806a288 @ =gButtonInput
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_0806a294
    ldr r2, lbl_0806a28c @ =gCurrentDemo
    ldrb r1, [r2, #3]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #3]
    bl DemoEnd
    ldr r1, lbl_0806a290 @ =gPauseScreenFlag
    movs r0, #9
    b lbl_0806a2a6
    .align 2, 0
lbl_0806a288: .4byte gButtonInput
lbl_0806a28c: .4byte gCurrentDemo
lbl_0806a290: .4byte gPauseScreenFlag
lbl_0806a294:
    ldr r0, lbl_0806a2d8 @ =gChangedInput
    strh r1, [r0]
    strh r1, [r2]
    bl sub_0806b240
    cmp r0, #0
    beq lbl_0806a2b0
    ldr r1, lbl_0806a2dc @ =gGameModeSub2
    movs r0, #0xb
lbl_0806a2a6:
    strb r0, [r1]
    movs r4, #1
    ldr r1, lbl_0806a2e0 @ =gSubGameModeStage
    movs r0, #7
    strb r0, [r1]
lbl_0806a2b0:
    cmp r4, #0
    beq lbl_0806a2ba
    movs r0, #4
    bl sub_080682ec
lbl_0806a2ba:
    ldr r0, lbl_0806a2e4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806a2ca
    bl update_minimap_anim_palette
lbl_0806a2ca:
    bl sub_08068694
    bl sub_080695bc
    movs r4, #0
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a2d8: .4byte gChangedInput
lbl_0806a2dc: .4byte gGameModeSub2
lbl_0806a2e0: .4byte gSubGameModeStage
lbl_0806a2e4: .4byte sNonGameplayRamPointer
lbl_0806a2e8:
    movs r4, #1
    movs r0, #0
    strb r0, [r3]
lbl_0806a2ee:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806a2f8
sub_0806a2f8: @ 0x0806a2f8
    push {r4, lr}
    ldr r1, lbl_0806a3d8 @ =0x040000d4
    ldr r0, lbl_0806a3dc @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806a3e0 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_0806a3e4 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x5c
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x54
    ldr r0, lbl_0806a3e8 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #8
    ldr r0, lbl_0806a3ec @ =gWrittenToMOSAIC_L
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_0806a3f0 @ =0x04000010
    ldr r0, lbl_0806a3f4 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldr r4, lbl_0806a3f8 @ =0x000001ff
    adds r1, r4, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a3fc @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a400 @ =gBG1HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a404 @ =gBG1VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a408 @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a40c @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a410 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a414 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0806a418 @ =0x04000008
    adds r0, r3, #0
    adds r0, #0x5e
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x60
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x62
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x64
    ldrh r0, [r0]
    strh r0, [r1]
    adds r2, #0x34
    ldr r0, lbl_0806a41c @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0806a420 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0806a424 @ =0x04000050
    adds r0, r3, #0
    adds r0, #0x66
    ldrh r0, [r0]
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806a3d8: .4byte 0x040000d4
lbl_0806a3dc: .4byte gOamData
lbl_0806a3e0: .4byte 0x84000100
lbl_0806a3e4: .4byte sNonGameplayRamPointer
lbl_0806a3e8: .4byte gWrittenToBLDY_NonGameplay
lbl_0806a3ec: .4byte gWrittenToMOSAIC_L
lbl_0806a3f0: .4byte 0x04000010
lbl_0806a3f4: .4byte gBG0HOFS_NonGameplay
lbl_0806a3f8: .4byte 0x000001ff
lbl_0806a3fc: .4byte gBG0VOFS_NonGameplay
lbl_0806a400: .4byte gBG1HOFS_NonGameplay
lbl_0806a404: .4byte gBG1VOFS_NonGameplay
lbl_0806a408: .4byte gBG2HOFS_NonGameplay
lbl_0806a40c: .4byte gBG2VOFS_NonGameplay
lbl_0806a410: .4byte gBG3HOFS_NonGameplay
lbl_0806a414: .4byte gBG3VOFS_NonGameplay
lbl_0806a418: .4byte 0x04000008
lbl_0806a41c: .4byte gWrittenToBLDALPHA_H
lbl_0806a420: .4byte gWrittenToBLDALPHA_L
lbl_0806a424: .4byte 0x04000050

    thumb_func_start sub_0806a428
sub_0806a428: @ 0x0806a428
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr

    thumb_func_start map_screen_init
map_screen_init: @ 0x0806a434
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0806a4f0 @ =sub_0806a428
    bl CallbackSetVBlank
    ldr r1, lbl_0806a4f4 @ =0x04000050
    movs r0, #0xff
    strh r0, [r1]
    ldr r2, lbl_0806a4f8 @ =0x04000054
    ldr r1, lbl_0806a4fc @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x13
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_0806a500 @ =gNextOamSlot
    strb r1, [r0]
    ldr r2, lbl_0806a504 @ =gNonGameplayRAM
    movs r3, #0xc5
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    bl ResetFreeOAM
    ldr r1, lbl_0806a508 @ =0x040000d4
    ldr r0, lbl_0806a50c @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806a510 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r4, lbl_0806a514 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x66
    movs r5, #0
    movs r0, #0xff
    strh r0, [r2]
    adds r1, #0x5c
    strh r5, [r1]
    ldr r0, lbl_0806a518 @ =gCurrentCutscene
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0806a4ba
    ldr r1, lbl_0806a51c @ =0x06010000
    ldr r2, lbl_0806a520 @ =0x0201e000
    movs r3, #0x80
    lsls r3, r3, #8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806a4ba:
    ldr r1, [r4]
    ldr r0, lbl_0806a524 @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r1, #0x12]
    ldr r1, [r4]
    ldr r0, lbl_0806a528 @ =gMinimapX
    ldrb r0, [r0]
    strb r0, [r1, #0x13]
    ldr r1, [r4]
    ldr r0, lbl_0806a52c @ =gMinimapY
    ldrb r0, [r0]
    strb r0, [r1, #0x14]
    ldr r0, [r4]
    strh r5, [r0]
    ldr r0, lbl_0806a530 @ =gPauseScreenFlag
    ldrb r0, [r0]
    subs r0, #3
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_0806a4e6
    b lbl_0806a5dc
lbl_0806a4e6:
    lsls r0, r0, #2
    ldr r1, lbl_0806a534 @ =lbl_0806a538
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806a4f0: .4byte sub_0806a428
lbl_0806a4f4: .4byte 0x04000050
lbl_0806a4f8: .4byte 0x04000054
lbl_0806a4fc: .4byte gWrittenToBLDY_NonGameplay
lbl_0806a500: .4byte gNextOamSlot
lbl_0806a504: .4byte gNonGameplayRAM
lbl_0806a508: .4byte 0x040000d4
lbl_0806a50c: .4byte gOamData
lbl_0806a510: .4byte 0x84000100
lbl_0806a514: .4byte sNonGameplayRamPointer
lbl_0806a518: .4byte gCurrentCutscene
lbl_0806a51c: .4byte 0x06010000
lbl_0806a520: .4byte 0x0201e000
lbl_0806a524: .4byte gCurrentArea
lbl_0806a528: .4byte gMinimapX
lbl_0806a52c: .4byte gMinimapY
lbl_0806a530: .4byte gPauseScreenFlag
lbl_0806a534: .4byte lbl_0806a538
lbl_0806a538: @ jump table
    .4byte lbl_0806a560 @ case 0
    .4byte lbl_0806a550 @ case 1
    .4byte lbl_0806a570 @ case 2
    .4byte lbl_0806a580 @ case 3
    .4byte lbl_0806a598 @ case 4
    .4byte lbl_0806a5cc @ case 5
lbl_0806a550:
    ldr r0, lbl_0806a55c @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x12
    b lbl_0806a58c
    .align 2, 0
lbl_0806a55c: .4byte sNonGameplayRamPointer
lbl_0806a560:
    ldr r0, lbl_0806a56c @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #8
    b lbl_0806a58c
    .align 2, 0
lbl_0806a56c: .4byte sNonGameplayRamPointer
lbl_0806a570:
    ldr r0, lbl_0806a57c @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x22
    b lbl_0806a58c
    .align 2, 0
lbl_0806a57c: .4byte sNonGameplayRamPointer
lbl_0806a580:
    ldr r0, lbl_0806a594 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r3, #0xc0
    lsls r3, r3, #1
    adds r0, r3, #0
lbl_0806a58c:
    orrs r0, r1
    strh r0, [r2]
    b lbl_0806a5dc
    .align 2, 0
lbl_0806a594: .4byte sNonGameplayRamPointer
lbl_0806a598:
    movs r0, #2
    bl update_suitType
    ldr r1, lbl_0806a5c0 @ =gSamusData
    movs r3, #0
    movs r0, #0x1e
    strb r0, [r1]
    movs r2, #0
    movs r0, #0x20
    strh r0, [r1, #0xe]
    strb r2, [r1, #0x1d]
    strh r3, [r1, #0xc]
    ldr r1, lbl_0806a5c4 @ =gCurrentItemBeingAcquired
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0806a5c8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xe0
    lsls r0, r0, #2
    b lbl_0806a5da
    .align 2, 0
lbl_0806a5c0: .4byte gSamusData
lbl_0806a5c4: .4byte gCurrentItemBeingAcquired
lbl_0806a5c8: .4byte sNonGameplayRamPointer
lbl_0806a5cc:
    movs r0, #1
    bl update_suitType
    ldr r0, lbl_0806a698 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xb0
    lsls r0, r0, #3
lbl_0806a5da:
    strh r0, [r1]
lbl_0806a5dc:
    ldr r1, lbl_0806a69c @ =0x083fd050
    ldr r2, lbl_0806a6a0 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806a6a4 @ =0x08411360
    movs r2, #0xa0
    lsls r2, r2, #0x13
    str r4, [sp]
    movs r0, #3
    movs r3, #0xa0
    bl DMATransfer
    ldr r1, lbl_0806a6a8 @ =0x083fcef0
    ldr r2, lbl_0806a6ac @ =0x050000a0
    movs r3, #0xb0
    lsls r3, r3, #1
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_0806a6b0 @ =0x08754bb8
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0806a6b4 @ =0x0840e0c4
    ldr r2, lbl_0806a6b8 @ =0x06008000
    movs r3, #0xc0
    lsls r3, r3, #6
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806a6bc @ =0x0600a820
    ldr r2, lbl_0806a6c0 @ =0x0600ac20
    movs r3, #0xf8
    lsls r3, r3, #2
    movs r6, #0x20
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_0806a6c4 @ =0x08400e08
    ldr r1, lbl_0806a6c8 @ =0x06013000
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6cc @ =0x08760104
    ldr r5, lbl_0806a6d0 @ =gLanguage
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6d4 @ =0x06010800
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6d8 @ =0x0876013c
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6dc @ =0x06011400
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6e0 @ =0x08760120
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6e4 @ =0x06011800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a698 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r0, [r0]
    ands r4, r0
    cmp r4, #0
    beq lbl_0806a6f4
    ldr r0, lbl_0806a6e8 @ =0x084030b4
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a6ec @ =0x084110c4
    ldr r1, lbl_0806a6f0 @ =0x0600a800
    bl CallLZ77UncompVRAM
    b lbl_0806a744
    .align 2, 0
lbl_0806a698: .4byte sNonGameplayRamPointer
lbl_0806a69c: .4byte 0x083fd050
lbl_0806a6a0: .4byte 0x05000200
lbl_0806a6a4: .4byte 0x08411360
lbl_0806a6a8: .4byte 0x083fcef0
lbl_0806a6ac: .4byte 0x050000a0
lbl_0806a6b0: .4byte 0x08754bb8
lbl_0806a6b4: .4byte 0x0840e0c4
lbl_0806a6b8: .4byte 0x06008000
lbl_0806a6bc: .4byte 0x0600a820
lbl_0806a6c0: .4byte 0x0600ac20
lbl_0806a6c4: .4byte 0x08400e08
lbl_0806a6c8: .4byte 0x06013000
lbl_0806a6cc: .4byte 0x08760104
lbl_0806a6d0: .4byte gLanguage
lbl_0806a6d4: .4byte 0x06010800
lbl_0806a6d8: .4byte 0x0876013c
lbl_0806a6dc: .4byte 0x06011400
lbl_0806a6e0: .4byte 0x08760120
lbl_0806a6e4: .4byte 0x06011800
lbl_0806a6e8: .4byte 0x084030b4
lbl_0806a6ec: .4byte 0x084110c4
lbl_0806a6f0: .4byte 0x0600a800
lbl_0806a6f4:
    ldr r0, lbl_0806a794 @ =0x083feb60
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a798 @ =0x083fefb8
    ldr r1, lbl_0806a79c @ =0x06001000
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a7a0 @ =0x084005a8
    ldr r1, lbl_0806a7a4 @ =0x06007400
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7a8 @ =0x08760158
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r4, lbl_0806a7ac @ =0x06006000
    adds r1, r4, #0
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7b0 @ =0x08760174
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a7b4 @ =0x06000c00
    bl CallLZ77UncompVRAM
    ldr r2, lbl_0806a7b8 @ =0x06010000
    movs r3, #0x80
    lsls r3, r3, #4
    str r6, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl DMATransfer
lbl_0806a744:
    movs r1, #0x8a
    lsls r1, r1, #5
    ldr r2, lbl_0806a7bc @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #5
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    bl BitFill
    ldr r1, lbl_0806a7c0 @ =0x02034000
    ldr r2, lbl_0806a7c4 @ =0x0600e000
    movs r7, #0x80
    lsls r7, r7, #4
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl DMATransfer
    ldr r5, lbl_0806a7c8 @ =sNonGameplayRamPointer
    mov r8, r5
    ldr r0, [r5]
    ldrh r1, [r0]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a7dc
    ldr r0, lbl_0806a7cc @ =0x08408e00
    ldr r1, lbl_0806a7d0 @ =0x0600b800
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7d4 @ =0x0000115f
    ldr r2, lbl_0806a7d8 @ =0x0600c000
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl BitFill
    b lbl_0806a8f6
    .align 2, 0
lbl_0806a794: .4byte 0x083feb60
lbl_0806a798: .4byte 0x083fefb8
lbl_0806a79c: .4byte 0x06001000
lbl_0806a7a0: .4byte 0x084005a8
lbl_0806a7a4: .4byte 0x06007400
lbl_0806a7a8: .4byte 0x08760158
lbl_0806a7ac: .4byte 0x06006000
lbl_0806a7b0: .4byte 0x08760174
lbl_0806a7b4: .4byte 0x06000c00
lbl_0806a7b8: .4byte 0x06010000
lbl_0806a7bc: .4byte 0x0600e800
lbl_0806a7c0: .4byte 0x02034000
lbl_0806a7c4: .4byte 0x0600e000
lbl_0806a7c8: .4byte sNonGameplayRamPointer
lbl_0806a7cc: .4byte 0x08408e00
lbl_0806a7d0: .4byte 0x0600b800
lbl_0806a7d4: .4byte 0x0000115f
lbl_0806a7d8: .4byte 0x0600c000
lbl_0806a7dc:
    ldr r0, lbl_0806a81c @ =0x08407ba8
    ldr r5, lbl_0806a820 @ =sEwramPointer
    ldr r1, [r5]
    movs r4, #0x90
    lsls r4, r4, #8
    adds r1, r1, r4
    bl CallLZ77UncompWRAM
    ldr r1, [r5]
    adds r1, r1, r4
    ldr r2, lbl_0806a824 @ =0x0600c800
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl DMATransfer
    movs r0, #2
    movs r1, #2
    bl PauseScreenUpdateBottomVisorOverlay
    mov r1, r8
    ldr r0, [r1]
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a828
    movs r0, #0xff
    bl sub_0806b718
    b lbl_0806a8f6
    .align 2, 0
lbl_0806a81c: .4byte 0x08407ba8
lbl_0806a820: .4byte sEwramPointer
lbl_0806a824: .4byte 0x0600c800
lbl_0806a828:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a84e
    ldr r0, lbl_0806a88c @ =0x084078ec
    ldr r1, lbl_0806a890 @ =0x0600b000
    bl CallLZ77UncompVRAM
    movs r1, #0xf0
    lsls r1, r1, #8
    ldr r2, [r5]
    movs r3, #0xd0
    lsls r3, r3, #8
    adds r2, r2, r3
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl BitFill
lbl_0806a84e:
    ldr r0, lbl_0806a894 @ =0x084082bc
    ldr r1, [r5]
    movs r2, #0xf0
    lsls r2, r2, #7
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a898 @ =0x084089ec
    ldr r1, [r5]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r1, r3
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a89c @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0806a8a4
    ldr r1, [r5]
    movs r5, #0x80
    lsls r5, r5, #8
    adds r1, r1, r5
    ldr r2, lbl_0806a8a0 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806a8ba
    .align 2, 0
lbl_0806a88c: .4byte 0x084078ec
lbl_0806a890: .4byte 0x0600b000
lbl_0806a894: .4byte 0x084082bc
lbl_0806a898: .4byte 0x084089ec
lbl_0806a89c: .4byte gEquipment
lbl_0806a8a0: .4byte 0x0600c000
lbl_0806a8a4:
    ldr r1, [r5]
    movs r0, #0xf0
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806a948 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806a8ba:
    ldr r0, lbl_0806a94c @ =0x08407d90
    ldr r4, lbl_0806a950 @ =sEwramPointer
    ldr r1, [r4]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a954 @ =0x08407f84
    ldr r1, [r4]
    movs r3, #0xa0
    lsls r3, r3, #8
    adds r1, r1, r3
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a958 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strb r0, [r1, #0x11]
    ldr r0, lbl_0806a95c @ =0x08408c90
    ldr r1, lbl_0806a960 @ =0x0600d800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a964 @ =0x084086dc
    ldr r1, [r4]
    movs r5, #0x88
    lsls r5, r5, #8
    adds r1, r1, r5
    bl CallLZ77UncompWRAM
lbl_0806a8f6:
    ldr r2, lbl_0806a968 @ =gBG0HOFS_NonGameplay
    ldr r0, lbl_0806a96c @ =gBG0VOFS_NonGameplay
    movs r1, #0
    strh r1, [r0]
    strh r1, [r2]
    ldr r0, lbl_0806a970 @ =gBG1HOFS_NonGameplay
    ldr r4, lbl_0806a974 @ =gBG1VOFS_NonGameplay
    strh r1, [r4]
    strh r1, [r0]
    ldr r2, lbl_0806a978 @ =gBG2HOFS_NonGameplay
    ldr r0, lbl_0806a97c @ =gBG2VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806a980 @ =gBG3HOFS_NonGameplay
    ldr r0, lbl_0806a984 @ =gBG3VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806a958 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    movs r3, #0
    strb r1, [r0, #8]
    ldr r1, [r2]
    strh r3, [r1, #0xa]
    adds r1, #4
    ldr r0, lbl_0806a988 @ =0x087600f8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    movs r6, #0x80
    lsls r6, r6, #3
    adds r5, r6, #0
    strh r5, [r4]
    ldr r3, [r2]
    ldrh r1, [r3]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a98c
    movs r0, #0xf
    strb r0, [r3, #4]
    b lbl_0806a9f2
    .align 2, 0
lbl_0806a948: .4byte 0x0600c000
lbl_0806a94c: .4byte 0x08407d90
lbl_0806a950: .4byte sEwramPointer
lbl_0806a954: .4byte 0x08407f84
lbl_0806a958: .4byte sNonGameplayRamPointer
lbl_0806a95c: .4byte 0x08408c90
lbl_0806a960: .4byte 0x0600d800
lbl_0806a964: .4byte 0x084086dc
lbl_0806a968: .4byte gBG0HOFS_NonGameplay
lbl_0806a96c: .4byte gBG0VOFS_NonGameplay
lbl_0806a970: .4byte gBG1HOFS_NonGameplay
lbl_0806a974: .4byte gBG1VOFS_NonGameplay
lbl_0806a978: .4byte gBG2HOFS_NonGameplay
lbl_0806a97c: .4byte gBG2VOFS_NonGameplay
lbl_0806a980: .4byte gBG3HOFS_NonGameplay
lbl_0806a984: .4byte gBG3VOFS_NonGameplay
lbl_0806a988: .4byte 0x087600f8
lbl_0806a98c:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9cc
    ldr r2, lbl_0806a9c0 @ =gEquipment
    ldr r4, lbl_0806a9c4 @ =gCurrentArea
    movs r0, #1
    ldrb r1, [r4]
    lsls r0, r1
    ldrb r1, [r2, #0x10]
    orrs r0, r1
    strb r0, [r2, #0x10]
    movs r0, #9
    strb r0, [r3, #4]
    ldrb r0, [r4]
    ldr r5, lbl_0806a9c8 @ =0x02034000
    adds r1, r5, #0
    bl PauseScreenGetMinimapData
    ldrb r0, [r4]
    adds r1, r5, #0
    bl MinimapSetDownloadedTiles
    bl PauseScreenInitMapDownload
    b lbl_0806a9f2
    .align 2, 0
lbl_0806a9c0: .4byte gEquipment
lbl_0806a9c4: .4byte gCurrentArea
lbl_0806a9c8: .4byte 0x02034000
lbl_0806a9cc:
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9da
    movs r0, #0x14
    strb r0, [r3, #4]
    b lbl_0806a9f2
lbl_0806a9da:
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9f2
    movs r0, #0x13
    strb r0, [r3, #4]
    ldr r0, lbl_0806aa38 @ =gCurrentItemBeingAcquired
    ldrb r1, [r0]
    movs r0, #1
    bl sub_08070020
lbl_0806a9f2:
    movs r0, #0xff
    bl PauseScreenGetAllMinimapData
    ldr r4, lbl_0806aa3c @ =sNonGameplayRamPointer
    bl draw_status_screen_tanks_amounts
    movs r0, #0
    bl ChozoHintDeterminePath
    movs r0, #0
    bl unk_6db58
    bl sub_0806facc
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806aa40
    adds r0, r2, #0
    adds r0, #0xb8
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xb9
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xba
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xbb
    strb r1, [r0]
    b lbl_0806aa6a
    .align 2, 0
lbl_0806aa38: .4byte gCurrentItemBeingAcquired
lbl_0806aa3c: .4byte sNonGameplayRamPointer
lbl_0806aa40:
    bl PauseScreenMapCheckExploredAreas
    bl PauseScreenCheckAreasWithTargets
    bl determine_maps_viewable
    bl LoadPauseScreenBgPalette
    ldr r0, lbl_0806aac8 @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r1, r1, r2
    ldr r2, lbl_0806aacc @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806aa6a:
    ldr r2, lbl_0806aad0 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    mov sl, r2
    ldr r3, lbl_0806aad4 @ =gBG1HOFS_NonGameplay
    mov ip, r3
    ldr r5, lbl_0806aad8 @ =gBG1VOFS_NonGameplay
    mov sb, r5
    cmp r0, #0
    beq lbl_0806aa88
    movs r0, #0x10
    strh r0, [r3]
    strh r0, [r5]
lbl_0806aa88:
    ldr r0, lbl_0806aadc @ =gWrittenToBLDY_NonGameplay
    ldr r2, lbl_0806aae0 @ =gWrittenToBLDALPHA_H
    movs r5, #0
    strh r5, [r2]
    strh r5, [r0]
    ldr r1, lbl_0806aae4 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    mov r6, sl
    ldr r3, [r6]
    ldrh r4, [r3]
    movs r0, #0x10
    ands r0, r4
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r2, #0
    mov r8, r1
    cmp r6, #0
    beq lbl_0806aaf0
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806aae8 @ =0x00003f42
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0806aaec @ =0x00000709
    strh r0, [r1]
    movs r0, #7
    strh r0, [r7]
    movs r0, #9
    mov r1, r8
    strh r0, [r1]
    b lbl_0806ab30
    .align 2, 0
lbl_0806aac8: .4byte sEwramPointer
lbl_0806aacc: .4byte 0x0600d000
lbl_0806aad0: .4byte sNonGameplayRamPointer
lbl_0806aad4: .4byte gBG1HOFS_NonGameplay
lbl_0806aad8: .4byte gBG1VOFS_NonGameplay
lbl_0806aadc: .4byte gWrittenToBLDY_NonGameplay
lbl_0806aae0: .4byte gWrittenToBLDALPHA_H
lbl_0806aae4: .4byte gWrittenToBLDALPHA_L
lbl_0806aae8: .4byte 0x00003f42
lbl_0806aaec: .4byte 0x00000709
lbl_0806aaf0:
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r4
    cmp r0, #0
    beq lbl_0806ab18
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806ab14 @ =0x00003c44
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x68
    movs r1, #0x16
    strh r1, [r0]
    strh r6, [r7]
    mov r2, r8
    strh r1, [r2]
    b lbl_0806ab30
    .align 2, 0
lbl_0806ab14: .4byte 0x00003c44
lbl_0806ab18:
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806ac3c @ =0x00003844
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0806ac40 @ =0x0000060a
    strh r0, [r1]
    movs r0, #6
    strh r0, [r7]
    movs r0, #0xa
    mov r3, r8
    strh r0, [r3]
lbl_0806ab30:
    ldr r1, lbl_0806ac44 @ =0x0400004a
    movs r0, #0x3f
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    ldr r0, lbl_0806ac48 @ =gWrittenToMOSAIC_L
    movs r6, #0
    strh r6, [r0]
    ldr r2, lbl_0806ac4c @ =0x04000010
    ldr r0, lbl_0806ac50 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldr r5, lbl_0806ac54 @ =0x000001ff
    adds r1, r5, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac58 @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    mov r3, ip
    ldrh r0, [r3]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    mov r5, sb
    ldrh r0, [r5]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac5c @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac60 @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac64 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac68 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_0806ac6c @ =0x0400004c
    strh r6, [r0]
    ldr r1, lbl_0806ac70 @ =0x04000050
    mov r0, sl
    ldr r4, [r0]
    adds r0, r4, #0
    adds r0, #0x66
    ldrh r0, [r0]
    strh r0, [r1]
    adds r2, #0x34
    ldrh r0, [r7]
    lsls r0, r0, #8
    mov r3, r8
    ldrh r1, [r3]
    orrs r0, r1
    strh r0, [r2]
    ldrh r1, [r4]
    movs r0, #0x10
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r5, #0
    beq lbl_0806ac80
    adds r1, r4, #0
    adds r1, #0x5c
    movs r2, #0
    movs r0, #0xf0
    lsls r0, r0, #5
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x6a
    strh r2, [r0]
    adds r0, #6
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    subs r0, #0xc
    strh r2, [r0]
    ldr r3, lbl_0806ac74 @ =0x0840d088
    ldrh r1, [r3, #2]
    ldr r5, lbl_0806ac78 @ =0x0000dc48
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    ldrh r0, [r3, #6]
    movs r6, #0xb8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x62
    strh r0, [r1]
    ldrh r0, [r3, #4]
    ldr r3, lbl_0806ac7c @ =0x00001808
    adds r1, r3, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x60
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x5e
    strh r2, [r0]
    b lbl_0806ae08
    .align 2, 0
lbl_0806ac3c: .4byte 0x00003844
lbl_0806ac40: .4byte 0x0000060a
lbl_0806ac44: .4byte 0x0400004a
lbl_0806ac48: .4byte gWrittenToMOSAIC_L
lbl_0806ac4c: .4byte 0x04000010
lbl_0806ac50: .4byte gBG0HOFS_NonGameplay
lbl_0806ac54: .4byte 0x000001ff
lbl_0806ac58: .4byte gBG0VOFS_NonGameplay
lbl_0806ac5c: .4byte gBG2HOFS_NonGameplay
lbl_0806ac60: .4byte gBG2VOFS_NonGameplay
lbl_0806ac64: .4byte gBG3HOFS_NonGameplay
lbl_0806ac68: .4byte gBG3VOFS_NonGameplay
lbl_0806ac6c: .4byte 0x0400004c
lbl_0806ac70: .4byte 0x04000050
lbl_0806ac74: .4byte 0x0840d088
lbl_0806ac78: .4byte 0x0000dc48
lbl_0806ac7c: .4byte 0x00001808
lbl_0806ac80:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806ad08
    adds r1, r4, #0
    adds r1, #0x5c
    movs r0, #0xf8
    lsls r0, r0, #5
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x6a
    strh r5, [r0]
    ldr r2, lbl_0806acfc @ =0x0840d088
    ldrh r0, [r2]
    movs r6, #0xc8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r3, r4, #0
    adds r3, #0x70
    strh r0, [r3]
    adds r0, r4, #0
    adds r0, #0x72
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    subs r0, #0xc
    strh r5, [r0]
    ldrh r1, [r2, #2]
    ldr r5, lbl_0806ad00 @ =0x0000dc48
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    ldrh r0, [r2, #6]
    movs r6, #0xb8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x62
    strh r0, [r1]
    ldrh r0, [r2, #4]
    ldr r2, lbl_0806ad04 @ =0x00001808
    adds r1, r2, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x60
    strh r0, [r1]
    ldrh r1, [r3]
    adds r0, r4, #0
    adds r0, #0x5e
    b lbl_0806ae06
    .align 2, 0
lbl_0806acfc: .4byte 0x0840d088
lbl_0806ad00: .4byte 0x0000dc48
lbl_0806ad04: .4byte 0x00001808
lbl_0806ad08:
    adds r1, r4, #0
    adds r1, #0x5c
    movs r0, #0xf0
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r3, lbl_0806ada0 @ =0x0840d088
    ldrh r0, [r3]
    ldr r5, lbl_0806ada4 @ =0x00001b04
    adds r1, r5, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x6a
    strh r0, [r1]
    ldrh r1, [r3, #6]
    ldr r2, lbl_0806ada8 @ =0x0000dc08
    adds r0, r2, #0
    adds r2, r1, #0
    orrs r2, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r2, [r0]
    ldr r5, lbl_0806adac @ =0x00001f08
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6e
    strh r1, [r0]
    ldrh r0, [r3, #2]
    movs r2, #0xc8
    lsls r2, r2, #5
    adds r1, r2, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x70
    strh r0, [r1]
    ldrh r2, [r3, #4]
    movs r3, #0xd0
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r2
    adds r3, r4, #0
    adds r3, #0x72
    strh r0, [r3]
    movs r5, #0xc0
    lsls r5, r5, #5
    adds r0, r5, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x74
    strh r1, [r0]
    ldrh r0, [r3]
    adds r1, r4, #0
    adds r1, #0x76
    strh r0, [r1]
    ldrh r0, [r4]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_0806adb4
    movs r6, #0xb0
    lsls r6, r6, #5
    adds r0, r6, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x78
    strh r1, [r0]
    ldr r1, lbl_0806adb0 @ =0x00001608
    adds r0, r1, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x7a
    b lbl_0806adbc
    .align 2, 0
lbl_0806ada0: .4byte 0x0840d088
lbl_0806ada4: .4byte 0x00001b04
lbl_0806ada8: .4byte 0x0000dc08
lbl_0806adac: .4byte 0x00001f08
lbl_0806adb0: .4byte 0x00001608
lbl_0806adb4:
    adds r0, r4, #0
    adds r0, #0x78
    strh r1, [r0]
    adds r0, #2
lbl_0806adbc:
    strh r1, [r0]
    mov r3, sl
    ldr r2, [r3]
    adds r0, r2, #0
    adds r0, #0x6c
    ldrh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    adds r0, #0xc
    ldrh r1, [r0]
    subs r0, #0x10
    strh r1, [r0]
    adds r0, #0xa
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0x5e
    strh r0, [r1]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806adfe
    adds r1, r2, #0
    adds r1, #0x5c
    movs r0, #0x94
    lsls r0, r0, #8
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x74
    ldrh r1, [r0]
    subs r0, #0x12
    b lbl_0806ae06
lbl_0806adfe:
    adds r0, r2, #0
    adds r0, #0x72
    ldrh r1, [r0]
    subs r0, #0x10
lbl_0806ae06:
    strh r1, [r0]
lbl_0806ae08:
    ldr r1, lbl_0806aeac @ =0x04000008
    mov r5, sl
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x5e
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x60
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x62
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x64
    ldrh r0, [r0]
    strh r0, [r1]
    bl sub_0806920c
    ldr r0, lbl_0806aeb0 @ =gOamYOffset_NonGameplay
    movs r1, #4
    strb r1, [r0]
    ldr r0, lbl_0806aeb4 @ =gOamXOffset_NonGameplay
    strb r1, [r0]
    bl sub_08068694
    bl PauseScreenUpdateBossIcons
    ldr r2, [r5]
    ldrh r1, [r2]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806ae6c
    ldr r6, lbl_0806aeb8 @ =0x00000412
    adds r0, r2, r6
    ldrb r0, [r0]
    cmp r0, #3
    beq lbl_0806ae6c
    ldr r1, lbl_0806aebc @ =0x00000413
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_0806ae6c:
    bl sub_080695bc
    ldr r1, lbl_0806aec0 @ =0x040000d4
    ldr r0, lbl_0806aec4 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806aec8 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #2
    bl sub_080682ec
    ldr r0, lbl_0806aecc @ =sub_0806a2f8
    bl CallbackSetVBlank
    movs r1, #0x80
    lsls r1, r1, #0x13
    ldr r0, lbl_0806aed0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x5c
    ldrh r0, [r0]
    strh r0, [r1]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806aeac: .4byte 0x04000008
lbl_0806aeb0: .4byte gOamYOffset_NonGameplay
lbl_0806aeb4: .4byte gOamXOffset_NonGameplay
lbl_0806aeb8: .4byte 0x00000412
lbl_0806aebc: .4byte 0x00000413
lbl_0806aec0: .4byte 0x040000d4
lbl_0806aec4: .4byte gOamData
lbl_0806aec8: .4byte 0x84000100
lbl_0806aecc: .4byte sub_0806a2f8
lbl_0806aed0: .4byte sNonGameplayRamPointer

    thumb_func_start determine_maps_viewable
determine_maps_viewable: @ 0x0806aed4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r3, lbl_0806aff8 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    ldr r1, lbl_0806affc @ =gEquipment
    ldrb r1, [r1, #0x10]
    adds r0, #0xba
    strb r1, [r0]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xba
    adds r1, #0xb8
    ldrb r0, [r2]
    ldrb r1, [r1]
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xba
    adds r1, #0xb9
    ldrb r0, [r2]
    ldrb r1, [r1]
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0xba
    ldrb r2, [r0]
    movs r4, #1
    movs r0, #1
    ands r0, r2
    adds r1, #0xbb
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #1
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #2
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #3
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #4
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #5
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #6
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r0, #0xbb
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_0806afe2
    movs r5, #0x93
    lsls r5, r5, #2
    ldr r0, lbl_0806b000 @ =0x00000251
    mov sl, r0
    ldr r0, lbl_0806b004 @ =sEwramPointer
    mov sb, r0
    movs r7, #0
    ldr r6, lbl_0806b008 @ =0x000090d0
    movs r4, #0x9b
    lsls r4, r4, #3
    movs r0, #0x98
    lsls r0, r0, #8
    mov r8, r0
    movs r0, #0xa0
    lsls r0, r0, #8
    mov ip, r0
lbl_0806afbe:
    mov r0, sb
    ldr r2, [r0]
    lsls r3, r5, #1
    mov r0, r8
    adds r1, r2, r0
    adds r0, r1, r3
    strh r7, [r0]
    adds r1, r1, r4
    strh r7, [r1]
    add r2, ip
    adds r3, r2, r3
    strh r6, [r3]
    adds r2, r2, r4
    strh r6, [r2]
    adds r4, #2
    adds r5, #1
    cmp r5, sl
    ble lbl_0806afbe
lbl_0806afe2:
    movs r0, #1
    movs r1, #1
    bl PauseScreenUpdateBottomVisorOverlay
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806aff8: .4byte sNonGameplayRamPointer
lbl_0806affc: .4byte gEquipment
lbl_0806b000: .4byte 0x00000251
lbl_0806b004: .4byte sEwramPointer
lbl_0806b008: .4byte 0x000090d0

    thumb_func_start PauseScreenUpdateBottomVisorOverlay
PauseScreenUpdateBottomVisorOverlay: @ 0x0806b00c
    push {r4, r5, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r0, lbl_0806b074 @ =0x0600cc40
    mov ip, r0
    ldr r0, lbl_0806b078 @ =sEwramPointer
    ldr r0, [r0]
    movs r3, #0x97
    lsls r3, r3, #8
    adds r5, r0, r3
    movs r4, #1
    rsbs r4, r4, #0
    adds r3, r4, #0
    cmp r2, #0
    beq lbl_0806b042
    movs r3, #0
    cmp r2, #1
    bne lbl_0806b042
    ldr r0, lbl_0806b07c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    bne lbl_0806b042
    movs r3, #0x16
lbl_0806b042:
    cmp r1, #0
    beq lbl_0806b05a
    movs r4, #0
    cmp r1, #1
    bne lbl_0806b05a
    ldr r0, lbl_0806b07c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbb
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0806b05a
    movs r4, #0x2d
lbl_0806b05a:
    cmp r3, #0
    bne lbl_0806b080
    cmp r4, #0
    bne lbl_0806b080
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    mov r2, ip
    movs r3, #0x80
    bl BitFill
    b lbl_0806b0ee
    .align 2, 0
lbl_0806b074: .4byte 0x0600cc40
lbl_0806b078: .4byte sEwramPointer
lbl_0806b07c: .4byte sNonGameplayRamPointer
lbl_0806b080:
    cmp r3, #0
    blt lbl_0806b0a6
    lsls r0, r3, #1
    adds r0, r0, r5
    ldrh r1, [r0]
    mov r2, ip
    strh r1, [r2, #0x2c]
    ldrh r1, [r0, #2]
    strh r1, [r2, #0x2e]
    adds r2, #0x6c
    adds r1, r0, #0
    adds r1, #0x40
    ldrh r1, [r1]
    strh r1, [r2]
    mov r1, ip
    adds r1, #0x6e
    adds r0, #0x42
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806b0a6:
    cmp r4, #0
    blt lbl_0806b0ee
    mov r3, ip
    adds r3, #0x5a
    adds r1, r4, #0
    adds r0, r1, #1
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    adds r2, r4, #0
    lsls r1, r1, #1
    adds r1, r1, r5
    ldrh r0, [r1]
    strh r0, [r3]
    adds r3, #2
    adds r0, r2, #1
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r5
    ldrh r0, [r2]
    strh r0, [r3]
    mov r2, ip
    adds r2, #0x5e
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r5
    ldrh r1, [r1]
    strh r1, [r2]
    mov r1, ip
    adds r1, #0x60
    asrs r0, r0, #0xf
    adds r0, r0, r5
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806b0ee:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start PauseScreenGetMinimapData
PauseScreenGetMinimapData: @ 0x0806b0f8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r7, r1, #0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldr r0, lbl_0806b174 @ =0x087601ec
    mov r1, r8
    lsls r4, r1, #2
    adds r0, r4, r0
    ldr r0, [r0]
    adds r1, r7, #0
    bl CallLZ77UncompWRAM
    mov r0, r8
    adds r1, r7, #0
    bl set_tiles_with_obtained_items
    ldr r6, lbl_0806b178 @ =0x0840d200
    mov r0, r8
    adds r5, r4, r0
    adds r0, r5, r6
    ldrb r4, [r0]
    cmp r4, #0
    beq lbl_0806b212
    adds r1, r4, #0
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_0806b212
    adds r0, r6, #2
    adds r0, r5, r0
    adds r1, r6, #3
    adds r1, r5, r1
    ldrb r1, [r1]
    lsls r1, r1, #5
    ldrb r0, [r0]
    adds r4, r1, r0
    mov r1, r8
    cmp r1, #5
    bne lbl_0806b184
    lsls r0, r4, #1
    adds r4, r0, r7
    ldrh r2, [r4]
    ldr r0, lbl_0806b17c @ =0x000003ff
    ldr r1, lbl_0806b180 @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1, #4]
    cmp r0, r1
    bne lbl_0806b212
    adds r1, r4, #0
    movs r3, #2
lbl_0806b164:
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b164
    b lbl_0806b212
    .align 2, 0
lbl_0806b174: .4byte 0x087601ec
lbl_0806b178: .4byte 0x0840d200
lbl_0806b17c: .4byte 0x000003ff
lbl_0806b180: .4byte 0x0840d224
lbl_0806b184:
    mov r0, r8
    cmp r0, #1
    bne lbl_0806b1d0
    lsls r0, r4, #1
    adds r3, r0, r7
    ldrh r2, [r3]
    ldr r0, lbl_0806b1c8 @ =0x000003ff
    ldr r1, lbl_0806b1cc @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1]
    cmp r0, r1
    bne lbl_0806b212
    adds r2, r3, #0
    movs r3, #1
lbl_0806b1a0:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1a0
    lsls r0, r4, #1
    adds r0, r0, r7
    adds r1, r0, #0
    adds r1, #0x40
    movs r3, #1
lbl_0806b1b8:
    ldrh r0, [r1]
    adds r0, #0x20
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1b8
    b lbl_0806b212
    .align 2, 0
lbl_0806b1c8: .4byte 0x000003ff
lbl_0806b1cc: .4byte 0x0840d224
lbl_0806b1d0:
    mov r1, r8
    cmp r1, #3
    bne lbl_0806b212
    lsls r0, r4, #1
    adds r3, r0, r7
    ldrh r2, [r3]
    ldr r0, lbl_0806b238 @ =0x000003ff
    ldr r1, lbl_0806b23c @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1, #2]
    cmp r0, r1
    bne lbl_0806b212
    adds r2, r3, #0
    movs r3, #1
lbl_0806b1ec:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1ec
    lsls r0, r4, #1
    adds r0, r0, r7
    adds r1, r0, #0
    adds r1, #0x40
    movs r3, #1
lbl_0806b204:
    ldrh r0, [r1]
    adds r0, #0x20
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b204
lbl_0806b212:
    mov r0, r8
    cmp r0, #0
    bne lbl_0806b22e
    movs r0, #3
    movs r1, #0x44
    bl EventFunction
    cmp r0, #0
    beq lbl_0806b22e
    adds r1, r7, #0
    adds r1, #0x9c
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0806b22e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806b238: .4byte 0x000003ff
lbl_0806b23c: .4byte 0x0840d224

    thumb_func_start sub_0806b240
sub_0806b240: @ 0x0806b240
    push {r4, r5, r6, lr}
    movs r6, #0
    bl CheckForMaintainedInput
    ldr r0, lbl_0806b264 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r0, [r1, #0xa]
    adds r0, #1
    strh r0, [r1, #0xa]
    ldrb r0, [r1, #4]
    cmp r0, #0x14
    bls lbl_0806b25a
    b lbl_0806b4f6
lbl_0806b25a:
    lsls r0, r0, #2
    ldr r1, lbl_0806b268 @ =lbl_0806b26c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806b264: .4byte sNonGameplayRamPointer
lbl_0806b268: .4byte lbl_0806b26c
lbl_0806b26c: @ jump table
    .4byte lbl_0806b2c0 @ case 0
    .4byte lbl_0806b2f0 @ case 1
    .4byte lbl_0806b31e @ case 2
    .4byte lbl_0806b328 @ case 3
    .4byte lbl_0806b358 @ case 4
    .4byte lbl_0806b398 @ case 5
    .4byte lbl_0806b37c @ case 6
    .4byte lbl_0806b398 @ case 7
    .4byte lbl_0806b3ac @ case 8
    .4byte lbl_0806b3c4 @ case 9
    .4byte lbl_0806b3dc @ case 10
    .4byte lbl_0806b3f4 @ case 11
    .4byte lbl_0806b418 @ case 12
    .4byte lbl_0806b430 @ case 13
    .4byte lbl_0806b45c @ case 14
    .4byte lbl_0806b430 @ case 15
    .4byte lbl_0806b478 @ case 16
    .4byte lbl_0806b498 @ case 17
    .4byte lbl_0806b44c @ case 18
    .4byte lbl_0806b4c6 @ case 19
    .4byte lbl_0806b4dc @ case 20
lbl_0806b2c0:
    ldr r2, lbl_0806b2e4 @ =gChangedInput
    ldr r0, lbl_0806b2e8 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #2
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b2dc
    ldr r0, lbl_0806b2ec @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806b324
lbl_0806b2dc:
    bl MapScreenSubroutine
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b2e4: .4byte gChangedInput
lbl_0806b2e8: .4byte gButtonAssignments
lbl_0806b2ec: .4byte sNonGameplayRamPointer
lbl_0806b2f0:
    ldr r0, lbl_0806b314 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b318
    adds r0, r2, #0
    adds r0, #0xd8
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806b30e
    movs r0, #1
    bl sub_0806b504
lbl_0806b30e:
    movs r6, #0
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b314: .4byte sNonGameplayRamPointer
lbl_0806b318:
    bl sub_08071800
    b lbl_0806b4f6
lbl_0806b31e:
    movs r0, #0xa0
    bl FadeMusic
lbl_0806b324:
    movs r6, #1
    b lbl_0806b4f6
lbl_0806b328:
    ldr r2, lbl_0806b34c @ =gChangedInput
    ldr r0, lbl_0806b350 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #3
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    bne lbl_0806b33c
    b lbl_0806b4f6
lbl_0806b33c:
    ldr r0, lbl_0806b354 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806b348
    b lbl_0806b4f6
lbl_0806b348:
    b lbl_0806b324
    .align 2, 0
lbl_0806b34c: .4byte gChangedInput
lbl_0806b350: .4byte gButtonAssignments
lbl_0806b354: .4byte sNonGameplayRamPointer
lbl_0806b358:
    bl sub_08070fb0
    cmp r0, #0
    bne lbl_0806b362
    b lbl_0806b4f6
lbl_0806b362:
    movs r0, #4
    bl sub_08068af8
    ldr r0, lbl_0806b378 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r0, #5
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b378: .4byte sNonGameplayRamPointer
lbl_0806b37c:
    bl sub_0807142c
    cmp r0, #0
    bne lbl_0806b386
    b lbl_0806b4f6
lbl_0806b386:
    ldr r0, lbl_0806b394 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r0, #7
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b394: .4byte sNonGameplayRamPointer
lbl_0806b398:
    ldr r0, lbl_0806b3a8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    cmp r0, #0xc
    bhi lbl_0806b3a4
    b lbl_0806b4f6
lbl_0806b3a4:
    b lbl_0806b324
    .align 2, 0
lbl_0806b3a8: .4byte sNonGameplayRamPointer
lbl_0806b3ac:
    bl ChozoStatueHintSubroutine
    cmp r0, #0
    bne lbl_0806b3b6
    b lbl_0806b4f6
lbl_0806b3b6:
    ldr r0, lbl_0806b3c0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xe
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3c0: .4byte sNonGameplayRamPointer
lbl_0806b3c4:
    bl PauseScreenMapDownloadSubroutine
    cmp r0, #0
    bne lbl_0806b3ce
    b lbl_0806b4f6
lbl_0806b3ce:
    ldr r0, lbl_0806b3d8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0x12
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3d8: .4byte sNonGameplayRamPointer
lbl_0806b3dc:
    bl PauseScreenEasySleepSubroutine
    cmp r0, #0
    bne lbl_0806b3e6
    b lbl_0806b4f6
lbl_0806b3e6:
    ldr r0, lbl_0806b3f0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0x11
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3f0: .4byte sNonGameplayRamPointer
lbl_0806b3f4:
    ldr r5, lbl_0806b414 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806b838
    cmp r0, #0
    bne lbl_0806b40a
    b lbl_0806b4f6
lbl_0806b40a:
    ldr r1, [r5]
    movs r0, #1
    strb r0, [r1, #4]
    b lbl_0806b4bc
    .align 2, 0
lbl_0806b414: .4byte sNonGameplayRamPointer
lbl_0806b418:
    ldr r5, lbl_0806b42c @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806ba34
    b lbl_0806b4b4
    .align 2, 0
lbl_0806b42c: .4byte sNonGameplayRamPointer
lbl_0806b430:
    ldr r1, lbl_0806b448 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    movs r3, #0
    movs r0, #8
    strb r0, [r2, #4]
    ldr r0, [r1]
    movs r2, #0
    strh r3, [r0, #0xa]
    strb r2, [r0, #8]
    ldr r0, [r1]
    strb r2, [r0, #8]
    b lbl_0806b4f2
    .align 2, 0
lbl_0806b448: .4byte sNonGameplayRamPointer
lbl_0806b44c:
    ldr r1, lbl_0806b458 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    movs r3, #0
    movs r0, #3
    b lbl_0806b4ec
    .align 2, 0
lbl_0806b458: .4byte sNonGameplayRamPointer
lbl_0806b45c:
    ldr r0, lbl_0806b474 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_0806b470
    movs r0, #2
lbl_0806b470:
    strb r0, [r2, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b474: .4byte sNonGameplayRamPointer
lbl_0806b478:
    ldr r5, lbl_0806b494 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806bc34
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, [r5]
    movs r0, #0xa
    strb r0, [r1, #4]
    b lbl_0806b4bc
    .align 2, 0
lbl_0806b494: .4byte sNonGameplayRamPointer
lbl_0806b498:
    ldr r5, lbl_0806b4ac @ =sNonGameplayRamPointer
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    beq lbl_0806b4b0
lbl_0806b4a4:
    bl sub_080681c8
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b4ac: .4byte sNonGameplayRamPointer
lbl_0806b4b0:
    bl sub_0806bf08
lbl_0806b4b4:
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r0, [r5]
    strb r4, [r0, #4]
lbl_0806b4bc:
    ldr r0, [r5]
    strb r4, [r0, #8]
    ldr r0, [r5]
    strh r4, [r0, #0xa]
    b lbl_0806b4f6
lbl_0806b4c6:
    bl sub_0806b778
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, lbl_0806b4d8 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    movs r3, #0
    movs r0, #4
    b lbl_0806b4ec
    .align 2, 0
lbl_0806b4d8: .4byte sNonGameplayRamPointer
lbl_0806b4dc:
    bl sub_0806b778
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, lbl_0806b500 @ =sNonGameplayRamPointer
    ldr r2, [r1]
    movs r3, #0
    movs r0, #6
lbl_0806b4ec:
    strb r0, [r2, #4]
    ldr r0, [r1]
    strb r3, [r0, #8]
lbl_0806b4f2:
    ldr r0, [r1]
    strh r3, [r0, #0xa]
lbl_0806b4f6:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806b500: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0806b504
sub_0806b504: @ 0x0806b504
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r4, lbl_0806b568 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    mov ip, r0
    movs r2, #0x84
    lsls r2, r2, #1
    add r2, ip
    ldrh r1, [r2]
    movs r3, #0x20
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r1
    strh r0, [r2]
    movs r2, #0x85
    lsls r2, r2, #1
    add r2, ip
    ldrh r0, [r2]
    ands r3, r0
    strh r3, [r2]
    ldr r0, lbl_0806b56c @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    adds r7, r4, #0
    cmp r0, #0
    beq lbl_0806b53e
    b lbl_0806b666
lbl_0806b53e:
    mov r1, ip
    ldrb r5, [r1, #8]
    cmp r5, #0
    beq lbl_0806b548
    b lbl_0806b666
lbl_0806b548:
    cmp r6, #0
    bne lbl_0806b5cc
    ldr r1, lbl_0806b570 @ =gChangedInput
    ldrh r4, [r1]
    movs r0, #0x10
    ands r0, r4
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0806b578
    lsls r1, r3, #0x10
    ldr r0, lbl_0806b574 @ =0x039f0000
    cmp r1, r0
    bgt lbl_0806b58a
    adds r0, r3, #0
    adds r0, #0x20
    b lbl_0806b588
    .align 2, 0
lbl_0806b568: .4byte sNonGameplayRamPointer
lbl_0806b56c: .4byte gButtonInput
lbl_0806b570: .4byte gChangedInput
lbl_0806b574: .4byte 0x039f0000
lbl_0806b578:
    movs r0, #0x20
    ands r0, r4
    cmp r0, #0
    beq lbl_0806b58a
    cmp r3, #0
    beq lbl_0806b58a
    adds r0, r3, #0
    subs r0, #0x20
lbl_0806b588:
    strh r0, [r2]
lbl_0806b58a:
    ldrh r1, [r6]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b5a8
    ldr r0, [r7]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r4, r0, r2
    ldrh r1, [r4]
    movs r2, #0
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_0806b666
    b lbl_0806b62c
lbl_0806b5a8:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b666
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r2, [r4]
    movs r0, #0
    ldrsh r1, [r4, r0]
    ldr r0, lbl_0806b5c8 @ =0x0000025f
    cmp r1, r0
    bgt lbl_0806b666
    b lbl_0806b658
    .align 2, 0
lbl_0806b5c8: .4byte 0x0000025f
lbl_0806b5cc:
    ldr r1, lbl_0806b5e8 @ =gChangedInput
    ldrh r4, [r1]
    movs r0, #0x10
    ands r0, r4
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0806b5f4
    lsls r1, r3, #0x10
    ldr r0, lbl_0806b5ec @ =0x039f0000
    cmp r1, r0
    bgt lbl_0806b5f0
    adds r0, r3, #0
    adds r0, #0x20
    b lbl_0806b60a
    .align 2, 0
lbl_0806b5e8: .4byte gChangedInput
lbl_0806b5ec: .4byte 0x039f0000
lbl_0806b5f0:
    strh r5, [r2]
    b lbl_0806b60c
lbl_0806b5f4:
    movs r0, #0x20
    ands r0, r4
    cmp r0, #0
    beq lbl_0806b60c
    cmp r3, #0
    beq lbl_0806b606
    adds r0, r3, #0
    subs r0, #0x20
    b lbl_0806b60a
lbl_0806b606:
    movs r0, #0xe8
    lsls r0, r0, #2
lbl_0806b60a:
    strh r0, [r2]
lbl_0806b60c:
    ldrh r1, [r6]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_0806b63c
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r1, [r4]
    movs r2, #0
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_0806b634
lbl_0806b62c:
    adds r0, r1, #0
    subs r0, #0x20
    strh r0, [r4]
    b lbl_0806b666
lbl_0806b634:
    movs r0, #0x98
    lsls r0, r0, #2
    strh r0, [r4]
    b lbl_0806b666
lbl_0806b63c:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b666
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r2, [r4]
    movs r0, #0
    ldrsh r1, [r4, r0]
    ldr r0, lbl_0806b660 @ =0x0000025f
    cmp r1, r0
    bgt lbl_0806b664
lbl_0806b658:
    adds r0, r2, #0
    adds r0, #0x20
    strh r0, [r4]
    b lbl_0806b666
    .align 2, 0
lbl_0806b660: .4byte 0x0000025f
lbl_0806b664:
    strh r3, [r4]
lbl_0806b666:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0806b66c
sub_0806b66c: @ 0x0806b66c
    push {r4, r5, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r5, #0
    ldrh r3, [r2]
    movs r4, #1
    cmp r3, r1
    bls lbl_0806b680
    subs r4, #2
lbl_0806b680:
    ldr r0, lbl_0806b690 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    adds r0, #4
    cmp r0, #0x1f
    bgt lbl_0806b694
    muls r0, r4, r0
    b lbl_0806b696
    .align 2, 0
lbl_0806b690: .4byte sNonGameplayRamPointer
lbl_0806b694:
    lsls r0, r4, #5
lbl_0806b696:
    adds r0, r3, r0
    strh r0, [r2]
    cmp r4, #0
    ble lbl_0806b6a8
    ldrh r0, [r2]
    cmp r0, r1
    blo lbl_0806b6ba
    strh r1, [r2]
    b lbl_0806b6b8
lbl_0806b6a8:
    movs r3, #0
    ldrsh r0, [r2, r3]
    cmp r0, r1
    bgt lbl_0806b6ba
    subs r0, r1, r0
    ldrh r1, [r2]
    adds r0, r0, r1
    strh r0, [r2]
lbl_0806b6b8:
    movs r5, #1
lbl_0806b6ba:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806b6c4
sub_0806b6c4: @ 0x0806b6c4
    push {r4, r5, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    movs r5, #0
    ldrh r2, [r3]
    movs r1, #1
    cmp r2, r4
    bls lbl_0806b6d8
    subs r1, #2
lbl_0806b6d8:
    ldr r0, lbl_0806b6e8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    adds r0, #4
    cmp r0, #0x1f
    bgt lbl_0806b6ec
    muls r0, r1, r0
    b lbl_0806b6ee
    .align 2, 0
lbl_0806b6e8: .4byte sNonGameplayRamPointer
lbl_0806b6ec:
    lsls r0, r1, #5
lbl_0806b6ee:
    adds r0, r2, r0
    strh r0, [r3]
    cmp r1, #0
    ble lbl_0806b700
    ldrh r0, [r3]
    cmp r0, r4
    blo lbl_0806b70a
    movs r5, #1
    b lbl_0806b70e
lbl_0806b700:
    movs r1, #0
    ldrsh r0, [r3, r1]
    cmp r0, r4
    bgt lbl_0806b70a
    movs r5, #1
lbl_0806b70a:
    cmp r5, #0
    beq lbl_0806b710
lbl_0806b70e:
    strh r4, [r3]
lbl_0806b710:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_0806b718
sub_0806b718: @ 0x0806b718
    push {r4, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r4, r1, #0
    cmp r1, #0xff
    beq lbl_0806b734
    ldr r0, lbl_0806b76c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x87
    lsls r2, r2, #3
    adds r0, r0, r2
    bl UpdateMenuOamDataID
lbl_0806b734:
    movs r0, #1
    cmp r4, #0xf
    beq lbl_0806b748
    movs r0, #2
    cmp r4, #0x10
    beq lbl_0806b748
    movs r0, #3
    cmp r4, #0
    bne lbl_0806b748
    movs r0, #0
lbl_0806b748:
    ldr r1, lbl_0806b770 @ =sEwramPointer
    lsls r0, r0, #7
    movs r2, #0x95
    lsls r2, r2, #8
    adds r0, r0, r2
    ldr r1, [r1]
    adds r1, r1, r0
    ldr r2, lbl_0806b774 @ =0x0600c800
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806b76c: .4byte sNonGameplayRamPointer
lbl_0806b770: .4byte sEwramPointer
lbl_0806b774: .4byte 0x0600c800

    thumb_func_start sub_0806b778
sub_0806b778: @ 0x0806b778
    push {r4, r5, lr}
    sub sp, #4
    movs r4, #0
    ldr r5, lbl_0806b794 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    ldrb r0, [r1, #8]
    cmp r0, #1
    beq lbl_0806b7a2
    cmp r0, #1
    bgt lbl_0806b798
    cmp r0, #0
    beq lbl_0806b7a8
    b lbl_0806b7fa
    .align 2, 0
lbl_0806b794: .4byte sNonGameplayRamPointer
lbl_0806b798:
    cmp r0, #2
    beq lbl_0806b7ae
    cmp r0, #3
    beq lbl_0806b7c0
    b lbl_0806b7fa
lbl_0806b7a2:
    movs r0, #3
    bl sub_08068af8
lbl_0806b7a8:
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b7fe
lbl_0806b7ae:
    ldrb r0, [r1, #0xa]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    bl draw_status_screen_item
    cmp r0, #0
    beq lbl_0806b7fa
    b lbl_0806b7a8
lbl_0806b7c0:
    ldr r0, lbl_0806b810 @ =gCurrentItemBeingAcquired
    ldrb r1, [r0]
    movs r0, #2
    bl sub_08070020
    ldr r1, [r5]
    adds r1, #0xc1
    strb r0, [r1]
    bl sub_08070f6c
    ldr r1, [r5]
    adds r1, #0x5c
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r2, lbl_0806b814 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806b7fa:
    cmp r4, #0
    ble lbl_0806b82a
lbl_0806b7fe:
    cmp r4, #0xff
    ble lbl_0806b81c
    ldr r2, lbl_0806b818 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    adds r1, r2, #0
    b lbl_0806b822
    .align 2, 0
lbl_0806b810: .4byte gCurrentItemBeingAcquired
lbl_0806b814: .4byte 0x06007800
lbl_0806b818: .4byte sNonGameplayRamPointer
lbl_0806b81c:
    ldr r1, lbl_0806b834 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    strb r4, [r0, #8]
lbl_0806b822:
    ldr r1, [r1]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
lbl_0806b82a:
    adds r0, r4, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806b834: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0806b838
sub_0806b838: @ 0x0806b838
    push {r4, lr}
    sub sp, #4
    movs r4, #0
    ldr r1, lbl_0806b858 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #9
    bls lbl_0806b84c
    b lbl_0806b9d6
lbl_0806b84c:
    lsls r0, r0, #2
    ldr r1, lbl_0806b85c @ =lbl_0806b860
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806b858: .4byte sNonGameplayRamPointer
lbl_0806b85c: .4byte lbl_0806b860
lbl_0806b860: @ jump table
    .4byte lbl_0806b888 @ case 0
    .4byte lbl_0806b8e0 @ case 1
    .4byte lbl_0806b8f4 @ case 2
    .4byte lbl_0806b912 @ case 3
    .4byte lbl_0806b93c @ case 4
    .4byte lbl_0806b944 @ case 5
    .4byte lbl_0806b950 @ case 6
    .4byte lbl_0806b95c @ case 7
    .4byte lbl_0806b974 @ case 8
    .4byte lbl_0806b9ac @ case 9
lbl_0806b888:
    ldr r0, lbl_0806b8ac @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0806b8b8
    ldr r0, lbl_0806b8b0 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806b8b4 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806b8d2
    .align 2, 0
lbl_0806b8ac: .4byte gEquipment
lbl_0806b8b0: .4byte sEwramPointer
lbl_0806b8b4: .4byte 0x0600c000
lbl_0806b8b8:
    ldr r0, lbl_0806b8d8 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0xf0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806b8dc @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806b8d2:
    movs r4, #1
    b lbl_0806b9da
    .align 2, 0
lbl_0806b8d8: .4byte sEwramPointer
lbl_0806b8dc: .4byte 0x0600c000
lbl_0806b8e0:
    movs r0, #0xf
    bl sub_0806b718
    movs r4, #0x80
    lsls r4, r4, #1
    movs r0, #0xfa
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0806b9d6
lbl_0806b8f4:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806b9d6
    movs r0, #2
    movs r1, #2
    bl PauseScreenUpdateBottomVisorOverlay
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b912:
    ldr r0, lbl_0806b934 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x80
    orrs r0, r1
    strh r0, [r2]
    adds r0, r2, #0
    adds r0, #0x74
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0x62
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_0806b938 @ =0x00003c44
    strh r0, [r1]
    movs r0, #1
    b lbl_0806b952
    .align 2, 0
lbl_0806b934: .4byte sNonGameplayRamPointer
lbl_0806b938: .4byte 0x00003c44
lbl_0806b93c:
    movs r0, #2
    bl sub_08068af8
    b lbl_0806b96a
lbl_0806b944:
    movs r0, #0x10
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    b lbl_0806b96a
lbl_0806b950:
    movs r0, #3
lbl_0806b952:
    bl sub_08068af8
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b95c:
    ldr r0, [r2]
    ldrb r0, [r0, #0xa]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    bl draw_status_screen_item
lbl_0806b96a:
    cmp r0, #0
    beq lbl_0806b9d6
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b974:
    bl sub_08070f6c
    ldr r0, lbl_0806b9a4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x5c
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r2, lbl_0806b9a8 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r4, #1
    rsbs r4, r4, #0
    b lbl_0806ba14
    .align 2, 0
lbl_0806b9a4: .4byte sNonGameplayRamPointer
lbl_0806b9a8: .4byte 0x06007800
lbl_0806b9ac:
    ldr r3, [r2]
    adds r0, r3, #0
    adds r0, #0x78
    ldrh r0, [r0]
    adds r1, r3, #0
    adds r1, #0x62
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    ldr r0, lbl_0806b9ec @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_0806b9f0 @ =0x00000433
    adds r2, r3, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806b9d6:
    cmp r4, #0
    ble lbl_0806ba10
lbl_0806b9da:
    cmp r4, #0xff
    ble lbl_0806b9f8
    ldr r2, lbl_0806b9f4 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_0806ba00
    .align 2, 0
lbl_0806b9ec: .4byte 0x0000fdff
lbl_0806b9f0: .4byte 0x00000433
lbl_0806b9f4: .4byte sNonGameplayRamPointer
lbl_0806b9f8:
    ldr r1, lbl_0806ba0c @ =sNonGameplayRamPointer
    ldr r0, [r1]
    strb r4, [r0, #8]
    adds r2, r1, #0
lbl_0806ba00:
    ldr r1, [r2]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
    b lbl_0806ba20
    .align 2, 0
lbl_0806ba0c: .4byte sNonGameplayRamPointer
lbl_0806ba10:
    cmp r4, #0
    bge lbl_0806ba20
lbl_0806ba14:
    ldr r1, lbl_0806ba2c @ =gWrittenToBLDALPHA_H
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0806ba30 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
lbl_0806ba20:
    adds r0, r4, #0
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806ba2c: .4byte gWrittenToBLDALPHA_H
lbl_0806ba30: .4byte gWrittenToBLDALPHA_L

    thumb_func_start sub_0806ba34
sub_0806ba34: @ 0x0806ba34
    push {r4, r5, lr}
    movs r4, #0
    ldr r1, lbl_0806ba50 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r5, r1, #0
    cmp r0, #8
    bls lbl_0806ba46
    b lbl_0806bbd0
lbl_0806ba46:
    lsls r0, r0, #2
    ldr r1, lbl_0806ba54 @ =lbl_0806ba58
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806ba50: .4byte sNonGameplayRamPointer
lbl_0806ba54: .4byte lbl_0806ba58
lbl_0806ba58: @ jump table
    .4byte lbl_0806ba7c @ case 0
    .4byte lbl_0806baa4 @ case 1
    .4byte lbl_0806bac8 @ case 2
    .4byte lbl_0806bad8 @ case 3
    .4byte lbl_0806bb18 @ case 4
    .4byte lbl_0806bb40 @ case 5
    .4byte lbl_0806bb76 @ case 6
    .4byte lbl_0806bb9c @ case 7
    .4byte lbl_0806bbc4 @ case 8
lbl_0806ba7c:
    ldr r0, lbl_0806ba9c @ =0x000001f5
    bl SoundPlay
    ldr r0, lbl_0806baa0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0
    strb r0, [r1]
    bl sub_0806b718
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806ba9c: .4byte 0x000001f5
lbl_0806baa0: .4byte sNonGameplayRamPointer
lbl_0806baa4:
    movs r0, #4
    bl sub_08068af8
    ldr r0, lbl_0806bac0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldr r4, lbl_0806bac4 @ =0x00000123
    adds r2, r0, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bac0: .4byte sNonGameplayRamPointer
lbl_0806bac4: .4byte 0x00000123
lbl_0806bac8:
    ldr r0, [r5]
    ldrh r0, [r0, #0xa]
    cmp r0, #0xc
    bhi lbl_0806bad2
    b lbl_0806bbd0
lbl_0806bad2:
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
lbl_0806bad8:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bbd0
    ldr r0, lbl_0806bb0c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x5c
    ldrh r2, [r3]
    ldr r0, lbl_0806bb10 @ =0x0000feff
    ands r0, r2
    strh r0, [r3]
    ldr r0, lbl_0806bb14 @ =0x00000463
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb0c: .4byte sNonGameplayRamPointer
lbl_0806bb10: .4byte 0x0000feff
lbl_0806bb14: .4byte 0x00000463
lbl_0806bb18:
    ldr r4, lbl_0806bb38 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x66
    movs r5, #0
    ldr r1, lbl_0806bb3c @ =0x00003844
    strh r1, [r0]
    movs r0, #5
    bl sub_08068af8
    ldr r0, [r4]
    adds r0, #0x57
    strb r5, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb38: .4byte sNonGameplayRamPointer
lbl_0806bb3c: .4byte 0x00003844
lbl_0806bb40:
    ldr r1, lbl_0806bb8c @ =gWrittenToBLDALPHA_H
    movs r0, #0x10
    strh r0, [r1]
    ldr r1, lbl_0806bb90 @ =gWrittenToBLDALPHA_L
    movs r0, #0
    strh r0, [r1]
    ldr r2, [r5]
    adds r3, r2, #0
    adds r3, #0x5c
    ldrh r0, [r3]
    movs r4, #0x80
    lsls r4, r4, #2
    adds r1, r4, #0
    orrs r0, r1
    strh r0, [r3]
    ldr r0, lbl_0806bb94 @ =0x00000433
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r5]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
lbl_0806bb76:
    ldr r0, lbl_0806bb98 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x72
    ldrh r1, [r1]
    adds r0, #0x62
    strh r1, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb8c: .4byte gWrittenToBLDALPHA_H
lbl_0806bb90: .4byte gWrittenToBLDALPHA_L
lbl_0806bb94: .4byte 0x00000433
lbl_0806bb98: .4byte sNonGameplayRamPointer
lbl_0806bb9c:
    ldr r0, [r5]
    adds r0, #0x68
    ldrh r0, [r0]
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bbd0
    ldr r2, [r5]
    ldrh r1, [r2]
    ldr r0, lbl_0806bbc0 @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bbc0: .4byte 0x0000ff7f
lbl_0806bbc4:
    movs r0, #1
    movs r1, #1
    bl PauseScreenUpdateBottomVisorOverlay
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806bbd0:
    cmp r4, #0
    ble lbl_0806bc04
lbl_0806bbd4:
    cmp r4, #0xff
    ble lbl_0806bbec
    ldr r2, lbl_0806bbe8 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    adds r5, r2, #0
    b lbl_0806bbf4
    .align 2, 0
lbl_0806bbe8: .4byte sNonGameplayRamPointer
lbl_0806bbec:
    ldr r1, lbl_0806bc00 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    strb r4, [r0, #8]
    adds r5, r1, #0
lbl_0806bbf4:
    ldr r1, [r5]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
    b lbl_0806bc1e
    .align 2, 0
lbl_0806bc00: .4byte sNonGameplayRamPointer
lbl_0806bc04:
    cmp r4, #0
    bge lbl_0806bc1e
    ldr r1, lbl_0806bc28 @ =gWrittenToBLDALPHA_H
    ldr r0, lbl_0806bc2c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x68
    ldrh r2, [r0]
    lsrs r0, r2, #8
    strh r0, [r1]
    ldr r1, lbl_0806bc30 @ =gWrittenToBLDALPHA_L
    movs r0, #0xff
    ands r0, r2
    strh r0, [r1]
lbl_0806bc1e:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806bc28: .4byte gWrittenToBLDALPHA_H
lbl_0806bc2c: .4byte sNonGameplayRamPointer
lbl_0806bc30: .4byte gWrittenToBLDALPHA_L

    thumb_func_start sub_0806bc34
sub_0806bc34: @ 0x0806bc34
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r4, lbl_0806bc60 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xe9
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    blt lbl_0806bc4c
    bl sub_0806fbb8
lbl_0806bc4c:
    ldr r0, [r4]
    ldrb r0, [r0, #8]
    cmp r0, #0xb
    bls lbl_0806bc56
    b lbl_0806bef0
lbl_0806bc56:
    lsls r0, r0, #2
    ldr r1, lbl_0806bc64 @ =lbl_0806bc68
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806bc60: .4byte sNonGameplayRamPointer
lbl_0806bc64: .4byte lbl_0806bc68
lbl_0806bc68: @ jump table
    .4byte lbl_0806bc98 @ case 0
    .4byte lbl_0806bc9e @ case 1
    .4byte lbl_0806bcc4 @ case 2
    .4byte lbl_0806bce8 @ case 3
    .4byte lbl_0806bd1c @ case 4
    .4byte lbl_0806bef0 @ case 5
    .4byte lbl_0806bd50 @ case 6
    .4byte lbl_0806bdbc @ case 7
    .4byte lbl_0806be04 @ case 8
    .4byte lbl_0806be58 @ case 9
    .4byte lbl_0806be7a @ case 10
    .4byte lbl_0806be9c @ case 11
lbl_0806bc98:
    movs r0, #0x80
    lsls r0, r0, #5
    b lbl_0806be7c
lbl_0806bc9e:
    movs r0, #2
    movs r1, #2
    bl PauseScreenUpdateBottomVisorOverlay
    movs r0, #0x10
    bl sub_0806b718
    ldr r0, lbl_0806bcbc @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x5c
    ldrh r2, [r1]
    ldr r0, lbl_0806bcc0 @ =0x0000fbff
    ands r0, r2
    strh r0, [r1]
    b lbl_0806bef0
    .align 2, 0
lbl_0806bcbc: .4byte sNonGameplayRamPointer
lbl_0806bcc0: .4byte 0x0000fbff
lbl_0806bcc4:
    ldr r0, lbl_0806bce0 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0x88
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806bce4 @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806bef0
    .align 2, 0
lbl_0806bce0: .4byte sEwramPointer
lbl_0806bce4: .4byte 0x0600d000
lbl_0806bce8:
    ldr r1, lbl_0806bd10 @ =0x06006000
    ldr r5, lbl_0806bd14 @ =sEwramPointer
    ldr r2, [r5]
    movs r3, #0xa8
    lsls r3, r3, #8
    adds r2, r2, r3
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0806bd18 @ =0x06006800
    ldr r2, [r5]
    movs r0, #0xb0
    lsls r0, r0, #8
    adds r2, r2, r0
    b lbl_0806be3c
    .align 2, 0
lbl_0806bd10: .4byte 0x06006000
lbl_0806bd14: .4byte sEwramPointer
lbl_0806bd18: .4byte 0x06006800
lbl_0806bd1c:
    ldr r1, lbl_0806bd44 @ =0x06007000
    ldr r5, lbl_0806bd48 @ =sEwramPointer
    ldr r2, [r5]
    movs r3, #0xb8
    lsls r3, r3, #8
    adds r2, r2, r3
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0806bd4c @ =0x06007800
    ldr r2, [r5]
    movs r0, #0xc0
    lsls r0, r0, #8
    adds r2, r2, r0
    b lbl_0806be3c
    .align 2, 0
lbl_0806bd44: .4byte 0x06007000
lbl_0806bd48: .4byte sEwramPointer
lbl_0806bd4c: .4byte 0x06007800
lbl_0806bd50:
    ldr r0, lbl_0806bda8 @ =0x040000d4
    ldr r1, lbl_0806bdac @ =sEwramPointer
    ldr r2, [r1]
    movs r3, #0xc0
    lsls r3, r3, #7
    adds r1, r2, r3
    str r1, [r0]
    movs r4, #0x87
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    ldr r3, lbl_0806bdb0 @ =0x80000040
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    movs r4, #0xc8
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0]
    movs r4, #0x8f
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    ldr r4, lbl_0806bdb4 @ =0x000061c0
    adds r1, r2, r4
    str r1, [r0]
    movs r4, #0x97
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    ldr r4, lbl_0806bdb8 @ =0x000065c0
    adds r1, r2, r4
    str r1, [r0]
    movs r1, #0x9f
    lsls r1, r1, #7
    adds r2, r2, r1
    str r2, [r0, #4]
    str r3, [r0, #8]
    ldr r0, [r0, #8]
    b lbl_0806bef0
    .align 2, 0
lbl_0806bda8: .4byte 0x040000d4
lbl_0806bdac: .4byte sEwramPointer
lbl_0806bdb0: .4byte 0x80000040
lbl_0806bdb4: .4byte 0x000061c0
lbl_0806bdb8: .4byte 0x000065c0
lbl_0806bdbc:
    ldr r0, lbl_0806bdf4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xe9
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0806be8c
    ldr r5, lbl_0806bdf8 @ =sEwramPointer
    ldr r1, [r5]
    movs r3, #0x80
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806bdfc @ =0x06006000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0x90
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806be00 @ =0x06006800
    b lbl_0806be3c
    .align 2, 0
lbl_0806bdf4: .4byte sNonGameplayRamPointer
lbl_0806bdf8: .4byte sEwramPointer
lbl_0806bdfc: .4byte 0x06006000
lbl_0806be00: .4byte 0x06006800
lbl_0806be04:
    ldr r0, lbl_0806be48 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xe9
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bge lbl_0806be8c
    ldr r5, lbl_0806be4c @ =sEwramPointer
    ldr r1, [r5]
    movs r3, #0xa0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806be50 @ =0x06007000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xb0
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806be54 @ =0x06007800
lbl_0806be3c:
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0806bef0
    .align 2, 0
lbl_0806be48: .4byte sNonGameplayRamPointer
lbl_0806be4c: .4byte sEwramPointer
lbl_0806be50: .4byte 0x06007000
lbl_0806be54: .4byte 0x06007800
lbl_0806be58:
    ldr r0, lbl_0806be94 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806be98 @ =0x00003c44
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
lbl_0806be7a:
    movs r0, #0x10
lbl_0806be7c:
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    bne lbl_0806bef0
    ldr r0, lbl_0806be94 @ =sNonGameplayRamPointer
    ldr r1, [r0]
lbl_0806be8c:
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    b lbl_0806bef0
    .align 2, 0
lbl_0806be94: .4byte sNonGameplayRamPointer
lbl_0806be98: .4byte 0x00003c44
lbl_0806be9c:
    ldr r5, lbl_0806bee8 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    movs r4, #0x8c
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #2
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    movs r0, #0x8d
    lsls r0, r0, #1
    adds r6, r1, r0
    movs r2, #0
    movs r3, #0
    adds r0, #0xf6
    strh r0, [r6]
    adds r4, r1, r4
    movs r0, #0x88
    lsls r0, r0, #1
    strh r0, [r4]
    adds r0, #0x13
    adds r4, r1, r0
    ldrb r1, [r4]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r4]
    ldr r1, lbl_0806beec @ =gDisableSoftreset
    movs r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    strb r2, [r0, #8]
    ldr r0, [r5]
    strh r3, [r0, #0xa]
    movs r0, #1
    b lbl_0806befc
    .align 2, 0
lbl_0806bee8: .4byte sNonGameplayRamPointer
lbl_0806beec: .4byte gDisableSoftreset
lbl_0806bef0:
    ldr r0, lbl_0806bf04 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    movs r0, #0
lbl_0806befc:
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806bf04: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0806bf08
sub_0806bf08: @ 0x0806bf08
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r1, lbl_0806bf24 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #8
    bls lbl_0806bf1a
    b lbl_0806c0c8
lbl_0806bf1a:
    lsls r0, r0, #2
    ldr r1, lbl_0806bf28 @ =lbl_0806bf2c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806bf24: .4byte sNonGameplayRamPointer
lbl_0806bf28: .4byte lbl_0806bf2c
lbl_0806bf2c: @ jump table
    .4byte lbl_0806bf50 @ case 0
    .4byte lbl_0806bf66 @ case 1
    .4byte lbl_0806bf88 @ case 2
    .4byte lbl_0806bfc4 @ case 3
    .4byte lbl_0806bff0 @ case 4
    .4byte lbl_0806c024 @ case 5
    .4byte lbl_0806c064 @ case 6
    .4byte lbl_0806c084 @ case 7
    .4byte lbl_0806c0ac @ case 8
lbl_0806bf50:
    ldr r1, lbl_0806bf80 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    movs r0, #0
    bl sub_0806b718
    ldr r0, lbl_0806bf84 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
lbl_0806bf66:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bf78
    b lbl_0806c0c8
lbl_0806bf78:
    ldr r0, lbl_0806bf84 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_0806c09a
    .align 2, 0
lbl_0806bf80: .4byte gDisableSoftreset
lbl_0806bf84: .4byte sNonGameplayRamPointer
lbl_0806bf88:
    ldr r4, lbl_0806bfb8 @ =sNonGameplayRamPointer
    ldr r3, [r4]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    ldr r0, lbl_0806bfbc @ =0x0000fbff
    ands r0, r1
    strh r0, [r2]
    movs r1, #0x8c
    lsls r1, r1, #1
    adds r0, r3, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    ldr r4, lbl_0806bfc0 @ =0x00000123
    adds r2, r0, r4
    ldrb r1, [r2]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806bfb8: .4byte sNonGameplayRamPointer
lbl_0806bfbc: .4byte 0x0000fbff
lbl_0806bfc0: .4byte 0x00000123
lbl_0806bfc4:
    ldr r1, lbl_0806bfe0 @ =0x040000d4
    ldr r0, lbl_0806bfe4 @ =sEwramPointer
    ldr r0, [r0]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r0, r0, r2
    str r0, [r1]
    ldr r0, lbl_0806bfe8 @ =0x0600d000
    str r0, [r1, #4]
    ldr r0, lbl_0806bfec @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806bfe0: .4byte 0x040000d4
lbl_0806bfe4: .4byte sEwramPointer
lbl_0806bfe8: .4byte 0x0600d000
lbl_0806bfec: .4byte 0x80000400
lbl_0806bff0:
    ldr r5, lbl_0806c018 @ =sEwramPointer
    ldr r1, [r5]
    movs r4, #0xa8
    lsls r4, r4, #8
    adds r1, r1, r4
    ldr r2, lbl_0806c01c @ =0x06006000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xb0
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806c020 @ =0x06006800
    b lbl_0806c04a
    .align 2, 0
lbl_0806c018: .4byte sEwramPointer
lbl_0806c01c: .4byte 0x06006000
lbl_0806c020: .4byte 0x06006800
lbl_0806c024:
    ldr r5, lbl_0806c058 @ =sEwramPointer
    ldr r1, [r5]
    movs r2, #0xb8
    lsls r2, r2, #8
    adds r1, r1, r2
    ldr r2, lbl_0806c05c @ =0x06007000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xc0
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806c060 @ =0x06007800
lbl_0806c04a:
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0806c0c8
    .align 2, 0
lbl_0806c058: .4byte sEwramPointer
lbl_0806c05c: .4byte 0x06007000
lbl_0806c060: .4byte 0x06007800
lbl_0806c064:
    ldr r3, [r2]
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806c0a4 @ =0x00003844
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
lbl_0806c084:
    ldr r4, lbl_0806c0a8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x68
    ldrh r0, [r0]
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    bne lbl_0806c0c8
    ldr r1, [r4]
lbl_0806c09a:
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806c0a4: .4byte 0x00003844
lbl_0806c0a8: .4byte sNonGameplayRamPointer
lbl_0806c0ac:
    movs r0, #1
    movs r1, #1
    bl PauseScreenUpdateBottomVisorOverlay
    ldr r2, lbl_0806c0c4 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    movs r1, #0
    strb r1, [r0, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    movs r0, #1
    b lbl_0806c0d4
    .align 2, 0
lbl_0806c0c4: .4byte sNonGameplayRamPointer
lbl_0806c0c8:
    ldr r0, lbl_0806c0dc @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    movs r0, #0
lbl_0806c0d4:
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806c0dc: .4byte sNonGameplayRamPointer

    thumb_func_start CheckForMaintainedInput
CheckForMaintainedInput: @ 0x0806c0e0
    push {r4, lr}
    ldr r1, lbl_0806c104 @ =gUnk_3005804
    ldr r2, lbl_0806c108 @ =gChangedInput
    ldrh r0, [r2]
    strh r0, [r1]
    ldr r1, lbl_0806c10c @ =gButtonInput
    ldrh r0, [r1]
    movs r3, #0xf0
    ands r3, r0
    adds r4, r1, #0
    cmp r3, #0
    beq lbl_0806c114
    ldr r1, lbl_0806c110 @ =gMaintainedInputData
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r3, r1, #0
    b lbl_0806c11c
    .align 2, 0
lbl_0806c104: .4byte gUnk_3005804
lbl_0806c108: .4byte gChangedInput
lbl_0806c10c: .4byte gButtonInput
lbl_0806c110: .4byte gMaintainedInputData
lbl_0806c114:
    ldr r0, lbl_0806c14c @ =gMaintainedInputData
    strb r3, [r0]
    strb r3, [r0, #1]
    adds r3, r0, #0
lbl_0806c11c:
    ldr r0, lbl_0806c150 @ =0x0840d66c
    ldrb r1, [r3, #1]
    adds r1, r1, r0
    ldrb r0, [r3]
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806c144
    ldrh r1, [r4]
    movs r0, #0xf0
    ands r0, r1
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
    movs r0, #0
    strb r0, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #5
    bhi lbl_0806c144
    adds r0, #1
    strb r0, [r3, #1]
lbl_0806c144:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c14c: .4byte gMaintainedInputData
lbl_0806c150: .4byte 0x0840d66c

    thumb_func_start update_minimap
update_minimap: @ 0x0806c154
    push {lr}
    bl check_for_unexplored_minimap_tile
    ldr r0, lbl_0806c174 @ =gUpdateMinimapFlag
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_0806c16a
    bl set_minimap_tile_explored
    bl update_minimap_for_explored_tiles
lbl_0806c16a:
    bl MinimapDraw
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c174: .4byte gUpdateMinimapFlag

    thumb_func_start set_minimap_tile_explored
set_minimap_tile_explored: @ 0x0806c178
    push {lr}
    ldr r0, lbl_0806c1ac @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806c1a8
    ldr r0, lbl_0806c1b0 @ =gCurrentArea
    ldrb r2, [r0]
    ldr r0, lbl_0806c1b4 @ =gMinimapY
    lsls r2, r2, #5
    ldrb r0, [r0]
    adds r2, r2, r0
    ldr r0, lbl_0806c1b8 @ =0x08754bc0
    ldr r0, [r0]
    lsls r2, r2, #2
    adds r2, r2, r0
    ldr r1, lbl_0806c1bc @ =0x08760218
    ldr r0, lbl_0806c1c0 @ =gMinimapX
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2]
    ldr r0, [r0]
    orrs r1, r0
    str r1, [r2]
lbl_0806c1a8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c1ac: .4byte gShipLandingFlag
lbl_0806c1b0: .4byte gCurrentArea
lbl_0806c1b4: .4byte gMinimapY
lbl_0806c1b8: .4byte 0x08754bc0
lbl_0806c1bc: .4byte 0x08760218
lbl_0806c1c0: .4byte gMinimapX

    thumb_func_start sub_0806c1c4
sub_0806c1c4: @ 0x0806c1c4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    ldr r0, lbl_0806c21c @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806c1e0
    b lbl_0806c372
lbl_0806c1e0:
    ldr r0, lbl_0806c220 @ =gLastAreaNameVisited
    ldrb r1, [r0]
    mov ip, r0
    cmp r1, #0
    bne lbl_0806c1ec
    b lbl_0806c372
lbl_0806c1ec:
    movs r4, #0
    movs r6, #0
    ldr r0, [sp]
    cmp r0, #1
    bne lbl_0806c236
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806c2a6
    movs r6, #0x7f
    ands r6, r1
    ldr r1, lbl_0806c224 @ =0x0840d684
    lsls r0, r6, #1
    adds r0, r0, r6
    lsls r0, r0, #2
    adds r3, r0, r1
    ldr r0, lbl_0806c228 @ =gAreaBeforeTransition
    ldrb r1, [r3]
    ldrb r2, [r0]
    cmp r1, r2
    bne lbl_0806c22c
    movs r4, #1
    b lbl_0806c2a6
    .align 2, 0
lbl_0806c21c: .4byte gShipLandingFlag
lbl_0806c220: .4byte gLastAreaNameVisited
lbl_0806c224: .4byte 0x0840d684
lbl_0806c228: .4byte gAreaBeforeTransition
lbl_0806c22c:
    ldrb r0, [r3, #5]
    cmp r0, r2
    bne lbl_0806c2a6
    movs r4, #2
    b lbl_0806c2a6
lbl_0806c236:
    ldr r1, lbl_0806c264 @ =0x0840d684
    mov r8, r1
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_0806c294
    mov r5, ip
    ldrb r2, [r5, #1]
    movs r3, #0
lbl_0806c246:
    ldrb r0, [r1]
    cmp r0, r2
    bne lbl_0806c268
    mov r7, ip
    ldrb r0, [r7, #2]
    ldrb r7, [r1, #1]
    cmp r0, r7
    bne lbl_0806c280
    ldrb r0, [r5, #3]
    ldrb r7, [r1, #2]
    cmp r0, r7
    bne lbl_0806c280
    movs r4, #1
    b lbl_0806c298
    .align 2, 0
lbl_0806c264: .4byte 0x0840d684
lbl_0806c268:
    ldrb r0, [r1, #5]
    cmp r0, r2
    bne lbl_0806c280
    ldrb r0, [r5, #2]
    ldrb r7, [r1, #6]
    cmp r0, r7
    bne lbl_0806c280
    ldrb r0, [r5, #3]
    ldrb r7, [r1, #7]
    cmp r0, r7
    bne lbl_0806c280
    movs r4, #2
lbl_0806c280:
    cmp r4, #0
    bne lbl_0806c298
    adds r3, #0xc
    adds r1, #0xc
    adds r6, #1
    mov r7, r8
    adds r0, r3, r7
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_0806c246
lbl_0806c294:
    cmp r4, #0
    beq lbl_0806c2a6
lbl_0806c298:
    movs r0, #0x80
    rsbs r0, r0, #0
    adds r1, r0, #0
    adds r0, r6, #0
    orrs r0, r1
    mov r1, ip
    strb r0, [r1]
lbl_0806c2a6:
    cmp r4, #1
    bne lbl_0806c2cc
    ldr r0, lbl_0806c2c8 @ =0x0840d684
    lsls r1, r6, #1
    adds r1, r1, r6
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r5, [r1]
    ldrb r3, [r1, #1]
    movs r0, #3
    ldrsb r0, [r1, r0]
    adds r0, r3, r0
    subs r4, r0, #1
    ldrb r2, [r1, #2]
    movs r0, #4
    ldrsb r0, [r1, r0]
    b lbl_0806c2f4
    .align 2, 0
lbl_0806c2c8: .4byte 0x0840d684
lbl_0806c2cc:
    cmp r4, #2
    beq lbl_0806c2d8
    movs r0, #0
    mov r1, ip
    strb r0, [r1]
    b lbl_0806c372
lbl_0806c2d8:
    ldr r0, lbl_0806c384 @ =0x0840d684
    lsls r1, r6, #1
    adds r1, r1, r6
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r5, [r1, #5]
    ldrb r3, [r1, #6]
    movs r0, #8
    ldrsb r0, [r1, r0]
    adds r0, r3, r0
    subs r4, r0, #1
    ldrb r2, [r1, #7]
    movs r0, #9
    ldrsb r0, [r1, r0]
lbl_0806c2f4:
    adds r0, r2, r0
    subs r1, r0, #1
    subs r3, #1
    mov r7, ip
    strb r3, [r7, #2]
    subs r2, #1
    strb r2, [r7, #3]
    lsls r0, r1, #5
    adds r0, r4, r0
    lsls r0, r0, #1
    ldr r2, lbl_0806c388 @ =0x02034800
    adds r3, r0, r2
    lsls r0, r5, #5
    adds r5, r0, r1
    movs r6, #0
    mov sl, r0
    ldr r1, lbl_0806c38c @ =0x08760218
    lsls r0, r4, #2
    adds r7, r0, r1
    ldr r0, lbl_0806c390 @ =0xfffffebf
    mov sb, r0
    ldr r1, lbl_0806c394 @ =0x08754bc0
    mov r8, r1
lbl_0806c322:
    ldrh r0, [r3]
    ldr r4, lbl_0806c398 @ =0x000003ff
    ands r4, r0
    mov r2, sb
    adds r0, r4, r2
    cmp r0, #0x1d
    bhi lbl_0806c348
    mov r1, r8
    ldr r0, [r1]
    lsls r2, r5, #2
    adds r2, r2, r0
    ldr r0, [r2]
    ldm r7!, {r1}
    orrs r0, r1
    str r0, [r2]
    adds r6, #1
    adds r3, #2
    cmp r6, #0x1f
    ble lbl_0806c322
lbl_0806c348:
    ldr r2, [sp]
    cmp r2, #0
    beq lbl_0806c372
    mov r3, ip
    ldrb r0, [r3, #3]
    mov r7, sl
    adds r5, r7, r0
    ldr r0, lbl_0806c394 @ =0x08754bc0
    ldr r0, [r0]
    lsls r2, r5, #2
    adds r2, r2, r0
    ldr r1, lbl_0806c38c @ =0x08760218
    ldrb r0, [r3, #2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2]
    ldr r0, [r0]
    orrs r1, r0
    str r1, [r2]
    movs r0, #0
    strb r0, [r3]
lbl_0806c372:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c384: .4byte 0x0840d684
lbl_0806c388: .4byte 0x02034800
lbl_0806c38c: .4byte 0x08760218
lbl_0806c390: .4byte 0xfffffebf
lbl_0806c394: .4byte 0x08754bc0
lbl_0806c398: .4byte 0x000003ff

    thumb_func_start check_for_unexplored_minimap_tile
check_for_unexplored_minimap_tile: @ 0x0806c39c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806c3cc @ =gUpdateMinimapFlag
    ldrb r1, [r0]
    adds r6, r0, #0
    cmp r1, #0
    bne lbl_0806c45c
    ldr r1, lbl_0806c3d0 @ =gSamusData
    ldrh r3, [r1, #0x12]
    adds r0, r3, #0
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldrh r0, [r1, #0x14]
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r4
    cmp r0, #0
    beq lbl_0806c3d4
    movs r4, #0
    b lbl_0806c3ec
    .align 2, 0
lbl_0806c3cc: .4byte gUpdateMinimapFlag
lbl_0806c3d0: .4byte gSamusData
lbl_0806c3d4:
    ldr r0, lbl_0806c3fc @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0x1c]
    lsls r0, r0, #0x16
    movs r2, #0xff
    lsls r2, r2, #0x18
    adds r0, r0, r2
    lsrs r2, r0, #0x10
    cmp r3, r2
    blo lbl_0806c3ec
    subs r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
lbl_0806c3ec:
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r5
    cmp r0, #0
    beq lbl_0806c400
    movs r5, #0
    b lbl_0806c41a
    .align 2, 0
lbl_0806c3fc: .4byte gBgPointersAndDimensions
lbl_0806c400:
    ldr r0, lbl_0806c464 @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0x1e]
    lsls r0, r0, #0x16
    movs r2, #0xff
    lsls r2, r2, #0x18
    adds r0, r0, r2
    lsrs r2, r0, #0x10
    ldrh r0, [r1, #0x14]
    cmp r0, r2
    blo lbl_0806c41a
    subs r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
lbl_0806c41a:
    lsrs r4, r4, #6
    lsrs r5, r5, #6
    adds r0, r4, #0
    movs r1, #0xf
    bl __udivsi3
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r5, #0
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r2, lbl_0806c468 @ =gMinimapX
    ldrb r1, [r2]
    ldr r3, lbl_0806c46c @ =gCurrentRoomEntry
    ldrb r0, [r3, #0xe]
    adds r0, r4, r0
    cmp r1, r0
    beq lbl_0806c44a
    strb r0, [r2]
    movs r0, #3
    strb r0, [r6]
lbl_0806c44a:
    ldr r2, lbl_0806c470 @ =gMinimapY
    ldrb r1, [r2]
    ldrb r0, [r3, #0xf]
    adds r0, r5, r0
    cmp r1, r0
    beq lbl_0806c45c
    strb r0, [r2]
    movs r0, #3
    strb r0, [r6]
lbl_0806c45c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c464: .4byte gBgPointersAndDimensions
lbl_0806c468: .4byte gMinimapX
lbl_0806c46c: .4byte gCurrentRoomEntry
lbl_0806c470: .4byte gMinimapY

    thumb_func_start MinimapCheckOnTransition
MinimapCheckOnTransition: @ 0x0806c474
    push {r4, r5, lr}
    ldr r5, lbl_0806c4f4 @ =gAreaBeforeTransition
    ldr r4, lbl_0806c4f8 @ =gCurrentArea
    ldrb r0, [r5]
    ldrb r1, [r4]
    cmp r0, r1
    beq lbl_0806c4bc
    movs r0, #0
    bl sub_0806c1c4
    ldrb r0, [r4]
    strb r0, [r5]
    ldrb r0, [r5]
    ldr r4, lbl_0806c4fc @ =0x02034800
    adds r1, r4, #0
    bl PauseScreenGetMinimapData
    ldr r1, lbl_0806c500 @ =0x040000d4
    str r4, [r1]
    ldr r4, lbl_0806c504 @ =0x02034000
    str r4, [r1, #4]
    ldr r0, lbl_0806c508 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #1
    bl sub_0806c1c4
    ldrb r0, [r5]
    adds r1, r4, #0
    bl MinimapSetDownloadedTiles
    ldr r0, lbl_0806c50c @ =gMinimapX
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, lbl_0806c510 @ =gMinimapY
    strb r1, [r0]
lbl_0806c4bc:
    ldr r4, lbl_0806c514 @ =gUpdateMinimapFlag
    movs r0, #0
    strb r0, [r4]
    bl check_for_unexplored_minimap_tile
    ldrb r0, [r4]
    cmp r0, #3
    bne lbl_0806c4d4
    bl set_minimap_tile_explored
    bl update_minimap_for_explored_tiles
lbl_0806c4d4:
    movs r0, #1
    strb r0, [r4]
    bl MinimapDraw
    movs r0, #2
    strb r0, [r4]
    bl MinimapDraw
    movs r0, #3
    strb r0, [r4]
    bl MinimapDraw
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c4f4: .4byte gAreaBeforeTransition
lbl_0806c4f8: .4byte gCurrentArea
lbl_0806c4fc: .4byte 0x02034800
lbl_0806c500: .4byte 0x040000d4
lbl_0806c504: .4byte 0x02034000
lbl_0806c508: .4byte 0x80000400
lbl_0806c50c: .4byte gMinimapX
lbl_0806c510: .4byte gMinimapY
lbl_0806c514: .4byte gUpdateMinimapFlag

    thumb_func_start update_minimap_for_explored_tiles
update_minimap_for_explored_tiles: @ 0x0806c518
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0806c558 @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806c59c
    ldr r2, lbl_0806c55c @ =gMinimapX
    ldr r3, lbl_0806c560 @ =gMinimapY
    ldrb r0, [r3]
    lsls r0, r0, #5
    ldrb r1, [r2]
    adds r0, r0, r1
    lsls r5, r0, #1
    ldr r0, lbl_0806c564 @ =0x02034000
    adds r4, r5, r0
    ldrh r1, [r4]
    movs r6, #0xf0
    lsls r6, r6, #8
    adds r0, r6, #0
    ands r0, r1
    adds r7, r2, #0
    cmp r0, #0
    bne lbl_0806c59c
    ldr r1, lbl_0806c568 @ =0x02034800
    adds r2, r5, r1
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806c56c
    strh r1, [r4]
    b lbl_0806c576
    .align 2, 0
lbl_0806c558: .4byte gShipLandingFlag
lbl_0806c55c: .4byte gMinimapX
lbl_0806c560: .4byte gMinimapY
lbl_0806c564: .4byte 0x02034000
lbl_0806c568: .4byte 0x02034800
lbl_0806c56c:
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    strh r0, [r4]
lbl_0806c576:
    ldrh r1, [r2]
    ldr r0, lbl_0806c5a4 @ =0x000003ff
    ands r0, r1
    ldr r1, lbl_0806c5a8 @ =0xfffffebf
    adds r0, r0, r1
    cmp r0, #3
    bhi lbl_0806c59c
    ldr r1, lbl_0806c5ac @ =gLastAreaNameVisited
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0806c5b0 @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r1, #1]
    ldrb r0, [r7]
    adds r0, #1
    strb r0, [r1, #2]
    ldrb r0, [r3]
    adds r0, #1
    strb r0, [r1, #3]
lbl_0806c59c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c5a4: .4byte 0x000003ff
lbl_0806c5a8: .4byte 0xfffffebf
lbl_0806c5ac: .4byte gLastAreaNameVisited
lbl_0806c5b0: .4byte gCurrentArea

    thumb_func_start MinimapDraw
MinimapDraw: @ 0x0806c5b4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r3, lbl_0806c5e4 @ =gUpdateMinimapFlag
    ldrb r0, [r3]
    cmp r0, #0
    beq lbl_0806c690
    ldr r0, lbl_0806c5e8 @ =0x02034000
    mov r8, r0
    ldrb r2, [r3]
    subs r1, r2, #1
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_0806c5ec @ =0x02037e20
    adds r6, r0, r1
    cmp r2, #3
    bne lbl_0806c5f0
    movs r7, #1
    mov sb, r7
    b lbl_0806c60a
    .align 2, 0
lbl_0806c5e4: .4byte gUpdateMinimapFlag
lbl_0806c5e8: .4byte 0x02034000
lbl_0806c5ec: .4byte 0x02037e20
lbl_0806c5f0:
    cmp r2, #2
    bne lbl_0806c5fa
    movs r0, #0
    mov sb, r0
    b lbl_0806c60a
lbl_0806c5fa:
    cmp r2, #1
    beq lbl_0806c604
    movs r0, #0
    strb r0, [r3]
    b lbl_0806c690
lbl_0806c604:
    movs r1, #1
    rsbs r1, r1, #0
    mov sb, r1
lbl_0806c60a:
    movs r5, #1
    rsbs r5, r5, #0
    mov r4, sp
lbl_0806c610:
    ldr r0, lbl_0806c6a0 @ =gMinimapX
    ldrb r0, [r0]
    adds r1, r0, r5
    cmp r1, #0x1f
    bls lbl_0806c61e
    movs r1, #1
    rsbs r1, r1, #0
lbl_0806c61e:
    ldr r0, lbl_0806c6a4 @ =gMinimapY
    ldrb r0, [r0]
    add r0, sb
    cmp r0, #0x1f
    bls lbl_0806c62c
    movs r0, #1
    rsbs r0, r0, #0
lbl_0806c62c:
    cmp r0, #0
    blt lbl_0806c634
    cmp r1, #0
    bge lbl_0806c638
lbl_0806c634:
    movs r1, #0x1f
    movs r0, #0x1f
lbl_0806c638:
    lsls r0, r0, #5
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, r8
    movs r7, #0xc0
    lsls r7, r7, #4
    adds r2, r7, #0
    ldrh r1, [r0]
    adds r0, r1, #0
    ands r0, r2
    lsrs r3, r0, #0xa
    lsrs r2, r1, #0xc
    ldr r7, lbl_0806c6a8 @ =0x000003ff
    adds r0, r7, #0
    ands r1, r0
    strh r1, [r4]
    ldr r0, lbl_0806c6ac @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0806c672
    movs r0, #0xa0
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_0806c672
    adds r0, r1, #0
    adds r0, #0x20
    strh r0, [r4]
lbl_0806c672:
    ldrh r0, [r4]
    lsls r0, r0, #5
    strh r0, [r4]
    ldr r1, lbl_0806c6b0 @ =0x08760298
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r3, [r0]
    adds r0, r6, #0
    mov r1, sp
    bl _call_via_r3
    adds r5, #1
    adds r6, #0x20
    cmp r5, #1
    ble lbl_0806c610
lbl_0806c690:
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c6a0: .4byte gMinimapX
lbl_0806c6a4: .4byte gMinimapY
lbl_0806c6a8: .4byte 0x000003ff
lbl_0806c6ac: .4byte gLanguage
lbl_0806c6b0: .4byte 0x08760298

    thumb_func_start MinimapCopyTileGfx
MinimapCopyTileGfx: @ 0x0806c6b4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldr r0, lbl_0806c780 @ =0x0840e0c4
    mov r8, r0
    ldr r1, lbl_0806c784 @ =0x0840d74c
    mov ip, r1
    lsrs r4, r2, #0x14
    ldr r7, lbl_0806c788 @ =0x0840d6fc
    movs r6, #0xf
    movs r0, #7
    mov sb, r0
lbl_0806c6d6:
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r3, [r0]
    orrs r3, r1
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #8
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x10
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x18
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    mov r0, sl
    adds r0, #4
    mov sl, r0
    subs r0, #4
    stm r0!, {r3}
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    mov r0, sb
    cmp r0, #0
    bge lbl_0806c6d6
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c780: .4byte 0x0840e0c4
lbl_0806c784: .4byte 0x0840d74c
lbl_0806c788: .4byte 0x0840d6fc

    thumb_func_start MinimapCopyTileXFlippedGfx
MinimapCopyTileXFlippedGfx: @ 0x0806c78c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    str r0, [sp]
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldr r0, lbl_0806c86c @ =0x0840e0c4
    mov sb, r0
    ldr r1, lbl_0806c870 @ =0x0840d74c
    mov r8, r1
    movs r3, #0xf
    mov ip, r3
    lsrs r6, r2, #0x14
    ldr r7, lbl_0806c874 @ =0x0840d6fc
    movs r0, #7
    mov sl, r0
lbl_0806c7b2:
    ldrh r0, [r5]
    adds r0, #3
    strh r0, [r5]
    ldrh r2, [r5]
    mov r1, sb
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r3, ip
    ands r0, r3
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r0, [r0]
    ldrb r4, [r1]
    orrs r4, r0
    subs r2, #1
    strh r2, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #8
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x10
    orrs r4, r0
    subs r0, r3, #1
    strh r0, [r5]
    ldrh r0, [r5]
    add r0, sb
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x18
    orrs r4, r0
    ldr r0, [sp]
    stm r0!, {r4}
    str r0, [sp]
    adds r3, #3
    strh r3, [r5]
    movs r1, #1
    rsbs r1, r1, #0
    add sl, r1
    mov r2, sl
    cmp r2, #0
    bge lbl_0806c7b2
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c86c: .4byte 0x0840e0c4
lbl_0806c870: .4byte 0x0840d74c
lbl_0806c874: .4byte 0x0840d6fc

    thumb_func_start MinimapCopyTileYFlippedGfx
MinimapCopyTileYFlippedGfx: @ 0x0806c878
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    ldrh r0, [r4]
    adds r0, #0x1c
    strh r0, [r4]
    ldr r0, lbl_0806c948 @ =0x0840e0c4
    mov r8, r0
    ldr r1, lbl_0806c94c @ =0x0840d74c
    mov ip, r1
    lsrs r5, r2, #0x14
    ldr r7, lbl_0806c950 @ =0x0840d6fc
    movs r6, #0xf
    movs r0, #7
    mov sb, r0
lbl_0806c8a0:
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r3, [r0]
    orrs r3, r1
    adds r2, #1
    strh r2, [r4]
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #8
    orrs r3, r0
    adds r2, #1
    strh r2, [r4]
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x10
    orrs r3, r0
    adds r0, r2, #1
    strh r0, [r4]
    ldrh r0, [r4]
    add r0, r8
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x18
    orrs r3, r0
    mov r0, sl
    adds r0, #4
    mov sl, r0
    subs r0, #4
    stm r0!, {r3}
    subs r2, #6
    strh r2, [r4]
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    mov r0, sb
    cmp r0, #0
    bge lbl_0806c8a0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c948: .4byte 0x0840e0c4
lbl_0806c94c: .4byte 0x0840d74c
lbl_0806c950: .4byte 0x0840d6fc

    thumb_func_start MinimapCopyTileXYFlippedGfx
MinimapCopyTileXYFlippedGfx: @ 0x0806c954
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    str r0, [sp]
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldrh r0, [r5]
    adds r0, #0x1f
    strh r0, [r5]
    ldr r0, lbl_0806ca38 @ =0x0840e0c4
    mov sb, r0
    ldr r1, lbl_0806ca3c @ =0x0840d74c
    mov r8, r1
    movs r3, #0xf
    mov ip, r3
    lsrs r6, r2, #0x14
    ldr r7, lbl_0806ca40 @ =0x0840d6fc
    movs r0, #7
    mov sl, r0
lbl_0806c980:
    ldrh r2, [r5]
    mov r1, sb
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r3, ip
    ands r0, r3
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r0, [r0]
    ldrb r4, [r1]
    orrs r4, r0
    subs r2, #1
    strh r2, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #8
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x10
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x18
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldr r3, [sp]
    stm r3!, {r4}
    str r3, [sp]
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    mov r1, sl
    cmp r1, #0
    bge lbl_0806c980
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806ca38: .4byte 0x0840e0c4
lbl_0806ca3c: .4byte 0x0840d74c
lbl_0806ca40: .4byte 0x0840d6fc

    thumb_func_start set_tiles_with_obtained_items
set_tiles_with_obtained_items: @ 0x0806ca44
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    mov ip, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_0806ca9e
    lsls r0, r0, #7
    ldr r1, lbl_0806caa8 @ =0x02033800
    adds r2, r0, r1
    movs r3, #0
    ldr r0, lbl_0806caac @ =0x08760218
    mov r8, r0
lbl_0806ca60:
    ldm r2!, {r0}
    adds r6, r3, #1
    adds r7, r2, #0
    cmp r0, #0
    beq lbl_0806ca96
    adds r4, r0, #0
    movs r5, #0
    lsls r0, r3, #6
    mov r1, ip
    adds r3, r0, r1
    mov r1, r8
lbl_0806ca76:
    ldr r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ca88
    eors r4, r2
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
lbl_0806ca88:
    adds r3, #2
    adds r1, #4
    adds r5, #1
    cmp r5, #0x1f
    bgt lbl_0806ca96
    cmp r4, #0
    bne lbl_0806ca76
lbl_0806ca96:
    adds r3, r6, #0
    adds r2, r7, #0
    cmp r3, #0x1f
    ble lbl_0806ca60
lbl_0806ca9e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806caa8: .4byte 0x02033800
lbl_0806caac: .4byte 0x08760218

    thumb_func_start MinimapSetDownloadedTiles
MinimapSetDownloadedTiles: @ 0x0806cab0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r2, r1, #0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r0, lbl_0806cb24 @ =0x08754bc0
    lsls r1, r4, #7
    ldr r0, [r0]
    adds r3, r0, r1
    ldr r0, lbl_0806cb28 @ =gEquipment
    ldrb r0, [r0, #0x10]
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cae4
    adds r0, r4, #0
    subs r0, #8
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_0806cb68
lbl_0806cae4:
    movs r1, #0
    movs r0, #0xf0
    lsls r0, r0, #8
    mov sl, r0
    ldr r5, lbl_0806cb2c @ =0x00002fff
    mov r8, r5
    movs r0, #0xc0
    lsls r0, r0, #6
    mov sb, r0
    ldr r5, lbl_0806cb30 @ =0x00000fff
    mov ip, r5
lbl_0806cafa:
    ldm r3!, {r0}
    adds r6, r1, #1
    adds r7, r3, #0
    str r0, [sp]
    ldr r3, lbl_0806cb34 @ =0x08760218
    movs r4, #0x1f
lbl_0806cb06:
    ldr r0, [r3]
    ldr r1, [sp]
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cb38
    ldrh r1, [r2]
    mov r0, sl
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cb54
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    b lbl_0806cb52
    .align 2, 0
lbl_0806cb24: .4byte 0x08754bc0
lbl_0806cb28: .4byte gEquipment
lbl_0806cb2c: .4byte 0x00002fff
lbl_0806cb30: .4byte 0x00000fff
lbl_0806cb34: .4byte 0x08760218
lbl_0806cb38:
    ldrh r1, [r2]
    cmp r1, r8
    bls lbl_0806cb46
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r1, #0
    b lbl_0806cb52
lbl_0806cb46:
    mov r0, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cb54
    mov r0, ip
    ands r0, r1
lbl_0806cb52:
    strh r0, [r2]
lbl_0806cb54:
    adds r3, #4
    subs r4, #1
    adds r2, #2
    cmp r4, #0
    bge lbl_0806cb06
    adds r1, r6, #0
    adds r3, r7, #0
    cmp r1, #0x1f
    ble lbl_0806cafa
    b lbl_0806cbc8
lbl_0806cb68:
    movs r1, #0
    ldr r5, lbl_0806cba0 @ =0x08760218
    mov r8, r5
    movs r0, #0xf0
    lsls r0, r0, #8
    mov ip, r0
lbl_0806cb74:
    ldm r3!, {r0}
    adds r6, r1, #1
    adds r7, r3, #0
    mov sb, r0
    mov r3, r8
    movs r4, #0x1f
lbl_0806cb80:
    ldr r0, [r3]
    mov r1, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cba4
    ldrh r1, [r2]
    mov r0, ip
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cbb6
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    b lbl_0806cbb4
    .align 2, 0
lbl_0806cba0: .4byte 0x08760218
lbl_0806cba4:
    ldrh r1, [r2]
    mov r0, ip
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cbb6
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r1, #0
lbl_0806cbb4:
    strh r0, [r2]
lbl_0806cbb6:
    adds r3, #4
    subs r4, #1
    adds r2, #2
    cmp r4, #0
    bge lbl_0806cb80
    adds r1, r6, #0
    adds r3, r7, #0
    cmp r1, #0x1f
    ble lbl_0806cb74
lbl_0806cbc8:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start MinimapUpdateForCollectedItem
MinimapUpdateForCollectedItem: @ 0x0806cbd8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    ldr r7, lbl_0806cc4c @ =gCurrentArea
    ldrb r0, [r7]
    cmp r0, #7
    bhi lbl_0806cc44
    subs r0, r2, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldr r5, lbl_0806cc50 @ =gCurrentRoomEntry
    ldrb r0, [r5, #0xe]
    adds r4, r4, r0
    subs r0, r6, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r1, [r5, #0xf]
    adds r0, r0, r1
    ldrb r1, [r7]
    lsls r1, r1, #7
    ldr r2, lbl_0806cc54 @ =0x02033800
    adds r1, r1, r2
    lsls r3, r0, #2
    adds r3, r3, r1
    ldr r2, lbl_0806cc58 @ =0x08760218
    lsls r1, r4, #2
    adds r1, r1, r2
    ldr r2, [r3]
    ldr r1, [r1]
    orrs r2, r1
    str r2, [r3]
    lsls r0, r0, #5
    adds r4, r4, r0
    lsls r4, r4, #1
    ldr r0, lbl_0806cc5c @ =0x02034000
    adds r1, r4, r0
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r2, lbl_0806cc60 @ =0x02034800
    adds r4, r4, r2
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    ldr r1, lbl_0806cc64 @ =gUpdateMinimapFlag
    movs r0, #3
    strb r0, [r1]
    bl MinimapDraw
lbl_0806cc44:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cc4c: .4byte gCurrentArea
lbl_0806cc50: .4byte gCurrentRoomEntry
lbl_0806cc54: .4byte 0x02033800
lbl_0806cc58: .4byte 0x08760218
lbl_0806cc5c: .4byte 0x02034000
lbl_0806cc60: .4byte 0x02034800
lbl_0806cc64: .4byte gUpdateMinimapFlag

    thumb_func_start MinimapCheckIsTileExplored
MinimapCheckIsTileExplored: @ 0x0806cc68
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    ldr r1, lbl_0806ccb4 @ =gCurrentArea
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0806ccc4
    adds r5, r0, #0
    lsls r5, r5, #5
    subs r0, r2, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldr r6, lbl_0806ccb8 @ =gCurrentRoomEntry
    ldrb r0, [r6, #0xe]
    adds r4, r4, r0
    subs r0, r7, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r1, [r6, #0xf]
    adds r0, r0, r1
    adds r0, r0, r5
    ldr r1, lbl_0806ccbc @ =0x08754bc0
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, lbl_0806ccc0 @ =0x08760218
    lsls r4, r4, #2
    adds r4, r4, r1
    ldr r0, [r0]
    ldr r1, [r4]
    ands r0, r1
    b lbl_0806ccc6
    .align 2, 0
lbl_0806ccb4: .4byte gCurrentArea
lbl_0806ccb8: .4byte gCurrentRoomEntry
lbl_0806ccbc: .4byte 0x08754bc0
lbl_0806ccc0: .4byte 0x08760218
lbl_0806ccc4:
    movs r0, #1
lbl_0806ccc6:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start load_minimap_tiles_with_obtained_items
load_minimap_tiles_with_obtained_items: @ 0x0806cccc
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r2, lbl_0806cd74 @ =0x02033800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r2, #0
lbl_0806ccea:
    lsls r0, r2, #8
    ldr r1, lbl_0806cd78 @ =0x02036c00
    adds r5, r0, r1
    lsls r0, r2, #7
    ldr r1, lbl_0806cd74 @ =0x02033800
    adds r1, r1, r0
    mov r8, r1
    movs r6, #0
    ldrb r0, [r5]
    adds r1, r2, #1
    mov sb, r1
    cmp r0, #0xff
    beq lbl_0806cd5a
    ldr r1, lbl_0806cd7c @ =0x0875fac4
    lsls r0, r2, #2
    adds r0, r0, r1
    ldr r7, [r0]
lbl_0806cd0c:
    ldrb r0, [r5, #2]
    subs r0, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldrb r0, [r5, #3]
    subs r0, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r2, [r5]
    lsls r1, r2, #4
    subs r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r7
    adds r2, r1, #0
    adds r2, #0x35
    ldrb r2, [r2]
    adds r4, r4, r2
    adds r1, #0x36
    ldrb r1, [r1]
    adds r0, r0, r1
    lsls r0, r0, #2
    add r0, r8
    ldr r1, lbl_0806cd80 @ =0x08760218
    lsls r4, r4, #2
    adds r4, r4, r1
    ldr r1, [r0]
    ldr r2, [r4]
    orrs r1, r2
    str r1, [r0]
    adds r6, #1
    adds r5, #4
    cmp r6, #0x3f
    bgt lbl_0806cd5a
    ldrb r0, [r5]
    cmp r0, #0xff
    bne lbl_0806cd0c
lbl_0806cd5a:
    mov r1, sb
    lsls r0, r1, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #7
    bls lbl_0806ccea
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cd74: .4byte 0x02033800
lbl_0806cd78: .4byte 0x02036c00
lbl_0806cd7c: .4byte 0x0875fac4
lbl_0806cd80: .4byte 0x08760218

    thumb_func_start MinimapUpdateChunk
MinimapUpdateChunk: @ 0x0806cd84
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r4, #0
    ldr r0, lbl_0806ce14 @ =0x0840d200
    adds r1, r0, #0
    ldrb r0, [r1]
    cmp r2, r0
    beq lbl_0806cda6
    adds r0, r1, #0
lbl_0806cd98:
    adds r0, #5
    adds r4, #1
    cmp r4, #6
    bhi lbl_0806cda6
    ldrb r3, [r0]
    cmp r2, r3
    bne lbl_0806cd98
lbl_0806cda6:
    cmp r4, #6
    ble lbl_0806cdac
    b lbl_0806ceec
lbl_0806cdac:
    ldr r0, lbl_0806ce18 @ =gCurrentArea
    ldrb r3, [r0]
    cmp r4, r3
    beq lbl_0806cdb6
    b lbl_0806ceec
lbl_0806cdb6:
    lsls r2, r4, #2
    adds r2, r2, r4
    adds r0, r1, #3
    adds r0, r2, r0
    ldrb r0, [r0]
    adds r1, #2
    adds r2, r2, r1
    lsls r0, r0, #5
    ldrb r2, [r2]
    adds r4, r0, r2
    lsls r0, r4, #1
    ldr r1, lbl_0806ce1c @ =0x02034800
    adds r5, r0, r1
    ldr r1, lbl_0806ce20 @ =0x02034000
    adds r6, r0, r1
    adds r0, r3, #0
    cmp r0, #5
    bne lbl_0806ce2c
    ldrh r0, [r5]
    ldr r1, lbl_0806ce24 @ =0x000003ff
    ldr r2, lbl_0806ce28 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2, #4]
    cmp r1, r2
    beq lbl_0806cdea
    b lbl_0806ceec
lbl_0806cdea:
    movs r7, #0xf0
    lsls r7, r7, #8
    adds r1, r6, #0
    adds r3, r5, #0
    movs r4, #2
lbl_0806cdf4:
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    ldrh r2, [r1]
    adds r0, r7, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ce08
    adds r0, r2, #1
    strh r0, [r1]
lbl_0806ce08:
    adds r1, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806cdf4
    b lbl_0806cee2
    .align 2, 0
lbl_0806ce14: .4byte 0x0840d200
lbl_0806ce18: .4byte gCurrentArea
lbl_0806ce1c: .4byte 0x02034800
lbl_0806ce20: .4byte 0x02034000
lbl_0806ce24: .4byte 0x000003ff
lbl_0806ce28: .4byte 0x0840d224
lbl_0806ce2c:
    cmp r0, #1
    bne lbl_0806ce84
    ldrh r0, [r5]
    ldr r1, lbl_0806ce7c @ =0x000003ff
    ldr r2, lbl_0806ce80 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2]
    cmp r1, r2
    bne lbl_0806ceec
    adds r3, r6, #0
    adds r2, r5, #0
    movs r4, #1
lbl_0806ce44:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce44
    adds r3, r6, #0
    adds r3, #0x40
    adds r2, r5, #0
    adds r2, #0x40
    movs r4, #1
lbl_0806ce64:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce64
    b lbl_0806cee2
    .align 2, 0
lbl_0806ce7c: .4byte 0x000003ff
lbl_0806ce80: .4byte 0x0840d224
lbl_0806ce84:
    cmp r0, #3
    bne lbl_0806cede
    ldrh r0, [r5]
    ldr r1, lbl_0806ced4 @ =0x000003ff
    ldr r2, lbl_0806ced8 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2, #2]
    cmp r1, r2
    bne lbl_0806cedc
    adds r3, r6, #0
    adds r2, r5, #0
    movs r4, #1
lbl_0806ce9c:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce9c
    adds r3, r6, #0
    adds r3, #0x40
    adds r2, r5, #0
    adds r2, #0x40
    movs r4, #1
lbl_0806cebc:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806cebc
    b lbl_0806cee2
    .align 2, 0
lbl_0806ced4: .4byte 0x000003ff
lbl_0806ced8: .4byte 0x0840d224
lbl_0806cedc:
    movs r4, #1
lbl_0806cede:
    cmp r4, #0
    bne lbl_0806ceec
lbl_0806cee2:
    ldr r1, lbl_0806cef4 @ =gUpdateMinimapFlag
    movs r0, #3
    strb r0, [r1]
    bl MinimapDraw
lbl_0806ceec:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cef4: .4byte gUpdateMinimapFlag

