.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_559

track_559_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N15
	.byte Cn3, En7
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-29
	.byte W01
	.byte Ds1
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

track_559_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v-47
	.byte N15
	.byte Cn5, Gs3
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-29
	.byte W01
	.byte Ds1
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

.align 2

track_559:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group17
	.word track_559_0
	.word track_559_1

.align 2
