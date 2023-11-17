.align 2

.section .rodata
.global track_406

track_406_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 56
	.byte 191, 64, 223, 60, 80, 144, 177

track_406_1:
	.byte 188, 0, 189, 2, 190, 70, 191, 64
	.byte 209, 71, 80, 131, 72, 60, 131, 71
	.byte 80, 131, 72, 60, 131, 71, 80, 131
	.byte 208, 72, 60, 129, 177

.align 2

track_406:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_406_0
	.word track_406_1

.align 2
