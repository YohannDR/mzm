.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_391

track_391_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 34
	.byte PAN, c_v
	.byte N01
	.byte An2, Cn4
	.byte W01
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N09
	.byte Bn1
	.byte W01
	.byte BEND, c_v-35
	.byte W01
	.byte En1
	.byte W01
	.byte En2
	.byte W01
	.byte En3
	.byte W02
	.byte VOL, 14
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_391:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_391_0

.align 2
