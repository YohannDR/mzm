.align 2

.global track_337

track_337_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N24
	.byte Fn1, Gs4
	.byte W04
	.byte BEND, c_v+28
	.byte W05
	.byte Gs2
	.byte W07
	.byte VOL, 40
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Cs0
	.byte W01
	.byte GsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_337:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_337_0

.align 2
