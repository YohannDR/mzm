.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_139

track_139_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 74
	.byte PAN, c_v
	.byte TIE
	.byte Cn3, En6
	.byte W30
	.byte W01
track_139_lbl_20bbdb:
	.byte W64
	.byte W01
	.byte GOTO
		.word track_139_lbl_20bbdb
	.byte W01
	.byte EOT

	.byte FINE

track_139_1:
	.byte KEYSH, 0
	.byte VOICE, 60
	.byte VOL, 95
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 26
	.byte BEND, c_v-47
	.byte W28
	.byte Gn0
	.byte N24
	.byte Gn3, Gn8
	.byte W01
	.byte BEND, c_v-30
	.byte W01
	.byte Cs1
	.byte W01
	.byte En1
	.byte W01
	.byte Gn1
	.byte W01
	.byte An1
	.byte W01
	.byte Cn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Fs2
	.byte W01
	.byte An2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Cn3
	.byte W01
	.byte Cs3
	.byte W01
	.byte Ds3
	.byte W01
	.byte Fs3
	.byte W01
	.byte Gs3
	.byte W01
	.byte Bn3
	.byte W01
	.byte Dn4
	.byte W01
	.byte Fn4
	.byte W01
	.byte An4
	.byte W01
	.byte Cs5
	.byte W01
	.byte Fn5
	.byte W01
	.byte An5
	.byte W01
	.byte Ds6
	.byte W44
	.byte W01

	.byte FINE

.align 2

track_139:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_139_0
	.word track_139_1

.align 2
