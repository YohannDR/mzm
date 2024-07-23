.align 2

.global track_146

track_146_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 0
	.byte PAN, c_v
	.byte N16
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte Cs0
	.byte W01
	.byte Gn1
	.byte W01
	.byte Dn2
	.byte W01
	.byte En2
	.byte W01
	.byte Dn2
	.byte W01
	.byte Bn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Ds1
	.byte W01
	.byte An0
	.byte W01
	.byte En0
	.byte W01
	.byte AsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_146:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_146_0

.align 2
