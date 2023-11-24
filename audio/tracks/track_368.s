.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_368

track_368_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N08
	.byte Gn3, Cn3
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+7
	.byte W52
	.byte W01
	.byte N08
	.byte Gn3, En1
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+7
	.byte W05

	.byte FINE

.align 2

track_368:
	.byte 1
	.byte 0
	.byte 151
	.byte 0
	.word voice_group3
	.word track_368_0

.align 2
