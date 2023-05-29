    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start call_soundcode_b
call_soundcode_b: @ 0x08004310
    push {r4, r5, r6, r7}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7, lr}
    add r4, pc, #0x0
    bx r4

    arm_func_start soundcode_b
soundcode_b: @ 0x08004320
    ldr r4, lbl_080043b0 @ =gMusicInfo
    ldrb ip, [r4, #0x4]
    mov lr, #0x600
    b lbl_08004338
lbl_08004330:
    subs r3, r3, #0x1
    beq lbl_080043a0
lbl_08004338:
    ldsb r6, [r0, lr]
    ldsb r7, [r1, lr]
    ldsb r4, [r0], #0x1
    ldsb r5, [r1], #0x1
    ldsb r10, [r0, lr]
    ldsb r11, [r1, lr]
    ldsb r8, [r0], #0x1
    ldsb r9, [r1], #0x1
    add r6, r6, r4
    add r6, r6, r5
    add r6, r6, r7
    add r8, r8, r9
    add r8, r8, r10
    add r8, r8, r11
    mul r6, ip, r6
    mul r8, ip, r8
    asrs r6, r6, #0x9
    addmi r6, r6, #0x1
    asrs r8, r8, #0x9
    addmi r8, r8, #0x1
    lsl r6, r6, #0x7
    lsl r8, r8, #0x7
    mov r7, r6
    mov r9, r8
    stmia r2!, {r6, r7, r8, r9}
    b lbl_08004330
lbl_080043a0:
    mov r0, r2
    ldmia sp!, {r8, r9, r10, r11, lr}
    ldmia sp!, {r4, r5, r6, r7}
    bx lr
lbl_080043b0:
    .4byte gMusicInfo

    thumb_func_start call_soundcode_c
call_soundcode_c: @ 0x080043b4
    push {r4, r5, r6, r7}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7, lr}
    add r4, pc, #0x0
    bx r4

    arm_func_start soundcode_c
soundcode_c: @ 0x080043c4
    mov r3, #0x600
    add r3, r0, r3
    mov ip, #0x0
    sub ip, ip, #0x1
    lsr ip, ip, #0x17
    ldr lr, lbl_08004460 @ =sArray_808cce2
    b lbl_080043e8
lbl_080043e0:
    subs r2, r2, #0x1
    beq lbl_08004450
lbl_080043e8:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    and r4, ip, r4, lsr #0x7
    and r5, ip, r5, lsr #0x7
    and r6, ip, r6, lsr #0x7
    and r7, ip, r7, lsr #0x7
    and r8, ip, r8, lsr #0x7
    and r9, ip, r9, lsr #0x7
    and r10, ip, r10, lsr #0x7
    and r11, ip, r11, lsr #0x7
    ldrb r4, [lr, r4]
    ldrb r5, [lr, r5]
    ldrb r6, [lr, r6]
    ldrb r7, [lr, r7]
    ldrb r8, [lr, r8]
    ldrb r9, [lr, r9]
    ldrb r10, [lr, r10]
    ldrb r11, [lr, r11]
    orr r4, r4, r6, lsl #0x8
    orr r4, r4, r8, lsl #0x10
    orr r4, r4, r10, lsl #0x18
    str r4, [r0], #0x4
    orr r5, r5, r7, lsl #0x8
    orr r5, r5, r9, lsl #0x10
    orr r5, r5, r11, lsl #0x18
    str r5, [r3], #0x4
    b lbl_080043e0
lbl_08004450:
    mov r0, r1
    ldmia sp!, {r8, r9, r10, r11, lr}
    ldmia sp!, {r4, r5, r6, r7}
    bx lr
lbl_08004460:
    .4byte sArray_808cce2

    thumb_func_start call_soundcode_a
call_soundcode_a: @ 0x08004464
    push {r4, r5, r6, r7}
    mov r3, r8
    mov r4, sb
    mov r5, sl
    mov r6, fp
    push {r3, r4, r5, r6, lr}
    add r4, pc, #0x0
    bx r4

    arm_func_start soundcode_a
