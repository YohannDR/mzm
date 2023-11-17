.align 2

.section .rodata
.global track_625

track_625_0:
	.byte 188, 0, 187, 75, 189, 51, 190, 120
	.byte 191, 64, 220, 57, 80, 141, 57, 32
	.byte 141, 57, 12, 141, 177

.align 2

track_625:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_625_0

.align 2
