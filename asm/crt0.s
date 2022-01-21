    .include "asm/macros.s"
    .include "asm/constants.s"

    arm_func_start _start
_start:
    mov r0, #PSR_IRQ_MODE
    msr cpsr_fc, r0
    ldr sp, sp_irq
    mov r0, #PSR_SYS_MODE
    msr cpsr_fc, r0
    ldr sp, sp_sys
    ldr r1, intr_vector_start
    add r0, pc, #0x20 // intr_vector_start
    str r0, [r1]
    ldr r1, main_loop_ptr
    mov lr, pc
    bx r1
    b _start

sp_sys: .4byte 0x03007e60
sp_irq: .4byte 0x03007fa0
intr_vector_start: .4byte 0x03007ffc
main_loop_ptr: .4byte 0x0800023d
