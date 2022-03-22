    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start multiply_decimal
multiply_decimal: @ 0x08000a4c
    push {lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    asrs r0, r0, #0x10
    muls r0, r1, r0
    adds r1, r0, #0
    cmp r0, #0
    bge lbl_08000a60
    adds r1, #0xff
lbl_08000a60:
    lsls r0, r1, #8
    asrs r0, r0, #0x10
    pop {r1}
    bx r1

    thumb_func_start div_signed_multiply_unused
div_signed_multiply_unused: @ 0x08000a68
    push {lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    asrs r0, r0, #8
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start div_10000_by
div_10000_by: @ 0x08000a80
    push {lr}
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    movs r0, #0x80
    lsls r0, r0, #9
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    pop {r1}
    bx r1
