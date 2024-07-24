.align 2

.global track_621

track_621_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+47
	.byte N09
	.byte Gn2, En6
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+47
	.byte N09
	.byte Gn2, Cn2
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+47
	.byte N09
	.byte Gn2, GsM1
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01

	.byte FINE

.align 2

track_621:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group4
	.word track_621_0

.align 2
