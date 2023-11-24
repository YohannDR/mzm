.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_587

track_587_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 66
	.byte PAN, c_v-32
	.byte BENDR, 24
	.byte BEND, c_v
	.byte TIE
	.byte Cn2, En6
	.byte W03
	.byte BEND, c_v
	.byte W03
	.byte PAN, c_v-30
	.byte BEND, c_v-1
	.byte W03
	.byte Ds3
	.byte W03
	.byte PAN, c_v-28
	.byte BEND, c_v-2
	.byte W03
	.byte Dn3
	.byte W03
	.byte PAN, c_v-26
	.byte BEND, c_v-3
	.byte W03
	.byte Cs3
	.byte W03
	.byte PAN, c_v-23
	.byte BEND, c_v-3
	.byte W03
	.byte Cn3
	.byte W03
	.byte PAN, c_v-21
	.byte BEND, c_v-4
	.byte W03
	.byte Bn2
	.byte W03
	.byte PAN, c_v-19
	.byte BEND, c_v-5
	.byte W03
	.byte As2
	.byte W03
	.byte PAN, c_v-17
	.byte BEND, c_v-6
	.byte W03
	.byte As2
	.byte W03
	.byte PAN, c_v-15
	.byte BEND, c_v-7
	.byte W03
	.byte An2
	.byte W03
	.byte PAN, c_v-13
	.byte BEND, c_v-8
	.byte W03
	.byte Gs2
	.byte W03
	.byte PAN, c_v-11
	.byte BEND, c_v-9
	.byte W03
	.byte Gn2
	.byte W03
	.byte PAN, c_v-8
	.byte BEND, c_v-9
	.byte W03
	.byte PAN, c_v-7
	.byte BEND, c_v-10
	.byte W03
	.byte Fs2
	.byte W03
	.byte PAN, c_v-5
	.byte BEND, c_v-11
	.byte W03
	.byte Fn2
	.byte W03
	.byte PAN, c_v-3
	.byte BEND, c_v-12
	.byte W03
	.byte En2
	.byte W03
	.byte PAN, c_v-1
	.byte BEND, c_v-12
	.byte W03
	.byte Ds2
	.byte W03
	.byte PAN, c_v+1
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v-14
	.byte W03
	.byte PAN, c_v+3
	.byte BEND, c_v-14
	.byte W03
	.byte Cs2
	.byte W03
	.byte PAN, c_v+5
	.byte BEND, c_v-15
	.byte W03
	.byte Cs2
	.byte W02
	.byte VOL, 65
	.byte W01
	.byte PAN, c_v+8
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 64
	.byte W01
	.byte BEND, c_v-16
	.byte W03
	.byte PAN, c_v+10
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 63
	.byte W04
	.byte PAN, c_v+12
	.byte W02
	.byte VOL, 62
	.byte W03
	.byte Dn3
	.byte W01
	.byte PAN, c_v+14
	.byte W02
	.byte VOL, 61
	.byte W03
	.byte Cn3
	.byte W01
	.byte PAN, c_v+16
	.byte W02
	.byte VOL, 58
	.byte W03
	.byte An2
	.byte W01
	.byte PAN, c_v+18
	.byte W02
	.byte VOL, 56
	.byte W03
	.byte Fs2
	.byte W01
	.byte PAN, c_v+20
	.byte W02
	.byte VOL, 52
	.byte W03
	.byte Dn2
	.byte W01
	.byte PAN, c_v+23
	.byte W03
	.byte VOL, 38
	.byte W03
	.byte PAN, c_v+25
	.byte VOL, 29
	.byte W03
	.byte AsM1
	.byte W03
	.byte PAN, c_v+27
	.byte VOL, 17
	.byte W03
	.byte CnM1
	.byte W03
	.byte PAN, c_v+29
	.byte VOL, 8
	.byte W03
	.byte EnM2
	.byte W03
	.byte PAN, c_v+31
	.byte VOL, 1
	.byte W02
	.byte CnM2
	.byte PAN, c_v+32
	.byte W01
	.byte EOT

	.byte FINE

.align 2

track_587:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_587_0

.align 2
