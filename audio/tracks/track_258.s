.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_258

track_258_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 22
	.byte PAN, c_v
	.byte N06
	.byte Cn3, Cn4
	.byte W03
	.byte VOL, 14
	.byte W01
	.byte FsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_258:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_258_0

.align 2
