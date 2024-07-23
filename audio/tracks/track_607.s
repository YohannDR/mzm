.align 2

.global track_607

track_607_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N15
	.byte Gn3, Gs4
	.byte W01
	.byte BEND, c_v+16
	.byte W01
	.byte Bn5
	.byte W01
	.byte Ds7
	.byte W01
	.byte Gn8
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v
	.byte W01
	.byte Gs4
	.byte W01
	.byte Cn6
	.byte W01
	.byte Ds7
	.byte W01
	.byte Gn8
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v
	.byte W01
	.byte Gs4
	.byte W01
	.byte Cn6
	.byte W01
	.byte Ds7
	.byte W01
	.byte Gn8
	.byte W01

	.byte FINE

.align 2

track_607:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_607_0

.align 2
