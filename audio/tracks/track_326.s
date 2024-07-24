.align 2

.global track_326

track_326_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 20
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 100
	.byte W04
	.byte N06
	.byte Cn2, Gs4
	.byte W06
	.byte BEND, c_v-63
	.byte N10
	.byte Cn3
	.byte W01
	.byte BEND, c_v-47
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte En3
	.byte W06

	.byte FINE

.align 2

track_326:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_326_0

.align 2
