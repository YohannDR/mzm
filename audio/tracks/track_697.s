.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_697

track_697_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 0
	.byte PAN, c_v-14
	.byte BENDR, 18
	.byte PRIO, 1
	.byte W06
	.byte VOL, 0
	.byte BEND, c_v-47
	.byte N16
	.byte Cn3, Cn7
	.byte W01
	.byte VOL, 28
	.byte W01
	.byte Dn1
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-8
	.byte W01
	.byte Gn3
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

track_697_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 0
	.byte PAN, c_v-14
	.byte BENDR, 18
	.byte W06
	.byte VOL, 0
	.byte BEND, c_v-47
	.byte N16
	.byte Fn3, Cn7
	.byte W01
	.byte VOL, 28
	.byte W01
	.byte Dn1
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-8
	.byte W01
	.byte Gn3
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+32
	.byte W01

	.byte FINE

.align 2

track_697:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voice_group3
	.word track_697_0
	.word track_697_1

.align 2
