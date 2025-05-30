.align 2

.global track_511

track_511_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 10
	.byte W04
	.byte BEND, c_v-63
	.byte N17, An1, v052
	.byte N17, En3, v040
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

track_511_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 28
	.byte PAN, c_v
	.byte N02, Fn3, v080
	.byte W02
	.byte Dn3 @ N02, v080
	.byte W02
	.byte An3 @ N02, v080
	.byte W02
	.byte Cn4 @ N02, v080
	.byte W04
	.byte Cn4, v032 @ N02
	.byte W04
	.byte Cn4, v012 @ N02
	.byte W02
	.byte FINE

.align 2

track_511:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_511_0
	.word track_511_1

.align 2
