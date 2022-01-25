    .include "asm/macros.inc"

    thumb_func_start _call_via_r0
_call_via_r0:
    bx r0
    nop

    thumb_func_start _call_via_r1
_call_via_r1:
    bx r1
    nop

    thumb_func_start _call_via_r2
_call_via_r2:
    bx r2
    nop

    thumb_func_start _call_via_r3
_call_via_r3:
    bx r3
    nop

    thumb_func_start _call_via_r4
_call_via_r4:
    bx r4
    nop

    thumb_func_start _call_via_r5
_call_via_r5:
    bx r5
    nop

    thumb_func_start _call_via_r6
_call_via_r6:
    bx r6
    nop

    thumb_func_start _call_via_r7
_call_via_r7:
    bx r7
    nop

    thumb_func_start _call_via_r8
_call_via_r8:
    bx r8
    nop

    thumb_func_start _call_via_r9
_call_via_r9:
    bx r9
    nop

    thumb_func_start _call_via_sl
_call_via_sl:
    bx sl
    nop

    thumb_func_start _call_via_fp
_call_via_fp:
    bx fp
    nop

    thumb_func_start _call_via_ip
_call_via_ip:
    bx ip
    nop

    thumb_func_start _call_via_sp
_call_via_sp:
    bx sp
    nop

    thumb_func_start _call_via_lr
_call_via_lr:
    bx lr
    nop

    @ TODO: division stuff
