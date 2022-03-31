    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_080051d4
sub_080051d4: @ 0x080051d4
    push {r4, lr}
    adds r4, r0, #0
    subs r3, r2, #1
    cmp r2, #0
    beq lbl_080051f0
    movs r2, #1
    rsbs r2, r2, #0
lbl_080051e2:
    ldrb r0, [r4]
    strb r0, [r1]
    adds r4, #1
    adds r1, #1
    subs r3, #1
    cmp r3, r2
    bne lbl_080051e2
lbl_080051f0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080051f8
sub_080051f8: @ 0x080051f8
    push {r4, r5, r6, lr}
    sub sp, #0x80
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r2, lbl_08005224 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_08005228 @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    ldr r3, lbl_0800522c @ =sub_080051d4
    movs r0, #1
    bics r3, r0
    mov r2, sp
    ldr r0, lbl_08005230 @ =sub_080051f8
    ldr r1, lbl_0800522c @ =sub_080051d4
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b lbl_08005240
    .align 2, 0
lbl_08005224: .4byte 0x04000204
lbl_08005228: .4byte 0x0000fffc
lbl_0800522c: .4byte sub_080051d4
lbl_08005230: .4byte sub_080051f8
lbl_08005234:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
lbl_08005240:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne lbl_08005234
    mov r3, sp
    adds r3, #1
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl _call_via_r3
    add sp, #0x80
    pop {r4, r5, r6}
    pop {r0}
    bx r0
