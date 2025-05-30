.align 2

.global track_612

track_612_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 5
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N15, An3, v080
	.byte W01
	.byte BEND, c_v-60
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+13
	.byte W01
	.byte FINE

.align 2

track_612:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group8
	.word track_612_0

.align 2
