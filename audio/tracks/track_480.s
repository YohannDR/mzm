.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_480

track_480_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 0
	.byte VOL, 15
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N60
	.byte An3, Gs6
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-59
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-55
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-50
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v-38
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v-34
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 56
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-8
	.byte W02
	.byte Cn3
	.byte W02
	.byte En3
	.byte W02
	.byte VOL, 60
	.byte W02
	.byte Bn2
	.byte W02
	.byte Gn2
	.byte W02
	.byte Gs1
	.byte W02
	.byte Bn0
	.byte W02
	.byte Ds0
	.byte W02
	.byte AsM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte AsM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte FnM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W36
	.byte W01
	.byte W10

	.byte FINE

track_480_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte N60
	.byte Fn2, En7
	.byte W02
	.byte VOL, 2
	.byte W02
	.byte DsM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte BnM2
	.byte W02
	.byte DnM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte Dn0
	.byte W02
	.byte Bn0
	.byte W02
	.byte Cn2
	.byte W02
	.byte Dn3
	.byte W18
	.byte En2
	.byte W02
	.byte Gs1
	.byte W02
	.byte Cs1
	.byte W02
	.byte Fn0
	.byte W02
	.byte Cn0
	.byte W02
	.byte GnM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W36
	.byte W01
	.byte W10

	.byte FINE

track_480_2:
	.byte KEYSH, 0
	.byte W30
	.byte VOICE, 8
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 8
	.byte PRIO, 25
	.byte BEND, c_v-63
	.byte N28
	.byte Cn3, En6
	.byte W01
	.byte BEND, c_v-58
	.byte W01
	.byte AsM2
	.byte W01
	.byte DsM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte Cn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte As0
	.byte W01
	.byte Dn1
	.byte W01
	.byte Gn1
	.byte W01
	.byte Cn2
	.byte W01
	.byte En2
	.byte W01
	.byte An2
	.byte W01
	.byte Dn3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Bn3
	.byte W01
	.byte En4
	.byte W01
	.byte Gs4
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fs5
	.byte W01
	.byte As5
	.byte W01
	.byte Ds6
	.byte W01
	.byte Gs6
	.byte W01
	.byte Cn7
	.byte W01
	.byte Fn7
	.byte W01
	.byte As7
	.byte W01
	.byte Dn8
	.byte W01
	.byte Gn8
	.byte W36
	.byte W03
	.byte W10

	.byte FINE

track_480_3:
	.byte KEYSH, 0
	.byte W30
	.byte VOICE, 7
	.byte VOL, 70
	.byte PAN, c_v
	.byte N72
	.byte Cn3, En3
	.byte W42
	.byte W01
	.byte VOL, 70
	.byte W02
	.byte Bn2
	.byte W02
	.byte Dn2
	.byte W02
	.byte Fn1
	.byte W02
	.byte Bn0
	.byte W02
	.byte Fn0
	.byte W02
	.byte BnM1
	.byte W02
	.byte GnM1
	.byte W02
	.byte DnM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GsM2
	.byte W02
	.byte GnM2
	.byte W01
	.byte W01
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W05

	.byte FINE

.align 2

track_480:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group12
	.word track_480_0
	.word track_480_1
	.word track_480_2
	.word track_480_3

.align 2
