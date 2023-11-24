.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_602

track_602_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte W12
	.byte N28
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v-35
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v-22
	.byte W02
	.byte Cs2
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+23
	.byte W01
	.byte Cn6
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte GnM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

track_602_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-47
	.byte W12
	.byte N28
	.byte Fn3, En6
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-46
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v-43
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v-35
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v-22
	.byte W02
	.byte Cs2
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v+23
	.byte W01
	.byte Cn6
	.byte W01
	.byte VOL, 20
	.byte W02
	.byte GnM2
	.byte W02
	.byte EnM2
	.byte W02
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_602:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_602_0
	.word track_602_1

.align 2
