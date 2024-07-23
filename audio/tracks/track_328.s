.align 2

.global track_328

track_328_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 28
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+13
	.byte W04
	.byte N22
	.byte Cn3, Gs4
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte Bn1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Fs1
	.byte W01
	.byte An3
	.byte W01
	.byte Bn5
	.byte W02
	.byte An5
	.byte W01
	.byte Fs5
	.byte W01
	.byte En5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Gn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte En4
	.byte W01
	.byte Fn4
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte CnM2
	.byte BEND, c_v+1

	.byte FINE

.align 2

track_328:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_328_0

.align 2
