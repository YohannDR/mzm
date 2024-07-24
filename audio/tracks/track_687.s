.align 2

.global track_687

track_687_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 120
	.byte PAN, c_v
	.byte N21
	.byte Cn3, Gn8
	.byte W21

	.byte FINE

track_687_1:
	.byte KEYSH, 0
	.byte VOICE, 18
	.byte VOL, 85
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W10
	.byte N15
	.byte Cn3, En6
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte An3
	.byte W01
	.byte Fn4
	.byte W01
	.byte Gn3
	.byte W01
	.byte Cs2
	.byte W01
	.byte Ds1
	.byte W01
	.byte Bn1
	.byte W01
	.byte Bn2
	.byte W01
	.byte Cn4
	.byte W01
	.byte Cs4
	.byte W01
	.byte Cs3
	.byte W01
	.byte Dn2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Cn3
	.byte W09
	.byte N20
	.byte Cn3, Cn3
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte Fn3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Fs4
	.byte W01
	.byte Gs4
	.byte W01
	.byte Fn4
	.byte W01
	.byte Bn1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Ds3
	.byte W01
	.byte Cn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte Dn4
	.byte W01
	.byte Ds3
	.byte W01
	.byte En3
	.byte W01
	.byte Fn3
	.byte W01
	.byte Gn3
	.byte W01
	.byte An3
	.byte W01
	.byte Cn4
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
