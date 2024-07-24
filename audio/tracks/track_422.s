.align 2

.global track_422

track_422_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W16
	.byte VOICE, 8
	.byte VOL, 25
	.byte PAN, c_v-14
	.byte BENDR, 8
	.byte BEND, c_v-63
	.byte N13
	.byte An3, En7
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte CnM2
	.byte W23
	.byte Cs0
	.byte BEND, c_v
	.byte N13
	.byte An3, Gs5
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_422:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_422_0

.align 2
