    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start __pack_d
__pack_d: @ 0x0808af18
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    adds r1, r0, #0
    ldr r4, [r1, #0xc]
    ldr r5, [r1, #0x10]
    ldr r7, [r1, #4]
    movs r6, #0
    movs r2, #0
    ldr r0, [r1]
    cmp r0, #1
    bhi lbl_0808af30
    movs r2, #1
lbl_0808af30:
    cmp r2, #0
    beq lbl_0808af50
    ldr r6, lbl_0808af44 @ =0x000007ff
    ldr r2, lbl_0808af48 @ =0x00000000
    ldr r3, lbl_0808af4c @ =0x00080000
    adds r0, r4, #0
    adds r1, r5, #0
    orrs r1, r3
    b lbl_0808b008
    .align 2, 0
lbl_0808af44: .4byte 0x000007ff
lbl_0808af48: .4byte 0x00000000
lbl_0808af4c: .4byte 0x00080000
lbl_0808af50:
    movs r2, #0
    cmp r0, #4
    bne lbl_0808af58
    movs r2, #1
lbl_0808af58:
    cmp r2, #0
    bne lbl_0808afa4
    movs r2, #0
    cmp r0, #2
    bne lbl_0808af64
    movs r2, #1
lbl_0808af64:
    cmp r2, #0
    beq lbl_0808af6e
    movs r4, #0
    movs r5, #0
    b lbl_0808b00c
lbl_0808af6e:
    adds r0, r5, #0
    orrs r0, r4
    cmp r0, #0
    beq lbl_0808b00c
    ldr r2, [r1, #8]
    ldr r0, lbl_0808af8c @ =0xfffffc02
    cmp r2, r0
    bge lbl_0808af9e
    subs r2, r0, r2
    cmp r2, #0x38
    ble lbl_0808af90
    movs r4, #0
    movs r5, #0
    b lbl_0808affe
    .align 2, 0
lbl_0808af8c: .4byte 0xfffffc02
lbl_0808af90:
    adds r1, r5, #0
    adds r0, r4, #0
    bl __lshrdi3
    adds r5, r1, #0
    adds r4, r0, #0
    b lbl_0808affe
lbl_0808af9e:
    ldr r0, lbl_0808afac @ =0x000003ff
    cmp r2, r0
    ble lbl_0808afb4
lbl_0808afa4:
    ldr r6, lbl_0808afb0 @ =0x000007ff
    movs r4, #0
    movs r5, #0
    b lbl_0808b00c
    .align 2, 0
lbl_0808afac: .4byte 0x000003ff
lbl_0808afb0: .4byte 0x000007ff
lbl_0808afb4:
    ldr r0, lbl_0808afdc @ =0x000003ff
    adds r6, r2, r0
    movs r0, #0xff
    adds r1, r4, #0
    ands r1, r0
    movs r2, #0
    cmp r1, #0x80
    bne lbl_0808afe0
    cmp r2, #0
    bne lbl_0808afe0
    adds r0, #1
    adds r1, r4, #0
    ands r1, r0
    adds r0, r2, #0
    orrs r0, r1
    cmp r0, #0
    beq lbl_0808afe8
    movs r0, #0x80
    movs r1, #0
    b lbl_0808afe4
    .align 2, 0
lbl_0808afdc: .4byte 0x000003ff
lbl_0808afe0:
    movs r0, #0x7f
    movs r1, #0
lbl_0808afe4:
    adds r4, r4, r0
    adcs r5, r1
lbl_0808afe8:
    ldr r0, lbl_0808b04c @ =0x1fffffff
    cmp r5, r0
    bls lbl_0808affe
    lsls r3, r5, #0x1f
    lsrs r2, r4, #1
    adds r0, r3, #0
    orrs r0, r2
    lsrs r1, r5, #1
    adds r5, r1, #0
    adds r4, r0, #0
    adds r6, #1
lbl_0808affe:
    lsls r3, r5, #0x18
    lsrs r2, r4, #8
    adds r0, r3, #0
    orrs r0, r2
    lsrs r1, r5, #8
lbl_0808b008:
    adds r5, r1, #0
    adds r4, r0, #0
lbl_0808b00c:
    str r4, [sp]
    ldr r2, lbl_0808b050 @ =0x000fffff
    ands r2, r5
    ldr r0, [sp, #4]
    ldr r1, lbl_0808b054 @ =0xfff00000
    ands r0, r1
    orrs r0, r2
    str r0, [sp, #4]
    mov r2, sp
    ldr r1, lbl_0808b058 @ =0x000007ff
    adds r0, r1, #0
    ands r6, r0
    lsls r1, r6, #4
    ldr r0, lbl_0808b05c @ =0xffff800f
    ldrh r3, [r2, #6]
    ands r0, r3
    orrs r0, r1
    strh r0, [r2, #6]
    lsls r1, r7, #7
    movs r0, #0x7f
    ldrb r3, [r2, #7]
    ands r0, r3
    orrs r0, r1
    strb r0, [r2, #7]
    ldr r1, [sp]
    ldr r0, [sp, #4]
    str r0, [sp]
    str r1, [sp, #4]
    ldr r0, [sp]
    ldr r1, [sp, #4]
    add sp, #8
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808b04c: .4byte 0x1fffffff
lbl_0808b050: .4byte 0x000fffff
lbl_0808b054: .4byte 0xfff00000
lbl_0808b058: .4byte 0x000007ff
lbl_0808b05c: .4byte 0xffff800f

    thumb_func_start __unpack_d
__unpack_d: @ 0x0808b060
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    adds r2, r0, #0
    adds r6, r1, #0
    ldr r1, [r2, #4]
    str r1, [sp]
    ldr r0, [r2]
    str r0, [sp, #4]
    mov r2, sp
    adds r4, r1, #0
    lsls r0, r0, #0xc
    lsrs r5, r0, #0xc
    ldrh r3, [r2, #6]
    lsls r0, r3, #0x11
    lsrs r3, r0, #0x15
    ldrb r2, [r2, #7]
    lsrs r0, r2, #7
    str r0, [r6, #4]
    cmp r3, #0
    bne lbl_0808b0d4
    orrs r1, r5
    cmp r1, #0
    bne lbl_0808b094
    movs r0, #2
    str r0, [r6]
    b lbl_0808b128
lbl_0808b094:
    ldr r0, lbl_0808b0cc @ =0xfffffc02
    str r0, [r6, #8]
    lsrs r3, r4, #0x18
    lsls r2, r5, #8
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #8
    adds r5, r1, #0
    adds r4, r0, #0
    movs r0, #3
    str r0, [r6]
    ldr r0, lbl_0808b0d0 @ =0x0fffffff
    cmp r5, r0
    bhi lbl_0808b104
    adds r7, r0, #0
lbl_0808b0b2:
    lsrs r3, r4, #0x1f
    lsls r2, r5, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #1
    adds r5, r1, #0
    adds r4, r0, #0
    ldr r0, [r6, #8]
    subs r0, #1
    str r0, [r6, #8]
    cmp r5, r7
    bls lbl_0808b0b2
    b lbl_0808b104
    .align 2, 0
lbl_0808b0cc: .4byte 0xfffffc02
lbl_0808b0d0: .4byte 0x0fffffff
lbl_0808b0d4:
    ldr r0, lbl_0808b0e8 @ =0x000007ff
    cmp r3, r0
    bne lbl_0808b10a
    orrs r1, r5
    cmp r1, #0
    bne lbl_0808b0ec
    movs r0, #4
    str r0, [r6]
    b lbl_0808b128
    .align 2, 0
lbl_0808b0e8: .4byte 0x000007ff
lbl_0808b0ec:
    movs r2, #0x80
    lsls r2, r2, #0xc
    movs r0, #0
    adds r1, r5, #0
    ands r1, r2
    orrs r1, r0
    cmp r1, #0
    beq lbl_0808b102
    movs r0, #1
    str r0, [r6]
    b lbl_0808b104
lbl_0808b102:
    str r1, [r6]
lbl_0808b104:
    str r4, [r6, #0xc]
    str r5, [r6, #0x10]
    b lbl_0808b128
lbl_0808b10a:
    ldr r1, lbl_0808b12c @ =0xfffffc01
    adds r0, r3, r1
    str r0, [r6, #8]
    movs r0, #3
    str r0, [r6]
    lsrs r3, r4, #0x18
    lsls r2, r5, #8
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #8
    ldr r2, lbl_0808b130 @ =0x00000000
    ldr r3, lbl_0808b134 @ =0x10000000
    orrs r1, r3
    str r0, [r6, #0xc]
    str r1, [r6, #0x10]
lbl_0808b128:
    add sp, #8
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808b12c: .4byte 0xfffffc01
lbl_0808b130: .4byte 0x00000000
lbl_0808b134: .4byte 0x10000000
