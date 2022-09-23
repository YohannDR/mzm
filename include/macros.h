#define behavior_to_block(behavior) (behavior - 0x10)
#define behavior_to_tank(behavior) (behavior - 0x34)
#define behavior_to_bldalpha(behavior) (behavior - 0x44)
#define behavior_to_door(behavior) (behavior - 0x7F)

#define bomb_chain_type_to_flag(type) (1 << type)