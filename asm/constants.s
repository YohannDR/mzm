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
