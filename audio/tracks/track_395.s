.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_395

track_395_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 0
	.byte PAN, c_v
	.byte W04
	.byte N06
	.byte Cn4, Cn3
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte Fn0
	.byte W01
	.byte As0
	.byte W01
	.byte Dn0
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte N07
	.byte An3
	.byte W02
	.byte VOL, 12
	.byte W01
	.byte AsM1
	.byte W01
	.byte Ds0
	.byte W03

	.byte FINE

.align 2

track_395:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_395_0

.align 2
