.align 2

.global track_452

track_452_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v-20
	.byte BENDR, 14
	.byte W08
	.byte BEND, c_v-47
	.byte N32
	.byte Cn3, En7, DsM2
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte AsM1
	.byte W01
	.byte Cs0
	.byte W01
	.byte En0
	.byte W01
	.byte Gn0
	.byte W01
	.byte As0
	.byte W01
	.byte Cn1
	.byte W01
	.byte Ds1
	.byte W01
	.byte Fs1
	.byte W01
	.byte An1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Fs2
	.byte W01
	.byte Gs2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Fn3
	.byte W01
	.byte Gs3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Cs4
	.byte W01
	.byte En4
	.byte W01
	.byte Gn4
	.byte W01
	.byte As4
	.byte W01
	.byte Cs5
	.byte W01
	.byte En5
	.byte W01
	.byte Gn5
	.byte W01
	.byte An5
	.byte W01
	.byte Cn6
	.byte W01
	.byte Ds6
	.byte W01
	.byte Fs6
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 0
	.byte W01

	.byte FINE

.align 2

track_452:
	.byte 1
	.byte 0
	.byte 203
	.byte 0
	.word voice_group10
	.word track_452_0

.align 2
