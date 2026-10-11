    .include "asm/constants.inc"
    .include "asm/macros.inc"
	.include "asm/emulator_constants.inc"

    .syntax unified

	.section .rodata

	.4byte 7159092
	.4byte 1789773

	.global sEmulatorAudio_NoiseSampleRateTable
sEmulatorAudio_NoiseSampleRateTable:
	.4byte 447443
	.4byte 223722
	.4byte 111861
	.4byte 55930
	.4byte 27965
	.4byte 18643
	.4byte 13983
	.4byte 11186
	.4byte 8860
	.4byte 7046
	.4byte 4710
	.4byte 3523
	.4byte 2349

	.4byte 1762
	.4byte 880
	.4byte 875

	.section .text

	thumb_func_start sub_0600E048
sub_0600E048: @ 0x0600E048
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r0, #0
	str r1, [sp]
	ldr r5, _0600E0E0 @ =sUnk_03005840
_0600E05A:
	movs r0, #0x92
	lsls r0, r0, #4
	cmp r2, r0
	bne _0600E05A
	ldr r1, [sp]
	ldr r2, _0600E0E4 @ =0x00000924
	adds r0, r1, r2
	ldr r4, [r0]
	adds r4, #0xd0
	ldr r4, [r4]
	ldr r5, [r5]
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0x12
	ldr r3, _0600E0E8 @ =0x0600B800
	adds r3, #0x80
	mov r10, r3
	movs r7, #1
	movs r5, #0xf8
	lsls r5, r5, #5
	movs r0, #0x80
	lsls r0, r0, #4
	mov r9, r0
