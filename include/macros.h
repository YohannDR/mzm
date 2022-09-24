#define behavior_to_block(behavior) (behavior - 0x10)
#define behavior_to_tank(behavior) (behavior - 0x34)
#define behavior_to_bldalpha(behavior) (behavior - 0x44)
#define behavior_to_door(behavior) (behavior - 0x7F)

#define bomb_chain_type_to_flag(type) (1 << type)

#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN