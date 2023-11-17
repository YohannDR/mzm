.align 2

.section .rodata
.global track_107

track_107_0:
	.byte 188, 0, 187, 75, 189, 33, 190, 48
	.byte 191, 64, 215, 60, 100, 136, 177

track_107_1:
	.byte 188, 0, 189, 34, 196, 110, 190, 48
	.byte 191, 64, 194, 110, 209, 82, 80, 132
	.byte 194, 0, 129, 110, 209, 131, 177

.align 2

track_107:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_107_0
	.word track_107_1

.align 2
