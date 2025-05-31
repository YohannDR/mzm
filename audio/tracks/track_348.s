.align 2

.global track_348

track_348_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 23
	.byte PAN, c_v
	.byte W08
	.byte N06, An1, v100
	.byte W06
	.byte N03, En2, v080
	.byte W03
	.byte Dn2, v060 @ N03
	.byte W10
	.byte Fn2 @ N03, v060
	.byte W03
	.byte As2 @ N03, v060
	.byte W03
	.byte FINE

.align 2

track_348:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group3
	.word track_348_0

.align 2
