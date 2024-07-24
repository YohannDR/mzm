.align 2

.global track_463

track_463_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N44
	.byte An2, En6, DnM2
	.byte W06
	.byte BEND, c_v+31
	.byte W06
	.byte Gn8
	.byte W24
	.byte W01
	.byte VOL, 80
	.byte W01
	.byte Gs2
	.byte W01
	.byte Fs1
	.byte W01
	.byte Gn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_463:
	.byte 1
	.byte 0
	.byte 204
	.byte 0
	.word voice_group10
	.word track_463_0

.align 2
