.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_164

track_164_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 100
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gn8
	.byte W02
	.byte VOICE, 14
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, En2
	.byte W13
	.byte VOICE, 12
	.byte N18
	.byte Cn3, GsM1
	.byte W20

	.byte FINE

track_164_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 54
	.byte W04
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W44
	.byte W01

	.byte FINE

.align 2

track_164:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group5
	.word track_164_0
	.word track_164_1

.align 2
