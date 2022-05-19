    .include "asm/macros.inc"

    .syntax unified

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

    thumb_func_start __divsi3
__divsi3: @ 0x0808ac34
    cmp r1, #0
    beq lbl_0808acbc
    push {r4}
    adds r4, r0, #0
    eors r4, r1
    mov ip, r4
    movs r3, #1
    movs r2, #0
    cmp r1, #0
    bpl lbl_0808ac4a
    rsbs r1, r1, #0
lbl_0808ac4a:
    cmp r0, #0
    bpl lbl_0808ac50
    rsbs r0, r0, #0
lbl_0808ac50:
    cmp r0, r1
    blo lbl_0808acae
    movs r4, #1
    lsls r4, r4, #0x1c
lbl_0808ac58:
    cmp r1, r4
    bhs lbl_0808ac66
    cmp r1, r0
    bhs lbl_0808ac66
    lsls r1, r1, #4
    lsls r3, r3, #4
    b lbl_0808ac58
lbl_0808ac66:
    lsls r4, r4, #3
lbl_0808ac68:
    cmp r1, r4
    bhs lbl_0808ac76
    cmp r1, r0
    bhs lbl_0808ac76
    lsls r1, r1, #1
    lsls r3, r3, #1
    b lbl_0808ac68
lbl_0808ac76:
    cmp r0, r1
    blo lbl_0808ac7e
    subs r0, r0, r1
    orrs r2, r3
lbl_0808ac7e:
    lsrs r4, r1, #1
    cmp r0, r4
    blo lbl_0808ac8a
    subs r0, r0, r4
    lsrs r4, r3, #1
    orrs r2, r4
lbl_0808ac8a:
    lsrs r4, r1, #2
    cmp r0, r4
    blo lbl_0808ac96
    subs r0, r0, r4
    lsrs r4, r3, #2
    orrs r2, r4
lbl_0808ac96:
    lsrs r4, r1, #3
    cmp r0, r4
    blo lbl_0808aca2
    subs r0, r0, r4
    lsrs r4, r3, #3
    orrs r2, r4
lbl_0808aca2:
    cmp r0, #0
    beq lbl_0808acae
    lsrs r3, r3, #4
    beq lbl_0808acae
    lsrs r1, r1, #4
    b lbl_0808ac76
lbl_0808acae:
    adds r0, r2, #0
    mov r4, ip
    cmp r4, #0
    bpl lbl_0808acb8
    rsbs r0, r0, #0
lbl_0808acb8:
    pop {r4}
    mov pc, lr
lbl_0808acbc:
    push {lr}
    bl __div_by_zero
    movs r0, #0
    pop {pc}
    .align 2, 0

    thumb_func_start __div_by_zero
__div_by_zero: @ 0x0808acc8
    mov pc, lr
    .align 2, 0

    thumb_func_start sub_0808accc
sub_0808accc: @ 0x0808accc
    push {r4, r5, lr}
    adds r5, r1, #0
    adds r4, r0, #0
    ldr r3, lbl_0808acec @ =0x00000000
    ldr r2, lbl_0808ace8 @ =0x41e00000
    bl __gedf2
    cmp r0, #0
    bge lbl_0808acf0
    adds r1, r5, #0
    adds r0, r4, #0
    bl __fixdfsi
    b lbl_0808ad06
    .align 2, 0
lbl_0808ace8: .4byte 0x41e00000
lbl_0808acec: .4byte 0x00000000
lbl_0808acf0:
    ldr r3, lbl_0808ad0c @ =0x00000000
    ldr r2, lbl_0808ad08 @ =0xc1e00000
    adds r1, r5, #0
    adds r0, r4, #0
    bl __adddf3
    bl __fixdfsi
    movs r1, #0x80
    lsls r1, r1, #0x18
    adds r0, r0, r1
lbl_0808ad06:
    pop {r4, r5, pc}
    .align 2, 0
lbl_0808ad08: .4byte 0xc1e00000
lbl_0808ad0c: .4byte 0x00000000

    thumb_func_start __modsi3
