    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

    arm_func_start _start
_start: @ 0x087d80d4
	mov r12, r0 @ r12 = r0 = 0x08000000
	@ r11 = 0x087d8124
	add r11, pc, #0x44 @ =_087d8124

	@ r0 = 0x087D8114
	add r0, pc, #0x30 @ =_087D8114
	@ r1 = 0x00000012
	@ r2 = 0x03007FA0 (sp_irq)
	@ r3 = 0x00000013
	@ r4 = 0x0000001F
	ldm r0, {r1, r2, r3, r4}

	msr cpsr_fc, r1   @ cpsr = 0x12 (IRQ)
	mov sp, r2        @ sp = 0x03007FA0 (sp_irq)

	msr cpsr_fc, r3   @ cpsr = 0x13 (SWI)
	add sp, r2, #0x40 @ sp = 0x03007FA0 + 0x40 = 0x03007FE0 (sp_svc)

	msr cpsr_fc, r4   @ cpsr = 0x1F (system? privileged user mode?)
	sub sp, r2, #0xa0 @ sp = 0x03007FA0 - 0xA0 = 0x03007F00 (sp_usr)

	@ r0 = 0x087D8148
	add r0, pc, #0x44  @ =_087D8148
	sub r1, sp, #0xb00 @ r1 = 0x03007F00 - 0xB00 = 0x03007400
	@ r4 = 0x040000D4 (DMA3SAD - DMA 3 Source Address)
	@ r5 = 0x13850021 (???)
	ldm r0!, {r4, r5}
	push {r0, r1, r11, r12}
	@ LZ77UnCompReadNormalWrite8bit(r0 = src = 0x087D8150, r1 = dst = 0x03007400)
	svc #0x110000
	@ r0 = 0x087D8150
	@ pc = 0x03007400
	pop {r0, pc}
	.align 2, 0
_087D8114: .4byte 0x00000012
_087D8118: .4byte 0x03007FA0
_087D811C: .4byte 0x00000013
_087D8120: .4byte 0x0000001F

	arm_func_start _087d8124
_087d8124: @ 0x087d8124
	@ set thumb mode magic
	orr r1, pc, #1
	bx r1

	thumb_func_start _087d812c
_087d812c: @ 0x087d812c
	movs r0, #0xfb

	@ 0x04000208 (IME) = 0
	ldr r3, _087D8140 @ =0x04000208
	movs r2, #0
	strb r2, [r3]

	@ soft reset re-entry = 0 (re-entry at 0x08000000)
	ldr r3, _087D8144 @ =0x03007FFA
	movs r2, #0
	strb r2, [r3]

	@ r3 = 0x03007FFA - 0xFA = 0x03007F00 (sp_usr)
	subs r3, #0xfa
	@ RegisterRamReset (r0 = 0xfb, all flags except palette)
	svc #1
	@ SoftReset (to 0x08000000)
	svc #0
	.align 2, 0
_087D8140: .4byte 0x04000208
_087D8144: .4byte 0x03007FFA
_087D8148: .4byte 0x040000D4
_087D814C:
.ifdef REGION_JP
    .4byte 0x141D0021
.else
    .4byte 0x13850021
.endif
