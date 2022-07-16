#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

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
u8 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 true_clip);
u8 BlockUpdateMakeSolidBlocks(u8 make_solid, u16 xPosition, u16 yPosition);
u8 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u8 action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock);
u8 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 stop_samus);
u8 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type);
u8 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition);
u8 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition);
u8 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition);
void BlockProcessBombChains(void);
void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition);
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition);

#endif /* BLOCK_H */