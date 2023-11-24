.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_447

track_447_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 94
	.byte PAN, c_v-20
	.byte W03
	.byte TIE
	.byte Cn3, Cn8
	.byte W02
	.byte VOL, 79
	.byte W06
	.byte An4
	.byte W06
	.byte As4
	.byte W04
	.byte Cn5
	.byte W02
	.byte Cs5
	.byte W02
	.byte Cs5
	.byte W02
	.byte Ds5
	.byte W02
	.byte En5
	.byte W02
	.byte Fn5
	.byte W02
	.byte Fs5
	.byte W02
	.byte Gs5
	.byte W02
	.byte As5
	.byte W56
	.byte W03
	.byte W56
	.byte W01
	.byte EOT
	.byte W30

	.byte FINE

track_447_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 86
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W12
	.byte N44
	.byte Cn3, En7, CsM2
	.byte W06
	.byte BEND, c_v+31
	.byte W06
	.byte Gn8
	.byte W32
	.byte W01
	.byte N36
	.byte Cn3, Gs0, CsM2
	.byte W36
	.byte W01
	.byte Cn3, GsM2, CsM2
	.byte W02
	.byte W84
	.byte W03

	.byte FINE

track_447_2:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte MOD, 30
	.byte VOL, 94
	.byte PAN, c_v
	.byte LFOS, 80
	.byte PRIO, 24
	.byte TIE
	.byte Fn2, Cn8
	.byte W96
	.byte VOL, 62
	.byte W48
	.byte EOT
	.byte W36
	.byte W03

	.byte FINE

.align 2

track_447:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group10
	.word track_447_0
	.word track_447_1
	.word track_447_2

.align 2
