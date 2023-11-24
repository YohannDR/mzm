.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_526

track_526_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 21
	.byte PAN, c_v
	.byte N02
	.byte Cn4, Gs4
	.byte W04
	.byte En4, En2
	.byte W02

	.byte FINE

track_526_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 17
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W04
	.byte Cn3, En1
	.byte W04
	.byte Cn3, GsM1
	.byte W02

	.byte FINE

.align 2

track_526:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_526_0
	.word track_526_1

.align 2
