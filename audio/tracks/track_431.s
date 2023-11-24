.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_431

track_431_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16
	.byte Gn3, En6
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte BnM2
	.byte W01
	.byte FnM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Ds0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Dn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Bn2
	.byte W01
	.byte En3
	.byte W04

	.byte FINE

.align 2

track_431:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_431_0

.align 2
