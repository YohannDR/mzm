.align 2

.global track_149

track_149_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 19
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-15
	.byte N20, An2, v100
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 29
	.byte W01
	.byte 32 @ VOL
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 34 @ VOL
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 31 @ VOL
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte 20 @ VOL
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 10 @ VOL
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte 5 @ VOL
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 2 @ VOL
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_149:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_149_0

.align 2
