.align 2

.global track_698

track_698_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 0
	.byte PAN, c_v-14
	.byte BENDR, 18
	.byte PRIO, 1
	.byte W02
	.byte BEND, c_v+32
	.byte N16
	.byte Cn3, Gs5
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte FsM1
	.byte W01
	.byte Ds1
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

track_698_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 0
	.byte PAN, c_v-14
	.byte BENDR, 18
	.byte W02
	.byte BEND, c_v+32
	.byte N16
	.byte Fn3, En6
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte FsM1
	.byte W01
	.byte Ds1
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_698:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group3
	.word track_698_0
	.word track_698_1

.align 2
