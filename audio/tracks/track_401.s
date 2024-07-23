.align 2

.global track_401

track_401_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 40
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 80
	.byte PRIO, 2
	.byte TIE
	.byte Cn3, En6
	.byte W48
	.byte LFOS, 60
	.byte W48
	.byte En1
	.byte W36
	.byte GsM1
	.byte W36
	.byte W02
	.byte VOL, 66
	.byte W02
	.byte Cs3
	.byte W02
	.byte Gn2
	.byte W02
	.byte Ds2
	.byte W02
	.byte As1
	.byte W02
	.byte Fn1
	.byte W02
	.byte Cs1
	.byte W02
	.byte Gn0
	.byte W02
	.byte Dn0
	.byte W02
	.byte AsM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte EOT

	.byte FINE

track_401_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v
	.byte N04
	.byte Cn2, Gs4
	.byte W04
	.byte Bn1
	.byte W04
	.byte Dn2
	.byte W04
	.byte An1
	.byte W04
	.byte Gn1
	.byte W04
	.byte Dn2
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Dn2
	.byte W04
	.byte Bn1
	.byte W04
	.byte Gn1
	.byte W04
	.byte An1
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Gn1
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte An1
	.byte W04
	.byte Dn2
	.byte W04
	.byte Gn1
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Dn2
	.byte W04
	.byte An1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Bn1
	.byte W04
	.byte Dn2
	.byte W04
	.byte An1
	.byte W04
	.byte Gn1
	.byte W04
	.byte Dn2
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Dn2
	.byte W04
	.byte Bn1
	.byte W04
	.byte Gn1
	.byte W04
	.byte An1
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte Gn1
	.byte W04
	.byte Bn1
	.byte W04
	.byte Cn2
	.byte W04
	.byte An1
	.byte W04
	.byte Dn2
	.byte W04
	.byte Gn1, Cn4
	.byte W04
	.byte Bn1, Cn3
	.byte W04
	.byte Cn2, En2
	.byte W04
	.byte Dn2, En1
	.byte W04
	.byte An1, Gs0
	.byte W04
	.byte Cn2, GsM1
	.byte W04
	.byte Bn1, CnM1
	.byte W04

	.byte FINE

track_401_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 26
	.byte BEND, c_v
	.byte N24
	.byte Cn3, Gs5
	.byte W03
	.byte BEND, c_v+7
	.byte W03
	.byte Fs4
	.byte W03
	.byte Bn4
	.byte W03
	.byte Ds5
	.byte W03
	.byte Gn5
	.byte W03
	.byte An5
	.byte W03
	.byte Cn6
	.byte W03
	.byte Cs6
	.byte N24
	.byte W03
	.byte BEND, c_v+35
	.byte W09
	.byte Cs6
	.byte W03
	.byte Cn6
	.byte W03
	.byte An5
	.byte W03
	.byte Gn5
	.byte W03
	.byte Ds5
	.byte N24
	.byte W03
	.byte BEND, c_v+18
	.byte W03
	.byte Fn4
	.byte W03
	.byte Bn3
	.byte W02
	.byte En3
	.byte W03
	.byte An2
	.byte W03
	.byte Ds2
	.byte W03
	.byte An1
	.byte W03
	.byte Ds1
	.byte W01
	.byte N24
	.byte W02
	.byte BEND, c_v-31
	.byte W03
	.byte Fn0
	.byte W03
	.byte Cs0
	.byte W03
	.byte AnM1
	.byte W03
	.byte FnM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte CsM1
	.byte W03
	.byte CnM1
	.byte W01
	.byte N24
	.byte W02
	.byte BEND, c_v-53
	.byte W03
	.byte CnM1
	.byte W03
	.byte CsM1
	.byte W03
	.byte DsM1
	.byte W03
	.byte FnM1
	.byte W03
	.byte AnM1
	.byte W03
	.byte Cs0
	.byte W03
	.byte Gn0
	.byte W01
	.byte N24
	.byte W02
	.byte BEND, c_v-27
	.byte W03
	.byte An1
	.byte W03
	.byte Fn2
	.byte W06
	.byte Bn3
	.byte W03
	.byte Fs4
	.byte W03
	.byte Cn5
	.byte W03
	.byte Fn5
	.byte W01
	.byte N24
	.byte W02
	.byte BEND, c_v+29
	.byte W03
	.byte Cn6
	.byte W03
	.byte Ds6
	.byte W03
	.byte En6
	.byte W03
	.byte Fn6
	.byte W09
	.byte Ds6
	.byte W01
	.byte N24
	.byte W02
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 63
	.byte W02
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 55
	.byte W02
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 48
	.byte W02
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 41
	.byte W02
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 33
	.byte W02
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 26
	.byte W02
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 12
	.byte N06
	.byte W03
	.byte VOL, 4
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_401:
	.byte 3
	.byte 0
	.byte 227
	.byte 0
	.word voice_group6
	.word track_401_0
	.word track_401_1
	.word track_401_2

.align 2
