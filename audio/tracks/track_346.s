.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_346

track_346_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-32
	.byte N24
	.byte Fn2, Gs4
	.byte W02
	.byte BEND, c_v-21
	.byte W02
	.byte Fn2
	.byte W02
	.byte En3
	.byte W02
	.byte VOL, 42
	.byte W02
	.byte En0
	.byte W02
	.byte FsM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GsM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_346:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_346_0

.align 2
