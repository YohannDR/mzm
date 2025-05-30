.align 2

.global track_473

track_473_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 66
	.byte PAN, c_v
	.byte BENDR, 24
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N08, Cn4, v060
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N08, Cn4, v032
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N08, Cn4, v012
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

track_473_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte MOD, 1
	.byte VOL, 48
	.byte PAN, c_v
	.byte LFOS, 80
	.byte N30, Cn3, v120
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte 49 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte FINE

.align 2

track_473:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group12
	.word track_473_0
	.word track_473_1

.align 2