soundcode_a: @ 0x08004474
    ldr ip, [r0, #0x18]
    ldrb r11, [r0, #0x11]
    ldrb r10, [r0, #0x12]
    ldr r9, [r0, #0x24]
    ldr r3, [r0, #0x20]
    ldr r8, [r3, #0xC]
    ldrb r4, [r0, #0x1]
    cmp r4, #0x20
    beq lbl_080048c0
    cmp r4, #0x8
    beq lbl_08004794
    mov r7, #0x0
    sub r7, r7, #0x1
    lsr r7, r7, #0x12
    ldr r6, [r0, #0x1C]
    stmdb sp!, {r0}
    ldrh r0, [r3, #0x2]
    ldr lr, [r3, #0x8]
    sub lr, lr, r8
    b lbl_080044cc
lbl_080044c4:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080044cc:
    add r4, ip, r6, lsl #0x2
    subs r4, r8, r4, lsr #0xE
    bgt lbl_080046d0
    mov r5, ip, lsr #0xE
    ands r0, r0, r0
    bne lbl_080045b8
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    b lbl_08004a98
lbl_080045b8:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, r8
    blt lbl_08004600
    and r3, ip, r7
    add r5, r5, lr
    add ip, r3, r5, lsl #0xE
    b lbl_08004700
lbl_08004600:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, r8
    blt lbl_08004648
    and r3, ip, r7
    add r5, r5, lr
    add ip, r3, r5, lsl #0xE
    b lbl_08004730
lbl_08004648:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, r8
    blt lbl_08004690
    and r3, ip, r7
    add r5, r5, lr
    add ip, r3, r5, lsl #0xE
    b lbl_08004760
lbl_08004690:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    and r3, ip, r7
    add r5, r5, lr
    add ip, r3, r5, lsl #0xE
    b lbl_080044c4
lbl_080046d0:
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
lbl_08004700:
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
lbl_08004730:
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
lbl_08004760:
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    b lbl_080044c4
lbl_08004794:
    stmdb sp!, {r0}
    ldrh r7, [r3, #0x2]
    ldr r6, [r3, #0x8]
    b lbl_080047ac
lbl_080047a4:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080047ac:
    add r4, ip, #0x4
    cmp r4, r8
    blt lbl_0800486c
    ldsb r3, [r9, ip]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, #0x1
    cmp ip, r8
    bne lbl_080047e4
    ands r7, r7, r7
    beq lbl_08004a98
    mov ip, r6
lbl_080047e4:
    ldsb r3, [r9, ip]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, #0x1
    cmp ip, r8
    bne lbl_08004810
    ands r7, r7, r7
    beq lbl_08004a98
    mov ip, r6
lbl_08004810:
    ldsb r3, [r9, ip]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, #0x1
    cmp ip, r8
    bne lbl_0800483c
    ands r7, r7, r7
    beq lbl_08004a98
    mov ip, r6
lbl_0800483c:
    ldsb r3, [r9, ip]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, #0x1
    cmp ip, r8
    bne lbl_080047a4
    ands r7, r7, r7
    beq lbl_08004a98
    mov ip, r6
    b lbl_080047a4
lbl_0800486c:
    ldmia r1, {r3, r4, r5, lr}
    ldsb r0, [r9, ip]
    mla r3, r0, r11, r3
    mla r4, r0, r10, r4
    add ip, ip, #0x1
    ldsb r0, [r9, ip]
    mla r5, r0, r11, r5
    mla lr, r0, r10, lr
    add ip, ip, #0x1
    stmia r1!, {r3, r4, r5, lr}
    ldmia r1, {r3, r4, r5, lr}
    ldsb r0, [r9, ip]
    mla r3, r0, r11, r3
    mla r4, r0, r10, r4
    add ip, ip, #0x1
    ldsb r0, [r9, ip]
    mla r5, r0, r11, r5
    mla lr, r0, r10, lr
    add ip, ip, #0x1
    stmia r1!, {r3, r4, r5, lr}
    b lbl_080047a4
lbl_080048c0:
    mov r7, #0x0
    sub r7, r7, #0x1
    mov r4, r7
    mov r7, r7, lsr #0x12
    ldr r6, [r0, #0x1C]
    eor r6, r6, r4
    add r6, r6, #0x1
    stmdb sp!, {r0}
    ldrh r0, [r3, #0x2]
    b lbl_080048f0
lbl_080048e8:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080048f0:
    add r4, ip, r6, lsl #0x2
    movs r4, r4, asr #0xE
    bgt lbl_080049d4
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    b lbl_08004a98
lbl_080049d4:
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    mov r5, ip, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, ip, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add ip, ip, r6
    b lbl_080048e8
lbl_08004a98:
    ldmia sp!, {r0}
    mov r4, #0x0
    strb r4, [r0, #0x0]
    b lbl_08004ab0
lbl_08004aa8:
    ldmia sp!, {r0}
    str ip, [r0, #0x18]
lbl_08004ab0:
    ldmia sp!, {r8, r9, r10, r11, lr}
    ldmia sp!, {r4, r5, r6, r7}
    bx lr

    thumb_func_start sub_08004abc
sub_08004abc: @ 0x08004abc
    add r2, pc, #0x0 @ =sub_08004ac0
    bx r2

    arm_func_start sub_08004ac0
sub_08004ac0: @ 0x08004ac0
    umull r2, r3, r0, r1
    lsr r2, r2, #0x12
    lsl r3, r3, #0xe
    add r3, r3, r2
    add r0, r3, #0
    bx lr

    thumb_func_start sub_08004ad8
sub_08004ad8: @ 0x08004ad8
    add r0, pc, #0x0 @ =sub_08004adc
    bx r0

    arm_func_start sub_08004adc
sub_08004adc: @ 0x08004adc
    ldr r0, lbl_08004b44 @ =gMusicInfo
    ldrb r1, [r0, #0x10]
    add r1, r1, #1
    ldrb r3, [r0, #0xe]
    cmp r1, r3
    bne lbl_08004b3c
    ldr r3, lbl_08004b48 @ =0x0808ceec
    ldr r3, [r3]
    ldr ip, lbl_08004b4c @ =0x0808cef0
    ldr ip, [ip]
    str ip, [r3]
    str ip, [r3, #0xC]
    mov r0, r0
    mov ip, #0x50
    lsl ip, ip, #0x4
    strh ip, [r3, #0x2]
    strh ip, [r3, #0xE]
    mov ip, #0xB6
    lsl ip, ip, #0x8
    strh ip, [r3, #0x2]
    mov ip, #0xF6
    lsl ip, ip, #0x8
    strh ip, [r3, #0xE]
    mov r1, #0x0
lbl_08004b3c:
    strb r1, [r0, #0x10]
    bx lr
    .align 2, 0
lbl_08004b44: .4byte gMusicInfo
lbl_08004b48: .4byte 0x0808ceec
lbl_08004b4c: .4byte 0x0808cef0

    thumb_func_start sub_08004b50
sub_08004b50: @ 0x08004b50
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    adds r4, r0, #0
    adds r5, r1, #0
    ldrb r6, [r4, #0x1c]
    cmp r6, #0
    bne lbl_08004c04
    movs r6, #1
    strb r6, [r4, #0x1c]
    ldrb r6, [r4, #0x1e]
    movs r7, #1
    ands r6, r7
    bne lbl_08004c00
    ldr r6, [r5]
    lsls r2, r6, #0x18
    lsrs r2, r2, #0x18
    bne lbl_08004b7c
    bl reset_track
    movs r2, #0
    strb r2, [r4]
    b lbl_08004c00
lbl_08004b7c:
    ldr r7, [r4]
    movs r3, #2
    lsls r2, r7, #0x18
    lsrs r2, r2, #0x18
    ands r3, r2
    beq lbl_08004ba2
    movs r3, #0x1d
    ldrb r3, [r4, r3]
    cmp r3, #0
    beq lbl_08004b9c
    lsls r1, r6, #8
    lsrs r1, r1, #0x18
    lsrs r2, r7, #0x18
    cmp r2, r1
    ble lbl_08004b9c
    b lbl_08004c0e
lbl_08004b9c:
    adds r0, r4, #0
    bl reset_track
lbl_08004ba2:
    movs r3, #2
    lsls r2, r6, #8
    orrs r2, r3
    ldr r0, [r5, #4]
    str r2, [r4]
    str r0, [r4, #0x14]
    str r5, [r4, #0x10]
    lsls r3, r3, #7
    strh r3, [r4, #0xc]
    lsrs r2, r6, #0x1f
    beq lbl_08004bbe
    lsrs r0, r6, #0x18
    bl DoSoundAction
lbl_08004bbe:
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    ldr r7, [r4, #0x18]
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r7, #0
    movs r3, #0x50
    muls r3, r6, r3
    bl BitFill
    movs r0, #1
    movs r2, #0x40
    lsls r1, r2, #0x10
    lsls r2, r2, #8
    orrs r1, r2
    movs r3, #0xc
    lsls r3, r3, #8
    movs r2, #2
    orrs r2, r3
    adds r5, #8
    b lbl_08004bf4
lbl_08004bec:
    subs r6, #1
    beq lbl_08004c00
    adds r7, #0x50
    adds r5, #4
lbl_08004bf4:
    ldr r3, [r5]
    strb r0, [r7]
    strh r2, [r7, #0x1a]
    str r1, [r7, #4]
    str r3, [r7, #0x24]
    b lbl_08004bec
lbl_08004c00:
    movs r6, #0
    strb r6, [r4, #0x1c]
lbl_08004c04:
    movs r0, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
lbl_08004c0e:
    movs r6, #0
    strb r6, [r4, #0x1c]
    movs r0, #1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start stop_music_or_sound
stop_music_or_sound: @ 0x08004c1c
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, #0x1c]
    cmp r6, #0
    bne lbl_08004c8c
    movs r6, #1
    strb r6, [r7, #0x1c]
    ldrb r6, [r7, #0x1e]
    movs r5, #1
    ands r5, r6
    bne lbl_08004c88
    ldrb r4, [r7]
    movs r5, #2
    ands r4, r5
    beq lbl_08004c88
    movs r4, #1
    strb r4, [r7]
    movs r4, #0
    strb r4, [r7, #4]
    ldrb r6, [r7, #1]
    ldr r5, [r7, #0x18]
    b lbl_08004c4e
lbl_08004c48:
    subs r6, #1
    beq lbl_08004c88
    adds r5, #0x50
lbl_08004c4e:
    ldr r4, [r5, #0x4c]
    cmp r4, #0
    beq lbl_08004c6a
    movs r3, #7
    movs r2, #0x34
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl sub_080024c0
    movs r3, #0
    strb r3, [r4]
    str r3, [r4, #0x24]
lbl_08004c6a:
    ldr r0, [r5, #0x48]
    movs r1, #0
lbl_08004c6e:
    cmp r0, #0
    beq lbl_08004c80
    ldr r2, [r0, #0x30]
    strb r1, [r0]
    str r1, [r0, #0x28]
    str r1, [r0, #0x30]
    str r1, [r0, #0x2c]
    adds r0, r2, #0
    b lbl_08004c6e
lbl_08004c80:
    movs r0, #0
    str r0, [r5, #0x4c]
    str r0, [r5, #0x48]
    b lbl_08004c48
lbl_08004c88:
    movs r6, #0
    strb r6, [r7, #0x1c]
lbl_08004c8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start reset_track
reset_track: @ 0x08004c94
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, #0x1e]
    movs r5, #1
    ands r5, r6
    bne lbl_08004cf6
    ldrb r4, [r7]
    movs r5, #2
    ands r4, r5
    beq lbl_08004cf6
    movs r4, #1
    strb r4, [r7]
    movs r4, #0
    strb r4, [r7, #4]
    ldrb r6, [r7, #1]
    ldr r5, [r7, #0x18]
    b lbl_08004cbc
lbl_08004cb6:
    subs r6, #1
    beq lbl_08004cf6
    adds r5, #0x50
lbl_08004cbc:
    ldr r4, [r5, #0x4c]
    cmp r4, #0
    beq lbl_08004cd8
    movs r3, #7
    movs r2, #0x34
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl sub_080024c0
    movs r3, #0
    strb r3, [r4]
    str r3, [r4, #0x24]
lbl_08004cd8:
    ldr r0, [r5, #0x48]
    movs r1, #0
lbl_08004cdc:
    cmp r0, #0
    beq lbl_08004cee
    ldr r2, [r0, #0x30]
    strb r1, [r0]
    str r1, [r0, #0x28]
    str r1, [r0, #0x30]
    str r1, [r0, #0x2c]
    adds r0, r2, #0
    b lbl_08004cdc
lbl_08004cee:
    movs r0, #0
    str r0, [r5, #0x4c]
    str r0, [r5, #0x48]
    b lbl_08004cb6
lbl_08004cf6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08004cfc
sub_08004cfc: @ 0x08004cfc
    adds r3, r0, #0
    ldr r0, [r3, #0xc]
    lsls r1, r0, #0x10
    adds r1, r0, r1
    lsrs r1, r1, #0x10
    movs r2, #0xff
    lsls r0, r2, #8
    ands r0, r1
    beq lbl_08004d14
    lsrs r0, r1, #8
    ands r1, r2
    b lbl_08004d16
lbl_08004d14:
    movs r0, #0
lbl_08004d16:
    strh r1, [r3, #0xe]
    bx lr
    .align 2, 0

    thumb_func_start sub_08004d1c
sub_08004d1c: @ 0x08004d1c
    ldr r2, [r1, #0x24]
    ldrb r3, [r2, #1]
    adds r2, #2
    str r2, [r1, #0x24]
    lsls r2, r3, #1
    strh r2, [r0, #0xa]
    cmp r2, #0x96
    beq lbl_08004d3c
    movs r1, #0x1b
    movs r3, #0x4e
    lsls r1, r1, #8
    orrs r1, r3
    lsls r2, r2, #8
    muls r1, r2, r1
    lsrs r1, r1, #0x14
    b lbl_08004d40
lbl_08004d3c:
    movs r1, #1
    lsls r1, r1, #8
lbl_08004d40:
    movs r3, #0
    strh r1, [r0, #0xc]
    strh r3, [r0, #0xe]
    bx lr

    thumb_func_start UpdateAudio
UpdateAudio: @ 0x08004d48
    push {r4, r5, r6, lr}
    ldr r4, lbl_08004df4 @ =sMusicTrackDataROM
    ldr r5, lbl_08004df8 @ =gNumMusicPlayers
    ldr r6, lbl_08004dfc @ =gSoundQueue
    b lbl_08004d5c
lbl_08004d52:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004d72
    adds r4, #0xc
    adds r6, #8
lbl_08004d5c:
    ldrb r3, [r6]
    cmp r3, #0
    beq lbl_08004d52
    ldr r0, [r4]
    ldr r1, [r6, #4]
    bl sub_08004b50
    movs r0, #0
    str r0, [r6]
    str r0, [r6, #4]
    b lbl_08004d52
lbl_08004d72:
    ldr r4, lbl_08004e00 @ =sMusicTrackDataROM
    ldr r6, lbl_08004e04 @ =gMusicInfo
    movs r0, #0x21
    ldrb r0, [r6, r0]
    movs r1, #0x80
    ands r1, r0
    beq lbl_08004d92
    movs r1, #0x7f
    ands r0, r1
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dd8
    adds r4, #0xc
    ldr r5, lbl_08004e08 @ =gNumMusicPlayers
    subs r5, #1
    b lbl_08004da8
lbl_08004d92:
    movs r0, #0x21
    ldrb r0, [r6, r0]
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dbc
    ldr r5, lbl_08004e0c @ =gNumMusicPlayers
    b lbl_08004da8
lbl_08004da0:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004dd8
    adds r4, #0xc
lbl_08004da8:
    ldr r0, [r4]
    cmp r0, #0
    beq lbl_08004da0
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004da0
    bl sub_08001850
    b lbl_08004da0
lbl_08004dbc:
    movs r0, #0x20
    ldrb r0, [r6, r0]
    movs r1, #0
    cmp r0, r1
    beq lbl_08004dc8
    movs r1, #0xc
lbl_08004dc8:
    adds r4, r4, r1
    ldr r0, [r4]
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004dd8
    bl sub_08001850
lbl_08004dd8:
    ldrb r5, [r6, #1]
    cmp r5, #0
    bne lbl_08004dea
    movs r5, #1
    strb r5, [r6, #1]
    bl sub_08001458
    bl sub_080010c4
lbl_08004dea:
    movs r0, #0
    strb r0, [r6, #1]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004df4: .4byte sMusicTrackDataROM
lbl_08004df8: .4byte gNumMusicPlayers
lbl_08004dfc: .4byte gSoundQueue
lbl_08004e00: .4byte sMusicTrackDataROM
lbl_08004e04: .4byte gMusicInfo
lbl_08004e08: .4byte gNumMusicPlayers
lbl_08004e0c: .4byte gNumMusicPlayers

    thumb_func_start sub_08004e10
sub_08004e10: @ 0x08004e10
    push {r4, r5, lr}
    ldr r1, [r0, #0x40]
    ldrb r2, [r0, #1]
    ldrb r3, [r0]
    movs r4, #0xf0
    ands r3, r4
    cmp r3, #0x80
    bne lbl_08004e40
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
    ldrb r2, [r1, #1]
    movs r3, #0x35
    strb r2, [r0, r3]
    ldrb r2, [r1, #3]
    cmp r2, #0
    bne lbl_08004e38
    movs r2, #0x40
    strb r2, [r0, #6]
    b lbl_08004e4c
lbl_08004e38:
    subs r2, #0x80
    bmi lbl_08004e4c
    strb r2, [r0, #6]
    b lbl_08004e4c
lbl_08004e40:
    ldr r3, [r0, #0x44]
    adds r3, r3, r2
    ldrb r3, [r3]
    movs r4, #0xc
    muls r3, r4, r3
    adds r1, r1, r3
lbl_08004e4c:
    ldr r2, [r1]
    lsls r3, r2, #0x18
    lsrs r3, r3, #0x18
    movs r4, #0x34
    strb r3, [r0, r4]
    lsls r4, r2, #8
    lsrs r4, r4, #0x18
    movs r5, #0x36
    strb r4, [r0, r5]
    movs r4, #7
    ands r3, r4
    bne lbl_08004e6a
    ldr r3, [r1, #4]
    str r3, [r0, #0x38]
    b lbl_08004eaa
lbl_08004e6a:
    cmp r3, #2
    bgt lbl_08004e88
    lsrs r3, r2, #0x18
    movs r4, #0x80
    ands r4, r3
    bne lbl_08004e7e
    movs r4, #0x70
    ands r4, r3
    beq lbl_08004e7e
    b lbl_08004e80
lbl_08004e7e:
    movs r3, #8
lbl_08004e80:
    movs r4, #0x37
    strb r3, [r0, r4]
    movs r4, #6
    b lbl_08004ea2
lbl_08004e88:
    cmp r3, #3
    bne lbl_08004e9c
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [r5, #4]
    bl sub_080050d0
    adds r0, r4, #0
    adds r1, r5, #0
    b lbl_08004eaa
lbl_08004e9c:
    cmp r3, #4
    bne lbl_08004eaa
    movs r4, #3
lbl_08004ea2:
    ldr r3, [r1, #4]
    lsls r3, r4
    movs r4, #0x38
    strb r3, [r0, r4]
lbl_08004eaa:
    ldr r2, [r1, #8]
    str r2, [r0, #0x3c]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08004eb4
sub_08004eb4: @ 0x08004eb4
    movs r1, #0x19
    ldrsb r1, [r0, r1]
    cmp r1, #0
    ble lbl_08004ebe
    adds r1, #1
lbl_08004ebe:
    ldr r2, [r0, #0x1c]
    ldrb r3, [r0, #0x1a]
    muls r1, r3, r1
    lsls r1, r1, #2
    lsls r3, r2, #0x18
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #0x10
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #8
    asrs r3, r3, #0x16
    lsls r3, r3, #2
    adds r1, r1, r3
    lsrs r2, r2, #0x18
    adds r1, r1, r2
    movs r3, #0x10
    ldr r2, [r0, r3]
    movs r3, #0xff
    ands r3, r2
    beq lbl_08004f06
    movs r3, #0xff
    lsls r3, r3, #8
    ands r3, r2
    beq lbl_08004f06
    lsls r3, r2, #8
    lsrs r3, r3, #0x18
    cmp r3, #0
    bne lbl_08004f06
    asrs r2, r2, #0x18
    lsls r2, r2, #2
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
lbl_08004f06:
    asrs r2, r1, #8
    strb r2, [r0, #0x17]
    strb r1, [r0, #0x18]
    bx lr
    .align 2, 0

    thumb_func_start sub_08004f10
sub_08004f10: @ 0x08004f10
    push {r4}
    ldr r1, [r0, #4]
    lsls r2, r1, #0x18
    lsrs r2, r2, #0x18
    lsls r3, r1, #0x10
    lsrs r3, r3, #0x18
    muls r2, r3, r2
    lsrs r2, r2, #5
    ldrh r3, [r0, #0x12]
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #1
    bne lbl_08004f3a
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r4, #0x41
    muls r2, r4, r2
    asrs r2, r2, #6
    cmp r2, #0xff
    blt lbl_08004f3a
    movs r2, #0xff
lbl_08004f3a:
    lsls r4, r1, #8
    lsrs r4, r4, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r4
    subs r1, #0x40
    cmp r1, #0x3f
    blt lbl_08004f4c
    movs r1, #0x3f
    b lbl_08004f56
lbl_08004f4c:
    movs r4, #0x40
    rsbs r4, r4, #0
    cmp r1, r4
    bpl lbl_08004f56
    rsbs r1, r4, #0
lbl_08004f56:
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #2
    bne lbl_08004f74
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r1, r1, r4
    cmp r1, #0x3f
    blt lbl_08004f6c
    movs r1, #0x3f
    b lbl_08004f74
lbl_08004f6c:
    movs r4, #0x40
    adds r3, r1, r4
    bpl lbl_08004f74
    rsbs r1, r4, #0
lbl_08004f74:
    movs r4, #0x40
    adds r3, r1, r4
    muls r3, r2, r3
    lsrs r3, r3, #7
    subs r4, r4, r1
    muls r4, r2, r4
    lsrs r4, r4, #7
    lsls r4, r4, #8
    orrs r3, r4
    strh r3, [r0, #8]
    pop {r4}
    bx lr

    thumb_func_start sub_08004f8c
sub_08004f8c: @ 0x08004f8c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldrb r1, [r4, #0x13]
    movs r2, #2
    orrs r1, r2
    strb r1, [r4, #0x13]
    bl sub_080020a4
    ldr r0, [r5, #0x48]
    cmp r0, #0
    beq lbl_08004fa8
    str r4, [r0, #0x2c]
lbl_08004fa8:
    str r0, [r4, #0x30]
    movs r1, #0
    str r1, [r4, #0x2c]
    str r5, [r4, #0x28]
    str r4, [r5, #0x48]
    movs r1, #0x34
    ldrb r0, [r5, r1]
    ldrb r1, [r5, #6]
    lsls r0, r0, #8
    lsls r6, r6, #0x10
    lsls r1, r1, #0x18
    movs r2, #1
    orrs r0, r1
    orrs r0, r2
    orrs r0, r6
    str r0, [r4]
    ldr r0, [r5, #0x3c]
    str r0, [r4, #8]
    ldr r0, [r5, #0xc]
    str r0, [r4, #0xc]
    movs r1, #0x10
    movs r2, #0xc
    ldr r0, [r5, #0x38]
    adds r1, r1, r0
    adds r2, r2, r0
    str r0, [r4, #0x20]
    str r1, [r4, #0x24]
    str r2, [r4, #0x14]
    ldrh r1, [r5]
    lsrs r2, r1, #8
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    strb r2, [r4, #6]
    movs r3, #0xf0
    ands r1, r3
    cmp r1, #0x80
    bne lbl_08004ff6
    movs r3, #0x35
    ldrb r2, [r5, r3]
lbl_08004ff6:
    strb r2, [r4, #7]
    movs r3, #0x17
    ldrsb r1, [r5, r3]
    adds r1, r1, r2
    bmi lbl_08005008
    cmp r1, #0x7f
    ble lbl_0800500a
    movs r1, #0x7f
    b lbl_0800500a
lbl_08005008:
    movs r1, #0
lbl_0800500a:
    ldrb r2, [r5, #0x18]
    bl Midikey2Freq
    ldr r1, lbl_0800502c @ =gMusicInfo
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_0800501e
    movs r0, #0x40
    lsls r0, r0, #8
    b lbl_08005024
lbl_0800501e:
    ldr r1, [r1, #0x18]
    bl sub_08004abc
lbl_08005024:
    str r0, [r4, #0x1c]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800502c: .4byte gMusicInfo

    thumb_func_start sub_08005030
sub_08005030: @ 0x08005030
    ldr r1, [r0, #0x24]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_0800503e
    ldr r2, [r1]
    b lbl_0800506a
lbl_0800503e:
    movs r2, #1
    ands r2, r1
    bne lbl_08005050
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    b lbl_0800506a
lbl_08005050:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
lbl_0800506a:
    str r2, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start sub_08005070
sub_08005070: @ 0x08005070
    ldr r1, [r0, #0x24]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_08005080
    ldr r2, [r1]
    adds r1, #4
    b lbl_080050b0
lbl_08005080:
    movs r2, #1
    ands r2, r1
    bne lbl_08005094
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #2
    b lbl_080050b0
lbl_08005094:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
    adds r1, #1
lbl_080050b0:
    str r2, [r0, #0x24]
    adds r0, #0x28
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    bne lbl_080050cc
lbl_080050ca:
    str r1, [r0]
lbl_080050cc:
    bx lr
    .align 2, 0

    thumb_func_start sub_080050d0
sub_080050d0: @ 0x080050d0
    ldr r3, lbl_080050fc @ =0x04000070
    movs r2, #0x40
    strb r2, [r3]
    ldr r1, lbl_08005100 @ =0x04000090
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    movs r2, #0
    strb r2, [r3]
    bx lr
    .align 2, 0
lbl_080050fc: .4byte 0x04000070
lbl_08005100: .4byte 0x04000090

    thumb_func_start sub_08005104
sub_08005104: @ 0x08005104
    push {r4, r5}
    ldr r4, [r0, #0x10]
    ldrh r5, [r0, #0x14]
    ldr r1, [r0, #0x24]
    movs r2, #0x34
    ldrb r1, [r1, r2]
    cmp r1, #8
    ble lbl_0800513e
    movs r2, #4
    movs r3, #0x89
    lsls r2, r2, #0x18
    orrs r2, r3
    ldrb r2, [r2]
    lsrs r2, r2, #6
    lsls r2, r2, #6
    movs r3, #0x40
    cmp r2, r3
    bge lbl_0800512c
    adds r5, #2
    b lbl_08005134
lbl_0800512c:
    movs r3, #0x80
    cmp r2, r3
    bge lbl_0800513e
    adds r5, #1
lbl_08005134:
    movs r2, #0xc7
    movs r3, #0xfe
    lsls r2, r2, #8
    orrs r2, r3
    ands r5, r2
lbl_0800513e:
    movs r2, #4
    movs r3, #0x60
    lsls r2, r2, #0x18
    orrs r2, r3
    movs r3, #7
    ands r1, r3
    lsls r3, r4, #8
    lsrs r3, r3, #0x10
    cmp r1, #1
    beq lbl_08005160
    cmp r1, #2
    beq lbl_08005172
    cmp r1, #3
    beq lbl_08005178
    cmp r1, #4
    beq lbl_08005180
    b lbl_08005184
lbl_08005160:
    strb r4, [r2]
    strh r3, [r2, #2]
    strh r5, [r2, #4]
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    strh r5, [r2, #4]
    b lbl_08005184
lbl_08005172:
    strh r3, [r2, #8]
    strh r5, [r2, #0xc]
    b lbl_08005184
lbl_08005178:
    strb r4, [r2, #0x10]
    strh r3, [r2, #0x12]
    strh r5, [r2, #0x14]
    b lbl_08005184
lbl_08005180:
    strh r3, [r2, #0x18]
    strh r5, [r2, #0x1c]
lbl_08005184:
    lsls r5, r5, #0x11
    lsrs r5, r5, #0x11
    strh r5, [r0, #0x14]
    pop {r4, r5}
    bx lr
    .align 2, 0
    