.align 2

.section .rodata
.global track_505

track_505_0:
	.byte 188, 0, 187, 75, 189, 5, 190, 32
	.byte 191, 64, 210, 60, 80, 134, 60, 32
	.byte 134, 60, 12, 131, 177

.align 2

track_505:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_505_0

.align 2
