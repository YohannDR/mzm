#ifndef KRAID_RISING_CUTSCENE
#define KRAID_RISING_CUTSCENE

#include "types.h"
#include "gba.h"
#include "structs/cutscene.h"

#define KRAID_RISING_OAM_ID_SAMUS 1
#define KRAID_RISING_OAM_ID_DEBRIS 2
#define KRAID_RISING_OAM_ID_SMALL_PUFF 3
#define KRAID_RISING_OAM_ID_BIG_PUFF 4

#define KRAID_RISING_PUFF_AMOUNT 11
#define KRAID_RISING_DEBRIS_AMOUNT 6

struct KraidRisingEwramData {
    u8 padding_0[BGCNT_VRAM_TILE_SIZE * 2];
    u8 barelyOpenedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 aLittleOpenedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 openedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 kraidRisingTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 caveBackgroundTileTable[BGCNT_VRAM_TILE_SIZE];
};

#define KRAID_RISING_EWRAM sEwramPointer->kraidRising

u8 KraidRisingRising(void);
struct CutsceneOamData* KraidRisingUpdatePuff(struct CutsceneOamData* pOam, u8 puffID);
struct CutsceneOamData* KraidRisingUpdateDebris(struct CutsceneOamData* pOam, u8 debrisID);
u8 KraidRisingOpeningEyes(void);
u8 KraidRisingInit(void);
u8 KraidRisingSubroutine(void);
void KraidRisingProcessOam(void);

#endif /* KRAID_RISING_CUTSCENE */
