.align 2

.global track_261

track_261_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 51
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03, En3, v080
	.byte W03
	.byte VOICE, 36
	.byte VOL, 20
	.byte BENDR, 12
	.byte N12, Fn3 @ v080
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_261:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group2
	.word track_261_0

.align 2
