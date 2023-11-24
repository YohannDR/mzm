.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_378

track_378_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 38
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 4
	.byte LFOS, 100
	.byte BEND, c_v+63
	.byte N16
	.byte Cn3, Cn3
	.byte W16

	.byte FINE

.align 2

track_378:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_378_0

.align 2
