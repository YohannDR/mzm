    .include "asm/macros.inc"

    .syntax unified

    
    thumb_func_start DisableChozodiaAlarm
DisableChozodiaAlarm: @ 0x080287e4
    push {lr}
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08028804
    ldr r1, lbl_08028800 @ =0x030001a8
    movs r2, #0xf0
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_08028822
    .align 2, 0
lbl_08028800: .4byte 0x030001a8
lbl_08028804:
    ldr r0, lbl_08028828 @ =0x030001a8
    strh r1, [r0]
    ldr r1, lbl_0802882c @ =0x0300004d
    movs r2, #1
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
    movs r0, #3
    movs r1, #0x43
    bl EventFunction
    cmp r0, #0
    bne lbl_08028822
    bl UpdateMusicAfterAlarmDisable
lbl_08028822:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08028828: .4byte 0x030001a8
lbl_0802882c: .4byte 0x0300004d

    thumb_func_start DecrementChozodiaAlarm
DecrementChozodiaAlarm: @ 0x08028830
    push {lr}
    ldr r1, lbl_0802884c @ =0x030001a8
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0802886a
    subs r0, #1
    strh r0, [r1]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_08028850
    bl DisableChozodiaAlarm
    b lbl_0802886a
    .align 2, 0
lbl_0802884c: .4byte 0x030001a8
lbl_08028850:
    ldr r0, lbl_08028870 @ =0x0300004d
    movs r1, #0
    strb r1, [r0]
    movs r0, #3
    movs r1, #0x43
    bl EventFunction
    cmp r0, #0
    bne lbl_0802886a
    movs r0, #0x45
    movs r1, #0x40
    bl PlayMusic
lbl_0802886a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08028870: .4byte 0x0300004d

    thumb_func_start spawn_space_pirates_waiting
spawn_space_pirates_waiting: @ 0x08028874
    push {r4, lr}
    sub sp, #8
    movs r4, #0
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    cmp r0, #0
    beq lbl_08028898
    ldr r1, lbl_08028894 @ =0x030001a8
    movs r2, #0xf0
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_080288a2
    .align 2, 0
lbl_08028894: .4byte 0x030001a8
lbl_08028898:
    ldr r0, lbl_080288ac @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_080288a2
    b lbl_080289a0
lbl_080288a2:
    movs r2, #0
    ldr r0, lbl_080288b0 @ =0x030006ec
    ldrb r3, [r0]
    adds r1, r0, #0
    b lbl_080288c2
    .align 2, 0
lbl_080288ac: .4byte 0x030001a8
lbl_080288b0: .4byte 0x030006ec
lbl_080288b4:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0xe
    bhi lbl_080288cc
    adds r0, r2, r1
    ldrb r3, [r0]
lbl_080288c2:
    cmp r3, #0x53
    bne lbl_080288b4
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_080288cc:
    cmp r4, #0
    bne lbl_08028910
    movs r2, #0
    ldr r1, lbl_080288d8 @ =0x030006ec
    b lbl_080288e2
    .align 2, 0
lbl_080288d8: .4byte 0x030006ec
lbl_080288dc:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_080288e2:
    cmp r2, #0xe
    bhi lbl_08028906
    adds r0, r2, r1
    ldrb r3, [r0]
    adds r0, r3, #0
    subs r0, #0x51
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_080288fe
    cmp r3, #0x54
    beq lbl_080288fe
    cmp r3, #0x55
    bne lbl_080288dc
lbl_080288fe:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r3, #0x52
lbl_08028906:
    cmp r4, #0
    bne lbl_08028910
    bl DisableChozodiaAlarm
    b lbl_080289a0
