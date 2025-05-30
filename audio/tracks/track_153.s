.align 2

.global track_153

track_153_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 40
	.byte PAN, c_v
	.byte N03, Fn3, v100
	.byte W03
	.byte FINE

.align 2

track_153:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_153_0

.align 2