_0600E088:
	mov r1, r10
	adds r1, #0x80
	str r1, [sp, #4]
	adds r2, r7, #1
	str r2, [sp, #8]
	mov r8, r7
	mov r3, r8
	movs r0, #7
	ands r3, r0
	mov r8, r3
	mov r4, r10
	ldr r6, _0600E0E8 @ =0x0600B800
	mov r12, r7
	mov r1, r12
	movs r2, #1
	ands r1, r2
	mov r12, r1
_0600E0AA:
	ldrh r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	movs r3, #0x1f
	ands r2, r3
	lsrs r3, r0, #0x1a
	mov r0, r8
	cmp r0, #0
	bne _0600E0EC
	movs r0, #0x3a
	muls r1, r0, r1
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	b _0600E0FE
	.align 2, 0
_0600E0E0: .4byte sUnk_03005840
_0600E0E4: .4byte 0x00000924
_0600E0E8: .4byte 0x0600B800
_0600E0EC:
	movs r0, #0x4d
	muls r1, r0, r1
	movs r0, #0x97
	muls r0, r2, r0
	adds r1, r1, r0
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r1, r1, r0
_0600E0FE:
	cmp r1, r5
	bls _0600E106
	movs r1, #0xf8
	lsls r1, r1, #5
_0600E106:
	adds r3, r1, #0
	adds r2, r3, #0
	mov r0, r12
	cmp r0, #0
	beq _0600E11C
	mov r0, r9
	adds r1, r3, r0
	cmp r1, r5
	bls _0600E11C
	movs r1, #0xf8
	lsls r1, r1, #5
_0600E11C:
	movs r0, #2
	ands r0, r7
	cmp r0, #0
	beq _0600E12E
	add r2, r9
	cmp r2, r5
	bls _0600E12E
	movs r2, #0xf8
	lsls r2, r2, #5
_0600E12E:
	movs r0, #4
	ands r0, r7
	cmp r0, #0
	beq _0600E140
	add r3, r9
	cmp r3, r5
	bls _0600E140
	movs r3, #0xf8
	lsls r3, r3, #5
_0600E140:
	lsrs r1, r1, #8
	ands r2, r5
	lsrs r0, r2, #3
	orrs r1, r0
	ands r3, r5
	lsls r0, r3, #2
	orrs r1, r0
	strh r1, [r4]
	adds r4, #2
	adds r6, #2
	mov r0, r10
	adds r0, #0x7e
	cmp r4, r0
	bls _0600E0AA
	ldr r1, [sp, #4]
	mov r10, r1
	ldr r7, [sp, #8]
	cmp r7, #0xf
	bls _0600E088
	ldr r2, [sp]
	ldr r3, _0600E1BC @ =0x00000924
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, #0xcc
	ldr r1, [r0]
	adds r6, r1, #0
	adds r6, #0x64
	subs r3, #0xd0
	adds r0, r2, r3
	ldr r2, _0600E1C0 @ =0x0000FFFF
	mov r10, r2
	ldr r0, [r0]
	mov r8, r0
	mov r9, r1
	movs r7, #0x18
_0600E186:
	mov r3, r9
	adds r3, #4
	mov r9, r3
	subs r3, #4
	ldm r3!, {r5}
	adds r4, r5, #0
	mov r0, r10
	ands r4, r0
	lsls r4, r4, #4
	add r4, r8
	adds r0, r6, #0
	adds r1, r4, #0
	svc #0x11
	lsrs r5, r5, #0x10
	adds r6, r6, r5
	subs r7, #1
	cmp r7, #0
	bge _0600E186
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0600E1BC: .4byte 0x00000924
_0600E1C0: .4byte 0x0000FFFF

	arm_func_start sub_0600E1C4
sub_0600E1C4: @ 0x0600E1C4
	mov r4, #0x4000000
	mov r1, #0x1000
	orr r1, r1, #0x60
	strh r1, [r4] @ REG_DISPCNT = 0x1060 (H-Blank Interval Free, One dimension OBJ Character VRAM Mapping, Screen Display OBJ=on)
	add r5, r4, #0x208
	mov r0, #0
	strh r0, [r5] @ REG_IME = 0 (disable interrupts)
	add r6, r4, #0x100
	strh r0, [r6, #2]   @ REG_TM0CNT_H = 0
	strh r0, [r6, #6]   @ REG_TM1CNT_H = 0
	strh r0, [r6, #0xa] @ REG_TM2CNT_H = 0
	strh r0, [r6, #0xe] @ REG_TM3CNT_H = 0
	mov r1, #8
	strh r1, [r4, #4] @ REG_DISPSTAT = 8 (V-Blank IRQ Enable) (why does debugger say 0xA?)
	mov r1, #0x31
	orr r1, r1, #0x2000
	strh r1, [r5, #-8] @ REG_IE = 0x2031 (Game Pak, Timer 2 Overflow, Timer 1 Overflow, LCD V-Blank)
	mvn r1, #0
	strh r1, [r5, #-6] @ REG_IF = 0xFFFF (acknowledge all interrupt requests)
	mov r1, #1
	strh r1, [r5] @ REG_IME = 1 (enable interrupts)
	@ EmulatorAudio_Initialize()
	ldr r4, _0600E234 @ =EmulatorAudio_Initialize
	add lr, pc, #0x0 @ =_0600E224
	bx r4
_0600E224:
	@ sub_03000368(SP_91C)
	@ goto _0600E23C
	ldr r4, _0600E238 @ =sub_03000368
	ldr r0, [sp, #SP_91C]
	add lr, pc, #0x8 @ =_0600E23C
	bx r4
	.align 2, 0
_0600E234: .4byte EmulatorAudio_Initialize
_0600E238: .4byte sub_03000368
_0600E23C:
	bl sub_0600EBF8
_0600E240:
	add lr, pc, #0x9C @ =sub_0600E2E4
	str lr, [sp, #SP_940] @ SP_940 = &sub_0600E2E4
_0600E248:
	ldrb r0, [sp, #SP_A30]
	cmp r0, #0    @ if SP_A30 == 0:
	beq _0600E274     @ goto _0600E274

	@ r0 = sub_0203E38C(SP, 0x0600A010) (always 0)
	add lr, pc, #0x14 @ =_0600E270
	mov r0, sp
	ldr r1, _0600E268 @ =0x0600A010
	ldr r12, _0600E26C @ =sub_0203E38C
	bx r12
	.align 2, 0
_0600E268: .4byte 0x0600A010
_0600E26C: .4byte sub_0203E38C

_0600E270:
	strb r0, [sp, #SP_A30] @ SP_A30 = r0 (always 0)
_0600E274:
	ldr r1, [sp, #SP_9B8]
	cmp r1, #0    @ if SP_9B8 == 0:
	beq _0600E290     @ goto _0600E290
	mov r2, #0
	str r2, [sp, #SP_9B8] @ SP_9B8 = 0
	@ sub_030030E8() with r1 = SP_9B8
	add lr, pc, #0x0 @ =_0600E290
	ldr pc, _0600E2BC @ =sub_030030E8

_0600E290:
	@ TODO: check if values are the same everytime
	@ Load 0x28 bytes from SP_884 to r3-r12
	@ r3-r4 = 0x00000000
	@ r5 = 0x030073FC
	@ r6 = 0x030073FF
	@ r7-r10 = 0x00000000
	@ r11 = 0x030029AC
	@ r12 = 0x030029F0
	add r0, sp, #0x800
	add r0, r0, #0x84
	ldm r0!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, r12}
	ldr r0, [r0] @ r0 = [SP_8AC] (always 0x00820000?)
	@ NOTE: this is a mirroring trick, the bits are ignored when accessing EWRAM
	bic sp, sp, #0xfe0000
	orr sp, sp, r0
	str pc, [sp, #0x9b0] @ SP_9B0 = 0x0600E2B4
	ldr r0, [sp, #0x9cc]
	add r0, r0, #1
	str r0, [sp, #0x9cc] @ SP_9CC += 1
	@ goto sub_03002E0C() with r5 = 0x030073FC, r12 = 0x030029F0 (no return)
	ldr pc, _0600E2C0 @ =sub_03002E0C
	.align 2, 0
_0600E2BC: .4byte sub_030030E8
_0600E2C0: .4byte sub_03002E0C

	arm_func_start sub_0600E2C4
sub_0600E2C4: @ 0x0600E2C4
	ldrb r0, [sp, #SP_A44]
	cmp r0, #0
	beq _0600E2E0
	ldr r0, [sp, #SP_914]
	cmp r0, #0
	ldrne pc, [sp, #SP_9BC]
	strb r0, [sp, #SP_A44]
_0600E2E0:
	ldr pc, [sp, #SP_940]

	arm_func_start sub_0600E2E4
sub_0600E2E4: @ 0x0600E2E4
	@ EmulatorReplaceCopyrightYear()
	add lr, pc, #0x8 @ =sub_0600E2F4
	ldr r12, _0600E2F0 @ =EmulatorReplaceCopyrightYear
	bx r12
	.align 2, 0
_0600E2F0: .4byte EmulatorReplaceCopyrightYear

	arm_func_start sub_0600E2F4
sub_0600E2F4: @ 0x0600E2F4
	@ EmulatorFillPasswordWithSaved(sp)
	mov r0, sp
	add lr, pc, #0x8 @ =sub_0600E308
	ldr r12, _0600E304 @ =EmulatorFillPasswordWithSaved
	bx r12
	.align 2, 0
_0600E304: .4byte EmulatorFillPasswordWithSaved

	arm_func_start sub_0600E308
sub_0600E308: @ 0x0600E308
	@ r0 = EmulatorRetrieveGameOverPassword(sp)
	mov r0, sp
	add lr, pc, #0x8 @ =sub_0600E31C
	ldr r12, _0600E318 @ =EmulatorRetrieveGameOverPassword
	bx r12
	.align 2, 0
_0600E318: .4byte EmulatorRetrieveGameOverPassword

	arm_func_start sub_0600E31C
sub_0600E31C: @ 0x0600E31C
	cmp r0, #0    @ if r0 != 0 (password retrieved):
	bne sub_0600E588     @ goto sub_0600E588
	ldrb r1, [sp, #SP_A33]
	cmp r1, #0
	bne _0600E340
	ldrb r1, [sp, #SP_A32]
	cmp r1, #0
	beq _0600E34C
	b sub_0600E6DC
_0600E340:
	mov r1, #0
	strb r1, [sp, #SP_A33]
	b _0600E60C
_0600E34C:
	ldr r0, [sp, #SP_914]
	cmp r0, #0xf
	moveq r1, #1
	strbeq r1, [sp, #SP_A2C]
	beq sub_0600EB34
	ldrb r1, [sp, #SP_A2C]
	cmp r1, #0
	cmpne r0, #0
	bne sub_0600EB34
	mov r1, #0
	strb r1, [sp, #SP_A2C]
	cmp r0, #0x300
	beq _0600E3B8
	add lr, pc, #0x4 @ =sub_0600E38C
	ldr pc, _0600E388 @ =sub_03002FAC
	.align 2, 0
_0600E388: .4byte sub_03002FAC

	arm_func_start sub_0600E38C
sub_0600E38C: @ 0x0600E38C
	add lr, pc, #0xC @ =sub_0600E3A0
	mov r0, #0x4000
	orr r0, r0, #0x15
	ldr r1, _0600E574 @ =EmulatorAudio_GetActiveChannels
	bx r1

	arm_func_start sub_0600E3A0
sub_0600E3A0: @ 0x0600E3A0
	ldr r1, [sp, #SP_908]
	and r1, r1, #0xc0
	bic r0, r0, #0xc0
	orr r1, r1, r0
	str r1, [sp, #SP_908]
	b _0600E248
_0600E3B8:
	mov r0, #0x41
	bl sub_06006E08 @ sub_06006E08(0x40|1) (Menu text)
	mov r0, #0
	strb r0, [sp, #SP_A45]
	strb r0, [sp, #SP_A43]
	bl sub_0600EB0C
	add lr, pc, #0x24 @ =sub_0600E3FC
_0600E3D4:
	str lr, [sp, #SP_940] @ SP_940 = lr
_0600E3D8:
	ldrb r0, [sp, #SP_A48]
	cmp r0, #0              @ if SP_A48 == 0:
	ldreq pc, [sp, #SP_9BC]     @ goto SP_9BC (sub_03005568())
	ldr r0, [sp, #SP_840]
_0600E3E8:
	ldr r1, [sp, #SP_840]
	cmp r0, r1
	svceq #0x20000
	beq _0600E3E8
	b sub_0600E2C4

	arm_func_start sub_0600E3FC
sub_0600E3FC: @ 0x0600E3FC
	ldrb r0, [sp, #SP_A45]
	cmp r0, #0x10
	addlo r0, r0, #1
	strblo r0, [sp, #SP_A45]
	mov r12, #0x4000000
	rsb r2, r0, #0x10
	orr r0, r0, r2, lsl #8
	strhlo r0, [r12, #0x52]
	mov r1, #0x3800
	orr r1, r1, #0x41
	strh r1, [r12, #0x50]
	mov r0, #1
	strbhs r0, [sp, #SP_A44]
	add lr, pc, #0x3C @ =sub_0600E474
	strhs lr, [sp, #SP_940]
	bl sub_0600EB18 @ sub_0600EB18() (Enable emulator text display)
	b _0600E3D8

	arm_func_start sub_0600E440
sub_0600E440: @ 0x0600E440
	mov r0, #0
	bl sub_0600EB1C @ sub_0600EB1C(0) (Disable emulator text display)
	ldrb r0, [sp, #SP_A2D]
	subs r0, r0, #1
	blo _0600E468
	strb r0, [sp, #SP_A2D]
	bne _0600E3D8
	add lr, pc, #0x4 @ =_0600E468
	ldr r2, _0600E578 @ =EmulatorAudio_Reset
	bx r2
_0600E468:
	bl sub_0600EB04
	sub lr, pc, #0x190
	b _0600E3D4

	@ Handle main menu
	arm_func_start sub_0600E474
sub_0600E474: @ 0x0600E474
	ldr r0, [sp, #SP_914]
	tst r0, #0xcf            @ if (SP_914 & 0xCF) != 0 (Pressing A, B, Select, Start, Up, or Down):
	strbne r0, [sp, #SP_A44]     @ SP_A44 = SP_914
	tst r0, #2    @ if (SP_914 & 2) != 0 (Pressing B):
	bne _0600E49C     @ goto _0600E49C
	and r1, r0, #0x300
	cmp r1, #0x300 @ if (SP_914 & 0x300) != 0x300 (Not pressing Left and Right):
	bne _0600E4B0      @ goto _0600E4B0
	mov r1, #1
	strb r1, [sp, #SP_A44] @ SP_A44 = 1
_0600E49C:
	mov r1, #0
	strb r1, [sp, #SP_A43] @ SP_A43 = 0
	sub lr, pc, #0x6c
	str lr, [sp, #SP_940] @ SP_940 = sub_0600E474
	b _0600EA9C
_0600E4B0:
	tst r0, #9
	ldrb r1, [sp, #SP_A43]     @ if (SP_A43 & 9) != 0:
	ldrne pc, [pc, r1, lsl #2]     @ goto _0600E4C0[SP_A43]
	beq _0600EA58
_0600E4C0:
	.4byte _0600E49C @ Continue
	.4byte sub_0600EC90 @ Quit Menu
	.4byte sub_0600E670 @ Reset Menu
	.4byte sub_0600E93C @ Sleep

	arm_func_start sub_0600E4D0
sub_0600E4D0: @ 0x0600E4D0
	mov r7, lr
	@ r0 = EmulatorLoadFromSram(src=r0, dst=SP_854, arg2=SP)
	ldr r1, [sp, #SP_854]
	mov r2, sp
	add lr, pc, #0x4 @ =_0600E4E8
	ldr r12, _0600E57C @ =EmulatorLoadFromSram
	bx r12
_0600E4E8:
	cmp r0, #0   @ if r0 == 0: (never true?)
	moveq r0, #4     @ r0 = 4
	bxeq r7          @ return r0

	@ Compare 0xC bytes between [SP_924 + 0xC0] and [SP_854]
	@ Return r0 = 2 if they're not equal
	ldr r3, [sp, #SP_924]
	add r3, r3, #0xc0
	add r1, r3, #0xc
	ldr r6, [sp, #SP_854]
_0600E504:
	ldr r2, [r3], #4
	ldr r8, [r6], #4
	cmp r2, r8
	movne r0, #2
	bxne r7
	cmp r3, r1
	blo _0600E504

	ldr r2, [sp, #SP_854]
	ldrh r6, [r2, #0xe] @ r6 = [SP_854 + 0xE]
	mov r1, #0
	strh r1, [r2, #0xe] @ [SP_854 + 0xE] = 0
	mov lr, r7

	arm_func_start sub_0600E534
sub_0600E534: @ 0x0600E534
	mov r7, lr

	@ Put [SP_854] through sub_03002DF0 until [SP_854 + r0]
	@ Likely creating a checksum for SP_854
	ldr r10, _0600E584 @ =0x0000C399
	ldr r2, [sp, #SP_854]
	mov r8, #0
	add r11, r2, r0
_0600E548:
	@ sub_03002DF0() with r8, r10, r9 parameters
	ldr r9, [r2], #4
	add lr, pc, #0x0 @ =0x0600E554
	ldr pc, _0600E580 @ =sub_03002DF0
	cmp r2, r11
	blo _0600E548

	cmp r8, r6   @ if r8 != r6:
	movne r0, #3     @ return r0 = 3
	bxne r7
	ldr r2, [sp, #SP_854]
	ldrb r0, [r2, #0xd]
	bx r7 @ return r0 = [SP_854 + 0xD]
	.align 2, 0
_0600E574: .4byte EmulatorAudio_GetActiveChannels
_0600E578: .4byte EmulatorAudio_Reset
_0600E57C: .4byte EmulatorLoadFromSram
_0600E580: .4byte sub_03002DF0
_0600E584: .4byte 0x0000C399

	@ Handle Game Over Menu
	arm_func_start sub_0600E588
sub_0600E588: @ 0x0600E588
	mov r0, #0x9c
	bl sub_06006E08 @ sub_06006E08(0x80|0x1C) (Clear text, then Game Over Save Request text)
	mov r1, #0
	strb r1, [sp, #SP_A43] @ SP_A43 = 0 (Yes option)
	mov r0, #0x10
	mov r12, #0x4000000
	rsb r2, r0, #0x10
	orr r0, r0, r2, lsl #8
	strh r0, [r12, #0x52] @ REG_BLDALPHA = (0x10 - 0x10) << 8 | (0x10) ()
	mov r1, #0x3800
	orr r1, r1, #0x41
	strh r1, [r12, #0x50] @ REG_BLDCNT = 0x3841 (Backdrop 2nd Target, OBJ 2nd Target, BG3 2nd Target, Alpha Blend, BG0 1st Target)
	bl sub_0600EB18 @ sub_0600EB18() (Enable emulator text display)
	bl _0600E3D4
	ldr r0, [sp, #SP_910]
	ldrb r1, [sp, #SP_A43] @ r1 = SP_A43
	tst r0, #0x30    @ if (SP_910 & 0x30) != 0 (Pressing Left or Right):
	eorne r1, r1, #1     @ r1 ^= 1 (Toggle option)
	tst r0, #2       @ if (SP_910 & 2) != 0 (Pressing B):
	movne r1, #1         @ r1 = 1 (No option)
	strb r1, [sp, #SP_A43] @ SP_A43 = r1
	tst r1, #1      @ if (r1 & 1) == 0:
	moveq r0, #0x1d     @ sub_06006E08(0x1D) (Game Over Select Yes text)
	movne r0, #0x1e @ else:
	bl sub_06006E08     @ sub_06006E08(0x1E) (Game Over Select No text)
	ldr r0, [sp, #SP_910]
	tst r0, #0xb  @ if (SP_910 & 0xB) == 0 (Not pressing A, B, or Start):
	beq _0600E3D8     @ goto _0600E3D8
	strb r0, [sp, #SP_A44] @ SP_A44 = SP_910
	ldrb r1, [sp, #SP_A43]
	tst r1, #1    @ if (SP_A43 & 1) != 0 (No option):
	bne _0600E60C     @ goto _0600E60C
	b sub_0600E6DC
_0600E60C:
	mov r0, #0x9f
	bl sub_06006E08 @ sub_06006E08(0x80|0x1F) (Clear text, then Game Over Continue text)
	bl sub_0600EB18 @ sub_0600EB18() (Enable emulator text display)
	mov r1, #0
	strb r1, [sp, #SP_A43] @ SP_A43 = 0 (Yes option)
	bl _0600E3D4
	ldr r0, [sp, #SP_910]
	ldrb r1, [sp, #SP_A43] @ r1 = SP_A43
	tst r0, #0x30    @ if (SP_910 & 0x30) != 0 (Pressing Left or Right):
	eorne r1, r1, #1     @ r1 ^= 1 (Toggle option)
	tst r0, #2       @ if (SP_910 & 2) != 0 (Pressing B):
	movne r1, #1         @ r1 = 1 (No option)
	strb r1, [sp, #SP_A43] @ SP_A43 = r1
	tst r1, #1      @ if (r1 & 1) == 0:
	moveq r0, #0x1d     @ sub_06006E08(0x1D) (Game Over Select Yes text)
	movne r0, #0x1e @ else:
	bl sub_06006E08     @ sub_06006E08(0x1E) (Game Over Select No text)
	ldr r0, [sp, #SP_910]
	tst r0, #0xb  @ if (SP_910 & 0xB) == 0 (Not pressing A, B, or Start):
	beq _0600E3D8     @ _0600E3D8
	strb r0, [sp, #SP_A44] @ SP_A44 = SP_910
	ldrb r1, [sp, #SP_A43]
	tst r1, #1    @ if (SP_A43 & 1) == 0 (Yes option):
	beq _0600ECE8     @ goto _0600ECE8
	b _0600ECFC

	@ Handle Reset Menu
	arm_func_start sub_0600E670
sub_0600E670: @ 0x0600E670
	mov r0, #0xa0
	bl sub_06006E08 @ sub_06006E08(0x80|0x20) (Clear text, then Reset Menu text)
	mov r1, #1
	strb r1, [sp, #SP_A43] @ SP_A43 = 1 (No option)
	bl _0600E3D4
	ldr r0, [sp, #SP_910]
	ldrb r1, [sp, #SP_A43] @ r1 = SP_A43
	tst r0, #0x30    @ if (SP_910 & 0x30) != 0 (Pressing Left or Right):
	eorne r1, r1, #1     @ r1 ^= 1 (Toggle option)
	tst r0, #2       @ if (SP_910 & 2) != 0 (Pressing B):
	movne r1, #1         @ r1 = 1 (No option)
	strb r1, [sp, #SP_A43] @ SP_A43 = r1
	tst r1, #1      @ if (r1 & 1) == 0:
	moveq r0, #0x1a     @ sub_06006E08(0x1A) (Menu Select Yes text)
	movne r0, #0x1b @ else:
	bl sub_06006E08     @ sub_06006E08(0x1B) (Menu Select No text)
	ldr r0, [sp, #SP_910]
	tst r0, #0xb  @ if (SP_910 & 0xB) == 0 (Not pressing A, B, or Start):
	beq _0600E3D8     @ goto _0600E3D8
	strb r0, [sp, #SP_A44] @ SP_A44 = SP_910
	mov r0, #0x80
	bl sub_06006E08 @ sub_06006E08(0x80) (Clear text)
	ldrb r1, [sp, #SP_A43]
	tst r1, #1    @ if (SP_A43 & 1) == 0:
	beq _0600EB40     @ goto _0600EB40
	ldr lr, _0600E7AC @ =sub_0600E440
	b _0600E3D4

	arm_func_start sub_0600E6DC
sub_0600E6DC: @ 0x0600E6DC
	bl _0600E3D4
	mov r12, #0x4000000
	ldr r1, [r12, #0x200]
	str r1, [sp, #SP_944]
	mov r0, #0x10
	bl sub_06006E08 @ sub_06006E08(0x10) (No text)
	add lr, pc, #0x4 @ =sub_0600E700
	ldr r12, _0600E7B0 @ =sub_0203E390
	bx r12

	arm_func_start sub_0600E700
sub_0600E700: @ 0x0600E700
	cmp r0, #0        @ if r0 != 0:
	movne r0, #0x18       @ sub_06006E08(0x18) (Sleep Mode text)
	blne sub_06006E08
	mov r12, #0x5000000
	mov r0, #0
	strh r0, [r12]
	bl sub_0600ED14
	mov r12, #0x4000000
	mov r0, #0
	str r0, [r12, #0x200]
	ldrb r0, [sp, #SP_A30]
	cmp r0, #0
	movne r0, #0
	movne r1, #0x14
	bne _0600E868
	bl sub_0600E754
	add r1, r0, #0x10
	mov r0, sp
	add lr, pc, #0x68 @ =sub_0600E7B8
	ldr r12, _0600E7B4 @ =EmulatorLoadFromPasswordBytes
	bx r12

	arm_func_start sub_0600E754
sub_0600E754: @ 0x0600E754
	ldr r4, _0600E788 @ =0x040000D4
	ldr r0, [sp, #SP_854]
	ldr r1, _0600E784 @ =0x0600A800
	ldr r5, _0600E78C @ =0x84000200
	stm r4, {r0, r1, r5} @ DMA(src=sp+#SP_854, dst=0x0600A800, cnt=Enable, 32bit, 0x800 bytes)
	mov r1, r0
	ldr r0, _0600E790 @ =0x0600A000
	nop
	nop
	stm r4, {r0, r1, r5} @ DMA(src=0x0600A000, dst=sp+#SP_854, cnt=Enable, 32bit, 0x800 bytes)
	mov r0, r1 @ return sp+#SP_854
	bx lr
	.align 2, 0
_0600E784: .4byte 0x0600A800
_0600E788: .4byte 0x040000D4
_0600E78C: .4byte 0x84000200
_0600E790: .4byte 0x0600A000

	arm_func_start sub_0600E794
sub_0600E794: @ 0x0600E794
	ldr r1, _0600E784 @ =0x0600A800
	ldr r2, [sp, #SP_854]
	ldr r4, _0600E788 @ =0x040000D4
	ldr r5, _0600E78C @ =0x84000200
	stm r4, {r1, r2, r5} @ DMA(src=0x0600A800, dst=sp+#SP_854, cnt=Enable, 32bit, 0x800 bytes)
	bx lr
	.align 2, 0
_0600E7AC: .4byte sub_0600E440
_0600E7B0: .4byte sub_0203E390
_0600E7B4: .4byte EmulatorLoadFromPasswordBytes

	arm_func_start sub_0600E7B8
sub_0600E7B8: @ 0x0600E7B8
	add r0, r0, #0x10
	ldr r3, [sp, #SP_924]
	add r3, r3, #0xc0
	add r1, r3, #0xc
	ldr r6, [sp, #SP_854]
_0600E7CC:
	ldr r2, [r3], #4
	str r2, [r6], #4
	cmp r3, r1
	blo _0600E7CC
	ldrb r6, [sp, #SP_A2E]
	ldrb r7, [sp, #SP_A2F]
	cmp r6, #2
	movhs r6, #0
	bhs _0600E810
	cmp r7, #2
	eorhs r7, r6, #1
	movhs r6, #1
	bhs _0600E810
	cmp r6, r7
	eor r7, r6, #1
	moveq r6, #1
	movne r6, #0
_0600E810:
	mov r3, #1
	add r3, r3, r7, lsl #8
	ldr r1, [sp, #SP_854]
	str r3, [r1, #0xc]
	strb r7, [sp, #SP_A31]
	bl sub_0600E534
	ldrb r7, [sp, #SP_A31]
	mov r0, sp
	ldr r1, [sp, #SP_854]
	strh r8, [r1, #0xe]
	mov r2, #0xa000
	orr r2, r2, #0x6000000
	stm r4, {r1, r2, r5}
	movs r2, r6
	ldrne r2, _0600E858 @ =0x0E007FD8
	add lr, pc, #0xC @ =sub_0600E860
	ldr r12, _0600E85C @ =EmulatorSaveToSram
	bx r12
	.align 2, 0
_0600E858: .4byte 0x0E007FD8
_0600E85C: .4byte EmulatorSaveToSram

	arm_func_start sub_0600E860
sub_0600E860: @ 0x0600E860
	bl sub_0600E794
	mov r1, #3
_0600E868:
	mov r0, #0
	str r0, [sp, #SP_9AC]
	strb r1, [sp, #SP_A47]
	cmp r0, #0
	addeq r6, sp, r6 @ WARNING: disassembler produces wrong instruction here
	strbeq r7, [r6, #SP_A2E]
	mov r12, #0x4000000
	add r2, r12, #0x208
	mov r0, #0
	strh r0, [r2]
	ldr r1, [sp, #SP_944]
	str r1, [r2, #-8]
	str r0, [sp, #SP_8F4]
	str r0, [sp, #SP_8F0]
	strb r0, [sp, #SP_A49]
	mov r1, #1
	strh r1, [r2]
	bl _0600E3D4
	ldrb r1, [sp, #SP_A47]
	subs r1, r1, #1
	strbne r1, [sp, #SP_A47]
	bne _0600E3D8
	ldr r0, [sp, #SP_9AC]
	cmp r0, #0        @ if r0 == 0:
	moveq r0, #0x8e       @ sub_06006E08(0x80|0xE) (Clear text, then Sleep Mode text)
	movne r0, #0x8f   @ else:
	blne sub_06006E08     @ sub_06006E08(0x80|0xF) (Clear text, then Sleep Mode text)
	bl sub_0600EB18 @ sub_0600EB18() (Enable emulator text display)
	ldrb r0, [sp, #SP_A41]
	cmp r0, #0
	orreq r2, r2, #0x800
	ldrb r0, [sp, #SP_A42]
	cmp r0, #0
	orreq r2, r2, #0x1000
	strh r2, [r1]
	bl _0600E3D4
	ldr r0, [sp, #SP_9AC]
	cmp r0, #0
	beq _0600E914
	ldr r0, [sp, #SP_910]
	tst r0, #0xf
	beq _0600E3D8
	strb r0, [sp, #SP_A44]
_0600E914:
	ldr lr, _0600E938 @ =sub_0600E440
	str lr, [sp, #SP_940]
	mov r0, #1
	strb r0, [sp, #SP_A33]
	mov r0, #0
	bl sub_0600EB1C @ sub_0600EB1C(0) (Disable emulator text display)
	mov r0, #0x80
	bl sub_06006E08 @ sub_06006E08(0x80) (Clear text)
	b _0600E3D8
	.align 2, 0
_0600E938: .4byte sub_0600E440

	@ Handle Sleep mode
	arm_func_start sub_0600E93C
sub_0600E93C: @ 0x0600E93C
	bl _0600E3D4
	mov r12, #0x4000000
	mov r0, #0x60
	strh r0, [r12] @ REG_DISPCNT = 0x60 (Screen off, OBJ VRAM 1D, OAM H-Blank)
	mov r0, #1
	strb r0, [sp, #SP_A48] @ SP_A48 = 1
	add lr, pc, #0x4 @ =sub_0600E960
	str lr, [sp, #SP_940] @ SP_940 = &sub_0600E960
	b sub_0600E2C4

	arm_func_start sub_0600E960
sub_0600E960: @ 0x0600E960
	ldrb r0, [sp, #SP_A48]
	cmp r0, #0
	bne sub_0600E2C4
	mov r12, #0x4000000
	mov r0, #0x80
	strh r0, [r12]
	mov r0, #0
	add r2, r12, #0x208
	strh r0, [r2]
	ldr r1, [r2, #-8]
	str r1, [sp, #SP_944]
	mov r1, #0x8300
	orr r1, r1, #4
	strh r1, [r2, #-0xd6]
	mov r1, #0x160
	str r1, [sp, #SP_928]
	mov r1, #0x3000
	strh r1, [r2, #-8]
	strh r1, [r2, #-6]
	mov r1, #1
	strh r1, [r2]
	mov r0, #0x42
	bl sub_06006E08 @ sub_06006E08(0x40|2) (Error text)
	mov r0, #0
	svc #0x190000
	svc #0x30000
	mov r0, #1
	svc #0x190000
	mov r12, #0x4000000
	add r2, r12, #0x208
	mov r0, #0
	strh r0, [r2]
	ldr r1, [sp, #SP_944]
	str r1, [r2, #-8]
	str r0, [sp, #SP_8F4]
	str r0, [sp, #SP_8F0]
	mov r1, #1
	strh r1, [r2]
	str r0, [sp, #SP_928]
	mov r1, #0
	orr r1, r1, #0x60
	ldrb r0, [sp, #SP_A41]
	cmp r0, #0
	orreq r1, r1, #0x800
	ldrb r0, [sp, #SP_A42]
	cmp r0, #0
	orreq r1, r1, #0x1000
	strh r1, [r12]
	mov r0, #0x3c
	strb r0, [sp, #SP_A47]
	strb r0, [sp, #SP_A44]
	str r0, [sp, #SP_914]
	bl _0600E3D4
	ldrb r0, [sp, #SP_A47]
	cmp r0, #0
	subne r0, r0, #1
	strbne r0, [sp, #SP_A47]
	ldrne pc, [sp, #SP_9BC]
	mov r0, #0x80
	bl sub_06006E08 @ sub_06006E08(0x80) (Clear text)
	bl sub_0600EB04
	b _0600E240
_0600EA58:
	tst r0, #0x40
	subne r1, r1, #1
	cmp r1, #0
	movmi r1, #3
	add r2, sp, r1
	ldrb r2, [r2, #0xa4a]
	tst r2, #0x80
	bne _0600EA58
_0600EA78:
	tst r0, #0x84
	addne r1, r1, #1
	cmp r1, #4
	movhs r1, #0
	add r2, sp, r1
	ldrb r2, [r2, #0xa4a]
	tst r2, #0x80
	bne _0600EA78
	strb r1, [sp, #SP_A43]
_0600EA9C:
	ldr r2, [sp, #SP_934]
	add r2, r2, #0x244
	mov r3, #3
_0600EAA8:
	cmp r1, r3
	moveq r0, #0
	movne r0, #0x8000
	add r12, r2, #0x1e
_0600EAB8:
	ldrh r4, [r12, #-2]!
	bic r4, r4, #0xc000
	add r4, r4, r0
	strh r4, [r12], #-0x40
	ldrh r4, [r12]
	bic r4, r4, #0xc000
	add r4, r4, r0
	strh r4, [r12], #0x40
	cmp r2, r12
	bne _0600EAB8
	cmp r1, r3
	ldreq r4, _0600EB00 @ =0x11840183
	ldrne r4, [pc, #0x12] @ WARNING: disassembler fails to produce this instruction
.ifdef REGION_JP
	strh r4, [r12, #6]
.else
	strh r4, [r12, #4]
.endif
	sub r2, r2, #0x80
	subs r3, r3, #1
	bhs _0600EAA8
	b _0600E3D8
	.align 2, 0
_0600EB00: .4byte 0x11840183

	arm_func_start sub_0600EB04
sub_0600EB04: @ 0x0600EB04
	mov r0, #0
	b _0600EB10

	arm_func_start sub_0600EB0C
sub_0600EB0C: @ 0x0600EB0C
	mov r0, #1
_0600EB10:
	ldr r12, _0600EBE4 @ =sub_03001D24
	bx r12

	@ Enable emulator text display
	arm_func_start sub_0600EB18
sub_0600EB18: @ 0x0600EB18
	mov r0, #0x100

	@ Set emulator text display
	@ Input: r0 = 0 is off, r0 = 0x100 is on
	arm_func_start sub_0600EB1C
sub_0600EB1C: @ 0x0600EB1C
	mov r1, #0x4000000
	ldrh r2, [r1]
	bic r2, r2, #0x100
	orr r2, r2, r0
	strh r2, [r1] @ REG_DISPCNT = (REG_DISPCNT & ~0x100) | r0 (Set BG0 to r0)
	bx lr

	arm_func_start sub_0600EB34
sub_0600EB34: @ 0x0600EB34
	mov r0, #0x80
	bl sub_06006E08 @ sub_06006E08(0x80) (Clear text)
	b _0600ECFC
_0600EB40:
	bl sub_0600EC4C
	add r1, sp, #0x800
	add r1, r1, #0xc4
	mov r0, #0x1e
	add r2, r1, #0x20
_0600EB54:
	strb r0, [r1], #1
	teq r1, r2
	bne _0600EB54
	mov r1, #0x200
	orr r1, r1, #0x5000000
	mov r0, #0
_0600EB6C:
	str r0, [r1], #4
	tst r1, #0x1fc
	bne _0600EB6C
	mov r1, #0x5000000
_0600EB7C:
	str r0, [r1], #4
	str r0, [r1], #0x1c
	tst r1, #0x80
	beq _0600EB7C
	ldr r0, [sp, #SP_8AC]
	orr r0, r0, #0x820000
	str r0, [sp, #SP_8AC]
	ldr r0, [sp, #SP_8BC]
	bic r0, r0, #0x80
	bic r0, r0, #0x1800
	str r0, [sp, #SP_8BC]
	mvn r0, #0xf3
	eor r0, r0, #0x360
	add r1, sp, #0x200
	stmdb r1!, {r0}
	str r1, [sp, #SP_88C]
	ldr lr, _0600EBE8 @ =sub_0600E440
	str lr, [sp, #SP_940]
	ldr lr, _0600EBEC @ =_0600E3D8
	mov r1, #0
	strb r1, [sp, #SP_A33]
	strb r1, [sp, #SP_A32]
	mov r1, #0xa
	strb r1, [sp, #SP_A2D]
	ldr r2, _0600EBF0 @ =EmulatorAudio_Disable
	bx r2
	.align 2, 0
_0600EBE4: .4byte sub_03001D24
_0600EBE8: .4byte sub_0600E440
_0600EBEC: .4byte _0600E3D8
_0600EBF0: .4byte EmulatorAudio_Disable
_0600EBF4: .4byte 0x0600A000

	arm_func_start sub_0600EBF8
sub_0600EBF8: @ 0x0600EBF8
	ldr r0, _0600EBF4 @ =0x0600A000
	ldr r1, [r0]
	ldr r0, [sp, #SP_924]
	ldr r2, [r0, #0xc0]
	cmp r1, r2 @ if [0x0600A000] != [SP_924 + 0xC0]:
	bxne lr        @ return

	@ Set 0x800 bytes at SP to 0xDA
	ldr r0, _0600EC48 @ =0xDADADADA
	mov r1, r0
	mov r2, r0
	mov r3, r0
	mov r4, sp
	add r5, sp, #0x800
	ldr r12, [sp, #0x1fc] @ backup SP_1FC
_0600EC2C:
	stmdb r5!, {r0, r1, r2, r3}
	cmp r5, r4
	bne _0600EC2C

	str r12, [sp, #0x1fc] @ restore SP_1FC
	mov r0, #1
	strb r0, [sp, #SP_A30] @ SP_A30 = 1
	bx lr
	.align 2, 0
_0600EC48: .4byte 0xDADADADA

	arm_func_start sub_0600EC4C
sub_0600EC4C: @ 0x0600EC4C
	mov r11, lr
	ldrb r0, [sp, #SP_A30]
	cmp r0, #0
	bne _0600EC80
	mov r0, sp
	ldr r1, _0600EC88 @ =0x0600A010
	add lr, pc, #0x4 @ =_0600EC70
	ldr r12, _0600EC8C @ =EmulatorLoadFromPasswordBytes
	bx r12
_0600EC70:
	ldr r3, [sp, #SP_924]
	ldr r2, [r3, #0xc0]
	ldr r3, _0600EBF4 @ =0x0600A000
	str r2, [r3]
_0600EC80:
	mov lr, r11
	b sub_0600EBF8
	.align 2, 0
_0600EC88: .4byte 0x0600A010
_0600EC8C: .4byte EmulatorLoadFromPasswordBytes

	@ Handle Quit Menu
	arm_func_start sub_0600EC90
sub_0600EC90: @ 0x0600EC90
	mov r0, #0x99
	bl sub_06006E08 @ sub_06006E08(0x80|0x19) (Clear text, then Quit Menu text)
	mov r1, #1
	strb r1, [sp, #SP_A43] @ SP_A43 = 1 (No option)
	bl _0600E3D4
	ldr r0, [sp, #SP_910]
	ldrb r1, [sp, #SP_A43] @ r1 = SP_A43
	tst r0, #0x30    @ if (SP_910 & 0x30) != 0 (Pressing Left or Right):
	eorne r1, r1, #1     @ r1 ^= 1 (Toggle option)
	tst r0, #2       @ if (SP_910 & 2) != 0 (Pressing B):
	movne r1, #1         @ r1 = 1 (No option)
	strb r1, [sp, #SP_A43] @ SP_A43 = r1
	tst r1, #1      @ if (r1 & 1) == 0:
	moveq r0, #0x1a     @ sub_06006E08(0x1A) (Menu Select Yes text)
	movne r0, #0x1b @ else:
	bl sub_06006E08     @ sub_06006E08(0x1B) (Menu Select No text)
	ldr r0, [sp, #SP_910]
	tst r0, #0xb  @ if (SP_910 & 0xB) == 0 (Not pressing A, B, or Start):
	beq _0600E3D8     @ goto _0600E3D8
	ldrb r1, [sp, #SP_A43]
	tst r1, #1    @ if (SP_A43 & 1) == 0 (select Yes):
	beq _0600ECFC     @ goto _0600ECFC
_0600ECE8:
	strb r0, [sp, #SP_A44] @ SP_A44 = SP_910
	mov r0, #0x80
	bl sub_06006E08 @ sub_06006E08(0x80) (Clear text)
	ldr lr, _0600ED0C @ =sub_0600E440
	b _0600E3D4
_0600ECFC:
	add lr, pc, #0x0 @ =_0600ED04
	ldr pc, _0600ED10 @ =sub_0600ED14
_0600ED04:
	ldr sp, [sp, #SP_920] @ SP = SP_920 (original sp (0x03007EF8))
	ldm sp!, {pc} @ Exit emulator (returns to 0x087D8124 of loader.s)
	.align 2, 0
_0600ED0C: .4byte sub_0600E440
_0600ED10: .4byte sub_0600ED14

	arm_func_start sub_0600ED14
sub_0600ED14: @ 0x0600ED14
	mov r11, lr
	bl sub_0600EB0C
	movs r0, r11 @ r0 = r11
	movne r0, #0x100 @ if r0 != 0 (always true?): r0 = 0x100
	bl sub_0600EB1C @ sub_0600EB1C(0x1000) (Enable emulator text display)
	bic r2, r2, #0x1800
	strh r2, [r1] @ REG_DISPCNT &= ~0x1800 (Turn off BG3 and OBJ)
	add r2, r1, #0x208
	mov r0, #0
	strh r0, [r2] @ REG_IME = 0 (Disable interrupts)
	ldrh r0, [r2, #-8]
	bic r0, r0, #0x78
	strh r0, [r2, #-8] @ REG_IE &= ~0x78 (Disable Timer 0-3 interrupts)
	ldr r0, _0600ED84 @ =0x84400004
	str r0, [r1, #0xc4]! @ REG_DMA1CNT = 0x84400004 (Enable, 32bit, Fixed, 16 bytes)
	mov r0, #2
	strb r0, [sp, #SP_A48] @ SP_A48 = 2
	mov r0, #1
	strb r0, [sp, #SP_A49] @ SP_A49 = 1
	mov r0, #1
	strh r0, [r2] @ REG_IME = 1 (Enable interrupts)
	mov r0, #0x440
	strh r0, [r1, #2] @ REG_DMA1CNT_H = 0x440 (Disable, 32bit, Fixed)

	@ Wait until SP_A49 and SP_A48 are the same (Happens during V-Blank interrupt)
_0600ED70:
	ldrb r0, [sp, #SP_A49]
	ldrb r1, [sp, #SP_A48]
	cmp r0, r1
	bne _0600ED70

	bx r11
	.align 2, 0
_0600ED84: .4byte 0x84400004
