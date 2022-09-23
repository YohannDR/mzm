#include "block.h"
#include "clipdata.h"
#include "power_bomb_explosion.h"
#include "data/block_data.c"
#include "clipdata.h" // ?
#include "constants/samus.h"
#include "constants/clipdata.h"
#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"

/**
 * @brief 590b0 | 214 | Checks if soemthing should happen to a block depending on the CCAA
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u32 1 if detroyed, 0 otherwise
 */
u32 BlockCheckCCAA(struct ClipdataBlockData* pClipBlock)
{
    // https://decomp.me/scratch/o1iEv

    u32 result;
    u32 bombChainType;
    register u32 destroy asm("r4");
    u16 behavior;
    u16 clipdata;

    result = FALSE;

    behavior = behavior_to_block(pClipBlock->behavior);
    // Check is block
    if (behavior <= behavior_to_block(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
    {
        // Get block behavior
        pClipBlock->blockBehavior = behavior_to_block(pClipBlock->behavior);

        if (gCurrentClipdataAffectingAction == CAA_SPEEDBOOSTER_ON_GROUND)
        {
            if (sBlockBehaviors[pClipBlock->blockBehavior].unk << 0x1C == 0x0)
                return result;
            
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        }
        else if (gCurrentClipdataAffectingAction == CAA_BOMB_CHAIN)
        {
            if (sBlockBehaviors[pClipBlock->blockBehavior].unk >> 4 == 0x0)
                return result;
        }

        destroy = TRUE;
        bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;

        // Apply behavior
        switch (pClipBlock->blockBehavior)
        {
            case behavior_to_block(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;
                break;
    
            case behavior_to_block(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;

            case behavior_to_block(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->yPosition--;
                break;
            
            case behavior_to_block(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM):
                destroy = BlockCheckRevealOrDestroyBombBlock(pClipBlock);
                break;

            case behavior_to_block(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NO_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_NO_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM):
            case behavior_to_block(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM):
                destroy = BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                break;

            case behavior_to_block(CLIP_BEHAVIOR_CRUMBLE_BLOCK):
            case behavior_to_block(CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK):
                BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                destroy = FALSE;
                break;
            
            case behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL2;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL3;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL4;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL1;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL2;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL3;
                break;

            case behavior_to_block(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL4;
                break;
        }
    }
    else
        return FALSE;

    // Abort if nothing happened
    if (!destroy)
        return FALSE;

    // Apply life type
    switch (sBlockBehaviors[pClipBlock->blockBehavior].lifeType)
    {
        case BLOCK_LIFE_TYPE_NO_NEVER_REFORM:
            if (BlockDestroyNonReformBlock(pClipBlock))
                result = TRUE;
            break;

        case BLOCK_LIFE_TYPE_REFORM:
            if (BlockStoreBrokenReformBlock(sBlockBehaviors[pClipBlock->blockBehavior].type,
                pClipBlock->xPosition, pClipBlock->yPosition, FALSE))
                result = TRUE;
            break;

        case BLOCK_LIFE_TYPE_BOMB_CHAIN:
            if (BlockCheckRevealOrDestroyBombBlock(pClipBlock))
            {
                // Check type isn't already active
                if (!(gActiveBombChainTypes & sBombChainReverseData[bombChainType].typeFlag))
                {
                    if (BlockStartBombChain(bombChainType, pClipBlock->xPosition, pClipBlock->yPosition))
                    {
                        // Destroy block
                        if (BlockDestroyNonReformBlock(pClipBlock))
                            result = TRUE;
                    }
                }
            }
            break;

        case BLOCK_LIFE_TYPE_TANK:
            // Check shoulr reveal
            if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & 
                (CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_BOMB_PISTOL | CAA_DAMAGE_TYPE_MISSILE |
                CAA_DAMAGE_TYPE_SUPER_MISSILE | CAA_DAMAGE_TYPE_POWER_BOMB))
            {
                clipdata = sTankBehaviors[behavior_to_tank(pClipBlock->behavior)].revealedClipdata;
                if (clipdata != 0x0)
                {
                    BGClipSetBG1BlockValue(clipdata, pClipBlock->yPosition, pClipBlock->xPosition);
                    BGClipSetClipdataBlockValue(clipdata, pClipBlock->yPosition, pClipBlock->xPosition);
                    result = TRUE;
                }
            }
    }

    return result;
}

u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock)
{

}

/**
 * @brief 59330 | 3c | Destroys a single bomb chain block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u8 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;
    return TRUE;
}

/**
 * @brief 5936c | 3c | Destroys a single block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u8 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;
    return TRUE;
}

/**
 * @brief 593a8 | d8 | Destroys a square block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u8 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock)
{
    u8 blockType;

    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;

    pClipBlock->xPosition++;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;
    
    pClipBlock->yPosition--;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;
    
    pClipBlock->xPosition--;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBGPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBGPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0x0;

    if (gCurrentClipdataAffectingAction != CAA_SPEEDBOOSTER)
        SoundPlayNotAlreadyPlaying(0x137);

    return TRUE;
}

u32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition)
{
    // https://decomp.me/scratch/wIffo

    u32 overLimit;
    u8* pBlock;
    i32 i;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return FALSE;
    else if (xPosition * yPosition == 0x0)
        return FALSE;

    overLimit = TRUE;
    pBlock = gNeverReformBlocks[gCurrentArea];
    i = gNumberOfNeverReformBlocks[gCurrentArea] * 2;

    for (; i < 0x1FC; i += 2)
    {
        if (pBlock[i] == 0xFF)
        {
            overLimit = FALSE;
            break;
        }
    }

    if (!overLimit)
    {
        pBlock[i++] = xPosition;
        pBlock[i] = yPosition;
    }

    return overLimit;
}

void BlockRemoveNeverReformBlocks(void)
{

}

void BlockRemoveNeverReformSingleBlock(u16 xPosition, u16 yPosition)
{

}

void BlockShiftNeverReformBlocks(void)
{

}

u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock)
{
    // https://decomp.me/scratch/7cgi5

    u32 blockType;

    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & sBlockWeaknesses[blockType])
        return TRUE;
    else
    {
        if ((gCurrentClipdataAffectingAction == CAA_BOMB_PISTOL || (gCurrentClipdataAffectingAction == CAA_POWER_BOMB && !gCurrentPowerBomb.owner)) && pClipBlock->behavior != sReformingBlocksTilemapValue[blockType])
        {
            blockType = sReformingBlocksTilemapValue[blockType];
            BGClipSetBG1BlockValue(blockType, pClipBlock->yPosition, pClipBlock->xPosition);
            BGClipSetClipdataBlockValue(blockType, pClipBlock->yPosition, pClipBlock->xPosition);
        }

        return FALSE;
    }
}

u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock)
{

}

/**
 * @brief 5987c | 164 | Applies the CCAA (Current Clipdata Affecting Action)
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param trueClip True clipdata block value
 * @return u32 1 if a block changed, 0 otherwise
 */
u32 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 trueClip)
{
    struct ClipdataBlockData clipBlock;
    u32 result;

    // Create clipdata block data structure
    clipBlock.xPosition = xPosition;
    clipBlock.yPosition = yPosition;
    clipBlock.behavior = gTilemapAndClipPointers.pClipBehaviors[trueClip];
    clipBlock.blockBehavior = 0x0;

    result = FALSE;

    switch (gCurrentClipdataAffectingAction)
    {
        case CAA_BEAM:
        case CAA_BOMB_PISTOL:
        case CAA_MISSILE:
        case CAA_SUPER_MISSILE:
        case CAA_POWER_BOMB:
            // Check on hatch
            if (gTilemapAndClipPointers.pClipCollisions[trueClip] == CLIPDATA_TYPE_DOOR &&
                BGClipCheckOpeningHatch(clipBlock.xPosition, clipBlock.yPosition) != 0x0)
                result = TRUE;
            else
            {
                // Check on block
                if (BlockCheckCCAA(&clipBlock))
                    result = TRUE;
            }
            break;

        case CAA_SPEEDBOOSTER:
        case CAA_SPEEDBOOSTER_ON_GROUND:
            if (BlockCheckCCAA(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(0x135);
                result = TRUE;
            }
            break;

        case CAA_SCREW_ATTACK:
            if (BlockCheckCCAA(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(0x139);
                result = TRUE;
            }
            break;

        case CAA_BOMB_CHAIN:
        case CAA_BOMB_CHAIN_UNUSED:
            if (BlockCheckCCAA(&clipBlock))
                result = TRUE;
            break;

        case CAA_REMOVE_SOLID:
            if (!BlockUpdateMakeSolidBlocks(FALSE, xPosition, yPosition))
                BGClipSetBG1BlockValue(0x0, yPosition, xPosition);

            BGClipSetClipdataBlockValue(0x0, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID_GRIPPABLE:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43E, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID2:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43D, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID3:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BGClipSetClipdataBlockValue(0x43F, yPosition, xPosition);
            break;
    }

    return result;
}

/**
 * @brief 599e0 | b8 | Updates the "make solid blocks" array
 * 
 * @param makeSolid Make solid flag
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if could store, 0 otherwise
 */
u32 BlockUpdateMakeSolidBlocks(u8 makeSolid, u16 xPosition, u16 yPosition)
{
    u32 result;
    i32 i;
    u16* pBlocks;

    result = FALSE;

    if (!makeSolid)
    {
        // Remove solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0x0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Found in the array, remove
                pBlocks[i] = 0x0;
                result = TRUE;
                break;
            }
        }
    }
    else
    {
        // Make solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0x0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Already in the array
                i = 0xFF;
                break;
            }
            else if (pBlocks[i] == 0x0)
                break; // Found empty space
        }

        result = FALSE;
        if (i != 0xFF)
        {
            if (gBGPointersAndDimensions.pClipDecomp[gBGPointersAndDimensions.clipdataWidth * yPosition + xPosition] == 0x0)
            {
                // Store if no block
                pBlocks[i] = (xPosition << 8 | yPosition);
                result = TRUE;
            }
        }
    }

    return result;
}

/**
 * @brief 59a9c | b8 | Applies the speedbooster/screw attack destructing action
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param action Destructing action
 * @return u32 1 if destroyed, 0
 */
u32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u16 action)
{
    u16 blockY;
    u16 blockX;
    u16 clipdata;
    u16 result;
    u16 position;

    blockX = xPosition >> 6;
    blockY = yPosition >> 6;

    if (blockX < gBGPointersAndDimensions.clipdataWidth && blockY < gBGPointersAndDimensions.clipdataHeight)
    {
        // Set CCAA
        if (action == DESTRUCTING_ACTION_SPEED)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        else if (action == DESTRUCTING_ACTION_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_ON_GROUND)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER_ON_GROUND;
        else
            return FALSE;

        // Get clipdata block
        position = gBGPointersAndDimensions.clipdataWidth * blockY + blockX;
        clipdata = gBGPointersAndDimensions.pClipDecomp[position];
        if (clipdata != 0x0)
        {
            // Apply first
            result = BlockApplyCCAA(blockY, blockX, clipdata);

            if (!result && action == DESTRUCTING_ACTION_SPEED_SCREW)
            {
                // Apply second
                gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
                BlockApplyCCAA(blockY, blockX, clipdata);
            }
        }
    }
    else
        return FALSE;

    // Clear CCAA
    gCurrentClipdataAffectingAction = CAA_NONE;
    
    return result;
}

/**
 * @brief 59b54 | 120 | Updates the broken blocks
 * 
 */
void BlockUpdateBrokenBlocks(void)
{
    struct BrokenBlock* pBlock;
    i32 i;
    u32 updateStage;

    pBlock = gBrokenBlocks;
    i = MAX_AMOUNT_OF_BROKEN_BLOCKS - 1;
    while (i >= 0)
    {
        if (pBlock->stage != 0x0)
        {
            pBlock->timer++;
            if (pBlock->broken)
            {
                if (pBlock->timer >= sBrokenBlocksTimers[pBlock->type][pBlock->stage])
                {
                    updateStage = FALSE;
                    pBlock->timer = 0x0;
    
                    if (pBlock->stage > 0xC)
                    {
                        if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                            pBlock->stage = 0x2;
                        else
                        {
                            BGClipSetClipdataBlockValue(sReformingBlocksTilemapValue[pBlock->type], pBlock->yPosition, pBlock->xPosition);
                            pBlock->broken = FALSE;
                            pBlock->stage = 0x0;
                            pBlock->type = BLOCK_TYPE_NONE;
                            pBlock->xPosition = 0x0;
                            pBlock->yPosition = 0x0;
                        }
                    }
                    else if (pBlock->stage == 0x7)
                    {
                        if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                            pBlock->timer = sBrokenBlocksTimers[pBlock->type][pBlock->stage] / 2;
                        else
                            updateStage = TRUE;
                    }
                    else
                    {
                        if (pBlock->stage == 0x1)
                            BlockBrokenBlockRemoveCollision(pBlock->yPosition, pBlock->xPosition);
                        updateStage = TRUE;
                    }
    
                    if (updateStage)
                    {
                        pBlock->stage++;
                        BlockUpdateBrokenBlockAnimation(pBlock);
                    }
                }
            }
            else
            {
                if (pBlock->timer >= sBrokenBlocksTimers[pBlock->type][pBlock->stage])
                {
                    pBlock->timer = 0x0;
                    pBlock->stage++;
    
                    BlockUpdateBrokenBlockAnimation(pBlock);
    
                    if (pBlock->stage > 0x6)
                    {
                        pBlock->broken = FALSE;
                        pBlock->stage = 0x0;
                        pBlock->type = BLOCK_TYPE_NONE;
                        pBlock->xPosition = 0x0;
                        pBlock->yPosition = 0x0;
                    }
                }
            }
        }


        i--;
        pBlock++;
    }
}

void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock)
{

}

