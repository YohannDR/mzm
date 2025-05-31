.align 2

.global track_444

track_444_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v-63
	.byte N32, Cn2, v080, 1
	.byte W01
	.byte BEND, c_v-56
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte MOD, 40
	.byte LFOS, 127
	.byte BEND, c_v-21
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte MOD, 20
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+28 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte MOD, 10
	.byte BEND, c_v+63
	.byte W06
	.byte VOL, 56
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_444:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_444_0

.align 2
