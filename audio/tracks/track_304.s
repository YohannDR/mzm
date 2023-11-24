.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_304

track_304_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 70
	.byte PAN, c_v
	.byte N09
	.byte An2, Cn7
	.byte W09
	.byte N13
	.byte Cn3, Cn2
	.byte W13
	.byte VOICE, 1
	.byte VOL, 77
	.byte N05
	.byte Gn2, Gs3
	.byte W30
	.byte W01

	.byte FINE

track_304_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 85
	.byte PAN, c_v
	.byte N05
	.byte Cn3, En5
	.byte W05
	.byte VOICE, 23
	.byte VOL, 70
	.byte N22
	.byte Cn3, Gs3
	.byte W19
	.byte VOL, 25
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2
	.byte W24
	.byte W03

	.byte FINE

.align 2

track_304:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_304_0
	.word track_304_1

.align 2
