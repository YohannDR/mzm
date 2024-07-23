.align 2

.global track_129

track_129_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte MOD, 40
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte BEND, c_v-47
	.byte N30
	.byte En3, Gs5, CsM2
	.byte W02
	.byte VOL, 14
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 24
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 47
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 41
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v+6
	.byte W02
	.byte VOL, 15
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 10
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 2
	.byte BEND, c_v+27
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

.align 2

track_129:
	.byte 1
	.byte 0
	.byte 150
	.byte 0
	.word voice_group1
	.word track_129_0

.align 2
