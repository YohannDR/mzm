.align 2

.global track_193

track_193_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte N13, Cn3, v100
	.byte W13
	.byte N06, An2, v080
	.byte W06
	.byte VOICE, 4
	.byte VOL, 86
	.byte N05, Gn2, v068
	.byte W32
	.byte W01
	.byte FINE

track_193_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte N05, Cn3, v088
	.byte W05
	.byte VOICE, 23
	.byte VOL, 78
	.byte N28, An2, v092
	.byte W20
	.byte VOL, 44
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W20
	.byte FINE

.align 2

track_193:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group5
	.word track_193_0
	.word track_193_1

.align 2
