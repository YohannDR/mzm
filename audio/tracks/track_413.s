.align 2

.global track_413

track_413_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 44
	.byte PAN, c_v
	.byte N15, An2, v092
	.byte W15
	.byte VOICE, 4
	.byte N09, Bn2, v088
	.byte W09
	.byte VOICE, 5
	.byte N15, An2, v092
	.byte W15
	.byte VOICE, 4
	.byte N09, Bn2, v088
	.byte W09
	.byte FINE

.align 2

track_413:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group6
	.word track_413_0

.align 2
