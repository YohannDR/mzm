.align 2

.section .rodata
.global track_502

track_502_0:
	.byte 188, 0, 187, 75, 189, 3, 190, 18
	.byte 191, 64, 211, 77, 80, 132, 77, 40
	.byte 132, 77, 20, 132, 177

.align 2

track_502:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_502_0

.align 2
