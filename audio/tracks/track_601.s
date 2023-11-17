.align 2

.section .rodata
.global track_601

track_601_0:
	.byte 188, 0, 187, 75, 189, 1, 190, 50
	.byte 191, 64, 193, 20, 192, 48, 229, 41
	.byte 80, 133, 192, 64, 143, 190, 18, 129
	.byte 6, 129, 0, 177

.align 2

track_601:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_601_0

.align 2
