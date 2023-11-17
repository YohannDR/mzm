.align 2

.section .rodata
.global track_700

track_700_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 70
	.byte 191, 64, 237, 60, 100, 158, 177

.align 2

track_700:
	.byte 1
	.byte 0
	.byte 182
	.byte 0
	.word voice_group15
	.word track_700_0

.align 2
