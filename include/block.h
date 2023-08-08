#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"
#include "structs/block.h"

u32 BlockCheckCCAA(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition);
void BlockRemoveNeverReformBlocks(void);
void BlockRemoveNeverReformSingleBlock(u8 xPosition, u8 yPosition);
void BlockShiftNeverReformBlocks(void);
u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 trueClip);
u32 BlockUpdateMakeSolidBlocks(u8 makeSolid, u16 xPosition, u16 yPosition);
u32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u16 action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock);
u32 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 advanceStage);
void BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type);
u32 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition);
u32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition);
u32 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition);
void BlockProcessBombChains(void);
void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition);
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition);

#endif /* BLOCK_H */