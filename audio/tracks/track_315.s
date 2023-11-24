.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_315

track_315_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N10
	.byte Cn3, Gs4
	.byte W10
	.byte N19
	.byte En3, En1
	.byte W19

	.byte FINE

track_315_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 26
	.byte BEND, c_v-32
	.byte N13
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-30
	.byte W01
	.byte Cn1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Fs1
	.byte W01
	.byte An1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fs6
	.byte W01
	.byte Gn8
	.byte W02
	.byte N05
	.byte Cn3, Cn3
	.byte W06
	.byte Cn3, Gs0
	.byte W06
	.byte Cn3, CnM1
	.byte W05

	.byte FINE

.align 2

track_315:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_315_0
	.word track_315_1

.align 2
