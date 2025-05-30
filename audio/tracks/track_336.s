.align 2

.global track_336

track_336_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v-63
	.byte N12, Cn3, v060
	.byte W02
	.byte BEND, c_v-61
	.byte W01
	.byte c_v-59 @ BEND
	.byte W01
	.byte c_v-56 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte FINE

.align 2

track_336:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_336_0

.align 2
