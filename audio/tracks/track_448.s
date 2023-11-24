.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_448

track_448_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W07
	.byte BEND, c_v-47
	.byte N20
	.byte Cn3, En7
	.byte W01
	.byte BEND, c_v-42
	.byte W01
	.byte Ds0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte Bn1
	.byte W01
	.byte En2
	.byte W01
	.byte An2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Bn3
	.byte W01
	.byte En4
	.byte W01
	.byte An4
	.byte W01
	.byte Dn5
	.byte W01
	.byte Gn5
	.byte W01
	.byte Cn6
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+47
	.byte W01

	.byte FINE

.align 2

track_448:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word voice_group10
	.word track_448_0

.align 2
