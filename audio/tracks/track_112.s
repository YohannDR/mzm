.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_112

track_112_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 52
	.byte PAN, c_v
	.byte N12
	.byte Cn3, Gs4
	.byte W03
	.byte VOL, 38
	.byte W01
	.byte En0
	.byte W01
	.byte GsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CsM2
	.byte W01

	.byte FINE

.align 2

track_112:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_112_0

.align 2
