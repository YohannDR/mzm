.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_429

track_429_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N32
	.byte An2, En6, CsM2
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte FsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte BnM2
	.byte W01
	.byte DnM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Cs1
	.byte W01
	.byte En1
	.byte W01
	.byte Gn1
	.byte W01
	.byte An1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Dn2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Gs2
	.byte W01
	.byte As2
	.byte W01
	.byte Cs3
	.byte W01
	.byte En3
	.byte W09

	.byte FINE

.align 2

track_429:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_429_0

.align 2
