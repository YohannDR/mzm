.align 2

.global track_147

track_147_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N16, An2, v080
	.byte W04
	.byte VOL, 36
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_147:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_147_0

.align 2
