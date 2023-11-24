.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_573

track_573_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 94
	.byte PAN, c_v
	.byte N90
	.byte Cn3, En7
	.byte W90

	.byte FINE

track_573_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N90
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
	.byte W30

	.byte FINE

track_573_2:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte MOD, 20
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 5
	.byte N90
	.byte Fn2, Gs4
	.byte W90

	.byte FINE

track_573_3:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 3
	.byte BEND, c_v+47
	.byte N90
	.byte Cn4, En2
	.byte W03
	.byte BEND, c_v+44
	.byte W03
	.byte As6
	.byte W03
	.byte Gn6
	.byte W03
	.byte En6
	.byte W03
	.byte Dn6
	.byte W03
	.byte Bn5
	.byte W03
	.byte Gs5
	.byte W03
	.byte Fs5
	.byte W03
	.byte Ds5
	.byte W03
	.byte Cn5
	.byte W03
	.byte As4
	.byte W03
	.byte Gn4
	.byte W03
	.byte En4
	.byte W03
	.byte Dn4
	.byte W03
	.byte Bn3
	.byte W03
	.byte VOL, 78
	.byte BEND, c_v+4
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 74
	.byte BEND, c_v-1
	.byte W03
	.byte VOL, 72
	.byte BEND, c_v-4
	.byte W03
	.byte VOL, 70
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 66
	.byte BEND, c_v-12
	.byte W03
	.byte VOL, 64
	.byte BEND, c_v-14
	.byte W21

	.byte FINE

.align 2

track_573:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_573_0
	.word track_573_1
	.word track_573_2
	.word track_573_3

.align 2
