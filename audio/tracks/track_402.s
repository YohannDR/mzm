.align 2

.global track_402

track_402_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 40
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 80
	.byte TIE, Cn3, v100
	.byte W96
	.byte W96
	.byte W24
	.byte EOT @ Cn3, v100
	.byte LFOS, 60
	.byte N72, Gn2 @ v100
	.byte W03
	.byte VOL, 62
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte LFOS, 50
	.byte VOL, 40
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte LFOS, 40
	.byte VOL, 22
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte LFOS, 30
	.byte VOL, 12
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte LFOS, 20
	.byte VOL, 6
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte LFOS, 10
	.byte VOL, 3
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte FINE

track_402_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v
	.byte BEND, c_v
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
	.byte BENDR, 12
	.byte BEND, c_v-16
	.byte N04, Bn1 @ v080
	.byte W03
	.byte VOL, 74
	.byte W01
	.byte N04, Cn2 @ v080
	.byte W02
	.byte VOL, 71
	.byte W02
	.byte N04, Dn2 @ v080
	.byte W01
	.byte VOL, 68
	.byte W03
	.byte 65 @ VOL
	.byte N04, Bn1 @ v080
	.byte W03
	.byte VOL, 61
	.byte W01
	.byte N04, Gn1 @ v080
	.byte W02
	.byte VOL, 58
	.byte W02
	.byte N04, An1 @ v080
	.byte W01
	.byte VOL, 55
	.byte W03
	.byte 51 @ VOL
	.byte N04, Bn1 @ v080
	.byte W03
	.byte VOL, 48
	.byte W01
	.byte N04, Cn2 @ v080
	.byte W02
	.byte VOL, 44
	.byte W02
	.byte N04, Gn1 @ v080
	.byte W01
	.byte VOL, 41
	.byte W03
	.byte 38 @ VOL
	.byte N04, Bn1 @ v080
	.byte W03
	.byte VOL, 35
	.byte W01
	.byte N04, Cn2 @ v080
	.byte W02
	.byte VOL, 31
	.byte W02
	.byte N04, An1 @ v080
	.byte W01
	.byte VOL, 28
	.byte W03
	.byte 25 @ VOL
	.byte N04, Dn2 @ v080
	.byte W03
	.byte VOL, 22
	.byte W01
	.byte N04, Gn1 @ v080
	.byte W02
	.byte VOL, 18
	.byte W02
	.byte N04, Bn1 @ v080
	.byte W01
	.byte VOL, 14
	.byte W03
	.byte 11 @ VOL
	.byte N04, Cn2 @ v080
	.byte W03
	.byte VOL, 8
	.byte W01
	.byte N04, Dn2 @ v080
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte N04, An1 @ v080
	.byte W01
	.byte VOL, 1
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_402_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte MOD, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 24
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
	.byte W03
	.byte c_v+1 @ BEND
	.byte W03
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-29 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v-35
	.byte W03
	.byte c_v-39 @ BEND
	.byte W03
	.byte c_v-43 @ BEND
	.byte W03
	.byte c_v-46 @ BEND
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-50 @ BEND
	.byte W03
	.byte c_v-52 @ BEND
	.byte W03
	.byte c_v-53 @ BEND
	.byte N24 @ Cn3, v092
	.byte W12
	.byte BEND, c_v-51
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-46 @ BEND
	.byte W03
	.byte c_v-43 @ BEND
	.byte W03
	.byte c_v-38 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v-33
	.byte W03
	.byte c_v-27 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-9 @ BEND
	.byte W03
	.byte c_v-1 @ BEND
	.byte W03
	.byte c_v+7 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v+19
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
	.byte W03
	.byte c_v+35 @ BEND
	.byte W03
	.byte c_v+37 @ BEND
	.byte N24 @ Cn3, v092
	.byte W15
	.byte BEND, c_v+36
	.byte W03
	.byte c_v+35 @ BEND
	.byte W03
	.byte c_v+33 @ BEND
	.byte W03
	.byte c_v+31 @ BEND
	.byte N24 @ Cn3, v092
	.byte W03
	.byte BEND, c_v+29
	.byte W03
	.byte c_v+25 @ BEND
	.byte W03
	.byte c_v+21 @ BEND
	.byte W03
	.byte c_v+17 @ BEND
	.byte W03
	.byte c_v+13 @ BEND
	.byte W03
	.byte c_v+9 @ BEND
	.byte W03
	.byte c_v+3 @ BEND
	.byte W03
	.byte VOICE, 3
	.byte VOL, 70
	.byte MOD, 40
	.byte LFOS, 60
	.byte BEND, c_v
	.byte N24, En2, v120
	.byte W06
	.byte VOL, 64
	.byte W06
	.byte 58 @ VOL
	.byte W06
	.byte 52 @ VOL
	.byte W06
	.byte 46 @ VOL
	.byte LFOS, 40
	.byte N24 @ En2, v120
	.byte W06
	.byte VOL, 40
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 22 @ VOL
	.byte LFOS, 20
	.byte N24 @ En2, v120
	.byte W06
	.byte VOL, 16
	.byte W06
	.byte 10 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W05
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_402:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group6
	.word track_402_0
	.word track_402_1
	.word track_402_2

.align 2
