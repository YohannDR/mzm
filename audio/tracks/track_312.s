.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_312

track_312_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Cn6
	.byte W03
	.byte VOICE, 20
	.byte N08
	.byte Cn3, En6
	.byte W08
	.byte An2
	.byte W08
	.byte VOICE, 19
	.byte N15
	.byte Cn3, Gs5
	.byte W08
	.byte VOL, 62
	.byte W01
	.byte Bn1
	.byte W01
	.byte Gn0
	.byte W01
	.byte DsM1
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W32
	.byte W03

	.byte FINE

track_312_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02
	.byte An4, Gs4
	.byte W03
	.byte N05
	.byte An2, En7
	.byte W07
	.byte Fn2, En6
	.byte W56
	.byte W02

	.byte FINE

.align 2

track_312:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_312_0
	.word track_312_1

.align 2
