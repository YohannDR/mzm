.align 2

.global track_306

track_306_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 70
	.byte PAN, c_v
	.byte N03, Cn3, v080
	.byte W03
	.byte VOICE, 19
	.byte MOD, 90
	.byte LFOS, 40
	.byte N06 @ Cn3, v080
	.byte W05
	.byte LFOS, 60
	.byte W01
	.byte N21, Dn3, v060
	.byte W04
	.byte LFOS, 80
	.byte W05
	.byte En6 @ N21, v060
	.byte W05
	.byte Cn8 @ N21, v060
	.byte W36
	.byte W01
	.byte FINE

track_306_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 36
	.byte W01
	.byte BEND, c_v-63
	.byte N10, Cn2, v092
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-35
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-7
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOICE, 2
	.byte VOL, 77
	.byte N04, Fn2, v112
	.byte W48
	.byte W01
	.byte FINE

.align 2

track_306:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_306_0
	.word track_306_1

.align 2
