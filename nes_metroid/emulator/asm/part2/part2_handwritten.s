    .include "asm/constants.inc"
    .include "asm/macros.inc"
	.include "asm/emulator_constants.inc"

    .syntax unified

	.section .data

    .global sEmulatorAudio_LengthCounterTable
sEmulatorAudio_LengthCounterTable: @ 0x030023DC
    .byte 10/2
	.byte 254/2
	.byte 20/2
	.byte 2/2
	.byte 40/2 - 1
	.byte 4/2
	.byte 80/2
	.byte 6/2
	.byte 160/2
	.byte 8/2
	.byte 60/2
	.byte 10/2
	.byte 14/2
	.byte 12/2
	.byte 26/2
	.byte 14/2
	.byte 12/2
	.byte 16/2
	.byte 24/2
	.byte 18/2
	.byte 48/2
	.byte 20/2
	.byte 96/2
	.byte 22/2
	.byte 192/2
	.byte 24/2
	.byte 72/2
	.byte 26/2
	.byte 16/2
	.byte 28/2
	.byte 32/2
	.byte 30/2

_030023FC:
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300241C:
	.byte 0x01, 0x01, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300243C:
	.byte 0x02, 0x02, 0x02, 0x02
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300245C:
	.byte 0x03, 0x03, 0x03, 0x03
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300247C:
	.byte 0x04, 0x04, 0x04, 0x04
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300249C:
	.byte 0x05, 0x05, 0x05, 0x05
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_030024BC:
	.byte 0x06, 0x06, 0x06, 0x06
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_030024DC:
	.byte 0x08, 0x08, 0x08, 0x08
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_030024FC:
	.byte 0x0A, 0x0A, 0x0A, 0x0A
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300251C:
	.byte 0x0C, 0x0C, 0x0C, 0x0C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300253C:
	.byte 0x0E, 0x0E, 0x0E, 0x0E
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300255C:
	.byte 0x10, 0x10, 0x10, 0x10
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0300257C:
	.byte 0x12, 0x12, 0x12, 0x12
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
_0300259C:
	.byte 0x14, 0x14, 0x14, 0x14
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
_030025BC:
	.byte 0x16, 0x16, 0x16, 0x16
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
_030025DC:
	.byte 0x19, 0x19, 0x19, 0x19
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01

	.global sUnk_030025FC
sUnk_030025FC:
	.4byte _030023FC
	.4byte _0300241C
	.4byte _0300243C
	.4byte _0300245C
	.4byte _0300247C
	.4byte _0300249C
	.4byte _030024BC
	.4byte _030024DC
	.4byte _030024FC
	.4byte _0300251C
	.4byte _0300253C
	.4byte _0300255C
	.4byte _0300257C
	.4byte _0300259C
	.4byte _030025BC
	.4byte _030025DC

	.global sUnk_0300263C
sUnk_0300263C:
	.byte 0x0E, 0x0F, 0x10, 0x0F

	.global sUnk_03002640
sUnk_03002640:
	.byte 0x1F, 0x0F, 0x07, 0x0F, 0x00

	.global sUnk_03002645
sUnk_03002645:
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02
	.byte 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
	.byte 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFD, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03
	.byte 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02
	.byte 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD
	.byte 0xFD, 0xFC, 0xFC, 0xFC, 0xFB, 0xFB, 0xFB, 0xFC, 0xFC, 0xFC, 0xFD, 0xFD, 0xFD, 0xFD, 0xFE, 0xFE
	.byte 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05
	.byte 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x07, 0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03
	.byte 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFD, 0xFD, 0xFC, 0xFC, 0xFB
	.byte 0xFB, 0xFA, 0xFA, 0xF9, 0xF9, 0xF8, 0xF9, 0xF9, 0xFA, 0xFA, 0xFB, 0xFB, 0xFC, 0xFC, 0xFD, 0xFD
	.byte 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x06, 0x06
	.byte 0x07, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x09, 0x09, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04, 0x04
	.byte 0x03, 0x03, 0x02, 0x01, 0x01, 0x00, 0xFF, 0xFF, 0xFE, 0xFD, 0xFD, 0xFC, 0xFC, 0xFB, 0xFA, 0xFA
	.byte 0xF9, 0xF8, 0xF8, 0xF7, 0xF7, 0xF6, 0xF7, 0xF7, 0xF8, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC, 0xFC
	.byte 0xFD, 0xFD, 0xFE, 0xFF, 0xFF, 0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x05, 0x05, 0x06, 0x07, 0x08
	.byte 0x09, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x09, 0x08, 0x07, 0x06, 0x05, 0x05
	.byte 0x04, 0x03, 0x02, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFE, 0xFD, 0xFC, 0xFB, 0xFB, 0xFA, 0xF9, 0xF8
	.byte 0xF7, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFB
	.byte 0xFC, 0xFD, 0xFE, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x09
	.byte 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x08, 0x07, 0x06
	.byte 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF8, 0xF7
	.byte 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF8, 0xF9, 0xFA
	.byte 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x07, 0x08, 0x09, 0x0A, 0x0B
	.byte 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x12, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07
	.byte 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5
	.byte 0xF4, 0xF3, 0xF2, 0xF1, 0xF0, 0xEE, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9
	.byte 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x03, 0x04, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0B, 0x0D
	.byte 0x0E, 0x0F, 0x10, 0x12, 0x13, 0x14, 0x13, 0x12, 0x10, 0x0F, 0x0E, 0x0D, 0x0B, 0x0A, 0x09, 0x08
	.byte 0x06, 0x05, 0x04, 0x03, 0x01, 0x00, 0xFF, 0xFD, 0xFC, 0xFB, 0xFA, 0xF8, 0xF7, 0xF6, 0xF5, 0xF3
	.byte 0xF2, 0xF1, 0xF0, 0xEE, 0xED, 0xEC, 0xED, 0xEE, 0xF0, 0xF1, 0xF2, 0xF3, 0xF5, 0xF6, 0xF7, 0xF8
	.byte 0xFA, 0xFB, 0xFC, 0xFD, 0xFF

	.global sUnk_03002845
sUnk_03002845:
	.byte 0x00

	.global sUnk_03002846
sUnk_03002846:
	.2byte 0x8000

_03002848:
	.byte 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08
_03002858:
	.byte 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08
_03002868:
	.byte 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08
_03002878:
	.byte 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08
_03002888:
	.byte 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x06
_03002898:
	.byte 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04
_030028A8:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02
_030028B8:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
_030028C8:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_030028D8:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
_030028E8:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFD
_030028F8:
	.byte 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD, 0xFD, 0xFC
_03002908:
	.byte 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD, 0xFC, 0xFC, 0xFC, 0xFB
_03002918:
	.byte 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFD, 0xFD, 0xFC, 0xFC, 0xFB, 0xFB, 0xFA, 0xFA, 0xF9, 0xF9, 0xF8
_03002928:
	.byte 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1
_03002938:
	.byte 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1

	.global sUnk_03002948
sUnk_03002948:
	.4byte _03002848
	.4byte _03002858
	.4byte _03002868
	.4byte _03002878
	.4byte _03002888
	.4byte _03002898
	.4byte _030028A8
	.4byte _030028B8
	.4byte _030028C8
	.4byte _030028D8
	.4byte _030028E8
	.4byte _030028F8
	.4byte _03002908
	.4byte _03002918
	.4byte _03002928
	.4byte _03002938

	.global sUnk_03002988
sUnk_03002988:
	.4byte 0x00000000

	@ Reads
_0300298C: .4byte sub_03005250 @ Addresses $1XXXX-$11XXX (Is this possible?)
_03002990: .4byte sub_03002E38 @ Addresses $EXXX-$FXXX (ROM)
_03002994: .4byte sub_03002E38 @ Addresses $CXXX-$DXXX (ROM)
_03002998: .4byte sub_03002E38 @ Addresses $AXXX-$BXXX (ROM)
_0300299C: .4byte sub_03002E38 @ Addresses $8XXX-$9XXX (ROM)
_030029A0: .4byte sub_03002E2C @ Addresses $6XXX-$7XXX (WRAM)
_030029A4: .4byte sub_03002EFC @ Addresses $4XXX-$5XXX (APU/2A03)
_030029A8: .4byte sub_03002E44 @ Addresses $2XXX-$3XXX (PPU)

	.global _030029AC
_030029AC: .4byte 0x00000000 @ Addresses $0XXX-$1XXX (RAM) (usually 0x06030072)
_030029B0: .4byte 0x00000000 @ Addresses $2XXX-$3XXX (PPU) (usually 0x00000000)
_030029B4: .4byte 0x00000000 @ Addresses $4XXX-$5XXX (APU/2A03) (usually 0x00000000)
_030029B8: .4byte 0x00000000 @ Addresses $6XXX-$7XXX (WRAM) (usually 0x06020360)
_030029BC: .4byte 0x00000000 @ Addresses $8XXX-$9XXX (ROM) (usually 0x06020140 or 0x06020180)
_030029C0: .4byte 0x00000000 @ Addresses $AXXX-$BXXX (ROM) (usually 0x06020140 or 0x06020180)
_030029C4: .4byte 0x00000000 @ Addresses $CXXX-$DXXX (ROM) (usually 0x060202C0)
_030029C8: .4byte 0x00000000 @ Addresses $EXXX-$FXXX (ROM) (usually 0x060202C0)
_030029CC: .4byte 0x00000000 @ Addresses $1XXXX-$11XXX (usually 0x0602FF72)

	@ Writes
_030029D0: .4byte sub_0600B000 @ Addresses $1XXXX-$11XXX (Is this possible?)
_030029D4: .4byte sub_03005844 @ Addresses $EXXX-$FXXX (ROM)
_030029D8: .4byte sub_03005844 @ Addresses $CXXX-$DXXX (ROM)
_030029DC: .4byte sub_03005844 @ Addresses $AXXX-$BXXX (ROM)
_030029E0: .4byte sub_03005844 @ Addresses $8XXX-$9XXX (ROM)
_030029E4: .4byte sub_03003044 @ Addresses $6XXX-$7XXX (WRAM)
_030029E8: .4byte sub_030033A4 @ Addresses $4XXX-$5XXX (APU/2A03)
_030029EC: .4byte sub_0300305C @ Addresses $2XXX-$3XXX (PPU)

	.global _030029F0
