.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_275

track_275_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte PAN, c_v
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte N16
	.byte Fs2, Gs4
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte DsM1
	.byte W01
	.byte BnM1
	.byte W10
	.byte AnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_275:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_275_0

.align 2
