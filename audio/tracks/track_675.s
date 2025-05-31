.align 2

.global track_675

track_675_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 70
	.byte PAN, c_v+6
	.byte N15, Cn3, v100
	.byte W13
	.byte VOL, 35
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_675:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group14
	.word track_675_0

.align 2
