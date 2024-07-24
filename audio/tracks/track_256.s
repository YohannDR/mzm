.align 2

.global track_256

track_256_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W44
	.byte VOICE, 18
	.byte VOL, 31
	.byte N03
	.byte An3, Cn3
	.byte W06
	.byte N03
	.byte W06
	.byte N03
	.byte W05
	.byte N03
	.byte W05
	.byte N03
	.byte W05
	.byte N03
	.byte W05
	.byte N03
	.byte W04
	.byte N03
	.byte W04
	.byte VOL, 31
	.byte N03
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte N02
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte CnM2

	.byte FINE

track_256_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 31
	.byte PAN, c_v
	.byte N03
	.byte An3, Cn3
	.byte W11
	.byte N03
	.byte W11
	.byte N03
	.byte W11
	.byte N03
	.byte W03
	.byte VOICE, 17
	.byte VOL, 47
	.byte N60
	.byte Cn3, Gs4
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
