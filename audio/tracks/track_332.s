.align 2

.global track_332

track_332_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 37
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03, Cn3, v092
	.byte W03
	.byte VOICE, 8
	.byte VOL, 18
	.byte BENDR, 10
	.byte N24, An1, v092, 1
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte 33 @ VOL
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte 18 @ VOL
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte 10 @ VOL
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte 6 @ VOL
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W15
	.byte FINE

track_332_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W02
	.byte N12, An2, v080
	.byte W40
	.byte FINE

.align 2

track_332:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_332_0
	.word track_332_1

.align 2
