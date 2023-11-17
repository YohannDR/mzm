.align 2

.section .rodata
.global track_164

track_164_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 100
	.byte 191, 64, 209, 60, 127, 130, 189, 14
	.byte 212, 60, 100, 133, 221, 64, 127, 142
	.byte 220, 62, 52, 141, 189, 12, 225, 60
	.byte 20, 148, 177

track_164_1:
	.byte 188, 0, 189, 1, 190, 100, 191, 64
	.byte 186, 54, 132, 212, 56, 80, 133, 217
	.byte 56, 112, 159, 129, 177

.align 2

track_164:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group5
	.word track_164_0
	.word track_164_1

.align 2
