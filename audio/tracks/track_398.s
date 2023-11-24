.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_398

track_398_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 70
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte N12
	.byte Cn3, Gs0
	.byte W08
	.byte VOL, 70
	.byte W01
	.byte Cs1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_398:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_398_0

.align 2
