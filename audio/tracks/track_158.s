.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_158

track_158_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 49
	.byte VOL, 34
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v
	.byte N12
	.byte Fn1, Gs4
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte Ds4
	.byte W01
	.byte An4
	.byte W01
	.byte Ds5
	.byte W01
	.byte An5
	.byte W01
	.byte Dn6
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01

	.byte FINE

.align 2

track_158:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group1
	.word track_158_0

.align 2
