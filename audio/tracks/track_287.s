.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_287

track_287_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 81
	.byte PAN, c_v+16
	.byte N03
	.byte An2, En1
	.byte W03
	.byte Cn3, Cn3
	.byte W03
	.byte N04
	.byte Bn2, Gs4
	.byte W04
	.byte An2, En6
	.byte W04
	.byte N05
	.byte Gn2, Gn8
	.byte W05
	.byte Fn2, En6
	.byte W05
	.byte N06
	.byte Dn2, Gs4
	.byte W06
	.byte Cn2, Cn4
	.byte W06
	.byte N08
	.byte An1, Cn3
	.byte W36

	.byte FINE

track_287_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 10
	.byte VOL, 115
	.byte PAN, c_v+16
	.byte N13
	.byte Cn3, Gn8
	.byte W13
	.byte Cn3, Cn3
	.byte W13
	.byte N19
	.byte Cn3, Gs0
	.byte W32
	.byte W02

	.byte FINE

track_287_2:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 72
	.byte PAN, c_v+16
	.byte N11
	.byte Cn3, En7
	.byte W02
	.byte VOL, 76
	.byte W02
	.byte An4
	.byte W02
	.byte Dn5
	.byte W02
	.byte AnM2
	.byte W02
	.byte Gn7
	.byte W01
	.byte N04
	.byte Cn3, Gs4
	.byte W06
	.byte VOICE, 12
	.byte VOL, 108
	.byte N03
	.byte En3, Cn8
	.byte W05
	.byte N10
	.byte Cn3
	.byte W11
	.byte N19
	.byte Cn3, En1
	.byte W36
	.byte W03

	.byte FINE

track_287_3:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 115
	.byte PAN, c_v+16
	.byte W04
	.byte N02
	.byte An2, Cn8
	.byte W03
	.byte N04
	.byte Bn2
	.byte W04
	.byte N15
	.byte Fn2, Gn8
	.byte W60
	.byte W01

	.byte FINE

.align 2

track_287:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_287_0
	.word track_287_1
	.word track_287_2
	.word track_287_3

.align 2
