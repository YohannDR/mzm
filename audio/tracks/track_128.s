.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_128

track_128_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N15
	.byte Dn3, Gs4
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-26
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+27
	.byte W01

	.byte FINE

.align 2

track_128:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group1
	.word track_128_0

.align 2
