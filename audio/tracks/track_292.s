.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_292

track_292_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 37
	.byte PAN, c_v-4
	.byte N02
	.byte Cn4, En1
	.byte W02
	.byte Bn3
	.byte W22
	.byte VOICE, 4
	.byte N24
	.byte As3
	.byte W40
	.byte As2, Cn3, DnM2
	.byte W24
	.byte W02
	.byte VOICE, 7
	.byte VOL, 44
	.byte N04
	.byte Cn4, En1
	.byte W04
	.byte Cn4, GsM1
	.byte W02
	.byte W02
	.byte VOICE, 4
	.byte N19
	.byte En2, Cn3
	.byte W19

	.byte FINE

track_292_1:
	.byte KEYSH, 0
	.byte W90
	.byte VOICE, 7
	.byte VOL, 44
	.byte PAN, c_v-4
	.byte W06
	.byte W14
	.byte N04
	.byte Cn4, Cn3
	.byte W04
	.byte Cn4, GsM1
	.byte W04

	.byte FINE

track_292_2:
	.byte KEYSH, 0
	.byte W92
	.byte VOICE, 24
	.byte PAN, c_v
	.byte BENDR, 4
	.byte VOL, 37
	.byte N36
	.byte Cn4, Gs0
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-1
	.byte W01
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-21
	.byte W03
	.byte VOL, 20
	.byte BEND, c_v-34
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-52
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-57
	.byte W03
	.byte VOL, 8
	.byte BEND, c_v-62
	.byte W03
	.byte VOL, 5
	.byte W03
	.byte EnM2
	.byte W03
	.byte DnM2
	.byte W03
	.byte CsM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_292:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_292_0
	.word track_292_1
	.word track_292_2

.align 2