/**
 * @brief 59da8 | ac | Stores a new broken block (that reforms)
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param advanceStage Starts the block at stage 2 if true
 * @return u32 1 if could store, 0 otherwise
 */
u32 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 advanceStage)
{
    u32 result;
    i32 i;
    struct BrokenBlock* pBlock;

    result = FALSE;
    pBlock = gBrokenBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS;)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            // Already in array
            if (pBlock->stage == 0x0)
                result = TRUE;
            else
                result = FALSE;
            break;
        }
        else
        {
            // Check save empty offset
            if (!(result & 0x80) && pBlock->stage == 0x0)
                result = i | 0x80; // Store empty offset
        }

        i++;
        pBlock++;
    }

    // Empty space was found
    if (result)
    {
        // Get offset
        if (result != TRUE)
            i = result & 0x7F;

        pBlock = gBrokenBlocks + i;

        // Store block
        pBlock->broken = TRUE;
        pBlock->type = type;
        pBlock->timer = 0x0;

        if (result & 0x80)
        {
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;
        }

        if (!advanceStage)
        {
            pBlock->stage = 0x2;
            BlockBrokenBlockRemoveCollision(yPosition, xPosition);
            BlockUpdateBrokenBlockAnimation(pBlock);
        }
        else
            pBlock->stage = 0x1;

        result = TRUE;
    }

    return result;
}

