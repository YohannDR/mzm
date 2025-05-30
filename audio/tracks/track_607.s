.align 2

.global track_607

track_607_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N15, Gn3, v080
	.byte W01
	.byte BEND, c_v+16
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_607:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_607_0

.align 2
