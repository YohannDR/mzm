.align 2

.global track_337

track_337_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N24, Fn1, v080
	.byte W04
	.byte BEND, c_v+28
	.byte W05
	.byte c_v-8 @ BEND
	.byte W07
	.byte VOL, 40
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_337:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_337_0

.align 2
