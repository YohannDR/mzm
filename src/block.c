#include "block.h"
#include "macros.h"
#include "gba.h"

#include "data/block_data.h"
#include "data/engine_pointers.h"

#include "constants/audio.h"
#include "constants/block.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/power_bomb_explosion.h"

/**
 * @brief 590b0 | 214 | Checks if soemthing should happen to a block depending on the Ccaa
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u32 1 if detroyed, 0 otherwise
 */
#ifdef NON_MATCHING
u32 BlockCheckCcaa(struct ClipdataBlockData* pClipBlock)
{
    // https://decomp.me/scratch/LL1r2

    u32 result;
    u32 bombChainType;
    u32 destroy;
    u32 behavior;
    u16 block;

    result = FALSE;

    block = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);
    // Check is block
    if (block <= BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
    {
        // Get block behavior
        pClipBlock->blockBehavior = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);

        if (gCurrentClipdataAffectingAction == CAA_SPEEDBOOSTER_ON_GROUND)
        {
            if (!sBlockBehaviors[pClipBlock->blockBehavior].isSpeedboost)
                return result;
            
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        }
        else if (gCurrentClipdataAffectingAction == CAA_BOMB_CHAIN)
        {
            if (!sBlockBehaviors[pClipBlock->blockBehavior].isBombChain)
                return result;
        }

        destroy = TRUE;
        bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;

        // Apply behavior
        switch (pClipBlock->blockBehavior)
        {
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;
                break;
    
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->yPosition--;
                break;
            
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM):
                destroy = BlockCheckRevealOrDestroyBombBlock(pClipBlock);
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM):
                destroy = BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_CRUMBLE_BLOCK):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK):
                BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                destroy = FALSE;
                break;
            
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL2;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL3;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL4;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL1;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL2;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL3;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4):
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
            if (!BlockCheckRevealOrDestroyBombBlock(pClipBlock))
                break;

            // Check type isn't already active
            if (gActiveBombChainTypes & sBombChainReverseData[bombChainType].typeFlag)
                break;

            if (BlockStartBombChain(bombChainType, pClipBlock->xPosition, pClipBlock->yPosition))
            {
                // Destroy block
                if (BlockDestroyNonReformBlock(pClipBlock))
                    result = TRUE;
            }
            break;

        case BLOCK_LIFE_TYPE_TANK:
            // Check should reveal
            if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & TANK_WEAKNESS)
            {
                behavior = sTankBehaviors[BEHAVIOR_TO_TANK(pClipBlock->behavior)].revealedClipdata;
                if (behavior != 0)
                {
                    BgClipSetBg1BlockValue(behavior, pClipBlock->yPosition, pClipBlock->xPosition);
                    BgClipSetClipdataBlockValue(behavior, pClipBlock->yPosition, pClipBlock->xPosition);
                    result = TRUE;
                }
            }
    }

    return result;
}
#else
NAKED_FUNCTION
u32 BlockCheckCcaa(struct ClipdataBlockData* pClipBlock)
{
    asm(" \n\
        push {r4, r5, r6, r7, lr} \n\
        add r5, r0, #0 \n\
        movs r7, #0 \n\
        ldrh r1, [r5, #4] \n\
        add r0, r1, #0 \n\
        sub r0, #0x10 \n\
        lsl r0, r0, #0x10 \n\
        lsr r0, r0, #0x10 \n\
        cmp r0, #0x2f \n\
        bls lbl_080590c6 \n\
        b lbl_080591ec \n\
    lbl_080590c6: \n\
        add r0, r1, #0 \n\
        sub r0, #0x10 \n\
        strb r0, [r5, #6] \n\
        ldr r3, lbl_080590ec @ =gCurrentClipdataAffectingAction \n\
        ldrb r0, [r3] \n\
        cmp r0, #0xd \n\
        bne lbl_080590f4 \n\
        ldr r1, lbl_080590f0 @ =sBlockBehaviors \n\
        ldrb r2, [r5, #6] \n\
        lsl r0, r2, #2 \n\
        add r0, r0, r1 \n\
        ldrb r0, [r0, #3] \n\
        lsl r0, r0, #0x1c \n\
        cmp r0, #0 \n\
        bne lbl_080590e6 \n\
        b lbl_080591ec \n\
    lbl_080590e6: \n\
        movs r0, #0xc \n\
        strb r0, [r3] \n\
        b lbl_08059108 \n\
        .align 2, 0 \n\
    lbl_080590ec: .4byte gCurrentClipdataAffectingAction \n\
    lbl_080590f0: .4byte sBlockBehaviors \n\
    lbl_080590f4: \n\
        ldrb r2, [r5, #6] \n\
        cmp r0, #0xf \n\
        bne lbl_08059108 \n\
        ldr r0, lbl_0805911c @ =sBlockBehaviors \n\
        lsl r1, r2, #2 \n\
        add r1, r1, r0 \n\
        ldrb r0, [r1, #3] \n\
        lsr r0, r0, #4 \n\
        cmp r0, #0 \n\
        beq lbl_080591ec \n\
    lbl_08059108: \n\
        movs r4, #1 \n\
        movs r6, #0 \n\
        sub r0, r2, #2 \n\
        cmp r0, #0x1c \n\
        bhi lbl_080591e8 \n\
        lsl r0, r0, #2 \n\
        ldr r1, lbl_08059120 @ =lbl_08059124 \n\
        add r0, r0, r1 \n\
        ldr r0, [r0] \n\
        mov pc, r0 \n\
        .align 2, 0 \n\
    lbl_0805911c: .4byte sBlockBehaviors \n\
    lbl_08059120: .4byte lbl_08059124 \n\
    lbl_08059124: @ jump table \n\
        .4byte lbl_08059198 @ case 0 \n\
        .4byte lbl_080591a6 @ case 1 \n\
        .4byte lbl_080591a0 @ case 2 \n\
        .4byte lbl_080591e8 @ case 3 \n\
        .4byte lbl_080591e8 @ case 4 \n\
        .4byte lbl_08059198 @ case 5 \n\
        .4byte lbl_080591a6 @ case 6 \n\
        .4byte lbl_080591a0 @ case 7 \n\
        .4byte lbl_080591e8 @ case 8 \n\
        .4byte lbl_080591ae @ case 9 \n\
        .4byte lbl_080591ae @ case 10 \n\
        .4byte lbl_080591b8 @ case 11 \n\
        .4byte lbl_080591b8 @ case 12 \n\
        .4byte lbl_080591b8 @ case 13 \n\
        .4byte lbl_080591b8 @ case 14 \n\
        .4byte lbl_080591b8 @ case 15 \n\
        .4byte lbl_080591b8 @ case 16 \n\
        .4byte lbl_080591c2 @ case 17 \n\
        .4byte lbl_080591b8 @ case 18 \n\
        .4byte lbl_080591b8 @ case 19 \n\
        .4byte lbl_080591ca @ case 20 \n\
        .4byte lbl_080591ce @ case 21 \n\
        .4byte lbl_080591d2 @ case 22 \n\
        .4byte lbl_080591d6 @ case 23 \n\
        .4byte lbl_080591da @ case 24 \n\
        .4byte lbl_080591de @ case 25 \n\
        .4byte lbl_080591e2 @ case 26 \n\
        .4byte lbl_080591e6 @ case 27 \n\
        .4byte lbl_080591c2 @ case 28 \n\
    lbl_08059198: \n\
        ldrh r0, [r5] \n\
        sub r0, #1 \n\
        strh r0, [r5] \n\
        b lbl_080591e8 \n\
    lbl_080591a0: \n\
        ldrh r0, [r5] \n\
        sub r0, #1 \n\
        strh r0, [r5] \n\
    lbl_080591a6: \n\
        ldrh r0, [r5, #2] \n\
        sub r0, #1 \n\
        strh r0, [r5, #2] \n\
        b lbl_080591e8 \n\
    lbl_080591ae: \n\
        add r0, r5, #0 \n\
        bl BlockCheckRevealOrDestroyBombBlock \n\
        add r4, r0, #0 \n\
        b lbl_080591e8 \n\
    lbl_080591b8: \n\
        add r0, r5, #0 \n\
        bl BlockCheckRevealOrDestroyNonBombBlock \n\
        add r4, r0, #0 \n\
        b lbl_080591e8 \n\
    lbl_080591c2: \n\
        add r0, r5, #0 \n\
        bl BlockCheckRevealOrDestroyNonBombBlock \n\
        b lbl_080591ec \n\
    lbl_080591ca: \n\
        movs r6, #0 \n\
        b lbl_080591e8 \n\
    lbl_080591ce: \n\
        movs r6, #1 \n\
        b lbl_080591e8 \n\
    lbl_080591d2: \n\
        movs r6, #2 \n\
        b lbl_080591e8 \n\
    lbl_080591d6: \n\
        movs r6, #3 \n\
        b lbl_080591e8 \n\
    lbl_080591da: \n\
        movs r6, #4 \n\
        b lbl_080591e8 \n\
    lbl_080591de: \n\
        movs r6, #5 \n\
        b lbl_080591e8 \n\
    lbl_080591e2: \n\
        movs r6, #6 \n\
        b lbl_080591e8 \n\
    lbl_080591e6: \n\
        movs r6, #7 \n\
    lbl_080591e8: \n\
        cmp r4, #0 \n\
        bne lbl_080591f0 \n\
    lbl_080591ec: \n\
        movs r0, #0 \n\
        b lbl_080592b0 \n\
    lbl_080591f0: \n\
        ldr r1, lbl_08059208 @ =sBlockBehaviors \n\
        ldrb r0, [r5, #6] \n\
        lsl r0, r0, #2 \n\
        add r0, r0, r1 \n\
        ldrb r1, [r0] \n\
        cmp r1, #2 \n\
        beq lbl_08059222 \n\
        cmp r1, #2 \n\
        bgt lbl_0805920c \n\
        cmp r1, #1 \n\
        beq lbl_08059216 \n\
        b lbl_080592ae \n\
        .align 2, 0 \n\
    lbl_08059208: .4byte sBlockBehaviors \n\
    lbl_0805920c: \n\
        cmp r1, #3 \n\
        beq lbl_08059234 \n\
        cmp r1, #4 \n\
        beq lbl_08059274 \n\
        b lbl_080592ae \n\
    lbl_08059216: \n\
        add r0, r5, #0 \n\
        bl BlockDestroyNonReformBlock \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        b lbl_080592ac \n\
    lbl_08059222: \n\
        ldrb r0, [r0, #2] \n\
        ldrh r1, [r5] \n\
        ldrh r2, [r5, #2] \n\
        movs r3, #0 \n\
        bl BlockStoreBrokenReformBlock \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        b lbl_080592ac \n\
    lbl_08059234: \n\
        add r0, r5, #0 \n\
        bl BlockCheckRevealOrDestroyBombBlock \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        ldr r2, lbl_0805926c @ =gActiveBombChainTypes \n\
        ldr r1, lbl_08059270 @ =sBombChainReverseData \n\
        lsl r0, r6, #2 \n\
        add r0, r0, r1 \n\
        ldrb r1, [r2] \n\
        ldrb r0, [r0] \n\
        and r0, r1 \n\
        cmp r0, #0 \n\
        bne lbl_080592ae \n\
        add r0, r6, #0 \n\
        ldrh r1, [r5] \n\
        ldrh r2, [r5, #2] \n\
        bl BlockStartBombChain \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        add r0, r5, #0 \n\
        bl BlockDestroyNonReformBlock \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        b lbl_080592ac \n\
        .align 2, 0 \n\
    lbl_0805926c: .4byte gActiveBombChainTypes \n\
    lbl_08059270: .4byte sBombChainReverseData \n\
    lbl_08059274: \n\
        ldr r1, lbl_080592b8 @ =sClipdataAffectingActionDamageTypes \n\
        ldr r0, lbl_080592bc @ =gCurrentClipdataAffectingAction \n\
        ldrb r0, [r0] \n\
        lsl r0, r0, #1 \n\
        add r0, r0, r1 \n\
        ldrh r1, [r0] \n\
        movs r0, #0x1f \n\
        and r0, r1 \n\
        cmp r0, #0 \n\
        beq lbl_080592ae \n\
        ldr r1, lbl_080592c0 @ =sTankBehaviors \n\
        ldrh r0, [r5, #4] \n\
        sub r0, #0x34 \n\
        lsl r0, r0, #3 \n\
        add r0, r0, r1 \n\
        ldrh r4, [r0, #4] \n\
        cmp r4, #0 \n\
        beq lbl_080592ae \n\
        ldrh r1, [r5, #2] \n\
        ldrh r2, [r5] \n\
        add r0, r4, #0 \n\
        bl BgClipSetBg1BlockValue \n\
        ldrh r1, [r5, #2] \n\
        ldrh r2, [r5] \n\
        add r0, r4, #0 \n\
        bl BgClipSetClipdataBlockValue \n\
    lbl_080592ac: \n\
        movs r7, #1 \n\
    lbl_080592ae: \n\
        add r0, r7, #0 \n\
    lbl_080592b0: \n\
        pop {r4, r5, r6, r7} \n\
        pop {r1} \n\
        bx r1 \n\
        .align 2, 0 \n\
    lbl_080592b8: .4byte sClipdataAffectingActionDamageTypes \n\
    lbl_080592bc: .4byte gCurrentClipdataAffectingAction \n\
    lbl_080592c0: .4byte sTankBehaviors \n\
    ");
}
#endif

