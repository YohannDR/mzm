.align 2

.global track_445

track_445_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte MOD, 0
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte BEND, c_v-63
	.byte W20
	.byte N40, En3, v072
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-38 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W01
	.byte MOD, 40
	.byte BEND, c_v-29
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte MOD, 20
	.byte BEND, c_v+4
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 67
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+34
	.byte W01
	.byte MOD, 10
	.byte VOL, 44
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte MOD, 5
	.byte VOL, 13
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W36
	.byte W01
	.byte W68
	.byte FINE

track_445_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte MOD, 0
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 127
	.byte BEND, c_v
	.byte N32, An2, v080
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte MOD, 30
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W03
	.byte c_v+36 @ BEND
	.byte W01
	.byte MOD, 10
	.byte BEND, c_v+35
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte MOD, 5
	.byte BEND, c_v+17
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W64
	.byte W68
	.byte FINE

track_445_2:
	.byte KEYSH, 0
	.byte W40
	.byte VOICE, 2
	.byte VOL, 113
	.byte PAN, c_v
	.byte N03, Bn2, v112
	.byte W03
	.byte VOICE, 13
	.byte N06 @ Bn2, v112
	.byte W06
	.byte N21, Cn3, v092
	.byte W23
	.byte N06, Bn2 @ v092
	.byte W06
	.byte N21, Cn3, v072
	.byte W18
	.byte W05
	.byte N06, Bn2 @ v072
	.byte W06
	.byte N21, Cn3, v052
	.byte W56
	.byte W01
	.byte FINE

track_445_3:
	.byte KEYSH, 0
	.byte W60
	.byte VOICE, 13
	.byte VOL, 94
	.byte PAN, c_v
	.byte N08, An2, v092
	.byte W08
	.byte N21, Bn2, v060
	.byte W21
	.byte N08, An2, v072
	.byte W07
	.byte W01
	.byte N21, Bn2, v040
	.byte W21
	.byte N08, An2, v052
	.byte W08
	.byte N21, Bn2, v020
	.byte W36
	.byte W02
	.byte FINE

track_445_4:
	.byte KEYSH, 0
	.byte W40
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 55
	.byte N02, Cn4, v080
	.byte W02
	.byte VOICE, 8
	.byte N05, Fn2, v120
	.byte W18
	.byte Gn2 @ N05, v120
	.byte W17
	.byte Fn2, v100 @ N05
	.byte W17
	.byte Gn2 @ N05, v100
	.byte W02
	.byte W15
	.byte Fn2 @ N05, v100
	.byte W52
	.byte W01
	.byte FINE

.align 2

track_445:
	.byte 5
	.byte 0
	.byte 229
	.byte 0
	.word voice_group9
	.word track_445_0
	.word track_445_1
	.word track_445_2
	.word track_445_3
	.word track_445_4

.align 2
