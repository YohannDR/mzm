.align 2

.section .rodata
.global track_672

track_672_0:
	.byte 188, 0, 187, 75, 189, 13, 190, 94
	.byte 191, 64, 230, 60, 100, 151, 177

track_672_1:
	.byte 188, 0, 189, 14, 190, 75, 191, 64
	.byte 216, 72, 80, 137, 72, 32, 137, 72
	.byte 12, 137, 177

.align 2

track_672:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_672_0
	.word track_672_1

.align 2
