.align 2

.global track_430

track_430_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N22
	.byte Dn3, En6
	.byte W01
	.byte BEND, c_v-60
	.byte W01
	.byte GsM2
	.byte W01
	.byte CnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte En0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn1
	.byte W01
	.byte En1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Cn2
	.byte W01
	.byte En2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Cn3
	.byte W01
	.byte En3
	.byte W06

	.byte FINE

.align 2

track_430:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_430_0

.align 2
