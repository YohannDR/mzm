#ifndef CONSTANTS_H
#define CONSTANTS_H

#define REG_BASE              0x04000000
#define REG_SOUNDCNT_X_OFFSET 0x00000084
#define REG_KEY_INPUT_OFFSET  0x00000130
#define REG_IE_OFFSET         0x00000200
#define REG_IF_OFFSET         0x00000202
#define REG_IME_OFFSET        0x00000208

#define REG_SOUNDCNT_X (REG_BASE + REG_SOUNDCNT_X_OFFSET)
#define REG_KEY_INPUT  (REG_BASE + REG_KEY_INPUT_OFFSET)
#define REG_IE         (REG_BASE + REG_IE_OFFSET)
#define REG_IF         (REG_BASE + REG_IF_OFFSET)
#define REG_IME        (REG_BASE + REG_IME_OFFSET)

#define KEY_A        (1 << 0)
#define KEY_B        (1 << 1)
#define KEY_SELECT   (1 << 2)
#define KEY_START    (1 << 3)
#define KEY_RIGHT    (1 << 4)
#define KEY_LEFT     (1 << 5)
#define KEY_UP       (1 << 6)
#define KEY_DOWN     (1 << 7)
#define KEY_RTRIGGER (1 << 8)
#define KEY_LTRIGGER (1 << 9)
#define KEY_MASK     0x3ff

#define GAMEMODE_SOFTRESET       0x00
#define GAMEMODE_INTRO           0x01
#define GAMEMODE_TITLE           0x02
#define GAMEMODE_FILESELECT      0x03
#define GAMEMODE_INGAME          0x04
#define GAMEMODE_MAP_SCREEN      0x05
#define GAMEMODE_GAMEOVER        0x06
#define GAMEMODE_CHOZODIA_ESCAPE 0x07
#define GAMEMODE_CREDITS         0x08
#define GAMEMODE_TOURIAN_ESCAPE  0x09
#define GAMEMODE_CUTSCENE        0x0a
#define GAMEMODE_DEMO            0x0b
#define GAMEMODE_GALLERY         0x0c
#define GAMEMODE_FUSION_GALLERY  0x0d
#define GAMEMODE_START_SOFTRESET 0x0e // probably
#define GAMEMODE_ERASE_SRAM      0x0f
#define GAMEMODE_DEBUG_MENU      0x10

#endif /* CONSTANTS_H */
