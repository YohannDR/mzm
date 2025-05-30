.align 2

.global track_166

track_166_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 78
	.byte PAN, c_v
	.byte TIE, Cn3, v100
	.byte W96
	.byte W96
	.byte W48
	.byte VOL, 78
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte EOT @ Cn3, v100
	.byte FINE

.align 2

track_166:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group4
	.word track_166_0

.align 2
