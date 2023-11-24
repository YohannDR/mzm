.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_15

track_15_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte PRIO, 120
	.byte W96
	.byte W96
track_15_lbl_22f230:
	.byte VOICE, 29
	.byte VOL, 48
	.byte PAN, c_v
	.byte N44
	.byte Bn3, Gs4
	.byte W48
	.byte N24
	.byte Cn4, En4
	.byte W24
	.byte Gn3, En3
	.byte W24
	.byte Gs3
	.byte W24
	.byte Fn3, Cn3
	.byte W24
	.byte Gn3, Gs2
	.byte W24
	.byte Ds3, Gs1
	.byte W24
	.byte Fn3, En7
	.byte W24
	.byte Dn3
	.byte W24
	.byte Ds3, Gs6
	.byte W24
	.byte N96
	.byte Gn2, Gn8
	.byte W24
	.byte W96
	.byte N24
	.byte As3, En5
	.byte W24
	.byte Gs3
	.byte W24
	.byte N96
	.byte Gn3
	.byte W48
	.byte W96
	.byte N24
	.byte Fn3, Gs6
	.byte W24
	.byte Dn3
	.byte W24
	.byte Ds3
	.byte W24
	.byte TIE
	.byte Gn2
	.byte W24
	.byte W96
	.byte W24
	.byte EOT
	.byte W72
	.byte N48
	.byte Dn4, En5
	.byte W48
	.byte N24
	.byte Ds4
	.byte W24
	.byte Bn3
	.byte W24
	.byte Cn4
	.byte W24
	.byte Gn3
	.byte W24
	.byte As3
	.byte W24
	.byte Gs3
	.byte W24
	.byte N96
	.byte Gn3
	.byte W96
	.byte W24
	.byte N24
	.byte Fn3, Cn8
	.byte W24
	.byte Dn3
	.byte W24
	.byte Ds3
	.byte W24
	.byte N96
	.byte Gn2, Gn8
	.byte W96
	.byte GOTO
		.word track_15_lbl_22f230

	.byte FINE

track_15_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 56
	.byte PAN, c_v+20
	.byte PRIO, 118
	.byte N24
	.byte Cn1, Cn4
	.byte W48
	.byte Cn1, Cn5
	.byte W48
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Gs4
	.byte W48
track_15_lbl_22f2b0:
	.byte N24
	.byte Cn1, Cn4
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, Cn3
	.byte W48
	.byte Cn1, En2
	.byte W48
	.byte Cn1, Cn5
	.byte W48
	.byte Cn1, Gs5
	.byte W48
	.byte Cn1, En5
	.byte W48
	.byte Cn1, Gs4
	.byte W48
	.byte Cn1, Cn4
	.byte W48
	.byte Cn1, En5
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, Cn5
	.byte W48
	.byte Cn1, Gs4
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Cn4
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, En4
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, Gs4
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, Cn5
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, En5
	.byte W48
	.byte N24
	.byte W48
	.byte Cn1, Gs5
	.byte W48
	.byte GOTO
		.word track_15_lbl_22f2b0

	.byte FINE

track_15_2:
	.byte KEYSH, 0
	.byte PRIO, 119
	.byte W01
	.byte VOICE, 4
	.byte VOL, 59
	.byte PAN, c_v-22
	.byte N28
	.byte Cn1, Cn4
	.byte W48
	.byte Cn1, En4
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, Gs4
	.byte W48
	.byte Cn1, En4
	.byte W44
	.byte W03
track_15_lbl_22f31c:
	.byte W01
	.byte N28
	.byte Cn1, Cn3
	.byte W48
	.byte Cn1, Gs5
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Cn3
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, En5
	.byte W48
	.byte Cn1, Cn5
	.byte W44
	.byte W03
track_15_lbl_22f335:
	.byte W01
	.byte N28
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Gs4
	.byte W44
	.byte W03
	.byte PEND
	.byte W01
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Cn4
	.byte W44
	.byte W03
	.byte W01
	.byte N28
	.byte W48
	.byte Cn1, En3
	.byte W44
	.byte W03
track_15_lbl_22f34e:
	.byte W01
	.byte N28
	.byte Cn1, Cn4
	.byte W48
	.byte Cn1, En4
	.byte W44
	.byte W03
	.byte PEND
	.byte W01
	.byte Cn1, Gs4
	.byte W48
	.byte Cn1, Gs5
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, Cn3
	.byte W48
	.byte Cn1, Cn4
	.byte W44
	.byte W03
	.byte PATT
		.word track_15_lbl_22f335
	.byte W01
	.byte N28
	.byte Cn1, Gs4
	.byte W48
	.byte N28
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, En4
	.byte W48
	.byte Cn1, Gs5
	.byte W44
	.byte W03
	.byte W01
	.byte Cn1, En4
	.byte W48
	.byte N28
	.byte W44
	.byte W03
	.byte PATT
		.word track_15_lbl_22f34e
	.byte GOTO
		.word track_15_lbl_22f31c

	.byte FINE

.align 2

track_15:
	.byte 3
	.byte 0
	.byte 130
	.byte 0
	.word voice_group0
	.word track_15_0
	.word track_15_1
	.word track_15_2

.align 2
