.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_149

track_149_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 19
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-15
	.byte N20
	.byte An2, En6
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 29
	.byte W01
	.byte Gs0
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte As0
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte Gn0
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte GsM1
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte AsM2
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte FnM2
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte DnM2
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte BEND, c_v
	.byte W01

	.byte FINE

.align 2

track_149:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voice_group1
	.word track_149_0

.align 2
