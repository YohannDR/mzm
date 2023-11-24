.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_308

track_308_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 74
	.byte PAN, c_v
	.byte N03
	.byte Bn2, Gs5
	.byte W03
	.byte VOICE, 19
	.byte N06
	.byte W06
	.byte N21
	.byte Cn3, Cn4
	.byte W48
	.byte W03

	.byte FINE

track_308_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte MOD, 80
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N12
	.byte Cn4, En1
	.byte W07
	.byte VOL, 62
	.byte W01
	.byte Cs1
	.byte W01
	.byte AsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte GnM2
	.byte W01
	.byte VOICE, 0
	.byte MOD, 0
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N04
	.byte Gn2, Gs4
	.byte W48

	.byte FINE

.align 2

track_308:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_308_0
	.word track_308_1

.align 2
