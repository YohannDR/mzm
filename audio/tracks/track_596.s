.align 2

.global track_596

track_596_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte MOD, 12
	.byte VOL, 120
	.byte PAN, c_v
	.byte LFOS, 100
	.byte PRIO, 25
	.byte W01
	.byte N05, Gn2, v080
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W09
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W06
	.byte N05 @ Gn2, v080
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W09
	.byte Fn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W05
	.byte N05 @ Gn2, v080
	.byte W06
	.byte En2, v100 @ N05
	.byte W08
	.byte Fn2, v092 @ N05
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W07
	.byte Gn2, v080 @ N05
	.byte W07
	.byte N05 @ Gn2, v080
	.byte W03
	.byte W02
	.byte Fn2, v100 @ N05
	.byte W09
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W06
	.byte N05 @ Gn2, v080
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W05
	.byte FINE

.align 2

track_596:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group4
	.word track_596_0

.align 2
