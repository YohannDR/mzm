.align 2

.global track_147

track_147_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N16
	.byte An2, Gs4
	.byte W04
	.byte VOL, 36
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte Gs0
	.byte W01
	.byte Fs0
	.byte W01
	.byte Ds0
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 25
	.byte W01
	.byte AsM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte DnM1
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte FnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_147:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_147_0

.align 2
