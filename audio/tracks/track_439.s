.align 2

.global track_439

track_439_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 48
	.byte BEND, c_v-63
	.byte N08, Cn3, v080
	.byte W01
	.byte BEND, c_v-57
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W07
	.byte VOICE, 15
	.byte VOL, 50
	.byte BENDR, 16
	.byte BEND, c_v-63
	.byte N13, Cn3, v072
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_439:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_439_0

.align 2
