.align 2

.global track_572

track_572_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 62
	.byte PAN, c_v
	.byte N13, Cn3, v080
	.byte W13
	.byte Cn3, v032 @ N13
	.byte W13
	.byte Cn3, v012 @ N13
	.byte W13
	.byte FINE

track_572_1:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 39
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-63
	.byte N23, An1, v080
	.byte N23, Cn2 @ v080
	.byte W01
	.byte BEND, c_v-54
	.byte W01
	.byte c_v-46 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-28 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-2 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_572:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_572_0
	.word track_572_1

.align 2
