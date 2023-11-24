.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_348

track_348_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 23
	.byte PAN, c_v
	.byte W08
	.byte N06
	.byte An1, En6
	.byte W06
	.byte N03
	.byte En2, Gs4
	.byte W03
	.byte Dn2, Cn3
	.byte W10
	.byte Fn2
	.byte W03
	.byte As2
	.byte W03

	.byte FINE

.align 2

track_348:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_348_0

.align 2
