.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_544

track_544_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 46
	.byte PAN, c_v
	.byte N18
	.byte Cn3, Gs4
	.byte W18

	.byte FINE

track_544_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 70
	.byte PAN, c_v
	.byte N04
	.byte Fn3, Gs4
	.byte W05
	.byte Dn3
	.byte W05
	.byte Bn2
	.byte W06
	.byte Bn2, Gs0
	.byte W06
	.byte Bn2, CnM1
	.byte W04
	.byte Gn3, Gs0
	.byte W04
	.byte Fn3, CnM1
	.byte W04
	.byte En3, GsM2
	.byte W04

	.byte FINE

.align 2

track_544:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_544_0
	.word track_544_1

.align 2
