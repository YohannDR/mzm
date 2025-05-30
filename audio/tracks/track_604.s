.align 2

.global track_604

track_604_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+47
	.byte N09, Cn2, v080
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+47
	.byte N09, Cn2, v032
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+47
	.byte N09, Cn2, v012
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01
	.byte FINE

.align 2

track_604:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_604_0

.align 2
