.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_383

track_383_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v-63
	.byte N11
	.byte Cn3, En7
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v
	.byte W01
	.byte VOICE, 17
	.byte MOD, 45
	.byte VOL, 50
	.byte LFOS, 127
	.byte BEND, c_v
	.byte N05
	.byte Cn3, En6
	.byte W05
	.byte N07
	.byte W07
	.byte N03
	.byte W03
	.byte N05
	.byte Cn3, Cn3
	.byte W05

	.byte FINE

.align 2

track_383:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_383_0

.align 2
