.align 2

.global track_341

track_341_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 42
	.byte PAN, c_v
	.byte N04, Cn3, v100
	.byte W04
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N36, An1 @ v100
	.byte W01
	.byte BEND, c_v-39
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W11
	.byte VOL, 42
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W21
	.byte FINE

track_341_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v-63
	.byte N24, Bn2, v100
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-54 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W54
	.byte FINE

.align 2

track_341:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_341_0
	.word track_341_1

.align 2
