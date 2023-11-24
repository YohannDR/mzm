.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_303

track_303_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Cn6
	.byte W03
	.byte VOICE, 20
	.byte N22
	.byte W56
	.byte W01

	.byte FINE

track_303_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02
	.byte An4, Gs4
	.byte W02
	.byte VOICE, 2
	.byte N02
	.byte An2, En7
	.byte W56
	.byte W02

	.byte FINE

.align 2

track_303:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_303_0
	.word track_303_1

.align 2
