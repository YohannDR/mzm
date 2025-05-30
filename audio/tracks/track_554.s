.align 2

.global track_554

track_554_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 22
	.byte PAN, c_v-24
	.byte BENDR, 12
	.byte BEND, c_v-19
	.byte TIE, Cn3, v072
	.byte TIE, Gn3, v060
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v-19
	.byte W03
	.byte VOL, 36
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 51
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 58
	.byte W03
	.byte 55 @ VOL
	.byte W01
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 29
	.byte W02
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 24
	.byte W02
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 21
	.byte W02
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 22
	.byte W02
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 46
	.byte W01
	.byte BEND, c_v-22
	.byte W02
	.byte VOL, 51
	.byte W01
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 57
	.byte W01
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 58
	.byte W01
	.byte BEND, c_v-13
	.byte W03
	.byte c_v-11 @ BEND
	.byte W02
	.byte VOL, 57
	.byte W01
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 54
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 41
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 26
	.byte W02
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 17
	.byte W02
	.byte BEND, c_v-19
	.byte W03
	.byte c_v-22 @ BEND
	.byte W01
	.byte VOL, 18
	.byte W03
	.byte 20 @ VOL
	.byte W02
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 24
	.byte W02
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 29
	.byte W01
	.byte W01
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 41
	.byte W01
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v-19
	.byte W05
	.byte VOL, 46
	.byte W01
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 44
	.byte W03
	.byte 41 @ VOL
	.byte W01
	.byte BEND, c_v-19
	.byte W02
	.byte VOL, 26
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 19
	.byte W01
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v-1
	.byte W03
	.byte c_v-19 @ BEND
	.byte W02
	.byte VOL, 19
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 23
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W01
	.byte BEND, c_v-14
	.byte W02
	.byte VOL, 43
	.byte W01
	.byte 46 @ VOL
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 49
	.byte BEND, c_v-10
	.byte W03
	.byte VOL, 51
	.byte BEND, c_v-7
	.byte W03
	.byte VOL, 52
	.byte BEND, c_v-5
	.byte W03
	.byte VOL, 51
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 48
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 46
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 43
	.byte W01
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 27
	.byte W03
	.byte 19 @ VOL
	.byte W01
	.byte BEND, c_v-19
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 12
	.byte W03
	.byte 9 @ VOL
	.byte W01
	.byte EOT, Cn3, v067
	.byte FINE

.align 2

track_554:
	.byte 1
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_554_0

.align 2
