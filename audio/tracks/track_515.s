.align 2

.global track_515

track_515_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 48
	.byte PAN, c_v
	.byte N03, En2, v064
	.byte W03
	.byte Cn2, v080 @ N03
	.byte W03
	.byte Cn2, v032 @ N03
	.byte W03
	.byte Cn2, v012 @ N03
	.byte W03
	.byte FINE

.align 2

track_515:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_515_0

.align 2
