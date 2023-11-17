.align 2

.section .rodata
.global track_111

track_111_0:
	.byte 188, 0, 187, 75, 189, 12, 190, 35
	.byte 191, 64, 208, 84, 127, 129, 209, 82
	.byte 130, 177

.align 2

track_111:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_111_0

.align 2