/**
 * @brief 59e54 | a4 | Stores a new broken block (that doesn't reform)
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param type Block type
 */
void BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type)
{
    struct BrokenBlock* pBlock;
    i32 i;
    i32 stage;

    pBlock = gBrokenBlocks;
    i = 0;

    while (i < MAX_AMOUNT_OF_BROKEN_BLOCKS)
    {
        if (pBlock->stage == 0x0)
        {
            pBlock->broken = FALSE;
            pBlock->stage = 0x2;
            pBlock->type = type;
            pBlock->timer = 0x0;
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;

            BlockUpdateBrokenBlockAnimation(pBlock);
            return;
        }

        i++;
        pBlock++;
    }

    stage = 0x4;

    while (stage != 0x0)
    {
        pBlock = gBrokenBlocks;
        i = 0;

        while (i < MAX_AMOUNT_OF_BROKEN_BLOCKS)
        {
            if (!pBlock->broken && pBlock->stage >= stage)
            {
                BGClipSetBG1BlockValue(0x0, pBlock->yPosition, pBlock->xPosition);

                pBlock->broken = FALSE;
                pBlock->stage = 0x2;
                pBlock->type = type;
                pBlock->timer = 0x0;
                pBlock->xPosition = xPosition;
                pBlock->yPosition = yPosition;

                BlockUpdateBrokenBlockAnimation(gBrokenBlocks + i);
                return;
            }

            i++;
            pBlock++;
        }

        stage >>= 1;
    }
}

