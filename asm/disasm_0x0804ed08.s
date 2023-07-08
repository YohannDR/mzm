    .include "asm/macros.inc"

    .syntax unified

     thumb_func_start set_beam_particle_effect
set_beam_particle_effect: @ 0x0804ed08
    push {r4, r5, lr}
    ldr r0, lbl_0804ed30 @ =gArmCannonY
    ldrh r5, [r0]
    ldr r0, lbl_0804ed34 @ =gArmCannonX
    ldrh r4, [r0]
    ldr r2, lbl_0804ed38 @ =gSamusData
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldrb r0, [r2, #2]
    cmp r0, #4
    bhi lbl_0804ed7c
    lsls r0, r0, #2
    ldr r1, lbl_0804ed3c @ =lbl_0804ed40
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804ed30: .4byte gArmCannonY
lbl_0804ed34: .4byte gArmCannonX
lbl_0804ed38: .4byte gSamusData
lbl_0804ed3c: .4byte lbl_0804ed40
lbl_0804ed40: @ jump table
    .4byte lbl_0804ed7c @ case 0
    .4byte lbl_0804ed5e @ case 1
    .4byte lbl_0804ed54 @ case 2
    .4byte lbl_0804ed72 @ case 3
    .4byte lbl_0804ed68 @ case 4
lbl_0804ed54:
    movs r2, #0xb
    cmp r3, #0
    beq lbl_0804ed84
    movs r2, #0x10
    b lbl_0804ed84
lbl_0804ed5e:
    movs r2, #0xa
    cmp r3, #0
    beq lbl_0804ed84
    movs r2, #0xf
    b lbl_0804ed84
lbl_0804ed68:
    movs r2, #0xd
    cmp r3, #0
    beq lbl_0804ed84
    movs r2, #0x12
    b lbl_0804ed84
lbl_0804ed72:
    movs r2, #0xc
    cmp r3, #0
    beq lbl_0804ed84
    movs r2, #0x11
    b lbl_0804ed84
lbl_0804ed7c:
    movs r2, #9
    cmp r3, #0
    beq lbl_0804ed84
    movs r2, #0xe
lbl_0804ed84:
    adds r0, r5, #0
    adds r1, r4, #0
    bl ParticleSet
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start check_number_of_projectiles
check_number_of_projectiles: @ 0x0804ed94
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    movs r3, #0
    ldr r2, lbl_0804edd0 @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r2, r1
    cmp r2, r0
    bhs lbl_0804edda
    movs r7, #1
    adds r6, r0, #0
lbl_0804edb0:
    ldrb r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0804edd4
    ldrb r0, [r2, #0xf]
    cmp r0, r5
    bne lbl_0804edd4
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r4
    blo lbl_0804edd4
    movs r0, #0
    b lbl_0804eddc
    .align 2, 0
lbl_0804edd0: .4byte gProjectileData
lbl_0804edd4:
    adds r2, #0x1c
    cmp r2, r6
    blo lbl_0804edb0
lbl_0804edda:
    movs r0, #1
lbl_0804eddc:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start initialize_projectile
initialize_projectile: @ 0x0804ede4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov r8, r2
    ldr r3, lbl_0804ee60 @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r3, r1
    cmp r3, r0
    bhs lbl_0804ee74
    movs r5, #1
    ldr r0, lbl_0804ee64 @ =gSamusData
    mov ip, r0
    movs r7, #0
    ldr r1, lbl_0804ee68 @ =0x0000ffff
    adds r6, r1, #0
lbl_0804ee14:
    ldrb r1, [r3]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0804ee6c
    movs r2, #0x17
    cmp r4, #0xd
    bls lbl_0804ee26
    movs r2, #7
lbl_0804ee26:
    mov r0, ip
    ldrh r1, [r0, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0804ee36
    movs r0, #0x40
    orrs r2, r0
lbl_0804ee36:
    strb r2, [r3]
    strb r4, [r3, #0xf]
    mov r1, sb
    strh r1, [r3, #8]
    mov r0, r8
    strh r0, [r3, #0xa]
    ldrh r0, [r3, #0x14]
    orrs r0, r6
    strh r0, [r3, #0x14]
    strh r5, [r3, #0x16]
    ldrh r0, [r3, #0x18]
    orrs r0, r6
    strh r0, [r3, #0x18]
    strh r5, [r3, #0x1a]
    strb r7, [r3, #0x11]
    strb r7, [r3, #0x13]
    mov r1, ip
    ldrb r0, [r1, #2]
    strb r0, [r3, #0x10]
    movs r0, #1
    b lbl_0804ee76
    .align 2, 0
lbl_0804ee60: .4byte gProjectileData
lbl_0804ee64: .4byte gSamusData
lbl_0804ee68: .4byte 0x0000ffff
lbl_0804ee6c:
    adds r3, #0x1c
    ldr r0, lbl_0804ee84 @ =gArmCannonY
    cmp r3, r0
    blo lbl_0804ee14
lbl_0804ee74:
    movs r0, #0
lbl_0804ee76:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0804ee84: .4byte gArmCannonY

    thumb_func_start ProjectileUpdate
ProjectileUpdate: @ 0x0804ee88
    push {r4, r5, lr}
    ldr r0, lbl_0804ef18 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0804ee96
    b lbl_0804f2e6
lbl_0804ee96:
    bl call_update_arm_cannon
    ldr r4, lbl_0804ef1c @ =gArmCannonY
    ldr r3, lbl_0804ef20 @ =gSamusData
    ldrh r0, [r3, #0x14]
    ldr r1, lbl_0804ef24 @ =gSamusPhysics
    adds r2, r1, #0
    adds r2, #0x4c
    lsrs r0, r0, #2
    ldrh r2, [r2]
    adds r0, r0, r2
    lsls r0, r0, #2
    strh r0, [r4]
    ldr r2, lbl_0804ef28 @ =gArmCannonX
    ldrh r0, [r3, #0x12]
    adds r1, #0x4a
    lsrs r0, r0, #2
    ldrh r1, [r1]
    adds r0, r0, r1
    lsls r0, r0, #2
    strh r0, [r2]
    ldr r0, lbl_0804ef2c @ =gSamusWeaponInfo
    ldrb r0, [r0, #5]
    cmp r0, #0x10
    bne lbl_0804ef02
    ldr r0, lbl_0804ef30 @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    beq lbl_0804ef02
    movs r4, #0
    movs r3, #0
    movs r5, #1
    ldr r2, lbl_0804ef34 @ =gParticleEffects
lbl_0804eed8:
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0804eee8
    ldrb r0, [r2, #2]
    cmp r0, #0x3b
    beq lbl_0804ef54
lbl_0804eee8:
    adds r2, #0xc
    adds r3, #1
    cmp r3, #0xf
    ble lbl_0804eed8
lbl_0804eef0:
    cmp r4, #0
    bne lbl_0804ef02
    ldr r0, lbl_0804ef1c @ =gArmCannonY
    ldrh r0, [r0]
    ldr r1, lbl_0804ef28 @ =gArmCannonX
    ldrh r1, [r1]
    movs r2, #0x3b
    bl ParticleSet
lbl_0804ef02:
    ldr r0, lbl_0804ef2c @ =gSamusWeaponInfo
    ldrb r0, [r0, #1]
    subs r0, #1
    cmp r0, #5
    bls lbl_0804ef0e
    b lbl_0804f2a8
lbl_0804ef0e:
    lsls r0, r0, #2
    ldr r1, lbl_0804ef38 @ =lbl_0804ef3c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804ef18: .4byte gGameModeSub1
lbl_0804ef1c: .4byte gArmCannonY
lbl_0804ef20: .4byte gSamusData
lbl_0804ef24: .4byte gSamusPhysics
lbl_0804ef28: .4byte gArmCannonX
lbl_0804ef2c: .4byte gSamusWeaponInfo
lbl_0804ef30: .4byte gEquipment
lbl_0804ef34: .4byte gParticleEffects
lbl_0804ef38: .4byte lbl_0804ef3c
lbl_0804ef3c: @ jump table
    .4byte lbl_0804f06a @ case 0
    .4byte lbl_0804f1bc @ case 1
    .4byte lbl_0804f200 @ case 2
    .4byte lbl_0804f244 @ case 3
    .4byte lbl_0804f274 @ case 4
    .4byte lbl_0804ef5c @ case 5
lbl_0804ef54:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    b lbl_0804eef0
lbl_0804ef5c:
    ldr r1, lbl_0804efa0 @ =gEquipment
    ldrb r0, [r1, #0x12]
    cmp r0, #2
    bne lbl_0804efb0
    movs r0, #0xb
    movs r1, #2
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804ef74
    b lbl_0804f2a2
lbl_0804ef74:
    ldr r0, lbl_0804efa4 @ =gArmCannonY
    ldrh r1, [r0]
    ldr r0, lbl_0804efa8 @ =gArmCannonX
    ldrh r2, [r0]
    movs r0, #0xb
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804ef8a
    b lbl_0804f2a2
lbl_0804ef8a:
    ldr r4, lbl_0804efac @ =gSamusWeaponInfo
    movs r0, #7
    strb r0, [r4, #4]
    bl set_beam_particle_effect
    movs r0, #4
    strb r0, [r4, #6]
    movs r0, #0xa0
    bl SoundPlay
    b lbl_0804f2a2
    .align 2, 0
lbl_0804efa0: .4byte gEquipment
lbl_0804efa4: .4byte gArmCannonY
lbl_0804efa8: .4byte gArmCannonX
lbl_0804efac: .4byte gSamusWeaponInfo
lbl_0804efb0:
    ldrb r1, [r1, #0xd]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f00c
    movs r4, #0xa
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0804efe8
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804efda
    movs r0, #2
    ands r1, r0
    movs r5, #0xf5
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xf7
    b lbl_0804f064
lbl_0804efda:
    movs r0, #2
    ands r1, r0
    movs r5, #0xf4
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xf6
    b lbl_0804f064
lbl_0804efe8:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804effe
    movs r0, #2
    ands r1, r0
    movs r5, #0xf1
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xf3
    b lbl_0804f064
lbl_0804effe:
    movs r0, #2
    ands r1, r0
    movs r5, #0xf0
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xf2
    b lbl_0804f064
lbl_0804f00c:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f03a
    movs r4, #9
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f02c
    movs r0, #2
    ands r1, r0
    movs r5, #0xed
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xef
    b lbl_0804f064
lbl_0804f02c:
    movs r0, #2
    ands r1, r0
    movs r5, #0xec
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xee
    b lbl_0804f064
lbl_0804f03a:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f052
    movs r4, #8
    movs r0, #1
    ands r1, r0
    movs r5, #0xea
    cmp r1, #0
    beq lbl_0804f064
    movs r5, #0xeb
    b lbl_0804f064
lbl_0804f052:
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_0804f060
    movs r4, #7
    movs r5, #0xe9
    b lbl_0804f064
lbl_0804f060:
    movs r4, #6
    movs r5, #0xe8
lbl_0804f064:
    adds r0, r4, #0
    movs r1, #2
    b lbl_0804f178
lbl_0804f06a:
    ldr r1, lbl_0804f0b0 @ =gEquipment
    ldrb r0, [r1, #0x12]
    cmp r0, #2
    bne lbl_0804f0c0
    movs r0, #5
    movs r1, #6
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804f082
    b lbl_0804f2a2
lbl_0804f082:
    ldr r0, lbl_0804f0b4 @ =gArmCannonY
    ldrh r1, [r0]
    ldr r0, lbl_0804f0b8 @ =gArmCannonX
    ldrh r2, [r0]
    movs r0, #5
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804f098
    b lbl_0804f2a2
lbl_0804f098:
    ldr r4, lbl_0804f0bc @ =gSamusWeaponInfo
    movs r0, #7
    strb r0, [r4, #4]
    bl set_beam_particle_effect
    movs r0, #4
    strb r0, [r4, #6]
    movs r0, #0x9f
    bl SoundPlay
    b lbl_0804f2a2
    .align 2, 0
lbl_0804f0b0: .4byte gEquipment
lbl_0804f0b4: .4byte gArmCannonY
lbl_0804f0b8: .4byte gArmCannonX
lbl_0804f0bc: .4byte gSamusWeaponInfo
lbl_0804f0c0:
    ldrb r1, [r1, #0xd]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f11c
    movs r4, #4
    adds r0, r1, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_0804f0f8
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f0ea
    movs r0, #2
    ands r1, r0
    movs r5, #0xd5
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xd7
    b lbl_0804f174
lbl_0804f0ea:
    movs r0, #2
    ands r1, r0
    movs r5, #0xd4
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xd6
    b lbl_0804f174
lbl_0804f0f8:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f10e
    movs r0, #2
    ands r1, r0
    movs r5, #0xd1
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xd3
    b lbl_0804f174
lbl_0804f10e:
    movs r0, #2
    ands r1, r0
    movs r5, #0xd0
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xd2
    b lbl_0804f174
lbl_0804f11c:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f14a
    movs r4, #3
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f13c
    movs r0, #2
    ands r1, r0
    movs r5, #0xcd
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xcf
    b lbl_0804f174
lbl_0804f13c:
    movs r0, #2
    ands r1, r0
    movs r5, #0xcc
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xce
    b lbl_0804f174
lbl_0804f14a:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f162
    movs r4, #2
    movs r0, #1
    ands r1, r0
    movs r5, #0xca
    cmp r1, #0
    beq lbl_0804f174
    movs r5, #0xcb
    b lbl_0804f174
lbl_0804f162:
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_0804f170
    movs r4, #1
    movs r5, #0xc9
    b lbl_0804f174
lbl_0804f170:
    movs r4, #0
    movs r5, #0xc8
lbl_0804f174:
    adds r0, r4, #0
    movs r1, #6
lbl_0804f178:
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804f184
    b lbl_0804f2a2
lbl_0804f184:
    ldr r0, lbl_0804f1b0 @ =gArmCannonY
    ldrh r1, [r0]
    ldr r0, lbl_0804f1b4 @ =gArmCannonX
    ldrh r2, [r0]
    adds r0, r4, #0
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804f19a
    b lbl_0804f2a2
lbl_0804f19a:
    ldr r4, lbl_0804f1b8 @ =gSamusWeaponInfo
    movs r0, #7
    strb r0, [r4, #4]
    bl set_beam_particle_effect
    movs r0, #4
    strb r0, [r4, #6]
    adds r0, r5, #0
    bl SoundPlay
    b lbl_0804f2a2
    .align 2, 0
lbl_0804f1b0: .4byte gArmCannonY
lbl_0804f1b4: .4byte gArmCannonX
lbl_0804f1b8: .4byte gSamusWeaponInfo
lbl_0804f1bc:
    movs r0, #0xc
    movs r1, #4
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r0, lbl_0804f1f4 @ =gArmCannonY
    ldrh r1, [r0]
    ldr r0, lbl_0804f1f8 @ =gArmCannonX
    ldrh r2, [r0]
    movs r0, #0xc
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r1, lbl_0804f1fc @ =gSamusWeaponInfo
    movs r0, #9
    strb r0, [r1, #4]
    movs r0, #0xf8
    bl SoundPlay
    movs r0, #0xf9
    bl SoundPlay
    b lbl_0804f2a2
    .align 2, 0
lbl_0804f1f4: .4byte gArmCannonY
lbl_0804f1f8: .4byte gArmCannonX
lbl_0804f1fc: .4byte gSamusWeaponInfo
lbl_0804f200:
    movs r0, #0xd
    movs r1, #4
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r0, lbl_0804f238 @ =gArmCannonY
    ldrh r1, [r0]
    ldr r0, lbl_0804f23c @ =gArmCannonX
    ldrh r2, [r0]
    movs r0, #0xd
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r1, lbl_0804f240 @ =gSamusWeaponInfo
    movs r0, #0xb
    strb r0, [r1, #4]
    movs r0, #0xfb
    bl SoundPlay
    movs r0, #0xfc
    bl SoundPlay
    b lbl_0804f2a2
    .align 2, 0
lbl_0804f238: .4byte gArmCannonY
lbl_0804f23c: .4byte gArmCannonX
lbl_0804f240: .4byte gSamusWeaponInfo
lbl_0804f244:
    movs r0, #0xe
    movs r1, #4
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r0, lbl_0804f26c @ =gSamusData
    ldrh r1, [r0, #0x14]
    ldrh r2, [r0, #0x12]
    movs r0, #0xe
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r1, lbl_0804f270 @ =gSamusWeaponInfo
    movs r0, #7
    b lbl_0804f2a0
    .align 2, 0
lbl_0804f26c: .4byte gSamusData
lbl_0804f270: .4byte gSamusWeaponInfo
lbl_0804f274:
    movs r0, #0xf
    movs r1, #1
    bl check_number_of_projectiles
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r0, lbl_0804f2ec @ =gCurrentPowerBomb
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0804f2a2
    ldr r0, lbl_0804f2f0 @ =gSamusData
    ldrh r1, [r0, #0x14]
    ldrh r2, [r0, #0x12]
    movs r0, #0xf
    bl initialize_projectile
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804f2a2
    ldr r1, lbl_0804f2f4 @ =gSamusWeaponInfo
    movs r0, #5
lbl_0804f2a0:
    strb r0, [r1, #4]
lbl_0804f2a2:
    ldr r1, lbl_0804f2f4 @ =gSamusWeaponInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_0804f2a8:
    bl check_ProjectileHitSprite
    ldr r4, lbl_0804f2f8 @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r4, r1
    cmp r4, r0
    bhs lbl_0804f2e6
    ldr r5, lbl_0804f2fc @ =0x0875f974
lbl_0804f2ba:
    ldrb r1, [r4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f2de
    ldrb r0, [r4, #0xf]
    lsls r0, r0, #2
    adds r0, r0, r5
    ldr r1, [r0]
    adds r0, r4, #0
    bl _call_via_r1
    adds r0, r4, #0
    bl update_projectile_anim
    adds r0, r4, #0
    bl check_despawn_projectile
lbl_0804f2de:
    adds r4, #0x1c
    ldr r0, lbl_0804f300 @ =gArmCannonY
    cmp r4, r0
    blo lbl_0804f2ba
lbl_0804f2e6:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f2ec: .4byte gCurrentPowerBomb
lbl_0804f2f0: .4byte gSamusData
lbl_0804f2f4: .4byte gSamusWeaponInfo
lbl_0804f2f8: .4byte gProjectileData
lbl_0804f2fc: .4byte 0x0875f974
lbl_0804f300: .4byte gArmCannonY

    thumb_func_start update_projectile_anim
update_projectile_anim: @ 0x0804f304
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #0xe]
    adds r0, #1
    strb r0, [r2, #0xe]
    ldrh r1, [r2, #0xc]
    ldr r3, [r2, #4]
    lsls r1, r1, #3
    adds r1, r1, r3
    ldrb r1, [r1, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhs lbl_0804f338
    movs r0, #1
    strb r0, [r2, #0xe]
    ldrh r0, [r2, #0xc]
    adds r0, #1
    strh r0, [r2, #0xc]
    ldrh r0, [r2, #0xc]
    lsls r0, r0, #3
    adds r0, r0, r3
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_0804f338
    strh r0, [r2, #0xc]
lbl_0804f338:
    pop {r0}
    bx r0

    thumb_func_start ProjectileDrawAllStatusFalse
ProjectileDrawAllStatusFalse: @ 0x0804f33c
    push {r4, lr}
    ldr r0, lbl_0804f374 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0804f36c
    ldr r4, lbl_0804f378 @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r4, r1
    cmp r4, r0
    bhs lbl_0804f36c
lbl_0804f354:
    ldrb r1, [r4]
    movs r0, #0x87
    ands r0, r1
    cmp r0, #3
    bne lbl_0804f364
    adds r0, r4, #0
    bl draw_projectile
lbl_0804f364:
    adds r4, #0x1c
    ldr r0, lbl_0804f37c @ =gArmCannonY
    cmp r4, r0
    blo lbl_0804f354
lbl_0804f36c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f374: .4byte gGameModeSub1
lbl_0804f378: .4byte gProjectileData
lbl_0804f37c: .4byte gArmCannonY

    thumb_func_start ProjectileDrawAllStatusTrue
ProjectileDrawAllStatusTrue: @ 0x0804f380
    push {r4, lr}
    ldr r0, lbl_0804f3b8 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0804f3b0
    ldr r4, lbl_0804f3bc @ =gProjectileData
    movs r1, #0xe0
    lsls r1, r1, #1
    adds r0, r4, r1
    cmp r4, r0
    bhs lbl_0804f3b0
lbl_0804f398:
    ldrb r1, [r4]
    movs r0, #0x87
    ands r0, r1
    cmp r0, #0x83
    bne lbl_0804f3a8
    adds r0, r4, #0
    bl draw_projectile
lbl_0804f3a8:
    adds r4, #0x1c
    ldr r0, lbl_0804f3c0 @ =gArmCannonY
    cmp r4, r0
    blo lbl_0804f398
lbl_0804f3b0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f3b8: .4byte gGameModeSub1
lbl_0804f3bc: .4byte gProjectileData
lbl_0804f3c0: .4byte gArmCannonY

    thumb_func_start draw_projectile
draw_projectile: @ 0x0804f3c4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    adds r3, r0, #0
    ldr r2, lbl_0804f448 @ =gNextOamSlot
    ldrb r0, [r2]
    str r0, [sp, #4]
    ldrh r0, [r3, #0xc]
    ldr r1, [r3, #4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r5, [r0]
    ldrh r1, [r5]
    mov sl, r1
    adds r5, #2
    ldr r0, [sp, #4]
    add r0, sl
    cmp r0, #0x7f
    ble lbl_0804f3f2
    b lbl_0804f550
lbl_0804f3f2:
    ldr r1, [sp, #4]
    lsls r0, r1, #3
    ldr r2, lbl_0804f44c @ =gOamData
    adds r4, r0, r2
    ldrh r1, [r3, #8]
    lsrs r1, r1, #2
    ldr r0, lbl_0804f450 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp]
    ldrh r1, [r3, #0xa]
    lsrs r1, r1, #2
    ldr r0, lbl_0804f454 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    ldrb r1, [r3]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #8]
    movs r0, #0x20
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0xc]
    ldr r0, lbl_0804f458 @ =gIoRegistersBackup
    ldrh r0, [r0, #0xc]
    movs r3, #3
    ands r3, r0
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f45c
    movs r3, #0
    b lbl_0804f45e
    .align 2, 0
lbl_0804f448: .4byte gNextOamSlot
lbl_0804f44c: .4byte gOamData
lbl_0804f450: .4byte gBG1YPosition
lbl_0804f454: .4byte gBG1XPosition
lbl_0804f458: .4byte gIoRegistersBackup
lbl_0804f45c:
    adds r3, #1
lbl_0804f45e:
    movs r0, #0
    mov ip, r0
    ldr r1, [sp, #4]
    add r1, sl
    str r1, [sp, #0x14]
    cmp ip, sl
    bge lbl_0804f548
    movs r0, #1
    mov r8, r0
    movs r0, #3
    ands r3, r0
    lsls r3, r3, #2
    str r3, [sp, #0x10]
lbl_0804f478:
    ldrh r0, [r5]
    adds r7, r0, #0
    adds r5, #2
    strh r7, [r4]
    adds r4, #2
    ldr r0, [sp, #4]
    add r0, ip
    lsls r0, r0, #3
    ldr r1, lbl_0804f560 @ =gOamData
    adds r3, r0, r1
    ldr r1, [sp]
    adds r0, r7, r1
    strb r0, [r3]
    ldrh r6, [r5]
    adds r5, #2
    strh r6, [r4]
    adds r4, #2
    mov r0, sb
    adds r1, r6, r0
    ldr r0, lbl_0804f564 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0804f568 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
    ldrh r0, [r5]
    strh r0, [r4]
    adds r5, #2
    adds r4, #2
    ldrb r1, [r3, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    ldr r1, [sp, #0x10]
    orrs r0, r1
    strb r0, [r3, #5]
    ldr r0, [sp, #8]
    cmp r0, #0
    beq lbl_0804f506
    ldrb r2, [r3, #3]
    lsls r0, r2, #0x1b
    lsrs r0, r0, #0x1f
    mov r1, r8
    eors r0, r1
    ands r0, r1
    lsls r0, r0, #4
    movs r1, #0x11
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    strb r1, [r3, #3]
    ldrb r0, [r3, #1]
    lsrs r0, r0, #6
    lsrs r1, r1, #6
    lsls r0, r0, #2
    adds r0, r1, r0
    ldr r1, lbl_0804f56c @ =0x082b0c94
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r1, r0, #3
    adds r1, r6, r1
    mov r0, sb
    subs r1, r0, r1
    ldr r0, lbl_0804f564 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r3, #2]
    ldr r0, lbl_0804f568 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #2]
lbl_0804f506:
    ldr r1, [sp, #0xc]
    cmp r1, #0
    beq lbl_0804f53e
    ldrb r2, [r3, #3]
    lsls r0, r2, #0x1a
    lsrs r0, r0, #0x1f
    mov r1, r8
    eors r0, r1
    ands r0, r1
    lsls r0, r0, #5
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    strb r1, [r3, #3]
    ldrb r0, [r3, #1]
    lsrs r0, r0, #6
    lsrs r1, r1, #6
    lsls r0, r0, #2
    adds r0, r1, r0
    ldr r1, lbl_0804f570 @ =0x082b0ca0
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r7, r0
    ldr r1, [sp]
    subs r0, r1, r0
    strb r0, [r3]
lbl_0804f53e:
    adds r4, #2
    movs r0, #1
    add ip, r0
    cmp ip, sl
    blt lbl_0804f478
lbl_0804f548:
    mov r1, sp
    ldrb r0, [r1, #0x14]
    ldr r1, lbl_0804f574 @ =gNextOamSlot
    strb r0, [r1]
lbl_0804f550:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f560: .4byte gOamData
lbl_0804f564: .4byte 0x000001ff
lbl_0804f568: .4byte 0xfffffe00
lbl_0804f56c: .4byte 0x082b0c94
lbl_0804f570: .4byte 0x082b0ca0
lbl_0804f574: .4byte gNextOamSlot

    thumb_func_start check_despawn_projectile
check_despawn_projectile: @ 0x0804f578
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r6, r0, #0
    ldrb r0, [r6]
    mov sl, r0
    movs r0, #1
    mov r1, sl
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f65e
    ldr r0, lbl_0804f604 @ =gBG1YPosition
    ldrh r7, [r6, #8]
    ldrh r4, [r6, #0xa]
    mov ip, r4
    ldrb r3, [r6, #0x12]
    movs r1, #0x80
    lsls r1, r1, #1
    adds r2, r1, #0
    ldrh r0, [r0]
    adds r1, r2, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r0, r7, r2
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    subs r0, r1, r3
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    movs r4, #0xa0
    lsls r4, r4, #2
    adds r0, r3, r4
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r8, r1
    ldr r1, lbl_0804f608 @ =gBG1XPosition
    ldrh r1, [r1]
    adds r0, r2, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    add r2, ip
    lsls r2, r2, #0x10
    subs r1, r0, r3
    lsls r1, r1, #0x10
    str r1, [sp]
    lsrs r4, r2, #0x10
    movs r1, #0xf0
    lsls r1, r1, #2
    adds r3, r3, r1
    adds r0, r0, r3
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r1, [sp]
    cmp r1, r2
    bhs lbl_0804f60c
    cmp r4, r0
    bhs lbl_0804f60c
    cmp sb, r5
    bhs lbl_0804f60c
    cmp r5, r8
    bhs lbl_0804f60c
    movs r0, #2
    mov r4, sl
    orrs r0, r4
    b lbl_0804f65c
    .align 2, 0
lbl_0804f604: .4byte gBG1YPosition
lbl_0804f608: .4byte gBG1XPosition
lbl_0804f60c:
    ldrb r0, [r6]
    movs r1, #0xfd
    ands r1, r0
    strb r1, [r6]
    ldrb r0, [r6, #0xf]
    cmp r0, #0xd
    bhi lbl_0804f65e
    ldr r1, lbl_0804f630 @ =gSamusData
    ldrh r0, [r1, #0x14]
    subs r0, #0x48
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldrh r4, [r1, #0x12]
    cmp r7, r5
    bls lbl_0804f634
    subs r0, r7, r5
    b lbl_0804f636
    .align 2, 0
lbl_0804f630: .4byte gSamusData
lbl_0804f634:
    subs r0, r5, r7
lbl_0804f636:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp ip, r4
    bls lbl_0804f644
    mov r1, ip
    subs r0, r1, r4
    b lbl_0804f648
lbl_0804f644:
    mov r1, ip
    subs r0, r4, r1
lbl_0804f648:
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0xc0
    lsls r0, r0, #2
    cmp r5, r0
    bhi lbl_0804f65a
    subs r0, #0x80
    cmp r4, r0
    bls lbl_0804f65e
lbl_0804f65a:
    movs r0, #0
lbl_0804f65c:
    strb r0, [r6]
lbl_0804f65e:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start load_beam_graphics
load_beam_graphics: @ 0x0804f670
    push {lr}
    ldr r1, lbl_0804f6b8 @ =gEquipment
    ldrb r0, [r1, #0x12]
    cmp r0, #2
    bne lbl_0804f6e8
    ldr r0, lbl_0804f6bc @ =0x040000d4
    ldr r1, lbl_0804f6c0 @ =0x0832b078
    str r1, [r0]
    ldr r1, lbl_0804f6c4 @ =0x06011000
    str r1, [r0, #4]
    ldr r1, lbl_0804f6c8 @ =0x80000080
    str r1, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f6cc @ =0x0832b278
    str r1, [r0]
    ldr r1, lbl_0804f6d0 @ =0x06011400
    str r1, [r0, #4]
    ldr r2, lbl_0804f6d4 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f6d8 @ =0x0832b478
    str r1, [r0]
    ldr r1, lbl_0804f6dc @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f6e0 @ =0x0832b678
    str r1, [r0]
    ldr r1, lbl_0804f6e4 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    bl HudDrawSuitless
    movs r0, #0x50
    b lbl_0804f8d2
    .align 2, 0
lbl_0804f6b8: .4byte gEquipment
lbl_0804f6bc: .4byte 0x040000d4
lbl_0804f6c0: .4byte 0x0832b078
lbl_0804f6c4: .4byte 0x06011000
lbl_0804f6c8: .4byte 0x80000080
lbl_0804f6cc: .4byte 0x0832b278
lbl_0804f6d0: .4byte 0x06011400
lbl_0804f6d4: .4byte 0x80000100
lbl_0804f6d8: .4byte 0x0832b478
lbl_0804f6dc: .4byte 0x06011800
lbl_0804f6e0: .4byte 0x0832b678
lbl_0804f6e4: .4byte 0x06011c00
lbl_0804f6e8:
    ldrb r3, [r1, #0xd]
    movs r0, #8
    ands r0, r3
    cmp r0, #0
    beq lbl_0804f758
    ldr r0, lbl_0804f730 @ =0x040000d4
    ldr r1, lbl_0804f734 @ =0x08329ed4
    str r1, [r0]
    ldr r1, lbl_0804f738 @ =0x06011000
    str r1, [r0, #4]
    ldr r2, lbl_0804f73c @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f740 @ =0x0832a0d4
    str r1, [r0]
    ldr r1, lbl_0804f744 @ =0x06011400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f748 @ =0x0832a2d4
    str r1, [r0]
    ldr r1, lbl_0804f74c @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f750 @ =0x0832a4d4
    str r1, [r0]
    ldr r1, lbl_0804f754 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #2
    ands r3, r0
    movs r0, #0x40
    b lbl_0804f79a
    .align 2, 0
lbl_0804f730: .4byte 0x040000d4
lbl_0804f734: .4byte 0x08329ed4
lbl_0804f738: .4byte 0x06011000
lbl_0804f73c: .4byte 0x80000100
lbl_0804f740: .4byte 0x0832a0d4
lbl_0804f744: .4byte 0x06011400
lbl_0804f748: .4byte 0x0832a2d4
lbl_0804f74c: .4byte 0x06011800
lbl_0804f750: .4byte 0x0832a4d4
lbl_0804f754: .4byte 0x06011c00
lbl_0804f758:
    movs r0, #4
    ands r0, r3
    cmp r0, #0
    beq lbl_0804f7cc
    ldr r0, lbl_0804f7a4 @ =0x040000d4
    ldr r1, lbl_0804f7a8 @ =0x08328f34
    str r1, [r0]
    ldr r1, lbl_0804f7ac @ =0x06011000
    str r1, [r0, #4]
    ldr r2, lbl_0804f7b0 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f7b4 @ =0x08329134
    str r1, [r0]
    ldr r1, lbl_0804f7b8 @ =0x06011400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f7bc @ =0x08329334
    str r1, [r0]
    ldr r1, lbl_0804f7c0 @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f7c4 @ =0x08329534
    str r1, [r0]
    ldr r1, lbl_0804f7c8 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #2
    ands r3, r0
    movs r0, #0x30
lbl_0804f79a:
    cmp r3, #0
    bne lbl_0804f7a0
    b lbl_0804f8d2
lbl_0804f7a0:
    movs r0, #0x20
    b lbl_0804f8d2
    .align 2, 0
lbl_0804f7a4: .4byte 0x040000d4
lbl_0804f7a8: .4byte 0x08328f34
lbl_0804f7ac: .4byte 0x06011000
lbl_0804f7b0: .4byte 0x80000100
lbl_0804f7b4: .4byte 0x08329134
lbl_0804f7b8: .4byte 0x06011400
lbl_0804f7bc: .4byte 0x08329334
lbl_0804f7c0: .4byte 0x06011800
lbl_0804f7c4: .4byte 0x08329534
lbl_0804f7c8: .4byte 0x06011c00
lbl_0804f7cc:
    movs r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_0804f834
    ldr r0, lbl_0804f80c @ =0x040000d4
    ldr r1, lbl_0804f810 @ =0x08328500
    str r1, [r0]
    ldr r1, lbl_0804f814 @ =0x06011000
    str r1, [r0, #4]
    ldr r2, lbl_0804f818 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f81c @ =0x08328700
    str r1, [r0]
    ldr r1, lbl_0804f820 @ =0x06011400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f824 @ =0x08328900
    str r1, [r0]
    ldr r1, lbl_0804f828 @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f82c @ =0x08328b00
    str r1, [r0]
    ldr r1, lbl_0804f830 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #0x20
    b lbl_0804f8d2
    .align 2, 0
lbl_0804f80c: .4byte 0x040000d4
lbl_0804f810: .4byte 0x08328500
lbl_0804f814: .4byte 0x06011000
lbl_0804f818: .4byte 0x80000100
lbl_0804f81c: .4byte 0x08328700
lbl_0804f820: .4byte 0x06011400
lbl_0804f824: .4byte 0x08328900
lbl_0804f828: .4byte 0x06011800
lbl_0804f82c: .4byte 0x08328b00
lbl_0804f830: .4byte 0x06011c00
lbl_0804f834:
    movs r0, #1
    ands r3, r0
    cmp r3, #0
    beq lbl_0804f89c
    ldr r0, lbl_0804f874 @ =0x040000d4
    ldr r1, lbl_0804f878 @ =0x08327b90
    str r1, [r0]
    ldr r1, lbl_0804f87c @ =0x06011000
    str r1, [r0, #4]
    ldr r2, lbl_0804f880 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f884 @ =0x08327d90
    str r1, [r0]
    ldr r1, lbl_0804f888 @ =0x06011400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f88c @ =0x08327f90
    str r1, [r0]
    ldr r1, lbl_0804f890 @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f894 @ =0x08328190
    str r1, [r0]
    ldr r1, lbl_0804f898 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #0x10
    b lbl_0804f8d2
    .align 2, 0
lbl_0804f874: .4byte 0x040000d4
lbl_0804f878: .4byte 0x08327b90
lbl_0804f87c: .4byte 0x06011000
lbl_0804f880: .4byte 0x80000100
lbl_0804f884: .4byte 0x08327d90
lbl_0804f888: .4byte 0x06011400
lbl_0804f88c: .4byte 0x08327f90
lbl_0804f890: .4byte 0x06011800
lbl_0804f894: .4byte 0x08328190
lbl_0804f898: .4byte 0x06011c00
lbl_0804f89c:
    ldr r0, lbl_0804f8ec @ =0x040000d4
    ldr r1, lbl_0804f8f0 @ =0x083271a8
    str r1, [r0]
    ldr r1, lbl_0804f8f4 @ =0x06011000
    str r1, [r0, #4]
    ldr r2, lbl_0804f8f8 @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f8fc @ =0x083273a8
    str r1, [r0]
    ldr r1, lbl_0804f900 @ =0x06011400
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f904 @ =0x083275a8
    str r1, [r0]
    ldr r1, lbl_0804f908 @ =0x06011800
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0804f90c @ =0x083277a8
    str r1, [r0]
    ldr r1, lbl_0804f910 @ =0x06011c00
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #0
lbl_0804f8d2:
    ldr r2, lbl_0804f8ec @ =0x040000d4
    lsls r0, r0, #1
    ldr r1, lbl_0804f914 @ =0x083270e8
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0804f918 @ =0x05000240
    str r0, [r2, #4]
    ldr r0, lbl_0804f91c @ =0x80000006
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f8ec: .4byte 0x040000d4
lbl_0804f8f0: .4byte 0x083271a8
lbl_0804f8f4: .4byte 0x06011000
lbl_0804f8f8: .4byte 0x80000100
lbl_0804f8fc: .4byte 0x083273a8
lbl_0804f900: .4byte 0x06011400
lbl_0804f904: .4byte 0x083275a8
lbl_0804f908: .4byte 0x06011800
lbl_0804f90c: .4byte 0x083277a8
lbl_0804f910: .4byte 0x06011c00
lbl_0804f914: .4byte 0x083270e8
lbl_0804f918: .4byte 0x05000240
lbl_0804f91c: .4byte 0x80000006

    thumb_func_start ProjectileCallLoadGraphicsAndClearProjectiles
ProjectileCallLoadGraphicsAndClearProjectiles: @ 0x0804f920
    push {lr}
    bl load_beam_graphics
    ldr r0, lbl_0804f94c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804f948
    ldr r0, lbl_0804f950 @ =gProjectileData
    movs r2, #0xe0
    lsls r2, r2, #1
    adds r1, r0, r2
    cmp r0, r1
    bhs lbl_0804f948
    movs r2, #0
lbl_0804f940:
    strb r2, [r0]
    adds r0, #0x1c
    cmp r0, r1
    blo lbl_0804f940
lbl_0804f948:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804f94c: .4byte gPauseScreenFlag
lbl_0804f950: .4byte gProjectileData

    thumb_func_start move_projectile
move_projectile: @ 0x0804f954
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x18
    lsrs r2, r1, #0x18
    ldrb r0, [r4, #0x10]
    cmp r0, #2
    beq lbl_0804f9aa
    cmp r0, #2
    bgt lbl_0804f96c
    cmp r0, #1
    beq lbl_0804f986
    b lbl_0804f9ce
lbl_0804f96c:
    cmp r0, #3
    beq lbl_0804f976
    cmp r0, #4
    beq lbl_0804f97e
    b lbl_0804f9ce
lbl_0804f976:
    ldrh r0, [r4, #8]
    subs r0, r0, r2
    strh r0, [r4, #8]
    b lbl_0804fa12
lbl_0804f97e:
    ldrh r0, [r4, #8]
    adds r0, r0, r2
    strh r0, [r4, #8]
    b lbl_0804fa12
lbl_0804f986:
    lsls r0, r2, #3
    subs r0, r0, r2
    movs r1, #0xa
    bl __divsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldrh r0, [r4, #8]
    subs r0, r0, r2
    strh r0, [r4, #8]
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f9de
    ldrh r0, [r4, #0xa]
    adds r0, r0, r2
    b lbl_0804f9e2
lbl_0804f9aa:
    lsls r0, r2, #3
    subs r0, r0, r2
    movs r1, #0xa
    bl __divsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldrh r0, [r4, #8]
    adds r0, r0, r2
    strh r0, [r4, #8]
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f9de
    ldrh r0, [r4, #0xa]
    adds r0, r0, r2
    b lbl_0804f9e2
lbl_0804f9ce:
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804f9de
    ldrh r0, [r4, #0xa]
    adds r0, r0, r2
    b lbl_0804f9e2
lbl_0804f9de:
    ldrh r0, [r4, #0xa]
    subs r0, r0, r2
lbl_0804f9e2:
    strh r0, [r4, #0xa]
    ldr r0, lbl_0804fa04 @ =gSamusData
    ldrh r0, [r0, #0x16]
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
    asrs r2, r0, #0x13
    adds r5, r2, #0
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fa08
    cmp r3, #0
    ble lbl_0804fa12
    ldrh r0, [r4, #0xa]
    adds r0, r0, r2
    b lbl_0804fa10
    .align 2, 0
lbl_0804fa04: .4byte gSamusData
lbl_0804fa08:
    cmp r3, #0
    bge lbl_0804fa12
    ldrh r0, [r4, #0xa]
    adds r0, r0, r5
lbl_0804fa10:
    strh r0, [r4, #0xa]
lbl_0804fa12:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0804fa18
sub_0804fa18: @ 0x0804fa18
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl ClipdataProcess
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_0804fa34
    movs r0, #0
    b lbl_0804fa36
lbl_0804fa34:
    movs r0, #1
lbl_0804fa36:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0804fa3c
sub_0804fa3c: @ 0x0804fa3c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    mov r8, r0
    ldrh r6, [r0, #8]
    ldrh r7, [r0, #0xa]
    adds r4, r6, #0
    adds r5, r7, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    adds r1, r0, #0
    movs r0, #0x80
    lsls r0, r0, #0x11
    ands r0, r1
    movs r2, #0x11
    cmp r0, #0
    bne lbl_0804fa66
    movs r0, #0
    b lbl_0804fc2e
lbl_0804fa66:
    movs r0, #0xff
    ands r0, r1
    subs r0, #2
    cmp r0, #0xa
    bls lbl_0804fa72
    b lbl_0804fbb0
lbl_0804fa72:
    lsls r0, r0, #2
    ldr r1, lbl_0804fa7c @ =lbl_0804fa80
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804fa7c: .4byte lbl_0804fa80
lbl_0804fa80: @ jump table
    .4byte lbl_0804fb30 @ case 0
    .4byte lbl_0804faac @ case 1
    .4byte lbl_0804fb7c @ case 2
    .4byte lbl_0804fb50 @ case 3
    .4byte lbl_0804fad8 @ case 4
    .4byte lbl_0804fb00 @ case 5
    .4byte lbl_0804fbb0 @ case 6
    .4byte lbl_0804fbb0 @ case 7
    .4byte lbl_0804fbb0 @ case 8
    .4byte lbl_0804fbb0 @ case 9
    .4byte lbl_0804fba4 @ case 10
lbl_0804faac:
    ldr r3, lbl_0804fad4 @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r7, #0
    ands r0, r2
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r7, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    movs r2, #5
    b lbl_0804fbce
    .align 2, 0
lbl_0804fad4: .4byte 0x0000ffc0
lbl_0804fad8:
    ldr r3, lbl_0804fafc @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r7, #0
    ands r0, r2
    lsrs r0, r0, #1
    subs r0, #0x3f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r7, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    subs r0, #0x7e
    b lbl_0804fb22
    .align 2, 0
lbl_0804fafc: .4byte 0x0000ffc0
lbl_0804fb00:
    ldr r3, lbl_0804fb2c @ =0x0000ffc0
    adds r1, r6, #0
    ands r1, r3
    movs r2, #0x3f
    adds r0, r7, #0
    ands r0, r2
    lsrs r0, r0, #1
    subs r0, #0x1f
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r1, r7, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    subs r0, #0x3e
lbl_0804fb22:
    subs r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    movs r2, #3
    b lbl_0804fbce
    .align 2, 0
lbl_0804fb2c: .4byte 0x0000ffc0
lbl_0804fb30:
    ldr r2, lbl_0804fb4c @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r2
    movs r1, #0x3f
    adds r0, r7, #0
    ands r0, r1
    orrs r4, r0
    adds r5, r7, #0
    ands r5, r2
    adds r0, r6, #0
    ands r0, r1
    orrs r5, r0
    movs r2, #4
    b lbl_0804fbce
    .align 2, 0
lbl_0804fb4c: .4byte 0x0000ffc0
lbl_0804fb50:
    ldr r3, lbl_0804fb74 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r3
    movs r2, #0x3f
    adds r0, r7, #0
    ands r0, r2
    lsrs r0, r0, #1
    adds r0, #0x1f
    orrs r4, r0
    adds r1, r7, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
    ldr r2, lbl_0804fb78 @ =0x0000ffc1
    adds r0, r0, r2
    b lbl_0804fb96
    .align 2, 0
lbl_0804fb74: .4byte 0x0000ffc0
lbl_0804fb78: .4byte 0x0000ffc1
lbl_0804fb7c:
    ldr r3, lbl_0804fba0 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r3
    movs r2, #0x3f
    adds r0, r7, #0
    ands r0, r2
    lsrs r0, r0, #1
    orrs r4, r0
    adds r1, r7, #0
    ands r1, r3
    adds r0, r6, #0
    ands r0, r2
    lsls r0, r0, #1
lbl_0804fb96:
    adds r1, r1, r0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    movs r2, #2
    b lbl_0804fbce
    .align 2, 0
lbl_0804fba0: .4byte 0x0000ffc0
lbl_0804fba4:
    ldr r4, lbl_0804fbac @ =0x0000ffc0
    ands r4, r6
    movs r2, #0x10
    b lbl_0804fbce
    .align 2, 0
lbl_0804fbac: .4byte 0x0000ffc0
lbl_0804fbb0:
    ldr r0, lbl_0804fbe0 @ =0x0000ffc0
    adds r4, r6, #0
    ands r4, r0
    adds r5, r7, #0
    ands r5, r0
    mov r0, r8
    ldrb r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    bne lbl_0804fbce
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
lbl_0804fbce:
    mov r1, r8
    ldrb r0, [r1, #0x10]
    cmp r0, #3
    beq lbl_0804fbee
    cmp r0, #3
    ble lbl_0804fbe4
    cmp r0, #4
    beq lbl_0804fbfc
    b lbl_0804fc06
    .align 2, 0
lbl_0804fbe0: .4byte 0x0000ffc0
lbl_0804fbe4:
    cmp r0, #1
    blt lbl_0804fc06
    cmp r2, #0x10
    bne lbl_0804fc2c
    b lbl_0804fc2a
lbl_0804fbee:
    cmp r2, #0x11
    bne lbl_0804fc2a
    adds r0, r4, #0
    adds r0, #0x40
    mov r1, r8
    strh r0, [r1, #8]
    b lbl_0804fc2c
lbl_0804fbfc:
    cmp r6, r4
    blo lbl_0804fc2a
    mov r0, r8
    strh r4, [r0, #8]
    b lbl_0804fc2c
lbl_0804fc06:
    cmp r2, #0xc
    beq lbl_0804fc2a
    mov r0, r8
    ldrb r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fc20
    cmp r7, r5
    blo lbl_0804fc2a
    mov r1, r8
    strh r5, [r1, #0xa]
    b lbl_0804fc2c
lbl_0804fc20:
    cmp r7, r5
    bhi lbl_0804fc2a
    mov r0, r8
    strh r5, [r0, #0xa]
    b lbl_0804fc2c
lbl_0804fc2a:
    movs r2, #0
lbl_0804fc2c:
    adds r0, r2, #0
lbl_0804fc2e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start ProjectileSetTrail
ProjectileSetTrail: @ 0x0804fc38
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    ldr r0, lbl_0804fc60 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    ands r0, r2
    cmp r0, #0
    bne lbl_0804fcd8
    movs r5, #0x20
    ldrh r3, [r4, #8]
    ldrh r2, [r4, #0xa]
    ldrb r0, [r4, #0x10]
    cmp r0, #2
    beq lbl_0804fc9c
    cmp r0, #2
    bgt lbl_0804fc64
    cmp r0, #1
    beq lbl_0804fc7e
    b lbl_0804fcba
    .align 2, 0
lbl_0804fc60: .4byte gFrameCounter8Bit
lbl_0804fc64:
    cmp r0, #3
    beq lbl_0804fc6e
    cmp r0, #4
    beq lbl_0804fc74
    b lbl_0804fcba
lbl_0804fc6e:
    adds r0, r3, #0
    adds r0, #0x20
    b lbl_0804fc78
lbl_0804fc74:
    adds r0, r3, #0
    subs r0, #0x20
lbl_0804fc78:
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    b lbl_0804fcce
lbl_0804fc7e:
    movs r0, #0x40
    adds r1, r3, #0
    adds r1, #0x18
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    ldrb r1, [r4]
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fc96
    adds r0, r2, #0
    subs r0, #0x18
    b lbl_0804fcca
lbl_0804fc96:
    adds r0, r2, #0
    adds r0, #0x18
    b lbl_0804fcca
lbl_0804fc9c:
    movs r0, #0x40
    adds r1, r3, #0
    subs r1, #0x18
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    ldrb r1, [r4]
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fcb4
    adds r0, r2, #0
    subs r0, #0x18
    b lbl_0804fcca
lbl_0804fcb4:
    adds r0, r2, #0
    adds r0, #0x18
    b lbl_0804fcca
lbl_0804fcba:
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fcc8
    subs r0, r2, r5
    b lbl_0804fcca
lbl_0804fcc8:
    adds r0, r2, r5
lbl_0804fcca:
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_0804fcce:
    adds r0, r3, #0
    adds r1, r2, #0
    adds r2, r6, #0
    bl ParticleSet
lbl_0804fcd8:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start missile_tumble_move
missile_tumble_move: @ 0x0804fce0
    push {r4, r5, lr}
    adds r2, r0, #0
    ldrb r1, [r2]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804fcf6
    strb r0, [r2]
    b lbl_0804fd40
lbl_0804fcf6:
    ldrb r1, [r2, #0x13]
    ldr r4, lbl_0804fd18 @ =0x08326ca8
    lsls r0, r1, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r3, [r0, r5]
    ldr r0, lbl_0804fd1c @ =0x00007fff
    cmp r3, r0
    bne lbl_0804fd20
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r4
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r5, [r2, #8]
    adds r0, r0, r5
    b lbl_0804fd28
    .align 2, 0
lbl_0804fd18: .4byte 0x08326ca8
lbl_0804fd1c: .4byte 0x00007fff
lbl_0804fd20:
    adds r0, r1, #1
    strb r0, [r2, #0x13]
    ldrh r0, [r2, #8]
    adds r0, r0, r3
lbl_0804fd28:
    strh r0, [r2, #8]
    ldrb r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fd3a
    ldrh r0, [r2, #0xa]
    adds r0, #4
    b lbl_0804fd3e
lbl_0804fd3a:
    ldrh r0, [r2, #0xa]
    subs r0, #4
lbl_0804fd3e:
    strh r0, [r2, #0xa]
lbl_0804fd40:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start check_projectile_hit_block
check_projectile_hit_block: @ 0x0804fd48
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    ldr r0, lbl_0804fd70 @ =gCurrentClipdataAffectingAction
    strb r1, [r0]
    ldrh r3, [r4, #8]
    ldrh r2, [r4, #0xa]
    ldrb r0, [r4, #0x10]
    cmp r0, #0
    bne lbl_0804fd7c
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0804fd74
    adds r0, r2, #0
    subs r0, #8
    b lbl_0804fd78
    .align 2, 0
lbl_0804fd70: .4byte gCurrentClipdataAffectingAction
lbl_0804fd74:
    adds r0, r2, #0
    adds r0, #8
lbl_0804fd78:
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_0804fd7c:
    adds r0, r3, #0
    adds r1, r2, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_0804fd96
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    adds r2, r5, #0
    bl ParticleSet
lbl_0804fd96:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start check_ProjectileHitSprite
check_ProjectileHitSprite: @ 0x0804fd9c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    ldr r0, lbl_0804fe94 @ =gEquipment
    mov sb, r0
    ldr r2, lbl_0804fe98 @ =gCurrentPowerBomb
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0804fe62
    mov r1, sb
    ldrb r0, [r1, #5]
    cmp r0, #0
    beq lbl_0804fe62
    ldrh r1, [r2, #6]
    ldrh r3, [r2, #4]
    ldrh r0, [r2, #0xc]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x18]
    ldrh r0, [r2, #0xe]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    ldrh r0, [r2, #8]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x20]
    ldrh r0, [r2, #0xa]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    ldr r2, lbl_0804fe9c @ =0x00008001
    str r2, [sp, #0x14]
    ldr r6, lbl_0804fea0 @ =gSpriteData
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r0, r6, r3
    cmp r6, r0
    bhs lbl_0804fe62
lbl_0804fdf8:
    ldrh r0, [r6]
    ldr r1, [sp, #0x14]
    ands r0, r1
    cmp r0, #1
    bne lbl_0804fe5a
    ldrh r0, [r6, #0x14]
    cmp r0, #0
    beq lbl_0804fe5a
    adds r0, r6, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0804fe5a
    ldrh r4, [r6, #2]
    ldrh r5, [r6, #4]
    ldrh r0, [r6, #0xa]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldrh r0, [r6, #0xc]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r6, #0xe]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldrh r0, [r6, #0x10]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    ldr r0, [sp, #0x18]
    str r0, [sp]
    ldr r0, [sp, #0x1c]
    str r0, [sp, #4]
    ldr r0, [sp, #0x20]
    str r0, [sp, #8]
    mov r0, sl
    str r0, [sp, #0xc]
    adds r0, r7, #0
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_0804fe5a
    adds r0, r6, #0
    bl power_bomb_deal_damage
lbl_0804fe5a:
    adds r6, #0x38
    ldr r0, lbl_0804fea4 @ =gSpritesetSpritesID
    cmp r6, r0
    blo lbl_0804fdf8
lbl_0804fe62:
    ldr r1, lbl_0804fe9c @ =0x00008001
    str r1, [sp, #0x14]
    movs r2, #0
    ldr r6, lbl_0804fea0 @ =gSpriteData
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r0, r6, r3
    cmp r6, r0
    bhs lbl_0804febe
    ldr r3, lbl_0804fea8 @ =gSpriteDrawOrder
    adds r4, r0, #0
lbl_0804fe78:
    ldrh r0, [r6]
    ldr r1, [sp, #0x14]
    ands r0, r1
    cmp r0, #1
    bne lbl_0804feac
    ldrh r0, [r6, #0x14]
    cmp r0, #0
    beq lbl_0804feac
    adds r1, r2, r3
    adds r0, r6, #0
    adds r0, #0x22
    ldrb r0, [r0]
    b lbl_0804feb0
    .align 2, 0
lbl_0804fe94: .4byte gEquipment
lbl_0804fe98: .4byte gCurrentPowerBomb
lbl_0804fe9c: .4byte 0x00008001
lbl_0804fea0: .4byte gSpriteData
lbl_0804fea4: .4byte gSpritesetSpritesID
lbl_0804fea8: .4byte gSpriteDrawOrder
lbl_0804feac:
    adds r1, r2, r3
    movs r0, #0
lbl_0804feb0:
    strb r0, [r1]
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r6, #0x38
    cmp r6, r4
    blo lbl_0804fe78
lbl_0804febe:
    movs r2, #1
    str r2, [sp, #0x10]
lbl_0804fec2:
    movs r2, #0
    ldr r6, lbl_0804ff94 @ =gSpriteData
    movs r3, #0xa8
    lsls r3, r3, #3
    adds r0, r6, r3
    ldr r1, [sp, #0x10]
    adds r1, #1
    str r1, [sp, #0x28]
    cmp r6, r0
    blo lbl_0804fed8
    b lbl_08050348
lbl_0804fed8:
    ldr r0, lbl_0804ff98 @ =gSpriteDrawOrder
    adds r0, r2, r0
    ldrb r0, [r0]
    adds r3, r6, #0
    adds r3, #0x38
    str r3, [sp, #0x2c]
    adds r2, #1
    str r2, [sp, #0x24]
    ldr r1, [sp, #0x10]
    cmp r0, r1
    beq lbl_0804fef0
    b lbl_08050338
lbl_0804fef0:
    ldrh r1, [r6, #2]
    ldrh r3, [r6, #4]
    ldrh r0, [r6, #0xa]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x18]
    ldrh r0, [r6, #0xc]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x1c]
    ldrh r0, [r6, #0xe]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x20]
    ldrh r0, [r6, #0x10]
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sl, r0
    movs r2, #0x11
    str r2, [sp, #0x14]
    ldr r3, lbl_0804ff9c @ =gProjectileData
    mov r8, r3
    movs r0, #0xe0
    lsls r0, r0, #1
    add r0, r8
    cmp r8, r0
    blo lbl_0804ff30
    b lbl_08050338
lbl_0804ff30:
    mov r1, r8
    ldrb r0, [r1]
    ldr r2, [sp, #0x14]
    ands r0, r2
    cmp r0, r2
    beq lbl_0804ff3e
    b lbl_0805032c
lbl_0804ff3e:
    ldrh r4, [r1, #8]
    ldrh r5, [r1, #0xa]
    ldrh r0, [r1, #0x14]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldrh r0, [r1, #0x16]
    adds r0, r4, r0
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    mov r3, r8
    ldrh r0, [r3, #0x18]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldrh r0, [r3, #0x1a]
    adds r0, r5, r0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    str r7, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #0xc]
    ldr r0, [sp, #0x18]
    ldr r1, [sp, #0x1c]
    ldr r2, [sp, #0x20]
    mov r3, sl
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    bne lbl_0804ff7e
    b lbl_0805032c
lbl_0804ff7e:
    mov r1, r8
    ldrb r0, [r1, #0xf]
    cmp r0, #0xe
    bls lbl_0804ff88
    b lbl_0805032c
lbl_0804ff88:
    lsls r0, r0, #2
    ldr r1, lbl_0804ffa0 @ =lbl_0804ffa4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804ff94: .4byte gSpriteData
lbl_0804ff98: .4byte gSpriteDrawOrder
lbl_0804ff9c: .4byte gProjectileData
lbl_0804ffa0: .4byte lbl_0804ffa4
lbl_0804ffa4: @ jump table
    .4byte lbl_0804ffe0 @ case 0
    .4byte lbl_0804fff2 @ case 1
    .4byte lbl_08050004 @ case 2
    .4byte lbl_08050034 @ case 3
    .4byte lbl_08050098 @ case 4
    .4byte lbl_08050140 @ case 5
    .4byte lbl_08050152 @ case 6
    .4byte lbl_0805016a @ case 7
    .4byte lbl_0805017c @ case 8
    .4byte lbl_080501ac @ case 9
    .4byte lbl_08050216 @ case 10
    .4byte lbl_080502be @ case 11
    .4byte lbl_08050306 @ case 12
    .4byte lbl_08050314 @ case 13
    .4byte lbl_08050322 @ case 14
lbl_0804ffe0:
    movs r0, #0x2a
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #2
    bl ProjectileHitSprite
    b lbl_08050162
lbl_0804fff2:
    movs r0, #0x2b
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #3
    bl ProjectileHitSprite
    b lbl_0805020e
lbl_08050004:
    mov r0, sb
    ldrb r1, [r0, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08050022
    movs r0, #0x2c
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #4
    bl ProjectileIceBeamHittingSprite
    b lbl_080502fe
lbl_08050022:
    movs r0, #0x2c
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #3
    bl ProjectileIceBeamHittingSprite
    b lbl_080502fe
lbl_08050034:
    mov r2, sb
    ldrb r1, [r2, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805006c
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805005a
    movs r0, #0x32
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #5
    bl ProjectileIceBeamHittingSprite
    b lbl_0805020e
lbl_0805005a:
    movs r0, #0x2d
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #4
    bl ProjectileHitSprite
    b lbl_0805020e
lbl_0805006c:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08050086
    movs r0, #0x32
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #4
    bl ProjectileIceBeamHittingSprite
    b lbl_0805020e
lbl_08050086:
    movs r0, #0x2d
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #3
    bl ProjectileHitSprite
    b lbl_0805020e
lbl_08050098:
    mov r0, sb
    ldrb r1, [r0, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080500e0
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080500c6
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080500f0
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #6
    bl ProjectileIceBeamHittingSprite
    b lbl_0805032c
lbl_080500c6:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0805011c
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #5
    bl ProjectileHitSprite
    b lbl_0805032c
lbl_080500e0:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08050114
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08050102
lbl_080500f0:
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #5
    bl ProjectileIceBeamHittingSprite
    b lbl_0805032c
lbl_08050102:
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #4
    bl ProjectileIceBeamHittingSprite
    b lbl_0805032c
lbl_08050114:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0805012e
lbl_0805011c:
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #4
    bl ProjectileHitSprite
    b lbl_0805032c
lbl_0805012e:
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #3
    bl ProjectileHitSprite
    b lbl_0805032c
lbl_08050140:
    adds r0, r6, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_080502fe
lbl_08050152:
    movs r0, #0x2a
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #8
    bl ProjectileNonIceChargedHitSprite
lbl_08050162:
    movs r0, #0
    mov r2, r8
    strb r0, [r2]
    b lbl_0805032c
lbl_0805016a:
    movs r0, #0x2b
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0xc
    bl ProjectileNonIceChargedHitSprite
    b lbl_0805020e
lbl_0805017c:
    mov r0, sb
    ldrb r1, [r0, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805019a
    movs r0, #0x2c
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_080502fe
lbl_0805019a:
    movs r0, #0x2c
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0xc
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_080502fe
lbl_080501ac:
    mov r2, sb
    ldrb r1, [r2, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080501e4
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080501d2
    movs r0, #0x32
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x14
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_0805020e
lbl_080501d2:
    movs r0, #0x2d
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl ProjectileNonIceChargedHitSprite
    b lbl_0805020e
lbl_080501e4:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080501fe
    movs r0, #0x32
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_0805020e
lbl_080501fe:
    movs r0, #0x2d
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0xc
    bl ProjectileNonIceChargedHitSprite
lbl_0805020e:
    movs r0, #0
    mov r3, r8
    strb r0, [r3]
    b lbl_0805032c
lbl_08050216:
    mov r0, sb
    ldrb r1, [r0, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805025e
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08050244
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0805026e
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x18
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_0805032c
lbl_08050244:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0805029a
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x14
    bl ProjectileNonIceChargedHitSprite
    b lbl_0805032c
lbl_0805025e:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08050292
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08050280
lbl_0805026e:
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x14
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_0805032c
lbl_08050280:
    movs r0, #0x33
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl ProjectileChargedIceBeamHittingSprite
    b lbl_0805032c
lbl_08050292:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080502ac
lbl_0805029a:
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl ProjectileNonIceChargedHitSprite
    b lbl_0805032c
lbl_080502ac:
    movs r0, #0x2e
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0xc
    bl ProjectileNonIceChargedHitSprite
    b lbl_0805032c
lbl_080502be:
    adds r0, r6, #0
    adds r0, #0x25
    ldrb r0, [r0]
    cmp r0, #0x14
    bne lbl_080502ee
    adds r1, r6, #0
    adds r1, #0x31
    movs r0, #0
    strb r0, [r1]
    subs r1, #1
    movs r0, #0x3c
    strb r0, [r1]
    adds r0, r6, #0
    adds r0, #0x20
    movs r1, #1
    strb r1, [r0]
    adds r0, #0x14
    strb r1, [r0]
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x2b
    bl ParticleSet
    b lbl_080502fe
lbl_080502ee:
    movs r0, #0x2b
    str r0, [sp]
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #0xc
    bl ProjectileNonIceChargedHitSprite
lbl_080502fe:
    movs r0, #0
    mov r1, r8
    strb r0, [r1]
    b lbl_0805032c
lbl_08050306:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    adds r3, r5, #0
    bl ProjectileMissileHitSprite
    b lbl_0805032c
lbl_08050314:
    adds r0, r6, #0
    mov r1, r8
    adds r2, r4, #0
    adds r3, r5, #0
    bl ProjectileSuperMissileHitSprite
    b lbl_0805032c
lbl_08050322:
    adds r0, r6, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl bomb_hit_sprite
lbl_0805032c:
    movs r2, #0x1c
    add r8, r2
    ldr r0, lbl_08050368 @ =gArmCannonY
    cmp r8, r0
    bhs lbl_08050338
    b lbl_0804ff30
lbl_08050338:
    ldr r3, [sp, #0x24]
    lsls r0, r3, #0x18
    lsrs r2, r0, #0x18
    ldr r6, [sp, #0x2c]
    ldr r0, lbl_0805036c @ =gSpritesetSpritesID
    cmp r6, r0
    bhs lbl_08050348
    b lbl_0804fed8
lbl_08050348:
    ldr r1, [sp, #0x28]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x10]
    cmp r0, #0x10
    bhi lbl_08050356
    b lbl_0804fec2
lbl_08050356:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08050368: .4byte gArmCannonY
lbl_0805036c: .4byte gSpritesetSpritesID

    thumb_func_start get_sprite_weakness
get_sprite_weakness: @ 0x08050370
    push {lr}
    adds r3, r0, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08050388
    ldr r2, lbl_08050384 @ =0x082b1be4
    b lbl_0805038a
    .align 2, 0
lbl_08050384: .4byte 0x082b1be4
lbl_08050388:
    ldr r2, lbl_0805039c @ =0x082b0d68
lbl_0805038a:
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r2, #4
    adds r0, r0, r2
    ldrh r0, [r0]
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805039c: .4byte 0x082b0d68

    thumb_func_start ice_beam_deal_damage
ice_beam_deal_damage: @ 0x080503a0
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r6, #0
    ldrh r0, [r3, #0x14]
    cmp r0, r1
    bls lbl_080503bc
    subs r0, r0, r1
    strh r0, [r3, #0x14]
    movs r6, #0xf0
    adds r4, r3, #0
    adds r4, #0x32
    b lbl_08050400
lbl_080503bc:
    movs r5, #0
    strh r6, [r3, #0x14]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x30
    strb r5, [r0]
    subs r0, #0x10
    strb r5, [r0]
    adds r1, r3, #0
    adds r1, #0x31
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #0
    beq lbl_080503f0
    ldr r2, lbl_08050420 @ =gSamusData
    ldrb r0, [r2, #1]
    cmp r0, #1
    bne lbl_080503f0
    movs r0, #2
    strb r0, [r2, #1]
    strb r5, [r1]
lbl_080503f0:
    adds r0, r3, #0
    adds r0, #0x24
    movs r1, #0x62
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
lbl_08050400:
    adds r2, r3, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    movs r1, #0x11
    orrs r0, r1
    strb r0, [r2]
    ldrb r1, [r4]
    movs r0, #2
    orrs r0, r1
    strb r0, [r4]
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08050420: .4byte gSamusData

    thumb_func_start ProjectileDealDamage
ProjectileDealDamage: @ 0x08050424
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r6, #0
    ldrh r0, [r3, #0x14]
    cmp r0, r1
    bls lbl_0805043e
    subs r0, r0, r1
    strh r0, [r3, #0x14]
    adds r4, r3, #0
    adds r4, #0x32
    b lbl_08050486
lbl_0805043e:
    movs r5, #0
    strh r6, [r3, #0x14]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r2]
    adds r0, r3, #0
    adds r0, #0x30
    strb r5, [r0]
    subs r0, #0x10
    strb r5, [r0]
    adds r1, r3, #0
    adds r1, #0x31
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #0
    beq lbl_08050472
    ldr r2, lbl_080504a8 @ =gSamusData
    ldrb r0, [r2, #1]
    cmp r0, #1
    bne lbl_08050472
    movs r0, #2
    strb r0, [r2, #1]
    strb r5, [r1]
lbl_08050472:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
    adds r1, #2
    movs r0, #1
    strb r0, [r1]
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_08050486:
    adds r2, r3, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    movs r1, #0x11
    orrs r0, r1
    strb r0, [r2]
    ldrb r1, [r4]
    movs r0, #2
    orrs r0, r1
    strb r0, [r4]
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080504a8: .4byte gSamusData

    thumb_func_start ProjectileHitSpriteImmuneToProjectiles
ProjectileHitSpriteImmuneToProjectiles: @ 0x080504ac
    push {lr}
    adds r1, r0, #0
    adds r3, r1, #0
    adds r3, #0x2b
    ldrb r2, [r3]
    movs r1, #0x7f
    ands r1, r2
    cmp r1, #2
    bhs lbl_080504c8
    movs r1, #0x80
    ands r1, r2
    movs r2, #2
    orrs r1, r2
    strb r1, [r3]
lbl_080504c8:
    pop {r1}
    bx r1

    thumb_func_start ProjectileHitSolidSprite
ProjectileHitSolidSprite: @ 0x080504cc
    push {lr}
    adds r1, r0, #0
    adds r3, r1, #0
    adds r3, #0x2b
    ldrb r2, [r3]
    movs r1, #0x7f
    ands r1, r2
    cmp r1, #3
    bhs lbl_080504e8
    movs r1, #0x80
    ands r1, r2
    movs r2, #3
    orrs r1, r2
    strb r1, [r3]
lbl_080504e8:
    pop {r1}
    bx r1

    thumb_func_start power_bomb_deal_damage
power_bomb_deal_damage: @ 0x080504ec
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r4, #0
    adds r5, #0x32
    ldrb r1, [r5]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050506
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    b lbl_080505a6
lbl_08050506:
    movs r0, #8
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    beq lbl_0805051a
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    b lbl_080505a6
lbl_0805051a:
    adds r0, r4, #0
    bl get_sprite_weakness
    movs r1, #0x10
    ands r1, r0
    cmp r1, #0
    beq lbl_0805057c
    ldrh r0, [r4, #0x14]
    cmp r0, #0x32
    bls lbl_08050534
    subs r0, #0x32
    strh r0, [r4, #0x14]
    b lbl_08050572
lbl_08050534:
    movs r3, #0
    strh r6, [r4, #0x14]
    ldrb r1, [r5]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r5]
    adds r0, r4, #0
    adds r0, #0x30
    strb r3, [r0]
    subs r0, #0x10
    strb r3, [r0]
    adds r1, r4, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08050562
    ldr r2, lbl_08050578 @ =gSamusData
    ldrb r0, [r2, #1]
    cmp r0, #1
    bne lbl_08050562
    movs r0, #2
    strb r0, [r2, #1]
    strb r3, [r1]
lbl_08050562:
    adds r0, r4, #0
    adds r0, #0x24
    movs r1, #0x62
    strb r1, [r0]
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
lbl_08050572:
    movs r2, #0x11
    b lbl_0805057e
    .align 2, 0
lbl_08050578: .4byte gSamusData
lbl_0805057c:
    movs r2, #3
lbl_0805057e:
    adds r1, r4, #0
    adds r1, #0x2b
    ldrb r3, [r1]
    movs r0, #0x7f
    ands r0, r3
    cmp r0, r2
    bhs lbl_08050594
    movs r0, #0x80
    orrs r2, r0
    strb r2, [r1]
    b lbl_0805059a
lbl_08050594:
    movs r0, #0x80
    orrs r0, r3
    strb r0, [r1]
lbl_0805059a:
    adds r2, r4, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #2
    orrs r0, r1
    strb r0, [r2]
lbl_080505a6:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start ProjectileHitSprite
ProjectileHitSprite: @ 0x080505ac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r4, r0, #0
    ldr r0, [sp, #0x24]
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    str r5, [sp]
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    mov sl, r6
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r8, r3
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov sb, r7
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_080505f4
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl ParticleSet
    b lbl_08050644
lbl_080505f4:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805060e
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_08050644
lbl_0805060e:
    adds r0, r4, #0
    bl get_sprite_weakness
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08050634
    adds r0, r4, #0
    mov r1, r8
    bl ProjectileDealDamage
    adds r0, r5, #0
    adds r1, r6, #0
    mov r2, sb
    bl ParticleSet
    b lbl_08050644
lbl_08050634:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    ldr r0, [sp]
    mov r1, sl
    movs r2, #0x2f
    bl ParticleSet
lbl_08050644:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ProjectileNonIceChargedHitSprite
ProjectileNonIceChargedHitSprite: @ 0x08050654
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r4, r0, #0
    ldr r0, [sp, #0x24]
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    str r5, [sp]
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    mov sl, r6
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r8, r3
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    mov sb, r7
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0805069c
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r5, #0
    adds r1, r6, #0
    adds r2, r7, #0
    bl ParticleSet
    b lbl_080506ec
lbl_0805069c:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080506b6
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_080506ec
lbl_080506b6:
    adds r0, r4, #0
    bl get_sprite_weakness
    lsls r0, r0, #0x10
    movs r1, #0xc0
    lsls r1, r1, #0xa
    ands r1, r0
    cmp r1, #0
    beq lbl_080506dc
    adds r0, r4, #0
    mov r1, r8
    bl ProjectileDealDamage
    adds r0, r5, #0
    adds r1, r6, #0
    mov r2, sb
    bl ParticleSet
    b lbl_080506ec
lbl_080506dc:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    ldr r0, [sp]
    mov r1, sl
    movs r2, #0x2f
    bl ParticleSet
lbl_080506ec:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start freeze_sprite
freeze_sprite: @ 0x080506fc
    push {lr}
    adds r2, r0, #0
    adds r0, #0x30
    strb r1, [r0]
    adds r0, #3
    ldrb r0, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, r0, r1
    movs r1, #0xf
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x20
    strb r1, [r0]
    movs r0, #0xa0
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ProjectileIceBeamHittingSprite
ProjectileIceBeamHittingSprite: @ 0x08050724
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r4, r0, #0
    ldr r0, [sp, #0x24]
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov r8, r2
    lsls r3, r3, #0x10
    lsrs r6, r3, #0x10
    mov sl, r6
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    str r5, [sp]
    movs r0, #0
    mov sb, r0
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0805076e
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r7, #0
    mov r1, r8
    adds r2, r5, #0
    bl ParticleSet
    b lbl_08050818
lbl_0805076e:
    movs r5, #0x40
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0805078a
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r7, #0
    mov r1, r8
    movs r2, #0x2f
    bl ParticleSet
    b lbl_08050818
lbl_0805078a:
    adds r0, r4, #0
    bl get_sprite_weakness
    lsls r1, r0, #0x10
    lsrs r2, r1, #0x10
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_080507d8
    adds r0, r2, #0
    ands r0, r5
    cmp r0, #0
    beq lbl_080507ce
    lsrs r1, r1, #0x18
    ldr r0, lbl_080507c0 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    bne lbl_080507c4
    adds r0, r4, #0
    adds r1, r6, #0
    bl ice_beam_deal_damage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    b lbl_080507e2
    .align 2, 0
lbl_080507c0: .4byte gFrameCounter8Bit
lbl_080507c4:
    adds r0, r4, #0
    adds r1, r6, #0
    bl ProjectileDealDamage
    b lbl_080507e4
lbl_080507ce:
    adds r0, r4, #0
    mov r1, sl
    bl ProjectileDealDamage
    b lbl_080507e4
lbl_080507d8:
    adds r0, r2, #0
    ands r0, r5
    cmp r0, #0
    beq lbl_080507f0
    movs r0, #0xf0
lbl_080507e2:
    mov sb, r0
lbl_080507e4:
    adds r0, r7, #0
    mov r1, r8
    ldr r2, [sp]
    bl ParticleSet
    b lbl_08050800
lbl_080507f0:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r7, #0
    mov r1, r8
    movs r2, #0x2f
    bl ParticleSet
lbl_08050800:
    mov r0, sb
    cmp r0, #0
    beq lbl_08050818
    adds r0, r4, #0
    mov r1, sb
    bl freeze_sprite
    adds r0, r7, #0
    mov r1, r8
    movs r2, #0x28
    bl ParticleSet
lbl_08050818:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ProjectileChargedIceBeamHittingSprite
ProjectileChargedIceBeamHittingSprite: @ 0x08050828
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r4, r0, #0
    ldr r0, [sp, #0x24]
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r7, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r8, r3
    mov r1, r8
    str r1, [sp]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    mov sl, r5
    movs r0, #0
    mov sb, r0
    adds r0, r4, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08050874
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r5, #0
    bl ParticleSet
    b lbl_08050904
lbl_08050874:
    movs r5, #0x40
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08050890
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r6, #0
    adds r1, r7, #0
    movs r2, #0x2f
    bl ParticleSet
    b lbl_08050904
lbl_08050890:
    adds r0, r4, #0
    bl get_sprite_weakness
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_080508c4
    adds r0, r1, #0
    ands r0, r5
    cmp r0, #0
    beq lbl_080508ba
    adds r0, r4, #0
    mov r1, r8
    bl ice_beam_deal_damage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    b lbl_080508d0
lbl_080508ba:
    adds r0, r4, #0
    ldr r1, [sp]
    bl ProjectileDealDamage
    b lbl_080508d0
lbl_080508c4:
    adds r0, r1, #0
    ands r0, r5
    cmp r0, #0
    beq lbl_080508dc
    movs r1, #0xf0
    mov sb, r1
lbl_080508d0:
    adds r0, r6, #0
    adds r1, r7, #0
    mov r2, sl
    bl ParticleSet
    b lbl_080508ec
lbl_080508dc:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    adds r0, r6, #0
    adds r1, r7, #0
    movs r2, #0x2f
    bl ParticleSet
lbl_080508ec:
    mov r0, sb
    cmp r0, #0
    beq lbl_08050904
    adds r0, r4, #0
    mov r1, sb
    bl freeze_sprite
    adds r0, r6, #0
    adds r1, r7, #0
    movs r2, #0x29
    bl ParticleSet
lbl_08050904:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start start_tumbling_missile
start_tumbling_missile: @ 0x08050914
    push {r4, r5, r6, lr}
    adds r4, r1, #0
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    movs r6, #0
    movs r2, #0
    movs r1, #7
    strb r1, [r4, #0x11]
    strb r2, [r4, #0x13]
    ldrb r1, [r4]
    movs r3, #0xef
    ands r3, r1
    movs r1, #8
    orrs r3, r1
    orrs r3, r6
    strb r3, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldrh r1, [r4, #0xa]
    ldrh r0, [r0, #4]
    cmp r1, r0
    bls lbl_08050946
    movs r0, #0x40
    orrs r3, r0
    b lbl_0805094a
lbl_08050946:
    movs r0, #0xbf
    ands r3, r0
lbl_0805094a:
    strb r3, [r4]
    cmp r5, #0xd
    bne lbl_08050960
    ldr r0, lbl_0805095c @ =0x08327018
    str r0, [r4, #4]
    movs r0, #0xfc
    bl SoundStop
    b lbl_0805096a
    .align 2, 0
lbl_0805095c: .4byte 0x08327018
lbl_08050960:
    ldr r0, lbl_08050970 @ =0x08326fd0
    str r0, [r4, #4]
    movs r0, #0xf9
    bl SoundStop
lbl_0805096a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08050970: .4byte 0x08326fd0

    thumb_func_start kraid_start_tumbling_missile
kraid_start_tumbling_missile: @ 0x08050974
    push {r4, r5, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    movs r5, #0
    movs r1, #0
    movs r0, #7
    strb r0, [r3, #0x11]
    strb r1, [r3, #0x13]
    ldrb r0, [r3]
    movs r2, #0xef
    ands r2, r0
    movs r0, #8
    orrs r2, r0
    orrs r2, r5
    strb r2, [r3]
    strb r1, [r3, #0xe]
    strh r1, [r3, #0xc]
    ldr r1, lbl_080509a8 @ =gCurrentSprite
    ldrh r0, [r3, #0xa]
    ldrh r1, [r1, #4]
    cmp r0, r1
    bls lbl_080509ac
    movs r0, #0x40
    orrs r2, r0
    b lbl_080509b0
    .align 2, 0
lbl_080509a8: .4byte gCurrentSprite
lbl_080509ac:
    movs r0, #0xbf
    ands r2, r0
lbl_080509b0:
    strb r2, [r3]
    cmp r4, #0xd
    bne lbl_080509c8
    ldr r0, lbl_080509c4 @ =0x08327018
    str r0, [r3, #4]
    movs r0, #0xfc
    bl SoundStop
    b lbl_080509d2
    .align 2, 0
lbl_080509c4: .4byte 0x08327018
lbl_080509c8:
    ldr r0, lbl_080509d8 @ =0x08326fd0
    str r0, [r3, #4]
    movs r0, #0xf9
    bl SoundStop
lbl_080509d2:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080509d8: .4byte 0x08326fd0

    thumb_func_start ProjectileMissileHitSprite
ProjectileMissileHitSprite: @ 0x080509dc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r4, r0, #0
    adds r7, r1, #0
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    mov sl, r5
    lsls r3, r3, #0x10
    lsrs r6, r3, #0x10
    mov sb, r6
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    mov r8, r0
    ands r0, r1
    cmp r0, #0
    beq lbl_08050a0c
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    b lbl_08050a36
lbl_08050a0c:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050a20
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r5, #0
    adds r1, r6, #0
    b lbl_08050a4c
lbl_08050a20:
    adds r0, r4, #0
    bl get_sprite_weakness
    mov r1, r8
    ands r1, r0
    cmp r1, #0
    beq lbl_08050a42
    adds r0, r4, #0
    movs r1, #0x14
    bl ProjectileDealDamage
lbl_08050a36:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x30
    bl ParticleSet
    b lbl_08050a5e
lbl_08050a42:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    mov r0, sl
    mov r1, sb
lbl_08050a4c:
    movs r2, #0x2f
    bl ParticleSet
    adds r0, r4, #0
    adds r1, r7, #0
    movs r2, #0xc
    bl start_tumbling_missile
    b lbl_08050a6e
lbl_08050a5e:
    ldrb r0, [r7, #0x11]
    cmp r0, #0
    bne lbl_08050a6a
    adds r0, r7, #0
    bl decrement_missile_counter
lbl_08050a6a:
    movs r0, #0
    strb r0, [r7]
lbl_08050a6e:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ProjectileSuperMissileHitSprite
ProjectileSuperMissileHitSprite: @ 0x08050a7c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    adds r7, r1, #0
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    mov sb, r5
    lsls r3, r3, #0x10
    lsrs r6, r3, #0x10
    mov r8, r6
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08050aa8
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    b lbl_08050ad2
lbl_08050aa8:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050abc
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    adds r0, r5, #0
    adds r1, r6, #0
    b lbl_08050ae8
lbl_08050abc:
    adds r0, r4, #0
    bl get_sprite_weakness
    movs r1, #0xc
    ands r1, r0
    cmp r1, #0
    beq lbl_08050ade
    adds r0, r4, #0
    movs r1, #0x64
    bl ProjectileDealDamage
lbl_08050ad2:
    adds r0, r5, #0
    adds r1, r6, #0
    movs r2, #0x31
    bl ParticleSet
    b lbl_08050afa
lbl_08050ade:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    mov r0, sb
    mov r1, r8
lbl_08050ae8:
    movs r2, #0x2f
    bl ParticleSet
    adds r0, r4, #0
    adds r1, r7, #0
    movs r2, #0xd
    bl start_tumbling_missile
    b lbl_08050b0a
lbl_08050afa:
    ldrb r0, [r7, #0x11]
    cmp r0, #0
    bne lbl_08050b06
    adds r0, r7, #0
    bl decrement_super_missile_counter
lbl_08050b06:
    movs r0, #0
    strb r0, [r7]
lbl_08050b0a:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start bomb_hit_sprite
bomb_hit_sprite: @ 0x08050b18
    push {r4, lr}
    adds r4, r0, #0
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050b30
    adds r0, r4, #0
    bl ProjectileHitSpriteImmuneToProjectiles
    b lbl_08050b5e
lbl_08050b30:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08050b40
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
    b lbl_08050b5e
lbl_08050b40:
    adds r0, r4, #0
    bl get_sprite_weakness
    movs r1, #2
    ands r1, r0
    cmp r1, #0
    beq lbl_08050b58
    adds r0, r4, #0
    movs r1, #8
    bl ProjectileDealDamage
    b lbl_08050b5e
lbl_08050b58:
    adds r0, r4, #0
    bl ProjectileHitSolidSprite
lbl_08050b5e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start ProjectileProcessNormalBeam
ProjectileProcessNormalBeam: @ 0x08050b64
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08050b8c
    ldr r0, lbl_08050b88 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08050ba0
    adds r0, r4, #0
    movs r1, #0x14
    bl move_projectile
    b lbl_08050c3c
    .align 2, 0
lbl_08050b88: .4byte gCurrentClipdataAffectingAction
lbl_08050b8c:
    cmp r0, #1
    bne lbl_08050bc4
    ldr r0, lbl_08050bb0 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08050bb4
lbl_08050ba0:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2a
    bl ParticleSet
    b lbl_08050c4e
    .align 2, 0
lbl_08050bb0: .4byte gCurrentClipdataAffectingAction
lbl_08050bb4:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08050c3c
lbl_08050bc4:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08050c0c
    lsls r0, r0, #2
    ldr r1, lbl_08050bd4 @ =lbl_08050bd8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08050bd4: .4byte lbl_08050bd8
lbl_08050bd8: @ jump table
    .4byte lbl_08050c0c @ case 0
    .4byte lbl_08050bf4 @ case 1
    .4byte lbl_08050bec @ case 2
    .4byte lbl_08050c04 @ case 3
    .4byte lbl_08050bfc @ case 4
lbl_08050bec:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050bf4:
    ldr r0, lbl_08050bf8 @ =0x08327aa8
    b lbl_08050c0e
    .align 2, 0
lbl_08050bf8: .4byte 0x08327aa8
lbl_08050bfc:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050c04:
    ldr r0, lbl_08050c08 @ =0x08327ac0
    b lbl_08050c0e
    .align 2, 0
lbl_08050c08: .4byte 0x08327ac0
lbl_08050c0c:
    ldr r0, lbl_08050c54 @ =0x08327a90
lbl_08050c0e:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x40
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_08050c58 @ =0x0000fff8
    strh r1, [r4, #0x14]
    movs r0, #8
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2a
    bl check_projectile_hit_block
lbl_08050c3c:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08050c4e
    movs r0, #0
    strb r0, [r4]
lbl_08050c4e:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08050c54: .4byte 0x08327a90
lbl_08050c58: .4byte 0x0000fff8

    thumb_func_start ProjectileProcessLongBeam
ProjectileProcessLongBeam: @ 0x08050c5c
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08050c84
    ldr r0, lbl_08050c80 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08050c98
    adds r0, r4, #0
    movs r1, #0x18
    bl move_projectile
    b lbl_08050d34
    .align 2, 0
lbl_08050c80: .4byte gCurrentClipdataAffectingAction
lbl_08050c84:
    cmp r0, #1
    bne lbl_08050cbc
    ldr r0, lbl_08050ca8 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08050cac
lbl_08050c98:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2b
    bl ParticleSet
    b lbl_08050d3a
    .align 2, 0
lbl_08050ca8: .4byte gCurrentClipdataAffectingAction
lbl_08050cac:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08050d34
lbl_08050cbc:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08050d04
    lsls r0, r0, #2
    ldr r1, lbl_08050ccc @ =lbl_08050cd0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08050ccc: .4byte lbl_08050cd0
lbl_08050cd0: @ jump table
    .4byte lbl_08050d04 @ case 0
    .4byte lbl_08050cec @ case 1
    .4byte lbl_08050ce4 @ case 2
    .4byte lbl_08050cfc @ case 3
    .4byte lbl_08050cf4 @ case 4
lbl_08050ce4:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050cec:
    ldr r0, lbl_08050cf0 @ =0x08328460
    b lbl_08050d06
    .align 2, 0
lbl_08050cf0: .4byte 0x08328460
lbl_08050cf4:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050cfc:
    ldr r0, lbl_08050d00 @ =0x08328478
    b lbl_08050d06
    .align 2, 0
lbl_08050d00: .4byte 0x08328478
lbl_08050d04:
    ldr r0, lbl_08050d40 @ =0x08328448
lbl_08050d06:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x40
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_08050d44 @ =0x0000fff4
    strh r1, [r4, #0x14]
    movs r0, #0xc
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2b
    bl check_projectile_hit_block
lbl_08050d34:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08050d3a:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08050d40: .4byte 0x08328448
lbl_08050d44: .4byte 0x0000fff4

    thumb_func_start ProjectileProcessIceBeam
ProjectileProcessIceBeam: @ 0x08050d48
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08050d8c
    ldr r0, lbl_08050d7c @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08050da0
    adds r0, r4, #0
    movs r1, #0x1a
    bl move_projectile
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050d80
    adds r0, r4, #0
    movs r1, #0x17
    b lbl_08050d84
    .align 2, 0
lbl_08050d7c: .4byte gCurrentClipdataAffectingAction
lbl_08050d80:
    adds r0, r4, #0
    movs r1, #0x16
lbl_08050d84:
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_08050e3c
lbl_08050d8c:
    cmp r0, #1
    bne lbl_08050dc4
    ldr r0, lbl_08050db0 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08050db4
lbl_08050da0:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2c
    bl ParticleSet
    b lbl_08050e58
    .align 2, 0
lbl_08050db0: .4byte gCurrentClipdataAffectingAction
lbl_08050db4:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08050e3c
lbl_08050dc4:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08050e0c
    lsls r0, r0, #2
    ldr r1, lbl_08050dd4 @ =lbl_08050dd8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08050dd4: .4byte lbl_08050dd8
lbl_08050dd8: @ jump table
    .4byte lbl_08050e0c @ case 0
    .4byte lbl_08050df4 @ case 1
    .4byte lbl_08050dec @ case 2
    .4byte lbl_08050e04 @ case 3
    .4byte lbl_08050dfc @ case 4
lbl_08050dec:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050df4:
    ldr r0, lbl_08050df8 @ =0x08328e44
    b lbl_08050e0e
    .align 2, 0
lbl_08050df8: .4byte 0x08328e44
lbl_08050dfc:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08050e04:
    ldr r0, lbl_08050e08 @ =0x08328e5c
    b lbl_08050e0e
    .align 2, 0
lbl_08050e08: .4byte 0x08328e5c
lbl_08050e0c:
    ldr r0, lbl_08050e60 @ =0x08328e2c
lbl_08050e0e:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x40
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_08050e64 @ =0x0000ffec
    strh r1, [r4, #0x14]
    movs r0, #0x14
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2c
    bl check_projectile_hit_block
lbl_08050e3c:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_08050e68 @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08050e58
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08050e58
    strb r1, [r4]
lbl_08050e58:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08050e60: .4byte 0x08328e2c
lbl_08050e64: .4byte 0x0000ffec
lbl_08050e68: .4byte gEquipment

    thumb_func_start check_wave_beam_colliding_with_blocks
check_wave_beam_colliding_with_blocks: @ 0x08050e6c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r2, r0, #0
    movs r5, #0
    movs r7, #7
    ldrh r4, [r2, #8]
    ldrh r6, [r2, #0xa]
    ldrb r0, [r2, #0x10]
    cmp r0, #4
    bls lbl_08050e84
    b lbl_08051010
lbl_08050e84:
    lsls r0, r0, #2
    ldr r1, lbl_08050e90 @ =lbl_08050e94
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08050e90: .4byte lbl_08050e94
lbl_08050e94: @ jump table
    .4byte lbl_08051010 @ case 0
    .4byte lbl_08050f3c @ case 1
    .4byte lbl_08050ea8 @ case 2
    .4byte lbl_08050fd0 @ case 3
    .4byte lbl_08050fd0 @ case 4
lbl_08050ea8:
    ldrb r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050ef8
    ldr r0, lbl_08050ef4 @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050eca
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050eca:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    subs r0, #0x2d
    adds r1, r6, #0
    adds r1, #0x2d
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050ee4
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050ee4:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    adds r0, #0x2d
    adds r1, r6, #0
    subs r1, #0x2d
    b lbl_0805104a
    .align 2, 0
lbl_08050ef4: .4byte gCurrentClipdataAffectingAction
lbl_08050ef8:
    ldr r0, lbl_08050f38 @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050f10
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050f10:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    subs r0, #0x2d
    adds r1, r6, #0
    subs r1, #0x2d
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050f2a
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050f2a:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    adds r0, #0x2d
    adds r1, r6, #0
    adds r1, #0x2d
    b lbl_0805104a
    .align 2, 0
lbl_08050f38: .4byte gCurrentClipdataAffectingAction
lbl_08050f3c:
    ldrb r1, [r2]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08050f8c
    ldr r0, lbl_08050f88 @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050f5e
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050f5e:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    subs r0, #0x2d
    adds r1, r6, #0
    subs r1, #0x2d
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050f78
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050f78:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    adds r0, #0x2d
    adds r1, r6, #0
    adds r1, #0x2d
    b lbl_0805104a
    .align 2, 0
lbl_08050f88: .4byte gCurrentClipdataAffectingAction
lbl_08050f8c:
    ldr r0, lbl_08050fcc @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050fa4
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050fa4:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    subs r0, #0x2d
    adds r1, r6, #0
    adds r1, #0x2d
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050fbe
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050fbe:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    adds r0, #0x2d
    adds r1, r6, #0
    subs r1, #0x2d
    b lbl_0805104a
    .align 2, 0
lbl_08050fcc: .4byte gCurrentClipdataAffectingAction
lbl_08050fd0:
    ldr r0, lbl_0805100c @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08050fe8
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08050fe8:
    mov r0, r8
    strb r7, [r0]
    adds r1, r6, #0
    adds r1, #0x40
    adds r0, r4, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08051000
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08051000:
    mov r0, r8
    strb r7, [r0]
    adds r1, r6, #0
    subs r1, #0x40
    adds r0, r4, #0
    b lbl_0805104a
    .align 2, 0
lbl_0805100c: .4byte gCurrentClipdataAffectingAction
lbl_08051010:
    ldr r0, lbl_08051064 @ =gCurrentClipdataAffectingAction
    mov r8, r0
    strb r7, [r0]
    adds r0, r4, #0
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08051028
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08051028:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    adds r0, #0x40
    adds r1, r6, #0
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08051040
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08051040:
    mov r0, r8
    strb r7, [r0]
    adds r0, r4, #0
    subs r0, #0x40
    adds r1, r6, #0
lbl_0805104a:
    bl sub_0804fa18
    cmp r0, #0
    beq lbl_08051058
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_08051058:
    adds r0, r5, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08051064: .4byte gCurrentClipdataAffectingAction

    thumb_func_start ProjectileProcessWaveBeam
ProjectileProcessWaveBeam: @ 0x08051068
    push {r4, r5, lr}
    adds r4, r0, #0
    bl check_wave_beam_colliding_with_blocks
    ldrb r0, [r4, #0x11]
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_080510ac
    adds r0, r4, #0
    movs r1, #0x1c
    bl move_projectile
    ldr r0, lbl_0805109c @ =gEquipment
    ldrb r0, [r0, #0xd]
    ands r5, r0
    cmp r5, #0
    beq lbl_08051166
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080510a0
    adds r0, r4, #0
    movs r1, #0x17
    b lbl_080510a4
    .align 2, 0
lbl_0805109c: .4byte gEquipment
lbl_080510a0:
    adds r0, r4, #0
    movs r1, #0x16
lbl_080510a4:
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_08051166
lbl_080510ac:
    cmp r5, #1
    bne lbl_080510be
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08051166
lbl_080510be:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051138
    lsls r0, r0, #2
    ldr r1, lbl_080510d0 @ =lbl_080510d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080510d0: .4byte lbl_080510d4
lbl_080510d4: @ jump table
    .4byte lbl_08051138 @ case 0
    .4byte lbl_080510f0 @ case 1
    .4byte lbl_080510e8 @ case 2
    .4byte lbl_08051118 @ case 3
    .4byte lbl_08051110 @ case 4
lbl_080510e8:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080510f0:
    ldr r0, lbl_08051104 @ =0x08329cac
    str r0, [r4, #4]
    ldr r0, lbl_08051108 @ =0x0000fff0
    strh r0, [r4, #0x14]
    movs r0, #0x40
    strh r0, [r4, #0x16]
    ldr r0, lbl_0805110c @ =0x0000ffd8
    strh r0, [r4, #0x18]
    movs r0, #0x28
    b lbl_0805114a
    .align 2, 0
lbl_08051104: .4byte 0x08329cac
lbl_08051108: .4byte 0x0000fff0
lbl_0805110c: .4byte 0x0000ffd8
lbl_08051110:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051118:
    ldr r0, lbl_0805112c @ =0x08329cec
    str r0, [r4, #4]
    ldr r0, lbl_08051130 @ =0x0000ffec
    strh r0, [r4, #0x14]
    movs r0, #0x14
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051134 @ =0x0000ffc0
    strh r0, [r4, #0x18]
    movs r0, #0x40
    b lbl_0805114a
    .align 2, 0
lbl_0805112c: .4byte 0x08329cec
lbl_08051130: .4byte 0x0000ffec
lbl_08051134: .4byte 0x0000ffc0
lbl_08051138:
    ldr r0, lbl_08051188 @ =0x08329c6c
    str r0, [r4, #4]
    ldr r0, lbl_0805118c @ =0x0000ffc0
    strh r0, [r4, #0x14]
    movs r0, #0x40
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051190 @ =0x0000ffec
    strh r0, [r4, #0x18]
    movs r0, #0x14
lbl_0805114a:
    strh r0, [r4, #0x1a]
    movs r2, #0
    movs r0, #0xa0
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    movs r0, #1
    strb r0, [r4, #0x11]
lbl_08051166:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_08051194 @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08051182
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08051182
    strb r1, [r4]
lbl_08051182:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051188: .4byte 0x08329c6c
lbl_0805118c: .4byte 0x0000ffc0
lbl_08051190: .4byte 0x0000ffec
lbl_08051194: .4byte gEquipment

    thumb_func_start ProjectileProcessPlasmaBeam
ProjectileProcessPlasmaBeam: @ 0x08051198
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r0, lbl_080511cc @ =gEquipment
    ldrb r1, [r0, #0xd]
    movs r0, #4
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    bne lbl_080511d4
    ldr r0, lbl_080511d0 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_080511da
    strb r6, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2e
    bl ParticleSet
    b lbl_08051346
    .align 2, 0
lbl_080511cc: .4byte gEquipment
lbl_080511d0: .4byte gCurrentClipdataAffectingAction
lbl_080511d4:
    adds r0, r4, #0
    bl check_wave_beam_colliding_with_blocks
lbl_080511da:
    ldrb r0, [r4, #0x11]
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_08051218
    adds r0, r4, #0
    movs r1, #0x20
    bl move_projectile
    ldr r0, lbl_08051208 @ =gEquipment
    ldrb r0, [r0, #0xd]
    ands r5, r0
    cmp r5, #0
    bne lbl_080511f6
    b lbl_0805132a
lbl_080511f6:
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805120c
    adds r0, r4, #0
    movs r1, #0x17
    b lbl_08051210
    .align 2, 0
lbl_08051208: .4byte gEquipment
lbl_0805120c:
    adds r0, r4, #0
    movs r1, #0x16
lbl_08051210:
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_0805132a
lbl_08051218:
    cmp r5, #1
    bne lbl_0805122a
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_0805132a
lbl_0805122a:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_080512c4
    lsls r0, r0, #2
    ldr r1, lbl_0805123c @ =lbl_08051240
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805123c: .4byte lbl_08051240
lbl_08051240: @ jump table
    .4byte lbl_080512c4 @ case 0
    .4byte lbl_0805125c @ case 1
    .4byte lbl_08051254 @ case 2
    .4byte lbl_08051294 @ case 3
    .4byte lbl_0805128c @ case 4
lbl_08051254:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_0805125c:
    cmp r6, #0
    beq lbl_08051284
    ldr r0, lbl_08051278 @ =0x0832ae38
    str r0, [r4, #4]
    ldr r0, lbl_0805127c @ =0x0000fff0
    strh r0, [r4, #0x14]
    movs r0, #0x40
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051280 @ =0x0000ffd0
    strh r0, [r4, #0x18]
    movs r0, #0x30
    strh r0, [r4, #0x1a]
    b lbl_080512f0
    .align 2, 0
lbl_08051278: .4byte 0x0832ae38
lbl_0805127c: .4byte 0x0000fff0
lbl_08051280: .4byte 0x0000ffd0
lbl_08051284:
    ldr r0, lbl_08051288 @ =0x0832ad38
    b lbl_080512ee
    .align 2, 0
lbl_08051288: .4byte 0x0832ad38
lbl_0805128c:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051294:
    cmp r6, #0
    beq lbl_080512bc
    ldr r0, lbl_080512b0 @ =0x0832ae78
    str r0, [r4, #4]
    ldr r0, lbl_080512b4 @ =0x0000ffe0
    strh r0, [r4, #0x14]
    movs r0, #0x20
    strh r0, [r4, #0x16]
    ldr r0, lbl_080512b8 @ =0x0000ffc0
    strh r0, [r4, #0x18]
    movs r0, #0x40
    strh r0, [r4, #0x1a]
    b lbl_080512f0
    .align 2, 0
lbl_080512b0: .4byte 0x0832ae78
lbl_080512b4: .4byte 0x0000ffe0
lbl_080512b8: .4byte 0x0000ffc0
lbl_080512bc:
    ldr r0, lbl_080512c0 @ =0x0832ad50
    b lbl_080512ee
    .align 2, 0
lbl_080512c0: .4byte 0x0832ad50
lbl_080512c4:
    cmp r6, #0
    beq lbl_080512ec
    ldr r0, lbl_080512e0 @ =0x0832adf8
    str r0, [r4, #4]
    ldr r0, lbl_080512e4 @ =0x0000ffc0
    strh r0, [r4, #0x14]
    movs r0, #0x40
    strh r0, [r4, #0x16]
    ldr r0, lbl_080512e8 @ =0x0000ffe0
    strh r0, [r4, #0x18]
    movs r0, #0x20
    strh r0, [r4, #0x1a]
    b lbl_080512f0
    .align 2, 0
lbl_080512e0: .4byte 0x0832adf8
lbl_080512e4: .4byte 0x0000ffc0
lbl_080512e8: .4byte 0x0000ffe0
lbl_080512ec:
    ldr r0, lbl_08051304 @ =0x0832ad20
lbl_080512ee:
    str r0, [r4, #4]
lbl_080512f0:
    cmp r6, #0
    beq lbl_08051308
    movs r0, #0xa0
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #8
    orrs r0, r1
    strb r0, [r4]
    b lbl_08051318
    .align 2, 0
lbl_08051304: .4byte 0x0832ad20
lbl_08051308:
    movs r0, #0x50
    strb r0, [r4, #0x12]
    ldr r1, lbl_0805134c @ =0x0000ffec
    strh r1, [r4, #0x14]
    movs r0, #0x14
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
lbl_08051318:
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    movs r1, #0
    strb r0, [r4]
    strb r1, [r4, #0xe]
    strh r1, [r4, #0xc]
    movs r0, #1
    strb r0, [r4, #0x11]
lbl_0805132a:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_08051350 @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08051346
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08051346
    strb r1, [r4]
lbl_08051346:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805134c: .4byte 0x0000ffec
lbl_08051350: .4byte gEquipment

    thumb_func_start ProjectileProcessPistol
ProjectileProcessPistol: @ 0x08051354
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_0805137c
    ldr r0, lbl_08051378 @ =gCurrentClipdataAffectingAction
    movs r1, #8
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051390
    adds r0, r4, #0
    movs r1, #0x16
    bl move_projectile
    b lbl_0805142c
    .align 2, 0
lbl_08051378: .4byte gCurrentClipdataAffectingAction
lbl_0805137c:
    cmp r0, #1
    bne lbl_080513b4
    ldr r0, lbl_080513a0 @ =gCurrentClipdataAffectingAction
    movs r1, #8
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_080513a4
lbl_08051390:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2a
    bl ParticleSet
    b lbl_08051432
    .align 2, 0
lbl_080513a0: .4byte gCurrentClipdataAffectingAction
lbl_080513a4:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_0805142c
lbl_080513b4:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_080513fc
    lsls r0, r0, #2
    ldr r1, lbl_080513c4 @ =lbl_080513c8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080513c4: .4byte lbl_080513c8
lbl_080513c8: @ jump table
    .4byte lbl_080513fc @ case 0
    .4byte lbl_080513e4 @ case 1
    .4byte lbl_080513dc @ case 2
    .4byte lbl_080513f4 @ case 3
    .4byte lbl_080513ec @ case 4
lbl_080513dc:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080513e4:
    ldr r0, lbl_080513e8 @ =0x0832b948
    b lbl_080513fe
    .align 2, 0
lbl_080513e8: .4byte 0x0832b948
lbl_080513ec:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080513f4:
    ldr r0, lbl_080513f8 @ =0x0832b960
    b lbl_080513fe
    .align 2, 0
lbl_080513f8: .4byte 0x0832b960
lbl_080513fc:
    ldr r0, lbl_08051438 @ =0x0832b930
lbl_080513fe:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x40
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_0805143c @ =0x0000fffc
    strh r1, [r4, #0x14]
    movs r0, #4
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #8
    movs r2, #0x2a
    bl check_projectile_hit_block
lbl_0805142c:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08051432:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051438: .4byte 0x0832b930
lbl_0805143c: .4byte 0x0000fffc

    thumb_func_start ProjectileProcessChargedNormalBeam
ProjectileProcessChargedNormalBeam: @ 0x08051440
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08051468
    ldr r0, lbl_08051464 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_0805147c
    adds r0, r4, #0
    movs r1, #0x14
    bl move_projectile
    b lbl_08051518
    .align 2, 0
lbl_08051464: .4byte gCurrentClipdataAffectingAction
lbl_08051468:
    cmp r0, #1
    bne lbl_080514a0
    ldr r0, lbl_0805148c @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08051490
lbl_0805147c:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2a
    bl ParticleSet
    b lbl_0805152a
    .align 2, 0
lbl_0805148c: .4byte gCurrentClipdataAffectingAction
lbl_08051490:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08051518
lbl_080514a0:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_080514e8
    lsls r0, r0, #2
    ldr r1, lbl_080514b0 @ =lbl_080514b4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080514b0: .4byte lbl_080514b4
lbl_080514b4: @ jump table
    .4byte lbl_080514e8 @ case 0
    .4byte lbl_080514d0 @ case 1
    .4byte lbl_080514c8 @ case 2
    .4byte lbl_080514e0 @ case 3
    .4byte lbl_080514d8 @ case 4
lbl_080514c8:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080514d0:
    ldr r0, lbl_080514d4 @ =0x08327b38
    b lbl_080514ea
    .align 2, 0
lbl_080514d4: .4byte 0x08327b38
lbl_080514d8:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080514e0:
    ldr r0, lbl_080514e4 @ =0x08327b50
    b lbl_080514ea
    .align 2, 0
lbl_080514e4: .4byte 0x08327b50
lbl_080514e8:
    ldr r0, lbl_08051530 @ =0x08327b20
lbl_080514ea:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x60
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_08051534 @ =0x0000fff4
    strh r1, [r4, #0x14]
    movs r0, #0xc
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2a
    bl check_projectile_hit_block
lbl_08051518:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_0805152a
    movs r0, #0
    strb r0, [r4]
lbl_0805152a:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051530: .4byte 0x08327b20
lbl_08051534: .4byte 0x0000fff4

    thumb_func_start ProjectileProcessChargedLongBeam
ProjectileProcessChargedLongBeam: @ 0x08051538
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_0805156c
    ldr r0, lbl_08051568 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051580
    adds r0, r4, #0
    movs r1, #0x18
    bl move_projectile
    adds r0, r4, #0
    movs r1, #0x18
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_0805161c
    .align 2, 0
lbl_08051568: .4byte gCurrentClipdataAffectingAction
lbl_0805156c:
    cmp r0, #1
    bne lbl_080515a4
    ldr r0, lbl_08051590 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08051594
lbl_08051580:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2b
    bl ParticleSet
    b lbl_08051622
    .align 2, 0
lbl_08051590: .4byte gCurrentClipdataAffectingAction
lbl_08051594:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_0805161c
lbl_080515a4:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_080515ec
    lsls r0, r0, #2
    ldr r1, lbl_080515b4 @ =lbl_080515b8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080515b4: .4byte lbl_080515b8
lbl_080515b8: @ jump table
    .4byte lbl_080515ec @ case 0
    .4byte lbl_080515d4 @ case 1
    .4byte lbl_080515cc @ case 2
    .4byte lbl_080515e4 @ case 3
    .4byte lbl_080515dc @ case 4
lbl_080515cc:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080515d4:
    ldr r0, lbl_080515d8 @ =0x083284a8
    b lbl_080515ee
    .align 2, 0
lbl_080515d8: .4byte 0x083284a8
lbl_080515dc:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080515e4:
    ldr r0, lbl_080515e8 @ =0x083284c0
    b lbl_080515ee
    .align 2, 0
lbl_080515e8: .4byte 0x083284c0
lbl_080515ec:
    ldr r0, lbl_08051628 @ =0x08328490
lbl_080515ee:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x80
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_0805162c @ =0x0000fff0
    strh r1, [r4, #0x14]
    movs r0, #0x10
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2b
    bl check_projectile_hit_block
lbl_0805161c:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08051622:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051628: .4byte 0x08328490
lbl_0805162c: .4byte 0x0000fff0

    thumb_func_start ProjectileProcessChargedIceBeam
ProjectileProcessChargedIceBeam: @ 0x08051630
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08051682
    ldr r0, lbl_08051668 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051696
    adds r0, r4, #0
    movs r1, #0x1a
    bl move_projectile
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805166c
    adds r0, r4, #0
    movs r1, #0x17
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_08051676
    .align 2, 0
lbl_08051668: .4byte gCurrentClipdataAffectingAction
lbl_0805166c:
    adds r0, r4, #0
    movs r1, #0x16
    movs r2, #3
    bl ProjectileSetTrail
lbl_08051676:
    adds r0, r4, #0
    movs r1, #0x19
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_08051734
lbl_08051682:
    cmp r0, #1
    bne lbl_080516bc
    ldr r0, lbl_080516a8 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_080516ac
lbl_08051696:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2c
    bl ParticleSet
    b lbl_08051750
    .align 2, 0
lbl_080516a8: .4byte gCurrentClipdataAffectingAction
lbl_080516ac:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08051734
lbl_080516bc:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051704
    lsls r0, r0, #2
    ldr r1, lbl_080516cc @ =lbl_080516d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080516cc: .4byte lbl_080516d0
lbl_080516d0: @ jump table
    .4byte lbl_08051704 @ case 0
    .4byte lbl_080516ec @ case 1
    .4byte lbl_080516e4 @ case 2
    .4byte lbl_080516fc @ case 3
    .4byte lbl_080516f4 @ case 4
lbl_080516e4:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080516ec:
    ldr r0, lbl_080516f0 @ =0x08328ed4
    b lbl_08051706
    .align 2, 0
lbl_080516f0: .4byte 0x08328ed4
lbl_080516f4:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080516fc:
    ldr r0, lbl_08051700 @ =0x08328eec
    b lbl_08051706
    .align 2, 0
lbl_08051700: .4byte 0x08328eec
lbl_08051704:
    ldr r0, lbl_08051758 @ =0x08328ebc
lbl_08051706:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x80
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_0805175c @ =0x0000ffe8
    strh r1, [r4, #0x14]
    movs r0, #0x18
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #7
    movs r2, #0x2c
    bl check_projectile_hit_block
lbl_08051734:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_08051760 @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08051750
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08051750
    strb r1, [r4]
lbl_08051750:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051758: .4byte 0x08328ebc
lbl_0805175c: .4byte 0x0000ffe8
lbl_08051760: .4byte gEquipment

    thumb_func_start ProjectileProcessChargedWaveBeam
ProjectileProcessChargedWaveBeam: @ 0x08051764
    push {r4, r5, lr}
    adds r4, r0, #0
    bl check_wave_beam_colliding_with_blocks
    ldrb r0, [r4, #0x11]
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_080517b6
    adds r0, r4, #0
    movs r1, #0x1c
    bl move_projectile
    ldr r0, lbl_0805179c @ =gEquipment
    ldrb r0, [r0, #0xd]
    ands r5, r0
    cmp r5, #0
    beq lbl_080517aa
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080517a0
    adds r0, r4, #0
    movs r1, #0x17
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_080517aa
    .align 2, 0
lbl_0805179c: .4byte gEquipment
lbl_080517a0:
    adds r0, r4, #0
    movs r1, #0x16
    movs r2, #3
    bl ProjectileSetTrail
lbl_080517aa:
    adds r0, r4, #0
    movs r1, #0x1a
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_0805186e
lbl_080517b6:
    cmp r5, #1
    bne lbl_080517c8
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_0805186e
lbl_080517c8:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051840
    lsls r0, r0, #2
    ldr r1, lbl_080517d8 @ =lbl_080517dc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080517d8: .4byte lbl_080517dc
lbl_080517dc: @ jump table
    .4byte lbl_08051840 @ case 0
    .4byte lbl_080517f8 @ case 1
    .4byte lbl_080517f0 @ case 2
    .4byte lbl_08051820 @ case 3
    .4byte lbl_08051818 @ case 4
lbl_080517f0:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080517f8:
    ldr r0, lbl_0805180c @ =0x08329e2c
    str r0, [r4, #4]
    ldr r0, lbl_08051810 @ =0x0000fff0
    strh r0, [r4, #0x14]
    movs r0, #0x48
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051814 @ =0x0000ffd0
    strh r0, [r4, #0x18]
    movs r0, #0x30
    b lbl_08051852
    .align 2, 0
lbl_0805180c: .4byte 0x08329e2c
lbl_08051810: .4byte 0x0000fff0
lbl_08051814: .4byte 0x0000ffd0
lbl_08051818:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051820:
    ldr r0, lbl_08051834 @ =0x08329e6c
    str r0, [r4, #4]
    ldr r0, lbl_08051838 @ =0x0000ffec
    strh r0, [r4, #0x14]
    movs r0, #0x14
    strh r0, [r4, #0x16]
    ldr r0, lbl_0805183c @ =0x0000ffb8
    strh r0, [r4, #0x18]
    movs r0, #0x48
    b lbl_08051852
    .align 2, 0
lbl_08051834: .4byte 0x08329e6c
lbl_08051838: .4byte 0x0000ffec
lbl_0805183c: .4byte 0x0000ffb8
lbl_08051840:
    ldr r0, lbl_08051890 @ =0x08329dec
    str r0, [r4, #4]
    ldr r0, lbl_08051894 @ =0x0000ffb8
    strh r0, [r4, #0x14]
    movs r0, #0x48
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051898 @ =0x0000ffec
    strh r0, [r4, #0x18]
    movs r0, #0x14
lbl_08051852:
    strh r0, [r4, #0x1a]
    movs r2, #0
    movs r0, #0xc0
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    movs r0, #1
    strb r0, [r4, #0x11]
lbl_0805186e:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_0805189c @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_0805188a
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_0805188a
    strb r1, [r4]
lbl_0805188a:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051890: .4byte 0x08329dec
lbl_08051894: .4byte 0x0000ffb8
lbl_08051898: .4byte 0x0000ffec
lbl_0805189c: .4byte gEquipment

    thumb_func_start ProjectileProcessChargedPlasmaBeam
ProjectileProcessChargedPlasmaBeam: @ 0x080518a0
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r0, lbl_080518d4 @ =gEquipment
    ldrb r1, [r0, #0xd]
    movs r0, #4
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0
    bne lbl_080518dc
    ldr r0, lbl_080518d8 @ =gCurrentClipdataAffectingAction
    movs r1, #7
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_080518e2
    strb r6, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2e
    bl ParticleSet
    b lbl_08051a6c
    .align 2, 0
lbl_080518d4: .4byte gEquipment
lbl_080518d8: .4byte gCurrentClipdataAffectingAction
lbl_080518dc:
    adds r0, r4, #0
    bl check_wave_beam_colliding_with_blocks
lbl_080518e2:
    ldrb r0, [r4, #0x11]
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_08051942
    adds r0, r4, #0
    movs r1, #0x20
    bl move_projectile
    ldr r0, lbl_08051914 @ =gEquipment
    ldrb r0, [r0, #0xd]
    ands r5, r0
    cmp r5, #0
    beq lbl_0805192c
    ldrb r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08051918
    adds r0, r4, #0
    movs r1, #0x17
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_08051922
    .align 2, 0
lbl_08051914: .4byte gEquipment
lbl_08051918:
    adds r0, r4, #0
    movs r1, #0x16
    movs r2, #3
    bl ProjectileSetTrail
lbl_08051922:
    cmp r6, #0
    beq lbl_08051936
    adds r0, r4, #0
    movs r1, #0x1c
    b lbl_0805193a
lbl_0805192c:
    cmp r6, #0
    beq lbl_08051936
    adds r0, r4, #0
    movs r1, #0x1c
    b lbl_0805193a
lbl_08051936:
    adds r0, r4, #0
    movs r1, #0x1b
lbl_0805193a:
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_08051a50
lbl_08051942:
    cmp r5, #1
    bne lbl_08051954
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08051a50
lbl_08051954:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_080519ec
    lsls r0, r0, #2
    ldr r1, lbl_08051964 @ =lbl_08051968
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08051964: .4byte lbl_08051968
lbl_08051968: @ jump table
    .4byte lbl_080519ec @ case 0
    .4byte lbl_08051984 @ case 1
    .4byte lbl_0805197c @ case 2
    .4byte lbl_080519bc @ case 3
    .4byte lbl_080519b4 @ case 4
lbl_0805197c:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051984:
    cmp r6, #0
    beq lbl_080519ac
    ldr r0, lbl_080519a0 @ =0x0832af88
    str r0, [r4, #4]
    ldr r0, lbl_080519a4 @ =0x0000fff0
    strh r0, [r4, #0x14]
    movs r0, #0x48
    strh r0, [r4, #0x16]
    ldr r0, lbl_080519a8 @ =0x0000ffc8
    strh r0, [r4, #0x18]
    movs r0, #0x38
    strh r0, [r4, #0x1a]
    b lbl_08051a18
    .align 2, 0
lbl_080519a0: .4byte 0x0832af88
lbl_080519a4: .4byte 0x0000fff0
lbl_080519a8: .4byte 0x0000ffc8
lbl_080519ac:
    ldr r0, lbl_080519b0 @ =0x0832adc8
    b lbl_08051a16
    .align 2, 0
lbl_080519b0: .4byte 0x0832adc8
lbl_080519b4:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_080519bc:
    cmp r6, #0
    beq lbl_080519e4
    ldr r0, lbl_080519d8 @ =0x0832afc8
    str r0, [r4, #4]
    ldr r0, lbl_080519dc @ =0x0000ffdc
    strh r0, [r4, #0x14]
    movs r0, #0x24
    strh r0, [r4, #0x16]
    ldr r0, lbl_080519e0 @ =0x0000ffb8
    strh r0, [r4, #0x18]
    movs r0, #0x48
    strh r0, [r4, #0x1a]
    b lbl_08051a18
    .align 2, 0
lbl_080519d8: .4byte 0x0832afc8
lbl_080519dc: .4byte 0x0000ffdc
lbl_080519e0: .4byte 0x0000ffb8
lbl_080519e4:
    ldr r0, lbl_080519e8 @ =0x0832ade0
    b lbl_08051a16
    .align 2, 0
lbl_080519e8: .4byte 0x0832ade0
lbl_080519ec:
    cmp r6, #0
    beq lbl_08051a14
    ldr r0, lbl_08051a08 @ =0x0832af48
    str r0, [r4, #4]
    ldr r0, lbl_08051a0c @ =0x0000ffb8
    strh r0, [r4, #0x14]
    movs r0, #0x48
    strh r0, [r4, #0x16]
    ldr r0, lbl_08051a10 @ =0x0000ffdc
    strh r0, [r4, #0x18]
    movs r0, #0x24
    strh r0, [r4, #0x1a]
    b lbl_08051a18
    .align 2, 0
lbl_08051a08: .4byte 0x0832af48
lbl_08051a0c: .4byte 0x0000ffb8
lbl_08051a10: .4byte 0x0000ffdc
lbl_08051a14:
    ldr r0, lbl_08051a3c @ =0x0832adb0
lbl_08051a16:
    str r0, [r4, #4]
lbl_08051a18:
    ldrb r0, [r4]
    movs r2, #0xfb
    ands r2, r0
    movs r0, #0
    strb r2, [r4]
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    movs r0, #1
    strb r0, [r4, #0x11]
    cmp r6, #0
    beq lbl_08051a40
    movs r0, #0xe0
    strb r0, [r4, #0x12]
    movs r1, #8
    adds r0, r2, #0
    orrs r0, r1
    strb r0, [r4]
    b lbl_08051a50
    .align 2, 0
lbl_08051a3c: .4byte 0x0832adb0
lbl_08051a40:
    movs r0, #0xc0
    strb r0, [r4, #0x12]
    ldr r1, lbl_08051a74 @ =0x0000ffe8
    strh r1, [r4, #0x14]
    movs r0, #0x18
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
lbl_08051a50:
    ldrb r0, [r4, #0x13]
    adds r2, r0, #1
    strb r2, [r4, #0x13]
    ldr r0, lbl_08051a78 @ =gEquipment
    ldrb r0, [r0, #0xd]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08051a6c
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xc
    bls lbl_08051a6c
    strb r1, [r4]
lbl_08051a6c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051a74: .4byte 0x0000ffe8
lbl_08051a78: .4byte gEquipment

    thumb_func_start ProjectileProcessChargedPistol
ProjectileProcessChargedPistol: @ 0x08051a7c
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08051ab0
    ldr r0, lbl_08051aac @ =gCurrentClipdataAffectingAction
    movs r1, #8
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051ac4
    adds r0, r4, #0
    movs r1, #0x16
    bl move_projectile
    adds r0, r4, #0
    movs r1, #0x1d
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_08051b60
    .align 2, 0
lbl_08051aac: .4byte gCurrentClipdataAffectingAction
lbl_08051ab0:
    cmp r0, #1
    bne lbl_08051ae8
    ldr r0, lbl_08051ad4 @ =gCurrentClipdataAffectingAction
    movs r1, #8
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08051ad8
lbl_08051ac4:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x2b
    bl ParticleSet
    b lbl_08051b66
    .align 2, 0
lbl_08051ad4: .4byte gCurrentClipdataAffectingAction
lbl_08051ad8:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x10
    bl move_projectile
    b lbl_08051b60
lbl_08051ae8:
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051b30
    lsls r0, r0, #2
    ldr r1, lbl_08051af8 @ =lbl_08051afc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08051af8: .4byte lbl_08051afc
lbl_08051afc: @ jump table
    .4byte lbl_08051b30 @ case 0
    .4byte lbl_08051b18 @ case 1
    .4byte lbl_08051b10 @ case 2
    .4byte lbl_08051b28 @ case 3
    .4byte lbl_08051b20 @ case 4
lbl_08051b10:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051b18:
    ldr r0, lbl_08051b1c @ =0x0832b990
    b lbl_08051b32
    .align 2, 0
lbl_08051b1c: .4byte 0x0832b990
lbl_08051b20:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051b28:
    ldr r0, lbl_08051b2c @ =0x0832b9a8
    b lbl_08051b32
    .align 2, 0
lbl_08051b2c: .4byte 0x0832b9a8
lbl_08051b30:
    ldr r0, lbl_08051b6c @ =0x0832b978
lbl_08051b32:
    str r0, [r4, #4]
    movs r2, #0
    movs r0, #0x80
    strb r0, [r4, #0x12]
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
    strb r2, [r4, #0xe]
    strh r2, [r4, #0xc]
    ldr r1, lbl_08051b70 @ =0x0000fff4
    strh r1, [r4, #0x14]
    movs r0, #0xc
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    movs r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #8
    movs r2, #0x2b
    bl check_projectile_hit_block
lbl_08051b60:
    ldrb r0, [r4, #0x13]
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08051b66:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051b6c: .4byte 0x0832b978
lbl_08051b70: .4byte 0x0000fff4

    thumb_func_start decrement_missile_counter
decrement_missile_counter: @ 0x08051b74
    push {lr}
    adds r3, r0, #0
    ldr r1, lbl_08051ba4 @ =gEquipment
    ldrh r0, [r1, #8]
    cmp r0, #0
    beq lbl_08051b94
    subs r0, #1
    strh r0, [r1, #8]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_08051b94
    ldr r0, lbl_08051ba8 @ =gSamusWeaponInfo
    ldrb r1, [r0, #2]
    movs r2, #1
    eors r1, r2
    strb r1, [r0, #2]
lbl_08051b94:
    movs r0, #0x40
    strb r0, [r3, #0x12]
    ldrb r1, [r3]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r3]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051ba4: .4byte gEquipment
lbl_08051ba8: .4byte gSamusWeaponInfo

    thumb_func_start ProjectileProcessMissile
ProjectileProcessMissile: @ 0x08051bac
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08051bec
    ldr r0, lbl_08051be8 @ =gCurrentClipdataAffectingAction
    movs r1, #9
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051c00
    ldrb r1, [r4, #0x13]
    adds r1, #8
    adds r0, r4, #0
    bl move_projectile
    ldrb r0, [r4, #0x13]
    cmp r0, #0xb
    bhi lbl_08051bda
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08051bda:
    adds r0, r4, #0
    movs r1, #0x14
    movs r2, #7
    bl ProjectileSetTrail
    b lbl_08051cbe
    .align 2, 0
lbl_08051be8: .4byte gCurrentClipdataAffectingAction
lbl_08051bec:
    cmp r0, #1
    bne lbl_08051c24
    ldr r0, lbl_08051c10 @ =gCurrentClipdataAffectingAction
    movs r1, #9
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08051c14
lbl_08051c00:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x30
    bl ParticleSet
    b lbl_08051cbe
    .align 2, 0
lbl_08051c10: .4byte gCurrentClipdataAffectingAction
lbl_08051c14:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x30
    bl move_projectile
    b lbl_08051cbe
lbl_08051c24:
    cmp r0, #0
    bne lbl_08051ca8
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051c70
    lsls r0, r0, #2
    ldr r1, lbl_08051c38 @ =lbl_08051c3c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08051c38: .4byte lbl_08051c3c
lbl_08051c3c: @ jump table
    .4byte lbl_08051c70 @ case 0
    .4byte lbl_08051c58 @ case 1
    .4byte lbl_08051c50 @ case 2
    .4byte lbl_08051c68 @ case 3
    .4byte lbl_08051c60 @ case 4
lbl_08051c50:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051c58:
    ldr r0, lbl_08051c5c @ =0x08326f58
    b lbl_08051c72
    .align 2, 0
lbl_08051c5c: .4byte 0x08326f58
lbl_08051c60:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051c68:
    ldr r0, lbl_08051c6c @ =0x08326f70
    b lbl_08051c72
    .align 2, 0
lbl_08051c6c: .4byte 0x08326f70
lbl_08051c70:
    ldr r0, lbl_08051ca0 @ =0x08326f40
lbl_08051c72:
    str r0, [r4, #4]
    adds r0, r4, #0
    bl decrement_missile_counter
    movs r0, #0
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    ldr r1, lbl_08051ca4 @ =0x0000fff8
    strh r1, [r4, #0x14]
    movs r0, #8
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #9
    movs r2, #0x30
    bl check_projectile_hit_block
    b lbl_08051cbe
    .align 2, 0
lbl_08051ca0: .4byte 0x08326f40
lbl_08051ca4: .4byte 0x0000fff8
lbl_08051ca8:
    ldrb r1, [r4]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08051cb8
    adds r0, r4, #0
    bl decrement_missile_counter
lbl_08051cb8:
    adds r0, r4, #0
    bl missile_tumble_move
lbl_08051cbe:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start decrement_super_missile_counter
decrement_super_missile_counter: @ 0x08051cc4
    push {lr}
    adds r3, r0, #0
    ldr r1, lbl_08051cf4 @ =gEquipment
    ldrb r0, [r1, #0xa]
    cmp r0, #0
    beq lbl_08051ce4
    subs r0, #1
    strb r0, [r1, #0xa]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08051ce4
    ldr r0, lbl_08051cf8 @ =gSamusWeaponInfo
    ldrb r1, [r0, #2]
    movs r2, #2
    eors r1, r2
    strb r1, [r0, #2]
lbl_08051ce4:
    movs r0, #0x40
    strb r0, [r3, #0x12]
    ldrb r1, [r3]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r3]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051cf4: .4byte gEquipment
lbl_08051cf8: .4byte gSamusWeaponInfo

    thumb_func_start ProjectileProcessSuperMissile
ProjectileProcessSuperMissile: @ 0x08051cfc
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #2
    bne lbl_08051d3c
    ldr r0, lbl_08051d38 @ =gCurrentClipdataAffectingAction
    movs r1, #0xa
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    bne lbl_08051d50
    ldrb r1, [r4, #0x13]
    adds r1, #0xc
    adds r0, r4, #0
    bl move_projectile
    ldrb r0, [r4, #0x13]
    cmp r0, #0xf
    bhi lbl_08051d2a
    adds r0, #1
    strb r0, [r4, #0x13]
lbl_08051d2a:
    adds r0, r4, #0
    movs r1, #0x15
    movs r2, #3
    bl ProjectileSetTrail
    b lbl_08051e0e
    .align 2, 0
lbl_08051d38: .4byte gCurrentClipdataAffectingAction
lbl_08051d3c:
    cmp r0, #1
    bne lbl_08051d74
    ldr r0, lbl_08051d60 @ =gCurrentClipdataAffectingAction
    movs r1, #0xa
    strb r1, [r0]
    adds r0, r4, #0
    bl sub_0804fa3c
    cmp r0, #0
    beq lbl_08051d64
lbl_08051d50:
    movs r0, #0
    strb r0, [r4]
    ldrh r0, [r4, #8]
    ldrh r1, [r4, #0xa]
    movs r2, #0x31
    bl ParticleSet
    b lbl_08051e0e
    .align 2, 0
lbl_08051d60: .4byte gCurrentClipdataAffectingAction
lbl_08051d64:
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0x30
    bl move_projectile
    b lbl_08051e0e
lbl_08051d74:
    cmp r0, #0
    bne lbl_08051df8
    ldrb r0, [r4, #0x10]
    cmp r0, #4
    bhi lbl_08051dc0
    lsls r0, r0, #2
    ldr r1, lbl_08051d88 @ =lbl_08051d8c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08051d88: .4byte lbl_08051d8c
lbl_08051d8c: @ jump table
    .4byte lbl_08051dc0 @ case 0
    .4byte lbl_08051da8 @ case 1
    .4byte lbl_08051da0 @ case 2
    .4byte lbl_08051db8 @ case 3
    .4byte lbl_08051db0 @ case 4
lbl_08051da0:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051da8:
    ldr r0, lbl_08051dac @ =0x08326fa0
    b lbl_08051dc2
    .align 2, 0
lbl_08051dac: .4byte 0x08326fa0
lbl_08051db0:
    ldrb r1, [r4]
    movs r0, #0x20
    orrs r0, r1
    strb r0, [r4]
lbl_08051db8:
    ldr r0, lbl_08051dbc @ =0x08326fb8
    b lbl_08051dc2
    .align 2, 0
lbl_08051dbc: .4byte 0x08326fb8
lbl_08051dc0:
    ldr r0, lbl_08051df0 @ =0x08326f88
lbl_08051dc2:
    str r0, [r4, #4]
    adds r0, r4, #0
    bl decrement_super_missile_counter
    movs r0, #0
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    ldr r1, lbl_08051df4 @ =0x0000fff4
    strh r1, [r4, #0x14]
    movs r0, #0xc
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    adds r0, r4, #0
    movs r1, #0xa
    movs r2, #0x31
    bl check_projectile_hit_block
    b lbl_08051e0e
    .align 2, 0
lbl_08051df0: .4byte 0x08326f88
lbl_08051df4: .4byte 0x0000fff4
lbl_08051df8:
    ldrb r1, [r4]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08051e08
    adds r0, r4, #0
    bl decrement_super_missile_counter
lbl_08051e08:
    adds r0, r4, #0
    bl missile_tumble_move
lbl_08051e0e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start morph_ball_launcher_launch_samus
morph_ball_launcher_launch_samus: @ 0x08051e14
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x10
    adds r5, r0, #0
    ldr r7, lbl_08051ec4 @ =gSamusData
    ldrh r1, [r7, #0x14]
    ldrh r3, [r7, #0x12]
    ldr r4, lbl_08051ec8 @ =gSamusPhysics
    adds r0, r4, #0
    adds r0, #0x70
    ldrh r0, [r0]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r2, r4, #0
    adds r2, #0x74
    ldrh r2, [r2]
    adds r1, r1, r2
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r2, r4, #0
    adds r2, #0x6e
    ldrh r2, [r2]
    adds r2, r3, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r4, #0x72
    ldrh r4, [r4]
    adds r3, r3, r4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldrh r4, [r5, #8]
    mov r8, r4
    ldrh r4, [r5, #0xa]
    mov sb, r4
    ldrh r6, [r5, #0x14]
    add r6, r8
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    ldrh r4, [r5, #0x16]
    add r8, r4
    mov r4, r8
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    mov r8, r4
    ldrh r4, [r5, #0x18]
    add r4, sb
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldrh r5, [r5, #0x1a]
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
    beq lbl_08051eb4
    ldrb r0, [r7, #6]
    cmp r0, #0
    bne lbl_08051eb4
    ldrb r0, [r7]
    cmp r0, #0x12
    bgt lbl_08051eb4
    cmp r0, #0x11
    blt lbl_08051eb4
    movs r0, #0xf0
    strb r0, [r7, #4]
    movs r0, #0x25
    bl SamusSetPose
lbl_08051eb4:
    add sp, #0x10
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08051ec4: .4byte gSamusData
lbl_08051ec8: .4byte gSamusPhysics

    thumb_func_start check_samus_bomb_bounce
check_samus_bomb_bounce: @ 0x08051ecc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    mov r8, r0
    ldr r0, lbl_08051fc4 @ =gSamusData
    ldrh r4, [r0, #0x14]
    str r4, [sp, #0x10]
    ldrh r5, [r0, #0x12]
    str r5, [sp, #0x14]
    adds r0, r4, #0
    adds r0, #0x20
    adds r1, r5, #0
    bl ClipdataProcess
    movs r6, #0x80
    lsls r6, r6, #0x11
    ands r0, r6
    cmp r0, #0
    beq lbl_08051f08
    adds r0, r4, #0
    subs r0, #0x60
    adds r1, r5, #0
    bl ClipdataProcess
    ands r0, r6
    cmp r0, #0
    bne lbl_08051fe8
lbl_08051f08:
    ldr r0, lbl_08051fc8 @ =gPreviousXPosition
    ldrh r0, [r0]
    str r0, [sp, #0x18]
    ldr r3, lbl_08051fcc @ =gSamusPhysics
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    ldr r1, [sp, #0x10]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r3, #0
    adds r1, #0x74
    ldrh r1, [r1]
    ldr r2, [sp, #0x10]
    adds r1, r2, r1
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r2, r3, #0
    adds r2, #0x6e
    ldrh r2, [r2]
    adds r2, r5, r2
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r3, #0x72
    ldrh r3, [r3]
    adds r3, r5, r3
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    mov r4, r8
    ldrh r4, [r4, #8]
    mov sl, r4
    mov r6, r8
    ldrh r6, [r6, #0xa]
    mov sb, r6
    mov r4, r8
    ldrh r6, [r4, #0x14]
    add r6, sl
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    mov ip, r6
    ldrh r5, [r4, #0x16]
    add r5, sl
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    ldrh r4, [r4, #0x18]
    add r4, sb
    lsls r4, r4, #0x10
    lsrs r7, r4, #0x10
    mov r6, r8
    ldrh r4, [r6, #0x1a]
    add r4, sb
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    mov r6, ip
    str r6, [sp]
    str r5, [sp, #4]
    str r7, [sp, #8]
    str r4, [sp, #0xc]
    bl SpriteUtilCheckObjectsTouching
    cmp r0, #0
    beq lbl_08051fe8
    subs r0, r4, r7
    lsrs r1, r0, #0x1f
    adds r0, r0, r1
    asrs r0, r0, #1
    adds r0, r7, r0
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r1, lbl_08051fc4 @ =gSamusData
    ldrb r0, [r1, #6]
    cmp r0, #0
    bne lbl_08051fe8
    ldr r0, [sp, #0x10]
    subs r0, #0x20
    movs r1, #0
    cmp r0, sl
    ble lbl_08051fa8
    movs r1, #0x80
lbl_08051fa8:
    mov r0, sb
    adds r0, #5
    ldr r2, [sp, #0x14]
    cmp r2, r0
    bge lbl_08051fd0
    subs r0, #0xa
    cmp r2, r0
    ble lbl_08051fd0
    adds r0, r1, #0
    adds r0, #0xb
    bl samus_bombjump
    b lbl_08051fe8
    .align 2, 0
lbl_08051fc4: .4byte gSamusData
lbl_08051fc8: .4byte gPreviousXPosition
lbl_08051fcc: .4byte gSamusPhysics
lbl_08051fd0:
    ldr r6, [sp, #0x18]
    cmp r4, r6
    blo lbl_08051fe0
    adds r0, r1, #0
    adds r0, #0xc
    bl samus_bombjump
    b lbl_08051fe8
lbl_08051fe0:
    adds r0, r1, #0
    adds r0, #0xa
    bl samus_bombjump
lbl_08051fe8:
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ProjectileProcessBomb
ProjectileProcessBomb: @ 0x08051ff8
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #7
    bls lbl_08052004
    b lbl_080521ea
lbl_08052004:
    lsls r0, r0, #2
    ldr r1, lbl_08052010 @ =lbl_08052014
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08052010: .4byte lbl_08052014
lbl_08052014: @ jump table
    .4byte lbl_08052034 @ case 0
    .4byte lbl_0805218c @ case 1
    .4byte lbl_080521b4 @ case 2
    .4byte lbl_08052078 @ case 3
    .4byte lbl_0805217c @ case 4
    .4byte lbl_0805218c @ case 5
    .4byte lbl_080521b4 @ case 6
    .4byte lbl_080521e0 @ case 7
lbl_08052034:
    ldr r0, lbl_08052070 @ =0x08326d40
    str r0, [r4, #4]
    movs r0, #0
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    movs r0, #0x20
    strb r0, [r4, #0x12]
    ldr r0, lbl_08052074 @ =0x0000ffc4
    strh r0, [r4, #0x14]
    movs r1, #0x30
    strh r1, [r4, #0x16]
    adds r0, #0xc
    strh r0, [r4, #0x18]
    strh r1, [r4, #0x1a]
    ldrb r1, [r4]
    movs r0, #0xbb
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r4]
    movs r0, #0x10
    strb r0, [r4, #0x13]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    movs r0, #0xfe
    bl SoundPlay
    b lbl_080521ea
    .align 2, 0
lbl_08052070: .4byte 0x08326d40
lbl_08052074: .4byte 0x0000ffc4
lbl_08052078:
    ldrb r0, [r4, #0x13]
    subs r1, r0, #1
    strb r1, [r4, #0x13]
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08052088
    b lbl_080521e8
lbl_08052088:
    lsls r0, r1, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0xf
    bne lbl_080520b4
    ldr r1, lbl_080520b0 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    subs r0, #8
    ldrh r1, [r4, #0xa]
    bl ClipdataProcess
    adds r0, r4, #0
    bl check_samus_bomb_bounce
    ldrb r1, [r4]
    movs r0, #0xef
    ands r0, r1
    b lbl_080521e8
    .align 2, 0
lbl_080520b0: .4byte gCurrentClipdataAffectingAction
lbl_080520b4:
    cmp r1, #0xe
    bne lbl_080520c8
    ldr r1, lbl_080520c4 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    adds r0, #0x38
    b lbl_08052136
    .align 2, 0
lbl_080520c4: .4byte gCurrentClipdataAffectingAction
lbl_080520c8:
    cmp r1, #0xd
    bne lbl_080520e4
    ldr r1, lbl_080520e0 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    subs r0, #8
    ldrh r1, [r4, #0xa]
    adds r1, #0x30
    bl ClipdataProcess
    b lbl_080521ea
    .align 2, 0
lbl_080520e0: .4byte gCurrentClipdataAffectingAction
lbl_080520e4:
    cmp r1, #0xc
    bne lbl_08052100
    ldr r1, lbl_080520fc @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    subs r0, #8
    ldrh r1, [r4, #0xa]
    subs r1, #0x30
    bl ClipdataProcess
    b lbl_080521ea
    .align 2, 0
lbl_080520fc: .4byte gCurrentClipdataAffectingAction
lbl_08052100:
    cmp r1, #0xb
    bne lbl_08052114
    ldr r1, lbl_08052110 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    adds r0, #0x38
    b lbl_08052150
    .align 2, 0
lbl_08052110: .4byte gCurrentClipdataAffectingAction
lbl_08052114:
    cmp r1, #0xa
    bne lbl_08052128
    ldr r1, lbl_08052124 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    adds r0, #0x38
    b lbl_0805216e
    .align 2, 0
lbl_08052124: .4byte gCurrentClipdataAffectingAction
lbl_08052128:
    cmp r1, #9
    bne lbl_08052144
    ldr r1, lbl_08052140 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    subs r0, #0x48
lbl_08052136:
    ldrh r1, [r4, #0xa]
    bl ClipdataProcess
    b lbl_080521ea
    .align 2, 0
lbl_08052140: .4byte gCurrentClipdataAffectingAction
lbl_08052144:
    cmp r1, #8
    bne lbl_08052160
    ldr r0, lbl_0805215c @ =gCurrentClipdataAffectingAction
    strb r1, [r0]
    ldrh r0, [r4, #8]
    subs r0, #0x48
lbl_08052150:
    ldrh r1, [r4, #0xa]
    adds r1, #0x24
    bl ClipdataProcess
    b lbl_080521ea
    .align 2, 0
lbl_0805215c: .4byte gCurrentClipdataAffectingAction
lbl_08052160:
    cmp r1, #7
    bne lbl_080521ea
    ldr r1, lbl_08052178 @ =gCurrentClipdataAffectingAction
    movs r0, #8
    strb r0, [r1]
    ldrh r0, [r4, #8]
    subs r0, #0x48
lbl_0805216e:
    ldrh r1, [r4, #0xa]
    subs r1, #0x24
    bl ClipdataProcess
    b lbl_080521ea
    .align 2, 0
lbl_08052178: .4byte gCurrentClipdataAffectingAction
lbl_0805217c:
    ldr r0, lbl_08052188 @ =0x08326d40
    str r0, [r4, #4]
    movs r0, #0
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    b lbl_080521a2
    .align 2, 0
lbl_08052188: .4byte 0x08326d40
lbl_0805218c:
    ldrb r0, [r4, #0x13]
    subs r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_080521ea
    ldr r0, lbl_080521b0 @ =0x08326d68
    str r0, [r4, #4]
    strb r1, [r4, #0xe]
    strh r1, [r4, #0xc]
lbl_080521a2:
    movs r0, #0x10
    strb r0, [r4, #0x13]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    b lbl_080521ea
    .align 2, 0
lbl_080521b0: .4byte 0x08326d68
lbl_080521b4:
    ldrb r0, [r4, #0x13]
    subs r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080521ea
    movs r0, #0x10
    strb r0, [r4, #0x13]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    ldrb r0, [r4]
    movs r1, #0x14
    orrs r0, r1
    strb r0, [r4]
    ldrh r0, [r4, #8]
    subs r0, #0x10
    ldrh r1, [r4, #0xa]
    movs r2, #0x13
    bl ParticleSet
    b lbl_080521ea
lbl_080521e0:
    adds r0, r4, #0
    bl morph_ball_launcher_launch_samus
    movs r0, #0
lbl_080521e8:
    strb r0, [r4]
lbl_080521ea:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start rocess_projectile_empty
rocess_projectile_empty: @ 0x080521f0
    bx lr
    .align 2, 0

    thumb_func_start ProjectileProcessPowerBomb
ProjectileProcessPowerBomb: @ 0x080521f4
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0x11]
    cmp r0, #1
    beq lbl_080522b0
    cmp r0, #1
    bgt lbl_08052208
    cmp r0, #0
    beq lbl_0805220e
    b lbl_080522fc
lbl_08052208:
    cmp r0, #2
    beq lbl_080522d8
    b lbl_080522fc
lbl_0805220e:
    ldr r1, lbl_08052298 @ =gEquipment
    ldrb r0, [r1, #0xb]
    cmp r0, #0
    beq lbl_0805222a
    subs r0, #1
    strb r0, [r1, #0xb]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805222a
    ldr r0, lbl_0805229c @ =gSamusWeaponInfo
    ldrb r1, [r0, #2]
    movs r2, #4
    eors r1, r2
    strb r1, [r0, #2]
lbl_0805222a:
    ldr r0, lbl_080522a0 @ =0x08326d90
    str r0, [r4, #4]
    movs r0, #0
    strb r0, [r4, #0xe]
    strh r0, [r4, #0xc]
    movs r0, #0x20
    strb r0, [r4, #0x12]
    ldr r1, lbl_080522a4 @ =0x0000fff0
    strh r1, [r4, #0x14]
    movs r0, #0x10
    strh r0, [r4, #0x16]
    strh r1, [r4, #0x18]
    strh r0, [r4, #0x1a]
    ldrb r1, [r4]
    movs r0, #0xbb
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r4]
    movs r0, #0x36
    strb r0, [r4, #0x13]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    ldr r3, lbl_080522a8 @ =gSpriteData
    movs r1, #0xa8
    lsls r1, r1, #3
    adds r0, r3, r1
    cmp r3, r0
    bhs lbl_08052288
    movs r6, #1
    movs r5, #0x7f
    adds r4, r0, #0
lbl_0805226c:
    ldrh r1, [r3]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08052282
    adds r2, r3, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    adds r0, r5, #0
    ands r0, r1
    strb r0, [r2]
lbl_08052282:
    adds r3, #0x38
    cmp r3, r4
    blo lbl_0805226c
lbl_08052288:
    movs r0, #0x80
    lsls r0, r0, #1
    bl SoundPlay
    ldr r1, lbl_080522ac @ =gCurrentPowerBomb
    movs r0, #1
    strb r0, [r1, #0x10]
    b lbl_080522fc
    .align 2, 0
lbl_08052298: .4byte gEquipment
lbl_0805229c: .4byte gSamusWeaponInfo
lbl_080522a0: .4byte 0x08326d90
lbl_080522a4: .4byte 0x0000fff0
lbl_080522a8: .4byte gSpriteData
lbl_080522ac: .4byte gCurrentPowerBomb
lbl_080522b0:
    ldrb r0, [r4, #0x13]
    subs r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_080522fc
    ldr r0, lbl_080522d4 @ =0x08326db0
    str r0, [r4, #4]
    strb r1, [r4, #0xe]
    strh r1, [r4, #0xc]
    movs r0, #0x28
    strb r0, [r4, #0x13]
    ldrb r0, [r4, #0x11]
    adds r0, #1
    strb r0, [r4, #0x11]
    b lbl_080522fc
    .align 2, 0
lbl_080522d4: .4byte 0x08326db0
lbl_080522d8:
    ldr r0, lbl_08052304 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_080522fc
    ldrb r0, [r4, #0x13]
    subs r0, #1
    strb r0, [r4, #0x13]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_080522fc
    ldrh r0, [r4, #0xa]
    ldrh r1, [r4, #8]
    movs r2, #0
    bl PowerBombExplosionStart
    strb r5, [r4]
lbl_080522fc:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08052304: .4byte gGameModeSub1
