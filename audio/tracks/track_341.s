.align 2

.global track_341

track_341_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 42
	.byte PAN, c_v
	.byte N04
	.byte Cn3, En6
	.byte W04
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N36
	.byte An1
	.byte W01
	.byte BEND, c_v-39
	.byte W01
	.byte An0
	.byte W01
	.byte En1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Gn3
	.byte W11
	.byte VOL, 42
	.byte W02
	.byte Fs0
	.byte W02
	.byte AnM1
	.byte W02
	.byte DsM1
	.byte W02
	.byte AsM2
	.byte W02
	.byte GsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W02
	.byte CnM2
	.byte W21

	.byte FINE

track_341_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v-63
	.byte N24
	.byte Bn2, En6
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte AsM2
	.byte W01
	.byte FnM1
	.byte W01
	.byte Ds0
	.byte W01
	.byte Gn1
	.byte W01
	.byte En3
	.byte W54

	.byte FINE

.align 2

track_341:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_341_0
	.word track_341_1

.align 2
