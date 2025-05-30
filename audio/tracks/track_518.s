.align 2

.global track_518

track_518_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W08
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13, Cn3, v080
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte N06, Gn3, v032
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_518_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+47
	.byte N09, An2, v060
	.byte W01
	.byte BEND, c_v+35
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-47
	.byte W01
	.byte FINE

.align 2

track_518:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_518_0
	.word track_518_1

.align 2
