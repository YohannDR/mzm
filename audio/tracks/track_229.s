.align 2

.global track_229

track_229_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v+36
	.byte N16, Cn3, v080
	.byte W16
	.byte FINE

.align 2

track_229:
	.byte 1
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_229_0

.align 2
