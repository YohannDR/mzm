.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_441

track_441_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 0
	.byte PAN, c_v
	.byte TIE
	.byte Cn3, En6
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs4
	.byte W92
	.byte W01
	.byte W96
	.byte W48
	.byte EOT

	.byte FINE

track_441_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte TIE
	.byte Bn2, Gs4
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fs4
	.byte W30
	.byte W01
	.byte BEND, c_v-62
	.byte W04
	.byte DsM2
	.byte W02
	.byte EnM2
	.byte W04
	.byte FnM2
	.byte W02
	.byte FsM2
	.byte W04
	.byte GnM2
	.byte W04
	.byte GsM2
	.byte W02
	.byte AnM2
	.byte W04
	.byte AsM2
	.byte W02
	.byte BnM2
	.byte W04
	.byte CnM1
	.byte W04
	.byte CsM1
	.byte W02
	.byte DnM1
	.byte W04
	.byte DsM1
	.byte W02
	.byte EnM1
	.byte W04
	.byte FnM1
	.byte W02
	.byte FsM1
	.byte W04
	.byte GnM1
	.byte W04
	.byte GsM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte W02
	.byte AsM1
	.byte W02
	.byte BnM1
	.byte W04
	.byte Cn0
	.byte W04
	.byte Cs0
	.byte W02
	.byte Dn0
	.byte W04
	.byte Ds0
	.byte W02
	.byte En0
	.byte W04
	.byte Fn0
	.byte W02
	.byte Fs0
	.byte W04
	.byte Gn0
	.byte W04
	.byte Gs0
	.byte W02
	.byte An0
	.byte W04
	.byte As0
	.byte W02
	.byte Bn0
	.byte W04
	.byte Cn1
	.byte W04
	.byte Cs1
	.byte W02
	.byte Dn1
	.byte W04
	.byte Ds1
	.byte W02
	.byte En1
	.byte W04
	.byte Fn1
	.byte W04
	.byte Fs1
	.byte W02
	.byte Gn1
	.byte W04
	.byte Gs1
	.byte W02
	.byte An1
	.byte W04
	.byte As1
	.byte W02
	.byte Bn1
	.byte W03
	.byte Cn2
	.byte W13
	.byte W48
	.byte EOT

	.byte FINE

track_441_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte MOD, 30
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 25
	.byte N24
	.byte Fn2, Gs4
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 60
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 100
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 60
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24
	.byte LFOS, 100
	.byte N24
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte W24

	.byte FINE

.align 2

track_441:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group9
	.word track_441_0
	.word track_441_1
	.word track_441_2

.align 2
