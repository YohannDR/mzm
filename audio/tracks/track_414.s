.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_414

track_414_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 30
	.byte VOL, 63
	.byte PAN, c_v
	.byte BENDR, 9
	.byte LFOS, 40
	.byte BEND, c_v+8
	.byte N56
	.byte Cn3, En6
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte Fs3
	.byte W02
	.byte Ds3
	.byte W02
	.byte Cn3
	.byte W02
	.byte An2
	.byte W02
	.byte Fs2
	.byte W02
	.byte En2
	.byte W02
	.byte Cs2
	.byte W02
	.byte As1
	.byte W02
	.byte Gn1
	.byte W02
	.byte En1
	.byte W02
	.byte Cs1
	.byte W02
	.byte Bn0
	.byte W02
	.byte Gs0
	.byte W02
	.byte Fn0
	.byte W02
	.byte Dn0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DsM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte AnM2
	.byte W02
	.byte FsM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W06

	.byte FINE

track_414_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 30
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 6
	.byte LFOS, 120
	.byte BEND, c_v+8
	.byte N24
	.byte Fn2, En6
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte Fs3
	.byte W02
	.byte Ds3
	.byte W02
	.byte Cn3
	.byte W02
	.byte An2
	.byte W02
	.byte Fs2
	.byte W02
	.byte En2
	.byte W02
	.byte Cs2
	.byte W02
	.byte As1
	.byte W02
	.byte Gn1
	.byte W02
	.byte En1
	.byte W02
	.byte Cs1
	.byte N24
	.byte W02
	.byte BEND, c_v-29
	.byte W02
	.byte Gs0
	.byte W02
	.byte Fn0
	.byte W02
	.byte Dn0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GsM1
	.byte W02
	.byte FsM1
	.byte W02
	.byte DsM1
	.byte W02
	.byte CnM1
	.byte W02
	.byte AnM2
	.byte W02
	.byte FsM2
	.byte W02
	.byte DsM2
	.byte N08
	.byte W02
	.byte BEND, c_v-63
	.byte W06

	.byte FINE

.align 2

track_414:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group6
	.word track_414_0
	.word track_414_1

.align 2
