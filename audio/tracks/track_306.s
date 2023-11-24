.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_306

track_306_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 70
	.byte PAN, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W03
	.byte VOICE, 19
	.byte MOD, 90
	.byte LFOS, 40
	.byte N06
	.byte W05
	.byte LFOS, 60
	.byte W01
	.byte N21
	.byte Dn3, Cn3
	.byte W04
	.byte LFOS, 80
	.byte W05
	.byte En6
	.byte W05
	.byte Cn8
	.byte W36
	.byte W01

	.byte FINE

track_306_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 36
	.byte W01
	.byte BEND, c_v-63
	.byte N10
	.byte Cn2, Gs5
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-35
	.byte W01
	.byte Cn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-7
	.byte W01
	.byte En3
	.byte W01
	.byte VOICE, 2
	.byte VOL, 77
	.byte N04
	.byte Fn2, En7
	.byte W48
	.byte W01

	.byte FINE

.align 2

track_306:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group5
	.word track_306_0
	.word track_306_1

.align 2
