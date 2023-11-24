.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_467

track_467_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte MOD, 0
	.byte VOL, 15
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-63
	.byte N60
	.byte An3, Cn5
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
	.byte W01

	.byte FINE

track_467_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte MOD, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N60
	.byte Fn2, Gs5
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
	.byte W01

	.byte FINE

.align 2

track_467:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word voice_group12
	.word track_467_0
	.word track_467_1

.align 2
