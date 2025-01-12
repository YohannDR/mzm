#ifndef MOTHER_BRAIN_CLOSE_UP_CUTSCENE
#define MOTHER_BRAIN_CLOSE_UP_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

enum MotherBrainCloseUpOamId {
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_BUBBLE = 1,
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_UNUSED_EYE,
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENING,
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_ELEVATOR_ANIMATION,
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENED,
    MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_FOCUSING,

    MOTHER_BRAIN_CLOSE_UP_OAM_ID_END
};

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