__modsi3: @ 0x0808ad10
    movs r3, #1
    cmp r1, #0
    beq lbl_0808add4
    bpl lbl_0808ad1a
    rsbs r1, r1, #0
lbl_0808ad1a:
    push {r4}
    push {r0}
    cmp r0, #0
    bpl lbl_0808ad24
    rsbs r0, r0, #0
lbl_0808ad24:
    cmp r0, r1
    blo lbl_0808adc8
    movs r4, #1
    lsls r4, r4, #0x1c
lbl_0808ad2c:
    cmp r1, r4
    bhs lbl_0808ad3a
    cmp r1, r0
    bhs lbl_0808ad3a
    lsls r1, r1, #4
    lsls r3, r3, #4
    b lbl_0808ad2c
lbl_0808ad3a:
    lsls r4, r4, #3
lbl_0808ad3c:
    cmp r1, r4
    bhs lbl_0808ad4a
    cmp r1, r0
    bhs lbl_0808ad4a
    lsls r1, r1, #1
    lsls r3, r3, #1
    b lbl_0808ad3c
lbl_0808ad4a:
    movs r2, #0
    cmp r0, r1
    blo lbl_0808ad52
    subs r0, r0, r1
lbl_0808ad52:
    lsrs r4, r1, #1
    cmp r0, r4
    blo lbl_0808ad64
    subs r0, r0, r4
    mov ip, r3
    movs r4, #1
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808ad64:
    lsrs r4, r1, #2
    cmp r0, r4
    blo lbl_0808ad76
    subs r0, r0, r4
    mov ip, r3
    movs r4, #2
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808ad76:
    lsrs r4, r1, #3
    cmp r0, r4
    blo lbl_0808ad88
    subs r0, r0, r4
    mov ip, r3
    movs r4, #3
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808ad88:
    mov ip, r3
    cmp r0, #0
    beq lbl_0808ad96
    lsrs r3, r3, #4
    beq lbl_0808ad96
    lsrs r1, r1, #4
    b lbl_0808ad4a
lbl_0808ad96:
    movs r4, #0xe
    lsls r4, r4, #0x1c
    ands r2, r4
    beq lbl_0808adc8
    mov r3, ip
    movs r4, #3
    rors r3, r4
    tst r2, r3
    beq lbl_0808adac
    lsrs r4, r1, #3
    adds r0, r0, r4
lbl_0808adac:
    mov r3, ip
    movs r4, #2
    rors r3, r4
    tst r2, r3
    beq lbl_0808adba
    lsrs r4, r1, #2
    adds r0, r0, r4
lbl_0808adba:
    mov r3, ip
    movs r4, #1
    rors r3, r4
    tst r2, r3
    beq lbl_0808adc8
    lsrs r4, r1, #1
    adds r0, r0, r4
lbl_0808adc8:
    pop {r4}
    cmp r4, #0
    bpl lbl_0808add0
    rsbs r0, r0, #0
lbl_0808add0:
    pop {r4}
    mov pc, lr
lbl_0808add4:
    push {lr}
    bl __div_by_zero
    movs r0, #0
    pop {pc}
    .align 2, 0

    thumb_func_start __udivsi3
__udivsi3: @ 0x0808ade0
    cmp r1, #0
    beq lbl_0808ae4e
    movs r3, #1
    movs r2, #0
    push {r4}
    cmp r0, r1
    blo lbl_0808ae48
    movs r4, #1
    lsls r4, r4, #0x1c
lbl_0808adf2:
    cmp r1, r4
    bhs lbl_0808ae00
    cmp r1, r0
    bhs lbl_0808ae00
    lsls r1, r1, #4
    lsls r3, r3, #4
    b lbl_0808adf2
lbl_0808ae00:
    lsls r4, r4, #3
lbl_0808ae02:
    cmp r1, r4
    bhs lbl_0808ae10
    cmp r1, r0
    bhs lbl_0808ae10
    lsls r1, r1, #1
    lsls r3, r3, #1
    b lbl_0808ae02
lbl_0808ae10:
    cmp r0, r1
    blo lbl_0808ae18
    subs r0, r0, r1
    orrs r2, r3
