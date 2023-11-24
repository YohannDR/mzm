.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_280

track_280_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 37
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03
	.byte Gn4, Cn1
	.byte W03
	.byte VOICE, 16
	.byte VOL, 37
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16
	.byte Fn2, Gs4
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01

	.byte FINE

track_280_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 37
	.byte PAN, c_v
	.byte N13
	.byte Fn2, Cn3
	.byte W32
	.byte VOL, 50
	.byte N10
	.byte Cn2
	.byte W06
	.byte VOL, 37
	.byte W01
	.byte Cs0
	.byte W01
	.byte CnM1
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_280:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word voice_group4
	.word track_280_0
	.word track_280_1

.align 2
