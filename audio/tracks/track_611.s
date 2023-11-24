.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_611

track_611_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 49
	.byte VOL, 78
	.byte PAN, c_v
	.byte N04
	.byte Cn4, En6
	.byte W04
	.byte As4
	.byte W04
	.byte Gs4
	.byte W04
	.byte Dn4
	.byte W04
	.byte Fs4
	.byte W04

	.byte FINE

track_611_1:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 48
	.byte VOL, 79
	.byte PAN, c_v
	.byte BENDR, 6
	.byte VOL, 77
	.byte BEND, c_v-1
	.byte N20
	.byte Cn3, Cn8
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 54
	.byte W01
	.byte Cn2
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 32
	.byte W01

	.byte FINE

.align 2

track_611:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word voice_group3
	.word track_611_0
	.word track_611_1

.align 2
