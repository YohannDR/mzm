.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_473

track_473_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 66
	.byte PAN, c_v
	.byte BENDR, 24
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N08
	.byte Cn4, Cn3
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte As4
	.byte W01
	.byte Gn5
	.byte W01
	.byte En6
	.byte W01
	.byte Cs7
	.byte W01
	.byte As7
	.byte W01
	.byte Gn8
	.byte W01
	.byte En3
	.byte N08
	.byte Cn4, Gs0
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte As4
	.byte W01
	.byte Gn5
	.byte W01
	.byte En6
	.byte W01
	.byte Cs7
	.byte W01
	.byte As7
	.byte W01
	.byte Gn8
	.byte W01
	.byte En3
	.byte N08
	.byte Cn4, CnM1
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte As4
	.byte W01
	.byte Gn5
	.byte W01
	.byte En6
	.byte W01
	.byte Cs7
	.byte W01
	.byte As7
	.byte W01
	.byte Gn8
	.byte W01

	.byte FINE

track_473_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte MOD, 1
	.byte VOL, 48
	.byte PAN, c_v
	.byte LFOS, 80
	.byte N30
	.byte Cn3, Cn8
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte Cs2
	.byte W02
	.byte En2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Fs3
	.byte W01
	.byte Dn4
	.byte W01
	.byte Bn3
	.byte W01
	.byte Cn2
	.byte W01
	.byte An1
	.byte W01
	.byte Gs1
	.byte W01
	.byte As1
	.byte W01
	.byte Cs2
	.byte W01
	.byte Fn2
	.byte W01
	.byte Bn2
	.byte W01
	.byte Bn3
	.byte W01
	.byte Gn4
	.byte W01
	.byte Cn5
	.byte W01
	.byte Dn5
	.byte W01
	.byte Cs5
	.byte W01
	.byte Dn4
	.byte W01
	.byte Fs3
	.byte W01
	.byte Cn3
	.byte W01
	.byte Fs2
	.byte W01
	.byte Cs2
	.byte W02
	.byte Ds2
	.byte W01
	.byte Gn2
	.byte W01
	.byte Dn3
	.byte W01

	.byte FINE

.align 2

track_473:
	.byte 2
	.byte 0
	.byte 201
	.byte 0
	.word voice_group12
	.word track_473_0
	.word track_473_1

.align 2
