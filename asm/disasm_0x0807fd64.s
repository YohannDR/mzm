    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start ProcessComplexOam
ProcessComplexOam: @ 0x0807fd64
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    str r0, [sp]
    ldr r4, [sp, #0x30]
    ldr r0, [sp, #0x34]
    mov r8, r0
    ldr r0, [sp, #0x38]
    lsls r1, r1, #0x10
    lsls r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    mov r5, r8
    lsls r5, r5, #0x18
    mov r8, r5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #4]
    movs r0, #0x80
    lsls r0, r0, #0xf
    adds r1, r1, r0
    asrs r1, r1, #0x10
    str r1, [sp, #8]
    adds r2, r2, r0
    asrs r2, r2, #0x10
    str r2, [sp, #0xc]
    ldr r1, [sp]
    lsls r0, r1, #3
    ldr r5, lbl_0807fe84 @ =gOamData
    adds r7, r0, r5
    ldrb r0, [r7, #1]
    mov sb, r0
    mov r1, sb
    lsrs r2, r1, #6
    ldrb r0, [r7, #3]
    lsrs r0, r0, #6
    ldr r1, lbl_0807fe88 @ =0x0845fd24
    lsls r2, r2, #2
    adds r0, r0, r2
    adds r1, r0, r1
    ldrb r1, [r1]
    mov ip, r1
    ldr r1, lbl_0807fe8c @ =0x0845fd30
    adds r0, r0, r1
    ldrb r0, [r0]
    mov sl, r0
    ldrh r0, [r7, #2]
    lsls r0, r0, #0x17
    lsrs r0, r0, #0x17
    ldr r1, [sp, #8]
    adds r5, r0, r1
    ldr r1, lbl_0807fe90 @ =0x000001ff
    adds r0, r1, #0
    ands r5, r0
    ldrb r0, [r7]
    ldr r1, [sp, #0xc]
    adds r6, r0, r1
    movs r0, #0xff
    ands r6, r0
    ldr r1, [sp, #8]
    subs r0, r5, r1
    add r0, ip
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    ldr r1, [sp, #0xc]
    subs r2, r6, r1
    add r2, sl
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    adds r1, r0, #0
    muls r1, r4, r1
    asrs r1, r1, #8
    subs r1, r1, r0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r2, #0
    muls r0, r4, r0
    asrs r0, r0, #8
    subs r0, r0, r2
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    adds r1, r5, r1
    lsls r1, r1, #0x10
    asrs r5, r1, #0x10
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    ldr r0, [sp, #8]
    subs r4, r5, r0
    add r4, ip
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    ldr r1, [sp, #0xc]
    subs r2, r6, r1
    add r2, sl
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    ldr r5, lbl_0807fe94 @ =0x0808c71c
    adds r0, r3, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r5
    movs r1, #0
    ldrsh r6, [r0, r1]
    adds r1, r4, #0
    muls r1, r6, r1
    lsls r3, r3, #1
    adds r3, r3, r5
    movs r5, #0
    ldrsh r3, [r3, r5]
    adds r0, r2, #0
    muls r0, r3, r0
    subs r1, r1, r0
    lsls r1, r1, #8
    asrs r5, r1, #0x10
    adds r0, r4, #0
    muls r0, r3, r0
    adds r1, r2, #0
    muls r1, r6, r1
    adds r0, r0, r1
    lsls r0, r0, #8
    asrs r6, r0, #0x10
    mov r0, r8
    cmp r0, #0
    bne lbl_0807fe98
    movs r0, #4
    rsbs r0, r0, #0
    mov r1, sb
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r7, #1]
    mov r1, ip
    subs r0, r5, r1
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    mov r1, sl
    subs r0, r6, r1
    b lbl_0807feb0
    .align 2, 0
lbl_0807fe84: .4byte gOamData
lbl_0807fe88: .4byte 0x0845fd24
lbl_0807fe8c: .4byte 0x0845fd30
lbl_0807fe90: .4byte 0x000001ff
lbl_0807fe94: .4byte 0x0808c71c
lbl_0807fe98:
    movs r0, #3
    mov r1, sb
    orrs r0, r1
    strb r0, [r7, #1]
    mov r1, ip
    lsls r0, r1, #1
    subs r0, r5, r0
    lsls r0, r0, #0x10
    asrs r5, r0, #0x10
    mov r1, sl
    lsls r0, r1, #1
    subs r0, r6, r0
lbl_0807feb0:
    lsls r0, r0, #0x10
    asrs r6, r0, #0x10
    ldr r0, [sp]
    lsls r3, r0, #3
    ldr r1, lbl_0807feec @ =gOamData
    adds r7, r3, r1
    ldr r0, [sp, #8]
    adds r1, r5, r0
    subs r1, #0x40
    ldr r0, lbl_0807fef0 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r7, #2]
    ldr r0, lbl_0807fef4 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r7, #2]
    ldr r1, [sp, #0xc]
    adds r0, r6, r1
    subs r0, #0x40
    strb r0, [r7]
    ldrb r4, [r7, #3]
    lsls r0, r4, #0x1b
    cmp r0, #0
    bge lbl_0807fefe
    lsls r0, r4, #0x1a
    cmp r0, #0
    bge lbl_0807fef8
    ldr r0, [sp, #4]
    adds r0, #3
    b lbl_0807ff08
    .align 2, 0
lbl_0807feec: .4byte gOamData
lbl_0807fef0: .4byte 0x000001ff
lbl_0807fef4: .4byte 0xfffffe00
lbl_0807fef8:
    ldr r0, [sp, #4]
    adds r0, #1
    b lbl_0807ff08
lbl_0807fefe:
    lsls r0, r4, #0x1a
    cmp r0, #0
    bge lbl_0807ff1a
    ldr r0, [sp, #4]
    adds r0, #2
lbl_0807ff08:
    movs r1, #7
    ands r0, r1
    lsls r0, r0, #1
    movs r1, #0xf
    rsbs r1, r1, #0
    ands r1, r4
    orrs r1, r0
    strb r1, [r7, #3]
    b lbl_0807ff2c
lbl_0807ff1a:
    movs r0, #7
    ldr r1, [sp, #4]
    ands r1, r0
    lsls r1, r1, #1
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r4
    orrs r0, r1
    strb r0, [r7, #3]
lbl_0807ff2c:
    ldr r5, lbl_0807ff54 @ =gOamData
    adds r2, r3, r5
    ldrb r1, [r2, #3]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #0x21
    rsbs r1, r1, #0
    ands r0, r1
    strb r0, [r2, #3]
    movs r0, #0
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807ff54: .4byte gOamData

    thumb_func_start CalculateOamPart4
CalculateOamPart4: @ 0x0807ff58
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    lsls r5, r5, #0x10
    asrs r5, r5, #0x10
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    ldr r6, lbl_080800ec @ =0x0808c71c
    adds r0, r4, #0
    adds r0, #0x40
    lsls r0, r0, #1
    adds r0, r0, r6
    movs r2, #0
    ldrsh r1, [r0, r2]
    str r1, [sp]
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldr r0, [sp]
    bl FixedMultiplication
    mov r8, r0
    mov r3, r8
    lsls r3, r3, #0x10
    asrs r3, r3, #0x10
    mov r8, r3
    lsls r4, r4, #1
    adds r4, r4, r6
    movs r1, #0
    ldrsh r0, [r4, r1]
    mov sl, r0
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, sl
    bl FixedMultiplication
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    str r0, [sp, #4]
    ldrh r4, [r4]
    rsbs r4, r4, #0
    lsls r4, r4, #0x10
    asrs r4, r4, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    mov sb, r0
    mov r2, sb
    lsls r2, r2, #0x10
    asrs r2, r2, #0x10
    mov sb, r2
    rsbs r5, r5, #0
    lsls r5, r5, #0x10
    asrs r5, r5, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    ldr r0, [sp]
    bl FixedMultiplication
    adds r6, r0, #0
    lsls r6, r6, #0x10
    asrs r6, r6, #0x10
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    mov r0, sl
    bl FixedMultiplication
    mov sl, r0
    mov r3, sl
    lsls r3, r3, #0x10
    asrs r3, r3, #0x10
    mov sl, r3
    adds r0, r5, #0
    bl FixedInverse
    adds r1, r0, #0
    lsls r1, r1, #0x10
    asrs r1, r1, #0x10
    adds r0, r4, #0
    bl FixedMultiplication
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    ldr r2, lbl_080800f0 @ =gOamData
    lsls r1, r7, #3
    adds r1, r1, r2
    mov r4, r8
    strh r4, [r1, #6]
    adds r1, r7, #1
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sp
    ldrh r3, [r3, #4]
    strh r3, [r1, #6]
    adds r1, r7, #2
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sb
    strh r4, [r1, #6]
    adds r1, r7, #3
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, r8
    strh r3, [r1, #6]
    adds r1, r7, #4
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #5
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sl
    strh r4, [r1, #6]
    adds r1, r7, #6
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sb
    strh r3, [r1, #6]
    adds r1, r7, #7
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, r8
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #8
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #9
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r3, sp
    ldrh r3, [r3, #4]
    strh r3, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xa
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r0, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xb
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xc
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r6, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xd
    lsls r1, r1, #3
    adds r1, r1, r2
    mov r4, sl
    strh r4, [r1, #6]
    adds r1, r7, #0
    adds r1, #0xe
    lsls r1, r1, #3
    adds r1, r1, r2
    strh r0, [r1, #6]
    adds r0, r7, #0
    adds r0, #0xf
    lsls r0, r0, #3
    adds r0, r0, r2
    strh r6, [r0, #6]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080800ec: .4byte 0x0808c71c
lbl_080800f0: .4byte gOamData
