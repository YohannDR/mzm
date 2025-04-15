#ifndef MAP_SCREEN_MENU_STRUCT_H
#define MAP_SCREEN_MENU_STRUCT_H

#include "types.h"
#include "constants/menus/status_screen.h"
#include "structs/menu.h"
#include "structs/connection.h"

#define PAUSE_SCREEN_DATA sNonGameplayRamPointer->pauseScreen
#define PAUSE_SCREEN_EWRAM sEwramPointer->pauseScreen

struct ChozoStatueTarget {
    u8 statueArea;
    u8 statueXStart;
    u8 statueXEnd;
    u8 statueYStart;
    u8 statueYEnd;
    u8 startIcon;

    u8 targetArea;
    u8 targetX;
    u8 targetY;
    u8 endIcon;
};

struct PauseScreenAreaIconData {
    u8 nameOamId;
    u8 nameSpawningOamId;
    u8 outlineOamId;
    u16 xPosition;
    u16 yPosition;
};

struct PauseScreenWireframeData {
    u8 oamId;
    u16 xPosition;
    u16 yPosition;
    u16 xOffset;
    u8 objMode;
    u16 xPosition2; // TODO: better name
    u16 yPosition2;
};

struct WorldMapData {
    u8 nameOamId;
    u8 outlinedOamId;
    u16 xPosition;
    u16 yPosition;
};

struct MinimapAreaName {
    u8 area1;
    u8 mapX1;
    u8 mapY1;
    s8 xOffset1;
    s8 yOffset1;

    u8 area2;
    u8 mapX2;
    u8 mapY2;
    s8 xOffset2;
    s8 yOffset2;
};

struct PauseScreenSubroutineData {
    u8 currentSubroutine;
    u8 padding_1[3];
    u8 stage;
    u16 timer;
    u8 fadeWireframeStage;
    u16 fadeWireframeTimer; // set but never read
};

struct UnknownItemPalette {
    u16 timer;
    s8 paletteRow;
    u8 flashingNumber;
};

struct ChozoHintTarget {
    s8 index;
    u8 unk_41; // target path index?
    s8 unk_42; // target area?
    u16 activatedTargets;
    u8 activeMovementScrollingFlag;
    u8 movementStage;
    u8 movementDelayTimer;
    u8 scrollingStage;
    u8 scrollingDelayTimer;
    u8 unk_4B; // unused
};

struct ChozoHintMapData {
    u16 mapYPostion;
    u16 mapXPosition;
    u16 hintTargetYPosition;
    u16 hintTargetXPosition;
    s16 distYToHintTarget;
    s16 distXToHintTarget;
    s8 yDirection; // 1: to the bottom, -1: to the top, 0: collinear
    s8 xDirection; // 1: to the right, -1: to the left, 0: collinear
    u16 absDistToHintTarget;
    u16 unk_10; // always 1
    u16 speedMultiplier;
};

struct MapScreenFading {
    u8 stage;
    u8 colorToApply;
    u8 paletteUpdated;
};

struct StatusScreenData {
    u8 unk_0; // set and checked but does nothing
    u8 currentStatusSlot;
    u8 previousLeftStatusSlot;
    u8 previousRightStatusSlot;

    u8 beamActivation[STATUS_SCREEN_BEAM_OFFSET_END];
    u8 suitActivation[STATUS_SCREEN_SUIT_OFFSET_END];
    u8 miscActivation[STATUS_SCREEN_MISC_OFFSET_END];
    u8 bombActivation[STATUS_SCREEN_BOMB_OFFSET_END];
    u8 missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_END];

    u8 padding_15[3];
};

struct BossFlameData {
    u16 yOffset;
    u8 moving;
    u8 oamOffset;
    u8 unk_4; // unused
    s8 movementDirection;
    u8 unk_6; // unused
    u8 unk_7; // unused
    u16 xPosition;
    u16 yPosition;
};

struct PauseScreenEwramData {
    u16 mapTilemaps[MAX_AMOUNT_OF_AREAS][1024];
    u16 easySleepTextFormatted_1[1024];
    u16 easySleepTextFormatted_2[1024];
    u16 unk_5000[1024];
    u16 unk_5800[1024];
    u16 unk_6000[1024];
    u16 originalBackgroundPalette[512];
    u16 backgroundPalette[512];
    u16 statusScreenTilemap[1024];
    u16 unk_7800[1024];
    u16 statusScreenBackgroundTilemap[1024];
    u16 easySleepTilemap[1024];
    u16 visorOverlayTilemap[1024];
    u16 mapScreenOverlayTilemap[1024];
    u16 worldMapOverlayTilemap[1024];
    u16 equipmentNamesGfxBackup[1024];
    u16 unk_b000[1024];
    u16 unk_b800[1024];
    u16 unk_c000[1024];
    u16 unk_c800[1024];
    u16 unk_d000[1024];
};

