.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_382

track_382_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 40
	.byte PAN, c_v
	.byte N13
	.byte Fn1, Cn4
	.byte W06
	.byte VOL, 40
	.byte W01
	.byte Cn0
	.byte W01
	.byte CsM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W12

	.byte FINE

track_382_1:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05
	.byte Bn2, Gs4
	.byte W24

	.byte FINE

.align 2

track_382:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_382_0
	.word track_382_1

.align 2
