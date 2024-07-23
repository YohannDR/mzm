.align 2

.global track_416

track_416_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 40
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 40
	.byte BEND, c_v-63
	.byte N16
	.byte An3, Cn3
	.byte W03
	.byte BEND, c_v-50
	.byte W03
	.byte Dn0
	.byte W03
	.byte Ds1
	.byte W03
	.byte Ds2
	.byte W03
	.byte En3
	.byte W01
	.byte LFOS, 0
	.byte N05
	.byte Fn4, En6
	.byte W05

	.byte FINE

track_416_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 8
	.byte W16
	.byte BEND, c_v-63
	.byte N54
	.byte An2, En6
	.byte W03
	.byte BEND, c_v-56
	.byte W03
	.byte DsM1
	.byte W03
	.byte AsM1
	.byte W03
	.byte Fs0
	.byte W03
	.byte Cs1
	.byte W03
	.byte Gs1
	.byte W03
	.byte Ds2
	.byte W03
	.byte As2
	.byte W03
	.byte Fn3
	.byte W03
	.byte Cn4
	.byte W03
	.byte Gn4
	.byte W03
	.byte Ds5
	.byte W03
	.byte As5
	.byte W03
	.byte Fn6
	.byte W03
	.byte Cn7
	.byte W03
	.byte Gn7
	.byte W03
	.byte Dn8
	.byte W03

	.byte FINE

.align 2

track_416:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word voice_group8
	.word track_416_0
	.word track_416_1

.align 2
