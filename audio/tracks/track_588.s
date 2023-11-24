.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_588

track_588_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N64
	.byte Cn3, Gn8, CsM2
	.byte W66
	.byte Cn3, EnM1, CsM2
	.byte W30
	.byte W24
	.byte VOL, 90
	.byte W01
	.byte Gn2
	.byte W01
	.byte Dn1
	.byte W01
	.byte Ds0
	.byte W01
	.byte GsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

track_588_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 90
	.byte PAN, c_v
	.byte W36
	.byte N64
	.byte Cn3, Cn1, CsM2
	.byte W60
	.byte W05

	.byte FINE

.align 2

track_588:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word voice_group13
	.word track_588_0
	.word track_588_1

.align 2