_030029F0: .4byte Opcode_BRK @ 0x00
_030029F4: .4byte Opcode_ORA_IndirectX @ 0x01
_030029F8: .4byte Opcode_NOP @ 0x02
_030029FC: .4byte Opcode_NOP @ 0x03
_03002A00: .4byte Opcode_NOP @ 0x04
_03002A04: .4byte Opcode_ORA_ZeroPage @ 0x05
_03002A08: .4byte Opcode_ASL_ZeroPage @ 0x06
_03002A0C: .4byte Opcode_NOP @ 0x07
_03002A10: .4byte Opcode_PHP @ 0x08
_03002A14: .4byte Opcode_ORA_Immediate @ 0x09
_03002A18: .4byte Opcode_ASL_Accumulator @ 0x0A
_03002A1C: .4byte Opcode_NOP @ 0x0B
_03002A20: .4byte Opcode_NOP @ 0x0C
_03002A24: .4byte Opcode_ORA_Absolute @ 0x0D
_03002A28: .4byte Opcode_ASL_Absolute @ 0x0E
_03002A2C: .4byte Opcode_NOP @ 0x0F
_03002A30: .4byte Opcode_BPL @ 0x10
_03002A34: .4byte Opcode_ORA_IndirectY @ 0x11
_03002A38: .4byte Opcode_NOP @ 0x12
_03002A3C: .4byte Opcode_NOP @ 0x13
_03002A40: .4byte Opcode_NOP @ 0x14
_03002A44: .4byte Opcode_ORA_ZeroPageX @ 0x15
_03002A48: .4byte Opcode_ASL_ZeroPageX @ 0x16
_03002A4C: .4byte Opcode_NOP @ 0x17
_03002A50: .4byte Opcode_CLC_SEC @ 0x18
_03002A54: .4byte Opcode_ORA_AbsoluteY @ 0x19
_03002A58: .4byte Opcode_NOP @ 0x1A
_03002A5C: .4byte Opcode_NOP @ 0x1B
_03002A60: .4byte Opcode_NOP @ 0x1C
_03002A64: .4byte Opcode_ORA_AbsoluteX @ 0x1D
_03002A68: .4byte Opcode_ASL_AbsoluteX @ 0x1E
_03002A6C: .4byte Opcode_NOP @ 0x1F
_03002A70: .4byte Opcode_JSR @ 0x20
_03002A74: .4byte Opcode_AND_IndirectX @ 0x21
_03002A78: .4byte Opcode_NOP @ 0x22
_03002A7C: .4byte Opcode_NOP @ 0x23
_03002A80: .4byte Opcode_BIT_ZeroPage @ 0x24
_03002A84: .4byte Opcode_AND_ZeroPage @ 0x25
_03002A88: .4byte Opcode_ROL_ZeroPage @ 0x26
_03002A8C: .4byte Opcode_NOP @ 0x27
_03002A90: .4byte Opcode_PLP @ 0x28
_03002A94: .4byte Opcode_AND_Immediate @ 0x29
_03002A98: .4byte Opcode_ROL_Accumulator @ 0x2A
_03002A9C: .4byte Opcode_NOP @ 0x2B
_03002AA0: .4byte Opcode_BIT_Absolute @ 0x2C
_03002AA4: .4byte Opcode_AND_Absolute @ 0x2D
_03002AA8: .4byte Opcode_ROL_Absolute @ 0x2E
_03002AAC: .4byte Opcode_NOP @ 0x2F
_03002AB0: .4byte Opcode_BMI @ 0x30
_03002AB4: .4byte Opcode_AND_IndirectY @ 0x31
_03002AB8: .4byte Opcode_NOP @ 0x32
_03002ABC: .4byte Opcode_NOP @ 0x33
_03002AC0: .4byte Opcode_NOP @ 0x34
_03002AC4: .4byte Opcode_AND_ZeroPageX @ 0x35
_03002AC8: .4byte Opcode_ROL_ZeroPageX @ 0x36
_03002ACC: .4byte Opcode_NOP @ 0x37
_03002AD0: .4byte Opcode_CLC_SEC @ 0x38
_03002AD4: .4byte Opcode_AND_AbsoluteY @ 0x39
_03002AD8: .4byte Opcode_NOP @ 0x3A
_03002ADC: .4byte Opcode_NOP @ 0x3B
_03002AE0: .4byte Opcode_NOP @ 0x3C
_03002AE4: .4byte Opcode_AND_AbsoluteX @ 0x3D
_03002AE8: .4byte Opcode_ROL_AbsoluteX @ 0x3E
_03002AEC: .4byte Opcode_NOP @ 0x3F
_03002AF0: .4byte Opcode_RTI @ 0x40
_03002AF4: .4byte Opcode_EOR_IndirectX @ 0x41
_03002AF8: .4byte Opcode_NOP @ 0x42
_03002AFC: .4byte Opcode_NOP @ 0x43
_03002B00: .4byte Opcode_NOP @ 0x44
_03002B04: .4byte Opcode_EOR_ZeroPage @ 0x45
_03002B08: .4byte Opcode_LSR_ZeroPage @ 0x46
_03002B0C: .4byte Opcode_NOP @ 0x47
_03002B10: .4byte Opcode_PHA @ 0x48
_03002B14: .4byte Opcode_EOR_Immediate @ 0x49
_03002B18: .4byte Opcode_LSR_Accumulator @ 0x4A
_03002B1C: .4byte Opcode_NOP @ 0x4B
_03002B20: .4byte Opcode_JMP_Absolute @ 0x4C
_03002B24: .4byte Opcode_EOR_Absolute @ 0x4D
_03002B28: .4byte Opcode_LSR_Absolute @ 0x4E
_03002B2C: .4byte Opcode_NOP @ 0x4F
_03002B30: .4byte Opcode_BVC @ 0x50
_03002B34: .4byte Opcode_EOR_IndirectY @ 0x51
_03002B38: .4byte Opcode_NOP @ 0x52
_03002B3C: .4byte Opcode_NOP @ 0x53
_03002B40: .4byte Opcode_NOP @ 0x54
_03002B44: .4byte Opcode_EOR_ZeroPageX @ 0x55
_03002B48: .4byte Opcode_LSR_ZeroPageX @ 0x56
_03002B4C: .4byte Opcode_NOP @ 0x57
_03002B50: .4byte Opcode_CLI @ 0x58
_03002B54: .4byte Opcode_EOR_AbsoluteY @ 0x59
_03002B58: .4byte Opcode_NOP @ 0x5A
_03002B5C: .4byte Opcode_NOP @ 0x5B
_03002B60: .4byte Opcode_NOP @ 0x5C
_03002B64: .4byte Opcode_EOR_AbsoluteX @ 0x5D
_03002B68: .4byte Opcode_LSR_AbsoluteX @ 0x5E
_03002B6C: .4byte Opcode_NOP @ 0x5F
_03002B70: .4byte Opcode_RTS @ 0x60
_03002B74: .4byte Opcode_ADC_IndirectX @ 0x61
_03002B78: .4byte Opcode_NOP @ 0x62
_03002B7C: .4byte Opcode_NOP @ 0x63
_03002B80: .4byte Opcode_NOP @ 0x64
_03002B84: .4byte Opcode_ADC_ZeroPage @ 0x65
_03002B88: .4byte Opcode_ROR_ZeroPage @ 0x66
_03002B8C: .4byte Opcode_NOP @ 0x67
_03002B90: .4byte Opcode_PLA @ 0x68
_03002B94: .4byte Opcode_ADC_Immediate @ 0x69
_03002B98: .4byte Opcode_ROR_Accumulator @ 0x6A
_03002B9C: .4byte Opcode_NOP @ 0x6B
_03002BA0: .4byte Opcode_JMP_Indirect @ 0x6C
_03002BA4: .4byte Opcode_ADC_Absolute @ 0x6D
_03002BA8: .4byte Opcode_ROR_Absolute @ 0x6E
_03002BAC: .4byte Opcode_NOP @ 0x6F
_03002BB0: .4byte Opcode_BVS @ 0x70
_03002BB4: .4byte Opcode_ADC_IndirectY @ 0x71
_03002BB8: .4byte Opcode_NOP @ 0x72
_03002BBC: .4byte Opcode_NOP @ 0x73
_03002BC0: .4byte Opcode_NOP @ 0x74
_03002BC4: .4byte Opcode_ADC_ZeroPageX @ 0x75
_03002BC8: .4byte Opcode_ROR_ZeroPageX @ 0x76
_03002BCC: .4byte Opcode_NOP @ 0x77
_03002BD0: .4byte Opcode_SEI @ 0x78
_03002BD4: .4byte Opcode_ADC_AbsoluteY @ 0x79
_03002BD8: .4byte Opcode_NOP @ 0x7A
_03002BDC: .4byte Opcode_NOP @ 0x7B
_03002BE0: .4byte Opcode_NOP @ 0x7C
_03002BE4: .4byte Opcode_ADC_AbsoluteX @ 0x7D
_03002BE8: .4byte Opcode_ROR_AbsoluteX @ 0x7E
_03002BEC: .4byte Opcode_NOP @ 0x7F
_03002BF0: .4byte Opcode_NOP @ 0x80
_03002BF4: .4byte Opcode_STA_IndirectX @ 0x81
_03002BF8: .4byte Opcode_NOP @ 0x82
_03002BFC: .4byte Opcode_NOP @ 0x83
_03002C00: .4byte Opcode_STY_ZeroPage @ 0x84
_03002C04: .4byte Opcode_STA_ZeroPage @ 0x85
_03002C08: .4byte Opcode_STX_ZeroPage @ 0x86
_03002C0C: .4byte Opcode_NOP @ 0x87
_03002C10: .4byte Opcode_DEY @ 0x88
_03002C14: .4byte Opcode_NOP @ 0x89
_03002C18: .4byte Opcode_TXA @ 0x8A
_03002C1C: .4byte Opcode_NOP @ 0x8B
_03002C20: .4byte Opcode_STY_Absolute @ 0x8C
_03002C24: .4byte Opcode_STA_Absolute @ 0x8D
_03002C28: .4byte Opcode_STX_Absolute @ 0x8E
_03002C2C: .4byte Opcode_NOP @ 0x8F
_03002C30: .4byte Opcode_BCC @ 0x90
_03002C34: .4byte Opcode_STA_IndirectY @ 0x91
_03002C38: .4byte Opcode_NOP @ 0x92
_03002C3C: .4byte Opcode_NOP @ 0x93
_03002C40: .4byte Opcode_STY_ZeroPageX @ 0x94
_03002C44: .4byte Opcode_STA_ZeroPageX @ 0x95
_03002C48: .4byte Opcode_STX_ZeroPageX @ 0x96
_03002C4C: .4byte Opcode_NOP @ 0x97
_03002C50: .4byte Opcode_TYA @ 0x98
_03002C54: .4byte Opcode_STA_AbsoluteY @ 0x99
_03002C58: .4byte Opcode_TXS @ 0x9A
_03002C5C: .4byte Opcode_NOP @ 0x9B
_03002C60: .4byte Opcode_NOP @ 0x9C
_03002C64: .4byte Opcode_STA_AbsoluteX @ 0x9D
_03002C68: .4byte Opcode_NOP @ 0x9E
_03002C6C: .4byte Opcode_NOP @ 0x9F
_03002C70: .4byte Opcode_LDY_Immediate @ 0xA0
_03002C74: .4byte Opcode_LDA_IndirectX @ 0xA1
_03002C78: .4byte Opcode_LDX_Immediate @ 0xA2
_03002C7C: .4byte Opcode_NOP @ 0xA3
_03002C80: .4byte Opcode_LDY_ZeroPage @ 0xA4
_03002C84: .4byte Opcode_LDA_ZeroPage @ 0xA5
_03002C88: .4byte Opcode_LDX_ZeroPage @ 0xA6
_03002C8C: .4byte Opcode_NOP @ 0xA7
_03002C90: .4byte Opcode_TAY @ 0xA8
_03002C94: .4byte Opcode_LDA_Immediate @ 0xA9
_03002C98: .4byte Opcode_TAX @ 0xAA
_03002C9C: .4byte Opcode_NOP @ 0xAB
_03002CA0: .4byte Opcode_LDY_Absolute @ 0xAC
_03002CA4: .4byte Opcode_LDA_Absolute @ 0xAD
_03002CA8: .4byte Opcode_LDX_Absolute @ 0xAE
_03002CAC: .4byte Opcode_NOP @ 0xAF
_03002CB0: .4byte Opcode_BCS @ 0xB0
_03002CB4: .4byte Opcode_LDA_IndirectY @ 0xB1
_03002CB8: .4byte Opcode_NOP @ 0xB2
_03002CBC: .4byte Opcode_NOP @ 0xB3
_03002CC0: .4byte Opcode_LDY_ZeroPageX @ 0xB4
_03002CC4: .4byte Opcode_LDA_ZeroPageX @ 0xB5
_03002CC8: .4byte Opcode_LDX_ZeroPageX @ 0xB6
_03002CCC: .4byte Opcode_NOP @ 0xB7
_03002CD0: .4byte Opcode_CLV @ 0xB8
_03002CD4: .4byte Opcode_LDA_AbsoluteY @ 0xB9
_03002CD8: .4byte Opcode_TSX @ 0xBA
_03002CDC: .4byte Opcode_NOP @ 0xBB
_03002CE0: .4byte Opcode_LDY_AbsoluteX @ 0xBC
_03002CE4: .4byte Opcode_LDA_AbsoluteX @ 0xBD
_03002CE8: .4byte Opcode_LDX_AbsoluteY @ 0xBE
_03002CEC: .4byte Opcode_NOP @ 0xBF
_03002CF0: .4byte Opcode_CPY_Immediate @ 0xC0
_03002CF4: .4byte Opcode_CMP_IndirectX @ 0xC1
_03002CF8: .4byte Opcode_NOP @ 0xC2
_03002CFC: .4byte Opcode_NOP @ 0xC3
_03002D00: .4byte Opcode_CPY_ZeroPage @ 0xC4
_03002D04: .4byte Opcode_CMP_ZeroPage @ 0xC5
_03002D08: .4byte Opcode_DEC_ZeroPage @ 0xC6
_03002D0C: .4byte Opcode_NOP @ 0xC7
_03002D10: .4byte Opcode_INY @ 0xC8
_03002D14: .4byte Opcode_CMP_Immediate @ 0xC9
_03002D18: .4byte Opcode_DEX @ 0xCA
_03002D1C: .4byte Opcode_NOP @ 0xCB
_03002D20: .4byte Opcode_CPY_Absolute @ 0xCC
_03002D24: .4byte Opcode_CMP_Absolute @ 0xCD
_03002D28: .4byte Opcode_DEC_Absolute @ 0xCE
_03002D2C: .4byte Opcode_NOP @ 0xCF
_03002D30: .4byte Opcode_BNE @ 0xD0
_03002D34: .4byte Opcode_CMP_IndirectY @ 0xD1
_03002D38: .4byte Opcode_NOP @ 0xD2
_03002D3C: .4byte Opcode_NOP @ 0xD3
_03002D40: .4byte Opcode_NOP @ 0xD4
_03002D44: .4byte Opcode_CMP_ZeroPageX @ 0xD5
_03002D48: .4byte Opcode_DEC_ZeroPageX @ 0xD6
_03002D4C: .4byte Opcode_NOP @ 0xD7
_03002D50: .4byte Opcode_CLD_SED @ 0xD8
_03002D54: .4byte Opcode_CMP_AbsoluteY @ 0xD9
_03002D58: .4byte Opcode_NOP @ 0xDA
_03002D5C: .4byte Opcode_NOP @ 0xDB
_03002D60: .4byte Opcode_NOP @ 0xDC
_03002D64: .4byte Opcode_CMP_AbsoluteX @ 0xDD
_03002D68: .4byte Opcode_DEC_AbsoluteX @ 0xDE
_03002D6C: .4byte Opcode_NOP @ 0xDF
_03002D70: .4byte Opcode_CPX_Immediate @ 0xE0
_03002D74: .4byte Opcode_SBC_IndirectX @ 0xE1
_03002D78: .4byte Opcode_NOP @ 0xE2
_03002D7C: .4byte Opcode_NOP @ 0xE3
_03002D80: .4byte Opcode_CPX_ZeroPage @ 0xE4
_03002D84: .4byte Opcode_SBC_ZeroPage @ 0xE5
_03002D88: .4byte Opcode_INC_ZeroPage @ 0xE6
_03002D8C: .4byte Opcode_NOP @ 0xE7
_03002D90: .4byte Opcode_INX @ 0xE8
_03002D94: .4byte Opcode_SBC_Immediate @ 0xE9
_03002D98: .4byte Opcode_NOP @ 0xEA
_03002D9C: .4byte Opcode_NOP @ 0xEB
_03002DA0: .4byte Opcode_CPX_Absolute @ 0xEC
_03002DA4: .4byte Opcode_SBC_Absolute @ 0xED
_03002DA8: .4byte Opcode_INC_Absolute @ 0xEE
_03002DAC: .4byte Opcode_NOP @ 0xEF
_03002DB0: .4byte Opcode_BEQ @ 0xF0
_03002DB4: .4byte Opcode_SBC_IndirectY @ 0xF1
_03002DB8: .4byte Opcode_NOP @ 0xF2
_03002DBC: .4byte Opcode_NOP @ 0xF3
_03002DC0: .4byte Opcode_NOP @ 0xF4
_03002DC4: .4byte Opcode_SBC_ZeroPageX @ 0xF5
_03002DC8: .4byte Opcode_INC_ZeroPageX @ 0xF6
_03002DCC: .4byte Opcode_NOP @ 0xF7
_03002DD0: .4byte Opcode_CLD_SED @ 0xF8
_03002DD4: .4byte Opcode_SBC_AbsoluteY @ 0xF9
_03002DD8: .4byte Opcode_NOP @ 0xFA
_03002DDC: .4byte Opcode_NOP @ 0xFB
_03002DE0: .4byte Opcode_NOP @ 0xFC
_03002DE4: .4byte Opcode_SBC_AbsoluteX @ 0xFD
_03002DE8: .4byte Opcode_INC_AbsoluteX @ 0xFE
_03002DEC: .4byte Opcode_NOP @ 0xFF

	.section .text

	@ Potentially some sort of checksum/CRC function
	arm_func_start sub_03002DF0
