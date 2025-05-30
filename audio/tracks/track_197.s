.align 2

.global track_197

track_197_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W10
	.byte VOICE, 10
	.byte VOL, 48
	.byte PAN, c_v-14
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N12, Dn3, v048
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v-51
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 59
	.byte N24, En3, v048, 2
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 71
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+18
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte 48 @ VOL
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 0 @ VOL
	.byte W15
	.byte FINE

track_197_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte PRIO, 1
	.byte N04, Cn3, v120
	.byte W04
	.byte N13, Gs2, v127
	.byte W13
	.byte As2, v100 @ N13
	.byte W10
	.byte VOL, 78
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W32
	.byte W01
	.byte FINE

track_197_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte W17
	.byte N13, En3, v100
	.byte W44
	.byte W01
	.byte FINE

track_197_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte PRIO, 1
	.byte W04
	.byte N04, Gs2, v100
	.byte W04
	.byte N10, Fn2, v127
	.byte W54
	.byte FINE

.align 2

track_197:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group11
	.word track_197_0
	.word track_197_1
	.word track_197_2
	.word track_197_3

.align 2
