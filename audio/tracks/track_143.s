.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_143

track_143_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 59
	.byte PAN, c_v
	.byte N60
	.byte Cn3, Cn3
	.byte W60
	.byte VOICE, 17
	.byte VOL, 74
	.byte TIE
	.byte Cn3, En6
	.byte W01
track_143_lbl_20bd26:
	.byte W32
	.byte W03
	.byte W60
	.byte GOTO
		.word track_143_lbl_20bd26
	.byte W01
	.byte EOT, Cn3

	.byte FINE

.align 2

track_143:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_143_0

.align 2
