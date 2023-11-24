.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_84

track_84_0:
	.byte KEYSH, 0
track_84_lbl_22b946:
	.byte TEMPO, 28
	.byte VOICE, 102
	.byte PAN, c_v
	.byte PRIO, 120
	.byte VOL, 11
	.byte N92
	.byte Bn1, Cn8, DsM2
	.byte N92
	.byte Fn2, Cn8, DsM2
	.byte W03
	.byte VOL, 13
	.byte W03
	.byte EnM1
	.byte W03
	.byte FsM1
	.byte W03
	.byte AnM1
	.byte W03
	.byte BnM1
	.byte W03
	.byte Dn0
	.byte W03
	.byte Fn0
	.byte W03
	.byte Gs0
	.byte W36
	.byte W03
	.byte Fn0
	.byte W04
	.byte Ds0
	.byte W05
	.byte Cs0
	.byte W05
	.byte AsM1
	.byte W05
	.byte GsM1
	.byte W05
	.byte FnM1
	.byte W05
	.byte DsM1
	.byte W03
	.byte CsM1
	.byte W01
	.byte GOTO
		.word track_84_lbl_22b946

	.byte FINE

.align 2

track_84:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voice_group20
	.word track_84_0

.align 2
