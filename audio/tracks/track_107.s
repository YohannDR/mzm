.align 2

.global track_107

track_107_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 33
	.byte VOL, 48
	.byte PAN, c_v
	.byte N08, Cn3, v100
	.byte W08
	.byte FINE

track_107_1:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte MOD, 110
	.byte VOL, 48
	.byte PAN, c_v
	.byte LFOS, 110
	.byte N02, As4, v080
	.byte W04
	.byte LFOS, 0
	.byte W01
	.byte Dn7 @ N02, v080
	.byte N02 @ Dn7, v080
	.byte W03
	.byte FINE

.align 2

track_107:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_107_0
	.word track_107_1

.align 2
