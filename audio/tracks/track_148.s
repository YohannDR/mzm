.align 2

.global track_148

track_148_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 22
	.byte PAN, c_v
	.byte BENDR, 3
	.byte BEND, c_v-32
	.byte N16
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+15
	.byte W01

	.byte FINE

.align 2

track_148:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_148_0

.align 2
