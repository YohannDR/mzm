.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_10

track_10_0:
	.byte KEYSH, 0
track_10_lbl_22e99e:
	.byte TEMPO, 49
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 28
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 97
	.byte PAN, c_v+15
	.byte TIE
	.byte En2, En1
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE
	.byte Cn2
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte GOTO
		.word track_10_lbl_22e99e

	.byte FINE

track_10_1:
	.byte KEYSH, 0
track_10_lbl_22e9cb:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v-17
	.byte PRIO, 27
	.byte N96
	.byte Cn2, Gn8
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_10_lbl_22e9cb

	.byte FINE

track_10_2:
	.byte KEYSH, 0
track_10_lbl_22e9f2:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v+15
	.byte PRIO, 29
	.byte W96
	.byte N96
	.byte Cn2, Gn8
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte W96
	.byte N96
	.byte W96
	.byte GOTO
		.word track_10_lbl_22e9f2

	.byte FINE

track_10_3:
	.byte KEYSH, 0
track_10_lbl_22ea19:
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 120
	.byte W96
	.byte N96
	.byte An1, En7
	.byte W96
	.byte Cn2
	.byte W96
	.byte Bn1
	.byte W96
	.byte TIE
	.byte En1, En6
	.byte W96
	.byte W48
	.byte EOT
	.byte W48
	.byte W96
	.byte N96
	.byte An1, En7
	.byte W96
	.byte Cn2
	.byte W96
	.byte Bn1
	.byte W96
	.byte N90
	.byte En2, Cn4
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_10_lbl_22ea19

	.byte FINE

track_10_4:
	.byte KEYSH, 0
track_10_lbl_22ea49:
	.byte VOICE, 26
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N12
	.byte Gs2, Gs7
	.byte W96
	.byte Gs2, Gn8
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte N12
	.byte W96
	.byte GOTO
		.word track_10_lbl_22ea49

	.byte FINE

track_10_5:
	.byte KEYSH, 0
track_10_lbl_22ea78:
	.byte W48
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v+15
	.byte PRIO, 118
	.byte N96
	.byte Bn1, Gs4
	.byte W48
	.byte W48
	.byte Bn1, Cn4
	.byte W48
	.byte W48
	.byte Bn1, Gs5
	.byte W48
	.byte W48
	.byte Bn1, Gs4
	.byte W48
	.byte W48
	.byte Bn1, Cn4
	.byte W48
	.byte W48
	.byte Bn1, Gs5
	.byte W48
	.byte W48
	.byte Bn1, Cn4
	.byte W48
	.byte W48
	.byte Bn1, Gs4
	.byte W48
	.byte W48
	.byte Bn1, Cn4
	.byte W48
	.byte W48
	.byte Bn1, Cn3
	.byte W48
	.byte W48
	.byte Bn1, Gs4
	.byte W48
	.byte W48
	.byte Bn1, Gs5
	.byte W48
	.byte W48
	.byte Bn1, Gs4
	.byte W48
	.byte W48
	.byte Bn1, Gs5
	.byte W48
	.byte GOTO
		.word track_10_lbl_22ea78
	.byte W48

	.byte FINE

.align 2

track_10:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_10_0
	.word track_10_1
	.word track_10_2
	.word track_10_3
	.word track_10_4
	.word track_10_5

.align 2
