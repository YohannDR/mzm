	.include "asm/constants.inc"
	.include "asm/macros.inc"

	@ regs:
	@ r0 = 0x087D8150 (Data to read from)
	@ r4 = 0x040000D4 (DMA3)
	@ r5 = 0x13850021 (???)
	.syntax unified

	arm_func_start start_code
start_code: @ 0x03007400
	ldr r9, _03007450 @ =0x01300014
	lsr r10, r9, #0x10 @ r10 = 0x130
	strh r9, [r4, r10] @ 0x040000D4 + 0x130 = 0x04000204 (WaitCnt) = 0x14

	and r6, r5, #0xff @ r6 = (0x13850021 & 0xFF) = 0x21
	add r6, r0, r6, lsl #4 @ r6 = 0x087D8150 + (0x21 << 4) = 0x087D8360 (source)
	add r5, pc, #0x1E8 @ =_03007604

ResetDstAddr: @ 0x03007418
	ldr r7, _03007610 @ =0x03000100 (destination)
	add r8, r7, #0x2000 @ r8 = 0x03000100 + 0x2000 = 0x03002100 (max destination)

ReadNextByte: @ 0x03007420
	ldrb r3, [r6], #1
	lsl r3, r3, #0x18
	orr r3, r3, #1 @ r3 = ([r6++] << 18) | 1

CheckNextBit: @ 0x0300742C
	lsls r3, r3, #1   @ r3 <<= 1
	blo Compressed    @ if highest bit was 0, goto Compressed
	ldrb r9, [r6], #1
	strb r9, [r7], #1 @ [r7++] = [r6++]
	cmp r7, r8
	bhs _03007484     @ if r7 >= r8 (wrote 0x2000 bytes?), goto @@_3007484
	tst r3, #0x100    @ if r3 has 0x100 (looped 8 times)
	beq CheckNextBit      @ goto ReadNextByte
	bne ReadNextByte  @ else, goto CheckNextBit
	.align 2, 0
_03007450: .4byte 0x01300014
_03007454:
.ifdef REGION_JP
	.4byte 0x06006778
.else
	.4byte 0x06006558
.endif

@ This routine is called when the emulator decompression is finished
	arm_func_start _03007458
_03007458: @ 0x03007458
	ldmdb r5!, {r1, r2, r3} @ load DMA values

@ r1 = [--r5] (DMA source)
@ r2 = [--r5] (DMA dest)
@ r3 = [--r5] (DMA count (sometimes))

@ Loads
@ 1: 0x06007000, 0x06008524, _03007458
@ 2: _03007560, 0x07000000, 0x85000100
@ 3: _030075AC, 0x05000000, 0x85000100
@ 4: 0x06007C44, 0x0203E000, 0x84000238
@ 5: _030075AC, 0x06010000, 0x85002000
@ 6: 0x06006EBC, 0x0600E000, 0x84000362
@ 7: 0x06006E5C, 0x0600C000, 0x84000018
@ 8: 0x06006D0C, 0x0600B000, 0x84000054
@ 9: 0x06000000, 0x0600B800, 0x00000000

