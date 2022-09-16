#ifndef UNKNOWN_ITEM_CHOZO_STATUE_AI_H
#define UNKNOWN_ITEM_CHOZO_STATUE_AI_H

#include "../types.h"

extern const struct FrameData sUnknownItemChozoStatuePartOAM_LegStanding[2];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_LegSitting[10];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_LegSeated[2];
extern const struct FrameData sUnknownItemChozoStatueOAM_Idle[2];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_EyeOpened[2];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_EyeClosing[3];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_EyeOpening[3];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_EyeClosed[2];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_ArmIdle[2];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_ArmGlow[9];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_ArmSamusGrabbed[2];
extern const struct FrameData sChozoBallOAM_UnknownClosed[5];
extern const struct FrameData sChozoBallOAM_UnknownRevealing[4];
extern const struct FrameData sChozoBallOAM_UnknownRevealed[5];
extern const struct FrameData sUnknownItemChozoStatueRefillOAM[41];
extern const struct FrameData sUnknownItemChozoStatuePartOAM_GlowIdle[41];

void UnknownItemChozoStatueSyncSubSprites(void);
void UnknownItemChozoStatueInit(void);
void UnknownItemChozoStatue_Empty(void);
void UnknownItemChozoStatueRegisterHint(void);
void UnknownItemChozoStatueHintFlashing(void);
void UnknownItemChozoStatueSittingInit(void);
void UnknownItemChozoStatueSitting(void);
void UnknownItemChozoStatueDelayBeforeRefillAfterHint(void);
void UnknownItemChozoStatueWaitForItemToBeCollected(void);
void UnknownItemChozoStatueTimerAfterItemGrabbed(void);
void UnknownItemChozoStatueRefillInit(void);
void UnknownItemChozoStatueRefillSamus(void);
void UnknownItemChozoStatueSleepingInit(void);
void UnknownItemChozoStatueSleeping(void);
void UnknownItemChozoStatuePartInit(void);
void UnknownItemChozoStatuePartGlowIdle(void);
void UnknownItemChozoStatuePartArmCheckGrabSamusHint(void);
void UnknownItemChozoStatuePartSyncSamus(void);
void UnknownItemChozoStatuePartArmSitting(void);
void UnknownItemChozoStatuePartArmSeated(void);
void UnknownItemChozoStatuePartArmCheckGrabSamusRefill(void);
void UnknownItemChozoStatuePartArmRefill(void);
void UnknownItemChozoStatuePart_Empty(void);
void UnknownItemChozoStatuePartSleepingInit(void);
void UnknownItemChozoStatuePartArmSleeping(void);
void UnknownItemChozoStatuePartEyeOpeningInit(void);
void UnknownItemChozoStatuePartEyeOpening(void);
void UnknownItemChozoStatuePartEyeClosingInit(void);
void UnknownItemChozoStatuePartEyeClosing(void);
void UnknownItemChozoStatuePartLegIdle(void);
void UnknownItemChozoStatue(void);
void UnknownItemChozoStatuePart(void);
void UnknownItemChozoStatueRefill(void);
void ChozoStatueStandingChangeCCAA(u8 bodyCaa, u8 handCaa);
void ChozoStatueSeatedChangeCCAA(u8 caa);

#endif /* UNKNOWN_ITEM_CHOZO_STATUE_AI_H */