struct PauseScreenData {
    u16 typeFlags;
    struct PauseScreenSubroutineData subroutineInfo;
    u8 unk_10; // unused

    u8 onWorldMap;
    u8 currentArea;
    u8 mapX;
    u8 mapY;
    u8 hintTargetX;
    u8 hintTargetY;

    u16 unk_18; // timer?
    s8 unk_1A; // index?
    u16 unk_1C; // timer?
    s8 unk_1E; // index?

    struct UnknownItemPalette unknownItemDynamicPalette;
    
    s8 mapViewX;
    s8 mapViewY;
    s8 mapRightBorder;
    s8 mapLeftBorder;
    s8 mapTopBorder;
    s8 mapBottomBorder;
    u8 absoluteMapRightBorder;
    u8 absoluteMapLeftBorder;
    u8 absoluteMapTopBorder;
    u8 absoluteMapBottomBorder;
    u8 canScrollRight;
    u8 canScrollLeft;
    u8 canScrollUp;
    u8 canScrollDown;

    u8 unk_32; // unused
    u8 unk_33; // unused
    u8 unk_34;

    u8 energyTankTotal;
    u8 energyTankCurrent;
    u8 missileTankTotal;
    u8 missileTankCurrent;
    u8 superMissileTankTotal;
    u8 superMissileTankCurrent;
    u8 powerBombTankTotal;
    u8 powerBombTankCurrent;
    u8 tankStatus;

    u8 padding_3E[2];

    struct ChozoHintTarget chozoHintTarget;

    u8 mapDownloadType;
    u8 downloadTimer;
    u8 downloadStage;
    u8 unk_4F;
    u8 currentDownloadedLine;
    u8 downloadLineTrailOamOffsetIndex;

    u8 padding_52[4];

    u8 unk_56;
    u8 currentStatusSlot;
    u8 currentEquipment;

    u8 padding_59[3];

    u16 dispcnt;
    u16 bg0cnt;
    u16 bg1cnt;
    u16 bg2cnt;
    u16 bg3cnt;
    u16 bldcnt;
    u16 targetBldAlpha;

    // TODO: naming
    u16 unk_6A; // bg0 cnt default
    u16 unk_6C; // bg3 cnt always
    u16 unk_6E; // bg cnt, set, never read
    u16 unk_70; // bg0 cnt for PAUSE_SCREEN_TYPE_DOWNLOADING_MAP, bg1 cnt default
    u16 unk_72; // bg2 cnt for !PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM or exiting status screen
    u16 unk_74; // bg2 cnt for PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM or starting status screen
    u16 unk_76; // bg cnt, set, never read
    u16 unk_78; // bg2 cnt, debug?
    u16 unk_7A; // bg cnt, set, never read, debug?

    u8 isFading;
    u8 bldAlphaStepLevel;
    u8 bldAlphaStepTimer; // essesntially always 0
    s8 bldAlphaStepDelayThreshold; // always 0
    u8 targetBldAlpha_L;
    u8 targetBldAlpha_H;

    u8 padding_82[10];

    struct ChozoHintMapData chozoHintMapMovementData;
    struct ChozoHintMapData chozoHintMapScrollingData;

    u8 changingMinimapStage;
    u8 padding_B5[3];

    u8 areasWithVisitedTiles;
    u8 areasWithHints;
    u8 areasViewables;
    u8 areasViewablesTotal;

    struct MapScreenFading mapScreenFading;
    struct StatusScreenData statusScreenData;

    u8 disableDebugMenu;

    u8 padding_D9[16];

    s8 easySleepTextState;
    u8 notPlayingEnablingNormalItemSound;

    struct BossFlameData bossFlameData[2];

    u16 (*mapsDataPointer)[1024];

    struct MenuOamData miscOam[23];
    struct MenuOamData unk_278[7];
    struct MenuOamData targetsOam[12];
    struct MenuOamData chozoHintOam[5];
    struct MenuOamData samusIconOam[1];
    struct MenuOamData bossIconOam[1];
    struct MenuOamData unk_418[1];
    struct MenuOamData overlayOam[4];
    struct MenuOamData borderArrowsOam[4];
    struct MenuOamData worldMapOam[24];
};

#endif /* MAP_SCREEN_MENU_STRUCT_H */
