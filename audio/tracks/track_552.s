.align 2

.global track_552

track_552_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N72, Dn1, v092, 1
	.byte W03
	.byte BEND, c_v+1
	.byte W06
	.byte c_v+2 @ BEND
	.byte W05
	.byte c_v+3 @ BEND
	.byte W06
	.byte c_v+4 @ BEND
	.byte W05
	.byte c_v+5 @ BEND
	.byte W06
	.byte c_v+6 @ BEND
	.byte W05
	.byte c_v+7 @ BEND
	.byte W05
	.byte c_v+8 @ BEND
	.byte W06
	.byte c_v+9 @ BEND
	.byte W05
	.byte c_v+10 @ BEND
	.byte W06
	.byte c_v+11 @ BEND
	.byte W10
	.byte VOL, 47
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 0 @ VOL
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
	.byte N72, Cn3, v052
	.byte W03
	.byte BEND, c_v+1
	.byte W04
	.byte c_v+2 @ BEND
	.byte W05
	.byte c_v+3 @ BEND
	.byte W04
	.byte c_v+4 @ BEND
	.byte W05
	.byte c_v+5 @ BEND
	.byte W04
	.byte c_v+6 @ BEND
	.byte W05
	.byte c_v+7 @ BEND
	.byte W04
	.byte c_v+8 @ BEND
	.byte W05
	.byte c_v+9 @ BEND
	.byte W04
	.byte c_v+10 @ BEND
	.byte W05
	.byte c_v+11 @ BEND
	.byte W04
	.byte c_v+12 @ BEND
	.byte W05
	.byte c_v+13 @ BEND
	.byte W04
	.byte c_v+14 @ BEND
	.byte W05
	.byte c_v+15 @ BEND
	.byte W02
	.byte VOL, 47
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte 0 @ VOL
	.byte FINE

track_552_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N72, AnM1, v100, 1
	.byte W04
	.byte BEND, c_v+1
	.byte W06
	.byte c_v+2 @ BEND
	.byte W07
	.byte c_v+3 @ BEND
	.byte W06
	.byte c_v+4 @ BEND
	.byte W07
	.byte c_v+5 @ BEND
	.byte W06
	.byte c_v+6 @ BEND
	.byte W07
	.byte c_v+7 @ BEND
	.byte W07
	.byte c_v+8 @ BEND
	.byte W03
	.byte VOL, 78
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte 55 @ VOL
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_552:
	.byte 3
	.byte 0
.ifdef REGION_US_BETA
	.byte 251
.else
	.byte 229
.endif
	.byte 128
	.word voice_group17
	.word track_552_0
	.word track_552_1
	.word track_552_2

.align 2