/**
 * @brief 592c4 | 6c | Handles the destruction of non reform blocks
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u32 bool, could destroy
 */
u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock)
{
    u32 subType;
    u32 result;

    result = FALSE;
    subType = sBlockBehaviors[pClipBlock->blockBehavior].subType;

    switch (subType)
    {
        case BLOCK_SUB_TYPE_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NO_REFORM:
        case BLOCK_SUB_TYPE_BOMB_CHAIN:
            // Nothing special to do
            break;

        case BLOCK_SUB_TYPE_NO_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM:
            // Store a never reform bock
            result = BlockStoreSingleNeverReformBlock(pClipBlock->xPosition, pClipBlock->yPosition);
            break;

        default:
            result = TRUE;
    }

    if (result)
        return FALSE;

    // Run special handler depending on the type
    result = sNonReformDestroyFunctionPointers[subType](pClipBlock);
    return result;
}

/**
 * @brief 59330 | 3c | Destroys a single bomb chain block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = CLIPDATA_AIR;
    return TRUE;
}

/**
 * @brief 5936c | 3c | Destroys a single block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = CLIPDATA_AIR;
    return TRUE;
}

/**
 * @brief 593a8 | d8 | Destroys a square block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock)
{
    u8 blockType;

    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Destroy top left
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0;

    // Destroy bottom right
    pClipBlock->xPosition++;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0;
    
    // Destroy top right
    pClipBlock->yPosition--;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0;
    
    // Destroy bottom left
    pClipBlock->xPosition--;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    gBgPointersAndDimensions.pClipDecomp[pClipBlock->yPosition * gBgPointersAndDimensions.clipdataWidth + pClipBlock->xPosition] = 0;

    // Play sound
    if (gCurrentClipdataAffectingAction != CAA_SPEEDBOOSTER)
        SoundPlayNotAlreadyPlaying(SOUND_SQUARE_BLOCK_DESTROYED);

    return TRUE;
}

/**
 * @brief 59480 | 80 | Stores a single never reform block in the save array
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @return u32 bool, couldn't store
 */
