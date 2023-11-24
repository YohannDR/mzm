.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_589

track_589_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W48
	.byte W02
	.byte VOICE, 20
	.byte VOL, 70
	.byte BEND, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte N04
	.byte An2, Cn3
	.byte W42
	.byte W01
	.byte W16
	.byte VOICE, 7
	.byte N05
	.byte Fn4, Gs3
	.byte W05
	.byte N09
	.byte Fn4, GsM1
	.byte W09
	.byte VOICE, 4
	.byte N12
	.byte Fn2, Gs5
	.byte W11
	.byte VOL, 23
	.byte W01
	.byte GnM2
	.byte W01
	.byte CnM2

	.byte FINE

track_589_1:
	.byte KEYSH, 0
	.byte W48
	.byte W02
	.byte VOICE, 21
	.byte VOL, 47
	.byte PAN, c_v
	.byte W10
	.byte N28
	.byte Cn3, Cn3
	.byte W22
	.byte VOL, 47
	.byte W01
	.byte Cs1
	.byte W01
	.byte En0
	.byte W01
	.byte FsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_589:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_589_0
	.word track_589_1

.align 2
