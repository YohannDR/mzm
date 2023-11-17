.align 2

.section .rodata
.global track_110

track_110_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 35
	.byte 191, 64, 208, 84, 127, 129, 82, 129
	.byte 177

.align 2

track_110:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_110_0

.align 2
