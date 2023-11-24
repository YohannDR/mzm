.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_132

track_132_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 82
	.byte PAN, c_v
	.byte N03
	.byte Cn3, En6
	.byte W03
	.byte N04
	.byte Cn3, En1
	.byte W04

	.byte FINE

.align 2

track_132:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_132_0

.align 2
