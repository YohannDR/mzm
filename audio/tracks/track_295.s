.align 2

.global track_295

track_295_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 22
	.byte PAN, c_v
	.byte BENDR, 2
	.byte W03
	.byte N12, Fs2, v080
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W09
	.byte VOICE, 7
	.byte VOL, 33
	.byte N02, Cn4, v060
	.byte W02
	.byte Cn4, v020 @ N02
	.byte W02
	.byte FINE

.align 2

track_295:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_295_0

.align 2
