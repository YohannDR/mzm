.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_432

track_432_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 74
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v
	.byte N36
	.byte Bn2, Gs5, CsM2
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte Cn3
	.byte W01
	.byte As2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Fs2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Cs2
	.byte W01
	.byte Bn1
	.byte W01
	.byte An1
	.byte W01
	.byte Gs1
	.byte W01
	.byte Fs1
	.byte W01
	.byte En1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Cn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte An0
	.byte W01
	.byte Gn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Dn0
	.byte W01
	.byte Cn0
	.byte W01
	.byte AsM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte AnM2
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-60
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-62
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_432:
	.byte 1
	.byte 0
	.byte 212
	.byte 0
	.word voice_group9
	.word track_432_0

.align 2
