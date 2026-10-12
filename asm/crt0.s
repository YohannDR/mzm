    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

    arm_func_start _start
_start: @ 0x080000c0
    mov r0, #PSR_IRQ_MODE
    msr cpsr_fc, r0
    ldr sp, gSpIrq_ptr
    mov r0, #PSR_SYS_MODE
    msr cpsr_fc, r0
    ldr sp, gSpSys_ptr
    ldr r1, gIntrVector_ptr
    adr r0, IntrMain
    str r0, [r1]
    ldr r1, agbmain_ptr
    mov lr, pc
    bx r1
    b _start

@ pool
gSpSys_ptr: .4byte 0x03007e60
gSpIrq_ptr: .4byte 0x03007fa0
gIntrVector_ptr: .4byte gIntrVector
agbmain_ptr: .4byte agbmain

    arm_func_start IntrMain
IntrMain: @ 0x08000104
    mov r3, REG_BASE
    add r3, r3, REG_IE_OFFSET
    ldr r2, [r3]
    ldrh r1, [r3, (REG_IME_OFFSET - REG_IE_OFFSET)] @ Interrupt Master Enable
    mrs r0, spsr
    push {r0-r3, lr}
    mov r0, 1
    strh r0, [r3, (REG_IME_OFFSET - REG_IE_OFFSET)] @ Interrupt Master Enable
    and r1, r2, r2, lsr 16
    mov ip, 0
    ands r0, r1, INTR_FLAG_GAMEPAK
    strbne r0, [r3, (REG_SOUNDCNT_X_OFFSET - REG_IE_OFFSET)]
    bne . @ spin
    mov ip, 0
    ands r0, r1, INTR_FLAG_DMA2
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_SERIAL
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_TIMER3
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_VBLANK
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_HBLANK
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_VCOUNT
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_TIMER0
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_TIMER1
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_TIMER2
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_DMA0
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_DMA1
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_DMA3
    bne interrupt_found
    add ip, ip, 4
    ands r0, r1, INTR_FLAG_KEYPAD
interrupt_found:
    strh r0, [r3, (REG_IF_OFFSET - REG_IE_OFFSET)]
    ldr r1, lbl_08000234
    bic r2, r2, r0
    and r1, r1, r2
    strh r1, [r3, (REG_IE_OFFSET - REG_IE_OFFSET)]
    mrs r3, apsr
    bic r3, r3, (PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK)
    orr r3, r3, PSR_SYS_MODE
    msr cpsr_fc, r3
    ldr r1, lbl_08000238 @ =sIntrTable
    add r1, r1, ip
    ldr r0, [r1]
    stmdb sp!, {lr}
    adr lr, interrupt_return
    bx r0
interrupt_return:
    ldmfd sp!, {lr}
    mrs r3, cpsr_fc
    bic r3, r3, (PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK)
    orr r3, r3, (PSR_I_BIT | PSR_IRQ_MODE)
    msr cpsr_fc, r3
    pop {r0-r3, lr}
    strh r2, [r3, (REG_IE_OFFSET - REG_IE_OFFSET)]
    strh r1, [r3, (REG_IME_OFFSET - REG_IE_OFFSET)]
    msr spsr_fc, r0
    bx lr

@ pool
lbl_08000234: .4byte (INTR_FLAG_GAMEPAK | INTR_FLAG_DMA2 | INTR_FLAG_SERIAL | INTR_FLAG_TIMER3)
lbl_08000238: .4byte sIntrTable
