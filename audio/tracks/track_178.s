.align 2

.global track_178

track_178_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 51
	.byte PAN, c_v-14
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N30
	.byte Cn2, Gs4, CsM2
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v-3
	.byte W01
	.byte Gn4
	.byte W01
	.byte As5
	.byte W01
	.byte Gs6
	.byte W01
	.byte Dn7
	.byte W01
	.byte En7
	.byte W01
	.byte Ds7
	.byte W01
	.byte Cn7
	.byte W01
	.byte Gn6
	.byte W01
	.byte Cs6
	.byte W01
	.byte Gn5
	.byte W01
	.byte Gn4
	.byte W01
	.byte Gn3
	.byte W01
	.byte An2
	.byte W01
	.byte Cs2
	.byte W01
	.byte En1
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-60
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_178:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_178_0

.align 2
