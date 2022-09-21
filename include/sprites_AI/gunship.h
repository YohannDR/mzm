#ifndef GUNSHIP_AI_H
#define GUNSHIP_AI_H

#include "types.h"

#define GUNSHIP_POSE_IDLE 0x9
#define GUNSHIP_POSE_CHECK_ESCAPE 0xF
#define GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING 0x11
#define GUNSHIP_POSE_START_ESCAPING 0x13
#define GUNSHIP_POSE_TAKING_OFF 0x15
#define GUNSHIP_POSE_FLYING 0x17
#define GUNSHIP_POSE_DO_NOTHING_ESCAPE 0x19
#define GUNSHIP_POSE_SAMUS_ENTERING 0x22
#define GUNSHIP_POSE_REFILL 0x23
#define GUNSHIP_POSE_AFTER_REFILL 0x24
#define GUNSHIP_POSE_SAMUS_LEAVE 0x25
#define GUNSHIP_POSE_SAMUS_LEAVING 0x27
#define GUNSHIP_POSE_RELEASE_SAMUS 0x28
#define GUNSHIP_POSE_SAMUS_RELEASED 0x29
#define GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED 0x2A
#define GUNSHIP_POSE_SAVING 0x42
#define GUNSHIP_POSE_AFTER_SAVE 0x43
#define GUNSHIP_POSE_LANDING 0x55
#define GUNSHIP_POSE_UNKNOWN 0x57
#define GUNSHIP_POSE_DO_NOTHING 0x59

// Gunship part

#define GUNSHIP_PART_ENTRANCE_FRONT 0x1
#define GUNSHIP_PART_ENTRANCE_BACK 0x2
#define GUNSHIP_PART_PLATFORM 0x3
#define GUNSHIP_PART_FLAMES_HORIZONTAL 0x4
#define GUNSHIP_PART_FLAMES_VERTICAL 0x5

#define GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE 0x8
#define GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING 0x9
#define GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE 0xE
#define GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING 0xF
#define GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES 0x32
#define GUNSHIP_PART_POSE_VERTICAL_FLAME_IDLE 0x33
#define GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES 0x34
#define GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING 0x35
#define GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING 0x36
#define GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED 0x37
#define GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP 0x42
#define GUNSHIP_PART_POSE_PLATFORM_GO_UP 0x43
#define GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN 0x44
#define GUNSHIP_PART_POSE_PLATFORM_GO_DOWN 0x45

void GunshipFlickerFlames(void);
void GunshipEntranceFlashingAnim(void);
u8 GunshipCheckSamusEnter(void);
void GunshipInit(void);
void GunshipLanding(void);
void GunshipIdle(void);
void GunshipSamusEntering(void);
void GunshipRefill(void);
void GunshipAfterRefill(void);
void GunshipSaving(void);
void GunshipAfterSave(void);
void GunshipSamusLeave(void);
void GunshipSamusLeaving(void);
void GunshipReleaseSamus(void);
void GunshipSamusReleased(void);
void GunshipCheckSamusOnTopAfterLeaving(void);
void GunshipCheckEscapeZebes(void);
void GunshipSamusEnteringWhenEscaping(void);
void GunshipStartEscaping(void);
void GunshipTakingOff(void);
void GunshipFlying(void);
void GunshipPartInit(void);
void GunshipPartCheckSetVerticalFlames(void);
void GunshipPartCheckSetHorizontalFlames(void);
void GunshipPartCheckSetVerticalFlamesBeforeLanding(void);
void GunshipPartCheckLandingEnded(void);
void GunshipPartFlickFlames_Unused(void);
void GunshipPartEntranceFrontIdle(void);
void GunshipPartEntranceFrontOpenClose(void);
void GunshipPartEntranceBackIdle(void);
void GunshipPartEntranceBackOpenClose(void);
void GunshipPartCheckPlatformGoUp(void);
void GunshipPartPlatformGoUp(void);
void GunshipPartCheckPlatformGoDown(void);
void GunshipPartPlatformGoDown(void);
void Gunship(void);
void GunshipPart(void);

#endif /* GUNSHIP_AI_H */