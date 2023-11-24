.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_233

track_233_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28
	.byte Cn3, Gs4, CsM2
	.byte W03
	.byte MOD, 25
	.byte LFOS, 110
	.byte MODT, mod_tre
	.byte W21
	.byte MOD, 0
	.byte W05

	.byte FINE

track_233_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N05
	.byte Fn2, En2
	.byte W01
	.byte BEND, c_v+47
	.byte W01
	.byte Cn6
	.byte W01
	.byte Gs4
	.byte W01
	.byte En3
	.byte W01
	.byte VOICE, 24
	.byte VOL, 49
	.byte N09
	.byte Bn2, Gs4
	.byte W09
	.byte An2, GsM1
	.byte W09
	.byte Gn2, GsM2
	.byte W09

	.byte FINE

.align 2

track_233:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_233_0
	.word track_233_1

.align 2
