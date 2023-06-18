    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start kraid_mouth_determine_spike_pos
kraid_mouth_determine_spike_pos: @ 0x080183d8
    push {r4, lr}
    ldr r4, lbl_08018434 @ =gSubSpriteData1
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_08018438 @ =gCurrentSprite
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0]
    ldr r1, lbl_0801843c @ =0x0875f564
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2, #0x18]
    ldr r0, [r0]
    cmp r1, r0
    beq lbl_0801840a
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
lbl_0801840a:
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #2]
    ldrh r1, [r4, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #4]
    ldrh r4, [r4, #8]
    adds r0, r0, r4
    strh r0, [r2, #4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018434: .4byte gSubSpriteData1
lbl_08018438: .4byte gCurrentSprite
lbl_0801843c: .4byte 0x0875f564

    thumb_func_start KraidCheckProjectilesCollidingWithBelly
KraidCheckProjectilesCollidingWithBelly: @ 0x08018440
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r2, lbl_08018500 @ =gCurrentSprite
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
    ldr r6, lbl_08018504 @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r6, r1
    cmp r6, r0
    blo lbl_08018484
    b lbl_080185d8
lbl_08018484:
    ldrb r1, [r6]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08018492
    b lbl_080185ce
lbl_08018492:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0801849c
    b lbl_080185ce
lbl_0801849c:
    ldrb r0, [r6, #0x11]
    cmp r0, #1
    bhi lbl_080184a4
    b lbl_080185ce
lbl_080184a4:
    ldrb r0, [r6, #0xf]
    cmp r0, #0xd
    bls lbl_080184ac
    b lbl_080185ce
lbl_080184ac:
    ldrh r0, [r6, #0xa]
    cmp r0, r8
    bhi lbl_080184b4
    b lbl_080185ce
lbl_080184b4:
    cmp r0, r7
    blo lbl_080184ba
    b lbl_080185ce
lbl_080184ba:
    ldrh r0, [r6, #8]
    cmp r0, sl
    bhi lbl_080184c2
    b lbl_080185ce
lbl_080184c2:
    cmp r0, sb
    blo lbl_080184c8
    b lbl_080185ce
lbl_080184c8:
    movs r0, #0
    strb r0, [r6]
    ldrh r4, [r6, #8]
    ldrh r5, [r6, #0xa]
    ldr r0, lbl_08018508 @ =gSpriteRng
    ldrb r1, [r0]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0801850c
    adds r2, r4, #0
    adds r2, #0x10
    adds r3, r5, #0
    subs r3, #8
    movs r0, #0
    movs r1, #0x12
    bl SpriteDebrisInit
    adds r2, r4, #0
    subs r2, #0x2a
    adds r3, r5, #0
    adds r3, #0x14
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    b lbl_0801852a
    .align 2, 0
lbl_08018500: .4byte gCurrentSprite
lbl_08018504: .4byte gProjectileData
lbl_08018508: .4byte gSpriteRng
lbl_0801850c:
    adds r3, r5, #0
    adds r3, #0xc
    movs r0, #0
    movs r1, #0x12
    adds r2, r4, #0
    bl SpriteDebrisInit
    adds r2, r4, #0
    subs r2, #0x18
    adds r3, r5, #0
    subs r3, #0x1e
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
lbl_0801852a:
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x1f
    bl ParticleSet
    ldrb r0, [r6, #0xf]
    cmp r0, #0xd
    bhi lbl_080185ce
    lsls r0, r0, #2
    ldr r1, lbl_0801854c @ =lbl_08018550
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801854c: .4byte lbl_08018550
lbl_08018550: @ jump table
    .4byte lbl_08018588 @ case 0
    .4byte lbl_08018594 @ case 1
    .4byte lbl_080185a0 @ case 2
    .4byte lbl_080185ac @ case 3
    .4byte lbl_080185ce @ case 4
    .4byte lbl_080185ce @ case 5
    .4byte lbl_08018588 @ case 6
    .4byte lbl_08018594 @ case 7
    .4byte lbl_080185a0 @ case 8
    .4byte lbl_080185ac @ case 9
    .4byte lbl_080185ce @ case 10
    .4byte lbl_080185ce @ case 11
    .4byte lbl_080185b8 @ case 12
    .4byte lbl_080185c4 @ case 13
lbl_08018588:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2a
    bl ParticleSet
    b lbl_080185ce
lbl_08018594:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2b
    bl ParticleSet
    b lbl_080185ce
lbl_080185a0:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2c
    bl ParticleSet
    b lbl_080185ce
lbl_080185ac:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2d
    bl ParticleSet
    b lbl_080185ce
lbl_080185b8:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x30
    bl ParticleSet
    b lbl_080185ce
lbl_080185c4:
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x31
    bl ParticleSet
lbl_080185ce:
    adds r6, #0x1c
    ldr r0, lbl_080185e8 @ =gArmCannonY
    cmp r6, r0
    bhs lbl_080185d8
    b lbl_08018484
lbl_080185d8:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080185e8: .4byte gArmCannonY

    thumb_func_start KraidOpenCloseRoutineAndProjectileCollision
KraidOpenCloseRoutineAndProjectileCollision: @ 0x080185ec
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r5, lbl_08018620 @ =gCurrentSprite
    ldr r2, lbl_08018624 @ =gSubSpriteData1
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    beq lbl_08018606
    subs r0, #1
    strb r0, [r2, #0xe]
lbl_08018606:
    ldr r1, [r5, #0x18]
    ldr r6, lbl_08018628 @ =0x082cab14
    cmp r1, r6
    bne lbl_08018650
    movs r0, #1
    str r0, [sp]
    ldrb r4, [r2, #0xe]
    cmp r4, #0
    beq lbl_08018630
    ldr r0, lbl_0801862c @ =0x082cab9c
    str r0, [r5, #0x18]
    b lbl_080186d6
    .align 2, 0
lbl_08018620: .4byte gCurrentSprite
lbl_08018624: .4byte gSubSpriteData1
lbl_08018628: .4byte 0x082cab14
lbl_0801862c: .4byte 0x082cab9c
lbl_08018630:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0801863a
    b lbl_0801872c
lbl_0801863a:
    ldr r0, lbl_08018648 @ =gSpriteRng
    ldrb r0, [r0]
    cmp r0, #4
    bhi lbl_0801872c
    ldr r0, lbl_0801864c @ =0x082cab44
    str r0, [r5, #0x18]
    b lbl_0801867a
    .align 2, 0
lbl_08018648: .4byte gSpriteRng
lbl_0801864c: .4byte 0x082cab44
lbl_08018650:
    ldr r7, lbl_08018668 @ =0x082cab44
    cmp r1, r7
    bne lbl_08018680
    movs r1, #1
    str r1, [sp]
    ldrb r4, [r2, #0xe]
    cmp r4, #0
    beq lbl_08018670
    ldr r0, lbl_0801866c @ =0x082cab9c
    str r0, [r5, #0x18]
    b lbl_080186d6
    .align 2, 0
lbl_08018668: .4byte 0x082cab44
lbl_0801866c: .4byte 0x082cab9c
lbl_08018670:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801872c
    str r6, [r5, #0x18]
lbl_0801867a:
    strb r4, [r5, #0x1c]
    strh r4, [r5, #0x16]
    b lbl_0801872c
lbl_08018680:
    ldr r4, lbl_080186ac @ =0x082cab9c
    cmp r1, r4
    bne lbl_080186ba
    ldrh r0, [r5, #0x16]
    cmp r0, #5
    bls lbl_080186b4
    movs r2, #0
    str r2, [sp]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801872c
    ldr r0, lbl_080186b0 @ =0x082cabe4
    str r0, [r5, #0x18]
    mov r3, sp
    ldrb r3, [r3]
    strb r3, [r5, #0x1c]
    mov r4, sp
    ldrh r4, [r4]
    strh r4, [r5, #0x16]
    b lbl_0801872c
    .align 2, 0
lbl_080186ac: .4byte 0x082cab9c
lbl_080186b0: .4byte 0x082cabe4
lbl_080186b4:
    movs r0, #1
    str r0, [sp]
    b lbl_08018740
lbl_080186ba:
    ldr r3, lbl_080186e8 @ =0x082cac34
    cmp r1, r3
    bne lbl_08018712
    ldrh r0, [r5, #0x16]
    movs r1, #0
    str r1, [sp]
    cmp r0, #1
    bls lbl_0801872c
    movs r3, #1
    str r3, [sp]
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    beq lbl_080186ec
    str r4, [r5, #0x18]
lbl_080186d6:
    movs r0, #0
    strb r0, [r5, #0x1c]
    strh r0, [r5, #0x16]
    movs r0, #0xe7
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0801872c
    .align 2, 0
lbl_080186e8: .4byte 0x082cac34
lbl_080186ec:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801872c
    ldr r0, lbl_08018704 @ =gSpriteRng
    ldrb r1, [r0]
    ldr r0, [sp]
    ands r0, r1
    cmp r0, #0
    beq lbl_08018708
    str r6, [r5, #0x18]
    b lbl_0801870a
    .align 2, 0
lbl_08018704: .4byte gSpriteRng
lbl_08018708:
    str r7, [r5, #0x18]
lbl_0801870a:
    movs r0, #0
    strb r0, [r5, #0x1c]
    strh r0, [r5, #0x16]
    b lbl_0801872c
lbl_08018712:
    ldr r0, lbl_0801873c @ =0x082cac1c
    movs r4, #0
    str r4, [sp]
    cmp r1, r0
    beq lbl_0801872c
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    bne lbl_0801872c
    str r3, [r5, #0x18]
    strb r4, [r5, #0x1c]
    mov r1, sp
    ldrh r1, [r1]
    strh r1, [r5, #0x16]
lbl_0801872c:
    ldr r2, [sp]
    cmp r2, #0
    bne lbl_08018740
    movs r3, #0x4c
    mov ip, r3
    movs r4, #0x10
    str r4, [sp, #8]
    b lbl_08018748
    .align 2, 0
lbl_0801873c: .4byte 0x082cac1c
lbl_08018740:
    movs r0, #0x44
    mov ip, r0
    movs r1, #0x14
    str r1, [sp, #8]
lbl_08018748:
    ldrh r4, [r5, #2]
    ldrh r1, [r5, #4]
    ldrh r0, [r5, #0xa]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    ldrh r0, [r5, #0xc]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrh r0, [r5, #0xe]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrh r0, [r5, #0x10]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldr r7, lbl_08018800 @ =gProjectileData
    movs r2, #0xe0
    lsls r2, r2, #1
    adds r0, r7, r2
    cmp r7, r0
    blo lbl_0801877e
    b lbl_08018a48
lbl_0801877e:
    adds r6, r5, #0
    adds r6, #0x2b
    ldr r0, lbl_08018804 @ =0x040000d4
    mov sb, r0
lbl_08018786:
    ldrb r2, [r7]
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    bne lbl_08018792
    b lbl_08018a3e
lbl_08018792:
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    bne lbl_0801879c
    b lbl_08018a3e
lbl_0801879c:
    ldrb r0, [r7, #0x11]
    cmp r0, #1
    bhi lbl_080187a4
    b lbl_08018a3e
lbl_080187a4:
    ldrh r0, [r7, #0xa]
    cmp r0, r3
    bhi lbl_080187ac
    b lbl_08018a3e
lbl_080187ac:
    cmp r0, r1
    blo lbl_080187b2
    b lbl_08018a3e
lbl_080187b2:
    ldrh r0, [r7, #8]
    cmp r0, sl
    bhi lbl_080187ba
    b lbl_08018a3e
lbl_080187ba:
    cmp r0, r8
    blo lbl_080187c0
    b lbl_08018a3e
lbl_080187c0:
    adds r1, r0, #0
    mov sl, r1
    ldrh r3, [r7, #0xa]
    str r3, [sp, #4]
    movs r3, #0
    mov r1, ip
    subs r0, r4, r1
    cmp sl, r0
    bgt lbl_080187d4
    b lbl_080189f8
lbl_080187d4:
    ldr r1, [sp, #8]
    adds r0, r4, r1
    cmp sl, r0
    blt lbl_080187de
    b lbl_080189f8
lbl_080187de:
    ldrb r0, [r7, #0x10]
    cmp r0, #0
    beq lbl_080187e6
    b lbl_080189f8
lbl_080187e6:
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_080187f0
    b lbl_080189f8
lbl_080187f0:
    ldrb r0, [r7, #0xf]
    cmp r0, #0xc
    bne lbl_08018808
    movs r3, #1
    movs r4, #0x14
    movs r2, #0x30
    mov r8, r2
    b lbl_080188b2
    .align 2, 0
lbl_08018800: .4byte gProjectileData
lbl_08018804: .4byte 0x040000d4
lbl_08018808:
    cmp r0, #0xd
    bne lbl_08018816
    movs r3, #1
    movs r4, #0x64
    movs r0, #0x31
    mov r8, r0
    b lbl_080188b2
lbl_08018816:
    cmp r0, #6
    bne lbl_08018824
    movs r3, #1
    movs r4, #8
    movs r1, #0x2a
    mov r8, r1
    b lbl_080188b2
lbl_08018824:
    cmp r0, #7
    bne lbl_08018832
    movs r3, #1
    movs r4, #0xc
    movs r2, #0x2b
    mov r8, r2
    b lbl_080188b2
lbl_08018832:
    cmp r0, #8
    bne lbl_08018854
    movs r3, #1
    ldr r0, lbl_08018850 @ =gEquipment
    ldrb r1, [r0, #0xd]
    adds r0, r3, #0
    ands r0, r1
    movs r4, #0xc
    cmp r0, #0
    beq lbl_08018848
    movs r4, #0x10
lbl_08018848:
    movs r0, #0x2c
    mov r8, r0
    b lbl_080188b2
    .align 2, 0
lbl_08018850: .4byte gEquipment
lbl_08018854:
    cmp r0, #9
    bne lbl_0801889c
    movs r3, #1
    ldr r0, lbl_08018878 @ =gEquipment
    ldrb r1, [r0, #0xd]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08018884
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801887c
    movs r4, #0x14
    movs r1, #0x32
    mov r8, r1
    b lbl_080188b2
    .align 2, 0
lbl_08018878: .4byte gEquipment
lbl_0801887c:
    movs r4, #0x10
    movs r2, #0x2d
    mov r8, r2
    b lbl_080188b2
lbl_08018884:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08018894
    movs r4, #0x10
    movs r0, #0x32
    mov r8, r0
    b lbl_080188b2
lbl_08018894:
    movs r4, #0xc
    movs r1, #0x2d
    mov r8, r1
    b lbl_080188b2
lbl_0801889c:
    movs r4, #0
    strb r3, [r7]
    adds r2, r5, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #2
    bls lbl_080188b0
    b lbl_08018a32
lbl_080188b0:
    b lbl_08018a28
lbl_080188b2:
    cmp r3, #0
    bne lbl_080188b8
    b lbl_08018a48
lbl_080188b8:
    ldr r2, [sp]
    cmp r2, #0
    bne lbl_080188d8
    ldrb r0, [r6]
    movs r1, #0x80
    ands r1, r0
    movs r0, #0x11
    orrs r1, r0
    strb r1, [r6]
    ldr r0, lbl_080188d4 @ =0x000001cf
    bl SoundPlay
    b lbl_080188ec
    .align 2, 0
lbl_080188d4: .4byte 0x000001cf
lbl_080188d8:
    ldrb r1, [r6]
    movs r0, #0x80
    ands r0, r1
    movs r3, #2
    orrs r0, r3
    strb r0, [r6]
    ldr r1, lbl_08018924 @ =gSubSpriteData1
    movs r0, #0xb4
    strb r0, [r1, #0xe]
    movs r4, #0
lbl_080188ec:
    ldrh r0, [r5, #0x14]
    cmp r0, r4
    bls lbl_080189b0
    subs r0, r0, r4
    strh r0, [r5, #0x14]
    ldr r1, lbl_08018928 @ =0x082b0d68
    ldr r4, lbl_0801892c @ =0x000007ce
    adds r2, r1, r4
    ldrh r1, [r2]
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    lsrs r1, r1, #2
    cmp r6, r1
    bhs lbl_0801893c
    adds r1, r5, #0
    adds r1, #0x34
    movs r0, #3
    strb r0, [r1]
    ldr r0, lbl_08018930 @ =0x082c8eb4
    mov r1, sb
    str r0, [r1]
    ldr r0, lbl_08018934 @ =0x05000140
    str r0, [r1, #4]
    ldr r0, lbl_08018938 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_08018966
    .align 2, 0
lbl_08018924: .4byte gSubSpriteData1
lbl_08018928: .4byte 0x082b0d68
lbl_0801892c: .4byte 0x000007ce
lbl_08018930: .4byte 0x082c8eb4
lbl_08018934: .4byte 0x05000140
lbl_08018938: .4byte 0x80000010
lbl_0801893c:
    ldrh r4, [r2]
    adds r0, r4, #0
    movs r1, #3
    bl __udivsi3
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r6, r0
    bhs lbl_08018978
    adds r0, r5, #0
    adds r0, #0x34
    movs r2, #2
    strb r2, [r0]
    ldr r0, lbl_0801896c @ =0x082c8e94
    mov r3, sb
    str r0, [r3]
    ldr r0, lbl_08018970 @ =0x05000140
    str r0, [r3, #4]
    ldr r0, lbl_08018974 @ =0x80000010
    str r0, [r3, #8]
    ldr r0, [r3, #8]
lbl_08018966:
    adds r3, r5, #0
    adds r3, #0x32
    b lbl_080189d6
    .align 2, 0
lbl_0801896c: .4byte 0x082c8e94
lbl_08018970: .4byte 0x05000140
lbl_08018974: .4byte 0x80000010
lbl_08018978:
    ldrh r2, [r5, #0x14]
    lsrs r1, r4, #2
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r3, r5, #0
    adds r3, #0x32
    cmp r2, r0
    bge lbl_080189d6
    adds r1, r5, #0
    adds r1, #0x34
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_080189a4 @ =0x082c8e74
    mov r4, sb
    str r0, [r4]
    ldr r0, lbl_080189a8 @ =0x05000140
    str r0, [r4, #4]
    ldr r0, lbl_080189ac @ =0x80000010
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    b lbl_080189d6
    .align 2, 0
lbl_080189a4: .4byte 0x082c8e74
lbl_080189a8: .4byte 0x05000140
lbl_080189ac: .4byte 0x80000010
lbl_080189b0:
    movs r2, #0
    movs r0, #0
    strh r0, [r5, #0x14]
    adds r3, r5, #0
    adds r3, #0x32
    ldrb r0, [r3]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r3]
    adds r0, r5, #0
    adds r0, #0x30
    strb r2, [r0]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
    adds r1, #2
    movs r0, #1
    strb r0, [r1]
lbl_080189d6:
    ldrb r1, [r3]
    movs r0, #2
    orrs r0, r1
    strb r0, [r3]
    ldr r2, lbl_080189f4 @ =gSubSpriteData1
    ldrh r0, [r5, #0x14]
    movs r1, #0
    strh r0, [r2, #0xa]
    strb r1, [r7]
    mov r0, sl
    ldr r1, [sp, #4]
    mov r2, r8
    bl ParticleSet
    b lbl_08018a48
    .align 2, 0
lbl_080189f4: .4byte gSubSpriteData1
lbl_080189f8:
    ldrb r0, [r7, #0xf]
    cmp r0, #0xc
    bne lbl_08018a08
    adds r0, r7, #0
    movs r1, #0xc
    bl kraid_start_tumbling_missile
    b lbl_08018a1a
lbl_08018a08:
    cmp r0, #0xd
    bne lbl_08018a16
    adds r0, r7, #0
    movs r1, #0xd
    bl kraid_start_tumbling_missile
    b lbl_08018a1a
lbl_08018a16:
    movs r0, #0
    strb r0, [r7]
lbl_08018a1a:
    adds r2, r5, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #2
    bhi lbl_08018a32
lbl_08018a28:
    movs r0, #0x80
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strb r0, [r2]
lbl_08018a32:
    mov r0, sl
    ldr r1, [sp, #4]
    movs r2, #0x2f
    bl ParticleSet
    b lbl_08018a48
lbl_08018a3e:
    adds r7, #0x1c
    ldr r0, lbl_08018a58 @ =gArmCannonY
    cmp r7, r0
    bhs lbl_08018a48
    b lbl_08018786
lbl_08018a48:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018a58: .4byte gArmCannonY

    thumb_func_start KraidRandomSpriteDebrisOnCeiling
KraidRandomSpriteDebrisOnCeiling: @ 0x08018a5c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    ldr r1, lbl_08018a84 @ =gSubSpriteData1
    ldrh r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_08018a90
    ldr r1, lbl_08018a88 @ =gSamusData
    ldr r2, lbl_08018a8c @ =0xfffffe40
    adds r0, r2, #0
    ldrh r2, [r1, #0x14]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r4, [r1, #0x12]
    b lbl_08018aa2
    .align 2, 0
lbl_08018a84: .4byte gSubSpriteData1
lbl_08018a88: .4byte gSamusData
lbl_08018a8c: .4byte 0xfffffe40
lbl_08018a90:
    ldr r0, lbl_08018ae8 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r0, #0x3c
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r0, [r1, #8]
    adds r0, #0xc0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
lbl_08018aa2:
    ldr r0, lbl_08018aec @ =gSpriteRng
    ldrb r7, [r0]
    ldr r0, lbl_08018af0 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #7
    mov r8, r0
    mov r2, r8
    ands r2, r1
    mov r8, r2
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08018afc
    adds r2, r5, r7
    lsls r3, r7, #4
    ldr r0, lbl_08018af4 @ =0xfffffed4
    adds r3, r3, r0
    adds r3, r4, r3
    movs r0, #0
    movs r1, #5
    bl SpriteDebrisInit
    mov r1, r8
    lsls r3, r1, #2
    ldr r2, lbl_08018af8 @ =0xfffffd44
    adds r3, r3, r2
    adds r3, r4, r3
    movs r0, #0
    movs r1, #5
    adds r2, r5, #0
    bl SpriteDebrisInit
    mov r0, r8
    lsls r6, r0, #4
    b lbl_08018b22
    .align 2, 0
lbl_08018ae8: .4byte gBG1YPosition
lbl_08018aec: .4byte gSpriteRng
lbl_08018af0: .4byte gFrameCounter8Bit
lbl_08018af4: .4byte 0xfffffed4
lbl_08018af8: .4byte 0xfffffd44
lbl_08018afc:
    subs r2, r5, r7
    lsls r3, r7, #5
    subs r3, #0xa0
    subs r3, r4, r3
    movs r0, #0
    movs r1, #7
    bl SpriteDebrisInit
    mov r1, r8
    lsls r6, r1, #4
    movs r2, #0xc8
    lsls r2, r2, #1
    adds r3, r6, r2
    subs r3, r4, r3
    movs r0, #0
    movs r1, #7
    adds r2, r5, #0
    bl SpriteDebrisInit
lbl_08018b22:
    cmp r7, #7
    bls lbl_08018b4c
    adds r3, r6, #0
    subs r3, #0xfa
    adds r3, r4, r3
    movs r0, #0
    movs r1, #8
    adds r2, r5, #0
    bl SpriteDebrisInit
    ldr r0, lbl_08018b48 @ =0xfffffed4
    adds r3, r6, r0
    subs r3, r4, r3
    movs r0, #0
    movs r1, #6
    adds r2, r5, #0
    bl SpriteDebrisInit
    b lbl_08018b6c
    .align 2, 0
lbl_08018b48: .4byte 0xfffffed4
lbl_08018b4c:
    adds r3, r6, #0
    subs r3, #0xc8
    subs r3, r4, r3
    movs r0, #0
    movs r1, #5
    adds r2, r5, #0
    bl SpriteDebrisInit
    ldr r1, lbl_08018b90 @ =0xfffffea2
    adds r3, r6, r1
    adds r3, r4, r3
    movs r0, #0
    movs r1, #5
    adds r2, r5, #0
    bl SpriteDebrisInit
lbl_08018b6c:
    movs r0, #3
    mov r2, sb
    ands r0, r2
    cmp r0, #0
    bne lbl_08018bea
    movs r0, #1
    ands r0, r7
    cmp r0, #0
    beq lbl_08018b94
    adds r3, r6, #0
    subs r3, #0xa0
    adds r3, r4, r3
    movs r0, #0
    movs r1, #6
    adds r2, r5, #0
    bl SpriteDebrisInit
    b lbl_08018ba4
    .align 2, 0
lbl_08018b90: .4byte 0xfffffea2
lbl_08018b94:
    adds r3, r6, #0
    subs r3, #0xa0
    subs r3, r4, r3
    movs r0, #0
    movs r1, #8
    adds r2, r5, #0
    bl SpriteDebrisInit
lbl_08018ba4:
    cmp r7, #7
    bls lbl_08018bca
    mov r0, r8
    lsls r3, r0, #5
    subs r3, r4, r3
    movs r0, #0
    movs r1, #7
    adds r2, r5, #0
    bl SpriteDebrisInit
    adds r3, r6, #0
    subs r3, #0x40
    subs r3, r4, r3
    movs r0, #0
    movs r1, #8
    adds r2, r5, #0
    bl SpriteDebrisInit
    b lbl_08018bea
lbl_08018bca:
    ldr r1, lbl_08018bf8 @ =0xfffffef2
    adds r3, r6, r1
    adds r3, r4, r3
    movs r0, #0
    movs r1, #5
    adds r2, r5, #0
    bl SpriteDebrisInit
    mov r2, r8
    lsls r3, r2, #2
    adds r3, r4, r3
    movs r0, #0
    movs r1, #6
    adds r2, r5, #0
    bl SpriteDebrisInit
lbl_08018bea:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018bf8: .4byte 0xfffffef2

    thumb_func_start sub_08018bfc
sub_08018bfc: @ 0x08018bfc
    ldr r1, lbl_08018c10 @ =gCurrentSprite
    ldr r0, lbl_08018c14 @ =0x0000ffa0
    strh r0, [r1, #0xa]
    movs r0, #0x20
    strh r0, [r1, #0xc]
    movs r0, #0xe0
    strh r0, [r1, #0xe]
    adds r0, #0x28
    strh r0, [r1, #0x10]
    bx lr
    .align 2, 0
lbl_08018c10: .4byte gCurrentSprite
lbl_08018c14: .4byte 0x0000ffa0

    thumb_func_start KraidPartUpdateRightArmIdlingHitbox
KraidPartUpdateRightArmIdlingHitbox: @ 0x08018c18
    push {lr}
    ldr r0, lbl_08018c38 @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_08018c26
    b lbl_08018d2c
lbl_08018c26:
    ldrh r0, [r2, #0x16]
    cmp r0, #9
    bls lbl_08018c2e
    b lbl_08018d2c
lbl_08018c2e:
    lsls r0, r0, #2
    ldr r1, lbl_08018c3c @ =lbl_08018c40
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08018c38: .4byte gCurrentSprite
lbl_08018c3c: .4byte lbl_08018c40
lbl_08018c40: @ jump table
    .4byte lbl_08018c68 @ case 0
    .4byte lbl_08018c7c @ case 1
    .4byte lbl_08018c90 @ case 2
    .4byte lbl_08018ca4 @ case 3
    .4byte lbl_08018cb8 @ case 4
    .4byte lbl_08018ccc @ case 5
    .4byte lbl_08018ce0 @ case 6
    .4byte lbl_08018cf4 @ case 7
    .4byte lbl_08018d08 @ case 8
    .4byte lbl_08018d1c @ case 9
lbl_08018c68:
    ldr r0, lbl_08018c78 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x28
    b lbl_08018d2a
    .align 2, 0
lbl_08018c78: .4byte 0x0000ffa0
lbl_08018c7c:
    ldr r0, lbl_08018c8c @ =0x0000ffb8
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018c8c: .4byte 0x0000ffb8
lbl_08018c90:
    ldr r0, lbl_08018ca0 @ =0x0000ffd0
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018ca0: .4byte 0x0000ffd0
lbl_08018ca4:
    ldr r0, lbl_08018cb4 @ =0x0000ffe8
    strh r0, [r2, #0xa]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018cb4: .4byte 0x0000ffe8
lbl_08018cb8:
    ldr r0, lbl_08018cc8 @ =0x0000ffe8
    strh r0, [r2, #0xa]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018cc8: .4byte 0x0000ffe8
lbl_08018ccc:
    ldr r0, lbl_08018cdc @ =0x0000ffe8
    strh r0, [r2, #0xa]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    adds r0, #0xc0
    strh r0, [r2, #0xe]
    adds r0, #0x5c
    b lbl_08018d2a
    .align 2, 0
lbl_08018cdc: .4byte 0x0000ffe8
lbl_08018ce0:
    ldr r0, lbl_08018cf0 @ =0x0000ffd8
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018cf0: .4byte 0x0000ffd8
lbl_08018cf4:
    ldr r0, lbl_08018d04 @ =0x0000ffc0
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x7c
    b lbl_08018d2a
    .align 2, 0
lbl_08018d04: .4byte 0x0000ffc0
lbl_08018d08:
    ldr r0, lbl_08018d18 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x30
    b lbl_08018d2a
    .align 2, 0
lbl_08018d18: .4byte 0x0000ffa0
lbl_08018d1c:
    ldr r0, lbl_08018d30 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    movs r0, #0x20
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x40
lbl_08018d2a:
    strh r0, [r2, #0x10]
lbl_08018d2c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018d30: .4byte 0x0000ffa0

    thumb_func_start KraidPartUpdateRightArmAttackingHitbox
KraidPartUpdateRightArmAttackingHitbox: @ 0x08018d34
    push {lr}
    ldr r0, lbl_08018d54 @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_08018d42
    b lbl_08018e84
lbl_08018d42:
    ldrh r0, [r2, #0x16]
    cmp r0, #0xb
    bls lbl_08018d4a
    b lbl_08018e84
lbl_08018d4a:
    lsls r0, r0, #2
    ldr r1, lbl_08018d58 @ =lbl_08018d5c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08018d54: .4byte gCurrentSprite
lbl_08018d58: .4byte lbl_08018d5c
lbl_08018d5c: @ jump table
    .4byte lbl_08018d8c @ case 0
    .4byte lbl_08018da8 @ case 1
    .4byte lbl_08018dbc @ case 2
    .4byte lbl_08018dd0 @ case 3
    .4byte lbl_08018de2 @ case 4
    .4byte lbl_08018e04 @ case 5
    .4byte lbl_08018e1c @ case 6
    .4byte lbl_08018e34 @ case 7
    .4byte lbl_08018e44 @ case 8
    .4byte lbl_08018e54 @ case 9
    .4byte lbl_08018e64 @ case 10
    .4byte lbl_08018e74 @ case 11
lbl_08018d8c:
    movs r1, #0
    ldr r0, lbl_08018da4 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    strh r1, [r2, #0xc]
    movs r0, #0xd0
    strh r0, [r2, #0xe]
    adds r0, #0x50
    strh r0, [r2, #0x10]
    adds r0, #0xa2
    bl SoundPlay
    b lbl_08018e84
    .align 2, 0
lbl_08018da4: .4byte 0x0000ffa0
lbl_08018da8:
    ldr r0, lbl_08018db8 @ =0x0000ff80
    strh r0, [r2, #0xa]
    adds r0, #0x40
    strh r0, [r2, #0xc]
    movs r0, #0xc0
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_08018e82
    .align 2, 0
lbl_08018db8: .4byte 0x0000ff80
lbl_08018dbc:
    ldr r0, lbl_08018dcc @ =0x0000ff40
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0x98
    strh r0, [r2, #0xe]
    movs r0, #0xc8
    b lbl_08018e82
    .align 2, 0
lbl_08018dcc: .4byte 0x0000ff40
lbl_08018dd0:
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r2, #0xa]
    adds r0, #0xa0
    strh r0, [r2, #0xc]
    movs r0, #0x80
    strh r0, [r2, #0xe]
    movs r0, #0xb8
    b lbl_08018e82
lbl_08018de2:
    ldr r0, lbl_08018dfc @ =0x0000fec0
    strh r0, [r2, #0xa]
    adds r0, #0xa0
    strh r0, [r2, #0xc]
    movs r0, #0x70
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    strh r0, [r2, #0x10]
    ldr r0, lbl_08018e00 @ =0x000001c3
    bl SoundPlay
    b lbl_08018e84
    .align 2, 0
lbl_08018dfc: .4byte 0x0000fec0
lbl_08018e00: .4byte 0x000001c3
lbl_08018e04:
    ldr r0, lbl_08018e18 @ =0x0000fec0
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r2, #0xe]
    adds r0, #0x28
    b lbl_08018e82
    .align 2, 0
lbl_08018e18: .4byte 0x0000fec0
lbl_08018e1c:
    movs r1, #0
    ldr r0, lbl_08018e30 @ =0x0000fec0
    strh r0, [r2, #0xa]
    strh r1, [r2, #0xc]
    movs r0, #0x90
    lsls r0, r0, #1
    strh r0, [r2, #0xe]
    adds r0, #0x98
    b lbl_08018e82
    .align 2, 0
lbl_08018e30: .4byte 0x0000fec0
lbl_08018e34:
    movs r0, #8
    strh r0, [r2, #0xa]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    adds r0, #0xc0
    strh r0, [r2, #0xe]
    adds r0, #0xa0
    b lbl_08018e82
lbl_08018e44:
    movs r0, #0x60
    strh r0, [r2, #0xa]
    movs r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0xa0
    b lbl_08018e82
lbl_08018e54:
    movs r0, #0x68
    strh r0, [r2, #0xa]
    movs r0, #0xa0
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_08018e82
lbl_08018e64:
    movs r0, #0x20
    strh r0, [r2, #0xa]
    movs r0, #0xa0
    strh r0, [r2, #0xc]
    movs r0, #0xe0
    strh r0, [r2, #0xe]
    adds r0, #0x40
    b lbl_08018e82
lbl_08018e74:
    movs r0, #0
    strh r0, [r2, #0xa]
    movs r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0xe8
    strh r0, [r2, #0xe]
    adds r0, #0x30
lbl_08018e82:
    strh r0, [r2, #0x10]
lbl_08018e84:
    pop {r0}
    bx r0

    thumb_func_start sub_08018e88
sub_08018e88: @ 0x08018e88
    push {lr}
    ldr r1, lbl_08018ea8 @ =gCurrentSprite
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_08018ea2
    ldr r0, lbl_08018eac @ =0x0000ff60
    strh r0, [r1, #0xa]
    adds r0, #0x80
    strh r0, [r1, #0xc]
    movs r0, #8
    strh r0, [r1, #0xe]
    movs r0, #0x88
    strh r0, [r1, #0x10]
lbl_08018ea2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018ea8: .4byte gCurrentSprite
lbl_08018eac: .4byte 0x0000ff60

    thumb_func_start KraidMouthUpdateLeftArmIdlingHitbox
KraidMouthUpdateLeftArmIdlingHitbox: @ 0x08018eb0
    push {lr}
    ldr r0, lbl_08018ed0 @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_08018ebe
    b lbl_08018fc4
lbl_08018ebe:
    ldrh r0, [r2, #0x16]
    cmp r0, #9
    bls lbl_08018ec6
    b lbl_08018fc4
lbl_08018ec6:
    lsls r0, r0, #2
    ldr r1, lbl_08018ed4 @ =lbl_08018ed8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08018ed0: .4byte gCurrentSprite
lbl_08018ed4: .4byte lbl_08018ed8
lbl_08018ed8: @ jump table
    .4byte lbl_08018f00 @ case 0
    .4byte lbl_08018f14 @ case 1
    .4byte lbl_08018f28 @ case 2
    .4byte lbl_08018f3c @ case 3
    .4byte lbl_08018f50 @ case 4
    .4byte lbl_08018f64 @ case 5
    .4byte lbl_08018f78 @ case 6
    .4byte lbl_08018f8c @ case 7
    .4byte lbl_08018fa0 @ case 8
    .4byte lbl_08018fb4 @ case 9
lbl_08018f00:
    ldr r0, lbl_08018f10 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #8
    strh r0, [r2, #0xe]
    movs r0, #0x88
    b lbl_08018fc2
    .align 2, 0
lbl_08018f10: .4byte 0x0000ff60
lbl_08018f14:
    ldr r0, lbl_08018f24 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #8
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f24: .4byte 0x0000ff60
lbl_08018f28:
    ldr r0, lbl_08018f38 @ =0x0000ff5c
    strh r0, [r2, #0xa]
    adds r0, #0x84
    strh r0, [r2, #0xc]
    movs r0, #8
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f38: .4byte 0x0000ff5c
lbl_08018f3c:
    ldr r0, lbl_08018f4c @ =0x0000ff58
    strh r0, [r2, #0xa]
    adds r0, #0x88
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f4c: .4byte 0x0000ff58
lbl_08018f50:
    ldr r0, lbl_08018f60 @ =0x0000ff58
    strh r0, [r2, #0xa]
    adds r0, #0x88
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    b lbl_08018fc2
    .align 2, 0
lbl_08018f60: .4byte 0x0000ff58
lbl_08018f64:
    ldr r0, lbl_08018f74 @ =0x0000ff58
    strh r0, [r2, #0xa]
    adds r0, #0x88
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f74: .4byte 0x0000ff58
lbl_08018f78:
    ldr r0, lbl_08018f88 @ =0x0000ff58
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f88: .4byte 0x0000ff58
lbl_08018f8c:
    ldr r0, lbl_08018f9c @ =0x0000ff68
    strh r0, [r2, #0xa]
    adds r0, #0x58
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018f9c: .4byte 0x0000ff68
lbl_08018fa0:
    ldr r0, lbl_08018fb0 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    b lbl_08018fc0
    .align 2, 0
lbl_08018fb0: .4byte 0x0000ff60
lbl_08018fb4:
    movs r1, #0
    ldr r0, lbl_08018fc8 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
lbl_08018fc0:
    movs r0, #0x90
lbl_08018fc2:
    strh r0, [r2, #0x10]
lbl_08018fc4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08018fc8: .4byte 0x0000ff60

    thumb_func_start sub_08018fcc
sub_08018fcc: @ 0x08018fcc
    push {lr}
    ldr r0, lbl_08018fec @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_08018fda
    b lbl_080190fc
lbl_08018fda:
    ldrh r0, [r2, #0x16]
    cmp r0, #9
    bls lbl_08018fe2
    b lbl_080190fc
lbl_08018fe2:
    lsls r0, r0, #2
    ldr r1, lbl_08018ff0 @ =lbl_08018ff4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08018fec: .4byte gCurrentSprite
lbl_08018ff0: .4byte lbl_08018ff4
lbl_08018ff4: @ jump table
    .4byte lbl_0801901c @ case 0
    .4byte lbl_0801903c @ case 1
    .4byte lbl_08019050 @ case 2
    .4byte lbl_08019064 @ case 3
    .4byte lbl_08019078 @ case 4
    .4byte lbl_0801909c @ case 5
    .4byte lbl_080190b0 @ case 6
    .4byte lbl_080190c4 @ case 7
    .4byte lbl_080190d8 @ case 8
    .4byte lbl_080190ec @ case 9
lbl_0801901c:
    ldr r0, lbl_08019038 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #8
    strh r0, [r2, #0xe]
    movs r0, #0x80
    strh r0, [r2, #0x10]
    movs r0, #0xe0
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_080190fc
    .align 2, 0
lbl_08019038: .4byte 0x0000ff60
lbl_0801903c:
    ldr r0, lbl_0801904c @ =0x0000ff40
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    adds r0, #0x40
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_080190fa
    .align 2, 0
lbl_0801904c: .4byte 0x0000ff40
lbl_08019050:
    ldr r0, lbl_08019060 @ =0x0000ff20
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    adds r0, #0x20
    strh r0, [r2, #0xe]
    movs r0, #0x50
    b lbl_080190fa
    .align 2, 0
lbl_08019060: .4byte 0x0000ff20
lbl_08019064:
    ldr r0, lbl_08019074 @ =0x0000fea0
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    adds r0, #0xa0
    strh r0, [r2, #0xe]
    movs r0, #0x30
    b lbl_080190fa
    .align 2, 0
lbl_08019074: .4byte 0x0000fea0
lbl_08019078:
    ldr r0, lbl_08019090 @ =0x0000fe20
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    ldr r0, lbl_08019094 @ =0x0000ffc0
    strh r0, [r2, #0xe]
    movs r0, #0x40
    strh r0, [r2, #0x10]
    ldr r0, lbl_08019098 @ =0x000001c1
    bl SoundPlay
    b lbl_080190fc
    .align 2, 0
lbl_08019090: .4byte 0x0000fe20
lbl_08019094: .4byte 0x0000ffc0
lbl_08019098: .4byte 0x000001c1
lbl_0801909c:
    ldr r0, lbl_080190ac @ =0x0000fe40
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0x60
    strh r0, [r2, #0xe]
    movs r0, #0xe0
    b lbl_080190fa
    .align 2, 0
lbl_080190ac: .4byte 0x0000fe40
lbl_080190b0:
    ldr r0, lbl_080190c0 @ =0x0000fee0
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0xc0
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_080190fa
    .align 2, 0
lbl_080190c0: .4byte 0x0000fee0
lbl_080190c4:
    ldr r0, lbl_080190d4 @ =0x0000ff20
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #0x40
    strh r0, [r2, #0xe]
    movs r0, #0xc0
    b lbl_080190fa
    .align 2, 0
lbl_080190d4: .4byte 0x0000ff20
lbl_080190d8:
    ldr r0, lbl_080190e8 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    movs r0, #0x80
    b lbl_080190fa
    .align 2, 0
lbl_080190e8: .4byte 0x0000ff60
lbl_080190ec:
    ldr r0, lbl_08019100 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    adds r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x70
lbl_080190fa:
    strh r0, [r2, #0x10]
lbl_080190fc:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019100: .4byte 0x0000ff60

    thumb_func_start KraidMouthUpdateLeftArmAttackingHitbox
KraidMouthUpdateLeftArmAttackingHitbox: @ 0x08019104
    push {lr}
    ldr r0, lbl_08019124 @ =gCurrentSprite
    ldrb r1, [r0, #0x1c]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_08019112
    b lbl_08019328
lbl_08019112:
    ldrh r0, [r2, #0x16]
    cmp r0, #0x13
    bls lbl_0801911a
    b lbl_08019328
lbl_0801911a:
    lsls r0, r0, #2
    ldr r1, lbl_08019128 @ =lbl_0801912c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08019124: .4byte gCurrentSprite
lbl_08019128: .4byte lbl_0801912c
lbl_0801912c: @ jump table
    .4byte lbl_0801917c @ case 0
    .4byte lbl_0801919c @ case 1
    .4byte lbl_080191b0 @ case 2
    .4byte lbl_080191c4 @ case 3
    .4byte lbl_080191d8 @ case 4
    .4byte lbl_080191e8 @ case 5
    .4byte lbl_080191fa @ case 6
    .4byte lbl_0801921c @ case 7
    .4byte lbl_08019230 @ case 8
    .4byte lbl_08019242 @ case 9
    .4byte lbl_08019258 @ case 10
    .4byte lbl_0801926c @ case 11
    .4byte lbl_08019280 @ case 12
    .4byte lbl_08019294 @ case 13
    .4byte lbl_080192a8 @ case 14
    .4byte lbl_080192bc @ case 15
    .4byte lbl_080192dc @ case 16
    .4byte lbl_080192f0 @ case 17
    .4byte lbl_08019304 @ case 18
    .4byte lbl_08019318 @ case 19
lbl_0801917c:
    movs r1, #0
    ldr r0, lbl_08019198 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
    movs r0, #0x80
    strh r0, [r2, #0x10]
    movs r0, #0xe2
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08019328
    .align 2, 0
lbl_08019198: .4byte 0x0000ff60
lbl_0801919c:
    ldr r0, lbl_080191ac @ =0x0000ff68
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    adds r0, #0x18
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_08019326
    .align 2, 0
lbl_080191ac: .4byte 0x0000ff68
lbl_080191b0:
    ldr r0, lbl_080191c0 @ =0x0000ff50
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    subs r0, #0x30
    strh r0, [r2, #0xe]
    movs r0, #0x20
    b lbl_08019326
    .align 2, 0
lbl_080191c0: .4byte 0x0000ff50
lbl_080191c4:
    ldr r0, lbl_080191d4 @ =0x0000ff20
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    subs r0, #0x20
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_08019326
    .align 2, 0
lbl_080191d4: .4byte 0x0000ff20
lbl_080191d8:
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_08019326
lbl_080191e8:
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    adds r0, #0x20
    strh r0, [r2, #0xe]
    adds r0, #0x60
    b lbl_08019326
lbl_080191fa:
    ldr r0, lbl_08019214 @ =0x0000fe80
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    adds r0, #0x80
    strh r0, [r2, #0xe]
    adds r0, #0x78
    strh r0, [r2, #0x10]
    ldr r0, lbl_08019218 @ =0x000001c5
    bl SoundPlay
    b lbl_08019328
    .align 2, 0
lbl_08019214: .4byte 0x0000fe80
lbl_08019218: .4byte 0x000001c5
lbl_0801921c:
    ldr r0, lbl_0801922c @ =0x0000fea0
    strh r0, [r2, #0xa]
    adds r0, #0x58
    strh r0, [r2, #0xc]
    movs r0, #8
    strh r0, [r2, #0xe]
    movs r0, #0x80
    b lbl_08019326
    .align 2, 0
lbl_0801922c: .4byte 0x0000fea0
lbl_08019230:
    movs r0, #0xff
    lsls r0, r0, #8
    strh r0, [r2, #0xa]
    adds r0, #0x40
    strh r0, [r2, #0xc]
    movs r0, #0x40
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    b lbl_08019326
lbl_08019242:
    ldr r0, lbl_08019254 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x70
    strh r0, [r2, #0xc]
    movs r0, #0x60
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    b lbl_08019326
    .align 2, 0
lbl_08019254: .4byte 0x0000ff60
lbl_08019258:
    ldr r0, lbl_08019268 @ =0x0000ffa0
    strh r0, [r2, #0xa]
    adds r0, #0x5c
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_08019326
    .align 2, 0
lbl_08019268: .4byte 0x0000ffa0
lbl_0801926c:
    ldr r0, lbl_0801927c @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_08019326
    .align 2, 0
lbl_0801927c: .4byte 0x0000ff60
lbl_08019280:
    ldr r0, lbl_08019290 @ =0x0000ff80
    strh r0, [r2, #0xa]
    adds r0, #0x40
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_08019326
    .align 2, 0
lbl_08019290: .4byte 0x0000ff80
lbl_08019294:
    ldr r0, lbl_080192a4 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x70
    b lbl_08019326
    .align 2, 0
lbl_080192a4: .4byte 0x0000ff60
lbl_080192a8:
    ldr r0, lbl_080192b8 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x80
    b lbl_08019326
    .align 2, 0
lbl_080192b8: .4byte 0x0000ff60
lbl_080192bc:
    ldr r0, lbl_080192d8 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x90
    strh r0, [r2, #0x10]
    movs r0, #0xe3
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08019328
    .align 2, 0
lbl_080192d8: .4byte 0x0000ff60
lbl_080192dc:
    ldr r0, lbl_080192ec @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    b lbl_08019326
    .align 2, 0
lbl_080192ec: .4byte 0x0000ff60
lbl_080192f0:
    ldr r0, lbl_08019300 @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x60
    strh r0, [r2, #0xc]
    movs r0, #0x10
    strh r0, [r2, #0xe]
    movs r0, #0x98
    b lbl_08019326
    .align 2, 0
lbl_08019300: .4byte 0x0000ff60
lbl_08019304:
    ldr r0, lbl_08019314 @ =0x0000ff68
    strh r0, [r2, #0xa]
    adds r0, #0x58
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    movs r0, #0x80
    b lbl_08019326
    .align 2, 0
lbl_08019314: .4byte 0x0000ff68
lbl_08019318:
    ldr r0, lbl_0801932c @ =0x0000ff60
    strh r0, [r2, #0xa]
    adds r0, #0x80
    strh r0, [r2, #0xc]
    movs r0, #4
    strh r0, [r2, #0xe]
    movs r0, #0x90
lbl_08019326:
    strh r0, [r2, #0x10]
lbl_08019328:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801932c: .4byte 0x0000ff60

    thumb_func_start KraidMoveBG2ToRight
KraidMoveBG2ToRight: @ 0x08019330
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_08019348 @ =gSubSpriteData1
    ldrh r1, [r2, #8]
    adds r1, r1, r0
    strh r1, [r2, #8]
    ldr r2, lbl_0801934c @ =gBG2Movement
    ldrh r1, [r2]
    subs r1, r1, r0
    strh r1, [r2]
    bx lr
    .align 2, 0
lbl_08019348: .4byte gSubSpriteData1
lbl_0801934c: .4byte gBG2Movement

    thumb_func_start KraidMoveBG2ToLeft
KraidMoveBG2ToLeft: @ 0x08019350
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_08019368 @ =gSubSpriteData1
    ldrh r1, [r2, #8]
    subs r1, r1, r0
    strh r1, [r2, #8]
    ldr r2, lbl_0801936c @ =gBG2Movement
    ldrh r1, [r2]
    adds r1, r1, r0
    strh r1, [r2]
    bx lr
    .align 2, 0
lbl_08019368: .4byte gSubSpriteData1
lbl_0801936c: .4byte gBG2Movement

    thumb_func_start KraidInit
KraidInit: @ 0x08019370
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r1, lbl_08019574 @ =gDoorUnlockTimer
    movs r0, #1
    strb r0, [r1]
    ldr r3, lbl_08019578 @ =gCurrentSprite
    ldrh r1, [r3, #2]
    subs r1, #0x28
    movs r2, #0
    movs r6, #0
    strh r1, [r3, #2]
    ldrh r0, [r3, #4]
    subs r0, #0x20
    strh r0, [r3, #4]
    ldr r4, lbl_0801957c @ =gSubSpriteData1
    mov r8, r4
    strh r1, [r4, #6]
    strh r0, [r4, #8]
    ldrh r0, [r4, #6]
    mov sb, r0
    ldrh r1, [r4, #8]
    mov sl, r1
    strh r0, [r3, #6]
    strh r1, [r3, #8]
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x1a
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x38
    strb r0, [r1]
    ldr r0, lbl_08019580 @ =0x0000ff90
    strh r0, [r3, #0xa]
    movs r1, #0x70
    strh r1, [r3, #0xc]
    subs r0, #0x30
    strh r0, [r3, #0xe]
    strh r1, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x2c
    movs r0, #0x78
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    subs r1, #7
    movs r0, #0xa
    strb r0, [r1]
    ldrh r0, [r3]
    movs r4, #0x80
    lsls r4, r4, #8
    adds r1, r4, #0
    orrs r0, r1
    orrs r0, r2
    movs r4, #0x80
    lsls r4, r4, #2
    adds r1, r4, #0
    orrs r0, r1
    movs r1, #0x20
    orrs r0, r1
    strh r0, [r3]
    ldr r0, lbl_08019584 @ =0x082b0d68
    ldr r1, lbl_08019588 @ =0x000007ce
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r3, #0x14]
    mov r4, r8
    strh r0, [r4, #0xa]
    strb r2, [r4, #0xf]
    strb r2, [r4, #0xe]
    strb r2, [r4, #0xd]
    ldr r0, lbl_0801958c @ =0x082c61f0
    str r0, [r4]
    strb r2, [r4, #0xc]
    strh r6, [r4, #4]
    ldr r0, lbl_08019590 @ =0x082cac1c
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    strh r6, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #1
    strb r0, [r1]
    movs r0, #6
    strb r0, [r3, #0x1e]
    ldrb r5, [r3, #0x1f]
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r4, [r0]
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #1
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #2
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r7, lbl_08019594 @ =gSpriteData
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r7
    adds r1, #0x2d
    strb r0, [r1]
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #3
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #4
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r7
    adds r1, #0x2d
    strb r0, [r1]
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #5
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #7
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r7
    adds r1, #0x2d
    strb r0, [r1]
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #8
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #9
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #0xa
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, sb
    str r0, [sp]
    mov r1, sl
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #3
    movs r1, #0xb
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r4, r8
    ldrh r0, [r4, #6]
    adds r0, #0x80
    strh r0, [r4, #6]
    ldr r1, lbl_08019598 @ =gBG2Movement
    ldrh r0, [r1, #2]
    subs r0, #0x80
    strh r0, [r1, #2]
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019574: .4byte gDoorUnlockTimer
lbl_08019578: .4byte gCurrentSprite
lbl_0801957c: .4byte gSubSpriteData1
lbl_08019580: .4byte 0x0000ff90
lbl_08019584: .4byte 0x082b0d68
lbl_08019588: .4byte 0x000007ce
lbl_0801958c: .4byte 0x082c61f0
lbl_08019590: .4byte 0x082cac1c
lbl_08019594: .4byte gSpriteData
lbl_08019598: .4byte gBG2Movement

    thumb_func_start KraidMoveUp
KraidMoveUp: @ 0x0801959c
    push {r4, r5, lr}
    ldr r5, lbl_080195cc @ =gCurrentSprite
    adds r0, r5, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    bl KraidRandomSpriteDebrisOnCeiling
    ldr r4, lbl_080195d0 @ =gSubSpriteData1
    ldrh r1, [r4, #6]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_080195be
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
lbl_080195be:
    ldrh r0, [r4, #6]
    ldrh r5, [r5, #6]
    cmp r0, r5
    bhi lbl_080195d4
    movs r0, #1
    b lbl_080195e2
    .align 2, 0
lbl_080195cc: .4byte gCurrentSprite
lbl_080195d0: .4byte gSubSpriteData1
lbl_080195d4:
    subs r0, #1
    strh r0, [r4, #6]
    ldr r1, lbl_080195e8 @ =gBG2Movement
    ldrh r0, [r1, #2]
    adds r0, #1
    strh r0, [r1, #2]
    movs r0, #0
lbl_080195e2:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080195e8: .4byte gBG2Movement

    thumb_func_start KraidGoUp
KraidGoUp: @ 0x080195ec
    push {r4, r5, lr}
    ldr r4, lbl_08019634 @ =gCurrentSprite
    adds r5, r4, #0
    adds r5, #0x2d
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_08019600
    ldr r0, lbl_08019638 @ =0x000001bf
    bl SoundPlay
lbl_08019600:
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    bl KraidMoveUp
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0801962c
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #2
    strb r1, [r0]
    ldr r0, lbl_0801963c @ =0x082cac34
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r2, [r4, #0x16]
lbl_0801962c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019634: .4byte gCurrentSprite
lbl_08019638: .4byte 0x000001bf
lbl_0801963c: .4byte 0x082cac34

    thumb_func_start KraidCheckFullyUp
KraidCheckFullyUp: @ 0x08019640
    push {r4, lr}
    ldr r4, lbl_08019668 @ =gCurrentSprite
    adds r1, r4, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    bl KraidMoveUp
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08019660
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
lbl_08019660:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019668: .4byte gCurrentSprite

    thumb_func_start sub_0801966c
sub_0801966c: @ 0x0801966c
    push {r4, r5, r6, r7, lr}
    ldr r5, lbl_080196b4 @ =gCurrentSprite
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r6, r5, #0
    cmp r0, #0
    bne lbl_08019680
    b lbl_080197c4
lbl_08019680:
    ldr r4, lbl_080196b8 @ =gSubSpriteData1
    ldr r0, lbl_080196bc @ =0x082b0d68
    ldr r1, lbl_080196c0 @ =0x000007ce
    adds r0, r0, r1
    ldrh r0, [r0]
    movs r1, #3
    bl __udivsi3
    ldrh r1, [r4, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, r0
    bhs lbl_080196a4
    ldr r0, lbl_080196c4 @ =gDifficulty
    ldrb r0, [r0]
    movs r2, #0xc0
    cmp r0, #0
    bne lbl_080196a6
lbl_080196a4:
    movs r2, #0x40
lbl_080196a6:
    ldrh r0, [r6, #8]
    adds r0, r0, r2
    ldrh r1, [r4, #8]
    cmp r0, r1
    bge lbl_080196c8
    movs r0, #2
    b lbl_0801980a
    .align 2, 0
lbl_080196b4: .4byte gCurrentSprite
lbl_080196b8: .4byte gSubSpriteData1
lbl_080196bc: .4byte 0x082b0d68
lbl_080196c0: .4byte 0x000007ce
lbl_080196c4: .4byte gDifficulty
lbl_080196c8:
    ldrh r0, [r4, #4]
    cmp r0, #4
    bls lbl_080196d0
    b lbl_08019808
lbl_080196d0:
    movs r0, #1
    bl KraidMoveBG2ToRight
    movs r5, #0x9e
    lsls r5, r5, #4
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r1, #0
    ldrh r4, [r4, #8]
    adds r0, r0, r4
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_080196f6
    b lbl_08019808
lbl_080196f6:
    ldr r7, lbl_080197b8 @ =gCurrentClipdataAffectingAction
    movs r6, #1
    strb r6, [r7]
    adds r0, r5, #0
    adds r1, r4, #0
    bl ClipdataProcess
    adds r0, r5, #0
    adds r1, r4, #0
    movs r2, #0x1e
    bl ParticleSet
    movs r2, #0x9d
    lsls r2, r2, #4
    movs r0, #0
    movs r1, #0x11
    adds r3, r4, #0
    bl SpriteDebrisInit
    adds r3, r4, #0
    adds r3, #0xc
    movs r0, #0
    movs r1, #0x12
    adds r2, r5, #0
    bl SpriteDebrisInit
    ldr r2, lbl_080197bc @ =0x000009b6
    adds r3, r4, #0
    adds r3, #0x14
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    ldr r2, lbl_080197c0 @ =0x000009c8
    adds r3, r4, #0
    subs r3, #0x1e
    movs r0, #0
    movs r1, #4
    bl SpriteDebrisInit
    movs r0, #0x9c
    lsls r0, r0, #1
    bl SoundPlay
    movs r5, #0xfc
    lsls r5, r5, #3
    adds r0, r4, #0
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_08019808
    strb r6, [r7]
    adds r0, r5, #0
    adds r1, r4, #0
    bl ClipdataProcess
    adds r0, r5, #0
    adds r1, r4, #0
    movs r2, #0x20
    bl ParticleSet
    adds r2, r5, #0
    subs r2, #0x10
    movs r0, #0
    movs r1, #0x11
    adds r3, r4, #0
    bl SpriteDebrisInit
    adds r3, r4, #0
    adds r3, #0xc
    movs r0, #0
    movs r1, #0x12
    adds r2, r5, #0
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x2a
    adds r3, r4, #0
    adds r3, #0x14
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r2, r5, #0
    subs r2, #0x18
    adds r3, r4, #0
    subs r3, #0x1e
    movs r0, #0
    movs r1, #4
    bl SpriteDebrisInit
    b lbl_08019808
    .align 2, 0
lbl_080197b8: .4byte gCurrentClipdataAffectingAction
lbl_080197bc: .4byte 0x000009b6
lbl_080197c0: .4byte 0x000009c8
lbl_080197c4:
    ldr r4, lbl_080197f0 @ =gSubSpriteData1
    ldr r0, lbl_080197f4 @ =0x082b0d68
    ldr r1, lbl_080197f8 @ =0x000007ce
    adds r0, r0, r1
    ldrh r0, [r0]
    movs r1, #3
    bl __udivsi3
    ldrh r1, [r4, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0
    cmp r1, r0
    bhs lbl_080197e2
    movs r2, #0x40
lbl_080197e2:
    ldrh r0, [r5, #8]
    adds r0, r0, r2
    ldrh r1, [r4, #8]
    cmp r0, r1
    ble lbl_080197fc
    movs r0, #1
    b lbl_0801980a
    .align 2, 0
lbl_080197f0: .4byte gSubSpriteData1
lbl_080197f4: .4byte 0x082b0d68
lbl_080197f8: .4byte 0x000007ce
lbl_080197fc:
    ldrh r0, [r4, #4]
    cmp r0, #4
    bhi lbl_08019808
    movs r0, #1
    bl KraidMoveBG2ToLeft
lbl_08019808:
    movs r0, #0
lbl_0801980a:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start KraidFirstStepInit
KraidFirstStepInit: @ 0x08019810
    push {lr}
    ldr r2, lbl_08019828 @ =gCurrentSprite
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08019834
    ldr r1, lbl_0801982c @ =gSubSpriteData1
    ldr r0, lbl_08019830 @ =0x082c6240
    b lbl_08019838
    .align 2, 0
lbl_08019828: .4byte gCurrentSprite
lbl_0801982c: .4byte gSubSpriteData1
lbl_08019830: .4byte 0x082c6240
lbl_08019834:
    ldr r1, lbl_0801984c @ =gSubSpriteData1
    ldr r0, lbl_08019850 @ =0x082c62e8
lbl_08019838:
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801984c: .4byte gSubSpriteData1
lbl_08019850: .4byte 0x082c62e8

    thumb_func_start kraid_feet_movement_same_direction_as_pos_update
kraid_feet_movement_same_direction_as_pos_update: @ 0x08019854
    push {r4, r5, r6, lr}
    bl sub_0801966c
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    bl SpriteUtilCheckNearEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0801992c
    ldr r0, lbl_08019898 @ =gSubSpriteData1
    ldrb r2, [r0, #0xd]
    adds r1, r2, #0
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_080198bc
    cmp r1, #3
    bhi lbl_080198a4
    adds r0, r2, #1
    strb r0, [r4, #0xd]
    ldr r1, lbl_0801989c @ =gCurrentSprite
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_0801988e
    ldr r0, lbl_080198a0 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
lbl_0801988e:
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    b lbl_0801992c
    .align 2, 0
lbl_08019898: .4byte gSubSpriteData1
lbl_0801989c: .4byte gCurrentSprite
lbl_080198a0: .4byte 0x0000fdff
lbl_080198a4:
    movs r0, #0
    strb r0, [r4, #0xd]
    ldr r1, lbl_080198b8 @ =gCurrentSprite
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_08019910
    .align 2, 0
lbl_080198b8: .4byte gCurrentSprite
lbl_080198bc:
    ldr r2, lbl_080198d8 @ =0x082b0d68
    ldr r1, lbl_080198dc @ =0x000007ce
    adds r0, r2, r1
    ldrh r0, [r0]
    ldrh r1, [r4, #0xa]
    lsrs r0, r0, #2
    adds r3, r2, #0
    cmp r1, r0
    bhs lbl_080198e4
    ldr r2, lbl_080198e0 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
    b lbl_080198ec
    .align 2, 0
lbl_080198d8: .4byte 0x082b0d68
lbl_080198dc: .4byte 0x000007ce
lbl_080198e0: .4byte gCurrentSprite
lbl_080198e4:
    ldr r2, lbl_08019918 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x10
lbl_080198ec:
    strb r0, [r1]
    adds r5, r2, #0
    cmp r6, #0
    beq lbl_0801992c
    ldr r2, lbl_0801991c @ =0x000007ce
    adds r0, r3, r2
    ldrh r0, [r0]
    movs r1, #3
    bl __udivsi3
    ldrh r1, [r4, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, r0
    bhs lbl_08019920
    cmp r6, #2
    bne lbl_08019920
    adds r1, r5, #0
lbl_08019910:
    adds r1, #0x24
    movs r0, #0x10
    strb r0, [r1]
    b lbl_0801992c
    .align 2, 0
lbl_08019918: .4byte gCurrentSprite
lbl_0801991c: .4byte 0x000007ce
lbl_08019920:
    ldrh r0, [r5]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r5]
lbl_0801992c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start KraidMoveFeet_to_opposite_direction_as_pos
KraidMoveFeet_to_opposite_direction_as_pos: @ 0x08019934
    push {lr}
    ldr r2, lbl_0801994c @ =gCurrentSprite
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08019958
    ldr r1, lbl_08019950 @ =gSubSpriteData1
    ldr r0, lbl_08019954 @ =0x082c6278
    b lbl_0801995c
    .align 2, 0
lbl_0801994c: .4byte gCurrentSprite
lbl_08019950: .4byte gSubSpriteData1
lbl_08019954: .4byte 0x082c6278
lbl_08019958:
    ldr r1, lbl_08019970 @ =gSubSpriteData1
    ldr r0, lbl_08019974 @ =0x082c62b0
lbl_0801995c:
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019970: .4byte gSubSpriteData1
lbl_08019974: .4byte 0x082c62b0

    thumb_func_start kraid_feet_movement_oppsite_direction_as_pos_update
kraid_feet_movement_oppsite_direction_as_pos_update: @ 0x08019978
    push {r4, r5, r6, lr}
    bl sub_0801966c
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    bl SpriteUtilCheckNearEndSubSprite1Anim
    cmp r0, #0
    beq lbl_08019a50
    ldr r0, lbl_080199bc @ =gSubSpriteData1
    ldrb r2, [r0, #0xd]
    adds r1, r2, #0
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_080199e0
    cmp r1, #3
    bhi lbl_080199c8
    adds r0, r2, #1
    strb r0, [r4, #0xd]
    ldr r1, lbl_080199c0 @ =gCurrentSprite
    ldrh r2, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_080199b2
    ldr r0, lbl_080199c4 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
lbl_080199b2:
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    b lbl_08019a50
    .align 2, 0
lbl_080199bc: .4byte gSubSpriteData1
lbl_080199c0: .4byte gCurrentSprite
lbl_080199c4: .4byte 0x0000fdff
lbl_080199c8:
    movs r0, #0
    strb r0, [r4, #0xd]
    ldr r1, lbl_080199dc @ =gCurrentSprite
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_08019a34
    .align 2, 0
lbl_080199dc: .4byte gCurrentSprite
lbl_080199e0:
    ldr r2, lbl_080199fc @ =0x082b0d68
    ldr r1, lbl_08019a00 @ =0x000007ce
    adds r0, r2, r1
    ldrh r0, [r0]
    ldrh r1, [r4, #0xa]
    lsrs r0, r0, #2
    adds r3, r2, #0
    cmp r1, r0
    bhs lbl_08019a08
    ldr r2, lbl_08019a04 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    b lbl_08019a10
    .align 2, 0
lbl_080199fc: .4byte 0x082b0d68
lbl_08019a00: .4byte 0x000007ce
lbl_08019a04: .4byte gCurrentSprite
lbl_08019a08:
    ldr r2, lbl_08019a3c @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0xe
lbl_08019a10:
    strb r0, [r1]
    adds r5, r2, #0
    cmp r6, #0
    beq lbl_08019a50
    ldr r2, lbl_08019a40 @ =0x000007ce
    adds r0, r3, r2
    ldrh r0, [r0]
    movs r1, #3
    bl __udivsi3
    ldrh r1, [r4, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, r0
    bhs lbl_08019a44
    cmp r6, #2
    bne lbl_08019a44
    adds r1, r5, #0
lbl_08019a34:
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    b lbl_08019a50
    .align 2, 0
lbl_08019a3c: .4byte gCurrentSprite
lbl_08019a40: .4byte 0x000007ce
lbl_08019a44:
    ldrh r0, [r5]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r5]
lbl_08019a50:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start KraidStandingInit
KraidStandingInit: @ 0x08019a58
    ldr r1, lbl_08019a70 @ =gSubSpriteData1
    ldr r0, lbl_08019a74 @ =0x082c6200
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r0, lbl_08019a78 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0xf
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08019a70: .4byte gSubSpriteData1
lbl_08019a74: .4byte 0x082c6200
lbl_08019a78: .4byte gCurrentSprite

    thumb_func_start KraidStanding
KraidStanding: @ 0x08019a7c
    push {lr}
    bl SpriteUtilCheckNearEndSubSprite1Anim
    cmp r0, #0
    beq lbl_08019aa4
    ldr r2, lbl_08019aa8 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldr r1, lbl_08019aac @ =gSubSpriteData1
    ldrb r0, [r1, #0xd]
    cmp r0, #1
    bne lbl_08019aa4
    adds r0, #1
    strb r0, [r1, #0xd]
    ldrh r1, [r2]
    ldr r0, lbl_08019ab0 @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
lbl_08019aa4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019aa8: .4byte gCurrentSprite
lbl_08019aac: .4byte gSubSpriteData1
lbl_08019ab0: .4byte 0x0000fdff

    thumb_func_start kraid_after_moving_feet_same_direction_as_pos
kraid_after_moving_feet_same_direction_as_pos: @ 0x08019ab4
    ldr r1, lbl_08019acc @ =gSubSpriteData1
    ldr r0, lbl_08019ad0 @ =0x082c6220
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r0, lbl_08019ad4 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0x11
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08019acc: .4byte gSubSpriteData1
lbl_08019ad0: .4byte 0x082c6220
lbl_08019ad4: .4byte gCurrentSprite

    thumb_func_start kraid_before_start_moving_feet_opposite_direction_as_pos
kraid_before_start_moving_feet_opposite_direction_as_pos: @ 0x08019ad8
    push {lr}
    bl SpriteUtilCheckNearEndSubSprite1Anim
    cmp r0, #0
    beq lbl_08019b00
    ldr r2, lbl_08019b04 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    ldr r1, lbl_08019b08 @ =gSubSpriteData1
    ldrb r0, [r1, #0xd]
    cmp r0, #1
    bne lbl_08019b00
    adds r0, #1
    strb r0, [r1, #0xd]
    ldrh r1, [r2]
    ldr r0, lbl_08019b0c @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
lbl_08019b00:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019b04: .4byte gCurrentSprite
lbl_08019b08: .4byte gSubSpriteData1
lbl_08019b0c: .4byte 0x0000fdff

    thumb_func_start KraidPreventSamusGoingThrough
KraidPreventSamusGoingThrough: @ 0x08019b10
    push {lr}
    ldr r0, lbl_08019b2c @ =gSubSpriteData1
    ldrh r0, [r0, #8]
    adds r0, #0xc0
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r2, lbl_08019b30 @ =gSamusData
    ldrh r0, [r2, #0x12]
    cmp r0, r1
    bhs lbl_08019b26
    strh r1, [r2, #0x12]
lbl_08019b26:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019b2c: .4byte gSubSpriteData1
lbl_08019b30: .4byte gSamusData

    thumb_func_start KraidDyingInit
KraidDyingInit: @ 0x08019b34
    push {r4, lr}
    ldr r0, lbl_08019b54 @ =gSubSpriteData1
    ldr r2, [r0]
    ldr r1, lbl_08019b58 @ =0x082c6200
    adds r3, r0, #0
    cmp r2, r1
    beq lbl_08019b4e
    ldr r0, lbl_08019b5c @ =0x082c6278
    cmp r2, r0
    beq lbl_08019b4e
    ldr r0, lbl_08019b60 @ =0x082c62b0
    cmp r2, r0
    bne lbl_08019b68
lbl_08019b4e:
    ldr r0, lbl_08019b64 @ =0x082c6320
    b lbl_08019b6a
    .align 2, 0
lbl_08019b54: .4byte gSubSpriteData1
lbl_08019b58: .4byte 0x082c6200
lbl_08019b5c: .4byte 0x082c6278
lbl_08019b60: .4byte 0x082c62b0
lbl_08019b64: .4byte 0x082c6320
lbl_08019b68:
    ldr r0, lbl_08019bd4 @ =0x082c6330
lbl_08019b6a:
    str r0, [r3]
    movs r2, #0
    strb r2, [r3, #0xc]
    strh r2, [r3, #4]
    ldr r0, lbl_08019bd8 @ =gCurrentSprite
    ldr r1, [r0, #0x18]
    ldr r4, lbl_08019bdc @ =0x082cab9c
    adds r3, r0, #0
    cmp r1, r4
    beq lbl_08019b8c
    ldr r0, lbl_08019be0 @ =0x082cabe4
    cmp r1, r0
    beq lbl_08019b8c
    str r4, [r3, #0x18]
    movs r0, #0
    strb r0, [r3, #0x1c]
    strh r2, [r3, #0x16]
lbl_08019b8c:
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x67
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x64
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #2
    movs r0, #0xc8
    strb r0, [r1]
    movs r0, #1
    strh r0, [r3, #0x14]
    subs r1, #3
    movs r0, #8
    strb r0, [r1]
    subs r1, #9
    movs r0, #0xc
    strb r0, [r1]
    movs r0, #1
    movs r1, #0x1e
    bl EventFunction
    movs r0, #0x1e
    bl MinimapUpdateChunk
    movs r0, #0xe8
    lsls r0, r0, #1
    bl SoundPlay
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019bd4: .4byte 0x082c6330
lbl_08019bd8: .4byte gCurrentSprite
lbl_08019bdc: .4byte 0x082cab9c
lbl_08019be0: .4byte 0x082cabe4

    thumb_func_start KraidDying
KraidDying: @ 0x08019be4
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_08019c64 @ =gCurrentSprite
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08019c68 @ =0x082cab9c
    cmp r1, r0
    bne lbl_08019c02
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08019c02
    ldr r0, lbl_08019c6c @ =0x082cabe4
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
lbl_08019c02:
    ldr r6, lbl_08019c64 @ =gCurrentSprite
    adds r7, r6, #0
    adds r7, #0x2d
    ldrb r0, [r7]
    bl KraidRandomSpriteDebrisOnCeiling
    bl KraidPreventSamusGoingThrough
    adds r1, r6, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrb r0, [r7]
    adds r0, #1
    strb r0, [r7]
    movs r1, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_08019c52
    movs r5, #0xa0
    lsls r5, r5, #4
    ldr r4, lbl_08019c70 @ =gSubSpriteData1
    ldrb r1, [r7]
    lsls r1, r1, #1
    subs r1, #0xc0
    ldrh r0, [r4, #8]
    adds r1, r1, r0
    adds r0, r5, #0
    movs r2, #0x38
    bl ParticleSet
    ldrh r1, [r4, #8]
    ldrb r0, [r7]
    lsls r0, r0, #1
    subs r0, #0xc0
    subs r1, r1, r0
    adds r0, r5, #0
    movs r2, #0x39
    bl ParticleSet
lbl_08019c52:
    adds r1, r6, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08019c74
    subs r0, #1
    strb r0, [r1]
    b lbl_08019d3a
    .align 2, 0
lbl_08019c64: .4byte gCurrentSprite
lbl_08019c68: .4byte 0x082cab9c
lbl_08019c6c: .4byte 0x082cabe4
lbl_08019c70: .4byte gSubSpriteData1
lbl_08019c74:
    adds r1, r6, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08019c9e
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08019c92
    movs r0, #6
    bl StartEffectForCutscene
    b lbl_08019c9e
lbl_08019c92:
    cmp r0, #0
    bne lbl_08019c9e
    movs r0, #0xe9
    lsls r0, r0, #1
    bl SoundPlay
lbl_08019c9e:
    ldr r5, lbl_08019d1c @ =gCurrentSprite
    adds r4, r5, #0
    adds r4, #0x2d
    ldrb r1, [r4]
    movs r6, #0xf
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08019cd2
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
    ldr r0, lbl_08019d20 @ =gSpriteRng
    ldrb r0, [r0]
    lsls r0, r0, #4
    subs r0, #0x64
    ldrh r1, [r5, #2]
    adds r0, r0, r1
    ldrb r1, [r4]
    subs r1, #0xc8
    ldrh r2, [r5, #4]
    adds r1, r1, r2
    movs r2, #0x1e
    bl ParticleSet
lbl_08019cd2:
    ldrb r2, [r4]
    adds r0, r2, #0
    subs r0, #8
    ands r0, r6
    cmp r0, #0
    bne lbl_08019cf6
    ldrh r0, [r5, #2]
    ldr r1, lbl_08019d20 @ =gSpriteRng
    ldrb r1, [r1]
    lsls r1, r1, #4
    subs r1, #0x8c
    subs r0, r0, r1
    ldrh r1, [r5, #4]
    subs r2, #0xf0
    subs r1, r1, r2
    movs r2, #0x22
    bl ParticleSet
lbl_08019cf6:
    ldr r4, lbl_08019d24 @ =gSubSpriteData1
    ldrh r0, [r4, #6]
    ldrh r1, [r4, #8]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_08019d2c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x68
    strb r0, [r1]
    adds r1, #8
    movs r0, #0x78
    strb r0, [r1]
    ldr r0, lbl_08019d28 @ =0x000001d1
    bl SoundPlay
    b lbl_08019d3a
    .align 2, 0
lbl_08019d1c: .4byte gCurrentSprite
lbl_08019d20: .4byte gSpriteRng
lbl_08019d24: .4byte gSubSpriteData1
lbl_08019d28: .4byte 0x000001d1
lbl_08019d2c:
    ldrh r0, [r4, #6]
    adds r0, #1
    strh r0, [r4, #6]
    ldr r1, lbl_08019d40 @ =gBG2Movement
    ldrh r0, [r1, #2]
    subs r0, #1
    strh r0, [r1, #2]
lbl_08019d3a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019d40: .4byte gBG2Movement

    thumb_func_start KraidBeforeDeath
KraidBeforeDeath: @ 0x08019d44
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r6, lbl_08019db8 @ =gCurrentSprite
    adds r5, r6, #0
    adds r5, #0x2d
    ldrb r0, [r5]
    bl KraidRandomSpriteDebrisOnCeiling
    bl KraidPreventSamusGoingThrough
    adds r1, r6, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08019dbc @ =gSpriteRng
    ldrb r4, [r0]
    mov r8, r4
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    ldrb r7, [r5]
    movs r0, #7
    ands r0, r7
    cmp r0, #0
    bne lbl_08019dee
    movs r0, #8
    ands r0, r7
    cmp r0, #0
    beq lbl_08019dc0
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
    lsls r4, r4, #4
    adds r0, r4, #0
    subs r0, #0x64
    ldrh r1, [r6, #2]
    adds r0, r0, r1
    lsls r5, r7, #1
    adds r1, r5, #0
    subs r1, #0xa0
    ldrh r2, [r6, #4]
    adds r1, r1, r2
    movs r2, #0x1e
    bl ParticleSet
    ldrh r0, [r6, #2]
    subs r4, #0x8c
    subs r0, r0, r4
    ldrh r1, [r6, #4]
    subs r5, #0xc0
    subs r1, r1, r5
    movs r2, #0x22
    bl ParticleSet
    b lbl_08019dee
    .align 2, 0
lbl_08019db8: .4byte gCurrentSprite
lbl_08019dbc: .4byte gSpriteRng
lbl_08019dc0:
    mov r1, r8
    lsls r0, r1, #4
    ldrh r2, [r6, #2]
    adds r0, r0, r2
    ldrh r1, [r6, #4]
    lsls r4, r7, #1
    adds r2, r4, #0
    subs r2, #0xa0
    subs r1, r1, r2
    movs r2, #0x1e
    bl ParticleSet
    ldrh r0, [r6, #2]
    mov r2, r8
    lsls r1, r2, #3
    subs r0, r0, r1
    subs r4, #0x64
    ldrh r6, [r6, #4]
    adds r4, r4, r6
    adds r1, r4, #0
    movs r2, #0x22
    bl ParticleSet
lbl_08019dee:
    movs r0, #0xf
    ands r0, r7
    cmp r0, #0
    bne lbl_08019e6a
    movs r0, #0x10
    ands r7, r0
    cmp r7, #0
    beq lbl_08019e3c
    movs r0, #0xa0
    lsls r0, r0, #4
    mov r8, r0
    ldr r6, lbl_08019e30 @ =gSubSpriteData1
    ldr r4, lbl_08019e34 @ =gCurrentSprite
    adds r4, #0x2c
    ldrb r1, [r4]
    lsls r1, r1, #1
    ldr r5, lbl_08019e38 @ =0xfffffee8
    adds r1, r1, r5
    ldrh r2, [r6, #8]
    adds r1, r1, r2
    movs r2, #0x20
    bl ParticleSet
    ldrh r1, [r6, #8]
    ldrb r0, [r4]
    lsls r0, r0, #1
    adds r0, r0, r5
    subs r1, r1, r0
    mov r0, r8
    movs r2, #0x21
    bl ParticleSet
    b lbl_08019e6a
    .align 2, 0
lbl_08019e30: .4byte gSubSpriteData1
lbl_08019e34: .4byte gCurrentSprite
lbl_08019e38: .4byte 0xfffffee8
lbl_08019e3c:
    movs r6, #0xa0
    lsls r6, r6, #4
    ldr r5, lbl_08019eb8 @ =gSubSpriteData1
    ldr r4, lbl_08019ebc @ =gCurrentSprite
    adds r4, #0x2c
    ldrb r1, [r4]
    lsls r1, r1, #1
    subs r1, #0xd2
    ldrh r0, [r5, #8]
    adds r1, r1, r0
    adds r0, r6, #0
    movs r2, #0x21
    bl ParticleSet
    ldrh r1, [r5, #8]
    ldrb r0, [r4]
    lsls r0, r0, #1
    subs r0, #0xd2
    subs r1, r1, r0
    adds r0, r6, #0
    movs r2, #0x20
    bl ParticleSet
lbl_08019e6a:
    ldr r1, lbl_08019ebc @ =gCurrentSprite
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08019eaa
    ldr r0, lbl_08019eb8 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0xc0
    ldrh r2, [r0, #8]
    movs r0, #0x27
    str r0, [sp]
    movs r0, #0
    movs r3, #0
    bl SpriteUtilSpriteDeath
    movs r0, #0x14
    movs r1, #0xb
    movs r2, #0
    bl sub_08003b30
    movs r1, #0x80
    lsls r1, r1, #3
    movs r0, #0
    bl IoUpdateDISPCNT
    ldr r1, lbl_08019ec0 @ =gInGameTimerAtBosses
    ldr r0, lbl_08019ec4 @ =gInGameTimer
    ldr r0, [r0]
    str r0, [r1]
lbl_08019eaa:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08019eb8: .4byte gSubSpriteData1
lbl_08019ebc: .4byte gCurrentSprite
lbl_08019ec0: .4byte gInGameTimerAtBosses
lbl_08019ec4: .4byte gInGameTimer

    thumb_func_start KraidPartInit
KraidPartInit: @ 0x08019ec8
    push {lr}
    ldr r2, lbl_08019ef8 @ =gCurrentSprite
    movs r0, #0xfa
    lsls r0, r0, #2
    strh r0, [r2, #0x14]
    ldrh r1, [r2]
    ldr r0, lbl_08019efc @ =0x0000fffb
    ands r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0xe
    strb r0, [r1]
    ldrb r0, [r2, #0x1e]
    mov ip, r2
    cmp r0, #0xb
    bls lbl_08019eec
    b lbl_0801a21c
lbl_08019eec:
    lsls r0, r0, #2
    ldr r1, lbl_08019f00 @ =lbl_08019f04
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08019ef8: .4byte gCurrentSprite
lbl_08019efc: .4byte 0x0000fffb
lbl_08019f00: .4byte lbl_08019f04
lbl_08019f04: @ jump table
    .4byte lbl_08019f34 @ case 0
    .4byte lbl_0801a0ec @ case 1
    .4byte lbl_08019f84 @ case 2
    .4byte lbl_08019fc8 @ case 3
    .4byte lbl_08019ff0 @ case 4
    .4byte lbl_0801a038 @ case 5
    .4byte lbl_0801a21c @ case 6
    .4byte lbl_0801a05c @ case 7
    .4byte lbl_0801a0a4 @ case 8
    .4byte lbl_0801a184 @ case 9
    .4byte lbl_0801a130 @ case 10
    .4byte lbl_0801a1cc @ case 11
lbl_08019f34:
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #4
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    adds r1, #0x25
    movs r0, #0xa
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x80
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x50
    strb r0, [r1]
    ldr r0, lbl_08019f7c @ =0x0000ff60
    mov r2, ip
    strh r0, [r2, #0xa]
    movs r0, #0xf0
    lsls r0, r0, #1
    strh r0, [r2, #0xc]
    ldr r0, lbl_08019f80 @ =0x0000fee0
    strh r0, [r2, #0xe]
    movs r0, #0xd0
    strh r0, [r2, #0x10]
    subs r1, #7
    movs r0, #1
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x44
    strb r0, [r1]
    b lbl_0801a20c
    .align 2, 0
lbl_08019f7c: .4byte 0x0000ff60
lbl_08019f80: .4byte 0x0000fee0
lbl_08019f84:
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #0xe
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    mov r1, ip
    adds r1, #0x29
    movs r0, #8
    strb r0, [r1]
    ldr r1, lbl_08019fc4 @ =0x0000ffe0
    mov r2, ip
    strh r1, [r2, #0xa]
    movs r0, #0x40
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
    movs r0, #0x20
    strh r0, [r2, #0x10]
    mov r1, ip
    adds r1, #0x22
    movs r0, #0xb
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0801a20c
    .align 2, 0
lbl_08019fc4: .4byte 0x0000ffe0
lbl_08019fc8:
    mov r2, ip
    ldrh r1, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    adds r0, #0xe
    movs r2, #4
    strb r2, [r0]
    subs r0, #0xc
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    b lbl_0801a0ce
lbl_08019ff0:
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #0xe
    strb r0, [r1]
    subs r1, #0xc
    movs r0, #0x14
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x10
    strb r0, [r1]
    adds r1, #1
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0801a030 @ =0x0000ffb0
    mov r2, ip
    strh r0, [r2, #0xa]
    movs r0, #0x50
    strh r0, [r2, #0xc]
    ldr r0, lbl_0801a034 @ =0x0000ffe0
    strh r0, [r2, #0xe]
    movs r0, #0x30
    strh r0, [r2, #0x10]
    subs r1, #7
    movs r0, #0xb
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0801a20c
    .align 2, 0
lbl_0801a030: .4byte 0x0000ffb0
lbl_0801a034: .4byte 0x0000ffe0
lbl_0801a038:
    mov r2, ip
    ldrh r1, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    adds r0, #0xe
    movs r2, #4
    strb r2, [r0]
    adds r1, #0x27
    movs r0, #0x14
    b lbl_0801a0c6
lbl_0801a05c:
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #0xe
    strb r0, [r1]
    subs r1, #0xc
    movs r0, #0x14
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x28
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_0801a09c @ =0x0000ffb0
    mov r2, ip
    strh r0, [r2, #0xa]
    movs r0, #0xd0
    strh r0, [r2, #0xc]
    ldr r0, lbl_0801a0a0 @ =0x0000ffe0
    strh r0, [r2, #0xe]
    movs r0, #0x20
    strh r0, [r2, #0x10]
    mov r1, ip
    adds r1, #0x22
    movs r0, #0xb
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0801a20c
    .align 2, 0
lbl_0801a09c: .4byte 0x0000ffb0
lbl_0801a0a0: .4byte 0x0000ffe0
lbl_0801a0a4:
    mov r2, ip
    ldrh r1, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    adds r0, #0xe
    movs r2, #4
    strb r2, [r0]
    adds r1, #0x27
    movs r0, #8
lbl_0801a0c6:
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x28
    movs r1, #0x10
lbl_0801a0ce:
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_0801a0e8 @ =0x0000fffc
    mov r1, ip
    strh r0, [r1, #0xa]
    strh r2, [r1, #0xc]
    strh r0, [r1, #0xe]
    strh r2, [r1, #0x10]
    adds r1, #0x22
    movs r0, #0xd
    strb r0, [r1]
    b lbl_0801a222
    .align 2, 0
lbl_0801a0e8: .4byte 0x0000fffc
lbl_0801a0ec:
    mov r3, ip
    adds r3, #0x32
    ldrb r1, [r3]
    movs r0, #0x40
    movs r2, #0
    orrs r0, r1
    strb r0, [r3]
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x80
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x28
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x60
    strb r0, [r1]
    subs r1, #7
    movs r0, #2
    strb r0, [r1]
    ldr r0, lbl_0801a12c @ =0x082cac6c
    mov r1, ip
    str r0, [r1, #0x18]
    strb r2, [r1, #0x1c]
    strh r2, [r1, #0x16]
    adds r1, #0x24
    movs r0, #0x10
    strb r0, [r1]
    b lbl_0801a222
    .align 2, 0
lbl_0801a12c: .4byte 0x082cac6c
lbl_0801a130:
    mov r2, ip
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    movs r3, #0
    orrs r0, r1
    strb r0, [r2]
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x60
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x38
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x78
    strb r0, [r1]
    subs r1, #7
    movs r0, #0xf
    strb r0, [r1]
    subs r1, #1
    movs r0, #3
    strb r0, [r1]
    ldr r0, lbl_0801a180 @ =0x082cadd4
    mov r2, ip
    str r0, [r2, #0x18]
    strb r3, [r2, #0x1c]
    movs r2, #0
    mov r0, ip
    strh r3, [r0, #0x16]
    adds r1, #3
    movs r0, #0x12
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2c
    strb r2, [r0]
    b lbl_0801a222
    .align 2, 0
lbl_0801a180: .4byte 0x082cadd4
lbl_0801a184:
    mov r2, ip
    ldrh r1, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    adds r1, #0x27
    movs r0, #0x36
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x28
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x38
    strb r0, [r1]
    ldr r1, lbl_0801a1c8 @ =0x0000fffc
    mov r2, ip
    strh r1, [r2, #0xa]
    movs r0, #4
    strh r0, [r2, #0xc]
    strh r1, [r2, #0xe]
    strh r0, [r2, #0x10]
    mov r1, ip
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    b lbl_0801a222
    .align 2, 0
lbl_0801a1c8: .4byte 0x0000fffc
lbl_0801a1cc:
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x36
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x28
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x70
    strb r0, [r1]
    movs r0, #0x80
    mov r1, ip
    strh r0, [r1, #0xa]
    movs r0, #0xa0
    strh r0, [r1, #0xc]
    movs r0, #0xc0
    strh r0, [r1, #0xe]
    adds r0, #0xb0
    strh r0, [r1, #0x10]
    adds r1, #0x22
    movs r0, #0xe
    strb r0, [r1]
    subs r1, #1
    movs r0, #3
    strb r0, [r1]
    adds r1, #3
    movs r0, #0x44
    strb r0, [r1]
    mov r2, ip
lbl_0801a20c:
    ldrh r1, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    b lbl_0801a222
lbl_0801a21c:
    movs r0, #0
    mov r2, ip
    strh r0, [r2]
lbl_0801a222:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start KraidPartThrowNails
KraidPartThrowNails: @ 0x0801a228
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r2, lbl_0801a280 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r1, lbl_0801a284 @ =gSpriteData
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r0, r0, r1
    adds r0, #0x24
    ldrb r0, [r0]
    adds r4, r2, #0
    cmp r0, #7
    bls lbl_0801a300
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0801a288 @ =0x082cac6c
    cmp r1, r0
    bne lbl_0801a298
    ldr r0, lbl_0801a28c @ =gFrameCounter8Bit
    ldrb r0, [r0]
    movs r5, #0x7f
    ands r5, r0
    cmp r5, #0
    bne lbl_0801a300
    bl SpriteUtilCountDrops
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r0, lbl_0801a290 @ =gDifficulty
    ldrb r0, [r0]
    movs r1, #3
    cmp r0, #0
    bne lbl_0801a270
    movs r1, #1
lbl_0801a270:
    cmp r2, r1
    bhs lbl_0801a300
    ldr r0, lbl_0801a294 @ =0x082cad1c
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    b lbl_0801a300
    .align 2, 0
lbl_0801a280: .4byte gCurrentSprite
lbl_0801a284: .4byte gSpriteData
lbl_0801a288: .4byte 0x082cac6c
lbl_0801a28c: .4byte gFrameCounter8Bit
lbl_0801a290: .4byte gDifficulty
lbl_0801a294: .4byte 0x082cad1c
lbl_0801a298:
    ldrh r0, [r4, #0x16]
    cmp r0, #7
    bne lbl_0801a2c0
    ldrb r0, [r4, #0x1c]
    cmp r0, #4
    bne lbl_0801a2c0
    ldrb r2, [r4, #0x1f]
    ldrh r0, [r4, #2]
    subs r0, #0xe0
    str r0, [sp]
    ldrh r0, [r4, #4]
    adds r0, #0x80
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x1d
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0801a2ec
lbl_0801a2c0:
    ldrh r0, [r4, #0x16]
    cmp r0, #8
    bne lbl_0801a2ec
    ldrb r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0801a2ec
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0xc0
    str r0, [sp]
    ldrh r0, [r4, #4]
    adds r0, #0xe0
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x1d
    movs r1, #1
    bl SpriteSpawnSecondary
lbl_0801a2ec:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801a300
    ldr r0, lbl_0801a308 @ =gCurrentSprite
    ldr r1, lbl_0801a30c @ =0x082cac6c
    str r1, [r0, #0x18]
    movs r1, #0
    strb r1, [r0, #0x1c]
    strh r1, [r0, #0x16]
lbl_0801a300:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801a308: .4byte gCurrentSprite
lbl_0801a30c: .4byte 0x082cac6c

    thumb_func_start KraidPartCheckAttack
KraidPartCheckAttack: @ 0x0801a310
    push {r4, r5, r6, r7, lr}
    ldr r5, lbl_0801a350 @ =gCurrentSprite
    adds r0, r5, #0
    adds r0, #0x23
    ldrb r6, [r0]
    movs r3, #0
    movs r7, #0
    ldr r1, lbl_0801a354 @ =gSpriteData
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r4, r0, r1
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a360
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801a3c4
    ldrh r1, [r4]
    ldr r0, lbl_0801a358 @ =0x0000f7ff
    ands r0, r1
    movs r1, #0
    strh r0, [r4]
    ldr r0, lbl_0801a35c @ =0x082cadd4
    str r0, [r5, #0x18]
    strb r1, [r5, #0x1c]
    strh r7, [r5, #0x16]
    b lbl_0801a3c4
    .align 2, 0
lbl_0801a350: .4byte gCurrentSprite
lbl_0801a354: .4byte gSpriteData
lbl_0801a358: .4byte 0x0000f7ff
lbl_0801a35c: .4byte 0x082cadd4
lbl_0801a360:
    adds r4, r5, #0
    adds r4, #0x2c
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0801a36e
    subs r0, #1
    b lbl_0801a37c
lbl_0801a36e:
    movs r1, #0x88
    lsls r1, r1, #2
    movs r0, #0x80
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    adds r3, r0, #0
    movs r0, #0xb4
lbl_0801a37c:
    strb r0, [r4]
    ldr r0, lbl_0801a3cc @ =gSubSpriteData1
    ldrh r2, [r0, #0xa]
    ldr r0, lbl_0801a3d0 @ =0x082b0d68
    ldr r1, lbl_0801a3d4 @ =0x000007ce
    adds r0, r0, r1
    ldrh r1, [r0]
    lsrs r1, r1, #2
    lsls r0, r1, #1
    adds r0, r0, r1
    cmp r2, r0
    bge lbl_0801a39e
    cmp r3, #8
    bne lbl_0801a39e
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0801a39e:
    cmp r7, #0
    beq lbl_0801a3c4
    ldr r1, lbl_0801a3d8 @ =gCurrentSprite
    ldr r0, lbl_0801a3dc @ =0x082cae2c
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    ldr r0, lbl_0801a3e0 @ =gSpriteData
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
lbl_0801a3c4:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801a3cc: .4byte gSubSpriteData1
lbl_0801a3d0: .4byte 0x082b0d68
lbl_0801a3d4: .4byte 0x000007ce
lbl_0801a3d8: .4byte gCurrentSprite
lbl_0801a3dc: .4byte 0x082cae2c
lbl_0801a3e0: .4byte gSpriteData

    thumb_func_start raid_mouth_call_kraid_check_prokectiles_colliding_with_belly
raid_mouth_call_kraid_check_prokectiles_colliding_with_belly: @ 0x0801a3e4
    push {lr}
    bl KraidCheckProjectilesCollidingWithBelly
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start KraidPartCheckShouldSpawnSpikes
KraidPartCheckShouldSpawnSpikes: @ 0x0801a3f0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r6, lbl_0801a4b4 @ =gCurrentSprite
    adds r0, r6, #0
    adds r0, #0x23
    ldrb r7, [r0]
    ldrb r0, [r6, #0x1e]
    mov r8, r0
    mov sl, r8
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    ldr r1, lbl_0801a4b8 @ =gSpriteData
    adds r4, r0, r1
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_0801a4fe
    bl KraidCheckProjectilesCollidingWithBelly
    ldr r2, lbl_0801a4bc @ =gSubSpriteData1
    mov sb, r2
    ldr r0, lbl_0801a4c0 @ =0x082b0d68
    ldr r1, lbl_0801a4c4 @ =0x000007ce
    adds r0, r0, r1
    ldrh r5, [r0]
    adds r0, r5, #0
    movs r1, #3
    bl __udivsi3
    mov r2, sb
    ldrh r1, [r2, #0xa]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0
    cmp r1, r0
    bhs lbl_0801a444
    movs r2, #1
lbl_0801a444:
    mov r0, r8
    cmp r0, #7
    bne lbl_0801a4d0
    mov r1, sb
    ldrh r2, [r1, #0xa]
    lsrs r1, r5, #2
    lsls r0, r1, #1
    adds r0, r0, r1
    cmp r2, r0
    blt lbl_0801a464
    ldr r0, lbl_0801a4c8 @ =gSamusData
    ldrh r1, [r0, #0x14]
    ldrh r0, [r6, #2]
    subs r0, #0x80
    cmp r1, r0
    blt lbl_0801a4fe
lbl_0801a464:
    movs r5, #0x1c
    movs r3, #0
    ldr r6, lbl_0801a4b8 @ =gSpriteData
    adds r4, r6, #0
lbl_0801a46c:
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r2, r0, r4
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a492
    adds r0, r2, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a492
    ldrb r0, [r2, #0x1d]
    cmp r0, r5
    beq lbl_0801a4fe
lbl_0801a492:
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0x17
    bls lbl_0801a46c
    lsls r1, r7, #3
    subs r1, r1, r7
    lsls r1, r1, #3
    adds r1, r1, r6
    ldrh r2, [r1]
    ldr r0, lbl_0801a4cc @ =0x0000ffdf
    ands r0, r2
    strh r0, [r1]
    ldr r1, lbl_0801a4b4 @ =gCurrentSprite
    movs r0, #1
    strh r0, [r1, #6]
    b lbl_0801a4f8
    .align 2, 0
lbl_0801a4b4: .4byte gCurrentSprite
lbl_0801a4b8: .4byte gSpriteData
lbl_0801a4bc: .4byte gSubSpriteData1
lbl_0801a4c0: .4byte 0x082b0d68
lbl_0801a4c4: .4byte 0x000007ce
lbl_0801a4c8: .4byte gSamusData
lbl_0801a4cc: .4byte 0x0000ffdf
lbl_0801a4d0:
    mov r0, sl
    cmp r0, #4
    bne lbl_0801a4e4
    ldrh r1, [r4]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0801a4fe
    movs r0, #0x3c
    b lbl_0801a4f4
lbl_0801a4e4:
    ldrh r1, [r4]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_0801a4fe
    cmp r2, #0
    beq lbl_0801a4fe
    movs r0, #0x78
lbl_0801a4f4:
    strh r0, [r6, #6]
    adds r1, r6, #0
lbl_0801a4f8:
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
lbl_0801a4fe:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start KraidMouthSpawnSpike
KraidMouthSpawnSpike: @ 0x0801a50c
    push {r4, r5, r6, r7, lr}
    sub sp, #0xc
    bl KraidCheckProjectilesCollidingWithBelly
    ldr r4, lbl_0801a590 @ =gCurrentSprite
    ldrh r0, [r4, #6]
    subs r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    cmp r6, #0
    bne lbl_0801a586
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r2, [r0]
    adds r7, r2, #0
    ldrb r0, [r4, #0x1e]
    adds r5, r0, #0
    cmp r5, #7
    bne lbl_0801a546
    ldr r1, lbl_0801a594 @ =gSpriteData
    lsls r0, r2, #3
    subs r0, r0, r2
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strh r1, [r0]
lbl_0801a546:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x1c
    adds r1, r5, #0
    bl SpriteSpawnSecondary
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x17
    bhi lbl_0801a57e
    ldr r2, lbl_0801a594 @ =gSpriteData
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r2
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrh r0, [r0, #8]
    strh r0, [r1, #8]
lbl_0801a57e:
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
lbl_0801a586:
    add sp, #0xc
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801a590: .4byte gCurrentSprite
lbl_0801a594: .4byte gSpriteData

    thumb_func_start KraidPartDyingInit
KraidPartDyingInit: @ 0x0801a598
    push {lr}
    ldr r1, lbl_0801a5b0 @ =gCurrentSprite
    ldrb r0, [r1, #0x1e]
    adds r2, r1, #0
    cmp r0, #0xb
    bhi lbl_0801a63c
    lsls r0, r0, #2
    ldr r1, lbl_0801a5b4 @ =lbl_0801a5b8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801a5b0: .4byte gCurrentSprite
lbl_0801a5b4: .4byte lbl_0801a5b8
lbl_0801a5b8: @ jump table
    .4byte lbl_0801a63c @ case 0
    .4byte lbl_0801a5e8 @ case 1
    .4byte lbl_0801a634 @ case 2
    .4byte lbl_0801a634 @ case 3
    .4byte lbl_0801a634 @ case 4
    .4byte lbl_0801a634 @ case 5
    .4byte lbl_0801a63c @ case 6
    .4byte lbl_0801a634 @ case 7
    .4byte lbl_0801a634 @ case 8
    .4byte lbl_0801a628 @ case 9
    .4byte lbl_0801a60c @ case 10
    .4byte lbl_0801a63c @ case 11
lbl_0801a5e8:
    ldr r0, lbl_0801a608 @ =0x082cacc4
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
    movs r0, #0xc8
    lsls r0, r0, #1
    strh r0, [r2, #6]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    subs r1, #2
    movs r0, #0xa
    b lbl_0801a642
    .align 2, 0
lbl_0801a608: .4byte 0x082cacc4
lbl_0801a60c:
    ldr r0, lbl_0801a624 @ =0x082cae94
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
    movs r0, #0xc8
    lsls r0, r0, #1
    strh r0, [r2, #6]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x67
    b lbl_0801a642
    .align 2, 0
lbl_0801a624: .4byte 0x082cae94
lbl_0801a628:
    adds r1, r2, #0
    adds r1, #0x22
    movs r0, #0xa
    strb r0, [r1]
    adds r1, #2
    b lbl_0801a640
lbl_0801a634:
    ldrh r1, [r2]
    movs r0, #4
    orrs r0, r1
    strh r0, [r2]
lbl_0801a63c:
    adds r1, r2, #0
    adds r1, #0x24
lbl_0801a640:
    movs r0, #0x68
lbl_0801a642:
    strb r0, [r1]
    pop {r0}
    bx r0

    thumb_func_start KraidPartDyingSinking
KraidPartDyingSinking: @ 0x0801a648
    push {r4, r5, lr}
    ldr r4, lbl_0801a66c @ =gCurrentSprite
    ldrh r0, [r4, #6]
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_0801a670
    subs r0, #1
    strh r0, [r4, #6]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0xa
    beq lbl_0801a662
    cmp r0, #1
    bne lbl_0801a6bc
lbl_0801a662:
    ldrb r0, [r4, #0x1c]
    adds r0, #1
    strb r0, [r4, #0x1c]
    b lbl_0801a6bc
    .align 2, 0
lbl_0801a66c: .4byte gCurrentSprite
lbl_0801a670:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0xa
    bne lbl_0801a694
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801a6bc
    ldr r0, lbl_0801a690 @ =0x082cadd4
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x27
    movs r0, #0x28
    b lbl_0801a6ae
    .align 2, 0
lbl_0801a690: .4byte 0x082cadd4
lbl_0801a694:
    cmp r0, #1
    bne lbl_0801a6bc
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0801a6bc
    ldr r0, lbl_0801a6c4 @ =0x082cac6c
    str r0, [r4, #0x18]
    strb r5, [r4, #0x1c]
    strh r5, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x27
    movs r0, #0x40
lbl_0801a6ae:
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    subs r1, #4
    movs r0, #0x68
    strb r0, [r1]
lbl_0801a6bc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801a6c4: .4byte 0x082cac6c

    thumb_func_start KraidPartDyingStationary
KraidPartDyingStationary: @ 0x0801a6c8
    push {lr}
    sub sp, #4
    ldr r0, lbl_0801a70c @ =gCurrentSprite
    ldrb r1, [r0, #0x1e]
    adds r3, r0, #0
    cmp r1, #0xa
    beq lbl_0801a6da
    cmp r1, #1
    bne lbl_0801a6e0
lbl_0801a6da:
    ldrb r0, [r3, #0x1c]
    adds r0, #2
    strb r0, [r3, #0x1c]
lbl_0801a6e0:
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r2, lbl_0801a710 @ =gSpriteData
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #0x1d]
    cmp r0, #0x6f
    bne lbl_0801a6f8
    b lbl_0801a848
lbl_0801a6f8:
    ldrb r0, [r3, #0x1e]
    cmp r0, #0xb
    bls lbl_0801a700
    b lbl_0801a844
lbl_0801a700:
    lsls r0, r0, #2
    ldr r1, lbl_0801a714 @ =lbl_0801a718
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801a70c: .4byte gCurrentSprite
lbl_0801a710: .4byte gSpriteData
lbl_0801a714: .4byte lbl_0801a718
lbl_0801a718: @ jump table
    .4byte lbl_0801a748 @ case 0
    .4byte lbl_0801a7e8 @ case 1
    .4byte lbl_0801a75c @ case 2
    .4byte lbl_0801a770 @ case 3
    .4byte lbl_0801a788 @ case 4
    .4byte lbl_0801a7a4 @ case 5
    .4byte lbl_0801a844 @ case 6
    .4byte lbl_0801a7bc @ case 7
    .4byte lbl_0801a7d0 @ case 8
    .4byte lbl_0801a810 @ case 9
    .4byte lbl_0801a7f8 @ case 10
    .4byte lbl_0801a828 @ case 11
lbl_0801a748:
    ldr r0, lbl_0801a758 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0x40
    ldrh r2, [r0, #8]
    subs r2, #0x80
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a758: .4byte gSubSpriteData1
lbl_0801a75c:
    ldr r0, lbl_0801a76c @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0x80
    ldrh r2, [r0, #8]
    movs r0, #0x80
    lsls r0, r0, #1
    adds r2, r2, r0
    b lbl_0801a832
    .align 2, 0
lbl_0801a76c: .4byte gSubSpriteData1
lbl_0801a770:
    ldr r0, lbl_0801a780 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0xc0
    ldrh r2, [r0, #8]
    ldr r0, lbl_0801a784 @ =0xfffffe80
    adds r2, r2, r0
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a780: .4byte gSubSpriteData1
lbl_0801a784: .4byte 0xfffffe80
lbl_0801a788:
    ldr r0, lbl_0801a79c @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    ldr r2, lbl_0801a7a0 @ =0xffffff00
    adds r1, r1, r2
    ldrh r2, [r0, #8]
    movs r0, #0x80
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a79c: .4byte gSubSpriteData1
lbl_0801a7a0: .4byte 0xffffff00
lbl_0801a7a4:
    ldr r0, lbl_0801a7b4 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    ldr r2, lbl_0801a7b8 @ =0xfffffec0
    adds r1, r1, r2
    ldrh r2, [r0, #8]
    subs r2, #0x40
    movs r0, #0x22
    b lbl_0801a834
    .align 2, 0
lbl_0801a7b4: .4byte gSubSpriteData1
lbl_0801a7b8: .4byte 0xfffffec0
lbl_0801a7bc:
    ldr r0, lbl_0801a7cc @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0x40
    ldrh r2, [r0, #8]
    adds r2, #0xc0
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a7cc: .4byte gSubSpriteData1
lbl_0801a7d0:
    ldr r0, lbl_0801a7e0 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0x80
    ldrh r2, [r0, #8]
    ldr r0, lbl_0801a7e4 @ =0xfffffec0
    adds r2, r2, r0
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a7e0: .4byte gSubSpriteData1
lbl_0801a7e4: .4byte 0xfffffec0
lbl_0801a7e8:
    ldr r0, lbl_0801a7f4 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0xc0
    ldrh r2, [r0, #8]
    adds r2, #0xc0
    b lbl_0801a832
    .align 2, 0
lbl_0801a7f4: .4byte gSubSpriteData1
lbl_0801a7f8:
    ldr r0, lbl_0801a808 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    ldr r2, lbl_0801a80c @ =0xffffff00
    adds r1, r1, r2
    ldrh r2, [r0, #8]
    subs r2, #0x40
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a808: .4byte gSubSpriteData1
lbl_0801a80c: .4byte 0xffffff00
lbl_0801a810:
    ldr r0, lbl_0801a820 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    ldr r2, lbl_0801a824 @ =0xfffffec0
    adds r1, r1, r2
    ldrh r2, [r0, #8]
    adds r2, #0x80
    movs r0, #0x20
    b lbl_0801a834
    .align 2, 0
lbl_0801a820: .4byte gSubSpriteData1
lbl_0801a824: .4byte 0xfffffec0
lbl_0801a828:
    ldr r0, lbl_0801a840 @ =gSubSpriteData1
    ldrh r1, [r0, #6]
    subs r1, #0x40
    ldrh r2, [r0, #8]
    subs r2, #0xc0
lbl_0801a832:
    movs r0, #0x21
lbl_0801a834:
    str r0, [sp]
    movs r0, #0
    movs r3, #0
    bl SpriteUtilSpriteDeath
    b lbl_0801a848
    .align 2, 0
lbl_0801a840: .4byte gSubSpriteData1
lbl_0801a844:
    movs r0, #0
    strh r0, [r3]
lbl_0801a848:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start KraidNailMovement
KraidNailMovement: @ 0x0801a850
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    movs r0, #4
    str r0, [sp]
    ldr r0, lbl_0801a888 @ =gDifficulty
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0801a86c
    movs r1, #8
    str r1, [sp]
lbl_0801a86c:
    ldr r1, lbl_0801a88c @ =gCurrentSprite
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r5, r1, #0
    cmp r0, #0
    bne lbl_0801a890
    strh r0, [r5]
    b lbl_0801aa2a
    .align 2, 0
lbl_0801a888: .4byte gDifficulty
lbl_0801a88c: .4byte gCurrentSprite
lbl_0801a890:
    ldr r1, [sp]
    muls r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp]
    adds r0, r5, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    lsls r0, r0, #6
    str r0, [sp, #8]
    adds r0, r5, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    lsls r0, r0, #6
    str r0, [sp, #4]
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a8c6
    ldrh r0, [r5, #6]
    ldr r1, [sp, #8]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    b lbl_0801a8d0
lbl_0801a8c6:
    ldrh r0, [r5, #6]
    ldr r1, [sp, #8]
    subs r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
lbl_0801a8d0:
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a8ea
    ldrh r0, [r5, #8]
    ldr r1, [sp, #4]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    b lbl_0801a8f6
lbl_0801a8ea:
    ldrh r0, [r5, #8]
    ldr r1, [sp, #4]
    subs r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
lbl_0801a8f6:
    mov sl, r5
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a996
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a952
    mov r1, sb
    mov r0, sb
    muls r0, r1, r0
    adds r1, r7, #0
    muls r1, r7, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    bne lbl_0801a928
    b lbl_0801aa2a
lbl_0801a928:
    lsls r0, r7, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #8]
    adds r0, r1, r0
    strh r0, [r5, #2]
    mov r1, sb
    lsls r0, r1, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #4]
    adds r0, r1, r0
    b lbl_0801aa28
lbl_0801a952:
    mov r1, sb
    mov r0, sb
    muls r0, r1, r0
    adds r1, r6, #0
    muls r1, r6, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0801aa2a
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #8]
    subs r0, r1, r0
    mov r1, sl
    strh r0, [r1, #2]
    mov r1, sb
    lsls r0, r1, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #4]
    adds r0, r1, r0
    b lbl_0801a9e2
lbl_0801a996:
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801a9e8
    mov r1, r8
    mov r0, r8
    muls r0, r1, r0
    adds r1, r7, #0
    muls r1, r7, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0801aa2a
    lsls r0, r7, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #8]
    adds r0, r1, r0
    mov r1, sl
    strh r0, [r1, #2]
    mov r1, r8
    lsls r0, r1, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #4]
    subs r0, r1, r0
lbl_0801a9e2:
    mov r1, sl
    strh r0, [r1, #4]
    b lbl_0801aa2a
lbl_0801a9e8:
    mov r1, r8
    mov r0, r8
    muls r0, r1, r0
    adds r1, r6, #0
    muls r1, r6, r1
    adds r0, r0, r1
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0801aa2a
    lsls r0, r6, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #8]
    subs r0, r1, r0
    strh r0, [r5, #2]
    mov r1, r8
    lsls r0, r1, #0xa
    adds r1, r4, #0
    bl __divsi3
    ldr r1, [sp]
    muls r0, r1, r0
    asrs r0, r0, #0xa
    ldr r1, [sp, #4]
    subs r0, r1, r0
lbl_0801aa28:
    strh r0, [r5, #4]
lbl_0801aa2a:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start Kraid
Kraid: @ 0x0801aa3c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0801aa6c @ =gCurrentSprite
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801aa54
    ldr r0, lbl_0801aa70 @ =gSubSpriteData1
    ldrh r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_0801aa54
    bl KraidOpenCloseRoutineAndProjectileCollision
lbl_0801aa54:
    ldr r0, lbl_0801aa6c @ =gCurrentSprite
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x68
    bls lbl_0801aa60
    b lbl_0801ac64
lbl_0801aa60:
    lsls r0, r0, #2
    ldr r1, lbl_0801aa74 @ =lbl_0801aa78
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0801aa6c: .4byte gCurrentSprite
lbl_0801aa70: .4byte gSubSpriteData1
lbl_0801aa74: .4byte lbl_0801aa78
lbl_0801aa78: @ jump table
    .4byte lbl_0801ac1c @ case 0
    .4byte lbl_0801ac22 @ case 1
    .4byte lbl_0801ac28 @ case 2
    .4byte lbl_0801ac64 @ case 3
    .4byte lbl_0801ac64 @ case 4
    .4byte lbl_0801ac64 @ case 5
    .4byte lbl_0801ac64 @ case 6
    .4byte lbl_0801ac64 @ case 7
    .4byte lbl_0801ac2e @ case 8
    .4byte lbl_0801ac32 @ case 9
    .4byte lbl_0801ac64 @ case 10
    .4byte lbl_0801ac64 @ case 11
    .4byte lbl_0801ac64 @ case 12
    .4byte lbl_0801ac64 @ case 13
    .4byte lbl_0801ac42 @ case 14
    .4byte lbl_0801ac46 @ case 15
    .4byte lbl_0801ac4c @ case 16
    .4byte lbl_0801ac50 @ case 17
    .4byte lbl_0801ac64 @ case 18
    .4byte lbl_0801ac64 @ case 19
    .4byte lbl_0801ac64 @ case 20
    .4byte lbl_0801ac64 @ case 21
    .4byte lbl_0801ac64 @ case 22
    .4byte lbl_0801ac64 @ case 23
    .4byte lbl_0801ac64 @ case 24
    .4byte lbl_0801ac64 @ case 25
    .4byte lbl_0801ac64 @ case 26
    .4byte lbl_0801ac64 @ case 27
    .4byte lbl_0801ac64 @ case 28
    .4byte lbl_0801ac64 @ case 29
    .4byte lbl_0801ac64 @ case 30
    .4byte lbl_0801ac64 @ case 31
    .4byte lbl_0801ac64 @ case 32
    .4byte lbl_0801ac64 @ case 33
    .4byte lbl_0801ac38 @ case 34
    .4byte lbl_0801ac3c @ case 35
    .4byte lbl_0801ac64 @ case 36
    .4byte lbl_0801ac64 @ case 37
    .4byte lbl_0801ac64 @ case 38
    .4byte lbl_0801ac64 @ case 39
    .4byte lbl_0801ac64 @ case 40
    .4byte lbl_0801ac64 @ case 41
    .4byte lbl_0801ac64 @ case 42
    .4byte lbl_0801ac64 @ case 43
    .4byte lbl_0801ac64 @ case 44
    .4byte lbl_0801ac64 @ case 45
    .4byte lbl_0801ac64 @ case 46
    .4byte lbl_0801ac64 @ case 47
    .4byte lbl_0801ac64 @ case 48
    .4byte lbl_0801ac64 @ case 49
    .4byte lbl_0801ac64 @ case 50
    .4byte lbl_0801ac64 @ case 51
    .4byte lbl_0801ac64 @ case 52
    .4byte lbl_0801ac64 @ case 53
    .4byte lbl_0801ac64 @ case 54
    .4byte lbl_0801ac64 @ case 55
    .4byte lbl_0801ac64 @ case 56
    .4byte lbl_0801ac64 @ case 57
    .4byte lbl_0801ac64 @ case 58
    .4byte lbl_0801ac64 @ case 59
    .4byte lbl_0801ac64 @ case 60
    .4byte lbl_0801ac64 @ case 61
    .4byte lbl_0801ac64 @ case 62
    .4byte lbl_0801ac64 @ case 63
    .4byte lbl_0801ac64 @ case 64
    .4byte lbl_0801ac64 @ case 65
    .4byte lbl_0801ac64 @ case 66
    .4byte lbl_0801ac64 @ case 67
    .4byte lbl_0801ac64 @ case 68
    .4byte lbl_0801ac64 @ case 69
    .4byte lbl_0801ac64 @ case 70
    .4byte lbl_0801ac64 @ case 71
    .4byte lbl_0801ac64 @ case 72
    .4byte lbl_0801ac64 @ case 73
    .4byte lbl_0801ac64 @ case 74
    .4byte lbl_0801ac64 @ case 75
    .4byte lbl_0801ac64 @ case 76
    .4byte lbl_0801ac64 @ case 77
    .4byte lbl_0801ac64 @ case 78
    .4byte lbl_0801ac64 @ case 79
    .4byte lbl_0801ac64 @ case 80
    .4byte lbl_0801ac64 @ case 81
    .4byte lbl_0801ac64 @ case 82
    .4byte lbl_0801ac64 @ case 83
    .4byte lbl_0801ac64 @ case 84
    .4byte lbl_0801ac64 @ case 85
    .4byte lbl_0801ac64 @ case 86
    .4byte lbl_0801ac64 @ case 87
    .4byte lbl_0801ac64 @ case 88
    .4byte lbl_0801ac64 @ case 89
    .4byte lbl_0801ac64 @ case 90
    .4byte lbl_0801ac64 @ case 91
    .4byte lbl_0801ac64 @ case 92
    .4byte lbl_0801ac64 @ case 93
    .4byte lbl_0801ac64 @ case 94
    .4byte lbl_0801ac64 @ case 95
    .4byte lbl_0801ac64 @ case 96
    .4byte lbl_0801ac64 @ case 97
    .4byte lbl_0801ac56 @ case 98
    .4byte lbl_0801ac64 @ case 99
    .4byte lbl_0801ac64 @ case 100
    .4byte lbl_0801ac64 @ case 101
    .4byte lbl_0801ac64 @ case 102
    .4byte lbl_0801ac5a @ case 103
    .4byte lbl_0801ac60 @ case 104
lbl_0801ac1c:
    bl KraidInit
    b lbl_0801ac64
lbl_0801ac22:
    bl KraidGoUp
    b lbl_0801ac64
lbl_0801ac28:
    bl KraidCheckFullyUp
    b lbl_0801ac64
lbl_0801ac2e:
    bl KraidFirstStepInit
lbl_0801ac32:
    bl kraid_feet_movement_same_direction_as_pos_update
    b lbl_0801ac64
lbl_0801ac38:
    bl KraidMoveFeet_to_opposite_direction_as_pos
lbl_0801ac3c:
    bl kraid_feet_movement_oppsite_direction_as_pos_update
    b lbl_0801ac64
lbl_0801ac42:
    bl KraidStandingInit
lbl_0801ac46:
    bl KraidStanding
    b lbl_0801ac64
lbl_0801ac4c:
    bl kraid_after_moving_feet_same_direction_as_pos
lbl_0801ac50:
    bl kraid_before_start_moving_feet_opposite_direction_as_pos
    b lbl_0801ac64
lbl_0801ac56:
    bl KraidDyingInit
lbl_0801ac5a:
    bl KraidDying
    b lbl_0801ac64
lbl_0801ac60:
    bl KraidBeforeDeath
lbl_0801ac64:
    ldr r5, lbl_0801acac @ =gCurrentSprite
    ldrb r0, [r5, #0x1d]
    cmp r0, #0x6f
    beq lbl_0801ac6e
    b lbl_0801aea0
lbl_0801ac6e:
    bl SpriteUtilUpdateSubSprite1Anim
    bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
    ldr r6, lbl_0801acb0 @ =gSubSpriteData1
    ldrb r0, [r6, #0xc]
    cmp r0, #1
    beq lbl_0801ac80
    b lbl_0801ae26
lbl_0801ac80:
    ldr r1, [r6]
    ldr r0, lbl_0801acb4 @ =0x082c61f0
    cmp r1, r0
    beq lbl_0801ac94
    ldr r0, lbl_0801acb8 @ =0x082c6200
    cmp r1, r0
    beq lbl_0801ac94
    ldr r0, lbl_0801acbc @ =0x082c6220
    cmp r1, r0
    bne lbl_0801acc4
lbl_0801ac94:
    ldrh r0, [r6, #4]
    cmp r0, #1
    bne lbl_0801ac9c
    b lbl_0801ad98
lbl_0801ac9c:
    cmp r0, #2
    beq lbl_0801aca2
    b lbl_0801ae26
lbl_0801aca2:
    ldr r1, lbl_0801acc0 @ =gBG2Movement
    ldrh r0, [r1, #2]
    adds r0, #4
    strh r0, [r1, #2]
    b lbl_0801ae26
    .align 2, 0
lbl_0801acac: .4byte gCurrentSprite
lbl_0801acb0: .4byte gSubSpriteData1
lbl_0801acb4: .4byte 0x082c61f0
lbl_0801acb8: .4byte 0x082c6200
lbl_0801acbc: .4byte 0x082c6220
lbl_0801acc0: .4byte gBG2Movement
lbl_0801acc4:
    ldr r4, lbl_0801ace8 @ =0x082c6240
    cmp r1, r4
    beq lbl_0801acd0
    ldr r0, lbl_0801acec @ =0x082c62e8
    cmp r1, r0
    bne lbl_0801ad64
lbl_0801acd0:
    ldrh r0, [r6, #4]
    cmp r0, #1
    beq lbl_0801acde
    cmp r0, #2
    beq lbl_0801acde
    cmp r0, #3
    bne lbl_0801acf4
lbl_0801acde:
    ldr r1, lbl_0801acf0 @ =gBG2Movement
    ldrh r0, [r1]
    subs r0, #4
    strh r0, [r1]
    b lbl_0801ae26
    .align 2, 0
lbl_0801ace8: .4byte 0x082c6240
lbl_0801acec: .4byte 0x082c62e8
lbl_0801acf0: .4byte gBG2Movement
lbl_0801acf4:
    cmp r0, #4
    beq lbl_0801ad98
    cmp r0, #5
    beq lbl_0801acfe
    b lbl_0801ae26
lbl_0801acfe:
    ldr r1, lbl_0801ad38 @ =gBG2Movement
    ldrh r0, [r1, #2]
    adds r0, #4
    strh r0, [r1, #2]
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0xe6
    lsls r0, r0, #1
    bl SoundPlay
    ldr r0, [r6]
    cmp r0, r4
    bne lbl_0801ad3c
    ldrh r0, [r5, #6]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    subs r1, #0x2c
    movs r2, #0x38
    bl ParticleSet
    ldrh r0, [r5, #6]
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    subs r1, #0x90
    b lbl_0801ade8
    .align 2, 0
lbl_0801ad38: .4byte gBG2Movement
lbl_0801ad3c:
    ldr r5, lbl_0801ad60 @ =gCurrentSprite
    ldrh r0, [r5, #6]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    adds r1, #0xec
    movs r2, #0x38
    bl ParticleSet
    ldrh r0, [r5, #6]
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    movs r2, #0xa8
    lsls r2, r2, #1
    adds r1, r1, r2
    b lbl_0801ade8
    .align 2, 0
lbl_0801ad60: .4byte gCurrentSprite
lbl_0801ad64:
    ldr r0, lbl_0801ad88 @ =0x082c6278
    cmp r1, r0
    beq lbl_0801ad70
    ldr r0, lbl_0801ad8c @ =0x082c62b0
    cmp r1, r0
    bne lbl_0801ae26
lbl_0801ad70:
    ldrh r0, [r6, #4]
    cmp r0, #1
    beq lbl_0801ad7e
    cmp r0, #2
    beq lbl_0801ad7e
    cmp r0, #3
    bne lbl_0801ad94
lbl_0801ad7e:
    ldr r1, lbl_0801ad90 @ =gBG2Movement
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    b lbl_0801ae26
    .align 2, 0
lbl_0801ad88: .4byte 0x082c6278
lbl_0801ad8c: .4byte 0x082c62b0
lbl_0801ad90: .4byte gBG2Movement
lbl_0801ad94:
    cmp r0, #4
    bne lbl_0801ada8
lbl_0801ad98:
    ldr r1, lbl_0801ada4 @ =gBG2Movement
    ldrh r0, [r1, #2]
    subs r0, #4
    strh r0, [r1, #2]
    b lbl_0801ae26
    .align 2, 0
lbl_0801ada4: .4byte gBG2Movement
lbl_0801ada8:
    cmp r0, #5
    bne lbl_0801ae26
    ldr r1, lbl_0801adf0 @ =gBG2Movement
    ldrh r0, [r1, #2]
    adds r0, #4
    strh r0, [r1, #2]
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0xe6
    lsls r0, r0, #1
    bl SoundPlay
    ldr r1, [r6]
    ldr r0, lbl_0801adf4 @ =0x082c62b0
    cmp r1, r0
    bne lbl_0801adfc
    ldr r5, lbl_0801adf8 @ =gCurrentSprite
    ldrh r0, [r5, #6]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    subs r1, #0x64
    movs r2, #0x38
    bl ParticleSet
    ldrh r0, [r5, #6]
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    subs r1, #0xc8
lbl_0801ade8:
    movs r2, #0x38
    bl ParticleSet
    b lbl_0801ae26
    .align 2, 0
lbl_0801adf0: .4byte gBG2Movement
lbl_0801adf4: .4byte 0x082c62b0
lbl_0801adf8: .4byte gCurrentSprite
lbl_0801adfc:
    ldr r5, lbl_0801ae74 @ =gCurrentSprite
    ldrh r0, [r5, #6]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    movs r3, #0x85
    lsls r3, r3, #1
    adds r1, r1, r3
    movs r2, #0x38
    bl ParticleSet
    ldrh r0, [r5, #6]
    adds r0, r0, r4
    ldrh r1, [r6, #8]
    movs r2, #0xb7
    lsls r2, r2, #1
    adds r1, r1, r2
    movs r2, #0x38
    bl ParticleSet
lbl_0801ae26:
    ldr r1, lbl_0801ae78 @ =gSubSpriteData1
    ldrb r0, [r1, #0xd]
    cmp r0, #0
    beq lbl_0801ae34
    ldrb r0, [r1, #0xc]
    adds r0, #4
    strb r0, [r1, #0xc]
lbl_0801ae34:
    ldr r1, lbl_0801ae7c @ =gLockScreen
    movs r0, #1
    strb r0, [r1]
    ldr r2, lbl_0801ae80 @ =gSamusData
    ldrh r0, [r2, #0x14]
    strh r0, [r1, #4]
    ldr r3, lbl_0801ae84 @ =0xfffffec0
    adds r0, r3, #0
    ldrh r2, [r2, #0x12]
    adds r0, r0, r2
    strh r0, [r1, #2]
    ldr r3, lbl_0801ae74 @ =gCurrentSprite
    adds r0, r3, #0
    adds r0, #0x20
    ldrb r2, [r0]
    adds r0, #0x13
    ldrb r1, [r0]
    movs r0, #0xe
    subs r0, r0, r1
    cmp r2, r0
    bne lbl_0801ae88
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0801aea6
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r3]
    b lbl_0801aea6
    .align 2, 0
lbl_0801ae74: .4byte gCurrentSprite
lbl_0801ae78: .4byte gSubSpriteData1
lbl_0801ae7c: .4byte gLockScreen
lbl_0801ae80: .4byte gSamusData
lbl_0801ae84: .4byte 0xfffffec0
lbl_0801ae88:
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0801aea6
    ldr r0, lbl_0801ae9c @ =0x0000fbff
    ands r0, r1
    strh r0, [r3]
    b lbl_0801aea6
    .align 2, 0
lbl_0801ae9c: .4byte 0x0000fbff
lbl_0801aea0:
    ldr r1, lbl_0801aeac @ =gLockScreen
    movs r0, #0
    strb r0, [r1]
lbl_0801aea6:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801aeac: .4byte gLockScreen

    thumb_func_start KraidPart
KraidPart: @ 0x0801aeb0
    push {r4, lr}
    ldr r3, lbl_0801af18 @ =gCurrentSprite
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r2, lbl_0801af1c @ =gSpriteData
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    adds r0, #0x34
    ldrb r1, [r0]
    adds r0, r3, #0
    adds r0, #0x34
    strb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    ldr r0, lbl_0801af20 @ =gSubSpriteData1
    ldrh r0, [r0, #0xa]
    cmp r0, #0
    bne lbl_0801aefa
    adds r1, r3, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    subs r1, #2
    ldrb r0, [r1]
    cmp r0, #0x61
    bhi lbl_0801aefa
    movs r0, #0x62
    strb r0, [r1]
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r3]
lbl_0801aefa:
    ldr r0, lbl_0801af18 @ =gCurrentSprite
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    beq lbl_0801af5e
    cmp r0, #0x43
    bgt lbl_0801af2e
    cmp r0, #0x10
    beq lbl_0801af4c
    cmp r0, #0x10
    bgt lbl_0801af24
    cmp r0, #0
    beq lbl_0801af46
    b lbl_0801af7a
    .align 2, 0
lbl_0801af18: .4byte gCurrentSprite
lbl_0801af1c: .4byte gSpriteData
lbl_0801af20: .4byte gSubSpriteData1
lbl_0801af24:
    cmp r0, #0x12
    beq lbl_0801af52
    cmp r0, #0x42
    beq lbl_0801af58
    b lbl_0801af7a
lbl_0801af2e:
    cmp r0, #0x62
    beq lbl_0801af6a
    cmp r0, #0x62
    bgt lbl_0801af3c
    cmp r0, #0x44
    beq lbl_0801af64
    b lbl_0801af7a
lbl_0801af3c:
    cmp r0, #0x67
    beq lbl_0801af70
    cmp r0, #0x68
    beq lbl_0801af76
    b lbl_0801af7a
lbl_0801af46:
    bl KraidPartInit
    b lbl_0801af7a
lbl_0801af4c:
    bl KraidPartThrowNails
    b lbl_0801af7a
lbl_0801af52:
    bl KraidPartCheckAttack
    b lbl_0801af7a
lbl_0801af58:
    bl KraidPartCheckShouldSpawnSpikes
    b lbl_0801af7a
lbl_0801af5e:
    bl KraidMouthSpawnSpike
    b lbl_0801af7a
lbl_0801af64:
    bl raid_mouth_call_kraid_check_prokectiles_colliding_with_belly
    b lbl_0801af7a
lbl_0801af6a:
    bl KraidPartDyingInit
    b lbl_0801af7a
lbl_0801af70:
    bl KraidPartDyingSinking
    b lbl_0801af7a
lbl_0801af76:
    bl KraidPartDyingStationary
lbl_0801af7a:
    ldr r4, lbl_0801af98 @ =gCurrentSprite
    ldrb r0, [r4, #0x1d]
    cmp r0, #3
    bne lbl_0801b03c
    ldrb r2, [r4, #0x1e]
    cmp r2, #0xa
    bne lbl_0801afca
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0801af9c @ =0x082cadd4
    cmp r1, r0
    bne lbl_0801afa0
    bl KraidPartUpdateRightArmIdlingHitbox
    b lbl_0801b016
    .align 2, 0
lbl_0801af98: .4byte gCurrentSprite
lbl_0801af9c: .4byte 0x082cadd4
lbl_0801afa0:
    ldr r0, lbl_0801afac @ =0x082cae2c
    cmp r1, r0
    bne lbl_0801afb0
    bl KraidPartUpdateRightArmAttackingHitbox
    b lbl_0801b016
    .align 2, 0
lbl_0801afac: .4byte 0x082cae2c
lbl_0801afb0:
    ldr r0, lbl_0801afbc @ =0x082cadc4
    cmp r1, r0
    bne lbl_0801afc0
    bl sub_08018bfc
    b lbl_0801b016
    .align 2, 0
lbl_0801afbc: .4byte 0x082cadc4
lbl_0801afc0:
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    b lbl_0801b016
lbl_0801afca:
    cmp r2, #1
    bne lbl_0801b01c
    ldr r1, [r4, #0x18]
    ldr r0, lbl_0801afdc @ =0x082cac6c
    cmp r1, r0
    bne lbl_0801afe0
    bl KraidMouthUpdateLeftArmIdlingHitbox
    b lbl_0801b016
    .align 2, 0
lbl_0801afdc: .4byte 0x082cac6c
lbl_0801afe0:
    ldr r0, lbl_0801afec @ =0x082cacc4
    cmp r1, r0
    bne lbl_0801aff0
    bl sub_08018fcc
    b lbl_0801b016
    .align 2, 0
lbl_0801afec: .4byte 0x082cacc4
lbl_0801aff0:
    ldr r0, lbl_0801affc @ =0x082cad1c
    cmp r1, r0
    bne lbl_0801b000
    bl KraidMouthUpdateLeftArmAttackingHitbox
    b lbl_0801b016
    .align 2, 0
lbl_0801affc: .4byte 0x082cad1c
lbl_0801b000:
    ldr r0, lbl_0801b00c @ =0x082cac5c
    cmp r1, r0
    bne lbl_0801b010
    bl sub_08018e88
    b lbl_0801b016
    .align 2, 0
lbl_0801b00c: .4byte 0x082cac5c
lbl_0801b010:
    adds r0, r4, #0
    adds r0, #0x26
    strb r2, [r0]
lbl_0801b016:
    bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
    b lbl_0801b03c
lbl_0801b01c:
    bl kraid_mouth_determine_spike_pos
    ldr r0, lbl_0801b044 @ =gSubSpriteData1
    ldrb r0, [r0, #0xd]
    cmp r0, #0
    beq lbl_0801b03c
    ldrb r0, [r4, #0x1e]
    cmp r0, #9
    beq lbl_0801b032
    cmp r0, #0xb
    bne lbl_0801b03c
lbl_0801b032:
    ldrb r0, [r4, #0x1c]
    cmp r0, #0xb
    bhi lbl_0801b03c
    adds r0, #4
    strb r0, [r4, #0x1c]
lbl_0801b03c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801b044: .4byte gSubSpriteData1

    thumb_func_start KraidSpike
KraidSpike: @ 0x0801b048
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_0801b0a8 @ =gSubSpriteData1
    ldrh r0, [r0, #0xa]
    ldr r4, lbl_0801b0ac @ =gCurrentSprite
    cmp r0, #0
    bne lbl_0801b062
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
lbl_0801b062:
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r6, [r0]
    adds r2, r4, #0
    adds r2, #0x34
    ldr r0, lbl_0801b0b0 @ =gSpriteData
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x34
    ldrb r1, [r1]
    ldrb r0, [r2]
    cmp r0, r1
    beq lbl_0801b08c
    strb r1, [r2]
    subs r2, #0x14
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0801b08c
    strb r1, [r2]
lbl_0801b08c:
    adds r7, r4, #0
    adds r7, #0x24
    ldrb r5, [r7]
    cmp r5, #0x23
    bne lbl_0801b098
    b lbl_0801b1b8
lbl_0801b098:
    cmp r5, #0x23
    bgt lbl_0801b0b4
    cmp r5, #0
    beq lbl_0801b0bc
    cmp r5, #9
    beq lbl_0801b11e
    b lbl_0801b4b4
    .align 2, 0
lbl_0801b0a8: .4byte gSubSpriteData1
lbl_0801b0ac: .4byte gCurrentSprite
lbl_0801b0b0: .4byte gSpriteData
lbl_0801b0b4:
    cmp r5, #0x25
    bne lbl_0801b0ba
    b lbl_0801b46c
lbl_0801b0ba:
    b lbl_0801b4b4
lbl_0801b0bc:
    ldrh r1, [r4]
    ldr r0, lbl_0801b134 @ =0x0000fffb
    ands r0, r1
    movs r3, #0
    strh r0, [r4]
    ldr r2, lbl_0801b138 @ =0x082b1be4
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    movs r0, #9
    strb r0, [r7]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r4, #0
    adds r1, #0x29
    movs r0, #0x30
    strb r0, [r1]
    ldr r0, lbl_0801b13c @ =0x0000ffe0
    strh r0, [r4, #0xa]
    movs r0, #0x20
    strh r0, [r4, #0xc]
    strh r5, [r4, #0xe]
    movs r0, #8
    strh r0, [r4, #0x10]
    subs r1, #7
    movs r0, #0xc
    strb r0, [r1]
    ldr r0, lbl_0801b140 @ =0x082cb2bc
    str r0, [r4, #0x18]
    strb r3, [r4, #0x1c]
    strh r5, [r4, #0x16]
    adds r1, #0xa
    movs r0, #0x14
    strb r0, [r1]
    ldr r0, lbl_0801b144 @ =0x000001c7
    bl SoundPlay
lbl_0801b11e:
    ldr r1, lbl_0801b148 @ =gCurrentSprite
    ldrh r0, [r1, #0x16]
    adds r2, r0, #0
    cmp r0, #4
    bhi lbl_0801b16a
    cmp r0, #1
    bne lbl_0801b14c
    movs r0, #0x20
    strh r0, [r1, #0x10]
    b lbl_0801b19a
    .align 2, 0
lbl_0801b134: .4byte 0x0000fffb
lbl_0801b138: .4byte 0x082b1be4
lbl_0801b13c: .4byte 0x0000ffe0
lbl_0801b140: .4byte 0x082cb2bc
lbl_0801b144: .4byte 0x000001c7
lbl_0801b148: .4byte gCurrentSprite
lbl_0801b14c:
    cmp r0, #2
    bne lbl_0801b156
    movs r0, #0x40
    strh r0, [r1, #0x10]
    b lbl_0801b19a
lbl_0801b156:
    cmp r0, #3
    bne lbl_0801b160
    movs r0, #0x60
    strh r0, [r1, #0x10]
    b lbl_0801b19a
lbl_0801b160:
    cmp r2, #4
    bne lbl_0801b19a
    movs r0, #0x80
    strh r0, [r1, #0x10]
    b lbl_0801b19a
lbl_0801b16a:
    adds r2, r1, #0
    adds r2, #0x25
    movs r0, #0x19
    strb r0, [r2]
    movs r0, #0x10
    strh r0, [r1, #0xe]
    movs r0, #0xa0
    strh r0, [r1, #0x10]
    adds r2, #7
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0801b188
    subs r0, #1
    strb r0, [r2]
    b lbl_0801b19a
lbl_0801b188:
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #4
    strb r0, [r2]
    movs r0, #0xe4
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801b19a:
    ldr r2, lbl_0801b1b0 @ =gCurrentSprite
    ldr r1, lbl_0801b1b4 @ =gSpriteData
    lsls r0, r6, #3
    subs r0, r0, r6
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r1, [r0, #2]
    strh r1, [r2, #2]
    ldrh r0, [r0, #4]
    strh r0, [r2, #4]
    b lbl_0801b4e2
    .align 2, 0
lbl_0801b1b0: .4byte gCurrentSprite
lbl_0801b1b4: .4byte gSpriteData
lbl_0801b1b8:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0801b1d2
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0801b1d2
    subs r1, #0xa
    movs r0, #4
    strb r0, [r1]
lbl_0801b1d2:
    ldr r0, lbl_0801b2bc @ =gCurrentSprite
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r1
    cmp r0, #0
    beq lbl_0801b1f8
    ldr r4, lbl_0801b2c0 @ =gSamusData
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    ldrh r1, [r4, #0x12]
    adds r1, #0x20
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801b1f8
    ldrh r0, [r4, #0x12]
    adds r0, #8
    strh r0, [r4, #0x12]
lbl_0801b1f8:
    ldr r5, lbl_0801b2bc @ =gCurrentSprite
    ldrh r0, [r5, #4]
    adds r1, r0, #0
    adds r1, #8
    strh r1, [r5, #4]
    ldrh r6, [r5, #2]
    adds r0, #0x88
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldrb r0, [r5, #0x1e]
    cmp r0, #2
    bne lbl_0801b218
    adds r0, r6, #0
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
lbl_0801b218:
    adds r0, r6, #0
    adds r1, r7, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0801b226
    b lbl_0801b4e2
lbl_0801b226:
    ldrh r0, [r5, #8]
    movs r1, #0xd0
    lsls r1, r1, #2
    adds r0, r0, r1
    cmp r7, r0
    blt lbl_0801b234
    b lbl_0801b368
lbl_0801b234:
    ldr r0, lbl_0801b2c4 @ =gCurrentClipdataAffectingAction
    mov sb, r0
    movs r1, #1
    mov r8, r1
    strb r1, [r0]
    adds r0, r6, #0
    adds r1, r7, #0
    bl ClipdataProcess
    adds r0, r6, #0
    adds r1, r7, #0
    movs r2, #0x20
    bl ParticleSet
    ldr r4, lbl_0801b2c8 @ =gSpriteRng
    ldrb r2, [r4]
    adds r2, #0x1a
    subs r2, r6, r2
    movs r0, #0
    movs r1, #0x11
    adds r3, r7, #0
    bl SpriteDebrisInit
    adds r2, r6, #0
    subs r2, #0x10
    ldrb r3, [r4]
    adds r3, #8
    adds r3, r7, r3
    movs r0, #0
    movs r1, #0x12
    bl SpriteDebrisInit
    ldrb r2, [r4]
    adds r2, #0x40
    subs r2, r6, r2
    adds r3, r7, #0
    adds r3, #0x10
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r2, r6, #0
    subs r2, #0x26
    ldrb r3, [r4]
    adds r3, #0x1c
    subs r3, r7, r3
    movs r0, #0
    movs r1, #4
    bl SpriteDebrisInit
    ldrb r0, [r5, #0x1e]
    cmp r0, #2
    bne lbl_0801b2d4
    ldr r2, lbl_0801b2cc @ =gSubSpriteData1
    ldrb r1, [r2, #0xf]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0801b2ac
    b lbl_0801b4e2
lbl_0801b2ac:
    mov r0, r8
    orrs r0, r1
    strb r0, [r2, #0xf]
    ldr r0, lbl_0801b2d0 @ =0x000001c9
    bl SoundPlay
    b lbl_0801b4e2
    .align 2, 0
lbl_0801b2bc: .4byte gCurrentSprite
lbl_0801b2c0: .4byte gSamusData
lbl_0801b2c4: .4byte gCurrentClipdataAffectingAction
lbl_0801b2c8: .4byte gSpriteRng
lbl_0801b2cc: .4byte gSubSpriteData1
lbl_0801b2d0: .4byte 0x000001c9
lbl_0801b2d4:
    cmp r0, #4
    bne lbl_0801b314
    ldr r2, lbl_0801b310 @ =gSubSpriteData1
    ldrb r1, [r2, #0xf]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0801b2f2
    movs r0, #2
    orrs r0, r1
    strb r0, [r2, #0xf]
    movs r0, #0xe5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801b2f2:
    mov r1, r8
    mov r0, sb
    strb r1, [r0]
    adds r0, r6, #0
    subs r0, #0x40
    adds r1, r7, #0
    bl ClipdataProcess
    mov r1, r8
    mov r0, sb
    strb r1, [r0]
    adds r4, r6, #0
    subs r4, #0x80
    b lbl_0801b34e
    .align 2, 0
lbl_0801b310: .4byte gSubSpriteData1
lbl_0801b314:
    cmp r0, #7
    beq lbl_0801b31a
    b lbl_0801b4e2
lbl_0801b31a:
    ldr r2, lbl_0801b364 @ =gSubSpriteData1
    ldrb r1, [r2, #0xf]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_0801b334
    movs r0, #4
    orrs r0, r1
    strb r0, [r2, #0xf]
    movs r0, #0xe5
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801b334:
    mov r1, r8
    mov r0, sb
    strb r1, [r0]
    adds r0, r6, #0
    subs r0, #0x40
    adds r1, r7, #0
    bl ClipdataProcess
    mov r1, r8
    mov r0, sb
    strb r1, [r0]
    adds r4, r6, #0
    adds r4, #0x40
lbl_0801b34e:
    adds r0, r4, #0
    adds r1, r7, #0
    bl ClipdataProcess
    adds r0, r4, #0
    adds r1, r7, #0
    movs r2, #0x20
    bl ParticleSet
    b lbl_0801b4e2
    .align 2, 0
lbl_0801b364: .4byte gSubSpriteData1
lbl_0801b368:
    ldrb r0, [r5, #0x1e]
    cmp r0, #2
    bne lbl_0801b378
    adds r0, r6, #0
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    b lbl_0801b3f8
lbl_0801b378:
    cmp r0, #4
    bne lbl_0801b3f8
    adds r4, r6, #0
    subs r4, #0xc0
    adds r5, r7, #0
    subs r5, #0x20
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0801b3a8
    ldr r1, lbl_0801b45c @ =gCurrentClipdataAffectingAction
    movs r0, #1
    strb r0, [r1]
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x20
    bl ParticleSet
lbl_0801b3a8:
    adds r5, r7, #0
    subs r5, #0x60
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0801b3d0
    ldr r1, lbl_0801b45c @ =gCurrentClipdataAffectingAction
    movs r0, #1
    strb r0, [r1]
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x20
    bl ParticleSet
lbl_0801b3d0:
    adds r5, r7, #0
    subs r5, #0xa0
    adds r0, r4, #0
    adds r1, r5, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0801b3f8
    ldr r1, lbl_0801b45c @ =gCurrentClipdataAffectingAction
    movs r0, #1
    strb r0, [r1]
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x20
    bl ParticleSet
lbl_0801b3f8:
    ldr r4, lbl_0801b460 @ =gSpriteRng
    ldrb r2, [r4]
    subs r2, r6, r2
    adds r3, r7, #0
    adds r3, #0x10
    movs r0, #0
    movs r1, #0x11
    bl SpriteDebrisInit
    adds r2, r6, #0
    adds r2, #0x10
    ldrb r3, [r4]
    lsls r3, r3, #1
    adds r3, r7, r3
    movs r0, #0
    movs r1, #0x12
    bl SpriteDebrisInit
    ldrb r2, [r4]
    adds r2, r6, r2
    adds r3, r7, #0
    subs r3, #0x10
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r2, r6, #0
    subs r2, #0x10
    ldrb r3, [r4]
    lsls r3, r3, #1
    subs r3, r7, r3
    movs r0, #0
    movs r1, #4
    bl SpriteDebrisInit
    ldr r1, lbl_0801b464 @ =gCurrentSprite
    movs r0, #0xb4
    lsls r0, r0, #1
    strh r0, [r1, #6]
    adds r2, r1, #0
    adds r2, #0x24
    movs r0, #0x25
    strb r0, [r2]
    adds r1, #0x22
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0801b468 @ =0x000001cb
    bl SoundPlay
    b lbl_0801b4e2
    .align 2, 0
lbl_0801b45c: .4byte gCurrentClipdataAffectingAction
lbl_0801b460: .4byte gSpriteRng
lbl_0801b464: .4byte gCurrentSprite
lbl_0801b468: .4byte 0x000001cb
lbl_0801b46c:
    ldrh r0, [r4, #6]
    subs r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0x3c
    bhi lbl_0801b4e2
    movs r0, #3
    ands r0, r2
    cmp r0, #0
    bne lbl_0801b4e2
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_0801b4a0
    adds r0, r4, #0
    adds r0, #0x33
    ldrb r0, [r0]
    ldrb r1, [r4, #0x1f]
    adds r0, r0, r1
    movs r1, #0xe
    subs r1, r1, r0
    adds r0, r4, #0
    adds r0, #0x20
    strb r1, [r0]
    b lbl_0801b4e2
lbl_0801b4a0:
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    cmp r2, #0
    bne lbl_0801b4e2
    movs r0, #0x62
    strb r0, [r7]
    b lbl_0801b4e2
lbl_0801b4b4:
    adds r0, r4, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0801b4ca
    ldr r1, lbl_0801b4f0 @ =gSamusData
    ldrb r0, [r1, #1]
    cmp r0, #1
    bne lbl_0801b4ca
    movs r0, #2
    strb r0, [r1, #1]
lbl_0801b4ca:
    movs r0, #0
    strh r0, [r4]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, #0x50
    movs r2, #0x1e
    bl ParticleSet
    movs r0, #0x9c
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801b4e2:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0801b4f0: .4byte gSamusData

    thumb_func_start KraidNail
KraidNail: @ 0x0801b4f4
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r0, lbl_0801b520 @ =gCurrentSprite
    adds r5, r0, #0
    adds r5, #0x24
    ldrb r3, [r5]
    adds r4, r0, #0
    cmp r3, #0
    beq lbl_0801b524
    cmp r3, #9
    bne lbl_0801b50c
    b lbl_0801b626
lbl_0801b50c:
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    b lbl_0801b6b0
    .align 2, 0
lbl_0801b520: .4byte gCurrentSprite
lbl_0801b524:
    ldrh r1, [r4]
    ldr r0, lbl_0801b5b8 @ =0x0000fffb
    ands r0, r1
    movs r6, #0
    strh r0, [r4]
    ldr r2, lbl_0801b5bc @ =0x082b1be4
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    movs r0, #9
    strb r0, [r5]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0801b5c0 @ =0x0000ffe4
    strh r1, [r4, #0xa]
    movs r0, #0x1c
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    ldr r0, lbl_0801b5c4 @ =0x082cb28c
    str r0, [r4, #0x18]
    strb r6, [r4, #0x1c]
    strh r3, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    subs r1, #1
    movs r0, #1
    strb r0, [r1]
    ldrh r0, [r4]
    movs r1, #0x80
    orrs r0, r1
    strh r0, [r4]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r4, #0x12]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r6, [r0]
    ldrh r0, [r4, #2]
    lsrs r0, r0, #6
    adds r1, r4, #0
    adds r1, #0x2f
    strb r0, [r1]
    ldrh r0, [r4, #4]
    lsrs r0, r0, #6
    subs r1, #1
    strb r0, [r1]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    beq lbl_0801b5cc
    ldr r1, lbl_0801b5c8 @ =gSamusData
    ldrh r3, [r1, #0x14]
    adds r2, r4, #0
    adds r2, #0x2a
    movs r0, #0x40
    strb r0, [r2]
    b lbl_0801b5dc
    .align 2, 0
lbl_0801b5b8: .4byte 0x0000fffb
lbl_0801b5bc: .4byte 0x082b1be4
lbl_0801b5c0: .4byte 0x0000ffe4
lbl_0801b5c4: .4byte 0x082cb28c
lbl_0801b5c8: .4byte gSamusData
lbl_0801b5cc:
    ldr r1, lbl_0801b5f4 @ =gSamusData
    ldrh r0, [r1, #0x14]
    subs r0, #0xa0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    adds r0, r4, #0
    adds r0, #0x2a
    strb r6, [r0]
lbl_0801b5dc:
    adds r5, r1, #0
    ldrh r2, [r5, #0x12]
    adds r0, r4, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    lsls r0, r0, #6
    cmp r3, r0
    bge lbl_0801b5fc
    ldrh r1, [r4]
    ldr r0, lbl_0801b5f8 @ =0x0000fbff
    ands r0, r1
    b lbl_0801b606
    .align 2, 0
lbl_0801b5f4: .4byte gSamusData
lbl_0801b5f8: .4byte 0x0000fbff
lbl_0801b5fc:
    ldrh r1, [r4]
    movs r6, #0x80
    lsls r6, r6, #3
    adds r0, r6, #0
    orrs r0, r1
lbl_0801b606:
    strh r0, [r4]
    ldrh r0, [r4, #4]
    cmp r2, r0
    bhs lbl_0801b616
    ldrh r0, [r5, #0x12]
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_0801b616:
    ldrh r1, [r4]
    movs r5, #0x80
    lsls r5, r5, #2
    adds r0, r5, #0
    orrs r0, r1
    strh r0, [r4]
    strh r3, [r4, #6]
    strh r2, [r4, #8]
lbl_0801b626:
    adds r5, r4, #0
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0801b656
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    movs r2, #0x1f
    bl ParticleSet
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0801b650
    movs r0, #0x96
    lsls r0, r0, #1
    bl SoundPlay
lbl_0801b650:
    movs r0, #0
    strh r0, [r5]
    b lbl_0801b6b0
lbl_0801b656:
    ldr r0, lbl_0801b670 @ =gDifficulty
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0801b67e
    ldrb r0, [r5, #0x1e]
    cmp r0, #0
    beq lbl_0801b674
    adds r1, r5, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0x14
    b lbl_0801b696
    .align 2, 0
lbl_0801b670: .4byte gDifficulty
lbl_0801b674:
    adds r1, r5, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0x16
    b lbl_0801b696
lbl_0801b67e:
    ldrb r0, [r5, #0x1e]
    cmp r0, #0
    beq lbl_0801b68e
    adds r1, r5, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0xc
    b lbl_0801b696
lbl_0801b68e:
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    adds r0, #0xe
lbl_0801b696:
    strb r0, [r1]
    ldr r1, lbl_0801b6a8 @ =gCurrentSprite
    ldrh r0, [r1, #0x14]
    cmp r0, #0
    bne lbl_0801b6ac
    adds r1, #0x24
    movs r0, #0x42
    strb r0, [r1]
    b lbl_0801b6b0
    .align 2, 0
lbl_0801b6a8: .4byte gCurrentSprite
lbl_0801b6ac:
    bl KraidNailMovement
lbl_0801b6b0:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
