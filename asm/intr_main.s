    .include "asm/constants.inc"
    .include "asm/macros.inc"

    arm_func_start intr_main
intr_main: @ 0x08000104
    mov r3, #REG_BASE
    add r3, r3, #REG_IE_OFFSET
    ldr r2, [r3]
    ldrh r1, [r3, #(REG_IME_OFFSET - REG_IE_OFFSET)] @ Interrupt Master Enable
    mrs r0, spsr
    stmfd sp!, {r0-r3, lr}
    mov r0, #1
    strh r0, [r3, #(REG_IME_OFFSET - REG_IE_OFFSET)] @ Interrupt Master Enable
    and r1, r2, r2, lsr #16
    mov ip, #0
    ands r0, r1, #INTR_FLAG_GAMEPAK
    strneb r0, [r3, #(REG_SOUNDCNT_X_OFFSET - REG_IE_OFFSET)]
lbl_08000134:
    bne lbl_08000134
    mov ip, #0
    ands r0, r1, #INTR_FLAG_DMA2
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_SERIAL
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_TIMER3
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_VBLANK
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_HBLANK
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_VCOUNT
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_TIMER0
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_TIMER1
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_TIMER2
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_DMA0
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_DMA1
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_DMA3
    bne interrupt_found
    add ip, ip, #4
    ands r0, r1, #INTR_FLAG_KEYPAD
interrupt_found:
    strh r0, [r3, #(REG_IF_OFFSET - REG_IE_OFFSET)]
    ldr r1, lbl_08000234
    bic r2, r2, r0
    and r1, r1, r2
    strh r1, [r3]
    mrs r3, apsr
    bic r3, r3, #(PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK)
    orr r3, r3, #PSR_SYS_MODE
    msr cpsr_fc, r3
    ldr r1, lbl_08000238
    add r1, r1, ip
    ldr r0, [r1]
    stmdb sp!, {lr}
    add lr, pc, #0x0 @ lbl_0800020C
    bx r0

lbl_0800020C:
    .byte 0x00, 0x40, 0xBD, 0xE8
    .byte 0x00, 0x30, 0x0F, 0xE1, 0xDF, 0x30, 0xC3, 0xE3, 0x92, 0x30, 0x83, 0xE3, 0x03, 0xF0, 0x29, 0xE1
    .byte 0x0F, 0x40, 0xBD, 0xE8, 0xB0, 0x20, 0xC3, 0xE1, 0xB8, 0x10, 0xC3, 0xE1, 0x00, 0xF0, 0x69, 0xE1
    .byte 0x1E, 0xFF, 0x2F, 0xE1

@ pool
lbl_08000234: .4byte 0x000024C0
lbl_08000238: .4byte 0x0808CA9C
