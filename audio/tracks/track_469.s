.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_469

track_469_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
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
	.byte W02
	.byte DsM2
	.byte W02
	.byte DnM2
	.byte W02
	.byte CnM2
	.byte W16

	.byte FINE

track_469_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N40
	.byte Cn4, En6
	.byte W03
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v-62
	.byte W01
	.byte DsM2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte DnM2
	.byte BEND, c_v-60
	.byte W01
	.byte FnM2
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-57
	.byte W02
	.byte GsM2
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-55
	.byte W01
	.byte AsM2
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-53
	.byte W01
	.byte CsM1
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v
	.byte W01
	.byte Cs5
	.byte W01
	.byte As6
	.byte W01
	.byte Gn8
	.byte W09
	.byte N12
	.byte Cn4, En1
	.byte W12
	.byte Cn4, CnM1
	.byte W32
	.byte W03

	.byte FINE

.align 2

track_469:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word voice_group12
	.word track_469_0
	.word track_469_1

.align 2
