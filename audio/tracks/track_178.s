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
	.byte N30, Cn2, v080, 1
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
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+40 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
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
