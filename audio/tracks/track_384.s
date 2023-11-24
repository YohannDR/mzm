.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_384

track_384_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 74
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W03
	.byte N04
	.byte Gn2, En6
	.byte W04
	.byte VOICE, 42
	.byte BENDR, 24
	.byte N12
	.byte Bn2, Gs4
	.byte W01
	.byte BEND, c_v-11
	.byte W01
	.byte Gn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte AnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W01

	.byte FINE

.align 2

track_384:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_384_0

.align 2
