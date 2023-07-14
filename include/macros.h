#define BEHAVIOR_TO_BLOCK(behavior) (behavior - 0x10)
#define BEHAVIOR_TO_TANK(behavior) (behavior - 0x34)
#define BEHAVIOR_TO_HAZARD(behavior) (behavior - 0x40)
#define BEHAVIOR_TO_BLDALPHA(behavior) (behavior - 0x44)
#define BEHAVIOR_TO_GROUND_EFFECT(behavior) (behavior - 0x50)
#define BEHAVIOR_TO_DOOR(behavior) (behavior - 0x7F)

#define bomb_chain_type_to_flag(type) (1 << type)

#define LOW_BYTE(value) ((value) & UCHAR_MAX)
#define HIGH_BYTE(value) (((value) & UCHAR_MAX << 8) >> 8)

/**
 * @brief Constructs an uint from 2 ushorts (high << 16 | low)
 * 
 * @param high High
 * @param low Low
 */
#define C_32_2_16(high, low) ((high) << 16 | (low))

/**
 * @brief Constructs an ushort from 2 bytes (high << 8 | low)
 * 
 * @param high High
 * @param low Low
 */
#define C_16_2_8(high, low) ((high) << 8 | (low))

#define check_samus_turning() ((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput)
#define ARRAY_SIZE(a) ((int)(sizeof((a)) / sizeof((a)[0])))
#define OFFSET_OF(type, element) ((int)&(((type*)0)->element))
#define CLAMP(value, min, max)\
{                             \
    if (value > (max))        \
        value = (max);        \
    else if (value < (min))   \
        value = (min);        \
}
#define CLAMP2(value, min, max)\
{                              \
    if (value < (min))         \
        value = (min);         \
    else if (value > (max))    \
        value = (max);         \
}

#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

#define RED(c) ((c) & COLOR_MASK)
#define GREEN(c) (((c) & (COLOR_MASK << 5)) >> 5)
#define BLUE(c) (((c) & (COLOR_MASK << 10)) >> 10)
#define COLOR(r, g, b) (((b) << 10) | ((g) << 5) | (r))
#define COLOR_GRAD(r, g, b) ((r) | ((g) << 5) | ((b) << 10))
#define COLOR_WHITE COLOR(0x1F, 0x1F, 0x1F)
#define COLOR_BLACK COLOR(0x0, 0x0, 0x0)
#define COLOR_MASK 0x1F

#define OAM_PART_SIZE 3
#define OAM_DATA_SIZE(nbrOfParts) (1 + (nbrOfParts) * OAM_PART_SIZE)
#define GET_OAM_DATA_SIZE(size) (((size) - 1) / OAM_PART_SIZE)

#define PI 128
#define sin(a) (sSineTable[(a)])
#define cos(a) (sSineTable[(a) + PI / 2])

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a Q8.8 fixed-point format number to a regular short
#define Q_8_8_TO_SHORT(n) ((s16)((n) >> 8))

// Converts a Q8.8 fixed-point format number to a regular short
#define Q_8_8_TO_SHORT_DIV(n) (((n) / 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q16.16 fixed-point format
#define Q_16_16(n)  ((s32)((n) * 65536))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) << 8))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((s32)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((s32)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((s32)((n) >> 8))

/**
 * @brief Performs a modulo (value % mod) operation on a value using the and operation (WARNING only use a value for mod that is divisble by 2)
 * 
 * @param value Value
 * @param mod Modulo
 */
#define MOD_AND(value, mod) ((value) & ((mod) - 1))

/**
 * @brief Performs a division (value / div) operation on a value using the right shift operation (WARNING only use a value for div that is divisble by 2 and <= 256)
 * 
 * @param value Value
 * @param div Divisor
 */
#define DIV_SHIFT(value, div) ((value) >> ((div) == 2 ? 1 : ((div) == 4 ? 2 : ((div) == 8 ? 3 : ((div) == 16 ? 4 : ((div) == 32 ? 5 : ((div) == 64 ? 6 : ((div) == 128 ? 7 : ((div) == 256 ? 8 : ((div) == 512 ? 9 : ((div) == 1024 ? 10 : 0)))))))))))

