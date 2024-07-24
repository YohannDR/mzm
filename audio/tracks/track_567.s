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
	.byte N68
	.byte An2, En6
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte PAN, c_v+27
	.byte W03
	.byte Fn5
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
	.byte Fs4
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
	.byte Gn3
	.byte BEND, c_v-8
	.byte W02
	.byte Gn2
	.byte W01
	.byte PAN, c_v
	.byte W03
	.byte Dn3
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
	.byte Ds2
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
	.byte Cs5
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
	.byte An0
	.byte PAN, c_v-26
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte EnM1
	.byte W01
	.byte AsM2
	.byte PAN, c_v-29
	.byte W01
	.byte As0
	.byte VOL, 4
	.byte W01
	.byte CnM2

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
