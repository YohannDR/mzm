.align 2

.global track_530

track_530_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 18
	.byte PAN, c_v-10
	.byte BENDR, 8
	.byte BEND, c_v-16
	.byte N19, Fs3, v080
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_530:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_530_0

.align 2
