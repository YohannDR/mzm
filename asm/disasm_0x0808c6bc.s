    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start memcpy
memcpy: @ 0x0808c6bc
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r5, #0
    adds r3, r1, #0
    cmp r2, #0xf
    bls lbl_0808c6fc
    adds r0, r3, #0
    orrs r0, r5
    movs r1, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0808c6fc
    adds r1, r5, #0
lbl_0808c6d6:
    ldm r3!, {r0}
    stm r1!, {r0}
    ldm r3!, {r0}
    stm r1!, {r0}
    ldm r3!, {r0}
    stm r1!, {r0}
    ldm r3!, {r0}
    stm r1!, {r0}
    subs r2, #0x10
    cmp r2, #0xf
    bhi lbl_0808c6d6
    cmp r2, #3
    bls lbl_0808c6fa
lbl_0808c6f0:
    ldm r3!, {r0}
    stm r1!, {r0}
    subs r2, #4
    cmp r2, #3
    bhi lbl_0808c6f0
lbl_0808c6fa:
    adds r4, r1, #0
lbl_0808c6fc:
    subs r2, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r2, r0
    beq lbl_0808c716
    adds r1, r0, #0
lbl_0808c708:
    ldrb r0, [r3]
    strb r0, [r4]
    adds r3, #1
    adds r4, #1
    subs r2, #1
    cmp r2, r1
    bne lbl_0808c708
lbl_0808c716:
    adds r0, r5, #0
    pop {r4, r5, pc}
    .align 2, 0
