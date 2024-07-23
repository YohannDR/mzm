.align 2

.global track_617

track_617_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 0
	.byte PAN, c_v
	.byte W13
	.byte MOD, 40
	.byte VOL, 9
	.byte BENDR, 10
	.byte LFOS, 40
	.byte BEND, c_v-49
	.byte N48
	.byte Gs2, Gn8
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 15
	.byte BEND, c_v-36
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 23
	.byte W02
	.byte GnM1
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 15
	.byte W02
	.byte CnM1
	.byte BEND, c_v-11
	.byte W02
	.byte VOL, 10
	.byte W02
	.byte GsM2
	.byte W02
	.byte FsM2
	.byte W02
	.byte FnM2
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 4
	.byte W02
	.byte DsM2
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 2
	.byte W02
	.byte CsM2
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte CnM2
	.byte BEND, c_v-19
	.byte W01

	.byte FINE

.align 2

track_617:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_617_0

.align 2
