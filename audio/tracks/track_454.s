.align 2

.global track_454

track_454_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 40
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N28, An3, v080
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+29 @ BEND
	.byte W02
	.byte c_v+34 @ BEND
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte 33 @ VOL
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 28 @ VOL
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte 25 @ VOL
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 23 @ VOL
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte 20 @ VOL
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte FINE

.align 2

track_454:
	.byte 1
	.byte 0
	.byte 175
	.byte 0
	.word voice_group10
	.word track_454_0

.align 2
