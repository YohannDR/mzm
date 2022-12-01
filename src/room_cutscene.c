#include "types.h"
#include "gba.h"

#include "transparency.h"
#include "room.h"
#include "scroll.h"
#include "connection.h"

#include "structs/bg_clip.h"
#include "structs/display.h"

void LoadRoomCutscene(u8 area, u8 room, u16 bgX, u16 bgY)
{
    gBG0XPosition = bgX;
    gBG0YPosition = bgY;
    gBG1XPosition = bgX;
    gBG1YPosition = bgY;
    gBG2XPosition = bgX;
    gBG2YPosition = bgY;

    gCurrentArea = area;
    gCurrentRoom = room - 1;

    RoomLoadEntry();
    RoomLoadTileset();
    RoomLoadBackgrounds();
    RoomRemoveNeverReformBlocksAndCollectedTanks();
    TransparencySetRoomEffectsTransparency();
    ScrollBG3();
    check_play_lightning_effect(); // Undefined
    RoomUpdateBackgroundsPosition();
    ConnectionLoadDoors();
    ConnectionCheckHatchLockEvents();

    RoomSetInitialTilemap(0);
    RoomSetInitialTilemap(1);
    RoomSetInitialTilemap(2);

    load_animated_graphics(); // Undefined

    DMATransfer(3, EWRAM_BASE + 0x7000, VRAM_BASE + 0x3000, 0x1000, 0x10);

    write16(REG_BG0CNT, gIORegistersBackup.BG0CNT);
    write16(REG_BG3CNT, gIORegistersBackup.BG3CNT);
}
