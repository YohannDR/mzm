.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_335

track_335_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v-32
	.byte W08
	.byte N24
	.byte Fn2, En6, CsM2
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-30
	.byte W02
	.byte VOL, 8
	.byte BEND, c_v-27
	.byte W02
	.byte VOL, 14
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v-22
	.byte W02
	.byte VOL, 24
	.byte BEND, c_v-20
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 23
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v-12
	.byte W02
	.byte VOL, 10
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v

	.byte FINE

.align 2

track_335:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_335_0

.align 2
