    .include "asm/constants.inc"
    .include "asm/macros.inc"
	.include "asm/emulator_constants.inc"

    .syntax unified

	arm_func_start sub_0600B000
sub_0600B000: @ 0x0600B000
	and r0, r0, #0xff
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	ldr pc, _0600B13C @ =_03005398

	@ Writes to PPUCTRL
	arm_func_start sub_0600B018
sub_0600B018: @ 0x0600B018
	bic r0, r11, #0x100000 @ r0 = r11 & ~0x00100000 (no effect?)
	tst r1, #0x10           @ if r1 & 0x10:
	orrne r0, r0, #0x100000     @ r0 |= 0x00100000
	cmp r0, r11              @ if r0 != r11:
	orrne r11, r0, #0x80000      @ r11 = r0 | 0x00080000
	strb r1, [sp, #SP_8BC] @ SP_8BC = r1
	ldrb r2, [sp, #SP_9C1]
	and r0, r1, #1
	and r2, r2, #2
	orr r0, r0, r2
	strb r0, [sp, #SP_9C1] @ SP_9C1 = (r1 & 1) | (SP_9C1 & 2)
	and r0, r1, #3
	strb r0, [sp, #SP_9C5] @ SP_9C5 = r1 & 3
	ldrb r1, [sp, #SP_A38]
	cmp r1, #0       @ if SP_A38 == 0:
	beq sub_0600B068     @ goto sub_0600B068
	ldr r2, [sp, #SP_8B4]
	cmp r2, r1       @ if SP_8B4 > SP_A38:
	bhs sub_0600B068     @ goto sub_0600B068
	strb r0, [sp, #SP_9C1] @ SP_9C1 = SP_9C5

	@ Writes to OAMDATA
	arm_func_start sub_0600B068
sub_0600B068: @ 0x0600B068
	cmp r4, #0                 @ if r4 < 0:
	ldrblt r1, [r5], #1            @ r1 = *r5++
	ldrlt pc, [r12, r1, lsl #2]     @ goto r12[r1]
	@ goto _03005398
	ldr pc, _0600B140 @ =_03005398

	@ Writes to PPUMASK and/or OAMADDR
	arm_func_start sub_0600B078
sub_0600B078: @ 0x0600B078
	add r2, sp, r0 @ WARNING: disassembler produces wrong instruction here
	strb r1, [r2, #SP_8BC] @ SP_*BC + r0 = r1
	cmp r4, #0                 @ if r4 < 0:
	ldrblt r1, [r5], #1            @ r1 = *r5++
	ldrlt pc, [r12, r1, lsl #2]     @ goto r12[r1]
	@ goto _0600B144
	ldr pc, _0600B144 @ =_03005398

	@ Writes to PPUSCROLL
	arm_func_start sub_0600B090
sub_0600B090: @ 0x0600B090
	tst r11, #0x200000
	eor r11, r11, #0x200000
	bne _0600B0B0
	strb r1, [sp, #SP_A39]
_0600B0A0:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	ldr pc, _0600B148 @ =_03005398
_0600B0B0:
	strb r1, [sp, #SP_9C4]
	ldrb r0, [sp, #SP_A38]
	cmp r0, #0
	beq _0600B0A0
	ldr r2, [sp, #SP_8B4]
	cmp r2, r0
	bhs _0600B0A0
	add r1, r1, r2
	strb r1, [sp, #SP_9C0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	ldr pc, _0600B14C @ =_03005398

	@ TODO: doesn't seem to be a way to cause sub_06006E08 to read this
	.global sEmulatorSleepModeText
sEmulatorSleepModeText: @ 0x0600B0E4
.ifdef REGION_JP
	@ スリープをかいじょするときは
	.4byte 0x06003B50
	.byte 0x20, 0x20, 0x20, 0x38, 0x20, 0x20, 0x20, 0x7B
	.byte 0x00, 0x00, 0x00, 0x00
	.4byte 0x06003B90
	.byte 0x39, 0x5E, 0x5C, 0x78, 0x73, 0x37, 0x77, 0x75, 0x59, 0x55, 0x7C, 0x54, 0x76, 0x34
	.byte 0x00, 0x00

	@ L+R+SELECT
	.4byte 0x06003C14
	.byte 0x01, 0x52, 0x53, 0x32, 0x53, 0x71, 0x72, 0x52, 0x72, 0x33, 0x51
	.byte 0x00

	@ をおしてください
	.4byte 0x06003C56
	.byte 0x02, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7B
	.byte 0x00
	.4byte 0x06003C96
	.byte 0x73, 0x57, 0x75, 0x74, 0x56, 0x35, 0x36, 0x77
	.byte 0x00, 0x00, 0x00, 0x00
.else
	@ TO DISABLE SLEEP
	.4byte 0x06003B90
	.byte 0x02, 0x6D, 0x6C, 0x20, 0x67, 0x6B, 0x4D, 0x27, 0x47, 0x48, 0x4B, 0x20, 0x4D, 0x48, 0x4B, 0x4B
	.byte 0x68
	.byte 0x00, 0x00, 0x00

	@ MODE, PRESS
	.4byte 0x06003BD0
	.byte 0x2C, 0x6C, 0x67, 0x4B, 0x69, 0x20, 0x68, 0x2D, 0x4B, 0x4D, 0x4D
	.byte 0x00

	@ L+R+SELECT
	.4byte 0x06003C16
	.byte 0x01, 0x48, 0x49, 0x2D, 0x49, 0x4D, 0x4B, 0x48, 0x4B, 0x2B, 0x6D
	.byte 0x00

	@ SIMULTANEOUSLY
	.4byte 0x06003C50
	.byte 0x02, 0x4D, 0x6B, 0x2C, 0x2E, 0x48, 0x6D, 0x27, 0x4C, 0x4B, 0x6C, 0x2E, 0x4D, 0x48, 0x29, 0x2A
	.byte 0x00, 0x00, 0x00, 0x00
.endif

	.4byte 0xFFFFFFFF

	@ TODO: what action could cause sub_06006E08 to read this?
	.global sEmulatorEmptyText
sEmulatorEmptyText: .4byte 0xFFFFFFFF

_0600B13C: .4byte _03005398
_0600B140: .4byte _03005398
_0600B144: .4byte _03005398
_0600B148: .4byte _03005398
_0600B14C: .4byte _03005398
