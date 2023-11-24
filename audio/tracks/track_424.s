.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_424

track_424_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 15
	.byte BEND, c_v-63
	.byte N40
	.byte Dn3, En6
	.byte W01
	.byte BEND, c_v-62
	.byte W01
	.byte EnM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte AsM2
	.byte W01
	.byte CnM1
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
	.byte BnM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gn0
	.byte W01
	.byte An0
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
	.byte Gs1
	.byte W01
	.byte As1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Dn2
	.byte W01
	.byte En2
	.byte W01
	.byte Fs2
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
	.byte W07
	.byte MOD, 40
	.byte LFOS, 50
	.byte N48
	.byte Cn3, Gs4
	.byte W48

	.byte FINE

.align 2

track_424:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_424_0

.align 2
