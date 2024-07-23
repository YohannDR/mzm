.align 2

.global track_393

track_393_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 39
	.byte VOL, 16
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v-47
	.byte N13
	.byte Gs1, Gs4
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte CsM1
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01

	.byte FINE

.align 2

track_393:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_393_0

.align 2
