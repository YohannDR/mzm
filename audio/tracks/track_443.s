.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_443

track_443_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 56
	.byte PAN, c_v
	.byte N56
	.byte Cn3, Gs4, DsM2
	.byte W05
	.byte VOL, 43
	.byte W01
	.byte Cn1
	.byte W01
	.byte Gs0
	.byte W01
	.byte Fn0
	.byte W01
	.byte Ds0
	.byte W01
	.byte Cs0
	.byte W01
	.byte Cs0
	.byte W48

	.byte FINE

.align 2

track_443:
	.byte 1
	.byte 0
	.byte 210
	.byte 0
	.word voice_group9
	.word track_443_0

.align 2
