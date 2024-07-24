.align 2

.global track_490

track_490_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 86
	.byte PAN, c_v
	.byte N17
	.byte Cn3, En6
	.byte W17

	.byte FINE

track_490_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte N17
	.byte En4, Gs4
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte CnM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte Cs1
	.byte W01
	.byte An2
	.byte W01
	.byte Dn5
	.byte W01
	.byte Bn3
	.byte W01
	.byte Bn2
	.byte W01
	.byte Cn2
	.byte W01
	.byte Dn1
	.byte W01
	.byte Fs0
	.byte W01
	.byte BnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_490:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_490_0
	.word track_490_1

.align 2
