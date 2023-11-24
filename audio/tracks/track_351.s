.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_351

track_351_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 39
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+32
	.byte W04
	.byte N12
	.byte Gn2, Gs4
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte Ds4
	.byte W01
	.byte En3
	.byte W01
	.byte Fs2
	.byte W01
	.byte Gn1
	.byte W01
	.byte An0
	.byte W01
	.byte AsM1
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_351:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_351_0

.align 2
