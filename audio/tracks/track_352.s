.align 2

.global track_352

track_352_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-25
	.byte N24
	.byte An2, En6, CsM2
	.byte W02
	.byte VOL, 58
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 67
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v-13
	.byte W02
	.byte Bn2
	.byte W02
	.byte An3
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 63
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v+32
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 4
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-23
	.byte W01

	.byte FINE

.align 2

track_352:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_352_0

.align 2
