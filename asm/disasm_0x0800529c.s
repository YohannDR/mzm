    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_0800529c
sub_0800529c: @ 0x0800529c
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r3, r1, #0
    subs r4, r2, #1
    cmp r2, #0
    beq lbl_080052c2
    movs r2, #1
    rsbs r2, r2, #0
lbl_080052ac:
    ldrb r1, [r3]
    ldrb r0, [r5]
    adds r5, #1
    adds r3, #1
    cmp r1, r0
    beq lbl_080052bc
    subs r0, r3, #1
    b lbl_080052c4
lbl_080052bc:
    subs r4, #1
    cmp r4, r2
    bne lbl_080052ac
lbl_080052c2:
    movs r0, #0
lbl_080052c4:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
