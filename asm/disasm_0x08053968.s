    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start EscapeDetermineTimer
EscapeDetermineTimer: @ 0x08053968
    push {lr}
    movs r0, #3
    movs r1, #0x41
    bl EventFunction
    cmp r0, #0
    bne lbl_08053986
    movs r0, #3
    movs r1, #0x27
    bl EventFunction
    cmp r0, #0
    beq lbl_080539a2
    movs r0, #1
    b lbl_080539a4
lbl_08053986:
    movs r0, #3
    movs r1, #0x4b
    bl EventFunction
    cmp r0, #0
    bne lbl_080539a2
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    cmp r0, #0
    beq lbl_080539a2
    movs r0, #2
    b lbl_080539a4
lbl_080539a2:
    movs r0, #0
lbl_080539a4:
    pop {r1}
    bx r1

    thumb_func_start EscapeCheckHasEscaped
EscapeCheckHasEscaped: @ 0x080539a8
    push {lr}
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    cmp r0, #0
    beq lbl_080539bc
    movs r0, #3
    movs r1, #0x4b
    b lbl_080539cc
lbl_080539bc:
    movs r0, #3
    movs r1, #0x27
    bl EventFunction
    cmp r0, #0
    beq lbl_080539d8
    movs r0, #3
    movs r1, #0x41
lbl_080539cc:
    bl EventFunction
    cmp r0, #0
    beq lbl_080539d8
    movs r0, #1
    b lbl_080539da
lbl_080539d8:
    movs r0, #0
