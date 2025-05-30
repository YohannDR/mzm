.align 2

.global track_584

track_584_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte TIE, Cn3, v120
	.byte W30
	.byte VOL, 94
	.byte W03
	.byte 92 @ VOL
	.byte W03
	.byte 88 @ VOL
	.byte W03
	.byte 84 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 63
	.byte W02
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 60
	.byte W02
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 58
	.byte W02
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 55
	.byte W02
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 52
	.byte W02
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 51
	.byte W02
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 48
	.byte W02
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 46
	.byte W02
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 44
	.byte W02
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 41
	.byte W02
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 40
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte BEND, c_v-16
	.byte W03
	.byte VOL, 21
	.byte BEND, c_v-18
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-24
	.byte W03
	.byte c_v-26 @ BEND
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-28
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-30
	.byte W03
	.byte VOL, 11
	.byte BEND, c_v-32
	.byte W03
	.byte VOL, 10
	.byte W06
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W06
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Cn3, v120
	.byte FINE

.align 2

track_584:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_584_0

.align 2
