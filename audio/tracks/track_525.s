.align 2

.section .rodata
.global track_525

track_525_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 31
	.byte 191, 64, 131, 226, 60, 80, 162, 177
	.byte 

track_525_1:
	.byte 188, 0, 189, 13, 190, 47, 191, 64
	.byte 131, 226, 53, 100, 162, 177

track_525_2:
	.byte 188, 0, 189, 2, 190, 31, 191, 64
	.byte 209, 67, 80, 130, 63, 130, 60, 130
	.byte 60, 32, 132, 60, 12, 159, 131, 177
	.byte 

.align 2

track_525:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_525_0
	.word track_525_1
	.word track_525_2

.align 2
