#include "sprites_AI/falling_chozo_pillar.h"
#include "sprites_AI/ruins_test.h"

#include "data/sprites/falling_chozo_pillar.c"

#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/sprite.h"

/**
 * @brief 4b884 | 218 | Falling chozo pillar AI
 * 
 */
void FallingChozoPillar(void)
{
    u8 effect;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.xPosition += 0x20;

            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = 0x80;

            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

            gCurrentSprite.pOam = sFallingChozoPillarOAM_Falling;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_CHECK_SUIT_ANIM_ENDED;
            gCurrentSprite.yPositionSpawn = 0x100;
            gCurrentSprite.timer = 0x0;
            break;

        case FALLING_CHOZO_PILLAR_POSE_CHECK_SUIT_ANIM_ENDED:
            if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED) // Check suit animation ended
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_CHECK_ON_SCREEN;
            }
            break;

        case FALLING_CHOZO_PILLAR_POSE_CHECK_ON_SCREEN:
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                // Start falling when on screen
                gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_FALLING;
                SoundPlay(0x10B);
            }
            break;

        case FALLING_CHOZO_PILLAR_POSE_FALLING:
            if (gCurrentSprite.yPositionSpawn != 0x0)
            {
                if (!(gCurrentSprite.timer++ & 0xF))
                {
                    // Start screen shake/play particle
                    ScreenShakeStartVertical(0x14, 0x81);
                    if (gFrameCounter8Bit & 0x1)
                        effect = PE_SECOND_MEDIUM_DUST;
                    else
                        effect = PE_SECOND_TWO_MEDIUM_DUST;

                    ParticleSet(gCurrentSprite.yPosition - 0x100, gCurrentSprite.xPosition - 0x38 + gSpriteRNG * 0x8, effect);
                }

                gCurrentSprite.yPositionSpawn--; // Timer
                gCurrentSprite.yPosition++; // Move down
            }
            else
            {
                // Timer done, set fallen behavior
                gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_FALLEN;
                ScreenShakeStartVertical(0x3C, 0x81);
                gCurrentSprite.timer = 0x28;
            }
            break;

        case FALLING_CHOZO_PILLAR_POSE_FALLEN:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Unknown, AI doesn't handle this case, most likely removed code
                gCurrentSprite.pose = 0x29;
                SoundPlay(0xA7);
            }
            break;
    }
}