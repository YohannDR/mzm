.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_340

track_340_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 37
	.byte PAN, c_v
	.byte W04
	.byte N04
	.byte An2, Gn8
	.byte W04
	.byte En3, En6
	.byte W04
	.byte N15
	.byte Cn3
	.byte W03
	.byte VOL, 20
	.byte W03
	.byte BnM2
	.byte W03
	.byte FnM2
	.byte W03
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_340:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_340_0

.align 2
