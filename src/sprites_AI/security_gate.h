#ifndef SECURITY_GATE_AI_H
#define SECURITY_GATE_AI_H

#include "../types.h"
#include "../clipdata.h"

void security_gate_change_ccaa(enum current_clipdata_affecting_action caa);
void security_gate_open(void);
void security_gate_start_closing(void);
void security_gate_default_open_init(void);
void security_gate_default_open_check_alarm(void);
void security_gate_check_closing_anim_ended(void);
void security_gate_default_open_open_after_alarm(void);
void security_gate_check_opening_anim_ended(void);
void security_gate_death(void);
void security_gate_default_closed_init(void);
void security_gate_default_closed_check_alarm(void);
void security_gate_default_closed_close_after_alarm(void);
void security_gate_default_open(void);
void security_gate_default_closed(void);

#endif /* SECURITY_GATE_AI_H */