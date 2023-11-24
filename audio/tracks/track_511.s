.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_511

track_511_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 10
	.byte W04
	.byte BEND, c_v-63
	.byte N17
	.byte An1, En2
	.byte N17
	.byte En3, En1
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+21
	.byte W01
	.byte An5
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

track_511_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02
	.byte Fn3, Gs4
	.byte W02
	.byte Dn3
	.byte W02
	.byte An3
	.byte W02
	.byte Cn4
	.byte W04
	.byte Cn4, Gs0
	.byte W04
	.byte Cn4, CnM1
	.byte W02

	.byte FINE

.align 2

track_511:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_511_0
	.word track_511_1

.align 2
