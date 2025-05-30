.align 2

.global track_701

track_701_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v-63
	.byte N78, Fn2, v100, 1
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W02
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+28 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-62
	.byte W01
	.byte VOL, 0
	.byte W28
	.byte 0 @ VOL
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-54
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_701:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group8
	.word track_701_0

.align 2
