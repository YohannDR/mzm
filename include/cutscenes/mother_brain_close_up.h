#ifndef MOTHER_BRAIN_CLOSE_UP_CUTSCENE
#define MOTHER_BRAIN_CLOSE_UP_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_BUBBLE 1
#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_UNUSED_EYE 2
#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENING 3
#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_ELEVATOR_ANIMATION 4
#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENED 5
#define MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_FOCUSING 6

u8 MotherBrainCloseUpLookingAtSamus(void);
void MotherBrainCloseUpUpdateElevatorReflection(struct CutsceneOamData* pOam);
u8 MotherBrainCloseUpEyeOpening(void);
u8 MotherBrainCloseUpTankView(void);
u8 MotherBrainCloseUpInit(void);
u8 MotherBrainCloseUpSubroutine(void);
void MotherBrainCloseUpProcessOAM(void);
void MotherBrainCloseUpUpdateEye(u8 lookingAtSamus);
void MotherBrainCloseUpUpdateBubble(struct CutsceneOamData* pOam);
u8 MotherBrainCloseUpInitBubbles(u8 packId);

#endif /* MOTHER_BRAIN_CLOSE_UP_CUTSCENE */
