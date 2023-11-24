.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_269

track_269_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v
	.byte N19
	.byte Bn2, Gs4
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

	.byte FINE

.align 2

track_269:
	.byte 1
	.byte 0
	.byte 190
	.byte 128
	.word voice_group4
	.word track_269_0

.align 2
