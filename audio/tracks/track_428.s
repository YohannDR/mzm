.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_428

track_428_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v
	.byte N36
	.byte Cn3, Gs5
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
	.byte GsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CsM2
	.byte W01

	.byte FINE

.align 2

track_428:
	.byte 1
	.byte 0
	.byte 211
	.byte 0
	.word voice_group9
	.word track_428_0

.align 2
