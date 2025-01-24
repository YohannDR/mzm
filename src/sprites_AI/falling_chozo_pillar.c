#include "sprites_AI/falling_chozo_pillar.h"
#include "sprites_AI/ruins_test.h"
#include "macros.h"

#include "gba/display.h"

#include "data/sprites/falling_chozo_pillar.h"

#include "constants/audio.h"
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
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);

            gCurrentSprite.pOam = sFallingChozoPillarOAM_Falling;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_CHECK_SUIT_ANIM_ENDED;
            gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(4.25f) + 1 * DELTA_TIME;
            gCurrentSprite.work0 = 0;
            break;

        case FALLING_CHOZO_PILLAR_POSE_CHECK_SUIT_ANIM_ENDED:
            // Check suit animation ended
            if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED)
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
                SoundPlay(SOUND_CHOZO_PILLAR_FALLING);
            }
            break;

        case FALLING_CHOZO_PILLAR_POSE_FALLING:
            if (gCurrentSprite.yPositionSpawn != 0)
            {
                // todo: APPLY_DELTA_TIME_INC won't match here
                // CONVERT_SECONDS(.25f) + 1 * DELTA_TIME
                if (MOD_AND(gCurrentSprite.work0++, 16) == 0)
                {
                    // Start screen shake/play particle
                    ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
                    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(1.f / 30)))
                        effect = PE_SECOND_MEDIUM_DUST;
                    else
                        effect = PE_SECOND_TWO_MEDIUM_DUST;

                    ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE * 4,
                        gCurrentSprite.xPosition - (BLOCK_SIZE - EIGHTH_BLOCK_SIZE) + gSpriteRng * EIGHTH_BLOCK_SIZE, effect);
                }

                // Timer
                APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
                gCurrentSprite.yPosition++; // Move down
            }
            else
            {
                // Timer done, set fallen behavior
                gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_FALLEN;
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f), 0x80 | 1);
                gCurrentSprite.work0 = TWO_THIRD_SECOND;
            }
            break;

        case FALLING_CHOZO_PILLAR_POSE_FALLEN:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pose = FALLING_CHOZO_PILLAR_POSE_IDLE;
                SoundPlay(SOUND_CHOZO_PILLAR_FELL);
            }
            break;
    }
}