@ DMAs
@ 1: _03007560, 0x07000000, 100 (32 bit, fixed) (010000A0)
@ 2: _030075AC, 0x05000000, 100 (32 bit, fixed) (0)
@ 3: 0x06007C44, 0x0203E000, 238 (32 bit)
@ 4: _030075AC, 0x06010000, 2000 (32 bit, fixed) (0)
@ 5: 0x06006EBC, 0x0600E000, 362 (32 bit)
@ 6: 0x06006E5C, 0x0600C000, 18 (32 bit)
@ 7: 0x06006D0C, 0x0600B000, 54 (32 bit)

	cmp r3, #0              @ if r3 != 0
	tstne r3, #-0x80000000      @ if r3 does not have 0x80000000:
	stmne r4, {r1, r2, r3}          @ DMA(src=r1, dst=r2, cnt=r3)
	cmp r3, #0
	bne _03007458               @ goto @@_3007458 (read from pool and try DMA)
	add r5, pc, #0xEC @ =_03007564
	ldr r1, [r5], #4        @ r1 = 0x087D814C, r5 += 4 (_03007568)
	ldrh r6, [r1, #2]       @ r6 = [r1 + 2] = 0x1385
	add r6, r1, r6, lsl #2  @ r6 = r1 + r6*4 = 0x87DCF60
	b ResetDstAddr          @ goto ResetDstAddr

_03007484: @ 0x03007484
	ldm r5, {r10, r12}          @ r5 starts near end of data pool (_03007604)
@ r10 = [r5] (DMA dest)
@ r12 = [r5+4] (Max dest end?)

@ Emulator:
@ 1: 06000000, 06008524
@ 2: 06001000, 06008524
@ 3: 06002000, 06008524
@ 4: 06003000, 06008524
@ 5: 06004000, 06008524
@ 6: 06005000, 06008524
@ 7: 06006000, 06008524
@ 8: 06007000, 06008524

@ Rom:
@ 1: 0201C000, 0203C000
@ 2: 0201D000, 0203C000
@ 3: 0201E000, 0203C000
@ 4: 0201F000, 0203C000
@ TODO: rest of these
@ last: 0203A000, 0203C000

	ldr r9, _03007610 @ =0x03000100 @ (DMA source)
@ r7 - 3000100 is length of decompressed data,
@ so r11 is DMA dest + size
	sub r11, r7, r9
	add r11, r11, r10            @ r11 = r7 - 0x03000100 + r10
	cmp r11, r12
	movhs r11, r12               @ if r11 >= r12: r11 = r12
	addlo r11, r10, #0x1000      @ else: r11 = r10 + 0x1000
	sub r12, r11, r10            @ r12 = r11 - r10 (r12 = size)
	lsr r11, r12, #2             @ r11 = r12 >> 2 (r11 = size/4)
	orr r11, r11, #0x84000000    @ r11 |= 0x84000000 (Enable, 32 bit)
@ DMAs

@ Emulator:
@ 1: 0x03000100, 0x06000000, 0x84000400
@ 2: 0x03000100, 0x06001000, 0x84000400
@ 3: 0x03000100, 0x06002000, 0x84000400
@ 4: 0x03000100, 0x06003000, 0x84000400
@ 5: 0x03000100, 0x06004000, 0x84000400
@ 6: 0x03000100, 0x06005000, 0x84000400
@ 7: 0x03000100, 0x06006000, 0x84000400
@ 8: 0x03000100, 0x06007000, 0x84000549
@ After this 8th DMA, JumpR15 is then hit

@ Rom:
@ 1: 0x03000100, 0x0201C000, 0x84000400
@ 2: 0x03000100, 0x0201D000, 0x84000400
@ 3: 0x03000100, 0x0201E000, 0x84000400
@ 4: 0x03000100, 0x0201F000, 0x84000400
@ TODO: rest of these
@ last: 0x03000100, 0x0203A000, 0x84000800
@ After about the 30th DMA, JumpR15 is then hit

	stm r4, {r9, r10, r11}       @ DMA(src=r9, dst=r10, cnt=r11)
	bhs JumpR15                  @ if size was >= max: goto JumpR15
	add r10, r10, r12            @ r10 += r12 (r10 = dest end)
	str r10, [r5]                @ [r5] = r10 (write new DMA dest?)
	sub r11, r7, r9
	sub r11, r11, r12            @ r11 = (r7 - r9) - r12 (decomp size - 0x1000)
	add r11, r11, #3             @ r11 += 3
	lsr r11, r11, #2             @ r11 >>= 2
	orr r11, r11, #0x84000000    @ r11 |= 84000000 (Enable, 32 bit)
	mov r10, r9                  @ r10 = r9 (DMA dst)
	add r9, r9, r12              @ r9 = r9 + r12 (DMA src)
@ DMAs

@ Emulator:
@ 1: 03001100, 03000100, 84000402
@ 2: 03001100, 03000100, 84000400
@ 3: 03001100, 03000100, 84000401
@ 4: 03001100, 03000100, 84000401
@ 5: 03001100, 03000100, 84000402
@ 6: 03001100, 03000100, 84000400
@ 7: 03001100, 03000100, 84000400

@ Rom:
@ 1: 03001100, 03000100, 84000400
@ 2: 03001100, 03000100, 84000400
@ 3: 03001100, 03000100, 84000400
@ 4: 03001100, 03000100, 84000425

	stm r4, {r9, r10, r11}       @ DMA(src=r9, dst=r10, cnt=r11) (copy everything after 3001100 to 3000100)
	sub r7, r7, r12              @ r7 -= r12 (r7 = end of data written to 3000100)
	blo Continue                 @ goto Continue (always true)

@ This routine is called when the rom decompression is finished
_030074E4: @ 0x030074E4
	ldm r5!, {r1, r2, r3}    @ load from data pool
@ 1: _030075AC,  0x03005A4C, 0x166 (32 bit, fixed) (0)
@ 2: 0x060012C0, 0x03000000, 0x1693 (32 bit)
@ 3: 0x06000080, 0x06006000, 0x490 (32 bit)
@ 4: _030075AC,  0x06000080, 0xFE0 (32 bit, fixed) (0)
@ 5: 0x06000000, 0x0600B800, 0x0 (No DMA)
	cmp r3, #0               @ if r3 != 0:
	stmne r4, {r1, r2, r3}       @ DMA(src=r1, dst=r2, cnt=r3)
	bne _030074E4                @ goto _030074E4 (repeat DMA)
	add r6, r1, #0x80        @ r6 = r1 + 80 (6000080?)

_030074F8: @ 0x030074F8
@ copy 2 bytes from 6000000 to 600B800 until src == 6000080
	ldrh r3, [r1], #2        @ r3 = [r1], r1 += 2
	strh r3, [r2], #2        @ [r2] = r3, r2 += 2
	teq r1, r6               @ if r1 ^ r6 != 0
	bne _030074F8                @ goto _030074F8
	sub r5, pc, #0xc4        @ r5 = _0300744C

JumpR15: @ 0x0300750C
	ldm r5!, {r9, r10, pc}
@ r9 = [r5++]
@ r10 = [r5++]
@ r15 = [r5++]
@ 1: 0x06007000, 0x06008524, _03007458
@ 2: 0x0203A000, 0x0203C000, _030074E4
@ 3: 0x1AFFFFF3, 0x01300014, 06006558 (emulator entry point)

Compressed: @ 0x03007510
	ldrb r9, [r6, #1]
	sub r9, r7, r9            @ r9 = r7 - [r6 + 1]
	ldrb r11, [r6], #2        @ r11 = [r6], r6 += 2
	cmp r11, #0x10
	lsrhs r12, r11, #4        @ if r11 >= 0x10: r12 = r11 >> 4
	ldrblo r12, [r6], #1      @ else: r12 = 0x10 + [r6]++
	addlo r12, r12, #0x10
	adds r10, r7, r12         @ r10 = r7 + r12 (update Cy)
	adcs r10, r10, #2         @ r10 += 2 + Cy (update Cy)
	and r11, r11, #0xf        @ r11 &= 0xF
	sbc r9, r9, r11, lsl #8   @ r9 = r9 - (r11 << 8) + Cy - 1

CompressedCopyLoop: @ 0x0300753C
	ldrb r12, [r9], #1
	strb r12, [r7], #1        @ [r7]++ = [r9]++
	cmp r7, r10               @ if r7 < r10:
	blo CompressedCopyLoop        @ goto CompressedCopyLoop
	cmp r7, r8                @ if r7 >= r8:
	bhs _03007484                 @ goto _03007484 (?)

Continue: @ 0x03007554
	tst r3, #0x100    @ if r3 has 0x100 (looped 8 times)
	beq CheckNextBit      @ goto ReadNextByte
	bne ReadNextByte  @ else, goto CheckNextBit
	.align 2, 0

_03007560: .4byte 0x010000A0
_03007564: .4byte 0x087D814C

_03007568: .4byte 0x0201C000
_0300756C: .4byte 0x0203C000
_03007570: .4byte _030074E4

_03007574: .4byte _030075AC
_03007578: .4byte 0x03005A4C
_0300757C: .4byte 0x85000166

_03007580:
.ifdef REGION_JP
	.4byte 0x060012E0
.else
	.4byte 0x060012C0
.endif
_03007584: .4byte 0x03000000
_03007588: .4byte 0x84001693

_0300758C: .4byte 0x06000080
_03007590: .4byte 0x06006000
_03007594:
.ifdef REGION_JP
	.4byte 0x84000498
.else
	.4byte 0x84000490
.endif

_03007598: .4byte _030075AC
_0300759C: .4byte 0x06000080
_030075A0: .4byte 0x85000FE0

_030075A4: .4byte 0x06000000
_030075A8: .4byte 0x0600B800
_030075AC: .4byte 0x00000000

_030075B0:
.ifdef REGION_JP
	.4byte 0x06006D2C
.else
	.4byte 0x06006D0C
.endif
_030075B4: .4byte 0x0600B000
_030075B8: .4byte 0x84000054

_030075BC:
.ifdef REGION_JP
	.4byte 0x06006E7C
.else
	.4byte 0x06006E5C
.endif
_030075C0: .4byte 0x0600C000
_030075C4: .4byte 0x84000018

_030075C8:
.ifdef REGION_JP
	.4byte 0x06006EDC
.else
	.4byte 0x06006EBC
.endif
_030075CC: .4byte 0x0600E000
_030075D0: .4byte 0x84000362

_030075D4: .4byte _030075AC
_030075D8: .4byte 0x06010000
_030075DC: .4byte 0x85002000

_030075E0:
.ifdef REGION_JP
	.4byte 0x06007C64
.else
	.4byte 0x06007C44
.endif
_030075E4: .4byte 0x0203E000
_030075E8:
.ifdef REGION_JP
	.4byte 0x84000244
.else
	.4byte 0x84000238
.endif

_030075EC: .4byte _030075AC
_030075F0: .4byte 0x05000000
_030075F4: .4byte 0x85000100

_030075F8: .4byte _03007560
_030075FC: .4byte 0x07000000
_03007600: .4byte 0x85000100

_03007604: .4byte 0x06000000
_03007608:
.ifdef REGION_JP
	.4byte 0x06008574
.else
	.4byte 0x06008524
.endif
_0300760C: .4byte _03007458

_03007610: .4byte 0x03000100
