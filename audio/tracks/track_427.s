.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_427

track_427_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36
	.byte Cn3, En6
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte FnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte Dn0
	.byte W01
	.byte En0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Fn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte An1
	.byte W01
	.byte Bn1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Gs2
	.byte W01
	.byte As2
	.byte W01
	.byte Cn3
	.byte W01
	.byte Dn3
	.byte W01
	.byte En3
	.byte W06

	.byte FINE

.align 2

track_427:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_427_0

.align 2
