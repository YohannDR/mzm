    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start AtomicSmoothMovement
AtomicSmoothMovement: @ 0x0803b944
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #2
    mov sb, r0
    ldr r0, lbl_0803b980 @ =gArmCannonY
    ldrh r0, [r0]
    str r0, [sp]
    ldr r0, lbl_0803b984 @ =gArmCannonX
    ldrh r0, [r0]
    mov sl, r0
    movs r7, #0
    movs r1, #0
    mov r8, r1
    ldr r0, lbl_0803b988 @ =gCurrentSprite
    ldrh r5, [r0, #2]
    ldrh r6, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803b98c
    adds r4, r6, #0
    adds r4, #0x20
    b lbl_0803b990
    .align 2, 0
lbl_0803b980: .4byte gArmCannonY
lbl_0803b984: .4byte gArmCannonX
lbl_0803b988: .4byte gCurrentSprite
lbl_0803b98c:
    adds r4, r6, #0
    subs r4, #0x20
lbl_0803b990:
    adds r0, r5, #0
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803b9b8
    adds r0, r5, #0
    adds r0, #0x20
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803b9b8
    adds r0, r5, #0
    subs r0, #0x20
    adds r1, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0803b9ba
lbl_0803b9b8:
    movs r7, #1
lbl_0803b9ba:
    ldr r0, lbl_0803b9d0 @ =gCurrentSprite
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0803b9d4
    adds r4, r5, #0
    adds r4, #0x20
    b lbl_0803b9d8
    .align 2, 0
lbl_0803b9d0: .4byte gCurrentSprite
lbl_0803b9d4:
    adds r4, r5, #0
    subs r4, #0x20
lbl_0803b9d8:
    adds r0, r4, #0
    adds r1, r6, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803ba00
    adds r1, r6, #0
    adds r1, #0x20
    adds r0, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    bne lbl_0803ba00
    adds r1, r6, #0
    subs r1, #0x20
    adds r0, r4, #0
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0803ba0a
lbl_0803ba00:
    mov r0, r8
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
lbl_0803ba0a:
    movs r4, #0
    ldr r2, lbl_0803ba44 @ =gCurrentSprite
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803ba60
    cmp r7, #0
    bne lbl_0803bab6
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0803ba48
    ldrh r1, [r2, #4]
    mov r0, sl
    subs r0, #4
    cmp r1, r0
    bgt lbl_0803ba78
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0x14
    bhs lbl_0803ba40
    adds r0, #1
    strb r0, [r1]
lbl_0803ba40:
    ldrb r0, [r1]
    b lbl_0803ba54
    .align 2, 0
lbl_0803ba44: .4byte gCurrentSprite
lbl_0803ba48:
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803bab6
    ldrb r0, [r3]
lbl_0803ba54:
    mov r3, sb
    asrs r0, r3
    ldrh r1, [r2, #4]
    adds r0, r0, r1
    strh r0, [r2, #4]
    b lbl_0803bab2
lbl_0803ba60:
    cmp r7, #0
    bne lbl_0803bab0
    adds r3, r2, #0
    adds r3, #0x2d
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0803ba98
    ldrh r1, [r2, #4]
    mov r0, sl
    adds r0, #4
    cmp r1, r0
    bge lbl_0803ba82
lbl_0803ba78:
    adds r0, r2, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    strb r0, [r3]
    b lbl_0803bab2
lbl_0803ba82:
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0x14
    bhs lbl_0803ba90
    adds r0, #1
    strb r0, [r1]
lbl_0803ba90:
    ldrb r1, [r1]
    mov r3, sb
    asrs r1, r3
    b lbl_0803baa8
lbl_0803ba98:
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803bab6
    ldrb r1, [r3]
    mov r0, sb
    asrs r1, r0
lbl_0803baa8:
    ldrh r0, [r2, #4]
    subs r0, r0, r1
    strh r0, [r2, #4]
    b lbl_0803bab2
lbl_0803bab0:
    movs r4, #1
lbl_0803bab2:
    cmp r4, #0
    beq lbl_0803baca
lbl_0803bab6:
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x2e
    movs r0, #1
    strb r0, [r1]
lbl_0803baca:
    movs r4, #0
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0803bb1c
    mov r0, r8
    cmp r0, #0
    bne lbl_0803bb74
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0803bb04
    ldrh r1, [r2, #2]
    ldr r0, [sp]
    subs r0, #4
    cmp r1, r0
    bgt lbl_0803bb36
    adds r1, r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0x14
    bhs lbl_0803bb00
    adds r0, #1
    strb r0, [r1]
lbl_0803bb00:
    ldrb r0, [r1]
    b lbl_0803bb10
lbl_0803bb04:
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803bb74
    ldrb r0, [r3]
lbl_0803bb10:
    mov r1, sb
    asrs r0, r1
    ldrh r3, [r2, #2]
    adds r0, r0, r3
    strh r0, [r2, #2]
    b lbl_0803bb70
lbl_0803bb1c:
    mov r0, r8
    cmp r0, #0
    bne lbl_0803bb6e
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0803bb56
    ldrh r1, [r2, #2]
    ldr r0, [sp]
    adds r0, #4
    cmp r1, r0
    bge lbl_0803bb40
lbl_0803bb36:
    adds r0, r2, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    strb r0, [r3]
    b lbl_0803bb70
lbl_0803bb40:
    adds r1, r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0x14
    bhs lbl_0803bb4e
    adds r0, #1
    strb r0, [r1]
lbl_0803bb4e:
    ldrb r1, [r1]
    mov r3, sb
    asrs r1, r3
    b lbl_0803bb66
lbl_0803bb56:
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803bb74
    ldrb r1, [r3]
    mov r0, sb
    asrs r1, r0
lbl_0803bb66:
    ldrh r0, [r2, #2]
    subs r0, r0, r1
    strh r0, [r2, #2]
    b lbl_0803bb70
lbl_0803bb6e:
    movs r4, #1
lbl_0803bb70:
    cmp r4, #0
    beq lbl_0803bb88
lbl_0803bb74:
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    eors r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x2f
    movs r0, #1
    strb r0, [r1]
lbl_0803bb88:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start AtomicUpdateDirectionToFleeSamus
AtomicUpdateDirectionToFleeSamus: @ 0x0803bb98
    push {r4, r5, r6, lr}
    ldr r2, lbl_0803bbe4 @ =gCurrentSprite
    ldrh r4, [r2, #2]
    ldrh r6, [r2, #4]
    ldr r0, lbl_0803bbe8 @ =gSamusData
    ldrh r1, [r0, #0x14]
    subs r1, #0x48
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrh r5, [r0, #0x12]
    ldr r3, lbl_0803bbec @ =0xfffffec0
    adds r0, r1, r3
    adds r3, r2, #0
    cmp r4, r0
    ble lbl_0803bc2a
    movs r2, #0xa0
    lsls r2, r2, #1
    adds r0, r1, r2
    cmp r4, r0
    bge lbl_0803bc2a
    ldr r2, lbl_0803bbec @ =0xfffffec0
    adds r0, r5, r2
    cmp r6, r0
    ble lbl_0803bc2a
    movs r2, #0xa0
    lsls r2, r2, #1
    adds r0, r5, r2
    cmp r6, r0
    bge lbl_0803bc2a
    cmp r4, r1
    bls lbl_0803bbf0
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r0, r1
    b lbl_0803bbf6
    .align 2, 0
lbl_0803bbe4: .4byte gCurrentSprite
lbl_0803bbe8: .4byte gSamusData
lbl_0803bbec: .4byte 0xfffffec0
lbl_0803bbf0:
    ldrh r1, [r3]
    ldr r0, lbl_0803bc08 @ =0x0000fbff
    ands r0, r1
lbl_0803bbf6:
    strh r0, [r3]
    cmp r6, r5
    bls lbl_0803bc0c
    ldrh r1, [r3]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    orrs r0, r1
    b lbl_0803bc12
    .align 2, 0
lbl_0803bc08: .4byte 0x0000fbff
lbl_0803bc0c:
    ldrh r1, [r3]
    ldr r0, lbl_0803bc30 @ =0x0000fdff
    ands r0, r1
lbl_0803bc12:
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x23
    strb r0, [r1]
    adds r1, #0xb
    movs r0, #4
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r2, [r0]
lbl_0803bc2a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803bc30: .4byte 0x0000fdff

    thumb_func_start AtomicCheckShootElectricity
AtomicCheckShootElectricity: @ 0x0803bc34
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r0, lbl_0803bc7c @ =gCurrentSprite
    mov ip, r0
    ldrh r0, [r0, #0x12]
    cmp r0, #0
    beq lbl_0803bc80
    subs r0, #1
    mov r1, ip
    strh r0, [r1, #0x12]
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    bne lbl_0803bce2
    adds r1, #0x2d
    movs r0, #0
    strb r0, [r1]
    subs r1, #3
    movs r0, #1
    strb r0, [r1]
    mov r5, ip
    ldrb r1, [r5, #0x1e]
    ldrb r2, [r5, #0x1f]
    mov r0, ip
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r5, #2]
    str r0, [sp]
    ldrh r0, [r5, #4]
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x1f
    bl SpriteSpawnSecondary
    b lbl_0803bce2
    .align 2, 0
lbl_0803bc7c: .4byte gCurrentSprite
lbl_0803bc80:
    mov r5, ip
    adds r5, #0x2a
    ldrb r0, [r5]
    subs r0, #1
    strb r0, [r5]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0803bce2
    mov r2, ip
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r1, r0, #1
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r1, lbl_0803bcd8 @ =0x0875f730
    lsls r2, r4, #1
    adds r0, r2, r1
    ldrb r3, [r0]
    mov r0, ip
    adds r0, #0x34
    strb r3, [r0]
    subs r0, #0x14
    strb r3, [r0]
    adds r1, #1
    adds r2, r2, r1
    ldrb r2, [r2]
    cmp r2, #0
    beq lbl_0803bcdc
    strb r2, [r5]
    cmp r4, #0x10
    bne lbl_0803bce2
    mov r0, ip
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803bce2
    movs r0, #0x98
    lsls r0, r0, #2
    bl SoundPlayNotAlreadyPlaying
    b lbl_0803bce2
    .align 2, 0
lbl_0803bcd8: .4byte 0x0875f730
lbl_0803bcdc:
    movs r0, #0xc8
    mov r1, ip
    strh r0, [r1, #0x12]
lbl_0803bce2:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AtomicInit
AtomicInit: @ 0x0803bcec
    push {r4, lr}
    ldr r0, lbl_0803bcfc @ =gDifficulty
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_0803bd04
    ldr r0, lbl_0803bd00 @ =gCurrentSprite
    strh r1, [r0]
    b lbl_0803bd60
    .align 2, 0
lbl_0803bcfc: .4byte gDifficulty
lbl_0803bd00: .4byte gCurrentSprite
lbl_0803bd04:
    ldr r0, lbl_0803bd68 @ =gCurrentSprite
    mov ip, r0
    adds r0, #0x27
    movs r3, #0
    movs r1, #0xc
    strb r1, [r0]
    mov r0, ip
    adds r0, #0x28
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r2, #0
    ldr r1, lbl_0803bd6c @ =0x0000ffe0
    mov r4, ip
    strh r1, [r4, #0xa]
    movs r0, #0x20
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    ldr r0, lbl_0803bd70 @ =0x082f7998
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    ldr r2, lbl_0803bd74 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    mov r1, ip
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    subs r1, #1
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #2]
    strh r0, [r4, #6]
    ldrh r0, [r4, #4]
    strh r0, [r4, #8]
    ldr r0, lbl_0803bd78 @ =gSpriteRng
    ldrb r0, [r0]
    lsls r0, r0, #4
    strh r0, [r4, #0x12]
lbl_0803bd60:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803bd68: .4byte gCurrentSprite
lbl_0803bd6c: .4byte 0x0000ffe0
lbl_0803bd70: .4byte 0x082f7998
lbl_0803bd74: .4byte 0x082b0d68
lbl_0803bd78: .4byte gSpriteRng

    thumb_func_start AtomicIdleInit
AtomicIdleInit: @ 0x0803bd7c
    ldr r3, lbl_0803bda0 @ =gCurrentSprite
    adds r1, r3, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_0803bda4 @ =0x082f7998
    str r0, [r3, #0x18]
    strb r2, [r3, #0x1c]
    movs r1, #0
    strh r2, [r3, #0x16]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r1, [r0]
    subs r0, #1
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0803bda0: .4byte gCurrentSprite
lbl_0803bda4: .4byte 0x082f7998

    thumb_func_start AtomicIdle
AtomicIdle: @ 0x0803bda8
    push {r4, r5, r6, lr}
    ldr r0, lbl_0803bdbc @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0x3f
    bls lbl_0803bdc4
    ldr r0, lbl_0803bdc0 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0x26
    strb r1, [r0]
    b lbl_0803be20
    .align 2, 0
lbl_0803bdbc: .4byte gSamusWeaponInfo
lbl_0803bdc0: .4byte gCurrentSprite
lbl_0803bdc4:
    ldr r3, lbl_0803be28 @ =gCurrentSprite
    movs r0, #0x2f
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    ldr r4, lbl_0803be2c @ =0x082f67fc
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r5, lbl_0803be30 @ =0x00007fff
    cmp r1, r5
    bne lbl_0803bde4
    movs r6, #0
    ldrsh r1, [r4, r6]
    movs r2, #0
lbl_0803bde4:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #2]
    adds r0, r0, r1
    strh r0, [r3, #2]
    movs r6, #0x2e
    adds r6, r6, r3
    mov ip, r6
    ldrb r2, [r6]
    ldr r4, lbl_0803be34 @ =0x082f687e
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r6, #0
    ldrsh r1, [r0, r6]
    cmp r1, r5
    bne lbl_0803be0c
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0
lbl_0803be0c:
    adds r0, r2, #1
    mov r2, ip
    strb r0, [r2]
    ldrh r0, [r3, #4]
    adds r0, r0, r1
    strh r0, [r3, #4]
    bl AtomicUpdateDirectionToFleeSamus
    bl AtomicCheckShootElectricity
lbl_0803be20:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803be28: .4byte gCurrentSprite
lbl_0803be2c: .4byte 0x082f67fc
lbl_0803be30: .4byte 0x00007fff
lbl_0803be34: .4byte 0x082f687e

    thumb_func_start AtomicMove
AtomicMove: @ 0x0803be38
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0803be50 @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0x3f
    bls lbl_0803be58
    ldr r0, lbl_0803be54 @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0x26
    strb r1, [r0]
    b lbl_0803bf70
    .align 2, 0
lbl_0803be50: .4byte gSamusWeaponInfo
lbl_0803be54: .4byte gCurrentSprite
lbl_0803be58:
    ldr r3, lbl_0803be78 @ =gCurrentSprite
    ldrh r7, [r3, #2]
    ldrh r6, [r3, #4]
    adds r1, r3, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r2, r0, #1
    strb r2, [r1]
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x50
    bls lbl_0803be7c
    subs r1, #8
    movs r0, #0x25
    strb r0, [r1]
    b lbl_0803bf70
    .align 2, 0
lbl_0803be78: .4byte gCurrentSprite
lbl_0803be7c:
    movs r0, #0xf
    ands r2, r0
    cmp r2, #0
    bne lbl_0803be92
    adds r1, r3, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0803be92
    subs r0, #1
    strb r0, [r1]
lbl_0803be92:
    ldr r4, lbl_0803bec4 @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x2f
    ldrb r5, [r0]
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    mov r8, r0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803bed8
    adds r0, r7, #0
    adds r0, #0x20
    adds r1, r6, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803bec8 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803becc
    ldrh r0, [r4, #2]
    adds r0, r5, r0
    strh r0, [r4, #2]
    b lbl_0803bf00
    .align 2, 0
lbl_0803bec4: .4byte gCurrentSprite
lbl_0803bec8: .4byte gPreviousCollisionCheck
lbl_0803becc:
    ldrh r1, [r4]
    ldr r0, lbl_0803bed4 @ =0x0000fbff
    ands r0, r1
    b lbl_0803befe
    .align 2, 0
lbl_0803bed4: .4byte 0x0000fbff
lbl_0803bed8:
    adds r0, r7, #0
    subs r0, #0x20
    adds r1, r6, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803bef4 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803bef8
    ldrh r0, [r4, #2]
    subs r0, r0, r5
    strh r0, [r4, #2]
    b lbl_0803bf00
    .align 2, 0
lbl_0803bef4: .4byte gPreviousCollisionCheck
lbl_0803bef8:
    ldrh r1, [r4]
    mov r0, r8
    orrs r0, r1
lbl_0803befe:
    strh r0, [r4]
lbl_0803bf00:
    ldr r4, lbl_0803bf2c @ =gCurrentSprite
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    mov r8, r0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803bf40
    adds r1, r6, #0
    adds r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803bf30 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803bf34
    ldrh r0, [r4, #4]
    adds r0, r5, r0
    strh r0, [r4, #4]
    b lbl_0803bf68
    .align 2, 0
lbl_0803bf2c: .4byte gCurrentSprite
lbl_0803bf30: .4byte gPreviousCollisionCheck
lbl_0803bf34:
    ldrh r1, [r4]
    ldr r0, lbl_0803bf3c @ =0x0000fdff
    ands r0, r1
    b lbl_0803bf66
    .align 2, 0
lbl_0803bf3c: .4byte 0x0000fdff
lbl_0803bf40:
    adds r1, r6, #0
    subs r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803bf5c @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803bf60
    ldrh r0, [r4, #4]
    subs r0, r0, r5
    strh r0, [r4, #4]
    b lbl_0803bf68
    .align 2, 0
lbl_0803bf5c: .4byte gPreviousCollisionCheck
lbl_0803bf60:
    ldrh r1, [r4]
    mov r0, r8
    orrs r0, r1
lbl_0803bf66:
    strh r0, [r4]
lbl_0803bf68:
    bl AtomicUpdateDirectionToFleeSamus
    bl AtomicCheckShootElectricity
lbl_0803bf70:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AtomicMoveBackToIdle
AtomicMoveBackToIdle: @ 0x0803bf7c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_0803bf98 @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0x3f
    bls lbl_0803bfa0
    ldr r0, lbl_0803bf9c @ =gCurrentSprite
    adds r0, #0x24
    movs r1, #0x26
    strb r1, [r0]
    b lbl_0803c0d8
    .align 2, 0
lbl_0803bf98: .4byte gSamusWeaponInfo
lbl_0803bf9c: .4byte gCurrentSprite
lbl_0803bfa0:
    ldr r0, lbl_0803bfcc @ =0x0000fffc
    mov r8, r0
    ldr r0, lbl_0803bfd0 @ =gCurrentSprite
    ldrh r1, [r0, #6]
    mov sb, r1
    ldrh r5, [r0, #8]
    ldrh r7, [r0, #2]
    ldrh r6, [r0, #4]
    mov r3, sb
    mov r2, r8
    ands r3, r2
    adds r2, r7, #0
    mov r1, r8
    ands r2, r1
    adds r4, r0, #0
    cmp r3, r2
    bhs lbl_0803bfd8
    ldrh r1, [r4]
    ldr r0, lbl_0803bfd4 @ =0x0000fbff
    ands r0, r1
    b lbl_0803bfe6
    .align 2, 0
lbl_0803bfcc: .4byte 0x0000fffc
lbl_0803bfd0: .4byte gCurrentSprite
lbl_0803bfd4: .4byte 0x0000fbff
lbl_0803bfd8:
    cmp r3, r2
    bls lbl_0803bfe8
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r0, r1
lbl_0803bfe6:
    strh r0, [r4]
lbl_0803bfe8:
    mov r3, r8
    ands r5, r3
    adds r1, r5, #0
    adds r0, r6, #0
    ands r0, r3
    mov sl, r1
    cmp r1, r0
    bhs lbl_0803c004
    ldrh r1, [r4]
    ldr r0, lbl_0803c000 @ =0x0000fdff
    ands r0, r1
    b lbl_0803c012
    .align 2, 0
lbl_0803c000: .4byte 0x0000fdff
lbl_0803c004:
    cmp r1, r0
    bls lbl_0803c014
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    orrs r0, r1
lbl_0803c012:
    strh r0, [r4]
lbl_0803c014:
    movs r5, #2
    ldr r4, lbl_0803c03c @ =gCurrentSprite
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c044
    adds r0, r7, #0
    adds r0, #0x20
    adds r1, r6, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803c040 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803c05c
    ldrh r0, [r4, #2]
    adds r0, #2
    b lbl_0803c05a
    .align 2, 0
lbl_0803c03c: .4byte gCurrentSprite
lbl_0803c040: .4byte gPreviousCollisionCheck
lbl_0803c044:
    adds r0, r7, #0
    subs r0, #0x20
    adds r1, r6, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803c084 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803c05c
    ldrh r0, [r4, #2]
    subs r0, #2
lbl_0803c05a:
    strh r0, [r4, #2]
lbl_0803c05c:
    ldr r4, lbl_0803c088 @ =gCurrentSprite
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c08c
    adds r1, r6, #0
    adds r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803c084 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803c0a4
    ldrh r0, [r4, #4]
    adds r0, r5, r0
    b lbl_0803c0a2
    .align 2, 0
lbl_0803c084: .4byte gPreviousCollisionCheck
lbl_0803c088: .4byte gCurrentSprite
lbl_0803c08c:
    adds r1, r6, #0
    subs r1, #0x20
    adds r0, r7, #0
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803c0c8 @ =gPreviousCollisionCheck
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803c0a4
    ldrh r0, [r4, #4]
    subs r0, r0, r5
lbl_0803c0a2:
    strh r0, [r4, #4]
lbl_0803c0a4:
    ldr r1, lbl_0803c0cc @ =gCurrentSprite
    ldrh r0, [r1, #2]
    mov r3, r8
    ands r0, r3
    mov r2, sb
    ands r2, r3
    mov sb, r2
    cmp r0, sb
    bne lbl_0803c0d0
    ldrh r0, [r1, #4]
    ands r0, r3
    cmp r0, sl
    bne lbl_0803c0d0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    b lbl_0803c0d8
    .align 2, 0
lbl_0803c0c8: .4byte gPreviousCollisionCheck
lbl_0803c0cc: .4byte gCurrentSprite
lbl_0803c0d0:
    bl AtomicUpdateDirectionToFleeSamus
    bl AtomicCheckShootElectricity
lbl_0803c0d8:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AtomicChasingSamusInit
AtomicChasingSamusInit: @ 0x0803c0e8
    ldr r3, lbl_0803c114 @ =gCurrentSprite
    adds r2, r3, #0
    adds r2, #0x24
    movs r1, #0
    movs r0, #0x27
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x34
    strb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    adds r0, #0xd
    strb r1, [r0]
    adds r0, #1
    movs r2, #1
    strb r2, [r0]
    subs r0, #2
    strb r1, [r0]
    adds r0, #3
    strb r2, [r0]
    bx lr
    .align 2, 0
lbl_0803c114: .4byte gCurrentSprite

    thumb_func_start AtomicChasingSamus
AtomicChasingSamus: @ 0x0803c118
    push {lr}
    ldr r0, lbl_0803c140 @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0
    bne lbl_0803c148
    ldr r2, lbl_0803c144 @ =gCurrentSprite
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r2, #0x12]
    cmp r0, #0
    bne lbl_0803c14c
    adds r1, #9
    strb r0, [r1]
    subs r1, #3
    movs r0, #1
    strb r0, [r1]
    b lbl_0803c14c
    .align 2, 0
lbl_0803c140: .4byte gSamusWeaponInfo
lbl_0803c144: .4byte gCurrentSprite
lbl_0803c148:
    bl AtomicSmoothMovement
lbl_0803c14c:
    pop {r0}
    bx r0

    thumb_func_start AtomicElectricityCheckAtomicDead
AtomicElectricityCheckAtomicDead: @ 0x0803c150
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_0803c174 @ =gSpriteData
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r2, r1, r2
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c170
    ldrb r0, [r2, #0x1d]
    cmp r0, #0x73
    beq lbl_0803c178
lbl_0803c170:
    movs r0, #1
    b lbl_0803c17a
    .align 2, 0
lbl_0803c174: .4byte gSpriteData
lbl_0803c178:
    movs r0, #0
lbl_0803c17a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start AtomicElectriciytInit
AtomicElectriciytInit: @ 0x0803c180
    push {r4, r5, lr}
    ldr r4, lbl_0803c19c @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r0, [r0]
    bl AtomicElectricityCheckAtomicDead
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    beq lbl_0803c1a0
    movs r0, #0
    strh r0, [r4]
    b lbl_0803c1ea
    .align 2, 0
lbl_0803c19c: .4byte gCurrentSprite
lbl_0803c1a0:
    ldrh r1, [r4]
    ldr r0, lbl_0803c1f0 @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    movs r5, #0x80
    lsls r5, r5, #8
    adds r1, r5, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x30
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0803c1f4 @ =0x0000fffc
    strh r1, [r4, #0xa]
    movs r0, #4
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    ldr r0, lbl_0803c1f8 @ =0x082f7c30
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x25
    strb r2, [r0]
    adds r1, #2
    movs r0, #8
    strb r0, [r1]
lbl_0803c1ea:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c1f0: .4byte 0x0000fffb
lbl_0803c1f4: .4byte 0x0000fffc
lbl_0803c1f8: .4byte 0x082f7c30

    thumb_func_start AtomicElectricitySpawn
AtomicElectricitySpawn: @ 0x0803c1fc
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_0803c21c @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r5, [r0]
    adds r0, r5, #0
    bl AtomicElectricityCheckAtomicDead
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    beq lbl_0803c220
    movs r0, #0
    strh r0, [r4]
    b lbl_0803c39c
    .align 2, 0
lbl_0803c21c: .4byte gCurrentSprite
lbl_0803c220:
    ldr r1, lbl_0803c288 @ =gSpriteData
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r1, [r0, #2]
    movs r7, #0
    strh r1, [r4, #2]
    ldrh r1, [r0, #4]
    strh r1, [r4, #4]
    ldrh r0, [r0, #0x12]
    cmp r0, #0xc8
    beq lbl_0803c23c
    b lbl_0803c39c
lbl_0803c23c:
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c24c
    ldr r0, lbl_0803c28c @ =0x00000261
    bl SoundPlayNotAlreadyPlaying
lbl_0803c24c:
    strb r7, [r4, #0x1c]
    strh r6, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #5
    strb r0, [r1]
    subs r1, #1
    movs r0, #9
    strb r0, [r1]
    ldrh r3, [r4, #2]
    ldrh r6, [r4, #4]
    ldr r1, lbl_0803c290 @ =gSamusData
    ldrh r0, [r1, #0x14]
    subs r0, #0x48
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldrh r5, [r1, #0x12]
    cmp r6, r5
    bhi lbl_0803c27a
    ldrh r0, [r4]
    movs r1, #0x40
    orrs r0, r1
    strh r0, [r4]
lbl_0803c27a:
    cmp r3, r2
    bls lbl_0803c294
    ldrh r0, [r4]
    movs r7, #0x80
    lsls r7, r7, #1
    b lbl_0803c29a
    .align 2, 0
lbl_0803c288: .4byte gSpriteData
lbl_0803c28c: .4byte 0x00000261
lbl_0803c290: .4byte gSamusData
lbl_0803c294:
    ldrh r0, [r4]
    movs r7, #0x80
    lsls r7, r7, #3
lbl_0803c29a:
    adds r1, r7, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r3, #0
    adds r0, #0x40
    cmp r0, r2
    ble lbl_0803c2f4
    subs r0, #0x80
    cmp r0, r2
    bge lbl_0803c2f4
    ldr r2, lbl_0803c2dc @ =gCurrentSprite
    ldr r0, lbl_0803c2e0 @ =0x082f7b20
    str r0, [r2, #0x18]
    adds r1, r2, #0
    adds r1, #0x2d
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0803c2e4 @ =0x0000ffe4
    strh r0, [r2, #0xa]
    movs r0, #0x1c
    strh r0, [r2, #0xc]
    ldrh r1, [r2]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0803c2e8
    movs r0, #0
    strh r0, [r2, #0xe]
    movs r0, #0xa0
    strh r0, [r2, #0x10]
    b lbl_0803c39c
    .align 2, 0
lbl_0803c2dc: .4byte gCurrentSprite
lbl_0803c2e0: .4byte 0x082f7b20
lbl_0803c2e4: .4byte 0x0000ffe4
lbl_0803c2e8:
    ldr r0, lbl_0803c2f0 @ =0x0000ff60
    strh r0, [r2, #0xe]
    strh r1, [r2, #0x10]
    b lbl_0803c39c
    .align 2, 0
lbl_0803c2f0: .4byte 0x0000ff60
lbl_0803c2f4:
    adds r0, r6, #0
    adds r0, #0x40
    cmp r0, r5
    ble lbl_0803c348
    subs r0, #0x80
    cmp r0, r5
    bge lbl_0803c348
    ldr r2, lbl_0803c330 @ =gCurrentSprite
    ldr r0, lbl_0803c334 @ =0x082f7a00
    str r0, [r2, #0x18]
    adds r1, r2, #0
    adds r1, #0x2d
    movs r0, #2
    strb r0, [r1]
    ldr r0, lbl_0803c338 @ =0x0000ffe4
    strh r0, [r2, #0xe]
    movs r0, #0x1c
    strh r0, [r2, #0x10]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0803c33c
    movs r0, #0
    strh r0, [r2, #0xa]
    movs r0, #0xa0
    b lbl_0803c39a
    .align 2, 0
lbl_0803c330: .4byte gCurrentSprite
lbl_0803c334: .4byte 0x082f7a00
lbl_0803c338: .4byte 0x0000ffe4
lbl_0803c33c:
    ldr r0, lbl_0803c344 @ =0x0000ff60
    strh r0, [r2, #0xa]
    strh r1, [r2, #0xc]
    b lbl_0803c39c
    .align 2, 0
lbl_0803c344: .4byte 0x0000ff60
lbl_0803c348:
    ldr r1, lbl_0803c36c @ =gCurrentSprite
    ldr r0, lbl_0803c370 @ =0x082f7a90
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    movs r0, #0
    strb r0, [r2]
    ldrh r2, [r1]
    movs r0, #0x40
    ands r0, r2
    adds r2, r1, #0
    cmp r0, #0
    beq lbl_0803c374
    movs r0, #0x20
    strh r0, [r2, #0xe]
    movs r0, #0x60
    b lbl_0803c37a
    .align 2, 0
lbl_0803c36c: .4byte gCurrentSprite
lbl_0803c370: .4byte 0x082f7a90
lbl_0803c374:
    ldr r0, lbl_0803c390 @ =0x0000ffa0
    strh r0, [r2, #0xe]
    adds r0, #0x40
lbl_0803c37a:
    strh r0, [r2, #0x10]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c394
    movs r0, #0x60
    strh r0, [r2, #0xa]
    movs r0, #0x20
    b lbl_0803c39a
    .align 2, 0
lbl_0803c390: .4byte 0x0000ffa0
lbl_0803c394:
    ldr r0, lbl_0803c3a4 @ =0x0000ffe0
    strh r0, [r2, #0xa]
    subs r0, #0x40
lbl_0803c39a:
    strh r0, [r2, #0xc]
lbl_0803c39c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c3a4: .4byte 0x0000ffe0

    thumb_func_start AtomicElectricityMove
AtomicElectricityMove: @ 0x0803c3a8
    push {r4, r5, lr}
    movs r3, #0x14
    ldr r2, lbl_0803c3d0 @ =gCurrentSprite
    adds r0, r2, #0
    adds r0, #0x2d
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    adds r5, r2, #0
    cmp r0, #0
    bne lbl_0803c3da
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c3d4
    ldrh r0, [r5, #2]
    adds r0, #0x14
    b lbl_0803c3d8
    .align 2, 0
lbl_0803c3d0: .4byte gCurrentSprite
lbl_0803c3d4:
    ldrh r0, [r5, #2]
    subs r0, #0x14
lbl_0803c3d8:
    strh r0, [r5, #2]
lbl_0803c3da:
    adds r0, r5, #0
    adds r0, #0x2d
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0803c3fe
    ldrh r1, [r5]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c3f8
    ldrh r0, [r5, #4]
    adds r0, r3, r0
    b lbl_0803c3fc
lbl_0803c3f8:
    ldrh r0, [r5, #4]
    subs r0, r0, r3
lbl_0803c3fc:
    strh r0, [r5, #4]
lbl_0803c3fe:
    adds r4, r5, #0
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0803c462
    ldr r0, lbl_0803c44c @ =gIoRegistersBackup
    ldrb r1, [r0, #0xc]
    movs r0, #3
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x21
    movs r3, #0
    strb r0, [r1]
    adds r1, #3
    movs r0, #0x23
    strb r0, [r1]
    movs r2, #0
    ldr r1, lbl_0803c450 @ =0x0000ffa0
    strh r1, [r4, #0xa]
    movs r0, #0x60
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803c458
    ldr r0, lbl_0803c454 @ =0x082f7bb0
    str r0, [r4, #0x18]
    b lbl_0803c45c
    .align 2, 0
lbl_0803c44c: .4byte gIoRegistersBackup
lbl_0803c450: .4byte 0x0000ffa0
lbl_0803c454: .4byte 0x082f7bb0
lbl_0803c458:
    ldr r0, lbl_0803c468 @ =0x082f7bf0
    str r0, [r5, #0x18]
lbl_0803c45c:
    ldr r0, lbl_0803c46c @ =0x00000262
    bl SoundPlay
lbl_0803c462:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c468: .4byte 0x082f7bf0
lbl_0803c46c: .4byte 0x00000262

    thumb_func_start AtomicElectricityExploding
AtomicElectricityExploding: @ 0x0803c470
    push {r4, lr}
    ldr r4, lbl_0803c4b8 @ =gCurrentSprite
    ldrh r0, [r4, #0x16]
    cmp r0, #3
    bhi lbl_0803c482
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
lbl_0803c482:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803c4b2
    adds r1, r4, #0
    adds r1, #0x24
    movs r3, #0
    movs r0, #0x25
    strb r0, [r1]
    movs r2, #0
    ldr r1, lbl_0803c4bc @ =0x0000fff0
    strh r1, [r4, #0xa]
    movs r0, #0x10
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0803c4c0 @ =0x082f7c30
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
lbl_0803c4b2:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c4b8: .4byte gCurrentSprite
lbl_0803c4bc: .4byte 0x0000fff0
lbl_0803c4c0: .4byte 0x082f7c30

    thumb_func_start AtomicElectricityCheckOnGroundAnimEnded
AtomicElectricityCheckOnGroundAnimEnded: @ 0x0803c4c4
    push {lr}
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803c4d4
    ldr r1, lbl_0803c4d8 @ =gCurrentSprite
    movs r0, #0
    strh r0, [r1]
lbl_0803c4d4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c4d8: .4byte gCurrentSprite

    thumb_func_start Atomic
Atomic: @ 0x0803c4dc
    push {r4, lr}
    sub sp, #4
    ldr r1, lbl_0803c51c @ =gCurrentSprite
    adds r3, r1, #0
    adds r3, #0x32
    ldrb r2, [r3]
    movs r4, #2
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0803c508
    movs r0, #0xfd
    ands r0, r2
    strb r0, [r3]
    ldrh r1, [r1]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803c508
    ldr r0, lbl_0803c520 @ =0x00000263
    bl SoundPlayNotAlreadyPlaying
lbl_0803c508:
    ldr r4, lbl_0803c51c @ =gCurrentSprite
    adds r0, r4, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803c524
    bl SpriteUtilUpdateFreezeTimer
    b lbl_0803c61e
    .align 2, 0
lbl_0803c51c: .4byte gCurrentSprite
lbl_0803c520: .4byte 0x00000263
lbl_0803c524:
    bl SpriteUtilIsSpriteStunned
    cmp r0, #0
    bne lbl_0803c61e
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x27
    bhi lbl_0803c60c
    lsls r0, r0, #2
    ldr r1, lbl_0803c540 @ =lbl_0803c544
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803c540: .4byte lbl_0803c544
lbl_0803c544: @ jump table
    .4byte lbl_0803c5e4 @ case 0
    .4byte lbl_0803c60c @ case 1
    .4byte lbl_0803c60c @ case 2
    .4byte lbl_0803c60c @ case 3
    .4byte lbl_0803c60c @ case 4
    .4byte lbl_0803c60c @ case 5
    .4byte lbl_0803c60c @ case 6
    .4byte lbl_0803c60c @ case 7
    .4byte lbl_0803c5ea @ case 8
    .4byte lbl_0803c5f0 @ case 9
    .4byte lbl_0803c60c @ case 10
    .4byte lbl_0803c60c @ case 11
    .4byte lbl_0803c60c @ case 12
    .4byte lbl_0803c60c @ case 13
    .4byte lbl_0803c60c @ case 14
    .4byte lbl_0803c60c @ case 15
    .4byte lbl_0803c60c @ case 16
    .4byte lbl_0803c60c @ case 17
    .4byte lbl_0803c60c @ case 18
    .4byte lbl_0803c60c @ case 19
    .4byte lbl_0803c60c @ case 20
    .4byte lbl_0803c60c @ case 21
    .4byte lbl_0803c60c @ case 22
    .4byte lbl_0803c60c @ case 23
    .4byte lbl_0803c60c @ case 24
    .4byte lbl_0803c60c @ case 25
    .4byte lbl_0803c60c @ case 26
    .4byte lbl_0803c60c @ case 27
    .4byte lbl_0803c60c @ case 28
    .4byte lbl_0803c60c @ case 29
    .4byte lbl_0803c60c @ case 30
    .4byte lbl_0803c60c @ case 31
    .4byte lbl_0803c60c @ case 32
    .4byte lbl_0803c60c @ case 33
    .4byte lbl_0803c60c @ case 34
    .4byte lbl_0803c5f6 @ case 35
    .4byte lbl_0803c60c @ case 36
    .4byte lbl_0803c5fc @ case 37
    .4byte lbl_0803c602 @ case 38
    .4byte lbl_0803c606 @ case 39
lbl_0803c5e4:
    bl AtomicInit
    b lbl_0803c61e
lbl_0803c5ea:
    bl AtomicIdleInit
    b lbl_0803c61e
lbl_0803c5f0:
    bl AtomicIdle
    b lbl_0803c61e
lbl_0803c5f6:
    bl AtomicMove
    b lbl_0803c61e
lbl_0803c5fc:
    bl AtomicMoveBackToIdle
    b lbl_0803c61e
lbl_0803c602:
    bl AtomicChasingSamusInit
lbl_0803c606:
    bl AtomicChasingSamus
    b lbl_0803c61e
lbl_0803c60c:
    ldr r0, lbl_0803c628 @ =gCurrentSprite
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    movs r0, #0x20
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_0803c61e:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803c628: .4byte gCurrentSprite

    thumb_func_start AtomicElectricity
AtomicElectricity: @ 0x0803c62c
    push {lr}
    ldr r0, lbl_0803c644 @ =gCurrentSprite
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x25
    bhi lbl_0803c700
    lsls r0, r0, #2
    ldr r1, lbl_0803c648 @ =lbl_0803c64c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803c644: .4byte gCurrentSprite
lbl_0803c648: .4byte lbl_0803c64c
lbl_0803c64c: @ jump table
    .4byte lbl_0803c6e4 @ case 0
    .4byte lbl_0803c700 @ case 1
    .4byte lbl_0803c700 @ case 2
    .4byte lbl_0803c700 @ case 3
    .4byte lbl_0803c700 @ case 4
    .4byte lbl_0803c700 @ case 5
    .4byte lbl_0803c700 @ case 6
    .4byte lbl_0803c700 @ case 7
    .4byte lbl_0803c6ea @ case 8
    .4byte lbl_0803c6f0 @ case 9
    .4byte lbl_0803c700 @ case 10
    .4byte lbl_0803c700 @ case 11
    .4byte lbl_0803c700 @ case 12
    .4byte lbl_0803c700 @ case 13
    .4byte lbl_0803c700 @ case 14
    .4byte lbl_0803c700 @ case 15
    .4byte lbl_0803c700 @ case 16
    .4byte lbl_0803c700 @ case 17
    .4byte lbl_0803c700 @ case 18
    .4byte lbl_0803c700 @ case 19
    .4byte lbl_0803c700 @ case 20
    .4byte lbl_0803c700 @ case 21
    .4byte lbl_0803c700 @ case 22
    .4byte lbl_0803c700 @ case 23
    .4byte lbl_0803c700 @ case 24
    .4byte lbl_0803c700 @ case 25
    .4byte lbl_0803c700 @ case 26
    .4byte lbl_0803c700 @ case 27
    .4byte lbl_0803c700 @ case 28
    .4byte lbl_0803c700 @ case 29
    .4byte lbl_0803c700 @ case 30
    .4byte lbl_0803c700 @ case 31
    .4byte lbl_0803c700 @ case 32
    .4byte lbl_0803c700 @ case 33
    .4byte lbl_0803c700 @ case 34
    .4byte lbl_0803c6f6 @ case 35
    .4byte lbl_0803c700 @ case 36
    .4byte lbl_0803c6fc @ case 37
lbl_0803c6e4:
    bl AtomicElectriciytInit
    b lbl_0803c700
lbl_0803c6ea:
    bl AtomicElectricitySpawn
    b lbl_0803c700
lbl_0803c6f0:
    bl AtomicElectricityMove
    b lbl_0803c700
lbl_0803c6f6:
    bl AtomicElectricityExploding
    b lbl_0803c700
lbl_0803c6fc:
    bl AtomicElectricityCheckOnGroundAnimEnded
lbl_0803c700:
    pop {r0}
    bx r0
