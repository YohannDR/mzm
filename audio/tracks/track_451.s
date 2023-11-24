.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_451

track_451_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte W10
	.byte PAN, c_v-20
	.byte W10
	.byte VOL, 70
	.byte W06
	.byte N08
	.byte An2, En6
	.byte W08
	.byte An2, Gs0
	.byte W08
	.byte An2, GsM2
	.byte W08

	.byte FINE

.align 2

track_451:
	.byte 1
	.byte 0
	.byte 201
	.byte 0
	.word voice_group10
	.word track_451_0

.align 2
