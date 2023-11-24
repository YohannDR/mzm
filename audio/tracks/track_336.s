.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_336

track_336_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v-63
	.byte N12
	.byte Cn3, Cn3
	.byte W02
	.byte BEND, c_v-61
	.byte W01
	.byte FnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte DsM1
	.byte W01
	.byte Gn0
	.byte W01
	.byte An1
	.byte W01
	.byte Fn2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Cs3
	.byte W01
	.byte En3

	.byte FINE

.align 2

track_336:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_336_0

.align 2
