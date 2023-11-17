.align 2

.section .rodata
.global track_662

track_662_0:
	.byte 188, 0, 187, 75, 189, 28, 190, 50
	.byte 191, 64, 235, 60, 80, 176, 129, 235
	.byte 62, 72, 175, 131, 129, 61, 64, 164
	.byte 60, 80, 155, 131, 156, 130, 178, 58
	.byte 231, 33, 8, 177

track_662_1:
	.byte 188, 0, 189, 28, 190, 19, 191, 64
	.byte 164, 235, 65, 72, 156, 164, 129, 235
	.byte 64, 64, 155, 131, 156, 131, 64, 52
	.byte 163, 129, 140, 65, 68, 152, 130, 178
	.byte 93, 231, 33, 8, 138, 177

.align 2

track_662:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group3
	.word track_662_0
	.word track_662_1

.align 2
