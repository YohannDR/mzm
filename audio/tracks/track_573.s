.align 2

.global track_573

track_573_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte N90, Cn3, v112
	.byte W90
	.byte FINE

track_573_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N90, Cn3, v100
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-10 @ BEND
	.byte W02
	.byte c_v-9 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-6 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-2 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v+4 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W30
	.byte FINE

track_573_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte MOD, 20
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 5
	.byte N90, Fn2, v080
	.byte W90
	.byte FINE

track_573_3:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 3
	.byte BEND, c_v+47
	.byte N90, Cn4, v052
	.byte W03
	.byte BEND, c_v+44
	.byte W03
	.byte c_v+42 @ BEND
	.byte W03
	.byte c_v+39 @ BEND
	.byte W03
	.byte c_v+36 @ BEND
	.byte W03
	.byte c_v+34 @ BEND
	.byte W03
	.byte c_v+31 @ BEND
	.byte W03
	.byte c_v+28 @ BEND
	.byte W03
	.byte c_v+26 @ BEND
	.byte W03
	.byte c_v+23 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+18 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+12 @ BEND
	.byte W03
	.byte c_v+10 @ BEND
	.byte W03
	.byte c_v+7 @ BEND
	.byte W03
	.byte VOL, 78
	.byte BEND, c_v+4
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 74
	.byte BEND, c_v-1
	.byte W03
	.byte VOL, 72
	.byte BEND, c_v-4
	.byte W03
	.byte VOL, 70
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 66
	.byte BEND, c_v-12
	.byte W03
	.byte VOL, 64
	.byte BEND, c_v-14
	.byte W21
	.byte FINE

.align 2

track_573:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_573_0
	.word track_573_1
	.word track_573_2
	.word track_573_3

.align 2
