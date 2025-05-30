.align 2

.global track_158

track_158_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 49
	.byte VOL, 34
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v
	.byte N12, Fn1, v080
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

.align 2

track_158:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group1
	.word track_158_0

.align 2
