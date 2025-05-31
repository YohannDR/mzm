.align 2

.global track_253

track_253_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 105
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 14
	.byte N05, Cn3, v100
	.byte W05
	.byte N14, En3, v127
	.byte W14
	.byte N13, Dn3, v052
	.byte W13
	.byte VOICE, 12
	.byte N18, Cn3, v020
	.byte W20
	.byte FINE

track_253_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 105
	.byte PAN, c_v
	.byte PRIO, 54
	.byte W04
	.byte N05, Gs2, v080
	.byte W05
	.byte N10, Gs2, v112
	.byte W44
	.byte W01
	.byte FINE

.align 2

track_253:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word voice_group5
	.word track_253_0
	.word track_253_1

.align 2
