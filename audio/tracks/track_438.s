.align 2

.global track_438

track_438_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 36
	.byte BEND, c_v
	.byte N10, An3, v080
	.byte W01
	.byte BEND, c_v-7
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W01
	.byte FINE

.align 2

track_438:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_438_0

.align 2
