.align 2

.global track_703

track_703_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v-14
	.byte BENDR, 12
	.byte W56
	.byte BEND, c_v
	.byte N24, Cn3, v120
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W17
	.byte W23
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte N24, Cn3, v100
	.byte W01
	.byte BEND, c_v+11
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W02
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v-8 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W02
	.byte FINE

track_703_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte MOD, 60
	.byte VOL, 0
	.byte LFOS, 40
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v-63
	.byte TIE, An2, v127
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 67
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 72
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+33
	.byte W01
	.byte c_v+37 @ BEND
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 74
	.byte W01
	.byte 72 @ VOL
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-11
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-29
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte VOL, 53
	.byte W01
	.byte 52 @ VOL
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-21
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte 28 @ VOL
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 40 @ VOL
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 19
	.byte W01
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+15
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-7
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-7
	.byte W02
	.byte c_v-3 @ BEND
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+5
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-3
	.byte W01
	.byte EOT @ An2, v127
	.byte FINE

track_703_2:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 113
	.byte PAN, c_v-14
	.byte W04
	.byte N48, Cn3, v100
	.byte W76
	.byte W01
	.byte N36, Dn3, v060, 3
	.byte W15
	.byte W24
	.byte FINE

track_703_3:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 72
	.byte PAN, c_v-14
	.byte N16, Cn3, v120
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W24
	.byte 80 @ VOL
	.byte N16 @ Cn3, v120
	.byte W01
	.byte VOL, 83
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W24
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte N16, Cn3, v112
	.byte W01
	.byte VOL, 91
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte FINE

.align 2

track_703:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group15
	.word track_703_0
	.word track_703_1
	.word track_703_2
	.word track_703_3

.align 2
