#ifndef SAVE_FILE_STRUCT_H
#define SAVE_FILE_STRUCT_H

#include "types.h"
#include "macros.h"
#include "gba.h"
#include "sram_misc.h"

#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/connection.h"
#include "structs/in_game_timer.h"
#include "structs/time_attack.h"
#include "structs/demo.h"

#define CORRUPTED_FILE_FLAG_CURRENT 1
#define CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP 2

#define SRAM_TEXT_SIZE 16

#define SRAM_GET_CHECKSUM_SIZE(type, iteration, checksumType) ((s32)(sizeof(type) / iteration / sizeof(checksumType)))

struct StartingInfo {
    u8 startingArea;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};

struct SaveFileInfo {
    u8 exists;
    u8 corruptionFlag;
    u8 currentArea;
    u16 currentEnergy;
    u16 maxEnergy;
    u16 currentMissiles;
    u16 maxMissiles;
    u8 suitType;
    u8 igtHours;
    u8 igtMinutes;
    u8 igtSconds;
    u8 hasSaved;
    s8 completedGame;
    s8 introPlayed;
    s8 language;
    u8 difficulty;
    u8 timeAttack;
};

struct SaveMusicInfo {
    u16 musicTrack;
    u16 unk_2;
    u8 unk_4;
    u8 priority;
};

struct SaveWorldData {
    u32 visitedMinimapTiles[MAX_AMOUNT_OF_AREAS][32];
    u8 neverReformBlocksBroken[2048];
    u8 itemsCollected[512];
    u32 hatchesOpened[MAX_AMOUNT_OF_AREAS][8];
    u32 eventsTriggered[8];
};

struct SaveFile {
    u8 ZERO_MISSION_010_Text[SRAM_TEXT_SIZE];
    s32 checksum;
    s32 notChecksum;

    struct GameCompletion gameCompletion;
    u8 hasSaved;
    u8 currentArea;
    u8 currentRoom;
    u8 LastDoorUsed;
    u8 mapX;
    u8 mapY;

    struct Camera camera;
    u16 bg0XPosition;
    u16 bg0YPosition;
    u16 bg1XPosition;
    u16 bg1YPosition;
    u16 bg2XPosition;
    u16 bg2YPosition;
    u16 bg3XPosition;
    u16 bg3YPosition;

    u8 difficulty;
    u8 useMotherShipDoor;
    u8 timeAttack;

    u8 numberOfNeverReformBlocksBroken[MAX_AMOUNT_OF_AREAS];
    u8 numberOfItemsCollected[MAX_AMOUNT_OF_AREAS];

    u8 PlanetZebes_Text[SRAM_TEXT_SIZE];

    struct SamusData samusData;
    struct WeaponInfo samusWeaponInfo;
    struct SamusEcho samusEcho;
    struct ScrewSpeedAnimation screwSpeedAnimation;
    struct Equipment equipment;
    struct HazardDamage hazardDamage;
    struct EnvironmentalEffect environmentalEffects[5];
    u16 preventMovementTimer;
    u8 disableDrawingSamusAndScrolling;

    u16 alarmTimer;
    struct InGameTimer inGameTimer;
    struct InGameTimer bestCompletionTimes[12];
    struct InGameTimer inGameTimerAtBosses[MAX_AMOUNT_OF_IGT_AT_BOSSES];

    struct SaveMusicInfo musicInfo;

    u32 inGameCutscenesTriggered[1];

    u8 SamusAran_Text[SRAM_TEXT_SIZE];

    u8 freespace[160];

    struct SaveWorldData worldData;
};

struct SaveDemo {
    u8 currentArea;
    u8 lastDoorUsed;

    u8 unk_2;
    u8 unk_3;

    struct SamusData samusData;
    struct WeaponInfo samusWeaponInfo;
    struct SamusEcho samusEcho;
    struct ScrewSpeedAnimation screwSpeedAnimation;
    struct Equipment equipment;
    struct HazardDamage hazardDamage;
    struct EnvironmentalEffect environmentalEffects[5];

    u8 visitedMinimapTiles[128];
    u8 hatchesOpened[32];
    u8 text[8];
    u8 useMotherShipDoors;

    u8 padding_241[63];
};

struct SaveFileScreenOptions {
    u32 checksum;
    u32 notChecksum;
    
    u8 unk_8;
    u8 unk_9;
    u16 counter;
    
    u16 galleryImages;
    u8 soundTestAndOriginalMetroid;

    u8 unk_F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u16 fusionGalleryImages;

    u32 timeAttack;
    u8 ZeroMissionUSA_Text[20];

    u8 padding_2A[16];
};

struct SaveValue {
    u8 magicNumber;
    u8 counter;
    u16 checksum;
    u16 notChecksum;

    u8 startText[SRAM_TEXT_SIZE];
    u8 value;
    u8 endText[SRAM_TEXT_SIZE];

    u8 padding_27[24];
};

struct SaveTimeAttack {
    u8 magicNumber;

    u8 padding_1[16];

    u16 checksum;
    u16 notChecksum;
    u8 counter;

    u8 startText[SRAM_TEXT_SIZE];
    struct TimeAttackRecord value;
    u8 endText[SRAM_TEXT_SIZE];

    u8 padding_68[152];
};

struct Sram {
    struct SaveFileScreenOptions fileScreenOptions_fileA;
    struct SaveFileScreenOptions fileScreenOptions_fileB;

    struct SaveFile files[3];
    struct SaveFile filesCopy[3];

    struct SaveFileScreenOptions fileScreenOptions_fileC;

    struct SaveValue mostRecentFileSave;
    struct SaveValue languagesSave[2];
    struct SaveValue soundModeSave;
    struct SaveTimeAttack timeAttackSaves[2];

    u16 demoInputData[DEMO_MAX_DURATION];
    u16 demoInputDuration[DEMO_MAX_DURATION];

    u8 padding_7480[896];

    struct SaveDemo demoSave;

    u8 padding_7a80[1264];

    u8 unk_7f70[16];
    u8 MetZeroSramCheck_Text[SRAM_TEXT_SIZE];
};

// Make sure that the size of the sram struct doesn't exceed the size of the flash sram
STATIC_ASSERT(sizeof(struct Sram) <= SRAM_SIZE, SramStructSize);

extern u8 gSramOperationStage;
extern u8 gSramCorruptFlag;
extern struct Sram gSram;

extern u8 gUnk_3000c20;
extern struct SaveFileInfo gSaveFilesInfo[3];
extern struct StartingInfo gStartingInfo;

// Place holder symbols?
extern u16 gSramDemoInputData[DEMO_MAX_DURATION];
extern u16 gSramDemoInputDuration[DEMO_MAX_DURATION];

#endif /* SAVE_FILE_STRUCT_H */
