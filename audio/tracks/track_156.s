.align 2

.global track_156

track_156_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Fn3, v100
	.byte W02
	.byte VOL, 30
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W04
	.byte VOICE, 45
	.byte VOL, 40
	.byte N03, Fn3, v080
	.byte W03
	.byte FINE

.align 2

track_156:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_156_0

.align 2
