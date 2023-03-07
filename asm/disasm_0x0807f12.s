    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_0807f120
sub_0807f120: @ 0x0807f120
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    movs r3, #0
    cmp r3, r4
    bge lbl_0807f140
lbl_0807f130:
    adds r2, r6, r3
    ldrb r1, [r2]
    adds r0, r5, #0
    eors r0, r1
    strb r0, [r2]
    adds r3, #1
    cmp r3, r4
    blt lbl_0807f130
lbl_0807f140:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start get_value_from_seed
get_value_from_seed: @ 0x0807f148
    push {lr}
    adds r3, r0, #0
    adds r2, r1, #0
    adds r0, r2, #0
    cmp r2, #0
    bge lbl_0807f156
    adds r0, r2, #7
lbl_0807f156:
    asrs r0, r0, #3
    lsls r1, r0, #3
    subs r1, r2, r1
    adds r0, r3, r0
    ldrb r0, [r0]
    lsls r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x1f
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0807f16c
sub_0807f16c: @ 0x0807f16c
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r0, r1, #0
    adds r3, r2, #0
    movs r4, #1
    ands r3, r4
    adds r2, r0, #0
    cmp r0, #0
    bge lbl_0807f180
    adds r2, r0, #7
lbl_0807f180:
    asrs r2, r2, #3
    lsls r1, r2, #3
    subs r1, r0, r1
    movs r0, #7
    subs r0, r0, r1
    lsls r3, r0
    lsls r4, r0
    lsls r0, r4, #0x18
    lsrs r4, r0, #0x18
    adds r2, r5, r2
    ldrb r0, [r2]
    bics r0, r4
    orrs r0, r3
    strb r0, [r2]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f1a4
sub_0807f1a4: @ 0x0807f1a4
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    bl get_value_from_seed
    mov r8, r0
    adds r0, r4, #0
    adds r1, r6, #0
    bl get_value_from_seed
    adds r2, r0, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f16c
    adds r0, r4, #0
    adds r1, r6, #0
    mov r2, r8
    bl sub_0807f16c
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f1dc
sub_0807f1dc: @ 0x0807f1dc
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    lsls r5, r1, #2
    movs r4, #0
    cmp r4, r5
    bge lbl_0807f1f8
lbl_0807f1e8:
    adds r2, r4, r5
    adds r0, r6, #0
    adds r1, r4, #0
    bl sub_0807f1a4
    adds r4, #2
    cmp r4, r5
    blt lbl_0807f1e8
lbl_0807f1f8:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f200
sub_0807f200: @ 0x0807f200
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    lsls r6, r1, #2
    lsls r1, r1, #3
    subs r5, r1, #1
    movs r4, #0
    cmp r4, r6
    bge lbl_0807f222
lbl_0807f210:
    adds r0, r7, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_0807f1a4
    adds r4, #1
    subs r5, #1
    cmp r4, r6
    blt lbl_0807f210
lbl_0807f222:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f228
sub_0807f228: @ 0x0807f228
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    lsls r0, r1, #3
    movs r1, #9
    bl __divsi3
    adds r6, r0, #0
    adds r5, r6, #0
    movs r4, #0
    cmp r4, r6
    bge lbl_0807f250
lbl_0807f23e:
    adds r0, r7, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_0807f1a4
    adds r4, #1
    adds r5, #8
    cmp r4, r6
    blt lbl_0807f23e
lbl_0807f250:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f258
sub_0807f258: @ 0x0807f258
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    adds r6, r1, #0
    adds r5, r6, #0
    movs r4, #0
    cmp r4, r6
    bge lbl_0807f278
lbl_0807f266:
    adds r0, r7, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_0807f1a4
    adds r4, #1
    adds r5, #7
    cmp r4, r6
    blt lbl_0807f266
lbl_0807f278:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f280
sub_0807f280: @ 0x0807f280
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    lsls r0, r1, #3
    movs r1, #6
    bl __divsi3
    adds r6, r0, #0
    adds r5, r6, #0
    movs r4, #0
    cmp r4, r6
    bge lbl_0807f2a8
lbl_0807f296:
    adds r0, r7, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_0807f1a4
    adds r4, #1
    adds r5, #5
    cmp r4, r6
    blt lbl_0807f296
