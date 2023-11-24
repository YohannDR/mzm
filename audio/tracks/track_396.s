.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_396

track_396_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N17
	.byte Cn2, En6
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-40
	.byte W01
	.byte En0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn1
	.byte W01
	.byte En1
	.byte W01
	.byte Gs1
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte GsM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_396:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group4
	.word track_396_0

.align 2
