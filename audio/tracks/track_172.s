.align 2

.global track_172

track_172_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 70
	.byte PAN, c_v+16
	.byte PRIO, 1
	.byte N04, Cn2, v120
	.byte W05
	.byte Dn2, v100 @ N04
	.byte W04
	.byte Cn2, v080 @ N04
	.byte W05
	.byte Bn1, v060 @ N04
	.byte W04
	.byte Cn2, v040 @ N04
	.byte W05
	.byte Dn2, v020 @ N04
	.byte W04
	.byte FINE

track_172_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v+16
	.byte W12
	.byte N32, An2, v080, 2
	.byte W20
	.byte VOL, 70
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 9 @ VOL
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

track_172_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 49
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte PRIO, 62
	.byte BEND, c_v-32
	.byte W01
	.byte N05, Fn3, v060
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, Gn3, v080
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, Fn3, v060
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, Gn3, v080
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte N05, Fn3, v060
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_172:
	.byte 3
	.byte 0
	.byte 190
	.byte 0
	.word voice_group7
	.word track_172_0
	.word track_172_1
	.word track_172_2

.align 2
