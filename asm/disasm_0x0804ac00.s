    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start sub_0804ac00
sub_0804ac00: @ 0x0804ac00
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_0804ac40 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    adds r3, r2, #0
    cmp r5, #0
    bne lbl_0804ac7c
    strb r4, [r1]
    adds r2, #0x2d
    ldrb r1, [r2]
    movs r4, #0x80
    adds r0, r1, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_0804ac44
    cmp r1, #0x80
    bls lbl_0804ac34
    subs r0, r1, #1
    strb r0, [r2]
lbl_0804ac34:
    ldrb r0, [r2]
    cmp r0, #0x80
    bne lbl_0804ac58
    strb r5, [r2]
    b lbl_0804ac58
    .align 2, 0
lbl_0804ac40: .4byte 0x03000738
lbl_0804ac44:
    cmp r1, #1
    bhi lbl_0804ac4c
    adds r0, r1, #1
    strb r0, [r2]
lbl_0804ac4c:
    ldrb r1, [r2]
    cmp r1, #2
    bne lbl_0804ac58
    adds r0, r4, #0
    orrs r0, r1
    strb r0, [r2]
lbl_0804ac58:
    adds r0, r3, #0
    adds r0, #0x2d
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    ldr r2, lbl_0804ac84 @ =0x040000d4
    lsls r0, r0, #5
    ldr r1, lbl_0804ac88 @ =0x0831b518
    adds r0, r0, r1
    str r0, [r2]
    ldrb r0, [r3, #0x1f]
    lsls r0, r0, #5
    ldr r1, lbl_0804ac8c @ =0x05000320
    adds r0, r0, r1
    str r0, [r2, #4]
    ldr r0, lbl_0804ac90 @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0804ac7c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804ac84: .4byte 0x040000d4
lbl_0804ac88: .4byte 0x0831b518
lbl_0804ac8c: .4byte 0x05000320
lbl_0804ac90: .4byte 0x80000010

    thumb_func_start EscapeShipSetIgnoreSamus
EscapeShipSetIgnoreSamus: @ 0x0804ac94
    push {r4, r5, lr}
    ldr r2, lbl_0804acc4 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0804acbe
    movs r5, #1
    movs r4, #0xf
    adds r3, r0, #0
lbl_0804aca8:
    ldrh r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0804acb8
    adds r0, r2, #0
    adds r0, #0x26
    strb r4, [r0]
lbl_0804acb8:
    adds r2, #0x38
    cmp r2, r3
    blo lbl_0804aca8
lbl_0804acbe:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804acc4: .4byte 0x030001ac

    thumb_func_start EscapeShipSetPirateDrawOrder
EscapeShipSetPirateDrawOrder: @ 0x0804acc8
    push {r4, r5, r6, r7, lr}
    movs r7, #0x14
    ldr r3, lbl_0804ad04 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r3, r1
    cmp r3, r0
    bhs lbl_0804acfc
    movs r6, #1
    movs r5, #2
    adds r4, r0, #0
    adds r2, r3, #0
    adds r2, #0x22
lbl_0804ace2:
    ldrh r1, [r3]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0804acf4
    ldrb r0, [r2, #3]
    cmp r0, r7
    bne lbl_0804acf4
    strb r5, [r2]
lbl_0804acf4:
    adds r2, #0x38
    adds r3, #0x38
    cmp r3, r4
    blo lbl_0804ace2
lbl_0804acfc:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804ad04: .4byte 0x030001ac

    thumb_func_start EscapeShipPirateCollision
EscapeShipPirateCollision: @ 0x0804ad08
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r2, lbl_0804ada4 @ =0x03000738
    ldrh r1, [r2, #2]
    ldrh r3, [r2, #4]
    ldrh r0, [r2, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    ldrh r0, [r2, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    ldrh r0, [r2, #0xe]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrh r0, [r2, #0x10]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r7, r3, #0x10
    ldr r6, lbl_0804ada8 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r6, r1
    cmp r6, r0
    bhs lbl_0804adb6
    adds r5, r6, #0
    adds r5, #0xa
lbl_0804ad50:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804adac
    ldrb r0, [r5, #0x1b]
    cmp r0, #0x14
    bne lbl_0804adac
    ldrh r3, [r6, #2]
    ldrh r4, [r6, #4]
    ldrh r2, [r5]
    adds r2, r3, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrh r0, [r5, #2]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrh r1, [r5, #4]
    adds r1, r4, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r0, [r5, #6]
    adds r4, r4, r0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    str r2, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r4, [sp, #0xc]
    mov r0, sl
    mov r1, sb
    mov r2, r8
    adds r3, r7, #0
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0804adac
    movs r0, #0x62
    strb r0, [r5, #0x1a]
    b lbl_0804adb6
    .align 2, 0
lbl_0804ada4: .4byte 0x03000738
lbl_0804ada8: .4byte 0x030001ac
lbl_0804adac:
    adds r5, #0x38
    adds r6, #0x38
    ldr r0, lbl_0804adc8 @ =0x030006ec
    cmp r6, r0
    blo lbl_0804ad50
lbl_0804adb6:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804adc8: .4byte 0x030006ec

    thumb_func_start EscapeShipCheckCollidingWithLaser
EscapeShipCheckCollidingWithLaser: @ 0x0804adcc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x14
    ldr r2, lbl_0804ae6c @ =0x03000738
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
    movs r7, #4
    ldr r6, lbl_0804ae70 @ =0x030001ac
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r6, r1
    cmp r6, r0
    bhs lbl_0804ae7c
lbl_0804ae14:
    ldrh r1, [r6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804ae74
    adds r0, r6, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, #0x13
    bne lbl_0804ae74
    ldrh r4, [r6, #2]
    ldrh r5, [r6, #4]
    subs r3, r4, r7
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    adds r2, r4, r7
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    subs r1, r5, r7
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r5, r7
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r3, [sp]
    str r2, [sp, #4]
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    ldr r0, [sp, #0x10]
    mov r1, sl
    mov r2, sb
    mov r3, r8
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0804ae74
    movs r0, #0
    strh r0, [r6]
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_0804ae7c
    .align 2, 0
lbl_0804ae6c: .4byte 0x03000738
lbl_0804ae70: .4byte 0x030001ac
lbl_0804ae74:
    adds r6, #0x38
    ldr r0, lbl_0804ae8c @ =0x030006ec
    cmp r6, r0
    blo lbl_0804ae14
lbl_0804ae7c:
    add sp, #0x14
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804ae8c: .4byte 0x030006ec

    thumb_func_start EscapeShip
EscapeShip: @ 0x0804ae90
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r0, lbl_0804aeb8 @ =0x03000738
    ldrh r1, [r0, #2]
    mov r8, r1
    ldrh r7, [r0, #4]
    adds r1, r0, #0
    adds r1, #0x24
    ldrb r1, [r1]
    adds r5, r0, #0
    cmp r1, #0x27
    bls lbl_0804aeae
    b lbl_0804b33e
lbl_0804aeae:
    lsls r0, r1, #2
    ldr r1, lbl_0804aebc @ =lbl_0804aec0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804aeb8: .4byte 0x03000738
lbl_0804aebc: .4byte lbl_0804aec0
lbl_0804aec0: @ jump table
    .4byte lbl_0804af60 @ case 0
    .4byte lbl_0804b33e @ case 1
    .4byte lbl_0804b33e @ case 2
    .4byte lbl_0804b33e @ case 3
    .4byte lbl_0804b33e @ case 4
    .4byte lbl_0804b33e @ case 5
    .4byte lbl_0804b33e @ case 6
    .4byte lbl_0804b33e @ case 7
    .4byte lbl_0804afe4 @ case 8
    .4byte lbl_0804b060 @ case 9
    .4byte lbl_0804b33e @ case 10
    .4byte lbl_0804b33e @ case 11
    .4byte lbl_0804b33e @ case 12
    .4byte lbl_0804b33e @ case 13
    .4byte lbl_0804b33e @ case 14
    .4byte lbl_0804b33e @ case 15
    .4byte lbl_0804b33e @ case 16
    .4byte lbl_0804b33e @ case 17
    .4byte lbl_0804b33e @ case 18
    .4byte lbl_0804b33e @ case 19
    .4byte lbl_0804b33e @ case 20
    .4byte lbl_0804b33e @ case 21
    .4byte lbl_0804b33e @ case 22
    .4byte lbl_0804b33e @ case 23
    .4byte lbl_0804b33e @ case 24
    .4byte lbl_0804b33e @ case 25
    .4byte lbl_0804b33e @ case 26
    .4byte lbl_0804b33e @ case 27
    .4byte lbl_0804b33e @ case 28
    .4byte lbl_0804b33e @ case 29
    .4byte lbl_0804b33e @ case 30
    .4byte lbl_0804b33e @ case 31
    .4byte lbl_0804b33e @ case 32
    .4byte lbl_0804b33e @ case 33
    .4byte lbl_0804b080 @ case 34
    .4byte lbl_0804b10c @ case 35
    .4byte lbl_0804b148 @ case 36
    .4byte lbl_0804b194 @ case 37
    .4byte lbl_0804b224 @ case 38
    .4byte lbl_0804b30c @ case 39
lbl_0804af60:
    ldr r5, lbl_0804afd4 @ =0x03000738
    adds r1, r5, #0
    adds r1, #0x27
    movs r4, #0
    movs r0, #0x30
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x28
    strb r4, [r0]
    adds r1, #2
    movs r0, #0x58
    strb r0, [r1]
    movs r2, #0
    ldr r0, lbl_0804afd8 @ =0x0000ffd4
    strh r0, [r5, #0xa]
    strh r4, [r5, #0xc]
    movs r0, #0x38
    strh r0, [r5, #0xe]
    movs r0, #0x68
    strh r0, [r5, #0x10]
    adds r0, r5, #0
    adds r0, #0x25
    strb r2, [r0]
    subs r1, #7
    movs r0, #0xb
    strb r0, [r1]
    ldr r0, lbl_0804afdc @ =0x0831c370
    str r0, [r5, #0x18]
    strh r4, [r5, #0x16]
    strb r2, [r5, #0x1c]
    adds r1, #2
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0804afe0 @ =0x0300070c
    strb r2, [r0, #0xf]
    ldrb r2, [r5, #0x1f]
    adds r6, r5, #0
    adds r6, #0x23
    ldrb r3, [r6]
    mov r0, r8
    str r0, [sp]
    str r7, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x45
    movs r1, #0
    bl SpriteSpawnSecondary
    ldrb r2, [r5, #0x1f]
    ldrb r3, [r6]
    mov r1, r8
    str r1, [sp]
    str r7, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x45
    movs r1, #2
    bl SpriteSpawnSecondary
    b lbl_0804b33e
    .align 2, 0
lbl_0804afd4: .4byte 0x03000738
lbl_0804afd8: .4byte 0x0000ffd4
lbl_0804afdc: .4byte 0x0831c370
lbl_0804afe0: .4byte 0x0300070c
lbl_0804afe4:
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    cmp r0, #0
    bne lbl_0804aff2
    b lbl_0804b33e
lbl_0804aff2:
    ldr r2, lbl_0804b050 @ =0x030013d4
    ldrh r0, [r2, #0x14]
    cmp r0, r8
    bls lbl_0804affc
    b lbl_0804b33e
lbl_0804affc:
    mov r6, r8
    subs r0, r6, r0
    movs r1, #0xc0
    lsls r1, r1, #2
    cmp r0, r1
    ble lbl_0804b00a
    b lbl_0804b33e
lbl_0804b00a:
    ldrh r0, [r2, #0x12]
    cmp r0, r7
    blo lbl_0804b012
    b lbl_0804b33e
lbl_0804b012:
    subs r0, r7, r0
    cmp r0, #0xff
    ble lbl_0804b01a
    b lbl_0804b33e
lbl_0804b01a:
    ldr r2, lbl_0804b054 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r4, #0
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_0804b058 @ =0x0831c380
    str r0, [r2, #0x18]
    movs r0, #0
    strh r4, [r2, #0x16]
    strb r0, [r2, #0x1c]
    ldrb r1, [r2, #0x1e]
    ldrh r3, [r2, #2]
    subs r3, #4
    ldrh r0, [r2, #4]
    adds r0, #0x70
    str r0, [sp]
    str r4, [sp, #4]
    movs r0, #0xc7
    movs r2, #0
    bl SpriteSpawnPrimary
    ldr r0, lbl_0804b05c @ =0x0000024e
    bl SoundPlay
    b lbl_0804b33e
    .align 2, 0
lbl_0804b050: .4byte 0x030013d4
lbl_0804b054: .4byte 0x03000738
lbl_0804b058: .4byte 0x0831c380
lbl_0804b05c: .4byte 0x0000024e
lbl_0804b060:
    ldr r2, lbl_0804b07c @ =0x03000738
    ldrh r0, [r2, #0x16]
    cmp r0, #6
    bhi lbl_0804b06a
    b lbl_0804b33e
lbl_0804b06a:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    adds r1, #1
    movs r0, #2
    strb r0, [r1]
    b lbl_0804b33e
    .align 2, 0
lbl_0804b07c: .4byte 0x03000738
lbl_0804b080:
    ldr r2, lbl_0804b0d4 @ =0x03000738
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r3
    cmp r0, #0
    bne lbl_0804b090
    b lbl_0804b33e
lbl_0804b090:
    adds r1, r2, #0
    adds r1, #0x31
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_0804b0d8 @ =0x0000efff
    ands r0, r3
    movs r3, #0
    strh r0, [r2]
    subs r1, #0xf
    movs r0, #4
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x23
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x14
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x25
    strb r3, [r0]
    ldr r1, lbl_0804b0dc @ =0x030013d4
    ldrb r0, [r1, #6]
    cmp r0, #0
    beq lbl_0804b0c2
    strb r3, [r1, #6]
lbl_0804b0c2:
    ldrh r1, [r1, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0804b0e0
    movs r0, #0x41
    bl SamusSetPose
    b lbl_0804b0e6
    .align 2, 0
lbl_0804b0d4: .4byte 0x03000738
lbl_0804b0d8: .4byte 0x0000efff
lbl_0804b0dc: .4byte 0x030013d4
lbl_0804b0e0:
    movs r0, #0x42
    bl SamusSetPose
lbl_0804b0e6:
    movs r0, #1
    movs r1, #0x4b
    bl EventFunction
    ldr r1, lbl_0804b104 @ =0x03000738
    movs r2, #0
    ldr r0, lbl_0804b108 @ =0x0000ff60
    strh r0, [r1, #0xa]
    strh r2, [r1, #0xc]
    strh r2, [r1, #0xe]
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r1, #0x10]
    b lbl_0804b33e
    .align 2, 0
lbl_0804b104: .4byte 0x03000738
lbl_0804b108: .4byte 0x0000ff60
lbl_0804b10c:
    ldr r2, lbl_0804b13c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    beq lbl_0804b122
    b lbl_0804b33e
lbl_0804b122:
    subs r1, #8
    movs r0, #0x24
    strb r0, [r1]
    ldr r0, lbl_0804b140 @ =0x0831c3c8
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    ldr r0, lbl_0804b144 @ =0x0000024f
    bl SoundPlay
    b lbl_0804b33e
    .align 2, 0
lbl_0804b13c: .4byte 0x03000738
lbl_0804b140: .4byte 0x0831c3c8
lbl_0804b144: .4byte 0x0000024f
lbl_0804b148:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0804b152
    b lbl_0804b33e
lbl_0804b152:
    ldr r3, lbl_0804b188 @ =0x03000738
    ldr r0, lbl_0804b18c @ =0x0831c370
    str r0, [r3, #0x18]
    movs r2, #0
    movs r0, #0
    strh r0, [r3, #0x16]
    strb r2, [r3, #0x1c]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x1e
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x5a
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2e
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    ldr r1, lbl_0804b190 @ =0x0300070c
    movs r0, #1
    strb r0, [r1, #0xf]
    b lbl_0804b33e
    .align 2, 0
lbl_0804b188: .4byte 0x03000738
lbl_0804b18c: .4byte 0x0831c370
lbl_0804b190: .4byte 0x0300070c
lbl_0804b194:
    adds r3, r5, #0
    adds r4, r3, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0804b1ea
    subs r0, #1
    strb r0, [r4]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0xa
    bhi lbl_0804b1b4
    ldrh r0, [r3, #4]
    adds r0, #2
    strh r0, [r3, #4]
    b lbl_0804b33e
lbl_0804b1b4:
    cmp r1, #0xb
    bne lbl_0804b1dc
    ldrb r2, [r3, #0x1f]
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r3, [r0]
    mov r0, r8
    str r0, [sp]
    str r7, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x45
    movs r1, #3
    bl SpriteSpawnSecondary
    movs r0, #0x94
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0804b33e
lbl_0804b1dc:
    cmp r1, #0xc
    beq lbl_0804b1e2
    b lbl_0804b33e
lbl_0804b1e2:
    movs r0, #8
    bl StartEffectForCutscene
    b lbl_0804b33e
lbl_0804b1ea:
    adds r2, r3, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0x3b
    bhi lbl_0804b218
    ldrh r0, [r3, #2]
    subs r0, #1
    strh r0, [r3, #2]
    cmp r1, #0
    bne lbl_0804b2a2
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x26
    strb r0, [r1]
    movs r0, #0xc8
    strb r0, [r4]
    movs r0, #0x64
    strb r0, [r2]
    b lbl_0804b2a2
lbl_0804b218:
    cmp r1, #0x42
    bhi lbl_0804b2a2
    ldrh r0, [r5, #4]
    adds r0, #1
    strh r0, [r5, #4]
    b lbl_0804b2a2
lbl_0804b224:
    ldr r2, lbl_0804b250 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    cmp r0, #0
    beq lbl_0804b27c
    subs r1, r0, #1
    strb r1, [r3]
    lsls r0, r1, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_0804b25c
    ldr r0, lbl_0804b254 @ =0x0831c410
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    ldr r0, lbl_0804b258 @ =0x00000251
    bl SoundPlay
    b lbl_0804b26a
    .align 2, 0
lbl_0804b250: .4byte 0x03000738
lbl_0804b254: .4byte 0x0831c410
lbl_0804b258: .4byte 0x00000251
lbl_0804b25c:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x64
    bne lbl_0804b26a
    ldr r1, lbl_0804b274 @ =0x0300070c
    movs r0, #2
    strb r0, [r1, #0xf]
lbl_0804b26a:
    ldr r1, lbl_0804b278 @ =0x03000738
    ldrh r0, [r1, #2]
    subs r0, #2
    strh r0, [r1, #2]
    b lbl_0804b2a2
    .align 2, 0
lbl_0804b274: .4byte 0x0300070c
lbl_0804b278: .4byte 0x03000738
lbl_0804b27c:
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804b2a2
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x27
    strb r0, [r1]
    movs r0, #0xc8
    strh r0, [r2, #6]
    movs r0, #4
    strb r0, [r3]
    ldr r0, lbl_0804b2f8 @ =0x00000252
    bl SoundPlay
lbl_0804b2a2:
    ldr r3, lbl_0804b2fc @ =0x03000738
    adds r5, r3, #0
    adds r5, #0x2f
    ldrb r2, [r5]
    ldr r4, lbl_0804b300 @ =0x0831a548
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r6, #0
    ldrsh r1, [r0, r6]
    ldr r6, lbl_0804b304 @ =0x00007fff
    cmp r1, r6
    bne lbl_0804b2c0
    movs r7, #0
    ldrsh r1, [r4, r7]
    movs r2, #0
lbl_0804b2c0:
    adds r0, r2, #1
    strb r0, [r5]
    ldrh r0, [r3, #2]
    adds r0, r0, r1
    strh r0, [r3, #2]
    adds r5, r3, #0
    adds r5, #0x2e
    ldrb r2, [r5]
    ldr r4, lbl_0804b308 @ =0x0831a5ca
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r7, #0
    ldrsh r1, [r0, r7]
    cmp r1, r6
    bne lbl_0804b2e4
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0
lbl_0804b2e4:
    adds r0, r2, #1
    strb r0, [r5]
    ldrh r0, [r3, #4]
    adds r0, r0, r1
    strh r0, [r3, #4]
    ldrh r1, [r3, #2]
    mov r8, r1
    ldrh r7, [r3, #4]
    b lbl_0804b33e
    .align 2, 0
lbl_0804b2f8: .4byte 0x00000252
lbl_0804b2fc: .4byte 0x03000738
lbl_0804b300: .4byte 0x0831a548
lbl_0804b304: .4byte 0x00007fff
lbl_0804b308: .4byte 0x0831a5ca
lbl_0804b30c:
    ldr r1, lbl_0804b384 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0x3f
    bhi lbl_0804b31c
    adds r0, #1
    strb r0, [r2]
lbl_0804b31c:
    ldrb r0, [r2]
    lsrs r0, r0, #1
    ldrh r2, [r1, #4]
    adds r0, r0, r2
    strh r0, [r1, #4]
    ldrh r0, [r1, #6]
    subs r0, #1
    strh r0, [r1, #6]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_0804b33e
    adds r1, #0x24
    movs r0, #0x28
    strb r0, [r1]
    movs r0, #1
    bl StartEffectForCutscene
lbl_0804b33e:
    ldr r5, lbl_0804b384 @ =0x03000738
    adds r4, r5, #0
    adds r4, #0x24
    ldrb r0, [r4]
    cmp r0, #0x22
    bls lbl_0804b378
    ldr r1, lbl_0804b388 @ =0x030013d4
    mov r0, r8
    subs r0, #0x2b
    strh r0, [r1, #0x14]
    adds r0, r7, #0
    adds r0, #0x50
    strh r0, [r1, #0x12]
    bl EscapeShipSetIgnoreSamus
    bl EscapeShipCheckCollidingWithLaser
    bl EscapeShipSetPirateDrawOrder
    ldrb r0, [r4]
    cmp r0, #0x26
    bls lbl_0804b378
    adds r0, r5, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0x10
    bls lbl_0804b378
    bl EscapeShipPirateCollision
lbl_0804b378:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804b384: .4byte 0x03000738
lbl_0804b388: .4byte 0x030013d4

    thumb_func_start EscapeShipPart
EscapeShipPart: @ 0x0804b38c
    push {r4, r5, lr}
    ldr r3, lbl_0804b3c0 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r4, [r0]
    ldr r2, lbl_0804b3c4 @ =0x030001ac
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrh r1, [r0, #2]
    strh r1, [r3, #2]
    ldrh r0, [r0, #4]
    strh r0, [r3, #4]
    adds r0, r3, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x32
    bls lbl_0804b3b4
    b lbl_0804b5fe
lbl_0804b3b4:
    lsls r0, r0, #2
    ldr r1, lbl_0804b3c8 @ =lbl_0804b3cc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804b3c0: .4byte 0x03000738
lbl_0804b3c4: .4byte 0x030001ac
lbl_0804b3c8: .4byte lbl_0804b3cc
lbl_0804b3cc: @ jump table
    .4byte lbl_0804b498 @ case 0
    .4byte lbl_0804b5fe @ case 1
    .4byte lbl_0804b5fe @ case 2
    .4byte lbl_0804b5fe @ case 3
    .4byte lbl_0804b5fe @ case 4
    .4byte lbl_0804b5fe @ case 5
    .4byte lbl_0804b5fe @ case 6
    .4byte lbl_0804b5fe @ case 7
    .4byte lbl_0804b58c @ case 8
    .4byte lbl_0804b5c4 @ case 9
    .4byte lbl_0804b5fe @ case 10
    .4byte lbl_0804b5fe @ case 11
    .4byte lbl_0804b5fe @ case 12
    .4byte lbl_0804b5fe @ case 13
    .4byte lbl_0804b568 @ case 14
    .4byte lbl_0804b5fe @ case 15
    .4byte lbl_0804b5fe @ case 16
    .4byte lbl_0804b5fe @ case 17
    .4byte lbl_0804b5fe @ case 18
    .4byte lbl_0804b5fe @ case 19
    .4byte lbl_0804b5fe @ case 20
    .4byte lbl_0804b5fe @ case 21
    .4byte lbl_0804b5fe @ case 22
    .4byte lbl_0804b5fe @ case 23
    .4byte lbl_0804b5fe @ case 24
    .4byte lbl_0804b5fe @ case 25
    .4byte lbl_0804b5fe @ case 26
    .4byte lbl_0804b5fe @ case 27
    .4byte lbl_0804b5fe @ case 28
    .4byte lbl_0804b5fe @ case 29
    .4byte lbl_0804b5fe @ case 30
    .4byte lbl_0804b5fe @ case 31
    .4byte lbl_0804b5fe @ case 32
    .4byte lbl_0804b5fe @ case 33
    .4byte lbl_0804b5fe @ case 34
    .4byte lbl_0804b5fe @ case 35
    .4byte lbl_0804b5fe @ case 36
    .4byte lbl_0804b5fe @ case 37
    .4byte lbl_0804b5fe @ case 38
    .4byte lbl_0804b5fe @ case 39
    .4byte lbl_0804b5fe @ case 40
    .4byte lbl_0804b5fe @ case 41
    .4byte lbl_0804b5fe @ case 42
    .4byte lbl_0804b5fe @ case 43
    .4byte lbl_0804b5fe @ case 44
    .4byte lbl_0804b5fe @ case 45
    .4byte lbl_0804b5fe @ case 46
    .4byte lbl_0804b5fe @ case 47
    .4byte lbl_0804b5fe @ case 48
    .4byte lbl_0804b5fe @ case 49
    .4byte lbl_0804b5e6 @ case 50
lbl_0804b498:
    ldrb r4, [r3, #0x1e]
    adds r5, r4, #0
    movs r0, #0x32
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    movs r0, #1
    movs r1, #0
    orrs r0, r2
    mov r2, ip
    strb r0, [r2]
    ldrh r2, [r3]
    ldr r0, lbl_0804b4f4 @ =0x0000fffb
    ands r0, r2
    movs r2, #0
    strh r0, [r3]
    strh r1, [r3, #0xa]
    strh r1, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r1, [r3, #0x10]
    strh r1, [r3, #0x16]
    strb r2, [r3, #0x1c]
    adds r0, r3, #0
    adds r0, #0x25
    strb r2, [r0]
    cmp r4, #0
    bne lbl_0804b4fc
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #1
    movs r0, #8
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x58
    strb r0, [r1]
    subs r1, #7
    movs r0, #0xa
    strb r0, [r1]
    ldr r0, lbl_0804b4f8 @ =0x0831c438
    str r0, [r3, #0x18]
    adds r1, #2
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0804b5fe
    .align 2, 0
lbl_0804b4f4: .4byte 0x0000fffb
lbl_0804b4f8: .4byte 0x0831c438
lbl_0804b4fc:
    cmp r4, #2
    bne lbl_0804b538
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x30
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x28
    strb r2, [r0]
    adds r1, #2
    movs r0, #0x70
    strb r0, [r1]
    subs r1, #7
    movs r0, #0xd
    strb r0, [r1]
    ldr r0, lbl_0804b534 @ =0x0831c480
    str r0, [r3, #0x18]
    adds r1, #2
    movs r0, #8
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #0xa
    movs r0, #4
    strb r0, [r1]
    b lbl_0804b5fe
    .align 2, 0
lbl_0804b534: .4byte 0x0831c480
lbl_0804b538:
    cmp r5, #3
    bne lbl_0804b5fe
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x10
    strb r0, [r1]
    adds r1, #1
    movs r0, #8
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x60
    strb r0, [r1]
    subs r1, #7
    movs r0, #0xe
    strb r0, [r1]
    ldr r0, lbl_0804b564 @ =0x0831c460
    str r0, [r3, #0x18]
    adds r1, #2
    movs r0, #0x32
    strb r0, [r1]
    b lbl_0804b5fe
    .align 2, 0
lbl_0804b564: .4byte 0x0831c460
lbl_0804b568:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x22
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0804b582
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    b lbl_0804b5fe
lbl_0804b582:
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xa
    strb r0, [r1]
    b lbl_0804b5fe
lbl_0804b58c:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r2, r0, r2
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x25
    bne lbl_0804b5de
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0804b5de
    ldr r0, lbl_0804b5c0 @ =0x0831c490
    str r0, [r3, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r3, #0x16]
    strb r1, [r3, #0x1c]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    b lbl_0804b5de
    .align 2, 0
lbl_0804b5c0: .4byte 0x0831c490
lbl_0804b5c4:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x25
    bls lbl_0804b5de
    ldrb r0, [r3, #0x1c]
    adds r0, #1
    strb r0, [r3, #0x1c]
    movs r0, #4
    b lbl_0804b5e0
lbl_0804b5de:
    movs r0, #8
lbl_0804b5e0:
    bl sub_0804ac00
    b lbl_0804b5fe
lbl_0804b5e6:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x26
    bls lbl_0804b5fe
    ldrh r1, [r3]
    movs r0, #4
    orrs r0, r1
    strh r0, [r3]
lbl_0804b5fe:
    pop {r4, r5}
    pop {r0}
    bx r0