u32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition)
{
    u32 overLimit;
    u8* pBlock;
    s32 i;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return FALSE;
    else if (xPosition * yPosition == 0)
        return FALSE;

    overLimit = TRUE;
    // 0x2035c00 = gNeverReformBlocks
    pBlock = (u8*)(0x2035c00 + gCurrentArea * 512);
    i = gNumberOfNeverReformBlocks[gCurrentArea] * 2;

    // Find empty slot
    for (; i < 0x1FC; i += 2)
    {
        if (pBlock[i] == UCHAR_MAX)
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

/**
 * @brief 59500 | 80 | Removes the broken never reform blocks of a room
 * 
 */
void BlockRemoveNeverReformBlocks(void)
{
    s32 i;
    s32 var_0;
    u8* pBlock;
    s32 limit;

    if (gPauseScreenFlag)
        i = TRUE;
    else
        i = FALSE;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        i = TRUE;

    if (i)
        return;

    // 0x2035c00 = gNeverReformBlocks
    pBlock = (u8*)(0x2035c00 + gCurrentArea * 512);
    limit = gNumberOfNeverReformBlocks[gCurrentArea] * 2;
    for (var_0 = 0; i < limit; i += 2)
    {
        if (pBlock[i + 0] == 0)
            var_0 = 1;

        if (var_0 == 1)
        {
            if (pBlock[i + 1] == gCurrentRoom)
                var_0 = 2;
            else
                var_0 = 0;
        }
        else if (var_0 == 2)
        {
            BlockRemoveNeverReformSingleBlock(pBlock[i + 0], pBlock[i + 1]);
        }
    }
}

/**
 * @brief 59580 | 64 | Removes a never reform block from the BG1 and clipdata
 * 
 * @param xPosition X position
 * @param yPosition Y position
 */
void BlockRemoveNeverReformSingleBlock(u8 xPosition, u8 yPosition)
{
    u16 behavior;
    u32 position;

    // Get position
    position = gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition;

    // Get previous behavior
    behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[position]];

    // Clear clipdata and bg1
    gBgPointersAndDimensions.pClipDecomp[position] = 0;
    gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;

    if (behavior == CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)
    {
        // Clear the rest of the 2x2 block
        gBgPointersAndDimensions.pClipDecomp[position + 1] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position + 1] = 0;

        position += gBgPointersAndDimensions.clipdataWidth;
        gBgPointersAndDimensions.pClipDecomp[position] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
        position++;

        gBgPointersAndDimensions.pClipDecomp[position] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
    }
}

