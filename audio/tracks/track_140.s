.align 2

.global track_140

track_140_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 28
	.byte PAN, c_v
	.byte N06, Cn3, v127
	.byte W06
	.byte Cn3, v080 @ N06
	.byte W07
	.byte Cn3, v060 @ N06
	.byte W07
	.byte Cn3, v020 @ N06
	.byte W06
	.byte FINE

track_140_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte PAN, c_v
	.byte W03
	.byte VOL, 17
	.byte N24, Cn2, v112, 1
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_140:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_140_0
	.word track_140_1

.align 2