sub_03002DF0: @ 0x03002DF0
	eor r8, r8, r9   @ r8 ^= r9

	@ loop 20 times:
	mov r12, #0x20
_03002DF8:
	lsrs r8, r8, #1  @ r8 >>= 1
	eorhs r8, r8, r10 @ if (r8 & 1): r8 ^= r10
	subs r12, r12, #1
	bne _03002DF8

	bx lr

	@ Seems to be the opcode handler
	@ r5 = 0x030073FC (is it always?)
	@ r12 = 0x030029F0 (is it always?)
	arm_func_start sub_03002E0C
sub_03002E0C: @ 0x03002E0C
	ldrb r1, [r5], #1 @ r1 = *r5++
	ldrb r0, [sp, #SP_A33]
	cmp r0, #0               @ if SP_A33 != 0:
	ldrbne r1, [sp, #SP_A32]     @ r1 = SP_A32
	movne r0, #0
	strbne r0, [sp, #SP_A32]     @ SP_A32 = 0
	strbne r0, [sp, #SP_A33]     @ SP_A33 = 0
	@ Goto r12[r1]
	ldr pc, [r12, r1, lsl #2]

	@ Reads from WRAM
	arm_func_start sub_03002E2C
sub_03002E2C: @ 0x03002E2C
	ldr r1, [sp, #SP_858]
	ldrb r3, [r0, r1, lsl #8]
	mov pc, lr

	@ Reads from ROM
	arm_func_start sub_03002E38
sub_03002E38: @ 0x03002E38
	ldr r1, [r11, r2, lsl #2]
	ldrb r3, [r0, r1, lsl #8]
	mov pc, lr

	@ Reads from PPU registers
	@ TODO: continue commenting from here
	arm_func_start sub_03002E44
sub_03002E44: @ 0x03002E44
	and r1, r0, #7
	lsr r3, r11, #0x10
	and r3, r3, #0xc0
	cmp r1, #7
	beq _03002E84
	bic r11, r11, #0xe00000
	ldr r1, [sp, #SP_9B0]
	cmp r1, r5
	strne r5, [sp, #SP_9B0]
	.global _03002E68
_03002E68:
	movne pc, lr
_03002E6C:
	ldr r1, [sp, #SP_8B4]
	ldrb r2, [sp, #SP_A35]
	cmp r1, r2
	movhs pc, lr
_03002E7C:
	bic r4, r4, #0xff000000
	mov pc, lr
_03002E84:
	ldr r1, [sp, #SP_8B8]
	cmp r1, #0x3000
	bge _03002EC8
	cmp r1, #0x2000
	blt _03002EE4
	add r2, sp, r1, lsr #10 @ WARNING: disassembler produces wrong instruction here
	ldrb r2, [r2, #SP_8A8]
	tst r2, #0xfe
	bne _03002EC8
	bic r12, r1, #0x2c00
	add r12, r12, r2, lsl #10
	lsl r12, r12, #1
	add r12, r12, #0x6000000
	add r12, r12, #0x2000
	ldrh r2, [r12]
	ldrb r3, [sp, #SP_A3F]
	strb r2, [sp, #SP_A3F]
_03002EC8:
	ldrb r2, [sp, #SP_8BC]
	tst r2, #4
	addeq r1, r1, #1
	addne r1, r1, #0x20
	str r1, [sp, #SP_8B8]
	add r12, r11, #0x44
	mov pc, lr
_03002EE4:
	add r2, r1, #0x6000000
	add r2, r2, #0x14000
	ldrh r2, [r2, r1]
	ldrb r3, [sp, #SP_A3F]
	strb r2, [sp, #SP_A3F]
	b _03002EC8

	@ Reads from APU/2A03 registers
	@ r0 = APU register address
	arm_func_start sub_03002EFC
sub_03002EFC: @ 0x03002EFC
	tst r0, #0x1f00 @ TODO: is this checking for outside APU space?
	bne _03002F2C
	and r2, r0, #0xff @ r2 = low byte of APU register address
	cmp r2, #0x15
	beq _03002F58 @ if r2 == SND_CHN: goto _03002F58
	blo _03002F2C @ if r2 < SND_CHN: goto _03002F2C
	cmp r2, #0x17
	blo _03002F68 @ if r2 < JOY2: goto _03002F68
	beq _03003010 @ if r2 == JOY2: goto _03003010
	cmp r2, #0x30 @ NOTE: this code should be unreachable
	blo _03002F2C
	bhs _03002F34
_03002F2C:
	lsr r3, r0, #8
	mov pc, lr
_03002F34:
	str r0, [sp, #SP_93C]
	str lr, [sp, #SP_938]
	adr lr, _03002F48
	ldr r2, _030031C8 @ =EmulatorAudio_GetActiveChannels
	bx r2
_03002F48:
	add r12, r11, #0x44
	mov r3, r0
	ldr r0, [sp, #SP_93C]
	ldr pc, [sp, #SP_938]
_03002F58:
	ldr r3, [sp, #SP_908]
	bic r2, r3, #0xc0
	str r2, [sp, #SP_908]
	mov pc, lr
_03002F68:
	ldr r2, [sp, #SP_828]
	mov r3, #0x40
	orr r3, r3, r2, lsr #31
	ldrb r1, [sp, #SP_A3B]
	tst r1, #1
	movne pc, lr
_03002F80:
	lsl r2, r2, #1
	str r2, [sp, #SP_828]
	ldr r0, [sp, #SP_820]
	tst r0, #0x20000000
	moveq pc, lr
_03002F94:
	ldrb r0, [sp, #SP_A34]
	add r0, r0, #1
	strb r0, [sp, #SP_A34]
	tst r0, #2
	orrne r3, r3, #4
	mov pc, lr

	@ Convert GBA keys into NES keys
	@ r0 = GBA keys
    arm_func_start sub_03002FAC
sub_03002FAC: @ 0x03002FAC
	lsl r1, r0, #0x1c
	add r2, pc, r1, lsr #0x1B
	ldrh r3, [r2, #0x18] @ r3 = _03002FD0[LOW_NYBBLE((u8)r0)]
	and r1, r0, #0xf0
	add r2, pc, r1, lsr #3
	ldrh r4, [r2, #0x2c] @ r4 = _03002FF0[HIGH_NYBBLE((u8)r0)]
	orr r3, r3, r4
	strb r3, [sp, #SP_823] @ SP_823 = r3 | r4
	bx lr
_03002FD0:
	.2byte 0x0000 @ 0
	.2byte 0x0080 @ A
	.2byte 0x0040 @ B
	.2byte 0x00C0 @ B|A
	.2byte 0x0020 @ SE
	.2byte 0x00A0 @ SE|A
	.2byte 0x0060 @ SE|B
	.2byte 0x00E0 @ SE|B|A
	.2byte 0x0010 @ ST
	.2byte 0x0090 @ ST|A
	.2byte 0x0050 @ ST|B
	.2byte 0x00D0 @ ST|B|A
	.2byte 0x0030 @ ST|SE
	.2byte 0x00B0 @ ST|SE|A
	.2byte 0x0070 @ ST|SE|B
	.2byte 0x00F0 @ ST|SE|B|A
_03002FF0:
	.2byte 0x0000 @ 0
	.2byte 0x0001 @ R
	.2byte 0x0002 @ L
	.2byte 0x0000 @ L|R
	.2byte 0x0008 @ U
	.2byte 0x0009 @ U|R
	.2byte 0x000A @ U|L
	.2byte 0x0000 @ U|L|R
	.2byte 0x0004 @ D
	.2byte 0x0005 @ D|R
	.2byte 0x0006 @ D|L
	.2byte 0x0000 @ D|L|R
	.2byte 0x0000 @ D|U
	.2byte 0x0000 @ D|U|R
	.2byte 0x0000 @ D|U|L
	.2byte 0x0000 @ D|U|L|R
_03003010:
	ldr r2, [sp, #SP_82C]
	mov r3, #0x40
	orr r3, r3, r2, lsr #31
	ldrb r1, [sp, #SP_A3B]
	tst r1, #1
	movne pc, lr
	lsl r2, r2, #1
	str r2, [sp, #SP_82C]
	mov pc, lr

	@ Invalid/Unused/Dontcare register
	arm_func_start sub_03003034
sub_03003034: @ 0x03003034
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398

	@ Writes to WRAM
	arm_func_start sub_03003044
sub_03003044: @ 0x03003044
	ldr r2, [sp, #SP_858]
	strb r1, [r0, r2, lsl #8]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398

	@ Writes to PPU registers
	arm_func_start sub_0300305C
sub_0300305C: @ 0x0300305C
	@ Goto _0300306C[r0]
	and r0, r0, #7
	ldr pc, [pc, r0, lsl #2]
_03003068:
	.4byte 0x00000000
_0300306C:
	.4byte sub_0600B018 @ PPUCTRL
	.4byte sub_0600B078 @ PPUMASK
	.4byte sub_03003034 @ PPUSTATUS
	.4byte sub_0600B078 @ OAMADDR
	.4byte sub_0600B068 @ OAMDATA
	.4byte sub_0600B090 @ PPUSCROLL
	.4byte sub_030031D4 @ PPUADDR
	.4byte sub_03003088 @ PPUDATA

	@ Writes to PPUDATA
	arm_func_start sub_03003088
sub_03003088: @ 0x03003088
	ldr r0, [sp, #SP_8B8]
	cmp r0, #0x3000
	bge _03003348
	cmp r0, #0x2000
	bge _03003220
	add r2, r0, #0x6000000
	add r2, r2, #0x14000
	strh r1, [r2, r0]!
	bic r2, r2, #0x1e
	ldr r1, [sp, #SP_9B8]
	cmp r1, r2
	beq _03003260
	str r2, [sp, #SP_9B8]
	cmp r1, #0
	beq _03003260
	add lr, sp, #0x900
	add lr, lr, #0xe4
	stm lr, {r0, r3, r4, r5, r6, r7, r8, r9, r10, r11}
	bl sub_030030E8
	add lr, sp, #0x900
	add lr, lr, #0xe4
	ldm lr, {r0, r3, r4, r5, r6, r7, r8, r9, r10, r11}
	add r12, r11, #0x44
	b _03003260

	arm_func_start sub_030030E8
sub_030030E8: @ 0x030030E8
	@ if r1 is between 0x06015400 and 0x06015540, return
	ldr r3, _030031CC @ =0x06015400
	cmp r1, r3
	blo _03003100
	ldr r3, _030031D0 @ =0x06015540
	cmp r1, r3
	bxlo lr

_03003100:
	ldm r1, {r3, r4, r5, r6, r7, r8, r9, r10} @ load r3-r10 from r1
	sub r11, r1, #0x4000 @ r11 = r1 - 0x4000
	mov r12, #0x7c00
	orr r12, r12, #0x6000000 @ r12 = 0x06007C00
	and r0, r3, #0xff
	ldr r0, [r12, r0, lsl #2]
	and r1, r7, #0xff
	ldr r1, [r12, r1, lsl #2]
	orr r1, r0, r1, lsl #1 @ r1 = r12[r3 & 0xFF] | (r12[r7 & 0xFF] << 1)
	and r3, r3, #0xff0000
	ldr r3, [r12, r3, lsr #14]
	and r7, r7, #0xff0000
	ldr r7, [r12, r7, lsr #14]
	orr r2, r3, r7, lsl #1 @ r2 = r12[(r3 & 0xFF0000) >> 14] | (r12[(r7 & 0xFF0000) >> 14] << 1)
	and r0, r4, #0xff
	ldr r0, [r12, r0, lsl #2]
	and r7, r8, #0xff
	ldr r7, [r12, r7, lsl #2]
	orr r3, r0, r7, lsl #1 @ r3 = r12[r4 & 0xFF] | (r12[r8 & 0xFF] << 1)
	and r4, r4, #0xff0000
	ldr r4, [r12, r4, lsr #14]
	and r8, r8, #0xff0000
	ldr r8, [r12, r8, lsr #14]
	orr r4, r4, r8, lsl #1 @ r4 = r12[(r4 & 0xFF0000) >> 14] | (r12[(r8 & 0xFF0000) >> 14] << 1)
	and r0, r6, #0xff
	ldr r0, [r12, r0, lsl #2]
	and r7, r10, #0xff
	ldr r7, [r12, r7, lsl #2]
	orr r7, r0, r7, lsl #1 @ r7 = r12[r6 & 0xFF] | (r12[r10 & 0xFF] << 1)
	and r6, r6, #0xff0000
	ldr r6, [r12, r6, lsr #14]
	and r10, r10, #0xff0000
	ldr r10, [r12, r10, lsr #14]
	orr r8, r6, r10, lsl #1 @ r8 = r12[(r6 & 0xFF0000) >> 14] | (r12[(r10 & 0xFF0000) >> 14] << 1)
	and r0, r5, #0xff0000
	ldr r0, [r12, r0, lsr #14]
	and r6, r9, #0xff0000
	ldr r6, [r12, r6, lsr #14]
	orr r6, r0, r6, lsl #1 @ r6 = r12[r5 & 0xFF] | (r12[r9 & 0xFF] << 1)
	and r5, r5, #0xff
	ldr r5, [r12, r5, lsl #2]
	and r9, r9, #0xff
	ldr r9, [r12, r9, lsl #2]
	orr r5, r5, r9, lsl #1 @ r5 = r12[(r5 & 0xFF0000) >> 14] | (r12[(r9 & 0xFF0000) >> 14] << 1)
	stm r11, {r1, r2, r3, r4, r5, r6, r7, r8} @ store r1-r8 to r11
	tst r11, #0x2000
	subeq r11, r11, #0x10000 @ if (r11 & 0x2000) == 0: r11 -= 0x10000
	subne r11, r11, #0xe000  @ else: r11 -= 0xE000
	stm r11, {r1, r2, r3, r4, r5, r6, r7, r8} @ store r1-r8 to r11
	bx lr
	.align 2, 0
_030031C8: .4byte EmulatorAudio_GetActiveChannels
_030031CC: .4byte 0x06015400
_030031D0: .4byte 0x06015540

	@ Writes to PPUADDR
	arm_func_start sub_030031D4
sub_030031D4: @ 0x030031D4
	tst r11, #0x200000
	eor r11, r11, #0x200000
	bne _030031F8
	bic r1, r1, #0xc0
	strb r1, [sp, #SP_8B9]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_030031F8:
	strb r1, [sp, #SP_8B8]
	ldr r0, [sp, #SP_8B8]
	lsr r2, r0, #2
	and r2, r2, #0x3f8
	orr r2, r2, r0, lsr #12
	str r2, [sp, #SP_9C0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03003220:
	add r2, sp, r0, lsr #10 @ WARNING: disassembler produces wrong instruction here
	ldrb r2, [r2, #SP_8A8]
	tst r2, #0xfe
	bne _03003260
	bic lr, r0, #0x2c00
	cmp lr, #0x3c0
	add lr, lr, r2, lsl #10
	add r0, lr, #0x6000000
	add r0, r0, #0x2000
	ldrh r0, [lr, r0]!
	and r0, r0, #0x3000
	orr r0, r0, r1
	strh r0, [lr]
	lsr lr, lr, #1
	bge _03003284
_0300325C:
	ldr r0, [sp, #SP_8B8]
_03003260:
	ldrb r1, [sp, #SP_8BC]
	tst r1, #4
	addeq r0, r0, #1
	addne r0, r0, #0x20
	str r0, [sp, #SP_8B8]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03003284:
	lsls r10, r10, #1
	and r0, lr, #7
	and lr, lr, #0x38
	lsl lr, lr, #5
	orr lr, lr, r0, lsl #3
	orr lr, lr, r2, lsl #11
	add lr, lr, #0x6000000
	add lr, lr, #0x2000
	orr r1, r1, r1, lsl #16
	mov r12, #0x3000
	orr r12, r12, r12, lsl #16
	ldm lr, {r0, r2}
	and r10, r12, r1, lsl #12
	bic r0, r0, r12
	orr r0, r0, r10
	and r10, r12, r1, lsl #10
	bic r2, r2, r12
	orr r2, r2, r10
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and r10, r12, r1, lsl #12
	bic r0, r0, r12
	orr r0, r0, r10
	and r10, r12, r1, lsl #10
	bic r2, r2, r12
	orr r2, r2, r10
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and r10, r12, r1, lsl #8
	bic r0, r0, r12
	orr r0, r0, r10
	and r10, r12, r1, lsl #6
	bic r2, r2, r12
	orr r2, r2, r10
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and r10, r12, r1, lsl #8
	bic r0, r0, r12
	orr r0, r0, r10
	and r10, r12, r1, lsl #6
	bic r2, r2, r12
	orr r2, r2, r10
	stm lr, {r0, r2}
	rrx r10, r10
	add r12, r11, #0x44
	b _0300325C
_03003348:
	subs r2, r0, #0x3f00
	blt _03003260
	cmp r2, #0x20
	bhs _03003260
	and r1, r1, #0x3f
	lsl r1, r1, #1
	tst r0, #0xf
	beq _03003380
	tst r0, #3
	beq _03003260
	and r2, r0, #0x1f
	add r2, r2, sp
	strb r1, [r2, #SP_8C4]
	b _03003260
_03003380:
	strb r1, [sp, #SP_8C4]
	strb r1, [sp, #SP_8C8]
	strb r1, [sp, #SP_8CC]
	strb r1, [sp, #SP_8D0]
	strb r1, [sp, #SP_8D4]
	strb r1, [sp, #SP_8D8]
	strb r1, [sp, #SP_8DC]
	strb r1, [sp, #SP_8E0]
	b _03003260

	@ Writes to APU/2A03 registers
	arm_func_start sub_030033A4
sub_030033A4: @ 0x030033A4
	tst r0, #0x1fc0
	bne sub_030034A8
	and r2, r0, #0x3f
	cmp r2, #0x20
	bge sub_030034A8
	subs r2, r2, #0x14
	blt sub_030034A8
	@ goto _030033C8[r2]
	ldr pc, [pc, r2, lsl #2]
_030033C4:
	.4byte 0x000000
_030033C8:
	.4byte sub_030033F8 @ OAMDMA
	.4byte sub_030034A8 @ SND_CHN
	.4byte sub_03003444 @ JOY1
	.4byte sub_03003494 @ JOY2
	.4byte sub_03003034 @ Invalid/Unused/Dontcare registers
	.4byte sub_03003034
	.4byte sub_03003034
	.4byte sub_03003034
	.4byte sub_03003034
	.4byte sub_03003034
	.4byte sub_03003034
	.4byte sub_03003034

	@ Writes to OAMDMA
	arm_func_start sub_030033F8
sub_030033F8: @ 0x030033F8
	mov lr, #0x4000000
	add lr, lr, #0xd4
	lsr r0, r1, #0xd
	ldr r0, [r11, r0, lsl #2]
	add r0, r0, r1
	lsl r0, r0, #8 @ r0 = (_030029AC[r1 >> 13] + r1) << 8
	mov r1, #0x6700
	orr r1, r1, #0x6000000
	mov r2, #-0x7c000000
	orr r2, r2, #0x40
	stm lr, {r0, r1, r2} @ DMA3(src=r0, dst=0x06006700, cnt=Enable, 32bit, 0x100 bytes)
	ldr r0, [sp, #SP_8B4]
	cmp r0, #0x80         @ if SP_8B4 < 0x80:
	addlt r0, r0, #4          @ SP_8B4 += 4
	str r0, [sp, #SP_8B4]
	adds r4, r4, #0x38000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398

	@ Writes to JOY1
	arm_func_start sub_03003444
sub_03003444: @ 0x03003444
	strb r1, [sp, #SP_A3B]
	tst r1, #1
	beq _03003484
	str r3, [sp, #SP_92C]
	str r4, [sp, #SP_930]
	mov lr, #0x4000000
	ldr r0, [lr, #0x130]
	mvn r0, r0, lsl #24
	lsr r0, r0, #0x18
	bl sub_03002FAC
	ldr r3, [sp, #SP_92C]
	ldr r4, [sp, #SP_930]
	add r0, sp, #0x820
	add r1, r0, #8
	ldm r0!, {r2, lr}
	stm r1!, {r2, lr}
_03003484:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398

	@ Writes to JOY2
	arm_func_start sub_03003494
sub_03003494: @ 0x03003494
	ands r2, r1, #0xc0
	strb r2, [sp, #SP_A3C]
	bne sub_030034A8
	mov r2, #0x40
	str r2, [sp, #SP_9D0]

	@ Writes to APU
	arm_func_start sub_030034A8
sub_030034A8: @ 0x030034A8
	str r3, [sp, #SP_884]
	@ Call SP_9B4 (EmulatorAudio_WriteToApu(apuRegister=r0, value=r1))
	ldr r3, [sp, #SP_9B4]
	adr lr, _030034B8
	bx r3
_030034B8:
	ldr r3, [sp, #SP_884]
	add r12, r11, #0x44
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398

@ Register usage:
@ r0-r3 are scratch
@ r4 top 2 bytes is the cycle counter (TODO: what are the rest of the bytes?)
@ r5 points to code execution (ROM)
@ r6 is likely the NES stack pointer (TODO: confirm)
@ r7 is used for Register A
@ r8 is used for Register X
@ r9 is used for Register Y
@ r10 is likely the carry flag (TODO: confirm)
@ r11 is the pointer to _030029AC (TODO: figure out positive indexes, negative indexes into read addresses)
@ r12 is the pointer to _030029F0 (positive indexes into opcode addresses, negative indexes into write addresses)

Opcode_LDA_Immediate: @ 0x030034D0
	ldrb r3, [r5], #1
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDX_Immediate: @ 0x030034E8
	ldrb r3, [r5], #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDY_Immediate: @ 0x03003500
	ldrb r3, [r5], #1
	and r9, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_ZeroPage: @ 0x03003518
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDX_ZeroPage: @ 0x03003534
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDY_ZeroPage: @ 0x03003550
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r9, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_ZeroPageX: @ 0x0300356C
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDX_ZeroPageX: @ 0x03003590
	ldrb r0, [r5], #1
	add r0, r0, r9
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDY_ZeroPageX: @ 0x030035B4
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r9, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_Absolute: @ 0x030035D8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _030035F4
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030035F4:
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDX_Absolute: @ 0x03003608
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003624
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003624:
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDY_Absolute: @ 0x03003638
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003654
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003654:
	and r9, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_AbsoluteX: @ 0x03003668
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03003688
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003688:
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_AbsoluteY: @ 0x0300369C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _030036BC
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030036BC:
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDX_AbsoluteY: @ 0x030036D0
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _030036F0
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030036F0:
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDY_AbsoluteX: @ 0x03003704
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03003724
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003724:
	and r9, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_IndirectY: @ 0x03003738
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _0300375C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_0300375C:
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LDA_IndirectX: @ 0x03003770
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003798
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003798:
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_ZeroPage: @ 0x030037AC
	ldrb r0, [r5], #1
	strb r7, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STX_ZeroPage: @ 0x030037C4
	ldrb r0, [r5], #1
	strb r8, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STY_ZeroPage: @ 0x030037DC
	ldrb r0, [r5], #1
	strb r9, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_ZeroPageX: @ 0x030037F4
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	strb r7, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STX_ZeroPageX: @ 0x03003814
	ldrb r0, [r5], #1
	add r0, r0, r9
	and r0, r0, #0xff
	strb r8, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STY_ZeroPageX: @ 0x03003834
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	strb r9, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_Absolute: @ 0x03003854
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STX_Absolute: @ 0x03003884
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r8
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STY_Absolute: @ 0x030038B4
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r9
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_AbsoluteX: @ 0x030038E4
	add r4, r4, #0x5000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_AbsoluteY: @ 0x03003918
	add r4, r4, #0x5000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_IndirectX: @ 0x0300394C
	add r4, r4, #0x6000000
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_STA_IndirectY: @ 0x03003988
	add r4, r4, #0x6000000
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [r12, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CLC_SEC: @ 0x030039C0
	lsl r10, r1, #0x1a
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_DEX: @ 0x030039D4
	sub r3, r8, #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_INX: @ 0x030039EC
	add r3, r8, #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_DEY: @ 0x03003A04
	sub r3, r9, #1
	and r9, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_INY: @ 0x03003A1C
	add r3, r9, #1
	and r9, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TXA: @ 0x03003A34
	mov r3, r8
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TYA: @ 0x03003A4C
	mov r3, r9
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TAX: @ 0x03003A64
	mov r3, r7
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TAY: @ 0x03003A7C
	mov r3, r7
	and r9, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_Immediate: @ 0x03003A94
	ldrb r3, [r5], #1
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPX_Immediate: @ 0x03003AB4
	ldrb r3, [r5], #1
	subs r3, r8, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPY_Immediate: @ 0x03003AD4
	ldrb r3, [r5], #1
	subs r3, r9, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_ZeroPage: @ 0x03003AF4
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPX_ZeroPage: @ 0x03003B18
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, r8, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPY_ZeroPage: @ 0x03003B3C
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, r9, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_ZeroPageX: @ 0x03003B60
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_Absolute: @ 0x03003B8C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003BA8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003BA8:
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPX_Absolute: @ 0x03003BC4
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003BE0
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003BE0:
	subs r3, r8, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CPY_Absolute: @ 0x03003BFC
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003C18
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003C18:
	subs r3, r9, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_AbsoluteX: @ 0x03003C34
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03003C54
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003C54:
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_AbsoluteY: @ 0x03003C70
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03003C90
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003C90:
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_IndirectX: @ 0x03003CAC
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003CD4
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003CD4:
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CMP_IndirectY: @ 0x03003CF0
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03003D14
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003D14:
	subs r3, r7, r3
	rrx r10, r10
	and r3, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_Immediate: @ 0x03003D30
	ldrb r3, [r5], #1
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_ZeroPage: @ 0x03003D68
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_ZeroPageX: @ 0x03003DA4
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_Absolute: @ 0x03003DE8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003E04
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003E04:
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_AbsoluteX: @ 0x03003E38
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03003E58
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003E58:
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_AbsoluteY: @ 0x03003E8C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03003EAC
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003EAC:
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_IndirectY: @ 0x03003EE0
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03003F04
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003F04:
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ADC_IndirectX: @ 0x03003F38
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003F60
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003F60:
	lsr r10, r10, #8
	orr r7, r10, r7, lsl #24
	orr r3, r10, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_IndirectX: @ 0x03003F94
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03003FBC
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03003FBC:
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_Immediate: @ 0x03003FEC
	ldrb r3, [r5], #1
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_ZeroPage: @ 0x03004020
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_ZeroPageX: @ 0x03004058
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_Absolute: @ 0x03004098
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _030040B4
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030040B4:
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_AbsoluteX: @ 0x030040E4
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004104
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004104:
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_AbsoluteY: @ 0x03004134
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03004154
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004154:
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_SBC_IndirectY: @ 0x03004184
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _030041A8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030041A8:
	lsls r10, r10, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx r10, r10
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_IndirectX: @ 0x030041D8
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004200
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004200:
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_Immediate: @ 0x03004218
	ldrb r3, [r5], #1
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_ZeroPage: @ 0x03004234
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_ZeroPageX: @ 0x03004254
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_Absolute: @ 0x0300427C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004298
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004298:
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_AbsoluteX: @ 0x030042B0
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _030042D0
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030042D0:
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_AbsoluteY: @ 0x030042E8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03004308
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004308:
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ORA_IndirectY: @ 0x03004320
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _03004344
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004344:
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_Immediate: @ 0x0300435C
	ldrb r3, [r5], #1
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_ZeroPage: @ 0x03004378
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_ZeroPageX: @ 0x03004398
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_Absolute: @ 0x030043C0
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _030043DC
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030043DC:
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_IndirectX: @ 0x030043F4
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _0300441C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_0300441C:
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_AbsoluteX: @ 0x03004434
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004454
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004454:
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_AbsoluteY: @ 0x0300446C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _0300448C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_0300448C:
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_AND_IndirectY: @ 0x030044A4
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _030044C8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030044C8:
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BIT_ZeroPage: @ 0x030044E0
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	bic sp, sp, #0x200000
	tst r3, #0x40
	orrne sp, sp, #0x200000
	tst r3, r7
	and r3, r3, #0x80
	lsl r3, r3, #2
	orrne r3, r3, #2
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BIT_Absolute: @ 0x03004514
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004530
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004530:
	bic sp, sp, #0x200000
	tst r3, #0x40
	orrne sp, sp, #0x200000
	tst r3, r7
	and r3, r3, #0x80
	lsl r3, r3, #2
	orrne r3, r3, #2
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_Immediate: @ 0x0300455C
	ldrb r3, [r5], #1
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_ZeroPage: @ 0x03004578
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_ZeroPageX: @ 0x03004598
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_Absolute: @ 0x030045C0
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _030045DC
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030045DC:
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_AbsoluteX: @ 0x030045F4
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004614
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_03004614:
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_AbsoluteY: @ 0x0300462C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _0300464C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_0300464C:
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_IndirectX: @ 0x03004664
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _0300468C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_0300468C:
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_EOR_IndirectY: @ 0x030046A4
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, r9
	lsrs r2, r0, #0xd
	adr lr, _030046C8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [sp, r0]
_030046C8:
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_INC_ZeroPage: @ 0x030046E0
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	add r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_INC_ZeroPageX: @ 0x03004700
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	add r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_INC_Absolute: @ 0x03004728
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _0300475C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	add r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_0300475C:
	add r4, r4, #0x6000000
	add r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_INC_AbsoluteX: @ 0x03004770
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _030047A8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	add r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_030047A8:
	add r4, r4, #0x7000000
	add r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_DEC_ZeroPage: @ 0x030047BC
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	sub r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_DEC_ZeroPageX: @ 0x030047DC
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	sub r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_DEC_Absolute: @ 0x03004804
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004838
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	sub r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004838:
	add r4, r4, #0x6000000
	sub r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_DEC_AbsoluteX: @ 0x0300484C
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004884
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	sub r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004884:
	add r4, r4, #0x7000000
	sub r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ASL_Accumulator: @ 0x03004898
	lsl r3, r7, #1
	lsl r10, r3, #0x17
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ASL_ZeroPage: @ 0x030048B4
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ASL_Absolute: @ 0x030048D8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004910
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004910:
	add r4, r4, #0x6000000
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ASL_AbsoluteX: @ 0x03004928
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004964
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004964:
	add r4, r4, #0x7000000
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ASL_ZeroPageX: @ 0x0300497C
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	lsl r10, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LSR_Accumulator: @ 0x030049A8
	lsr r3, r7, #1
	lsl r10, r7, #0x1f
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LSR_ZeroPage: @ 0x030049C4
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LSR_ZeroPageX: @ 0x030049E8
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_LSR_Absolute: @ 0x03004A14
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004A4C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004A4C:
	add r4, r4, #0x6000000
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_LSR_AbsoluteX: @ 0x03004A64
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004AA0
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004AA0:
	add r4, r4, #0x7000000
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ROL_Accumulator: @ 0x03004AB8
	lsl r3, r7, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROL_ZeroPage: @ 0x03004AD8
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROL_ZeroPageX: @ 0x03004B00
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROL_Absolute: @ 0x03004B30
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004B6C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004B6C:
	add r4, r4, #0x6000000
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ROL_AbsoluteX: @ 0x03004B88
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004BC8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004BC8:
	add r4, r4, #0x7000000
	lsl r3, r3, #1
	orr r3, r3, r10, lsr #31
	lsl r10, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ROR_Accumulator: @ 0x03004BE4
	tst r10, #-0x80000000
	orrne r7, r7, #0x100
	lsl r10, r7, #0x1f
	lsr r3, r7, #1
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROR_ZeroPage: @ 0x03004C08
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROR_ZeroPageX: @ 0x03004C34
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_ROR_Absolute: @ 0x03004C68
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	adr lr, _03004CA8
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004CA8:
	add r4, r4, #0x6000000
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_ROR_AbsoluteX: @ 0x03004CC8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	adr lr, _03004D0C
	ldrne pc, [r11, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004D0C:
	add r4, r4, #0x7000000
	tst r10, #-0x80000000
	orrne r3, r3, #0x100
	lsl r10, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [r12, -r2, lsl #2]
Opcode_BPL: @ 0x03004D2C
	tst r3, #0x280
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004D4C:
	add r5, r5, #1
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BMI: @ 0x03004D60
	tst r3, #0x280
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BVC: @ 0x03004D80
	tst sp, #0x200000
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BVS: @ 0x03004DA0
	tst sp, #0x200000
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BCC: @ 0x03004DC0
	tst r10, #-0x80000000
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BCS: @ 0x03004DE0
	tst r10, #-0x80000000
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BNE: @ 0x03004E00
	tst r3, #0xff
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BEQ: @ 0x03004E20
	tst r3, #0xff
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_JSR: @ 0x03004E40
	ldrb r0, [r5], #1
	sub r2, r5, r4, lsl #8
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsr r1, r2, #8
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	strb r2, [r6], #-1
	orr r6, r6, #0x100
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_PHA: @ 0x03004E84
	strb r7, [r6], #-1
	orr r6, r6, #0x100
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_PLA: @ 0x03004E9C
	and r0, r6, #0xff
	cmp r0, #0xff
	subeq r6, r6, #0x100
	ldrb r3, [r6, #1]!
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_RTS: @ 0x03004EC0
	ldrb r0, [r6, #1]!
	ldrb r1, [r6, #1]!
	tst r6, #0x100
	subeq r6, r6, #0x100
	orr r0, r0, r1, lsl #8
	add r0, r0, #1
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_JMP_Absolute: @ 0x03004EF8
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_JMP_Indirect: @ 0x03004F24
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	bne _03004F64
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03004F64:
	str r3, [sp, #SP_884]
	adr lr, _03004F70
	ldr pc, [r11, -r2, lsl #2]
_03004F70:
	strb r3, [sp, #SP_A3E]
	add r0, r0, #1
	lsrs r2, r0, #0xd
	adr lr, _03004F84
	ldr pc, [r11, -r2, lsl #2]
_03004F84:
	ldrb r0, [sp, #SP_A3E]
	orr r0, r0, r3, lsl #8
	ldr r3, [sp, #SP_884]
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_BRK: @ 0x03004FB0
	add r5, r5, #1
	mvn r0, #1
	mov lr, #0xa0000
	b _0300516C
Opcode_PHP: @ 0x03004FC0
	lsr r1, r10, #0x1f
	tst r3, #0xff
	orreq r1, r1, #2
	orr r1, r1, sp, lsr #15
	tst r3, #0x280
	orrne r1, r1, #0x80
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_PLP: @ 0x03004FF0
	and r0, r6, #0xff
	cmp r0, #0xff
	subeq r6, r6, #0x100
	ldrb r1, [r6, #1]!
	lsl r10, r1, #0x1f
	and r3, r1, #2
	eor r3, r3, #2
	tst r1, #0x80
	orrne r3, r3, #0x200
	and r1, r1, #0x7c
	bic sp, sp, #0x3e0000
	orr sp, sp, r1, lsl #15
	tst sp, #0x820000
	beq _030050B8
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_RTI: @ 0x03005038
	ldrb r0, [r6, #1]!
	lsl r10, r0, #0x1f
	and r3, r0, #2
	eor r3, r3, #2
	tst r0, #0x80
	orrne r3, r3, #0x200
	and r0, r0, #0x7c
	bic sp, sp, #0x3e0000
	orr sp, sp, r0, lsl #15
	ldrb r0, [r6, #1]!
	ldrb r1, [r6, #1]!
	tst r6, #0x100
	subeq r6, r6, #0x100
	orr r0, r0, r1, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	tst sp, #0x820000
	beq _030050B8
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CLI: @ 0x0300509C
	bic sp, sp, #0x20000
	tst sp, #0x800000
	beq _030050B8
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_030050B8:
	orr sp, sp, #0x800000
_030050BC:
	mvn r0, #1
	b _03005168
Opcode_SEI: @ 0x030050C4
	orr sp, sp, #0x20000
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TXS: @ 0x030050D8
	bic r6, r6, #0xff
	orr r6, r6, r8
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_TSX: @ 0x030050F0
	and r3, r6, #0xff
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CLV: @ 0x03005108
	bic sp, sp, #0x200000
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_CLD_SED: @ 0x0300511C
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
Opcode_NOP: @ 0x0300512C
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_0300513C:
	strb r1, [sp, #SP_A32]
	sub r5, r5, #1
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03005154:
	add r12, r12, #1
	str r12, [sp, #SP_8B4]
	add r12, r11, #0x44
	adds r4, r4, #-0x72000000
	mvn r0, #5
_03005168:
	mov lr, #0x20000
_0300516C:
	sub r2, r5, r4, lsl #8
	lsr r1, r2, #8
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	strb r2, [r6], #-1
	orr r6, r6, #0x100
	bic sp, sp, #0x80000
	lsr r1, r10, #0x1f
	tst r3, #0xff
	orreq r1, r1, #2
	orr r1, r1, sp, lsr #15
	tst r3, #0x280
	orrne r1, r1, #0x80
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	orr sp, sp, lr
	add r2, r0, #0x10000
	ldr r1, [r11, #0x1c]
	add r1, r2, r1, lsl #8
	ldrh r0, [r1]
	lsr r1, r0, #0xd
	ldr r1, [r11, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrb r1, [r5], #1
	ldr pc, [r12, r1, lsl #2]
_030051D8:
	mov lr, #0x4000000
	ldrh r1, [lr]
	ldrb r2, [sp, #SP_8BD]
	ldrb r0, [sp, #SP_A41]
	subs r0, r0, #1
	strbpl r0, [sp, #SP_A41]
	bhs _030051FC
	tst r2, #8
	orrne r1, r1, #0x800
_030051FC:
	ldrb r0, [sp, #SP_A42]
	subs r0, r0, #1
	strbpl r0, [sp, #SP_A42]
	bhs _03005214
	tst r2, #0x10
	orrne r1, r1, #0x1000
_03005214:
	strh r1, [lr]
	bic r11, r11, #0x400000
	orr r11, r11, #0x800000
	mov r1, #0xff
	strb r1, [sp, #SP_A35]
	mvn r12, #0x15
	str r12, [sp, #SP_8B4]
	adds r4, r4, #-0x72000000
	add r0, sp, #0x800
	add r0, r0, #0x84
	stm r0!, {r3, r4, r5, r6, r7, r8, r9, r10, r11}
	and r1, sp, #0xfe0000
	str r1, [r0, #4]
	mov r0, #0
	ldr pc, [sp, #SP_9BC]

	arm_func_start sub_03005250
sub_03005250: @ 0x03005250
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	mov pc, lr

	@ V-Blank interrupt
	arm_func_start sub_0300525C
sub_0300525C: @ 0x0300525C
	add r12, r0, #0x800 @ r12 = 0x03007A00
	stm r12, {r4, r5, r6, r7, r8, lr} @ Backup 0x03007A00 to r4-r8, lr
	ldr r4, [r0, #SP_840]
	add r4, r4, #1
	str r4, [r0, #SP_840] @ SP_840 += 1
	mov lr, #0x4000000
	ldr r4, [lr, #0x130]
	mvn r4, r4, lsl #0x16
	lsr r4, r4, #0x16 @ r4 = ~(REG_KEY_INPUT << 0x16) >> 0x16
	ldr r5, [r0, #SP_90C] @ r5 = SP_90C
	str r4, [r0, #SP_90C] @ SP_90C = r4
	eor r1, r4, r5
	and r1, r1, r4
	str r1, [r0, #SP_910] @ SP_910 = (r4 ^ r5) & r4
	str r4, [r0, #SP_914] @ SP_914 = r4
	mov r4, #0
	str r4, [lr, #0xb8] @ REG_DMA0_CNT = 0
	str r4, [lr, #0xd0]! @ REG_DMA2_CNT = 0
	ldrb r5, [r0, #SP_A48]
	cmp r5, #0               @ if SP_A48 != 0:
	ldrbne r5, [r0, #SP_A49]
	strbne r5, [r0, #SP_A48]     @ SP_A48 = SP_A49
	bne _03005390                @ goto _03005390
	ldr r1, [r0, #SP_8F0]   @ r1 = SP_8F0
	cmp r1, #0              @ if SP_8F0 != 0:
	strne r4, [r0, #SP_8F0]     @ SP_8F0 = 0
	strne r1, [r0, #SP_8F4]     @ SP_8F4 = r1
	ldreq r1, [r0, #SP_8F4] @ else:
	cmpeq r1, #0                @ if SP_8F4 == 0:
	beq _03005390                   @ goto _03005390
	mov r3, #0x7000000
	add r3, r3, #0x1e0
	mov r5, #-0x7c000000
	orr r5, r5, #0x80
	stmib lr, {r1, r3, r5} @ DMA(src=SP_8F4, dst=0x070001E0 (OAM), cnt=Enable, 32bit, 0x200 bytes)
	add r1, r1, #0x200 @ r1 += 0x200
	ldm r1!, {r2}
	sub r3, lr, #0xb4
	str r2, [r3] @ REG_BG3HOFS = *r1++
	ldr r5, _03005394 @ =0xA2600002
	stmda lr, {r1, r3, r5} @ DMA(src=r1, dst=REG_BG3HOFS, cnt=Enable, Hblank, Repeat, Inc/Reload, 0x8 bytes)
	add r1, r1, #0x27c @ r1 += 0x27C
	ldrh r2, [r1], #2
	strh r2, [r3, #-0xe]! @ REG_BG3CNT = *r1++
	sub r5, r5, #1
	sub lr, lr, #0x20
	stm lr, {r1, r3, r5} @ DMA(src=r1, dst=REG_BG3CNT, cnt=Enable, Hblank, Repeat, Inc/Reload, 0x4 bytes)
	add r1, r0, #0x800
	add r1, r1, #0xc4 @ r1 = &SP_8C4
	mov r2, #0xb800
	orr r2, r2, #0x6000000 @ r2 = 0x0600B800
	ldrb r6, [r0, #SP_8BD]
	tst r6, #1           @ if SP_8BD & 1:
	addne r2, r2, #0x400     @ r2 = 0x0600BC00
	and r6, r6, #0xe0
	add r2, r2, r6, lsl #2 @ r2 = r2 + (SP_8BD & 0xE0) * 4
	mov lr, #0x5000000 @ lr = 0x05000000
	ldrb r6, [r1], #1
	ldrh r6, [r2, r6] @ r6 = r2[*r1++]

_03005348:
	ldrb r3, [r1], #1
	ldrh r3, [r2, r3]
	orr r3, r6, r3, lsl #0x10 @ r3 = r6 | (r2[*r1++] << 0x10)
	ldrb r4, [r1], #1
	ldrh r4, [r2, r4]
	ldrb r5, [r1], #2
	ldrh r5, [r2, r5]
	orr r4, r4, r5, lsl #0x10 @ r4 = r2[*r1++] | (r2[*r1, r1 += 2] << 0x10)
	stm lr, {r3, r4} @ *lr = r3, *(lr + 1) = r4
	add lr, lr, #0x20 @ lr += 0x20
	tst lr, #0x60
	bne _03005348
	tst lr, #0x200
	addeq lr, lr, #0x180
	beq _03005348

	mov lr, #0x5000000
	ldr r6, [lr, #0x40]
	str r6, [lr, #0x84] @ 0x05000084 = [0x05000040]
_03005390:
	ldm r12, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_03005394: .4byte 0xA2600002

    arm_func_start _03005398
_03005398: @ 0x03005398
	ldr r12, [sp, #SP_8B4]
	cmp r12, #0xf0 @ if SP_8B4 >= 0xF0:
	bhs _0300552C     @ goto _0300552C
	cmp r12, #0xe2 @ if SP_8B4 >= 0xE2:
	bhs _03005478     @ goto _03005478
	subs r0, r12, #0xc @ r0 = SP_8B4 - 0xC
	ldrlo r0, [sp, #SP_9C0] @ if r0 < 0: r0 = SP_9C0
	blo _03005478			    @ goto _03005478
	bne _03005418 @ if r0 != 0: goto _03005418
	mov lr, #0x4000000
	ldrh r1, [lr]
	ldrb r2, [sp, #SP_8BD]
	tst r2, #8
	biceq r1, r1, #0x800
	moveq r2, #2
	strbeq r2, [sp, #SP_A41]
	ldrbeq r2, [sp, #SP_8BD]
	tst r2, #0x10
	biceq r1, r1, #0x1000
	moveq r2, #2
	strbeq r2, [sp, #SP_A42]
	strh r1, [lr]
	bic r11, r11, #0xc0000
	ldr r1, [sp, #SP_8E4]
	ldr r2, [sp, #SP_8E8]
	str r1, [sp, #SP_96C]
	str r2, [sp, #SP_970]
	tst r11, #0x100000
	streq r1, [sp, #SP_94C]
	strne r2, [sp, #SP_94C]
	mov r1, #0
	strb r1, [sp, #SP_A40]
_03005418:
	mov lr, #0x6000
	orr lr, lr, #0x6000000
	add lr, lr, r0, lsl #3
	ldrb r0, [sp, #SP_8E4]
	cmp r0, #0
	movne r0, #0xa
	tst r11, #0x100000
	orrne r0, r0, #5
	strh r0, [lr, #2]
	ldrb r0, [sp, #SP_9C1]
	add r1, sp, r0 @ WARNING: disassembler produces wrong instruction here
	ldrb r1, [r1, #SP_8B0]
	eor r0, r0, #1
	add r0, sp, r0 @ WARNING: disassembler produces wrong instruction here
	ldrb r0, [r0, #SP_8B0]
	orr r0, r0, r1, lsl #6
	ldr r1, [sp, #SP_8BC]
	bic r1, r1, #0xc3
	orr r1, r1, r0
	strh r1, [lr]
	ldr r0, [sp, #SP_9C0]
	ldrb r1, [sp, #SP_A39]
	orr r1, r1, r0, lsl #8
	strh r1, [lr, #4]
_03005478:
	add r0, r0, #1
	ands r1, r0, #0xff
	subeq r0, r0, #0x100
	cmp r1, #0xf0
	addeq r0, r0, #0x110
	bic r0, r0, #0xfc00
	str r0, [sp, #SP_9C0]
	mov r2, #0x6700
	orr r2, r2, #0x6000000
	ldrh r2, [r2]
	and r2, r2, #0xff
	cmp r2, r12
	bne _030054B0
	strb r2, [sp, #SP_A35]
_030054B0:
	ldrb r2, [sp, #SP_A35]
	cmp r12, r2
	orreq r11, r11, #0x400000
	ldr r2, [sp, #SP_9D0]
	cmp r12, r2
	bne _03005504
	ldrb r0, [sp, #SP_A3C]
	tst r0, #0xc0
	bne _03005504
	ldrb r0, [sp, #SP_908]
	orr r0, r0, #0x40
	strb r0, [sp, #SP_908]
	tst sp, #0x20000
	bicne sp, sp, #0x800000
	bne _03005504
	orr sp, sp, #0x800000
	add r12, r12, #1
	str r12, [sp, #SP_8B4]
	add r12, r11, #0x44
	adds r4, r4, #-0x72000000
	b _030050BC
_03005504:
	add r12, r12, #1
	str r12, [sp, #SP_8B4]
	add r12, r11, #0x44
	adds r4, r4, #-0x72000000
	ldrb r1, [r5], #1
	ldr pc, [r12, r1, lsl #2]
_0300551C:
	ldrb r0, [sp, #SP_8BC]
	tst r0, #0x80
	bne _03005154
	b _03005504
_0300552C:
	beq _030051D8
	cmn r12, #0x15
	beq _0300551C
	cmn r12, #1
	bne _03005504
	bic r11, r11, #0xc00000
	ldr r1, [sp, #SP_9C4]
	ldr r0, [sp, #SP_830]
	add r1, r1, r0
	str r1, [sp, #SP_9C0]
	b _03005504
_03005558: .4byte 0x040000D4
_0300555C: .4byte sUnk_0203E634
_03005560: .4byte 0x06003060
_03005564: .4byte 0x80000010

	arm_func_start sub_03005568
sub_03005568: @ 0x03005568
	ldrb r0, [sp, #SP_A46] @ r0 = SP_A46
	cmp r0, #0x18 @ if SP_A46 >= 0x18:
	movhs r0, #0      @ r0 = 0
	lsr r1, r0, #2 @ r1 = r0 >> 2
	add r0, r0, #1 @ r0 += 1
	strb r0, [sp, #SP_A46] @ SP_A46 = r0
	adr r0, _03005558 @ r0 = &_03005558
	ldm r0, {r2, r3, r4, r5}
	add r3, r3, r1, lsl #5
	stm r2, {r3, r4, r5} @ DMA3(src=sUnk_0203E634+(r1<<5), dst=0x06003060, cnt=Enable, 16bit, 0x20 bytes)
_03005590:
	ldr r12, [sp, #SP_8EC]
	ldr r0, [sp, #SP_8F4]
	cmp r0, r12    @ if SP_8F4 == SP_8EC:
	svceq #0x20000     @ Halt
	beq _03005590      @ Goto _03005590
	ldr r0, [sp, #SP_830] @ r0 = SP_830
	cmp r0, #0               @ if r0 == 0:
	moveq r0, #0x9600000         @ r0 = 0x09600000
	lslne r0, r0, #0x18      @ else:
	addne r0, r0, #0xc000000     @ r0 = (r0 << 0x18) + 0x0C000000
	str r0, [sp, #SP_838] @ SP_838 = r0
	moveq r0, #0xc00000   @ if r0 == 0: r0 = 0x00C00000
	movne r0, #0x1000000  @ else: r0 = 0x01000000
	str r0, [sp, #SP_834] @ SP_834 = r0
	ldr r1, [sp, #SP_8F8]
	sub r1, r1, r12
	str r1, [sp, #SP_8EC] @ SP_8EC = SP_8F8 - SP_8EC

	mov r7, #0x6700
	orr r7, r7, #0x6000000 @ r7 = 0x06006700
	add r6, r12, #0x200 @ r6 = r12 + 0x200
	sub lr, r7, #0x760 @ lr = 0x06005FA0
_030055E4:
	ldr r10, [r7], #4
	and r9, r10, #0xff
	add r9, r9, #1
	cmp r9, #0xf0
	bhs _0300567C
	subs r0, r9, #0xc
	addhs r11, lr, r9, lsl #3
	addlo r11, lr, #0x60
	ldrh r8, [r11]
	tst r8, #0x1000
	beq _0300567C
	and r0, r10, #0xc00000
	lsl r0, r0, #6
	and r1, r10, #0xff000000
	lsr r1, r1, #1
	sub r1, r1, #0x4000000
	lsr r1, r1, #7
	orr r0, r0, r1
	ldr r2, [sp, #SP_834]
	mul r1, r9, r2
	ldr r2, [sp, #SP_838]
	sub r1, r1, r2
	orr r0, r0, r1, lsr #24
	and r1, r10, #0x30000
	lsr r1, r1, #4
	tst r10, #0x200000
	orreq r1, r1, #0x400
	orrne r1, r1, #0x800
	and r10, r10, #0xff00
	tst r8, #0x20
	andeq r2, r8, #8
	orrne r0, r0, #0x8000
	andne r2, r10, #0x100
	bicne r10, r10, #0x100
	cmp r2, #0
	orrne r10, r10, #0x10000
	orr r1, r1, r10, lsr #8
	stm r12!, {r0, r1}
_0300567C:
	tst r7, #0xff
	bne _030055E4
	mov r0, #0xa0
_03005688:
	cmp r12, r6
	strlo r0, [r12], #8
	blo _03005688
	add r9, r12, #0x280
	mov r10, #0
	ldr lr, [sp, #SP_900]
	ldr r0, [sp, #SP_830]
	cmp r0, #0
	beq _030056B4
	mov r4, #0
	b _030056E8
_030056B4:
	ldr r0, [sp, #SP_8FC]
	ror r0, r0, #0x10
	lsl r0, r0, #0x10
	orr r4, r0, r0, lsr #16
	ldr r0, [sp, #SP_9C4]
	and r0, r0, #3
	rsb r0, r0, #0x20
	rors r4, r4, r0
	rorpl r4, r4, #1
	addmi lr, lr, #8
	b _030056E8
_030056E0:
	lsl r0, r0, #0x10
	orr r4, r0, r0, lsr #16
_030056E8:
	ldrh r8, [lr]
	tst r8, #0x800
	beq _03005794
	mov r7, #0x400
	orr r7, r7, #1
	and r0, r8, r8, lsr #6
	ands r2, r0, #1
	orrne r7, r7, #0x8000
	eor r0, r8, r8, lsr #6
	tst r0, #1
	orrne r7, r7, #0x4000
	ldrh r0, [lr, #2]
	and r0, r0, #0xc
	ldr r1, [sp, #SP_830]
	cmp r1, #0
	movne r0, #0xc
	orr r7, r7, r0
	orr r7, r7, r7, lsl #16
	ldrh r0, [lr, #4]
	and r1, r0, #0xff
	tst r8, #0x40
	orrne r1, r1, #0x100
	add r5, r1, #8
	and r0, r0, #0xff00
	orr r0, r0, r2, lsl #16
	sub r0, r0, r10, lsl #8
	orr r5, r5, r0, lsl #8
_03005754:
	strh r7, [r9], #2
	str r5, [r12], #4
	add lr, lr, #8
	rors r4, r4, #0x1f
	addmi lr, lr, #8
	rormi r4, r4, #0x1f
	add r10, r10, #1
	cmp r10, #0xa0
	blo _030056E8
_03005778:
	ldr r0, [sp, #SP_8F0]
	cmp r0, #0
	bne _03005778
	sub r1, r12, #0x480
	str r1, [sp, #SP_8F0]
	ldr pc, _03005790 @ =sub_0600E2C4
	.align 2, 0
_03005790: .4byte sub_0600E2C4
_03005794:
	ldr r7, _030057A4 @ =0x0000C401
	mov r0, #0x1000000
	sub r5, r0, r10, lsl #16
	b _03005754
	.align 2, 0
_030057A4: .4byte 0x0000C401

	@ Interrupt handler
	arm_func_start sub_030057A8
sub_030057A8: @ 0x030057A8
	mov r12, #0x4000000
	ldr r2, [r12, #0x200]
	and r1, r2, r2, lsr #0x10 @ r1 = REG_IF & REG_IE
	ands r2, r1, #0x2000 @ if Game Pak interrupt:
	bne _0300580C            @ goto _0300580C
	ands r0, r1, #0x10   @ if Timer 1 interrupt:
	bne _030057E4            @ goto _030057E4
	add r2, r2, #4 @ r2 = 4
	ands r0, r1, #1      @ if V-Blank interrupt:
	strhne r0, [r12, #-8]     @ 0x3007FF8 (Interrupt check flag) = 1
	bne _030057E4            @ goto _030057E4
	add r2, r2, #4 @ r2 = 8
	ands r0, r1, #0x40 @ if Timer 3 interrupt:
	bne _030057E4          @ goto _030057E4
	add r2, r2, #4 @ r2 = 12
_030057E4:
	add r12, r12, #0x200
	strh r0, [r12, #2] @ REG_IF = r0
	ldr r0, sUnk_03005808
	@ goto _030057F8[r2]
	ldr r12, [pc, r2]
	bx r12
_030057F8:
	.4byte EmulatorAudio_Timer1Callback @ Timer 1 Interrupt
	.4byte sub_0300525C @ V-Blank Interrupt
	.4byte sub_0300582C @ Timer 3 Interrupt
	.4byte sub_0300583C @ All other interrupts
    .global sUnk_03005808
sUnk_03005808: .4byte 0x00000000
_0300580C:
	strb r2, [r12, #0x84]
	ldr r0, sUnk_03005808
	ldr r1, [r0, #0x928]
	strh r1, [r12]
	mov r12, #0x5000000
	mov r1, #0
	strh r1, [r12]
_03005828:
	b _03005828

	@ Timer 3 Interrupt
	arm_func_start sub_0300582C
sub_0300582C: @ 0x0300582C
	ldr r12, [r0, #0x918]
	cmp r12, #0
	bxeq lr
	bx r12

	arm_func_start sub_0300583C
sub_0300583C: @ 0x0300583C
	bx lr

	.global sUnk_03005840
sUnk_03005840: @ 0x03005840
	.4byte 0x0600B800

	@ Writes to ROM (invalid?)
	arm_func_start sub_03005844
sub_03005844: @ 0x03005844
	tst r1, #0x80
	bne _03005880
	ldrb r2, [sp, #SP_A55]
	tst r1, #1
	orrne r2, r2, #0x20
	lsr r2, r2, #1
	ldrb r1, [sp, #SP_A54]
	subs r1, r1, #1
	beq _0300588C
	strb r2, [sp, #SP_A55]
	strb r1, [sp, #SP_A54]
_03005870:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
_03005880:
	ldrb r2, [sp, #SP_A4F]
	orr r2, r2, #0xc
	movs r0, #0x8000
_0300588C:
	mov r1, #5
	strb r1, [sp, #SP_A54]
	add r0, sp, r0, lsr #13 @ WARNING: disassembler produces wrong instruction here
	ldrb r1, [r0, #SP_A4B]
	cmp r1, r2
	beq _03005870
	strb r2, [r0, #SP_A4B]
	ldrb r0, [sp, #SP_A4F]
	ldr r2, [sp, #SP_874]
	ldrb lr, [sp, #SP_A52]
	tst r0, #8
	biceq lr, lr, #1
	and lr, r2, lr, lsl #6
	ldr r2, [sp, #SP_85C]
	bne _030058E0
	add r2, r2, lr
	str r2, [r11, #0x10]
	str r2, [r11, #0x14]
	str r2, [r11, #0x18]
	str r2, [r11, #0x1c]
	b _0300594C
_030058E0:
	tst r0, #4
	bne _0300591C
	ldrb r1, [sp, #SP_A53]
	cmp r1, #0
	ldrbne r1, [sp, #SP_A50]
	tstne r1, #0x10
	addne r2, r2, #0x400
	str r2, [r11, #0x10]
	str r2, [r11, #0x14]
	ldr r2, [sp, #SP_86C]
	subeq r2, r2, #0x400
	add r2, r2, lr
	str r2, [r11, #0x18]
	str r2, [r11, #0x1c]
	b _0300594C
_0300591C:
	ldrb r1, [sp, #SP_A53]
	cmp r1, #0
	ldrbne r1, [sp, #SP_A50]
	tstne r1, #0x10
	addne r2, r2, #0x400
	add r2, r2, lr
	str r2, [r11, #0x10]
	str r2, [r11, #0x14]
	ldr r2, [sp, #SP_86C]
	subeq r2, r2, #0x400
	str r2, [r11, #0x18]
	str r2, [r11, #0x1c]
_0300594C:
	ldr r1, [sp, #SP_878]
	cmp r1, #0
	beq _030059F8
	tst r0, #0x10
	ldrb r1, [sp, #SP_A50]
	ldr r2, [sp, #SP_87C]
	bne _030059AC
	bic r1, r1, #1
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r2, [sp, #SP_8E4]
	cmp r2, lr
	orrne r11, r11, #0xc0000
	strne lr, [sp, #SP_8E4]
	ldr lr, _03005A38 @ =0x07060504
	orr lr, lr, r1
	ldreq r2, [sp, #SP_8E8]
	cmpeq r2, lr
	orrne r11, r11, #0xc0000
	strne lr, [sp, #SP_8E8]
	b _030059F8
_030059AC:
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r1, [sp, #SP_8E4]
	cmp r1, lr
	orrne r11, r11, #0xc0000
	strne lr, [sp, #SP_8E4]
	ldrb r1, [sp, #SP_A51]
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r1, [sp, #SP_8E8]
	cmp r1, lr
	orrne r11, r11, #0xc0000
	strne lr, [sp, #SP_8E8]
_030059F8:
	adr r1, _03005A3C
	and r0, r0, #3
	ldr r0, [r1, r0, lsl #2]
	str r0, [sp, #SP_8B0]
	sub r2, r5, r4, lsl #8
	lsr r1, r2, #0xd
	ldr r1, [r11, r1, lsl #2]
	add r5, r2, r1, lsl #8
	and r4, r4, #0xff000000
	sub r4, r4, #0x6000000
	adds r4, r4, r1
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [r12, r1, lsl #2]
	b _03005398
	.align 2, 0
_03005A34: .4byte 0x03020100
_03005A38: .4byte 0x07060504
_03005A3C: .4byte 0x00000000
_03005A40: .4byte 0x01010101
_03005A44: .4byte 0x01000100
_03005A48: .4byte 0x01010000
