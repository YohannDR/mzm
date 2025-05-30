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
	.byte N16, An3, v060
	.byte W03
	.byte BEND, c_v-50
	.byte W03
	.byte c_v-38 @ BEND
	.byte W03
	.byte c_v-25 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v @ BEND
	.byte W01
	.byte LFOS, 0
	.byte N05, Fn4, v100
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
	.byte N54, An2, v100
	.byte W03
	.byte BEND, c_v-56
	.byte W03
	.byte c_v-49 @ BEND
	.byte W03
	.byte c_v-42 @ BEND
	.byte W03
	.byte c_v-34 @ BEND
	.byte W03
	.byte c_v-27 @ BEND
	.byte W03
	.byte c_v-20 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v+1 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+23 @ BEND
	.byte W03
	.byte c_v+30 @ BEND
	.byte W03
	.byte c_v+37 @ BEND
	.byte W03
	.byte c_v+44 @ BEND
	.byte W03
	.byte c_v+51 @ BEND
	.byte W03
	.byte c_v+58 @ BEND
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
