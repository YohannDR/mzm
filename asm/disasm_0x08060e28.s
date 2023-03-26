    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start return_one
return_one: @ 0x08060e28
    movs r0, #1
    bx lr

    thumb_func_start tourian_escape_main
tourian_escape_main: @ 0x08060e2c
    push {r4, r5, lr}
    movs r4, #0
    ldr r1, lbl_08060e94 @ =0x0875fe3c
    ldr r5, lbl_08060e98 @ =gTourianEscapeCutsceneStage
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08060e60
    movs r0, #0xa0
    lsls r0, r0, #0x13
    movs r1, #0
    strh r4, [r0]
    ldr r0, lbl_08060e9c @ =gSubGameModeStage
    strb r1, [r0]
    ldr r0, lbl_08060ea0 @ =gGameModeSub1
    strh r4, [r0]
    ldr r1, lbl_08060ea4 @ =gGameModeSub2
    movs r0, #4
    strb r0, [r1]
    movs r4, #1
lbl_08060e60:
    cmp r4, #0
    beq lbl_08060eb8
    movs r0, #0
    ldrsb r0, [r5, r0]
    cmp r0, #1
    bne lbl_08060e8e
    movs r0, #2
    bl ColorFadingStart
    ldr r1, lbl_08060ea8 @ =gCurrentArea
    movs r0, #6
    strb r0, [r1]
    ldr r0, lbl_08060eac @ =gCurrentRoom
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08060eb0 @ =gLastDoorUsed
    strb r1, [r0]
    ldr r1, lbl_08060eb4 @ =gCurrentCutscene
    movs r0, #3
    strb r0, [r1]
    ldr r1, lbl_08060ea4 @ =gGameModeSub2
    movs r0, #0xa
    strb r0, [r1]
lbl_08060e8e:
    movs r0, #1
    b lbl_08060eba
    .align 2, 0
lbl_08060e94: .4byte 0x0875fe3c
lbl_08060e98: .4byte gTourianEscapeCutsceneStage
lbl_08060e9c: .4byte gSubGameModeStage
lbl_08060ea0: .4byte gGameModeSub1
lbl_08060ea4: .4byte gGameModeSub2
lbl_08060ea8: .4byte gCurrentArea
lbl_08060eac: .4byte gCurrentRoom
lbl_08060eb0: .4byte gLastDoorUsed
lbl_08060eb4: .4byte gCurrentCutscene
lbl_08060eb8:
    movs r0, #0
lbl_08060eba:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08060ec0
sub_08060ec0: @ 0x08060ec0
    push {lr}
    ldr r0, lbl_08060ed4 @ =gCurrentCutscene
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    beq lbl_08060ed8
    cmp r0, #9
    beq lbl_08060ee2
    b lbl_08060eea
    .align 2, 0
lbl_08060ed4: .4byte gCurrentCutscene
lbl_08060ed8:
    movs r0, #0x34
    movs r1, #0
    bl PlayMusic
    b lbl_08060eea
lbl_08060ee2:
    movs r0, #0x93
    lsls r0, r0, #2
    bl SoundPlay
lbl_08060eea:
    movs r0, #0xa
    bl FadeAllSounds
    pop {r0}
    bx r0

    thumb_func_start end_cutscene
end_cutscene: @ 0x08060ef4
    push {r4, r5, lr}
    ldr r0, lbl_08060f10 @ =gCurrentCutscene
    ldrb r0, [r0]
    subs r0, #1
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xb
    bhi lbl_08060fda
    lsls r0, r0, #2
    ldr r1, lbl_08060f14 @ =lbl_08060f18
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08060f10: .4byte gCurrentCutscene
lbl_08060f14: .4byte lbl_08060f18
lbl_08060f18: @ jump table
    .4byte lbl_08060f5c @ case 0
    .4byte lbl_08060fda @ case 1
    .4byte lbl_08060f94 @ case 2
    .4byte lbl_08060fda @ case 3
    .4byte lbl_08060fda @ case 4
    .4byte lbl_08060fac @ case 5
    .4byte lbl_08060fda @ case 6
    .4byte lbl_08060f48 @ case 7
    .4byte lbl_08060fda @ case 8
    .4byte lbl_08060fda @ case 9
    .4byte lbl_08060fda @ case 10
    .4byte lbl_08060f88 @ case 11
lbl_08060f48:
    ldr r0, lbl_08060f58 @ =0x0836bdac
    adds r0, #0x7d
    ldrb r1, [r0]
    movs r0, #1
    bl EventFunction
    b lbl_08060fda
    .align 2, 0
lbl_08060f58: .4byte 0x0836bdac
lbl_08060f5c:
    ldr r0, lbl_08060f74 @ =gCurrentArea
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08060f78 @ =gCurrentRoom
    strb r1, [r0]
    ldr r0, lbl_08060f7c @ =gLastDoorUsed
    strb r1, [r0]
    ldr r0, lbl_08060f80 @ =gGameModeSub3
    strb r1, [r0]
    ldr r0, lbl_08060f84 @ =gShipLandingFlag
    strb r1, [r0]
    b lbl_08060fda
    .align 2, 0
lbl_08060f74: .4byte gCurrentArea
lbl_08060f78: .4byte gCurrentRoom
lbl_08060f7c: .4byte gLastDoorUsed
lbl_08060f80: .4byte gGameModeSub3
lbl_08060f84: .4byte gShipLandingFlag
lbl_08060f88:
    ldr r1, lbl_08060f90 @ =gPauseScreenFlag
    movs r0, #8
    strb r0, [r1]
    b lbl_08060fda
    .align 2, 0
