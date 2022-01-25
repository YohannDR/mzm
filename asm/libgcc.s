    .include "asm/macros.inc"

    thumb_func_start _call_via_r0
_call_via_r0:
    bx r0
    nop

    .globl _call_via_r1
    .type _call_via_r1, %function
_call_via_r1:
    bx r1
    nop

    .globl _call_via_r2
    .type _call_via_r2, %function
_call_via_r2:
    bx r2
    nop

    .globl _call_via_r3
    .type _call_via_r3, %function
_call_via_r3:
    bx r3
    nop

    .globl _call_via_r4
    .type _call_via_r4, %function
_call_via_r4:
    bx r4
    nop

    .globl _call_via_r5
    .type _call_via_r5, %function
_call_via_r5:
    bx r5
    nop

    .globl _call_via_r6
    .type _call_via_r6, %function
_call_via_r6:
    bx r6
    nop

    .globl _call_via_r7
    .type _call_via_r7, %function
_call_via_r7:
    bx r7
    nop

    .globl _call_via_r8
    .type _call_via_r8, %function
_call_via_r8:
    bx r8
    nop

    .globl _call_via_r9
    .type _call_via_r9, %function
_call_via_r9:
    bx r9
    nop

    .globl _call_via_sl
    .type _call_via_sl, %function
_call_via_sl:
    bx sl
    nop

    .globl _call_via_fp
    .type _call_via_fp, %function
_call_via_fp:
    bx fp
    nop

    .globl _call_via_ip
    .type _call_via_ip, %function
_call_via_ip:
    bx ip
    nop

    .globl _call_via_sp
    .type _call_via_sp, %function
_call_via_sp:
    bx sp
    nop

    .globl _call_via_lr
    .type _call_via_lr, %function
_call_via_lr:
    bx lr
    nop

    @ TODO: division stuff
