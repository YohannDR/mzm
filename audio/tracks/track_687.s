.align 2

.global track_687

track_687_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 120
	.byte PAN, c_v
	.byte N21, Cn3, v127
	.byte W21
	.byte FINE

track_687_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 85
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W10
	.byte N15, Cn3, v100
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-25 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-14 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W09
	.byte N20, Cn3, v060
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte FINE

.align 2

track_687:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_687_0
	.word track_687_1

.align 2
