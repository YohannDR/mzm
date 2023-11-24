.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_180

track_180_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 31
	.byte PAN, c_v-34
	.byte N16
	.byte Cn3, En6
	.byte W16

	.byte FINE

.align 2

track_180:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group11
	.word track_180_0

.align 2
