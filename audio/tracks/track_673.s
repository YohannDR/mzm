.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_673

track_673_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 70
	.byte PAN, c_v
	.byte N12
	.byte Cn3, En6
	.byte W12

	.byte FINE

.align 2

track_673:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_673_0

.align 2