/**
 * @brief 595e4 | 18c | Shifts and re-organizes the never reform blocks when transitionning
 * 
 */
void BlockShiftNeverReformBlocks(void)
{
    u8* src;
    u8* dst;
    s32 amount;
    s32 var_0;
    s32 i;

    // FIXME use symbol
    src = (u8*)0x2035c00 + gAreaBeforeTransition * 512; // gNeverReformBlocks
    if (src[gNumberOfNeverReformBlocks[gAreaBeforeTransition] * 2] == UCHAR_MAX)
        return;

    dst = EWRAM_BASE;
    DmaTransfer(3, src, dst, 512, 16);
    BitFill(3, USHORT_MAX, src, 512, 16);

    var_0 = 0;
    amount = 0;
    i = 0;

    while (amount < gNumberOfNeverReformBlocks[gAreaBeforeTransition] * 2)
    {
        if (dst[amount] == 0)
        {
            if (var_0 == 1)
                var_0 = 10;
            else if (var_0 == 0 && dst[i + 1] == gCurrentRoom)
                var_0 = 1;
        }

        if (var_0 < 10)
        {
            src[i++] = dst[amount++];
            src[i++] = dst[amount++];
        }
        else if (var_0 == 10)
        {
            dst = EWRAM_BASE + gNumberOfNeverReformBlocks[gAreaBeforeTransition] * 2;
            while (*dst != UCHAR_MAX)
            {
                src[i++] = *dst++;
                src[i++] = *dst++;
            }

            var_0 = 2;
            dst = EWRAM_BASE;
        }
    }

    if (var_0 != 2)
    {
        if (var_0 != 1)
        {
            src[i++] = 0;
            src[i++] = gCurrentRoom;
        }

        dst = EWRAM_BASE + gNumberOfNeverReformBlocks[gAreaBeforeTransition] * 2;
        while (*dst != UCHAR_MAX)
        {
            src[i++] = *dst++;
            src[i++] = *dst++;
        }
    }

    gNumberOfNeverReformBlocks[gAreaBeforeTransition] = i >> 1;
}

