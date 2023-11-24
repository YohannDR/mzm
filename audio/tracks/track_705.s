.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_705

track_705_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 89
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs5
	.byte W03
	.byte VOICE, 19
	.byte N21
	.byte W44
	.byte W01

	.byte FINE

track_705_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte N04
	.byte Fn2, En7
	.byte W44
	.byte W02

	.byte FINE

.align 2

track_705:
	.byte 2
	.byte 0
	.byte 171
	.byte 0
	.word voice_group5
	.word track_705_0
	.word track_705_1

.align 2
