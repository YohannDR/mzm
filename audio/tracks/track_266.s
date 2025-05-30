.align 2

.global track_266

track_266_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N06, Cn6, v060
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W03
	.byte N06, Cn6, v040
	.byte W06
	.byte Cn6, v020 @ N06
	.byte W12
	.byte FINE

.align 2

track_266:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_266_0

.align 2
