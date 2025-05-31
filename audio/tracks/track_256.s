.align 2

.global track_256

track_256_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03, Cn3, v080
	.byte W44
	.byte VOICE, 18
	.byte VOL, 31
	.byte N03, An3, v060
	.byte W06
	.byte N03 @ An3, v060
	.byte W06
	.byte N03 @ An3, v060
	.byte W05
	.byte N03 @ An3, v060
	.byte W05
	.byte N03 @ An3, v060
	.byte W05
	.byte N03 @ An3, v060
	.byte W05
	.byte N03 @ An3, v060
	.byte W04
	.byte N03 @ An3, v060
	.byte W04
	.byte VOL, 31
	.byte N03 @ An3, v060
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte N02 @ An3, v060
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 0 @ VOL
	.byte FINE

track_256_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 31
	.byte PAN, c_v
	.byte N03, An3, v060
	.byte W11
	.byte N03 @ An3, v060
	.byte W11
	.byte N03 @ An3, v060
	.byte W11
	.byte N03 @ An3, v060
	.byte W03
	.byte VOICE, 17
	.byte VOL, 47
	.byte N60, Cn3, v080
	.byte W60
	.byte FINE

.align 2

track_256:
	.byte 2
	.byte 0
	.byte 222
	.byte 0
	.word voice_group2
	.word track_256_0
	.word track_256_1

.align 2
