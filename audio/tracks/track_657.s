.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_657

track_657_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 14
	.byte VOL, 44
	.byte BEND, c_v
	.byte N10
	.byte An2, En6
	.byte W01
	.byte VOL, 45
	.byte W01
	.byte Cn2
	.byte W01
	.byte Ds2
	.byte W01
	.byte Gn2
	.byte W06
	.byte N10
	.byte An2, Cn3
	.byte W10
	.byte An2, Gs0
	.byte W10
	.byte N21
	.byte An2, CnM1
	.byte W21

	.byte FINE

track_657_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 14
	.byte VOL, 33
	.byte BEND, c_v
	.byte N10
	.byte Cn3, En6
	.byte W01
	.byte VOL, 34
	.byte W01
	.byte Cn1
	.byte W01
	.byte En1
	.byte W01
	.byte Gs1
	.byte W06
	.byte N10
	.byte Cn3, Cn3
	.byte W10
	.byte Cn3, Gs0
	.byte W10
	.byte N21
	.byte Cn3, CnM1
	.byte W21

	.byte FINE

track_657_2:
	.byte KEYSH, 0
	.byte VOL, 18
	.byte W01
	.byte GnM1
	.byte W01
	.byte GsM1
	.byte W01
	.byte AnM1
	.byte W04
	.byte VOICE, 15
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N60
	.byte Cn1, Cn4, CsM2
	.byte W01
	.byte VOL, 22
	.byte W01
	.byte BnM1
	.byte W01
	.byte Cn0
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte En0
	.byte W01
	.byte Fn0
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte An0
	.byte W01
	.byte As0
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte Ds1
	.byte W01
	.byte Fs1
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 45
	.byte W01
	.byte Bn1
	.byte W01
	.byte En2
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 55
	.byte W01
	.byte Dn3
	.byte W01
	.byte Fn3
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte As3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte Fs3
	.byte W01
	.byte Ds3
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 60
	.byte W02
	.byte Fn2
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte Bn1
	.byte W01
	.byte As1
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte Gn1
	.byte W01
	.byte Fs1
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 42
	.byte W01
	.byte Fs1
	.byte W01
	.byte Gn1
	.byte BEND, c_v-14
	.byte W02
	.byte VOL, 44
	.byte W01
	.byte An1
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte Cs2
	.byte W01
	.byte Dn2
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte En2
	.byte W01
	.byte En2
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 52
	.byte W02
	.byte Dn2
	.byte BEND, c_v-18
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte An1
	.byte W01
	.byte Cn1
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte Ds0
	.byte W01
	.byte BnM1
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 20
	.byte W01
	.byte FnM1
	.byte W01
	.byte DnM1
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte AsM2
	.byte W01
	.byte GsM2
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte FnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte DnM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2

	.byte FINE

.align 2

track_657:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_657_0
	.word track_657_1
	.word track_657_2

.align 2
