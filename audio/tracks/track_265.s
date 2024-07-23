.align 2

.global track_265

track_265_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 40
	.byte PAN, c_v
	.byte N21
	.byte Dn3, Cn3
	.byte W16
	.byte VOL, 33
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_265:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_265_0

.align 2
