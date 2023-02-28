#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"

void DMATransfer(u8 channel, void *src, void *dst, u32 len, u8 bitSize);
void init_sound(void);
void read_sram(void);
void start_new_demo(void);
int softreset_main(void);
int fileselect_main(void);
int map_screen_main(void);
int gameover_main(void);
int chozodia_escape_main(void);
int credits_main(void);
int tourian_escape_main(void);
int cutscene_main(void);
int gallery_main(void);
int fusion_gallery_main(void);

void unk_33dc(void);
void QueueSound(u16 id, u32 unk); /* TODO: unk type */
void StopOrFadeSound(u16 id, u32 unk); /* TODO: unk type */
void UpdateAudio();
void sub_0805d034(void);

#endif /* FUNCS_H */
