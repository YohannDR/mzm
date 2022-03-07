    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_0808af18
sub_0808af18: @ 0x0808af18
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
    bl sub_0808c600
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

    thumb_func_start sub_0808b060
sub_0808b060: @ 0x0808b060
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

    thumb_func_start sub_0808b138
sub_0808b138: @ 0x0808b138
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    adds r3, r0, #0
    adds r4, r1, #0
    mov sl, r2
    movs r0, #0
    ldr r2, [r3]
    cmp r2, #1
    bhi lbl_0808b154
    movs r0, #1
lbl_0808b154:
    cmp r0, #0
    beq lbl_0808b15c
lbl_0808b158:
    adds r0, r3, #0
    b lbl_0808b394
lbl_0808b15c:
    movs r1, #0
    ldr r0, [r4]
    cmp r0, #1
    bhi lbl_0808b166
    movs r1, #1
lbl_0808b166:
    cmp r1, #0
    bne lbl_0808b1de
    movs r1, #0
    cmp r2, #4
    bne lbl_0808b172
    movs r1, #1
lbl_0808b172:
    cmp r1, #0
    beq lbl_0808b194
    movs r1, #0
    cmp r0, #4
    bne lbl_0808b17e
    movs r1, #1
lbl_0808b17e:
    cmp r1, #0
    beq lbl_0808b158
    ldr r1, [r3, #4]
    ldr r0, [r4, #4]
    cmp r1, r0
    beq lbl_0808b158
    ldr r0, lbl_0808b190 @ =0x030058e0
    b lbl_0808b394
    .align 2, 0
lbl_0808b190: .4byte 0x030058e0
lbl_0808b194:
    movs r1, #0
    cmp r0, #4
    bne lbl_0808b19c
    movs r1, #1
lbl_0808b19c:
    cmp r1, #0
    bne lbl_0808b1de
    movs r1, #0
    cmp r0, #2
    bne lbl_0808b1a8
    movs r1, #1
lbl_0808b1a8:
    cmp r1, #0
    beq lbl_0808b1d0
    movs r0, #0
    cmp r2, #2
    bne lbl_0808b1b4
    movs r0, #1
lbl_0808b1b4:
    cmp r0, #0
    beq lbl_0808b158
    mov r1, sl
    adds r0, r3, #0
    ldm r0!, {r2, r5, r6}
    stm r1!, {r2, r5, r6}
    ldm r0!, {r2, r5}
    stm r1!, {r2, r5}
    ldr r0, [r3, #4]
    ldr r1, [r4, #4]
    ands r0, r1
    mov r6, sl
    str r0, [r6, #4]
    b lbl_0808b392
lbl_0808b1d0:
    movs r1, #0
    ldr r0, [r3]
    cmp r0, #2
    bne lbl_0808b1da
    movs r1, #1
lbl_0808b1da:
    cmp r1, #0
    beq lbl_0808b1e2
lbl_0808b1de:
    adds r0, r4, #0
    b lbl_0808b394
lbl_0808b1e2:
    ldr r0, [r3, #8]
    mov sb, r0
    ldr r1, [r4, #8]
    mov r8, r1
    ldr r6, [r3, #0xc]
    ldr r7, [r3, #0x10]
    ldr r0, [r4, #0xc]
    ldr r1, [r4, #0x10]
    str r0, [sp]
    str r1, [sp, #4]
    mov r1, sb
    mov r2, r8
    subs r0, r1, r2
    cmp r0, #0
    bge lbl_0808b202
    rsbs r0, r0, #0
lbl_0808b202:
    cmp r0, #0x3f
    bgt lbl_0808b280
    ldr r3, [r3, #4]
    mov ip, r3
    ldr r4, [r4, #4]
    str r4, [sp, #8]
    cmp sb, r8
    ble lbl_0808b24c
    mov r3, sb
    mov r4, r8
    subs r3, r3, r4
    mov r8, r3
lbl_0808b21a:
    movs r5, #1
    rsbs r5, r5, #0
    add r8, r5
    ldr r2, [sp]
    movs r0, #1
    ands r2, r0
    movs r3, #0
    ldr r1, [sp, #4]
    lsls r5, r1, #0x1f
    ldr r0, [sp]
    lsrs r4, r0, #1
    adds r0, r5, #0
    orrs r0, r4
    adds r4, r1, #0
    lsrs r1, r4, #1
    adds r5, r2, #0
    orrs r5, r0
    str r5, [sp]
    adds r4, r3, #0
    orrs r4, r1
    str r4, [sp, #4]
    mov r5, r8
    cmp r5, #0
    bne lbl_0808b21a
    mov r8, sb
lbl_0808b24c:
    cmp r8, sb
    ble lbl_0808b29c
    mov r0, r8
    mov r1, sb
    subs r0, r0, r1
    mov sb, r0
lbl_0808b258:
    movs r2, #1
    rsbs r2, r2, #0
    add sb, r2
    movs r2, #1
    ands r2, r6
    movs r3, #0
    lsls r5, r7, #0x1f
    lsrs r4, r6, #1
    adds r0, r5, #0
    orrs r0, r4
    lsrs r1, r7, #1
    adds r6, r2, #0
    orrs r6, r0
    adds r7, r3, #0
    orrs r7, r1
    mov r3, sb
    cmp r3, #0
    bne lbl_0808b258
    mov sb, r8
    b lbl_0808b29c
lbl_0808b280:
    cmp sb, r8
    ble lbl_0808b28e
    movs r0, #0
    movs r1, #0
    str r0, [sp]
    str r1, [sp, #4]
    b lbl_0808b294
lbl_0808b28e:
    mov sb, r8
    movs r6, #0
    movs r7, #0
lbl_0808b294:
    ldr r3, [r3, #4]
    mov ip, r3
    ldr r4, [r4, #4]
    str r4, [sp, #8]
lbl_0808b29c:
    ldr r1, [sp, #8]
    cmp ip, r1
    beq lbl_0808b344
    mov r2, ip
    cmp r2, #0
    beq lbl_0808b2be
    adds r1, r7, #0
    adds r0, r6, #0
    bl sub_0808c6a4
    adds r3, r1, #0
    adds r2, r0, #0
    ldr r4, [sp]
    ldr r5, [sp, #4]
    adds r2, r2, r4
    adcs r3, r5
    b lbl_0808b2ca
lbl_0808b2be:
    adds r3, r7, #0
    adds r2, r6, #0
    ldr r0, [sp]
    ldr r1, [sp, #4]
    subs r2, r2, r0
    sbcs r3, r1
lbl_0808b2ca:
    cmp r3, #0
    blt lbl_0808b2e0
    movs r0, #0
    mov r1, sl
    str r0, [r1, #4]
    mov r4, sb
    str r4, [r1, #8]
    mov r5, sl
    str r2, [r5, #0xc]
    str r3, [r5, #0x10]
    b lbl_0808b2f8
lbl_0808b2e0:
    movs r0, #1
    mov r6, sl
    str r0, [r6, #4]
    mov r0, sb
    str r0, [r6, #8]
    adds r1, r3, #0
    adds r0, r2, #0
    bl sub_0808c6a4
    mov r2, sl
    str r0, [r2, #0xc]
    str r1, [r2, #0x10]
lbl_0808b2f8:
    mov r4, sl
    ldr r2, [r4, #0xc]
    ldr r3, [r4, #0x10]
    movs r0, #1
    rsbs r0, r0, #0
    asrs r1, r0, #0x1f
lbl_0808b304:
    adds r2, r2, r0
    adcs r3, r1
    ldr r0, lbl_0808b340 @ =0x0fffffff
    cmp r3, r0
    bhi lbl_0808b35c
    cmp r3, r0
    bne lbl_0808b31a
    movs r0, #2
    rsbs r0, r0, #0
    cmp r2, r0
    bhi lbl_0808b35c
lbl_0808b31a:
    mov r5, sl
    ldr r0, [r5, #0xc]
    ldr r1, [r5, #0x10]
    lsrs r3, r0, #0x1f
    lsls r2, r1, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r0, #1
    mov r6, sl
    str r0, [r6, #0xc]
    str r1, [r6, #0x10]
    ldr r2, [r6, #8]
    subs r2, #1
    str r2, [r6, #8]
    movs r2, #1
    rsbs r2, r2, #0
    asrs r3, r2, #0x1f
    b lbl_0808b304
    .align 2, 0
lbl_0808b340: .4byte 0x0fffffff
lbl_0808b344:
    mov r0, ip
    mov r1, sl
    str r0, [r1, #4]
    mov r2, sb
    str r2, [r1, #8]
    ldr r3, [sp]
    ldr r4, [sp, #4]
    adds r6, r6, r3
    adcs r7, r4
    mov r4, sl
    str r6, [r4, #0xc]
    str r7, [r4, #0x10]
lbl_0808b35c:
    movs r0, #3
    mov r5, sl
    str r0, [r5]
    ldr r1, [r5, #0x10]
    ldr r0, lbl_0808b3a0 @ =0x1fffffff
    cmp r1, r0
    bls lbl_0808b392
    ldr r4, [r5, #0xc]
    ldr r5, [r5, #0x10]
    movs r2, #1
    adds r0, r4, #0
    ands r0, r2
    movs r1, #0
    lsls r6, r5, #0x1f
    mov r8, r6
    lsrs r6, r4, #1
    mov r2, r8
    orrs r2, r6
    lsrs r3, r5, #1
    orrs r0, r2
    orrs r1, r3
    mov r2, sl
    str r0, [r2, #0xc]
    str r1, [r2, #0x10]
    ldr r0, [r2, #8]
    adds r0, #1
    str r0, [r2, #8]
lbl_0808b392:
    mov r0, sl
lbl_0808b394:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808b3a0: .4byte 0x1fffffff

    thumb_func_start sub_0808b3a4
sub_0808b3a4: @ 0x0808b3a4
    push {r4, lr}
    sub sp, #0x4c
    str r0, [sp, #0x3c]
    str r1, [sp, #0x40]
    str r2, [sp, #0x44]
    str r3, [sp, #0x48]
    add r0, sp, #0x3c
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x44
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    add r2, sp, #0x28
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b138
    bl sub_0808af18
    add sp, #0x4c
    pop {r4, pc}

    thumb_func_start sub_0808b3d4
sub_0808b3d4: @ 0x0808b3d4
    push {r4, lr}
    sub sp, #0x4c
    str r0, [sp, #0x3c]
    str r1, [sp, #0x40]
    str r2, [sp, #0x44]
    str r3, [sp, #0x48]
    add r0, sp, #0x3c
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x44
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    ldr r0, [r4, #4]
    movs r1, #1
    eors r0, r1
    str r0, [r4, #4]
    add r2, sp, #0x28
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b138
    bl sub_0808af18
    add sp, #0x4c
    pop {r4, pc}

    thumb_func_start sub_0808b40c
sub_0808b40c: @ 0x0808b40c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x74
    str r0, [sp, #0x3c]
    str r1, [sp, #0x40]
    str r2, [sp, #0x44]
    str r3, [sp, #0x48]
    add r0, sp, #0x3c
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x44
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    mov r8, sp
    add r0, sp, #0x28
    mov sl, r0
    movs r0, #0
    ldr r1, [sp]
    cmp r1, #1
    bhi lbl_0808b442
    movs r0, #1
lbl_0808b442:
    cmp r0, #0
    bne lbl_0808b4a6
    movs r2, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808b450
    movs r2, #1
lbl_0808b450:
    cmp r2, #0
    beq lbl_0808b458
    ldr r0, [sp, #4]
    b lbl_0808b4c8
lbl_0808b458:
    movs r2, #0
    cmp r1, #4
    bne lbl_0808b460
    movs r2, #1
lbl_0808b460:
    cmp r2, #0
    beq lbl_0808b472
    movs r1, #0
    cmp r0, #2
    bne lbl_0808b46c
    movs r1, #1
lbl_0808b46c:
    cmp r1, #0
    bne lbl_0808b48a
    b lbl_0808b4a6
lbl_0808b472:
    movs r2, #0
    cmp r0, #4
    bne lbl_0808b47a
    movs r2, #1
lbl_0808b47a:
    cmp r2, #0
    beq lbl_0808b49a
    movs r0, #0
    cmp r1, #2
    bne lbl_0808b486
    movs r0, #1
lbl_0808b486:
    cmp r0, #0
    beq lbl_0808b494
lbl_0808b48a:
    ldr r0, lbl_0808b490 @ =0x030058e0
    b lbl_0808b692
    .align 2, 0
lbl_0808b490: .4byte 0x030058e0
lbl_0808b494:
    mov r1, r8
    ldr r0, [r1, #4]
    b lbl_0808b4c8
lbl_0808b49a:
    movs r2, #0
    cmp r1, #2
    bne lbl_0808b4a2
    movs r2, #1
lbl_0808b4a2:
    cmp r2, #0
    beq lbl_0808b4b8
lbl_0808b4a6:
    ldr r0, [sp, #4]
    ldr r1, [sp, #0x18]
    eors r0, r1
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
    str r1, [sp, #4]
    mov r0, sp
    b lbl_0808b692
lbl_0808b4b8:
    movs r1, #0
    cmp r0, #2
    bne lbl_0808b4c0
    movs r1, #1
lbl_0808b4c0:
    cmp r1, #0
    beq lbl_0808b4d8
    mov r2, r8
    ldr r0, [r2, #4]
lbl_0808b4c8:
    ldr r1, [sp, #0x18]
    eors r0, r1
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
    str r1, [sp, #0x18]
    adds r0, r4, #0
    b lbl_0808b692
lbl_0808b4d8:
    mov r4, r8
    ldr r0, [r4, #0xc]
    ldr r1, [r4, #0x10]
    adds r6, r0, #0
    movs r7, #0
    str r1, [sp, #0x4c]
    movs r5, #0
    str r5, [sp, #0x50]
    ldr r0, [sp, #0x20]
    ldr r1, [sp, #0x24]
    adds r4, r0, #0
    str r1, [sp, #0x54]
    movs r0, #0
    str r0, [sp, #0x58]
    adds r1, r5, #0
    adds r0, r4, #0
    adds r3, r7, #0
    adds r2, r6, #0
    bl sub_0808c634
    str r0, [sp, #0x5c]
    str r1, [sp, #0x60]
    ldr r0, [sp, #0x54]
    ldr r1, [sp, #0x58]
    adds r3, r7, #0
    adds r2, r6, #0
    bl sub_0808c634
    adds r7, r1, #0
    adds r6, r0, #0
    adds r1, r5, #0
    adds r0, r4, #0
    ldr r2, [sp, #0x4c]
    ldr r3, [sp, #0x50]
    bl sub_0808c634
    adds r5, r1, #0
    adds r4, r0, #0
    ldr r0, [sp, #0x54]
    ldr r1, [sp, #0x58]
    ldr r2, [sp, #0x4c]
    ldr r3, [sp, #0x50]
    bl sub_0808c634
    str r0, [sp, #0x64]
    str r1, [sp, #0x68]
    movs r1, #0
    movs r2, #0
    str r1, [sp, #0x6c]
    str r2, [sp, #0x70]
    adds r3, r7, #0
    adds r2, r6, #0
    adds r2, r2, r4
    adcs r3, r5
    cmp r7, r3
    bhi lbl_0808b550
    cmp r7, r3
    bne lbl_0808b558
    cmp r6, r2
    bls lbl_0808b558
lbl_0808b550:
    ldr r5, lbl_0808b6a8 @ =0x00000001
    ldr r4, lbl_0808b6a4 @ =0x00000000
    str r4, [sp, #0x6c]
    str r5, [sp, #0x70]
lbl_0808b558:
    adds r1, r2, #0
    movs r6, #0
    adds r7, r1, #0
    ldr r0, [sp, #0x5c]
    ldr r1, [sp, #0x60]
    adds r6, r6, r0
    adcs r7, r1
    cmp r1, r7
    bhi lbl_0808b574
    ldr r1, [sp, #0x60]
    cmp r1, r7
    bne lbl_0808b584
    cmp r0, r6
    bls lbl_0808b584
lbl_0808b574:
    movs r0, #1
    movs r1, #0
    ldr r4, [sp, #0x6c]
    ldr r5, [sp, #0x70]
    adds r4, r4, r0
    adcs r5, r1
    str r4, [sp, #0x6c]
    str r5, [sp, #0x70]
lbl_0808b584:
    adds r0, r3, #0
    adds r2, r0, #0
    movs r3, #0
    adds r5, r3, #0
    adds r4, r2, #0
    ldr r0, [sp, #0x64]
    ldr r1, [sp, #0x68]
    adds r4, r4, r0
    adcs r5, r1
    ldr r1, [sp, #0x6c]
    ldr r2, [sp, #0x70]
    adds r4, r4, r1
    adcs r5, r2
    mov r0, r8
    ldr r2, [r0, #8]
    ldr r0, [sp, #0x1c]
    adds r2, r2, r0
    str r2, [sp, #0x30]
    mov r0, r8
    ldr r1, [r0, #4]
    ldr r0, [sp, #0x18]
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    str r0, [sp, #0x2c]
    adds r2, #4
    str r2, [sp, #0x30]
    ldr r0, lbl_0808b6ac @ =0x1fffffff
    cmp r5, r0
    bls lbl_0808b606
    movs r1, #1
    mov sb, r1
    mov r8, r0
    mov ip, r2
lbl_0808b5ca:
    movs r2, #1
    add ip, r2
    mov r0, sb
    ands r0, r4
    cmp r0, #0
    beq lbl_0808b5f0
    lsls r3, r7, #0x1f
    lsrs r2, r6, #1
    adds r0, r3, #0
    orrs r0, r2
    lsrs r1, r7, #1
    adds r7, r1, #0
    adds r6, r0, #0
    adds r0, r6, #0
    movs r1, #0x80
    lsls r1, r1, #0x18
    orrs r1, r7
    adds r7, r1, #0
    adds r6, r0, #0
lbl_0808b5f0:
    lsls r3, r5, #0x1f
    lsrs r2, r4, #1
    adds r0, r3, #0
    orrs r0, r2
    lsrs r1, r5, #1
    adds r5, r1, #0
    adds r4, r0, #0
    cmp r5, r8
    bhi lbl_0808b5ca
    mov r0, ip
    str r0, [sp, #0x30]
lbl_0808b606:
    ldr r0, lbl_0808b6b0 @ =0x0fffffff
    cmp r5, r0
    bhi lbl_0808b658
    movs r1, #0x80
    lsls r1, r1, #0x18
    mov sb, r1
    mov r8, r0
    ldr r2, [sp, #0x30]
    mov ip, r2
lbl_0808b618:
    movs r0, #1
    rsbs r0, r0, #0
    add ip, r0
    lsrs r3, r4, #0x1f
    lsls r2, r5, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #1
    adds r5, r1, #0
    adds r4, r0, #0
    movs r0, #0
    mov r1, sb
    ands r1, r7
    orrs r0, r1
    cmp r0, #0
    beq lbl_0808b642
    movs r0, #1
    orrs r0, r4
    adds r1, r5, #0
    adds r5, r1, #0
    adds r4, r0, #0
lbl_0808b642:
    lsrs r3, r6, #0x1f
    lsls r2, r7, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r6, #1
    adds r7, r1, #0
    adds r6, r0, #0
    cmp r5, r8
    bls lbl_0808b618
    mov r1, ip
    str r1, [sp, #0x30]
lbl_0808b658:
    movs r0, #0xff
    adds r1, r4, #0
    ands r1, r0
    movs r2, #0
    cmp r1, #0x80
    bne lbl_0808b686
    cmp r2, #0
    bne lbl_0808b686
    adds r0, #1
    adds r1, r4, #0
    ands r1, r0
    adds r0, r2, #0
    orrs r0, r1
    cmp r0, #0
    bne lbl_0808b67e
    adds r0, r7, #0
    orrs r0, r6
    cmp r0, #0
    beq lbl_0808b686
lbl_0808b67e:
    movs r0, #0x80
    movs r1, #0
    adds r4, r4, r0
    adcs r5, r1
lbl_0808b686:
    str r4, [sp, #0x34]
    str r5, [sp, #0x38]
    movs r0, #3
    mov r2, sl
    str r0, [r2]
    add r0, sp, #0x28
lbl_0808b692:
    bl sub_0808af18
    add sp, #0x74
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808b6a4: .4byte 0x00000000
lbl_0808b6a8: .4byte 0x00000001
lbl_0808b6ac: .4byte 0x1fffffff
lbl_0808b6b0: .4byte 0x0fffffff

    thumb_func_start sub_0808b6b4
sub_0808b6b4: @ 0x0808b6b4
    push {r4, r5, r6, r7, lr}
    sub sp, #0x48
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    mov ip, sp
    movs r0, #0
    ldr r3, [sp]
    cmp r3, #1
    bhi lbl_0808b6de
    movs r0, #1
lbl_0808b6de:
    cmp r0, #0
    beq lbl_0808b6e6
    mov r1, sp
    b lbl_0808b828
lbl_0808b6e6:
    movs r0, #0
    ldr r2, [sp, #0x14]
    adds r5, r2, #0
    cmp r2, #1
    bhi lbl_0808b6f2
    movs r0, #1
lbl_0808b6f2:
    cmp r0, #0
    beq lbl_0808b6fa
    adds r1, r4, #0
    b lbl_0808b828
lbl_0808b6fa:
    ldr r0, [sp, #4]
    ldr r1, [sp, #0x18]
    eors r0, r1
    str r0, [sp, #4]
    movs r0, #0
    cmp r3, #4
    bne lbl_0808b70a
    movs r0, #1
lbl_0808b70a:
    cmp r0, #0
    bne lbl_0808b71a
    movs r4, #0
    cmp r3, #2
    bne lbl_0808b716
    movs r4, #1
lbl_0808b716:
    cmp r4, #0
    beq lbl_0808b72c
lbl_0808b71a:
    mov r1, ip
    ldr r0, [r1]
    cmp r0, r5
    beq lbl_0808b724
    b lbl_0808b828
lbl_0808b724:
    ldr r1, lbl_0808b728 @ =0x030058e0
    b lbl_0808b828
    .align 2, 0
lbl_0808b728: .4byte 0x030058e0
lbl_0808b72c:
    movs r0, #0
    cmp r2, #4
    bne lbl_0808b734
    movs r0, #1
lbl_0808b734:
    cmp r0, #0
    beq lbl_0808b746
    movs r0, #0
    movs r1, #0
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    str r4, [sp, #8]
    mov r1, sp
    b lbl_0808b828
lbl_0808b746:
    movs r0, #0
    cmp r2, #2
    bne lbl_0808b74e
    movs r0, #1
lbl_0808b74e:
    cmp r0, #0
    beq lbl_0808b75a
    movs r0, #4
    mov r2, ip
    str r0, [r2]
    b lbl_0808b826
lbl_0808b75a:
    mov r3, ip
    ldr r1, [r3, #8]
    ldr r0, [sp, #0x1c]
    subs r6, r1, r0
    str r6, [r3, #8]
    ldr r4, [r3, #0xc]
    ldr r5, [r3, #0x10]
    ldr r0, [sp, #0x20]
    ldr r1, [sp, #0x24]
    str r0, [sp, #0x38]
    str r1, [sp, #0x3c]
    cmp r1, r5
    bhi lbl_0808b77e
    ldr r1, [sp, #0x3c]
    cmp r1, r5
    bne lbl_0808b792
    cmp r0, r4
    bls lbl_0808b792
lbl_0808b77e:
    lsrs r3, r4, #0x1f
    lsls r2, r5, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #1
    adds r5, r1, #0
    adds r4, r0, #0
    subs r0, r6, #1
    mov r2, ip
    str r0, [r2, #8]
lbl_0808b792:
    ldr r7, lbl_0808b838 @ =0x10000000
    ldr r6, lbl_0808b834 @ =0x00000000
    movs r0, #0
    movs r1, #0
    str r0, [sp, #0x40]
    str r1, [sp, #0x44]
lbl_0808b79e:
    ldr r1, [sp, #0x3c]
    cmp r1, r5
    bhi lbl_0808b7c2
    cmp r1, r5
    bne lbl_0808b7ae
    ldr r2, [sp, #0x38]
    cmp r2, r4
    bhi lbl_0808b7c2
lbl_0808b7ae:
    ldr r0, [sp, #0x40]
    orrs r0, r6
    ldr r1, [sp, #0x44]
    orrs r1, r7
    str r0, [sp, #0x40]
    str r1, [sp, #0x44]
    ldr r0, [sp, #0x38]
    ldr r1, [sp, #0x3c]
    subs r4, r4, r0
    sbcs r5, r1
lbl_0808b7c2:
    lsls r3, r7, #0x1f
    lsrs r2, r6, #1
    adds r0, r3, #0
    orrs r0, r2
    lsrs r1, r7, #1
    adds r7, r1, #0
    adds r6, r0, #0
    lsrs r3, r4, #0x1f
    lsls r2, r5, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r4, #1
    adds r5, r1, #0
    adds r4, r0, #0
    adds r0, r7, #0
    orrs r0, r6
    cmp r0, #0
    bne lbl_0808b79e
    movs r0, #0xff
    ldr r1, [sp, #0x40]
    ands r1, r0
    movs r2, #0
    cmp r1, #0x80
    bne lbl_0808b81c
    cmp r2, #0
    bne lbl_0808b81c
    adds r0, #1
    ldr r1, [sp, #0x40]
    ands r1, r0
    adds r0, r2, #0
    orrs r0, r1
    cmp r0, #0
    bne lbl_0808b80c
    adds r0, r5, #0
    orrs r0, r4
    cmp r0, #0
    beq lbl_0808b81c
lbl_0808b80c:
    movs r0, #0x80
    movs r1, #0
    ldr r2, [sp, #0x40]
    ldr r3, [sp, #0x44]
    adds r2, r2, r0
    adcs r3, r1
    str r2, [sp, #0x40]
    str r3, [sp, #0x44]
lbl_0808b81c:
    ldr r0, [sp, #0x40]
    ldr r1, [sp, #0x44]
    mov r2, ip
    str r0, [r2, #0xc]
    str r1, [r2, #0x10]
lbl_0808b826:
    mov r1, ip
lbl_0808b828:
    adds r0, r1, #0
    bl sub_0808af18
    add sp, #0x48
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808b834: .4byte 0x00000000
lbl_0808b838: .4byte 0x10000000

    thumb_func_start sub_0808b83c
sub_0808b83c: @ 0x0808b83c
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r6, r1, #0
    movs r0, #0
    ldr r1, [r5]
    cmp r1, #1
    bhi lbl_0808b84c
    movs r0, #1
lbl_0808b84c:
    cmp r0, #0
    bne lbl_0808b85e
    movs r0, #0
    ldr r2, [r6]
    cmp r2, #1
    bhi lbl_0808b85a
    movs r0, #1
lbl_0808b85a:
    cmp r0, #0
    beq lbl_0808b862
lbl_0808b85e:
    movs r0, #1
    b lbl_0808b938
lbl_0808b862:
    movs r0, #0
    cmp r1, #4
    bne lbl_0808b86a
    movs r0, #1
lbl_0808b86a:
    cmp r0, #0
    beq lbl_0808b882
    movs r0, #0
    cmp r2, #4
    bne lbl_0808b876
    movs r0, #1
lbl_0808b876:
    cmp r0, #0
    beq lbl_0808b882
    ldr r0, [r6, #4]
    ldr r1, [r5, #4]
    subs r0, r0, r1
    b lbl_0808b938
lbl_0808b882:
    movs r1, #0
    ldr r0, [r5]
    cmp r0, #4
    bne lbl_0808b88c
    movs r1, #1
lbl_0808b88c:
    cmp r1, #0
    bne lbl_0808b8da
    movs r1, #0
    cmp r2, #4
    bne lbl_0808b898
    movs r1, #1
lbl_0808b898:
    cmp r1, #0
    beq lbl_0808b8aa
lbl_0808b89c:
    ldr r0, [r6, #4]
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, #0
    beq lbl_0808b8e4
    movs r1, #1
    b lbl_0808b8e4
lbl_0808b8aa:
    movs r1, #0
    cmp r0, #2
    bne lbl_0808b8b2
    movs r1, #1
lbl_0808b8b2:
    cmp r1, #0
    beq lbl_0808b8c2
    movs r1, #0
    cmp r2, #2
    bne lbl_0808b8be
    movs r1, #1
lbl_0808b8be:
    cmp r1, #0
    bne lbl_0808b936
lbl_0808b8c2:
    movs r1, #0
    cmp r0, #2
    bne lbl_0808b8ca
    movs r1, #1
lbl_0808b8ca:
    cmp r1, #0
    bne lbl_0808b89c
    movs r0, #0
    cmp r2, #2
    bne lbl_0808b8d6
    movs r0, #1
lbl_0808b8d6:
    cmp r0, #0
    beq lbl_0808b8e8
lbl_0808b8da:
    ldr r0, [r5, #4]
    movs r1, #1
    cmp r0, #0
    beq lbl_0808b8e4
    subs r1, #2
lbl_0808b8e4:
    adds r0, r1, #0
    b lbl_0808b938
lbl_0808b8e8:
    ldr r0, [r6, #4]
    ldr r4, [r5, #4]
    cmp r4, r0
    beq lbl_0808b8fa
lbl_0808b8f0:
    movs r0, #1
    cmp r4, #0
    beq lbl_0808b938
    subs r0, #2
    b lbl_0808b938
lbl_0808b8fa:
    ldr r1, [r5, #8]
    ldr r0, [r6, #8]
    cmp r1, r0
    bgt lbl_0808b8f0
    cmp r1, r0
    bge lbl_0808b912
lbl_0808b906:
    movs r0, #1
    rsbs r0, r0, #0
    cmp r4, #0
    beq lbl_0808b938
    movs r0, #1
    b lbl_0808b938
lbl_0808b912:
    ldr r3, [r5, #0x10]
    ldr r2, [r6, #0x10]
    cmp r3, r2
    bhi lbl_0808b8f0
    cmp r3, r2
    bne lbl_0808b926
    ldr r1, [r5, #0xc]
    ldr r0, [r6, #0xc]
    cmp r1, r0
    bhi lbl_0808b8f0
lbl_0808b926:
    cmp r2, r3
    bhi lbl_0808b906
    cmp r2, r3
    bne lbl_0808b936
    ldr r1, [r6, #0xc]
    ldr r0, [r5, #0xc]
    cmp r1, r0
    bhi lbl_0808b906
lbl_0808b936:
    movs r0, #0
lbl_0808b938:
    pop {r4, r5, r6, pc}
    .align 2, 0

    thumb_func_start sub_0808b93c
sub_0808b93c: @ 0x0808b93c
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
    add sp, #0x38
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808b968
sub_0808b968: @ 0x0808b968
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808b990
    movs r1, #1
lbl_0808b990:
    cmp r1, #0
    bne lbl_0808b9a2
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808b99e
    movs r1, #1
lbl_0808b99e:
    cmp r1, #0
    beq lbl_0808b9a6
lbl_0808b9a2:
    movs r0, #1
    b lbl_0808b9ae
lbl_0808b9a6:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808b9ae:
    add sp, #0x38
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808b9b4
sub_0808b9b4: @ 0x0808b9b4
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808b9dc
    movs r1, #1
lbl_0808b9dc:
    cmp r1, #0
    bne lbl_0808b9ee
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808b9ea
    movs r1, #1
lbl_0808b9ea:
    cmp r1, #0
    beq lbl_0808b9f2
lbl_0808b9ee:
    movs r0, #1
    b lbl_0808b9fa
lbl_0808b9f2:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808b9fa:
    add sp, #0x38
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808ba00
sub_0808ba00: @ 0x0808ba00
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808ba28
    movs r1, #1
lbl_0808ba28:
    cmp r1, #0
    bne lbl_0808ba3a
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808ba36
    movs r1, #1
lbl_0808ba36:
    cmp r1, #0
    beq lbl_0808ba40
lbl_0808ba3a:
    movs r0, #1
    rsbs r0, r0, #0
    b lbl_0808ba48
lbl_0808ba40:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808ba48:
    add sp, #0x38
    pop {r4, pc}

    thumb_func_start sub_0808ba4c
sub_0808ba4c: @ 0x0808ba4c
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808ba74
    movs r1, #1
lbl_0808ba74:
    cmp r1, #0
    bne lbl_0808ba86
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808ba82
    movs r1, #1
lbl_0808ba82:
    cmp r1, #0
    beq lbl_0808ba8c
lbl_0808ba86:
    movs r0, #1
    rsbs r0, r0, #0
    b lbl_0808ba94
lbl_0808ba8c:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808ba94:
    add sp, #0x38
    pop {r4, pc}

    thumb_func_start sub_0808ba98
sub_0808ba98: @ 0x0808ba98
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808bac0
    movs r1, #1
lbl_0808bac0:
    cmp r1, #0
    bne lbl_0808bad2
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808bace
    movs r1, #1
lbl_0808bace:
    cmp r1, #0
    beq lbl_0808bad6
lbl_0808bad2:
    movs r0, #1
    b lbl_0808bade
lbl_0808bad6:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808bade:
    add sp, #0x38
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808bae4
sub_0808bae4: @ 0x0808bae4
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x28]
    str r1, [sp, #0x2c]
    str r2, [sp, #0x30]
    str r3, [sp, #0x34]
    add r0, sp, #0x28
    mov r1, sp
    bl sub_0808b060
    add r0, sp, #0x30
    add r4, sp, #0x14
    adds r1, r4, #0
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808bb0c
    movs r1, #1
lbl_0808bb0c:
    cmp r1, #0
    bne lbl_0808bb1e
    movs r1, #0
    ldr r0, [sp, #0x14]
    cmp r0, #1
    bhi lbl_0808bb1a
    movs r1, #1
lbl_0808bb1a:
    cmp r1, #0
    beq lbl_0808bb22
lbl_0808bb1e:
    movs r0, #1
    b lbl_0808bb2a
lbl_0808bb22:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808b83c
lbl_0808bb2a:
    add sp, #0x38
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808bb30
sub_0808bb30: @ 0x0808bb30
    push {r4, r5, lr}
    sub sp, #0x14
    adds r2, r0, #0
    movs r0, #3
    str r0, [sp]
    lsrs r1, r2, #0x1f
    str r1, [sp, #4]
    cmp r2, #0
    bne lbl_0808bb48
    movs r0, #2
    str r0, [sp]
    b lbl_0808bb9e
lbl_0808bb48:
    movs r0, #0x3c
    str r0, [sp, #8]
    cmp r1, #0
    beq lbl_0808bb6e
    movs r0, #0x80
    lsls r0, r0, #0x18
    cmp r2, r0
    bne lbl_0808bb68
    ldr r1, lbl_0808bb64 @ =0x00000000
    ldr r0, lbl_0808bb60 @ =0xc1e00000
    b lbl_0808bba4
    .align 2, 0
lbl_0808bb60: .4byte 0xc1e00000
lbl_0808bb64: .4byte 0x00000000
lbl_0808bb68:
    rsbs r0, r2, #0
    asrs r1, r0, #0x1f
    b lbl_0808bb72
lbl_0808bb6e:
    adds r0, r2, #0
    asrs r1, r2, #0x1f
lbl_0808bb72:
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    ldr r0, [sp, #0x10]
    ldr r1, lbl_0808bba8 @ =0x0fffffff
    cmp r0, r1
    bhi lbl_0808bb9e
    adds r5, r1, #0
    ldr r4, [sp, #8]
lbl_0808bb82:
    ldr r0, [sp, #0xc]
    ldr r1, [sp, #0x10]
    lsrs r3, r0, #0x1f
    lsls r2, r1, #1
    adds r1, r3, #0
    orrs r1, r2
    lsls r0, r0, #1
    str r0, [sp, #0xc]
    str r1, [sp, #0x10]
    subs r4, #1
    ldr r0, [sp, #0x10]
    cmp r0, r5
    bls lbl_0808bb82
    str r4, [sp, #8]
lbl_0808bb9e:
    mov r0, sp
    bl sub_0808af18
lbl_0808bba4:
    add sp, #0x14
    pop {r4, r5, pc}
    .align 2, 0
lbl_0808bba8: .4byte 0x0fffffff

    thumb_func_start sub_0808bbac
sub_0808bbac: @ 0x0808bbac
    push {lr}
    sub sp, #0x1c
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    add r0, sp, #0x14
    mov r1, sp
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #2
    bne lbl_0808bbc6
    movs r1, #1
lbl_0808bbc6:
    cmp r1, #0
    bne lbl_0808bbfa
    movs r1, #0
    cmp r0, #1
    bhi lbl_0808bbd2
    movs r1, #1
lbl_0808bbd2:
    cmp r1, #0
    bne lbl_0808bbfa
    movs r1, #0
    cmp r0, #4
    bne lbl_0808bbde
    movs r1, #1
lbl_0808bbde:
    cmp r1, #0
    beq lbl_0808bbf4
lbl_0808bbe2:
    ldr r0, [sp, #4]
    ldr r1, lbl_0808bbf0 @ =0x7fffffff
    cmp r0, #0
    beq lbl_0808bc18
    adds r1, #1
    b lbl_0808bc18
    .align 2, 0
lbl_0808bbf0: .4byte 0x7fffffff
lbl_0808bbf4:
    ldr r0, [sp, #8]
    cmp r0, #0
    bge lbl_0808bbfe
lbl_0808bbfa:
    movs r0, #0
    b lbl_0808bc1a
lbl_0808bbfe:
    cmp r0, #0x1e
    bgt lbl_0808bbe2
    movs r2, #0x3c
    subs r2, r2, r0
    ldr r0, [sp, #0xc]
    ldr r1, [sp, #0x10]
    bl sub_0808c600
    adds r1, r0, #0
    ldr r0, [sp, #4]
    cmp r0, #0
    beq lbl_0808bc18
    rsbs r1, r1, #0
lbl_0808bc18:
    adds r0, r1, #0
lbl_0808bc1a:
    add sp, #0x1c
    pop {pc}
    .align 2, 0

    thumb_func_start sub_0808bc20
sub_0808bc20: @ 0x0808bc20
    push {lr}
    sub sp, #0x1c
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    add r0, sp, #0x14
    mov r1, sp
    bl sub_0808b060
    movs r1, #0
    ldr r0, [sp, #4]
    cmp r0, #0
    bne lbl_0808bc3a
    movs r1, #1
lbl_0808bc3a:
    str r1, [sp, #4]
    mov r0, sp
    bl sub_0808af18
    add sp, #0x1c
    pop {pc}
    .align 2, 0

    thumb_func_start sub_0808bc48
sub_0808bc48: @ 0x0808bc48
    sub sp, #4
    push {r4, lr}
    sub sp, #0x14
    str r3, [sp, #0x1c]
    ldr r3, [sp, #0x1c]
    ldr r4, [sp, #0x20]
    str r0, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #0xc]
    str r4, [sp, #0x10]
    mov r0, sp
    bl sub_0808af18
    add sp, #0x14
    pop {r4}
    pop {r3}
    add sp, #4
    bx r3
    .align 2, 0

    thumb_func_start sub_0808bc70
sub_0808bc70: @ 0x0808bc70
    push {r4, r5, lr}
    sub sp, #0x1c
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
    add r0, sp, #0x14
    mov r1, sp
    bl sub_0808b060
    ldr r2, [sp, #0xc]
    ldr r3, [sp, #0x10]
    lsls r5, r3, #2
    lsrs r4, r2, #0x1e
    adds r0, r5, #0
    orrs r0, r4
    adds r5, r0, #0
    ldr r4, lbl_0808bcb0 @ =0x3fffffff
    adds r0, r2, #0
    ands r0, r4
    movs r1, #0
    orrs r0, r1
    cmp r0, #0
    beq lbl_0808bca0
    movs r0, #1
    orrs r5, r0
lbl_0808bca0:
    ldr r0, [sp]
    ldr r1, [sp, #4]
    ldr r2, [sp, #8]
    adds r3, r5, #0
    bl sub_0808c5bc
    add sp, #0x1c
    pop {r4, r5, pc}
    .align 2, 0
lbl_0808bcb0: .4byte 0x3fffffff

    thumb_func_start sub_0808bcb4
sub_0808bcb4: @ 0x0808bcb4
    push {r4, r5, r6, lr}
    ldr r2, [r0, #0xc]
    ldr r6, [r0, #4]
    movs r5, #0
    movs r1, #0
    ldr r3, [r0]
    cmp r3, #1
    bhi lbl_0808bcc6
    movs r1, #1
lbl_0808bcc6:
    cmp r1, #0
    beq lbl_0808bcd4
    movs r5, #0xff
    movs r0, #0x80
    lsls r0, r0, #0xd
    orrs r2, r0
    b lbl_0808bd3a
lbl_0808bcd4:
    movs r1, #0
    cmp r3, #4
    bne lbl_0808bcdc
    movs r1, #1
lbl_0808bcdc:
    cmp r1, #0
    bne lbl_0808bd10
    movs r1, #0
    cmp r3, #2
    bne lbl_0808bce8
    movs r1, #1
lbl_0808bce8:
    cmp r1, #0
    beq lbl_0808bcf0
    movs r2, #0
    b lbl_0808bd3a
lbl_0808bcf0:
    cmp r2, #0
    beq lbl_0808bd3a
    ldr r0, [r0, #8]
    movs r3, #0x7e
    rsbs r3, r3, #0
    cmp r0, r3
    bge lbl_0808bd0c
    subs r0, r3, r0
    cmp r0, #0x19
    ble lbl_0808bd08
    movs r2, #0
    b lbl_0808bd38
lbl_0808bd08:
    lsrs r2, r0
    b lbl_0808bd38
lbl_0808bd0c:
    cmp r0, #0x7f
    ble lbl_0808bd16
lbl_0808bd10:
    movs r5, #0xff
    movs r2, #0
    b lbl_0808bd3a
lbl_0808bd16:
    adds r5, r0, #0
    adds r5, #0x7f
    movs r0, #0x7f
    ands r0, r2
    cmp r0, #0x40
    bne lbl_0808bd2e
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    beq lbl_0808bd30
    adds r2, #0x40
    b lbl_0808bd30
lbl_0808bd2e:
    adds r2, #0x3f
lbl_0808bd30:
    cmp r2, #0
    bge lbl_0808bd38
    lsrs r2, r2, #1
    adds r5, #1
lbl_0808bd38:
    lsrs r2, r2, #7
lbl_0808bd3a:
    ldr r0, lbl_0808bd5c @ =0x007fffff
    ands r2, r0
    ldr r0, lbl_0808bd60 @ =0xff800000
    ands r4, r0
    orrs r4, r2
    movs r0, #0xff
    ands r5, r0
    lsls r1, r5, #0x17
    ldr r0, lbl_0808bd64 @ =0x807fffff
    ands r4, r0
    orrs r4, r1
    lsls r1, r6, #0x1f
    ldr r0, lbl_0808bd68 @ =0x7fffffff
    ands r4, r0
    orrs r4, r1
    adds r0, r4, #0
    pop {r4, r5, r6, pc}
    .align 2, 0
lbl_0808bd5c: .4byte 0x007fffff
lbl_0808bd60: .4byte 0xff800000
lbl_0808bd64: .4byte 0x807fffff
lbl_0808bd68: .4byte 0x7fffffff

    thumb_func_start sub_0808bd6c
sub_0808bd6c: @ 0x0808bd6c
    push {r4, lr}
    adds r3, r1, #0
    ldr r0, [r0]
    lsls r1, r0, #9
    lsrs r2, r1, #9
    lsls r1, r0, #1
    lsrs r1, r1, #0x18
    lsrs r0, r0, #0x1f
    str r0, [r3, #4]
    cmp r1, #0
    bne lbl_0808bdb0
    cmp r2, #0
    bne lbl_0808bd8c
    movs r0, #2
    str r0, [r3]
    b lbl_0808bde4
lbl_0808bd8c:
    adds r4, r1, #0
    subs r4, #0x7e
    str r4, [r3, #8]
    lsls r2, r2, #7
    movs r0, #3
    str r0, [r3]
    ldr r1, lbl_0808bdac @ =0x3fffffff
    cmp r2, r1
    bhi lbl_0808bdcc
    adds r0, r4, #0
lbl_0808bda0:
    lsls r2, r2, #1
    subs r0, #1
    cmp r2, r1
    bls lbl_0808bda0
    str r0, [r3, #8]
    b lbl_0808bdcc
    .align 2, 0
lbl_0808bdac: .4byte 0x3fffffff
lbl_0808bdb0:
    cmp r1, #0xff
    bne lbl_0808bdd0
    cmp r2, #0
    bne lbl_0808bdbe
    movs r0, #4
    str r0, [r3]
    b lbl_0808bde4
lbl_0808bdbe:
    movs r0, #0x80
    lsls r0, r0, #0xd
    ands r0, r2
    cmp r0, #0
    beq lbl_0808bdca
    movs r0, #1
lbl_0808bdca:
    str r0, [r3]
lbl_0808bdcc:
    str r2, [r3, #0xc]
    b lbl_0808bde4
lbl_0808bdd0:
    adds r0, r1, #0
    subs r0, #0x7f
    str r0, [r3, #8]
    movs r0, #3
    str r0, [r3]
    lsls r0, r2, #7
    movs r1, #0x80
    lsls r1, r1, #0x17
    orrs r0, r1
    str r0, [r3, #0xc]
lbl_0808bde4:
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808bde8
sub_0808bde8: @ 0x0808bde8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r6, r0, #0
    adds r7, r1, #0
    adds r5, r2, #0
    movs r0, #0
    ldr r2, [r6]
    cmp r2, #1
    bhi lbl_0808bdfe
    movs r0, #1
lbl_0808bdfe:
    cmp r0, #0
    beq lbl_0808be06
lbl_0808be02:
    adds r0, r6, #0
    b lbl_0808bf5c
lbl_0808be06:
    movs r1, #0
    ldr r0, [r7]
    cmp r0, #1
    bhi lbl_0808be10
    movs r1, #1
lbl_0808be10:
    cmp r1, #0
    bne lbl_0808be84
    movs r1, #0
    cmp r2, #4
    bne lbl_0808be1c
    movs r1, #1
lbl_0808be1c:
    cmp r1, #0
    beq lbl_0808be3c
    movs r1, #0
    cmp r0, #4
    bne lbl_0808be28
    movs r1, #1
lbl_0808be28:
    cmp r1, #0
    beq lbl_0808be02
    ldr r1, [r6, #4]
    ldr r0, [r7, #4]
    cmp r1, r0
    beq lbl_0808be02
    ldr r0, lbl_0808be38 @ =0x030058f8
    b lbl_0808bf5c
    .align 2, 0
lbl_0808be38: .4byte 0x030058f8
lbl_0808be3c:
    movs r1, #0
    cmp r0, #4
    bne lbl_0808be44
    movs r1, #1
lbl_0808be44:
    cmp r1, #0
    bne lbl_0808be84
    movs r1, #0
    cmp r0, #2
    bne lbl_0808be50
    movs r1, #1
lbl_0808be50:
    cmp r1, #0
    beq lbl_0808be76
    movs r0, #0
    cmp r2, #2
    bne lbl_0808be5c
    movs r0, #1
lbl_0808be5c:
    cmp r0, #0
    beq lbl_0808be02
    adds r1, r5, #0
    adds r0, r6, #0
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r6, #4]
    ldr r1, [r7, #4]
    ands r0, r1
    str r0, [r5, #4]
    b lbl_0808bf5a
lbl_0808be76:
    movs r1, #0
    ldr r0, [r6]
    cmp r0, #2
    bne lbl_0808be80
    movs r1, #1
lbl_0808be80:
    cmp r1, #0
    beq lbl_0808be88
lbl_0808be84:
    adds r0, r7, #0
    b lbl_0808bf5c
lbl_0808be88:
    ldr r1, [r6, #8]
    ldr r3, [r7, #8]
    ldr r2, [r6, #0xc]
    ldr r4, [r7, #0xc]
    subs r0, r1, r3
    cmp r0, #0
    bge lbl_0808be98
    rsbs r0, r0, #0
lbl_0808be98:
    cmp r0, #0x1f
    bgt lbl_0808bedc
    ldr r6, [r6, #4]
    ldr r7, [r7, #4]
    mov r8, r7
    cmp r1, r3
    ble lbl_0808bebe
    movs r7, #1
    mov ip, r7
    subs r3, r1, r3
lbl_0808beac:
    subs r3, #1
    adds r0, r4, #0
    mov r7, ip
    ands r0, r7
    lsrs r4, r4, #1
    orrs r4, r0
    cmp r3, #0
    bne lbl_0808beac
    adds r3, r1, #0
lbl_0808bebe:
    cmp r3, r1
    ble lbl_0808beee
    movs r0, #1
    mov ip, r0
    subs r1, r3, r1
lbl_0808bec8:
    subs r1, #1
    adds r0, r2, #0
    mov r7, ip
    ands r0, r7
    lsrs r2, r2, #1
    orrs r2, r0
    cmp r1, #0
    bne lbl_0808bec8
    adds r1, r3, #0
    b lbl_0808beee
lbl_0808bedc:
    cmp r1, r3
    ble lbl_0808bee4
    movs r4, #0
    b lbl_0808bee8
lbl_0808bee4:
    adds r1, r3, #0
    movs r2, #0
lbl_0808bee8:
    ldr r6, [r6, #4]
    ldr r7, [r7, #4]
    mov r8, r7
lbl_0808beee:
    cmp r6, r8
    beq lbl_0808bf38
    cmp r6, #0
    beq lbl_0808befa
    subs r3, r4, r2
    b lbl_0808befc
lbl_0808befa:
    subs r3, r2, r4
lbl_0808befc:
    cmp r3, #0
    blt lbl_0808bf0a
    movs r0, #0
    str r0, [r5, #4]
    str r1, [r5, #8]
    str r3, [r5, #0xc]
    b lbl_0808bf14
lbl_0808bf0a:
    movs r0, #1
    str r0, [r5, #4]
    str r1, [r5, #8]
    rsbs r0, r3, #0
    str r0, [r5, #0xc]
lbl_0808bf14:
    ldr r1, [r5, #0xc]
    subs r0, r1, #1
    ldr r2, lbl_0808bf34 @ =0x3ffffffe
    cmp r0, r2
    bhi lbl_0808bf40
lbl_0808bf1e:
    lsls r0, r1, #1
    str r0, [r5, #0xc]
    ldr r1, [r5, #8]
    subs r1, #1
    str r1, [r5, #8]
    adds r1, r0, #0
    subs r0, r1, #1
    cmp r0, r2
    bls lbl_0808bf1e
    b lbl_0808bf40
    .align 2, 0
lbl_0808bf34: .4byte 0x3ffffffe
lbl_0808bf38:
    str r6, [r5, #4]
    str r1, [r5, #8]
    adds r0, r2, r4
    str r0, [r5, #0xc]
lbl_0808bf40:
    movs r0, #3
    str r0, [r5]
    ldr r1, [r5, #0xc]
    cmp r1, #0
    bge lbl_0808bf5a
    movs r0, #1
    ands r0, r1
    lsrs r1, r1, #1
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [r5, #8]
    adds r0, #1
    str r0, [r5, #8]
lbl_0808bf5a:
    adds r0, r5, #0
lbl_0808bf5c:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7, pc}
    .align 2, 0

    thumb_func_start sub_0808bf64
sub_0808bf64: @ 0x0808bf64
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x30]
    str r1, [sp, #0x34]
    add r0, sp, #0x30
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x34
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    add r2, sp, #0x20
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808bde8
    bl sub_0808bcb4
    add sp, #0x38
    pop {r4, pc}

    thumb_func_start sub_0808bf90
sub_0808bf90: @ 0x0808bf90
    push {r4, lr}
    sub sp, #0x38
    str r0, [sp, #0x30]
    str r1, [sp, #0x34]
    add r0, sp, #0x30
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x34
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    ldr r0, [r4, #4]
    movs r1, #1
    eors r0, r1
    str r0, [r4, #4]
    add r2, sp, #0x20
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808bde8
    bl sub_0808bcb4
    add sp, #0x38
    pop {r4, pc}

    thumb_func_start sub_0808bfc4
sub_0808bfc4: @ 0x0808bfc4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x38
    str r0, [sp, #0x30]
    str r1, [sp, #0x34]
    add r0, sp, #0x30
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x34
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    mov r7, sp
    add r0, sp, #0x20
    mov r8, r0
    movs r0, #0
    ldr r1, [sp]
    mov sb, r8
    cmp r1, #1
    bhi lbl_0808bff6
    movs r0, #1
lbl_0808bff6:
    cmp r0, #0
    bne lbl_0808c054
    movs r2, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c004
    movs r2, #1
lbl_0808c004:
    cmp r2, #0
    beq lbl_0808c00c
    ldr r0, [sp, #4]
    b lbl_0808c074
lbl_0808c00c:
    movs r2, #0
    cmp r1, #4
    bne lbl_0808c014
    movs r2, #1
lbl_0808c014:
    cmp r2, #0
    beq lbl_0808c026
    movs r1, #0
    cmp r0, #2
    bne lbl_0808c020
    movs r1, #1
lbl_0808c020:
    cmp r1, #0
    bne lbl_0808c03e
    b lbl_0808c054
lbl_0808c026:
    movs r2, #0
    cmp r0, #4
    bne lbl_0808c02e
    movs r2, #1
lbl_0808c02e:
    cmp r2, #0
    beq lbl_0808c048
    movs r0, #0
    cmp r1, #2
    bne lbl_0808c03a
    movs r0, #1
lbl_0808c03a:
    cmp r0, #0
    beq lbl_0808c072
lbl_0808c03e:
    ldr r0, lbl_0808c044 @ =0x030058f8
    b lbl_0808c116
    .align 2, 0
lbl_0808c044: .4byte 0x030058f8
lbl_0808c048:
    movs r2, #0
    cmp r1, #2
    bne lbl_0808c050
    movs r2, #1
lbl_0808c050:
    cmp r2, #0
    beq lbl_0808c066
lbl_0808c054:
    ldr r0, [sp, #4]
    ldr r1, [sp, #0x14]
    eors r0, r1
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
    str r1, [sp, #4]
    mov r0, sp
    b lbl_0808c116
lbl_0808c066:
    movs r1, #0
    cmp r0, #2
    bne lbl_0808c06e
    movs r1, #1
lbl_0808c06e:
    cmp r1, #0
    beq lbl_0808c084
lbl_0808c072:
    ldr r0, [r7, #4]
lbl_0808c074:
    ldr r1, [sp, #0x14]
    eors r0, r1
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r1, r1, #0x1f
    str r1, [sp, #0x14]
    adds r0, r4, #0
    b lbl_0808c116
lbl_0808c084:
    ldr r0, [r7, #0xc]
    movs r1, #0
    ldr r2, [sp, #0x1c]
    movs r3, #0
    bl sub_0808c634
    adds r2, r1, #0
    adds r5, r2, #0
    adds r6, r0, #0
    ldr r4, [r7, #8]
    ldr r0, [sp, #0x18]
    adds r4, r4, r0
    str r4, [sp, #0x28]
    ldr r1, [r7, #4]
    ldr r0, [sp, #0x14]
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    str r0, [sp, #0x24]
    adds r4, #2
    str r4, [sp, #0x28]
    cmp r2, #0
    bge lbl_0808c0d0
    movs r2, #1
    movs r1, #0x80
    lsls r1, r1, #0x18
lbl_0808c0ba:
    adds r4, #1
    adds r0, r5, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0808c0c8
    lsrs r6, r6, #1
    orrs r6, r1
lbl_0808c0c8:
    lsrs r5, r5, #1
    cmp r5, #0
    blt lbl_0808c0ba
    str r4, [sp, #0x28]
lbl_0808c0d0:
    ldr r0, lbl_0808c124 @ =0x3fffffff
    cmp r5, r0
    bhi lbl_0808c0f6
    movs r4, #0x80
    lsls r4, r4, #0x18
    movs r3, #1
    adds r2, r0, #0
    ldr r1, [sp, #0x28]
lbl_0808c0e0:
    subs r1, #1
    lsls r5, r5, #1
    adds r0, r6, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_0808c0ee
    orrs r5, r3
lbl_0808c0ee:
    lsls r6, r6, #1
    cmp r5, r2
    bls lbl_0808c0e0
    str r1, [sp, #0x28]
lbl_0808c0f6:
    movs r0, #0x7f
    ands r0, r5
    cmp r0, #0x40
    bne lbl_0808c10c
    movs r0, #0x80
    ands r0, r5
    cmp r0, #0
    bne lbl_0808c10a
    cmp r6, #0
    beq lbl_0808c10c
lbl_0808c10a:
    adds r5, #0x40
lbl_0808c10c:
    str r5, [sp, #0x2c]
    movs r0, #3
    mov r1, r8
    str r0, [r1]
    mov r0, sb
lbl_0808c116:
    bl sub_0808bcb4
    add sp, #0x38
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808c124: .4byte 0x3fffffff

    thumb_func_start sub_0808c128
sub_0808c128: @ 0x0808c128
    push {r4, r5, r6, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r5, sp, #0x10
    adds r1, r5, #0
    bl sub_0808bd6c
    mov r4, sp
    movs r0, #0
    ldr r3, [sp]
    cmp r3, #1
    bhi lbl_0808c14e
    movs r0, #1
lbl_0808c14e:
    cmp r0, #0
    beq lbl_0808c156
    mov r1, sp
    b lbl_0808c208
lbl_0808c156:
    movs r0, #0
    ldr r2, [sp, #0x10]
    adds r6, r2, #0
    cmp r2, #1
    bhi lbl_0808c162
    movs r0, #1
lbl_0808c162:
    cmp r0, #0
    beq lbl_0808c16a
    adds r1, r5, #0
    b lbl_0808c208
lbl_0808c16a:
    ldr r0, [sp, #4]
    ldr r1, [sp, #0x14]
    eors r0, r1
    str r0, [sp, #4]
    movs r0, #0
    cmp r3, #4
    bne lbl_0808c17a
    movs r0, #1
lbl_0808c17a:
    cmp r0, #0
    bne lbl_0808c18a
    movs r0, #0
    cmp r3, #2
    bne lbl_0808c186
    movs r0, #1
lbl_0808c186:
    cmp r0, #0
    beq lbl_0808c19c
lbl_0808c18a:
    ldr r0, [r4]
    adds r1, r4, #0
    cmp r0, r6
    bne lbl_0808c208
    ldr r1, lbl_0808c198 @ =0x030058f8
    b lbl_0808c208
    .align 2, 0
lbl_0808c198: .4byte 0x030058f8
lbl_0808c19c:
    movs r1, #0
    cmp r2, #4
    bne lbl_0808c1a4
    movs r1, #1
lbl_0808c1a4:
    cmp r1, #0
    beq lbl_0808c1b0
    str r0, [sp, #0xc]
    str r0, [sp, #8]
    mov r1, sp
    b lbl_0808c208
lbl_0808c1b0:
    movs r0, #0
    cmp r2, #2
    bne lbl_0808c1b8
    movs r0, #1
lbl_0808c1b8:
    cmp r0, #0
    beq lbl_0808c1c2
    movs r0, #4
    str r0, [r4]
    b lbl_0808c206
lbl_0808c1c2:
    ldr r1, [r4, #8]
    ldr r0, [sp, #0x18]
    subs r0, r1, r0
    str r0, [r4, #8]
    ldr r2, [r4, #0xc]
    ldr r3, [sp, #0x1c]
    cmp r2, r3
    bhs lbl_0808c1d8
    lsls r2, r2, #1
    subs r0, #1
    str r0, [r4, #8]
lbl_0808c1d8:
    movs r0, #0x80
    lsls r0, r0, #0x17
    movs r1, #0
lbl_0808c1de:
    cmp r2, r3
    blo lbl_0808c1e6
    orrs r1, r0
    subs r2, r2, r3
lbl_0808c1e6:
    lsrs r0, r0, #1
    lsls r2, r2, #1
    cmp r0, #0
    bne lbl_0808c1de
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0x40
    bne lbl_0808c204
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0808c202
    cmp r2, #0
    beq lbl_0808c204
lbl_0808c202:
    adds r1, #0x40
lbl_0808c204:
    str r1, [r4, #0xc]
lbl_0808c206:
    adds r1, r4, #0
lbl_0808c208:
    adds r0, r1, #0
    bl sub_0808bcb4
    add sp, #0x28
    pop {r4, r5, r6, pc}
    .align 2, 0

    thumb_func_start sub_0808c214
sub_0808c214: @ 0x0808c214
    push {r4, lr}
    adds r4, r0, #0
    movs r0, #0
    ldr r2, [r4]
    cmp r2, #1
    bhi lbl_0808c222
    movs r0, #1
lbl_0808c222:
    cmp r0, #0
    bne lbl_0808c234
    movs r0, #0
    ldr r3, [r1]
    cmp r3, #1
    bhi lbl_0808c230
    movs r0, #1
lbl_0808c230:
    cmp r0, #0
    beq lbl_0808c238
lbl_0808c234:
    movs r0, #1
    b lbl_0808c2f6
lbl_0808c238:
    movs r0, #0
    cmp r2, #4
    bne lbl_0808c240
    movs r0, #1
lbl_0808c240:
    cmp r0, #0
    beq lbl_0808c258
    movs r0, #0
    cmp r3, #4
    bne lbl_0808c24c
    movs r0, #1
lbl_0808c24c:
    cmp r0, #0
    beq lbl_0808c258
    ldr r0, [r1, #4]
    ldr r1, [r4, #4]
    subs r0, r0, r1
    b lbl_0808c2f6
lbl_0808c258:
    movs r2, #0
    ldr r0, [r4]
    cmp r0, #4
    bne lbl_0808c262
    movs r2, #1
lbl_0808c262:
    cmp r2, #0
    bne lbl_0808c2b0
    movs r2, #0
    cmp r3, #4
    bne lbl_0808c26e
    movs r2, #1
lbl_0808c26e:
    cmp r2, #0
    beq lbl_0808c280
lbl_0808c272:
    ldr r0, [r1, #4]
    movs r1, #1
    rsbs r1, r1, #0
    cmp r0, #0
    beq lbl_0808c2ba
    movs r1, #1
    b lbl_0808c2ba
lbl_0808c280:
    movs r2, #0
    cmp r0, #2
    bne lbl_0808c288
    movs r2, #1
lbl_0808c288:
    cmp r2, #0
    beq lbl_0808c298
    movs r2, #0
    cmp r3, #2
    bne lbl_0808c294
    movs r2, #1
lbl_0808c294:
    cmp r2, #0
    bne lbl_0808c2f4
lbl_0808c298:
    movs r2, #0
    cmp r0, #2
    bne lbl_0808c2a0
    movs r2, #1
lbl_0808c2a0:
    cmp r2, #0
    bne lbl_0808c272
    movs r0, #0
    cmp r3, #2
    bne lbl_0808c2ac
    movs r0, #1
lbl_0808c2ac:
    cmp r0, #0
    beq lbl_0808c2be
lbl_0808c2b0:
    ldr r0, [r4, #4]
    movs r1, #1
    cmp r0, #0
    beq lbl_0808c2ba
    subs r1, #2
lbl_0808c2ba:
    adds r0, r1, #0
    b lbl_0808c2f6
lbl_0808c2be:
    ldr r3, [r4, #4]
    ldr r0, [r1, #4]
    cmp r3, r0
    beq lbl_0808c2d0
lbl_0808c2c6:
    movs r0, #1
    cmp r3, #0
    beq lbl_0808c2f6
    subs r0, #2
    b lbl_0808c2f6
lbl_0808c2d0:
    ldr r2, [r4, #8]
    ldr r0, [r1, #8]
    cmp r2, r0
    bgt lbl_0808c2c6
    cmp r2, r0
    bge lbl_0808c2e8
lbl_0808c2dc:
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, #0
    beq lbl_0808c2f6
    movs r0, #1
    b lbl_0808c2f6
lbl_0808c2e8:
    ldr r0, [r4, #0xc]
    ldr r1, [r1, #0xc]
    cmp r0, r1
    bhi lbl_0808c2c6
    cmp r0, r1
    blo lbl_0808c2dc
lbl_0808c2f4:
    movs r0, #0
lbl_0808c2f6:
    pop {r4, pc}

    thumb_func_start sub_0808c2f8
sub_0808c2f8: @ 0x0808c2f8
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
    add sp, #0x28
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808c320
sub_0808c320: @ 0x0808c320
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c344
    movs r1, #1
lbl_0808c344:
    cmp r1, #0
    bne lbl_0808c356
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c352
    movs r1, #1
lbl_0808c352:
    cmp r1, #0
    beq lbl_0808c35a
lbl_0808c356:
    movs r0, #1
    b lbl_0808c362
lbl_0808c35a:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c362:
    add sp, #0x28
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808c368
sub_0808c368: @ 0x0808c368
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c38c
    movs r1, #1
lbl_0808c38c:
    cmp r1, #0
    bne lbl_0808c39e
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c39a
    movs r1, #1
lbl_0808c39a:
    cmp r1, #0
    beq lbl_0808c3a2
lbl_0808c39e:
    movs r0, #1
    b lbl_0808c3aa
lbl_0808c3a2:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c3aa:
    add sp, #0x28
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808c3b0
sub_0808c3b0: @ 0x0808c3b0
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c3d4
    movs r1, #1
lbl_0808c3d4:
    cmp r1, #0
    bne lbl_0808c3e6
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c3e2
    movs r1, #1
lbl_0808c3e2:
    cmp r1, #0
    beq lbl_0808c3ec
lbl_0808c3e6:
    movs r0, #1
    rsbs r0, r0, #0
    b lbl_0808c3f4
lbl_0808c3ec:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c3f4:
    add sp, #0x28
    pop {r4, pc}

    thumb_func_start sub_0808c3f8
sub_0808c3f8: @ 0x0808c3f8
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c41c
    movs r1, #1
lbl_0808c41c:
    cmp r1, #0
    bne lbl_0808c42e
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c42a
    movs r1, #1
lbl_0808c42a:
    cmp r1, #0
    beq lbl_0808c434
lbl_0808c42e:
    movs r0, #1
    rsbs r0, r0, #0
    b lbl_0808c43c
lbl_0808c434:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c43c:
    add sp, #0x28
    pop {r4, pc}

    thumb_func_start sub_0808c440
sub_0808c440: @ 0x0808c440
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c464
    movs r1, #1
lbl_0808c464:
    cmp r1, #0
    bne lbl_0808c476
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c472
    movs r1, #1
lbl_0808c472:
    cmp r1, #0
    beq lbl_0808c47a
lbl_0808c476:
    movs r0, #1
    b lbl_0808c482
lbl_0808c47a:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c482:
    add sp, #0x28
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808c488
sub_0808c488: @ 0x0808c488
    push {r4, lr}
    sub sp, #0x28
    str r0, [sp, #0x20]
    str r1, [sp, #0x24]
    add r0, sp, #0x20
    mov r1, sp
    bl sub_0808bd6c
    add r0, sp, #0x24
    add r4, sp, #0x10
    adds r1, r4, #0
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #1
    bhi lbl_0808c4ac
    movs r1, #1
lbl_0808c4ac:
    cmp r1, #0
    bne lbl_0808c4be
    movs r1, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bhi lbl_0808c4ba
    movs r1, #1
lbl_0808c4ba:
    cmp r1, #0
    beq lbl_0808c4c2
lbl_0808c4be:
    movs r0, #1
    b lbl_0808c4ca
lbl_0808c4c2:
    mov r0, sp
    adds r1, r4, #0
    bl sub_0808c214
lbl_0808c4ca:
    add sp, #0x28
    pop {r4, pc}
    .align 2, 0

    thumb_func_start sub_0808c4d0
sub_0808c4d0: @ 0x0808c4d0
    push {lr}
    sub sp, #0x10
    adds r1, r0, #0
    movs r0, #3
    str r0, [sp]
    lsrs r2, r1, #0x1f
    str r2, [sp, #4]
    cmp r1, #0
    bne lbl_0808c4e8
    movs r0, #2
    str r0, [sp]
    b lbl_0808c520
lbl_0808c4e8:
    movs r0, #0x1e
    str r0, [sp, #8]
    cmp r2, #0
    beq lbl_0808c506
    movs r0, #0x80
    lsls r0, r0, #0x18
    cmp r1, r0
    bne lbl_0808c500
    ldr r0, lbl_0808c4fc @ =0xcf000000
    b lbl_0808c526
    .align 2, 0
lbl_0808c4fc: .4byte 0xcf000000
lbl_0808c500:
    rsbs r0, r1, #0
    str r0, [sp, #0xc]
    b lbl_0808c508
lbl_0808c506:
    str r1, [sp, #0xc]
lbl_0808c508:
    ldr r2, [sp, #0xc]
    ldr r3, lbl_0808c52c @ =0x3fffffff
    cmp r2, r3
    bhi lbl_0808c520
    ldr r1, [sp, #8]
lbl_0808c512:
    lsls r0, r2, #1
    subs r1, #1
    adds r2, r0, #0
    cmp r0, r3
    bls lbl_0808c512
    str r1, [sp, #8]
    str r0, [sp, #0xc]
lbl_0808c520:
    mov r0, sp
    bl sub_0808bcb4
lbl_0808c526:
    add sp, #0x10
    pop {pc}
    .align 2, 0
lbl_0808c52c: .4byte 0x3fffffff

    thumb_func_start sub_0808c530
sub_0808c530: @ 0x0808c530
    push {lr}
    sub sp, #0x14
    str r0, [sp, #0x10]
    add r0, sp, #0x10
    mov r1, sp
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp]
    cmp r0, #2
    bne lbl_0808c548
    movs r1, #1
lbl_0808c548:
    cmp r1, #0
    bne lbl_0808c57a
    movs r1, #0
    cmp r0, #1
    bhi lbl_0808c554
    movs r1, #1
lbl_0808c554:
    cmp r1, #0
    bne lbl_0808c57a
    movs r1, #0
    cmp r0, #4
    bne lbl_0808c560
    movs r1, #1
lbl_0808c560:
    cmp r1, #0
    beq lbl_0808c574
lbl_0808c564:
    ldr r0, [sp, #4]
    ldr r1, lbl_0808c570 @ =0x7fffffff
    cmp r0, #0
    beq lbl_0808c592
    adds r1, #1
    b lbl_0808c592
    .align 2, 0
lbl_0808c570: .4byte 0x7fffffff
lbl_0808c574:
    ldr r1, [sp, #8]
    cmp r1, #0
    bge lbl_0808c57e
lbl_0808c57a:
    movs r0, #0
    b lbl_0808c594
lbl_0808c57e:
    cmp r1, #0x1e
    bgt lbl_0808c564
    movs r0, #0x1e
    subs r0, r0, r1
    ldr r1, [sp, #0xc]
    lsrs r1, r0
    ldr r0, [sp, #4]
    cmp r0, #0
    beq lbl_0808c592
    rsbs r1, r1, #0
lbl_0808c592:
    adds r0, r1, #0
lbl_0808c594:
    add sp, #0x14
    pop {pc}

    thumb_func_start sub_0808c598
sub_0808c598: @ 0x0808c598
    push {lr}
    sub sp, #0x14
    str r0, [sp, #0x10]
    add r0, sp, #0x10
    mov r1, sp
    bl sub_0808bd6c
    movs r1, #0
    ldr r0, [sp, #4]
    cmp r0, #0
    bne lbl_0808c5b0
    movs r1, #1
lbl_0808c5b0:
    str r1, [sp, #4]
    mov r0, sp
    bl sub_0808bcb4
    add sp, #0x14
    pop {pc}

    thumb_func_start sub_0808c5bc
sub_0808c5bc: @ 0x0808c5bc
    push {lr}
    sub sp, #0x10
    str r0, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #0xc]
    mov r0, sp
    bl sub_0808bcb4
    add sp, #0x10
    pop {pc}
    .align 2, 0

    thumb_func_start sub_0808c5d4
sub_0808c5d4: @ 0x0808c5d4
    push {r4, r5, r6, lr}
    sub sp, #0x18
    str r0, [sp, #0x14]
    add r0, sp, #0x14
    add r1, sp, #4
    bl sub_0808bd6c
    ldr r0, [sp, #4]
    ldr r1, [sp, #8]
    ldr r2, [sp, #0xc]
    ldr r3, [sp, #0x10]
    movs r4, #0
    lsrs r6, r3, #2
    lsls r5, r4, #0x1e
    adds r4, r6, #0
    orrs r4, r5
    lsls r3, r3, #0x1e
    str r4, [sp]
    bl sub_0808bc48
    add sp, #0x18
    pop {r4, r5, r6, pc}

    thumb_func_start sub_0808c600
sub_0808c600: @ 0x0808c600
    push {r4, r5, r6, lr}
    adds r6, r1, #0
    adds r5, r0, #0
    cmp r2, #0
    beq lbl_0808c630
    movs r0, #0x20
    subs r0, r0, r2
    cmp r0, #0
    bgt lbl_0808c61c
    movs r4, #0
    rsbs r0, r0, #0
    adds r3, r6, #0
    lsrs r3, r0
    b lbl_0808c62c
lbl_0808c61c:
    adds r1, r6, #0
    lsls r1, r0
    adds r4, r6, #0
    lsrs r4, r2
    adds r0, r5, #0
    lsrs r0, r2
    adds r3, r0, #0
    orrs r3, r1
lbl_0808c62c:
    adds r1, r4, #0
    adds r0, r3, #0
lbl_0808c630:
    pop {r4, r5, r6, pc}
    .align 2, 0

    thumb_func_start sub_0808c634
sub_0808c634: @ 0x0808c634
    push {r4, r5, r6, r7, lr}
    sub sp, #0x10
    str r0, [sp]
    str r1, [sp, #4]
    str r2, [sp, #8]
    str r3, [sp, #0xc]
    ldr r3, [sp]
    ldr r0, lbl_0808c6a0 @ =0x0000ffff
    mov ip, r0
    adds r2, r3, #0
    ands r2, r0
    lsrs r3, r3, #0x10
    ldr r1, [sp, #8]
    adds r0, r1, #0
    mov r4, ip
    ands r0, r4
    lsrs r1, r1, #0x10
    adds r5, r2, #0
    muls r5, r0, r5
    adds r4, r2, #0
    muls r4, r1, r4
    adds r2, r3, #0
    muls r2, r0, r2
    muls r3, r1, r3
    lsrs r0, r5, #0x10
    adds r4, r4, r0
    adds r4, r4, r2
    cmp r4, r2
    bhs lbl_0808c674
    movs r0, #0x80
    lsls r0, r0, #9
    adds r3, r3, r0
lbl_0808c674:
    lsrs r0, r4, #0x10
    adds r7, r3, r0
    mov r1, ip
    ands r4, r1
    lsls r0, r4, #0x10
    ands r5, r1
    adds r6, r0, #0
    orrs r6, r5
    adds r1, r7, #0
    adds r0, r6, #0
    ldr r3, [sp]
    ldr r4, [sp, #0xc]
    adds r2, r3, #0
    muls r2, r4, r2
    ldr r5, [sp, #4]
    ldr r4, [sp, #8]
    adds r3, r5, #0
    muls r3, r4, r3
    adds r2, r2, r3
    adds r1, r7, r2
    add sp, #0x10
    pop {r4, r5, r6, r7, pc}
    .align 2, 0
lbl_0808c6a0: .4byte 0x0000ffff

    thumb_func_start sub_0808c6a4
sub_0808c6a4: @ 0x0808c6a4
    push {r4, lr}
    rsbs r2, r0, #0
    adds r3, r2, #0
    rsbs r1, r1, #0
    cmp r2, #0
    beq lbl_0808c6b2
    subs r1, #1
lbl_0808c6b2:
    adds r4, r1, #0
    adds r1, r4, #0
    adds r0, r3, #0
    pop {r4, pc}
    .align 2, 0

    thumb_func_start copy_bytes
copy_bytes: @ 0x0808c6bc
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