/**
 * @brief Performs a multiplaction (value * mul) operation on a value using the left shift operation (WARNING only use a value for div that is divisble by 2 and <= 256)
 * 
 * @param value Value
 * @param mul Multiplier
 */
#define MUL_SHIFT(value, mul) ((value) << ((mul) == 2 ? 1 : ((mul) == 4 ? 2 : ((mul) == 8 ? 3 : ((mul) == 16 ? 4 : ((mul) == 32 ? 5 : ((mul) == 64 ? 6 : ((mul) == 128 ? 7 : ((mul) == 256 ? 8 : ((mul) == 512 ? 9 : ((mul) == 1024 ? 10 : 0)))))))))))

/**
 * @brief Multiplies a number by a fraction (num/den)
 * 
 * @param value Value
 * @param num Numerator
 * @param den Denominator
 */
#define FRACT_MUL(value, num, den) ((value) * (num) / (den))

#define GET_PSPRITE_HEALTH(id) sPrimarySpriteStats[(id)][0]
#define GET_SSPRITE_HEALTH(id) sSecondarySpriteStats[(id)][0]

#define GET_PSPRITE_DAMAGE(id) sPrimarySpriteStats[(id)][1]
#define GET_SSPRITE_DAMAGE(id) sSecondarySpriteStats[(id)][1]

#define GET_PSPRITE_WEAKNESS(id) sPrimarySpriteStats[(id)][2]
#define GET_SSPRITE_WEAKNESS(id) sSecondarySpriteStats[(id)][2]

#define SUB_PIXEL_TO_PIXEL(pixel) ((pixel) / SUB_PIXEL_RATIO)
#define SUB_PIXEL_TO_PIXEL_(pixel) (DIV_SHIFT(pixel, SUB_PIXEL_RATIO))
#define PIXEL_TO_SUBPIXEL(pixel) ((pixel) * SUB_PIXEL_RATIO)
#define SUB_PIXEL_TO_BLOCK(pixel) ((pixel) / BLOCK_SIZE)
#define BLOCK_TO_SUB_PIXEL(block) ((block) * BLOCK_SIZE)

#define SPRITE_HAS_ISFT(sprite) ((sprite).invincibilityStunFlashTimer & 0x7F)
#define SPRITE_CLEAR_ISFT(sprite) ((sprite).invincibilityStunFlashTimer &= 0x80)
#define SPRITE_SET_ISFT(sprite, value) ((sprite).invincibilityStunFlashTimer |= (value))
#define SPRITE_CLEAR_AND_SET_ISFT(sprite, value)\
{                                               \
    SPRITE_CLEAR_ISFT(sprite);                  \
    SPRITE_SET_ISFT(sprite, value);             \
}


#define HAS_AREA_MAP(area) ((gEquipment.downloadedMapStatus >> (area)) & 1)

#define PEN_GET_ENDING(pen) ((pen) & 0xF)
#define PEN_GET_ABILITY(pen) ((pen) >> 4 & 0xF)
#define PEN_GET_POWER_BOMB(pen) ((pen) >> 8 & 0xF)
#define PEN_GET_SUPER_MISSILE(pen) ((pen) >> 12 & 0xF)
#define PEN_GET_MISSILE(pen) (LOW_BYTE((pen) >> 16))
#define PEN_GET_ENERGY(pen) (LOW_BYTE((pen) >> 24))

#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#define _INCBIN_U8  INCBIN
#define _INCBIN_U16 INCBIN
#define _INCBIN_U32 INCBIN
#define _INCBIN_S8  INCBIN
#define _INCBIN_S16 INCBIN
#define _INCBIN_S32 INCBIN

#define FORCE_RODATA __attribute__((section(".rodata")))
#define NAKED_FUNCTION __attribute__((naked))
