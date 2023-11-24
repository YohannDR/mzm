.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_675

track_675_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 70
	.byte PAN, c_v+6
	.byte N15
	.byte Cn3, En6
	.byte W13
	.byte VOL, 35
	.byte W01
	.byte FnM1
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_675:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_675_0

.align 2
