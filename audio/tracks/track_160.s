.align 2

.section .rodata
.global track_160

track_160_0:
	.byte 188, 0, 187, 75, 189, 34, 190, 50
	.byte 191, 64, 210, 60, 80, 131, 189, 35
	.byte 220, 141, 60, 32, 141, 177

track_160_1:
	.byte 188, 0, 189, 25, 190, 12, 191, 64
	.byte 193, 20, 192, 127, 223, 64, 52, 129
	.byte 190, 18, 192, 119, 129, 190, 25, 192
	.byte 110, 129, 190, 31, 192, 102, 129, 93
	.byte 129, 85, 129, 77, 129, 68, 129, 60
	.byte 129, 51, 129, 43, 129, 35, 129, 26
	.byte 129, 18, 129, 9, 129, 1, 129, 177
	.byte 

.align 2

track_160:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_160_0
	.word track_160_1

.align 2
