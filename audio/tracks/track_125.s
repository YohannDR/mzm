.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_125

track_125_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 15
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N24
	.byte Cn5, En6
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte GsM1
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte Fs0
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 38
	.byte W01
	.byte An1
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte Dn2
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte As1
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 41
	.byte W01
	.byte Bn0
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte DsM1
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte GsM2
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte EnM2
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte CsM2
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_125:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group1
	.word track_125_0

.align 2
