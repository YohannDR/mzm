#include "worker_robot.h"
#include "../../data/data.h"
#include "../globals.h"

const u32 sWorkerRobotGFX[376];
const u16 sWorkerRobotPAL[32];

const u16 sWorkerRobotOAM_Walking_Frame2[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f7, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_Walking_Frame3[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fd, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f2, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_Walking_Frame4[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f1, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fd, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f2, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_Walking_Frame5[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1fe, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f4, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_Walking_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1fc, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f6, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_Walking_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x205
};

const u16 sWorkerRobotOAM_Walking_Frame0[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_Walking_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f9, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame0[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe2, 0x1f4, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe2, 0x1f4, OBJ_SPRITE_OAM | 0x235,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame3[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe2, 0x1f4, OBJ_SPRITE_OAM | 0x255,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame4[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe2, 0x1f4, OBJ_SPRITE_OAM | 0x275,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame5[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe3, 0x1f4, OBJ_SPRITE_OAM | 0x1217,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame6[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1f4, OBJ_SPRITE_OAM | 0x1237,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x120c,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x120e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const u16 sWorkerRobotOAM_Sleeping_Frame0[56] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x1f4, OBJ_SPRITE_OAM | 0x1217,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const u16 sWorkerRobotOAM_WakingUp_Frame2[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1f4, OBJ_SPRITE_OAM | 0x1217,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const u16 sWorkerRobotOAM_Standing_Frame1[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xe6, 0x1f4, OBJ_SPRITE_OAM | 0x1257,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1212,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x1214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const u16 sWorkerRobotOAM_GoingToSleep_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1219,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x121b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x127e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, OBJ_SPRITE_OAM | 0x121e
};

const struct FrameData sWorkerRobotOAM_Walking[9] = {
    sWorkerRobotOAM_Walking_Frame0,
    0x8,
    sWorkerRobotOAM_Walking_Frame1,
    0x8,
    sWorkerRobotOAM_Walking_Frame2,
    0x8,
    sWorkerRobotOAM_Walking_Frame3,
    0x8,
    sWorkerRobotOAM_Walking_Frame4,
    0x8,
    sWorkerRobotOAM_Walking_Frame5,
    0x8,
    sWorkerRobotOAM_Walking_Frame6,
    0x8,
    sWorkerRobotOAM_Walking_Frame7,
    0x8,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_WalkingBackwards[9] = {
    sWorkerRobotOAM_Walking_Frame0,
    0x8,
    sWorkerRobotOAM_Walking_Frame7,
    0x8,
    sWorkerRobotOAM_Walking_Frame6,
    0x8,
    sWorkerRobotOAM_Walking_Frame5,
    0x8,
    sWorkerRobotOAM_Walking_Frame4,
    0x8,
    sWorkerRobotOAM_Walking_Frame3,
    0x8,
    sWorkerRobotOAM_Walking_Frame2,
    0x8,
    sWorkerRobotOAM_Walking_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_Standing[2] = {
    sWorkerRobotOAM_Walking_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_BackToSleep[9] = {
    sWorkerRobotOAM_BackToSleep_Frame0,
    0x2,
    sWorkerRobotOAM_BackToSleep_Frame1,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame2,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame3,
    0xF,
    sWorkerRobotOAM_BackToSleep_Frame4,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame5,
    0xF,
    sWorkerRobotOAM_BackToSleep_Frame6,
    0x4,
    sWorkerRobotOAM_Sleeping_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_Sleeping[2] = {
    sWorkerRobotOAM_Sleeping_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_GoingToSleep[3] = {
    sWorkerRobotOAM_Sleeping_Frame0,
    0x4,
    sWorkerRobotOAM_GoingToSleep_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_TurningAround[3] = {
    sWorkerRobotOAM_GoingToSleep_Frame1,
    0x4,
    sWorkerRobotOAM_Sleeping_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sWorkerRobotOAM_WakingUp[9] = {
    sWorkerRobotOAM_Sleeping_Frame0,
    0x2,
    sWorkerRobotOAM_Standing_Frame1,
    0x4,
    sWorkerRobotOAM_WakingUp_Frame2,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame5,
    0xF,
    sWorkerRobotOAM_BackToSleep_Frame4,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame3,
    0xF,
    sWorkerRobotOAM_BackToSleep_Frame2,
    0x4,
    sWorkerRobotOAM_BackToSleep_Frame1,
    0x2,
    NULL,
    0x0
};


u8 WorkerRobotCheckSamusInFront(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteLeft;
    u16 spriteRight;
    u16 samusY;
    u16 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;

    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY - 0xA4;
        spriteLeft = spriteY - 0x48;
        spriteRight = spriteY + 0x48;

        samusY = gSamusData.yPosition;
        samusX = gSamusData.xPosition;
        samusTop = samusY + gSamusPhysics.drawDistanceTopOffset;
        samusBottom = samusY + gSamusPhysics.drawDistanceBottomOffset;
        samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
        samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteY, spriteLeft, spriteRight,
            samusTop, samusBottom, samusLeft, samusRight))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (spriteX < samusX)
                    return TRUE;
            }
            else
            {
                if (spriteX > samusX)
                    return TRUE;
            }
        }
    }
    
    return FALSE;
}

void WorkerRobotInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x74;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x1C;
    gCurrentSprite.hitboxRightOffset = 0x1C;
    gCurrentSprite.drawDistanceTopOffset = 0x28;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.pOam = sWorkerRobotOAM_Sleeping;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    SpriteUtilMakeSpriteFaceAwawFromSamusXFlip();
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
}

void WorkerRobotSleepingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
    gCurrentSprite.pOam = sWorkerRobotOAM_Sleeping;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void WorkerRobotSleeping(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT;
    else if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP_INIT;
}

void WorkerRobotWakingUpInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP;
    gCurrentSprite.pOam = sWorkerRobotOAM_WakingUp;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x26F);
}

void WorkerRobotChecWakingUpAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
}

void WorkerRobotWalkingDetectProjectile(void)
{
    struct ProjectileData* pProj;
    u8 type;
    u8 onSide;
    
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    onSide = FALSE;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
    pProj = gProjectileData;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT)) == (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
        {
            type = pProj->type;
            if ((u8)(type - 0xC) < 0x2)
            {
                projY = pProj->yPosition;
                projX = pProj->xPosition;
                projTop = projY + pProj->hitboxTopOffset;
                projBottom = projY + pProj->hitboxBottomOffset;
                projLeft = projX + pProj->hitboxLeftOffset;
                projRight = projX + pProj->hitboxRightOffset;

                if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                {
                    if (pProj->direction == ACD_FORWARD || ((u8)(pProj->direction - 0x1) < 0x2 && projY > spriteTop && projY < spriteBottom))
                        onSide++;
                    
                    if (onSide)
                    {
                        if (pProj->status & PROJ_STATUS_XFLIP)
                        {
                            projX = spriteLeft;
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            if (!(gCurrentSprite.status & SPRITE_STATUS_XFLIP))
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_WalkingBackwards)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_WalkingBackwards;
                            }
                            else
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_Walking)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
                            }
                        }
                        else
                        {
                            projX = spriteRight;
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_WalkingBackwards)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_WalkingBackwards;
                            }
                            else
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_Walking)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
                            }
                        }
                        gCurrentSprite.animationDurationCounter = 0x0;
                    }

                    if (type == PROJ_TYPE_SUPER_MISSILE)
                    {
                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
                        if (onSide)
                            gCurrentSprite.workVariable = 0x3C;
                    }
                    else
                    {
                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
                        if (onSide)
                            gCurrentSprite.workVariable = 0x1E;
                    }
                    pProj->status = 0x0;
                    break;
                }
            }
        }
    }
}

void WorkerRobotStandingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING;
    gCurrentSprite.pOam = sWorkerRobotOAM_Standing;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.timer = 0x1E;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.hitboxTopOffset = -0x84;
}

void WorkerRobotStanding(void)
{
    WorkerRobotWalkingDetectProjectile();
    if (gCurrentSprite.workVariable != 0x0)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING_INIT;
    }
}

void WorkerRobotWalkingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void WorkerRobotWalking(void)
{

}

void WorkerRobotBackToSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP;
    gCurrentSprite.pOam = sWorkerRobotOAM_BackToSleep;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x270);
}

void WorkerRobotCheckBackToSleepAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = WORKER_ROBOT_POSE_TURNING_AROUND;
        gCurrentSprite.pOam = sWorkerRobotOAM_GoingToSleep;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.hitboxTopOffset = -0x74;
    }
}

void WorkerRobotTurningAround(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
        else
            gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);

        gCurrentSprite.pose = WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED;
        gCurrentSprite.pOam = sWorkerRobotOAM_TurningAround;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void WorkerRobotCheckTurningAroundAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
}

void WorkerRobotFallingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

void WorkerRobotFalling(void)
{

}

void WorkerRobotFallingSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable = 0x0;
}

void WorkerRobotFallingSleep(void)
{

}

void WorkerRobot(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WorkerRobotInit();

        case WORKER_ROBOT_POSE_SLEEPING_INIT:
            WorkerRobotSleepingInit();

        case WORKER_ROBOT_POSE_SLEEPING:
            WorkerRobotSleeping();
            break;

        case WORKER_ROBOT_POSE_WAKING_UP_INIT:
            WorkerRobotWakingUpInit();

        case WORKER_ROBOT_POSE_WAKING_UP:
            WorkerRobotChecWakingUpAnimEnded();
            break;

        case WORKER_ROBOT_POSE_STANDING_INIT:
            WorkerRobotStandingInit();

        case WORKER_ROBOT_POSE_STANDING:
            WorkerRobotStanding();
            break;

        case WORKER_ROBOT_POSE_WALKING_INIT:
            WorkerRobotWalkingInit();

        case WORKER_ROBOT_POSE_WALKING:
            WorkerRobotWalking();
            break;

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT:
            WorkerRobotBackToSleepInit();

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP:
            WorkerRobotCheckBackToSleepAnimEnded();
            break;

        case WORKER_ROBOT_POSE_TURNING_AROUND:
            WorkerRobotTurningAround();

        case WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED:
            WorkerRobotCheckTurningAroundAnimEnded();
            break;

        case WORKER_ROBOT_POSE_FALLING_INIT:
            WorkerRobotFallingInit();

        case WORKER_ROBOT_POSE_FALLING:
            WorkerRobotFalling();
            break;

        case WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT:
            WorkerRobotFallingSleepInit();
            break;

        case WORKER_ROBOT_POSE_FALLING_SLEEPING:
            WorkerRobotFallingSleep();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x46, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}