lbl_08060f90: .4byte gPauseScreenFlag
lbl_08060f94:
    ldr r1, lbl_08060fa4 @ =gPauseScreenFlag
    movs r0, #7
    strb r0, [r1]
    ldr r1, lbl_08060fa8 @ =gMusicTrackInfo
    movs r0, #7
    strb r0, [r1, #2]
    b lbl_08060fda
    .align 2, 0
lbl_08060fa4: .4byte gPauseScreenFlag
lbl_08060fa8: .4byte gMusicTrackInfo
lbl_08060fac:
    ldr r0, lbl_08060fc4 @ =gCurrentArea
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08060fc8
    movs r0, #0x1c
    bl SoundStop
    movs r0, #0x34
    movs r1, #0x3c
    bl sub_08003bd0
    b lbl_08060fda
    .align 2, 0
lbl_08060fc4: .4byte gCurrentArea
lbl_08060fc8:
    cmp r0, #3
    bne lbl_08060fda
    movs r0, #0x1c
    bl SoundStop
    movs r0, #0x35
    movs r1, #0x3c
    bl sub_08003bd0
lbl_08060fda:
    ldr r5, lbl_08061038 @ =0x0836bdac
    ldr r4, lbl_0806103c @ =gCurrentCutscene
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #4
    adds r0, r0, r5
    ldrb r0, [r0, #0xc]
    bl ColorFadingStart
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #4
    adds r1, r0, r5
    ldrb r0, [r1, #0xd]
    cmp r0, #0
    beq lbl_08061002
    adds r1, r0, #0
    movs r0, #1
    bl EventFunction
lbl_08061002:
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #4
    adds r1, r0, r5
    ldrb r0, [r1, #1]
    lsls r0, r0, #0x1a
    lsrs r0, r0, #0x1e
    cmp r0, #0
    beq lbl_08061032
    movs r0, #0x87
    lsls r0, r0, #1
    ldrh r1, [r1, #0xa]
    bl sub_08002de8
    ldr r0, lbl_08061040 @ =gMusicTrackInfo
    ldrh r0, [r0]
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r1, r1, #4
    adds r1, r1, r5
    ldrh r1, [r1, #0xa]
    movs r2, #0
    bl sub_08003c20
lbl_08061032:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061038: .4byte 0x0836bdac
lbl_0806103c: .4byte gCurrentCutscene
lbl_08061040: .4byte gMusicTrackInfo

    thumb_func_start cutscene_main
cutscene_main: @ 0x08061044
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_0806105c @ =gSubGameModeStage
    ldrb r0, [r0]
    cmp r0, #4
    bls lbl_08061052
    b lbl_0806121c
lbl_08061052:
    lsls r0, r0, #2
    ldr r1, lbl_08061060 @ =lbl_08061064
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806105c: .4byte gSubGameModeStage
lbl_08061060: .4byte lbl_08061064
lbl_08061064: @ jump table
    .4byte lbl_08061078 @ case 0
    .4byte lbl_080610bc @ case 1
    .4byte lbl_080610ce @ case 2
    .4byte lbl_080610e0 @ case 3
    .4byte lbl_08061158 @ case 4
lbl_08061078:
    ldr r0, lbl_080610a0 @ =sub_080612d4
    bl CallbackSetVBlank
    ldr r1, lbl_080610a4 @ =0x0836bdac
    ldr r0, lbl_080610a8 @ =gCurrentCutscene
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #4
    adds r0, r0, r1
    ldrb r0, [r0, #8]
    bl unk_61fa0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_080610b0
    ldr r1, lbl_080610ac @ =gSubGameModeStage
    movs r0, #2
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_080610a0: .4byte sub_080612d4
lbl_080610a4: .4byte 0x0836bdac
lbl_080610a8: .4byte gCurrentCutscene
lbl_080610ac: .4byte gSubGameModeStage
lbl_080610b0:
    ldr r1, lbl_080610b8 @ =gSubGameModeStage
    movs r0, #1
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_080610b8: .4byte gSubGameModeStage
lbl_080610bc:
    bl sub_08061f60
    bl sub_080621d0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_080610cc
    b lbl_0806121c
lbl_080610cc:
    b lbl_08061136
lbl_080610ce:
    bl sub_080612e0
    ldr r0, lbl_080610dc @ =sub_0806122c
    bl CallbackSetVBlank
    b lbl_08061136
    .align 2, 0
lbl_080610dc: .4byte sub_0806122c
lbl_080610e0:
    ldr r0, lbl_08061140 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #2]
    adds r0, #1
    strh r0, [r1, #2]
    bl sub_08061be4
    ldr r1, lbl_08061144 @ =0x0836bdac
    ldr r4, lbl_08061148 @ =gCurrentCutscene
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #4
    adds r1, #4
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r2, r1, #0x1f
    ldr r0, lbl_0806114c @ =gCutsceneToSkip
    ldrb r1, [r0]
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r1, r0
    bne lbl_0806112a
    ldr r0, lbl_08061150 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806112a
    bl sub_08060ec0
    movs r2, #1
lbl_0806112a:
    cmp r2, #0
    beq lbl_0806121c
    ldr r0, lbl_08061140 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0x1c]
lbl_08061136:
    ldr r1, lbl_08061154 @ =gSubGameModeStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_08061140: .4byte 0x08754bc4
lbl_08061144: .4byte 0x0836bdac
lbl_08061148: .4byte gCurrentCutscene
lbl_0806114c: .4byte gCutsceneToSkip
lbl_08061150: .4byte gChangedInput
lbl_08061154: .4byte gSubGameModeStage
lbl_08061158:
    ldr r0, lbl_0806117c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbf
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_08061184
    ldr r1, lbl_08061180 @ =0x00007fff
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08061198
    .align 2, 0
lbl_0806117c: .4byte 0x08754bc4
lbl_08061180: .4byte 0x00007fff
lbl_08061184:
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
lbl_08061198:
    movs r2, #0xc0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #9
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r1, #0x40
    bl BitFill
    ldr r2, lbl_08061208 @ =0x06010000
    movs r3, #0x80
    lsls r3, r3, #8
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r2, #0xe0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0xff
    bl BitFill
    bl end_cutscene
    ldr r3, lbl_0806120c @ =0x0836bdac
    ldr r2, lbl_08061210 @ =gCurrentCutscene
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r0, r0, #4
    adds r0, r0, r3
    ldrb r0, [r0, #1]
    lsrs r0, r0, #6
    cmp r0, #0
    beq lbl_080611ee
    ldr r1, lbl_08061214 @ =gCutsceneToSkip
    ldrb r0, [r2]
    strb r0, [r1]
lbl_080611ee:
    ldr r1, lbl_08061218 @ =gSubGameModeStage
    movs r0, #0
    strb r0, [r1]
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r0, r0, #4
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08061204
    strb r0, [r2]
lbl_08061204:
    movs r0, #1
    b lbl_0806121e
    .align 2, 0
lbl_08061208: .4byte 0x06010000
lbl_0806120c: .4byte 0x0836bdac
lbl_08061210: .4byte gCurrentCutscene
lbl_08061214: .4byte gCutsceneToSkip
lbl_08061218: .4byte gSubGameModeStage
lbl_0806121c:
    movs r0, #0
lbl_0806121e:
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start return_one_cutscene
return_one_cutscene: @ 0x08061228
    movs r0, #1
    bx lr

    thumb_func_start sub_0806122c
sub_0806122c: @ 0x0806122c
    ldr r1, lbl_080612b0 @ =0x040000d4
    ldr r0, lbl_080612b4 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_080612b8 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xc4
    ldr r0, lbl_080612bc @ =0x08754bc4
    ldr r2, [r0]
    ldrh r0, [r2, #0x30]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x28]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x32]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x2a]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x34]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x2c]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x36]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x2e]
    strh r0, [r1]
    subs r1, #0x16
    ldrh r0, [r2, #0x20]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x22]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x24]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #0x26]
    strh r0, [r1]
    adds r1, #0x46
    ldr r0, lbl_080612c0 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_080612c4 @ =0x04000052
    ldr r0, lbl_080612c8 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_080612cc @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r3]
    ldr r1, lbl_080612d0 @ =0x04000050
    ldrh r0, [r2, #0x1e]
    strh r0, [r1]
    subs r1, #0x50
    ldrh r0, [r2, #0x1c]
    strh r0, [r1]
    bx lr
    .align 2, 0
lbl_080612b0: .4byte 0x040000d4
lbl_080612b4: .4byte gOamData
lbl_080612b8: .4byte 0x84000100
lbl_080612bc: .4byte 0x08754bc4
lbl_080612c0: .4byte gWrittenToBLDY_NonGameplay
lbl_080612c4: .4byte 0x04000052
lbl_080612c8: .4byte gWrittenToBLDALPHA_H
lbl_080612cc: .4byte gWrittenToBLDALPHA_L
lbl_080612d0: .4byte 0x04000050

    thumb_func_start sub_080612d4
sub_080612d4: @ 0x080612d4
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr

    thumb_func_start sub_080612e0
sub_080612e0: @ 0x080612e0
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_080613c0 @ =sub_080612d4
    bl CallbackSetVBlank
    ldr r2, lbl_080613c4 @ =gNonGameplayRAM
    movs r3, #0xc5
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_080613c8 @ =gOamXOffset_NonGameplay
    ldr r1, lbl_080613cc @ =gOamYOffset_NonGameplay
    movs r0, #0
    strb r0, [r1]
    strb r0, [r2]
    ldr r1, lbl_080613d0 @ =gNextOamSlot
    strb r0, [r1]
    bl ResetFreeOAM
    ldr r1, lbl_080613d4 @ =0x04000050
    ldr r0, lbl_080613d8 @ =0x08754bc4
    ldr r3, [r0]
    movs r4, #0
    movs r0, #0xff
    strh r0, [r3, #0x1e]
    strh r0, [r1]
    ldr r2, lbl_080613dc @ =0x04000054
    ldr r1, lbl_080613e0 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r4, [r3, #0x1c]
    strh r4, [r0]
    ldr r1, lbl_080613e4 @ =0x0836bdac
    ldr r0, lbl_080613e8 @ =gCurrentCutscene
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #4
    adds r0, r0, r1
    ldrb r3, [r0]
    cmp r3, #0
    beq lbl_0806135e
    cmp r3, #2
    bne lbl_0806134a
    ldr r0, lbl_080613ec @ =gPauseScreenFlag
    strb r3, [r0]
lbl_0806134a:
    cmp r3, #2
    bgt lbl_0806135e
    ldr r1, lbl_080613f0 @ =0x06010000
    ldr r2, lbl_080613f4 @ =0x0201e000
    lsls r3, r3, #0xe
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806135e:
    ldr r2, lbl_080613f8 @ =gCutsceneToSkip
    ldrb r1, [r2]
    ldr r4, lbl_080613e8 @ =gCurrentCutscene
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r1, r0
    beq lbl_08061370
    movs r0, #0
    strb r0, [r2]
lbl_08061370:
    bl ClearGfxRam
    ldr r2, lbl_080613fc @ =gBG0HOFS_NonGameplay
    ldr r0, lbl_08061400 @ =gBG0VOFS_NonGameplay
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r3, #0
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_08061404 @ =gBG1HOFS_NonGameplay
    ldr r0, lbl_08061408 @ =gBG1VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806140c @ =gBG2HOFS_NonGameplay
    ldr r0, lbl_08061410 @ =gBG2VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_08061414 @ =gBG3HOFS_NonGameplay
    ldr r0, lbl_08061418 @ =gBG3VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_080613d8 @ =0x08754bc4
    ldr r0, [r2]
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    strh r1, [r0, #2]
    ldr r1, lbl_080613e4 @ =0x0836bdac
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #4
    adds r1, #4
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080613c0: .4byte sub_080612d4
lbl_080613c4: .4byte gNonGameplayRAM
lbl_080613c8: .4byte gOamXOffset_NonGameplay
lbl_080613cc: .4byte gOamYOffset_NonGameplay
lbl_080613d0: .4byte gNextOamSlot
lbl_080613d4: .4byte 0x04000050
lbl_080613d8: .4byte 0x08754bc4
lbl_080613dc: .4byte 0x04000054
lbl_080613e0: .4byte gWrittenToBLDY_NonGameplay
lbl_080613e4: .4byte 0x0836bdac
lbl_080613e8: .4byte gCurrentCutscene
lbl_080613ec: .4byte gPauseScreenFlag
lbl_080613f0: .4byte 0x06010000
lbl_080613f4: .4byte 0x0201e000
lbl_080613f8: .4byte gCutsceneToSkip
lbl_080613fc: .4byte gBG0HOFS_NonGameplay
lbl_08061400: .4byte gBG0VOFS_NonGameplay
lbl_08061404: .4byte gBG1HOFS_NonGameplay
lbl_08061408: .4byte gBG1VOFS_NonGameplay
lbl_0806140c: .4byte gBG2HOFS_NonGameplay
lbl_08061410: .4byte gBG2VOFS_NonGameplay
lbl_08061414: .4byte gBG3HOFS_NonGameplay
lbl_08061418: .4byte gBG3VOFS_NonGameplay

    thumb_func_start CutsceneSetBGCNTPageData
CutsceneSetBGCNTPageData: @ 0x0806141c
    push {r4, lr}
    adds r4, r1, #0
    adds r3, r0, #0
    lsls r0, r4, #0x10
    lsrs r1, r0, #0x10
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08061432
    movs r1, #0
    b lbl_08061454
lbl_08061432:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_0806143e
    movs r1, #1
    b lbl_08061454
lbl_0806143e:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_0806144a
    movs r1, #2
    b lbl_08061454
lbl_0806144a:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bne lbl_08061478
    movs r1, #3
lbl_08061454:
    ldr r0, lbl_08061480 @ =0x08754bc4
    ldr r2, [r0]
    lsls r0, r1, #1
    adds r2, #0x20
    adds r2, r2, r0
    lsrs r0, r4, #0x10
    lsrs r1, r3, #0x10
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    orrs r1, r0
    movs r0, #0xff
    lsls r0, r0, #8
    ands r0, r3
    orrs r1, r0
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x16
    orrs r1, r0
    strh r1, [r2]
lbl_08061478:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061480: .4byte 0x08754bc4

    thumb_func_start sub_08061484
sub_08061484: @ 0x08061484
    push {lr}
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r2, r1, #0
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_0806149c
    movs r1, #0
    b lbl_080614be
lbl_0806149c:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_080614a8
    movs r1, #1
    b lbl_080614be
lbl_080614a8:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_080614b4
    movs r1, #2
    b lbl_080614be
lbl_080614b4:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r2, r0
    bne lbl_080614ca
    movs r1, #3
lbl_080614be:
    ldr r0, lbl_080614d0 @ =0x08754bc4
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r0, #0x20
    adds r0, r0, r1
    strh r3, [r0]
lbl_080614ca:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080614d0: .4byte 0x08754bc4

    thumb_func_start CutsceneSetBackgroundPosition
CutsceneSetBackgroundPosition: @ 0x080614d4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    movs r0, #1
    ands r0, r3
    cmp r0, #0
    beq lbl_08061528
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_080614fc
    ldr r0, lbl_080614f8 @ =gBG0HOFS_NonGameplay
    b lbl_08061526
    .align 2, 0
lbl_080614f8: .4byte gBG0HOFS_NonGameplay
lbl_080614fc:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_0806150c
    ldr r0, lbl_08061508 @ =gBG1HOFS_NonGameplay
    b lbl_08061526
    .align 2, 0
lbl_08061508: .4byte gBG1HOFS_NonGameplay
lbl_0806150c:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_0806151c
    ldr r0, lbl_08061518 @ =gBG2HOFS_NonGameplay
    b lbl_08061526
    .align 2, 0
lbl_08061518: .4byte gBG2HOFS_NonGameplay
lbl_0806151c:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bne lbl_08061528
    ldr r0, lbl_0806153c @ =gBG3HOFS_NonGameplay
lbl_08061526:
    strh r2, [r0]
lbl_08061528:
    movs r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_08061570
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08061544
    ldr r0, lbl_08061540 @ =gBG0VOFS_NonGameplay
    b lbl_0806156e
    .align 2, 0
lbl_0806153c: .4byte gBG3HOFS_NonGameplay
lbl_08061540: .4byte gBG0VOFS_NonGameplay
lbl_08061544:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_08061554
    ldr r0, lbl_08061550 @ =gBG1VOFS_NonGameplay
    b lbl_0806156e
    .align 2, 0
lbl_08061550: .4byte gBG1VOFS_NonGameplay
lbl_08061554:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_08061564
    ldr r0, lbl_08061560 @ =gBG2VOFS_NonGameplay
    b lbl_0806156e
    .align 2, 0
lbl_08061560: .4byte gBG2VOFS_NonGameplay
lbl_08061564:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bne lbl_08061570
    ldr r0, lbl_08061574 @ =gBG3VOFS_NonGameplay
lbl_0806156e:
    strh r2, [r0]
lbl_08061570:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061574: .4byte gBG3VOFS_NonGameplay

    thumb_func_start CutsceneGetBGHOFSPointer
CutsceneGetBGHOFSPointer: @ 0x08061578
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, r1, #0
    movs r2, #0
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_08061594
    ldr r2, lbl_08061590 @ =gBG0HOFS_NonGameplay
    b lbl_080615be
    .align 2, 0
lbl_08061590: .4byte gBG0HOFS_NonGameplay
lbl_08061594:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_080615a4
    ldr r2, lbl_080615a0 @ =gBG1HOFS_NonGameplay
    b lbl_080615be
    .align 2, 0
lbl_080615a0: .4byte gBG1HOFS_NonGameplay
lbl_080615a4:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_080615b4
    ldr r2, lbl_080615b0 @ =gBG2HOFS_NonGameplay
    b lbl_080615be
    .align 2, 0
lbl_080615b0: .4byte gBG2HOFS_NonGameplay
lbl_080615b4:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r3, r0
    bne lbl_080615be
    ldr r2, lbl_080615c4 @ =gBG3HOFS_NonGameplay
lbl_080615be:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_080615c4: .4byte gBG3HOFS_NonGameplay

    thumb_func_start CutsceneGetBGVOFSPointer
CutsceneGetBGVOFSPointer: @ 0x080615c8
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, r1, #0
    movs r2, #0
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_080615e4
    ldr r2, lbl_080615e0 @ =gBG0VOFS_NonGameplay
    b lbl_0806160e
    .align 2, 0
lbl_080615e0: .4byte gBG0VOFS_NonGameplay
lbl_080615e4:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_080615f4
    ldr r2, lbl_080615f0 @ =gBG1VOFS_NonGameplay
    b lbl_0806160e
    .align 2, 0
lbl_080615f0: .4byte gBG1VOFS_NonGameplay
lbl_080615f4:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_08061604
    ldr r2, lbl_08061600 @ =gBG2VOFS_NonGameplay
    b lbl_0806160e
    .align 2, 0
lbl_08061600: .4byte gBG2VOFS_NonGameplay
lbl_08061604:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r3, r0
    bne lbl_0806160e
    ldr r2, lbl_08061614 @ =gBG3VOFS_NonGameplay
lbl_0806160e:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_08061614: .4byte gBG3VOFS_NonGameplay

    thumb_func_start CutsceneStartBackgroundScrolling
CutsceneStartBackgroundScrolling: @ 0x08061618
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r6, r1, #0
    adds r5, r0, #0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov ip, r2
    movs r7, #0
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r2
    cmp r0, #0
    beq lbl_0806164e
    ldr r0, lbl_080616d0 @ =0x08754bc4
    ldr r2, [r0]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r2, #0x38
    adds r2, r2, r1
    ldr r1, [r2]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
lbl_0806164e:
    movs r0, #0x80
    lsls r0, r0, #2
    mov r1, ip
    ands r0, r1
    cmp r0, #0
    beq lbl_08061676
    ldr r0, lbl_080616d0 @ =0x08754bc4
    ldr r2, [r0]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    adds r0, #2
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r2, #0x38
    adds r2, r2, r1
    ldr r0, [r2]
    cmp r0, #0
    beq lbl_08061676
    adds r7, #1
lbl_08061676:
    movs r0, #0x80
    lsls r0, r0, #3
    mov r2, ip
    ands r0, r2
    cmp r0, #0
    beq lbl_0806169e
    ldr r0, lbl_080616d0 @ =0x08754bc4
    ldr r2, [r0]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    adds r0, #4
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r2, #0x38
    adds r2, r2, r1
    ldr r0, [r2]
    cmp r0, #0
    beq lbl_0806169e
    adds r7, #1
lbl_0806169e:
    movs r0, #0x80
    lsls r0, r0, #4
    mov r3, ip
    ands r0, r3
    cmp r0, #0
    beq lbl_080616c6
    ldr r0, lbl_080616d0 @ =0x08754bc4
    ldr r2, [r0]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    adds r0, #6
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #2
    adds r2, #0x38
    adds r2, r2, r1
    ldr r0, [r2]
    cmp r0, #0
    beq lbl_080616c6
    adds r7, #1
lbl_080616c6:
    cmp r7, #0
    beq lbl_080616d4
    movs r0, #0
    b lbl_080618ce
    .align 2, 0
lbl_080616d0: .4byte 0x08754bc4
lbl_080616d4:
    cmp r7, #1
    beq lbl_080616fc
    cmp r7, #1
    bgt lbl_080616e2
    cmp r7, #0
    beq lbl_080616ec
    b lbl_08061738
lbl_080616e2:
    cmp r7, #2
    beq lbl_08061710
    cmp r7, #3
    beq lbl_08061724
    b lbl_08061738
lbl_080616ec:
    movs r0, #0x80
    lsls r0, r0, #1
    mov r1, ip
    ands r0, r1
    movs r3, #0
    cmp r0, #0
    bne lbl_0806173c
    b lbl_08061738
lbl_080616fc:
    movs r0, #0x80
    lsls r0, r0, #2
    mov r2, ip
    ands r0, r2
    movs r3, #1
    rsbs r3, r3, #0
    cmp r0, #0
    beq lbl_0806173c
    movs r3, #2
    b lbl_0806173c
lbl_08061710:
    movs r0, #0x80
    lsls r0, r0, #3
    mov r3, ip
    ands r0, r3
    movs r3, #1
    rsbs r3, r3, #0
    cmp r0, #0
    beq lbl_0806173c
    movs r3, #4
    b lbl_0806173c
lbl_08061724:
    movs r0, #0x80
    lsls r0, r0, #4
    mov r1, ip
    ands r0, r1
    movs r3, #1
    rsbs r3, r3, #0
    cmp r0, #0
    beq lbl_0806173c
    movs r3, #6
    b lbl_0806173c
lbl_08061738:
    movs r3, #1
    rsbs r3, r3, #0
lbl_0806173c:
    adds r7, #1
    cmp r3, #0
    bge lbl_08061744
    b lbl_080618c6
lbl_08061744:
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    adds r3, r3, r0
    ldr r2, lbl_08061760 @ =0x08754bc4
    mov r8, r2
    cmp r3, #7
    bls lbl_08061754
    b lbl_08061860
lbl_08061754:
    lsls r0, r3, #2
    ldr r1, lbl_08061764 @ =lbl_08061768
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08061760: .4byte 0x08754bc4
lbl_08061764: .4byte lbl_08061768
lbl_08061768: @ jump table
    .4byte lbl_08061788 @ case 0
    .4byte lbl_080617a4 @ case 1
    .4byte lbl_080617c0 @ case 2
    .4byte lbl_080617dc @ case 3
    .4byte lbl_080617f8 @ case 4
    .4byte lbl_08061814 @ case 5
    .4byte lbl_08061830 @ case 6
    .4byte lbl_0806184c @ case 7
lbl_08061788:
    ldr r2, lbl_0806179c @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617a0 @ =gBG0HOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_0806179c: .4byte 0x08754bc4
lbl_080617a0: .4byte gBG0HOFS_NonGameplay
lbl_080617a4:
    ldr r2, lbl_080617b8 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617bc @ =gBG0VOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_080617b8: .4byte 0x08754bc4
lbl_080617bc: .4byte gBG0VOFS_NonGameplay
lbl_080617c0:
    ldr r2, lbl_080617d4 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617d8 @ =gBG1HOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_080617d4: .4byte 0x08754bc4
lbl_080617d8: .4byte gBG1HOFS_NonGameplay
lbl_080617dc:
    ldr r2, lbl_080617f0 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617f4 @ =gBG1VOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_080617f0: .4byte 0x08754bc4
lbl_080617f4: .4byte gBG1VOFS_NonGameplay
lbl_080617f8:
    ldr r2, lbl_0806180c @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_08061810 @ =gBG2HOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_0806180c: .4byte 0x08754bc4
lbl_08061810: .4byte gBG2HOFS_NonGameplay
lbl_08061814:
    ldr r2, lbl_08061828 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_0806182c @ =gBG2VOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_08061828: .4byte 0x08754bc4
lbl_0806182c: .4byte gBG2VOFS_NonGameplay
lbl_08061830:
    ldr r2, lbl_08061844 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_08061848 @ =gBG3HOFS_NonGameplay
    b lbl_0806185c
    .align 2, 0
lbl_08061844: .4byte 0x08754bc4
lbl_08061848: .4byte gBG3HOFS_NonGameplay
lbl_0806184c:
    ldr r2, lbl_08061888 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_0806188c @ =gBG3VOFS_NonGameplay
lbl_0806185c:
    str r0, [r1]
    mov r8, r2
lbl_08061860:
    adds r4, r6, #0
    lsls r0, r4, #0x18
    cmp r0, #0
    bne lbl_08061890
    mov r0, r8
    ldr r2, [r0]
    lsls r1, r3, #1
    adds r0, r1, r3
    lsls r0, r0, #2
    adds r0, r2, r0
    movs r2, #1
    rsbs r2, r2, #0
    adds r4, r2, #0
    cmp r5, #0
    blt lbl_08061880
    movs r4, #1
lbl_08061880:
    adds r0, #0x3f
    strb r4, [r0]
    b lbl_080618a2
    .align 2, 0
lbl_08061888: .4byte 0x08754bc4
lbl_0806188c: .4byte gBG3VOFS_NonGameplay
lbl_08061890:
    mov r1, r8
    ldr r0, [r1]
    lsls r2, r3, #1
    adds r1, r2, r3
    lsls r1, r1, #2
    adds r0, r0, r1
    adds r0, #0x3f
    strb r4, [r0]
    adds r1, r2, #0
lbl_080618a2:
    mov r2, r8
    ldr r0, [r2]
    adds r2, r1, r3
    lsls r2, r2, #2
    adds r0, r0, r2
    lsls r1, r6, #0x10
    asrs r1, r1, #0x18
    adds r0, #0x40
    strb r1, [r0]
    mov r3, r8
    ldr r0, [r3]
    adds r0, r0, r2
    adds r0, #0x3e
    strb r1, [r0]
    ldr r0, [r3]
    adds r0, r0, r2
    asrs r1, r5, #0x10
    strh r1, [r0, #0x3c]
lbl_080618c6:
    cmp r7, #3
    bgt lbl_080618cc
    b lbl_080616d4
lbl_080618cc:
    movs r0, #1
lbl_080618ce:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_080618d8
sub_080618d8: @ 0x080618d8
    push {r4, lr}
    adds r2, r0, #0
    movs r0, #4
    ldrsh r3, [r2, r0]
    cmp r3, #0
    beq lbl_08061938
    ldrb r1, [r2, #6]
    movs r0, #6
    ldrsb r0, [r2, r0]
    cmp r0, #0
    ble lbl_080618f4
    subs r0, r1, #1
    strb r0, [r2, #6]
    b lbl_08061930
lbl_080618f4:
    ldrb r0, [r2, #8]
    strb r0, [r2, #6]
    movs r0, #7
    ldrsb r0, [r2, r0]
    cmp r0, #0
    blt lbl_08061908
    movs r4, #1
    cmp r3, r0
    bge lbl_08061914
    b lbl_08061920
lbl_08061908:
    movs r0, #7
    ldrsb r0, [r2, r0]
    movs r4, #1
    cmp r3, r0
    ble lbl_08061914
    movs r4, #0
lbl_08061914:
    cmp r4, #0
    beq lbl_08061920
    adds r4, r0, #0
    ldrh r0, [r2, #4]
    subs r0, r0, r4
    b lbl_08061926
lbl_08061920:
    movs r1, #4
    ldrsh r4, [r2, r1]
    movs r0, #0
lbl_08061926:
    strh r0, [r2, #4]
    ldr r1, [r2]
    ldrh r0, [r1]
    adds r0, r0, r4
    strh r0, [r1]
lbl_08061930:
    movs r1, #4
    ldrsh r0, [r2, r1]
    cmp r0, #0
    bne lbl_0806193c
lbl_08061938:
    movs r0, #0
    str r0, [r2]
lbl_0806193c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start CutsceneCheckBackgroundScrollingActive
CutsceneCheckBackgroundScrollingActive: @ 0x08061944
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r4, r1, #0
    movs r3, #0
    movs r2, #1
    rsbs r2, r2, #0
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r1, r0
    bne lbl_0806195e
    movs r2, #0
    b lbl_08061984
lbl_0806195e:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_0806196a
    movs r2, #2
    b lbl_08061984
lbl_0806196a:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_08061976
    movs r2, #4
    b lbl_08061984
lbl_08061976:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r4, r0
    bne lbl_08061980
    movs r2, #6
lbl_08061980:
    cmp r2, #0
    blt lbl_080619b8
lbl_08061984:
    ldr r0, lbl_080619c0 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    adds r1, #0x38
    adds r0, r1, r0
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_0806199c
    movs r0, #1
    orrs r3, r0
lbl_0806199c:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    asrs r2, r0, #0x18
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    adds r0, r1, r0
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_080619b8
    movs r0, #2
    orrs r3, r0
    lsls r0, r3, #0x18
    lsrs r3, r0, #0x18
lbl_080619b8:
    adds r0, r3, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080619c0: .4byte 0x08754bc4

    thumb_func_start CutsceneUpdateBackgroundsPosition
CutsceneUpdateBackgroundsPosition: @ 0x080619c4
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080619f8
    movs r6, #0x38
    movs r5, #0
    movs r4, #7
lbl_080619d8:
    ldr r0, lbl_08061a64 @ =0x08754bc4
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x38
    adds r0, r0, r5
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_080619ee
    adds r0, r1, r6
    bl sub_080618d8
lbl_080619ee:
    adds r6, #0xc
    adds r5, #0xc
    subs r4, #1
    cmp r4, #0
    bge lbl_080619d8
lbl_080619f8:
    ldr r4, lbl_08061a64 @ =0x08754bc4
    ldr r1, [r4]
    ldr r0, lbl_08061a68 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x30]
    ldr r0, lbl_08061a6c @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x28]
    ldr r0, lbl_08061a70 @ =gBG1HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x32]
    ldr r0, lbl_08061a74 @ =gBG1VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x2a]
    ldr r0, lbl_08061a78 @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x34]
    ldr r0, lbl_08061a7c @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x2c]
    ldr r0, lbl_08061a80 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x36]
    ldr r0, lbl_08061a84 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x2e]
    adds r1, #0x98
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08061a4a
    movs r0, #0
    bl sub_08061a88
lbl_08061a4a:
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xa0
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_08061a5c
    movs r0, #1
    bl sub_08061a88
lbl_08061a5c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061a64: .4byte 0x08754bc4
lbl_08061a68: .4byte gBG0HOFS_NonGameplay
lbl_08061a6c: .4byte gBG0VOFS_NonGameplay
lbl_08061a70: .4byte gBG1HOFS_NonGameplay
lbl_08061a74: .4byte gBG1VOFS_NonGameplay
lbl_08061a78: .4byte gBG2HOFS_NonGameplay
lbl_08061a7c: .4byte gBG2VOFS_NonGameplay
lbl_08061a80: .4byte gBG3HOFS_NonGameplay
lbl_08061a84: .4byte gBG3VOFS_NonGameplay

    thumb_func_start sub_08061a88
sub_08061a88: @ 0x08061a88
    push {r4, lr}
    adds r2, r1, #0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldrb r1, [r2, #2]
    movs r0, #2
    ldrsb r0, [r2, r0]
    cmp r0, #1
    ble lbl_08061aa0
    subs r0, r1, #1
    strb r0, [r2, #2]
    b lbl_08061b8c
lbl_08061aa0:
    ldrb r0, [r2, #3]
    strb r0, [r2, #2]
    ldr r0, lbl_08061b28 @ =0x0875fe58
    ldrb r3, [r2, #4]
    adds r0, r3, r0
    ldrb r1, [r2, #5]
    ldrb r0, [r0]
    cmp r1, r0
    ble lbl_08061ab6
    movs r0, #0
    strb r0, [r2, #5]
lbl_08061ab6:
    ldr r1, lbl_08061b2c @ =0x0875fe48
    lsls r0, r3, #2
    adds r0, r0, r1
    ldrb r1, [r2, #5]
    ldr r0, [r0]
    adds r0, r0, r1
    movs r3, #0
    ldrsb r3, [r0, r3]
    adds r1, #1
    strb r1, [r2, #5]
    cmp r4, #0
    bne lbl_08061b34
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08061ae4
    ldr r0, lbl_08061b30 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x30]
    adds r0, r0, r3
    strh r0, [r1, #0x30]
lbl_08061ae4:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08061afa
    ldr r0, lbl_08061b30 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x32]
    adds r0, r0, r3
    strh r0, [r1, #0x32]
lbl_08061afa:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b10
    ldr r0, lbl_08061b30 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x34]
    adds r0, r0, r3
    strh r0, [r1, #0x34]
lbl_08061b10:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b8c
    ldr r0, lbl_08061b30 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x36]
    adds r0, r0, r3
    strh r0, [r1, #0x36]
    b lbl_08061b8c
    .align 2, 0
lbl_08061b28: .4byte 0x0875fe58
lbl_08061b2c: .4byte 0x0875fe48
lbl_08061b30: .4byte 0x08754bc4
lbl_08061b34:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b4a
    ldr r0, lbl_08061b94 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x28]
    adds r0, r0, r3
    strh r0, [r1, #0x28]
lbl_08061b4a:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b60
    ldr r0, lbl_08061b94 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x2a]
    adds r0, r0, r3
    strh r0, [r1, #0x2a]
lbl_08061b60:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b76
    ldr r0, lbl_08061b94 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x2c]
    adds r0, r0, r3
    strh r0, [r1, #0x2c]
lbl_08061b76:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08061b8c
    ldr r0, lbl_08061b94 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0x2e]
    adds r0, r0, r3
    strh r0, [r1, #0x2e]
lbl_08061b8c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061b94: .4byte 0x08754bc4

    thumb_func_start CutsceneStartScreenShake
CutsceneStartScreenShake: @ 0x08061b98
    push {r4, r5, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r5, r4, #0
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08061bbc
    ldr r0, lbl_08061bb8 @ =0x08754bc4
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0x98
    movs r1, #0
    strh r4, [r2]
    b lbl_08061bcc
    .align 2, 0
lbl_08061bb8: .4byte 0x08754bc4
lbl_08061bbc:
    cmp r0, #1
    bne lbl_08061bd8
    ldr r0, lbl_08061be0 @ =0x08754bc4
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0xa0
    movs r1, #0
    strh r5, [r2]
lbl_08061bcc:
    strb r1, [r2, #2]
    lsrs r0, r3, #8
    strb r0, [r2, #3]
    lsrs r0, r3, #0x10
    strb r0, [r2, #4]
    strb r1, [r2, #5]
lbl_08061bd8:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061be0: .4byte 0x08754bc4

    thumb_func_start sub_08061be4
sub_08061be4: @ 0x08061be4
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_08061c18 @ =0x08754bc4
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r3, [r0]
    movs r0, #5
    ands r0, r3
    adds r7, r1, #0
    cmp r0, #0
    bne lbl_08061bfc
    b lbl_08061d62
lbl_08061bfc:
    movs r0, #1
    ands r0, r3
    cmp r0, #0
    beq lbl_08061ca0
    adds r1, r2, #0
    adds r1, #0xb0
    ldrb r3, [r1]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    ble lbl_08061c1c
    subs r0, r3, #1
    b lbl_08061d60
    .align 2, 0
lbl_08061c18: .4byte 0x08754bc4
lbl_08061c1c:
    adds r0, r2, #0
    adds r0, #0xaf
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r0, lbl_08061c4c @ =gWrittenToBLDY_NonGameplay
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0xa9
    ldrb r3, [r2]
    ldrh r4, [r0]
    adds r2, r3, #0
    adds r5, r0, #0
    cmp r4, r2
    beq lbl_08061c6e
    cmp r4, r2
    bhs lbl_08061c50
    ldrh r0, [r5]
    adds r1, #0xae
    ldrb r1, [r1]
    adds r0, r0, r1
    cmp r0, r3
    bgt lbl_08061c5c
    b lbl_08061c60
    .align 2, 0
lbl_08061c4c: .4byte gWrittenToBLDY_NonGameplay
lbl_08061c50:
    ldrh r0, [r5]
    adds r1, #0xae
    ldrb r1, [r1]
    subs r0, r0, r1
    cmp r0, r3
    bge lbl_08061c60
lbl_08061c5c:
    strh r3, [r5]
    b lbl_08061c62
lbl_08061c60:
    strh r0, [r5]
lbl_08061c62:
    ldr r0, [r7]
    adds r0, #0xa9
    ldrh r1, [r5]
    ldrb r0, [r0]
    cmp r1, r0
    bne lbl_08061d62
lbl_08061c6e:
    ldr r1, [r7]
    adds r1, #0xa8
    ldrb r2, [r1]
    movs r0, #0xfe
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r7]
    adds r1, #0xa8
    ldrb r2, [r1]
    movs r0, #2
    orrs r0, r2
    strb r0, [r1]
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08061d62
    adds r0, r2, #0
    adds r0, #0xb2
    ldrh r0, [r0]
    strh r0, [r2, #0x1e]
    b lbl_08061d62
lbl_08061ca0:
    adds r1, r2, #0
    adds r1, #0xb6
    ldrb r3, [r1]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    ble lbl_08061cb2
    subs r0, r3, #1
    b lbl_08061d60
lbl_08061cb2:
    adds r0, r2, #0
    adds r0, #0xb5
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r0, lbl_08061ce0 @ =gWrittenToBLDALPHA_L
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0xaa
    ldrb r3, [r2]
    ldrh r4, [r0]
    adds r2, r3, #0
    adds r6, r0, #0
    cmp r4, r2
    beq lbl_08061cf6
    cmp r4, r2
    bhs lbl_08061ce4
    ldrh r0, [r6]
    adds r1, #0xb4
    ldrb r1, [r1]
    adds r0, r0, r1
    cmp r0, r3
    bgt lbl_08061cf0
    b lbl_08061cf4
    .align 2, 0
lbl_08061ce0: .4byte gWrittenToBLDALPHA_L
lbl_08061ce4:
    ldrh r0, [r6]
    adds r1, #0xb4
    ldrb r1, [r1]
    subs r0, r0, r1
    cmp r0, r3
    bge lbl_08061cf4
lbl_08061cf0:
    strh r3, [r6]
    b lbl_08061cf6
lbl_08061cf4:
    strh r0, [r6]
lbl_08061cf6:
    ldr r0, lbl_08061d1c @ =gWrittenToBLDALPHA_H
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0xab
    ldrb r3, [r2]
    ldrh r4, [r0]
    adds r2, r3, #0
    adds r5, r0, #0
    cmp r4, r2
    beq lbl_08061d32
    cmp r4, r2
    bhs lbl_08061d20
    ldrh r0, [r5]
    adds r1, #0xb4
    ldrb r1, [r1]
    adds r0, r0, r1
    cmp r0, r3
    bgt lbl_08061d2c
    b lbl_08061d30
    .align 2, 0
lbl_08061d1c: .4byte gWrittenToBLDALPHA_H
lbl_08061d20:
    ldrh r0, [r5]
    adds r1, #0xb4
    ldrb r1, [r1]
    subs r0, r0, r1
    cmp r0, r3
    bge lbl_08061d30
lbl_08061d2c:
    strh r3, [r5]
    b lbl_08061d32
lbl_08061d30:
    strh r0, [r5]
lbl_08061d32:
    ldr r2, [r7]
    adds r1, r2, #0
    adds r1, #0xaa
    ldrh r0, [r6]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08061d62
    adds r1, r2, #0
    adds r1, #0xab
    ldrh r0, [r5]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08061d62
    adds r2, #0xa8
    ldrb r1, [r2]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r2]
    ldr r1, [r7]
    adds r1, #0xa8
    ldrb r2, [r1]
    movs r0, #8
    orrs r0, r2
lbl_08061d60:
    strb r0, [r1]
lbl_08061d62:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start CutsceneStartSpriteEffect
CutsceneStartSpriteEffect: @ 0x08061d68
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldr r4, lbl_08061dc4 @ =0x08754bc4
    mov r8, r4
    ldr r5, [r4]
    adds r5, #0xa8
    ldrb r6, [r5]
    movs r4, #0xfd
    ands r4, r6
    strb r4, [r5]
    mov r4, r8
    ldr r5, [r4]
    adds r5, #0xa8
    ldrb r6, [r5]
    movs r4, #1
    orrs r4, r6
    strb r4, [r5]
    mov r5, r8
    ldr r4, [r5]
    adds r4, #0xa9
    strb r1, [r4]
    ldr r1, [r5]
    adds r1, #0xae
    strb r3, [r1]
    ldr r1, [r5]
    adds r1, #0xaf
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    strb r2, [r1]
    ldr r1, [r5]
    adds r1, #0xb0
    strb r2, [r1]
    ldr r2, [r5]
    adds r1, r2, #0
    adds r1, #0xac
    strh r0, [r1]
    strh r0, [r2, #0x1e]
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061dc4: .4byte 0x08754bc4

    thumb_func_start CutsceneStartBackgroundEffect
CutsceneStartBackgroundEffect: @ 0x08061dc8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r4, [sp, #0x18]
    mov r8, r4
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldr r6, lbl_08061e34 @ =0x08754bc4
    ldr r4, [r6]
    adds r4, #0xa8
    ldrb r5, [r4]
    movs r0, #0xf7
    ands r0, r5
    strb r0, [r4]
    ldr r4, [r6]
    adds r4, #0xa8
    ldrb r5, [r4]
    movs r0, #4
    orrs r0, r5
    strb r0, [r4]
    ldr r0, [r6]
    adds r0, #0xaa
    strb r1, [r0]
    ldr r0, [r6]
    adds r0, #0xab
    strb r2, [r0]
    ldr r0, [r6]
    adds r0, #0xb4
    mov r1, r8
    strb r1, [r0]
    ldr r0, [r6]
    adds r0, #0xb5
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    strb r3, [r0]
    ldr r0, [r6]
    adds r0, #0xb6
    strb r3, [r0]
    ldr r2, [r6]
    adds r0, r2, #0
    adds r0, #0xb2
    strh r7, [r0]
    subs r0, #0xa
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08061e2a
    strh r7, [r2, #0x1e]
lbl_08061e2a:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061e34: .4byte 0x08754bc4

    thumb_func_start CutsceneReset
CutsceneReset: @ 0x08061e38
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r0, lbl_08061ef0 @ =gWrittenToBLDY_NonGameplay
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08061ef4 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08061ef8 @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r1, lbl_08061efc @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xa8
    movs r3, #0
    strb r2, [r0]
    ldr r0, [r1]
    strh r3, [r0, #0x1e]
    movs r2, #0
    adds r5, r1, #0
    ldr r0, lbl_08061f00 @ =gCurrentOamRotation
    mov r8, r0
    ldr r1, lbl_08061f04 @ =gCurrentOamScaling
    mov sb, r1
    mov ip, r5
    ldr r3, lbl_08061f08 @ =0x0840d058
lbl_08061e70:
    mov r4, ip
    ldr r0, [r4]
    lsls r1, r2, #5
    adds r0, r0, r1
    adds r0, #0xf0
    adds r1, r3, #0
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldm r1!, {r4, r6, r7}
    stm r0!, {r4, r6, r7}
    ldm r1!, {r6, r7}
    stm r0!, {r6, r7}
    adds r2, #1
    cmp r2, #0x1d
    ble lbl_08061e70
    movs r0, #0
    mov r1, r8
    strh r0, [r1]
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r4, #0
    mov r6, sb
    strh r0, [r6]
    ldr r2, [r5]
    adds r2, #8
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #4
    bl BitFill
    ldr r2, [r5]
    adds r2, #0xc0
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x30
    bl BitFill
    ldr r2, [r5]
    adds r2, #0x38
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x60
    bl BitFill
    ldr r2, [r5]
    adds r2, #0xc
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x10
    bl BitFill
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061ef0: .4byte gWrittenToBLDY_NonGameplay
lbl_08061ef4: .4byte gWrittenToBLDALPHA_L
lbl_08061ef8: .4byte gWrittenToBLDALPHA_H
lbl_08061efc: .4byte 0x08754bc4
lbl_08061f00: .4byte gCurrentOamRotation
lbl_08061f04: .4byte gCurrentOamScaling
lbl_08061f08: .4byte 0x0840d058

    thumb_func_start unk_61f0c
unk_61f0c: @ 0x08061f0c
    ldr r0, lbl_08061f20 @ =0x08754bc4
    ldr r2, [r0]
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldr r1, lbl_08061f24 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    movs r0, #0xff
    strh r0, [r2, #0x1e]
    bx lr
    .align 2, 0
lbl_08061f20: .4byte 0x08754bc4
lbl_08061f24: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start unk_61f28
unk_61f28: @ 0x08061f28
    ldr r0, lbl_08061f3c @ =0x08754bc4
    ldr r2, [r0]
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldr r1, lbl_08061f40 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    movs r0, #0xbf
    strh r0, [r2, #0x1e]
    bx lr
    .align 2, 0
lbl_08061f3c: .4byte 0x08754bc4
lbl_08061f40: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start unk_61f44
unk_61f44: @ 0x08061f44
    push {lr}
    bl sub_08061f60
    bl sub_080621d0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08061f58
    movs r0, #0
    b lbl_08061f5a
lbl_08061f58:
    movs r0, #1
lbl_08061f5a:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08061f60
sub_08061f60: @ 0x08061f60
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_08061f98 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08061f90
    ldr r0, lbl_08061f9c @ =0x08754bb4
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r1, r3
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, [r4]
    adds r0, #0xbc
    movs r1, #0
    strb r1, [r0]
lbl_08061f90:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061f98: .4byte 0x08754bc4
lbl_08061f9c: .4byte 0x08754bb4

    thumb_func_start unk_61fa0
unk_61fa0: @ 0x08061fa0
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    movs r7, #0
    ldr r1, lbl_08061fe8 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xbb
    strb r7, [r0]
    ldr r0, [r1]
    adds r0, #0xbc
    strb r7, [r0]
    ldr r0, [r1]
    adds r0, #0xb8
    strh r7, [r0]
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_08061fec @ =0x08754bb4
    ldr r2, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    subs r0, r4, #1
    cmp r0, #9
    bls lbl_08061fde
    b lbl_080621c4
lbl_08061fde:
    lsls r0, r0, #2
    ldr r1, lbl_08061ff0 @ =lbl_08061ff4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08061fe8: .4byte 0x08754bc4
lbl_08061fec: .4byte 0x08754bb4
lbl_08061ff0: .4byte lbl_08061ff4
lbl_08061ff4: @ jump table
    .4byte lbl_0806201c @ case 0
    .4byte lbl_08062068 @ case 1
    .4byte lbl_080620b8 @ case 2
    .4byte lbl_080621c4 @ case 3
    .4byte lbl_08062108 @ case 4
    .4byte lbl_0806210e @ case 5
    .4byte lbl_08062134 @ case 6
    .4byte lbl_08062154 @ case 7
    .4byte lbl_0806217c @ case 8
    .4byte lbl_0806219c @ case 9
lbl_0806201c:
    movs r6, #0xa0
    lsls r6, r6, #0x13
    movs r4, #0x80
    lsls r4, r4, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r4, #0
    bl BitFill
    ldr r0, lbl_08062060 @ =0x08754bb4
    ldr r2, [r0]
    adds r2, r2, r4
    str r5, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    ldr r2, lbl_08062064 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r3, #0
    strb r3, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #2
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    strb r3, [r0]
    b lbl_0806216e
    .align 2, 0
lbl_08062060: .4byte 0x08754bb4
lbl_08062064: .4byte 0x08754bc4
lbl_08062068:
    movs r6, #0xa0
    lsls r6, r6, #0x13
    movs r4, #0x80
    lsls r4, r4, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r4, #0
    bl BitFill
    ldr r0, lbl_080620b0 @ =0x08754bb4
    ldr r2, [r0]
    adds r2, r2, r4
    str r5, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    ldr r2, lbl_080620b4 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r3, #0
    strb r3, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #4
    strb r1, [r0]
    b lbl_0806216e
    .align 2, 0
lbl_080620b0: .4byte 0x08754bb4
lbl_080620b4: .4byte 0x08754bc4
lbl_080620b8:
    movs r6, #0xa0
    lsls r6, r6, #0x13
    movs r4, #0x80
    lsls r4, r4, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r4, #0
    bl BitFill
    ldr r0, lbl_08062100 @ =0x08754bb4
    ldr r2, [r0]
    adds r2, r2, r4
    str r5, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    ldr r2, lbl_08062104 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r3, #0
    strb r3, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #8
    strb r1, [r0]
    b lbl_0806216e
    .align 2, 0
lbl_08062100: .4byte 0x08754bb4
lbl_08062104: .4byte 0x08754bc4
lbl_08062108:
    movs r0, #0x14
    bl FadeMusic
lbl_0806210e:
    ldr r1, lbl_08062130 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xba
    movs r3, #0
    movs r2, #2
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbd
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r3, [r0]
    ldr r0, [r1]
    adds r0, #0xbf
    strb r2, [r0]
    b lbl_080621c6
    .align 2, 0
lbl_08062130: .4byte 0x08754bc4
lbl_08062134:
    ldr r2, lbl_08062150 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r3, #2
    strb r3, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #4
    strb r1, [r0]
    b lbl_0806216e
    .align 2, 0
lbl_08062150: .4byte 0x08754bc4
lbl_08062154:
    ldr r2, lbl_08062178 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r4, #0
    movs r3, #2
    strb r3, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #8
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    strb r4, [r0]
lbl_0806216e:
    ldr r0, [r2]
    adds r0, #0xbf
    strb r3, [r0]
    b lbl_080621c6
    .align 2, 0
lbl_08062178: .4byte 0x08754bc4
lbl_0806217c:
    ldr r1, lbl_08062198 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xba
    movs r3, #0
    movs r2, #2
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbd
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r3, [r0]
    ldr r0, [r1]
    b lbl_080621b8
    .align 2, 0
lbl_08062198: .4byte 0x08754bc4
lbl_0806219c:
    ldr r2, lbl_080621c0 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xba
    movs r1, #2
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbd
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #4
    strb r1, [r0]
    ldr r0, [r2]
lbl_080621b8:
    adds r0, #0xbf
    movs r1, #3
    strb r1, [r0]
    b lbl_080621c6
    .align 2, 0
lbl_080621c0: .4byte 0x08754bc4
lbl_080621c4:
    movs r7, #1
lbl_080621c6:
    adds r0, r7, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_080621d0
sub_080621d0: @ 0x080621d0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    movs r0, #0
    mov r8, r0
    ldr r7, lbl_08062204 @ =0x08754bc4
    ldr r2, [r7]
    adds r3, r2, #0
    adds r3, #0xb8
    ldrh r0, [r3]
    adds r0, #1
    movs r1, #0
    strh r0, [r3]
    adds r0, r2, #0
    adds r0, #0xba
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_080621f8
    b lbl_080623e4
lbl_080621f8:
    cmp r0, #1
    bgt lbl_08062208
    cmp r0, #0
    beq lbl_08062214
    b lbl_080623fe
    .align 2, 0
lbl_08062204: .4byte 0x08754bc4
lbl_08062208:
    cmp r0, #2
    beq lbl_080622dc
    cmp r0, #3
    bne lbl_08062212
    b lbl_080623e4
lbl_08062212:
    b lbl_080623fe
lbl_08062214:
    adds r0, r2, #0
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08062220
    b lbl_080623fe
lbl_08062220:
    movs r1, #0
    ldrsh r0, [r3, r1]
    adds r1, r2, #0
    adds r1, #0xbe
    ldrb r1, [r1]
    cmp r0, r1
    bge lbl_08062230
    b lbl_080623fe
lbl_08062230:
    adds r1, r2, #0
    adds r1, #0xbb
    ldrb r0, [r1]
    cmp r0, #0x1f
    bhi lbl_080622b0
    ldr r4, lbl_080622a8 @ =0x08754bb4
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r0, r3
    str r0, [sp, #8]
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r0, [r0]
    ldrb r1, [r1]
    add r6, sp, #8
    ldr r5, lbl_080622ac @ =0x0000ffff
    str r5, [sp]
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xc0
    lsls r3, r3, #3
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xbf
    ldrb r0, [r0]
    adds r1, #0xbb
    ldrb r1, [r1]
    str r5, [sp]
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r7]
    adds r0, #0xbc
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0xbb
    ldrb r0, [r2]
    cmp r0, #0x1f
    beq lbl_08062366
    ldrb r0, [r2]
    adds r1, #0xbd
    ldrb r1, [r1]
    adds r0, r0, r1
    cmp r0, #0x1f
    bgt lbl_08062380
    b lbl_08062368
    .align 2, 0
lbl_080622a8: .4byte 0x08754bb4
lbl_080622ac: .4byte 0x0000ffff
lbl_080622b0:
    ldr r0, lbl_080622d8 @ =0x08754bb4
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r2, r1, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, [r7]
    adds r0, #0xbc
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r7]
    adds r1, #0xba
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080623fe
    .align 2, 0
lbl_080622d8: .4byte 0x08754bb4
lbl_080622dc:
    adds r0, r2, #0
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080622e8
    b lbl_080623fe
lbl_080622e8:
    movs r1, #0
    ldrsh r0, [r3, r1]
    adds r1, r2, #0
    adds r1, #0xbe
    ldrb r1, [r1]
    cmp r0, r1
    bge lbl_080622f8
    b lbl_080623fe
lbl_080622f8:
    mov r0, r8
    strh r0, [r3]
    adds r1, r2, #0
    adds r1, #0xbb
    ldrb r0, [r1]
    cmp r0, #0x1f
    bhi lbl_08062384
    ldr r4, lbl_0806236c @ =0x08754bb4
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r0, r3
    str r0, [sp, #8]
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r0, [r0]
    ldrb r1, [r1]
    add r6, sp, #8
    ldr r5, lbl_08062370 @ =0x0000ffff
    str r5, [sp]
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xc0
    lsls r3, r3, #3
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xbf
    ldrb r0, [r0]
    adds r1, #0xbb
    ldrb r1, [r1]
    str r5, [sp]
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r7]
    adds r0, #0xbc
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0xbb
    ldrb r0, [r2]
    cmp r0, #0x1f
    bne lbl_08062374
lbl_08062366:
    adds r0, #1
lbl_08062368:
    strb r0, [r2]
    b lbl_080623fe
    .align 2, 0
lbl_0806236c: .4byte 0x08754bb4
lbl_08062370: .4byte 0x0000ffff
lbl_08062374:
    ldrb r0, [r2]
    adds r1, #0xbd
    ldrb r1, [r1]
    adds r0, r0, r1
    cmp r0, #0x1f
    ble lbl_08062368
lbl_08062380:
    movs r0, #0x1f
    b lbl_08062368
lbl_08062384:
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_080623b0
    ldr r1, lbl_080623a8 @ =0x00007fff
    ldr r0, lbl_080623ac @ =0x08754bb4
    ldr r2, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r2, r2, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_080623c6
    .align 2, 0
lbl_080623a8: .4byte 0x00007fff
lbl_080623ac: .4byte 0x08754bb4
lbl_080623b0:
    ldr r0, lbl_080623dc @ =0x08754bb4
    ldr r2, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r2, r2, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
lbl_080623c6:
    ldr r2, lbl_080623e0 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xbc
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xba
    movs r1, #3
    strb r1, [r0]
    b lbl_080623fe
    .align 2, 0
lbl_080623dc: .4byte 0x08754bb4
lbl_080623e0: .4byte 0x08754bc4
lbl_080623e4:
    adds r0, r2, #0
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080623fe
    adds r0, r2, #0
    adds r0, #0xbb
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xba
    strb r1, [r0]
    movs r0, #1
    mov r8, r0
lbl_080623fe:
    mov r0, r8
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
