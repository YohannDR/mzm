.align 2

.global track_411

track_411_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N36, En3, v080, 1
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v-53
	.byte W02
	.byte VOL, 99
	.byte BEND, c_v-40
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v-19
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+55 @ BEND
	.byte W03
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte VOL, 55
	.byte W02
	.byte 27 @ VOL
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v+1
	.byte W36
	.byte W03
	.byte VOL, 80
	.byte PAN, c_v
	.byte BEND, c_v-63
	.byte N21, Cn3 @ v080
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v-53
	.byte W02
	.byte VOL, 99
	.byte BEND, c_v-40
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v-19
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+55 @ BEND
	.byte W03
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v-63
	.byte N36, Gn3, v120, 1
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v-53
	.byte W02
	.byte VOL, 99
	.byte BEND, c_v-40
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v-19
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+55 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+43 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W04
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte VOL, 81
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 19
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W10
	.byte VOICE, 8
	.byte VOL, 120
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W02
	.byte N12, Cn3, v080
	.byte W12
	.byte Cn3, v100 @ N12
	.byte W12
	.byte N12 @ Cn3, v100
	.byte W12
	.byte N12 @ Cn3, v100
	.byte W12
	.byte N12 @ Cn3, v100
	.byte W12
	.byte N12 @ Cn3, v100
	.byte W12
	.byte N12 @ Cn3, v100
	.byte W12
	.byte N20 @ Cn3, v100
	.byte W60
	.byte FINE

track_411_1:
	.byte KEYSH, 0
	.byte W28
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W01
	.byte N48, An2, v060, 2
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 42
	.byte W01
	.byte 80 @ VOL
	.byte BEND, c_v+23
	.byte W02
	.byte c_v+26 @ BEND
	.byte W03
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-52 @ BEND
	.byte W02
	.byte c_v-59 @ BEND
	.byte W02
	.byte c_v-59 @ BEND
	.byte W02
	.byte c_v-51 @ BEND
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W01
	.byte VOL, 80
	.byte W01
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 0
	.byte W18
	.byte W15
	.byte 80 @ VOL
	.byte PAN, c_v
	.byte BEND, c_v-63
	.byte N36, Gn3, v032, 1
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v-53
	.byte W02
	.byte VOL, 99
	.byte BEND, c_v-40
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v-19
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+55 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+43 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W04
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte VOL, 81
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 19
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W44
	.byte W01
	.byte W96
	.byte FINE

track_411_2:
	.byte KEYSH, 0
	.byte W96
	.byte W32
	.byte W03
	.byte VOICE, 9
	.byte VOL, 110
	.byte PAN, c_v
	.byte W01
	.byte N02, Cn3, v100
	.byte W02
	.byte VOICE, 10
	.byte N18, Cn3, v127
	.byte W18
	.byte VOICE, 9
	.byte N02, Cn3, v100
	.byte W02
	.byte VOICE, 10
	.byte N18, An2, v127
	.byte W18
	.byte VOICE, 9
	.byte N02, Cn3, v100
	.byte W02
	.byte VOICE, 10
	.byte N18, Cn3, v127
	.byte W18
	.byte VOICE, 9
	.byte N02, Cn3, v100
	.byte W02
	.byte VOICE, 10
	.byte N18, En3, v127
	.byte W18
	.byte VOICE, 9
	.byte N02, Bn2, v100
	.byte W02
	.byte VOICE, 10
	.byte N18, Cn3, v127
	.byte W72
	.byte W02
	.byte FINE

track_411_3:
	.byte KEYSH, 0
	.byte W96
	.byte W32
	.byte W03
	.byte VOICE, 11
	.byte VOL, 127
	.byte PAN, c_v
	.byte W07
	.byte N05, Gs2, v100
	.byte W05
	.byte N10, Gs2, v127
	.byte W10
	.byte N05, Fn2, v100
	.byte W05
	.byte N10, Fn2, v127
	.byte W10
	.byte N05, Gs2, v100
	.byte W05
	.byte N10, Gs2, v127
	.byte W10
	.byte N05, Fn2, v100
	.byte W05
	.byte N10, Fn2, v127
	.byte W04
	.byte W06
	.byte N05, Gs2, v100
	.byte W05
	.byte N10, Gs2, v127
	.byte W10
	.byte N05, Fn2, v100
	.byte W05
	.byte N10, Fn2, v127
	.byte W10
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v100
	.byte W54
	.byte W01
	.byte FINE

.align 2

track_411:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word voice_group6
	.word track_411_0
	.word track_411_1
	.word track_411_2
	.word track_411_3

.align 2
