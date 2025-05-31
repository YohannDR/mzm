.align 2

.global track_189

track_189_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte MOD, 14
	.byte VOL, 110
	.byte PAN, c_v+20
	.byte LFOS, 90
	.byte N08, Fs2, v127
	.byte W16
	.byte FINE

.align 2

track_189:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group11
	.word track_189_0

.align 2
