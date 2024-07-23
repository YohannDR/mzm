.align 2

.global track_571

track_571_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte MOD, 16
	.byte VOL, 0
	.byte LFOS, 4
	.byte PAN, c_v+30
	.byte TIE
	.byte Fn2, Cn8
	.byte W03
	.byte VOL, 1
	.byte PAN, c_v+27
	.byte W03
	.byte VOL, 4
	.byte PAN, c_v+25
	.byte W03
	.byte VOL, 6
	.byte PAN, c_v+22
	.byte W03
	.byte VOL, 9
	.byte PAN, c_v+20
	.byte W03
	.byte VOL, 11
	.byte PAN, c_v+17
	.byte W03
	.byte VOL, 15
	.byte PAN, c_v+15
	.byte W03
	.byte VOL, 19
	.byte PAN, c_v+12
	.byte W03
	.byte VOL, 24
	.byte PAN, c_v+10
	.byte W03
	.byte VOL, 32
	.byte PAN, c_v+7
	.byte W03
	.byte VOL, 39
	.byte PAN, c_v+5
	.byte W03
	.byte VOL, 49
	.byte PAN, c_v+2
	.byte W03
	.byte VOL, 62
	.byte PAN, c_v
	.byte W60
	.byte W96
	.byte W96
	.byte W72
	.byte EOT

	.byte FINE

track_571_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte MOD, 30
	.byte VOL, 0
	.byte LFOS, 10
	.byte MODT, mod_tre
	.byte PAN, c_v+30
	.byte TIE
	.byte Gn2, Gs4
	.byte W03
	.byte VOL, 1
	.byte PAN, c_v+27
	.byte W03
	.byte VOL, 4
	.byte PAN, c_v+25
	.byte W03
	.byte VOL, 6
	.byte PAN, c_v+22
	.byte W03
	.byte VOL, 9
	.byte PAN, c_v+20
	.byte W03
	.byte VOL, 11
	.byte PAN, c_v+17
	.byte W03
	.byte VOL, 15
	.byte PAN, c_v+15
	.byte W03
	.byte VOL, 19
	.byte PAN, c_v+12
	.byte W03
	.byte VOL, 24
	.byte PAN, c_v+10
	.byte W03
	.byte VOL, 32
	.byte PAN, c_v+7
	.byte W03
	.byte VOL, 39
	.byte PAN, c_v+5
	.byte W03
	.byte VOL, 49
	.byte PAN, c_v+2
	.byte W03
	.byte VOL, 62
	.byte PAN, c_v
	.byte W60
	.byte W96
	.byte W96
	.byte W72
	.byte EOT

	.byte FINE

.align 2

track_571:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_571_0
	.word track_571_1

.align 2
