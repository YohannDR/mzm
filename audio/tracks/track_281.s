.align 2

.global track_281

track_281_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W18
	.byte VOICE, 16
	.byte BENDR, 6
	.byte VOL, 12
	.byte BEND, c_v+63
	.byte N22
	.byte Cn2, Cn4
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+27
	.byte W01
	.byte Cs5
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W01
	.byte VOICE, 7
	.byte VOL, 37
	.byte BEND, c_v
	.byte N03
	.byte Gn4, Cn1
	.byte W03

	.byte FINE

track_281_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 50
	.byte N10
	.byte Cn2, Cn3
	.byte W06
	.byte VOL, 37
	.byte W01
	.byte Cs0
	.byte W01
	.byte CnM1
	.byte W01
	.byte CnM2
	.byte W19
	.byte Cs1
	.byte N13
	.byte Fn2
	.byte W13

	.byte FINE

.align 2

track_281:
	.byte 2
	.byte 0
	.byte 221
	.byte 0
	.word voice_group4
	.word track_281_0
	.word track_281_1

.align 2
