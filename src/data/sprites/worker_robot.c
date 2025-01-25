#include "data/sprites/worker_robot.h"
#include "macros.h"

const u32 sWorkerRobotGfx[376] = INCBIN_U32("data/sprites/WorkerRobot.gfx.lz");
const u16 sWorkerRobotPal[32] = INCBIN_U16("data/sprites/WorkerRobot.pal");

const u16 sWorkerRobotOAM_Walking_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f7, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_Walking_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fd, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f2, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_Walking_Frame4[OAM_DATA_SIZE(8)] = {
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

const u16 sWorkerRobotOAM_Walking_Frame5[OAM_DATA_SIZE(8)] = {
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

const u16 sWorkerRobotOAM_Walking_Frame6[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1fc, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f6, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x21e
};

const u16 sWorkerRobotOAM_Walking_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x27e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x205
};

const u16 sWorkerRobotOAM_Walking_Frame0[OAM_DATA_SIZE(8)] = {
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

const u16 sWorkerRobotOAM_Walking_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1fa, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f9, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x27e
};

const u16 sWorkerRobotOAM_BackToSleep_Frame0[OAM_DATA_SIZE(8)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame1[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame2[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame3[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame4[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame5[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_BackToSleep_Frame6[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_Sleeping_Frame0[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_UnusedFrame[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_WakingUp_Frame2[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_Standing_Frame1[OAM_DATA_SIZE(9)] = {
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

const u16 sWorkerRobotOAM_GoingToSleep_Frame1[OAM_DATA_SIZE(8)] = {
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
    [0] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_WalkingBackwards[9] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_Standing[2] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_Walking_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_BackToSleep[9] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame3,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [4] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame5,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [6] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOAM_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_Sleeping[2] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_Sleeping_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_GoingToSleep[3] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_GoingToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_TurningAround[3] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_GoingToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOAM_WakingUp[9] = {
    [0] = {
        .pFrame = sWorkerRobotOAM_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sWorkerRobotOAM_Standing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOAM_WakingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame5,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [4] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame3,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [6] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOAM_BackToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};
