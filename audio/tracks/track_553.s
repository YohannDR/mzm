.align 2

.global track_553

track_553_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte N72, Cn3, v112
	.byte W72
	.byte FINE

track_553_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N72, Cn3, v100
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
	.byte W12
	.byte FINE

track_553_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte MOD, 20
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 5
	.byte N72, Fn2, v080
	.byte W72
	.byte FINE

.align 2

track_553:
	.byte 3
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_553_0
	.word track_553_1
	.word track_553_2

.align 2
