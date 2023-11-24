.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_542

track_542_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte MOD, 24
	.byte VOL, 33
	.byte PAN, c_v
	.byte LFOS, 127
	.byte TIE
	.byte Cn4, Cn3
	.byte W01
track_542_lbl_20f41e:
	.byte W92
	.byte W03
	.byte GOTO
		.word track_542_lbl_20f41e
	.byte W01
	.byte EOT, Cn4

	.byte FINE

.align 2

track_542:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_542_0

.align 2
