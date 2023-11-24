.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_604

track_604_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+47
	.byte N09
	.byte Cn2, Gs4
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+47
	.byte N09
	.byte Cn2, Gs0
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+47
	.byte N09
	.byte Cn2, CnM1
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte Gn4
	.byte W01
	.byte En3
	.byte W01
	.byte Cn2
	.byte W01
	.byte Gs0
	.byte W01
	.byte Cn2
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+16
	.byte W01

	.byte FINE

.align 2

track_604:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_604_0

.align 2
