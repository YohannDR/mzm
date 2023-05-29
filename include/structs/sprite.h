#ifndef SPRITE_STRUCT_H
#define SPRITE_STRUCT_H

#include "types.h"

#define ENEMY_ROOM_DATA_SIZE 3
#define ENEMY_ROOM_DATA_ARRAY_SIZE(nbr) (ENEMY_ROOM_DATA_SIZE * nbr)

// Structs

struct SubSpriteData {
    const struct FrameData* pMultiOam;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
    u16 health;
    u8 animationDurationCounter;
    u8 workVariable1;
    u8 workVariable2;
    u8 workVariable3;
    u8 workVariable4;
    u8 workVariable5;
    u8 workVariable6;
    u8 workVariable7;
};

struct SpriteData {
    u16 status;
    u16 yPosition;
    u16 xPosition;
    u16 yPositionSpawn;
    u16 xPositionSpawn;
    i16 hitboxTopOffset;
    i16 hitboxBottomOffset;
    i16 hitboxLeftOffset;
    i16 hitboxRightOffset;
    u16 oamScaling;
    u16 health;
    u16 currentAnimationFrame;
    const struct FrameData* pOam;
    u8 animationDurationCounter;
    u8 spriteID;
    u8 roomSlot;
    u8 spritesetGfxSlot;
    u8 paletteRow;
    u8 bgPriority;
    u8 drawOrder;
    u8 primarySpriteRamSlot;
    u8 pose;
    u8 samusCollision;
    u8 ignoreSamusCollisionTimer;
    u8 drawDistanceTopOffset;
    u8 drawDistanceBottomOffset;
    u8 drawDistanceHorizontalOffset;
    u8 oamRotation;
    u8 invincibilityStunFlashTimer;
    u8 timer;
    u8 workVariable;
    u8 workVariable2;
    u8 arrayOffset;
    u8 freezeTimer;
    u8 standingOnSprite;
    u8 properties;
    u8 frozenPaletteRowOffset;
    u8 absolutePaletteRow;
};

struct BossWork {
    u16 work1; // Usually spawn Y
    u16 work2; // Usually spawn X
    u16 work3;
    u16 work4; // Usually health
    u16 work5;
    u16 work6;
    u16 work7;
    u16 work8;
    u16 work9;
    u16 work10;
    u16 work11; // Completion percentage, only used by mecha ridley
    u16 work12;
    u16 work13;
    u16 work14;
    u16 work15;
    u16 work16;
    u16 work17;
    u16 work18;
    u16 work19;
    u16 work20;
    u16 work21;
    u16 work22;
    u16 work23;
    u16 work24;
};

// Globals

#define MAX_AMOUNT_OF_SPRITES 24

extern u16 gAlarmTimer;
extern struct SpriteData gSpriteData[MAX_AMOUNT_OF_SPRITES];
extern u8 gSpritesetSpritesID[15];
extern u8 gSpritesetGfxSlots[15];
extern struct SubSpriteData gSubSpriteData1;
extern struct SubSpriteData gSubSpriteData2;
extern u8 gParasiteRelated;
extern struct SpriteData gCurrentSprite;
extern u8 gPreviousVerticalCollisionCheck;
extern u8 gPreviousCollisionCheck;
extern u8 gIgnoreSamusAndSpriteCollision;
extern u8 gSpriteDrawOrder[MAX_AMOUNT_OF_SPRITES];
extern struct BossWork gBossWork;
extern u8 gSpriteRNG;
extern u8 gDisableDrawingSprites;

#endif
