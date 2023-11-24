.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_350

track_350_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte MOD, 45
	.byte VOL, 37
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N32
	.byte An3, Gs4
	.byte W02
	.byte VOL, 25
	.byte W02
	.byte GsM1
	.byte W01
	.byte FsM1
	.byte W02
	.byte Ds0
	.byte W02
	.byte Fs1
	.byte W02
	.byte An0
	.byte W02
	.byte GsM2
	.byte W02
	.byte FsM2
	.byte W02
	.byte AnM2
	.byte W02
	.byte GnM1
	.byte W02
	.byte Fn0
	.byte W02
	.byte Ds0
	.byte W01
	.byte Cn0
	.byte W02
	.byte DnM1
	.byte W02
	.byte GnM2
	.byte W02
	.byte DnM2
	.byte W02

	.byte FINE

.align 2

track_350:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_350_0

.align 2
