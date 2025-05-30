.align 2

.global track_145

track_145_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 44
	.byte PAN, c_v
	.byte N08, En2, v080
	.byte W08
	.byte Fn2, v100 @ N08
	.byte W08
	.byte N09, Gn2, v080
	.byte W09
	.byte N36, An2, v064, 2
	.byte W03
	.byte VOL, 52
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_145:
	.byte 1
	.byte 0
	.byte 150
	.byte 0
	.word voice_group1
	.word track_145_0

.align 2
