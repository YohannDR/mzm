.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_246

track_246_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18
	.byte Cn3, En2
	.byte W03
	.byte MOD, 60
	.byte VOL, 41
	.byte LFOS, 120
	.byte MODT, mod_tre
	.byte W15

	.byte FINE

track_246_1:
	.byte KEYSH, 0
	.byte VOICE, 29
	.byte VOL, 75
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte VOICE, 24
	.byte VOL, 21
	.byte N07
	.byte Cn3, Gs5
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte Dn1
	.byte W01
	.byte As1
	.byte W01
	.byte Fs2
	.byte W03
	.byte N07
	.byte Bn2, En2
	.byte W07
	.byte N05
	.byte An2, GsM1
	.byte W05

	.byte FINE

.align 2

track_246:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_246_0
	.word track_246_1

.align 2
