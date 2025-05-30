.align 2

.global track_292

track_292_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 37
	.byte PAN, c_v-4
	.byte N02, Cn4, v040
	.byte W02
	.byte Bn3 @ N02, v040
	.byte W22
	.byte VOICE, 4
	.byte N24, As3 @ v040
	.byte W40
	.byte As2, v060, 2 @ N24
	.byte W24
	.byte W02
	.byte VOICE, 7
	.byte VOL, 44
	.byte N04, Cn4, v040
	.byte W04
	.byte Cn4, v020 @ N04
	.byte W02
	.byte W02
	.byte VOICE, 4
	.byte N19, En2, v060
	.byte W19
	.byte FINE

track_292_1:
	.byte KEYSH, 0
	.byte W90
	.byte VOICE, 7
	.byte VOL, 44
	.byte PAN, c_v-4
	.byte W06
	.byte W14
	.byte N04, Cn4, v060
	.byte W04
	.byte Cn4, v020 @ N04
	.byte W04
	.byte FINE

track_292_2:
	.byte KEYSH, 0
	.byte W92
	.byte VOICE, 24
	.byte PAN, c_v
	.byte BENDR, 4
	.byte VOL, 37
	.byte N36, Cn4, v032
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-1
	.byte W01
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 20
	.byte BEND, c_v-34
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-52
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-57
	.byte W03
	.byte VOL, 8
	.byte BEND, c_v-62
	.byte W03
	.byte VOL, 5
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_292:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_292_0
	.word track_292_1
	.word track_292_2

.align 2
