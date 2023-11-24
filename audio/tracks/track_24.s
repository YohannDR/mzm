.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_24

track_24_0:
	.byte KEYSH, 0
track_24_lbl_22ff56:
	.byte TEMPO, 49
	.byte VOICE, 99
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 28
	.byte TIE
	.byte Gn3, Gn8
	.byte W96
	.byte W96
	.byte EOT
	.byte VOICE, 97
	.byte PAN, c_v+15
	.byte TIE
	.byte Fn1, Cn3
	.byte W96
	.byte W96
	.byte EOT
	.byte W96
	.byte W96
	.byte PAN, c_v-17
	.byte TIE
	.byte An1
	.byte W96
	.byte W96
	.byte EOT
	.byte W96
	.byte W96
	.byte PAN, c_v
	.byte TIE
	.byte Fs1
	.byte W96
	.byte W96
	.byte EOT
	.byte W96
	.byte W96
	.byte GOTO
		.word track_24_lbl_22ff56

	.byte FINE

track_24_1:
	.byte KEYSH, 0
track_24_lbl_22ff8c:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v-17
	.byte PRIO, 29
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
		.word track_24_lbl_22ff8c

	.byte FINE

track_24_2:
	.byte KEYSH, 0
track_24_lbl_22ffb3:
	.byte VOICE, 96
	.byte VOL, 62
	.byte PAN, c_v+15
	.byte PRIO, 30
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
		.word track_24_lbl_22ffb3

	.byte FINE

track_24_3:
	.byte KEYSH, 0
track_24_lbl_22ffda:
	.byte VOICE, 26
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 118
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
		.word track_24_lbl_22ffda

	.byte FINE

track_24_4:
	.byte KEYSH, 0
track_24_lbl_230009:
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v-17
	.byte PRIO, 119
	.byte N96
	.byte Bn1, En6
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte N96
	.byte W96
	.byte GOTO
		.word track_24_lbl_230009

	.byte FINE

track_24_5:
	.byte KEYSH, 0
track_24_lbl_230037:
	.byte W48
	.byte VOICE, 58
	.byte VOL, 44
	.byte PAN, c_v+15
	.byte PRIO, 120
	.byte N96
	.byte Bn1, En6
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte W48
	.byte N96
	.byte W48
	.byte GOTO
		.word track_24_lbl_230037
	.byte W48

	.byte FINE

.align 2

track_24:
	.byte 6
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_24_0
	.word track_24_1
	.word track_24_2
	.word track_24_3
	.word track_24_4
	.word track_24_5

.align 2
