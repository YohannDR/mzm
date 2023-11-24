.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_271

track_271_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 18
	.byte W01
track_271_lbl_20dc1d:
	.byte BEND, c_v-13
	.byte N15
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Cs3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Cn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte As4
	.byte W01
	.byte En5
	.byte W01
	.byte An5
	.byte W01
	.byte Dn6
	.byte W01
	.byte Gs6
	.byte W01
	.byte Cs7
	.byte W01
	.byte Fs7
	.byte W01
	.byte Cn8
	.byte W01
	.byte Gn8
	.byte W02
	.byte GOTO
		.word track_271_lbl_20dc1d

	.byte FINE

track_271_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 18
	.byte W01
track_271_lbl_20dc51:
	.byte W01
	.byte BEND, c_v-13
	.byte N15
	.byte Gn2, Cn3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Cs3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Cn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte As4
	.byte W01
	.byte En5
	.byte W01
	.byte An5
	.byte W01
	.byte Dn6
	.byte W01
	.byte Gs6
	.byte W01
	.byte Cs7
	.byte W01
	.byte Fs7
	.byte W01
	.byte Cn8
	.byte W01
	.byte Gn8
	.byte W01
	.byte GOTO
		.word track_271_lbl_20dc51

	.byte FINE

.align 2

track_271:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_271_0
	.word track_271_1

.align 2
