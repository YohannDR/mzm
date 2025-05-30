.align 2

.global track_610

track_610_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 47
	.byte VOL, 51
	.byte PAN, c_v
	.byte N22, Cn3, v100
	.byte W22
	.byte FINE

.align 2

track_610:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group3
	.word track_610_0

.align 2
