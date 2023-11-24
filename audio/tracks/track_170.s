.include "audio/m_play_def.s"

.align 2

.section .rodata
.global track_170

track_170_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte W05
	.byte N05
	.byte Gn4, En6
	.byte W32
	.byte W02

	.byte FINE

track_170_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 25
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N18
	.byte Cn4, En2
	.byte W12
	.byte BEND, c_v
	.byte W01
	.byte Bn1
	.byte W01
	.byte Bn0
	.byte W01
	.byte En0
	.byte W01
	.byte AsM1
	.byte W01
	.byte FnM1
	.byte W01
	.byte DnM1
	.byte W21

	.byte FINE

track_170_2:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 62
	.byte PAN, c_v+16
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N24
	.byte Fn2, Gs4
	.byte W01
	.byte BEND, c_v-23
	.byte W01
	.byte Bn2
	.byte W01
	.byte Bn3
	.byte W01
	.byte Fn4
	.byte W01
	.byte Gn4
	.byte W01
	.byte Fs4
	.byte W01
	.byte Ds4
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v-33
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-5
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte GsM2
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-7
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-33
	.byte W01
	.byte DsM1
	.byte W15

	.byte FINE

.align 2

track_170:
	.byte 3
	.byte 0
	.byte 180
	.byte 0
	.word voice_group7
	.word track_170_0
	.word track_170_1
	.word track_170_2

.align 2
