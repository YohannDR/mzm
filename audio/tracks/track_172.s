.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_172

track_172_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 70
	.byte PAN, c_v+16
	.byte PRIO, 1
	.byte N04
	.byte Cn2, Cn8
	.byte W05
	.byte Dn2, En6
	.byte W04
	.byte Cn2, Gs4
	.byte W05
	.byte Bn1, Cn3
	.byte W04
	.byte Cn2, En1
	.byte W05
	.byte Dn2, GsM1
	.byte W04

	.byte FINE

track_172_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v+16
	.byte W12
	.byte N32
	.byte An2, Gs4, DnM2
	.byte W20
	.byte VOL, 70
	.byte W01
	.byte An2
	.byte W01
	.byte Bn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Gn0
	.byte W01
	.byte Dn0
	.byte W01
	.byte GsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_172_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 49
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte PRIO, 62
	.byte BEND, c_v-32
	.byte W01
	.byte N05
	.byte Fn3, Cn3
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte Bn6
	.byte W01
	.byte Cn8
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte Gn3, Gs4
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte Fn3, Cn3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte Gn3, Gs4
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01
	.byte Gs0
	.byte N05
	.byte Fn3, Cn3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn6
	.byte W01
	.byte Gn8
	.byte W01

	.byte FINE

.align 2

track_172:
	.byte 3
	.byte 0
	.byte 190
	.byte 0
	.word voice_group7
	.word track_172_0
	.word track_172_1
	.word track_172_2

.align 2
