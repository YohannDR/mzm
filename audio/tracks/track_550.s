.align 2

.section .rodata
.global track_550

track_550_0:
	.byte 188, 0, 187, 75, 189, 9, 190, 31
	.byte 191, 64, 209, 60, 80, 130, 177

.align 2

track_550:
	.byte 1
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_550_0

.align 2
