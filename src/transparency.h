#ifndef TRANSPARENCY_H
#define TRANSPARENCY_H

#include "types.h"

struct bldalpha_data {
    u16 maybe_bldcnt;
    u8 unk;
    u8 eva;
    u8 evb;
    u8 unk2;
    u8 unk3;
    u8 fading_related;
};

struct bldcnt_data {
    u16 unk;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
};

void transparency_set_room_effects_and_transparency(void);
u16 transparency_get_bg_size_flag(u8 size);
u16 transparency_check_is_dark_room(void);
void transparency_update_bldcnt(u8 action, u16 value);
void unk_55adc(u8 unk, u8 unk2, u8 unk3);
void unk_55b24(u8 eva, u8 evb, u8 unk, u8 fading_related);
void unk_55b9c(u8 unk, u8 unk2, u8 unk3);
void transparency_update_bldalpha(u8 eva, u8 evb, u8 unk, u8 fading_related);
void transparency_apply_new_effects(void);
void transparency_apply_new_bldalpha(struct bldalpha_data* pBldalpha);
void transparency_apply_new_bldcnt(struct bldcnt_data* pBldcnt);
void unk_55e60(void);
void unk_55f68(void);

#endif /* TRANSPARENCY_H */