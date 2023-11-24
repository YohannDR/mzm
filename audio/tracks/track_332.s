.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_332

track_332_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 37
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N03
	.byte Cn3, Gs5
	.byte W03
	.byte VOICE, 8
	.byte VOL, 18
	.byte BENDR, 10
	.byte N24
	.byte An1, Gs5, CsM2
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte An0
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte Ds0
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte FsM1
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte AsM2
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte FsM2
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W15

	.byte FINE

track_332_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W02
	.byte N12
	.byte An2, Gs4
	.byte W40

	.byte FINE

.align 2

track_332:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word voice_group3
	.word track_332_0
	.word track_332_1

.align 2
