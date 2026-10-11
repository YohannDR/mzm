    .include "asm/constants.inc"
    .include "asm/macros.inc"

_087D8150:
.ifdef REGION_JP
    .incbin "payload/payload_jp.gba.lz"
.else
    .ifdef REGION_EU
        .ifdef DEBUG
            .incbin "payload/payload_eu_beta.gba.lz"
        .else
            .incbin "payload/payload_eu.gba.lz"
        .endif
    .else
        .ifdef REGION_US
            .ifdef DEBUG
                .incbin "payload/payload_us_beta.gba.lz"
            .else
                .incbin "payload/payload_us.gba.lz"
            .endif
        .endif
    .endif
.endif
    .align 4, 0

_087D8360:
.ifdef REGION_JP
    .incbin "emulator/emulator_jp.gba.lz"
.else
    .ifdef REGION_EU
        .ifdef DEBUG
            .incbin "emulator/emulator_eu_beta.gba.lz"
        .else
            .incbin "emulator/emulator_eu.gba.lz"
        .endif
    .else
        .ifdef REGION_US
            .ifdef DEBUG
                .incbin "emulator/emulator_us_beta.gba.lz"
            .else
                .incbin "emulator/emulator_us.gba.lz"
            .endif
        .endif
    .endif
.endif
_087DCDB0:
.ifdef REGION_JP
    .incbin "emulator/emulatorUnused_jp.gba"
.else
    .ifdef REGION_EU
        .ifdef DEBUG
            .incbin "emulator/emulatorUnused_eu_beta.gba"
        .else
            .incbin "emulator/emulatorUnused_eu.gba"
        .endif
    .else
        .ifdef REGION_US
            .ifdef DEBUG
                .incbin "emulator/emulatorUnused_us_beta.gba"
            .else
                .incbin "emulator/emulatorUnused_us.gba"
            .endif
        .endif
    .endif
.endif

_087DCF60:
    .incbin "data/M1_NES_MZM.nes.lz"
    .align 2, 0


.global sUnk_087F3398
sUnk_087F3398:
    .2byte (0x020350E0 - 0x0201C000) >> 4, _087F3A08 - _087F33FC
    .2byte (0x02034000 - 0x0201C000) >> 4, _087F4248 - _087F3A08
    .2byte (0x0202CD60 - 0x0201C000) >> 4, _087F4540 - _087F4248
    .2byte (0x02024D60 - 0x0201C000) >> 4, _087F4828 - _087F4540
    .2byte (0x02021160 - 0x0201C000) >> 4, _087F4B88 - _087F4828
    .2byte (0x02028D60 - 0x0201C000) >> 4, _087F4F18 - _087F4B88
    .2byte (0x02029160 - 0x0201C000) >> 4, _087F524C - _087F4F18
    .2byte (0x02025160 - 0x0201C000) >> 4, _087F5574 - _087F524C
    .2byte (0x02036CA0 - 0x0201C000) >> 4, _087F59FC - _087F5574
    .2byte (0x020372A0 - 0x0201C000) >> 4, _087F5A8C - _087F59FC
    .2byte (0x02035EF0 - 0x0201C000) >> 4, _087F5FA8 - _087F5A8C
    .2byte (0x020373F0 - 0x0201C000) >> 4, _087F6068 - _087F5FA8
    .2byte (0x0202D360 - 0x0201C000) >> 4, _087F61B4 - _087F6068
    .2byte (0x02037330 - 0x0201C000) >> 4, _087F6268 - _087F61B4
    .2byte (0x020369C0 - 0x0201C000) >> 4, _087F6520 - _087F6268
    .2byte (0x020366F0 - 0x0201C000) >> 4, _087F6760 - _087F6520
    .2byte (0x02030D60 - 0x0201C000) >> 4, _087F6B18 - _087F6760
    .2byte (0x02036950 - 0x0201C000) >> 4, _087F6B94 - _087F6B18
    .2byte (0x020374C0 - 0x0201C000) >> 4, _087F6D98 - _087F6B94
    .2byte (0x02020D60 - 0x0201C000) >> 4, _087F7018 - _087F6D98
    .2byte (0x02035890 - 0x0201C000) >> 4, _087F7028 - _087F7018
    .2byte (0x02034BE0 - 0x0201C000) >> 4, _087F7344 - _087F7028
    .2byte (0x020349A0 - 0x0201C000) >> 4, _087F73F8 - _087F7344
    .2byte (0x02035DA0 - 0x0201C000) >> 4, _087F7544 - _087F73F8
    .2byte (0x02035980 - 0x0201C000) >> 4, sUnk_087F7558 - _087F7544
_087F33FC:
    .incbin "data/gfx/GFX_SamusSuitless.nes.lz"
    .align 2, 0
_087F3A08:
    .incbin "data/gfx/GFX_Samus.nes.lz"
    .align 2, 0
_087F4248:
    .incbin "data/gfx/GFX_EndingSprites.nes.lz"
    .align 2, 0
_087F4540:
    .incbin "data/gfx/GFX_NorfairSprites.nes.lz"
    .align 2, 0
_087F4828:
    .incbin "data/gfx/GFX_BrinstarSprites.nes.lz"
    .align 2, 0
_087F4B88:
    .incbin "data/gfx/GFX_KraidSprites.nes.lz"
    .align 2, 0
_087F4F18:
    .incbin "data/gfx/GFX_RidleySprites.nes.lz"
    .align 2, 0
_087F524C:
    .incbin "data/gfx/GFX_TourianSprites.nes.lz"
    .align 2, 0
_087F5574:
    .incbin "data/gfx/GFX_TourBG.nes.lz"
    .align 2, 0
_087F59FC:
    .incbin "data/gfx/GFX_Zebetite.nes.lz"
    .align 2, 0
_087F5A8C:
    .incbin "data/gfx/GFX_CREBG2.nes.lz"
    .align 2, 0
_087F5FA8:
    .incbin "data/gfx/GFX_RidlBG.nes.lz"
    .align 2, 0
_087F6068:
    .incbin "data/gfx/GFX_KraiBG3.nes.lz"
    .align 2, 0
_087F61B4:
    .incbin "data/gfx/GFX_KraiBG2.nes.lz"
    .align 2, 0
_087F6268:
    .incbin "data/gfx/GFX_BossBG.nes.lz"
    .align 2, 0
_087F6520:
    .incbin "data/gfx/GFX_NorfBG1.nes.lz"
    .align 2, 0
_087F6760:
    .incbin "data/gfx/GFX_CREBG1.nes.lz"
    .align 2, 0
_087F6B18:
    .incbin "data/gfx/GFX_NorfBG2.nes.lz"
    .align 2, 0
_087F6B94:
    .incbin "data/gfx/GFX_Font.nes.lz"
    .align 2, 0
_087F6D98:
    .incbin "data/gfx/GFX_TheEndFont.nes.lz"
    .align 2, 0
_087F7018:
    .incbin "data/gfx/GFX_ExclamationPoint.nes.lz"
    .align 2, 0
_087F7028:
    .incbin "data/gfx/GFX_Title.nes.lz"
    .align 2, 0
_087F7344:
    .incbin "data/gfx/GFX_IntroSprites.nes.lz"
    .align 2, 0
_087F73F8:
    .incbin "data/gfx/GFX_BrinBG1.nes.lz"
    .align 2, 0
_087F7544:
    .incbin "data/gfx/GFX_Solid.nes.lz"
    .align 2, 0

.global sUnk_087F7558
sUnk_087F7558:
    .incbin "data/palette.pal.lz"
    .align 2, 0

