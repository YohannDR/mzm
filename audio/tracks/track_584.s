.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_584

track_584_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte TIE
	.byte Cn3, Cn8
	.byte W30
	.byte VOL, 94
	.byte W03
	.byte Gs5
	.byte W03
	.byte En5
	.byte W03
	.byte Cn5
	.byte W03
	.byte An4
	.byte W03
	.byte Fn4
	.byte W03
	.byte Dn4
	.byte W03
	.byte Bn3
	.byte W03
	.byte Gs3
	.byte W03
	.byte Fs3
	.byte W02
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 63
	.byte W02
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 60
	.byte W02
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 58
	.byte W02
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 55
	.byte W02
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 52
	.byte W02
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 51
	.byte W02
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 48
	.byte W02
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 46
	.byte W02
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 44
	.byte W02
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 41
	.byte W02
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 40
	.byte W03
	.byte Cs1
	.byte W03
	.byte Bn0
	.byte W03
	.byte An0
	.byte W03
	.byte Gs0
	.byte W03
	.byte Fs0
	.byte W03
	.byte Fn0
	.byte W03
	.byte Ds0
	.byte W03
	.byte Cs0
	.byte W03
	.byte Cn0
	.byte W03
	.byte AsM1
	.byte BEND, c_v-16
	.byte W03
	.byte VOL, 21
	.byte BEND, c_v-18
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 18
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 16
	.byte BEND, c_v-24
	.byte W03
	.byte Dn1
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-28
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-30
	.byte W03
	.byte VOL, 11
	.byte BEND, c_v-32
	.byte W03
	.byte VOL, 10
	.byte W06
	.byte GsM2
	.byte W03
	.byte GnM2
	.byte W06
	.byte FnM2
	.byte W03
	.byte DsM2
	.byte W06
	.byte DnM2
	.byte W03
	.byte CsM2
	.byte W03
	.byte CnM2
	.byte W02
	.byte CnM2
	.byte W01
	.byte EOT

	.byte FINE

.align 2

track_584:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_584_0

.align 2
