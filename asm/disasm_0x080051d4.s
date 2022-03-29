    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_080051d4
sub_080051d4: @ 0x080051d4
    push {r4, lr}
    adds r4, r0, #0
    subs r3, r2, #1
    cmp r2, #0
    beq lbl_080051f0
    movs r2, #1
    rsbs r2, r2, #0
lbl_080051e2:
    ldrb r0, [r4]
    strb r0, [r1]
    adds r4, #1
    adds r1, #1
    subs r3, #1
    cmp r3, r2
    bne lbl_080051e2
lbl_080051f0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080051f8
sub_080051f8: @ 0x080051f8
    push {r4, r5, r6, lr}
    sub sp, #0x80
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r2, lbl_08005224 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_08005228 @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    ldr r3, lbl_0800522c @ =sub_080051d4
    movs r0, #1
    bics r3, r0
    mov r2, sp
    ldr r0, lbl_08005230 @ =sub_080051f8
    ldr r1, lbl_0800522c @ =sub_080051d4
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b lbl_08005240
    .align 2, 0
lbl_08005224: .4byte 0x04000204
lbl_08005228: .4byte 0x0000fffc
lbl_0800522c: .4byte sub_080051d4
lbl_08005230: .4byte sub_080051f8
lbl_08005234:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
lbl_08005240:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne lbl_08005234
    mov r3, sp
    adds r3, #1
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl _call_via_r3
    add sp, #0x80
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_0800525c
sub_0800525c: @ 0x0800525c
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r3, r2, #0
    ldr r2, lbl_08005294 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_08005298 @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    subs r3, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, r0
    beq lbl_0800528c
    adds r1, r0, #0
lbl_0800527e:
    ldrb r0, [r5]
    strb r0, [r4]
    adds r5, #1
    adds r4, #1
    subs r3, #1
    cmp r3, r1
    bne lbl_0800527e
lbl_0800528c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08005294: .4byte 0x04000204
lbl_08005298: .4byte 0x0000fffc

    thumb_func_start sub_0800529c
sub_0800529c: @ 0x0800529c
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r3, r1, #0
    subs r4, r2, #1
    cmp r2, #0
    beq lbl_080052c2
    movs r2, #1
    rsbs r2, r2, #0
lbl_080052ac:
    ldrb r1, [r3]
    ldrb r0, [r5]
    adds r5, #1
    adds r3, #1
    cmp r1, r0
    beq lbl_080052bc
    subs r0, r3, #1
    b lbl_080052c4
lbl_080052bc:
    subs r4, #1
    cmp r4, r2
    bne lbl_080052ac
lbl_080052c2:
    movs r0, #0
lbl_080052c4:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080052cc
sub_080052cc: @ 0x080052cc
    push {r4, r5, r6, lr}
    sub sp, #0xc0
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r2, lbl_080052f8 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_080052fc @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    ldr r3, lbl_08005300 @ =sub_0800529c
    movs r0, #1
    bics r3, r0
    mov r2, sp
    ldr r0, lbl_08005304 @ =sub_080052cc
    ldr r1, lbl_08005300 @ =sub_0800529c
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b lbl_08005314
    .align 2, 0
lbl_080052f8: .4byte 0x04000204
lbl_080052fc: .4byte 0x0000fffc
lbl_08005300: .4byte sub_0800529c
lbl_08005304: .4byte sub_080052cc
lbl_08005308:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
lbl_08005314:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne lbl_08005308
    mov r3, sp
    adds r3, #1
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl _call_via_r3
    add sp, #0xc0
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sub_08005330
sub_08005330: @ 0x08005330
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    adds r5, r1, #0
    adds r4, r2, #0
    movs r7, #0
    b lbl_08005342
lbl_0800533c:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08005342:
    cmp r7, #2
    bhi lbl_08005360
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl sub_0800525c
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl sub_080052cc
    adds r3, r0, #0
    cmp r3, #0
    bne lbl_0800533c
lbl_08005360:
    adds r0, r3, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

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
    ldr r0, lbl_08005418 @ =0x03001530
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
    bl samus_apply_screw_speedbooster_damage_to_environment
    mov r0, r8
    adds r1, r4, #0
    adds r2, r6, #0
    bl samus_apply_screw_speedbooster_damage_to_environment
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
    bl samus_apply_screw_speedbooster_damage_to_environment
lbl_0800540c:
    mov r0, r8
    adds r1, r5, #0
    adds r2, r6, #0
    bl samus_apply_screw_speedbooster_damage_to_environment
    b lbl_0800543e
    .align 2, 0
lbl_08005418: .4byte 0x03001530
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
    bl samus_apply_screw_speedbooster_damage_to_environment
lbl_08005434:
    mov r0, sb
    adds r1, r5, #0
    adds r2, r6, #0
    bl samus_apply_screw_speedbooster_damage_to_environment
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
    bl samus_apply_screw_speedbooster_damage_to_environment
    mov r0, r8
    adds r1, r5, #0
    adds r2, r6, #0
    bl samus_apply_screw_speedbooster_damage_to_environment
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    ldr r0, lbl_08005898 @ =0x03001588
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
lbl_08005898: .4byte 0x03001588
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
    ldr r0, lbl_080059a0 @ =0x030013f4
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
lbl_080059a0: .4byte 0x030013f4
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
    ldr r7, lbl_08005b54 @ =0x03001600
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
lbl_08005b54: .4byte 0x03001600
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

    thumb_func_start samus_check_landing_collision
samus_check_landing_collision: @ 0x08005c4c
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
    ldr r0, lbl_08005d30 @ =0x03001602
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
lbl_08005d30: .4byte 0x03001602
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

    thumb_func_start samus_check_top_collision
samus_check_top_collision: @ 0x08005e1c
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
    ldr r1, lbl_08005ef8 @ =0x03001600
    strh r0, [r1]
    b lbl_08005f24
    .align 2, 0
lbl_08005ef4: .4byte 0x0000ffc0
lbl_08005ef8: .4byte 0x03001600
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

    thumb_func_start samus_check_collisions
samus_check_collisions: @ 0x08005f38
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
    bl samus_check_top_collision
    b lbl_08005fc6
lbl_08005f72:
    cmp r0, #2
    bne lbl_08005f80
    adds r0, r5, #0
    mov r1, sb
    bl samus_check_landing_collision
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
    bl samus_check_landing_collision
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
    ldr r2, lbl_080060b8 @ =0x03001530
    ldrb r1, [r2, #0xf]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080060dc
    ldr r0, lbl_080060bc @ =0x0300137c
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
    bl sub_08057df8
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_080060dc
    ldrh r0, [r5, #0x14]
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl sub_08057df8
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
    bl check_hazard_at_pos
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
    ldr r2, lbl_080060b8 @ =0x03001530
    ldrb r0, [r2, #0x12]
    cmp r0, #2
    bne lbl_080060c0
    movs r0, #0x3d
    mov sl, r0
    movs r0, #0x9b
    bl play_sound1
    b lbl_080060dc
    .align 2, 0
lbl_080060b8: .4byte 0x03001530
lbl_080060bc: .4byte 0x0300137c
lbl_080060c0:
    movs r1, #0x15
    mov sl, r1
    mov r0, sb
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080060d6
    movs r0, #0x95
    bl play_sound1
    b lbl_080060dc
lbl_080060d6:
    movs r0, #0x7a
    bl play_sound1
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
    ldr r0, lbl_080061c8 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080061e2
    ldr r0, lbl_080061cc @ =0x030013f4
    ldrb r0, [r0, #0xa]
    cmp r0, #1
    bne lbl_080061e2
    movs r2, #0x34
    mov sl, r2
    b lbl_080061e2
    .align 2, 0
lbl_080061c8: .4byte 0x03001530
lbl_080061cc: .4byte 0x030013f4
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
    bl samus_set_pose
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
    ldr r0, lbl_08006270 @ =0x03001588
    mov sl, r0
    movs r7, #0
    movs r2, #1
    str r2, [sp, #4]
    cmp r1, #0
    bne lbl_08006278
    movs r3, #0
    str r3, [sp, #8]
    ldr r1, lbl_08006274 @ =0x0300154c
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
lbl_08006270: .4byte 0x03001588
lbl_08006274: .4byte 0x0300154c
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
    bl check_for_ground_effect_clipdata
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
    ldr r0, lbl_08006300 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08006304
    movs r0, #0xa1
    bl play_sound1
    b lbl_08006366
    .align 2, 0
lbl_08006300: .4byte 0x03001530
lbl_08006304:
    movs r0, #0x68
    bl play_sound1
    b lbl_08006366
lbl_0800630c:
    ldr r0, lbl_0800631c @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08006320
    movs r0, #0xa2
    bl play_sound1
    b lbl_08006366
    .align 2, 0
lbl_0800631c: .4byte 0x03001530
lbl_08006320:
    movs r0, #0x69
    bl play_sound1
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
    bl play_sound1
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
    bl play_sound1
    b lbl_08006366
lbl_08006360:
    movs r0, #0x67
    bl play_sound1
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
    bl check_for_ground_effect_clipdata
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080063a8
    movs r3, #0xc
    str r3, [sp]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r0, lbl_0800639c @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080063a0
    movs r0, #0xa3
    bl play_sound1
    b lbl_0800641a
    .align 2, 0
lbl_0800639c: .4byte 0x03001530
lbl_080063a0:
    movs r0, #0x74
    bl play_sound1
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
    bl play_sound1
    b lbl_0800641a
lbl_080063d8:
    mov r0, sl
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080063ea
    movs r0, #0x95
    bl play_sound1
    b lbl_0800641a
lbl_080063ea:
    ldr r0, lbl_080063fc @ =0x030013f4
    ldrh r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_08006400
    movs r0, #0x72
    bl play_sound1
    b lbl_0800641a
    .align 2, 0
lbl_080063fc: .4byte 0x030013f4
lbl_08006400:
    ldr r0, lbl_08006410 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08006414
    movs r0, #0x71
    bl play_sound1
    b lbl_0800641a
    .align 2, 0
lbl_08006410: .4byte 0x03001530
lbl_08006414:
    movs r0, #0x99
    bl play_sound1
lbl_0800641a:
    ldrh r3, [r6, #0x12]
    mov r8, r3
    ldrh r4, [r6, #0x14]
    b lbl_080065b4
lbl_08006422:
    ldrh r0, [r6, #0x14]
    str r0, [sp, #0xc]
    ldr r0, lbl_08006474 @ =0x03001602
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
    bl check_hazard_at_pos
    adds r5, r0, #0
    movs r4, #0xff
    ands r5, r4
    ldrh r1, [r6, #0x12]
    mov r0, sl
    bl check_hazard_at_pos
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
lbl_08006474: .4byte 0x03001602
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
    ldr r1, lbl_080064fc @ =0x0300006c
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08006500
    adds r4, r0, #0
    b lbl_080065b4
    .align 2, 0
lbl_080064fc: .4byte 0x0300006c
lbl_08006500:
    ldr r1, [sp, #0xc]
    cmp r1, sl
    bhs lbl_08006510
    ldr r0, lbl_0800650c @ =0x03001602
    ldrh r0, [r0]
    b lbl_08006512
    .align 2, 0
lbl_0800650c: .4byte 0x03001602
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
    bl play_sound1
    b lbl_080065b4
lbl_0800655e:
    ldrh r0, [r6, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r6, #0x12]
    bl check_for_ground_effect_clipdata
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
    bl check_for_ground_effect_clipdata
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
    ldr r0, lbl_080065ec @ =0x0300154c
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
lbl_080065ec: .4byte 0x0300154c

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
    ldr r4, lbl_0800661c @ =0x03001588
    ldr r6, lbl_08006620 @ =0x0300154c
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
lbl_0800661c: .4byte 0x03001588
lbl_08006620: .4byte 0x0300154c
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
    bl check_hazard_at_pos
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
    bl check_hazard_at_pos
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
    bl check_hazard_at_pos
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
    bl check_hazard_at_pos
    adds r2, r0, #0
    movs r0, #0xff
    ands r2, r0
    movs r3, #0
    cmp r5, #2
    bne lbl_080067d8
    cmp r7, #2
    beq lbl_080067d8
    ldr r0, lbl_080067d4 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0800680a
    movs r3, #0xa
    str r3, [sp]
    b lbl_0800680e
    .align 2, 0
lbl_080067d4: .4byte 0x03001530
lbl_080067d8:
    cmp r5, #3
    bne lbl_080067f8
    cmp r7, #3
    beq lbl_080067f8
    ldr r0, lbl_080067f4 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_0800680a
    movs r0, #0xa
    str r0, [sp]
    b lbl_08006804
    .align 2, 0
lbl_080067f4: .4byte 0x03001530
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
    ldr r0, lbl_0800682c @ =0x0300006c
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_08006830
    strh r0, [r6, #6]
    b lbl_0800684c
    .align 2, 0
lbl_0800682c: .4byte 0x0300006c
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
    bl play_sound1
lbl_08006852:
    ldr r6, lbl_080068b8 @ =0x0300154c
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
lbl_080068b8: .4byte 0x0300154c
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
    bl play_sound1
    b lbl_08006934
lbl_0800690a:
    ldrb r0, [r6, #2]
    cmp r0, #1
    bne lbl_08006934
    movs r0, #0x74
    bl play_sound1
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

    thumb_func_start samus_update_jump_velocity
samus_update_jump_velocity: @ 0x08006950
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r6, lbl_08006978 @ =0x03001530
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
lbl_08006978: .4byte 0x03001530
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
    ldr r0, lbl_08006ac4 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006ac8
    movs r0, #0x74
    strh r0, [r4, #0x18]
    movs r0, #0x95
    bl play_sound1
    b lbl_08006bc2
    .align 2, 0
lbl_08006ac4: .4byte 0x03001588
lbl_08006ac8:
    ldrb r0, [r2, #0x12]
    cmp r0, #2
    beq lbl_08006ad6
    movs r0, #0x76
    bl play_sound1
    b lbl_08006bc2
lbl_08006ad6:
    movs r0, #0x9a
    bl play_sound1
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
    ldr r0, lbl_08006b98 @ =0x0300137c
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
lbl_08006b98: .4byte 0x0300137c
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
    ldr r0, lbl_08006be8 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08006c12
    movs r1, #0x18
    ldrsh r0, [r4, r1]
    cmp r0, #0xc0
    bne lbl_08006bec
    movs r0, #0x6e
    bl play_sound1
    b lbl_08006c26
    .align 2, 0
lbl_08006be8: .4byte 0x03001588
lbl_08006bec:
    cmp r0, #0xe8
    bne lbl_08006bf8
    movs r0, #0x6f
    bl play_sound1
    b lbl_08006c26
lbl_08006bf8:
    cmp r0, #0xd4
    bne lbl_08006c26
    movs r0, #0x9d
    bl play_sound1
    b lbl_08006c26
lbl_08006c04:
    cmp r0, #0x14
    bne lbl_08006c26
    ldr r0, lbl_08006c1c @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006c20
lbl_08006c12:
    movs r0, #0x94
    bl play_sound1
    b lbl_08006c26
    .align 2, 0
lbl_08006c1c: .4byte 0x03001588
lbl_08006c20:
    movs r0, #0x70
    bl play_sound1
lbl_08006c26:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start samus_set_landing_pose
samus_set_landing_pose: @ 0x08006c2c
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
    ldr r0, lbl_08006d74 @ =0x0300137c
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08006d80
    ldr r0, lbl_08006d78 @ =0x03001530
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
lbl_08006d74: .4byte 0x0300137c
lbl_08006d78: .4byte 0x03001530
lbl_08006d7c: .4byte 0x0823a554
lbl_08006d80:
    movs r0, #0x18
    ldrsh r1, [r5, r0]
    movs r0, #0xc0
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_08006db8
    ldr r0, lbl_08006db4 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08006db8
    ldrh r0, [r4, #0x14]
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r4, #0x12]
    bl check_for_ground_effect_clipdata
    cmp r0, #3
    beq lbl_08006db8
    movs r0, #1
    strb r0, [r4, #4]
    movs r0, #0x32
    strh r0, [r4, #0x18]
    b lbl_08006e54
    .align 2, 0
lbl_08006db4: .4byte 0x03001588
lbl_08006db8:
    movs r0, #0x11
    b lbl_08006e52
lbl_08006dbc:
    ldr r0, lbl_08006dd4 @ =0x0300137c
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
lbl_08006dd4: .4byte 0x0300137c
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
    bl play_sound1
    b lbl_08006e54
lbl_08006e04:
    movs r0, #0x1e
    movs r1, #1
    bl start_horizontal_screen_shake
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
    bl play_sound1
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
    ldr r0, lbl_08006e80 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08006e90
    movs r0, #1
    strb r0, [r4, #0x1d]
    b lbl_08006e90
    .align 2, 0
lbl_08006e80: .4byte 0x03001588
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

    thumb_func_start samus_set_hurt_pose
samus_set_hurt_pose: @ 0x08006eac
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r0, lbl_08006ed4 @ =0x03001530
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
lbl_08006ed4: .4byte 0x03001530
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
    bl play_sound1
    b lbl_0800701e
    .align 2, 0
lbl_08006fdc: .4byte 0x0823a554
lbl_08006fe0:
    ldr r0, lbl_08007034 @ =0x0300003d
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_08007038 @ =0x03000029
    strb r1, [r0]
    movs r0, #0x33
    strb r0, [r4]
    ldr r1, lbl_0800703c @ =0x030013b8
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
    ldr r1, lbl_08007040 @ =0x030013ba
    subs r2, #0x50
    adds r0, r2, #0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldrh r1, [r4, #0x14]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    asrs r0, r0, #0x14
    strh r0, [r4, #0x18]
    ldr r1, lbl_08007044 @ =0x03000c72
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
lbl_08007034: .4byte 0x0300003d
lbl_08007038: .4byte 0x03000029
lbl_0800703c: .4byte 0x030013b8
lbl_08007040: .4byte 0x030013ba
lbl_08007044: .4byte 0x03000c72

    thumb_func_start samus_set_knockback_pose
samus_set_knockback_pose: @ 0x08007048
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

    thumb_func_start samus_turn_around_arm_cannon
samus_turn_around_arm_cannon: @ 0x08007164
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
    ldr r0, lbl_080072b0 @ =0x0300137c
    ldr r2, lbl_080072b4 @ =0x0300168c
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
lbl_080072b0: .4byte 0x0300137c
lbl_080072b4: .4byte 0x0300168c
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
    ldr r0, lbl_080072fc @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    strb r0, [r4, #0xa]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08007300
    movs r0, #0x94
    bl play_sound1
    b lbl_0800731a
    .align 2, 0
lbl_080072fc: .4byte 0x03001588
lbl_08007300:
    ldr r0, lbl_08007310 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08007314
    movs r0, #0x7b
    bl play_sound1
    b lbl_0800731a
    .align 2, 0
lbl_08007310: .4byte 0x03001530
lbl_08007314:
    movs r0, #0x9c
    bl play_sound1
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
    bl play_sound1
    b lbl_080074e2
lbl_08007340:
    movs r0, #0x32
    strb r0, [r4, #8]
    movs r0, #0x8e
    bl play_sound1
    b lbl_080074e2
lbl_0800734c:
    ldrb r0, [r5, #4]
    cmp r0, #0xf0
    beq lbl_080073d8
    ldr r0, lbl_08007374 @ =0x0300137c
    ldr r1, lbl_08007378 @ =0x0300168c
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
lbl_08007374: .4byte 0x0300137c
lbl_08007378: .4byte 0x0300168c
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
    ldr r1, lbl_080073f0 @ =0x03001528
    movs r0, #1
    strb r0, [r1]
    b lbl_080074e2
    .align 2, 0
lbl_080073f0: .4byte 0x03001528
lbl_080073f4:
    ldrb r0, [r5, #4]
    strb r0, [r4, #4]
    movs r0, #1
    strb r0, [r4, #0x1d]
lbl_080073fc:
    movs r0, #0x30
    strb r0, [r4, #6]
    movs r0, #0x90
    bl play_sound1
    b lbl_080074e2
lbl_08007408:
    ldrb r0, [r5, #4]
    cmp r0, #0xf0
    bne lbl_08007412
    strb r0, [r4, #4]
    b lbl_08007418
lbl_08007412:
    ldr r1, lbl_08007420 @ =0x03001528
    movs r0, #1
    strb r0, [r1]
lbl_08007418:
    movs r0, #0x8f
    bl play_sound1
    b lbl_080074e2
    .align 2, 0
lbl_08007420: .4byte 0x03001528
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
    ldr r1, lbl_08007454 @ =0x0300141c
    strb r0, [r1]
    strb r0, [r1, #1]
    b lbl_080074e2
    .align 2, 0
lbl_08007450: .4byte 0x0000ffc0
lbl_08007454: .4byte 0x0300141c
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
    bl play_sound1
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
    ldr r0, lbl_080074a4 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_080074a8
    movs r0, #0x9b
    bl play_sound1
    b lbl_080074e2
    .align 2, 0
lbl_080074a4: .4byte 0x03001530
lbl_080074a8:
    movs r0, #0x7a
    bl play_sound1
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

    thumb_func_start samus_set_pose
samus_set_pose: @ 0x080074e8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    ldr r5, lbl_08007524 @ =0x030013d4
    ldr r6, lbl_08007528 @ =0x030013f4
    ldr r7, lbl_0800752c @ =0x03001414
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
    bl samus_copy_data
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
lbl_08007524: .4byte 0x030013d4
lbl_08007528: .4byte 0x030013f4
lbl_0800752c: .4byte 0x03001414
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
    bl play_sound2
    b lbl_08007562
lbl_0800754c:
    cmp r4, #0x26
    beq lbl_08007562
    movs r0, #0x8f
    bl play_sound2
    b lbl_08007562
lbl_08007558:
    cmp r4, #0x27
    beq lbl_08007562
    movs r0, #0x8f
    bl play_sound2
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
    bl samus_update_jump_velocity
    b lbl_080075b4
lbl_08007584:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl samus_set_landing_pose
    b lbl_080075b4
lbl_08007590:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl samus_set_hurt_pose
    b lbl_080075b4
lbl_0800759c:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl samus_set_knockback_pose
    b lbl_080075b4
lbl_080075a8:
    strb r4, [r5]
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl samus_turn_around_arm_cannon
lbl_080075b4:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start samus_copy_data
samus_copy_data: @ 0x080075bc
    push {r4, r5, r6, lr}
    ldr r2, lbl_08007610 @ =0x030013d4
    ldr r3, lbl_08007614 @ =0x03001528
    ldr r0, lbl_08007618 @ =0x030013f4
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
lbl_08007610: .4byte 0x030013d4
lbl_08007614: .4byte 0x03001528
lbl_08007618: .4byte 0x030013f4

    thumb_func_start samus_update_physics
samus_update_physics: @ 0x0800761c
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_08007644 @ =0x030013d4
    ldr r7, lbl_08007648 @ =0x03001530
    ldr r4, lbl_0800764c @ =0x03001588
    ldr r1, lbl_08007650 @ =0x03004fc9
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
lbl_08007644: .4byte 0x030013d4
lbl_08007648: .4byte 0x03001530
lbl_0800764c: .4byte 0x03001588
lbl_08007650: .4byte 0x03004fc9
lbl_08007654:
    ldrh r0, [r6, #0x14]
lbl_08007656:
    movs r5, #0
    ldrh r1, [r6, #0x12]
    bl check_hazard_at_pos
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
    ldr r0, lbl_080076cc @ =0x03001530
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
lbl_080076cc: .4byte 0x03001530
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

    thumb_func_start samus_change_velocity_on_slope
samus_change_velocity_on_slope: @ 0x0800772c
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

    thumb_func_start samus_copy_palette
samus_copy_palette: @ 0x08007770
    push {r4, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    adds r2, r3, r2
    cmp r3, r2
    bge lbl_08007792
    ldr r1, lbl_08007798 @ =0x030053e0
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
lbl_08007798: .4byte 0x030053e0

    thumb_func_start samus_update
samus_update: @ 0x0800779c
    push {r4, lr}
    ldr r4, lbl_080077dc @ =0x030013d4
    ldr r0, lbl_080077e0 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #1
    ble lbl_080077b0
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
lbl_080077b0:
    adds r0, r4, #0
    bl samus_update_physics
    adds r0, r4, #0
    bl samus_execute_pose
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xff
    beq lbl_080077c8
    bl samus_set_pose
lbl_080077c8:
    ldr r1, lbl_080077e4 @ =0x03001588
    adds r0, r4, #0
    bl sub_0800b8a8
    adds r0, r4, #0
    bl samus_update_velocity_pos
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080077dc: .4byte 0x030013d4
lbl_080077e0: .4byte 0x03000c72
lbl_080077e4: .4byte 0x03001588

    thumb_func_start samus_update_hitbox
samus_update_hitbox: @ 0x080077e8
    push {r4, r5, lr}
    ldr r5, lbl_08007818 @ =0x030013d4
    ldr r4, lbl_0800781c @ =0x03001588
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
    ldr r0, lbl_08007820 @ =0x03001600
    ldrh r1, [r5, #0x12]
    ldrh r0, [r0]
    cmp r1, r0
    bls lbl_08007824
    movs r0, #2
    b lbl_0800782a
    .align 2, 0
lbl_08007818: .4byte 0x030013d4
lbl_0800781c: .4byte 0x03001588
lbl_08007820: .4byte 0x03001600
lbl_08007824:
    cmp r1, r0
    bhs lbl_0800782c
    movs r0, #1
lbl_0800782a:
    strb r0, [r2]
lbl_0800782c:
    ldr r0, lbl_08007848 @ =0x03004fc9
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800785c
    ldr r0, lbl_0800784c @ =0x03001602
    ldrh r1, [r5, #0x14]
    ldrh r0, [r0]
    cmp r1, r0
    bls lbl_08007850
    adds r1, r4, #0
    adds r1, #0x4f
    movs r0, #2
    b lbl_0800785a
    .align 2, 0
lbl_08007848: .4byte 0x03004fc9
lbl_0800784c: .4byte 0x03001602
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
    bl samus_check_collisions
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_0800b8a8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080078d8: .4byte 0x08239464
lbl_080078dc: .4byte 0x0823a554

    thumb_func_start samus_graphics_update
samus_graphics_update: @ 0x080078e0
    push {r4, lr}
    ldr r4, lbl_08007914 @ =0x030013d4
    ldr r0, lbl_08007918 @ =0x03000c72
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
    bl samus_update_graphics_oam
    adds r0, r4, #0
    bl samus_update_anim_timers_and_palette
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08007914: .4byte 0x030013d4
lbl_08007918: .4byte 0x03000c72

    thumb_func_start call_check_low_health
call_check_low_health: @ 0x0800791c
    push {lr}
    bl check_play_low_health_sound
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start call_update_arm_cannon
call_update_arm_cannon: @ 0x08007928
    push {lr}
    ldr r0, lbl_08007944 @ =0x030013d4
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
lbl_08007944: .4byte 0x030013d4

    thumb_func_start samus_bombjump
samus_bombjump: @ 0x08007948
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_0800799c @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08007996
    movs r3, #0
    movs r0, #0x7f
    ands r0, r2
    cmp r0, #9
    bls lbl_08007984
    ldr r1, lbl_080079a0 @ =0x030013d4
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
    ldr r1, lbl_080079a0 @ =0x030013d4
    movs r0, #0x7f
    ands r0, r2
    strb r0, [r1, #4]
    movs r0, #0xfe
    bl samus_set_pose
lbl_08007996:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800799c: .4byte 0x03001588
lbl_080079a0: .4byte 0x030013d4

    thumb_func_start samus_update_aim
samus_update_aim: @ 0x080079a4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r5, lbl_080079cc @ =0x03001414
    ldr r2, lbl_080079d0 @ =0x0300137c
    ldr r0, lbl_080079d4 @ =0x0300168c
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
lbl_080079cc: .4byte 0x03001414
lbl_080079d0: .4byte 0x0300137c
lbl_080079d4: .4byte 0x0300168c
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
    ldr r0, lbl_08007c50 @ =0x03001530
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
lbl_08007c50: .4byte 0x03001530
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

    thumb_func_start samus_fire_beam_missile
samus_fire_beam_missile: @ 0x08007cf8
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
    ldr r0, lbl_08007d30 @ =0x03001380
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
lbl_08007d30: .4byte 0x03001380
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
    ldr r0, lbl_08007d78 @ =0x0300137c
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
lbl_08007d78: .4byte 0x0300137c
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
    ldr r0, lbl_08007df8 @ =0x03001380
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
lbl_08007df8: .4byte 0x03001380
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

    thumb_func_start samus_check_new_projectile
samus_check_new_projectile: @ 0x08007e20
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    ldr r5, lbl_08007e48 @ =0x03001588
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
lbl_08007e48: .4byte 0x03001588
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
    bl samus_fire_beam_missile
lbl_08008008:
    adds r1, r5, #0
    adds r1, #0x5c
    strb r0, [r1]
    b lbl_08008054
lbl_08008010:
    ldr r0, lbl_08008040 @ =0x03001380
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
lbl_08008040: .4byte 0x03001380
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
    ldr r0, lbl_0800807c @ =0x03001380
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
lbl_0800807c: .4byte 0x03001380

    thumb_func_start samus_set_highlighted_weapon
samus_set_highlighted_weapon: @ 0x08008080
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
    ldr r0, lbl_080080cc @ =0x03001380
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
    bl play_sound1
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
lbl_080080cc: .4byte 0x03001380
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
    ldr r0, lbl_08008174 @ =0x0300137c
    ldr r1, lbl_08008178 @ =0x0300168c
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
lbl_08008174: .4byte 0x0300137c
lbl_08008178: .4byte 0x0300168c
lbl_0800817c:
    ldr r0, lbl_0800819c @ =0x0300137c
    ldr r1, lbl_080081a0 @ =0x0300168c
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
lbl_0800819c: .4byte 0x0300137c
lbl_080081a0: .4byte 0x0300168c
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
    bl play_sound1
lbl_080081b8:
    strb r6, [r4, #2]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start samus_set_spinning_pose
samus_set_spinning_pose: @ 0x080081c0
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
    ldr r0, lbl_080081fc @ =0x03001588
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
lbl_080081fc: .4byte 0x03001588
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
    ldr r0, lbl_08008230 @ =0x03001588
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
lbl_08008230: .4byte 0x03001588
lbl_08008234:
    ldr r0, lbl_08008248 @ =0x03001588
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
lbl_08008248: .4byte 0x03001588
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
    ldr r1, lbl_08008274 @ =0x03001528
    movs r0, #0
    strb r0, [r1]
lbl_08008270:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08008274: .4byte 0x03001528

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
    bl check_hazard_at_pos
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
    bl play_sound1
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
    bl play_sound1
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
    bl play_sound1
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
    bl play_sound2
lbl_08008470:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start samus_inactivity
samus_inactivity: @ 0x08008478
    movs r0, #0xff
    bx lr

    thumb_func_start sub_0800847c
sub_0800847c: @ 0x0800847c
    push {r4, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_08008490 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008498
    ldr r1, lbl_08008494 @ =0x082399b0
    b lbl_0800849a
    .align 2, 0
lbl_08008490: .4byte 0x03001530
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

    thumb_func_start samus_running
samus_running: @ 0x080084dc
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_080084f4 @ =0x03001380
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
lbl_080084f4: .4byte 0x03001380
lbl_080084f8:
    ldr r2, lbl_08008528 @ =0x03001588
    adds r0, r2, #0
    adds r0, #0x60
    movs r1, #0
    ldrsh r5, [r0, r1]
    ldr r0, lbl_0800852c @ =0x03001530
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
lbl_08008528: .4byte 0x03001588
lbl_0800852c: .4byte 0x03001530
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
    ldr r0, lbl_0800857c @ =0x0300137c
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
lbl_0800857c: .4byte 0x0300137c
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

    thumb_func_start samus_running_gfx
samus_running_gfx: @ 0x080085b0
    push {r4, r5, lr}
    adds r2, r0, #0
    ldr r5, lbl_080085c8 @ =0x03001528
    ldr r4, lbl_080085cc @ =0x03001588
    ldrb r1, [r2, #5]
    cmp r1, #0
    bne lbl_080085d4
    ldr r0, lbl_080085d0 @ =0x08238d8c
    ldr r3, [r0]
    strb r1, [r5]
    b lbl_080085dc
    .align 2, 0
lbl_080085c8: .4byte 0x03001528
lbl_080085cc: .4byte 0x03001588
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
    ldr r0, lbl_0800863c @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008640
    movs r0, #0x64
    bl play_sound1
    b lbl_0800868a
    .align 2, 0
lbl_0800863c: .4byte 0x03001530
lbl_08008640:
    movs r0, #0x96
    bl play_sound1
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
    bl play_sound1
    b lbl_0800868a
lbl_0800866e:
    ldr r0, lbl_08008680 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008684
    movs r0, #0x65
    bl play_sound1
    b lbl_0800868a
    .align 2, 0
lbl_08008680: .4byte 0x03001530
lbl_08008684:
    movs r0, #0x97
    bl play_sound1
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

    thumb_func_start samus_standing
samus_standing: @ 0x080086d4
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008718 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_08008724
    ldr r0, lbl_0800871c @ =0x03001380
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
lbl_08008718: .4byte 0x0300137c
lbl_0800871c: .4byte 0x03001380
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
    ldr r0, lbl_08008748 @ =0x0300137c
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800874c
    movs r0, #0
    b lbl_08008816
    .align 2, 0
lbl_08008748: .4byte 0x0300137c
lbl_0800874c:
    ldr r0, lbl_0800875c @ =0x03001588
    adds r6, r0, #0
    adds r6, #0x5c
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_08008760
    movs r0, #3
    b lbl_08008816
    .align 2, 0
lbl_0800875c: .4byte 0x03001588
lbl_08008760:
    movs r0, #0x30
    eors r0, r1
    ands r0, r2
    cmp r0, #0
    beq lbl_0800876e
    movs r0, #2
    b lbl_08008816
lbl_0800876e:
    ldr r0, lbl_080087b8 @ =0x03001380
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
    bl check_hazard_at_pos
    asrs r0, r0, #0x10
    cmp r0, #1
    beq lbl_080087f0
    ldr r0, lbl_080087bc @ =0x03001414
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800879e
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_08008804
lbl_0800879e:
    ldr r4, lbl_080087c0 @ =0x03001530
    ldrb r0, [r4, #0x12]
    cmp r0, #2
    beq lbl_080087ac
    movs r0, #0x79
    bl play_sound1
lbl_080087ac:
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_080087c4
    movs r0, #6
    b lbl_08008816
    .align 2, 0
lbl_080087b8: .4byte 0x03001380
lbl_080087bc: .4byte 0x03001414
lbl_080087c0: .4byte 0x03001530
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
    bl check_hazard_at_pos
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

    thumb_func_start samus_standing_gfx
samus_standing_gfx: @ 0x0800881c
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

    thumb_func_start samus_turning
samus_turning: @ 0x0800883c
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008880 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_0800888c
    ldr r0, lbl_08008884 @ =0x03001380
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
lbl_08008880: .4byte 0x0300137c
lbl_08008884: .4byte 0x03001380
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
    ldr r0, lbl_080088dc @ =0x03001380
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080088c8
    ldr r0, lbl_080088e0 @ =0x03001414
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080088b6
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_080088c8
lbl_080088b6:
    movs r0, #5
    strb r0, [r4]
    ldr r0, lbl_080088e4 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_080088c8
    movs r0, #0x79
    bl play_sound1
lbl_080088c8:
    ldr r0, lbl_080088e8 @ =0x03001588
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
lbl_080088dc: .4byte 0x03001380
lbl_080088e0: .4byte 0x03001414
lbl_080088e4: .4byte 0x03001530
lbl_080088e8: .4byte 0x03001588
lbl_080088ec:
    movs r0, #3
    b lbl_080088f2
lbl_080088f0:
    movs r0, #0xff
lbl_080088f2:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start samus_turning_gfx
samus_turning_gfx: @ 0x080088f8
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008938
    ldr r2, lbl_08008920 @ =0x0300137c
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
lbl_08008920: .4byte 0x0300137c
lbl_08008924:
    ldr r0, lbl_08008930 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008934
    movs r0, #0x3b
    b lbl_0800893a
    .align 2, 0
lbl_08008930: .4byte 0x03001530
lbl_08008934:
    movs r0, #1
    b lbl_0800893a
lbl_08008938:
    movs r0, #0xff
lbl_0800893a:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start samus_shooting_gfx
samus_shooting_gfx: @ 0x08008940
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

    thumb_func_start samus_crouching
samus_crouching: @ 0x0800895c
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldr r0, lbl_080089a0 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_080089ac
    ldr r0, lbl_080089a4 @ =0x03001380
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
lbl_080089a0: .4byte 0x0300137c
lbl_080089a4: .4byte 0x03001380
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
    ldr r2, lbl_08008a4c @ =0x03001380
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a58
    movs r0, #6
    ands r0, r5
    cmp r0, #0
    bne lbl_08008a58
    ldr r0, lbl_08008a50 @ =0x03001414
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
    ldr r0, lbl_08008a54 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08008afc
    b lbl_08008b04
    .align 2, 0
lbl_08008a4c: .4byte 0x03001380
lbl_08008a50: .4byte 0x03001414
lbl_08008a54: .4byte 0x03001530
lbl_08008a58:
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a90
    ldr r0, lbl_08008a88 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008a90
    ldr r0, lbl_08008a8c @ =0x03001414
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008a7c
    ldrb r0, [r4, #2]
    cmp r0, #2
    bne lbl_08008a90
lbl_08008a7c:
    movs r0, #0x77
    bl play_sound1
    movs r0, #0x10
    b lbl_08008b0c
    .align 2, 0
lbl_08008a88: .4byte 0x03001530
lbl_08008a8c: .4byte 0x03001414
lbl_08008a90:
    adds r0, r4, #0
    bl samus_update_aim
    ldrb r0, [r4, #2]
    cmp r0, #3
    bne lbl_08008aa0
    movs r0, #0
    strb r0, [r4, #2]
lbl_08008aa0:
    ldr r0, lbl_08008ab0 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008ab4
    movs r0, #6
    b lbl_08008b0c
    .align 2, 0
lbl_08008ab0: .4byte 0x03001588
lbl_08008ab4:
    ldr r1, lbl_08008ac8 @ =0x0300137c
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
lbl_08008ac8: .4byte 0x0300137c
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
    ldr r0, lbl_08008b00 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008b04
lbl_08008afc:
    movs r0, #0x3b
    b lbl_08008b0c
    .align 2, 0
lbl_08008b00: .4byte 0x03001530
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

    thumb_func_start samus_turning_and_crouching
samus_turning_and_crouching: @ 0x08008b14
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    ldr r0, lbl_08008b58 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_08008b64
    ldr r0, lbl_08008b5c @ =0x03001380
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
lbl_08008b58: .4byte 0x0300137c
lbl_08008b5c: .4byte 0x03001380
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
    ldr r0, lbl_08008c0c @ =0x03001380
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008bf8
    movs r0, #6
    ands r0, r4
    cmp r0, #0
    bne lbl_08008bf8
    ldr r0, lbl_08008c10 @ =0x03001414
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
    ldr r0, lbl_08008c14 @ =0x03001588
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
lbl_08008c0c: .4byte 0x03001380
lbl_08008c10: .4byte 0x03001414
lbl_08008c14: .4byte 0x03001588
lbl_08008c18:
    movs r0, #6
    b lbl_08008c1e
lbl_08008c1c:
    movs r0, #0xff
lbl_08008c1e:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start samus_turning_and_crouching_gfx
samus_turning_and_crouching_gfx: @ 0x08008c24
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08008c48
    ldr r0, lbl_08008c40 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008c44
    movs r0, #0x3c
    b lbl_08008c4a
    .align 2, 0
lbl_08008c40: .4byte 0x03001530
lbl_08008c44:
    movs r0, #4
    b lbl_08008c4a
lbl_08008c48:
    movs r0, #0xff
lbl_08008c4a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_shooting_and_crouching_gfx
samus_shooting_and_crouching_gfx: @ 0x08008c50
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

    thumb_func_start samus_skidding
samus_skidding: @ 0x08008c6c
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08008c84 @ =0x03001380
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
lbl_08008c84: .4byte 0x03001380
lbl_08008c88:
    ldr r0, lbl_08008c9c @ =0x0300137c
    ldrh r1, [r0]
    ldrh r3, [r2, #0xe]
    adds r0, r1, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08008ca0
    movs r0, #0
    b lbl_08008cf2
    .align 2, 0
lbl_08008c9c: .4byte 0x0300137c
lbl_08008ca0:
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x80
    bne lbl_08008ccc
    movs r0, #0xb4
    strb r0, [r2, #8]
    ldr r1, lbl_08008cc0 @ =0x03001528
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_08008cc4 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08008cc8
    movs r0, #0x3c
    b lbl_08008cf2
    .align 2, 0
lbl_08008cc0: .4byte 0x03001528
lbl_08008cc4: .4byte 0x03001530
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

    thumb_func_start samus_midair
samus_midair: @ 0x08008cf8
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r2, lbl_08008d24 @ =0x03001380
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d2c
    ldrb r0, [r4, #2]
    cmp r0, #4
    bne lbl_08008d2c
    ldr r0, lbl_08008d28 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08008d2c
    movs r0, #0x77
    bl play_sound1
    movs r0, #0x14
    b lbl_08008dec
    .align 2, 0
lbl_08008d24: .4byte 0x03001380
lbl_08008d28: .4byte 0x03001530
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
    ldr r0, lbl_08008d58 @ =0x0300137c
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
lbl_08008d58: .4byte 0x0300137c
lbl_08008d5c:
    movs r6, #0
    ldr r5, lbl_08008d88 @ =0x03001588
    adds r0, r5, #0
    adds r0, #0x68
    movs r1, #0
    ldrsh r2, [r0, r1]
    ldr r0, lbl_08008d8c @ =0x0300137c
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
lbl_08008d88: .4byte 0x03001588
lbl_08008d8c: .4byte 0x0300137c
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
    ldr r0, lbl_08008df4 @ =0x0300137c
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
lbl_08008df4: .4byte 0x0300137c

    thumb_func_start samus_midair_gfx
samus_midair_gfx: @ 0x08008df8
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

    thumb_func_start samus_turning_midair
samus_turning_midair: @ 0x08008e38
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08008e54 @ =0x03001380
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
lbl_08008e54: .4byte 0x03001380
lbl_08008e58:
    ldr r0, lbl_08008e7c @ =0x0300137c
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
lbl_08008e7c: .4byte 0x0300137c
lbl_08008e80:
    ldr r0, lbl_08008e94 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008e98
    movs r0, #2
    strb r0, [r2, #4]
    movs r0, #0xfe
    b lbl_08008eb0
    .align 2, 0
lbl_08008e94: .4byte 0x03001588
lbl_08008e98:
    ldr r0, lbl_08008eb4 @ =0x0300137c
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
lbl_08008eb4: .4byte 0x0300137c

    thumb_func_start samus_turning_midair_gfx
samus_turning_midair_gfx: @ 0x08008eb8
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

    thumb_func_start samus_start_summersault_gfx
samus_start_summersault_gfx: @ 0x08008ed8
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

    thumb_func_start samus_summersault
samus_summersault: @ 0x08008efc
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08008f10 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08008f14
    movs r0, #0
    b lbl_08008f2a
    .align 2, 0
lbl_08008f10: .4byte 0x03001588
lbl_08008f14:
    ldr r0, lbl_08008f30 @ =0x0300137c
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
lbl_08008f30: .4byte 0x0300137c
lbl_08008f34:
    adds r0, r4, #0
    bl samus_update_aim
    ldr r1, lbl_08008f80 @ =0x03001588
    adds r0, r1, #0
    adds r0, #0x68
    movs r2, #0
    ldrsh r5, [r0, r2]
    ldr r0, lbl_08008f84 @ =0x03001530
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
    ldr r0, lbl_08008f88 @ =0x03001380
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
lbl_08008f80: .4byte 0x03001588
lbl_08008f84: .4byte 0x03001530
lbl_08008f88: .4byte 0x03001380
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
    ldr r0, lbl_08008fe0 @ =0x03001380
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
    bl sub_08057df8
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
lbl_08008fe0: .4byte 0x03001380
lbl_08008fe4:
    movs r5, #1
lbl_08008fe6:
    ldr r2, lbl_08009004 @ =0x0300137c
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
lbl_08009004: .4byte 0x0300137c
lbl_08009008:
    ldr r0, lbl_08009038 @ =0x03001588
    adds r0, #0x6a
    movs r2, #0
    ldrsh r1, [r0, r2]
    adds r0, r5, #0
    adds r2, r4, #0
    bl sub_08008278
lbl_08009018:
    ldr r0, lbl_0800903c @ =0x0300137c
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
lbl_08009038: .4byte 0x03001588
lbl_0800903c: .4byte 0x0300137c

    thumb_func_start samus_summersault_gfx
samus_summersault_gfx: @ 0x08009040
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009074 @ =0x03001588
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
    bl play_sound1
    b lbl_08009092
    .align 2, 0
lbl_08009074: .4byte 0x03001588
lbl_08009078:
    ldr r0, lbl_08009088 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_0800908c
    movs r0, #0x6a
    bl play_sound1
    b lbl_08009092
    .align 2, 0
lbl_08009088: .4byte 0x03001530
lbl_0800908c:
    movs r0, #0x98
    bl play_sound1
lbl_08009092:
    movs r0, #0xff
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_starting_walljump
samus_starting_walljump: @ 0x0800909c
    push {lr}
    adds r3, r0, #0
    ldr r0, lbl_080090b4 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080090b8
    movs r0, #0
    strb r0, [r3, #4]
    movs r0, #0xfe
    b lbl_080090da
    .align 2, 0
lbl_080090b4: .4byte 0x03001588
lbl_080090b8:
    ldr r0, lbl_080090d4 @ =0x0300137c
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
lbl_080090d4: .4byte 0x0300137c
lbl_080090d8:
    movs r0, #0xff
lbl_080090da:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_starting_walljump_gfx
samus_starting_walljump_gfx: @ 0x080090e0
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

    thumb_func_start samus_spacejump_gfx
samus_spacejump_gfx: @ 0x08009104
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800912a
    ldr r0, lbl_08009120 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009124
    movs r0, #0x6b
    bl play_sound1
    b lbl_0800912a
    .align 2, 0
lbl_08009120: .4byte 0x03001588
lbl_08009124:
    movs r0, #0x6b
    bl play_sound1
lbl_0800912a:
    ldr r0, lbl_0800914c @ =0x03001588
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
lbl_0800914c: .4byte 0x03001588

    thumb_func_start samus_screwattack_gfx
samus_screwattack_gfx: @ 0x08009150
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009174 @ =0x03001530
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
    bl play_sound1
    b lbl_0800918c
    .align 2, 0
lbl_08009174: .4byte 0x03001530
lbl_08009178: .4byte 0x08238ef4
lbl_0800917c:
    ldr r0, lbl_08009200 @ =0x08238ef4
    ldr r5, [r0]
    ldrh r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0800918c
    movs r0, #0x6c
    bl play_sound1
lbl_0800918c:
    ldrb r0, [r4, #0x1d]
    lsls r0, r0, #4
    adds r5, r5, r0
    ldrb r1, [r5, #0xc]
    ldr r0, lbl_08009204 @ =0x03001588
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
    ldr r3, lbl_08009208 @ =0x03001528
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
lbl_08009204: .4byte 0x03001588
lbl_08009208: .4byte 0x03001528
lbl_0800920c: .4byte 0x08289084

    thumb_func_start samus_morphing
samus_morphing: @ 0x08009210
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_0800922c @ =0x03001380
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
lbl_0800922c: .4byte 0x03001380

    thumb_func_start samus_morphing_gfx
samus_morphing_gfx: @ 0x08009230
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

    thumb_func_start samus_morphball
samus_morphball: @ 0x0800924c
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
    ldr r0, lbl_080092ac @ =0x03001380
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080092b8
    ldr r0, lbl_080092b0 @ =0x03001530
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
lbl_080092ac: .4byte 0x03001380
lbl_080092b0: .4byte 0x03001530
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
    ldr r0, lbl_080092e8 @ =0x03001530
    ldrb r0, [r0, #0xf]
    ands r0, r1
    cmp r0, #0
    bne lbl_0800925c
    strb r0, [r4, #4]
lbl_080092d6:
    ldr r0, lbl_080092ec @ =0x0300137c
    ldrh r0, [r0]
    movs r1, #0x30
    ands r1, r0
    cmp r1, #0
    beq lbl_080092f0
    strh r1, [r4, #0xe]
    movs r0, #0x12
    b lbl_080093ac
    .align 2, 0
lbl_080092e8: .4byte 0x03001530
lbl_080092ec: .4byte 0x0300137c
lbl_080092f0:
    ldr r0, lbl_0800932c @ =0x03001380
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
    ldr r0, lbl_08009338 @ =0x03001600
    strh r1, [r0]
    b lbl_0800935e
    .align 2, 0
lbl_0800932c: .4byte 0x03001380
lbl_08009330: .4byte 0x0823a554
lbl_08009334: .4byte 0x0000ffc0
lbl_08009338: .4byte 0x03001600
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
    ldr r0, lbl_08009374 @ =0x03001600
    strh r1, [r0]
    movs r0, #0
lbl_0800935a:
    cmp r0, #0
    bne lbl_08009386
lbl_0800935e:
    ldr r0, lbl_08009378 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800937c
    movs r0, #0x78
    bl play_sound1
    b lbl_08009382
    .align 2, 0
lbl_08009370: .4byte 0x0000ffc0
lbl_08009374: .4byte 0x03001600
lbl_08009378: .4byte 0x03001588
lbl_0800937c:
    movs r0, #0x78
    bl play_sound1
lbl_08009382:
    movs r0, #0x13
    b lbl_080093ac
lbl_08009386:
    ldrb r0, [r4, #0xa]
    cmp r0, #0
    beq lbl_080093aa
    subs r0, #1
    strb r0, [r4, #0xa]
    ldr r0, lbl_080093b4 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x80
    bne lbl_080093aa
    movs r0, #0xb4
    strb r0, [r4, #8]
    movs r0, #0
    strb r0, [r4, #0xa]
    ldr r1, lbl_080093b8 @ =0x03001528
    movs r0, #8
    strb r0, [r1]
lbl_080093aa:
    movs r0, #0xff
lbl_080093ac:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080093b4: .4byte 0x0300137c
lbl_080093b8: .4byte 0x03001528

    thumb_func_start samus_rolling
samus_rolling: @ 0x080093bc
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_080093e4 @ =0x03001380
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080093ec
    ldr r0, lbl_080093e8 @ =0x03001530
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
lbl_080093e4: .4byte 0x03001380
lbl_080093e8: .4byte 0x03001530
lbl_080093ec:
    ldr r0, lbl_0800941c @ =0x0823a554
    movs r2, #4
    ldrsh r1, [r0, r2]
    adds r0, r4, #0
    bl sub_080057ec
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08009432
    ldr r0, lbl_08009420 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009432
    ldr r0, lbl_08009424 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009428
    movs r0, #0x78
    bl play_sound1
    b lbl_0800942e
    .align 2, 0
lbl_0800941c: .4byte 0x0823a554
lbl_08009420: .4byte 0x03001380
lbl_08009424: .4byte 0x03001588
lbl_08009428:
    movs r0, #0x78
    bl play_sound1
lbl_0800942e:
    movs r0, #0x13
    b lbl_08009482
lbl_08009432:
    ldr r0, lbl_08009468 @ =0x0300137c
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08009470
    ldr r2, lbl_0800946c @ =0x03001588
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
lbl_08009468: .4byte 0x0300137c
lbl_0800946c: .4byte 0x03001588
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

    thumb_func_start samus_rolling_gfx
samus_rolling_gfx: @ 0x08009488
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

    thumb_func_start samus_unmorphing
samus_unmorphing: @ 0x080094c0
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
    ldr r0, lbl_080094f0 @ =0x03001380
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
lbl_080094f0: .4byte 0x03001380
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

    thumb_func_start samus_unmorphing_gfx
samus_unmorphing_gfx: @ 0x08009508
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

    thumb_func_start samus_morphball_midair
samus_morphball_midair: @ 0x0800952c
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009560 @ =0x03001380
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
    ldr r0, lbl_08009568 @ =0x03001588
    adds r0, #0x5b
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0800956c
    movs r0, #0x78
    bl play_sound1
    b lbl_08009572
    .align 2, 0
lbl_08009560: .4byte 0x03001380
lbl_08009564: .4byte 0x0823a554
lbl_08009568: .4byte 0x03001588
lbl_0800956c:
    movs r0, #0x78
    bl play_sound1
lbl_08009572:
    movs r0, #0xf
    strb r0, [r4, #9]
    movs r0, #8
    b lbl_080095fc
lbl_0800957a:
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_0800959c
    ldr r0, lbl_08009598 @ =0x0300137c
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
lbl_08009598: .4byte 0x0300137c
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
    ldr r0, lbl_080095e0 @ =0x0300137c
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r3, r2, #0
    ands r3, r1
    cmp r3, #0
    beq lbl_080095e8
lbl_080095c6:
    ldr r1, lbl_080095e4 @ =0x03001588
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
lbl_080095e0: .4byte 0x0300137c
lbl_080095e4: .4byte 0x03001588
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

    thumb_func_start samus_hanging_on_ledge
samus_hanging_on_ledge: @ 0x08009604
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldr r0, lbl_08009618 @ =0x03000114
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
lbl_08009618: .4byte 0x03000114
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
    bl sub_08057df8
    adds r6, r0, #0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r6, r4
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl sub_08057df8
    adds r3, r0, #0
    ands r3, r4
    ldr r0, lbl_08009680 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080096c6
    ldr r0, lbl_08009684 @ =0x0300137c
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
lbl_08009680: .4byte 0x03001380
lbl_08009684: .4byte 0x0300137c
lbl_08009688:
    ldr r0, lbl_08009698 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800969c
    movs r0, #0x1c
    b lbl_0800976a
    .align 2, 0
lbl_08009698: .4byte 0x03001530
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
    ldr r0, lbl_080096e8 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080096f8
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xe]
    ldr r0, lbl_080096ec @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080096f0
    movs r0, #4
    b lbl_080096f2
    .align 2, 0
lbl_080096e8: .4byte 0x03001588
lbl_080096ec: .4byte 0x0300137c
lbl_080096f0:
    movs r0, #3
lbl_080096f2:
    strb r0, [r5, #2]
    movs r0, #0x19
    b lbl_0800976a
lbl_080096f8:
    ldr r0, lbl_08009720 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_08009734
    ldr r0, lbl_08009724 @ =0x03001414
    ldrb r0, [r0, #5]
    cmp r0, #0
    beq lbl_08009734
    ldrh r0, [r5, #0xe]
    movs r1, #0x30
    eors r0, r1
    strh r0, [r5, #0xe]
    ldr r0, lbl_08009728 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800972c
    movs r0, #4
    b lbl_0800972e
    .align 2, 0
lbl_08009720: .4byte 0x03001530
lbl_08009724: .4byte 0x03001414
lbl_08009728: .4byte 0x0300137c
lbl_0800972c:
    movs r0, #3
lbl_0800972e:
    strb r0, [r5, #2]
    movs r0, #0x18
    b lbl_0800976a
lbl_08009734:
    ldr r0, lbl_08009760 @ =0x0300137c
    ldr r1, lbl_08009764 @ =0x0300168c
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
lbl_08009760: .4byte 0x0300137c
lbl_08009764: .4byte 0x0300168c
lbl_08009768:
    movs r0, #0xff
lbl_0800976a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start samus_hanging_on_ledge_gfx
samus_hanging_on_ledge_gfx: @ 0x08009770
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08009794 @ =0x03001588
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
lbl_08009794: .4byte 0x03001588

    thumb_func_start samus_turning_to_aim_while_hanging
samus_turning_to_aim_while_hanging: @ 0x08009798
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldr r0, lbl_080097a8 @ =0x03000114
    ldrb r0, [r0]
    cmp r0, #0x1d
    bls lbl_080097ac
    movs r0, #0
    b lbl_0800983e
    .align 2, 0
lbl_080097a8: .4byte 0x03000114
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
    bl sub_08057df8
    adds r6, r0, #0
    movs r4, #0x80
    lsls r4, r4, #0x11
    ands r6, r4
    ldrh r0, [r5, #0x14]
    subs r0, #0xd0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r1, [r5, #0x12]
    bl sub_08057df8
    adds r3, r0, #0
    ands r3, r4
    ldr r0, lbl_08009818 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009844
    ldr r1, lbl_0800981c @ =0x0300137c
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
lbl_08009818: .4byte 0x03001380
lbl_0800981c: .4byte 0x0300137c
lbl_08009820:
    ldr r0, lbl_08009838 @ =0x03001530
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
lbl_08009838: .4byte 0x03001530
lbl_0800983c:
    movs r0, #1
lbl_0800983e:
    strb r0, [r5, #4]
    movs r0, #0xfe
    b lbl_0800985a
lbl_08009844:
    ldr r0, lbl_08009854 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08009858
    movs r0, #0xff
    b lbl_0800985a
    .align 2, 0
lbl_08009854: .4byte 0x03001588
lbl_08009858:
    movs r0, #0x19
lbl_0800985a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start samus_turning_to_aim_while_hanging_gfx
samus_turning_to_aim_while_hanging_gfx: @ 0x08009860
    push {lr}
    ldr r1, lbl_08009878 @ =0x03001588
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
lbl_08009878: .4byte 0x03001588
lbl_0800987c:
    movs r0, #0x18
lbl_0800987e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_hiding_cannon_while_hanging_gfx
samus_hiding_cannon_while_hanging_gfx: @ 0x08009884
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_080098a0 @ =0x03001588
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
lbl_080098a0: .4byte 0x03001588
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

    thumb_func_start samus_aiming_while_hanging
samus_aiming_while_hanging: @ 0x080098b4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    ldr r0, lbl_080098c8 @ =0x03000114
    ldrb r0, [r0]
    cmp r0, #0x1d
    bls lbl_080098cc
    movs r0, #0
    b lbl_08009982
    .align 2, 0
lbl_080098c8: .4byte 0x03000114
lbl_080098cc:
    adds r0, r5, #0
    bl samus_update_aim
    ldr r0, lbl_080098e0 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080098e4
    movs r0, #0x19
    b lbl_08009a34
    .align 2, 0
lbl_080098e0: .4byte 0x03001588
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
    bl sub_08057df8
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
    bl sub_08057df8
    adds r7, r0, #0
    ands r7, r4
    ldr r0, lbl_08009958 @ =0x03001380
    ldrh r4, [r0]
    movs r0, #1
    ands r0, r4
    cmp r0, #0
    beq lbl_08009988
    ldr r3, lbl_0800995c @ =0x0300137c
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
lbl_08009958: .4byte 0x03001380
lbl_0800995c: .4byte 0x0300137c
lbl_08009960:
    ldr r0, lbl_08009974 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009978
    movs r0, #0x30
    eors r0, r4
    b lbl_08009a22
    .align 2, 0
lbl_08009974: .4byte 0x03001530
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
    ldr r2, lbl_080099bc @ =0x0300137c
    ldr r0, lbl_080099c0 @ =0x0300168c
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
    ldr r0, lbl_080099c4 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_080099b6
    ldr r0, lbl_080099c8 @ =0x03001414
    ldrb r0, [r0, #5]
    cmp r0, #0
    bne lbl_080099cc
lbl_080099b6:
    movs r0, #0x17
    b lbl_08009a34
    .align 2, 0
lbl_080099bc: .4byte 0x0300137c
lbl_080099c0: .4byte 0x0300168c
lbl_080099c4: .4byte 0x03001530
lbl_080099c8: .4byte 0x03001414
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
    ldr r0, lbl_08009a28 @ =0x03001530
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
lbl_08009a28: .4byte 0x03001530
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

    thumb_func_start samus_pulling_up
samus_pulling_up: @ 0x08009a40
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

    thumb_func_start samus_pulling_up_gfx
samus_pulling_up_gfx: @ 0x08009a68
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

    thumb_func_start samus_pulling_forward
samus_pulling_forward: @ 0x08009a94
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

    thumb_func_start samus_pulling_forward_gfx
samus_pulling_forward_gfx: @ 0x08009ab4
    push {lr}
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009ad8
    ldr r0, lbl_08009ad0 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08009ad4
    movs r0, #0x3b
    b lbl_08009ada
    .align 2, 0
lbl_08009ad0: .4byte 0x03001530
lbl_08009ad4:
    movs r0, #1
    b lbl_08009ada
lbl_08009ad8:
    movs r0, #0xff
lbl_08009ada:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_pulling_into_morphball_tunnel_gfx
samus_pulling_into_morphball_tunnel_gfx: @ 0x08009ae0
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
    bl play_sound1
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

    thumb_func_start samus_using_elevator
samus_using_elevator: @ 0x08009b28
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
    bl check_hazard_at_pos
    asrs r5, r0, #0x10
    ldrh r1, [r4, #0x10]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08009b74
    ldr r0, lbl_08009b70 @ =0x03001602
    ldrh r0, [r0]
    ldrh r1, [r4, #0x12]
    bl check_hazard_at_pos
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
lbl_08009b70: .4byte 0x03001602
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
    bl sub_08002c80
lbl_08009ba6:
    movs r0, #0xff
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08009bb0: .4byte 0x0000ffc0

    thumb_func_start samus_using_elevator_gfx
samus_using_elevator_gfx: @ 0x08009bb4
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

    thumb_func_start samus_facing_foreground
samus_facing_foreground: @ 0x08009c04
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08009c20 @ =0x0300137c
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
lbl_08009c20: .4byte 0x0300137c
lbl_08009c24:
    movs r0, #0xff
lbl_08009c26:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_turning_from_facing_foreground_gfx
samus_turning_from_facing_foreground_gfx: @ 0x08009c2c
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
    ldr r0, lbl_08009c58 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_08009c5c
    movs r0, #0x3b
    b lbl_08009c62
    .align 2, 0
lbl_08009c58: .4byte 0x03001530
lbl_08009c5c:
    movs r0, #1
    b lbl_08009c62
lbl_08009c60:
    movs r0, #0xff
lbl_08009c62:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_delay_before_shinespark_gfx
samus_delay_before_shinespark_gfx: @ 0x08009c68
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_08009c98
    ldr r2, lbl_08009c94 @ =0x0300137c
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
lbl_08009c94: .4byte 0x0300137c
lbl_08009c98:
    movs r0, #0xff
lbl_08009c9a:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start samus_shinesparking
samus_shinesparking: @ 0x08009ca0
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
    bl start_vertical_screen_shake
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
    ldr r1, lbl_08009d30 @ =0x03004fc9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0xfd
    b lbl_08009d48
    .align 2, 0
lbl_08009d30: .4byte 0x03004fc9
lbl_08009d34:
    movs r0, #0x1e
    movs r1, #1
    bl start_horizontal_screen_shake
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

    thumb_func_start samus_shinesparking_gfx
samus_shinesparking_gfx: @ 0x08009d50
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
    ldr r3, lbl_08009dd4 @ =0x03001528
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
lbl_08009dd4: .4byte 0x03001528
lbl_08009dd8: .4byte 0x08288f94

    thumb_func_start samus_shinespark_bonk_gfx
samus_shinespark_bonk_gfx: @ 0x08009ddc
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

    thumb_func_start samus_delay_after_shinespark_gfx
samus_delay_after_shinespark_gfx: @ 0x08009df0
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

    thumb_func_start samus_delay_before_ballspark
samus_delay_before_ballspark: @ 0x08009e0c
    push {r4, lr}
    adds r4, r0, #0
    ldr r2, lbl_08009e30 @ =0x0300137c
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
lbl_08009e30: .4byte 0x0300137c

    thumb_func_start samus_delay_before_ballspark_gfx
samus_delay_before_ballspark_gfx: @ 0x08009c68
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
    ldr r3, lbl_08009eb4 @ =0x03001528
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
lbl_08009eb4: .4byte 0x03001528
lbl_08009eb8: .4byte 0x08288f28

    thumb_func_start samus_ballsparking_gfx
samus_ballsparking_gfx: @ 0x08009ebc
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
    ldr r3, lbl_08009f30 @ =0x03001528
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
lbl_08009f30: .4byte 0x03001528
lbl_08009f34: .4byte 0x08288f94

    thumb_func_start samus_ballspark_bonk_gfx
samus_ballspark_bonk_gfx: @ 0x08009f38
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

    thumb_func_start samus_on_zipline
samus_on_zipline: @ 0x08009f4c
    push {lr}
    adds r3, r0, #0
    ldr r0, lbl_08009f60 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009f64
    movs r0, #0xfe
    b lbl_08009fa0
    .align 2, 0
lbl_08009f60: .4byte 0x03001380
lbl_08009f64:
    ldr r0, lbl_08009f74 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08009f78
    movs r0, #0x29
    b lbl_08009fa0
    .align 2, 0
lbl_08009f74: .4byte 0x03001588
lbl_08009f78:
    ldrb r0, [r3]
    cmp r0, #0x28
    bne lbl_08009f9e
    ldr r2, lbl_08009f94 @ =0x0300137c
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
lbl_08009f94: .4byte 0x0300137c
lbl_08009f98:
    adds r0, r3, #0
    bl samus_update_aim
lbl_08009f9e:
    movs r0, #0xff
lbl_08009fa0:
    pop {r1}
    bx r1

    thumb_func_start samus_shooting_on_zipline
samus_shooting_on_zipline: @ 0x08009fa4
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

    thumb_func_start samus_morphball_on_zipline
samus_morphball_on_zipline: @ 0x08009fc0
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_08009fd4 @ =0x03001380
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08009fd8
    movs r0, #0xfe
    b lbl_08009fe8
    .align 2, 0
lbl_08009fd4: .4byte 0x03001380
lbl_08009fd8:
    ldr r0, lbl_08009fec @ =0x0300137c
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
lbl_08009fec: .4byte 0x0300137c

    thumb_func_start samus_saving_loading_game
samus_saving_loading_game: @ 0x08009ff0
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

    thumb_func_start samus_turning_to_download_mapdata
samus_turning_to_download_mapdata: @ 0x0800a008
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

    thumb_func_start samus_getting_hurt
samus_getting_hurt: @ 0x0800a024
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
    ldr r0, lbl_0800a07c @ =0x03001588
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
lbl_0800a07c: .4byte 0x03001588
lbl_0800a080:
    movs r0, #0x14
    b lbl_0800a086
lbl_0800a084:
    movs r0, #0xff
lbl_0800a086:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_getting_hurt_gfx
samus_getting_hurt_gfx: @ 0x0800a08c
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

    thumb_func_start samus_getting_knocked_back
samus_getting_knocked_back: @ 0x0800a0ac
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

    thumb_func_start samus_dying
samus_dying: @ 0x0800a0dc
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldrh r0, [r4, #0xc]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_0800a0f2
    adds r0, #1
    strh r0, [r4, #0xc]
    bl sub_08002a58
    b lbl_0800a100
lbl_0800a0f2:
    cmp r1, #1
    bne lbl_0800a100
    adds r0, #1
    strh r0, [r4, #0xc]
    movs r0, #0x83
    bl play_sound1
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
    ldr r0, lbl_0800a138 @ =0x030013b8
    ldrh r0, [r0]
    movs r3, #0xf0
    lsls r3, r3, #1
    adds r2, r0, r3
    ldr r0, lbl_0800a13c @ =0x030013ba
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
lbl_0800a138: .4byte 0x030013b8
lbl_0800a13c: .4byte 0x030013ba
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
    ldr r1, lbl_0800a1c8 @ =0x03000029
    movs r0, #2
    strb r0, [r1]
lbl_0800a1c0:
    ldrb r0, [r4, #7]
    adds r0, #1
    strb r0, [r4, #7]
    b lbl_0800a1d8
    .align 2, 0
lbl_0800a1c8: .4byte 0x03000029
lbl_0800a1cc:
    ldr r1, lbl_0800a1e0 @ =0x03000c70
    movs r0, #6
    strh r0, [r1]
    ldr r1, lbl_0800a1e4 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
lbl_0800a1d8:
    movs r0, #0xff
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800a1e0: .4byte 0x03000c70
lbl_0800a1e4: .4byte 0x03000c72

    thumb_func_start samus_crouching_to_crawl_gfx
samus_crouching_to_crawl_gfx: @ 0x0800a1e8
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

    thumb_func_start samus_crawling_stopped
samus_crawling_stopped: @ 0x0800a21c
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
    ldr r0, lbl_0800a250 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800a254
    movs r0, #0x3a
    b lbl_0800a27c
    .align 2, 0
lbl_0800a250: .4byte 0x03001588
lbl_0800a254:
    ldr r0, lbl_0800a268 @ =0x0300137c
    ldrh r2, [r0]
    ldrh r1, [r4, #0xe]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800a26c
    movs r0, #0x37
    b lbl_0800a27c
    .align 2, 0
lbl_0800a268: .4byte 0x0300137c
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

    thumb_func_start samus_starting_to_crawl_gfx
samus_starting_to_crawl_gfx: @ 0x0800a284
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

    thumb_func_start samus_crawling
samus_crawling: @ 0x0800a2a0
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
    ldr r3, lbl_0800a2d0 @ =0x03001588
    adds r0, r3, #0
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800a2d4
    movs r0, #0x3a
    b lbl_0800a30e
    .align 2, 0
lbl_0800a2d0: .4byte 0x03001588
lbl_0800a2d4:
    ldr r0, lbl_0800a2f8 @ =0x0300137c
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
lbl_0800a2f8: .4byte 0x0300137c
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

    thumb_func_start samus_dying_gfx
samus_dying_gfx: @ 0x0800a314
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
    bl play_sound1
lbl_0800a350:
    movs r0, #0xff
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start samus_turning_around_crawling
samus_turning_around_crawling: @ 0x0800a358
    push {lr}
    ldr r0, lbl_0800a368 @ =0x03001588
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800a36c
    movs r0, #0xff
    b lbl_0800a36e
    .align 2, 0
lbl_0800a368: .4byte 0x03001588
lbl_0800a36c:
    movs r0, #0x3a
lbl_0800a36e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_crawling_gfx
samus_crawling_gfx: @ 0x0800a374
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

    thumb_func_start samus_suitlett_grabbing_ledge
samus_suitlett_grabbing_ledge: @ 0x0800a390
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

    thumb_func_start samus_facing_background
samus_facing_background: @ 0x0800a3ac
    push {lr}
    adds r2, r0, #0
    ldr r0, lbl_0800a3c8 @ =0x0300137c
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
lbl_0800a3c8: .4byte 0x0300137c
lbl_0800a3cc:
    movs r0, #0xff
lbl_0800a3ce:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start samus_turning_from_facing_background_gfx
samus_turning_from_facing_background_gfx: @ 0x0800a3d4
    push {r4, lr}
    adds r4, r0, #0
    movs r1, #0
    bl sub_0800847c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0800a420
    ldr r2, lbl_0800a3fc @ =0x0300137c
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
lbl_0800a3fc: .4byte 0x0300137c
lbl_0800a400:
    ldrh r0, [r4, #0xc]
    cmp r0, #0
    beq lbl_0800a40a
    movs r0, #0x3e
    b lbl_0800a422
lbl_0800a40a:
    ldr r0, lbl_0800a418 @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0800a41c
    movs r0, #0x3b
    b lbl_0800a422
    .align 2, 0
lbl_0800a418: .4byte 0x03001530
lbl_0800a41c:
    movs r0, #1
    b lbl_0800a422
lbl_0800a420:
    movs r0, #0xff
lbl_0800a422:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start samus_turning_to_enter_spaceship_gfx
samus_turning_to_enter_spaceship_gfx: @ 0x0800a428
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
    ldr r6, lbl_0800a460 @ =0x03001414
    ldr r4, lbl_0800a464 @ =0x03001530
    ldr r2, lbl_0800a468 @ =0x03001544
    adds r1, r4, #0
    bl samus_apply_hazard_damage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800a46c
    movs r0, #0xfa
    b lbl_0800a4f2
    .align 2, 0
lbl_0800a460: .4byte 0x03001414
lbl_0800a464: .4byte 0x03001530
lbl_0800a468: .4byte 0x03001544
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
    bl play_sound1
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
    bl samus_set_highlighted_weapon
lbl_0800a4ac:
    adds r0, r5, #0
    adds r1, r4, #0
    bl samus_set_spinning_pose
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r4, #0
    bl samus_check_new_projectile
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
    ldr r3, lbl_0800a530 @ =0x03001588
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
lbl_0800a530: .4byte 0x03001588
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
    bl samus_change_velocity_on_slope
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

    thumb_func_start samus_update_graphics_oam
samus_update_graphics_oam: @ 0x0800a688
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov sb, r0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_0800a6c4 @ =0x03001414
    mov r8, r0
    ldr r6, lbl_0800a6c8 @ =0x03001530
    ldr r1, lbl_0800a6cc @ =0x03001588
    mov ip, r1
    ldr r3, lbl_0800a6d0 @ =0x0300141c
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
lbl_0800a6c4: .4byte 0x03001414
lbl_0800a6c8: .4byte 0x03001530
lbl_0800a6cc: .4byte 0x03001588
lbl_0800a6d0: .4byte 0x0300141c
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
    ldr r1, lbl_0800a7c8 @ =0x03001600
    ldrh r1, [r1]
    strh r1, [r0]
    adds r0, r3, #0
    adds r0, #0x88
    adds r0, r0, r2
    ldr r1, lbl_0800a7cc @ =0x03001602
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
lbl_0800a7c8: .4byte 0x03001600
lbl_0800a7cc: .4byte 0x03001602
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
    ldr r4, lbl_0800b314 @ =0x03001528
    ldrb r0, [r4]
    adds r7, r2, #0
    mov r8, r1
    cmp r0, #8
    bne lbl_0800b2ec
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    ldr r4, lbl_0800b318 @ =0x082890f0
    ldr r1, lbl_0800b314 @ =0x03001528
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
    ldr r2, lbl_0800b314 @ =0x03001528
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
    ldr r4, lbl_0800b314 @ =0x03001528
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
lbl_0800b314: .4byte 0x03001528
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
    ldr r1, lbl_0800b464 @ =0x03001528
    ldrb r0, [r1]
    cmp r0, #8
    bne lbl_0800b420
    ldr r2, lbl_0800b468 @ =0x082890f0
    str r2, [sp]
lbl_0800b420:
    ldr r3, lbl_0800b464 @ =0x03001528
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
lbl_0800b464: .4byte 0x03001528
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
    ldr r1, lbl_0800b4d8 @ =0x03005440
    movs r0, #0x40
    strh r0, [r1]
    ldr r1, lbl_0800b4dc @ =0x03001414
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
    ldr r2, lbl_0800b4e0 @ =0x03001530
    ldrb r0, [r2, #0x12]
    adds r1, r0, #0
    mov r2, sp
    strb r0, [r2, #4]
    cmp r1, #1
    bne lbl_0800b554
    ldr r0, lbl_0800b4e0 @ =0x03001530
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
lbl_0800b4d8: .4byte 0x03005440
lbl_0800b4dc: .4byte 0x03001414
lbl_0800b4e0: .4byte 0x03001530
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
    ldr r2, lbl_0800b58c @ =0x03001530
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
lbl_0800b58c: .4byte 0x03001530
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
    bl samus_copy_palette
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
    ldr r0, lbl_0800b6c0 @ =0x03000c77
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
lbl_0800b6c0: .4byte 0x03000c77
lbl_0800b6c4:
    ldr r0, lbl_0800b710 @ =0x03001544
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
    ldr r0, lbl_0800b714 @ =0x03000c77
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
    bl samus_copy_palette
    b lbl_0800b7d6
    .align 2, 0
lbl_0800b710: .4byte 0x03001544
lbl_0800b714: .4byte 0x03000c77
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
    bl samus_copy_palette
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
    bl samus_copy_palette
    mov r4, r8
    adds r4, #0x40
    b lbl_0800b7d6
lbl_0800b766:
    ldr r1, lbl_0800b780 @ =0x03001414
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0800b7b2
    ldr r2, lbl_0800b784 @ =0x03001530
    ldrb r1, [r2, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b788
    mov r4, ip
    adds r4, #0x40
    b lbl_0800b7c8
    .align 2, 0
lbl_0800b780: .4byte 0x03001414
lbl_0800b784: .4byte 0x03001530
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
    bl samus_copy_palette
    mov r4, r8
    adds r4, #0x20
lbl_0800b7d6:
    adds r0, r4, #0
    movs r1, #0x10
    movs r2, #0x10
    bl samus_copy_palette
    b lbl_0800b858
lbl_0800b7e2:
    mov r4, r8
    mov r1, sp
    ldrb r1, [r1, #4]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0800b84e
    ldr r2, lbl_0800b814 @ =0x03001414
    ldrb r0, [r2, #5]
    cmp r0, #0x40
    blo lbl_0800b84e
    subs r0, #0x40
    asrs r2, r0, #2
    cmp r2, #3
    beq lbl_0800b84e
    ldr r0, lbl_0800b818 @ =0x03001530
    ldrb r1, [r0, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800b81c
    mov r4, sb
    adds r4, #0x80
    b lbl_0800b846
    .align 2, 0
lbl_0800b814: .4byte 0x03001414
lbl_0800b818: .4byte 0x03001530
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
    bl samus_copy_palette
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
    ldr r1, lbl_0800b898 @ =0x030013d4
    ldr r0, lbl_0800b89c @ =0x03001530
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0800b894
    ldrb r0, [r1]
    cmp r0, #0x33
    beq lbl_0800b894
    ldr r0, lbl_0800b8a0 @ =0x03001606
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0800b894
    ldr r0, lbl_0800b8a4 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0800b894
    movs r0, #0x82
    bl play_sound1
lbl_0800b894:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800b898: .4byte 0x030013d4
lbl_0800b89c: .4byte 0x03001530
lbl_0800b8a0: .4byte 0x03001606
lbl_0800b8a4: .4byte 0x03000c77

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
    ldr r6, lbl_0800b934 @ =0x030013d4
    ldr r4, lbl_0800b938 @ =0x03001530
    ldr r0, lbl_0800b93c @ =0x03001588
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
lbl_0800b934: .4byte 0x030013d4
lbl_0800b938: .4byte 0x03001530
lbl_0800b93c: .4byte 0x03001588
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

    thumb_func_start init_samus
init_samus: @ 0x0800bcb8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_0800bd84 @ =0x03000bf0
    movs r3, #0
    ldrsb r3, [r0, r3]
    ldr r5, lbl_0800bd88 @ =0x03000c75
    cmp r3, #0
    bne lbl_0800bd00
    ldr r2, lbl_0800bd8c @ =0x0300141c
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
    ldr r4, lbl_0800bd90 @ =0x0300154c
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
    ldr r0, lbl_0800bd98 @ =0x03000c1d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800bdbc
    str r5, [sp]
    ldr r0, lbl_0800bd9c @ =0x040000d4
    mov r6, sp
    str r6, [r0]
    ldr r4, lbl_0800bda0 @ =0x030013d4
    str r4, [r0, #4]
    ldr r1, lbl_0800bda4 @ =0x85000008
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r3, lbl_0800bda8 @ =0x03001530
    str r3, [r0, #4]
    ldr r1, lbl_0800bdac @ =0x85000005
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r1, lbl_0800bdb0 @ =0x03001414
    str r1, [r0, #4]
    ldr r2, lbl_0800bdb4 @ =0x85000002
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r5, [sp]
    str r6, [r0]
    ldr r1, lbl_0800bdb8 @ =0x03001528
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r2, #0
    mov r8, r3
    ldr r3, lbl_0800bd90 @ =0x0300154c
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
lbl_0800bd84: .4byte 0x03000bf0
lbl_0800bd88: .4byte 0x03000c75
lbl_0800bd8c: .4byte 0x0300141c
lbl_0800bd90: .4byte 0x0300154c
lbl_0800bd94: .4byte 0x08238b68
lbl_0800bd98: .4byte 0x03000c1d
lbl_0800bd9c: .4byte 0x040000d4
lbl_0800bda0: .4byte 0x030013d4
lbl_0800bda4: .4byte 0x85000008
lbl_0800bda8: .4byte 0x03001530
lbl_0800bdac: .4byte 0x85000005
lbl_0800bdb0: .4byte 0x03001414
lbl_0800bdb4: .4byte 0x85000002
lbl_0800bdb8: .4byte 0x03001528
lbl_0800bdbc:
    str r5, [sp]
    ldr r1, lbl_0800bddc @ =0x040000d4
    mov r3, sp
    str r3, [r1]
    ldr r0, lbl_0800bde0 @ =0x03001588
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
lbl_0800bde0: .4byte 0x03001588
lbl_0800bde4: .4byte 0x8500001e

    thumb_func_start draw_samus
draw_samus: @ 0x0800bde8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    movs r0, #2
    str r0, [sp]
    ldr r0, lbl_0800be1c @ =0x030013d4
    ldrb r1, [r0]
    cmp r1, #0x33
    bne lbl_0800be2c
    movs r1, #0
    str r1, [sp]
    ldr r0, lbl_0800be20 @ =0x03001382
    strb r1, [r0]
    ldr r3, lbl_0800be24 @ =0x03000e7c
    ldr r2, lbl_0800be28 @ =0x0300154c
    adds r0, r2, #0
    adds r0, #0x30
lbl_0800be10:
    strb r1, [r0]
    subs r0, #0xc
    cmp r0, r2
    bge lbl_0800be10
    b lbl_0800be3a
    .align 2, 0
lbl_0800be1c: .4byte 0x030013d4
lbl_0800be20: .4byte 0x03001382
lbl_0800be24: .4byte 0x03000e7c
lbl_0800be28: .4byte 0x0300154c
lbl_0800be2c:
    ldr r0, lbl_0800c1b8 @ =0x0300002b
    ldrb r0, [r0]
    ldr r3, lbl_0800c1bc @ =0x03000e7c
    cmp r0, #0
    beq lbl_0800be3a
    movs r0, #1
    str r0, [sp]
lbl_0800be3a:
    ldr r1, lbl_0800c1c0 @ =0x03001382
    ldrb r0, [r1]
    cmp r0, #0x6a
    bls lbl_0800be46
    movs r0, #0x6a
    strb r0, [r1]
lbl_0800be46:
    ldr r2, lbl_0800c1c0 @ =0x03001382
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
    ldr r0, lbl_0800c1c4 @ =0x0300154c
    adds r3, r1, r0
    ldrb r0, [r3]
    adds r2, #1
    str r2, [sp, #8]
    cmp r0, #0
    beq lbl_0800befe
    ldr r0, lbl_0800c1c4 @ =0x0300154c
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
    ldr r2, lbl_0800c1c8 @ =0x030013b8
    ldrh r0, [r2]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    ldrh r1, [r3, #6]
    lsrs r1, r1, #2
    ldr r3, lbl_0800c1cc @ =0x030013ba
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
    ldr r2, lbl_0800c1bc @ =0x03000e7c
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
    ldr r3, lbl_0800c1d8 @ =0x030013d4
    ldrh r1, [r3, #0x12]
    lsrs r1, r1, #2
    ldr r2, lbl_0800c1c8 @ =0x030013b8
    ldrh r0, [r2]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    ldrh r0, [r3, #0x14]
    lsrs r0, r0, #2
    ldr r3, lbl_0800c1cc @ =0x030013ba
    ldrh r1, [r3]
    lsrs r1, r1, #2
    subs r0, r0, r1
    adds r0, #2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    mov r8, r0
    ldr r0, lbl_0800c1dc @ =0x03001588
    adds r0, #0x36
    ldrb r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800bfa2
    ldr r0, lbl_0800c1dc @ =0x03001588
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
    ldr r0, lbl_0800c1bc @ =0x03000e7c
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
    ldr r2, lbl_0800c1dc @ =0x03001588
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
    ldr r2, lbl_0800c1bc @ =0x03000e7c
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
    ldr r2, lbl_0800c1dc @ =0x03001588
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
    ldr r2, lbl_0800c1bc @ =0x03000e7c
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
    ldr r2, lbl_0800c1dc @ =0x03001588
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
    ldr r2, lbl_0800c1bc @ =0x03000e7c
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
    ldr r0, lbl_0800c1dc @ =0x03001588
    adds r0, #0x36
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c17a
    ldr r2, lbl_0800c1dc @ =0x03001588
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
    ldr r2, lbl_0800c1bc @ =0x03000e7c
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
    ldr r1, lbl_0800c1e0 @ =0x0300141c
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
    ldr r0, lbl_0800c1c0 @ =0x03001382
    strb r7, [r0]
    b lbl_0800c1e4
    .align 2, 0
lbl_0800c1b8: .4byte 0x0300002b
lbl_0800c1bc: .4byte 0x03000e7c
lbl_0800c1c0: .4byte 0x03001382
lbl_0800c1c4: .4byte 0x0300154c
lbl_0800c1c8: .4byte 0x030013b8
lbl_0800c1cc: .4byte 0x030013ba
lbl_0800c1d0: .4byte 0x000001ff
lbl_0800c1d4: .4byte 0xfffffe00
lbl_0800c1d8: .4byte 0x030013d4
lbl_0800c1dc: .4byte 0x03001588
lbl_0800c1e0: .4byte 0x0300141c
lbl_0800c1e4:
    b lbl_0800c2ae
lbl_0800c1e6:
    ldr r1, lbl_0800c200 @ =0x03001588
    ldr r4, [r1]
    ldrh r1, [r4]
    adds r4, #2
    movs r0, #0xff
    ands r1, r0
    adds r0, r7, r1
    cmp r0, #0x80
    ble lbl_0800c208
    ldr r2, lbl_0800c204 @ =0x03001382
    strb r7, [r2]
    b lbl_0800c2ae
    .align 2, 0
lbl_0800c200: .4byte 0x03001588
lbl_0800c204: .4byte 0x03001382
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
    ldr r3, lbl_0800c2c0 @ =0x030013b8
    ldrh r0, [r3]
    lsrs r0, r0, #2
    subs r0, r1, r0
    mov sb, r0
    mov r0, ip
    adds r0, #0x88
    adds r2, r2, r0
    ldrh r0, [r2]
    lsrs r0, r0, #2
    ldr r2, lbl_0800c2c4 @ =0x030013ba
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
    ldr r0, lbl_0800c2c8 @ =0x03000e7c
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
    ldr r3, lbl_0800c2d4 @ =0x03001382
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
lbl_0800c2c0: .4byte 0x030013b8
lbl_0800c2c4: .4byte 0x030013ba
lbl_0800c2c8: .4byte 0x03000e7c
lbl_0800c2cc: .4byte 0x000001ff
lbl_0800c2d0: .4byte 0xfffffe00
lbl_0800c2d4: .4byte 0x03001382

    thumb_func_start demo_main
demo_main: @ 0x0800c2d8
    push {lr}
    ldr r0, lbl_0800c2ec @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800c2f8
    cmp r0, #1
    bne lbl_0800c2f0
    bl sub_0800c2fc
    b lbl_0800c2f8
    .align 2, 0
lbl_0800c2ec: .4byte 0x030013d2
lbl_0800c2f0:
    cmp r0, #2
    bne lbl_0800c2f8
    bl sub_0800c384
lbl_0800c2f8:
    pop {r0}
    bx r0

    thumb_func_start sub_0800c2fc
sub_0800c2fc: @ 0x0800c2fc
    push {r4, r5, r6, r7, lr}
    ldr r3, lbl_0800c310 @ =0x030053ca
    ldrh r0, [r3]
    cmp r0, #0xfd
    bls lbl_0800c318
    ldr r1, lbl_0800c314 @ =0x03001380
    movs r0, #8
    strh r0, [r1]
    b lbl_0800c378
    .align 2, 0
lbl_0800c310: .4byte 0x030053ca
lbl_0800c314: .4byte 0x03001380
lbl_0800c318:
    ldr r1, lbl_0800c350 @ =0x0300137c
    ldr r6, lbl_0800c354 @ =0x03004fca
    ldrh r2, [r3]
    lsls r5, r2, #1
    adds r0, r5, r6
    ldrh r4, [r1]
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_0800c360
    ldr r7, lbl_0800c358 @ =0x030051ca
    adds r0, r5, r7
    ldrh r1, [r0]
    ldr r0, lbl_0800c35c @ =0x0000ffff
    cmp r1, r0
    bne lbl_0800c342
    adds r0, r2, #1
    strh r0, [r3]
    ldrh r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r6
    strh r4, [r0]
lbl_0800c342:
    ldrh r1, [r3]
    lsls r1, r1, #1
    adds r1, r1, r7
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_0800c378
    .align 2, 0
lbl_0800c350: .4byte 0x0300137c
lbl_0800c354: .4byte 0x03004fca
lbl_0800c358: .4byte 0x030051ca
lbl_0800c35c: .4byte 0x0000ffff
lbl_0800c360:
    adds r0, r2, #1
    strh r0, [r3]
    ldrh r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r6
    strh r4, [r0]
    ldr r1, lbl_0800c380 @ =0x030051ca
    ldrh r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #1
    strh r1, [r0]
lbl_0800c378:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c380: .4byte 0x030051ca

    thumb_func_start sub_0800c384
sub_0800c384: @ 0x0800c384
    push {r4, r5, r6, lr}
    ldr r3, lbl_0800c3b4 @ =0x030053ca
    ldrh r5, [r3]
    ldr r6, lbl_0800c3b8 @ =0x0300137c
    cmp r5, #0xfd
    bhi lbl_0800c3a2
    ldr r4, lbl_0800c3bc @ =0x030053cc
    ldrh r1, [r4]
    ldr r0, lbl_0800c3c0 @ =0x0000ffff
    cmp r1, r0
    beq lbl_0800c3a2
    adds r2, r6, #0
    ldrh r0, [r2]
    cmp r0, #0
    beq lbl_0800c3c8
lbl_0800c3a2:
    ldr r0, lbl_0800c3c4 @ =0x03001380
    movs r1, #8
    strh r1, [r0]
    ldrh r0, [r6]
    cmp r0, #0
    beq lbl_0800c3fc
    movs r0, #0
    strh r0, [r6]
    b lbl_0800c3fc
    .align 2, 0
lbl_0800c3b4: .4byte 0x030053ca
lbl_0800c3b8: .4byte 0x0300137c
lbl_0800c3bc: .4byte 0x030053cc
lbl_0800c3c0: .4byte 0x0000ffff
lbl_0800c3c4: .4byte 0x03001380
lbl_0800c3c8:
    cmp r1, #0
    bne lbl_0800c3dc
    adds r0, r5, #1
    strh r0, [r3]
    ldr r1, lbl_0800c404 @ =0x030051ca
    ldrh r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4]
lbl_0800c3dc:
    ldr r1, lbl_0800c408 @ =0x03004fca
    ldrh r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    strh r1, [r2]
    ldr r3, lbl_0800c40c @ =0x03001380
    ldr r2, lbl_0800c410 @ =0x030053ce
    ldrh r0, [r2]
    eors r0, r1
    ands r0, r1
    strh r0, [r3]
    strh r1, [r2]
    ldrh r0, [r4]
    subs r0, #1
    strh r0, [r4]
lbl_0800c3fc:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c404: .4byte 0x030051ca
lbl_0800c408: .4byte 0x03004fca
lbl_0800c40c: .4byte 0x03001380
lbl_0800c410: .4byte 0x030053ce

    thumb_func_start sub_0800c414
sub_0800c414: @ 0x0800c414
    ldr r2, lbl_0800c434 @ =0x0300137c
    ldr r1, lbl_0800c438 @ =0x03004fca
    ldr r0, lbl_0800c43c @ =0x030053ca
    ldrh r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    strh r1, [r2]
    ldr r3, lbl_0800c440 @ =0x03001380
    ldr r2, lbl_0800c444 @ =0x030053ce
    ldrh r0, [r2]
    eors r0, r1
    ands r0, r1
    strh r0, [r3]
    strh r1, [r2]
    bx lr
    .align 2, 0
lbl_0800c434: .4byte 0x0300137c
lbl_0800c438: .4byte 0x03004fca
lbl_0800c43c: .4byte 0x030053ca
lbl_0800c440: .4byte 0x03001380
lbl_0800c444: .4byte 0x030053ce

    thumb_func_start sub_0800c448
sub_0800c448: @ 0x0800c448
    push {r4, r5, r6, lr}
    ldr r0, lbl_0800c474 @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0800c48c
    ldr r4, lbl_0800c478 @ =0x030053cc
    ldr r6, lbl_0800c47c @ =0x030053ca
    ldr r5, lbl_0800c480 @ =0x030053ce
    movs r3, #0
    ldr r2, lbl_0800c484 @ =0x030051ca
    ldr r1, lbl_0800c488 @ =0x03004fca
    movs r0, #0xff
lbl_0800c460:
    strh r3, [r1]
    strh r3, [r2]
    adds r2, #2
    adds r1, #2
    subs r0, #1
    cmp r0, #0
    bge lbl_0800c460
    movs r0, #0
    strh r0, [r4]
    b lbl_0800c498
    .align 2, 0
lbl_0800c474: .4byte 0x030013d2
lbl_0800c478: .4byte 0x030053cc
lbl_0800c47c: .4byte 0x030053ca
lbl_0800c480: .4byte 0x030053ce
lbl_0800c484: .4byte 0x030051ca
lbl_0800c488: .4byte 0x03004fca
lbl_0800c48c:
    ldr r0, lbl_0800c4a4 @ =0x030053cc
    ldr r1, lbl_0800c4a8 @ =0x030051ca
    ldrh r1, [r1]
    strh r1, [r0]
    ldr r6, lbl_0800c4ac @ =0x030053ca
    ldr r5, lbl_0800c4b0 @ =0x030053ce
lbl_0800c498:
    movs r0, #0
    strh r0, [r6]
    strh r0, [r5]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c4a4: .4byte 0x030053cc
lbl_0800c4a8: .4byte 0x030051ca
lbl_0800c4ac: .4byte 0x030053ca
lbl_0800c4b0: .4byte 0x030053ce

    thumb_func_start ingame_main
ingame_main: @ 0x0800c4b4
    push {r4, lr}
    bl ingame_setvblank_callback
    movs r4, #0
    ldr r0, lbl_0800c4d4 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #6
    bls lbl_0800c4c8
    b lbl_0800c642
lbl_0800c4c8:
    lsls r0, r0, #2
    ldr r1, lbl_0800c4d8 @ =lbl_0800c4dc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800c4d4: .4byte 0x03000c72
lbl_0800c4d8: .4byte lbl_0800c4dc
lbl_0800c4dc: @ jump table
    .4byte lbl_0800c4f8 @ case 0
    .4byte lbl_0800c524 @ case 1
    .4byte lbl_0800c540 @ case 2
    .4byte lbl_0800c5e2 @ case 3
    .4byte lbl_0800c642 @ case 4
    .4byte lbl_0800c62c @ case 5
    .4byte lbl_0800c63a @ case 6
lbl_0800c4f8:
    ldr r0, lbl_0800c51c @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800c508
    bl sub_0800c448
lbl_0800c508:
    ldr r0, lbl_0800c520 @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0800c514
    bl sub_0800c414
lbl_0800c514:
    bl init_and_load_generics
    b lbl_0800c532
    .align 2, 0
lbl_0800c51c: .4byte 0x03000c75
lbl_0800c520: .4byte 0x030013d2
lbl_0800c524:
    bl sub_08057a24
    bl sub_0805c3ac
    cmp r0, #0
    bne lbl_0800c532
    b lbl_0800c642
lbl_0800c532:
    ldr r1, lbl_0800c53c @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_0800c642
    .align 2, 0
lbl_0800c53c: .4byte 0x03000c72
lbl_0800c540:
    bl demo_main
    bl sub_08057a24
    ldr r0, lbl_0800c5ac @ =0x03001380
    ldr r1, lbl_0800c5b0 @ =0x0300168c
    ldrh r2, [r0]
    ldrh r0, [r1, #4]
    ands r0, r2
    cmp r0, #0
    bne lbl_0800c562
    ldr r0, lbl_0800c5b4 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800c572
lbl_0800c562:
    bl sub_08057c4c
    cmp r0, #0
    beq lbl_0800c572
    ldr r1, lbl_0800c5b8 @ =0x03000c72
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0800c572:
    ldr r0, lbl_0800c5b8 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0800c634
    ldr r1, lbl_0800c5bc @ =0x03001600
    ldr r2, lbl_0800c5c0 @ =0x030013d4
    ldrh r0, [r2, #0x12]
    strh r0, [r1]
    ldr r1, lbl_0800c5c4 @ =0x03001602
    ldrh r0, [r2, #0x14]
    strh r0, [r1]
    ldr r0, lbl_0800c5c8 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    bne lbl_0800c59c
    ldr r1, lbl_0800c5cc @ =0x030053d0
    movs r0, #1
    strb r0, [r1]
lbl_0800c59c:
    ldr r1, lbl_0800c5d0 @ =0x03001606
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0800c5d4
    subs r0, #1
    strh r0, [r1]
    b lbl_0800c5dc
    .align 2, 0
lbl_0800c5ac: .4byte 0x03001380
lbl_0800c5b0: .4byte 0x0300168c
lbl_0800c5b4: .4byte 0x03000bf0
lbl_0800c5b8: .4byte 0x03000c72
lbl_0800c5bc: .4byte 0x03001600
lbl_0800c5c0: .4byte 0x030013d4
lbl_0800c5c4: .4byte 0x03001602
lbl_0800c5c8: .4byte 0x0300137c
lbl_0800c5cc: .4byte 0x030053d0
lbl_0800c5d0: .4byte 0x03001606
lbl_0800c5d4:
    bl samus_update
    bl samus_update_hitbox
lbl_0800c5dc:
    bl update_in_game_timer
    b lbl_0800c634
lbl_0800c5e2:
    bl sub_08057af8
    bl sub_0805c460
    cmp r0, #0
    beq lbl_0800c642
    ldr r1, lbl_0800c61c @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_0800c620 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800c618
    ldr r0, lbl_0800c624 @ =0x0300007d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800c618
    ldr r0, lbl_0800c628 @ =0x0300007e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800c642
lbl_0800c618:
    movs r4, #1
    b lbl_0800c642
    .align 2, 0
lbl_0800c61c: .4byte 0x03000c72
lbl_0800c620: .4byte 0x03000bf0
lbl_0800c624: .4byte 0x0300007d
lbl_0800c628: .4byte 0x0300007e
lbl_0800c62c:
    bl sub_08057a24
    bl samus_update
lbl_0800c634:
    bl sub_08056e28
    b lbl_0800c642
lbl_0800c63a:
    bl sub_0800cde8
    bl sub_08056e28
lbl_0800c642:
    ldr r0, lbl_0800c660 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #5
    bne lbl_0800c664
    bl samus_graphics_update
    bl draw_samus
    bl reset_free_oam
    bl update_room_info
    b lbl_0800c6de
    .align 2, 0
lbl_0800c660: .4byte 0x03000c72
lbl_0800c664:
    cmp r0, #0
    beq lbl_0800c6de
    bl sub_08056e74
    bl update_sprites
    ldr r0, lbl_0800c684 @ =0x03001608
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800c688
    bl process_general_scrolling
    bl samus_graphics_update
    b lbl_0800c694
    .align 2, 0
lbl_0800c684: .4byte 0x03001608
lbl_0800c688:
    ldr r0, lbl_0800c6e8 @ =0x0300003d
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0800c694
    bl process_general_scrolling
lbl_0800c694:
    bl update_arm_cannon_and_weapons
    bl draw_hud
    bl sub_0800d36c
    bl process_particle_effects
    bl call_draw_projectile8_bit_false
    ldr r0, lbl_0800c6ec @ =0x0300007c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800c6b4
    bl call_draw_sprite
lbl_0800c6b4:
    ldr r0, lbl_0800c6f0 @ =0x03001608
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800c6c0
    bl draw_samus
lbl_0800c6c0:
    bl sub_0800d4bc
    bl call_draw_projectile8_bit_true
    bl reset_free_oam
    bl update_room_info
    ldr r0, lbl_0800c6f4 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0800c6de
    bl call_check_low_health
lbl_0800c6de:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800c6e8: .4byte 0x0300003d
lbl_0800c6ec: .4byte 0x0300007c
lbl_0800c6f0: .4byte 0x03001608
lbl_0800c6f4: .4byte 0x03000c72

    thumb_func_start ingame_setvblank_callback
ingame_setvblank_callback: @ 0x0800c6f8
    push {lr}
    ldr r0, lbl_0800c710 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0800c724
    cmp r0, #2
    bgt lbl_0800c714
    cmp r0, #0
    blt lbl_0800c724
    b lbl_0800c718
    .align 2, 0
lbl_0800c710: .4byte 0x03000c72
lbl_0800c714:
    cmp r0, #3
    bne lbl_0800c724
lbl_0800c718:
    ldr r0, lbl_0800c720 @ =ingame_load_vblank_callback
    bl set_vblank_callback
    b lbl_0800c72a
    .align 2, 0
lbl_0800c720: .4byte ingame_load_vblank_callback
lbl_0800c724:
    ldr r0, lbl_0800c730 @ =ingame_vblank_callback
    bl set_vblank_callback
lbl_0800c72a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c730: .4byte ingame_vblank_callback

    thumb_func_start update_samus_graphics
update_samus_graphics: @ 0x0800c734
    push {r4, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    ldr r0, lbl_0800c860 @ =0x03001608
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800c744
    b lbl_0800c85a
lbl_0800c744:
    ldrh r0, [r3, #8]
    cmp r0, #0
    beq lbl_0800c762
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #4]
    str r0, [r2]
    ldr r0, lbl_0800c868 @ =0x06010000
    str r0, [r2, #4]
    ldrh r0, [r3, #8]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c762:
    ldrh r0, [r3, #0x10]
    cmp r0, #0
    beq lbl_0800c780
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0xc]
    str r0, [r2]
    ldr r0, lbl_0800c86c @ =0x06010400
    str r0, [r2, #4]
    ldrh r0, [r3, #0x10]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c780:
    ldrh r0, [r3, #0x18]
    cmp r0, #0
    beq lbl_0800c79e
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x14]
    str r0, [r2]
    ldr r0, lbl_0800c870 @ =0x06010280
    str r0, [r2, #4]
    ldrh r0, [r3, #0x18]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c79e:
    ldrh r0, [r3, #0x20]
    cmp r0, #0
    beq lbl_0800c7bc
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x1c]
    str r0, [r2]
    ldr r0, lbl_0800c874 @ =0x06010680
    str r0, [r2, #4]
    ldrh r0, [r3, #0x20]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c7bc:
    ldrh r0, [r3, #0x2c]
    cmp r0, #0
    beq lbl_0800c7da
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x28]
    str r0, [r2]
    ldr r0, lbl_0800c878 @ =0x06010800
    str r0, [r2, #4]
    ldrh r0, [r3, #0x2c]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c7da:
    ldrh r0, [r3, #0x34]
    cmp r0, #0
    beq lbl_0800c7f8
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x30]
    str r0, [r2]
    ldr r0, lbl_0800c87c @ =0x06010c00
    str r0, [r2, #4]
    ldrh r0, [r3, #0x34]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c7f8:
    adds r1, r3, #0
    adds r1, #0x40
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0800c81a
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x3c]
    str r0, [r2]
    ldr r0, lbl_0800c880 @ =0x06010840
    str r0, [r2, #4]
    ldrh r0, [r1]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c81a:
    adds r1, r3, #0
    adds r1, #0x48
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0800c83c
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, [r3, #0x44]
    str r0, [r2]
    ldr r0, lbl_0800c884 @ =0x06010c40
    str r0, [r2, #4]
    ldrh r0, [r1]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c83c:
    cmp r4, #0
    beq lbl_0800c85a
    ldr r2, lbl_0800c864 @ =0x040000d4
    ldr r0, lbl_0800c888 @ =0x030053e0
    str r0, [r2]
    ldr r0, lbl_0800c88c @ =0x05000200
    str r0, [r2, #4]
    ldr r0, lbl_0800c890 @ =0x03005440
    ldrh r0, [r0]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c85a:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c860: .4byte 0x03001608
lbl_0800c864: .4byte 0x040000d4
lbl_0800c868: .4byte 0x06010000
lbl_0800c86c: .4byte 0x06010400
lbl_0800c870: .4byte 0x06010280
lbl_0800c874: .4byte 0x06010680
lbl_0800c878: .4byte 0x06010800
lbl_0800c87c: .4byte 0x06010c00
lbl_0800c880: .4byte 0x06010840
lbl_0800c884: .4byte 0x06010c40
lbl_0800c888: .4byte 0x030053e0
lbl_0800c88c: .4byte 0x05000200
lbl_0800c890: .4byte 0x03005440

    thumb_func_start ingame_load_vblank_callback
ingame_load_vblank_callback: @ 0x0800c894
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r3, lbl_0800c9a0 @ =0x040000d4
    ldr r0, lbl_0800c9a4 @ =0x03000e7c
    str r0, [r3]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r3, #4]
    ldr r0, lbl_0800c9a8 @ =0x84000100
    str r0, [r3, #8]
    ldr r0, [r3, #8]
    ldr r6, lbl_0800c9ac @ =0x03000080
    ldrb r1, [r6, #7]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c934
    ldr r2, lbl_0800c9b0 @ =0x040000b0
    ldr r7, lbl_0800c9b4 @ =0x02026300
    str r7, [r2]
    ldr r5, [r6]
    str r5, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    ldr r1, lbl_0800c9b8 @ =0x80600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r0, sp
    movs r4, #0
    strb r4, [r0]
    strb r4, [r0]
    strb r4, [r0]
    strb r4, [r0]
    str r7, [r2]
    str r5, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    movs r1, #0xc0
    lsls r1, r1, #0xf
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r0, sp
    strb r4, [r0]
    ldr r0, lbl_0800c9bc @ =0x03000c78
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    ldrb r0, [r6, #6]
    mov ip, r0
    cmp r1, #0
    bne lbl_0800c920
    mov r0, sp
    strb r1, [r0]
    ldr r0, lbl_0800c9c0 @ =0x02026d00
    str r0, [r3]
    str r7, [r3, #4]
    ldrh r0, [r6, #4]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r3, #8]
    ldr r0, [r3, #8]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_0800c9c4 @ =0x03000010
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0800c920:
    mov r0, sp
    strb r4, [r0]
    str r7, [r2]
    str r5, [r2, #4]
    mov r1, ip
    lsrs r0, r1, #1
    ldr r1, lbl_0800c9c8 @ =0xa2600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800c934:
    ldr r1, lbl_0800c9cc @ =0x03001588
    movs r0, #0
    bl update_samus_graphics
    ldr r2, lbl_0800c9d0 @ =0x03000008
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800c950
    ldr r0, lbl_0800c9d4 @ =0x04000050
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_0800c950:
    ldr r1, lbl_0800c9d8 @ =0x04000054
    ldr r0, lbl_0800c9dc @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #0x44
    ldr r2, lbl_0800c9e0 @ =0x030000e4
    ldrh r0, [r2]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #2]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #4]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #6]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #8]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0xa]
    strh r0, [r1]
    ldr r3, lbl_0800c9e4 @ =0x0400001c
    ldr r1, lbl_0800c9e8 @ =0x0300002a
    ldrb r0, [r1]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r3]
    adds r3, #2
    ldrb r0, [r1]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrh r0, [r0, #2]
    strh r0, [r3]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800c9a0: .4byte 0x040000d4
lbl_0800c9a4: .4byte 0x03000e7c
lbl_0800c9a8: .4byte 0x84000100
lbl_0800c9ac: .4byte 0x03000080
lbl_0800c9b0: .4byte 0x040000b0
lbl_0800c9b4: .4byte 0x02026300
lbl_0800c9b8: .4byte 0x80600000
lbl_0800c9bc: .4byte 0x03000c78
lbl_0800c9c0: .4byte 0x02026d00
lbl_0800c9c4: .4byte 0x03000010
lbl_0800c9c8: .4byte 0xa2600000
lbl_0800c9cc: .4byte 0x03001588
lbl_0800c9d0: .4byte 0x03000008
lbl_0800c9d4: .4byte 0x04000050
lbl_0800c9d8: .4byte 0x04000054
lbl_0800c9dc: .4byte 0x030013ae
lbl_0800c9e0: .4byte 0x030000e4
lbl_0800c9e4: .4byte 0x0400001c
lbl_0800c9e8: .4byte 0x0300002a

    thumb_func_start sub_0800c9ec
sub_0800c9ec: @ 0x0800c9ec
    push {lr}
    ldr r1, lbl_0800ca4c @ =0x040000d4
    ldr r0, lbl_0800ca50 @ =0x03000e7c
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0800ca54 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r1, lbl_0800ca58 @ =0x03001588
    movs r0, #0
    bl update_samus_graphics
    ldr r1, lbl_0800ca5c @ =0x04000010
    ldr r2, lbl_0800ca60 @ =0x030000e4
    ldrh r0, [r2]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #2]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #4]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #6]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #8]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0xa]
    strh r0, [r1]
    ldr r3, lbl_0800ca64 @ =0x0400001c
    ldr r1, lbl_0800ca68 @ =0x0300002a
    ldrb r0, [r1]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r3]
    adds r3, #2
    ldrb r0, [r1]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrh r0, [r0, #2]
    strh r0, [r3]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800ca4c: .4byte 0x040000d4
lbl_0800ca50: .4byte 0x03000e7c
lbl_0800ca54: .4byte 0x84000100
lbl_0800ca58: .4byte 0x03001588
lbl_0800ca5c: .4byte 0x04000010
lbl_0800ca60: .4byte 0x030000e4
lbl_0800ca64: .4byte 0x0400001c
lbl_0800ca68: .4byte 0x0300002a

    thumb_func_start ingame_vblank_callback
ingame_vblank_callback: @ 0x0800ca6c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r3, lbl_0800cb60 @ =0x040000d4
    ldr r0, lbl_0800cb64 @ =0x03000e7c
    str r0, [r3]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r3, #4]
    ldr r0, lbl_0800cb68 @ =0x84000100
    str r0, [r3, #8]
    ldr r0, [r3, #8]
    ldr r6, lbl_0800cb6c @ =0x03000080
    ldrb r1, [r6, #7]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800cb0c
    ldr r2, lbl_0800cb70 @ =0x040000b0
    ldr r7, lbl_0800cb74 @ =0x02026300
    str r7, [r2]
    ldr r5, [r6]
    str r5, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    ldr r1, lbl_0800cb78 @ =0x80600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r0, sp
    movs r4, #0
    strb r4, [r0]
    strb r4, [r0]
    strb r4, [r0]
    strb r4, [r0]
    str r7, [r2]
    str r5, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    movs r1, #0xc0
    lsls r1, r1, #0xf
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r0, sp
    strb r4, [r0]
    ldr r0, lbl_0800cb7c @ =0x03000c78
    ldrh r0, [r0]
    movs r1, #1
    ands r1, r0
    ldrb r0, [r6, #6]
    mov ip, r0
    cmp r1, #0
    bne lbl_0800caf8
    mov r0, sp
    strb r1, [r0]
    ldr r0, lbl_0800cb80 @ =0x02026d00
    str r0, [r3]
    str r7, [r3, #4]
    ldrh r0, [r6, #4]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r3, #8]
    ldr r0, [r3, #8]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_0800cb84 @ =0x03000010
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0800caf8:
    mov r0, sp
    strb r4, [r0]
    str r7, [r2]
    str r5, [r2, #4]
    mov r1, ip
    lsrs r0, r1, #1
    ldr r1, lbl_0800cb88 @ =0xa2600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0800cb0c:
    ldr r1, lbl_0800cb8c @ =0x03001588
    movs r0, #1
    bl update_samus_graphics
    ldr r2, lbl_0800cb90 @ =0x0400004c
    ldr r0, lbl_0800cb94 @ =0x0300139c
    ldrh r0, [r0]
    lsls r0, r0, #4
    ldr r1, lbl_0800cb98 @ =0x0300139e
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    subs r2, #0x3c
    ldr r1, lbl_0800cb9c @ =0x030000e4
    ldrh r0, [r1]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #2]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #4]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #6]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #8]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #0xa]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #0xc]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #0xe]
    strh r0, [r2]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800cb60: .4byte 0x040000d4
lbl_0800cb64: .4byte 0x03000e7c
lbl_0800cb68: .4byte 0x84000100
lbl_0800cb6c: .4byte 0x03000080
lbl_0800cb70: .4byte 0x040000b0
lbl_0800cb74: .4byte 0x02026300
lbl_0800cb78: .4byte 0x80600000
lbl_0800cb7c: .4byte 0x03000c78
lbl_0800cb80: .4byte 0x02026d00
lbl_0800cb84: .4byte 0x03000010
lbl_0800cb88: .4byte 0xa2600000
lbl_0800cb8c: .4byte 0x03001588
lbl_0800cb90: .4byte 0x0400004c
lbl_0800cb94: .4byte 0x0300139c
lbl_0800cb98: .4byte 0x0300139e
lbl_0800cb9c: .4byte 0x030000e4
lbl_0800cba0:
    .byte 0x81, 0xB0, 0x69, 0x46, 0x00, 0x20, 0x08, 0x70, 0x01, 0xB0, 0x70, 0x47

    thumb_func_start init_and_load_generics
init_and_load_generics: @ 0x0800cbac
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r3, lbl_0800cd64 @ =0x04000208
    movs r0, #0
    strh r0, [r3]
    ldr r2, lbl_0800cd68 @ =0x04000004
    ldrh r1, [r2]
    ldr r0, lbl_0800cd6c @ =0x0000ffef
    ands r0, r1
    strh r0, [r2]
    ldr r2, lbl_0800cd70 @ =0x04000200
    ldrh r1, [r2]
    ldr r0, lbl_0800cd74 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0800cd78 @ =0x04000202
    movs r0, #2
    strh r0, [r1]
    movs r0, #1
    strh r0, [r3]
    ldr r0, lbl_0800cd7c @ =0x0800cba1
    bl set_vblank_callback
    ldr r0, lbl_0800cd80 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800cbf2
    ldr r0, lbl_0800cd84 @ =0x0300007e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800cbfa
lbl_0800cbf2:
    bl clear_ram
    bl load_common_sprites_gfx
lbl_0800cbfa:
    ldr r4, lbl_0800cd88 @ =0x030013ae
    movs r0, #0x10
    strh r0, [r4]
    bl sub_0805c08c
    ldr r1, lbl_0800cd8c @ =0x04000054
    ldrh r0, [r4]
    strh r0, [r1]
    ldr r0, lbl_0800cd90 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800cc22
    ldr r0, lbl_0800cd94 @ =0x0300007d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800cc34
lbl_0800cc22:
    ldr r1, lbl_0800cd98 @ =0x0201e000
    ldr r2, lbl_0800cd9c @ =0x06010000
    movs r3, #0x80
    lsls r3, r3, #7
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl dma_transfer
lbl_0800cc34:
    ldr r1, lbl_0800cda0 @ =0x03000000
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_0800cda4 @ =0x040000d4
    ldr r0, lbl_0800cda8 @ =0x0832ba08
    str r0, [r1]
    ldr r0, lbl_0800cdac @ =0x05000240
    str r0, [r1, #4]
    ldr r0, lbl_0800cdb0 @ =0x80000060
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    bl init_samus
    ldr r1, lbl_0800cdb4 @ =0x04000006
lbl_0800cc50:
    ldrh r0, [r1]
    subs r0, #0x15
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x8b
    bls lbl_0800cc50
    bl load_room
    ldr r1, lbl_0800cdb4 @ =0x04000006
lbl_0800cc62:
    ldrh r0, [r1]
    subs r0, #0x15
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x8b
    bls lbl_0800cc62
    ldr r0, lbl_0800cd90 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800cc8e
    ldr r0, lbl_0800cd80 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800cc8e
    bl samus_update
    bl samus_update_hitbox
lbl_0800cc8e:
    bl samus_graphics_update
    ldr r2, lbl_0800cda4 @ =0x040000d4
    ldr r0, lbl_0800cdb8 @ =0x030053e0
    str r0, [r2]
    ldr r0, lbl_0800cdbc @ =0x05000200
    str r0, [r2, #4]
    ldr r0, lbl_0800cdc0 @ =0x03005440
    ldrh r0, [r0]
    lsrs r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    bl sub_0800c9ec
    ldr r1, lbl_0800cdb4 @ =0x04000006
lbl_0800ccb2:
    ldrh r0, [r1]
    subs r0, #0x15
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x8b
    bls lbl_0800ccb2
    bl reset_hud
    bl load_sprite_data
    bl call_load_beam_graphics_and_clear_projectiles
    ldr r7, lbl_0800cd90 @ =0x03000bf0
    movs r0, #0
    ldrsb r0, [r7, r0]
    cmp r0, #0
    beq lbl_0800cd06
    ldr r1, lbl_0800cdc4 @ =0x02022000
    ldr r2, lbl_0800cdc8 @ =0x06014000
    movs r3, #0x80
    lsls r3, r3, #7
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl dma_transfer
    ldr r1, lbl_0800cdcc @ =0x02035700
    ldr r2, lbl_0800cdd0 @ =0x05000300
    movs r3, #0x80
    lsls r3, r3, #1
    str r4, [sp]
    movs r0, #3
    bl dma_transfer
    ldr r1, lbl_0800cdd4 @ =0x02035460
    ldr r2, lbl_0800cdd8 @ =0x05000060
    movs r3, #0xd0
    lsls r3, r3, #1
    str r4, [sp]
    movs r0, #3
    bl dma_transfer
lbl_0800cd06:
    bl sub_08055f68
    ldr r5, lbl_0800cd80 @ =0x03000c75
    movs r4, #0
    ldrsb r4, [r5, r4]
    cmp r4, #0
    bne lbl_0800cd20
    bl update_sprites
    movs r0, #1
    strb r0, [r5]
    ldr r0, lbl_0800cddc @ =0x03001606
    strh r4, [r0]
lbl_0800cd20:
    ldr r1, lbl_0800cd88 @ =0x030013ae
    movs r0, #0xf
    strh r0, [r1]
    ldr r1, lbl_0800cdb4 @ =0x04000006
    ldrh r0, [r1]
    subs r0, #0x15
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r6, lbl_0800cd84 @ =0x0300007e
    adds r3, r7, #0
    ldr r4, lbl_0800cd94 @ =0x0300007d
    ldr r2, lbl_0800cde0 @ =0x03000c1d
    ldr r5, lbl_0800cde4 @ =ingame_load_vblank_callback
    cmp r0, #0x8b
    bhi lbl_0800cd4a
lbl_0800cd3e:
    ldrh r0, [r1]
    subs r0, #0x15
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x8b
    bls lbl_0800cd3e
lbl_0800cd4a:
    movs r0, #0
    strb r0, [r2]
    strb r0, [r3]
    strb r0, [r4]
    strb r0, [r6]
    adds r0, r5, #0
    bl set_vblank_callback
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800cd64: .4byte 0x04000208
lbl_0800cd68: .4byte 0x04000004
lbl_0800cd6c: .4byte 0x0000ffef
lbl_0800cd70: .4byte 0x04000200
lbl_0800cd74: .4byte 0x0000fffd
lbl_0800cd78: .4byte 0x04000202
lbl_0800cd7c: .4byte 0x0800cba1
lbl_0800cd80: .4byte 0x03000c75
lbl_0800cd84: .4byte 0x0300007e
lbl_0800cd88: .4byte 0x030013ae
lbl_0800cd8c: .4byte 0x04000054
lbl_0800cd90: .4byte 0x03000bf0
lbl_0800cd94: .4byte 0x0300007d
lbl_0800cd98: .4byte 0x0201e000
lbl_0800cd9c: .4byte 0x06010000
lbl_0800cda0: .4byte 0x03000000
lbl_0800cda4: .4byte 0x040000d4
lbl_0800cda8: .4byte 0x0832ba08
lbl_0800cdac: .4byte 0x05000240
lbl_0800cdb0: .4byte 0x80000060
lbl_0800cdb4: .4byte 0x04000006
lbl_0800cdb8: .4byte 0x030053e0
lbl_0800cdbc: .4byte 0x05000200
lbl_0800cdc0: .4byte 0x03005440
lbl_0800cdc4: .4byte 0x02022000
lbl_0800cdc8: .4byte 0x06014000
lbl_0800cdcc: .4byte 0x02035700
lbl_0800cdd0: .4byte 0x05000300
lbl_0800cdd4: .4byte 0x02035460
lbl_0800cdd8: .4byte 0x05000060
lbl_0800cddc: .4byte 0x03001606
lbl_0800cde0: .4byte 0x03000c1d
lbl_0800cde4: .4byte ingame_load_vblank_callback

    thumb_func_start sub_0800cde8
sub_0800cde8: @ 0x0800cde8
    push {r4, r5, r6, r7, lr}
    movs r5, #0
    movs r6, #0
    ldr r1, lbl_0800cea0 @ =0x03001600
    ldr r7, lbl_0800cea4 @ =0x030013d4
    ldrh r0, [r7, #0x12]
    strh r0, [r1]
    ldr r1, lbl_0800cea8 @ =0x03001602
    ldrh r0, [r7, #0x14]
    strh r0, [r1]
    ldr r2, lbl_0800ceac @ =0x03001380
    ldrh r1, [r2]
    movs r0, #0xa
    ands r0, r1
    adds r4, r7, #0
    cmp r0, #0
    beq lbl_0800ce14
    ldr r0, lbl_0800ceb0 @ =0x03000c72
    movs r1, #2
    strh r1, [r0]
    ldr r0, lbl_0800ceb4 @ =0x0300007f
    strb r6, [r0]
lbl_0800ce14:
    ldrh r1, [r2]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce28
    ldr r0, lbl_0800ceb4 @ =0x0300007f
    ldrb r1, [r0]
    movs r2, #1
    eors r1, r2
    strb r1, [r0]
lbl_0800ce28:
    ldr r0, lbl_0800ceb8 @ =0x0300137c
    ldrh r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce36
    movs r5, #0xc
lbl_0800ce36:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce42
    movs r5, #0xc
    rsbs r5, r5, #0
lbl_0800ce42:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce4e
    movs r6, #0xc
    rsbs r6, r6, #0
lbl_0800ce4e:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce58
    movs r6, #0xc
lbl_0800ce58:
    movs r0, #0xc0
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce6a
    lsls r0, r5, #0x11
    asrs r5, r0, #0x10
    lsls r0, r6, #0x11
    asrs r6, r0, #0x10
lbl_0800ce6a:
    ldrh r1, [r4, #0x12]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce7c
    movs r0, #0
    strh r0, [r4, #0x12]
lbl_0800ce7c:
    ldrh r1, [r4, #0x14]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ce8a
    movs r0, #0
    strh r0, [r4, #0x14]
lbl_0800ce8a:
    ldr r1, lbl_0800cebc @ =0x0300009c
    ldrh r0, [r1, #0xc]
    lsls r2, r0, #6
    cmp r5, #0
    bge lbl_0800cec4
    ldrh r0, [r4, #0x12]
    cmn r0, r5
    bge lbl_0800cec0
    movs r0, #0
    strh r0, [r4, #0x12]
    b lbl_0800ced4
    .align 2, 0
lbl_0800cea0: .4byte 0x03001600
lbl_0800cea4: .4byte 0x030013d4
lbl_0800cea8: .4byte 0x03001602
lbl_0800ceac: .4byte 0x03001380
lbl_0800ceb0: .4byte 0x03000c72
lbl_0800ceb4: .4byte 0x0300007f
lbl_0800ceb8: .4byte 0x0300137c
lbl_0800cebc: .4byte 0x0300009c
lbl_0800cec0:
    adds r0, r0, r5
    b lbl_0800ced2
lbl_0800cec4:
    ldrh r3, [r7, #0x12]
    subs r0, r2, r5
    cmp r3, r0
    ble lbl_0800ced0
    strh r2, [r7, #0x12]
    b lbl_0800ced4
lbl_0800ced0:
    adds r0, r3, r5
lbl_0800ced2:
    strh r0, [r7, #0x12]
lbl_0800ced4:
    ldrh r0, [r1, #0xe]
    lsls r2, r0, #6
    cmp r6, #0
    bge lbl_0800ceea
    ldrh r0, [r4, #0x14]
    cmn r0, r6
    bge lbl_0800cee6
    movs r0, #0
    b lbl_0800cef8
lbl_0800cee6:
    adds r0, r0, r6
    b lbl_0800cef8
lbl_0800ceea:
    ldrh r1, [r4, #0x14]
    subs r0, r2, r6
    cmp r1, r0
    ble lbl_0800cef6
    strh r2, [r4, #0x14]
    b lbl_0800cefa
lbl_0800cef6:
    adds r0, r1, r6
lbl_0800cef8:
    strh r0, [r4, #0x14]
lbl_0800cefa:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start update_sprites
update_sprites: @ 0x0800cf00
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r6, lbl_0800cfa8 @ =0x03000738
    ldr r0, lbl_0800cfac @ =0x03000c77
    ldrb r0, [r0]
    str r0, [sp]
    ldr r0, lbl_0800cfb0 @ =0x03000002
    ldrh r0, [r0]
    lsrs r0, r0, #4
    str r0, [sp, #4]
    ldr r0, lbl_0800cfb4 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0800cf28
    b lbl_0800d138
lbl_0800cf28:
    bl sprite_debris_process_all
    bl check_stop_sprites_pose
    cmp r0, #0
    bne lbl_0800d028
    bl samus_sprite_collision
    movs r7, #0
    ldr r5, lbl_0800cfb8 @ =0x030001ac
    ldr r4, lbl_0800cfbc @ =0x040000d4
    ldr r0, lbl_0800cfc0 @ =0x0300083c
    mov sl, r0
    ldr r1, lbl_0800cfc4 @ =0x082b0cac
    mov sb, r1
lbl_0800cf46:
    lsls r2, r7, #3
    subs r0, r2, r7
    lsls r0, r0, #3
    adds r3, r0, r5
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    beq lbl_0800d00e
    str r3, [r4]
    ldr r0, lbl_0800cfa8 @ =0x03000738
    str r0, [r4, #4]
    ldr r0, lbl_0800cfc8 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, [sp]
    adds r0, r1, r7
    ldr r1, [sp, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    movs r1, #0x1f
    ands r0, r1
    add r0, sb
    ldrb r0, [r0]
    mov r1, sl
    strb r0, [r1]
    adds r0, r6, #0
    bl update_sprite_stun_timer
    adds r0, r6, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800cfd0
    ldr r0, lbl_0800cfcc @ =0x0875f1e8
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
    b lbl_0800cfde
    .align 2, 0
lbl_0800cfa8: .4byte 0x03000738
lbl_0800cfac: .4byte 0x03000c77
lbl_0800cfb0: .4byte 0x03000002
lbl_0800cfb4: .4byte 0x03000c72
lbl_0800cfb8: .4byte 0x030001ac
lbl_0800cfbc: .4byte 0x040000d4
lbl_0800cfc0: .4byte 0x0300083c
lbl_0800cfc4: .4byte 0x082b0cac
lbl_0800cfc8: .4byte 0x8000001c
lbl_0800cfcc: .4byte 0x0875f1e8
lbl_0800cfd0:
    ldr r0, lbl_0800d01c @ =0x0875e8c0
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
lbl_0800cfde:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800cffa
    adds r0, r6, #0
    bl samus_standing_on_sprite
    adds r0, r6, #0
    bl update_sprite_anim
    adds r0, r6, #0
    bl check_sprite_is_on_screen
lbl_0800cffa:
    ldr r0, lbl_0800d020 @ =0x03000738
    str r0, [r4]
    mov r1, r8
    subs r0, r1, r7
    lsls r0, r0, #3
    adds r0, r0, r5
    str r0, [r4, #4]
    ldr r0, lbl_0800d024 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
lbl_0800d00e:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x17
    bls lbl_0800cf46
    b lbl_0800d214
    .align 2, 0
lbl_0800d01c: .4byte 0x0875e8c0
lbl_0800d020: .4byte 0x03000738
lbl_0800d024: .4byte 0x8000001c
lbl_0800d028:
    movs r7, #0
    ldr r5, lbl_0800d0b0 @ =0x040000d4
    mov sl, r6
    ldr r0, lbl_0800d0b4 @ =0x8000001c
    mov sb, r0
lbl_0800d032:
    lsls r2, r7, #3
    subs r0, r2, r7
    lsls r0, r0, #3
    ldr r1, lbl_0800d0b8 @ =0x030001ac
    adds r4, r0, r1
    ldrh r1, [r4]
    movs r0, #1
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    beq lbl_0800d12a
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800d060
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d10c
lbl_0800d060:
    str r4, [r5]
    mov r0, sl
    str r0, [r5, #4]
    mov r1, sb
    str r1, [r5, #8]
    ldr r0, [r5, #8]
    ldr r2, lbl_0800d0bc @ =0x082b0cac
    ldr r1, [sp]
    adds r0, r1, r7
    ldr r1, [sp, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    movs r1, #0x1f
    ands r0, r1
    adds r0, r0, r2
    ldrb r0, [r0]
    ldr r1, lbl_0800d0c0 @ =0x0300083c
    strb r0, [r1]
    adds r0, r6, #0
    bl update_sprite_stun_timer
    adds r0, r6, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d0c8
    ldr r0, lbl_0800d0c4 @ =0x0875f1e8
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
    b lbl_0800d0d6
    .align 2, 0
lbl_0800d0b0: .4byte 0x040000d4
lbl_0800d0b4: .4byte 0x8000001c
lbl_0800d0b8: .4byte 0x030001ac
lbl_0800d0bc: .4byte 0x082b0cac
lbl_0800d0c0: .4byte 0x0300083c
lbl_0800d0c4: .4byte 0x0875f1e8
lbl_0800d0c8:
    ldr r0, lbl_0800d104 @ =0x0875e8c0
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
lbl_0800d0d6:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d0f2
    adds r0, r6, #0
    bl samus_standing_on_sprite
    adds r0, r6, #0
    bl update_sprite_anim
    adds r0, r6, #0
    bl check_sprite_is_on_screen
lbl_0800d0f2:
    mov r0, sl
    str r0, [r5]
    mov r1, r8
    subs r0, r1, r7
    lsls r0, r0, #3
    ldr r1, lbl_0800d108 @ =0x030001ac
    adds r0, r0, r1
    str r0, [r5, #4]
    b lbl_0800d124
    .align 2, 0
lbl_0800d104: .4byte 0x0875e8c0
lbl_0800d108: .4byte 0x030001ac
lbl_0800d10c:
    str r4, [r5]
    mov r1, sl
    str r1, [r5, #4]
    mov r0, sb
    str r0, [r5, #8]
    ldr r0, [r5, #8]
    adds r0, r6, #0
    bl check_sprite_is_on_screen
    mov r1, sl
    str r1, [r5]
    str r4, [r5, #4]
lbl_0800d124:
    mov r0, sb
    str r0, [r5, #8]
    ldr r0, [r5, #8]
lbl_0800d12a:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x17
    bhi lbl_0800d136
    b lbl_0800d032
lbl_0800d136:
    b lbl_0800d30c
lbl_0800d138:
    cmp r0, #6
    beq lbl_0800d13e
    b lbl_0800d23c
lbl_0800d13e:
    movs r7, #0
    ldr r5, lbl_0800d1ac @ =0x030001ac
    ldr r4, lbl_0800d1b0 @ =0x040000d4
    ldr r1, lbl_0800d1b4 @ =0x0300083c
    mov sl, r1
    ldr r0, lbl_0800d1b8 @ =0x082b0cac
    mov sb, r0
lbl_0800d14c:
    lsls r2, r7, #3
    subs r0, r2, r7
    lsls r0, r0, #3
    adds r3, r0, r5
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    beq lbl_0800d20a
    str r3, [r4]
    ldr r0, lbl_0800d1bc @ =0x03000738
    str r0, [r4, #4]
    ldr r0, lbl_0800d1c0 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, [sp]
    adds r0, r1, r7
    ldr r1, [sp, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    movs r1, #0x1f
    ands r0, r1
    add r0, sb
    ldrb r0, [r0]
    mov r1, sl
    strb r0, [r1]
    adds r0, r6, #0
    bl update_sprite_stun_timer
    adds r0, r6, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d1c8
    ldr r0, lbl_0800d1c4 @ =0x0875f1e8
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
    b lbl_0800d1d6
    .align 2, 0
lbl_0800d1ac: .4byte 0x030001ac
lbl_0800d1b0: .4byte 0x040000d4
lbl_0800d1b4: .4byte 0x0300083c
lbl_0800d1b8: .4byte 0x082b0cac
lbl_0800d1bc: .4byte 0x03000738
lbl_0800d1c0: .4byte 0x8000001c
lbl_0800d1c4: .4byte 0x0875f1e8
lbl_0800d1c8:
    ldr r0, lbl_0800d228 @ =0x0875e8c0
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
lbl_0800d1d6:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d1f2
    adds r0, r6, #0
    bl samus_standing_on_sprite
    adds r0, r6, #0
    bl update_sprite_anim
    adds r0, r6, #0
    bl check_sprite_is_on_screen
lbl_0800d1f2:
    ldr r0, lbl_0800d22c @ =0x03000738
    str r0, [r4]
    mov r1, r8
    subs r0, r1, r7
    lsls r0, r0, #3
    ldr r1, lbl_0800d230 @ =0x030001ac
    adds r0, r0, r1
    str r0, [r4, #4]
    ldr r0, lbl_0800d234 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    adds r5, r1, #0
lbl_0800d20a:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x17
    bls lbl_0800d14c
lbl_0800d214:
    bl decrement_chozodia_alarm
    ldr r1, lbl_0800d238 @ =0x03000734
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0800d30c
    subs r0, #1
    strb r0, [r1]
    b lbl_0800d30c
    .align 2, 0
lbl_0800d228: .4byte 0x0875e8c0
lbl_0800d22c: .4byte 0x03000738
lbl_0800d230: .4byte 0x030001ac
lbl_0800d234: .4byte 0x8000001c
lbl_0800d238: .4byte 0x03000734
lbl_0800d23c:
    movs r7, #0
    ldr r5, lbl_0800d2b0 @ =0x030001ac
    ldr r4, lbl_0800d2b4 @ =0x040000d4
    ldr r0, lbl_0800d2b8 @ =0x0300083c
    mov sl, r0
    ldr r1, lbl_0800d2bc @ =0x082b0cac
    mov sb, r1
lbl_0800d24a:
    lsls r2, r7, #3
    subs r0, r2, r7
    lsls r0, r0, #3
    adds r3, r0, r5
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    beq lbl_0800d302
    str r3, [r4]
    ldr r0, lbl_0800d2c0 @ =0x03000738
    str r0, [r4, #4]
    ldr r0, lbl_0800d2c4 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    ldr r1, [sp]
    adds r0, r1, r7
    ldr r1, [sp, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #4]
    adds r0, r0, r1
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    movs r1, #0x1f
    ands r0, r1
    add r0, sb
    ldrb r0, [r0]
    mov r1, sl
    strb r0, [r1]
    adds r0, r6, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800d2da
    adds r0, r6, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d2cc
    ldr r0, lbl_0800d2c8 @ =0x0875f1e8
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
    b lbl_0800d2da
    .align 2, 0
lbl_0800d2b0: .4byte 0x030001ac
lbl_0800d2b4: .4byte 0x040000d4
lbl_0800d2b8: .4byte 0x0300083c
lbl_0800d2bc: .4byte 0x082b0cac
lbl_0800d2c0: .4byte 0x03000738
lbl_0800d2c4: .4byte 0x8000001c
lbl_0800d2c8: .4byte 0x0875f1e8
lbl_0800d2cc:
    ldr r0, lbl_0800d31c @ =0x0875e8c0
    ldrb r1, [r6, #0x1d]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, [r1]
    bl _call_via_r0
lbl_0800d2da:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d2ea
    adds r0, r6, #0
    bl check_sprite_is_on_screen
lbl_0800d2ea:
    ldr r0, lbl_0800d320 @ =0x03000738
    str r0, [r4]
    mov r1, r8
    subs r0, r1, r7
    lsls r0, r0, #3
    ldr r1, lbl_0800d324 @ =0x030001ac
    adds r0, r0, r1
    str r0, [r4, #4]
    ldr r0, lbl_0800d328 @ =0x8000001c
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    adds r5, r1, #0
lbl_0800d302:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0x17
    bls lbl_0800d24a
lbl_0800d30c:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800d31c: .4byte 0x0875e8c0
lbl_0800d320: .4byte 0x03000738
lbl_0800d324: .4byte 0x030001ac
lbl_0800d328: .4byte 0x8000001c

    thumb_func_start update_sprite_anim
update_sprite_anim: @ 0x0800d32c
    push {lr}
    adds r2, r0, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800d368
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
    ldrh r1, [r2, #0x16]
    ldr r3, [r2, #0x18]
    lsls r1, r1, #3
    adds r1, r1, r3
    ldrb r1, [r1, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhs lbl_0800d368
    movs r0, #1
    strb r0, [r2, #0x1c]
    ldrh r0, [r2, #0x16]
    adds r0, #1
    strh r0, [r2, #0x16]
    ldrh r0, [r2, #0x16]
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800d368
    strh r0, [r2, #0x16]
lbl_0800d368:
    pop {r0}
    bx r0

    thumb_func_start sub_0800d36c
sub_0800d36c: @ 0x0800d36c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #8
    ldr r0, lbl_0800d3c4 @ =0x03000c72
    movs r2, #0
    ldrsh r1, [r0, r2]
    movs r0, #2
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    mov ip, r0
    movs r0, #0x17
    mov sb, r0
    movs r1, #0x13
    mov r8, r1
    ldr r0, lbl_0800d3c8 @ =0x030001ac
    movs r7, #0
    ldr r3, lbl_0800d3cc @ =0x030007f3
    adds r4, r0, #0
    adds r4, #0x22
    adds r6, r0, #0
    movs r5, #0x17
lbl_0800d39e:
    ldrh r0, [r6]
    mov r2, sb
    ands r0, r2
    cmp r0, r8
    bne lbl_0800d3d0
    ldrb r2, [r4]
    cmp r2, #8
    bhi lbl_0800d3d0
    mov r0, ip
    cmp r0, #0
    beq lbl_0800d3be
    ldrb r1, [r4, #0x10]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0800d3d0
lbl_0800d3be:
    strb r2, [r3]
    b lbl_0800d3d2
    .align 2, 0
lbl_0800d3c4: .4byte 0x03000c72
lbl_0800d3c8: .4byte 0x030001ac
lbl_0800d3cc: .4byte 0x030007f3
lbl_0800d3d0:
    strb r7, [r3]
lbl_0800d3d2:
    adds r3, #1
    adds r4, #0x38
    adds r6, #0x38
    subs r5, #1
    cmp r5, #0
    bge lbl_0800d39e
    movs r6, #1
    ldr r3, lbl_0800d424 @ =0x030006ec
lbl_0800d3e2:
    movs r5, #0
    ldr r4, lbl_0800d428 @ =0x030001ac
    adds r7, r6, #1
    cmp r4, r3
    bhs lbl_0800d40e
    ldr r2, lbl_0800d42c @ =0x030007f3
lbl_0800d3ee:
    adds r0, r5, r2
    ldrb r0, [r0]
    cmp r0, r6
    bne lbl_0800d406
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp]
    str r3, [sp, #4]
    bl draw_sprite
    ldr r3, [sp, #4]
    ldr r2, [sp]
lbl_0800d406:
    adds r5, #1
    adds r4, #0x38
    cmp r4, r3
    blo lbl_0800d3ee
lbl_0800d40e:
    adds r6, r7, #0
    cmp r6, #8
    ble lbl_0800d3e2
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800d424: .4byte 0x030006ec
lbl_0800d428: .4byte 0x030001ac
lbl_0800d42c: .4byte 0x030007f3

    thumb_func_start call_draw_sprite
call_draw_sprite: @ 0x0800d430
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    movs r7, #0x17
    movs r6, #3
    bl sprite_debris_draw_all
    ldr r0, lbl_0800d45c @ =0x030001ac
    movs r4, #0
    ldr r1, lbl_0800d460 @ =0x030007f3
    adds r3, r0, #0
    adds r3, #0x22
    adds r2, r0, #0
    movs r5, #0x17
lbl_0800d44a:
    ldrh r0, [r2]
    ands r0, r7
    cmp r0, r6
    bne lbl_0800d464
    ldrb r0, [r3]
    cmp r0, #8
    bhi lbl_0800d464
    strb r0, [r1]
    b lbl_0800d466
    .align 2, 0
lbl_0800d45c: .4byte 0x030001ac
lbl_0800d460: .4byte 0x030007f3
lbl_0800d464:
    strb r4, [r1]
lbl_0800d466:
    adds r1, #1
    adds r3, #0x38
    adds r2, #0x38
    subs r5, #1
    cmp r5, #0
    bge lbl_0800d44a
    movs r6, #1
    ldr r3, lbl_0800d4b0 @ =0x030006ec
lbl_0800d476:
    movs r5, #0
    ldr r4, lbl_0800d4b4 @ =0x030001ac
    adds r7, r6, #1
    cmp r4, r3
    bhs lbl_0800d4a2
    ldr r2, lbl_0800d4b8 @ =0x030007f3
lbl_0800d482:
    adds r0, r5, r2
    ldrb r0, [r0]
    cmp r0, r6
    bne lbl_0800d49a
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp]
    str r3, [sp, #4]
    bl draw_sprite
    ldr r3, [sp, #4]
    ldr r2, [sp]
lbl_0800d49a:
    adds r5, #1
    adds r4, #0x38
    cmp r4, r3
    blo lbl_0800d482
lbl_0800d4a2:
    adds r6, r7, #0
    cmp r6, #8
    ble lbl_0800d476
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800d4b0: .4byte 0x030006ec
lbl_0800d4b4: .4byte 0x030001ac
lbl_0800d4b8: .4byte 0x030007f3

    thumb_func_start sub_0800d4bc
sub_0800d4bc: @ 0x0800d4bc
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    movs r7, #0x17
    movs r6, #3
    ldr r0, lbl_0800d4e4 @ =0x030001ac
    movs r4, #0
    ldr r1, lbl_0800d4e8 @ =0x030007f3
    adds r3, r0, #0
    adds r3, #0x22
    adds r2, r0, #0
    movs r5, #0x17
lbl_0800d4d2:
    ldrh r0, [r2]
    ands r0, r7
    cmp r0, r6
    bne lbl_0800d4ec
    ldrb r0, [r3]
    cmp r0, #8
    bls lbl_0800d4ec
    strb r0, [r1]
    b lbl_0800d4ee
    .align 2, 0
lbl_0800d4e4: .4byte 0x030001ac
lbl_0800d4e8: .4byte 0x030007f3
lbl_0800d4ec:
    strb r4, [r1]
lbl_0800d4ee:
    adds r1, #1
    adds r3, #0x38
    adds r2, #0x38
    subs r5, #1
    cmp r5, #0
    bge lbl_0800d4d2
    movs r6, #9
    ldr r3, lbl_0800d538 @ =0x030006ec
lbl_0800d4fe:
    movs r5, #0
    ldr r4, lbl_0800d53c @ =0x030001ac
    adds r7, r6, #1
    cmp r4, r3
    bhs lbl_0800d52a
    ldr r2, lbl_0800d540 @ =0x030007f3
lbl_0800d50a:
    adds r0, r5, r2
    ldrb r0, [r0]
    cmp r0, r6
    bne lbl_0800d522
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp]
    str r3, [sp, #4]
    bl draw_sprite
    ldr r3, [sp, #4]
    ldr r2, [sp]
lbl_0800d522:
    adds r5, #1
    adds r4, #0x38
    cmp r4, r3
    blo lbl_0800d50a
lbl_0800d52a:
    adds r6, r7, #0
    cmp r6, #0x10
    ble lbl_0800d4fe
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800d538: .4byte 0x030006ec
lbl_0800d53c: .4byte 0x030001ac
lbl_0800d540: .4byte 0x030007f3

    thumb_func_start draw_sprite
draw_sprite: @ 0x0800d544
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x4c
    adds r7, r0, #0
    str r1, [sp]
    ldr r2, lbl_0800d754 @ =0x03001382
    ldrb r3, [r2]
    ldrh r0, [r7, #0x16]
    ldr r1, [r7, #0x18]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r0, [r0]
    mov sl, r0
    ldrh r0, [r0]
    str r0, [sp, #8]
    movs r1, #2
    add sl, r1
    adds r0, r0, r3
    cmp r0, #0x7f
    ble lbl_0800d576
    bl lbl_0800dd9e
lbl_0800d576:
    lsls r1, r3, #3
    ldr r0, lbl_0800d758 @ =0x03000e7c
    adds r1, r1, r0
    mov r8, r1
    ldrh r1, [r7, #2]
    lsrs r1, r1, #2
    ldr r0, lbl_0800d75c @ =0x030013ba
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #0x38]
    ldrh r1, [r7, #4]
    lsrs r1, r1, #2
    ldr r0, lbl_0800d760 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #0x34]
    ldrh r2, [r7]
    movs r0, #0x40
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x14]
    movs r0, #0x80
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    movs r0, #0x80
    lsls r0, r0, #7
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x18]
    movs r0, #0x80
    lsls r0, r0, #6
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x24]
    ldrb r1, [r7, #0x1f]
    adds r0, r7, #0
    adds r0, #0x20
    ldrb r0, [r0]
    adds r0, r1, r0
    str r0, [sp, #0x2c]
    lsls r1, r1, #6
    str r1, [sp, #0x30]
    adds r0, r7, #0
    adds r0, #0x21
    ldrb r0, [r0]
    str r0, [sp, #0x28]
    ldr r0, lbl_0800d764 @ =0x0300002b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800d606
    ldr r4, [sp, #0x28]
    cmp r4, #0
    beq lbl_0800d606
    subs r4, #1
    str r4, [sp, #0x28]
lbl_0800d606:
    adds r0, r7, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r4, #0x20
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800d61e
    ldrh r6, [r7, #2]
    str r6, [sp, #0x38]
    ldrh r0, [r7, #4]
    str r0, [sp, #0x34]
lbl_0800d61e:
    movs r0, #8
    ands r0, r2
    cmp r0, #0
    beq lbl_0800d628
    b lbl_0800d93c
lbl_0800d628:
    ldr r1, [sp, #8]
    adds r1, r1, r3
    str r1, [sp, #0x48]
    ldr r2, [sp, #8]
    cmp r2, #0
    bne lbl_0800d636
    b lbl_0800d7e8
lbl_0800d636:
    ldr r1, lbl_0800d758 @ =0x03000e7c
    movs r4, #1
    mov sb, r4
    lsls r0, r3, #3
    adds r5, r0, r1
    ldr r6, [sp, #0x28]
    movs r0, #3
    ands r6, r0
    lsls r1, r6, #2
    str r1, [sp, #0x44]
    str r2, [sp, #4]
lbl_0800d64c:
    mov r2, sl
    ldrh r6, [r2]
    movs r3, #2
    add sl, r3
    mov r4, r8
    strh r6, [r4]
    add r8, r3
    mov r0, sl
    ldrh r3, [r0]
    movs r1, #2
    add sl, r1
    mov r2, r8
    strh r3, [r2]
    add r8, r1
    mov r4, sl
    ldrh r0, [r4]
    mov r1, r8
    strh r0, [r1]
    movs r2, #2
    add sl, r2
    add r8, r2
    ldr r4, [sp, #0x38]
    adds r0, r6, r4
    strb r0, [r5]
    ldr r0, [sp, #0x34]
    adds r1, r3, r0
    ldr r2, lbl_0800d768 @ =0x000001ff
    ands r1, r2
    ldrh r2, [r5, #2]
    ldr r0, lbl_0800d76c @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r5, #2]
    ldrb r1, [r5, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    ldr r4, [sp, #0x44]
    orrs r0, r4
    lsrs r2, r0, #4
    ldr r1, [sp, #0x2c]
    adds r2, r2, r1
    lsls r2, r2, #4
    movs r1, #0xf
    ands r0, r1
    orrs r0, r2
    strb r0, [r5, #5]
    ldrh r2, [r5, #4]
    lsls r1, r2, #0x16
    lsrs r1, r1, #0x16
    ldr r4, [sp, #0x30]
    adds r1, r1, r4
    ldr r4, lbl_0800d770 @ =0x000003ff
    adds r0, r4, #0
    ands r1, r0
    ldr r0, lbl_0800d774 @ =0xfffffc00
    ands r0, r2
    orrs r0, r1
    strh r0, [r5, #4]
    ldr r0, [sp, #0x14]
    cmp r0, #0
    beq lbl_0800d706
    ldrb r2, [r5, #3]
    lsls r0, r2, #0x1b
    lsrs r0, r0, #0x1f
    mov r1, sb
    eors r0, r1
    ands r0, r1
    lsls r0, r0, #4
    movs r1, #0x11
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    strb r1, [r5, #3]
    ldrb r0, [r5, #1]
    lsrs r4, r0, #6
    lsrs r2, r1, #6
    lsls r0, r4, #2
    adds r0, r2, r0
    ldr r2, lbl_0800d778 @ =0x082b0c94
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r1, r0, #3
    adds r1, r3, r1
    ldr r3, [sp, #0x34]
    subs r1, r3, r1
    ldr r4, lbl_0800d768 @ =0x000001ff
    ands r1, r4
    ldrh r2, [r5, #2]
    ldr r0, lbl_0800d76c @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r5, #2]
lbl_0800d706:
    ldr r0, [sp, #0x24]
    cmp r0, #0
    beq lbl_0800d73e
    ldrb r2, [r5, #3]
    lsls r0, r2, #0x1a
    lsrs r0, r0, #0x1f
    mov r1, sb
    eors r0, r1
    ands r0, r1
    lsls r0, r0, #5
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    strb r1, [r5, #3]
    ldrb r0, [r5, #1]
    lsrs r4, r0, #6
    lsrs r2, r1, #6
    lsls r0, r4, #2
    adds r0, r2, r0
    ldr r2, lbl_0800d77c @ =0x082b0ca0
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r6, r0
    ldr r3, [sp, #0x38]
    subs r0, r3, r0
    strb r0, [r5]
lbl_0800d73e:
    mov r4, ip
    cmp r4, #0
    beq lbl_0800d7c2
    ldr r6, [sp, #0x18]
    cmp r6, #0
    beq lbl_0800d780
    ldrb r0, [r5, #1]
    movs r1, #3
    orrs r0, r1
    b lbl_0800d78c
    .align 2, 0
lbl_0800d754: .4byte 0x03001382
lbl_0800d758: .4byte 0x03000e7c
lbl_0800d75c: .4byte 0x030013ba
lbl_0800d760: .4byte 0x030013b8
lbl_0800d764: .4byte 0x0300002b
lbl_0800d768: .4byte 0x000001ff
lbl_0800d76c: .4byte 0xfffffe00
lbl_0800d770: .4byte 0x000003ff
lbl_0800d774: .4byte 0xfffffc00
lbl_0800d778: .4byte 0x082b0c94
lbl_0800d77c: .4byte 0x082b0ca0
lbl_0800d780:
    ldrb r1, [r5, #1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    mov r2, sb
    orrs r0, r2
lbl_0800d78c:
    strb r0, [r5, #1]
    ldr r3, [sp]
    asrs r0, r3, #4
    mov r4, sb
    ands r0, r4
    lsls r0, r0, #5
    ldrb r2, [r5, #3]
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    asrs r0, r3, #3
    ands r0, r4
    lsls r0, r0, #4
    movs r6, #0x11
    rsbs r6, r6, #0
    ands r1, r6
    orrs r1, r0
    movs r0, #7
    adds r2, r3, #0
    ands r2, r0
    lsls r2, r2, #1
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r1, r0
    orrs r1, r2
    strb r1, [r5, #3]
lbl_0800d7c2:
    ldr r0, [sp, #0x1c]
    cmp r0, #0
    beq lbl_0800d7d6
    ldrb r0, [r5, #1]
    movs r1, #0xd
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #4
    orrs r1, r0
    strb r1, [r5, #1]
lbl_0800d7d6:
    movs r1, #2
    add r8, r1
    adds r5, #8
    ldr r2, [sp, #4]
    subs r2, #1
    str r2, [sp, #4]
    cmp r2, #0
    beq lbl_0800d7e8
    b lbl_0800d64c
lbl_0800d7e8:
    add r3, sp, #0x48
    ldrb r4, [r3]
    ldr r3, lbl_0800d874 @ =0x03001382
    strb r4, [r3]
    mov r4, ip
    cmp r4, #0
    bne lbl_0800d7f8
    b lbl_0800dd9e
lbl_0800d7f8:
    adds r0, r7, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    str r0, [sp, #0x3c]
    ldrh r6, [r7, #0x12]
    str r6, [sp, #0x40]
    ldr r0, [sp, #0x14]
    cmp r0, #0
    beq lbl_0800d880
    ldr r5, lbl_0800d878 @ =0x0808c71c
    ldr r1, [sp, #0x3c]
    adds r1, #0x40
    mov sb, r1
    lsls r0, r1, #1
    adds r0, r0, r5
    movs r2, #0
    ldrsh r6, [r0, r2]
    ldr r3, [sp, #0x40]
    rsbs r4, r3, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r6, #0
    bl fix_mul
    ldr r6, lbl_0800d87c @ =0x03000e7c
    mov r8, r6
    ldr r2, [sp]
    lsls r1, r2, #5
    add r1, r8
    strh r0, [r1, #6]
    ldr r3, [sp, #0x3c]
    lsls r6, r3, #1
    adds r5, r6, r5
    movs r0, #0
    ldrsh r5, [r5, r0]
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r5, #0
    bl fix_mul
    ldr r1, [sp]
    lsls r2, r1, #2
    adds r1, r2, #1
    lsls r1, r1, #3
    add r1, r8
    strh r0, [r1, #6]
    mov sl, sb
    adds r5, r6, #0
    adds r7, r2, #0
    ldr r3, [sp, #0x40]
    lsls r2, r3, #0x10
    b lbl_0800d8e2
    .align 2, 0
lbl_0800d874: .4byte 0x03001382
lbl_0800d878: .4byte 0x0808c71c
lbl_0800d87c: .4byte 0x03000e7c
lbl_0800d880:
    ldr r4, lbl_0800d934 @ =0x0808c71c
    ldr r6, [sp, #0x3c]
    adds r6, #0x40
    mov sl, r6
    lsls r0, r6, #1
    adds r0, r0, r4
    movs r1, #0
    ldrsh r5, [r0, r1]
    ldr r2, [sp, #0x40]
    lsls r2, r2, #0x10
    mov sb, r2
    asrs r6, r2, #0x10
    adds r0, r6, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r5, #0
    bl fix_mul
    ldr r3, lbl_0800d938 @ =0x03000e7c
    mov r8, r3
    ldr r2, [sp]
    lsls r1, r2, #5
    add r1, r8
    strh r0, [r1, #6]
    ldr r3, [sp, #0x3c]
    lsls r5, r3, #1
    adds r4, r5, r4
    movs r0, #0
    ldrsh r4, [r4, r0]
    adds r0, r6, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl fix_mul
    ldr r1, [sp]
    lsls r2, r1, #2
    adds r1, r2, #1
    lsls r1, r1, #3
    add r1, r8
    strh r0, [r1, #6]
    adds r7, r2, #0
    mov r2, sb
lbl_0800d8e2:
    ldr r3, lbl_0800d934 @ =0x0808c71c
    mov r8, r3
    adds r0, r5, r3
    ldrh r4, [r0]
    rsbs r4, r4, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    asrs r5, r2, #0x10
    adds r0, r5, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl fix_mul
    ldr r6, lbl_0800d938 @ =0x03000e7c
    adds r1, r7, #2
    lsls r1, r1, #3
    adds r1, r1, r6
    strh r0, [r1, #6]
    mov r4, sl
    lsls r0, r4, #1
    add r0, r8
    movs r1, #0
    ldrsh r4, [r0, r1]
    adds r0, r5, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl fix_mul
    adds r1, r7, #3
    lsls r1, r1, #3
    adds r1, r1, r6
    strh r0, [r1, #6]
    b lbl_0800dd9e
    .align 2, 0
lbl_0800d934: .4byte 0x0808c71c
lbl_0800d938: .4byte 0x03000e7c
lbl_0800d93c:
    adds r0, r7, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    str r0, [sp, #0x3c]
    ldrh r6, [r7, #0x12]
    str r6, [sp, #0x40]
    adds r0, r4, #0
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x20]
    ldr r0, [sp, #0x38]
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x38]
    ldr r0, [sp, #0x34]
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x34]
    movs r0, #0
    str r0, [sp, #4]
    ldr r1, [sp, #8]
    adds r1, r1, r3
    str r1, [sp, #0x48]
    ldr r2, [sp, #8]
    cmp r0, r2
    blt lbl_0800d978
    b lbl_0800dbf4
lbl_0800d978:
    ldr r1, lbl_0800dac0 @ =0x03000e7c
    lsls r0, r3, #3
    adds r7, r0, r1
lbl_0800d97e:
    mov r3, sl
    ldrh r6, [r3]
    movs r4, #2
    add sl, r4
    mov r0, r8
    strh r6, [r0]
    add r8, r4
    mov r1, sl
    ldrh r3, [r1]
    add sl, r4
    mov r2, r8
    strh r3, [r2]
    add r8, r4
    mov r4, sl
    ldrh r0, [r4]
    mov r1, r8
    strh r0, [r1]
    movs r2, #2
    add sl, r2
    add r8, r2
    movs r0, #3
    ldr r1, [sp, #0x28]
    ands r1, r0
    lsls r1, r1, #2
    ldrb r2, [r7, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    lsrs r2, r0, #4
    ldr r4, [sp, #0x2c]
    adds r2, r2, r4
    lsls r2, r2, #4
    movs r1, #0xf
    ands r0, r1
    orrs r0, r2
    strb r0, [r7, #5]
    ldrh r2, [r7, #4]
    lsls r1, r2, #0x16
    lsrs r1, r1, #0x16
    ldr r0, [sp, #0x30]
    adds r1, r1, r0
    ldr r4, lbl_0800dac4 @ =0x000003ff
    adds r0, r4, #0
    ands r1, r0
    ldr r0, lbl_0800dac8 @ =0xfffffc00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #4]
    ldrb r0, [r7, #1]
    lsrs r4, r0, #6
    ldrb r0, [r7, #3]
    lsrs r2, r0, #6
    lsls r1, r4, #2
    adds r1, r2, r1
    ldr r2, lbl_0800dacc @ =0x082b0ca0
    adds r0, r1, r2
    ldrb r0, [r0]
    lsls r0, r0, #2
    mov ip, r0
    mov r4, ip
    str r4, [sp, #0xc]
    ldr r0, lbl_0800dad0 @ =0x082b0c94
    adds r1, r1, r0
    ldrb r1, [r1]
    lsls r1, r1, #2
    mov sb, r1
    str r1, [sp, #0x10]
    ldr r4, [sp, #0x38]
    adds r2, r6, r4
    movs r0, #0xff
    ands r2, r0
    ldr r0, [sp, #0x34]
    adds r6, r3, r0
    ldr r1, lbl_0800dad4 @ =0x000001ff
    adds r0, r1, #0
    ands r6, r0
    subs r0, r2, r4
    add r0, ip
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
    ldr r4, [sp, #0x34]
    subs r0, r6, r4
    add r0, sb
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    ldr r4, [sp, #0x40]
    adds r0, r1, #0
    muls r0, r4, r0
    cmp r0, #0
    bge lbl_0800da36
    adds r0, #0xff
lbl_0800da36:
    asrs r0, r0, #8
    subs r0, r0, r1
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    ldr r4, [sp, #0x40]
    adds r0, r3, #0
    muls r0, r4, r0
    cmp r0, #0
    bge lbl_0800da4a
    adds r0, #0xff
lbl_0800da4a:
    asrs r0, r0, #8
    subs r0, r0, r3
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
    adds r0, r6, r1
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    adds r0, r2, r3
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    ldr r0, [sp, #0x34]
    subs r3, r6, r0
    add r3, sb
    lsls r3, r3, #0x10
    asrs r3, r3, #0x10
    ldr r1, [sp, #0x38]
    subs r2, r2, r1
    add r2, ip
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    ldr r0, [sp, #0x3c]
    adds r0, #0x40
    lsls r0, r0, #1
    ldr r4, lbl_0800dad8 @ =0x0808c71c
    adds r0, r0, r4
    movs r6, #0
    ldrsh r5, [r0, r6]
    adds r1, r3, #0
    muls r1, r5, r1
    ldr r4, [sp, #0x3c]
    lsls r0, r4, #1
    ldr r6, lbl_0800dad8 @ =0x0808c71c
    adds r0, r0, r6
    movs r6, #0
    ldrsh r4, [r0, r6]
    adds r0, r2, #0
    muls r0, r4, r0
    subs r1, r1, r0
    lsls r1, r1, #8
    asrs r6, r1, #0x10
    adds r0, r3, #0
    muls r0, r4, r0
    adds r1, r2, #0
    muls r1, r5, r1
    adds r0, r0, r1
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    ldr r0, [sp, #0x18]
    cmp r0, #0
    beq lbl_0800dadc
    mov r1, sb
    lsls r0, r1, #1
    subs r0, r6, r0
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    mov r3, ip
    lsls r0, r3, #1
    subs r0, r2, r0
    b lbl_0800dae8
    .align 2, 0
lbl_0800dac0: .4byte 0x03000e7c
lbl_0800dac4: .4byte 0x000003ff
lbl_0800dac8: .4byte 0xfffffc00
lbl_0800dacc: .4byte 0x082b0ca0
lbl_0800dad0: .4byte 0x082b0c94
lbl_0800dad4: .4byte 0x000001ff
lbl_0800dad8: .4byte 0x0808c71c
lbl_0800dadc:
    ldr r4, [sp, #0x10]
    subs r0, r6, r4
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    ldr r1, [sp, #0xc]
    subs r0, r2, r1
lbl_0800dae8:
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    ldr r3, [sp, #0x38]
    adds r0, r2, r3
    subs r0, #0x40
    strb r0, [r7]
    ldr r4, [sp, #0x34]
    adds r1, r6, r4
    subs r1, #0x40
    ldr r0, lbl_0800db18 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r7, #2]
    ldr r0, lbl_0800db1c @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #2]
    ldr r6, [sp, #0x18]
    cmp r6, #0
    beq lbl_0800db20
    ldrb r0, [r7, #1]
    movs r1, #3
    orrs r0, r1
    strb r0, [r7, #1]
    b lbl_0800db2e
    .align 2, 0
lbl_0800db18: .4byte 0x000001ff
lbl_0800db1c: .4byte 0xfffffe00
lbl_0800db20:
    ldrb r0, [r7, #1]
    movs r1, #4
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    strb r1, [r7, #1]
lbl_0800db2e:
    ldr r0, [sp, #0x20]
    cmp r0, #0
    beq lbl_0800db82
    ldrb r1, [r7, #3]
    lsls r0, r1, #0x1b
    cmp r0, #0
    bge lbl_0800db70
    ldrh r2, [r7, #2]
    lsls r1, r2, #0x17
    lsrs r1, r1, #0x17
    subs r1, #1
    ldr r3, lbl_0800db68 @ =0x000001ff
    adds r0, r3, #0
    ands r1, r0
    ldr r0, lbl_0800db6c @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #2]
    ldrb r0, [r7, #3]
    movs r4, #0x20
    orrs r0, r4
    movs r6, #0x10
    orrs r0, r6
    movs r1, #0xf
    rsbs r1, r1, #0
    ands r0, r1
    movs r1, #0xa
    b lbl_0800dbc8
    .align 2, 0
lbl_0800db68: .4byte 0x000001ff
lbl_0800db6c: .4byte 0xfffffe00
lbl_0800db70:
    movs r0, #0x20
    orrs r0, r1
    movs r2, #0x10
    orrs r0, r2
    movs r3, #0xf
    rsbs r3, r3, #0
    ands r0, r3
    movs r1, #8
    b lbl_0800dbc8
lbl_0800db82:
    ldrb r1, [r7, #3]
    lsls r0, r1, #0x1b
    cmp r0, #0
    bge lbl_0800dbb8
    ldrh r2, [r7, #2]
    lsls r1, r2, #0x17
    lsrs r1, r1, #0x17
    subs r1, #1
    ldr r4, lbl_0800dbb0 @ =0x000001ff
    adds r0, r4, #0
    ands r1, r0
    ldr r0, lbl_0800dbb4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #2]
    ldrb r0, [r7, #3]
    movs r6, #0x20
    orrs r0, r6
    movs r1, #0x10
    orrs r0, r1
    movs r1, #0xe
    b lbl_0800dbc8
    .align 2, 0
lbl_0800dbb0: .4byte 0x000001ff
lbl_0800dbb4: .4byte 0xfffffe00
lbl_0800dbb8:
    movs r0, #0x20
    orrs r0, r1
    movs r2, #0x10
    orrs r0, r2
    movs r3, #0xf
    rsbs r3, r3, #0
    ands r0, r3
    movs r1, #0xc
lbl_0800dbc8:
    orrs r0, r1
    strb r0, [r7, #3]
    ldr r4, [sp, #0x1c]
    cmp r4, #0
    beq lbl_0800dbe0
    ldrb r0, [r7, #1]
    movs r1, #0xd
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #4
    orrs r1, r0
    strb r1, [r7, #1]
lbl_0800dbe0:
    movs r6, #2
    add r8, r6
    adds r7, #8
    ldr r0, [sp, #4]
    adds r0, #1
    str r0, [sp, #4]
    ldr r1, [sp, #8]
    cmp r0, r1
    bge lbl_0800dbf4
    b lbl_0800d97e
lbl_0800dbf4:
    add r2, sp, #0x48
    ldrb r3, [r2]
    ldr r2, lbl_0800dce4 @ =0x03001382
    strb r3, [r2]
    ldr r3, [sp, #0x3c]
    lsls r0, r3, #1
    ldr r4, lbl_0800dce8 @ =0x0808c71c
    adds r6, r0, r4
    ldrh r4, [r6]
    rsbs r4, r4, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r1, [sp, #0x40]
    lsls r0, r1, #0x10
    asrs r7, r0, #0x10
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl fix_mul
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    ldr r0, [sp, #0x3c]
    adds r0, #0x40
    lsls r0, r0, #1
    ldr r2, lbl_0800dce8 @ =0x0808c71c
    adds r0, r0, r2
    movs r4, #0
    ldrsh r3, [r0, r4]
    mov r8, r3
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, r8
    bl fix_mul
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldr r0, [sp, #0x20]
    cmp r0, #0
    beq lbl_0800dd10
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, r8
    bl fix_mul
    ldr r5, lbl_0800dcec @ =0x03000e7c
    ldr r2, lbl_0800dcf0 @ =0x00000386
    adds r1, r5, r2
    strh r0, [r1]
    movs r3, #0
    ldrsh r6, [r6, r3]
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r6, #0
    bl fix_mul
    ldr r4, lbl_0800dcf4 @ =0x0000038e
    adds r1, r5, r4
    strh r0, [r1]
    ldr r1, lbl_0800dcf8 @ =0x00000396
    adds r0, r5, r1
    mov r2, sl
    strh r2, [r0]
    ldr r3, lbl_0800dcfc @ =0x0000039e
    adds r0, r5, r3
    mov r4, sb
    strh r4, [r0]
    ldr r0, [sp, #0x40]
    rsbs r4, r0, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, r8
    bl fix_mul
    ldr r2, lbl_0800dd00 @ =0x000003a6
    adds r1, r5, r2
    strh r0, [r1]
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r6, #0
    bl fix_mul
    ldr r3, lbl_0800dd04 @ =0x000003ae
    adds r1, r5, r3
    strh r0, [r1]
    ldr r4, lbl_0800dd08 @ =0x000003b6
    adds r0, r5, r4
    mov r6, sl
    strh r6, [r0]
    ldr r0, lbl_0800dd0c @ =0x000003be
    b lbl_0800dd98
    .align 2, 0
lbl_0800dce4: .4byte 0x03001382
lbl_0800dce8: .4byte 0x0808c71c
lbl_0800dcec: .4byte 0x03000e7c
lbl_0800dcf0: .4byte 0x00000386
lbl_0800dcf4: .4byte 0x0000038e
lbl_0800dcf8: .4byte 0x00000396
lbl_0800dcfc: .4byte 0x0000039e
lbl_0800dd00: .4byte 0x000003a6
lbl_0800dd04: .4byte 0x000003ae
lbl_0800dd08: .4byte 0x000003b6
lbl_0800dd0c: .4byte 0x000003be
lbl_0800dd10:
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, r8
    bl fix_mul
    ldr r5, lbl_0800ddb0 @ =0x03000e7c
    ldr r2, lbl_0800ddb4 @ =0x000003c6
    adds r1, r5, r2
    strh r0, [r1]
    movs r3, #0
    ldrsh r6, [r6, r3]
    adds r0, r7, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r6, #0
    bl fix_mul
    ldr r4, lbl_0800ddb8 @ =0x000003ce
    adds r1, r5, r4
    strh r0, [r1]
    ldr r1, lbl_0800ddbc @ =0x000003d6
    adds r0, r5, r1
    mov r2, sl
    strh r2, [r0]
    ldr r3, lbl_0800ddc0 @ =0x000003de
    adds r0, r5, r3
    mov r4, sb
    strh r4, [r0]
    ldr r0, [sp, #0x40]
    rsbs r4, r0, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, r8
    bl fix_mul
    ldr r2, lbl_0800ddc4 @ =0x000003e6
    adds r1, r5, r2
    strh r0, [r1]
    adds r0, r4, #0
    bl fix_inverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r6, #0
    bl fix_mul
    ldr r3, lbl_0800ddc8 @ =0x000003ee
    adds r1, r5, r3
    strh r0, [r1]
    ldr r4, lbl_0800ddcc @ =0x000003f6
    adds r0, r5, r4
    mov r6, sl
    strh r6, [r0]
    ldr r0, lbl_0800ddd0 @ =0x000003fe
lbl_0800dd98:
    adds r5, r5, r0
    mov r1, sb
    strh r1, [r5]
lbl_0800dd9e:
    add sp, #0x4c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800ddb0: .4byte 0x03000e7c
lbl_0800ddb4: .4byte 0x000003c6
lbl_0800ddb8: .4byte 0x000003ce
lbl_0800ddbc: .4byte 0x000003d6
lbl_0800ddc0: .4byte 0x000003de
lbl_0800ddc4: .4byte 0x000003e6
lbl_0800ddc8: .4byte 0x000003ee
lbl_0800ddcc: .4byte 0x000003f6
lbl_0800ddd0: .4byte 0x000003fe

    thumb_func_start check_sprite_is_on_screen
check_sprite_is_on_screen: @ 0x0800ddd4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov ip, r0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ddf0
    b lbl_0800df0c
lbl_0800ddf0:
    ldr r0, lbl_0800de88 @ =0x030013ba
    ldrh r0, [r0]
    mov r8, r0
    ldr r0, lbl_0800de8c @ =0x030013b8
    ldrh r0, [r0]
    mov sl, r0
    mov r0, ip
    ldrh r0, [r0, #2]
    mov sb, r0
    mov r1, ip
    ldrh r1, [r1, #4]
    str r1, [sp]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r2, r3, #0
    mov r4, r8
    adds r0, r4, r2
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    mov r7, sb
    adds r0, r7, r2
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    mov r0, ip
    adds r0, #0x28
    ldrb r0, [r0]
    lsls r0, r0, #2
    subs r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    mov r0, ip
    adds r0, #0x27
    ldrb r0, [r0]
    lsls r0, r0, #2
    movs r1, #0xa0
    lsls r1, r1, #2
    adds r0, r0, r1
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r3, sl
    adds r0, r3, r2
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldr r4, [sp]
    adds r2, r4, r2
    lsls r2, r2, #0x10
    mov r0, ip
    adds r0, #0x29
    ldrb r0, [r0]
    lsls r0, r0, #2
    subs r1, r3, r0
    lsls r1, r1, #0x10
    lsrs r4, r2, #0x10
    movs r7, #0xf0
    lsls r7, r7, #2
    adds r0, r0, r7
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, r2
    bhs lbl_0800de90
    cmp r4, r0
    bhs lbl_0800de90
    ldr r0, [sp, #4]
    cmp r0, r5
    bhs lbl_0800de90
    cmp r5, r6
    bhs lbl_0800de90
    mov r2, ip
    ldrh r1, [r2]
    movs r0, #2
    orrs r0, r1
    strh r0, [r2]
    b lbl_0800df0c
    .align 2, 0
lbl_0800de88: .4byte 0x030013ba
lbl_0800de8c: .4byte 0x030013b8
lbl_0800de90:
    mov r3, ip
    ldrh r1, [r3]
    ldr r0, lbl_0800df1c @ =0x0000fffd
    ands r0, r1
    strh r0, [r3]
    mov r0, ip
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800df0c
    movs r4, #0xa0
    lsls r4, r4, #2
    adds r1, r4, #0
    mov r7, r8
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    mov r2, sb
    adds r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r4, lbl_0800df20 @ =0xfffffdc0
    adds r2, r4, #0
    adds r0, r3, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    movs r7, #0x98
    lsls r7, r7, #3
    adds r0, r3, r7
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r3, sl
    adds r0, r3, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldr r4, [sp]
    adds r1, r4, r1
    lsls r1, r1, #0x10
    adds r2, r3, r2
    lsls r2, r2, #0x10
    mov r8, r2
    lsrs r4, r1, #0x10
    movs r7, #0xc0
    lsls r7, r7, #3
    adds r0, r3, r7
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r8, r1
    bhs lbl_0800df06
    cmp r4, r0
    bhs lbl_0800df06
    ldr r0, [sp, #4]
    cmp r0, r5
    bhs lbl_0800df06
    cmp r5, r6
    blo lbl_0800df0c
lbl_0800df06:
    movs r0, #0
    mov r1, ip
    strh r0, [r1]
lbl_0800df0c:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800df1c: .4byte 0x0000fffd
lbl_0800df20: .4byte 0xfffffdc0

    thumb_func_start load_sprite_data
load_sprite_data: @ 0x0800df24
    push {lr}
    ldr r0, lbl_0800df70 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800df6a
    ldr r0, lbl_0800df74 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800df4c
    ldr r0, lbl_0800df78 @ =0x03000c1d
    movs r1, #0
    ldrsb r1, [r0, r1]
    cmp r1, #0
    bne lbl_0800df4c
    ldr r0, lbl_0800df7c @ =0x030001a8
    strh r1, [r0]
lbl_0800df4c:
    bl clear_sprite_data
    bl load_spriteset
    bl sub_08053a18
    bl init_location_text
    bl load_room_sprites
    bl spawn_space_pirates_waiting
    ldr r1, lbl_0800df80 @ =0x03000734
    movs r0, #0
    strb r0, [r1]
lbl_0800df6a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800df70: .4byte 0x03000bf0
lbl_0800df74: .4byte 0x03000c75
lbl_0800df78: .4byte 0x03000c1d
lbl_0800df7c: .4byte 0x030001a8
lbl_0800df80: .4byte 0x03000734

    thumb_func_start load_spriteset
load_spriteset: @ 0x0800df84
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    movs r7, #0
    ldr r5, lbl_0800e05c @ =0x03000078
    ldr r6, lbl_0800e060 @ =0x0875f31c
    ldr r4, lbl_0800e064 @ =0x030006ec
    movs r3, #0
    movs r2, #0x10
    ldr r1, lbl_0800e068 @ =0x030006fb
lbl_0800df9c:
    adds r0, r7, r4
    strb r2, [r0]
    adds r0, r7, r1
    strb r3, [r0]
    adds r7, #1
    cmp r7, #0xe
    ble lbl_0800df9c
    movs r0, #0xff
    mov sb, r0
    ldrb r1, [r5]
    cmp r1, #0x70
    ble lbl_0800dfc0
    ldr r0, lbl_0800e06c @ =0x03000054
    ldrb r0, [r0]
    movs r1, #0
    cmp r0, #7
    bls lbl_0800dfc0
    movs r1, #0x71
lbl_0800dfc0:
    movs r7, #0
    lsls r0, r1, #2
    adds r1, r0, r6
    ldr r1, [r1]
    ldrb r5, [r1]
    ldrb r6, [r1, #1]
    movs r1, #1
    mov r8, r1
    mov sl, r0
    cmp r5, #0
    beq lbl_0800e04e
lbl_0800dfd6:
    ldr r0, lbl_0800e064 @ =0x030006ec
    adds r0, r7, r0
    strb r5, [r0]
    ldr r1, lbl_0800e068 @ =0x030006fb
    adds r1, r7, r1
    movs r2, #7
    adds r0, r6, #0
    ands r0, r2
    strb r0, [r1]
    cmp r6, sb
    beq lbl_0800e030
    mov sb, r6
    cmp r6, #8
    beq lbl_0800e030
    subs r5, #0x10
    ldr r4, lbl_0800e070 @ =0x0875ebf8
    lsls r5, r5, #2
    adds r4, r5, r4
    ldr r0, [r4]
    lsls r1, r6, #0xb
    ldr r2, lbl_0800e074 @ =0x06014000
    adds r1, r1, r2
    bl LZ77_uncomp_vram
    ldr r0, [r4]
    ldrb r2, [r0, #1]
    ldrb r1, [r0, #2]
    lsls r1, r1, #8
    ldr r3, lbl_0800e078 @ =0x040000d4
    ldr r0, lbl_0800e07c @ =0x0875eef0
    adds r5, r5, r0
    ldr r0, [r5]
    str r0, [r3]
    lsls r0, r6, #5
    ldr r4, lbl_0800e080 @ =0x05000300
    adds r0, r0, r4
    str r0, [r3, #4]
    orrs r2, r1
    asrs r0, r2, #0xb
    lsls r0, r0, #4
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r0, r1
    str r0, [r3, #8]
    ldr r0, [r3, #8]
lbl_0800e030:
    adds r7, #1
    cmp r7, #0xe
    bgt lbl_0800e04e
    ldr r0, lbl_0800e060 @ =0x0875f31c
    add r0, sl
    ldr r1, [r0]
    mov r2, r8
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrb r5, [r0]
    ldrb r6, [r0, #1]
    movs r4, #1
    add r8, r4
    cmp r5, #0
    bne lbl_0800dfd6
lbl_0800e04e:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e05c: .4byte 0x03000078
lbl_0800e060: .4byte 0x0875f31c
lbl_0800e064: .4byte 0x030006ec
lbl_0800e068: .4byte 0x030006fb
lbl_0800e06c: .4byte 0x03000054
lbl_0800e070: .4byte 0x0875ebf8
lbl_0800e074: .4byte 0x06014000
lbl_0800e078: .4byte 0x040000d4
lbl_0800e07c: .4byte 0x0875eef0
lbl_0800e080: .4byte 0x05000300

    thumb_func_start load_sprite_graphics
load_sprite_graphics: @ 0x0800e084
    push {lr}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x18
    movs r2, #0xf0
    lsls r2, r2, #0x18
    adds r0, r0, r2
    ldr r2, lbl_0800e0a8 @ =0x0875ebf8
    lsrs r0, r0, #0x16
    adds r0, r0, r2
    ldr r0, [r0]
    lsrs r1, r1, #0xd
    ldr r2, lbl_0800e0ac @ =0x06014000
    adds r1, r1, r2
    bl LZ77_uncomp_vram
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e0a8: .4byte 0x0875ebf8
lbl_0800e0ac: .4byte 0x06014000

    thumb_func_start load_sprite_palette
load_sprite_palette: @ 0x0800e0b0
    push {r4, lr}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x18
    lsls r2, r2, #0x18
    movs r3, #0xf0
    lsls r3, r3, #0x18
    adds r0, r0, r3
    ldr r4, lbl_0800e0e4 @ =0x040000d4
    ldr r3, lbl_0800e0e8 @ =0x0875eef0
    lsrs r0, r0, #0x16
    adds r0, r0, r3
    ldr r0, [r0]
    str r0, [r4]
    lsrs r1, r1, #0x13
    ldr r0, lbl_0800e0ec @ =0x05000300
    adds r1, r1, r0
    str r1, [r4, #4]
    lsrs r2, r2, #0x14
    movs r0, #0x80
    lsls r0, r0, #0x18
    orrs r2, r0
    str r2, [r4, #8]
    ldr r0, [r4, #8]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e0e4: .4byte 0x040000d4
lbl_0800e0e8: .4byte 0x0875eef0
lbl_0800e0ec: .4byte 0x05000300

    thumb_func_start clear_sprite_data
clear_sprite_data: @ 0x0800e0f0
    push {r4, r5, r6, lr}
    ldr r0, lbl_0800e12c @ =0x030001ac
    movs r6, #0
    movs r5, #0
    movs r4, #0xff
    adds r1, r0, #0
    adds r1, #0x1e
    adds r3, r0, #0
    movs r2, #0x17
lbl_0800e102:
    strh r5, [r3]
    strb r6, [r1, #0x13]
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
    adds r1, #0x38
    adds r3, #0x38
    subs r2, #1
    cmp r2, #0
    bge lbl_0800e102
    ldr r1, lbl_0800e130 @ =0x03000770
    movs r2, #0
    adds r0, r1, #0
    adds r0, #0x70
lbl_0800e11e:
    strb r2, [r0, #0xb]
    subs r0, #0x10
    cmp r0, r1
    bge lbl_0800e11e
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e12c: .4byte 0x030001ac
lbl_0800e130: .4byte 0x03000770

    thumb_func_start load_room_sprites
load_room_sprites: @ 0x0800e134
    push {r4, r5, lr}
    movs r4, #0
    ldr r1, lbl_0800e178 @ =0x030000bc
    ldr r0, [r1, #8]
    ldrb r3, [r0]
    cmp r3, #0xff
    beq lbl_0800e170
    adds r5, r1, #0
lbl_0800e144:
    ldr r1, [r5, #8]
    lsls r0, r4, #1
    adds r0, r0, r4
    adds r0, r0, r1
    ldrb r2, [r0, #1]
    ldrb r0, [r0, #2]
    adds r1, r3, #0
    adds r3, r4, #0
    bl init_primary_sprite
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0x17
    bhi lbl_0800e170
    ldr r1, [r5, #8]
    lsls r0, r4, #1
    adds r0, r0, r4
    adds r0, r0, r1
    ldrb r3, [r0]
    cmp r3, #0xff
    bne lbl_0800e144
lbl_0800e170:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e178: .4byte 0x030000bc

    thumb_func_start init_primary_sprite
init_primary_sprite: @ 0x0800e17c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r0, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov sl, r3
    movs r7, #0
    ldr r2, lbl_0800e1f4 @ =0x030001ac
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r1, r2, r3
    cmp r2, r1
    bhs lbl_0800e248
    movs r6, #1
    movs r3, #0
    lsls r0, r0, #6
    adds r0, #0x40
    mov sb, r0
    mov r8, r1
    movs r0, #0x1d
    adds r0, r0, r2
    mov ip, r0
    lsls r0, r5, #6
    adds r5, r0, #0
    adds r5, #0x20
lbl_0800e1be:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0800e238
    movs r1, #0
    strh r6, [r2]
    movs r0, #0x7f
    ands r4, r0
    cmp r4, #0x10
    bls lbl_0800e200
    subs r1, r4, #1
    lsls r1, r1, #0x18
    movs r0, #0xf0
    lsls r0, r0, #0x14
    ands r0, r1
    lsrs r4, r0, #0x18
    ldr r1, lbl_0800e1f8 @ =0x030006fb
    adds r0, r4, r1
    ldrb r0, [r0]
    mov r1, ip
    strb r0, [r1, #2]
    ldr r1, lbl_0800e1fc @ =0x030006ec
    adds r0, r4, r1
    ldrb r0, [r0]
    b lbl_0800e206
    .align 2, 0
lbl_0800e1f4: .4byte 0x030001ac
lbl_0800e1f8: .4byte 0x030006fb
lbl_0800e1fc: .4byte 0x030006ec
lbl_0800e200:
    mov r0, ip
    strb r1, [r0, #2]
    subs r0, r4, #1
lbl_0800e206:
    mov r1, ip
    strb r0, [r1]
    mov r0, ip
    strb r3, [r0, #0x15]
    mov r1, sb
    strh r1, [r2, #2]
    strh r5, [r2, #4]
    mov r1, sl
    strb r1, [r0, #1]
    movs r0, #2
    mov r1, ip
    strb r0, [r1, #4]
    movs r0, #4
    strb r0, [r1, #5]
    strb r3, [r1, #7]
    strh r3, [r2, #0x14]
    strb r3, [r1, #0xe]
    strb r3, [r1, #3]
    strb r3, [r1, #0x16]
    strb r3, [r1, #0x17]
    strb r6, [r1, #9]
    strb r7, [r1, #6]
    strb r3, [r1, #0x13]
    strb r3, [r1, #0x14]
    b lbl_0800e248
lbl_0800e238:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    movs r0, #0x38
    add ip, r0
    adds r2, #0x38
    cmp r2, r8
    blo lbl_0800e1be
lbl_0800e248:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start spawn_new_secondary_sprite
spawn_new_secondary_sprite: @ 0x0800e258
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r4, [sp, #0x24]
    ldr r5, [sp, #0x28]
    ldr r6, [sp, #0x2c]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov sl, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov r8, r2
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp]
    lsls r4, r4, #0x10
    lsrs r7, r4, #0x10
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    movs r4, #0
    ldr r2, lbl_0800e2f0 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0800e306
    movs r0, #7
    movs r1, #0
    orrs r6, r0
    movs r0, #0x1d
    adds r0, r0, r2
    mov ip, r0
lbl_0800e2a8:
    ldrh r0, [r2]
    movs r3, #1
    ands r3, r0
    cmp r3, #0
    bne lbl_0800e2f4
    strh r6, [r2]
    movs r0, #0x80
    mov r6, ip
    strb r0, [r6, #0x15]
    mov r0, r8
    strb r0, [r6, #2]
    mov r0, sb
    strb r0, [r6]
    strh r7, [r2, #2]
    strh r5, [r2, #4]
    mov r5, sl
    strb r5, [r6, #1]
    movs r0, #2
    strb r0, [r6, #4]
    movs r0, #4
    strb r0, [r6, #5]
    strb r1, [r6, #7]
    strh r3, [r2, #0x14]
    strb r1, [r6, #0xe]
    strb r1, [r6, #3]
    strb r1, [r6, #0x16]
    strb r1, [r6, #0x17]
    movs r0, #1
    strb r0, [r6, #9]
    mov r2, sp
    ldrb r2, [r2]
    strb r2, [r6, #6]
    strb r1, [r6, #0x13]
    strb r1, [r6, #0x14]
    adds r0, r4, #0
    b lbl_0800e308
    .align 2, 0
lbl_0800e2f0: .4byte 0x030001ac
lbl_0800e2f4:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r0, #0x38
    add ip, r0
    adds r2, #0x38
    ldr r0, lbl_0800e318 @ =0x030006ec
    cmp r2, r0
    blo lbl_0800e2a8
lbl_0800e306:
    movs r0, #0xff
lbl_0800e308:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800e318: .4byte 0x030006ec

    thumb_func_start spawn_new_primary_sprite
spawn_new_primary_sprite: @ 0x0800e31c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [sp, #0x20]
    ldr r5, [sp, #0x24]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov sl, r1
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r8, r3
    lsls r4, r4, #0x10
    lsrs r6, r4, #0x10
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    movs r4, #0
    ldr r2, lbl_0800e3a8 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0800e3be
    movs r0, #7
    movs r1, #0
    orrs r5, r0
    movs r0, #0x1d
    adds r0, r0, r2
    mov ip, r0
lbl_0800e362:
    ldrh r0, [r2]
    movs r3, #1
    ands r3, r0
    cmp r3, #0
    bne lbl_0800e3ac
    strh r5, [r2]
    mov r5, ip
    strb r1, [r5, #0x15]
    strb r7, [r5, #2]
    mov r0, sb
    strb r0, [r5]
    mov r5, r8
    strh r5, [r2, #2]
    strh r6, [r2, #4]
    mov r5, sl
    mov r0, ip
    strb r5, [r0, #1]
    movs r0, #2
    mov r5, ip
    strb r0, [r5, #4]
    movs r0, #4
    strb r0, [r5, #5]
    strb r1, [r5, #7]
    strh r3, [r2, #0x14]
    strb r1, [r5, #0xe]
    strb r1, [r5, #3]
    strb r1, [r5, #0x16]
    strb r1, [r5, #0x17]
    movs r0, #1
    strb r0, [r5, #9]
    strb r4, [r5, #6]
    strb r1, [r5, #0x13]
    strb r1, [r5, #0x14]
    adds r0, r4, #0
    b lbl_0800e3c0
    .align 2, 0
lbl_0800e3a8: .4byte 0x030001ac
lbl_0800e3ac:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r0, #0x38
    add ip, r0
    adds r2, #0x38
    ldr r0, lbl_0800e3d0 @ =0x030006ec
    cmp r2, r0
    blo lbl_0800e362
lbl_0800e3be:
    movs r0, #0xff
lbl_0800e3c0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800e3d0: .4byte 0x030006ec

    thumb_func_start spawn_drops_and_followers
spawn_drops_and_followers: @ 0x0800e3d4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r4, [sp, #0x24]
    ldr r5, [sp, #0x28]
    ldr r6, [sp, #0x2c]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov sl, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov r8, r2
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp]
    lsls r4, r4, #0x10
    lsrs r7, r4, #0x10
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    movs r4, #0
    ldr r2, lbl_0800e46c @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0800e482
    movs r0, #7
    movs r1, #0
    orrs r6, r0
    movs r0, #0x1d
    adds r0, r0, r2
    mov ip, r0
lbl_0800e424:
    ldrh r0, [r2]
    movs r3, #1
    ands r3, r0
    cmp r3, #0
    bne lbl_0800e470
    strh r6, [r2]
    mov r6, ip
    strb r1, [r6, #0x15]
    mov r0, r8
    strb r0, [r6, #2]
    mov r0, sb
    strb r0, [r6]
    strh r7, [r2, #2]
    strh r5, [r2, #4]
    mov r5, sl
    strb r5, [r6, #1]
    movs r0, #2
    strb r0, [r6, #4]
    movs r0, #4
    strb r0, [r6, #5]
    strb r1, [r6, #7]
    strh r3, [r2, #0x14]
    strb r1, [r6, #0xe]
    strb r1, [r6, #3]
    strb r1, [r6, #0x16]
    strb r1, [r6, #0x17]
    movs r0, #1
    strb r0, [r6, #9]
    mov r2, sp
    ldrb r2, [r2]
    strb r2, [r6, #6]
    strb r1, [r6, #0x13]
    strb r1, [r6, #0x14]
    adds r0, r4, #0
    b lbl_0800e484
    .align 2, 0
lbl_0800e46c: .4byte 0x030001ac
lbl_0800e470:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r0, #0x38
    add ip, r0
    adds r2, #0x38
    ldr r0, lbl_0800e494 @ =0x030006ec
    cmp r2, r0
    blo lbl_0800e424
lbl_0800e482:
    movs r0, #0xff
lbl_0800e484:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800e494: .4byte 0x030006ec

    thumb_func_start init_location_text
init_location_text: @ 0x0800e498
    push {r4, lr}
    bl load_area_banner_gfx_slot
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #7
    bhi lbl_0800e502
    ldr r0, lbl_0800e508 @ =0x030001ac
    mov ip, r0
    movs r2, #0
    movs r3, #0
    ldr r0, lbl_0800e50c @ =0x00008017
    mov r1, ip
    strh r0, [r1]
    adds r1, #0x32
    movs r0, #0x20
    strb r0, [r1]
    mov r0, ip
    strb r4, [r0, #0x1f]
    movs r0, #0x74
    mov r1, ip
    strb r0, [r1, #0x1d]
    ldr r1, lbl_0800e510 @ =0x030013d4
    ldrh r0, [r1, #0x14]
    mov r4, ip
    strh r0, [r4, #2]
    ldrh r0, [r1, #0x12]
    strh r0, [r4, #4]
    mov r0, ip
    adds r0, #0x21
    strb r2, [r0]
    adds r0, #1
    movs r1, #1
    strb r1, [r0]
    adds r0, #2
    strb r2, [r0]
    strh r3, [r4, #0x14]
    adds r0, #7
    strb r2, [r0]
    subs r0, #0xb
    strb r2, [r0]
    adds r0, #0x13
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    subs r0, #0xe
    strb r1, [r0]
    subs r0, #3
    strb r2, [r0]
    adds r0, #0xd
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
lbl_0800e502:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e508: .4byte 0x030001ac
lbl_0800e50c: .4byte 0x00008017
lbl_0800e510: .4byte 0x030013d4

    thumb_func_start sub_0800e514
sub_0800e514: @ 0x0800e514
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r2, lbl_0800e594 @ =0x03001588
    adds r0, r2, #0
    adds r0, #0x72
    ldrh r0, [r0]
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    mov sb, r4
    adds r7, r2, #0
    adds r7, #0x6e
    movs r0, #0
    ldrsh r1, [r7, r0]
    adds r1, r4, r1
    adds r0, r5, #0
    bl check_collision_at_pos
    ldr r6, lbl_0800e598 @ =0x030007f1
    ldrb r2, [r6]
    mov r8, r2
    cmp r2, #0
    bne lbl_0800e586
    adds r0, r5, #0
    subs r0, #0x40
    movs r2, #0
    ldrsh r1, [r7, r2]
    adds r1, r4, r1
    bl check_collision_at_pos
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0800e56a
    bl is_morphed
    cmp r0, #0
    beq lbl_0800e586
lbl_0800e56a:
    ldr r2, lbl_0800e59c @ =0x030013d4
    mov r0, sb
    strh r0, [r2, #0x12]
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800e586
    ldr r0, lbl_0800e5a0 @ =0x03001530
    ldrh r0, [r0, #6]
    cmp r0, #0
    beq lbl_0800e586
    mov r0, r8
    strh r0, [r2, #0x16]
lbl_0800e586:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e594: .4byte 0x03001588
lbl_0800e598: .4byte 0x030007f1
lbl_0800e59c: .4byte 0x030013d4
lbl_0800e5a0: .4byte 0x03001530

    thumb_func_start sub_0800e5a4
sub_0800e5a4: @ 0x0800e5a4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r2, lbl_0800e624 @ =0x03001588
    adds r0, r2, #0
    adds r0, #0x6e
    ldrh r0, [r0]
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    mov sb, r4
    adds r7, r2, #0
    adds r7, #0x72
    movs r0, #0
    ldrsh r1, [r7, r0]
    adds r1, r4, r1
    adds r0, r5, #0
    bl check_collision_at_pos
    ldr r6, lbl_0800e628 @ =0x030007f1
    ldrb r2, [r6]
    mov r8, r2
    cmp r2, #0
    bne lbl_0800e618
    adds r0, r5, #0
    subs r0, #0x40
    movs r2, #0
    ldrsh r1, [r7, r2]
    adds r1, r4, r1
    bl check_collision_at_pos
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0800e5fa
    bl is_morphed
    cmp r0, #0
    beq lbl_0800e618
lbl_0800e5fa:
    ldr r2, lbl_0800e62c @ =0x030013d4
    mov r0, sb
    adds r0, #1
    strh r0, [r2, #0x12]
    ldrh r1, [r2, #0xe]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800e618
    ldr r0, lbl_0800e630 @ =0x03001530
    ldrh r0, [r0, #6]
    cmp r0, #0
    beq lbl_0800e618
    mov r0, r8
    strh r0, [r2, #0x16]
lbl_0800e618:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800e624: .4byte 0x03001588
lbl_0800e628: .4byte 0x030007f1
lbl_0800e62c: .4byte 0x030013d4
lbl_0800e630: .4byte 0x03001530

    thumb_func_start take_damage_from_sprite
take_damage_from_sprite: @ 0x0800e634
    push {r4, r5, r6, r7, lr}
    adds r3, r1, #0
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r2, r2, #0x10
    lsrs r4, r2, #0x10
    adds r0, r3, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0800e658
    ldr r2, lbl_0800e654 @ =0x082b1be4
    b lbl_0800e65a
    .align 2, 0
lbl_0800e654: .4byte 0x082b1be4
lbl_0800e658:
    ldr r2, lbl_0800e684 @ =0x082b0d68
lbl_0800e65a:
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r2, #2
    adds r0, r0, r2
    ldrh r3, [r0]
    adds r0, r3, #0
    muls r0, r4, r0
    lsls r5, r0, #0x10
    lsrs r3, r5, #0x10
    ldr r1, lbl_0800e688 @ =0x03001530
    ldrb r2, [r1, #0xf]
    adds r4, r2, #0
    movs r0, #0x30
    ands r0, r2
    adds r6, r1, #0
    cmp r0, #0x30
    bne lbl_0800e68c
    lsrs r3, r5, #0x11
    b lbl_0800e6ae
    .align 2, 0
lbl_0800e684: .4byte 0x082b0d68
lbl_0800e688: .4byte 0x03001530
lbl_0800e68c:
    movs r0, #0x20
    ands r2, r0
    cmp r2, #0
    beq lbl_0800e69a
    lsls r0, r3, #3
    subs r0, r0, r3
    b lbl_0800e6a4
lbl_0800e69a:
    movs r0, #0x10
    ands r4, r0
    cmp r4, #0
    beq lbl_0800e6ae
    lsls r0, r3, #3
lbl_0800e6a4:
    movs r1, #0xa
    bl __divsi3
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
lbl_0800e6ae:
    ldr r0, lbl_0800e6bc @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800e6c0
    lsrs r3, r3, #1
    b lbl_0800e6c8
    .align 2, 0
lbl_0800e6bc: .4byte 0x0300002c
lbl_0800e6c0:
    cmp r0, #2
    bne lbl_0800e6c8
    lsls r0, r3, #0x11
    lsrs r3, r0, #0x10
lbl_0800e6c8:
    cmp r3, #0
    bne lbl_0800e6ce
    movs r3, #1
lbl_0800e6ce:
    ldrh r0, [r6, #6]
    cmp r0, r3
    bls lbl_0800e6e6
    subs r0, r0, r3
    strh r0, [r6, #6]
    cmp r7, #0
    beq lbl_0800e6e2
    movs r0, #0xfa
    bl samus_set_pose
lbl_0800e6e2:
    movs r0, #1
    b lbl_0800e6f2
lbl_0800e6e6:
    movs r0, #0
    strh r0, [r6, #6]
    movs r0, #0xfa
    bl samus_set_pose
    movs r0, #0
lbl_0800e6f2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_collision
check_collision: @ 0x0800e6f8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r4, [sp, #0x18]
    ldr r5, [sp, #0x1c]
    mov r8, r5
    ldr r5, [sp, #0x20]
    ldr r6, [sp, #0x24]
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    mov r7, r8
    lsls r7, r7, #0x10
    mov r8, r7
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    cmp r8, r0
    blo lbl_0800e73c
    cmp r4, r1
    bhs lbl_0800e73c
    cmp r6, r2
    blo lbl_0800e73c
    cmp r5, r3
    bhs lbl_0800e73c
    movs r0, #1
    b lbl_0800e73e
lbl_0800e73c:
    movs r0, #0
lbl_0800e73e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start samus_sprite_collision
samus_sprite_collision: @ 0x0800e748
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x40
    ldr r0, lbl_0800e7c8 @ =0x030013d4
    mov sl, r0
    movs r1, #0
    str r1, [sp, #0x10]
    ldrh r2, [r0, #0x14]
    str r2, [sp, #0x14]
    ldrh r3, [r0, #0x12]
    str r3, [sp, #0x18]
    ldr r0, lbl_0800e7cc @ =0x03001600
    ldrh r0, [r0]
    str r0, [sp, #0x2c]
    ldr r1, lbl_0800e7d0 @ =0x03001588
    adds r0, r1, #0
    adds r0, #0x70
    ldrh r0, [r0]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    adds r0, r1, #0
    adds r0, #0x74
    ldrh r0, [r0]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x20]
    adds r0, r1, #0
    adds r0, #0x6e
    ldrh r0, [r0]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x24]
    adds r0, r1, #0
    adds r0, #0x72
    ldrh r0, [r0]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x28]
    mov r1, sl
    ldrb r0, [r1]
    cmp r0, #0x26
    bne lbl_0800e7fe
    ldrb r0, [r1, #4]
    cmp r0, #0
    beq lbl_0800e80a
    cmp r0, #1
    bne lbl_0800e7d4
    ldr r0, [sp, #0x1c]
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    ldr r0, [sp, #0x20]
    adds r0, #0x20
    b lbl_0800e7f6
    .align 2, 0
lbl_0800e7c8: .4byte 0x030013d4
lbl_0800e7cc: .4byte 0x03001600
lbl_0800e7d0: .4byte 0x03001588
lbl_0800e7d4:
    ldr r0, [sp, #0x24]
    subs r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x24]
    ldr r0, [sp, #0x28]
    adds r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x28]
    ldr r0, [sp, #0x1c]
    subs r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    ldr r0, [sp, #0x20]
    adds r0, #0x18
lbl_0800e7f6:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x20]
    b lbl_0800e81e
lbl_0800e7fe:
    cmp r0, #0x22
    bne lbl_0800e81e
    mov r2, sl
    ldrb r0, [r2, #4]
    cmp r0, #0
    bne lbl_0800e81e
lbl_0800e80a:
    ldr r0, [sp, #0x24]
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x24]
    ldr r0, [sp, #0x28]
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x28]
lbl_0800e81e:
    ldr r6, lbl_0800e8ec @ =0x030001ac
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r0, r6, r3
    cmp r6, r0
    blo lbl_0800e82e
    bl lbl_0800f314
lbl_0800e82e:
    ldrh r0, [r6]
    movs r1, #3
    ands r0, r1
    cmp r0, #3
    beq lbl_0800e83c
    bl sub_0800f308
lbl_0800e83c:
    adds r0, r6, #0
    adds r0, #0x26
    ldrb r4, [r0]
    str r0, [sp, #0x3c]
    cmp r4, #0
    beq lbl_0800e84c
    bl sub_0800f308
lbl_0800e84c:
    ldrh r2, [r6, #2]
    str r2, [sp, #0x30]
    ldrh r3, [r6, #4]
    str r3, [sp, #0x34]
    ldrh r0, [r6, #0xa]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r0, [r6, #0xc]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrh r0, [r6, #0xe]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrh r0, [r6, #0x10]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    str r5, [sp]
    mov r0, sb
    str r0, [sp, #4]
    mov r1, r8
    str r1, [sp, #8]
    str r7, [sp, #0xc]
    ldr r0, [sp, #0x1c]
    ldr r1, [sp, #0x20]
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x28]
    bl check_collision
    cmp r0, #0
    bne lbl_0800e898
    bl sub_0800f308
lbl_0800e898:
    ldr r0, lbl_0800e8f0 @ =0x030007f2
    strb r4, [r0]
    mov r2, sb
    subs r0, r2, r5
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    mov r3, r8
    subs r0, r7, r3
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    add r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    movs r4, #0
    subs r0, r2, #4
    ldr r1, [sp, #0x20]
    cmp r0, r1
    ble lbl_0800e8d4
    mov r3, sl
    movs r1, #0x18
    ldrsh r0, [r3, r1]
    cmp r0, #0x18
    bgt lbl_0800e8d4
    movs r4, #1
lbl_0800e8d4:
    adds r0, r2, #4
    ldr r2, [sp, #0x1c]
    cmp r0, r2
    bge lbl_0800e8e0
    movs r0, #2
    orrs r4, r0
lbl_0800e8e0:
    ldr r3, [sp, #0x2c]
    cmp ip, r3
    blo lbl_0800e8f4
    movs r0, #4
    b lbl_0800e8f6
    .align 2, 0
lbl_0800e8ec: .4byte 0x030001ac
lbl_0800e8f0: .4byte 0x030007f2
lbl_0800e8f4:
    movs r0, #8
lbl_0800e8f6:
    orrs r4, r0
    lsls r0, r4, #0x18
    lsrs r4, r0, #0x18
    adds r0, r6, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800e908
    b lbl_0800ea02
lbl_0800e908:
    bl is_pulling_self_up
    cmp r0, #0
    beq lbl_0800e914
    bl lbl_0800f300
lbl_0800e914:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800e924
    bl lbl_0800f300
lbl_0800e924:
    bl is_on_zipline
    cmp r0, #0
    beq lbl_0800e936
    movs r0, #0xfe
    bl samus_set_pose
    bl lbl_0800f300
lbl_0800e936:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800e98c
    ldr r0, lbl_0800e984 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800e988 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800e95c
    bl lbl_0800f300
lbl_0800e95c:
    mov r2, sl
    movs r3, #0x18
    ldrsh r0, [r2, r3]
    cmp r0, #0
    ble lbl_0800e96a
    bl lbl_0800f300
lbl_0800e96a:
    adds r0, r5, #1
    strh r0, [r2, #0x14]
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #2
    bl lbl_0800f2fe
    .align 2, 0
lbl_0800e984: .4byte 0x03001588
lbl_0800e988: .4byte 0x030007f1
lbl_0800e98c:
    ldr r0, [sp, #0x1c]
    adds r0, #0x10
    cmp r0, sb
    ble lbl_0800e9e8
    ldr r0, lbl_0800e9dc @ =0x03001588
    adds r4, r0, #0
    adds r4, #0x70
    movs r3, #0
    ldrsh r0, [r4, r3]
    mov r1, sb
    subs r0, r1, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800e9e0 @ =0x030007f1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_0800e9b4
    bl lbl_0800f300
lbl_0800e9b4:
    ldrh r0, [r4]
    mov r2, sb
    subs r0, r2, r0
    mov r3, sl
    strh r0, [r3, #0x14]
    movs r2, #0x18
    ldrsh r0, [r3, r2]
    cmp r0, #0
    bgt lbl_0800e9ca
    bl lbl_0800f300
lbl_0800e9ca:
    ldr r0, lbl_0800e9e4 @ =0x03001530
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_0800e9d6
    bl lbl_0800f300
lbl_0800e9d6:
    strh r1, [r3, #0x18]
    bl lbl_0800f300
    .align 2, 0
lbl_0800e9dc: .4byte 0x03001588
lbl_0800e9e0: .4byte 0x030007f1
lbl_0800e9e4: .4byte 0x03001530
lbl_0800e9e8:
    ldr r3, [sp, #0x18]
    cmp r3, r8
    blo lbl_0800e9f6
    cmp r3, r7
    bhi lbl_0800e9f6
    bl lbl_0800f300
lbl_0800e9f6:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800ea00
    b lbl_0800f026
lbl_0800ea00:
    b lbl_0800f030
lbl_0800ea02:
    adds r0, r6, #0
    adds r0, #0x25
    ldrb r1, [r0]
    str r0, [sp, #0x38]
    cmp r1, #0x24
    bls lbl_0800ea12
    bl lbl_0800f2f4
lbl_0800ea12:
    lsls r0, r1, #2
    ldr r1, lbl_0800ea1c @ =lbl_0800ea20
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800ea1c: .4byte lbl_0800ea20
lbl_0800ea20: @ jump table
    .4byte lbl_0800f300 @ case 0
    .4byte lbl_0800eac6 @ case 1
    .4byte lbl_0800eba0 @ case 2
    .4byte lbl_0800ec0c @ case 3
    .4byte lbl_0800ee36 @ case 4
    .4byte lbl_0800eece @ case 5
    .4byte lbl_0800ee2e @ case 6
    .4byte lbl_0800f160 @ case 7
    .4byte lbl_0800f2f4 @ case 8
    .4byte lbl_0800ef2e @ case 9
    .4byte lbl_0800f0a8 @ case 10
    .4byte lbl_0800f03a @ case 11
    .4byte lbl_0800f010 @ case 12
    .4byte lbl_0800ee84 @ case 13
    .4byte lbl_0800ee7c @ case 14
    .4byte lbl_0800ee6c @ case 15
    .4byte lbl_0800ef68 @ case 16
    .4byte lbl_0800ef70 @ case 17
    .4byte lbl_0800ee36 @ case 18
    .4byte lbl_0800ee2e @ case 19
    .4byte lbl_0800ef16 @ case 20
    .4byte lbl_0800edfc @ case 21
    .4byte lbl_0800ed6a @ case 22
    .4byte lbl_0800f190 @ case 23
    .4byte lbl_0800f200 @ case 24
    .4byte lbl_0800ecb4 @ case 25
    .4byte lbl_0800ef90 @ case 26
    .4byte lbl_0800eab4 @ case 27
    .4byte lbl_0800f25a @ case 28
    .4byte lbl_0800f2c0 @ case 29
    .4byte lbl_0800ed5c @ case 30
    .4byte lbl_0800ed5c @ case 31
    .4byte lbl_0800ed5c @ case 32
    .4byte lbl_0800ed5c @ case 33
    .4byte lbl_0800ed5c @ case 34
    .4byte lbl_0800ed5c @ case 35
    .4byte lbl_0800ed5c @ case 36
lbl_0800eab4:
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    ldr r1, lbl_0800eb30 @ =0x030007f2
    movs r0, #1
    strb r0, [r1]
lbl_0800eac6:
    bl is_pulling_self_up
    cmp r0, #0
    beq lbl_0800ead2
    bl lbl_0800f300
lbl_0800ead2:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800eae2
    bl lbl_0800f300
lbl_0800eae2:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800eb3c
    ldr r0, lbl_0800eb34 @ =0x03001588
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800eb38 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800eb08
    bl lbl_0800f300
lbl_0800eb08:
    mov r1, sl
    movs r2, #0x18
    ldrsh r0, [r1, r2]
    cmp r0, #0
    ble lbl_0800eb16
    bl lbl_0800f300
lbl_0800eb16:
    adds r0, r5, #1
    strh r0, [r1, #0x14]
    ldrh r1, [r6]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r6]
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #2
    bl lbl_0800f2fe
    .align 2, 0
lbl_0800eb30: .4byte 0x030007f2
lbl_0800eb34: .4byte 0x03001588
lbl_0800eb38: .4byte 0x030007f1
lbl_0800eb3c:
    ldr r0, [sp, #0x1c]
    adds r0, #0x10
    cmp r0, sb
    ble lbl_0800eb90
    ldr r0, lbl_0800eb84 @ =0x03001588
    adds r4, r0, #0
    adds r4, #0x70
    movs r1, #0
    ldrsh r0, [r4, r1]
    mov r2, sb
    subs r0, r2, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800eb88 @ =0x030007f1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_0800eb62
    b lbl_0800f300
lbl_0800eb62:
    ldrh r0, [r4]
    mov r3, sb
    subs r0, r3, r0
    mov r2, sl
    strh r0, [r2, #0x14]
    movs r3, #0x18
    ldrsh r0, [r2, r3]
    cmp r0, #0
    bgt lbl_0800eb76
    b lbl_0800f300
lbl_0800eb76:
    ldr r0, lbl_0800eb8c @ =0x03001530
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_0800eb80
    b lbl_0800f300
lbl_0800eb80:
    strh r1, [r2, #0x18]
    b lbl_0800f300
    .align 2, 0
lbl_0800eb84: .4byte 0x03001588
lbl_0800eb88: .4byte 0x030007f1
lbl_0800eb8c: .4byte 0x03001530
lbl_0800eb90:
    ldr r0, [sp, #0x18]
    cmp r0, r8
    bhs lbl_0800eb98
    b lbl_0800e9f6
lbl_0800eb98:
    cmp r0, r7
    bhi lbl_0800eb9e
    b lbl_0800f300
lbl_0800eb9e:
    b lbl_0800e9f6
lbl_0800eba0:
    bl is_pulling_self_up
    cmp r0, #0
    beq lbl_0800ebaa
    b lbl_0800f300
lbl_0800ebaa:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ebb8
    b lbl_0800f300
lbl_0800ebb8:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    blt lbl_0800ebc2
    b lbl_0800f300
lbl_0800ebc2:
    ldr r0, lbl_0800ec04 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800ec08 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800ebde
    b lbl_0800f300
lbl_0800ebde:
    mov r2, sl
    movs r3, #0x18
    ldrsh r0, [r2, r3]
    cmp r0, #0
    ble lbl_0800ebea
    b lbl_0800f300
lbl_0800ebea:
    adds r0, r5, #1
    strh r0, [r2, #0x14]
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #2
    b lbl_0800f2fe
    .align 2, 0
lbl_0800ec04: .4byte 0x03001588
lbl_0800ec08: .4byte 0x030007f1
lbl_0800ec0c:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ec1a
    b lbl_0800f300
lbl_0800ec1a:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800ec80
    bl is_pulling_self_up
    cmp r0, #0
    beq lbl_0800ec2c
    b lbl_0800f300
lbl_0800ec2c:
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #0x27
    bls lbl_0800ec36
    b lbl_0800f300
lbl_0800ec36:
    ldr r0, lbl_0800ec78 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800ec7c @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800ec52
    b lbl_0800f300
lbl_0800ec52:
    mov r2, sl
    movs r3, #0x18
    ldrsh r0, [r2, r3]
    cmp r0, #0
    ble lbl_0800ec5e
    b lbl_0800f300
lbl_0800ec5e:
    adds r0, r5, #1
    strh r0, [r2, #0x14]
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #2
    b lbl_0800f2fe
    .align 2, 0
lbl_0800ec78: .4byte 0x03001588
lbl_0800ec7c: .4byte 0x030007f1
lbl_0800ec80:
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #0
    beq lbl_0800ec8a
    b lbl_0800f2f4
lbl_0800ec8a:
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800ec9c
    b lbl_0800f2f4
lbl_0800ec9c:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    bne lbl_0800eca6
    b lbl_0800ef26
lbl_0800eca6:
    ldr r0, lbl_0800ecb0 @ =0x0000ffc0
    mov r1, sl
    strh r0, [r1, #0x16]
    b lbl_0800f2f4
    .align 2, 0
lbl_0800ecb0: .4byte 0x0000ffc0
lbl_0800ecb4:
    ldr r0, [sp, #0x18]
    cmp r0, r7
    bls lbl_0800ecf6
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800ecee
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800ecee
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800ece8
    ldr r0, lbl_0800ece4 @ =0x0000ffc0
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800ecee
    .align 2, 0
lbl_0800ece4: .4byte 0x0000ffc0
lbl_0800ece8:
    movs r0, #0x40
    mov r3, sl
    strh r0, [r3, #0x16]
lbl_0800ecee:
    movs r0, #0xf
    ldr r1, [sp, #0x3c]
    strb r0, [r1]
    b lbl_0800f2fa
lbl_0800ecf6:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    blt lbl_0800ed00
    b lbl_0800f300
lbl_0800ed00:
    bl is_pulling_self_up
    cmp r0, #0
    beq lbl_0800ed0a
    b lbl_0800f300
lbl_0800ed0a:
    mov r2, sl
    ldrb r0, [r2, #6]
    cmp r0, #0x25
    bls lbl_0800ed14
    b lbl_0800f300
lbl_0800ed14:
    ldr r0, lbl_0800ed54 @ =0x03001588
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldr r0, lbl_0800ed58 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800ed30
    b lbl_0800f300
lbl_0800ed30:
    mov r1, sl
    movs r2, #0x18
    ldrsh r0, [r1, r2]
    cmp r0, #0
    ble lbl_0800ed3c
    b lbl_0800f300
lbl_0800ed3c:
    adds r0, r5, #1
    strh r0, [r1, #0x14]
    ldrh r1, [r6]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r6]
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #2
    b lbl_0800f2fe
    .align 2, 0
lbl_0800ed54: .4byte 0x03001588
lbl_0800ed58: .4byte 0x030007f1
lbl_0800ed5c:
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    b lbl_0800f2fa
lbl_0800ed6a:
    adds r0, r6, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0xf
    beq lbl_0800ed78
    cmp r0, #0x25
    bne lbl_0800edfc
lbl_0800ed78:
    ldrh r1, [r6]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800edc4
    adds r0, r6, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    subs r0, #0x21
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1e
    bhi lbl_0800edfc
    movs r3, #0x80
    lsls r3, r3, #4
    adds r0, r3, #0
    movs r4, #0
    orrs r0, r1
    strh r0, [r6]
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800edb6
    ldr r0, lbl_0800edc0 @ =0x0000ffa0
    mov r1, sl
    strh r0, [r1, #0x16]
lbl_0800edb6:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800edc0: .4byte 0x0000ffa0
lbl_0800edc4:
    adds r0, r6, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    adds r0, #0x3f
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1e
    bhi lbl_0800edfc
    movs r3, #0x80
    lsls r3, r3, #4
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r6]
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800edf4
    movs r0, #0x60
    mov r1, sl
    strh r0, [r1, #0x16]
lbl_0800edf4:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
lbl_0800edfc:
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800ee26
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800ee20
    ldr r0, lbl_0800ee1c @ =0x0000ffc0
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800ee26
    .align 2, 0
lbl_0800ee1c: .4byte 0x0000ffc0
lbl_0800ee20:
    movs r0, #0x40
    mov r1, sl
    strh r0, [r1, #0x16]
lbl_0800ee26:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
lbl_0800ee2e:
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_0800ee36:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ee44
    b lbl_0800f300
lbl_0800ee44:
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #0
    beq lbl_0800ee4e
    b lbl_0800f2f4
lbl_0800ee4e:
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800ee60
    b lbl_0800f2f4
lbl_0800ee60:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800ee6a
    b lbl_0800eca6
lbl_0800ee6a:
    b lbl_0800ef26
lbl_0800ee6c:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ee7a
    b lbl_0800f300
lbl_0800ee7a:
    b lbl_0800ee4e
lbl_0800ee7c:
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_0800ee84:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ee92
    b lbl_0800f300
lbl_0800ee92:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800eec6
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800eec6
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800eec0
    ldr r0, lbl_0800eebc @ =0x0000ff80
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800eec6
    .align 2, 0
lbl_0800eebc: .4byte 0x0000ff80
lbl_0800eec0:
    movs r0, #0x80
    mov r3, sl
    strh r0, [r3, #0x16]
lbl_0800eec6:
    movs r0, #0xf
    ldr r1, [sp, #0x3c]
    strb r0, [r1]
    b lbl_0800f2fa
lbl_0800eece:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800eedc
    b lbl_0800f300
lbl_0800eedc:
    mov r2, sl
    ldrb r0, [r2, #6]
    cmp r0, #0
    bne lbl_0800ef0e
    movs r0, #1
    adds r1, r6, #0
    movs r2, #5
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800ef0e
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800ef08
    ldr r0, lbl_0800ef04 @ =0x0000ffb8
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800ef0e
    .align 2, 0
lbl_0800ef04: .4byte 0x0000ffb8
lbl_0800ef08:
    movs r0, #0x48
    mov r1, sl
    strh r0, [r1, #0x16]
lbl_0800ef0e:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
lbl_0800ef16:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800ef24
    b lbl_0800f300
lbl_0800ef24:
    b lbl_0800ec80
lbl_0800ef26:
    movs r0, #0x40
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800f2f4
lbl_0800ef2e:
    ldrh r0, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r2, #0
    orrs r1, r0
    strh r1, [r6]
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #7
    bhi lbl_0800ef5a
    movs r0, #0
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    ldr r0, lbl_0800ef64 @ =0x03001530
    ldrh r0, [r0, #6]
    cmp r0, #0
    beq lbl_0800ef5a
    movs r0, #8
    mov r1, sl
    strb r0, [r1, #6]
lbl_0800ef5a:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800ef64: .4byte 0x03001530
lbl_0800ef68:
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_0800ef70:
    movs r0, #0
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    movs r0, #0xf
    ldr r3, [sp, #0x3c]
    strb r0, [r3]
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0800ef8a
    b lbl_0800f2fa
lbl_0800ef8a:
    movs r0, #8
    strb r0, [r1, #6]
    b lbl_0800f2fa
lbl_0800ef90:
    movs r0, #2
    ands r4, r0
    cmp r4, #0
    bne lbl_0800ef9a
    b lbl_0800f2f4
lbl_0800ef9a:
    mov r2, sl
    ldrb r0, [r2]
    cmp r0, #0xc
    beq lbl_0800efb6
    cmp r0, #0xc
    bgt lbl_0800efac
    cmp r0, #8
    beq lbl_0800efb6
    b lbl_0800f2f4
lbl_0800efac:
    cmp r0, #0x14
    beq lbl_0800efde
    cmp r0, #0x26
    beq lbl_0800efd8
    b lbl_0800f2f4
lbl_0800efb6:
    ldrh r1, [r6, #2]
    adds r1, #0xa8
    mov r3, sl
    strh r1, [r3, #0x14]
    ldrh r2, [r6, #4]
    strh r2, [r3, #0x12]
    ldr r0, lbl_0800efd0 @ =0x03001602
    strh r1, [r0]
    ldr r0, lbl_0800efd4 @ =0x03001600
    strh r2, [r0]
    movs r0, #0x28
    b lbl_0800eff4
    .align 2, 0
lbl_0800efd0: .4byte 0x03001602
lbl_0800efd4: .4byte 0x03001600
lbl_0800efd8:
    movs r0, #0x8f
    bl play_sound2
lbl_0800efde:
    ldrh r1, [r6, #2]
    adds r1, #0x3c
    mov r3, sl
    strh r1, [r3, #0x14]
    ldrh r2, [r6, #4]
    strh r2, [r3, #0x12]
    ldr r0, lbl_0800f008 @ =0x03001602
    strh r1, [r0]
    ldr r0, lbl_0800f00c @ =0x03001600
    strh r2, [r0]
    movs r0, #0x2b
lbl_0800eff4:
    bl samus_set_pose
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    b lbl_0800f2f4
    .align 2, 0
lbl_0800f008: .4byte 0x03001602
lbl_0800f00c: .4byte 0x03001600
lbl_0800f010:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800f01e
    b lbl_0800f300
lbl_0800f01e:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f030
lbl_0800f026:
    ldr r0, [sp, #0x14]
    mov r1, r8
    bl sub_0800e514
    b lbl_0800f300
lbl_0800f030:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl sub_0800e5a4
    b lbl_0800f300
lbl_0800f03a:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800f048
    b lbl_0800f300
lbl_0800f048:
    movs r0, #4
    ands r0, r4
    cmp r0, #0
    beq lbl_0800f05a
    ldr r0, [sp, #0x14]
    mov r1, r8
    bl sub_0800e514
    b lbl_0800f062
lbl_0800f05a:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl sub_0800e5a4
lbl_0800f062:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0800f06c
    b lbl_0800f300
lbl_0800f06c:
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800f07e
    b lbl_0800f2fa
lbl_0800f07e:
    ldr r0, lbl_0800f098 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800f088
    b lbl_0800f2fa
lbl_0800f088:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f0a0
    ldr r0, lbl_0800f09c @ =0x0000ffc0
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800f098: .4byte 0x030007f1
lbl_0800f09c: .4byte 0x0000ffc0
lbl_0800f0a0:
    movs r0, #0x40
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800f2fa
lbl_0800f0a8:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800f0b6
    b lbl_0800f300
lbl_0800f0b6:
    movs r0, #4
    ands r0, r4
    cmp r0, #0
    beq lbl_0800f0c8
    ldr r0, [sp, #0x14]
    mov r1, r8
    bl sub_0800e514
    b lbl_0800f0d0
lbl_0800f0c8:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl sub_0800e5a4
lbl_0800f0d0:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800f110
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800f0ea
    b lbl_0800f2fa
lbl_0800f0ea:
    ldr r0, lbl_0800f104 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800f0f4
    b lbl_0800f2fa
lbl_0800f0f4:
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f10c
    ldr r0, lbl_0800f108 @ =0x0000ffc0
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800f104: .4byte 0x030007f1
lbl_0800f108: .4byte 0x0000ffc0
lbl_0800f10c:
    movs r0, #0x40
    b lbl_0800f146
lbl_0800f110:
    ldr r5, lbl_0800f14c @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0800f11a
    b lbl_0800f2fa
lbl_0800f11a:
    ldr r0, lbl_0800f150 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    ldr r2, [sp, #0x14]
    adds r0, r2, r0
    ldr r1, [sp, #0x18]
    bl check_collision_at_pos
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0800f136
    b lbl_0800f2fa
lbl_0800f136:
    movs r0, #0xf9
    bl samus_set_pose
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f158
    ldr r0, lbl_0800f154 @ =0x0000ffc0
lbl_0800f146:
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800f14c: .4byte 0x030007f1
lbl_0800f150: .4byte 0x03001588
lbl_0800f154: .4byte 0x0000ffc0
lbl_0800f158:
    movs r0, #0x40
    mov r1, sl
    strh r0, [r1, #0x16]
    b lbl_0800f2fa
lbl_0800f160:
    adds r0, r6, #0
    mov r1, sl
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    beq lbl_0800f16e
    b lbl_0800f300
lbl_0800f16e:
    movs r0, #0xf9
    bl samus_set_pose
    movs r0, #4
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f188
    ldr r0, lbl_0800f184 @ =0x0000ffe0
    mov r2, sl
    strh r0, [r2, #0x16]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800f184: .4byte 0x0000ffe0
lbl_0800f188:
    movs r0, #0x20
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800f2fa
lbl_0800f190:
    ldrh r0, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r2, #0
    orrs r1, r0
    strh r1, [r6]
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #0
    bne lbl_0800f1ee
    ldr r0, lbl_0800f1f8 @ =0x03001530
    ldrb r1, [r0, #0xf]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    bne lbl_0800f1ee
    bl sub_0802fef0
    cmp r0, #0
    bne lbl_0800f1ba
    b lbl_0800f300
lbl_0800f1ba:
    ldr r0, [sp, #0x10]
    lsrs r2, r0, #2
    movs r0, #0
    adds r1, r6, #0
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800f1ee
    movs r0, #0x10
    mov r1, sl
    strb r0, [r1, #6]
    movs r0, #0x80
    bl sub_08002b20
    ldr r1, lbl_0800f1fc @ =0x0300070c
    ldrb r0, [r1, #0xe]
    adds r0, #1
    strb r0, [r1, #0xe]
    movs r1, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0800f1ee
    movs r0, #0x7c
    bl play_sound1
lbl_0800f1ee:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f300
    .align 2, 0
lbl_0800f1f8: .4byte 0x03001530
lbl_0800f1fc: .4byte 0x0300070c
lbl_0800f200:
    ldr r0, [sp, #0x30]
    adds r0, #0x20
    ldr r3, [sp, #0x14]
    cmp r3, r0
    ble lbl_0800f216
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
lbl_0800f216:
    mov r3, sl
    ldrb r0, [r3, #6]
    cmp r0, #0
    bne lbl_0800f300
    movs r0, #0
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800f300
    ldr r0, lbl_0800f240 @ =0x03001530
    ldrb r0, [r0, #0xf]
    movs r1, #0x30
    ands r1, r0
    str r1, [sp, #0x10]
    cmp r1, #0
    bne lbl_0800f244
    movs r0, #1
    b lbl_0800f254
    .align 2, 0
lbl_0800f240: .4byte 0x03001530
lbl_0800f244:
    ldr r3, [sp, #0x10]
    cmp r3, #0x30
    bne lbl_0800f252
    movs r0, #8
    mov r1, sl
    strb r0, [r1, #6]
    b lbl_0800f300
lbl_0800f252:
    movs r0, #4
lbl_0800f254:
    mov r2, sl
    strb r0, [r2, #6]
    b lbl_0800f300
lbl_0800f25a:
    movs r0, #2
    ands r4, r0
    cmp r4, #0
    beq lbl_0800f29c
    ldr r0, [sp, #0x30]
    ldr r1, [sp, #0x34]
    bl ridley_check_grabbing
    cmp r0, #0
    beq lbl_0800f29c
    ldrh r1, [r6]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r0, r3, #0
    movs r2, #0
    orrs r0, r1
    strh r0, [r6]
    ldr r0, [sp, #0x38]
    strb r2, [r0]
    ldr r1, lbl_0800f294 @ =0x030007f2
    movs r0, #1
    strb r0, [r1]
    movs r0, #8
    bl samus_set_pose
    ldr r0, lbl_0800f298 @ =0x000001e3
    bl play_sound1
    b lbl_0800f300
    .align 2, 0
lbl_0800f294: .4byte 0x030007f2
lbl_0800f298: .4byte 0x000001e3
lbl_0800f29c:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800f2b8
    adds r0, r6, #0
    bl sprite_take_damage_from_samus_contact
    cmp r0, #0
    bne lbl_0800f2b8
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl take_damage_from_sprite
lbl_0800f2b8:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
lbl_0800f2c0:
    bl get_final_completion_percentage
    movs r3, #1
    str r3, [sp, #0x10]
    cmp r0, #0x64
    bne lbl_0800f2d0
    movs r0, #2
    str r0, [sp, #0x10]
lbl_0800f2d0:
    movs r0, #1
    adds r1, r6, #0
    ldr r2, [sp, #0x10]
    bl take_damage_from_sprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800f2e6
    ldr r0, lbl_0800f2f0 @ =0x0000ff80
    mov r1, sl
    strh r0, [r1, #0x16]
lbl_0800f2e6:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
    .align 2, 0
lbl_0800f2f0: .4byte 0x0000ff80
lbl_0800f2f4:
    movs r0, #0xf
    ldr r3, [sp, #0x3c]
    strb r0, [r3]
lbl_0800f2fa:
    ldr r1, lbl_0800f354 @ =0x030007f2
    movs r0, #1
lbl_0800f2fe:
    strb r0, [r1]
lbl_0800f300:
    ldr r0, lbl_0800f354 @ =0x030007f2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800f314

    thumb_func_start sub_0800f308
sub_0800f308: @ 0x0800f308
    adds r6, #0x38
    ldr r0, lbl_0800f358 @ =0x030006ec
    cmp r6, r0
    bhs lbl_0800f314
    bl lbl_0800e82e
lbl_0800f314:
    ldr r6, lbl_0800f35c @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r6, r1
    cmp r6, r0
    bhs lbl_0800f342
    movs r3, #1
    adds r2, r0, #0
lbl_0800f324:
    ldrh r1, [r6]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f33c
    adds r1, r6, #0
    adds r1, #0x26
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0800f33c
    subs r0, #1
    strb r0, [r1]
lbl_0800f33c:
    adds r6, #0x38
    cmp r6, r2
    blo lbl_0800f324
lbl_0800f342:
    add sp, #0x40
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f354: .4byte 0x030007f2
lbl_0800f358: .4byte 0x030006ec
lbl_0800f35c: .4byte 0x030001ac

    thumb_func_start check_vertical_collision_at_pos
check_vertical_collision_at_pos: @ 0x0800f360
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_08057e7c
    adds r3, r0, #0
    movs r2, #0x80
    lsls r2, r2, #0x11
    ands r2, r3
    cmp r2, #0
    beq lbl_0800f38c
    ldr r1, lbl_0800f388 @ =0x030007f0
    movs r0, #0x11
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_0800f392
    .align 2, 0
lbl_0800f388: .4byte 0x030007f0
lbl_0800f38c:
    ldr r0, lbl_0800f3a8 @ =0x030007f0
    strb r2, [r0]
    adds r2, r0, #0
lbl_0800f392:
    movs r0, #0xff
    ands r0, r3
    subs r0, #2
    cmp r0, #0xa
    bhi lbl_0800f46c
    lsls r0, r0, #2
    ldr r1, lbl_0800f3ac @ =lbl_0800f3b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800f3a8: .4byte 0x030007f0
lbl_0800f3ac: .4byte lbl_0800f3b0
lbl_0800f3b0: @ jump table
    .4byte lbl_0800f428 @ case 0
    .4byte lbl_0800f3dc @ case 1
    .4byte lbl_0800f450 @ case 2
    .4byte lbl_0800f43c @ case 3
    .4byte lbl_0800f3f8 @ case 4
    .4byte lbl_0800f40c @ case 5
    .4byte lbl_0800f46c @ case 6
    .4byte lbl_0800f46c @ case 7
    .4byte lbl_0800f46c @ case 8
    .4byte lbl_0800f46c @ case 9
    .4byte lbl_0800f468 @ case 10
lbl_0800f3dc:
    ldr r0, lbl_0800f3f4 @ =0x0000ffc0
    ands r0, r4
    movs r1, #0x3f
    ands r1, r5
    subs r1, #0x3f
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r0, #5
    strb r0, [r2]
    b lbl_0800f470
    .align 2, 0
lbl_0800f3f4: .4byte 0x0000ffc0
lbl_0800f3f8:
    ldr r0, lbl_0800f408 @ =0x0000ffc0
    ands r0, r4
    movs r1, #0x3f
    ands r1, r5
    lsrs r1, r1, #1
    subs r1, #0x3f
    b lbl_0800f418
    .align 2, 0
lbl_0800f408: .4byte 0x0000ffc0
lbl_0800f40c:
    ldr r0, lbl_0800f424 @ =0x0000ffc0
    ands r0, r4
    movs r1, #0x3f
    ands r1, r5
    lsrs r1, r1, #1
    subs r1, #0x1f
lbl_0800f418:
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r0, #3
    strb r0, [r2]
    b lbl_0800f470
    .align 2, 0
lbl_0800f424: .4byte 0x0000ffc0
lbl_0800f428:
    ldr r1, lbl_0800f438 @ =0x0000ffc0
    ands r1, r4
    movs r0, #0x3f
    ands r0, r5
    orrs r1, r0
    movs r0, #4
    strb r0, [r2]
    b lbl_0800f470
    .align 2, 0
lbl_0800f438: .4byte 0x0000ffc0
lbl_0800f43c:
    ldr r1, lbl_0800f44c @ =0x0000ffc0
    ands r1, r4
    movs r0, #0x3f
    ands r0, r5
    lsrs r0, r0, #1
    adds r0, #0x1f
    b lbl_0800f45a
    .align 2, 0
lbl_0800f44c: .4byte 0x0000ffc0
lbl_0800f450:
    ldr r1, lbl_0800f464 @ =0x0000ffc0
    ands r1, r4
    movs r0, #0x3f
    ands r0, r5
    lsrs r0, r0, #1
lbl_0800f45a:
    orrs r1, r0
    movs r0, #2
    strb r0, [r2]
    b lbl_0800f470
    .align 2, 0
lbl_0800f464: .4byte 0x0000ffc0
lbl_0800f468:
    movs r0, #0x10
    strb r0, [r2]
lbl_0800f46c:
    ldr r1, lbl_0800f478 @ =0x0000ffc0
    ands r1, r4
lbl_0800f470:
    adds r0, r1, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800f478: .4byte 0x0000ffc0

    thumb_func_start check_vertical_collision_at_pos_slopes
check_vertical_collision_at_pos_slopes: @ 0x0800f47c
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08057e7c
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    movs r3, #0
    cmp r0, #0
    beq lbl_0800f49e
    movs r3, #0x11
lbl_0800f49e:
    movs r0, #0xff
    ands r0, r1
    subs r0, #2
    cmp r0, #0xa
    bhi lbl_0800f56a
    lsls r0, r0, #2
    ldr r1, lbl_0800f4b4 @ =lbl_0800f4b8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800f4b4: .4byte lbl_0800f4b8
lbl_0800f4b8: @ jump table
    .4byte lbl_0800f52c @ case 0
    .4byte lbl_0800f4e4 @ case 1
    .4byte lbl_0800f554 @ case 2
    .4byte lbl_0800f540 @ case 3
    .4byte lbl_0800f4fc @ case 4
    .4byte lbl_0800f510 @ case 5
    .4byte lbl_0800f56a @ case 6
    .4byte lbl_0800f56a @ case 7
    .4byte lbl_0800f56a @ case 8
    .4byte lbl_0800f56a @ case 9
    .4byte lbl_0800f568 @ case 10
lbl_0800f4e4:
    ldr r1, lbl_0800f4f8 @ =0x0000ffc0
    ands r1, r5
    movs r0, #0x3f
    ands r0, r4
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    movs r3, #5
    b lbl_0800f56e
    .align 2, 0
lbl_0800f4f8: .4byte 0x0000ffc0
lbl_0800f4fc:
    ldr r1, lbl_0800f50c @ =0x0000ffc0
    ands r1, r5
    movs r0, #0x3f
    ands r0, r4
    lsrs r0, r0, #1
    subs r0, #0x3f
    b lbl_0800f51c
    .align 2, 0
lbl_0800f50c: .4byte 0x0000ffc0
lbl_0800f510:
    ldr r1, lbl_0800f528 @ =0x0000ffc0
    ands r1, r5
    movs r0, #0x3f
    ands r0, r4
    lsrs r0, r0, #1
    subs r0, #0x1f
lbl_0800f51c:
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    movs r3, #3
    b lbl_0800f56e
    .align 2, 0
lbl_0800f528: .4byte 0x0000ffc0
lbl_0800f52c:
    ldr r2, lbl_0800f53c @ =0x0000ffc0
    ands r2, r5
    movs r0, #0x3f
    ands r0, r4
    orrs r2, r0
    movs r3, #4
    b lbl_0800f56e
    .align 2, 0
lbl_0800f53c: .4byte 0x0000ffc0
lbl_0800f540:
    ldr r2, lbl_0800f550 @ =0x0000ffc0
    ands r2, r5
    movs r0, #0x3f
    ands r0, r4
    lsrs r0, r0, #1
    adds r0, #0x1f
    b lbl_0800f55e
    .align 2, 0
lbl_0800f550: .4byte 0x0000ffc0
lbl_0800f554:
    ldr r2, lbl_0800f564 @ =0x0000ffc0
    ands r2, r5
    movs r0, #0x3f
    ands r0, r4
    lsrs r0, r0, #1
lbl_0800f55e:
    orrs r2, r0
    movs r3, #2
    b lbl_0800f56e
    .align 2, 0
lbl_0800f564: .4byte 0x0000ffc0
lbl_0800f568:
    movs r3, #0x10
lbl_0800f56a:
    ldr r2, lbl_0800f578 @ =0x0000ffc0
    ands r2, r5
lbl_0800f56e:
    cmp r5, r2
    blo lbl_0800f580
    ldr r0, lbl_0800f57c @ =0x030007f0
    strb r3, [r0]
    b lbl_0800f586
    .align 2, 0
lbl_0800f578: .4byte 0x0000ffc0
lbl_0800f57c: .4byte 0x030007f0
lbl_0800f580:
    ldr r1, lbl_0800f590 @ =0x030007f0
    movs r0, #0
    strb r0, [r1]
lbl_0800f586:
    adds r0, r2, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800f590: .4byte 0x030007f0

    thumb_func_start sub_0800f594
sub_0800f594: @ 0x0800f594
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r7, lbl_0800f600 @ =0x03000738
    ldrh r5, [r7, #2]
    mov sb, r5
    ldrh r4, [r7, #4]
    mov sl, r4
    subs r0, r5, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r4, #0
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldr r6, lbl_0800f604 @ =0x030007f0
    ldrb r1, [r6]
    movs r0, #0xf
    mov r8, r0
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f5ee
    adds r0, r5, #0
    adds r1, r4, #0
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldrb r1, [r6]
    mov r0, r8
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f5ee
    mov r0, sb
    adds r0, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r1, sl
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0800f5f0
lbl_0800f5ee:
    strh r2, [r7, #2]
lbl_0800f5f0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f600: .4byte 0x03000738
lbl_0800f604: .4byte 0x030007f0

    thumb_func_start sub_0800f608
sub_0800f608: @ 0x0800f608
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r6, lbl_0800f680 @ =0x03000738
    ldrh r0, [r6, #0xc]
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    mov sb, r5
    ldrh r4, [r6, #4]
    mov sl, r4
    subs r0, r5, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r4, #0
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldr r7, lbl_0800f684 @ =0x030007f0
    ldrb r1, [r7]
    movs r0, #0xf
    mov r8, r0
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f66a
    adds r0, r5, #0
    adds r1, r4, #0
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldrb r1, [r7]
    mov r0, r8
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f66a
    mov r0, sb
    adds r0, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r1, sl
    bl check_vertical_collision_at_pos
    adds r2, r0, #0
    ldrb r0, [r7]
    cmp r0, #0
    beq lbl_0800f670
lbl_0800f66a:
    ldrh r0, [r6, #0xc]
    subs r0, r2, r0
    strh r0, [r6, #2]
lbl_0800f670:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f680: .4byte 0x03000738
lbl_0800f684: .4byte 0x030007f0

    thumb_func_start check_collision_at_pos
check_collision_at_pos: @ 0x0800f688
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl sub_08057e7c
    adds r3, r0, #0
    movs r2, #0x80
    lsls r2, r2, #0x11
    ands r2, r3
    cmp r2, #0
    beq lbl_0800f6b0
    ldr r1, lbl_0800f6ac @ =0x030007f1
    movs r0, #0x11
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_0800f6b6
    .align 2, 0
lbl_0800f6ac: .4byte 0x030007f1
lbl_0800f6b0:
    ldr r0, lbl_0800f6cc @ =0x030007f1
    strb r2, [r0]
    adds r2, r0, #0
lbl_0800f6b6:
    movs r0, #0xff
    ands r0, r3
    subs r0, #2
    cmp r0, #0xa
    bhi lbl_0800f71c
    lsls r0, r0, #2
    ldr r1, lbl_0800f6d0 @ =lbl_0800f6d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800f6cc: .4byte 0x030007f1
lbl_0800f6d0: .4byte lbl_0800f6d4
lbl_0800f6d4: @ jump table
    .4byte lbl_0800f70c @ case 0
    .4byte lbl_0800f700 @ case 1
    .4byte lbl_0800f714 @ case 2
    .4byte lbl_0800f710 @ case 3
    .4byte lbl_0800f704 @ case 4
    .4byte lbl_0800f708 @ case 5
    .4byte lbl_0800f71c @ case 6
    .4byte lbl_0800f71c @ case 7
    .4byte lbl_0800f71c @ case 8
    .4byte lbl_0800f71c @ case 9
    .4byte lbl_0800f718 @ case 10
lbl_0800f700:
    movs r0, #5
    b lbl_0800f71a
lbl_0800f704:
    movs r0, #3
    b lbl_0800f71a
lbl_0800f708:
    movs r0, #3
    b lbl_0800f71a
lbl_0800f70c:
    movs r0, #4
    b lbl_0800f71a
lbl_0800f710:
    movs r0, #2
    b lbl_0800f71a
lbl_0800f714:
    movs r0, #2
    b lbl_0800f71a
lbl_0800f718:
    movs r0, #0x10
lbl_0800f71a:
    strb r0, [r2]
lbl_0800f71c:
    pop {r0}
    bx r0

    thumb_func_start check_collision_at_pos_noglobal
check_collision_at_pos_noglobal: @ 0x0800f720
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl sub_08057e7c
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    movs r2, #0
    cmp r0, #0
    beq lbl_0800f73e
    movs r2, #0x11
lbl_0800f73e:
    movs r0, #0xff
    ands r0, r1
    subs r0, #2
    cmp r0, #0xa
    bhi lbl_0800f796
    lsls r0, r0, #2
    ldr r1, lbl_0800f754 @ =lbl_0800f758
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0800f754: .4byte lbl_0800f758
lbl_0800f758: @ jump table
    .4byte lbl_0800f78c @ case 0
    .4byte lbl_0800f784 @ case 1
    .4byte lbl_0800f790 @ case 2
    .4byte lbl_0800f790 @ case 3
    .4byte lbl_0800f788 @ case 4
    .4byte lbl_0800f788 @ case 5
    .4byte lbl_0800f796 @ case 6
    .4byte lbl_0800f796 @ case 7
    .4byte lbl_0800f796 @ case 8
    .4byte lbl_0800f796 @ case 9
    .4byte lbl_0800f794 @ case 10
lbl_0800f784:
    movs r2, #5
    b lbl_0800f796
lbl_0800f788:
    movs r2, #3
    b lbl_0800f796
lbl_0800f78c:
    movs r2, #4
    b lbl_0800f796
lbl_0800f790:
    movs r2, #2
    b lbl_0800f796
lbl_0800f794:
    movs r2, #0x10
lbl_0800f796:
    adds r0, r2, #0
    pop {r1}
    bx r1

    thumb_func_start current_sprite_falling_unused
current_sprite_falling_unused: @ 0x0800f79c
    push {r4, r5, lr}
    ldr r4, lbl_0800f7c0 @ =0x03000738
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl check_vertical_collision_at_pos_slopes
    adds r1, r0, #0
    ldr r0, lbl_0800f7c4 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0800f7c8
    strh r1, [r4, #2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0800f804
    .align 2, 0
lbl_0800f7c0: .4byte 0x03000738
lbl_0800f7c4: .4byte 0x030007f0
lbl_0800f7c8:
    movs r0, #0x2f
    adds r0, r0, r4
    mov ip, r0
    ldrb r1, [r0]
    ldr r3, lbl_0800f7f0 @ =0x082b0d04
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r2, [r0, r5]
    ldr r0, lbl_0800f7f4 @ =0x00007fff
    cmp r2, r0
    bne lbl_0800f7f8
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r5, [r4, #2]
    adds r0, r0, r5
    b lbl_0800f802
    .align 2, 0
lbl_0800f7f0: .4byte 0x082b0d04
lbl_0800f7f4: .4byte 0x00007fff
lbl_0800f7f8:
    adds r0, r1, #1
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_0800f802:
    strh r0, [r4, #2]
lbl_0800f804:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start current_sprite_choose_rand_xflip
current_sprite_choose_rand_xflip: @ 0x0800f80c
    push {lr}
    ldr r0, lbl_0800f824 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f830
    ldr r2, lbl_0800f828 @ =0x03000738
    ldrh r1, [r2]
    ldr r0, lbl_0800f82c @ =0x0000ffbf
    ands r0, r1
    b lbl_0800f838
    .align 2, 0
lbl_0800f824: .4byte 0x0300083c
lbl_0800f828: .4byte 0x03000738
lbl_0800f82c: .4byte 0x0000ffbf
lbl_0800f830:
    ldr r2, lbl_0800f840 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
lbl_0800f838:
    strh r0, [r2]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f840: .4byte 0x03000738

    thumb_func_start current_sprite_choose_rand_xdirection
current_sprite_choose_rand_xdirection: @ 0x0800f844
    push {lr}
    ldr r0, lbl_0800f85c @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f868
    ldr r2, lbl_0800f860 @ =0x03000738
    ldrh r1, [r2]
    ldr r0, lbl_0800f864 @ =0x0000fdff
    ands r0, r1
    b lbl_0800f874
    .align 2, 0
lbl_0800f85c: .4byte 0x0300083c
lbl_0800f860: .4byte 0x03000738
lbl_0800f864: .4byte 0x0000fdff
lbl_0800f868:
    ldr r2, lbl_0800f87c @ =0x03000738
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r1
lbl_0800f874:
    strh r0, [r2]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f87c: .4byte 0x03000738

    thumb_func_start current_sprite_choose_rand_xdirection_with_room_slot
current_sprite_choose_rand_xdirection_with_room_slot: @ 0x0800f880
    push {lr}
    ldr r2, lbl_0800f898 @ =0x03000738
    ldrb r1, [r2, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f8a0
    ldrh r1, [r2]
    ldr r0, lbl_0800f89c @ =0x0000fdff
    ands r0, r1
    b lbl_0800f8aa
    .align 2, 0
lbl_0800f898: .4byte 0x03000738
lbl_0800f89c: .4byte 0x0000fdff
lbl_0800f8a0:
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r1
lbl_0800f8aa:
    strh r0, [r2]
    pop {r0}
    bx r0

    thumb_func_start current_sprite_face_samus_xflip
current_sprite_face_samus_xflip: @ 0x0800f8b0
    push {lr}
    ldr r2, lbl_0800f8c8 @ =0x03000738
    ldr r1, lbl_0800f8cc @ =0x030013d4
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f8d4
    ldrh r1, [r2]
    ldr r0, lbl_0800f8d0 @ =0x0000ffbf
    ands r0, r1
    b lbl_0800f8da
    .align 2, 0
lbl_0800f8c8: .4byte 0x03000738
lbl_0800f8cc: .4byte 0x030013d4
lbl_0800f8d0: .4byte 0x0000ffbf
lbl_0800f8d4:
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
lbl_0800f8da:
    strh r0, [r2]
    pop {r0}
    bx r0

    thumb_func_start current_sprite_face_samus_direction
current_sprite_face_samus_direction: @ 0x0800f8e0
    push {lr}
    ldr r2, lbl_0800f8f8 @ =0x03000738
    ldr r1, lbl_0800f8fc @ =0x030013d4
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f904
    ldrh r1, [r2]
    ldr r0, lbl_0800f900 @ =0x0000fdff
    ands r0, r1
    b lbl_0800f90e
    .align 2, 0
lbl_0800f8f8: .4byte 0x03000738
lbl_0800f8fc: .4byte 0x030013d4
lbl_0800f900: .4byte 0x0000fdff
lbl_0800f904:
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r1
lbl_0800f90e:
    strh r0, [r2]
    pop {r0}
    bx r0

    thumb_func_start current_sprite_face_away_from_samus_xflip
current_sprite_face_away_from_samus_xflip: @ 0x0800f914
    push {lr}
    ldr r2, lbl_0800f92c @ =0x03000738
    ldr r1, lbl_0800f930 @ =0x030013d4
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f934
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    b lbl_0800f93a
    .align 2, 0
lbl_0800f92c: .4byte 0x03000738
lbl_0800f930: .4byte 0x030013d4
lbl_0800f934:
    ldrh r1, [r2]
    ldr r0, lbl_0800f940 @ =0x0000ffbf
    ands r0, r1
lbl_0800f93a:
    strh r0, [r2]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f940: .4byte 0x0000ffbf

    thumb_func_start current_sprite_face_away_from_samus_direction
current_sprite_face_away_from_samus_direction: @ 0x0800f944
    push {lr}
    ldr r2, lbl_0800f960 @ =0x03000738
    ldr r1, lbl_0800f964 @ =0x030013d4
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f968
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r1
    b lbl_0800f96e
    .align 2, 0
lbl_0800f960: .4byte 0x03000738
lbl_0800f964: .4byte 0x030013d4
lbl_0800f968:
    ldrh r1, [r2]
    ldr r0, lbl_0800f974 @ =0x0000fdff
    ands r0, r1
lbl_0800f96e:
    strh r0, [r2]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f974: .4byte 0x0000fdff

    thumb_func_start sub_0800f978
sub_0800f978: @ 0x0800f978
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    ldr r4, lbl_0800f9a0 @ =0x03000738
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl check_collision_at_pos
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f9a8
    ldr r0, lbl_0800f9a4 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0800f9bc
    b lbl_0800f9b0
    .align 2, 0
lbl_0800f9a0: .4byte 0x03000738
lbl_0800f9a4: .4byte 0x030007f1
lbl_0800f9a8:
    ldr r0, lbl_0800f9d0 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0800f9bc
lbl_0800f9b0:
    lsls r0, r5, #1
    movs r1, #3
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
lbl_0800f9bc:
    ldr r2, lbl_0800f9d4 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f9d8
    ldrh r0, [r2, #4]
    adds r0, r0, r5
    b lbl_0800f9dc
    .align 2, 0
lbl_0800f9d0: .4byte 0x030007f1
lbl_0800f9d4: .4byte 0x03000738
lbl_0800f9d8:
    ldrh r0, [r2, #4]
    subs r0, r0, r5
lbl_0800f9dc:
    strh r0, [r2, #4]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0800f9e4
sub_0800f9e4: @ 0x0800f9e4
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    ldr r4, lbl_0800fa14 @ =0x03000738
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl check_collision_at_pos
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800fa22
    ldr r0, lbl_0800fa18 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0800fa1c
    lsls r0, r5, #1
    movs r1, #3
    bl __divsi3
    lsls r0, r0, #0x10
    b lbl_0800fa4c
    .align 2, 0
lbl_0800fa14: .4byte 0x03000738
lbl_0800fa18: .4byte 0x030007f1
lbl_0800fa1c:
    cmp r0, #3
    bne lbl_0800fa4e
    b lbl_0800fa40
lbl_0800fa22:
    ldr r0, lbl_0800fa38 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0800fa3c
    lsls r0, r5, #1
    movs r1, #3
    bl __divsi3
    lsls r0, r0, #0x10
    b lbl_0800fa4c
    .align 2, 0
lbl_0800fa38: .4byte 0x030007f1
lbl_0800fa3c:
    cmp r0, #2
    bne lbl_0800fa4e
lbl_0800fa40:
    lsls r0, r5, #1
    adds r0, r0, r5
    cmp r0, #0
    bge lbl_0800fa4a
    adds r0, #3
lbl_0800fa4a:
    lsls r0, r0, #0xe
lbl_0800fa4c:
    asrs r5, r0, #0x10
lbl_0800fa4e:
    cmp r5, #0
    bne lbl_0800fa54
    movs r5, #1
lbl_0800fa54:
    ldr r2, lbl_0800fa68 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800fa6c
    ldrh r0, [r2, #4]
    adds r0, r0, r5
    b lbl_0800fa70
    .align 2, 0
lbl_0800fa68: .4byte 0x03000738
lbl_0800fa6c:
    ldrh r0, [r2, #4]
    subs r0, r0, r5
lbl_0800fa70:
    strh r0, [r2, #4]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start mecha_ridley_misile_rotate
mecha_ridley_misile_rotate: @ 0x0800fa78
    push {r4, r5, r6, lr}
    ldr r4, [sp, #0x10]
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    lsls r1, r1, #0x10
    asrs r6, r1, #0x10
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    lsls r3, r3, #0x10
    asrs r1, r3, #0x10
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    movs r3, #2
    cmp r6, r1
    bge lbl_0800fabe
    adds r0, r4, #0
    subs r0, #0x40
    cmp r0, r2
    bge lbl_0800faa8
    adds r0, #0x80
    cmp r0, r2
    ble lbl_0800faa8
    movs r2, #0xc0
    b lbl_0800fafe
lbl_0800faa8:
    cmp r2, r4
    ble lbl_0800fab2
    subs r0, r1, r6
    movs r2, #0xe0
    b lbl_0800fad8
lbl_0800fab2:
    subs r0, r1, r6
    movs r2, #0xa0
    cmp r0, #0x3f
    bgt lbl_0800fae8
    movs r2, #0x80
    b lbl_0800fafe
lbl_0800fabe:
    adds r0, r4, #0
    subs r0, #0x40
    cmp r0, r2
    bge lbl_0800fad0
    adds r0, #0x80
    cmp r0, r2
    ble lbl_0800fad0
    movs r2, #0x40
    b lbl_0800fafe
lbl_0800fad0:
    cmp r2, r4
    ble lbl_0800fade
    subs r0, r6, r1
    movs r2, #0x20
lbl_0800fad8:
    cmp r0, #0x3f
    bgt lbl_0800fae8
    b lbl_0800faec
lbl_0800fade:
    subs r0, r6, r1
    movs r2, #0x60
    cmp r0, #0x3f
    bgt lbl_0800fae8
    movs r2, #0x80
lbl_0800fae8:
    cmp r2, #0
    bne lbl_0800fafe
lbl_0800faec:
    subs r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_0800fbb6
    cmp r5, #0x7f
    ble lbl_0800fbbc
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fafe:
    cmp r2, #0x20
    bne lbl_0800fb1e
    adds r0, r5, #0
    subs r0, #0x21
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_0800fbb6
    adds r0, r5, #0
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_0800fbbc
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb1e:
    cmp r2, #0x40
    bne lbl_0800fb3e
    adds r0, r5, #0
    subs r0, #0x41
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_0800fbb6
    adds r0, r5, #0
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_0800fbbc
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb3e:
    cmp r2, #0x60
    bne lbl_0800fb5e
    adds r0, r5, #0
    subs r0, #0x61
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_0800fbb6
    adds r0, r5, #0
    subs r0, #0x60
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_0800fbbc
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb5e:
    cmp r2, #0x80
    bne lbl_0800fb76
    subs r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0800fb70
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb70:
    cmp r5, #0x80
    ble lbl_0800fbbc
    b lbl_0800fbb6
lbl_0800fb76:
    cmp r2, #0xa0
    bne lbl_0800fb8a
    adds r0, r5, #0
    subs r0, #0x21
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0800fbb2
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb8a:
    cmp r2, #0xc0
    bne lbl_0800fb9e
    adds r0, r5, #0
    subs r0, #0x41
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0800fbb2
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fb9e:
    cmp r2, #0xe0
    bne lbl_0800fbbc
    adds r0, r5, #0
    subs r0, #0x61
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0800fbb2
    adds r0, r5, r3
    b lbl_0800fbb8
lbl_0800fbb2:
    cmp r0, #0x7f
    bls lbl_0800fbbc
lbl_0800fbb6:
    subs r0, r5, r3
lbl_0800fbb8:
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
lbl_0800fbbc:
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_end_of_current_sprite_anim
check_end_of_current_sprite_anim: @ 0x0800fbc8
    push {lr}
    ldr r0, lbl_0800fbf4 @ =0x03000738
    ldrb r1, [r0, #0x1c]
    ldrh r2, [r0, #0x16]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, [r0, #0x18]
    lsls r0, r2, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fbf8
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fbf8
    movs r0, #1
    b lbl_0800fbfa
    .align 2, 0
lbl_0800fbf4: .4byte 0x03000738
lbl_0800fbf8:
    movs r0, #0
lbl_0800fbfa:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_near_end_of_current_sprite_anim
check_near_end_of_current_sprite_anim: @ 0x0800fc00
    push {lr}
    ldr r0, lbl_0800fc30 @ =0x03000738
    ldrb r1, [r0, #0x1c]
    ldrh r3, [r0, #0x16]
    lsls r1, r1, #0x18
    movs r2, #0x80
    lsls r2, r2, #0x12
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    ldr r2, [r0, #0x18]
    lsls r0, r3, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fc34
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fc34
    movs r0, #1
    b lbl_0800fc36
    .align 2, 0
lbl_0800fc30: .4byte 0x03000738
lbl_0800fc34:
    movs r0, #0
lbl_0800fc36:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_end_of_slotted_sprite_anim
check_end_of_slotted_sprite_anim: @ 0x0800fc3c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r3, lbl_0800fc78 @ =0x030001ac
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r0, r1, r3
    ldrb r2, [r0, #0x1c]
    ldrh r4, [r0, #0x16]
    adds r2, #1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r3, #0x18
    adds r1, r1, r3
    ldr r1, [r1]
    lsls r0, r4, #3
    adds r0, r0, r1
    ldrb r0, [r0, #4]
    cmp r0, r2
    bhs lbl_0800fc7c
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r1
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fc7c
    movs r0, #1
    b lbl_0800fc7e
    .align 2, 0
lbl_0800fc78: .4byte 0x030001ac
lbl_0800fc7c:
    movs r0, #0
lbl_0800fc7e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start check_near_end_of_slotted_sprite_anim
check_near_end_of_slotted_sprite_anim: @ 0x0800fc84
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r3, lbl_0800fcc4 @ =0x030001ac
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r0, r1, r3
    ldrb r2, [r0, #0x1c]
    ldrh r4, [r0, #0x16]
    lsls r2, r2, #0x18
    movs r0, #0x80
    lsls r0, r0, #0x12
    adds r2, r2, r0
    lsrs r2, r2, #0x18
    adds r3, #0x18
    adds r1, r1, r3
    ldr r1, [r1]
    lsls r0, r4, #3
    adds r0, r0, r1
    ldrb r0, [r0, #4]
    cmp r0, r2
    bhs lbl_0800fcc8
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r1
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fcc8
    movs r0, #1
    b lbl_0800fcca
    .align 2, 0
lbl_0800fcc4: .4byte 0x030001ac
lbl_0800fcc8:
    movs r0, #0
lbl_0800fcca:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start check_end_of_subsprite_data1_anim
check_end_of_subsprite_data1_anim: @ 0x0800fcd0
    push {lr}
    ldr r0, lbl_0800fcfc @ =0x0300070c
    ldrb r1, [r0, #0xc]
    ldrh r2, [r0, #4]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, [r0]
    lsls r0, r2, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fd00
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fd00
    movs r0, #1
    b lbl_0800fd02
    .align 2, 0
lbl_0800fcfc: .4byte 0x0300070c
lbl_0800fd00:
    movs r0, #0
lbl_0800fd02:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_near_end_of_subsprite_data1_anim
check_near_end_of_subsprite_data1_anim: @ 0x0800fd08
    push {lr}
    ldr r0, lbl_0800fd38 @ =0x0300070c
    ldrb r1, [r0, #0xc]
    ldrh r3, [r0, #4]
    lsls r1, r1, #0x18
    movs r2, #0x80
    lsls r2, r2, #0x12
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    ldr r2, [r0]
    lsls r0, r3, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fd3c
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fd3c
    movs r0, #1
    b lbl_0800fd3e
    .align 2, 0
lbl_0800fd38: .4byte 0x0300070c
lbl_0800fd3c:
    movs r0, #0
lbl_0800fd3e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0800fd44
sub_0800fd44: @ 0x0800fd44
    push {lr}
    ldr r0, lbl_0800fd70 @ =0x03000720
    ldrb r1, [r0, #0xc]

    non_word_aligned_thumb_func_start check_end_of_subsprite_data2_anim
check_end_of_subsprite_data2_anim: @ 0x0800fd4a
    ldrh r2, [r0, #4]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, [r0]
    lsls r0, r2, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fd74
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fd74
    movs r0, #1
    b lbl_0800fd76
    .align 2, 0
lbl_0800fd70: .4byte 0x03000720
lbl_0800fd74:
    movs r0, #0
lbl_0800fd76:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_end_of_subsprite_anim_ptr
check_end_of_subsprite_anim_ptr: @ 0x0800fd7c
    push {lr}
    ldrb r1, [r0, #0xc]
    ldrh r2, [r0, #4]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, [r0]
    lsls r0, r2, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fda6
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fda6
    movs r0, #1
    b lbl_0800fda8
lbl_0800fda6:
    movs r0, #0
lbl_0800fda8:
    pop {r1}
    bx r1

    thumb_func_start check_near_end_of_subsprite_anim_ptr
check_near_end_of_subsprite_anim_ptr: @ 0x0800fdac
    push {lr}
    ldrb r1, [r0, #0xc]
    ldrh r3, [r0, #4]
    lsls r1, r1, #0x18
    movs r2, #0x80
    lsls r2, r2, #0x12
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    ldr r2, [r0]
    lsls r0, r3, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_0800fdda
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0800fdda
    movs r0, #1
    b lbl_0800fddc
lbl_0800fdda:
    movs r0, #0
lbl_0800fddc:
    pop {r1}
    bx r1

    thumb_func_start check_samus_near_sprite_left_right
check_samus_near_sprite_left_right: @ 0x0800fde0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    movs r6, #0
    ldr r2, lbl_0800fe14 @ =0x030013d4
    ldr r0, lbl_0800fe18 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    ldrh r1, [r2, #0x14]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r4, [r2, #0x12]
    ldr r0, lbl_0800fe1c @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    cmp r1, r3
    bls lbl_0800fe20
    subs r0, r1, r3
    b lbl_0800fe22
    .align 2, 0
lbl_0800fe14: .4byte 0x030013d4
lbl_0800fe18: .4byte 0x03001588
lbl_0800fe1c: .4byte 0x03000738
lbl_0800fe20:
    subs r0, r3, r1
lbl_0800fe22:
    cmp r0, r5
    blt lbl_0800fe2a
    movs r0, #0
    b lbl_0800fe42
lbl_0800fe2a:
    cmp r2, r4
    bls lbl_0800fe38
    subs r0, r2, r4
    cmp r0, r7
    bge lbl_0800fe40
    movs r6, #4
    b lbl_0800fe40
lbl_0800fe38:
    subs r0, r4, r2
    cmp r0, r7
    bge lbl_0800fe40
    movs r6, #8
lbl_0800fe40:
    adds r0, r6, #0
lbl_0800fe42:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_samus_near_sprite_above_below
check_samus_near_sprite_above_below: @ 0x0800fe48
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    movs r5, #0
    ldr r2, lbl_0800fe7c @ =0x030013d4
    ldr r0, lbl_0800fe80 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    ldrh r1, [r2, #0x14]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r1, [r2, #0x12]
    ldr r0, lbl_0800fe84 @ =0x03000738
    ldrh r2, [r0, #2]
    ldrh r0, [r0, #4]
    cmp r0, r1
    bls lbl_0800fe88
    subs r0, r0, r1
    b lbl_0800fe8a
    .align 2, 0
lbl_0800fe7c: .4byte 0x030013d4
lbl_0800fe80: .4byte 0x03001588
lbl_0800fe84: .4byte 0x03000738
lbl_0800fe88:
    subs r0, r1, r0
lbl_0800fe8a:
    cmp r0, r4
    blt lbl_0800fe92
    movs r0, #0
    b lbl_0800feaa
lbl_0800fe92:
    cmp r2, r3
    bls lbl_0800fea0
    subs r0, r2, r3
    cmp r0, r6
    bge lbl_0800fea8
    movs r5, #1
    b lbl_0800fea8
lbl_0800fea0:
    subs r0, r3, r2
    cmp r0, r6
    bge lbl_0800fea8
    movs r5, #2
lbl_0800fea8:
    adds r0, r5, #0
lbl_0800feaa:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start check_samus_near_sprite_front_behind_x
check_samus_near_sprite_front_behind_x: @ 0x0800feb0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov r8, r2
    movs r0, #0
    mov ip, r0
    movs r6, #0
    ldr r2, lbl_0800fef8 @ =0x030013d4
    ldr r0, lbl_0800fefc @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    ldrh r1, [r2, #0x14]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r5, [r2, #0x12]
    ldr r0, lbl_0800ff00 @ =0x03000738
    ldrh r2, [r0, #2]
    ldrh r4, [r0, #4]
    adds r1, r0, #0
    cmp r2, r3
    bls lbl_0800ff04
    subs r0, r2, r3
    b lbl_0800ff06
    .align 2, 0
lbl_0800fef8: .4byte 0x030013d4
lbl_0800fefc: .4byte 0x03001588
lbl_0800ff00: .4byte 0x03000738
lbl_0800ff04:
    subs r0, r3, r2
lbl_0800ff06:
    cmp r0, r7
    blt lbl_0800ff0e
    movs r0, #0
    b lbl_0800ff54
lbl_0800ff0e:
    ldrh r1, [r1]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800ff1a
    movs r6, #1
lbl_0800ff1a:
    cmp r4, r5
    bls lbl_0800ff38
    cmp r6, #0
    beq lbl_0800ff2e
    subs r0, r4, r5
    cmp r0, r8
    bge lbl_0800ff52
    movs r0, #0xc
    mov ip, r0
    b lbl_0800ff52
lbl_0800ff2e:
    subs r0, r4, r5
    cmp r0, sb
    bge lbl_0800ff52
    movs r1, #3
    b lbl_0800ff50
lbl_0800ff38:
    cmp r6, #0
    beq lbl_0800ff48
    subs r0, r5, r4
    cmp r0, sb
    bge lbl_0800ff52
    movs r0, #3
    mov ip, r0
    b lbl_0800ff52
lbl_0800ff48:
    subs r0, r5, r4
    cmp r0, r8
    bge lbl_0800ff52
    movs r1, #0xc
lbl_0800ff50:
    mov ip, r1
lbl_0800ff52:
    mov r0, ip
lbl_0800ff54:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start samus_standing_on_sprite
samus_standing_on_sprite: @ 0x0800ff60
    push {r4, r5, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_0800ff9c
    ldr r5, lbl_0800ff94 @ =0x030013d4
    ldrb r0, [r5, #1]
    cmp r0, #1
    beq lbl_0800ff8a
    cmp r0, #2
    bne lbl_0800ff86
    movs r0, #0xfd
    bl samus_set_pose
lbl_0800ff86:
    movs r0, #1
    strb r0, [r5, #1]
lbl_0800ff8a:
    ldrh r1, [r4]
    ldr r0, lbl_0800ff98 @ =0x0000efff
    ands r0, r1
    strh r0, [r4]
    b lbl_0800ffde
    .align 2, 0
lbl_0800ff94: .4byte 0x030013d4
lbl_0800ff98: .4byte 0x0000efff
lbl_0800ff9c:
    adds r1, r4, #0
    adds r1, #0x31
    ldrb r2, [r1]
    cmp r2, #1
    beq lbl_0800ffd0
    cmp r2, #2
    bne lbl_0800ffde
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0800ffc8 @ =0x030013f4
    ldr r1, lbl_0800ffcc @ =0x030013d4
    ldrh r0, [r0, #0x14]
    ldrh r2, [r1, #0x14]
    cmp r0, r2
    bhi lbl_0800ffde
    ldrh r0, [r4, #0xa]
    ldrh r4, [r4, #2]
    adds r0, r0, r4
    adds r0, #1
    strh r0, [r1, #0x14]
    b lbl_0800ffde
    .align 2, 0
lbl_0800ffc8: .4byte 0x030013f4
lbl_0800ffcc: .4byte 0x030013d4
lbl_0800ffd0:
    strb r0, [r1]
    ldr r1, lbl_0800ffe4 @ =0x030013d4
    ldrb r0, [r1, #1]
    cmp r0, #1
    bne lbl_0800ffde
    movs r0, #2
    strb r0, [r1, #1]
lbl_0800ffde:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800ffe4: .4byte 0x030013d4

    thumb_func_start update_freeze_timer
update_freeze_timer: @ 0x0800ffe8
    push {r4, lr}
    ldr r0, lbl_08010034 @ =0x03000c77
    ldrb r1, [r0]
    movs r4, #1
    adds r0, r4, #0
    ands r0, r1
    ldr r3, lbl_08010038 @ =0x03000738
    cmp r0, #0
    beq lbl_08010004
    adds r1, r3, #0
    adds r1, #0x30
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
lbl_08010004:
    adds r2, r3, #0
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_08010016
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
lbl_08010016:
    cmp r1, #0x2d
    bhi lbl_08010046
    ands r1, r4
    cmp r1, #0
    beq lbl_0801003c
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    b lbl_08010044
    .align 2, 0
lbl_08010034: .4byte 0x03000c77
lbl_08010038: .4byte 0x03000738
lbl_0801003c:
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
lbl_08010044:
    strb r1, [r0]
lbl_08010046:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start unfreeze_anim_easy
unfreeze_anim_easy: @ 0x0801004c
    push {lr}
    ldr r2, lbl_08010090 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r1, [r0]
    subs r1, #1
    strb r1, [r0]
    ldrb r0, [r0]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08010068
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
lbl_08010068:
    cmp r1, #0x5a
    bhi lbl_0801009e
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0801009e
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08010094
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    b lbl_0801009c
    .align 2, 0
lbl_08010090: .4byte 0x03000738
lbl_08010094:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
lbl_0801009c:
    strb r1, [r0]
lbl_0801009e:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start metroid_unfreeze_anim
metroid_unfreeze_anim: @ 0x080100a4
    push {lr}
    ldr r2, lbl_080100e8 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r1, [r0]
    subs r1, #2
    strb r1, [r0]
    ldrb r0, [r0]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_080100c0
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
lbl_080100c0:
    cmp r1, #0x78
    bhi lbl_080100f6
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_080100f6
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080100ec
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    b lbl_080100f4
    .align 2, 0
lbl_080100e8: .4byte 0x03000738
lbl_080100ec:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
lbl_080100f4:
    strb r1, [r0]
lbl_080100f6:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start update_secondary_sprite_freeze_timer
update_secondary_sprite_freeze_timer: @ 0x080100fc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    ldr r0, lbl_08010190 @ =0x03000738
    adds r1, r0, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08010186
    movs r5, #0
    ldr r0, lbl_08010194 @ =0x030001ac
    mov r8, r0
    mov ip, r1
lbl_0801011e:
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    mov r1, r8
    adds r2, r0, r1
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0801017c
    adds r0, r2, #0
    adds r0, #0x32
    ldrb r4, [r0]
    movs r0, #0x80
    ands r0, r4
    cmp r0, #0
    beq lbl_0801017c
    ldrb r0, [r2, #0x1d]
    cmp r0, r7
    bne lbl_0801017c
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    cmp r0, r6
    bne lbl_0801017c
    adds r3, r2, #0
    adds r3, #0x30
    mov r0, ip
    ldrb r1, [r0]
    ldrb r0, [r3]
    cmp r0, r1
    bhs lbl_0801017c
    movs r0, #0x10
    ands r0, r4
    cmp r0, #0
    bne lbl_0801017c
    strb r1, [r3]
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    strb r1, [r0]
lbl_0801017c:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0x17
    bls lbl_0801011e
lbl_08010186:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08010190: .4byte 0x03000738
lbl_08010194: .4byte 0x030001ac

    thumb_func_start update_primary_sprite_freeze_timer
update_primary_sprite_freeze_timer: @ 0x08010198
    push {r4, r5, lr}
    ldr r1, lbl_080101ec @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x30
    ldrb r5, [r0]
    adds r3, r5, #0
    cmp r3, #0
    beq lbl_080101e4
    subs r0, #0xd
    ldrb r1, [r0]
    ldr r2, lbl_080101f0 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r2, r0, r2
    adds r4, r2, #0
    adds r4, #0x30
    ldrb r0, [r4]
    cmp r0, r3
    bhs lbl_080101e4
    adds r0, r2, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_080101e4
    strb r5, [r4]
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    strb r1, [r0]
lbl_080101e4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080101ec: .4byte 0x03000738
lbl_080101f0: .4byte 0x030001ac

    thumb_func_start sub_080101f4
sub_080101f4: @ 0x080101f4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r3, #0
    ldr r7, lbl_08010258 @ =0x030001ac
    movs r4, #0
lbl_08010204:
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r2, r0, r7
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010246
    adds r0, r2, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08010246
    ldrb r0, [r2, #0x1d]
    cmp r0, r6
    bne lbl_08010246
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    cmp r0, r5
    bne lbl_08010246
    adds r1, r2, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08010246
    strb r4, [r1]
    adds r0, r2, #0
    adds r0, #0x20
    strb r4, [r0]
lbl_08010246:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0x17
    bls lbl_08010204
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08010258: .4byte 0x030001ac

    thumb_func_start refill_energy
refill_energy: @ 0x0801025c
    push {lr}
    ldr r0, lbl_08010278 @ =0x03001530
    ldrh r1, [r0, #6]
    ldrh r2, [r0]
    adds r3, r0, #0
    cmp r1, r2
    bhs lbl_08010298
    subs r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x15
    cmp r1, #0
    bne lbl_0801027c
    movs r1, #1
    b lbl_08010282
    .align 2, 0
lbl_08010278: .4byte 0x03001530
lbl_0801027c:
    cmp r1, #0xa
    bls lbl_08010282
    movs r1, #0xb
lbl_08010282:
    ldrh r0, [r3, #6]
    adds r0, r1, r0
    strh r0, [r3, #6]
    ldrh r1, [r3]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_08010294
    strh r1, [r3, #6]
lbl_08010294:
    movs r0, #1
    b lbl_0801029a
lbl_08010298:
    movs r0, #0
lbl_0801029a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start refill_missiles
refill_missiles: @ 0x080102a0
    push {lr}
    ldr r0, lbl_080102bc @ =0x03001530
    ldrh r1, [r0, #8]
    ldrh r2, [r0, #2]
    adds r3, r0, #0
    cmp r1, r2
    bhs lbl_080102dc
    subs r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x15
    cmp r1, #0
    bne lbl_080102c0
    movs r1, #1
    b lbl_080102c6
    .align 2, 0
lbl_080102bc: .4byte 0x03001530
lbl_080102c0:
    cmp r1, #5
    bls lbl_080102c6
    movs r1, #6
lbl_080102c6:
    ldrh r0, [r3, #8]
    adds r0, r1, r0
    strh r0, [r3, #8]
    ldrh r1, [r3, #2]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_080102d8
    strh r1, [r3, #8]
lbl_080102d8:
    movs r0, #1
    b lbl_080102de
lbl_080102dc:
    movs r0, #0
lbl_080102de:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080102e4
sub_080102e4: @ 0x080102e4
    push {lr}
    ldr r0, lbl_08010300 @ =0x03001530
    ldrb r1, [r0, #0xa]

    non_word_aligned_thumb_func_start refill_super_missiles
refill_super_missiles: @ 0x080102ea
    ldrb r2, [r0, #4]
    adds r3, r0, #0
    cmp r1, r2
    bhs lbl_08010320
    subs r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x14
    cmp r1, #0
    bne lbl_08010304
    movs r1, #1
    b lbl_0801030a
    .align 2, 0
lbl_08010300: .4byte 0x03001530
lbl_08010304:
    cmp r1, #3
    bls lbl_0801030a
    movs r1, #4
lbl_0801030a:
    ldrb r0, [r3, #0xa]
    adds r0, r0, r1
    strb r0, [r3, #0xa]
    ldrb r1, [r3, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, r1
    bls lbl_0801031c
    strb r1, [r3, #0xa]
lbl_0801031c:
    movs r0, #1
    b lbl_08010322
lbl_08010320:
    movs r0, #0
lbl_08010322:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start refill_powerbombs
refill_powerbombs: @ 0x08010328
    push {lr}
    ldr r0, lbl_08010344 @ =0x03001530
    ldrb r1, [r0, #0xb]
    ldrb r2, [r0, #5]
    adds r3, r0, #0
    cmp r1, r2
    bhs lbl_08010364
    subs r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x14
    cmp r1, #0
    bne lbl_08010348
    movs r1, #1
    b lbl_0801034e
    .align 2, 0
lbl_08010344: .4byte 0x03001530
lbl_08010348:
    cmp r1, #3
    bls lbl_0801034e
    movs r1, #4
lbl_0801034e:
    ldrb r0, [r3, #0xb]
    adds r0, r0, r1
    strb r0, [r3, #0xb]
    ldrb r1, [r3, #5]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, r1
    bls lbl_08010360
    strb r1, [r3, #0xb]
lbl_08010360:
    movs r0, #1
    b lbl_08010366
lbl_08010364:
    movs r0, #0
lbl_08010366:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start is_crouching_or_morphed
is_crouching_or_morphed: @ 0x0801036c
    push {lr}
    ldr r0, lbl_08010384 @ =0x030013d4
    ldrb r0, [r0]
    subs r0, #4
    cmp r0, #0x38
    bls lbl_0801037a
    b lbl_08010474
lbl_0801037a:
    lsls r0, r0, #2
    ldr r1, lbl_08010388 @ =lbl_0801038c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08010384: .4byte 0x030013d4
lbl_08010388: .4byte lbl_0801038c
lbl_0801038c: @ jump table
    .4byte lbl_08010470 @ case 0
    .4byte lbl_08010470 @ case 1
    .4byte lbl_08010470 @ case 2
    .4byte lbl_08010474 @ case 3
    .4byte lbl_08010474 @ case 4
    .4byte lbl_08010474 @ case 5
    .4byte lbl_08010474 @ case 6
    .4byte lbl_08010474 @ case 7
    .4byte lbl_08010474 @ case 8
    .4byte lbl_08010474 @ case 9
    .4byte lbl_08010474 @ case 10
    .4byte lbl_08010474 @ case 11
    .4byte lbl_08010470 @ case 12
    .4byte lbl_08010470 @ case 13
    .4byte lbl_08010470 @ case 14
    .4byte lbl_08010470 @ case 15
    .4byte lbl_08010470 @ case 16
    .4byte lbl_08010474 @ case 17
    .4byte lbl_08010474 @ case 18
    .4byte lbl_08010474 @ case 19
    .4byte lbl_08010474 @ case 20
    .4byte lbl_08010474 @ case 21
    .4byte lbl_08010474 @ case 22
    .4byte lbl_08010474 @ case 23
    .4byte lbl_08010474 @ case 24
    .4byte lbl_08010474 @ case 25
    .4byte lbl_08010474 @ case 26
    .4byte lbl_08010474 @ case 27
    .4byte lbl_08010474 @ case 28
    .4byte lbl_08010474 @ case 29
    .4byte lbl_08010474 @ case 30
    .4byte lbl_08010474 @ case 31
    .4byte lbl_08010474 @ case 32
    .4byte lbl_08010474 @ case 33
    .4byte lbl_08010474 @ case 34
    .4byte lbl_08010474 @ case 35
    .4byte lbl_08010474 @ case 36
    .4byte lbl_08010474 @ case 37
    .4byte lbl_08010474 @ case 38
    .4byte lbl_08010474 @ case 39
    .4byte lbl_08010474 @ case 40
    .4byte lbl_08010474 @ case 41
    .4byte lbl_08010474 @ case 42
    .4byte lbl_08010474 @ case 43
    .4byte lbl_08010474 @ case 44
    .4byte lbl_08010470 @ case 45
    .4byte lbl_08010474 @ case 46
    .4byte lbl_08010474 @ case 47
    .4byte lbl_08010470 @ case 48
    .4byte lbl_08010470 @ case 49
    .4byte lbl_08010470 @ case 50
    .4byte lbl_08010470 @ case 51
    .4byte lbl_08010470 @ case 52
    .4byte lbl_08010470 @ case 53
    .4byte lbl_08010470 @ case 54
    .4byte lbl_08010474 @ case 55
    .4byte lbl_08010470 @ case 56
lbl_08010470:
    movs r0, #1
    b lbl_08010476
lbl_08010474:
    movs r0, #0
lbl_08010476:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start is_crouching_or_crawling
is_crouching_or_crawling: @ 0x0801047c
    push {lr}
    ldr r0, lbl_08010494 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x3a
    bgt lbl_08010498
    cmp r0, #0x34
    bge lbl_0801049c
    cmp r0, #6
    bgt lbl_080104a0
    cmp r0, #4
    blt lbl_080104a0
    b lbl_0801049c
    .align 2, 0
lbl_08010494: .4byte 0x030013d4
lbl_08010498:
    cmp r0, #0x3c
    bne lbl_080104a0
lbl_0801049c:
    movs r0, #1
    b lbl_080104a2
lbl_080104a0:
    movs r0, #0
lbl_080104a2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start is_morphed
is_morphed: @ 0x080104a8
    push {lr}
    ldr r0, lbl_080104c0 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x10
    blt lbl_080104c4
    cmp r0, #0x14
    ble lbl_080104ba
    cmp r0, #0x31
    bne lbl_080104c4
lbl_080104ba:
    movs r0, #1
    b lbl_080104c6
    .align 2, 0
lbl_080104c0: .4byte 0x030013d4
lbl_080104c4:
    movs r0, #0
lbl_080104c6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_stop_sprites_pose
check_stop_sprites_pose: @ 0x080104cc
    push {lr}
    ldr r0, lbl_080104e8 @ =0x03001606
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_080104e2
    ldr r0, lbl_080104ec @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x1e
    bgt lbl_080104f0
    cmp r0, #0x1d
    blt lbl_080104f0
lbl_080104e2:
    movs r0, #1
    b lbl_080104f2
    .align 2, 0
lbl_080104e8: .4byte 0x03001606
lbl_080104ec: .4byte 0x030013d4
lbl_080104f0:
    movs r0, #0
lbl_080104f2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sprite_take_damage_from_samus_contact
sprite_take_damage_from_samus_contact: @ 0x080104f8
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    movs r5, #0
    ldr r0, lbl_0801053c @ =0x03001530
    ldrb r1, [r0, #0x12]
    adds r7, r0, #0
    cmp r1, #2
    beq lbl_08010564
    adds r2, r4, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x48
    ands r0, r1
    adds r6, r2, #0
    cmp r0, #0
    bne lbl_08010564
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    bne lbl_08010564
    ldrb r0, [r3, #5]
    cmp r0, #0
    beq lbl_08010544
    ldrb r0, [r3]
    cmp r0, #0x22
    beq lbl_08010536
    cmp r0, #0x26
    bne lbl_08010540
lbl_08010536:
    movs r5, #1
    b lbl_0801056c
    .align 2, 0
lbl_0801053c: .4byte 0x03001530
lbl_08010540:
    movs r5, #2
    b lbl_0801056c
lbl_08010544:
    ldrb r0, [r3]
    cmp r0, #0xb
    blt lbl_08010560
    cmp r0, #0xe
    ble lbl_08010556
    cmp r0, #0xf
    bne lbl_08010560
    movs r5, #3
    b lbl_0801056c
lbl_08010556:
    ldr r0, lbl_08010568 @ =0x03001414
    ldrb r0, [r0, #5]
    cmp r0, #0x3f
    bls lbl_08010560
    movs r5, #4
lbl_08010560:
    cmp r5, #0
    bne lbl_0801056c
lbl_08010564:
    movs r0, #0
    b lbl_080106a0
    .align 2, 0
lbl_08010568: .4byte 0x03001414
lbl_0801056c:
    ldrb r1, [r6]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08010580
    ldr r2, lbl_0801057c @ =0x082b1be4
    b lbl_08010582
    .align 2, 0
lbl_0801057c: .4byte 0x082b1be4
lbl_08010580:
    ldr r2, lbl_080105fc @ =0x082b0d68
lbl_08010582:
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r2, #4
    adds r0, r0, r2
    ldrh r1, [r0]
    cmp r5, #3
    bls lbl_0801060c
    movs r0, #3
    ands r1, r0
    cmp r1, #0
    bne lbl_0801059e
    b lbl_0801069c
lbl_0801059e:
    ldr r1, lbl_08010600 @ =0x03001414
    movs r0, #0
    strb r0, [r1, #5]
    movs r1, #2
    ldrb r2, [r7, #0xd]
    adds r3, r2, #0
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    beq lbl_080105b4
    movs r1, #3
lbl_080105b4:
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_080105c2
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
lbl_080105c2:
    movs r0, #4
    ands r2, r0
    cmp r2, #0
    beq lbl_080105d0
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
lbl_080105d0:
    movs r0, #8
    ands r3, r0
    cmp r3, #0
    beq lbl_080105de
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
lbl_080105de:
    lsls r0, r1, #0x12
    lsrs r1, r0, #0x10
    adds r0, r4, #0
    bl projectile_deal_damage
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08010604
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x66
    strb r0, [r1]
    b lbl_0801069e
    .align 2, 0
lbl_080105fc: .4byte 0x082b0d68
lbl_08010600: .4byte 0x03001414
lbl_08010604:
    adds r0, r4, #0
    adds r0, #0x26
    strb r1, [r0]
    b lbl_0801069c
lbl_0801060c:
    movs r0, #0x20
    ands r1, r0
    cmp r1, #0
    beq lbl_08010684
    movs r2, #0
    movs r0, #0
    strh r0, [r4, #0x14]
    ldrb r1, [r6]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r6]
    adds r0, r4, #0
    adds r0, #0x30
    strb r2, [r0]
    subs r0, #0x10
    strb r2, [r0]
    adds r1, r4, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08010642
    ldrb r0, [r3, #1]
    cmp r0, #1
    bne lbl_08010642
    movs r0, #2
    strb r0, [r3, #1]
    strb r2, [r1]
lbl_08010642:
    cmp r5, #1
    bne lbl_0801064e
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x63
    b lbl_08010660
lbl_0801064e:
    cmp r5, #2
    bne lbl_0801065a
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x64
    b lbl_08010660
lbl_0801065a:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x65
lbl_08010660:
    strb r0, [r1]
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    adds r2, r4, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    movs r1, #0x11
    orrs r0, r1
    strb r0, [r2]
    ldrb r1, [r6]
    movs r0, #2
    orrs r0, r1
    strb r0, [r6]
    b lbl_0801069e
lbl_08010684:
    adds r2, r4, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #3
    bhs lbl_0801069c
    movs r0, #0x80
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strb r0, [r2]
lbl_0801069c:
    movs r5, #0
lbl_0801069e:
    adds r0, r5, #0
lbl_080106a0:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start is_pulling_self_up
is_pulling_self_up: @ 0x080106a8
    push {lr}
    ldr r0, lbl_080106bc @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x1c
    bgt lbl_080106c0
    cmp r0, #0x1a
    blt lbl_080106c0
    movs r0, #1
    b lbl_080106c2
    .align 2, 0
lbl_080106bc: .4byte 0x030013d4
lbl_080106c0:
    movs r0, #0
lbl_080106c2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start is_on_zipline
is_on_zipline: @ 0x080106c8
    push {lr}
    ldr r0, lbl_080106dc @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x2b
    bgt lbl_080106e0
    cmp r0, #0x28
    blt lbl_080106e0
    movs r0, #1
    b lbl_080106e2
    .align 2, 0
lbl_080106dc: .4byte 0x030013d4
lbl_080106e0:
    movs r0, #0
lbl_080106e2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start count_primary_sprites
count_primary_sprites: @ 0x080106e8
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #0
    ldr r2, lbl_08010734 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0801072a
    adds r6, r0, #0
    adds r3, r2, #0
    adds r3, #0x1d
lbl_08010702:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010722
    ldrb r1, [r3, #0x15]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08010722
    ldrb r0, [r3]
    cmp r0, r5
    bne lbl_08010722
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_08010722:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r6
    blo lbl_08010702
lbl_0801072a:
    adds r0, r4, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08010734: .4byte 0x030001ac

    thumb_func_start count_secondary_sprites_with_current_sprites_slot
count_secondary_sprites_with_current_sprites_slot: @ 0x08010738
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    movs r4, #0
    ldr r0, lbl_08010790 @ =0x03000738
    adds r0, #0x23
    ldrb r5, [r0]
    ldr r2, lbl_08010794 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08010786
    adds r7, r0, #0
    adds r3, r2, #0
    adds r3, #0x23
lbl_08010758:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0801077e
    ldrb r1, [r3, #0xf]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0801077e
    ldrb r0, [r2, #0x1d]
    cmp r0, r6
    bne lbl_0801077e
    ldrb r0, [r3]
    cmp r0, r5
    bne lbl_0801077e
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0801077e:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r7
    blo lbl_08010758
lbl_08010786:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08010790: .4byte 0x03000738
lbl_08010794: .4byte 0x030001ac

    thumb_func_start count_primary_sprites_with_current_sprites_slot
count_primary_sprites_with_current_sprites_slot: @ 0x08010798
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    movs r4, #0
    ldr r0, lbl_080107f0 @ =0x03000738
    adds r0, #0x23
    ldrb r5, [r0]
    ldr r2, lbl_080107f4 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_080107e6
    adds r7, r0, #0
    adds r3, r2, #0
    adds r3, #0x23
lbl_080107b8:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080107de
    ldrb r1, [r3, #0xf]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_080107de
    ldrb r0, [r2, #0x1d]
    cmp r0, r6
    bne lbl_080107de
    ldrb r0, [r3]
    cmp r0, r5
    bne lbl_080107de
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_080107de:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r7
    blo lbl_080107b8
lbl_080107e6:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080107f0: .4byte 0x03000738
lbl_080107f4: .4byte 0x030001ac

    thumb_func_start find_primary_sprite
find_primary_sprite: @ 0x080107f8
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #0
    ldr r2, lbl_08010830 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08010844
    adds r3, r2, #0
    adds r3, #0x1d
lbl_08010810:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010834
    ldrb r1, [r3, #0x15]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08010834
    ldrb r0, [r3]
    cmp r0, r5
    bne lbl_08010834
    adds r0, r4, #0
    b lbl_08010846
    .align 2, 0
lbl_08010830: .4byte 0x030001ac
lbl_08010834:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r3, #0x38
    adds r2, #0x38
    ldr r0, lbl_0801084c @ =0x030006ec
    cmp r2, r0
    blo lbl_08010810
lbl_08010844:
    movs r0, #0xff
lbl_08010846:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0801084c: .4byte 0x030006ec

    thumb_func_start find_secondary_sprite_with_room_slot
find_secondary_sprite_with_room_slot: @ 0x08010850
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r4, #0
    ldr r3, lbl_08010890 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r3, r1
    cmp r3, r0
    bhs lbl_080108a4
    adds r2, r3, #0
    adds r2, #0x1d
lbl_0801086c:
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010894
    ldrb r1, [r2, #0x15]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08010894
    ldrb r0, [r2]
    cmp r0, r6
    bne lbl_08010894
    ldrb r0, [r2, #1]
    cmp r0, r5
    bne lbl_08010894
    adds r0, r4, #0
    b lbl_080108a6
    .align 2, 0
lbl_08010890: .4byte 0x030001ac
lbl_08010894:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, #0x38
    adds r3, #0x38
    ldr r0, lbl_080108ac @ =0x030006ec
    cmp r3, r0
    blo lbl_0801086c
lbl_080108a4:
    movs r0, #0xff
lbl_080108a6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080108ac: .4byte 0x030006ec

    thumb_func_start check_current_enemy_has_drop
check_current_enemy_has_drop: @ 0x080108b0
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_080108e8 @ =0x03000738
    adds r0, #0x23
    ldrb r4, [r0]
    movs r7, #0x1f
    ldr r2, lbl_080108ec @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_080108f8
    movs r6, #1
    adds r3, r2, #0
    adds r3, #0x23
    adds r5, r0, #0
lbl_080108ce:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080108f0
    ldrb r0, [r3]
    cmp r0, r4
    bne lbl_080108f0
    ldrb r0, [r3, #2]
    cmp r0, r7
    blo lbl_080108f0
    movs r0, #1
    b lbl_080108fa
    .align 2, 0
lbl_080108e8: .4byte 0x03000738
lbl_080108ec: .4byte 0x030001ac
lbl_080108f0:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r5
    blo lbl_080108ce
lbl_080108f8:
    movs r0, #0
lbl_080108fa:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start count_enemy_drops
count_enemy_drops: @ 0x08010900
    push {r4, r5, r6, lr}
    movs r3, #0
    movs r6, #0x1f
    ldr r2, lbl_08010940 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08010936
    movs r5, #1
    adds r4, r0, #0
lbl_08010916:
    ldrh r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08010930
    adds r0, r2, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, r6
    blo lbl_08010930
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
lbl_08010930:
    adds r2, #0x38
    cmp r2, r4
    blo lbl_08010916
lbl_08010936:
    adds r0, r3, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08010940: .4byte 0x030001ac

    thumb_func_start mecha_ridley_missile_move
mecha_ridley_missile_move: @ 0x08010944
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r4, [sp, #0x24]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    adds r7, r5, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    str r2, [sp]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov r8, r3
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    movs r0, #0
    mov sb, r0
    ldr r1, lbl_080109b8 @ =0x03000738
    mov ip, r1
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, #0
    beq lbl_080109d6
    mov r2, ip
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_080109bc
    mov r6, ip
    ldrh r1, [r6, #4]
    subs r0, r5, #4
    cmp r1, r0
    bgt lbl_080109ec
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r3
    bhs lbl_080109a8
    adds r0, #1
    strb r0, [r1]
lbl_080109a8:
    ldrb r0, [r1]
    asrs r0, r4
    mov r1, ip
    ldrh r1, [r1, #4]
    adds r0, r0, r1
    mov r2, ip
    strh r0, [r2, #4]
    b lbl_08010a54
    .align 2, 0
lbl_080109b8: .4byte 0x03000738
lbl_080109bc:
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010a5a
    ldrb r0, [r2]
    asrs r0, r4
    mov r3, ip
    ldrh r3, [r3, #4]
    adds r0, r0, r3
    mov r6, ip
    strh r0, [r6, #4]
    b lbl_08010a54
lbl_080109d6:
    mov r2, ip
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_08010a20
    mov r0, ip
    ldrh r3, [r0, #4]
    adds r0, r7, #4
    cmp r3, r0
    bge lbl_080109f6
lbl_080109ec:
    mov r0, ip
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_08010a54
lbl_080109f6:
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r8
    bhs lbl_08010a04
    adds r0, #1
    strb r0, [r1]
lbl_08010a04:
    ldrb r0, [r1]
    asrs r0, r4
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    subs r1, r3, r1
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08010a4a
    movs r1, #1
    mov sb, r1
    strb r5, [r2]
    b lbl_08010a54
lbl_08010a20:
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010a50
    ldrb r0, [r2]
    asrs r0, r4
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    mov r3, ip
    ldrh r0, [r3, #4]
    subs r1, r0, r1
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08010a4a
    movs r0, #1
    mov sb, r0
    strb r6, [r2]
    b lbl_08010a54
lbl_08010a4a:
    mov r2, ip
    strh r1, [r2, #4]
    b lbl_08010a54
lbl_08010a50:
    movs r3, #1
    mov sb, r3
lbl_08010a54:
    mov r6, sb
    cmp r6, #0
    beq lbl_08010a72
lbl_08010a5a:
    mov r1, ip
    ldrh r0, [r1]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    eors r0, r1
    mov r3, ip
    strh r0, [r3]
    mov r1, ip
    adds r1, #0x2e
    movs r0, #1
    strb r0, [r1]
lbl_08010a72:
    movs r6, #0
    mov sb, r6
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_08010ae2
    mov r3, ip
    adds r3, #0x2c
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_08010ac8
    mov r2, ip
    ldrh r1, [r2, #2]
    mov r0, sl
    subs r0, #4
    cmp r1, r0
    ble lbl_08010aa8
    mov r0, ip
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r3]
    b lbl_08010b6a
lbl_08010aa8:
    mov r1, ip
    adds r1, #0x2f
    ldrb r0, [r1]
    ldr r3, [sp]
    cmp r0, r3
    bhs lbl_08010ab8
    adds r0, #1
    strb r0, [r1]
lbl_08010ab8:
    ldrb r0, [r1]
    asrs r0, r4
    mov r4, ip
    ldrh r4, [r4, #2]
    adds r0, r0, r4
    mov r6, ip
    strh r0, [r6, #2]
    b lbl_08010b6a
lbl_08010ac8:
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010b70
    ldrb r0, [r3]
    asrs r0, r4
    mov r1, ip
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    mov r2, ip
    strh r0, [r2, #2]
    b lbl_08010b6a
lbl_08010ae2:
    mov r2, ip
    adds r2, #0x2c
    ldrb r0, [r2]
    adds r5, r0, #0
    cmp r5, #0
    bne lbl_08010b36
    mov r6, ip
    ldrh r3, [r6, #2]
    mov r0, sl
    adds r0, #4
    cmp r3, r0
    bge lbl_08010b04
    mov r0, ip
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_08010b6a
lbl_08010b04:
    mov r1, ip
    adds r1, #0x2f
    ldrb r0, [r1]
    ldr r6, [sp]
    cmp r0, r6
    bhs lbl_08010b14
    adds r0, #1
    strb r0, [r1]
lbl_08010b14:
    ldrb r0, [r1]
    asrs r0, r4
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    subs r1, r3, r1
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08010b30
    movs r0, #1
    mov sb, r0
    strb r5, [r2]
    b lbl_08010b6a
lbl_08010b30:
    mov r2, ip
    strh r1, [r2, #2]
    b lbl_08010b6a
lbl_08010b36:
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010b66
    ldrb r0, [r2]
    asrs r0, r4
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    mov r4, ip
    ldrh r0, [r4, #2]
    subs r1, r0, r1
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08010b60
    movs r6, #1
    mov sb, r6
    strb r3, [r2]
    b lbl_08010b6a
lbl_08010b60:
    mov r0, ip
    strh r1, [r0, #2]
    b lbl_08010b6a
lbl_08010b66:
    movs r1, #1
    mov sb, r1
lbl_08010b6a:
    mov r2, sb
    cmp r2, #0
    beq lbl_08010b86
lbl_08010b70:
    mov r3, ip
    ldrh r0, [r3]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r1, r4, #0
    eors r0, r1
    strh r0, [r3]
    mov r1, ip
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_08010b86:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ridley_fireball_move
ridley_fireball_move: @ 0x08010b98
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, [sp, #0x18]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    lsls r2, r2, #0x18
    lsrs r6, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_08010be0 @ =0x03000738
    mov ip, r0
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08010be4
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r3
    bhs lbl_08010bd0
    adds r0, #1
    strb r0, [r1]
lbl_08010bd0:
    ldrb r0, [r1]
    asrs r0, r4
    mov r1, ip
    ldrh r1, [r1, #4]
    adds r0, r0, r1
    mov r2, ip
    b lbl_08010bfc
    .align 2, 0
lbl_08010be0: .4byte 0x03000738
lbl_08010be4:
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r3
    bhs lbl_08010bf2
    adds r0, #1
    strb r0, [r1]
lbl_08010bf2:
    ldrb r1, [r1]
    asrs r1, r4
    mov r2, ip
    ldrh r0, [r2, #4]
    subs r0, r0, r1
lbl_08010bfc:
    strh r0, [r2, #4]
    movs r7, #0
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_08010c64
    mov r2, ip
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_08010c4a
    mov r5, ip
    adds r5, #0x2f
    ldrb r3, [r5]
    cmp r3, r6
    bhs lbl_08010c36
    mov r0, ip
    ldrh r1, [r0, #2]
    mov r0, r8
    subs r0, #4
    cmp r1, r0
    bgt lbl_08010cbe
    adds r0, r3, #1
    strb r0, [r5]
lbl_08010c36:
    mov r0, ip
    adds r0, #0x2f
    ldrb r0, [r0]
    asrs r0, r4
    mov r1, ip
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    mov r2, ip
    strh r0, [r2, #2]
    b lbl_08010cca
lbl_08010c4a:
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010cce
    ldrb r0, [r2]
    asrs r0, r4
    mov r4, ip
    ldrh r4, [r4, #2]
    adds r0, r0, r4
    mov r1, ip
    strh r0, [r1, #2]
    b lbl_08010cca
lbl_08010c64:
    mov r2, ip
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_08010c9a
    mov r5, ip
    adds r5, #0x2f
    ldrb r3, [r5]
    cmp r3, r6
    bhs lbl_08010c88
    mov r0, ip
    ldrh r1, [r0, #2]
    mov r0, r8
    adds r0, #4
    cmp r1, r0
    blt lbl_08010cbe
    adds r0, r3, #1
    strb r0, [r5]
lbl_08010c88:
    mov r0, ip
    adds r0, #0x2f
    ldrb r1, [r0]
    asrs r1, r4
    mov r2, ip
    ldrh r0, [r2, #2]
    subs r0, r0, r1
    strh r0, [r2, #2]
    b lbl_08010cca
lbl_08010c9a:
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08010cc8
    ldrb r0, [r2]
    asrs r0, r4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r4, ip
    ldrh r1, [r4, #2]
    subs r1, r1, r0
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08010cc2
    movs r7, #1
lbl_08010cbe:
    strb r3, [r2]
    b lbl_08010cca
lbl_08010cc2:
    mov r0, ip
    strh r1, [r0, #2]
    b lbl_08010cca
lbl_08010cc8:
    movs r7, #1
lbl_08010cca:
    cmp r7, #0
    beq lbl_08010ce6
lbl_08010cce:
    mov r1, ip
    ldrh r0, [r1]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    eors r0, r1
    mov r4, ip
    strh r0, [r4]
    mov r1, ip
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_08010ce6:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start update_sprite_stun_timer
update_sprite_stun_timer: @ 0x08010cf0
    push {lr}
    adds r2, r0, #0
    adds r3, r2, #0
    adds r3, #0x2b
    ldrb r1, [r3]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08010d62
    subs r0, r1, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08010d62
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08010d34
    ldrh r0, [r2, #0x14]
    cmp r0, #0
    beq lbl_08010d62
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xe
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    b lbl_08010d60
lbl_08010d34:
    ldrh r0, [r2, #0x14]
    cmp r0, #0
    beq lbl_08010d62
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08010d58
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    b lbl_08010d60
lbl_08010d58:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
lbl_08010d60:
    strb r1, [r0]
lbl_08010d62:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start random_sprite_debris
random_sprite_debris: @ 0x08010d68
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r6, r3, #0x10
    cmp r4, #2
    beq lbl_08010dc2
    cmp r4, #2
    bgt lbl_08010d88
    cmp r4, #1
    beq lbl_08010d8e
    b lbl_08010e88
lbl_08010d88:
    cmp r4, #3
    beq lbl_08010e14
    b lbl_08010e88
lbl_08010d8e:
    ldr r0, lbl_08010dac @ =0x03000c77
    ldrb r1, [r0]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08010db0
    adds r2, r5, #0
    subs r2, #8
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #2
    bl sprite_debris_init
    b lbl_08010e88
    .align 2, 0
lbl_08010dac: .4byte 0x03000c77
lbl_08010db0:
    adds r2, r5, #0
    adds r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #1
    bl sprite_debris_init
    b lbl_08010e88
lbl_08010dc2:
    ldr r0, lbl_08010df0 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010df4
    adds r2, r5, #0
    subs r2, #8
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #2
    bl sprite_debris_init
    adds r2, r5, #0
    adds r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #4
    bl sprite_debris_init
    b lbl_08010e88
    .align 2, 0
lbl_08010df0: .4byte 0x03000c77
lbl_08010df4:
    adds r2, r5, #0
    subs r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #1
    bl sprite_debris_init
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #3
    adds r2, r5, #0
    bl sprite_debris_init
    b lbl_08010e88
lbl_08010e14:
    ldr r0, lbl_08010e54 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08010e58
    adds r2, r5, #0
    subs r2, #8
    adds r4, r6, #0
    subs r4, #8
    adds r0, r7, #0
    movs r1, #1
    adds r3, r4, #0
    bl sprite_debris_init
    adds r2, r5, #0
    subs r2, #0x10
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #3
    bl sprite_debris_init
    adds r2, r5, #0
    adds r2, #8
    adds r0, r7, #0
    movs r1, #4
    adds r3, r4, #0
    bl sprite_debris_init
    b lbl_08010e88
    .align 2, 0
lbl_08010e54: .4byte 0x03000c77
lbl_08010e58:
    adds r2, r5, #0
    subs r2, #0x10
    adds r4, r6, #0
    adds r4, #8
    adds r0, r7, #0
    movs r1, #2
    adds r3, r4, #0
    bl sprite_debris_init
    adds r2, r5, #0
    adds r2, #8
    adds r0, r7, #0
    movs r1, #3
    adds r3, r4, #0
    bl sprite_debris_init
    adds r2, r5, #0
    adds r2, #0x10
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #4
    bl sprite_debris_init
lbl_08010e88:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start get_ammo_drop
get_ammo_drop: @ 0x08010e90
    push {lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r0, lbl_08010eb8 @ =0x03001530
    ldrh r1, [r0, #6]
    adds r2, r0, #0
    ldrh r0, [r2]
    cmp r1, r0
    bne lbl_08010ee4
    movs r0, #1
    ands r0, r3
    cmp r0, #0
    beq lbl_08010ebc
    ldrh r0, [r2, #2]
    ldrh r1, [r2, #8]
    cmp r0, r1
    bls lbl_08010ebc
    movs r0, #0x1c
    b lbl_08010ee6
    .align 2, 0
lbl_08010eb8: .4byte 0x03001530
lbl_08010ebc:
    movs r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_08010ed0
    ldrb r0, [r2, #4]
    ldrb r1, [r2, #0xa]
    cmp r0, r1
    bls lbl_08010ed0
    movs r0, #0x1d
    b lbl_08010ee6
lbl_08010ed0:
    movs r0, #4
    ands r0, r3
    cmp r0, #0
    beq lbl_08010ee4
    ldrb r0, [r2, #5]
    ldrb r2, [r2, #0xb]
    cmp r0, r2
    bls lbl_08010ee4
    movs r0, #0x1e
    b lbl_08010ee6
lbl_08010ee4:
    movs r0, #0
lbl_08010ee6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start determine_enemy_drop
determine_enemy_drop: @ 0x08010eec
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    movs r0, #0
    mov sb, r0
    ldr r0, lbl_08010f3c @ =0x03001530
    ldrh r1, [r0, #6]
    mov r8, r0
    ldrh r2, [r0]
    cmp r1, r2
    bne lbl_08010f0a
    movs r0, #1
    mov sb, r0
lbl_08010f0a:
    ldr r0, lbl_08010f40 @ =0x0300083c
    ldrb r4, [r0]
    lsls r4, r4, #8
    ldr r1, lbl_08010f44 @ =0x03000c77
    ldr r0, lbl_08010f48 @ =0x03000002
    ldrh r0, [r0]
    ldrb r1, [r1]
    adds r0, r0, r1
    adds r0, r4, r0
    lsls r0, r0, #0x16
    lsrs r4, r0, #0x16
    cmp r4, #0
    bne lbl_08010f26
    movs r4, #1
lbl_08010f26:
    ldr r0, lbl_08010f4c @ =0x03000738
    ldrb r3, [r0, #0x1d]
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08010f54
    ldr r2, lbl_08010f50 @ =0x082b1be4
    b lbl_08010f56
    .align 2, 0
lbl_08010f3c: .4byte 0x03001530
lbl_08010f40: .4byte 0x0300083c
lbl_08010f44: .4byte 0x03000c77
lbl_08010f48: .4byte 0x03000002
lbl_08010f4c: .4byte 0x03000738
lbl_08010f50: .4byte 0x082b1be4
lbl_08010f54:
    ldr r2, lbl_08010fbc @ =0x082b0d68
lbl_08010f56:
    lsls r1, r3, #3
    adds r1, r1, r3
    lsls r1, r1, #1
    adds r0, r2, #0
    adds r0, #8
    adds r0, r1, r0
    ldrh r0, [r0]
    mov ip, r0
    adds r0, r2, #0
    adds r0, #0xa
    adds r0, r1, r0
    ldrh r6, [r0]
    adds r0, r2, #0
    adds r0, #0xc
    adds r0, r1, r0
    ldrh r5, [r0]
    adds r0, r2, #0
    adds r0, #0xe
    adds r0, r1, r0
    ldrh r3, [r0]
    adds r0, r2, #0
    adds r0, #0x10
    adds r1, r1, r0
    ldrh r2, [r1]
    cmp r2, #0
    beq lbl_08010fc0
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r0, #0
    subs r0, r1, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    cmp r4, r1
    bhi lbl_08010fc4
    cmp r4, r2
    bls lbl_08010fc4
    mov r1, r8
    ldrb r0, [r1, #5]
    ldrb r2, [r1, #0xb]
    cmp r0, r2
    bhi lbl_08010fb8
    mov r1, sb
    cmp r1, #0
    beq lbl_0801101c
    movs r7, #0x1b
    cmp r0, #0
    beq lbl_08011074
lbl_08010fb8:
    movs r7, #0x1e
    b lbl_08011074
    .align 2, 0
lbl_08010fbc: .4byte 0x082b0d68
lbl_08010fc0:
    movs r2, #0x80
    lsls r2, r2, #3
lbl_08010fc4:
    cmp r3, #0
    beq lbl_08010ff0
    subs r0, r2, r3
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r2, r4
    blo lbl_08010ff2
    cmp r4, r3
    bls lbl_08010ff2
    mov r2, r8
    ldrb r0, [r2, #4]
    ldrb r1, [r2, #0xa]
    cmp r0, r1
    bhi lbl_08010fec
    mov r2, sb
    cmp r2, #0
    beq lbl_0801101c
    movs r7, #0x1b
    cmp r0, #0
    beq lbl_08011074
lbl_08010fec:
    movs r7, #0x1d
    b lbl_08011074
lbl_08010ff0:
    adds r3, r2, #0
lbl_08010ff2:
    cmp r5, #0
    beq lbl_08011020
    subs r0, r3, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r3, r4
    blo lbl_08011022
    cmp r4, r5
    bls lbl_08011022
    mov r1, r8
    ldrh r0, [r1, #2]
    ldrh r2, [r1, #8]
    cmp r0, r2
    bhi lbl_08011072
    mov r1, sb
    cmp r1, #0
    beq lbl_0801101c
    movs r7, #0x1b
    cmp r0, #0
    beq lbl_08011074
    b lbl_08011072
lbl_0801101c:
    movs r7, #0x1a
    b lbl_08011074
lbl_08011020:
    adds r5, r3, #0
lbl_08011022:
    cmp r6, #0
    beq lbl_08011048
    subs r0, r5, r6
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r5, r4
    blo lbl_0801104a
    cmp r4, r6
    bls lbl_0801104a
    movs r7, #0x1a
    mov r2, sb
    cmp r2, #0
    beq lbl_08011074
    mov r1, r8
    ldrh r0, [r1, #2]
    ldrh r2, [r1, #8]
    cmp r0, r2
    bls lbl_08011074
    b lbl_08011072
lbl_08011048:
    adds r6, r5, #0
lbl_0801104a:
    mov r0, ip
    cmp r0, #0
    beq lbl_08011074
    subs r0, r6, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    cmp r6, r4
    blo lbl_08011074
    cmp r4, ip
    bls lbl_08011074
    movs r7, #0x1b
    mov r1, sb
    cmp r1, #0
    beq lbl_08011074
    mov r2, r8
    ldrh r0, [r2, #2]
    ldrh r1, [r2, #8]
    cmp r0, r1
    bls lbl_08011074
lbl_08011072:
    movs r7, #0x1c
lbl_08011074:
    adds r0, r7, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sprite_death
sprite_death: @ 0x08011084
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r4, [sp, #0x24]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    lsls r4, r4, #0x18
    lsrs r2, r4, #0x18
    ldr r0, lbl_080110b8 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x64
    beq lbl_080110e8
    cmp r0, #0x64
    bgt lbl_080110bc
    cmp r0, #0x63
    beq lbl_080110c6
    b lbl_0801114c
    .align 2, 0
lbl_080110b8: .4byte 0x03000738
lbl_080110bc:
    cmp r0, #0x65
    beq lbl_0801110c
    cmp r0, #0x66
    beq lbl_0801112c
    b lbl_0801114c
lbl_080110c6:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x24
    bl set_particle_effect
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl random_sprite_debris
    ldr r0, lbl_080110e4 @ =0x00000131
    bl play_sound1
    b lbl_080111d8
    .align 2, 0
lbl_080110e4: .4byte 0x00000131
lbl_080110e8:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x26
    bl set_particle_effect
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl random_sprite_debris
    ldr r0, lbl_08011108 @ =0x00000133
    bl play_sound1
    b lbl_080111d8
    .align 2, 0
lbl_08011108: .4byte 0x00000133
lbl_0801110c:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x23
    bl set_particle_effect
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl random_sprite_debris
    movs r0, #0x98
    lsls r0, r0, #1
    bl play_sound1
    b lbl_080111d8
lbl_0801112c:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x25
    bl set_particle_effect
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl random_sprite_debris
    movs r0, #0x99
    lsls r0, r0, #1
    bl play_sound1
    b lbl_080111d8
lbl_0801114c:
    cmp r2, #0x1f
    bne lbl_08011168
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x1f
    bl set_particle_effect
    cmp r7, #0
    beq lbl_080111d8
    movs r0, #0x96
    lsls r0, r0, #1
    bl play_sound1
    b lbl_080111d8
lbl_08011168:
    cmp r2, #0x20
    bne lbl_08011188
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl set_particle_effect
    cmp r7, #0
    beq lbl_080111d8
    ldr r0, lbl_08011184 @ =0x0000012d
    bl play_sound1
    b lbl_080111d8
    .align 2, 0
lbl_08011184: .4byte 0x0000012d
lbl_08011188:
    cmp r2, #0x21
    bne lbl_080111a4
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x21
    bl set_particle_effect
    cmp r7, #0
    beq lbl_080111d8
    movs r0, #0x97
    lsls r0, r0, #1
    bl play_sound1
    b lbl_080111d8
lbl_080111a4:
    cmp r2, #0x22
    bne lbl_080111c4
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x22
    bl set_particle_effect
    cmp r7, #0
    beq lbl_080111d8
    ldr r0, lbl_080111c0 @ =0x0000012f
    bl play_sound1
    b lbl_080111d8
    .align 2, 0
lbl_080111c0: .4byte 0x0000012f
lbl_080111c4:
    adds r0, r2, #0
    subs r0, #0x27
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_080111d8
    adds r0, r5, #0
    adds r1, r6, #0
    bl set_particle_effect
lbl_080111d8:
    bl determine_enemy_drop
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r3, r2, #0
    cmp r2, #0
    beq lbl_08011264
    mov r0, r8
    cmp r0, #0
    beq lbl_08011210
    cmp r0, #2
    beq lbl_0801126e
    ldr r0, lbl_0801120c @ =0x03000738
    ldrb r1, [r0, #0x1e]
    adds r0, #0x23
    ldrb r3, [r0]
    str r5, [sp]
    str r6, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r2, #0
    movs r2, #0
    bl spawn_drops_and_followers
    b lbl_0801126e
    .align 2, 0
lbl_0801120c: .4byte 0x03000738
lbl_08011210:
    ldr r2, lbl_08011260 @ =0x03000738
    movs r1, #0
    movs r0, #7
    strh r0, [r2]
    adds r0, r2, #0
    adds r0, #0x32
    strb r1, [r0]
    strb r1, [r2, #0x1f]
    strb r3, [r2, #0x1d]
    strh r5, [r2, #2]
    strh r6, [r2, #4]
    adds r3, r2, #0
    adds r3, #0x21
    movs r0, #2
    strb r0, [r3]
    adds r3, #1
    movs r0, #4
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x24
    strb r1, [r0]
    mov r0, r8
    strh r0, [r2, #0x14]
    adds r0, r2, #0
    adds r0, #0x2b
    strb r1, [r0]
    subs r0, #0xb
    strb r1, [r0]
    adds r0, #0x13
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r3, #4
    movs r0, #1
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x30
    strb r1, [r0]
    b lbl_0801126e
    .align 2, 0
lbl_08011260: .4byte 0x03000738
lbl_08011264:
    mov r1, r8
    cmp r1, #0
    bne lbl_0801126e
    ldr r0, lbl_0801127c @ =0x03000738
    strh r1, [r0]
lbl_0801126e:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801127c: .4byte 0x03000738

    thumb_func_start is_sprite_stunned
is_sprite_stunned: @ 0x08011280
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_080112c0 @ =0x0300002c
    ldrb r0, [r0]
    movs r3, #0xe
    cmp r0, #1
    bhi lbl_08011290
    movs r3, #9
lbl_08011290:
    ldr r2, lbl_080112c4 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, r3
    bls lbl_080112b6
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x61
    bhi lbl_080112b6
    ldrb r0, [r2, #0x1c]
    cmp r0, #0
    beq lbl_080112b4
    subs r0, #1
    strb r0, [r2, #0x1c]
lbl_080112b4:
    movs r4, #1
lbl_080112b6:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080112c0: .4byte 0x0300002c
lbl_080112c4: .4byte 0x03000738

    thumb_func_start is_sprite_on_screen_and_shaking
is_sprite_on_screen_and_shaking: @ 0x080112c8
    push {lr}
    ldr r0, lbl_080112ec @ =0x03000738
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080112f8
    ldr r0, lbl_080112f0 @ =0x03000110
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080112e6
    ldr r0, lbl_080112f4 @ =0x03000114
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080112f8
lbl_080112e6:
    movs r0, #1
    b lbl_080112fa
    .align 2, 0
lbl_080112ec: .4byte 0x03000738
lbl_080112f0: .4byte 0x03000110
lbl_080112f4: .4byte 0x03000114
lbl_080112f8:
    movs r0, #0
lbl_080112fa:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08011300
sub_08011300: @ 0x08011300
    push {r4, lr}
    ldr r4, lbl_0801132c @ =0x0300070c
    movs r0, #0
    strb r0, [r4, #0xe]
    ldrb r1, [r4, #0xc]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrh r3, [r4, #4]
    ldr r2, [r4]
    lsls r0, r3, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    cmp r0, r1
    bhs lbl_08011326
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    adds r0, #1
    strb r0, [r4, #0xe]
lbl_08011326:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801132c: .4byte 0x0300070c

    thumb_func_start update_subsprite1_anim
update_subsprite1_anim: @ 0x08011330
    push {lr}
    ldr r2, lbl_08011368 @ =0x0300070c
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
    ldrh r1, [r2, #4]
    ldr r3, [r2]
    lsls r1, r1, #3
    adds r1, r1, r3
    ldrb r1, [r1, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhs lbl_08011364
    movs r0, #1
    strb r0, [r2, #0xc]
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    ldrh r0, [r2, #4]
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08011364
    strh r0, [r2, #4]
lbl_08011364:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08011368: .4byte 0x0300070c

    thumb_func_start sync_current_sprite_pos_with_subsprite1
sync_current_sprite_pos_with_subsprite1: @ 0x0801136c
    push {r4, lr}
    ldr r3, lbl_080113a8 @ =0x0300070c
    ldrh r0, [r3, #4]
    ldr r1, [r3]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r4, [r0]
    ldr r2, lbl_080113ac @ =0x03000738
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r4
    ldrh r0, [r0, #2]
    ldrh r1, [r3, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r4
    ldrh r0, [r0, #4]
    ldrh r3, [r3, #8]
    adds r0, r0, r3
    strh r0, [r2, #4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080113a8: .4byte 0x0300070c
lbl_080113ac: .4byte 0x03000738

    thumb_func_start sub_080113b0
sub_080113b0: @ 0x080113b0
    push {r4, lr}
    ldr r4, lbl_080113f0 @ =0x0300070c
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_080113f4 @ =0x03000738
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #2]
    ldrh r1, [r4, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080113f8
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r1, [r4, #8]
    ldrh r0, [r0, #4]
    subs r1, r1, r0
    strh r1, [r2, #4]
    b lbl_0801140a
    .align 2, 0
lbl_080113f0: .4byte 0x0300070c
lbl_080113f4: .4byte 0x03000738
lbl_080113f8:
    ldrb r0, [r2, #0x1e]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1, #4]
    ldrh r4, [r4, #8]
    adds r0, r0, r4
    strh r0, [r2, #4]
lbl_0801140a:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start update_subsprite2_anima
update_subsprite2_anima: @ 0x08011410
    push {lr}
    ldr r2, lbl_08011448 @ =0x03000720
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
    ldrh r1, [r2, #4]
    ldr r3, [r2]
    lsls r1, r1, #3
    adds r1, r1, r3
    ldrb r1, [r1, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhs lbl_08011444
    movs r0, #1
    strb r0, [r2, #0xc]
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    ldrh r0, [r2, #4]
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08011444
    strh r0, [r2, #4]
lbl_08011444:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08011448: .4byte 0x03000720

    thumb_func_start sub_0801144c
sub_0801144c: @ 0x0801144c
    push {r4, lr}
    ldr r4, lbl_0801148c @ =0x03000720
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_08011490 @ =0x03000738
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #2]
    ldrh r1, [r4, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08011494
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r1, [r4, #8]
    ldrh r0, [r0, #4]
    subs r1, r1, r0
    strh r1, [r2, #4]
    b lbl_080114a6
    .align 2, 0
lbl_0801148c: .4byte 0x03000720
lbl_08011490: .4byte 0x03000738
lbl_08011494:
    ldrb r0, [r2, #0x1e]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1, #4]
    ldrh r4, [r4, #8]
    adds r0, r0, r4
    strh r0, [r2, #4]
lbl_080114a6:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start update_subsprite_anim
update_subsprite_anim: @ 0x080114ac
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
    ldrh r1, [r2, #4]
    ldr r3, [r2]
    lsls r1, r1, #3
    adds r1, r1, r3
    ldrb r1, [r1, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhs lbl_080114e0
    movs r0, #1
    strb r0, [r2, #0xc]
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    ldrh r0, [r2, #4]
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080114e0
    strh r0, [r2, #4]
lbl_080114e0:
    pop {r0}
    bx r0

    thumb_func_start sync_current_sprite_pos_with_subsprite
sync_current_sprite_pos_with_subsprite: @ 0x080114e4
    push {r4, lr}
    ldrh r1, [r0, #4]
    ldr r2, [r0]
    lsls r1, r1, #3
    adds r1, r1, r2
    ldr r4, [r1]
    ldr r3, lbl_0801151c @ =0x03000738
    ldrb r2, [r3, #0x1e]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #1
    adds r1, r1, r4
    ldrh r1, [r1, #2]
    ldrh r2, [r0, #6]
    adds r1, r1, r2
    strh r1, [r3, #2]
    ldrb r2, [r3, #0x1e]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #1
    adds r1, r1, r4
    ldrh r1, [r1, #4]
    ldrh r0, [r0, #8]
    adds r1, r1, r0
    strh r1, [r3, #4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801151c: .4byte 0x03000738

    thumb_func_start sub_08011520
sub_08011520: @ 0x08011520
    push {r4, lr}
    adds r2, r0, #0
    ldrh r0, [r2, #4]
    ldr r1, [r2]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r4, [r0]
    ldr r3, lbl_08011560 @ =0x03000738
    ldrb r1, [r3, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r4
    ldrh r0, [r0, #2]
    ldrh r1, [r2, #6]
    adds r0, r0, r1
    strh r0, [r3, #2]
    ldrh r1, [r3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08011564
    ldrb r1, [r3, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r4
    ldrh r1, [r2, #8]
    ldrh r0, [r0, #4]
    subs r1, r1, r0
    strh r1, [r3, #4]
    b lbl_08011576
    .align 2, 0
lbl_08011560: .4byte 0x03000738
lbl_08011564:
    ldrb r0, [r3, #0x1e]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #1
    adds r1, r1, r4
    ldrh r0, [r1, #4]
    ldrh r2, [r2, #8]
    adds r0, r0, r2
    strh r0, [r3, #4]
lbl_08011576:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start security_gate_samus_collision
security_gate_samus_collision: @ 0x0801157c
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #0x10
    ldr r4, lbl_08011604 @ =0x03000738
    ldrh r1, [r4, #2]
    ldrh r3, [r4, #4]
    ldrh r0, [r4, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrh r2, [r4, #0xc]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r2, [r4, #0xe]
    adds r2, r3, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrh r4, [r4, #0x10]
    adds r3, r3, r4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, lbl_08011608 @ =0x030013d4
    ldrh r5, [r4, #0x14]
    mov r8, r5
    ldrh r4, [r4, #0x12]
    mov sb, r4
    ldr r5, lbl_0801160c @ =0x03001588
    adds r4, r5, #0
    adds r4, #0x70
    ldrh r6, [r4]
    add r6, r8
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    adds r4, #4
    ldrh r4, [r4]
    add r8, r4
    mov r4, r8
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    mov r8, r4
    adds r4, r5, #0
    adds r4, #0x6e
    ldrh r4, [r4]
    add r4, sb
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    adds r5, #0x72
    ldrh r5, [r5]
    add sb, r5
    mov r5, sb
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    mov sb, r5
    str r6, [sp]
    mov r5, r8
    str r5, [sp, #4]
    str r4, [sp, #8]
    mov r4, sb
    str r4, [sp, #0xc]
    bl check_collision
    cmp r0, #0
    bne lbl_08011610
    movs r0, #0
    b lbl_08011612
    .align 2, 0
lbl_08011604: .4byte 0x03000738
lbl_08011608: .4byte 0x030013d4
lbl_0801160c: .4byte 0x03001588
lbl_08011610:
    movs r0, #1
lbl_08011612:
    add sp, #0x10
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start set_sprite_splash_effect
set_sprite_splash_effect: @ 0x08011620
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    adds r6, r3, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r5, r1, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r4, r2, #0
    ldr r0, lbl_08011648 @ =0x030000dc
    ldrh r0, [r0, #2]
    cmp r0, #3
    bgt lbl_0801164c
    cmp r0, #2
    bge lbl_08011678
    cmp r0, #1
    beq lbl_08011652
    b lbl_080116c4
    .align 2, 0
lbl_08011648: .4byte 0x030000dc
lbl_0801164c:
    cmp r0, #4
    beq lbl_0801169e
    b lbl_080116c4
lbl_08011652:
    cmp r2, #1
    bne lbl_08011660
    adds r0, r3, #0
    movs r2, #0
    bl set_particle_effect
    b lbl_080116c4
lbl_08011660:
    cmp r2, #2
    bne lbl_0801166e
    adds r0, r3, #0
    movs r2, #1
    bl set_particle_effect
    b lbl_080116c4
lbl_0801166e:
    adds r0, r3, #0
    movs r2, #2
    bl set_particle_effect
    b lbl_080116c4
lbl_08011678:
    cmp r2, #1
    bne lbl_08011686
    adds r0, r3, #0
    movs r2, #3
    bl set_particle_effect
    b lbl_080116c4
lbl_08011686:
    cmp r2, #2
    bne lbl_08011694
    adds r0, r3, #0
    movs r2, #4
    bl set_particle_effect
    b lbl_080116c4
lbl_08011694:
    adds r0, r3, #0
    movs r2, #5
    bl set_particle_effect
    b lbl_080116c4
lbl_0801169e:
    cmp r2, #1
    bne lbl_080116ac
    adds r0, r3, #0
    movs r2, #6
    bl set_particle_effect
    b lbl_080116c4
lbl_080116ac:
    cmp r4, #2
    bne lbl_080116ba
    adds r0, r3, #0
    movs r2, #7
    bl set_particle_effect
    b lbl_080116c4
lbl_080116ba:
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #8
    bl set_particle_effect
lbl_080116c4:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sprite_check_out_of_room_effect
sprite_check_out_of_room_effect: @ 0x080116cc
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r5, r3, #0x18
    ldr r1, lbl_0801170c @ =0x0300006c
    ldrh r1, [r1]
    cmp r0, r1
    bls lbl_08011710
    cmp r4, r1
    bhi lbl_08011710
    cmp r5, #0
    beq lbl_08011706
    adds r0, r4, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r6, #0
    bl check_collision_at_pos_noglobal
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r5, #0
    bl set_sprite_splash_effect
lbl_08011706:
    movs r0, #1
    b lbl_08011712
    .align 2, 0
lbl_0801170c: .4byte 0x0300006c
lbl_08011710:
    movs r0, #0
lbl_08011712:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sprite_check_in_room_effect
sprite_check_in_room_effect: @ 0x08011718
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r5, r3, #0x18
    ldr r1, lbl_08011750 @ =0x0300006c
    ldrh r1, [r1]
    cmp r0, r1
    bhs lbl_08011754
    cmp r4, r1
    blo lbl_08011754
    cmp r5, #0
    beq lbl_0801174c
    adds r0, r4, #0
    adds r1, r6, #0
    bl check_collision_at_pos_noglobal
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r5, #0
    bl set_sprite_splash_effect
lbl_0801174c:
    movs r0, #1
    b lbl_08011756
    .align 2, 0
lbl_08011750: .4byte 0x0300006c
lbl_08011754:
    movs r0, #0
lbl_08011756:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start get_final_completion_percentage
get_final_completion_percentage: @ 0x0801175c
    push {r4, r5, lr}
    bl get_percent_and_ending_number
    lsrs r1, r0, #0x18
    lsrs r4, r0, #0x10
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    lsrs r5, r0, #0xc
    movs r2, #0xf
    ands r5, r2
    lsrs r3, r0, #8
    ands r3, r2
    lsrs r0, r0, #4
    ands r0, r2
    adds r1, r1, r4
    adds r1, r1, r5
    adds r1, r1, r3
    adds r1, r1, r0
    adds r0, r1, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start set_debris_splash_effect
set_debris_splash_effect: @ 0x08011788
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldr r1, lbl_080117b0 @ =0x0300006c
    ldrh r1, [r1]
    cmp r0, r1
    bhs lbl_080117ac
    cmp r3, r1
    blo lbl_080117ac
    adds r0, r3, #0
    adds r1, r2, #0
    movs r2, #1
    bl set_sprite_splash_effect
lbl_080117ac:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080117b0: .4byte 0x0300006c


