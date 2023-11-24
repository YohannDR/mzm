.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_140

track_140_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 28
	.byte PAN, c_v
	.byte N06
	.byte Cn3, Gn8
	.byte W06
	.byte Cn3, Gs4
	.byte W07
	.byte Cn3, Cn3
	.byte W07
	.byte Cn3, GsM1
	.byte W06

	.byte FINE

track_140_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte PAN, c_v
	.byte W03
	.byte VOL, 17
	.byte N24
	.byte Cn2, En7, CsM2
	.byte W01
	.byte VOL, 24
	.byte W01
	.byte Fn0
	.byte W01
	.byte Gs0
	.byte W01
	.byte Bn0
	.byte W01
	.byte Cn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Dn1
	.byte W01
	.byte Cs1
	.byte W01
	.byte Cn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte Fn0
	.byte W01
	.byte BnM1
	.byte W01
	.byte FsM1
	.byte W01
	.byte DnM1
	.byte W01
	.byte AsM2
	.byte W01
	.byte GnM2
	.byte W01
	.byte FnM2
	.byte W01
	.byte EnM2
	.byte W01
	.byte DsM2
	.byte W01
	.byte CsM2
	.byte W01
	.byte CnM2
	.byte W01
	.byte CnM2
	.byte W01

	.byte FINE

.align 2

track_140:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_140_0
	.word track_140_1

.align 2
