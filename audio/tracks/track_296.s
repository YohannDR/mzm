.align 2

.global track_296

track_296_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 22
	.byte PAN, c_v
	.byte BENDR, 2
	.byte W03
	.byte N12
	.byte Fs2, Gs4
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte Fs0
	.byte W01
	.byte An0
	.byte W09
	.byte VOICE, 7
	.byte VOL, 33
	.byte N02
	.byte Cn4, Cn3
	.byte W02
	.byte VOICE, 20
	.byte N02
	.byte Cn4, Cn0
	.byte W02

	.byte FINE

.align 2

track_296:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voice_group4
	.word track_296_0

.align 2
