.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_343

track_343_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W04
	.byte N21
	.byte Fn2, Gs4
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte AnM2
	.byte W01
	.byte GnM1
	.byte W01
	.byte Ds0
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte Cs1
	.byte W01
	.byte En1
	.byte W01
	.byte Fs1
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 43
	.byte W04
	.byte Fn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte As0
	.byte W01
	.byte Dn0
	.byte W01
	.byte EnM1
	.byte W01
	.byte AnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_343:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_343_0

.align 2
