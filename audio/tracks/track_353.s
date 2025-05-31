.align 2

.global track_353

track_353_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte W01
	.byte BEND, c_v-32
	.byte W01
	.byte BENDR, 12
	.byte W01
	.byte PAN, c_v
	.byte W01
	.byte VOL, 29
	.byte W04
	.byte N30, Cn3, v080
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 58
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-23
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 74
	.byte BEND, c_v+1
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+26 @ BEND
	.byte W02
	.byte c_v+27 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte VOL, 74
	.byte BEND, c_v
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte 38 @ VOL
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 29
	.byte W01
	.byte 23 @ VOL
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 18
	.byte W32
	.byte FINE

track_353_1:
	.byte KEYSH, 0
	.byte W05
	.byte VOICE, 15
	.byte W01
	.byte BENDR, 12
	.byte W01
	.byte PAN, c_v
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte PRIO, 87
	.byte W07
	.byte N24, Gn3, v072
	.byte W02
	.byte BEND, c_v-45
	.byte W02
	.byte c_v-41 @ BEND
	.byte W02
	.byte c_v-35 @ BEND
	.byte W02
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-15 @ BEND
	.byte W02
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W02
	.byte c_v+39 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W32
	.byte FINE

.align 2

track_353:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_353_0
	.word track_353_1

.align 2
