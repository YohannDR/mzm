.align 2

.global track_489

track_489_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-40
	.byte N15
	.byte Cn2, En6
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte Dn6
	.byte W01
	.byte Gn7
	.byte W01
	.byte En8
	.byte W01
	.byte Gn8
	.byte W01
	.byte Fn8
	.byte W01
	.byte Cs8
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v-40
	.byte N15
	.byte Cn2, Cn3
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte Dn6
	.byte W01
	.byte Gn7
	.byte W01
	.byte En8
	.byte W01
	.byte Gn8
	.byte W01
	.byte Fn8
	.byte W01
	.byte Cs8
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v-40
	.byte N15
	.byte Cn2, GsM1
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte Dn6
	.byte W01
	.byte Gn7
	.byte W01
	.byte En8
	.byte W01
	.byte Gn8
	.byte W01
	.byte Fn8
	.byte W01
	.byte Cs8
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-16
	.byte W19

	.byte FINE

track_489_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 113
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15
	.byte Fn1, Cn8
	.byte W15
	.byte Fn1, Gs0
	.byte W15
	.byte Fn1, CnM1
	.byte W32
	.byte W01

	.byte FINE

track_489_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 71
	.byte N10
	.byte Gn2, Cn8
	.byte W15
	.byte Gn2, Gs4
	.byte W15
	.byte Gn2, En1
	.byte W32
	.byte W01

	.byte FINE

.align 2

track_489:
	.byte 3
	.byte 0
	.byte 180
	.byte 0
	.word voice_group13
	.word track_489_0
	.word track_489_1
	.word track_489_2

.align 2
