.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_455

track_455_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N24
	.byte Cn4, Gs4
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte CnM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte En0
	.byte W01
	.byte As0
	.byte W01
	.byte Ds1
	.byte W01
	.byte An1
	.byte W01
	.byte Dn2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Cs3
	.byte W01
	.byte Gn3
	.byte W01
	.byte Cn4
	.byte W01
	.byte Fs4
	.byte W01
	.byte Bn4
	.byte W01
	.byte Fn5
	.byte W01
	.byte As5
	.byte W01
	.byte En6
	.byte W01
	.byte An6
	.byte W01
	.byte Ds7
	.byte W01
	.byte Gs7
	.byte W01
	.byte Cs8
	.byte W01
	.byte Gn8
	.byte W01

	.byte FINE

.align 2

track_455:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group10
	.word track_455_0

.align 2
