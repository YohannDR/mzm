.align 2

.global track_195

track_195_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 51
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N36, En3, v080, 2
	.byte W01
	.byte BEND, c_v-45
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-39 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-35 @ BEND
	.byte W01
	.byte c_v-33 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_195:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voice_group11
	.word track_195_0

.align 2
