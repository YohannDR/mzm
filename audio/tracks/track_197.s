.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_197

track_197_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W10
	.byte VOICE, 10
	.byte VOL, 48
	.byte PAN, c_v-14
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N12
	.byte Dn3, Cn2
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v-51
	.byte W01
	.byte FsM1
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 59
	.byte N24
	.byte En3, Cn2, DnM2
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 71
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+18
	.byte W01
	.byte Gs4
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte Cn2
	.byte BEND, c_v-1
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte CnM2
	.byte W15

	.byte FINE

track_197_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte PRIO, 1
	.byte N04
	.byte Cn3, Cn8
	.byte W04
	.byte N13
	.byte Gs2, Gn8
	.byte W13
	.byte As2, En6
	.byte W10
	.byte VOL, 78
	.byte W01
	.byte BnM1
	.byte W01
	.byte GnM2
	.byte W32
	.byte W01

	.byte FINE

track_197_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte W17
	.byte N13
	.byte En3, En6
	.byte W44
	.byte W01

	.byte FINE

track_197_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 100
	.byte PAN, c_v-14
	.byte PRIO, 1
	.byte W04
	.byte N04
	.byte Gs2, En6
	.byte W04
	.byte N10
	.byte Fn2, Gn8
	.byte W54

	.byte FINE

.align 2

track_197:
	.byte 4
	.byte 0
	.byte 229
	.byte 0
	.word voice_group11
	.word track_197_0
	.word track_197_1
	.word track_197_2
	.word track_197_3

.align 2
