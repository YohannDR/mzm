.align 2

.section .rodata
.global track_555

track_555_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 62
	.byte 191, 64, 210, 60, 100, 132, 232, 60
	.byte 80, 153, 177

track_555_1:
	.byte 188, 0, 189, 2, 190, 62, 191, 64
	.byte 210, 52, 80, 132, 232, 153, 177

.align 2

track_555:
	.byte 2
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_555_0
	.word track_555_1

.align 2
