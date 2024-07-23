.align 2

.global track_193

track_193_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte N13
	.byte Cn3, En6
	.byte W13
	.byte N06
	.byte An2, Gs4
	.byte W06
	.byte VOICE, 4
	.byte VOL, 86
	.byte N05
	.byte Gn2, Gs3
	.byte W32
	.byte W01

	.byte FINE

track_193_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte N05
	.byte Cn3, En5
	.byte W05
	.byte VOICE, 23
	.byte VOL, 78
	.byte N28
	.byte An2, Gs5
	.byte W20
	.byte VOL, 44
	.byte W01
	.byte En0
	.byte W01
	.byte GnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
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
