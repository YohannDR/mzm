.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_426

track_426_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte MOD, 0
	.byte VOL, 34
	.byte PAN, c_v
	.byte BENDR, 14
	.byte LFOS, 127
	.byte BEND, c_v-63
	.byte N60
	.byte En2, Gs4
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte En1
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte Cs2
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 57
	.byte W01
	.byte An3
	.byte BEND, c_v-41
	.byte W02
	.byte Gn0
	.byte W02
	.byte Dn1
	.byte W02
	.byte MOD, 40
	.byte BEND, c_v-19
	.byte W02
	.byte Fn2
	.byte W02
	.byte Cn3
	.byte W02
	.byte Gs3
	.byte W02
	.byte Ds4
	.byte W02
	.byte Bn4
	.byte W02
	.byte MOD, 20
	.byte BEND, c_v+26
	.byte W02
	.byte Cs6
	.byte W02
	.byte An6
	.byte W02
	.byte En7
	.byte W02
	.byte Cn8
	.byte W02
	.byte Gn8
	.byte W02
	.byte MOD, 10
	.byte W12
	.byte VOL, 69
	.byte W01
	.byte Bn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte An1
	.byte W01
	.byte En1
	.byte W01
	.byte Cs1
	.byte W01
	.byte As0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Fs0
	.byte W01
	.byte En0
	.byte W01
	.byte Dn0
	.byte W01
	.byte Cs0
	.byte W01
	.byte N15
	.byte En2, GsM1
	.byte W06
	.byte VOL, 25
	.byte W01
	.byte FsM1
	.byte W01
	.byte CnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_426:
	.byte 1
	.byte 0
	.byte 219
	.byte 0
	.word voice_group9
	.word track_426_0

.align 2
