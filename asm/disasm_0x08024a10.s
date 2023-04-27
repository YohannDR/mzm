    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start HiveSpawnParticle
HiveSpawnParticle: @ 0x08024a10
    push {r4, r5, lr}
    ldr r0, lbl_08024a38 @ =gCurrentSprite
    ldrh r4, [r0, #2]
    ldrh r5, [r0, #4]
    adds r0, r4, #0
    subs r0, #0x20
    adds r1, r5, #0
    movs r2, #0x35
    bl ParticleSet
    adds r4, #0x60
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x36
    bl ParticleSet
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024a38: .4byte gCurrentSprite

    thumb_func_start HiveInit
HiveInit: @ 0x08024a3c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    movs r0, #3
    movs r1, #0x2c
    bl EventFunction
    adds r7, r0, #0
    cmp r7, #0
    beq lbl_08024a60
    ldr r1, lbl_08024a5c @ =gCurrentSprite
    movs r0, #0
    strh r0, [r1]
    b lbl_08024b3e
    .align 2, 0
lbl_08024a5c: .4byte gCurrentSprite
lbl_08024a60:
    ldr r0, lbl_08024b4c @ =gCurrentSprite
    mov ip, r0
    adds r0, #0x27
    movs r1, #0x28
    strb r1, [r0]
    mov r0, ip
    adds r0, #0x28
    strb r1, [r0]
    mov r1, ip
    adds r1, #0x29
    movs r0, #0x14
    strb r0, [r1]
    movs r3, #0
    ldr r0, lbl_08024b50 @ =0x0000ff80
    mov r1, ip
    strh r0, [r1, #0xa]
    movs r0, #0x80
    strh r0, [r1, #0xc]
    ldr r0, lbl_08024b54 @ =0x0000ffd0
    strh r0, [r1, #0xe]
    movs r0, #0x30
    strh r0, [r1, #0x10]
    adds r1, #0x25
    movs r0, #0xb
    strb r0, [r1]
    adds r1, #0xe
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08024b58 @ =0x082da8ec
    mov r1, ip
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r7, [r1, #0x16]
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r2, lbl_08024b5c @ =0x082b0d68
    mov r0, ip
    ldrb r1, [r0, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    mov r1, ip
    strh r0, [r1, #0x14]
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2c
    strb r3, [r0]
    mov r0, ip
    ldrh r5, [r0, #2]
    ldrh r4, [r0, #4]
    ldrb r1, [r0, #0x1f]
    mov r8, r1
    ldrb r6, [r0, #0x1e]
    adds r0, #0x23
    ldrb r3, [r0]
    str r5, [sp]
    str r4, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x11
    adds r1, r6, #0
    mov r2, r8
    bl SpriteSpawnSecondary
    adds r3, r5, #0
    adds r3, #0x40
    adds r0, r4, #0
    subs r0, #0x1f
    str r0, [sp]
    str r7, [sp, #4]
    movs r0, #0x4a
    adds r1, r6, #0
    mov r2, r8
    bl SpriteSpawnPrimary
    adds r3, r5, #0
    adds r3, #0x20
    adds r0, r4, #0
    adds r0, #0x10
    str r0, [sp]
    str r7, [sp, #4]
    movs r0, #0x4a
    adds r1, r6, #0
    mov r2, r8
    bl SpriteSpawnPrimary
    adds r3, r5, #0
    subs r3, #0x48
    adds r0, r4, #0
    subs r0, #0x10
    str r0, [sp]
    str r7, [sp, #4]
    movs r0, #0x4a
    adds r1, r6, #0
    mov r2, r8
    bl SpriteSpawnPrimary
    subs r5, #0x60
    adds r4, #0x1f
    str r4, [sp]
    str r7, [sp, #4]
    movs r0, #0x4a
    adds r1, r6, #0
    mov r2, r8
    adds r3, r5, #0
    bl SpriteSpawnPrimary
lbl_08024b3e:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024b4c: .4byte gCurrentSprite
lbl_08024b50: .4byte 0x0000ff80
lbl_08024b54: .4byte 0x0000ffd0
lbl_08024b58: .4byte 0x082da8ec
lbl_08024b5c: .4byte 0x082b0d68

    thumb_func_start hive_count_mellow
hive_count_mellow: @ 0x08024b60
    push {r4, r5, r6, r7, lr}
    movs r4, #0
    movs r0, #0x12
    mov ip, r0
    ldr r0, lbl_08024bac @ =gCurrentSprite
    ldrb r5, [r0, #0x1e]
    ldr r2, lbl_08024bb0 @ =gSpriteData
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08024ba4
    movs r7, #1
    adds r3, r2, #0
    adds r3, #0x1e
    adds r6, r0, #0
lbl_08024b80:
    ldrh r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08024b9c
    ldrb r0, [r3, #7]
    cmp r0, ip
    bne lbl_08024b9c
    ldrb r0, [r3]
    cmp r0, r5
    bne lbl_08024b9c
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_08024b9c:
    adds r3, #0x38
    adds r2, #0x38
    cmp r2, r6
    blo lbl_08024b80
lbl_08024ba4:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08024bac: .4byte gCurrentSprite
lbl_08024bb0: .4byte gSpriteData

    thumb_func_start HivePhase1
HivePhase1: @ 0x08024bb4
    push {lr}
    sub sp, #8
    bl hive_count_mellow
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bhi lbl_08024bda
    ldr r0, lbl_08024c20 @ =gCurrentSprite
    ldrb r1, [r0, #0x1e]
    ldrb r2, [r0, #0x1f]
    ldrh r3, [r0, #2]
    ldrh r0, [r0, #4]
    str r0, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x4a
    bl SpriteSpawnPrimary
lbl_08024bda:
    ldr r3, lbl_08024c20 @ =gCurrentSprite
    ldr r2, lbl_08024c24 @ =0x082b0d68
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    ldrh r1, [r3, #0x14]
    lsrs r0, r0, #1
    cmp r1, r0
    bhs lbl_08024c18
    adds r2, r3, #0
    adds r2, #0x33
    movs r1, #0
    movs r0, #2
    strb r0, [r2]
    ldr r0, lbl_08024c28 @ =0x082da9a4
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r1, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #0xb0
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    bl HiveSpawnParticle
lbl_08024c18:
    add sp, #8
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024c20: .4byte gCurrentSprite
lbl_08024c24: .4byte 0x082b0d68
lbl_08024c28: .4byte 0x082da9a4

    thumb_func_start HivePhase2
HivePhase2: @ 0x08024c2c
    push {lr}
    sub sp, #8
    bl hive_count_mellow
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bhi lbl_08024c52
    ldr r0, lbl_08024c98 @ =gCurrentSprite
    ldrb r1, [r0, #0x1e]
    ldrb r2, [r0, #0x1f]
    ldrh r3, [r0, #2]
    ldrh r0, [r0, #4]
    str r0, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x4a
    bl SpriteSpawnPrimary
lbl_08024c52:
    ldr r3, lbl_08024c98 @ =gCurrentSprite
    ldr r2, lbl_08024c9c @ =0x082b0d68
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    ldrh r1, [r3, #0x14]
    lsrs r0, r0, #2
    cmp r1, r0
    bhs lbl_08024c90
    adds r2, r3, #0
    adds r2, #0x33
    movs r1, #0
    movs r0, #3
    strb r0, [r2]
    ldr r0, lbl_08024ca0 @ =0x082daa04
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r1, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    movs r0, #0xb0
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    bl HiveSpawnParticle
lbl_08024c90:
    add sp, #8
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024c98: .4byte gCurrentSprite
lbl_08024c9c: .4byte 0x082b0d68
lbl_08024ca0: .4byte 0x082daa04

    thumb_func_start HivePhase3
HivePhase3: @ 0x08024ca4
    push {lr}
    sub sp, #8
    bl hive_count_mellow
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bhi lbl_08024cca
    ldr r0, lbl_08024cd0 @ =gCurrentSprite
    ldrb r1, [r0, #0x1e]
    ldrb r2, [r0, #0x1f]
    ldrh r3, [r0, #2]
    ldrh r0, [r0, #4]
    str r0, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x4a
    bl SpriteSpawnPrimary
lbl_08024cca:
    add sp, #8
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024cd0: .4byte gCurrentSprite

    thumb_func_start HiveDying
HiveDying: @ 0x08024cd4
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    movs r2, #0
    movs r5, #0x4b
    ldr r3, lbl_08024da4 @ =gSpriteData
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r3, r1
    cmp r3, r0
    bhs lbl_08024d1e
    adds r4, r0, #0
lbl_08024cee:
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08024d18
    adds r0, r3, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08024d18
    ldrb r0, [r3, #0x1d]
    cmp r0, r5
    bne lbl_08024d18
    ldrh r0, [r3, #0x14]
    cmp r0, #0
    beq lbl_08024d18
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08024d18:
    adds r3, #0x38
    cmp r3, r4
    blo lbl_08024cee
lbl_08024d1e:
    cmp r2, #0
    bne lbl_08024d2a
    movs r0, #1
    movs r1, #0x2c
    bl EventFunction
lbl_08024d2a:
    movs r2, #9
    mov ip, r2
    ldr r0, lbl_08024da8 @ =gCurrentSprite
    ldrb r5, [r0, #0x1e]
    movs r7, #0x12
    ldr r3, lbl_08024da4 @ =gSpriteData
    movs r2, #0xa8
    lsls r2, r2, #3
    adds r1, r3, r2
    adds r4, r0, #0
    cmp r3, r1
    bhs lbl_08024d78
    adds r6, r1, #0
    adds r2, r3, #0
    adds r2, #0x1e
lbl_08024d48:
    ldrh r1, [r3]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08024d70
    ldrb r0, [r2, #7]
    cmp r0, r7
    bne lbl_08024d70
    ldrb r0, [r2]
    cmp r0, r5
    bne lbl_08024d70
    ldrb r0, [r2, #6]
    cmp r0, ip
    bne lbl_08024d70
    movs r0, #0x25
    strb r0, [r2, #6]
    ldrb r0, [r2, #0x14]
    movs r1, #4
    orrs r0, r1
    strb r0, [r2, #0x14]
lbl_08024d70:
    adds r2, #0x38
    adds r3, #0x38
    cmp r3, r6
    blo lbl_08024d48
lbl_08024d78:
    adds r3, r4, #0
    adds r1, r3, #0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #0x62
    bhi lbl_08024d8e
    adds r0, r3, #0
    adds r0, #0x2c
    ldrb r2, [r0]
    cmp r2, #0
    beq lbl_08024dac
lbl_08024d8e:
    ldrh r1, [r3, #2]
    adds r1, #0x48
    ldrh r2, [r3, #4]
    movs r0, #0x22
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    b lbl_08024dca
    .align 2, 0
lbl_08024da4: .4byte gSpriteData
lbl_08024da8: .4byte gCurrentSprite
lbl_08024dac:
    movs r0, #0x67
    strb r0, [r1]
    ldr r0, lbl_08024dd8 @ =0x082daa6c
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    movs r1, #0
    strh r2, [r4, #0x16]
    adds r0, r4, #0
    adds r0, #0x25
    strb r1, [r0]
    ldr r0, lbl_08024ddc @ =0x00000161
    bl SoundPlayNotAlreadyPlaying
    bl HiveSpawnParticle
lbl_08024dca:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024dd8: .4byte 0x082daa6c
lbl_08024ddc: .4byte 0x00000161

    thumb_func_start HiveIgnoreSamusCollision
HiveIgnoreSamusCollision: @ 0x08024de0
    ldr r0, lbl_08024dec @ =gCurrentSprite
    adds r0, #0x26
    movs r1, #1
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_08024dec: .4byte gCurrentSprite

    thumb_func_start HiveRootsInit
HiveRootsInit: @ 0x08024df0
    push {r4, lr}
    ldr r0, lbl_08024e44 @ =gCurrentSprite
    mov ip, r0
    ldrh r1, [r0]
    ldr r0, lbl_08024e48 @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    movs r3, #0
    mov r1, ip
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x25
    strb r2, [r0]
    adds r0, #2
    strb r2, [r0]
    adds r1, #0x28
    movs r0, #0x20
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x14
    strb r0, [r1]
    ldr r1, lbl_08024e4c @ =0x0000fffc
    mov r4, ip
    strh r1, [r4, #0xa]
    movs r0, #4
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    mov r1, ip
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_08024e50 @ =0x082da984
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    adds r1, #0xf
    movs r0, #1
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08024e44: .4byte gCurrentSprite
lbl_08024e48: .4byte 0x0000fffb
lbl_08024e4c: .4byte 0x0000fffc
lbl_08024e50: .4byte 0x082da984

    thumb_func_start HiveRootsMove
HiveRootsMove: @ 0x08024e54
    ldr r2, lbl_08024e70 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r3, lbl_08024e74 @ =gSpriteData
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrh r1, [r0, #2]
    strh r1, [r2, #2]
    ldrh r0, [r0, #4]
    strh r0, [r2, #4]
    bx lr
    .align 2, 0
lbl_08024e70: .4byte gCurrentSprite
lbl_08024e74: .4byte gSpriteData

    thumb_func_start MellowInit
MellowInit: @ 0x08024e78
    push {r4, r5, lr}
    adds r4, r0, #0
    movs r0, #3
    movs r1, #0x2c
    bl EventFunction
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_08024e8e
    movs r0, #0
    b lbl_08024fbe
lbl_08024e8e:
    ldrh r1, [r4]
    ldr r0, lbl_08024f04 @ =0x0000fffb
    ands r0, r1
    movs r5, #0
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    movs r1, #0xc
    strb r1, [r0]
    ldr r0, lbl_08024f08 @ =0x0000fff4
    strh r0, [r4, #0xa]
    strh r1, [r4, #0xc]
    subs r0, #0x14
    strh r0, [r4, #0xe]
    movs r3, #0x20
    strh r3, [r4, #0x10]
    strb r5, [r4, #0x1c]
    strh r2, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #0x12
    strb r0, [r1]
    ldr r2, lbl_08024f0c @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0x88
    beq lbl_08024f3e
    ldr r0, lbl_08024f10 @ =0x082da88c
    str r0, [r4, #0x18]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_08024f14 @ =gSpriteRNG
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r2, r4, #0
    adds r2, #0x2f
    strb r0, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08024f18
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x14
    b lbl_08024f1e
    .align 2, 0
lbl_08024f04: .4byte 0x0000fffb
lbl_08024f08: .4byte 0x0000fff4
lbl_08024f0c: .4byte 0x082b0d68
lbl_08024f10: .4byte 0x082da88c
lbl_08024f14: .4byte gSpriteRNG
lbl_08024f18:
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x3c
lbl_08024f1e:
    strb r0, [r1]
    ldrh r1, [r4, #4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08024f34
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    b lbl_08024fc0
lbl_08024f34:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #6
    strb r0, [r1]
    b lbl_08024fc0
lbl_08024f3e:
    ldr r0, lbl_08024f9c @ =0x082da8bc
    str r0, [r4, #0x18]
    ldr r0, lbl_08024fa0 @ =gIoRegistersBackup
    ldrb r2, [r0, #0xc]
    movs r1, #3
    adds r0, r1, #0
    ands r0, r2
    adds r2, r4, #0
    adds r2, #0x21
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x22
    strb r1, [r0]
    adds r0, #0xb
    strb r5, [r0]
    adds r0, #1
    movs r2, #1
    strb r2, [r0]
    subs r0, #2
    strb r5, [r0]
    adds r0, #3
    strb r2, [r0]
    ldr r0, lbl_08024fa4 @ =gSpriteRNG
    ldrb r0, [r0]
    ands r1, r0
    strh r1, [r4, #8]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    strh r3, [r4, #0x12]
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldrh r2, [r4, #2]
    ldr r1, lbl_08024fa8 @ =gSamusData
    ldr r0, lbl_08024fac @ =gSamusPhysics
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    ldrh r1, [r1, #0x14]
    adds r0, r0, r1
    cmp r2, r0
    ble lbl_08024fb4
    ldrh r1, [r4]
    ldr r0, lbl_08024fb0 @ =0x0000fbff
    ands r0, r1
    b lbl_08024fbe
    .align 2, 0
lbl_08024f9c: .4byte 0x082da8bc
lbl_08024fa0: .4byte gIoRegistersBackup
lbl_08024fa4: .4byte gSpriteRNG
lbl_08024fa8: .4byte gSamusData
lbl_08024fac: .4byte gSamusPhysics
lbl_08024fb0: .4byte 0x0000fbff
lbl_08024fb4:
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
lbl_08024fbe:
    strh r0, [r4]
lbl_08024fc0:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MellowIdle
MellowIdle: @ 0x08024fc8
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r3, r4, #0
    adds r3, #0x2f
    ldrb r2, [r3]
    ldr r5, lbl_08025030 @ =0x082d88e4
    lsls r0, r2, #1
    adds r0, r0, r5
    movs r6, #0
    ldrsh r1, [r0, r6]
    ldr r6, lbl_08025034 @ =0x00007fff
    cmp r1, r6
    bne lbl_08024fe8
    movs r7, #0
    ldrsh r1, [r5, r7]
    movs r2, #0
lbl_08024fe8:
    adds r0, r2, #1
    strb r0, [r3]
    ldrh r0, [r4, #2]
    adds r0, r0, r1
    strh r0, [r4, #2]
    adds r3, r4, #0
    adds r3, #0x2e
    ldrb r2, [r3]
    ldr r5, lbl_08025038 @ =0x082d8966
    lsls r0, r2, #1
    adds r0, r0, r5
    movs r7, #0
    ldrsh r1, [r0, r7]
    cmp r1, r6
    bne lbl_0802500c
    movs r0, #0
    ldrsh r1, [r5, r0]
    movs r2, #0
lbl_0802500c:
    adds r0, r2, #1
    strb r0, [r3]
    ldrh r0, [r4, #4]
    adds r0, r0, r1
    strh r0, [r4, #4]
    ldrb r0, [r3]
    cmp r0, #1
    beq lbl_08025020
    cmp r0, #0x29
    bne lbl_08025040
lbl_08025020:
    adds r1, r4, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #3
    bne lbl_0802503c
    movs r0, #6
    b lbl_0802503e
    .align 2, 0
lbl_08025030: .4byte 0x082d88e4
lbl_08025034: .4byte 0x00007fff
lbl_08025038: .4byte 0x082d8966
lbl_0802503c:
    movs r0, #3
lbl_0802503e:
    strb r0, [r1]
lbl_08025040:
    movs r0, #0xa0
    lsls r0, r0, #1
    movs r1, #0x88
    lsls r1, r1, #1
    bl SpriteUtilCheckSamusNearSpriteLeftRight
    cmp r0, #0
    beq lbl_08025078
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x22
    strb r0, [r1]
    ldr r0, lbl_08025080 @ =0x082da8bc
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r2, [r4, #0x16]
    ldr r0, lbl_08025084 @ =gIoRegistersBackup
    ldrb r1, [r0, #0xc]
    movs r2, #3
    adds r0, r2, #0
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x21
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x22
    strb r2, [r0]
lbl_08025078:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08025080: .4byte 0x082da8bc
lbl_08025084: .4byte gIoRegistersBackup

    thumb_func_start MellowFleeing
MellowFleeing: @ 0x08025088
    push {lr}
    adds r1, r0, #0
    ldr r0, lbl_080250a8 @ =gSpriteRNG
    ldrb r0, [r0]
    lsrs r3, r0, #2
    adds r2, r3, #0
    adds r2, #8
    adds r0, r1, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0x27
    bhi lbl_080250ac
    ldrh r0, [r1, #4]
    adds r0, r0, r2
    b lbl_080250b0
    .align 2, 0
lbl_080250a8: .4byte gSpriteRNG
lbl_080250ac:
    ldrh r0, [r1, #4]
    subs r0, r0, r2
lbl_080250b0:
    strh r0, [r1, #4]
    adds r2, r3, #4
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0x1f
    bhi lbl_080250c4
    ldrh r0, [r1, #2]
    adds r0, r0, r2
    b lbl_080250c8
lbl_080250c4:
    ldrh r0, [r1, #2]
    subs r0, r0, r2
lbl_080250c8:
    strh r0, [r1, #2]
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MellowSamusDetectedInit
MellowSamusDetectedInit: @ 0x080250d0
    push {r4, lr}
    adds r4, r0, #0
    adds r0, #0x2d
    movs r1, #0
    strb r1, [r0]
    adds r0, #1
    movs r2, #1
    strb r2, [r0]
    subs r0, #2
    strb r1, [r0]
    adds r0, #3
    strb r2, [r0]
    strh r1, [r4, #8]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #0x20
    strh r0, [r4, #0x12]
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldrh r2, [r4, #2]
    ldr r1, lbl_08025118 @ =gSamusData
    ldr r0, lbl_0802511c @ =gSamusPhysics
    adds r0, #0x70
    movs r3, #0
    ldrsh r0, [r0, r3]
    ldrh r1, [r1, #0x14]
    adds r0, r0, r1
    cmp r2, r0
    ble lbl_08025124
    ldrh r1, [r4]
    ldr r0, lbl_08025120 @ =0x0000fbff
    ands r0, r1
    b lbl_0802512e
    .align 2, 0
lbl_08025118: .4byte gSamusData
lbl_0802511c: .4byte gSamusPhysics
lbl_08025120: .4byte 0x0000fbff
lbl_08025124:
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    orrs r0, r1
lbl_0802512e:
    strh r0, [r4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MellowMove
MellowMove: @ 0x08025138
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov ip, r0
    movs r0, #0
    str r0, [sp]
    movs r5, #0x18
    mov r2, ip
    ldrh r1, [r2, #2]
    adds r0, r1, #0
    subs r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    adds r1, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sl, r1
    ldrh r1, [r2, #4]
    adds r0, r1, #0
    subs r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    adds r1, #0x18
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    mov r0, ip
    adds r0, #0x23
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    ldr r0, lbl_080251dc @ =gSpriteData
    adds r2, r1, r0
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, lbl_080251e0 @ =gSamusData
    mov sb, r1
    cmp r2, r0
    bhs lbl_08025202
    adds r3, r2, #0
    adds r3, #0x25
lbl_0802519c:
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080251f8
    ldrb r0, [r3]
    cmp r0, #0x12
    bne lbl_080251f8
    ldrh r6, [r2, #2]
    ldrh r4, [r2, #4]
    subs r0, r6, r5
    cmp sl, r0
    ble lbl_080251f8
    adds r0, r6, r5
    ldr r1, [sp, #4]
    cmp r1, r0
    bge lbl_080251f8
    subs r0, r4, r5
    cmp r7, r0
    ble lbl_080251f8
    adds r0, r4, r5
    cmp r8, r0
    bge lbl_080251f8
    ldrb r0, [r3, #0xb]
    cmp r0, #0
    bne lbl_08025202
    mov r1, ip
    ldrh r0, [r1, #2]
    cmp r0, r6
    bls lbl_080251e4
    subs r0, r6, #4
    b lbl_080251e6
    .align 2, 0
lbl_080251dc: .4byte gSpriteData
lbl_080251e0: .4byte gSamusData
lbl_080251e4:
    adds r0, r6, #4
lbl_080251e6:
    strh r0, [r2, #2]
    mov r1, ip
    ldrh r0, [r1, #4]
    cmp r0, r4
    bhi lbl_08025240
    ldrh r0, [r2, #4]
    adds r0, #4
    strh r0, [r2, #4]
    b lbl_08025202
lbl_080251f8:
    adds r3, #0x38
    adds r2, #0x38
    ldr r0, lbl_08025238 @ =gSpritesetSpritesID
    cmp r2, r0
    blo lbl_0802519c
lbl_08025202:
    mov r2, ip
    ldrb r0, [r2, #0x1e]
    cmp r0, #0x88
    bne lbl_08025298
    movs r7, #0x14
    ldr r1, lbl_0802523c @ =gSpriteRNG
    ldrb r0, [r1]
    adds r0, #0x1e
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldrb r1, [r1]
    lsls r1, r1, #2
    adds r1, #0xdc
    mov r2, sb
    ldrh r0, [r2, #0x14]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrh r4, [r2, #0x12]
    mov r1, ip
    ldrh r0, [r1, #8]
    cmp r0, #1
    beq lbl_08025248
    cmp r0, #3
    beq lbl_08025270
    b lbl_08025304
    .align 2, 0
lbl_08025238: .4byte gSpritesetSpritesID
lbl_0802523c: .4byte gSpriteRNG
lbl_08025240:
    ldrh r0, [r2, #4]
    subs r0, #4
    strh r0, [r2, #4]
    b lbl_08025202
lbl_08025248:
    adds r0, r6, #0
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r2, ip
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08025266
    movs r1, #0x80
    lsls r1, r1, #1
    adds r0, r4, r1
    b lbl_08025300
lbl_08025266:
    ldr r2, lbl_0802526c @ =0xffffff00
    adds r0, r4, r2
    b lbl_08025300
    .align 2, 0
lbl_0802526c: .4byte 0xffffff00
lbl_08025270:
    adds r0, r6, #0
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08025290
    ldr r1, lbl_0802528c @ =0xffffff00
    adds r0, r4, r1
    b lbl_08025300
    .align 2, 0
lbl_0802528c: .4byte 0xffffff00
lbl_08025290:
    movs r2, #0x80
    lsls r2, r2, #1
    adds r0, r4, r2
    b lbl_08025300
lbl_08025298:
    ldr r0, lbl_080252c0 @ =gSamusPhysics
    adds r0, #0x70
    ldrh r0, [r0]
    mov r1, sb
    ldrh r1, [r1, #0x14]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r2, sb
    ldrh r4, [r2, #0x12]
    movs r7, #0x1e
    movs r5, #0x28
    mov r1, ip
    ldrh r0, [r1, #8]
    cmp r0, #1
    beq lbl_080252c4
    cmp r0, #3
    beq lbl_080252e0
    b lbl_08025304
    .align 2, 0
lbl_080252c0: .4byte gSamusPhysics
lbl_080252c4:
    adds r0, r6, #0
    subs r0, #0x20
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r2, ip
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_080252fc
    adds r0, r4, #0
    subs r0, #0x30
    b lbl_08025300
lbl_080252e0:
    adds r0, r6, #0
    adds r0, #0x20
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080252fc
    adds r0, r4, #0
    subs r0, #0x30
    b lbl_08025300
lbl_080252fc:
    adds r0, r4, #0
    adds r0, #0x30
lbl_08025300:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
lbl_08025304:
    mov r2, ip
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_08025354
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0802533c
    mov r0, ip
    ldrh r1, [r0, #4]
    subs r0, r4, #4
    cmp r1, r0
    bgt lbl_08025368
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r5
    bhs lbl_08025336
    adds r0, #1
    strb r0, [r1]
lbl_08025336:
    ldrb r0, [r1]
    lsrs r0, r0, #2
    b lbl_08025348
lbl_0802533c:
    subs r1, r0, #1
    strb r1, [r2]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_080253ca
    lsrs r0, r0, #0x1a
lbl_08025348:
    mov r1, ip
    ldrh r1, [r1, #4]
    adds r0, r0, r1
    mov r2, ip
    strh r0, [r2, #4]
    b lbl_080253d4
lbl_08025354:
    mov r2, ip
    adds r2, #0x2d
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_08025396
    mov r0, ip
    ldrh r1, [r0, #4]
    adds r0, r4, #4
    cmp r1, r0
    bge lbl_08025372
lbl_08025368:
    mov r0, ip
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_080253d4
lbl_08025372:
    mov r1, ip
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, r5
    bhs lbl_08025380
    adds r0, #1
    strb r0, [r1]
lbl_08025380:
    ldrb r0, [r1]
    lsrs r5, r0, #2
    mov r1, ip
    ldrh r0, [r1, #4]
    subs r1, r0, r5
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    bne lbl_080253b2
    b lbl_080253c4
lbl_08025396:
    subs r1, r0, #1
    strb r1, [r2]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_080253ca
    lsrs r5, r0, #0x1a
    mov r1, ip
    ldrh r0, [r1, #4]
    subs r1, r0, r5
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_080253c4
lbl_080253b2:
    ldr r0, [sp]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    strb r3, [r2]
    mov r2, ip
    strh r3, [r2, #4]
    b lbl_080253d4
lbl_080253c4:
    mov r0, ip
    strh r1, [r0, #4]
    b lbl_080253d4
lbl_080253ca:
    ldr r0, [sp]
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
lbl_080253d4:
    ldr r1, [sp]
    cmp r1, #0
    beq lbl_08025404
    mov r2, ip
    ldrh r0, [r2]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    eors r0, r1
    mov r1, ip
    strh r0, [r1]
    adds r1, #0x2e
    movs r0, #1
    strb r0, [r1]
    mov r2, ip
    ldrh r0, [r2, #8]
    adds r0, #1
    strh r0, [r2, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08025404
    movs r0, #0
    strh r0, [r2, #8]
lbl_08025404:
    movs r0, #0
    str r0, [sp]
    mov r2, ip
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_08025462
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0802544a
    mov r0, ip
    ldrh r1, [r0, #2]
    subs r0, r6, #4
    cmp r1, r0
    ble lbl_08025436
    mov r0, ip
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_080254e2
lbl_08025436:
    mov r1, ip
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, r7
    bhs lbl_08025444
    adds r0, #1
    strb r0, [r1]
lbl_08025444:
    ldrb r0, [r1]
    lsrs r0, r0, #2
    b lbl_08025456
lbl_0802544a:
    subs r1, r0, #1
    strb r1, [r2]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_080254e8
    lsrs r0, r0, #0x1a
lbl_08025456:
    mov r1, ip
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    mov r2, ip
    strh r0, [r2, #2]
    b lbl_080254e2
lbl_08025462:
    mov r4, ip
    adds r4, #0x2c
    ldrb r0, [r4]
    adds r2, r0, #0
    cmp r2, #0
    bne lbl_080254b0
    mov r0, ip
    ldrh r1, [r0, #2]
    adds r0, r6, #4
    cmp r1, r0
    bge lbl_08025482
    mov r0, ip
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r4]
    b lbl_080254e2
lbl_08025482:
    mov r1, ip
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, r7
    bhs lbl_08025490
    adds r0, #1
    strb r0, [r1]
lbl_08025490:
    ldrb r0, [r1]
    lsrs r5, r0, #2
    mov r1, ip
    ldrh r0, [r1, #2]
    subs r1, r0, r5
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_080254d8
    movs r0, #1
    str r0, [sp]
    strb r2, [r4]
    mov r1, ip
    strh r2, [r1, #2]
    b lbl_080254e2
lbl_080254b0:
    subs r1, r0, #1
    strb r1, [r4]
    lsls r0, r1, #0x18
    cmp r0, #0
    beq lbl_080254de
    lsrs r5, r0, #0x1a
    mov r1, ip
    ldrh r0, [r1, #2]
    subs r1, r0, r5
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_080254d8
    movs r2, #1
    str r2, [sp]
    strb r3, [r4]
    mov r0, ip
    strh r3, [r0, #2]
    b lbl_080254e2
lbl_080254d8:
    mov r2, ip
    strh r1, [r2, #2]
    b lbl_080254e2
lbl_080254de:
    movs r0, #1
    str r0, [sp]
lbl_080254e2:
    ldr r1, [sp]
    cmp r1, #0
    beq lbl_080254fe
lbl_080254e8:
    mov r2, ip
    ldrh r0, [r2]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r1, r2, #0
    eors r0, r1
    mov r1, ip
    strh r0, [r1]
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_080254fe:
    mov r2, ip
    ldrh r0, [r2, #0x12]
    subs r0, #1
    strh r0, [r2, #0x12]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_08025522
    movs r0, #0x20
    strh r0, [r2, #0x12]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08025522
    movs r0, #0xaf
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_08025522:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start Hive
Hive: @ 0x08025534
    push {r4, r5, lr}
    ldr r4, lbl_0802555c @ =gCurrentSprite
    adds r5, r4, #0
    adds r5, #0x30
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_08025560
    bl SpriteUtilUpdateFreezeTimer
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r1, [r0]
    movs r0, #0x11
    bl SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
    ldrb r1, [r5]
    adds r0, r4, #0
    adds r0, #0x2c
    strb r1, [r0]
    b lbl_080255b2
    .align 2, 0
lbl_0802555c: .4byte gCurrentSprite
lbl_08025560:
    bl SpriteUtilIsSpriteStunned
    cmp r0, #0
    bne lbl_080255b2
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x25
    beq lbl_080255a2
    cmp r0, #0x25
    bgt lbl_0802558a
    cmp r0, #9
    beq lbl_08025596
    cmp r0, #9
    bgt lbl_08025584
    cmp r0, #0
    beq lbl_08025590
    b lbl_080255ae
lbl_08025584:
    cmp r0, #0x23
    beq lbl_0802559c
    b lbl_080255ae
lbl_0802558a:
    cmp r0, #0x67
    beq lbl_080255a8
    b lbl_080255ae
lbl_08025590:
    bl HiveInit
    b lbl_080255b2
lbl_08025596:
    bl HivePhase1
    b lbl_080255b2
lbl_0802559c:
    bl HivePhase2
    b lbl_080255b2
lbl_080255a2:
    bl HivePhase3
    b lbl_080255b2
lbl_080255a8:
    bl HiveIgnoreSamusCollision
    b lbl_080255b2
lbl_080255ae:
    bl HiveDying
lbl_080255b2:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start HiveRoots
HiveRoots: @ 0x080255b8
    push {r4, r5, r6, lr}
    ldr r2, lbl_08025614 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r4, [r0]
    adds r1, r2, #0
    adds r1, #0x26
    movs r5, #0
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_08025618 @ =gSpriteData
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r3, r0, r1
    ldrb r0, [r3, #0x1d]
    mov ip, r2
    adds r6, r1, #0
    cmp r0, #0x4b
    bne lbl_08025620
    adds r0, r3, #0
    adds r0, #0x20
    ldrb r1, [r0]
    mov r0, ip
    adds r0, #0x20
    strb r1, [r0]
    ldr r2, lbl_0802561c @ =0x082b0d68
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    ldrh r1, [r3, #0x14]
    lsrs r0, r0, #1
    cmp r1, r0
    bhs lbl_08025626
    adds r0, r3, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08025626
    mov r0, ip
    strh r5, [r0]
    b lbl_0802565c
    .align 2, 0
lbl_08025614: .4byte gCurrentSprite
lbl_08025618: .4byte gSpriteData
lbl_0802561c: .4byte 0x082b0d68
lbl_08025620:
    mov r1, ip
    strh r5, [r1]
    b lbl_0802565c
lbl_08025626:
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0802563a
    mov r1, ip
    strh r0, [r1]
    b lbl_0802565c
lbl_0802563a:
    mov r0, ip
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0802564a
    bl SpriteUtilUpdateFreezeTimer
    b lbl_0802565c
lbl_0802564a:
    mov r0, ip
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08025658
    bl HiveRootsInit
lbl_08025658:
    bl HiveRootsMove
lbl_0802565c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start Mellow
Mellow: @ 0x08025664
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_080256a0 @ =gCurrentSprite
    adds r2, r4, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r3, #2
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08025690
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r4]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08025690
    ldr r0, lbl_080256a4 @ =0x0000015f
    bl SoundPlayNotAlreadyPlaying
lbl_08025690:
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080256a8
    bl SpriteUtilUpdateFreezeTimer
    b lbl_080257ae
    .align 2, 0
lbl_080256a0: .4byte gCurrentSprite
lbl_080256a4: .4byte 0x0000015f
lbl_080256a8:
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x24
    cmp r0, #9
    bls lbl_080256cc
    ldrb r0, [r1]
    cmp r0, #0x61
    bhi lbl_080256cc
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    beq lbl_080257ae
    subs r0, #1
    strb r0, [r4, #0x1c]
    b lbl_080257ae
lbl_080256cc:
    ldrb r0, [r1]
    cmp r0, #0x25
    bhi lbl_0802579e
    lsls r0, r0, #2
    ldr r1, lbl_080256dc @ =lbl_080256e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080256dc: .4byte lbl_080256e0
lbl_080256e0: @ jump table
    .4byte lbl_08025778 @ case 0
    .4byte lbl_0802579e @ case 1
    .4byte lbl_0802579e @ case 2
    .4byte lbl_0802579e @ case 3
    .4byte lbl_0802579e @ case 4
    .4byte lbl_0802579e @ case 5
    .4byte lbl_0802579e @ case 6
    .4byte lbl_0802579e @ case 7
    .4byte lbl_0802579e @ case 8
    .4byte lbl_08025780 @ case 9
    .4byte lbl_0802579e @ case 10
    .4byte lbl_0802579e @ case 11
    .4byte lbl_0802579e @ case 12
    .4byte lbl_0802579e @ case 13
    .4byte lbl_0802579e @ case 14
    .4byte lbl_0802579e @ case 15
    .4byte lbl_0802579e @ case 16
    .4byte lbl_0802579e @ case 17
    .4byte lbl_0802579e @ case 18
    .4byte lbl_0802579e @ case 19
    .4byte lbl_0802579e @ case 20
    .4byte lbl_0802579e @ case 21
    .4byte lbl_0802579e @ case 22
    .4byte lbl_0802579e @ case 23
    .4byte lbl_0802579e @ case 24
    .4byte lbl_0802579e @ case 25
    .4byte lbl_0802579e @ case 26
    .4byte lbl_0802579e @ case 27
    .4byte lbl_0802579e @ case 28
    .4byte lbl_0802579e @ case 29
    .4byte lbl_0802579e @ case 30
    .4byte lbl_0802579e @ case 31
    .4byte lbl_0802579e @ case 32
    .4byte lbl_0802579e @ case 33
    .4byte lbl_08025788 @ case 34
    .4byte lbl_0802578e @ case 35
    .4byte lbl_0802579e @ case 36
    .4byte lbl_08025796 @ case 37
lbl_08025778:
    adds r0, r4, #0
    bl MellowInit
    b lbl_080257ae
lbl_08025780:
    adds r0, r4, #0
    bl MellowIdle
    b lbl_080257ae
lbl_08025788:
    adds r0, r4, #0
    bl MellowSamusDetectedInit
lbl_0802578e:
    adds r0, r4, #0
    bl MellowMove
    b lbl_080257ae
lbl_08025796:
    adds r0, r4, #0
    bl MellowFleeing
    b lbl_080257ae
lbl_0802579e:
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_080257ae:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MellowSwarm
MellowSwarm: @ 0x080257b8
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    movs r6, #0
    ldr r1, lbl_080257e4 @ =gCurrentSprite
    adds r0, r1, #0
    adds r0, #0x26
    movs r5, #1
    strb r5, [r0]
    adds r7, r1, #0
    adds r7, #0x24
    ldrb r0, [r7]
    adds r4, r1, #0
    cmp r0, #0
    bne lbl_080258b6
    movs r0, #3
    movs r1, #0x2c
    bl EventFunction
    cmp r0, #0
    beq lbl_080257e8
    strh r6, [r4]
    b lbl_0802598c
    .align 2, 0
lbl_080257e4: .4byte gCurrentSprite
lbl_080257e8:
    ldrh r1, [r4]
    ldr r2, lbl_08025858 @ =0x00008004
    adds r0, r2, #0
    movs r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldr r1, lbl_0802585c @ =0x0000fffc
    strh r1, [r4, #0xa]
    movs r0, #4
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r0, r4, #0
    adds r0, #0x27
    strb r5, [r0]
    adds r0, #1
    strb r5, [r0]
    adds r0, #1
    strb r5, [r0]
    subs r0, #4
    strb r2, [r0]
    ldr r0, lbl_08025860 @ =0x082da88c
    str r0, [r4, #0x18]
    strh r6, [r4, #0x16]
    strb r2, [r4, #0x1c]
    movs r3, #9
    strb r3, [r7]
    ldr r0, lbl_08025864 @ =gSamusData
    ldrh r1, [r0, #0x12]
    lsrs r1, r1, #2
    ldr r0, lbl_08025868 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    cmp r1, #0x78
    ble lbl_08025838
    ldrh r0, [r4]
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r4]
lbl_08025838:
    movs r0, #0xf0
    strh r0, [r4, #6]
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x85
    bne lbl_080258ac
    ldr r0, lbl_0802586c @ =gEquipment
    ldrh r1, [r0, #6]
    ldr r0, lbl_08025870 @ =0x0000018f
    cmp r1, r0
    bls lbl_08025874
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0xf
    strb r0, [r1]
    b lbl_0802598c
    .align 2, 0
lbl_08025858: .4byte 0x00008004
lbl_0802585c: .4byte 0x0000fffc
lbl_08025860: .4byte 0x082da88c
lbl_08025864: .4byte gSamusData
lbl_08025868: .4byte gBG1XPosition
lbl_0802586c: .4byte gEquipment
lbl_08025870: .4byte 0x0000018f
lbl_08025874:
    ldr r0, lbl_08025884 @ =0x0000012b
    cmp r1, r0
    bls lbl_08025888
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0xc
    strb r0, [r1]
    b lbl_0802598c
    .align 2, 0
lbl_08025884: .4byte 0x0000012b
lbl_08025888:
    cmp r1, #0xc7
    bls lbl_08025894
    adds r0, r4, #0
    adds r0, #0x2e
    strb r3, [r0]
    b lbl_0802598c
lbl_08025894:
    cmp r1, #0x63
    bls lbl_080258a2
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #6
    strb r0, [r1]
    b lbl_0802598c
lbl_080258a2:
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #3
    strb r0, [r1]
    b lbl_0802598c
lbl_080258ac:
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #5
    strb r0, [r1]
    b lbl_0802598c
lbl_080258b6:
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_080258ce
    ldrh r0, [r4, #6]
    cmp r0, #0
    beq lbl_080258ce
    subs r0, #1
    strh r0, [r4, #6]
    b lbl_0802598c
lbl_080258ce:
    movs r7, #0x12
    ldr r2, lbl_08025920 @ =gSpriteData
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_08025900
    movs r5, #1
    adds r3, r0, #0
lbl_080258e0:
    ldrh r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080258fa
    adds r0, r2, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, r7
    bne lbl_080258fa
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_080258fa:
    adds r2, #0x38
    cmp r2, r3
    blo lbl_080258e0
lbl_08025900:
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08025924
    adds r0, r4, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r6, r0
    blo lbl_0802592c
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    b lbl_0802598c
    .align 2, 0
lbl_08025920: .4byte gSpriteData
lbl_08025924:
    cmp r6, #0x13
    bhi lbl_0802598c
    movs r0, #0xf0
    strh r0, [r4, #6]
lbl_0802592c:
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08025950
    ldr r0, lbl_08025948 @ =gSamusData
    ldr r2, lbl_0802594c @ =gSpriteRNG
    ldrb r1, [r2]
    lsls r1, r1, #5
    ldrh r0, [r0, #0x12]
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    b lbl_08025960
    .align 2, 0
lbl_08025948: .4byte gSamusData
lbl_0802594c: .4byte gSpriteRNG
lbl_08025950:
    ldr r0, lbl_08025994 @ =gSamusData
    ldr r2, lbl_08025998 @ =gSpriteRNG
    ldrb r1, [r2]
    lsls r1, r1, #5
    ldrh r0, [r0, #0x12]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
lbl_08025960:
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r5
    cmp r0, #0
    beq lbl_0802596c
    movs r5, #0
lbl_0802596c:
    ldr r1, lbl_0802599c @ =gBG1YPosition
    ldrb r0, [r2]
    lsls r0, r0, #1
    adds r0, #0x10
    ldrh r3, [r1]
    subs r3, r3, r0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrb r2, [r4, #0x1f]
    str r5, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x4a
    movs r1, #0x88
    bl SpriteSpawnPrimary
lbl_0802598c:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08025994: .4byte gSamusData
lbl_08025998: .4byte gSpriteRNG
lbl_0802599c: .4byte gBG1YPosition
