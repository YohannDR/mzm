.align 2

.global track_533

track_533_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N04
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W04

	.byte FINE

track_533_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 2
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W08
	.byte W08
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W04

	.byte FINE

track_533_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 31
	.byte PAN, c_v
	.byte W16
	.byte N04
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W16
	.byte Gn2, Gs4
	.byte W04
	.byte Bn2, Cn3
	.byte W04
	.byte Fs3, En1
	.byte W04

	.byte FINE

.align 2

track_533:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group16
	.word track_533_0
	.word track_533_1
	.word track_533_2

.align 2
