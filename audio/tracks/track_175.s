.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_175

track_175_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W02
	.byte VOICE, 0
	.byte VOL, 45
	.byte PAN, c_v-14
	.byte BENDR, 6
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N30
	.byte Cn3, Gs4
	.byte W02
	.byte VOL, 81
	.byte BEND, c_v+50
	.byte W02
	.byte VOL, 91
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 89
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 82
	.byte BEND, c_v-38
	.byte W02
	.byte VOL, 73
	.byte BEND, c_v-43
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-27
	.byte W02
	.byte VOL, 63
	.byte BEND, c_v+2
	.byte W02
	.byte VOL, 64
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 61
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 13
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v+30
	.byte W02
	.byte VOL, 0

	.byte FINE

track_175_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 55
	.byte PAN, c_v-14
	.byte PRIO, 1
	.byte N04
	.byte Cn2, Cn8
	.byte W04
	.byte Dn2, En6
	.byte W04
	.byte Cn2, Cn8
	.byte W04
	.byte Bn1, En6
	.byte W04
	.byte Cn2, Cn8
	.byte W04
	.byte Dn2, En6
	.byte W04
	.byte Cn2, Cn8
	.byte W04
	.byte Bn1, En6
	.byte W04
	.byte Cn2, Cn8
	.byte W04

	.byte FINE

.align 2

track_175:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group7
	.word track_175_0
	.word track_175_1

.align 2
