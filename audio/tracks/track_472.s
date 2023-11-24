.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_472

track_472_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 62
	.byte PAN, c_v
	.byte TIE
	.byte Cn3, En3
	.byte W32
	.byte W02
	.byte MOD, 20
	.byte LFOS, 120
	.byte MODT, mod_tre
	.byte W01
track_472_lbl_2153e2:
	.byte W60
	.byte W01
	.byte GOTO
		.word track_472_lbl_2153e2
	.byte W01
	.byte EOT, Cn3

	.byte FINE

.align 2

track_472:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voice_group12
	.word track_472_0

.align 2
