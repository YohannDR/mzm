.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_286

track_286_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 69
	.byte PAN, c_v+16
	.byte N04
	.byte An2, En1
	.byte W04
	.byte N03
	.byte Cn3, Cn3
	.byte W03
	.byte Bn2, Gs4
	.byte W03
	.byte N04
	.byte An2, En6
	.byte W04
	.byte Gn2, Cn8
	.byte W04
	.byte Fn2, Gs4
	.byte W04
	.byte N05
	.byte Dn2, Cn3
	.byte W05
	.byte N06
	.byte Cn2
	.byte W06
	.byte N08
	.byte An1
	.byte W36
	.byte W03

	.byte FINE

track_286_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 69
	.byte PAN, c_v+16
	.byte N11
	.byte Cn3, En7
	.byte W02
	.byte VOL, 77
	.byte W02
	.byte Dn5
	.byte W02
	.byte Bn5
	.byte W02
	.byte Gn6
	.byte W02
	.byte Dn7
	.byte W01
	.byte VOICE, 10
	.byte N13
	.byte Cn3, Gn8
	.byte W13
	.byte Cn3, Cn3
	.byte W13
	.byte N19
	.byte Cn3, Gs0
	.byte W32
	.byte W03

	.byte FINE

track_286_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 103
	.byte PAN, c_v+16
	.byte W02
	.byte N02
	.byte An2, En6
	.byte W02
	.byte N04
	.byte Bn2
	.byte W04
	.byte N15
	.byte Fn2, Gn8
	.byte W04
	.byte VOL, 110
	.byte W60

	.byte FINE

.align 2

track_286:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_286_0
	.word track_286_1
	.word track_286_2

.align 2
