.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_243

track_243_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28
	.byte Cn3, En4
	.byte W21
	.byte VOL, 56
	.byte W01
	.byte Bn1
	.byte W01
	.byte En1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Gn0
	.byte W01
	.byte Fs0
	.byte W02

	.byte FINE

track_243_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 49
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte W01
	.byte N07
	.byte Fn2, En2
	.byte W01
	.byte BEND, c_v+52
	.byte W01
	.byte An6
	.byte W01
	.byte Bn5
	.byte W01
	.byte Cn5
	.byte W01
	.byte Dn4
	.byte W01
	.byte En3
	.byte W01
	.byte VOICE, 24
	.byte VOL, 67
	.byte N09
	.byte Bn2, Gs4
	.byte W09
	.byte An2, GsM1
	.byte W09
	.byte Gn2, CnM1
	.byte W09

	.byte FINE

.align 2

track_243:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_243_0
	.word track_243_1

.align 2
