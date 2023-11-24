.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_683

track_683_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 70
	.byte PAN, c_v+6
	.byte N12
	.byte Cn3, En6
	.byte W12

	.byte FINE

.align 2

track_683:
	.byte 1
	.byte 0
	.byte 179
	.byte 0
	.word voice_group14
	.word track_683_0

.align 2
