.align 2

.global track_603

track_603_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte PRIO, 1
	.byte BEND, c_v+32
	.byte W02
	.byte N20
	.byte Cn3, Cn4
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-1
	.byte W01
	.byte Gs2
	.byte W01
	.byte Dn2
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte CsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

track_603_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+32
	.byte W02
	.byte N20
	.byte Fn3, En6
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-1
	.byte W01
	.byte Gs2
	.byte W01
	.byte Dn2
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte CsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_603:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word voice_group3
	.word track_603_0
	.word track_603_1

.align 2
