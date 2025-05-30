.align 2

.global track_461

track_461_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 16
	.byte BEND, c_v-32
	.byte N32, Gn3, v120, 1
	.byte W03
	.byte BEND, c_v-9
	.byte W03
	.byte c_v+6 @ BEND
	.byte W03
	.byte c_v+13 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+11 @ BEND
	.byte W03
	.byte VOL, 57
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 43
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_461:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word voice_group10
	.word track_461_0

.align 2
