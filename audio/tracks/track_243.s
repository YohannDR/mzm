.align 2

.global track_243

track_243_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 56
	.byte PAN, c_v
	.byte N28, Cn3, v076
	.byte W21
	.byte VOL, 56
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W02
	.byte FINE

track_243_1:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 49
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte W01
	.byte N07, Fn2, v052
	.byte W01
	.byte BEND, c_v+52
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOICE, 24
	.byte VOL, 67
	.byte N09, Bn2, v080
	.byte W09
	.byte An2, v020 @ N09
	.byte W09
	.byte Gn2, v012 @ N09
	.byte W09
	.byte FINE

.align 2

track_243:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_243_0
	.word track_243_1

.align 2
