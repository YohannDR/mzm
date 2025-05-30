.align 2

.global track_273

track_273_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 30
	.byte PAN, c_v
	.byte N09, Bn4, v080
	.byte W17
	.byte Bn4, v060 @ N09
	.byte W17
	.byte Bn4, v040 @ N09
	.byte W16
	.byte Bn4, v020 @ N09
	.byte W17
	.byte Bn4, v008 @ N09
	.byte W09
	.byte FINE

.align 2

track_273:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voice_group16
	.word track_273_0

.align 2
