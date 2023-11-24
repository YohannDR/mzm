.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_685

track_685_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 20
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 120
	.byte MODT, mod_tre
	.byte N60
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W22
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_685:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.word voice_group12
	.word track_685_0

.align 2
