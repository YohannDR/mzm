.align 2

.global track_567

track_567_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 94
	.byte PAN, c_v+30
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N68, An2, v100
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte PAN, c_v+27
	.byte W03
	.byte c_v+25 @ PAN
	.byte BEND, c_v-2
	.byte W03
	.byte PAN, c_v+22
	.byte W01
	.byte BEND, c_v-3
	.byte W02
	.byte PAN, c_v+19
	.byte W02
	.byte BEND, c_v-4
	.byte W01
	.byte PAN, c_v+17
	.byte W03
	.byte c_v+14 @ PAN
	.byte BEND, c_v-5
	.byte W03
	.byte PAN, c_v+11
	.byte W01
	.byte BEND, c_v-6
	.byte W02
	.byte PAN, c_v+9
	.byte W02
	.byte BEND, c_v-7
	.byte W01
	.byte PAN, c_v+6
	.byte W03
	.byte c_v+3 @ PAN
	.byte BEND, c_v-8
	.byte W02
	.byte c_v-9 @ BEND
	.byte W01
	.byte PAN, c_v
	.byte W03
	.byte c_v-2 @ PAN
	.byte BEND, c_v-10
	.byte W03
	.byte PAN, c_v-5
	.byte W01
	.byte BEND, c_v-11
	.byte W02
	.byte PAN, c_v-8
	.byte W02
	.byte BEND, c_v-12
	.byte W01
	.byte PAN, c_v-10
	.byte W03
	.byte c_v-13 @ PAN
	.byte VOL, 93
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 92
	.byte W01
	.byte PAN, c_v-16
	.byte W01
	.byte VOL, 90
	.byte BEND, c_v-14
	.byte W02
	.byte PAN, c_v-18
	.byte VOL, 88
	.byte W02
	.byte 85 @ VOL
	.byte BEND, c_v-15
	.byte W01
	.byte PAN, c_v-21
	.byte W01
	.byte VOL, 79
	.byte W02
	.byte PAN, c_v-24
	.byte VOL, 70
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 46
	.byte W01
	.byte 33 @ VOL
	.byte PAN, c_v-26
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte PAN, c_v-29
	.byte W01
	.byte c_v-30 @ PAN
	.byte VOL, 4
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_567:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_567_0

.align 2
