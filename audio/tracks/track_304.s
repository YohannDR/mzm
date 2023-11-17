.align 2

.section .rodata
.global track_304

track_304_0:
	.byte 188, 0, 187, 75, 189, 19, 190, 70
	.byte 191, 64, 216, 57, 108, 137, 220, 60
	.byte 48, 141, 189, 1, 190, 77, 212, 55
	.byte 68, 154, 129, 177

track_304_1:
	.byte 188, 0, 189, 11, 190, 85, 191, 64
	.byte 212, 60, 88, 133, 189, 23, 190, 70
	.byte 229, 60, 68, 147, 190, 25, 129, 9
	.byte 129, 0, 152, 131, 177

.align 2

track_304:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_304_0
	.word track_304_1

.align 2