lbl_080539da:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start EscapeUpdateOAM
EscapeUpdateOAM: @ 0x080539e0
    movs r2, #0xcf
    lsls r2, r2, #6
    ldr r3, lbl_08053a10 @ =0x03000964
    ldr r1, lbl_08053a14 @ =0x0300095e
    ldrb r0, [r1]
    adds r0, r0, r2
    strh r0, [r3, #0x30]
    ldrb r0, [r1, #1]
    adds r0, r0, r2
    strh r0, [r3, #0x2a]
    ldrb r0, [r1, #2]
    adds r0, r0, r2
    strh r0, [r3, #0x1e]
    ldrb r0, [r1, #3]
    adds r0, r0, r2
    strh r0, [r3, #0x18]
    ldrb r0, [r1, #4]
    adds r0, r0, r2
    strh r0, [r3, #0xc]
    ldrb r0, [r1, #5]
    adds r0, r0, r2
    strh r0, [r3, #6]
    bx lr
    .align 2, 0
lbl_08053a10: .4byte 0x03000964
lbl_08053a14: .4byte 0x0300095e

    thumb_func_start EscapeCheckReloadGraphics
EscapeCheckReloadGraphics: @ 0x08053a18
    push {lr}
    bl EscapeDetermineTimer
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08053a34
    ldr r1, lbl_08053a38 @ =0x040000d4
    ldr r0, lbl_08053a3c @ =0x0833d794
    str r0, [r1]
    ldr r0, lbl_08053a40 @ =0x06017800
    str r0, [r1, #4]
    ldr r0, lbl_08053a44 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08053a34:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08053a38: .4byte 0x040000d4
lbl_08053a3c: .4byte 0x0833d794
lbl_08053a40: .4byte 0x06017800
lbl_08053a44: .4byte 0x80000400

    thumb_func_start EscapeStart
EscapeStart: @ 0x08053a48
    push {lr}
    ldr r1, lbl_08053a88 @ =0x040000d4
    ldr r2, lbl_08053a8c @ =0x0833d794
    str r2, [r1]
    ldr r0, lbl_08053a90 @ =0x06017800
    str r0, [r1, #4]
    ldr r3, lbl_08053a94 @ =0x800000b0
    str r3, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0x80
    lsls r0, r0, #3
    adds r2, r2, r0
    str r2, [r1]
    ldr r0, lbl_08053a98 @ =0x06017c00
    str r0, [r1, #4]
    str r3, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08053a9c @ =0x0833df94
    str r0, [r1]
    ldr r0, lbl_08053aa0 @ =0x03000964
    str r0, [r1, #4]
    ldr r0, lbl_08053aa4 @ =0x80000019
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #2
    movs r1, #0x8d
    movs r2, #0x3c
    bl ParticleSet
    pop {r0}
    bx r0
    .align 2, 0
lbl_08053a88: .4byte 0x040000d4
lbl_08053a8c: .4byte 0x0833d794
lbl_08053a90: .4byte 0x06017800
lbl_08053a94: .4byte 0x800000b0
lbl_08053a98: .4byte 0x06017c00
lbl_08053a9c: .4byte 0x0833df94
lbl_08053aa0: .4byte 0x03000964
lbl_08053aa4: .4byte 0x80000019

    thumb_func_start EscapeSetTimer
EscapeSetTimer: @ 0x08053aa8
    push {lr}
    bl EscapeDetermineTimer
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r1, lbl_08053ad4 @ =0x0300095d
    movs r0, #0xff
    strb r0, [r1]
    cmp r3, #1
    bne lbl_08053b10
    ldr r0, lbl_08053ad8 @ =0x0300002c
    ldrb r2, [r0]
    cmp r2, #0
    bne lbl_08053ae0
    ldr r0, lbl_08053adc @ =0x0300095e
    strb r2, [r0]
    strb r2, [r0, #1]
    strb r2, [r0, #2]
    strb r2, [r0, #3]
    movs r1, #3
    b lbl_08053b42
    .align 2, 0
lbl_08053ad4: .4byte 0x0300095d
lbl_08053ad8: .4byte 0x0300002c
lbl_08053adc: .4byte 0x0300095e
lbl_08053ae0:
    cmp r2, #2
    bne lbl_08053afc
    ldr r0, lbl_08053af8 @ =0x0300095e
    movs r1, #0
    strb r1, [r0]
    strb r1, [r0, #1]
    strb r1, [r0, #2]
    strb r1, [r0, #3]
    strb r3, [r0, #4]
    strb r1, [r0, #5]
    b lbl_08053b5c
    .align 2, 0
lbl_08053af8: .4byte 0x0300095e
lbl_08053afc:
    ldr r0, lbl_08053b0c @ =0x0300095e
    movs r2, #0
    strb r2, [r0]
    strb r2, [r0, #1]
    strb r2, [r0, #2]
    strb r2, [r0, #3]
    movs r1, #2
    b lbl_08053b42
    .align 2, 0
lbl_08053b0c: .4byte 0x0300095e
lbl_08053b10:
    cmp r3, #2
    bne lbl_08053b4c
    ldr r0, lbl_08053b2c @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_08053b34
    ldr r0, lbl_08053b30 @ =0x0300095e
    movs r2, #0
    strb r2, [r0]
    strb r2, [r0, #1]
    strb r2, [r0, #2]
    strb r2, [r0, #3]
    movs r1, #3
    b lbl_08053b42
    .align 2, 0
lbl_08053b2c: .4byte 0x0300002c
lbl_08053b30: .4byte 0x0300095e
lbl_08053b34:
    ldr r0, lbl_08053b48 @ =0x0300095e
    movs r2, #0
    strb r2, [r0]
    strb r2, [r0, #1]
    strb r2, [r0, #2]
    strb r2, [r0, #3]
    movs r1, #5
lbl_08053b42:
    strb r1, [r0, #4]
    strb r2, [r0, #5]
    b lbl_08053b5c
    .align 2, 0
lbl_08053b48: .4byte 0x0300095e
lbl_08053b4c:
    ldr r1, lbl_08053b60 @ =0x0300095e
    movs r0, #9
    strb r0, [r1]
    strb r0, [r1, #1]
    strb r0, [r1, #2]
    strb r0, [r1, #3]
    strb r0, [r1, #4]
    strb r0, [r1, #5]
lbl_08053b5c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08053b60: .4byte 0x0300095e

    thumb_func_start EscaepUpdateTimer
EscaepUpdateTimer: @ 0x08053b64
    push {r4, r5, lr}
    bl EscapeDetermineTimer
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08053b7a
    ldr r0, lbl_08053b84 @ =0x0300095c
    ldrb r2, [r0]
    adds r5, r0, #0
    cmp r2, #1
    beq lbl_08053b88
lbl_08053b7a:
    ldr r1, lbl_08053b84 @ =0x0300095c
    movs r0, #0
    strb r0, [r1]
    b lbl_08053c60
    .align 2, 0
lbl_08053b84: .4byte 0x0300095c
lbl_08053b88:
    ldr r0, lbl_08053bbc @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_08053c60
    ldr r0, lbl_08053bc0 @ =0x03001606
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08053c60
    ldr r1, lbl_08053bc4 @ =0x0300095d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ands r2, r4
    cmp r2, #0
    beq lbl_08053bde
    ldr r0, lbl_08053bc8 @ =0x0300095e
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #1
    bls lbl_08053bcc
    subs r0, r1, #2
    strb r0, [r3]
    b lbl_08053c06
    .align 2, 0
lbl_08053bbc: .4byte 0x03000c72
lbl_08053bc0: .4byte 0x03001606
lbl_08053bc4: .4byte 0x0300095d
lbl_08053bc8: .4byte 0x0300095e
lbl_08053bcc:
    adds r0, r1, #0
    adds r0, #8
    strb r0, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08053bfe
    movs r0, #9
    strb r0, [r3, #1]
    b lbl_08053c06
lbl_08053bde:
    ldr r0, lbl_08053bf0 @ =0x0300095e
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08053bf4
    subs r0, r1, #1
    strb r0, [r3]
    b lbl_08053c06
    .align 2, 0
lbl_08053bf0: .4byte 0x0300095e
lbl_08053bf4:
    movs r1, #9
    strb r1, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #0
    beq lbl_08053c04
lbl_08053bfe:
    subs r0, #1
    strb r0, [r3, #1]
    b lbl_08053c06
lbl_08053c04:
    strb r1, [r3, #1]
lbl_08053c06:
    movs r0, #0x3f
    ands r0, r4
    cmp r0, #0
    bne lbl_08053c60
    adds r2, r3, #0
    movs r1, #9
    strb r1, [r2]
    strb r1, [r2, #1]
    ldrb r0, [r2, #2]
    cmp r0, #0
    beq lbl_08053c22
    subs r0, #1
    strb r0, [r2, #2]
    b lbl_08053c60
lbl_08053c22:
    strb r1, [r2, #2]
    ldrb r0, [r2, #3]
    cmp r0, #0
    beq lbl_08053c30
    subs r0, #1
    strb r0, [r2, #3]
    b lbl_08053c60
lbl_08053c30:
    movs r0, #5
    strb r0, [r2, #3]
    ldrb r0, [r2, #4]
    cmp r0, #0
    beq lbl_08053c40
    subs r0, #1
    strb r0, [r2, #4]
    b lbl_08053c60
lbl_08053c40:
    strb r1, [r2, #4]
    ldrb r0, [r2, #5]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08053c50
    subs r0, #1
    strb r0, [r2, #5]
    b lbl_08053c60
lbl_08053c50:
    strb r1, [r3]
    strb r1, [r3, #1]
    strb r1, [r3, #2]
    strb r1, [r3, #3]
    strb r1, [r3, #4]
    strb r1, [r3, #5]
    movs r0, #2
    strb r0, [r5]
lbl_08053c60:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
