.align 2

.section .rodata
.global track_180

track_180_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 31
	.byte 191, 30, 223, 60, 100, 144, 177

.align 2

track_180:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group11
	.word track_180_0

.align 2
