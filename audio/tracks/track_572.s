.align 2

.global track_572

track_572_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 62
	.byte PAN, c_v
	.byte N13
	.byte Cn3, Gs4
	.byte W13
	.byte Cn3, Gs0
	.byte W13
	.byte Cn3, CnM1
	.byte W13

	.byte FINE

track_572_1:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 39
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-63
	.byte N23
	.byte An1, Gs4
	.byte N23
	.byte Cn2
	.byte W01
	.byte BEND, c_v-54
	.byte W01
	.byte FsM1
	.byte W01
	.byte Ds0
	.byte W01
	.byte Cn1
	.byte W01
	.byte An1
	.byte W01
	.byte Fn2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Gn4
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
	.byte FsM1
	.byte W01
	.byte CsM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
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
