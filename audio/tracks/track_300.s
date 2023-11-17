.align 2

.section .rodata
.global track_300

track_300_0:
	.byte 188, 0, 187, 75, 189, 18, 190, 56
	.byte 191, 64, 226, 60, 92, 153, 129, 177
	.byte 

track_300_1:
	.byte 188, 0, 189, 0, 190, 62, 191, 64
	.byte 186, 55, 211, 53, 112, 153, 129, 177
	.byte 

.align 2

track_300:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word voice_group5
	.word track_300_0
	.word track_300_1

.align 2
