#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

#define BLOCK_TYPE_NONE 0x0
#define BLOCK_TYPE_SHOT_BLOCK_REFORM 0x1
#define BLOCK_TYPE_BOMB_BLOCK_REFORM 0x2
#define BLOCK_TYPE_SPEEDBOOSTER_BLOCK_REFORM 0x3
#define BLOCK_TYPE_CRUMBLE 0x4
#define BLOCK_TYPE_SLOW_CRUMBLE 0x5
#define BLOCK_TYPE_MISSILE_NEVER_REFORM 0x6
#define BLOCK_TYPE_MISSILE_NO_REFORM 0x7
#define BLOCK_TYPE_SUPER_MISSILE_NEVER_REFORM 0x8
#define BLOCK_TYPE_SUPER_MISSILE_NO_REFORM 0x9
#define BLOCK_TYPE_POWER_BOMB_NEVER_REFORM 0xA
#define BLOCK_TYPE_SCREW_NO_REFORM 0xB
#define BLOCK_TYPE_SPEEDBOOSTER_NO_REFORM 0xC
#define BLOCK_TYPE_BOMB_NEVER_REFORM 0xD
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN1 0xE
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN2 0xF
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN3 0x10
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN4 0x11
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1 0xE
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2 0xF
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3 0x10
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4 0x11

struct BrokenBlock {
    u8 broken;
    u8 stage;
    u8 type;
    u8 xPosition;
    u8 yPosition;
    u16 timer;
};

struct ClipdataBlockData {
    u16 xPosition;
    u16 yPosition;
    u16 behavior;
    u8 blockBehavior;
};

u8 BlockCheckCCAA(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition);
void BlockRemoveNeverReformBlocks(void);
void BlockRemoveNeverReformSingleBlock(u16 xPosition, u16 yPosition);
void BlockShiftNeverReformBlocks(void);
u8 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 trueClip);
u8 BlockUpdateMakeSolidBlocks(u8 make_solid, u16 xPosition, u16 yPosition);
u8 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u8 action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock);
u8 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 stopSamus);
u8 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type);
u8 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition);
u8 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition);
u8 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition);
void BlockProcessBombChains(void);
void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition);
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition);

#endif /* BLOCK_H */