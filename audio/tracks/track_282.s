.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_282

track_282_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 23
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-16
	.byte TIE
	.byte Cn4, En3
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
track_282_lbl_20e12a:
	.byte W84
	.byte W03
	.byte GOTO
		.word track_282_lbl_20e12a
	.byte W01
	.byte EOT, Cn4

	.byte FINE

.align 2

track_282:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_282_0

.align 2
