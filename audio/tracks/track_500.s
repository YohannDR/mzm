.align 2

.global track_500

track_500_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W12
	.byte BENDR, 14
	.byte BEND, c_v-63
	.byte N24, Cn4, v040
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte c_v-52 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-30 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte VOICE, 0
	.byte VOL, 25
	.byte BEND, c_v
	.byte N04, Fn3, v060
	.byte W04
	.byte Cs4, v040 @ N04
	.byte W04
	.byte An3, v060 @ N04
	.byte W04
	.byte Bn3, v040 @ N04
	.byte W04
	.byte Gn3, v060 @ N04
	.byte W04
	.byte Fn3, v040 @ N04
	.byte W04
	.byte FINE

track_500_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13, Cn3, v080
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte N06, Gn3, v032
	.byte W01
	.byte VOL, 25
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
	.byte W01
	.byte FINE

.align 2

track_500:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_500_0
	.word track_500_1

.align 2
