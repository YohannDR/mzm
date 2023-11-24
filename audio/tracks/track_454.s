.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_454

track_454_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 40
	.byte PAN, c_v-20
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N28
	.byte An3, Gs4
	.byte W02
	.byte BEND, c_v+5
	.byte W02
	.byte Dn4
	.byte W02
	.byte Gn4
	.byte W02
	.byte Bn4
	.byte W02
	.byte En5
	.byte W02
	.byte An5
	.byte W02
	.byte Dn6
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte An0
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte En0
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte Cs0
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte BnM1
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte GsM1
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 20
	.byte W01

	.byte FINE

.align 2

track_454:
	.byte 1
	.byte 0
	.byte 175
	.byte 0
	.word voice_group10
	.word track_454_0

.align 2
