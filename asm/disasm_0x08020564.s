    .include "asm/macros.inc"

    .syntax unified

    
    thumb_func_start DragonYMovement
DragonYMovement: @ 0x08020564
    push {r4, r5, lr}
    ldr r2, lbl_08020594 @ =0x03000738
    ldrh r3, [r2, #2]
    adds r5, r3, #0
    ldrh r4, [r2, #6]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08020598
    adds r0, r4, #0
    subs r0, #0x7f
    cmp r0, r3
    bge lbl_08020586
    subs r0, r3, #2
    strh r0, [r2, #2]
lbl_08020586:
    ldrh r1, [r2, #2]
    ldrh r2, [r2, #4]
    adds r0, r3, #0
    movs r3, #1
    bl SpriteUtilCheckOutOfRoomEffect
    b lbl_080205ae
    .align 2, 0
lbl_08020594: .4byte 0x03000738
lbl_08020598:
    subs r0, r4, #2
    cmp r0, r3
    ble lbl_080205a2
    adds r0, r3, #2
    strh r0, [r2, #2]
lbl_080205a2:
    ldrh r1, [r2, #2]
    ldrh r2, [r2, #4]
    adds r0, r5, #0
    movs r3, #1
    bl SpriteUtilCheckInRoomEffect
lbl_080205ae:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start DragonInit
DragonInit: @ 0x080205b4
    push {r4, lr}
    ldr r4, lbl_08020614 @ =0x03000738
    movs r2, #0
    movs r3, #0
    ldr r0, lbl_08020618 @ =0x0000ffc0
    strh r0, [r4, #0xa]
    movs r0, #0x50
    strh r0, [r4, #0xc]
    ldr r0, lbl_0802061c @ =0x0000ffe8
    strh r0, [r4, #0xe]
    movs r1, #0x18
    movs r0, #0x18
    strh r0, [r4, #0x10]
    adds r0, r4, #0
    adds r0, #0x27
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_08020620 @ =0x082d5ad8
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    ldr r2, lbl_08020624 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    bl SpriteUtilMakeSpriteFaceSamusXFlip
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #2]
    strh r0, [r4, #6]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020614: .4byte 0x03000738
lbl_08020618: .4byte 0x0000ffc0
lbl_0802061c: .4byte 0x0000ffe8
lbl_08020620: .4byte 0x082d5ad8
lbl_08020624: .4byte 0x082b0d68

    thumb_func_start DragonIdleInit
DragonIdleInit: @ 0x08020628
    ldr r0, lbl_08020648 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #9
    strb r1, [r2]
    ldr r1, lbl_0802064c @ =0x082d5ad8
    str r1, [r0, #0x18]
    movs r1, #0
    strh r3, [r0, #0x16]
    strb r1, [r0, #0x1c]
    adds r0, #0x2c
    movs r1, #0x64
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08020648: .4byte 0x03000738
lbl_0802064c: .4byte 0x082d5ad8

    thumb_func_start DragonGoUp
DragonGoUp: @ 0x08020650
    push {r4, lr}
    ldr r4, lbl_080206a8 @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08020662
    subs r0, #1
    strb r0, [r1]
lbl_08020662:
    bl DragonYMovement
    ldrh r1, [r4]
    ldr r0, lbl_080206ac @ =0x0000fbff
    ands r0, r1
    strh r0, [r4]
    ldr r0, lbl_080206b0 @ =0x030013d4
    ldrh r0, [r0, #0x14]
    ldrh r1, [r4, #2]
    cmp r0, r1
    bhi lbl_08020712
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r1, #0
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    beq lbl_08020696
    ldrh r0, [r4]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r4]
lbl_08020696:
    cmp r2, #8
    bne lbl_080206b4
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    bne lbl_080206cc
    b lbl_080206c2
    .align 2, 0
lbl_080206a8: .4byte 0x03000738
lbl_080206ac: .4byte 0x0000fbff
lbl_080206b0: .4byte 0x030013d4
lbl_080206b4:
    cmp r2, #4
    bne lbl_08020712
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080206cc
lbl_080206c2:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xa
    strb r0, [r1]
    b lbl_08020712
lbl_080206cc:
    ldr r2, lbl_080206f0 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08020712
    ldrh r0, [r2, #2]
    subs r0, #0x88
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080206f4
    ldrh r0, [r2, #4]
    adds r0, #0x48
    b lbl_080206f8
    .align 2, 0
lbl_080206f0: .4byte 0x03000738
lbl_080206f4:
    ldrh r0, [r2, #4]
    subs r0, #0x48
lbl_080206f8:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r0, r3, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08020718 @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08020712
    ldr r0, lbl_0802071c @ =0x03000738
    adds r0, #0x24
    movs r1, #0x34
    strb r1, [r0]
lbl_08020712:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020718: .4byte 0x030007f1
lbl_0802071c: .4byte 0x03000738

    thumb_func_start dragon_turning_around_gfx_init
dragon_turning_around_gfx_init: @ 0x08020720
    ldr r1, lbl_08020738 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0xb
    strb r0, [r2]
    ldr r0, lbl_0802073c @ =0x082d5b28
    str r0, [r1, #0x18]
    movs r0, #0
    strh r3, [r1, #0x16]
    strb r0, [r1, #0x1c]
    bx lr
    .align 2, 0
lbl_08020738: .4byte 0x03000738
lbl_0802073c: .4byte 0x082d5b28

    thumb_func_start DragonCheckTurningAroundFirstHalfAnimEnded
DragonCheckTurningAroundFirstHalfAnimEnded: @ 0x08020740
    push {lr}
    bl DragonYMovement
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802076c
    ldr r2, lbl_08020770 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r3, #0
    movs r0, #0xc
    strb r0, [r1]
    ldr r0, lbl_08020774 @ =0x082d5b40
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    ldrh r0, [r2]
    movs r1, #0x40
    eors r0, r1
    strh r0, [r2]
lbl_0802076c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020770: .4byte 0x03000738
lbl_08020774: .4byte 0x082d5b40

    thumb_func_start DragonCheckTurningAroundSecondHalfAnimEnded
DragonCheckTurningAroundSecondHalfAnimEnded: @ 0x08020778
    push {lr}
    bl DragonYMovement
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802078e
    ldr r0, lbl_08020794 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x34
    strb r1, [r0]
lbl_0802078e:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020794: .4byte 0x03000738

    thumb_func_start DragonWarningInit
DragonWarningInit: @ 0x08020798
    ldr r0, lbl_080207b8 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x35
    strb r1, [r2]
    ldr r1, lbl_080207bc @ =0x082d5af8
    str r1, [r0, #0x18]
    movs r1, #0
    strh r3, [r0, #0x16]
    strb r1, [r0, #0x1c]
    adds r0, #0x2c
    movs r1, #0x1e
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_080207b8: .4byte 0x03000738
lbl_080207bc: .4byte 0x082d5af8

    thumb_func_start DragonWarning
DragonWarning: @ 0x080207c0
    push {r4, lr}
    bl DragonYMovement
    ldr r2, lbl_080207f8 @ =0x03000738
    adds r4, r2, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    subs r0, #1
    strb r0, [r4]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_080207f0
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x37
    strb r0, [r1]
    ldr r0, lbl_080207fc @ =0x082d5b10
    str r0, [r2, #0x18]
    movs r0, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    movs r0, #8
    strb r0, [r4]
lbl_080207f0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080207f8: .4byte 0x03000738
lbl_080207fc: .4byte 0x082d5b10

    thumb_func_start DragonSpit
DragonSpit: @ 0x08020800
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r4, lbl_08020834 @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08020862
    bl DragonIdleInit
    ldrh r0, [r4, #2]
    subs r0, #0x48
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08020838
    ldrh r0, [r4, #4]
    adds r0, #0x28
    b lbl_0802083c
    .align 2, 0
lbl_08020834: .4byte 0x03000738
lbl_08020838:
    ldrh r0, [r4, #4]
    subs r0, #0x28
lbl_0802083c:
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_0802086c @ =0x03000738
    ldrb r2, [r0, #0x1f]
    adds r3, r0, #0
    adds r3, #0x23
    ldrb r3, [r3]
    str r5, [sp]
    str r1, [sp, #4]
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #8]
    movs r0, #8
    movs r1, #0
    bl SpriteSpawnSecondary
lbl_08020862:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802086c: .4byte 0x03000738

    thumb_func_start DragonFireballInit
DragonFireballInit: @ 0x08020870
    push {r4, r5, lr}
    ldr r3, lbl_0802090c @ =0x03000738
    ldrh r0, [r3]
    ldr r4, lbl_08020910 @ =0x0000fffb
    ands r4, r0
    movs r5, #0
    movs r2, #0
    strh r4, [r3]
    movs r0, #0x32
    adds r0, r0, r3
    mov ip, r0
    ldrb r1, [r0]
    movs r0, #4
    orrs r0, r1
    mov r1, ip
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_08020914 @ =0x0000fff0
    strh r1, [r3, #0xa]
    movs r0, #0x10
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    ldr r0, lbl_08020918 @ =0x082d5b58
    str r0, [r3, #0x18]
    strb r5, [r3, #0x1c]
    strh r2, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r1, #1
    movs r0, #6
    strb r0, [r1]
    subs r1, #3
    movs r0, #3
    strb r0, [r1]
    ldr r1, lbl_0802091c @ =0x03000088
    ldrb r1, [r1, #0xc]
    ands r0, r1
    adds r1, r3, #0
    adds r1, #0x21
    strb r0, [r1]
    ldr r2, lbl_08020920 @ =0x082b1be4
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r3, #0x14]
    movs r0, #0x40
    ands r0, r4
    cmp r0, #0
    beq lbl_08020928
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r0, #0
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x2a
    movs r0, #0x40
    strb r0, [r1]
    ldrh r1, [r3]
    ldr r0, lbl_08020924 @ =0x0000ffbf
    ands r0, r1
    strh r0, [r3]
    b lbl_0802092e
    .align 2, 0
lbl_0802090c: .4byte 0x03000738
lbl_08020910: .4byte 0x0000fffb
lbl_08020914: .4byte 0x0000fff0
lbl_08020918: .4byte 0x082d5b58
lbl_0802091c: .4byte 0x03000088
lbl_08020920: .4byte 0x082b1be4
lbl_08020924: .4byte 0x0000ffbf
lbl_08020928:
    adds r0, r3, #0
    adds r0, #0x2a
    strb r5, [r0]
lbl_0802092e:
    ldrh r1, [r3]
    movs r0, #0x80
    movs r2, #0
    orrs r0, r1
    strh r0, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r3, #0x12]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r2, [r0]
    movs r0, #0xa6
    lsls r0, r0, #1
    bl SoundPlay
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DragonFireballMove
DragonFireballMove: @ 0x08020954
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r0, #0xc
    mov sb, r0
    ldr r2, lbl_080209a0 @ =0x03000738
    ldrh r1, [r2, #2]
    mov r8, r1
    movs r4, #0x2f
    adds r4, r4, r2
    mov ip, r4
    ldrb r3, [r4]
    ldr r7, lbl_080209a4 @ =0x082d5134
    lsls r0, r3, #1
    adds r1, r0, r7
    movs r4, #0
    ldrsh r1, [r1, r4]
    ldr r6, lbl_080209a8 @ =0x082d5184
    adds r0, r0, r6
    movs r4, #0
    ldrsh r5, [r0, r4]
    ldr r0, lbl_080209ac @ =0x00007fff
    adds r4, r2, #0
    cmp r1, r0
    bne lbl_080209b0
    subs r0, r3, #1
    lsls r0, r0, #1
    adds r1, r0, r7
    movs r2, #0
    ldrsh r1, [r1, r2]
    adds r0, r0, r6
    movs r2, #0
    ldrsh r5, [r0, r2]
    add r1, r8
    strh r1, [r4, #2]
    b lbl_080209bc
    .align 2, 0
lbl_080209a0: .4byte 0x03000738
lbl_080209a4: .4byte 0x082d5134
lbl_080209a8: .4byte 0x082d5184
lbl_080209ac: .4byte 0x00007fff
lbl_080209b0:
    adds r0, r3, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
lbl_080209bc:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080209d4
    ldrh r0, [r4, #4]
    add r0, sb
    strh r0, [r4, #4]
    adds r0, r5, #0
    adds r0, #0x40
    b lbl_080209de
lbl_080209d4:
    ldrh r0, [r4, #4]
    mov r1, sb
    subs r0, r0, r1
    strh r0, [r4, #4]
    rsbs r0, r5, #0
lbl_080209de:
    adds r1, r4, #0
    adds r1, #0x2a
    strb r0, [r1]
    adds r5, r4, #0
    ldrh r1, [r5, #2]
    ldrh r2, [r5, #4]
    mov r0, r8
    movs r3, #0
    bl SpriteUtilCheckInRoomEffect
    cmp r0, #0
    beq lbl_080209fa
    adds r1, r5, #0
    b lbl_08020a10
lbl_080209fa:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_08020a24 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_08020a16
    adds r1, r4, #0
lbl_08020a10:
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_08020a16:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020a24: .4byte 0x030007f1

    thumb_func_start DragonFireballExplodingInit
DragonFireballExplodingInit: @ 0x08020a28
    ldr r2, lbl_08020a58 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x26
    movs r1, #0
    movs r0, #1
    strb r0, [r3]
    ldr r0, lbl_08020a5c @ =0x082d5b78
    str r0, [r2, #0x18]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
    ldrh r1, [r2]
    ldr r0, lbl_08020a60 @ =0x0000ff7f
    ands r0, r1
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
    bx lr
    .align 2, 0
lbl_08020a58: .4byte 0x03000738
lbl_08020a5c: .4byte 0x082d5b78
lbl_08020a60: .4byte 0x0000ff7f

    thumb_func_start DragonFireballCheckExplodingAnimEnded
DragonFireballCheckExplodingAnimEnded: @ 0x08020a64
    push {r4, lr}
    ldr r4, lbl_08020a84 @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08020a7c
    movs r0, #0
    strh r0, [r4]
lbl_08020a7c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020a84: .4byte 0x03000738

    thumb_func_start Dragon
Dragon: @ 0x08020a88
    push {r4, lr}
    sub sp, #4
    ldr r1, lbl_08020ac8 @ =0x03000738
    adds r3, r1, #0
    adds r3, #0x32
    ldrb r2, [r3]
    movs r4, #2
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_08020ab4
    movs r0, #0xfd
    ands r0, r2
    strb r0, [r3]
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08020ab4
    ldr r0, lbl_08020acc @ =0x0000014d
    bl SoundPlayNotAlreadyPlaying
lbl_08020ab4:
    ldr r4, lbl_08020ac8 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08020ad0
    bl SpriteUtilUpdateFreezeTimer
    b lbl_08020c16
    .align 2, 0
lbl_08020ac8: .4byte 0x03000738
lbl_08020acc: .4byte 0x0000014d
lbl_08020ad0:
    bl SpriteUtilIsSpriteStunned
    cmp r0, #0
    beq lbl_08020ada
    b lbl_08020c16
lbl_08020ada:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x37
    bls lbl_08020ae6
    b lbl_08020c04
lbl_08020ae6:
    lsls r0, r0, #2
    ldr r1, lbl_08020af0 @ =lbl_08020af4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08020af0: .4byte lbl_08020af4
lbl_08020af4: @ jump table
    .4byte lbl_08020bd4 @ case 0
    .4byte lbl_08020c04 @ case 1
    .4byte lbl_08020c04 @ case 2

    thumb_func_start DeoremThorn
DeoremThorn: @ 0x08020b00
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r2, r3, #0xf
    lsrs r2, r0, #0x20
    lsrs r6, r3, #0xf
    lsrs r2, r0, #0x20
    lsrs r4, r4, #0xf
    lsrs r2, r0, #0x20
    lsrs r0, r5, #0xf
    lsrs r2, r0, #0x20
    lsrs r6, r5, #0xf
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r4, r6, #0xf
    lsrs r2, r0, #0x20
    lsrs r0, r7, #0xf
    lsrs r2, r0, #0x20
    lsrs r4, r0, #0x10
    lsrs r2, r0, #0x20
    lsrs r6, r7, #0xf
    lsrs r2, r0, #0x20
lbl_08020bd4:
    bl DragonInit
    b lbl_08020c16
lbl_08020bda:
    bl DragonIdleInit
lbl_08020bde:
    bl DragonGoUp
    b lbl_08020c16
lbl_08020be4:
    bl dragon_turning_around_gfx_init
lbl_08020be8:
    bl DragonCheckTurningAroundFirstHalfAnimEnded
    b lbl_08020c16
lbl_08020bee:
    bl DragonCheckTurningAroundSecondHalfAnimEnded
    b lbl_08020c16
lbl_08020bf4:
    bl DragonWarningInit
lbl_08020bf8:
    bl DragonWarning
    b lbl_08020c16
lbl_08020bfe:
    bl DragonSpit
    b lbl_08020c16
lbl_08020c04:
    ldr r0, lbl_08020c20 @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    movs r0, #0x21
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_08020c16:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020c20: .4byte 0x03000738

    thumb_func_start DragonFireball
DragonFireball: @ 0x08020c24
    push {lr}
    sub sp, #4
    ldr r1, lbl_08020c44 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r2, r1, #0
    cmp r0, #0x42
    beq lbl_08020c58
    cmp r0, #0x42
    bgt lbl_08020c48
    cmp r0, #0
    beq lbl_08020c4e
    cmp r0, #9
    beq lbl_08020c52
    b lbl_08020c64
    .align 2, 0
lbl_08020c44: .4byte 0x03000738
lbl_08020c48:
    cmp r0, #0x43
    beq lbl_08020c5e
    b lbl_08020c64
lbl_08020c4e:
    bl DragonFireballInit
lbl_08020c52:
    bl DragonFireballMove
    b lbl_08020c74
lbl_08020c58:
    bl DragonFireballExplodingInit
    b lbl_08020c74
lbl_08020c5e:
    bl DragonFireballCheckExplodingAnimEnded
    b lbl_08020c74
lbl_08020c64:
    ldrh r1, [r2, #2]
    ldrh r2, [r2, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_08020c74:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start deorem_left_change_ccaa
deorem_left_change_ccaa: @ 0x08020c7c
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r0, lbl_08020cf8 @ =0x0300080c
    ldrh r7, [r0]
    ldrh r6, [r0, #2]
    ldr r5, lbl_08020cfc @ =0x03000079
    strb r4, [r5]
    adds r0, r7, #0
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    adds r0, r7, #0
    adds r0, #0x40
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    adds r0, r7, #0
    adds r0, #0x80
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    adds r0, r7, #0
    adds r0, #0xc0
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    movs r1, #0x80
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r6, #0
    bl ClipdataProcess
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020cf8: .4byte 0x0300080c
lbl_08020cfc: .4byte 0x03000079

    thumb_func_start deorem_right_change_ccaa
deorem_right_change_ccaa: @ 0x08020d00
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    ldr r0, lbl_08020d88 @ =0x0300080c
    ldrh r7, [r0]
    movs r1, #0xd0
    lsls r1, r1, #2
    adds r4, r1, #0
    ldrh r0, [r0, #2]
    adds r4, r4, r0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldr r6, lbl_08020d8c @ =0x03000079
    strb r5, [r6]
    adds r0, r7, #0
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r0, r7, #0
    adds r0, #0x40
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r0, r7, #0
    adds r0, #0x80
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    adds r0, r7, #0
    adds r0, #0xc0
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r1, #0x80
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r4, #0
    bl ClipdataProcess
    strb r5, [r6]
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r4, #0
    bl ClipdataProcess
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020d88: .4byte 0x0300080c
lbl_08020d8c: .4byte 0x03000079

    thumb_func_start sub_08020d90
sub_08020d90: @ 0x08020d90
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r7, r6, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r5, r4, #0
    ldr r2, lbl_08020de4 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08020e10
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08020dec
    subs r0, r4, #4
    ldrh r1, [r2, #4]
    cmp r1, r0
    bgt lbl_08020e24
    adds r3, r2, #0
    adds r3, #0x2e
    ldrb r0, [r3]
    cmp r0, r6
    bhs lbl_08020dce
    adds r0, #1
    strb r0, [r3]
lbl_08020dce:
    ldr r0, lbl_08020de8 @ =0x0300080c
    ldrh r0, [r0, #2]
    movs r4, #0xa0
    lsls r4, r4, #2
    adds r0, r0, r4
    cmp r1, r0
    bge lbl_08020e5a
    ldrb r0, [r3]
    asrs r0, r0, #1
    adds r0, r1, r0
    b lbl_08020e58
    .align 2, 0
lbl_08020de4: .4byte 0x03000738
lbl_08020de8: .4byte 0x0300080c
lbl_08020dec:
    cmp r1, #1
    bls lbl_08020df4
    subs r0, #1
    strb r0, [r3]
lbl_08020df4:
    ldrh r1, [r2, #4]
    ldr r0, lbl_08020e0c @ =0x0300080c
    ldrh r0, [r0, #2]
    movs r4, #0xa0
    lsls r4, r4, #2
    adds r0, r0, r4
    cmp r1, r0
    bge lbl_08020e5a
    ldrb r0, [r3]
    asrs r0, r0, #1
    adds r0, r1, r0
    b lbl_08020e58
    .align 2, 0
lbl_08020e0c: .4byte 0x0300080c
lbl_08020e10:
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08020e3e
    adds r0, r5, #4
    ldrh r1, [r2, #4]
    cmp r1, r0
    bge lbl_08020e2e
lbl_08020e24:
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r3]
    b lbl_08020e5a
lbl_08020e2e:
    adds r3, r2, #0
    adds r3, #0x2e
    ldrb r0, [r3]
    cmp r0, r7
    bhs lbl_08020e48
    adds r0, #1
    strb r0, [r3]
    b lbl_08020e48
lbl_08020e3e:
    cmp r1, #1
    bls lbl_08020e46
    subs r0, #1
    strb r0, [r3]
lbl_08020e46:
    ldrh r1, [r2, #4]
lbl_08020e48:
    ldr r0, lbl_08020e60 @ =0x0300080c
    ldrh r0, [r0, #2]
    adds r0, #0xc0
    cmp r1, r0
    ble lbl_08020e5a
    ldrb r0, [r3]
    asrs r0, r0, #1
    subs r0, r1, r0
lbl_08020e58:
    strh r0, [r2, #4]
lbl_08020e5a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08020e60: .4byte 0x0300080c

    thumb_func_start DeoremRandomSpriteDebris
DeoremRandomSpriteDebris: @ 0x08020e64
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldr r1, lbl_08020eb0 @ =0x0300080c
    ldrh r0, [r1]
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    movs r2, #0xd0
    lsls r2, r2, #1
    adds r0, r2, #0
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r0, lbl_08020eb4 @ =0x0300083c
    ldrb r5, [r0]
    ldr r0, lbl_08020eb8 @ =0x03000c77
    ldrb r4, [r0]
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq lbl_08020ebc
    adds r2, r5, #0
    subs r2, #0x6c
    adds r2, r7, r2
    lsls r3, r5, #5
    adds r3, #0x14
    adds r3, r6, r3
    movs r0, #0
    movs r1, #5
    bl SpriteDebrisInit
    b lbl_08020ed0
    .align 2, 0
lbl_08020eb0: .4byte 0x0300080c
lbl_08020eb4: .4byte 0x0300083c
lbl_08020eb8: .4byte 0x03000c77
lbl_08020ebc:
    adds r2, r5, #0
    subs r2, #0x64
    adds r2, r7, r2
    lsls r3, r5, #4
    adds r3, #0x1a
    adds r3, r6, r3
    movs r0, #0
    movs r1, #7
    bl SpriteDebrisInit
lbl_08020ed0:
    cmp r5, #7
    bls lbl_08020eea
    adds r2, r5, #0
    subs r2, #0x50
    adds r2, r7, r2
    lsls r3, r5, #1
    adds r3, #0x12
    subs r3, r6, r3
    movs r0, #0
    movs r1, #8
    bl SpriteDebrisInit
    b lbl_08020f0e
lbl_08020eea:
    adds r2, r5, #0
    subs r2, #0x5a
    adds r2, r7, r2
    lsls r3, r5, #2
    adds r3, #0x12
    subs r3, r6, r3
    movs r0, #0
    movs r1, #6
    bl SpriteDebrisInit
    adds r2, r7, #0
    subs r2, #0x78
    lsls r3, r4, #1
    subs r3, r6, r3
    movs r0, #0
    movs r1, #5
    bl SpriteDebrisInit
lbl_08020f0e:
    movs r0, #0x20
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    bne lbl_08020f76
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq lbl_08020f32
    adds r2, r7, #0
    subs r2, #0xa0
    lsls r4, r4, #1
    subs r3, r6, r4
    movs r0, #0
    movs r1, #6
    bl SpriteDebrisInit
    b lbl_08020f42
lbl_08020f32:
    adds r2, r7, #0
    subs r2, #0x28
    lsls r4, r4, #1
    subs r3, r6, r4
    movs r0, #0
    movs r1, #8
    bl SpriteDebrisInit
lbl_08020f42:
    cmp r5, #0xb
    bls lbl_08020f68
    adds r2, r7, #0
    subs r2, #0xa
    adds r3, r6, r4
    movs r0, #0
    movs r1, #5
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x78
    adds r2, r7, r2
    lsls r3, r5, #3
    subs r3, r6, r3
    movs r0, #0
    movs r1, #6
    bl SpriteDebrisInit
    b lbl_08020f76
lbl_08020f68:
    adds r2, r7, #0
    subs r2, #0x3c
    adds r3, r6, r4
    movs r0, #0
    movs r1, #7
    bl SpriteDebrisInit
lbl_08020f76:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start DeoremSpriteDebrisSpawn
DeoremSpriteDebrisSpawn: @ 0x08020f80
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r0, r2, #0
    cmp r2, #3
    beq lbl_08020fc0
    cmp r2, #3
    bgt lbl_08020f9e
    cmp r2, #1
    beq lbl_08020fa8
    b lbl_08021022
lbl_08020f9e:
    cmp r0, #7
    beq lbl_08020fe0
    cmp r0, #0xc
    beq lbl_08021002
    b lbl_08021022
lbl_08020fa8:
    adds r2, r5, #0
    subs r2, #0x40
    movs r0, #0
    movs r1, #0x11
    adds r3, r4, #0
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x10
    adds r3, r4, #0
    adds r3, #0x3e
    b lbl_08020ff8
lbl_08020fc0:
    adds r2, r5, #0
    adds r2, #0x28
    adds r3, r4, #0
    subs r3, #0x5c
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r3, r4, #0
    adds r3, #0x1e
    movs r0, #0
    movs r1, #4
    adds r2, r5, #0
    bl SpriteDebrisInit
    b lbl_08021022
lbl_08020fe0:
    adds r2, r5, #0
    adds r2, #0x14
    adds r3, r4, #0
    subs r3, #0x14
    movs r0, #0
    movs r1, #0x11
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x14
    adds r3, r4, #0
    adds r3, #0x6e
lbl_08020ff8:
    movs r0, #0
    movs r1, #0x12
    bl SpriteDebrisInit
    b lbl_08021022
lbl_08021002:
    adds r2, r5, #0
    adds r2, #0x28
    adds r3, r4, #0
    adds r3, #0x1e
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x10
    adds r3, r4, #0
    subs r3, #0x64
    movs r0, #0
    movs r1, #4
    bl SpriteDebrisInit
lbl_08021022:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start DeoremCheckLeaving
DeoremCheckLeaving: @ 0x08021028
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_08021078 @ =0x030001ac
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r4, r1, r2
    ldrh r2, [r4, #6]
    cmp r2, #0
    bne lbl_0802108c
    ldr r3, lbl_0802107c @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x42
    strb r1, [r0]
    ldr r1, [r3, #0x18]
    ldr r0, lbl_08021080 @ =0x082d7a84
    cmp r1, r0
    beq lbl_08021072
    ldr r0, lbl_08021084 @ =0x082d79d4
    cmp r1, r0
    beq lbl_08021072
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r2, [r3, #0x16]
    movs r0, #0x40
    strh r0, [r3, #0xc]
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldr r0, lbl_08021088 @ =0x00000199
    bl SoundPlay
lbl_08021072:
    movs r0, #1
    b lbl_0802108e
    .align 2, 0
lbl_08021078: .4byte 0x030001ac
lbl_0802107c: .4byte 0x03000738
lbl_08021080: .4byte 0x082d7a84
lbl_08021084: .4byte 0x082d79d4
lbl_08021088: .4byte 0x00000199
lbl_0802108c:
    movs r0, #0
lbl_0802108e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start DeoremSpawnChargeBeam
DeoremSpawnChargeBeam: @ 0x08021094
    push {r4, lr}
    sub sp, #8
    adds r3, r0, #0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r0, lbl_080210d0 @ =0x03000738
    ldrb r4, [r0, #0x1f]
    str r1, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x44
    movs r1, #0
    adds r2, r4, #0
    bl SpriteSpawnPrimary
    movs r0, #0x44
    adds r1, r4, #0
    bl SpriteLoadGFX
    movs r0, #0x44
    adds r1, r4, #0
    movs r2, #1
    bl SpriteLoadPAL
    add sp, #8
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080210d0: .4byte 0x03000738

    thumb_func_start DeoremSetEyeOpeningTimer
DeoremSetEyeOpeningTimer: @ 0x080210d4
    push {lr}
    ldr r0, lbl_080210e8 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080210f0
    ldr r0, lbl_080210ec @ =0x03000738
    adds r0, #0x2c
    movs r1, #0x78
    b lbl_08021106
    .align 2, 0
lbl_080210e8: .4byte 0x0300002c
lbl_080210ec: .4byte 0x03000738
lbl_080210f0:
    cmp r0, #2
    bne lbl_08021100
    ldr r0, lbl_080210fc @ =0x03000738
    adds r0, #0x2c
    movs r1, #0x28
    b lbl_08021106
    .align 2, 0
lbl_080210fc: .4byte 0x03000738
lbl_08021100:
    ldr r0, lbl_0802110c @ =0x03000738
    adds r0, #0x2c
    movs r1, #0x50
lbl_08021106:
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802110c: .4byte 0x03000738

    thumb_func_start DeoremCallSpawnChargeBeam
DeoremCallSpawnChargeBeam: @ 0x08021110
    push {r4, lr}
    ldr r4, lbl_08021138 @ =0x03000738
    ldrh r0, [r4, #2]
    adds r0, #0xb0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0xd0
    lsls r2, r2, #1
    adds r1, r2, #0
    ldrh r2, [r4, #4]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl DeoremSpawnChargeBeam
    movs r0, #0
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021138: .4byte 0x03000738

    thumb_func_start DeoremInit
DeoremInit: @ 0x0802113c
    push {r4, r5, lr}
    ldr r4, lbl_08021178 @ =0x03000738
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x42
    bne lbl_08021180
    movs r0, #3
    movs r1, #0x19
    bl EventFunction
    cmp r0, #0
    beq lbl_080211d4
    movs r0, #3
    movs r1, #0x1a
    bl EventFunction
    cmp r0, #0
    beq lbl_080211c8
    ldr r0, lbl_0802117c @ =0x03001530
    ldrb r1, [r0, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_080211c8
    movs r0, #3
    movs r1, #0x1b
    bl EventFunction
    cmp r0, #0
    beq lbl_080211b0
    b lbl_080211c8
    .align 2, 0
lbl_08021178: .4byte 0x03000738
lbl_0802117c: .4byte 0x03001530
lbl_08021180:
    movs r0, #3
    movs r1, #0x1a
    bl EventFunction
    cmp r0, #0
    beq lbl_080211d4
    movs r0, #3
    movs r1, #0x19
    bl EventFunction
    cmp r0, #0
    beq lbl_080211c8
    ldr r0, lbl_080211c4 @ =0x03001530
    ldrb r1, [r0, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_080211c8
    movs r0, #3
    movs r1, #0x1b
    bl EventFunction
    cmp r0, #0
    beq lbl_080211c8
lbl_080211b0:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x60
    strb r0, [r1]
    ldrh r1, [r4]
    movs r0, #4
    orrs r0, r1
    strh r0, [r4]
    b lbl_0802124a
    .align 2, 0
lbl_080211c4: .4byte 0x03001530
lbl_080211c8:
    ldr r1, lbl_080211d0 @ =0x03000738
    movs r0, #0
    strh r0, [r1]
    b lbl_0802124a
    .align 2, 0
lbl_080211d0: .4byte 0x03000738
lbl_080211d4:
    ldr r2, lbl_08021250 @ =0x0300080c
    ldr r0, lbl_08021254 @ =0x03000738
    mov ip, r0
    ldrh r1, [r0, #2]
    adds r0, r1, #0
    subs r0, #0x20
    movs r3, #0
    movs r4, #0
    strh r0, [r2]
    mov r5, ip
    ldrh r0, [r5, #4]
    strh r0, [r2, #2]
    subs r1, #0xa0
    strh r1, [r5, #2]
    ldr r1, lbl_08021258 @ =0x0000ffa0
    strh r1, [r5, #0xa]
    movs r0, #0x40
    strh r0, [r5, #0xc]
    strh r1, [r5, #0xe]
    movs r0, #0x60
    strh r0, [r5, #0x10]
    mov r0, ip
    adds r0, #0x27
    movs r1, #0x20
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    mov r1, ip
    adds r1, #0x29
    movs r0, #0x30
    strb r0, [r1]
    ldr r0, lbl_0802125c @ =0x082d795c
    str r0, [r5, #0x18]
    strb r3, [r5, #0x1c]
    strh r4, [r5, #0x16]
    subs r1, #4
    movs r0, #4
    strb r0, [r1]
    subs r1, #3
    movs r0, #0xa
    strb r0, [r1]
    ldr r2, lbl_08021260 @ =0x082b0d68
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r5, #0x14]
    mov r0, ip
    adds r0, #0x2c
    strb r3, [r0]
    mov r1, ip
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2a
    strb r3, [r0]
lbl_0802124a:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021250: .4byte 0x0300080c
lbl_08021254: .4byte 0x03000738
lbl_08021258: .4byte 0x0000ffa0
lbl_0802125c: .4byte 0x082d795c
lbl_08021260: .4byte 0x082b0d68

    thumb_func_start DeoremSpawnGoingDown
DeoremSpawnGoingDown: @ 0x08021264
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r0, lbl_080212b4 @ =0x0300080c
    mov r8, r0
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r0, r1, #0
    mov r2, r8
    ldrh r2, [r2, #2]
    adds r6, r0, r2
    lsls r0, r6, #0x10
    lsrs r7, r0, #0x10
    ldr r3, lbl_080212b8 @ =0x030013d4
    ldrh r1, [r3, #0x12]
    adds r4, r1, #0
    ldr r2, lbl_080212bc @ =0x03000738
    adds r5, r2, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    ldr r0, lbl_080212c0 @ =0x03001530
    ldrh r0, [r0, #2]
    cmp r0, #0
    bne lbl_080212c8
    ldr r2, lbl_080212c4 @ =0xfffffc00
    adds r0, r7, r2
    cmp r1, r0
    bgt lbl_080212a4
    b lbl_0802140c
lbl_080212a4:
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r7, r2
    cmp r1, r0
    blt lbl_080212b0
    b lbl_0802140c
lbl_080212b0:
    b lbl_080212ec
    .align 2, 0
lbl_080212b4: .4byte 0x0300080c
lbl_080212b8: .4byte 0x030013d4
lbl_080212bc: .4byte 0x03000738
lbl_080212c0: .4byte 0x03001530
lbl_080212c4: .4byte 0xfffffc00
lbl_080212c8:
    adds r0, r7, #0
    subs r0, #0x20
    cmp r1, r0
    ble lbl_080212d6
    adds r0, #0x40
    cmp r1, r0
    blt lbl_08021320
lbl_080212d6:
    ldr r1, lbl_08021318 @ =0xfffffc00
    adds r0, r7, r1
    cmp r4, r0
    bgt lbl_080212e0
    b lbl_0802140c
lbl_080212e0:
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r7, r2
    cmp r4, r0
    blt lbl_080212ec
    b lbl_0802140c
lbl_080212ec:
    ldr r0, lbl_0802131c @ =0x0300083c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080212fc
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
lbl_080212fc:
    ldrb r1, [r5]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    beq lbl_08021308
    b lbl_0802140c
lbl_08021308:
    ldrb r0, [r5]
    bl DeoremRandomSpriteDebris
    movs r0, #0xc8
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0802140c
    .align 2, 0
lbl_08021318: .4byte 0xfffffc00
lbl_0802131c: .4byte 0x0300083c
lbl_08021320:
    ldr r1, lbl_0802134c @ =0x03000100
    movs r4, #1
    strb r4, [r1]
    ldrh r0, [r3, #0x14]
    strh r0, [r1, #4]
    strh r6, [r1, #2]
    ldrh r1, [r3, #0xe]
    movs r0, #0x10
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_08021350
    mov r0, r8
    strh r4, [r0, #4]
    movs r1, #0xd0
    lsls r1, r1, #2
    adds r0, r1, #0
    ldrh r1, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    b lbl_08021354
    .align 2, 0
lbl_0802134c: .4byte 0x03000100
lbl_08021350:
    mov r1, r8
    strh r0, [r1, #4]
lbl_08021354:
    ldrh r0, [r2, #4]
    movs r1, #0
    mov r8, r1
    strh r0, [r2, #8]
    ldrh r0, [r2, #2]
    strh r0, [r2, #6]
    ldrb r6, [r2, #0x1f]
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r5, [r0]
    ldrh r4, [r2, #2]
    ldrh r7, [r2, #4]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x2e
    strb r0, [r1]
    str r4, [sp]
    str r7, [sp, #4]
    mov r2, r8
    str r2, [sp, #8]
    movs r0, #9
    movs r1, #5
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r7, [sp, #4]
    mov r0, r8
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #4
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r7, [sp, #4]
    mov r1, r8
    str r1, [sp, #8]
    movs r0, #9
    movs r1, #3
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r7, [sp, #4]
    mov r2, r8
    str r2, [sp, #8]
    movs r0, #9
    movs r1, #2
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r7, [sp, #4]
    mov r0, r8
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #1
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r7, [sp, #4]
    mov r1, r8
    str r1, [sp, #8]
    movs r0, #9
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteSpawnSecondary
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartVertical
    ldr r0, lbl_08021418 @ =0x00000193
    bl SoundPlay
    movs r0, #2
    bl deorem_left_change_ccaa
    movs r0, #2
    bl deorem_right_change_ccaa
lbl_0802140c:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021418: .4byte 0x00000193

    thumb_func_start DeoremSpawnGoingDownAnim
DeoremSpawnGoingDownAnim: @ 0x0802141c
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08021460 @ =0x0300080c
    ldrh r6, [r0]
    ldr r1, lbl_08021464 @ =0x03000738
    ldrh r5, [r1, #8]
    adds r7, r5, #0
    ldrh r0, [r1, #2]
    adds r0, #0x10
    strh r0, [r1, #2]
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    cmp r3, #0xf
    bhi lbl_08021468
    ldrb r4, [r0]
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r6, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r5, #0
    adds r2, r4, #0
    bl DeoremSpriteDebrisSpawn
    cmp r4, #8
    bne lbl_080214a4
    movs r3, #0xe0
    lsls r3, r3, #1
    adds r0, r6, r3
    adds r1, r5, #0
    movs r2, #0x36
    bl ParticleSet
    b lbl_080214a4
    .align 2, 0
lbl_08021460: .4byte 0x0300080c
lbl_08021464: .4byte 0x03000738
lbl_08021468:
    movs r0, #0x2e
    subs r0, r0, r3
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r5, r6, #0
    adds r5, #0x40
    lsls r0, r5, #0x10
    lsrs r0, r0, #0x10
    adds r1, r7, #0
    adds r2, r4, #0
    bl DeoremSpriteDebrisSpawn
    cmp r4, #0
    bne lbl_080214a4
    adds r0, r5, #0
    adds r1, r7, #0
    movs r2, #0x36
    bl ParticleSet
    ldr r0, lbl_080214dc @ =0x00000191
    bl SoundPlay
    movs r0, #0xce
    lsls r0, r0, #1
    bl SoundPlay
    movs r0, #0x3c
    movs r1, #0
    bl MusicPlay
lbl_080214a4:
    ldr r2, lbl_080214e0 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021506
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    movs r0, #0xa
    strb r0, [r3]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_080214e4 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_080214ec
    ldr r1, lbl_080214e8 @ =0xfffffcc0
    b lbl_080214f0
    .align 2, 0
lbl_080214dc: .4byte 0x00000191
lbl_080214e0: .4byte 0x03000738
lbl_080214e4: .4byte 0x0300080c
lbl_080214e8: .4byte 0xfffffcc0
lbl_080214ec:
    movs r1, #0xd0
    lsls r1, r1, #2
lbl_080214f0:
    adds r0, r1, #0
    ldrh r3, [r2, #4]
    adds r0, r0, r3
    strh r0, [r2, #4]
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartVertical
    ldr r0, lbl_0802150c @ =0x00000193
    bl SoundPlay
lbl_08021506:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802150c: .4byte 0x00000193

    thumb_func_start DeoremSpawnGoingUp
DeoremSpawnGoingUp: @ 0x08021510
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r2, lbl_080215d8 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0
    bne lbl_080215cc
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #0x32
    strb r0, [r3]
    movs r1, #0xc7
    lsls r1, r1, #2
    adds r0, r1, #0
    ldrh r1, [r2, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrb r0, [r2, #0x1f]
    mov r8, r0
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r6, [r0]
    ldrh r4, [r2, #2]
    ldrh r5, [r2, #4]
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #0xb
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #0xa
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #9
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #8
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #7
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    movs r0, #9
    movs r1, #6
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartVertical
    ldr r0, lbl_080215dc @ =0x00000193
    bl SoundPlay
lbl_080215cc:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080215d8: .4byte 0x03000738
lbl_080215dc: .4byte 0x00000193

    thumb_func_start DeoremSpawnGoingUpAnim
DeoremSpawnGoingUpAnim: @ 0x080215e0
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08021620 @ =0x0300080c
    ldrh r2, [r0]
    adds r7, r2, #0
    ldr r1, lbl_08021624 @ =0x03000738
    ldrh r5, [r1, #4]
    adds r6, r5, #0
    ldrh r0, [r1, #2]
    subs r0, #0x10
    strh r0, [r1, #2]
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    cmp r3, #0xf
    bhi lbl_08021628
    ldrb r4, [r0]
    adds r6, r2, #0
    adds r6, #0x40
    lsls r0, r6, #0x10
    lsrs r0, r0, #0x10
    adds r1, r5, #0
    adds r2, r4, #0
    bl DeoremSpriteDebrisSpawn
    cmp r4, #8
    bne lbl_08021654
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #0x36
    bl ParticleSet
    b lbl_08021654
    .align 2, 0
lbl_08021620: .4byte 0x0300080c
lbl_08021624: .4byte 0x03000738
lbl_08021628:
    movs r0, #0x32
    subs r0, r0, r3
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r1, #0xc0
    lsls r1, r1, #1
    adds r0, r7, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r6, #0
    adds r2, r4, #0
    bl DeoremSpriteDebrisSpawn
    cmp r4, #4
    bne lbl_08021654
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r7, r1
    adds r1, r6, #0
    movs r2, #0x36
    bl ParticleSet
lbl_08021654:
    ldr r2, lbl_0802168c @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080216b0
    ldrh r1, [r2]
    ldr r0, lbl_08021690 @ =0x0000feff
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x24
    strb r0, [r1]
    movs r0, #0x3c
    strb r0, [r3]
    ldr r0, lbl_08021694 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_08021698
    movs r1, #0xd0
    lsls r1, r1, #1
    b lbl_0802169a
    .align 2, 0
lbl_0802168c: .4byte 0x03000738
lbl_08021690: .4byte 0x0000feff
lbl_08021694: .4byte 0x0300080c
lbl_08021698:
    ldr r1, lbl_080216b8 @ =0xfffffe60
lbl_0802169a:
    adds r0, r1, #0
    ldrh r1, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartVertical
    ldr r0, lbl_080216bc @ =0x00000193
    bl SoundPlay
lbl_080216b0:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080216b8: .4byte 0xfffffe60
lbl_080216bc: .4byte 0x00000193

    thumb_func_start DeoremSpawnHeadBody
DeoremSpawnHeadBody: @ 0x080216c0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r7, lbl_080217b0 @ =0x03000738
    adds r4, r7, #0
    adds r4, #0x2c
    ldrb r1, [r4]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_080216e2
    ldrb r0, [r4]
    bl DeoremRandomSpriteDebris
lbl_080216e2:
    ldrb r0, [r4]
    subs r0, #1
    strb r0, [r4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sl, r0
    cmp r0, #0
    bne lbl_080217c2
    adds r1, r7, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    ldrh r0, [r7, #6]
    strh r0, [r7, #2]
    ldrh r1, [r7]
    ldr r0, lbl_080217b4 @ =0x0000fffb
    ands r0, r1
    strh r0, [r7]
    movs r0, #0xb
    strb r0, [r4]
    ldrb r0, [r7, #0x1f]
    str r0, [sp, #0xc]
    adds r0, r7, #0
    adds r0, #0x23
    ldrb r0, [r0]
    mov sb, r0
    ldrh r6, [r7, #2]
    ldrh r0, [r7, #4]
    mov r8, r0
    str r6, [sp]
    str r0, [sp, #4]
    mov r0, sl
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #0xe
    ldr r2, [sp, #0xc]
    mov r3, sb
    bl SpriteSpawnSecondary
    adds r5, r0, #0
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    str r6, [sp]
    mov r0, r8
    str r0, [sp, #4]
    mov r0, sl
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #0xd
    ldr r2, [sp, #0xc]
    mov r3, sb
    bl SpriteSpawnSecondary
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    str r6, [sp]
    mov r0, r8
    str r0, [sp, #4]
    mov r0, sl
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #0xc
    ldr r2, [sp, #0xc]
    mov r3, sb
    bl SpriteSpawnSecondary
    ldr r2, lbl_080217b8 @ =0x030001ac
    lsls r1, r4, #3
    subs r1, r1, r4
    lsls r1, r1, #3
    adds r1, r1, r2
    adds r1, #0x2c
    strb r0, [r1]
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x2c
    strb r4, [r0]
    subs r6, #0x1c
    str r6, [sp]
    movs r0, #4
    rsbs r0, r0, #0
    add r8, r0
    mov r0, r8
    str r0, [sp, #4]
    mov r0, sl
    str r0, [sp, #8]
    movs r0, #0xa
    movs r1, #0
    ldr r2, [sp, #0xc]
    mov r3, sb
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0xff
    bne lbl_080217bc
    mov r0, sl
    strh r0, [r7]
    b lbl_080217c2
    .align 2, 0
lbl_080217b0: .4byte 0x03000738
lbl_080217b4: .4byte 0x0000fffb
lbl_080217b8: .4byte 0x030001ac
lbl_080217bc:
    adds r0, r7, #0
    adds r0, #0x2f
    strb r2, [r0]
lbl_080217c2:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremAfterSpawn
DeoremAfterSpawn: @ 0x080217d4
    push {r4, r5, lr}
    ldr r4, lbl_08021804 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x2f
    ldrb r5, [r0]
    ldr r2, lbl_08021808 @ =0x03000c77
    ldrb r1, [r2]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_080217f0
    ldrb r0, [r2]
    bl DeoremRandomSpriteDebris
lbl_080217f0:
    ldrh r1, [r4, #2]
    ldrh r0, [r4, #6]
    adds r0, #0xa0
    cmp r1, r0
    bge lbl_0802180c
    adds r0, r1, #0
    adds r0, #8
    strh r0, [r4, #2]
    b lbl_08021868
    .align 2, 0
lbl_08021804: .4byte 0x03000738
lbl_08021808: .4byte 0x03000c77
lbl_0802180c:
    adds r2, r4, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021868
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x26
    strb r1, [r0]
    ldr r0, lbl_08021830 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08021834
    movs r0, #0x5a
    b lbl_0802183e
    .align 2, 0
lbl_08021830: .4byte 0x0300002c
lbl_08021834:
    cmp r0, #2
    bne lbl_0802183c
    movs r0, #0x22
    b lbl_0802183e
lbl_0802183c:
    movs r0, #0x3c
lbl_0802183e:
    strb r0, [r2]
    ldr r1, lbl_08021870 @ =0x03000738
    ldr r0, lbl_08021874 @ =0x082d7984
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    strh r0, [r1, #0xc]
    ldr r0, lbl_08021878 @ =0x030001ac
    lsls r1, r5, #3
    subs r1, r1, r5
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    ldr r0, lbl_0802187c @ =0x00007fff
    ands r0, r2
    strh r0, [r1]
    movs r0, #0xcc
    lsls r0, r0, #1
    bl SoundPlay
lbl_08021868:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021870: .4byte 0x03000738
lbl_08021874: .4byte 0x082d7984
lbl_08021878: .4byte 0x030001ac
lbl_0802187c: .4byte 0x00007fff

    thumb_func_start sub_08021880
sub_08021880: @ 0x08021880
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, lbl_080218dc @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r6, [r0]
    ldr r2, lbl_080218e0 @ =0x030001ac
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrh r0, [r0, #0x14]
    mov r8, r0
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #0
    bne lbl_080218aa
    b lbl_080219fc
lbl_080218aa:
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_080218b8
    b lbl_080219fc
lbl_080218b8:
    adds r0, r6, #0
    bl DeoremCheckLeaving
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    beq lbl_080218c8
    b lbl_08021aee
lbl_080218c8:
    ldr r1, [r5, #0x18]
    ldr r0, lbl_080218e4 @ =0x082d79d4
    cmp r1, r0
    bne lbl_080218ec
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021902
    ldr r0, lbl_080218e8 @ =0x082d7a84
    b lbl_080218fc
    .align 2, 0
lbl_080218dc: .4byte 0x03000738
lbl_080218e0: .4byte 0x030001ac
lbl_080218e4: .4byte 0x082d79d4
lbl_080218e8: .4byte 0x082d7a84
lbl_080218ec:
    ldr r0, lbl_0802194c @ =0x082d7984
    cmp r1, r0
    bne lbl_08021902
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021902
    ldr r0, lbl_08021950 @ =0x082d7a5c
lbl_080218fc:
    str r0, [r5, #0x18]
    strb r4, [r5, #0x1c]
    strh r4, [r5, #0x16]
lbl_08021902:
    ldr r4, lbl_08021954 @ =0x03000738
    adds r7, r4, #0
    adds r7, #0x2c
    ldrb r0, [r7]
    subs r0, #1
    movs r5, #0
    strb r0, [r7]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080219b0
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldr r0, lbl_08021958 @ =0x082d79fc
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    movs r6, #0
    strh r5, [r4, #0x16]
    ldrh r1, [r4]
    ldr r0, lbl_0802195c @ =0x0000ffdf
    ands r0, r1
    strh r0, [r4]
    ldr r0, lbl_08021960 @ =0x0000019d
    bl SoundPlay
    adds r0, r4, #0
    adds r0, #0x2a
    strb r6, [r0]
    mov r0, r8
    cmp r0, #0x3c
    bne lbl_08021964
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    b lbl_08021984
    .align 2, 0
lbl_0802194c: .4byte 0x082d7984
lbl_08021950: .4byte 0x082d7a5c
lbl_08021954: .4byte 0x03000738
lbl_08021958: .4byte 0x082d79fc
lbl_0802195c: .4byte 0x0000ffdf
lbl_08021960: .4byte 0x0000019d
lbl_08021964:
    ldrh r3, [r4, #4]
    adds r1, r3, #0
    subs r1, #0x60
    ldr r0, lbl_08021990 @ =0x030013d4
    ldrh r2, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, r2
    bge lbl_08021994
    adds r0, r3, #0
    adds r0, #0x60
    cmp r0, r2
    ble lbl_08021994
    ldrh r0, [r4]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
lbl_08021984:
    orrs r0, r1
    strh r0, [r4]
    movs r0, #8
    strb r0, [r7]
    b lbl_08021aee
    .align 2, 0
lbl_08021990: .4byte 0x030013d4
lbl_08021994:
    ldr r1, lbl_080219ac @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2d
    movs r0, #0
    strb r0, [r2]
    adds r2, #1
    movs r0, #1
    strb r0, [r2]
    ldrh r0, [r5, #0x12]
    strh r0, [r1, #0x12]
    b lbl_08021a68
    .align 2, 0
lbl_080219ac: .4byte 0x03000738
lbl_080219b0:
    cmp r0, #0x17
    beq lbl_080219b6
    b lbl_08021aee
lbl_080219b6:
    ldr r1, [r4, #0x18]
    ldr r0, lbl_080219ec @ =0x082d7a5c
    cmp r1, r0
    beq lbl_080219c0
    b lbl_08021aee
lbl_080219c0:
    ldr r0, lbl_080219f0 @ =0x082d79d4
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    movs r0, #0x40
    strh r0, [r4, #0xc]
    ldr r0, lbl_080219f4 @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r0, lbl_080219f8 @ =0x00000199
    bl SoundPlay
    b lbl_08021aee
    .align 2, 0
lbl_080219ec: .4byte 0x082d7a5c
lbl_080219f0: .4byte 0x082d79d4
lbl_080219f4: .4byte 0x030001ac
lbl_080219f8: .4byte 0x00000199
lbl_080219fc:
    adds r4, r5, #0
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08021a24 @ =0x082d79fc
    cmp r1, r0
    bne lbl_08021a34
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021aee
    ldrh r1, [r4]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08021a2c
    ldr r0, lbl_08021a28 @ =0x082d7a44
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08021aee
    .align 2, 0
lbl_08021a24: .4byte 0x082d79fc
lbl_08021a28: .4byte 0x082d7a44
lbl_08021a2c:
    movs r0, #0x20
    orrs r0, r1
    strh r0, [r4]
    b lbl_08021aee
lbl_08021a34:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08021a72
    movs r5, #0xfa
    lsls r5, r5, #1
    movs r2, #0xc
    mov r0, r8
    cmp r0, #0x3c
    bne lbl_08021a4e
    movs r2, #8
lbl_08021a4e:
    adds r3, r4, #0
    adds r3, #0x2c
    ldrb r1, [r3]
    cmp r1, #0
    beq lbl_08021a80
    ldrh r0, [r4, #2]
    subs r0, r0, r2
    strh r0, [r4, #2]
    subs r0, r1, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021aee
lbl_08021a68:
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
    b lbl_08021aee
lbl_08021a72:
    ldrh r1, [r5, #0x12]
    movs r0, #0x14
    bl sub_08020d90
    movs r5, #0xe8
    lsls r5, r5, #1
    movs r2, #8
lbl_08021a80:
    ldr r3, lbl_08021aac @ =0x03000738
    ldrh r1, [r3, #2]
    ldrh r0, [r3, #6]
    adds r0, r0, r5
    cmp r1, r0
    bge lbl_08021aba
    adds r0, r2, r1
    strh r0, [r3, #2]
    adds r1, r3, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08021aee
    adds r0, #1
    strb r0, [r1]
    cmp r2, #8
    bls lbl_08021ab0
    movs r0, #0xca
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08021aee
    .align 2, 0
lbl_08021aac: .4byte 0x03000738
lbl_08021ab0:
    movs r0, #0xcf
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08021aee
lbl_08021aba:
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x27
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x1e
    strb r0, [r1]
    ldr r0, lbl_08021af8 @ =0x082d7984
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r2, [r3, #0x16]
    strh r2, [r3, #0xc]
    ldr r0, lbl_08021afc @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    ldr r0, lbl_08021b00 @ =0x00007fff
    ands r0, r2
    strh r0, [r1]
    movs r0, #0xcc
    lsls r0, r0, #1
    bl SoundPlay
lbl_08021aee:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021af8: .4byte 0x082d7984
lbl_08021afc: .4byte 0x030001ac
lbl_08021b00: .4byte 0x00007fff

    thumb_func_start DeoremRetracting
DeoremRetracting: @ 0x08021b04
    push {r4, r5, lr}
    ldr r4, lbl_08021b78 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    adds r2, r0, #0
    ldr r1, lbl_08021b7c @ =0x030001ac
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r5, [r0, #0x14]
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08021bac
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08021b80 @ =0x082d7984
    cmp r1, r0
    bne lbl_08021b48
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021b48
    ldr r0, lbl_08021b84 @ =0x082d7a5c
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    ldr r0, lbl_08021b88 @ =0x0000ff70
    strh r0, [r4, #0xe]
    movs r0, #0x90
    strh r0, [r4, #0x10]
lbl_08021b48:
    ldr r2, lbl_08021b78 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x18
    bls lbl_08021b90
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08021b6a
    b lbl_08021c68
lbl_08021b6a:
    ldr r0, lbl_08021b8c @ =0x030013d4
    ldrh r1, [r0, #0x12]
    movs r0, #0x10
    bl sub_08020d90
    b lbl_08021c68
    .align 2, 0
lbl_08021b78: .4byte 0x03000738
lbl_08021b7c: .4byte 0x030001ac
lbl_08021b80: .4byte 0x082d7984
lbl_08021b84: .4byte 0x082d7a5c
lbl_08021b88: .4byte 0x0000ff70
lbl_08021b8c: .4byte 0x030013d4
lbl_08021b90:
    cmp r0, #0
    bne lbl_08021c68
    ldrh r0, [r2]
    ldr r1, lbl_08021ba4 @ =0x0000fbff
    ands r1, r0
    strh r1, [r2]
    ldr r0, lbl_08021ba8 @ =0x00000195
    bl SoundPlay
    b lbl_08021c68
    .align 2, 0
lbl_08021ba4: .4byte 0x0000fbff
lbl_08021ba8: .4byte 0x00000195
lbl_08021bac:
    ldrh r0, [r4, #2]
    subs r0, #8
    strh r0, [r4, #2]
    ldrh r1, [r4, #2]
    ldrh r0, [r4, #6]
    adds r0, #0xa0
    cmp r1, r0
    bge lbl_08021c68
    ldr r0, lbl_08021c08 @ =0x0000ffa0
    strh r0, [r4, #0xe]
    movs r0, #0x60
    strh r0, [r4, #0x10]
    ldrh r0, [r4, #6]
    adds r0, #0xa0
    strh r0, [r4, #2]
    adds r0, r2, #0
    bl DeoremCheckLeaving
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021c68
    cmp r5, #0x3c
    beq lbl_08021be6
    ldr r0, lbl_08021c0c @ =0x0300083c
    ldrb r0, [r0]
    cmp r0, #0xa
    bhi lbl_08021be6
    cmp r5, #0x14
    bhi lbl_08021c5c
lbl_08021be6:
    ldr r0, lbl_08021c10 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_08021c20
    ldr r2, lbl_08021c14 @ =0x03000738
    ldrh r0, [r2, #8]
    ldr r1, lbl_08021c18 @ =0xfffffe60
    adds r0, r0, r1
    ldr r1, lbl_08021c1c @ =0x030013d4
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bgt lbl_08021c44
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x28
    b lbl_08021c4a
    .align 2, 0
lbl_08021c08: .4byte 0x0000ffa0
lbl_08021c0c: .4byte 0x0300083c
lbl_08021c10: .4byte 0x0300080c
lbl_08021c14: .4byte 0x03000738
lbl_08021c18: .4byte 0xfffffe60
lbl_08021c1c: .4byte 0x030013d4
lbl_08021c20:
    ldr r2, lbl_08021c3c @ =0x03000738
    ldrh r0, [r2, #8]
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r0, r0, r1
    ldr r1, lbl_08021c40 @ =0x030013d4
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    ble lbl_08021c44
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x28
    b lbl_08021c4a
    .align 2, 0
lbl_08021c3c: .4byte 0x03000738
lbl_08021c40: .4byte 0x030013d4
lbl_08021c44:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x29
lbl_08021c4a:
    strb r0, [r1]
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0xff
    strb r0, [r1]
    subs r1, #2
    movs r0, #0
    strb r0, [r1]
    b lbl_08021c68
lbl_08021c5c:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x26
    strb r0, [r1]
    bl DeoremSetEyeOpeningTimer
lbl_08021c68:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremThrowingThorns
DeoremThrowingThorns: @ 0x08021c70
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r2, lbl_08021d08 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2f
    ldrb r6, [r0]
    ldr r1, lbl_08021d0c @ =0x030001ac
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r3, [r0, #0x14]
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    movs r0, #0xe6
    mov r8, r0
    mov sb, r2
    cmp r3, #0x14
    bls lbl_08021cac
    movs r1, #0x1e
    mov r8, r1
    cmp r3, #0x28
    bhi lbl_08021cac
    movs r3, #0xd2
    mov r8, r3
lbl_08021cac:
    mov r4, sb
    adds r5, r4, #0
    adds r5, #0x2a
    ldrb r1, [r5]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_08021cc4
    movs r0, #0xcb
    lsls r0, r0, #1
    bl SoundPlay
lbl_08021cc4:
    ldrb r0, [r5]
    adds r0, #1
    movs r7, #0
    strb r0, [r5]
    adds r0, r4, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, r8
    bhs lbl_08021d4c
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08021d10 @ =0x082d7a5c
    cmp r1, r0
    bne lbl_08021d1c
    ldr r0, lbl_08021d14 @ =0x082d79d4
    str r0, [r4, #0x18]
    strb r7, [r4, #0x1c]
    strh r7, [r4, #0x16]
    movs r0, #0x40
    strh r0, [r4, #0xc]
    ldr r0, lbl_08021d0c @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r0, lbl_08021d18 @ =0x00000199
    bl SoundPlay
    b lbl_08021d34
    .align 2, 0
lbl_08021d08: .4byte 0x03000738
lbl_08021d0c: .4byte 0x030001ac
lbl_08021d10: .4byte 0x082d7a5c
lbl_08021d14: .4byte 0x082d79d4
lbl_08021d18: .4byte 0x00000199
lbl_08021d1c:
    ldr r0, lbl_08021d58 @ =0x082d79d4
    cmp r1, r0
    bne lbl_08021d34
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021d34
    ldr r0, lbl_08021d5c @ =0x082d7a84
    mov r1, sb
    str r0, [r1, #0x18]
    strb r7, [r1, #0x1c]
    strh r7, [r1, #0x16]
lbl_08021d34:
    ldr r1, lbl_08021d60 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_08021d4c
    adds r0, r1, #0
    adds r0, #0x24
    movs r1, #0x2a
    strb r1, [r0]
    movs r0, #0x3c
    strb r0, [r2]
lbl_08021d4c:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021d58: .4byte 0x082d79d4
lbl_08021d5c: .4byte 0x082d7a84
lbl_08021d60: .4byte 0x03000738

    thumb_func_start DeoremAfterThorns
DeoremAfterThorns: @ 0x08021d64
    push {r4, lr}
    ldr r4, lbl_08021da4 @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08021da8 @ =0x082d79d4
    cmp r1, r0
    bne lbl_08021d82
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021d82
    ldr r0, lbl_08021dac @ =0x082d7a84
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
lbl_08021d82:
    ldr r2, lbl_08021da4 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021d9e
    subs r1, #8
    movs r0, #0x26
    strb r0, [r1]
    bl DeoremSetEyeOpeningTimer
lbl_08021d9e:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021da4: .4byte 0x03000738
lbl_08021da8: .4byte 0x082d79d4
lbl_08021dac: .4byte 0x082d7a84

    thumb_func_start DeoremDying
DeoremDying: @ 0x08021db0
    push {r4, r5, lr}
    ldr r5, lbl_08021e18 @ =0x03000738
    ldr r0, lbl_08021e1c @ =0x082d7aac
    str r0, [r5, #0x18]
    movs r0, #0
    strb r0, [r5, #0x1c]
    movs r4, #0
    strh r0, [r5, #0x16]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    adds r2, r5, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x70
    orrs r0, r1
    strb r0, [r2]
    movs r0, #1
    bl deorem_left_change_ccaa
    movs r0, #1
    bl deorem_right_change_ccaa
    ldr r0, lbl_08021e20 @ =0x03000100
    strb r4, [r0]
    movs r0, #1
    movs r1, #0x19
    bl EventFunction
    movs r0, #1
    movs r1, #0x1a
    bl EventFunction
    ldrb r0, [r5, #0x1d]
    cmp r0, #0x43
    bne lbl_08021e02
    movs r0, #1
    movs r1, #0x1b
    bl EventFunction
lbl_08021e02:
    ldr r0, lbl_08021e24 @ =0x0000019b
    bl SoundPlay
    movs r0, #0x32
    movs r1, #1
    movs r2, #0
    bl sub_08003b30
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021e18: .4byte 0x03000738
lbl_08021e1c: .4byte 0x082d7aac
lbl_08021e20: .4byte 0x03000100
lbl_08021e24: .4byte 0x0000019b

    thumb_func_start DeoremDyingGoingDown
DeoremDyingGoingDown: @ 0x08021e28
    push {lr}
    ldr r2, lbl_08021e48 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrh r1, [r2, #2]
    ldrh r0, [r2, #6]
    movs r3, #0xe8
    lsls r3, r3, #1
    adds r0, r0, r3
    cmp r1, r0
    bge lbl_08021e4c
    adds r0, r1, #4
    strh r0, [r2, #2]
    b lbl_08021e70
    .align 2, 0
lbl_08021e48: .4byte 0x03000738
lbl_08021e4c:
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x68
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x3c
    strb r0, [r1]
    adds r3, r2, #0
    adds r3, #0x2b
    ldrb r1, [r3]
    movs r0, #0x80
    ands r0, r1
    strb r0, [r3]
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
lbl_08021e70:
    pop {r0}
    bx r0

    thumb_func_start DeoremDeath
DeoremDeath: @ 0x08021e74
    push {lr}
    sub sp, #4
    ldr r2, lbl_08021ea8 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    adds r1, #6
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08021ea2
    ldrh r1, [r2, #2]
    ldrh r2, [r2, #4]
    adds r2, #0x40
    movs r0, #0x22
    str r0, [sp]
    movs r0, #0
    movs r3, #0
    bl SpriteUtilSpriteDeath
lbl_08021ea2:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021ea8: .4byte 0x03000738

    thumb_func_start DeoremCheckLeaving_to_ceiling_anim_ended
DeoremCheckLeaving_to_ceiling_anim_ended: @ 0x08021eac
    push {r4, lr}
    ldr r4, lbl_08021ed4 @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08021ed8 @ =0x082d79d4
    cmp r1, r0
    beq lbl_08021ebe
    ldr r0, lbl_08021edc @ =0x082d7a84
    cmp r1, r0
    bne lbl_08021ee4
lbl_08021ebe:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08021f00
    ldr r0, lbl_08021ee0 @ =0x082d795c
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08021f00
    .align 2, 0
lbl_08021ed4: .4byte 0x03000738
lbl_08021ed8: .4byte 0x082d79d4
lbl_08021edc: .4byte 0x082d7a84
lbl_08021ee0: .4byte 0x082d795c
lbl_08021ee4:
    ldr r0, lbl_08021f08 @ =0x082d795c
    cmp r1, r0
    bne lbl_08021f00
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x43
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x3c
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x2a
    strb r2, [r0]
lbl_08021f00:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08021f08: .4byte 0x082d795c

    thumb_func_start DeoremLeaving
DeoremLeaving: @ 0x08021f0c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r1, lbl_08021f2c @ =0x03000738
    ldrh r2, [r1, #2]
    ldrh r0, [r1, #6]
    subs r0, #0x40
    adds r7, r1, #0
    cmp r2, r0
    ble lbl_08021f30
    subs r0, r2, #4
    strh r0, [r7, #2]
    b lbl_0802207a
    .align 2, 0
lbl_08021f2c: .4byte 0x03000738
lbl_08021f30:
    movs r3, #0
    ldr r4, lbl_08021fb8 @ =0x030001ac
lbl_08021f34:
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r2, r0, r4
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08021f62
    adds r0, r2, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08021f62
    ldrb r0, [r2, #0x1d]
    subs r0, #0x1a
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bhi lbl_08021f62
    b lbl_0802207a
lbl_08021f62:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0x17
    bls lbl_08021f34
    adds r4, r7, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    mov sl, r0
    cmp r0, #0
    beq lbl_08021fc0
    adds r2, r0, #0
    ldr r3, lbl_08021fbc @ =0x0300080c
    ldrh r0, [r3]
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r5, #0xd0
    lsls r5, r5, #1
    adds r1, r5, #0
    ldrh r3, [r3, #2]
    adds r1, r1, r3
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl DeoremSpriteDebrisSpawn
    ldrb r0, [r4]
    subs r0, #1
    strb r0, [r4]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_0802207a
    ldr r2, lbl_08021fb8 @ =0x030001ac
    adds r0, r7, #0
    adds r0, #0x2f
    ldrb r1, [r0]
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    strh r3, [r0]
    b lbl_0802207a
    .align 2, 0
lbl_08021fb8: .4byte 0x030001ac
lbl_08021fbc: .4byte 0x0300080c
lbl_08021fc0:
    ldr r1, lbl_08022050 @ =0x0300080c
    movs r2, #0xd0
    lsls r2, r2, #1
    adds r0, r2, #0
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    movs r5, #0
    mov sb, r5
    strh r0, [r7, #4]
    adds r1, r7, #0
    adds r1, #0x24
    movs r0, #0x44
    strb r0, [r1]
    ldrb r0, [r7, #0x1f]
    mov r8, r0
    adds r0, r7, #0
    adds r0, #0x23
    ldrb r6, [r0]
    ldrh r4, [r7, #2]
    ldrh r5, [r7, #4]
    str r4, [sp]
    str r5, [sp, #4]
    mov r1, sl
    str r1, [sp, #8]
    movs r0, #9
    movs r1, #0x11
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    mov r2, sl
    str r2, [sp, #8]
    movs r0, #9
    movs r1, #0x10
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    str r4, [sp]
    str r5, [sp, #4]
    mov r5, sl
    str r5, [sp, #8]
    movs r0, #9
    movs r1, #0xf
    mov r2, r8
    adds r3, r6, #0
    bl SpriteSpawnSecondary
    movs r0, #1
    bl deorem_left_change_ccaa
    movs r0, #1
    bl deorem_right_change_ccaa
    ldr r0, lbl_08022054 @ =0x03000100
    mov r1, sb
    strb r1, [r0]
    ldrb r0, [r7, #0x1d]
    cmp r0, #0x42
    bne lbl_08022058
    movs r0, #1
    movs r1, #0x19
    bl EventFunction
    movs r0, #0
    movs r1, #0x1a
    bl EventFunction
    b lbl_08022068
    .align 2, 0
lbl_08022050: .4byte 0x0300080c
lbl_08022054: .4byte 0x03000100
lbl_08022058:
    movs r0, #0
    movs r1, #0x19
    bl EventFunction
    movs r0, #1
    movs r1, #0x1a
    bl EventFunction
lbl_08022068:
    movs r0, #0xc9
    lsls r0, r0, #1
    bl SoundPlay
    movs r0, #0x32
    movs r1, #1
    movs r2, #0
    bl sub_08003b30
lbl_0802207a:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremLeavingAnim
DeoremLeavingAnim: @ 0x0802208c
    push {lr}
    ldr r2, lbl_080220c8 @ =0x03000c77
    ldrb r1, [r2]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_080220b0
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_080220a8
    ldrb r0, [r2]
    bl DeoremRandomSpriteDebris
lbl_080220a8:
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
lbl_080220b0:
    ldr r2, lbl_080220cc @ =0x03000738
    ldrh r1, [r2, #2]
    ldrh r0, [r2, #6]
    movs r3, #0xb0
    lsls r3, r3, #2
    adds r0, r0, r3
    cmp r1, r0
    bge lbl_080220d0
    adds r0, r1, #0
    adds r0, #0x10
    strh r0, [r2, #2]
    b lbl_080220e8
    .align 2, 0
lbl_080220c8: .4byte 0x03000c77
lbl_080220cc: .4byte 0x03000738
lbl_080220d0:
    ldrh r1, [r2]
    ldr r3, lbl_080220ec @ =0x00008004
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x45
    strb r0, [r1]
    adds r1, #9
    movs r0, #0xf0
    strb r0, [r1]
lbl_080220e8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080220ec: .4byte 0x00008004

    thumb_func_start DeoremLeavingInGroundDebris
DeoremLeavingInGroundDebris: @ 0x080220f0
    push {lr}
    ldr r0, lbl_08022138 @ =0x03000738
    adds r0, #0x26
    movs r1, #1
    strb r1, [r0]
    ldr r2, lbl_0802213c @ =0x03000c77
    ldrb r1, [r2]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0802211c
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_08022114
    ldrb r0, [r2]
    bl DeoremRandomSpriteDebris
lbl_08022114:
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
lbl_0802211c:
    ldr r2, lbl_08022138 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08022132
    strh r0, [r2]
lbl_08022132:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022138: .4byte 0x03000738
lbl_0802213c: .4byte 0x03000c77

    thumb_func_start DeoremSegmentInit
DeoremSegmentInit: @ 0x08022140
    push {r4, lr}
    ldr r0, lbl_0802217c @ =0x03000738
    mov ip, r0
    adds r0, #0x33
    movs r3, #0
    movs r2, #1
    strb r2, [r0]
    mov r4, ip
    ldrh r1, [r4]
    ldr r0, lbl_08022180 @ =0x0000fffb
    ands r0, r1
    movs r1, #0
    strh r0, [r4]
    adds r4, #0x25
    movs r0, #4
    strb r0, [r4]
    mov r0, ip
    strb r1, [r0, #0x1c]
    strh r3, [r0, #0x16]
    strh r2, [r0, #0x14]
    ldrb r2, [r0, #0x1e]
    mov r3, ip
    cmp r2, #0x13
    bhi lbl_080221e8
    lsls r0, r2, #2
    ldr r1, lbl_08022184 @ =lbl_08022188
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802217c: .4byte 0x03000738
lbl_08022180: .4byte 0x0000fffb
lbl_08022184: .4byte lbl_08022188
lbl_08022188: @ jump table
    .4byte lbl_080221e4 @ case 0
    .4byte lbl_080221d8 @ case 1
    .4byte lbl_080221dc @ case 2
    .4byte lbl_080221e0 @ case 3
    .4byte lbl_080221e4 @ case 4
    .4byte lbl_080221d8 @ case 5
    .4byte lbl_080221e8 @ case 6
    .4byte lbl_080221d8 @ case 7
    .4byte lbl_080221dc @ case 8
    .4byte lbl_080221e0 @ case 9
    .4byte lbl_080221e4 @ case 10
    .4byte lbl_080221d8 @ case 11
    .4byte lbl_080221dc @ case 12
    .4byte lbl_080221d8 @ case 13
    .4byte lbl_080221e4 @ case 14
    .4byte lbl_080221e0 @ case 15
    .4byte lbl_080221dc @ case 16
    .4byte lbl_080221d8 @ case 17
    .4byte lbl_080221dc @ case 18
    .4byte lbl_080221dc @ case 19
lbl_080221d8:
    movs r0, #1
    b lbl_080221e6
lbl_080221dc:
    movs r0, #2
    b lbl_080221e6
lbl_080221e0:
    movs r0, #3
    b lbl_080221e6
lbl_080221e4:
    movs r0, #0
lbl_080221e6:
    strh r0, [r3, #0x16]
lbl_080221e8:
    cmp r2, #0x12
    bne lbl_08022220
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x30
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r4, r3, #0
    adds r4, #0x29
    movs r0, #0x1a
    strb r0, [r4]
    ldr r0, lbl_08022214 @ =0x0000ffa0
    strh r0, [r3, #0xa]
    movs r0, #0x60
    strh r0, [r3, #0xc]
    ldr r0, lbl_08022218 @ =0x0000ffd0
    strh r0, [r3, #0xe]
    strh r1, [r3, #0x10]
    ldr r0, lbl_0802221c @ =0x082d78e4
    b lbl_0802228e
    .align 2, 0
lbl_08022214: .4byte 0x0000ffa0
lbl_08022218: .4byte 0x0000ffd0
lbl_0802221c: .4byte 0x082d78e4
lbl_08022220:
    cmp r2, #0
    beq lbl_0802222c
    cmp r2, #6
    beq lbl_0802222c
    cmp r2, #0xc
    bne lbl_08022268
lbl_0802222c:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x29
    movs r0, #0x20
    strb r0, [r1]
    ldr r0, lbl_0802225c @ =0x0000ffc0
    strh r0, [r3, #0xa]
    movs r0, #0x40
    strh r0, [r3, #0xc]
    ldr r0, lbl_08022260 @ =0x0000ffa0
    strh r0, [r3, #0xe]
    movs r0, #0x60
    strh r0, [r3, #0x10]
    ldr r0, lbl_08022264 @ =0x082d78bc
    str r0, [r3, #0x18]
    subs r1, #7
    movs r0, #0xb
    strb r0, [r1]
    b lbl_08022290
    .align 2, 0
lbl_0802225c: .4byte 0x0000ffc0
lbl_08022260: .4byte 0x0000ffa0
lbl_08022264: .4byte 0x082d78bc
lbl_08022268:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x12
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x29
    movs r0, #0x22
    strb r0, [r1]
    ldr r0, lbl_080222a0 @ =0x0000ffc0
    strh r0, [r3, #0xa]
    movs r0, #0x40
    strh r0, [r3, #0xc]
    ldr r0, lbl_080222a4 @ =0x0000ffa0
    strh r0, [r3, #0xe]
    movs r0, #0x60
    strh r0, [r3, #0x10]
    ldr r0, lbl_080222a8 @ =0x082d7894
lbl_0802228e:
    str r0, [r3, #0x18]
lbl_08022290:
    cmp r2, #5
    bhi lbl_080222ac
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    b lbl_08022356
    .align 2, 0
lbl_080222a0: .4byte 0x0000ffc0
lbl_080222a4: .4byte 0x0000ffa0
lbl_080222a8: .4byte 0x082d7894
lbl_080222ac:
    subs r0, r2, #6
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #5
    bhi lbl_080222ca
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    orrs r0, r1
    b lbl_08022354
lbl_080222ca:
    adds r0, r2, #0
    subs r0, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_080222ee
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x24
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #0xa
    movs r0, #1
    strb r0, [r1]
    b lbl_08022356
lbl_080222ee:
    adds r0, r2, #0
    subs r0, #0xf
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_08022314
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x4a
    strb r0, [r1]
    subs r1, #2
    movs r0, #3
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    b lbl_08022356
lbl_08022314:
    cmp r2, #0x12
    bne lbl_0802232a
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    subs r1, #2
    movs r0, #3
    strb r0, [r1]
    adds r1, #0xc
    b lbl_0802234c
lbl_0802232a:
    cmp r2, #0x13
    bne lbl_08022352
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x11
    strb r0, [r1]
    subs r1, #2
    movs r0, #3
    strb r0, [r1]
    ldrh r1, [r3]
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x2e
lbl_0802234c:
    movs r0, #0x1c
    strb r0, [r1]
    b lbl_08022356
lbl_08022352:
    movs r0, #0
lbl_08022354:
    strh r0, [r3]
lbl_08022356:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start DeoremSegmentSpawnGoingDown
DeoremSegmentSpawnGoingDown: @ 0x0802235c
    push {r4, r5, r6, lr}
    ldr r1, lbl_08022384 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r5, [r0]
    ldrb r0, [r1, #0x1e]
    mov ip, r1
    cmp r0, #0
    bne lbl_0802238c
    ldr r1, lbl_08022388 @ =0x030001ac
    lsls r2, r5, #3
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #2]
    subs r0, #0xa8
    mov r3, ip
    strh r0, [r3, #2]
    b lbl_080223b0
    .align 2, 0
lbl_08022384: .4byte 0x03000738
lbl_08022388: .4byte 0x030001ac
lbl_0802238c:
    ldr r3, lbl_080223e4 @ =0x030001ac
    lsls r4, r5, #3
    subs r0, r4, r5
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r0, [r0, #2]
    subs r0, #0xa8
    mov r6, ip
    ldrb r2, [r6, #0x1e]
    movs r1, #0x64
    adds r6, r2, #0
    muls r6, r1, r6
    adds r1, r6, #0
    subs r0, r0, r1
    mov r1, ip
    strh r0, [r1, #2]
    adds r1, r3, #0
    adds r2, r4, #0
lbl_080223b0:
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x22
    bne lbl_080223de
    mov r1, ip
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r1, #8
    movs r0, #6
    strb r0, [r1]
    mov r3, ip
    ldrb r0, [r3, #0x1e]
    cmp r0, #0
    bne lbl_080223de
    ldr r0, lbl_080223e8 @ =0x082d7894
    str r0, [r3, #0x18]
    subs r1, #0xa
    movs r0, #4
    strb r0, [r1]
lbl_080223de:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080223e4: .4byte 0x030001ac
lbl_080223e8: .4byte 0x082d7894

    thumb_func_start DeoremSegmentSpawnGoingDownAfter
DeoremSegmentSpawnGoingDownAfter: @ 0x080223ec
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0xc
    ldr r2, lbl_080224ac @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r6, [r0]
    movs r7, #0x10
    ldr r0, lbl_080224b0 @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r1, [r1]
    adds r4, r2, #0
    mov sb, r0
    cmp r1, #0x25
    bne lbl_08022418
    movs r7, #8
lbl_08022418:
    ldrh r0, [r4, #2]
    adds r0, r7, r0
    strh r0, [r4, #2]
    adds r5, r4, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    cmp r0, #0
    bne lbl_0802245a
    movs r0, #0x64
    adds r1, r7, #0
    bl __divsi3
    strb r0, [r5]
    ldrb r0, [r5]
    adds r1, r7, #0
    muls r1, r0, r1
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    ldrh r0, [r4, #0x16]
    adds r0, #1
    strh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_0802245a
    mov r0, r8
    strh r0, [r4, #0x16]
lbl_0802245a:
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    add r0, sb
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x26
    bne lbl_0802249e
    ldrb r0, [r4, #0x1e]
    lsls r0, r0, #2
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
    subs r1, #0xa
    movs r0, #0xf
    strb r0, [r1]
    ldrb r0, [r4, #0x1e]
    cmp r0, #5
    bne lbl_0802249e
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0x64
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #0x12
    bl SpriteSpawnSecondary
lbl_0802249e:
    add sp, #0xc
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080224ac: .4byte 0x03000738
lbl_080224b0: .4byte 0x030001ac

    thumb_func_start DeoremSegmentSpawnGoingUp
DeoremSegmentSpawnGoingUp: @ 0x080224b4
    push {r4, r5, lr}
    ldr r1, lbl_080224dc @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r5, [r0]
    ldrb r0, [r1, #0x1e]
    mov ip, r1
    cmp r0, #6
    bne lbl_080224e4
    ldr r1, lbl_080224e0 @ =0x030001ac
    lsls r2, r5, #3
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #2]
    adds r0, #0xa8
    mov r3, ip
    strh r0, [r3, #2]
    b lbl_08022506
    .align 2, 0
lbl_080224dc: .4byte 0x03000738
lbl_080224e0: .4byte 0x030001ac
lbl_080224e4:
    ldr r3, lbl_0802253c @ =0x030001ac
    lsls r4, r5, #3
    subs r0, r4, r5
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r2, [r0, #2]
    adds r2, #0xa8
    mov r1, ip
    ldrb r0, [r1, #0x1e]
    subs r0, #6
    movs r1, #0x64
    muls r0, r1, r0
    adds r2, r2, r0
    mov r0, ip
    strh r2, [r0, #2]
    adds r1, r3, #0
    adds r2, r4, #0
lbl_08022506:
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x24
    bne lbl_08022534
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    adds r1, #8
    movs r0, #6
    strb r0, [r1]
    mov r1, ip
    ldrb r0, [r1, #0x1e]
    cmp r0, #6
    bne lbl_08022534
    ldr r0, lbl_08022540 @ =0x082d7894
    str r0, [r1, #0x18]
    adds r1, #0x22
    movs r0, #4
    strb r0, [r1]
lbl_08022534:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802253c: .4byte 0x030001ac
lbl_08022540: .4byte 0x082d7894

    thumb_func_start DeoremSegmentSpawnGoingUpAfter
DeoremSegmentSpawnGoingUpAfter: @ 0x08022544
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0xc
    ldr r2, lbl_08022604 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r6, [r0]
    movs r7, #0x10
    ldr r0, lbl_08022608 @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r1, [r1]
    adds r4, r2, #0
    mov sb, r0
    cmp r1, #0x25
    bne lbl_08022570
    movs r7, #8
lbl_08022570:
    ldrh r0, [r4, #2]
    subs r0, r0, r7
    strh r0, [r4, #2]
    adds r5, r4, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    cmp r0, #0
    bne lbl_080225b0
    movs r0, #0x64
    adds r1, r7, #0
    bl __divsi3
    strb r0, [r5]
    ldrb r0, [r5]
    muls r0, r7, r0
    ldrh r1, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
    ldrh r0, [r4, #0x16]
    adds r0, #1
    strh r0, [r4, #0x16]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_080225b0
    mov r0, r8
    strh r0, [r4, #0x16]
lbl_080225b0:
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    add r0, sb
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x26
    bne lbl_080225f6
    ldrb r0, [r4, #0x1e]
    subs r0, #6
    lsls r0, r0, #2
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
    subs r1, #0xa
    movs r0, #0x11
    strb r0, [r1]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0xb
    bne lbl_080225f6
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    adds r0, #0x64
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #9
    movs r1, #0x13
    bl SpriteSpawnSecondary
lbl_080225f6:
    add sp, #0xc
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022604: .4byte 0x03000738
lbl_08022608: .4byte 0x030001ac

    thumb_func_start DeoremSegmentRightIdleAnim
DeoremSegmentRightIdleAnim: @ 0x0802260c
    push {r4, r5, r6, r7, lr}
    sub sp, #0xc
    ldr r0, lbl_08022660 @ =0x03000738
    mov ip, r0
    mov r5, ip
    adds r5, #0x23
    ldrb r1, [r5]
    ldr r2, lbl_08022664 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r2
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    mov r4, ip
    cmp r3, #0
    beq lbl_0802270c
    subs r0, #8
    ldrb r0, [r0]
    cmp r0, #0x28
    bne lbl_080226d8
    ldrb r0, [r4, #0x1c]
    adds r0, #4
    strb r0, [r4, #0x1c]
    ldrb r6, [r4, #0x1f]
    ldrb r7, [r5]
    ldrh r0, [r4, #2]
    adds r0, #0x18
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r0, lbl_08022668 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_0802266c
    ldrh r0, [r4, #4]
    subs r0, #0x60
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r5, #0
    b lbl_08022678
    .align 2, 0
lbl_08022660: .4byte 0x03000738
lbl_08022664: .4byte 0x030001ac
lbl_08022668: .4byte 0x0300080c
lbl_0802266c:
    mov r1, ip
    ldrh r0, [r1, #4]
    adds r0, #0x60
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r5, #0x40
lbl_08022678:
    ldrb r0, [r4, #0x1e]
    cmp r0, #1
    bne lbl_0802268e
    cmp r3, #0xf1
    bne lbl_0802268e
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #0
    b lbl_080226ce
lbl_0802268e:
    ldrb r0, [r4, #0x1e]
    cmp r0, #2
    bne lbl_080226a4
    cmp r3, #0xb5
    bne lbl_080226a4
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #1
    b lbl_080226ce
lbl_080226a4:
    ldrb r0, [r4, #0x1e]
    cmp r0, #3
    bne lbl_080226ba
    cmp r3, #0x65
    bne lbl_080226ba
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #2
    b lbl_080226ce
lbl_080226ba:
    ldrb r0, [r4, #0x1e]
    cmp r0, #4
    bne lbl_08022748
    cmp r3, #0x15
    bne lbl_08022748
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #3
lbl_080226ce:
    adds r2, r6, #0
    adds r3, r7, #0
    bl SpriteSpawnSecondary
    b lbl_08022748
lbl_080226d8:
    mov r4, ip
    adds r4, #0x2e
    ldrb r2, [r4]
    ldr r3, lbl_08022704 @ =0x082d5ba0
    lsls r0, r2, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r0, lbl_08022708 @ =0x00007fff
    cmp r1, r0
    bne lbl_080226f4
    movs r0, #0
    ldrsh r1, [r3, r0]
    movs r2, #0
lbl_080226f4:
    adds r0, r2, #1
    strb r0, [r4]
    mov r2, ip
    ldrh r0, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    b lbl_08022748
    .align 2, 0
lbl_08022704: .4byte 0x082d5ba0
lbl_08022708: .4byte 0x00007fff
lbl_0802270c:
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x26
    bne lbl_08022724
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x33
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x19
    b lbl_08022746
lbl_08022724:
    cmp r0, #0x27
    bne lbl_08022736
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x35
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x19
    b lbl_08022746
lbl_08022736:
    cmp r0, #0x44
    bne lbl_08022748
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x46
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x2e
lbl_08022746:
    strb r0, [r1]
lbl_08022748:
    add sp, #0xc
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start DeoremSegmentLeftIdleAnim
DeoremSegmentLeftIdleAnim: @ 0x08022750
    push {r4, r5, r6, r7, lr}
    sub sp, #0xc
    ldr r0, lbl_0802279c @ =0x03000738
    mov ip, r0
    mov r5, ip
    adds r5, #0x23
    ldrb r1, [r5]
    ldr r2, lbl_080227a0 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r2
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    mov r4, ip
    cmp r3, #0
    beq lbl_08022848
    subs r0, #8
    ldrb r0, [r0]
    cmp r0, #0x29
    bne lbl_08022814
    ldrb r0, [r4, #0x1c]
    adds r0, #4
    strb r0, [r4, #0x1c]
    ldrb r6, [r4, #0x1f]
    ldrb r7, [r5]
    ldrh r2, [r4, #2]
    ldr r0, lbl_080227a4 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_080227a8
    ldrh r0, [r4, #4]
    adds r0, #0x60
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r5, #0x40
    b lbl_080227b4
    .align 2, 0
lbl_0802279c: .4byte 0x03000738
lbl_080227a0: .4byte 0x030001ac
lbl_080227a4: .4byte 0x0300080c
lbl_080227a8:
    mov r1, ip
    ldrh r0, [r1, #4]
    subs r0, #0x60
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r5, #0
lbl_080227b4:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0xa
    bne lbl_080227ca
    cmp r3, #0xf1
    bne lbl_080227ca
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #0
    b lbl_0802280a
lbl_080227ca:
    ldrb r0, [r4, #0x1e]
    cmp r0, #9
    bne lbl_080227e0
    cmp r3, #0xb5
    bne lbl_080227e0
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #1
    b lbl_0802280a
lbl_080227e0:
    ldrb r0, [r4, #0x1e]
    cmp r0, #8
    bne lbl_080227f6
    cmp r3, #0x65
    bne lbl_080227f6
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #2
    b lbl_0802280a
lbl_080227f6:
    ldrb r0, [r4, #0x1e]
    cmp r0, #7
    bne lbl_0802288a
    cmp r3, #0x15
    bne lbl_0802288a
    str r2, [sp]
    str r1, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0xb
    movs r1, #3
lbl_0802280a:
    adds r2, r6, #0
    adds r3, r7, #0
    bl SpriteSpawnSecondary
    b lbl_0802288a
lbl_08022814:
    mov r4, ip
    adds r4, #0x2e
    ldrb r2, [r4]
    ldr r3, lbl_08022840 @ =0x082d5ba0
    lsls r0, r2, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r0, lbl_08022844 @ =0x00007fff
    cmp r1, r0
    bne lbl_08022830
    movs r0, #0
    ldrsh r1, [r3, r0]
    movs r2, #0
lbl_08022830:
    adds r0, r2, #1
    strb r0, [r4]
    mov r2, ip
    ldrh r0, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    b lbl_0802288a
    .align 2, 0
lbl_08022840: .4byte 0x082d5ba0
lbl_08022844: .4byte 0x00007fff
lbl_08022848:
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x26
    bne lbl_08022860
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x35
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x19
    b lbl_08022888
lbl_08022860:
    cmp r0, #0x27
    bne lbl_08022872
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x33
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x19
    b lbl_08022888
lbl_08022872:
    cmp r0, #0x44
    bne lbl_0802288a
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    adds r1, #8
    movs r0, #6
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x4c
lbl_08022888:
    strb r0, [r1]
lbl_0802288a:
    add sp, #0xc
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremSegmentGoingDown
DeoremSegmentGoingDown: @ 0x08022894
    push {r4, r5, lr}
    ldr r1, lbl_080228d8 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r2, [r0]
    adds r4, r1, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    adds r3, r1, #0
    cmp r0, #0
    beq lbl_080228b4
    subs r0, #1
    strb r0, [r4]
    ldrh r0, [r3, #2]
    adds r0, #4
    strh r0, [r3, #2]
lbl_080228b4:
    ldr r0, lbl_080228dc @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_080228e8
    ldrb r0, [r3, #0x1e]
    cmp r0, #5
    bls lbl_080228d0
    cmp r0, #0x12
    bne lbl_080228e0
lbl_080228d0:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0xf
    b lbl_080228e6
    .align 2, 0
lbl_080228d8: .4byte 0x03000738
lbl_080228dc: .4byte 0x030001ac
lbl_080228e0:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x11
lbl_080228e6:
    strb r0, [r1]
lbl_080228e8:
    movs r0, #0x2e
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    ldr r4, lbl_08022918 @ =0x082d5ba0
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r0, lbl_0802291c @ =0x00007fff
    cmp r1, r0
    bne lbl_08022906
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0
lbl_08022906:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #4]
    adds r0, r0, r1
    strh r0, [r3, #4]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022918: .4byte 0x082d5ba0
lbl_0802291c: .4byte 0x00007fff

    thumb_func_start DeoremSegmentGoingUp
DeoremSegmentGoingUp: @ 0x08022920
    push {r4, r5, lr}
    ldr r1, lbl_08022964 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r2, [r0]
    adds r4, r1, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    adds r3, r1, #0
    cmp r0, #0
    beq lbl_08022940
    subs r0, #1
    strb r0, [r4]
    ldrh r0, [r3, #2]
    subs r0, #4
    strh r0, [r3, #2]
lbl_08022940:
    ldr r0, lbl_08022968 @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08022974
    ldrb r0, [r3, #0x1e]
    cmp r0, #5
    bls lbl_0802295c
    cmp r0, #0x12
    bne lbl_0802296c
lbl_0802295c:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0xf
    b lbl_08022972
    .align 2, 0
lbl_08022964: .4byte 0x03000738
lbl_08022968: .4byte 0x030001ac
lbl_0802296c:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x11
lbl_08022972:
    strb r0, [r1]
lbl_08022974:
    movs r0, #0x2e
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    ldr r4, lbl_080229a4 @ =0x082d5ba0
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r0, lbl_080229a8 @ =0x00007fff
    cmp r1, r0
    bne lbl_08022992
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0
lbl_08022992:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #4]
    adds r0, r0, r1
    strh r0, [r3, #4]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080229a4: .4byte 0x082d5ba0
lbl_080229a8: .4byte 0x00007fff

    thumb_func_start DeoremSegmentAboveHeadMovement
DeoremSegmentAboveHeadMovement: @ 0x080229ac
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_080229d4 @ =0x03000738
    adds r1, r0, #0
    adds r1, #0x23
    ldrb r7, [r1]
    ldrb r1, [r0, #0x1e]
    adds r6, r0, #0
    cmp r1, #0xc
    bne lbl_080229dc
    ldr r2, lbl_080229d8 @ =0x030001ac
    lsls r3, r7, #3
    subs r1, r3, r7
    lsls r1, r1, #3
    adds r1, r1, r2
    ldrh r0, [r1, #2]
    subs r0, #0xa8
    strh r0, [r6, #2]
    ldrh r5, [r1, #4]
    mov ip, r2
    b lbl_08022a0a
    .align 2, 0
lbl_080229d4: .4byte 0x03000738
lbl_080229d8: .4byte 0x030001ac
lbl_080229dc:
    ldr r3, lbl_08022a14 @ =0x030001ac
    lsls r4, r7, #3
    subs r0, r4, r7
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r2, [r0, #2]
    subs r2, #0xa8
    ldrb r0, [r6, #0x1e]
    subs r0, #0xc
    movs r1, #0x64
    muls r0, r1, r0
    subs r2, r2, r0
    strh r2, [r6, #2]
    adds r0, r6, #0
    adds r0, #0x2c
    ldrb r1, [r0]
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r5, [r0, #4]
    mov ip, r3
    adds r3, r4, #0
lbl_08022a0a:
    ldrh r1, [r6, #4]
    cmp r1, r5
    bls lbl_08022a18
    subs r0, r1, r5
    b lbl_08022a1a
    .align 2, 0
lbl_08022a14: .4byte 0x030001ac
lbl_08022a18:
    subs r0, r5, r1
lbl_08022a1a:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #2
    bhi lbl_08022a26
    movs r2, #1
    b lbl_08022a28
lbl_08022a26:
    lsrs r2, r0, #2
lbl_08022a28:
    cmp r1, r5
    bhs lbl_08022a32
    ldrh r0, [r6, #4]
    adds r0, r2, r0
    b lbl_08022a3a
lbl_08022a32:
    cmp r1, r5
    bls lbl_08022a3c
    ldrh r0, [r6, #4]
    subs r0, r0, r2
lbl_08022a3a:
    strh r0, [r6, #4]
lbl_08022a3c:
    subs r0, r3, r7
    lsls r0, r0, #3
    mov r1, ip
    adds r2, r0, r1
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x44
    bne lbl_08022a5a
    ldrh r0, [r2, #4]
    strh r0, [r6, #4]
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x4a
    strb r0, [r1]
lbl_08022a5a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start DeoremSegmentLeftLeaving
DeoremSegmentLeftLeaving: @ 0x08022a60
    push {r4, r5, lr}
    ldr r1, lbl_08022adc @ =0x03000738
    ldrh r4, [r1, #2]
    adds r0, r4, #0
    subs r0, #0x10
    strh r0, [r1, #2]
    adds r5, r1, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    adds r2, r1, #0
    cmp r3, #0
    bne lbl_08022af8
    movs r0, #6
    strb r0, [r5]
    adds r0, r4, #0
    adds r0, #0x50
    strh r0, [r2, #2]
    ldrh r0, [r2, #0x16]
    adds r0, #1
    strh r0, [r2, #0x16]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08022a9a
    strh r3, [r2, #0x16]
lbl_08022a9a:
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r3, [r0]
    cmp r3, #0
    bne lbl_08022b02
    ldrb r0, [r2, #0x1e]
    cmp r0, #0x13
    bne lbl_08022aec
    adds r1, r2, #0
    adds r1, #0x27
    movs r0, #0x10
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    ldr r0, lbl_08022ae0 @ =0x0000ffd0
    strh r0, [r2, #0xa]
    movs r0, #0xa0
    strh r0, [r2, #0xc]
    ldr r0, lbl_08022ae4 @ =0x0000ffc0
    strh r0, [r2, #0xe]
    movs r0, #0x40
    strh r0, [r2, #0x10]
    ldr r0, lbl_08022ae8 @ =0x082d78e4
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r3, [r2, #0x16]
    movs r0, #0x38
    b lbl_08022aee
    .align 2, 0
lbl_08022adc: .4byte 0x03000738
lbl_08022ae0: .4byte 0x0000ffd0
lbl_08022ae4: .4byte 0x0000ffc0
lbl_08022ae8: .4byte 0x082d78e4
lbl_08022aec:
    movs r0, #0x2e
lbl_08022aee:
    strb r0, [r5]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
lbl_08022af8:
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08022b0c
lbl_08022b02:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
lbl_08022b0c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremSegmentLeftLeavingEnd
DeoremSegmentLeftLeavingEnd: @ 0x08022b14
    push {lr}
    ldr r2, lbl_08022b38 @ =0x03000738
    ldrh r0, [r2, #2]
    subs r0, #0x10
    strh r0, [r2, #2]
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08022b32
    strh r0, [r2]
lbl_08022b32:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022b38: .4byte 0x03000738

    thumb_func_start DeoremSegmentMiddleLeavingEnd
DeoremSegmentMiddleLeavingEnd: @ 0x08022b3c
    push {lr}
    ldr r2, lbl_08022b60 @ =0x03000738
    ldrh r0, [r2, #2]
    adds r0, #0x10
    strh r0, [r2, #2]
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08022b5a
    strh r0, [r2]
lbl_08022b5a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022b60: .4byte 0x03000738

    thumb_func_start DeoremSegmentMiddleLeaving
DeoremSegmentMiddleLeaving: @ 0x08022b64
    push {r4, r5, lr}
    ldr r1, lbl_08022b8c @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r5, [r0]
    ldrb r0, [r1, #0x1e]
    mov ip, r1
    cmp r0, #0xc
    bne lbl_08022b94
    ldr r1, lbl_08022b90 @ =0x030001ac
    lsls r2, r5, #3
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #2]
    subs r0, #0xa8
    mov r3, ip
    strh r0, [r3, #2]
    b lbl_08022bb6
    .align 2, 0
lbl_08022b8c: .4byte 0x03000738
lbl_08022b90: .4byte 0x030001ac
lbl_08022b94:
    ldr r3, lbl_08022bec @ =0x030001ac
    lsls r4, r5, #3
    subs r0, r4, r5
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r2, [r0, #2]
    subs r2, #0xa8
    mov r1, ip
    ldrb r0, [r1, #0x1e]
    subs r0, #0xc
    movs r1, #0x64
    muls r0, r1, r0
    subs r2, r2, r0
    mov r0, ip
    strh r2, [r0, #2]
    adds r1, r3, #0
    adds r2, r4, #0
lbl_08022bb6:
    subs r0, r2, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x45
    bne lbl_08022be4
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x4b
    strb r0, [r1]
    adds r1, #8
    movs r0, #6
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x14
    strb r0, [r1]
    mov r1, ip
    ldrb r0, [r1, #0x1e]
    cmp r0, #0xc
    bne lbl_08022be4
    ldr r0, lbl_08022bf0 @ =0x082d7894
    str r0, [r1, #0x18]
lbl_08022be4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022bec: .4byte 0x030001ac
lbl_08022bf0: .4byte 0x082d7894

    thumb_func_start DeoremSegmentRighLeaving
DeoremSegmentRighLeaving: @ 0x08022bf4
    push {r4, r5, lr}
    ldr r2, lbl_08022c84 @ =0x03000738
    ldrh r3, [r2, #2]
    adds r0, r3, #0
    adds r0, #0x10
    strh r0, [r2, #2]
    adds r5, r2, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    movs r4, #0xff
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_08022c7e
    movs r0, #6
    strb r0, [r5]
    adds r0, r3, #0
    subs r0, #0x50
    strh r0, [r2, #2]
    ldrh r0, [r2, #0x16]
    adds r0, #1
    strh r0, [r2, #0x16]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08022c2e
    strh r1, [r2, #0x16]
lbl_08022c2e:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    adds r3, r4, #0
    ands r3, r0
    cmp r3, #0
    bne lbl_08022c7e
    ldrb r0, [r2, #0x1e]
    cmp r0, #0x11
    bne lbl_08022c72
    subs r1, #6
    movs r0, #0x10
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    ldr r0, lbl_08022c88 @ =0x0000ffd0
    strh r0, [r2, #0xa]
    movs r0, #0xa0
    strh r0, [r2, #0xc]
    ldr r0, lbl_08022c8c @ =0x0000ffc0
    strh r0, [r2, #0xe]
    movs r0, #0x40
    strh r0, [r2, #0x10]
    ldr r0, lbl_08022c90 @ =0x082d78e4
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r3, [r2, #0x16]
lbl_08022c72:
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #0x4c
    strb r1, [r0]
    movs r0, #0x2e
    strb r0, [r5]
lbl_08022c7e:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022c84: .4byte 0x03000738
lbl_08022c88: .4byte 0x0000ffd0
lbl_08022c8c: .4byte 0x0000ffc0
lbl_08022c90: .4byte 0x082d78e4

    thumb_func_start DeoremSegmentRighLeavingEnd
DeoremSegmentRighLeavingEnd: @ 0x08022c94
    push {lr}
    ldr r2, lbl_08022cb8 @ =0x03000738
    ldrh r0, [r2, #2]
    adds r0, #0x10
    strh r0, [r2, #2]
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08022cb2
    strh r0, [r2]
lbl_08022cb2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022cb8: .4byte 0x03000738

    thumb_func_start DeoremSegmentSetTimerDying
DeoremSegmentSetTimerDying: @ 0x08022cbc
    push {lr}
    movs r2, #6
    ldr r1, lbl_08022cd4 @ =0x03000738
    ldrb r0, [r1, #0x1e]
    adds r3, r1, #0
    cmp r0, #0x13
    bhi lbl_08022d88
    lsls r0, r0, #2
    ldr r1, lbl_08022cd8 @ =lbl_08022cdc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08022cd4: .4byte 0x03000738
lbl_08022cd8: .4byte lbl_08022cdc
lbl_08022cdc: @ jump table
    .4byte lbl_08022d5a @ case 0
    .4byte lbl_08022d60 @ case 1
    .4byte lbl_08022d68 @ case 2
    .4byte lbl_08022d6e @ case 3
    .4byte lbl_08022d76 @ case 4
    .4byte lbl_08022d7c @ case 5
    .4byte lbl_08022d34 @ case 6
    .4byte lbl_08022d38 @ case 7
    .4byte lbl_08022d3c @ case 8
    .4byte lbl_08022d44 @ case 9
    .4byte lbl_08022d4a @ case 10
    .4byte lbl_08022d4e @ case 11
    .4byte lbl_08022d88 @ case 12
    .4byte lbl_08022d2c @ case 13
    .4byte lbl_08022d30 @ case 14
    .4byte lbl_08022d88 @ case 15
    .4byte lbl_08022d88 @ case 16
    .4byte lbl_08022d88 @ case 17
    .4byte lbl_08022d80 @ case 18
    .4byte lbl_08022d52 @ case 19
lbl_08022d2c:
    lsls r0, r2, #0x19
    b lbl_08022d86
lbl_08022d30:
    lsls r0, r2, #1
    b lbl_08022d82
lbl_08022d34:
    lsls r0, r2, #0x1a
    b lbl_08022d86
lbl_08022d38:
    lsls r0, r2, #2
    b lbl_08022d82
lbl_08022d3c:
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #0x19
    b lbl_08022d86
lbl_08022d44:
    lsls r0, r2, #3
    subs r0, r0, r2
    b lbl_08022d84
lbl_08022d4a:
    lsls r0, r2, #0x1b
    b lbl_08022d86
lbl_08022d4e:
    lsls r0, r2, #3
    b lbl_08022d82
lbl_08022d52:
    lsls r0, r2, #2
    adds r0, r0, r2
    lsls r0, r0, #0x19
    b lbl_08022d86
lbl_08022d5a:
    movs r0, #0xb
    muls r0, r2, r0
    b lbl_08022d84
lbl_08022d60:
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #0x1a
    b lbl_08022d86
lbl_08022d68:
    movs r0, #0xd
    muls r0, r2, r0
    b lbl_08022d84
lbl_08022d6e:
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #0x19
    b lbl_08022d86
lbl_08022d76:
    lsls r0, r2, #4
    subs r0, r0, r2
    b lbl_08022d84
lbl_08022d7c:
    lsls r0, r2, #0x1c
    b lbl_08022d86
lbl_08022d80:
    lsls r0, r2, #4
lbl_08022d82:
    adds r0, r0, r2
lbl_08022d84:
    lsls r0, r0, #0x18
lbl_08022d86:
    lsrs r2, r0, #0x18
lbl_08022d88:
    adds r1, r2, #0
    adds r1, #0x3c
    adds r0, r3, #0
    adds r0, #0x2c
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    adds r2, r3, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    pop {r0}
    bx r0

    thumb_func_start DeoremSegmentDying
DeoremSegmentDying: @ 0x08022db4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r1, lbl_08022dec @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x26
    movs r6, #1
    strb r6, [r0]
    ldrh r5, [r1, #4]
    ldrb r3, [r1, #0x1e]
    adds r4, r3, #0
    ldr r0, lbl_08022df0 @ =0x0300083c
    ldrb r0, [r0]
    lsls r0, r0, #0x19
    lsrs r2, r0, #0x18
    adds r7, r1, #0
    cmp r3, #0xb
    bls lbl_08022dde
    adds r0, r2, #0
    adds r0, #0x30
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08022dde:
    adds r0, r3, #0
    ands r0, r6
    cmp r0, #0
    beq lbl_08022df4
    adds r0, r5, r2
    adds r0, r0, r3
    b lbl_08022df8
    .align 2, 0
lbl_08022dec: .4byte 0x03000738
lbl_08022df0: .4byte 0x0300083c
lbl_08022df4:
    adds r0, r2, r4
    subs r0, r5, r0
lbl_08022df8:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r2, r7, #0
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    bne lbl_08022e3a
    ldrh r4, [r2, #2]
    movs r0, #0x21
    str r0, [sp]
    movs r0, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0
    bl SpriteUtilSpriteDeath
    ldr r0, lbl_08022e44 @ =0x0300080c
    ldrh r1, [r0]
    movs r2, #0xe0
    lsls r2, r2, #1
    adds r0, r1, r2
    cmp r4, r0
    bgt lbl_08022e38
    adds r0, r1, #0
    adds r0, #0x80
    cmp r4, r0
    bge lbl_08022e3a
lbl_08022e38:
    strh r6, [r7]
lbl_08022e3a:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08022e44: .4byte 0x0300080c

    thumb_func_start DeoremEyeInit
DeoremEyeInit: @ 0x08022e48
    push {r4, r5, r6, lr}
    ldr r6, lbl_08022ef0 @ =0x03000738
    ldrh r0, [r6]
    movs r4, #8
    movs r3, #0
    movs r5, #0
    adds r1, r4, #0
    orrs r1, r0
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r6, #0x12]
    ldr r0, lbl_08022ef4 @ =0x0000fffb
    ands r1, r0
    strh r1, [r6]
    adds r1, r6, #0
    adds r1, #0x22
    movs r0, #0xb
    strb r0, [r1]
    ldr r2, lbl_08022ef8 @ =0x082b1be4
    ldrb r1, [r6, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r6, #0x14]
    adds r0, r6, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_08022efc @ =0x0000ffc0
    strh r0, [r6, #0xa]
    movs r0, #0x30
    strh r0, [r6, #0xc]
    ldr r0, lbl_08022f00 @ =0x0000ffd8
    strh r0, [r6, #0xe]
    movs r0, #0x28
    strh r0, [r6, #0x10]
    ldr r0, lbl_08022f04 @ =0x082d792c
    str r0, [r6, #0x18]
    strb r3, [r6, #0x1c]
    strh r5, [r6, #0x16]
    adds r1, r6, #0
    adds r1, #0x33
    movs r0, #4
    strb r0, [r1]
    adds r0, r6, #0
    adds r0, #0x25
    strb r3, [r0]
    subs r0, #1
    strb r4, [r0]
    movs r0, #0xe1
    lsls r0, r0, #3
    strh r0, [r6, #6]
    movs r0, #3
    movs r1, #0x19
    bl EventFunction
    cmp r0, #0
    bne lbl_08022eda
    movs r0, #3
    movs r1, #0x1a
    bl EventFunction
    cmp r0, #0
    bne lbl_08022eda
    ldrh r0, [r6, #6]
    lsrs r0, r0, #1
    strh r0, [r6, #6]
lbl_08022eda:
    ldr r2, lbl_08022ef0 @ =0x03000738
    ldr r1, lbl_08022f08 @ =0x030013d4
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_08022f0c
    adds r0, r2, #0
    adds r0, #0x2a
    movs r1, #0x80
    b lbl_08022f12
    .align 2, 0
lbl_08022ef0: .4byte 0x03000738
lbl_08022ef4: .4byte 0x0000fffb
lbl_08022ef8: .4byte 0x082b1be4
lbl_08022efc: .4byte 0x0000ffc0
lbl_08022f00: .4byte 0x0000ffd8
lbl_08022f04: .4byte 0x082d792c
lbl_08022f08: .4byte 0x030013d4
lbl_08022f0c:
    adds r0, r2, #0
    adds r0, #0x2a
    movs r1, #0
lbl_08022f12:
    strb r1, [r0]
    adds r0, #2
    strb r1, [r0]
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #0
    strb r0, [r1]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremEyeSetPose9
DeoremEyeSetPose9: @ 0x08022f28
    ldr r0, lbl_08022f34 @ =0x03000738
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08022f34: .4byte 0x03000738

    thumb_func_start DeoremEyeMove
DeoremEyeMove: @ 0x08022f38
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #2
    ldr r2, lbl_08022f90 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    mov r8, r0
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r3, [r0]
    ldr r1, lbl_08022f94 @ =0x030013d4
    ldrh r0, [r1, #0x14]
    subs r0, #0x48
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    movs r0, #0x12
    ldrsh r4, [r1, r0]
    ldr r1, lbl_08022f98 @ =0x030001ac
    mov sb, r1
    mov r1, r8
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    add r0, sb
    movs r1, #2
    ldrsh r5, [r0, r1]
    movs r1, #4
    ldrsh r0, [r0, r1]
    mov ip, r0
    cmp r6, r5
    bge lbl_08022fa8
    subs r0, #0x40
    cmp r0, r4
    bge lbl_08022f84
    adds r0, #0x80
lbl_08022f84:
    cmp r4, ip
    ble lbl_08022f9c
    subs r0, r5, r6
    movs r1, #0xe0
    b lbl_08022fc2
    .align 2, 0
lbl_08022f90: .4byte 0x03000738
lbl_08022f94: .4byte 0x030013d4
lbl_08022f98: .4byte 0x030001ac
lbl_08022f9c:
    subs r0, r5, r6
    movs r1, #0xa0
    cmp r0, #0x3f
    bgt lbl_08022fd2
    movs r1, #0x80
    b lbl_08022fe8
lbl_08022fa8:
    mov r0, ip
    subs r0, #0x40
    cmp r0, r4
    bge lbl_08022fba
    adds r0, #0x80
    cmp r0, r4
    ble lbl_08022fba
    movs r1, #0x40
    b lbl_08022fe8
lbl_08022fba:
    cmp r4, ip
    ble lbl_08022fc8
    subs r0, r6, r5
    movs r1, #0x20
lbl_08022fc2:
    cmp r0, #0x3f
    bgt lbl_08022fd2
    b lbl_08022fd6
lbl_08022fc8:
    subs r0, r6, r5
    movs r1, #0x60
    cmp r0, #0x3f
    bgt lbl_08022fd2
    movs r1, #0x80
lbl_08022fd2:
    cmp r1, #0
    bne lbl_08022fe8
lbl_08022fd6:
    subs r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_080230a0
    cmp r3, #0x7f
    ble lbl_080230a6
    adds r0, r3, r7
    b lbl_080230a2
lbl_08022fe8:
    cmp r1, #0x20
    bne lbl_08023008
    adds r0, r3, #0
    subs r0, #0x21
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_080230a0
    adds r0, r3, #0
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_080230a6
    adds r0, r3, r7
    b lbl_080230a2
lbl_08023008:
    cmp r1, #0x40
    bne lbl_08023028
    adds r0, r3, #0
    subs r0, #0x41
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_080230a0
    adds r0, r3, #0
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_080230a6
    adds r0, r3, r7
    b lbl_080230a2
lbl_08023028:
    cmp r1, #0x60
    bne lbl_08023048
    adds r0, r3, #0
    subs r0, #0x61
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bls lbl_080230a0
    adds r0, r3, #0
    subs r0, #0x60
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7f
    bls lbl_080230a6
    adds r0, r3, r7
    b lbl_080230a2
lbl_08023048:
    cmp r1, #0x80
    bne lbl_08023060
    subs r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0802305a
    adds r0, r3, r7
    b lbl_080230a2
lbl_0802305a:
    cmp r3, #0x80
    ble lbl_080230a6
    b lbl_080230a0
lbl_08023060:
    cmp r1, #0xa0
    bne lbl_08023074
    adds r0, r3, #0
    subs r0, #0x21
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0802309c
    adds r0, r3, r7
    b lbl_080230a2
lbl_08023074:
    cmp r1, #0xc0
    bne lbl_08023088
    adds r0, r3, #0
    subs r0, #0x41
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0802309c
    adds r0, r3, r7
    b lbl_080230a2
lbl_08023088:
    cmp r1, #0xe0
    bne lbl_080230a6
    adds r0, r3, #0
    subs r0, #0x61
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x7e
    bhi lbl_0802309c
    adds r0, r3, r7
    b lbl_080230a2
lbl_0802309c:
    cmp r0, #0x7f
    bls lbl_080230a6
lbl_080230a0:
    subs r0, r3, r7
lbl_080230a2:
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
lbl_080230a6:
    mov r0, r8
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    add r1, sb
    ldrh r0, [r1, #2]
    subs r0, #0x1c
    strh r0, [r2, #2]
    ldrh r0, [r1, #4]
    subs r0, #4
    strh r0, [r2, #4]
    adds r0, r2, #0
    adds r0, #0x2c
    strb r3, [r0]
    subs r0, #2
    strb r3, [r0]
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080230d4
sub_080230d4: @ 0x080230d4
    push {r4, lr}
    ldr r4, lbl_08023108 @ =0x03000738
    ldr r0, [r4, #0x18]
    ldr r2, lbl_0802310c @ =0x082d792c
    cmp r0, r2
    bne lbl_08023118
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08023134
    ldr r0, lbl_08023110 @ =0x0300083c
    ldrb r1, [r0]
    cmp r1, #9
    bhi lbl_08023134
    ldr r0, lbl_08023114 @ =0x082d791c
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    adds r0, r1, #0
    adds r0, #8
    lsls r0, r0, #2
    adds r1, r4, #0
    adds r1, #0x2e
    strb r0, [r1]
    b lbl_08023134
    .align 2, 0
lbl_08023108: .4byte 0x03000738
lbl_0802310c: .4byte 0x082d792c
lbl_08023110: .4byte 0x0300083c
lbl_08023114: .4byte 0x082d791c
lbl_08023118:
    adds r1, r4, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08023134
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08023134
    str r2, [r4, #0x18]
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
lbl_08023134:
    bl DeoremEyeMove
    movs r0, #3
    movs r1, #0x19
    bl EventFunction
    cmp r0, #0
    bne lbl_08023158
    movs r0, #3
    movs r1, #0x1a
    bl EventFunction
    cmp r0, #0
    bne lbl_08023158
    ldr r0, lbl_0802316c @ =0x03000738
    ldrh r0, [r0, #0x14]
    cmp r0, #0x3c
    beq lbl_08023164
lbl_08023158:
    ldr r1, lbl_0802316c @ =0x03000738
    ldrh r0, [r1, #6]
    cmp r0, #0
    beq lbl_08023164
    subs r0, #1
    strh r0, [r1, #6]
lbl_08023164:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802316c: .4byte 0x03000738

    thumb_func_start DeoremEyeDyingGFXInit
DeoremEyeDyingGFXInit: @ 0x08023170
    ldr r3, lbl_0802319c @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r2, lbl_080231a0 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x24
    movs r2, #0
    movs r1, #0x62
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    ldr r0, lbl_080231a4 @ =0x082d791c
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r2, [r3, #0x16]
    bx lr
    .align 2, 0
lbl_0802319c: .4byte 0x03000738
lbl_080231a0: .4byte 0x030001ac
lbl_080231a4: .4byte 0x082d791c

    thumb_func_start DeoremEyeDyingSpinningAnim
DeoremEyeDyingSpinningAnim: @ 0x080231a8
    push {r4, lr}
    ldr r3, lbl_080231e8 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r4, [r0]
    ldr r1, lbl_080231ec @ =0x030001ac
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r2, r0, r1
    ldrh r0, [r2, #2]
    subs r0, #0x18
    strh r0, [r3, #2]
    ldrh r0, [r2, #4]
    subs r0, #4
    strh r0, [r3, #4]
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x68
    bne lbl_080231f0
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0x1e
    bhi lbl_080231f0
    adds r2, r3, #0
    adds r2, #0x2a
    ldrb r0, [r2]
    adds r0, #8
    b lbl_080231f8
    .align 2, 0
lbl_080231e8: .4byte 0x03000738
lbl_080231ec: .4byte 0x030001ac
lbl_080231f0:
    adds r2, r3, #0
    adds r2, #0x2a
    ldrb r0, [r2]
    adds r0, #4
lbl_080231f8:
    strb r0, [r2]
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r1, r0, r1
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r2, [r0]
    cmp r2, #0x68
    bne lbl_08023222
    adds r0, #8
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_08023222
    adds r0, r3, #0
    adds r0, #0x24
    strb r2, [r0]
    adds r1, r3, #0
    adds r1, #0x2c
    movs r0, #0x78
    strb r0, [r1]
lbl_08023222:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start DeoremEyeDyingMovingAnim
DeoremEyeDyingMovingAnim: @ 0x08023228
    push {r4, lr}
    ldr r1, lbl_08023264 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2a
    ldrb r0, [r2]
    adds r0, #0xc
    strb r0, [r2]
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    adds r3, r1, #0
    cmp r0, #0x63
    bhi lbl_08023248
    ldrh r0, [r3, #2]
    subs r0, #1
    strh r0, [r3, #2]
lbl_08023248:
    ldr r0, lbl_08023268 @ =0x0300080c
    movs r2, #0xd0
    lsls r2, r2, #1
    adds r1, r2, #0
    ldrh r0, [r0, #2]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r2, [r3, #4]
    subs r0, r1, #2
    cmp r2, r0
    bge lbl_0802326c
    adds r0, r2, #2
    b lbl_08023274
    .align 2, 0
lbl_08023264: .4byte 0x03000738
lbl_08023268: .4byte 0x0300080c
lbl_0802326c:
    adds r0, r1, #2
    cmp r2, r0
    ble lbl_08023276
    subs r0, r2, #2
lbl_08023274:
    strh r0, [r3, #4]
lbl_08023276:
    adds r2, r3, #0
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r4, r1, #0
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_080232cc
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080232ae
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
    b lbl_080232cc
lbl_080232ae:
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    cmp r4, #0
    bne lbl_080232cc
    strh r4, [r3]
    ldrh r0, [r3, #2]
    ldrh r1, [r3, #4]
    bl DeoremSpawnChargeBeam
    ldr r0, lbl_080232d4 @ =0x00000221
    bl SoundPlay
lbl_080232cc:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080232d4: .4byte 0x00000221

    thumb_func_start DeoremThornInit
DeoremThornInit: @ 0x080232d8
    push {r4, r5, r6, lr}
    ldr r3, lbl_08023378 @ =0x03000738
    ldrh r1, [r3]
    movs r0, #0x80
    movs r5, #0
    movs r2, #0
    adds r4, r0, #0
    orrs r4, r1
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r3, #0x12]
    adds r6, r3, #0
    adds r6, #0x2a
    strb r5, [r6]
    ldr r0, lbl_0802337c @ =0x0000fffb
    ands r4, r0
    strh r4, [r3]
    movs r0, #0x32
    adds r0, r0, r3
    mov ip, r0
    ldrb r1, [r0]
    movs r0, #4
    orrs r0, r1
    mov r1, ip
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_08023380 @ =0x0000ffe4
    strh r0, [r3, #0xa]
    movs r0, #0x1c
    strh r0, [r3, #0xc]
    ldr r0, lbl_08023384 @ =0x0000ffe8
    strh r0, [r3, #0xe]
    movs r0, #0x18
    strh r0, [r3, #0x10]
    ldr r0, lbl_08023388 @ =0x082d790c
    str r0, [r3, #0x18]
    strb r5, [r3, #0x1c]
    strh r2, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x2f
    movs r0, #0x14
    strb r0, [r1]
    subs r1, #0xb
    movs r0, #9
    strb r0, [r1]
    adds r1, #1
    movs r0, #4
    strb r0, [r1]
    subs r1, #3
    movs r0, #3
    strb r0, [r1]
    ldr r2, lbl_0802338c @ =0x082b1be4
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r3, #0x14]
    movs r0, #0x40
    ands r0, r4
    adds r2, r3, #0
    cmp r0, #0
    beq lbl_08023390
    movs r1, #0x80
    lsls r1, r1, #2
    adds r0, r1, #0
    adds r1, r4, #0
    orrs r1, r0
    strh r1, [r2]
    movs r0, #0x80
    strb r0, [r6]
    b lbl_08023398
    .align 2, 0
lbl_08023378: .4byte 0x03000738
lbl_0802337c: .4byte 0x0000fffb
lbl_08023380: .4byte 0x0000ffe4
lbl_08023384: .4byte 0x0000ffe8
lbl_08023388: .4byte 0x082d790c
lbl_0802338c: .4byte 0x082b1be4
lbl_08023390:
    ldr r0, lbl_080233ac @ =0x0000fdff
    ands r0, r4
    strh r0, [r2]
    strb r5, [r6]
lbl_08023398:
    ldrh r0, [r2]
    ldr r1, lbl_080233b0 @ =0x0000ffbf
    ands r1, r0
    strh r1, [r2]
    ldrh r0, [r2, #2]
    subs r0, #0xc
    strh r0, [r2, #2]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080233ac: .4byte 0x0000fdff
lbl_080233b0: .4byte 0x0000ffbf

    thumb_func_start DeoremThornSpawning
DeoremThornSpawning: @ 0x080233b4
    push {r4, r5, lr}
    ldr r4, lbl_080233e8 @ =0x03000738
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080233d6
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x23
    strb r1, [r0]
    ldr r0, lbl_080233ec @ =0x00000197
    bl SoundPlay
lbl_080233d6:
    ldrb r0, [r5]
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080233f0
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #5
    b lbl_080233f6
    .align 2, 0
lbl_080233e8: .4byte 0x03000738
lbl_080233ec: .4byte 0x00000197
lbl_080233f0:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #3
lbl_080233f6:
    strb r0, [r1]
    ldr r2, lbl_08023410 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08023414
    adds r1, r2, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0x20
    b lbl_0802341c
    .align 2, 0
lbl_08023410: .4byte 0x03000738
lbl_08023414:
    adds r1, r2, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    subs r0, #0x20
lbl_0802341c:
    strb r0, [r1]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start DeoremThornMovement
DeoremThornMovement: @ 0x08023424
    push {r4, r5, lr}
    ldr r1, lbl_08023454 @ =0x03000738
    movs r0, #0x2f
    adds r0, r0, r1
    mov ip, r0
    ldrb r2, [r0]
    ldr r5, lbl_08023458 @ =0x082d5be2
    lsls r0, r2, #1
    adds r0, r0, r5
    movs r4, #0
    ldrsh r3, [r0, r4]
    ldr r0, lbl_0802345c @ =0x00007fff
    adds r4, r1, #0
    cmp r3, r0
    bne lbl_08023460
    subs r0, r2, #1
    lsls r0, r0, #1
    adds r0, r0, r5
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r1, [r4, #2]
    adds r0, r0, r1
    b lbl_0802346e
    .align 2, 0
lbl_08023454: .4byte 0x03000738
lbl_08023458: .4byte 0x082d5be2
lbl_0802345c: .4byte 0x00007fff
lbl_08023460:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r0, ip
    strb r2, [r0]
    ldrh r0, [r4, #2]
    adds r0, r0, r3
lbl_0802346e:
    strh r0, [r4, #2]
    movs r3, #4
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080234bc
    cmp r2, #0x23
    bls lbl_0802348a
    adds r1, r4, #0
    adds r1, #0x2a
    movs r0, #0xb8
    b lbl_080234b4
lbl_0802348a:
    cmp r2, #0x20
    bls lbl_08023496
    adds r1, r4, #0
    adds r1, #0x2a
    movs r0, #0xb0
    b lbl_080234b4
lbl_08023496:
    cmp r2, #0x1c
    bls lbl_080234ac
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0x9f
    bls lbl_080234a8
    movs r0, #0xa0
    b lbl_080234b4
lbl_080234a8:
    adds r0, #8
    b lbl_080234b4
lbl_080234ac:
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0x10
lbl_080234b4:
    strb r0, [r1]
    ldrh r0, [r4, #4]
    adds r0, r3, r0
    b lbl_080234f8
lbl_080234bc:
    cmp r2, #0x23
    bls lbl_080234c8
    adds r1, r4, #0
    adds r1, #0x2a
    movs r0, #0xc8
    b lbl_080234f2
lbl_080234c8:
    cmp r2, #0x20
    bls lbl_080234d4
    adds r1, r4, #0
    adds r1, #0x2a
    movs r0, #0xd0
    b lbl_080234f2
lbl_080234d4:
    cmp r2, #0x1c
    bls lbl_080234ea
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0xe0
    bhi lbl_080234e6
    movs r0, #0xe0
    b lbl_080234f2
lbl_080234e6:
    subs r0, #8
    b lbl_080234f2
lbl_080234ea:
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    subs r0, #0x10
lbl_080234f2:
    strb r0, [r1]
    ldrh r0, [r4, #4]
    subs r0, r0, r3
lbl_080234f8:
    strh r0, [r4, #4]
    cmp r2, #0x20
    bls lbl_08023514
    ldrh r0, [r4, #2]
    subs r0, #0x20
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0802351c @ =0x030007f1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08023514
    movs r0, #0
    strh r0, [r4]
lbl_08023514:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802351c: .4byte 0x030007f1

    thumb_func_start Deorem
Deorem: @ 0x08023520
    push {lr}
    ldr r0, lbl_08023538 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x68
    bls lbl_0802352e
    b lbl_08023752
lbl_0802352e:
    lsls r0, r0, #2
    ldr r1, lbl_0802353c @ =lbl_08023540
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08023538: .4byte 0x03000738
lbl_0802353c: .4byte lbl_08023540
lbl_08023540: @ jump table
    .4byte lbl_080236e4 @ case 0
    .4byte lbl_08023752 @ case 1
    .4byte lbl_08023752 @ case 2
    .4byte lbl_08023752 @ case 3
    .4byte lbl_08023752 @ case 4
    .4byte lbl_08023752 @ case 5
    .4byte lbl_08023752 @ case 6
    .4byte lbl_08023752 @ case 7
    .4byte lbl_080236ea @ case 8
    .4byte lbl_080236f0 @ case 9
    .4byte lbl_08023752 @ case 10
    .4byte lbl_08023752 @ case 11
    .4byte lbl_08023752 @ case 12
    .4byte lbl_08023752 @ case 13
    .4byte lbl_08023752 @ case 14
    .4byte lbl_08023752 @ case 15
    .4byte lbl_08023752 @ case 16
    .4byte lbl_08023752 @ case 17
    .4byte lbl_08023752 @ case 18
    .4byte lbl_08023752 @ case 19
    .4byte lbl_08023752 @ case 20
    .4byte lbl_08023752 @ case 21
    .4byte lbl_08023752 @ case 22
    .4byte lbl_08023752 @ case 23
    .4byte lbl_08023752 @ case 24
    .4byte lbl_08023752 @ case 25
    .4byte lbl_08023752 @ case 26
    .4byte lbl_08023752 @ case 27
    .4byte lbl_08023752 @ case 28
    .4byte lbl_08023752 @ case 29
    .4byte lbl_08023752 @ case 30
    .4byte lbl_08023752 @ case 31
    .4byte lbl_08023752 @ case 32
    .4byte lbl_08023752 @ case 33
    .4byte lbl_080236f6 @ case 34
    .4byte lbl_080236fc @ case 35
    .4byte lbl_08023702 @ case 36
    .4byte lbl_08023708 @ case 37
    .4byte lbl_0802370e @ case 38
    .4byte lbl_08023714 @ case 39
    .4byte lbl_0802371a @ case 40
    .4byte lbl_0802371a @ case 41
    .4byte lbl_08023720 @ case 42
    .4byte lbl_08023752 @ case 43
    .4byte lbl_08023752 @ case 44
    .4byte lbl_08023752 @ case 45
    .4byte lbl_08023752 @ case 46
    .4byte lbl_08023752 @ case 47
    .4byte lbl_08023752 @ case 48
    .4byte lbl_08023752 @ case 49
    .4byte lbl_08023752 @ case 50
    .4byte lbl_08023752 @ case 51
    .4byte lbl_08023752 @ case 52
    .4byte lbl_08023752 @ case 53
    .4byte lbl_08023752 @ case 54
    .4byte lbl_08023752 @ case 55
    .4byte lbl_08023752 @ case 56
    .4byte lbl_08023752 @ case 57
    .4byte lbl_08023752 @ case 58
    .4byte lbl_08023752 @ case 59
    .4byte lbl_08023752 @ case 60
    .4byte lbl_08023752 @ case 61
    .4byte lbl_08023752 @ case 62
    .4byte lbl_08023752 @ case 63
    .4byte lbl_08023752 @ case 64
    .4byte lbl_08023752 @ case 65
    .4byte lbl_08023736 @ case 66
    .4byte lbl_0802373c @ case 67
    .4byte lbl_08023742 @ case 68
    .4byte lbl_08023748 @ case 69
    .4byte lbl_08023752 @ case 70
    .4byte lbl_08023752 @ case 71
    .4byte lbl_08023752 @ case 72
    .4byte lbl_08023752 @ case 73
    .4byte lbl_08023752 @ case 74
    .4byte lbl_08023752 @ case 75
    .4byte lbl_08023752 @ case 76
    .4byte lbl_08023752 @ case 77
    .4byte lbl_08023752 @ case 78
    .4byte lbl_08023752 @ case 79
    .4byte lbl_08023752 @ case 80
    .4byte lbl_08023752 @ case 81
    .4byte lbl_08023752 @ case 82
    .4byte lbl_08023752 @ case 83
    .4byte lbl_08023752 @ case 84
    .4byte lbl_08023752 @ case 85
    .4byte lbl_08023752 @ case 86
    .4byte lbl_08023752 @ case 87
    .4byte lbl_08023752 @ case 88
    .4byte lbl_08023752 @ case 89
    .4byte lbl_08023752 @ case 90
    .4byte lbl_08023752 @ case 91
    .4byte lbl_08023752 @ case 92
    .4byte lbl_08023752 @ case 93
    .4byte lbl_08023752 @ case 94
    .4byte lbl_08023752 @ case 95
    .4byte lbl_0802374e @ case 96
    .4byte lbl_08023752 @ case 97
    .4byte lbl_08023726 @ case 98
    .4byte lbl_08023752 @ case 99
    .4byte lbl_08023752 @ case 100
    .4byte lbl_08023752 @ case 101
    .4byte lbl_08023752 @ case 102
    .4byte lbl_0802372a @ case 103
    .4byte lbl_08023730 @ case 104
lbl_080236e4:
    bl DeoremInit
    b lbl_08023752
lbl_080236ea:
    bl DeoremSpawnGoingDown
    b lbl_08023752
lbl_080236f0:
    bl DeoremSpawnGoingDownAnim
    b lbl_08023752
lbl_080236f6:
    bl DeoremSpawnGoingUp
    b lbl_08023752
lbl_080236fc:
    bl DeoremSpawnGoingUpAnim
    b lbl_08023752
lbl_08023702:
    bl DeoremSpawnHeadBody
    b lbl_08023752
lbl_08023708:
    bl DeoremAfterSpawn
    b lbl_08023752
lbl_0802370e:
    bl sub_08021880
    b lbl_08023752
lbl_08023714:
    bl DeoremRetracting
    b lbl_08023752
lbl_0802371a:
    bl DeoremThrowingThorns
    b lbl_08023752
lbl_08023720:
    bl DeoremAfterThorns
    b lbl_08023752
lbl_08023726:
    bl DeoremDying
lbl_0802372a:
    bl DeoremDyingGoingDown
    b lbl_08023752
lbl_08023730:
    bl DeoremDeath
    b lbl_08023752
lbl_08023736:
    bl DeoremCheckLeaving_to_ceiling_anim_ended
    b lbl_08023752
lbl_0802373c:
    bl DeoremLeaving
    b lbl_08023752
lbl_08023742:
    bl DeoremLeavingAnim
    b lbl_08023752
lbl_08023748:
    bl DeoremLeavingInGroundDebris
    b lbl_08023752
lbl_0802374e:
    bl DeoremCallSpawnChargeBeam
lbl_08023752:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremSegment
DeoremSegment: @ 0x08023758
    push {r4, r5, lr}
    ldr r3, lbl_080237dc @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r2, [r0]
    ldr r0, lbl_080237e0 @ =0x030001ac
    lsls r1, r2, #3
    subs r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r4, r1, #0
    adds r4, #0x24
    ldrb r1, [r4]
    adds r5, r0, #0
    cmp r1, #0x61
    bls lbl_08023792
    adds r1, r3, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrb r0, [r4]
    cmp r0, #0x68
    bne lbl_08023792
    subs r1, #2
    ldrb r0, [r1]
    cmp r0, #0x61
    bhi lbl_08023792
    movs r0, #0x62
    strb r0, [r1]
lbl_08023792:
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r2, r0, r5
    adds r5, r2, #0
    adds r5, #0x34
    ldrb r1, [r5]
    cmp r1, #2
    bne lbl_080237aa
    adds r0, r3, #0
    adds r0, #0x34
    strb r1, [r0]
lbl_080237aa:
    adds r0, r2, #0
    adds r0, #0x20
    ldrb r4, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, #0x13
    ldrb r0, [r0]
    adds r1, r1, r0
    movs r0, #0xe
    subs r0, r0, r1
    cmp r4, r0
    bne lbl_080237e4
    adds r0, r3, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r3, #0x1f]
    adds r0, r0, r1
    movs r1, #0xe
    subs r1, r1, r0
    adds r0, r3, #0
    adds r0, #0x20
    strb r1, [r0]
    ldrb r0, [r3, #0x1c]
    adds r0, #1
    strb r0, [r3, #0x1c]
    b lbl_080237f4
    .align 2, 0
lbl_080237dc: .4byte 0x03000738
lbl_080237e0: .4byte 0x030001ac
lbl_080237e4:
    ldrb r5, [r5]
    cmp r4, r5
    bne lbl_080237f4
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
lbl_080237f4:
    adds r0, r3, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    bls lbl_08023800
    b lbl_08023a18
lbl_08023800:
    lsls r0, r0, #2
    ldr r1, lbl_0802380c @ =lbl_08023810
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802380c: .4byte lbl_08023810
lbl_08023810: @ jump table
    .4byte lbl_080239b0 @ case 0
    .4byte lbl_08023a18 @ case 1
    .4byte lbl_08023a18 @ case 2
    .4byte lbl_08023a18 @ case 3
    .4byte lbl_08023a18 @ case 4
    .4byte lbl_08023a18 @ case 5
    .4byte lbl_08023a18 @ case 6
    .4byte lbl_08023a18 @ case 7
    .4byte lbl_080239b6 @ case 8
    .4byte lbl_080239bc @ case 9
    .4byte lbl_08023a18 @ case 10
    .4byte lbl_08023a18 @ case 11
    .4byte lbl_08023a18 @ case 12
    .4byte lbl_08023a18 @ case 13
    .4byte lbl_08023a18 @ case 14
    .4byte lbl_080239c2 @ case 15
    .4byte lbl_08023a18 @ case 16
    .4byte lbl_080239d4 @ case 17
    .4byte lbl_08023a18 @ case 18
    .4byte lbl_08023a18 @ case 19
    .4byte lbl_08023a18 @ case 20
    .4byte lbl_08023a18 @ case 21
    .4byte lbl_08023a18 @ case 22
    .4byte lbl_08023a18 @ case 23
    .4byte lbl_08023a18 @ case 24
    .4byte lbl_08023a18 @ case 25
    .4byte lbl_08023a18 @ case 26
    .4byte lbl_08023a18 @ case 27
    .4byte lbl_08023a18 @ case 28
    .4byte lbl_08023a18 @ case 29
    .4byte lbl_08023a18 @ case 30
    .4byte lbl_08023a18 @ case 31
    .4byte lbl_08023a18 @ case 32
    .4byte lbl_08023a18 @ case 33
    .4byte lbl_080239c8 @ case 34
    .4byte lbl_080239ce @ case 35
    .4byte lbl_080239e6 @ case 36
    .4byte lbl_08023a18 @ case 37
    .4byte lbl_08023a18 @ case 38
    .4byte lbl_08023a18 @ case 39
    .4byte lbl_08023a18 @ case 40
    .4byte lbl_08023a18 @ case 41
    .4byte lbl_08023a18 @ case 42
    .4byte lbl_08023a18 @ case 43
    .4byte lbl_08023a18 @ case 44
    .4byte lbl_08023a18 @ case 45
    .4byte lbl_08023a18 @ case 46
    .4byte lbl_08023a18 @ case 47
    .4byte lbl_08023a18 @ case 48
    .4byte lbl_08023a18 @ case 49
    .4byte lbl_08023a18 @ case 50
    .4byte lbl_080239da @ case 51
    .4byte lbl_08023a18 @ case 52
    .4byte lbl_080239e0 @ case 53
    .4byte lbl_08023a18 @ case 54
    .4byte lbl_08023a18 @ case 55
    .4byte lbl_08023a18 @ case 56
    .4byte lbl_08023a18 @ case 57
    .4byte lbl_08023a18 @ case 58
    .4byte lbl_08023a18 @ case 59
    .4byte lbl_08023a18 @ case 60
    .4byte lbl_08023a18 @ case 61
    .4byte lbl_08023a18 @ case 62
    .4byte lbl_08023a18 @ case 63
    .4byte lbl_08023a18 @ case 64
    .4byte lbl_08023a18 @ case 65
    .4byte lbl_080239f6 @ case 66
    .4byte lbl_080239fc @ case 67
    .4byte lbl_08023a18 @ case 68
    .4byte lbl_08023a18 @ case 69
    .4byte lbl_08023a02 @ case 70
    .4byte lbl_08023a18 @ case 71
    .4byte lbl_08023a18 @ case 72
    .4byte lbl_08023a18 @ case 73
    .4byte lbl_08023a08 @ case 74
    .4byte lbl_08023a0e @ case 75
    .4byte lbl_08023a14 @ case 76
    .4byte lbl_08023a18 @ case 77
    .4byte lbl_08023a18 @ case 78
    .4byte lbl_08023a18 @ case 79
    .4byte lbl_08023a18 @ case 80
    .4byte lbl_08023a18 @ case 81
    .4byte lbl_08023a18 @ case 82
    .4byte lbl_08023a18 @ case 83
    .4byte lbl_08023a18 @ case 84
    .4byte lbl_08023a18 @ case 85
    .4byte lbl_08023a18 @ case 86
    .4byte lbl_08023a18 @ case 87
    .4byte lbl_08023a18 @ case 88
    .4byte lbl_08023a18 @ case 89
    .4byte lbl_08023a18 @ case 90
    .4byte lbl_08023a18 @ case 91
    .4byte lbl_08023a18 @ case 92
    .4byte lbl_08023a18 @ case 93
    .4byte lbl_08023a18 @ case 94
    .4byte lbl_08023a18 @ case 95
    .4byte lbl_08023a18 @ case 96
    .4byte lbl_08023a18 @ case 97
    .4byte lbl_080239ec @ case 98
    .4byte lbl_08023a18 @ case 99
    .4byte lbl_08023a18 @ case 100
    .4byte lbl_08023a18 @ case 101
    .4byte lbl_08023a18 @ case 102
    .4byte lbl_080239f0 @ case 103
lbl_080239b0:
    bl DeoremSegmentInit
    b lbl_08023a18
lbl_080239b6:
    bl DeoremSegmentSpawnGoingDown
    b lbl_08023a18
lbl_080239bc:
    bl DeoremSegmentSpawnGoingDownAfter
    b lbl_08023a18
lbl_080239c2:
    bl DeoremSegmentRightIdleAnim
    b lbl_08023a18
lbl_080239c8:
    bl DeoremSegmentSpawnGoingUp
    b lbl_08023a18
lbl_080239ce:
    bl DeoremSegmentSpawnGoingUpAfter
    b lbl_08023a18
lbl_080239d4:
    bl DeoremSegmentLeftIdleAnim
    b lbl_08023a18
lbl_080239da:
    bl DeoremSegmentGoingDown
    b lbl_08023a18
lbl_080239e0:
    bl DeoremSegmentGoingUp
    b lbl_08023a18
lbl_080239e6:
    bl DeoremSegmentAboveHeadMovement
    b lbl_08023a18
lbl_080239ec:
    bl DeoremSegmentSetTimerDying
lbl_080239f0:
    bl DeoremSegmentDying
    b lbl_08023a18
lbl_080239f6:
    bl DeoremSegmentLeftLeaving
    b lbl_08023a18
lbl_080239fc:
    bl DeoremSegmentLeftLeavingEnd
    b lbl_08023a18
lbl_08023a02:
    bl DeoremSegmentMiddleLeavingEnd
    b lbl_08023a18
lbl_08023a08:
    bl DeoremSegmentMiddleLeaving
    b lbl_08023a18
lbl_08023a0e:
    bl DeoremSegmentRighLeaving
    b lbl_08023a18
lbl_08023a14:
    bl DeoremSegmentRighLeavingEnd
lbl_08023a18:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start DeoremEye
DeoremEye: @ 0x08023a20
    push {r4, r5, r6, r7, lr}
    ldr r3, lbl_08023ac0 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x26
    movs r7, #0
    movs r0, #1
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    bhi lbl_08023a9c
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r2, [r0]
    adds r0, #8
    ldrb r5, [r0]
    movs r1, #0x7f
    ands r1, r5
    cmp r1, #0
    beq lbl_08023a9c
    ldr r6, lbl_08023ac4 @ =0x030001ac
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r4, r0, #3
    adds r2, r4, r6
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x61
    bhi lbl_08023a9c
    adds r0, r2, #0
    adds r0, #0x2b
    strb r5, [r0]
    cmp r1, #0x10
    bne lbl_08023a9c
    adds r0, r6, #0
    adds r0, #0x18
    adds r0, r4, r0
    ldr r1, lbl_08023ac8 @ =0x082d7a84
    str r1, [r0]
    strb r7, [r2, #0x1c]
    strh r7, [r2, #0x16]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    ldrh r0, [r3, #0x14]
    cmp r0, #0x14
    bhi lbl_08023a88
    adds r1, r2, #0
    adds r1, #0x34
    movs r0, #2
    strb r0, [r1]
lbl_08023a88:
    ldrh r0, [r3]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r3]
    movs r0, #0xcd
    lsls r0, r0, #1
    bl SoundPlay
lbl_08023a9c:
    ldr r0, lbl_08023ac0 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    beq lbl_08023aee
    cmp r0, #0x67
    bgt lbl_08023ad2
    cmp r0, #0x62
    beq lbl_08023aea
    cmp r0, #0x62
    bgt lbl_08023af8
    cmp r0, #8
    beq lbl_08023ade
    cmp r0, #8
    bgt lbl_08023acc
    cmp r0, #0
    beq lbl_08023ad8
    b lbl_08023af8
    .align 2, 0
lbl_08023ac0: .4byte 0x03000738
lbl_08023ac4: .4byte 0x030001ac
lbl_08023ac8: .4byte 0x082d7a84
lbl_08023acc:
    cmp r0, #9
    beq lbl_08023ae4
    b lbl_08023af8
lbl_08023ad2:
    cmp r0, #0x68
    beq lbl_08023af4
    b lbl_08023af8
lbl_08023ad8:
    bl DeoremEyeInit
    b lbl_08023af8
lbl_08023ade:
    bl DeoremEyeSetPose9
    b lbl_08023af8
lbl_08023ae4:
    bl sub_080230d4
    b lbl_08023af8
lbl_08023aea:
    bl DeoremEyeDyingGFXInit
lbl_08023aee:
    bl DeoremEyeDyingSpinningAnim
    b lbl_08023af8
lbl_08023af4:
    bl DeoremEyeDyingMovingAnim
lbl_08023af8:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08023b00:
    .byte 0x00, 0xB5, 0x81, 0xB0, 0x05, 0x49, 0x08, 0x1C, 0x24, 0x30, 0x00, 0x78, 0x0A, 0x1C, 0x09, 0x28
    .byte 0x0B, 0xD0, 0x09, 0x28, 0x04, 0xDC, 0x00, 0x28, 0x05, 0xD0, 0x0C, 0xE0, 0x38, 0x07, 0x00, 0x03
    .byte 0x23, 0x28, 0x05, 0xD0, 0x07, 0xE0, 0xFF, 0xF7, 0xD7, 0xFB, 0xFF, 0xF7, 0x43, 0xFC, 0x0A, 0xE0
    .byte 0xFF, 0xF7, 0x78, 0xFC, 0x07, 0xE0, 0x51, 0x88, 0x92, 0x88, 0x20, 0x20, 0x00, 0x90, 0x00, 0x20
    .byte 0x01, 0x23, 0xED, 0xF7, 0x9F, 0xFA, 0x01, 0xB0, 0x01, 0xBC, 0x00, 0x47
