.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_700

track_700_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte N42
	.byte Cn3, En6
	.byte W42

	.byte FINE

.align 2

track_700:
	.byte 1
	.byte 0
	.byte 182
	.byte 0
	.word voice_group15
	.word track_700_0

.align 2
