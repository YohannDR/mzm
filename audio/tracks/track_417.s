.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_417

track_417_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 76
	.byte PAN, c_v
	.byte N04
	.byte An4, Gs5
	.byte W36
	.byte W01

	.byte FINE

track_417_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 95
	.byte PAN, c_v
	.byte N44
	.byte Cn3, En7, CsM2
	.byte W02
	.byte VOL, 82
	.byte W02
	.byte As3
	.byte W02
	.byte Bn2
	.byte W02
	.byte Cs2
	.byte W02
	.byte En1
	.byte W02
	.byte An0
	.byte W02
	.byte Ds0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte EnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FsM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte DnM2
	.byte W04
	.byte CsM2
	.byte W02
	.byte CnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_417:
	.byte 2
	.byte 0
	.byte 166
	.byte 0
	.word voice_group8
	.word track_417_0
	.word track_417_1

.align 2
