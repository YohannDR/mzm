.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_279

track_279_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v
	.byte N19
	.byte Cn3, En6
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v-35
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-49
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W01
	.byte VOICE, 20
	.byte VOL, 61
	.byte BEND, c_v
	.byte N03
	.byte Cn3, Gs4
	.byte W05
	.byte N04
	.byte An2, Cn3
	.byte W04

	.byte FINE

track_279_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 31
	.byte PAN, c_v
	.byte W28
	.byte W01
	.byte N04
	.byte Cn3, Gs1
	.byte W06
	.byte N04
	.byte W06
	.byte N04
	.byte W06
	.byte N04
	.byte W06
	.byte Cn3, EnM1
	.byte W06
	.byte Cn3, GsM2
	.byte W04

	.byte FINE

.align 2

track_279:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_279_0
	.word track_279_1

.align 2
