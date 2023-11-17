.align 2

.section .rodata
.global track_456

track_456_0:
	.byte 188, 0, 187, 75, 189, 0, 190, 70
	.byte 191, 44, 210, 60, 80, 131, 189, 13
	.byte 219, 48, 92, 132, 190, 70, 129, 47
	.byte 129, 32, 129, 21, 129, 15, 129, 10
	.byte 129, 6, 129, 2, 129, 0, 152, 177
	.byte 

track_456_1:
	.byte 188, 0, 189, 14, 190, 56, 191, 44
	.byte 186, 72, 138, 213, 81, 80, 153, 129
	.byte 177

.align 2

track_456:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_456_0
	.word track_456_1

.align 2
