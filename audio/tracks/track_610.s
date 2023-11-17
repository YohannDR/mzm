.align 2

.section .rodata
.global track_610

track_610_0:
	.byte 188, 0, 187, 75, 189, 47, 190, 51
	.byte 191, 64, 229, 60, 100, 150, 177

.align 2

track_610:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group3
	.word track_610_0

.align 2