lbl_0807f2a8:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start generate_time_attack_password
generate_time_attack_password: @ 0x0807f2b0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    adds r7, r0, #0
    mov sb, r1
    cmp r2, #0
    ble lbl_0807f354
    movs r0, #4
    str r0, [sp]
    movs r1, #3
    str r1, [sp, #4]
    movs r0, #2
    str r0, [sp, #8]
    movs r1, #1
    str r1, [sp, #0xc]
    movs r0, #0
    str r0, [sp, #0x10]
    mov sl, r2
lbl_0807f2da:
    adds r0, r7, #0
    ldr r1, [sp, #0x10]
    bl get_value_from_seed
    adds r4, r0, #0
    adds r0, r7, #0
    ldr r1, [sp, #0xc]
    bl get_value_from_seed
    mov r8, r0
    adds r0, r7, #0
    ldr r1, [sp, #8]
    bl get_value_from_seed
    adds r6, r0, #0
    adds r0, r7, #0
    ldr r1, [sp, #4]
    bl get_value_from_seed
    adds r5, r0, #0
    adds r0, r7, #0
    ldr r1, [sp]
    bl get_value_from_seed
    lsls r4, r4, #4
    mov r1, r8
    lsls r1, r1, #3
    orrs r4, r1
    lsls r6, r6, #2
    orrs r4, r6
    lsls r5, r5, #1
    orrs r4, r5
    orrs r4, r0
    ldr r0, lbl_0807f36c @ =0x0845fcf4
    adds r4, r4, r0
    ldrb r0, [r4]
    mov r1, sb
    strb r0, [r1]
    movs r0, #1
    add sb, r0
    ldr r1, [sp]
    adds r1, #5
    str r1, [sp]
    ldr r0, [sp, #4]
    adds r0, #5
    str r0, [sp, #4]
    ldr r1, [sp, #8]
    adds r1, #5
    str r1, [sp, #8]
    ldr r0, [sp, #0xc]
    adds r0, #5
    str r0, [sp, #0xc]
    ldr r1, [sp, #0x10]
    adds r1, #5
    str r1, [sp, #0x10]
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    mov r1, sl
    cmp r1, #0
    bne lbl_0807f2da
lbl_0807f354:
    movs r0, #0
    mov r1, sb
    strb r0, [r1]
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807f36c: .4byte 0x0845fcf4

    thumb_func_start is_save_file_not_legit
is_save_file_not_legit: @ 0x0807f370
    push {r4, r5, lr}
    sub sp, #0x10
    movs r4, #0
    ldr r5, lbl_0807f3e0 @ =0x03000184
lbl_0807f378:
    lsls r2, r4, #2
    mov r0, sp
    adds r3, r0, r2
    adds r2, r2, r5
    ldrb r1, [r2]
    lsls r1, r1, #0x18
    ldrb r0, [r2, #1]
    lsls r0, r0, #0x10
    adds r1, r1, r0
    ldrb r0, [r2, #2]
    lsls r0, r0, #8
    adds r1, r1, r0
    ldrb r0, [r2, #3]
    adds r1, r1, r0
    str r1, [r3]
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bls lbl_0807f378
    movs r4, #0
lbl_0807f3a2:
    adds r1, r4, #1
    lsls r0, r1, #0x18
    lsrs r3, r0, #0x18
    lsls r2, r4, #2
    adds r4, r1, #0
    cmp r3, #3
    bhi lbl_0807f3ca
    mov r1, sp
    adds r0, r1, r2
    ldr r1, [r0]
lbl_0807f3b6:
    lsls r0, r3, #2
    add r0, sp
    ldr r0, [r0]
    cmp r1, r0
    bhs lbl_0807f3da
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #3
    bls lbl_0807f3b6
lbl_0807f3ca:
    mov r0, sp
    adds r1, r0, r2
    ldr r0, lbl_0807f3e4 @ =0x0845fd14
    adds r0, r2, r0
    ldr r1, [r1]
    ldr r0, [r0]
    cmp r1, r0
    bhi lbl_0807f3e8
lbl_0807f3da:
    movs r0, #0
    b lbl_0807f3f2
    .align 2, 0
lbl_0807f3e0: .4byte 0x03000184
lbl_0807f3e4: .4byte 0x0845fd14
lbl_0807f3e8:
    lsls r0, r4, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bls lbl_0807f3a2
    movs r0, #1
lbl_0807f3f2:
    add sp, #0x10
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0807f3fc
sub_0807f3fc: @ 0x0807f3fc
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x30
    ldr r7, lbl_0807f604 @ =0x03000014
    ldr r0, [r7, #8]
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807f414
    b lbl_0807f5f4
lbl_0807f414:
    bl is_save_file_not_legit
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0807f420
    b lbl_0807f5f4
lbl_0807f420:
    bl GetPercentAndEndingNumber
    adds r3, r0, #0
    movs r0, #0xff
    lsrs r1, r3, #0x18
    lsrs r6, r3, #0x10
    ands r6, r0
    lsrs r5, r3, #0xc
    movs r0, #0xf
    ands r5, r0
    lsrs r4, r3, #8
    ands r4, r0
    lsrs r2, r3, #4
    ands r2, r0
    cmp r1, #0xc
    bls lbl_0807f442
    b lbl_0807f5f4
lbl_0807f442:
    cmp r6, #0x32
    bls lbl_0807f448
    b lbl_0807f5f4
lbl_0807f448:
    cmp r5, #0xf
    bls lbl_0807f44e
    b lbl_0807f5f4
lbl_0807f44e:
    cmp r4, #9
    bls lbl_0807f454
    b lbl_0807f5f4
lbl_0807f454:
    cmp r2, #0xe
    bls lbl_0807f45a
    b lbl_0807f5f4
lbl_0807f45a:
    cmp r2, #7
    bhi lbl_0807f460
    b lbl_0807f5f4
lbl_0807f460:
    cmp r6, #0
    bne lbl_0807f466
    b lbl_0807f5f4
lbl_0807f466:
    movs r4, #0
    mov sb, r7
    add r3, sp, #0x10
    movs r1, #0
lbl_0807f46e:
    lsls r0, r4, #2
    add r0, sp
    str r1, [r0]
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bls lbl_0807f46e
    movs r4, #0
    ldr r6, lbl_0807f608 @ =0x03000184
lbl_0807f482:
    lsls r2, r4, #2
    adds r2, r2, r6
    ldrb r1, [r2]
    ldr r0, [sp]
    adds r5, r0, r1
    str r5, [sp]
    ldrb r1, [r2, #1]
    ldr r0, [sp, #4]
    adds r0, r0, r1
    str r0, [sp, #4]
    ldrb r1, [r2, #2]
    ldr r0, [sp, #8]
    adds r0, r0, r1
    str r0, [sp, #8]
    ldrb r1, [r2, #3]
    ldr r0, [sp, #0xc]
    adds r1, r0, r1
    str r1, [sp, #0xc]
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bls lbl_0807f482
    movs r0, #0x1f
    ands r5, r0
    str r5, [sp]
    lsrs r0, r1, #7
    movs r1, #1
    ands r0, r1
    strb r0, [r3]
    ldr r0, [sp, #4]
    movs r2, #1
    ands r0, r2
    strb r0, [r3, #1]
    ldr r0, [sp, #8]
    lsrs r0, r0, #7
    ands r0, r1
    strb r0, [r3, #2]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #6
    ands r0, r1
    strb r0, [r3, #3]
    ldr r0, [sp]
    ands r0, r2
    strb r0, [r3, #4]
    ldr r0, [sp, #4]
    lsrs r0, r0, #1
    ands r0, r1
    strb r0, [r3, #5]
    ldr r0, [sp, #8]
    lsrs r0, r0, #6
    ands r0, r1
    strb r0, [r3, #6]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #5
    ands r0, r1
    strb r0, [r3, #7]
    ldr r0, [sp]
    lsrs r0, r0, #1
    ands r0, r1
    strb r0, [r3, #8]
    ldr r0, [sp, #8]
    lsrs r0, r0, #5
    ands r0, r1
    strb r0, [r3, #9]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #4
    ands r0, r1
    strb r0, [r3, #0xa]
    ldr r0, [sp, #4]
    lsrs r0, r0, #2
    ands r0, r1
    strb r0, [r3, #0xb]
    ldr r0, [sp, #8]
    lsrs r0, r0, #4
    ands r0, r1
    strb r0, [r3, #0xc]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #3
    ands r0, r1
    strb r0, [r3, #0xd]
    ldr r0, [sp]
    lsrs r0, r0, #2
    ands r0, r1
    strb r0, [r3, #0xe]
    ldr r0, [sp, #4]
    lsrs r0, r0, #3
    ands r0, r1
    strb r0, [r3, #0xf]
    ldr r0, [sp, #4]
    lsrs r0, r0, #7
    ands r0, r1
    strb r0, [r3, #0x10]
    ldr r0, [sp, #8]
    lsrs r0, r0, #3
    ands r0, r1
    strb r0, [r3, #0x11]
    ldr r0, [sp]
    lsrs r0, r0, #3
    ands r0, r1
    strb r0, [r3, #0x12]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #2
    ands r0, r1
    strb r0, [r3, #0x13]
    ldr r0, [sp, #8]
    lsrs r0, r0, #2
    ands r0, r1
    strb r0, [r3, #0x14]
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #1
    ands r0, r1
    strb r0, [r3, #0x15]
    ldr r0, [sp, #4]
    lsrs r0, r0, #4
    ands r0, r1
    strb r0, [r3, #0x16]
    ldr r0, [sp, #8]
    lsrs r0, r0, #1
    ands r0, r1
    strb r0, [r3, #0x17]
    ldr r0, [sp, #8]
    ands r0, r2
    strb r0, [r3, #0x18]
    ldr r0, [sp, #0xc]
    ands r0, r2
    strb r0, [r3, #0x19]
    ldr r0, [sp, #4]
    lsrs r0, r0, #6
    ands r0, r1
    strb r0, [r3, #0x1a]
    ldr r0, [sp]
    lsrs r0, r0, #4
    ands r0, r1
    strb r0, [r3, #0x1b]
    ldr r0, [sp, #4]
    lsrs r0, r0, #5
    ands r0, r1
    strb r0, [r3, #0x1c]
    movs r0, #1
    ands r0, r1
    strb r0, [r3, #0x1d]
    movs r0, #2
    ands r0, r2
    strb r0, [r3, #0x1e]
    strb r2, [r3, #0x1f]
    movs r0, #0
    mov r8, r0
    movs r1, #0x18
    mov ip, r1
    movs r4, #0
    adds r7, r3, #0
lbl_0807f5b2:
    movs r3, #0
    movs r2, #7
    movs r1, #0
    adds r6, r4, #1
    mov r5, ip
    subs r5, #8
    lsls r4, r4, #3
lbl_0807f5c0:
    adds r0, r4, r1
    adds r0, r7, r0
    ldrb r0, [r0]
    lsls r0, r2
    adds r3, r3, r0
    subs r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #7
    bls lbl_0807f5c0
    mov r0, ip
    lsls r3, r0
    add r8, r3
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r0, r6, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #3
    bls lbl_0807f5b2
    mov r1, r8
    mov r0, sb
    str r1, [r0, #8]
lbl_0807f5f4:
    add sp, #0x30
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807f604: .4byte 0x03000014
lbl_0807f608: .4byte 0x03000184

    thumb_func_start sub_0807f60c
sub_0807f60c: @ 0x0807f60c
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    ldr r0, lbl_0807f620 @ =0x03000014
    ldr r1, [r0, #8]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0807f624
    movs r0, #0
    b lbl_0807f688
    .align 2, 0
lbl_0807f620: .4byte 0x03000014
lbl_0807f624:
    adds r3, r1, #0
    movs r4, #0
    movs r2, #0x1f
    movs r1, #0
    movs r5, #1
lbl_0807f62e:
    adds r0, r3, #0
    lsrs r0, r1
    ands r0, r5
    lsls r0, r2
    adds r4, r4, r0
    subs r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x1f
    bls lbl_0807f62e
    lsls r0, r4, #3
    lsrs r4, r0, #6
    ldr r3, lbl_0807f690 @ =0x00989680
    movs r1, #0
lbl_0807f650:
    movs r2, #0
    adds r5, r1, #1
    cmp r4, r3
    blo lbl_0807f664
lbl_0807f658:
    subs r4, r4, r3
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r4, r3
    bhs lbl_0807f658
lbl_0807f664:
    adds r1, r6, r1
    adds r0, r2, #0
    adds r0, #0x30
    strb r0, [r1]
    adds r0, r3, #0
    movs r1, #0xa
    bl __udivsi3
    adds r3, r0, #0
    lsls r0, r5, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #6
    bls lbl_0807f650
    adds r1, r6, r1
    adds r0, r4, #0
    adds r0, #0x30
    strb r0, [r1]
    movs r0, #1
lbl_0807f688:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807f690: .4byte 0x00989680

    thumb_func_start sub_0807f694
sub_0807f694: @ 0x0807f694
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x46
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x49
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f6d8
sub_0807f6d8: @ 0x0807f6d8
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x90
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x5e
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f71c
sub_0807f71c: @ 0x0807f71c
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x91
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0xe3
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f760
sub_0807f760: @ 0x0807f760
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x59
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x63
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x39
    bl sub_0807f120
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f7b0
sub_0807f7b0: @ 0x0807f7b0
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x95
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0xfc
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0807f7f4
sub_0807f7f4: @ 0x0807f7f4
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x4d
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x4a
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x53
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f844
sub_0807f844: @ 0x0807f844
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x41
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x59
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x4f
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807f89c
sub_0807f89c: @ 0x0807f89c
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    movs r2, #0x54
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f228
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x4f
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f1dc
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f200
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x4d
    bl sub_0807f120
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f258
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_0807f280
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start randomize_time_attack_password_seed
randomize_time_attack_password_seed: @ 0x0807f8fc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldrb r4, [r0]
    movs r2, #0x80
    mov ip, r2
    movs r3, #0x80
    ands r3, r4
    ldrb r5, [r0, #4]
    movs r2, #0x40
    ands r2, r5
    orrs r3, r2
    ldrb r6, [r0, #8]
    movs r7, #0x20
    mov sl, r7
    movs r2, #0x20
    ands r2, r6
    orrs r3, r2
    ldrb r2, [r0, #0xa]
    mov r8, r2
    movs r7, #0x10
    mov sb, r7
    movs r2, #0x10
    mov r7, r8
    ands r2, r7
    orrs r3, r2
    strb r3, [r0, #0xc]
    movs r3, #0x7f
    ands r3, r4
    movs r4, #0xbf
    ands r4, r5
    movs r5, #0xdf
    ands r5, r6
    movs r6, #0xef
    mov r2, r8
    ands r6, r2
    lsls r1, r1, #4
    adds r2, r1, #0
    mov r7, ip
    ands r2, r7
    orrs r3, r2
    strb r3, [r0]
    adds r2, r1, #0
    movs r3, #0x40
    ands r2, r3
    orrs r4, r2
    strb r4, [r0, #4]
    adds r2, r1, #0
    mov r7, sl
    ands r2, r7
    orrs r5, r2
    strb r5, [r0, #8]
    mov r2, sb
    ands r1, r2
    orrs r6, r1
    strb r6, [r0, #0xa]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start generate_time_attack_password_seed
generate_time_attack_password_seed: @ 0x0807f980
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    adds r7, r0, #0
    movs r5, #0
    movs r4, #1
    adds r6, r7, #0
    adds r6, #0x25
    mov ip, r6
    movs r3, #0x1f
lbl_0807f99a:
    mov r0, ip
    adds r2, r0, r5
    ldr r1, [r7]
    ands r1, r4
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    strb r0, [r2]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807f99a
    movs r4, #1
    movs r1, #0x10
    adds r1, r1, r7
    mov sl, r1
    adds r2, r6, #0
    movs r3, #6
lbl_0807f9c0:
    adds r1, r2, r5
    ldrb r0, [r7, #4]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807f9c0
    movs r4, #1
    adds r2, r6, #0
    movs r3, #5
lbl_0807f9dc:
    adds r1, r2, r5
    ldrb r0, [r7, #5]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807f9dc
    movs r4, #1
    adds r2, r6, #0
    movs r3, #5
lbl_0807f9f8:
    adds r1, r2, r5
    ldrb r0, [r7, #6]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807f9f8
    movs r4, #1
    adds r2, r6, #0
    movs r3, #5
lbl_0807fa14:
    adds r1, r2, r5
    ldrb r0, [r7, #7]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fa14
    movs r4, #1
    adds r2, r6, #0
    movs r3, #4
lbl_0807fa30:
    adds r1, r2, r5
    ldrb r0, [r7, #8]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fa30
    movs r4, #1
    adds r2, r6, #0
    movs r3, #3
lbl_0807fa4c:
    adds r1, r2, r5
    ldrb r0, [r7, #9]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fa4c
    movs r4, #1
    adds r2, r6, #0
    movs r3, #3
lbl_0807fa68:
    adds r1, r2, r5
    ldrb r0, [r7, #0xa]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fa68
    movs r4, #1
    adds r1, r6, r5
    ldrb r0, [r7, #0xb]
    ands r0, r4
    strb r0, [r1]
    adds r5, #1
    adds r1, r6, r5
    ldrb r0, [r7, #0xc]
    ands r0, r4
    strb r0, [r1]
    adds r5, #1
    adds r2, r6, #0
    movs r3, #7
lbl_0807fa98:
    adds r1, r2, r5
    ldrb r0, [r7, #0xd]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fa98
    movs r4, #1
    adds r2, r6, #0
    movs r3, #7
lbl_0807fab4:
    adds r1, r2, r5
    ldrb r0, [r7, #0xe]
    ands r0, r4
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r1]
    lsls r4, r4, #1
    adds r5, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fab4
    movs r2, #0
    mov ip, r2
    movs r5, #0
    ldrb r3, [r7, #0xf]
    mov sb, r3
    mov r8, r6
lbl_0807fad6:
    movs r4, #0
    movs r1, #0
    adds r6, r5, #1
    lsls r0, r5, #3
    mov r3, r8
    adds r2, r0, r3
    movs r3, #7
lbl_0807fae4:
    ldrb r0, [r2]
    lsls r0, r4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r4, #1
    adds r2, #1
    subs r3, #1
    cmp r3, #0
    bge lbl_0807fae4
    mov r2, sp
    adds r0, r2, r5
    strb r1, [r0]
    add ip, r1
    adds r5, r6, #0
    cmp r6, #0xa
    ble lbl_0807fad6
    adds r0, r2, r6
    mov r3, ip
    strb r3, [r0]
    mov r1, sb
    lsls r0, r1, #2
    ldr r2, lbl_0807fb44 @ =0x08760c68
    adds r0, r0, r2
    ldr r2, [r0]
    mov r0, sp
    movs r1, #0xc
    bl _call_via_r2
    ldrb r1, [r7, #0xf]
    mov r0, sp
    bl randomize_time_attack_password_seed
    mov r0, sp
    mov r1, sl
    movs r2, #0x14
    bl generate_time_attack_password
    movs r0, #0
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807fb44: .4byte 0x08760c68

    thumb_func_start check_set_new_time_attack_record
check_set_new_time_attack_record: @ 0x0807fb48
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r2, lbl_0807fbf8 @ =0x03000150
    ldrb r1, [r2]
    lsls r1, r1, #0x18
    ldrb r0, [r2, #1]
    lsls r0, r0, #0x10
    adds r1, r1, r0
    ldrb r0, [r2, #2]
    lsls r0, r0, #8
    adds r6, r1, r0
    ldr r2, lbl_0807fbfc @ =0x03001694
    ldrb r1, [r2, #0x14]
    lsls r1, r1, #0x18
    ldrb r0, [r2, #0x15]
    lsls r0, r0, #0x10
    adds r1, r1, r0
    ldrb r0, [r2, #0x16]
    lsls r0, r0, #8
    adds r1, r1, r0
    str r1, [sp, #8]
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r1, [r0]
    lsls r1, r1, #0x18
    adds r0, #1
    ldrb r0, [r0]
    lsls r0, r0, #0x10
    adds r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    lsls r0, r0, #8
    adds r5, r1, r0
    bl GetPercentAndEndingNumber
    movs r1, #0xff
    lsrs r2, r0, #0x18
    mov sl, r2
    lsrs r7, r0, #0x10
    ands r7, r1
    lsrs r1, r0, #0xc
    mov sb, r1
    movs r1, #0xf
    mov r2, sb
    ands r2, r1
    mov sb, r2
    lsrs r2, r0, #8
    ands r2, r1
    mov r8, r2
    lsrs r4, r0, #4
    ands r4, r1
    mov r1, sl
    adds r0, r1, r7
    add r0, sb
    add r0, r8
    adds r0, r0, r4
    movs r2, #0
    str r2, [sp, #4]
    cmp r4, #0xd
    bls lbl_0807fbce
    movs r1, #1
    str r1, [sp, #4]
lbl_0807fbce:
    movs r2, #0
    str r2, [sp]
    ldr r1, [sp, #8]
    cmp r6, r1
    bhs lbl_0807fbdc
    movs r2, #1
    str r2, [sp]
lbl_0807fbdc:
    cmp r0, #0x63
    bls lbl_0807fbec
    cmp r6, r5
    bhs lbl_0807fbec
    movs r0, #2
    ldr r1, [sp]
    orrs r1, r0
    str r1, [sp]
lbl_0807fbec:
    ldr r2, [sp]
    cmp r2, #0
    bne lbl_0807fc00
    movs r0, #0
    b lbl_0807fd38
    .align 2, 0
lbl_0807fbf8: .4byte 0x03000150
lbl_0807fbfc: .4byte 0x03001694
lbl_0807fc00:
    movs r0, #0
    mov ip, r0
    ldr r0, lbl_0807fd48 @ =0x03000014
    ldr r0, [r0, #8]
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807fc1a
    bl is_save_file_not_legit
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
lbl_0807fc1a:
    mov r1, sl
    cmp r1, #0xc
    bhi lbl_0807fc3c
    cmp r7, #0x32
    bhi lbl_0807fc3c
    mov r2, sb
    cmp r2, #0xf
    bhi lbl_0807fc3c
    mov r0, r8
    cmp r0, #9
    bhi lbl_0807fc3c
    cmp r4, #0xe
    bhi lbl_0807fc3c
    cmp r4, #7
    bls lbl_0807fc3c
    cmp r7, #0
    bne lbl_0807fc40
lbl_0807fc3c:
    movs r1, #0
    mov ip, r1
lbl_0807fc40:
    ldr r5, lbl_0807fd4c @ =0x03000184
    ldrb r0, [r5, #3]
    movs r3, #0xf
    adds r4, r3, #0
    ands r4, r0
    lsls r4, r4, #4
    ldrb r1, [r5, #0xb]
    adds r0, r3, #0
    ands r0, r1
    orrs r4, r0
    ldrb r0, [r5, #0xf]
    adds r2, r3, #0
    ands r2, r0
    lsls r2, r2, #4
    ldrb r1, [r5, #7]
    adds r0, r3, #0
    ands r0, r1
    orrs r2, r0
    ldr r6, lbl_0807fd50 @ =0x0300160c
    ldr r0, lbl_0807fd48 @ =0x03000014
    ldr r0, [r0, #8]
    str r0, [r6]
    ldr r5, lbl_0807fd54 @ =0x03000150
    ldrb r0, [r5]
    strb r0, [r6, #4]
    ldrb r0, [r5, #1]
    strb r0, [r6, #5]
    ldrb r0, [r5, #2]
    strb r0, [r6, #6]
    strb r7, [r6, #7]
    mov r0, sb
    strb r0, [r6, #8]
    mov r1, r8
    strb r1, [r6, #9]
    mov r0, sl
    strb r0, [r6, #0xa]
    mov r1, sp
    ldrb r1, [r1, #4]
    strb r1, [r6, #0xb]
    mov r0, ip
    strb r0, [r6, #0xc]
    strb r4, [r6, #0xd]
    strb r2, [r6, #0xe]
    ldr r0, lbl_0807fd58 @ =0x03000c77
    ldrb r0, [r0]
    ands r3, r0
    strb r3, [r6, #0xf]
    adds r0, r6, #0
    bl generate_time_attack_password_seed
    movs r0, #1
    ldr r1, [sp]
    ands r0, r1
    cmp r0, #0
    beq lbl_0807fcda
    movs r2, #0
    ldr r3, lbl_0807fd5c @ =0x03001694
    adds r4, r3, #0
    adds r7, r6, #0
    adds r7, #0x10
lbl_0807fcb8:
    adds r1, r2, r4
    adds r0, r7, r2
    ldrb r0, [r0]
    strb r0, [r1]
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x13
    bls lbl_0807fcb8
    ldrb r0, [r5]
    strb r0, [r3, #0x14]
    ldrb r0, [r5, #1]
    strb r0, [r3, #0x15]
    ldrb r0, [r5, #2]
    strb r0, [r3, #0x16]
    ldrb r0, [r5, #3]
    strb r0, [r3, #0x17]
lbl_0807fcda:
    movs r0, #2
    ldr r2, [sp]
    ands r0, r2
    cmp r0, #0
    beq lbl_0807fd22
    movs r2, #0
    ldr r5, lbl_0807fd54 @ =0x03000150
    ldr r3, lbl_0807fd5c @ =0x03001694
    adds r7, r3, #0
    adds r7, #0x18
    adds r4, r6, #0
    adds r4, #0x10
lbl_0807fcf2:
    adds r1, r2, r7
    adds r0, r4, r2
    ldrb r0, [r0]
    strb r0, [r1]
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x13
    bls lbl_0807fcf2
    ldrb r1, [r5]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r1, [r0]
    ldrb r0, [r5, #1]
    adds r1, r3, #0
    adds r1, #0x2d
    strb r0, [r1]
    ldrb r0, [r5, #2]
    adds r1, #1
    strb r0, [r1]
    ldrb r1, [r5, #3]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r1, [r0]
lbl_0807fd22:
    ldr r0, [sp]
    cmp r0, #0
    beq lbl_0807fd36
    bl backup_time_attack_for_sram
    ldr r0, lbl_0807fd60 @ =0x03001604
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_0807fd36:
    movs r0, #1
lbl_0807fd38:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807fd48: .4byte 0x03000014
lbl_0807fd4c: .4byte 0x03000184
lbl_0807fd50: .4byte 0x0300160c
lbl_0807fd54: .4byte 0x03000150
lbl_0807fd58: .4byte 0x03000c77
lbl_0807fd5c: .4byte 0x03001694
lbl_0807fd60: .4byte 0x03001604

    thumb_func_start ProcessComplexOam
ProcessComplexOam: @ 0x0807fd64
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    str r0, [sp]
    ldr r4, [sp, #0x30]
    ldr r0, [sp, #0x34]
    mov r8, r0
    ldr r0, [sp, #0x38]
    lsls r1, r1, #0x10
    lsls r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    mov r5, r8
    lsls r5, r5, #0x18
    mov r8, r5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #4]
    movs r0, #0x80
    lsls r0, r0, #0xf
    adds r1, r1, r0
    asrs r1, r1, #0x10
    str r1, [sp, #8]
    adds r2, r2, r0
    asrs r2, r2, #0x10
    str r2, [sp, #0xc]
    ldr r1, [sp]
    lsls r0, r1, #3
    ldr r5, lbl_0807fe84 @ =0x03000e7c
    adds r7, r0, r5
    ldrb r0, [r7, #1]
    mov sb, r0
    mov r1, sb
    lsrs r2, r1, #6
    ldrb r0, [r7, #3]
    lsrs r0, r0, #6
    ldr r1, lbl_0807fe88 @ =0x0845fd24
    lsls r2, r2, #2
    adds r0, r0, r2
    adds r1, r0, r1
    ldrb r1, [r1]
    mov ip, r1
    ldr r1, lbl_0807fe8c @ =0x0845fd30
    adds r0, r0, r1
    ldrb r0, [r0]
    mov sl, r0
    ldrh r0, [r7, #2]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x17
    ldr r1, [sp, #8]
    adds r5, r0, r1
    ldr r1, lbl_0807fe90 @ =0x000001ff
    adds r0, r1, #0
    ands r5, r0
    ldrb r0, [r7]
    ldr r1, [sp, #0xc]
    adds r6, r0, r1
    movs r0, #0xff
    ands r6, r0
    ldr r1, [sp, #8]
    subs r0, r5, r1
    add r0, ip
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    ldr r1, [sp, #0xc]
    subs r2, r6, r1
    add r2, sl
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    adds r1, r0, #0
    muls r1, r4, r1
    asrs r1, r1, #8
    subs r1, r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r2, #0
    muls r0, r4, r0
    asrs r0, r0, #8
    subs r0, r0, r2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    adds r1, r5, r1
    lsls r1, r1, #0x10
    asrs r5, r1, #0x10
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    ldr r0, [sp, #8]
    subs r4, r5, r0
    add r4, ip
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r1, [sp, #0xc]
    subs r2, r6, r1
    add r2, sl
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    ldr r5, lbl_0807fe94 @ =0x0808c71c
    adds r0, r3, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r5
    movs r1, #0
    ldrsh r6, [r0, r1]
    adds r1, r4, #0
    muls r1, r6, r1
    lsls r3, r3, #1
    adds r3, r3, r5
    movs r5, #0
    ldrsh r3, [r3, r5]
    adds r0, r2, #0
    muls r0, r3, r0
    subs r1, r1, r0
    lsls r1, r1, #8
    asrs r5, r1, #0x10
    adds r0, r4, #0
    muls r0, r3, r0
    adds r1, r2, #0
    muls r1, r6, r1
    adds r0, r0, r1
    lsls r0, r0, #8
    asrs r6, r0, #0x10
    mov r0, r8
    cmp r0, #0
    bne lbl_0807fe98
    movs r0, #4
    rsbs r0, r0, #0
    mov r1, sb
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r7, #1]
    mov r1, ip
    subs r0, r5, r1
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    mov r1, sl
    subs r0, r6, r1
    b lbl_0807feb0
    .align 2, 0
lbl_0807fe84: .4byte 0x03000e7c
lbl_0807fe88: .4byte 0x0845fd24
lbl_0807fe8c: .4byte 0x0845fd30
lbl_0807fe90: .4byte 0x000001ff
lbl_0807fe94: .4byte 0x0808c71c
lbl_0807fe98:
    movs r0, #3
    mov r1, sb
    orrs r0, r1
    strb r0, [r7, #1]
    mov r1, ip
    lsls r0, r1, #1
    subs r0, r5, r0
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    mov r1, sl
    lsls r0, r1, #1
    subs r0, r6, r0
lbl_0807feb0:
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    ldr r0, [sp]
    lsls r3, r0, #3
    ldr r1, lbl_0807feec @ =0x03000e7c
    adds r7, r3, r1
    ldr r0, [sp, #8]
    adds r1, r5, r0
    subs r1, #0x40
    ldr r0, lbl_0807fef0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r7, #2]
    ldr r0, lbl_0807fef4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #2]
    ldr r1, [sp, #0xc]
    adds r0, r6, r1
    subs r0, #0x40
    strb r0, [r7]
    ldrb r4, [r7, #3]
    lsls r0, r4, #0x1b
    cmp r0, #0
    bge lbl_0807fefe
    lsls r0, r4, #0x1a
    cmp r0, #0
    bge lbl_0807fef8
    ldr r0, [sp, #4]
    adds r0, #3
    b lbl_0807ff08
    .align 2, 0
lbl_0807feec: .4byte 0x03000e7c
lbl_0807fef0: .4byte 0x000001ff
lbl_0807fef4: .4byte 0xfffffe00
lbl_0807fef8:
    ldr r0, [sp, #4]
    adds r0, #1
    b lbl_0807ff08
lbl_0807fefe:
    lsls r0, r4, #0x1a
    cmp r0, #0
    bge lbl_0807ff1a
    ldr r0, [sp, #4]
    adds r0, #2
lbl_0807ff08:
    movs r1, #7
    ands r0, r1
    lsls r0, r0, #1
    movs r1, #0xf
    rsbs r1, r1, #0
    ands r1, r4
    orrs r1, r0
    strb r1, [r7, #3]
    b lbl_0807ff2c
lbl_0807ff1a:
    movs r0, #7
    ldr r1, [sp, #4]
    ands r1, r0
    lsls r1, r1, #1
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r4
    orrs r0, r1
    strb r0, [r7, #3]
lbl_0807ff2c:
    ldr r5, lbl_0807ff54 @ =0x03000e7c
    adds r2, r3, r5
    ldrb r1, [r2, #3]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r0, r1
    strb r0, [r2, #3]
    movs r0, #0
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807ff54: .4byte 0x03000e7c

    thumb_func_start CalculateOamPart4
CalculateOamPart4: @ 0x0807ff58
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    lsls r5, r5, #0x10
    asrs r5, r5, #0x10
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    ldr r6, lbl_080800ec @ =0x0808c71c
    adds r0, r4, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r6
    movs r2, #0
    ldrsh r1, [r0, r2]
    str r1, [sp]
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldr r0, [sp]
    bl FixedMultiplication
    mov r8, r0
    mov r3, r8
    lsls r3, r3, #0x10
    asrs r3, r3, #0x10
    mov r8, r3
    lsls r4, r4, #1
    adds r4, r4, r6
    movs r1, #0
    ldrsh r0, [r4, r1]
    mov sl, r0
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, sl
    bl FixedMultiplication
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    str r0, [sp, #4]
    ldrh r4, [r4]
    rsbs r4, r4, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    mov sb, r0
    mov r2, sb
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    mov sb, r2
    rsbs r5, r5, #0
    lsls r5, r5, #0x10
    asrs r5, r5, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldr r0, [sp]
    bl FixedMultiplication
    adds r6, r0, #0
    lsls r6, r6, #0x10
    asrs r6, r6, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, sl
    bl FixedMultiplication
    mov sl, r0
    mov r3, sl
    lsls r3, r3, #0x10
    asrs r3, r3, #0x10
    mov sl, r3
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    ldr r2, lbl_080800f0 @ =0x03000e7c
    lsls r1, r7, #3
    adds r1, r1, r2
    mov r4, r8
    strh r4, [r1, #6]
    adds r1, r7, #1
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sp
    ldrh r3, [r3, #4]
    strh r3, [r1, #6]
    adds r1, r7, #2
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sb
    strh r4, [r1, #6]
    adds r1, r7, #3
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, r8
    strh r3, [r1, #6]
    adds r1, r7, #4
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #5
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sl
    strh r4, [r1, #6]
    adds r1, r7, #6
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sb
    strh r3, [r1, #6]
    adds r1, r7, #7
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, r8
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #8
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #9
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sp
    ldrh r3, [r3, #4]
    strh r3, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xa
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r0, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xb
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xc
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xd
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sl
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xe
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r0, [r1, #6]
    adds r0, r7, #0
    adds r0, #0xf
    lsls r0, r0, #3
    adds r0, r0, r2
    strh r6, [r0, #6]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080800ec: .4byte 0x0808c71c
lbl_080800f0: .4byte 0x03000e7c
