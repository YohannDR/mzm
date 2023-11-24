.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_273

track_273_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 30
	.byte PAN, c_v
	.byte N09
	.byte Bn4, Gs4
	.byte W17
	.byte Bn4, Cn3
	.byte W17
	.byte Bn4, En1
	.byte W16
	.byte Bn4, GsM1
	.byte W17
	.byte Bn4, GsM2
	.byte W09

	.byte FINE

.align 2

track_273:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group16
	.word track_273_0

.align 2
