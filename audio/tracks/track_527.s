.align 2

.section .rodata
.global track_527

track_527_0:
	.byte 188, 0, 187, 75, 152, 130, 189, 14
	.byte 190, 56, 191, 64, 214, 66, 80, 139
	.byte 214, 139, 214, 135, 177

track_527_1:
	.byte 188, 0, 189, 2, 190, 70, 191, 64
	.byte 193, 2, 192, 64, 211, 55, 80, 132
	.byte 192, 69, 211, 59, 133, 211, 133, 59
	.byte 60, 133, 59, 40, 133, 59, 12, 132
	.byte 177

.align 2

track_527:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_527_0
	.word track_527_1

.align 2
