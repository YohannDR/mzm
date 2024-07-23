.align 2

.global track_380

track_380_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N09
	.byte En3, Gs4
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+23
	.byte W01
	.byte Bn5
	.byte W01
	.byte Gn6
	.byte W01
	.byte Ds7
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+63
	.byte W01

	.byte FINE

.align 2

track_380:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_380_0

.align 2
