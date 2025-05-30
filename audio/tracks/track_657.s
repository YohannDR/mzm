.align 2

.global track_657

track_657_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 14
	.byte VOL, 44
	.byte BEND, c_v
	.byte N10, An2, v100
	.byte W01
	.byte VOL, 45
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W06
	.byte N10, An2, v060
	.byte W10
	.byte An2, v032 @ N10
	.byte W10
	.byte N21, An2, v012
	.byte W21
	.byte FINE

track_657_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 14
	.byte VOL, 33
	.byte BEND, c_v
	.byte N10, Cn3, v100
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W06
	.byte N10, Cn3, v060
	.byte W10
	.byte Cn3, v032 @ N10
	.byte W10
	.byte N21, Cn3, v012
	.byte W21
	.byte FINE

track_657_2:
	.byte KEYSH, 0
	.byte VOL, 18
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W04
	.byte VOICE, 15
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N60, Cn1, v072, 1
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 45
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 55
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 60
	.byte W02
	.byte 53 @ VOL
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 42
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte BEND, c_v-14
	.byte W02
	.byte VOL, 44
	.byte W01
	.byte 45 @ VOL
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 52
	.byte W02
	.byte 50 @ VOL
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_657:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_657_0
	.word track_657_1
	.word track_657_2

.align 2
