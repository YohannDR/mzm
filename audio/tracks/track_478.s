.align 2

.global track_478

track_478_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 6
	.byte N32
	.byte Cn3, Gs4
	.byte W06
	.byte BEND, c_v
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+4
	.byte W01
	.byte Cs4
	.byte W01
	.byte Ds4
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 72
	.byte BEND, c_v-5
	.byte W02
	.byte An2
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-4
	.byte W01
	.byte Gs3
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 67
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+8
	.byte W01
	.byte An3
	.byte W01
	.byte En3

	.byte FINE

.align 2

track_478:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group12
	.word track_478_0

.align 2
