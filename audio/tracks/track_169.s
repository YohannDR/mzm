.align 2

.global track_169

track_169_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N05, Cn3, v064
	.byte W05
	.byte N24, Cn4, v064, 2
	.byte W90
	.byte W01
	.byte W05
	.byte FINE

.align 2

track_169:
	.byte 1
	.byte 0
	.byte 255
	.byte 0
	.word voice_group19
	.word track_169_0

.align 2
