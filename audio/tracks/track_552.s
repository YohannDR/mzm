.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_552

track_552_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N72
	.byte Dn1, Gs5, CsM2
	.byte W03
	.byte BEND, c_v+1
	.byte W06
	.byte Fs3
	.byte W05
	.byte Gn3
	.byte W06
	.byte Gs3
	.byte W05
	.byte An3
	.byte W06
	.byte As3
	.byte W05
	.byte Bn3
	.byte W05
	.byte Cn4
	.byte W06
	.byte Cs4
	.byte W05
	.byte Dn4
	.byte W06
	.byte Ds4
	.byte W10
	.byte VOL, 47
	.byte W01
	.byte Gn0
	.byte W01
	.byte DsM1
	.byte W01
	.byte GnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_552_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte MOD, 20
	.byte VOL, 39
	.byte PAN, c_v
	.byte BENDR, 2
	.byte LFOS, 16
	.byte MODT, mod_tre
	.byte BEND, c_v
	.byte N72
	.byte Cn3, En2
	.byte W03
	.byte BEND, c_v+1
	.byte W04
	.byte Fs3
	.byte W05
	.byte Gn3
	.byte W04
	.byte Gs3
	.byte W05
	.byte An3
	.byte W04
	.byte As3
	.byte W05
	.byte Bn3
	.byte W04
	.byte Cn4
	.byte W05
	.byte Cs4
	.byte W04
	.byte Dn4
	.byte W05
	.byte Ds4
	.byte W04
	.byte En4
	.byte W05
	.byte Fn4
	.byte W04
	.byte Fs4
	.byte W05
	.byte Gn4
	.byte W02
	.byte VOL, 47
	.byte W01
	.byte Gn0
	.byte W01
	.byte DsM1
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte CnM2

	.byte FINE

track_552_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N72
	.byte AnM1, En6, CsM2
	.byte W04
	.byte BEND, c_v+1
	.byte W06
	.byte Fs3
	.byte W07
	.byte Gn3
	.byte W06
	.byte Gs3
	.byte W07
	.byte An3
	.byte W06
	.byte As3
	.byte W07
	.byte Bn3
	.byte W07
	.byte Cn4
	.byte W03
	.byte VOL, 78
	.byte W01
	.byte Fn4
	.byte W01
	.byte Dn4
	.byte W01
	.byte Cs4
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte As3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Fn3
	.byte W01
	.byte Dn3
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte Gn2
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs1
	.byte W01
	.byte Ds1
	.byte W01
	.byte An0
	.byte W01
	.byte Ds0
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_552:
	.byte 3
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_552_0
	.word track_552_1
	.word track_552_2

.align 2
