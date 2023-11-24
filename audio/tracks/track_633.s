.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_633

track_633_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N18
	.byte Cn5, Cn3
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte DsM1
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte Ds0
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte Cn1
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte As0
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte Cn0
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte AnM2
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte DnM2
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 0
	.byte W02

	.byte FINE

.align 2

track_633:
	.byte 1
	.byte 0
	.byte 169
	.byte 0
	.word voice_group1
	.word track_633_0

.align 2
