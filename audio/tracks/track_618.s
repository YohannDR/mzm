.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_618

track_618_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N19
	.byte Cn1, Gs4
	.byte W05
	.byte BEND, c_v
	.byte W11
	.byte VOL, 11
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_618:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_618_0

.align 2
