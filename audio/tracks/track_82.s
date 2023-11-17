.align 2

.section .rodata
.global track_82

track_82_0:
	.byte 188, 0, 187, 60, 189, 2, 190, 0
	.byte 231, 60, 12, 176, 178, 222, 184, 34
	.byte 8, 177

.align 2

track_82:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_82_0

.align 2
