.align 2

.global track_569

track_569_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 120
	.byte PAN, c_v-30
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N72, Cn2, v127
	.byte W02
	.byte BEND, c_v+3
	.byte W01
	.byte PAN, c_v-26
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte PAN, c_v-21
	.byte BEND, c_v+8
	.byte W02
	.byte c_v+11 @ BEND
	.byte W01
	.byte PAN, c_v-17
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte PAN, c_v-12
	.byte BEND, c_v+16
	.byte W02
	.byte c_v+19 @ BEND
	.byte W01
	.byte PAN, c_v-8
	.byte W01
	.byte BEND, c_v+21
	.byte W02
	.byte PAN, c_v-3
	.byte BEND, c_v+24
	.byte W02
	.byte c_v+27 @ BEND
	.byte W01
	.byte PAN, c_v+1
	.byte W01
	.byte BEND, c_v+29
	.byte W02
	.byte PAN, c_v+6
	.byte BEND, c_v+32
	.byte W02
	.byte c_v+35 @ BEND
	.byte W01
	.byte PAN, c_v+10
	.byte W01
	.byte BEND, c_v+37
	.byte W02
	.byte PAN, c_v+15
	.byte BEND, c_v+40
	.byte W02
	.byte c_v+43 @ BEND
	.byte W01
	.byte PAN, c_v+19
	.byte W01
	.byte BEND, c_v+46
	.byte W02
	.byte PAN, c_v+24
	.byte BEND, c_v+48
	.byte W02
	.byte c_v+51 @ BEND
	.byte W01
	.byte PAN, c_v+28
	.byte W01
	.byte VOL, 120
	.byte PAN, c_v+30
	.byte BEND, c_v+54
	.byte W02
	.byte VOL, 101
	.byte BEND, c_v+56
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v+59
	.byte W02
	.byte VOL, 71
	.byte BEND, c_v+62
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 59
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte FINE

.align 2

track_569:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group17
	.word track_569_0

.align 2
