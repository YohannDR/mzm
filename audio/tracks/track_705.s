.align 2

.section .rodata
.global track_705

track_705_0:
	.byte 188, 0, 187, 75, 189, 11, 190, 89
	.byte 191, 64, 210, 60, 92, 131, 189, 19
	.byte 228, 159, 129, 177

track_705_1:
	.byte 188, 0, 189, 0, 190, 94, 191, 64
	.byte 186, 55, 130, 211, 53, 112, 159, 130
	.byte 177

.align 2

track_705:
	.byte 2
	.byte 0
	.byte 171
	.byte 0
	.word voice_group5
	.word track_705_0
	.word track_705_1

.align 2
