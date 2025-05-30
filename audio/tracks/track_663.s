.align 2

.global track_663

track_663_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W08
	.byte VOICE, 29
	.byte VOL, 90
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-8
	.byte N36, Cn3, v080
	.byte W02
	.byte BEND, c_v-7
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte c_v+1 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v+4 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+8 @ BEND
	.byte W12
	.byte FINE

.align 2

track_663:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_663_0

.align 2
