.align 2

.global track_121

track_121_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 50
	.byte PAN, c_v
	.byte N01, As4, v127
	.byte W01
	.byte Gs4, v064 @ N01
	.byte W01
	.byte FINE

.align 2

track_121:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_121_0

.align 2
