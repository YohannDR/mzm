.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_439

track_439_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 48
	.byte BEND, c_v-63
	.byte N08
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-57
	.byte W01
	.byte DsM1
	.byte W01
	.byte AnM1
	.byte W01
	.byte Gn0
	.byte W01
	.byte Fn1
	.byte W01
	.byte Gn2
	.byte W01
	.byte Ds5
	.byte W07
	.byte VOICE, 15
	.byte VOL, 50
	.byte BENDR, 16
	.byte BEND, c_v-63
	.byte N13
	.byte Cn3, Cn4
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte BnM2
	.byte W01
	.byte EnM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte Bn0
	.byte W01
	.byte En2
	.byte W01
	.byte Gn4
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte CsM1
	.byte W01
	.byte FsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_439:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group9
	.word track_439_0

.align 2
