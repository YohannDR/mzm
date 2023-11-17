.align 2

.section .rodata
.global track_693

track_693_0:
	.byte 188, 0, 187, 75, 189, 43, 190, 94
	.byte 191, 50, 132, 212, 60, 60, 133, 64
	.byte 133, 64, 20, 133, 177

track_693_1:
	.byte 188, 0, 189, 42, 190, 113, 191, 50
	.byte 132, 212, 67, 120, 133, 212, 133, 67
	.byte 32, 133, 177

.align 2

track_693:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_693_0
	.word track_693_1

.align 2
