#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

#define bomb_chain_type_to_flag(type) (1 << type)

#define MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS 64
#define MAX_AMOUNT_OF_BROKEN_BLOCKS 48
#define MAX_AMOUNT_OF_BOMB_CHAINS 4
#define MAX_AMOUNT_OF_BLOCKS 48
#define MAX_AMOUNT_OF_BLOCKS_TYPES 22
#define MAX_AMOUNT_OF_TANK_TYPES 12

extern struct BrokenBlock gBrokenBlocks[MAX_AMOUNT_OF_BROKEN_BLOCKS];
extern u16 gMakeSolidBlocks[MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS];
extern struct BombChain gBombChains[MAX_AMOUNT_OF_BOMB_CHAINS];
extern u8 gActiveBombChainTypes;

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
#define BLOCK_TYPE_SPEEDBOOSTER_BLOCK_NO_REFORM 0xC
#define BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM 0xD
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN1 0xE
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN2 0xF
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN3 0x10
#define BLOCK_TYPE_VERTICAL_BOMB_CHAIN4 0x11
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN1 0x12
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN2 0x13
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN3 0x14
#define BLOCK_TYPE_HORIZONTAL_BOMB_CHAIN4 0x15

#define ITEM_TYPE_NONE 0x0
#define ITEM_TYPE_MISSILE 0x1
#define ITEM_TYPE_ENERGY 0x2
#define ITEM_TYPE_SUPER_MISSILE 0x3
#define ITEM_TYPE_POWER_BOMB 0x4
#define ITEM_TYPE_ABILITY 0x80

#define CAA_DAMAGE_TYPE_NONE 0x0
#define CAA_DAMAGE_TYPE_BEAM 0x1
#define CAA_DAMAGE_TYPE_BOMB_PISTOL 0x2
#define CAA_DAMAGE_TYPE_MISSILE 0x4
#define CAA_DAMAGE_TYPE_SUPER_MISSILE 0x8
#define CAA_DAMAGE_TYPE_POWER_BOMB 0x10
#define CAA_DAMAGE_TYPE_SPEEDBOOST 0x20
#define CAA_DAMAGE_TYPE_SPEEDBOOST_ON_GROUND 0x40
#define CAA_DAMAGE_TYPE_SCREW_ATTACK 0x80
#define CAA_DAMAGE_TYPE_BOMB_CHAIN 0x1000

#define BLOCK_LIFE_TYPE_NONE 0x0 
#define BLOCK_LIFE_TYPE_NO_NEVER_REFORM 0x1 
#define BLOCK_LIFE_TYPE_REFORM 0x2 
#define BLOCK_LIFE_TYPE_BOMB_CHAIN 0x3 
#define BLOCK_LIFE_TYPE_TANK 0x4 

#define BLOCK_SUB_TYPE_REFORM 0x0
#define BLOCK_SUB_TYPE_SQUARE_NO_REFORM 0x1
#define BLOCK_SUB_TYPE_NO_REFORM 0x2
#define BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM 0x3
#define BLOCK_SUB_TYPE_BOMB_CHAIN 0x4

#define BOMB_CHAIN_TYPE_VERTICAL1 0x0
#define BOMB_CHAIN_TYPE_VERTICAL2 0x1
#define BOMB_CHAIN_TYPE_VERTICAL3 0x2
#define BOMB_CHAIN_TYPE_VERTICAL4 0x3
#define BOMB_CHAIN_TYPE_HORIZONTAL1 0x4
#define BOMB_CHAIN_TYPE_HORIZONTAL2 0x5
#define BOMB_CHAIN_TYPE_HORIZONTAL3 0x6
#define BOMB_CHAIN_TYPE_HORIZONTAL4 0x7

#define SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_UP 0x0
#define SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_DOWN 0x1
#define SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_LEFT 0x2
#define SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_RIGHT 0x3

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

struct BombChain {
    u8 currentOffset;
    u8 srcXPosition; 
    u8 srcYPosition;
    u8 type:3;
    u8 padding:3;
    u8 flipped:1;
    u8 unk:1;
};

struct TankList {
    u8 energy;
    u8 missile;
    u8 superMissile;
    u8 powerBomb;
};

struct BlockBehavior {
    u8 lifeType;
    u8 subType;
    u8 type;
    u8 unk;
};

struct BombChainReverseData {
    u8 typeFlag;
    u16 behavior;
};

struct TankBehavior {
    u8 itemType;
    u8 underwater;
    i8 messageID;
    u16 revealedClipdata;
};

u32 BlockCheckCCAA(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock);
u8 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition);
void BlockRemoveNeverReformBlocks(void);
void BlockRemoveNeverReformSingleBlock(u16 xPosition, u16 yPosition);
void BlockShiftNeverReformBlocks(void);
u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockApplyCCAA(u16 yPosition, u16 xPosition, u16 trueClip);
u32 BlockUpdateMakeSolidBlocks(u8 makeSolid, u16 xPosition, u16 yPosition);
u32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, u16 action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock);
u32 BlockStoreBrokenReformBlock(u8 type, u16 xPosition, u16 yPosition, u8 advanceStage);
u8 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, u8 type);
u8 BlockCheckRevealBombChainBlock(u8 type, u16 xPosition, u16 yPosition);
u32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition);
u32 BlockStartBombChain(u8 type, u16 xPosition, u16 yPosition);
void BlockProcessBombChains(void);
void BlockCheckStartNewSubBombChain(u8 type, u8 xPosition, u8 yPosition);
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition);

#endif /* BLOCK_H */