.align 2

.section .rodata
.global track_526

track_526_0:
	.byte 188, 0, 187, 75, 189, 5, 190, 21
	.byte 191, 64, 209, 72, 80, 132, 76, 52
	.byte 130, 177

track_526_1:
	.byte 188, 0, 189, 2, 190, 17, 191, 64
	.byte 209, 60, 80, 132, 60, 40, 132, 60
	.byte 20, 130, 177

.align 2

track_526:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_526_0
	.word track_526_1

.align 2
