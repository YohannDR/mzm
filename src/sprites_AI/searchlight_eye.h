#ifndef SEARCHLIGHT_EYE_AI_H
#define SEARCHLIGHT_EYE_AI_H

#include "../types.h"

void searchlight_eye_init(void);
void searchlight_eye_move(void);
void searchlight_eye_check_alarm(void);
void searchlight_eye_check_alerted_anim_ended(void);
void searchlight_eye_check_should_shot(void);
void searchlight_eye_shoot(void);
void searchlight_eye_beam_init(void);
void searchlight_eye_beam_detect_samus(void);
void searchlight_eye_beam_disappear(void);
void searchlight_eye(void);
void searchlight_eye_beam(void);
void searchlight_eye_projectile(void);

#endif /* SEARCHLIGHT_EYE_AI_H */