/**
 * @brief 59770 | 84 | Checks if a non bomb block should be destroyed
 * 
 * @param pClipBlock Clipdata block data pointer
 * @return u32 bool, destroy
 */
u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock)
{
    s32 blockType;

    // Get block type
    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Check for block weakness
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & sBlockWeaknesses[blockType])
    {
        // Block is weak to current action, hence it that be destroyed
        return TRUE;
    }
    
    // Check weaknesses to reveal
    if ((gCurrentClipdataAffectingAction != CAA_BOMB_PISTOL && (gCurrentClipdataAffectingAction != CAA_POWER_BOMB ||
        gCurrentPowerBomb.owner)))
        return FALSE;

    // Check isn't already revealed
    if (pClipBlock->behavior != sReformingBlocksTilemapValue[blockType])
    {
        // Reveal
        BgClipSetBg1BlockValue(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
        BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
    }

    return FALSE;
}

/**
 * @brief 597f4 | 88 | Checks if a bomb block should be destroyed
 * 
 * @param pClipBlock Clipdata block data pointer
 * @return u32 bool, destroy
 */
u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock)
{
    s32 blockType;
    u16 value;
    u32 reveal;

    // Get block type
    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Check for block weakness
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & sBlockWeaknesses[blockType])
    {
        // Block is weak to current action, hence it that be destroyed
        return TRUE;
    }

    // Check weaknesses to reveal and isn't already revealed
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] &
        (CAA_DAMAGE_TYPE_BEAM | CAA_DAMAGE_TYPE_MISSILE | CAA_DAMAGE_TYPE_SUPER_MISSILE) &&
        pClipBlock->behavior != sReformingBlocksTilemapValue[blockType])
    {
        reveal = TRUE;
        value = sReformingBlocksTilemapValue[blockType];

        if (blockType > BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM)
        {
            // Handle the special case of bomb chain blocks
            reveal = BlockCheckRevealBombChainBlock(blockType, pClipBlock->xPosition, pClipBlock->yPosition);
        }

        if (!reveal)
            return FALSE;

        // Reveal block
        BgClipSetBg1BlockValue(value, pClipBlock->yPosition, pClipBlock->xPosition);
        BgClipSetClipdataBlockValue(value, pClipBlock->yPosition, pClipBlock->xPosition);
    }

    return FALSE;
}

/**
 * @brief 5987c | 164 | Applies the Ccaa (Current Clipdata Affecting Action)
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param trueClip True clipdata block value
 * @return u32 1 if a block changed, 0 otherwise
 */
