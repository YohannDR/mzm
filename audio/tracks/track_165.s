.align 2

.global track_165

track_165_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 74
	.byte PAN, c_v
	.byte N03, Bn2, v092
	.byte W03
	.byte VOICE, 19
	.byte N06 @ Bn2, v092
	.byte W06
	.byte N21, Cn3, v072
	.byte W44
	.byte W03
	.byte FINE

track_165_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02, Cn4, v080
	.byte W02
	.byte VOICE, 2
	.byte N04, Gn2, v120
	.byte W54
	.byte FINE

.align 2

track_165:
	.byte 2
	.byte 0
	.byte 190
	.byte 0
	.word voice_group5
	.word track_165_0
	.word track_165_1

.align 2
