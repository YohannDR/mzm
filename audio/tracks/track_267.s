.align 2

.global track_267

track_267_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v
	.byte TIE, An1, v100
	.byte W01
track_267_lbl_20fc4a:
	.byte W05
	.byte BEND, c_v+10
	.byte W06
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+27 @ BEND
	.byte W06
	.byte c_v+31 @ BEND
	.byte W05
	.byte c_v+32 @ BEND
	.byte W08
	.byte c_v+30 @ BEND
	.byte W06
	.byte c_v+25 @ BEND
	.byte W05
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+11 @ BEND
	.byte W06
	.byte c_v+1 @ BEND
	.byte W07
	.byte c_v-11 @ BEND
	.byte W05
	.byte c_v-19 @ BEND
	.byte W06
	.byte c_v-26 @ BEND
	.byte W06
	.byte c_v-31 @ BEND
	.byte W12
	.byte W01
	.byte c_v-29 @ BEND
	.byte W05
	.byte c_v-26 @ BEND
	.byte W06
	.byte c_v-19 @ BEND
	.byte W06
	.byte c_v-10 @ BEND
	.byte W06
	.byte c_v @ BEND
	.byte W06
	.byte c_v+10 @ BEND
	.byte W06
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+27 @ BEND
	.byte W06
	.byte c_v+31 @ BEND
	.byte W05
	.byte c_v+32 @ BEND
	.byte W09
	.byte c_v+29 @ BEND
	.byte W05
	.byte c_v+25 @ BEND
	.byte W05
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+11 @ BEND
	.byte W06
	.byte c_v+1 @ BEND
	.byte W06
	.byte c_v-9 @ BEND
	.byte W06
	.byte c_v-19 @ BEND
	.byte W06
	.byte c_v-26 @ BEND
	.byte W06
	.byte c_v-31 @ BEND
	.byte W13
	.byte c_v-30 @ BEND
	.byte W05
	.byte c_v-26 @ BEND
	.byte W06
	.byte c_v-19 @ BEND
	.byte W06
	.byte c_v-10 @ BEND
	.byte W06
	.byte GOTO
		.word track_267_lbl_20fc4a
	.byte W01
	.byte EOT, An1 @ v100
	.byte FINE

track_267_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte MOD, 50
	.byte VOL, 94
	.byte PAN, c_v
	.byte LFOS, 20
	.byte MODT, mod_tre
	.byte TIE, Cn3, v120
	.byte W01
track_267_lbl_20fcb2:
	.byte W23
	.byte MOD, 30
	.byte W24
	.byte 20 @ MOD
	.byte W24
	.byte 60 @ MOD
	.byte W24
	.byte 50 @ MOD
	.byte W24
	.byte 20 @ MOD
	.byte W24
	.byte 40 @ MOD
	.byte W24
	.byte 30 @ MOD
	.byte W24
	.byte 60 @ MOD
	.byte W24
	.byte 50 @ MOD
	.byte W24
	.byte GOTO
		.word track_267_lbl_20fcb2
	.byte W01
	.byte EOT, Cn3 @ v120
	.byte FINE

track_267_2:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte MOD, 12
	.byte VOL, 70
	.byte PAN, c_v
	.byte LFOS, 120
	.byte PRIO, 25
	.byte W01
track_267_lbl_20fcde:
	.byte N05, Gn2, v080
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W09
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W06
	.byte N05 @ Gn2, v080
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W09
	.byte Dn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W05
	.byte N05 @ Gn2, v080
	.byte W06
	.byte En2, v100 @ N05
	.byte W08
	.byte Fn2, v092 @ N05
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W07
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W05
	.byte W01
	.byte Fn2, v092 @ N05
	.byte W05
	.byte Gn2, v100 @ N05
	.byte W07
	.byte Dn2 @ N05, v100
	.byte W05
	.byte Fn2, v092 @ N05
	.byte W07
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Fn2, v092 @ N05
	.byte W09
	.byte En2, v100 @ N05
	.byte W05
	.byte Dn2 @ N05, v100
	.byte W05
	.byte Fn2 @ N05, v100
	.byte W06
	.byte Gn2 @ N05, v100
	.byte W05
	.byte Fn2, v092 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W09
	.byte Dn2, v100 @ N05
	.byte W05
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W06
	.byte En2 @ N05, v100
	.byte W06
	.byte W02
	.byte Fn2 @ N05, v100
	.byte W05
	.byte Dn2, v092 @ N05
	.byte W07
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Fn2, v100 @ N05
	.byte W06
	.byte Gn2, v080 @ N05
	.byte W05
	.byte Dn2, v100 @ N05
	.byte W07
	.byte N05 @ Dn2, v100
	.byte W05
	.byte Gn2, v092 @ N05
	.byte W06
	.byte GOTO
		.word track_267_lbl_20fcde
	.byte FINE

.align 2

track_267:
	.byte 3
	.byte 0
	.byte 228
	.byte 0
	.word voice_group4
	.word track_267_0
	.word track_267_1
	.word track_267_2

.align 2
