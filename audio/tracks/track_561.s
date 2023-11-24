.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_561

track_561_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N16
	.byte Cn2, Cn8
	.byte W01
	.byte BEND, c_v-55
	.byte W01
	.byte FsM1
	.byte W01
	.byte Dn0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Gn1
	.byte W01
	.byte En2
	.byte W01
	.byte Cn3
	.byte W01
	.byte Gs3
	.byte W01
	.byte Fn4
	.byte W01
	.byte Cs5
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte VOICE, 10
	.byte BEND, c_v
	.byte N48
	.byte Cn2, Gs4
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte CnM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Gs0
	.byte W02
	.byte Cn2
	.byte W01
	.byte Cn3
	.byte W02
	.byte Dn4
	.byte W02
	.byte Gn4
	.byte W04
	.byte En4
	.byte W02
	.byte Bn3
	.byte W02
	.byte En3
	.byte W03
	.byte Cs2
	.byte W02
	.byte En1
	.byte W02
	.byte An0
	.byte W02
	.byte Dn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte AsM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_561_1:
	.byte KEYSH, 0
	.byte W16
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte N48
	.byte En2, Gs4
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte CnM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Gs0
	.byte W02
	.byte Cn2
	.byte W01
	.byte Cn3
	.byte W02
	.byte Dn4
	.byte W02
	.byte Gn4
	.byte W04
	.byte En4
	.byte W02
	.byte Bn3
	.byte W02
	.byte En3
	.byte W03
	.byte Cs2
	.byte W02
	.byte En1
	.byte W02
	.byte An0
	.byte W02
	.byte Dn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte AsM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

track_561_2:
	.byte KEYSH, 0
	.byte W16
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte N48
	.byte Gn2, Gs4
	.byte W02
	.byte VOL, 5
	.byte W02
	.byte CnM1
	.byte W02
	.byte AnM1
	.byte W02
	.byte Gs0
	.byte W02
	.byte Cn2
	.byte W01
	.byte Cn3
	.byte W02
	.byte Dn4
	.byte W02
	.byte Gn4
	.byte W04
	.byte En4
	.byte W02
	.byte Bn3
	.byte W02
	.byte En3
	.byte W03
	.byte Cs2
	.byte W02
	.byte En1
	.byte W02
	.byte An0
	.byte W02
	.byte Dn0
	.byte W02
	.byte AnM1
	.byte W02
	.byte FnM1
	.byte W02
	.byte CsM1
	.byte W02
	.byte AsM2
	.byte W02
	.byte GnM2
	.byte W02
	.byte DsM2
	.byte W02
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_561:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group17
	.word track_561_0
	.word track_561_1
	.word track_561_2

.align 2
