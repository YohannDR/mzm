.align 2

.global track_452

track_452_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W08
	.byte BEND, c_v-47
	.byte N32, Cn3, v112, 3
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-22 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_452:
	.byte 1
	.byte 0
	.byte 203
	.byte 0
	.word voice_group10
	.word track_452_0

.align 2
