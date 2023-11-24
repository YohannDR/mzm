.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_135

track_135_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 48
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v
	.byte N09
	.byte Cn3, Gs4
	.byte W09
	.byte Cn3, Gs0
	.byte W01
	.byte BEND, c_v-1
	.byte W03
	.byte Bn2
	.byte W03
	.byte Gs2
	.byte W02
	.byte N09
	.byte Cn3, EnM1
	.byte W09

	.byte FINE

.align 2

track_135:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group1
	.word track_135_0

.align 2
