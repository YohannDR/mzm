.align 2

.global track_220

track_220_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 30
	.byte VOL, 11
	.byte PAN, c_v
	.byte BENDR, 7
	.byte BEND, c_v-63
	.byte N48
	.byte Cn3, Gs4, CsM2
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-55
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-50
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v-46
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-42
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-38
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v-34
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-29
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v-27
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v-6
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v-2
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+38
	.byte W01

	.byte FINE

.align 2

track_220:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voice_group2
	.word track_220_0

.align 2
