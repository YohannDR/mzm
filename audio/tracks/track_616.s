.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_616

track_616_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 0
	.byte MOD, 60
	.byte VOL, 35
	.byte PAN, c_v
	.byte LFOS, 70
	.byte W05
	.byte N36
	.byte Fn3, Gs4
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte En0
	.byte W01
	.byte Cs0
	.byte W01
	.byte Cs0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn0
	.byte W01
	.byte An0
	.byte W01
	.byte Dn1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Gs1
	.byte W01
	.byte An1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Dn1
	.byte W01
	.byte An0
	.byte W01
	.byte Ds0
	.byte W01
	.byte BnM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W10

	.byte FINE

.align 2

track_616:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_616_0

.align 2
