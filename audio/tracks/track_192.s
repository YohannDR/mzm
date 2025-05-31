.align 2

.global track_192

track_192_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 44
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+63
	.byte N10, Dn2, v060
	.byte W01
	.byte BEND, c_v+47
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_192:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word voice_group11
	.word track_192_0

.align 2
