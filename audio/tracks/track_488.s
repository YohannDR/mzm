.align 2

.global track_488

track_488_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-40
	.byte N19, Cn2, v100
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+61
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+63
	.byte W01
	.byte c_v+62 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-16
	.byte W01
	.byte FINE

track_488_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N19, Fn1, v120
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W06
	.byte 110 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_488_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 110
	.byte PAN, c_v
	.byte N05, Gn2, v120
	.byte W05
	.byte FINE

.align 2

track_488:
	.byte 3
	.byte 0
	.byte 196
	.byte 0
	.word voice_group13
	.word track_488_0
	.word track_488_1
	.word track_488_2

.align 2
