.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_495

track_495_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 105
	.byte PAN, c_v-20
	.byte N05
	.byte Cn3, Cn8
	.byte W05
	.byte N14
	.byte En3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Cn3
	.byte W28
	.byte W01
	.byte N05
	.byte Dn3, Cn8
	.byte W05
	.byte N14
	.byte Cn3, Gn8
	.byte W14
	.byte N13
	.byte En3, Gs5
	.byte W28
	.byte W01
	.byte N05
	.byte En3, Cn8
	.byte W05
	.byte N14
	.byte Cn3, Gn8
	.byte W14
	.byte N13
	.byte Dn3, Gs4
	.byte W13

	.byte FINE

track_495_1:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 12
	.byte VOL, 105
	.byte PAN, c_v-20
	.byte N03
	.byte Bn2, Cn8
	.byte W03
	.byte VOICE, 15
	.byte N06
	.byte Gn2, Gn8
	.byte W06
	.byte N21
	.byte Cn3, Gs5
	.byte W36
	.byte W03
	.byte VOICE, 12
	.byte N03
	.byte Bn2, En7
	.byte W03
	.byte VOICE, 14
	.byte N07
	.byte An2
	.byte W07
	.byte N21
	.byte Bn2, Gs5
	.byte W14
	.byte W24
	.byte VOICE, 12
	.byte N03
	.byte Bn2, En7
	.byte W03
	.byte VOICE, 15
	.byte N07
	.byte An2, Gn8
	.byte W07
	.byte N20
	.byte Cn3, En7
	.byte W20

	.byte FINE

track_495_2:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 16
	.byte MOD, 0
	.byte VOL, 105
	.byte LFOS, 0
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W42
	.byte W01
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W36
	.byte W03
	.byte W04
	.byte N05
	.byte Gs2, Gs4
	.byte W05
	.byte N10
	.byte Gs2, En7
	.byte W24
	.byte W01
	.byte Gs2, Gs4
	.byte W10

	.byte FINE

track_495_3:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 105
	.byte PAN, c_v
	.byte PRIO, 1
	.byte BEND, c_v
	.byte W10
	.byte N56
	.byte Cn3, Cn8, DnM2
	.byte W14
	.byte MOD, 30
	.byte LFOS, 100
	.byte MODT, mod_tre
	.byte W72
	.byte MOD, 0
	.byte LFOS, 0
	.byte W07
	.byte N44
	.byte Fn3, Gn8
	.byte W44
	.byte Fn3, En2
	.byte W44
	.byte Fn3, En0
	.byte W01
	.byte W42
	.byte W01

	.byte FINE

.align 2

track_495:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word voice_group13
	.word track_495_0
	.word track_495_1
	.word track_495_2
	.word track_495_3

.align 2
