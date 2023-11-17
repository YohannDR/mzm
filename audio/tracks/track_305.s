.align 2

.section .rodata
.global track_305

track_305_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 94
	.byte 191, 64, 213, 60, 100, 134, 189, 0
	.byte 190, 70, 217, 55, 60, 156, 177

track_305_1:
	.byte 188, 0, 189, 19, 190, 78, 191, 64
	.byte 130, 217, 60, 100, 138, 62, 20, 154
	.byte 177

.align 2

track_305:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_305_0
	.word track_305_1

.align 2
