.align 2

.section .rodata
.global track_695

track_695_0:
	.byte 188, 0, 187, 75, 189, 43, 190, 100
	.byte 191, 50, 132, 212, 60, 80, 133, 64
	.byte 133, 67, 64, 134, 69, 32, 135, 71
	.byte 20, 133, 177

track_695_1:
	.byte 188, 0, 189, 42, 190, 127, 191, 50
	.byte 132, 212, 67, 127, 133, 68, 133, 69
	.byte 88, 134, 69, 44, 135, 72, 32, 133
	.byte 177

.align 2

track_695:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_695_0
	.word track_695_1

.align 2
