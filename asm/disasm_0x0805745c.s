    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start GadoraHatchUpdate
GadoraHatchUpdate: @ 0x0805790c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    rsbs r3, r2, #0
    orrs r3, r2
    lsrs r3, r3, #0x1f
    str r3, [sp]
    movs r6, #0
    movs r7, #0
    movs r4, #0
    lsrs r0, r0, #0x16
    lsls r0, r0, #0x10
    mov r8, r0
    lsrs r1, r1, #0x16
    lsls r1, r1, #0x10
    mov ip, r1
    mov sb, r3
    ldr r3, lbl_08057990 @ =0x0300545c
    movs r0, #2
    rsbs r0, r0, #0
    mov sl, r0
lbl_08057944:
    ldrb r0, [r3, #1]
    lsls r0, r0, #0x1e
    cmp r0, #0
    bne lbl_08057994
    ldrb r1, [r3, #5]
    adds r0, r1, r6
    mov r5, r8
    lsrs r2, r5, #0x10
    cmp r0, r2
    blt lbl_08057974
    subs r0, r1, r6
    cmp r0, r2
    bgt lbl_08057974
    ldrb r1, [r3, #6]
    adds r0, r1, #3
    mov r5, ip
    lsrs r2, r5, #0x10
    cmp r0, r2
    blt lbl_08057974
    movs r5, #0
    subs r0, r1, r5
    cmp r0, r2
    bgt lbl_08057974
    movs r7, #1
lbl_08057974:
    cmp r7, #0
    beq lbl_08057994
    ldrb r1, [r3]
    lsls r0, r1, #0x1f
    lsrs r0, r0, #0x1f
    ldr r2, [sp]
    cmp r0, r2
    beq lbl_080579a2
    mov r0, sl
    ands r0, r1
    mov r5, sb
    orrs r0, r5
    strb r0, [r3]
    b lbl_0805799c
    .align 2, 0
lbl_08057990: .4byte 0x0300545c
lbl_08057994:
    adds r3, #8
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08057944
lbl_0805799c:
    adds r4, #1
    cmp r7, #0
    bne lbl_080579a4
lbl_080579a2:
    movs r4, #0
lbl_080579a4:
    adds r0, r4, #0
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

