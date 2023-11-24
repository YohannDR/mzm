.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_338

track_338_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 12
	.byte N20
	.byte Fn1, En7
	.byte W07
	.byte VOL, 27
	.byte W01
	.byte AsM1
	.byte W01
	.byte GnM1
	.byte W01
	.byte DsM1
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte EnM2
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W14

	.byte FINE

track_338_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04
	.byte An2, Cn8
	.byte W32
	.byte W01

	.byte FINE

.align 2

track_338:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word voice_group3
	.word track_338_0
	.word track_338_1

.align 2
