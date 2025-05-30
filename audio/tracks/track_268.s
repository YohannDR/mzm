.align 2

.global track_268

track_268_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16, Cn3, v080
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+24
	.byte W01
	.byte FINE

.align 2

track_268:
	.byte 1
	.byte 0
	.byte 221
	.byte 128
	.word voice_group4
	.word track_268_0

.align 2
