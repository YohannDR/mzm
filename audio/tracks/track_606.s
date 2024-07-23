.align 2

.global track_606

track_606_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N30
	.byte Gn2, Gs4
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte DnM1
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte En1
	.byte BEND, c_v-51
	.byte W02
	.byte AsM1
	.byte W02
	.byte Cs1
	.byte W02
	.byte En1
	.byte W02
	.byte Cs1
	.byte W02
	.byte Gn0
	.byte W02
	.byte BnM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte CsM1
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte Fs0
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte EnM1
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte GsM2
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte DnM2
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_606:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_606_0

.align 2
