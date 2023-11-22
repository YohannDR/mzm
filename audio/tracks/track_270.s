.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_270

track_270_0:
	.byte KEYSH, 0
	.byte TEMPO, 75

	.byte VOICE, 1
	.byte VOL, 35
	.byte PAN, c_v+0
	.byte BENDR, 12
	.byte BEND, c_v-16
	.byte TIE, An2, En6
	.byte W01

	.byte VOL, 38
	.byte BEND, c_v-14
	.byte W01

	.byte VOL, 40
	.byte BEND, c_v-12
	.byte W01

	.byte VOL, 43
	.byte BEND, c_v-10
	.byte W01

	.byte VOL, 46
	.byte BEND, c_v-8
	.byte W01

	.byte VOL, 48
	.byte BEND, c_v-6
	.byte W01

	.byte VOL, 51
	.byte BEND, c_v-4
	.byte W01

	.byte VOL, 53
	.byte BEND, c_v-2
	.byte W01

	.byte VOL, 56
	.byte BEND, c_v
	.byte W01

track_270_lbl_1:
	.byte W84
	.byte W03

	.byte GOTO
		.word track_270_lbl_1

	.byte W01
	.byte EOT, An2
	.byte FINE

.align 2

track_270:
	.byte 1
	.byte 0
	.byte 254
	.byte 0
	.word voice_group4
	.word track_270_0

.align 2
