    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start check_play_room_music_track
check_play_room_music_track: @ 0x08060928
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r2, lbl_0806095c @ =gMusicTrackInfo
    ldr r1, lbl_08060960 @ =0x0875fac4
    lsrs r0, r0, #0x16
    adds r0, r0, r1
    ldr r1, [r0]
    lsls r0, r4, #4
    subs r0, r0, r4
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrh r1, [r0, #0x3a]
    movs r0, #0
    strh r1, [r2]
    strb r0, [r2, #4]
    ldr r0, lbl_08060964 @ =gAreaBeforeTransition
    ldrb r0, [r0]
    adds r5, r2, #0
    cmp r0, #2
    beq lbl_08060968
    cmp r0, #6
    beq lbl_08060976
    b lbl_08060994
    .align 2, 0
lbl_0806095c: .4byte gMusicTrackInfo
lbl_08060960: .4byte 0x0875fac4
lbl_08060964: .4byte gAreaBeforeTransition
lbl_08060968:
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x5f
    bne lbl_08060994
    movs r0, #1
    strb r0, [r5, #4]
    b lbl_08060994
lbl_08060976:
    ldr r0, lbl_080609d0 @ =gEquipment
    ldrb r2, [r0, #0x12]
    cmp r2, #1
    bne lbl_08060994
    ldr r0, lbl_080609d4 @ =gAlarmTimer
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_08060994
    adds r0, r1, #0
    subs r0, #0x5b
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bhi lbl_08060994
    strb r2, [r5, #4]
lbl_08060994:
    movs r0, #4
    ldrsb r0, [r5, r0]
    cmp r0, #0
    bne lbl_080609c4
    ldr r1, lbl_080609d8 @ =gCurrentCutscene
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_080609ba
    ldr r0, lbl_080609dc @ =0x0836bdac
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r1, r1, #4
    adds r1, r1, r0
    ldrb r0, [r1, #1]
    lsls r0, r0, #0x1c
    cmp r0, #0
    beq lbl_080609c4
lbl_080609ba:
    ldrh r0, [r5]
    bl update_music_track
    movs r0, #1
    strb r0, [r5, #3]
lbl_080609c4:
    ldr r0, lbl_080609e0 @ =gDestinationRoom
    strb r4, [r0]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080609d0: .4byte gEquipment
lbl_080609d4: .4byte gAlarmTimer
lbl_080609d8: .4byte gCurrentCutscene
lbl_080609dc: .4byte 0x0836bdac
lbl_080609e0: .4byte gDestinationRoom

    thumb_func_start check_play_loading_jingle
check_play_loading_jingle: @ 0x080609e4
    push {lr}
    ldr r1, lbl_08060a2c @ =gMusicTrackInfo
    ldr r0, lbl_08060a30 @ =gCurrentRoomEntry
    ldrh r0, [r0, #0x16]
    strh r0, [r1]
    ldr r0, lbl_08060a34 @ =gGameModeSub3
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08060a28
    ldr r0, lbl_08060a38 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08060a28
    ldr r0, lbl_08060a3c @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08060a28
    bl sub_08003eb8
    ldr r0, lbl_08060a40 @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x2c
    bne lbl_08060a28
    ldr r1, lbl_08060a44 @ =gDisablePause
    movs r0, #1
    strb r0, [r1]
    movs r0, #0x36
    movs r1, #1
    bl InsertMusicAndQueueCurrent
lbl_08060a28:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060a2c: .4byte gMusicTrackInfo
lbl_08060a30: .4byte gCurrentRoomEntry
lbl_08060a34: .4byte gGameModeSub3
lbl_08060a38: .4byte gDemoState
lbl_08060a3c: .4byte gIsLoadingFile
lbl_08060a40: .4byte gSamusData
lbl_08060a44: .4byte gDisablePause

    thumb_func_start UpdateMusicWhenPausing
UpdateMusicWhenPausing: @ 0x08060a48
    push {lr}
    ldr r2, lbl_08060a6c @ =gMusicTrackInfo
    movs r0, #0
    strb r0, [r2, #2]
    ldr r1, lbl_08060a70 @ =gPauseScreenFlag
    ldrb r0, [r1]
    subs r0, #1
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r3, r1, #0
    cmp r0, #7
    bhi lbl_08060ab4
    lsls r0, r0, #2
    ldr r1, lbl_08060a74 @ =lbl_08060a78
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08060a6c: .4byte gMusicTrackInfo
lbl_08060a70: .4byte gPauseScreenFlag
lbl_08060a74: .4byte lbl_08060a78
lbl_08060a78: @ jump table
    .4byte lbl_08060ab4 @ case 0
    .4byte lbl_08060a98 @ case 1
    .4byte lbl_08060ab4 @ case 2
    .4byte lbl_08060ab0 @ case 3
    .4byte lbl_08060ab4 @ case 4
    .4byte lbl_08060ab0 @ case 5
    .4byte lbl_08060ab4 @ case 6
    .4byte lbl_08060ab4 @ case 7
lbl_08060a98:
    bl sub_08003f20
    ldr r0, lbl_08060aa8 @ =gMusicTrackInfo
    ldr r1, lbl_08060aac @ =gPauseScreenFlag
    ldrb r1, [r1]
    strb r1, [r0, #2]
    b lbl_08060ab4
    .align 2, 0
lbl_08060aa8: .4byte gMusicTrackInfo
lbl_08060aac: .4byte gPauseScreenFlag
lbl_08060ab0:
    ldrb r0, [r3]
    strb r0, [r2, #2]
lbl_08060ab4:
    pop {r0}
    bx r0

    thumb_func_start update_music_after_unpause
update_music_after_unpause: @ 0x08060ab8
    push {lr}
    ldr r0, lbl_08060ad4 @ =gMusicTrackInfo
    ldrb r0, [r0, #2]
    subs r0, #1
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_08060b10
    lsls r0, r0, #2
    ldr r1, lbl_08060ad8 @ =lbl_08060adc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08060ad4: .4byte gMusicTrackInfo
lbl_08060ad8: .4byte lbl_08060adc
lbl_08060adc: @ jump table
    .4byte lbl_08060b10 @ case 0
    .4byte lbl_08060afc @ case 1
    .4byte lbl_08060b10 @ case 2
    .4byte lbl_08060b10 @ case 3
    .4byte lbl_08060b10 @ case 4
    .4byte lbl_08060b02 @ case 5
    .4byte lbl_08060b08 @ case 6
    .4byte lbl_08060b10 @ case 7
lbl_08060afc:
    bl sub_08003f6c
    b lbl_08060b10
lbl_08060b02:
    bl RetrieveTrackData2SoundChannels
    b lbl_08060b10
lbl_08060b08:
    movs r0, #0xe
    movs r1, #0x10
    bl PlayMusic
lbl_08060b10:
    pop {r0}
    bx r0
