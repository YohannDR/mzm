    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start sub_0803d860
sub_0803d860: @ 0x0803d860
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r2, lbl_0803d884 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    mov ip, r2
    cmp r0, #0
    beq lbl_0803d888
    mov r0, ip
    adds r0, #0x2a
    ldrb r0, [r0]
    adds r0, #0x80
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    b lbl_0803d88e
    .align 2, 0
lbl_0803d884: .4byte 0x03000738
lbl_0803d888:
    mov r0, ip
    adds r0, #0x2a
    ldrb r5, [r0]
lbl_0803d88e:
    ldr r0, lbl_0803d8d4 @ =0x0300070c
    ldrb r1, [r0, #0xf]
    movs r6, #0x80
    lsls r6, r6, #1
    mov r8, r0
    cmp r1, #1
    bne lbl_0803d89e
    adds r6, #0x80
lbl_0803d89e:
    mov r4, ip
    adds r4, #0x2f
    ldrb r1, [r4]
    ldr r3, lbl_0803d8d8 @ =0x082fab90
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r7, #0
    ldrsh r2, [r0, r7]
    ldr r0, lbl_0803d8dc @ =0x00007fff
    cmp r2, r0
    bne lbl_0803d8ba
    movs r0, #0
    ldrsh r2, [r3, r0]
    movs r1, #0
lbl_0803d8ba:
    adds r0, r1, #1
    strb r0, [r4]
    mov r1, ip
    ldrh r0, [r1, #0x14]
    cmp r0, #0
    beq lbl_0803d8e0
    lsls r0, r2, #2
    ldrb r1, [r1, #0x1e]
    lsrs r1, r1, #2
    adds r1, #1
    muls r0, r1, r0
    b lbl_0803d8e2
    .align 2, 0
lbl_0803d8d4: .4byte 0x0300070c
lbl_0803d8d8: .4byte 0x082fab90
lbl_0803d8dc: .4byte 0x00007fff
lbl_0803d8e0:
    lsls r0, r2, #4
lbl_0803d8e2:
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    ldr r1, lbl_0803d90c @ =0x0808c71c
    lsls r0, r5, #1
    adds r0, r0, r1
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r2, r0, #0
    cmp r2, #0
    bge lbl_0803d910
    rsbs r0, r2, #0
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    mov r3, r8
    ldrh r0, [r3, #6]
    subs r0, r0, r2
    mov r7, ip
    strh r0, [r7, #2]
    b lbl_0803d920
    .align 2, 0
lbl_0803d90c: .4byte 0x0808c71c
lbl_0803d910:
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r0, r0, #0x10
    mov r2, r8
    ldrh r2, [r2, #6]
    adds r0, r0, r2
    mov r3, ip
    strh r0, [r3, #2]
lbl_0803d920:
    adds r0, r5, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r7, #0
    ldrsh r2, [r0, r7]
    mov r0, r8
    movs r1, #8
    ldrsh r3, [r0, r1]
    mov r7, ip
    ldrh r1, [r7]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803d944
    adds r0, r3, r6
    b lbl_0803d946
lbl_0803d944:
    subs r0, r3, r6
lbl_0803d946:
    lsls r0, r0, #0x10
    asrs r3, r0, #0x10
    cmp r2, #0
    bge lbl_0803d95e
    rsbs r0, r2, #0
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    subs r0, r3, r2
    mov r1, ip
    strh r0, [r1, #4]
    b lbl_0803d96c
lbl_0803d95e:
    adds r0, r2, #0
    muls r0, r4, r0
    lsls r0, r0, #8
    asrs r2, r0, #0x10
    adds r0, r3, r2
    mov r2, ip
    strh r0, [r2, #4]
lbl_0803d96c:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AcidWormRandomXMovement
AcidWormRandomXMovement: @ 0x0803d978
    push {r4, r5, lr}
    ldr r3, lbl_0803d9ac @ =0x03000738
    movs r0, #0x2e
    adds r0, r0, r3
    mov ip, r0
    ldrb r2, [r0]
    ldr r4, lbl_0803d9b0 @ =0x082fabd2
    lsls r0, r2, #1
    adds r0, r0, r4
    movs r5, #0
    ldrsh r1, [r0, r5]
    ldr r0, lbl_0803d9b4 @ =0x00007fff
    cmp r1, r0
    bne lbl_0803d99a
    movs r0, #0x28
    ldrsh r1, [r4, r0]
    movs r2, #0x14
lbl_0803d99a:
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
lbl_0803d9ac: .4byte 0x03000738
lbl_0803d9b0: .4byte 0x082fabd2
lbl_0803d9b4: .4byte 0x00007fff

    thumb_func_start AcidWormChangeTwoGroundCCAA
AcidWormChangeTwoGroundCCAA: @ 0x0803d9b8
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    adds r6, r0, #0
    adds r4, r1, #0
    adds r5, r2, #0
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    ldr r0, lbl_0803d9fc @ =0x03000079
    mov r8, r0
    strb r6, [r0]
    adds r4, #0x40
    adds r1, r5, #0
    subs r1, #0x20
    adds r0, r4, #0
    bl ClipdataProcess
    mov r0, r8
    strb r6, [r0]
    adds r5, #0x20
    adds r0, r4, #0
    adds r1, r5, #0
    bl ClipdataProcess
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803d9fc: .4byte 0x03000079

    thumb_func_start AcidWormChangeBigBlockDownCCAA
AcidWormChangeBigBlockDownCCAA: @ 0x0803da00
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r0, lbl_0803da48 @ =0x03000738
    ldrh r6, [r0, #6]
    ldrh r7, [r0, #8]
    ldr r5, lbl_0803da4c @ =0x03000079
    strb r4, [r5]
    adds r1, r7, #0
    subs r1, #0x20
    adds r0, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    adds r1, r7, #0
    adds r1, #0x20
    adds r0, r6, #0
    bl ClipdataProcess
    movs r0, #3
    movs r1, #0x1c
    bl EventFunction
    cmp r0, #0
    bne lbl_0803da42
    adds r0, r6, #0
    subs r0, #0x40
    adds r1, r7, #0
    subs r1, #0x10
    movs r2, #0x22
    bl ParticleSet
lbl_0803da42:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803da48: .4byte 0x03000738
lbl_0803da4c: .4byte 0x03000079

    thumb_func_start AcidWormChangeBigBlockMiddleCCAA
AcidWormChangeBigBlockMiddleCCAA: @ 0x0803da50
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r1, lbl_0803daa0 @ =0x03000738
    ldrh r0, [r1, #6]
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrh r7, [r1, #8]
    ldr r5, lbl_0803daa4 @ =0x03000079
    strb r4, [r5]
    adds r1, r7, #0
    subs r1, #0x20
    adds r0, r6, #0
    bl ClipdataProcess
    strb r4, [r5]
    adds r1, r7, #0
    adds r1, #0x20
    adds r0, r6, #0
    bl ClipdataProcess
    movs r0, #3
    movs r1, #0x1c
    bl EventFunction
    cmp r0, #0
    bne lbl_0803da98
    adds r0, r6, #0
    subs r0, #0x40
    adds r1, r7, #0
    adds r1, #0x10
    movs r2, #0x22
    bl ParticleSet
lbl_0803da98:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803daa0: .4byte 0x03000738
lbl_0803daa4: .4byte 0x03000079

    thumb_func_start AcidWormChangeBigBlockTopCCAA
AcidWormChangeBigBlockTopCCAA: @ 0x0803daa8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r1, lbl_0803db84 @ =0x03000738
    ldrh r0, [r1, #6]
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldrh r7, [r1, #8]
    ldr r5, lbl_0803db88 @ =0x03000079
    strb r4, [r5]
    movs r0, #0x20
    rsbs r0, r0, #0
    adds r0, r0, r7
    mov r8, r0
    adds r0, r6, #0
    mov r1, r8
    bl ClipdataProcess
    strb r4, [r5]
    adds r5, r7, #0
    adds r5, #0x20
    adds r0, r6, #0
    adds r1, r5, #0
    bl ClipdataProcess
    movs r0, #3
    movs r1, #0x1c
    bl EventFunction
    cmp r0, #0
    bne lbl_0803db78
    adds r0, r6, #0
    subs r0, #0x40
    adds r1, r7, #0
    subs r1, #8
    movs r2, #0x22
    bl ParticleSet
    adds r4, r6, #0
    subs r4, #0x80
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    adds r2, r4, #0
    subs r2, #0x42
    movs r0, #0
    movs r1, #0x11
    mov r3, r8
    bl SpriteDebrisInit
    adds r3, r7, #0
    subs r3, #0x34
    movs r0, #0
    movs r1, #0x12
    adds r2, r4, #0
    bl SpriteDebrisInit
    adds r2, r4, #0
    subs r2, #0x5c
    adds r3, r7, #0
    subs r3, #0x3e
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    movs r0, #0
    movs r1, #4
    adds r2, r4, #0
    mov r3, r8
    bl SpriteDebrisInit
    adds r2, r4, #0
    subs r2, #0x24
    adds r3, r7, #0
    adds r3, #0x52
    movs r0, #0
    movs r1, #0x11
    bl SpriteDebrisInit
    adds r2, r4, #0
    subs r2, #0x4c
    movs r0, #0
    movs r1, #0x12
    adds r3, r5, #0
    bl SpriteDebrisInit
    adds r3, r7, #0
    adds r3, #0x48
    movs r0, #0
    movs r1, #0x13
    adds r2, r4, #0
    bl SpriteDebrisInit
    subs r4, #0x6c
    adds r3, r7, #0
    adds r3, #0x34
    movs r0, #0
    movs r1, #4
    adds r2, r4, #0
    bl SpriteDebrisInit
lbl_0803db78:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803db84: .4byte 0x03000738
lbl_0803db88: .4byte 0x03000079

    thumb_func_start AcidWormPlaySound
AcidWormPlaySound: @ 0x0803db8c
    push {lr}
    ldr r0, lbl_0803dba0 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    bne lbl_0803dba4
    movs r0, #0xd8
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803dbac
    .align 2, 0
lbl_0803dba0: .4byte 0x0300070c
lbl_0803dba4:
    movs r0, #0xd6
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803dbac:
    pop {r0}
    bx r0

    thumb_func_start AcidWormCollidingWithSamusWhenExtending
AcidWormCollidingWithSamusWhenExtending: @ 0x0803dbb0
    push {lr}
    ldr r3, lbl_0803dbc4 @ =0x03000738
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_0803dbc8
    movs r0, #0
    b lbl_0803dbe8
    .align 2, 0
lbl_0803dbc4: .4byte 0x03000738
lbl_0803dbc8:
    ldr r0, lbl_0803dbec @ =0x0000f7ff
    ands r0, r1
    movs r1, #0
    movs r2, #0
    strh r0, [r3]
    ldr r0, lbl_0803dbf0 @ =0x082fc1c8
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r2, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x27
    strb r0, [r1]
    bl AcidWormPlaySound
    movs r0, #1
lbl_0803dbe8:
    pop {r1}
    bx r1
    .align 2, 0
lbl_0803dbec: .4byte 0x0000f7ff
lbl_0803dbf0: .4byte 0x082fc1c8

    thumb_func_start AcidWormInit
AcidWormInit: @ 0x0803dbf4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    ldr r4, lbl_0803dcdc @ =0x03000738
    ldr r0, lbl_0803dce0 @ =0x0000ffd0
    strh r0, [r4, #0xa]
    movs r1, #0x38
    strh r1, [r4, #0xc]
    subs r0, #8
    strh r0, [r4, #0xe]
    strh r1, [r4, #0x10]
    adds r0, r4, #0
    adds r0, #0x27
    movs r2, #0x1a
    strb r2, [r0]
    adds r1, r4, #0
    adds r1, #0x28
    movs r0, #0x10
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x29
    strb r2, [r0]
    ldr r0, lbl_0803dce4 @ =0x082fc110
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    movs r1, #0
    strh r1, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #0x16
    strb r0, [r1]
    ldr r2, lbl_0803dce8 @ =0x082b0d68
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    adds r2, r4, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r0, r4, #0
    adds r0, #0x24
    movs r2, #1
    strb r2, [r0]
    ldrh r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x2f
    movs r1, #0
    strb r1, [r0]
    adds r1, r4, #0
    adds r1, #0x2e
    movs r0, #0x14
    strb r0, [r1]
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    adds r0, #0x20
    strh r0, [r4, #4]
    ldrh r6, [r4, #2]
    mov r8, r6
    ldrh r5, [r4, #4]
    mov sb, r5
    ldr r2, lbl_0803dcec @ =0x0300070c
    mov sl, r2
    strh r6, [r2, #6]
    strh r5, [r2, #8]
    strh r6, [r4, #6]
    strh r5, [r4, #8]
    movs r0, #0
    strb r0, [r2, #0xf]
    strb r0, [r2, #0xe]
    movs r0, #3
    movs r1, #0x1c
    bl EventFunction
    adds r7, r0, #0
    cmp r7, #0
    beq lbl_0803dcf4
    ldr r1, lbl_0803dcf0 @ =0x0300006e
    movs r2, #0x98
    lsls r2, r2, #2
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #1
    bl AcidWormChangeBigBlockDownCCAA
    movs r0, #1
    bl AcidWormChangeBigBlockMiddleCCAA
    movs r0, #1
    bl AcidWormChangeBigBlockTopCCAA
    movs r0, #1
    adds r1, r6, #0
    adds r2, r5, #0
    bl AcidWormChangeTwoGroundCCAA
    movs r0, #0
    strh r0, [r4]
    b lbl_0803de02
    .align 2, 0
lbl_0803dcdc: .4byte 0x03000738
lbl_0803dce0: .4byte 0x0000ffd0
lbl_0803dce4: .4byte 0x082fc110
lbl_0803dce8: .4byte 0x082b0d68
lbl_0803dcec: .4byte 0x0300070c
lbl_0803dcf0: .4byte 0x0300006e
lbl_0803dcf4:
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    bne lbl_0803dd04
    strh r7, [r4]
    b lbl_0803de02
lbl_0803dd04:
    ldr r0, lbl_0803de14 @ =0x0300007b
    movs r1, #1
    strb r1, [r0]
    ldrh r0, [r4, #6]
    subs r0, #0x80
    mov r2, sl
    strh r0, [r2, #0xa]
    movs r0, #0
    strb r0, [r4, #0x1e]
    ldrb r5, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r4, [r0]
    mov r0, r8
    adds r0, #0x40
    str r0, [sp]
    mov r1, sb
    str r1, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #1
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, r8
    adds r0, #0x80
    str r0, [sp]
    mov r2, sb
    str r2, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #2
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r0, r8
    adds r0, #0xc0
    str r0, [sp]
    mov r0, sb
    str r0, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #3
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0x80
    lsls r0, r0, #1
    add r0, r8
    str r0, [sp]
    mov r1, sb
    str r1, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #4
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0xa0
    lsls r0, r0, #1
    add r0, r8
    str r0, [sp]
    mov r2, sb
    str r2, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #5
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0xc0
    lsls r0, r0, #1
    add r0, r8
    str r0, [sp]
    mov r0, sb
    str r0, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #6
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0xe0
    lsls r0, r0, #1
    add r0, r8
    str r0, [sp]
    mov r1, sb
    str r1, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #7
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0x80
    lsls r0, r0, #2
    add r0, r8
    str r0, [sp]
    mov r2, sb
    str r2, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #8
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    movs r0, #0x90
    lsls r0, r0, #2
    add r0, r8
    str r0, [sp]
    mov r0, sb
    str r0, [sp, #4]
    str r7, [sp, #8]
    movs r0, #0x25
    movs r1, #9
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
lbl_0803de02:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803de14: .4byte 0x0300007b

    thumb_func_start acid_worm_check_SamusOnZipline
AcidWormCheckSamusOnZipline: @ 0x0803de18
    push {lr}
    bl SpriteUtilCheckOnZipline
    cmp r0, #0
    beq lbl_0803de30
    ldr r0, lbl_0803de34 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x42
    strb r1, [r0]
    movs r0, #0x12
    bl FadeMusic
lbl_0803de30:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803de34: .4byte 0x03000738

    thumb_func_start AcidWormSpawnStart
AcidWormSpawnStart: @ 0x0803de38
    push {lr}
    bl SpriteUtilCheckOnZipline
    cmp r0, #0
    beq lbl_0803dea4
    ldr r0, lbl_0803dea8 @ =0x030013d4
    ldrh r2, [r0, #0x12]
    ldr r3, lbl_0803deac @ =0x03000738
    ldrh r1, [r3, #8]
    adds r0, r1, #0
    subs r0, #0x8c
    cmp r2, r0
    ble lbl_0803dea4
    adds r0, r1, #0
    adds r0, #0x8c
    cmp r2, r0
    bge lbl_0803dea4
    ldrh r1, [r3]
    ldr r0, lbl_0803deb0 @ =0x00007fff
    ands r0, r1
    movs r2, #0
    strh r0, [r3]
    ldr r1, lbl_0803deb4 @ =0x0300070c
    movs r0, #1
    strb r0, [r1, #0xe]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r2, [r0]
    movs r0, #1
    bl AcidWormChangeBigBlockDownCCAA
    movs r0, #0x3c
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0x3c
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
    ldr r0, lbl_0803deb8 @ =0x000001a7
    bl SoundPlay
    movs r0, #0xd4
    lsls r0, r0, #1
    bl SoundPlay
    movs r0, #0x3c
    movs r1, #0
    bl PlayMusic
lbl_0803dea4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803dea8: .4byte 0x030013d4
lbl_0803deac: .4byte 0x03000738
lbl_0803deb0: .4byte 0x00007fff
lbl_0803deb4: .4byte 0x0300070c
lbl_0803deb8: .4byte 0x000001a7

    thumb_func_start AcidWormSpawnExtending
AcidWormSpawnExtending: @ 0x0803debc
    push {r4, lr}
    ldr r4, lbl_0803dee8 @ =0x03000738
    ldrh r3, [r4, #2]
    ldrh r0, [r4, #6]
    ldr r1, lbl_0803deec @ =0xfffffe40
    adds r0, r0, r1
    cmp r3, r0
    bge lbl_0803def4
    adds r1, r4, #0
    adds r1, #0x24
    movs r2, #0
    movs r0, #0x45
    strb r0, [r1]
    ldr r0, lbl_0803def0 @ =0x082fc388
    str r0, [r4, #0x18]
    strb r2, [r4, #0x1c]
    strh r2, [r4, #0x16]
    movs r0, #0xd5
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803df46
    .align 2, 0
lbl_0803dee8: .4byte 0x03000738
lbl_0803deec: .4byte 0xfffffe40
lbl_0803def0: .4byte 0x082fc388
lbl_0803def4:
    adds r0, r3, #0
    subs r0, #0x10
    strh r0, [r4, #2]
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r3, #0
    movs r3, #3
    bl SpriteUtilCheckOutOfRoomEffect
    cmp r0, #0
    beq lbl_0803df10
    ldr r0, lbl_0803df34 @ =0x000001bb
    bl SoundPlay
lbl_0803df10:
    ldr r1, lbl_0803df38 @ =0x0300006e
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bne lbl_0803df3c
    movs r0, #1
    bl AcidWormChangeBigBlockMiddleCCAA
    b lbl_0803df46
    .align 2, 0
lbl_0803df34: .4byte 0x000001bb
lbl_0803df38: .4byte 0x0300006e
lbl_0803df3c:
    cmp r0, #8
    bne lbl_0803df46
    movs r0, #1
    bl AcidWormChangeBigBlockTopCCAA
lbl_0803df46:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start AcidWormSpawnStayingOnTop
AcidWormSpawnStayingOnTop: @ 0x0803df4c
    push {lr}
    bl AcidWormRandomXMovement
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803df74
    ldr r1, lbl_0803df78 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x24
    movs r3, #0
    movs r0, #0x47
    strb r0, [r2]
    ldr r0, lbl_0803df7c @ =0x082fc1c8
    str r0, [r1, #0x18]
    strb r3, [r1, #0x1c]
    strh r3, [r1, #0x16]
    ldr r0, lbl_0803df80 @ =0x000001a9
    bl SoundPlay
lbl_0803df74:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803df78: .4byte 0x03000738
lbl_0803df7c: .4byte 0x082fc1c8
lbl_0803df80: .4byte 0x000001a9

    thumb_func_start AcidWormSpawnRetracting
AcidWormSpawnRetracting: @ 0x0803df84
    push {lr}
    bl AcidWormRandomXMovement
    ldr r3, lbl_0803dfbc @ =0x03000738
    ldrh r0, [r3, #2]
    ldrh r1, [r3, #6]
    cmp r0, r1
    blo lbl_0803dfc0
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldrh r1, [r3]
    movs r2, #0
    orrs r0, r1
    strh r0, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r3, #0x12]
    adds r0, r3, #0
    adds r0, #0x2a
    strb r2, [r0]
    adds r1, r3, #0
    adds r1, #0x2c
    movs r0, #0x3c
    strb r0, [r1]
    b lbl_0803dff0
    .align 2, 0
lbl_0803dfbc: .4byte 0x03000738
lbl_0803dfc0:
    ldrh r0, [r3, #2]
    adds r1, r0, #0
    adds r1, #0x10
    strh r1, [r3, #2]
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    movs r3, #3
    bl SpriteUtilCheckInRoomEffect
    cmp r0, #0
    beq lbl_0803dfdc
    ldr r0, lbl_0803dff4 @ =0x000001bb
    bl SoundPlay
lbl_0803dfdc:
    ldr r0, lbl_0803dff8 @ =0x0300006c
    ldr r1, lbl_0803dffc @ =0x0300070c
    ldrh r0, [r0]
    ldrh r1, [r1, #0xa]
    cmp r0, r1
    bls lbl_0803dff0
    ldr r1, lbl_0803e000 @ =0x0300006e
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_0803dff0:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803dff4: .4byte 0x000001bb
lbl_0803dff8: .4byte 0x0300006c
lbl_0803dffc: .4byte 0x0300070c
lbl_0803e000: .4byte 0x0300006e

    thumb_func_start sub_0803e004
sub_0803e004: @ 0x0803e004
    ldr r1, lbl_0803e028 @ =0x03000738
    ldr r0, lbl_0803e02c @ =0x082fc110
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    adds r2, r1, #0
    adds r2, #0x24
    movs r0, #9
    strb r0, [r2]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_0803e028: .4byte 0x03000738
lbl_0803e02c: .4byte 0x082fc110

    thumb_func_start AcidWormIdle
AcidWormIdle: @ 0x0803e030
    push {r4, r5, r6, r7, lr}
    ldr r3, lbl_0803e068 @ =0x0300006c
    ldr r0, lbl_0803e06c @ =0x0300070c
    ldrh r1, [r3]
    adds r6, r0, #0
    ldrh r0, [r6, #0xa]
    cmp r1, r0
    bls lbl_0803e048
    ldr r1, lbl_0803e070 @ =0x0300006e
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_0803e048:
    ldr r7, lbl_0803e074 @ =0x030013d4
    ldrh r2, [r7, #0x14]
    ldr r0, lbl_0803e078 @ =0x03000738
    ldrh r5, [r0, #2]
    adds r4, r0, #0
    ldrh r3, [r3]
    cmp r2, r3
    bhi lbl_0803e05c
    cmp r2, r5
    bls lbl_0803e07c
lbl_0803e05c:
    adds r1, r4, #0
    adds r1, #0x2c
    movs r0, #0x3c
    strb r0, [r1]
    b lbl_0803e0dc
    .align 2, 0
lbl_0803e068: .4byte 0x0300006c
lbl_0803e06c: .4byte 0x0300070c
lbl_0803e070: .4byte 0x0300006e
lbl_0803e074: .4byte 0x030013d4
lbl_0803e078: .4byte 0x03000738
lbl_0803e07c:
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #0
    bne lbl_0803e0dc
    subs r0, r5, r2
    subs r0, #0x51
    cmp r0, #0xee
    bhi lbl_0803e0b4
    ldrh r2, [r7, #0x12]
    ldrh r1, [r4, #8]
    ldr r5, lbl_0803e0b0 @ =0xfffffe40
    adds r0, r1, r5
    cmp r2, r0
    ble lbl_0803e0b4
    movs r5, #0xe0
    lsls r5, r5, #1
    adds r0, r1, r5
    cmp r2, r0
    bge lbl_0803e0b4
    strb r3, [r6, #0xf]
    b lbl_0803e0b8
    .align 2, 0
lbl_0803e0b0: .4byte 0xfffffe40
lbl_0803e0b4:
    movs r0, #1
    strb r0, [r6, #0xf]
lbl_0803e0b8:
    ldr r0, lbl_0803e0e4 @ =0x082fc318
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    bl SpriteUtilMakeSpriteFaceSamusDirection
    ldrh r1, [r4]
    ldr r0, lbl_0803e0e8 @ =0x0000fbff
    ands r0, r1
    strh r0, [r4]
    ldr r0, lbl_0803e0ec @ =0x000001b5
    bl SoundPlay
lbl_0803e0dc:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e0e4: .4byte 0x082fc318
lbl_0803e0e8: .4byte 0x0000fbff
lbl_0803e0ec: .4byte 0x000001b5

    thumb_func_start acid_worm_check_end_warning_anim
acid_worm_check_end_warning_anim: @ 0x0803e0f0
    push {lr}
    bl sub_0803d860
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803e144
    ldr r2, lbl_0803e130 @ =0x03000738
    ldr r0, lbl_0803e134 @ =0x082fc138
    str r0, [r2, #0x18]
    movs r3, #0
    strb r3, [r2, #0x1c]
    strh r3, [r2, #0x16]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
    adds r1, #8
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0803e138 @ =0x0300070c
    ldrh r1, [r0, #0xa]
    ldrh r0, [r2, #6]
    subs r0, #0xc0
    cmp r1, r0
    bne lbl_0803e140
    ldr r1, lbl_0803e13c @ =0x0300006e
    movs r2, #0x40
    rsbs r2, r2, #0
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_0803e144
    .align 2, 0
lbl_0803e130: .4byte 0x03000738
lbl_0803e134: .4byte 0x082fc138
lbl_0803e138: .4byte 0x0300070c
lbl_0803e13c: .4byte 0x0300006e
lbl_0803e140:
    ldr r0, lbl_0803e148 @ =0x0300006e
    strh r3, [r0]
lbl_0803e144:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e148: .4byte 0x0300006e

    thumb_func_start AcidWormExtend
AcidWormExtend: @ 0x0803e14c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r3, lbl_0803e194 @ =0x082b0d68
    ldr r2, lbl_0803e198 @ =0x03000738
    ldrb r1, [r2, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r7, [r0]
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    mov r8, r2
    cmp r0, #0
    beq lbl_0803e1cc
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803e17a
    b lbl_0803e49a
lbl_0803e17a:
    ldr r0, lbl_0803e19c @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    bne lbl_0803e1c0
    ldrh r1, [r2, #0x14]
    lsrs r0, r7, #2
    cmp r1, r0
    bhi lbl_0803e1a4
    ldr r0, lbl_0803e1a0 @ =0x000001af
    bl SoundPlay
    b lbl_0803e49a
    .align 2, 0
lbl_0803e194: .4byte 0x082b0d68
lbl_0803e198: .4byte 0x03000738
lbl_0803e19c: .4byte 0x0300070c
lbl_0803e1a0: .4byte 0x000001af
lbl_0803e1a4:
    lsrs r0, r7, #1
    cmp r1, r0
    bhi lbl_0803e1b4
    movs r0, #0xd7
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803e49a
lbl_0803e1b4:
    ldr r0, lbl_0803e1bc @ =0x000001ad
    bl SoundPlay
    b lbl_0803e49a
    .align 2, 0
lbl_0803e1bc: .4byte 0x000001ad
lbl_0803e1c0:
    ldr r0, lbl_0803e1c8 @ =0x000001ab
    bl SoundPlay
    b lbl_0803e49a
    .align 2, 0
lbl_0803e1c8: .4byte 0x000001ab
lbl_0803e1cc:
    ldr r1, lbl_0803e1ec @ =0x0300006e
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r0, lbl_0803e1f0 @ =0x0300070c
    ldrb r1, [r0, #0xf]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_0803e200
    mov r0, r8
    ldrh r1, [r0, #0x14]
    lsrs r0, r7, #2
    cmp r1, r0
    bhi lbl_0803e1f4
    movs r2, #4
    b lbl_0803e202
    .align 2, 0
lbl_0803e1ec: .4byte 0x0300006e
lbl_0803e1f0: .4byte 0x0300070c
lbl_0803e1f4:
    lsrs r0, r7, #1
    movs r2, #2
    cmp r1, r0
    bhi lbl_0803e202
    movs r2, #3
    b lbl_0803e202
lbl_0803e200:
    movs r2, #2
lbl_0803e202:
    movs r4, #0
    mov r3, r8
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803e236
    mov r1, r8
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0x3e
    bls lbl_0803e220
    movs r4, #1
    b lbl_0803e224
lbl_0803e220:
    adds r0, r2, r0
    strb r0, [r1]
lbl_0803e224:
    ldrh r1, [r5, #8]
    mov r3, r8
    ldrh r0, [r3, #8]
    adds r0, #0x40
    cmp r1, r0
    bge lbl_0803e260
    adds r0, r1, r2
    strh r0, [r5, #8]
    b lbl_0803e266
lbl_0803e236:
    mov r3, r8
    adds r3, #0x2a
    ldrb r1, [r3]
    subs r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xbf
    bhi lbl_0803e24a
    movs r4, #1
    b lbl_0803e24e
lbl_0803e24a:
    subs r0, r1, r2
    strb r0, [r3]
lbl_0803e24e:
    ldrh r1, [r5, #8]
    mov r3, r8
    ldrh r0, [r3, #8]
    subs r0, #0x40
    cmp r1, r0
    ble lbl_0803e260
    subs r0, r1, r2
    strh r0, [r5, #8]
    b lbl_0803e266
lbl_0803e260:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0803e266:
    ldrh r1, [r5, #6]
    mov r3, r8
    ldrh r0, [r3, #6]
    subs r0, #0x30
    cmp r1, r0
    ble lbl_0803e278
    subs r0, r1, r2
    strh r0, [r5, #6]
    b lbl_0803e27e
lbl_0803e278:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0803e27e:
    mov r0, r8
    ldrh r6, [r0, #2]
    bl sub_0803d860
    mov r3, r8
    ldrh r1, [r3, #2]
    ldrh r2, [r3, #4]
    adds r0, r6, #0
    movs r3, #3
    bl SpriteUtilCheckOutOfRoomEffect
    cmp r0, #0
    beq lbl_0803e29e
    ldr r0, lbl_0803e2dc @ =0x000001bb
    bl SoundPlay
lbl_0803e29e:
    bl AcidWormCollidingWithSamusWhenExtending
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803e2aa
    b lbl_0803e49a
lbl_0803e2aa:
    cmp r4, #3
    beq lbl_0803e2b0
    b lbl_0803e49a
lbl_0803e2b0:
    mov r1, r8
    adds r1, #0x24
    movs r0, #0xf
    strb r0, [r1]
    ldr r0, lbl_0803e2e0 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    beq lbl_0803e2c2
    b lbl_0803e48c
lbl_0803e2c2:
    mov r0, r8
    ldrh r6, [r0, #2]
    ldrh r5, [r0, #4]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0803e2e4
    adds r0, r5, #0
    adds r0, #0x40
    b lbl_0803e2e8
    .align 2, 0
lbl_0803e2dc: .4byte 0x000001bb
lbl_0803e2e0: .4byte 0x0300070c
lbl_0803e2e4:
    adds r0, r5, #0
    subs r0, #0x40
lbl_0803e2e8:
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r1, lbl_0803e37c @ =0x03000738
    mov r8, r1
    ldrh r1, [r1, #0x14]
    lsrs r0, r7, #2
    cmp r1, r0
    bhi lbl_0803e384
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0x28
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
    adds r2, r6, #0
    subs r2, #0x42
    adds r3, r5, #0
    subs r3, #0x20
    movs r0, #0
    movs r1, #0x11
    bl SpriteDebrisInit
    movs r0, #0
    movs r1, #4
    adds r2, r6, #0
    adds r3, r5, #0
    bl SpriteDebrisInit
    adds r3, r5, #0
    adds r3, #0x34
    movs r0, #0
    movs r1, #0x12
    adds r2, r6, #0
    bl SpriteDebrisInit
    adds r2, r6, #0
    subs r2, #0x5c
    adds r3, r5, #0
    subs r3, #0x3e
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r4, r6, #0
    adds r4, #0x20
    adds r3, r5, #0
    adds r3, #0x20
    movs r0, #0
    movs r1, #4
    adds r2, r4, #0
    bl SpriteDebrisInit
    adds r2, r6, #0
    adds r2, #0x40
    movs r0, #0
    movs r1, #0x12
    adds r3, r5, #0
    bl SpriteDebrisInit
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x22
    bl ParticleSet
    mov r1, r8
    adds r1, #0x2c
    movs r0, #0x78
    strb r0, [r1]
    ldr r0, lbl_0803e380 @ =0x000001b3
    bl SoundPlay
    b lbl_0803e440
    .align 2, 0
lbl_0803e37c: .4byte 0x03000738
lbl_0803e380: .4byte 0x000001b3
lbl_0803e384:
    lsrs r0, r7, #1
    cmp r1, r0
    bhi lbl_0803e3f6
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
    adds r2, r6, #0
    subs r2, #0x42
    adds r3, r5, #0
    subs r3, #0x20
    movs r0, #0
    movs r1, #0x11
    bl SpriteDebrisInit
    adds r3, r5, #0
    adds r3, #0x34
    movs r0, #0
    movs r1, #0x12
    adds r2, r6, #0
    bl SpriteDebrisInit
    adds r2, r6, #0
    subs r2, #0x5c
    adds r3, r5, #0
    subs r3, #0x3e
    movs r0, #0
    movs r1, #0x13
    bl SpriteDebrisInit
    adds r4, r6, #0
    adds r4, #0x20
    adds r3, r5, #0
    adds r3, #0x20
    movs r0, #0
    movs r1, #4
    adds r2, r4, #0
    bl SpriteDebrisInit
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x21
    bl ParticleSet
    mov r1, r8
    adds r1, #0x2c
    movs r0, #0x8c
    strb r0, [r1]
    movs r0, #0xd9
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803e440
lbl_0803e3f6:
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
    adds r2, r6, #0
    subs r2, #0x42
    adds r3, r5, #0
    subs r3, #0x20
    movs r0, #0
    movs r1, #0x12
    bl SpriteDebrisInit
    adds r4, r6, #0
    adds r4, #0x20
    adds r3, r5, #0
    adds r3, #0x20
    movs r0, #0
    movs r1, #4
    adds r2, r4, #0
    bl SpriteDebrisInit
    adds r0, r4, #0
    adds r1, r5, #0
    movs r2, #0x20
    bl ParticleSet
    mov r1, r8
    adds r1, #0x2c
    movs r0, #0xa0
    strb r0, [r1]
    ldr r0, lbl_0803e458 @ =0x000001b1
    bl SoundPlay
lbl_0803e440:
    ldr r0, lbl_0803e45c @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0803e464
    ldr r2, lbl_0803e460 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r0, #0x3c
    strb r0, [r1]
    mov r8, r2
    b lbl_0803e476
    .align 2, 0
lbl_0803e458: .4byte 0x000001b1
lbl_0803e45c: .4byte 0x0300002c
lbl_0803e460: .4byte 0x03000738
lbl_0803e464:
    ldr r3, lbl_0803e484 @ =0x03000738
    mov r8, r3
    cmp r0, #2
    bne lbl_0803e476
    mov r1, r8
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #0x14
    strb r0, [r1]
lbl_0803e476:
    ldr r0, lbl_0803e488 @ =0x082fc1c8
    mov r1, r8
    str r0, [r1, #0x18]
    adds r1, #0x2d
    movs r0, #0
    strb r0, [r1]
    b lbl_0803e492
    .align 2, 0
lbl_0803e484: .4byte 0x03000738
lbl_0803e488: .4byte 0x082fc1c8
lbl_0803e48c:
    ldr r0, lbl_0803e4a4 @ =0x082fc150
    mov r3, r8
    str r0, [r3, #0x18]
lbl_0803e492:
    movs r0, #0
    mov r1, r8
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
lbl_0803e49a:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e4a4: .4byte 0x082fc150

    thumb_func_start AcidWormExtended
AcidWormExtended: @ 0x0803e4a8
    push {r4, r5, lr}
    sub sp, #0xc
    movs r5, #0
    bl sub_0803d860
    ldr r0, lbl_0803e504 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #0
    bne lbl_0803e50c
    bl AcidWormCollidingWithSamusWhenExtending
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803e4c6
    b lbl_0803e6a8
lbl_0803e4c6:
    ldr r4, lbl_0803e508 @ =0x03000738
    adds r5, r4, #0
    adds r5, #0x2d
    ldrb r1, [r5]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_0803e4de
    movs r0, #0xda
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803e4de:
    ldrb r0, [r5]
    adds r0, #1
    strb r0, [r5]
    adds r1, r4, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0803e4f6
    b lbl_0803e6a8
lbl_0803e4f6:
    subs r1, #8
    movs r0, #0x27
    strb r0, [r1]
    bl AcidWormPlaySound
    b lbl_0803e6a8
    .align 2, 0
lbl_0803e504: .4byte 0x0300070c
lbl_0803e508: .4byte 0x03000738
lbl_0803e50c:
    ldr r0, lbl_0803e52c @ =0x030013d4
    ldrh r2, [r0, #0x12]
    ldr r0, lbl_0803e530 @ =0x03000738
    ldrh r1, [r0, #8]
    ldr r3, lbl_0803e534 @ =0xfffffe40
    adds r0, r1, r3
    cmp r2, r0
    ble lbl_0803e538
    movs r4, #0xe0
    lsls r4, r4, #1
    adds r0, r1, r4
    cmp r2, r0
    bge lbl_0803e538
    movs r5, #1
    b lbl_0803e546
    .align 2, 0
lbl_0803e52c: .4byte 0x030013d4
lbl_0803e530: .4byte 0x03000738
lbl_0803e534: .4byte 0xfffffe40
lbl_0803e538:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803e546
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
lbl_0803e546:
    ldr r1, lbl_0803e560 @ =0x03000738
    ldrh r0, [r1, #0x16]
    mov ip, r1
    cmp r0, #1
    bne lbl_0803e564
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0803e564
    movs r0, #0xdb
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803e68e
    .align 2, 0
lbl_0803e560: .4byte 0x03000738
lbl_0803e564:
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #2
    bne lbl_0803e580
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0803e580
    ldr r0, lbl_0803e57c @ =0x000001b7
    bl SoundPlay
    b lbl_0803e68e
    .align 2, 0
lbl_0803e57c: .4byte 0x000001b7
lbl_0803e580:
    mov r3, ip
    ldrh r0, [r3, #0x16]
    cmp r0, #5
    bne lbl_0803e5d8
    ldrb r0, [r3, #0x1c]
    cmp r0, #1
    bne lbl_0803e5d8
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0803e5b8
    ldrb r2, [r3, #0x1f]
    mov r0, ip
    adds r0, #0x23
    ldrb r3, [r0]
    mov r4, ip
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    adds r0, #0x30
    str r0, [sp, #4]
    movs r0, #0x40
    str r0, [sp, #8]
    b lbl_0803e5ce
lbl_0803e5b8:
    mov r0, ip
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    mov r4, ip
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x30
    str r0, [sp, #4]
    str r1, [sp, #8]
lbl_0803e5ce:
    movs r0, #0x26
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0803e68e
lbl_0803e5d8:
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #7
    bne lbl_0803e632
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0803e632
    ldrh r1, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0803e612
    mov r3, ip
    ldrb r2, [r3, #0x1f]
    mov r0, ip
    adds r0, #0x23
    ldrb r3, [r0]
    mov r4, ip
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    adds r0, #0x30
    str r0, [sp, #4]
    movs r0, #0x40
    str r0, [sp, #8]
    b lbl_0803e628
lbl_0803e612:
    mov r0, ip
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    mov r4, ip
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x30
    str r0, [sp, #4]
    str r1, [sp, #8]
lbl_0803e628:
    movs r0, #0x26
    movs r1, #1
    bl SpriteSpawnSecondary
    b lbl_0803e68e
lbl_0803e632:
    mov r4, ip
    ldrh r0, [r4, #0x16]
    cmp r0, #9
    bne lbl_0803e68e
    ldrb r0, [r4, #0x1c]
    cmp r0, #1
    bne lbl_0803e68e
    ldrh r1, [r4]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0803e670
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    adds r0, #0x30
    str r0, [sp, #4]
    movs r0, #0x40
    str r0, [sp, #8]
    movs r0, #0x26
    movs r1, #2
    bl SpriteSpawnSecondary
    b lbl_0803e68e
lbl_0803e670:
    mov r0, ip
    ldrb r2, [r0, #0x1f]
    adds r0, #0x23
    ldrb r3, [r0]
    mov r4, ip
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x30
    str r0, [sp, #4]
    str r1, [sp, #8]
    movs r0, #0x26
    movs r1, #2
    bl SpriteSpawnSecondary
lbl_0803e68e:
    cmp r5, #0
    beq lbl_0803e6a8
    ldr r1, lbl_0803e6b0 @ =0x03000738
    ldr r0, lbl_0803e6b4 @ =0x082fc1c8
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    adds r1, #0x24
    movs r0, #0x27
    strb r0, [r1]
    bl AcidWormPlaySound
lbl_0803e6a8:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e6b0: .4byte 0x03000738
lbl_0803e6b4: .4byte 0x082fc1c8

    thumb_func_start AcidWormRetracting
AcidWormRetracting: @ 0x0803e6b8
    push {r4, r5, r6, r7, lr}
    movs r4, #2
    movs r7, #0
    ldr r2, lbl_0803e6e4 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    adds r5, r2, #0
    cmp r3, #0
    beq lbl_0803e704
    adds r1, r5, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #2
    bhi lbl_0803e6e8
    movs r7, #1
    movs r0, #0
    b lbl_0803e6ea
    .align 2, 0
lbl_0803e6e4: .4byte 0x03000738
lbl_0803e6e8:
    subs r0, #2
lbl_0803e6ea:
    strb r0, [r1]
    ldr r0, lbl_0803e700 @ =0x0300070c
    ldrh r1, [r0, #8]
    ldrh r2, [r5, #8]
    adds r3, r0, #0
    cmp r1, r2
    bls lbl_0803e730
    subs r0, r1, r4
    strh r0, [r3, #8]
    b lbl_0803e738
    .align 2, 0
lbl_0803e700: .4byte 0x0300070c
lbl_0803e704:
    adds r1, r5, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #2
    bhi lbl_0803e714
    movs r7, #1
    strb r3, [r1]
    b lbl_0803e718
lbl_0803e714:
    adds r0, #2
    strb r0, [r1]
lbl_0803e718:
    ldr r0, lbl_0803e72c @ =0x0300070c
    ldrh r1, [r0, #8]
    ldrh r2, [r5, #8]
    adds r3, r0, #0
    cmp r1, r2
    bhs lbl_0803e730
    adds r0, r1, r4
    strh r0, [r3, #8]
    b lbl_0803e738
    .align 2, 0
lbl_0803e72c: .4byte 0x0300070c
lbl_0803e730:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    strh r2, [r3, #8]
lbl_0803e738:
    ldrh r0, [r3, #6]
    ldrh r1, [r5, #6]
    cmp r0, r1
    bhs lbl_0803e746
    adds r0, #2
    strh r0, [r3, #6]
    b lbl_0803e74e
lbl_0803e746:
    strh r1, [r3, #6]
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_0803e74e:
    ldr r0, lbl_0803e7f8 @ =0x0300006c
    ldrh r0, [r0]
    ldrh r3, [r3, #0xa]
    cmp r0, r3
    bls lbl_0803e760
    ldr r1, lbl_0803e7fc @ =0x0300006e
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_0803e760:
    adds r4, r5, #0
    ldrh r6, [r4, #2]
    bl sub_0803d860
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r6, #0
    movs r3, #3
    bl SpriteUtilCheckInRoomEffect
    cmp r0, #0
    beq lbl_0803e77e
    ldr r0, lbl_0803e800 @ =0x000001bb
    bl SoundPlay
lbl_0803e77e:
    ldr r4, lbl_0803e804 @ =0x030013d4
    ldrh r3, [r4, #0x14]
    ldrh r6, [r5, #2]
    cmp r7, #3
    bne lbl_0803e856
    ldr r2, lbl_0803e808 @ =0x082b0d68
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    ldrh r1, [r5, #0x14]
    lsrs r0, r0, #1
    cmp r1, r0
    bhi lbl_0803e83c
    ldr r0, lbl_0803e80c @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803e83c
    ldrh r0, [r5]
    movs r1, #0x20
    eors r0, r1
    strh r0, [r5]
    movs r1, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0803e81c
    subs r0, r6, r3
    subs r0, #0x51
    cmp r0, #0xee
    bhi lbl_0803e81c
    ldrh r2, [r4, #0x12]
    ldrh r1, [r5, #8]
    ldr r3, lbl_0803e810 @ =0xfffffe40
    adds r0, r1, r3
    cmp r2, r0
    ble lbl_0803e81c
    movs r3, #0xe0
    lsls r3, r3, #1
    adds r0, r1, r3
    cmp r2, r0
    bge lbl_0803e81c
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x29
    strb r0, [r1]
    ldr r0, lbl_0803e814 @ =0x082fc138
    str r0, [r5, #0x18]
    movs r0, #0
    strb r0, [r5, #0x1c]
    movs r0, #0
    strh r0, [r5, #0x16]
    adds r1, #8
    movs r0, #0x28
    strb r0, [r1]
    ldr r0, lbl_0803e818 @ =0x000001b9
    bl SoundPlay
    b lbl_0803e856
    .align 2, 0
lbl_0803e7f8: .4byte 0x0300006c
lbl_0803e7fc: .4byte 0x0300006e
lbl_0803e800: .4byte 0x000001bb
lbl_0803e804: .4byte 0x030013d4
lbl_0803e808: .4byte 0x082b0d68
lbl_0803e80c: .4byte 0x0300002c
lbl_0803e810: .4byte 0xfffffe40
lbl_0803e814: .4byte 0x082fc138
lbl_0803e818: .4byte 0x000001b9
lbl_0803e81c:
    ldr r2, lbl_0803e834 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0803e838 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    lsls r0, r0, #3
    adds r0, #0x3c
    b lbl_0803e852
    .align 2, 0
lbl_0803e834: .4byte 0x03000738
lbl_0803e838: .4byte 0x0300083c
lbl_0803e83c:
    ldr r2, lbl_0803e85c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0803e860 @ =0x0300083c
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    lsls r0, r0, #3
    adds r0, #0x50
lbl_0803e852:
    adds r2, #0x2c
    strb r0, [r2]
lbl_0803e856:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e85c: .4byte 0x03000738
lbl_0803e860: .4byte 0x0300083c

    thumb_func_start AcidWormRaiseAcid
AcidWormRaiseAcid: @ 0x0803e864
    push {lr}
    ldr r0, lbl_0803e88c @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0803e87a
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
lbl_0803e87a:
    ldr r2, lbl_0803e890 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0803e894
    subs r0, #1
    strb r0, [r1]
    b lbl_0803e8ba
    .align 2, 0
lbl_0803e88c: .4byte 0x03000c77
lbl_0803e890: .4byte 0x03000738
lbl_0803e894:
    ldr r1, lbl_0803e8c0 @ =0x0300006e
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    ldr r0, lbl_0803e8c4 @ =0x0300006c
    ldrh r1, [r0]
    ldrh r0, [r2, #6]
    ldr r3, lbl_0803e8c8 @ =0xfffffec0
    adds r0, r0, r3
    cmp r1, r0
    bge lbl_0803e8ba
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #0x2b
    strb r1, [r0]
    movs r0, #0xdd
    lsls r0, r0, #1
    bl SoundPlay
lbl_0803e8ba:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e8c0: .4byte 0x0300006e
lbl_0803e8c4: .4byte 0x0300006c
lbl_0803e8c8: .4byte 0xfffffec0

    thumb_func_start AcidWormAcidGoDown
AcidWormAcidGoDown: @ 0x0803e8cc
    push {r4, lr}
    ldr r4, lbl_0803e928 @ =0x0300006e
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    ldr r0, lbl_0803e92c @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0803e8ea
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
lbl_0803e8ea:
    ldr r0, lbl_0803e930 @ =0x0300006c
    ldrh r1, [r0]
    ldr r2, lbl_0803e934 @ =0x03000738
    ldrh r0, [r2, #6]
    subs r0, #0xc0
    cmp r1, r0
    ble lbl_0803e920
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #8
    strb r0, [r1]
    adds r1, #8
    movs r0, #1
    strb r0, [r1]
    movs r1, #0x40
    rsbs r1, r1, #0
    adds r0, r1, #0
    strh r0, [r4]
    ldr r3, lbl_0803e938 @ =0x0300070c
    ldrh r1, [r3, #0xa]
    ldrh r2, [r2, #6]
    adds r0, r2, #0
    subs r0, #0x80
    cmp r1, r0
    bne lbl_0803e920
    subs r0, #0x40
    strh r0, [r3, #0xa]
lbl_0803e920:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803e928: .4byte 0x0300006e
lbl_0803e92c: .4byte 0x03000c77
lbl_0803e930: .4byte 0x0300006c
lbl_0803e934: .4byte 0x03000738
lbl_0803e938: .4byte 0x0300070c

    thumb_func_start AcidWormDeathGFXInit
AcidWormDeathGFXInit: @ 0x0803e93c
    ldr r0, lbl_0803e958 @ =0x03000738
    ldr r1, lbl_0803e95c @ =0x082fc138
    str r1, [r0, #0x18]
    movs r1, #0
    strb r1, [r0, #0x1c]
    strh r1, [r0, #0x16]
    adds r2, r0, #0
    adds r2, #0x24
    movs r1, #0x67
    strb r1, [r2]
    adds r0, #0x2b
    movs r1, #0x50
    strb r1, [r0]
    bx lr
    .align 2, 0
lbl_0803e958: .4byte 0x03000738
lbl_0803e95c: .4byte 0x082fc138

    thumb_func_start AcidWormDeathFlashingAnim
AcidWormDeathFlashingAnim: @ 0x0803e960
    push {r4, r5, lr}
    ldr r4, lbl_0803e9b0 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x26
    movs r5, #1
    strb r5, [r0]
    bl sub_0803d860
    adds r2, r4, #0
    adds r2, #0x2b
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0803e9e2
    subs r0, r1, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r2, r1, #0
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0803e9e2
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0803e9b4
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
    b lbl_0803e9e2
    .align 2, 0
lbl_0803e9b0: .4byte 0x03000738
lbl_0803e9b4:
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r1, [r0]
    subs r0, #0x14
    strb r1, [r0]
    cmp r2, #0
    bne lbl_0803e9e2
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x22
    bl ParticleSet
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x68
    strb r0, [r1]
    ldrh r1, [r4]
    movs r0, #4
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x2c
    strb r5, [r0]
lbl_0803e9e2:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start AcidWormDying
AcidWormDying: @ 0x0803e9e8
    push {r4, lr}
    ldr r0, lbl_0803ea10 @ =0x0300006c
    ldrh r1, [r0]
    ldr r3, lbl_0803ea14 @ =0x03000738
    ldrh r2, [r3, #6]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r2, r4
    cmp r1, r0
    ble lbl_0803ea1c
    ldr r0, lbl_0803ea18 @ =0x0300070c
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    bne lbl_0803eaa8
    strh r0, [r3]
    movs r0, #0xb
    movs r1, #0
    bl PlayMusic
    b lbl_0803eaa8
    .align 2, 0
lbl_0803ea10: .4byte 0x0300006c
lbl_0803ea14: .4byte 0x03000738
lbl_0803ea18: .4byte 0x0300070c
lbl_0803ea1c:
    ldr r0, lbl_0803ea48 @ =0x0300070c
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    bne lbl_0803ea5c
    cmp r1, r2
    bhs lbl_0803ea54
    ldr r0, lbl_0803ea4c @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_0803ea5c
    ldr r0, lbl_0803ea50 @ =0x0300083c
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, #0x48
    adds r0, r2, r0
    ldrh r1, [r3, #8]
    movs r2, #0x39
    bl ParticleSet
    b lbl_0803ea5c
    .align 2, 0
lbl_0803ea48: .4byte 0x0300070c
lbl_0803ea4c: .4byte 0x03000c77
lbl_0803ea50: .4byte 0x0300083c
lbl_0803ea54:
    ldr r1, lbl_0803ea7c @ =0x0300006e
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0803ea5c:
    ldr r0, lbl_0803ea80 @ =0x03000738
    adds r1, r0, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0803ea84
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0803eaa8
    movs r0, #0xdf
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803eaa8
    .align 2, 0
lbl_0803ea7c: .4byte 0x0300006e
lbl_0803ea80: .4byte 0x03000738
lbl_0803ea84:
    ldr r1, lbl_0803eab0 @ =0x0300006e
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r0, lbl_0803eab4 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0803eaa8
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0xa
    movs r1, #0x81
    bl ScreenShakeStartHorizontal
lbl_0803eaa8:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803eab0: .4byte 0x0300006e
lbl_0803eab4: .4byte 0x03000c77

    thumb_func_start AcidWormBodyInit
AcidWormBodyInit: @ 0x0803eab8
    push {r4, lr}
    ldr r0, lbl_0803eb2c @ =0x03000738
    mov ip, r0
    ldrh r1, [r0]
    ldr r0, lbl_0803eb30 @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    movs r4, #0
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    mov r1, ip
    strh r0, [r1]
    adds r1, #0x25
    movs r0, #0x15
    strb r0, [r1]
    subs r1, #1
    movs r0, #0x43
    strb r0, [r1]
    mov r3, ip
    strb r2, [r3, #0x1c]
    strh r4, [r3, #0x16]
    mov r2, ip
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    strh r0, [r3, #0x14]
    mov r0, ip
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldrb r0, [r3, #0x1e]
    lsls r0, r0, #1
    movs r1, #0x14
    subs r1, r1, r0
    mov r0, ip
    adds r0, #0x2e
    strb r1, [r0]
    ldrb r0, [r3, #0x1e]
    subs r0, #1
    cmp r0, #8
    bls lbl_0803eb20
    b lbl_0803ed04
lbl_0803eb20:
    lsls r0, r0, #2
    ldr r1, lbl_0803eb34 @ =lbl_0803eb38
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803eb2c: .4byte 0x03000738
lbl_0803eb30: .4byte 0x0000fffb
lbl_0803eb34: .4byte lbl_0803eb38
lbl_0803eb38: @ jump table
    .4byte lbl_0803eb5c @ case 0
    .4byte lbl_0803eb84 @ case 1
    .4byte lbl_0803ebbc @ case 2
    .4byte lbl_0803ebec @ case 3
    .4byte lbl_0803ec1c @ case 4
    .4byte lbl_0803ec44 @ case 5
    .4byte lbl_0803ec74 @ case 6
    .4byte lbl_0803eca4 @ case 7
    .4byte lbl_0803ecd4 @ case 8
lbl_0803eb5c:
    ldr r1, lbl_0803eb7c @ =0x0000fff0
    strh r1, [r3, #0xa]
    movs r0, #0x10
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    ldr r0, lbl_0803eb80 @ =0x082fc1f0
    str r0, [r3, #0x18]
    adds r0, r3, #0
    adds r0, #0x2c
    movs r1, #8
    b lbl_0803ec0a
    .align 2, 0
lbl_0803eb7c: .4byte 0x0000fff0
lbl_0803eb80: .4byte 0x082fc1f0
lbl_0803eb84:
    ldr r1, lbl_0803ebb4 @ =0x0000ffd0
    strh r1, [r3, #0xa]
    movs r0, #0x30
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #2
    strb r0, [r1]
    ldr r0, lbl_0803ebb8 @ =0x082fc200
    str r0, [r3, #0x18]
    adds r0, r3, #0
    adds r0, #0x2c
    movs r2, #0x10
    strb r2, [r0]
    movs r0, #0x32
    adds r0, r0, r3
    mov ip, r0
    ldrb r1, [r0]
    movs r0, #0xbf
    ands r0, r1
    mov r1, ip
    b lbl_0803ecf2
    .align 2, 0
lbl_0803ebb4: .4byte 0x0000ffd0
lbl_0803ebb8: .4byte 0x082fc200
lbl_0803ebbc:
    ldr r0, lbl_0803ebe0 @ =0x0000ffd0
    strh r0, [r3, #0xa]
    movs r0, #0x30
    strh r0, [r3, #0xc]
    ldr r0, lbl_0803ebe4 @ =0x0000ffd8
    strh r0, [r3, #0xe]
    movs r0, #0x28
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    ldr r0, lbl_0803ebe8 @ =0x082fc270
    str r0, [r3, #0x18]
    adds r0, r3, #0
    adds r0, #0x2c
    movs r1, #0x18
    b lbl_0803ec0a
    .align 2, 0
lbl_0803ebe0: .4byte 0x0000ffd0
lbl_0803ebe4: .4byte 0x0000ffd8
lbl_0803ebe8: .4byte 0x082fc270
lbl_0803ebec:
    ldr r1, lbl_0803ec14 @ =0x0000ffdc
    strh r1, [r3, #0xa]
    movs r0, #0x24
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0803ec18 @ =0x082fc280
    str r0, [r3, #0x18]
    adds r0, r3, #0
    adds r0, #0x2c
    movs r1, #0x20
lbl_0803ec0a:
    strb r1, [r0]
    adds r0, #3
    strb r1, [r0]
    b lbl_0803ed08
    .align 2, 0
lbl_0803ec14: .4byte 0x0000ffdc
lbl_0803ec18: .4byte 0x082fc280
lbl_0803ec1c:
    movs r2, #0
    ldr r1, lbl_0803ec3c @ =0x0000ffe0
    strh r1, [r3, #0xa]
    movs r0, #0x20
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_0803ec40 @ =0x082fc290
    str r0, [r3, #0x18]
    adds r1, #0xa
    movs r0, #0x28
    b lbl_0803ecf2
    .align 2, 0
lbl_0803ec3c: .4byte 0x0000ffe0
lbl_0803ec40: .4byte 0x082fc290
lbl_0803ec44:
    ldr r1, lbl_0803ec6c @ =0x0000ffe0
    strh r1, [r3, #0xa]
    movs r0, #0x20
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_0803ec70 @ =0x082fc290
    str r0, [r3, #0x18]
    adds r1, #0xa
    movs r0, #0x30
    strb r0, [r1]
    adds r1, #3
    movs r0, #8
    strb r0, [r1]
    b lbl_0803ed08
    .align 2, 0
lbl_0803ec6c: .4byte 0x0000ffe0
lbl_0803ec70: .4byte 0x082fc290
lbl_0803ec74:
    ldr r1, lbl_0803ec9c @ =0x0000ffe0
    strh r1, [r3, #0xa]
    movs r0, #0x20
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_0803eca0 @ =0x082fc290
    str r0, [r3, #0x18]
    adds r1, #0xa
    movs r0, #0x38
    strb r0, [r1]
    adds r1, #3
    movs r0, #0x10
    strb r0, [r1]
    b lbl_0803ed08
    .align 2, 0
lbl_0803ec9c: .4byte 0x0000ffe0
lbl_0803eca0: .4byte 0x082fc290
lbl_0803eca4:
    ldr r1, lbl_0803eccc @ =0x0000ffe0
    strh r1, [r3, #0xa]
    movs r0, #0x20
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_0803ecd0 @ =0x082fc290
    str r0, [r3, #0x18]
    adds r1, #0xa
    movs r0, #0x40
    strb r0, [r1]
    adds r1, #3
    movs r0, #0x18
    strb r0, [r1]
    b lbl_0803ed08
    .align 2, 0
lbl_0803eccc: .4byte 0x0000ffe0
lbl_0803ecd0: .4byte 0x082fc290
lbl_0803ecd4:
    ldr r1, lbl_0803ecfc @ =0x0000ffe0
    strh r1, [r3, #0xa]
    movs r2, #0x20
    movs r0, #0x20
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_0803ed00 @ =0x082fc290
    str r0, [r3, #0x18]
    adds r1, #0xa
    movs r0, #0x48
lbl_0803ecf2:
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2f
    strb r2, [r0]
    b lbl_0803ed08
    .align 2, 0
lbl_0803ecfc: .4byte 0x0000ffe0
lbl_0803ed00: .4byte 0x082fc290
lbl_0803ed04:
    mov r3, ip
    strh r4, [r3]
lbl_0803ed08:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AcidWormBodyMove
AcidWormBodyMove: @ 0x0803ed10
    push {r4, r5, lr}
    ldr r4, lbl_0803ed4c @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r5, [r0]
    ldr r1, lbl_0803ed50 @ =0x030001ac
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    bne lbl_0803ed54
    ldrh r3, [r4, #2]
    adds r0, r3, #0
    subs r0, #0x10
    strh r0, [r4, #2]
    ldrb r1, [r4, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0803eda8
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r3, #0
    movs r3, #3
    bl SpriteUtilCheckOutOfRoomEffect
    b lbl_0803eda8
    .align 2, 0
lbl_0803ed4c: .4byte 0x03000738
lbl_0803ed50: .4byte 0x030001ac
lbl_0803ed54:
    cmp r0, #0x47
    bne lbl_0803ed7c
    bl AcidWormRandomXMovement
    ldrh r3, [r4, #2]
    adds r0, r3, #0
    adds r0, #0x10
    strh r0, [r4, #2]
    ldrb r1, [r4, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0803eda8
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r3, #0
    movs r3, #3
    bl SpriteUtilCheckInRoomEffect
    b lbl_0803eda8
lbl_0803ed7c:
    cmp r0, #0x45
    bne lbl_0803ed86
    bl AcidWormRandomXMovement
    b lbl_0803eda8
lbl_0803ed86:
    cmp r0, #8
    bne lbl_0803eda8
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldrh r1, [r4]
    movs r0, #0x80
    movs r2, #0
    orrs r0, r1
    strh r0, [r4]
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r4, #0x12]
    adds r0, r4, #0
    adds r0, #0x2a
    strb r2, [r0]
lbl_0803eda8:
    ldr r1, lbl_0803ee0c @ =0x030001ac
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r3, r0, r1
    adds r0, r3, #0
    adds r0, #0x24
    ldrb r0, [r0]
    ldr r4, lbl_0803ee10 @ =0x03000738
    cmp r0, #0x42
    bls lbl_0803edc6
    ldrh r1, [r4]
    ldr r0, lbl_0803ee14 @ =0x00007fff
    ands r0, r1
    strh r0, [r4]
lbl_0803edc6:
    ldrb r0, [r4, #0x1e]
    cmp r0, #2
    bne lbl_0803ee04
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_0803ee18 @ =0x000003ff
    cmp r1, r0
    bhi lbl_0803ee04
    adds r2, r4, #0
    adds r2, #0x2b
    ldrb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x2b
    strb r0, [r1]
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r4, #0x14]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r3, #0x14]
    cmp r0, r1
    bls lbl_0803ee04
    subs r0, r0, r1
    strh r0, [r3, #0x14]
    adds r0, r2, #0
    strh r0, [r4, #0x14]
lbl_0803ee04:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803ee0c: .4byte 0x030001ac
lbl_0803ee10: .4byte 0x03000738
lbl_0803ee14: .4byte 0x00007fff
lbl_0803ee18: .4byte 0x000003ff

    thumb_func_start AcidWormBodyMainLoop
AcidWormBodyMainLoop: @ 0x0803ee1c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r2, lbl_0803ee5c @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r0, [r0]
    mov r8, r0
    adds r0, r2, #0
    adds r0, #0x2c
    ldrb r5, [r0]
    adds r6, r5, #0
    ldr r1, lbl_0803ee60 @ =0x030001ac
    mov r3, r8
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r4, r0, r1
    ldrh r3, [r4, #0x14]
    adds r7, r1, #0
    cmp r3, #0
    bne lbl_0803ee64
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x25
    strb r3, [r0]
    strh r3, [r2, #0x14]
    b lbl_0803effa
    .align 2, 0
lbl_0803ee5c: .4byte 0x03000738
lbl_0803ee60: .4byte 0x030001ac
lbl_0803ee64:
    ldrh r1, [r4]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803ee84
    ldrh r1, [r2]
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    adds r0, r4, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    subs r0, r0, r5
    b lbl_0803ee94
lbl_0803ee84:
    ldrh r1, [r2]
    ldr r0, lbl_0803eee0 @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
    adds r0, r4, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    adds r0, r6, r0
lbl_0803ee94:
    adds r1, r2, #0
    adds r1, #0x2a
    strb r0, [r1]
    mov r0, r8
    lsls r2, r0, #3
    subs r0, r2, r0
    lsls r0, r0, #3
    adds r5, r0, r7
    ldrh r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    mov sb, r2
    cmp r0, #0
    bne lbl_0803ef02
    ldr r4, lbl_0803eee4 @ =0x03000738
    ldrh r6, [r4, #2]
    adds r7, r6, #0
    bl sub_0803d860
    adds r0, r5, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x25
    bne lbl_0803eee8
    ldrb r1, [r4, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0803ef02
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r6, #0
    movs r3, #3
    bl SpriteUtilCheckOutOfRoomEffect
    b lbl_0803ef02
    .align 2, 0
lbl_0803eee0: .4byte 0x0000fdff
lbl_0803eee4: .4byte 0x03000738
lbl_0803eee8:
    cmp r0, #0x27
    bne lbl_0803ef02
    ldrb r1, [r4, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0803ef02
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    adds r0, r7, #0
    movs r3, #3
    bl SpriteUtilCheckInRoomEffect
lbl_0803ef02:
    ldr r4, lbl_0803ef70 @ =0x03000738
    ldrb r6, [r4, #0x1e]
    cmp r6, #2
    beq lbl_0803ef0c
    b lbl_0803f006
lbl_0803ef0c:
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_0803ef74 @ =0x000003ff
    cmp r1, r0
    bhi lbl_0803efcc
    ldr r1, lbl_0803ef78 @ =0x030001ac
    mov r2, sb
    mov r3, r8
    subs r0, r2, r3
    lsls r0, r0, #3
    adds r3, r0, r1
    adds r2, r4, #0
    adds r2, #0x2b
    ldrb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x2b
    movs r5, #0
    strb r0, [r1]
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    strb r0, [r2]
    ldrh r1, [r4, #0x14]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    subs r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldrh r0, [r3, #0x14]
    cmp r0, r1
    bls lbl_0803ef98
    subs r0, r0, r1
    strh r0, [r3, #0x14]
    adds r0, r2, #0
    strh r0, [r4, #0x14]
    ldr r2, lbl_0803ef7c @ =0x082b0d68
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r1, [r0]
    ldrh r2, [r3, #0x14]
    lsrs r0, r1, #2
    cmp r2, r0
    bhi lbl_0803ef80
    adds r0, r3, #0
    adds r0, #0x34
    strb r6, [r0]
    b lbl_0803ef8e
    .align 2, 0
lbl_0803ef70: .4byte 0x03000738
lbl_0803ef74: .4byte 0x000003ff
lbl_0803ef78: .4byte 0x030001ac
lbl_0803ef7c: .4byte 0x082b0d68
lbl_0803ef80:
    lsrs r0, r1, #1
    cmp r2, r0
    bhi lbl_0803ef8e
    adds r1, r3, #0
    adds r1, #0x34
    movs r0, #1
    strb r0, [r1]
lbl_0803ef8e:
    movs r0, #0xde
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0803efcc
lbl_0803ef98:
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x62
    strb r0, [r1]
    movs r1, #0
    strh r5, [r3, #0x14]
    adds r0, r3, #0
    adds r0, #0x25
    strb r1, [r0]
    strh r5, [r4, #0x14]
    ldrh r0, [r4]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0803efc8 @ =0x000001bd
    bl SoundPlay
    b lbl_0803f006
    .align 2, 0
lbl_0803efc8: .4byte 0x000001bd
lbl_0803efcc:
    ldr r0, lbl_0803efec @ =0x030001ac
    mov r2, sb
    mov r3, r8
    subs r1, r2, r3
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0803eff8
    ldr r2, lbl_0803eff0 @ =0x03000738
    ldrh r1, [r2]
    ldr r0, lbl_0803eff4 @ =0x00007fff
    ands r0, r1
    b lbl_0803f004
    .align 2, 0
lbl_0803efec: .4byte 0x030001ac
lbl_0803eff0: .4byte 0x03000738
lbl_0803eff4: .4byte 0x00007fff
lbl_0803eff8:
    ldr r2, lbl_0803f014 @ =0x03000738
lbl_0803effa:
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    orrs r0, r1
lbl_0803f004:
    strh r0, [r2]
lbl_0803f006:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f014: .4byte 0x03000738

    thumb_func_start AcidWormBodyDeath
AcidWormBodyDeath: @ 0x0803f018
    push {r4, r5, lr}
    sub sp, #4
    ldr r5, lbl_0803f054 @ =0x03000738
    adds r0, r5, #0
    adds r0, #0x23
    ldrb r4, [r0]
    adds r1, r5, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl sub_0803d860
    ldr r1, lbl_0803f058 @ =0x030001ac
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r4, r0, r1
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0803f05c
    adds r0, r4, #0
    adds r0, #0x20
    ldrb r1, [r0]
    adds r0, r5, #0
    adds r0, #0x20
    strb r1, [r0]
    b lbl_0803f0cc
    .align 2, 0
lbl_0803f054: .4byte 0x03000738
lbl_0803f058: .4byte 0x030001ac
lbl_0803f05c:
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_0803f0cc
    ldrb r0, [r5, #0x1e]
    movs r5, #0x21
    cmp r0, #2
    beq lbl_0803f0bc
    movs r5, #0x20
    cmp r0, #9
    bne lbl_0803f0bc
    ldr r0, lbl_0803f0d4 @ =0x0300070c
    strb r1, [r0, #0xe]
    ldrh r0, [r4, #6]
    adds r0, #0x60
    ldrh r1, [r4, #8]
    movs r2, #0x21
    bl ParticleSet
    ldrh r0, [r4, #6]
    adds r0, #0x40
    ldrh r1, [r4, #8]
    movs r2, #0x21
    bl ParticleSet
    ldrh r1, [r4, #6]
    ldrh r2, [r4, #8]
    movs r0, #1
    bl AcidWormChangeTwoGroundCCAA
    movs r0, #1
    movs r1, #0x1c
    bl EventFunction
    ldr r1, lbl_0803f0d8 @ =0x0300007b
    movs r2, #0x14
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
    movs r0, #0x87
    lsls r0, r0, #1
    bl FadeMusic
lbl_0803f0bc:
    ldr r0, lbl_0803f0dc @ =0x03000738
    ldrh r1, [r0, #2]
    ldrh r2, [r0, #4]
    str r5, [sp]
    movs r0, #0
    movs r3, #0
    bl SpriteUtilSpriteDeath
lbl_0803f0cc:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f0d4: .4byte 0x0300070c
lbl_0803f0d8: .4byte 0x0300007b
lbl_0803f0dc: .4byte 0x03000738

    thumb_func_start AcidWormSpitInit
AcidWormSpitInit: @ 0x0803f0e0
    push {r4, lr}
    ldr r0, lbl_0803f158 @ =0x03000738
    mov ip, r0
    ldrh r1, [r0]
    ldr r0, lbl_0803f15c @ =0x0000fffb
    ands r0, r1
    movs r3, #0
    movs r2, #0
    mov r1, ip
    strh r0, [r1]
    mov r4, ip
    adds r4, #0x32
    ldrb r1, [r4]
    movs r0, #4
    orrs r0, r1
    strb r0, [r4]
    mov r0, ip
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0803f160 @ =0x0000fff0
    mov r4, ip
    strh r1, [r4, #0xa]
    movs r0, #0x10
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    ldr r0, lbl_0803f164 @ =0x082fc2c8
    str r0, [r4, #0x18]
    strb r3, [r4, #0x1c]
    strh r2, [r4, #0x16]
    mov r1, ip
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    ldr r2, lbl_0803f168 @ =0x082b1be4
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    mov r0, ip
    adds r0, #0x2f
    strb r3, [r0]
    mov r1, ip
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    adds r1, #1
    movs r0, #6
    strb r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f158: .4byte 0x03000738
lbl_0803f15c: .4byte 0x0000fffb
lbl_0803f160: .4byte 0x0000fff0
lbl_0803f164: .4byte 0x082fc2c8
lbl_0803f168: .4byte 0x082b1be4

    thumb_func_start AcidWormSpitMove
AcidWormSpitMove: @ 0x0803f16c
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0803f1a0 @ =0x03000738
    ldrb r1, [r0, #0x1e]
    adds r4, r0, #0
    cmp r1, #2
    bne lbl_0803f1ac
    movs r6, #2
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r1, [r5]
    ldr r3, lbl_0803f1a4 @ =0x082fab14
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r7, #0
    ldrsh r2, [r0, r7]
    ldr r0, lbl_0803f1a8 @ =0x00007fff
    cmp r2, r0
    bne lbl_0803f210
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r7, [r4, #2]
    adds r0, r0, r7
    b lbl_0803f218
    .align 2, 0
lbl_0803f1a0: .4byte 0x03000738
lbl_0803f1a4: .4byte 0x082fab14
lbl_0803f1a8: .4byte 0x00007fff
lbl_0803f1ac:
    cmp r1, #1
    bne lbl_0803f1e0
    movs r6, #0xa
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r1, [r5]
    ldr r3, lbl_0803f1d8 @ =0x082fab34
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r7, #0
    ldrsh r2, [r0, r7]
    ldr r0, lbl_0803f1dc @ =0x00007fff
    cmp r2, r0
    bne lbl_0803f210
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r7, [r4, #2]
    adds r0, r0, r7
    b lbl_0803f218
    .align 2, 0
lbl_0803f1d8: .4byte 0x082fab34
lbl_0803f1dc: .4byte 0x00007fff
lbl_0803f1e0:
    movs r6, #7
    adds r5, r4, #0
    adds r5, #0x2f
    ldrb r1, [r5]
    ldr r3, lbl_0803f208 @ =0x082fab68
    lsls r0, r1, #1
    adds r0, r0, r3
    movs r7, #0
    ldrsh r2, [r0, r7]
    ldr r0, lbl_0803f20c @ =0x00007fff
    cmp r2, r0
    bne lbl_0803f210
    subs r0, r1, #1
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r7, [r4, #2]
    adds r0, r0, r7
    b lbl_0803f218
    .align 2, 0
lbl_0803f208: .4byte 0x082fab68
lbl_0803f20c: .4byte 0x00007fff
lbl_0803f210:
    adds r0, r1, #1
    strb r0, [r5]
    ldrh r0, [r4, #2]
    adds r0, r0, r2
lbl_0803f218:
    strh r0, [r4, #2]
    ldrh r1, [r4]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0803f22a
    ldrh r0, [r4, #4]
    adds r0, r6, r0
    b lbl_0803f22e
lbl_0803f22a:
    ldrh r0, [r4, #4]
    subs r0, r0, r6
lbl_0803f22e:
    strh r0, [r4, #4]
    adds r3, r4, #0
    ldr r0, lbl_0803f254 @ =0x0300006c
    ldrh r5, [r0]
    ldrh r0, [r3, #2]
    cmp r0, r5
    blo lbl_0803f25c
    movs r1, #0
    movs r2, #0
    strh r5, [r3, #2]
    ldr r0, lbl_0803f258 @ =0x082fc2e8
    str r0, [r3, #0x18]
    strb r1, [r3, #0x1c]
    strh r2, [r3, #0x16]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x45
    b lbl_0803f276
    .align 2, 0
lbl_0803f254: .4byte 0x0300006c
lbl_0803f258: .4byte 0x082fc2e8
lbl_0803f25c:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilCheckCollisionAtPosition
    ldr r0, lbl_0803f280 @ =0x030007f1
    ldrb r1, [r0]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_0803f278
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x42
lbl_0803f276:
    strb r0, [r1]
lbl_0803f278:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f280: .4byte 0x030007f1

    thumb_func_start AcidWormSpitExplodingGFXInit
AcidWormSpitExplodingGFXInit: @ 0x0803f284
    push {lr}
    ldr r2, lbl_0803f2c0 @ =0x03000738
    ldr r0, lbl_0803f2c4 @ =0x082fc2e8
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x43
    strb r0, [r1]
    ldr r0, lbl_0803f2c8 @ =0x03000088
    ldrb r1, [r0, #0xc]
    movs r0, #3
    ands r0, r1
    adds r1, r2, #0
    adds r1, #0x21
    strb r0, [r1]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    movs r0, #0xdc
    lsls r0, r0, #1
    bl SoundPlay
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f2c0: .4byte 0x03000738
lbl_0803f2c4: .4byte 0x082fc2e8
lbl_0803f2c8: .4byte 0x03000088

    thumb_func_start acid_worm_check_exploding_anim_ended
acid_worm_check_exploding_anim_ended: @ 0x0803f2cc
    push {r4, lr}
    ldr r4, lbl_0803f2ec @ =0x03000738
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803f2e4
    movs r0, #0
    strh r0, [r4]
lbl_0803f2e4:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f2ec: .4byte 0x03000738

    thumb_func_start acid_worm_check_exploding_on_acid_anim_ended
acid_worm_check_exploding_on_acid_anim_ended: @ 0x0803f2f0
    push {r4, lr}
    ldr r4, lbl_0803f314 @ =0x03000738
    ldr r0, lbl_0803f318 @ =0x0300006c
    ldrh r0, [r0]
    strh r0, [r4, #2]
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0803f30e
    movs r0, #0
    strh r0, [r4]
lbl_0803f30e:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f314: .4byte 0x03000738
lbl_0803f318: .4byte 0x0300006c

    thumb_func_start AcidWorm
AcidWorm: @ 0x0803f31c
    push {lr}
    ldr r0, lbl_0803f334 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x68
    bls lbl_0803f32a
    b lbl_0803f542
lbl_0803f32a:
    lsls r0, r0, #2
    ldr r1, lbl_0803f338 @ =lbl_0803f33c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0803f334: .4byte 0x03000738
lbl_0803f338: .4byte lbl_0803f33c
lbl_0803f33c: @ jump table
    .4byte lbl_0803f4e0 @ case 0
    .4byte lbl_0803f4e6 @ case 1
    .4byte lbl_0803f542 @ case 2
    .4byte lbl_0803f542 @ case 3
    .4byte lbl_0803f542 @ case 4
    .4byte lbl_0803f542 @ case 5
    .4byte lbl_0803f542 @ case 6
    .4byte lbl_0803f542 @ case 7
    .4byte lbl_0803f504 @ case 8
    .4byte lbl_0803f508 @ case 9
    .4byte lbl_0803f542 @ case 10
    .4byte lbl_0803f542 @ case 11
    .4byte lbl_0803f542 @ case 12
    .4byte lbl_0803f542 @ case 13
    .4byte lbl_0803f542 @ case 14
    .4byte lbl_0803f520 @ case 15
    .4byte lbl_0803f542 @ case 16
    .4byte lbl_0803f542 @ case 17
    .4byte lbl_0803f542 @ case 18
    .4byte lbl_0803f542 @ case 19
    .4byte lbl_0803f542 @ case 20
    .4byte lbl_0803f542 @ case 21
    .4byte lbl_0803f542 @ case 22
    .4byte lbl_0803f542 @ case 23
    .4byte lbl_0803f542 @ case 24
    .4byte lbl_0803f542 @ case 25
    .4byte lbl_0803f542 @ case 26
    .4byte lbl_0803f542 @ case 27
    .4byte lbl_0803f542 @ case 28
    .4byte lbl_0803f542 @ case 29
    .4byte lbl_0803f542 @ case 30
    .4byte lbl_0803f542 @ case 31
    .4byte lbl_0803f542 @ case 32
    .4byte lbl_0803f542 @ case 33
    .4byte lbl_0803f542 @ case 34
    .4byte lbl_0803f50e @ case 35
    .4byte lbl_0803f542 @ case 36
    .4byte lbl_0803f514 @ case 37
    .4byte lbl_0803f542 @ case 38
    .4byte lbl_0803f51a @ case 39
    .4byte lbl_0803f542 @ case 40
    .4byte lbl_0803f526 @ case 41
    .4byte lbl_0803f542 @ case 42
    .4byte lbl_0803f52c @ case 43
    .4byte lbl_0803f542 @ case 44
    .4byte lbl_0803f542 @ case 45
    .4byte lbl_0803f542 @ case 46
    .4byte lbl_0803f542 @ case 47
    .4byte lbl_0803f542 @ case 48
    .4byte lbl_0803f542 @ case 49
    .4byte lbl_0803f542 @ case 50
    .4byte lbl_0803f542 @ case 51
    .4byte lbl_0803f542 @ case 52
    .4byte lbl_0803f542 @ case 53
    .4byte lbl_0803f542 @ case 54
    .4byte lbl_0803f542 @ case 55
    .4byte lbl_0803f542 @ case 56
    .4byte lbl_0803f542 @ case 57
    .4byte lbl_0803f542 @ case 58
    .4byte lbl_0803f542 @ case 59
    .4byte lbl_0803f542 @ case 60
    .4byte lbl_0803f542 @ case 61
    .4byte lbl_0803f542 @ case 62
    .4byte lbl_0803f542 @ case 63
    .4byte lbl_0803f542 @ case 64
    .4byte lbl_0803f542 @ case 65
    .4byte lbl_0803f4ec @ case 66
    .4byte lbl_0803f4f2 @ case 67
    .4byte lbl_0803f542 @ case 68
    .4byte lbl_0803f4f8 @ case 69
    .4byte lbl_0803f542 @ case 70
    .4byte lbl_0803f4fe @ case 71
    .4byte lbl_0803f542 @ case 72
    .4byte lbl_0803f542 @ case 73
    .4byte lbl_0803f542 @ case 74
    .4byte lbl_0803f542 @ case 75
    .4byte lbl_0803f542 @ case 76
    .4byte lbl_0803f542 @ case 77
    .4byte lbl_0803f542 @ case 78
    .4byte lbl_0803f542 @ case 79
    .4byte lbl_0803f542 @ case 80
    .4byte lbl_0803f542 @ case 81
    .4byte lbl_0803f542 @ case 82
    .4byte lbl_0803f542 @ case 83
    .4byte lbl_0803f542 @ case 84
    .4byte lbl_0803f542 @ case 85
    .4byte lbl_0803f542 @ case 86
    .4byte lbl_0803f542 @ case 87
    .4byte lbl_0803f542 @ case 88
    .4byte lbl_0803f542 @ case 89
    .4byte lbl_0803f542 @ case 90
    .4byte lbl_0803f542 @ case 91
    .4byte lbl_0803f542 @ case 92
    .4byte lbl_0803f542 @ case 93
    .4byte lbl_0803f542 @ case 94
    .4byte lbl_0803f542 @ case 95
    .4byte lbl_0803f542 @ case 96
    .4byte lbl_0803f542 @ case 97
    .4byte lbl_0803f532 @ case 98
    .4byte lbl_0803f542 @ case 99
    .4byte lbl_0803f542 @ case 100
    .4byte lbl_0803f542 @ case 101
    .4byte lbl_0803f542 @ case 102
    .4byte lbl_0803f538 @ case 103
    .4byte lbl_0803f53e @ case 104
lbl_0803f4e0:
    bl AcidWormInit
    b lbl_0803f542
lbl_0803f4e6:
    bl AcidWormCheckSamusOnZipline
    b lbl_0803f542
lbl_0803f4ec:
    bl AcidWormSpawnStart
    b lbl_0803f542
lbl_0803f4f2:
    bl AcidWormSpawnExtending
    b lbl_0803f542
lbl_0803f4f8:
    bl AcidWormSpawnStayingOnTop
    b lbl_0803f542
lbl_0803f4fe:
    bl AcidWormSpawnRetracting
    b lbl_0803f542
lbl_0803f504:
    bl sub_0803e004
lbl_0803f508:
    bl AcidWormIdle
    b lbl_0803f542
lbl_0803f50e:
    bl acid_worm_check_end_warning_anim
    b lbl_0803f542
lbl_0803f514:
    bl AcidWormExtend
    b lbl_0803f542
lbl_0803f51a:
    bl AcidWormRetracting
    b lbl_0803f542
lbl_0803f520:
    bl AcidWormExtended
    b lbl_0803f542
lbl_0803f526:
    bl AcidWormRaiseAcid
    b lbl_0803f542
lbl_0803f52c:
    bl AcidWormAcidGoDown
    b lbl_0803f542
lbl_0803f532:
    bl AcidWormDeathGFXInit
    b lbl_0803f542
lbl_0803f538:
    bl AcidWormDeathFlashingAnim
    b lbl_0803f542
lbl_0803f53e:
    bl AcidWormDying
lbl_0803f542:
    ldr r0, lbl_0803f564 @ =0x0300070c
    ldrb r1, [r0, #0xe]
    cmp r1, #0
    beq lbl_0803f574
    ldr r1, lbl_0803f568 @ =0x03000100
    movs r0, #2
    strb r0, [r1]
    ldr r2, lbl_0803f56c @ =0x03000738
    ldr r3, lbl_0803f570 @ =0xffffff00
    adds r0, r3, #0
    ldrh r3, [r2, #6]
    adds r0, r0, r3
    strh r0, [r1, #4]
    ldrh r0, [r2, #8]
    strh r0, [r1, #2]
    b lbl_0803f578
    .align 2, 0
lbl_0803f564: .4byte 0x0300070c
lbl_0803f568: .4byte 0x03000100
lbl_0803f56c: .4byte 0x03000738
lbl_0803f570: .4byte 0xffffff00
lbl_0803f574:
    ldr r0, lbl_0803f57c @ =0x03000100
    strb r1, [r0]
lbl_0803f578:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0803f57c: .4byte 0x03000100

    thumb_func_start AcidWormBody
AcidWormBody: @ 0x0803f580
    push {r4, r5, r6, lr}
    ldr r3, lbl_0803f5d4 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r1, [r0]
    ldr r2, lbl_0803f5d8 @ =0x030001ac
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r2, r0, r2
    adds r5, r2, #0
    adds r5, #0x34
    ldrb r6, [r5]
    adds r0, r3, #0
    adds r0, #0x34
    strb r6, [r0]
    adds r0, r2, #0
    adds r0, #0x20
    ldrb r4, [r0]
    ldrb r1, [r2, #0x1f]
    adds r0, #0x13
    ldrb r0, [r0]
    adds r1, r1, r0
    movs r0, #0xe
    subs r0, r0, r1
    adds r2, r3, #0
    cmp r4, r0
    bne lbl_0803f5dc
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
    ldrb r0, [r2, #0x1c]
    adds r0, #1
    strb r0, [r2, #0x1c]
    b lbl_0803f5e8
    .align 2, 0
lbl_0803f5d4: .4byte 0x03000738
lbl_0803f5d8: .4byte 0x030001ac
lbl_0803f5dc:
    ldrb r5, [r5]
    cmp r4, r5
    bne lbl_0803f5e8
    adds r0, r2, #0
    adds r0, #0x20
    strb r6, [r0]
lbl_0803f5e8:
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x43
    beq lbl_0803f60c
    cmp r0, #0x43
    bgt lbl_0803f600
    cmp r0, #0
    beq lbl_0803f606
    cmp r0, #9
    beq lbl_0803f612
    b lbl_0803f61c
lbl_0803f600:
    cmp r0, #0x67
    beq lbl_0803f618
    b lbl_0803f61c
lbl_0803f606:
    bl AcidWormBodyInit
    b lbl_0803f61c
lbl_0803f60c:
    bl AcidWormBodyMove
    b lbl_0803f61c
lbl_0803f612:
    bl AcidWormBodyMainLoop
    b lbl_0803f61c
lbl_0803f618:
    bl AcidWormBodyDeath
lbl_0803f61c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AcidWormSpit
AcidWormSpit: @ 0x0803f624
    push {lr}
    sub sp, #4
    ldr r1, lbl_0803f648 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r2, r1, #0
    cmp r0, #0x43
    beq lbl_0803f662
    cmp r0, #0x43
    bgt lbl_0803f64c
    cmp r0, #0x42
    beq lbl_0803f65e
    cmp r0, #0
    beq lbl_0803f652
    cmp r0, #9
    beq lbl_0803f658
    b lbl_0803f66e
    .align 2, 0
lbl_0803f648: .4byte 0x03000738
lbl_0803f64c:
    cmp r0, #0x45
    beq lbl_0803f668
    b lbl_0803f66e
lbl_0803f652:
    bl AcidWormSpitInit
    b lbl_0803f67e
lbl_0803f658:
    bl AcidWormSpitMove
    b lbl_0803f67e
lbl_0803f65e:
    bl AcidWormSpitExplodingGFXInit
lbl_0803f662:
    bl acid_worm_check_exploding_anim_ended
    b lbl_0803f67e
lbl_0803f668:
    bl acid_worm_check_exploding_on_acid_anim_ended
    b lbl_0803f67e
lbl_0803f66e:
    ldrh r1, [r2, #2]
    ldrh r2, [r2, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
lbl_0803f67e:
    add sp, #4
    pop {r0}
    bx r0
    