u32 BlockApplyCcaa(u16 yPosition, u16 xPosition, u16 trueClip)
{
    struct ClipdataBlockData clipBlock;
    u32 result;

    // Create clipdata block data structure
    clipBlock.xPosition = xPosition;
    clipBlock.yPosition = yPosition;
    clipBlock.behavior = gTilemapAndClipPointers.pClipBehaviors[trueClip];
    clipBlock.blockBehavior = 0;

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
                BgClipCheckOpeningHatch(clipBlock.xPosition, clipBlock.yPosition) != 0)
                result = TRUE;
            else
            {
                // Check on block
                if (BlockCheckCcaa(&clipBlock))
                    result = TRUE;
            }
            break;

        case CAA_SPEEDBOOSTER:
        case CAA_SPEEDBOOSTER_ON_GROUND:
            if (BlockCheckCcaa(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(SOUND_BLOCK_DESTROYED_WITH_SPEEDBOOSTER);
                result = TRUE;
            }
            break;

        case CAA_SCREW_ATTACK:
            if (BlockCheckCcaa(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(SOUND_BLOCK_DESTROYED_WITH_SCREW_ATTACK);
                result = TRUE;
            }
            break;

        case CAA_BOMB_CHAIN:
        case CAA_BOMB_CHAIN_UNUSED:
            if (BlockCheckCcaa(&clipBlock))
                result = TRUE;
            break;

        case CAA_REMOVE_SOLID:
            if (!BlockUpdateMakeSolidBlocks(FALSE, xPosition, yPosition))
                BgClipSetBg1BlockValue(0, yPosition, xPosition);

            BgClipSetClipdataBlockValue(0, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID_GRIPPABLE:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID2, yPosition, xPosition);
            break;

        case CAA_MAKE_STOP_ENEMY:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_STOP_ENEMY_AIR, yPosition, xPosition);
            break;

        case CAA_MAKE_NON_POWER_GRIP:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_NON_POWER_GRIP, yPosition, xPosition);
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
    s32 i;
    u16* pBlocks;

    result = FALSE;

    if (!makeSolid)
    {
        // Remove solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Found in the array, remove
                pBlocks[i] = 0;
                result = TRUE;
                break;
            }
        }
    }
    else
    {
        // Make solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
        {
            if (pBlocks[--i] == (xPosition << 8 | yPosition))
            {
                // Already in the array
                i = UCHAR_MAX;
                break;
            }
            else if (pBlocks[i] == 0)
                break; // Found empty space
        }

        result = FALSE;
        if (i != UCHAR_MAX)
        {
            if (gBgPointersAndDimensions.pClipDecomp[gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition] == 0)
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

    blockX = xPosition / BLOCK_SIZE;
    blockY = yPosition / BLOCK_SIZE;

    if (blockX < gBgPointersAndDimensions.clipdataWidth && blockY < gBgPointersAndDimensions.clipdataHeight)
    {
        // Set Ccaa
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
        position = gBgPointersAndDimensions.clipdataWidth * blockY + blockX;
        clipdata = gBgPointersAndDimensions.pClipDecomp[position];

        if (clipdata != 0)
        {
            // Apply first
            result = BlockApplyCcaa(blockY, blockX, clipdata);

            if (!result && action == DESTRUCTING_ACTION_SPEED_SCREW)
            {
                // Apply second
                gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
                BlockApplyCcaa(blockY, blockX, clipdata);
            }
        }
    }
    else
        return FALSE;

    // Clear Ccaa
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
    s32 i;
    u32 updateStage;

    pBlock = gBrokenBlocks;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        // Check exists
        if (pBlock->stage == 0)
            continue;

        // Update timer
        pBlock->timer++;

        if (pBlock->broken)
        {
            if (pBlock->timer < sBrokenBlocksTimers[pBlock->type][pBlock->stage])
                continue;

            updateStage = FALSE;
            pBlock->timer = 0;

            if (pBlock->stage >= ARRAY_SIZE(sBrokenBlocksTimers[0]))
            {
                if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                {
                    pBlock->stage = 2;
                }
                else
                {
                    BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[pBlock->type], pBlock->yPosition, pBlock->xPosition);
                    pBlock->broken = FALSE;
                    pBlock->stage = 0;
                    pBlock->type = BLOCK_TYPE_NONE;
                    pBlock->xPosition = 0;
                    pBlock->yPosition = 0;
                }
            }
            else if (pBlock->stage == 7)
            {
                if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                    pBlock->timer = sBrokenBlocksTimers[pBlock->type][pBlock->stage] / 2;
                else
                    updateStage = TRUE;
            }
            else
            {
                if (pBlock->stage == 1)
                    BlockBrokenBlockRemoveCollision(pBlock->yPosition, pBlock->xPosition);
                updateStage = TRUE;
            }

            if (updateStage)
            {
                pBlock->stage++;
                BlockUpdateBrokenBlockAnimation(pBlock);
            }
        }
        else if (pBlock->timer >= sBrokenBlocksTimers[pBlock->type][pBlock->stage])
        {
            pBlock->timer = 0;
            pBlock->stage++;

            BlockUpdateBrokenBlockAnimation(pBlock);

            if (pBlock->stage > 6)
            {
                pBlock->broken = FALSE;
                pBlock->stage = 0;
                pBlock->type = BLOCK_TYPE_NONE;
                pBlock->xPosition = 0;
                pBlock->yPosition = 0;
            }
        }
    }
}

