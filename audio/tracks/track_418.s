.align 2

.global track_418

track_418_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 86
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N24, Cn3, v080
	.byte W01
	.byte BEND, c_v-60
	.byte W01
	.byte c_v-55 @ BEND
	.byte W01
	.byte c_v-49 @ BEND
	.byte W01
	.byte c_v-41 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W02
	.byte VOL, 54
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

track_418_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 69
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N30, Fn3, v060
	.byte W12
	.byte BEND, c_v-19
	.byte W03
	.byte VOL, 69
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_418:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group8
	.word track_418_0
	.word track_418_1

.align 2
