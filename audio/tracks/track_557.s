.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_557

track_557_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte MOD, 30
	.byte VOL, 66
	.byte PAN, c_v
	.byte LFOS, 60
	.byte PRIO, 25
	.byte N24
	.byte En2, Cn3
	.byte W24
	.byte LFOS, 64
	.byte N24
	.byte En2, Gs3
	.byte W24
	.byte LFOS, 68
	.byte N24
	.byte En2, En4
	.byte W24
	.byte LFOS, 72
	.byte N24
	.byte En2, Cn5
	.byte W24
	.byte LFOS, 76
	.byte N24
	.byte En2, En5
	.byte W24
	.byte LFOS, 80
	.byte N24
	.byte En2, Cn6
	.byte W24
	.byte LFOS, 84
	.byte N24
	.byte En2, En6
	.byte W24
	.byte LFOS, 88
	.byte N24
	.byte En2, Gs6
	.byte W24

	.byte FINE

track_557_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v
	.byte TIE
	.byte En2, En7
	.byte W96
	.byte W88
	.byte W01
	.byte VOL, 64
	.byte W01
	.byte En2
	.byte W01
	.byte Gs1
	.byte W01
	.byte Cn1
	.byte W01
	.byte Fs0
	.byte W01
	.byte Dn0
	.byte W01
	.byte GsM1
	.byte W01
	.byte EnM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte BnM2
	.byte W01
	.byte GsM2
	.byte W01
	.byte FsM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte EOT

	.byte FINE

track_557_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 53
	.byte PAN, c_v
	.byte N08
	.byte Fn1, Cn1
	.byte W08
	.byte Fn1, En1
	.byte W08
	.byte Fn1, Gs1
	.byte W08
	.byte N08
	.byte W08
	.byte Fn1, Cn2
	.byte W08
	.byte Fn1, En2
	.byte W08
	.byte An1, Gs2
	.byte W08
	.byte An1, Cn3
	.byte W08
	.byte An1, Gs3
	.byte W08
	.byte An1, Cn4
	.byte W08
	.byte An1, En4
	.byte W08
	.byte An1, Gs4
	.byte W08
	.byte Cn2
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte N08
	.byte W08
	.byte Cn2, Cn3
	.byte W08
	.byte Cn2, GsM1
	.byte W08
	.byte Cn2, CnM1
	.byte W08

	.byte FINE

.align 2

track_557:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group10
	.word track_557_0
	.word track_557_1
	.word track_557_2

.align 2
