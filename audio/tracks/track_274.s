.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_274

track_274_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 5
	.byte VOL, 27
	.byte PAN, c_v
	.byte N16
	.byte Fs2, Gs4
	.byte W10
	.byte VOL, 27
	.byte W01
	.byte FnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_274:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_274_0

.align 2
