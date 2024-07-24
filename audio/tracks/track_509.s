.align 2

.global track_509

track_509_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v-47
	.byte N10
	.byte An2, En4
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+24
	.byte W01
	.byte Ds6
	.byte W01
	.byte Ds7
	.byte W02

	.byte FINE

.align 2

track_509:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_509_0

.align 2
