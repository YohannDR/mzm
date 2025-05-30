.align 2

.global track_609

track_609_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 36
	.byte BEND, c_v+63
	.byte N16, Cn4, v080
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+50
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v
	.byte W01
	.byte VOL, 1
	.byte FINE

.align 2

track_609:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_609_0

.align 2
