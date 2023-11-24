.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_605

track_605_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 67
	.byte PAN, c_v
	.byte N03
	.byte An2, Gs5
	.byte W03
	.byte VOICE, 19
	.byte N21
	.byte Bn2
	.byte W44
	.byte W01

	.byte FINE

track_605_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte N03
	.byte Fn2, En7
	.byte W44
	.byte W02

	.byte FINE

.align 2

track_605:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group5
	.word track_605_0
	.word track_605_1

.align 2
