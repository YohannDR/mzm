.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_110

track_110_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 35
	.byte PAN, c_v
	.byte N01
	.byte Cn5, Gn8
	.byte W01
	.byte As4
	.byte W01

	.byte FINE

.align 2

track_110:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_110_0

.align 2
