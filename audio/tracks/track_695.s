.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_695

track_695_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte W04
	.byte N05
	.byte Cn3, Gs4
	.byte W05
	.byte En3
	.byte W05
	.byte Gn3, En3
	.byte W06
	.byte An3, Gs0
	.byte W07
	.byte Bn3, GsM1
	.byte W05

	.byte FINE

track_695_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, c_v-14
	.byte W04
	.byte N05
	.byte Gn3, Gn8
	.byte W05
	.byte Gs3
	.byte W05
	.byte An3, En5
	.byte W06
	.byte An3, Gs1
	.byte W07
	.byte Cn4, Gs0
	.byte W05

	.byte FINE

.align 2

track_695:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group4
	.word track_695_0
	.word track_695_1

.align 2
