.align 2

.section .rodata
.global track_671

track_671_0:
	.byte 188, 0, 187, 75, 189, 2, 190, 62
	.byte 191, 70, 130, 234, 59, 80, 155, 177
	.byte 

track_671_1:
	.byte 188, 0, 189, 1, 190, 78, 191, 70
	.byte 235, 59, 100, 156, 177

.align 2

track_671:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_671_0
	.word track_671_1

.align 2