/**
 * @brief 59ef8 | 78 | Reveals a bomb chain block
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if was revealed, 0 otherwise
 */
u32 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition)
{
    struct BrokenBlock* pBlock;
    i32 i;
    i32 couldSpawn;

    couldSpawn = FALSE;
    pBlock = gBrokenBlocks;
    i = 0;

    while (i < MAX_AMOUNT_OF_BROKEN_BLOCKS)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            couldSpawn = 0x0;
            break;
        }

        if (!(couldSpawn & 0x80) && pBlock->stage == 0x0)
            couldSpawn = i | 0x80;

        i++;
        pBlock++;
    }

    if (couldSpawn)
    {
        pBlock = gBrokenBlocks + (couldSpawn & 0x7F);

        pBlock->broken = FALSE;
        pBlock->stage = 0x0;
        pBlock->type = type;
        pBlock->timer = 0x0;
        pBlock->xPosition = xPosition;
        pBlock->yPosition = yPosition;
        couldSpawn = TRUE;
    }

    return couldSpawn;
}

/**
 * @brief 59f70 | 70 | Checks if Samus is in a reforming block
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if in block, 0 otherwise
 */
u32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition)
{
    u8 inX;
    u8 inY;
    u8 inBlock;

    // Check in X
    inX = FALSE;
    if ((gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset) >> 6 <= xPosition &&
        xPosition <= (gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset) >> 6)
        inX = TRUE;

    // Check in Y
    inY = FALSE;
    if ((gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset) >> 6 <= yPosition &&
        yPosition <= (gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset) >> 6)
        inY = TRUE;

    inBlock = FALSE;
    if (inX)
        inBlock = inY;
        
    return inBlock;
}

