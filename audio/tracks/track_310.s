.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_310

track_310_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte MOD, 20
	.byte VOL, 66
	.byte PAN, c_v
	.byte LFOS, 100
	.byte TIE
	.byte Cn3, Gs4
	.byte W01
track_310_lbl_2104ce:
	.byte W92
	.byte W03
	.byte GOTO
		.word track_310_lbl_2104ce
	.byte W01
	.byte EOT, Cn3

	.byte FINE

.align 2

track_310:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group5
	.word track_310_0

.align 2
