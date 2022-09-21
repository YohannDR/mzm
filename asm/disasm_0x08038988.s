    .include "asm/macros.inc"

    .syntax unified
    
    
    thumb_func_start RuinsTestCalculateDelay
RuinsTestCalculateDelay: @ 0x08038988
    lsls r0, r0, #0x18
    ldr r3, lbl_080389a0 @ =0x0300080c
    ldr r2, lbl_080389a4 @ =0x0808c99c
    ldr r1, lbl_080389a8 @ =0x03000c77
    ldrb r1, [r1]
    adds r1, r1, r2
    lsrs r0, r0, #0x18
    ldrb r1, [r1]
    adds r0, r0, r1
    strh r0, [r3, #8]
    bx lr
    .align 2, 0
lbl_080389a0: .4byte 0x0300080c
lbl_080389a4: .4byte 0x0808c99c
lbl_080389a8: .4byte 0x03000c77

    thumb_func_start RuinsTestChangeCCAA
RuinsTestChangeCCAA: @ 0x080389ac
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    ldr r0, lbl_08038a6c @ =0x0300080c
    ldr r1, lbl_08038a70 @ =0xfffffe60
    adds r4, r1, #0
    ldrh r1, [r0]
    adds r4, r4, r1
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldrh r7, [r0, #2]
    ldr r6, lbl_08038a74 @ =0x03000079
    strb r5, [r6]
    adds r0, r4, #0
    adds r1, r7, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    subs r1, #0x40
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    subs r1, #0x80
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    subs r1, #0xc0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    ldr r0, lbl_08038a78 @ =0xffffff00
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    ldr r0, lbl_08038a7c @ =0xfffffec0
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    ldr r0, lbl_08038a80 @ =0xfffffe80
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    adds r1, #0x40
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    adds r1, #0x80
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r1, r7, #0
    adds r1, #0xc0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r0, #0x80
    lsls r0, r0, #1
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r0, #0xa0
    lsls r0, r0, #1
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r1, r7, r0
    adds r0, r4, #0
    bl ClipdataProcess
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08038a6c: .4byte 0x0300080c
lbl_08038a70: .4byte 0xfffffe60
lbl_08038a74: .4byte 0x03000079
lbl_08038a78: .4byte 0xffffff00
lbl_08038a7c: .4byte 0xfffffec0
lbl_08038a80: .4byte 0xfffffe80

    thumb_func_start ruins_test_move_to_pos
ruins_test_move_to_pos: @ 0x08038a84
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, [sp, #0x20]
    ldr r5, [sp, #0x24]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    lsls r5, r5, #0x10
    lsrs r7, r5, #0x10
    adds r0, r7, #0
    muls r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r2, r8
    bls lbl_08038ad4
    mov r1, r8
    subs r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r1, lbl_08038ad0 @ =0x03000738
    ldrh r2, [r1]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r4, #0
    orrs r0, r2
    b lbl_08038ae4
    .align 2, 0
lbl_08038ad0: .4byte 0x03000738
lbl_08038ad4:
    mov r1, r8
    subs r0, r1, r2
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r1, lbl_08038b04 @ =0x03000738
    ldrh r2, [r1]
    ldr r0, lbl_08038b08 @ =0x0000fbff
    ands r0, r2
lbl_08038ae4:
    strh r0, [r1]
    cmp r3, sb
    bls lbl_08038b0c
    mov r2, sb
    subs r0, r3, r2
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r4, lbl_08038b04 @ =0x03000738
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    b lbl_08038b20
    .align 2, 0
lbl_08038b04: .4byte 0x03000738
lbl_08038b08: .4byte 0x0000fbff
lbl_08038b0c:
    mov r4, sb
    subs r0, r4, r3
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r0, lbl_08038b78 @ =0x03000738
    ldrh r1, [r0]
    ldr r0, lbl_08038b7c @ =0x0000fdff
    ands r0, r1
    ldr r1, lbl_08038b78 @ =0x03000738
    strh r0, [r1]
lbl_08038b20:
    ldr r2, lbl_08038b78 @ =0x03000738
    mov sl, r2
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08038bba
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08038b80
    adds r0, r6, #0
    muls r0, r6, r0
    adds r1, r5, #0
    muls r1, r5, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_08038c40
    lsls r0, r5, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    add r0, r8
    mov r1, sl
    strh r0, [r1, #2]
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    add r0, sb
    mov r2, sl
    strh r0, [r2, #4]
    b lbl_08038c40
    .align 2, 0
lbl_08038b78: .4byte 0x03000738
lbl_08038b7c: .4byte 0x0000fdff
lbl_08038b80:
    adds r0, r6, #0
    muls r0, r6, r0
    adds r1, r5, #0
    muls r1, r5, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_08038c40
    lsls r0, r5, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    mov r1, r8
    subs r0, r1, r0
    mov r2, sl
    strh r0, [r2, #2]
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    add r0, sb
    b lbl_08038bfc
lbl_08038bba:
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08038c02
    adds r0, r6, #0
    muls r0, r6, r0
    adds r1, r5, #0
    muls r1, r5, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_08038c40
    lsls r0, r5, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    add r0, r8
    mov r1, sl
    strh r0, [r1, #2]
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    mov r2, sb
    subs r0, r2, r0
lbl_08038bfc:
    mov r4, sl
    strh r0, [r4, #4]
    b lbl_08038c40
lbl_08038c02:
    adds r0, r6, #0
    muls r0, r6, r0
    adds r1, r5, #0
    muls r1, r5, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_08038c40
    lsls r0, r5, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    mov r1, r8
    subs r0, r1, r0
    ldr r2, lbl_08038c50 @ =0x03000738
    strh r0, [r2, #2]
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    muls r0, r7, r0
    asrs r0, r0, #0xa
    mov r4, sb
    subs r0, r4, r0
    ldr r1, lbl_08038c50 @ =0x03000738
    strh r0, [r1, #4]
lbl_08038c40:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08038c50: .4byte 0x03000738

    thumb_func_start RuinsTestProjectileCollision
RuinsTestProjectileCollision: @ 0x08038c54
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08038cf0 @ =0x0300002c
    ldrb r0, [r0]
    movs r4, #0x19
    cmp r0, #0
    beq lbl_08038c68
    movs r4, #0x32
    cmp r0, #2
    bne lbl_08038c68
    movs r4, #0x64
lbl_08038c68:
    ldr r2, lbl_08038cf4 @ =0x03000738
    ldrh r1, [r2, #2]
    ldrh r3, [r2, #4]
    ldrh r0, [r2, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    ldrh r0, [r2, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    ldrh r0, [r2, #0xe]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrh r0, [r2, #0x10]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r5, r3, #0x10
    ldr r1, lbl_08038cf8 @ =0x03000a2c
    movs r2, #0xe0
    lsls r2, r2, #1
    adds r0, r1, r2
    cmp r1, r0
    bhs lbl_08038d1c
    ldr r3, lbl_08038cfc @ =0x030013d4
lbl_08038c9e:
    ldrb r2, [r1]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    beq lbl_08038d14
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_08038d14
    ldrb r0, [r1, #0x11]
    cmp r0, #1
    bls lbl_08038d14
    ldrb r0, [r1, #0xf]
    cmp r0, #5
    beq lbl_08038cc0
    cmp r0, #0xb
    bne lbl_08038d14
lbl_08038cc0:
    ldrh r0, [r1, #0xa]
    cmp r0, r6
    bls lbl_08038d14
    cmp r0, r5
    bhs lbl_08038d14
    ldrh r0, [r1, #8]
    cmp r0, ip
    bls lbl_08038d14
    cmp r0, r7
    bhs lbl_08038d14
    movs r0, #0xef
    ands r0, r2
    strb r0, [r1]
    ldrb r2, [r3, #6]
    cmp r2, #0
    bne lbl_08038d14
    ldr r1, lbl_08038d00 @ =0x03001530
    ldrh r0, [r1, #6]
    cmp r0, r4
    bls lbl_08038d04
    subs r0, r0, r4
    strh r0, [r1, #6]
    b lbl_08038d06
    .align 2, 0
lbl_08038cf0: .4byte 0x0300002c
lbl_08038cf4: .4byte 0x03000738
lbl_08038cf8: .4byte 0x03000a2c
lbl_08038cfc: .4byte 0x030013d4
lbl_08038d00: .4byte 0x03001530
lbl_08038d04:
    strh r2, [r1, #6]
lbl_08038d06:
    movs r0, #0xff
    strb r0, [r3, #4]
    movs r0, #0xfa
    bl SamusSetPose
    movs r0, #1
    b lbl_08038d1e
lbl_08038d14:
    adds r1, #0x1c
    ldr r0, lbl_08038d24 @ =0x03000bec
    cmp r1, r0
    blo lbl_08038c9e
lbl_08038d1c:
    movs r0, #0
lbl_08038d1e:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08038d24: .4byte 0x03000bec

    thumb_func_start RuinsTestCheckHitByChargedPistol
RuinsTestCheckHitByChargedPistol: @ 0x08038d28
    push {lr}
    ldr r2, lbl_08038d58 @ =0x03000a2c
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08038d64
lbl_08038d36:
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08038d5c
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08038d5c
    ldrb r0, [r2, #0x11]
    cmp r0, #1
    bls lbl_08038d5c
    ldrb r0, [r2, #0xf]
    cmp r0, #0xb
    bne lbl_08038d5c
    movs r0, #1
    b lbl_08038d66
    .align 2, 0
lbl_08038d58: .4byte 0x03000a2c
lbl_08038d5c:
    adds r2, #0x1c
    ldr r0, lbl_08038d6c @ =0x03000bec
    cmp r2, r0
    blo lbl_08038d36
lbl_08038d64:
    movs r0, #0
lbl_08038d66:
    pop {r1}
    bx r1
    .align 2, 0
lbl_08038d6c: .4byte 0x03000bec

    thumb_func_start RuinsTestCheckSymbolShooted
RuinsTestCheckSymbolShooted: @ 0x08038d70
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_08038dd4 @ =0x03000738
    adds r5, r4, #0
    adds r5, #0x2b
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_08038dea
    ldrh r0, [r4, #0x14]
    cmp r0, #0x64
    beq lbl_08038dea
    ldr r0, lbl_08038dd8 @ =0x000001d9
    bl SoundPlay
    ldrh r0, [r4]
    movs r1, #0x80
    lsls r1, r1, #8
    adds r7, r1, #0
    movs r6, #0
    adds r2, r7, #0
    orrs r2, r0
    strh r2, [r4]
    movs r0, #0x64
    strh r0, [r4, #0x14]
    ldr r3, lbl_08038ddc @ =0x0300070c
    ldrh r0, [r3, #0xa]
    adds r0, #1
    strh r0, [r3, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08038de0
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    movs r0, #1
    strb r0, [r3, #0xf]
    strb r0, [r3, #0xd]
    movs r0, #0
    strh r0, [r4, #0x12]
    adds r0, r4, #0
    adds r0, #0x25
    strb r6, [r0]
    orrs r2, r7
    strh r2, [r4]
    ldrb r0, [r5]
    adds r0, #0x3c
    strb r0, [r5]
    movs r0, #1
    b lbl_08038dec
    .align 2, 0
lbl_08038dd4: .4byte 0x03000738
lbl_08038dd8: .4byte 0x000001d9
lbl_08038ddc: .4byte 0x0300070c
lbl_08038de0:
    movs r0, #0x80
    strb r0, [r3, #0xd]
    movs r0, #0xf0
    bl RuinsTestCalculateDelay
lbl_08038dea:
    movs r0, #0
lbl_08038dec:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start RuinsTestCheckSamusHurting
RuinsTestCheckSamusHurting: @ 0x08038df4
    push {lr}
    ldr r2, lbl_08038e10 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08038e1e
    ldr r0, lbl_08038e14 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x2f
    bne lbl_08038e18
    movs r0, #1
    b lbl_08038e20
    .align 2, 0
lbl_08038e10: .4byte 0x03000738
lbl_08038e14: .4byte 0x030013d4
lbl_08038e18:
    ldr r0, lbl_08038e24 @ =0x0000ffdf
    ands r0, r1
    strh r0, [r2]
lbl_08038e1e:
    movs r0, #0
lbl_08038e20:
    pop {r1}
    bx r1
    .align 2, 0
lbl_08038e24: .4byte 0x0000ffdf

    thumb_func_start sub_08038e28
sub_08038e28: @ 0x08038e28
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r4, lbl_08038e4c @ =0x0300070c
    ldrb r1, [r4, #0xd]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08038eac
    cmp r1, #1
    bne lbl_08038e50
    bl RuinsTestCheckHitByChargedPistol
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08038e54
    ldrb r0, [r4, #0xd]
    subs r0, #1
    b lbl_08038e52
    .align 2, 0
lbl_08038e4c: .4byte 0x0300070c
lbl_08038e50:
    subs r0, r1, #1
lbl_08038e52:
    strb r0, [r4, #0xd]
lbl_08038e54:
    ldr r3, lbl_08038e9c @ =0x03000738
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08038f38
    ldr r0, lbl_08038ea0 @ =0x00007fff
    ands r0, r1
    movs r1, #0
    strh r0, [r3]
    ldrb r2, [r3, #0x1f]
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r4, lbl_08038ea4 @ =0x0300070c
    ldrh r0, [r4, #6]
    str r0, [sp]
    ldrh r0, [r4, #8]
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0x40
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x17
    bhi lbl_08038f38
    ldr r0, lbl_08038ea8 @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r0, [r4, #0xa]
    strh r0, [r1, #0x14]
    b lbl_08038f38
    .align 2, 0
lbl_08038e9c: .4byte 0x03000738
lbl_08038ea0: .4byte 0x00007fff
lbl_08038ea4: .4byte 0x0300070c
lbl_08038ea8: .4byte 0x030001ac
lbl_08038eac:
    ldr r5, lbl_08038ee8 @ =0x03000738
    ldrh r1, [r5]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08038ec2
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r5]
lbl_08038ec2:
    ldrb r1, [r4, #0xd]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08038f38
    ldr r1, lbl_08038eec @ =0x0300080c
    ldrh r0, [r1, #4]
    cmp r0, #0
    bne lbl_08038ef0
    ldrh r1, [r5]
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r5]
    movs r0, #0xf0
    bl RuinsTestCalculateDelay
    movs r0, #1
    b lbl_08038f3a
    .align 2, 0
lbl_08038ee8: .4byte 0x03000738
lbl_08038eec: .4byte 0x0300080c
lbl_08038ef0:
    ldrh r0, [r1, #8]
    cmp r0, #0
    bne lbl_08038f1c
    ldrh r0, [r4, #0xa]
    cmp r0, #0
    bne lbl_08038f00
    movs r0, #0x78
    b lbl_08038f12
lbl_08038f00:
    cmp r0, #1
    bne lbl_08038f08
    movs r0, #0x5a
    b lbl_08038f12
lbl_08038f08:
    cmp r0, #2
    bne lbl_08038f10
    movs r0, #0x3c
    b lbl_08038f12
lbl_08038f10:
    movs r0, #0x28
lbl_08038f12:
    strb r0, [r4, #0xd]
    movs r0, #0x78
    bl RuinsTestCalculateDelay
    b lbl_08038f38
lbl_08038f1c:
    subs r0, #1
    strh r0, [r1, #8]
    bl RuinsTestProjectileCollision
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08038f38
    ldrh r0, [r5]
    movs r1, #0x20
    orrs r0, r1
    strh r0, [r5]
    movs r0, #0x78
    bl RuinsTestCalculateDelay
lbl_08038f38:
    movs r0, #0
lbl_08038f3a:
    add sp, #0xc
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start RuinsTestGhostMove
RuinsTestGhostMove: @ 0x08038f44
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_08038f64 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r3, r2, #0
    cmp r0, #0
    beq lbl_08038f68
    adds r1, r3, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, r4, r0
    b lbl_08038f70
    .align 2, 0
lbl_08038f64: .4byte 0x03000738
lbl_08038f68:
    adds r1, r3, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, r0, r4
lbl_08038f70:
    strb r0, [r1]
    movs r0, #0x12
    ldrsh r4, [r3, r0]
    adds r0, r3, #0
    adds r0, #0x2d
    ldrb r5, [r0]
    ldr r1, lbl_08038f9c @ =0x0808c71c
    lsls r0, r5, #1
    adds r0, r0, r1
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r2, r0, #0
    cmp r2, #0
    bge lbl_08038fa0
    rsbs r0, r2, #0
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    ldrh r0, [r3, #6]
    subs r0, r0, r2
    b lbl_08038faa
    .align 2, 0
lbl_08038f9c: .4byte 0x0808c71c
lbl_08038fa0:
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r0, r0, #0x10
    ldrh r2, [r3, #6]
    adds r0, r0, r2
lbl_08038faa:
    strh r0, [r3, #2]
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r2, r0, #0
    cmp r2, #0
    bge lbl_08038fcc
    rsbs r0, r2, #0
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    ldrh r0, [r3, #8]
    subs r0, r0, r2
    b lbl_08038fd6
lbl_08038fcc:
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r0, r0, #0x10
    ldrh r2, [r3, #8]
    adds r0, r0, r2
lbl_08038fd6:
    strh r0, [r3, #4]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RuinsTestInit
RuinsTestInit: @ 0x08038fe0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r7, lbl_080390b0 @ =0x03000738
    adds r0, r7, #0
    adds r0, #0x27
    movs r1, #0
    mov r8, r1
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r2, #0
    ldr r1, lbl_080390b4 @ =0x0000ffbc
    strh r1, [r7, #0xa]
    movs r0, #0x44
    strh r0, [r7, #0xc]
    strh r1, [r7, #0xe]
    strh r0, [r7, #0x10]
    ldrh r0, [r7]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r7]
    adds r1, r7, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    subs r1, #3
    movs r0, #0xc
    strb r0, [r1]
    movs r0, #0x64
    strh r0, [r7, #0x14]
    adds r0, r7, #0
    adds r0, #0x33
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_080390b8 @ =0x082f60dc
    str r0, [r7, #0x18]
    mov r0, r8
    strh r0, [r7, #0x16]
    strb r2, [r7, #0x1c]
    adds r0, r7, #0
    adds r0, #0x24
    strb r1, [r0]
    adds r0, #8
    strb r2, [r0]
    ldrh r0, [r7, #2]
    adds r0, #0x10
    strh r0, [r7, #2]
    ldrh r4, [r7, #2]
    ldrh r6, [r7, #4]
    ldr r5, lbl_080390bc @ =0x0300080c
    strh r4, [r5]
    strh r6, [r5, #2]
    strh r4, [r7, #6]
    strh r6, [r7, #8]
    ldr r0, lbl_080390c0 @ =0x0300070c
    strh r4, [r0, #6]
    strh r6, [r0, #8]
    strb r2, [r0, #0xf]
    mov r1, r8
    strh r1, [r0, #0xa]
    strb r2, [r0, #0xd]
    movs r0, #0x78
    bl RuinsTestCalculateDelay
    ldrb r2, [r7, #0x1f]
    adds r0, r7, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r7, #2]
    str r0, [sp]
    ldrh r0, [r7, #4]
    str r0, [sp, #4]
    mov r0, r8
    str r0, [sp, #8]
    movs r0, #0x3b
    movs r1, #0
    bl SpriteSpawnSecondary
    movs r0, #0x3e
    bl SamusSetPose
    ldr r0, lbl_080390c4 @ =0x030013d4
    ldr r1, lbl_080390c8 @ =0x0000012f
    adds r4, r4, r1
    strh r4, [r0, #0x14]
    strh r6, [r0, #0x12]
    mov r3, r8
    strh r3, [r5, #4]
    strh r3, [r5, #6]
    strh r3, [r5, #0xa]
    strh r3, [r5, #0xc]
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080390b0: .4byte 0x03000738
lbl_080390b4: .4byte 0x0000ffbc
lbl_080390b8: .4byte 0x082f60dc
lbl_080390bc: .4byte 0x0300080c
lbl_080390c0: .4byte 0x0300070c
lbl_080390c4: .4byte 0x030013d4
lbl_080390c8: .4byte 0x0000012f

    thumb_func_start sub_080390cc
sub_080390cc: @ 0x080390cc
    push {lr}
    ldr r3, lbl_080390e0 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x2c
    ldrb r2, [r0]
    cmp r2, #0
    bne lbl_080390e4
    strb r2, [r3, #0x1c]
    b lbl_08039100
    .align 2, 0
lbl_080390e0: .4byte 0x03000738
lbl_080390e4:
    cmp r2, #2
    bne lbl_08039100
    ldr r0, lbl_08039104 @ =0x082f5e44
    str r0, [r3, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r3, #0x16]
    strb r1, [r3, #0x1c]
    adds r0, r3, #0
    adds r0, #0x24
    strb r2, [r0]
    ldr r0, lbl_08039108 @ =0x000001d5
    bl SoundPlay
lbl_08039100:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039104: .4byte 0x082f5e44
lbl_08039108: .4byte 0x000001d5

    thumb_func_start RuinsTestTurningIntoReflection
RuinsTestTurningIntoReflection: @ 0x0803910c
    push {lr}
    sub sp, #0xc
    ldr r1, lbl_0803913c @ =0x03000738
    ldrh r0, [r1, #0x16]
    cmp r0, #7
    bne lbl_08039162
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_08039140
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x3d
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_08039162
    .align 2, 0
lbl_0803913c: .4byte 0x03000738
lbl_08039140:
    cmp r0, #4
    bne lbl_08039162
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    adds r0, #0x5c
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x3c
    movs r1, #0
    bl SpriteSpawnSecondary
lbl_08039162:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08039186
    ldr r0, lbl_0803918c @ =0x03000738
    ldr r1, lbl_08039190 @ =0x082f5ec4
    str r1, [r0, #0x18]
    movs r2, #0
    movs r1, #0
    strh r1, [r0, #0x16]
    strb r2, [r0, #0x1c]
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #3
    strb r1, [r2]
    adds r0, #0x2c
    movs r1, #0x20
    strb r1, [r0]
lbl_08039186:
    add sp, #0xc
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803918c: .4byte 0x03000738
lbl_08039190: .4byte 0x082f5ec4

    thumb_func_start sub_08039194
sub_08039194: @ 0x08039194
    push {lr}
    ldr r1, lbl_080391bc @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_080391b8
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_080391b8
    ldr r0, lbl_080391c0 @ =0x030013d4
    strh r2, [r0, #0xc]
    adds r1, #0x24
    movs r0, #4
    strb r0, [r1]
lbl_080391b8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080391bc: .4byte 0x03000738
lbl_080391c0: .4byte 0x030013d4

    thumb_func_start RuinsTestCheckSamusNotFacingBackground
RuinsTestCheckSamusNotFacingBackground: @ 0x080391c4
    push {lr}
    ldr r0, lbl_080391e4 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x3e
    beq lbl_080391de
    ldr r0, lbl_080391e8 @ =0x03000738
    adds r0, #0x24
    movs r1, #8
    strb r1, [r0]
    ldr r1, lbl_080391ec @ =0x0300080c
    movs r0, #0xe1
    lsls r0, r0, #3
    strh r0, [r1, #4]
lbl_080391de:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080391e4: .4byte 0x030013d4
lbl_080391e8: .4byte 0x03000738
lbl_080391ec: .4byte 0x0300080c

    thumb_func_start sub_080391f0
sub_080391f0: @ 0x080391f0
    push {lr}
    bl RuinsTestCheckSamusHurting
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08039226
    bl RuinsTestCheckSymbolShooted
    bl sub_08038e28
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08039212
    ldr r0, lbl_0803922c @ =0x0300070c
    ldrh r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_08039226
lbl_08039212:
    ldr r1, lbl_08039230 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r0, #9
    strb r0, [r2]
    adds r1, #0x2c
    movs r0, #0x78
    strb r0, [r1]
    bl SpriteUtilChooseRandomXDirection
lbl_08039226:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803922c: .4byte 0x0300070c
lbl_08039230: .4byte 0x03000738

    thumb_func_start RuinsTestSpawnGhost
RuinsTestSpawnGhost: @ 0x08039234
    push {r4, lr}
    sub sp, #0xc
    ldr r0, lbl_08039278 @ =0x0300070c
    ldrh r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_08039248
    ldr r0, lbl_0803927c @ =0x0300080c
    ldrh r0, [r0, #0xc]
    cmp r0, #0
    beq lbl_080392ba
lbl_08039248:
    ldr r0, lbl_08039280 @ =0x03000738
    mov ip, r0
    mov r1, ip
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    movs r4, #0
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x54
    bne lbl_08039284
    mov r1, ip
    ldrb r2, [r1, #0x1f]
    mov r0, ip
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x3e
    b lbl_0803929e
    .align 2, 0
lbl_08039278: .4byte 0x0300070c
lbl_0803927c: .4byte 0x0300080c
lbl_08039280: .4byte 0x03000738
lbl_08039284:
    cmp r0, #0x40
    bne lbl_080392a6
    mov r0, ip
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    mov r1, ip
    ldrh r0, [r1, #2]
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x3f
lbl_0803929e:
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_080392ba
lbl_080392a6:
    cmp r0, #0
    bne lbl_080392ba
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    ldr r1, lbl_080392c4 @ =0x0300080c
    movs r0, #0x96
    lsls r0, r0, #3
    strh r0, [r1, #4]
lbl_080392ba:
    add sp, #0xc
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080392c4: .4byte 0x0300080c

    thumb_func_start RuinsTestMovingInit
RuinsTestMovingInit: @ 0x080392c8
    ldr r2, lbl_080392ec @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2d
    movs r1, #0
    movs r0, #0x40
    strb r0, [r3]
    strh r1, [r2, #0x12]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
lbl_080392ec: .4byte 0x03000738

    thumb_func_start RuinsTestMoveCirclePattern
RuinsTestMoveCirclePattern: @ 0x080392f0
    push {r4, r5, r6, r7, lr}
    bl RuinsTestCheckSamusHurting
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080393e4
    bl RuinsTestCheckSymbolShooted
    ldr r0, lbl_0803931c @ =0x0300080c
    ldrh r1, [r0, #4]
    ldr r0, lbl_08039320 @ =0x00000257
    cmp r1, r0
    bhi lbl_08039328
    ldr r0, lbl_08039324 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    movs r3, #1
    cmp r0, #0
    bne lbl_0803932a
    movs r3, #2
    b lbl_0803932a
    .align 2, 0
lbl_0803931c: .4byte 0x0300080c
lbl_08039320: .4byte 0x00000257
lbl_08039324: .4byte 0x03000c77
lbl_08039328:
    movs r3, #1
lbl_0803932a:
    ldr r2, lbl_08039340 @ =0x03000738
    ldrh r0, [r2, #0x12]
    cmp r0, #0xbf
    bhi lbl_08039348
    adds r0, #3
    movs r1, #0
    strh r0, [r2, #0x12]
    ldr r0, lbl_08039344 @ =0x0300080c
    strh r1, [r0, #0xa]
    adds r6, r0, #0
    b lbl_0803934e
    .align 2, 0
lbl_08039340: .4byte 0x03000738
lbl_08039344: .4byte 0x0300080c
lbl_08039348:
    movs r0, #0xc0
    strh r0, [r2, #0x12]
    ldr r6, lbl_080393c4 @ =0x0300080c
lbl_0803934e:
    ldrh r0, [r6, #6]
    cmp r0, #0
    bne lbl_0803935a
    adds r0, r3, #0
    bl RuinsTestGhostMove
lbl_0803935a:
    ldr r5, lbl_080393c8 @ =0x0300070c
    ldr r4, lbl_080393cc @ =0x03000738
    ldrh r0, [r4, #2]
    movs r7, #0
    strh r0, [r5, #6]
    ldrh r0, [r4, #4]
    strh r0, [r5, #8]
    bl sub_08038e28
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08039378
    ldrh r0, [r5, #0xa]
    cmp r0, #1
    bls lbl_080393e4
lbl_08039378:
    ldrh r1, [r4]
    ldr r0, lbl_080393d0 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r4]
    adds r2, r4, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #0x41
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_080393e4
    ldrh r0, [r4, #0x12]
    cmp r0, #0xc0
    bne lbl_080393e4
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x2e
    strb r7, [r0]
    movs r0, #0x96
    lsls r0, r0, #3
    strh r0, [r6, #4]
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080393d4
    strb r7, [r2]
    ldrh r0, [r4, #6]
    subs r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    subs r0, #0xc0
    b lbl_080393e2
    .align 2, 0
lbl_080393c4: .4byte 0x0300080c
lbl_080393c8: .4byte 0x0300070c
lbl_080393cc: .4byte 0x03000738
lbl_080393d0: .4byte 0x0000f7ff
lbl_080393d4:
    movs r0, #0x80
    strb r0, [r2]
    ldrh r0, [r4, #6]
    subs r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    adds r0, #0xc0
lbl_080393e2:
    strh r0, [r4, #8]
lbl_080393e4:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RuinsTestMoveAtomPattern
RuinsTestMoveAtomPattern: @ 0x080393ec
    push {r4, r5, r6, lr}
    ldr r4, lbl_08039430 @ =0x0300080c
    ldrh r0, [r4, #4]
    cmp r0, #0
    bne lbl_080393fa
    adds r0, #1
    strh r0, [r4, #4]
lbl_080393fa:
    movs r5, #0
    bl RuinsTestCheckSamusHurting
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08039408
    b lbl_08039606
lbl_08039408:
    bl RuinsTestCheckSymbolShooted
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08039414
    b lbl_08039606
lbl_08039414:
    ldrh r1, [r4, #4]
    cmp r1, #1
    bhi lbl_08039438
    ldr r0, lbl_08039434 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    movs r1, #2
    cmp r0, #0
    bne lbl_0803942a
    movs r1, #3
lbl_0803942a:
    movs r4, #0xfc
    b lbl_08039450
    .align 2, 0
lbl_08039430: .4byte 0x0300080c
lbl_08039434: .4byte 0x03000c77
lbl_08039438:
    ldr r0, lbl_0803949c @ =0x00000257
    cmp r1, r0
    bls lbl_0803944c
    ldr r0, lbl_080394a0 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    movs r1, #1
    cmp r0, #0
    beq lbl_0803944e
lbl_0803944c:
    movs r1, #2
lbl_0803944e:
    movs r4, #0xfe
lbl_08039450:
    ldr r0, lbl_080394a4 @ =0x0300080c
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_0803945e
    adds r0, r1, #0
    bl RuinsTestGhostMove
lbl_0803945e:
    ldr r0, lbl_080394a8 @ =0x03000738
    movs r1, #0x2d
    adds r1, r1, r0
    mov ip, r1
    ldrb r3, [r1]
    ands r3, r4
    adds r6, r0, #0
    adds r6, #0x2e
    ldrb r2, [r6]
    adds r4, r0, #0
    cmp r2, #0
    bne lbl_080394be
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080394ac
    cmp r3, #0x80
    beq lbl_08039488
    b lbl_080395ea
lbl_08039488:
    movs r0, #0xc0
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    adds r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    subs r0, #0xc0
    b lbl_080395a4
    .align 2, 0
lbl_0803949c: .4byte 0x00000257
lbl_080394a0: .4byte 0x03000c77
lbl_080394a4: .4byte 0x0300080c
lbl_080394a8: .4byte 0x03000738
lbl_080394ac:
    cmp r3, #0
    beq lbl_080394b2
    b lbl_080395ea
lbl_080394b2:
    movs r0, #0xc0
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    adds r0, #0xc0
    b lbl_0803959e
lbl_080394be:
    cmp r2, #1
    bne lbl_080394fa
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_080394e4
    cmp r3, #0x40
    beq lbl_080394d8
    b lbl_080395ea
lbl_080394d8:
    movs r0, #0x80
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    adds r0, #0xc0
    b lbl_0803959e
lbl_080394e4:
    cmp r3, #0x40
    beq lbl_080394ea
    b lbl_080395ea
lbl_080394ea:
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    adds r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    subs r0, #0xc0
    b lbl_080395a4
lbl_080394fa:
    cmp r2, #2
    bne lbl_0803953c
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_08039524
    cmp r3, #0
    bne lbl_080395ea
    movs r0, #0x80
    mov r1, ip
    strb r0, [r1]
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r1, #0
    ldrh r1, [r4, #8]
    adds r0, r0, r1
    b lbl_080395a4
lbl_08039524:
    cmp r3, #0x80
    bne lbl_080395ea
    mov r1, ip
    strb r0, [r1]
    ldr r1, lbl_08039538 @ =0xfffffe80
    adds r0, r1, #0
    ldrh r1, [r4, #8]
    adds r0, r0, r1
    b lbl_080395a4
    .align 2, 0
lbl_08039538: .4byte 0xfffffe80
lbl_0803953c:
    cmp r2, #3
    bne lbl_0803956a
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08039554
    cmp r3, #0
    bne lbl_080395ea
    movs r0, #0x40
    b lbl_08039596
lbl_08039554:
    cmp r3, #0x80
    bne lbl_080395ea
    movs r0, #0x40
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    subs r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    subs r0, #0xc0
    b lbl_080395a4
lbl_0803956a:
    cmp r2, #4
    bne lbl_080395ae
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08039590
    cmp r3, #0xc0
    bne lbl_080395ea
    movs r0, #0
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    subs r0, #0xc0
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    subs r0, #0xc0
    b lbl_080395a4
lbl_08039590:
    cmp r3, #0xc0
    bne lbl_080395ea
    movs r0, #0x80
lbl_08039596:
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #6]
    subs r0, #0xc0
lbl_0803959e:
    strh r0, [r4, #6]
    ldrh r0, [r4, #8]
    adds r0, #0xc0
lbl_080395a4:
    strh r0, [r4, #8]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    b lbl_080395ea
lbl_080395ae:
    cmp r2, #5
    bne lbl_080395ea
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080395d0
    cmp r3, #0x80
    bne lbl_080395ea
    movs r0, #0
    mov r1, ip
    strb r0, [r1]
    ldr r1, lbl_080395cc @ =0xfffffe80
    b lbl_080395de
    .align 2, 0
lbl_080395cc: .4byte 0xfffffe80
lbl_080395d0:
    cmp r3, #0
    bne lbl_080395ea
    movs r0, #0x80
    mov r1, ip
    strb r0, [r1]
    movs r1, #0xc0
    lsls r1, r1, #1
lbl_080395de:
    adds r0, r1, #0
    ldrh r1, [r4, #8]
    adds r0, r0, r1
    movs r1, #0
    strh r0, [r4, #8]
    strb r1, [r6]
lbl_080395ea:
    cmp r5, #0
    beq lbl_080395f8
    adds r1, r4, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_080395f8:
    ldr r0, lbl_0803960c @ =0x0300070c
    ldrh r1, [r4, #2]
    strh r1, [r0, #6]
    ldrh r1, [r4, #4]
    strh r1, [r0, #8]
    bl sub_08038e28
lbl_08039606:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803960c: .4byte 0x0300070c

    thumb_func_start RuinsTestMoveToCenter
RuinsTestMoveToCenter: @ 0x08039610
    push {r4, r5, r6, lr}
    sub sp, #8
    ldr r2, lbl_08039638 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    adds r4, r2, #0
    cmp r0, #0
    bne lbl_08039696
    ldr r0, lbl_0803963c @ =0x0300080c
    ldrh r5, [r0]
    ldrh r6, [r0, #2]
    ldrh r0, [r4, #4]
    cmp r6, r0
    bls lbl_08039640
    subs r0, r6, r0
    b lbl_08039642
    .align 2, 0
lbl_08039638: .4byte 0x03000738
lbl_0803963c: .4byte 0x0300080c
lbl_08039640:
    subs r0, r0, r6
lbl_08039642:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r4, #2]
    cmp r5, r0
    bls lbl_08039650
    subs r0, r5, r0
    b lbl_08039652
lbl_08039650:
    subs r0, r0, r5
lbl_08039652:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, #3
    bhi lbl_08039678
    cmp r0, #3
    bhi lbl_08039678
    strh r5, [r4, #2]
    strh r6, [r4, #4]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x68
    strb r0, [r1]
    ldr r1, lbl_08039674 @ =0x0300070c
    movs r0, #2
    strb r0, [r1, #0xf]
    b lbl_08039696
    .align 2, 0
lbl_08039674: .4byte 0x0300070c
lbl_08039678:
    ldr r1, lbl_080396a0 @ =0x0300070c
    ldrh r0, [r1, #6]
    ldrh r1, [r1, #8]
    ldrh r2, [r4, #0x12]
    adds r3, r2, #1
    strh r3, [r4, #0x12]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp]
    movs r2, #4
    str r2, [sp, #4]
    adds r2, r5, #0
    adds r3, r6, #0
    bl ruins_test_move_to_pos
lbl_08039696:
    add sp, #8
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080396a0: .4byte 0x0300070c

    thumb_func_start sub_080396a4
sub_080396a4: @ 0x080396a4
    push {lr}
    ldr r0, lbl_080396c8 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #4
    bne lbl_080396c4
    ldr r2, lbl_080396cc @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x69
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x64
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x22
    strb r0, [r1]
lbl_080396c4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080396c8: .4byte 0x0300070c
lbl_080396cc: .4byte 0x03000738

    thumb_func_start RuinsTestDespawn
RuinsTestDespawn: @ 0x080396d0
    push {r4, lr}
    sub sp, #0xc
    ldr r1, lbl_080396f8 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08039700
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0803975e
    ldr r0, lbl_080396fc @ =0x082f6064
    str r0, [r1, #0x18]
    movs r0, #0
    strh r2, [r1, #0x16]
    strb r0, [r1, #0x1c]
    b lbl_0803975e
    .align 2, 0
lbl_080396f8: .4byte 0x03000738
lbl_080396fc: .4byte 0x082f6064
lbl_08039700:
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08039734
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0803975e
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    adds r0, #0x5c
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x41
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0803975e
lbl_08039734:
    ldr r0, lbl_08039768 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #5
    bne lbl_0803975e
    adds r1, #0x24
    movs r0, #0x6a
    strb r0, [r1]
    movs r0, #1
    bl RuinsTestChangeCCAA
    movs r0, #1
    movs r1, #0x43
    bl EventFunction
    ldr r1, lbl_0803976c @ =0x03000184
    ldr r0, lbl_08039770 @ =0x03000150
    ldr r0, [r0]
    str r0, [r1, #8]
    movs r0, #4
    bl start_effect_for_cutscene
lbl_0803975e:
    add sp, #0xc
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039768: .4byte 0x0300070c
lbl_0803976c: .4byte 0x03000184
lbl_08039770: .4byte 0x03000150

    thumb_func_start RuinsTestGhostInit
RuinsTestGhostInit: @ 0x08039774
    push {r4, r5, r6, r7, lr}
    ldr r5, lbl_08039808 @ =0x03000738
    ldrh r0, [r5]
    ldr r1, lbl_0803980c @ =0x0000fffb
    ands r1, r0
    movs r6, #0
    movs r7, #0
    strh r1, [r5]
    ldrb r0, [r5, #0x1e]
    cmp r0, #0
    bne lbl_0803981c
    adds r3, r5, #0
    adds r3, #0x27
    movs r0, #0x54
    strb r0, [r3]
    adds r0, r5, #0
    adds r0, #0x28
    movs r4, #0x10
    strb r4, [r0]
    adds r3, #2
    movs r0, #0x38
    strb r0, [r3]
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r5, #0xa]
    movs r0, #0x40
    strh r0, [r5, #0xc]
    ldr r0, lbl_08039810 @ =0x0000ff60
    strh r0, [r5, #0xe]
    movs r0, #0xa0
    strh r0, [r5, #0x10]
    subs r3, #7
    movs r0, #0xd
    strb r0, [r3]
    ldr r0, lbl_08039814 @ =0x082f5d2c
    str r0, [r5, #0x18]
    strh r7, [r5, #0x16]
    strb r6, [r5, #0x1c]
    movs r0, #1
    strh r0, [r5, #0x14]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r1, r0
    adds r2, r5, #0
    adds r2, #0x24
    movs r0, #8
    strb r0, [r2]
    adds r0, r5, #0
    adds r0, #0x25
    strb r6, [r0]
    movs r2, #0x80
    lsls r2, r2, #6
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r5]
    ldr r1, lbl_08039818 @ =0x00002444
    movs r0, #1
    bl TransparencyUpdateBLDCNT
    movs r0, #0x10
    movs r1, #0
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
    adds r0, r5, #0
    adds r0, #0x2c
    strb r6, [r0]
    adds r0, #1
    strb r4, [r0]
    adds r0, #1
    b lbl_0803987a
    .align 2, 0
lbl_08039808: .4byte 0x03000738
lbl_0803980c: .4byte 0x0000fffb
lbl_08039810: .4byte 0x0000ff60
lbl_08039814: .4byte 0x082f5d2c
lbl_08039818: .4byte 0x00002444
lbl_0803981c:
    movs r0, #0x10
    adds r2, r1, #0
    orrs r2, r0
    adds r0, r5, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_08039884 @ =0x0000ffc0
    strh r1, [r5, #0xa]
    movs r0, #0x40
    strh r0, [r5, #0xc]
    strh r1, [r5, #0xe]
    strh r0, [r5, #0x10]
    adds r1, r5, #0
    adds r1, #0x22
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08039888 @ =0x082f5fe4
    str r0, [r5, #0x18]
    strh r7, [r5, #0x16]
    strb r6, [r5, #0x1c]
    movs r1, #0x80
    lsls r1, r1, #8
    adds r0, r1, #0
    orrs r2, r0
    strh r2, [r5]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x25
    strb r6, [r0]
    ldrh r0, [r5, #2]
    strh r0, [r5, #6]
    ldrh r0, [r5, #4]
    strh r0, [r5, #8]
    strh r7, [r5, #0x12]
    adds r1, #8
    movs r0, #4
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x2d
lbl_0803987a:
    strb r6, [r0]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039884: .4byte 0x0000ffc0
lbl_08039888: .4byte 0x082f5fe4

    thumb_func_start RuinsTestGhostSpawn
RuinsTestGhostSpawn: @ 0x0803988c
    push {lr}
    ldr r2, lbl_080398bc @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r1, #0xff
    adds r3, r0, #0
    ands r3, r1
    movs r0, #3
    ands r3, r0
    cmp r3, #0
    bne lbl_080398f4
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_080398c0
    adds r0, #1
    strb r0, [r1]
    ldrb r1, [r1]
    movs r0, #0x10
    b lbl_080398d2
    .align 2, 0
lbl_080398bc: .4byte 0x03000738
lbl_080398c0:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #9
    bls lbl_080398dc
    subs r0, #1
    strb r0, [r1]
    ldrb r0, [r1]
    movs r1, #8
lbl_080398d2:
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
    b lbl_080398f4
lbl_080398dc:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_080398f8 @ =0x082f5d3c
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    ldr r0, lbl_080398fc @ =0x000001d7
    bl SoundPlay
lbl_080398f4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080398f8: .4byte 0x082f5d3c
lbl_080398fc: .4byte 0x000001d7

    thumb_func_start ruins_test_ghost_sync_pos
ruins_test_ghost_sync_pos: @ 0x08039900
    push {r4, lr}
    ldr r0, lbl_0803994c @ =0x0300070c
    ldrb r1, [r0, #0xf]
    adds r4, r0, #0
    cmp r1, #2
    bls lbl_0803996c
    ldr r2, lbl_08039950 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080399ee
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080399ee
    movs r0, #0xa
    strb r0, [r1]
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    adds r1, r0, #1
    strb r1, [r3]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bhi lbl_08039954
    ldrb r0, [r3]
    movs r1, #0x10
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
    b lbl_080399ee
    .align 2, 0
lbl_0803994c: .4byte 0x0300070c
lbl_08039950: .4byte 0x03000738
lbl_08039954:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
    movs r0, #0x10
    strb r0, [r3]
    movs r1, #0x91
    lsls r1, r1, #6
    movs r0, #1
    bl TransparencyUpdateBLDCNT
    b lbl_080399ee
lbl_0803996c:
    ldr r3, lbl_080399a0 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r2, lbl_080399a4 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrh r1, [r0, #2]
    strh r1, [r3, #2]
    ldrh r1, [r0, #4]
    strh r1, [r3, #4]
    adds r0, #0x2b
    ldrb r0, [r0]
    adds r1, r3, #0
    adds r1, #0x2b
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_080399ac
    ldrh r1, [r3]
    ldr r0, lbl_080399a8 @ =0x0000dfff
    ands r0, r1
    b lbl_080399b6
    .align 2, 0
lbl_080399a0: .4byte 0x03000738
lbl_080399a4: .4byte 0x030001ac
lbl_080399a8: .4byte 0x0000dfff
lbl_080399ac:
    ldrh r0, [r3]
    movs r2, #0x80
    lsls r2, r2, #6
    adds r1, r2, #0
    orrs r0, r1
lbl_080399b6:
    strh r0, [r3]
    ldrb r0, [r4, #0xf]
    cmp r0, #2
    bne lbl_080399ee
    movs r2, #0
    movs r0, #3
    strb r0, [r4, #0xf]
    adds r1, r3, #0
    adds r1, #0x2d
    movs r0, #9
    strb r0, [r1]
    subs r1, #1
    movs r0, #0xa
    strb r0, [r1]
    ldr r0, lbl_080399f4 @ =0x082f5d2c
    str r0, [r3, #0x18]
    movs r0, #0
    strh r2, [r3, #0x16]
    strb r0, [r3, #0x1c]
    ldrh r0, [r3]
    movs r2, #0x80
    lsls r2, r2, #6
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r3]
    ldr r0, lbl_080399f8 @ =0x000001df
    bl SoundPlay
lbl_080399ee:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080399f4: .4byte 0x082f5d2c
lbl_080399f8: .4byte 0x000001df

    thumb_func_start RuinsTestGhostDespawn
RuinsTestGhostDespawn: @ 0x080399fc
    push {r4, lr}
    ldr r2, lbl_08039a34 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    movs r4, #0xff
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_08039a3a
    movs r0, #0xa
    strb r0, [r1]
    adds r1, #1
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ands r0, r4
    cmp r0, #0xff
    beq lbl_08039a38
    ldrb r0, [r1]
    movs r1, #0x10
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
    b lbl_08039a3a
    .align 2, 0
lbl_08039a34: .4byte 0x03000738
lbl_08039a38:
    strh r3, [r2]
lbl_08039a3a:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start RuinsTestGhostMoveSymbolToPlace
RuinsTestGhostMoveSymbolToPlace: @ 0x08039a40
    push {r4, r5, r6, lr}
    sub sp, #8
    ldr r2, lbl_08039a7c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    mov ip, r2
    cmp r0, #0
    beq lbl_08039a5a
    b lbl_08039b6c
lbl_08039a5a:
    movs r0, #4
    strb r0, [r1]
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r1, r0, #1
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xb
    bls lbl_08039a70
    b lbl_08039b6c
lbl_08039a70:
    lsls r0, r0, #2
    ldr r1, lbl_08039a80 @ =lbl_08039a84
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08039a7c: .4byte 0x03000738
lbl_08039a80: .4byte lbl_08039a84
lbl_08039a84: @ jump table
    .4byte lbl_08039ab4 @ case 0
    .4byte lbl_08039b5c @ case 1
    .4byte lbl_08039ac4 @ case 2
    .4byte lbl_08039ad4 @ case 3
    .4byte lbl_08039ae4 @ case 4
    .4byte lbl_08039af4 @ case 5
    .4byte lbl_08039b04 @ case 6
    .4byte lbl_08039b14 @ case 7
    .4byte lbl_08039b24 @ case 8
    .4byte lbl_08039b34 @ case 9
    .4byte lbl_08039b44 @ case 10
    .4byte lbl_08039b54 @ case 11
lbl_08039ab4:
    ldr r1, lbl_08039abc @ =0x040000d4
    ldr r0, lbl_08039ac0 @ =0x082f471c
    b lbl_08039b60
    .align 2, 0
lbl_08039abc: .4byte 0x040000d4
lbl_08039ac0: .4byte 0x082f471c
lbl_08039ac4:
    ldr r1, lbl_08039acc @ =0x040000d4
    ldr r0, lbl_08039ad0 @ =0x082f476c
    b lbl_08039b60
    .align 2, 0
lbl_08039acc: .4byte 0x040000d4
lbl_08039ad0: .4byte 0x082f476c
lbl_08039ad4:
    ldr r1, lbl_08039adc @ =0x040000d4
    ldr r0, lbl_08039ae0 @ =0x082f477c
    b lbl_08039b60
    .align 2, 0
lbl_08039adc: .4byte 0x040000d4
lbl_08039ae0: .4byte 0x082f477c
lbl_08039ae4:
    ldr r1, lbl_08039aec @ =0x040000d4
    ldr r0, lbl_08039af0 @ =0x082f478c
    b lbl_08039b60
    .align 2, 0
lbl_08039aec: .4byte 0x040000d4
lbl_08039af0: .4byte 0x082f478c
lbl_08039af4:
    ldr r1, lbl_08039afc @ =0x040000d4
    ldr r0, lbl_08039b00 @ =0x082f479c
    b lbl_08039b60
    .align 2, 0
lbl_08039afc: .4byte 0x040000d4
lbl_08039b00: .4byte 0x082f479c
lbl_08039b04:
    ldr r1, lbl_08039b0c @ =0x040000d4
    ldr r0, lbl_08039b10 @ =0x082f47ac
    b lbl_08039b60
    .align 2, 0
lbl_08039b0c: .4byte 0x040000d4
lbl_08039b10: .4byte 0x082f47ac
lbl_08039b14:
    ldr r1, lbl_08039b1c @ =0x040000d4
    ldr r0, lbl_08039b20 @ =0x082f479c
    b lbl_08039b60
    .align 2, 0
lbl_08039b1c: .4byte 0x040000d4
lbl_08039b20: .4byte 0x082f479c
lbl_08039b24:
    ldr r1, lbl_08039b2c @ =0x040000d4
    ldr r0, lbl_08039b30 @ =0x082f478c
    b lbl_08039b60
    .align 2, 0
lbl_08039b2c: .4byte 0x040000d4
lbl_08039b30: .4byte 0x082f478c
lbl_08039b34:
    ldr r1, lbl_08039b3c @ =0x040000d4
    ldr r0, lbl_08039b40 @ =0x082f477c
    b lbl_08039b60
    .align 2, 0
lbl_08039b3c: .4byte 0x040000d4
lbl_08039b40: .4byte 0x082f477c
lbl_08039b44:
    ldr r1, lbl_08039b4c @ =0x040000d4
    ldr r0, lbl_08039b50 @ =0x082f476c
    b lbl_08039b60
    .align 2, 0
lbl_08039b4c: .4byte 0x040000d4
lbl_08039b50: .4byte 0x082f476c
lbl_08039b54:
    mov r1, ip
    adds r1, #0x2d
    movs r0, #0
    strb r0, [r1]
lbl_08039b5c:
    ldr r1, lbl_08039b88 @ =0x040000d4
    ldr r0, lbl_08039b8c @ =0x082f475c
lbl_08039b60:
    str r0, [r1]
    ldr r0, lbl_08039b90 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_08039b94 @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08039b6c:
    ldr r0, lbl_08039b98 @ =0x0300080c
    ldrh r4, [r0]
    ldrh r5, [r0, #2]
    mov r1, ip
    ldrb r0, [r1, #0x1e]
    cmp r0, #1
    bne lbl_08039ba0
    adds r0, r4, #0
    subs r0, #0xb0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r2, lbl_08039b9c @ =0xfffffea0
    adds r0, r5, r2
    b lbl_08039bda
    .align 2, 0
lbl_08039b88: .4byte 0x040000d4
lbl_08039b8c: .4byte 0x082f475c
lbl_08039b90: .4byte 0x050003c0
lbl_08039b94: .4byte 0x80000008
lbl_08039b98: .4byte 0x0300080c
lbl_08039b9c: .4byte 0xfffffea0
lbl_08039ba0:
    cmp r0, #2
    bne lbl_08039bb4
    adds r0, r4, #0
    subs r0, #0xb0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r3, #0xb0
    lsls r3, r3, #1
    adds r0, r5, r3
    b lbl_08039bda
lbl_08039bb4:
    cmp r0, #3
    bne lbl_08039bcc
    adds r0, r4, #0
    adds r0, #0xb0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r6, lbl_08039bc8 @ =0xfffffea0
    adds r0, r5, r6
    b lbl_08039bda
    .align 2, 0
lbl_08039bc8: .4byte 0xfffffea0
lbl_08039bcc:
    adds r0, r4, #0
    adds r0, #0xb0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r1, #0xb0
    lsls r1, r1, #1
    adds r0, r5, r1
lbl_08039bda:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    mov r2, ip
    ldrh r0, [r2, #4]
    cmp r5, r0
    bls lbl_08039bea
    subs r0, r5, r0
    b lbl_08039bec
lbl_08039bea:
    subs r0, r0, r5
lbl_08039bec:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    mov r3, ip
    ldrh r0, [r3, #2]
    cmp r4, r0
    bls lbl_08039bfc
    subs r0, r4, r0
    b lbl_08039bfe
lbl_08039bfc:
    subs r0, r0, r4
lbl_08039bfe:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, #3
    bhi lbl_08039c48
    cmp r0, #3
    bhi lbl_08039c48
    movs r3, #0
    movs r2, #0
    mov r6, ip
    strh r4, [r6, #2]
    strh r5, [r6, #4]
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    ldr r0, lbl_08039c40 @ =0x082f5ff4
    str r0, [r6, #0x18]
    strh r2, [r6, #0x16]
    strb r3, [r6, #0x1c]
    ldrh r1, [r6]
    ldr r0, lbl_08039c44 @ =0x0000ffef
    ands r0, r1
    strh r0, [r6]
    mov r1, ip
    adds r1, #0x22
    movs r0, #0xe
    strb r0, [r1]
    movs r0, #0xed
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08039c6a
    .align 2, 0
lbl_08039c40: .4byte 0x082f5ff4
lbl_08039c44: .4byte 0x0000ffef
lbl_08039c48:
    mov r1, ip
    ldrh r0, [r1, #6]
    ldrh r1, [r1, #8]
    mov r3, ip
    ldrh r2, [r3, #0x12]
    adds r3, r2, #1
    mov r6, ip
    strh r3, [r6, #0x12]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp]
    movs r2, #4
    str r2, [sp, #4]
    adds r2, r4, #0
    adds r3, r5, #0
    bl ruins_test_move_to_pos
lbl_08039c6a:
    add sp, #8
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RuinsTestGhostSymbolPlacing
RuinsTestGhostSymbolPlacing: @ 0x08039c74
    push {lr}
    ldr r1, lbl_08039c94 @ =0x03000738
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    beq lbl_08039c80
    b lbl_08039d90
lbl_08039c80:
    ldrh r0, [r1, #0x16]
    cmp r0, #0xc
    bls lbl_08039c88
    b lbl_08039d90
lbl_08039c88:
    lsls r0, r0, #2
    ldr r1, lbl_08039c98 @ =lbl_08039c9c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08039c94: .4byte 0x03000738
lbl_08039c98: .4byte lbl_08039c9c
lbl_08039c9c: @ jump table
    .4byte lbl_08039d80 @ case 0
    .4byte lbl_08039cd0 @ case 1
    .4byte lbl_08039ce0 @ case 2
    .4byte lbl_08039cf0 @ case 3
    .4byte lbl_08039d00 @ case 4
    .4byte lbl_08039d10 @ case 5
    .4byte lbl_08039d20 @ case 6
    .4byte lbl_08039d30 @ case 7
    .4byte lbl_08039d40 @ case 8
    .4byte lbl_08039d50 @ case 9
    .4byte lbl_08039d60 @ case 10
    .4byte lbl_08039d70 @ case 11
    .4byte lbl_08039d80 @ case 12
lbl_08039cd0:
    ldr r1, lbl_08039cd8 @ =0x040000d4
    ldr r0, lbl_08039cdc @ =0x082f475c
    b lbl_08039d84
    .align 2, 0
lbl_08039cd8: .4byte 0x040000d4
lbl_08039cdc: .4byte 0x082f475c
lbl_08039ce0:
    ldr r1, lbl_08039ce8 @ =0x040000d4
    ldr r0, lbl_08039cec @ =0x082f476c
    b lbl_08039d84
    .align 2, 0
lbl_08039ce8: .4byte 0x040000d4
lbl_08039cec: .4byte 0x082f476c
lbl_08039cf0:
    ldr r1, lbl_08039cf8 @ =0x040000d4
    ldr r0, lbl_08039cfc @ =0x082f477c
    b lbl_08039d84
    .align 2, 0
lbl_08039cf8: .4byte 0x040000d4
lbl_08039cfc: .4byte 0x082f477c
lbl_08039d00:
    ldr r1, lbl_08039d08 @ =0x040000d4
    ldr r0, lbl_08039d0c @ =0x082f478c
    b lbl_08039d84
    .align 2, 0
lbl_08039d08: .4byte 0x040000d4
lbl_08039d0c: .4byte 0x082f478c
lbl_08039d10:
    ldr r1, lbl_08039d18 @ =0x040000d4
    ldr r0, lbl_08039d1c @ =0x082f479c
    b lbl_08039d84
    .align 2, 0
lbl_08039d18: .4byte 0x040000d4
lbl_08039d1c: .4byte 0x082f479c
lbl_08039d20:
    ldr r1, lbl_08039d28 @ =0x040000d4
    ldr r0, lbl_08039d2c @ =0x082f47ac
    b lbl_08039d84
    .align 2, 0
lbl_08039d28: .4byte 0x040000d4
lbl_08039d2c: .4byte 0x082f47ac
lbl_08039d30:
    ldr r1, lbl_08039d38 @ =0x040000d4
    ldr r0, lbl_08039d3c @ =0x082f479c
    b lbl_08039d84
    .align 2, 0
lbl_08039d38: .4byte 0x040000d4
lbl_08039d3c: .4byte 0x082f479c
lbl_08039d40:
    ldr r1, lbl_08039d48 @ =0x040000d4
    ldr r0, lbl_08039d4c @ =0x082f478c
    b lbl_08039d84
    .align 2, 0
lbl_08039d48: .4byte 0x040000d4
lbl_08039d4c: .4byte 0x082f478c
lbl_08039d50:
    ldr r1, lbl_08039d58 @ =0x040000d4
    ldr r0, lbl_08039d5c @ =0x082f477c
    b lbl_08039d84
    .align 2, 0
lbl_08039d58: .4byte 0x040000d4
lbl_08039d5c: .4byte 0x082f477c
lbl_08039d60:
    ldr r1, lbl_08039d68 @ =0x040000d4
    ldr r0, lbl_08039d6c @ =0x082f476c
    b lbl_08039d84
    .align 2, 0
lbl_08039d68: .4byte 0x040000d4
lbl_08039d6c: .4byte 0x082f476c
lbl_08039d70:
    ldr r1, lbl_08039d78 @ =0x040000d4
    ldr r0, lbl_08039d7c @ =0x082f475c
    b lbl_08039d84
    .align 2, 0
lbl_08039d78: .4byte 0x040000d4
lbl_08039d7c: .4byte 0x082f475c
lbl_08039d80:
    ldr r1, lbl_08039db8 @ =0x040000d4
    ldr r0, lbl_08039dbc @ =0x082f471c
lbl_08039d84:
    str r0, [r1]
    ldr r0, lbl_08039dc0 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_08039dc4 @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08039d90:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08039de6
    ldr r2, lbl_08039dc8 @ =0x03000738
    ldr r0, lbl_08039dcc @ =0x082f5d74
    str r0, [r2, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r2, #0x16]
    strb r1, [r2, #0x1c]
    adds r1, r2, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x2b
    bne lbl_08039dd0
    movs r0, #0x6c
    strb r0, [r1]
    b lbl_08039de6
    .align 2, 0
lbl_08039db8: .4byte 0x040000d4
lbl_08039dbc: .4byte 0x082f471c
lbl_08039dc0: .4byte 0x050003c0
lbl_08039dc4: .4byte 0x80000008
lbl_08039dc8: .4byte 0x03000738
lbl_08039dcc: .4byte 0x082f5d74
lbl_08039dd0:
    ldrb r0, [r2, #0x1e]
    cmp r0, #4
    bne lbl_08039dda
    movs r0, #0x26
    b lbl_08039ddc
lbl_08039dda:
    movs r0, #0x27
lbl_08039ddc:
    strb r0, [r1]
    ldr r1, lbl_08039dec @ =0x0300080c
    ldrh r0, [r1, #0xc]
    adds r0, #1
    strh r0, [r1, #0xc]
lbl_08039de6:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039dec: .4byte 0x0300080c

    thumb_func_start RuinsTestGhostSymbolSetGhostDisappearing
RuinsTestGhostSymbolSetGhostDisappearing: @ 0x08039df0
    push {lr}
    ldr r1, lbl_08039e0c @ =0x0300070c
    ldrb r0, [r1, #0xf]
    cmp r0, #3
    bne lbl_08039e06
    movs r0, #4
    strb r0, [r1, #0xf]
    ldr r0, lbl_08039e10 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x27
    strb r1, [r0]
lbl_08039e06:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039e0c: .4byte 0x0300070c
lbl_08039e10: .4byte 0x03000738

    thumb_func_start sub_08039e14
sub_08039e14: @ 0x08039e14
    push {lr}
    ldr r0, lbl_08039e34 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #4
    bne lbl_08039e2e
    ldr r1, lbl_08039e38 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    movs r0, #0x50
    strb r0, [r2]
    adds r1, #0x24
    movs r0, #0x29
    strb r0, [r1]
lbl_08039e2e:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039e34: .4byte 0x0300070c
lbl_08039e38: .4byte 0x03000738

    thumb_func_start sub_08039e3c
sub_08039e3c: @ 0x08039e3c
    push {lr}
    ldr r2, lbl_08039e70 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_08039e6a
    subs r1, #8
    movs r0, #0x2b
    strb r0, [r1]
    ldr r0, lbl_08039e74 @ =0x082f5ff4
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    movs r0, #0xf0
    lsls r0, r0, #1
    bl SoundPlay
lbl_08039e6a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08039e70: .4byte 0x03000738
lbl_08039e74: .4byte 0x082f5ff4

    thumb_func_start RuinsTest
RuinsTest: @ 0x08039e78
    push {r4, lr}
    sub sp, #0xc
    ldr r0, lbl_08039e94 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x69
    bls lbl_08039e88
    b lbl_0803a08e
lbl_08039e88:
    lsls r0, r0, #2
    ldr r1, lbl_08039e98 @ =lbl_08039e9c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08039e94: .4byte 0x03000738
lbl_08039e98: .4byte lbl_08039e9c
lbl_08039e9c: @ jump table
    .4byte lbl_0803a044 @ case 0
    .4byte lbl_0803a04a @ case 1
    .4byte lbl_0803a050 @ case 2
    .4byte lbl_0803a056 @ case 3
    .4byte lbl_0803a05c @ case 4
    .4byte lbl_0803a08e @ case 5
    .4byte lbl_0803a08e @ case 6
    .4byte lbl_0803a08e @ case 7
    .4byte lbl_0803a062 @ case 8
    .4byte lbl_0803a068 @ case 9
    .4byte lbl_0803a08e @ case 10
    .4byte lbl_0803a08e @ case 11
    .4byte lbl_0803a08e @ case 12
    .4byte lbl_0803a08e @ case 13
    .4byte lbl_0803a08e @ case 14
    .4byte lbl_0803a08e @ case 15
    .4byte lbl_0803a08e @ case 16
    .4byte lbl_0803a08e @ case 17
    .4byte lbl_0803a08e @ case 18
    .4byte lbl_0803a08e @ case 19
    .4byte lbl_0803a08e @ case 20
    .4byte lbl_0803a08e @ case 21
    .4byte lbl_0803a08e @ case 22
    .4byte lbl_0803a08e @ case 23
    .4byte lbl_0803a08e @ case 24
    .4byte lbl_0803a08e @ case 25
    .4byte lbl_0803a08e @ case 26
    .4byte lbl_0803a08e @ case 27
    .4byte lbl_0803a08e @ case 28
    .4byte lbl_0803a08e @ case 29
    .4byte lbl_0803a08e @ case 30
    .4byte lbl_0803a08e @ case 31
    .4byte lbl_0803a08e @ case 32
    .4byte lbl_0803a08e @ case 33
    .4byte lbl_0803a06e @ case 34
    .4byte lbl_0803a072 @ case 35
    .4byte lbl_0803a08e @ case 36
    .4byte lbl_0803a078 @ case 37
    .4byte lbl_0803a08e @ case 38
    .4byte lbl_0803a08e @ case 39
    .4byte lbl_0803a08e @ case 40
    .4byte lbl_0803a08e @ case 41
    .4byte lbl_0803a08e @ case 42
    .4byte lbl_0803a08e @ case 43
    .4byte lbl_0803a08e @ case 44
    .4byte lbl_0803a08e @ case 45
    .4byte lbl_0803a08e @ case 46
    .4byte lbl_0803a08e @ case 47
    .4byte lbl_0803a08e @ case 48
    .4byte lbl_0803a08e @ case 49
    .4byte lbl_0803a08e @ case 50
    .4byte lbl_0803a08e @ case 51
    .4byte lbl_0803a08e @ case 52
    .4byte lbl_0803a08e @ case 53
    .4byte lbl_0803a08e @ case 54
    .4byte lbl_0803a08e @ case 55
    .4byte lbl_0803a08e @ case 56
    .4byte lbl_0803a08e @ case 57
    .4byte lbl_0803a08e @ case 58
    .4byte lbl_0803a08e @ case 59
    .4byte lbl_0803a08e @ case 60
    .4byte lbl_0803a08e @ case 61
    .4byte lbl_0803a08e @ case 62
    .4byte lbl_0803a08e @ case 63
    .4byte lbl_0803a08e @ case 64
    .4byte lbl_0803a08e @ case 65
    .4byte lbl_0803a08e @ case 66
    .4byte lbl_0803a08e @ case 67
    .4byte lbl_0803a08e @ case 68
    .4byte lbl_0803a08e @ case 69
    .4byte lbl_0803a08e @ case 70
    .4byte lbl_0803a08e @ case 71
    .4byte lbl_0803a08e @ case 72
    .4byte lbl_0803a08e @ case 73
    .4byte lbl_0803a08e @ case 74
    .4byte lbl_0803a08e @ case 75
    .4byte lbl_0803a08e @ case 76
    .4byte lbl_0803a08e @ case 77
    .4byte lbl_0803a08e @ case 78
    .4byte lbl_0803a08e @ case 79
    .4byte lbl_0803a08e @ case 80
    .4byte lbl_0803a08e @ case 81
    .4byte lbl_0803a08e @ case 82
    .4byte lbl_0803a08e @ case 83
    .4byte lbl_0803a08e @ case 84
    .4byte lbl_0803a08e @ case 85
    .4byte lbl_0803a08e @ case 86
    .4byte lbl_0803a08e @ case 87
    .4byte lbl_0803a08e @ case 88
    .4byte lbl_0803a08e @ case 89
    .4byte lbl_0803a08e @ case 90
    .4byte lbl_0803a08e @ case 91
    .4byte lbl_0803a08e @ case 92
    .4byte lbl_0803a08e @ case 93
    .4byte lbl_0803a08e @ case 94
    .4byte lbl_0803a08e @ case 95
    .4byte lbl_0803a08e @ case 96
    .4byte lbl_0803a08e @ case 97
    .4byte lbl_0803a08e @ case 98
    .4byte lbl_0803a08e @ case 99
    .4byte lbl_0803a08e @ case 100
    .4byte lbl_0803a08e @ case 101
    .4byte lbl_0803a08e @ case 102
    .4byte lbl_0803a07e @ case 103
    .4byte lbl_0803a084 @ case 104
    .4byte lbl_0803a08a @ case 105
lbl_0803a044:
    bl RuinsTestInit
    b lbl_0803a08e
lbl_0803a04a:
    bl sub_080390cc
    b lbl_0803a08e
lbl_0803a050:
    bl RuinsTestTurningIntoReflection
    b lbl_0803a08e
lbl_0803a056:
    bl sub_08039194
    b lbl_0803a08e
lbl_0803a05c:
    bl RuinsTestCheckSamusNotFacingBackground
    b lbl_0803a08e
lbl_0803a062:
    bl sub_080391f0
    b lbl_0803a08e
lbl_0803a068:
    bl RuinsTestSpawnGhost
    b lbl_0803a08e
lbl_0803a06e:
    bl RuinsTestMovingInit
lbl_0803a072:
    bl RuinsTestMoveCirclePattern
    b lbl_0803a08e
lbl_0803a078:
    bl RuinsTestMoveAtomPattern
    b lbl_0803a08e
lbl_0803a07e:
    bl RuinsTestMoveToCenter
    b lbl_0803a08e
lbl_0803a084:
    bl sub_080396a4
    b lbl_0803a08e
lbl_0803a08a:
    bl RuinsTestDespawn
lbl_0803a08e:
    ldr r0, lbl_0803a140 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    bne lbl_0803a164
    ldr r4, lbl_0803a144 @ =0x0300080c
    ldrh r0, [r4, #6]
    cmp r0, #0
    bne lbl_0803a106
    ldrh r0, [r4, #0xc]
    cmp r0, #2
    bls lbl_0803a0d4
    ldr r0, lbl_0803a148 @ =0x03000c77
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_0803a0d4
    ldr r0, lbl_0803a14c @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803a0d4
    strh r1, [r4, #0xa]
    movs r0, #1
    strh r0, [r4, #6]
    ldr r0, lbl_0803a150 @ =0x03000738
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4]
    str r0, [sp]
    ldrh r0, [r4, #2]
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0x3e
    movs r1, #1
    bl SpriteSpawnSecondary
lbl_0803a0d4:
    ldr r4, lbl_0803a144 @ =0x0300080c
    ldrh r0, [r4, #0xa]
    cmp r0, #0x1e
    bls lbl_0803a106
    ldr r0, lbl_0803a148 @ =0x03000c77
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803a106
    movs r1, #0
    strh r1, [r4, #0xa]
    movs r0, #1
    strh r0, [r4, #6]
    ldr r0, lbl_0803a150 @ =0x03000738
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4]
    str r0, [sp]
    ldrh r0, [r4, #2]
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0x3e
    movs r1, #2
    bl SpriteSpawnSecondary
lbl_0803a106:
    ldr r0, lbl_0803a144 @ =0x0300080c
    ldrh r1, [r0, #4]
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_0803a114
    subs r0, r1, #1
    strh r0, [r2, #4]
lbl_0803a114:
    ldr r0, lbl_0803a150 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x22
    bls lbl_0803a164
    ldrh r0, [r2, #0xc]
    cmp r0, #0
    beq lbl_0803a164
    ldr r3, lbl_0803a154 @ =0x030013d4
    ldr r1, lbl_0803a158 @ =0x03001600
    ldrh r0, [r3, #0x12]
    ldrh r1, [r1]
    cmp r0, r1
    bne lbl_0803a160
    ldr r1, lbl_0803a15c @ =0x03001602
    ldrh r0, [r3, #0x14]
    ldrh r1, [r1]
    cmp r0, r1
    bne lbl_0803a160
    ldrh r0, [r2, #0xa]
    adds r0, #1
    b lbl_0803a162
    .align 2, 0
lbl_0803a140: .4byte 0x0300070c
lbl_0803a144: .4byte 0x0300080c
lbl_0803a148: .4byte 0x03000c77
lbl_0803a14c: .4byte 0x0300002c
lbl_0803a150: .4byte 0x03000738
lbl_0803a154: .4byte 0x030013d4
lbl_0803a158: .4byte 0x03001600
lbl_0803a15c: .4byte 0x03001602
lbl_0803a160:
    movs r0, #0
lbl_0803a162:
    strh r0, [r2, #0xa]
lbl_0803a164:
    add sp, #0xc
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start RuinsTestSymbol
RuinsTestSymbol: @ 0x0803a16c
    push {lr}
    ldr r1, lbl_0803a18c @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    adds r0, #1
    ldrb r0, [r0]
    mov ip, r1
    cmp r0, #0x25
    bls lbl_0803a182
    b lbl_0803a4e6
lbl_0803a182:
    lsls r0, r0, #2
    ldr r1, lbl_0803a190 @ =lbl_0803a194
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803a18c: .4byte 0x03000738
lbl_0803a190: .4byte lbl_0803a194
lbl_0803a194: @ jump table
    .4byte lbl_0803a22c @ case 0
    .4byte lbl_0803a4e6 @ case 1
    .4byte lbl_0803a4e6 @ case 2
    .4byte lbl_0803a4e6 @ case 3
    .4byte lbl_0803a4e6 @ case 4
    .4byte lbl_0803a4e6 @ case 5
    .4byte lbl_0803a4e6 @ case 6
    .4byte lbl_0803a4e6 @ case 7
    .4byte lbl_0803a290 @ case 8
    .4byte lbl_0803a2c8 @ case 9
    .4byte lbl_0803a4e6 @ case 10
    .4byte lbl_0803a4e6 @ case 11
    .4byte lbl_0803a4e6 @ case 12
    .4byte lbl_0803a4e6 @ case 13
    .4byte lbl_0803a4e6 @ case 14
    .4byte lbl_0803a4e6 @ case 15
    .4byte lbl_0803a4e6 @ case 16
    .4byte lbl_0803a4e6 @ case 17
    .4byte lbl_0803a4e6 @ case 18
    .4byte lbl_0803a4e6 @ case 19
    .4byte lbl_0803a4e6 @ case 20
    .4byte lbl_0803a4e6 @ case 21
    .4byte lbl_0803a4e6 @ case 22
    .4byte lbl_0803a4e6 @ case 23
    .4byte lbl_0803a4e6 @ case 24
    .4byte lbl_0803a4e6 @ case 25
    .4byte lbl_0803a4e6 @ case 26
    .4byte lbl_0803a4e6 @ case 27
    .4byte lbl_0803a4e6 @ case 28
    .4byte lbl_0803a4e6 @ case 29
    .4byte lbl_0803a4e6 @ case 30
    .4byte lbl_0803a4e6 @ case 31
    .4byte lbl_0803a4e6 @ case 32
    .4byte lbl_0803a4e6 @ case 33
    .4byte lbl_0803a4e6 @ case 34
    .4byte lbl_0803a3e8 @ case 35
    .4byte lbl_0803a4e6 @ case 36
    .4byte lbl_0803a48c @ case 37
lbl_0803a22c:
    mov r0, ip
    ldrh r1, [r0]
    ldr r0, lbl_0803a284 @ =0x0000fffb
    ands r0, r1
    movs r3, #0
    movs r2, #0
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x27
    movs r1, #0x40
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    mov r1, ip
    adds r1, #0x29
    movs r0, #0x68
    strb r0, [r1]
    mov r0, ip
    strh r2, [r0, #0xa]
    strh r2, [r0, #0xc]
    strh r2, [r0, #0xe]
    strh r2, [r0, #0x10]
    ldr r0, lbl_0803a288 @ =0x082f5d84
    mov r1, ip
    str r0, [r1, #0x18]
    strh r2, [r1, #0x16]
    strb r3, [r1, #0x1c]
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r3, [r0]
    adds r1, #8
    movs r0, #0x3c
    strb r0, [r1]
    subs r1, #0xa
    movs r0, #0xd
    strb r0, [r1]
    ldr r1, lbl_0803a28c @ =0x03000049
    movs r0, #1
    strb r0, [r1]
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a284: .4byte 0x0000fffb
lbl_0803a288: .4byte 0x082f5d84
lbl_0803a28c: .4byte 0x03000049
lbl_0803a290:
    mov r1, ip
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803a2a2
    b lbl_0803a4e6
lbl_0803a2a2:
    subs r1, #8
    movs r0, #9
    strb r0, [r1]
    movs r1, #0
    movs r0, #1
    mov r2, ip
    strh r0, [r2, #0x16]
    strb r1, [r2, #0x1c]
    movs r0, #0x43
    movs r1, #0
    bl MusicPlay
    ldr r0, lbl_0803a2c4 @ =0x000001d3
    bl SoundPlay
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a2c4: .4byte 0x000001d3
lbl_0803a2c8:
    mov r1, ip
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0803a3a8
    ldrh r0, [r1, #0x16]
    subs r0, #2
    cmp r0, #8
    bhi lbl_0803a3a8
    lsls r0, r0, #2
    ldr r1, lbl_0803a2e4 @ =lbl_0803a2e8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803a2e4: .4byte lbl_0803a2e8
lbl_0803a2e8: @ jump table
    .4byte lbl_0803a30c @ case 0
    .4byte lbl_0803a31c @ case 1
    .4byte lbl_0803a32c @ case 2
    .4byte lbl_0803a36c @ case 3
    .4byte lbl_0803a33c @ case 4
    .4byte lbl_0803a34c @ case 5
    .4byte lbl_0803a35c @ case 6
    .4byte lbl_0803a36c @ case 7
    .4byte lbl_0803a390 @ case 8
lbl_0803a30c:
    ldr r1, lbl_0803a314 @ =0x040000d4
    ldr r0, lbl_0803a318 @ =0x082f475c
    b lbl_0803a370
    .align 2, 0
lbl_0803a314: .4byte 0x040000d4
lbl_0803a318: .4byte 0x082f475c
lbl_0803a31c:
    ldr r1, lbl_0803a324 @ =0x040000d4
    ldr r0, lbl_0803a328 @ =0x082f476c
    b lbl_0803a370
    .align 2, 0
lbl_0803a324: .4byte 0x040000d4
lbl_0803a328: .4byte 0x082f476c
lbl_0803a32c:
    ldr r1, lbl_0803a334 @ =0x040000d4
    ldr r0, lbl_0803a338 @ =0x082f477c
    b lbl_0803a370
    .align 2, 0
lbl_0803a334: .4byte 0x040000d4
lbl_0803a338: .4byte 0x082f477c
lbl_0803a33c:
    ldr r1, lbl_0803a344 @ =0x040000d4
    ldr r0, lbl_0803a348 @ =0x082f479c
    b lbl_0803a370
    .align 2, 0
lbl_0803a344: .4byte 0x040000d4
lbl_0803a348: .4byte 0x082f479c
lbl_0803a34c:
    ldr r1, lbl_0803a354 @ =0x040000d4
    ldr r0, lbl_0803a358 @ =0x082f47ac
    b lbl_0803a370
    .align 2, 0
lbl_0803a354: .4byte 0x040000d4
lbl_0803a358: .4byte 0x082f47ac
lbl_0803a35c:
    ldr r1, lbl_0803a364 @ =0x040000d4
    ldr r0, lbl_0803a368 @ =0x082f479c
    b lbl_0803a370
    .align 2, 0
lbl_0803a364: .4byte 0x040000d4
lbl_0803a368: .4byte 0x082f479c
lbl_0803a36c:
    ldr r1, lbl_0803a380 @ =0x040000d4
    ldr r0, lbl_0803a384 @ =0x082f478c
lbl_0803a370:
    str r0, [r1]
    ldr r0, lbl_0803a388 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_0803a38c @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0803a3a8
    .align 2, 0
lbl_0803a380: .4byte 0x040000d4
lbl_0803a384: .4byte 0x082f478c
lbl_0803a388: .4byte 0x050003c0
lbl_0803a38c: .4byte 0x80000008
lbl_0803a390:
    ldr r1, lbl_0803a3d0 @ =0x040000d4
    ldr r0, lbl_0803a3d4 @ =0x082f477c
    str r0, [r1]
    ldr r0, lbl_0803a3d8 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_0803a3dc @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0xea
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803a3a8:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0803a3b2
    b lbl_0803a4e6
lbl_0803a3b2:
    ldr r0, lbl_0803a3e0 @ =0x03000738
    ldr r1, lbl_0803a3e4 @ =0x082f5df4
    str r1, [r0, #0x18]
    movs r2, #0
    movs r1, #0
    strh r1, [r0, #0x16]
    strb r2, [r0, #0x1c]
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x23
    strb r1, [r2]
    adds r0, #0x2c
    movs r1, #0x78
    strb r1, [r0]
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a3d0: .4byte 0x040000d4
lbl_0803a3d4: .4byte 0x082f477c
lbl_0803a3d8: .4byte 0x050003c0
lbl_0803a3dc: .4byte 0x80000008
lbl_0803a3e0: .4byte 0x03000738
lbl_0803a3e4: .4byte 0x082f5df4
lbl_0803a3e8:
    mov r2, ip
    ldrb r0, [r2, #0x1c]
    cmp r0, #1
    bne lbl_0803a414
    ldrh r0, [r2, #0x16]
    cmp r0, #0
    bne lbl_0803a404
    ldr r1, lbl_0803a3fc @ =0x040000d4
    ldr r0, lbl_0803a400 @ =0x082f478c
    b lbl_0803a408
    .align 2, 0
lbl_0803a3fc: .4byte 0x040000d4
lbl_0803a400: .4byte 0x082f478c
lbl_0803a404:
    ldr r1, lbl_0803a43c @ =0x040000d4
    ldr r0, lbl_0803a440 @ =0x082f47ac
lbl_0803a408:
    str r0, [r1]
    ldr r0, lbl_0803a444 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_0803a448 @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0803a414:
    mov r0, ip
    adds r0, #0x2c
    ldrb r1, [r0]
    subs r1, #1
    strb r1, [r0]
    lsls r0, r1, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0803a450
    ldr r0, lbl_0803a44c @ =0x082f5e0c
    mov r1, ip
    str r0, [r1, #0x18]
    movs r0, #0
    strh r2, [r1, #0x16]
    strb r0, [r1, #0x1c]
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a43c: .4byte 0x040000d4
lbl_0803a440: .4byte 0x082f47ac
lbl_0803a444: .4byte 0x050003c0
lbl_0803a448: .4byte 0x80000008
lbl_0803a44c: .4byte 0x082f5e0c
lbl_0803a450:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x3c
    bne lbl_0803a470
    ldr r0, lbl_0803a46c @ =0x030001ac
    lsls r1, r3, #3
    subs r1, r1, r3
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x2c
    movs r0, #2
    strb r0, [r1]
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a46c: .4byte 0x030001ac
lbl_0803a470:
    cmp r0, #0x6e
    bne lbl_0803a4e6
    ldr r0, lbl_0803a488 @ =0x030001ac
    lsls r1, r3, #3
    subs r1, r1, r3
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x2c
    movs r0, #1
    strb r0, [r1]
    b lbl_0803a4e6
    .align 2, 0
lbl_0803a488: .4byte 0x030001ac
lbl_0803a48c:
    mov r2, ip
    ldrb r0, [r2, #0x1c]
    cmp r0, #1
    bne lbl_0803a4d8
    ldrh r0, [r2, #0x16]
    cmp r0, #1
    beq lbl_0803a4b8
    cmp r0, #1
    bgt lbl_0803a4a4
    cmp r0, #0
    beq lbl_0803a4aa
    b lbl_0803a4d8
lbl_0803a4a4:
    cmp r0, #2
    beq lbl_0803a4c8
    b lbl_0803a4d8
lbl_0803a4aa:
    ldr r1, lbl_0803a4b0 @ =0x040000d4
    ldr r0, lbl_0803a4b4 @ =0x082f478c
    b lbl_0803a4cc
    .align 2, 0
lbl_0803a4b0: .4byte 0x040000d4
lbl_0803a4b4: .4byte 0x082f478c
lbl_0803a4b8:
    ldr r1, lbl_0803a4c0 @ =0x040000d4
    ldr r0, lbl_0803a4c4 @ =0x082f476c
    b lbl_0803a4cc
    .align 2, 0
lbl_0803a4c0: .4byte 0x040000d4
lbl_0803a4c4: .4byte 0x082f476c
lbl_0803a4c8:
    ldr r1, lbl_0803a4ec @ =0x040000d4
    ldr r0, lbl_0803a4f0 @ =0x082f471c
lbl_0803a4cc:
    str r0, [r1]
    ldr r0, lbl_0803a4f4 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_0803a4f8 @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0803a4d8:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803a4e6
    ldr r1, lbl_0803a4fc @ =0x03000738
    movs r0, #0
    strh r0, [r1]
lbl_0803a4e6:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803a4ec: .4byte 0x040000d4
lbl_0803a4f0: .4byte 0x082f471c
lbl_0803a4f4: .4byte 0x050003c0
lbl_0803a4f8: .4byte 0x80000008
lbl_0803a4fc: .4byte 0x03000738

    thumb_func_start RuinsTestSamusReflectionStart
RuinsTestSamusReflectionStart: @ 0x0803a500
    push {r4, r5, lr}
    ldr r2, lbl_0803a51c @ =0x03000738
    adds r4, r2, #0
    adds r4, #0x24
    ldrb r3, [r4]
    mov ip, r2
    cmp r3, #8
    beq lbl_0803a5a4
    cmp r3, #8
    bgt lbl_0803a520
    cmp r3, #0
    beq lbl_0803a528
    b lbl_0803a6b0
    .align 2, 0
lbl_0803a51c: .4byte 0x03000738
lbl_0803a520:
    cmp r3, #9
    bne lbl_0803a526
    b lbl_0803a690
lbl_0803a526:
    b lbl_0803a6b0
lbl_0803a528:
    ldrh r1, [r2]
    ldr r0, lbl_0803a58c @ =0x0000fffb
    ands r0, r1
    movs r1, #0
    strh r0, [r2]
    movs r0, #0x27
    adds r0, r0, r2
    mov ip, r0
    movs r0, #0x28
    mov r5, ip
    strb r0, [r5]
    adds r0, r2, #0
    adds r0, #0x28
    strb r1, [r0]
    movs r0, #0x29
    adds r0, r0, r2
    mov ip, r0
    movs r0, #0x10
    mov r5, ip
    strb r0, [r5]
    strh r3, [r2, #0xa]
    strh r3, [r2, #0xc]
    strh r3, [r2, #0xe]
    strh r3, [r2, #0x10]
    ldr r0, lbl_0803a590 @ =0x082f5cd4
    str r0, [r2, #0x18]
    strh r3, [r2, #0x16]
    strb r1, [r2, #0x1c]
    movs r0, #8
    strb r0, [r4]
    adds r0, r2, #0
    adds r0, #0x25
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    ldr r1, lbl_0803a594 @ =0x040000d4
    ldr r0, lbl_0803a598 @ =0x082f47bc
    str r0, [r1]
    ldr r0, lbl_0803a59c @ =0x050003e0
    str r0, [r1, #4]
    ldr r0, lbl_0803a5a0 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #1
    strb r0, [r1]
    b lbl_0803a6b0
    .align 2, 0
lbl_0803a58c: .4byte 0x0000fffb
lbl_0803a590: .4byte 0x082f5cd4
lbl_0803a594: .4byte 0x040000d4
lbl_0803a598: .4byte 0x082f47bc
lbl_0803a59c: .4byte 0x050003e0
lbl_0803a5a0: .4byte 0x80000010
lbl_0803a5a4:
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r3, r0, #0
    cmp r3, #0xf
    bhi lbl_0803a5f0
    adds r0, #1
    strb r0, [r1]
    cmp r3, #0xe
    ble lbl_0803a5dc
    ldr r1, lbl_0803a5cc @ =0x040000d4
    ldr r0, lbl_0803a5d0 @ =0x082f473c
    str r0, [r1]
    ldr r0, lbl_0803a5d4 @ =0x050003e0
    str r0, [r1, #4]
    ldr r0, lbl_0803a5d8 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0803a5f0
    .align 2, 0
lbl_0803a5cc: .4byte 0x040000d4
lbl_0803a5d0: .4byte 0x082f473c
lbl_0803a5d4: .4byte 0x050003e0
lbl_0803a5d8: .4byte 0x80000010
lbl_0803a5dc:
    ldr r2, lbl_0803a62c @ =0x040000d4
    lsls r0, r3, #5
    ldr r1, lbl_0803a630 @ =0x082f47bc
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0803a634 @ =0x050003e0
    str r0, [r2, #4]
    ldr r0, lbl_0803a638 @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0803a5f0:
    ldr r2, lbl_0803a63c @ =0x030013d4
    ldrb r0, [r2]
    cmp r0, #0x3e
    beq lbl_0803a6b0
    ldr r1, lbl_0803a640 @ =0x03000049
    movs r0, #0
    strb r0, [r1]
    mov r1, ip
    adds r1, #0x2c
    movs r0, #2
    strb r0, [r1]
    subs r1, #8
    movs r0, #9
    strb r0, [r1]
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0803a654
    ldr r1, lbl_0803a62c @ =0x040000d4
    ldr r0, lbl_0803a644 @ =0x082f3c5c
    str r0, [r1]
    ldr r0, lbl_0803a648 @ =0x06014280
    str r0, [r1, #4]
    ldr r0, lbl_0803a64c @ =0x800000c0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_0803a650 @ =0x082f3ddc
    b lbl_0803a666
    .align 2, 0
lbl_0803a62c: .4byte 0x040000d4
lbl_0803a630: .4byte 0x082f47bc
lbl_0803a634: .4byte 0x050003e0
lbl_0803a638: .4byte 0x80000010
lbl_0803a63c: .4byte 0x030013d4
lbl_0803a640: .4byte 0x03000049
lbl_0803a644: .4byte 0x082f3c5c
lbl_0803a648: .4byte 0x06014280
lbl_0803a64c: .4byte 0x800000c0
lbl_0803a650: .4byte 0x082f3ddc
lbl_0803a654:
    ldr r1, lbl_0803a674 @ =0x040000d4
    ldr r0, lbl_0803a678 @ =0x082f3edc
    str r0, [r1]
    ldr r0, lbl_0803a67c @ =0x06014280
    str r0, [r1, #4]
    ldr r0, lbl_0803a680 @ =0x800000c0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_0803a684 @ =0x082f405c
lbl_0803a666:
    str r0, [r1]
    ldr r0, lbl_0803a688 @ =0x06014680
    str r0, [r1, #4]
    ldr r0, lbl_0803a68c @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0803a6b0
    .align 2, 0
lbl_0803a674: .4byte 0x040000d4
lbl_0803a678: .4byte 0x082f3edc
lbl_0803a67c: .4byte 0x06014280
lbl_0803a680: .4byte 0x800000c0
lbl_0803a684: .4byte 0x082f405c
lbl_0803a688: .4byte 0x06014680
lbl_0803a68c: .4byte 0x80000080
lbl_0803a690:
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0803a6b0
    strh r0, [r2]
    ldrh r0, [r2, #2]
    subs r0, #0x5c
    ldrh r1, [r2, #4]
    movs r2, #0x3a
    bl ParticleSet
lbl_0803a6b0:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RuinsTestReflectionCover
RuinsTestReflectionCover: @ 0x0803a6b8
    push {r4, r5, lr}
    ldr r3, lbl_0803a6d8 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r2, [r0]
    adds r5, r3, #0
    adds r5, #0x24
    ldrb r4, [r5]
    mov ip, r3
    cmp r4, #8
    beq lbl_0803a72c
    cmp r4, #8
    bgt lbl_0803a6dc
    cmp r4, #0
    beq lbl_0803a6e2
    b lbl_0803a778
    .align 2, 0
lbl_0803a6d8: .4byte 0x03000738
lbl_0803a6dc:
    cmp r4, #9
    beq lbl_0803a774
    b lbl_0803a778
lbl_0803a6e2:
    ldrh r1, [r3]
    movs r0, #0x10
    movs r2, #0
    orrs r0, r1
    ldr r1, lbl_0803a724 @ =0x0000fffb
    ands r0, r1
    strh r0, [r3]
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    strh r4, [r3, #0xa]
    strh r4, [r3, #0xc]
    strh r4, [r3, #0xe]
    strh r4, [r3, #0x10]
    ldr r0, lbl_0803a728 @ =0x082f5eac
    str r0, [r3, #0x18]
    strh r4, [r3, #0x16]
    strb r2, [r3, #0x1c]
    movs r0, #8
    strb r0, [r5]
    adds r0, r3, #0
    adds r0, #0x25
    strb r2, [r0]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #2
    strb r0, [r1]
    b lbl_0803a778
    .align 2, 0
lbl_0803a724: .4byte 0x0000fffb
lbl_0803a728: .4byte 0x082f5eac
lbl_0803a72c:
    ldr r1, lbl_0803a750 @ =0x030001ac
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r1, [r0, #2]
    strh r1, [r3, #2]
    ldrh r0, [r0, #4]
    strh r0, [r3, #4]
    ldr r0, lbl_0803a754 @ =0x0300070c
    ldrb r1, [r0, #0xd]
    adds r2, r0, #0
    cmp r1, #0
    bne lbl_0803a75c
    ldrh r1, [r3]
    ldr r0, lbl_0803a758 @ =0x0000fffb
    ands r0, r1
    b lbl_0803a762
    .align 2, 0
lbl_0803a750: .4byte 0x030001ac
lbl_0803a754: .4byte 0x0300070c
lbl_0803a758: .4byte 0x0000fffb
lbl_0803a75c:
    ldrh r0, [r3]
    movs r1, #4
    orrs r0, r1
lbl_0803a762:
    strh r0, [r3]
    ldrb r0, [r2, #0xf]
    cmp r0, #4
    bne lbl_0803a778
    mov r1, ip
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    b lbl_0803a778
lbl_0803a774:
    movs r0, #0
    strh r0, [r3]
lbl_0803a778:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RuinsTestGhostOutline
RuinsTestGhostOutline: @ 0x0803a780
    push {r4, lr}
    sub sp, #0xc
    ldr r4, lbl_0803a798 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r3, [r0]
    cmp r3, #0
    beq lbl_0803a79c
    cmp r3, #9
    beq lbl_0803a820
    b lbl_0803a8a0
    .align 2, 0
lbl_0803a798: .4byte 0x03000738
lbl_0803a79c:
    ldrh r1, [r4]
    ldr r0, lbl_0803a7dc @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    strh r3, [r4, #0xa]
    strh r3, [r4, #0xc]
    strh r3, [r4, #0xe]
    strh r3, [r4, #0x10]
    strh r3, [r4, #0x16]
    strb r2, [r4, #0x1c]
    subs r0, #4
    strb r2, [r0]
    ldrb r1, [r4, #0x1e]
    cmp r1, #0
    beq lbl_0803a7f8
    adds r2, r4, #0
    adds r2, #0x22
    movs r0, #0xe
    strb r0, [r2]
    cmp r1, #1
    bne lbl_0803a7e4
    ldr r0, lbl_0803a7e0 @ =0x082f62dc
    b lbl_0803a7e6
    .align 2, 0
lbl_0803a7dc: .4byte 0x0000fffb
lbl_0803a7e0: .4byte 0x082f62dc
lbl_0803a7e4:
    ldr r0, lbl_0803a7f0 @ =0x082f5ce4
lbl_0803a7e6:
    str r0, [r4, #0x18]
    ldr r0, lbl_0803a7f4 @ =0x000001db
    bl SoundPlay
    b lbl_0803a80c
    .align 2, 0
lbl_0803a7f0: .4byte 0x082f5ce4
lbl_0803a7f4: .4byte 0x000001db
lbl_0803a7f8:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xd
    strb r0, [r1]
    ldr r0, lbl_0803a818 @ =0x082f5ce4
    str r0, [r4, #0x18]
    movs r0, #0xeb
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803a80c:
    ldr r0, lbl_0803a81c @ =0x03000738
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    b lbl_0803a8a0
    .align 2, 0
lbl_0803a818: .4byte 0x082f5ce4
lbl_0803a81c: .4byte 0x03000738
lbl_0803a820:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    beq lbl_0803a888
    ldrh r0, [r4, #0x16]
    cmp r0, #4
    bne lbl_0803a888
    ldrb r0, [r4, #0x1c]
    cmp r0, #8
    bne lbl_0803a888
    movs r0, #3
    bl make_background_flash
    ldrb r0, [r4, #0x1e]
    cmp r0, #1
    bne lbl_0803a864
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r1, lbl_0803a860 @ =0x0300080c
    ldrh r0, [r1]
    str r0, [sp]
    ldrh r0, [r1, #2]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x42
    movs r1, #1
    bl SpriteSpawnSecondary
    b lbl_0803a888
    .align 2, 0
lbl_0803a860: .4byte 0x0300080c
lbl_0803a864:
    cmp r0, #2
    bne lbl_0803a888
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r0, lbl_0803a8a8 @ =0x0300080c
    ldrh r0, [r0]
    str r0, [sp]
    ldr r0, lbl_0803a8ac @ =0x030013d4
    ldrh r0, [r0, #0x12]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x42
    movs r1, #2
    bl SpriteSpawnSecondary
lbl_0803a888:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803a8a0
    ldr r0, lbl_0803a8b0 @ =0x03000738
    movs r1, #0
    strh r1, [r0]
    ldrb r0, [r0, #0x1e]
    cmp r0, #0
    beq lbl_0803a8a0
    ldr r0, lbl_0803a8a8 @ =0x0300080c
    strh r1, [r0, #6]
lbl_0803a8a0:
    add sp, #0xc
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803a8a8: .4byte 0x0300080c
lbl_0803a8ac: .4byte 0x030013d4
lbl_0803a8b0: .4byte 0x03000738

    thumb_func_start RuinsTestShootableSymbol
RuinsTestShootableSymbol: @ 0x0803a8b4
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r2, lbl_0803a900 @ =0x03000738
    ldr r1, lbl_0803a904 @ =0x0300070c
    ldrh r0, [r1, #6]
    strh r0, [r2, #2]
    ldrh r0, [r1, #8]
    strh r0, [r2, #4]
    adds r3, r2, #0
    adds r3, #0x24
    ldrb r0, [r3]
    adds r4, r2, #0
    adds r2, r1, #0
    cmp r0, #0
    beq lbl_0803a8ea
    ldrh r1, [r2, #0xa]
    ldrh r0, [r4, #0x14]
    cmp r0, r1
    beq lbl_0803a8ea
    strh r1, [r4, #0x14]
    ldr r0, lbl_0803a908 @ =0x082f5f9c
    str r0, [r4, #0x18]
    movs r0, #0
    strh r0, [r4, #0x16]
    strb r0, [r4, #0x1c]
    movs r0, #0x27
    strb r0, [r3]
lbl_0803a8ea:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x27
    bls lbl_0803a8f6
    b lbl_0803aade
lbl_0803a8f6:
    lsls r0, r0, #2
    ldr r1, lbl_0803a90c @ =lbl_0803a910
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803a900: .4byte 0x03000738
lbl_0803a904: .4byte 0x0300070c
lbl_0803a908: .4byte 0x082f5f9c
lbl_0803a90c: .4byte lbl_0803a910
lbl_0803a910: @ jump table
    .4byte lbl_0803a9b0 @ case 0
    .4byte lbl_0803aade @ case 1
    .4byte lbl_0803aade @ case 2
    .4byte lbl_0803aade @ case 3
    .4byte lbl_0803aade @ case 4
    .4byte lbl_0803aade @ case 5
    .4byte lbl_0803aade @ case 6
    .4byte lbl_0803aade @ case 7
    .4byte lbl_0803aade @ case 8
    .4byte lbl_0803aa04 @ case 9
    .4byte lbl_0803aade @ case 10
    .4byte lbl_0803aade @ case 11
    .4byte lbl_0803aade @ case 12
    .4byte lbl_0803aade @ case 13
    .4byte lbl_0803aade @ case 14
    .4byte lbl_0803aade @ case 15
    .4byte lbl_0803aade @ case 16
    .4byte lbl_0803aade @ case 17
    .4byte lbl_0803aade @ case 18
    .4byte lbl_0803aade @ case 19
    .4byte lbl_0803aade @ case 20
    .4byte lbl_0803aade @ case 21
    .4byte lbl_0803aade @ case 22
    .4byte lbl_0803aade @ case 23
    .4byte lbl_0803aade @ case 24
    .4byte lbl_0803aade @ case 25
    .4byte lbl_0803aade @ case 26
    .4byte lbl_0803aade @ case 27
    .4byte lbl_0803aade @ case 28
    .4byte lbl_0803aade @ case 29
    .4byte lbl_0803aade @ case 30
    .4byte lbl_0803aade @ case 31
    .4byte lbl_0803aade @ case 32
    .4byte lbl_0803aade @ case 33
    .4byte lbl_0803aade @ case 34
    .4byte lbl_0803aa2c @ case 35
    .4byte lbl_0803aade @ case 36
    .4byte lbl_0803aa54 @ case 37
    .4byte lbl_0803aade @ case 38
    .4byte lbl_0803aa68 @ case 39
lbl_0803a9b0:
    ldrh r1, [r4]
    ldr r0, lbl_0803a9fc @ =0x0000fffb
    ands r0, r1
    movs r3, #0
    movs r2, #0
    movs r5, #0x80
    lsls r5, r5, #8
    adds r1, r5, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    strh r2, [r4, #0xa]
    strh r2, [r4, #0xc]
    strh r2, [r4, #0xe]
    strh r2, [r4, #0x10]
    ldr r0, lbl_0803aa00 @ =0x082f5eec
    str r0, [r4, #0x18]
    strh r2, [r4, #0x16]
    strb r3, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x25
    strb r3, [r0]
    movs r0, #0xec
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803aade
    .align 2, 0
lbl_0803a9fc: .4byte 0x0000fffb
lbl_0803aa00: .4byte 0x082f5eec
lbl_0803aa04:
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803aade
    ldr r0, lbl_0803aa28 @ =0x082f5f3c
    str r0, [r4, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r4, #0x16]
    strb r1, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    b lbl_0803aade
    .align 2, 0
lbl_0803aa28: .4byte 0x082f5f3c
lbl_0803aa2c:
    ldrb r1, [r2, #0xd]
    cmp r1, #0
    bne lbl_0803aade
    ldr r0, lbl_0803aa50 @ =0x082f5f74
    str r0, [r4, #0x18]
    movs r0, #0
    strh r1, [r4, #0x16]
    strb r0, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    movs r0, #0xec
    lsls r0, r0, #1
    movs r1, #0x28
    bl SoundFade
    b lbl_0803aade
    .align 2, 0
lbl_0803aa50: .4byte 0x082f5f74
lbl_0803aa54:
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803aade
    movs r0, #0
    strh r0, [r4]
    b lbl_0803aade
lbl_0803aa68:
    ldrb r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0803aab4
    ldrh r0, [r4, #0x16]
    cmp r0, #6
    beq lbl_0803aa94
    cmp r0, #6
    bgt lbl_0803aa7e
    cmp r0, #5
    beq lbl_0803aa84
    b lbl_0803aab4
lbl_0803aa7e:
    cmp r0, #7
    beq lbl_0803aaa4
    b lbl_0803aab4
lbl_0803aa84:
    ldr r1, lbl_0803aa8c @ =0x040000d4
    ldr r0, lbl_0803aa90 @ =0x082f476c
    b lbl_0803aaa8
    .align 2, 0
lbl_0803aa8c: .4byte 0x040000d4
lbl_0803aa90: .4byte 0x082f476c
lbl_0803aa94:
    ldr r1, lbl_0803aa9c @ =0x040000d4
    ldr r0, lbl_0803aaa0 @ =0x082f475c
    b lbl_0803aaa8
    .align 2, 0
lbl_0803aa9c: .4byte 0x040000d4
lbl_0803aaa0: .4byte 0x082f475c
lbl_0803aaa4:
    ldr r1, lbl_0803aae8 @ =0x040000d4
    ldr r0, lbl_0803aaec @ =0x082f471c
lbl_0803aaa8:
    str r0, [r1]
    ldr r0, lbl_0803aaf0 @ =0x050003c0
    str r0, [r1, #4]
    ldr r0, lbl_0803aaf4 @ =0x80000008
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0803aab4:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803aade
    ldr r4, lbl_0803aaf8 @ =0x0300070c
    movs r5, #0
    strb r5, [r4, #0xd]
    ldr r0, lbl_0803aafc @ =0x03000738
    strh r5, [r0]
    ldrh r1, [r4, #0xa]
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #6]
    str r0, [sp]
    ldrh r0, [r4, #8]
    str r0, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0x3f
    bl SpriteSpawnSecondary
lbl_0803aade:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803aae8: .4byte 0x040000d4
lbl_0803aaec: .4byte 0x082f471c
lbl_0803aaf0: .4byte 0x050003c0
lbl_0803aaf4: .4byte 0x80000008
lbl_0803aaf8: .4byte 0x0300070c
lbl_0803aafc: .4byte 0x03000738

    thumb_func_start RuinsTestGhost
RuinsTestGhost: @ 0x0803ab00
    push {lr}
    ldr r0, lbl_0803ab18 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    bls lbl_0803ab0e
    b lbl_0803ac64
lbl_0803ab0e:
    lsls r0, r0, #2
    ldr r1, lbl_0803ab1c @ =lbl_0803ab20
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803ab18: .4byte 0x03000738
lbl_0803ab1c: .4byte lbl_0803ab20
lbl_0803ab20: @ jump table
    .4byte lbl_0803ac30 @ case 0
    .4byte lbl_0803ac64 @ case 1
    .4byte lbl_0803ac64 @ case 2
    .4byte lbl_0803ac64 @ case 3
    .4byte lbl_0803ac64 @ case 4
    .4byte lbl_0803ac64 @ case 5
    .4byte lbl_0803ac64 @ case 6
    .4byte lbl_0803ac64 @ case 7
    .4byte lbl_0803ac36 @ case 8
    .4byte lbl_0803ac3c @ case 9
    .4byte lbl_0803ac64 @ case 10
    .4byte lbl_0803ac64 @ case 11
    .4byte lbl_0803ac64 @ case 12
    .4byte lbl_0803ac64 @ case 13
    .4byte lbl_0803ac64 @ case 14
    .4byte lbl_0803ac64 @ case 15
    .4byte lbl_0803ac64 @ case 16
    .4byte lbl_0803ac64 @ case 17
    .4byte lbl_0803ac64 @ case 18
    .4byte lbl_0803ac64 @ case 19
    .4byte lbl_0803ac64 @ case 20
    .4byte lbl_0803ac64 @ case 21
    .4byte lbl_0803ac64 @ case 22
    .4byte lbl_0803ac64 @ case 23
    .4byte lbl_0803ac64 @ case 24
    .4byte lbl_0803ac64 @ case 25
    .4byte lbl_0803ac64 @ case 26
    .4byte lbl_0803ac64 @ case 27
    .4byte lbl_0803ac64 @ case 28
    .4byte lbl_0803ac64 @ case 29
    .4byte lbl_0803ac64 @ case 30
    .4byte lbl_0803ac64 @ case 31
    .4byte lbl_0803ac64 @ case 32
    .4byte lbl_0803ac64 @ case 33
    .4byte lbl_0803ac64 @ case 34
    .4byte lbl_0803ac48 @ case 35
    .4byte lbl_0803ac64 @ case 36
    .4byte lbl_0803ac4e @ case 37
    .4byte lbl_0803ac54 @ case 38
    .4byte lbl_0803ac5a @ case 39
    .4byte lbl_0803ac64 @ case 40
    .4byte lbl_0803ac60 @ case 41
    .4byte lbl_0803ac64 @ case 42
    .4byte lbl_0803ac4e @ case 43
    .4byte lbl_0803ac64 @ case 44
    .4byte lbl_0803ac64 @ case 45
    .4byte lbl_0803ac64 @ case 46
    .4byte lbl_0803ac64 @ case 47
    .4byte lbl_0803ac64 @ case 48
    .4byte lbl_0803ac64 @ case 49
    .4byte lbl_0803ac64 @ case 50
    .4byte lbl_0803ac64 @ case 51
    .4byte lbl_0803ac64 @ case 52
    .4byte lbl_0803ac64 @ case 53
    .4byte lbl_0803ac64 @ case 54
    .4byte lbl_0803ac64 @ case 55
    .4byte lbl_0803ac64 @ case 56
    .4byte lbl_0803ac64 @ case 57
    .4byte lbl_0803ac64 @ case 58
    .4byte lbl_0803ac64 @ case 59
    .4byte lbl_0803ac64 @ case 60
    .4byte lbl_0803ac64 @ case 61
    .4byte lbl_0803ac64 @ case 62
    .4byte lbl_0803ac64 @ case 63
    .4byte lbl_0803ac64 @ case 64
    .4byte lbl_0803ac64 @ case 65
    .4byte lbl_0803ac64 @ case 66
    .4byte lbl_0803ac42 @ case 67
lbl_0803ac30:
    bl RuinsTestGhostInit
    b lbl_0803ac64
lbl_0803ac36:
    bl RuinsTestGhostSpawn
    b lbl_0803ac64
lbl_0803ac3c:
    bl ruins_test_ghost_sync_pos
    b lbl_0803ac64
lbl_0803ac42:
    bl RuinsTestGhostDespawn
    b lbl_0803ac64
lbl_0803ac48:
    bl RuinsTestGhostMoveSymbolToPlace
    b lbl_0803ac64
lbl_0803ac4e:
    bl RuinsTestGhostSymbolPlacing
    b lbl_0803ac64
lbl_0803ac54:
    bl RuinsTestGhostSymbolSetGhostDisappearing
    b lbl_0803ac64
lbl_0803ac5a:
    bl sub_08039e14
    b lbl_0803ac64
lbl_0803ac60:
    bl sub_08039e3c
lbl_0803ac64:
    pop {r0}
    bx r0

    thumb_func_start RuinsTestSamusReflectionEnd
RuinsTestSamusReflectionEnd: @ 0x0803ac68
    push {r4, r5, lr}
    sub sp, #8
    ldr r0, lbl_0803acb0 @ =0x0300070c
    ldrb r1, [r0, #0xf]
    adds r2, r0, #0
    cmp r1, #4
    bls lbl_0803acbc
    ldrb r0, [r2, #0xf]
    cmp r0, #5
    bne lbl_0803ac7e
    b lbl_0803b034
lbl_0803ac7e:
    cmp r0, #6
    beq lbl_0803ac84
    b lbl_0803b034
lbl_0803ac84:
    ldr r2, lbl_0803acb4 @ =0x03000738
    movs r4, #0
    strh r4, [r2]
    ldr r3, lbl_0803acb8 @ =0x030001ac
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r1, [r0]
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    strh r4, [r0]
    ldrh r3, [r2, #2]
    ldrh r0, [r2, #4]
    str r0, [sp]
    str r4, [sp, #4]
    movs r0, #0x11
    movs r1, #0x20
    movs r2, #6
    bl SpriteSpawnPrimary
    b lbl_0803b034
    .align 2, 0
lbl_0803acb0: .4byte 0x0300070c
lbl_0803acb4: .4byte 0x03000738
lbl_0803acb8: .4byte 0x030001ac
lbl_0803acbc:
    ldr r1, lbl_0803acd8 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #0x25
    bls lbl_0803accc
    b lbl_0803b034
lbl_0803accc:
    lsls r0, r0, #2
    ldr r1, lbl_0803acdc @ =lbl_0803ace0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803acd8: .4byte 0x03000738
lbl_0803acdc: .4byte lbl_0803ace0
lbl_0803ace0: @ jump table
    .4byte lbl_0803ad78 @ case 0
    .4byte lbl_0803b034 @ case 1
    .4byte lbl_0803b034 @ case 2
    .4byte lbl_0803b034 @ case 3
    .4byte lbl_0803b034 @ case 4
    .4byte lbl_0803b034 @ case 5
    .4byte lbl_0803b034 @ case 6
    .4byte lbl_0803b034 @ case 7
    .4byte lbl_0803ae2c @ case 8
    .4byte lbl_0803af1c @ case 9
    .4byte lbl_0803b034 @ case 10
    .4byte lbl_0803b034 @ case 11
    .4byte lbl_0803b034 @ case 12
    .4byte lbl_0803b034 @ case 13
    .4byte lbl_0803b034 @ case 14
    .4byte lbl_0803b034 @ case 15
    .4byte lbl_0803b034 @ case 16
    .4byte lbl_0803b034 @ case 17
    .4byte lbl_0803b034 @ case 18
    .4byte lbl_0803b034 @ case 19
    .4byte lbl_0803b034 @ case 20
    .4byte lbl_0803b034 @ case 21
    .4byte lbl_0803b034 @ case 22
    .4byte lbl_0803b034 @ case 23
    .4byte lbl_0803b034 @ case 24
    .4byte lbl_0803b034 @ case 25
    .4byte lbl_0803b034 @ case 26
    .4byte lbl_0803b034 @ case 27
    .4byte lbl_0803b034 @ case 28
    .4byte lbl_0803b034 @ case 29
    .4byte lbl_0803b034 @ case 30
    .4byte lbl_0803b034 @ case 31
    .4byte lbl_0803b034 @ case 32
    .4byte lbl_0803b034 @ case 33
    .4byte lbl_0803b034 @ case 34
    .4byte lbl_0803afc0 @ case 35
    .4byte lbl_0803b034 @ case 36
    .4byte lbl_0803b018 @ case 37
lbl_0803ad78:
    ldrh r1, [r4]
    ldr r0, lbl_0803adfc @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    movs r1, #0
    strh r0, [r4]
    adds r3, r4, #0
    adds r3, #0x27
    movs r0, #0x28
    strb r0, [r3]
    adds r0, r4, #0
    adds r0, #0x28
    strb r2, [r0]
    adds r3, #2
    movs r0, #0x10
    strb r0, [r3]
    strh r1, [r4, #0xa]
    strh r1, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r1, [r4, #0x10]
    ldr r0, lbl_0803ae00 @ =0x082f5cd4
    str r0, [r4, #0x18]
    strh r1, [r4, #0x16]
    strb r2, [r4, #0x1c]
    adds r0, r4, #0
    adds r0, #0x24
    movs r3, #8
    strb r3, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xb
    strb r0, [r1]
    ldr r1, lbl_0803ae04 @ =0x040000d4
    ldr r0, lbl_0803ae08 @ =0x082f43dc
    str r0, [r1]
    ldr r0, lbl_0803ae0c @ =0x06014280
    str r0, [r1, #4]
    ldr r0, lbl_0803ae10 @ =0x800000c0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_0803ae14 @ =0x082f455c
    str r0, [r1]
    ldr r0, lbl_0803ae18 @ =0x06014680
    str r0, [r1, #4]
    ldr r0, lbl_0803ae1c @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_0803ae20 @ =0x082f47bc
    str r0, [r1]
    ldr r0, lbl_0803ae24 @ =0x050003e0
    str r0, [r1, #4]
    ldr r0, lbl_0803ae28 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    adds r0, r4, #0
    adds r0, #0x2c
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r0, #1
    strb r3, [r0]
    adds r0, #1
    strb r2, [r0]
    b lbl_0803b034
    .align 2, 0
lbl_0803adfc: .4byte 0x0000fffb
lbl_0803ae00: .4byte 0x082f5cd4
lbl_0803ae04: .4byte 0x040000d4
lbl_0803ae08: .4byte 0x082f43dc
lbl_0803ae0c: .4byte 0x06014280
lbl_0803ae10: .4byte 0x800000c0
lbl_0803ae14: .4byte 0x082f455c
lbl_0803ae18: .4byte 0x06014680
lbl_0803ae1c: .4byte 0x80000080
lbl_0803ae20: .4byte 0x082f47bc
lbl_0803ae24: .4byte 0x050003e0
lbl_0803ae28: .4byte 0x80000010
lbl_0803ae2c:
    adds r1, r4, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    movs r3, #0xff
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0803ae9c
    movs r0, #8
    strb r0, [r1]
    adds r2, r4, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0803ae60
    subs r1, #2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ands r0, r3
    cmp r0, #9
    bls lbl_0803ae82
    movs r0, #1
    strb r0, [r2]
    b lbl_0803ae82
lbl_0803ae60:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ands r0, r3
    cmp r0, #0
    bne lbl_0803ae82
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803ae82
    subs r1, #8
    movs r0, #9
    strb r0, [r1]
lbl_0803ae82:
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    ldr r2, lbl_0803aeb0 @ =0x040000d4
    lsls r0, r3, #5
    ldr r1, lbl_0803aeb4 @ =0x082f47bc
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0803aeb8 @ =0x050003e0
    str r0, [r2, #4]
    ldr r0, lbl_0803aebc @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0803ae9c:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #9
    bne lbl_0803aec0
    adds r1, r4, #0
    adds r1, #0x2c
    movs r0, #0x1f
    strb r0, [r1]
    b lbl_0803b034
    .align 2, 0
lbl_0803aeb0: .4byte 0x040000d4
lbl_0803aeb4: .4byte 0x082f47bc
lbl_0803aeb8: .4byte 0x050003e0
lbl_0803aebc: .4byte 0x80000010
lbl_0803aec0:
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0803aecc
    b lbl_0803b034
lbl_0803aecc:
    ldrh r2, [r4, #4]
    adds r0, r2, #0
    subs r0, #0xc
    ldr r4, lbl_0803af0c @ =0x030013d4
    ldrh r1, [r4, #0x12]
    cmp r0, r1
    blt lbl_0803aedc
    b lbl_0803b034
lbl_0803aedc:
    adds r0, #0x18
    cmp r0, r1
    bgt lbl_0803aee4
    b lbl_0803b034
lbl_0803aee4:
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_0803af10 @ =0x0300080c
    ldrh r0, [r0]
    ldr r3, lbl_0803af14 @ =0x0000012f
    adds r0, r0, r3
    cmp r1, r0
    beq lbl_0803aef4
    b lbl_0803b034
lbl_0803aef4:
    strh r2, [r4, #0x12]
    movs r0, #0x3f
    bl SamusSetPose
    movs r1, #1
    movs r0, #1
    strh r0, [r4, #0xc]
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    ldr r0, lbl_0803af18 @ =0x03000049
    b lbl_0803b032
    .align 2, 0
lbl_0803af0c: .4byte 0x030013d4
lbl_0803af10: .4byte 0x0300080c
lbl_0803af14: .4byte 0x0000012f
lbl_0803af18: .4byte 0x03000049
lbl_0803af1c:
    adds r2, r4, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    subs r1, r0, #1
    strb r1, [r2]
    lsls r0, r1, #0x18
    cmp r0, #0
    bne lbl_0803af74
    ldrh r1, [r4]
    ldr r0, lbl_0803af60 @ =0x0000fffb
    ands r0, r1
    strh r0, [r4]
    ldr r1, lbl_0803af64 @ =0x040000d4
    ldr r0, lbl_0803af68 @ =0x082f499c
    str r0, [r1]
    ldr r0, lbl_0803af6c @ =0x050003e0
    str r0, [r1, #4]
    ldr r0, lbl_0803af70 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #1
    strb r0, [r2]
    adds r1, #9
    movs r0, #0xc
    strb r0, [r1]
    movs r0, #0xc8
    bl MusicFade
    b lbl_0803b034
    .align 2, 0
lbl_0803af60: .4byte 0x0000fffb
lbl_0803af64: .4byte 0x040000d4
lbl_0803af68: .4byte 0x082f499c
lbl_0803af6c: .4byte 0x050003e0
lbl_0803af70: .4byte 0x80000010
lbl_0803af74:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x1e
    bne lbl_0803b034
    ldrh r1, [r4]
    movs r0, #4
    orrs r0, r1
    strh r0, [r4]
    ldr r1, lbl_0803afa4 @ =0x040000d4
    ldr r0, lbl_0803afa8 @ =0x082f415c
    str r0, [r1]
    ldr r0, lbl_0803afac @ =0x06014280
    str r0, [r1, #4]
    ldr r0, lbl_0803afb0 @ =0x800000c0
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_0803afb4 @ =0x082f42dc
    str r0, [r1]
    ldr r0, lbl_0803afb8 @ =0x06014680
    str r0, [r1, #4]
    ldr r0, lbl_0803afbc @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0803b034
    .align 2, 0
lbl_0803afa4: .4byte 0x040000d4
lbl_0803afa8: .4byte 0x082f415c
lbl_0803afac: .4byte 0x06014280
lbl_0803afb0: .4byte 0x800000c0
lbl_0803afb4: .4byte 0x082f42dc
lbl_0803afb8: .4byte 0x06014680
lbl_0803afbc: .4byte 0x80000080
lbl_0803afc0:
    adds r1, r4, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0803b034
    movs r0, #0xc
    strb r0, [r1]
    adds r5, r4, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    adds r1, r0, #1
    strb r1, [r5]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r2, lbl_0803b008 @ =0x040000d4
    lsls r0, r3, #5
    ldr r1, lbl_0803b00c @ =0x082f499c
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0803b010 @ =0x050003e0
    str r0, [r2, #4]
    ldr r0, lbl_0803b014 @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    cmp r3, #8
    ble lbl_0803b034
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x25
    strb r1, [r0]
    movs r0, #0x14
    strb r0, [r5]
    b lbl_0803b034
    .align 2, 0
lbl_0803b008: .4byte 0x040000d4
lbl_0803b00c: .4byte 0x082f499c
lbl_0803b010: .4byte 0x050003e0
lbl_0803b014: .4byte 0x80000010
lbl_0803b018:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_0803b034
    movs r0, #5
    strb r0, [r2, #0xf]
    adds r0, r4, #0
    adds r0, #0x24
lbl_0803b032:
    strb r1, [r0]
lbl_0803b034:
    add sp, #8
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start RuinsTestLightningOnGroundInit
RuinsTestLightningOnGroundInit: @ 0x0803b03c
    ldr r0, lbl_0803b060 @ =0x03000738
    ldr r1, lbl_0803b064 @ =0x082f61cc
    str r1, [r0, #0x18]
    movs r1, #0
    movs r2, #0
    strh r2, [r0, #0x16]
    strb r1, [r0, #0x1c]
    ldr r1, lbl_0803b068 @ =0x0000fff0
    strh r1, [r0, #0xa]
    strh r2, [r0, #0xc]
    subs r1, #0x50
    strh r1, [r0, #0xe]
    movs r1, #0x60
    strh r1, [r0, #0x10]
    adds r0, #0x24
    movs r1, #0x25
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0803b060: .4byte 0x03000738
lbl_0803b064: .4byte 0x082f61cc
lbl_0803b068: .4byte 0x0000fff0

    thumb_func_start RuinsTestLightning
RuinsTestLightning: @ 0x0803b06c
    push {r4, r5, lr}
    sub sp, #0xc
    movs r4, #0x10
    ldr r0, lbl_0803b084 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    beq lbl_0803b08c
    ldr r1, lbl_0803b088 @ =0x03000738
    movs r0, #0
    strh r0, [r1]
    b lbl_0803b360
    .align 2, 0
lbl_0803b084: .4byte 0x0300070c
lbl_0803b088: .4byte 0x03000738
lbl_0803b08c:
    ldr r1, lbl_0803b0a8 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #0x27
    bls lbl_0803b09c
    b lbl_0803b360
lbl_0803b09c:
    lsls r0, r0, #2
    ldr r1, lbl_0803b0ac @ =lbl_0803b0b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803b0a8: .4byte 0x03000738
lbl_0803b0ac: .4byte lbl_0803b0b0
lbl_0803b0b0: @ jump table
    .4byte lbl_0803b150 @ case 0
    .4byte lbl_0803b360 @ case 1
    .4byte lbl_0803b360 @ case 2
    .4byte lbl_0803b360 @ case 3
    .4byte lbl_0803b360 @ case 4
    .4byte lbl_0803b360 @ case 5
    .4byte lbl_0803b360 @ case 6
    .4byte lbl_0803b360 @ case 7
    .4byte lbl_0803b360 @ case 8
    .4byte lbl_0803b1c4 @ case 9
    .4byte lbl_0803b360 @ case 10
    .4byte lbl_0803b360 @ case 11
    .4byte lbl_0803b360 @ case 12
    .4byte lbl_0803b360 @ case 13
    .4byte lbl_0803b360 @ case 14
    .4byte lbl_0803b360 @ case 15
    .4byte lbl_0803b360 @ case 16
    .4byte lbl_0803b360 @ case 17
    .4byte lbl_0803b360 @ case 18
    .4byte lbl_0803b360 @ case 19
    .4byte lbl_0803b360 @ case 20
    .4byte lbl_0803b360 @ case 21
    .4byte lbl_0803b360 @ case 22
    .4byte lbl_0803b360 @ case 23
    .4byte lbl_0803b360 @ case 24
    .4byte lbl_0803b360 @ case 25
    .4byte lbl_0803b360 @ case 26
    .4byte lbl_0803b360 @ case 27
    .4byte lbl_0803b360 @ case 28
    .4byte lbl_0803b360 @ case 29
    .4byte lbl_0803b360 @ case 30
    .4byte lbl_0803b360 @ case 31
    .4byte lbl_0803b360 @ case 32
    .4byte lbl_0803b360 @ case 33
    .4byte lbl_0803b360 @ case 34
    .4byte lbl_0803b24c @ case 35
    .4byte lbl_0803b360 @ case 36
    .4byte lbl_0803b280 @ case 37
    .4byte lbl_0803b360 @ case 38
    .4byte lbl_0803b328 @ case 39
lbl_0803b150:
    ldr r4, lbl_0803b1a0 @ =0x03000738
    ldrh r1, [r4]
    ldr r0, lbl_0803b1a4 @ =0x0000fffb
    ands r0, r1
    movs r5, #0
    movs r2, #0
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x27
    movs r0, #0x50
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x20
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x28
    strb r0, [r1]
    subs r1, #4
    movs r0, #4
    strb r0, [r1]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    beq lbl_0803b1ac
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r4, #0xa]
    strh r2, [r4, #0xc]
    adds r0, #0xf0
    strh r0, [r4, #0xe]
    movs r0, #0x10
    strh r0, [r4, #0x10]
    ldr r0, lbl_0803b1a8 @ =0x082f6124
    str r0, [r4, #0x18]
    strh r2, [r4, #0x16]
    strb r5, [r4, #0x1c]
    subs r1, #1
    movs r0, #9
    strb r0, [r1]
    b lbl_0803b1b6
    .align 2, 0
lbl_0803b1a0: .4byte 0x03000738
lbl_0803b1a4: .4byte 0x0000fffb
lbl_0803b1a8: .4byte 0x082f6124
lbl_0803b1ac:
    bl RuinsTestLightningOnGroundInit
    adds r0, r4, #0
    adds r0, #0x2c
    strb r5, [r0]
lbl_0803b1b6:
    ldr r0, lbl_0803b1c0 @ =0x03000738
    adds r0, #0x22
    movs r1, #1
    strb r1, [r0]
    b lbl_0803b360
    .align 2, 0
lbl_0803b1c0: .4byte 0x03000738
lbl_0803b1c4:
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0803b1f4 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803b21c
    movs r2, #0
    strh r1, [r5, #2]
    ldrb r0, [r5, #0x1e]
    cmp r0, #2
    bne lbl_0803b1fc
    strh r2, [r5]
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    movs r2, #0x1e
    bl ParticleSet
    ldr r0, lbl_0803b1f8 @ =0x000001dd
    bl SoundPlay
    b lbl_0803b360
    .align 2, 0
lbl_0803b1f4: .4byte 0x030007f0
lbl_0803b1f8: .4byte 0x000001dd
lbl_0803b1fc:
    ldr r0, lbl_0803b218 @ =0x082f6184
    str r0, [r5, #0x18]
    strh r2, [r5, #0x16]
    movs r0, #0
    strb r0, [r5, #0x1c]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #0xef
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803b360
    .align 2, 0
lbl_0803b218: .4byte 0x082f6184
lbl_0803b21c:
    ldrh r0, [r5, #2]
    adds r0, r4, r0
    strh r0, [r5, #2]
    ldrh r1, [r5]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803b232
    b lbl_0803b360
lbl_0803b232:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0803b23c
    b lbl_0803b360
lbl_0803b23c:
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r5]
    movs r0, #0xee
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803b360
lbl_0803b24c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0803b256
    b lbl_0803b360
lbl_0803b256:
    bl RuinsTestLightningOnGroundInit
    ldr r1, lbl_0803b27c @ =0x03000738
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    str r0, [sp]
    ldrh r0, [r1, #4]
    str r0, [sp, #4]
    movs r0, #0x40
    str r0, [sp, #8]
    movs r0, #0x42
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0803b360
    .align 2, 0
lbl_0803b27c: .4byte 0x03000738
lbl_0803b280:
    ldr r1, lbl_0803b2b4 @ =0x03000738
    ldrb r0, [r1, #0x1e]
    cmp r0, #0
    bne lbl_0803b2a0
    adds r1, #0x2c
    ldrb r2, [r1]
    adds r0, r2, #1
    strb r0, [r1]
    movs r0, #0x1f
    ands r0, r2
    cmp r0, #0
    bne lbl_0803b2a0
    movs r0, #0xef
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803b2a0:
    ldr r2, lbl_0803b2b4 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    adds r5, r2, #0
    cmp r0, #0
    beq lbl_0803b2b8
    ldrh r0, [r5, #4]
    adds r0, r4, r0
    b lbl_0803b2bc
    .align 2, 0
lbl_0803b2b4: .4byte 0x03000738
lbl_0803b2b8:
    ldrh r0, [r5, #4]
    subs r0, r0, r4
lbl_0803b2bc:
    strh r0, [r5, #4]
    adds r4, r5, #0
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0803b360
    ldr r0, lbl_0803b308 @ =0x082f6254
    str r0, [r4, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r4, #0x16]
    strb r1, [r4, #0x1c]
    ldr r0, lbl_0803b30c @ =0x0000ffa0
    strh r0, [r4, #0xa]
    movs r0, #0x60
    strh r0, [r4, #0xc]
    ldr r0, lbl_0803b310 @ =0x0000fff0
    strh r0, [r4, #0xe]
    movs r0, #0x10
    strh r0, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x27
    strb r0, [r1]
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0803b318
    ldrh r1, [r4, #4]
    ldr r0, lbl_0803b314 @ =0x0000ffc0
    ands r0, r1
    strh r0, [r4, #4]
    b lbl_0803b360
    .align 2, 0
lbl_0803b308: .4byte 0x082f6254
lbl_0803b30c: .4byte 0x0000ffa0
lbl_0803b310: .4byte 0x0000fff0
lbl_0803b314: .4byte 0x0000ffc0
lbl_0803b318:
    ldrh r1, [r5, #4]
    ldr r0, lbl_0803b324 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x40
    strh r0, [r5, #4]
    b lbl_0803b360
    .align 2, 0
lbl_0803b324: .4byte 0x0000ffc0
lbl_0803b328:
    ldr r1, lbl_0803b368 @ =0x03000738
    ldrb r0, [r1, #0x1e]
    cmp r0, #0
    bne lbl_0803b348
    adds r1, #0x2c
    ldrb r2, [r1]
    adds r0, r2, #1
    strb r0, [r1]
    movs r0, #0x1f
    ands r0, r2
    cmp r0, #0
    bne lbl_0803b348
    movs r0, #0xef
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803b348:
    ldr r2, lbl_0803b368 @ =0x03000738
    ldrh r0, [r2, #2]
    subs r0, r0, r4
    strh r0, [r2, #2]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_0803b360
    strh r0, [r2]
lbl_0803b360:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803b368: .4byte 0x03000738
