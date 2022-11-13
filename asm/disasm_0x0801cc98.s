    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start ReoInit
ReoInit: @ 0x0801cc98
    push {r4, r5, lr}
    ldr r4, lbl_0801cd08 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x27
    movs r2, #0
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r5, #0
    ldr r0, lbl_0801cd0c @ =0x0000ffe0
    strh r0, [r4, #0xa]
    movs r0, #0x20
    strh r0, [r4, #0xc]
    ldr r0, lbl_0801cd10 @ =0x0000ffc8
    strh r0, [r4, #0xe]
    movs r0, #0x38
    strh r0, [r4, #0x10]
    ldr r0, lbl_0801cd14 @ =0x082ce214
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r2, [r4, #0x16]
    ldr r2, lbl_0801cd18 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    bl SpriteUtilChooseRandomXDirection
    ldr r0, lbl_0801cd1c @ =0x0300083c
    ldrb r0, [r0]
    cmp r0, #8
    bls lbl_0801ccf8
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
lbl_0801ccf8:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801cd08: .4byte 0x03000738
lbl_0801cd0c: .4byte 0x0000ffe0
lbl_0801cd10: .4byte 0x0000ffc8
lbl_0801cd14: .4byte 0x082ce214
lbl_0801cd18: .4byte 0x082b0d68
lbl_0801cd1c: .4byte 0x0300083c

    thumb_func_start ReoIdleInit
ReoIdleInit: @ 0x0801cd20
    ldr r2, lbl_0801cd3c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_0801cd40 @ =0x0300083c
    ldrb r0, [r0]
    lsls r0, r0, #0x1a
    lsrs r0, r0, #0x18
    adds r1, #0xa
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    bx lr
    .align 2, 0
lbl_0801cd3c: .4byte 0x03000738
lbl_0801cd40: .4byte 0x0300083c

    thumb_func_start ReoIdle
ReoIdle: @ 0x0801cd44
    push {r4, r5, r6, lr}
    ldr r4, lbl_0801cdb8 @ =0x03000738
    movs r0, #0x2f
    adds r0, r0, r4
    mov ip, r0
    ldrb r2, [r0]
    ldr r3, lbl_0801cdbc @ =0x082cd604
    lsls r0, r2, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r5, lbl_0801cdc0 @ =0x00007fff
    cmp r1, r5
    bne lbl_0801cd66
    movs r6, #0
    ldrsh r1, [r3, r6]
    movs r2, #0
lbl_0801cd66:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
    movs r6, #0x2e
    adds r6, r6, r4
    mov ip, r6
    ldrb r2, [r6]
    ldr r3, lbl_0801cdc4 @ =0x082cd686
    lsls r0, r2, #1
    adds r0, r0, r3
    movs r6, #0
    ldrsh r1, [r0, r6]
    cmp r1, r5
    bne lbl_0801cd8e
    movs r0, #0
    ldrsh r1, [r3, r0]
    movs r2, #0
lbl_0801cd8e:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r4, #4]
    adds r0, r0, r1
    strh r0, [r4, #4]
    movs r0, #0x80
    lsls r0, r0, #2
    movs r1, #0xe0
    lsls r1, r1, #1
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    beq lbl_0801cdb2
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
lbl_0801cdb2:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801cdb8: .4byte 0x03000738
lbl_0801cdbc: .4byte 0x082cd604
lbl_0801cdc0: .4byte 0x00007fff
lbl_0801cdc4: .4byte 0x082cd686

    thumb_func_start ReoMovingInit
ReoMovingInit: @ 0x0801cdc8
    push {r4, r5, lr}
    ldr r4, lbl_0801ce24 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x2d
    movs r2, #0
    strb r2, [r0]
    adds r0, #1
    movs r1, #1
    strb r1, [r0]
    subs r0, #2
    strb r2, [r0]
    adds r0, #3
    strb r1, [r0]
    ldr r0, lbl_0801ce28 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    movs r5, #0
    strh r0, [r4, #8]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #0x20
    strh r0, [r4, #0x12]
    ldr r0, lbl_0801ce2c @ =0x082ce284
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r2, [r4, #0x16]
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldrh r2, [r4, #2]
    ldr r1, lbl_0801ce30 @ =0x030013d4
    ldr r0, lbl_0801ce34 @ =0x03001588
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    ldrh r1, [r1, #0x14]
    adds r0, r0, r1
    cmp r2, r0
    ble lbl_0801ce3c
    ldrh r1, [r4]
    ldr r0, lbl_0801ce38 @ =0x0000fbff
    ands r0, r1
    b lbl_0801ce46
    .align 2, 0
lbl_0801ce24: .4byte 0x03000738
lbl_0801ce28: .4byte 0x0300083c
lbl_0801ce2c: .4byte 0x082ce284
lbl_0801ce30: .4byte 0x030013d4
lbl_0801ce34: .4byte 0x03001588
lbl_0801ce38: .4byte 0x0000fbff
lbl_0801ce3c:
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
lbl_0801ce46:
    strh r0, [r4]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ReoMove
ReoMove: @ 0x0801ce50
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_0801cefc @ =0x03000738
    ldrh r1, [r0, #2]
    str r1, [sp]
    ldrh r3, [r0, #4]
    mov r8, r3
    movs r3, #0x28
    ldrb r1, [r0, #0x1d]
    str r1, [sp, #4]
    adds r0, #0x23
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x17
    bhi lbl_0801cf62
    ldr r0, lbl_0801cf00 @ =0x030001ac
    mov sl, r0
lbl_0801ce7e:
    lsls r2, r6, #3
    subs r0, r2, r6
    lsls r0, r0, #3
    mov r1, sl
    adds r4, r0, r1
    ldrh r1, [r4]
    movs r0, #1
    ands r0, r1
    mov sb, r2
    cmp r0, #0
    beq lbl_0801cf58
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0801cf58
    ldrb r0, [r4, #0x1d]
    ldr r1, [sp, #4]
    cmp r0, r1
    bne lbl_0801cf58
    ldrh r7, [r4, #2]
    ldrh r5, [r4, #4]
    ldr r0, [sp]
    adds r1, r0, r3
    subs r0, r7, r3
    cmp r1, r0
    ble lbl_0801cf58
    ldr r0, [sp]
    subs r1, r0, r3
    adds r0, r7, r3
    cmp r1, r0
    bge lbl_0801cf58
    mov r0, r8
    adds r1, r0, r3
    subs r0, r5, r3
    cmp r1, r0
    ble lbl_0801cf58
    mov r0, r8
    subs r1, r0, r3
    adds r0, r5, r3
    cmp r1, r0
    bge lbl_0801cf58
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0801cf62
    ldr r1, [sp]
    cmp r1, r7
    bls lbl_0801cf04
    adds r0, r7, #0
    subs r0, #0x20
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801cf18
    ldrh r0, [r4, #2]
    subs r0, #4
    b lbl_0801cf16
    .align 2, 0
lbl_0801cefc: .4byte 0x03000738
lbl_0801cf00: .4byte 0x030001ac
lbl_0801cf04:
    adds r0, r7, #0
    adds r0, #0x20
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801cf18
    ldrh r0, [r4, #2]
    adds r0, #4
lbl_0801cf16:
    strh r0, [r4, #2]
lbl_0801cf18:
    cmp r8, r5
    bls lbl_0801cf3a
    adds r1, r5, #0
    subs r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801cf62
    mov r3, sb
    subs r1, r3, r6
    lsls r1, r1, #3
    add r1, sl
    ldrh r0, [r1, #4]
    subs r0, #4
    strh r0, [r1, #4]
    b lbl_0801cf62
lbl_0801cf3a:
    adds r1, r5, #0
    adds r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801cf62
    mov r0, sb
    subs r1, r0, r6
    lsls r1, r1, #3
    add r1, sl
    ldrh r0, [r1, #4]
    adds r0, #4
    strh r0, [r1, #4]
    b lbl_0801cf62
lbl_0801cf58:
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0x17
    bls lbl_0801ce7e
lbl_0801cf62:
    ldr r2, lbl_0801cf78 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801cf7c
    ldrh r0, [r2, #2]
    ldrh r1, [r2, #4]
    adds r1, #0x20
    b lbl_0801cf82
    .align 2, 0
lbl_0801cf78: .4byte 0x03000738
lbl_0801cf7c:
    ldrh r0, [r2, #2]
    ldrh r1, [r2, #4]
    subs r1, #0x20
lbl_0801cf82:
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0801cfaa
    ldr r2, lbl_0801cfc0 @ =0x03000738
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    movs r1, #0
    strh r0, [r2]
    adds r0, r2, #0
    adds r0, #0x2d
    strb r1, [r0]
    adds r2, #0x2e
    movs r0, #1
    strb r0, [r2]
lbl_0801cfaa:
    ldr r2, lbl_0801cfc0 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801cfc4
    ldrh r0, [r2, #2]
    adds r0, #0x20
    b lbl_0801cfc8
    .align 2, 0
lbl_0801cfc0: .4byte 0x03000738
lbl_0801cfc4:
    ldrh r0, [r2, #2]
    subs r0, #0x20
lbl_0801cfc8:
    ldrh r1, [r2, #4]
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_0801d010 @ =0x03000738
    cmp r0, #0
    beq lbl_0801cff4
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    eors r0, r1
    movs r1, #0
    strh r0, [r2]
    adds r0, r2, #0
    adds r0, #0x2c
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_0801cff4:
    ldr r1, lbl_0801d014 @ =0x030013d4
    ldrh r0, [r1, #0x14]
    subs r0, #0x48
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldrh r5, [r1, #0x12]
    ldr r0, [sp, #4]
    cmp r0, #0x40
    bne lbl_0801d018
    movs r1, #0x20
    mov r8, r1
    movs r4, #0x40
    b lbl_0801d01e
    .align 2, 0
lbl_0801d010: .4byte 0x03000738
lbl_0801d014: .4byte 0x030013d4
lbl_0801d018:
    movs r3, #0x10
    mov r8, r3
    movs r4, #0x18
lbl_0801d01e:
    ldrh r1, [r2]
    movs r6, #0x80
    lsls r6, r6, #2
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d078
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0801d058
    ldrh r1, [r2, #4]
    subs r0, r5, #4
    cmp r1, r0
    bgt lbl_0801d08a
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r4
    bhs lbl_0801d04c
    adds r0, #1
    strb r0, [r1]
lbl_0801d04c:
    ldrb r0, [r1]
    lsrs r0, r0, #2
    ldrh r1, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    b lbl_0801d0ce
lbl_0801d058:
    subs r1, r0, #1
    strb r1, [r3]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_0801d06c
    lsrs r0, r0, #0x1a
    ldrh r3, [r2, #4]
    adds r0, r0, r3
    strh r0, [r2, #4]
    b lbl_0801d0ce
lbl_0801d06c:
    ldrh r0, [r2]
    ldr r1, lbl_0801d074 @ =0x0000fdff
    ands r1, r0
    b lbl_0801d0c4
    .align 2, 0
lbl_0801d074: .4byte 0x0000fdff
lbl_0801d078:
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0801d0a8
    ldrh r1, [r2, #4]
    adds r0, r5, #4
    cmp r1, r0
    bge lbl_0801d094
lbl_0801d08a:
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r3]
    b lbl_0801d0ce
lbl_0801d094:
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r4
    bhs lbl_0801d0a2
    adds r0, #1
    strb r0, [r1]
lbl_0801d0a2:
    ldrb r1, [r1]
    lsrs r1, r1, #2
    b lbl_0801d0b6
lbl_0801d0a8:
    subs r1, r0, #1
    strb r1, [r3]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_0801d0be
    adds r1, r0, #0
    lsrs r1, r1, #0x1a
lbl_0801d0b6:
    ldrh r0, [r2, #4]
    subs r0, r0, r1
    strh r0, [r2, #4]
    b lbl_0801d0ce
lbl_0801d0be:
    ldrh r0, [r2]
    adds r1, r6, #0
    orrs r1, r0
lbl_0801d0c4:
    strh r1, [r2]
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #1
    strb r0, [r1]
lbl_0801d0ce:
    adds r3, r2, #0
    ldrh r4, [r3]
    movs r5, #0x80
    lsls r5, r5, #3
    adds r0, r5, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_0801d148
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0801d10c
    ldrh r1, [r3, #2]
    subs r0, r7, #4
    cmp r1, r0
    ble lbl_0801d0f8
    adds r0, r3, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_0801d12e
lbl_0801d0f8:
    adds r1, r3, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, r8
    bhs lbl_0801d106
    adds r0, #1
    strb r0, [r1]
lbl_0801d106:
    ldrb r0, [r1]
    lsrs r0, r0, #2
    b lbl_0801d118
lbl_0801d10c:
    subs r1, r0, #1
    strb r1, [r2]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_0801d120
    lsrs r0, r0, #0x1a
lbl_0801d118:
    ldrh r1, [r3, #2]
    adds r0, r0, r1
    strh r0, [r3, #2]
    b lbl_0801d12e
lbl_0801d120:
    ldr r0, lbl_0801d140 @ =0x0000fbff
    ands r0, r4
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_0801d12e:
    ldr r0, lbl_0801d144 @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    ldr r0, [sp]
    movs r3, #1
    bl SpriteUtilCheckInRoomEffect
    b lbl_0801d1ac
    .align 2, 0
lbl_0801d140: .4byte 0x0000fbff
lbl_0801d144: .4byte 0x03000738
lbl_0801d148:
    adds r4, r3, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0801d178
    ldrh r1, [r3, #2]
    adds r0, r7, #4
    cmp r1, r0
    bge lbl_0801d164
    adds r0, r3, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r4]
    b lbl_0801d19e
lbl_0801d164:
    adds r1, r3, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, r8
    bhs lbl_0801d172
    adds r0, #1
    strb r0, [r1]
lbl_0801d172:
    ldrb r1, [r1]
    lsrs r1, r1, #2
    b lbl_0801d186
lbl_0801d178:
    subs r1, r0, #1
    strb r1, [r4]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_0801d18e
    adds r1, r0, #0
    lsrs r1, r1, #0x1a
lbl_0801d186:
    ldrh r0, [r3, #2]
    subs r0, r0, r1
    strh r0, [r3, #2]
    b lbl_0801d19e
lbl_0801d18e:
    ldrh r1, [r2]
    adds r0, r5, #0
    orrs r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_0801d19e:
    ldr r0, lbl_0801d1e0 @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    ldr r0, [sp]
    movs r3, #1
    bl SpriteUtilCheckOutOfRoomEffect
lbl_0801d1ac:
    ldr r1, lbl_0801d1e0 @ =0x03000738
    ldrh r0, [r1, #0x12]
    subs r0, #1
    strh r0, [r1, #0x12]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_0801d1d0
    movs r0, #0x20
    strh r0, [r1, #0x12]
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d1d0
    movs r0, #0xac
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0801d1d0:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d1e0: .4byte 0x03000738

    thumb_func_start Reo
Reo: @ 0x0801d1e4
    push {r4, lr}
    sub sp, #4
    ldr r1, lbl_0801d224 @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x32
    ldrb r2, [r3]
    movs r4, #2
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0801d210
    movs r0, #0xfd
    ands r0, r2
    strb r0, [r3]
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d210
    ldr r0, lbl_0801d228 @ =0x00000159
    bl SoundPlayNotAlreadyPlaying
lbl_0801d210:
    ldr r4, lbl_0801d224 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801d22c
    bl SpriteUtilUpdateFreezeTimer
    b lbl_0801d30a
    .align 2, 0
lbl_0801d224: .4byte 0x03000738
lbl_0801d228: .4byte 0x00000159
lbl_0801d22c:
    bl SpriteUtilIsSpriteStunned
    cmp r0, #0
    bne lbl_0801d30a
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x23
    bhi lbl_0801d2f8
    lsls r0, r0, #2
    ldr r1, lbl_0801d248 @ =lbl_0801d24c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801d248: .4byte lbl_0801d24c
lbl_0801d24c: @ jump table
    .4byte lbl_0801d2dc @ case 0
    .4byte lbl_0801d2f8 @ case 1
    .4byte lbl_0801d2f8 @ case 2
    .4byte lbl_0801d2f8 @ case 3
    .4byte lbl_0801d2f8 @ case 4
    .4byte lbl_0801d2f8 @ case 5
    .4byte lbl_0801d2f8 @ case 6
    .4byte lbl_0801d2f8 @ case 7
    .4byte lbl_0801d2e2 @ case 8
    .4byte lbl_0801d2e8 @ case 9
    .4byte lbl_0801d2f8 @ case 10
    .4byte lbl_0801d2f8 @ case 11
    .4byte lbl_0801d2f8 @ case 12
    .4byte lbl_0801d2f8 @ case 13
    .4byte lbl_0801d2f8 @ case 14
    .4byte lbl_0801d2f8 @ case 15
    .4byte lbl_0801d2f8 @ case 16
    .4byte lbl_0801d2f8 @ case 17
    .4byte lbl_0801d2f8 @ case 18
    .4byte lbl_0801d2f8 @ case 19
    .4byte lbl_0801d2f8 @ case 20
    .4byte lbl_0801d2f8 @ case 21
    .4byte lbl_0801d2f8 @ case 22
    .4byte lbl_0801d2f8 @ case 23
    .4byte lbl_0801d2f8 @ case 24
    .4byte lbl_0801d2f8 @ case 25
    .4byte lbl_0801d2f8 @ case 26
    .4byte lbl_0801d2f8 @ case 27
    .4byte lbl_0801d2f8 @ case 28
    .4byte lbl_0801d2f8 @ case 29
    .4byte lbl_0801d2f8 @ case 30
    .4byte lbl_0801d2f8 @ case 31
    .4byte lbl_0801d2f8 @ case 32
    .4byte lbl_0801d2f8 @ case 33
    .4byte lbl_0801d2ee @ case 34
    .4byte lbl_0801d2f2 @ case 35
lbl_0801d2dc:
    bl ReoInit
    b lbl_0801d30a
lbl_0801d2e2:
    bl ReoIdleInit
    b lbl_0801d30a
lbl_0801d2e8:
    bl ReoIdle
    b lbl_0801d30a
lbl_0801d2ee:
    bl ReoMovingInit
lbl_0801d2f2:
    bl ReoMove
    b lbl_0801d30a
lbl_0801d2f8:
    ldr r0, lbl_0801d314 @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    movs r0, #0x21
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_0801d30a:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d314: .4byte 0x03000738

    thumb_func_start ZiplineCheckColliding
ZiplineCheckColliding: @ 0x0801d318
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_0801d350 @ =0x03000738
    ldrh r0, [r6, #2]
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r3, r5, #0
    ldrh r4, [r6, #4]
    adds r2, r4, #0
    adds r0, r6, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0801d37a
    adds r1, r4, #0
    adds r1, #0x2c
    adds r0, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r7, lbl_0801d354 @ =0x030000dc
    ldrh r0, [r7]
    cmp r0, #7
    bne lbl_0801d35c
    ldrh r1, [r6]
    ldr r0, lbl_0801d358 @ =0x0000fdff
    ands r0, r1
    strh r0, [r6]
    b lbl_0801d39c
    .align 2, 0
lbl_0801d350: .4byte 0x03000738
lbl_0801d354: .4byte 0x030000dc
lbl_0801d358: .4byte 0x0000fdff
lbl_0801d35c:
    adds r1, r4, #0
    subs r1, #0x2c
    adds r0, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldrh r0, [r7]
    cmp r0, #7
    bne lbl_0801d39c
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    b lbl_0801d39c
lbl_0801d37a:
    ldrh r1, [r6]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d392
    adds r1, r4, #0
    adds r1, #0x2c
    adds r0, r5, #0
    bl SpriteUtilCheckCollisionAtPosition
    b lbl_0801d39c
lbl_0801d392:
    adds r1, r2, #0
    subs r1, #0x2c
    adds r0, r3, #0
    bl SpriteUtilCheckCollisionAtPosition
lbl_0801d39c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ZiplineMoving
ZiplineMoving: @ 0x0801d3a4
    push {r4, r5, r6, lr}
    movs r6, #0
    movs r5, #0
    ldr r0, lbl_0801d3c0 @ =0x03000738
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d3c4
    movs r5, #1
    movs r4, #0xc
    b lbl_0801d3c6
    .align 2, 0
lbl_0801d3c0: .4byte 0x03000738
lbl_0801d3c4:
    movs r4, #0x10
lbl_0801d3c6:
    bl ZiplineCheckColliding
    ldr r0, lbl_0801d3f4 @ =0x030000dc
    ldrh r0, [r0]
    cmp r0, #7
    bne lbl_0801d404
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r1, lbl_0801d3f8 @ =0x03000738
    ldrh r2, [r1, #4]
    ldr r0, lbl_0801d3fc @ =0x0000ffc0
    ands r0, r2
    adds r3, r0, #0
    adds r3, #0x20
    strh r3, [r1, #4]
    adds r2, r1, #0
    cmp r5, #0
    beq lbl_0801d43e
    ldr r0, lbl_0801d400 @ =0x030013d4
    strh r3, [r0, #0x12]
    b lbl_0801d43e
    .align 2, 0
lbl_0801d3f4: .4byte 0x030000dc
lbl_0801d3f8: .4byte 0x03000738
lbl_0801d3fc: .4byte 0x0000ffc0
lbl_0801d400: .4byte 0x030013d4
lbl_0801d404:
    ldr r2, lbl_0801d424 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d42c
    ldrh r0, [r2, #4]
    adds r0, r4, r0
    strh r0, [r2, #4]
    cmp r5, #0
    beq lbl_0801d43e
    ldr r1, lbl_0801d428 @ =0x030013d4
    ldrh r0, [r1, #0x12]
    adds r0, r4, r0
    b lbl_0801d43c
    .align 2, 0
lbl_0801d424: .4byte 0x03000738
lbl_0801d428: .4byte 0x030013d4
lbl_0801d42c:
    ldrh r0, [r2, #4]
    subs r0, r0, r4
    strh r0, [r2, #4]
    cmp r5, #0
    beq lbl_0801d43e
    ldr r1, lbl_0801d464 @ =0x030013d4
    ldrh r0, [r1, #0x12]
    subs r0, r0, r4
lbl_0801d43c:
    strh r0, [r1, #0x12]
lbl_0801d43e:
    cmp r6, #0
    beq lbl_0801d45c
    cmp r5, #0
    beq lbl_0801d45c
    ldrh r1, [r2]
    ldr r0, lbl_0801d468 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #0xf
    strb r0, [r1]
    movs r0, #0xfe
    bl SamusSetPose
lbl_0801d45c:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0801d464: .4byte 0x030013d4
lbl_0801d468: .4byte 0x0000f7ff

    thumb_func_start ZiplineUpdateOAM
ZiplineUpdateOAM: @ 0x0801d46c
    push {r4, r5, r6, lr}
    ldr r4, lbl_0801d4a4 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, #0
    bne lbl_0801d482
    b lbl_0801d57c
lbl_0801d482:
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_0801d51c
    adds r5, r4, #0
    adds r5, #0x2d
    ldrb r1, [r5]
    cmp r1, #1
    beq lbl_0801d4c4
    cmp r1, #1
    bgt lbl_0801d4a8
    cmp r1, #0
    beq lbl_0801d4b2
    b lbl_0801d63e
    .align 2, 0
lbl_0801d4a4: .4byte 0x03000738
lbl_0801d4a8:
    cmp r1, #2
    beq lbl_0801d504
    cmp r1, #3
    beq lbl_0801d4e4
    b lbl_0801d63e
lbl_0801d4b2:
    ldr r0, lbl_0801d4c0 @ =0x082ce9b0
    str r0, [r4, #0x18]
    strb r1, [r4, #0x1c]
    strh r1, [r4, #0x16]
    movs r0, #1
    strb r0, [r5]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d4c0: .4byte 0x082ce9b0
lbl_0801d4c4:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0801d4ce
    b lbl_0801d63e
lbl_0801d4ce:
    ldr r0, lbl_0801d4e0 @ =0x082ce9d0
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    movs r0, #2
    strb r0, [r5]
    strh r0, [r4, #0x14]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d4e0: .4byte 0x082ce9d0
lbl_0801d4e4:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0801d4ee
    b lbl_0801d63e
lbl_0801d4ee:
    ldr r0, lbl_0801d500 @ =0x082ce9d0
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    movs r0, #2
    strb r0, [r5]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d500: .4byte 0x082ce9d0
lbl_0801d504:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801d518 @ =0x082ce9d0
    cmp r0, r1
    bne lbl_0801d50e
    b lbl_0801d63e
lbl_0801d50e:
    str r1, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d518: .4byte 0x082ce9d0
lbl_0801d51c:
    adds r6, r4, #0
    adds r6, #0x2d
    ldrb r0, [r6]
    cmp r0, #1
    beq lbl_0801d54c
    cmp r0, #1
    bgt lbl_0801d530
    cmp r0, #0
    beq lbl_0801d53a
    b lbl_0801d63e
lbl_0801d530:
    cmp r0, #2
    beq lbl_0801d568
    cmp r0, #3
    beq lbl_0801d54c
    b lbl_0801d63e
lbl_0801d53a:
    ldr r0, lbl_0801d548 @ =0x082ce928
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #1
    strb r0, [r6]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d548: .4byte 0x082ce928
lbl_0801d54c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801d63e
    ldr r0, lbl_0801d564 @ =0x082ce948
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #2
    strb r0, [r6]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d564: .4byte 0x082ce948
lbl_0801d568:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801d578 @ =0x082ce948
    cmp r0, r1
    beq lbl_0801d63e
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d578: .4byte 0x082ce948
lbl_0801d57c:
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_0801d5e4
    adds r5, r4, #0
    adds r5, #0x2d
    ldrb r1, [r5]
    cmp r1, #1
    beq lbl_0801d5bc
    cmp r1, #1
    bgt lbl_0801d59e
    cmp r1, #0
    beq lbl_0801d5d8
    b lbl_0801d63e
lbl_0801d59e:
    cmp r1, #2
    beq lbl_0801d5a8
    cmp r1, #3
    beq lbl_0801d5bc
    b lbl_0801d63e
lbl_0801d5a8:
    ldr r0, lbl_0801d5b8 @ =0x082cea08
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    strh r6, [r4, #0x16]
    movs r0, #3
    strb r0, [r5]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d5b8: .4byte 0x082cea08
lbl_0801d5bc:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801d63e
    ldr r0, lbl_0801d5d4 @ =0x082ce978
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    movs r0, #0
    strh r6, [r4, #0x16]
    strb r0, [r5]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d5d4: .4byte 0x082ce978
lbl_0801d5d8:
    ldr r0, [r4, #0x18]
    ldr r2, lbl_0801d5e0 @ =0x082ce978
    b lbl_0801d634
    .align 2, 0
lbl_0801d5e0: .4byte 0x082ce978
lbl_0801d5e4:
    adds r6, r4, #0
    adds r6, #0x2d
    ldrb r1, [r6]
    cmp r1, #1
    beq lbl_0801d614
    cmp r1, #1
    bgt lbl_0801d5f8
    cmp r1, #0
    beq lbl_0801d630
    b lbl_0801d63e
lbl_0801d5f8:
    cmp r1, #2
    beq lbl_0801d602
    cmp r1, #3
    beq lbl_0801d614
    b lbl_0801d63e
lbl_0801d602:
    ldr r0, lbl_0801d610 @ =0x082ce958
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #3
    strb r0, [r6]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d610: .4byte 0x082ce958
lbl_0801d614:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801d63e
    ldr r0, lbl_0801d62c @ =0x082ce918
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r0, #0
    strh r5, [r4, #0x16]
    strb r0, [r6]
    b lbl_0801d63e
    .align 2, 0
lbl_0801d62c: .4byte 0x082ce918
lbl_0801d630:
    ldr r0, [r4, #0x18]
    ldr r2, lbl_0801d644 @ =0x082ce918
lbl_0801d634:
    cmp r0, r2
    beq lbl_0801d63e
    str r2, [r4, #0x18]
    strb r1, [r4, #0x1c]
    strh r1, [r4, #0x16]
lbl_0801d63e:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d644: .4byte 0x082ce918

    thumb_func_start ZiplineInit
ZiplineInit: @ 0x0801d648
    push {r4, r5, r6, lr}
    ldr r5, lbl_0801d6c0 @ =0x03000738
    movs r3, #0
    movs r4, #0
    ldr r0, lbl_0801d6c4 @ =0x0000ffc0
    strh r0, [r5, #0xa]
    movs r1, #0x10
    movs r0, #0x10
    strh r0, [r5, #0xc]
    ldr r0, lbl_0801d6c8 @ =0x0000fffc
    strh r0, [r5, #0xe]
    movs r0, #4
    strh r0, [r5, #0x10]
    adds r0, r5, #0
    adds r0, #0x27
    strb r1, [r0]
    adds r1, r5, #0
    adds r1, #0x28
    movs r2, #8
    movs r0, #8
    strb r0, [r1]
    adds r1, #1
    strb r0, [r1]
    subs r1, #4
    movs r0, #0x1a
    strb r0, [r1]
    movs r1, #1
    movs r0, #1
    strh r0, [r5, #0x14]
    movs r0, #0x32
    adds r0, r0, r5
    mov ip, r0
    ldrb r0, [r0]
    orrs r2, r0
    mov r6, ip
    strb r2, [r6]
    adds r2, r5, #0
    adds r2, #0x22
    movs r0, #3
    strb r0, [r2]
    adds r0, r5, #0
    adds r0, #0x21
    strb r1, [r0]
    strb r3, [r5, #0x1c]
    strh r4, [r5, #0x16]
    adds r0, #0xb
    strb r3, [r0]
    adds r0, #1
    strb r3, [r0]
    bl ZiplineCheckColliding
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    beq lbl_0801d6d0
    ldr r0, lbl_0801d6cc @ =0x082ce978
    b lbl_0801d6d2
    .align 2, 0
lbl_0801d6c0: .4byte 0x03000738
lbl_0801d6c4: .4byte 0x0000ffc0
lbl_0801d6c8: .4byte 0x0000fffc
lbl_0801d6cc: .4byte 0x082ce978
lbl_0801d6d0:
    ldr r0, lbl_0801d6e4 @ =0x082ce918
lbl_0801d6d2:
    str r0, [r5, #0x18]
    ldr r0, lbl_0801d6e8 @ =0x03000738
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d6e4: .4byte 0x082ce918
lbl_0801d6e8: .4byte 0x03000738

    thumb_func_start ZiplineUpdate
ZiplineUpdate: @ 0x0801d6ec
    push {r4, r5, lr}
    bl SpriteUtilCheckOnZipline
    cmp r0, #0
    bne lbl_0801d710
    ldr r1, lbl_0801d768 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_0801d710
    ldr r0, lbl_0801d76c @ =0x0000f7ff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0x26
    movs r0, #0xf
    strb r0, [r1]
lbl_0801d710:
    bl ZiplineUpdateOAM
    ldr r4, lbl_0801d768 @ =0x03000738
    ldrh r0, [r4, #0x14]
    cmp r0, #2
    bne lbl_0801d760
    adds r5, r4, #0
    adds r5, #0x2c
    ldrb r1, [r5]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0801d732
    movs r0, #0x88
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801d732:
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    bl ZiplineMoving
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0801d760
    movs r2, #0
    movs r0, #1
    strh r0, [r4, #0x14]
    ldrh r0, [r4]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r4]
    strb r2, [r5]
    movs r0, #0x88
    lsls r0, r0, #1
    movs r1, #4
    bl SoundFade
lbl_0801d760:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d768: .4byte 0x03000738
lbl_0801d76c: .4byte 0x0000f7ff

    thumb_func_start ZiplineButtonInit
ZiplineButtonInit: @ 0x0801d770
    push {r4, lr}
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    beq lbl_0801d78c
    ldr r1, lbl_0801d784 @ =0x03000738
    ldr r0, lbl_0801d788 @ =0x082cea38
    b lbl_0801d790
    .align 2, 0
lbl_0801d784: .4byte 0x03000738
lbl_0801d788: .4byte 0x082cea38
lbl_0801d78c:
    ldr r1, lbl_0801d7fc @ =0x03000738
    ldr r0, lbl_0801d800 @ =0x082cea28
lbl_0801d790:
    str r0, [r1, #0x18]
    mov ip, r1
    mov r1, ip
    ldrh r0, [r1, #2]
    subs r0, #0x80
    movs r2, #0
    movs r3, #0
    strh r0, [r1, #2]
    mov r0, ip
    adds r0, #0x27
    strb r2, [r0]
    adds r1, #0x28
    movs r0, #0x18
    strb r0, [r1]
    mov r4, ip
    adds r4, #0x29
    movs r1, #8
    movs r0, #8
    strb r0, [r4]
    mov r4, ip
    strh r3, [r4, #0xa]
    movs r0, #0x50
    strh r0, [r4, #0xc]
    ldr r0, lbl_0801d804 @ =0x0000ffec
    strh r0, [r4, #0xe]
    movs r0, #0x14
    strh r0, [r4, #0x10]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    movs r2, #1
    movs r0, #1
    strh r0, [r4, #0x14]
    mov r3, ip
    adds r3, #0x32
    ldrb r0, [r3]
    orrs r1, r0
    strb r1, [r3]
    mov r0, ip
    adds r0, #0x24
    strb r2, [r0]
    mov r1, ip
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x21
    strb r2, [r0]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d7fc: .4byte 0x03000738
lbl_0801d800: .4byte 0x082cea28
lbl_0801d804: .4byte 0x0000ffec

    thumb_func_start ZiplineButtonIdleInit
ZiplineButtonIdleInit: @ 0x0801d808
    ldr r1, lbl_0801d820 @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x24
    movs r2, #0
    movs r0, #9
    strb r0, [r3]
    strb r2, [r1, #0x1c]
    strh r2, [r1, #0x16]
    ldr r0, lbl_0801d824 @ =0x082cea38
    str r0, [r1, #0x18]
    bx lr
    .align 2, 0
lbl_0801d820: .4byte 0x03000738
lbl_0801d824: .4byte 0x082cea38

    thumb_func_start ZiplineButtonBindZipline
ZiplineButtonBindZipline: @ 0x0801d828
    push {r4, lr}
    movs r0, #0x3d
    bl SpriteUtilFindPrimary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xff
    bne lbl_0801d844
    ldr r1, lbl_0801d840 @ =0x03000738
    movs r0, #0
    strh r0, [r1]
    b lbl_0801d86c
    .align 2, 0
lbl_0801d840: .4byte 0x03000738
lbl_0801d844:
    ldr r4, lbl_0801d860 @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x2d
    strb r0, [r1]
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    beq lbl_0801d864
    bl ZiplineButtonIdleInit
    b lbl_0801d86c
    .align 2, 0
lbl_0801d860: .4byte 0x03000738
lbl_0801d864:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
lbl_0801d86c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ZiplineButtonOff
ZiplineButtonOff: @ 0x0801d874
    push {lr}
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    beq lbl_0801d886
    bl ZiplineButtonIdleInit
lbl_0801d886:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ZiplineButtonIdle
ZiplineButtonIdle: @ 0x0801d88c
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_0801d8bc @ =0x03000738
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r2, [r1]
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0801d8c8
    ldr r1, lbl_0801d8c0 @ =0x030001ac
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r0, r0, r1
    movs r1, #2
    strh r1, [r0, #0x14]
    movs r4, #1
    ldr r0, lbl_0801d8c4 @ =0x00000111
    bl SoundPlay
    b lbl_0801d8da
    .align 2, 0
lbl_0801d8bc: .4byte 0x03000738
lbl_0801d8c0: .4byte 0x030001ac
lbl_0801d8c4: .4byte 0x00000111
lbl_0801d8c8:
    ldr r0, lbl_0801d8f8 @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r0, [r1, #0x14]
    cmp r0, #2
    bne lbl_0801d8da
    movs r4, #1
lbl_0801d8da:
    cmp r4, #0
    beq lbl_0801d8f2
    ldr r1, lbl_0801d8fc @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x24
    movs r2, #0
    movs r0, #0x23
    strb r0, [r3]
    strb r2, [r1, #0x1c]
    strh r2, [r1, #0x16]
    ldr r0, lbl_0801d900 @ =0x082cea70
    str r0, [r1, #0x18]
lbl_0801d8f2:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d8f8: .4byte 0x030001ac
lbl_0801d8fc: .4byte 0x03000738
lbl_0801d900: .4byte 0x082cea70

    thumb_func_start ZiplineButtonZiplineMoving
ZiplineButtonZiplineMoving: @ 0x0801d904
    push {lr}
    ldr r0, lbl_0801d924 @ =0x03000738
    adds r0, #0x2d
    ldrb r1, [r0]
    ldr r2, lbl_0801d928 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrh r0, [r0, #0x14]
    cmp r0, #1
    bne lbl_0801d920
    bl ZiplineButtonIdleInit
lbl_0801d920:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801d924: .4byte 0x03000738
lbl_0801d928: .4byte 0x030001ac

    thumb_func_start Zipline
Zipline: @ 0x0801d92c
    push {lr}
    ldr r0, lbl_0801d940 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801d944
    cmp r0, #9
    beq lbl_0801d94a
    b lbl_0801d94e
    .align 2, 0
lbl_0801d940: .4byte 0x03000738
lbl_0801d944:
    bl ZiplineInit
    b lbl_0801d94e
lbl_0801d94a:
    bl ZiplineUpdate
lbl_0801d94e:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ZiplineButton
ZiplineButton: @ 0x0801d954
    push {lr}
    ldr r0, lbl_0801d96c @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x23
    bhi lbl_0801da20
    lsls r0, r0, #2
    ldr r1, lbl_0801d970 @ =lbl_0801d974
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801d96c: .4byte 0x03000738
lbl_0801d970: .4byte lbl_0801d974
lbl_0801d974: @ jump table
    .4byte lbl_0801da04 @ case 0
    .4byte lbl_0801da0a @ case 1
    .4byte lbl_0801da20 @ case 2
    .4byte lbl_0801da20 @ case 3
    .4byte lbl_0801da20 @ case 4
    .4byte lbl_0801da20 @ case 5
    .4byte lbl_0801da20 @ case 6
    .4byte lbl_0801da20 @ case 7
    .4byte lbl_0801da20 @ case 8
    .4byte lbl_0801da10 @ case 9
    .4byte lbl_0801da20 @ case 10
    .4byte lbl_0801da20 @ case 11
    .4byte lbl_0801da20 @ case 12
    .4byte lbl_0801da20 @ case 13
    .4byte lbl_0801da20 @ case 14
    .4byte lbl_0801da1c @ case 15
    .4byte lbl_0801da20 @ case 16
    .4byte lbl_0801da20 @ case 17
    .4byte lbl_0801da20 @ case 18
    .4byte lbl_0801da20 @ case 19
    .4byte lbl_0801da20 @ case 20
    .4byte lbl_0801da20 @ case 21
    .4byte lbl_0801da20 @ case 22
    .4byte lbl_0801da20 @ case 23
    .4byte lbl_0801da20 @ case 24
    .4byte lbl_0801da20 @ case 25
    .4byte lbl_0801da20 @ case 26
    .4byte lbl_0801da20 @ case 27
    .4byte lbl_0801da20 @ case 28
    .4byte lbl_0801da20 @ case 29
    .4byte lbl_0801da20 @ case 30
    .4byte lbl_0801da20 @ case 31
    .4byte lbl_0801da20 @ case 32
    .4byte lbl_0801da20 @ case 33
    .4byte lbl_0801da20 @ case 34
    .4byte lbl_0801da16 @ case 35
lbl_0801da04:
    bl ZiplineButtonInit
    b lbl_0801da20
lbl_0801da0a:
    bl ZiplineButtonBindZipline
    b lbl_0801da20
lbl_0801da10:
    bl ZiplineButtonIdle
    b lbl_0801da20
lbl_0801da16:
    bl ZiplineButtonZiplineMoving
    b lbl_0801da20
lbl_0801da1c:
    bl ZiplineButtonOff
lbl_0801da20:
    pop {r0}
    bx r0

    thumb_func_start SovaCheckCollidingWithAir
SovaCheckCollidingWithAir: @ 0x0801da24
    push {r4, r5, r6, lr}
    movs r6, #0
    ldr r4, lbl_0801da58 @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801da84
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0801da60
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_0801da5c @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0801dad0
    ldrh r0, [r4, #2]
    adds r0, #0x20
    ldrh r1, [r4, #4]
    b lbl_0801dac4
    .align 2, 0
lbl_0801da58: .4byte 0x03000738
lbl_0801da5c: .4byte 0x030007f1
lbl_0801da60:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_0801da80 @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0801dad0
    ldrh r0, [r4, #2]
    adds r0, #0x20
    ldrh r1, [r4, #4]
    subs r1, #4
    b lbl_0801dac4
    .align 2, 0
lbl_0801da80: .4byte 0x030007f1
lbl_0801da84:
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801daac
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_0801daa8 @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0801dad0
    ldrh r0, [r4, #2]
    subs r0, #4
    b lbl_0801dac0
    .align 2, 0
lbl_0801daa8: .4byte 0x030007f1
lbl_0801daac:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_0801dad8 @ =0x030007f1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0801dad0
    ldrh r0, [r4, #2]
lbl_0801dac0:
    ldrh r1, [r4, #4]
    adds r1, #0x20
lbl_0801dac4:
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0801dad0
    movs r6, #1
lbl_0801dad0:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0801dad8: .4byte 0x030007f1

    thumb_func_start SovaUpdateHitbox
SovaUpdateHitbox: @ 0x0801dadc
    push {lr}
    ldr r1, lbl_0801db04 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    cmp r0, #0
    beq lbl_0801db28
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_0801db10
    ldr r0, lbl_0801db08 @ =0x0000ffe4
    strh r0, [r1, #0xa]
    movs r0, #0x1c
    strh r0, [r1, #0xc]
    ldr r0, lbl_0801db0c @ =0x0000ffcc
    strh r0, [r1, #0xe]
    movs r0, #4
    b lbl_0801db4e
    .align 2, 0
lbl_0801db04: .4byte 0x03000738
lbl_0801db08: .4byte 0x0000ffe4
lbl_0801db0c: .4byte 0x0000ffcc
lbl_0801db10:
    ldr r0, lbl_0801db20 @ =0x0000ffe4
    strh r0, [r1, #0xa]
    movs r0, #0x1c
    strh r0, [r1, #0xc]
    ldr r0, lbl_0801db24 @ =0x0000fffc
    strh r0, [r1, #0xe]
    movs r0, #0x34
    b lbl_0801db4e
    .align 2, 0
lbl_0801db20: .4byte 0x0000ffe4
lbl_0801db24: .4byte 0x0000fffc
lbl_0801db28:
    adds r0, r1, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801db40
    ldr r0, lbl_0801db3c @ =0x0000fffc
    strh r0, [r1, #0xa]
    movs r0, #0x34
    b lbl_0801db46
    .align 2, 0
lbl_0801db3c: .4byte 0x0000fffc
lbl_0801db40:
    ldr r0, lbl_0801db54 @ =0x0000ffcc
    strh r0, [r1, #0xa]
    movs r0, #4
lbl_0801db46:
    strh r0, [r1, #0xc]
    ldr r0, lbl_0801db58 @ =0x0000ffe4
    strh r0, [r1, #0xe]
    movs r0, #0x1c
lbl_0801db4e:
    strh r0, [r1, #0x10]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801db54: .4byte 0x0000ffcc
lbl_0801db58: .4byte 0x0000ffe4

    thumb_func_start SovaSetCrawlingOAM
SovaSetCrawlingOAM: @ 0x0801db5c
    push {lr}
    ldr r1, lbl_0801db7c @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    cmp r0, #0
    beq lbl_0801db90
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0801db84
    ldr r0, lbl_0801db80 @ =0x082cfc78
    str r0, [r1, #0x18]
    b lbl_0801dbc6
    .align 2, 0
lbl_0801db7c: .4byte 0x03000738
lbl_0801db80: .4byte 0x082cfc78
lbl_0801db84:
    ldr r0, lbl_0801db8c @ =0x082cfc40
    str r0, [r1, #0x18]
    b lbl_0801dbc6
    .align 2, 0
lbl_0801db8c: .4byte 0x082cfc40
lbl_0801db90:
    adds r0, r1, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801dba4
    ldr r0, lbl_0801dba0 @ =0x082cfcb0
    b lbl_0801dba6
    .align 2, 0
lbl_0801dba0: .4byte 0x082cfcb0
lbl_0801dba4:
    ldr r0, lbl_0801dbbc @ =0x082cfb98
lbl_0801dba6:
    str r0, [r1, #0x18]
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0801dbc0
    movs r0, #0x40
    orrs r0, r2
    b lbl_0801dbc4
    .align 2, 0
lbl_0801dbbc: .4byte 0x082cfb98
lbl_0801dbc0:
    ldr r0, lbl_0801dbd0 @ =0x0000ffbf
    ands r0, r2
lbl_0801dbc4:
    strh r0, [r1]
lbl_0801dbc6:
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801dbd0: .4byte 0x0000ffbf

    thumb_func_start SovaInit
SovaInit: @ 0x0801dbd4
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_0801dc0c @ =0x03000738
    adds r7, r4, #0
    adds r7, #0x2e
    movs r0, #0
    strb r0, [r7]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    bl SpriteUtilChooseRandomXDirection
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r5, lbl_0801dc10 @ =0x030007f1
    ldrb r1, [r5]
    movs r6, #0xf0
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dc18
    ldrh r1, [r4]
    ldr r0, lbl_0801dc14 @ =0x0000fbff
    ands r0, r1
    strh r0, [r4]
    b lbl_0801dca8
    .align 2, 0
lbl_0801dc0c: .4byte 0x03000738
lbl_0801dc10: .4byte 0x030007f1
lbl_0801dc14: .4byte 0x0000fbff
lbl_0801dc18:
    ldrh r0, [r4, #2]
    subs r0, #0x44
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r1, [r5]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dc44
    ldrh r1, [r4]
    ldr r0, lbl_0801dc40 @ =0x0000fbff
    ands r0, r1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    subs r0, #0x40
    strh r0, [r4, #2]
    movs r0, #1
    strb r0, [r7]
    b lbl_0801dca8
    .align 2, 0
lbl_0801dc40: .4byte 0x0000fbff
lbl_0801dc44:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    subs r1, #0x24
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r1, [r5]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dc72
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0x20
    b lbl_0801dca6
lbl_0801dc72:
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r5]
    adds r2, r6, #0
    ands r2, r0
    cmp r2, #0
    bne lbl_0801dc8c
    strh r2, [r4]
    b lbl_0801dd14
lbl_0801dc8c:
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r0, r1
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    adds r0, #0x20
lbl_0801dca6:
    strh r0, [r4, #4]
lbl_0801dca8:
    ldr r2, lbl_0801dcc8 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    adds r4, r2, #0
    cmp r0, #0
    bne lbl_0801dcd2
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dccc
    movs r0, #0x40
    orrs r0, r1
    b lbl_0801dcd0
    .align 2, 0
lbl_0801dcc8: .4byte 0x03000738
lbl_0801dccc:
    ldr r0, lbl_0801dd1c @ =0x0000ffbf
    ands r0, r1
lbl_0801dcd0:
    strh r0, [r4]
lbl_0801dcd2:
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    bl SovaSetCrawlingOAM
    bl SovaUpdateHitbox
    ldr r2, lbl_0801dd20 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x33
    bne lbl_0801dd14
    adds r0, r4, #0
    adds r0, #0x34
    movs r1, #1
    strb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
lbl_0801dd14:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801dd1c: .4byte 0x0000ffbf
lbl_0801dd20: .4byte 0x082b0d68

    thumb_func_start SovaIdleInit
SovaIdleInit: @ 0x0801dd24
    push {lr}
    bl SovaSetCrawlingOAM
    ldr r0, lbl_0801dd38 @ =0x03000738
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801dd38: .4byte 0x03000738

    thumb_func_start SovaMove
SovaMove: @ 0x0801dd3c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0801dd54 @ =0x03000738
    ldrh r0, [r0, #0x16]
    cmp r0, #3
    beq lbl_0801dd66
    cmp r0, #3
    bgt lbl_0801dd58
    cmp r0, #2
    beq lbl_0801dd62
    b lbl_0801dd76
    .align 2, 0
lbl_0801dd54: .4byte 0x03000738
lbl_0801dd58:
    cmp r0, #4
    beq lbl_0801dd6c
    cmp r0, #5
    beq lbl_0801dd70
    b lbl_0801dd76
lbl_0801dd62:
    movs r0, #1
    b lbl_0801dd78
lbl_0801dd66:
    movs r1, #2
    mov r8, r1
    b lbl_0801dd7a
lbl_0801dd6c:
    movs r0, #3
    b lbl_0801dd78
lbl_0801dd70:
    movs r1, #1
    mov r8, r1
    b lbl_0801dd7a
lbl_0801dd76:
    movs r0, #0
lbl_0801dd78:
    mov r8, r0
lbl_0801dd7a:
    ldr r0, lbl_0801dda8 @ =0x03000738
    ldrb r0, [r0, #0x1d]
    cmp r0, #0x33
    bne lbl_0801dd92
    mov r1, r8
    cmp r1, #0
    beq lbl_0801dd92
    mov r0, r8
    adds r0, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
lbl_0801dd92:
    movs r5, #0
    bl SovaCheckCollidingWithAir
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0801ddac
    ldr r0, lbl_0801dda8 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    b lbl_0801e1d2
    .align 2, 0
lbl_0801dda8: .4byte 0x03000738
lbl_0801ddac:
    bl SpriteUtilIsSpriteOnScreenAndScreenShake
    cmp r0, #0
    beq lbl_0801dddc
    ldr r2, lbl_0801ddd8 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0801ddce
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0801ddce
    b lbl_0801e1d4
lbl_0801ddce:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x1e
    strb r0, [r1]
    b lbl_0801e1d4
    .align 2, 0
lbl_0801ddd8: .4byte 0x03000738
lbl_0801dddc:
    ldr r4, lbl_0801de1c @ =0x03000738
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0801ddec
    b lbl_0801df56
lbl_0801ddec:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dea0
    movs r6, #0x80
    lsls r6, r6, #2
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801de44
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r7, lbl_0801de20 @ =0x030007f1
    ldrb r1, [r7]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    bne lbl_0801de24
    ldrh r1, [r4]
    adds r0, r6, #0
    orrs r0, r1
    b lbl_0801de8c
    .align 2, 0
lbl_0801de1c: .4byte 0x03000738
lbl_0801de20: .4byte 0x030007f1
lbl_0801de24:
    ldrh r0, [r4, #2]
    adds r0, #0x1c
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r7]
    cmp r0, #0x11
    bne lbl_0801deec
    ldrh r1, [r4]
    ldr r0, lbl_0801de40 @ =0x0000fdff
    ands r0, r1
    b lbl_0801de60
    .align 2, 0
lbl_0801de40: .4byte 0x0000fdff
lbl_0801de44:
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r7, lbl_0801de70 @ =0x030007f1
    ldrb r1, [r7]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    bne lbl_0801de74
    ldrh r1, [r4]
    adds r0, r6, #0
    orrs r0, r1
lbl_0801de60:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #5
    strb r0, [r1]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801de70: .4byte 0x030007f1
lbl_0801de74:
    ldrh r0, [r4, #2]
    subs r0, #0x1c
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r7]
    cmp r0, #0x11
    bne lbl_0801df4c
    ldrh r1, [r4]
    ldr r0, lbl_0801de9c @ =0x0000fdff
    ands r0, r1
lbl_0801de8c:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #7
    strb r0, [r1]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801de9c: .4byte 0x0000fdff
lbl_0801dea0:
    movs r7, #0x80
    lsls r7, r7, #2
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801def4
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0801decc @ =0x030007f1
    ldrb r1, [r6]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    bne lbl_0801ded4
    ldrh r1, [r4]
    ldr r0, lbl_0801ded0 @ =0x0000fdff
    ands r0, r1
    b lbl_0801df3e
    .align 2, 0
lbl_0801decc: .4byte 0x030007f1
lbl_0801ded0: .4byte 0x0000fdff
lbl_0801ded4:
    ldrh r0, [r4, #2]
    adds r0, #0x1c
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0x11
    bne lbl_0801deec
    ldrh r1, [r4]
    adds r0, r7, #0
    orrs r0, r1
    b lbl_0801df12
lbl_0801deec:
    ldrh r0, [r4, #2]
    add r0, r8
    strh r0, [r4, #2]
    b lbl_0801e1c8
lbl_0801def4:
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0801df20 @ =0x030007f1
    ldrb r1, [r6]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    bne lbl_0801df28
    ldrh r1, [r4]
    ldr r0, lbl_0801df24 @ =0x0000fdff
    ands r0, r1
lbl_0801df12:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #4
    strb r0, [r1]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801df20: .4byte 0x030007f1
lbl_0801df24: .4byte 0x0000fdff
lbl_0801df28:
    ldrh r0, [r4, #2]
    subs r0, #0x1c
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0x11
    bne lbl_0801df4c
    ldrh r1, [r4]
    adds r0, r7, #0
    orrs r0, r1
lbl_0801df3e:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #6
    strb r0, [r1]
    b lbl_0801e1c8
lbl_0801df4c:
    ldrh r0, [r4, #2]
    mov r1, r8
    subs r0, r0, r1
    strh r0, [r4, #2]
    b lbl_0801e1c8
lbl_0801df56:
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801e00a
    movs r7, #0x80
    lsls r7, r7, #2
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801dfae
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0801df8c @ =0x030007f1
    ldrb r1, [r6]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0801df94
    ldrh r1, [r4]
    ldr r0, lbl_0801df90 @ =0x0000fdff
    ands r0, r1
    b lbl_0801dffc
    .align 2, 0
lbl_0801df8c: .4byte 0x030007f1
lbl_0801df90: .4byte 0x0000fdff
lbl_0801df94:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, #0x1c
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0x11
    beq lbl_0801dfa6
    b lbl_0801e140
lbl_0801dfa6:
    ldrh r1, [r4]
    adds r0, r7, #0
    orrs r0, r1
    b lbl_0801dfcc
lbl_0801dfae:
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0801dfdc @ =0x030007f1
    ldrb r1, [r6]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0801dfe4
    ldrh r1, [r4]
    ldr r0, lbl_0801dfe0 @ =0x0000fdff
    ands r0, r1
lbl_0801dfcc:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #3
    strb r0, [r1]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801dfdc: .4byte 0x030007f1
lbl_0801dfe0: .4byte 0x0000fdff
lbl_0801dfe4:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #0x1c
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0x11
    beq lbl_0801dff6
    b lbl_0801e190
lbl_0801dff6:
    ldrh r1, [r4]
    adds r0, r7, #0
    orrs r0, r1
lbl_0801dffc:
    strh r0, [r4]
    movs r5, #1
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #2
    strb r0, [r1]
    b lbl_0801e1c8
lbl_0801e00a:
    bl unk_f594
    ldr r0, lbl_0801e044 @ =0x030007f0
    ldrb r2, [r0]
    adds r1, r2, #0
    cmp r1, #0
    beq lbl_0801e022
    movs r0, #0xf0
    ands r0, r2
    cmp r0, #0
    bne lbl_0801e022
    b lbl_0801e118
lbl_0801e022:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801e048 @ =0x082cfb98
    cmp r0, r1
    beq lbl_0801e052
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e04c
    movs r0, #0x40
    orrs r0, r1
    b lbl_0801e050
    .align 2, 0
lbl_0801e044: .4byte 0x030007f0
lbl_0801e048: .4byte 0x082cfb98
lbl_0801e04c:
    ldr r0, lbl_0801e08c @ =0x0000ffbf
    ands r0, r1
lbl_0801e050:
    strh r0, [r4]
lbl_0801e052:
    ldr r4, lbl_0801e090 @ =0x03000738
    ldrh r1, [r4]
    movs r6, #0x80
    lsls r6, r6, #2
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e0b8
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r7, lbl_0801e094 @ =0x030007f1
    ldrb r0, [r7]
    cmp r0, #0
    bne lbl_0801e098
    ldrh r1, [r4]
    movs r2, #0
    adds r0, r6, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    adds r0, r4, #0
    adds r0, #0x2d
    strb r2, [r0]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801e08c: .4byte 0x0000ffbf
lbl_0801e090: .4byte 0x03000738
lbl_0801e094: .4byte 0x030007f1
lbl_0801e098:
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    adds r1, #0x1c
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r7]
    cmp r0, #0x11
    bne lbl_0801e140
    ldrh r1, [r4]
    ldr r0, lbl_0801e0b4 @ =0x0000fdff
    ands r0, r1
    b lbl_0801e0d0
    .align 2, 0
lbl_0801e0b4: .4byte 0x0000fdff
lbl_0801e0b8:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #4
    bl SpriteUtilCheckCollisionAtPosition
    ldr r7, lbl_0801e0e4 @ =0x030007f1
    ldrb r0, [r7]
    cmp r0, #0
    bne lbl_0801e0e8
    ldrh r1, [r4]
    adds r0, r6, #0
    orrs r0, r1
lbl_0801e0d0:
    strh r0, [r4]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #1
    strb r0, [r1]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801e0e4: .4byte 0x030007f1
lbl_0801e0e8:
    ldrh r0, [r4, #2]
    subs r0, #4
    ldrh r1, [r4, #4]
    subs r1, #0x1c
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r7]
    cmp r0, #0x11
    bne lbl_0801e190
    ldrh r1, [r4]
    ldr r0, lbl_0801e114 @ =0x0000fdff
    ands r0, r1
    movs r1, #0
    strh r0, [r4]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    adds r0, r4, #0
    adds r0, #0x2d
    strb r1, [r0]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801e114: .4byte 0x0000fdff
lbl_0801e118:
    ldrh r2, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0801e174
    cmp r1, #2
    beq lbl_0801e12c
    cmp r1, #4
    bne lbl_0801e14c
lbl_0801e12c:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801e148 @ =0x082cfc08
    cmp r0, r1
    beq lbl_0801e140
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #0x40
    orrs r0, r2
    strh r0, [r4]
lbl_0801e140:
    ldrh r0, [r4, #4]
    add r0, r8
    strh r0, [r4, #4]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801e148: .4byte 0x082cfc08
lbl_0801e14c:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801e170 @ =0x082cfbd0
    cmp r0, r1
    beq lbl_0801e160
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #0x40
    orrs r0, r2
    strh r0, [r4]
lbl_0801e160:
    mov r1, r8
    lsls r0, r1, #1
    movs r1, #3
    bl __divsi3
    ldrh r1, [r4, #4]
    adds r1, r1, r0
    b lbl_0801e1c6
    .align 2, 0
lbl_0801e170: .4byte 0x082cfbd0
lbl_0801e174:
    cmp r1, #3
    beq lbl_0801e17c
    cmp r1, #5
    bne lbl_0801e1a4
lbl_0801e17c:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801e19c @ =0x082cfc08
    cmp r0, r1
    beq lbl_0801e190
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldr r0, lbl_0801e1a0 @ =0x0000ffbf
    ands r0, r2
    strh r0, [r4]
lbl_0801e190:
    ldrh r0, [r4, #4]
    mov r1, r8
    subs r0, r0, r1
    strh r0, [r4, #4]
    b lbl_0801e1c8
    .align 2, 0
lbl_0801e19c: .4byte 0x082cfc08
lbl_0801e1a0: .4byte 0x0000ffbf
lbl_0801e1a4:
    ldr r0, [r4, #0x18]
    ldr r1, lbl_0801e1e0 @ =0x082cfbd0
    cmp r0, r1
    beq lbl_0801e1b8
    str r1, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldr r0, lbl_0801e1e4 @ =0x0000ffbf
    ands r0, r2
    strh r0, [r4]
lbl_0801e1b8:
    mov r1, r8
    lsls r0, r1, #1
    movs r1, #3
    bl __divsi3
    ldrh r1, [r4, #4]
    subs r1, r1, r0
lbl_0801e1c6:
    strh r1, [r4, #4]
lbl_0801e1c8:
    cmp r5, #0
    beq lbl_0801e1d4
    ldr r0, lbl_0801e1e8 @ =0x03000738
    adds r0, #0x24
    movs r1, #0xa
lbl_0801e1d2:
    strb r1, [r0]
lbl_0801e1d4:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801e1e0: .4byte 0x082cfbd0
lbl_0801e1e4: .4byte 0x0000ffbf
lbl_0801e1e8: .4byte 0x03000738

    thumb_func_start SovaTurningAroundInit
SovaTurningAroundInit: @ 0x0801e1ec
    push {r4, lr}
    ldr r3, lbl_0801e218 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r4, #0
    movs r0, #0xb
    strb r0, [r1]
    strb r4, [r3, #0x1c]
    strh r4, [r3, #0x16]
    adds r0, r3, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    adds r2, r3, #0
    cmp r0, #7
    bls lbl_0801e20c
    b lbl_0801e378
lbl_0801e20c:
    lsls r0, r0, #2
    ldr r1, lbl_0801e21c @ =lbl_0801e220
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801e218: .4byte 0x03000738
lbl_0801e21c: .4byte lbl_0801e220
lbl_0801e220: @ jump table
    .4byte lbl_0801e240 @ case 0
    .4byte lbl_0801e268 @ case 1
    .4byte lbl_0801e284 @ case 2
    .4byte lbl_0801e2ac @ case 3
    .4byte lbl_0801e2c8 @ case 4
    .4byte lbl_0801e2f0 @ case 5
    .4byte lbl_0801e320 @ case 6
    .4byte lbl_0801e348 @ case 7
lbl_0801e240:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e254
    ldr r0, lbl_0801e250 @ =0x082cfce8
    b lbl_0801e256
    .align 2, 0
lbl_0801e250: .4byte 0x082cfce8
lbl_0801e254:
    ldr r0, lbl_0801e260 @ =0x082cfd28
lbl_0801e256:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    ldr r1, lbl_0801e264 @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e30e
    .align 2, 0
lbl_0801e260: .4byte 0x082cfd28
lbl_0801e264: .4byte 0x0000ffbf
lbl_0801e268:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e27c
    ldr r0, lbl_0801e278 @ =0x082cfce8
    b lbl_0801e306
    .align 2, 0
lbl_0801e278: .4byte 0x082cfce8
lbl_0801e27c:
    ldr r0, lbl_0801e280 @ =0x082cfd28
    b lbl_0801e306
    .align 2, 0
lbl_0801e280: .4byte 0x082cfd28
lbl_0801e284:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e298
    ldr r0, lbl_0801e294 @ =0x082cfd28
    b lbl_0801e29a
    .align 2, 0
lbl_0801e294: .4byte 0x082cfd28
lbl_0801e298:
    ldr r0, lbl_0801e2a4 @ =0x082cfce8
lbl_0801e29a:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    ldr r1, lbl_0801e2a8 @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e366
    .align 2, 0
lbl_0801e2a4: .4byte 0x082cfce8
lbl_0801e2a8: .4byte 0x0000ffbf
lbl_0801e2ac:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e2c0
    ldr r0, lbl_0801e2bc @ =0x082cfd28
    b lbl_0801e35e
    .align 2, 0
lbl_0801e2bc: .4byte 0x082cfd28
lbl_0801e2c0:
    ldr r0, lbl_0801e2c4 @ =0x082cfce8
    b lbl_0801e35e
    .align 2, 0
lbl_0801e2c4: .4byte 0x082cfce8
lbl_0801e2c8:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e2dc
    ldr r0, lbl_0801e2d8 @ =0x082cfd48
    b lbl_0801e2de
    .align 2, 0
lbl_0801e2d8: .4byte 0x082cfd48
lbl_0801e2dc:
    ldr r0, lbl_0801e2e8 @ =0x082cfd08
lbl_0801e2de:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    ldr r1, lbl_0801e2ec @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e30e
    .align 2, 0
lbl_0801e2e8: .4byte 0x082cfd08
lbl_0801e2ec: .4byte 0x0000ffbf
lbl_0801e2f0:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e304
    ldr r0, lbl_0801e300 @ =0x082cfd08
    b lbl_0801e306
    .align 2, 0
lbl_0801e300: .4byte 0x082cfd08
lbl_0801e304:
    ldr r0, lbl_0801e318 @ =0x082cfd48
lbl_0801e306:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    movs r1, #0x40
    orrs r1, r0
lbl_0801e30e:
    ldr r0, lbl_0801e31c @ =0x0000feff
    ands r1, r0
    strh r1, [r2]
    b lbl_0801e37a
    .align 2, 0
lbl_0801e318: .4byte 0x082cfd48
lbl_0801e31c: .4byte 0x0000feff
lbl_0801e320:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e334
    ldr r0, lbl_0801e330 @ =0x082cfd48
    b lbl_0801e336
    .align 2, 0
lbl_0801e330: .4byte 0x082cfd48
lbl_0801e334:
    ldr r0, lbl_0801e340 @ =0x082cfd08
lbl_0801e336:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    ldr r1, lbl_0801e344 @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e366
    .align 2, 0
lbl_0801e340: .4byte 0x082cfd08
lbl_0801e344: .4byte 0x0000ffbf
lbl_0801e348:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e35c
    ldr r0, lbl_0801e358 @ =0x082cfd08
    b lbl_0801e35e
    .align 2, 0
lbl_0801e358: .4byte 0x082cfd08
lbl_0801e35c:
    ldr r0, lbl_0801e374 @ =0x082cfd48
lbl_0801e35e:
    str r0, [r2, #0x18]
    ldrh r0, [r2]
    movs r1, #0x40
    orrs r1, r0
lbl_0801e366:
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r1, r0
    strh r1, [r2]
    b lbl_0801e37a
    .align 2, 0
lbl_0801e374: .4byte 0x082cfd48
lbl_0801e378:
    strh r4, [r3]
lbl_0801e37a:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start SovaTurningAround
SovaTurningAround: @ 0x0801e380
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0801e38c
    b lbl_0801e56c
lbl_0801e38c:
    ldr r3, lbl_0801e3bc @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldrh r1, [r3]
    ldr r0, lbl_0801e3c0 @ =0x0000feff
    ands r0, r1
    movs r1, #0
    strh r0, [r3]
    adds r0, r3, #0
    adds r0, #0x2e
    strb r1, [r0]
    subs r0, #1
    ldrb r0, [r0]
    adds r2, r3, #0
    cmp r0, #7
    bls lbl_0801e3b2
    b lbl_0801e560
lbl_0801e3b2:
    lsls r0, r0, #2
    ldr r1, lbl_0801e3c4 @ =lbl_0801e3c8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801e3bc: .4byte 0x03000738
lbl_0801e3c0: .4byte 0x0000feff
lbl_0801e3c4: .4byte lbl_0801e3c8
lbl_0801e3c8: @ jump table
    .4byte lbl_0801e3e8 @ case 0
    .4byte lbl_0801e414 @ case 1
    .4byte lbl_0801e426 @ case 2
    .4byte lbl_0801e450 @ case 3
    .4byte lbl_0801e484 @ case 4
    .4byte lbl_0801e4ac @ case 5
    .4byte lbl_0801e4f8 @ case 6
    .4byte lbl_0801e51c @ case 7
lbl_0801e3e8:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0801e402
    ldrh r0, [r2, #2]
    subs r0, #0x18
    strh r0, [r2, #2]
    ldrh r1, [r2, #4]
    ldr r0, lbl_0801e40c @ =0x0000ffc0
    ands r0, r1
    strh r0, [r2, #4]
lbl_0801e402:
    ldrh r0, [r2]
    ldr r1, lbl_0801e410 @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e472
    .align 2, 0
lbl_0801e40c: .4byte 0x0000ffc0
lbl_0801e410: .4byte 0x0000ffbf
lbl_0801e414:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0801e46c
    ldrh r0, [r2, #2]
    subs r0, #0x1c
    b lbl_0801e460
lbl_0801e426:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e440
    ldrh r0, [r2, #2]
    adds r0, #0x18
    strh r0, [r2, #2]
    ldrh r1, [r2, #4]
    ldr r0, lbl_0801e448 @ =0x0000ffc0
    ands r0, r1
    strh r0, [r2, #4]
lbl_0801e440:
    ldrh r0, [r2]
    ldr r1, lbl_0801e44c @ =0x0000ffbf
    ands r1, r0
    b lbl_0801e472
    .align 2, 0
lbl_0801e448: .4byte 0x0000ffc0
lbl_0801e44c: .4byte 0x0000ffbf
lbl_0801e450:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e46c
    ldrh r0, [r2, #2]
    adds r0, #0x1c
lbl_0801e460:
    strh r0, [r2, #2]
    ldrh r1, [r2, #4]
    ldr r0, lbl_0801e480 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x40
    strh r0, [r2, #4]
lbl_0801e46c:
    ldrh r0, [r2]
    movs r1, #0x40
    orrs r1, r0
lbl_0801e472:
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r3, #0
    orrs r1, r0
    strh r1, [r2]
    b lbl_0801e564
    .align 2, 0
lbl_0801e480: .4byte 0x0000ffc0
lbl_0801e484:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_0801e4d4
    ldrh r0, [r2, #4]
    adds r0, #0x1c
    strh r0, [r2, #4]
    ldrh r1, [r2, #2]
    ldr r0, lbl_0801e4a8 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x40
    strh r0, [r2, #2]
    movs r0, #0x40
    orrs r0, r3
    b lbl_0801e4e0
    .align 2, 0
lbl_0801e4a8: .4byte 0x0000ffc0
lbl_0801e4ac:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    bne lbl_0801e4d4
    ldrh r0, [r2, #4]
    subs r0, #0x1c
    strh r0, [r2, #4]
    ldrh r1, [r2, #2]
    ldr r0, lbl_0801e4d0 @ =0x0000ffc0
    ands r0, r1
    adds r0, #0x40
    strh r0, [r2, #2]
    movs r0, #0x40
    orrs r0, r3
    b lbl_0801e4e0
    .align 2, 0
lbl_0801e4d0: .4byte 0x0000ffc0
lbl_0801e4d4:
    ldrh r0, [r2, #2]
    ldr r1, lbl_0801e4ec @ =0x0000ffc0
    ands r1, r0
    strh r1, [r2, #2]
    ldr r0, lbl_0801e4f0 @ =0x0000ffbf
    ands r0, r3
lbl_0801e4e0:
    strh r0, [r2]
    ldrh r1, [r2]
    ldr r0, lbl_0801e4f4 @ =0x0000fbff
    ands r0, r1
    strh r0, [r2]
    b lbl_0801e564
    .align 2, 0
lbl_0801e4ec: .4byte 0x0000ffc0
lbl_0801e4f0: .4byte 0x0000ffbf
lbl_0801e4f4: .4byte 0x0000fbff
lbl_0801e4f8:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_0801e540
    ldrh r1, [r2, #2]
    ldr r0, lbl_0801e518 @ =0x0000ffc0
    ands r0, r1
    strh r0, [r2, #2]
    ldrh r0, [r2, #4]
    adds r0, #0x18
    strh r0, [r2, #4]
    movs r0, #0x40
    orrs r0, r3
    b lbl_0801e544
    .align 2, 0
lbl_0801e518: .4byte 0x0000ffc0
lbl_0801e51c:
    ldrh r3, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r3
    cmp r0, #0
    bne lbl_0801e540
    ldrh r1, [r2, #2]
    ldr r0, lbl_0801e53c @ =0x0000ffc0
    ands r0, r1
    strh r0, [r2, #2]
    ldrh r0, [r2, #4]
    subs r0, #0x1c
    strh r0, [r2, #4]
    movs r0, #0x40
    orrs r0, r3
    b lbl_0801e544
    .align 2, 0
lbl_0801e53c: .4byte 0x0000ffc0
lbl_0801e540:
    ldr r0, lbl_0801e558 @ =0x0000ffbf
    ands r0, r3
lbl_0801e544:
    strh r0, [r2]
    ldrh r1, [r2]
    ldr r0, lbl_0801e55c @ =0x0000fbff
    ands r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #1
    strb r0, [r1]
    b lbl_0801e564
    .align 2, 0
lbl_0801e558: .4byte 0x0000ffbf
lbl_0801e55c: .4byte 0x0000fbff
lbl_0801e560:
    movs r0, #0
    strh r0, [r3]
lbl_0801e564:
    bl SovaSetCrawlingOAM
    bl SovaUpdateHitbox
lbl_0801e56c:
    pop {r0}
    bx r0

    thumb_func_start SovaLandingInit
SovaLandingInit: @ 0x0801e570
    push {r4, lr}
    ldr r4, lbl_0801e59c @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0xf
    strb r0, [r1]
    ldr r0, lbl_0801e5a0 @ =0x082cfd68
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r2, [r4, #0x16]
    bl SpriteUtilChooseRandomXDirection
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e5a4
    movs r0, #0x40
    orrs r0, r1
    b lbl_0801e5a8
    .align 2, 0
lbl_0801e59c: .4byte 0x03000738
lbl_0801e5a0: .4byte 0x082cfd68
lbl_0801e5a4:
    ldr r0, lbl_0801e5b0 @ =0x0000ffbf
    ands r0, r1
lbl_0801e5a8:
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801e5b0: .4byte 0x0000ffbf

    thumb_func_start SovaLandingInit_anim
SovaLandingInit_anim: @ 0x0801e5b4
    push {lr}
    bl SovaCheckCollidingWithAir
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0801e5cc
    ldr r0, lbl_0801e5c8 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x1e
    b lbl_0801e5da
    .align 2, 0
lbl_0801e5c8: .4byte 0x03000738
lbl_0801e5cc:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801e5dc
    ldr r0, lbl_0801e5e0 @ =0x03000738
    adds r0, #0x24
    movs r1, #8
lbl_0801e5da:
    strb r1, [r0]
lbl_0801e5dc:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801e5e0: .4byte 0x03000738

    thumb_func_start SovaFallingInit
SovaFallingInit: @ 0x0801e5e4
    push {r4, r5, r6, lr}
    ldr r1, lbl_0801e608 @ =0x03000738
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0801e614
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_0801e60c
    ldrh r0, [r6, #4]
    subs r0, #0x20
    strh r0, [r6, #4]
    b lbl_0801e624
    .align 2, 0
lbl_0801e608: .4byte 0x03000738
lbl_0801e60c:
    ldrh r0, [r6, #4]
    adds r0, #0x20
    strh r0, [r6, #4]
    b lbl_0801e624
lbl_0801e614:
    adds r0, r6, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801e624
    ldrh r0, [r6, #2]
    adds r0, #0x28
    strh r0, [r6, #2]
lbl_0801e624:
    adds r1, r6, #0
    adds r1, #0x24
    movs r4, #0
    movs r0, #0x1f
    strb r0, [r1]
    adds r0, r6, #0
    adds r0, #0x2f
    strb r4, [r0]
    subs r0, #1
    strb r4, [r0]
    ldrh r1, [r6]
    ldr r0, lbl_0801e654 @ =0x0000fabf
    ands r0, r1
    movs r5, #0
    strh r0, [r6]
    bl SovaUpdateHitbox
    ldr r0, lbl_0801e658 @ =0x082cfd68
    str r0, [r6, #0x18]
    strb r5, [r6, #0x1c]
    strh r4, [r6, #0x16]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801e654: .4byte 0x0000fabf
lbl_0801e658: .4byte 0x082cfd68

    thumb_func_start SovaFalling
SovaFalling: @ 0x0801e65c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0801e68c @ =0x03000738
    ldrh r6, [r0, #2]
    movs r1, #0x2f
    adds r1, r1, r0
    mov ip, r1
    ldrb r2, [r1]
    ldr r5, lbl_0801e690 @ =0x082b0d04
    lsls r1, r2, #1
    adds r1, r1, r5
    movs r4, #0
    ldrsh r3, [r1, r4]
    ldr r1, lbl_0801e694 @ =0x00007fff
    adds r4, r0, #0
    cmp r3, r1
    bne lbl_0801e698
    subs r0, r2, #1
    lsls r0, r0, #1
    adds r0, r0, r5
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, r6, r0
    b lbl_0801e6a2
    .align 2, 0
lbl_0801e68c: .4byte 0x03000738
lbl_0801e690: .4byte 0x082b0d04
lbl_0801e694: .4byte 0x00007fff
lbl_0801e698:
    adds r0, r2, #1
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #2]
    adds r0, r0, r3
lbl_0801e6a2:
    strh r0, [r4, #2]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0801e6c0 @ =0x030007f0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801e6c4
    strh r1, [r4, #2]
    bl SovaLandingInit
    b lbl_0801e6d0
    .align 2, 0
lbl_0801e6c0: .4byte 0x030007f0
lbl_0801e6c4:
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r6, #0
    movs r3, #2
    bl SpriteUtilCheckInRoomEffect
lbl_0801e6d0:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SovaDeath
SovaDeath: @ 0x0801e6d8
    push {r4, lr}
    sub sp, #4
    ldr r3, lbl_0801e6fc @ =0x03000738
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    ldrh r4, [r3]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r4
    cmp r0, #0
    beq lbl_0801e70a
    movs r0, #0x40
    ands r0, r4
    cmp r0, #0
    beq lbl_0801e700
    adds r0, r2, #0
    subs r0, #0x28
    b lbl_0801e704
    .align 2, 0
lbl_0801e6fc: .4byte 0x03000738
lbl_0801e700:
    adds r0, r2, #0
    adds r0, #0x28
lbl_0801e704:
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    b lbl_0801e722
lbl_0801e70a:
    adds r0, r3, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801e71a
    adds r0, r1, #0
    adds r0, #0x28
    b lbl_0801e71e
lbl_0801e71a:
    adds r0, r1, #0
    subs r0, #0x28
lbl_0801e71e:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
lbl_0801e722:
    movs r0, #0x20
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start Sova
Sova: @ 0x0801e738
    push {r4, lr}
    ldr r1, lbl_0801e778 @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x32
    ldrb r2, [r3]
    movs r4, #2
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0801e764
    movs r0, #0xfd
    ands r0, r2
    strb r0, [r3]
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801e764
    movs r0, #0xaa
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0801e764:
    ldr r4, lbl_0801e778 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801e77c
    bl SpriteUtilUpdateFreezeTimer
    b lbl_0801e84e
    .align 2, 0
lbl_0801e778: .4byte 0x03000738
lbl_0801e77c:
    bl SpriteUtilIsSpriteStunned
    cmp r0, #0
    bne lbl_0801e84e
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x1f
    bhi lbl_0801e84a
    lsls r0, r0, #2
    ldr r1, lbl_0801e798 @ =lbl_0801e79c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801e798: .4byte lbl_0801e79c
lbl_0801e79c: @ jump table
    .4byte lbl_0801e81c @ case 0
    .4byte lbl_0801e84a @ case 1
    .4byte lbl_0801e84a @ case 2
    .4byte lbl_0801e84a @ case 3
    .4byte lbl_0801e84a @ case 4
    .4byte lbl_0801e84a @ case 5
    .4byte lbl_0801e84a @ case 6
    .4byte lbl_0801e84a @ case 7
    .4byte lbl_0801e822 @ case 8
    .4byte lbl_0801e826 @ case 9
    .4byte lbl_0801e82c @ case 10
    .4byte lbl_0801e830 @ case 11
    .4byte lbl_0801e84a @ case 12
    .4byte lbl_0801e84a @ case 13
    .4byte lbl_0801e836 @ case 14
    .4byte lbl_0801e83a @ case 15
    .4byte lbl_0801e84a @ case 16
    .4byte lbl_0801e84a @ case 17
    .4byte lbl_0801e84a @ case 18
    .4byte lbl_0801e84a @ case 19
    .4byte lbl_0801e84a @ case 20
    .4byte lbl_0801e84a @ case 21
    .4byte lbl_0801e84a @ case 22
    .4byte lbl_0801e84a @ case 23
    .4byte lbl_0801e84a @ case 24
    .4byte lbl_0801e84a @ case 25
    .4byte lbl_0801e84a @ case 26
    .4byte lbl_0801e84a @ case 27
    .4byte lbl_0801e84a @ case 28
    .4byte lbl_0801e84a @ case 29
    .4byte lbl_0801e840 @ case 30
    .4byte lbl_0801e844 @ case 31
lbl_0801e81c:
    bl SovaInit
    b lbl_0801e84e
lbl_0801e822:
    bl SovaIdleInit
lbl_0801e826:
    bl SovaMove
    b lbl_0801e84e
lbl_0801e82c:
    bl SovaTurningAroundInit
lbl_0801e830:
    bl SovaTurningAround
    b lbl_0801e84e
lbl_0801e836:
    bl SovaLandingInit
lbl_0801e83a:
    bl SovaLandingInit_anim
    b lbl_0801e84e
lbl_0801e840:
    bl SovaFallingInit
lbl_0801e844:
    bl SovaFalling
    b lbl_0801e84e
lbl_0801e84a:
    bl SovaDeath
lbl_0801e84e:
    pop {r4}
    pop {r0}
    bx r0
