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
	.byte N24
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-60
	.byte W01
	.byte AnM2
	.byte W01
	.byte DsM1
	.byte W01
	.byte BnM1
	.byte W01
	.byte An0
	.byte W01
	.byte Bn1
	.byte W01
	.byte Gn3
	.byte W01
	.byte Cn6
	.byte W01
	.byte Bn6
	.byte W01
	.byte Ds7
	.byte W01
	.byte Cn7
	.byte W01
	.byte Fn6
	.byte W01
	.byte Fs5
	.byte W01
	.byte Fn4
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
	.byte N30
	.byte Fn3, Cn3
	.byte W12
	.byte BEND, c_v-19
	.byte W03
	.byte VOL, 69
	.byte W01
	.byte Fs3
	.byte W01
	.byte En3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Bn2
	.byte W01
	.byte An2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Cs2
	.byte W01
	.byte An1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Cs0
	.byte W01
	.byte DnM1
	.byte W01
	.byte GsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte CnM2
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
