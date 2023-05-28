#include "data/sprites/worker_robot.h"
#include "macros.h"

const u32 sWorkerRobotGfx[376] = INCBIN_U32("data/sprites/WorkerRobot.gfx.lz");
const u16 sWorkerRobotPAL[32] = INCBIN_U16("data/sprites/WorkerRobot.pal");

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

const u16 sWorkerRobotOAM_Sleeping_Frame0[28] = {
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

const u16 sWorkerRobotOAM_UnusedFrame[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xea, 0x1f4, OBJ_SPRITE_OAM | 0x1217,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x1202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x125e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f7, OBJ_SPRITE_OAM | 0x121e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x127e,
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
