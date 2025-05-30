.align 2

.global track_561

track_561_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16, Cn2, v120
	.byte W01
	.byte BEND, c_v-55
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte VOICE, 10
	.byte BEND, c_v
	.byte N48, Cn2, v080
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W04
	.byte 76 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_561_1:
	.byte KEYSH, 0
	.byte W16
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte N48, En2, v080
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W04
	.byte 76 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_561_2:
	.byte KEYSH, 0
	.byte W16
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte N48, Gn2, v080
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W04
	.byte 76 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_561:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group17
	.word track_561_0
	.word track_561_1
	.word track_561_2

.align 2
