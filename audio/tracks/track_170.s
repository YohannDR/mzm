.align 2

.global track_170

track_170_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte W05
	.byte N05, Gn4, v100
	.byte W32
	.byte W02
	.byte FINE

track_170_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 25
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N18, Cn4, v052
	.byte W12
	.byte BEND, c_v
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-36 @ BEND
	.byte W01
	.byte c_v-42 @ BEND
	.byte W01
	.byte c_v-47 @ BEND
	.byte W01
	.byte c_v-50 @ BEND
	.byte W21
	.byte FINE

track_170_2:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N24, Fn2, v080
	.byte W01
	.byte BEND, c_v-23
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte 8 @ VOL
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-33
	.byte W01
	.byte c_v-49 @ BEND
	.byte W15
	.byte FINE

.align 2

track_170:
	.byte 3
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_170_0
	.word track_170_1
	.word track_170_2

.align 2