lbl_0808ae18:
    lsrs r4, r1, #1
    cmp r0, r4
    blo lbl_0808ae24
    subs r0, r0, r4
    lsrs r4, r3, #1
    orrs r2, r4
lbl_0808ae24:
    lsrs r4, r1, #2
    cmp r0, r4
    blo lbl_0808ae30
    subs r0, r0, r4
    lsrs r4, r3, #2
    orrs r2, r4
lbl_0808ae30:
    lsrs r4, r1, #3
    cmp r0, r4
    blo lbl_0808ae3c
    subs r0, r0, r4
    lsrs r4, r3, #3
    orrs r2, r4
lbl_0808ae3c:
    cmp r0, #0
    beq lbl_0808ae48
    lsrs r3, r3, #4
    beq lbl_0808ae48
    lsrs r1, r1, #4
    b lbl_0808ae10
lbl_0808ae48:
    adds r0, r2, #0
    pop {r4}
    mov pc, lr
lbl_0808ae4e:
    push {lr}
    bl __div_by_zero
    movs r0, #0
    pop {pc}

    thumb_func_start __umodsi3
__umodsi3: @ 0x0808ae58
    cmp r1, #0
    beq lbl_0808af0e
    movs r3, #1
    cmp r0, r1
    bhs lbl_0808ae64
    mov pc, lr
lbl_0808ae64:
    push {r4}
    movs r4, #1
    lsls r4, r4, #0x1c
lbl_0808ae6a:
    cmp r1, r4
    bhs lbl_0808ae78
    cmp r1, r0
    bhs lbl_0808ae78
    lsls r1, r1, #4
    lsls r3, r3, #4
    b lbl_0808ae6a
lbl_0808ae78:
    lsls r4, r4, #3
lbl_0808ae7a:
    cmp r1, r4
    bhs lbl_0808ae88
    cmp r1, r0
    bhs lbl_0808ae88
    lsls r1, r1, #1
    lsls r3, r3, #1
    b lbl_0808ae7a
lbl_0808ae88:
    movs r2, #0
    cmp r0, r1
    blo lbl_0808ae90
    subs r0, r0, r1
lbl_0808ae90:
    lsrs r4, r1, #1
    cmp r0, r4
    blo lbl_0808aea2
    subs r0, r0, r4
    mov ip, r3
    movs r4, #1
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808aea2:
    lsrs r4, r1, #2
    cmp r0, r4
    blo lbl_0808aeb4
    subs r0, r0, r4
    mov ip, r3
    movs r4, #2
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808aeb4:
    lsrs r4, r1, #3
    cmp r0, r4
    blo lbl_0808aec6
    subs r0, r0, r4
    mov ip, r3
    movs r4, #3
    rors r3, r4
    orrs r2, r3
    mov r3, ip
lbl_0808aec6:
    mov ip, r3
    cmp r0, #0
    beq lbl_0808aed4
    lsrs r3, r3, #4
    beq lbl_0808aed4
    lsrs r1, r1, #4
    b lbl_0808ae88
lbl_0808aed4:
    movs r4, #0xe
    lsls r4, r4, #0x1c
    ands r2, r4
    bne lbl_0808aee0
    pop {r4}
    mov pc, lr
lbl_0808aee0:
    mov r3, ip
    movs r4, #3
    rors r3, r4
    tst r2, r3
    beq lbl_0808aeee
    lsrs r4, r1, #3
    adds r0, r0, r4
lbl_0808aeee:
    mov r3, ip
    movs r4, #2
    rors r3, r4
    tst r2, r3
    beq lbl_0808aefc
    lsrs r4, r1, #2
    adds r0, r0, r4
lbl_0808aefc:
    mov r3, ip
    movs r4, #1
    rors r3, r4
    tst r2, r3
    beq lbl_0808af0a
    lsrs r4, r1, #1
    adds r0, r0, r4
lbl_0808af0a:
    pop {r4}
    mov pc, lr
lbl_0808af0e:
    push {lr}
    bl __div_by_zero
    movs r0, #0
    pop {pc}
