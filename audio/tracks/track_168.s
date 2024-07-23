.align 2

.global track_168

track_168_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 127
	.byte PAN, c_v
	.byte N05
	.byte Cn5, En3
	.byte W05
	.byte N24
	.byte Cn6, En3, DnM2
	.byte W90
	.byte W01
	.byte W05

	.byte FINE

.align 2

track_168:
	.byte 1
	.byte 0
	.byte 255
	.byte 0
	.word voice_group19
	.word track_168_0

.align 2
