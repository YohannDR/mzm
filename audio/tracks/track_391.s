.align 2

.global track_391

track_391_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 34
	.byte PAN, c_v
	.byte N01, An2, v072
	.byte W01
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N09, Bn1 @ v072
	.byte W01
	.byte BEND, c_v-35
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W02
	.byte VOL, 14
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_391:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_391_0

.align 2
