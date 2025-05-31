.align 2

.global track_672

track_672_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 94
	.byte PAN, c_v
	.byte N23, Cn3, v100
	.byte W23
	.byte FINE

track_672_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v
	.byte N09, Cn4, v080
	.byte W09
	.byte Cn4, v032 @ N09
	.byte W09
	.byte Cn4, v012 @ N09
	.byte W09
	.byte FINE

.align 2

track_672:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voice_group14
	.word track_672_0
	.word track_672_1

.align 2
