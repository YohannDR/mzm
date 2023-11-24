.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_142

track_142_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 59
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N30
	.byte Cn3, Cn3
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte An3
	.byte W02
	.byte Cn4
	.byte W02
	.byte Dn4
	.byte W02
	.byte Fn4
	.byte W02
	.byte Gs4
	.byte W02
	.byte As4
	.byte W02
	.byte Cs5
	.byte W02
	.byte En5
	.byte W02
	.byte Fs5
	.byte W02
	.byte An5
	.byte W02
	.byte Cn6
	.byte W06
	.byte VOICE, 17
	.byte VOL, 74
	.byte BEND, c_v
	.byte TIE
	.byte Cn3, En6
	.byte W01
track_142_lbl_20bcf5:
	.byte W64
	.byte W01
	.byte W30
	.byte GOTO
		.word track_142_lbl_20bcf5
	.byte W01
	.byte EOT, Cn3

	.byte FINE

.align 2

track_142:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_142_0

.align 2
