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
	.byte TIE
	.byte Cn3, Cn4
	.byte TIE
	.byte Gn3, Cn3
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v-19
	.byte W03
	.byte VOL, 36
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 51
	.byte W03
	.byte Gn2
	.byte W03
	.byte As2
	.byte W03
	.byte Cn3
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 58
	.byte W03
	.byte Gn2
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
	.byte As0
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
	.byte Fn2
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
	.byte Fs1
	.byte W01
	.byte VOL, 18
	.byte W03
	.byte GsM1
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
	.byte As0
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
	.byte Fn1
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
	.byte An1
	.byte W02
	.byte VOL, 19
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 23
	.byte W03
	.byte Fn0
	.byte W03
	.byte Cn1
	.byte W01
	.byte BEND, c_v-14
	.byte W02
	.byte VOL, 43
	.byte W01
	.byte As1
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
	.byte GnM1
	.byte W01
	.byte BEND, c_v-19
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 12
	.byte W03
	.byte AnM2
	.byte W01
	.byte EOT, Cn3
	.byte Gn3

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
