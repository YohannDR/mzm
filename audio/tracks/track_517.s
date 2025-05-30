.align 2

.global track_517

track_517_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13, Cn3, v080
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte N06, Gn3, v032
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_517_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v-47
	.byte N08, En2, v060
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+47 @ BEND
	.byte W02
	.byte FINE

.align 2

track_517:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_517_0
	.word track_517_1

.align 2
