.align 2

.global track_462

track_462_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 108
	.byte PAN, c_v-20
	.byte W28
	.byte TIE
	.byte Cn3, Cn8
	.byte W68
	.byte W80
	.byte W02
	.byte EOT

	.byte FINE

.align 2

track_462:
	.byte 1
	.byte 0
	.byte 225
	.byte 0
	.word voice_group10
	.word track_462_0

.align 2
