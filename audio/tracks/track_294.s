.align 2

.global track_294

track_294_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte VOL, 0
	.byte N80, Gn1, v127, 2
	.byte N80, Cn2, v127, 2
	.byte W01
	.byte VOL, 0
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W24
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W15
	.byte W05
	.byte FINE

track_294_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 14
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-47
	.byte N52, Cn2, v040
	.byte W03
	.byte BEND, c_v-42
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-36
	.byte W03
	.byte c_v-31 @ BEND
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-25
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-14
	.byte W03
	.byte c_v-9 @ BEND
	.byte W03
	.byte VOL, 21
	.byte BEND, c_v-4
	.byte W03
	.byte VOL, 22
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v+7
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v+13
	.byte W03
	.byte VOL, 27
	.byte BEND, c_v+18
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v+24
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v+29
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v+34
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v+40
	.byte W03
	.byte VOL, 39
	.byte W01
	.byte VOICE, 25
	.byte VOL, 78
	.byte BENDR, 8
	.byte PRIO, 25
	.byte BEND, c_v-63
	.byte N10, Cn3, v100
	.byte W01
	.byte BEND, c_v-54
	.byte W01
	.byte c_v-45 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-18 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W30
	.byte W05
	.byte FINE

.align 2

track_294:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_294_0
	.word track_294_1

.align 2
