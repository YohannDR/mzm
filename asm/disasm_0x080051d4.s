    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sram_write_unchecked_internal
sram_write_unchecked_internal: @ 0x080051d4
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

    thumb_func_start sram_write_unchecked
sram_write_unchecked: @ 0x080051f8
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
    ldr r3, lbl_0800522c @ =sram_write_unchecked_internal
    movs r0, #1
    bics r3, r0
    mov r2, sp
    ldr r0, lbl_08005230 @ =sram_write_unchecked
    ldr r1, lbl_0800522c @ =sram_write_unchecked_internal
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b lbl_08005240
    .align 2, 0
lbl_08005224: .4byte 0x04000204
lbl_08005228: .4byte 0x0000fffc
lbl_0800522c: .4byte sram_write_unchecked_internal
lbl_08005230: .4byte sram_write_unchecked
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

    thumb_func_start sram_write
sram_write: @ 0x0800525c
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    adds r3, r2, #0
    ldr r2, lbl_08005294 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_08005298 @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    subs r3, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r3, r0
    beq lbl_0800528c
    adds r1, r0, #0
lbl_0800527e:
    ldrb r0, [r5]
    strb r0, [r4]
    adds r5, #1
    adds r4, #1
    subs r3, #1
    cmp r3, r1
    bne lbl_0800527e
lbl_0800528c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08005294: .4byte 0x04000204
lbl_08005298: .4byte 0x0000fffc

    thumb_func_start sram_check_internal
sram_check_internal: @ 0x0800529c
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

    thumb_func_start sram_check
sram_check: @ 0x080052cc
    push {r4, r5, r6, lr}
    sub sp, #0xc0
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r2, lbl_080052f8 @ =0x04000204
    ldrh r0, [r2]
    ldr r1, lbl_080052fc @ =0x0000fffc
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strh r0, [r2]
    ldr r3, lbl_08005300 @ =sram_check_internal
    movs r0, #1
    bics r3, r0
    mov r2, sp
    ldr r0, lbl_08005304 @ =sram_check
    ldr r1, lbl_08005300 @ =sram_check_internal
    subs r0, r0, r1
    lsls r0, r0, #0xf
    b lbl_08005314
    .align 2, 0
lbl_080052f8: .4byte 0x04000204
lbl_080052fc: .4byte 0x0000fffc
lbl_08005300: .4byte sram_check_internal
lbl_08005304: .4byte sram_check
lbl_08005308:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r0, r1, #1
    lsls r0, r0, #0x10
lbl_08005314:
    lsrs r1, r0, #0x10
    cmp r1, #0
    bne lbl_08005308
    mov r3, sp
    adds r3, #1
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl _call_via_r3
    add sp, #0xc0
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sram_write_checked
sram_write_checked: @ 0x08005330
    push {r4, r5, r6, r7, lr}
    adds r6, r0, #0
    adds r5, r1, #0
    adds r4, r2, #0
    movs r7, #0
    b lbl_08005342
lbl_0800533c:
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
lbl_08005342:
    cmp r7, #2
    bhi lbl_08005360
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl sram_write
    adds r0, r6, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl sram_check
    adds r3, r0, #0
    cmp r3, #0
    bne lbl_0800533c
lbl_08005360:
    adds r0, r3, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
