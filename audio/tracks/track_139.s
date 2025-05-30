.align 2

.global track_139

track_139_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 74
	.byte PAN, c_v
	.byte TIE, Cn3, v100
	.byte W30
	.byte W01
track_139_lbl_20bbdb:
	.byte W64
	.byte W01
	.byte GOTO
		.word track_139_lbl_20bbdb
	.byte W01
	.byte EOT @ Cn3, v100
	.byte FINE

track_139_1:
	.byte KEYSH, 0
	.byte VOICE, 60
	.byte VOL, 95
	.byte PAN, c_v
	.byte BENDR, 20
	.byte PRIO, 26
	.byte BEND, c_v-47
	.byte W28
	.byte c_v-33 @ BEND
	.byte N24, Gn3, v127
	.byte W01
	.byte BEND, c_v-30
	.byte W01
	.byte c_v-27 @ BEND
	.byte W01
	.byte c_v-24 @ BEND
	.byte W01
	.byte c_v-21 @ BEND
	.byte W01
	.byte c_v-19 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-4 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-1 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W44
	.byte W01
	.byte FINE

.align 2

track_139:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voice_group1
	.word track_139_0
	.word track_139_1

.align 2
