#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

struct BrokenBlock {
    u8 broken;
    u8 stage;
    u8 type;
    u8 x_position;
    u8 y_position;
    u16 timer;
};

struct ClipdataBlockData {
    u16 x_position;
    u16 y_position;
    u16 behavior;
    u8 block_behavior;
};

u8 block_check_ccaa(struct ClipdataBlockData* pClipBlock);
u8 block_destroy_non_reform_block(struct ClipdataBlockData* pClipBlock);
u8 block_destroy_bomb_chain_block(struct ClipdataBlockData* pClipBlock);
u8 block_destroy_single_breakable_block(struct ClipdataBlockData* pClipBlock);
u8 block_destroy_square_block(struct ClipdataBlockData* pClipBlock);
u8 block_store_single_never_reform_block(u16 x_position, u16 y_position);
void block_remove_never_reform_blocks(void);
void block_remove_never_reform_single_block(void);
void block_shift_never_reform_blocks(void);
u8 block_check_reveal_or_destroy_non_bomb_block(struct ClipdataBlockData* pClipBlock);
u8 block_check_reveal_or_destroy_bomb_block(struct ClipdataBlockData* pClipBlock);
u8 block_apply_ccaa(u16 y_position, u16 x_position, u16 true_clip);
u8 block_update_make_solid_blocks(u8 make_solid, u16 x_position, u16 y_position);
u8 block_samus_apply_screw_speedbooster_damage_to_environment(u16 x_position, u16 y_position, u8 action);
void block_update_broken_blocks(void);
void block_update_borken_block_animation(struct BrokenBlock* pBlock);
u8 block_store_broken_reform_block(u8 type, u16 x_position, u16 y_position, u8 stop_samus);
u8 block_store_broken_non_reform_block(u16 x_position, u16 y_position, u8 type);
u8 block_check_reveal_bomb_chain_block(u8 type, u16 x_position, u16 y_position);
u8 block_check_samus_in_reforming_block(u8 x_position, u8 y_position);
u8 block_start_bomb_chain(u8 type, u16 x_position, u16 y_position);
void block_process_bomb_chain(void);
void block_check_start_new_sub_bomb_chain(u8 type, u8 x_position, u8 y_position);
void block_broken_block_reform_remove_collision(u16 y_position, u16 x_position);

#endif /* BLOCK_H */