.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_354

track_354_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 20
	.byte VOL, 9
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 110
	.byte BEND, c_v
	.byte N96
	.byte En3, Cn3
	.byte W01
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+21
	.byte W01
	.byte Bn5
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+42
	.byte W01
	.byte Gs7
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 20
	.byte W02
	.byte Fn0
	.byte W84
	.byte W02

	.byte FINE

.align 2

track_354:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_354_0

.align 2
