#ifndef MAP_SCREEN_MENU_STRUCT_H
#define MAP_SCREEN_MENU_STRUCT_H

#include "types.h"
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
    u16 unk_A;
    u16 unk_C;
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
    i8 xOffset1;
    i8 yOffset1;

    u8 area2;
    u8 mapX2;
    u8 mapY2;
    i8 xOffset2;
    i8 yOffset2;
};

struct PauseScreenSubroutineData {
    u8 currentSubroutine;
    u8 padding_1[3];
    u8 stage;
    u16 timer;
    u8 unk_8;
    u16 unk_A;
};

struct UnknownItemPalette {
    u16 timer;
    i8 paletteRow;
    u8 flashingNumber;
};

struct ChozoHintRelated {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    i16 unk_8;
    i16 unk_A;
    i8 unk_C;
    i8 unk_D;
    u16 unk_E;
    u16 unk_10;
    u16 unk_12;
};

struct MapScreenFading {
    u8 stage;
    u8 colorToApply;
    u8 unk_2;
};

struct StatusScreenData {
    u8 unk_0;
    u8 currentStatusSlot;
    u8 previousLeftStatusSlot;
    u8 previousRightStatusSlot;

    u8 beamActivation[5];
    u8 suitActivation[2];
    u8 miscActivation[6];
    u8 bombActivation[2];
    u8 missilesActivation[2];

    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
};

struct BossFlameData {
    u16 yOffset;
    u8 moving;
    u8 oamOffset;
    u8 unk_4;
    i8 movementDirection;
    u8 unk_6;
    u8 unk_7;
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
    u16 unk_6800[512];
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
    u8 unk_10;

    u8 onWorldMap;
    u8 currentArea;
    u8 mapX;
    u8 mapY;
    u8 hintTargetX;
    u8 hintTargetY;

    u16 unk_18;
    i8 unk_1A;
    u16 unk_1C;
    u8 unk_1E;

    struct UnknownItemPalette unknownItemDynamicPalette;
    
    i8 mapViewX;
    i8 mapViewY;
    i8 mapRightBorder;
    i8 mapLeftBorder;
    i8 mapTopBorder;
    i8 mapBottomBorder;
    u8 absoluteMapRightBorder;
    u8 absoluteMapLeftBorder;
    u8 absoluteMapTopBorder;
    u8 absoluteMapBottomBorder;
    u8 canScrollRight;
    u8 canScrollLeft;
    u8 canScrollUp;
    u8 canScrollDown;

    u8 unk_32;
    u8 unk_33;
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

    i8 unk_40;
    u8 unk_41;
    i8 unk_42;
    u16 activatedTargets;
    u8 unk_46;
    u8 unk_47;
    u8 unk_48;
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;

    u8 mapDownloadType;
    u8 downloadTimer;
    u8 downloadStage;
    u8 unk_4F;
    u8 currentDownloadedLine;
    u8 unk_51;

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

    u16 unk_68;
    u16 unk_6A;
    u16 unk_6C;
    u16 unk_6E;
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
    u16 unk_76;
    u16 unk_78;
    u16 unk_7A;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    i8 unk_7F;
    u8 unk_80;
    u8 unk_81;

    u8 padding_82[10];

    struct ChozoHintRelated unk_8C[2];

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

    i8 easySleepTextState;
    u8 unk_EA;

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
