.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_690

track_690_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N32
	.byte Cn3, En6, DnM2
	.byte W32
	.byte W02

	.byte FINE

.align 2

track_690:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_690_0

.align 2
