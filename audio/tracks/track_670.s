.align 2

.global track_670

track_670_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N30
	.byte Cn3, En6
	.byte W30

	.byte FINE

.align 2

track_670:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_670_0

.align 2
