.align 2

.global track_386

track_386_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W04
	.byte N24, En2, v064, 1
	.byte W05
	.byte VOL, 50
	.byte BEND, c_v+30
	.byte W10
	.byte VOL, 40
	.byte BEND, c_v+15
	.byte W06
	.byte VOL, 30
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_386:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voice_group3
	.word track_386_0

.align 2
