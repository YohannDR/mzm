.align 2

.global track_351

track_351_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 39
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+32
	.byte W04
	.byte N12, Gn2, v080
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_351:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_351_0

.align 2
