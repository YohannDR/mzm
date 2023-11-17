.align 2

.section .rodata
.global track_465

track_465_0:
	.byte 188, 0, 187, 75, 176, 152, 189, 20
	.byte 190, 127, 191, 44, 222, 60, 127, 143
	.byte 231, 57, 127, 2, 163, 129, 143, 177
	.byte 

track_465_1:
	.byte 188, 0, 176, 154, 189, 19, 190, 127
	.byte 191, 44, 222, 60, 127, 143, 231, 57
	.byte 127, 1, 160, 131, 143, 177

track_465_2:
	.byte 188, 0, 176, 152, 189, 2, 190, 100
	.byte 191, 64, 186, 25, 209, 81, 80, 130
	.byte 189, 21, 209, 57, 112, 141, 189, 2
	.byte 209, 55, 80, 130, 189, 21, 216, 55
	.byte 120, 162, 129, 143, 177

.align 2

track_465:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group10
	.word track_465_0
	.word track_465_1
	.word track_465_2

.align 2
