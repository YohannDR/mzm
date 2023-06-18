    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start WorkerRobotCheckSamusInFront
WorkerRobotCheckSamusInFront: @ 0x0802f534
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    ldr r0, lbl_0802f5d4 @ =gCurrentSprite
    mov sl, r0
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    cmp r0, #0
    bne lbl_0802f5e4
    mov r4, sl
    ldrh r1, [r4, #2]
    ldrh r5, [r4, #4]
    mov sb, r5
    adds r0, r1, #0
    subs r0, #0xa4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r2, sb
    subs r2, #0x48
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov r3, sb
    adds r3, #0x48
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, lbl_0802f5d8 @ =gSamusData
    ldrh r6, [r4, #0x14]
    mov r8, r6
    ldrh r7, [r4, #0x12]
    ldr r4, lbl_0802f5dc @ =gSamusPhysics
    mov ip, r4
    adds r4, #0x70
    ldrh r6, [r4]
    add r6, r8
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    mov r4, ip
    adds r4, #0x74
    ldrh r4, [r4]
    add r8, r4
    mov r5, r8
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    mov r8, r5
    mov r4, ip
    adds r4, #0x6e
    ldrh r5, [r4]
    adds r5, r7, r5
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    adds r4, #4
    ldrh r4, [r4]
    adds r4, r7, r4
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    str r6, [sp]
    mov r6, r8
    str r6, [sp, #4]
    str r5, [sp, #8]
    str r4, [sp, #0xc]
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0802f5e4
    mov r0, sl
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f5e0
    cmp sb, r7
    bhs lbl_0802f5e4
lbl_0802f5ce:
    movs r0, #1
    b lbl_0802f5e6
    .align 2, 0
lbl_0802f5d4: .4byte gCurrentSprite
lbl_0802f5d8: .4byte gSamusData
lbl_0802f5dc: .4byte gSamusPhysics
lbl_0802f5e0:
    cmp sb, r7
    bhi lbl_0802f5ce
lbl_0802f5e4:
    movs r0, #0
lbl_0802f5e6:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start WorkerRobotInit
WorkerRobotInit: @ 0x0802f5f8
    push {r4, r5, lr}
    ldr r4, lbl_0802f678 @ =gCurrentSprite
    movs r5, #0
    movs r1, #0
    ldr r0, lbl_0802f67c @ =0x0000ff8c
    strh r0, [r4, #0xa]
    strh r1, [r4, #0xc]
    adds r0, #0x58
    strh r0, [r4, #0xe]
    movs r0, #0x1c
    strh r0, [r4, #0x10]
    adds r2, r4, #0
    adds r2, #0x27
    movs r0, #0x28
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x28
    strb r5, [r0]
    adds r2, #2
    movs r0, #0x10
    strb r0, [r2]
    ldr r0, lbl_0802f680 @ =0x082e7bcc
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r1, [r4, #0x16]
    adds r2, #9
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r5, [r0]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #1
    strb r0, [r1]
    ldr r2, lbl_0802f684 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    bl SpriteUtilMakeSpriteFaceAwawFromSamusXFlip
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f66a
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
lbl_0802f66a:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x11
    strb r0, [r1]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802f678: .4byte gCurrentSprite
lbl_0802f67c: .4byte 0x0000ff8c
lbl_0802f680: .4byte 0x082e7bcc
lbl_0802f684: .4byte 0x082b0d68

    thumb_func_start WorkerRobotSleepingInit
WorkerRobotSleepingInit: @ 0x0802f688
    ldr r1, lbl_0802f6a0 @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x11
    strb r0, [r2]
    ldr r0, lbl_0802f6a4 @ =0x082e7bcc
    str r0, [r1, #0x18]
    movs r0, #0
    strh r3, [r1, #0x16]
    strb r0, [r1, #0x1c]
    bx lr
    .align 2, 0
lbl_0802f6a0: .4byte gCurrentSprite
lbl_0802f6a4: .4byte 0x082e7bcc

    thumb_func_start WorkerRobotSleeping
WorkerRobotSleeping: @ 0x0802f6a8
    push {r4, lr}
    ldr r4, lbl_0802f6c0 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802f6c4
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x20
    b lbl_0802f6d8
    .align 2, 0
lbl_0802f6c0: .4byte gCurrentSprite
lbl_0802f6c4:
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f6da
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x12
lbl_0802f6d8:
    strb r0, [r1]
lbl_0802f6da:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start WorkerRobotWakingUpInit
WorkerRobotWakingUpInit: @ 0x0802f6e0
    push {lr}
    ldr r1, lbl_0802f70c @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x13
    strb r0, [r2]
    ldr r0, lbl_0802f710 @ =0x082e7c0c
    str r0, [r1, #0x18]
    movs r0, #0
    strh r3, [r1, #0x16]
    strb r0, [r1, #0x1c]
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f708
    ldr r0, lbl_0802f714 @ =0x0000026f
    bl SoundPlayNotAlreadyPlaying
lbl_0802f708:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802f70c: .4byte gCurrentSprite
lbl_0802f710: .4byte 0x082e7c0c
lbl_0802f714: .4byte 0x0000026f

    thumb_func_start WorkerRobotChecWakingUpAnimEnded
WorkerRobotChecWakingUpAnimEnded: @ 0x0802f718
    push {lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802f72a
    ldr r0, lbl_0802f730 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0xe
    strb r1, [r0]
lbl_0802f72a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802f730: .4byte gCurrentSprite

    thumb_func_start WorkerRobotWalkingDetectProjectile
WorkerRobotWalkingDetectProjectile: @ 0x0802f734
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    movs r0, #0
    mov r8, r0
    ldr r3, lbl_0802f828 @ =gCurrentSprite
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    ldrh r0, [r3, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrh r0, [r3, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
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
    ldr r4, lbl_0802f82c @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r4, r1
    cmp r4, r0
    blo lbl_0802f77e
    b lbl_0802f8ba
lbl_0802f77e:
    ldrb r0, [r4]
    movs r1, #0x11
    ands r0, r1
    cmp r0, #0x11
    beq lbl_0802f78a
    b lbl_0802f8b0
lbl_0802f78a:
    ldrb r0, [r4, #0xf]
    str r0, [sp, #0x10]
    subs r0, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_0802f79a
    b lbl_0802f8b0
lbl_0802f79a:
    ldrh r6, [r4, #8]
    ldrh r5, [r4, #0xa]
    ldrh r3, [r4, #0x14]
    adds r3, r6, r3
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrh r2, [r4, #0x16]
    adds r2, r6, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrh r1, [r4, #0x18]
    adds r1, r5, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r0, [r4, #0x1a]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r3, [sp]
    str r2, [sp, #4]
    str r1, [sp, #8]
    str r0, [sp, #0xc]
    mov r0, sb
    adds r1, r7, #0
    ldr r2, [sp, #0x14]
    mov r3, sl
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0802f8b0
    ldrb r0, [r4, #0x10]
    cmp r0, #0
    beq lbl_0802f7ee
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_0802f7f8
    cmp r6, sb
    bls lbl_0802f7f8
    cmp r6, r7
    bhs lbl_0802f7f8
lbl_0802f7ee:
    mov r0, r8
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
lbl_0802f7f8:
    mov r1, r8
    cmp r1, #0
    beq lbl_0802f86a
    ldrb r1, [r4]
    movs r3, #0x40
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f834
    ldr r5, [sp, #0x14]
    ldr r0, lbl_0802f828 @ =gCurrentSprite
    ldrh r2, [r0]
    movs r7, #0x80
    lsls r7, r7, #2
    adds r1, r7, #0
    orrs r1, r2
    strh r1, [r0]
    ands r1, r3
    adds r2, r0, #0
    cmp r1, #0
    bne lbl_0802f85c
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0802f830 @ =0x082e7b2c
    b lbl_0802f860
    .align 2, 0
lbl_0802f828: .4byte gCurrentSprite
lbl_0802f82c: .4byte gProjectileData
lbl_0802f830: .4byte 0x082e7b2c
lbl_0802f834:
    mov r5, sl
    ldr r0, lbl_0802f850 @ =gCurrentSprite
    ldrh r1, [r0]
    ldr r7, lbl_0802f854 @ =0x0000fdff
    adds r2, r7, #0
    ands r1, r2
    strh r1, [r0]
    ands r1, r3
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_0802f85c
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0802f858 @ =0x082e7b2c
    b lbl_0802f860
    .align 2, 0
lbl_0802f850: .4byte gCurrentSprite
lbl_0802f854: .4byte 0x0000fdff
lbl_0802f858: .4byte 0x082e7b2c
lbl_0802f85c:
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0802f888 @ =0x082e7ae4
lbl_0802f860:
    cmp r0, r1
    beq lbl_0802f866
    str r1, [r2, #0x18]
lbl_0802f866:
    movs r0, #0
    strb r0, [r2, #0x1c]
lbl_0802f86a:
    ldr r0, [sp, #0x10]
    cmp r0, #0xd
    bne lbl_0802f890
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #0x31
    bl ParticleSet
    mov r1, r8
    cmp r1, #0
    beq lbl_0802f8a6
    movs r0, #0x3c
    ldr r7, lbl_0802f88c @ =gCurrentSprite+0x2d
    strb r0, [r7]
    b lbl_0802f8a6
    .align 2, 0
lbl_0802f888: .4byte 0x082e7ae4
lbl_0802f88c: .4byte gCurrentSprite+0x2d
lbl_0802f890:
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #0x30
    bl ParticleSet
    mov r0, r8
    cmp r0, #0
    beq lbl_0802f8a6
    movs r0, #0x1e
    ldr r1, lbl_0802f8ac @ =gCurrentSprite+0x2d
    strb r0, [r1]
lbl_0802f8a6:
    movs r0, #0
    strb r0, [r4]
    b lbl_0802f8ba
    .align 2, 0
lbl_0802f8ac: .4byte gCurrentSprite+0x2d
lbl_0802f8b0:
    adds r4, #0x1c
    ldr r0, lbl_0802f8cc @ =gArmCannonY
    cmp r4, r0
    bhs lbl_0802f8ba
    b lbl_0802f77e
lbl_0802f8ba:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802f8cc: .4byte gArmCannonY

    thumb_func_start WorkerRobotStandingInit
WorkerRobotStandingInit: @ 0x0802f8d0
    ldr r0, lbl_0802f900 @ =gCurrentSprite
    mov ip, r0
    mov r1, ip
    adds r1, #0x24
    movs r3, #0
    movs r0, #0xf
    strb r0, [r1]
    ldr r0, lbl_0802f904 @ =0x082e7b74
    mov r1, ip
    str r0, [r1, #0x18]
    movs r2, #0
    strh r3, [r1, #0x16]
    strb r2, [r1, #0x1c]
    adds r1, #0x2c
    movs r0, #0x1e
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2d
    strb r2, [r0]
    ldr r0, lbl_0802f908 @ =0x0000ff7c
    mov r1, ip
    strh r0, [r1, #0xa]
    bx lr
    .align 2, 0
lbl_0802f900: .4byte gCurrentSprite
lbl_0802f904: .4byte 0x082e7b74
lbl_0802f908: .4byte 0x0000ff7c

    thumb_func_start WorkerRobotCheckProjectile
WorkerRobotCheckProjectile: @ 0x0802f90c
    push {lr}
    bl WorkerRobotWalkingDetectProjectile
    ldr r2, lbl_0802f928 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802f92c
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #9
    b lbl_0802f940
    .align 2, 0
lbl_0802f928: .4byte gCurrentSprite
lbl_0802f92c:
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802f942
    subs r1, #8
    movs r0, #8
lbl_0802f940:
    strb r0, [r1]
lbl_0802f942:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start WorkerRobotWalkingInit
WorkerRobotWalkingInit: @ 0x0802f948
    ldr r1, lbl_0802f960 @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #9
    strb r0, [r2]
    ldr r0, lbl_0802f964 @ =0x082e7ae4
    str r0, [r1, #0x18]
    movs r0, #0
    strh r3, [r1, #0x16]
    strb r0, [r1, #0x1c]
    bx lr
    .align 2, 0
lbl_0802f960: .4byte gCurrentSprite
lbl_0802f964: .4byte 0x082e7ae4

    thumb_func_start WorkerRobotMove
WorkerRobotMove: @ 0x0802f968
    push {r4, r5, lr}
    bl unk_f594
    ldr r0, lbl_0802f9cc @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802f9ec
    ldr r4, lbl_0802f9d0 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0802f9ec
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    adds r2, r0, #0
    cmp r2, #0
    bne lbl_0802f9ec
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x1e
    strb r1, [r0]
    adds r1, r4, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0802f9aa
    b lbl_0802fbb4
lbl_0802f9aa:
    strb r2, [r1]
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f9d4
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802f9c4
    b lbl_0802fbb4
lbl_0802f9c4:
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    b lbl_0802fbb4
    .align 2, 0
lbl_0802f9cc: .4byte gPreviousVerticalCollisionCheck
lbl_0802f9d0: .4byte gCurrentSprite
lbl_0802f9d4:
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0802f9e0
    b lbl_0802fbb4
lbl_0802f9e0:
    ldr r0, lbl_0802f9e8 @ =0x0000fdff
    ands r0, r1
    strh r0, [r4]
    b lbl_0802fbb4
    .align 2, 0
lbl_0802f9e8: .4byte 0x0000fdff
lbl_0802f9ec:
    movs r5, #1
    bl WorkerRobotWalkingDetectProjectile
    ldr r2, lbl_0802fa38 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802fa94
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fa1e
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #3
    bne lbl_0802fa1e
    ldrb r0, [r2, #0x1c]
    cmp r0, #6
    bne lbl_0802fa1e
    ldr r0, lbl_0802fa3c @ =0x0000026e
    bl SoundPlayNotAlreadyPlaying
lbl_0802fa1e:
    ldr r0, lbl_0802fa38 @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r1, #4
    strb r1, [r0, #0x1c]
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r1, [r1]
    lsrs r5, r1, #2
    adds r3, r0, #0
    cmp r5, #8
    bls lbl_0802fa40
    movs r5, #8
    b lbl_0802fa46
    .align 2, 0
lbl_0802fa38: .4byte gCurrentSprite
lbl_0802fa3c: .4byte 0x0000026e
lbl_0802fa40:
    cmp r5, #0
    bne lbl_0802fa46
    movs r5, #1
lbl_0802fa46:
    adds r1, r3, #0
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0802fad0
    ldrh r2, [r1]
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_0802fa76
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    ands r0, r2
    cmp r0, #0
    bne lbl_0802fa88
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0802fa88
lbl_0802fa76:
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0802fa86
    ldr r0, lbl_0802fa90 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
lbl_0802fa86:
    adds r1, r3, #0
lbl_0802fa88:
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0802fbb4
    .align 2, 0
lbl_0802fa90: .4byte 0x0000fdff
lbl_0802fa94:
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fab4
    ldrh r1, [r2, #0x16]
    movs r0, #3
    ands r0, r1
    cmp r0, #3
    bne lbl_0802fab4
    ldrb r0, [r2, #0x1c]
    cmp r0, #8
    bne lbl_0802fab4
    ldr r0, lbl_0802fac8 @ =0x0000026e
    bl SoundPlayNotAlreadyPlaying
lbl_0802fab4:
    bl WorkerRobotCheckSamusInFront
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0802fad0
    ldr r0, lbl_0802facc @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0xa
    strb r1, [r0]
    b lbl_0802fbb4
    .align 2, 0
lbl_0802fac8: .4byte 0x0000026e
lbl_0802facc: .4byte gCurrentSprite
lbl_0802fad0:
    ldr r4, lbl_0802fb34 @ =gCurrentSprite
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fb40
    ldr r0, lbl_0802fb38 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fb18
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802fb02
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802fb84
lbl_0802fb02:
    ldr r4, lbl_0802fb34 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    subs r0, #0x48
    ldrh r1, [r4, #4]
    adds r1, #0x28
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x11
    beq lbl_0802fb7a
lbl_0802fb18:
    ldr r1, lbl_0802fb34 @ =gCurrentSprite
    ldrh r0, [r1, #4]
    adds r0, r5, r0
    strh r0, [r1, #4]
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fbb4
    ldr r1, lbl_0802fb3c @ =gSamusData
    ldrh r0, [r1, #0x12]
    adds r0, r5, r0
    b lbl_0802fbb2
    .align 2, 0
lbl_0802fb34: .4byte gCurrentSprite
lbl_0802fb38: .4byte gPreviousVerticalCollisionCheck
lbl_0802fb3c: .4byte gSamusData
lbl_0802fb40:
    ldr r0, lbl_0802fb90 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fb98
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802fb64
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0802fb84
lbl_0802fb64:
    ldr r4, lbl_0802fb94 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    subs r0, #0x48
    ldrh r1, [r4, #4]
    subs r1, #0x28
    bl SpriteUtilGetCollisionAtPosition
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x11
    bne lbl_0802fb98
lbl_0802fb7a:
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0802fbb4
lbl_0802fb84:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xa
    strb r0, [r1]
    b lbl_0802fbb4
    .align 2, 0
lbl_0802fb90: .4byte gPreviousVerticalCollisionCheck
lbl_0802fb94: .4byte gCurrentSprite
lbl_0802fb98:
    ldr r1, lbl_0802fbbc @ =gCurrentSprite
    ldrh r0, [r1, #4]
    subs r0, r0, r5
    strh r0, [r1, #4]
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fbb4
    ldr r1, lbl_0802fbc0 @ =gSamusData
    ldrh r0, [r1, #0x12]
    subs r0, r0, r5
lbl_0802fbb2:
    strh r0, [r1, #0x12]
lbl_0802fbb4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802fbbc: .4byte gCurrentSprite
lbl_0802fbc0: .4byte gSamusData

    thumb_func_start WorkerRobotBackToSleepInit
WorkerRobotBackToSleepInit: @ 0x0802fbc4
    push {lr}
    ldr r1, lbl_0802fbf4 @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0xb
    strb r0, [r2]
    ldr r0, lbl_0802fbf8 @ =0x082e7b84
    str r0, [r1, #0x18]
    movs r0, #0
    strh r3, [r1, #0x16]
    strb r0, [r1, #0x1c]
    ldrh r1, [r1]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0802fbee
    movs r0, #0x9c
    lsls r0, r0, #2
    bl SoundPlayNotAlreadyPlaying
lbl_0802fbee:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802fbf4: .4byte gCurrentSprite
lbl_0802fbf8: .4byte 0x082e7b84

    thumb_func_start WorkerRobotCheckBackToSleepAnimEnded
WorkerRobotCheckBackToSleepAnimEnded: @ 0x0802fbfc
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802fc1e
    ldr r1, lbl_0802fc24 @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0xc
    strb r0, [r2]
    ldr r0, lbl_0802fc28 @ =0x082e7bdc
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    ldr r0, lbl_0802fc2c @ =0x0000ff8c
    strh r0, [r1, #0xa]
lbl_0802fc1e:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802fc24: .4byte gCurrentSprite
lbl_0802fc28: .4byte 0x082e7bdc
lbl_0802fc2c: .4byte 0x0000ff8c

    thumb_func_start WorkerRobotTurningAround
WorkerRobotTurningAround: @ 0x0802fc30
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802fc74
    ldr r1, lbl_0802fc50 @ =gCurrentSprite
    ldrh r2, [r1]
    movs r0, #0x40
    ands r0, r2
    adds r3, r1, #0
    cmp r0, #0
    beq lbl_0802fc58
    ldr r0, lbl_0802fc54 @ =0x0000fdbf
    ands r0, r2
    b lbl_0802fc60
    .align 2, 0
lbl_0802fc50: .4byte gCurrentSprite
lbl_0802fc54: .4byte 0x0000fdbf
lbl_0802fc58:
    movs r1, #0x90
    lsls r1, r1, #2
    adds r0, r1, #0
    orrs r0, r2
lbl_0802fc60:
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0xd
    strb r0, [r1]
    ldr r0, lbl_0802fc78 @ =0x082e7bf4
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r2, [r3, #0x16]
lbl_0802fc74:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802fc78: .4byte 0x082e7bf4

    thumb_func_start WorkerRobotCheckTurningAroundAnimEnded
WorkerRobotCheckTurningAroundAnimEnded: @ 0x0802fc7c
    push {lr}
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0802fc8e
    ldr r0, lbl_0802fc94 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0x10
    strb r1, [r0]
lbl_0802fc8e:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0802fc94: .4byte gCurrentSprite

    thumb_func_start WorkerRobotFallingInit
WorkerRobotFallingInit: @ 0x0802fc98
    ldr r3, lbl_0802fcb8 @ =gCurrentSprite
    adds r2, r3, #0
    adds r2, #0x24
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r1, [r0]
    subs r0, #2
    strb r1, [r0]
    ldr r0, lbl_0802fcbc @ =0x082e7ae4
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r1, [r3, #0x16]
    bx lr
    .align 2, 0
lbl_0802fcb8: .4byte gCurrentSprite
lbl_0802fcbc: .4byte 0x082e7ae4

    thumb_func_start WorkerRobotFalling
WorkerRobotFalling: @ 0x0802fcc0
    push {r4, r5, lr}
    ldr r4, lbl_0802fcf0 @ =gCurrentSprite
    ldrb r0, [r4, #0x1c]
    adds r0, #2
    strb r0, [r4, #0x1c]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802fcf4 @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802fcfc
    strh r1, [r4, #2]
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0xe
    strb r1, [r0]
    ldr r0, lbl_0802fcf8 @ =0x00000271
    bl SoundPlay
    b lbl_0802fd38
    .align 2, 0
lbl_0802fcf0: .4byte gCurrentSprite
lbl_0802fcf4: .4byte gPreviousVerticalCollisionCheck
lbl_0802fcf8: .4byte 0x00000271
lbl_0802fcfc:
    movs r0, #0x2f
    adds r0, r0, r4
    mov ip, r0
    ldrb r1, [r0]
    ldr r3, lbl_0802fd24 @ =0x082b0d04
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r2, [r0, r5]
    ldr r0, lbl_0802fd28 @ =0x00007fff
    cmp r2, r0
    bne lbl_0802fd2c
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r5, [r4, #2]
    adds r0, r0, r5
    b lbl_0802fd36
    .align 2, 0
lbl_0802fd24: .4byte 0x082b0d04
lbl_0802fd28: .4byte 0x00007fff
lbl_0802fd2c:
    adds r0, r1, #1
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_0802fd36:
    strh r0, [r4, #2]
lbl_0802fd38:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0802fd40
sub_0802fd40: @ 0x0802fd40
    ldr r3, lbl_0802fd58 @ =gCurrentSprite
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x21
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r2, [r0]
    subs r0, #2
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0802fd58: .4byte gCurrentSprite

    thumb_func_start WorkerRobotFallingSleep
WorkerRobotFallingSleep: @ 0x0802fd5c
    push {r4, r5, lr}
    ldr r4, lbl_0802fd84 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0802fd88 @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802fd90
    strh r1, [r4, #2]
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x10
    strb r1, [r0]
    ldr r0, lbl_0802fd8c @ =0x00000271
    bl SoundPlay
    b lbl_0802fdcc
    .align 2, 0
lbl_0802fd84: .4byte gCurrentSprite
lbl_0802fd88: .4byte gPreviousVerticalCollisionCheck
lbl_0802fd8c: .4byte 0x00000271
lbl_0802fd90:
    movs r0, #0x2f
    adds r0, r0, r4
    mov ip, r0
    ldrb r1, [r0]
    ldr r3, lbl_0802fdb8 @ =0x082b0d54
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r5, #0
    ldrsh r2, [r0, r5]
    ldr r0, lbl_0802fdbc @ =0x00007fff
    cmp r2, r0
    bne lbl_0802fdc0
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r5, [r4, #2]
    adds r0, r0, r5
    b lbl_0802fdca
    .align 2, 0
lbl_0802fdb8: .4byte 0x082b0d54
lbl_0802fdbc: .4byte 0x00007fff
lbl_0802fdc0:
    adds r0, r1, #1
    mov r1, ip
    strb r0, [r1]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_0802fdca:
    strh r0, [r4, #2]
lbl_0802fdcc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start WorkerRobot
WorkerRobot: @ 0x0802fdd4
    push {lr}
    sub sp, #4
    ldr r1, lbl_0802fdf0 @ =gCurrentSprite
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r2, r1, #0
    cmp r0, #0x21
    bhi lbl_0802fed6
    lsls r0, r0, #2
    ldr r1, lbl_0802fdf4 @ =lbl_0802fdf8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0802fdf0: .4byte gCurrentSprite
lbl_0802fdf4: .4byte lbl_0802fdf8
lbl_0802fdf8: @ jump table
    .4byte lbl_0802fe80 @ case 0
    .4byte lbl_0802fed6 @ case 1
    .4byte lbl_0802fed6 @ case 2
    .4byte lbl_0802fed6 @ case 3
    .4byte lbl_0802fed6 @ case 4
    .4byte lbl_0802fed6 @ case 5
    .4byte lbl_0802fed6 @ case 6
    .4byte lbl_0802fed6 @ case 7
    .4byte lbl_0802fea2 @ case 8
    .4byte lbl_0802fea6 @ case 9
    .4byte lbl_0802feac @ case 10
    .4byte lbl_0802feb0 @ case 11
    .4byte lbl_0802feb6 @ case 12
    .4byte lbl_0802febc @ case 13
    .4byte lbl_0802fe98 @ case 14
    .4byte lbl_0802fe9c @ case 15
    .4byte lbl_0802fe84 @ case 16
    .4byte lbl_0802fe88 @ case 17
    .4byte lbl_0802fe8e @ case 18
    .4byte lbl_0802fe92 @ case 19
    .4byte lbl_0802fed6 @ case 20
    .4byte lbl_0802fed6 @ case 21
    .4byte lbl_0802fed6 @ case 22
    .4byte lbl_0802fed6 @ case 23
    .4byte lbl_0802fed6 @ case 24
    .4byte lbl_0802fed6 @ case 25
    .4byte lbl_0802fed6 @ case 26
    .4byte lbl_0802fed6 @ case 27
    .4byte lbl_0802fed6 @ case 28
    .4byte lbl_0802fed6 @ case 29
    .4byte lbl_0802fec2 @ case 30
    .4byte lbl_0802fec6 @ case 31
    .4byte lbl_0802fecc @ case 32
    .4byte lbl_0802fed0 @ case 33
lbl_0802fe80:
    bl WorkerRobotInit
lbl_0802fe84:
    bl WorkerRobotSleepingInit
lbl_0802fe88:
    bl WorkerRobotSleeping
    b lbl_0802fee8
lbl_0802fe8e:
    bl WorkerRobotWakingUpInit
lbl_0802fe92:
    bl WorkerRobotChecWakingUpAnimEnded
    b lbl_0802fee8
lbl_0802fe98:
    bl WorkerRobotStandingInit
lbl_0802fe9c:
    bl WorkerRobotCheckProjectile
    b lbl_0802fee8
lbl_0802fea2:
    bl WorkerRobotWalkingInit
lbl_0802fea6:
    bl WorkerRobotMove
    b lbl_0802fee8
lbl_0802feac:
    bl WorkerRobotBackToSleepInit
lbl_0802feb0:
    bl WorkerRobotCheckBackToSleepAnimEnded
    b lbl_0802fee8
lbl_0802feb6:
    bl WorkerRobotTurningAround
    b lbl_0802fee8
lbl_0802febc:
    bl WorkerRobotCheckTurningAroundAnimEnded
    b lbl_0802fee8
lbl_0802fec2:
    bl WorkerRobotFallingInit
lbl_0802fec6:
    bl WorkerRobotFalling
    b lbl_0802fee8
lbl_0802fecc:
    bl sub_0802fd40
lbl_0802fed0:
    bl WorkerRobotFallingSleep
    b lbl_0802fee8
lbl_0802fed6:
    ldrh r1, [r2, #2]
    subs r1, #0x46
    ldrh r2, [r2, #4]
    movs r0, #0x22
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_0802fee8:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0802fef0
sub_0802fef0: @ 0x0802fef0
    push {r4, lr}
    movs r4, #0
    ldr r2, lbl_0802ff28 @ =gSpriteData
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0802ff36
    adds r3, r2, #0
    adds r3, #0x24
lbl_0802ff04:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ff2c
    ldrb r0, [r3, #1]
    cmp r0, #0x17
    bne lbl_0802ff2c
    ldrb r0, [r3]
    cmp r0, #0x43
    bne lbl_0802ff20
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0802ff20:
    cmp r4, #3
    bls lbl_0802ff2c
    movs r0, #1
    b lbl_0802ff38
    .align 2, 0
lbl_0802ff28: .4byte gSpriteData
lbl_0802ff2c:
    adds r3, #0x38
    adds r2, #0x38
    ldr r0, lbl_0802ff40 @ =gSpritesetSpritesID
    cmp r2, r0
    blo lbl_0802ff04
lbl_0802ff36:
    movs r0, #0
lbl_0802ff38:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0802ff40: .4byte gSpritesetSpritesID

    thumb_func_start ParasiteInit
ParasiteInit: @ 0x0802ff44
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    adds r6, r0, #0
    movs r3, #0
    movs r2, #0
    ldr r0, lbl_0802ffdc @ =0x0000fffc
    strh r0, [r6, #0xa]
    strh r2, [r6, #0xc]
    strh r0, [r6, #0xe]
    movs r1, #4
    movs r0, #4
    strh r0, [r6, #0x10]
    adds r0, r6, #0
    adds r0, #0x27
    movs r5, #8
    strb r5, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r5, [r0]
    ldr r0, lbl_0802ffe0 @ =0x082e8318
    str r0, [r6, #0x18]
    strb r3, [r6, #0x1c]
    strh r2, [r6, #0x16]
    adds r1, r6, #0
    adds r1, #0x25
    movs r0, #0x17
    strb r0, [r1]
    movs r0, #1
    strh r0, [r6, #0x14]
    ldr r0, lbl_0802ffe4 @ =gSubSpriteData1
    strb r3, [r0, #0xe]
    bl SpriteUtilChooseRandomXFlip
    adds r0, r6, #0
    adds r0, #0x24
    strb r5, [r0]
    ldrb r0, [r6, #0x1d]
    mov r8, r0
    cmp r0, #0x5e
    bne lbl_08030062
    ldr r0, lbl_0802ffe8 @ =gEquipment
    ldrb r1, [r0, #0xc]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0802ffb8
    movs r0, #3
    movs r1, #0x2d
    bl EventFunction
    cmp r0, #0
    bne lbl_0802ffb8
    ldr r1, lbl_0802ffec @ =gDoorUnlockTimer
    movs r0, #1
    strb r0, [r1]
lbl_0802ffb8:
    ldrh r1, [r6]
    movs r0, #4
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r5, #0
    beq lbl_0802fff8
    ldr r0, lbl_0802fff0 @ =gSpriteRng
    ldrb r7, [r0]
    ldr r0, lbl_0802fff4 @ =0x0000fffb
    ands r0, r1
    strh r0, [r6]
    adds r0, r7, #0
    muls r0, r7, r0
    ldrh r1, [r6, #4]
    adds r0, r0, r1
    strh r0, [r6, #4]
    b lbl_08030062
    .align 2, 0
lbl_0802ffdc: .4byte 0x0000fffc
lbl_0802ffe0: .4byte 0x082e8318
lbl_0802ffe4: .4byte gSubSpriteData1
lbl_0802ffe8: .4byte gEquipment
lbl_0802ffec: .4byte gDoorUnlockTimer
lbl_0802fff0: .4byte gSpriteRng
lbl_0802fff4: .4byte 0x0000fffb
lbl_0802fff8:
    ldrb r7, [r6, #0x1f]
    ldrb r0, [r6, #0x1e]
    str r0, [sp, #8]
    ldrh r4, [r6, #2]
    ldrh r6, [r6, #4]
    adds r0, r6, #0
    subs r0, #8
    str r0, [sp]
    str r5, [sp, #4]
    mov r0, r8
    ldr r1, [sp, #8]
    adds r2, r7, #0
    adds r3, r4, #0
    bl SpriteSpawnPrimary
    adds r0, r6, #0
    adds r0, #0xc
    str r0, [sp]
    str r5, [sp, #4]
    mov r0, r8
    ldr r1, [sp, #8]
    adds r2, r7, #0
    adds r3, r4, #0
    bl SpriteSpawnPrimary
    adds r0, r6, #0
    subs r0, #0xc
    str r0, [sp]
    str r5, [sp, #4]
    mov r0, r8
    ldr r1, [sp, #8]
    adds r2, r7, #0
    adds r3, r4, #0
    bl SpriteSpawnPrimary
    adds r0, r6, #0
    adds r0, #8
    str r0, [sp]
    str r5, [sp, #4]
    mov r0, r8
    ldr r1, [sp, #8]
    adds r2, r7, #0
    adds r3, r4, #0
    bl SpriteSpawnPrimary
    str r6, [sp]
    str r5, [sp, #4]
    mov r0, r8
    ldr r1, [sp, #8]
    adds r2, r7, #0
    adds r3, r4, #0
    bl SpriteSpawnPrimary
lbl_08030062:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteGrabSamus
ParasiteGrabSamus: @ 0x08030070
    push {r4, r5, lr}
    adds r3, r0, #0
    adds r1, r3, #0
    adds r1, #0x24
    movs r5, #0
    movs r0, #0x43
    strb r0, [r1]
    ldr r0, lbl_080300b8 @ =0x082e84e0
    str r0, [r3, #0x18]
    movs r1, #0
    strh r5, [r3, #0x16]
    strb r1, [r3, #0x1c]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r1, [r0]
    ldr r2, lbl_080300bc @ =gSamusData
    ldr r1, lbl_080300c0 @ =gSamusPhysics
    adds r0, r1, #0
    adds r0, #0x70
    ldrh r0, [r0]
    ldrh r4, [r2, #0x14]
    adds r0, r0, r4
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r1, #0x6e
    ldrh r0, [r1]
    ldrh r1, [r2, #0x12]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r3, #2]
    cmp r0, r4
    bhs lbl_080300c4
    strh r5, [r3, #6]
    b lbl_080300c8
    .align 2, 0
lbl_080300b8: .4byte 0x082e84e0
lbl_080300bc: .4byte gSamusData
lbl_080300c0: .4byte gSamusPhysics
lbl_080300c4:
    subs r0, r0, r4
    strh r0, [r3, #6]
lbl_080300c8:
    ldrh r0, [r3, #4]
    cmp r0, r1
    bhs lbl_080300d2
    movs r0, #0
    b lbl_080300d4
lbl_080300d2:
    subs r0, r0, r1
lbl_080300d4:
    strh r0, [r3, #8]
    ldrh r1, [r3, #2]
    ldrh r0, [r2, #0x14]
    subs r0, #0x40
    cmp r1, r0
    ble lbl_080300ec
    ldrh r1, [r3]
    ldr r0, lbl_080300e8 @ =0x0000feff
    ands r0, r1
    b lbl_080300f6
    .align 2, 0
lbl_080300e8: .4byte 0x0000feff
lbl_080300ec:
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    orrs r0, r1
lbl_080300f6:
    strh r0, [r3]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteSamusGrabbed
ParasiteSamusGrabbed: @ 0x08030100
    push {r4, r5, r6, r7, lr}
    adds r3, r0, #0
    ldr r0, lbl_08030128 @ =gSamusData
    ldrb r1, [r0]
    adds r6, r0, #0
    cmp r1, #0xf
    bne lbl_08030130
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x44
    strb r1, [r0]
    ldr r0, lbl_0803012c @ =gSpriteRng
    ldrb r2, [r0]
    cmp r2, #5
    bhi lbl_08030120
    movs r2, #6
lbl_08030120:
    adds r0, r3, #0
    adds r0, #0x2e
    strb r2, [r0]
    b lbl_08030288
    .align 2, 0
lbl_08030128: .4byte gSamusData
lbl_0803012c: .4byte gSpriteRng
lbl_08030130:
    ldr r1, lbl_0803016c @ =gParasiteRelated
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0803013c
    movs r0, #0x5a
    strb r0, [r1]
lbl_0803013c:
    ldrh r4, [r3]
    movs r5, #0x80
    lsls r5, r5, #1
    adds r0, r5, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_08030178
    ldr r2, lbl_08030170 @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x74
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldrh r7, [r6, #0x14]
    adds r1, r1, r7
    ldrh r0, [r3, #2]
    adds r0, #8
    mov ip, r2
    adds r2, r3, #0
    adds r2, #0x2c
    cmp r1, r0
    bge lbl_080301a0
    ldr r0, lbl_08030174 @ =0x0000feff
    ands r0, r4
    b lbl_08030198
    .align 2, 0
lbl_0803016c: .4byte gParasiteRelated
lbl_08030170: .4byte gSamusPhysics
lbl_08030174: .4byte 0x0000feff
lbl_08030178:
    ldr r2, lbl_080301c4 @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x70
    movs r7, #0
    ldrsh r1, [r0, r7]
    ldrh r0, [r6, #0x14]
    adds r1, r1, r0
    ldrh r0, [r3, #2]
    subs r0, #8
    mov ip, r2
    adds r2, r3, #0
    adds r2, #0x2c
    cmp r1, r0
    ble lbl_080301a0
    adds r0, r5, #0
    orrs r0, r4
lbl_08030198:
    strh r0, [r3]
    ldr r0, lbl_080301c8 @ =gSpriteRng
    ldrb r0, [r0]
    strb r0, [r2]
lbl_080301a0:
    ldrh r4, [r3]
    movs r0, #0x40
    ands r0, r4
    cmp r0, #0
    beq lbl_080301d0
    mov r0, ip
    adds r0, #0x72
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldrh r7, [r6, #0x12]
    adds r1, r1, r7
    ldrh r0, [r3, #4]
    adds r0, #8
    cmp r1, r0
    bge lbl_080301f0
    ldr r0, lbl_080301cc @ =0x0000ffbf
    ands r0, r4
    b lbl_080301e8
    .align 2, 0
lbl_080301c4: .4byte gSamusPhysics
lbl_080301c8: .4byte gSpriteRng
lbl_080301cc: .4byte 0x0000ffbf
lbl_080301d0:
    mov r0, ip
    adds r0, #0x6e
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldrh r7, [r6, #0x12]
    adds r1, r1, r7
    ldrh r0, [r3, #4]
    subs r0, #8
    cmp r1, r0
    ble lbl_080301f0
    movs r0, #0x40
    orrs r0, r4
lbl_080301e8:
    strh r0, [r3]
    ldr r0, lbl_08030214 @ =gSpriteRng
    ldrb r0, [r0]
    strb r0, [r2]
lbl_080301f0:
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0803025c
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_08030218
    ldr r0, lbl_08030214 @ =gSpriteRng
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_08030228
    ldrh r0, [r3, #6]
    adds r0, #1
    b lbl_08030226
    .align 2, 0
lbl_08030214: .4byte gSpriteRng
lbl_08030218:
    ldr r0, lbl_08030244 @ =gSpriteRng
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_08030228
    ldrh r0, [r3, #6]
    subs r0, #1
lbl_08030226:
    strh r0, [r3, #6]
lbl_08030228:
    movs r0, #0x40
    ands r0, r4
    cmp r0, #0
    beq lbl_08030248
    adds r1, r3, #0
    adds r1, #0x23
    ldrb r0, [r2]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08030260
    ldrh r0, [r3, #8]
    adds r0, #1
    strh r0, [r3, #8]
    b lbl_08030260
    .align 2, 0
lbl_08030244: .4byte gSpriteRng
lbl_08030248:
    adds r1, r3, #0
    adds r1, #0x23
    ldrb r0, [r2]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08030260
    ldrh r0, [r3, #8]
    subs r0, #1
    strh r0, [r3, #8]
    b lbl_08030260
lbl_0803025c:
    subs r0, #1
    strb r0, [r2]
lbl_08030260:
    mov r0, ip
    adds r0, #0x70
    ldrh r1, [r0]
    ldrh r0, [r6, #0x14]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    mov r0, ip
    adds r0, #0x6e
    ldrh r0, [r0]
    ldrh r6, [r6, #0x12]
    adds r0, r0, r6
    lsls r0, r0, #0x10
    lsrs r1, r1, #0x10
    ldrh r2, [r3, #6]
    adds r1, r1, r2
    strh r1, [r3, #2]
    lsrs r0, r0, #0x10
    ldrh r5, [r3, #8]
    adds r0, r0, r5
    strh r0, [r3, #4]
lbl_08030288:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteExpulsedInit
ParasiteExpulsedInit: @ 0x08030290
    adds r3, r0, #0
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x45
    strb r0, [r1]
    ldr r0, lbl_080302b8 @ =0x082e8528
    str r0, [r3, #0x18]
    movs r0, #0
    strh r2, [r3, #0x16]
    strb r0, [r3, #0x1c]
    adds r1, #0xb
    movs r0, #8
    strb r0, [r1]
    ldrh r1, [r3]
    ldr r0, lbl_080302bc @ =0x0000feff
    ands r0, r1
    strh r0, [r3]
    bx lr
    .align 2, 0
lbl_080302b8: .4byte 0x082e8528
lbl_080302bc: .4byte 0x0000feff

    thumb_func_start parasite_star_explused_after_grabbing_object
parasite_star_explused_after_grabbing_object: @ 0x080302c0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r0, [r2]
    adds r1, r0, #0
    adds r1, #0xff
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_080302e4
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    b lbl_080302ee
lbl_080302e4:
    strb r1, [r2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x47
    strb r0, [r1]
lbl_080302ee:
    ldrh r5, [r4, #2]
    mov r8, r5
    ldrh r6, [r4, #4]
    adds r7, r6, #0
    adds r0, r5, #0
    subs r0, #0x14
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    bne lbl_0803030c
    ldr r0, lbl_08030334 @ =0x0000ffc0
    ands r0, r5
    adds r0, #0x50
    strh r0, [r4, #2]
lbl_0803030c:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08030338
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_08030356
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_08030354
    .align 2, 0
lbl_08030334: .4byte 0x0000ffc0
lbl_08030338:
    adds r1, r7, #0
    subs r1, #0x10
    mov r0, r8
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_08030356
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_08030354:
    strh r0, [r4, #4]
lbl_08030356:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ParasiteExpulsed
ParasiteExpulsed: @ 0x08030360
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r0, [r2]
    adds r1, r0, #0
    adds r1, #0xff
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08030386
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    b lbl_08030390
lbl_08030386:
    strb r1, [r2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x47
    strb r0, [r1]
lbl_08030390:
    ldrh r5, [r4, #2]
    mov sb, r5
    ldrh r6, [r4, #4]
    mov r8, r6
    adds r0, r5, #0
    subs r0, #0x14
    adds r1, r6, #0
    bl ClipdataProcess
    movs r7, #0x80
    lsls r7, r7, #0x11
    ands r0, r7
    cmp r0, #0
    beq lbl_080303b4
    ldr r0, lbl_080303dc @ =0x0000ffc0
    ands r0, r5
    adds r0, #0x50
    strh r0, [r4, #2]
lbl_080303b4:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080303e0
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    ands r0, r7
    cmp r0, #0
    bne lbl_080303fc
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_080303fa
    .align 2, 0
lbl_080303dc: .4byte 0x0000ffc0
lbl_080303e0:
    mov r1, r8
    subs r1, #0x10
    mov r0, sb
    bl ClipdataProcess
    ands r0, r7
    cmp r0, #0
    bne lbl_080303fc
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_080303fa:
    strh r0, [r4, #4]
lbl_080303fc:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start parasite_explused_after_grabbing_object
parasite_explused_after_grabbing_object: @ 0x08030408
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    ldrh r0, [r4, #2]
    mov sb, r0
    adds r1, r4, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r2, r0, #0
    cmp r0, #0x13
    bgt lbl_08030426
    adds r0, #2
    strb r0, [r1]
lbl_08030426:
    ldrh r0, [r4, #2]
    adds r0, r0, r2
    movs r1, #0
    mov r8, r1
    movs r7, #0
    strh r0, [r4, #2]
    ldrh r5, [r4, #2]
    ldrh r6, [r4, #4]
    adds r0, r5, #0
    adds r1, r6, #0
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r2, r0, #0
    ldr r0, lbl_0803045c @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08030490
    ldr r1, lbl_08030460 @ =gSpriteRng
    ldrb r0, [r1]
    cmp r0, #8
    bls lbl_08030468
    ldr r0, lbl_08030464 @ =0x082e8378
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    mov r0, r8
    strb r0, [r4, #0x1c]
    b lbl_0803047e
    .align 2, 0
lbl_0803045c: .4byte gPreviousVerticalCollisionCheck
lbl_08030460: .4byte gSpriteRng
lbl_08030464: .4byte 0x082e8378
lbl_08030468:
    ldr r0, lbl_0803048c @ =0x082e8398
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    mov r0, r8
    strb r0, [r4, #0x1c]
    ldrb r0, [r1]
    lsls r0, r0, #1
    adds r0, #0x20
    adds r1, r4, #0
    adds r1, #0x2c
    strb r0, [r1]
lbl_0803047e:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    strh r2, [r4, #2]
    b lbl_080304e2
    .align 2, 0
lbl_0803048c: .4byte 0x082e8398
lbl_08030490:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080304b8
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_080304d6
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_080304d4
lbl_080304b8:
    adds r1, r6, #0
    subs r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_080304d6
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_080304d4:
    strh r0, [r4, #4]
lbl_080304d6:
    mov r0, sb
    adds r1, r5, #0
    adds r2, r6, #0
    movs r3, #1
    bl SpriteUtilCheckInRoomEffect
lbl_080304e2:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteMultipleExpulsedDown
ParasiteMultipleExpulsedDown: @ 0x080304f0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r2, r0, #0
    cmp r0, #0x13
    bgt lbl_08030508
    adds r0, #2
    strb r0, [r1]
lbl_08030508:
    ldrh r0, [r4, #2]
    adds r0, r0, r2
    movs r1, #0
    mov r8, r1
    movs r7, #0
    strh r0, [r4, #2]
    ldrh r5, [r4, #2]
    ldrh r6, [r4, #4]
    adds r0, r5, #0
    adds r1, r6, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    beq lbl_08030578
    ldr r0, lbl_08030550 @ =0x0000ffc0
    ands r0, r5
    cmp r5, r0
    blo lbl_08030578
    strh r0, [r4, #2]
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0xf
    strb r1, [r0]
    ldr r1, lbl_08030554 @ =gSpriteRng
    ldrb r0, [r1]
    cmp r0, #8
    bls lbl_0803055c
    ldr r0, lbl_08030558 @ =0x082e8378
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    mov r0, r8
    strb r0, [r4, #0x1c]
    b lbl_080305c2
    .align 2, 0
lbl_08030550: .4byte 0x0000ffc0
lbl_08030554: .4byte gSpriteRng
lbl_08030558: .4byte 0x082e8378
lbl_0803055c:
    ldr r0, lbl_08030574 @ =0x082e8398
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    mov r0, r8
    strb r0, [r4, #0x1c]
    ldrb r0, [r1]
    lsls r0, r0, #1
    adds r0, #0x20
    adds r1, r4, #0
    adds r1, #0x2c
    strb r0, [r1]
    b lbl_080305c2
    .align 2, 0
lbl_08030574: .4byte 0x082e8398
lbl_08030578:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080305a2
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_080305c2
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_080305c0
lbl_080305a2:
    adds r1, r6, #0
    subs r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_080305c2
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_080305c0:
    strh r0, [r4, #4]
lbl_080305c2:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_080305cc
sub_080305cc: @ 0x080305cc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080305ea
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0803067a
lbl_080305ea:
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r0, [r2]
    adds r1, r0, #0
    adds r1, #0xff
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08030606
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    b lbl_08030610
lbl_08030606:
    strb r1, [r2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x4b
    strb r0, [r1]
lbl_08030610:
    ldrh r5, [r4, #2]
    mov r8, r5
    ldrh r6, [r4, #4]
    adds r7, r6, #0
    adds r0, r5, #0
    subs r0, #0x14
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    bne lbl_0803062e
    ldr r0, lbl_08030658 @ =0x0000ffc0
    ands r0, r5
    adds r0, #0x50
    strh r0, [r4, #2]
lbl_0803062e:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0803065c
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_0803067a
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_08030678
    .align 2, 0
lbl_08030658: .4byte 0x0000ffc0
lbl_0803065c:
    adds r1, r7, #0
    subs r1, #0x10
    mov r0, r8
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_0803067a
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_08030678:
    strh r0, [r4, #4]
lbl_0803067a:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ParasiteJumping
ParasiteJumping: @ 0x08030684
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080306a4
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_08030734
lbl_080306a4:
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r0, [r2]
    adds r1, r0, #0
    adds r1, #0xff
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_080306c0
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    b lbl_080306ca
lbl_080306c0:
    strb r1, [r2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x4b
    strb r0, [r1]
lbl_080306ca:
    ldrh r5, [r4, #2]
    mov sb, r5
    ldrh r6, [r4, #4]
    mov r8, r6
    adds r0, r5, #0
    subs r0, #0x14
    adds r1, r6, #0
    bl ClipdataProcess
    movs r7, #0x80
    lsls r7, r7, #0x11
    ands r0, r7
    cmp r0, #0
    beq lbl_080306ee
    ldr r0, lbl_08030714 @ =0x0000ffc0
    ands r0, r5
    adds r0, #0x50
    strh r0, [r4, #2]
lbl_080306ee:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08030718
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    ands r0, r7
    cmp r0, #0
    bne lbl_08030734
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_08030732
    .align 2, 0
lbl_08030714: .4byte 0x0000ffc0
lbl_08030718:
    mov r1, r8
    subs r1, #0x10
    mov r0, sb
    bl ClipdataProcess
    ands r0, r7
    cmp r0, #0
    bne lbl_08030734
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_08030732:
    strh r0, [r4, #4]
lbl_08030734:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08030740
sub_08030740: @ 0x08030740
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    ldrh r0, [r4, #2]
    mov r8, r0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, #0
    beq lbl_08030766
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_08030802
lbl_08030766:
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r1, [r2]
    cmp r1, #0xf
    bgt lbl_08030774
    adds r0, r1, #2
    strb r0, [r2]
lbl_08030774:
    ldrh r0, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
    ldrh r5, [r4, #2]
    ldrh r6, [r4, #4]
    adds r0, r5, #0
    adds r1, r6, #0
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r2, r0, #0
    ldr r0, lbl_080307a8 @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080307b0
    ldr r0, lbl_080307ac @ =0x082e8378
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    movs r0, #0
    strb r0, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    strh r2, [r4, #2]
    b lbl_08030802
    .align 2, 0
lbl_080307a8: .4byte gPreviousVerticalCollisionCheck
lbl_080307ac: .4byte 0x082e8378
lbl_080307b0:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080307d8
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_080307f6
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_080307f4
lbl_080307d8:
    adds r1, r6, #0
    subs r1, #0x10
    adds r0, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    bne lbl_080307f6
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_080307f4:
    strh r0, [r4, #4]
lbl_080307f6:
    mov r0, r8
    adds r1, r5, #0
    adds r2, r6, #0
    movs r3, #1
    bl SpriteUtilCheckInRoomEffect
lbl_08030802:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ParasiteJumpingDown
ParasiteJumpingDown: @ 0x0803080c
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    cmp r7, #0
    beq lbl_0803082a
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_080308c6
lbl_0803082a:
    adds r2, r4, #0
    adds r2, #0x2f
    ldrb r1, [r2]
    cmp r1, #0xf
    bgt lbl_08030838
    adds r0, r1, #2
    strb r0, [r2]
lbl_08030838:
    ldrh r0, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
    ldrh r5, [r4, #2]
    ldrh r6, [r4, #4]
    adds r0, r5, #0
    adds r1, r6, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    beq lbl_0803087c
    ldr r2, lbl_08030874 @ =0x0000ffc0
    ands r2, r5
    cmp r5, r2
    blt lbl_0803087c
    ldr r0, lbl_08030878 @ =0x082e8378
    str r0, [r4, #0x18]
    strh r7, [r4, #0x16]
    movs r0, #0
    strb r0, [r4, #0x1c]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    strh r2, [r4, #2]
    b lbl_080308c6
    .align 2, 0
lbl_08030874: .4byte 0x0000ffc0
lbl_08030878: .4byte 0x082e8378
lbl_0803087c:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080308a6
    adds r1, r6, #0
    adds r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_080308c6
    adds r1, r4, #0
    adds r1, #0x2e
    ldrh r0, [r4, #4]
    ldrb r1, [r1]
    adds r0, r0, r1
    b lbl_080308c4
lbl_080308a6:
    adds r1, r6, #0
    subs r1, #0x10
    adds r0, r5, #0
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_080308c6
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r1, [r0]
    ldrh r0, [r4, #4]
    subs r0, r0, r1
lbl_080308c4:
    strh r0, [r4, #4]
lbl_080308c6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ParasiteIdleInit
ParasiteIdleInit: @ 0x080308cc
    push {r4, lr}
    adds r3, r0, #0
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_08030914 @ =0x082e8318
    str r0, [r3, #0x18]
    movs r0, #0
    strh r2, [r3, #0x16]
    strb r0, [r3, #0x1c]
    ldr r4, lbl_08030918 @ =gSpriteRng
    ldrb r0, [r4]
    lsrs r0, r0, #1
    cmp r0, #5
    bhi lbl_080308f0
    movs r0, #6
lbl_080308f0:
    adds r1, r3, #0
    adds r1, #0x2e
    strb r0, [r1]
    ldrh r0, [r3, #4]
    lsrs r0, r0, #5
    movs r2, #0xf
    movs r1, #0xf
    ands r0, r1
    ldrb r4, [r4]
    adds r0, r0, r4
    ands r0, r2
    adds r1, r3, #0
    adds r1, #0x2c
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08030914: .4byte 0x082e8318
lbl_08030918: .4byte gSpriteRng

    thumb_func_start sub_0803091c
sub_0803091c: @ 0x0803091c
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, #0
    beq lbl_0803093a
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_08030aae
lbl_0803093a:
    bl unk_f594
    ldr r0, lbl_08030950 @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08030954
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x1e
    strb r0, [r1]
    b lbl_08030aae
    .align 2, 0
lbl_08030950: .4byte gPreviousVerticalCollisionCheck
lbl_08030954:
    ldrh r0, [r5, #2]
    subs r0, #0x10
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    bne lbl_0803096c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
    b lbl_08030aae
lbl_0803096c:
    adds r2, r5, #0
    adds r2, #0x2c
    ldrb r4, [r2]
    ldr r0, lbl_0803099c @ =gFrameCounter8Bit
    ldrb r0, [r0]
    lsrs r1, r0, #4
    cmp r1, r4
    bne lbl_080309a8
    ldr r0, lbl_080309a0 @ =0x082e8350
    str r0, [r5, #0x18]
    movs r0, #0
    strh r6, [r5, #0x16]
    strb r0, [r5, #0x1c]
    ldr r0, lbl_080309a4 @ =gSpriteRng
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    strb r0, [r2]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    b lbl_08030aae
    .align 2, 0
lbl_0803099c: .4byte gFrameCounter8Bit
lbl_080309a0: .4byte 0x082e8350
lbl_080309a4: .4byte gSpriteRng
lbl_080309a8:
    adds r0, r4, #1
    cmp r1, r0
    beq lbl_080309b4
    subs r0, r4, #1
    cmp r1, r0
    bne lbl_08030a20
lbl_080309b4:
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x49
    strb r0, [r1]
    ldr r0, lbl_080309dc @ =0x082e8480
    str r0, [r5, #0x18]
    movs r0, #0
    strh r6, [r5, #0x16]
    strb r0, [r5, #0x1c]
    ldr r0, lbl_080309e0 @ =gSpriteRng
    ldrb r1, [r0]
    cmp r1, #3
    bhi lbl_080309e4
    adds r1, r5, #0
    adds r1, #0x2f
    movs r0, #4
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_080309ec
    .align 2, 0
lbl_080309dc: .4byte 0x082e8480
lbl_080309e0: .4byte gSpriteRng
lbl_080309e4:
    adds r0, r5, #0
    adds r0, #0x2f
    strb r1, [r0]
    adds r2, r0, #0
lbl_080309ec:
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08030aae
    ldrb r4, [r2]
    cmp r4, #7
    bhi lbl_08030a06
    movs r0, #0xba
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030aae
lbl_08030a06:
    cmp r4, #0xb
    bls lbl_08030a14
    movs r0, #0xbb
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030aae
lbl_08030a14:
    ldr r0, lbl_08030a1c @ =0x00000175
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030aae
    .align 2, 0
lbl_08030a1c: .4byte 0x00000175
lbl_08030a20:
    ldr r6, lbl_08030a40 @ =gParasiteRelated
    ldrb r0, [r6]
    cmp r0, #0
    bne lbl_08030a44
    movs r0, #0x60
    movs r1, #0x48
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    beq lbl_08030a38
    movs r0, #0x5a
    strb r0, [r6]
lbl_08030a38:
    movs r0, #1
    ands r4, r0
    adds r4, #1
    b lbl_08030a4a
    .align 2, 0
lbl_08030a40: .4byte gParasiteRelated
lbl_08030a44:
    adds r0, r5, #0
    adds r0, #0x2e
    ldrb r4, [r0]
lbl_08030a4a:
    ldrh r1, [r5]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08030a7c
    ldr r0, lbl_08030a78 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_08030a70
    ldrh r0, [r5, #2]
    subs r0, #0x10
    ldrh r1, [r5, #4]
    adds r1, #0x10
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    beq lbl_08030a98
lbl_08030a70:
    ldrh r0, [r5, #4]
    adds r0, r4, r0
    b lbl_08030aac
    .align 2, 0
lbl_08030a78: .4byte gPreviousVerticalCollisionCheck
lbl_08030a7c:
    ldr r0, lbl_08030aa4 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_08030aa8
    ldrh r0, [r5, #2]
    subs r0, #0x10
    ldrh r1, [r5, #4]
    subs r1, #0x10
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    bne lbl_08030aa8
lbl_08030a98:
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0xa
    strb r0, [r1]
    b lbl_08030aae
    .align 2, 0
lbl_08030aa4: .4byte gPreviousVerticalCollisionCheck
lbl_08030aa8:
    ldrh r0, [r5, #4]
    subs r0, r0, r4
lbl_08030aac:
    strh r0, [r5, #4]
lbl_08030aae:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start ParasiteIdle
ParasiteIdle: @ 0x08030ab4
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08030ace
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_08030c52
lbl_08030ace:
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08030af0
    ldr r0, lbl_08030aec @ =gFrameCounter8Bit
    ldrb r1, [r0]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08030b20
    b lbl_08030afc
    .align 2, 0
lbl_08030aec: .4byte gFrameCounter8Bit
lbl_08030af0:
    ldr r0, lbl_08030b1c @ =gFrameCounter8Bit
    ldrb r1, [r0]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08030b20
lbl_08030afc:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl ClipdataProcess
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    bne lbl_08030b20
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x1e
    strb r0, [r1]
    b lbl_08030c52
    .align 2, 0
lbl_08030b1c: .4byte gFrameCounter8Bit
lbl_08030b20:
    adds r2, r4, #0
    adds r2, #0x2c
    ldrb r5, [r2]
    ldr r0, lbl_08030b54 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    lsrs r0, r0, #4
    adds r1, r0, #0
    cmp r1, r5
    bne lbl_08030b60
    ldr r0, lbl_08030b58 @ =0x082e8350
    str r0, [r4, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r4, #0x16]
    strb r1, [r4, #0x1c]
    ldr r0, lbl_08030b5c @ =gSpriteRng
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    strb r0, [r2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    b lbl_08030c52
    .align 2, 0
lbl_08030b54: .4byte gFrameCounter8Bit
lbl_08030b58: .4byte 0x082e8350
lbl_08030b5c: .4byte gSpriteRng
lbl_08030b60:
    adds r0, r5, #1
    cmp r1, r0
    beq lbl_08030b6c
    subs r0, r5, #1
    cmp r1, r0
    bne lbl_08030bd8
lbl_08030b6c:
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x49
    strb r0, [r1]
    ldr r0, lbl_08030b94 @ =0x082e8480
    str r0, [r4, #0x18]
    movs r0, #0
    strh r2, [r4, #0x16]
    strb r0, [r4, #0x1c]
    ldr r0, lbl_08030b98 @ =gSpriteRng
    ldrb r1, [r0]
    cmp r1, #3
    bhi lbl_08030b9c
    adds r1, r4, #0
    adds r1, #0x2f
    movs r0, #4
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_08030ba4
    .align 2, 0
lbl_08030b94: .4byte 0x082e8480
lbl_08030b98: .4byte gSpriteRng
lbl_08030b9c:
    adds r0, r4, #0
    adds r0, #0x2f
    strb r1, [r0]
    adds r2, r0, #0
lbl_08030ba4:
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08030c52
    ldrb r5, [r2]
    cmp r5, #7
    bhi lbl_08030bbe
    movs r0, #0xba
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030c52
lbl_08030bbe:
    cmp r5, #0xb
    bls lbl_08030bcc
    movs r0, #0xbb
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030c52
lbl_08030bcc:
    ldr r0, lbl_08030bd4 @ =0x00000175
    bl SoundPlayNotAlreadyPlaying
    b lbl_08030c52
    .align 2, 0
lbl_08030bd4: .4byte 0x00000175
lbl_08030bd8:
    ldr r6, lbl_08030bf8 @ =gParasiteRelated
    ldrb r0, [r6]
    cmp r0, #0
    bne lbl_08030bfc
    movs r0, #0x60
    movs r1, #0x48
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    beq lbl_08030bf0
    movs r0, #0x5a
    strb r0, [r6]
lbl_08030bf0:
    movs r0, #1
    ands r5, r0
    adds r5, #1
    b lbl_08030c02
    .align 2, 0
lbl_08030bf8: .4byte gParasiteRelated
lbl_08030bfc:
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r5, [r0]
lbl_08030c02:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08030c2a
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    adds r1, #0x10
    bl ClipdataProcess
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    bne lbl_08030c42
    ldrh r0, [r4, #4]
    adds r0, r5, r0
    b lbl_08030c50
lbl_08030c2a:
    ldrh r0, [r4, #2]
    subs r0, #0x10
    ldrh r1, [r4, #4]
    subs r1, #0x10
    bl ClipdataProcess
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    cmp r0, #0
    beq lbl_08030c4c
lbl_08030c42:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xa
    strb r0, [r1]
    b lbl_08030c52
lbl_08030c4c:
    ldrh r0, [r4, #4]
    subs r0, r0, r5
lbl_08030c50:
    strh r0, [r4, #4]
lbl_08030c52:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start ParasiteTurningAroundInit
ParasiteTurningAroundInit: @ 0x08030c58
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0xb
    strb r1, [r2]
    ldr r1, lbl_08030c70 @ =0x082e8400
    str r1, [r0, #0x18]
    movs r1, #0
    strh r3, [r0, #0x16]
    strb r1, [r0, #0x1c]
    bx lr
    .align 2, 0
lbl_08030c70: .4byte 0x082e8400

    thumb_func_start ParasiteTurningAroundFirstPart
ParasiteTurningAroundFirstPart: @ 0x08030c74
    push {r4, lr}
    adds r4, r0, #0
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08030c90
    ldrh r0, [r4]
    movs r1, #0x40
    eors r0, r1
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xc
    strb r0, [r1]
lbl_08030c90:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteTurningAroundSecondPart
ParasiteTurningAroundSecondPart: @ 0x08030c98
    push {r4, lr}
    adds r4, r0, #0
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08030cac
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
lbl_08030cac:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08030cb4
sub_08030cb4: @ 0x08030cb4
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0xf
    strb r1, [r2]
    ldr r1, lbl_08030cd0 @ =0x082e8350
    str r1, [r0, #0x18]
    movs r1, #0
    strh r3, [r0, #0x16]
    strb r1, [r0, #0x1c]
    adds r0, #0x2c
    movs r1, #0x1e
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08030cd0: .4byte 0x082e8350

    thumb_func_start ParasiteLanding
ParasiteLanding: @ 0x08030cd4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_08030cf2
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x1e
    b lbl_08030d6a
lbl_08030cf2:
    movs r5, #0
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08030d10 @ =0x082e8350
    cmp r1, r0
    bne lbl_08030d14
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08030d4a
    b lbl_08030d4e
    .align 2, 0
lbl_08030d10: .4byte 0x082e8350
lbl_08030d14:
    ldr r0, lbl_08030d38 @ =0x082e8398
    cmp r1, r0
    bne lbl_08030d40
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08030d4a
    ldr r0, lbl_08030d3c @ =0x082e83c0
    str r0, [r4, #0x18]
    movs r0, #0
    strh r5, [r4, #0x16]
    strb r0, [r4, #0x1c]
    b lbl_08030d4a
    .align 2, 0
lbl_08030d38: .4byte 0x082e8398
lbl_08030d3c: .4byte 0x082e83c0
lbl_08030d40:
    bl SpriteUtilCheckNearEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08030d4a
    movs r5, #1
lbl_08030d4a:
    cmp r5, #0
    beq lbl_08030d6c
lbl_08030d4e:
    ldr r0, lbl_08030d60 @ =gSpriteRng
    ldrb r0, [r0]
    cmp r0, #6
    bls lbl_08030d64
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #8
    b lbl_08030d6a
    .align 2, 0
lbl_08030d60: .4byte gSpriteRng
lbl_08030d64:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xa
lbl_08030d6a:
    strb r0, [r1]
lbl_08030d6c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08030d74
sub_08030d74: @ 0x08030d74
    adds r2, r0, #0
    adds r2, #0x24
    movs r3, #0
    movs r1, #0x1f
    strb r1, [r2]
    adds r0, #0x2f
    strb r3, [r0]
    bx lr

    thumb_func_start ParasiteFalling
ParasiteFalling: @ 0x08030d84
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldrh r6, [r4, #2]
    adds r3, r4, #0
    adds r3, #0x2f
    ldrb r1, [r3]
    ldr r5, lbl_08030db0 @ =0x082b0d04
    lsls r0, r1, #1
    adds r0, r0, r5
    movs r7, #0
    ldrsh r2, [r0, r7]
    ldr r0, lbl_08030db4 @ =0x00007fff
    cmp r2, r0
    bne lbl_08030db8
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r5
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, r6, r0
    b lbl_08030dc0
    .align 2, 0
lbl_08030db0: .4byte 0x082b0d04
lbl_08030db4: .4byte 0x00007fff
lbl_08030db8:
    adds r0, r1, #1
    strb r0, [r3]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_08030dc0:
    strh r0, [r4, #2]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_08030de0 @ =gPreviousVerticalCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08030de4
    strh r1, [r4, #2]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    b lbl_08030df0
    .align 2, 0
lbl_08030de0: .4byte gPreviousVerticalCollisionCheck
lbl_08030de4:
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r6, #0
    movs r3, #1
    bl SpriteUtilCheckInRoomEffect
lbl_08030df0:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08030df8
sub_08030df8: @ 0x08030df8
    push {r4, lr}
    ldrh r2, [r0]
    ldr r1, lbl_08030e28 @ =0x0000fe7f
    ands r1, r2
    movs r4, #0
    movs r3, #0
    strh r1, [r0]
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x67
    strb r1, [r2]
    ldr r1, lbl_08030e2c @ =0x082e8598
    str r1, [r0, #0x18]
    strh r3, [r0, #0x16]
    strb r4, [r0, #0x1c]
    ldr r1, lbl_08030e30 @ =gIoRegistersBackup
    ldrb r2, [r1, #0xc]
    movs r1, #3
    ands r1, r2
    adds r0, #0x21
    strb r1, [r0]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08030e28: .4byte 0x0000fe7f
lbl_08030e2c: .4byte 0x082e8598
lbl_08030e30: .4byte gIoRegistersBackup

    thumb_func_start sub_08030e34
sub_08030e34: @ 0x08030e34
    push {r4, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08030e4c
    movs r0, #0
    strh r0, [r4]
lbl_08030e4c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ParasiteMultipleDying
ParasiteMultipleDying: @ 0x08030e54
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r1, r4, #0
    adds r1, #0x26
    movs r5, #0
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08030ea6
    strh r5, [r4]
    ldr r2, lbl_08030eac @ =gSpriteData
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r1, [r0]
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    strh r5, [r0]
    movs r0, #3
    movs r1, #0x2d
    bl EventFunction
    cmp r0, #0
    bne lbl_08030ea6
    movs r0, #0x5e
    bl SpriteUtilCountPrimarySprites
    cmp r0, #0
    bne lbl_08030ea6
    movs r0, #1
    movs r1, #0x2d
    bl EventFunction
    ldr r1, lbl_08030eb0 @ =gDoorUnlockTimer
    movs r2, #0x14
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
lbl_08030ea6:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08030eac: .4byte gSpriteData
lbl_08030eb0: .4byte gDoorUnlockTimer

    thumb_func_start sub_08030eb4
sub_08030eb4: @ 0x08030eb4
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    adds r1, r3, #0
    adds r1, #0x24
    movs r6, #0
    movs r0, #0x4d
    strb r0, [r1]
    ldr r0, lbl_08030f00 @ =0x082e84e0
    str r0, [r3, #0x18]
    movs r1, #0
    strh r6, [r3, #0x16]
    strb r1, [r3, #0x1c]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r1, [r0]
    adds r0, #1
    ldrb r4, [r0]
    ldr r2, lbl_08030f04 @ =gSpriteData
    lsls r1, r4, #3
    subs r1, r1, r4
    lsls r1, r1, #3
    adds r1, r1, r2
    ldrh r0, [r1, #0xa]
    ldrh r5, [r1, #2]
    adds r0, r0, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r0, [r1, #0xe]
    ldrh r1, [r1, #4]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r3, #2]
    cmp r0, r5
    bhs lbl_08030f08
    strh r6, [r3, #6]
    b lbl_08030f0c
    .align 2, 0
lbl_08030f00: .4byte 0x082e84e0
lbl_08030f04: .4byte gSpriteData
lbl_08030f08:
    subs r0, r0, r5
    strh r0, [r3, #6]
lbl_08030f0c:
    ldrh r0, [r3, #4]
    cmp r0, r1
    bhs lbl_08030f16
    movs r0, #0
    b lbl_08030f18
lbl_08030f16:
    subs r0, r0, r1
lbl_08030f18:
    strh r0, [r3, #8]
    ldrh r0, [r3, #2]
    lsls r1, r4, #3
    subs r1, r1, r4
    lsls r1, r1, #3
    adds r1, r1, r2
    ldrh r1, [r1, #2]
    subs r1, #0x60
    cmp r0, r1
    ble lbl_08030f38
    ldrh r1, [r3]
    ldr r0, lbl_08030f34 @ =0x0000feff
    ands r0, r1
    b lbl_08030f42
    .align 2, 0
lbl_08030f34: .4byte 0x0000feff
lbl_08030f38:
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r2, #0
    orrs r0, r1
lbl_08030f42:
    strh r0, [r3]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08030f4c
sub_08030f4c: @ 0x08030f4c
    push {r4, r5, r6, r7, lr}
    adds r3, r0, #0
    adds r0, #0x2d
    ldrb r6, [r0]
    ldr r1, lbl_08030f94 @ =gSpriteData
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r2, r0, r1
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    mov ip, r1
    cmp r0, #0x25
    bne lbl_08030fa0
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x44
    strb r1, [r0]
    ldr r0, lbl_08030f98 @ =gSpriteRng
    ldrb r0, [r0]
    cmp r0, #5
    bhi lbl_08030f7c
    movs r0, #6
lbl_08030f7c:
    adds r1, r3, #0
    adds r1, #0x2e
    strb r0, [r1]
    subs r1, #9
    movs r0, #0x17
    strb r0, [r1]
    ldrh r1, [r3]
    ldr r0, lbl_08030f9c @ =0x00007fff
    ands r0, r1
    strh r0, [r3]
    b lbl_080310e2
    .align 2, 0
lbl_08030f94: .4byte gSpriteData
lbl_08030f98: .4byte gSpriteRng
lbl_08030f9c: .4byte 0x00007fff
lbl_08030fa0:
    ldr r1, lbl_08030fd0 @ =gParasiteRelated
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08030fac
    movs r0, #0x5a
    strb r0, [r1]
lbl_08030fac:
    ldrh r5, [r3]
    movs r7, #0x80
    lsls r7, r7, #1
    adds r0, r7, #0
    ands r0, r5
    cmp r0, #0
    beq lbl_08030fd8
    ldrh r1, [r2, #2]
    ldrh r0, [r3, #2]
    adds r0, #8
    adds r4, r3, #0
    adds r4, #0x2c
    cmp r1, r0
    bge lbl_08030ff8
    ldr r0, lbl_08030fd4 @ =0x0000feff
    ands r0, r5
    b lbl_08030ff0
    .align 2, 0
lbl_08030fd0: .4byte gParasiteRelated
lbl_08030fd4: .4byte 0x0000feff
lbl_08030fd8:
    movs r0, #0xa
    ldrsh r1, [r2, r0]
    ldrh r2, [r2, #2]
    adds r1, r1, r2
    ldrh r0, [r3, #2]
    subs r0, #8
    adds r4, r3, #0
    adds r4, #0x2c
    cmp r1, r0
    ble lbl_08030ff8
    adds r0, r7, #0
    orrs r0, r5
lbl_08030ff0:
    strh r0, [r3]
    ldr r0, lbl_08031020 @ =gSpriteRng
    ldrb r0, [r0]
    strb r0, [r4]
lbl_08030ff8:
    ldrh r5, [r3]
    movs r0, #0x40
    ands r0, r5
    cmp r0, #0
    beq lbl_08031028
    lsls r2, r6, #3
    subs r0, r2, r6
    lsls r0, r0, #3
    add r0, ip
    movs r7, #0x10
    ldrsh r1, [r0, r7]
    ldrh r0, [r0, #4]
    adds r1, r1, r0
    ldrh r0, [r3, #4]
    adds r0, #8
    cmp r1, r0
    bge lbl_0803104c
    ldr r0, lbl_08031024 @ =0x0000ffbf
    ands r0, r5
    b lbl_08031044
    .align 2, 0
lbl_08031020: .4byte gSpriteRng
lbl_08031024: .4byte 0x0000ffbf
lbl_08031028:
    lsls r2, r6, #3
    subs r0, r2, r6
    lsls r0, r0, #3
    add r0, ip
    movs r7, #0xe
    ldrsh r1, [r0, r7]
    ldrh r0, [r0, #4]
    adds r1, r1, r0
    ldrh r0, [r3, #4]
    subs r0, #8
    cmp r1, r0
    ble lbl_0803104c
    movs r0, #0x40
    orrs r0, r5
lbl_08031044:
    strh r0, [r3]
    ldr r0, lbl_08031070 @ =gSpriteRng
    ldrb r0, [r0]
    strb r0, [r4]
lbl_0803104c:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_080310b8
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_08031074
    ldr r0, lbl_08031070 @ =gSpriteRng
    ldrb r1, [r0]
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_08031084
    ldrh r0, [r3, #6]
    adds r0, #1
    b lbl_08031082
    .align 2, 0
lbl_08031070: .4byte gSpriteRng
lbl_08031074:
    ldr r0, lbl_080310a0 @ =gSpriteRng
    ldrb r1, [r0]
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_08031084
    ldrh r0, [r3, #6]
    subs r0, #1
lbl_08031082:
    strh r0, [r3, #6]
lbl_08031084:
    movs r0, #0x40
    ands r0, r5
    cmp r0, #0
    beq lbl_080310a4
    adds r1, r3, #0
    adds r1, #0x23
    ldrb r0, [r4]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080310bc
    ldrh r0, [r3, #8]
    adds r0, #1
    strh r0, [r3, #8]
    b lbl_080310bc
    .align 2, 0
lbl_080310a0: .4byte gSpriteRng
lbl_080310a4:
    adds r1, r3, #0
    adds r1, #0x23
    ldrb r0, [r4]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080310bc
    ldrh r0, [r3, #8]
    subs r0, #1
    strh r0, [r3, #8]
    b lbl_080310bc
lbl_080310b8:
    subs r0, #1
    strb r0, [r4]
lbl_080310bc:
    subs r0, r2, r6
    lsls r0, r0, #3
    add r0, ip
    ldrh r1, [r0, #0xa]
    ldrh r2, [r0, #2]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    ldrh r2, [r0, #0xe]
    ldrh r0, [r0, #4]
    adds r2, r2, r0
    lsls r2, r2, #0x10
    lsrs r1, r1, #0x10
    ldrh r7, [r3, #6]
    adds r1, r1, r7
    strh r1, [r3, #2]
    lsrs r2, r2, #0x10
    ldrh r0, [r3, #8]
    adds r2, r2, r0
    strh r2, [r3, #4]
lbl_080310e2:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ParasiteProjectilesCollision
ParasiteProjectilesCollision: @ 0x080310e8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r6, r0, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08031114
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
    b lbl_080311ea
lbl_0803110c:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    b lbl_080311ae
lbl_08031114:
    movs r7, #0
    ldrh r1, [r6, #2]
    ldrh r0, [r6, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x10]
    ldrh r0, [r6, #0xc]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp, #0x14]
    ldrh r1, [r6, #4]
    ldrh r0, [r6, #0xe]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrh r0, [r6, #0x10]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r8, r1
    ldr r5, lbl_080311bc @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r5, r1
    movs r1, #0x24
    adds r1, r1, r6
    mov sl, r1
    cmp r5, r0
    bhs lbl_080311ae
lbl_08031154:
    ldrb r0, [r5]
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080311a6
    ldrb r0, [r5, #0xf]
    cmp r0, #0xe
    bne lbl_080311a6
    ldrb r0, [r5, #0x11]
    cmp r0, #3
    bne lbl_080311a6
    ldrh r3, [r5, #8]
    ldrh r4, [r5, #0x14]
    adds r4, r3, r4
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldrh r0, [r5, #0x16]
    adds r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrh r2, [r5, #0xa]
    ldrh r1, [r5, #0x18]
    adds r1, r2, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r0, [r5, #0x1a]
    adds r2, r2, r0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r4, [sp]
    str r3, [sp, #4]
    str r1, [sp, #8]
    str r2, [sp, #0xc]
    ldr r0, [sp, #0x10]
    ldr r1, [sp, #0x14]
    mov r2, sb
    mov r3, r8
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    bne lbl_0803110c
lbl_080311a6:
    adds r5, #0x1c
    ldr r0, lbl_080311c0 @ =gArmCannonY
    cmp r5, r0
    blo lbl_08031154
lbl_080311ae:
    cmp r7, #0
    beq lbl_080311c4
    movs r0, #0x62
    mov r1, sl
    strb r0, [r1]
    b lbl_080311ea
    .align 2, 0
lbl_080311bc: .4byte gProjectileData
lbl_080311c0: .4byte gArmCannonY
lbl_080311c4:
    adds r0, r6, #0
    adds r0, #0x2b
    strb r7, [r0]
    movs r0, #1
    strh r0, [r6, #0x14]
    movs r0, #0x44
    mov r1, sl
    strb r0, [r1]
    ldr r0, lbl_080311fc @ =gSpriteRng
    ldrb r0, [r0]
    lsrs r7, r0, #1
    cmp r7, #8
    bhi lbl_080311e0
    movs r7, #9
lbl_080311e0:
    adds r0, r6, #0
    adds r0, #0x2e
    strb r7, [r0]
    bl SpriteUtilMakeSpriteFaceAwawFromSamusDirection
lbl_080311ea:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080311fc: .4byte gSpriteRng

    thumb_func_start ParasiteMultiple
ParasiteMultiple: @ 0x08031200
    push {r4, lr}
    ldr r4, lbl_08031238 @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_08031222
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x66
    bhi lbl_08031222
    adds r0, r4, #0
    bl ParasiteProjectilesCollision
lbl_08031222:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    bls lbl_0803122e
    b lbl_0803146a
lbl_0803122e:
    lsls r0, r0, #2
    ldr r1, lbl_0803123c @ =lbl_08031240
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08031238: .4byte gCurrentSprite
lbl_0803123c: .4byte lbl_08031240
lbl_08031240: @ jump table
    .4byte lbl_080313e0 @ case 0
    .4byte lbl_0803146a @ case 1
    .4byte lbl_0803146a @ case 2
    .4byte lbl_0803146a @ case 3
    .4byte lbl_0803146a @ case 4
    .4byte lbl_0803146a @ case 5
    .4byte lbl_0803146a @ case 6
    .4byte lbl_0803146a @ case 7
    .4byte lbl_080313e8 @ case 8
    .4byte lbl_080313f0 @ case 9
    .4byte lbl_080313f8 @ case 10
    .4byte lbl_080313fe @ case 11
    .4byte lbl_08031406 @ case 12
    .4byte lbl_0803146a @ case 13
    .4byte lbl_0803140e @ case 14
    .4byte lbl_08031414 @ case 15
    .4byte lbl_0803146a @ case 16
    .4byte lbl_0803146a @ case 17
    .4byte lbl_0803146a @ case 18
    .4byte lbl_0803146a @ case 19
    .4byte lbl_0803146a @ case 20
    .4byte lbl_0803146a @ case 21
    .4byte lbl_0803146a @ case 22
    .4byte lbl_0803146a @ case 23
    .4byte lbl_0803146a @ case 24
    .4byte lbl_0803146a @ case 25
    .4byte lbl_0803146a @ case 26
    .4byte lbl_0803146a @ case 27
    .4byte lbl_0803146a @ case 28
    .4byte lbl_0803146a @ case 29
    .4byte lbl_0803141c @ case 30
    .4byte lbl_08031422 @ case 31
    .4byte lbl_0803146a @ case 32
    .4byte lbl_0803146a @ case 33
    .4byte lbl_0803146a @ case 34
    .4byte lbl_0803146a @ case 35
    .4byte lbl_0803146a @ case 36
    .4byte lbl_0803146a @ case 37
    .4byte lbl_0803146a @ case 38
    .4byte lbl_0803146a @ case 39
    .4byte lbl_0803146a @ case 40
    .4byte lbl_0803146a @ case 41
    .4byte lbl_0803146a @ case 42
    .4byte lbl_0803146a @ case 43
    .4byte lbl_0803146a @ case 44
    .4byte lbl_0803146a @ case 45
    .4byte lbl_0803146a @ case 46
    .4byte lbl_0803146a @ case 47
    .4byte lbl_0803146a @ case 48
    .4byte lbl_0803146a @ case 49
    .4byte lbl_0803146a @ case 50
    .4byte lbl_0803146a @ case 51
    .4byte lbl_0803146a @ case 52
    .4byte lbl_0803146a @ case 53
    .4byte lbl_0803146a @ case 54
    .4byte lbl_0803146a @ case 55
    .4byte lbl_0803146a @ case 56
    .4byte lbl_0803146a @ case 57
    .4byte lbl_0803146a @ case 58
    .4byte lbl_0803146a @ case 59
    .4byte lbl_0803146a @ case 60
    .4byte lbl_0803146a @ case 61
    .4byte lbl_0803146a @ case 62
    .4byte lbl_0803146a @ case 63
    .4byte lbl_0803146a @ case 64
    .4byte lbl_0803146a @ case 65
    .4byte lbl_0803142a @ case 66
    .4byte lbl_08031430 @ case 67
    .4byte lbl_08031438 @ case 68
    .4byte lbl_0803143e @ case 69
    .4byte lbl_0803146a @ case 70
    .4byte lbl_08031446 @ case 71
    .4byte lbl_0803146a @ case 72
    .4byte lbl_0803144e @ case 73
    .4byte lbl_0803146a @ case 74
    .4byte lbl_08031456 @ case 75
    .4byte lbl_0803146a @ case 76
    .4byte lbl_0803146a @ case 77
    .4byte lbl_0803146a @ case 78
    .4byte lbl_0803146a @ case 79
    .4byte lbl_0803146a @ case 80
    .4byte lbl_0803146a @ case 81
    .4byte lbl_0803146a @ case 82
    .4byte lbl_0803146a @ case 83
    .4byte lbl_0803146a @ case 84
    .4byte lbl_0803146a @ case 85
    .4byte lbl_0803146a @ case 86
    .4byte lbl_0803146a @ case 87
    .4byte lbl_0803146a @ case 88
    .4byte lbl_0803146a @ case 89
    .4byte lbl_0803146a @ case 90
    .4byte lbl_0803146a @ case 91
    .4byte lbl_0803146a @ case 92
    .4byte lbl_0803146a @ case 93
    .4byte lbl_0803146a @ case 94
    .4byte lbl_0803146a @ case 95
    .4byte lbl_0803146a @ case 96
    .4byte lbl_0803146a @ case 97
    .4byte lbl_0803145e @ case 98
    .4byte lbl_0803146a @ case 99
    .4byte lbl_0803146a @ case 100
    .4byte lbl_0803146a @ case 101
    .4byte lbl_0803146a @ case 102
    .4byte lbl_08031464 @ case 103
lbl_080313e0:
    adds r0, r4, #0
    bl ParasiteInit
    b lbl_0803146a
lbl_080313e8:
    adds r0, r4, #0
    bl ParasiteIdleInit
    b lbl_0803146a
lbl_080313f0:
    adds r0, r4, #0
    bl ParasiteIdle
    b lbl_0803146a
lbl_080313f8:
    adds r0, r4, #0
    bl ParasiteTurningAroundInit
lbl_080313fe:
    adds r0, r4, #0
    bl ParasiteTurningAroundFirstPart
    b lbl_0803146a
lbl_08031406:
    adds r0, r4, #0
    bl ParasiteTurningAroundSecondPart
    b lbl_0803146a
lbl_0803140e:
    adds r0, r4, #0
    bl sub_08030cb4
lbl_08031414:
    adds r0, r4, #0
    bl ParasiteLanding
    b lbl_0803146a
lbl_0803141c:
    adds r0, r4, #0
    bl sub_08030d74
lbl_08031422:
    adds r0, r4, #0
    bl ParasiteFalling
    b lbl_0803146a
lbl_0803142a:
    adds r0, r4, #0
    bl ParasiteGrabSamus
lbl_08031430:
    adds r0, r4, #0
    bl ParasiteSamusGrabbed
    b lbl_0803146a
lbl_08031438:
    adds r0, r4, #0
    bl ParasiteExpulsedInit
lbl_0803143e:
    adds r0, r4, #0
    bl ParasiteExpulsed
    b lbl_0803146a
lbl_08031446:
    adds r0, r4, #0
    bl ParasiteMultipleExpulsedDown
    b lbl_0803146a
lbl_0803144e:
    adds r0, r4, #0
    bl ParasiteJumping
    b lbl_0803146a
lbl_08031456:
    adds r0, r4, #0
    bl ParasiteJumpingDown
    b lbl_0803146a
lbl_0803145e:
    adds r0, r4, #0
    bl sub_08030df8
lbl_08031464:
    adds r0, r4, #0
    bl ParasiteMultipleDying
lbl_0803146a:
    ldrh r1, [r4]
    ldr r0, lbl_08031478 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08031478: .4byte 0x0000f7ff

    thumb_func_start Parasite
Parasite: @ 0x0803147c
    push {r4, lr}
    ldr r4, lbl_080314b4 @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0803149e
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x66
    bhi lbl_0803149e
    adds r0, r4, #0
    bl ParasiteProjectilesCollision
lbl_0803149e:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    bls lbl_080314aa
    b lbl_080316f4
lbl_080314aa:
    lsls r0, r0, #2
    ldr r1, lbl_080314b8 @ =lbl_080314bc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080314b4: .4byte gCurrentSprite
lbl_080314b8: .4byte lbl_080314bc
lbl_080314bc: @ jump table
    .4byte lbl_0803165c @ case 0
    .4byte lbl_080316f4 @ case 1
    .4byte lbl_080316f4 @ case 2
    .4byte lbl_080316f4 @ case 3
    .4byte lbl_080316f4 @ case 4
    .4byte lbl_080316f4 @ case 5
    .4byte lbl_080316f4 @ case 6
    .4byte lbl_080316f4 @ case 7
    .4byte lbl_08031664 @ case 8
    .4byte lbl_0803166a @ case 9
    .4byte lbl_08031672 @ case 10
    .4byte lbl_08031678 @ case 11
    .4byte lbl_08031680 @ case 12
    .4byte lbl_080316f4 @ case 13
    .4byte lbl_08031688 @ case 14
    .4byte lbl_0803168e @ case 15
    .4byte lbl_080316f4 @ case 16
    .4byte lbl_080316f4 @ case 17
    .4byte lbl_080316f4 @ case 18
    .4byte lbl_080316f4 @ case 19
    .4byte lbl_080316f4 @ case 20
    .4byte lbl_080316f4 @ case 21
    .4byte lbl_080316f4 @ case 22
    .4byte lbl_080316f4 @ case 23
    .4byte lbl_080316f4 @ case 24
    .4byte lbl_080316f4 @ case 25
    .4byte lbl_080316f4 @ case 26
    .4byte lbl_080316f4 @ case 27
    .4byte lbl_080316f4 @ case 28
    .4byte lbl_080316f4 @ case 29
    .4byte lbl_08031696 @ case 30
    .4byte lbl_0803169c @ case 31
    .4byte lbl_080316f4 @ case 32
    .4byte lbl_080316f4 @ case 33
    .4byte lbl_080316f4 @ case 34
    .4byte lbl_080316f4 @ case 35
    .4byte lbl_080316f4 @ case 36
    .4byte lbl_080316f4 @ case 37
    .4byte lbl_080316f4 @ case 38
    .4byte lbl_080316f4 @ case 39
    .4byte lbl_080316f4 @ case 40
    .4byte lbl_080316f4 @ case 41
    .4byte lbl_080316f4 @ case 42
    .4byte lbl_080316f4 @ case 43
    .4byte lbl_080316f4 @ case 44
    .4byte lbl_080316f4 @ case 45
    .4byte lbl_080316f4 @ case 46
    .4byte lbl_080316f4 @ case 47
    .4byte lbl_080316f4 @ case 48
    .4byte lbl_080316f4 @ case 49
    .4byte lbl_080316f4 @ case 50
    .4byte lbl_080316f4 @ case 51
    .4byte lbl_080316f4 @ case 52
    .4byte lbl_080316f4 @ case 53
    .4byte lbl_080316f4 @ case 54
    .4byte lbl_080316f4 @ case 55
    .4byte lbl_080316f4 @ case 56
    .4byte lbl_080316f4 @ case 57
    .4byte lbl_080316f4 @ case 58
    .4byte lbl_080316f4 @ case 59
    .4byte lbl_080316f4 @ case 60
    .4byte lbl_080316f4 @ case 61
    .4byte lbl_080316f4 @ case 62
    .4byte lbl_080316f4 @ case 63
    .4byte lbl_080316f4 @ case 64
    .4byte lbl_080316f4 @ case 65
    .4byte lbl_080316a4 @ case 66
    .4byte lbl_080316aa @ case 67
    .4byte lbl_080316b2 @ case 68
    .4byte lbl_080316b8 @ case 69
    .4byte lbl_080316f4 @ case 70
    .4byte lbl_080316c0 @ case 71
    .4byte lbl_080316f4 @ case 72
    .4byte lbl_080316c8 @ case 73
    .4byte lbl_080316f4 @ case 74
    .4byte lbl_080316d0 @ case 75
    .4byte lbl_080316d8 @ case 76
    .4byte lbl_080316e0 @ case 77
    .4byte lbl_080316f4 @ case 78
    .4byte lbl_080316f4 @ case 79
    .4byte lbl_080316f4 @ case 80
    .4byte lbl_080316f4 @ case 81
    .4byte lbl_080316f4 @ case 82
    .4byte lbl_080316f4 @ case 83
    .4byte lbl_080316f4 @ case 84
    .4byte lbl_080316f4 @ case 85
    .4byte lbl_080316f4 @ case 86
    .4byte lbl_080316f4 @ case 87
    .4byte lbl_080316f4 @ case 88
    .4byte lbl_080316f4 @ case 89
    .4byte lbl_080316f4 @ case 90
    .4byte lbl_080316f4 @ case 91
    .4byte lbl_080316f4 @ case 92
    .4byte lbl_080316f4 @ case 93
    .4byte lbl_080316f4 @ case 94
    .4byte lbl_080316f4 @ case 95
    .4byte lbl_080316f4 @ case 96
    .4byte lbl_080316f4 @ case 97
    .4byte lbl_080316e8 @ case 98
    .4byte lbl_080316f4 @ case 99
    .4byte lbl_080316f4 @ case 100
    .4byte lbl_080316f4 @ case 101
    .4byte lbl_080316f4 @ case 102
    .4byte lbl_080316ee @ case 103
lbl_0803165c:
    adds r0, r4, #0
    bl ParasiteInit
    b lbl_080316f4
lbl_08031664:
    adds r0, r4, #0
    bl ParasiteIdleInit
lbl_0803166a:
    adds r0, r4, #0
    bl sub_0803091c
    b lbl_080316f4
lbl_08031672:
    adds r0, r4, #0
    bl ParasiteTurningAroundInit
lbl_08031678:
    adds r0, r4, #0
    bl ParasiteTurningAroundFirstPart
    b lbl_080316f4
lbl_08031680:
    adds r0, r4, #0
    bl ParasiteTurningAroundSecondPart
    b lbl_080316f4
lbl_08031688:
    adds r0, r4, #0
    bl sub_08030cb4
lbl_0803168e:
    adds r0, r4, #0
    bl ParasiteLanding
    b lbl_080316f4
lbl_08031696:
    adds r0, r4, #0
    bl sub_08030d74
lbl_0803169c:
    adds r0, r4, #0
    bl ParasiteFalling
    b lbl_080316f4
lbl_080316a4:
    adds r0, r4, #0
    bl ParasiteGrabSamus
lbl_080316aa:
    adds r0, r4, #0
    bl ParasiteSamusGrabbed
    b lbl_080316f4
lbl_080316b2:
    adds r0, r4, #0
    bl ParasiteExpulsedInit
lbl_080316b8:
    adds r0, r4, #0
    bl parasite_star_explused_after_grabbing_object
    b lbl_080316f4
lbl_080316c0:
    adds r0, r4, #0
    bl parasite_explused_after_grabbing_object
    b lbl_080316f4
lbl_080316c8:
    adds r0, r4, #0
    bl sub_080305cc
    b lbl_080316f4
lbl_080316d0:
    adds r0, r4, #0
    bl sub_08030740
    b lbl_080316f4
lbl_080316d8:
    adds r0, r4, #0
    bl sub_08030eb4
    b lbl_080316f4
lbl_080316e0:
    adds r0, r4, #0
    bl sub_08030f4c
    b lbl_080316f4
lbl_080316e8:
    adds r0, r4, #0
    bl sub_08030df8
lbl_080316ee:
    adds r0, r4, #0
    bl sub_08030e34
lbl_080316f4:
    ldrh r1, [r4]
    ldr r0, lbl_08031704 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08031704: .4byte 0x0000f7ff
