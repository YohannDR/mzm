    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start SpriteUtilInitLocationText
SpriteUtilInitLocationText: @ 0x0800e498
    push {r4, lr}
    bl LocationTextGetGfxSlot
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #7
    bhi lbl_0800e502
    ldr r0, lbl_0800e508 @ =gSpriteData
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
    ldr r1, lbl_0800e510 @ =gSamusData
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
lbl_0800e508: .4byte gSpriteData
lbl_0800e50c: .4byte 0x00008017
lbl_0800e510: .4byte gSamusData

    thumb_func_start SpriteUtilCheckStopSamusAgainstSolidSpriteLeft
SpriteUtilCheckStopSamusAgainstSolidSpriteLeft: @ 0x0800e514
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r2, lbl_0800e594 @ =gSamusPhysics
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
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0800e598 @ =gPreviousCollisionCheck
    ldrb r2, [r6]
    mov r8, r2
    cmp r2, #0
    bne lbl_0800e586
    adds r0, r5, #0
    subs r0, #0x40
    movs r2, #0
    ldrsh r1, [r7, r2]
    adds r1, r4, r1
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0800e56a
    bl SpriteUtilCheckMorphed
    cmp r0, #0
    beq lbl_0800e586
lbl_0800e56a:
    ldr r2, lbl_0800e59c @ =gSamusData
    mov r0, sb
    strh r0, [r2, #0x12]
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0800e586
    ldr r0, lbl_0800e5a0 @ =gEquipment
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
lbl_0800e594: .4byte gSamusPhysics
lbl_0800e598: .4byte gPreviousCollisionCheck
lbl_0800e59c: .4byte gSamusData
lbl_0800e5a0: .4byte gEquipment

    thumb_func_start SpriteUtilCheckStopSamusAgainstSolidSpriteRight
SpriteUtilCheckStopSamusAgainstSolidSpriteRight: @ 0x0800e5a4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r2, lbl_0800e624 @ =gSamusPhysics
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
    bl SpriteUtilCheckCollisionAtPosition
    ldr r6, lbl_0800e628 @ =gPreviousCollisionCheck
    ldrb r2, [r6]
    mov r8, r2
    cmp r2, #0
    bne lbl_0800e618
    adds r0, r5, #0
    subs r0, #0x40
    movs r2, #0
    ldrsh r1, [r7, r2]
    adds r1, r4, r1
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0800e5fa
    bl SpriteUtilCheckMorphed
    cmp r0, #0
    beq lbl_0800e618
lbl_0800e5fa:
    ldr r2, lbl_0800e62c @ =gSamusData
    mov r0, sb
    adds r0, #1
    strh r0, [r2, #0x12]
    ldrh r1, [r2, #0xe]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0800e618
    ldr r0, lbl_0800e630 @ =gEquipment
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
lbl_0800e624: .4byte gSamusPhysics
lbl_0800e628: .4byte gPreviousCollisionCheck
lbl_0800e62c: .4byte gSamusData
lbl_0800e630: .4byte gEquipment

    thumb_func_start SpriteUtilTakeDamageFromSprite
SpriteUtilTakeDamageFromSprite: @ 0x0800e634
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
    ldr r1, lbl_0800e688 @ =gEquipment
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
lbl_0800e688: .4byte gEquipment
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
    ldr r0, lbl_0800e6bc @ =gDifficulty
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800e6c0
    lsrs r3, r3, #1
    b lbl_0800e6c8
    .align 2, 0
lbl_0800e6bc: .4byte gDifficulty
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
    bl SamusSetPose
lbl_0800e6e2:
    movs r0, #1
    b lbl_0800e6f2
lbl_0800e6e6:
    movs r0, #0
    strh r0, [r6, #6]
    movs r0, #0xfa
    bl SamusSetPose
    movs r0, #0
lbl_0800e6f2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start SpriteUtilCheckObjectsTouching
SpriteUtilCheckObjectsTouching: @ 0x0800e6f8
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

    thumb_func_start SpriteUtilSamusAndSpriteCollision
SpriteUtilSamusAndSpriteCollision: @ 0x0800e748
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x40
    ldr r0, lbl_0800e7c8 @ =gSamusData
    mov sl, r0
    movs r1, #0
    str r1, [sp, #0x10]
    ldrh r2, [r0, #0x14]
    str r2, [sp, #0x14]
    ldrh r3, [r0, #0x12]
    str r3, [sp, #0x18]
    ldr r0, lbl_0800e7cc @ =gPreviousXPosition
    ldrh r0, [r0]
    str r0, [sp, #0x2c]
    ldr r1, lbl_0800e7d0 @ =gSamusPhysics
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
lbl_0800e7c8: .4byte gSamusData
lbl_0800e7cc: .4byte gPreviousXPosition
lbl_0800e7d0: .4byte gSamusPhysics
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
    ldr r6, lbl_0800e8ec @ =gSpriteData
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
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    bne lbl_0800e898
    bl sub_0800f308
lbl_0800e898:
    ldr r0, lbl_0800e8f0 @ =gIgnoreSamusAndSpriteCollision
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
lbl_0800e8ec: .4byte gSpriteData
lbl_0800e8f0: .4byte gIgnoreSamusAndSpriteCollision
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
    bl SpriteUtilCheckPullingSelfUp
    cmp r0, #0
    beq lbl_0800e914
    bl lbl_0800f300
lbl_0800e914:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
    cmp r0, #0
    beq lbl_0800e924
    bl lbl_0800f300
lbl_0800e924:
    bl SpriteUtilCheckOnZipline
    cmp r0, #0
    beq lbl_0800e936
    movs r0, #0xfe
    bl SamusSetPose
    bl lbl_0800f300
lbl_0800e936:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800e98c
    ldr r0, lbl_0800e984 @ =gSamusPhysics
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800e988 @ =gPreviousCollisionCheck
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
lbl_0800e984: .4byte gSamusPhysics
lbl_0800e988: .4byte gPreviousCollisionCheck
lbl_0800e98c:
    ldr r0, [sp, #0x1c]
    adds r0, #0x10
    cmp r0, sb
    ble lbl_0800e9e8
    ldr r0, lbl_0800e9dc @ =gSamusPhysics
    adds r4, r0, #0
    adds r4, #0x70
    movs r3, #0
    ldrsh r0, [r4, r3]
    mov r1, sb
    subs r0, r1, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800e9e0 @ =gPreviousCollisionCheck
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
    ldr r0, lbl_0800e9e4 @ =gEquipment
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_0800e9d6
    bl lbl_0800f300
lbl_0800e9d6:
    strh r1, [r3, #0x18]
    bl lbl_0800f300
    .align 2, 0
lbl_0800e9dc: .4byte gSamusPhysics
lbl_0800e9e0: .4byte gPreviousCollisionCheck
lbl_0800e9e4: .4byte gEquipment
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
    ldr r1, lbl_0800eb30 @ =gIgnoreSamusAndSpriteCollision
    movs r0, #1
    strb r0, [r1]
lbl_0800eac6:
    bl SpriteUtilCheckPullingSelfUp
    cmp r0, #0
    beq lbl_0800ead2
    bl lbl_0800f300
lbl_0800ead2:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
    cmp r0, #0
    beq lbl_0800eae2
    bl lbl_0800f300
lbl_0800eae2:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800eb3c
    ldr r0, lbl_0800eb34 @ =gSamusPhysics
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800eb38 @ =gPreviousCollisionCheck
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
lbl_0800eb30: .4byte gIgnoreSamusAndSpriteCollision
lbl_0800eb34: .4byte gSamusPhysics
lbl_0800eb38: .4byte gPreviousCollisionCheck
lbl_0800eb3c:
    ldr r0, [sp, #0x1c]
    adds r0, #0x10
    cmp r0, sb
    ble lbl_0800eb90
    ldr r0, lbl_0800eb84 @ =gSamusPhysics
    adds r4, r0, #0
    adds r4, #0x70
    movs r1, #0
    ldrsh r0, [r4, r1]
    mov r2, sb
    subs r0, r2, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800eb88 @ =gPreviousCollisionCheck
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
    ldr r0, lbl_0800eb8c @ =gEquipment
    ldrh r0, [r0, #6]
    cmp r0, #0
    bne lbl_0800eb80
    b lbl_0800f300
lbl_0800eb80:
    strh r1, [r2, #0x18]
    b lbl_0800f300
    .align 2, 0
lbl_0800eb84: .4byte gSamusPhysics
lbl_0800eb88: .4byte gPreviousCollisionCheck
lbl_0800eb8c: .4byte gEquipment
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
    bl SpriteUtilCheckPullingSelfUp
    cmp r0, #0
    beq lbl_0800ebaa
    b lbl_0800f300
lbl_0800ebaa:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    ldr r0, lbl_0800ec04 @ =gSamusPhysics
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800ec08 @ =gPreviousCollisionCheck
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
lbl_0800ec04: .4byte gSamusPhysics
lbl_0800ec08: .4byte gPreviousCollisionCheck
lbl_0800ec0c:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
    cmp r0, #0
    beq lbl_0800ec1a
    b lbl_0800f300
lbl_0800ec1a:
    ldr r0, [sp, #0x14]
    subs r0, #0x18
    cmp r0, r5
    bge lbl_0800ec80
    bl SpriteUtilCheckPullingSelfUp
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
    ldr r0, lbl_0800ec78 @ =gSamusPhysics
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800ec7c @ =gPreviousCollisionCheck
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
lbl_0800ec78: .4byte gSamusPhysics
lbl_0800ec7c: .4byte gPreviousCollisionCheck
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilCheckPullingSelfUp
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
    ldr r0, lbl_0800ed54 @ =gSamusPhysics
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r0, #1
    adds r0, r5, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0800ed58 @ =gPreviousCollisionCheck
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
lbl_0800ed54: .4byte gSamusPhysics
lbl_0800ed58: .4byte gPreviousCollisionCheck
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilTakeDamageFromSprite
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
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilTakeDamageFromSprite
    ldr r0, lbl_0800ef64 @ =gEquipment
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
lbl_0800ef64: .4byte gEquipment
lbl_0800ef68:
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_0800ef70:
    movs r0, #0
    adds r1, r6, #0
    movs r2, #1
    bl SpriteUtilTakeDamageFromSprite
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
    ldr r0, lbl_0800efd0 @ =gPreviousYPosition
    strh r1, [r0]
    ldr r0, lbl_0800efd4 @ =gPreviousXPosition
    strh r2, [r0]
    movs r0, #0x28
    b lbl_0800eff4
    .align 2, 0
lbl_0800efd0: .4byte gPreviousYPosition
lbl_0800efd4: .4byte gPreviousXPosition
lbl_0800efd8:
    movs r0, #0x8f
    bl SoundStop
lbl_0800efde:
    ldrh r1, [r6, #2]
    adds r1, #0x3c
    mov r3, sl
    strh r1, [r3, #0x14]
    ldrh r2, [r6, #4]
    strh r2, [r3, #0x12]
    ldr r0, lbl_0800f008 @ =gPreviousYPosition
    strh r1, [r0]
    ldr r0, lbl_0800f00c @ =gPreviousXPosition
    strh r2, [r0]
    movs r0, #0x2b
lbl_0800eff4:
    bl SamusSetPose
    ldrh r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r6]
    b lbl_0800f2f4
    .align 2, 0
lbl_0800f008: .4byte gPreviousYPosition
lbl_0800f00c: .4byte gPreviousXPosition
lbl_0800f010:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteLeft
    b lbl_0800f300
lbl_0800f030:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteRight
    b lbl_0800f300
lbl_0800f03a:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteLeft
    b lbl_0800f062
lbl_0800f05a:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteRight
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
    bl SpriteUtilTakeDamageFromSprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800f07e
    b lbl_0800f2fa
lbl_0800f07e:
    ldr r0, lbl_0800f098 @ =gPreviousCollisionCheck
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
lbl_0800f098: .4byte gPreviousCollisionCheck
lbl_0800f09c: .4byte 0x0000ffc0
lbl_0800f0a0:
    movs r0, #0x40
    mov r3, sl
    strh r0, [r3, #0x16]
    b lbl_0800f2fa
lbl_0800f0a8:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
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
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteLeft
    b lbl_0800f0d0
lbl_0800f0c8:
    ldr r0, [sp, #0x14]
    adds r1, r7, #0
    bl SpriteUtilCheckStopSamusAgainstSolidSpriteRight
lbl_0800f0d0:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800f110
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl SpriteUtilTakeDamageFromSprite
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800f0ea
    b lbl_0800f2fa
lbl_0800f0ea:
    ldr r0, lbl_0800f104 @ =gPreviousCollisionCheck
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
lbl_0800f104: .4byte gPreviousCollisionCheck
lbl_0800f108: .4byte 0x0000ffc0
lbl_0800f10c:
    movs r0, #0x40
    b lbl_0800f146
lbl_0800f110:
    ldr r5, lbl_0800f14c @ =gPreviousCollisionCheck
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0800f11a
    b lbl_0800f2fa
lbl_0800f11a:
    ldr r0, lbl_0800f150 @ =gSamusPhysics
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    adds r0, #1
    ldr r2, [sp, #0x14]
    adds r0, r2, r0
    ldr r1, [sp, #0x18]
    bl SpriteUtilCheckCollisionAtPosition
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0800f136
    b lbl_0800f2fa
lbl_0800f136:
    movs r0, #0xf9
    bl SamusSetPose
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
lbl_0800f14c: .4byte gPreviousCollisionCheck
lbl_0800f150: .4byte gSamusPhysics
lbl_0800f154: .4byte 0x0000ffc0
lbl_0800f158:
    movs r0, #0x40
    mov r1, sl
    strh r0, [r1, #0x16]
    b lbl_0800f2fa
lbl_0800f160:
    adds r0, r6, #0
    mov r1, sl
    bl SpriteUtilSpriteTakeDamageFromSamusContact
    cmp r0, #0
    beq lbl_0800f16e
    b lbl_0800f300
lbl_0800f16e:
    movs r0, #0xf9
    bl SamusSetPose
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
    ldr r0, lbl_0800f1f8 @ =gEquipment
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
    bl SpriteUtilTakeDamageFromSprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800f1ee
    movs r0, #0x10
    mov r1, sl
    strb r0, [r1, #6]
    movs r0, #0x80
    bl SoundPlayNotAlreadyPlaying
    ldr r1, lbl_0800f1fc @ =gSubSpriteData1
    ldrb r0, [r1, #0xe]
    adds r0, #1
    strb r0, [r1, #0xe]
    movs r1, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0800f1ee
    movs r0, #0x7c
    bl SoundPlay
lbl_0800f1ee:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f300
    .align 2, 0
lbl_0800f1f8: .4byte gEquipment
lbl_0800f1fc: .4byte gSubSpriteData1
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
    bl SpriteUtilTakeDamageFromSprite
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0800f300
    ldr r0, lbl_0800f240 @ =gEquipment
    ldrb r0, [r0, #0xf]
    movs r1, #0x30
    ands r1, r0
    str r1, [sp, #0x10]
    cmp r1, #0
    bne lbl_0800f244
    movs r0, #1
    b lbl_0800f254
    .align 2, 0
lbl_0800f240: .4byte gEquipment
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
    bl RidleyCheckGrabbing
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
    ldr r1, lbl_0800f294 @ =gIgnoreSamusAndSpriteCollision
    movs r0, #1
    strb r0, [r1]
    movs r0, #8
    bl SamusSetPose
    ldr r0, lbl_0800f298 @ =0x000001e3
    bl SoundPlay
    b lbl_0800f300
    .align 2, 0
lbl_0800f294: .4byte gIgnoreSamusAndSpriteCollision
lbl_0800f298: .4byte 0x000001e3
lbl_0800f29c:
    mov r1, sl
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_0800f2b8
    adds r0, r6, #0
    bl SpriteUtilSpriteTakeDamageFromSamusContact
    cmp r0, #0
    bne lbl_0800f2b8
    movs r0, #1
    adds r1, r6, #0
    movs r2, #1
    bl SpriteUtilTakeDamageFromSprite
lbl_0800f2b8:
    movs r0, #0xf
    ldr r2, [sp, #0x3c]
    strb r0, [r2]
    b lbl_0800f2fa
lbl_0800f2c0:
    bl SpriteUtilGetFinalCompletionPercentage
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
    bl SpriteUtilTakeDamageFromSprite
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
    ldr r1, lbl_0800f354 @ =gIgnoreSamusAndSpriteCollision
    movs r0, #1
lbl_0800f2fe:
    strb r0, [r1]
lbl_0800f300:
    ldr r0, lbl_0800f354 @ =gIgnoreSamusAndSpriteCollision
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800f314

    thumb_func_start sub_0800f308
sub_0800f308: @ 0x0800f308
    adds r6, #0x38
    ldr r0, lbl_0800f358 @ =gSpritesetSpritesID
    cmp r6, r0
    bhs lbl_0800f314
    bl lbl_0800e82e
lbl_0800f314:
    ldr r6, lbl_0800f35c @ =gSpriteData
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
lbl_0800f354: .4byte gIgnoreSamusAndSpriteCollision
lbl_0800f358: .4byte gSpritesetSpritesID
lbl_0800f35c: .4byte gSpriteData

    thumb_func_start SpriteUtilCheckVerticalCollisionAtPosition
SpriteUtilCheckVerticalCollisionAtPosition: @ 0x0800f360
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    adds r3, r0, #0
    movs r2, #0x80
    lsls r2, r2, #0x11
    ands r2, r3
    cmp r2, #0
    beq lbl_0800f38c
    ldr r1, lbl_0800f388 @ =gPreviousVerticalCollisionCheck
    movs r0, #0x11
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_0800f392
    .align 2, 0
lbl_0800f388: .4byte gPreviousVerticalCollisionCheck
lbl_0800f38c:
    ldr r0, lbl_0800f3a8 @ =gPreviousVerticalCollisionCheck
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
lbl_0800f3a8: .4byte gPreviousVerticalCollisionCheck
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

    thumb_func_start SpriteUtilCheckVerticalCollisionAtPositionSlopes
SpriteUtilCheckVerticalCollisionAtPositionSlopes: @ 0x0800f47c
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r0, r5, #0
    adds r1, r4, #0
    bl ClipdataProcess
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
    ldr r0, lbl_0800f57c @ =gPreviousVerticalCollisionCheck
    strb r3, [r0]
    b lbl_0800f586
    .align 2, 0
lbl_0800f578: .4byte 0x0000ffc0
lbl_0800f57c: .4byte gPreviousVerticalCollisionCheck
lbl_0800f580:
    ldr r1, lbl_0800f590 @ =gPreviousVerticalCollisionCheck
    movs r0, #0
    strb r0, [r1]
lbl_0800f586:
    adds r0, r2, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800f590: .4byte gPreviousVerticalCollisionCheck

    thumb_func_start unk_f594
unk_f594: @ 0x0800f594
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r7, lbl_0800f600 @ =gCurrentSprite
    ldrh r5, [r7, #2]
    mov sb, r5
    ldrh r4, [r7, #4]
    mov sl, r4
    subs r0, r5, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r4, #0
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    ldr r6, lbl_0800f604 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r6]
    movs r0, #0xf
    mov r8, r0
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f5ee
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilCheckVerticalCollisionAtPosition
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
    bl SpriteUtilCheckVerticalCollisionAtPosition
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
lbl_0800f600: .4byte gCurrentSprite
lbl_0800f604: .4byte gPreviousVerticalCollisionCheck

    thumb_func_start sub_0800f608
sub_0800f608: @ 0x0800f608
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r6, lbl_0800f680 @ =gCurrentSprite
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
    bl SpriteUtilCheckVerticalCollisionAtPosition
    adds r2, r0, #0
    ldr r7, lbl_0800f684 @ =gPreviousVerticalCollisionCheck
    ldrb r1, [r7]
    movs r0, #0xf
    mov r8, r0
    ands r0, r1
    cmp r0, #1
    bhi lbl_0800f66a
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilCheckVerticalCollisionAtPosition
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
    bl SpriteUtilCheckVerticalCollisionAtPosition
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
lbl_0800f680: .4byte gCurrentSprite
lbl_0800f684: .4byte gPreviousVerticalCollisionCheck

    thumb_func_start SpriteUtilCheckCollisionAtPosition
SpriteUtilCheckCollisionAtPosition: @ 0x0800f688
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcess
    adds r3, r0, #0
    movs r2, #0x80
    lsls r2, r2, #0x11
    ands r2, r3
    cmp r2, #0
    beq lbl_0800f6b0
    ldr r1, lbl_0800f6ac @ =gPreviousCollisionCheck
    movs r0, #0x11
    strb r0, [r1]
    adds r2, r1, #0
    b lbl_0800f6b6
    .align 2, 0
lbl_0800f6ac: .4byte gPreviousCollisionCheck
lbl_0800f6b0:
    ldr r0, lbl_0800f6cc @ =gPreviousCollisionCheck
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
lbl_0800f6cc: .4byte gPreviousCollisionCheck
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

    thumb_func_start SpriteUtilGetCollisionAtPosition
SpriteUtilGetCollisionAtPosition: @ 0x0800f720
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcess
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
    ldr r4, lbl_0800f7c0 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
    adds r1, r0, #0
    ldr r0, lbl_0800f7c4 @ =gPreviousVerticalCollisionCheck
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
lbl_0800f7c0: .4byte gCurrentSprite
lbl_0800f7c4: .4byte gPreviousVerticalCollisionCheck
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

    thumb_func_start SpriteUtilChooseRandomXFlip
SpriteUtilChooseRandomXFlip: @ 0x0800f80c
    push {lr}
    ldr r0, lbl_0800f824 @ =gSpriteRng
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f830
    ldr r2, lbl_0800f828 @ =gCurrentSprite
    ldrh r1, [r2]
    ldr r0, lbl_0800f82c @ =0x0000ffbf
    ands r0, r1
    b lbl_0800f838
    .align 2, 0
lbl_0800f824: .4byte gSpriteRng
lbl_0800f828: .4byte gCurrentSprite
lbl_0800f82c: .4byte 0x0000ffbf
lbl_0800f830:
    ldr r2, lbl_0800f840 @ =gCurrentSprite
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
lbl_0800f838:
    strh r0, [r2]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800f840: .4byte gCurrentSprite

    thumb_func_start SpriteUtilChooseRandomXDirection
SpriteUtilChooseRandomXDirection: @ 0x0800f844
    push {lr}
    ldr r0, lbl_0800f85c @ =gSpriteRng
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f868
    ldr r2, lbl_0800f860 @ =gCurrentSprite
    ldrh r1, [r2]
    ldr r0, lbl_0800f864 @ =0x0000fdff
    ands r0, r1
    b lbl_0800f874
    .align 2, 0
lbl_0800f85c: .4byte gSpriteRng
lbl_0800f860: .4byte gCurrentSprite
lbl_0800f864: .4byte 0x0000fdff
lbl_0800f868:
    ldr r2, lbl_0800f87c @ =gCurrentSprite
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
lbl_0800f87c: .4byte gCurrentSprite

    thumb_func_start SpriteUtilChooseRandomXDirectionRoomSlot
SpriteUtilChooseRandomXDirectionRoomSlot: @ 0x0800f880
    push {lr}
    ldr r2, lbl_0800f898 @ =gCurrentSprite
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
lbl_0800f898: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilMakeSpriteFaceSamusXFlip
SpriteUtilMakeSpriteFaceSamusXFlip: @ 0x0800f8b0
    push {lr}
    ldr r2, lbl_0800f8c8 @ =gCurrentSprite
    ldr r1, lbl_0800f8cc @ =gSamusData
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f8d4
    ldrh r1, [r2]
    ldr r0, lbl_0800f8d0 @ =0x0000ffbf
    ands r0, r1
    b lbl_0800f8da
    .align 2, 0
lbl_0800f8c8: .4byte gCurrentSprite
lbl_0800f8cc: .4byte gSamusData
lbl_0800f8d0: .4byte 0x0000ffbf
lbl_0800f8d4:
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
lbl_0800f8da:
    strh r0, [r2]
    pop {r0}
    bx r0

    thumb_func_start SpriteUtilMakeSpriteFaceSamusDirection
SpriteUtilMakeSpriteFaceSamusDirection: @ 0x0800f8e0
    push {lr}
    ldr r2, lbl_0800f8f8 @ =gCurrentSprite
    ldr r1, lbl_0800f8fc @ =gSamusData
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f904
    ldrh r1, [r2]
    ldr r0, lbl_0800f900 @ =0x0000fdff
    ands r0, r1
    b lbl_0800f90e
    .align 2, 0
lbl_0800f8f8: .4byte gCurrentSprite
lbl_0800f8fc: .4byte gSamusData
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

    thumb_func_start SpriteUtilMakeSpriteFaceAwawFromSamusXFlip
SpriteUtilMakeSpriteFaceAwawFromSamusXFlip: @ 0x0800f914
    push {lr}
    ldr r2, lbl_0800f92c @ =gCurrentSprite
    ldr r1, lbl_0800f930 @ =gSamusData
    ldrh r0, [r2, #4]
    ldrh r1, [r1, #0x12]
    cmp r0, r1
    bls lbl_0800f934
    ldrh r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    b lbl_0800f93a
    .align 2, 0
lbl_0800f92c: .4byte gCurrentSprite
lbl_0800f930: .4byte gSamusData
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

    thumb_func_start SpriteUtilMakeSpriteFaceAwawFromSamusDirection
SpriteUtilMakeSpriteFaceAwawFromSamusDirection: @ 0x0800f944
    push {lr}
    ldr r2, lbl_0800f960 @ =gCurrentSprite
    ldr r1, lbl_0800f964 @ =gSamusData
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
lbl_0800f960: .4byte gCurrentSprite
lbl_0800f964: .4byte gSamusData
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

    thumb_func_start unk_f978
unk_f978: @ 0x0800f978
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    ldr r4, lbl_0800f9a0 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800f9a8
    ldr r0, lbl_0800f9a4 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0800f9bc
    b lbl_0800f9b0
    .align 2, 0
lbl_0800f9a0: .4byte gCurrentSprite
lbl_0800f9a4: .4byte gPreviousCollisionCheck
lbl_0800f9a8:
    ldr r0, lbl_0800f9d0 @ =gPreviousCollisionCheck
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
    ldr r2, lbl_0800f9d4 @ =gCurrentSprite
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
lbl_0800f9d0: .4byte gPreviousCollisionCheck
lbl_0800f9d4: .4byte gCurrentSprite
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
    ldr r4, lbl_0800fa14 @ =gCurrentSprite
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800fa22
    ldr r0, lbl_0800fa18 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0800fa1c
    lsls r0, r5, #1
    movs r1, #3
    bl __divsi3
    lsls r0, r0, #0x10
    b lbl_0800fa4c
    .align 2, 0
lbl_0800fa14: .4byte gCurrentSprite
lbl_0800fa18: .4byte gPreviousCollisionCheck
lbl_0800fa1c:
    cmp r0, #3
    bne lbl_0800fa4e
    b lbl_0800fa40
lbl_0800fa22:
    ldr r0, lbl_0800fa38 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0800fa3c
    lsls r0, r5, #1
    movs r1, #3
    bl __divsi3
    lsls r0, r0, #0x10
    b lbl_0800fa4c
    .align 2, 0
lbl_0800fa38: .4byte gPreviousCollisionCheck
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
    ldr r2, lbl_0800fa68 @ =gCurrentSprite
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800fa6c
    ldrh r0, [r2, #4]
    adds r0, r0, r5
    b lbl_0800fa70
    .align 2, 0
lbl_0800fa68: .4byte gCurrentSprite
lbl_0800fa6c:
    ldrh r0, [r2, #4]
    subs r0, r0, r5
lbl_0800fa70:
    strh r0, [r2, #4]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start SpriteUtilMakeSpriteFaceSamusRotation
SpriteUtilMakeSpriteFaceSamusRotation: @ 0x0800fa78
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

    thumb_func_start SpriteUtilCheckEndCurrentSpriteAnim
SpriteUtilCheckEndCurrentSpriteAnim: @ 0x0800fbc8
    push {lr}
    ldr r0, lbl_0800fbf4 @ =gCurrentSprite
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
lbl_0800fbf4: .4byte gCurrentSprite
lbl_0800fbf8:
    movs r0, #0
lbl_0800fbfa:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckNearEndCurrentSpriteAnim
SpriteUtilCheckNearEndCurrentSpriteAnim: @ 0x0800fc00
    push {lr}
    ldr r0, lbl_0800fc30 @ =gCurrentSprite
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
lbl_0800fc30: .4byte gCurrentSprite
lbl_0800fc34:
    movs r0, #0
lbl_0800fc36:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckEndSpriteAnim
SpriteUtilCheckEndSpriteAnim: @ 0x0800fc3c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r3, lbl_0800fc78 @ =gSpriteData
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
lbl_0800fc78: .4byte gSpriteData
lbl_0800fc7c:
    movs r0, #0
lbl_0800fc7e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SpriteUtilCheckNearEndSpriteAnim
SpriteUtilCheckNearEndSpriteAnim: @ 0x0800fc84
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r3, lbl_0800fcc4 @ =gSpriteData
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
lbl_0800fcc4: .4byte gSpriteData
lbl_0800fcc8:
    movs r0, #0
lbl_0800fcca:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start SpriteUtilCheckEndSubSprite1Anim
SpriteUtilCheckEndSubSprite1Anim: @ 0x0800fcd0
    push {lr}
    ldr r0, lbl_0800fcfc @ =gSubSpriteData1
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
lbl_0800fcfc: .4byte gSubSpriteData1
lbl_0800fd00:
    movs r0, #0
lbl_0800fd02:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckNearEndSubSprite1Anim
SpriteUtilCheckNearEndSubSprite1Anim: @ 0x0800fd08
    push {lr}
    ldr r0, lbl_0800fd38 @ =gSubSpriteData1
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
lbl_0800fd38: .4byte gSubSpriteData1
lbl_0800fd3c:
    movs r0, #0
lbl_0800fd3e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckEndSubSprite2Anim
SpriteUtilCheckEndSubSprite2Anim: @ 0x0800fd44
    push {lr}
    ldr r0, lbl_0800fd70 @ =gSubSpriteData2
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
lbl_0800fd70: .4byte gSubSpriteData2
lbl_0800fd74:
    movs r0, #0
lbl_0800fd76:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckEndSubSpriteAnim
SpriteUtilCheckEndSubSpriteAnim: @ 0x0800fd7c
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

    thumb_func_start SpriteUtilCheckNearEndSubSpriteAnim
SpriteUtilCheckNearEndSubSpriteAnim: @ 0x0800fdac
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

    thumb_func_start SpriteUtilCheckSamusNearSpriteLeftRight
SpriteUtilCheckSamusNearSpriteLeftRight: @ 0x0800fde0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    movs r6, #0
    ldr r2, lbl_0800fe14 @ =gSamusData
    ldr r0, lbl_0800fe18 @ =gSamusPhysics
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
    ldr r0, lbl_0800fe1c @ =gCurrentSprite
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    cmp r1, r3
    bls lbl_0800fe20
    subs r0, r1, r3
    b lbl_0800fe22
    .align 2, 0
lbl_0800fe14: .4byte gSamusData
lbl_0800fe18: .4byte gSamusPhysics
lbl_0800fe1c: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilCheckSamusNearSpriteAboveBelow
SpriteUtilCheckSamusNearSpriteAboveBelow: @ 0x0800fe48
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    movs r5, #0
    ldr r2, lbl_0800fe7c @ =gSamusData
    ldr r0, lbl_0800fe80 @ =gSamusPhysics
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
    ldr r0, lbl_0800fe84 @ =gCurrentSprite
    ldrh r2, [r0, #2]
    ldrh r0, [r0, #4]
    cmp r0, r1
    bls lbl_0800fe88
    subs r0, r0, r1
    b lbl_0800fe8a
    .align 2, 0
lbl_0800fe7c: .4byte gSamusData
lbl_0800fe80: .4byte gSamusPhysics
lbl_0800fe84: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilCheckSamusNearSpriteFrontBehind
SpriteUtilCheckSamusNearSpriteFrontBehind: @ 0x0800feb0
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
    ldr r2, lbl_0800fef8 @ =gSamusData
    ldr r0, lbl_0800fefc @ =gSamusPhysics
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
    ldr r0, lbl_0800ff00 @ =gCurrentSprite
    ldrh r2, [r0, #2]
    ldrh r4, [r0, #4]
    adds r1, r0, #0
    cmp r2, r3
    bls lbl_0800ff04
    subs r0, r2, r3
    b lbl_0800ff06
    .align 2, 0
lbl_0800fef8: .4byte gSamusData
lbl_0800fefc: .4byte gSamusPhysics
lbl_0800ff00: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilSamusStandingOnSprite
SpriteUtilSamusStandingOnSprite: @ 0x0800ff60
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
    ldr r5, lbl_0800ff94 @ =gSamusData
    ldrb r0, [r5, #1]
    cmp r0, #1
    beq lbl_0800ff8a
    cmp r0, #2
    bne lbl_0800ff86
    movs r0, #0xfd
    bl SamusSetPose
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
lbl_0800ff94: .4byte gSamusData
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
    ldr r0, lbl_0800ffc8 @ =gSamusDataCopy
    ldr r1, lbl_0800ffcc @ =gSamusData
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
lbl_0800ffc8: .4byte gSamusDataCopy
lbl_0800ffcc: .4byte gSamusData
lbl_0800ffd0:
    strb r0, [r1]
    ldr r1, lbl_0800ffe4 @ =gSamusData
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
lbl_0800ffe4: .4byte gSamusData

    thumb_func_start SpriteUtilUpdateFreezeTimer
SpriteUtilUpdateFreezeTimer: @ 0x0800ffe8
    push {r4, lr}
    ldr r0, lbl_08010034 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r4, #1
    adds r0, r4, #0
    ands r0, r1
    ldr r3, lbl_08010038 @ =gCurrentSprite
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
lbl_08010034: .4byte gFrameCounter8Bit
lbl_08010038: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilUnfreezeAnimEasy
SpriteUtilUnfreezeAnimEasy: @ 0x0801004c
    push {lr}
    ldr r2, lbl_08010090 @ =gCurrentSprite
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
lbl_08010090: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilMetroidUnfreezeAnim
SpriteUtilMetroidUnfreezeAnim: @ 0x080100a4
    push {lr}
    ldr r2, lbl_080100e8 @ =gCurrentSprite
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
lbl_080100e8: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent: @ 0x080100fc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    ldr r0, lbl_08010190 @ =gCurrentSprite
    adds r1, r0, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08010186
    movs r5, #0
    ldr r0, lbl_08010194 @ =gSpriteData
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
lbl_08010190: .4byte gCurrentSprite
lbl_08010194: .4byte gSpriteData

    thumb_func_start SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent
SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent: @ 0x08010198
    push {r4, r5, lr}
    ldr r1, lbl_080101ec @ =gCurrentSprite
    adds r0, r1, #0
    adds r0, #0x30
    ldrb r5, [r0]
    adds r3, r5, #0
    cmp r3, #0
    beq lbl_080101e4
    subs r0, #0xd
    ldrb r1, [r0]
    ldr r2, lbl_080101f0 @ =gSpriteData
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
lbl_080101ec: .4byte gCurrentSprite
lbl_080101f0: .4byte gSpriteData

    thumb_func_start SpriteUtilUnfreezeSecondarySprites
SpriteUtilUnfreezeSecondarySprites: @ 0x080101f4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r3, #0
    ldr r7, lbl_08010258 @ =gSpriteData
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
lbl_08010258: .4byte gSpriteData

    thumb_func_start SpriteUtilRefillEnergy
SpriteUtilRefillEnergy: @ 0x0801025c
    push {lr}
    ldr r0, lbl_08010278 @ =gEquipment
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
lbl_08010278: .4byte gEquipment
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

    thumb_func_start SpriteUtilRefillMissiles
SpriteUtilRefillMissiles: @ 0x080102a0
    push {lr}
    ldr r0, lbl_080102bc @ =gEquipment
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
lbl_080102bc: .4byte gEquipment
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

    thumb_func_start SpriteUtilRefillSuperMissiles
SpriteUtilRefillSuperMissiles: @ 0x080102ea
    push {lr}
    ldr r0, lbl_08010300 @ =gEquipment
    ldrb r1, [r0, #0xa]
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
lbl_08010300: .4byte gEquipment
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

    thumb_func_start SpriteUtilRefillPowerBombs
SpriteUtilRefillPowerBombs: @ 0x08010328
    push {lr}
    ldr r0, lbl_08010344 @ =gEquipment
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
lbl_08010344: .4byte gEquipment
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

    thumb_func_start SpriteUtilCheckCrouchingOrMorphed
SpriteUtilCheckCrouchingOrMorphed: @ 0x0801036c
    push {lr}
    ldr r0, lbl_08010384 @ =gSamusData
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
lbl_08010384: .4byte gSamusData
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

    thumb_func_start SpriteUtilCheckCrouchingOrCrawling
SpriteUtilCheckCrouchingOrCrawling: @ 0x0801047c
    push {lr}
    ldr r0, lbl_08010494 @ =gSamusData
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
lbl_08010494: .4byte gSamusData
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

    thumb_func_start SpriteUtilCheckMorphed
SpriteUtilCheckMorphed: @ 0x080104a8
    push {lr}
    ldr r0, lbl_080104c0 @ =gSamusData
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
lbl_080104c0: .4byte gSamusData
lbl_080104c4:
    movs r0, #0
lbl_080104c6:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckStopSpritesPose
SpriteUtilCheckStopSpritesPose: @ 0x080104cc
    push {lr}
    ldr r0, lbl_080104e8 @ =gPreventMovementTimer
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_080104e2
    ldr r0, lbl_080104ec @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1e
    bgt lbl_080104f0
    cmp r0, #0x1d
    blt lbl_080104f0
lbl_080104e2:
    movs r0, #1
    b lbl_080104f2
    .align 2, 0
lbl_080104e8: .4byte gPreventMovementTimer
lbl_080104ec: .4byte gSamusData
lbl_080104f0:
    movs r0, #0
lbl_080104f2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilSpriteTakeDamageFromSamusContact
SpriteUtilSpriteTakeDamageFromSamusContact: @ 0x080104f8
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r3, r1, #0
    movs r5, #0
    ldr r0, lbl_0801053c @ =gEquipment
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
lbl_0801053c: .4byte gEquipment
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
    ldr r0, lbl_08010568 @ =gSamusWeaponInfo
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
lbl_08010568: .4byte gSamusWeaponInfo
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
    ldr r1, lbl_08010600 @ =gSamusWeaponInfo
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
    bl ProjectileDealDamage
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
lbl_08010600: .4byte gSamusWeaponInfo
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

    thumb_func_start SpriteUtilCheckPullingSelfUp
SpriteUtilCheckPullingSelfUp: @ 0x080106a8
    push {lr}
    ldr r0, lbl_080106bc @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1c
    bgt lbl_080106c0
    cmp r0, #0x1a
    blt lbl_080106c0
    movs r0, #1
    b lbl_080106c2
    .align 2, 0
lbl_080106bc: .4byte gSamusData
lbl_080106c0:
    movs r0, #0
lbl_080106c2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCheckOnZipline
SpriteUtilCheckOnZipline: @ 0x080106c8
    push {lr}
    ldr r0, lbl_080106dc @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x2b
    bgt lbl_080106e0
    cmp r0, #0x28
    blt lbl_080106e0
    movs r0, #1
    b lbl_080106e2
    .align 2, 0
lbl_080106dc: .4byte gSamusData
lbl_080106e0:
    movs r0, #0
lbl_080106e2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilCountPrimarySprites
SpriteUtilCountPrimarySprites: @ 0x080106e8
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #0
    ldr r2, lbl_08010734 @ =gSpriteData
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
lbl_08010734: .4byte gSpriteData

    thumb_func_start SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot
SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot: @ 0x08010738
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    movs r4, #0
    ldr r0, lbl_08010790 @ =gCurrentSprite
    adds r0, #0x23
    ldrb r5, [r0]
    ldr r2, lbl_08010794 @ =gSpriteData
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
lbl_08010790: .4byte gCurrentSprite
lbl_08010794: .4byte gSpriteData

    thumb_func_start SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot
SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot: @ 0x08010798
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    movs r4, #0
    ldr r0, lbl_080107f0 @ =gCurrentSprite
    adds r0, #0x23
    ldrb r5, [r0]
    ldr r2, lbl_080107f4 @ =gSpriteData
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
lbl_080107f0: .4byte gCurrentSprite
lbl_080107f4: .4byte gSpriteData

    thumb_func_start SpriteUtilFindPrimary
SpriteUtilFindPrimary: @ 0x080107f8
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #0
    ldr r2, lbl_08010830 @ =gSpriteData
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
lbl_08010830: .4byte gSpriteData
lbl_08010834:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r3, #0x38
    adds r2, #0x38
    ldr r0, lbl_0801084c @ =gSpritesetSpritesID
    cmp r2, r0
    blo lbl_08010810
lbl_08010844:
    movs r0, #0xff
lbl_08010846:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0801084c: .4byte gSpritesetSpritesID

    thumb_func_start SpriteUtilFindSecondaryWithRoomSlot
SpriteUtilFindSecondaryWithRoomSlot: @ 0x08010850
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r4, #0
    ldr r3, lbl_08010890 @ =gSpriteData
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
lbl_08010890: .4byte gSpriteData
lbl_08010894:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r2, #0x38
    adds r3, #0x38
    ldr r0, lbl_080108ac @ =gSpritesetSpritesID
    cmp r3, r0
    blo lbl_0801086c
lbl_080108a4:
    movs r0, #0xff
lbl_080108a6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080108ac: .4byte gSpritesetSpritesID

    thumb_func_start SpriteUtilCheckHasDrops
SpriteUtilCheckHasDrops: @ 0x080108b0
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_080108e8 @ =gCurrentSprite
    adds r0, #0x23
    ldrb r4, [r0]
    movs r7, #0x1f
    ldr r2, lbl_080108ec @ =gSpriteData
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
lbl_080108e8: .4byte gCurrentSprite
lbl_080108ec: .4byte gSpriteData
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

    thumb_func_start SpriteUtilCountDrops
SpriteUtilCountDrops: @ 0x08010900
    push {r4, r5, r6, lr}
    movs r3, #0
    movs r6, #0x1f
    ldr r2, lbl_08010940 @ =gSpriteData
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
lbl_08010940: .4byte gSpriteData

    thumb_func_start SpriteUtilMoveSpriteTowardsSamus
SpriteUtilMoveSpriteTowardsSamus: @ 0x08010944
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
    ldr r1, lbl_080109b8 @ =gCurrentSprite
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
lbl_080109b8: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilRidleyFireballMove
SpriteUtilRidleyFireballMove: @ 0x08010b98
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
    ldr r0, lbl_08010be0 @ =gCurrentSprite
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
lbl_08010be0: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilUpdateStunTimer
SpriteUtilUpdateStunTimer: @ 0x08010cf0
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

    thumb_func_start SpriteUtilRandomSpriteDebris
SpriteUtilRandomSpriteDebris: @ 0x08010d68
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
    ldr r0, lbl_08010dac @ =gFrameCounter8Bit
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
    bl SpriteDebrisInit
    b lbl_08010e88
    .align 2, 0
lbl_08010dac: .4byte gFrameCounter8Bit
lbl_08010db0:
    adds r2, r5, #0
    adds r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #1
    bl SpriteDebrisInit
    b lbl_08010e88
lbl_08010dc2:
    ldr r0, lbl_08010df0 @ =gFrameCounter8Bit
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
    bl SpriteDebrisInit
    adds r2, r5, #0
    adds r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #4
    bl SpriteDebrisInit
    b lbl_08010e88
    .align 2, 0
lbl_08010df0: .4byte gFrameCounter8Bit
lbl_08010df4:
    adds r2, r5, #0
    subs r2, #8
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #1
    bl SpriteDebrisInit
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #3
    adds r2, r5, #0
    bl SpriteDebrisInit
    b lbl_08010e88
lbl_08010e14:
    ldr r0, lbl_08010e54 @ =gFrameCounter8Bit
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
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x10
    adds r3, r6, #0
    adds r3, #8
    adds r0, r7, #0
    movs r1, #3
    bl SpriteDebrisInit
    adds r2, r5, #0
    adds r2, #8
    adds r0, r7, #0
    movs r1, #4
    adds r3, r4, #0
    bl SpriteDebrisInit
    b lbl_08010e88
    .align 2, 0
lbl_08010e54: .4byte gFrameCounter8Bit
lbl_08010e58:
    adds r2, r5, #0
    subs r2, #0x10
    adds r4, r6, #0
    adds r4, #8
    adds r0, r7, #0
    movs r1, #2
    adds r3, r4, #0
    bl SpriteDebrisInit
    adds r2, r5, #0
    adds r2, #8
    adds r0, r7, #0
    movs r1, #3
    adds r3, r4, #0
    bl SpriteDebrisInit
    adds r2, r5, #0
    adds r2, #0x10
    adds r3, r6, #0
    subs r3, #8
    adds r0, r7, #0
    movs r1, #4
    bl SpriteDebrisInit
lbl_08010e88:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpriteUtilGetAmmoDrop
SpriteUtilGetAmmoDrop: @ 0x08010e90
    push {lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r0, lbl_08010eb8 @ =gEquipment
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
lbl_08010eb8: .4byte gEquipment
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

    thumb_func_start SpriteUtilDetermineEnemyDrop
SpriteUtilDetermineEnemyDrop: @ 0x08010eec
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    movs r0, #0
    mov sb, r0
    ldr r0, lbl_08010f3c @ =gEquipment
    ldrh r1, [r0, #6]
    mov r8, r0
    ldrh r2, [r0]
    cmp r1, r2
    bne lbl_08010f0a
    movs r0, #1
    mov sb, r0
lbl_08010f0a:
    ldr r0, lbl_08010f40 @ =gSpriteRng
    ldrb r4, [r0]
    lsls r4, r4, #8
    ldr r1, lbl_08010f44 @ =gFrameCounter8Bit
    ldr r0, lbl_08010f48 @ =gFrameCounter16Bit
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
    ldr r0, lbl_08010f4c @ =gCurrentSprite
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
lbl_08010f3c: .4byte gEquipment
lbl_08010f40: .4byte gSpriteRng
lbl_08010f44: .4byte gFrameCounter8Bit
lbl_08010f48: .4byte gFrameCounter16Bit
lbl_08010f4c: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilSpriteDeath
SpriteUtilSpriteDeath: @ 0x08011084
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
    ldr r0, lbl_080110b8 @ =gCurrentSprite
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
lbl_080110b8: .4byte gCurrentSprite
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
    bl ParticleSet
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl SpriteUtilRandomSpriteDebris
    ldr r0, lbl_080110e4 @ =0x00000131
    bl SoundPlay
    b lbl_080111d8
    .align 2, 0
lbl_080110e4: .4byte 0x00000131
lbl_080110e8:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x26
    bl ParticleSet
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl SpriteUtilRandomSpriteDebris
    ldr r0, lbl_08011108 @ =0x00000133
    bl SoundPlay
    b lbl_080111d8
    .align 2, 0
lbl_08011108: .4byte 0x00000133
lbl_0801110c:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x23
    bl ParticleSet
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl SpriteUtilRandomSpriteDebris
    movs r0, #0x98
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080111d8
lbl_0801112c:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x25
    bl ParticleSet
    movs r0, #0
    movs r1, #3
    adds r2, r5, #0
    adds r3, r6, #0
    bl SpriteUtilRandomSpriteDebris
    movs r0, #0x99
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080111d8
lbl_0801114c:
    cmp r2, #0x1f
    bne lbl_08011168
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x1f
    bl ParticleSet
    cmp r7, #0
    beq lbl_080111d8
    movs r0, #0x96
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080111d8
lbl_08011168:
    cmp r2, #0x20
    bne lbl_08011188
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x20
    bl ParticleSet
    cmp r7, #0
    beq lbl_080111d8
    ldr r0, lbl_08011184 @ =0x0000012d
    bl SoundPlay
    b lbl_080111d8
    .align 2, 0
lbl_08011184: .4byte 0x0000012d
lbl_08011188:
    cmp r2, #0x21
    bne lbl_080111a4
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x21
    bl ParticleSet
    cmp r7, #0
    beq lbl_080111d8
    movs r0, #0x97
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080111d8
lbl_080111a4:
    cmp r2, #0x22
    bne lbl_080111c4
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x22
    bl ParticleSet
    cmp r7, #0
    beq lbl_080111d8
    ldr r0, lbl_080111c0 @ =0x0000012f
    bl SoundPlay
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
    bl ParticleSet
lbl_080111d8:
    bl SpriteUtilDetermineEnemyDrop
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
    ldr r0, lbl_0801120c @ =gCurrentSprite
    ldrb r1, [r0, #0x1e]
    adds r0, #0x23
    ldrb r3, [r0]
    str r5, [sp]
    str r6, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    adds r0, r2, #0
    movs r2, #0
    bl SpriteSpawnDropFollowers
    b lbl_0801126e
    .align 2, 0
lbl_0801120c: .4byte gCurrentSprite
lbl_08011210:
    ldr r2, lbl_08011260 @ =gCurrentSprite
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
lbl_08011260: .4byte gCurrentSprite
lbl_08011264:
    mov r1, r8
    cmp r1, #0
    bne lbl_0801126e
    ldr r0, lbl_0801127c @ =gCurrentSprite
    strh r1, [r0]
lbl_0801126e:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801127c: .4byte gCurrentSprite

    thumb_func_start SpriteUtilIsSpriteStunned
SpriteUtilIsSpriteStunned: @ 0x08011280
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_080112c0 @ =gDifficulty
    ldrb r0, [r0]
    movs r3, #0xe
    cmp r0, #1
    bhi lbl_08011290
    movs r3, #9
lbl_08011290:
    ldr r2, lbl_080112c4 @ =gCurrentSprite
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
lbl_080112c0: .4byte gDifficulty
lbl_080112c4: .4byte gCurrentSprite

    thumb_func_start SpriteUtilIsShouldFall
SpriteUtilIsShouldFall: @ 0x080112c8
    push {lr}
    ldr r0, lbl_080112ec @ =gCurrentSprite
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080112f8
    ldr r0, lbl_080112f0 @ =gScreenShakeY
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080112e6
    ldr r0, lbl_080112f4 @ =gScreenShakeX
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080112f8
lbl_080112e6:
    movs r0, #1
    b lbl_080112fa
    .align 2, 0
lbl_080112ec: .4byte gCurrentSprite
lbl_080112f0: .4byte gScreenShakeY
lbl_080112f4: .4byte gScreenShakeX
lbl_080112f8:
    movs r0, #0
lbl_080112fa:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start SpriteUtilUpdateSubSprite1Timer
SpriteUtilUpdateSubSprite1Timer: @ 0x08011300
    push {r4, lr}
    ldr r4, lbl_0801132c @ =gSubSpriteData1
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
lbl_0801132c: .4byte gSubSpriteData1

    thumb_func_start SpriteUtilUpdateSubSprite1Anim
SpriteUtilUpdateSubSprite1Anim: @ 0x08011330
    push {lr}
    ldr r2, lbl_08011368 @ =gSubSpriteData1
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
lbl_08011368: .4byte gSubSpriteData1

    thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position: @ 0x0801136c
    push {r4, lr}
    ldr r3, lbl_080113a8 @ =gSubSpriteData1
    ldrh r0, [r3, #4]
    ldr r1, [r3]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r4, [r0]
    ldr r2, lbl_080113ac @ =gCurrentSprite
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
lbl_080113a8: .4byte gSubSpriteData1
lbl_080113ac: .4byte gCurrentSprite

    thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM
SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM: @ 0x080113b0
    push {r4, lr}
    ldr r4, lbl_080113f0 @ =gSubSpriteData1
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_080113f4 @ =gCurrentSprite
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
lbl_080113f0: .4byte gSubSpriteData1
lbl_080113f4: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilUpdateSubSprite2Anim
SpriteUtilUpdateSubSprite2Anim: @ 0x08011410
    push {lr}
    ldr r2, lbl_08011448 @ =gSubSpriteData2
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
lbl_08011448: .4byte gSubSpriteData2

    thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM
SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM: @ 0x0801144c
    push {r4, lr}
    ldr r4, lbl_0801148c @ =gSubSpriteData2
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_08011490 @ =gCurrentSprite
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
lbl_0801148c: .4byte gSubSpriteData2
lbl_08011490: .4byte gCurrentSprite
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

    thumb_func_start SpriteUtilUpdateSubSpriteAnim
SpriteUtilUpdateSubSpriteAnim: @ 0x080114ac
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

    thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition
SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition: @ 0x080114e4
    push {r4, lr}
    ldrh r1, [r0, #4]
    ldr r2, [r0]
    lsls r1, r1, #3
    adds r1, r1, r2
    ldr r4, [r1]
    ldr r3, lbl_0801151c @ =gCurrentSprite
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
lbl_0801151c: .4byte gCurrentSprite

    thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam
SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam: @ 0x08011520
    push {r4, lr}
    adds r2, r0, #0
    ldrh r0, [r2, #4]
    ldr r1, [r2]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r4, [r0]
    ldr r3, lbl_08011560 @ =gCurrentSprite
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
lbl_08011560: .4byte gCurrentSprite
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

    thumb_func_start SpriteCheckCollidingWithSamusDrawing
SpriteCheckCollidingWithSamusDrawing: @ 0x0801157c
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #0x10
    ldr r4, lbl_08011604 @ =gCurrentSprite
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
    ldr r4, lbl_08011608 @ =gSamusData
    ldrh r5, [r4, #0x14]
    mov r8, r5
    ldrh r4, [r4, #0x12]
    mov sb, r4
    ldr r5, lbl_0801160c @ =gSamusPhysics
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
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    bne lbl_08011610
    movs r0, #0
    b lbl_08011612
    .align 2, 0
lbl_08011604: .4byte gCurrentSprite
lbl_08011608: .4byte gSamusData
lbl_0801160c: .4byte gSamusPhysics
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

    thumb_func_start SpriteUtilSetSplashEffect
SpriteUtilSetSplashEffect: @ 0x08011620
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
    ldr r0, lbl_08011648 @ =gCurrentAffectingClipdata
    ldrh r0, [r0, #2]
    cmp r0, #3
    bgt lbl_0801164c
    cmp r0, #2
    bge lbl_08011678
    cmp r0, #1
    beq lbl_08011652
    b lbl_080116c4
    .align 2, 0
lbl_08011648: .4byte gCurrentAffectingClipdata
lbl_0801164c:
    cmp r0, #4
    beq lbl_0801169e
    b lbl_080116c4
lbl_08011652:
    cmp r2, #1
    bne lbl_08011660
    adds r0, r3, #0
    movs r2, #0
    bl ParticleSet
    b lbl_080116c4
lbl_08011660:
    cmp r2, #2
    bne lbl_0801166e
    adds r0, r3, #0
    movs r2, #1
    bl ParticleSet
    b lbl_080116c4
lbl_0801166e:
    adds r0, r3, #0
    movs r2, #2
    bl ParticleSet
    b lbl_080116c4
lbl_08011678:
    cmp r2, #1
    bne lbl_08011686
    adds r0, r3, #0
    movs r2, #3
    bl ParticleSet
    b lbl_080116c4
lbl_08011686:
    cmp r2, #2
    bne lbl_08011694
    adds r0, r3, #0
    movs r2, #4
    bl ParticleSet
    b lbl_080116c4
lbl_08011694:
    adds r0, r3, #0
    movs r2, #5
    bl ParticleSet
    b lbl_080116c4
lbl_0801169e:
    cmp r2, #1
    bne lbl_080116ac
    adds r0, r3, #0
    movs r2, #6
    bl ParticleSet
    b lbl_080116c4
lbl_080116ac:
    cmp r4, #2
    bne lbl_080116ba
    adds r0, r3, #0
    movs r2, #7
    bl ParticleSet
    b lbl_080116c4
lbl_080116ba:
    adds r0, r6, #0
    adds r1, r5, #0
    movs r2, #8
    bl ParticleSet
lbl_080116c4:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SpriteUtilCheckOutOfRoomEffect
SpriteUtilCheckOutOfRoomEffect: @ 0x080116cc
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r5, r3, #0x18
    ldr r1, lbl_0801170c @ =gEffectYPosition
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
    bl SpriteUtilGetCollisionAtPosition
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r5, #0
    bl SpriteUtilSetSplashEffect
lbl_08011706:
    movs r0, #1
    b lbl_08011712
    .align 2, 0
lbl_0801170c: .4byte gEffectYPosition
lbl_08011710:
    movs r0, #0
lbl_08011712:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SpriteUtilCheckInRoomEffect
SpriteUtilCheckInRoomEffect: @ 0x08011718
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r5, r3, #0x18
    ldr r1, lbl_08011750 @ =gEffectYPosition
    ldrh r1, [r1]
    cmp r0, r1
    bhs lbl_08011754
    cmp r4, r1
    blo lbl_08011754
    cmp r5, #0
    beq lbl_0801174c
    adds r0, r4, #0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    adds r0, r4, #0
    adds r1, r6, #0
    adds r2, r5, #0
    bl SpriteUtilSetSplashEffect
lbl_0801174c:
    movs r0, #1
    b lbl_08011756
    .align 2, 0
lbl_08011750: .4byte gEffectYPosition
lbl_08011754:
    movs r0, #0
lbl_08011756:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start SpriteUtilGetFinalCompletionPercentage
SpriteUtilGetFinalCompletionPercentage: @ 0x0801175c
    push {r4, r5, lr}
    bl ChozodiaEscapeGetItemCountAndEndingNumber
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
