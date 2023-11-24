.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_196

track_196_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Cn8
	.byte W02
	.byte VOICE, 14
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte En3, Gn8
	.byte W05
	.byte Dn3, Gs4
	.byte W05
	.byte VOICE, 12
	.byte N18
	.byte Cn3, Gs0
	.byte W18
	.byte VOICE, 11
	.byte N02
	.byte Cn3, Cn8
	.byte W02
	.byte VOICE, 14
	.byte N13
	.byte Dn3, Gs4
	.byte W13
	.byte VOICE, 12
	.byte N18
	.byte Cn3, En1
	.byte W18
	.byte VOICE, 11
	.byte N02
	.byte Cn3, En6
	.byte W02
	.byte VOICE, 14
	.byte N13
	.byte Dn3
	.byte W13
	.byte VOICE, 12
	.byte N18
	.byte Cn3, Cn3
	.byte W13
	.byte W32
	.byte W02

	.byte FINE

track_196_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W02
	.byte VOICE, 14
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Gs4
	.byte W13
	.byte VOICE, 12
	.byte N18
	.byte Cn3, En6
	.byte W18
	.byte VOICE, 11
	.byte VOL, 86
	.byte PAN, c_v
	.byte N02
	.byte Cn3, Gs4
	.byte W02
	.byte VOICE, 14
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Gs4
	.byte W13
	.byte VOICE, 12
	.byte N18
	.byte Cn3, En1
	.byte W02
	.byte W32
	.byte W02

	.byte FINE

track_196_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 33
	.byte N05
	.byte An2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W12
	.byte N05
	.byte Gn2, En6
	.byte W08
	.byte N04
	.byte Fn2
	.byte W21
	.byte N05
	.byte An2, Gs4
	.byte W05
	.byte Gs2, En7
	.byte W05
	.byte Gn2, En6
	.byte W07
	.byte Fn2, Cn8
	.byte W32
	.byte W01
	.byte W32
	.byte W02

	.byte FINE

track_196_3:
	.byte KEYSH, 0
	.byte W03
	.byte VOICE, 23
	.byte VOL, 78
	.byte PAN, c_v
	.byte N22
	.byte Cn3, Cn6
	.byte W19
	.byte VOL, 28
	.byte W01
	.byte BnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Dn3
	.byte N16
	.byte Bn2, En6
	.byte W13
	.byte VOL, 28
	.byte W01
	.byte BnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte Bn1
	.byte N20
	.byte An2, Gs4
	.byte W17
	.byte VOL, 28
	.byte W01
	.byte BnM2
	.byte W01
	.byte CnM2
	.byte W03
	.byte Dn3
	.byte N15
	.byte Bn2, Cn4
	.byte W12
	.byte VOL, 28
	.byte W01
	.byte BnM2
	.byte W01
	.byte CnM2
	.byte W19
	.byte W32
	.byte W02

	.byte FINE

.align 2

track_196:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group5
	.word track_196_0
	.word track_196_1
	.word track_196_2
	.word track_196_3

.align 2
