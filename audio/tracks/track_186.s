.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_186

track_186_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte MOD, 14
	.byte VOL, 100
	.byte PAN, c_v-34
	.byte LFOS, 90
	.byte N08
	.byte Fs2, Gn8
	.byte W16

	.byte FINE

.align 2

track_186:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group11
	.word track_186_0

.align 2
