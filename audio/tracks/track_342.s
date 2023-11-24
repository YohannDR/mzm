.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_342

track_342_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N19
	.byte Bn1, Cn4
	.byte W02
	.byte BEND, c_v-22
	.byte W02
	.byte Ds0
	.byte W02
	.byte FsM1
	.byte W02
	.byte BnM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DsM2
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte AsM1
	.byte BEND, c_v-63
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte GnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W32
	.byte W03

	.byte FINE

track_342_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte PAN, c_v
	.byte PRIO, 2
	.byte W02
	.byte VOL, 62
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N11
	.byte An4, En6
	.byte W01
	.byte BEND, c_v-4
	.byte W01
	.byte Gs2
	.byte W01
	.byte En2
	.byte W01
	.byte Cn2
	.byte W44
	.byte W03

	.byte FINE

.align 2

track_342:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_342_0
	.word track_342_1

.align 2
