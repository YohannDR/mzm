.align 2

.global track_397

track_397_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 50
	.byte PAN, c_v
	.byte N03
	.byte Gn3, Cn3
	.byte W03
	.byte VOICE, 19
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N09
	.byte Fn2, Gs4
	.byte W01
	.byte BEND, c_v-44
	.byte W01
	.byte Ds1
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte EnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_397:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_397_0

.align 2
