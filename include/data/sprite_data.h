#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#include "types.h"

// 2b0c94

extern const u8 sOamXFlipOffsets[3][4];

extern const u8 sOamYFlipOffsets[3][4];

extern const u8 sSpriteRandomNumberTable[32];

extern const s16 sSpritesFallingCeilingSpeed[16];

extern const s16 sSpritesFallingSpeed[16];

extern const s16 sSpritesFallingSpeed_Unused[8];

extern const s16 sSpritesFallingSpeed_Unused2[16];

extern const s16 sWorkerRobotSleepingFallingSpeed[10];

/**
 * @brief Stats of the primary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
extern const u16 sPrimarySpriteStats[206][9];

/**
 * @brief Stats of the secondary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
extern const u16 sSecondarySpriteStats[77][9];



#endif
