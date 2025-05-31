.align 2

.global track_280

track_280_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 37
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03, Gn4, v036
	.byte W03
	.byte VOICE, 16
	.byte VOL, 37
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16, Fn2, v080
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

track_280_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 37
	.byte PAN, c_v
	.byte N13, Fn2, v060
	.byte W32
	.byte VOL, 50
	.byte N10, Cn2 @ v060
	.byte W06
	.byte VOL, 37
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_280:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_280_0
	.word track_280_1

.align 2
