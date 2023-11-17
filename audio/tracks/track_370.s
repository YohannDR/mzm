.align 2

.section .rodata
.global track_370

track_370_0:
	.byte 188, 0, 187, 75, 189, 29, 190, 120
	.byte 191, 64, 193, 12, 192, 56, 235, 60
	.byte 80, 130, 192, 57, 130, 59, 130, 60
	.byte 130, 61, 130, 63, 130, 64, 130, 65
	.byte 130, 67, 130, 68, 130, 69, 130, 71
	.byte 130, 72, 140, 177

.align 2

track_370:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group3
	.word track_370_0

.align 2
