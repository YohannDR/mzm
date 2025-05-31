.align 2

.global track_236

track_236_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 0
	.byte PAN, c_v
	.byte W07
	.byte N18, Cn3, v052
	.byte W03
	.byte VOL, 53
	.byte W15
	.byte FINE

track_236_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 66
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N10, Cn3, v080
	.byte W10
	.byte VOICE, 24
	.byte VOL, 40
	.byte BENDR, 12
	.byte N19, Ds3, v052
	.byte W07
	.byte VOL, 13
	.byte BEND, c_v-11
	.byte W07
	.byte VOL, 3
	.byte BEND, c_v-21
	.byte W05
	.byte FINE

.align 2

track_236:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word voice_group2
	.word track_236_0
	.word track_236_1

.align 2