/**
 * @brief 59c74 | 134 | Updates the animation of a breaking block
 * 
 * @param pBlock Broken block pointer
 */
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock)
{
    u16 value;
    u16* dst;
    u16* src;
    u32 offset;

    value = CLIPDATA_TILEMAP_AIR;

    // Get clipdata tilemap value
    switch (pBlock->stage)
    {
        case 2:
        case 12:
            value = sReformingBlocksTilemapValue[pBlock->type];
            break;

        case 3:
        case 11:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID;
            break;

        case 4:
        case 10:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_1;
            break;

        case 5:
        case 9:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_2;
            break;

        case 6:
        case 8:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_3;
            break;

        case 7:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_AIR;
            break;

        case 0:
        case 1:
        case 13:
            break;
    }

    // No tile, abort
    if (value == CLIPDATA_TILEMAP_AIR)
        return;

    // Write value to BG1 map
    gBgPointersAndDimensions.backgrounds[1].pDecomp[pBlock->yPosition * gBgPointersAndDimensions.backgrounds[1].width +
        pBlock->xPosition] = value;

    // Check is on screen, no need to update the tilemap if off screen, that can be delegated to the room tilemap update functions
    offset = gBg1YPosition / BLOCK_SIZE;
    if ((s32)(offset - 4) > pBlock->yPosition || pBlock->yPosition > (s32)(offset + 13))
        return;

    offset = gBg1XPosition / BLOCK_SIZE;
    if ((s32)(offset - 4) > pBlock->xPosition || pBlock->xPosition > (s32)(offset + 18))
        return;

    // Apply to tilemap
    dst = VRAM_BASE + 0x1000;
    if (pBlock->xPosition & 0x10)
        dst = VRAM_BASE + 0x1800;

    offset = (pBlock->xPosition & 0xF) * 2;
    dst += (pBlock->yPosition & 0xF) * 64 + offset;

    offset = value * 4;
    src = gTilemapAndClipPointers.pTilemap;
    dst[0] = src[offset++];
    dst[1] = src[offset++];
    dst[32] = src[offset++];
    dst[33] = src[offset];
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
    s32 i;
    struct BrokenBlock* pBlock;

    result = FALSE;
    pBlock = gBrokenBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS;)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            // Already in array
            if (pBlock->stage == 0)
                result = TRUE;
            else
                result = FALSE;
            break;
        }
        else
        {
            // Check save empty offset
            if (!(result & 0x80) && pBlock->stage == 0)
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
        pBlock->timer = 0;

        if (result & 0x80)
        {
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;
        }

        if (!advanceStage)
        {
            pBlock->stage = 2;
            BlockBrokenBlockRemoveCollision(yPosition, xPosition);
            BlockUpdateBrokenBlockAnimation(pBlock);
        }
        else
            pBlock->stage = 1;

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
    s32 i;
    s32 stage;

    for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->stage == 0)
        {
            // Found slot
            pBlock->broken = FALSE;
            pBlock->stage = 2;
            pBlock->type = type;
            pBlock->timer = 0;
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;

            BlockUpdateBrokenBlockAnimation(pBlock);
            return;
        }
    }

    for (stage = 4; stage != 0; stage >>= 1)
    {
        for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
        {
            // Already broken
            if (pBlock->broken)
                continue;

            // Not far enough
            if (pBlock->stage < stage)
                continue;

            // Remove bg1
            BgClipSetBg1BlockValue(0, pBlock->yPosition, pBlock->xPosition);

            // Register
            pBlock->broken = FALSE;
            pBlock->stage = 2;
            pBlock->type = type;
            pBlock->timer = 0;
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;

            BlockUpdateBrokenBlockAnimation(&gBrokenBlocks[i]);
            return;
        }
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
    s32 i;
    s32 couldSpawn;

    couldSpawn = FALSE;

    for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            couldSpawn = 0;
            break;
        }

        if (!(couldSpawn & 0x80) && pBlock->stage == 0)
            couldSpawn = i | 0x80;
    }

    if (couldSpawn)
    {
        pBlock = gBrokenBlocks + (couldSpawn & 0x7F);

        pBlock->broken = FALSE;
        pBlock->stage = 0;
        pBlock->type = type;
        pBlock->timer = 0;
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
    if ((gSamusData.yPosition + gSamusPhysics.drawDistanceTop) >> 6 <= yPosition &&
        yPosition <= (gSamusData.yPosition + gSamusPhysics.drawDistanceBottom) >> 6)
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
    s32 i;
    
    couldSpawn = FALSE;
    
    for (i = MAX_AMOUNT_OF_BOMB_CHAINS - 1 ; i >= 0; i--)
    {
        if (gBombChains[i].currentOffset == 0)
        {
            // Found empty slot
            gBombChains[i].currentOffset = 1;
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
        SoundPlayNotAlreadyPlaying(SOUND_BOMB_CHAIN);

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
    pChain += (gFrameCounter8Bit & 3);

    if (pChain->currentOffset == 0)
        return;

    horizontal = FALSE;
    if (pChain->type > BOMB_CHAIN_TYPE_VERTICAL4)
        horizontal = TRUE;

    // Create clipdata block data structure
    clipBlock.behavior = sBombChainReverseData[pChain->type].behavior;
    clipBlock.blockBehavior = BEHAVIOR_TO_BLOCK(clipBlock.behavior);
    clipBlock.yPosition = 0;
    clipBlock.xPosition = 0;

    if (!horizontal)
    {
        // Update vertical
        clipBlock.xPosition = pChain->srcXPosition;
        if (pChain->flipped)
        {
            // Going up
            clipBlock.yPosition = pChain->srcYPosition - pChain->currentOffset;
            if (clipBlock.yPosition <= 1)
                pChain->flipped = FALSE;
            else
            {
                clipdata = gBgPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBgPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
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
            if (clipBlock.yPosition >= gBgPointersAndDimensions.clipdataHeight - 2)
                pChain->unk = FALSE;
            else
            {
                clipdata = gBgPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBgPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
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
            if (clipBlock.xPosition <= 1)
                pChain->flipped = FALSE;
            else
            {
                clipdata = gBgPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBgPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
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
            if (clipBlock.xPosition >= gBgPointersAndDimensions.clipdataWidth - 2)
                pChain->unk = FALSE;
            else
            {
                clipdata = gBgPointersAndDimensions.pClipDecomp[clipBlock.yPosition * gBgPointersAndDimensions.clipdataWidth + clipBlock.xPosition];
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
        pChain->currentOffset = 0;

        // Remove type
        gActiveBombChainTypes &= ~sBombChainReverseData[pChain->type].typeFlag;

        // Fade sound if no bomb chains active
        if (gActiveBombChainTypes == 0)
            SoundFade(SOUND_BOMB_CHAIN, CONVERT_SECONDS(1.f / 6));
    }
}

/**
 * @brief 5a330 | b0 | Checks if a new sub bomb chain should start
 * 
 * @param type Sub bomb chain type
 * @param xPosition X position
 * @param yPosition Y position
 */
void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition)
{
    u16 clipdata;
    s32 i;
    s32 yOffset;
    s32 xOffset;
    s32 offset;
    s32 width;

    // Set bomb chain CAA
    gCurrentClipdataAffectingAction = CAA_BOMB_CHAIN;

    // Check the current position
    clipdata = gBgPointersAndDimensions.pClipDecomp[yPosition * gBgPointersAndDimensions.clipdataWidth + xPosition];
    if (clipdata != 0)
        BlockApplyCcaa(yPosition, xPosition, clipdata);

    for (i = 0; i < ARRAY_SIZE(sSubBombChainPositionOffset[0]) / 2; i++)
    {
        width = gBgPointersAndDimensions.clipdataWidth;

        // Get Y offset
        yOffset = yPosition + sSubBombChainPositionOffset[type][i * 2 + 1];
        offset = yOffset * gBgPointersAndDimensions.clipdataWidth;
        
        // Get X offset
        xOffset = xPosition + sSubBombChainPositionOffset[type][i * 2 + 0];
        offset += xOffset;

        // Get clipdata
        clipdata = gBgPointersAndDimensions.pClipDecomp[offset];

        // Apply to block
        if (clipdata != 0)
            BlockApplyCcaa(yOffset, xOffset, clipdata);
    }

    // Clear CAA
    gCurrentClipdataAffectingAction = CAA_NONE;
}

/**
 * @brief 5a3e0 | a4 | Removes the collision and graphics of a broken block 
 * 
 * @param yPosition Y position
 * @param xPosition X position
 */
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition)
{
    u16 position;
    u16* dst;

    position = gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition;
    gBgPointersAndDimensions.pClipDecomp[position] = 0;
    gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;

    if (gBg1YPosition / BLOCK_SIZE - 4 > yPosition)
        return;
    
    if (yPosition > gBg1YPosition / BLOCK_SIZE + 13)
        return;

    if (gBg1XPosition / BLOCK_SIZE - 4 > xPosition)
        return;
        
    if (xPosition > gBg1XPosition / BLOCK_SIZE + 18)
        return;

    dst = VRAM_BASE + 0x1000;
    if (xPosition & 0x10)
        dst = VRAM_BASE + 0x1800;

    dst += (yPosition & 0xF) * BLOCK_SIZE + (xPosition & 0xF) * 2;

    dst[0] = gTilemapAndClipPointers.pTilemap[0];
    dst[1] = gTilemapAndClipPointers.pTilemap[1];
    dst[32] = gTilemapAndClipPointers.pTilemap[2];
    dst[33] = gTilemapAndClipPointers.pTilemap[3];
}
