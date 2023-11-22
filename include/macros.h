#define BEHAVIOR_TO_BLOCK(behavior) (behavior - 0x10)
#define BEHAVIOR_TO_TANK(behavior) (behavior - 0x34)
#define BEHAVIOR_TO_HAZARD(behavior) (behavior - 0x40)
#define BEHAVIOR_TO_BLDALPHA(behavior) (behavior - 0x44)
#define BEHAVIOR_TO_GROUND_EFFECT(behavior) (behavior - 0x50)
#define BEHAVIOR_TO_DOOR(behavior) (behavior - 0x7F)

#define bomb_chain_type_to_flag(type) (1 << type)

#define LOW_BYTE(value) ((value) & UCHAR_MAX)
#define HIGH_BYTE(value) (((value) & UCHAR_MAX << 8) >> 8)

#define LOW_SHORT(value) ((value) & USHORT_MAX)
#define HIGH_SHORT(value) ((value) >> 16)

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

/**
 * @brief Constructs an ushort from 2 bytes (low | high << 8)
 * 
 * @param high High
 * @param low Low
 */
#define C_16_2_8_(high, low) ((low) | (high) << 8)

#define C_S8_2_S16(value) ((value) & 0x80 ? 0x100 + (value) : (value))
#define C_S9_2_S16(value) ((value) & 0x100 ? 0x200 + (value) : (value))

#define OPPOSITE_DIRECTION(dir) ((dir) ^ (KEY_RIGHT | KEY_LEFT))
#define ARRAY_SIZE(a) ((s32)(sizeof((a)) / sizeof((a)[0])))
#define ARRAY_ACCESS(a, o) (a[(u32)(o) % ARRAY_SIZE(a)])
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

#define CEIL(v) ((int)(((float)v) + .5) == (int)(v) ? ((int)(v)) : (int)(((float)v) + .5))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

#define RED(c) ((c) & COLOR_MASK)
#define GREEN(c) (((c) & (COLOR_MASK << 5)) >> 5)
#define BLUE(c) (((c) & (COLOR_MASK << 10)) >> 10)
#define COLOR(r, g, b) (((b) << 10) | ((g) << 5) | (r))
#define COLOR_GRAD(r, g, b) ((r) | ((g) << 5) | ((b) << 10))
#define COLOR_WHITE COLOR(COLOR_MASK, COLOR_MASK, COLOR_MASK)
#define COLOR_BLACK COLOR(0, 0, 0)
#define COLOR_MASK 0x1F

#define SET_BACKDROP_COLOR(color) (write16(PALRAM_BASE, (color)))

#define OAM_PART_SIZE 3
#define OAM_DATA_SIZE(nbrOfParts) (1 + (nbrOfParts) * OAM_PART_SIZE)
#define GET_OAM_DATA_SIZE(size) (((size) - 1) / OAM_PART_SIZE)

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
 * @brief Performs a division (value / div) operation on a value using the right shift operation (WARNING only use a value for div that is divisble by 2 and <= 1024)
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

// PI is half a rotation on the unit circle, a full rotation is Q_8_8(1.f)
#define PI Q_8_8(.5f)
#define sin(a) (sSineTable[(a)])
#define cos(a) (sSineTable[(a) + PI / 2])

#define GET_PSPRITE_HEALTH(id) sPrimarySpriteStats[(id)][0]
#define GET_SSPRITE_HEALTH(id) sSecondarySpriteStats[(id)][0]

#define GET_PSPRITE_DAMAGE(id) sPrimarySpriteStats[(id)][1]
#define GET_SSPRITE_DAMAGE(id) sSecondarySpriteStats[(id)][1]

#define GET_PSPRITE_WEAKNESS(id) sPrimarySpriteStats[(id)][2]
#define GET_SSPRITE_WEAKNESS(id) sSecondarySpriteStats[(id)][2]

#define SUB_PIXEL_TO_PIXEL(pixel) ((pixel) / SUB_PIXEL_RATIO)
#define SUB_PIXEL_TO_PIXEL_(pixel) (DIV_SHIFT(pixel, SUB_PIXEL_RATIO))
#define PIXEL_TO_SUB_PIXEL(pixel) ((pixel) * SUB_PIXEL_RATIO)
#define SUB_PIXEL_TO_BLOCK(pixel) ((pixel) / BLOCK_SIZE)
#define BLOCK_TO_SUB_PIXEL(block) ((block) * BLOCK_SIZE)
#define VELOCITY_TO_SUB_PIXEL(velocity) (DIV_SHIFT((velocity), 8))
#define SUB_PIXEL_TO_VELOCITY(velocity) ((s16)((velocity) * 8))

#define SCREEN_SIZE_X_SUB_PIXEL (PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_X))
#define SCREEN_SIZE_Y_SUB_PIXEL (PIXEL_TO_SUB_PIXEL(SCREEN_SIZE_Y))

#define SCREEN_SIZE_X_BLOCKS (SUB_PIXEL_TO_BLOCK(SCREEN_SIZE_X_SUB_PIXEL))
#define SCREEN_SIZE_Y_BLOCKS (SUB_PIXEL_TO_BLOCK(SCREEN_SIZE_Y_SUB_PIXEL))

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


#define INCTEXT(x)  {0}

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
