.align 2

.global track_156

track_156_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05
	.byte Fn3, En6
	.byte W02
	.byte VOL, 30
	.byte W01
	.byte GsM1
	.byte W01
	.byte AsM2
	.byte W04
	.byte VOICE, 45
	.byte VOL, 40
	.byte N03
	.byte Fn3, Gs4
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