lbl_08028910:
    ldr r0, lbl_0802893c @ =0x030000f8
    ldrh r4, [r0, #2]
    ldrh r2, [r0]
    ldr r0, lbl_08028940 @ =0x03000057
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #2
    bne lbl_08028954
    ldr r0, lbl_08028944 @ =0x03000078
    ldrb r0, [r0]
    cmp r0, #0x58
    beq lbl_0802892e
    cmp r0, #0x67
    bne lbl_08028948
lbl_0802892e:
    str r2, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r3, #0
    movs r1, #0x81
    movs r2, #5
    b lbl_08028980
    .align 2, 0
lbl_0802893c: .4byte 0x030000f8
lbl_08028940: .4byte 0x03000057
lbl_08028944: .4byte 0x03000078
lbl_08028948:
    str r2, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r3, #0
    movs r1, #0x81
    b lbl_0802897e
lbl_08028954:
    ldr r0, lbl_08028970 @ =0x03000078
    ldrb r0, [r0]
    cmp r0, #0x58
    beq lbl_08028960
    cmp r0, #0x67
    bne lbl_08028974
lbl_08028960:
    str r2, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r3, #0
    movs r1, #0x80
    movs r2, #5
    b lbl_08028980
    .align 2, 0
lbl_08028970: .4byte 0x03000078
lbl_08028974:
    str r2, [sp]
    movs r0, #0
    str r0, [sp, #4]
    adds r0, r3, #0
    movs r1, #0x80
lbl_0802897e:
    movs r2, #0
lbl_08028980:
    adds r3, r4, #0
    bl SpriteSpawnPrimary
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_080289a8 @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
lbl_080289a0:
    add sp, #8
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080289a8: .4byte 0x030001ac

    thumb_func_start SpacePirateFlip
SpacePirateFlip: @ 0x080289ac
    push {lr}
    ldr r2, lbl_080289cc @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080289d4
    movs r0, #0x40
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_080289d0 @ =0x0000ffe8
    strh r0, [r2, #0xe]
    movs r0, #0x40
    b lbl_080289e0
    .align 2, 0
lbl_080289cc: .4byte 0x03000738
lbl_080289d0: .4byte 0x0000ffe8
lbl_080289d4:
    ldr r0, lbl_080289e8 @ =0x0000ffbf
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_080289ec @ =0x0000ffc0
    strh r0, [r2, #0xe]
    movs r0, #0x18
lbl_080289e0:
    strh r0, [r2, #0x10]
    pop {r0}
    bx r0
    .align 2, 0
lbl_080289e8: .4byte 0x0000ffbf
lbl_080289ec: .4byte 0x0000ffc0

    thumb_func_start SpacePirateSamusDetection
SpacePirateSamusDetection: @ 0x080289f0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    ldr r0, lbl_08028a24 @ =0x030013d4
    ldrh r1, [r0, #0x14]
    adds r1, #4
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    ldrh r4, [r0, #0x12]
    ldr r0, lbl_08028a28 @ =0x03000738
    ldrh r1, [r0, #2]
    str r1, [sp]
    ldrh r2, [r0, #4]
    str r2, [sp, #4]
    adds r7, r0, #0
    cmp r3, r1
    bls lbl_08028a30
    ldr r1, lbl_08028a2c @ =0x030007f3
    movs r0, #1
    strb r0, [r1, #3]
    ldr r5, [sp]
    subs r0, r3, r5
    b lbl_08028a3a
    .align 2, 0
lbl_08028a24: .4byte 0x030013d4
lbl_08028a28: .4byte 0x03000738
lbl_08028a2c: .4byte 0x030007f3
lbl_08028a30:
    ldr r1, lbl_08028a4c @ =0x030007f3
    movs r0, #0
    strb r0, [r1, #3]
    ldr r2, [sp]
    subs r0, r2, r3
lbl_08028a3a:
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r5, [sp, #4]
    cmp r4, r5
    bls lbl_08028a50
    movs r0, #1
    strb r0, [r1, #4]
    subs r0, r4, r5
    b lbl_08028a58
    .align 2, 0
lbl_08028a4c: .4byte 0x030007f3
lbl_08028a50:
    movs r0, #0
    strb r0, [r1, #4]
    ldr r2, [sp, #4]
    subs r0, r2, r4
lbl_08028a58:
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r0, lbl_08028a80 @ =0x0300080c
    movs r5, #0
    strh r2, [r0, #2]
    movs r0, #0xa0
    lsls r0, r0, #2
    cmp r2, r0
    bls lbl_08028a8c
    strb r5, [r1, #2]
    adds r1, r7, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08028a84
    subs r0, #1
    strb r0, [r1]
    bl lbl_080293f2
    .align 2, 0
lbl_08028a80: .4byte 0x0300080c
lbl_08028a84:
    movs r0, #0x3c
    strb r0, [r1]
    bl lbl_080293f2
lbl_08028a8c:
    cmp r6, r0
    bls lbl_08028a96
    strb r5, [r1, #2]
    bl lbl_080293f2
lbl_08028a96:
    ldr r1, lbl_08028b0c @ =0x030007f3
    movs r0, #1
    strb r0, [r1, #2]
    adds r1, r7, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08028aaa
    subs r0, #1
    strb r0, [r1]
lbl_08028aaa:
    ldr r0, lbl_08028b10 @ =0x0000ffc0
    mov r8, r3
    ands r3, r0
    mov r8, r3
    mov sl, r0
    mov r5, sl
    ands r5, r4
    mov sl, r5
    ldr r1, [sp]
    adds r2, r1, #0
    ands r2, r0
    str r2, [sp, #0xc]
    ldr r3, [sp, #4]
    adds r4, r3, #0
    ands r4, r0
    str r4, [sp, #0x10]
    mov r0, r8
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    mov r8, r5
    ldr r1, lbl_08028b14 @ =0xffc00000
    adds r0, r0, r1
    lsrs r0, r0, #0x10
    str r0, [sp, #8]
    movs r2, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCrouchingOrMorphed
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    movs r4, #8
    movs r3, #8
    str r3, [sp, #0x14]
    adds r0, r7, #0
    adds r0, #0x24
    ldrb r0, [r0]
    subs r0, #0x12
    ldr r2, [sp, #0x24]
    cmp r0, #0x4d
    bls lbl_08028b00
    b lbl_08028d78
lbl_08028b00:
    lsls r0, r0, #2
    ldr r1, lbl_08028b18 @ =lbl_08028b1c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08028b0c: .4byte 0x030007f3
lbl_08028b10: .4byte 0x0000ffc0
lbl_08028b14: .4byte 0xffc00000
lbl_08028b18: .4byte lbl_08028b1c
lbl_08028b1c: @ jump table
    .4byte lbl_08028d3c @ case 0
    .4byte lbl_08028d3c @ case 1
    .4byte lbl_08028d78 @ case 2
    .4byte lbl_08028d3c @ case 3
    .4byte lbl_08028d78 @ case 4
    .4byte lbl_08028d78 @ case 5
    .4byte lbl_08028d3c @ case 6
    .4byte lbl_08028d3c @ case 7
    .4byte lbl_08028d78 @ case 8
    .4byte lbl_08028d78 @ case 9
    .4byte lbl_08028d78 @ case 10
    .4byte lbl_08028d78 @ case 11
    .4byte lbl_08028d78 @ case 12
    .4byte lbl_08028d78 @ case 13
    .4byte lbl_08028d78 @ case 14
    .4byte lbl_08028d78 @ case 15
    .4byte lbl_08028d78 @ case 16
    .4byte lbl_08028d78 @ case 17
    .4byte lbl_08028d78 @ case 18
    .4byte lbl_08028d78 @ case 19
    .4byte lbl_08028d78 @ case 20
    .4byte lbl_08028d78 @ case 21
    .4byte lbl_08028d78 @ case 22
    .4byte lbl_08028d78 @ case 23
    .4byte lbl_08028d78 @ case 24
    .4byte lbl_08028d78 @ case 25
    .4byte lbl_08028d78 @ case 26
    .4byte lbl_08028d78 @ case 27
    .4byte lbl_08028d78 @ case 28
    .4byte lbl_08028d78 @ case 29
    .4byte lbl_08028d78 @ case 30
    .4byte lbl_08028d78 @ case 31
    .4byte lbl_08028d78 @ case 32
    .4byte lbl_08028d78 @ case 33
    .4byte lbl_08028d78 @ case 34
    .4byte lbl_08028d78 @ case 35
    .4byte lbl_08028d78 @ case 36
    .4byte lbl_08028d78 @ case 37
    .4byte lbl_08028d3c @ case 38
    .4byte lbl_08028d3c @ case 39
    .4byte lbl_08028d3c @ case 40
    .4byte lbl_08028d3c @ case 41
    .4byte lbl_08028d78 @ case 42
    .4byte lbl_08028d78 @ case 43
    .4byte lbl_08028d78 @ case 44
    .4byte lbl_08028d78 @ case 45
    .4byte lbl_08028d78 @ case 46
    .4byte lbl_08028d78 @ case 47
    .4byte lbl_080293ec @ case 48
    .4byte lbl_080293ec @ case 49
    .4byte lbl_08028d78 @ case 50
    .4byte lbl_08028d78 @ case 51
    .4byte lbl_08028d78 @ case 52
    .4byte lbl_08028d78 @ case 53
    .4byte lbl_08028d3c @ case 54
    .4byte lbl_08028d3c @ case 55
    .4byte lbl_08028d3c @ case 56
    .4byte lbl_08028d3c @ case 57
    .4byte lbl_08028d78 @ case 58
    .4byte lbl_080293ec @ case 59
    .4byte lbl_08028d78 @ case 60
    .4byte lbl_08028d78 @ case 61
    .4byte lbl_08028d78 @ case 62
    .4byte lbl_08028c54 @ case 63
    .4byte lbl_08028c54 @ case 64
    .4byte lbl_08028c54 @ case 65
    .4byte lbl_08028d78 @ case 66
    .4byte lbl_08028c54 @ case 67
    .4byte lbl_08028d78 @ case 68
    .4byte lbl_08028d78 @ case 69
    .4byte lbl_08028d78 @ case 70
    .4byte lbl_08028d78 @ case 71
    .4byte lbl_08028d78 @ case 72
    .4byte lbl_08028d78 @ case 73
    .4byte lbl_08028d78 @ case 74
    .4byte lbl_08028d78 @ case 75
    .4byte lbl_08028d3c @ case 76
    .4byte lbl_08028d3c @ case 77
lbl_08028c54:
    ldr r4, [sp, #0xc]
    movs r5, #0x40
    subs r0, r4, r5
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r0, lbl_08028c74 @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #1
    bne lbl_08028cd4
    ldr r0, [sp, #0x10]
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028c92
    .align 2, 0
lbl_08028c74: .4byte 0x030007f3
lbl_08028c78:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028c84
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_08028cb8
lbl_08028c84:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028c92:
    ldr r3, [sp, #0x14]
    cmp r7, r3
    bhs lbl_08028cbe
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028ccc @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028cbe
    cmp r5, sl
    bne lbl_08028c84
    cmp r6, r8
    bne lbl_08028c78
lbl_08028cb8:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028cbe:
    cmp r2, #0
    bne lbl_08028cc4
    b lbl_080293ec
lbl_08028cc4:
    ldr r0, lbl_08028cd0 @ =0x030007f3
    movs r1, #0
    b lbl_080292f0
    .align 2, 0
lbl_08028ccc: .4byte 0x030007f1
lbl_08028cd0: .4byte 0x030007f3
lbl_08028cd4:
    ldr r4, [sp, #0x10]
    movs r5, #0x40
    subs r0, r4, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028cfc
lbl_08028ce2:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028cee
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_08028d22
lbl_08028cee:
    movs r3, #0x40
    subs r0, r5, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028cfc:
    ldr r4, [sp, #0x14]
    cmp r7, r4
    bhs lbl_08028d28
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028d34 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028d28
    cmp r5, sl
    bne lbl_08028cee
    cmp r6, r8
    bne lbl_08028ce2
lbl_08028d22:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028d28:
    cmp r2, #0
    bne lbl_08028d2e
    b lbl_080293ec
lbl_08028d2e:
    ldr r1, lbl_08028d38 @ =0x030007f3
    movs r0, #0
    b lbl_08029104
    .align 2, 0
lbl_08028d34: .4byte 0x030007f1
lbl_08028d38: .4byte 0x030007f3
lbl_08028d3c:
    ldr r0, lbl_08028d54 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08028d5c
    ldr r1, lbl_08028d58 @ =0x030007f3
    ldrb r0, [r1, #4]
    cmp r0, #1
    bne lbl_08028d78
    b lbl_080293ee
    .align 2, 0
lbl_08028d54: .4byte 0x03000738
lbl_08028d58: .4byte 0x030007f3
lbl_08028d5c:
    ldr r1, lbl_08028d68 @ =0x030007f3
    ldrb r0, [r1, #4]
    cmp r0, #0
    bne lbl_08028d78
    b lbl_080293f0
    .align 2, 0
lbl_08028d68: .4byte 0x030007f3
lbl_08028d6c:
    adds r4, r7, #0
    b lbl_08028df2
lbl_08028d70:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_08028eb4
lbl_08028d78:
    cmp r6, #0xbf
    bls lbl_08028d7e
    b lbl_08028ffc
lbl_08028d7e:
    movs r5, #0x40
    lsls r1, r5, #1
    adds r0, r1, #0
    adds r0, #0x40
    ldr r3, [sp, #0xc]
    subs r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r0, lbl_08028da8 @ =0x030007f3
    ldrb r0, [r0, #4]
    str r1, [sp, #0x18]
    cmp r0, #1
    beq lbl_08028d9a
    b lbl_08028ed4
lbl_08028d9a:
    ldr r0, [sp, #0x10]
    adds r0, #0x40
    lsls r1, r0, #0x10
    lsrs r5, r1, #0x10
    movs r7, #0
    str r0, [sp, #0x1c]
    b lbl_08028dc6
    .align 2, 0
lbl_08028da8: .4byte 0x030007f3
lbl_08028dac:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028db8
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_08028dec
lbl_08028db8:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028dc6:
    ldr r3, [sp, #0x14]
    cmp r7, r3
    bhs lbl_08028df2
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028e0c @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028d6c
    cmp r5, sl
    bne lbl_08028db8
    cmp r6, r8
    bne lbl_08028dac
lbl_08028dec:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028df2:
    cmp r2, #0
    bne lbl_08028eba
    cmp r4, #7
    bhi lbl_08028e02
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x14]
lbl_08028e02:
    ldr r4, [sp, #0x1c]
    lsls r0, r4, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028e2a
    .align 2, 0
lbl_08028e0c: .4byte 0x030007f1
lbl_08028e10:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028e1c
    ldr r1, [sp, #8]
    cmp r4, r1
    beq lbl_08028e54
lbl_08028e1c:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028e2a:
    ldr r3, [sp, #0x14]
    cmp r7, r3
    bhs lbl_08028e5a
    adds r4, r6, #0
    adds r4, #0x40
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028e68 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028e5a
    cmp r5, sl
    bne lbl_08028e1c
    cmp r4, r8
    bne lbl_08028e10
lbl_08028e54:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028e5a:
    cmp r2, #0
    bne lbl_08028eba
    ldr r4, [sp, #0x1c]
    lsls r0, r4, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028e92
    .align 2, 0
lbl_08028e68: .4byte 0x030007f1
lbl_08028e6c:
    cmp r5, sl
    bne lbl_08028e84
    cmp r4, r8
    bne lbl_08028e76
    b lbl_08028d70
lbl_08028e76:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028e84
    ldr r1, [sp, #8]
    cmp r4, r1
    bne lbl_08028e84
    b lbl_08028d70
lbl_08028e84:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028e92:
    ldr r3, [sp, #0x14]
    cmp r7, r3
    bhs lbl_08028eb4
    ldr r0, [sp, #0x18]
    adds r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028ec0 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08028e6c
lbl_08028eb4:
    cmp r2, #0
    bne lbl_08028eba
    b lbl_08028ffc
lbl_08028eba:
    ldr r0, lbl_08028ec4 @ =0x030007f3
    movs r1, #0
    b lbl_080292f0
    .align 2, 0
lbl_08028ec0: .4byte 0x030007f1
lbl_08028ec4: .4byte 0x030007f3
lbl_08028ec8:
    adds r4, r7, #0
    b lbl_08028f2a
lbl_08028ecc:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_08028fe8
lbl_08028ed4:
    ldr r1, [sp, #0x10]
    movs r3, #0x40
    subs r0, r1, r3
    lsls r1, r0, #0x10
    lsrs r5, r1, #0x10
    movs r7, #0
    str r0, [sp, #0x20]
    b lbl_08028efe
lbl_08028ee4:
    mov r0, sb
    cmp r0, #0
    bne lbl_08028ef0
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_08028f24
lbl_08028ef0:
    movs r3, #0x40
    subs r0, r5, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028efe:
    ldr r0, [sp, #0x14]
    cmp r7, r0
    bhs lbl_08028f2a
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028f44 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028ec8
    cmp r5, sl
    bne lbl_08028ef0
    cmp r6, r8
    bne lbl_08028ee4
lbl_08028f24:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028f2a:
    cmp r2, #0
    bne lbl_08028fec
    cmp r4, #7
    bhi lbl_08028f3a
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x14]
lbl_08028f3a:
    ldr r1, [sp, #0x20]
    lsls r0, r1, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028f62
    .align 2, 0
lbl_08028f44: .4byte 0x030007f1
lbl_08028f48:
    mov r3, sb
    cmp r3, #0
    bne lbl_08028f54
    ldr r0, [sp, #8]
    cmp r4, r0
    beq lbl_08028f8c
lbl_08028f54:
    movs r1, #0x40
    subs r0, r5, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028f62:
    ldr r3, [sp, #0x14]
    cmp r7, r3
    bhs lbl_08028f92
    adds r4, r6, #0
    adds r4, #0x40
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028fa0 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_08028f92
    cmp r5, sl
    bne lbl_08028f54
    cmp r4, r8
    bne lbl_08028f48
lbl_08028f8c:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08028f92:
    cmp r2, #0
    bne lbl_08028fec
    ldr r4, [sp, #0x20]
    lsls r0, r4, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
    b lbl_08028fc6
    .align 2, 0
lbl_08028fa0: .4byte 0x030007f1
lbl_08028fa4:
    cmp r5, sl
    bne lbl_08028fb8
    cmp r4, r8
    beq lbl_08028ecc
    mov r0, sb
    cmp r0, #0
    bne lbl_08028fb8
    ldr r1, [sp, #8]
    cmp r4, r1
    beq lbl_08028ecc
lbl_08028fb8:
    movs r3, #0x40
    subs r0, r5, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08028fc6:
    ldr r4, [sp, #0x14]
    cmp r7, r4
    bhs lbl_08028fe8
    ldr r0, [sp, #0x18]
    adds r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08028ff4 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08028fa4
lbl_08028fe8:
    cmp r2, #0
    beq lbl_08028ffc
lbl_08028fec:
    ldr r1, lbl_08028ff8 @ =0x030007f3
    movs r0, #0
    b lbl_08029104
    .align 2, 0
lbl_08028ff4: .4byte 0x030007f1
lbl_08028ff8: .4byte 0x030007f3
lbl_08028ffc:
    ldr r1, lbl_08029088 @ =0x030007f3
    ldrb r0, [r1, #3]
    cmp r0, #0
    beq lbl_08029006
    b lbl_080291fc
lbl_08029006:
    movs r3, #0x40
    lsls r4, r3, #1
    adds r0, r4, #0
    adds r0, #0x40
    ldr r5, [sp, #0xc]
    subs r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrb r0, [r1, #4]
    cmp r0, #1
    bne lbl_08029110
    ldr r0, [sp]
    subs r0, #0xa0
    ldr r1, [sp, #0x10]
    adds r1, #0x40
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802908c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_0802903a
    b lbl_080293ec
lbl_0802903a:
    ldr r1, [sp, #0x10]
    adds r0, r1, r4
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
lbl_08029044:
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802908c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029090
    mov r4, sb
    cmp r4, #0
    beq lbl_080290fa
    cmp r5, sl
    bne lbl_080290fa
    movs r1, #0x40
    subs r0, r6, r1
    cmp r0, r8
    bne lbl_080290fa
    mov r0, r8
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802908c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_080290fa
    b lbl_080290dc
    .align 2, 0
lbl_08029088: .4byte 0x030007f3
lbl_0802908c: .4byte 0x030007f1
lbl_08029090:
    movs r0, #0x40
    subs r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_080290bc @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_080290c0
    mov r4, sb
    cmp r4, #0
    beq lbl_080290fa
    cmp r5, sl
    bne lbl_080290fa
    cmp r6, r8
    bne lbl_080290fa
    b lbl_080290dc
    .align 2, 0
lbl_080290bc: .4byte 0x030007f1
lbl_080290c0:
    cmp r5, sl
    bne lbl_080290e4
    cmp r6, r8
    beq lbl_080290dc
    cmp r4, r8
    beq lbl_080290dc
    mov r0, sb
    cmp r0, #0
    bne lbl_080290e4
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_080290dc
    cmp r4, r1
    bne lbl_080290e4
lbl_080290dc:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_080290fa
lbl_080290e4:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r0, r4, #0x10
    lsrs r6, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #4
    bls lbl_08029044
lbl_080290fa:
    cmp r2, #0
    bne lbl_08029100
    b lbl_080293ec
lbl_08029100:
    ldr r1, lbl_0802910c @ =0x030007f3
    movs r0, #1
lbl_08029104:
    strb r0, [r1]
    strb r0, [r1, #1]
    b lbl_080293f2
    .align 2, 0
lbl_0802910c: .4byte 0x030007f3
lbl_08029110:
    ldr r0, [sp]
    subs r0, #0xa0
    ldr r3, [sp, #0x10]
    movs r5, #0x40
    subs r1, r3, r5
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802917c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029130
    b lbl_080293ec
lbl_08029130:
    ldr r1, [sp, #0x10]
    subs r0, r1, r4
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
lbl_0802913a:
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802917c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029180
    mov r4, sb
    cmp r4, #0
    beq lbl_080291ea
    cmp r5, sl
    bne lbl_080291ea
    movs r1, #0x40
    subs r0, r6, r1
    cmp r0, r8
    bne lbl_080291ea
    mov r0, r8
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_0802917c @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_080291ea
    b lbl_080291cc
    .align 2, 0
lbl_0802917c: .4byte 0x030007f1
lbl_08029180:
    movs r0, #0x40
    subs r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_080291ac @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_080291b0
    mov r4, sb
    cmp r4, #0
    beq lbl_080291ea
    cmp r5, sl
    bne lbl_080291ea
    cmp r6, r8
    bne lbl_080291ea
    b lbl_080291cc
    .align 2, 0
lbl_080291ac: .4byte 0x030007f1
lbl_080291b0:
    cmp r5, sl
    bne lbl_080291d4
    cmp r6, r8
    beq lbl_080291cc
    cmp r4, r8
    beq lbl_080291cc
    mov r0, sb
    cmp r0, #0
    bne lbl_080291d4
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_080291cc
    cmp r4, r1
    bne lbl_080291d4
lbl_080291cc:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_080291ea
lbl_080291d4:
    movs r3, #0x40
    subs r0, r5, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r0, r4, #0x10
    lsrs r6, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #4
    bls lbl_0802913a
lbl_080291ea:
    cmp r2, #0
    bne lbl_080291f0
    b lbl_080293ec
lbl_080291f0:
    ldr r0, lbl_080291f8 @ =0x030007f3
    movs r2, #0
    movs r1, #1
    b lbl_080293e0
    .align 2, 0
lbl_080291f8: .4byte 0x030007f3
lbl_080291fc:
    ldr r4, [sp, #0xc]
    movs r5, #0x40
    subs r0, r4, r5
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrb r0, [r1, #4]
    cmp r0, #1
    bne lbl_080292fc
    ldr r1, [sp, #4]
    adds r1, #0x3c
    ldr r0, [sp]
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_08029274 @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029228
    b lbl_080293ec
lbl_08029228:
    ldr r0, [sp, #0x10]
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
lbl_08029232:
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08029274 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029278
    mov r1, sb
    cmp r1, #0
    beq lbl_080292e6
    cmp r5, sl
    bne lbl_080292e6
    movs r3, #0x40
    subs r0, r6, r3
    cmp r0, r8
    bne lbl_080292e6
    mov r0, r8
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r4, lbl_08029274 @ =0x030007f1
    ldrb r1, [r4]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_080292e6
    b lbl_080292c4
    .align 2, 0
lbl_08029274: .4byte 0x030007f1
lbl_08029278:
    movs r0, #0x40
    subs r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_080292a4 @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_080292a8
    mov r4, sb
    cmp r4, #0
    beq lbl_080292e6
    cmp r5, sl
    bne lbl_080292e6
    cmp r6, r8
    bne lbl_080292e6
    b lbl_080292c4
    .align 2, 0
lbl_080292a4: .4byte 0x030007f1
lbl_080292a8:
    cmp r5, sl
    bne lbl_080292cc
    cmp r6, r8
    beq lbl_080292c4
    cmp r4, r8
    beq lbl_080292c4
    mov r0, sb
    cmp r0, #0
    bne lbl_080292cc
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_080292c4
    cmp r4, r1
    bne lbl_080292cc
lbl_080292c4:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_080292e6
lbl_080292cc:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r6, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #4
    bls lbl_08029232
lbl_080292e6:
    cmp r2, #0
    bne lbl_080292ec
    b lbl_080293ec
lbl_080292ec:
    ldr r0, lbl_080292f8 @ =0x030007f3
    movs r1, #2
lbl_080292f0:
    strb r1, [r0]
    movs r1, #1
    strb r1, [r0, #1]
    b lbl_080293f2
    .align 2, 0
lbl_080292f8: .4byte 0x030007f3
lbl_080292fc:
    ldr r1, [sp, #4]
    subs r1, #0x3c
    ldr r0, [sp]
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_08029364 @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_080293ec
    ldr r4, [sp, #0x10]
    movs r5, #0x40
    subs r0, r4, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r7, #0
lbl_08029322:
    adds r0, r6, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08029364 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029368
    mov r1, sb
    cmp r1, #0
    beq lbl_080293d6
    cmp r5, sl
    bne lbl_080293d6
    movs r3, #0x40
    subs r0, r6, r3
    cmp r0, r8
    bne lbl_080293d6
    mov r0, r8
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r4, lbl_08029364 @ =0x030007f1
    ldrb r1, [r4]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    bne lbl_080293d6
    b lbl_080293b4
    .align 2, 0
lbl_08029364: .4byte 0x030007f1
lbl_08029368:
    movs r0, #0x40
    subs r4, r6, r0
    adds r0, r4, #0
    adds r1, r5, #0
    str r2, [sp, #0x24]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r3, lbl_08029394 @ =0x030007f1
    ldrb r1, [r3]
    movs r0, #0xf0
    ands r0, r1
    ldr r2, [sp, #0x24]
    cmp r0, #0
    beq lbl_08029398
    mov r4, sb
    cmp r4, #0
    beq lbl_080293d6
    cmp r5, sl
    bne lbl_080293d6
    cmp r6, r8
    bne lbl_080293d6
    b lbl_080293b4
    .align 2, 0
lbl_08029394: .4byte 0x030007f1
lbl_08029398:
    cmp r5, sl
    bne lbl_080293bc
    cmp r6, r8
    beq lbl_080293b4
    cmp r4, r8
    beq lbl_080293b4
    mov r0, sb
    cmp r0, #0
    bne lbl_080293bc
    ldr r1, [sp, #8]
    cmp r6, r1
    beq lbl_080293b4
    cmp r4, r1
    bne lbl_080293bc
lbl_080293b4:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    b lbl_080293d6
lbl_080293bc:
    movs r3, #0x40
    subs r0, r5, r3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r0, r6, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #4
    bls lbl_08029322
lbl_080293d6:
    cmp r2, #0
    beq lbl_080293ec
    ldr r0, lbl_080293e8 @ =0x030007f3
    movs r2, #0
    movs r1, #2
lbl_080293e0:
    strb r1, [r0]
    strb r2, [r0, #1]
    b lbl_080293f2
    .align 2, 0
lbl_080293e8: .4byte 0x030007f3
lbl_080293ec:
    ldr r1, lbl_08029404 @ =0x030007f3
lbl_080293ee:
    movs r0, #0
lbl_080293f0:
    strb r0, [r1, #2]
lbl_080293f2:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08029404: .4byte 0x030007f3

    thumb_func_start SpacePirateCheckCollidingWithLaser
SpacePirateCheckCollidingWithLaser: @ 0x08029408
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r3, lbl_080294b4 @ =0x03000738
    ldrh r1, [r3]
    movs r0, #6
    ands r0, r1
    cmp r0, #2
    bne lbl_080294ca
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    ldrh r0, [r3, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    ldrh r0, [r3, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    ldrh r0, [r3, #0xe]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrh r0, [r3, #0x10]
    adds r2, r2, r0
    lsls r2, r2, #0x10
    lsrs r7, r2, #0x10
    movs r6, #4
    ldr r4, lbl_080294b8 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r4, r1
    cmp r4, r0
    bhs lbl_080294ca
    adds r5, r4, #0
    adds r5, #0x24
lbl_0802945c:
    ldrh r1, [r4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080294c0
    ldrb r0, [r5, #1]
    cmp r0, #0x13
    bne lbl_080294c0
    ldrb r0, [r5, #0xa]
    cmp r0, #0
    bne lbl_080294c0
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r3, r0, r6
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    adds r0, r0, r6
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r2, r1, r6
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r1, r1, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r3, [sp]
    str r0, [sp, #4]
    str r2, [sp, #8]
    str r1, [sp, #0xc]
    mov r0, sl
    mov r1, sb
    mov r2, r8
    adds r3, r7, #0
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_080294c0
    movs r0, #0x42
    strb r0, [r5]
    movs r0, #0x6b
    ldr r1, lbl_080294bc @ =0x0300075c
    strb r0, [r1]
    b lbl_080294ca
    .align 2, 0
lbl_080294b4: .4byte 0x03000738
lbl_080294b8: .4byte 0x030001ac
lbl_080294bc: .4byte 0x0300075c
lbl_080294c0:
    adds r5, #0x38
    adds r4, #0x38
    ldr r0, lbl_080294dc @ =0x030006ec
    cmp r4, r0
    blo lbl_0802945c
lbl_080294ca:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080294dc: .4byte 0x030006ec

    thumb_func_start SpacePirateFireLaserGround
SpacePirateFireLaserGround: @ 0x080294e0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    ldr r2, lbl_08029550 @ =0x03000738
    ldrb r7, [r2, #0x1f]
    str r7, [sp, #0xc]
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    mov r8, r0
    str r0, [sp, #0x10]
    ldrh r5, [r2, #2]
    mov sb, r5
    ldrh r6, [r2, #4]
    mov sl, r6
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_080295b4
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08029554
    adds r0, r5, #0
    subs r0, #0x34
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x44
    str r0, [sp, #4]
    movs r4, #0x40
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r5, #0
    subs r0, #0x78
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x78
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    b lbl_0802961c
    .align 2, 0
lbl_08029550: .4byte 0x03000738
lbl_08029554:
    cmp r0, #1
    bne lbl_08029580
    adds r0, r5, #0
    subs r0, #0x98
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x44
    str r0, [sp, #4]
    movs r4, #0x40
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #1
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r5, #0
    subs r0, #0x5e
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x58
    b lbl_08029614
lbl_08029580:
    cmp r0, #2
    bne lbl_0802965e
    adds r0, r5, #0
    subs r0, #0x1c
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x44
    str r0, [sp, #4]
    movs r4, #0x40
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #2
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r5, #0
    subs r0, #0x60
    str r0, [sp]
    adds r0, r6, #0
    adds r0, #0x58
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #2
    b lbl_0802961c
lbl_080295b4:
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080295ec
    adds r0, r5, #0
    subs r0, #0x34
    str r0, [sp]
    adds r0, r6, #0
    subs r0, #0x44
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r5, #0
    subs r0, #0x78
    str r0, [sp]
    adds r0, r6, #0
    subs r0, #0x78
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    b lbl_0802961c
lbl_080295ec:
    cmp r0, #1
    bne lbl_08029626
    adds r0, r5, #0
    subs r0, #0x98
    str r0, [sp]
    adds r0, r6, #0
    subs r0, #0x44
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #1
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r5, #0
    subs r0, #0x5e
    str r0, [sp]
    adds r0, r6, #0
    subs r0, #0x58
lbl_08029614:
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #1
lbl_0802961c:
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    b lbl_0802965e
lbl_08029626:
    cmp r0, #2
    bne lbl_0802965e
    mov r0, sb
    subs r0, #0x1c
    str r0, [sp]
    mov r0, sl
    subs r0, #0x44
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #2
    ldr r2, [sp, #0xc]
    ldr r3, [sp, #0x10]
    bl SpriteSpawnSecondary
    mov r0, sb
    subs r0, #0x60
    str r0, [sp]
    mov r0, sl
    subs r0, #0x58
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #2
    ldr r2, [sp, #0xc]
    ldr r3, [sp, #0x10]
    bl SpriteSpawnSecondary
lbl_0802965e:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirateFireLaserWall
SpacePirateFireLaserWall: @ 0x08029670
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r0, lbl_080296c8 @ =0x03000738
    ldrb r7, [r0, #0x1f]
    adds r1, r0, #0
    adds r1, #0x23
    ldrb r1, [r1]
    mov r8, r1
    ldrh r6, [r0, #2]
    ldrh r5, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080296cc
    adds r0, r6, #0
    subs r0, #0x94
    str r0, [sp]
    subs r5, #0x44
    str r5, [sp, #4]
    movs r4, #0
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r6, #0
    subs r0, #0x4e
    str r0, [sp]
    str r5, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    b lbl_080296fc
    .align 2, 0
lbl_080296c8: .4byte 0x03000738
lbl_080296cc:
    adds r0, r6, #0
    subs r0, #0x94
    str r0, [sp]
    adds r5, #0x44
    str r5, [sp, #4]
    movs r4, #0x40
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
    adds r0, r6, #0
    subs r0, #0x4e
    str r0, [sp]
    str r5, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x16
    movs r1, #0
    adds r2, r7, #0
    mov r3, r8
    bl SpriteSpawnSecondary
lbl_080296fc:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08029708
sub_08029708: @ 0x08029708
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    ldr r1, lbl_0802984c @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_08029746
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    bne lbl_08029746
    movs r0, #0xc0
    lsls r0, r0, #1
    movs r1, #0xa0
    lsls r1, r1, #2
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    bne lbl_0802973e
    b lbl_0802988e
lbl_0802973e:
    ldrh r0, [r4]
    movs r1, #0x20
    orrs r0, r1
    strh r0, [r4]
lbl_08029746:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    str r0, [sp, #0x14]
    ldrh r1, [r4, #2]
    ldrh r0, [r4, #4]
    mov sb, r0
    adds r0, r1, #0
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    str r1, [sp, #0x20]
    mov r0, sb
    subs r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x24]
    mov r0, sb
    adds r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x28]
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x18]
    movs r1, #0
    str r1, [sp, #0x10]
    ldr r6, lbl_08029850 @ =0x030001ac
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r0, r6, r3
    cmp r6, r0
    blo lbl_080297a2
    b lbl_0802992a
lbl_080297a2:
    mov sl, r2
    adds r7, r6, #0
    adds r7, #0x24
lbl_080297a8:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_080297b4
    b lbl_08029914
lbl_080297b4:
    ldrb r0, [r7, #1]
    cmp r0, #0x14
    beq lbl_080297bc
    b lbl_08029914
lbl_080297bc:
    ldrb r0, [r7]
    cmp r0, #9
    bne lbl_080297ca
    ldr r0, [sp, #0x14]
    cmp r0, #0x23
    bne lbl_080297ca
    b lbl_08029914
lbl_080297ca:
    ldrh r1, [r6, #2]
    ldrh r2, [r6, #4]
    adds r0, r1, #0
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r3, #0
    orrs r3, r1
    adds r0, r2, #0
    subs r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r0, r2, #0
    adds r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp sb, r2
    bne lbl_08029854
    ldr r0, lbl_0802984c @ =0x03000738
    adds r0, #0x23
    ldrb r0, [r0]
    ldr r2, [sp, #0x10]
    cmp r0, r2
    blo lbl_080297fc
    b lbl_08029914
lbl_080297fc:
    str r4, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r5, [sp, #0xc]
    ldr r0, [sp, #0x1c]
    ldr r1, [sp, #0x20]
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x28]
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    bne lbl_08029816
    b lbl_08029914
lbl_08029816:
    ldrh r1, [r6]
    movs r2, #0x20
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_08029882
    orrs r1, r2
    movs r2, #0
    strh r1, [r6]
    adds r0, r1, #0
    mov r3, sl
    ands r0, r3
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r8
    beq lbl_0802988e
    ldr r0, [sp, #0x18]
    cmp r0, #0
    beq lbl_08029910
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r6]
    movs r0, #0x44
    b lbl_08029912
    .align 2, 0
lbl_0802984c: .4byte 0x03000738
lbl_08029850: .4byte 0x030001ac
lbl_08029854:
    mov r0, r8
    cmp r0, #0
    beq lbl_080298ba
    cmp sb, r2
    bhs lbl_08029914
    str r4, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r5, [sp, #0xc]
    ldr r0, [sp, #0x1c]
    ldr r1, [sp, #0x20]
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x28]
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_08029914
    ldrh r1, [r6]
    movs r2, #0x20
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08029892
lbl_08029882:
    mov r0, sl
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r8
    bne lbl_08029914
lbl_0802988e:
    movs r0, #1
    b lbl_0802992c
lbl_08029892:
    orrs r1, r2
    movs r2, #0
    strh r1, [r6]
    adds r0, r1, #0
    mov r3, sl
    ands r0, r3
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r8
    beq lbl_0802988e
    ldr r0, [sp, #0x18]
    cmp r0, #0
    beq lbl_08029910
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r6]
    movs r0, #0x44
    b lbl_08029912
lbl_080298ba:
    cmp sb, r2
    bls lbl_08029914
    str r4, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r5, [sp, #0xc]
    ldr r0, [sp, #0x1c]
    ldr r1, [sp, #0x20]
    ldr r2, [sp, #0x24]
    ldr r3, [sp, #0x28]
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_08029914
    ldrh r1, [r6]
    movs r2, #0x20
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_080298ec
    mov r0, sl
    ands r0, r1
    cmp r0, #0
    bne lbl_08029914
    b lbl_0802988e
lbl_080298ec:
    orrs r1, r2
    movs r2, #0
    strh r1, [r6]
    adds r0, r1, #0
    mov r3, sl
    ands r0, r3
    cmp r0, #0
    beq lbl_0802988e
    ldr r0, [sp, #0x18]
    cmp r0, #0
    beq lbl_08029910
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r6]
    movs r0, #0x44
    b lbl_08029912
lbl_08029910:
    movs r0, #0xa
lbl_08029912:
    strb r0, [r7]
lbl_08029914:
    ldr r0, [sp, #0x10]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x10]
    adds r7, #0x38
    adds r6, #0x38
    ldr r0, lbl_0802993c @ =0x030006ec
    cmp r6, r0
    bhs lbl_0802992a
    b lbl_080297a8
lbl_0802992a:
    movs r0, #0
lbl_0802992c:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0802993c: .4byte 0x030006ec

    thumb_func_start sub_08029940
sub_08029940: @ 0x08029940
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x10]
    movs r6, #0xf0
    rsbs r6, r6, #0
    ldr r0, lbl_080299a8 @ =0x03000738
    ldrh r5, [r0, #2]
    ldrh r1, [r0, #4]
    adds r0, r5, r6
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    mov sb, r5
    adds r0, r1, #0
    subs r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    adds r1, #0x2c
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    movs r4, #0
lbl_08029978:
    ldr r1, lbl_080299ac @ =0x030001ac
    lsls r2, r4, #3
    subs r0, r2, r4
    lsls r0, r0, #3
    adds r3, r0, r1
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080299fc
    adds r0, r3, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, #0x14
    bne lbl_080299fc
    movs r0, #0
    ldrh r3, [r3, #2]
    ldr r1, [sp, #0x10]
    cmp r1, #0
    bne lbl_080299b0
    cmp r5, r3
    bls lbl_080299b6
    b lbl_080299ba
    .align 2, 0
lbl_080299a8: .4byte 0x03000738
lbl_080299ac: .4byte 0x030001ac
lbl_080299b0:
    cmp r5, r3
    bhs lbl_080299b6
    movs r0, #1
lbl_080299b6:
    cmp r0, #0
    beq lbl_080299fc
lbl_080299ba:
    subs r0, r2, r4
    lsls r0, r0, #3
    ldr r1, lbl_080299f8 @ =0x030001ac
    adds r0, r0, r1
    ldrh r0, [r0, #4]
    adds r2, r3, r6
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    movs r1, #0
    orrs r3, r1
    adds r1, r0, #0
    subs r1, #0x2c
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, #0x2c
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r2, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    mov r0, sl
    mov r1, sb
    mov r2, r8
    adds r3, r7, #0
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_080299fc
    movs r0, #1
    b lbl_08029a08
    .align 2, 0
lbl_080299f8: .4byte 0x030001ac
lbl_080299fc:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0x17
    bls lbl_08029978
    movs r0, #0
lbl_08029a08:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start SpacePirateCheckSamusInShootingRange
SpacePirateCheckSamusInShootingRange: @ 0x08029a18
    push {r4, lr}
    ldr r0, lbl_08029a68 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r4, r0, #0
    cmp r1, #1
    bne lbl_08029ab6
    ldr r0, lbl_08029a6c @ =0x03000738
    ldrb r0, [r0, #0x1d]
    movs r1, #0x80
    lsls r1, r1, #2
    cmp r0, #0x55
    beq lbl_08029a3e
    subs r1, #0x80
    ldr r0, lbl_08029a70 @ =0x030013d4
    movs r2, #0x16
    ldrsh r0, [r0, r2]
    cmp r0, #0
    beq lbl_08029a3e
    movs r1, #0xc0
lbl_08029a3e:
    ldrb r0, [r4]
    movs r2, #0xc0
    lsls r2, r2, #1
    cmp r0, #0
    bne lbl_08029a4a
    movs r2, #0x80
lbl_08029a4a:
    adds r0, r2, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r3, r0, #0
    ldr r2, lbl_08029a6c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08029a74
    cmp r3, #8
    bne lbl_08029a8c
    b lbl_08029a78
    .align 2, 0
lbl_08029a68: .4byte 0x030007f3
lbl_08029a6c: .4byte 0x03000738
lbl_08029a70: .4byte 0x030013d4
lbl_08029a74:
    cmp r3, #4
    bne lbl_08029a8c
lbl_08029a78:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    ldrb r1, [r4]
    adds r0, r2, #0
    adds r0, #0x2d
    strb r1, [r0]
    movs r0, #1
    b lbl_08029b62
lbl_08029a8c:
    movs r1, #0xa0
    lsls r1, r1, #2
    adds r0, r1, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r3, r0, #0
    ldr r2, lbl_08029aac @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08029ab0
    cmp r3, #4
    bne lbl_08029b60
    b lbl_08029b50
    .align 2, 0
lbl_08029aac: .4byte 0x03000738
lbl_08029ab0:
    cmp r3, #8
    bne lbl_08029b60
    b lbl_08029b50
lbl_08029ab6:
    ldr r2, lbl_08029adc @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08029ae0
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029af4
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08029af4
    b lbl_08029b50
    .align 2, 0
lbl_08029adc: .4byte 0x03000738
lbl_08029ae0:
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029af4
    ldrb r0, [r4, #4]
    cmp r0, #1
    beq lbl_08029b50
lbl_08029af4:
    adds r1, r2, #0
    ldrb r0, [r1, #0x1d]
    cmp r0, #0x53
    beq lbl_08029b60
    ldrh r3, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_08029b30
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08029b60
    ldr r0, lbl_08029b2c @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08029b1e
    movs r0, #0x20
    ands r0, r3
    cmp r0, #0
    bne lbl_08029b60
lbl_08029b1e:
    adds r0, r1, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    cmp r0, #0x3c
    bne lbl_08029b60
    b lbl_08029b52
    .align 2, 0
lbl_08029b2c: .4byte 0x030001a8
lbl_08029b30:
    ldrb r0, [r4, #4]
    cmp r0, #1
    bne lbl_08029b60
    ldr r0, lbl_08029b5c @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08029b46
    movs r0, #0x20
    ands r0, r3
    cmp r0, #0
    bne lbl_08029b60
lbl_08029b46:
    adds r0, r2, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    cmp r0, #0x3c
    bne lbl_08029b60
lbl_08029b50:
    adds r1, r2, #0
lbl_08029b52:
    adds r1, #0x24
    movs r0, #0x44
    strb r0, [r1]
    movs r0, #1
    b lbl_08029b62
    .align 2, 0
lbl_08029b5c: .4byte 0x030001a8
lbl_08029b60:
    movs r0, #0
lbl_08029b62:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start sub_08029b68
sub_08029b68: @ 0x08029b68
    push {r4, r5, r6, lr}
    ldr r2, lbl_08029bb4 @ =0x03000738
    adds r4, r2, #0
    adds r4, #0x24
    ldrb r6, [r4]
    ldr r0, lbl_08029bb8 @ =0x030001a8
    ldrh r1, [r0]
    movs r0, #0xef
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_08029b88
    adds r1, r2, #0
    adds r1, #0x2b
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08029b88:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_08029c08
    ldr r0, lbl_08029bbc @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r5, r0, #0
    cmp r1, #1
    bne lbl_08029bd8
    ldrb r0, [r5, #1]
    cmp r0, #1
    bne lbl_08029bc0
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x22
    b lbl_08029bd6
    .align 2, 0
lbl_08029bb4: .4byte 0x03000738
lbl_08029bb8: .4byte 0x030001a8
lbl_08029bbc: .4byte 0x030007f3
lbl_08029bc0:
    ldr r0, lbl_08029c00 @ =0x0300080c
    ldrh r1, [r0, #2]
    ldr r0, lbl_08029c04 @ =0x000002ff
    cmp r1, r0
    bhi lbl_08029bd8
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x44
lbl_08029bd6:
    strb r0, [r4]
lbl_08029bd8:
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029c7c
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r1, r0
    strh r1, [r2]
    ldrb r0, [r5, #4]
    cmp r0, #0
    bne lbl_08029c74
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_08029c7a
    .align 2, 0
lbl_08029c00: .4byte 0x0300080c
lbl_08029c04: .4byte 0x000002ff
lbl_08029c08:
    ldr r0, lbl_08029c28 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r5, r0, #0
    cmp r1, #1
    bne lbl_08029c44
    ldrb r0, [r5, #1]
    cmp r0, #0
    bne lbl_08029c2c
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x22
    b lbl_08029c42
    .align 2, 0
lbl_08029c28: .4byte 0x030007f3
lbl_08029c2c:
    ldr r0, lbl_08029c6c @ =0x0300080c
    ldrh r1, [r0, #2]
    ldr r0, lbl_08029c70 @ =0x000002ff
    cmp r1, r0
    bhi lbl_08029c44
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
    movs r0, #0x44
lbl_08029c42:
    strb r0, [r4]
lbl_08029c44:
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029c7c
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r1, r0
    strh r1, [r2]
    ldrb r0, [r5, #4]
    cmp r0, #1
    bne lbl_08029c74
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_08029c7a
    .align 2, 0
lbl_08029c6c: .4byte 0x0300080c
lbl_08029c70: .4byte 0x000002ff
lbl_08029c74:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
lbl_08029c7a:
    strb r0, [r1]
lbl_08029c7c:
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r6, r0
    beq lbl_08029c8a
    movs r0, #1
    b lbl_08029c8c
lbl_08029c8a:
    movs r0, #0
lbl_08029c8c:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08029c94
sub_08029c94: @ 0x08029c94
    push {r4, r5, lr}
    ldr r2, lbl_08029d08 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r5, [r0]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08029cc0
    ldr r0, lbl_08029d0c @ =0x030001a8
    ldrh r1, [r0]
    movs r0, #0xef
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_08029cc0
    adds r1, r2, #0
    adds r1, #0x2b
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08029cc0:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_08029d14
    ldr r0, lbl_08029d10 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r4, r0, #0
    cmp r1, #1
    bne lbl_08029ce6
    ldrb r0, [r4, #1]
    cmp r0, #1
    bne lbl_08029ce6
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
lbl_08029ce6:
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029d56
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r1, r0
    strh r1, [r2]
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08029d56
    b lbl_08029d4e
    .align 2, 0
lbl_08029d08: .4byte 0x03000738
lbl_08029d0c: .4byte 0x030001a8
lbl_08029d10: .4byte 0x030007f3
lbl_08029d14:
    ldr r0, lbl_08029d64 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r4, r0, #0
    cmp r1, #1
    bne lbl_08029d2e
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_08029d2e
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2]
lbl_08029d2e:
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029d56
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r1, r0
    strh r1, [r2]
    ldrb r0, [r4, #4]
    cmp r0, #1
    bne lbl_08029d56
lbl_08029d4e:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x58
    strb r0, [r1]
lbl_08029d56:
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r5, r0
    beq lbl_08029d68
    movs r0, #1
    b lbl_08029d6a
    .align 2, 0
lbl_08029d64: .4byte 0x030007f3
lbl_08029d68:
    movs r0, #0
lbl_08029d6a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08029d70
sub_08029d70: @ 0x08029d70
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r2, lbl_08029dd8 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r5, [r0]
    mov r8, r5
    ldrh r7, [r2, #2]
    ldrh r4, [r2, #4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_08029da6
    ldr r0, lbl_08029ddc @ =0x030001a8
    ldrh r1, [r0]
    movs r0, #0xef
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_08029da6
    adds r1, r2, #0
    adds r1, #0x2b
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08029da6:
    ldr r0, lbl_08029de0 @ =0x030007f3
    ldrb r0, [r0, #2]
    cmp r0, #1
    beq lbl_08029dbc
    adds r0, r2, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08029e72
lbl_08029dbc:
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r1, r0
    strh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r1, r0
    cmp r1, #0
    beq lbl_08029de4
    adds r0, r4, #0
    adds r0, #0x30
    b lbl_08029de8
    .align 2, 0
lbl_08029dd8: .4byte 0x03000738
lbl_08029ddc: .4byte 0x030001a8
lbl_08029de0: .4byte 0x030007f3
lbl_08029de4:
    adds r0, r4, #0
    subs r0, #0x30
lbl_08029de8:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r7, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    ldr r6, lbl_08029e3c @ =0x030000dc
    ldrh r0, [r6]
    cmp r0, #9
    beq lbl_08029e9c
    adds r0, r7, #0
    subs r0, #0xe0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    ldrh r0, [r6]
    cmp r0, #9
    beq lbl_08029e9e
    ldr r0, lbl_08029e40 @ =0x030007f3
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08029e5a
    ldr r2, lbl_08029e44 @ =0x030013d4
    ldr r0, lbl_08029e48 @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r0, r7, #0
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_08029e4c
    subs r0, r0, r1
    b lbl_08029e4e
    .align 2, 0
lbl_08029e3c: .4byte 0x030000dc
lbl_08029e40: .4byte 0x030007f3
lbl_08029e44: .4byte 0x030013d4
lbl_08029e48: .4byte 0x03001588
lbl_08029e4c:
    subs r0, r1, r0
lbl_08029e4e:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x43
    bhi lbl_08029e9e
    movs r5, #0x38
    b lbl_08029e9e
lbl_08029e5a:
    cmp r0, #1
    bne lbl_08029e68
    mov r3, r8
    cmp r3, #0x49
    beq lbl_08029e9e
    movs r5, #0x48
    b lbl_08029e9e
lbl_08029e68:
    mov r0, r8
    cmp r0, #0x5f
    beq lbl_08029e9e
    movs r5, #0x5e
    b lbl_08029e9e
lbl_08029e72:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08029e84
    adds r0, r4, #0
    adds r0, #0x30
    b lbl_08029e88
lbl_08029e84:
    adds r0, r4, #0
    subs r0, #0x30
lbl_08029e88:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r7, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    ldr r0, lbl_08029ea8 @ =0x030000dc
    ldrh r0, [r0]
    cmp r0, #9
    bne lbl_08029e9e
lbl_08029e9c:
    movs r5, #0x12
lbl_08029e9e:
    cmp r8, r5
    bne lbl_08029eac
    movs r0, #0
    b lbl_08029ee2
    .align 2, 0
lbl_08029ea8: .4byte 0x030000dc
lbl_08029eac:
    mov r1, r8
    cmp r1, #0x19
    bne lbl_08029eb6
    adds r0, r5, #0
    b lbl_08029ee2
lbl_08029eb6:
    cmp r5, #0x12
    bne lbl_08029ed8
    ldr r2, lbl_08029ed4 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #0
    strb r5, [r0]
    adds r0, #9
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #1
    strb r0, [r1]
    b lbl_08029ee0
    .align 2, 0
lbl_08029ed4: .4byte 0x03000738
lbl_08029ed8:
    ldr r0, lbl_08029eec @ =0x03000738
    adds r0, #0x24
    movs r1, #0x18
    strb r1, [r0]
lbl_08029ee0:
    movs r0, #1
lbl_08029ee2:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08029eec: .4byte 0x03000738

    thumb_func_start sub_08029ef0
sub_08029ef0: @ 0x08029ef0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r6, #0
    movs r1, #0
    ldr r4, lbl_08029f84 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    str r0, [sp]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r1, [r0]
    ldrh r7, [r4, #2]
    ldrh r0, [r4, #4]
    mov sb, r0
    subs r0, r7, #4
    mov r1, sb
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    ldr r5, lbl_08029f88 @ =0x030007f0
    ldrb r1, [r5]
    movs r0, #0xf
    mov r8, r0
    ands r0, r1
    cmp r0, #1
    bhi lbl_08029f52
    adds r0, r7, #0
    mov r1, sb
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    ldrb r1, [r5]
    mov r0, r8
    ands r0, r1
    cmp r0, #1
    bhi lbl_08029f52
    adds r0, r7, #4
    mov r1, sb
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_08029f60
lbl_08029f52:
    strh r2, [r4, #2]
    lsls r0, r2, #0x10
    lsrs r7, r0, #0x10
    ldr r0, lbl_08029f88 @ =0x030007f0
    ldrb r3, [r0]
    cmp r3, #0
    bne lbl_08029fce
lbl_08029f60:
    ldr r4, lbl_08029f84 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08029f98
    mov r1, sb
    subs r1, #0x10
    adds r0, r7, #0
    bl SpriteUtilCheckVerticalCollisionAtPosition
    ldr r0, lbl_08029f88 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08029f8c
    adds r1, r4, #0
    b lbl_0802a0ba
    .align 2, 0
lbl_08029f84: .4byte 0x03000738
lbl_08029f88: .4byte 0x030007f0
lbl_08029f8c:
    cmp r0, #4
    beq lbl_08029fbe
    cmp r0, #2
    beq lbl_08029f96
    b lbl_0802a360
lbl_08029f96:
    b lbl_08029fbe
lbl_08029f98:
    mov r1, sb
    adds r1, #0x10
    adds r0, r7, #0
    bl SpriteUtilCheckVerticalCollisionAtPosition
    ldr r0, lbl_08029fb0 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08029fb4
    adds r1, r4, #0
    b lbl_0802a0ba
    .align 2, 0
lbl_08029fb0: .4byte 0x030007f0
lbl_08029fb4:
    cmp r0, #5
    beq lbl_08029fbe
    cmp r0, #3
    beq lbl_08029fbe
    b lbl_0802a360
lbl_08029fbe:
    adds r0, r7, #0
    adds r0, #0x40
    mov r1, sb
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    strh r2, [r4, #2]
    b lbl_0802a360
lbl_08029fce:
    ldr r2, lbl_0802a014 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    cmp r0, #0
    beq lbl_0802a074
    movs r0, #0xf0
    ands r0, r3
    cmp r0, #0
    bne lbl_08029fec
    b lbl_0802a1a4
lbl_08029fec:
    mov r4, sb
    adds r4, #0x28
    adds r0, r7, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    mov r8, r4
    cmp r0, #0
    bne lbl_0802a018
    ldr r1, [sp]
    cmp r1, #9
    bne lbl_0802a0a2
    ldr r2, lbl_0802a014 @ =0x03000738
    ldrh r0, [r2, #0x12]
    cmp r0, #0x14
    bls lbl_0802a0a2
    adds r1, r2, #0
    b lbl_0802a1c0
    .align 2, 0
lbl_0802a014: .4byte 0x03000738
lbl_0802a018:
    adds r4, r7, #0
    subs r4, #0x20
    mov r5, sb
    adds r5, #0x50
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x11
    beq lbl_0802a032
    b lbl_0802a154
lbl_0802a032:
    ldr r0, lbl_0802a048 @ =0x030000dc
    ldrh r0, [r0]
    cmp r0, #8
    bne lbl_0802a064
    ldr r1, lbl_0802a04c @ =0x03000738
    ldrb r0, [r1, #0x1d]
    cmp r0, #0x53
    bne lbl_0802a050
    movs r0, #0
    strh r0, [r1]
    b lbl_0802a0f8
    .align 2, 0
lbl_0802a048: .4byte 0x030000dc
lbl_0802a04c: .4byte 0x03000738
lbl_0802a050:
    ldr r0, lbl_0802a06c @ =0x030001a8
    ldrh r2, [r0]
    cmp r2, #0
    bne lbl_0802a064
    ldr r0, lbl_0802a070 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0802a128
lbl_0802a064:
    adds r0, r4, #0
    mov r1, r8
    b lbl_0802a13c
    .align 2, 0
lbl_0802a06c: .4byte 0x030001a8
lbl_0802a070: .4byte 0x03000738
lbl_0802a074:
    movs r0, #0xf0
    ands r0, r3
    cmp r0, #0
    bne lbl_0802a07e
    b lbl_0802a1a4
lbl_0802a07e:
    mov r4, sb
    subs r4, #0x28
    adds r0, r7, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    mov sl, r4
    cmp r0, #0
    bne lbl_0802a0cc
    ldr r2, [sp]
    cmp r2, #9
    bne lbl_0802a0a2
    ldr r1, lbl_0802a0c4 @ =0x03000738
    ldrh r0, [r1, #0x12]
    cmp r0, #0x14
    bls lbl_0802a0a2
    b lbl_0802a1c0
lbl_0802a0a2:
    ldr r1, lbl_0802a0c8 @ =0x030007f3
    ldrb r0, [r1, #2]
    cmp r0, #1
    bne lbl_0802a0b8
    ldrb r0, [r1]
    cmp r0, #1
    bhi lbl_0802a0b8
    ldr r1, lbl_0802a0c4 @ =0x03000738
    adds r1, #0x2d
    movs r0, #2
    strb r0, [r1]
lbl_0802a0b8:
    ldr r1, lbl_0802a0c4 @ =0x03000738
lbl_0802a0ba:
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0802a360
    .align 2, 0
lbl_0802a0c4: .4byte 0x03000738
lbl_0802a0c8: .4byte 0x030007f3
lbl_0802a0cc:
    adds r4, r7, #0
    subs r4, #0x20
    mov r5, sb
    subs r5, #0x50
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x11
    bne lbl_0802a154
    ldr r0, lbl_0802a108 @ =0x030000dc
    ldrh r0, [r0]
    cmp r0, #8
    bne lbl_0802a138
    ldr r2, lbl_0802a10c @ =0x03000738
    ldrb r0, [r2, #0x1d]
    cmp r0, #0x53
    bne lbl_0802a114
    mov r0, r8
    strh r0, [r2]
lbl_0802a0f8:
    ldr r0, lbl_0802a110 @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0802a102
    b lbl_0802a360
lbl_0802a102:
    bl DisableChozodiaAlarm
    b lbl_0802a360
    .align 2, 0
lbl_0802a108: .4byte 0x030000dc
lbl_0802a10c: .4byte 0x03000738
lbl_0802a110: .4byte 0x030001a8
lbl_0802a114:
    ldr r0, lbl_0802a130 @ =0x030001a8
    ldrh r2, [r0]
    cmp r2, #0
    bne lbl_0802a138
    ldr r0, lbl_0802a134 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a138
lbl_0802a128:
    ldr r1, lbl_0802a134 @ =0x03000738
    strh r2, [r1]
    b lbl_0802a360
    .align 2, 0
lbl_0802a130: .4byte 0x030001a8
lbl_0802a134: .4byte 0x03000738
lbl_0802a138:
    adds r0, r4, #0
    mov r1, sl
lbl_0802a13c:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_0802a150
    movs r0, #0xf0
    ands r1, r0
    cmp r1, #0
    beq lbl_0802a154
lbl_0802a150:
    movs r0, #1
    orrs r6, r0
lbl_0802a154:
    adds r0, r7, #0
    subs r0, #0x60
    adds r4, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x11
    bne lbl_0802a170
    movs r0, #2
    orrs r6, r0
    lsls r0, r6, #0x18
    lsrs r6, r0, #0x18
lbl_0802a170:
    adds r0, r7, #0
    subs r0, #0xa0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x11
    bne lbl_0802a18a
    movs r0, #4
    orrs r6, r0
    lsls r0, r6, #0x18
    lsrs r6, r0, #0x18
lbl_0802a18a:
    adds r0, r7, #0
    subs r0, #0xe0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x11
    bne lbl_0802a1a4
    movs r0, #8
    orrs r6, r0
    lsls r0, r6, #0x18
    lsrs r6, r0, #0x18
lbl_0802a1a4:
    ldr r2, [sp]
    cmp r2, #9
    bne lbl_0802a1cc
    cmp r6, #0
    bne lbl_0802a1b0
    b lbl_0802a360
lbl_0802a1b0:
    cmp r6, #8
    bne lbl_0802a1b6
    b lbl_0802a360
lbl_0802a1b6:
    ldr r0, lbl_0802a1c8 @ =0x03000738
    ldrh r1, [r0, #0x12]
    cmp r1, #0x14
    bls lbl_0802a1cc
    adds r1, r0, #0
lbl_0802a1c0:
    adds r1, #0x24
    movs r0, #0x16
    strb r0, [r1]
    b lbl_0802a360
    .align 2, 0
lbl_0802a1c8: .4byte 0x03000738
lbl_0802a1cc:
    cmp r6, #0xf
    bhi lbl_0802a2b8
    lsls r0, r6, #2
    ldr r1, lbl_0802a1dc @ =lbl_0802a1e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802a1dc: .4byte lbl_0802a1e0
lbl_0802a1e0: @ jump table
    .4byte lbl_0802a2d6 @ case 0
    .4byte lbl_0802a220 @ case 1
    .4byte lbl_0802a230 @ case 2
    .4byte lbl_0802a250 @ case 3
    .4byte lbl_0802a260 @ case 4
    .4byte lbl_0802a2a0 @ case 5
    .4byte lbl_0802a260 @ case 6
    .4byte lbl_0802a2a0 @ case 7
    .4byte lbl_0802a2d6 @ case 8
    .4byte lbl_0802a2b8 @ case 9
    .4byte lbl_0802a2b8 @ case 10
    .4byte lbl_0802a2b8 @ case 11
    .4byte lbl_0802a2b8 @ case 12
    .4byte lbl_0802a2b8 @ case 13
    .4byte lbl_0802a280 @ case 14
    .4byte lbl_0802a2a0 @ case 15
lbl_0802a220:
    ldr r1, lbl_0802a22c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2d
    movs r0, #1
    b lbl_0802a2a8
    .align 2, 0
lbl_0802a22c: .4byte 0x03000738
lbl_0802a230:
    ldr r0, lbl_0802a248 @ =0x030013d4
    ldrh r1, [r0, #0x14]
    adds r0, r7, #0
    subs r0, #0x60
    cmp r1, r0
    blt lbl_0802a250
    ldr r2, lbl_0802a24c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x4e
    b lbl_0802a2d4
    .align 2, 0
lbl_0802a248: .4byte 0x030013d4
lbl_0802a24c: .4byte 0x03000738
lbl_0802a250:
    ldr r1, lbl_0802a25c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2d
    movs r0, #2
    b lbl_0802a2a8
    .align 2, 0
lbl_0802a25c: .4byte 0x03000738
lbl_0802a260:
    ldr r0, lbl_0802a278 @ =0x030013d4
    ldrh r1, [r0, #0x14]
    adds r0, r7, #0
    subs r0, #0xa0
    cmp r1, r0
    blt lbl_0802a2a0
    ldr r2, lbl_0802a27c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x4e
    b lbl_0802a2d4
    .align 2, 0
lbl_0802a278: .4byte 0x030013d4
lbl_0802a27c: .4byte 0x03000738
lbl_0802a280:
    ldr r0, lbl_0802a298 @ =0x030013d4
    ldrh r1, [r0, #0x14]
    adds r0, r7, #0
    subs r0, #0xe0
    cmp r1, r0
    blt lbl_0802a2a0
    ldr r2, lbl_0802a29c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x4e
    b lbl_0802a2d4
    .align 2, 0
lbl_0802a298: .4byte 0x030013d4
lbl_0802a29c: .4byte 0x03000738
lbl_0802a2a0:
    ldr r1, lbl_0802a2b4 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2d
    movs r0, #3
lbl_0802a2a8:
    strb r0, [r2]
    subs r2, #9
    movs r0, #0x42
    strb r0, [r2]
    b lbl_0802a2d6
    .align 2, 0
lbl_0802a2b4: .4byte 0x03000738
lbl_0802a2b8:
    ldr r0, [sp]
    cmp r0, #9
    bne lbl_0802a2cc
    ldr r2, lbl_0802a2c8 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x16
    b lbl_0802a2d4
    .align 2, 0
lbl_0802a2c8: .4byte 0x03000738
lbl_0802a2cc:
    ldr r2, lbl_0802a314 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
lbl_0802a2d4:
    strb r0, [r1]
lbl_0802a2d6:
    ldr r0, lbl_0802a314 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x42
    bne lbl_0802a360
    ldr r0, lbl_0802a314 @ =0x03000738
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0802a360
    ldr r2, lbl_0802a314 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a31c
    adds r0, r7, #0
    subs r0, #0xe0
    mov r4, sb
    adds r4, #0x30
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802a340
    ldr r1, lbl_0802a318 @ =0xfffffee0
    adds r0, r7, r1
    b lbl_0802a334
    .align 2, 0
lbl_0802a314: .4byte 0x03000738
lbl_0802a318: .4byte 0xfffffee0
lbl_0802a31c:
    adds r0, r7, #0
    subs r0, #0xe0
    mov r4, sb
    subs r4, #0x30
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802a340
    ldr r2, lbl_0802a350 @ =0xfffffee0
    adds r0, r7, r2
lbl_0802a334:
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802a360
lbl_0802a340:
    ldr r0, [sp]
    cmp r0, #9
    bne lbl_0802a358
    ldr r0, lbl_0802a354 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x16
    b lbl_0802a35e
    .align 2, 0
lbl_0802a350: .4byte 0xfffffee0
lbl_0802a354: .4byte 0x03000738
lbl_0802a358:
    ldr r0, lbl_0802a370 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x44
lbl_0802a35e:
    strb r1, [r0]
lbl_0802a360:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802a370: .4byte 0x03000738

    thumb_func_start SpacePirateInit
SpacePirateInit: @ 0x0802a374
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r4, lbl_0802a418 @ =0x03000738
    ldrb r0, [r4, #0x1d]
    adds r5, r0, #0
    adds r2, r4, #0
    adds r2, #0x27
    movs r1, #0
    movs r0, #0x40
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x28
    movs r2, #8
    mov sl, r2
    mov r3, sl
    strb r3, [r0]
    adds r2, r4, #0
    adds r2, #0x29
    movs r0, #0x28
    strb r0, [r2]
    movs r7, #0
    ldr r0, lbl_0802a41c @ =0x0000ff60
    strh r0, [r4, #0xa]
    strh r1, [r4, #0xc]
    ldr r0, lbl_0802a420 @ =0x082e4320
    str r0, [r4, #0x18]
    ldr r0, lbl_0802a424 @ =0x0300083c
    mov r8, r0
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    strh r0, [r4, #0x16]
    strb r7, [r4, #0x1c]
    ldr r1, lbl_0802a428 @ =0x082b0d68
    lsls r0, r5, #3
    adds r0, r0, r5
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r4, #0x12]
    movs r1, #0x2e
    adds r1, r1, r4
    mov sb, r1
    strb r7, [r1]
    adds r0, r4, #0
    adds r0, #0x2a
    strb r7, [r0]
    adds r0, r5, #0
    subs r0, #0x52
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bls lbl_0802a3ec
    b lbl_0802a4f0
lbl_0802a3ec:
    adds r0, r4, #0
    adds r0, #0x25
    strb r7, [r0]
    ldrb r1, [r4, #0x1e]
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802a494
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a42c
    ldrh r0, [r4, #4]
    subs r0, #0x88
    b lbl_0802a430
    .align 2, 0
lbl_0802a418: .4byte 0x03000738
lbl_0802a41c: .4byte 0x0000ff60
lbl_0802a420: .4byte 0x082e4320
lbl_0802a424: .4byte 0x0300083c
lbl_0802a428: .4byte 0x082b0d68
lbl_0802a42c:
    ldrh r0, [r4, #4]
    adds r0, #0x88
lbl_0802a430:
    strh r0, [r4, #4]
    cmp r5, #0x53
    bne lbl_0802a444
    ldr r2, lbl_0802a440 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x78
    b lbl_0802a474
    .align 2, 0
lbl_0802a440: .4byte 0x03000738
lbl_0802a444:
    ldr r0, lbl_0802a460 @ =0x03000054
    ldrb r0, [r0]
    cmp r0, #6
    bne lbl_0802a46c
    ldr r0, lbl_0802a464 @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #0x50
    bne lbl_0802a46c
    ldr r2, lbl_0802a468 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x6e
    b lbl_0802a474
    .align 2, 0
lbl_0802a460: .4byte 0x03000054
lbl_0802a464: .4byte 0x03000055
lbl_0802a468: .4byte 0x03000738
lbl_0802a46c:
    ldr r2, lbl_0802a48c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x14
lbl_0802a474:
    strb r0, [r1]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x24
    strb r0, [r1]
    ldrh r1, [r2]
    ldr r3, lbl_0802a490 @ =0x00008020
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    b lbl_0802a628
    .align 2, 0
lbl_0802a48c: .4byte 0x03000738
lbl_0802a490: .4byte 0x00008020
lbl_0802a494:
    cmp r5, #0x53
    bne lbl_0802a49c
    strh r0, [r4]
    b lbl_0802a62c
lbl_0802a49c:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    subs r1, #0x80
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802a4be
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldrh r0, [r4, #4]
    subs r0, #0x28
    b lbl_0802a4ca
lbl_0802a4be:
    ldrh r0, [r4]
    ldr r1, lbl_0802a4e4 @ =0x0000fdff
    ands r1, r0
    strh r1, [r4]
    ldrh r0, [r4, #4]
    adds r0, #0x28
lbl_0802a4ca:
    strh r0, [r4, #4]
    ldr r1, lbl_0802a4e8 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r0, #0x28
    strb r0, [r2]
    ldrh r2, [r1]
    ldr r3, lbl_0802a4ec @ =0x00008024
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0802a628
    .align 2, 0
lbl_0802a4e4: .4byte 0x0000fdff
lbl_0802a4e8: .4byte 0x03000738
lbl_0802a4ec: .4byte 0x00008024
lbl_0802a4f0:
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #0x14
    strb r0, [r1]
    ldrh r6, [r4, #2]
    ldrh r5, [r4, #4]
    adds r0, r6, #0
    adds r1, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0802a550 @ =0x030001a8
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0802a56c
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldr r0, lbl_0802a554 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802a558
    adds r1, r5, #0
    subs r1, #0x40
    adds r0, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802a548
    adds r1, r5, #0
    adds r1, #0x40
    adds r0, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802a558
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
lbl_0802a548:
    bl SpacePirateClimbingUpInit
    b lbl_0802a628
    .align 2, 0
lbl_0802a550: .4byte 0x030001a8
lbl_0802a554: .4byte 0x030007f1
lbl_0802a558:
    bl SpriteUtilMakeSpriteFaceSamusDirection
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    mov r0, sl
    mov r3, sb
    strb r0, [r3]
    b lbl_0802a628
lbl_0802a56c:
    ldr r2, lbl_0802a5bc @ =0x030000dc
    mov sb, r2
    ldrh r0, [r2]
    cmp r0, #7
    bne lbl_0802a5d4
    ldr r0, lbl_0802a5c0 @ =0x082e4890
    str r0, [r4, #0x18]
    strh r1, [r4, #0x16]
    mov r3, r8
    ldrb r1, [r3]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, #0x3c
    adds r1, r4, #0
    adds r1, #0x2c
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r7, [r0]
    subs r1, #8
    movs r0, #0x27
    strb r0, [r1]
    adds r1, r5, #0
    adds r1, #0x40
    adds r0, r6, #0
    bl SpriteUtilCheckCollisionAtPosition
    mov r1, sb
    ldrh r0, [r1]
    cmp r0, #7
    bne lbl_0802a5c4
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    b lbl_0802a628
    .align 2, 0
lbl_0802a5bc: .4byte 0x030000dc
lbl_0802a5c0: .4byte 0x082e4890
lbl_0802a5c4:
    ldrh r1, [r4]
    ldr r0, lbl_0802a5d0 @ =0x0000fdff
    ands r0, r1
    strh r0, [r4]
    b lbl_0802a628
    .align 2, 0
lbl_0802a5d0: .4byte 0x0000fdff
lbl_0802a5d4:
    ldr r0, lbl_0802a5f8 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802a61c
    adds r1, r5, #0
    subs r1, #0x40
    adds r0, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802a5fc
    mov r3, r8
    ldrb r1, [r3]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0802a548
    b lbl_0802a616
    .align 2, 0
lbl_0802a5f8: .4byte 0x030007f1
lbl_0802a5fc:
    adds r1, r5, #0
    adds r1, #0x40
    adds r0, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802a61c
    mov r0, r8
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a548
lbl_0802a616:
    bl SpacePirateClimbingDownInit
    b lbl_0802a628
lbl_0802a61c:
    bl SpriteUtilMakeSpriteFaceSamusDirection
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
lbl_0802a628:
    bl SpacePirateFlip
lbl_0802a62c:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirateFallingInit
SpacePirateFallingInit: @ 0x0802a63c
    ldr r3, lbl_0802a668 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x1f
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r2, [r0]
    movs r1, #0
    ldr r0, lbl_0802a66c @ =0x0000ff60
    strh r0, [r3, #0xa]
    ldr r0, lbl_0802a670 @ =0x082e44d0
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r2, [r3, #0x16]
    ldrh r1, [r3]
    ldr r0, lbl_0802a674 @ =0x0000bfff
    ands r0, r1
    strh r0, [r3]
    bx lr
    .align 2, 0
lbl_0802a668: .4byte 0x03000738
lbl_0802a66c: .4byte 0x0000ff60
lbl_0802a670: .4byte 0x082e44d0
lbl_0802a674: .4byte 0x0000bfff

    thumb_func_start SpacePirateFalling
SpacePirateFalling: @ 0x0802a678
    push {r4, r5, r6, lr}
    ldr r4, lbl_0802a6c0 @ =0x03000738
    ldrh r1, [r4]
    movs r6, #0x80
    lsls r6, r6, #7
    adds r0, r6, #0
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r5, #0
    beq lbl_0802a6e6
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802a762
    ldrh r2, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    cmp r0, #0
    beq lbl_0802a6dc
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802a6c8
    ldr r0, lbl_0802a6c4 @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0802a762
    b lbl_0802a6d0
    .align 2, 0
lbl_0802a6c0: .4byte 0x03000738
lbl_0802a6c4: .4byte 0x030007f3
lbl_0802a6c8:
    ldr r0, lbl_0802a6d8 @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #1
    bne lbl_0802a762
lbl_0802a6d0:
    movs r0, #0x44
    strb r0, [r1]
    b lbl_0802a762
    .align 2, 0
lbl_0802a6d8: .4byte 0x030007f3
lbl_0802a6dc:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0802a762
lbl_0802a6e6:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802a71c @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802a728
    movs r2, #0
    strh r1, [r4, #2]
    ldrh r0, [r4]
    adds r1, r6, #0
    orrs r1, r0
    strh r1, [r4]
    ldr r0, lbl_0802a720 @ =0x082e44e0
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #2
    ands r1, r0
    cmp r1, #0
    beq lbl_0802a762
    ldr r0, lbl_0802a724 @ =0x00000167
    bl SoundPlayNotAlreadyPlaying
    b lbl_0802a762
    .align 2, 0
lbl_0802a71c: .4byte 0x030007f0
lbl_0802a720: .4byte 0x082e44e0
lbl_0802a724: .4byte 0x00000167
lbl_0802a728:
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r1, [r5]
    ldr r3, lbl_0802a750 @ =0x082b0d04
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r6, #0
    ldrsh r2, [r0, r6]
    ldr r0, lbl_0802a754 @ =0x00007fff
    cmp r2, r0
    bne lbl_0802a758
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r6, [r4, #2]
    adds r0, r0, r6
    b lbl_0802a760
    .align 2, 0
lbl_0802a750: .4byte 0x082b0d04
lbl_0802a754: .4byte 0x00007fff
lbl_0802a758:
    adds r0, r1, #1
    strb r0, [r5]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_0802a760:
    strh r0, [r4, #2]
lbl_0802a762:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start unk_2a768
unk_2a768: @ 0x0802a768
    ldr r0, lbl_0802a788 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0xf
    strb r1, [r2]
    movs r2, #0
    ldr r1, lbl_0802a78c @ =0x0000ff60
    strh r1, [r0, #0xa]
    ldr r1, lbl_0802a790 @ =0x082e42f8
    str r1, [r0, #0x18]
    strb r2, [r0, #0x1c]
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802a788: .4byte 0x03000738
lbl_0802a78c: .4byte 0x0000ff60
lbl_0802a790: .4byte 0x082e42f8

    thumb_func_start unk_2a794
unk_2a794: @ 0x0802a794
    ldr r0, lbl_0802a7b4 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0xf
    strb r1, [r2]
    movs r2, #0
    ldr r1, lbl_0802a7b8 @ =0x0000ff60
    strh r1, [r0, #0xa]
    ldr r1, lbl_0802a7bc @ =0x082e48b8
    str r1, [r0, #0x18]
    strb r2, [r0, #0x1c]
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802a7b4: .4byte 0x03000738
lbl_0802a7b8: .4byte 0x0000ff60
lbl_0802a7bc: .4byte 0x082e48b8

    thumb_func_start unk_2a7c0
unk_2a7c0: @ 0x0802a7c0
    push {lr}
    bl unk_f594
    ldr r0, lbl_0802a7d8 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802a7e0
    ldr r0, lbl_0802a7dc @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    b lbl_0802a7f8
    .align 2, 0
lbl_0802a7d8: .4byte 0x030007f0
lbl_0802a7dc: .4byte 0x03000738
lbl_0802a7e0:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802a7fa
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802a7fa
    ldr r0, lbl_0802a800 @ =0x03000738
    adds r0, #0x24
    movs r1, #8
lbl_0802a7f8:
    strb r1, [r0]
lbl_0802a7fa:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802a800: .4byte 0x03000738

    thumb_func_start SpacePirateWalkingInit
SpacePirateWalkingInit: @ 0x0802a804
    push {lr}
    ldr r2, lbl_0802a830 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r3, #0
    movs r0, #9
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x2e
    strb r3, [r0]
    ldr r0, lbl_0802a834 @ =0x0000ff60
    strh r0, [r2, #0xa]
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0802a838 @ =0x082e4320
    cmp r0, r1
    beq lbl_0802a82c
    str r1, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r3, [r2, #0x16]
lbl_0802a82c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802a830: .4byte 0x03000738
lbl_0802a834: .4byte 0x0000ff60
lbl_0802a838: .4byte 0x082e4320

    thumb_func_start SpacePirateWalking
SpacePirateWalking: @ 0x0802a83c
    push {r4, r5, r6, lr}
    ldr r4, lbl_0802a880 @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl sub_08029b68
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    bne lbl_0802a900
    bl sub_08029ef0
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #9
    bne lbl_0802a900
    bl sub_08029708
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    beq lbl_0802a88c
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802a884 @ =0x082e4320
    cmp r1, r0
    bne lbl_0802a900
    ldr r0, lbl_0802a888 @ =0x082e42f8
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    strh r6, [r4, #0x16]
    b lbl_0802a900
    .align 2, 0
lbl_0802a880: .4byte 0x03000738
lbl_0802a884: .4byte 0x082e4320
lbl_0802a888: .4byte 0x082e42f8
lbl_0802a88c:
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802a8c4 @ =0x082e42f8
    cmp r1, r0
    bne lbl_0802a8ac
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802a900
    ldr r0, lbl_0802a8c8 @ =0x082e4320
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r0, #0
    strh r5, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
lbl_0802a8ac:
    adds r4, #0x2e
    ldrb r0, [r4]
    lsrs r0, r0, #2
    bl sub_0800f978
    ldrb r0, [r4]
    adds r1, r0, #0
    cmp r1, #0x1f
    bhi lbl_0802a8cc
    adds r0, #2
    b lbl_0802a8d2
    .align 2, 0
lbl_0802a8c4: .4byte 0x082e42f8
lbl_0802a8c8: .4byte 0x082e4320
lbl_0802a8cc:
    cmp r1, #0x20
    bls lbl_0802a8d4
    subs r0, #1
lbl_0802a8d2:
    strb r0, [r4]
lbl_0802a8d4:
    ldr r2, lbl_0802a908 @ =0x03000738
    ldrh r0, [r2, #0x12]
    cmp r0, #0xff
    bhi lbl_0802a8e0
    adds r0, #1
    strh r0, [r2, #0x12]
lbl_0802a8e0:
    ldrb r0, [r2, #0x1c]
    cmp r0, #5
    bls lbl_0802a900
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802a900
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a900
    ldr r0, lbl_0802a90c @ =0x00000165
    bl SoundPlayNotAlreadyPlaying
lbl_0802a900:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802a908: .4byte 0x03000738
lbl_0802a90c: .4byte 0x00000165

    thumb_func_start SpacePirateIdle
SpacePirateIdle: @ 0x0802a910
    push {r4, r5, r6, lr}
    movs r5, #0
    ldr r4, lbl_0802a92c @ =0x03000738
    adds r6, r4, #0
    adds r6, #0x2d
    ldrb r0, [r6]
    cmp r0, #1
    beq lbl_0802a9d0
    cmp r0, #1
    bgt lbl_0802a930
    cmp r0, #0
    beq lbl_0802a936
    b lbl_0802aa20
    .align 2, 0
lbl_0802a92c: .4byte 0x03000738
lbl_0802a930:
    cmp r0, #2
    beq lbl_0802a9fc
    b lbl_0802aa20
lbl_0802a936:
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802a976
    adds r1, r4, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x10
    bne lbl_0802a950
    movs r0, #0x27
    strb r0, [r1]
    b lbl_0802a9b2
lbl_0802a950:
    cmp r0, #0xe
    bne lbl_0802a96c
    movs r0, #0x27
    strb r0, [r1]
    ldr r0, lbl_0802a968 @ =0x082e42f8
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #2
    strb r0, [r6]
    b lbl_0802a9ae
    .align 2, 0
lbl_0802a968: .4byte 0x082e42f8
lbl_0802a96c:
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #0x14
    strb r0, [r1]
    b lbl_0802a9ae
lbl_0802a976:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802a98c
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802a9ae
    b lbl_0802a9b2
lbl_0802a98c:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0802a99c
    subs r0, #1
    strb r0, [r1]
    b lbl_0802a9ae
lbl_0802a99c:
    ldr r1, lbl_0802a9c4 @ =0x0300083c
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r0, [r0]
    ldrb r1, [r1]
    lsrs r0, r0, #1
    cmp r1, r0
    bne lbl_0802a9ae
    movs r5, #1
lbl_0802a9ae:
    cmp r5, #0
    beq lbl_0802aa20
lbl_0802a9b2:
    ldr r1, lbl_0802a9c8 @ =0x03000738
    ldr r0, lbl_0802a9cc @ =0x082e43c8
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    adds r1, #0x2d
    movs r0, #1
    b lbl_0802aa1e
    .align 2, 0
lbl_0802a9c4: .4byte 0x0300083c
lbl_0802a9c8: .4byte 0x03000738
lbl_0802a9cc: .4byte 0x082e43c8
lbl_0802a9d0:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802aa20
    movs r0, #2
    strb r0, [r6]
    ldr r0, lbl_0802a9f8 @ =0x082e43f0
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldrh r0, [r4]
    movs r2, #0xa0
    lsls r2, r2, #4
    adds r1, r2, #0
    eors r0, r1
    strh r0, [r4]
    bl SpacePirateFlip
    b lbl_0802aa20
    .align 2, 0
lbl_0802a9f8: .4byte 0x082e43f0
lbl_0802a9fc:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802aa20
    strb r5, [r6]
    ldr r0, lbl_0802aa28 @ =0x082e4890
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldr r0, lbl_0802aa2c @ =0x0300083c
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, #0x3c
    adds r1, r4, #0
    adds r1, #0x2c
lbl_0802aa1e:
    strb r0, [r1]
lbl_0802aa20:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802aa28: .4byte 0x082e4890
lbl_0802aa2c: .4byte 0x0300083c

    thumb_func_start SpacePirateIdleAtDoor
SpacePirateIdleAtDoor: @ 0x0802aa30
    push {lr}
    ldr r2, lbl_0802aa54 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0802aa58 @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_0802aa50
    adds r1, #6
    movs r0, #0x14
    strb r0, [r1]
    subs r1, #8
    movs r0, #0x24
    strb r0, [r1]
lbl_0802aa50:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802aa54: .4byte 0x03000738
lbl_0802aa58: .4byte 0x030001a8

    thumb_func_start unk_2aa5c
unk_2aa5c: @ 0x0802aa5c
    ldr r3, lbl_0802aa80 @ =0x03000738
    ldr r0, lbl_0802aa84 @ =0x082e4890
    str r0, [r3, #0x18]
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x2b
    strb r0, [r1]
    strb r2, [r3, #0x1c]
    movs r0, #0
    strh r2, [r3, #0x16]
    adds r1, #0xa
    strb r0, [r1]
    subs r1, #2
    movs r0, #6
    strb r0, [r1]
    bx lr
    .align 2, 0
lbl_0802aa80: .4byte 0x03000738
lbl_0802aa84: .4byte 0x082e4890

    thumb_func_start unk_2aa88
unk_2aa88: @ 0x0802aa88
    push {r4, r5, lr}
    bl unk_f594
    ldr r0, lbl_0802aaa0 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802aaa8
    ldr r0, lbl_0802aaa4 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0802aae4
    .align 2, 0
lbl_0802aaa0: .4byte 0x030007f0
lbl_0802aaa4: .4byte 0x03000738
lbl_0802aaa8:
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802aae4
    ldr r5, lbl_0802aad0 @ =0x03000738
    adds r4, r5, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0802aad4
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802aae4
    ldrb r0, [r4]
    subs r0, #1
    strb r0, [r4]
    b lbl_0802aae4
    .align 2, 0
lbl_0802aad0: .4byte 0x03000738
lbl_0802aad4:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802aae4
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x44
    strb r0, [r1]
lbl_0802aae4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start unk_2aaec
unk_2aaec: @ 0x0802aaec
    ldr r0, lbl_0802ab08 @ =0x03000738
    ldr r1, lbl_0802ab0c @ =0x082e42f8
    str r1, [r0, #0x18]
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x11
    strb r1, [r2]
    strb r3, [r0, #0x1c]
    movs r1, #0
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0802ab08: .4byte 0x03000738
lbl_0802ab0c: .4byte 0x082e42f8

    thumb_func_start unk_2ab10
unk_2ab10: @ 0x0802ab10
    ldr r0, lbl_0802ab2c @ =0x03000738
    ldr r1, lbl_0802ab30 @ =0x082e4890
    str r1, [r0, #0x18]
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x11
    strb r1, [r2]
    strb r3, [r0, #0x1c]
    movs r1, #0
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0802ab2c: .4byte 0x03000738
lbl_0802ab30: .4byte 0x082e4890

    thumb_func_start unk_2ab34
unk_2ab34: @ 0x0802ab34
    ldr r0, lbl_0802ab50 @ =0x03000738
    ldr r1, lbl_0802ab54 @ =0x082e48b8
    str r1, [r0, #0x18]
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x11
    strb r1, [r2]
    strb r3, [r0, #0x1c]
    movs r1, #0
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0802ab50: .4byte 0x03000738
lbl_0802ab54: .4byte 0x082e48b8

    thumb_func_start sub_0802ab58
sub_0802ab58: @ 0x0802ab58
    push {lr}
    bl unk_f594
    ldr r0, lbl_0802ab70 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802ab78
    ldr r0, lbl_0802ab74 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0802ab98
    .align 2, 0
lbl_0802ab70: .4byte 0x030007f0
lbl_0802ab74: .4byte 0x03000738
lbl_0802ab78:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802ab98
    ldr r1, lbl_0802ab9c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0xb
    strb r0, [r2]
    movs r2, #0
    strh r3, [r1, #0x12]
    ldr r0, lbl_0802aba0 @ =0x082e43c8
    str r0, [r1, #0x18]
    strb r2, [r1, #0x1c]
    strh r3, [r1, #0x16]
lbl_0802ab98:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ab9c: .4byte 0x03000738
lbl_0802aba0: .4byte 0x082e43c8

    thumb_func_start SpacePirateTurningAroundInit
SpacePirateTurningAroundInit: @ 0x0802aba4
    ldr r0, lbl_0802abc8 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0xb
    strb r1, [r2]
    movs r2, #0
    ldr r1, lbl_0802abcc @ =0x0000ff60
    strh r1, [r0, #0xa]
    strh r3, [r0, #0x12]
    ldr r1, lbl_0802abd0 @ =0x082e43c8
    str r1, [r0, #0x18]
    strb r2, [r0, #0x1c]
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802abc8: .4byte 0x03000738
lbl_0802abcc: .4byte 0x0000ff60
lbl_0802abd0: .4byte 0x082e43c8

    thumb_func_start SpacePirateTurningAroundFirstPart
SpacePirateTurningAroundFirstPart: @ 0x0802abd4
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802ac02
    ldr r2, lbl_0802ac08 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r3, #0
    movs r0, #0xc
    strb r0, [r1]
    ldr r0, lbl_0802ac0c @ =0x082e43f0
    str r0, [r2, #0x18]
    strb r3, [r2, #0x1c]
    strh r3, [r2, #0x16]
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    bl SpacePirateFlip
lbl_0802ac02:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ac08: .4byte 0x03000738
lbl_0802ac0c: .4byte 0x082e43f0

    thumb_func_start SpacePirateTurningAroundSecondPart
SpacePirateTurningAroundSecondPart: @ 0x0802ac10
    push {r4, lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802ac54
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802ac4c
    ldr r4, lbl_0802ac48 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ac54
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802ac54
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    b lbl_0802ac54
    .align 2, 0
lbl_0802ac48: .4byte 0x03000738
lbl_0802ac4c:
    ldr r0, lbl_0802ac5c @ =0x03000738
    adds r0, #0x24
    movs r1, #8
    strb r1, [r0]
lbl_0802ac54:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ac5c: .4byte 0x03000738

    thumb_func_start SpacePirateTurningAroundAlertedInit
SpacePirateTurningAroundAlertedInit: @ 0x0802ac60
    ldr r0, lbl_0802ac80 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x45
    strb r1, [r2]
    movs r2, #0
    ldr r1, lbl_0802ac84 @ =0x0000ff60
    strh r1, [r0, #0xa]
    ldr r1, lbl_0802ac88 @ =0x082e43c8
    str r1, [r0, #0x18]
    strb r2, [r0, #0x1c]
    strh r3, [r0, #0x16]
    adds r0, #0x2e
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802ac80: .4byte 0x03000738
lbl_0802ac84: .4byte 0x0000ff60
lbl_0802ac88: .4byte 0x082e43c8

    thumb_func_start SpacePirateTurningAroundFirstPartAlerted
SpacePirateTurningAroundFirstPartAlerted: @ 0x0802ac8c
    push {r4, r5, lr}
    ldr r4, lbl_0802acc8 @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    movs r5, #0
    strb r0, [r4, #0x1c]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802acc0
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x47
    strb r0, [r1]
    ldr r0, lbl_0802accc @ =0x082e43f0
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    eors r0, r1
    strh r0, [r4]
    bl SpacePirateFlip
lbl_0802acc0:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802acc8: .4byte 0x03000738
lbl_0802accc: .4byte 0x082e43f0

    thumb_func_start SpacePirateTurningAroundSecondPartAlerted
SpacePirateTurningAroundSecondPartAlerted: @ 0x0802acd0
    push {r4, lr}
    ldr r4, lbl_0802ad0c @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802ad2c
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ad1a
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802ad2c
    bl sub_08029ef0
    adds r1, r4, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x47
    bne lbl_0802ad10
    movs r0, #0x22
    b lbl_0802ad2a
    .align 2, 0
lbl_0802ad0c: .4byte 0x03000738
lbl_0802ad10:
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x55
    bne lbl_0802ad2c
    movs r0, #0x2a
    b lbl_0802ad2a
lbl_0802ad1a:
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802ad2c
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
lbl_0802ad2a:
    strb r0, [r1]
lbl_0802ad2c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirateWalkingAlertedInit
SpacePirateWalkingAlertedInit: @ 0x0802ad34
    push {lr}
    ldr r2, lbl_0802ad60 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    ldr r0, lbl_0802ad64 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r1, #0xa
    movs r0, #8
    strb r0, [r1]
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0802ad68 @ =0x082e4320
    cmp r0, r1
    beq lbl_0802ad5c
    str r1, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    movs r0, #0
    strh r0, [r2, #0x16]
lbl_0802ad5c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ad60: .4byte 0x03000738
lbl_0802ad64: .4byte 0x0000ff60
lbl_0802ad68: .4byte 0x082e4320

    thumb_func_start SpacePirateWalkingAlerted
SpacePirateWalkingAlerted: @ 0x0802ad6c
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_0802ada8 @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    beq lbl_0802ad84
    b lbl_0802ae82
lbl_0802ad84:
    bl sub_08029ef0
    adds r7, r4, #0
    adds r7, #0x24
    ldrb r0, [r7]
    cmp r0, #0x23
    beq lbl_0802adac
    ldrb r1, [r4, #0x1d]
    cmp r1, #0x53
    beq lbl_0802ad9c
    cmp r1, #0x55
    bne lbl_0802ae82
lbl_0802ad9c:
    cmp r0, #0x42
    bne lbl_0802ae82
    movs r0, #0x2a
    strb r0, [r7]
    b lbl_0802ae82
    .align 2, 0
lbl_0802ada8: .4byte 0x03000738
lbl_0802adac:
    bl sub_08029708
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    beq lbl_0802ae12
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802adcc @ =0x082e4320
    cmp r1, r0
    bne lbl_0802add4
    ldr r0, lbl_0802add0 @ =0x082e42f8
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    strh r6, [r4, #0x16]
    b lbl_0802ae82
    .align 2, 0
lbl_0802adcc: .4byte 0x082e4320
lbl_0802add0: .4byte 0x082e42f8
lbl_0802add4:
    ldr r0, lbl_0802ae00 @ =0x082e42f8
    cmp r1, r0
    bne lbl_0802ae82
    ldr r0, lbl_0802ae04 @ =0x030007f3
    ldrb r0, [r0, #2]
    cmp r0, #1
    bne lbl_0802ae82
    movs r1, #0xa0
    lsls r1, r1, #2
    adds r0, r1, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r2, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ae08
    cmp r2, #4
    bne lbl_0802ae82
    b lbl_0802ae0c
    .align 2, 0
lbl_0802ae00: .4byte 0x082e42f8
lbl_0802ae04: .4byte 0x030007f3
lbl_0802ae08:
    cmp r2, #8
    bne lbl_0802ae82
lbl_0802ae0c:
    movs r0, #0x44
    strb r0, [r7]
    b lbl_0802ae82
lbl_0802ae12:
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802ae54 @ =0x082e42f8
    cmp r1, r0
    bne lbl_0802ae32
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802ae82
    ldr r0, lbl_0802ae58 @ =0x082e4320
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r0, #0
    strh r5, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
lbl_0802ae32:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ae5c
    adds r4, #0x2e
    ldrb r0, [r4]
    lsrs r0, r0, #2
    bl sub_0800f978
    ldrb r0, [r4]
    cmp r0, #0x33
    bhi lbl_0802ae60
    adds r0, #2
    strb r0, [r4]
    b lbl_0802ae60
    .align 2, 0
lbl_0802ae54: .4byte 0x082e42f8
lbl_0802ae58: .4byte 0x082e4320
lbl_0802ae5c:
    movs r0, #9
    strb r0, [r7]
lbl_0802ae60:
    ldr r2, lbl_0802ae88 @ =0x03000738
    ldrb r0, [r2, #0x1c]
    cmp r0, #5
    bls lbl_0802ae82
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802ae82
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ae82
    ldr r0, lbl_0802ae8c @ =0x00000165
    bl SoundPlayNotAlreadyPlaying
lbl_0802ae82:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ae88: .4byte 0x03000738
lbl_0802ae8c: .4byte 0x00000165

    thumb_func_start SpacePirateJumpingInit
SpacePirateJumpingInit: @ 0x0802ae90
    push {lr}
    ldr r3, lbl_0802aed4 @ =0x03000738
    adds r2, r3, #0
    adds r2, #0x24
    movs r1, #0
    movs r0, #0x43
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r1, [r0]
    ldr r0, lbl_0802aed8 @ =0x082e4450
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    movs r2, #0
    strh r1, [r3, #0x16]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r2, [r0]
    ldrh r0, [r3]
    ldr r1, lbl_0802aedc @ =0x0000bfff
    ands r1, r0
    strh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802aee4
    ldr r0, lbl_0802aee0 @ =0x030013d4
    ldrh r0, [r0, #0x12]
    ldrh r1, [r3, #4]
    cmp r0, r1
    bhs lbl_0802aef4
    b lbl_0802aeee
    .align 2, 0
lbl_0802aed4: .4byte 0x03000738
lbl_0802aed8: .4byte 0x082e4450
lbl_0802aedc: .4byte 0x0000bfff
lbl_0802aee0: .4byte 0x030013d4
lbl_0802aee4:
    ldr r0, lbl_0802aef8 @ =0x030013d4
    ldrh r0, [r0, #0x12]
    ldrh r1, [r3, #4]
    cmp r0, r1
    bls lbl_0802aef4
lbl_0802aeee:
    adds r0, r3, #0
    adds r0, #0x2e
    strb r2, [r0]
lbl_0802aef4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802aef8: .4byte 0x030013d4

    thumb_func_start SpacePirateJumping
SpacePirateJumping: @ 0x0802aefc
    push {r4, r5, r6, r7, lr}
    movs r7, #0
    ldr r4, lbl_0802af4c @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #7
    ands r0, r1
    cmp r0, #0
    beq lbl_0802af76
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0802af18
    b lbl_0802b2f6
lbl_0802af18:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802af50
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802af30
    b lbl_0802b2f6
lbl_0802af30:
    bl sub_08029ef0
    adds r1, r4, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x43
    beq lbl_0802af44
    cmp r0, #0x4d
    beq lbl_0802af44
    b lbl_0802b2f6
lbl_0802af44:
    movs r0, #0x22
    strb r0, [r1]
    b lbl_0802b2f6
    .align 2, 0
lbl_0802af4c: .4byte 0x03000738
lbl_0802af50:
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802af5c
    b lbl_0802b2f6
lbl_0802af5c:
    bl sub_08029ef0
    adds r1, r4, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x43
    beq lbl_0802af70
    cmp r0, #0x4d
    beq lbl_0802af70
    b lbl_0802b2f6
lbl_0802af70:
    movs r0, #8
    strb r0, [r1]
    b lbl_0802b2f6
lbl_0802af76:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    bne lbl_0802afec
    ldrh r0, [r4, #0x16]
    cmp r0, #3
    bhi lbl_0802afc6
    cmp r0, #3
    beq lbl_0802af8c
    b lbl_0802b2f6
lbl_0802af8c:
    ldr r1, [r4, #0x18]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r1, [r0, #4]
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    cmp r1, r0
    blt lbl_0802af9e
    b lbl_0802b2f6
lbl_0802af9e:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    ldrh r0, [r4, #2]
    subs r0, #0xb4
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802afb4
    b lbl_0802b2f6
lbl_0802afb4:
    ldrh r0, [r4, #2]
    subs r0, #0xb4
    movs r2, #0x40
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    adds r0, #0xf4
    strh r0, [r4, #2]
    b lbl_0802b2f6
lbl_0802afc6:
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802afe8
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    lsrs r6, r0, #2
    cmp r6, #5
    bgt lbl_0802afe0
    movs r6, #5
    b lbl_0802afee
lbl_0802afe0:
    cmp r6, #8
    ble lbl_0802afee
    movs r6, #9
    b lbl_0802afee
lbl_0802afe8:
    movs r6, #4
    b lbl_0802afee
lbl_0802afec:
    movs r6, #0xc
lbl_0802afee:
    ldr r4, lbl_0802b048 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b04c
    ldrh r0, [r4, #2]
    subs r0, #0xa0
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b012
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b012:
    ldrh r0, [r4, #2]
    subs r0, #0x5a
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b028
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b028:
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b03e
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b03e:
    cmp r7, #0
    bne lbl_0802b098
    ldrh r0, [r4, #4]
    adds r0, r0, r6
    b lbl_0802b096
    .align 2, 0
lbl_0802b048: .4byte 0x03000738
lbl_0802b04c:
    ldrh r0, [r4, #2]
    subs r0, #0xa0
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b062
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b062:
    ldrh r0, [r4, #2]
    subs r0, #0x5a
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b078
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b078:
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b08e
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802b08e:
    cmp r7, #0
    bne lbl_0802b098
    ldrh r0, [r4, #4]
    subs r0, r0, r6
lbl_0802b096:
    strh r0, [r4, #4]
lbl_0802b098:
    ldr r1, lbl_0802b0cc @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_0802b0de
    cmp r7, #0
    bne lbl_0802b0ae
    b lbl_0802b1c8
lbl_0802b0ae:
    ldr r1, lbl_0802b0d0 @ =0x030013d4
    ldrh r0, [r5, #2]
    ldrh r3, [r1, #0x14]
    cmp r0, r3
    bhs lbl_0802b0de
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802b0d4
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0802b0de
    b lbl_0802b1c8
    .align 2, 0
lbl_0802b0cc: .4byte 0x03000738
lbl_0802b0d0: .4byte 0x030013d4
lbl_0802b0d4:
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bhs lbl_0802b0de
    movs r7, #0
lbl_0802b0de:
    cmp r7, #0
    beq lbl_0802b1c8
    movs r2, #2
    cmp r7, #2
    bhi lbl_0802b0f0
    movs r2, #0x1e
    cmp r7, #1
    bls lbl_0802b0f0
    movs r2, #0xf
lbl_0802b0f0:
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, r2
    bls lbl_0802b1c8
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b118
    ldrh r0, [r5, #2]
    subs r0, #0xa8
    ldrh r1, [r5, #4]
    adds r1, #0x30
    b lbl_0802b120
lbl_0802b118:
    ldrh r0, [r5, #2]
    subs r0, #0xa8
    ldrh r1, [r5, #4]
    subs r1, #0x30
lbl_0802b120:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802b140
    ldr r2, lbl_0802b13c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x48
    strb r0, [r1]
    adds r5, r2, #0
    b lbl_0802b1b8
    .align 2, 0
lbl_0802b13c: .4byte 0x03000738
lbl_0802b140:
    ldr r1, lbl_0802b174 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_0802b198
    ldr r0, lbl_0802b178 @ =0x030007f3
    ldrb r0, [r0, #3]
    cmp r0, #1
    bne lbl_0802b1b0
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802b180
    ldr r1, lbl_0802b17c @ =0x030013d4
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0802b1b0
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802b1b6
    .align 2, 0
lbl_0802b174: .4byte 0x03000738
lbl_0802b178: .4byte 0x030007f3
lbl_0802b17c: .4byte 0x030013d4
lbl_0802b180:
    ldr r1, lbl_0802b194 @ =0x030013d4
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bhi lbl_0802b1b0
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802b1b6
    .align 2, 0
lbl_0802b194: .4byte 0x030013d4
lbl_0802b198:
    ldr r0, lbl_0802b1ac @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b1b0
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802b1b6
    .align 2, 0
lbl_0802b1ac: .4byte 0x0300083c
lbl_0802b1b0:
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x48
lbl_0802b1b6:
    strb r0, [r1]
lbl_0802b1b8:
    ldrh r1, [r5, #4]
    ldr r0, lbl_0802b1c4 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x20
    strh r0, [r5, #4]
    b lbl_0802b2f6
    .align 2, 0
lbl_0802b1c4: .4byte 0x0000ffc0
lbl_0802b1c8:
    ldr r1, lbl_0802b210 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802b1e6
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b1e6
    movs r0, #0xb3
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0802b1e6:
    ldr r1, lbl_0802b210 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #1
    bne lbl_0802b218
    ldr r0, lbl_0802b214 @ =0x082e1030
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x2a
    bhi lbl_0802b27e
    b lbl_0802b27a
    .align 2, 0
lbl_0802b210: .4byte 0x03000738
lbl_0802b214: .4byte 0x082e1030
lbl_0802b218:
    cmp r0, #2
    bne lbl_0802b23c
    ldr r0, lbl_0802b238 @ =0x082e1046
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x26
    bhi lbl_0802b27e
    b lbl_0802b27a
    .align 2, 0
lbl_0802b238: .4byte 0x082e1046
lbl_0802b23c:
    cmp r0, #3
    bne lbl_0802b260
    ldr r0, lbl_0802b25c @ =0x082e105a
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x2a
    bhi lbl_0802b27e
    b lbl_0802b27a
    .align 2, 0
lbl_0802b25c: .4byte 0x082e105a
lbl_0802b260:
    ldr r0, lbl_0802b2c8 @ =0x082e1020
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x1e
    bhi lbl_0802b27e
lbl_0802b27a:
    adds r0, r3, #1
    strb r0, [r4]
lbl_0802b27e:
    adds r4, r5, #0
    ldrh r0, [r4, #2]
    adds r0, r0, r6
    movs r7, #0
    strh r0, [r4, #2]
    cmp r6, #0
    ble lbl_0802b2d8
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802b2cc @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802b2f6
    strh r1, [r4, #2]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #7
    adds r1, r2, #0
    orrs r0, r1
    orrs r0, r7
    strh r0, [r4]
    ldr r1, lbl_0802b2d0 @ =0x082e44e0
    str r1, [r4, #0x18]
    strb r7, [r4, #0x1c]
    movs r1, #0
    strh r1, [r4, #0x16]
    movs r1, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b2f6
    ldr r0, lbl_0802b2d4 @ =0x00000167
    bl SoundPlayNotAlreadyPlaying
    b lbl_0802b2f6
    .align 2, 0
lbl_0802b2c8: .4byte 0x082e1020
lbl_0802b2cc: .4byte 0x030007f0
lbl_0802b2d0: .4byte 0x082e44e0
lbl_0802b2d4: .4byte 0x00000167
lbl_0802b2d8:
    ldrh r0, [r5, #2]
    subs r0, #0xb4
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b2f6
    ldrh r0, [r5, #2]
    subs r0, #0xb4
    movs r3, #0x40
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    adds r0, #0xf4
    strh r0, [r5, #2]
lbl_0802b2f6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start SpacePirateChargingLaserInit
SpacePirateChargingLaserInit: @ 0x0802b2fc
    push {lr}
    ldr r2, lbl_0802b31c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x35
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x18
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0802b324
    ldr r0, lbl_0802b320 @ =0x082e4558
    b lbl_0802b332
    .align 2, 0
lbl_0802b31c: .4byte 0x03000738
lbl_0802b320: .4byte 0x082e4558
lbl_0802b324:
    cmp r0, #2
    bne lbl_0802b330
    ldr r0, lbl_0802b32c @ =0x082e4490
    b lbl_0802b332
    .align 2, 0
lbl_0802b32c: .4byte 0x082e4490
lbl_0802b330:
    ldr r0, lbl_0802b348 @ =0x082e4368
lbl_0802b332:
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    movs r1, #0
    strh r0, [r2, #0x16]
    adds r0, r2, #0
    adds r0, #0x2e
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802b348: .4byte 0x082e4368

    thumb_func_start SpacePirateChargingLaser
SpacePirateChargingLaser: @ 0x0802b34c
    push {lr}
    bl unk_f594
    ldr r0, lbl_0802b364 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802b36c
    ldr r0, lbl_0802b368 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0802b38a
    .align 2, 0
lbl_0802b364: .4byte 0x030007f0
lbl_0802b368: .4byte 0x03000738
lbl_0802b36c:
    ldr r1, lbl_0802b380 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0802b384
    subs r0, #1
    strb r0, [r2]
    b lbl_0802b38a
    .align 2, 0
lbl_0802b380: .4byte 0x03000738
lbl_0802b384:
    adds r1, #0x24
    movs r0, #0x36
    strb r0, [r1]
lbl_0802b38a:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirateShootingLaserInit
SpacePirateShootingLaserInit: @ 0x0802b390
    push {lr}
    ldr r0, lbl_0802b3ac @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x37
    strb r1, [r2]
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r1, [r1]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_0802b3b4
    ldr r0, lbl_0802b3b0 @ =0x082e4598
    b lbl_0802b3c2
    .align 2, 0
lbl_0802b3ac: .4byte 0x03000738
lbl_0802b3b0: .4byte 0x082e4598
lbl_0802b3b4:
    cmp r1, #2
    bne lbl_0802b3c0
    ldr r0, lbl_0802b3bc @ =0x082e4508
    b lbl_0802b3c2
    .align 2, 0
lbl_0802b3bc: .4byte 0x082e4508
lbl_0802b3c0:
    ldr r0, lbl_0802b3d0 @ =0x082e4428
lbl_0802b3c2:
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802b3d0: .4byte 0x082e4428

    thumb_func_start SpacePirateShootingLaser
SpacePirateShootingLaser: @ 0x0802b3d4
    push {r4, r5, lr}
    ldr r1, lbl_0802b400 @ =0x03000738
    ldrh r0, [r1, #0x16]
    cmp r0, #2
    bne lbl_0802b3e8
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0802b3e8
    bl SpacePirateFireLaserGround
lbl_0802b3e8:
    bl unk_f594
    ldr r0, lbl_0802b404 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802b408
    ldr r0, lbl_0802b400 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0802b4ba
    .align 2, 0
lbl_0802b400: .4byte 0x03000738
lbl_0802b404: .4byte 0x030007f0
lbl_0802b408:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802b4ba
    ldr r0, lbl_0802b424 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_0802b42c
    ldr r0, lbl_0802b428 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x22
    strb r1, [r0]
    b lbl_0802b4ba
    .align 2, 0
lbl_0802b424: .4byte 0x030007f3
lbl_0802b428: .4byte 0x03000738
lbl_0802b42c:
    ldr r0, lbl_0802b47c @ =0x03000738
    ldrb r0, [r0, #0x1d]
    movs r1, #0x80
    lsls r1, r1, #2
    cmp r0, #0x55
    beq lbl_0802b446
    subs r1, #0x80
    ldr r0, lbl_0802b480 @ =0x030013d4
    movs r2, #0x16
    ldrsh r0, [r0, r2]
    cmp r0, #0
    beq lbl_0802b446
    movs r1, #0xc0
lbl_0802b446:
    adds r4, r5, #0
    ldrb r0, [r4]
    movs r2, #0xc0
    lsls r2, r2, #1
    cmp r0, #0
    bne lbl_0802b454
    movs r2, #0x80
lbl_0802b454:
    adds r0, r2, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r3, r0, #0
    ldr r2, lbl_0802b47c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b490
    cmp r3, #8
    bne lbl_0802b484
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    ldrb r1, [r4]
    b lbl_0802b4aa
    .align 2, 0
lbl_0802b47c: .4byte 0x03000738
lbl_0802b480: .4byte 0x030013d4
lbl_0802b484:
    cmp r3, #4
    bne lbl_0802b4b2
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_0802b4b8
lbl_0802b490:
    cmp r3, #8
    bne lbl_0802b49c
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_0802b4b8
lbl_0802b49c:
    cmp r3, #4
    bne lbl_0802b4b2
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    ldrb r1, [r5]
lbl_0802b4aa:
    adds r0, r2, #0
    adds r0, #0x2d
    strb r1, [r0]
    b lbl_0802b4ba
lbl_0802b4b2:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
lbl_0802b4b8:
    strb r0, [r1]
lbl_0802b4ba:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start SpacePirateWaitingAtDoor
SpacePirateWaitingAtDoor: @ 0x0802b4c0
    push {r4, r5, r6, r7, lr}
    sub sp, #0xc
    ldr r0, lbl_0802b4d4 @ =0x030001a8
    ldrh r1, [r0]
    cmp r1, #0
    bne lbl_0802b4dc
    ldr r0, lbl_0802b4d8 @ =0x03000738
    strh r1, [r0]
    b lbl_0802b620
    .align 2, 0
lbl_0802b4d4: .4byte 0x030001a8
lbl_0802b4d8: .4byte 0x03000738
lbl_0802b4dc:
    movs r7, #0
    movs r5, #0
    ldr r1, lbl_0802b500 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x26
    movs r0, #1
    strb r0, [r2]
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0802b504
    ldrh r0, [r6, #4]
    adds r0, #0x40
    b lbl_0802b508
    .align 2, 0
lbl_0802b500: .4byte 0x03000738
lbl_0802b504:
    ldrh r0, [r6, #4]
    subs r0, #0x40
lbl_0802b508:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r4, r6, #0
    ldrh r0, [r4, #2]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802b534 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802b538
    ldrh r0, [r4, #2]
    adds r0, #0x10
    strh r0, [r4, #2]
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #2
    bls lbl_0802b620
    subs r0, #1
    strb r0, [r1]
    b lbl_0802b620
    .align 2, 0
lbl_0802b534: .4byte 0x030007f0
lbl_0802b538:
    strh r1, [r4, #2]
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0802b548
    subs r0, #1
    strb r0, [r1]
lbl_0802b548:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0x81
    bne lbl_0802b552
    ldrb r0, [r1]
    b lbl_0802b596
lbl_0802b552:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b564
    ldrh r0, [r4, #4]
    adds r0, #0x60
    b lbl_0802b568
lbl_0802b564:
    ldrh r0, [r6, #4]
    subs r0, #0x60
lbl_0802b568:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r4, lbl_0802b58c @ =0x03000738
    ldrh r0, [r4, #2]
    subs r0, #0x20
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0
    bne lbl_0802b590
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0x63
    bhi lbl_0802b5a0
    b lbl_0802b59a
    .align 2, 0
lbl_0802b58c: .4byte 0x03000738
lbl_0802b590:
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r0, [r0]
lbl_0802b596:
    cmp r0, #0
    bne lbl_0802b5a0
lbl_0802b59a:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_0802b5a0:
    cmp r5, #0
    beq lbl_0802b620
    ldr r4, lbl_0802b600 @ =0x03000738
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x54
    bne lbl_0802b5bc
    movs r0, #0xc0
    lsls r0, r0, #1
    movs r1, #0xa0
    lsls r1, r1, #2
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    beq lbl_0802b620
lbl_0802b5bc:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    adds r1, #8
    movs r0, #0xa
    strb r0, [r1]
    cmp r7, #0
    beq lbl_0802b620
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0802b604
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0x50
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0x40
    str r0, [sp, #8]
    movs r0, #0x16
    movs r1, #0x80
    bl SpriteSpawnSecondary
    b lbl_0802b620
    .align 2, 0
lbl_0802b600: .4byte 0x03000738
lbl_0802b604:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0x50
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0x16
    movs r1, #0x80
    bl SpriteSpawnSecondary
lbl_0802b620:
    add sp, #0xc
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start SpacePirateShootingAfterWaitingAtDoor
SpacePirateShootingAfterWaitingAtDoor: @ 0x0802b628
    push {r4, lr}
    ldr r2, lbl_0802b674 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    adds r1, #6
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    adds r4, r2, #0
    cmp r0, #0
    bne lbl_0802b6bc
    ldrh r1, [r4]
    ldr r0, lbl_0802b678 @ =0x00007ffb
    ands r0, r1
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x20
    strb r0, [r1]
    subs r1, #9
    movs r0, #0x14
    strb r0, [r1]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0x81
    bne lbl_0802b6b4
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b67c
    ldrh r0, [r4, #4]
    adds r0, #0x40
    b lbl_0802b680
    .align 2, 0
lbl_0802b674: .4byte 0x03000738
lbl_0802b678: .4byte 0x00007ffb
lbl_0802b67c:
    ldrh r0, [r4, #4]
    subs r0, #0x40
lbl_0802b680:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r4, #2]
    subs r0, #0x60
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b6b4
    movs r2, #0
    movs r3, #0
    ldr r0, lbl_0802b6ac @ =0x0000ffc0
    strh r0, [r4, #0xa]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x51
    strb r0, [r1]
    ldr r0, lbl_0802b6b0 @ =0x082e4680
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    b lbl_0802b6bc
    .align 2, 0
lbl_0802b6ac: .4byte 0x0000ffc0
lbl_0802b6b0: .4byte 0x082e4680
lbl_0802b6b4:
    ldr r0, lbl_0802b6c4 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x23
    strb r1, [r0]
lbl_0802b6bc:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802b6c4: .4byte 0x03000738

    thumb_func_start SpacePirateClimbingUpInit
SpacePirateClimbingUpInit: @ 0x0802b6c8
    ldr r0, lbl_0802b6fc @ =0x03000738
    mov ip, r0
    mov r1, ip
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x49
    strb r0, [r1]
    ldr r0, lbl_0802b700 @ =0x082e45c0
    mov r1, ip
    str r0, [r1, #0x18]
    strb r2, [r1, #0x1c]
    movs r3, #0
    strh r2, [r1, #0x16]
    ldrh r1, [r1, #4]
    ldr r0, lbl_0802b704 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x20
    mov r1, ip
    strh r0, [r1, #4]
    adds r1, #0x2c
    movs r0, #1
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2d
    strb r3, [r0]
    bx lr
    .align 2, 0
lbl_0802b6fc: .4byte 0x03000738
lbl_0802b700: .4byte 0x082e45c0
lbl_0802b704: .4byte 0x0000ffc0

    thumb_func_start SpacePirateClimbingUp
SpacePirateClimbingUp: @ 0x0802b708
    push {r4, r5, r6, lr}
    movs r4, #0
    bl sub_08029d70
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802b718
    b lbl_0802b8f6
lbl_0802b718:
    ldr r2, lbl_0802b750 @ =0x03000738
    ldrh r5, [r2, #2]
    ldrh r6, [r2, #4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b730
    adds r0, r2, #0
    adds r0, #0x2d
    strb r4, [r0]
lbl_0802b730:
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r1, [r3]
    cmp r1, #1
    bls lbl_0802b754
    ldrh r0, [r2, #0x16]
    cmp r0, #0
    beq lbl_0802b742
    b lbl_0802b8f6
lbl_0802b742:
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
    subs r0, r1, #1
    strb r0, [r3]
    b lbl_0802b8f6
    .align 2, 0
lbl_0802b750: .4byte 0x03000738
lbl_0802b754:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b76a
    adds r0, r5, #0
    subs r0, #0xa8
    adds r1, r6, #0
    adds r1, #0x30
    b lbl_0802b772
lbl_0802b76a:
    adds r0, r5, #0
    subs r0, #0xa8
    adds r1, r6, #0
    subs r1, #0x30
lbl_0802b772:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0802b820
    ldr r0, lbl_0802b798 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b79c
    adds r0, r5, #0
    subs r0, #0x20
    adds r1, r6, #0
    adds r1, #0x30
    b lbl_0802b7a4
    .align 2, 0
lbl_0802b798: .4byte 0x03000738
lbl_0802b79c:
    adds r0, r5, #0
    subs r0, #0x20
    adds r1, r6, #0
    subs r1, #0x30
lbl_0802b7a4:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    beq lbl_0802b858
    ldr r2, lbl_0802b7d0 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802b7d4
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0802b7d4
    movs r0, #0x28
    strb r0, [r1]
    b lbl_0802b820
    .align 2, 0
lbl_0802b7d0: .4byte 0x03000738
lbl_0802b7d4:
    ldr r0, lbl_0802b7ec @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b7f0
    adds r0, r5, #0
    subs r0, #0x60
    adds r1, r6, #0
    adds r1, #0x30
    b lbl_0802b7f8
    .align 2, 0
lbl_0802b7ec: .4byte 0x03000738
lbl_0802b7f0:
    adds r0, r5, #0
    subs r0, #0x60
    adds r1, r6, #0
    subs r1, #0x30
lbl_0802b7f8:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0802b820
    ldr r2, lbl_0802b81c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2d
    movs r0, #1
    strb r0, [r1]
    subs r1, #9
    movs r0, #0x42
    strb r0, [r1]
    ldrh r0, [r2, #2]
    subs r0, #0x20
    strh r0, [r2, #2]
    b lbl_0802b8f6
    .align 2, 0
lbl_0802b81c: .4byte 0x03000738
lbl_0802b820:
    adds r0, r5, #0
    subs r0, #0xc0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    adds r4, r0, #0
    cmp r4, #0
    beq lbl_0802b84c
    ldr r3, lbl_0802b848 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x12
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    subs r0, #1
    strb r2, [r0]
    b lbl_0802b8f6
    .align 2, 0
lbl_0802b848: .4byte 0x03000738
lbl_0802b84c:
    movs r0, #0
    bl sub_08029940
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802b874
lbl_0802b858:
    ldr r2, lbl_0802b870 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x12
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x2d
    strb r4, [r0]
    adds r1, #8
    movs r0, #1
    strb r0, [r1]
    b lbl_0802b8f6
    .align 2, 0
lbl_0802b870: .4byte 0x03000738
lbl_0802b874:
    ldr r2, lbl_0802b88c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b890
    movs r1, #8
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
    b lbl_0802b8ce
    .align 2, 0
lbl_0802b88c: .4byte 0x03000738
lbl_0802b890:
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0802b8c8
    ldr r0, lbl_0802b8c0 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0802b8cc
    ldr r0, lbl_0802b8c4 @ =0x03000c77
    ldrb r1, [r0]
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    lsls r0, r0, #3
    cmp r1, r0
    bge lbl_0802b8cc
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x18
    strb r0, [r1]
    b lbl_0802b8f6
    .align 2, 0
lbl_0802b8c0: .4byte 0x0300083c
lbl_0802b8c4: .4byte 0x03000c77
lbl_0802b8c8:
    adds r0, #1
    strb r0, [r1]
lbl_0802b8cc:
    movs r1, #4
lbl_0802b8ce:
    ldrh r0, [r2, #2]
    subs r0, r0, r1
    strh r0, [r2, #2]
    ldrb r0, [r2, #0x1c]
    cmp r0, #9
    bls lbl_0802b8f6
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802b8f6
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b8f6
    movs r0, #0xb6
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0802b8f6:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start SpacePirateClimbingDownInit
SpacePirateClimbingDownInit: @ 0x0802b8fc
    ldr r1, lbl_0802b924 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x5f
    strb r0, [r2]
    ldr r0, lbl_0802b928 @ =0x082e4608
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    ldrh r2, [r1, #4]
    ldr r0, lbl_0802b92c @ =0x0000ffc0
    ands r0, r2
    adds r0, #0x20
    strh r0, [r1, #4]
    adds r1, #0x2c
    movs r0, #1
    strb r0, [r1]
    bx lr
    .align 2, 0
lbl_0802b924: .4byte 0x03000738
lbl_0802b928: .4byte 0x082e4608
lbl_0802b92c: .4byte 0x0000ffc0

    thumb_func_start SpacePirateClimbingDown
SpacePirateClimbingDown: @ 0x0802b930
    push {r4, r5, r6, r7, lr}
    movs r5, #0
    bl sub_08029d70
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802b940
    b lbl_0802ba76
lbl_0802b940:
    ldr r4, lbl_0802b958 @ =0x03000738
    ldrh r6, [r4, #2]
    ldrh r7, [r4, #4]
    adds r0, r6, #0
    adds r0, #0x3c
    adds r1, r7, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802b95c
    adds r0, r4, #0
    b lbl_0802b9b4
    .align 2, 0
lbl_0802b958: .4byte 0x03000738
lbl_0802b95c:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b96e
    adds r1, r7, #0
    adds r1, #0x30
    b lbl_0802b972
lbl_0802b96e:
    adds r1, r7, #0
    subs r1, #0x30
lbl_0802b972:
    adds r0, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_0802b9c8
    ldr r0, lbl_0802b998 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802b99c
    adds r0, r6, #0
    adds r0, #0x48
    adds r1, r7, #0
    adds r1, #0x30
    b lbl_0802b9a4
    .align 2, 0
lbl_0802b998: .4byte 0x03000738
lbl_0802b99c:
    adds r0, r6, #0
    adds r0, #0x48
    adds r1, r7, #0
    subs r1, #0x30
lbl_0802b9a4:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_0802b9c8
    ldr r2, lbl_0802b9c4 @ =0x03000738
    adds r0, r2, #0
lbl_0802b9b4:
    adds r0, #0x24
    movs r1, #0x12
    strb r1, [r0]
    adds r0, #9
    strb r5, [r0]
    subs r0, #1
    strb r5, [r0]
    b lbl_0802ba76
    .align 2, 0
lbl_0802b9c4: .4byte 0x03000738
lbl_0802b9c8:
    movs r0, #1
    bl sub_08029940
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802b9f4
    ldr r3, lbl_0802b9f0 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x12
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #8
    movs r0, #1
    strb r0, [r1]
    b lbl_0802ba76
    .align 2, 0
lbl_0802b9f0: .4byte 0x03000738
lbl_0802b9f4:
    ldr r2, lbl_0802ba0c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ba10
    movs r1, #8
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
    b lbl_0802ba4e
    .align 2, 0
lbl_0802ba0c: .4byte 0x03000738
lbl_0802ba10:
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0802ba48
    ldr r0, lbl_0802ba40 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ba4c
    ldr r0, lbl_0802ba44 @ =0x03000c77
    ldrb r1, [r0]
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    lsls r0, r0, #3
    cmp r1, r0
    ble lbl_0802ba4c
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x18
    strb r0, [r1]
    b lbl_0802ba76
    .align 2, 0
lbl_0802ba40: .4byte 0x0300083c
lbl_0802ba44: .4byte 0x03000c77
lbl_0802ba48:
    adds r0, #1
    strb r0, [r1]
lbl_0802ba4c:
    movs r1, #4
lbl_0802ba4e:
    ldrh r0, [r2, #2]
    adds r0, r1, r0
    strh r0, [r2, #2]
    ldrb r0, [r2, #0x1c]
    cmp r0, #9
    bls lbl_0802ba76
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802ba76
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ba76
    movs r0, #0xb6
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0802ba76:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start unk_2ba7c
unk_2ba7c: @ 0x0802ba7c
    ldr r3, lbl_0802ba94 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x19
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r0, #2
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802ba94: .4byte 0x03000738

    thumb_func_start unk_2ba98
unk_2ba98: @ 0x0802ba98
    push {r4, r5, r6, r7, lr}
    movs r7, #0
    movs r6, #0
    ldr r2, lbl_0802bac8 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bab2
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
lbl_0802bab2:
    ldrh r4, [r2, #2]
    ldrh r5, [r2, #4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bacc
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802bad0
    .align 2, 0
lbl_0802bac8: .4byte 0x03000738
lbl_0802bacc:
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802bad0:
    adds r0, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0802bb28
    ldr r0, lbl_0802baf8 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bafc
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802bb04
    .align 2, 0
lbl_0802baf8: .4byte 0x03000738
lbl_0802bafc:
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802bb04:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0802bb28
    ldr r3, lbl_0802bb24 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x12
    strb r1, [r0]
    adds r0, #9
    strb r2, [r0]
    subs r0, #1
    strb r2, [r0]
    b lbl_0802bc4e
    .align 2, 0
lbl_0802bb24: .4byte 0x03000738
lbl_0802bb28:
    ldr r0, lbl_0802bb40 @ =0x03000738
    adds r4, r0, #0
    adds r4, #0x2d
    ldrb r2, [r4]
    adds r5, r0, #0
    cmp r2, #2
    beq lbl_0802bb6c
    cmp r2, #2
    bgt lbl_0802bb44
    cmp r2, #1
    beq lbl_0802bb4a
    b lbl_0802bc3c
    .align 2, 0
lbl_0802bb40: .4byte 0x03000738
lbl_0802bb44:
    cmp r2, #3
    beq lbl_0802bc28
    b lbl_0802bc3c
lbl_0802bb4a:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0802bb54
    b lbl_0802bc4e
lbl_0802bb54:
    ldr r0, lbl_0802bb68 @ =0x082e47a0
    str r0, [r5, #0x18]
    movs r0, #0
    strb r0, [r5, #0x1c]
    strh r0, [r5, #0x16]
    ldrb r0, [r4]
    adds r0, #1
    strb r0, [r4]
    b lbl_0802bc4e
    .align 2, 0
lbl_0802bb68: .4byte 0x082e47a0
lbl_0802bb6c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bc4e
    bl sub_08029d70
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0x38
    bne lbl_0802bb88
    adds r0, r5, #0
    adds r0, #0x24
    strb r4, [r0]
    b lbl_0802bc4e
lbl_0802bb88:
    cmp r4, #0
    bne lbl_0802bbb8
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bba8
    ldr r0, lbl_0802bba4 @ =0x030007f3
    ldrb r0, [r0, #3]
    movs r4, #0x48
    cmp r0, #1
    bne lbl_0802bbb8
    b lbl_0802bbb6
    .align 2, 0
lbl_0802bba4: .4byte 0x030007f3
lbl_0802bba8:
    ldr r0, lbl_0802bbec @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    movs r4, #0x48
    cmp r0, #0
    beq lbl_0802bbb8
lbl_0802bbb6:
    movs r4, #0x5e
lbl_0802bbb8:
    cmp r4, #0x5e
    bne lbl_0802bbc2
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_0802bbc2:
    adds r0, r6, #0
    bl sub_08029940
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802bbf8
    ldr r0, lbl_0802bbf0 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x4b
    strb r1, [r2]
    ldr r1, lbl_0802bbf4 @ =0x082e4830
    str r1, [r0, #0x18]
    strb r3, [r0, #0x1c]
    movs r1, #0
    strh r3, [r0, #0x16]
    adds r0, #0x2d
    strb r1, [r0]
    b lbl_0802bbfe
    .align 2, 0
lbl_0802bbec: .4byte 0x0300083c
lbl_0802bbf0: .4byte 0x03000738
lbl_0802bbf4: .4byte 0x082e4830
lbl_0802bbf8:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802bbfe:
    cmp r7, #0
    beq lbl_0802bc4e
    ldr r2, lbl_0802bc20 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    adds r0, #1
    movs r1, #0
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x2c
    strb r4, [r0]
    ldr r0, lbl_0802bc24 @ =0x082e4808
    str r0, [r2, #0x18]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    b lbl_0802bc4e
    .align 2, 0
lbl_0802bc20: .4byte 0x03000738
lbl_0802bc24: .4byte 0x082e4808
lbl_0802bc28:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bc4e
    adds r0, r5, #0
    adds r0, #0x2c
    ldrb r1, [r0]
    subs r0, #8
    strb r1, [r0]
    b lbl_0802bc4e
lbl_0802bc3c:
    ldr r0, lbl_0802bc54 @ =0x082e4780
    str r0, [r5, #0x18]
    movs r0, #0
    strb r0, [r5, #0x1c]
    strh r0, [r5, #0x16]
    adds r1, r5, #0
    adds r1, #0x2d
    movs r0, #1
    strb r0, [r1]
lbl_0802bc4e:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bc54: .4byte 0x082e4780

    thumb_func_start SpacePirateClimbingChargingLaserInit
SpacePirateClimbingChargingLaserInit: @ 0x0802bc58
    ldr r1, lbl_0802bc70 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x39
    strb r0, [r2]
    ldr r0, lbl_0802bc74 @ =0x082e47c8
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802bc70: .4byte 0x03000738
lbl_0802bc74: .4byte 0x082e47c8

    thumb_func_start SpacePirateClimbingChargingLaser
SpacePirateClimbingChargingLaser: @ 0x0802bc78
    push {lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bc8a
    ldr r0, lbl_0802bc90 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x3a
    strb r1, [r0]
lbl_0802bc8a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bc90: .4byte 0x03000738

    thumb_func_start SpacePirateClimbingShootingLaserInit
SpacePirateClimbingShootingLaserInit: @ 0x0802bc94
    ldr r1, lbl_0802bcb4 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x3b
    strb r0, [r2]
    ldr r0, lbl_0802bcb8 @ =0x082e47e0
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    bx lr
    .align 2, 0
lbl_0802bcb4: .4byte 0x03000738
lbl_0802bcb8: .4byte 0x082e47e0

    thumb_func_start SpacePirateClimbingShootingLaser
SpacePirateClimbingShootingLaser: @ 0x0802bcbc
    push {r4, r5, lr}
    ldr r0, lbl_0802bcd8 @ =0x03000738
    ldrh r4, [r0, #2]
    ldrh r5, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bcdc
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802bce0
    .align 2, 0
lbl_0802bcd8: .4byte 0x03000738
lbl_0802bcdc:
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802bce0:
    adds r0, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0802bd38
    ldr r0, lbl_0802bd08 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bd0c
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802bd14
    .align 2, 0
lbl_0802bd08: .4byte 0x03000738
lbl_0802bd0c:
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802bd14:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0802bd38
    ldr r3, lbl_0802bd34 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x12
    strb r1, [r0]
    adds r0, #9
    strb r2, [r0]
    subs r0, #1
    strb r2, [r0]
    b lbl_0802bd6c
    .align 2, 0
lbl_0802bd34: .4byte 0x03000738
lbl_0802bd38:
    ldr r1, lbl_0802bd74 @ =0x03000738
    ldrh r0, [r1, #0x16]
    cmp r0, #2
    bne lbl_0802bd4a
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0802bd4a
    bl SpacePirateFireLaserWall
lbl_0802bd4a:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bd6c
    ldr r0, lbl_0802bd74 @ =0x03000738
    ldr r1, lbl_0802bd78 @ =0x082e47a0
    str r1, [r0, #0x18]
    movs r1, #0
    strb r1, [r0, #0x1c]
    strh r1, [r0, #0x16]
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x19
    strb r1, [r2]
    adds r0, #0x2d
    movs r1, #2
    strb r1, [r0]
lbl_0802bd6c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bd74: .4byte 0x03000738
lbl_0802bd78: .4byte 0x082e47a0

    thumb_func_start SpacePirateTurningAroundToWallJumpInit
SpacePirateTurningAroundToWallJumpInit: @ 0x0802bd7c
    ldr r1, lbl_0802bd94 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x13
    strb r0, [r2]
    ldr r0, lbl_0802bd98 @ =0x082e4780
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802bd94: .4byte 0x03000738
lbl_0802bd98: .4byte 0x082e4780

    thumb_func_start SpacePirateTurningAroundToWallJump
SpacePirateTurningAroundToWallJump: @ 0x0802bd9c
    push {r4, r5, lr}
    ldr r4, lbl_0802bdbc @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r5, [r0]
    cmp r5, #0
    beq lbl_0802bdc0
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bdd8
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x4a
    strb r0, [r1]
    b lbl_0802bdd8
    .align 2, 0
lbl_0802bdbc: .4byte 0x03000738
lbl_0802bdc0:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bdd8
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x15
    strb r1, [r0]
    ldr r0, lbl_0802bde0 @ =0x082e47a0
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
lbl_0802bdd8:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bde0: .4byte 0x082e47a0

    thumb_func_start SpacePirateDelayBeforeLaunchingFromWall
SpacePirateDelayBeforeLaunchingFromWall: @ 0x0802bde4
    push {r4, r5, lr}
    ldr r0, lbl_0802be00 @ =0x03000738
    ldrh r4, [r0, #2]
    ldrh r5, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802be04
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802be08
    .align 2, 0
lbl_0802be00: .4byte 0x03000738
lbl_0802be04:
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802be08:
    adds r0, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802be48
    ldr r0, lbl_0802be30 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802be34
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    adds r1, #0x30
    b lbl_0802be3c
    .align 2, 0
lbl_0802be30: .4byte 0x03000738
lbl_0802be34:
    adds r0, r4, #0
    adds r0, #0x48
    adds r1, r5, #0
    subs r1, #0x30
lbl_0802be3c:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802be50
lbl_0802be48:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802be58
lbl_0802be50:
    ldr r0, lbl_0802be60 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x4a
    strb r1, [r0]
lbl_0802be58:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802be60: .4byte 0x03000738

    thumb_func_start SpacePirateLaunchingFromWallInit
SpacePirateLaunchingFromWallInit: @ 0x0802be64
    ldr r1, lbl_0802be7c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x4b
    strb r0, [r2]
    ldr r0, lbl_0802be80 @ =0x082e4830
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802be7c: .4byte 0x03000738
lbl_0802be80: .4byte 0x082e4830

    thumb_func_start SpacePirateLaunchingFromWall
SpacePirateLaunchingFromWall: @ 0x0802be84
    push {lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bec2
    ldr r3, lbl_0802bec8 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x4d
    strb r0, [r1]
    ldr r0, lbl_0802becc @ =0x082e4850
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    movs r1, #0
    strh r2, [r3, #0x16]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r1, [r0]
    adds r0, #3
    strb r1, [r0]
    ldrh r1, [r3]
    ldr r0, lbl_0802bed0 @ =0x0000bfff
    ands r0, r1
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    eors r0, r1
    strh r0, [r3]
    bl SpacePirateFlip
lbl_0802bec2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bec8: .4byte 0x03000738
lbl_0802becc: .4byte 0x082e4850
lbl_0802bed0: .4byte 0x0000bfff

    thumb_func_start SpacePirateStartingToCrawlInit
SpacePirateStartingToCrawlInit: @ 0x0802bed4
    ldr r1, lbl_0802beec @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x4f
    strb r0, [r2]
    ldr r0, lbl_0802bef0 @ =0x082e4650
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802beec: .4byte 0x03000738
lbl_0802bef0: .4byte 0x082e4650

    thumb_func_start SpacePirateStartingToCrawl
SpacePirateStartingToCrawl: @ 0x0802bef4
    push {lr}
    ldr r2, lbl_0802bf04 @ =0x03000738
    ldrh r0, [r2, #0x16]
    cmp r0, #1
    bne lbl_0802bf0c
    ldr r0, lbl_0802bf08 @ =0x0000ff80
    strh r0, [r2, #0xa]
    b lbl_0802bf62
    .align 2, 0
lbl_0802bf04: .4byte 0x03000738
lbl_0802bf08: .4byte 0x0000ff80
lbl_0802bf0c:
    cmp r0, #2
    bne lbl_0802bf1c
    ldr r0, lbl_0802bf18 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    b lbl_0802bf62
    .align 2, 0
lbl_0802bf18: .4byte 0x0000ffa0
lbl_0802bf1c:
    cmp r0, #2
    bls lbl_0802bf62
    ldrb r0, [r2, #0x1c]
    cmp r0, #1
    bne lbl_0802bf46
    ldr r0, lbl_0802bf3c @ =0x0000ffc0
    strh r0, [r2, #0xa]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bf40
    ldrh r0, [r2, #4]
    adds r0, #0x20
    b lbl_0802bf44
    .align 2, 0
lbl_0802bf3c: .4byte 0x0000ffc0
lbl_0802bf40:
    ldrh r0, [r2, #4]
    subs r0, #0x20
lbl_0802bf44:
    strh r0, [r2, #4]
lbl_0802bf46:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802bf62
    ldr r1, lbl_0802bf68 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x51
    strb r0, [r2]
    ldr r0, lbl_0802bf6c @ =0x082e4680
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
lbl_0802bf62:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802bf68: .4byte 0x03000738
lbl_0802bf6c: .4byte 0x082e4680

    thumb_func_start SpacePirateCrawling
SpacePirateCrawling: @ 0x0802bf70
    push {r4, r5, r6, r7, lr}
    bl sub_08029c94
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802bf7e
    b lbl_0802c09a
lbl_0802bf7e:
    ldr r0, lbl_0802bf9c @ =0x03000738
    ldrh r5, [r0, #2]
    ldrh r6, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bfa0
    adds r0, r5, #0
    subs r0, #0x20
    adds r1, r6, #0
    adds r1, #0x50
    b lbl_0802bfa8
    .align 2, 0
lbl_0802bf9c: .4byte 0x03000738
lbl_0802bfa0:
    adds r0, r5, #0
    subs r0, #0x20
    adds r1, r6, #0
    subs r1, #0x50
lbl_0802bfa8:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802bfc4
    ldr r0, lbl_0802bfc0 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x58
    strb r1, [r0]
    b lbl_0802c09a
    .align 2, 0
lbl_0802bfc0: .4byte 0x03000738
lbl_0802bfc4:
    ldr r7, lbl_0802bff0 @ =0x03000738
    ldrh r1, [r7]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802bff4
    adds r4, r6, #0
    adds r4, #0x54
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802c01a
    adds r0, r5, #0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802c010
    b lbl_0802c01a
    .align 2, 0
lbl_0802bff0: .4byte 0x03000738
lbl_0802bff4:
    adds r4, r6, #0
    subs r4, #0x54
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802c01a
    adds r0, r5, #0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802c01a
lbl_0802c010:
    adds r1, r7, #0
    adds r1, #0x24
    movs r0, #0x5a
    strb r0, [r1]
    b lbl_0802c09a
lbl_0802c01a:
    subs r5, #0x60
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802c044
    adds r0, r5, #0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802c044
    ldr r0, lbl_0802c040 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x56
    strb r1, [r0]
    b lbl_0802c09a
    .align 2, 0
lbl_0802c040: .4byte 0x03000738
lbl_0802c044:
    ldr r2, lbl_0802c05c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c060
    movs r3, #4
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
    b lbl_0802c062
    .align 2, 0
lbl_0802c05c: .4byte 0x03000738
lbl_0802c060:
    movs r3, #1
lbl_0802c062:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c074
    ldrh r0, [r2, #4]
    adds r0, r3, r0
    b lbl_0802c078
lbl_0802c074:
    ldrh r0, [r2, #4]
    subs r0, r0, r3
lbl_0802c078:
    strh r0, [r2, #4]
    ldrb r0, [r2, #0x1c]
    cmp r0, #9
    bls lbl_0802c09a
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802c09a
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c09a
    ldr r0, lbl_0802c0a0 @ =0x0000016b
    bl SoundPlayNotAlreadyPlaying
lbl_0802c09a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c0a0: .4byte 0x0000016b

    thumb_func_start SpacePirateTurningAroundWhileCrawlingInit
SpacePirateTurningAroundWhileCrawlingInit: @ 0x0802c0a4
    ldr r1, lbl_0802c0bc @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x53
    strb r0, [r2]
    ldr r0, lbl_0802c0c0 @ =0x082e46f8
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802c0bc: .4byte 0x03000738
lbl_0802c0c0: .4byte 0x082e46f8

    thumb_func_start SpacePirateTurningWhileCrawlingFirstPart
SpacePirateTurningWhileCrawlingFirstPart: @ 0x0802c0c4
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802c0f2
    ldr r2, lbl_0802c0f8 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r3, #0
    movs r0, #0x55
    strb r0, [r1]
    ldr r0, lbl_0802c0fc @ =0x082e4728
    str r0, [r2, #0x18]
    strb r3, [r2, #0x1c]
    strh r3, [r2, #0x16]
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    bl SpacePirateFlip
lbl_0802c0f2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c0f8: .4byte 0x03000738
lbl_0802c0fc: .4byte 0x082e4728

    thumb_func_start SpacePirateTurningWhileCrawlingSecondPart
SpacePirateTurningWhileCrawlingSecondPart: @ 0x0802c100
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802c11e
    ldr r1, lbl_0802c124 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x51
    strb r0, [r2]
    ldr r0, lbl_0802c128 @ =0x082e4680
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
lbl_0802c11e:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c124: .4byte 0x03000738
lbl_0802c128: .4byte 0x082e4680

    thumb_func_start SpacePirateStandingUpInit
SpacePirateStandingUpInit: @ 0x0802c12c
    ldr r1, lbl_0802c144 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x57
    strb r0, [r2]
    ldr r0, lbl_0802c148 @ =0x082e46c8
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802c144: .4byte 0x03000738
lbl_0802c148: .4byte 0x082e46c8

    thumb_func_start SpacePirateStandingUp
SpacePirateStandingUp: @ 0x0802c14c
    push {r4, lr}
    ldr r4, lbl_0802c170 @ =0x03000738
    ldrh r0, [r4, #0x16]
    cmp r0, #2
    bne lbl_0802c178
    ldrb r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0802c1fc
    ldr r0, lbl_0802c174 @ =0x0000ffa0
    strh r0, [r4, #0xa]
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0802c192
    b lbl_0802c1a0
    .align 2, 0
lbl_0802c170: .4byte 0x03000738
lbl_0802c174: .4byte 0x0000ffa0
lbl_0802c178:
    cmp r0, #3
    bne lbl_0802c1a8
    ldrb r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0802c1fc
    ldr r0, lbl_0802c19c @ =0x0000ff80
    strh r0, [r4, #0xa]
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c1a0
lbl_0802c192:
    ldrh r0, [r4, #4]
    adds r0, #0x18
    strh r0, [r4, #4]
    b lbl_0802c1fc
    .align 2, 0
lbl_0802c19c: .4byte 0x0000ff80
lbl_0802c1a0:
    ldrh r0, [r4, #4]
    subs r0, #0x18
    strh r0, [r4, #4]
    b lbl_0802c1fc
lbl_0802c1a8:
    ldr r0, lbl_0802c1dc @ =0x0000ff60
    strh r0, [r4, #0xa]
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802c1fc
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802c1e0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c1fc
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802c1fc
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x22
    b lbl_0802c1fa
    .align 2, 0
lbl_0802c1dc: .4byte 0x0000ff60
lbl_0802c1e0:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c1f4
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x22
    b lbl_0802c1fa
lbl_0802c1f4:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
lbl_0802c1fa:
    strb r0, [r1]
lbl_0802c1fc:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirateFallingWhileCrawlingInit
SpacePirateFallingWhileCrawlingInit: @ 0x0802c204
    ldr r1, lbl_0802c21c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x5b
    strb r0, [r2]
    ldr r0, lbl_0802c220 @ =0x082e46c8
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802c21c: .4byte 0x03000738
lbl_0802c220: .4byte 0x082e46c8

    thumb_func_start SpacePirateFallingWhileCrawling
SpacePirateFallingWhileCrawling: @ 0x0802c224
    push {lr}
    ldr r0, lbl_0802c24c @ =0x03000738
    mov ip, r0
    ldrh r0, [r0, #0x16]
    cmp r0, #2
    bne lbl_0802c254
    mov r1, ip
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0802c2c0
    ldr r0, lbl_0802c250 @ =0x0000ffa0
    strh r0, [r1, #0xa]
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0802c270
    b lbl_0802c280
    .align 2, 0
lbl_0802c24c: .4byte 0x03000738
lbl_0802c250: .4byte 0x0000ffa0
lbl_0802c254:
    cmp r0, #3
    bne lbl_0802c2c0
    mov r1, ip
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0802c28a
    ldr r0, lbl_0802c27c @ =0x0000ff80
    strh r0, [r1, #0xa]
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c280
lbl_0802c270:
    mov r1, ip
    ldrh r0, [r1, #4]
    adds r0, #0x18
    strh r0, [r1, #4]
    b lbl_0802c2c0
    .align 2, 0
lbl_0802c27c: .4byte 0x0000ff80
lbl_0802c280:
    mov r1, ip
    ldrh r0, [r1, #4]
    subs r0, #0x18
    strh r0, [r1, #4]
    b lbl_0802c2c0
lbl_0802c28a:
    cmp r0, #5
    bne lbl_0802c2c0
    movs r2, #0
    movs r3, #0
    ldr r0, lbl_0802c2c4 @ =0x0000ff60
    mov r1, ip
    strh r0, [r1, #0xa]
    adds r1, #0x24
    movs r0, #0x4d
    strb r0, [r1]
    ldr r0, lbl_0802c2c8 @ =0x082e4850
    mov r1, ip
    str r0, [r1, #0x18]
    strb r2, [r1, #0x1c]
    strh r3, [r1, #0x16]
    mov r0, ip
    adds r0, #0x2c
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r0, #2
    strb r2, [r0]
    ldrh r1, [r1]
    ldr r0, lbl_0802c2cc @ =0x0000bfff
    ands r0, r1
    mov r1, ip
    strh r0, [r1]
lbl_0802c2c0:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c2c4: .4byte 0x0000ff60
lbl_0802c2c8: .4byte 0x082e4850
lbl_0802c2cc: .4byte 0x0000bfff

    thumb_func_start SpacePirateCrawlingStoppedInit
SpacePirateCrawlingStoppedInit: @ 0x0802c2d0
    ldr r1, lbl_0802c2e8 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x59
    strb r0, [r2]
    ldr r0, lbl_0802c2ec @ =0x082e4758
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    bx lr
    .align 2, 0
lbl_0802c2e8: .4byte 0x03000738
lbl_0802c2ec: .4byte 0x082e4758

    thumb_func_start SpacePirateCrawlingStopped
SpacePirateCrawlingStopped: @ 0x0802c2f0
    push {lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802c302
    ldr r0, lbl_0802c308 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x52
    strb r1, [r0]
lbl_0802c302:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c308: .4byte 0x03000738

    thumb_func_start SpacePirateDeath
SpacePirateDeath: @ 0x0802c30c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802c32a
    ldr r0, lbl_0802c394 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c32a
    movs r0, #0xb5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0802c32a:
    ldr r0, lbl_0802c394 @ =0x03000738
    ldrh r1, [r0, #2]
    subs r1, #0x60
    ldrh r2, [r0, #4]
    movs r0, #0x22
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    ldr r0, lbl_0802c398 @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_0802c38a
    movs r4, #0
    movs r7, #0x14
    ldr r2, lbl_0802c39c @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0802c382
    movs r6, #1
    adds r3, r2, #0
    adds r3, #0x24
    adds r5, r0, #0
lbl_0802c35e:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c37a
    ldrb r0, [r3, #1]
    cmp r0, r7
    bne lbl_0802c37a
    ldrb r0, [r3]
    cmp r0, #0x61
    bhi lbl_0802c37a
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0802c37a:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r5
    blo lbl_0802c35e
lbl_0802c382:
    cmp r4, #0
    bne lbl_0802c38a
    bl DisableChozodiaAlarm
lbl_0802c38a:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c394: .4byte 0x03000738
lbl_0802c398: .4byte 0x030001a8
lbl_0802c39c: .4byte 0x030001ac

    thumb_func_start SpacePirateHitByLaserInit
SpacePirateHitByLaserInit: @ 0x0802c3a0
    push {r4, lr}
    ldr r4, lbl_0802c3e4 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c3b6
    movs r0, #0xb5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0802c3b6:
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x6c
    strb r0, [r1]
    movs r3, #0
    strh r2, [r4, #0x14]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x25
    strb r3, [r0]
    adds r1, r4, #0
    adds r1, #0x2c
    movs r0, #0x21
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c3e4: .4byte 0x03000738

    thumb_func_start SpacePirateHitByLaser
SpacePirateHitByLaser: @ 0x0802c3e8
    push {lr}
    ldr r2, lbl_0802c430 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
    adds r1, #6
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r3, r1, #0
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802c448
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c434
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xe
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    strb r1, [r0]
    b lbl_0802c448
    .align 2, 0
lbl_0802c430: .4byte 0x03000738
lbl_0802c434:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    cmp r3, #0
    bne lbl_0802c448
    movs r0, #0
    bl SpacePirateDeath
lbl_0802c448:
    pop {r0}
    bx r0

    thumb_func_start SpacePirateLaserInit
SpacePirateLaserInit: @ 0x0802c44c
    push {r4, r5, r6, lr}
    ldr r2, lbl_0802c4c4 @ =0x03000738
    ldrh r0, [r2]
    ldr r3, lbl_0802c4c8 @ =0x0000fffb
    ands r3, r0
    movs r4, #0
    movs r6, #0
    movs r1, #0x80
    lsls r1, r1, #8
    adds r0, r1, #0
    orrs r3, r0
    orrs r3, r4
    strh r3, [r2]
    movs r0, #0x25
    adds r0, r0, r2
    mov ip, r0
    movs r0, #0x13
    mov r1, ip
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0802c4cc @ =0x0000fff4
    strh r1, [r2, #0xa]
    movs r0, #0xc
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
    strh r0, [r2, #0x10]
    strb r4, [r2, #0x1c]
    strh r6, [r2, #0x16]
    adds r5, r2, #0
    adds r5, #0x2c
    movs r0, #0x3c
    strb r0, [r5]
    adds r0, r2, #0
    adds r0, #0x2f
    strb r4, [r0]
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #0xa
    strb r0, [r1]
    subs r1, #0xa
    movs r0, #9
    strb r0, [r1]
    subs r1, #2
    movs r0, #3
    strb r0, [r1]
    ldrb r0, [r2, #0x1e]
    adds r1, r0, #0
    cmp r0, #0
    bne lbl_0802c4d4
    ldr r0, lbl_0802c4d0 @ =0x082e43a8
    str r0, [r2, #0x18]
    b lbl_0802c528
    .align 2, 0
lbl_0802c4c4: .4byte 0x03000738
lbl_0802c4c8: .4byte 0x0000fffb
lbl_0802c4cc: .4byte 0x0000fff4
lbl_0802c4d0: .4byte 0x082e43a8
lbl_0802c4d4:
    cmp r0, #1
    bne lbl_0802c4e4
    ldr r0, lbl_0802c4e0 @ =0x082e4870
    str r0, [r2, #0x18]
    b lbl_0802c528
    .align 2, 0
lbl_0802c4e0: .4byte 0x082e4870
lbl_0802c4e4:
    cmp r0, #2
    bne lbl_0802c500
    ldr r0, lbl_0802c4fc @ =0x082e4870
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
    b lbl_0802c528
    .align 2, 0
lbl_0802c4fc: .4byte 0x082e4870
lbl_0802c500:
    cmp r1, #0x80
    bne lbl_0802c524
    movs r1, #4
    orrs r3, r1
    strh r3, [r2]
    ldr r0, lbl_0802c520 @ =0x082e43a8
    str r0, [r2, #0x18]
    mov r0, ip
    strb r4, [r0]
    strb r1, [r5]
    movs r1, #5
    adds r0, r2, #0
    adds r0, #0x26
    strb r1, [r0]
    b lbl_0802c53a
    .align 2, 0
lbl_0802c520: .4byte 0x082e43a8
lbl_0802c524:
    strh r6, [r2]
    b lbl_0802c53a
lbl_0802c528:
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c53a
    movs r0, #0xb4
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0802c53a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start SpacePirateLaserExplodingInit
SpacePirateLaserExplodingInit: @ 0x0802c540
    push {lr}
    ldr r2, lbl_0802c558 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_0802c55c
    strh r0, [r2]
    b lbl_0802c590
    .align 2, 0
lbl_0802c558: .4byte 0x03000738
lbl_0802c55c:
    ldr r0, lbl_0802c594 @ =0x082e4908
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    movs r1, #0
    strh r0, [r2, #0x16]
    adds r0, r2, #0
    adds r0, #0x25
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
    adds r1, #2
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0802c598 @ =0x03000088
    ldrb r1, [r0, #0xc]
    movs r0, #3
    ands r0, r1
    adds r1, r2, #0
    adds r1, #0x21
    strb r0, [r1]
    ldr r0, lbl_0802c59c @ =0x0000025f
    bl SoundPlayNotAlreadyPlaying
lbl_0802c590:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c594: .4byte 0x082e4908
lbl_0802c598: .4byte 0x03000088
lbl_0802c59c: .4byte 0x0000025f

    thumb_func_start SpacePirateLaserCheckExplodingAnimEnded
SpacePirateLaserCheckExplodingAnimEnded: @ 0x0802c5a0
    push {r4, lr}
    ldr r4, lbl_0802c5c0 @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802c5b8
    movs r0, #0
    strh r0, [r4]
lbl_0802c5b8:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802c5c0: .4byte 0x03000738

    thumb_func_start SpacePirateLaserMove
SpacePirateLaserMove: @ 0x0802c5c4
    push {r4, r5, lr}
    ldr r0, lbl_0802c5f4 @ =0x03000738
    adds r1, r0, #0
    adds r1, #0x2e
    ldrb r2, [r1]
    adds r4, r0, #0
    cmp r2, #0
    beq lbl_0802c5d8
    subs r0, r2, #1
    strb r0, [r1]
lbl_0802c5d8:
    ldrb r0, [r4, #0x1e]
    cmp r0, #1
    beq lbl_0802c5f8
    cmp r0, #2
    beq lbl_0802c614
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c630
    ldrh r0, [r4, #4]
    adds r0, #0x14
    b lbl_0802c634
    .align 2, 0
lbl_0802c5f4: .4byte 0x03000738
lbl_0802c5f8:
    ldrh r0, [r4, #2]
    subs r0, #0xf
    strh r0, [r4, #2]
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c60e
    ldrh r0, [r4, #4]
    adds r0, #0xf
    b lbl_0802c634
lbl_0802c60e:
    ldrh r0, [r4, #4]
    subs r0, #0xf
    b lbl_0802c634
lbl_0802c614:
    ldrh r0, [r4, #2]
    adds r0, #0xf
    strh r0, [r4, #2]
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c62a
    ldrh r0, [r4, #4]
    adds r0, #0xf
    b lbl_0802c634
lbl_0802c62a:
    ldrh r0, [r4, #4]
    subs r0, #0xf
    b lbl_0802c634
lbl_0802c630:
    ldrh r0, [r4, #4]
    subs r0, #0x14
lbl_0802c634:
    strh r0, [r4, #4]
    ldr r1, lbl_0802c658 @ =0x03000079
    movs r0, #8
    strb r0, [r1]
    adds r5, r4, #0
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802c662
    ldrb r0, [r5, #0x1e]
    cmp r0, #0x80
    bne lbl_0802c65c
    movs r0, #0
    strh r0, [r5]
    b lbl_0802c69c
    .align 2, 0
lbl_0802c658: .4byte 0x03000079
lbl_0802c65c:
    bl SpacePirateLaserExplodingInit
    b lbl_0802c69c
lbl_0802c662:
    ldrb r0, [r5, #0x1e]
    cmp r0, #0x80
    beq lbl_0802c688
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0802c69c
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802c69c
    strh r0, [r5]
    b lbl_0802c69c
lbl_0802c688:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802c69c
    strh r0, [r4]
lbl_0802c69c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpacePirate
SpacePirate: @ 0x0802c6a4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r4, lbl_0802c718 @ =0x03000738
    ldrh r0, [r4]
    movs r6, #0x80
    lsls r6, r6, #3
    adds r1, r6, #0
    ands r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    rsbs r1, r1, #0
    lsrs r1, r1, #0x1f
    mov r8, r1
    adds r7, r4, #0
    adds r7, #0x24
    ldrb r0, [r7]
    mov ip, r4
    cmp r0, #0x61
    bls lbl_0802c6ce
    b lbl_0802c7d4
lbl_0802c6ce:
    adds r2, r4, #0
    adds r2, #0x30
    ldrb r5, [r2]
    cmp r5, #0
    beq lbl_0802c742
    ldr r0, lbl_0802c71c @ =0x03001530
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0802c738
    ldr r0, lbl_0802c720 @ =0x03000c77
    ldrb r1, [r0]
    movs r3, #1
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802c6f2
    subs r0, r5, #1
    strb r0, [r2]
lbl_0802c6f2:
    ldrb r2, [r2]
    cmp r2, #0
    bne lbl_0802c6fe
    ldrb r0, [r4, #0x1c]
    subs r0, #1
    strb r0, [r4, #0x1c]
lbl_0802c6fe:
    cmp r2, #0x2d
    bhi lbl_0802c72e
    adds r1, r3, #0
    ands r1, r2
    cmp r1, #0
    beq lbl_0802c724
    adds r0, r4, #0
    adds r0, #0x20
    strb r3, [r0]
    adds r0, #0x14
    strb r3, [r0]
    b lbl_0802c72e
    .align 2, 0
lbl_0802c718: .4byte 0x03000738
lbl_0802c71c: .4byte 0x03001530
lbl_0802c720: .4byte 0x03000c77
lbl_0802c724:
    adds r0, r4, #0
    adds r0, #0x20
    strb r1, [r0]
    adds r0, #0x14
    strb r1, [r0]
lbl_0802c72e:
    mov r1, ip
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    b lbl_0802c73c
lbl_0802c738:
    bl SpriteUtilUpdateFreezeTimer
lbl_0802c73c:
    bl SpacePirateCheckCollidingWithLaser
    b lbl_0802cb10
lbl_0802c742:
    bl SpacePirateSamusDetection
    ldrh r2, [r4]
    adds r0, r6, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0802c7bc
    ldr r0, lbl_0802c784 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r3, r0, #0
    cmp r1, #1
    bne lbl_0802c7a6
    ldr r0, lbl_0802c788 @ =0x030001a8
    movs r5, #0xf0
    lsls r5, r5, #1
    adds r1, r5, #0
    strh r1, [r0]
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x53
    bne lbl_0802c7d0
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802c78c
    ldrb r0, [r3, #1]
    cmp r0, #1
    bne lbl_0802c7a0
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_0802c79a
    b lbl_0802c7a0
    .align 2, 0
lbl_0802c784: .4byte 0x030007f3
lbl_0802c788: .4byte 0x030001a8
lbl_0802c78c:
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_0802c7a0
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    bne lbl_0802c7a0
lbl_0802c79a:
    movs r0, #0x51
    strb r0, [r4, #0x1d]
    b lbl_0802c7d0
lbl_0802c7a0:
    movs r0, #0
    strb r0, [r3, #2]
    b lbl_0802c7d0
lbl_0802c7a6:
    ldr r0, lbl_0802c7b4 @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0802c7d0
    ldr r0, lbl_0802c7b8 @ =0x0000fbff
    ands r0, r2
    b lbl_0802c7ce
    .align 2, 0
lbl_0802c7b4: .4byte 0x030001a8
lbl_0802c7b8: .4byte 0x0000fbff
lbl_0802c7bc:
    ldr r0, lbl_0802c7ec @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_0802c7d0
    ldrb r0, [r7]
    cmp r0, #0
    beq lbl_0802c7d0
    adds r0, r6, #0
    orrs r0, r2
lbl_0802c7ce:
    strh r0, [r4]
lbl_0802c7d0:
    bl SpacePirateCheckCollidingWithLaser
lbl_0802c7d4:
    ldr r0, lbl_0802c7f0 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x6c
    bls lbl_0802c7e0
    b lbl_0802caf0
lbl_0802c7e0:
    lsls r0, r0, #2
    ldr r1, lbl_0802c7f4 @ =lbl_0802c7f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802c7ec: .4byte 0x030001a8
lbl_0802c7f0: .4byte 0x03000738
lbl_0802c7f4: .4byte lbl_0802c7f8
lbl_0802c7f8: @ jump table
    .4byte lbl_0802c9ac @ case 0
    .4byte lbl_0802caf0 @ case 1
    .4byte lbl_0802caf0 @ case 2
    .4byte lbl_0802caf0 @ case 3
    .4byte lbl_0802caf0 @ case 4
    .4byte lbl_0802caf0 @ case 5
    .4byte lbl_0802caf0 @ case 6
    .4byte lbl_0802caf0 @ case 7
    .4byte lbl_0802c9b2 @ case 8
    .4byte lbl_0802c9b8 @ case 9
    .4byte lbl_0802ca12 @ case 10
    .4byte lbl_0802ca16 @ case 11
    .4byte lbl_0802ca1c @ case 12
    .4byte lbl_0802caf0 @ case 13
    .4byte lbl_0802c9f6 @ case 14
    .4byte lbl_0802c9f0 @ case 15
    .4byte lbl_0802ca0c @ case 16
    .4byte lbl_0802ca00 @ case 17
    .4byte lbl_0802ca8c @ case 18
    .4byte lbl_0802ca90 @ case 19
    .4byte lbl_0802caf0 @ case 20
    .4byte lbl_0802ca96 @ case 21
    .4byte lbl_0802ca06 @ case 22
    .4byte lbl_0802caf0 @ case 23
    .4byte lbl_0802ca6e @ case 24
    .4byte lbl_0802ca72 @ case 25
    .4byte lbl_0802c9ec @ case 26
    .4byte lbl_0802caf0 @ case 27
    .4byte lbl_0802c9fc @ case 28
    .4byte lbl_0802caf0 @ case 29
    .4byte lbl_0802c9e2 @ case 30
    .4byte lbl_0802c9e6 @ case 31
    .4byte lbl_0802caf0 @ case 32
    .4byte lbl_0802caf0 @ case 33
    .4byte lbl_0802ca22 @ case 34
    .4byte lbl_0802ca26 @ case 35
    .4byte lbl_0802c9ca @ case 36
    .4byte lbl_0802c9d0 @ case 37
    .4byte lbl_0802caf0 @ case 38
    .4byte lbl_0802c9be @ case 39
    .4byte lbl_0802c9c4 @ case 40
    .4byte lbl_0802caf0 @ case 41
    .4byte lbl_0802c9d6 @ case 42
    .4byte lbl_0802c9dc @ case 43
    .4byte lbl_0802caf0 @ case 44
    .4byte lbl_0802caf0 @ case 45
    .4byte lbl_0802caf0 @ case 46
    .4byte lbl_0802caf0 @ case 47
    .4byte lbl_0802caf0 @ case 48
    .4byte lbl_0802caf0 @ case 49
    .4byte lbl_0802caf0 @ case 50
    .4byte lbl_0802caf0 @ case 51
    .4byte lbl_0802ca2c @ case 52
    .4byte lbl_0802ca30 @ case 53
    .4byte lbl_0802ca36 @ case 54
    .4byte lbl_0802ca3a @ case 55
    .4byte lbl_0802ca78 @ case 56
    .4byte lbl_0802ca7c @ case 57
    .4byte lbl_0802ca82 @ case 58
    .4byte lbl_0802ca86 @ case 59
    .4byte lbl_0802caf0 @ case 60
    .4byte lbl_0802caf0 @ case 61
    .4byte lbl_0802caf0 @ case 62
    .4byte lbl_0802caf0 @ case 63
    .4byte lbl_0802caf0 @ case 64
    .4byte lbl_0802caf0 @ case 65
    .4byte lbl_0802ca40 @ case 66
    .4byte lbl_0802ca44 @ case 67
    .4byte lbl_0802ca4a @ case 68
    .4byte lbl_0802ca4e @ case 69
    .4byte lbl_0802caf0 @ case 70
    .4byte lbl_0802ca54 @ case 71
    .4byte lbl_0802ca5a @ case 72
    .4byte lbl_0802ca5e @ case 73
    .4byte lbl_0802ca9c @ case 74
    .4byte lbl_0802caa0 @ case 75
    .4byte lbl_0802caf0 @ case 76
    .4byte lbl_0802ca44 @ case 77
    .4byte lbl_0802caa6 @ case 78
    .4byte lbl_0802caaa @ case 79
    .4byte lbl_0802caf0 @ case 80
    .4byte lbl_0802cab0 @ case 81
    .4byte lbl_0802cab6 @ case 82
    .4byte lbl_0802cabc @ case 83
    .4byte lbl_0802caf0 @ case 84
    .4byte lbl_0802cac2 @ case 85
    .4byte lbl_0802cac8 @ case 86
    .4byte lbl_0802cacc @ case 87
    .4byte lbl_0802cad2 @ case 88
    .4byte lbl_0802cad6 @ case 89
    .4byte lbl_0802cadc @ case 90
    .4byte lbl_0802cae0 @ case 91
    .4byte lbl_0802caf0 @ case 92
    .4byte lbl_0802caf0 @ case 93
    .4byte lbl_0802ca64 @ case 94
    .4byte lbl_0802ca68 @ case 95
    .4byte lbl_0802caf0 @ case 96
    .4byte lbl_0802caf0 @ case 97
    .4byte lbl_0802caf0 @ case 98
    .4byte lbl_0802caf0 @ case 99
    .4byte lbl_0802caf0 @ case 100
    .4byte lbl_0802caf0 @ case 101
    .4byte lbl_0802caf0 @ case 102
    .4byte lbl_0802caf0 @ case 103
    .4byte lbl_0802caf0 @ case 104
    .4byte lbl_0802caf0 @ case 105
    .4byte lbl_0802caf0 @ case 106
    .4byte lbl_0802cae6 @ case 107
    .4byte lbl_0802caea @ case 108
lbl_0802c9ac:
    bl SpacePirateInit
    b lbl_0802caf6
lbl_0802c9b2:
    bl SpacePirateWalkingInit
    b lbl_0802caf6
lbl_0802c9b8:
    bl SpacePirateWalking
    b lbl_0802caf6
lbl_0802c9be:
    bl SpacePirateIdle
    b lbl_0802caf6
lbl_0802c9c4:
    bl SpacePirateIdleAtDoor
    b lbl_0802caf6
lbl_0802c9ca:
    bl SpacePirateWaitingAtDoor
    b lbl_0802caf6
lbl_0802c9d0:
    bl SpacePirateShootingAfterWaitingAtDoor
    b lbl_0802caf6
lbl_0802c9d6:
    bl unk_2aa5c
    b lbl_0802caf6
lbl_0802c9dc:
    bl unk_2aa88
    b lbl_0802caf6
lbl_0802c9e2:
    bl SpacePirateFallingInit
lbl_0802c9e6:
    bl SpacePirateFalling
    b lbl_0802caf6
lbl_0802c9ec:
    bl unk_2a794
lbl_0802c9f0:
    bl unk_2a7c0
    b lbl_0802caf6
lbl_0802c9f6:
    bl unk_2a768
    b lbl_0802c9f0
lbl_0802c9fc:
    bl unk_2ab34
lbl_0802ca00:
    bl sub_0802ab58
    b lbl_0802caf6
lbl_0802ca06:
    bl unk_2ab10
    b lbl_0802ca00
lbl_0802ca0c:
    bl unk_2aaec
    b lbl_0802ca00
lbl_0802ca12:
    bl SpacePirateTurningAroundInit
lbl_0802ca16:
    bl SpacePirateTurningAroundFirstPart
    b lbl_0802caf6
lbl_0802ca1c:
    bl SpacePirateTurningAroundSecondPart
    b lbl_0802caf6
lbl_0802ca22:
    bl SpacePirateWalkingAlertedInit
lbl_0802ca26:
    bl SpacePirateWalkingAlerted
    b lbl_0802caf6
lbl_0802ca2c:
    bl SpacePirateChargingLaserInit
lbl_0802ca30:
    bl SpacePirateChargingLaser
    b lbl_0802caf6
lbl_0802ca36:
    bl SpacePirateShootingLaserInit
lbl_0802ca3a:
    bl SpacePirateShootingLaser
    b lbl_0802caf6
lbl_0802ca40:
    bl SpacePirateJumpingInit
lbl_0802ca44:
    bl SpacePirateJumping
    b lbl_0802caf6
lbl_0802ca4a:
    bl SpacePirateTurningAroundAlertedInit
lbl_0802ca4e:
    bl SpacePirateTurningAroundFirstPartAlerted
    b lbl_0802caf6
lbl_0802ca54:
    bl SpacePirateTurningAroundSecondPartAlerted
    b lbl_0802caf6
lbl_0802ca5a:
    bl SpacePirateClimbingUpInit
lbl_0802ca5e:
    bl SpacePirateClimbingUp
    b lbl_0802caf6
lbl_0802ca64:
    bl SpacePirateClimbingDownInit
lbl_0802ca68:
    bl SpacePirateClimbingDown
    b lbl_0802caf6
lbl_0802ca6e:
    bl unk_2ba7c
lbl_0802ca72:
    bl unk_2ba98
    b lbl_0802caf6
lbl_0802ca78:
    bl SpacePirateClimbingChargingLaserInit
lbl_0802ca7c:
    bl SpacePirateClimbingChargingLaser
    b lbl_0802caf6
lbl_0802ca82:
    bl SpacePirateClimbingShootingLaserInit
lbl_0802ca86:
    bl SpacePirateClimbingShootingLaser
    b lbl_0802caf6
lbl_0802ca8c:
    bl SpacePirateTurningAroundToWallJumpInit
lbl_0802ca90:
    bl SpacePirateTurningAroundToWallJump
    b lbl_0802caf6
lbl_0802ca96:
    bl SpacePirateDelayBeforeLaunchingFromWall
    b lbl_0802caf6
lbl_0802ca9c:
    bl SpacePirateLaunchingFromWallInit
lbl_0802caa0:
    bl SpacePirateLaunchingFromWall
    b lbl_0802caf6
lbl_0802caa6:
    bl SpacePirateStartingToCrawlInit
lbl_0802caaa:
    bl SpacePirateStartingToCrawl
    b lbl_0802caf6
lbl_0802cab0:
    bl SpacePirateCrawling
    b lbl_0802caf6
lbl_0802cab6:
    bl SpacePirateTurningAroundWhileCrawlingInit
    b lbl_0802caf6
lbl_0802cabc:
    bl SpacePirateTurningWhileCrawlingFirstPart
    b lbl_0802caf6
lbl_0802cac2:
    bl SpacePirateTurningWhileCrawlingSecondPart
    b lbl_0802caf6
lbl_0802cac8:
    bl SpacePirateStandingUpInit
lbl_0802cacc:
    bl SpacePirateStandingUp
    b lbl_0802caf6
lbl_0802cad2:
    bl SpacePirateCrawlingStoppedInit
lbl_0802cad6:
    bl SpacePirateCrawlingStopped
    b lbl_0802caf6
lbl_0802cadc:
    bl SpacePirateFallingWhileCrawlingInit
lbl_0802cae0:
    bl SpacePirateFallingWhileCrawling
    b lbl_0802caf6
lbl_0802cae6:
    bl SpacePirateHitByLaserInit
lbl_0802caea:
    bl SpacePirateHitByLaser
    b lbl_0802caf6
lbl_0802caf0:
    movs r0, #1
    bl SpacePirateDeath
lbl_0802caf6:
    mov r0, r8
    cmp r0, #0
    bne lbl_0802cb10
    ldr r0, lbl_0802cb1c @ =0x03000738
    ldrh r1, [r0]
    ldr r0, lbl_0802cb20 @ =0x00008403
    ands r0, r1
    ldr r1, lbl_0802cb24 @ =0x00000403
    cmp r0, r1
    bne lbl_0802cb10
    ldr r0, lbl_0802cb28 @ =0x00000169
    bl SoundPlayNotAlreadyPlaying
lbl_0802cb10:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802cb1c: .4byte 0x03000738
lbl_0802cb20: .4byte 0x00008403
lbl_0802cb24: .4byte 0x00000403
lbl_0802cb28: .4byte 0x00000169

    thumb_func_start SpacePirateLaser
SpacePirateLaser: @ 0x0802cb2c
    push {lr}
    ldr r0, lbl_0802cb44 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x42
    beq lbl_0802cb54
    cmp r0, #0x42
    bgt lbl_0802cb48
    cmp r0, #0
    beq lbl_0802cb4e
    b lbl_0802cb60
    .align 2, 0
lbl_0802cb44: .4byte 0x03000738
lbl_0802cb48:
    cmp r0, #0x43
    beq lbl_0802cb5a
    b lbl_0802cb60
lbl_0802cb4e:
    bl SpacePirateLaserInit
    b lbl_0802cb64
lbl_0802cb54:
    bl SpacePirateLaserExplodingInit
    b lbl_0802cb64
lbl_0802cb5a:
    bl SpacePirateLaserCheckExplodingAnimEnded
    b lbl_0802cb64
lbl_0802cb60:
    bl SpacePirateLaserMove
lbl_0802cb64:
    pop {r0}
    bx r0

    thumb_func_start BlackSpacePirateProjectileCollision
BlackSpacePirateProjectileCollision: @ 0x0802cb68
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    ldr r0, lbl_0802cc1c @ =0x03001530
    mov sl, r0
    ldr r5, lbl_0802cc20 @ =0x03000738
    ldrh r1, [r5, #2]
    ldrh r2, [r5, #4]
    ldrh r0, [r5, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    ldrh r0, [r5, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #0xc]
    ldrh r0, [r5, #0xe]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #8]
    ldrh r0, [r5, #0x10]
    adds r2, r2, r0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0x10]
    ldr r6, lbl_0802cc24 @ =0x03000a2c
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r6, r1
    cmp r6, r0
    blo lbl_0802cbb4
    b lbl_0802cdba
lbl_0802cbb4:
    movs r0, #1
    mov sb, r0
    movs r1, #0x33
    mov r8, r1
    movs r7, #0x2e
lbl_0802cbbe:
    ldrb r1, [r6]
    mov r0, sb
    ands r0, r1
    cmp r0, #0
    bne lbl_0802cbca
    b lbl_0802cdb0
lbl_0802cbca:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0802cbd4
    b lbl_0802cdb0
lbl_0802cbd4:
    ldrb r0, [r6, #0x11]
    cmp r0, #1
    bhi lbl_0802cbdc
    b lbl_0802cdb0
lbl_0802cbdc:
    ldrb r0, [r6, #0xf]
    cmp r0, #0xd
    bls lbl_0802cbe4
    b lbl_0802cdb0
lbl_0802cbe4:
    ldrh r0, [r6, #0xa]
    ldr r1, [sp, #8]
    cmp r0, r1
    bhi lbl_0802cbee
    b lbl_0802cdb0
lbl_0802cbee:
    ldr r1, [sp, #0x10]
    cmp r0, r1
    blo lbl_0802cbf6
    b lbl_0802cdb0
lbl_0802cbf6:
    ldrh r0, [r6, #8]
    ldr r1, [sp, #4]
    cmp r0, r1
    bhi lbl_0802cc00
    b lbl_0802cdb0
lbl_0802cc00:
    ldr r1, [sp, #0xc]
    cmp r0, r1
    blo lbl_0802cc08
    b lbl_0802cdb0
lbl_0802cc08:
    adds r3, r0, #0
    ldrh r4, [r6, #0xa]
    ldrb r1, [r6, #0xf]
    cmp r1, #0xa
    beq lbl_0802ccda
    cmp r1, #0xa
    bgt lbl_0802cc28
    cmp r1, #4
    beq lbl_0802cc36
    b lbl_0802cda2
    .align 2, 0
lbl_0802cc1c: .4byte 0x03001530
lbl_0802cc20: .4byte 0x03000738
lbl_0802cc24: .4byte 0x03000a2c
lbl_0802cc28:
    cmp r1, #0xc
    bne lbl_0802cc2e
    b lbl_0802cd86
lbl_0802cc2e:
    cmp r1, #0xd
    bne lbl_0802cc34
    b lbl_0802cd94
lbl_0802cc34:
    b lbl_0802cda2
lbl_0802cc36:
    movs r0, #0
    strb r0, [r6]
    mov r0, sl
    ldrb r2, [r0, #0xd]
    mov r0, sb
    ands r0, r2
    cmp r0, #0
    beq lbl_0802cc82
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802cc6c
    ands r1, r2
    cmp r1, #0
    beq lbl_0802cc66
    mov r1, r8
    str r1, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #6
    bl ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cc66:
    mov r0, r8
    str r0, [sp]
    b lbl_0802cc94
lbl_0802cc6c:
    ands r1, r2
    cmp r1, #0
    beq lbl_0802ccba
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #5
    bl ProjectileHitSprite
    b lbl_0802cdb0
lbl_0802cc82:
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802ccb4
    ands r1, r2
    cmp r1, #0
    beq lbl_0802cca2
    mov r1, r8
    str r1, [sp]
lbl_0802cc94:
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #5
    bl ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cca2:
    mov r0, r8
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #4
    bl ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802ccb4:
    ands r1, r2
    cmp r1, #0
    beq lbl_0802ccca
lbl_0802ccba:
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #4
    bl ProjectileHitSprite
    b lbl_0802cdb0
lbl_0802ccca:
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #3
    bl ProjectileHitSprite
    b lbl_0802cdb0
lbl_0802ccda:
    movs r0, #0
    strb r0, [r6]
    mov r0, sl
    ldrb r1, [r0, #0xd]
    mov r0, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd2a
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd12
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd0c
    mov r1, r8
    str r1, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0x18
    bl charged_ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd0c:
    mov r0, r8
    str r0, [sp]
    b lbl_0802cd3e
lbl_0802cd12:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd66
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0x14
    bl non_ice_charged_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd2a:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd5e
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd4c
    mov r1, r8
    str r1, [sp]
lbl_0802cd3e:
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0x14
    bl charged_ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd4c:
    mov r0, r8
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl charged_ice_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd5e:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cd76
lbl_0802cd66:
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl non_ice_charged_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd76:
    str r7, [sp]
    adds r0, r5, #0
    adds r1, r3, #0
    adds r2, r4, #0
    movs r3, #0xc
    bl non_ice_charged_beam_hitting_sprite
    b lbl_0802cdb0
lbl_0802cd86:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r3, #0
    adds r3, r4, #0
    bl missile_hit_sprite
    b lbl_0802cdb0
lbl_0802cd94:
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r3, #0
    adds r3, r4, #0
    bl super_missile_hit_sprite
    b lbl_0802cdb0
lbl_0802cda2:
    movs r0, #0
    strb r0, [r6]
    adds r0, r3, #0
    adds r1, r4, #0
    movs r2, #0x2f
    bl ParticleSet
lbl_0802cdb0:
    adds r6, #0x1c
    ldr r0, lbl_0802cdcc @ =0x03000bec
    cmp r6, r0
    bhs lbl_0802cdba
    b lbl_0802cbbe
lbl_0802cdba:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802cdcc: .4byte 0x03000bec

    thumb_func_start BlackSpacePirateCollidingWithLaser
BlackSpacePirateCollidingWithLaser: @ 0x0802cdd0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x20
    ldr r3, lbl_0802ce88 @ =0x03000738
    ldrh r1, [r3]
    movs r0, #6
    ands r0, r1
    cmp r0, #2
    bne lbl_0802ce9c
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    ldrh r0, [r3, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x10]
    ldrh r0, [r3, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #0x18]
    ldrh r0, [r3, #0xe]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x14]
    ldrh r0, [r3, #0x10]
    adds r2, r2, r0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov sl, r2
    movs r0, #4
    mov sb, r0
    ldr r6, lbl_0802ce8c @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r6, r1
    cmp r6, r0
    bhs lbl_0802ce9c
    movs r7, #0x25
    adds r7, r7, r6
    mov r8, r7
lbl_0802ce2a:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ce90
    mov r1, r8
    ldrb r0, [r1]
    cmp r0, #0x13
    bne lbl_0802ce90
    ldrb r7, [r1, #9]
    str r7, [sp, #0x1c]
    cmp r7, #0
    bne lbl_0802ce90
    ldrh r4, [r6, #2]
    ldrh r5, [r6, #4]
    mov r0, sb
    subs r3, r4, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    adds r2, r4, r0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    subs r1, r5, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r3, [sp]
    str r2, [sp, #4]
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0x18]
    ldr r2, [sp, #0x14]
    mov r3, sl
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0802ce90
    strh r7, [r6]
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_0802ce9c
    .align 2, 0
lbl_0802ce88: .4byte 0x03000738
lbl_0802ce8c: .4byte 0x030001ac
lbl_0802ce90:
    movs r7, #0x38
    add r8, r7
    adds r6, #0x38
    ldr r0, lbl_0802ceac @ =0x030006ec
    cmp r6, r0
    blo lbl_0802ce2a
lbl_0802ce9c:
    add sp, #0x20
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802ceac: .4byte 0x030006ec

    thumb_func_start BlackSpacePirateInit
BlackSpacePirateInit: @ 0x0802ceb0
    push {r4, r5, r6, lr}
    ldr r0, lbl_0802cf6c @ =0x03000738
    mov ip, r0
    ldrh r0, [r0]
    ldr r3, lbl_0802cf70 @ =0x0000fffb
    ands r3, r0
    movs r5, #0
    movs r4, #0
    mov r1, ip
    strh r3, [r1]
    mov r0, ip
    adds r0, #0x27
    movs r6, #0x40
    strb r6, [r0]
    adds r1, #0x28
    movs r0, #8
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x28
    strb r0, [r1]
    ldr r0, lbl_0802cf74 @ =0x0000ff60
    mov r1, ip
    strh r0, [r1, #0xa]
    strh r4, [r1, #0xc]
    ldr r2, lbl_0802cf78 @ =0x082b0d68
    ldrb r1, [r1, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    mov r1, ip
    strh r0, [r1, #0x14]
    strh r0, [r1, #6]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r1, #0x12]
    mov r0, ip
    adds r0, #0x2e
    strb r5, [r0]
    subs r0, #4
    strb r5, [r0]
    adds r1, #0x25
    movs r0, #0x14
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x34
    movs r1, #2
    strb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    ldr r0, lbl_0802cf7c @ =0x082e4890
    mov r1, ip
    str r0, [r1, #0x18]
    strh r4, [r1, #0x16]
    strb r5, [r1, #0x1c]
    ldr r0, lbl_0802cf80 @ =0x0300083c
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, #0x3c
    mov r1, ip
    adds r1, #0x2c
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2d
    strb r5, [r0]
    subs r1, #8
    movs r0, #1
    strb r0, [r1]
    movs r1, #0x80
    lsls r1, r1, #8
    adds r0, r1, #0
    orrs r3, r0
    orrs r3, r5
    mov r0, ip
    strh r3, [r0]
    ldrb r1, [r0, #0x1e]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cf84
    adds r0, r3, #0
    ands r0, r6
    cmp r0, #0
    beq lbl_0802cf88
    movs r1, #0x80
    lsls r1, r1, #2
    adds r0, r1, #0
    orrs r3, r0
    mov r0, ip
    strh r3, [r0]
    b lbl_0802cf88
    .align 2, 0
lbl_0802cf6c: .4byte 0x03000738
lbl_0802cf70: .4byte 0x0000fffb
lbl_0802cf74: .4byte 0x0000ff60
lbl_0802cf78: .4byte 0x082b0d68
lbl_0802cf7c: .4byte 0x082e4890
lbl_0802cf80: .4byte 0x0300083c
lbl_0802cf84:
    bl SpriteUtilMakeSpriteFaceSamusDirection
lbl_0802cf88:
    bl SpacePirateFlip
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start BlackSpacePirateCheckStartActing
BlackSpacePirateCheckStartActing: @ 0x0802cf94
    push {lr}
    ldr r2, lbl_0802cfb0 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802cfaa
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x27
    strb r0, [r1]
lbl_0802cfaa:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802cfb0: .4byte 0x03000738

    thumb_func_start BlackSpacePirateShootingInit
BlackSpacePirateShootingInit: @ 0x0802cfb4
    push {lr}
    ldr r2, lbl_0802cfd4 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x35
    strb r0, [r1]
    adds r1, #8
    movs r0, #0xc
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0802cfdc
    ldr r0, lbl_0802cfd8 @ =0x082e4558
    b lbl_0802cfea
    .align 2, 0
lbl_0802cfd4: .4byte 0x03000738
lbl_0802cfd8: .4byte 0x082e4558
lbl_0802cfdc:
    cmp r0, #2
    bne lbl_0802cfe8
    ldr r0, lbl_0802cfe4 @ =0x082e4490
    b lbl_0802cfea
    .align 2, 0
lbl_0802cfe4: .4byte 0x082e4490
lbl_0802cfe8:
    ldr r0, lbl_0802d000 @ =0x082e4368
lbl_0802cfea:
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    movs r1, #0
    strh r0, [r2, #0x16]
    adds r0, r2, #0
    adds r0, #0x2e
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802d000: .4byte 0x082e4368

    thumb_func_start space_pirate_shooting_timer
space_pirate_shooting_timer: @ 0x0802d004
    push {r4, lr}
    ldr r4, lbl_0802d024 @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl unk_f594
    ldr r0, lbl_0802d028 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802d02c
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x1e
    b lbl_0802d040
    .align 2, 0
lbl_0802d024: .4byte 0x03000738
lbl_0802d028: .4byte 0x030007f0
lbl_0802d02c:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0802d03a
    subs r0, #1
    b lbl_0802d040
lbl_0802d03a:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x36
lbl_0802d040:
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start black_space_pirate_shooting_gfx_init
black_space_pirate_shooting_gfx_init: @ 0x0802d048
    push {lr}
    ldr r0, lbl_0802d064 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x37
    strb r1, [r2]
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r1, [r1]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_0802d06c
    ldr r0, lbl_0802d068 @ =0x082e4598
    b lbl_0802d07a
    .align 2, 0
lbl_0802d064: .4byte 0x03000738
lbl_0802d068: .4byte 0x082e4598
lbl_0802d06c:
    cmp r1, #2
    bne lbl_0802d078
    ldr r0, lbl_0802d074 @ =0x082e4508
    b lbl_0802d07a
    .align 2, 0
lbl_0802d074: .4byte 0x082e4508
lbl_0802d078:
    ldr r0, lbl_0802d088 @ =0x082e4428
lbl_0802d07a:
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802d088: .4byte 0x082e4428

    thumb_func_start sub_0802d08c
sub_0802d08c: @ 0x0802d08c
    push {r4, r5, lr}
    ldr r0, lbl_0802d0c0 @ =0x03000738
    ldrb r1, [r0, #0x1c]
    adds r1, #1
    strb r1, [r0, #0x1c]
    ldrh r0, [r0, #0x16]
    cmp r0, #2
    bne lbl_0802d0a8
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bne lbl_0802d0a8
    bl SpacePirateFireLaserGround
lbl_0802d0a8:
    bl unk_f594
    ldr r0, lbl_0802d0c4 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802d0c8
    ldr r0, lbl_0802d0c0 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0802d17a
    .align 2, 0
lbl_0802d0c0: .4byte 0x03000738
lbl_0802d0c4: .4byte 0x030007f0
lbl_0802d0c8:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802d17a
    ldr r0, lbl_0802d0e4 @ =0x030007f3
    ldrb r1, [r0, #2]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_0802d0ec
    ldr r0, lbl_0802d0e8 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x22
    strb r1, [r0]
    b lbl_0802d17a
    .align 2, 0
lbl_0802d0e4: .4byte 0x030007f3
lbl_0802d0e8: .4byte 0x03000738
lbl_0802d0ec:
    ldr r0, lbl_0802d13c @ =0x03000738
    ldrb r0, [r0, #0x1d]
    movs r1, #0x80
    lsls r1, r1, #2
    cmp r0, #0x55
    beq lbl_0802d106
    subs r1, #0x80
    ldr r0, lbl_0802d140 @ =0x030013d4
    movs r2, #0x16
    ldrsh r0, [r0, r2]
    cmp r0, #0
    beq lbl_0802d106
    movs r1, #0xc0
lbl_0802d106:
    adds r4, r5, #0
    ldrb r0, [r4]
    movs r2, #0xc0
    lsls r2, r2, #1
    cmp r0, #0
    bne lbl_0802d114
    movs r2, #0x80
lbl_0802d114:
    adds r0, r2, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r3, r0, #0
    ldr r2, lbl_0802d13c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d150
    cmp r3, #8
    bne lbl_0802d144
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    ldrb r1, [r4]
    b lbl_0802d16a
    .align 2, 0
lbl_0802d13c: .4byte 0x03000738
lbl_0802d140: .4byte 0x030013d4
lbl_0802d144:
    cmp r3, #4
    bne lbl_0802d172
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_0802d178
lbl_0802d150:
    cmp r3, #8
    bne lbl_0802d15c
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x44
    b lbl_0802d178
lbl_0802d15c:
    cmp r3, #4
    bne lbl_0802d172
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    ldrb r1, [r5]
lbl_0802d16a:
    adds r0, r2, #0
    adds r0, #0x2d
    strb r1, [r0]
    b lbl_0802d17a
lbl_0802d172:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
lbl_0802d178:
    strb r0, [r1]
lbl_0802d17a:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start BlackSpacePirateJumping
BlackSpacePirateJumping: @ 0x0802d180
    push {r4, r5, r6, r7, lr}
    movs r7, #0
    ldr r4, lbl_0802d1cc @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #7
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d232
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0802d19c
    b lbl_0802d5d6
lbl_0802d19c:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d20c
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802d1b4
    b lbl_0802d5d6
lbl_0802d1b4:
    bl sub_08029ef0
    adds r2, r4, #0
    adds r2, #0x24
    ldrb r0, [r2]
    cmp r0, #0x43
    beq lbl_0802d1c6
    cmp r0, #0x4d
    bne lbl_0802d1d0
lbl_0802d1c6:
    movs r0, #0x22
    strb r0, [r2]
    b lbl_0802d5d6
    .align 2, 0
lbl_0802d1cc: .4byte 0x03000738
lbl_0802d1d0:
    cmp r0, #0x42
    bne lbl_0802d200
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d1f0
    ldr r0, lbl_0802d1ec @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #0
    beq lbl_0802d1ea
    b lbl_0802d5d6
lbl_0802d1ea:
    b lbl_0802d206
    .align 2, 0
lbl_0802d1ec: .4byte 0x030007f3
lbl_0802d1f0:
    ldr r0, lbl_0802d1fc @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #1
    beq lbl_0802d1fa
    b lbl_0802d5d6
lbl_0802d1fa:
    b lbl_0802d206
    .align 2, 0
lbl_0802d1fc: .4byte 0x030007f3
lbl_0802d200:
    cmp r0, #0x4e
    beq lbl_0802d206
    b lbl_0802d5d6
lbl_0802d206:
    movs r0, #0x44
    strb r0, [r2]
    b lbl_0802d5d6
lbl_0802d20c:
    bl sub_08029b68
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802d218
    b lbl_0802d5d6
lbl_0802d218:
    bl sub_08029ef0
    adds r1, r4, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x43
    beq lbl_0802d22c
    cmp r0, #0x4d
    beq lbl_0802d22c
    b lbl_0802d5d6
lbl_0802d22c:
    movs r0, #8
    strb r0, [r1]
    b lbl_0802d5d6
lbl_0802d232:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    bne lbl_0802d2a6
    ldrh r0, [r4, #0x16]
    cmp r0, #3
    bhi lbl_0802d282
    cmp r0, #3
    beq lbl_0802d248
    b lbl_0802d5d6
lbl_0802d248:
    ldr r1, [r4, #0x18]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r1, [r0, #4]
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    cmp r1, r0
    blt lbl_0802d25a
    b lbl_0802d5d6
lbl_0802d25a:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    ldrh r0, [r4, #2]
    subs r0, #0xb4
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802d270
    b lbl_0802d5d6
lbl_0802d270:
    ldrh r0, [r4, #2]
    subs r0, #0xb4
    movs r2, #0x40
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    adds r0, #0xf4
    strh r0, [r4, #2]
    b lbl_0802d5d6
lbl_0802d282:
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d2a2
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    lsrs r6, r0, #2
    cmp r6, #5
    bgt lbl_0802d29c
    movs r6, #5
    b lbl_0802d2a8
lbl_0802d29c:
    cmp r6, #0xb
    ble lbl_0802d2a8
    b lbl_0802d2a6
lbl_0802d2a2:
    movs r6, #4
    b lbl_0802d2a8
lbl_0802d2a6:
    movs r6, #0xc
lbl_0802d2a8:
    ldr r4, lbl_0802d304 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d308
    ldrh r0, [r4, #2]
    subs r0, #0xa0
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d2cc
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d2cc:
    ldrh r0, [r4, #2]
    subs r0, #0x5a
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d2e2
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d2e2:
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d2f8
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d2f8:
    cmp r7, #0
    bne lbl_0802d354
    ldrh r0, [r4, #4]
    adds r0, r0, r6
    b lbl_0802d352
    .align 2, 0
lbl_0802d304: .4byte 0x03000738
lbl_0802d308:
    ldrh r0, [r4, #2]
    subs r0, #0xa0
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d31e
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d31e:
    ldrh r0, [r4, #2]
    subs r0, #0x5a
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d334
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d334:
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d34a
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0802d34a:
    cmp r7, #0
    bne lbl_0802d354
    ldrh r0, [r4, #4]
    subs r0, r0, r6
lbl_0802d352:
    strh r0, [r4, #4]
lbl_0802d354:
    ldr r1, lbl_0802d388 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_0802d39a
    cmp r7, #0
    bne lbl_0802d36a
    b lbl_0802d484
lbl_0802d36a:
    ldr r1, lbl_0802d38c @ =0x030013d4
    ldrh r0, [r5, #2]
    ldrh r3, [r1, #0x14]
    cmp r0, r3
    bhs lbl_0802d39a
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802d390
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0802d39a
    b lbl_0802d484
    .align 2, 0
lbl_0802d388: .4byte 0x03000738
lbl_0802d38c: .4byte 0x030013d4
lbl_0802d390:
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bhs lbl_0802d39a
    movs r7, #0
lbl_0802d39a:
    cmp r7, #0
    beq lbl_0802d484
    movs r2, #2
    cmp r7, #2
    bhi lbl_0802d3ac
    movs r2, #0x1e
    cmp r7, #1
    bls lbl_0802d3ac
    movs r2, #0xf
lbl_0802d3ac:
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, r2
    bls lbl_0802d484
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d3d4
    ldrh r0, [r5, #2]
    subs r0, #0xa8
    ldrh r1, [r5, #4]
    adds r1, #0x30
    b lbl_0802d3dc
lbl_0802d3d4:
    ldrh r0, [r5, #2]
    subs r0, #0xa8
    ldrh r1, [r5, #4]
    subs r1, #0x30
lbl_0802d3dc:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802d3fc
    ldr r2, lbl_0802d3f8 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x48
    strb r0, [r1]
    adds r5, r2, #0
    b lbl_0802d474
    .align 2, 0
lbl_0802d3f8: .4byte 0x03000738
lbl_0802d3fc:
    ldr r1, lbl_0802d430 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_0802d454
    ldr r0, lbl_0802d434 @ =0x030007f3
    ldrb r0, [r0, #3]
    cmp r0, #1
    bne lbl_0802d46c
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802d43c
    ldr r1, lbl_0802d438 @ =0x030013d4
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0802d46c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802d472
    .align 2, 0
lbl_0802d430: .4byte 0x03000738
lbl_0802d434: .4byte 0x030007f3
lbl_0802d438: .4byte 0x030013d4
lbl_0802d43c:
    ldr r1, lbl_0802d450 @ =0x030013d4
    ldrh r0, [r5, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bhi lbl_0802d46c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802d472
    .align 2, 0
lbl_0802d450: .4byte 0x030013d4
lbl_0802d454:
    ldr r0, lbl_0802d468 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d46c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x5e
    b lbl_0802d472
    .align 2, 0
lbl_0802d468: .4byte 0x0300083c
lbl_0802d46c:
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x48
lbl_0802d472:
    strb r0, [r1]
lbl_0802d474:
    ldrh r1, [r5, #4]
    ldr r0, lbl_0802d480 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x20
    strh r0, [r5, #4]
    b lbl_0802d5d6
    .align 2, 0
lbl_0802d480: .4byte 0x0000ffc0
lbl_0802d484:
    ldr r1, lbl_0802d4cc @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802d4a2
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d4a2
    movs r0, #0xb3
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0802d4a2:
    ldr r1, lbl_0802d4cc @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #1
    bne lbl_0802d4d4
    ldr r0, lbl_0802d4d0 @ =0x082e1030
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x2a
    bhi lbl_0802d55e
    b lbl_0802d55a
    .align 2, 0
lbl_0802d4cc: .4byte 0x03000738
lbl_0802d4d0: .4byte 0x082e1030
lbl_0802d4d4:
    cmp r0, #2
    bne lbl_0802d4f8
    ldr r0, lbl_0802d4f4 @ =0x082e1046
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x26
    bhi lbl_0802d55e
    b lbl_0802d55a
    .align 2, 0
lbl_0802d4f4: .4byte 0x082e1046
lbl_0802d4f8:
    cmp r0, #3
    bne lbl_0802d51c
    ldr r0, lbl_0802d518 @ =0x082e105a
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x2a
    bhi lbl_0802d55e
    b lbl_0802d55a
    .align 2, 0
lbl_0802d518: .4byte 0x082e105a
lbl_0802d51c:
    cmp r0, #4
    bne lbl_0802d540
    ldr r0, lbl_0802d53c @ =0x082e1070
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x2e
    bhi lbl_0802d55e
    b lbl_0802d55a
    .align 2, 0
lbl_0802d53c: .4byte 0x082e1070
lbl_0802d540:
    ldr r0, lbl_0802d5a8 @ =0x082e1020
    adds r4, r5, #0
    adds r4, #0x2f
    ldrb r3, [r4]
    lsls r1, r3, #0x18
    lsrs r2, r1, #0x18
    lsrs r1, r1, #0x1a
    lsls r1, r1, #1
    adds r1, r1, r0
    movs r0, #0
    ldrsh r6, [r1, r0]
    cmp r2, #0x1e
    bhi lbl_0802d55e
lbl_0802d55a:
    adds r0, r3, #1
    strb r0, [r4]
lbl_0802d55e:
    adds r4, r5, #0
    ldrh r0, [r4, #2]
    adds r0, r0, r6
    movs r7, #0
    strh r0, [r4, #2]
    cmp r6, #0
    ble lbl_0802d5b8
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802d5ac @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802d5d6
    strh r1, [r4, #2]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #7
    adds r1, r2, #0
    orrs r0, r1
    orrs r0, r7
    strh r0, [r4]
    ldr r1, lbl_0802d5b0 @ =0x082e44e0
    str r1, [r4, #0x18]
    strb r7, [r4, #0x1c]
    movs r1, #0
    strh r1, [r4, #0x16]
    movs r1, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d5d6
    ldr r0, lbl_0802d5b4 @ =0x00000167
    bl SoundPlayNotAlreadyPlaying
    b lbl_0802d5d6
    .align 2, 0
lbl_0802d5a8: .4byte 0x082e1020
lbl_0802d5ac: .4byte 0x030007f0
lbl_0802d5b0: .4byte 0x082e44e0
lbl_0802d5b4: .4byte 0x00000167
lbl_0802d5b8:
    ldrh r0, [r5, #2]
    subs r0, #0xb4
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802d5d6
    ldrh r0, [r5, #2]
    subs r0, #0xb4
    movs r3, #0x40
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    adds r0, #0xf4
    strh r0, [r5, #2]
lbl_0802d5d6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0802d5dc
sub_0802d5dc: @ 0x0802d5dc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    movs r0, #0
    mov r8, r0
    ldr r4, lbl_0802d628 @ =0x03000738
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    bl SpacePirateCheckSamusInShootingRange
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    beq lbl_0802d5fc
    b lbl_0802d746
lbl_0802d5fc:
    bl sub_08029ef0
    adds r7, r4, #0
    adds r7, #0x24
    ldrb r0, [r7]
    cmp r0, #0x23
    beq lbl_0802d64c
    cmp r0, #0x42
    bne lbl_0802d640
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d630
    ldr r0, lbl_0802d62c @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #0
    beq lbl_0802d624
    b lbl_0802d746
lbl_0802d624:
    b lbl_0802d646
    .align 2, 0
lbl_0802d628: .4byte 0x03000738
lbl_0802d62c: .4byte 0x030007f3
lbl_0802d630:
    ldr r0, lbl_0802d63c @ =0x030007f3
    ldrb r0, [r0, #4]
    cmp r0, #1
    beq lbl_0802d63a
    b lbl_0802d746
lbl_0802d63a:
    b lbl_0802d646
    .align 2, 0
lbl_0802d63c: .4byte 0x030007f3
lbl_0802d640:
    cmp r0, #0x4e
    beq lbl_0802d646
    b lbl_0802d746
lbl_0802d646:
    movs r0, #0x44
    strb r0, [r7]
    b lbl_0802d746
lbl_0802d64c:
    ldrh r1, [r4]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d65a
    movs r1, #1
    mov r8, r1
lbl_0802d65a:
    bl sub_08029708
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    beq lbl_0802d6d4
    ldrh r0, [r4, #2]
    ldr r1, lbl_0802d694 @ =0xfffffed4
    adds r0, r0, r1
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802d6b8
    ldrh r0, [r4, #2]
    subs r0, #0xf0
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802d746
    mov r0, r8
    cmp r0, #0
    beq lbl_0802d698
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x18
    b lbl_0802d69e
    .align 2, 0
lbl_0802d694: .4byte 0xfffffed4
lbl_0802d698:
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x30
lbl_0802d69e:
    strb r0, [r1]
    ldr r0, lbl_0802d6b4 @ =0x03000738
    adds r0, #0x2d
    movs r1, #4
    strb r1, [r0]
    bl SpacePirateJumpingInit
    bl BlackSpacePirateJumping
    b lbl_0802d746
    .align 2, 0
lbl_0802d6b4: .4byte 0x03000738
lbl_0802d6b8:
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802d6cc @ =0x082e4320
    cmp r1, r0
    bne lbl_0802d746
    ldr r0, lbl_0802d6d0 @ =0x082e42f8
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    strh r6, [r4, #0x16]
    b lbl_0802d746
    .align 2, 0
lbl_0802d6cc: .4byte 0x082e4320
lbl_0802d6d0: .4byte 0x082e42f8
lbl_0802d6d4:
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0802d718 @ =0x082e42f8
    cmp r1, r0
    bne lbl_0802d6f4
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802d746
    ldr r0, lbl_0802d71c @ =0x082e4320
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r0, #0
    strh r5, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
lbl_0802d6f4:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d720
    adds r4, #0x2e
    ldrb r0, [r4]
    lsrs r0, r0, #2
    bl sub_0800f978
    ldrb r0, [r4]
    cmp r0, #0x33
    bhi lbl_0802d724
    adds r0, #2
    strb r0, [r4]
    b lbl_0802d724
    .align 2, 0
lbl_0802d718: .4byte 0x082e42f8
lbl_0802d71c: .4byte 0x082e4320
lbl_0802d720:
    movs r0, #9
    strb r0, [r7]
lbl_0802d724:
    ldr r2, lbl_0802d750 @ =0x03000738
    ldrb r0, [r2, #0x1c]
    cmp r0, #5
    bls lbl_0802d746
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802d746
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d746
    ldr r0, lbl_0802d754 @ =0x00000165
    bl SoundPlayNotAlreadyPlaying
lbl_0802d746:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802d750: .4byte 0x03000738
lbl_0802d754: .4byte 0x00000165

    thumb_func_start BlackSpacePirateDeath
BlackSpacePirateDeath: @ 0x0802d758
    push {lr}
    sub sp, #4
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802d776
    ldr r0, lbl_0802d790 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d776
    movs r0, #0xb5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0802d776:
    ldr r0, lbl_0802d790 @ =0x03000738
    ldrh r1, [r0, #2]
    subs r1, #0x60
    ldrh r2, [r0, #4]
    movs r0, #0x22
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802d790: .4byte 0x03000738

    thumb_func_start sub_0802d794
sub_0802d794: @ 0x0802d794
    push {r4, lr}
    ldr r4, lbl_0802d7d8 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d7aa
    movs r0, #0xb5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0802d7aa:
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x6c
    strb r0, [r1]
    movs r3, #0
    strh r2, [r4, #0x14]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x25
    strb r3, [r0]
    adds r1, r4, #0
    adds r1, #0x2c
    movs r0, #0x21
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802d7d8: .4byte 0x03000738

    thumb_func_start sub_0802d7dc
sub_0802d7dc: @ 0x0802d7dc
    push {lr}
    ldr r2, lbl_0802d824 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrb r0, [r2, #0x1c]
    subs r0, #1
    strb r0, [r2, #0x1c]
    adds r1, #6
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r3, r1, #0
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0802d83c
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d828
    adds r0, r2, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xe
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    strb r1, [r0]
    b lbl_0802d83c
    .align 2, 0
lbl_0802d824: .4byte 0x03000738
lbl_0802d828:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    cmp r3, #0
    bne lbl_0802d83c
    movs r0, #0
    bl BlackSpacePirateDeath
lbl_0802d83c:
    pop {r0}
    bx r0

    thumb_func_start BlackSpacePirate
BlackSpacePirate: @ 0x0802d840
    push {r4, r5, r6, r7, lr}
    bl BlackSpacePirateProjectileCollision
    ldr r5, lbl_0802d888 @ =0x03000738
    ldrh r0, [r5]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r1, r4, #0
    ands r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    rsbs r1, r1, #0
    lsrs r7, r1, #0x1f
    adds r6, r5, #0
    adds r6, #0x24
    ldrb r0, [r6]
    cmp r0, #0x61
    bhi lbl_0802d8c4
    bl SpacePirateSamusDetection
    ldrh r1, [r5]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802d8ac
    ldr r0, lbl_0802d88c @ =0x030007f3
    ldrb r0, [r0, #2]
    cmp r0, #1
    bne lbl_0802d894
    ldr r1, lbl_0802d890 @ =0x030001a8
    movs r2, #0xf0
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_0802d8c0
    .align 2, 0
lbl_0802d888: .4byte 0x03000738
lbl_0802d88c: .4byte 0x030007f3
lbl_0802d890: .4byte 0x030001a8
lbl_0802d894:
    ldr r0, lbl_0802d8a4 @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0802d8c0
    ldr r0, lbl_0802d8a8 @ =0x0000fbff
    ands r0, r1
    b lbl_0802d8be
    .align 2, 0
lbl_0802d8a4: .4byte 0x030001a8
lbl_0802d8a8: .4byte 0x0000fbff
lbl_0802d8ac:
    ldr r0, lbl_0802d8dc @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_0802d8c0
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0802d8c0
    adds r0, r4, #0
    orrs r0, r1
lbl_0802d8be:
    strh r0, [r5]
lbl_0802d8c0:
    bl BlackSpacePirateCollidingWithLaser
lbl_0802d8c4:
    ldr r0, lbl_0802d8e0 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x6c
    bls lbl_0802d8d0
    b lbl_0802dc44
lbl_0802d8d0:
    lsls r0, r0, #2
    ldr r1, lbl_0802d8e4 @ =lbl_0802d8e8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802d8dc: .4byte 0x030001a8
lbl_0802d8e0: .4byte 0x03000738
lbl_0802d8e4: .4byte lbl_0802d8e8
lbl_0802d8e8: @ jump table
    .4byte lbl_0802da9c @ case 0
    .4byte lbl_0802daa2 @ case 1
    .4byte lbl_0802dc44 @ case 2
    .4byte lbl_0802dc44 @ case 3
    .4byte lbl_0802dc44 @ case 4
    .4byte lbl_0802dc44 @ case 5
    .4byte lbl_0802dc44 @ case 6
    .4byte lbl_0802dc44 @ case 7
    .4byte lbl_0802daa8 @ case 8
    .4byte lbl_0802daae @ case 9
    .4byte lbl_0802db08 @ case 10
    .4byte lbl_0802db0c @ case 11
    .4byte lbl_0802db12 @ case 12
    .4byte lbl_0802dc44 @ case 13
    .4byte lbl_0802daec @ case 14
    .4byte lbl_0802dae6 @ case 15
    .4byte lbl_0802db02 @ case 16
    .4byte lbl_0802daf6 @ case 17
    .4byte lbl_0802dbe0 @ case 18
    .4byte lbl_0802dbe4 @ case 19
    .4byte lbl_0802dc44 @ case 20
    .4byte lbl_0802dbea @ case 21
    .4byte lbl_0802dafc @ case 22
    .4byte lbl_0802dc44 @ case 23
    .4byte lbl_0802dbc2 @ case 24
    .4byte lbl_0802dbc6 @ case 25
    .4byte lbl_0802dae2 @ case 26
    .4byte lbl_0802dc44 @ case 27
    .4byte lbl_0802daf2 @ case 28
    .4byte lbl_0802dc44 @ case 29
    .4byte lbl_0802dad8 @ case 30
    .4byte lbl_0802dadc @ case 31
    .4byte lbl_0802dc44 @ case 32
    .4byte lbl_0802dc44 @ case 33
    .4byte lbl_0802db18 @ case 34
    .4byte lbl_0802db1c @ case 35
    .4byte lbl_0802dac0 @ case 36
    .4byte lbl_0802dac6 @ case 37
    .4byte lbl_0802dc44 @ case 38
    .4byte lbl_0802dab4 @ case 39
    .4byte lbl_0802daba @ case 40
    .4byte lbl_0802dc44 @ case 41
    .4byte lbl_0802dacc @ case 42
    .4byte lbl_0802dad2 @ case 43
    .4byte lbl_0802dc44 @ case 44
    .4byte lbl_0802dc44 @ case 45
    .4byte lbl_0802dc44 @ case 46
    .4byte lbl_0802dc44 @ case 47
    .4byte lbl_0802dc44 @ case 48
    .4byte lbl_0802dc44 @ case 49
    .4byte lbl_0802dc44 @ case 50
    .4byte lbl_0802dc44 @ case 51
    .4byte lbl_0802db22 @ case 52
    .4byte lbl_0802db26 @ case 53
    .4byte lbl_0802db2c @ case 54
    .4byte lbl_0802db30 @ case 55
    .4byte lbl_0802dbcc @ case 56
    .4byte lbl_0802dbd0 @ case 57
    .4byte lbl_0802dbd6 @ case 58
    .4byte lbl_0802dbda @ case 59
    .4byte lbl_0802dc44 @ case 60
    .4byte lbl_0802dc44 @ case 61
    .4byte lbl_0802dc44 @ case 62
    .4byte lbl_0802dc44 @ case 63
    .4byte lbl_0802dc44 @ case 64
    .4byte lbl_0802dc44 @ case 65
    .4byte lbl_0802db94 @ case 66
    .4byte lbl_0802db98 @ case 67
    .4byte lbl_0802db9e @ case 68
    .4byte lbl_0802dba2 @ case 69
    .4byte lbl_0802dc44 @ case 70
    .4byte lbl_0802dba8 @ case 71
    .4byte lbl_0802dbae @ case 72
    .4byte lbl_0802dbb2 @ case 73
    .4byte lbl_0802dbf0 @ case 74
    .4byte lbl_0802dbf4 @ case 75
    .4byte lbl_0802dc44 @ case 76
    .4byte lbl_0802db98 @ case 77
    .4byte lbl_0802dbfa @ case 78
    .4byte lbl_0802dbfe @ case 79
    .4byte lbl_0802dc44 @ case 80
    .4byte lbl_0802dc04 @ case 81
    .4byte lbl_0802dc0a @ case 82
    .4byte lbl_0802dc10 @ case 83
    .4byte lbl_0802dc44 @ case 84
    .4byte lbl_0802dc16 @ case 85
    .4byte lbl_0802dc1c @ case 86
    .4byte lbl_0802dc20 @ case 87
    .4byte lbl_0802dc26 @ case 88
    .4byte lbl_0802dc2a @ case 89
    .4byte lbl_0802dc30 @ case 90
    .4byte lbl_0802dc34 @ case 91
    .4byte lbl_0802dc44 @ case 92
    .4byte lbl_0802dc44 @ case 93
    .4byte lbl_0802dbb8 @ case 94
    .4byte lbl_0802dbbc @ case 95
    .4byte lbl_0802dc44 @ case 96
    .4byte lbl_0802dc44 @ case 97
    .4byte lbl_0802dc44 @ case 98
    .4byte lbl_0802dc44 @ case 99
    .4byte lbl_0802dc44 @ case 100
    .4byte lbl_0802dc44 @ case 101
    .4byte lbl_0802dc44 @ case 102
    .4byte lbl_0802dc44 @ case 103
    .4byte lbl_0802dc44 @ case 104
    .4byte lbl_0802dc44 @ case 105
    .4byte lbl_0802dc44 @ case 106
    .4byte lbl_0802dc3a @ case 107
    .4byte lbl_0802dc3e @ case 108
lbl_0802da9c:
    bl BlackSpacePirateInit
    b lbl_0802dc4a
lbl_0802daa2:
    bl BlackSpacePirateCheckStartActing
    b lbl_0802dc4a
lbl_0802daa8:
    bl SpacePirateWalkingInit
    b lbl_0802dc4a
lbl_0802daae:
    bl SpacePirateWalking
    b lbl_0802dc4a
lbl_0802dab4:
    bl SpacePirateIdle
    b lbl_0802dc4a
lbl_0802daba:
    bl SpacePirateIdleAtDoor
    b lbl_0802dc4a
lbl_0802dac0:
    bl SpacePirateWaitingAtDoor
    b lbl_0802dc4a
lbl_0802dac6:
    bl SpacePirateShootingAfterWaitingAtDoor
    b lbl_0802dc4a
lbl_0802dacc:
    bl unk_2aa5c
    b lbl_0802dc4a
lbl_0802dad2:
    bl unk_2aa88
    b lbl_0802dc4a
lbl_0802dad8:
    bl SpacePirateFallingInit
lbl_0802dadc:
    bl SpacePirateFalling
    b lbl_0802dc4a
lbl_0802dae2:
    bl unk_2a794
lbl_0802dae6:
    bl unk_2a7c0
    b lbl_0802dc4a
lbl_0802daec:
    bl unk_2a768
    b lbl_0802dae6
lbl_0802daf2:
    bl unk_2ab34
lbl_0802daf6:
    bl sub_0802ab58
    b lbl_0802dc4a
lbl_0802dafc:
    bl unk_2ab10
    b lbl_0802daf6
lbl_0802db02:
    bl unk_2aaec
    b lbl_0802daf6
lbl_0802db08:
    bl SpacePirateTurningAroundInit
lbl_0802db0c:
    bl SpacePirateTurningAroundFirstPart
    b lbl_0802dc4a
lbl_0802db12:
    bl SpacePirateTurningAroundSecondPart
    b lbl_0802dc4a
lbl_0802db18:
    bl SpacePirateWalkingAlertedInit
lbl_0802db1c:
    bl sub_0802d5dc
    b lbl_0802dc4a
lbl_0802db22:
    bl BlackSpacePirateShootingInit
lbl_0802db26:
    bl space_pirate_shooting_timer
    b lbl_0802dc4a
lbl_0802db2c:
    bl black_space_pirate_shooting_gfx_init
lbl_0802db30:
    bl sub_0802d08c
    ldr r4, lbl_0802db8c @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x37
    bne lbl_0802db42
    b lbl_0802dc4a
lbl_0802db42:
    cmp r0, #0x44
    bne lbl_0802db48
    b lbl_0802dc4a
lbl_0802db48:
    ldrh r0, [r4, #2]
    ldr r1, lbl_0802db90 @ =0xfffffed4
    adds r0, r0, r1
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802dc4a
    ldrh r0, [r4, #2]
    subs r0, #0xf0
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802dc4a
    ldrh r0, [r4, #6]
    ldrh r2, [r4, #0x14]
    cmp r0, r2
    beq lbl_0802dc4a
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x18
    strb r0, [r1]
    subs r1, #1
    movs r0, #4
    strb r0, [r1]
    bl SpacePirateJumpingInit
    bl BlackSpacePirateJumping
    ldrh r0, [r4, #0x14]
    strh r0, [r4, #6]
    b lbl_0802dc4a
    .align 2, 0
lbl_0802db8c: .4byte 0x03000738
lbl_0802db90: .4byte 0xfffffed4
lbl_0802db94:
    bl SpacePirateJumpingInit
lbl_0802db98:
    bl BlackSpacePirateJumping
    b lbl_0802dc4a
lbl_0802db9e:
    bl SpacePirateTurningAroundAlertedInit
lbl_0802dba2:
    bl SpacePirateTurningAroundFirstPartAlerted
    b lbl_0802dc4a
lbl_0802dba8:
    bl SpacePirateTurningAroundSecondPartAlerted
    b lbl_0802dc4a
lbl_0802dbae:
    bl SpacePirateClimbingUpInit
lbl_0802dbb2:
    bl SpacePirateClimbingUp
    b lbl_0802dc4a
lbl_0802dbb8:
    bl SpacePirateClimbingDownInit
lbl_0802dbbc:
    bl SpacePirateClimbingDown
    b lbl_0802dc4a
lbl_0802dbc2:
    bl unk_2ba7c
lbl_0802dbc6:
    bl unk_2ba98
    b lbl_0802dc4a
lbl_0802dbcc:
    bl SpacePirateClimbingChargingLaserInit
lbl_0802dbd0:
    bl SpacePirateClimbingChargingLaser
    b lbl_0802dc4a
lbl_0802dbd6:
    bl SpacePirateClimbingShootingLaserInit
lbl_0802dbda:
    bl SpacePirateClimbingShootingLaser
    b lbl_0802dc4a
lbl_0802dbe0:
    bl SpacePirateTurningAroundToWallJumpInit
lbl_0802dbe4:
    bl SpacePirateTurningAroundToWallJump
    b lbl_0802dc4a
lbl_0802dbea:
    bl SpacePirateDelayBeforeLaunchingFromWall
    b lbl_0802dc4a
lbl_0802dbf0:
    bl SpacePirateLaunchingFromWallInit
lbl_0802dbf4:
    bl SpacePirateLaunchingFromWall
    b lbl_0802dc4a
lbl_0802dbfa:
    bl SpacePirateStartingToCrawlInit
lbl_0802dbfe:
    bl SpacePirateStartingToCrawl
    b lbl_0802dc4a
lbl_0802dc04:
    bl SpacePirateCrawling
    b lbl_0802dc4a
lbl_0802dc0a:
    bl SpacePirateTurningAroundWhileCrawlingInit
    b lbl_0802dc4a
lbl_0802dc10:
    bl SpacePirateTurningWhileCrawlingFirstPart
    b lbl_0802dc4a
lbl_0802dc16:
    bl SpacePirateTurningWhileCrawlingSecondPart
    b lbl_0802dc4a
lbl_0802dc1c:
    bl SpacePirateStandingUpInit
lbl_0802dc20:
    bl SpacePirateStandingUp
    b lbl_0802dc4a
lbl_0802dc26:
    bl SpacePirateCrawlingStoppedInit
lbl_0802dc2a:
    bl SpacePirateCrawlingStopped
    b lbl_0802dc4a
lbl_0802dc30:
    bl SpacePirateFallingWhileCrawlingInit
lbl_0802dc34:
    bl SpacePirateFallingWhileCrawling
    b lbl_0802dc4a
lbl_0802dc3a:
    bl sub_0802d794
lbl_0802dc3e:
    bl sub_0802d7dc
    b lbl_0802dc4a
lbl_0802dc44:
    movs r0, #1
    bl BlackSpacePirateDeath
lbl_0802dc4a:
    cmp r7, #0
    bne lbl_0802dc62
    ldr r0, lbl_0802dc68 @ =0x03000738
    ldrh r1, [r0]
    ldr r0, lbl_0802dc6c @ =0x00008403
    ands r0, r1
    ldr r1, lbl_0802dc70 @ =0x00000403
    cmp r0, r1
    bne lbl_0802dc62
    ldr r0, lbl_0802dc74 @ =0x00000169
    bl SoundPlayNotAlreadyPlaying
lbl_0802dc62:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802dc68: .4byte 0x03000738
lbl_0802dc6c: .4byte 0x00008403
lbl_0802dc70: .4byte 0x00000403
lbl_0802dc74: .4byte 0x00000169
