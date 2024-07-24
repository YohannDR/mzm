.align 2

.global track_323

track_323_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 19
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte BEND, c_v+32
	.byte N18
	.byte Cn3, Cn3
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+17
	.byte W01
	.byte Fs4
	.byte W01
	.byte Ds4
	.byte W01
	.byte Cn4
	.byte W01
	.byte An3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Cn3
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_323:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_323_0

.align 2
