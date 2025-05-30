.align 2

.global track_679

track_679_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 94
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N07, Cn4, v100
	.byte W07
	.byte VOICE, 10
	.byte BENDR, 4
	.byte VOL, 112
	.byte BEND, c_v-1
	.byte N18, An3, v080
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 50
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W44
	.byte W02
	.byte FINE

track_679_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N05, Gn2, v127
	.byte W68
	.byte W01
	.byte FINE

.align 2

track_679:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_679_0
	.word track_679_1

.align 2
