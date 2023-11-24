.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_553

track_553_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 86
	.byte PAN, c_v
	.byte N72
	.byte Cn3, En7
	.byte W72

	.byte FINE

track_553_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N72
	.byte Cn3, En6
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte Dn2
	.byte W02
	.byte Ds2
	.byte W02
	.byte En2
	.byte W02
	.byte Fn2
	.byte W02
	.byte Fs2
	.byte W02
	.byte Gn2
	.byte W02
	.byte Gs2
	.byte W01
	.byte An2
	.byte W02
	.byte As2
	.byte W02
	.byte Bn2
	.byte W02
	.byte Cn3
	.byte W02
	.byte Cs3
	.byte W02
	.byte Dn3
	.byte W02
	.byte Ds3
	.byte W02
	.byte En3
	.byte W01
	.byte Fn3
	.byte W02
	.byte Fs3
	.byte W02
	.byte Gn3
	.byte W02
	.byte Gs3
	.byte W02
	.byte An3
	.byte W02
	.byte As3
	.byte W02
	.byte Bn3
	.byte W02
	.byte Cn4
	.byte W01
	.byte Cs4
	.byte W02
	.byte Dn4
	.byte W02
	.byte Ds4
	.byte W02
	.byte En4
	.byte W02
	.byte Fn4
	.byte W02
	.byte Fs4
	.byte W02
	.byte Gn4
	.byte W02
	.byte Gs4
	.byte W12

	.byte FINE

track_553_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte MOD, 20
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 5
	.byte N72
	.byte Fn2, Gs4
	.byte W72

	.byte FINE

.align 2

track_553:
	.byte 3
	.byte 0
	.byte 229
	.byte 128
	.word voice_group17
	.word track_553_0
	.word track_553_1
	.word track_553_2

.align 2
