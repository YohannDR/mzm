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
	.byte TIE, Cn3, v100
	.byte W48
	.byte LFOS, 60
	.byte W48
	.byte En1 @ TIE, v100
	.byte W36
	.byte GsM1 @ TIE, v100
	.byte W36
	.byte W02
	.byte VOL, 66
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ GsM1, v100
	.byte FINE

track_401_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v
	.byte N04, Cn2, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte Gn1 @ N04, v080
	.byte W04
	.byte Bn1 @ N04, v080
	.byte W04
	.byte Cn2 @ N04, v080
	.byte W04
	.byte An1 @ N04, v080
	.byte W04
	.byte Dn2 @ N04, v080
	.byte W04
	.byte Gn1, v072 @ N04
	.byte W04
	.byte Bn1, v060 @ N04
	.byte W04
	.byte Cn2, v052 @ N04
	.byte W04
	.byte Dn2, v040 @ N04
	.byte W04
	.byte An1, v032 @ N04
	.byte W04
	.byte Cn2, v020 @ N04
	.byte W04
	.byte Bn1, v012 @ N04
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
	.byte N24, Cn3, v092
	.byte W03
	.byte BEND, c_v+7
	.byte W03
	.byte c_v+14 @ BEND
	.byte W03
	.byte c_v+19 @ BEND
	.byte W03
	.byte c_v+23 @ BEND
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+29 @ BEND
	.byte W03
	.byte c_v+32 @ BEND
	.byte W03
	.byte c_v+33 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v+35
	.byte W09
	.byte c_v+33 @ BEND
	.byte W03
	.byte c_v+32 @ BEND
	.byte W03
	.byte c_v+29 @ BEND
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+23 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v+18
	.byte W03
	.byte c_v+13 @ BEND
	.byte W03
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W03
	.byte c_v-7 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-25 @ BEND
	.byte W01
	.byte N24 @ Cn3, v092
	.byte W02
	.byte BEND, c_v-31
	.byte W03
	.byte c_v-35 @ BEND
	.byte W03
	.byte c_v-39 @ BEND
	.byte W03
	.byte c_v-43 @ BEND
	.byte W03
	.byte c_v-47 @ BEND
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-51 @ BEND
	.byte W03
	.byte c_v-52 @ BEND
	.byte W01
	.byte N24 @ Cn3, v092
	.byte W02
	.byte BEND, c_v-53
	.byte W03
	.byte c_v-52 @ BEND
	.byte W03
	.byte c_v-51 @ BEND
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-47 @ BEND
	.byte W03
	.byte c_v-43 @ BEND
	.byte W03
	.byte c_v-39 @ BEND
	.byte W03
	.byte c_v-33 @ BEND
	.byte W01
	.byte N24 @ Cn3, v092
	.byte W02
	.byte BEND, c_v-27
	.byte W03
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W06
	.byte c_v+7 @ BEND
	.byte W03
	.byte c_v+14 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+25 @ BEND
	.byte W01
	.byte N24 @ Cn3, v092
	.byte W02
	.byte BEND, c_v+29
	.byte W03
	.byte c_v+32 @ BEND
	.byte W03
	.byte c_v+35 @ BEND
	.byte W03
	.byte c_v+36 @ BEND
	.byte W03
	.byte c_v+37 @ BEND
	.byte W09
	.byte c_v+35 @ BEND
	.byte W01
	.byte N24 @ Cn3, v092
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
	.byte N06 @ Cn3, v092
	.byte W03
	.byte VOL, 4
	.byte W02
	.byte 0 @ VOL
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
