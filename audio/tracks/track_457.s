.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_457

track_457_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Cn8
	.byte W02
	.byte VOICE, 7
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte En3, Gn8
	.byte W05
	.byte Dn3, Gs4
	.byte W05
	.byte VOICE, 8
	.byte N10
	.byte Cn3, Gs0
	.byte W10
	.byte VOICE, 6
	.byte N02
	.byte Cn3, GsM1
	.byte W02
	.byte VOICE, 7
	.byte N09
	.byte Dn3, En1
	.byte W09
	.byte VOICE, 8
	.byte N12
	.byte Cn3, GsM1
	.byte W36

	.byte FINE

track_457_1:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 6
	.byte VOL, 110
	.byte PAN, c_v
	.byte N02
	.byte Cn3, En2
	.byte W02
	.byte VOICE, 7
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Gs4
	.byte W13
	.byte VOICE, 8
	.byte N18
	.byte Cn3, En1
	.byte W36

	.byte FINE

track_457_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N10
	.byte Gn2, En7
	.byte W12
	.byte N05
	.byte Fn2, En6
	.byte W56
	.byte W01

	.byte FINE

.align 2

track_457:
	.byte 3
	.byte 0
	.byte 220
	.byte 0
	.word voice_group10
	.word track_457_0
	.word track_457_1
	.word track_457_2

.align 2
