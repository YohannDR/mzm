.align 2

.global track_154

track_154_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 40
	.byte PAN, c_v
	.byte N03, Gn3, v100
	.byte W03
	.byte FINE

.align 2

track_154:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voice_group1
	.word track_154_0

.align 2
