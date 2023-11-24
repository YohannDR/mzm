.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_704

track_704_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, DnM2
	.byte W76
	.byte W01

	.byte FINE

track_704_1:
	.byte KEYSH, 0
	.byte W06
	.byte VOICE, 14
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N15
	.byte Cn3, Gn8
	.byte W15
	.byte N24
	.byte An2, Gn8, CsM2
	.byte W20
	.byte VOL, 120
	.byte W01
	.byte Bn5
	.byte W01
	.byte Gn4
	.byte W01
	.byte Fn3
	.byte W01
	.byte Fs2
	.byte W01
	.byte Gs1
	.byte W01
	.byte Cn1
	.byte W01
	.byte Gn0
	.byte W01
	.byte Cs0
	.byte W01
	.byte GsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W36

	.byte FINE

track_704_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte N02
	.byte Cn3, Gn8
	.byte W02
	.byte VOICE, 20
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, En2
	.byte W13
	.byte VOICE, 19
	.byte VOL, 75
	.byte W02
	.byte VOICE, 20
	.byte VOL, 120
	.byte N05
	.byte Cn3, En6
	.byte W01
	.byte VOL, 95
	.byte W01
	.byte Gn4
	.byte W01
	.byte Fn3
	.byte W01
	.byte Fs2
	.byte W01
	.byte Gs1
	.byte N14
	.byte En3, Gn8
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte Gn0
	.byte W01
	.byte Cs0
	.byte W01
	.byte GsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W40
	.byte W01

	.byte FINE

track_704_3:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte PRIO, 25
	.byte N02
	.byte An4, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N02
	.byte An2, En7
	.byte W13
	.byte VOICE, 18
	.byte N02
	.byte Gn2, Gs4
	.byte W02
	.byte VOICE, 17
	.byte N09
	.byte Gn2, Cn8
	.byte W09
	.byte VOL, 120
	.byte PAN, c_v+6
	.byte PRIO, 25
	.byte W02
	.byte VOICE, 17
	.byte N02
	.byte Gn2, En7
	.byte W64

	.byte FINE

.align 2

track_704:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group13
	.word track_704_0
	.word track_704_1
	.word track_704_2
	.word track_704_3

.align 2
