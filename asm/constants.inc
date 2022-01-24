    .set PSR_USR_MODE,  0x00000010
    .set PSR_FIQ_MODE,  0x00000011
    .set PSR_IRQ_MODE,  0x00000012
    .set PSR_SVC_MODE,  0x00000013
    .set PSR_ABT_MODE,  0x00000017
    .set PSR_UND_MODE,  0x0000001b
    .set PSR_SYS_MODE,  0x0000001f
    .set PSR_MODE_MASK, 0x0000001f
    .set PSR_T_BIT,     0x00000020
    .set PSR_F_BIT,     0x00000040
    .set PSR_I_BIT,     0x00000080

    .set REG_BASE,              0x04000000
    .set REG_SOUNDCNT_X_OFFSET, 0x00000084
    .set REG_KEY_INPUT_OFFSET,  0x00000130
    .set REG_IE_OFFSET,         0x00000200
    .set REG_IF_OFFSET,         0x00000202
    .set REG_IME_OFFSET,        0x00000208

    .set REG_SOUNDCNT_X, (REG_BASE + REG_SOUNDCNT_X_OFFSET)
    .set REG_KEY_INPUT,  (REG_BASE + REG_KEY_INPUT_OFFSET)
    .set REG_IE,         (REG_BASE + REG_IE_OFFSET)
    .set REG_IF,         (REG_BASE + REG_IF_OFFSET)
    .set REG_IME,        (REG_BASE + REG_IME_OFFSET)

    .set INTR_FLAG_VBLANK,  1 << 0
    .set INTR_FLAG_HBLANK,  1 << 1
    .set INTR_FLAG_VCOUNT,  1 << 2
    .set INTR_FLAG_TIMER0,  1 << 3
    .set INTR_FLAG_TIMER1,  1 << 4
    .set INTR_FLAG_TIMER2,  1 << 5
    .set INTR_FLAG_TIMER3,  1 << 6
    .set INTR_FLAG_SERIAL,  1 << 7
    .set INTR_FLAG_DMA0,    1 << 8
    .set INTR_FLAG_DMA1,    1 << 9
    .set INTR_FLAG_DMA2,    1 << 10
    .set INTR_FLAG_DMA3,    1 << 11
    .set INTR_FLAG_KEYPAD,  1 << 12
    .set INTR_FLAG_GAMEPAK, 1 << 13

    .set KEY_A,        1 << 0
    .set KEY_B,        1 << 1
    .set KEY_SELECT,   1 << 2
    .set KEY_START,    1 << 3
    .set KEY_RIGHT,    1 << 4
    .set KEY_LEFT,     1 << 5
    .set KEY_UP,       1 << 6
    .set KEY_DOWN,     1 << 7
    .set KEY_RTRIGGER, 1 << 8
    .set KEY_LTRIGGER, 1 << 9
    .set KEY_MASK,     0x3ff

    .set SYSCALL_SoftReset,            0
    .set SYSCALL_RegisterRamReset,     1
    .set SYSCALL_Halt,                 2
    .set SYSCALL_Stop,                 3
    .set SYSCALL_IntrWait,             4
    .set SYSCALL_VBlankIntrWait,       5
    .set SYSCALL_Div,                  6
    .set SYSCALL_DivArm,               7
    .set SYSCALL_Sqrt,                 8
    .set SYSCALL_ArcTan,               9
    .set SYSCALL_ArcTan2,              10
    .set SYSCALL_CPUSet,               11
    .set SYSCALL_CPUSetFast,           12
    .set SYSCALL_BiosChecksum,         13
    .set SYSCALL_BgAffineSet,          14
    .set SYSCALL_ObjAffineSet,         15
    .set SYSCALL_BitUnPack,            16
    .set SYSCALL_LZ77UnCompWRAM,       17
    .set SYSCALL_LZ77UnCompVRAM,       18
    .set SYSCALL_HuffUnComp,           19
    .set SYSCALL_LRUnCompWRAM,         20
    .set SYSCALL_LRUnCompVRAM,         21
    .set SYSCALL_Diff8bitUnFilterWRAM, 22
    .set SYSCALL_Diff8bitUnFilterVRAM, 23
    .set SYSCALL_Diff16bitUnFilter,    24
    .set SYSCALL_SoundBiasChange,      25
    .set SYSCALL_SoundDriverInit,      26
    .set SYSCALL_SoundDriverMode,      27
    .set SYSCALL_SoundDriverMain,      28
    .set SYSCALL_SoundDriverVSync,     29
    .set SYSCALL_SoundChannelClear,    30
    .set SYSCALL_MIDIKey2Freq,         31
    .set SYSCALL_MusicPlayerOpen,      32
    .set SYSCALL_MusicPlayerStart,     33
    .set SYSCALL_MusicPlayerStop,      34
    .set SYSCALL_MusicPlayerContinue,  35
    .set SYSCALL_MusicPlayerFadeOut,   36
    .set SYSCALL_MultiBoot,            37
    .set SYSCALL_HardReset,            38
    .set SYSCALL_CustomHalt,           39
    .set SYSCALL_SoundDriverVSyncOff,  40
    .set SYSCALL_SoundDriverVSyncOn,   41
    .set SYSCALL_GetJumpList,          42

    .set GAMEMODE_SOFTRESET,       0x00
    .set GAMEMODE_INTRO,           0x01
    .set GAMEMODE_TITLE,           0x02
    .set GAMEMODE_FILESELECT,      0x03
    .set GAMEMODE_INGAME,          0x04
    .set GAMEMODE_MAP_SCREEN,      0x05
    .set GAMEMODE_GAMEOVER,        0x06
    .set GAMEMODE_CHOZODIA_ESCAPE, 0x07
    .set GAMEMODE_CREDITS,         0x08
    .set GAMEMODE_TOURIAN_ESCAPE,  0x09
    .set GAMEMODE_CUTSCENE,        0x0a
    .set GAMEMODE_DEMO,            0x0b
    .set GAMEMODE_GALLERY,         0x0c
    .set GAMEMODE_FUSION_GALLERY,  0x0d
    .set GAMEMODE_START_SOFTRESET, 0x0e @ probably
    .set GAMEMODE_ERASE_SRAM,      0x0f
    .set GAMEMODE_DEBUG_MENU,      0x10
