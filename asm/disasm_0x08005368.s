    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start samus_check_screw_speedboost_affecting_environment
samus_check_screw_speedboost_affecting_environment: @ 0x08005368
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r2, r0, #0
    mov sl, r1
    movs r6, #0
    ldrb r0, [r2]
    cmp r0, #0xf
    beq lbl_0800538e
    cmp r0, #0xb
    bne lbl_08005390
    ldr r0, lbl_08005418 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08005390
lbl_0800538e:
    movs r6, #2
lbl_08005390:
    ldrb r0, [r2, #5]
    cmp r0, #0
    beq lbl_0800539c
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
lbl_0800539c:
    cmp r6, #0
    beq lbl_08005464
    mov r0, sl
    adds r0, #0x50
    ldrh r1, [r2, #0x12]
    ldrh r0, [r0]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    mov r0, sl
    adds r0, #0x52
    ldrh r0, [r0]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r8, r1
    mov r0, sl
    adds r0, #0x54
    ldrh r1, [r0]
    ldrh r3, [r2, #0x14]
    adds r0, r1, r3
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldrh r5, [r2, #0x14]
    movs r7, #0
    lsls r1, r1, #0x10
    ldr r0, lbl_0800541c @ =0xffc00000
    cmp r1, r0
    bge lbl_080053da
    movs r7, #1
lbl_080053da:
    mov r0, sb
    adds r1, r4, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
    mov r0, r8
    adds r1, r4, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
    mov r0, sl
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_08005420
    cmp r7, #0
    beq lbl_0800540c
    adds r1, r4, #0
    adds r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r0, r8
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
lbl_0800540c:
    mov r0, r8
    adds r1, r5, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
    b lbl_0800543e
    .align 2, 0
lbl_08005418: .4byte gEquipment
lbl_0800541c: .4byte 0xffc00000
lbl_08005420:
    cmp r7, #0
    beq lbl_08005434
    adds r1, r4, #0
    adds r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r0, sb
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
lbl_08005434:
    mov r0, sb
    adds r1, r5, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
lbl_0800543e:
    mov r0, sl
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08005450
    adds r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r6, #4
lbl_08005450:
    mov r0, sb
    adds r1, r5, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
    mov r0, r8
    adds r1, r5, #0
    adds r2, r6, #0
    bl BlockSamusApplyScrewSpeedboosterDamageToEnvironment
lbl_08005464:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08005474
sub_08005474: @ 0x08005474
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    mov sb, r2
    mov r8, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    adds r0, r6, #0
    adds r1, r5, #0
    bl ClipdataProcessForSamus
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    rsbs r1, r1, #0
    lsrs r7, r1, #0x1f
    movs r1, #0xff
    ands r1, r0
    subs r0, r1, #2
    cmp r0, #0xa
    bls lbl_080054a6
    b lbl_080055da
lbl_080054a6:
    lsls r0, r0, #2
    ldr r1, lbl_080054b0 @ =lbl_080054b4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080054b0: .4byte lbl_080054b4
lbl_080054b4: @ jump table
    .4byte lbl_08005564 @ case 0
    .4byte lbl_080054e0 @ case 1
    .4byte lbl_080055b0 @ case 2
    .4byte lbl_08005584 @ case 3
    .4byte lbl_0800550c @ case 4
    .4byte lbl_08005534 @ case 5
    .4byte lbl_080055da @ case 6
    .4byte lbl_080055da @ case 7
    .4byte lbl_080055da @ case 8
    .4byte lbl_080055da @ case 9
   .4byte lbl_080055d8 @ case 10
lbl_080054e0:
    ldr r3, lbl_08005508 @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r5, #0
    ands r0, r2
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r5, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    movs r1, #0x11
    b lbl_080055e6
    .align 2, 0
lbl_08005508: .4byte 0x0000ffc0
lbl_0800550c:
    ldr r3, lbl_08005530 @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r5, #0
    ands r0, r2
    lsrs r0, r0, #1
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r5, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    subs r0, #0x7e
    b lbl_08005556
    .align 2, 0
lbl_08005530: .4byte 0x0000ffc0
lbl_08005534:
    ldr r3, lbl_08005560 @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r5, #0
    ands r0, r2
    lsrs r0, r0, #1
    subs r0, #0x1f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r5, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    subs r0, #0x3e
lbl_08005556:
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    movs r1, #0x12
    b lbl_080055e6
    .align 2, 0
lbl_08005560: .4byte 0x0000ffc0
lbl_08005564:
    ldr r2, lbl_08005580 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r2
    movs r1, #0x3f
    adds r0, r5, #0
    ands r0, r1
    orrs r4, r0
    adds r3, r5, #0
    ands r3, r2
    adds r0, r6, #0
    ands r0, r1
    orrs r3, r0
    movs r1, #0x21
    b lbl_080055e6
    .align 2, 0
lbl_08005580: .4byte 0x0000ffc0
lbl_08005584:
    ldr r3, lbl_080055a8 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r3
    movs r2, #0x3f
    adds r0, r5, #0
    ands r0, r2
    lsrs r0, r0, #1
    adds r0, #0x1f
    orrs r4, r0
    adds r1, r5, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    ldr r2, lbl_080055ac @ =0x0000ffc1
    adds r0, r0, r2
    b lbl_080055ca
    .align 2, 0
lbl_080055a8: .4byte 0x0000ffc0
lbl_080055ac: .4byte 0x0000ffc1
lbl_080055b0:
    ldr r3, lbl_080055d4 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r3
    movs r2, #0x3f
    adds r0, r5, #0
    ands r0, r2
    lsrs r0, r0, #1
    orrs r4, r0
    adds r1, r5, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
lbl_080055ca:
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    movs r1, #0x22
    b lbl_080055e6
    .align 2, 0
lbl_080055d4: .4byte 0x0000ffc0
lbl_080055d8:
    movs r7, #0x10
lbl_080055da:
    ldr r0, lbl_08005600 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r0
    adds r3, r5, #0
    ands r3, r0
    movs r1, #0
lbl_080055e6:
    mov r0, r8
    strh r4, [r0]
    mov r2, sb
    strh r3, [r2]
    ldr r0, [sp, #0x1c]
    strh r1, [r0]
    adds r0, r7, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08005600: .4byte 0x0000ffc0

    thumb_func_start sub_08005604
sub_08005604: @ 0x08005604
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x10
    lsrs r7, r2, #0x10
    movs r6, #0
    adds r0, r4, #0
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08005630
    ldrh r1, [r5, #0x12]
    ldr r0, lbl_0800562c @ =0x0000ffc0
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x50
    ldrh r1, [r1]
    subs r0, r0, r1
    strh r0, [r3]
    b lbl_08005642
    .align 2, 0
lbl_0800562c: .4byte 0x0000ffc0
lbl_08005630:
    ldrh r0, [r5, #0x12]
    ldr r1, lbl_080056b4 @ =0x0000ffc0
    ands r1, r0
    adds r0, r4, #0
    adds r0, #0x52
    ldrh r0, [r0]
    subs r1, r1, r0
    adds r1, #0x3f
    strh r1, [r3]
lbl_08005642:
    adds r4, #0x54
    ldrh r0, [r4]
    ldrh r5, [r5, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r5, #0
    adds r1, r7, #0
    bl ClipdataProcessForSamus
    adds r2, r0, #0
    movs r0, #0xff
    ands r0, r2
    cmp r0, #7
    bgt lbl_08005664
    cmp r0, #2
    bge lbl_08005674
lbl_08005664:
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r2
    cmp r0, #0
    beq lbl_08005674
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_08005674:
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r0, #0x40
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_080056ac
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r7, #0
    bl ClipdataProcessForSamus
    adds r2, r0, #0
    movs r0, #0xff
    ands r0, r2
    cmp r0, #7
    bgt lbl_0800569c
    cmp r0, #2
    bge lbl_080056ac
lbl_0800569c:
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r2
    cmp r0, #0
    beq lbl_080056ac
    adds r0, r6, #2
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_080056ac:
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080056b4: .4byte 0x0000ffc0

    thumb_func_start sub_080056b8
sub_080056b8: @ 0x080056b8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    adds r6, r1, #0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov r8, r2
    movs r5, #0
    adds r0, r6, #0
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_080056ec
    ldrh r1, [r4, #0x12]
    ldr r0, lbl_080056e8 @ =0x0000ffc0
    ands r0, r1
    adds r1, r6, #0
    adds r1, #0x50
    ldrh r1, [r1]
    subs r0, r0, r1
    strh r0, [r3]
    b lbl_080056fe
    .align 2, 0
lbl_080056e8: .4byte 0x0000ffc0
lbl_080056ec:
    ldrh r0, [r4, #0x12]
    ldr r1, lbl_08005724 @ =0x0000ffc0
    ands r1, r0
    adds r0, r6, #0
    adds r0, #0x52
    ldrh r0, [r0]
    subs r1, r1, r0
    adds r1, #0x3f
    strh r1, [r3]
lbl_080056fe:
    ldrh r7, [r4, #0x14]
    adds r0, r7, #0
    mov r1, r8
    bl ClipdataProcessForSamus
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    beq lbl_0800572e
    movs r0, #0xff
    ands r0, r1
    cmp r0, #7
    bgt lbl_08005728
    cmp r0, #2
    blt lbl_08005728
    movs r5, #0x80
    b lbl_0800572e
    .align 2, 0
lbl_08005724: .4byte 0x0000ffc0
lbl_08005728:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_0800572e:
    cmp r5, #1
    bne lbl_0800574a
    ldrh r0, [r4, #0x14]
    ldrh r1, [r4, #0x12]
    bl ClipdataProcessForSamus
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #7
    bgt lbl_0800574a
    cmp r1, #2
    blt lbl_0800574a
    movs r5, #0x81
lbl_0800574a:
    adds r0, r6, #0
    adds r0, #0x54
    movs r2, #0
    ldrsh r1, [r0, r2]
    movs r0, #0x40
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_08005786
    adds r0, r7, #0
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r1, r8
    bl ClipdataProcessForSamus
    adds r1, r0, #0
    movs r0, #0xff
    ands r0, r1
    cmp r0, #7
    bgt lbl_08005776
    cmp r0, #2
    bge lbl_08005786
lbl_08005776:
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    beq lbl_08005786
    adds r0, r5, #2
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08005786:
    adds r0, r5, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08005794
sub_08005794: @ 0x08005794
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r5, #0
    ldrh r0, [r4, #0x14]
    bl ClipdataProcessForSamus
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    beq lbl_080057c6
    movs r0, #0xff
    ands r0, r1
    cmp r0, #7
    bgt lbl_080057c0
    cmp r0, #2
    blt lbl_080057c0
    movs r5, #0x80
    b lbl_080057c6
lbl_080057c0:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_080057c6:
    cmp r5, #1
    bne lbl_080057e2
    ldrh r0, [r4, #0x14]
    ldrh r1, [r4, #0x12]
    bl ClipdataProcessForSamus
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #7
    bgt lbl_080057e2
    cmp r1, #2
    blt lbl_080057e2
    movs r5, #0x81
lbl_080057e2:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080057ec
sub_080057ec: @ 0x080057ec
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r0, #0
    lsls r1, r1, #0x10
    ldr r0, lbl_08005898 @ =gSamusPhysics
    mov sl, r0
    asrs r1, r1, #0x10
    ldrh r0, [r6, #0x14]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    mov sb, r5
    mov r0, sl
    adds r0, #0x50
    ldrh r1, [r0]
    ldrh r0, [r6, #0x12]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcessForSamus
    movs r7, #0x80
    lsls r7, r7, #0x11
    ands r0, r7
    rsbs r0, r0, #0
    lsrs r4, r0, #0x1f
    ldr r0, lbl_0800589c @ =0x0823a566
    mov r8, r0
    ldrh r1, [r0]
    ldrh r0, [r6, #0x12]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcessForSamus
    ands r0, r7
    cmp r0, #0
    beq lbl_08005846
    adds r0, r4, #2
    adds r4, r0, #0
lbl_08005846:
    mov r0, r8
    ldrh r1, [r0, #2]
    ldrh r0, [r6, #0x12]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcessForSamus
    ands r0, r7
    cmp r0, #0
    beq lbl_08005864
    adds r0, r4, #4
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_08005864:
    mov r0, sl
    adds r0, #0x52
    ldrh r1, [r0]
    ldrh r6, [r6, #0x12]
    adds r1, r1, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r0, sb
    bl ClipdataProcessForSamus
    ands r0, r7
    cmp r0, #0
    beq lbl_08005886
    adds r0, r4, #0
    adds r0, #8
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_08005886:
    adds r0, r4, #0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08005898: .4byte gSamusPhysics
lbl_0800589c: .4byte 0x0823a566

    thumb_func_start sub_080058a0
sub_080058a0: @ 0x080058a0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    adds r6, r0, #0
    adds r7, r1, #0
    adds r0, r7, #0
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_080058ce
    movs r5, #0x20
    adds r1, #0x50
    ldrh r4, [r1]
    adds r0, r7, #0
    adds r0, #0x52
    ldrh r2, [r0]
    mov r8, r2
    mov sl, r1
    mov sb, r0
    b lbl_080058e2
lbl_080058ce:
    movs r5, #0x10
    adds r1, r7, #0
    adds r1, #0x52
    ldrh r4, [r1]
    adds r0, r7, #0
    adds r0, #0x50
    ldrh r2, [r0]
    mov r8, r2
    mov sl, r0
    mov sb, r1
lbl_080058e2:
    ldrh r2, [r6, #0x12]
    adds r2, r4, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r0, r6, #0
    adds r1, r7, #0
    add r3, sp, #4
    bl sub_08005604
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    beq lbl_0800590c
    add r0, sp, #4
    ldrh r0, [r0]
    strh r0, [r6, #0x12]
    adds r1, r7, #0
    adds r1, #0x58
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0800590c:
    ldr r0, lbl_080059a0 @ =gSamusDataCopy
    strb r2, [r0, #0xa]
    ldrh r0, [r6, #0x1a]
    cmp r0, #0
    bne lbl_080059b0
    ldrh r1, [r6, #0x12]
    adds r1, r4, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r6, #0
    bl sub_08005794
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x80
    beq lbl_080059cc
    cmp r2, #0x81
    beq lbl_080059f8
    cmp r2, #0
    beq lbl_08005944
    add r0, sp, #4
    ldrh r0, [r0]
    strh r0, [r6, #0x12]
    adds r1, r7, #0
    adds r1, #0x58
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08005944:
    ldrb r0, [r6, #1]
    cmp r0, #1
    bne lbl_0800594c
    b lbl_08005ac2
lbl_0800594c:
    ldrh r0, [r6, #0x12]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r5, sp
    adds r5, #6
    add r4, sp, #8
    str r4, [sp]
    add r2, sp, #4
    adds r3, r5, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080059aa
    ldrh r0, [r6, #0x12]
    add r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r4, [sp]
    add r2, sp, #4
    adds r3, r5, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldrh r1, [r4]
    cmp r1, #0
    bne lbl_080059a4
    cmp r2, #0
    bne lbl_080059aa
    movs r0, #0xfe
    b lbl_08005ac4
    .align 2, 0
lbl_080059a0: .4byte gSamusDataCopy
lbl_080059a4:
    ldrh r0, [r5]
    strh r0, [r6, #0x14]
    strh r1, [r6, #0x1a]
lbl_080059aa:
    movs r0, #0
    strb r0, [r6, #1]
    b lbl_08005ac2
lbl_080059b0:
    ands r5, r0
    cmp r5, #0
    beq lbl_08005a32
    ldrh r1, [r6, #0x12]
    adds r1, r4, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r6, #0
    bl sub_08005794
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x80
    bne lbl_080059f4
lbl_080059cc:
    ldrh r0, [r6, #0x12]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    mov r4, sp
    adds r4, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_08005474
    ldrh r0, [r4]
    movs r1, #0
    strh r0, [r6, #0x14]
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    strb r1, [r6, #1]
    b lbl_08005ac2
lbl_080059f4:
    cmp r2, #0
    beq lbl_08005ac2
lbl_080059f8:
    ldrh r0, [r6, #0x12]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    subs r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r4, sp
    adds r4, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_08005474
    ldrh r4, [r4]
    strh r4, [r6, #0x14]
    ldrh r0, [r5]
    cmp r0, #0
    bne lbl_08005a28
    adds r0, r4, #0
    adds r0, #0x3f
    strh r0, [r6, #0x14]
lbl_08005a28:
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    movs r0, #0
    strb r0, [r6, #1]
    b lbl_08005ac2
lbl_08005a32:
    ldrh r0, [r6, #0x12]
    add r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    mov r4, sp
    adds r4, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_08005a5a
    ldrh r0, [r4]
    b lbl_08005ac0
lbl_08005a5a:
    cmp r2, #0
    bne lbl_08005ac2
    ldrh r0, [r6, #0x12]
    add r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    adds r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r5, [sp]
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_08005a8a
    ldrh r0, [r4]
    b lbl_08005ac0
lbl_08005a8a:
    cmp r2, #0
    beq lbl_08005ac2
    adds r0, r7, #0
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08005aac
    ldrh r0, [r6, #0x12]
    ldr r1, lbl_08005aa8 @ =0x0000ffc0
    ands r1, r0
    mov r2, sl
    ldrh r0, [r2]
    subs r1, r1, r0
    b lbl_08005aba
    .align 2, 0
lbl_08005aa8: .4byte 0x0000ffc0
lbl_08005aac:
    ldrh r0, [r6, #0x12]
    ldr r1, lbl_08005ad4 @ =0x0000ffc0
    ands r1, r0
    mov r2, sb
    ldrh r0, [r2]
    subs r1, r1, r0
    adds r1, #0x3f
lbl_08005aba:
    strh r1, [r6, #0x12]
    ldrh r0, [r4]
    subs r0, #1
lbl_08005ac0:
    strh r0, [r6, #0x14]
lbl_08005ac2:
    movs r0, #0xff
lbl_08005ac4:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08005ad4: .4byte 0x0000ffc0

    thumb_func_start sub_08005ad8
sub_08005ad8: @ 0x08005ad8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    adds r4, r0, #0
    mov r8, r1
    ldrh r0, [r4, #0x12]
    ldr r6, lbl_08005b50 @ =0x0000ffc0
    ldr r7, lbl_08005b54 @ =gPreviousXPosition
    ldrh r2, [r7]
    adds r1, r6, #0
    ands r1, r0
    adds r0, r6, #0
    ands r0, r2
    cmp r1, r0
    bne lbl_08005b7e
    ldrh r0, [r4, #0x1a]
    cmp r0, #0
    bne lbl_08005b7e
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_08005b7e
    ldrh r0, [r4, #0x12]
    ldrh r1, [r4, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r3, sp
    adds r3, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    bl sub_08005474
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08005b7e
    ldrh r0, [r5]
    cmp r0, #0
    bne lbl_08005b7e
    mov r0, r8
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_08005b58
    ldrh r2, [r4, #0x12]
    movs r3, #0x3f
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0x1d
    bls lbl_08005b7e
    ldrh r1, [r7]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0x1e
    bhi lbl_08005b7e
    adds r0, r6, #0
    ands r0, r2
    adds r0, #0x1e
    b lbl_08005b78
    .align 2, 0
lbl_08005b50: .4byte 0x0000ffc0
lbl_08005b54: .4byte gPreviousXPosition
lbl_08005b58:
    cmp r0, #1
    bne lbl_08005b7e
    ldrh r2, [r4, #0x12]
    movs r3, #0x3f
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0x21
    bhi lbl_08005b7e
    ldrh r1, [r7]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0x20
    bls lbl_08005b7e
    adds r0, r6, #0
    ands r0, r2
    adds r0, #0x21
lbl_08005b78:
    strh r0, [r4, #0x12]
    movs r0, #0xfe
    b lbl_08005b80
lbl_08005b7e:
    movs r0, #0xff
lbl_08005b80:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_08005b8c
sub_08005b8c: @ 0x08005b8c
    push {r4, r5, r6, r7, lr}
    sub sp, #0xc
    adds r4, r0, #0
    adds r5, r1, #0
    adds r0, r5, #0
    adds r0, #0x54
    movs r2, #0
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    beq lbl_08005bae
    cmp r0, #3
    bne lbl_08005bc4
lbl_08005bae:
    ldrh r1, [r4, #0x12]
    ldr r0, lbl_08005bc0 @ =0x0000ffc0
    ands r0, r1
    adds r1, r5, #0
    adds r1, #0x50
    ldrh r1, [r1]
    subs r0, r0, r1
    strh r0, [r4, #0x12]
    b lbl_08005bde
    .align 2, 0
lbl_08005bc0: .4byte 0x0000ffc0
lbl_08005bc4:
    cmp r0, #8
    beq lbl_08005bcc
    cmp r0, #0xc
    bne lbl_08005bde
lbl_08005bcc:
    ldrh r0, [r4, #0x12]
    ldr r1, lbl_08005c3c @ =0x0000ffc0
    ands r1, r0
    adds r0, r5, #0
    adds r0, #0x52
    ldrh r0, [r0]
    subs r1, r1, r0
    adds r1, #0x3f
    strh r1, [r4, #0x12]
lbl_08005bde:
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_08005c40
    adds r0, r5, #0
    adds r0, #0x50
    ldrh r0, [r0]
    ldrh r1, [r4, #0x12]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r7, sp
    adds r7, #6
    add r6, sp, #8
    str r6, [sp]
    add r2, sp, #4
    adds r3, r7, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08005c40
    adds r0, r5, #0
    adds r0, #0x52
    ldrh r0, [r0]
    ldrh r2, [r4, #0x12]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r6, [sp]
    add r2, sp, #4
    adds r3, r7, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08005c40
    movs r0, #0xfe
    b lbl_08005c42
    .align 2, 0
lbl_08005c3c: .4byte 0x0000ffc0
lbl_08005c40:
    movs r0, #0xff
lbl_08005c42:
    add sp, #0xc
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusCheckLandingCollision
SamusCheckLandingCollision: @ 0x08005c4c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x24
    adds r6, r0, #0
    mov sb, r1
    mov r0, sb
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08005c6e
    mov r0, sb
    adds r0, #0x50
    ldrh r1, [r0]
    b lbl_08005c76
lbl_08005c6e:
    mov r0, sb
    adds r0, #0x52
    ldrh r1, [r0]
    subs r0, #2
lbl_08005c76:
    str r0, [sp, #0x20]
    ldrh r2, [r6, #0x12]
    adds r2, r1, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r0, r6, #0
    mov r1, sb
    add r3, sp, #4
    bl sub_08005604
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08005ca0
    add r0, sp, #4
    ldrh r0, [r0]
    strh r0, [r6, #0x12]
    mov r1, sb
    adds r1, #0x58
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08005ca0:
    ldrb r0, [r6, #1]
    cmp r0, #1
    bne lbl_08005ca8
    b lbl_08005e06
lbl_08005ca8:
    ldrh r0, [r6, #0x14]
    ldr r1, lbl_08005d2c @ =0x0000ffc0
    ands r1, r0
    str r1, [sp, #0x14]
    ldr r0, lbl_08005d30 @ =gPreviousYPosition
    ldrh r0, [r0]
    ldr r2, lbl_08005d2c @ =0x0000ffc0
    mov sl, r2
    mov r1, sl
    ands r1, r0
    mov sl, r1
    ldr r2, [sp, #0x20]
    str r2, [sp, #0x18]
    ldrh r0, [r2]
    ldrh r1, [r6, #0x12]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    movs r2, #6
    add r2, sp
    mov r8, r2
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    mov r3, r8
    bl sub_08005474
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x10]
    mov r0, sb
    adds r0, #0x52
    str r0, [sp, #0x1c]
    ldrh r0, [r0]
    ldrh r1, [r6, #0x12]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    mov r2, sp
    adds r2, #0xa
    add r4, sp, #0xc
    mov r7, sp
    adds r7, #0xe
    str r7, [sp]
    adds r3, r4, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, [sp, #0x14]
    cmp r2, sl
    bls lbl_08005db2
    ldr r1, [sp, #0x10]
    cmp r1, #0
    beq lbl_08005d72
    ldrh r1, [r5]
    cmp r1, #0
    beq lbl_08005d3c
    cmp r0, #0
    beq lbl_08005d34
    ldrh r0, [r4]
    subs r0, #1
    b lbl_08005de6
    .align 2, 0
lbl_08005d2c: .4byte 0x0000ffc0
lbl_08005d30: .4byte gPreviousYPosition
lbl_08005d34:
    strh r1, [r6, #0x1a]
    mov r2, r8
    ldrh r0, [r2]
    b lbl_08005de6
lbl_08005d3c:
    ldr r1, [sp, #0x18]
    ldrh r0, [r1]
    ldrh r2, [r6, #0x12]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    subs r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r5, [sp]
    add r2, sp, #4
    mov r3, r8
    bl sub_08005474
    mov r0, r8
    ldrh r3, [r0]
    strh r3, [r6, #0x14]
    ldrh r0, [r5]
    cmp r0, #0
    bne lbl_08005d6c
    adds r0, r3, #0
    adds r0, #0x3f
    strh r0, [r6, #0x14]
lbl_08005d6c:
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    b lbl_08005de8
lbl_08005d72:
    cmp r0, #0
    beq lbl_08005e06
    ldrh r0, [r7]
    cmp r0, #0
    bne lbl_08005de2
    ldr r1, [sp, #0x1c]
    ldrh r0, [r1]
    ldrh r2, [r6, #0x12]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    subs r1, #0x40
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r5, [sp]
    add r2, sp, #4
    mov r3, r8
    bl sub_08005474
    mov r0, r8
    ldrh r3, [r0]
    strh r3, [r6, #0x14]
    ldrh r0, [r5]
    cmp r0, #0
    bne lbl_08005dac
    adds r0, r3, #0
    adds r0, #0x3f
    strh r0, [r6, #0x14]
lbl_08005dac:
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    b lbl_08005de8
lbl_08005db2:
    ldr r1, [sp, #0x10]
    cmp r1, #0
    beq lbl_08005dd8
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_08005dc6
    strh r0, [r6, #0x1a]
    mov r2, r8
    ldrh r0, [r2]
    b lbl_08005de6
lbl_08005dc6:
    ldrh r1, [r6, #0x12]
    ldr r0, lbl_08005dd4 @ =0x0000ffc0
    ands r0, r1
    ldr r2, [sp, #0x20]
    ldrh r1, [r2]
    subs r0, r0, r1
    b lbl_08005dfa
    .align 2, 0
lbl_08005dd4: .4byte 0x0000ffc0
lbl_08005dd8:
    cmp r0, #0
    beq lbl_08005e06
    ldrh r0, [r7]
    cmp r0, #0
    beq lbl_08005dec
lbl_08005de2:
    strh r0, [r6, #0x1a]
    ldrh r0, [r4]
lbl_08005de6:
    strh r0, [r6, #0x14]
lbl_08005de8:
    movs r0, #0xfd
    b lbl_08005e08
lbl_08005dec:
    ldrh r1, [r6, #0x12]
    ldr r0, lbl_08005e18 @ =0x0000ffc0
    ands r0, r1
    ldr r2, [sp, #0x1c]
    ldrh r1, [r2]
    subs r0, r0, r1
    adds r0, #0x3f
lbl_08005dfa:
    strh r0, [r6, #0x12]
    mov r1, sb
    adds r1, #0x58
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08005e06:
    movs r0, #0xff
lbl_08005e08:
    add sp, #0x24
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08005e18: .4byte 0x0000ffc0

    thumb_func_start SamusCheckTopCollision
SamusCheckTopCollision: @ 0x08005e1c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    adds r6, r0, #0
    adds r4, r1, #0
    adds r0, r4, #0
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08005e3a
    adds r0, r4, #0
    adds r0, #0x50
    ldrh r5, [r0]
    b lbl_08005e44
lbl_08005e3a:
    adds r0, r4, #0
    adds r0, #0x52
    ldrh r5, [r0]
    movs r0, #0x50
    adds r0, r0, r4
lbl_08005e44:
    mov r8, r0
    ldrh r2, [r6, #0x12]
    adds r2, r5, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r0, r6, #0
    adds r1, r4, #0
    add r3, sp, #4
    bl sub_080056b8
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0
    beq lbl_08005e9c
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08005e76
    add r0, sp, #4
    ldrh r0, [r0]
    strh r0, [r6, #0x12]
lbl_08005e76:
    ldrh r0, [r6, #0x12]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x14]
    mov r4, sp
    adds r4, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_08005474
    ldrh r0, [r4]
    strh r0, [r6, #0x14]
    ldrh r0, [r5]
    strh r0, [r6, #0x1a]
    movs r0, #0xfd
    b lbl_08005f26
lbl_08005e9c:
    cmp r1, #0
    beq lbl_08005eb0
    add r0, sp, #4
    ldrh r0, [r0]
    strh r0, [r6, #0x12]
    adds r1, r4, #0
    adds r1, #0x58
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08005eb0:
    adds r5, r4, #0
    adds r5, #0x54
    movs r2, #0
    ldrsh r1, [r5, r2]
    adds r0, r6, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bne lbl_08005ed8
    ldrh r1, [r6, #0x12]
    ldr r0, lbl_08005ed4 @ =0x0000ffc0
    ands r0, r1
    mov r2, r8
    ldrh r1, [r2]
    subs r0, r0, r1
    b lbl_08005eec
    .align 2, 0
lbl_08005ed4: .4byte 0x0000ffc0
lbl_08005ed8:
    cmp r1, #8
    bne lbl_08005efc
    ldrh r1, [r6, #0x12]
    ldr r0, lbl_08005ef4 @ =0x0000ffc0
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x52
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r0, #0x3f
lbl_08005eec:
    strh r0, [r6, #0x12]
    ldr r1, lbl_08005ef8 @ =gPreviousXPosition
    strh r0, [r1]
    b lbl_08005f24
    .align 2, 0
lbl_08005ef4: .4byte 0x0000ffc0
lbl_08005ef8: .4byte gPreviousXPosition
lbl_08005efc:
    movs r0, #6
    ands r1, r0
    cmp r1, #0
    beq lbl_08005f24
    ldrh r2, [r5]
    ldrh r1, [r6, #0x14]
    adds r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r1, lbl_08005f34 @ =0x0000ffc0
    ands r0, r1
    subs r0, r0, r2
    adds r0, #0x40
    strh r0, [r6, #0x14]
    strh r7, [r6, #0x18]
    adds r1, r4, #0
    adds r1, #0x59
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08005f24:
    movs r0, #0xff
lbl_08005f26:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08005f34: .4byte 0x0000ffc0

    thumb_func_start SamusCheckCollisions
SamusCheckCollisions: @ 0x08005f38
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r5, r0, #0
    mov sb, r1
    mov r4, sb
    adds r4, #0x56
    ldrb r0, [r4]
    cmp r0, #3
    bls lbl_08005f54
    b lbl_08006204
lbl_08005f54:
    adds r0, r5, #0
    bl samus_check_screw_speedboost_affecting_environment
    movs r0, #0xff
    mov sl, r0
    mov r0, sb
    adds r0, #0x4f
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08005f72
    adds r0, r5, #0
    mov r1, sb
    bl SamusCheckTopCollision
    b lbl_08005fc6
lbl_08005f72:
    cmp r0, #2
    bne lbl_08005f80
    adds r0, r5, #0
    mov r1, sb
    bl SamusCheckLandingCollision
    b lbl_08005fc6
lbl_08005f80:
    mov r0, sb
    adds r0, #0x4e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08005fb8
    ldrb r0, [r4]
    cmp r0, #2
    bne lbl_08005f9a
    adds r0, r5, #0
    mov r1, sb
    bl SamusCheckLandingCollision
    b lbl_08005fc6
lbl_08005f9a:
    adds r0, r5, #0
    mov r1, sb
    bl sub_080058a0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sl, r0
    cmp r0, #0xff
    beq lbl_08005fae
    b lbl_080060dc
lbl_08005fae:
    adds r0, r5, #0
    mov r1, sb
    bl sub_08005ad8
    b lbl_08005fc6
lbl_08005fb8:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_08005fcc
    adds r0, r5, #0
    mov r1, sb
    bl sub_08005b8c
lbl_08005fc6:
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sl, r0
lbl_08005fcc:
    mov r1, sl
    cmp r1, #0xff
    beq lbl_08005fd4
    b lbl_080060dc
lbl_08005fd4:
    ldr r2, lbl_080060b8 @ =gEquipment
    ldrb r1, [r2, #0xf]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080060dc
    ldr r0, lbl_080060bc @ =gButtonInput
    ldrh r0, [r0]
    ldrh r1, [r5, #0xe]
    ands r0, r1
    cmp r0, #0
    beq lbl_080060dc
    movs r2, #0x18
    ldrsh r0, [r5, r2]
    cmp r0, #0
    bgt lbl_080060dc
    movs r0, #0x10
    ands r0, r1
    movs r1, #0x1f
    rsbs r1, r1, #0
    str r1, [sp]
    cmp r0, #0
    beq lbl_08006006
    movs r2, #0x1f
    str r2, [sp]
lbl_08006006:
    ldrh r0, [r5, #0x14]
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl ClipdataProcessForSamus
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_080060dc
    ldrh r0, [r5, #0x14]
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl ClipdataProcessForSamus
    adds r7, r0, #0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r7, r4
    ldrh r0, [r5, #0x14]
    subs r0, #0x68
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    ldr r2, [sp]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcessForSamus
    mov r8, r0
    ands r0, r4
    mov r8, r0
    ldrh r0, [r5, #0x14]
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    ldr r2, [sp]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcessForSamus
    adds r6, r0, #0
    ands r6, r4
    ldrb r0, [r5]
    cmp r0, #8
    beq lbl_08006078
    cmp r0, #8
    blt lbl_080060dc
    cmp r0, #0xf
    bgt lbl_080060dc
    cmp r0, #0xb
    blt lbl_080060dc
lbl_08006078:
    ldrh r0, [r5, #0x14]
    subs r0, #0x60
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    ldr r2, [sp]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataCheckCurrentAffectingAtPosition
    asrs r0, r0, #0x10
    cmp r7, #0
    bne lbl_080060dc
    mov r1, r8
    cmp r1, #0
    beq lbl_080060dc
    cmp r0, #6
    beq lbl_080060dc
    cmp r6, #0
    bne lbl_080060dc
    ldr r2, lbl_080060b8 @ =gEquipment
    ldrb r0, [r2, #0x12]
    cmp r0, #2
    bne lbl_080060c0
    movs r0, #0x3d
    mov sl, r0
    movs r0, #0x9b
    bl SoundPlay
    b lbl_080060dc
    .align 2, 0
lbl_080060b8: .4byte gEquipment
lbl_080060bc: .4byte gButtonInput
lbl_080060c0:
    movs r1, #0x15
    mov sl, r1
    mov r0, sb
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080060d6
    movs r0, #0x95
    bl SoundPlay
    b lbl_080060dc
lbl_080060d6:
    movs r0, #0x7a
    bl SoundPlay
lbl_080060dc:
    mov r0, sb
    adds r0, #0x58
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080060e8
    b lbl_080061e2
lbl_080060e8:
    movs r0, #0
    strh r0, [r5, #0x16]
    ldrb r0, [r5]
    cmp r0, #0x2b
    bhi lbl_080061e2
    lsls r0, r0, #2
    ldr r1, lbl_080060fc @ =lbl_08006100
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080060fc: .4byte lbl_08006100
lbl_08006100: @ jump table
    .4byte lbl_080061b0 @ case 0
    .4byte lbl_080061e2 @ case 1
    .4byte lbl_080061e2 @ case 2
    .4byte lbl_080061e2 @ case 3
    .4byte lbl_080061e2 @ case 4
    .4byte lbl_080061e2 @ case 5
    .4byte lbl_080061e2 @ case 6
    .4byte lbl_080061e2 @ case 7
    .4byte lbl_080061e2 @ case 8
    .4byte lbl_080061e2 @ case 9
    .4byte lbl_080061e2 @ case 10
    .4byte lbl_080061e2 @ case 11
    .4byte lbl_080061d0 @ case 12
    .4byte lbl_080061e2 @ case 13
    .4byte lbl_080061e2 @ case 14
    .4byte lbl_080061d0 @ case 15
    .4byte lbl_080061e2 @ case 16
    .4byte lbl_080061e2 @ case 17
    .4byte lbl_080061e2 @ case 18
    .4byte lbl_080061e2 @ case 19
    .4byte lbl_080061e2 @ case 20
    .4byte lbl_080061e2 @ case 21
    .4byte lbl_080061e2 @ case 22
    .4byte lbl_080061e2 @ case 23
    .4byte lbl_080061e2 @ case 24
    .4byte lbl_080061e2 @ case 25
    .4byte lbl_080061e2 @ case 26
    .4byte lbl_080061e2 @ case 27
    .4byte lbl_080061e2 @ case 28
    .4byte lbl_080061e2 @ case 29
    .4byte lbl_080061e2 @ case 30
    .4byte lbl_080061e2 @ case 31
    .4byte lbl_080061e2 @ case 32
    .4byte lbl_080061e2 @ case 33
    .4byte lbl_080061e2 @ case 34
    .4byte lbl_080061e2 @ case 35
    .4byte lbl_080061e2 @ case 36
    .4byte lbl_080061e2 @ case 37
    .4byte lbl_080061e2 @ case 38
    .4byte lbl_080061e2 @ case 39
    .4byte lbl_080061de @ case 40
    .4byte lbl_080061de @ case 41
    .4byte lbl_080061de @ case 42
    .4byte lbl_080061de @ case 43
lbl_080061b0:
    ldr r0, lbl_080061c8 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080061e2
    ldr r0, lbl_080061cc @ =gSamusDataCopy
    ldrb r0, [r0, #0xa]
    cmp r0, #1
    bne lbl_080061e2
    movs r2, #0x34
    mov sl, r2
    b lbl_080061e2
    .align 2, 0
lbl_080061c8: .4byte gEquipment
lbl_080061cc: .4byte gSamusDataCopy
lbl_080061d0:
    movs r0, #8
    strb r0, [r5, #7]
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xc]
    b lbl_080061e2
lbl_080061de:
    movs r0, #0xfe
    mov sl, r0
lbl_080061e2:
    mov r0, sb
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #0xff
    beq lbl_08006204
    mov r1, sl
    cmp r1, #0xfe
    bne lbl_080061f8
    ldrh r0, [r5, #0x14]
    adds r0, #1
    strh r0, [r5, #0x14]
lbl_080061f8:
    mov r2, sl
    cmp r2, #0xff
    beq lbl_08006204
    mov r0, sl
    bl SamusSetPose
lbl_08006204:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start samus_apply_environment_effects
samus_apply_environment_effects: @ 0x08006214
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    adds r6, r0, #0
    mov sb, r2
    ldr r0, lbl_08006270 @ =gSamusPhysics
    mov sl, r0
    movs r7, #0
    movs r2, #1
    str r2, [sp, #4]
    cmp r1, #0
    bne lbl_08006278
    movs r3, #0
    str r3, [sp, #8]
    ldr r1, lbl_08006274 @ =gSamusEnvironmentalEffects
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0800625c
lbl_0800623e:
    ldr r0, [sp, #8]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #8]
    cmp r0, #2
    bhi lbl_08006262
    lsls r0, r0, #1
    ldr r2, [sp, #8]
    adds r0, r0, r2
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800623e
lbl_0800625c:
    ldr r3, [sp, #8]
    cmp r3, #2
    bls lbl_0800627e
lbl_08006262:
    ldr r0, [sp, #4]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #4]
    b lbl_0800627e
    .align 2, 0
lbl_08006270: .4byte gSamusPhysics
lbl_08006274: .4byte gSamusEnvironmentalEffects
lbl_08006278:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #8]
lbl_0800627e:
    mov r0, sb
    cmp r0, #7
    bls lbl_08006286
    b lbl_080065b4
lbl_08006286:
    lsls r0, r0, #2
    ldr r1, lbl_08006290 @ =lbl_08006294
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08006290: .4byte lbl_08006294
lbl_08006294: @ jump table
    .4byte lbl_080062b4 @ case 0
    .4byte lbl_080062b4 @ case 1
    .4byte lbl_0800636c @ case 2
    .4byte lbl_08006422 @ case 3
    .4byte lbl_08006422 @ case 4
    .4byte lbl_0800651c @ case 5
    .4byte lbl_0800655e @ case 6
    .4byte lbl_08006590 @ case 7
lbl_080062b4:
    ldrh r1, [r6, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080062c4
    ldrh r0, [r6, #0x12]
    adds r0, #4
    b lbl_080062c8
lbl_080062c4:
    ldrh r0, [r6, #0x12]
    subs r0, #4
lbl_080062c8:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldrh r0, [r6, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r4, #0
    bl ClipdataCheckGroundEffect
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_08006328
    movs r1, #1
    str r1, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov r2, sb
    cmp r2, #0
    bne lbl_0800630c
    ldr r0, lbl_08006300 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08006304
    movs r0, #0xa1
    bl SoundPlay
    b lbl_08006366
    .align 2, 0
lbl_08006300: .4byte gEquipment
lbl_08006304:
    movs r0, #0x68
    bl SoundPlay
    b lbl_08006366
lbl_0800630c:
    ldr r0, lbl_0800631c @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08006320
    movs r0, #0xa2
    bl SoundPlay
    b lbl_08006366
    .align 2, 0
lbl_0800631c: .4byte gEquipment
lbl_08006320:
    movs r0, #0x69
    bl SoundPlay
    b lbl_08006366
lbl_08006328:
    cmp r5, #2
    bne lbl_08006344
    movs r3, #2
    str r3, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov r0, sb
    cmp r0, #0
    beq lbl_08006358
    movs r0, #0x67
    bl SoundPlay
    b lbl_08006366
lbl_08006344:
    cmp r5, #3
    bne lbl_08006366
    movs r1, #3
    str r1, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov r2, sb
    cmp r2, #0
    bne lbl_08006360
lbl_08006358:
    movs r0, #0x66
    bl SoundPlay
    b lbl_08006366
lbl_08006360:
    movs r0, #0x67
    bl SoundPlay
lbl_08006366:
    mov r8, r4
    ldrh r4, [r6, #0x14]
    b lbl_080065b4
lbl_0800636c:
    ldrh r0, [r6, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x12]
    bl ClipdataCheckGroundEffect
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080063a8
    movs r3, #0xc
    str r3, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r0, lbl_0800639c @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080063a0
    movs r0, #0xa3
    bl SoundPlay
    b lbl_0800641a
    .align 2, 0
lbl_0800639c: .4byte gEquipment
lbl_080063a0:
    movs r0, #0x74
    bl SoundPlay
    b lbl_0800641a
lbl_080063a8:
    cmp r5, #5
    bne lbl_080063b8
    movs r0, #0xd
    str r0, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    b lbl_0800641a
lbl_080063b8:
    cmp r5, #2
    bne lbl_080063c2
    movs r1, #0xe
    str r1, [sp]
    b lbl_080063ca
lbl_080063c2:
    cmp r5, #3
    bne lbl_080063d8
    movs r2, #0xf
    str r2, [sp]
lbl_080063ca:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    movs r0, #0x73
    bl SoundPlay
    b lbl_0800641a
lbl_080063d8:
    mov r0, sl
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080063ea
    movs r0, #0x95
    bl SoundPlay
    b lbl_0800641a
lbl_080063ea:
    ldr r0, lbl_080063fc @ =gSamusDataCopy
    ldrh r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_08006400
    movs r0, #0x72
    bl SoundPlay
    b lbl_0800641a
    .align 2, 0
lbl_080063fc: .4byte gSamusDataCopy
lbl_08006400:
    ldr r0, lbl_08006410 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08006414
    movs r0, #0x71
    bl SoundPlay
    b lbl_0800641a
    .align 2, 0
lbl_08006410: .4byte gEquipment
lbl_08006414:
    movs r0, #0x99
    bl SoundPlay
lbl_0800641a:
    ldrh r3, [r6, #0x12]
    mov r8, r3
    ldrh r4, [r6, #0x14]
    b lbl_080065b4
lbl_08006422:
    ldrh r0, [r6, #0x14]
    str r0, [sp, #0xc]
    ldr r0, lbl_08006474 @ =gPreviousYPosition
    ldrh r0, [r0]
    mov sl, r0
    mov r1, sb
    cmp r1, #3
    bne lbl_08006446
    ldr r0, [sp, #0xc]
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0xc]
    mov r0, sl
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
lbl_08006446:
    ldrh r1, [r6, #0x12]
    ldr r0, [sp, #0xc]
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r5, r0, #0
    movs r4, #0xff
    ands r5, r4
    ldrh r1, [r6, #0x12]
    mov r0, sl
    bl ClipdataCheckCurrentAffectingAtPosition
    ands r0, r4
    ldr r2, [sp, #0xc]
    cmp r2, sl
    bhs lbl_0800649e
    cmp r5, #1
    beq lbl_08006478
    cmp r0, #1
    bne lbl_08006478
    movs r3, #4
    str r3, [sp]
    b lbl_080064d4
    .align 2, 0
lbl_08006474: .4byte gPreviousYPosition
lbl_08006478:
    cmp r5, #2
    beq lbl_08006486
    cmp r0, #2
    bne lbl_08006486
    movs r0, #6
    str r0, [sp]
    b lbl_080064d4
lbl_08006486:
    cmp r5, #3
    beq lbl_08006494
    cmp r0, #3
    bne lbl_08006494
    movs r1, #6
    str r1, [sp]
    b lbl_080064d4
lbl_08006494:
    cmp r5, #4
    beq lbl_080064da
    cmp r0, #4
    bne lbl_080064da
    b lbl_080064d0
lbl_0800649e:
    cmp r5, #1
    bne lbl_080064ac
    cmp r0, #1
    beq lbl_080064ac
    movs r3, #4
    str r3, [sp]
    b lbl_080064d4
lbl_080064ac:
    cmp r5, #2
    bne lbl_080064ba
    cmp r0, #2
    beq lbl_080064ba
    movs r0, #6
    str r0, [sp]
    b lbl_080064d4
lbl_080064ba:
    cmp r5, #3
    bne lbl_080064c8
    cmp r0, #3
    beq lbl_080064c8
    movs r1, #6
    str r1, [sp]
    b lbl_080064d4
lbl_080064c8:
    cmp r5, #4
    bne lbl_080064da
    cmp r0, #4
    beq lbl_080064da
lbl_080064d0:
    movs r2, #8
    str r2, [sp]
lbl_080064d4:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_080064da:
    mov r3, sb
    cmp r3, #4
    bne lbl_080064ea
    ldr r0, [sp]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
lbl_080064ea:
    ldrh r0, [r6, #0x12]
    mov r8, r0
    ldr r1, lbl_080064fc @ =gEffectYPosition
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08006500
    adds r4, r0, #0
    b lbl_080065b4
    .align 2, 0
lbl_080064fc: .4byte gEffectYPosition
lbl_08006500:
    ldr r1, [sp, #0xc]
    cmp r1, sl
    bhs lbl_08006510
    ldr r0, lbl_0800650c @ =gPreviousYPosition
    ldrh r0, [r0]
    b lbl_08006512
    .align 2, 0
lbl_0800650c: .4byte gPreviousYPosition
lbl_08006510:
    ldrh r0, [r6, #0x14]
lbl_08006512:
    ldr r4, lbl_08006518 @ =0x0000ffc0
    ands r4, r0
    b lbl_080065b4
    .align 2, 0
lbl_08006518: .4byte 0x0000ffc0
lbl_0800651c:
    ldrb r0, [r6, #1]
    cmp r0, #2
    beq lbl_080065b4
    movs r2, #0x12
    str r2, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldrh r1, [r6, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800653c
    ldrh r0, [r6, #0x12]
    adds r0, #0xc
    b lbl_08006540
lbl_0800653c:
    ldrh r0, [r6, #0x12]
    subs r0, #0xc
lbl_08006540:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    mov r0, sl
    adds r0, #0x70
    ldrh r0, [r0]
    ldrh r6, [r6, #0x14]
    adds r0, r0, r6
    adds r0, #0x10
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0x91
    bl SoundPlay
    b lbl_080065b4
lbl_0800655e:
    ldrh r0, [r6, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x12]
    bl ClipdataCheckGroundEffect
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_08006578
    movs r3, #0x10
    str r3, [sp]
    b lbl_08006582
lbl_08006578:
    subs r0, r5, #2
    cmp r0, #1
    bhi lbl_08006588
    movs r0, #0x11
    str r0, [sp]
lbl_08006582:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08006588:
    ldrh r1, [r6, #0x12]
    mov r8, r1
    ldrh r4, [r6, #0x14]
    b lbl_080065b4
lbl_08006590:
    ldrh r0, [r6, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x12]
    bl ClipdataCheckGroundEffect
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080065b4
    movs r2, #1
    str r2, [sp]
    ldrh r3, [r6, #0x12]
    mov r8, r3
    ldrh r4, [r6, #0x14]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_080065b4:
    ldr r0, [sp, #4]
    ands r7, r0
    cmp r7, #0
    beq lbl_080065da
    ldr r0, lbl_080065ec @ =gSamusEnvironmentalEffects
    ldr r2, [sp, #8]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    movs r0, #0
    mov r3, sp
    ldrb r3, [r3]
    strb r3, [r1]
    strb r0, [r1, #2]
    strb r0, [r1, #1]
    mov r0, r8
    strh r0, [r1, #4]
    strh r4, [r1, #6]
lbl_080065da:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080065ec: .4byte gSamusEnvironmentalEffects

    thumb_func_start samus_update_environment_effects
samus_update_environment_effects: @ 0x080065f0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov r8, r0
    ldrb r0, [r0]
    cmp r0, #0x33
    bne lbl_08006606
    b lbl_08006940
lbl_08006606:
    ldr r4, lbl_0800661c @ =gSamusPhysics
    ldr r6, lbl_08006620 @ =gSamusEnvironmentalEffects
    mov r1, r8
    ldrb r0, [r1]
    cmp r0, #0x32
    bhi lbl_0800670a
    lsls r0, r0, #2
    ldr r1, lbl_08006624 @ =lbl_08006628
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800661c: .4byte gSamusPhysics
lbl_08006620: .4byte gSamusEnvironmentalEffects
lbl_08006624: .4byte lbl_08006628
lbl_08006628: @ jump table
    .4byte lbl_08006700 @ case 0
    .4byte lbl_0800670a @ case 1
    .4byte lbl_0800670a @ case 2
    .4byte lbl_0800670a @ case 3
    .4byte lbl_0800670a @ case 4
    .4byte lbl_0800670a @ case 5
    .4byte lbl_0800670a @ case 6
    .4byte lbl_0800670a @ case 7
    .4byte lbl_080066f4 @ case 8
    .4byte lbl_080066f4 @ case 9
    .4byte lbl_0800670a @ case 10
    .4byte lbl_080066f4 @ case 11
    .4byte lbl_080066f4 @ case 12
    .4byte lbl_0800670a @ case 13
    .4byte lbl_080066f4 @ case 14
    .4byte lbl_080066f4 @ case 15
    .4byte lbl_0800670a @ case 16
    .4byte lbl_0800670a @ case 17
    .4byte lbl_08006700 @ case 18
    .4byte lbl_0800670a @ case 19
    .4byte lbl_080066f4 @ case 20
    .4byte lbl_0800670a @ case 21
    .4byte lbl_0800670a @ case 22
    .4byte lbl_0800670a @ case 23
    .4byte lbl_0800670a @ case 24
    .4byte lbl_0800670a @ case 25
    .4byte lbl_080066f4 @ case 26
    .4byte lbl_080066f4 @ case 27
    .4byte lbl_080066f4 @ case 28
    .4byte lbl_0800670a @ case 29
    .4byte lbl_0800670a @ case 30
    .4byte lbl_0800670a @ case 31
    .4byte lbl_0800670a @ case 32
    .4byte lbl_080066f4 @ case 33
    .4byte lbl_080066f4 @ case 34
    .4byte lbl_0800670a @ case 35
    .4byte lbl_0800670a @ case 36
    .4byte lbl_0800670a @ case 37
    .4byte lbl_0800670a @ case 38
    .4byte lbl_0800670a @ case 39
    .4byte lbl_0800670a @ case 40
    .4byte lbl_0800670a @ case 41
    .4byte lbl_0800670a @ case 42
    .4byte lbl_0800670a @ case 43
    .4byte lbl_0800670a @ case 44
    .4byte lbl_0800670a @ case 45
    .4byte lbl_0800670a @ case 46
    .4byte lbl_080066f4 @ case 47
    .4byte lbl_080066f4 @ case 48
    .4byte lbl_080066f4 @ case 49
    .4byte lbl_080066f4 @ case 50
lbl_080066f4:
    mov r0, r8
    movs r1, #3
    movs r2, #3
    bl samus_apply_environment_effects
    b lbl_0800670a
lbl_08006700:
    mov r0, r8
    movs r1, #0
    movs r2, #4
    bl samus_apply_environment_effects
lbl_0800670a:
    mov r2, r8
    ldrh r0, [r2, #0x14]
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r2, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    movs r1, #0xff
    ands r1, r0
    cmp r1, #1
    bne lbl_0800673a
    ldrb r0, [r6, #3]
    cmp r0, #0xdb
    bhi lbl_0800672c
    adds r0, #1
    b lbl_08006738
lbl_0800672c:
    mov r0, r8
    movs r1, #0
    movs r2, #5
    bl samus_apply_environment_effects
    movs r0, #0
lbl_08006738:
    strb r0, [r6, #3]
lbl_0800673a:
    adds r6, #0x30
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_08006744
    b lbl_08006852
lbl_08006744:
    mov r3, r8
    ldrb r0, [r3]
    cmp r0, #0x1c
    bgt lbl_0800675a
    cmp r0, #0x15
    blt lbl_0800675a
    ldrh r0, [r3, #0x14]
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    b lbl_0800675e
lbl_0800675a:
    mov r0, r8
    ldrh r0, [r0, #0x14]
lbl_0800675e:
    mov sb, r0
    mov r2, r8
    ldrh r1, [r2, #0x12]
    mov r0, sb
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r5, r0, #0
    movs r3, #0xff
    mov sl, r3
    ands r5, r3
    adds r4, #0x70
    ldrh r0, [r4]
    add r0, sb
    subs r0, #8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r2, r8
    ldrh r1, [r2, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r7, r0, #0
    mov r3, sl
    ands r7, r3
    ldrh r2, [r4]
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r0, #0x40
    rsbs r0, r0, #0
    cmp r1, r0
    ble lbl_080067a0
    mov r0, sb
    subs r0, #0x40
    b lbl_080067a4
lbl_080067a0:
    mov r1, sb
    adds r0, r1, r2
lbl_080067a4:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    mov r2, r8
    ldrh r1, [r2, #0x12]
    adds r0, r4, #0
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r2, r0, #0
    movs r0, #0xff
    ands r2, r0
    movs r3, #0
    cmp r5, #2
    bne lbl_080067d8
    cmp r7, #2
    beq lbl_080067d8
    ldr r0, lbl_080067d4 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0800680a
    movs r3, #0xa
    str r3, [sp]
    b lbl_0800680e
    .align 2, 0
lbl_080067d4: .4byte gEquipment
lbl_080067d8:
    cmp r5, #3
    bne lbl_080067f8
    cmp r7, #3
    beq lbl_080067f8
    ldr r0, lbl_080067f4 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_0800680a
    movs r0, #0xa
    str r0, [sp]
    b lbl_08006804
    .align 2, 0
lbl_080067f4: .4byte gEquipment
lbl_080067f8:
    cmp r5, #4
    bne lbl_0800680a
    cmp r7, #4
    beq lbl_0800680a
    movs r1, #0xb
    str r1, [sp]
lbl_08006804:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
lbl_0800680a:
    cmp r3, #0
    beq lbl_08006852
lbl_0800680e:
    movs r0, #0
    mov r3, sp
    ldrb r3, [r3]
    strb r3, [r6]
    strb r0, [r6, #2]
    strb r0, [r6, #1]
    mov r1, r8
    ldrh r0, [r1, #0x12]
    strh r0, [r6, #4]
    ldr r0, lbl_0800682c @ =gEffectYPosition
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_08006830
    strh r0, [r6, #6]
    b lbl_0800684c
    .align 2, 0
lbl_0800682c: .4byte gEffectYPosition
lbl_08006830:
    subs r0, r2, #2
    cmp r0, #2
    bhi lbl_08006844
    ldr r0, lbl_08006840 @ =0x0000ffc0
    ands r4, r0
    strh r4, [r6, #6]
    b lbl_0800684c
    .align 2, 0
lbl_08006840: .4byte 0x0000ffc0
lbl_08006844:
    ldr r0, lbl_080068b4 @ =0x0000ffc0
    mov r2, sb
    ands r2, r0
    strh r2, [r6, #6]
lbl_0800684c:
    movs r0, #0x7d
    bl SoundPlay
lbl_08006852:
    ldr r6, lbl_080068b8 @ =gSamusEnvironmentalEffects
    movs r4, #0
lbl_08006856:
    ldrb r3, [r6]
    str r3, [sp]
    cmp r3, #0
    beq lbl_08006934
    ldrb r1, [r6, #1]
    adds r1, #1
    strb r1, [r6, #1]
    ldr r2, lbl_080068bc @ =0x0823a56c
    adds r0, r3, #0
    subs r0, #1
    lsls r0, r0, #2
    adds r0, r0, r2
    ldr r2, [r0]
    ldrb r0, [r6, #2]
    lsls r0, r0, #3
    adds r2, r2, r0
    movs r3, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r0, [r2, #4]
    cmp r1, r0
    blo lbl_08006898
    strb r3, [r6, #1]
    ldrb r0, [r6, #2]
    adds r0, #1
    strb r0, [r6, #2]
    adds r2, #8
    ldrb r0, [r2, #4]
    cmp r0, #0
    bne lbl_08006896
    strb r3, [r6]
    strb r3, [r6, #2]
lbl_08006896:
    movs r3, #1
lbl_08006898:
    ldr r0, [r2]
    str r0, [r6, #8]
    cmp r3, #0
    beq lbl_08006934
    ldr r0, [sp]
    subs r0, #4
    cmp r0, #0xd
    bhi lbl_08006934
    lsls r0, r0, #2
    ldr r1, lbl_080068c0 @ =lbl_080068c4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080068b4: .4byte 0x0000ffc0
lbl_080068b8: .4byte gSamusEnvironmentalEffects
lbl_080068bc: .4byte 0x0823a56c
lbl_080068c0: .4byte lbl_080068c4
lbl_080068c4: @ jump table
    .4byte lbl_080068fc @ case 0
    .4byte lbl_0800690a @ case 1
    .4byte lbl_080068fc @ case 2
    .4byte lbl_0800690a @ case 3
    .4byte lbl_080068fc @ case 4
    .4byte lbl_0800690a @ case 5
    .4byte lbl_08006918 @ case 6
    .4byte lbl_08006918 @ case 7
    .4byte lbl_08006934 @ case 8
    .4byte lbl_08006934 @ case 9
    .4byte lbl_08006934 @ case 10
    .4byte lbl_08006934 @ case 11
    .4byte lbl_08006920 @ case 12
    .4byte lbl_08006920 @ case 13
lbl_080068fc:
    ldrb r0, [r6, #2]
    cmp r0, #1
    bne lbl_08006934
    movs r0, #0x75
    bl SoundPlay
    b lbl_08006934
lbl_0800690a:
    ldrb r0, [r6, #2]
    cmp r0, #1
    bne lbl_08006934
    movs r0, #0x74
    bl SoundPlay
    b lbl_08006934
lbl_08006918:
    mov r1, r8
    ldrh r0, [r1, #0x12]
    strh r0, [r6, #4]
    b lbl_08006934
lbl_08006920:
    cmp r4, #0
    bne lbl_08006934
    ldrb r0, [r6, #2]
    cmp r0, #3
    bne lbl_08006934
    mov r0, r8
    movs r1, #0
    movs r2, #6
    bl samus_apply_environment_effects
lbl_08006934:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r6, #0xc
    cmp r4, #4
    bls lbl_08006856
lbl_08006940:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start SamusSetMidAir
SamusSetMidAir: @ 0x08006950
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r6, lbl_08006978 @ =gEquipment
    ldrh r0, [r5, #0x16]
    strh r0, [r4, #0x16]
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    ldrb r0, [r5, #5]
    strb r0, [r4, #5]
    ldrb r0, [r5]
    adds r2, r6, #0
    cmp r0, #0x2b
    bls lbl_0800696e
    b lbl_08006b76
lbl_0800696e:
    lsls r0, r0, #2
    ldr r1, lbl_0800697c @ =lbl_08006980
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08006978: .4byte gEquipment
lbl_0800697c: .4byte lbl_08006980
lbl_08006980: @ jump table
    .4byte lbl_08006a30 @ case 0
    .4byte lbl_08006b76 @ case 1
    .4byte lbl_08006b76 @ case 2
    .4byte lbl_08006b76 @ case 3
    .4byte lbl_08006b5e @ case 4
    .4byte lbl_08006b5e @ case 5
    .4byte lbl_08006b5e @ case 6
    .4byte lbl_08006b76 @ case 7
    .4byte lbl_08006b76 @ case 8
    .4byte lbl_08006b76 @ case 9
    .4byte lbl_08006b76 @ case 10
    .4byte lbl_08006a54 @ case 11
    .4byte lbl_08006a54 @ case 12
    .4byte lbl_08006a88 @ case 13
    .4byte lbl_08006a54 @ case 14
    .4byte lbl_08006a54 @ case 15
    .4byte lbl_08006b18 @ case 16
    .4byte lbl_08006b10 @ case 17
    .4byte lbl_08006b10 @ case 18
    .4byte lbl_08006b76 @ case 19
    .4byte lbl_08006ade @ case 20
    .4byte lbl_08006b76 @ case 21
    .4byte lbl_08006b76 @ case 22
    .4byte lbl_08006b76 @ case 23
    .4byte lbl_08006b76 @ case 24
    .4byte lbl_08006b76 @ case 25
    .4byte lbl_08006b76 @ case 26
    .4byte lbl_08006b76 @ case 27
    .4byte lbl_08006b76 @ case 28
    .4byte lbl_08006b76 @ case 29
    .4byte lbl_08006b76 @ case 30
    .4byte lbl_08006b76 @ case 31
    .4byte lbl_08006b76 @ case 32
    .4byte lbl_08006b76 @ case 33
    .4byte lbl_08006b76 @ case 34
    .4byte lbl_08006b76 @ case 35
    .4byte lbl_08006b76 @ case 36
    .4byte lbl_08006b58 @ case 37
    .4byte lbl_08006b76 @ case 38
    .4byte lbl_08006b58 @ case 39
    .4byte lbl_08006b76 @ case 40
    .4byte lbl_08006b76 @ case 41
    .4byte lbl_08006b76 @ case 42
    .4byte lbl_08006b58 @ case 43
lbl_08006a30:
    ldrb r1, [r5, #4]
    cmp r1, #1
    bne lbl_08006a8e
    movs r0, #0xb
    strb r0, [r4]
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_08006a44
    movs r0, #0xd4
    b lbl_08006bc0
lbl_08006a44:
    ldrb r0, [r6, #0xf]
    ands r1, r0
    cmp r1, #0
    beq lbl_08006a50
    movs r0, #0xe8
    b lbl_08006bc0
lbl_08006a50:
    movs r0, #0xc0
    b lbl_08006bc0
lbl_08006a54:
    movs r0, #0
    movs r1, #8
    strb r1, [r4]
    strh r0, [r4, #0x16]
    ldrb r0, [r5, #4]
    cmp r0, #2
    bne lbl_08006a66
    ldrh r0, [r5, #0x18]
    strh r0, [r4, #0x18]
lbl_08006a66:
    ldr r0, lbl_08006a84 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08006a7a
    b lbl_08006bc2
lbl_08006a7a:
    ldrh r0, [r4, #0x14]
    adds r0, #0x20
    strh r0, [r4, #0x14]
    b lbl_08006bc2
    .align 2, 0
lbl_08006a84: .4byte 0x0823a554
lbl_08006a88:
    ldrb r1, [r5, #4]
    cmp r1, #0
    bne lbl_08006a94
lbl_08006a8e:
    movs r0, #8
    strb r0, [r4]
    b lbl_08006bc2
lbl_08006a94:
    movs r0, #0xc
    strb r0, [r4]
    cmp r1, #1
    bne lbl_08006aac
    ldrb r0, [r6, #0xf]
    ands r1, r0
    cmp r1, #0
    beq lbl_08006aa8
    movs r0, #0xe8
    b lbl_08006aaa
lbl_08006aa8:
    movs r0, #0xc0
lbl_08006aaa:
    strh r0, [r4, #0x18]
lbl_08006aac:
    ldr r0, lbl_08006ac4 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006ac8
    movs r0, #0x74
    strh r0, [r4, #0x18]
    movs r0, #0x95
    bl SoundPlay
    b lbl_08006bc2
    .align 2, 0
lbl_08006ac4: .4byte gSamusPhysics
lbl_08006ac8:
    ldrb r0, [r2, #0x12]
    cmp r0, #2
    beq lbl_08006ad6
    movs r0, #0x76
    bl SoundPlay
    b lbl_08006bc2
lbl_08006ad6:
    movs r0, #0x9a
    bl SoundPlay
    b lbl_08006bc2
lbl_08006ade:
    ldrb r0, [r5, #4]
    cmp r0, #0xa
    bne lbl_08006aec
    movs r0, #0x10
    strh r0, [r4, #0xe]
    movs r0, #0x30
    b lbl_08006afe
lbl_08006aec:
    cmp r0, #0xb
    bne lbl_08006af4
    movs r0, #0
    b lbl_08006afe
lbl_08006af4:
    cmp r0, #0xc
    bne lbl_08006bc2
    movs r0, #0x20
    strh r0, [r4, #0xe]
    ldr r0, lbl_08006b0c @ =0x0000ffd0
lbl_08006afe:
    strh r0, [r4, #0x16]
    movs r0, #0xa4
    strh r0, [r4, #0x18]
    movs r0, #1
    strb r0, [r4, #4]
    b lbl_08006bc2
    .align 2, 0
lbl_08006b0c: .4byte 0x0000ffd0
lbl_08006b10:
    ldrb r0, [r5, #0x1d]
    strb r0, [r4, #0x1d]
    ldrb r0, [r5, #0x1c]
    strb r0, [r4, #0x1c]
lbl_08006b18:
    ldrb r1, [r5, #4]
    cmp r1, #0xa
    bne lbl_08006b26
    movs r0, #0x10
    strh r0, [r4, #0xe]
    movs r0, #0x30
    b lbl_08006b38
lbl_08006b26:
    cmp r1, #0xb
    bne lbl_08006b2e
    movs r0, #0
    b lbl_08006b38
lbl_08006b2e:
    cmp r1, #0xc
    bne lbl_08006b48
    movs r0, #0x20
    strh r0, [r4, #0xe]
    ldr r0, lbl_08006b44 @ =0x0000ffd0
lbl_08006b38:
    strh r0, [r4, #0x16]
    movs r0, #0xa4
    strh r0, [r4, #0x18]
    movs r0, #1
    strb r0, [r4, #4]
    b lbl_08006b58
    .align 2, 0
lbl_08006b44: .4byte 0x0000ffd0
lbl_08006b48:
    ldrh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    strh r0, [r4, #0x16]
    cmp r1, #1
    bne lbl_08006b58
    movs r0, #0xd4
    strh r0, [r4, #0x18]
lbl_08006b58:
    movs r0, #0x14
    strb r0, [r4]
    b lbl_08006bc2
lbl_08006b5e:
    ldr r0, lbl_08006b94 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08006b76
    ldrh r0, [r4, #0x14]
    adds r0, #0x20
    strh r0, [r4, #0x14]
lbl_08006b76:
    movs r2, #8
    strb r2, [r4]
    ldrb r0, [r5, #4]
    cmp r0, #1
    bne lbl_08006bba
    ldr r0, lbl_08006b98 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    beq lbl_08006b9c
    movs r0, #0xb
    strb r0, [r4]
    b lbl_08006b9e
    .align 2, 0
lbl_08006b94: .4byte 0x0823a554
lbl_08006b98: .4byte gButtonInput
lbl_08006b9c:
    strb r2, [r4]
lbl_08006b9e:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_08006ba8
    movs r0, #0xd4
    b lbl_08006bc0
lbl_08006ba8:
    ldrb r1, [r6, #0xf]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08006bb6
    movs r0, #0xe8
    b lbl_08006bc0
lbl_08006bb6:
    movs r0, #0xc0
    b lbl_08006bc0
lbl_08006bba:
    cmp r0, #2
    bne lbl_08006bc2
    ldrh r0, [r5, #0x18]
lbl_08006bc0:
    strh r0, [r4, #0x18]
lbl_08006bc2:
    ldrb r0, [r5, #4]
    cmp r0, #1
    bne lbl_08006c26
    ldrb r0, [r4]
    cmp r0, #8
    bne lbl_08006c04
    ldr r0, lbl_08006be8 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08006c12
    movs r1, #0x18
    ldrsh r0, [r4, r1]
    cmp r0, #0xc0
    bne lbl_08006bec
    movs r0, #0x6e
    bl SoundPlay
    b lbl_08006c26
    .align 2, 0
lbl_08006be8: .4byte gSamusPhysics
lbl_08006bec:
    cmp r0, #0xe8
    bne lbl_08006bf8
    movs r0, #0x6f
    bl SoundPlay
    b lbl_08006c26
lbl_08006bf8:
    cmp r0, #0xd4
    bne lbl_08006c26
    movs r0, #0x9d
    bl SoundPlay
    b lbl_08006c26
lbl_08006c04:
    cmp r0, #0x14
    bne lbl_08006c26
    ldr r0, lbl_08006c1c @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006c20
lbl_08006c12:
    movs r0, #0x94
    bl SoundPlay
    b lbl_08006c26
    .align 2, 0
lbl_08006c1c: .4byte gSamusPhysics
lbl_08006c20:
    movs r0, #0x70
    bl SoundPlay
lbl_08006c26:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start SamusSetLandingPose
SamusSetLandingPose: @ 0x08006c2c
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r0, #0
    strh r0, [r5, #0xc]
    ldrb r0, [r5]
    subs r0, #8
    cmp r0, #0x2a
    bls lbl_08006c40
    b lbl_08006e2a
lbl_08006c40:
    lsls r0, r0, #2
    ldr r1, lbl_08006c4c @ =lbl_08006c50
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08006c4c: .4byte lbl_08006c50
lbl_08006c50: @ jump table
    .4byte lbl_08006cfc @ case 0
    .4byte lbl_08006e2a @ case 1
    .4byte lbl_08006e2a @ case 2
    .4byte lbl_08006e2a @ case 3
    .4byte lbl_08006e2a @ case 4
    .4byte lbl_08006e2a @ case 5
    .4byte lbl_08006e2a @ case 6
    .4byte lbl_08006e2a @ case 7
    .4byte lbl_08006e2a @ case 8
    .4byte lbl_08006e2a @ case 9
    .4byte lbl_08006e2a @ case 10
    .4byte lbl_08006e2a @ case 11
    .4byte lbl_08006d34 @ case 12
    .4byte lbl_08006e2a @ case 13
    .4byte lbl_08006e2a @ case 14
    .4byte lbl_08006e2a @ case 15
    .4byte lbl_08006e2a @ case 16
    .4byte lbl_08006e2a @ case 17
    .4byte lbl_08006e2a @ case 18
    .4byte lbl_08006e2a @ case 19
    .4byte lbl_08006e2a @ case 20
    .4byte lbl_08006e2a @ case 21
    .4byte lbl_08006e2a @ case 22
    .4byte lbl_08006e2a @ case 23
    .4byte lbl_08006e2a @ case 24
    .4byte lbl_08006e2a @ case 25
    .4byte lbl_08006dbc @ case 26
    .4byte lbl_08006e2a @ case 27
    .4byte lbl_08006e2a @ case 28
    .4byte lbl_08006e2a @ case 29
    .4byte lbl_08006dbc @ case 30
    .4byte lbl_08006e2a @ case 31
    .4byte lbl_08006e2a @ case 32
    .4byte lbl_08006e2a @ case 33
    .4byte lbl_08006e2a @ case 34
    .4byte lbl_08006e2a @ case 35
    .4byte lbl_08006e2a @ case 36
    .4byte lbl_08006e2a @ case 37
    .4byte lbl_08006e2a @ case 38
    .4byte lbl_08006e2a @ case 39
    .4byte lbl_08006e2a @ case 40
    .4byte lbl_08006db8 @ case 41
    .4byte lbl_08006db8 @ case 42
lbl_08006cfc:
    ldr r0, lbl_08006d14 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08006d18
    movs r0, #4
    b lbl_08006e52
    .align 2, 0
lbl_08006d14: .4byte 0x0823a554
lbl_08006d18:
    movs r2, #0x16
    ldrsh r0, [r5, r2]
    cmp r0, #0
    bne lbl_08006d24
    movs r0, #0xa
    b lbl_08006e52
lbl_08006d24:
    ldrb r0, [r5, #5]
    cmp r0, #0
    bne lbl_08006d2c
    b lbl_08006e50
lbl_08006d2c:
    strb r1, [r4]
    movs r0, #1
    strb r0, [r4, #5]
    b lbl_08006e54
lbl_08006d34:
    ldrh r0, [r5, #0xc]
    adds r0, #1
    strh r0, [r5, #0xc]
    ldr r0, lbl_08006d74 @ =gButtonInput
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08006d80
    ldr r0, lbl_08006d78 @ =gEquipment
    ldrb r1, [r0, #0xf]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08006d80
    ldr r0, lbl_08006d7c @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    movs r0, #6
    ands r1, r0
    cmp r1, #0
    bne lbl_08006db8
    movs r0, #0x14
    strb r0, [r4, #4]
    b lbl_08006db8
    .align 2, 0
lbl_08006d74: .4byte gButtonInput
lbl_08006d78: .4byte gEquipment
lbl_08006d7c: .4byte 0x0823a554
lbl_08006d80:
    movs r0, #0x18
    ldrsh r1, [r5, r0]
    movs r0, #0xc0
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_08006db8
    ldr r0, lbl_08006db4 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08006db8
    ldrh r0, [r4, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x12]
    bl ClipdataCheckGroundEffect
    cmp r0, #3
    beq lbl_08006db8
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0x32
    strh r0, [r4, #0x18]
    b lbl_08006e54
    .align 2, 0
lbl_08006db4: .4byte gSamusPhysics
lbl_08006db8:
    movs r0, #0x11
    b lbl_08006e52
lbl_08006dbc:
    ldr r0, lbl_08006dd4 @ =gButtonInput
    ldrh r0, [r0]
    ldrh r1, [r4, #0xe]
    ands r0, r1
    cmp r0, #0
    beq lbl_08006e04
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08006dd8
    movs r0, #0xa0
    b lbl_08006dda
    .align 2, 0
lbl_08006dd4: .4byte gButtonInput
lbl_08006dd8:
    ldr r0, lbl_08006de8 @ =0x0000ff60
lbl_08006dda:
    strh r0, [r4, #0x16]
    ldrb r0, [r5]
    cmp r0, #0x22
    bne lbl_08006dec
    movs r0, #0
    strb r0, [r4]
    b lbl_08006df4
    .align 2, 0
lbl_08006de8: .4byte 0x0000ff60
lbl_08006dec:
    movs r0, #0x12
    strb r0, [r4]
    movs r0, #6
    strb r0, [r4, #8]
lbl_08006df4:
    movs r0, #1
    strb r0, [r4, #5]
    movs r0, #0xa0
    strb r0, [r4, #0xa]
    movs r0, #0x8b
    bl SoundPlay
    b lbl_08006e54
lbl_08006e04:
    movs r0, #0x1e
    movs r1, #1
    bl ScreenShakeStartHorizontal
    ldrb r0, [r5]
    cmp r0, #0x22
    bne lbl_08006e16
    movs r0, #0x23
    b lbl_08006e18
lbl_08006e16:
    movs r0, #0x27
lbl_08006e18:
    strb r0, [r4]
    ldrb r0, [r5, #4]
    strb r0, [r4, #4]
    movs r0, #1
    strb r0, [r4, #0x1d]
    movs r0, #0x90
    bl SoundPlay
    b lbl_08006e54
lbl_08006e2a:
    ldr r0, lbl_08006e40 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08006e44
    movs r0, #4
    b lbl_08006e52
    .align 2, 0
lbl_08006e40: .4byte 0x0823a554
lbl_08006e44:
    movs r1, #0x16
    ldrsh r0, [r5, r1]
    cmp r0, #0
    bne lbl_08006e50
    movs r0, #0xa
    b lbl_08006e52
lbl_08006e50:
    movs r0, #1
lbl_08006e52:
    strb r0, [r4]
lbl_08006e54:
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    ldrb r2, [r4]
    adds r1, r0, #0
    cmp r2, #1
    beq lbl_08006e90
    cmp r2, #1
    bgt lbl_08006e6a
    cmp r2, #0
    beq lbl_08006e84
    b lbl_08006e9c
lbl_08006e6a:
    cmp r2, #0xa
    bne lbl_08006e9c
    ldr r0, lbl_08006e80 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006e90
    movs r0, #1
    strb r0, [r4, #0x1d]
    b lbl_08006e90
    .align 2, 0
lbl_08006e80: .4byte gSamusPhysics
lbl_08006e84:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bne lbl_08006e90
    movs r0, #1
    strb r0, [r4, #2]
lbl_08006e90:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bne lbl_08006e9c
    movs r0, #2
    strb r0, [r4, #2]
lbl_08006e9c:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #2
    bl samus_apply_environment_effects
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start SamusChangeToHurtPose
SamusChangeToHurtPose: @ 0x08006eac
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r0, lbl_08006ed4 @ =gEquipment
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_08006ebe
    b lbl_08006fe0
lbl_08006ebe:
    movs r2, #0
    ldrb r0, [r5]
    subs r0, #0x10
    cmp r0, #0x2a
    bhi lbl_08006f96
    lsls r0, r0, #2
    ldr r1, lbl_08006ed8 @ =lbl_08006edc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08006ed4: .4byte gEquipment
lbl_08006ed8: .4byte lbl_08006edc
lbl_08006edc: @ jump table
    .4byte lbl_08006f88 @ case 0
    .4byte lbl_08006f88 @ case 1
    .4byte lbl_08006f88 @ case 2
    .4byte lbl_08006f96 @ case 3
    .4byte lbl_08006f88 @ case 4
    .4byte lbl_08006f96 @ case 5
    .4byte lbl_08006f96 @ case 6
    .4byte lbl_08006f96 @ case 7
    .4byte lbl_08006f96 @ case 8
    .4byte lbl_08006f96 @ case 9
    .4byte lbl_08006f96 @ case 10
    .4byte lbl_08006f96 @ case 11
    .4byte lbl_08006f88 @ case 12
    .4byte lbl_08006f96 @ case 13
    .4byte lbl_08006f96 @ case 14
    .4byte lbl_08006f96 @ case 15
    .4byte lbl_08006f96 @ case 16
    .4byte lbl_08006f96 @ case 17
    .4byte lbl_08006f96 @ case 18
    .4byte lbl_08006f96 @ case 19
    .4byte lbl_08006f96 @ case 20
    .4byte lbl_08006f88 @ case 21
    .4byte lbl_08006f96 @ case 22
    .4byte lbl_08006f88 @ case 23
    .4byte lbl_08006f96 @ case 24
    .4byte lbl_08006f96 @ case 25
    .4byte lbl_08006f96 @ case 26
    .4byte lbl_08006f88 @ case 27
    .4byte lbl_08006f96 @ case 28
    .4byte lbl_08006f96 @ case 29
    .4byte lbl_08006f96 @ case 30
    .4byte lbl_08006f96 @ case 31
    .4byte lbl_08006f96 @ case 32
    .4byte lbl_08006f88 @ case 33
    .4byte lbl_08006f88 @ case 34
    .4byte lbl_08006f96 @ case 35
    .4byte lbl_08006f96 @ case 36
    .4byte lbl_08006f8c @ case 37
    .4byte lbl_08006f8c @ case 38
    .4byte lbl_08006f8c @ case 39
    .4byte lbl_08006f96 @ case 40
    .4byte lbl_08006f8c @ case 41
    .4byte lbl_08006f8c @ case 42
lbl_08006f88:
    movs r0, #0x31
    b lbl_08006fa8
lbl_08006f8c:
    movs r1, #0
    movs r0, #0x35
    strb r0, [r4]
    strh r1, [r4, #0x16]
    b lbl_08006faa
lbl_08006f96:
    ldr r0, lbl_08006fdc @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r0, #0x2f
lbl_08006fa8:
    strb r0, [r4]
lbl_08006faa:
    cmp r2, #0
    beq lbl_08006fb6
    ldrh r1, [r4, #0x14]
    movs r0, #0x3f
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_08006fb6:
    ldrb r0, [r5, #4]
    cmp r0, #0xff
    bne lbl_08006fc0
    movs r0, #1
    strb r0, [r4, #4]
lbl_08006fc0:
    movs r0, #0x70
    strh r0, [r4, #0x18]
    ldrb r0, [r5, #1]
    cmp r0, #2
    bne lbl_08006fce
    movs r0, #0x38
    strh r0, [r4, #0x18]
lbl_08006fce:
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    movs r0, #0x7c
    bl SoundPlay
    b lbl_0800701e
    .align 2, 0
lbl_08006fdc: .4byte 0x0823a554
lbl_08006fe0:
    ldr r0, lbl_08007034 @ =gDisableScrolling
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_08007038 @ =gMonochromeBgFading
    strb r1, [r0]
    movs r0, #0x33
    strb r0, [r4]
    ldr r1, lbl_0800703c @ =gBg1XPosition
    movs r2, #0xf0
    lsls r2, r2, #1
    adds r0, r2, #0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldrh r1, [r4, #0x12]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    strh r0, [r4, #0x16]
    ldr r1, lbl_08007040 @ =gBg1YPosition
    subs r2, #0x50
    adds r0, r2, #0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldrh r1, [r4, #0x14]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x14
    strh r0, [r4, #0x18]
    ldr r1, lbl_08007044 @ =gGameModeSub1
    movs r0, #5
    strh r0, [r1]
lbl_0800701e:
    movs r0, #0
    movs r1, #0x30
    strb r1, [r4, #6]
    strb r0, [r4, #8]
    movs r1, #2
    strb r1, [r4, #1]
    strb r0, [r6, #1]
    strb r0, [r6, #6]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007034: .4byte gDisableScrolling
lbl_08007038: .4byte gMonochromeBgFading
lbl_0800703c: .4byte gBg1XPosition
lbl_08007040: .4byte gBg1YPosition
lbl_08007044: .4byte gGameModeSub1

    thumb_func_start SamusChangeToKnockbackPose
SamusChangeToKnockbackPose: @ 0x08007048
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    movs r2, #0
    ldrb r0, [r5]
    subs r0, #0x10
    cmp r0, #0x2a
    bhi lbl_0800711c
    lsls r0, r0, #2
    ldr r1, lbl_08007064 @ =lbl_08007068
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08007064: .4byte lbl_08007068
lbl_08007068: @ jump table
    .4byte lbl_08007114 @ case 0
    .4byte lbl_08007114 @ case 1
    .4byte lbl_08007114 @ case 2
    .4byte lbl_0800711c @ case 3
    .4byte lbl_08007114 @ case 4
    .4byte lbl_0800711c @ case 5
    .4byte lbl_0800711c @ case 6
    .4byte lbl_0800711c @ case 7
    .4byte lbl_0800711c @ case 8
    .4byte lbl_0800711c @ case 9
    .4byte lbl_0800711c @ case 10
    .4byte lbl_0800711c @ case 11
    .4byte lbl_08007114 @ case 12
    .4byte lbl_0800711c @ case 13
    .4byte lbl_0800711c @ case 14
    .4byte lbl_0800711c @ case 15
    .4byte lbl_0800711c @ case 16
    .4byte lbl_0800711c @ case 17
    .4byte lbl_0800711c @ case 18
    .4byte lbl_0800711c @ case 19
    .4byte lbl_0800711c @ case 20
    .4byte lbl_08007114 @ case 21
    .4byte lbl_0800711c @ case 22
    .4byte lbl_08007114 @ case 23
    .4byte lbl_0800711c @ case 24
    .4byte lbl_0800711c @ case 25
    .4byte lbl_0800711c @ case 26
    .4byte lbl_08007114 @ case 27
    .4byte lbl_0800711c @ case 28
    .4byte lbl_0800711c @ case 29
    .4byte lbl_0800711c @ case 30
    .4byte lbl_0800711c @ case 31
    .4byte lbl_0800711c @ case 32
    .4byte lbl_08007114 @ case 33
    .4byte lbl_08007130 @ case 34
    .4byte lbl_0800711c @ case 35
    .4byte lbl_0800711c @ case 36
    .4byte lbl_08007118 @ case 37
    .4byte lbl_08007118 @ case 38
    .4byte lbl_08007118 @ case 39
    .4byte lbl_0800711c @ case 40
    .4byte lbl_08007118 @ case 41
    .4byte lbl_08007118 @ case 42
lbl_08007114:
    movs r0, #0x32
    b lbl_0800712e
lbl_08007118:
    movs r0, #0x35
    b lbl_0800712e
lbl_0800711c:
    ldr r0, lbl_08007160 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r0, #0x30
lbl_0800712e:
    strb r0, [r4]
lbl_08007130:
    cmp r2, #0
    beq lbl_0800713c
    ldrh r1, [r4, #0x14]
    movs r0, #0x3f
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_0800713c:
    movs r1, #0
    movs r0, #0x70
    strh r0, [r4, #0x18]
    ldrb r0, [r5, #1]
    cmp r0, #2
    bne lbl_0800714c
    movs r0, #0x38
    strh r0, [r4, #0x18]
lbl_0800714c:
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    strb r1, [r4, #8]
    movs r0, #2
    strb r0, [r4, #1]
    strb r1, [r6, #1]
    strb r1, [r6, #6]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007160: .4byte 0x0823a554

    thumb_func_start SamusCheckCarryFromCopy
SamusCheckCarryFromCopy: @ 0x08007164
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldrb r0, [r4]
    cmp r0, #0x42
    bls lbl_08007174
    b lbl_080074de
lbl_08007174:
    lsls r0, r0, #2
    ldr r1, lbl_08007180 @ =lbl_08007184
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08007180: .4byte lbl_08007184
lbl_08007184: @ jump table
    .4byte lbl_08007290 @ case 0
    .4byte lbl_080072b8 @ case 1
    .4byte lbl_080074da @ case 2
    .4byte lbl_080074de @ case 3
    .4byte lbl_080072ce @ case 4
    .4byte lbl_080074da @ case 5
    .4byte lbl_080074de @ case 6
    .4byte lbl_08007326 @ case 7
    .4byte lbl_080074de @ case 8
    .4byte lbl_080074d6 @ case 9
    .4byte lbl_080074de @ case 10
    .4byte lbl_080074de @ case 11
    .4byte lbl_080074de @ case 12
    .4byte lbl_080074de @ case 13
    .4byte lbl_080074de @ case 14
    .4byte lbl_080074de @ case 15
    .4byte lbl_080074de @ case 16
    .4byte lbl_0800731a @ case 17
    .4byte lbl_080074de @ case 18
    .4byte lbl_080074de @ case 19
    .4byte lbl_080074b8 @ case 20
    .4byte lbl_08007424 @ case 21
    .4byte lbl_080074de @ case 22
    .4byte lbl_080074de @ case 23
    .4byte lbl_080074de @ case 24
    .4byte lbl_080074de @ case 25
    .4byte lbl_080072e4 @ case 26
    .4byte lbl_080074de @ case 27
    .4byte lbl_080072e4 @ case 28
    .4byte lbl_08007458 @ case 29
    .4byte lbl_080074b8 @ case 30
    .4byte lbl_0800747c @ case 31
    .4byte lbl_080074de @ case 32
    .4byte lbl_08007340 @ case 33
    .4byte lbl_0800734c @ case 34
    .4byte lbl_080073f4 @ case 35
    .4byte lbl_080074de @ case 36
    .4byte lbl_08007408 @ case 37
    .4byte lbl_0800734c @ case 38
    .4byte lbl_080073fc @ case 39
    .4byte lbl_08007482 @ case 40
    .4byte lbl_080074de @ case 41
    .4byte lbl_080074da @ case 42
    .4byte lbl_080074de @ case 43
    .4byte lbl_080074b0 @ case 44
    .4byte lbl_080074b4 @ case 45
    .4byte lbl_080074da @ case 46
    .4byte lbl_080074de @ case 47
    .4byte lbl_080074de @ case 48
    .4byte lbl_080074de @ case 49
    .4byte lbl_080074de @ case 50
    .4byte lbl_080074de @ case 51
    .4byte lbl_080074b8 @ case 52
    .4byte lbl_080074be @ case 53
    .4byte lbl_080074de @ case 54
    .4byte lbl_080074de @ case 55
    .4byte lbl_080074de @ case 56
    .4byte lbl_080074da @ case 57
    .4byte lbl_080074de @ case 58
    .4byte lbl_080074de @ case 59
    .4byte lbl_080074de @ case 60
    .4byte lbl_08007424 @ case 61
    .4byte lbl_080074ca @ case 62
    .4byte lbl_080074de @ case 63
    .4byte lbl_080074de @ case 64
    .4byte lbl_080074e2 @ case 65
    .4byte lbl_080074d0 @ case 66
lbl_08007290:
    ldr r0, lbl_080072b0 @ =gButtonInput
    ldr r2, lbl_080072b4 @ =gButtonAssignments
    ldrh r1, [r0]
    ldrh r0, [r2, #2]
    ands r0, r1
    cmp r0, #0
    beq lbl_080072a0
    b lbl_080074de
lbl_080072a0:
    ldrh r0, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_080072aa
    b lbl_080074de
lbl_080072aa:
    movs r0, #5
    b lbl_080074e0
    .align 2, 0
lbl_080072b0: .4byte gButtonInput
lbl_080072b4: .4byte gButtonAssignments
lbl_080072b8:
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    ldrb r0, [r5]
    cmp r0, #4
    beq lbl_080072c8
    cmp r0, #6
    beq lbl_080072c8
    b lbl_080074e2
lbl_080072c8:
    movs r0, #6
    strb r0, [r4, #0xa]
    b lbl_080074e2
lbl_080072ce:
    ldrb r0, [r5, #2]
    strb r0, [r4, #2]
    movs r1, #1
    strb r1, [r4, #0x1d]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_080072e0
    b lbl_080074e2
lbl_080072e0:
    movs r0, #0
    b lbl_080074e0
lbl_080072e4:
    ldr r0, lbl_080072fc @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    strb r0, [r4, #0xa]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08007300
    movs r0, #0x94
    bl SoundPlay
    b lbl_0800731a
    .align 2, 0
lbl_080072fc: .4byte gSamusPhysics
lbl_08007300:
    ldr r0, lbl_08007310 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08007314
    movs r0, #0x7b
    bl SoundPlay
    b lbl_0800731a
    .align 2, 0
lbl_08007310: .4byte gEquipment
lbl_08007314:
    movs r0, #0x9c
    bl SoundPlay
lbl_0800731a:
    ldrb r0, [r5, #5]
    cmp r0, #0
    bne lbl_08007322
    b lbl_080074b8
lbl_08007322:
    movs r0, #6
    b lbl_080074b6
lbl_08007326:
    ldrh r0, [r5, #0x16]
    movs r1, #0
    strh r0, [r4, #0x16]
    strb r1, [r6]
    adds r0, r4, #0
    movs r1, #0
    movs r2, #6
    bl samus_apply_environment_effects
    movs r0, #0x8c
    bl SoundPlay
    b lbl_080074e2
lbl_08007340:
    movs r0, #0x32
    strb r0, [r4, #8]
    movs r0, #0x8e
    bl SoundPlay
    b lbl_080074e2
lbl_0800734c:
    ldrb r0, [r5, #4]
    cmp r0, #0xf0
    beq lbl_080073d8
    ldr r0, lbl_08007374 @ =gButtonInput
    ldr r1, lbl_08007378 @ =gButtonAssignments
    ldrh r2, [r0]
    ldrh r0, [r1, #2]
    ands r0, r2
    cmp r0, #0
    beq lbl_08007388
    movs r0, #2
    strb r0, [r4, #4]
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800737c
    movs r0, #0xa0
    b lbl_0800737e
    .align 2, 0
lbl_08007374: .4byte gButtonInput
lbl_08007378: .4byte gButtonAssignments
lbl_0800737c:
    ldr r0, lbl_08007384 @ =0x0000ff60
lbl_0800737e:
    strh r0, [r4, #0x16]
    movs r0, #0x60
    b lbl_080073da
    .align 2, 0
lbl_08007384: .4byte 0x0000ff60
lbl_08007388:
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080073d8
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_080073b8
    movs r0, #2
    strb r0, [r4, #4]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080073aa
    movs r0, #0xa0
    b lbl_080073ac
lbl_080073aa:
    ldr r0, lbl_080073b4 @ =0x0000ff60
lbl_080073ac:
    strh r0, [r4, #0x16]
    movs r0, #0x60
    b lbl_080073da
    .align 2, 0
lbl_080073b4: .4byte 0x0000ff60
lbl_080073b8:
    ldrb r0, [r4, #4]
    adds r0, #1
    strb r0, [r4, #4]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080073cc
    movs r0, #0xc0
    strh r0, [r4, #0x16]
    b lbl_080073dc
lbl_080073cc:
    ldr r0, lbl_080073d4 @ =0x0000ff40
    strh r0, [r4, #0x16]
    b lbl_080073dc
    .align 2, 0
lbl_080073d4: .4byte 0x0000ff40
lbl_080073d8:
    movs r0, #0xc0
lbl_080073da:
    strh r0, [r4, #0x18]
lbl_080073dc:
    ldrb r0, [r4, #5]
    adds r0, #1
    movs r1, #0
    strb r0, [r4, #5]
    strb r1, [r4, #8]
    strb r1, [r6]
    ldr r1, lbl_080073f0 @ =gScrewSpeedAnimation
    movs r0, #1
    strb r0, [r1]
    b lbl_080074e2
    .align 2, 0
lbl_080073f0: .4byte gScrewSpeedAnimation
lbl_080073f4:
    ldrb r0, [r5, #4]
    strb r0, [r4, #4]
    movs r0, #1
    strb r0, [r4, #0x1d]
lbl_080073fc:
    movs r0, #0x30
    strb r0, [r4, #6]
    movs r0, #0x90
    bl SoundPlay
    b lbl_080074e2
lbl_08007408:
    ldrb r0, [r5, #4]
    cmp r0, #0xf0
    bne lbl_08007412
    strb r0, [r4, #4]
    b lbl_08007418
lbl_08007412:
    ldr r1, lbl_08007420 @ =gScrewSpeedAnimation
    movs r0, #1
    strb r0, [r1]
lbl_08007418:
    movs r0, #0x8f
    bl SoundPlay
    b lbl_080074e2
    .align 2, 0
lbl_08007420: .4byte gScrewSpeedAnimation
lbl_08007424:
    ldrh r1, [r4, #0x14]
    movs r0, #0x3f
    ands r0, r1
    cmp r0, #0x1e
    bhi lbl_0800743c
    ldr r0, lbl_08007438 @ =0x0000ffc0
    ands r0, r1
    adds r0, #8
    b lbl_08007442
    .align 2, 0
lbl_08007438: .4byte 0x0000ffc0
lbl_0800743c:
    ldr r0, lbl_08007450 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x48
lbl_08007442:
    strh r0, [r4, #0x14]
    movs r0, #0
    strb r0, [r6]
    ldr r1, lbl_08007454 @ =gSamusEcho
    strb r0, [r1]
    strb r0, [r1, #1]
    b lbl_080074e2
    .align 2, 0
lbl_08007450: .4byte 0x0000ffc0
lbl_08007454: .4byte gSamusEcho
lbl_08007458:
    ldrh r1, [r5, #0x10]
    strh r1, [r4, #0x10]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08007468
    movs r0, #8
    b lbl_0800746a
lbl_08007468:
    ldr r0, lbl_08007478 @ =0x0000fff8
lbl_0800746a:
    strh r0, [r4, #0x18]
    movs r0, #0x87
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080074e2
    .align 2, 0
lbl_08007478: .4byte 0x0000fff8
lbl_0800747c:
    ldrh r0, [r5, #0x10]
    strh r0, [r4, #0x10]
    b lbl_080074b8
lbl_08007482:
    ldrb r0, [r5]
    subs r0, #0x29
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_080074de
    movs r0, #0
    strb r0, [r6]
    ldr r0, lbl_080074a4 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080074a8
    movs r0, #0x9b
    bl SoundPlay
    b lbl_080074e2
    .align 2, 0
lbl_080074a4: .4byte gEquipment
lbl_080074a8:
    movs r0, #0x7a
    bl SoundPlay
    b lbl_080074e2
lbl_080074b0:
    ldrh r0, [r5, #0xc]
    strh r0, [r4, #0xc]
lbl_080074b4:
    movs r0, #1
lbl_080074b6:
    strb r0, [r4, #0xa]
lbl_080074b8:
    movs r0, #0
    strb r0, [r6]
    b lbl_080074e2
lbl_080074be:
    ldrb r0, [r5]
    cmp r0, #0x3a
    bne lbl_080074e2
    movs r0, #1
    strb r0, [r4, #4]
    b lbl_080074e2
lbl_080074ca:
    movs r0, #1
    strh r0, [r4, #0xc]
    b lbl_080074de
lbl_080074d0:
    movs r0, #1
    strb r0, [r4, #3]
    b lbl_080074e2
lbl_080074d6:
    ldrh r0, [r5, #0x18]
    strh r0, [r4, #0x18]
lbl_080074da:
    movs r0, #1
    strb r0, [r4, #3]
lbl_080074de:
    ldrb r0, [r5, #2]
lbl_080074e0:
    strb r0, [r4, #2]
lbl_080074e2:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start SamusSetPose
SamusSetPose: @ 0x080074e8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    ldr r5, lbl_08007524 @ =gSamusData
    ldr r6, lbl_08007528 @ =gSamusDataCopy
    ldr r7, lbl_0800752c @ =gSamusWeaponInfo
    lsrs r4, r0, #0x18
    movs r1, #0xe0
    lsls r1, r1, #0x13
    adds r0, r0, r1
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_08007504
    movs r0, #0
    strb r0, [r5, #3]
lbl_08007504:
    adds r0, r5, #0
    bl SamusCopyData
    ldrb r0, [r6, #2]
    cmp r0, #5
    bne lbl_08007514
    movs r0, #0
    strb r0, [r6, #2]
lbl_08007514:
    ldrb r0, [r6]
    cmp r0, #0x22
    beq lbl_08007540
    cmp r0, #0x22
    bgt lbl_08007530
    cmp r0, #0x21
    beq lbl_0800753a
    b lbl_08007562
    .align 2, 0
lbl_08007524: .4byte gSamusData
lbl_08007528: .4byte gSamusDataCopy
lbl_0800752c: .4byte gSamusWeaponInfo
lbl_08007530:
    cmp r0, #0x25
    beq lbl_0800754c
    cmp r0, #0x26
    beq lbl_08007558
    b lbl_08007562
lbl_0800753a:
    cmp r4, #0x22
    beq lbl_08007562
    b lbl_08007544
lbl_08007540:
    cmp r4, #0x23
    beq lbl_08007562
lbl_08007544:
    movs r0, #0x8e
    bl SoundStop
    b lbl_08007562
lbl_0800754c:
    cmp r4, #0x26
    beq lbl_08007562
    movs r0, #0x8f
    bl SoundStop
    b lbl_08007562
lbl_08007558:
    cmp r4, #0x27
    beq lbl_08007562
    movs r0, #0x8f
    bl SoundStop
lbl_08007562:
    cmp r4, #0xfa
    beq lbl_08007590
    cmp r4, #0xfa
    bgt lbl_08007570
    cmp r4, #0xf9
    beq lbl_0800759c
    b lbl_080075a8
lbl_08007570:
    cmp r4, #0xfd
    beq lbl_08007584
    cmp r4, #0xfe
    bne lbl_080075a8
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl SamusSetMidAir
    b lbl_080075b4
lbl_08007584:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl SamusSetLandingPose
    b lbl_080075b4
lbl_08007590:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl SamusChangeToHurtPose
    b lbl_080075b4
lbl_0800759c:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl SamusChangeToKnockbackPose
    b lbl_080075b4
lbl_080075a8:
    strb r4, [r5]
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl SamusCheckCarryFromCopy
lbl_080075b4:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SamusCopyData
SamusCopyData: @ 0x080075bc
    push {r4, r5, r6, lr}
    ldr r2, lbl_08007610 @ =gSamusData
    ldr r3, lbl_08007614 @ =gScrewSpeedAnimation
    ldr r0, lbl_08007618 @ =gSamusDataCopy
    adds r1, r2, #0
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldm r1!, {r4, r5}
    stm r0!, {r4, r5}
    ldrb r0, [r2, #3]
    cmp r0, #0
    beq lbl_080075e4
    ldrh r0, [r2, #0xe]
    movs r1, #0x30
    eors r0, r1
    movs r1, #0
    strh r0, [r2, #0xe]
    strb r1, [r2, #3]
lbl_080075e4:
    movs r0, #0
    strb r0, [r2, #2]
    strb r0, [r2, #4]
    strb r0, [r2, #5]
    strb r0, [r2, #7]
    strb r0, [r2, #0xa]
    movs r1, #0
    strh r0, [r2, #0xc]
    strh r0, [r2, #0x10]
    strh r0, [r2, #0x16]
    strh r0, [r2, #0x18]
    strb r1, [r2, #0x1c]
    strb r1, [r2, #0x1d]
    ldrb r0, [r2, #8]
    cmp r0, #0xb4
    beq lbl_08007606
    strb r1, [r3]
lbl_08007606:
    strb r1, [r3, #1]
    strb r1, [r3, #2]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007610: .4byte gSamusData
lbl_08007614: .4byte gScrewSpeedAnimation
lbl_08007618: .4byte gSamusDataCopy

    thumb_func_start SamusUpdatePhysics
SamusUpdatePhysics: @ 0x0800761c
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_08007644 @ =gSamusData
    ldr r7, lbl_08007648 @ =gEquipment
    ldr r4, lbl_0800764c @ =gSamusPhysics
    ldr r1, lbl_08007650 @ =gUnk_03004fc9
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r6]
    cmp r0, #0x15
    blt lbl_08007654
    cmp r0, #0x1c
    ble lbl_08007638
    cmp r0, #0x3d
    bne lbl_08007654
lbl_08007638:
    ldrh r0, [r6, #0x14]
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    b lbl_08007656
    .align 2, 0
lbl_08007644: .4byte gSamusData
lbl_08007648: .4byte gEquipment
lbl_0800764c: .4byte gSamusPhysics
lbl_08007650: .4byte gUnk_03004fc9
lbl_08007654:
    ldrh r0, [r6, #0x14]
lbl_08007656:
    movs r5, #0
    ldrh r1, [r6, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #4
    bgt lbl_0800767a
    cmp r1, #1
    blt lbl_0800767a
    ldrb r1, [r7, #0xf]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_08007684
    movs r5, #1
    b lbl_08007684
lbl_0800767a:
    ldr r0, lbl_080076cc @ =gEquipment
    ldrb r0, [r0, #0x13]
    cmp r0, #0
    beq lbl_08007684
    adds r5, #1
lbl_08007684:
    adds r0, r4, #0
    adds r0, #0x5b
    strb r5, [r0]
    cmp r5, #0
    beq lbl_080076d0
    adds r0, #3
    movs r2, #4
    strh r2, [r0]
    adds r1, r4, #0
    adds r1, #0x60
    movs r0, #0x30
    strh r0, [r1]
    adds r1, #0xa
    movs r0, #0x20
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x68
    strh r2, [r0]
    adds r1, #2
    movs r0, #0x18
    strh r0, [r1]
    subs r1, #0xa
    movs r0, #5
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x64
    movs r1, #0x28
    strh r1, [r0]
    adds r0, #2
    strh r1, [r0]
    ldrb r0, [r6, #5]
    cmp r0, #0
    beq lbl_08007714
    movs r0, #0
    strb r0, [r6, #5]
    b lbl_08007714
    .align 2, 0
lbl_080076cc: .4byte gEquipment
lbl_080076d0:
    adds r0, r4, #0
    adds r0, #0x5e
    movs r1, #8
    strh r1, [r0]
    adds r3, r4, #0
    adds r3, #0x60
    movs r0, #0x60
    strh r0, [r3]
    adds r2, r4, #0
    adds r2, #0x6a
    movs r0, #0x40
    strh r0, [r2]
    adds r0, r4, #0
    adds r0, #0x68
    strh r1, [r0]
    adds r1, r4, #0
    adds r1, #0x6c
    movs r0, #0x30
    strh r0, [r1]
    subs r1, #0xa
    movs r0, #0xa
    strh r0, [r1]
    adds r1, #2
    movs r0, #0xc0
    strh r0, [r1]
    adds r1, #2
    movs r0, #0x80
    strh r0, [r1]
    ldrb r0, [r6, #5]
    cmp r0, #0
    beq lbl_08007714
    movs r0, #0xa0
    strh r0, [r2]
    strh r0, [r3]
lbl_08007714:
    ldrb r0, [r6, #1]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_08007724
    movs r0, #0
    strh r0, [r6, #0x1a]
lbl_08007724:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SamusChangeVelocityOnSlope
SamusChangeVelocityOnSlope: @ 0x0800772c
    push {lr}
    movs r1, #0x16
    ldrsh r2, [r0, r1]
    ldrh r1, [r0, #0xe]
    ldrh r3, [r0, #0x1a]
    ands r1, r3
    cmp r1, #0
    beq lbl_08007758
    movs r0, #1
    ands r0, r3
    cmp r0, #0
    beq lbl_0800774a
    lsls r0, r2, #1
    adds r0, r0, r2
    b lbl_0800774c
lbl_0800774a:
    lsls r0, r2, #2
lbl_0800774c:
    movs r1, #5
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    b lbl_0800776a
lbl_08007758:
    cmp r2, #0xa0
    ble lbl_08007760
    movs r2, #0xa0
    b lbl_0800776a
lbl_08007760:
    movs r0, #0xa0
    rsbs r0, r0, #0
    cmp r2, r0
    bge lbl_0800776a
    adds r2, r0, #0
lbl_0800776a:
    adds r0, r2, #0
    pop {r1}
    bx r1

    thumb_func_start SamusCopyPalette
SamusCopyPalette: @ 0x08007770
    push {r4, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    adds r2, r3, r2
    cmp r3, r2
    bge lbl_08007792
    ldr r1, lbl_08007798 @ =gSamusPalette
    lsls r0, r3, #1
    adds r1, r0, r1
    subs r3, r2, r3
lbl_08007784:
    ldrh r0, [r4]
    strh r0, [r1]
    adds r4, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_08007784
lbl_08007792:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007798: .4byte gSamusPalette

    thumb_func_start SamusUpdate
SamusUpdate: @ 0x0800779c
    push {r4, lr}
    ldr r4, lbl_080077dc @ =gSamusData
    ldr r0, lbl_080077e0 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #1
    ble lbl_080077b0
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
lbl_080077b0:
    adds r0, r4, #0
    bl SamusUpdatePhysics
    adds r0, r4, #0
    bl samus_execute_pose
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xff
    beq lbl_080077c8
    bl SamusSetPose
lbl_080077c8:
    ldr r1, lbl_080077e4 @ =gSamusPhysics
    adds r0, r4, #0
    bl sub_0800b8a8
    adds r0, r4, #0
    bl samus_update_velocity_pos
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080077dc: .4byte gSamusData
lbl_080077e0: .4byte gGameModeSub1
lbl_080077e4: .4byte gSamusPhysics

    thumb_func_start SamusUpdateHitboxMovingDirection
SamusUpdateHitboxMovingDirection: @ 0x080077e8
    push {r4, r5, lr}
    ldr r5, lbl_08007818 @ =gSamusData
    ldr r4, lbl_0800781c @ =gSamusPhysics
    adds r0, r4, #0
    adds r0, #0x58
    movs r1, #0
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r2, r4, #0
    adds r2, #0x4e
    strb r1, [r2]
    subs r0, #0xb
    strb r1, [r0]
    ldr r0, lbl_08007820 @ =gPreviousXPosition
    ldrh r1, [r5, #0x12]
    ldrh r0, [r0]
    cmp r1, r0
    bls lbl_08007824
    movs r0, #2
    b lbl_0800782a
    .align 2, 0
lbl_08007818: .4byte gSamusData
lbl_0800781c: .4byte gSamusPhysics
lbl_08007820: .4byte gPreviousXPosition
lbl_08007824:
    cmp r1, r0
    bhs lbl_0800782c
    movs r0, #1
lbl_0800782a:
    strb r0, [r2]
lbl_0800782c:
    ldr r0, lbl_08007848 @ =gUnk_03004fc9
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800785c
    ldr r0, lbl_0800784c @ =gPreviousYPosition
    ldrh r1, [r5, #0x14]
    ldrh r0, [r0]
    cmp r1, r0
    bls lbl_08007850
    adds r1, r4, #0
    adds r1, #0x4f
    movs r0, #2
    b lbl_0800785a
    .align 2, 0
lbl_08007848: .4byte gUnk_03004fc9
lbl_0800784c: .4byte gPreviousYPosition
lbl_08007850:
    cmp r1, r0
    bhs lbl_0800785c
    adds r1, r4, #0
    adds r1, #0x4f
    movs r0, #1
lbl_0800785a:
    strb r0, [r1]
lbl_0800785c:
    ldr r1, lbl_080078d8 @ =0x08239464
    ldrb r2, [r5]
    lsls r0, r2, #1
    adds r0, r0, r2
    adds r1, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #0x56
    adds r1, r1, r4
    mov ip, r1
    strb r0, [r1]
    ldr r2, lbl_080078dc @ =0x0823a554
    adds r3, r4, #0
    adds r3, #0x57
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r1, [r0]
    adds r0, r4, #0
    adds r0, #0x50
    strh r1, [r0]
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r1, r2, #2
    adds r0, r0, r1
    ldrh r0, [r0]
    adds r1, r4, #0
    adds r1, #0x52
    strh r0, [r1]
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r2, #4
    adds r0, r0, r2
    ldrh r1, [r0]
    adds r0, r4, #0
    adds r0, #0x54
    strh r1, [r0]
    mov r1, ip
    ldrb r0, [r1]
    cmp r0, #3
    bne lbl_080078c2
    adds r1, r4, #0
    adds r1, #0x4f
    movs r0, #2
    strb r0, [r1]
lbl_080078c2:
    adds r0, r5, #0
    adds r1, r4, #0
    bl SamusCheckCollisions
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_0800b8a8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080078d8: .4byte 0x08239464
lbl_080078dc: .4byte 0x0823a554

    thumb_func_start SamusCallGfxFunctions
SamusCallGfxFunctions: @ 0x080078e0
    push {r4, lr}
    ldr r4, lbl_08007914 @ =gSamusData
    ldr r0, lbl_08007918 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_080078f4
    adds r0, r4, #0
    bl samus_update_environment_effects
lbl_080078f4:
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    movs r1, #1
    cmp r0, #0
    beq lbl_08007902
    movs r1, #0
lbl_08007902:
    adds r0, r4, #0
    bl SamusUpdateGraphicsOam
    adds r0, r4, #0
    bl samus_update_anim_timers_and_palette
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007914: .4byte gSamusData
lbl_08007918: .4byte gGameModeSub1

    thumb_func_start SamusCallCheckLowHealth
SamusCallCheckLowHealth: @ 0x0800791c
    push {lr}
    bl check_play_low_health_sound
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start call_update_arm_cannon
call_update_arm_cannon: @ 0x08007928
    push {lr}
    ldr r0, lbl_08007944 @ =gSamusData
    ldrh r1, [r0, #0xe]
    movs r0, #0x10
    ands r0, r1
    movs r1, #1
    cmp r0, #0
    beq lbl_0800793a
    movs r1, #0
lbl_0800793a:
    adds r0, r1, #0
    bl update_cannon_oam
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007944: .4byte gSamusData

    thumb_func_start samus_bombjump
samus_bombjump: @ 0x08007948
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_0800799c @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08007996
    movs r3, #0
    movs r0, #0x7f
    ands r0, r2
    cmp r0, #9
    bls lbl_08007984
    ldr r1, lbl_080079a0 @ =gSamusData
    ldrb r0, [r1]
    cmp r0, #0x10
    blt lbl_08007984
    cmp r0, #0x12
    ble lbl_08007988
    cmp r0, #0x14
    bne lbl_08007984
    movs r4, #0x18
    ldrsh r0, [r1, r4]
    cmp r0, #0
    bgt lbl_08007984
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    bne lbl_08007984
    movs r3, #1
lbl_08007984:
    cmp r3, #0
    beq lbl_08007996
lbl_08007988:
    ldr r1, lbl_080079a0 @ =gSamusData
    movs r0, #0x7f
    ands r0, r2
    strb r0, [r1, #4]
    movs r0, #0xfe
    bl SamusSetPose
lbl_08007996:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800799c: .4byte gSamusPhysics
lbl_080079a0: .4byte gSamusData

    thumb_func_start samus_update_aim
samus_update_aim: @ 0x080079a4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r5, lbl_080079cc @ =gSamusWeaponInfo
    ldr r2, lbl_080079d0 @ =gButtonInput
    ldr r0, lbl_080079d4 @ =gButtonAssignments
    ldrh r1, [r2]
    ldrh r0, [r0, #2]
    ands r0, r1
    cmp r0, #0
    bne lbl_080079ba
    b lbl_08007afc
lbl_080079ba:
    ldrb r0, [r4]
    cmp r0, #0x3c
    bls lbl_080079c2
    b lbl_08007cf0
lbl_080079c2:
    lsls r0, r0, #2
    ldr r1, lbl_080079d8 @ =lbl_080079dc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080079cc: .4byte gSamusWeaponInfo
lbl_080079d0: .4byte gButtonInput
lbl_080079d4: .4byte gButtonAssignments
lbl_080079d8: .4byte lbl_080079dc
lbl_080079dc: @ jump table
    .4byte lbl_08007ad0 @ case 0
    .4byte lbl_08007ad0 @ case 1
    .4byte lbl_08007cf0 @ case 2
    .4byte lbl_08007ad0 @ case 3
    .4byte lbl_08007ad0 @ case 4
    .4byte lbl_08007cf0 @ case 5
    .4byte lbl_08007ad0 @ case 6
    .4byte lbl_08007cf0 @ case 7
    .4byte lbl_08007ad0 @ case 8
    .4byte lbl_08007cf0 @ case 9
    .4byte lbl_08007ad0 @ case 10
    .4byte lbl_08007ad0 @ case 11
    .4byte lbl_08007ad0 @ case 12
    .4byte lbl_08007cf0 @ case 13
    .4byte lbl_08007ad0 @ case 14
    .4byte lbl_08007ad0 @ case 15
    .4byte lbl_08007cf0 @ case 16
    .4byte lbl_08007cf0 @ case 17
    .4byte lbl_08007cf0 @ case 18
    .4byte lbl_08007cf0 @ case 19
    .4byte lbl_08007cf0 @ case 20
    .4byte lbl_08007cf0 @ case 21
    .4byte lbl_08007cf0 @ case 22
    .4byte lbl_08007cf0 @ case 23
    .4byte lbl_08007ad0 @ case 24
    .4byte lbl_08007cf0 @ case 25
    .4byte lbl_08007cf0 @ case 26
    .4byte lbl_08007cf0 @ case 27
    .4byte lbl_08007cf0 @ case 28
    .4byte lbl_08007cf0 @ case 29
    .4byte lbl_08007cf0 @ case 30
    .4byte lbl_08007cf0 @ case 31
    .4byte lbl_08007cf0 @ case 32
    .4byte lbl_08007cf0 @ case 33
    .4byte lbl_08007cf0 @ case 34
    .4byte lbl_08007cf0 @ case 35
    .4byte lbl_08007cf0 @ case 36
    .4byte lbl_08007cf0 @ case 37
    .4byte lbl_08007cf0 @ case 38
    .4byte lbl_08007cf0 @ case 39
    .4byte lbl_08007af6 @ case 40
    .4byte lbl_08007cf0 @ case 41
    .4byte lbl_08007cf0 @ case 42
    .4byte lbl_08007cf0 @ case 43
    .4byte lbl_08007cf0 @ case 44
    .4byte lbl_08007cf0 @ case 45
    .4byte lbl_08007cf0 @ case 46
    .4byte lbl_08007cf0 @ case 47
    .4byte lbl_08007cf0 @ case 48
    .4byte lbl_08007cf0 @ case 49
    .4byte lbl_08007cf0 @ case 50
    .4byte lbl_08007cf0 @ case 51
    .4byte lbl_08007cf0 @ case 52
    .4byte lbl_08007cf0 @ case 53
    .4byte lbl_08007cf0 @ case 54
    .4byte lbl_08007cf0 @ case 55
    .4byte lbl_08007cf0 @ case 56
    .4byte lbl_08007cf0 @ case 57
    .4byte lbl_08007cf0 @ case 58
    .4byte lbl_08007ad0 @ case 59
    .4byte lbl_08007ad0 @ case 60
lbl_08007ad0:
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08007ae0
    movs r0, #2
    strb r0, [r4, #2]
    b lbl_08007cee
lbl_08007ae0:
    ldrb r0, [r5]
    cmp r0, #1
    bls lbl_08007af0
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    bne lbl_08007af0
    b lbl_08007cf0
lbl_08007af0:
    movs r0, #1
    strb r0, [r4, #2]
    b lbl_08007cee
lbl_08007af6:
    movs r0, #2
    strb r0, [r4, #2]
    b lbl_08007cee
lbl_08007afc:
    ldrb r0, [r4]
    cmp r0, #0x3c
    bls lbl_08007b04
    b lbl_08007cec
lbl_08007b04:
    lsls r0, r0, #2
    ldr r1, lbl_08007b10 @ =lbl_08007b14
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08007b10: .4byte lbl_08007b14
lbl_08007b14: @ jump table
    .4byte lbl_08007c08 @ case 0
    .4byte lbl_08007c54 @ case 1
    .4byte lbl_08007cec @ case 2
    .4byte lbl_08007c54 @ case 3
    .4byte lbl_08007c64 @ case 4
    .4byte lbl_08007cec @ case 5
    .4byte lbl_08007c64 @ case 6
    .4byte lbl_08007cec @ case 7
    .4byte lbl_08007c6a @ case 8
    .4byte lbl_08007cec @ case 9
    .4byte lbl_08007c54 @ case 10
    .4byte lbl_08007c6a @ case 11
    .4byte lbl_08007c6a @ case 12
    .4byte lbl_08007cec @ case 13
    .4byte lbl_08007c6a @ case 14
    .4byte lbl_08007c6a @ case 15
    .4byte lbl_08007cec @ case 16
    .4byte lbl_08007cec @ case 17
    .4byte lbl_08007cec @ case 18
    .4byte lbl_08007cec @ case 19
    .4byte lbl_08007cec @ case 20
    .4byte lbl_08007cec @ case 21
    .4byte lbl_08007cec @ case 22
    .4byte lbl_08007cec @ case 23
    .4byte lbl_08007c6a @ case 24
    .4byte lbl_08007cec @ case 25
    .4byte lbl_08007cec @ case 26
    .4byte lbl_08007cec @ case 27
    .4byte lbl_08007cec @ case 28
    .4byte lbl_08007cec @ case 29
    .4byte lbl_08007cec @ case 30
    .4byte lbl_08007cec @ case 31
    .4byte lbl_08007cec @ case 32
    .4byte lbl_08007cec @ case 33
    .4byte lbl_08007cec @ case 34
    .4byte lbl_08007cec @ case 35
    .4byte lbl_08007cec @ case 36
    .4byte lbl_08007cec @ case 37
    .4byte lbl_08007cec @ case 38
    .4byte lbl_08007cec @ case 39
    .4byte lbl_08007cba @ case 40
    .4byte lbl_08007cec @ case 41
    .4byte lbl_08007cec @ case 42
    .4byte lbl_08007cec @ case 43
    .4byte lbl_08007cec @ case 44
    .4byte lbl_08007cec @ case 45
    .4byte lbl_08007cec @ case 46
    .4byte lbl_08007cec @ case 47
    .4byte lbl_08007cec @ case 48
    .4byte lbl_08007cec @ case 49
    .4byte lbl_08007cec @ case 50
    .4byte lbl_08007cec @ case 51
    .4byte lbl_08007cec @ case 52
    .4byte lbl_08007cec @ case 53
    .4byte lbl_08007cec @ case 54
    .4byte lbl_08007cec @ case 55
    .4byte lbl_08007cec @ case 56
    .4byte lbl_08007cec @ case 57
    .4byte lbl_08007cec @ case 58
    .4byte lbl_08007c54 @ case 59
    .4byte lbl_08007c64 @ case 60
lbl_08007c08:
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08007c18
    movs r0, #1
    strb r0, [r4, #2]
    b lbl_08007c32
lbl_08007c18:
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_08007c2a
    movs r0, #2
    strb r0, [r4, #2]
    b lbl_08007c32
lbl_08007c2a:
    ldrb r0, [r4, #2]
    cmp r0, #4
    bhi lbl_08007c32
    strb r1, [r4, #2]
lbl_08007c32:
    ldr r0, lbl_08007c50 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08007cec
    ldrb r0, [r4, #2]
    cmp r0, #5
    bne lbl_08007cec
    ldrb r0, [r5, #2]
    cmp r0, #0
    bne lbl_08007c64
    ldrb r0, [r5, #5]
    cmp r0, #0
    beq lbl_08007cec
    b lbl_08007c64
    .align 2, 0
lbl_08007c50: .4byte gEquipment
lbl_08007c54:
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    bne lbl_08007c64
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    bne lbl_08007c82
lbl_08007c64:
    movs r0, #0
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007c6a:
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08007c88
    ldrh r0, [r4, #0xe]
    ands r0, r1
    cmp r0, #0
    beq lbl_08007c82
    movs r0, #1
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007c82:
    movs r0, #3
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007c88:
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_08007c9e
    ldrh r0, [r4, #0xe]
    ands r0, r1
    cmp r0, #0
    bne lbl_08007cd0
    b lbl_08007cd6
lbl_08007c9e:
    ldrh r3, [r4, #0xe]
    ands r3, r1
    cmp r3, #0
    beq lbl_08007caa
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007caa:
    ldrb r0, [r4, #2]
    subs r0, #3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_08007cec
    strb r3, [r4, #2]
    b lbl_08007cec
lbl_08007cba:
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    beq lbl_08007cdc
    ldrh r0, [r4, #0xe]
    ands r0, r1
    cmp r0, #0
    beq lbl_08007cd6
lbl_08007cd0:
    movs r0, #2
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007cd6:
    movs r0, #4
    strb r0, [r4, #2]
    b lbl_08007cec
lbl_08007cdc:
    ldrh r0, [r4, #0xe]
    ands r0, r1
    cmp r0, #0
    bne lbl_08007cea
    ldrb r0, [r4, #2]
    cmp r0, #4
    beq lbl_08007cec
lbl_08007cea:
    strb r2, [r4, #2]
lbl_08007cec:
    movs r0, #0
lbl_08007cee:
    strb r0, [r5]
lbl_08007cf0:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SamusCheckFireBeamMissile
SamusCheckFireBeamMissile: @ 0x08007cf8
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r3, r1, #0
    adds r6, r2, #0
    movs r2, #0
    ldrb r0, [r3, #4]
    cmp r0, #0
    bne lbl_08007d4a
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08007d4a
    ldr r0, lbl_08007d30 @ =gChangedInput
    ldrh r1, [r0]
    movs r5, #2
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08007d4a
    ldrb r1, [r3, #2]
    movs r4, #1
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08007d34
    movs r0, #2
    strb r0, [r3, #1]
    b lbl_08007d44
    .align 2, 0
lbl_08007d30: .4byte gChangedInput
lbl_08007d34:
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08007d42
    movs r0, #3
    strb r0, [r3, #1]
    b lbl_08007d44
lbl_08007d42:
    strb r4, [r3, #1]
lbl_08007d44:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08007d4a:
    cmp r2, #0
    bne lbl_08007da2
    ldrb r0, [r3, #2]
    cmp r0, #0
    bne lbl_08007d9c
    ldr r0, lbl_08007d78 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08007d82
    ldrb r1, [r6, #0xd]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08007d9c
    ldrb r0, [r3, #5]
    cmp r0, #0x4e
    bhi lbl_08007d7c
    adds r0, #1
    strb r0, [r3, #5]
    b lbl_08007d9e
    .align 2, 0
lbl_08007d78: .4byte gButtonInput
lbl_08007d7c:
    movs r0, #0x40
    strb r0, [r3, #5]
    b lbl_08007d9e
lbl_08007d82:
    ldrb r0, [r3, #5]
    cmp r0, #0x3f
    bls lbl_08007d8c
    movs r0, #6
    b lbl_08007d92
lbl_08007d8c:
    cmp r0, #0x19
    bls lbl_08007d96
    movs r0, #1
lbl_08007d92:
    strb r0, [r3, #1]
    movs r2, #1
lbl_08007d96:
    movs r0, #0
    strb r0, [r3, #5]
    b lbl_08007d9e
lbl_08007d9c:
    strb r2, [r3, #5]
lbl_08007d9e:
    cmp r2, #0
    beq lbl_08007dac
lbl_08007da2:
    ldrb r0, [r7, #2]
    cmp r0, #5
    bne lbl_08007dac
    movs r0, #0
    strb r0, [r7, #2]
lbl_08007dac:
    adds r0, r2, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start samus_check_fully_charged
samus_check_fully_charged: @ 0x08007db4
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r2, r1, #0
    movs r4, #0
    ldrb r0, [r2, #5]
    cmp r0, #0x7e
    bhi lbl_08007dc6
    adds r0, #1
    b lbl_08007dc8
lbl_08007dc6:
    movs r0, #0x70
lbl_08007dc8:
    strb r0, [r2, #5]
    ldrb r0, [r2, #4]
    cmp r0, #0
    bne lbl_08007e0a
    ldrb r3, [r2, #1]
    cmp r3, #0
    bne lbl_08007e0a
    ldr r0, lbl_08007df8 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08007e0a
    ldrb r0, [r2, #5]
    cmp r0, #0x6f
    bls lbl_08007dfc
    movs r0, #6
    strb r0, [r2, #1]
    strb r3, [r2, #5]
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    b lbl_08007e00
    .align 2, 0
lbl_08007df8: .4byte gChangedInput
lbl_08007dfc:
    movs r0, #1
    strb r0, [r2, #1]
lbl_08007e00:
    movs r0, #0
    strb r0, [r2, #5]
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_08007e0a:
    cmp r4, #0
    beq lbl_08007e18
    ldrb r0, [r5, #2]
    cmp r0, #5
    bne lbl_08007e18
    movs r0, #0
    strb r0, [r5, #2]
lbl_08007e18:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start SamusCheckNewProjectile
SamusCheckNewProjectile: @ 0x08007e20
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    ldr r5, lbl_08007e48 @ =gSamusPhysics
    adds r0, r5, #0
    adds r0, #0x5c
    movs r1, #0
    strb r1, [r0]
    ldrb r0, [r2, #0x12]
    cmp r0, #2
    bne lbl_08007ede
    ldrb r0, [r4]
    subs r0, #0x1e
    cmp r0, #0x20
    bhi lbl_08007ed4
    lsls r0, r0, #2
    ldr r1, lbl_08007e4c @ =lbl_08007e50
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08007e48: .4byte gSamusPhysics
lbl_08007e4c: .4byte lbl_08007e50
lbl_08007e50: @ jump table
    .4byte lbl_08008050 @ case 0
    .4byte lbl_08007ed4 @ case 1
    .4byte lbl_08007ed4 @ case 2
    .4byte lbl_08007ed4 @ case 3
    .4byte lbl_08007ed4 @ case 4
    .4byte lbl_08007ed4 @ case 5
    .4byte lbl_08007ed4 @ case 6
    .4byte lbl_08007ed4 @ case 7
    .4byte lbl_08007ed4 @ case 8
    .4byte lbl_08007ed4 @ case 9
    .4byte lbl_08007ed4 @ case 10
    .4byte lbl_08007ed4 @ case 11
    .4byte lbl_08007ed4 @ case 12
    .4byte lbl_08007ed4 @ case 13
    .4byte lbl_08008050 @ case 14
    .4byte lbl_08008050 @ case 15
    .4byte lbl_08007ed4 @ case 16
    .4byte lbl_08008054 @ case 17
    .4byte lbl_08008054 @ case 18
    .4byte lbl_08007ed4 @ case 19
    .4byte lbl_08007ed4 @ case 20
    .4byte lbl_08008050 @ case 21
    .4byte lbl_08007ed4 @ case 22
    .4byte lbl_08007ed4 @ case 23
    .4byte lbl_08007ed4 @ case 24
    .4byte lbl_08007ed4 @ case 25
    .4byte lbl_08007ed4 @ case 26
    .4byte lbl_08007ed4 @ case 27
    .4byte lbl_08007ed4 @ case 28
    .4byte lbl_08007ed4 @ case 29
    .4byte lbl_08007ed4 @ case 30
    .4byte lbl_08007ed4 @ case 31
    .4byte lbl_08008050 @ case 32
lbl_08007ed4:
    adds r0, r4, #0
    adds r1, r3, #0
    bl samus_check_fully_charged
    b lbl_08008008
lbl_08007ede:
    ldrb r0, [r4]
    cmp r0, #0x42
    bls lbl_08007ee6
    b lbl_08008054
lbl_08007ee6:
    lsls r0, r0, #2
    ldr r1, lbl_08007ef0 @ =lbl_08007ef4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08007ef0: .4byte lbl_08007ef4
lbl_08007ef4: @ jump table
    .4byte lbl_08008000 @ case 0
    .4byte lbl_08008000 @ case 1
    .4byte lbl_08008000 @ case 2
    .4byte lbl_08008000 @ case 3
    .4byte lbl_08008000 @ case 4
    .4byte lbl_08008000 @ case 5
    .4byte lbl_08008000 @ case 6
    .4byte lbl_08008054 @ case 7
    .4byte lbl_08008000 @ case 8
    .4byte lbl_08008000 @ case 9
    .4byte lbl_08008000 @ case 10
    .4byte lbl_08008000 @ case 11
    .4byte lbl_08008000 @ case 12
    .4byte lbl_08008054 @ case 13
    .4byte lbl_08008000 @ case 14
    .4byte lbl_08008000 @ case 15
    .4byte lbl_08008046 @ case 16
    .4byte lbl_08008010 @ case 17
    .4byte lbl_08008010 @ case 18
    .4byte lbl_08008054 @ case 19
    .4byte lbl_08008010 @ case 20
    .4byte lbl_08008000 @ case 21
    .4byte lbl_08008054 @ case 22
    .4byte lbl_08008000 @ case 23
    .4byte lbl_08008000 @ case 24
    .4byte lbl_08008000 @ case 25
    .4byte lbl_08008054 @ case 26
    .4byte lbl_08008054 @ case 27
    .4byte lbl_08008054 @ case 28
    .4byte lbl_08008050 @ case 29
    .4byte lbl_08008054 @ case 30
    .4byte lbl_08008054 @ case 31
    .4byte lbl_08008054 @ case 32
    .4byte lbl_08008054 @ case 33
    .4byte lbl_08008054 @ case 34
    .4byte lbl_08008054 @ case 35
    .4byte lbl_08008054 @ case 36
    .4byte lbl_08008054 @ case 37
    .4byte lbl_08008054 @ case 38
    .4byte lbl_08008054 @ case 39
    .4byte lbl_08008000 @ case 40
    .4byte lbl_08008000 @ case 41
    .4byte lbl_08008054 @ case 42
    .4byte lbl_08008010 @ case 43
    .4byte lbl_08008050 @ case 44
    .4byte lbl_08008050 @ case 45
    .4byte lbl_08008050 @ case 46
    .4byte lbl_08008054 @ case 47
    .4byte lbl_08008054 @ case 48
    .4byte lbl_08008054 @ case 49
    .4byte lbl_08008054 @ case 50
    .4byte lbl_08008050 @ case 51
    .4byte lbl_08008054 @ case 52
    .4byte lbl_08008054 @ case 53
    .4byte lbl_08008054 @ case 54
    .4byte lbl_08008054 @ case 55
    .4byte lbl_08008054 @ case 56
    .4byte lbl_08008054 @ case 57
    .4byte lbl_08008054 @ case 58
    .4byte lbl_08008054 @ case 59
    .4byte lbl_08008054 @ case 60
    .4byte lbl_08008054 @ case 61
    .4byte lbl_08008054 @ case 62
    .4byte lbl_08008054 @ case 63
    .4byte lbl_08008054 @ case 64
    .4byte lbl_08008050 @ case 65
    .4byte lbl_08008050 @ case 66
lbl_08008000:
    adds r0, r4, #0
    adds r1, r3, #0
    bl SamusCheckFireBeamMissile
lbl_08008008:
    adds r1, r5, #0
    adds r1, #0x5c
    strb r0, [r1]
    b lbl_08008054
lbl_08008010:
    ldr r0, lbl_08008040 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08008046
    ldrb r0, [r3, #4]
    cmp r0, #0
    bne lbl_08008046
    ldrb r1, [r2, #0xd]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08008046
    ldrb r1, [r3, #2]
    movs r2, #4
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008044
    movs r0, #5
    strb r0, [r3, #1]
    b lbl_08008046
    .align 2, 0
lbl_08008040: .4byte gChangedInput
lbl_08008044:
    strb r2, [r3, #1]
lbl_08008046:
    ldrb r0, [r3, #5]
    cmp r0, #0x3f
    bls lbl_08008050
    movs r0, #6
    strb r0, [r3, #1]
lbl_08008050:
    movs r0, #0
    strb r0, [r3, #5]
lbl_08008054:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start samus_check_a_button_pressed
samus_check_a_button_pressed: @ 0x0800805c
    push {lr}
    adds r2, r0, #0
    movs r3, #0
    ldr r0, lbl_0800807c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008074
    movs r0, #1
    strb r0, [r2, #4]
    movs r3, #1
lbl_08008074:
    adds r0, r3, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800807c: .4byte gChangedInput

    thumb_func_start SamusSetHighlightedWeapon
SamusSetHighlightedWeapon: @ 0x08008080
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r4, r1, #0
    adds r5, r2, #0
    movs r6, #0
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    bne lbl_08008094
    strb r6, [r4, #3]
    b lbl_080080ba
lbl_08008094:
    ldrh r0, [r5, #8]
    cmp r0, #0
    bne lbl_080080a0
    movs r0, #1
    strb r0, [r4, #3]
    b lbl_080080ba
lbl_080080a0:
    ldr r0, lbl_080080cc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080080ba
    ldrb r0, [r4, #3]
    movs r1, #1
    eors r0, r1
    strb r0, [r4, #3]
    movs r0, #0x85
    bl SoundPlay
lbl_080080ba:
    ldrb r0, [r7]
    subs r0, #0x11
    cmp r0, #0x21
    bhi lbl_0800817c
    lsls r0, r0, #2
    ldr r1, lbl_080080d0 @ =lbl_080080d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080080cc: .4byte gChangedInput
lbl_080080d0: .4byte lbl_080080d4
lbl_080080d4: @ jump table
    .4byte lbl_0800815c @ case 0
    .4byte lbl_0800815c @ case 1
    .4byte lbl_0800817c @ case 2
    .4byte lbl_0800815c @ case 3
    .4byte lbl_080081a6 @ case 4
    .4byte lbl_0800817c @ case 5
    .4byte lbl_0800817c @ case 6
    .4byte lbl_0800817c @ case 7
    .4byte lbl_0800817c @ case 8
    .4byte lbl_0800817c @ case 9
    .4byte lbl_0800817c @ case 10
    .4byte lbl_0800817c @ case 11
    .4byte lbl_080081a6 @ case 12
    .4byte lbl_080081a6 @ case 13
    .4byte lbl_080081a6 @ case 14
    .4byte lbl_080081a6 @ case 15
    .4byte lbl_080081a6 @ case 16
    .4byte lbl_080081a6 @ case 17
    .4byte lbl_080081a6 @ case 18
    .4byte lbl_080081a6 @ case 19
    .4byte lbl_080081a6 @ case 20
    .4byte lbl_080081a6 @ case 21
    .4byte lbl_080081a6 @ case 22
    .4byte lbl_0800817c @ case 23
    .4byte lbl_0800817c @ case 24
    .4byte lbl_0800817c @ case 25
    .4byte lbl_0800815c @ case 26
    .4byte lbl_080081a6 @ case 27
    .4byte lbl_0800817c @ case 28
    .4byte lbl_0800817c @ case 29
    .4byte lbl_0800817c @ case 30
    .4byte lbl_0800817c @ case 31
    .4byte lbl_0800815c @ case 32
    .4byte lbl_0800815c @ case 33
lbl_0800815c:
    ldr r0, lbl_08008174 @ =gButtonInput
    ldr r1, lbl_08008178 @ =gButtonAssignments
    ldrh r2, [r0]
    ldrh r0, [r1]
    ands r0, r2
    cmp r0, #0
    beq lbl_080081a6
    ldrb r0, [r5, #0xb]
    cmp r0, #0
    beq lbl_080081a6
    movs r6, #4
    b lbl_080081aa
    .align 2, 0
lbl_08008174: .4byte gButtonInput
lbl_08008178: .4byte gButtonAssignments
lbl_0800817c:
    ldr r0, lbl_0800819c @ =gButtonInput
    ldr r1, lbl_080081a0 @ =gButtonAssignments
    ldrh r2, [r0]
    ldrh r0, [r1]
    ands r0, r2
    cmp r0, #0
    beq lbl_080081a6
    ldrb r0, [r4, #3]
    cmp r0, #0
    bne lbl_080081a4
    ldrh r0, [r5, #8]
    cmp r0, #0
    beq lbl_080081a6
    movs r6, #1
    b lbl_080081aa
    .align 2, 0
lbl_0800819c: .4byte gButtonInput
lbl_080081a0: .4byte gButtonAssignments
lbl_080081a4:
    movs r6, #2
lbl_080081a6:
    cmp r6, #0
    beq lbl_080081b8
lbl_080081aa:
    ldrb r0, [r4, #2]
    cmp r0, #0
    bne lbl_080081b8
    strb r0, [r4, #5]
    movs r0, #0x84
    bl SoundPlay
lbl_080081b8:
    strb r6, [r4, #2]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start SamusSetSpinningPose
SamusSetSpinningPose: @ 0x080081c0
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r0, #0xe
    beq lbl_08008200
    cmp r0, #0xe
    bgt lbl_080081d4
    cmp r0, #0xc
    beq lbl_080081da
    b lbl_08008270
lbl_080081d4:
    cmp r0, #0xf
    beq lbl_08008234
    b lbl_08008270
lbl_080081da:
    ldr r0, lbl_080081fc @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08008270
    ldrb r1, [r1, #0xf]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    bne lbl_0800820e
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08008270
    movs r0, #0xe
    strb r0, [r2]
    b lbl_08008270
    .align 2, 0
lbl_080081fc: .4byte gSamusPhysics
lbl_08008200:
    ldrb r1, [r1, #0xf]
    movs r0, #8
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    beq lbl_08008214
lbl_0800820e:
    movs r0, #0xf
    strb r0, [r2]
    b lbl_08008270
lbl_08008214:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08008226
    ldr r0, lbl_08008230 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008270
lbl_08008226:
    movs r0, #0xc
    strb r0, [r2]
    strb r3, [r2, #0x1d]
    b lbl_08008270
    .align 2, 0
lbl_08008230: .4byte gSamusPhysics
lbl_08008234:
    ldr r0, lbl_08008248 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800824c
    movs r1, #0
    movs r0, #0xc
    strb r0, [r2]
    strb r1, [r2, #0x1d]
    b lbl_0800826a
    .align 2, 0
lbl_08008248: .4byte gSamusPhysics
lbl_0800824c:
    ldrb r1, [r1, #0xf]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    bne lbl_0800826a
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08008262
    movs r0, #0xe
    b lbl_08008264
lbl_08008262:
    movs r0, #0xc
lbl_08008264:
    strb r0, [r2]
    movs r0, #0
    strb r0, [r2, #0x1d]
lbl_0800826a:
    ldr r1, lbl_08008274 @ =gScrewSpeedAnimation
    movs r0, #0
    strb r0, [r1]
lbl_08008270:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08008274: .4byte gScrewSpeedAnimation

    thumb_func_start sub_08008278
sub_08008278: @ 0x08008278
    push {r4, lr}
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    lsls r1, r1, #0x10
    asrs r3, r1, #0x10
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800829e
    ldrh r0, [r2, #0x16]
    adds r0, r4, r0
    strh r0, [r2, #0x16]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, r3
    ble lbl_080082b0
    strh r3, [r2, #0x16]
    b lbl_080082b0
lbl_0800829e:
    ldrh r0, [r2, #0x16]
    subs r0, r0, r4
    strh r0, [r2, #0x16]
    movs r1, #0x16
    ldrsh r0, [r2, r1]
    rsbs r1, r3, #0
    cmp r0, r1
    bge lbl_080082b0
    strh r1, [r2, #0x16]
lbl_080082b0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start samus_apply_hazard_damage
samus_apply_hazard_damage: @ 0x080082b8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r3, r0, #0
    adds r7, r1, #0
    adds r4, r2, #0
    ldrb r0, [r3]
    cmp r0, #0x20
    bne lbl_080082cc
    b lbl_08008414
lbl_080082cc:
    cmp r0, #0x20
    bgt lbl_080082e2
    cmp r0, #0x1c
    bgt lbl_080082e8
    cmp r0, #0x15
    blt lbl_080082e8
    ldrh r0, [r3, #0x14]
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    b lbl_080082ea
lbl_080082e2:
    cmp r0, #0x33
    bne lbl_080082e8
    b lbl_08008414
lbl_080082e8:
    ldrh r2, [r3, #0x14]
lbl_080082ea:
    ldrb r0, [r4]
    adds r0, #1
    strb r0, [r4]
    movs r5, #0
    mov r8, r5
    movs r6, #0
    ldrh r1, [r3, #0x12]
    adds r0, r2, #0
    bl ClipdataCheckCurrentAffectingAtPosition
    adds r2, r0, #0
    movs r0, #0xff
    ands r2, r0
    ldrb r1, [r7, #0xf]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800831e
    cmp r2, #4
    bne lbl_080083a8
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #3
    bls lbl_080083a8
    movs r6, #1
    b lbl_080083a8
lbl_0800831e:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08008346
    cmp r2, #4
    bne lbl_08008336
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #1
    bls lbl_080083a8
    movs r6, #1
    b lbl_080083a8
lbl_08008336:
    cmp r2, #2
    bne lbl_080083a8
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #4
    bls lbl_080083a8
    movs r6, #1
    b lbl_080083a8
lbl_08008346:
    cmp r2, #4
    bne lbl_08008350
    movs r5, #1
    movs r6, #1
    b lbl_080083a8
lbl_08008350:
    cmp r2, #6
    bne lbl_08008376
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #3
    bls lbl_0800835e
    movs r6, #0xf
lbl_0800835e:
    ldrh r0, [r4, #2]
    adds r1, r0, #1
    strh r1, [r4, #2]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x57
    bls lbl_080083a8
    mov r0, r8
    strh r0, [r4, #2]
    movs r0, #1
    mov r8, r0
    b lbl_080083a8
lbl_08008376:
    cmp r2, #2
    bne lbl_08008386
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #2
    bls lbl_080083a8
    movs r6, #1
    b lbl_080083a8
lbl_08008386:
    cmp r2, #3
    bne lbl_08008396
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #7
    bls lbl_080083a8
    movs r6, #1
    b lbl_080083a8
lbl_08008396:
    cmp r2, #5
    beq lbl_0800839e
    cmp r2, #7
    bne lbl_080083a8
lbl_0800839e:
    movs r5, #1
    ldrb r0, [r4]
    cmp r0, #5
    bls lbl_080083a8
    movs r6, #0xf
lbl_080083a8:
    cmp r5, #0
    bne lbl_080083b6
    strb r5, [r4]
    movs r0, #0
    strh r5, [r4, #2]
    strb r0, [r4, #4]
    b lbl_08008404
lbl_080083b6:
    ldrb r0, [r4, #4]
    adds r1, r0, #1
    strb r1, [r4, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x21
    beq lbl_080083d4
    cmp r0, #0x21
    bgt lbl_080083ce
    cmp r0, #1
    beq lbl_080083d4
    b lbl_080083ec
lbl_080083ce:
    cmp r0, #0x40
    beq lbl_080083e8
    b lbl_080083ec
lbl_080083d4:
    cmp r2, #4
    beq lbl_080083e0
    cmp r2, #2
    beq lbl_080083e0
    cmp r2, #3
    bne lbl_080083ec
lbl_080083e0:
    movs r0, #0x7e
    bl SoundPlay
    b lbl_080083ec
lbl_080083e8:
    movs r0, #0
    strb r0, [r4, #4]
lbl_080083ec:
    cmp r6, #0
    beq lbl_080083fa
    ldrh r0, [r7, #6]
    subs r0, #1
    movs r1, #0
    strh r0, [r7, #6]
    strb r1, [r4]
lbl_080083fa:
    cmp r6, #0xf
    bne lbl_08008404
    movs r0, #0x7f
    bl SoundPlay
lbl_08008404:
    ldrh r0, [r7, #6]
    cmp r0, #0
    beq lbl_08008410
    mov r0, r8
    cmp r0, #0
    beq lbl_08008414
lbl_08008410:
    movs r0, #1
    b lbl_08008416
lbl_08008414:
    movs r0, #0
lbl_08008416:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_08008420
sub_08008420: @ 0x08008420
    push {r4, lr}
    adds r4, r0, #0
    ldrb r2, [r4]
    cmp r2, #0x33
    beq lbl_08008460
    cmp r2, #0x22
    beq lbl_08008432
    cmp r2, #0x26
    bne lbl_08008436
lbl_08008432:
    movs r0, #1
    b lbl_08008462
lbl_08008436:
    ldrh r0, [r4, #0x16]
    adds r0, #0x9f
    lsls r0, r0, #0x10
    movs r1, #0x9f
    lsls r1, r1, #0x11
    cmp r0, r1
    bls lbl_0800845a
    ldrb r0, [r4, #5]
    cmp r0, #0
    bne lbl_08008470
    cmp r2, #7
    beq lbl_08008464
    adds r0, #1
    strb r0, [r4, #5]
    movs r0, #0x8b
    bl SoundPlay
    b lbl_08008464
lbl_0800845a:
    ldrb r0, [r4, #5]
    cmp r0, #0
    beq lbl_0800846a
lbl_08008460:
    movs r0, #0
lbl_08008462:
    strb r0, [r4, #5]
lbl_08008464:
    ldrb r0, [r4, #5]
    cmp r0, #0
    bne lbl_08008470
lbl_0800846a:
    movs r0, #0x8b
    bl SoundStop
lbl_08008470:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SamusInactivity
SamusInactivity: @ 0x08008478
    movs r0, #0xff
    bx lr

    thumb_func_start sub_0800847c
sub_0800847c: @ 0x0800847c
    push {r4, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_08008490 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008498
    ldr r1, lbl_08008494 @ =0x082399b0
    b lbl_0800849a
    .align 2, 0
lbl_08008490: .4byte gEquipment
lbl_08008494: .4byte 0x082399b0
lbl_08008498:
    ldr r1, lbl_080084cc @ =0x08238b74
lbl_0800849a:
    ldrb r0, [r2]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldrb r0, [r2, #0x1d]
    lsls r0, r0, #4
    adds r3, r3, r0
    ldrb r1, [r3, #0xc]
    cmp r4, #0
    beq lbl_080084b2
    lsls r0, r1, #0x19
    lsrs r1, r0, #0x18
lbl_080084b2:
    ldrb r0, [r2, #0x1c]
    cmp r0, r1
    blo lbl_080084d4
    movs r0, #0
    strb r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1d]
    adds r0, #1
    strb r0, [r2, #0x1d]
    ldrb r0, [r3, #0x1c]
    cmp r0, #0
    bne lbl_080084d0
    movs r0, #2
    b lbl_080084d6
    .align 2, 0
lbl_080084cc: .4byte 0x08238b74
lbl_080084d0:
    movs r0, #1
    b lbl_080084d6
lbl_080084d4:
    movs r0, #0
lbl_080084d6:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusRunning
SamusRunning: @ 0x080084dc
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_080084f4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080084f8
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0xfe
    b lbl_080085aa
    .align 2, 0
lbl_080084f4: .4byte gChangedInput
lbl_080084f8:
    ldr r2, lbl_08008528 @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x60
    movs r1, #0
    ldrsh r5, [r0, r1]
    ldr r0, lbl_0800852c @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800854e
    adds r0, r2, #0
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800854e
    ldrb r0, [r4, #0xa]
    adds r1, r0, #0
    adds r3, r0, #0
    cmp r1, #0x8b
    bls lbl_08008530
    movs r5, #0xa0
    b lbl_08008536
    .align 2, 0
lbl_08008528: .4byte gSamusPhysics
lbl_0800852c: .4byte gEquipment
lbl_08008530:
    cmp r1, #0x77
    bls lbl_08008536
    movs r5, #0x8c
lbl_08008536:
    ldrh r0, [r4, #0x16]
    adds r0, #0x5f
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xbe
    bls lbl_0800854e
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x9f
    bhi lbl_08008552
    adds r0, r3, #1
    b lbl_08008550
lbl_0800854e:
    movs r0, #0
lbl_08008550:
    strb r0, [r4, #0xa]
lbl_08008552:
    ldr r0, lbl_0800857c @ =gButtonInput
    ldrh r3, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008580
    adds r0, r2, #0
    adds r0, #0x5e
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r1, r5, #0
    adds r2, r4, #0
    bl sub_08008278
    adds r0, r4, #0
    bl samus_update_aim
    movs r0, #0xff
    b lbl_080085aa
    .align 2, 0
lbl_0800857c: .4byte gButtonInput
lbl_08008580:
    ldrb r0, [r4, #5]
    cmp r0, #0
    beq lbl_0800858a
    movs r0, #7
    b lbl_080085aa
lbl_0800858a:
    adds r0, r2, #0
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008598
    movs r0, #3
    b lbl_080085aa
lbl_08008598:
    movs r0, #0x30
    eors r0, r1
    ands r0, r3
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_080085a8
    movs r0, #2
    b lbl_080085aa
lbl_080085a8:
    movs r0, #1
lbl_080085aa:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start SamusRunningGfx
SamusRunningGfx: @ 0x080085b0
    push {r4, r5, lr}
    adds r2, r0, #0
    ldr r5, lbl_080085c8 @ =gScrewSpeedAnimation
    ldr r4, lbl_080085cc @ =gSamusPhysics
    ldrb r1, [r2, #5]
    cmp r1, #0
    bne lbl_080085d4
    ldr r0, lbl_080085d0 @ =0x08238d8c
    ldr r3, [r0]
    strb r1, [r5]
    b lbl_080085dc
    .align 2, 0
lbl_080085c8: .4byte gScrewSpeedAnimation
lbl_080085cc: .4byte gSamusPhysics
lbl_080085d0: .4byte 0x08238d8c
lbl_080085d4:
    ldr r0, lbl_08008618 @ =0x08238dac
    ldr r3, [r0]
    movs r0, #1
    strb r0, [r5]
lbl_080085dc:
    ldrb r0, [r2, #0x1d]
    lsls r0, r0, #4
    adds r3, r3, r0
    ldrb r1, [r3, #0xc]
    adds r4, #0x5b
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080085f0
    lsls r0, r1, #0x19
    lsrs r1, r0, #0x18
lbl_080085f0:
    ldrb r0, [r2, #0x1c]
    cmp r0, r1
    blo lbl_0800868a
    movs r0, #0
    strb r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1d]
    adds r0, #1
    strb r0, [r2, #0x1d]
    ldrb r0, [r3, #0x1c]
    cmp r0, #0
    bne lbl_08008608
    strb r0, [r2, #0x1d]
lbl_08008608:
    ldrb r0, [r2, #0x1d]
    cmp r0, #2
    beq lbl_08008648
    cmp r0, #2
    bgt lbl_0800861c
    cmp r0, #1
    beq lbl_08008626
    b lbl_0800868a
    .align 2, 0
lbl_08008618: .4byte 0x08238dac
lbl_0800861c:
    cmp r0, #6
    beq lbl_08008660
    cmp r0, #7
    beq lbl_08008654
    b lbl_0800868a
lbl_08008626:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_08008666
    ldr r0, lbl_0800863c @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008640
    movs r0, #0x64
    bl SoundPlay
    b lbl_0800868a
    .align 2, 0
lbl_0800863c: .4byte gEquipment
lbl_08008640:
    movs r0, #0x96
    bl SoundPlay
    b lbl_0800868a
lbl_08008648:
    adds r0, r2, #0
    movs r1, #0
    movs r2, #0
    bl samus_apply_environment_effects
    b lbl_0800868a
lbl_08008654:
    adds r0, r2, #0
    movs r1, #0
    movs r2, #1
    bl samus_apply_environment_effects
    b lbl_0800868a
lbl_08008660:
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0800866e
lbl_08008666:
    movs r0, #0x93
    bl SoundPlay
    b lbl_0800868a
lbl_0800866e:
    ldr r0, lbl_08008680 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008684
    movs r0, #0x65
    bl SoundPlay
    b lbl_0800868a
    .align 2, 0
lbl_08008680: .4byte gEquipment
lbl_08008684:
    movs r0, #0x97
    bl SoundPlay
lbl_0800868a:
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_080086c8
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    ldr r3, lbl_080086d0 @ =0x08288e20
    ldrb r2, [r5, #2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r1, #8]
    cmp r0, r1
    blo lbl_080086c8
    movs r0, #0
    strb r0, [r5, #1]
    ldrb r0, [r5, #2]
    adds r0, #1
    strb r0, [r5, #2]
    ldrb r1, [r5, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r3
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_080086c8
    strb r0, [r5, #2]
lbl_080086c8:
    movs r0, #0xff
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080086d0: .4byte 0x08288e20

    thumb_func_start SamusStanding
SamusStanding: @ 0x080086d4
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008718 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_08008724
    ldr r0, lbl_0800871c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008724
    ldrb r0, [r4, #8]
    cmp r0, #0
    beq lbl_08008724
    ldr r0, lbl_08008720 @ =0x0823a554
    ldrh r1, [r0, #4]
    subs r1, #0x20
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08008724
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    strh r0, [r4, #0x14]
    movs r0, #0x21
    b lbl_08008816
    .align 2, 0
lbl_08008718: .4byte gButtonInput
lbl_0800871c: .4byte gChangedInput
lbl_08008720: .4byte 0x0823a554
lbl_08008724:
    adds r0, r4, #0
    bl samus_check_a_button_pressed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08008734
    movs r0, #0xfe
    b lbl_08008816
lbl_08008734:
    ldr r0, lbl_08008748 @ =gButtonInput
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800874c
    movs r0, #0
    b lbl_08008816
    .align 2, 0
lbl_08008748: .4byte gButtonInput
lbl_0800874c:
    ldr r0, lbl_0800875c @ =gSamusPhysics
    adds r6, r0, #0
    adds r6, #0x5c
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_08008760
    movs r0, #3
    b lbl_08008816
    .align 2, 0
lbl_0800875c: .4byte gSamusPhysics
lbl_08008760:
    movs r0, #0x30
    eors r0, r1
    ands r0, r2
    cmp r0, #0
    beq lbl_0800876e
    movs r0, #2
    b lbl_08008816
lbl_0800876e:
    ldr r0, lbl_080087b8 @ =gChangedInput
    ldrh r1, [r0]
    movs r5, #0x80
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080087d2
    ldrh r0, [r4, #0x14]
    adds r0, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    asrs r0, r0, #0x10
    cmp r0, #1
    beq lbl_080087f0
    ldr r0, lbl_080087bc @ =gSamusWeaponInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800879e
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_08008804
lbl_0800879e:
    ldr r4, lbl_080087c0 @ =gEquipment
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    beq lbl_080087ac
    movs r0, #0x79
    bl SoundPlay
lbl_080087ac:
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_080087c4
    movs r0, #6
    b lbl_08008816
    .align 2, 0
lbl_080087b8: .4byte gChangedInput
lbl_080087bc: .4byte gSamusWeaponInfo
lbl_080087c0: .4byte gEquipment
lbl_080087c4:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_080087ce
    movs r0, #0x3c
    b lbl_08008816
lbl_080087ce:
    movs r0, #4
    b lbl_08008816
lbl_080087d2:
    movs r5, #0x40
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008804
    ldrh r0, [r4, #0x14]
    adds r0, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    asrs r0, r0, #0x10
    cmp r0, #2
    bne lbl_08008804
lbl_080087f0:
    ldrh r1, [r4, #0x12]
    ldr r0, lbl_08008800 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x20
    strh r0, [r4, #0x12]
    strh r5, [r4, #0x10]
    movs r0, #0x1f
    b lbl_08008816
    .align 2, 0
lbl_08008800: .4byte 0x0000ffc0
lbl_08008804:
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    beq lbl_0800880e
    subs r0, #1
    strb r0, [r4, #0xa]
lbl_0800880e:
    adds r0, r4, #0
    bl samus_update_aim
    movs r0, #0xff
lbl_08008816:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SamusStandingGfx
SamusStandingGfx: @ 0x0800881c
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008832
    movs r0, #0
    strb r0, [r4, #0x1d]
lbl_08008832:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningAround
SamusTurningAround: @ 0x0800883c
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008880 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_0800888c
    ldr r0, lbl_08008884 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800888c
    ldrb r0, [r4, #8]
    cmp r0, #0
    beq lbl_0800888c
    ldr r0, lbl_08008888 @ =0x0823a554
    ldrh r1, [r0, #4]
    subs r1, #0x20
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800888c
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    strh r0, [r4, #0x14]
    movs r0, #0x21
    b lbl_080088f2
    .align 2, 0
lbl_08008880: .4byte gButtonInput
lbl_08008884: .4byte gChangedInput
lbl_08008888: .4byte 0x0823a554
lbl_0800888c:
    adds r0, r4, #0
    bl samus_check_a_button_pressed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800889c
    movs r0, #0xfe
    b lbl_080088f2
lbl_0800889c:
    ldr r0, lbl_080088dc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080088c8
    ldr r0, lbl_080088e0 @ =gSamusWeaponInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080088b6
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_080088c8
lbl_080088b6:
    movs r0, #5
    strb r0, [r4]
    ldr r0, lbl_080088e4 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_080088c8
    movs r0, #0x79
    bl SoundPlay
lbl_080088c8:
    ldr r0, lbl_080088e8 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080088f0
    ldrb r0, [r4]
    cmp r0, #5
    bne lbl_080088ec
    movs r0, #6
    b lbl_080088f2
    .align 2, 0
lbl_080088dc: .4byte gChangedInput
lbl_080088e0: .4byte gSamusWeaponInfo
lbl_080088e4: .4byte gEquipment
lbl_080088e8: .4byte gSamusPhysics
lbl_080088ec:
    movs r0, #3
    b lbl_080088f2
lbl_080088f0:
    movs r0, #0xff
lbl_080088f2:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusTurningAroundGfx
SamusTurningAroundGfx: @ 0x080088f8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008938
    ldr r2, lbl_08008920 @ =gButtonInput
    ldrh r0, [r4, #0xe]
    movs r1, #0x30
    eors r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08008924
    movs r0, #0
    b lbl_0800893a
    .align 2, 0
lbl_08008920: .4byte gButtonInput
lbl_08008924:
    ldr r0, lbl_08008930 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008934
    movs r0, #0x3b
    b lbl_0800893a
    .align 2, 0
lbl_08008930: .4byte gEquipment
lbl_08008934:
    movs r0, #1
    b lbl_0800893a
lbl_08008938:
    movs r0, #0xff
lbl_0800893a:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusShootingGfx
SamusShootingGfx: @ 0x08008940
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08008954
    movs r0, #0xff
    b lbl_08008956
lbl_08008954:
    movs r0, #1
lbl_08008956:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusCrouching
SamusCrouching: @ 0x0800895c
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldr r0, lbl_080089a0 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_080089ac
    ldr r0, lbl_080089a4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080089ac
    ldrb r0, [r4, #8]
    cmp r0, #0
    beq lbl_080089ac
    ldr r0, lbl_080089a8 @ =0x0823a554
    ldrh r1, [r0, #4]
    subs r1, #0x20
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080089ac
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    strh r0, [r4, #0x14]
    movs r0, #0x21
    b lbl_08008b0c
    .align 2, 0
lbl_080089a0: .4byte gButtonInput
lbl_080089a4: .4byte gChangedInput
lbl_080089a8: .4byte 0x0823a554
lbl_080089ac:
    ldr r6, lbl_080089cc @ =0x0823a554
    movs r0, #4
    ldrsh r1, [r6, r0]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #1
    bne lbl_080089d4
    ldrh r0, [r4, #0x12]
    ldr r1, lbl_080089d0 @ =0x0000ffc0
    ands r1, r0
    ldrh r0, [r6]
    subs r1, r1, r0
    b lbl_080089e4
    .align 2, 0
lbl_080089cc: .4byte 0x0823a554
lbl_080089d0: .4byte 0x0000ffc0
lbl_080089d4:
    cmp r5, #8
    bne lbl_080089e8
    ldrh r0, [r4, #0x12]
    ldr r1, lbl_08008a0c @ =0x0000ffc0
    ands r1, r0
    ldrh r0, [r6]
    subs r1, r1, r0
    adds r1, #0x3f
lbl_080089e4:
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
lbl_080089e8:
    adds r0, r4, #0
    bl samus_check_a_button_pressed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08008a10
    movs r0, #6
    ands r0, r5
    cmp r0, #0
    bne lbl_08008a10
    cmp r5, #1
    beq lbl_08008a04
    cmp r5, #8
    bne lbl_08008a06
lbl_08008a04:
    strh r7, [r4, #0x12]
lbl_08008a06:
    movs r0, #0xfe
    b lbl_08008b0c
    .align 2, 0
lbl_08008a0c: .4byte 0x0000ffc0
lbl_08008a10:
    ldr r2, lbl_08008a4c @ =gChangedInput
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a58
    movs r0, #6
    ands r0, r5
    cmp r0, #0
    bne lbl_08008a58
    ldr r0, lbl_08008a50 @ =gSamusWeaponInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008a32
    ldrb r0, [r4, #2]
    cmp r0, #1
    bne lbl_08008a58
lbl_08008a32:
    cmp r5, #1
    beq lbl_08008a3a
    cmp r5, #8
    bne lbl_08008a3c
lbl_08008a3a:
    strh r7, [r4, #0x12]
lbl_08008a3c:
    movs r0, #6
    strh r0, [r4, #0xc]
    ldr r0, lbl_08008a54 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008afc
    b lbl_08008b04
    .align 2, 0
lbl_08008a4c: .4byte gChangedInput
lbl_08008a50: .4byte gSamusWeaponInfo
lbl_08008a54: .4byte gEquipment
lbl_08008a58:
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a90
    ldr r0, lbl_08008a88 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a90
    ldr r0, lbl_08008a8c @ =gSamusWeaponInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008a7c
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_08008a90
lbl_08008a7c:
    movs r0, #0x77
    bl SoundPlay
    movs r0, #0x10
    b lbl_08008b0c
    .align 2, 0
lbl_08008a88: .4byte gEquipment
lbl_08008a8c: .4byte gSamusWeaponInfo
lbl_08008a90:
    adds r0, r4, #0
    bl samus_update_aim
    ldrb r0, [r4, #2]
    cmp r0, #3
    bne lbl_08008aa0
    movs r0, #0
    strb r0, [r4, #2]
lbl_08008aa0:
    ldr r0, lbl_08008ab0 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008ab4
    movs r0, #6
    b lbl_08008b0c
    .align 2, 0
lbl_08008ab0: .4byte gSamusPhysics
lbl_08008ab4:
    ldr r1, lbl_08008ac8 @ =gButtonInput
    ldrh r2, [r4, #0xe]
    movs r0, #0x30
    eors r0, r2
    ldrh r1, [r1]
    ands r0, r1
    cmp r0, #0
    beq lbl_08008acc
    movs r0, #5
    b lbl_08008b0c
    .align 2, 0
lbl_08008ac8: .4byte gButtonInput
lbl_08008acc:
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08008b08
    movs r0, #6
    ands r0, r5
    cmp r0, #0
    bne lbl_08008b0a
    ldrb r0, [r4, #0xa]
    adds r1, r0, #1
    strb r1, [r4, #0xa]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_08008b0a
    cmp r5, #1
    beq lbl_08008af2
    cmp r5, #8
    bne lbl_08008af4
lbl_08008af2:
    strh r7, [r4, #0x12]
lbl_08008af4:
    ldr r0, lbl_08008b00 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008b04
lbl_08008afc:
    movs r0, #0x3b
    b lbl_08008b0c
    .align 2, 0
lbl_08008b00: .4byte gEquipment
lbl_08008b04:
    movs r0, #1
    b lbl_08008b0c
lbl_08008b08:
    strb r0, [r4, #0xa]
lbl_08008b0a:
    movs r0, #0xff
lbl_08008b0c:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningAroundAndCrouching
SamusTurningAroundAndCrouching: @ 0x08008b14
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    ldr r0, lbl_08008b58 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_08008b64
    ldr r0, lbl_08008b5c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008b64
    ldrb r0, [r5, #8]
    cmp r0, #0
    beq lbl_08008b64
    ldr r0, lbl_08008b60 @ =0x0823a554
    ldrh r1, [r0, #4]
    subs r1, #0x20
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r5, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08008b64
    ldrh r0, [r5, #0x14]
    subs r0, #0x20
    strh r0, [r5, #0x14]
    movs r0, #0x21
    b lbl_08008c1e
    .align 2, 0
lbl_08008b58: .4byte gButtonInput
lbl_08008b5c: .4byte gChangedInput
lbl_08008b60: .4byte 0x0823a554
lbl_08008b64:
    ldr r6, lbl_08008b84 @ =0x0823a554
    movs r0, #4
    ldrsh r1, [r6, r0]
    adds r0, r5, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #1
    bne lbl_08008b8c
    ldrh r0, [r5, #0x12]
    ldr r1, lbl_08008b88 @ =0x0000ffc0
    ands r1, r0
    ldrh r0, [r6]
    subs r1, r1, r0
    b lbl_08008b9c
    .align 2, 0
lbl_08008b84: .4byte 0x0823a554
lbl_08008b88: .4byte 0x0000ffc0
lbl_08008b8c:
    cmp r4, #8
    bne lbl_08008ba0
    ldrh r0, [r5, #0x12]
    ldr r1, lbl_08008bc4 @ =0x0000ffc0
    ands r1, r0
    ldrh r0, [r6]
    subs r1, r1, r0
    adds r1, #0x3f
lbl_08008b9c:
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
lbl_08008ba0:
    adds r0, r5, #0
    bl samus_check_a_button_pressed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08008bc8
    movs r0, #6
    ands r0, r4
    cmp r0, #0
    bne lbl_08008bc8
    cmp r4, #1
    beq lbl_08008bbc
    cmp r4, #8
    bne lbl_08008bbe
lbl_08008bbc:
    strh r7, [r5, #0x12]
lbl_08008bbe:
    movs r0, #0xfe
    b lbl_08008c1e
    .align 2, 0
lbl_08008bc4: .4byte 0x0000ffc0
lbl_08008bc8:
    ldr r0, lbl_08008c0c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008bf8
    movs r0, #6
    ands r0, r4
    cmp r0, #0
    bne lbl_08008bf8
    ldr r0, lbl_08008c10 @ =gSamusWeaponInfo
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008bea
    ldrb r0, [r5, #2]
    cmp r0, #1
    bne lbl_08008bf8
lbl_08008bea:
    cmp r4, #1
    beq lbl_08008bf2
    cmp r4, #8
    bne lbl_08008bf4
lbl_08008bf2:
    strh r7, [r5, #0x12]
lbl_08008bf4:
    movs r0, #2
    strb r0, [r5]
lbl_08008bf8:
    ldr r0, lbl_08008c14 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008c1c
    ldrb r0, [r5]
    cmp r0, #2
    bne lbl_08008c18
    movs r0, #3
    b lbl_08008c1e
    .align 2, 0
lbl_08008c0c: .4byte gChangedInput
lbl_08008c10: .4byte gSamusWeaponInfo
lbl_08008c14: .4byte gSamusPhysics
lbl_08008c18:
    movs r0, #6
    b lbl_08008c1e
lbl_08008c1c:
    movs r0, #0xff
lbl_08008c1e:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start SamusTurningAroundAndCrouchingGfx
SamusTurningAroundAndCrouchingGfx: @ 0x08008c24
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008c48
    ldr r0, lbl_08008c40 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008c44
    movs r0, #0x3c
    b lbl_08008c4a
    .align 2, 0
lbl_08008c40: .4byte gEquipment
lbl_08008c44:
    movs r0, #4
    b lbl_08008c4a
lbl_08008c48:
    movs r0, #0xff
lbl_08008c4a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusShootingAndCrouchingGfx
SamusShootingAndCrouchingGfx: @ 0x08008c50
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08008c64
    movs r0, #0xff
    b lbl_08008c66
lbl_08008c64:
    movs r0, #4
lbl_08008c66:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusSkidding
SamusSkidding: @ 0x08008c6c
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08008c84 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008c88
    movs r0, #1
    strb r0, [r2, #4]
    movs r0, #0xfe
    b lbl_08008cf2
    .align 2, 0
lbl_08008c84: .4byte gChangedInput
lbl_08008c88:
    ldr r0, lbl_08008c9c @ =gButtonInput
    ldrh r1, [r0]
    ldrh r3, [r2, #0xe]
    adds r0, r1, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08008ca0
    movs r0, #0
    b lbl_08008cf2
    .align 2, 0
lbl_08008c9c: .4byte gButtonInput
lbl_08008ca0:
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x80
    bne lbl_08008ccc
    movs r0, #0xb4
    strb r0, [r2, #8]
    ldr r1, lbl_08008cc0 @ =gScrewSpeedAnimation
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_08008cc4 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008cc8
    movs r0, #0x3c
    b lbl_08008cf2
    .align 2, 0
lbl_08008cc0: .4byte gScrewSpeedAnimation
lbl_08008cc4: .4byte gEquipment
lbl_08008cc8:
    movs r0, #4
    b lbl_08008cf2
lbl_08008ccc:
    movs r0, #0x10
    ands r0, r3
    cmp r0, #0
    beq lbl_08008ce4
    ldrh r0, [r2, #0x16]
    subs r0, #0xa
    strh r0, [r2, #0x16]
    lsls r0, r0, #0x10
    cmp r0, #0
    bgt lbl_08008cf0
lbl_08008ce0:
    movs r0, #1
    b lbl_08008cf2
lbl_08008ce4:
    ldrh r0, [r2, #0x16]
    adds r0, #0xa
    strh r0, [r2, #0x16]
    lsls r0, r0, #0x10
    cmp r0, #0
    bge lbl_08008ce0
lbl_08008cf0:
    movs r0, #0xff
lbl_08008cf2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusMidAir
SamusMidAir: @ 0x08008cf8
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r2, lbl_08008d24 @ =gChangedInput
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d2c
    ldrb r0, [r4, #2]
    cmp r0, #4
    bne lbl_08008d2c
    ldr r0, lbl_08008d28 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d2c
    movs r0, #0x77
    bl SoundPlay
    movs r0, #0x14
    b lbl_08008dec
    .align 2, 0
lbl_08008d24: .4byte gChangedInput
lbl_08008d28: .4byte gEquipment
lbl_08008d2c:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d5c
    ldrb r0, [r4, #8]
    cmp r0, #0
    beq lbl_08008d40
    movs r0, #0x21
    b lbl_08008dec
lbl_08008d40:
    ldr r0, lbl_08008d58 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #0xc0
    ands r1, r0
    cmp r1, #0
    bne lbl_08008d5c
    movs r0, #0xc
    strb r0, [r4]
    strb r1, [r4, #0x1d]
    strb r1, [r4, #0x1c]
    b lbl_08008dea
    .align 2, 0
lbl_08008d58: .4byte gButtonInput
lbl_08008d5c:
    movs r6, #0
    ldr r5, lbl_08008d88 @ =gSamusPhysics
    adds r0, r5, #0
    adds r0, #0x68
    movs r1, #0
    ldrsh r2, [r0, r1]
    ldr r0, lbl_08008d8c @ =gButtonInput
    ldrh r3, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d90
    adds r0, r5, #0
    adds r0, #0x6a
    movs r3, #0
    ldrsh r1, [r0, r3]
    adds r0, r2, #0
    adds r2, r4, #0
    bl sub_08008278
    b lbl_08008dc6
    .align 2, 0
lbl_08008d88: .4byte gSamusPhysics
lbl_08008d8c: .4byte gButtonInput
lbl_08008d90:
    movs r0, #0x30
    eors r0, r1
    ands r0, r3
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_08008da0
    movs r6, #1
    b lbl_08008dc6
lbl_08008da0:
    ldrh r0, [r4, #0x16]
    movs r3, #0x16
    ldrsh r1, [r4, r3]
    cmp r1, #0
    ble lbl_08008db6
    subs r0, r0, r2
    strh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    cmp r0, #0
    bge lbl_08008dc6
    b lbl_08008dc4
lbl_08008db6:
    cmp r1, #0
    bge lbl_08008dc6
    adds r0, r2, r0
    strh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    cmp r0, #0
    ble lbl_08008dc6
lbl_08008dc4:
    strh r6, [r4, #0x16]
lbl_08008dc6:
    adds r0, r4, #0
    bl samus_update_aim
    cmp r6, #0
    beq lbl_08008dd4
    movs r0, #9
    b lbl_08008dec
lbl_08008dd4:
    ldr r0, lbl_08008df4 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08008dea
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    ble lbl_08008dea
    strh r1, [r4, #0x18]
lbl_08008dea:
    movs r0, #0xff
lbl_08008dec:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08008df4: .4byte gButtonInput

    thumb_func_start SamusMidAirGfx
SamusMidAirGfx: @ 0x08008df8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0x18
    ldrsh r0, [r4, r1]
    cmp r0, #0
    blt lbl_08008e10
    ldrb r0, [r4, #0x1d]
    cmp r0, #2
    bne lbl_08008e1a
    movs r0, #0
    strb r0, [r4, #0x1c]
    b lbl_08008e1a
lbl_08008e10:
    ldrb r0, [r4, #0x1d]
    cmp r0, #1
    bhi lbl_08008e1a
    movs r0, #2
    strb r0, [r4, #0x1d]
lbl_08008e1a:
    adds r0, r4, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008e2e
    movs r0, #4
    strb r0, [r4, #0x1d]
lbl_08008e2e:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningAroundMidAir
SamusTurningAroundMidAir: @ 0x08008e38
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08008e54 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008e80
    ldrb r0, [r2, #8]
    cmp r0, #0
    beq lbl_08008e58
    movs r0, #0x21
    b lbl_08008eb0
    .align 2, 0
lbl_08008e54: .4byte gChangedInput
lbl_08008e58:
    ldr r0, lbl_08008e7c @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_08008e80
    movs r0, #0xc
    strb r0, [r2]
    ldrh r0, [r2, #0xe]
    movs r1, #0x30
    eors r0, r1
    movs r1, #0
    strh r0, [r2, #0xe]
    strb r1, [r2, #0x1d]
    strb r1, [r2, #0x1c]
    strb r1, [r2, #3]
    b lbl_08008eae
    .align 2, 0
lbl_08008e7c: .4byte gButtonInput
lbl_08008e80:
    ldr r0, lbl_08008e94 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008e98
    movs r0, #2
    strb r0, [r2, #4]
    movs r0, #0xfe
    b lbl_08008eb0
    .align 2, 0
lbl_08008e94: .4byte gSamusPhysics
lbl_08008e98:
    ldr r0, lbl_08008eb4 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08008eae
    movs r3, #0x18
    ldrsh r0, [r2, r3]
    cmp r0, #0
    ble lbl_08008eae
    strh r1, [r2, #0x18]
lbl_08008eae:
    movs r0, #0xff
lbl_08008eb0:
    pop {r1}
    bx r1
    .align 2, 0
lbl_08008eb4: .4byte gButtonInput

    thumb_func_start SamusTurningAroundMidAirGfx
SamusTurningAroundMidAirGfx: @ 0x08008eb8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08008ece
    movs r0, #0xff
    b lbl_08008ed2
lbl_08008ece:
    strb r0, [r4, #4]
    movs r0, #0xfe
lbl_08008ed2:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusStartingSpinJumpGfx
SamusStartingSpinJumpGfx: @ 0x08008ed8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008ef2
    movs r1, #0
    movs r0, #0xc
    strb r0, [r4]
    strb r1, [r4, #0x1d]
lbl_08008ef2:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusSpinning
SamusSpinning: @ 0x08008efc
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008f10 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008f14
    movs r0, #0
    b lbl_08008f2a
    .align 2, 0
lbl_08008f10: .4byte gSamusPhysics
lbl_08008f14:
    ldr r0, lbl_08008f30 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_08008f34
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008f34
    movs r0, #2
lbl_08008f2a:
    strb r0, [r4, #4]
    movs r0, #0xfe
    b lbl_08009030
    .align 2, 0
lbl_08008f30: .4byte gButtonInput
lbl_08008f34:
    adds r0, r4, #0
    bl samus_update_aim
    ldr r1, lbl_08008f80 @ =gSamusPhysics
    adds r0, r1, #0
    adds r0, #0x68
    movs r2, #0
    ldrsh r5, [r0, r2]
    ldr r0, lbl_08008f84 @ =gEquipment
    ldrb r2, [r0, #0xf]
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_08008f92
    adds r0, r1, #0
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08008f92
    ldr r0, lbl_08008f88 @ =gChangedInput
    ldrh r1, [r0]
    movs r3, #1
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08008fe6
    movs r0, #0x18
    ldrsh r1, [r4, r0]
    movs r0, #0x40
    rsbs r0, r0, #0
    cmp r1, r0
    bgt lbl_08008fe6
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08008f8c
    movs r0, #0xe8
    b lbl_08008f8e
    .align 2, 0
lbl_08008f80: .4byte gSamusPhysics
lbl_08008f84: .4byte gEquipment
lbl_08008f88: .4byte gChangedInput
lbl_08008f8c:
    movs r0, #0xc0
lbl_08008f8e:
    strh r0, [r4, #0x18]
    b lbl_0800902e
lbl_08008f92:
    ldrb r0, [r4, #7]
    cmp r0, #0
    beq lbl_08008fe6
    subs r0, #1
    strb r0, [r4, #7]
    ldrh r0, [r4, #0xe]
    ldrh r2, [r4, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_08008fe6
    ldr r0, lbl_08008fe0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08008fe4
    movs r0, #0x10
    ands r0, r2
    movs r2, #0x28
    cmp r0, #0
    beq lbl_08008fbe
    subs r2, #0x50
lbl_08008fbe:
    ldrh r0, [r4, #0x14]
    ldrh r1, [r4, #0x12]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcessForSamus
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    beq lbl_08008fe4
    ldrh r0, [r4, #0xc]
    strh r0, [r4, #0xe]
    movs r0, #0xd
    b lbl_08009030
    .align 2, 0
lbl_08008fe0: .4byte gChangedInput
lbl_08008fe4:
    movs r5, #1
lbl_08008fe6:
    ldr r2, lbl_08009004 @ =gButtonInput
    ldrh r1, [r4, #0xe]
    movs r0, #0x30
    adds r3, r1, #0
    eors r3, r0
    ldrh r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08009008
    movs r0, #0
    strh r3, [r4, #0xe]
    strh r0, [r4, #0x16]
    b lbl_08009018
    .align 2, 0
lbl_08009004: .4byte gButtonInput
lbl_08009008:
    ldr r0, lbl_08009038 @ =gSamusPhysics
    adds r0, #0x6a
    movs r2, #0
    ldrsh r1, [r0, r2]
    adds r0, r5, #0
    adds r2, r4, #0
    bl sub_08008278
lbl_08009018:
    ldr r0, lbl_0800903c @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_0800902e
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    ble lbl_0800902e
    strh r1, [r4, #0x18]
lbl_0800902e:
    movs r0, #0xff
lbl_08009030:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009038: .4byte gSamusPhysics
lbl_0800903c: .4byte gButtonInput

    thumb_func_start SamusSpinningGfx
SamusSpinningGfx: @ 0x08009040
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009074 @ =gSamusPhysics
    adds r5, r0, #0
    adds r5, #0x5b
    ldrb r1, [r5]
    adds r0, r4, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800905e
    movs r0, #0
    strb r0, [r4, #0x1d]
lbl_0800905e:
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_08009092
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_08009078
    movs r0, #0x92
    bl SoundPlay
    b lbl_08009092
    .align 2, 0
lbl_08009074: .4byte gSamusPhysics
lbl_08009078:
    ldr r0, lbl_08009088 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_0800908c
    movs r0, #0x6a
    bl SoundPlay
    b lbl_08009092
    .align 2, 0
lbl_08009088: .4byte gEquipment
lbl_0800908c:
    movs r0, #0x98
    bl SoundPlay
lbl_08009092:
    movs r0, #0xff
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusStartingWallJump
SamusStartingWallJump: @ 0x0800909c
    push {lr}
    adds r3, r0, #0
    ldr r0, lbl_080090b4 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080090b8
    movs r0, #0
    strb r0, [r3, #4]
    movs r0, #0xfe
    b lbl_080090da
    .align 2, 0
lbl_080090b4: .4byte gSamusPhysics
lbl_080090b8:
    ldr r0, lbl_080090d4 @ =gButtonInput
    ldrh r2, [r0]
    movs r1, #0x30
    ands r1, r2
    cmp r1, #0
    bne lbl_080090d8
    movs r0, #0xc0
    ands r0, r2
    cmp r0, #0
    beq lbl_080090d8
    strb r1, [r3, #4]
    movs r0, #0xfe
    b lbl_080090da
    .align 2, 0
lbl_080090d4: .4byte gButtonInput
lbl_080090d8:
    movs r0, #0xff
lbl_080090da:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusStartingWallJumpGfx
SamusStartingWallJumpGfx: @ 0x080090e0
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_080090f6
    movs r0, #0xff
    b lbl_080090fc
lbl_080090f6:
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0xfe
lbl_080090fc:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusSpaceJumpingGfx
SamusSpaceJumpingGfx: @ 0x08009104
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800912a
    ldr r0, lbl_08009120 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009124
    movs r0, #0x6b
    bl SoundPlay
    b lbl_0800912a
    .align 2, 0
lbl_08009120: .4byte gSamusPhysics
lbl_08009124:
    movs r0, #0x6b
    bl SoundPlay
lbl_0800912a:
    ldr r0, lbl_0800914c @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r1, [r0]
    adds r0, r4, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009142
    movs r0, #0
    strb r0, [r4, #0x1d]
lbl_08009142:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800914c: .4byte gSamusPhysics

    thumb_func_start SamusScrewAttackingGfx
SamusScrewAttackingGfx: @ 0x08009150
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009174 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800917c
    ldr r0, lbl_08009178 @ =0x08238ef4
    ldr r5, [r0, #8]
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800918c
    movs r0, #0x6d
    bl SoundPlay
    b lbl_0800918c
    .align 2, 0
lbl_08009174: .4byte gEquipment
lbl_08009178: .4byte 0x08238ef4
lbl_0800917c:
    ldr r0, lbl_08009200 @ =0x08238ef4
    ldr r5, [r0]
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800918c
    movs r0, #0x6c
    bl SoundPlay
lbl_0800918c:
    ldrb r0, [r4, #0x1d]
    lsls r0, r0, #4
    adds r5, r5, r0
    ldrb r1, [r5, #0xc]
    ldr r0, lbl_08009204 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080091a2
    lsls r0, r1, #0x19
    lsrs r1, r0, #0x18
lbl_080091a2:
    ldrb r0, [r4, #0x1c]
    cmp r0, r1
    blo lbl_080091ba
    movs r0, #0
    strb r0, [r4, #0x1c]
    ldrb r0, [r4, #0x1d]
    adds r0, #1
    strb r0, [r4, #0x1d]
    ldrb r0, [r5, #0x1c]
    cmp r0, #0
    bne lbl_080091ba
    strb r0, [r4, #0x1d]
lbl_080091ba:
    ldr r3, lbl_08009208 @ =gScrewSpeedAnimation
    movs r0, #1
    strb r0, [r3]
    ldrb r1, [r3, #1]
    adds r1, #1
    strb r1, [r3, #1]
    ldr r4, lbl_0800920c @ =0x08289084
    ldrb r2, [r3, #2]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    adds r0, r0, r4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r0, [r0, #8]
    cmp r1, r0
    blo lbl_080091f8
    movs r0, #0
    strb r0, [r3, #1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldrb r1, [r3, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_080091f8
    strb r0, [r3, #2]
lbl_080091f8:
    movs r0, #0xff
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009200: .4byte 0x08238ef4
lbl_08009204: .4byte gSamusPhysics
lbl_08009208: .4byte gScrewSpeedAnimation
lbl_0800920c: .4byte 0x08289084

    thumb_func_start SamusMorphing
SamusMorphing: @ 0x08009210
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_0800922c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009224
    movs r0, #0x13
    strb r0, [r2]
lbl_08009224:
    movs r0, #0xff
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800922c: .4byte gChangedInput

    thumb_func_start SamusMorphingGfx
SamusMorphingGfx: @ 0x08009230
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08009244
    movs r0, #0xff
    b lbl_08009246
lbl_08009244:
    movs r0, #0x11
lbl_08009246:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusMorphball
SamusMorphball: @ 0x0800924c
    push {r4, r5, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #4]
    adds r1, r0, #0
    cmp r1, #0x15
    bls lbl_08009260
    movs r0, #1
    strb r0, [r4, #4]
lbl_0800925c:
    movs r0, #0xfe
    b lbl_080093ac
lbl_08009260:
    cmp r1, #0x13
    bls lbl_0800926a
    adds r0, #1
    strb r0, [r4, #4]
    b lbl_080093aa
lbl_0800926a:
    ldr r0, lbl_080092ac @ =gChangedInput
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080092b8
    ldr r0, lbl_080092b0 @ =gEquipment
    ldrb r1, [r0, #0xf]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080092b8
    ldrb r0, [r4, #8]
    cmp r0, #0
    beq lbl_080092b8
    ldr r0, lbl_080092b4 @ =0x0823a554
    ldrh r1, [r0, #0x10]
    subs r1, #0x40
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080092b8
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    strh r0, [r4, #0x14]
    movs r0, #0x25
    b lbl_080093ac
    .align 2, 0
lbl_080092ac: .4byte gChangedInput
lbl_080092b0: .4byte gEquipment
lbl_080092b4: .4byte 0x0823a554
lbl_080092b8:
    adds r0, r4, #0
    bl samus_check_a_button_pressed
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_080092d6
    ldrb r1, [r4, #4]
    cmp r1, #1
    bne lbl_0800925c
    ldr r0, lbl_080092e8 @ =gEquipment
    ldrb r0, [r0, #0xf]
    ands r0, r1
    cmp r0, #0
    bne lbl_0800925c
    strb r0, [r4, #4]
lbl_080092d6:
    ldr r0, lbl_080092ec @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #0x30
    ands r1, r0
    cmp r1, #0
    beq lbl_080092f0
    strh r1, [r4, #0xe]
    movs r0, #0x12
    b lbl_080093ac
    .align 2, 0
lbl_080092e8: .4byte gEquipment
lbl_080092ec: .4byte gButtonInput
lbl_080092f0:
    ldr r0, lbl_0800932c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009386
    ldr r5, lbl_08009330 @ =0x0823a554
    movs r0, #4
    ldrsh r1, [r5, r0]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0800933c
    ldrh r1, [r5]
    ldrh r2, [r4, #0x12]
    adds r0, r1, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r0, lbl_08009334 @ =0x0000ffc0
    ands r2, r0
    subs r1, r2, r1
    adds r1, #0x40
    strh r1, [r4, #0x12]
    ldr r0, lbl_08009338 @ =gPreviousXPosition
    strh r1, [r0]
    b lbl_0800935e
    .align 2, 0
lbl_0800932c: .4byte gChangedInput
lbl_08009330: .4byte 0x0823a554
lbl_08009334: .4byte 0x0000ffc0
lbl_08009338: .4byte gPreviousXPosition
lbl_0800933c:
    cmp r0, #8
    bne lbl_0800935a
    ldrh r1, [r5, #2]
    ldrh r2, [r4, #0x12]
    adds r0, r1, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r0, lbl_08009370 @ =0x0000ffc0
    ands r2, r0
    subs r1, r2, r1
    subs r1, #1
    strh r1, [r4, #0x12]
    ldr r0, lbl_08009374 @ =gPreviousXPosition
    strh r1, [r0]
    movs r0, #0
lbl_0800935a:
    cmp r0, #0
    bne lbl_08009386
lbl_0800935e:
    ldr r0, lbl_08009378 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800937c
    movs r0, #0x78
    bl SoundPlay
    b lbl_08009382
    .align 2, 0
lbl_08009370: .4byte 0x0000ffc0
lbl_08009374: .4byte gPreviousXPosition
lbl_08009378: .4byte gSamusPhysics
lbl_0800937c:
    movs r0, #0x78
    bl SoundPlay
lbl_08009382:
    movs r0, #0x13
    b lbl_080093ac
lbl_08009386:
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    beq lbl_080093aa
    subs r0, #1
    strb r0, [r4, #0xa]
    ldr r0, lbl_080093b4 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x80
    bne lbl_080093aa
    movs r0, #0xb4
    strb r0, [r4, #8]
    movs r0, #0
    strb r0, [r4, #0xa]
    ldr r1, lbl_080093b8 @ =gScrewSpeedAnimation
    movs r0, #8
    strb r0, [r1]
lbl_080093aa:
    movs r0, #0xff
lbl_080093ac:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080093b4: .4byte gButtonInput
lbl_080093b8: .4byte gScrewSpeedAnimation

    thumb_func_start SamusRolling
SamusRolling: @ 0x080093bc
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_080093e4 @ =gChangedInput
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080093ec
    ldr r0, lbl_080093e8 @ =gEquipment
    ldrb r1, [r0, #0xf]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080093ec
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0xfe
    b lbl_08009482
    .align 2, 0
lbl_080093e4: .4byte gChangedInput
lbl_080093e8: .4byte gEquipment
lbl_080093ec:
    ldr r0, lbl_0800941c @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08009432
    ldr r0, lbl_08009420 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009432
    ldr r0, lbl_08009424 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009428
    movs r0, #0x78
    bl SoundPlay
    b lbl_0800942e
    .align 2, 0
lbl_0800941c: .4byte 0x0823a554
lbl_08009420: .4byte gChangedInput
lbl_08009424: .4byte gSamusPhysics
lbl_08009428:
    movs r0, #0x78
    bl SoundPlay
lbl_0800942e:
    movs r0, #0x13
    b lbl_08009482
lbl_08009432:
    ldr r0, lbl_08009468 @ =gButtonInput
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08009470
    ldr r2, lbl_0800946c @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x60
    movs r3, #0
    ldrsh r1, [r0, r3]
    ldrb r0, [r4, #5]
    cmp r0, #0
    beq lbl_08009456
    movs r1, #0xa0
    movs r0, #6
    strb r0, [r4, #8]
lbl_08009456:
    adds r0, r2, #0
    adds r0, #0x5e
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r2, r4, #0
    bl sub_08008278
    movs r0, #0xff
    b lbl_08009482
    .align 2, 0
lbl_08009468: .4byte gButtonInput
lbl_0800946c: .4byte gSamusPhysics
lbl_08009470:
    movs r0, #0x30
    eors r0, r1
    ands r0, r2
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_08009480
    movs r0, #1
    strb r0, [r4, #3]
lbl_08009480:
    movs r0, #0x11
lbl_08009482:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusRollingGfx
SamusRollingGfx: @ 0x08009488
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_080094a0
    movs r0, #0
    strb r0, [r4, #0x1d]
    b lbl_080094b8
lbl_080094a0:
    cmp r0, #1
    bne lbl_080094b8
    ldrb r0, [r4, #0x1d]
    cmp r0, #1
    beq lbl_080094ae
    cmp r0, #5
    bne lbl_080094b8
lbl_080094ae:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #7
    bl samus_apply_environment_effects
lbl_080094b8:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusUnmorphing
SamusUnmorphing: @ 0x080094c0
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_080094ec @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080094fc
    ldr r0, lbl_080094f0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080094f4
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0xfe
    b lbl_08009502
    .align 2, 0
lbl_080094ec: .4byte 0x0823a554
lbl_080094f0: .4byte gChangedInput
lbl_080094f4:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08009500
lbl_080094fc:
    movs r0, #0x10
    strb r0, [r4]
lbl_08009500:
    movs r0, #0xff
lbl_08009502:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusUnmorphingGfx
SamusUnmorphingGfx: @ 0x08009508
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800951e
    movs r0, #0xff
    b lbl_08009524
lbl_0800951e:
    movs r0, #0xf
    strb r0, [r4, #9]
    movs r0, #4
lbl_08009524:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusMorphballMidAir
SamusMorphballMidAir: @ 0x0800952c
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009560 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800957a
    ldr r0, lbl_08009564 @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800957a
    ldr r0, lbl_08009568 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0800956c
    movs r0, #0x78
    bl SoundPlay
    b lbl_08009572
    .align 2, 0
lbl_08009560: .4byte gChangedInput
lbl_08009564: .4byte 0x0823a554
lbl_08009568: .4byte gSamusPhysics
lbl_0800956c:
    movs r0, #0x78
    bl SoundPlay
lbl_08009572:
    movs r0, #0xf
    strb r0, [r4, #9]
    movs r0, #8
    b lbl_080095fc
lbl_0800957a:
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_0800959c
    ldr r0, lbl_08009598 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_080095a8
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    ble lbl_080095a8
    strh r1, [r4, #0x18]
    b lbl_080095a8
    .align 2, 0
lbl_08009598: .4byte gButtonInput
lbl_0800959c:
    movs r1, #0x18
    ldrsh r0, [r4, r1]
    cmp r0, #6
    bgt lbl_080095a8
    movs r0, #0
    strb r0, [r4, #4]
lbl_080095a8:
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    blt lbl_080095b8
    movs r1, #0x16
    ldrsh r0, [r4, r1]
    cmp r0, #0
    bne lbl_080095c6
lbl_080095b8:
    ldr r0, lbl_080095e0 @ =gButtonInput
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r3, r2, #0
    ands r3, r1
    cmp r3, #0
    beq lbl_080095e8
lbl_080095c6:
    ldr r1, lbl_080095e4 @ =gSamusPhysics
    adds r0, r1, #0
    adds r0, #0x68
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r1, #0x6c
    movs r2, #0
    ldrsh r1, [r1, r2]
    adds r2, r4, #0
    bl sub_08008278
    b lbl_080095fa
    .align 2, 0
lbl_080095e0: .4byte gButtonInput
lbl_080095e4: .4byte gSamusPhysics
lbl_080095e8:
    movs r0, #0x30
    eors r1, r0
    adds r0, r1, #0
    ands r0, r2
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_080095f8
    strh r1, [r4, #0xe]
lbl_080095f8:
    strh r3, [r4, #0x16]
lbl_080095fa:
    movs r0, #0xff
lbl_080095fc:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusHangingOnLedge
SamusHangingOnLedge: @ 0x08009604
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldr r0, lbl_08009618 @ =gScreenShakeX
    ldrb r0, [r0]
    cmp r0, #0x1d
    bls lbl_0800961c
    movs r0, #0
lbl_08009612:
    strb r0, [r5, #4]
lbl_08009614:
    movs r0, #0xfe
    b lbl_0800976a
    .align 2, 0
lbl_08009618: .4byte gScreenShakeX
lbl_0800961c:
    ldrh r1, [r5, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800962c
    ldrh r0, [r5, #0x12]
    adds r0, #0x20
    b lbl_08009630
lbl_0800962c:
    ldrh r0, [r5, #0x12]
    subs r0, #0x20
lbl_08009630:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    bl ClipdataProcessForSamus
    adds r6, r0, #0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r6, r4
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl ClipdataProcessForSamus
    adds r3, r0, #0
    ands r3, r4
    ldr r0, lbl_08009680 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080096c6
    ldr r0, lbl_08009684 @ =gButtonInput
    ldrh r1, [r0]
    ldrh r2, [r5, #0xe]
    ands r1, r2
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_0800969c
    cmp r6, #0
    bne lbl_08009688
    cmp r3, #0
    bne lbl_08009688
    movs r0, #0x1a
    b lbl_0800976a
    .align 2, 0
lbl_08009680: .4byte gChangedInput
lbl_08009684: .4byte gButtonInput
lbl_08009688:
    ldr r0, lbl_08009698 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800969c
    movs r0, #0x1c
    b lbl_0800976a
    .align 2, 0
lbl_08009698: .4byte gEquipment
lbl_0800969c:
    movs r0, #0x30
    eors r0, r2
    ldrh r3, [r4]
    adds r1, r0, #0
    ands r1, r3
    cmp r1, #0
    beq lbl_080096b0
    strh r0, [r5, #0xe]
    movs r0, #1
    b lbl_08009612
lbl_080096b0:
    movs r0, #0x80
    ands r0, r3
    cmp r0, #0
    beq lbl_080096bc
    strb r1, [r5, #4]
    b lbl_08009614
lbl_080096bc:
    movs r0, #2
    strb r0, [r5, #4]
    movs r0, #0x90
    strh r0, [r5, #0x18]
    b lbl_08009614
lbl_080096c6:
    ldr r0, lbl_080096e8 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080096f8
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xe]
    ldr r0, lbl_080096ec @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080096f0
    movs r0, #4
    b lbl_080096f2
    .align 2, 0
lbl_080096e8: .4byte gSamusPhysics
lbl_080096ec: .4byte gButtonInput
lbl_080096f0:
    movs r0, #3
lbl_080096f2:
    strb r0, [r5, #2]
    movs r0, #0x19
    b lbl_0800976a
lbl_080096f8:
    ldr r0, lbl_08009720 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08009734
    ldr r0, lbl_08009724 @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0
    beq lbl_08009734
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xe]
    ldr r0, lbl_08009728 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800972c
    movs r0, #4
    b lbl_0800972e
    .align 2, 0
lbl_08009720: .4byte gEquipment
lbl_08009724: .4byte gSamusWeaponInfo
lbl_08009728: .4byte gButtonInput
lbl_0800972c:
    movs r0, #3
lbl_0800972e:
    strb r0, [r5, #2]
    movs r0, #0x18
    b lbl_0800976a
lbl_08009734:
    ldr r0, lbl_08009760 @ =gButtonInput
    ldr r1, lbl_08009764 @ =gButtonAssignments
    ldrh r3, [r0]
    ldrh r0, [r1, #2]
    ands r0, r3
    ldrh r2, [r5, #0xe]
    cmp r0, #0
    bne lbl_08009756
    movs r0, #0xc0
    ands r0, r3
    cmp r0, #0
    bne lbl_08009756
    movs r0, #0x30
    eors r0, r2
    ands r0, r3
    cmp r0, #0
    beq lbl_08009768
lbl_08009756:
    movs r0, #0x30
    eors r0, r2
    strh r0, [r5, #0xe]
    movs r0, #0x16
    b lbl_0800976a
    .align 2, 0
lbl_08009760: .4byte gButtonInput
lbl_08009764: .4byte gButtonAssignments
lbl_08009768:
    movs r0, #0xff
lbl_0800976a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SamusHangingOnLedgeGfx
SamusHangingOnLedgeGfx: @ 0x08009770
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009794 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r1, [r0]
    adds r0, r4, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800978c
    movs r0, #0
    strb r0, [r4, #0x1d]
lbl_0800978c:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009794: .4byte gSamusPhysics

    thumb_func_start SamusTurningToAimWhileHanging
SamusTurningToAimWhileHanging: @ 0x08009798
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldr r0, lbl_080097a8 @ =gScreenShakeX
    ldrb r0, [r0]
    cmp r0, #0x1d
    bls lbl_080097ac
    movs r0, #0
    b lbl_0800983e
    .align 2, 0
lbl_080097a8: .4byte gScreenShakeX
lbl_080097ac:
    ldrh r1, [r5, #0xe]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_080097bc
    ldrh r0, [r5, #0x12]
    adds r0, #0x20
    b lbl_080097c0
lbl_080097bc:
    ldrh r0, [r5, #0x12]
    subs r0, #0x20
lbl_080097c0:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    bl ClipdataProcessForSamus
    adds r6, r0, #0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r6, r4
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl ClipdataProcessForSamus
    adds r3, r0, #0
    ands r3, r4
    ldr r0, lbl_08009818 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009844
    ldr r1, lbl_0800981c @ =gButtonInput
    ldrh r2, [r5, #0xe]
    movs r0, #0x30
    adds r4, r2, #0
    eors r4, r0
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800983c
    cmp r6, #0
    bne lbl_08009820
    cmp r3, #0
    bne lbl_08009820
    strh r4, [r5, #0xe]
    movs r0, #0x1a
    b lbl_0800985a
    .align 2, 0
lbl_08009818: .4byte gChangedInput
lbl_0800981c: .4byte gButtonInput
lbl_08009820:
    ldr r0, lbl_08009838 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800983c
    movs r0, #0x30
    eors r0, r2
    strh r0, [r5, #0xe]
    movs r0, #0x1c
    b lbl_0800985a
    .align 2, 0
lbl_08009838: .4byte gEquipment
lbl_0800983c:
    movs r0, #1
lbl_0800983e:
    strb r0, [r5, #4]
    movs r0, #0xfe
    b lbl_0800985a
lbl_08009844:
    ldr r0, lbl_08009854 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08009858
    movs r0, #0xff
    b lbl_0800985a
    .align 2, 0
lbl_08009854: .4byte gSamusPhysics
lbl_08009858:
    movs r0, #0x19
lbl_0800985a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SamusTurningToAimWhileHangingGfx
SamusTurningToAimWhileHangingGfx: @ 0x08009860
    push {lr}
    ldr r1, lbl_08009878 @ =gSamusPhysics
    adds r1, #0x5b
    ldrb r1, [r1]
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800987c
    movs r0, #0xff
    b lbl_0800987e
    .align 2, 0
lbl_08009878: .4byte gSamusPhysics
lbl_0800987c:
    movs r0, #0x18
lbl_0800987e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusHidingArmCannonWhileHangingGfx
SamusHidingArmCannonWhileHangingGfx: @ 0x08009884
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_080098a0 @ =gSamusPhysics
    adds r0, #0x5b
    ldrb r1, [r0]
    adds r0, r4, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_080098a4
    movs r0, #0xff
    b lbl_080098ae
    .align 2, 0
lbl_080098a0: .4byte gSamusPhysics
lbl_080098a4:
    ldrh r0, [r4, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r4, #0xe]
    movs r0, #0x15
lbl_080098ae:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusAimingWhileHanging
SamusAimingWhileHanging: @ 0x080098b4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    ldr r0, lbl_080098c8 @ =gScreenShakeX
    ldrb r0, [r0]
    cmp r0, #0x1d
    bls lbl_080098cc
    movs r0, #0
    b lbl_08009982
    .align 2, 0
lbl_080098c8: .4byte gScreenShakeX
lbl_080098cc:
    adds r0, r5, #0
    bl samus_update_aim
    ldr r0, lbl_080098e0 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080098e4
    movs r0, #0x19
    b lbl_08009a34
    .align 2, 0
lbl_080098e0: .4byte gSamusPhysics
lbl_080098e4:
    ldrh r1, [r5, #0xe]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_080098f4
    ldrh r0, [r5, #0x12]
    adds r0, #0x20
    b lbl_080098f8
lbl_080098f4:
    ldrh r0, [r5, #0x12]
    subs r0, #0x20
lbl_080098f8:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    bl ClipdataProcessForSamus
    mov r8, r0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r0, r4
    mov r8, r0
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl ClipdataProcessForSamus
    adds r7, r0, #0
    ands r7, r4
    ldr r0, lbl_08009958 @ =gChangedInput
    ldrh r4, [r0]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq lbl_08009988
    ldr r3, lbl_0800995c @ =gButtonInput
    ldrh r2, [r5, #0xe]
    movs r0, #0x30
    adds r6, r2, #0
    eors r6, r0
    ldrh r1, [r3]
    adds r0, r6, #0
    ands r0, r1
    adds r4, r2, #0
    adds r2, r3, #0
    cmp r0, #0
    beq lbl_08009978
    mov r0, r8
    cmp r0, #0
    bne lbl_08009960
    cmp r7, #0
    bne lbl_08009960
    strh r6, [r5, #0xe]
    movs r0, #0x1a
    b lbl_08009a34
    .align 2, 0
lbl_08009958: .4byte gChangedInput
lbl_0800995c: .4byte gButtonInput
lbl_08009960:
    ldr r0, lbl_08009974 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009978
    movs r0, #0x30
    eors r0, r4
    b lbl_08009a22
    .align 2, 0
lbl_08009974: .4byte gEquipment
lbl_08009978:
    ldrh r0, [r2]
    ands r0, r4
    cmp r0, #0
    beq lbl_08009982
    movs r0, #1
lbl_08009982:
    strb r0, [r5, #4]
    movs r0, #0xfe
    b lbl_08009a34
lbl_08009988:
    movs r6, #0
    ldr r2, lbl_080099bc @ =gButtonInput
    ldr r0, lbl_080099c0 @ =gButtonAssignments
    ldrh r1, [r2]
    ldrh r0, [r0, #2]
    ands r0, r1
    cmp r0, #0
    bne lbl_080099e4
    ldrh r1, [r5, #0xe]
    movs r0, #0x30
    eors r0, r1
    ands r0, r4
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_080099d0
    ldr r0, lbl_080099c4 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_080099b6
    ldr r0, lbl_080099c8 @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0
    bne lbl_080099cc
lbl_080099b6:
    movs r0, #0x17
    b lbl_08009a34
    .align 2, 0
lbl_080099bc: .4byte gButtonInput
lbl_080099c0: .4byte gButtonAssignments
lbl_080099c4: .4byte gEquipment
lbl_080099c8: .4byte gSamusWeaponInfo
lbl_080099cc:
    movs r0, #3
    strb r0, [r5, #2]
lbl_080099d0:
    ldrh r2, [r2]
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_080099e4
    adds r0, r2, #0
    ands r0, r4
    cmp r0, #0
    bne lbl_080099e4
    adds r6, #1
lbl_080099e4:
    cmp r6, #0
    beq lbl_08009a30
    ldrb r0, [r5, #0xa]
    adds r1, r0, #1
    strb r1, [r5, #0xa]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #9
    bls lbl_08009a32
    mov r0, r8
    cmp r0, #0
    bne lbl_08009a0c
    cmp r7, #0
    bne lbl_08009a0c
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xe]
    movs r0, #0x1a
    b lbl_08009a34
lbl_08009a0c:
    ldr r0, lbl_08009a28 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08009a2c
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
lbl_08009a22:
    strh r0, [r5, #0xe]
    movs r0, #0x1c
    b lbl_08009a34
    .align 2, 0
lbl_08009a28: .4byte gEquipment
lbl_08009a2c:
    strb r0, [r5, #0xa]
    b lbl_08009a32
lbl_08009a30:
    strb r6, [r5, #0xa]
lbl_08009a32:
    movs r0, #0xff
lbl_08009a34:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusPullingSelfUp
SamusPullingSelfUp: @ 0x08009a40
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08009a64 @ =0x0823a5b4
    ldrb r1, [r2, #0x1d]
    lsls r1, r1, #1
    adds r1, r1, r0
    ldrh r1, [r1]
    ldrb r0, [r2, #0xa]
    cmp r0, #0
    beq lbl_08009a56
    lsrs r1, r1, #1
lbl_08009a56:
    ldrh r0, [r2, #0x14]
    subs r0, r0, r1
    strh r0, [r2, #0x14]
    movs r0, #0xff
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009a64: .4byte 0x0823a5b4

    thumb_func_start SamusPullingSelfUpGfx
SamusPullingSelfUpGfx: @ 0x08009a68
    push {r4, lr}
    adds r4, r0, #0
    ldrb r1, [r4, #0xa]
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08009a7e
    movs r0, #0xff
    b lbl_08009a8a
lbl_08009a7e:
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_08009a90 @ =0x0000ffc0
    ands r0, r1
    subs r0, #1
    strh r0, [r4, #0x14]
    movs r0, #0x1b
lbl_08009a8a:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009a90: .4byte 0x0000ffc0

    thumb_func_start SamusPullingSelfForward
SamusPullingSelfForward: @ 0x08009a94
    push {lr}
    adds r2, r0, #0
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08009aa8
    ldrh r0, [r2, #0x12]
    adds r0, #4
    b lbl_08009aac
lbl_08009aa8:
    ldrh r0, [r2, #0x12]
    subs r0, #4
lbl_08009aac:
    strh r0, [r2, #0x12]
    movs r0, #0xff
    pop {r1}
    bx r1

    thumb_func_start SamusPullingSelfForwardGfx
SamusPullingSelfForwardGfx: @ 0x08009ab4
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009ad8
    ldr r0, lbl_08009ad0 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08009ad4
    movs r0, #0x3b
    b lbl_08009ada
    .align 2, 0
lbl_08009ad0: .4byte gEquipment
lbl_08009ad4:
    movs r0, #1
    b lbl_08009ada
lbl_08009ad8:
    movs r0, #0xff
lbl_08009ada:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusPullingSelfIntoMorphballTunnelGfx
SamusPullingSelfIntoMorphballTunnelGfx: @ 0x08009ae0
    push {r4, lr}
    adds r4, r0, #0
    ldrb r1, [r4, #0xa]
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009b20
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08009b02
    ldrh r0, [r4, #0x12]
    adds r0, #6
    b lbl_08009b06
lbl_08009b02:
    ldrh r0, [r4, #0x12]
    subs r0, #6
lbl_08009b06:
    strh r0, [r4, #0x12]
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_08009b1c @ =0x0000ffc0
    ands r0, r1
    subs r0, #1
    strh r0, [r4, #0x14]
    movs r0, #0x77
    bl SoundPlay
    movs r0, #0x11
    b lbl_08009b22
    .align 2, 0
lbl_08009b1c: .4byte 0x0000ffc0
lbl_08009b20:
    movs r0, #0xff
lbl_08009b22:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusUsingAnElevator
SamusUsingAnElevator: @ 0x08009b28
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x1d]
    cmp r0, #0
    bne lbl_08009ba6
    movs r6, #0
    ldrh r0, [r4, #0x14]
    ldrh r1, [r4, #0x18]
    subs r0, r0, r1
    strh r0, [r4, #0x14]
    ldrh r0, [r4, #0x14]
    ldrh r1, [r4, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    asrs r5, r0, #0x10
    ldrh r1, [r4, #0x10]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009b74
    ldr r0, lbl_08009b70 @ =gPreviousYPosition
    ldrh r0, [r0]
    ldrh r1, [r4, #0x12]
    bl ClipdataCheckCurrentAffectingAtPosition
    asrs r0, r0, #0x10
    cmp r5, #1
    beq lbl_08009b8c
    cmp r0, #1
    bne lbl_08009b8c
    ldrh r1, [r4, #0x14]
    movs r0, #0x3f
    orrs r0, r1
    strh r0, [r4, #0x14]
    b lbl_08009b90
    .align 2, 0
lbl_08009b70: .4byte gPreviousYPosition
lbl_08009b74:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08009b8c
    cmp r5, #2
    bne lbl_08009b8c
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_08009bb0 @ =0x0000ffc0
    ands r0, r1
    subs r0, #1
    strh r0, [r4, #0x14]
    movs r6, #1
lbl_08009b8c:
    cmp r6, #0
    beq lbl_08009ba6
lbl_08009b90:
    ldrb r0, [r4, #0x1d]
    adds r0, #1
    movs r1, #0
    strb r0, [r4, #0x1d]
    strb r1, [r4, #0x1c]
    strh r1, [r4, #0x18]
    movs r0, #0x87
    lsls r0, r0, #1
    movs r1, #0xa
    bl SoundFade
lbl_08009ba6:
    movs r0, #0xff
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009bb0: .4byte 0x0000ffc0

    thumb_func_start SamusUsingAnElevatorGfx
SamusUsingAnElevatorGfx: @ 0x08009bb4
    push {r4, lr}
    adds r2, r0, #0
    ldrh r1, [r2, #0x10]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08009bcc
    ldr r0, lbl_08009bc8 @ =0x08238f54
    ldr r1, [r0]
    b lbl_08009bd0
    .align 2, 0
lbl_08009bc8: .4byte 0x08238f54
lbl_08009bcc:
    ldr r0, lbl_08009bf8 @ =0x08238f54
    ldr r1, [r0, #8]
lbl_08009bd0:
    ldrb r3, [r2, #0x1d]
    lsls r0, r3, #4
    adds r1, r1, r0
    ldrb r0, [r2, #0x1c]
    ldrb r4, [r1, #0xc]
    cmp r0, r4
    blo lbl_08009bfc
    cmp r3, #0
    beq lbl_08009bee
    movs r0, #0
    strb r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1d]
    adds r0, #1
    strb r0, [r2, #0x1d]
    adds r1, #0x10
lbl_08009bee:
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    bne lbl_08009bfc
    movs r0, #0x1e
    b lbl_08009bfe
    .align 2, 0
lbl_08009bf8: .4byte 0x08238f54
lbl_08009bfc:
    movs r0, #0xff
lbl_08009bfe:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusFacingTheForeground
SamusFacingTheForeground: @ 0x08009c04
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08009c20 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #0x30
    ands r1, r0
    cmp r1, #0
    beq lbl_08009c24
    ldrh r0, [r2, #0xc]
    cmp r0, #0
    bne lbl_08009c24
    strh r1, [r2, #0xe]
    movs r0, #0x1f
    b lbl_08009c26
    .align 2, 0
lbl_08009c20: .4byte gButtonInput
lbl_08009c24:
    movs r0, #0xff
lbl_08009c26:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningFromFacningForegroundGfx
SamusTurningFromFacningForegroundGfx: @ 0x08009c2c
    push {lr}
    adds r1, r0, #0
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bls lbl_08009c60
    ldrh r0, [r1, #0x10]
    cmp r0, #0
    beq lbl_08009c40
    movs r0, #0x1d
    b lbl_08009c62
lbl_08009c40:
    ldrb r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_08009c4a
    movs r0, #0x2c
    b lbl_08009c62
lbl_08009c4a:
    ldr r0, lbl_08009c58 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08009c5c
    movs r0, #0x3b
    b lbl_08009c62
    .align 2, 0
lbl_08009c58: .4byte gEquipment
lbl_08009c5c:
    movs r0, #1
    b lbl_08009c62
lbl_08009c60:
    movs r0, #0xff
lbl_08009c62:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusDelayBeforeShinesparkingGfx
SamusDelayBeforeShinesparkingGfx: @ 0x08009c68
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009c98
    ldr r2, lbl_08009c94 @ =gButtonInput
    ldrh r0, [r4, #0xe]
    movs r1, #0x30
    eors r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08009c8e
    movs r0, #1
    strb r0, [r4, #3]
lbl_08009c8e:
    movs r0, #0x22
    b lbl_08009c9a
    .align 2, 0
lbl_08009c94: .4byte gButtonInput
lbl_08009c98:
    movs r0, #0xff
lbl_08009c9a:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusShinesparking
SamusShinesparking: @ 0x08009ca0
    push {r4, r5, r6, lr}
    sub sp, #0xc
    adds r4, r0, #0
    movs r1, #0
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08009cb8
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    bne lbl_08009cce
    b lbl_08009cd4
lbl_08009cb8:
    cmp r0, #1
    beq lbl_08009cc4
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_08009cd4
lbl_08009cc4:
    movs r2, #0x16
    ldrsh r0, [r4, r2]
    cmp r0, #0
    bne lbl_08009cce
    movs r1, #1
lbl_08009cce:
    movs r0, #0
    cmp r0, #0
    beq lbl_08009cde
lbl_08009cd4:
    movs r0, #0x1e
    movs r1, #1
    bl ScreenShakeStartVertical
    b lbl_08009d3c
lbl_08009cde:
    cmp r1, #0
    beq lbl_08009d46
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    movs r1, #0x1c
    rsbs r1, r1, #0
    cmp r0, #0
    beq lbl_08009cf2
    movs r1, #0x1c
lbl_08009cf2:
    ldrh r0, [r4, #0x12]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r6, sp
    adds r6, #6
    add r5, sp, #8
    str r5, [sp]
    add r2, sp, #4
    adds r3, r6, #0
    bl sub_08005474
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08009d34
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_08009d34
    strh r0, [r4, #0x1a]
    ldrh r0, [r6]
    strh r0, [r4, #0x14]
    ldr r1, lbl_08009d30 @ =gUnk_03004fc9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0xfd
    b lbl_08009d48
    .align 2, 0
lbl_08009d30: .4byte gUnk_03004fc9
lbl_08009d34:
    movs r0, #0x1e
    movs r1, #1
    bl ScreenShakeStartHorizontal
lbl_08009d3c:
    ldrb r0, [r4]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b lbl_08009d48
lbl_08009d46:
    movs r0, #0xff
lbl_08009d48:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SamusShinesparkingGfx
SamusShinesparkingGfx: @ 0x08009d50
    push {r4, lr}
    adds r1, r0, #0
    ldrb r0, [r1, #4]
    cmp r0, #0
    bne lbl_08009d68
    ldr r0, lbl_08009d64 @ =0x08238f64
    ldr r2, [r0]
    movs r3, #1
    b lbl_08009d6e
    .align 2, 0
lbl_08009d64: .4byte 0x08238f64
lbl_08009d68:
    ldr r0, lbl_08009dd0 @ =0x08238f64
    ldr r2, [r0, #8]
    movs r3, #2
lbl_08009d6e:
    ldrb r0, [r1, #0x1d]
    lsls r0, r0, #4
    adds r2, r2, r0
    ldrb r0, [r1, #0x1c]
    ldrb r4, [r2, #0xc]
    cmp r0, r4
    blo lbl_08009d8e
    movs r0, #0
    strb r0, [r1, #0x1c]
    ldrb r0, [r1, #0x1d]
    adds r0, #1
    strb r0, [r1, #0x1d]
    ldrb r0, [r2, #0x1c]
    cmp r0, #0
    bne lbl_08009d8e
    strb r3, [r1, #0x1d]
lbl_08009d8e:
    ldr r3, lbl_08009dd4 @ =gScrewSpeedAnimation
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    ldr r4, lbl_08009dd8 @ =0x08288f94
    ldrb r2, [r3, #2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r1, #8]
    cmp r0, r1
    blo lbl_08009dc8
    movs r0, #0
    strb r0, [r3, #1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldrb r1, [r3, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_08009dc8
    strb r0, [r3, #2]
lbl_08009dc8:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009dd0: .4byte 0x08238f64
lbl_08009dd4: .4byte gScrewSpeedAnimation
lbl_08009dd8: .4byte 0x08288f94

    thumb_func_start SamusShinesparkCollisionGfx
SamusShinesparkCollisionGfx: @ 0x08009ddc
    push {lr}
    ldrb r0, [r0, #0x1c]
    cmp r0, #0x10
    bhi lbl_08009de8
    movs r0, #0xff
    b lbl_08009dea
lbl_08009de8:
    movs r0, #0x24
lbl_08009dea:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusDelayAfterShinesparkingGfx
SamusDelayAfterShinesparkingGfx: @ 0x08009df0
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08009e04
    movs r0, #0xff
    b lbl_08009e06
lbl_08009e04:
    movs r0, #0xfe
lbl_08009e06:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusDelayBeforeBallsparking
SamusDelayBeforeBallsparking: @ 0x08009e0c
    push {r4, lr}
    adds r4, r0, #0
    ldr r2, lbl_08009e30 @ =gButtonInput
    ldrh r1, [r4, #0xe]
    movs r0, #0x30
    adds r3, r1, #0
    eors r3, r0
    ldrh r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08009e26
    strh r3, [r4, #0xe]
lbl_08009e26:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009e30: .4byte gButtonInput

    thumb_func_start SamusDelayBeforeBallsparkingGfx
SamusDelayBeforeBallsparkingGfx: @ 0x08009e34
    push {r4, r5, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0xa]
    cmp r0, #0x3b
    bls lbl_08009e42
    movs r0, #0x26
    b lbl_08009eac
lbl_08009e42:
    cmp r0, #0
    bne lbl_08009e52
    ldrb r0, [r4, #4]
    cmp r0, #0xf0
    beq lbl_08009e52
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    strh r0, [r4, #0x14]
lbl_08009e52:
    ldrb r0, [r4, #0xa]
    adds r0, #1
    movs r5, #0
    strb r0, [r4, #0xa]
    adds r0, r4, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009e6c
    strb r5, [r4, #0x1d]
lbl_08009e6c:
    ldrb r0, [r4, #4]
    cmp r0, #0xf0
    beq lbl_08009eaa
    ldr r3, lbl_08009eb4 @ =gScrewSpeedAnimation
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    ldr r4, lbl_08009eb8 @ =0x08288f28
    ldrb r2, [r3, #2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r1, #8]
    cmp r0, r1
    blo lbl_08009eaa
    strb r5, [r3, #1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldrb r1, [r3, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_08009eaa
    strb r0, [r3, #2]
lbl_08009eaa:
    movs r0, #0xff
lbl_08009eac:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009eb4: .4byte gScrewSpeedAnimation
lbl_08009eb8: .4byte 0x08288f28

    thumb_func_start SamusBallsparkingGfx
SamusBallsparkingGfx: @ 0x08009ebc
    push {r4, lr}
    adds r2, r0, #0
    ldr r1, lbl_08009f2c @ =0x08238b74
    ldrb r0, [r2]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r1, [r0]
    ldrb r0, [r2, #0x1d]
    lsls r0, r0, #4
    adds r1, r1, r0
    ldrb r0, [r2, #0x1c]
    ldrb r3, [r1, #0xc]
    cmp r0, r3
    blo lbl_08009eea
    movs r0, #0
    strb r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1d]
    adds r0, #1
    strb r0, [r2, #0x1d]
    ldrb r0, [r1, #0x1c]
    cmp r0, #0
    bne lbl_08009eea
    strb r0, [r2, #0x1d]
lbl_08009eea:
    ldr r3, lbl_08009f30 @ =gScrewSpeedAnimation
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    ldr r4, lbl_08009f34 @ =0x08288f94
    ldrb r2, [r3, #2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r1, #8]
    cmp r0, r1
    blo lbl_08009f24
    movs r0, #0
    strb r0, [r3, #1]
    ldrb r0, [r3, #2]
    adds r0, #1
    strb r0, [r3, #2]
    ldrb r1, [r3, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_08009f24
    strb r0, [r3, #2]
lbl_08009f24:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009f2c: .4byte 0x08238b74
lbl_08009f30: .4byte gScrewSpeedAnimation
lbl_08009f34: .4byte 0x08288f94

    thumb_func_start SamusBallsparkCollisionGfx
SamusBallsparkCollisionGfx: @ 0x08009f38
    push {lr}
    ldrb r0, [r0, #0x1c]
    cmp r0, #0x10
    bhi lbl_08009f44
    movs r0, #0xff
    b lbl_08009f46
lbl_08009f44:
    movs r0, #0xfe
lbl_08009f46:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusOnZipline
SamusOnZipline: @ 0x08009f4c
    push {lr}
    adds r3, r0, #0
    ldr r0, lbl_08009f60 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009f64
    movs r0, #0xfe
    b lbl_08009fa0
    .align 2, 0
lbl_08009f60: .4byte gChangedInput
lbl_08009f64:
    ldr r0, lbl_08009f74 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009f78
    movs r0, #0x29
    b lbl_08009fa0
    .align 2, 0
lbl_08009f74: .4byte gSamusPhysics
lbl_08009f78:
    ldrb r0, [r3]
    cmp r0, #0x28
    bne lbl_08009f9e
    ldr r2, lbl_08009f94 @ =gButtonInput
    ldrh r0, [r3, #0xe]
    movs r1, #0x30
    eors r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08009f98
    movs r0, #0x2a
    b lbl_08009fa0
    .align 2, 0
lbl_08009f94: .4byte gButtonInput
lbl_08009f98:
    adds r0, r3, #0
    bl samus_update_aim
lbl_08009f9e:
    movs r0, #0xff
lbl_08009fa0:
    pop {r1}
    bx r1

    thumb_func_start SamusShootingOnZiplineGfx
SamusShootingOnZiplineGfx: @ 0x08009fa4
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_08009fb8
    movs r0, #0xff
    b lbl_08009fba
lbl_08009fb8:
    movs r0, #0x28
lbl_08009fba:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusMorphballOnZipline
SamusMorphballOnZipline: @ 0x08009fc0
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08009fd4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009fd8
    movs r0, #0xfe
    b lbl_08009fe8
    .align 2, 0
lbl_08009fd4: .4byte gChangedInput
lbl_08009fd8:
    ldr r0, lbl_08009fec @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #0x30
    ands r1, r0
    cmp r1, #0
    beq lbl_08009fe6
    strh r1, [r2, #0xe]
lbl_08009fe6:
    movs r0, #0xff
lbl_08009fe8:
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009fec: .4byte gButtonInput

    thumb_func_start SamusSavingLoadingGame
SamusSavingLoadingGame: @ 0x08009ff0
    push {lr}
    adds r1, r0, #0
    ldrb r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_0800a000
    movs r0, #0
    strb r0, [r1, #0x1d]
    strb r0, [r1, #0x1c]
lbl_0800a000:
    movs r0, #0xff
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningAroundToDownloadMapDataGfxGfx
SamusTurningAroundToDownloadMapDataGfxGfx: @ 0x0800a008
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800a01c
    movs r0, #0xff
    b lbl_0800a01e
lbl_0800a01c:
    movs r0, #0x2d
lbl_0800a01e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusGettingHurt
SamusGettingHurt: @ 0x0800a024
    push {lr}
    adds r2, r0, #0
    movs r3, #0
    ldrb r0, [r2, #4]
    cmp r0, #0
    beq lbl_0800a052
    ldrh r0, [r2, #0x18]
    adds r0, #7
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xe
    bhi lbl_0800a052
    ldrh r0, [r2, #0xc]
    adds r1, r0, #1
    strh r1, [r2, #0xc]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_0800a052
    ldr r0, lbl_0800a07c @ =gSamusPhysics
    adds r0, #0x62
    strh r3, [r0]
    movs r3, #1
lbl_0800a052:
    cmp r3, #0
    bne lbl_0800a084
    ldrb r0, [r2, #0xa]
    adds r1, r0, #1
    strb r1, [r2, #0xa]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_0800a084
    movs r0, #0x18
    ldrsh r1, [r2, r0]
    movs r0, #0x10
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_0800a084
    strb r3, [r2, #4]
    ldrb r0, [r2]
    cmp r0, #0x2f
    bne lbl_0800a080
    movs r0, #8
    b lbl_0800a086
    .align 2, 0
lbl_0800a07c: .4byte gSamusPhysics
lbl_0800a080:
    movs r0, #0x14
    b lbl_0800a086
lbl_0800a084:
    movs r0, #0xff
lbl_0800a086:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusGettingHurtGfx
SamusGettingHurtGfx: @ 0x0800a08c
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800a0a4
    ldrb r0, [r4, #0x1d]
    subs r0, #1
    strb r0, [r4, #0x1d]
lbl_0800a0a4:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusGettingKnockedBack
SamusGettingKnockedBack: @ 0x0800a0ac
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #0xa]
    cmp r0, #0xc
    bls lbl_0800a0d0
    movs r0, #0x18
    ldrsh r1, [r2, r0]
    movs r0, #0x20
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_0800a0d4
    ldrb r0, [r2]
    cmp r0, #0x30
    bne lbl_0800a0cc
    movs r0, #8
    b lbl_0800a0d6
lbl_0800a0cc:
    movs r0, #0x14
    b lbl_0800a0d6
lbl_0800a0d0:
    adds r0, #1
    strb r0, [r2, #0xa]
lbl_0800a0d4:
    movs r0, #0xff
lbl_0800a0d6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusDying
SamusDying: @ 0x0800a0dc
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldrh r0, [r4, #0xc]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_0800a0f2
    adds r0, #1
    strh r0, [r4, #0xc]
    bl StopAllMusicsAndSounds
    b lbl_0800a100
lbl_0800a0f2:
    cmp r1, #1
    bne lbl_0800a100
    adds r0, #1
    strh r0, [r4, #0xc]
    movs r0, #0x83
    bl SoundPlay
lbl_0800a100:
    movs r5, #0
    movs r0, #0x40
    strb r0, [r4, #6]
    movs r0, #0x16
    ldrsh r1, [r4, r0]
    cmp r1, #0
    bne lbl_0800a116
    movs r2, #0x18
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_0800a172
lbl_0800a116:
    ldr r0, lbl_0800a138 @ =gBg1XPosition
    ldrh r0, [r0]
    movs r3, #0xf0
    lsls r3, r3, #1
    adds r2, r0, r3
    ldr r0, lbl_0800a13c @ =gBg1YPosition
    ldrh r0, [r0]
    movs r6, #0xc8
    lsls r6, r6, #1
    adds r3, r0, r6
    cmp r1, #0
    ble lbl_0800a140
    ldrh r0, [r4, #0x12]
    cmp r0, r2
    blo lbl_0800a14c
    b lbl_0800a14a
    .align 2, 0
lbl_0800a138: .4byte gBg1XPosition
lbl_0800a13c: .4byte gBg1YPosition
lbl_0800a140:
    cmp r1, #0
    bge lbl_0800a14c
    ldrh r0, [r4, #0x12]
    cmp r0, r2
    bhi lbl_0800a14c
lbl_0800a14a:
    strh r5, [r4, #0x16]
lbl_0800a14c:
    movs r1, #0x18
    ldrsh r0, [r4, r1]
    cmp r0, #0
    ble lbl_0800a15c
    ldrh r0, [r4, #0x14]
    cmp r0, r3
    blo lbl_0800a16a
    b lbl_0800a166
lbl_0800a15c:
    cmp r0, #0
    bge lbl_0800a16a
    ldrh r0, [r4, #0x14]
    cmp r0, r3
    bhi lbl_0800a16a
lbl_0800a166:
    movs r0, #0
    strh r0, [r4, #0x18]
lbl_0800a16a:
    ldrh r0, [r4, #0x18]
    ldrh r2, [r4, #0x14]
    adds r0, r0, r2
    strh r0, [r4, #0x14]
lbl_0800a172:
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x17
    bls lbl_0800a1d8
    ldrb r0, [r4, #0xa]
    adds r1, r0, #1
    strb r1, [r4, #0xa]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x24
    beq lbl_0800a1c0
    cmp r0, #0x24
    bgt lbl_0800a1a2
    cmp r0, #0xc
    beq lbl_0800a1c0
    cmp r0, #0xc
    bgt lbl_0800a198
    cmp r0, #4
    beq lbl_0800a1ba
    b lbl_0800a1d8
lbl_0800a198:
    cmp r0, #0x14
    beq lbl_0800a1c0
    cmp r0, #0x1c
    beq lbl_0800a1c0
    b lbl_0800a1d8
lbl_0800a1a2:
    cmp r0, #0x34
    beq lbl_0800a1c0
    cmp r0, #0x34
    bgt lbl_0800a1b0
    cmp r0, #0x2c
    beq lbl_0800a1c0
    b lbl_0800a1d8
lbl_0800a1b0:
    cmp r0, #0x50
    beq lbl_0800a1c0
    cmp r0, #0x78
    beq lbl_0800a1cc
    b lbl_0800a1d8
lbl_0800a1ba:
    ldr r1, lbl_0800a1c8 @ =gMonochromeBgFading
    movs r0, #2
    strb r0, [r1]
lbl_0800a1c0:
    ldrb r0, [r4, #7]
    adds r0, #1
    strb r0, [r4, #7]
    b lbl_0800a1d8
    .align 2, 0
lbl_0800a1c8: .4byte gMonochromeBgFading
lbl_0800a1cc:
    ldr r1, lbl_0800a1e0 @ =gMainGameMode
    movs r0, #6
    strh r0, [r1]
    ldr r1, lbl_0800a1e4 @ =gGameModeSub1
    movs r0, #0
    strh r0, [r1]
lbl_0800a1d8:
    movs r0, #0xff
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800a1e0: .4byte gMainGameMode
lbl_0800a1e4: .4byte gGameModeSub1

    thumb_func_start SamusCrouchingToCrawlGfx
SamusCrouchingToCrawlGfx: @ 0x0800a1e8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800a214
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a20a
    ldrh r0, [r4, #0x12]
    adds r0, #4
    b lbl_0800a20e
lbl_0800a20a:
    ldrh r0, [r4, #0x12]
    subs r0, #4
lbl_0800a20e:
    strh r0, [r4, #0x12]
    movs r0, #0x36
    b lbl_0800a216
lbl_0800a214:
    movs r0, #0xff
lbl_0800a216:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusCrawlingStopped
SamusCrawlingStopped: @ 0x0800a21c
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0
    strh r0, [r4, #0x16]
    ldr r0, lbl_0800a23c @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800a240
    movs r0, #0x38
    b lbl_0800a27c
    .align 2, 0
lbl_0800a23c: .4byte 0x0823a554
lbl_0800a240:
    ldr r0, lbl_0800a250 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800a254
    movs r0, #0x3a
    b lbl_0800a27c
    .align 2, 0
lbl_0800a250: .4byte gSamusPhysics
lbl_0800a254:
    ldr r0, lbl_0800a268 @ =gButtonInput
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a26c
    movs r0, #0x37
    b lbl_0800a27c
    .align 2, 0
lbl_0800a268: .4byte gButtonInput
lbl_0800a26c:
    movs r0, #0x30
    eors r0, r1
    ands r0, r2
    cmp r0, #0
    bne lbl_0800a27a
    movs r0, #0xff
    b lbl_0800a27c
lbl_0800a27a:
    movs r0, #0x39
lbl_0800a27c:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusStartingToCrawlGfx
SamusStartingToCrawlGfx: @ 0x0800a284
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800a298
    movs r0, #0xff
    b lbl_0800a29a
lbl_0800a298:
    movs r0, #0x35
lbl_0800a29a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusCrawling
SamusCrawling: @ 0x0800a2a0
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_0800a2bc @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800a2c0
    movs r0, #0x38
    b lbl_0800a30e
    .align 2, 0
lbl_0800a2bc: .4byte 0x0823a554
lbl_0800a2c0:
    ldr r3, lbl_0800a2d0 @ =gSamusPhysics
    adds r0, r3, #0
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800a2d4
    movs r0, #0x3a
    b lbl_0800a30e
    .align 2, 0
lbl_0800a2d0: .4byte gSamusPhysics
lbl_0800a2d4:
    ldr r0, lbl_0800a2f8 @ =gButtonInput
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a2fc
    adds r0, r3, #0
    adds r0, #0x5e
    movs r1, #0
    ldrsh r0, [r0, r1]
    movs r1, #0x20
    adds r2, r4, #0
    bl sub_08008278
    movs r0, #0xff
    b lbl_0800a30e
    .align 2, 0
lbl_0800a2f8: .4byte gButtonInput
lbl_0800a2fc:
    movs r0, #0x30
    eors r0, r1
    ands r0, r2
    lsls r0, r0, #0x10
    cmp r0, #0
    beq lbl_0800a30c
    movs r0, #1
    strb r0, [r4, #3]
lbl_0800a30c:
    movs r0, #0x35
lbl_0800a30e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusCrawlingGfx
SamusCrawlingGfx: @ 0x0800a314
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800a32c
    movs r0, #0
    strb r0, [r4, #0x1d]
    b lbl_0800a344
lbl_0800a32c:
    cmp r0, #1
    bne lbl_0800a344
    ldrb r0, [r4, #0x1d]
    cmp r0, #1
    beq lbl_0800a33a
    cmp r0, #4
    bne lbl_0800a344
lbl_0800a33a:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #7
    bl samus_apply_environment_effects
lbl_0800a344:
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800a350
    movs r0, #0x9e
    bl SoundPlay
lbl_0800a350:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusTurningAroundWhileCrawling
SamusTurningAroundWhileCrawling: @ 0x0800a358
    push {lr}
    ldr r0, lbl_0800a368 @ =gSamusPhysics
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800a36c
    movs r0, #0xff
    b lbl_0800a36e
    .align 2, 0
lbl_0800a368: .4byte gSamusPhysics
lbl_0800a36c:
    movs r0, #0x3a
lbl_0800a36e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningAroundWhileCrawlingGfx
SamusTurningAroundWhileCrawlingGfx: @ 0x0800a374
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800a388
    movs r0, #0xff
    b lbl_0800a38a
lbl_0800a388:
    movs r0, #0x36
lbl_0800a38a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusGrabbingALedgeSuitlessGfx
SamusGrabbingALedgeSuitlessGfx: @ 0x0800a390
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800a3a4
    movs r0, #0xff
    b lbl_0800a3a6
lbl_0800a3a4:
    movs r0, #0x15
lbl_0800a3a6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusFacingTheBackground
SamusFacingTheBackground: @ 0x0800a3ac
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_0800a3c8 @ =gButtonInput
    ldrh r0, [r0]
    movs r1, #0x30
    ands r1, r0
    cmp r1, #0
    beq lbl_0800a3cc
    ldrh r0, [r2, #0xc]
    cmp r0, #0
    bne lbl_0800a3cc
    strh r1, [r2, #0xe]
    movs r0, #0x3f
    b lbl_0800a3ce
    .align 2, 0
lbl_0800a3c8: .4byte gButtonInput
lbl_0800a3cc:
    movs r0, #0xff
lbl_0800a3ce:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SamusTurningFromFacingTheBackgroundGfx
SamusTurningFromFacingTheBackgroundGfx: @ 0x0800a3d4
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800a420
    ldr r2, lbl_0800a3fc @ =gButtonInput
    ldrh r0, [r4, #0xe]
    movs r1, #0x30
    eors r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a400
    movs r0, #0
    b lbl_0800a422
    .align 2, 0
lbl_0800a3fc: .4byte gButtonInput
lbl_0800a400:
    ldrh r0, [r4, #0xc]
    cmp r0, #0
    beq lbl_0800a40a
    movs r0, #0x3e
    b lbl_0800a422
lbl_0800a40a:
    ldr r0, lbl_0800a418 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0800a41c
    movs r0, #0x3b
    b lbl_0800a422
    .align 2, 0
lbl_0800a418: .4byte gEquipment
lbl_0800a41c:
    movs r0, #1
    b lbl_0800a422
lbl_0800a420:
    movs r0, #0xff
lbl_0800a422:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SamusTurningToEnterEscapeShipGfx
SamusTurningToEnterEscapeShipGfx: @ 0x0800a428
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800a43c
    movs r0, #0xff
    b lbl_0800a43e
lbl_0800a43c:
    movs r0, #0x41
lbl_0800a43e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_execute_pose
samus_execute_pose: @ 0x0800a444
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldr r6, lbl_0800a460 @ =gSamusWeaponInfo
    ldr r4, lbl_0800a464 @ =gEquipment
    ldr r2, lbl_0800a468 @ =gSamusHazardDamage
    adds r1, r4, #0
    bl samus_apply_hazard_damage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800a46c
    movs r0, #0xfa
    b lbl_0800a4f2
    .align 2, 0
lbl_0800a460: .4byte gSamusWeaponInfo
lbl_0800a464: .4byte gEquipment
lbl_0800a468: .4byte gSamusHazardDamage
lbl_0800a46c:
    ldrb r0, [r6, #4]
    cmp r0, #0
    beq lbl_0800a476
    subs r0, #1
    strb r0, [r6, #4]
lbl_0800a476:
    ldrb r0, [r5, #8]
    cmp r0, #0
    beq lbl_0800a49c
    ldrb r0, [r5]
    cmp r0, #0x21
    beq lbl_0800a49c
    cmp r0, #0x25
    beq lbl_0800a49c
    ldrb r0, [r5, #8]
    movs r1, #0xf
    ands r0, r1
    cmp r0, #4
    bne lbl_0800a496
    movs r0, #0x8d
    bl SoundPlay
lbl_0800a496:
    ldrb r0, [r5, #8]
    subs r0, #1
    strb r0, [r5, #8]
lbl_0800a49c:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    beq lbl_0800a4ac
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl SamusSetHighlightedWeapon
lbl_0800a4ac:
    adds r0, r5, #0
    adds r1, r4, #0
    bl SamusSetSpinningPose
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl SamusCheckNewProjectile
    ldr r1, lbl_0800a4f8 @ =0x0875e6a8
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r5, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0xff
    bne lbl_0800a4ea
    ldr r1, lbl_0800a4fc @ =0x0875e7b4
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    adds r0, r5, #0
    bl _call_via_r1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0800a4ea:
    adds r0, r5, #0
    bl sub_08008420
    adds r0, r4, #0
lbl_0800a4f2:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800a4f8: .4byte 0x0875e6a8
lbl_0800a4fc: .4byte 0x0875e7b4

    thumb_func_start samus_update_velocity_pos
samus_update_velocity_pos: @ 0x0800a500
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r3, lbl_0800a530 @ =gSamusPhysics
    ldr r1, lbl_0800a534 @ =0x08239464
    ldrb r2, [r4]
    lsls r0, r2, #1
    adds r0, r0, r2
    adds r1, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r1, r3, #0
    adds r1, #0x57
    strb r0, [r1]
    ldrb r0, [r4]
    subs r0, #8
    cmp r0, #0x2a
    bls lbl_0800a524
    b lbl_0800a646
lbl_0800a524:
    lsls r0, r0, #2
    ldr r1, lbl_0800a538 @ =lbl_0800a53c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800a530: .4byte gSamusPhysics
lbl_0800a534: .4byte 0x08239464
lbl_0800a538: .4byte lbl_0800a53c
lbl_0800a53c: @ jump table
    .4byte lbl_0800a5e8 @ case 0
    .4byte lbl_0800a5e8 @ case 1
    .4byte lbl_0800a646 @ case 2
    .4byte lbl_0800a5e8 @ case 3
    .4byte lbl_0800a5e8 @ case 4
    .4byte lbl_0800a646 @ case 5
    .4byte lbl_0800a5e8 @ case 6
    .4byte lbl_0800a5e8 @ case 7
    .4byte lbl_0800a646 @ case 8
    .4byte lbl_0800a646 @ case 9
    .4byte lbl_0800a646 @ case 10
    .4byte lbl_0800a646 @ case 11
    .4byte lbl_0800a5e8 @ case 12
    .4byte lbl_0800a646 @ case 13
    .4byte lbl_0800a646 @ case 14
    .4byte lbl_0800a646 @ case 15
    .4byte lbl_0800a646 @ case 16
    .4byte lbl_0800a646 @ case 17
    .4byte lbl_0800a646 @ case 18
    .4byte lbl_0800a646 @ case 19
    .4byte lbl_0800a646 @ case 20
    .4byte lbl_0800a646 @ case 21
    .4byte lbl_0800a646 @ case 22
    .4byte lbl_0800a646 @ case 23
    .4byte lbl_0800a646 @ case 24
    .4byte lbl_0800a646 @ case 25
    .4byte lbl_0800a630 @ case 26
    .4byte lbl_0800a646 @ case 27
    .4byte lbl_0800a646 @ case 28
    .4byte lbl_0800a646 @ case 29
    .4byte lbl_0800a630 @ case 30
    .4byte lbl_0800a646 @ case 31
    .4byte lbl_0800a646 @ case 32
    .4byte lbl_0800a646 @ case 33
    .4byte lbl_0800a646 @ case 34
    .4byte lbl_0800a646 @ case 35
    .4byte lbl_0800a646 @ case 36
    .4byte lbl_0800a646 @ case 37
    .4byte lbl_0800a646 @ case 38
    .4byte lbl_0800a5e8 @ case 39
    .4byte lbl_0800a5e8 @ case 40
    .4byte lbl_0800a5e8 @ case 41
    .4byte lbl_0800a5e8 @ case 42
lbl_0800a5e8:
    adds r0, r3, #0
    adds r0, #0x64
    ldrh r1, [r4, #0x18]
    ldrh r0, [r0]
    lsls r2, r1, #0x10
    lsls r0, r0, #0x10
    adds r5, r1, #0
    cmp r2, r0
    ble lbl_0800a5fe
    asrs r2, r0, #0x13
    b lbl_0800a616
lbl_0800a5fe:
    movs r0, #0x18
    ldrsh r1, [r4, r0]
    adds r0, r3, #0
    adds r0, #0x66
    movs r6, #0
    ldrsh r0, [r0, r6]
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_0800a614
    asrs r2, r0, #3
    b lbl_0800a616
lbl_0800a614:
    asrs r2, r2, #0x13
lbl_0800a616:
    lsls r1, r5, #0x10
    ldr r0, lbl_0800a62c @ =0xff190000
    cmp r1, r0
    blt lbl_0800a640
    adds r0, r3, #0
    adds r0, #0x62
    ldrh r0, [r0]
    subs r0, r5, r0
    strh r0, [r4, #0x18]
    b lbl_0800a640
    .align 2, 0
lbl_0800a62c: .4byte 0xff190000
lbl_0800a630:
    ldrb r1, [r4, #4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0800a646
    ldrh r0, [r4, #0x18]
    lsls r0, r0, #0x10
    asrs r2, r0, #0x13
lbl_0800a640:
    ldrh r0, [r4, #0x14]
    subs r0, r0, r2
    strh r0, [r4, #0x14]
lbl_0800a646:
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_0800a676
    adds r0, r4, #0
    bl SamusChangeVelocityOnSlope
    lsls r0, r0, #0x10
    asrs r2, r0, #0x13
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0800a67c
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a66e
    cmp r2, #0
    bge lbl_0800a67c
    movs r2, #0
    b lbl_0800a67c
lbl_0800a66e:
    cmp r2, #0
    ble lbl_0800a67c
    movs r2, #0
    b lbl_0800a67c
lbl_0800a676:
    ldrh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    asrs r2, r0, #0x13
lbl_0800a67c:
    ldrh r0, [r4, #0x12]
    adds r0, r0, r2
    strh r0, [r4, #0x12]
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start SamusUpdateGraphicsOam
SamusUpdateGraphicsOam: @ 0x0800a688
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov sb, r0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_0800a6c4 @ =gSamusWeaponInfo
    mov r8, r0
    ldr r6, lbl_0800a6c8 @ =gEquipment
    ldr r1, lbl_0800a6cc @ =gSamusPhysics
    mov ip, r1
    ldr r3, lbl_0800a6d0 @ =gSamusEcho
    mov r2, sb
    ldrb r2, [r2]
    mov sl, r2
    mov r0, sb
    ldrb r7, [r0, #2]
    mov r0, sl
    subs r0, #8
    cmp r0, #0xc
    bhi lbl_0800a72c
    lsls r0, r0, #2
    ldr r1, lbl_0800a6d4 @ =lbl_0800a6d8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800a6c4: .4byte gSamusWeaponInfo
lbl_0800a6c8: .4byte gEquipment
lbl_0800a6cc: .4byte gSamusPhysics
lbl_0800a6d0: .4byte gSamusEcho
lbl_0800a6d4: .4byte lbl_0800a6d8
lbl_0800a6d8: @ jump table
    .4byte lbl_0800a70c @ case 0
    .4byte lbl_0800a72c @ case 1
    .4byte lbl_0800a72c @ case 2
    .4byte lbl_0800a72c @ case 3
    .4byte lbl_0800a70c @ case 4
    .4byte lbl_0800a72c @ case 5
    .4byte lbl_0800a70c @ case 6
    .4byte lbl_0800a70c @ case 7
    .4byte lbl_0800a72c @ case 8
    .4byte lbl_0800a72c @ case 9
    .4byte lbl_0800a72c @ case 10
    .4byte lbl_0800a72c @ case 11
    .4byte lbl_0800a70c @ case 12
lbl_0800a70c:
    mov r0, ip
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800a72c
    mov r1, sb
    movs r2, #0x18
    ldrsh r0, [r1, r2]
    cmp r0, #0x50
    ble lbl_0800a72c
    movs r0, #1
    strb r0, [r3]
    movs r0, #6
    strb r0, [r3, #1]
    movs r0, #2
    strb r0, [r3, #3]
lbl_0800a72c:
    mov r1, sb
    ldrb r0, [r1, #5]
    cmp r0, #0
    beq lbl_0800a742
    movs r0, #1
    strb r0, [r3]
    movs r0, #0x10
    strb r0, [r3, #1]
    movs r0, #4
    strb r0, [r3, #3]
    b lbl_0800a752
lbl_0800a742:
    ldrb r0, [r3, #1]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_0800a750
    subs r0, #1
    strb r0, [r3, #1]
    b lbl_0800a752
lbl_0800a750:
    strb r1, [r3]
lbl_0800a752:
    movs r2, #0x84
    lsls r2, r2, #1
    adds r5, r3, r2
    ldrh r0, [r5]
    movs r2, #0x3f
    ands r2, r0
    lsls r2, r2, #1
    adds r0, r3, #0
    adds r0, #8
    adds r0, r0, r2
    ldr r1, lbl_0800a7c8 @ =gPreviousXPosition
    ldrh r1, [r1]
    strh r1, [r0]
    adds r0, r3, #0
    adds r0, #0x88
    adds r0, r0, r2
    ldr r1, lbl_0800a7cc @ =gPreviousYPosition
    ldrh r1, [r1]
    strh r1, [r0]
    ldrh r2, [r5]
    adds r0, r2, #1
    strh r0, [r5]
    lsls r1, r2, #0x10
    movs r0, #0x80
    lsls r0, r0, #0x11
    cmp r1, r0
    ble lbl_0800a78e
    adds r0, r2, #0
    subs r0, #0x7f
    strh r0, [r5]
lbl_0800a78e:
    movs r1, #0
    ldrsh r0, [r5, r1]
    cmp r0, #0x3f
    ble lbl_0800a7a0
    movs r2, #0x85
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #1
    strb r0, [r1]
lbl_0800a7a0:
    mov r3, sb
    ldrb r0, [r3]
    cmp r0, #0x2d
    bne lbl_0800a7b2
    ldrb r0, [r3, #0xa]
    cmp r0, #0
    beq lbl_0800a7b2
    movs r0, #1
    mov sl, r0
lbl_0800a7b2:
    mov r1, sl
    cmp r1, #0x3c
    bls lbl_0800a7bc
    bl lbl_0800af20
lbl_0800a7bc:
    lsls r0, r1, #2
    ldr r1, lbl_0800a7d0 @ =lbl_0800a7d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800a7c8: .4byte gPreviousXPosition
lbl_0800a7cc: .4byte gPreviousYPosition
lbl_0800a7d0: .4byte lbl_0800a7d4
lbl_0800a7d4: @ jump table
    .4byte lbl_0800a8c8 @ case 0
    .4byte lbl_0800a94c @ case 1
    .4byte lbl_0800a998 @ case 2
    .4byte lbl_0800a9e8 @ case 3
    .4byte lbl_0800aa30 @ case 4
    .4byte lbl_0800aa7c @ case 5
    .4byte lbl_0800aacc @ case 6
    .4byte lbl_0800ab14 @ case 7
    .4byte lbl_0800ab5c @ case 8
    .4byte lbl_0800aba4 @ case 9
    .4byte lbl_0800abf0 @ case 10
    .4byte lbl_0800af20 @ case 11
    .4byte lbl_0800af20 @ case 12
    .4byte lbl_0800af20 @ case 13
    .4byte lbl_0800af20 @ case 14
    .4byte lbl_0800ac40 @ case 15
    .4byte lbl_0800af20 @ case 16
    .4byte lbl_0800af20 @ case 17
    .4byte lbl_0800af20 @ case 18
    .4byte lbl_0800af20 @ case 19
    .4byte lbl_0800af20 @ case 20
    .4byte lbl_0800af20 @ case 21
    .4byte lbl_0800af20 @ case 22
    .4byte lbl_0800af20 @ case 23
    .4byte lbl_0800ac98 @ case 24
    .4byte lbl_0800ace8 @ case 25
    .4byte lbl_0800af20 @ case 26
    .4byte lbl_0800af20 @ case 27
    .4byte lbl_0800af20 @ case 28
    .4byte lbl_0800ad30 @ case 29
    .4byte lbl_0800af20 @ case 30
    .4byte lbl_0800af20 @ case 31
    .4byte lbl_0800af20 @ case 32
    .4byte lbl_0800af20 @ case 33
    .4byte lbl_0800ad70 @ case 34
    .4byte lbl_0800ad70 @ case 35
    .4byte lbl_0800af20 @ case 36
    .4byte lbl_0800af20 @ case 37
    .4byte lbl_0800af20 @ case 38
    .4byte lbl_0800af20 @ case 39
    .4byte lbl_0800ada4 @ case 40
    .4byte lbl_0800add4 @ case 41
    .4byte lbl_0800ae00 @ case 42
    .4byte lbl_0800af20 @ case 43
    .4byte lbl_0800ae90 @ case 44
    .4byte lbl_0800af20 @ case 45
    .4byte lbl_0800af20 @ case 46
    .4byte lbl_0800af20 @ case 47
    .4byte lbl_0800af20 @ case 48
    .4byte lbl_0800af20 @ case 49
    .4byte lbl_0800af20 @ case 50
    .4byte lbl_0800af20 @ case 51
    .4byte lbl_0800af20 @ case 52
    .4byte lbl_0800ae30 @ case 53
    .4byte lbl_0800af20 @ case 54
    .4byte lbl_0800af20 @ case 55
    .4byte lbl_0800af20 @ case 56
    .4byte lbl_0800af20 @ case 57
    .4byte lbl_0800af20 @ case 58
    .4byte lbl_0800ae4c @ case 59
    .4byte lbl_0800ae6c @ case 60
lbl_0800a8c8:
    cmp r7, #4
    bls lbl_0800a8d2
    subs r0, r7, #2
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0800a8d2:
    ldrb r1, [r6, #0x12]
    cmp r1, #2
    bne lbl_0800a8f0
    ldr r1, lbl_0800a8e8 @ =0x08239bc8
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800a8ec @ =0x08239fb8
    b lbl_0800ae7a
    .align 2, 0
lbl_0800a8e8: .4byte 0x08239bc8
lbl_0800a8ec: .4byte 0x08239fb8
lbl_0800a8f0:
    mov r3, sb
    ldrb r0, [r3, #5]
    cmp r0, #0
    bne lbl_0800a924
    cmp r1, #0
    beq lbl_0800a904
    ldr r3, lbl_0800a900 @ =0x08239748
    b lbl_0800a906
    .align 2, 0
lbl_0800a900: .4byte 0x08239748
lbl_0800a904:
    ldr r3, lbl_0800a91c @ =0x08238d8c
lbl_0800a906:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800a920 @ =0x0823920c
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800a91c: .4byte 0x08238d8c
lbl_0800a920: .4byte 0x0823920c
lbl_0800a924:
    cmp r1, #0
    beq lbl_0800a930
    ldr r3, lbl_0800a92c @ =0x08239768
    b lbl_0800a932
    .align 2, 0
lbl_0800a92c: .4byte 0x08239768
lbl_0800a930:
    ldr r3, lbl_0800a944 @ =0x08238dac
lbl_0800a932:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800a948 @ =0x0823922c
    b lbl_0800af72
    .align 2, 0
lbl_0800a944: .4byte 0x08238dac
lbl_0800a948: .4byte 0x0823922c
lbl_0800a94c:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800a96c
    ldr r1, lbl_0800a964 @ =0x08239be8
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800a968 @ =0x08239fd8
    b lbl_0800ae7a
    .align 2, 0
lbl_0800a964: .4byte 0x08239be8
lbl_0800a968: .4byte 0x08239fd8
lbl_0800a96c:
    cmp r0, #0
    beq lbl_0800a978
    ldr r3, lbl_0800a974 @ =0x08239788
    b lbl_0800a97a
    .align 2, 0
lbl_0800a974: .4byte 0x08239788
lbl_0800a978:
    ldr r3, lbl_0800a990 @ =0x08238dcc
lbl_0800a97a:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800a994 @ =0x0823924c
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800a990: .4byte 0x08238dcc
lbl_0800a994: .4byte 0x0823924c
lbl_0800a998:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800a9bc
    ldr r1, lbl_0800a9b4 @ =0x08239c08
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800a9b8 @ =0x08239ff8
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
    b lbl_0800af78
    .align 2, 0
lbl_0800a9b4: .4byte 0x08239c08
lbl_0800a9b8: .4byte 0x08239ff8
lbl_0800a9bc:
    cmp r0, #0
    beq lbl_0800a9c8
    ldr r3, lbl_0800a9c4 @ =0x082397a8
    b lbl_0800a9ca
    .align 2, 0
lbl_0800a9c4: .4byte 0x082397a8
lbl_0800a9c8:
    ldr r3, lbl_0800a9e0 @ =0x08238dec
lbl_0800a9ca:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800a9e4 @ =0x0823926c
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800a9e0: .4byte 0x08238dec
lbl_0800a9e4: .4byte 0x0823926c
lbl_0800a9e8:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800aa08
    ldr r1, lbl_0800aa00 @ =0x08239c28
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800aa04 @ =0x0823a018
    b lbl_0800af36
    .align 2, 0
lbl_0800aa00: .4byte 0x08239c28
lbl_0800aa04: .4byte 0x0823a018
lbl_0800aa08:
    cmp r0, #0
    beq lbl_0800aa14
    ldr r3, lbl_0800aa10 @ =0x082397c8
    b lbl_0800aa16
    .align 2, 0
lbl_0800aa10: .4byte 0x082397c8
lbl_0800aa14:
    ldr r3, lbl_0800aa28 @ =0x08238e0c
lbl_0800aa16:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800aa2c @ =0x0823928c
    b lbl_0800af72
    .align 2, 0
lbl_0800aa28: .4byte 0x08238e0c
lbl_0800aa2c: .4byte 0x0823928c
lbl_0800aa30:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800aa50
    ldr r1, lbl_0800aa48 @ =0x08239c48
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800aa4c @ =0x0823a038
    b lbl_0800ae7a
    .align 2, 0
lbl_0800aa48: .4byte 0x08239c48
lbl_0800aa4c: .4byte 0x0823a038
lbl_0800aa50:
    cmp r0, #0
    beq lbl_0800aa5c
    ldr r3, lbl_0800aa58 @ =0x082397e8
    b lbl_0800aa5e
    .align 2, 0
lbl_0800aa58: .4byte 0x082397e8
lbl_0800aa5c:
    ldr r3, lbl_0800aa74 @ =0x08238e2c
lbl_0800aa5e:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800aa78 @ =0x082392ac
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800aa74: .4byte 0x08238e2c
lbl_0800aa78: .4byte 0x082392ac
lbl_0800aa7c:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800aaa0
    ldr r1, lbl_0800aa98 @ =0x08239c60
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800aa9c @ =0x0823a050
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
    b lbl_0800af78
    .align 2, 0
lbl_0800aa98: .4byte 0x08239c60
lbl_0800aa9c: .4byte 0x0823a050
lbl_0800aaa0:
    cmp r0, #0
    beq lbl_0800aaac
    ldr r3, lbl_0800aaa8 @ =0x08239800
    b lbl_0800aaae
    .align 2, 0
lbl_0800aaa8: .4byte 0x08239800
lbl_0800aaac:
    ldr r3, lbl_0800aac4 @ =0x08238e44
lbl_0800aaae:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800aac8 @ =0x082392c4
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800aac4: .4byte 0x08238e44
lbl_0800aac8: .4byte 0x082392c4
lbl_0800aacc:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800aaec
    ldr r1, lbl_0800aae4 @ =0x08239c78
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800aae8 @ =0x0823a068
    b lbl_0800af36
    .align 2, 0
lbl_0800aae4: .4byte 0x08239c78
lbl_0800aae8: .4byte 0x0823a068
lbl_0800aaec:
    cmp r0, #0
    beq lbl_0800aaf8
    ldr r3, lbl_0800aaf4 @ =0x08239818
    b lbl_0800aafa
    .align 2, 0
lbl_0800aaf4: .4byte 0x08239818
lbl_0800aaf8:
    ldr r3, lbl_0800ab0c @ =0x08238e5c
lbl_0800aafa:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ab10 @ =0x082392dc
    b lbl_0800af72
    .align 2, 0
lbl_0800ab0c: .4byte 0x08238e5c
lbl_0800ab10: .4byte 0x082392dc
lbl_0800ab14:
    mov r2, r8
    ldrb r1, [r2, #2]
    movs r0, #3
    ands r0, r1
    adds r3, r1, #0
    cmp r0, #0
    beq lbl_0800ab28
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0800ab28:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ab38
    ldr r2, lbl_0800ab34 @ =0x08239830
    b lbl_0800ab3a
    .align 2, 0
lbl_0800ab34: .4byte 0x08239830
lbl_0800ab38:
    ldr r2, lbl_0800ab54 @ =0x08238e74
lbl_0800ab3a:
    lsls r1, r4, #2
    lsls r0, r7, #3
    adds r0, r1, r0
    adds r0, r0, r2
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ab58 @ =0x08238ff4
    mov r4, sl
    lsls r0, r4, #3
    adds r0, r6, r0
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af7c
    .align 2, 0
lbl_0800ab54: .4byte 0x08238e74
lbl_0800ab58: .4byte 0x08238ff4
lbl_0800ab5c:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800ab7c
    ldr r1, lbl_0800ab74 @ =0x08239c90
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ab78 @ =0x0823a080
    b lbl_0800af36
    .align 2, 0
lbl_0800ab74: .4byte 0x08239c90
lbl_0800ab78: .4byte 0x0823a080
lbl_0800ab7c:
    cmp r0, #0
    beq lbl_0800ab88
    ldr r3, lbl_0800ab84 @ =0x08239840
    b lbl_0800ab8a
    .align 2, 0
lbl_0800ab84: .4byte 0x08239840
lbl_0800ab88:
    ldr r3, lbl_0800ab9c @ =0x08238e84
lbl_0800ab8a:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800aba0 @ =0x08239304
    b lbl_0800af72
    .align 2, 0
lbl_0800ab9c: .4byte 0x08238e84
lbl_0800aba0: .4byte 0x08239304
lbl_0800aba4:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800abc4
    ldr r1, lbl_0800abbc @ =0x08239cb8
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800abc0 @ =0x0823a0a8
    b lbl_0800ae7a
    .align 2, 0
lbl_0800abbc: .4byte 0x08239cb8
lbl_0800abc0: .4byte 0x0823a0a8
lbl_0800abc4:
    cmp r0, #0
    beq lbl_0800abd0
    ldr r3, lbl_0800abcc @ =0x08239868
    b lbl_0800abd2
    .align 2, 0
lbl_0800abcc: .4byte 0x08239868
lbl_0800abd0:
    ldr r3, lbl_0800abe8 @ =0x08238eac
lbl_0800abd2:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800abec @ =0x0823932c
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800abe8: .4byte 0x08238eac
lbl_0800abec: .4byte 0x0823932c
lbl_0800abf0:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800ac14
    ldr r1, lbl_0800ac0c @ =0x08239ce0
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ac10 @ =0x0823a0d0
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
    b lbl_0800af78
    .align 2, 0
lbl_0800ac0c: .4byte 0x08239ce0
lbl_0800ac10: .4byte 0x0823a0d0
lbl_0800ac14:
    cmp r0, #0
    beq lbl_0800ac20
    ldr r3, lbl_0800ac1c @ =0x08239890
    b lbl_0800ac22
    .align 2, 0
lbl_0800ac1c: .4byte 0x08239890
lbl_0800ac20:
    ldr r3, lbl_0800ac38 @ =0x08238ed4
lbl_0800ac22:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ac3c @ =0x08239354
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800ac38: .4byte 0x08238ed4
lbl_0800ac3c: .4byte 0x08239354
lbl_0800ac40:
    ldrb r1, [r6, #0xf]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ac68
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ac5c
    ldr r0, lbl_0800ac58 @ =0x082398b0
    lsls r1, r4, #2
    adds r0, #8
    b lbl_0800ac7c
    .align 2, 0
lbl_0800ac58: .4byte 0x082398b0
lbl_0800ac5c:
    ldr r0, lbl_0800ac64 @ =0x08238ef4
    lsls r1, r4, #2
    adds r0, #8
    b lbl_0800ac7c
    .align 2, 0
lbl_0800ac64: .4byte 0x08238ef4
lbl_0800ac68:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ac78
    ldr r0, lbl_0800ac74 @ =0x082398b0
    b lbl_0800ac7a
    .align 2, 0
lbl_0800ac74: .4byte 0x082398b0
lbl_0800ac78:
    ldr r0, lbl_0800ac90 @ =0x08238ef4
lbl_0800ac7a:
    lsls r1, r4, #2
lbl_0800ac7c:
    adds r0, r1, r0
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ac94 @ =0x08238ff4
    mov r3, sl
    lsls r0, r3, #3
    adds r0, r6, r0
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800ac90: .4byte 0x08238ef4
lbl_0800ac94: .4byte 0x08238ff4
lbl_0800ac98:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800acbc
    ldr r1, lbl_0800acb4 @ =0x08239d00
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800acb8 @ =0x0823a0f0
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
    b lbl_0800af78
    .align 2, 0
lbl_0800acb4: .4byte 0x08239d00
lbl_0800acb8: .4byte 0x0823a0f0
lbl_0800acbc:
    cmp r0, #0
    beq lbl_0800acc8
    ldr r3, lbl_0800acc4 @ =0x082398c0
    b lbl_0800acca
    .align 2, 0
lbl_0800acc4: .4byte 0x082398c0
lbl_0800acc8:
    ldr r3, lbl_0800ace0 @ =0x08238f04
lbl_0800acca:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ace4 @ =0x08239374
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800ace0: .4byte 0x08238f04
lbl_0800ace4: .4byte 0x08239374
lbl_0800ace8:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800ad08
    ldr r1, lbl_0800ad00 @ =0x08239d28
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ad04 @ =0x0823a118
    b lbl_0800af36
    .align 2, 0
lbl_0800ad00: .4byte 0x08239d28
lbl_0800ad04: .4byte 0x0823a118
lbl_0800ad08:
    cmp r0, #0
    beq lbl_0800ad14
    ldr r3, lbl_0800ad10 @ =0x082398e8
    b lbl_0800ad16
    .align 2, 0
lbl_0800ad10: .4byte 0x082398e8
lbl_0800ad14:
    ldr r3, lbl_0800ad28 @ =0x08238f2c
lbl_0800ad16:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ad2c @ =0x0823939c
    b lbl_0800af72
    .align 2, 0
lbl_0800ad28: .4byte 0x08238f2c
lbl_0800ad2c: .4byte 0x0823939c
lbl_0800ad30:
    mov r2, sb
    ldrh r1, [r2, #0x10]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ad42
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0800ad42:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ad50
    ldr r3, lbl_0800ad4c @ =0x08239910
    b lbl_0800ad52
    .align 2, 0
lbl_0800ad4c: .4byte 0x08239910
lbl_0800ad50:
    ldr r3, lbl_0800ad68 @ =0x08238f54
lbl_0800ad52:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ad6c @ =0x082393c4
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800ad68: .4byte 0x08238f54
lbl_0800ad6c: .4byte 0x082393c4
lbl_0800ad70:
    mov r1, sb
    ldrb r7, [r1, #4]
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ad84
    ldr r3, lbl_0800ad80 @ =0x08239920
    b lbl_0800ad86
    .align 2, 0
lbl_0800ad80: .4byte 0x08239920
lbl_0800ad84:
    ldr r3, lbl_0800ad9c @ =0x08238f64
lbl_0800ad86:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ada0 @ =0x082393d4
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800ad9c: .4byte 0x08238f64
lbl_0800ada0: .4byte 0x082393d4
lbl_0800ada4:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800adb4
    ldr r3, lbl_0800adb0 @ =0x08239938
    b lbl_0800adb6
    .align 2, 0
lbl_0800adb0: .4byte 0x08239938
lbl_0800adb4:
    ldr r3, lbl_0800adcc @ =0x08238f7c
lbl_0800adb6:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800add0 @ =0x082393ec
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800adcc: .4byte 0x08238f7c
lbl_0800add0: .4byte 0x082393ec
lbl_0800add4:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ade4
    ldr r3, lbl_0800ade0 @ =0x08239960
    b lbl_0800ade6
    .align 2, 0
lbl_0800ade0: .4byte 0x08239960
lbl_0800ade4:
    ldr r3, lbl_0800adf8 @ =0x08238fa4
lbl_0800ade6:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800adfc @ =0x08239414
    b lbl_0800af72
    .align 2, 0
lbl_0800adf8: .4byte 0x08238fa4
lbl_0800adfc: .4byte 0x08239414
lbl_0800ae00:
    ldrb r0, [r6, #0x12]
    cmp r0, #0
    beq lbl_0800ae10
    ldr r3, lbl_0800ae0c @ =0x08239988
    b lbl_0800ae12
    .align 2, 0
lbl_0800ae0c: .4byte 0x08239988
lbl_0800ae10:
    ldr r3, lbl_0800ae28 @ =0x08238fcc
lbl_0800ae12:
    lsls r1, r4, #2
    lsls r2, r7, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800ae2c @ =0x0823943c
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800ae80
    .align 2, 0
lbl_0800ae28: .4byte 0x08238fcc
lbl_0800ae2c: .4byte 0x0823943c
lbl_0800ae30:
    mov r3, sb
    ldrb r7, [r3, #4]
    ldr r1, lbl_0800ae44 @ =0x08239d88
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ae48 @ =0x0823a188
    b lbl_0800af36
    .align 2, 0
lbl_0800ae44: .4byte 0x08239d88
lbl_0800ae48: .4byte 0x0823a188
lbl_0800ae4c:
    ldr r1, lbl_0800ae64 @ =0x08239d50
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ae68 @ =0x0823a140
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
    b lbl_0800af78
    .align 2, 0
lbl_0800ae64: .4byte 0x08239d50
lbl_0800ae68: .4byte 0x0823a140
lbl_0800ae6c:
    ldr r1, lbl_0800ae88 @ =0x08239d70
    lsls r2, r4, #2
    lsls r0, r7, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800ae8c @ =0x0823a160
lbl_0800ae7a:
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
lbl_0800ae80:
    mov r2, r8
    ldrb r3, [r2, #2]
    b lbl_0800af7c
    .align 2, 0
lbl_0800ae88: .4byte 0x08239d70
lbl_0800ae8c: .4byte 0x0823a160
lbl_0800ae90:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800aec8
    mov r3, sb
    ldrh r0, [r3, #0xc]
    cmp r0, #0
    beq lbl_0800aeac
    ldr r5, lbl_0800aea8 @ =0x082b0bf4
    lsls r6, r4, #2
    mov r4, sl
    lsls r2, r4, #3
    b lbl_0800aebc
    .align 2, 0
lbl_0800aea8: .4byte 0x082b0bf4
lbl_0800aeac:
    ldr r3, lbl_0800aec0 @ =0x082399b0
    lsls r1, r4, #2
    mov r0, sl
    lsls r2, r0, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
lbl_0800aebc:
    ldr r1, lbl_0800aec4 @ =0x08239da0
    b lbl_0800af72
    .align 2, 0
lbl_0800aec0: .4byte 0x082399b0
lbl_0800aec4: .4byte 0x08239da0
lbl_0800aec8:
    cmp r0, #0
    beq lbl_0800aee4
    mov r2, sb
    ldrh r0, [r2, #0xc]
    cmp r0, #0
    beq lbl_0800aedc
    ldr r5, lbl_0800aed8 @ =0x0827f430
    b lbl_0800aeee
    .align 2, 0
lbl_0800aed8: .4byte 0x0827f430
lbl_0800aedc:
    ldr r3, lbl_0800aee0 @ =0x08239530
    b lbl_0800aefe
    .align 2, 0
lbl_0800aee0: .4byte 0x08239530
lbl_0800aee4:
    mov r1, sb
    ldrh r0, [r1, #0xc]
    cmp r0, #0
    beq lbl_0800aefc
    ldr r5, lbl_0800aef8 @ =0x08256484
lbl_0800aeee:
    lsls r6, r4, #2
    mov r3, sl
    lsls r2, r3, #3
    b lbl_0800af0c
    .align 2, 0
lbl_0800aef8: .4byte 0x08256484
lbl_0800aefc:
    ldr r3, lbl_0800af18 @ =0x08238b74
lbl_0800aefe:
    lsls r1, r4, #2
    mov r4, sl
    lsls r2, r4, #3
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
lbl_0800af0c:
    ldr r1, lbl_0800af1c @ =0x08238ff4
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
    b lbl_0800af3c
    .align 2, 0
lbl_0800af18: .4byte 0x08238b74
lbl_0800af1c: .4byte 0x08238ff4
lbl_0800af20:
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_0800af4c
    ldr r1, lbl_0800af44 @ =0x082399b0
    lsls r2, r4, #2
    mov r3, sl
    lsls r0, r3, #3
    adds r0, r2, r0
    adds r1, r0, r1
    ldr r5, [r1]
    ldr r1, lbl_0800af48 @ =0x08239da0
lbl_0800af36:
    adds r0, r0, r1
    ldr r4, [r0]
    adds r6, r2, #0
lbl_0800af3c:
    mov r0, r8
    ldrb r3, [r0, #2]
    b lbl_0800af7c
    .align 2, 0
lbl_0800af44: .4byte 0x082399b0
lbl_0800af48: .4byte 0x08239da0
lbl_0800af4c:
    cmp r0, #0
    beq lbl_0800af60
    ldr r3, lbl_0800af5c @ =0x08239530
    lsls r1, r4, #2
    mov r4, sl
    lsls r2, r4, #3
    b lbl_0800af68
    .align 2, 0
lbl_0800af5c: .4byte 0x08239530
lbl_0800af60:
    ldr r3, lbl_0800afe4 @ =0x08238b74
    lsls r1, r4, #2
    mov r0, sl
    lsls r2, r0, #3
lbl_0800af68:
    adds r0, r1, r2
    adds r0, r0, r3
    ldr r5, [r0]
    adds r6, r1, #0
    ldr r1, lbl_0800afe8 @ =0x08238ff4
lbl_0800af72:
    adds r0, r6, r2
    adds r0, r0, r1
    ldr r4, [r0]
lbl_0800af78:
    mov r1, r8
    ldrb r3, [r1, #2]
lbl_0800af7c:
    mov r2, sb
    ldrb r0, [r2, #0x1d]
    lsls r0, r0, #4
    adds r5, r5, r0
    ldr r0, [r5, #8]
    mov r1, ip
    str r0, [r1]
    ldr r1, [r5]
    ldrb r0, [r1]
    lsls r0, r0, #5
    mov r8, r0
    mov r0, r8
    mov r2, ip
    strh r0, [r2, #8]
    adds r1, #1
    ldrb r0, [r1]
    lsls r0, r0, #5
    mov r8, r0
    mov r0, r8
    strh r0, [r2, #0x10]
    adds r1, #1
    str r1, [r2, #4]
    ldrh r2, [r2, #8]
    mov r8, r2
    add r8, r1
    mov r0, r8
    mov r1, ip
    str r0, [r1, #0xc]
    ldr r1, [r5, #4]
    ldrb r0, [r1]
    lsls r0, r0, #5
    mov r2, ip
    strh r0, [r2, #0x18]
    adds r1, #1
    ldrb r0, [r1]
    lsls r0, r0, #5
    strh r0, [r2, #0x20]
    adds r1, #1
    str r1, [r2, #0x14]
    ldrh r0, [r2, #0x18]
    adds r0, r1, r0
    str r0, [r2, #0x1c]
    movs r0, #0
    strh r0, [r2, #0x22]
    mov r2, sb
    ldrb r1, [r2, #0x1d]
    mov r0, sl
    cmp r0, #0x33
    bne lbl_0800afec
    movs r0, #0
    b lbl_0800afee
    .align 2, 0
lbl_0800afe4: .4byte 0x08238b74
lbl_0800afe8: .4byte 0x08238ff4
lbl_0800afec:
    movs r0, #0x40
lbl_0800afee:
    mov r2, ip
    strh r0, [r2, #0x2c]
    strh r0, [r2, #0x34]
    lsls r0, r1, #3
    adds r4, r4, r0
    ldr r0, [r4, #4]
    mov r4, ip
    str r0, [r4, #0x24]
    ldrh r0, [r0]
    strh r0, [r4, #0x22]
    mov r0, sb
    ldrh r2, [r0, #0xe]
    mov r1, sl
    cmp r1, #0x29
    bls lbl_0800b00e
    b lbl_0800b20c
lbl_0800b00e:
    lsls r0, r1, #2
    ldr r1, lbl_0800b018 @ =lbl_0800b01c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800b018: .4byte lbl_0800b01c
lbl_0800b01c: @ jump table
    .4byte lbl_0800b1c4 @ case 0
    .4byte lbl_0800b20c @ case 1
    .4byte lbl_0800b20c @ case 2
    .4byte lbl_0800b20c @ case 3
    .4byte lbl_0800b20c @ case 4
    .4byte lbl_0800b20c @ case 5
    .4byte lbl_0800b20c @ case 6
    .4byte lbl_0800b20c @ case 7
    .4byte lbl_0800b20c @ case 8
    .4byte lbl_0800b20c @ case 9
    .4byte lbl_0800b20c @ case 10
    .4byte lbl_0800b20c @ case 11
    .4byte lbl_0800b20c @ case 12
    .4byte lbl_0800b20c @ case 13
    .4byte lbl_0800b20c @ case 14
    .4byte lbl_0800b20c @ case 15
    .4byte lbl_0800b20c @ case 16
    .4byte lbl_0800b20c @ case 17
    .4byte lbl_0800b20c @ case 18
    .4byte lbl_0800b20c @ case 19
    .4byte lbl_0800b20c @ case 20
    .4byte lbl_0800b20c @ case 21
    .4byte lbl_0800b20c @ case 22
    .4byte lbl_0800b20c @ case 23
    .4byte lbl_0800b0c4 @ case 24
    .4byte lbl_0800b0c4 @ case 25
    .4byte lbl_0800b20c @ case 26
    .4byte lbl_0800b20c @ case 27
    .4byte lbl_0800b20c @ case 28
    .4byte lbl_0800b20c @ case 29
    .4byte lbl_0800b20c @ case 30
    .4byte lbl_0800b20c @ case 31
    .4byte lbl_0800b20c @ case 32
    .4byte lbl_0800b20c @ case 33
    .4byte lbl_0800b20c @ case 34
    .4byte lbl_0800b20c @ case 35
    .4byte lbl_0800b20c @ case 36
    .4byte lbl_0800b20c @ case 37
    .4byte lbl_0800b20c @ case 38
    .4byte lbl_0800b20c @ case 39
    .4byte lbl_0800b144 @ case 40
    .4byte lbl_0800b144 @ case 41
lbl_0800b0c4:
    movs r0, #3
    ands r0, r3
    cmp r0, #0
    beq lbl_0800b108
    mov r2, sb
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b0f0
    ldr r0, lbl_0800b0e8 @ =0x0823a484
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b0ec @ =0x0823a498
    b lbl_0800b26a
    .align 2, 0
lbl_0800b0e8: .4byte 0x0823a484
lbl_0800b0ec: .4byte 0x0823a498
lbl_0800b0f0:
    ldr r0, lbl_0800b100 @ =0x0823a45c
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r4, ip
    str r0, [r4, #0x28]
    ldr r0, lbl_0800b104 @ =0x0823a470
    b lbl_0800b28a
    .align 2, 0
lbl_0800b100: .4byte 0x0823a45c
lbl_0800b104: .4byte 0x0823a470
lbl_0800b108:
    mov r0, sb
    ldrh r1, [r0, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b12c
    ldr r0, lbl_0800b124 @ =0x0823a434
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r2, ip
    str r0, [r2, #0x28]
    ldr r0, lbl_0800b128 @ =0x0823a448
    b lbl_0800b242
    .align 2, 0
lbl_0800b124: .4byte 0x0823a434
lbl_0800b128: .4byte 0x0823a448
lbl_0800b12c:
    ldr r0, lbl_0800b13c @ =0x0823a40c
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b140 @ =0x0823a420
    b lbl_0800b26a
    .align 2, 0
lbl_0800b13c: .4byte 0x0823a40c
lbl_0800b140: .4byte 0x0823a420
lbl_0800b144:
    movs r0, #3
    ands r0, r3
    cmp r0, #0
    beq lbl_0800b188
    mov r4, sb
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b170
    ldr r0, lbl_0800b168 @ =0x0823a4d4
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r2, ip
    str r0, [r2, #0x28]
    ldr r0, lbl_0800b16c @ =0x0823a4e8
    b lbl_0800b242
    .align 2, 0
lbl_0800b168: .4byte 0x0823a4d4
lbl_0800b16c: .4byte 0x0823a4e8
lbl_0800b170:
    ldr r0, lbl_0800b180 @ =0x0823a3e4
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b184 @ =0x0823a3f8
    b lbl_0800b26a
    .align 2, 0
lbl_0800b180: .4byte 0x0823a3e4
lbl_0800b184: .4byte 0x0823a3f8
lbl_0800b188:
    mov r4, sb
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b1ac
    ldr r0, lbl_0800b1a4 @ =0x0823a4ac
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r2, ip
    str r0, [r2, #0x28]
    ldr r0, lbl_0800b1a8 @ =0x0823a4c0
    b lbl_0800b242
    .align 2, 0
lbl_0800b1a4: .4byte 0x0823a4ac
lbl_0800b1a8: .4byte 0x0823a4c0
lbl_0800b1ac:
    ldr r0, lbl_0800b1bc @ =0x0823a394
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b1c0 @ =0x0823a3a8
    b lbl_0800b26a
    .align 2, 0
lbl_0800b1bc: .4byte 0x0823a394
lbl_0800b1c0: .4byte 0x0823a3a8
lbl_0800b1c4:
    mov r4, sb
    ldrh r1, [r4, #0xe]
    movs r0, #0x10
    ands r0, r1
    adds r2, r1, #0
    cmp r0, #0
    beq lbl_0800b20c
    movs r0, #3
    ands r0, r3
    cmp r0, #0
    beq lbl_0800b1f4
    ldr r0, lbl_0800b1ec @ =0x0823a344
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r2, ip
    str r0, [r2, #0x28]
    ldr r0, lbl_0800b1f0 @ =0x0823a358
    b lbl_0800b242
    .align 2, 0
lbl_0800b1ec: .4byte 0x0823a344
lbl_0800b1f0: .4byte 0x0823a358
lbl_0800b1f4:
    ldr r0, lbl_0800b204 @ =0x0823a31c
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b208 @ =0x0823a330
    b lbl_0800b26a
    .align 2, 0
lbl_0800b204: .4byte 0x0823a31c
lbl_0800b208: .4byte 0x0823a330
lbl_0800b20c:
    movs r0, #3
    ands r0, r3
    cmp r0, #0
    beq lbl_0800b254
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_0800b234
    ldr r0, lbl_0800b22c @ =0x0823a3bc
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r4, ip
    str r0, [r4, #0x28]
    ldr r0, lbl_0800b230 @ =0x0823a3d0
    b lbl_0800b28a
    .align 2, 0
lbl_0800b22c: .4byte 0x0823a3bc
lbl_0800b230: .4byte 0x0823a3d0
lbl_0800b234:
    ldr r0, lbl_0800b24c @ =0x0823a3e4
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r2, ip
    str r0, [r2, #0x28]
    ldr r0, lbl_0800b250 @ =0x0823a3f8
lbl_0800b242:
    adds r1, r1, r0
    ldr r0, [r1]
    str r0, [r2, #0x30]
    b lbl_0800b290
    .align 2, 0
lbl_0800b24c: .4byte 0x0823a3e4
lbl_0800b250: .4byte 0x0823a3f8
lbl_0800b254:
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_0800b27c
    ldr r0, lbl_0800b274 @ =0x0823a36c
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r3, ip
    str r0, [r3, #0x28]
    ldr r0, lbl_0800b278 @ =0x0823a380
lbl_0800b26a:
    adds r1, r1, r0
    ldr r0, [r1]
    str r0, [r3, #0x30]
    b lbl_0800b290
    .align 2, 0
lbl_0800b274: .4byte 0x0823a36c
lbl_0800b278: .4byte 0x0823a380
lbl_0800b27c:
    ldr r0, lbl_0800b30c @ =0x0823a394
    lsls r1, r7, #2
    adds r0, r1, r0
    ldr r0, [r0]
    mov r4, ip
    str r0, [r4, #0x28]
    ldr r0, lbl_0800b310 @ =0x0823a3a8
lbl_0800b28a:
    adds r1, r1, r0
    ldr r0, [r1]
    str r0, [r4, #0x30]
lbl_0800b290:
    mov r3, ip
    adds r3, #0x36
    movs r0, #0
    strb r0, [r3]
    mov r2, ip
    adds r2, #0x40
    movs r5, #0
    strh r0, [r2]
    mov r1, ip
    adds r1, #0x48
    strh r0, [r1]
    ldr r4, lbl_0800b314 @ =gScrewSpeedAnimation
    ldrb r0, [r4]
    adds r7, r2, #0
    mov r8, r1
    cmp r0, #8
    bne lbl_0800b2ec
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    ldr r4, lbl_0800b318 @ =0x082890f0
    ldr r1, lbl_0800b314 @ =gScrewSpeedAnimation
    ldrb r2, [r1, #2]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r1, #8]
    cmp r0, r1
    blo lbl_0800b2ec
    ldr r2, lbl_0800b314 @ =gScrewSpeedAnimation
    strb r5, [r2, #1]
    ldrb r0, [r2, #2]
    adds r0, #1
    strb r0, [r2, #2]
    ldrb r1, [r2, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #8]
    cmp r0, #0
    bne lbl_0800b2ec
    strb r5, [r2]
lbl_0800b2ec:
    ldr r4, lbl_0800b314 @ =gScrewSpeedAnimation
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0800b2f6
    b lbl_0800b452
lbl_0800b2f6:
    movs r0, #0x20
    strb r0, [r3]
    mov r0, sl
    cmp r0, #0x26
    bls lbl_0800b302
    b lbl_0800b414
lbl_0800b302:
    lsls r0, r0, #2
    ldr r1, lbl_0800b31c @ =lbl_0800b320
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800b30c: .4byte 0x0823a394
lbl_0800b310: .4byte 0x0823a3a8
lbl_0800b314: .4byte gScrewSpeedAnimation
lbl_0800b318: .4byte 0x082890f0
lbl_0800b31c: .4byte lbl_0800b320
lbl_0800b320: @ jump table
    .4byte lbl_0800b3f0 @ case 0
    .4byte lbl_0800b414 @ case 1
    .4byte lbl_0800b414 @ case 2
    .4byte lbl_0800b414 @ case 3
    .4byte lbl_0800b414 @ case 4
    .4byte lbl_0800b414 @ case 5
    .4byte lbl_0800b414 @ case 6
    .4byte lbl_0800b414 @ case 7
    .4byte lbl_0800b414 @ case 8
    .4byte lbl_0800b414 @ case 9
    .4byte lbl_0800b414 @ case 10
    .4byte lbl_0800b414 @ case 11
    .4byte lbl_0800b414 @ case 12
    .4byte lbl_0800b414 @ case 13
    .4byte lbl_0800b414 @ case 14
    .4byte lbl_0800b3bc @ case 15
    .4byte lbl_0800b414 @ case 16
    .4byte lbl_0800b414 @ case 17
    .4byte lbl_0800b414 @ case 18
    .4byte lbl_0800b414 @ case 19
    .4byte lbl_0800b414 @ case 20
    .4byte lbl_0800b414 @ case 21
    .4byte lbl_0800b414 @ case 22
    .4byte lbl_0800b414 @ case 23
    .4byte lbl_0800b414 @ case 24
    .4byte lbl_0800b414 @ case 25
    .4byte lbl_0800b414 @ case 26
    .4byte lbl_0800b414 @ case 27
    .4byte lbl_0800b414 @ case 28
    .4byte lbl_0800b414 @ case 29
    .4byte lbl_0800b414 @ case 30
    .4byte lbl_0800b414 @ case 31
    .4byte lbl_0800b414 @ case 32
    .4byte lbl_0800b414 @ case 33
    .4byte lbl_0800b3c8 @ case 34
    .4byte lbl_0800b414 @ case 35
    .4byte lbl_0800b414 @ case 36
    .4byte lbl_0800b400 @ case 37
    .4byte lbl_0800b3dc @ case 38
lbl_0800b3bc:
    ldr r1, lbl_0800b3c4 @ =0x08289084
    str r1, [sp]
    b lbl_0800b420
    .align 2, 0
lbl_0800b3c4: .4byte 0x08289084
lbl_0800b3c8:
    ldr r1, lbl_0800b3d8 @ =0x0823a504
    mov r2, sb
    ldrb r0, [r2, #4]
    lsls r0, r0, #3
    adds r0, r6, r0
    adds r0, r0, r1
    b lbl_0800b3f4
    .align 2, 0
lbl_0800b3d8: .4byte 0x0823a504
lbl_0800b3dc:
    ldr r1, lbl_0800b3ec @ =0x0823a51c
    mov r3, sb
    ldrb r0, [r3, #4]
    lsls r0, r0, #3
    adds r0, r6, r0
    adds r0, r0, r1
    b lbl_0800b3f4
    .align 2, 0
lbl_0800b3ec: .4byte 0x0823a51c
lbl_0800b3f0:
    ldr r0, lbl_0800b3fc @ =0x0823a4fc
    adds r0, r6, r0
lbl_0800b3f4:
    ldr r0, [r0]
    str r0, [sp]
    b lbl_0800b420
    .align 2, 0
lbl_0800b3fc: .4byte 0x0823a4fc
lbl_0800b400:
    mov r4, sb
    ldrb r0, [r4, #4]
    cmp r0, #0xf0
    beq lbl_0800b414
    ldr r0, lbl_0800b410 @ =0x08288f28
    str r0, [sp]
    b lbl_0800b420
    .align 2, 0
lbl_0800b410: .4byte 0x08288f28
lbl_0800b414:
    ldr r1, lbl_0800b464 @ =gScrewSpeedAnimation
    ldrb r0, [r1]
    cmp r0, #8
    bne lbl_0800b420
    ldr r2, lbl_0800b468 @ =0x082890f0
    str r2, [sp]
lbl_0800b420:
    ldr r3, lbl_0800b464 @ =gScrewSpeedAnimation
    ldrb r1, [r3, #2]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    ldr r4, [sp]
    adds r4, r4, r0
    ldr r0, [r4, #4]
    mov r1, ip
    str r0, [r1, #0x38]
    ldr r1, [r4]
    ldrb r0, [r1]
    lsls r0, r0, #5
    strh r0, [r7]
    adds r1, #1
    ldrb r0, [r1]
    lsls r0, r0, #5
    mov r2, r8
    strh r0, [r2]
    adds r1, #1
    mov r3, ip
    str r1, [r3, #0x3c]
    ldrh r0, [r7]
    adds r0, r1, r0
    str r0, [r3, #0x44]
lbl_0800b452:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800b464: .4byte gScrewSpeedAnimation
lbl_0800b468: .4byte 0x082890f0

    thumb_func_start samus_update_anim_timers_and_palette
samus_update_anim_timers_and_palette: @ 0x0800b46c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r5, r0, #0
    ldr r1, lbl_0800b4d8 @ =gSamusPaletteSize
    movs r0, #0x40
    strh r0, [r1]
    ldr r1, lbl_0800b4dc @ =gSamusWeaponInfo
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0800b48c
    subs r0, #1
    strb r0, [r1, #6]
lbl_0800b48c:
    ldrb r0, [r5, #9]
    cmp r0, #0
    beq lbl_0800b496
    subs r0, #1
    strb r0, [r5, #9]
lbl_0800b496:
    ldr r2, lbl_0800b4e0 @ =gEquipment
    ldrb r0, [r2, #0x12]
    adds r1, r0, #0
    mov r2, sp
    strb r0, [r2, #4]
    cmp r1, #1
    bne lbl_0800b554
    ldr r0, lbl_0800b4e0 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b508
    ldr r1, lbl_0800b4e4 @ =0x082383c8
    mov r8, r1
    ldr r2, lbl_0800b4e8 @ =0x08238428
    mov ip, r2
    ldr r6, lbl_0800b4ec @ =0x082384c8
    ldr r0, lbl_0800b4f0 @ =0x08238508
    mov sl, r0
    ldr r1, lbl_0800b4f4 @ =0x08238568
    str r1, [sp]
    ldr r2, lbl_0800b4f8 @ =0x08238608
    mov sb, r2
    ldr r0, lbl_0800b4fc @ =0x0823a224
    ldrb r1, [r5, #0x1d]
    lsls r1, r1, #2
    adds r0, r1, r0
    ldr r3, [r0]
    ldr r7, lbl_0800b500 @ =0x082379e8
    ldr r0, lbl_0800b504 @ =0x0823a2dc
    b lbl_0800b624
    .align 2, 0
lbl_0800b4d8: .4byte gSamusPaletteSize
lbl_0800b4dc: .4byte gSamusWeaponInfo
lbl_0800b4e0: .4byte gEquipment
lbl_0800b4e4: .4byte 0x082383c8
lbl_0800b4e8: .4byte 0x08238428
lbl_0800b4ec: .4byte 0x082384c8
lbl_0800b4f0: .4byte 0x08238508
lbl_0800b4f4: .4byte 0x08238568
lbl_0800b4f8: .4byte 0x08238608
lbl_0800b4fc: .4byte 0x0823a224
lbl_0800b500: .4byte 0x082379e8
lbl_0800b504: .4byte 0x0823a2dc
lbl_0800b508:
    ldr r0, lbl_0800b530 @ =0x08237fa8
    mov r8, r0
    ldr r1, lbl_0800b534 @ =0x08238008
    mov ip, r1
    ldr r6, lbl_0800b538 @ =0x082380a8
    ldr r2, lbl_0800b53c @ =0x082380e8
    mov sl, r2
    ldr r0, lbl_0800b540 @ =0x08238148
    str r0, [sp]
    ldr r1, lbl_0800b544 @ =0x082381e8
    mov sb, r1
    ldr r0, lbl_0800b548 @ =0x0823a1f8
    ldrb r1, [r5, #0x1d]
    lsls r1, r1, #2
    adds r0, r1, r0
    ldr r3, [r0]
    ldr r7, lbl_0800b54c @ =0x082379c8
    ldr r0, lbl_0800b550 @ =0x0823a2bc
    b lbl_0800b624
    .align 2, 0
lbl_0800b530: .4byte 0x08237fa8
lbl_0800b534: .4byte 0x08238008
lbl_0800b538: .4byte 0x082380a8
lbl_0800b53c: .4byte 0x082380e8
lbl_0800b540: .4byte 0x08238148
lbl_0800b544: .4byte 0x082381e8
lbl_0800b548: .4byte 0x0823a1f8
lbl_0800b54c: .4byte 0x082379c8
lbl_0800b550: .4byte 0x0823a2bc
lbl_0800b554:
    cmp r1, #0
    bne lbl_0800b600
    ldr r2, lbl_0800b58c @ =gEquipment
    ldrb r1, [r2, #0xf]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b5b4
    ldr r0, lbl_0800b590 @ =0x08237be8
    mov r8, r0
    ldr r1, lbl_0800b594 @ =0x08237c48
    mov ip, r1
    ldr r6, lbl_0800b598 @ =0x08237ce8
    ldr r2, lbl_0800b59c @ =0x08237d28
    mov sl, r2
    ldr r0, lbl_0800b5a0 @ =0x08237d88
    str r0, [sp]
    ldr r1, lbl_0800b5a4 @ =0x08237e28
    mov sb, r1
    ldr r0, lbl_0800b5a8 @ =0x0823a1cc
    ldrb r1, [r5, #0x1d]
    lsls r1, r1, #2
    adds r0, r1, r0
    ldr r3, [r0]
    ldr r7, lbl_0800b5ac @ =0x082379a8
    ldr r0, lbl_0800b5b0 @ =0x0823a29c
    b lbl_0800b624
    .align 2, 0
lbl_0800b58c: .4byte gEquipment
lbl_0800b590: .4byte 0x08237be8
lbl_0800b594: .4byte 0x08237c48
lbl_0800b598: .4byte 0x08237ce8
lbl_0800b59c: .4byte 0x08237d28
lbl_0800b5a0: .4byte 0x08237d88
lbl_0800b5a4: .4byte 0x08237e28
lbl_0800b5a8: .4byte 0x0823a1cc
lbl_0800b5ac: .4byte 0x082379a8
lbl_0800b5b0: .4byte 0x0823a29c
lbl_0800b5b4:
    ldr r2, lbl_0800b5dc @ =0x082376a8
    mov r8, r2
    ldr r0, lbl_0800b5e0 @ =0x08237708
    mov ip, r0
    ldr r6, lbl_0800b5e4 @ =0x082377a8
    ldr r1, lbl_0800b5e8 @ =0x082377e8
    mov sl, r1
    ldr r2, lbl_0800b5ec @ =0x08237848
    str r2, [sp]
    ldr r0, lbl_0800b5f0 @ =0x08237a68
    mov sb, r0
    ldr r0, lbl_0800b5f4 @ =0x0823a1a0
    ldrb r1, [r5, #0x1d]
    lsls r1, r1, #2
    adds r0, r1, r0
    ldr r3, [r0]
    ldr r7, lbl_0800b5f8 @ =0x08237888
    ldr r0, lbl_0800b5fc @ =0x0823a27c
    b lbl_0800b624
    .align 2, 0
lbl_0800b5dc: .4byte 0x082376a8
lbl_0800b5e0: .4byte 0x08237708
lbl_0800b5e4: .4byte 0x082377a8
lbl_0800b5e8: .4byte 0x082377e8
lbl_0800b5ec: .4byte 0x08237848
lbl_0800b5f0: .4byte 0x08237a68
lbl_0800b5f4: .4byte 0x0823a1a0
lbl_0800b5f8: .4byte 0x08237888
lbl_0800b5fc: .4byte 0x0823a27c
lbl_0800b600:
    ldr r1, lbl_0800b650 @ =0x082387e8
    mov r8, r1
    ldr r2, lbl_0800b654 @ =0x08238848
    mov ip, r2
    ldr r6, lbl_0800b658 @ =0x082388e8
    ldr r0, lbl_0800b65c @ =0x082377e8
    mov sl, r0
    ldr r1, lbl_0800b660 @ =0x08237848
    str r1, [sp]
    ldr r2, lbl_0800b664 @ =0x08238988
    mov sb, r2
    ldr r0, lbl_0800b668 @ =0x0823a250
    ldrb r1, [r5, #0x1d]
    lsls r1, r1, #2
    adds r0, r1, r0
    ldr r3, [r0]
    ldr r7, lbl_0800b66c @ =0x082378a8
    ldr r0, lbl_0800b670 @ =0x0823a2fc
lbl_0800b624:
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r0, [r5]
    adds r4, r0, #0
    cmp r4, #0x33
    bne lbl_0800b6a0
    ldr r4, lbl_0800b674 @ =0x08237888
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x10
    bl SamusCopyPalette
    ldrb r0, [r5, #7]
    cmp r0, #0
    bne lbl_0800b698
    ldrb r0, [r5, #0x1d]
    cmp r0, #0xb
    beq lbl_0800b64c
    cmp r0, #0xf
    bne lbl_0800b678
lbl_0800b64c:
    adds r4, #0x40
    b lbl_0800b7d6
    .align 2, 0
lbl_0800b650: .4byte 0x082387e8
lbl_0800b654: .4byte 0x08238848
lbl_0800b658: .4byte 0x082388e8
lbl_0800b65c: .4byte 0x082377e8
lbl_0800b660: .4byte 0x08237848
lbl_0800b664: .4byte 0x08238988
lbl_0800b668: .4byte 0x0823a250
lbl_0800b66c: .4byte 0x082378a8
lbl_0800b670: .4byte 0x0823a2fc
lbl_0800b674: .4byte 0x08237888
lbl_0800b678:
    cmp r0, #0xc
    beq lbl_0800b680
    cmp r0, #0xe
    bne lbl_0800b684
lbl_0800b680:
    adds r4, #0x80
    b lbl_0800b7d6
lbl_0800b684:
    cmp r0, #0xd
    bne lbl_0800b68c
    adds r4, #0xc0
    b lbl_0800b7d6
lbl_0800b68c:
    adds r4, #0x20
    cmp r0, #0xa
    bls lbl_0800b694
    b lbl_0800b7d6
lbl_0800b694:
    adds r4, r7, #0
    b lbl_0800b7d6
lbl_0800b698:
    ldrb r0, [r5, #7]
    lsls r0, r0, #5
    adds r4, r0, r4
    b lbl_0800b7d6
lbl_0800b6a0:
    ldrb r0, [r5, #6]
    cmp r0, #0
    beq lbl_0800b6c4
    subs r0, #1
    strb r0, [r5, #6]
    ldr r0, lbl_0800b6c0 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    adds r4, r6, #0
    adds r4, #0x20
    cmp r0, #1
    bls lbl_0800b6bc
    b lbl_0800b7c8
lbl_0800b6bc:
    adds r4, r6, #0
    b lbl_0800b7c8
    .align 2, 0
lbl_0800b6c0: .4byte gFrameCounter8Bit
lbl_0800b6c4:
    ldr r0, lbl_0800b710 @ =gSamusHazardDamage
    ldrb r2, [r0, #4]
    cmp r2, #0
    beq lbl_0800b6d4
    movs r0, #0xf
    ands r0, r2
    cmp r0, #7
    bhi lbl_0800b72c
lbl_0800b6d4:
    ldrb r0, [r5, #5]
    cmp r0, #0
    bne lbl_0800b6e0
    ldrb r0, [r5, #8]
    cmp r0, #0
    beq lbl_0800b718
lbl_0800b6e0:
    ldr r0, lbl_0800b714 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    movs r1, #6
    bl __umodsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    blt lbl_0800b6fe
    mov r4, sl
    cmp r0, #1
    ble lbl_0800b702
    adds r4, #0x20
    cmp r0, #3
    ble lbl_0800b702
lbl_0800b6fe:
    mov r4, sl
    adds r4, #0x40
lbl_0800b702:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x10
    bl SamusCopyPalette
    b lbl_0800b7d6
    .align 2, 0
lbl_0800b710: .4byte gSamusHazardDamage
lbl_0800b714: .4byte gFrameCounter8Bit
lbl_0800b718:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bne lbl_0800b732
    ldrb r1, [r5, #0x1d]
    movs r0, #1
    ands r0, r1
    mov r4, r8
    cmp r0, #0
    beq lbl_0800b7c8
lbl_0800b72c:
    adds r4, r6, #0
    adds r4, #0x20
    b lbl_0800b7c8
lbl_0800b732:
    cmp r0, #0x2c
    bne lbl_0800b748
    adds r4, r3, #0
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x10
    bl SamusCopyPalette
    mov r4, r8
    adds r4, #0x40
    b lbl_0800b7d6
lbl_0800b748:
    cmp r0, #0x2d
    bne lbl_0800b766
    ldrb r0, [r5, #0xa]
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_0800b756
    mov r4, r8
lbl_0800b756:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x10
    bl SamusCopyPalette
    mov r4, r8
    adds r4, #0x40
    b lbl_0800b7d6
lbl_0800b766:
    ldr r1, lbl_0800b780 @ =gSamusWeaponInfo
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0800b7b2
    ldr r2, lbl_0800b784 @ =gEquipment
    ldrb r1, [r2, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b788
    mov r4, ip
    adds r4, #0x40
    b lbl_0800b7c8
    .align 2, 0
lbl_0800b780: .4byte gSamusWeaponInfo
lbl_0800b784: .4byte gEquipment
lbl_0800b788:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b796
    mov r4, ip
    adds r4, #0x80
    b lbl_0800b7c8
lbl_0800b796:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b7a4
    mov r4, ip
    adds r4, #0x60
    b lbl_0800b7c8
lbl_0800b7a4:
    movs r0, #1
    ands r0, r1
    mov r4, ip
    cmp r0, #0
    beq lbl_0800b7c8
    adds r4, #0x20
    b lbl_0800b7c8
lbl_0800b7b2:
    ldrb r0, [r5, #9]
    cmp r0, #0
    beq lbl_0800b7e2
    subs r0, #5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r4, [sp]
    adds r4, #0x20
    cmp r0, #4
    bls lbl_0800b7c8
    ldr r4, [sp]
lbl_0800b7c8:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x10
    bl SamusCopyPalette
    mov r4, r8
    adds r4, #0x20
lbl_0800b7d6:
    adds r0, r4, #0
    movs r1, #0x10
    movs r2, #0x10
    bl SamusCopyPalette
    b lbl_0800b858
lbl_0800b7e2:
    mov r4, r8
    mov r1, sp
    ldrb r1, [r1, #4]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800b84e
    ldr r2, lbl_0800b814 @ =gSamusWeaponInfo
    ldrb r0, [r2, #5]
    cmp r0, #0x40
    blo lbl_0800b84e
    subs r0, #0x40
    asrs r2, r0, #2
    cmp r2, #3
    beq lbl_0800b84e
    ldr r0, lbl_0800b818 @ =gEquipment
    ldrb r1, [r0, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b81c
    mov r4, sb
    adds r4, #0x80
    b lbl_0800b846
    .align 2, 0
lbl_0800b814: .4byte gSamusWeaponInfo
lbl_0800b818: .4byte gEquipment
lbl_0800b81c:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b82c
    movs r4, #0x80
    lsls r4, r4, #1
    add r4, sb
    b lbl_0800b846
lbl_0800b82c:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b83a
    mov r4, sb
    adds r4, #0xc0
    b lbl_0800b846
lbl_0800b83a:
    movs r0, #1
    ands r0, r1
    mov r4, sb
    cmp r0, #0
    beq lbl_0800b846
    adds r4, #0x40
lbl_0800b846:
    movs r0, #1
    ands r2, r0
    lsls r0, r2, #5
    adds r4, r4, r0
lbl_0800b84e:
    adds r0, r4, #0
    movs r1, #0
    movs r2, #0x20
    bl SamusCopyPalette
lbl_0800b858:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start check_play_low_health_sound
check_play_low_health_sound: @ 0x0800b868
    push {lr}
    ldr r1, lbl_0800b898 @ =gSamusData
    ldr r0, lbl_0800b89c @ =gEquipment
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0800b894
    ldrb r0, [r1]
    cmp r0, #0x33
    beq lbl_0800b894
    ldr r0, lbl_0800b8a0 @ =gPreventMovementTimer
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0800b894
    ldr r0, lbl_0800b8a4 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0800b894
    movs r0, #0x82
    bl SoundPlay
lbl_0800b894:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800b898: .4byte gSamusData
lbl_0800b89c: .4byte gEquipment
lbl_0800b8a0: .4byte gPreventMovementTimer
lbl_0800b8a4: .4byte gFrameCounter8Bit

    thumb_func_start sub_0800b8a8
sub_0800b8a8: @ 0x0800b8a8
    push {r4, r5, lr}
    adds r5, r0, #0
    mov ip, r1
    ldr r4, lbl_0800b908 @ =0x08239464
    ldrb r1, [r5]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r4
    ldrb r1, [r0]
    ldr r3, lbl_0800b90c @ =0x0823a534
    lsls r1, r1, #3
    adds r0, r1, r3
    ldrh r0, [r0]
    mov r2, ip
    adds r2, #0x6e
    strh r0, [r2]
    adds r0, r3, #2
    adds r0, r1, r0
    ldrh r2, [r0]
    mov r0, ip
    adds r0, #0x70
    strh r2, [r0]
    adds r0, r3, #4
    adds r0, r1, r0
    ldrh r0, [r0]
    mov r2, ip
    adds r2, #0x72
    strh r0, [r2]
    adds r3, #6
    adds r1, r1, r3
    ldrh r1, [r1]
    mov r0, ip
    adds r0, #0x74
    strh r1, [r0]
    ldrb r1, [r5]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r4, #2
    adds r0, r0, r4
    ldrb r1, [r0]
    ldrb r0, [r5, #1]
    cmp r0, #1
    beq lbl_0800b900
    strb r1, [r5, #1]
lbl_0800b900:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800b908: .4byte 0x08239464
lbl_0800b90c: .4byte 0x0823a534

    thumb_func_start update_cannon_oam
update_cannon_oam: @ 0x0800b910
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r6, lbl_0800b934 @ =gSamusData
    ldr r4, lbl_0800b938 @ =gEquipment
    ldr r0, lbl_0800b93c @ =gSamusPhysics
    mov ip, r0
    ldrb r5, [r6]
    ldrb r2, [r6, #2]
    cmp r5, #0x3c
    bls lbl_0800b928
    b lbl_0800bc4c
lbl_0800b928:
    lsls r0, r5, #2
    ldr r1, lbl_0800b940 @ =lbl_0800b944
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800b934: .4byte gSamusData
lbl_0800b938: .4byte gEquipment
lbl_0800b93c: .4byte gSamusPhysics
lbl_0800b940: .4byte lbl_0800b944
lbl_0800b944: @ jump table
    .4byte lbl_0800ba38 @ case 0
    .4byte lbl_0800ba74 @ case 1
    .4byte lbl_0800ba94 @ case 2
    .4byte lbl_0800bab4 @ case 3
    .4byte lbl_0800bad4 @ case 4
    .4byte lbl_0800baf4 @ case 5
    .4byte lbl_0800bb14 @ case 6
    .4byte lbl_0800bc4c @ case 7
    .4byte lbl_0800bb34 @ case 8
    .4byte lbl_0800bb54 @ case 9
    .4byte lbl_0800bb74 @ case 10
    .4byte lbl_0800bc4c @ case 11
    .4byte lbl_0800bc4c @ case 12
    .4byte lbl_0800bc4c @ case 13
    .4byte lbl_0800bc4c @ case 14
    .4byte lbl_0800bc4c @ case 15
    .4byte lbl_0800bc4c @ case 16
    .4byte lbl_0800bc4c @ case 17
    .4byte lbl_0800bc4c @ case 18
    .4byte lbl_0800bc4c @ case 19
    .4byte lbl_0800bc4c @ case 20
    .4byte lbl_0800bc4c @ case 21
    .4byte lbl_0800bc4c @ case 22
    .4byte lbl_0800bc4c @ case 23
    .4byte lbl_0800bb94 @ case 24
    .4byte lbl_0800bbb4 @ case 25
    .4byte lbl_0800bc4c @ case 26
    .4byte lbl_0800bc4c @ case 27
    .4byte lbl_0800bc4c @ case 28
    .4byte lbl_0800bbd4 @ case 29
    .4byte lbl_0800bc4c @ case 30
    .4byte lbl_0800bc4c @ case 31
    .4byte lbl_0800bc4c @ case 32
    .4byte lbl_0800bc4c @ case 33
    .4byte lbl_0800bbf0 @ case 34
    .4byte lbl_0800bbf0 @ case 35
    .4byte lbl_0800bc4c @ case 36
    .4byte lbl_0800bc4c @ case 37
    .4byte lbl_0800bc4c @ case 38
    .4byte lbl_0800bc4c @ case 39
    .4byte lbl_0800bc00 @ case 40
    .4byte lbl_0800bc0c @ case 41
    .4byte lbl_0800bc18 @ case 42
    .4byte lbl_0800bc4c @ case 43
    .4byte lbl_0800bc4c @ case 44
    .4byte lbl_0800bc4c @ case 45
    .4byte lbl_0800bc4c @ case 46
    .4byte lbl_0800bc4c @ case 47
    .4byte lbl_0800bc4c @ case 48
    .4byte lbl_0800bc4c @ case 49
    .4byte lbl_0800bc4c @ case 50
    .4byte lbl_0800bc4c @ case 51
    .4byte lbl_0800bc4c @ case 52
    .4byte lbl_0800bc24 @ case 53
    .4byte lbl_0800bc4c @ case 54
    .4byte lbl_0800bc4c @ case 55
    .4byte lbl_0800bc4c @ case 56
    .4byte lbl_0800bc4c @ case 57
    .4byte lbl_0800bc4c @ case 58
    .4byte lbl_0800bc34 @ case 59
    .4byte lbl_0800bc40 @ case 60
lbl_0800ba38:
    cmp r2, #4
    bls lbl_0800ba42
    subs r0, r2, #2
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_0800ba42:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800ba54
    ldr r0, lbl_0800ba50 @ =0x08239fb8
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800ba50: .4byte 0x08239fb8
lbl_0800ba54:
    ldrb r0, [r6, #5]
    cmp r0, #0
    bne lbl_0800ba68
    ldr r0, lbl_0800ba64 @ =0x0823920c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800ba64: .4byte 0x0823920c
lbl_0800ba68:
    ldr r0, lbl_0800ba70 @ =0x0823922c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800ba70: .4byte 0x0823922c
lbl_0800ba74:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800ba88
    ldr r0, lbl_0800ba84 @ =0x08239fd8
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800ba84: .4byte 0x08239fd8
lbl_0800ba88:
    ldr r0, lbl_0800ba90 @ =0x0823924c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800ba90: .4byte 0x0823924c
lbl_0800ba94:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800baa8
    ldr r0, lbl_0800baa4 @ =0x08239ff8
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800baa4: .4byte 0x08239ff8
lbl_0800baa8:
    ldr r0, lbl_0800bab0 @ =0x0823926c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bab0: .4byte 0x0823926c
lbl_0800bab4:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bac8
    ldr r0, lbl_0800bac4 @ =0x0823a018
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bac4: .4byte 0x0823a018
lbl_0800bac8:
    ldr r0, lbl_0800bad0 @ =0x0823928c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bad0: .4byte 0x0823928c
lbl_0800bad4:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bae8
    ldr r0, lbl_0800bae4 @ =0x0823a038
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bae4: .4byte 0x0823a038
lbl_0800bae8:
    ldr r0, lbl_0800baf0 @ =0x082392ac
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800baf0: .4byte 0x082392ac
lbl_0800baf4:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bb08
    ldr r0, lbl_0800bb04 @ =0x0823a050
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb04: .4byte 0x0823a050
lbl_0800bb08:
    ldr r0, lbl_0800bb10 @ =0x082392c4
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb10: .4byte 0x082392c4
lbl_0800bb14:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bb28
    ldr r0, lbl_0800bb24 @ =0x0823a068
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb24: .4byte 0x0823a068
lbl_0800bb28:
    ldr r0, lbl_0800bb30 @ =0x082392dc
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb30: .4byte 0x082392dc
lbl_0800bb34:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bb48
    ldr r0, lbl_0800bb44 @ =0x0823a080
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb44: .4byte 0x0823a080
lbl_0800bb48:
    ldr r0, lbl_0800bb50 @ =0x08239304
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb50: .4byte 0x08239304
lbl_0800bb54:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bb68
    ldr r0, lbl_0800bb64 @ =0x0823a0a8
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb64: .4byte 0x0823a0a8
lbl_0800bb68:
    ldr r0, lbl_0800bb70 @ =0x0823932c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb70: .4byte 0x0823932c
lbl_0800bb74:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bb88
    ldr r0, lbl_0800bb84 @ =0x0823a0d0
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb84: .4byte 0x0823a0d0
lbl_0800bb88:
    ldr r0, lbl_0800bb90 @ =0x08239354
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bb90: .4byte 0x08239354
lbl_0800bb94:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bba8
    ldr r0, lbl_0800bba4 @ =0x0823a0f0
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bba4: .4byte 0x0823a0f0
lbl_0800bba8:
    ldr r0, lbl_0800bbb0 @ =0x08239374
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bbb0: .4byte 0x08239374
lbl_0800bbb4:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bbc8
    ldr r0, lbl_0800bbc4 @ =0x0823a118
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bbc4: .4byte 0x0823a118
lbl_0800bbc8:
    ldr r0, lbl_0800bbd0 @ =0x0823939c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bbd0: .4byte 0x0823939c
lbl_0800bbd4:
    ldrh r1, [r6, #0x10]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800bbe4
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_0800bbe4:
    ldr r0, lbl_0800bbec @ =0x082393c4
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bbec: .4byte 0x082393c4
lbl_0800bbf0:
    ldrb r2, [r6, #4]
    ldr r0, lbl_0800bbfc @ =0x082393d4
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bbfc: .4byte 0x082393d4
lbl_0800bc00:
    ldr r0, lbl_0800bc08 @ =0x082393ec
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc08: .4byte 0x082393ec
lbl_0800bc0c:
    ldr r0, lbl_0800bc14 @ =0x08239414
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc14: .4byte 0x08239414
lbl_0800bc18:
    ldr r0, lbl_0800bc20 @ =0x0823943c
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc20: .4byte 0x0823943c
lbl_0800bc24:
    ldrb r2, [r6, #4]
    ldr r0, lbl_0800bc30 @ =0x0823a188
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc30: .4byte 0x0823a188
lbl_0800bc34:
    ldr r0, lbl_0800bc3c @ =0x0823a140
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc3c: .4byte 0x0823a140
lbl_0800bc40:
    ldr r0, lbl_0800bc48 @ =0x0823a160
    lsls r1, r3, #2
    lsls r2, r2, #3
    b lbl_0800bc62
    .align 2, 0
lbl_0800bc48: .4byte 0x0823a160
lbl_0800bc4c:
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    bne lbl_0800bc5c
    ldr r0, lbl_0800bc58 @ =0x08239da0
    b lbl_0800bc5e
    .align 2, 0
lbl_0800bc58: .4byte 0x08239da0
lbl_0800bc5c:
    ldr r0, lbl_0800bcac @ =0x08238ff4
lbl_0800bc5e:
    lsls r1, r3, #2
    lsls r2, r5, #3
lbl_0800bc62:
    adds r1, r1, r2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r0, [r6, #0x1d]
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, [r1]
    movs r0, #0
    ldrsh r1, [r2, r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800bc80
    ldr r0, lbl_0800bcb0 @ =0xffffff00
    adds r1, r1, r0
lbl_0800bc80:
    mov r0, ip
    adds r0, #0x4c
    strh r1, [r0]
    adds r1, r0, #0
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    movs r0, #2
    ldrsh r1, [r2, r0]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800bca0
    ldr r0, lbl_0800bcb4 @ =0xfffffe00
    adds r1, r1, r0
lbl_0800bca0:
    mov r0, ip
    adds r0, #0x4a
    strh r1, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800bcac: .4byte 0x08238ff4
lbl_0800bcb0: .4byte 0xffffff00
lbl_0800bcb4: .4byte 0xfffffe00

    thumb_func_start SamusInit
SamusInit: @ 0x0800bcb8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_0800bd84 @ =gPauseScreenFlag
    movs r3, #0
    ldrsb r3, [r0, r3]
    ldr r5, lbl_0800bd88 @ =gGameModeSub3
    cmp r3, #0
    bne lbl_0800bd00
    ldr r2, lbl_0800bd8c @ =gSamusEcho
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0
    strh r3, [r0]
    movs r3, #0x85
    lsls r3, r3, #1
    adds r0, r2, r3
    strb r1, [r0]
    movs r2, #0
    ldr r4, lbl_0800bd90 @ =gSamusEnvironmentalEffects
    mov ip, r4
    ldr r3, lbl_0800bd94 @ =0x08238b68
lbl_0800bce8:
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    add r0, ip
    adds r1, r3, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #4
    bls lbl_0800bce8
lbl_0800bd00:
    ldrb r5, [r5]
    lsls r5, r5, #0x18
    asrs r5, r5, #0x18
    cmp r5, #0
    bne lbl_0800bdce
    ldr r0, lbl_0800bd98 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800bdbc
    str r5, [sp]
    ldr r0, lbl_0800bd9c @ =0x040000d4
    mov r6, sp
    str r6, [r0]
    ldr r4, lbl_0800bda0 @ =gSamusData
    str r4, [r0, #4]
    ldr r1, lbl_0800bda4 @ =0x85000008
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r3, lbl_0800bda8 @ =gEquipment
    str r3, [r0, #4]
    ldr r1, lbl_0800bdac @ =0x85000005
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r1, lbl_0800bdb0 @ =gSamusWeaponInfo
    str r1, [r0, #4]
    ldr r2, lbl_0800bdb4 @ =0x85000002
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r1, lbl_0800bdb8 @ =gScrewSpeedAnimation
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r2, #0
    mov r8, r3
    ldr r3, lbl_0800bd90 @ =gSamusEnvironmentalEffects
    ldr r7, lbl_0800bd94 @ =0x08238b68
    mov ip, r7
lbl_0800bd5a:
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    adds r0, r0, r3
    mov r1, ip
    ldm r1!, {r5, r6, r7}
    stm r0!, {r5, r6, r7}
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #4
    bls lbl_0800bd5a
    movs r0, #0x1e
    strb r0, [r4]
    movs r0, #0x20
    strh r0, [r4, #0xe]
    movs r0, #0x63
    mov r1, r8
    strh r0, [r1]
    strh r0, [r1, #6]
    b lbl_0800bdce
    .align 2, 0
lbl_0800bd84: .4byte gPauseScreenFlag
lbl_0800bd88: .4byte gGameModeSub3
lbl_0800bd8c: .4byte gSamusEcho
lbl_0800bd90: .4byte gSamusEnvironmentalEffects
lbl_0800bd94: .4byte 0x08238b68
lbl_0800bd98: .4byte gIsLoadingFile
lbl_0800bd9c: .4byte 0x040000d4
lbl_0800bda0: .4byte gSamusData
lbl_0800bda4: .4byte 0x85000008
lbl_0800bda8: .4byte gEquipment
lbl_0800bdac: .4byte 0x85000005
lbl_0800bdb0: .4byte gSamusWeaponInfo
lbl_0800bdb4: .4byte 0x85000002
lbl_0800bdb8: .4byte gScrewSpeedAnimation
lbl_0800bdbc:
    str r5, [sp]
    ldr r1, lbl_0800bddc @ =0x040000d4
    mov r3, sp
    str r3, [r1]
    ldr r0, lbl_0800bde0 @ =gSamusPhysics
    str r0, [r1, #4]
    ldr r0, lbl_0800bde4 @ =0x8500001e
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0800bdce:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800bddc: .4byte 0x040000d4
lbl_0800bde0: .4byte gSamusPhysics
lbl_0800bde4: .4byte 0x8500001e

    thumb_func_start SamusDraw
SamusDraw: @ 0x0800bde8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    movs r0, #2
    str r0, [sp]
    ldr r0, lbl_0800be1c @ =gSamusData
    ldrb r1, [r0]
    cmp r1, #0x33
    bne lbl_0800be2c
    movs r1, #0
    str r1, [sp]
    ldr r0, lbl_0800be20 @ =gNextOamSlot
    strb r1, [r0]
    ldr r3, lbl_0800be24 @ =gOamData
    ldr r2, lbl_0800be28 @ =gSamusEnvironmentalEffects
    adds r0, r2, #0
    adds r0, #0x30
lbl_0800be10:
    strb r1, [r0]
    subs r0, #0xc
    cmp r0, r2
    bge lbl_0800be10
    b lbl_0800be3a
    .align 2, 0
lbl_0800be1c: .4byte gSamusData
lbl_0800be20: .4byte gNextOamSlot
lbl_0800be24: .4byte gOamData
lbl_0800be28: .4byte gSamusEnvironmentalEffects
lbl_0800be2c:
    ldr r0, lbl_0800c1b8 @ =gSamusOnTopOfBackgrounds
    ldrb r0, [r0]
    ldr r3, lbl_0800c1bc @ =gOamData
    cmp r0, #0
    beq lbl_0800be3a
    movs r0, #1
    str r0, [sp]
lbl_0800be3a:
    ldr r1, lbl_0800c1c0 @ =gNextOamSlot
    ldrb r0, [r1]
    cmp r0, #0x6a
    bls lbl_0800be46
    movs r0, #0x6a
    strb r0, [r1]
lbl_0800be46:
    ldr r2, lbl_0800c1c0 @ =gNextOamSlot
    ldrb r1, [r2]
    lsls r0, r1, #3
    adds r5, r0, r3
    adds r7, r1, #0
    adds r6, r7, #0
    movs r2, #0
    ldr r3, [sp]
    str r3, [sp, #4]
lbl_0800be58:
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r1, r0, #2
    ldr r0, lbl_0800c1c4 @ =gSamusEnvironmentalEffects
    adds r3, r1, r0
    ldrb r0, [r3]
    adds r2, #1
    str r2, [sp, #8]
    cmp r0, #0
    beq lbl_0800befe
    ldr r0, lbl_0800c1c4 @ =gSamusEnvironmentalEffects
    adds r0, #8
    adds r0, r1, r0
    ldr r4, [r0]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldrh r1, [r3, #4]
    lsrs r1, r1, #2
    ldr r2, lbl_0800c1c8 @ =gBg1XPosition
    ldrh r0, [r2]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    ldrh r1, [r3, #6]
    lsrs r1, r1, #2
    ldr r3, lbl_0800c1cc @ =gBg1YPosition
    ldrh r0, [r3]
    lsrs r0, r0, #2
    subs r1, r1, r0
    adds r1, #2
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r8, r1
    cmp r6, r7
    bhs lbl_0800befe
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    mov sl, r0
    ldr r1, [sp, #4]
    lsls r1, r1, #2
    mov ip, r1
lbl_0800beb2:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_0800c1bc @ =gOamData
    adds r3, r3, r2
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    mov r0, sl
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    mov r1, ip
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800beb2
lbl_0800befe:
    ldr r2, [sp, #8]
    lsls r0, r2, #0x10
    asrs r2, r0, #0x10
    cmp r2, #4
    ble lbl_0800be58
    ldr r3, lbl_0800c1d8 @ =gSamusData
    ldrh r1, [r3, #0x12]
    lsrs r1, r1, #2
    ldr r2, lbl_0800c1c8 @ =gBg1XPosition
    ldrh r0, [r2]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    ldrh r0, [r3, #0x14]
    lsrs r0, r0, #2
    ldr r3, lbl_0800c1cc @ =gBg1YPosition
    ldrh r1, [r3]
    lsrs r1, r1, #2
    subs r0, r0, r1
    adds r0, #2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    mov r8, r0
    ldr r0, lbl_0800c1dc @ =gSamusPhysics
    adds r0, #0x36
    ldrb r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800bfa2
    ldr r0, lbl_0800c1dc @ =gSamusPhysics
    ldr r4, [r0, #0x38]
    ldrh r0, [r4]
    adds r0, r7, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    adds r4, #2
    cmp r6, r7
    bhs lbl_0800bfa2
    ldr r1, [sp]
    lsls r1, r1, #2
    mov sl, r1
    movs r2, #0xd
    rsbs r2, r2, #0
    mov ip, r2
lbl_0800bf58:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r0, lbl_0800c1bc @ =gOamData
    adds r3, r3, r0
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    mov r0, ip
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800bf58
lbl_0800bfa2:
    ldr r2, lbl_0800c1dc @ =gSamusPhysics
    ldrh r1, [r2, #0x22]
    movs r0, #0x80
    lsls r0, r0, #6
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c01a
    ldr r4, [r2, #0x24]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r6, r7
    bhs lbl_0800c01a
    ldr r3, [sp]
    lsls r3, r3, #2
    mov sl, r3
    movs r0, #0xd
    rsbs r0, r0, #0
    mov ip, r0
lbl_0800bfd0:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_0800c1bc @ =gOamData
    adds r3, r3, r2
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    mov r0, ip
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800bfd0
lbl_0800c01a:
    ldr r2, lbl_0800c1dc @ =gSamusPhysics
    ldr r4, [r2]
    ldrh r0, [r4]
    adds r0, r7, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    adds r4, #2
    cmp r6, r7
    bhs lbl_0800c082
    ldr r3, [sp]
    lsls r3, r3, #2
    mov sl, r3
    movs r0, #0xd
    rsbs r0, r0, #0
    mov ip, r0
lbl_0800c038:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_0800c1bc @ =gOamData
    adds r3, r3, r2
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    mov r0, ip
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800c038
lbl_0800c082:
    ldr r2, lbl_0800c1dc @ =gSamusPhysics
    ldrh r1, [r2, #0x22]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c0fa
    ldr r4, [r2, #0x24]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r6, r7
    bhs lbl_0800c0fa
    ldr r3, [sp]
    lsls r3, r3, #2
    mov sl, r3
    movs r0, #0xd
    rsbs r0, r0, #0
    mov ip, r0
lbl_0800c0b0:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_0800c1bc @ =gOamData
    adds r3, r3, r2
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    mov r0, ip
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800c0b0
lbl_0800c0fa:
    ldr r0, lbl_0800c1dc @ =gSamusPhysics
    adds r0, #0x36
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c17a
    ldr r2, lbl_0800c1dc @ =gSamusPhysics
    ldr r4, [r2, #0x38]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    cmp r0, #0x80
    ble lbl_0800c11c
    b lbl_0800c2aa
lbl_0800c11c:
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r6, r7
    bhs lbl_0800c17a
    ldr r0, [sp]
    lsls r0, r0, #2
    mov sl, r0
    movs r1, #0xd
    rsbs r1, r1, #0
    mov ip, r1
lbl_0800c130:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r2, lbl_0800c1bc @ =gOamData
    adds r3, r3, r2
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c1d0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c1d4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    mov r0, ip
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800c130
lbl_0800c17a:
    ldr r1, lbl_0800c1e0 @ =gSamusEcho
    ldrb r0, [r1]
    mov ip, r1
    cmp r0, #0
    bne lbl_0800c186
    b lbl_0800c2aa
lbl_0800c186:
    movs r2, #0x84
    lsls r2, r2, #1
    add r2, ip
    ldrb r1, [r1, #3]
    mov r3, ip
    ldrb r0, [r3, #2]
    muls r1, r0, r1
    ldrh r0, [r2]
    subs r0, r0, r1
    subs r0, #3
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    movs r0, #0x85
    lsls r0, r0, #1
    add r0, ip
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800c1e6
    cmp r2, #0
    bge lbl_0800c1e6
    ldr r0, lbl_0800c1c0 @ =gNextOamSlot
    strb r7, [r0]
    b lbl_0800c1e4
    .align 2, 0
lbl_0800c1b8: .4byte gSamusOnTopOfBackgrounds
lbl_0800c1bc: .4byte gOamData
lbl_0800c1c0: .4byte gNextOamSlot
lbl_0800c1c4: .4byte gSamusEnvironmentalEffects
lbl_0800c1c8: .4byte gBg1XPosition
lbl_0800c1cc: .4byte gBg1YPosition
lbl_0800c1d0: .4byte 0x000001ff
lbl_0800c1d4: .4byte 0xfffffe00
lbl_0800c1d8: .4byte gSamusData
lbl_0800c1dc: .4byte gSamusPhysics
lbl_0800c1e0: .4byte gSamusEcho
lbl_0800c1e4:
    b lbl_0800c2ae
lbl_0800c1e6:
    ldr r1, lbl_0800c200 @ =gSamusPhysics
    ldr r4, [r1]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    cmp r0, #0x80
    ble lbl_0800c208
    ldr r2, lbl_0800c204 @ =gNextOamSlot
    strb r7, [r2]
    b lbl_0800c2ae
    .align 2, 0
lbl_0800c200: .4byte gSamusPhysics
lbl_0800c204: .4byte gNextOamSlot
lbl_0800c208:
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    movs r0, #0x3f
    ands r2, r0
    lsls r2, r2, #1
    mov r0, ip
    adds r0, #8
    adds r0, r2, r0
    ldrh r1, [r0]
    lsrs r1, r1, #2
    ldr r3, lbl_0800c2c0 @ =gBg1XPosition
    ldrh r0, [r3]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    mov r0, ip
    adds r0, #0x88
    adds r2, r2, r0
    ldrh r0, [r2]
    lsrs r0, r0, #2
    ldr r2, lbl_0800c2c4 @ =gBg1YPosition
    ldrh r1, [r2]
    lsrs r1, r1, #2
    subs r0, r0, r1
    adds r0, #2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    mov r8, r0
    cmp r6, r7
    bhs lbl_0800c29e
    ldr r3, [sp]
    lsls r3, r3, #2
    mov sl, r3
lbl_0800c24a:
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    lsls r3, r6, #3
    ldr r0, lbl_0800c2c8 @ =gOamData
    adds r3, r3, r0
    mov r2, r8
    adds r0, r1, r2
    strb r0, [r3]
    ldrh r1, [r4]
    adds r4, #2
    strh r1, [r5]
    adds r5, #2
    add r1, sb
    ldr r0, lbl_0800c2cc @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0800c2d0 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r4]
    strh r0, [r5]
    adds r4, #2
    ldrb r1, [r3, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    mov r1, sl
    orrs r0, r1
    movs r1, #0xf
    ands r0, r1
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r3, #5]
    adds r5, #4
    adds r0, r6, #1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, r7
    blo lbl_0800c24a
lbl_0800c29e:
    mov r2, ip
    ldrb r0, [r2, #2]
    adds r0, #1
    movs r1, #3
    ands r0, r1
    strb r0, [r2, #2]
lbl_0800c2aa:
    ldr r3, lbl_0800c2d4 @ =gNextOamSlot
    strb r7, [r3]
lbl_0800c2ae:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c2c0: .4byte gBg1XPosition
lbl_0800c2c4: .4byte gBg1YPosition
lbl_0800c2c8: .4byte gOamData
lbl_0800c2cc: .4byte 0x000001ff
lbl_0800c2d0: .4byte 0xfffffe00
lbl_0800c2d4: .4byte gNextOamSlot
