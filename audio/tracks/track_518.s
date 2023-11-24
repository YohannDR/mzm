.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_518

track_518_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W08
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte N13
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte Cs0
	.byte W01
	.byte Cs1
	.byte W01
	.byte Cs1
	.byte W01
	.byte En0
	.byte N06
	.byte Gn3, Gs0
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte FsM1
	.byte W01
	.byte DsM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_518_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+47
	.byte N09
	.byte An2, Cn3
	.byte W01
	.byte BEND, c_v+35
	.byte W01
	.byte En5
	.byte W01
	.byte En4
	.byte W01
	.byte En3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-47
	.byte W01

	.byte FINE

.align 2

track_518:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group16
	.word track_518_0
	.word track_518_1

.align 2
