.align 2

.global track_532

track_532_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 0
	.byte TIE, Gn1, v100
	.byte TIE, Cn2 @ v100
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W04
	.byte 61 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte EOT, Gn1, v048
	.byte FINE

.align 2

track_532:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word voice_group16
	.word track_532_0

.align 2
