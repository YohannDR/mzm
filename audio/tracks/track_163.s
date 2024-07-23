.align 2

.global track_163

track_163_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 42
	.byte PAN, c_v
	.byte N07
	.byte Fn3, En7
	.byte W07

	.byte FINE

.align 2

track_163:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group1
	.word track_163_0

.align 2
