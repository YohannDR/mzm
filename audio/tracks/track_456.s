.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_456

track_456_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v-20
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte VOICE, 13
	.byte N12
	.byte Cn2, Gs5
	.byte W04
	.byte VOL, 70
	.byte W01
	.byte Bn1
	.byte W01
	.byte Gs0
	.byte W01
	.byte AnM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W24

	.byte FINE

track_456_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 56
	.byte PAN, c_v-20
	.byte PRIO, 72
	.byte W10
	.byte N06
	.byte An4, Gs4
	.byte W28
	.byte W01

	.byte FINE

.align 2

track_456:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_456_0
	.word track_456_1

.align 2
