.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_321

track_321_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 11
	.byte BEND, c_v
	.byte N05
	.byte Cn3, Gs4
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-10
	.byte N05
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-20
	.byte N05
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-31
	.byte N05
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-37
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-41
	.byte N05
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-51
	.byte N05
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-61
	.byte W01
	.byte CsM2

	.byte FINE

.align 2

track_321:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_321_0

.align 2
