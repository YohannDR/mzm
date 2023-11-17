.align 2

.section .rodata
.global track_233

track_233_0:
	.byte 188, 0, 187, 75, 189, 1, 190, 56
	.byte 191, 64, 232, 60, 80, 1, 131, 196
	.byte 25, 194, 110, 197, 1, 149, 196, 0
	.byte 133, 177

track_233_1:
	.byte 188, 0, 189, 25, 190, 35, 191, 64
	.byte 193, 20, 186, 1, 192, 127, 212, 53
	.byte 52, 129, 192, 111, 129, 96, 129, 80
	.byte 129, 64, 129, 189, 24, 190, 49, 216
	.byte 59, 80, 137, 57, 20, 137, 55, 8
	.byte 137, 177

.align 2

track_233:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_233_0
	.word track_233_1

.align 2
