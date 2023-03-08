#define BEHAVIOR_TO_BLOCK(behavior) (behavior - 0x10)
#define BEHAVIOR_TO_TANK(behavior) (behavior - 0x34)
#define BEHAVIOR_TO_HAZARD(behavior) (behavior - 0x40)
#define BEHAVIOR_TO_BLDALPHA(behavior) (behavior - 0x44)
#define BEHAVIOR_TO_GROUND_EFFECT(behavior) (behavior - 0x50)
#define BEHAVIOR_TO_DOOR(behavior) (behavior - 0x7F)

#define bomb_chain_type_to_flag(type) (1 << type)

#define check_samus_turning() ((pData->direction ^ (KEY_RIGHT | KEY_LEFT)) & gButtonInput)
#define ARRAY_SIZE(a) ((int)(sizeof((a)) / sizeof((a)[0])))
#define OFFSET_OF(type, element) ((int)&(((type *)0)->element))

#define STATIC_ASSERT(expr, id) typedef char id[(expr) ? 1 : -1];

#define RED(c) ((c) & COLOR_MASK)
#define GREEN(c) (((c) & (COLOR_MASK << 5)) >> 5)
#define BLUE(c) do{b=((c) & (COLOR_MASK << 10)) >> 10;}while(0)
#define COLOR(r, g, b) (((b) << 10) | ((g) << 5) | (r))
#define COLOR_WHITE COLOR(0x1F, 0x1F, 0x1F)
#define COLOR_BLACK COLOR(0x0, 0x0, 0x0)
#define COLOR_MASK 0x1F

#define PI 128
#define sin(a) (sSineTable[(a)])
#define cos(a) (sSineTable[(a) + PI / 2])

#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN

#define FORCE_RODATA __attribute__((section(".rodata")))
