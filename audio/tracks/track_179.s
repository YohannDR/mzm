.align 2

.global track_179

track_179_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 55
	.byte PAN, c_v
	.byte W02
	.byte N14
	.byte An3, Gs4
	.byte W14

	.byte FINE

track_179_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W06
	.byte BEND, c_v
	.byte N44
	.byte Cn3, En2
	.byte W03
	.byte BEND, c_v-11
	.byte W03
	.byte Gs1
	.byte W03
	.byte Bn0
	.byte W03
	.byte Fn0
	.byte W01
	.byte VOL, 23
	.byte W02
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 17
	.byte W02
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 11
	.byte W02
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 8
	.byte W02
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 6
	.byte W02
	.byte BEND, c_v-54
	.byte W01
	.byte VOL, 4
	.byte W02
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte BEND, c_v-60
	.byte W01
	.byte VOL, 1
	.byte W02
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 0
	.byte W02
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_179:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group11
	.word track_179_0
	.word track_179_1

.align 2
