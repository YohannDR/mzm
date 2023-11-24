.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_381

track_381_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 35
	.byte PAN, c_v
	.byte N02
	.byte An2, En6
	.byte W02
	.byte VOICE, 8
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N12
	.byte Fn1
	.byte W01
	.byte BEND, c_v-35
	.byte W01
	.byte En1
	.byte W01
	.byte En2
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte FnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_381:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_381_0

.align 2
