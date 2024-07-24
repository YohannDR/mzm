.align 2

.global track_450

track_450_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 70
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W06
	.byte BEND, c_v-47
	.byte N19
	.byte Cn3, En7
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte Ds0
	.byte W01
	.byte An0
	.byte W01
	.byte Dn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Fs2
	.byte W01
	.byte Bn2
	.byte W01
	.byte En3
	.byte W01
	.byte An3
	.byte W01
	.byte Dn4
	.byte W01
	.byte Gs4
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fs5
	.byte W01
	.byte Bn5
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+47
	.byte W01

	.byte FINE

.align 2

track_450:
	.byte 1
	.byte 0
	.byte 201
	.byte 0
	.word voice_group10
	.word track_450_0

.align 2
