.align 2

.global track_468

track_468_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte MOD, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte PRIO, 2
	.byte BEND, c_v-63
	.byte TIE, Fn3, v080
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W90
	.byte W24
	.byte W01
	.byte VOL, 39
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Fn3, v080
	.byte FINE

track_468_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE, Cn7, v040
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W90
	.byte W20
	.byte 20 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W06
	.byte EOT @ Cn7, v040
	.byte FINE

track_468_2:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 5
	.byte VOL, 49
	.byte PAN, c_v
	.byte BENDR, 6
	.byte PRIO, 1
	.byte N44, Cn3, v080, 1
	.byte W02
	.byte VOL, 51
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W03
	.byte FINE

.align 2

track_468:
	.byte 3
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_468_0
	.word track_468_1
	.word track_468_2

.align 2
