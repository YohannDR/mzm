.align 2

.global track_510

track_510_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 27
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v+47
	.byte N11
	.byte Dn3, Cn3
	.byte W01
	.byte BEND, c_v+37
	.byte W01
	.byte Fs5
	.byte W01
	.byte Gs4
	.byte W01
	.byte An3
	.byte W01
	.byte Bn2
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_510:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_510_0

.align 2
