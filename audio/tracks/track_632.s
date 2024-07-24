.align 2

.global track_632

track_632_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N24
	.byte En6, Gs4
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte DsM1
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte BnM1
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 29
	.byte W01
	.byte As0
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte Dn1
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte Bn0
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte Dn0
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 15
	.byte W01
	.byte BnM2
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte FsM2
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte DsM2
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte CsM2
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_632:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word voice_group1
	.word track_632_0

.align 2
