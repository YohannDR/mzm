.align 2

.global track_191

track_191_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte MOD, 14
	.byte VOL, 127
	.byte PAN, c_v+3
	.byte LFOS, 90
	.byte N08, Fs2, v127
	.byte W16
	.byte FINE

.align 2

track_191:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group11
	.word track_191_0

.align 2
