.align 2

.global track_609

track_609_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 36
	.byte BEND, c_v+63
	.byte N16
	.byte Cn4, Gs4
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+50
	.byte W01
	.byte Dn7
	.byte W01
	.byte As6
	.byte W01
	.byte Fn6
	.byte W01
	.byte Cs6
	.byte W01
	.byte An5
	.byte W01
	.byte Fn5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Gs4
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v
	.byte W01
	.byte VOL, 1

	.byte FINE

.align 2

track_609:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_609_0

.align 2
