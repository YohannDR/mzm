.align 2

.global track_390

track_390_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 26
	.byte BEND, c_v
	.byte N20
	.byte En3, Gs4
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte Cs1
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-16
	.byte W01

	.byte FINE

.align 2

track_390:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_390_0

.align 2
