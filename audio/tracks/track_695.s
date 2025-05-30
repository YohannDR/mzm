.align 2

.global track_695

track_695_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Cn3, v080
	.byte W05
	.byte En3 @ N05, v080
	.byte W05
	.byte Gn3, v064 @ N05
	.byte W06
	.byte An3, v032 @ N05
	.byte W07
	.byte Bn3, v020 @ N05
	.byte W05
	.byte FINE

track_695_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, c_v-14
	.byte W04
	.byte N05, Gn3, v127
	.byte W05
	.byte Gs3 @ N05, v127
	.byte W05
	.byte An3, v088 @ N05
	.byte W06
	.byte An3, v044 @ N05
	.byte W07
	.byte Cn4, v032 @ N05
	.byte W05
	.byte FINE

.align 2

track_695:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_695_0
	.word track_695_1

.align 2
