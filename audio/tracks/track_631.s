.align 2

.section .rodata
.global track_631

track_631_0:
	.byte 188, 0, 187, 75, 189, 18, 190, 63
	.byte 191, 64, 226, 60, 92, 153, 129, 177
	.byte 

track_631_1:
	.byte 188, 0, 189, 0, 190, 70, 191, 64
	.byte 186, 55, 211, 53, 112, 153, 129, 177
	.byte 

.align 2

track_631:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group5
	.word track_631_0
	.word track_631_1

.align 2
