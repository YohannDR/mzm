.align 2

.global track_591

track_591_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v
	.byte N13, Fn4, v080
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-54
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-60
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-62
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-63
	.byte W01
	.byte VOICE, 20
	.byte BEND, c_v
	.byte N02, Bn3, v060
	.byte W02
	.byte Cn4 @ N02, v060
	.byte W02
	.byte FINE

.align 2

track_591:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_591_0

.align 2