/**
 * @brief 59fe0 | b8 | Starts a new bomb chain
 * 
 * @param type Bomb chain type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if could start, 0 otherwise
 */
u32 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition)
{
    u32 couldSpawn;
    i32 i;
    
    couldSpawn = FALSE;
    i = MAX_AMOUNT_OF_BOMB_CHAINS - 1;
    
    for (; i >= 0; i--)
    {
        if (gBombChains[i].currentOffset == 0x0)
        {
            // Found empty slot
            gBombChains[i].currentOffset = 0x1;
            gBombChains[i].srcXPosition = xPosition;
            gBombChains[i].srcYPosition = yPosition;

            gBombChains[i].flipped = TRUE;
            gBombChains[i].unk = TRUE;
            gBombChains[i].type = type;
            
            // Add type
            gActiveBombChainTypes |= sBombChainReverseData[type].typeFlag;
            couldSpawn = TRUE;
            break;
        }
    }

    // Check play bomb chain sound
    if (couldSpawn && gActiveBombChainTypes == sBombChainReverseData[type].typeFlag)
        SoundPlayNotAlreadyPlaying(0x136);

    return couldSpawn;
}

/**
 * @brief 5a098 | 298 | Processes the bomb chains
 * 
 */
void BlockProcessBombChains(void)
{
    u8 horizontal;
    struct ClipdataBlockData clipBlock;
    struct BombChain* pChain;
    u16 clipdata;

    // Update each bomb chain every 4 frames
    pChain = gBombChains;
    pChain += (gFrameCounter8Bit & 0x3);
    
    if (pChain->currentOffset == 0x0)
        return;

    horizontal = FALSE;
    if (pChain->type > BOMB_CHAIN_TYPE_VERTICAL4)
        horizontal = TRUE;

    // Create clipdata block data structure
    clipBlock.behavior = sBombChainReverseData[pChain->type].behavior;
    clipBlock.blockBehavior = behavior_to_block(clipBlock.behavior);
    clipBlock.yPosition = 0x0;
    clipBlock.xPosition = 0x0;

    if (!horizontal)
    {
        // Update vertical
        clipBlock.xPosition = pChain->srcXPosition;
        if (pChain->flipped)
        {
            // Going up
            clipBlock.yPosition = pChain->srcYPosition - pChain->currentOffset;
            if (clipBlock.yPosition <= 0x1)
                pChain->flipped = FALSE;
            else
            {
                clipdata = gBGPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBGPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->flipped = FALSE;
                }
                else
                {
                    pChain->flipped = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_UP, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
        
        if (pChain->unk)
        {
            // Going down
            clipBlock.yPosition = pChain->srcYPosition + pChain->currentOffset;
            if (clipBlock.yPosition >= gBGPointersAndDimensions.clipdataHeight - 0x2)
                pChain->unk = FALSE;
            else
            {
                clipdata = gBGPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBGPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->unk = FALSE;
                }
                else
                {
                    pChain->unk = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_DOWN, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }
    else
    {
        clipBlock.yPosition = pChain->srcYPosition;
        if (pChain->flipped)
        {
            // Going left
            clipBlock.xPosition = pChain->srcXPosition - pChain->currentOffset;
            if (clipBlock.xPosition <= 0x1)
                pChain->flipped = FALSE;
            else
            {
                clipdata = gBGPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBGPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->flipped = FALSE;
                }
                else
                {
                    pChain->flipped = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_LEFT, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }

        if (pChain->unk)
        {
            // Going right
            clipBlock.xPosition = pChain->srcXPosition + pChain->currentOffset;
            if (clipBlock.xPosition >= gBGPointersAndDimensions.clipdataWidth - 0x2)
                pChain->unk = FALSE;
            else
            {
                clipdata = gBGPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBGPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->unk = FALSE;
                }
                else
                {
                    pChain->unk = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_RIGHT, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }

    // Check update offset
    if (pChain->flipped || pChain->unk)
        pChain->currentOffset++;
    else
    {
        // Bomb chain ended
        pChain->currentOffset = 0x0;

        // Remove type
        gActiveBombChainTypes &= ~sBombChainReverseData[pChain->type].typeFlag;

        // Fade sound if no bomb chains active
        if (gActiveBombChainTypes == 0)
            SoundFade(0x136, 0xA);
    }
}

void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition)
{
    // https://decomp.me/scratch/QBMJ2

    u16 clipdata;
    i32 i;
    i32 yOffset;
    i32 xOffset;
    i32 offset;

    gCurrentClipdataAffectingAction = CAA_BOMB_CHAIN;
    clipdata = gBGPointersAndDimensions.pClipDecomp[yPosition * gBGPointersAndDimensions.clipdataWidth + xPosition];
    if (clipdata != 0x0)
        BlockApplyCCAA(yPosition, xPosition, clipdata);

    i = 0x0;
    for (; i < 0x2; ++i)
    {
        yOffset = yPosition + sSubBombChainPositionOffset[type][i*2+1];
        offset = yOffset * gBGPointersAndDimensions.clipdataWidth;
        xOffset = xPosition + sSubBombChainPositionOffset[type][i*2];
        offset += xOffset;
        clipdata = gBGPointersAndDimensions.pClipDecomp[offset];
        if (clipdata != 0x0)
            BlockApplyCCAA(yOffset, xOffset, clipdata);

    }

    gCurrentClipdataAffectingAction = CAA_NONE;
}

void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition)
{

}