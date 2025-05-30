.align 2

.global track_142

track_142_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 59
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N30, Cn3, v060
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+18 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+26 @ BEND
	.byte W02
	.byte c_v+29 @ BEND
	.byte W02
	.byte c_v+32 @ BEND
	.byte W06
	.byte VOICE, 17
	.byte VOL, 74
	.byte BEND, c_v
	.byte TIE, Cn3, v100
	.byte W01
track_142_lbl_20bcf5:
	.byte W64
	.byte W01
	.byte W30
	.byte GOTO
		.word track_142_lbl_20bcf5
	.byte W01
	.byte EOT, Cn3 @ v100
	.byte FINE

.align 2

track_142:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_142_0

.align 2
