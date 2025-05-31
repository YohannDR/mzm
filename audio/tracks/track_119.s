.align 2

.global track_119

track_119_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 30
	.byte BEND, c_v
	.byte N10, Cn2, v127
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W07
	.byte FINE

.align 2

track_119:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_119_0

.align 2
