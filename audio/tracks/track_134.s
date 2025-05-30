.align 2

.global track_134

track_134_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 43
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v
	.byte N09, Cn3, v080
	.byte W09
	.byte Cn3, v032 @ N09
	.byte W01
	.byte BEND, c_v-1
	.byte W03
	.byte c_v-5 @ BEND
	.byte W03
	.byte c_v-8 @ BEND
	.byte W02
	.byte N09, Cn3, v016
	.byte W01
	.byte BEND, c_v-12
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-19 @ BEND
	.byte W02
	.byte FINE

.align 2

track_134:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group1
	.word track_134_0

.align 2
