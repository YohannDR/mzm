.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_333

track_333_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 39
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N05
	.byte Fn2, Gs4
	.byte W05
	.byte N15
	.byte Cn3, Cn3
	.byte W06
	.byte BEND, c_v-8
	.byte W05
	.byte VOL, 19
	.byte BEND, c_v-24
	.byte W02
	.byte VOL, 9
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_333:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_333_0

.align 2
