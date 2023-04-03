    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start load_room_cutscene_escape
load_room_cutscene_escape: @ 0x08057d04
    push {r4, lr}
    sub sp, #4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, lbl_08057d9c @ =gBG0XPosition
    strh r2, [r4]
    ldr r4, lbl_08057da0 @ =gBG0YPosition
    strh r3, [r4]
    ldr r4, lbl_08057da4 @ =gBG1XPosition
    strh r2, [r4]
    ldr r4, lbl_08057da8 @ =gBG1YPosition
    strh r3, [r4]
    ldr r4, lbl_08057dac @ =gBG2XPosition
    strh r2, [r4]
    ldr r2, lbl_08057db0 @ =gBG2YPosition
    strh r3, [r2]
    ldr r2, lbl_08057db4 @ =gCurrentArea
    strb r0, [r2]
    ldr r0, lbl_08057db8 @ =gCurrentRoom
    subs r1, #1
    strb r1, [r0]
    bl load_room_entry
    bl load_tileset
    bl load_room_backgrounds
    bl remove_never_reform_blocks_and_collected_tank
    bl TransparencySetRoomEffectsTransparency
    bl ScrollBG3
    bl AnimatedGraphicsCheckPlayLightningEffect
    bl update_backgrounds_pos
    bl load_doors
    bl check_hatch_lock_events
    movs r0, #0
    bl sub_08056b28
    movs r0, #1
    bl sub_08056b28
    movs r0, #2
    bl sub_08056b28
    bl AnimatedGraphicsLoad
    ldr r1, lbl_08057dbc @ =0x02007000
    ldr r2, lbl_08057dc0 @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_08057dc4 @ =0x04000008
    ldr r2, lbl_08057dc8 @ =gIoRegistersBackup
    ldrh r0, [r2, #0xa]
    strh r0, [r1]
    adds r1, #6
    ldrh r0, [r2, #0x10]
    strh r0, [r1]
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057d9c: .4byte gBG0XPosition
lbl_08057da0: .4byte gBG0YPosition
lbl_08057da4: .4byte gBG1XPosition
lbl_08057da8: .4byte gBG1YPosition
lbl_08057dac: .4byte gBG2XPosition
lbl_08057db0: .4byte gBG2YPosition
lbl_08057db4: .4byte gCurrentArea
lbl_08057db8: .4byte gCurrentRoom
lbl_08057dbc: .4byte 0x02007000
lbl_08057dc0: .4byte 0x06003000
lbl_08057dc4: .4byte 0x04000008
lbl_08057dc8: .4byte gIoRegistersBackup

    thumb_func_start setup_clipdata_code
setup_clipdata_code: @ 0x08057dcc
    ldr r1, lbl_08057de4 @ =0x040000d4
    ldr r0, lbl_08057de8 @ =sub_08057f7c
    str r0, [r1]
    ldr r2, lbl_08057dec @ =gNonGameplayRAM
    str r2, [r1, #4]
    ldr r0, lbl_08057df0 @ =0x80000140
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08057df4 @ =gClipdataCodePointer
    adds r2, #1
    str r2, [r0]
    bx lr
    .align 2, 0
lbl_08057de4: .4byte 0x040000d4
lbl_08057de8: .4byte sub_08057f7c
lbl_08057dec: .4byte gNonGameplayRAM
lbl_08057df0: .4byte 0x80000140
lbl_08057df4: .4byte gClipdataCodePointer

    thumb_func_start sub_08057df8
sub_08057df8: @ 0x08057df8
    push {r4, r5, r6, lr}
    sub sp, #0x14
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    mov r2, sp
    lsrs r0, r0, #0x16
    strh r0, [r2, #0x12]
    mov r0, sp
    lsrs r1, r1, #0x16
    strh r1, [r0, #0x10]
    ldr r4, lbl_08057e1c @ =gBGPointersAndDimensions
    ldrh r0, [r4, #0x1c]
    cmp r1, r0
    blo lbl_08057e24
    ldr r0, lbl_08057e20 @ =0x01000001
    b lbl_08057e72
    .align 2, 0
lbl_08057e1c: .4byte gBGPointersAndDimensions
lbl_08057e20: .4byte 0x01000001
lbl_08057e24:
    mov r0, sp
    ldrh r0, [r0, #0x12]
    ldrh r1, [r4, #0x1e]
    cmp r0, r1
    bhs lbl_08057e70
    ldr r3, lbl_08057e68 @ =gTilemapAndClipPointers
    ldrh r2, [r4, #0x1c]
    mov r0, sp
    ldrh r0, [r0, #0x12]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1, #0x10]
    adds r0, r0, r1
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    ldr r0, [r3, #4]
    adds r0, r0, r1
    ldrb r0, [r0]
    str r0, [sp]
    movs r0, #0x3f
    ands r5, r0
    str r5, [sp, #8]
    ands r6, r0
    str r6, [sp, #4]
    movs r0, #0
    str r0, [sp, #0xc]
    ldr r0, lbl_08057e6c @ =gClipdataCodePointer
    ldr r1, [r0]
    mov r0, sp
    bl _call_via_r1
    b lbl_08057e72
    .align 2, 0
lbl_08057e68: .4byte gTilemapAndClipPointers
lbl_08057e6c: .4byte gClipdataCodePointer
lbl_08057e70:
    movs r0, #0
lbl_08057e72:
    add sp, #0x14
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ClipdataProcess
ClipdataProcess: @ 0x08057e7c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x14
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    mov r8, r2
    mov r2, sp
    lsrs r0, r0, #0x16
    movs r4, #0
    movs r3, #0
    strh r0, [r2, #0x12]
    mov r0, sp
    lsrs r1, r1, #0x16
    strh r1, [r0, #0x10]
    ldr r2, lbl_08057ec0 @ =gBGPointersAndDimensions
    ldrh r0, [r2, #0x1c]
    cmp r1, r0
    bhs lbl_08057eb0
    mov r0, sp
    ldrh r0, [r0, #0x12]
    ldrh r2, [r2, #0x1e]
    cmp r0, r2
    blo lbl_08057ecc
lbl_08057eb0:
    ldr r0, lbl_08057ec4 @ =gCurrentAffectingClipdata
    strh r3, [r0]
    strh r3, [r0, #2]
    ldr r0, lbl_08057ec8 @ =gCurrentClipdataAffectingAction
    strb r4, [r0]
    movs r0, #0
    b lbl_08057f5e
    .align 2, 0
lbl_08057ec0: .4byte gBGPointersAndDimensions
lbl_08057ec4: .4byte gCurrentAffectingClipdata
lbl_08057ec8: .4byte gCurrentClipdataAffectingAction
lbl_08057ecc:
    ldr r2, lbl_08057ef0 @ =gCurrentClipdataAffectingAction
    ldrb r1, [r2]
    cmp r1, #0
    bne lbl_08057ef8
    movs r0, #2
    str r0, [sp, #0xc]
    ldr r0, lbl_08057ef4 @ =gCurrentAffectingClipdata
    strh r1, [r0]
    strh r1, [r0, #2]
    mov r0, sp
    ldrh r1, [r0, #0x12]
    ldrh r2, [r0, #0x10]
    adds r0, r7, #0
    movs r3, #2
    bl check_current_affecting_hazard_and_very_special_clipdata
    b lbl_08057f0c
    .align 2, 0
lbl_08057ef0: .4byte gCurrentClipdataAffectingAction
lbl_08057ef4: .4byte gCurrentAffectingClipdata
lbl_08057ef8:
    cmp r1, #5
    bls lbl_08057f08
    movs r0, #1
    str r0, [sp, #0xc]
    cmp r1, #6
    bne lbl_08057f0c
    strb r4, [r2]
    b lbl_08057f0c
lbl_08057f08:
    movs r0, #2
    str r0, [sp, #0xc]
lbl_08057f0c:
    ldr r2, lbl_08057f6c @ =gBGPointersAndDimensions
    mov r0, sp
    ldrh r5, [r0, #0x12]
    ldrh r0, [r2, #0x1c]
    muls r0, r5, r0
    mov r1, sp
    ldrh r3, [r1, #0x10]
    adds r0, r0, r3
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    ldr r6, lbl_08057f70 @ =gCurrentClipdataAffectingAction
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_08057f3a
    adds r2, r4, #0
    adds r0, r5, #0
    adds r1, r3, #0
    bl BlockApplyCCAA
    movs r0, #0
    strb r0, [r6]
lbl_08057f3a:
    ldr r0, lbl_08057f74 @ =gTilemapAndClipPointers
    ldr r0, [r0, #4]
    adds r0, r0, r4
    ldrb r0, [r0]
    str r0, [sp]
    movs r1, #0x3f
    adds r0, r7, #0
    ands r0, r1
    str r0, [sp, #8]
    mov r0, r8
    ands r0, r1
    str r0, [sp, #4]
    ldr r0, lbl_08057f78 @ =gClipdataCodePointer
    ldr r1, [r0]
    mov r0, sp
    bl _call_via_r1
    adds r4, r0, #0
lbl_08057f5e:
    add sp, #0x14
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08057f6c: .4byte gBGPointersAndDimensions
lbl_08057f70: .4byte gCurrentClipdataAffectingAction
lbl_08057f74: .4byte gTilemapAndClipPointers
lbl_08057f78: .4byte gClipdataCodePointer

    thumb_func_start sub_08057f7c
sub_08057f7c: @ 0x08057f7c
    push {lr}
    adds r2, r0, #0
    movs r1, #0
    ldr r0, [r2]
    cmp r0, #0xc
    bhi lbl_08058078
    lsls r0, r0, #2
    ldr r1, lbl_08057f94 @ =lbl_08057f98
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08057f94: .4byte lbl_08057f98
lbl_08057f98: @ jump table
    .4byte lbl_0805804a @ case 0
    .4byte lbl_08057fcc @ case 1
    .4byte lbl_08057fd4 @ case 2
    .4byte lbl_08057fe4 @ case 3
    .4byte lbl_08057ff8 @ case 4
    .4byte lbl_0805800a @ case 5
    .4byte lbl_0805801e @ case 6
    .4byte lbl_08058034 @ case 7
    .4byte lbl_0805804e @ case 8
    .4byte lbl_08058058 @ case 9
    .4byte lbl_08058062 @ case 10
    .4byte lbl_0805806e @ case 11
    .4byte lbl_0805804a @ case 12
lbl_08057fcc:
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057fd4:
    ldr r1, [r2, #8]
    ldr r0, [r2, #4]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057fe4:
    ldr r0, [r2, #4]
    movs r1, #0x3f
    subs r1, r1, r0
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057ff8:
    ldr r0, [r2, #4]
    asrs r0, r0, #1
    ldr r1, [r2, #8]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805800a:
    ldr r0, [r2, #4]
    adds r0, #0x3f
    asrs r0, r0, #1
    ldr r1, [r2, #8]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805801e:
    ldr r0, [r2, #4]
    asrs r0, r0, #1
    movs r1, #0x3f
    subs r1, r1, r0
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08058034:
    ldr r0, [r2, #4]
    movs r1, #0x3f
    subs r1, r1, r0
    asrs r1, r1, #1
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805804a:
    ldr r1, [r2]
    b lbl_08058078
lbl_0805804e:
    ldr r0, [r2, #0xc]
    cmp r0, #1
    ble lbl_0805806e
    movs r0, #0
    b lbl_08058068
lbl_08058058:
    ldr r0, [r2, #0xc]
    cmp r0, #1
    bgt lbl_0805806e
    movs r0, #0
    b lbl_08058068
lbl_08058062:
    ldr r0, [r2, #0xc]
    cmp r0, #0
    bne lbl_0805806e
lbl_08058068:
    str r0, [r2]
    movs r1, #0
    b lbl_08058078
lbl_0805806e:
    movs r0, #1
    str r0, [r2]
    movs r1, #0x80
    lsls r1, r1, #0x11
lbl_08058076:
    orrs r1, r0
lbl_08058078:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_hazard_at_pos
check_hazard_at_pos: @ 0x08058080
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    ldr r3, lbl_080580a8 @ =gCurrentAffectingClipdata
    movs r2, #0
    strh r2, [r3]
    strh r2, [r3, #2]
    lsrs r3, r0, #0x16
    lsrs r2, r1, #0x16
    ldr r0, lbl_080580ac @ =gBGPointersAndDimensions
    ldrh r1, [r0, #0x1e]
    cmp r3, r1
    bhs lbl_080580a2
    ldrh r0, [r0, #0x1c]
    cmp r2, r0
    blo lbl_080580b0
lbl_080580a2:
    movs r0, #0
    b lbl_080580ba
    .align 2, 0
lbl_080580a8: .4byte gCurrentAffectingClipdata
lbl_080580ac: .4byte gBGPointersAndDimensions
lbl_080580b0:
    adds r0, r4, #0
    adds r1, r3, #0
    movs r3, #0
    bl check_current_affecting_hazard_and_very_special_clipdata
lbl_080580ba:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start check_current_affecting_hazard_and_very_special_clipdata
check_current_affecting_hazard_and_very_special_clipdata: @ 0x080580c0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r6, r3, #0x18
    ldr r4, lbl_08058100 @ =gTilemapAndClipPointers
    ldr r3, lbl_08058104 @ =gBGPointersAndDimensions
    ldrh r0, [r3, #0x1c]
    muls r0, r1, r0
    adds r0, r0, r2
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r4, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r5, [r0]
    cmp r5, #0
    beq lbl_0805810c
    cmp r5, #0xf
    bgt lbl_0805810c
    ldr r1, lbl_08058108 @ =0x083458e4
    lsls r0, r5, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    b lbl_0805810e
    .align 2, 0
lbl_08058100: .4byte gTilemapAndClipPointers
lbl_08058104: .4byte gBGPointersAndDimensions
lbl_08058108: .4byte 0x083458e4
lbl_0805810c:
    movs r4, #0
lbl_0805810e:
    cmp r6, #0
    bne lbl_0805812c
    subs r0, r4, #1
    cmp r0, #1
    bhi lbl_0805812c
    ldr r0, lbl_08058144 @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1d
    beq lbl_0805812c
    adds r0, r4, #0
    bl check_cant_use_elevator
    cmp r0, #0
    beq lbl_0805812c
    movs r4, #0
lbl_0805812c:
    ldr r0, lbl_08058148 @ =gCurrentAffectingClipdata
    strh r4, [r0]
    movs r4, #0
    adds r2, r5, #0
    subs r2, #0x40
    adds r5, r0, #0
    cmp r2, #3
    bhi lbl_08058150
    ldr r1, lbl_0805814c @ =0x08345924
    lsls r0, r2, #1
    adds r0, r0, r1
    b lbl_0805818a
    .align 2, 0
lbl_08058144: .4byte gSamusData
lbl_08058148: .4byte gCurrentAffectingClipdata
lbl_0805814c: .4byte 0x08345924
lbl_08058150:
    ldr r1, lbl_0805817c @ =gCurrentRoomEntry
    ldrb r0, [r1, #1]
    cmp r0, #0
    beq lbl_0805818c
    ldrb r0, [r1, #0x14]
    cmp r0, #0
    beq lbl_0805818c
    cmp r0, #7
    bhi lbl_0805818c
    ldr r3, lbl_08058180 @ =0x08345904
    lsls r1, r0, #2
    adds r0, r3, #2
    adds r2, r1, r0
    ldrh r0, [r2]
    cmp r0, #0
    beq lbl_08058188
    ldr r0, lbl_08058184 @ =gEffectYPosition
    ldrh r0, [r0]
    cmp r0, r7
    bhi lbl_08058188
    ldrh r4, [r2]
    b lbl_0805818c
    .align 2, 0
lbl_0805817c: .4byte gCurrentRoomEntry
lbl_08058180: .4byte 0x08345904
lbl_08058184: .4byte gEffectYPosition
lbl_08058188:
    adds r0, r1, r3
lbl_0805818a:
    ldrh r4, [r0]
lbl_0805818c:
    strh r4, [r5, #2]
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    ldrh r1, [r5, #2]
    orrs r0, r1
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_cant_use_elevator
check_cant_use_elevator: @ 0x0805819c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080581e0 @ =gLastElevatorUsed
    movs r1, #0
    strb r1, [r0, #2]
    movs r2, #0
    strh r1, [r0]
    strb r2, [r0, #3]
    movs r4, #0
    movs r5, #8
    ldr r0, lbl_080581e4 @ =gCurrentArea
    mov sb, r0
    ldr r1, lbl_080581e8 @ =0x08345934
    mov r8, r1
    mov r6, r8
    adds r6, #0x44
    movs r7, #0x40
lbl_080581c2:
    ldr r0, lbl_080581e4 @ =gCurrentArea
    ldr r1, lbl_080581e8 @ =0x08345934
    adds r1, r7, r1
    ldrb r0, [r0]
    ldrb r2, [r1]
    cmp r0, r2
    bne lbl_080581f0
    ldr r0, lbl_080581ec @ =gCurrentRoom
    ldrb r0, [r0]
    ldrb r1, [r1, #1]
    cmp r0, r1
    bne lbl_080581f0
    movs r4, #1
    b lbl_0805820c
    .align 2, 0
lbl_080581e0: .4byte gLastElevatorUsed
lbl_080581e4: .4byte gCurrentArea
lbl_080581e8: .4byte 0x08345934
lbl_080581ec: .4byte gCurrentRoom
lbl_080581f0:
    mov r1, sb
    ldrb r0, [r1]
    ldrb r2, [r6]
    cmp r0, r2
    bne lbl_08058208
    ldr r0, lbl_08058228 @ =gCurrentRoom
    ldrb r0, [r0]
    ldrb r1, [r6, #1]
    cmp r0, r1
    bne lbl_08058208
    movs r4, #1
    rsbs r4, r4, #0
lbl_08058208:
    cmp r4, #0
    beq lbl_08058240
lbl_0805820c:
    cmp r5, #8
    bne lbl_0805822e
    movs r0, #3
    movs r1, #0x41
    bl EventFunction
    cmp r0, #0
    beq lbl_0805822c
    mov r6, r8
    adds r6, #0x34
    movs r7, #0x30
    movs r5, #6
    b lbl_0805822e
    .align 2, 0
lbl_08058228: .4byte gCurrentRoom
lbl_0805822c:
    movs r4, #0
lbl_0805822e:
    cmp r4, #0
    beq lbl_08058240
    ldr r0, lbl_0805823c @ =gLastElevatorUsed
    strb r5, [r0, #2]
    strb r4, [r0, #3]
    b lbl_0805824a
    .align 2, 0
lbl_0805823c: .4byte gLastElevatorUsed
lbl_08058240:
    subs r6, #8
    subs r7, #8
    subs r5, #1
    cmp r5, #0
    bgt lbl_080581c2
lbl_0805824a:
    movs r0, #0
    cmp r4, #0
    bne lbl_08058252
    movs r0, #1
lbl_08058252:
    adds r4, r0, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_for_ground_effect_clipdata
check_for_ground_effect_clipdata: @ 0x08058260
    push {lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r3, r0, #0x16
    lsrs r1, r1, #0x16
    ldr r2, lbl_0805827c @ =gBGPointersAndDimensions
    ldrh r0, [r2, #0x1e]
    cmp r3, r0
    bge lbl_08058278
    ldrh r0, [r2, #0x1c]
    cmp r1, r0
    blt lbl_08058280
lbl_08058278:
    movs r0, #0
    b lbl_080582c0
    .align 2, 0
lbl_0805827c: .4byte gBGPointersAndDimensions
lbl_08058280:
    muls r0, r3, r0
    adds r0, r0, r1
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    cmp r0, #0
    beq lbl_0805829a
    movs r2, #0
    b lbl_080582a4
lbl_0805829a:
    ldr r0, lbl_080582b4 @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r2, [r0]
lbl_080582a4:
    adds r1, r2, #0
    subs r1, #0x50
    cmp r1, #4
    bhi lbl_080582bc
    ldr r0, lbl_080582b8 @ =0x0834592c
    adds r0, r1, r0
    ldrb r2, [r0]
    b lbl_080582be
    .align 2, 0
lbl_080582b4: .4byte gTilemapAndClipPointers
lbl_080582b8: .4byte 0x0834592c
lbl_080582bc:
    movs r2, #0
lbl_080582be:
    adds r0, r2, #0
lbl_080582c0:
    pop {r1}
    bx r1

    thumb_func_start process_scrolls
process_scrolls: @ 0x080582c4
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    bl update_gCurrentScrolls
    ldr r0, lbl_08058320 @ =gCamera
    ldrh r7, [r0]
    ldrh r6, [r0, #2]
    ldr r4, lbl_08058324 @ =gCurrentScrolls
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080582ee
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_x
    adds r7, r0, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_y
    adds r6, r0, #0
lbl_080582ee:
    adds r4, #0xc
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0805830e
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_x
    adds r0, r7, r0
    asrs r7, r0, #1
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_y
    adds r0, r6, r0
    asrs r6, r0, #1
lbl_0805830e:
    lsls r0, r7, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r6, #0x10
    lsrs r1, r1, #0x10
    bl ScrollScreen
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058320: .4byte gCamera
lbl_08058324: .4byte gCurrentScrolls

    thumb_func_start ScrollScreen
ScrollScreen: @ 0x08058328
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    ldr r1, lbl_08058364 @ =gCamera
    strh r4, [r1]
    strh r2, [r1, #2]
    ldr r0, lbl_08058368 @ =gGameModeSub1
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_080583dc
    ldr r0, lbl_0805836c @ =gBG1YPosition
    adds r3, r0, #0
    ldrh r0, [r3]
    cmp r2, r0
    beq lbl_08058390
    ldrh r0, [r3]
    subs r1, r2, r0
    cmp r1, #0
    ble lbl_08058374
    ldr r0, lbl_08058370 @ =gUnk_3005714
    movs r2, #6
    ldrsh r0, [r0, r2]
    cmp r0, r1
    bge lbl_08058380
    b lbl_0805837e
    .align 2, 0
lbl_08058364: .4byte gCamera
lbl_08058368: .4byte gGameModeSub1
lbl_0805836c: .4byte gBG1YPosition
lbl_08058370: .4byte gUnk_3005714
lbl_08058374:
    ldr r0, lbl_0805838c @ =gUnk_3005714
    movs r2, #4
    ldrsh r0, [r0, r2]
    cmp r0, r1
    ble lbl_08058380
lbl_0805837e:
    adds r1, r0, #0
lbl_08058380:
    strb r1, [r5, #5]
    ldrh r0, [r3]
    adds r0, r0, r1
    strh r0, [r3]
    b lbl_08058394
    .align 2, 0
lbl_0805838c: .4byte gUnk_3005714
lbl_08058390:
    movs r0, #0
    strb r0, [r5, #5]
lbl_08058394:
    ldr r0, lbl_080583b4 @ =gBG1XPosition
    adds r2, r0, #0
    ldrh r3, [r2]
    cmp r4, r3
    beq lbl_080583d8
    ldrh r0, [r2]
    subs r1, r4, r0
    cmp r1, #0
    ble lbl_080583bc
    ldr r0, lbl_080583b8 @ =gUnk_3005714
    movs r3, #2
    ldrsh r0, [r0, r3]
    cmp r0, r1
    bge lbl_080583c8
    b lbl_080583c6
    .align 2, 0
lbl_080583b4: .4byte gBG1XPosition
lbl_080583b8: .4byte gUnk_3005714
lbl_080583bc:
    ldr r0, lbl_080583d4 @ =gUnk_3005714
    movs r3, #0
    ldrsh r0, [r0, r3]
    cmp r0, r1
    ble lbl_080583c8
lbl_080583c6:
    adds r1, r0, #0
lbl_080583c8:
    strb r1, [r5, #4]
    ldrh r0, [r2]
    adds r0, r0, r1
    strh r0, [r2]
    b lbl_080583dc
    .align 2, 0
lbl_080583d4: .4byte gUnk_3005714
lbl_080583d8:
    movs r0, #0
    strb r0, [r5, #4]
lbl_080583dc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start process_scroll_x
process_scroll_x: @ 0x080583e4
    push {r4, lr}
    adds r3, r0, #0
    ldrh r1, [r1]
    ldrh r2, [r3, #4]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r2, r4
    cmp r1, r0
    bge lbl_080583fa
    adds r0, r2, #0
    b lbl_08058418
lbl_080583fa:
    ldrh r2, [r3, #2]
    ldr r3, lbl_0805840c @ =0xfffffe20
    adds r0, r2, r3
    cmp r1, r0
    ble lbl_08058414
    ldr r4, lbl_08058410 @ =0xfffffc40
    adds r0, r2, r4
    b lbl_08058418
    .align 2, 0
lbl_0805840c: .4byte 0xfffffe20
lbl_08058410: .4byte 0xfffffc40
lbl_08058414:
    ldr r2, lbl_08058420 @ =0xfffffe20
    adds r0, r1, r2
lbl_08058418:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08058420: .4byte 0xfffffe20

    thumb_func_start process_scroll_y
process_scroll_y: @ 0x08058424
    push {r4, lr}
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r0, #2
    bne lbl_08058468
    ldrh r1, [r1, #2]
    ldrh r3, [r2, #6]
    movs r4, #0xc0
    lsls r4, r4, #1
    adds r0, r3, r4
    cmp r1, r0
    blt lbl_0805844e
    ldrh r2, [r2, #8]
    ldr r4, lbl_08058454 @ =0xffffff00
    adds r0, r2, r4
    cmp r1, r0
    ble lbl_0805845c
    ldr r1, lbl_08058458 @ =0xfffffd80
    adds r0, r2, r1
    cmp r0, r3
    bge lbl_0805846e
lbl_0805844e:
    adds r0, r3, #0
    b lbl_0805846e
    .align 2, 0
lbl_08058454: .4byte 0xffffff00
lbl_08058458: .4byte 0xfffffd80
lbl_0805845c:
    ldr r2, lbl_08058464 @ =0xfffffe80
    adds r0, r1, r2
    b lbl_0805846e
    .align 2, 0
lbl_08058464: .4byte 0xfffffe80
lbl_08058468:
    ldrh r0, [r2, #8]
    ldr r4, lbl_08058474 @ =0xfffffd80
    adds r0, r0, r4
lbl_0805846e:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08058474: .4byte 0xfffffd80

    thumb_func_start load_scrolls
load_scrolls: @ 0x08058478
    push {r4, r5, lr}
    ldr r1, lbl_0805849c @ =0x0875fd28
    ldr r0, lbl_080584a0 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r2, [r0]
    ldr r3, [r2]
    ldr r0, lbl_080584a4 @ =gCurrentRoom
    ldrb r1, [r3]
    adds r5, r0, #0
    ldr r4, lbl_080584a8 @ =gCurrentRoomScrollDataPointer
    ldrb r0, [r5]
    cmp r1, r0
    bne lbl_080584b0
    str r3, [r4]
    b lbl_080584c6
    .align 2, 0
lbl_0805849c: .4byte 0x0875fd28
lbl_080584a0: .4byte gCurrentArea
lbl_080584a4: .4byte gCurrentRoom
lbl_080584a8: .4byte gCurrentRoomScrollDataPointer
lbl_080584ac:
    str r1, [r4]
    b lbl_080584cc
lbl_080584b0:
    ldr r1, [r2]
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_080584ac
    adds r2, #4
    ldr r1, [r2]
    ldrb r0, [r1]
    ldrb r3, [r5]
    cmp r0, r3
    bne lbl_080584b0
    str r1, [r4]
lbl_080584c6:
    ldr r1, lbl_080584d4 @ =gCurrentRoomEntry
    movs r0, #3
    strb r0, [r1, #5]
lbl_080584cc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080584d4: .4byte gCurrentRoomEntry

    thumb_func_start update_gCurrentScrolls
update_gCurrentScrolls: @ 0x080584d8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x10
    ldr r2, lbl_08058554 @ =gCurrentScrolls
    movs r1, #0
    strb r1, [r2]
    strb r1, [r2, #0xc]
    ldrh r1, [r0]
    lsrs r1, r1, #6
    mov r8, r1
    ldrh r0, [r0, #2]
    subs r0, #1
    lsls r0, r0, #0xa
    lsrs r0, r0, #0x10
    mov ip, r0
    ldr r0, lbl_08058558 @ =gCurrentRoomScrollDataPointer
    ldr r0, [r0]
    adds r0, #1
    ldrb r5, [r0]
    adds r4, r0, #1
    adds r7, r2, #0
    cmp r5, #0
    bne lbl_0805850c
    b lbl_08058616
lbl_0805850c:
    ldr r6, lbl_0805855c @ =gBGPointersAndDimensions
    mov sb, r7
lbl_08058510:
    mov r0, sb
    adds r0, #0x18
    cmp r2, r0
    bne lbl_0805851a
    b lbl_0805862c
lbl_0805851a:
    movs r0, #0
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #2
    str r0, [sp, #8]
    movs r0, #3
    str r0, [sp, #0xc]
    ldrb r0, [r4, #4]
    cmp r0, #0xff
    beq lbl_08058560
    ldrb r0, [r4, #7]
    cmp r0, #0xff
    beq lbl_08058560
    ldrb r1, [r4, #5]
    ldrh r0, [r6, #0x1c]
    muls r0, r1, r0
    ldrb r1, [r4, #4]
    adds r3, r0, r1
    ldr r1, [r6, #0x18]
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08058586
    ldrb r0, [r4, #6]
    cmp r0, #0xff
    beq lbl_08058586
    b lbl_0805857c
    .align 2, 0
lbl_08058554: .4byte gCurrentScrolls
lbl_08058558: .4byte gCurrentRoomScrollDataPointer
lbl_0805855c: .4byte gBGPointersAndDimensions
lbl_08058560:
    ldr r0, lbl_0805863c @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1d
    bne lbl_08058586
    ldrb r0, [r4, #7]
    cmp r0, #0xff
    beq lbl_08058586
    ldrb r0, [r4, #6]
    subs r0, #2
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_08058586
    ldrb r0, [r4, #6]
lbl_0805857c:
    lsls r0, r0, #2
    mov r3, sp
    adds r1, r3, r0
    movs r0, #7
    str r0, [r1]
lbl_08058586:
    ldr r0, [sp]
    adds r0, r4, r0
    ldrb r1, [r0]
    cmp r1, r8
    bhi lbl_0805860c
    ldr r0, [sp, #4]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp r8, r0
    bhi lbl_0805860c
    ldr r0, [sp, #8]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp r0, ip
    bhi lbl_0805860c
    ldr r0, [sp, #0xc]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp ip, r0
    bhi lbl_0805860c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0805860c
    lsls r0, r1, #6
    cmp r0, #0x80
    bge lbl_080585bc
    movs r0, #0x80
lbl_080585bc:
    strh r0, [r2, #4]
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    adds r3, r0, #0
    subs r3, #0x80
    ldr r0, [sp, #4]
    adds r0, r4, r0
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #6
    adds r1, r3, #0
    cmp r0, r3
    bge lbl_080585d8
    adds r1, r0, #0
lbl_080585d8:
    strh r1, [r2, #2]
    ldr r0, [sp, #8]
    adds r0, r4, r0
    ldrb r0, [r0]
    lsls r0, r0, #6
    cmp r0, #0x80
    bge lbl_080585e8
    movs r0, #0x80
lbl_080585e8:
    strh r0, [r2, #6]
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    adds r3, r0, #0
    subs r3, #0x80
    ldr r0, [sp, #0xc]
    adds r0, r4, r0
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #6
    adds r1, r3, #0
    cmp r0, r3
    bge lbl_08058604
    adds r1, r0, #0
lbl_08058604:
    strh r1, [r2, #8]
    movs r0, #2
    strb r0, [r2]
    adds r2, #0xc
lbl_0805860c:
    adds r4, #8
    subs r5, #1
    cmp r5, #0
    beq lbl_08058616
    b lbl_08058510
lbl_08058616:
    ldrb r0, [r7]
    cmp r0, #0
    bne lbl_0805862c
    ldrb r0, [r7, #0xc]
    cmp r0, #0
    bne lbl_0805862c
    strb r0, [r7]
    strh r0, [r7, #2]
    strh r0, [r7, #4]
    strh r0, [r7, #6]
    strh r0, [r7, #8]
lbl_0805862c:
    add sp, #0x10
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805863c: .4byte gSamusData

    thumb_func_start ScrollProcessGeneral
ScrollProcessGeneral: @ 0x08058640
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805867c @ =gColorFading
    ldrb r0, [r0, #1]
    cmp r0, #0
    beq lbl_0805864e
    b lbl_0805881e
lbl_0805864e:
    ldr r0, lbl_08058680 @ =gLockScreen
    ldrb r1, [r0]
    adds r4, r0, #0
    cmp r1, #0
    bne lbl_080586c8
    ldr r2, lbl_08058684 @ =gSamusData
    ldrh r1, [r2, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    ldrh r0, [r2, #0x12]
    orrs r0, r1
    str r0, [sp]
    ldrb r0, [r2]
    adds r1, r0, #0
    cmp r1, #0x15
    beq lbl_08058672
    cmp r1, #0x3d
    bne lbl_0805868c
lbl_08058672:
    ldr r1, lbl_08058688 @ =gSlowScrollingTimer
    movs r0, #1
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_0805867c: .4byte gColorFading
lbl_08058680: .4byte gLockScreen
lbl_08058684: .4byte gSamusData
lbl_08058688: .4byte gSlowScrollingTimer
lbl_0805868c:
    subs r0, #0x1a
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_080586a4
    ldr r1, lbl_080586a0 @ =gSlowScrollingTimer
    movs r0, #8
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586a0: .4byte gSlowScrollingTimer
lbl_080586a4:
    cmp r1, #0x1c
    bne lbl_080586b4
    ldr r1, lbl_080586b0 @ =gSlowScrollingTimer
    movs r0, #0x14
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586b0: .4byte gSlowScrollingTimer
lbl_080586b4:
    ldr r1, lbl_080586c4 @ =gSlowScrollingTimer
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_080586f4
    subs r0, #1
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586c4: .4byte gSlowScrollingTimer
lbl_080586c8:
    cmp r1, #1
    bne lbl_080586d8
    ldrh r1, [r4, #4]
    lsls r1, r1, #0x10
    ldrh r0, [r4, #2]
    orrs r0, r1
    str r0, [sp]
    b lbl_080586f4
lbl_080586d8:
    ldr r2, lbl_08058740 @ =gSamusData
    ldrh r1, [r2, #0x12]
    ldrh r0, [r4, #2]
    adds r1, r1, r0
    ldrh r0, [r4, #4]
    adds r0, #1
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    lsls r0, r0, #0xf
    lsrs r0, r0, #0x10
    lsls r0, r0, #0x10
    lsrs r1, r1, #1
    orrs r1, r0
    str r1, [sp]
lbl_080586f4:
    ldr r2, [sp]
    lsrs r1, r2, #0x10
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08058708
    ldr r0, lbl_08058744 @ =0x0000ffff
    ands r2, r0
    str r2, [sp]
lbl_08058708:
    ldr r3, lbl_08058748 @ =gUnk_3005714
    ldr r2, lbl_0805874c @ =0x08345988
    ldr r0, [r2]
    ldr r1, [r2, #4]
    str r0, [r3]
    str r1, [r3, #4]
    ldrb r0, [r4]
    adds r4, r3, #0
    cmp r0, #0
    bne lbl_080587a2
    ldr r0, lbl_08058750 @ =gSlowScrollingTimer
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0805879a
    ldr r2, lbl_08058740 @ =gSamusData
    ldrh r1, [r2, #0x12]
    ldr r0, lbl_08058754 @ =gPreviousXPosition
    ldrh r0, [r0]
    subs r1, r1, r0
    cmp r1, #0
    ble lbl_08058758
    movs r5, #2
    ldrsh r0, [r3, r5]
    cmp r1, r0
    blt lbl_08058768
    adds r0, r1, #4
    strh r0, [r3, #2]
    b lbl_08058768
    .align 2, 0
lbl_08058740: .4byte gSamusData
lbl_08058744: .4byte 0x0000ffff
lbl_08058748: .4byte gUnk_3005714
lbl_0805874c: .4byte 0x08345988
lbl_08058750: .4byte gSlowScrollingTimer
lbl_08058754: .4byte gPreviousXPosition
lbl_08058758:
    cmp r1, #0
    bge lbl_08058768
    movs r5, #0
    ldrsh r0, [r3, r5]
    cmp r1, r0
    bgt lbl_08058768
    subs r0, r1, #4
    strh r0, [r3]
lbl_08058768:
    ldrh r0, [r2, #0x14]
    ldr r1, lbl_08058784 @ =gPreviousYPosition
    ldrh r1, [r1]
    subs r1, r0, r1
    cmp r1, #0
    ble lbl_08058788
    movs r2, #6
    ldrsh r0, [r4, r2]
    cmp r1, r0
    blt lbl_080587a2
    adds r0, r1, #4
    strh r0, [r4, #6]
    b lbl_080587a2
    .align 2, 0
lbl_08058784: .4byte gPreviousYPosition
lbl_08058788:
    cmp r1, #0
    bge lbl_080587a2
    movs r5, #4
    ldrsh r0, [r4, r5]
    cmp r1, r0
    bgt lbl_080587a2
    subs r0, r1, #4
    strh r0, [r4, #4]
    b lbl_080587a2
lbl_0805879a:
    ldr r0, [r2, #8]
    ldr r1, [r2, #0xc]
    str r0, [r3]
    str r1, [r3, #4]
lbl_080587a2:
    ldr r0, lbl_080587c4 @ =gDisableScrolling
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805881e
    ldr r0, lbl_080587c8 @ =gUnk_300007f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080587d0
    ldr r0, lbl_080587cc @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #6
    bne lbl_080587d0
    mov r0, sp
    bl sub_08059008
    b lbl_080587ea
    .align 2, 0
lbl_080587c4: .4byte gDisableScrolling
lbl_080587c8: .4byte gUnk_300007f
lbl_080587cc: .4byte gGameModeSub1
lbl_080587d0:
    ldr r0, lbl_080587e0 @ =gCurrentRoomEntry
    ldrb r0, [r0, #5]
    cmp r0, #3
    bne lbl_080587e4
    mov r0, sp
    bl process_scrolls
    b lbl_080587ea
    .align 2, 0
lbl_080587e0: .4byte gCurrentRoomEntry
lbl_080587e4:
    mov r0, sp
    bl ScrollWithNoScrolls
lbl_080587ea:
    mov r0, sp
    bl ScrollBG2
    ldr r0, lbl_08058828 @ =gBG0Movement
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08058808
    ldr r0, lbl_0805882c @ =gCurrentRoomEntry
    ldrb r1, [r0, #1]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08058808
    bl automatic_scroll_bg0
lbl_08058808:
    mov r0, sp
    bl update_effect_and_haze_pos
    bl ScrollBG3
    ldr r0, lbl_08058830 @ =gBG3Movement
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805881e
    bl automatic_scroll_bg3
lbl_0805881e:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058828: .4byte gBG0Movement
lbl_0805882c: .4byte gCurrentRoomEntry
lbl_08058830: .4byte gBG3Movement

    thumb_func_start ScrollWithNoScrolls
ScrollWithNoScrolls: @ 0x08058834
    push {r4, lr}
    adds r4, r0, #0
    bl ScrollWithNoScrollsX
    adds r0, r4, #0
    bl ScrollWithNoScrollsY
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start ScrollWithNoScrollsY
ScrollWithNoScrollsY: @ 0x08058848
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08058860 @ =gLockScreen
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805886c
    ldr r2, lbl_08058864 @ =gSamusData
    ldrh r1, [r2, #0x14]
    ldr r0, lbl_08058868 @ =gPreviousYPosition
    ldrh r0, [r0]
    subs r1, r1, r0
    b lbl_08058870
    .align 2, 0
lbl_08058860: .4byte gLockScreen
lbl_08058864: .4byte gSamusData
lbl_08058868: .4byte gPreviousYPosition
lbl_0805886c:
    movs r1, #0
    ldr r2, lbl_08058898 @ =gSamusData
lbl_08058870:
    ldrb r2, [r2]
    adds r0, r2, #0
    subs r0, #0x11
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_08058882
    cmp r2, #0x1c
    bne lbl_080588a4
lbl_08058882:
    ldr r1, lbl_0805889c @ =gScreenYOffset
    movs r0, #0
    ldrsb r0, [r1, r0]
    adds r0, #4
    adds r3, r1, #0
    cmp r0, #0x1f
    bgt lbl_080588a0
    ldrb r0, [r3]
    adds r0, #2
    b lbl_080588c6
    .align 2, 0
lbl_08058898: .4byte gSamusData
lbl_0805889c: .4byte gScreenYOffset
lbl_080588a0:
    movs r0, #0x20
    b lbl_080588c6
lbl_080588a4:
    ldr r3, lbl_080588c0 @ =gScreenYOffset
    cmp r1, #0
    bge lbl_080588c8
    movs r0, #0
    ldrsb r0, [r3, r0]
    adds r0, r0, r1
    cmp r0, #0
    ble lbl_080588c4
    lsrs r0, r1, #0x1f
    adds r0, r1, r0
    asrs r0, r0, #1
    ldrb r1, [r3]
    adds r0, r0, r1
    b lbl_080588c6
    .align 2, 0
lbl_080588c0: .4byte gScreenYOffset
lbl_080588c4:
    movs r0, #0
lbl_080588c6:
    strb r0, [r3]
lbl_080588c8:
    ldrh r2, [r4, #2]
    movs r1, #0
    ldrsb r1, [r3, r1]
    movs r0, #0x80
    lsls r0, r0, #2
    subs r0, r0, r1
    cmp r2, r0
    bge lbl_080588dc
    movs r3, #0x80
    b lbl_080588fe
lbl_080588dc:
    ldr r0, lbl_080588f0 @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0xe]
    lsls r0, r0, #6
    ldr r3, lbl_080588f4 @ =0xfffffe80
    adds r0, r0, r3
    subs r0, r0, r1
    cmp r2, r0
    ble lbl_080588f8
    adds r0, r0, r3
    b lbl_080588fc
    .align 2, 0
lbl_080588f0: .4byte gBGPointersAndDimensions
lbl_080588f4: .4byte 0xfffffe80
lbl_080588f8:
    ldr r4, lbl_08058918 @ =0xfffffe80
    adds r0, r2, r4
lbl_080588fc:
    adds r3, r0, r1
lbl_080588fe:
    ldr r2, lbl_0805891c @ =gCamera
    strh r3, [r2, #2]
    ldr r1, lbl_08058920 @ =gBG1YPosition
    ldrh r0, [r1]
    subs r3, r3, r0
    cmp r3, #0
    ble lbl_08058928
    ldr r0, lbl_08058924 @ =gUnk_3005714
    movs r4, #6
    ldrsh r0, [r0, r4]
    cmp r0, r3
    bge lbl_08058934
    b lbl_08058932
    .align 2, 0
lbl_08058918: .4byte 0xfffffe80
lbl_0805891c: .4byte gCamera
lbl_08058920: .4byte gBG1YPosition
lbl_08058924: .4byte gUnk_3005714
lbl_08058928:
    ldr r0, lbl_08058944 @ =gUnk_3005714
    movs r4, #4
    ldrsh r0, [r0, r4]
    cmp r3, r0
    bge lbl_08058934
lbl_08058932:
    adds r3, r0, #0
lbl_08058934:
    strb r3, [r2, #5]
    ldrh r0, [r1]
    adds r0, r0, r3
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058944: .4byte gUnk_3005714

    thumb_func_start ScrollWithNoScrollsX
ScrollWithNoScrollsX: @ 0x08058948
    push {r4, lr}
    adds r2, r0, #0
    movs r3, #0
    ldr r0, lbl_08058970 @ =gLockScreen
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08058988
    ldr r0, lbl_08058974 @ =gSamusPhysics
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_08058988
    ldr r0, lbl_08058978 @ =gSamusData
    ldrh r1, [r0, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0805897c
    movs r3, #0x80
    b lbl_08058988
    .align 2, 0
lbl_08058970: .4byte gLockScreen
lbl_08058974: .4byte gSamusPhysics
lbl_08058978: .4byte gSamusData
lbl_0805897c:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08058988
    movs r3, #0x80
    rsbs r3, r3, #0
lbl_08058988:
    ldr r0, lbl_080589a0 @ =gScreenXOffset
    strh r3, [r0]
    ldrh r2, [r2]
    movs r3, #0
    ldrsh r1, [r0, r3]
    movs r0, #0x98
    lsls r0, r0, #2
    subs r0, r0, r1
    cmp r2, r0
    bge lbl_080589a4
    movs r3, #0x80
    b lbl_080589ce
    .align 2, 0
lbl_080589a0: .4byte gScreenXOffset
lbl_080589a4:
    ldr r0, lbl_080589bc @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0xc]
    lsls r0, r0, #6
    ldr r4, lbl_080589c0 @ =0xfffffda0
    adds r0, r0, r4
    subs r0, r0, r1
    cmp r2, r0
    ble lbl_080589c8
    ldr r2, lbl_080589c4 @ =0xfffffe20
    adds r0, r0, r2
    b lbl_080589cc
    .align 2, 0
lbl_080589bc: .4byte gBGPointersAndDimensions
lbl_080589c0: .4byte 0xfffffda0
lbl_080589c4: .4byte 0xfffffe20
lbl_080589c8:
    ldr r3, lbl_080589e8 @ =0xfffffe20
    adds r0, r2, r3
lbl_080589cc:
    adds r3, r0, r1
lbl_080589ce:
    ldr r2, lbl_080589ec @ =gCamera
    strh r3, [r2]
    ldr r1, lbl_080589f0 @ =gBG1XPosition
    ldrh r0, [r1]
    subs r3, r3, r0
    cmp r3, #0
    ble lbl_080589f8
    ldr r0, lbl_080589f4 @ =gUnk_3005714
    movs r4, #2
    ldrsh r0, [r0, r4]
    cmp r0, r3
    bge lbl_08058a04
    b lbl_08058a02
    .align 2, 0
lbl_080589e8: .4byte 0xfffffe20
lbl_080589ec: .4byte gCamera
lbl_080589f0: .4byte gBG1XPosition
lbl_080589f4: .4byte gUnk_3005714
lbl_080589f8:
    ldr r0, lbl_08058a14 @ =gUnk_3005714
    movs r4, #0
    ldrsh r0, [r0, r4]
    cmp r3, r0
    bge lbl_08058a04
lbl_08058a02:
    adds r3, r0, #0
lbl_08058a04:
    strb r3, [r2, #4]
    ldrh r0, [r1]
    adds r0, r0, r3
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058a14: .4byte gUnk_3005714

    thumb_func_start update_effect_and_haze_pos
update_effect_and_haze_pos: @ 0x08058a18
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    movs r7, #0
    ldr r1, lbl_08058a4c @ =gCurrentRoomEntry
    ldrb r2, [r1, #1]
    movs r0, #0x10
    ands r0, r2
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    mov ip, r1
    cmp r3, #0
    beq lbl_08058a64
    cmp r2, #0x11
    beq lbl_08058a36
    b lbl_08058c4e
lbl_08058a36:
    ldr r1, lbl_08058a50 @ =gBG0XPosition
    ldr r0, lbl_08058a54 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #1
    strh r0, [r1]
    ldr r1, lbl_08058a58 @ =gBG0YPosition
    ldr r0, lbl_08058a5c @ =gBG1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r6, lbl_08058a60 @ =gEffectYPositionOffset
    b lbl_08058c64
    .align 2, 0
lbl_08058a4c: .4byte gCurrentRoomEntry
lbl_08058a50: .4byte gBG0XPosition
lbl_08058a54: .4byte gBG1XPosition
lbl_08058a58: .4byte gBG0YPosition
lbl_08058a5c: .4byte gBG1YPosition
lbl_08058a60: .4byte gEffectYPositionOffset
lbl_08058a64:
    mov r0, ip
    ldrh r1, [r0, #0x12]
    ldr r0, lbl_08058ab0 @ =0x0000ffff
    cmp r1, r0
    bne lbl_08058a70
    b lbl_08058b80
lbl_08058a70:
    ldr r1, lbl_08058ab4 @ =gBG0XPosition
    ldr r0, lbl_08058ab8 @ =gBG1XPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_08058abc @ =gEffectYPositionOffset
    movs r1, #0
    ldrsh r0, [r2, r1]
    mov r3, ip
    ldrh r3, [r3, #0x12]
    adds r0, r0, r3
    ldr r1, lbl_08058ac0 @ =gBG1YPosition
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r5, r0, #2
    ldr r0, lbl_08058ac4 @ =gWaterMovement
    ldrb r1, [r0]
    adds r6, r2, #0
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058af8
    ldr r0, lbl_08058ac8 @ =gPreventMovementTimer
    ldrh r0, [r0]
    ldr r3, lbl_08058acc @ =0x0875fd54
    cmp r0, #0
    bne lbl_08058aec
    ldrb r1, [r2, #2]
    movs r0, #2
    ldrsb r0, [r2, r0]
    cmp r0, #0
    beq lbl_08058ad0
    subs r0, r1, #1
    b lbl_08058aea
    .align 2, 0
lbl_08058ab0: .4byte 0x0000ffff
lbl_08058ab4: .4byte gBG0XPosition
lbl_08058ab8: .4byte gBG1XPosition
lbl_08058abc: .4byte gEffectYPositionOffset
lbl_08058ac0: .4byte gBG1YPosition
lbl_08058ac4: .4byte gWaterMovement
lbl_08058ac8: .4byte gPreventMovementTimer
lbl_08058acc: .4byte 0x0875fd54
lbl_08058ad0:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bls lbl_08058ae0
    strb r7, [r2, #1]
lbl_08058ae0:
    ldrb r0, [r2, #1]
    lsls r0, r0, #1
    adds r1, r3, #1
    adds r0, r0, r1
    ldrb r0, [r0]
lbl_08058aea:
    strb r0, [r2, #2]
lbl_08058aec:
    ldrb r0, [r2, #1]
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsb r1, [r0, r1]
    b lbl_08058afa
lbl_08058af8:
    movs r1, #0
lbl_08058afa:
    adds r0, r1, #0
    subs r0, #8
    lsls r0, r0, #2
    strb r0, [r2, #3]
    adds r5, r5, r1
    cmp r5, #0
    bge lbl_08058b3c
    ldr r2, lbl_08058b30 @ =gIoRegistersBackup
    ldrh r3, [r2, #0x12]
    movs r4, #0xc0
    lsls r4, r4, #8
    adds r0, r4, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08058b62
    ldrh r1, [r2, #0xa]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08058b62
    ldr r0, lbl_08058b34 @ =0x00003fff
    ands r0, r3
    strh r0, [r2, #0x12]
    ldr r1, lbl_08058b38 @ =0x04000008
    strh r0, [r1]
    b lbl_08058b62
    .align 2, 0
lbl_08058b30: .4byte gIoRegistersBackup
lbl_08058b34: .4byte 0x00003fff
lbl_08058b38: .4byte 0x04000008
lbl_08058b3c:
    ldr r2, lbl_08058b74 @ =gIoRegistersBackup
    ldrh r3, [r2, #0x12]
    movs r1, #0xc0
    lsls r1, r1, #8
    adds r0, r1, #0
    ands r0, r3
    cmp r0, #0
    bne lbl_08058b62
    ldrh r0, [r2, #0xa]
    ands r1, r0
    cmp r1, #0
    beq lbl_08058b62
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2, #0x12]
    ldr r2, lbl_08058b78 @ =0x04000008
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
lbl_08058b62:
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r5, r0
    ble lbl_08058b6c
    adds r5, r0, #0
lbl_08058b6c:
    ldr r1, lbl_08058b7c @ =gBG0YPosition
    rsbs r0, r5, #0
    lsls r0, r0, #2
    b lbl_08058c62
    .align 2, 0
lbl_08058b74: .4byte gIoRegistersBackup
lbl_08058b78: .4byte 0x04000008
lbl_08058b7c: .4byte gBG0YPosition
lbl_08058b80:
    movs r7, #1
    mov r1, ip
    ldrb r0, [r1, #1]
    cmp r0, #0x43
    beq lbl_08058bb0
    cmp r0, #0x43
    bgt lbl_08058b94
    cmp r0, #0x41
    beq lbl_08058b9e
    b lbl_08058c4c
lbl_08058b94:
    cmp r0, #0x44
    beq lbl_08058bdc
    cmp r0, #0x45
    beq lbl_08058bb0
    b lbl_08058c4c
lbl_08058b9e:
    ldr r0, lbl_08058ba8 @ =gBG0XPosition
    strh r3, [r0]
    ldr r0, lbl_08058bac @ =gBG0YPosition
    strh r3, [r0]
    b lbl_08058c4e
    .align 2, 0
lbl_08058ba8: .4byte gBG0XPosition
lbl_08058bac: .4byte gBG0YPosition
lbl_08058bb0:
    ldr r2, lbl_08058bcc @ =gBG0XPosition
    ldr r0, lbl_08058bd0 @ =gBG1XPosition
    ldrh r0, [r0]
    ldrh r1, [r4]
    subs r0, r0, r1
    strh r0, [r2]
    ldr r2, lbl_08058bd4 @ =gBG0YPosition
    ldr r0, lbl_08058bd8 @ =gBG1YPosition
    ldrh r0, [r0]
    ldrh r1, [r4, #2]
    subs r0, r0, r1
    adds r0, #0x40
    strh r0, [r2]
    b lbl_08058c4e
    .align 2, 0
lbl_08058bcc: .4byte gBG0XPosition
lbl_08058bd0: .4byte gBG1XPosition
lbl_08058bd4: .4byte gBG0YPosition
lbl_08058bd8: .4byte gBG1YPosition
lbl_08058bdc:
    movs r5, #0
    ldr r6, lbl_08058c38 @ =gBG0XPosition
    ldr r0, lbl_08058c3c @ =gBG1XPosition
    ldr r3, lbl_08058c40 @ =gWaitingSpacePiratesPosition
    ldrh r1, [r0]
    ldrh r0, [r3]
    subs r1, r1, r0
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r1, r2
    strh r0, [r6]
    ldr r4, lbl_08058c44 @ =gBG0YPosition
    ldr r0, lbl_08058c48 @ =gBG1YPosition
    ldrh r2, [r0]
    ldrh r0, [r3, #2]
    subs r2, r2, r0
    movs r3, #0x88
    lsls r3, r3, #3
    adds r0, r2, r3
    strh r0, [r4]
    movs r0, #0xa0
    lsls r0, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #0x10
    movs r0, #0xc0
    lsls r0, r0, #0x13
    cmp r1, r0
    bls lbl_08058c16
    movs r5, #1
lbl_08058c16:
    movs r1, #0xd0
    lsls r1, r1, #2
    adds r0, r2, r1
    lsls r0, r0, #0x10
    movs r1, #0xc0
    lsls r1, r1, #0x12
    cmp r0, r1
    bls lbl_08058c28
    movs r5, #1
lbl_08058c28:
    cmp r5, #0
    beq lbl_08058c4e
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    strh r0, [r6]
    b lbl_08058c4e
    .align 2, 0
lbl_08058c38: .4byte gBG0XPosition
lbl_08058c3c: .4byte gBG1XPosition
lbl_08058c40: .4byte gWaitingSpacePiratesPosition
lbl_08058c44: .4byte gBG0YPosition
lbl_08058c48: .4byte gBG1YPosition
lbl_08058c4c:
    movs r7, #0
lbl_08058c4e:
    ldr r6, lbl_08058c78 @ =gEffectYPositionOffset
    cmp r7, #0
    bne lbl_08058c64
    ldr r1, lbl_08058c7c @ =gBG0YPosition
    ldr r0, lbl_08058c80 @ =gBG1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058c84 @ =gBG0XPosition
    ldr r0, lbl_08058c88 @ =gBG1XPosition
    ldrh r0, [r0]
lbl_08058c62:
    strh r0, [r1]
lbl_08058c64:
    mov r3, ip
    ldrh r1, [r3, #0x12]
    ldr r0, lbl_08058c8c @ =0x0000ffff
    cmp r1, r0
    bne lbl_08058c94
    ldr r1, lbl_08058c90 @ =gEffectYPosition
    movs r0, #0
    strh r0, [r1]
    strh r0, [r6]
    b lbl_08058cb2
    .align 2, 0
lbl_08058c78: .4byte gEffectYPositionOffset
lbl_08058c7c: .4byte gBG0YPosition
lbl_08058c80: .4byte gBG1YPosition
lbl_08058c84: .4byte gBG0XPosition
lbl_08058c88: .4byte gBG1XPosition
lbl_08058c8c: .4byte 0x0000ffff
lbl_08058c90: .4byte gEffectYPosition
lbl_08058c94:
    ldr r0, lbl_08058cb8 @ =gWaterMovement
    ldrb r0, [r0, #3]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov r1, ip
    ldrh r1, [r1, #0x12]
    adds r0, r0, r1
    movs r2, #0
    ldrsh r1, [r6, r2]
    adds r5, r0, r1
    cmp r5, #0
    bge lbl_08058cae
    movs r5, #0
lbl_08058cae:
    ldr r0, lbl_08058cbc @ =gEffectYPosition
    strh r5, [r0]
lbl_08058cb2:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058cb8: .4byte gWaterMovement
lbl_08058cbc: .4byte gEffectYPosition

    thumb_func_start automatic_scroll_bg0
automatic_scroll_bg0: @ 0x08058cc0
    push {lr}
    ldr r0, lbl_08058cd4 @ =gBG0Movement
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058cd8
    ldrb r1, [r2, #1]
    movs r0, #7
    b lbl_08058ce0
    .align 2, 0
lbl_08058cd4: .4byte gBG0Movement
lbl_08058cd8:
    cmp r1, #2
    bne lbl_08058cee
    ldrb r1, [r2, #1]
    movs r0, #3
lbl_08058ce0:
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    b lbl_08058d16
lbl_08058cee:
    cmp r1, #3
    bne lbl_08058d02
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #6]
    adds r0, #1
    b lbl_08058d14
lbl_08058d02:
    cmp r1, #4
    bne lbl_08058d16
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #6]
    subs r0, #1
lbl_08058d14:
    strh r0, [r2, #6]
lbl_08058d16:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    pop {r0}
    bx r0

    thumb_func_start get_BG3Scrolling_values
get_BG3Scrolling_values: @ 0x08058d20
    push {lr}
    movs r3, #0
    movs r2, #0
    ldr r0, lbl_08058d38 @ =gCurrentRoomEntry
    ldrb r0, [r0, #6]
    cmp r0, #0xa
    bhi lbl_08058d96
    lsls r0, r0, #2
    ldr r1, lbl_08058d3c @ =lbl_08058d40
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08058d38: .4byte gCurrentRoomEntry
lbl_08058d3c: .4byte lbl_08058d40
lbl_08058d40: @ jump table
    .4byte lbl_08058d96 @ case 0
    .4byte lbl_08058d6c @ case 1
    .4byte lbl_08058d70 @ case 2
    .4byte lbl_08058d76 @ case 3
    .4byte lbl_08058d7c @ case 4
    .4byte lbl_08058d82 @ case 5
    .4byte lbl_08058d88 @ case 6
    .4byte lbl_08058d92 @ case 7
    .4byte lbl_08058d92 @ case 8
    .4byte lbl_08058d8e @ case 9
    .4byte lbl_08058d88 @ case 10
lbl_08058d6c:
    movs r2, #2
    b lbl_08058d94
lbl_08058d70:
    movs r2, #0
    movs r3, #2
    b lbl_08058d96
lbl_08058d76:
    movs r2, #2
    movs r3, #2
    b lbl_08058d96
lbl_08058d7c:
    movs r2, #1
    movs r3, #2
    b lbl_08058d96
lbl_08058d82:
    movs r2, #2
    movs r3, #1
    b lbl_08058d96
lbl_08058d88:
    movs r2, #1
    movs r3, #1
    b lbl_08058d96
lbl_08058d8e:
    movs r2, #3
    b lbl_08058d94
lbl_08058d92:
    movs r2, #1
lbl_08058d94:
    movs r3, #0
lbl_08058d96:
    lsls r0, r3, #0x10
    orrs r0, r2
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ScrollBG3
ScrollBG3: @ 0x08058da0
    push {lr}
    bl get_BG3Scrolling_values
    adds r3, r0, #0
    movs r0, #0xff
    ands r0, r3
    asrs r3, r3, #0x10
    cmp r0, #0
    beq lbl_08058df0
    cmp r0, #1
    bne lbl_08058dc8
    ldr r1, lbl_08058dc0 @ =gBG3XPosition
    ldr r0, lbl_08058dc4 @ =gBG1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058dee
    .align 2, 0
lbl_08058dc0: .4byte gBG3XPosition
lbl_08058dc4: .4byte gBG1XPosition
lbl_08058dc8:
    cmp r0, #2
    bne lbl_08058de0
    ldr r1, lbl_08058dd8 @ =gBG3XPosition
    ldr r0, lbl_08058ddc @ =gBG1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058dee
    .align 2, 0
lbl_08058dd8: .4byte gBG3XPosition
lbl_08058ddc: .4byte gBG1XPosition
lbl_08058de0:
    cmp r0, #3
    bne lbl_08058df0
    ldr r1, lbl_08058e20 @ =gBG3XPosition
    ldr r0, lbl_08058e24 @ =gBG1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058dee:
    strh r0, [r1]
lbl_08058df0:
    ldr r1, lbl_08058e28 @ =gCurrentRoomEntry
    ldrb r0, [r1, #0x1a]
    cmp r0, #0
    beq lbl_08058e6c
    ldr r0, lbl_08058e2c @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0x1e]
    subs r0, #0xc
    lsls r2, r0, #6
    ldrb r1, [r1, #0x19]
    movs r0, #2
    ands r0, r1
    movs r1, #0x80
    lsls r1, r1, #3
    cmp r0, #0
    beq lbl_08058e12
    movs r1, #0x80
    lsls r1, r1, #4
lbl_08058e12:
    ldr r0, lbl_08058e30 @ =0xfffffd80
    adds r1, r1, r0
    cmp r3, #0
    bne lbl_08058e34
    movs r1, #0
    movs r2, #0
    b lbl_08058e4c
    .align 2, 0
lbl_08058e20: .4byte gBG3XPosition
lbl_08058e24: .4byte gBG1XPosition
lbl_08058e28: .4byte gCurrentRoomEntry
lbl_08058e2c: .4byte gBGPointersAndDimensions
lbl_08058e30: .4byte 0xfffffd80
lbl_08058e34:
    cmp r3, #1
    bne lbl_08058e44
    ldr r0, lbl_08058e40 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r2, r2, r0
    b lbl_08058e4c
    .align 2, 0
lbl_08058e40: .4byte gBG1YPosition
lbl_08058e44:
    ldr r0, lbl_08058e58 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r0, r2, r0
    asrs r2, r0, #2
lbl_08058e4c:
    subs r1, r1, r2
    cmp r1, #0
    ble lbl_08058e60
    ldr r0, lbl_08058e5c @ =gBG3YPosition
    strh r1, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e58: .4byte gBG1YPosition
lbl_08058e5c: .4byte gBG3YPosition
lbl_08058e60:
    ldr r1, lbl_08058e68 @ =gBG3YPosition
    movs r0, #0
    b lbl_08058eb6
    .align 2, 0
lbl_08058e68: .4byte gBG3YPosition
lbl_08058e6c:
    cmp r3, #0
    bne lbl_08058e7c
    ldr r0, lbl_08058e78 @ =gBG3YPosition
    strh r3, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e78: .4byte gBG3YPosition
lbl_08058e7c:
    cmp r3, #1
    bne lbl_08058e94
    ldr r1, lbl_08058e8c @ =gBG3YPosition
    ldr r0, lbl_08058e90 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058eb6
    .align 2, 0
lbl_08058e8c: .4byte gBG3YPosition
lbl_08058e90: .4byte gBG1YPosition
lbl_08058e94:
    cmp r3, #2
    bne lbl_08058eac
    ldr r1, lbl_08058ea4 @ =gBG3YPosition
    ldr r0, lbl_08058ea8 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058eb6
    .align 2, 0
lbl_08058ea4: .4byte gBG3YPosition
lbl_08058ea8: .4byte gBG1YPosition
lbl_08058eac:
    ldr r1, lbl_08058ebc @ =gBG3YPosition
    ldr r0, lbl_08058ec0 @ =gBG1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058eb6:
    strh r0, [r1]
lbl_08058eb8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058ebc: .4byte gBG3YPosition
lbl_08058ec0: .4byte gBG1YPosition

    thumb_func_start sub_08058ec4
sub_08058ec4: @ 0x08058ec4
    push {lr}
    bl get_BG3Scrolling_values
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #0
    bne lbl_08058ee0
    ldr r0, lbl_08058edc @ =gBG3XPosition
    strh r1, [r0]
    b lbl_08058f08
    .align 2, 0
lbl_08058edc: .4byte gBG3XPosition
lbl_08058ee0:
    cmp r1, #2
    bne lbl_08058ef8
    ldr r1, lbl_08058ef0 @ =gBG3XPosition
    ldr r0, lbl_08058ef4 @ =gBG1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058f06
    .align 2, 0
lbl_08058ef0: .4byte gBG3XPosition
lbl_08058ef4: .4byte gBG1XPosition
lbl_08058ef8:
    cmp r1, #3
    bne lbl_08058f08
    ldr r1, lbl_08058f0c @ =gBG3XPosition
    ldr r0, lbl_08058f10 @ =gBG1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058f06:
    strh r0, [r1]
lbl_08058f08:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058f0c: .4byte gBG3XPosition
lbl_08058f10: .4byte gBG1XPosition

    thumb_func_start automatic_scroll_bg3
automatic_scroll_bg3: @ 0x08058f14
    push {lr}
    ldr r0, lbl_08058f3c @ =gBG3Movement
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058f30
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058f30
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
lbl_08058f30:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058f3c: .4byte gBG3Movement

    thumb_func_start ScrollBG2
ScrollBG2: @ 0x08058f40
    push {lr}
    ldr r0, lbl_08058f78 @ =gCurrentRoomEntry
    ldrb r2, [r0, #3]
    movs r0, #0x10
    ands r0, r2
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08058ff4
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_08058fd0
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x31
    bne lbl_08058fd0
    ldr r2, lbl_08058f7c @ =gBG1XPosition
    ldr r1, lbl_08058f80 @ =gBG2Movement
    movs r3, #0
    ldrsh r0, [r1, r3]
    ldrh r2, [r2]
    adds r2, r0, r2
    adds r3, r1, #0
    cmp r2, #0
    bge lbl_08058f84
    movs r2, #0
    b lbl_08058f92
    .align 2, 0
lbl_08058f78: .4byte gCurrentRoomEntry
lbl_08058f7c: .4byte gBG1XPosition
lbl_08058f80: .4byte gBG2Movement
lbl_08058f84:
    ldr r0, lbl_08058fa8 @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0x14]
    subs r0, #0xf
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058f92
    adds r2, r0, #0
lbl_08058f92:
    ldr r0, lbl_08058fac @ =gBG2XPosition
    strh r2, [r0]
    ldr r1, lbl_08058fb0 @ =gBG1YPosition
    movs r2, #2
    ldrsh r0, [r3, r2]
    ldrh r1, [r1]
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_08058fb4
    movs r2, #0
    b lbl_08058fc2
    .align 2, 0
lbl_08058fa8: .4byte gBGPointersAndDimensions
lbl_08058fac: .4byte gBG2XPosition
lbl_08058fb0: .4byte gBG1YPosition
lbl_08058fb4:
    ldr r0, lbl_08058fc8 @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0x16]
    subs r0, #0xa
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058fc2
    adds r2, r0, #0
lbl_08058fc2:
    ldr r0, lbl_08058fcc @ =gBG2YPosition
    strh r2, [r0]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fc8: .4byte gBGPointersAndDimensions
lbl_08058fcc: .4byte gBG2YPosition
lbl_08058fd0:
    ldr r1, lbl_08058fe4 @ =gBG2XPosition
    ldr r0, lbl_08058fe8 @ =gBG1XPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058fec @ =gBG2YPosition
    ldr r0, lbl_08058ff0 @ =gBG1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fe4: .4byte gBG2XPosition
lbl_08058fe8: .4byte gBG1XPosition
lbl_08058fec: .4byte gBG2YPosition
lbl_08058ff0: .4byte gBG1YPosition
lbl_08058ff4:
    ldr r0, lbl_08059000 @ =gBG2XPosition
    strh r1, [r0]
    ldr r0, lbl_08059004 @ =gBG2YPosition
    strh r1, [r0]
lbl_08058ffc:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059000: .4byte gBG2XPosition
lbl_08059004: .4byte gBG2YPosition

    thumb_func_start sub_08059008
sub_08059008: @ 0x08059008
    push {r4, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    ldr r0, lbl_0805901c @ =0x000001df
    cmp r1, r0
    bhi lbl_08059024
    ldr r1, lbl_08059020 @ =gBG1XPosition
    movs r0, #0
    b lbl_08059052
    .align 2, 0
lbl_0805901c: .4byte 0x000001df
lbl_08059020: .4byte gBG1XPosition
lbl_08059024:
    ldrh r3, [r4]
    ldr r0, lbl_0805903c @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0xc]
    lsls r2, r0, #6
    ldr r1, lbl_08059040 @ =0xfffffe20
    adds r0, r2, r1
    cmp r3, r0
    ble lbl_0805904c
    ldr r1, lbl_08059044 @ =gBG1XPosition
    ldr r3, lbl_08059048 @ =0xfffffc40
    adds r0, r2, r3
    b lbl_08059052
    .align 2, 0
lbl_0805903c: .4byte gBGPointersAndDimensions
lbl_08059040: .4byte 0xfffffe20
lbl_08059044: .4byte gBG1XPosition
lbl_08059048: .4byte 0xfffffc40
lbl_0805904c:
    ldr r1, lbl_08059064 @ =gBG1XPosition
    ldr r2, lbl_08059068 @ =0xfffffe20
    adds r0, r3, r2
lbl_08059052:
    strh r0, [r1]
    ldrh r1, [r4, #2]
    ldr r0, lbl_0805906c @ =0x0000017f
    cmp r1, r0
    bhi lbl_08059074
    ldr r1, lbl_08059070 @ =gBG1YPosition
    movs r0, #0
    b lbl_0805909e
    .align 2, 0
lbl_08059064: .4byte gBG1XPosition
lbl_08059068: .4byte 0xfffffe20
lbl_0805906c: .4byte 0x0000017f
lbl_08059070: .4byte gBG1YPosition
lbl_08059074:
    ldrh r3, [r4, #2]
    ldr r0, lbl_0805908c @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0xe]
    lsls r2, r0, #6
    adds r0, r2, #0
    subs r0, #0xc0
    cmp r3, r0
    ble lbl_08059098
    ldr r1, lbl_08059090 @ =gBG1YPosition
    ldr r3, lbl_08059094 @ =0xfffffdc0
    adds r0, r2, r3
    b lbl_0805909e
    .align 2, 0
lbl_0805908c: .4byte gBGPointersAndDimensions
lbl_08059090: .4byte gBG1YPosition
lbl_08059094: .4byte 0xfffffdc0
lbl_08059098:
    ldr r1, lbl_080590a8 @ =gBG1YPosition
    ldr r2, lbl_080590ac @ =0xfffffe80
    adds r0, r3, r2
lbl_0805909e:
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080590a8: .4byte gBG1YPosition
lbl_080590ac: .4byte 0xfffffe80

    thumb_func_start sub_080590b0
sub_080590b0: @ 0x080590b0
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    movs r7, #0
    ldrh r1, [r5, #4]
    adds r0, r1, #0
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x2f
    bls lbl_080590c6
    b lbl_080591ec
lbl_080590c6:
    adds r0, r1, #0
    subs r0, #0x10
    strb r0, [r5, #6]
    ldr r3, lbl_080590ec @ =gCurrentClipdataAffectingAction
    ldrb r0, [r3]
    cmp r0, #0xd
    bne lbl_080590f4
    ldr r1, lbl_080590f0 @ =0x083459f0
    ldrb r2, [r5, #6]
    lsls r0, r2, #2
    adds r0, r0, r1
    ldrb r0, [r0, #3]
    lsls r0, r0, #0x1c
    cmp r0, #0
    bne lbl_080590e6
    b lbl_080591ec
lbl_080590e6:
    movs r0, #0xc
    strb r0, [r3]
    b lbl_08059108
    .align 2, 0
lbl_080590ec: .4byte gCurrentClipdataAffectingAction
lbl_080590f0: .4byte 0x083459f0
lbl_080590f4:
    ldrb r2, [r5, #6]
    cmp r0, #0xf
    bne lbl_08059108
    ldr r0, lbl_0805911c @ =0x083459f0
    lsls r1, r2, #2
    adds r1, r1, r0
    ldrb r0, [r1, #3]
    lsrs r0, r0, #4
    cmp r0, #0
    beq lbl_080591ec
lbl_08059108:
    movs r4, #1
    movs r6, #0
    subs r0, r2, #2
    cmp r0, #0x1c
    bhi lbl_080591e8
    lsls r0, r0, #2
    ldr r1, lbl_08059120 @ =lbl_08059124
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805911c: .4byte 0x083459f0
lbl_08059120: .4byte lbl_08059124
lbl_08059124: @ jump table
    .4byte lbl_08059198 @ case 0
    .4byte lbl_080591a6 @ case 1
    .4byte lbl_080591a0 @ case 2
    .4byte lbl_080591e8 @ case 3
    .4byte lbl_080591e8 @ case 4
    .4byte lbl_08059198 @ case 5
    .4byte lbl_080591a6 @ case 6
    .4byte lbl_080591a0 @ case 7
    .4byte lbl_080591e8 @ case 8
    .4byte lbl_080591ae @ case 9
    .4byte lbl_080591ae @ case 10
    .4byte lbl_080591b8 @ case 11
    .4byte lbl_080591b8 @ case 12
    .4byte lbl_080591b8 @ case 13
    .4byte lbl_080591b8 @ case 14
    .4byte lbl_080591b8 @ case 15
    .4byte lbl_080591b8 @ case 16
    .4byte lbl_080591c2 @ case 17
    .4byte lbl_080591b8 @ case 18
    .4byte lbl_080591b8 @ case 19
    .4byte lbl_080591ca @ case 20
    .4byte lbl_080591ce @ case 21
    .4byte lbl_080591d2 @ case 22
    .4byte lbl_080591d6 @ case 23
    .4byte lbl_080591da @ case 24
    .4byte lbl_080591de @ case 25
    .4byte lbl_080591e2 @ case 26
    .4byte lbl_080591e6 @ case 27
    .4byte lbl_080591c2 @ case 28
lbl_08059198:
    ldrh r0, [r5]
    subs r0, #1
    strh r0, [r5]
    b lbl_080591e8
lbl_080591a0:
    ldrh r0, [r5]
    subs r0, #1
    strh r0, [r5]
lbl_080591a6:
    ldrh r0, [r5, #2]
    subs r0, #1
    strh r0, [r5, #2]
    b lbl_080591e8
lbl_080591ae:
    adds r0, r5, #0
    bl sub_080597f4
    adds r4, r0, #0
    b lbl_080591e8
lbl_080591b8:
    adds r0, r5, #0
    bl sub_08059770
    adds r4, r0, #0
    b lbl_080591e8
lbl_080591c2:
    adds r0, r5, #0
    bl sub_08059770
    b lbl_080591ec
lbl_080591ca:
    movs r6, #0
    b lbl_080591e8
lbl_080591ce:
    movs r6, #1
    b lbl_080591e8
lbl_080591d2:
    movs r6, #2
    b lbl_080591e8
lbl_080591d6:
    movs r6, #3
    b lbl_080591e8
lbl_080591da:
    movs r6, #4
    b lbl_080591e8
lbl_080591de:
    movs r6, #5
    b lbl_080591e8
lbl_080591e2:
    movs r6, #6
    b lbl_080591e8
lbl_080591e6:
    movs r6, #7
lbl_080591e8:
    cmp r4, #0
    bne lbl_080591f0
lbl_080591ec:
    movs r0, #0
    b lbl_080592b0
lbl_080591f0:
    ldr r1, lbl_08059208 @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #2
    beq lbl_08059222
    cmp r1, #2
    bgt lbl_0805920c
    cmp r1, #1
    beq lbl_08059216
    b lbl_080592ae
    .align 2, 0
lbl_08059208: .4byte 0x083459f0
lbl_0805920c:
    cmp r1, #3
    beq lbl_08059234
    cmp r1, #4
    beq lbl_08059274
    b lbl_080592ae
lbl_08059216:
    adds r0, r5, #0
    bl sub_080592c4
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
lbl_08059222:
    ldrb r0, [r0, #2]
    ldrh r1, [r5]
    ldrh r2, [r5, #2]
    movs r3, #0
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
lbl_08059234:
    adds r0, r5, #0
    bl sub_080597f4
    cmp r0, #0
    beq lbl_080592ae
    ldr r2, lbl_0805926c @ =gActiveBombChainTypes
    ldr r1, lbl_08059270 @ =0x08345c28
    lsls r0, r6, #2
    adds r0, r0, r1
    ldrb r1, [r2]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    bne lbl_080592ae
    adds r0, r6, #0
    ldrh r1, [r5]
    ldrh r2, [r5, #2]
    bl start_bomb_chain
    cmp r0, #0
    beq lbl_080592ae
    adds r0, r5, #0
    bl sub_080592c4
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
    .align 2, 0
lbl_0805926c: .4byte gActiveBombChainTypes
lbl_08059270: .4byte 0x08345c28
lbl_08059274:
    ldr r1, lbl_080592b8 @ =0x083459d0
    ldr r0, lbl_080592bc @ =gCurrentClipdataAffectingAction
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    beq lbl_080592ae
    ldr r1, lbl_080592c0 @ =0x08345c48
    ldrh r0, [r5, #4]
    subs r0, #0x34
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r4, [r0, #4]
    cmp r4, #0
    beq lbl_080592ae
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_bg1_block_value
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_clipdata_block_value
lbl_080592ac:
    movs r7, #1
lbl_080592ae:
    adds r0, r7, #0
lbl_080592b0:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080592b8: .4byte 0x083459d0
lbl_080592bc: .4byte gCurrentClipdataAffectingAction
lbl_080592c0: .4byte 0x08345c48

    thumb_func_start sub_080592c4
sub_080592c4: @ 0x080592c4
    push {r4, r5, lr}
    adds r5, r0, #0
    movs r2, #0
    ldr r1, lbl_080592e4 @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r4, [r0, #1]
    cmp r4, #4
    bhi lbl_0805930c
    lsls r0, r4, #2
    ldr r1, lbl_080592e8 @ =lbl_080592ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080592e4: .4byte 0x083459f0
lbl_080592e8: .4byte lbl_080592ec
lbl_080592ec: @ jump table
    .4byte lbl_0805930e @ case 0
    .4byte lbl_0805930e @ case 1
    .4byte lbl_08059300 @ case 2
    .4byte lbl_08059300 @ case 3
    .4byte lbl_0805930e @ case 4
lbl_08059300:
    ldrh r0, [r5]
    ldrh r1, [r5, #2]
    bl sub_08059480
    adds r2, r0, #0
    b lbl_0805930e
lbl_0805930c:
    movs r2, #1
lbl_0805930e:
    cmp r2, #0
    bne lbl_08059328
    ldr r0, lbl_08059324 @ =0x0875fd64
    lsls r1, r4, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r5, #0
    bl _call_via_r1
    adds r2, r0, #0
    b lbl_0805932a
    .align 2, 0
lbl_08059324: .4byte 0x0875fd64
lbl_08059328:
    movs r0, #0
lbl_0805932a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08059330
sub_08059330: @ 0x08059330
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    ldr r3, lbl_08059364 @ =0x083459f0
    ldrb r2, [r4, #6]
    lsls r2, r2, #2
    adds r2, r2, r3
    ldrb r2, [r2, #2]
    bl store_broken_non_reform_block
    ldr r2, lbl_08059368 @ =gBGPointersAndDimensions
    ldrh r1, [r4, #2]
    ldrh r0, [r2, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059364: .4byte 0x083459f0
lbl_08059368: .4byte gBGPointersAndDimensions

    thumb_func_start destroy_single_breakable_block
destroy_single_breakable_block: @ 0x0805936c
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    ldr r3, lbl_080593a0 @ =0x083459f0
    ldrb r2, [r4, #6]
    lsls r2, r2, #2
    adds r2, r2, r3
    ldrb r2, [r2, #2]
    bl store_broken_non_reform_block
    ldr r2, lbl_080593a4 @ =gBGPointersAndDimensions
    ldrh r1, [r4, #2]
    ldrh r0, [r2, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080593a0: .4byte 0x083459f0
lbl_080593a4: .4byte gBGPointersAndDimensions

    thumb_func_start destroy_square_block
destroy_square_block: @ 0x080593a8
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    adds r4, r0, #0
    ldr r1, lbl_08059470 @ =0x083459f0
    ldrb r0, [r4, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r6, [r0, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldr r5, lbl_08059474 @ =gBGPointersAndDimensions
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    ldrh r0, [r4]
    adds r0, #1
    movs r1, #0
    mov r8, r1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    adds r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldrh r0, [r4, #2]
    subs r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldrh r0, [r4]
    subs r0, #1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    adds r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldr r0, lbl_08059478 @ =gCurrentClipdataAffectingAction
    ldrb r0, [r0]
    cmp r0, #0xc
    beq lbl_08059464
    ldr r0, lbl_0805947c @ =0x00000137
    bl SoundPlayNotAlreadyPlaying
lbl_08059464:
    movs r0, #1
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059470: .4byte 0x083459f0
lbl_08059474: .4byte gBGPointersAndDimensions
lbl_08059478: .4byte gCurrentClipdataAffectingAction
lbl_0805947c: .4byte 0x00000137

    thumb_func_start sub_08059480
sub_08059480: @ 0x08059480
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    ldr r1, lbl_080594a0 @ =gCurrentArea
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0805949a
    adds r0, r4, #0
    muls r0, r5, r0
    cmp r0, #0
    bne lbl_080594a4
lbl_0805949a:
    movs r0, #0
    b lbl_080594f6
    .align 2, 0
lbl_080594a0: .4byte gCurrentArea
lbl_080594a4:
    movs r3, #1
    ldrb r0, [r1]
    lsls r1, r0, #9
    ldr r6, lbl_080594c8 @ =0x02035c00
    adds r2, r1, r6
    ldr r1, lbl_080594cc @ =gNumberOfNeverReformBlocks
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r1, r0, #1
    ldr r0, lbl_080594d0 @ =0x000001fb
    cmp r1, r0
    bgt lbl_080594e6
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_080594d4
    movs r3, #0
    b lbl_080594ea
    .align 2, 0
lbl_080594c8: .4byte 0x02035c00
lbl_080594cc: .4byte gNumberOfNeverReformBlocks
lbl_080594d0: .4byte 0x000001fb
lbl_080594d4:
    adds r1, #2
    ldr r0, lbl_080594fc @ =0x000001fb
    cmp r1, r0
    bgt lbl_080594e6
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_080594d4
    movs r3, #0
lbl_080594e6:
    cmp r3, #0
    bne lbl_080594f4
lbl_080594ea:
    adds r0, r2, r1
    strb r4, [r0]
    adds r1, #1
    adds r0, r2, r1
    strb r5, [r0]
lbl_080594f4:
    adds r0, r3, #0
lbl_080594f6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080594fc: .4byte 0x000001fb

    thumb_func_start remove_never_reform_blocks
remove_never_reform_blocks: @ 0x08059500
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08059550 @ =gPauseScreenFlag
    movs r1, #0
    ldrsb r1, [r0, r1]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    ldr r1, lbl_08059554 @ =gCurrentArea
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_08059518
    movs r6, #1
lbl_08059518:
    cmp r6, #0
    bne lbl_08059578
    ldrb r0, [r1]
    lsls r1, r0, #9
    ldr r3, lbl_08059558 @ =0x02035c00
    adds r2, r1, r3
    ldr r1, lbl_0805955c @ =gNumberOfNeverReformBlocks
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r7, r0, #1
    movs r5, #0
    cmp r6, r7
    bge lbl_08059578
    adds r4, r2, #0
lbl_08059534:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0805953c
    movs r5, #1
lbl_0805953c:
    cmp r5, #1
    bne lbl_08059564
    ldr r1, lbl_08059560 @ =gCurrentRoom
    ldrb r0, [r4, #1]
    movs r5, #0
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08059570
    movs r5, #2
    b lbl_08059570
    .align 2, 0
lbl_08059550: .4byte gPauseScreenFlag
lbl_08059554: .4byte gCurrentArea
lbl_08059558: .4byte 0x02035c00
lbl_0805955c: .4byte gNumberOfNeverReformBlocks
lbl_08059560: .4byte gCurrentRoom
lbl_08059564:
    cmp r5, #2
    bne lbl_08059570
    ldrb r0, [r4]
    ldrb r1, [r4, #1]
    bl remove_never_reform_block_in_clipdata_bg
lbl_08059570:
    adds r4, #2
    adds r6, #2
    cmp r6, r7
    blt lbl_08059534
lbl_08059578:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start remove_never_reform_block_in_clipdata_bg
remove_never_reform_block_in_clipdata_bg: @ 0x08059580
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_080595dc @ =gBGPointersAndDimensions
    mov ip, r2
    ldrh r2, [r2, #0x1c]
    muls r1, r2, r1
    adds r3, r1, r0
    ldr r1, lbl_080595e0 @ =gTilemapAndClipPointers
    mov r0, ip
    ldr r7, [r0, #0x18]
    lsls r2, r3, #1
    adds r5, r2, r7
    ldrh r0, [r5]
    ldr r1, [r1, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    movs r4, #0
    strh r4, [r5]
    mov r1, ip
    ldr r6, [r1, #8]
    adds r2, r2, r6
    strh r4, [r2]
    cmp r0, #0x11
    bne lbl_080595d6
    strh r4, [r5, #2]
    strh r4, [r2, #2]
    ldrh r0, [r1, #0x1c]
    adds r3, r3, r0
    lsls r0, r3, #1
    adds r1, r0, r7
    strh r4, [r1]
    adds r0, r0, r6
    strh r4, [r0]
    adds r3, #1
    lsls r0, r3, #1
    adds r1, r0, r7
    strh r4, [r1]
    adds r0, r0, r6
    strh r4, [r0]
lbl_080595d6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080595dc: .4byte gBGPointersAndDimensions
lbl_080595e0: .4byte gTilemapAndClipPointers

    thumb_func_start BlockShiftNeverReformBlocks
BlockShiftNeverReformBlocks: @ 0x080595e4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08059668 @ =gAreaBeforeTransition
    mov sl, r0
    ldrb r0, [r0]
    lsls r1, r0, #9
    ldr r2, lbl_0805966c @ =0x02035c00
    adds r2, r2, r1
    mov r8, r2
    ldr r5, lbl_08059670 @ =gNumberOfNeverReformBlocks
    mov sb, r5
    add r0, sb
    ldrb r0, [r0]
    lsls r0, r0, #1
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_08059612
    b lbl_08059752
lbl_08059612:
    movs r6, #0x80
    lsls r6, r6, #0x12
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_08059674 @ =0x0000ffff
    str r4, [sp]
    movs r0, #3
    mov r2, r8
    adds r3, r5, #0
    bl BitFill
    movs r2, #0
    movs r7, #0
    mov r1, sl
    ldrb r0, [r1]
    add r0, sb
    ldrb r0, [r0]
    movs r4, #0
    cmp r0, #0
    beq lbl_080596f8
    mov ip, sb
    mov sb, sl
    ldr r5, lbl_08059678 @ =gCurrentRoom
    mov sl, r5
    mov r3, r8
lbl_08059654:
    adds r0, r6, r7
    ldrb r1, [r0]
    str r0, [sp, #4]
    cmp r1, #0
    bne lbl_0805968e
    cmp r2, #1
    bne lbl_0805967c
    movs r2, #0xa
    b lbl_0805968e
    .align 2, 0
lbl_08059668: .4byte gAreaBeforeTransition
lbl_0805966c: .4byte 0x02035c00
lbl_08059670: .4byte gNumberOfNeverReformBlocks
lbl_08059674: .4byte 0x0000ffff
lbl_08059678: .4byte gCurrentRoom
lbl_0805967c:
    cmp r2, #0
    bne lbl_0805968e
    adds r0, r4, r6
    ldrb r0, [r0, #1]
    mov r1, sl
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0805968e
    movs r2, #1
lbl_0805968e:
    cmp r2, #9
    bgt lbl_080596aa
    ldr r5, [sp, #4]
    ldrb r0, [r5]
    strb r0, [r3]
    adds r7, #1
    adds r3, #1
    adds r0, r6, r7
    ldrb r0, [r0]
    strb r0, [r3]
    adds r7, #1
    adds r3, #1
    adds r4, #2
    b lbl_080596ea
lbl_080596aa:
    cmp r2, #0xa
    bne lbl_080596ea
    mov r1, sb
    ldrb r0, [r1]
    add r0, ip
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x12
    adds r6, r0, r1
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_080596e4
    mov r5, r8
    adds r1, r4, r5
lbl_080596ca:
    strb r2, [r1]
    adds r6, #1
    adds r1, #1
    ldrb r0, [r6]
    strb r0, [r1]
    adds r6, #1
    adds r1, #1
    adds r3, #2
    adds r4, #2
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    bne lbl_080596ca
lbl_080596e4:
    movs r2, #2
    movs r6, #0x80
    lsls r6, r6, #0x12
lbl_080596ea:
    mov r1, sb
    ldrb r0, [r1]
    add r0, ip
    ldrb r0, [r0]
    lsls r0, r0, #1
    cmp r7, r0
    blt lbl_08059654
lbl_080596f8:
    ldr r3, lbl_08059764 @ =gAreaBeforeTransition
    ldr r5, lbl_08059768 @ =gNumberOfNeverReformBlocks
    cmp r2, #2
    beq lbl_0805974a
    cmp r2, #1
    beq lbl_08059718
    mov r2, r8
    adds r1, r2, r4
    movs r0, #0
    strb r0, [r1]
    adds r4, #1
    adds r1, r2, r4
    ldr r0, lbl_0805976c @ =gCurrentRoom
    ldrb r0, [r0]
    strb r0, [r1]
    adds r4, #1
lbl_08059718:
    ldrb r0, [r3]
    adds r0, r0, r5
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x12
    adds r6, r0, r1
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_0805974a
    mov r0, r8
    adds r1, r4, r0
lbl_08059732:
    strb r2, [r1]
    adds r6, #1
    adds r1, #1
    ldrb r0, [r6]
    strb r0, [r1]
    adds r6, #1
    adds r1, #1
    adds r4, #2
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    bne lbl_08059732
lbl_0805974a:
    ldrb r0, [r3]
    adds r0, r0, r5
    asrs r1, r4, #1
    strb r1, [r0]
lbl_08059752:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059764: .4byte gAreaBeforeTransition
lbl_08059768: .4byte gNumberOfNeverReformBlocks
lbl_0805976c: .4byte gCurrentRoom

    thumb_func_start sub_08059770
sub_08059770: @ 0x08059770
    push {r4, r5, lr}
    adds r5, r0, #0
    ldr r1, lbl_0805979c @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r4, [r0, #2]
    ldr r2, lbl_080597a0 @ =0x083459d0
    ldr r0, lbl_080597a4 @ =gCurrentClipdataAffectingAction
    ldrb r3, [r0]
    lsls r1, r3, #1
    adds r1, r1, r2
    ldr r2, lbl_080597a8 @ =0x08345ab0
    lsls r0, r4, #1
    adds r0, r0, r2
    ldrh r1, [r1]
    ldrh r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_080597ac
    movs r0, #1
    b lbl_080597e4
    .align 2, 0
lbl_0805979c: .4byte 0x083459f0
lbl_080597a0: .4byte 0x083459d0
lbl_080597a4: .4byte gCurrentClipdataAffectingAction
lbl_080597a8: .4byte 0x08345ab0
lbl_080597ac:
    adds r1, r3, #0
    cmp r1, #8
    beq lbl_080597be
    cmp r1, #0xb
    bne lbl_080597e2
    ldr r0, lbl_080597ec @ =gCurrentPowerBomb
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    bne lbl_080597e2
lbl_080597be:
    ldr r0, lbl_080597f0 @ =0x08345adc
    lsls r1, r4, #1
    adds r1, r1, r0
    ldrh r0, [r5, #4]
    ldrh r2, [r1]
    cmp r0, r2
    beq lbl_080597e2
    ldrh r4, [r1]
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_bg1_block_value
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_clipdata_block_value
lbl_080597e2:
    movs r0, #0
lbl_080597e4:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080597ec: .4byte gCurrentPowerBomb
lbl_080597f0: .4byte 0x08345adc

    thumb_func_start sub_080597f4
sub_080597f4: @ 0x080597f4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r1, lbl_08059820 @ =0x083459f0
    ldrb r0, [r4, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r3, [r0, #2]
    ldr r1, lbl_08059824 @ =0x083459d0
    ldr r0, lbl_08059828 @ =gCurrentClipdataAffectingAction
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldr r1, lbl_0805982c @ =0x08345ab0
    lsls r5, r3, #1
    adds r1, r5, r1
    ldrh r2, [r0]
    ldrh r0, [r1]
    ands r0, r2
    cmp r0, #0
    beq lbl_08059830
    movs r0, #1
    b lbl_08059870
    .align 2, 0
lbl_08059820: .4byte 0x083459f0
lbl_08059824: .4byte 0x083459d0
lbl_08059828: .4byte gCurrentClipdataAffectingAction
lbl_0805982c: .4byte 0x08345ab0
lbl_08059830:
    movs r0, #0xd
    ands r0, r2
    cmp r0, #0
    beq lbl_0805986e
    ldr r0, lbl_08059878 @ =0x08345adc
    adds r1, r5, r0
    ldrh r0, [r4, #4]
    ldrh r2, [r1]
    cmp r0, r2
    beq lbl_0805986e
    movs r0, #1
    ldrh r5, [r1]
    cmp r3, #0xd
    ble lbl_08059856
    adds r0, r3, #0
    ldrh r1, [r4]
    ldrh r2, [r4, #2]
    bl sub_08059ef8
lbl_08059856:
    cmp r0, #0
    beq lbl_0805986e
    ldrh r1, [r4, #2]
    ldrh r2, [r4]
    adds r0, r5, #0
    bl set_bg1_block_value
    ldrh r1, [r4, #2]
    ldrh r2, [r4]
    adds r0, r5, #0
    bl set_clipdata_block_value
lbl_0805986e:
    movs r0, #0
lbl_08059870:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059878: .4byte 0x08345adc

    thumb_func_start BlockApplyCCAA
BlockApplyCCAA: @ 0x0805987c
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r7, r2, #0x10
    ldr r2, lbl_080598c0 @ =0xffff0000
    lsrs r5, r0, #0x10
    orrs r0, r4
    str r0, [sp]
    ldr r3, lbl_080598c4 @ =gTilemapAndClipPointers
    ldr r1, [r3, #8]
    lsls r0, r7, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    ldr r0, [sp, #4]
    ands r0, r2
    orrs r0, r1
    ldr r1, lbl_080598c8 @ =0xff00ffff
    ands r0, r1
    str r0, [sp, #4]
    movs r6, #0
    ldr r0, lbl_080598cc @ =gCurrentClipdataAffectingAction
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #0xe
    bls lbl_080598b6
    b lbl_080599d2
lbl_080598b6:
    lsls r0, r0, #2
    ldr r1, lbl_080598d0 @ =lbl_080598d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080598c0: .4byte 0xffff0000
lbl_080598c4: .4byte gTilemapAndClipPointers
lbl_080598c8: .4byte 0xff00ffff
lbl_080598cc: .4byte gCurrentClipdataAffectingAction
lbl_080598d0: .4byte lbl_080598d4
lbl_080598d4: @ jump table
    .4byte lbl_08059964 @ case 0
    .4byte lbl_08059980 @ case 1
    .4byte lbl_08059998 @ case 2
    .4byte lbl_080599b8 @ case 3
    .4byte lbl_08059958 @ case 4
    .4byte lbl_080599d2 @ case 5
    .4byte lbl_08059910 @ case 6
    .4byte lbl_08059910 @ case 7
    .4byte lbl_08059910 @ case 8
    .4byte lbl_08059910 @ case 9
    .4byte lbl_08059910 @ case 10
    .4byte lbl_0805992c @ case 11
    .4byte lbl_0805992c @ case 12
    .4byte lbl_08059940 @ case 13
    .4byte lbl_08059958 @ case 14
lbl_08059910:
    ldr r0, [r3, #4]
    adds r0, r0, r7
    ldrb r0, [r0]
    cmp r0, #0xb
    bne lbl_08059958
    mov r0, sp
    ldrh r0, [r0]
    ldr r1, [sp]
    lsrs r1, r1, #0x10
    bl check_opening_hatch
    cmp r0, #0
    bne lbl_08059950
    b lbl_08059958
lbl_0805992c:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    ldr r0, lbl_0805993c @ =0x00000135
    b lbl_0805994c
    .align 2, 0
lbl_0805993c: .4byte 0x00000135
lbl_08059940:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    ldr r0, lbl_08059954 @ =0x00000139
lbl_0805994c:
    bl SoundPlayNotAlreadyPlaying
lbl_08059950:
    movs r6, #1
    b lbl_080599d2
    .align 2, 0
lbl_08059954: .4byte 0x00000139
lbl_08059958:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    b lbl_08059950
lbl_08059964:
    movs r0, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    cmp r0, #0
    bne lbl_0805997c
    movs r0, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_bg1_block_value
lbl_0805997c:
    movs r0, #0
    b lbl_080599aa
lbl_08059980:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_08059994 @ =0x0000043e
    b lbl_080599aa
    .align 2, 0
lbl_08059994: .4byte 0x0000043e
lbl_08059998:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_080599b4 @ =0x0000043d
lbl_080599aa:
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
    b lbl_080599d2
    .align 2, 0
lbl_080599b4: .4byte 0x0000043d
lbl_080599b8:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_080599dc @ =0x0000043f
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
lbl_080599d2:
    adds r0, r6, #0
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080599dc: .4byte 0x0000043f

    thumb_func_start sub_080599e0
sub_080599e0: @ 0x080599e0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    movs r6, #0
    cmp r0, #0
    bne lbl_08059a3e
    ldr r0, lbl_08059a18 @ =0x02027780
    mov r8, r0
    movs r3, #0x3f
    movs r1, #0x7e
    add r1, r8
    mov ip, r1
    ldrh r2, [r1]
    lsls r1, r7, #8
    adds r0, r1, #0
    orrs r0, r5
    adds r4, r1, #0
    cmp r2, r0
    bne lbl_08059a1c
    mov r0, ip
    strh r6, [r0]
    b lbl_08059a88
    .align 2, 0
lbl_08059a18: .4byte 0x02027780
lbl_08059a1c:
    subs r3, #1
    cmp r3, #0
    ble lbl_08059a8a
    subs r3, #1
    lsls r0, r3, #1
    mov r1, r8
    adds r2, r0, r1
    ldrh r1, [r2]
    adds r0, r4, #0
    orrs r0, r5
    cmp r1, r0
    bne lbl_08059a1c
    movs r0, #0
    strh r0, [r2]
    b lbl_08059a88
lbl_08059a3a:
    movs r3, #0xff
    b lbl_08059a66
lbl_08059a3e:
    ldr r0, lbl_08059a48 @ =0x02027780
    mov r8, r0
    movs r3, #0x40
    lsls r4, r7, #8
    b lbl_08059a52
    .align 2, 0
lbl_08059a48: .4byte 0x02027780
lbl_08059a4c:
    subs r3, #1
    cmp r3, #0
    ble lbl_08059a66
lbl_08059a52:
    subs r3, #1
    lsls r0, r3, #1
    add r0, r8
    ldrh r1, [r0]
    adds r0, r4, #0
    orrs r0, r5
    cmp r1, r0
    beq lbl_08059a3a
    cmp r1, #0
    bne lbl_08059a4c
lbl_08059a66:
    movs r6, #0
    cmp r3, #0xff
    beq lbl_08059a8a
    ldr r1, lbl_08059a98 @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    muls r0, r5, r0
    adds r0, r0, r7
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08059a8a
    lsls r0, r3, #1
    add r0, r8
    orrs r4, r5
    strh r4, [r0]
lbl_08059a88:
    movs r6, #1
lbl_08059a8a:
    adds r0, r6, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059a98: .4byte gBGPointersAndDimensions

    thumb_func_start samus_apply_screw_speedbooster_damage_to_environment
samus_apply_screw_speedbooster_damage_to_environment: @ 0x08059a9c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsrs r7, r0, #0x16
    lsrs r6, r1, #0x16
    ldr r0, lbl_08059ac8 @ =gBGPointersAndDimensions
    adds r2, r0, #0
    ldrh r0, [r2, #0x1c]
    cmp r7, r0
    bhs lbl_08059af4
    ldrh r1, [r2, #0x1e]
    cmp r6, r1
    bhs lbl_08059af4
    cmp r5, #1
    bne lbl_08059ad0
    ldr r1, lbl_08059acc @ =gCurrentClipdataAffectingAction
    movs r0, #0xc
    b lbl_08059afc
    .align 2, 0
lbl_08059ac8: .4byte gBGPointersAndDimensions
lbl_08059acc: .4byte gCurrentClipdataAffectingAction
lbl_08059ad0:
    cmp r5, #2
    bne lbl_08059ae0
    ldr r1, lbl_08059adc @ =gCurrentClipdataAffectingAction
    movs r0, #0xe
    b lbl_08059afc
    .align 2, 0
lbl_08059adc: .4byte gCurrentClipdataAffectingAction
lbl_08059ae0:
    cmp r5, #3
    bne lbl_08059af0
    ldr r1, lbl_08059aec @ =gCurrentClipdataAffectingAction
    movs r0, #0xe
    b lbl_08059afc
    .align 2, 0
lbl_08059aec: .4byte gCurrentClipdataAffectingAction
lbl_08059af0:
    cmp r5, #4
    beq lbl_08059af8
lbl_08059af4:
    movs r0, #0
    b lbl_08059b46
lbl_08059af8:
    ldr r1, lbl_08059b50 @ =gCurrentClipdataAffectingAction
    movs r0, #0xd
lbl_08059afc:
    strb r0, [r1]
    ldrh r0, [r2, #0x1c]
    adds r1, r6, #0
    muls r1, r0, r1
    adds r0, r1, #0
    adds r0, r7, r0
    lsls r0, r0, #0x10
    ldr r1, [r2, #0x18]
    lsrs r0, r0, #0xf
    adds r0, r0, r1
    ldrh r4, [r0]
    cmp r4, #0
    beq lbl_08059b3e
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl BlockApplyCCAA
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    cmp r0, #0
    bne lbl_08059b3e
    cmp r5, #3
    bne lbl_08059b3e
    ldr r1, lbl_08059b50 @ =gCurrentClipdataAffectingAction
    movs r0, #0xc
    strb r0, [r1]
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl BlockApplyCCAA
lbl_08059b3e:
    ldr r1, lbl_08059b50 @ =gCurrentClipdataAffectingAction
    movs r0, #0
    strb r0, [r1]
    mov r0, r8
lbl_08059b46:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059b50: .4byte gCurrentClipdataAffectingAction

    thumb_func_start update_broken_blocks
update_broken_blocks: @ 0x08059b54
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r4, lbl_08059bb0 @ =gBrokenBlocks
    movs r0, #0x2f
    mov sb, r0
lbl_08059b62:
    ldrb r7, [r4, #1]
    adds r2, r7, #0
    cmp r2, #0
    beq lbl_08059c52
    ldrh r0, [r4, #6]
    adds r3, r0, #1
    movs r6, #0
    strh r3, [r4, #6]
    ldrb r5, [r4]
    cmp r5, #0
    beq lbl_08059c1e
    ldr r1, lbl_08059bb4 @ =0x08345b08
    mov r8, r1
    ldrb r0, [r4, #2]
    movs r7, #0xd
    adds r1, r0, #0
    muls r1, r7, r1
    ldrb r0, [r4, #1]
    adds r1, r1, r0
    add r1, r8
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_08059c52
    movs r5, #0
    strh r5, [r4, #6]
    cmp r2, #0xc
    bls lbl_08059bdc
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    bl check_samus_in_reforming_block
    cmp r0, #0
    beq lbl_08059bb8
    movs r0, #2
    strb r0, [r4, #1]
    b lbl_08059c0c
    .align 2, 0
lbl_08059bb0: .4byte gBrokenBlocks
lbl_08059bb4: .4byte 0x08345b08
lbl_08059bb8:
    ldr r1, lbl_08059bd8 @ =0x08345adc
    ldrb r0, [r4, #2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldrb r1, [r4, #4]
    ldrb r2, [r4, #3]
    bl set_clipdata_block_value
    strb r6, [r4]
    strb r6, [r4, #1]
    strb r6, [r4, #2]
    strb r6, [r4, #3]
    strb r6, [r4, #4]
    b lbl_08059c0c
    .align 2, 0
lbl_08059bd8: .4byte 0x08345adc
lbl_08059bdc:
    cmp r2, #7
    bne lbl_08059bfe
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    bl check_samus_in_reforming_block
    cmp r0, #0
    beq lbl_08059c10
    ldrb r0, [r4, #2]
    muls r0, r7, r0
    ldrb r1, [r4, #1]
    adds r0, r0, r1
    add r0, r8
    ldrb r0, [r0]
    lsrs r0, r0, #1
    strh r0, [r4, #6]
    b lbl_08059c0c
lbl_08059bfe:
    cmp r2, #1
    bne lbl_08059c0a
    ldrb r0, [r4, #4]
    ldrb r1, [r4, #3]
    bl sub_0805a3e0
lbl_08059c0a:
    movs r5, #1
lbl_08059c0c:
    cmp r5, #0
    beq lbl_08059c52
lbl_08059c10:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059c52
lbl_08059c1e:
    ldr r2, lbl_08059c70 @ =0x08345b08
    ldrb r1, [r4, #2]
    movs r0, #0xd
    muls r1, r0, r1
    ldrb r0, [r4, #1]
    adds r1, r1, r0
    adds r1, r1, r2
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_08059c52
    strh r5, [r4, #6]
    adds r0, r7, #1
    strb r0, [r4, #1]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    ldrb r0, [r4, #1]
    cmp r0, #6
    bls lbl_08059c52
    strb r6, [r4]
    strb r6, [r4, #1]
    strb r6, [r4, #2]
    strb r6, [r4, #3]
    strb r6, [r4, #4]
lbl_08059c52:
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    adds r4, #8
    mov r0, sb
    cmp r0, #0
    blt lbl_08059c62
    b lbl_08059b62
lbl_08059c62:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059c70: .4byte 0x08345b08

    thumb_func_start breaking_reforming_block_anim
breaking_reforming_block_anim: @ 0x08059c74
    push {r4, r5, lr}
    adds r4, r0, #0
    movs r5, #0
    ldrb r0, [r4, #1]
    cmp r0, #0xd
    bhi lbl_08059cfc
    lsls r0, r0, #2
    ldr r1, lbl_08059c8c @ =lbl_08059c90
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08059c8c: .4byte lbl_08059c90
lbl_08059c90: @ jump table
    .4byte lbl_08059cfc @ case 0
    .4byte lbl_08059cfc @ case 1
    .4byte lbl_08059cc8 @ case 2
    .4byte lbl_08059cd8 @ case 3
    .4byte lbl_08059ce0 @ case 4
    .4byte lbl_08059ce8 @ case 5
    .4byte lbl_08059cf0 @ case 6
    .4byte lbl_08059cf8 @ case 7
    .4byte lbl_08059cf0 @ case 8
    .4byte lbl_08059ce8 @ case 9
    .4byte lbl_08059ce0 @ case 10
    .4byte lbl_08059cd8 @ case 11
    .4byte lbl_08059cc8 @ case 12
    .4byte lbl_08059cfc @ case 13
lbl_08059cc8:
    ldr r1, lbl_08059cd4 @ =0x08345adc
    ldrb r0, [r4, #2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r5, [r0]
    b lbl_08059cfc
    .align 2, 0
lbl_08059cd4: .4byte 0x08345adc
lbl_08059cd8:
    ldr r5, lbl_08059cdc @ =0x00000401
    b lbl_08059d00
    .align 2, 0
lbl_08059cdc: .4byte 0x00000401
lbl_08059ce0:
    ldr r5, lbl_08059ce4 @ =0x00000402
    b lbl_08059d00
    .align 2, 0
lbl_08059ce4: .4byte 0x00000402
lbl_08059ce8:
    ldr r5, lbl_08059cec @ =0x00000403
    b lbl_08059d00
    .align 2, 0
lbl_08059cec: .4byte 0x00000403
lbl_08059cf0:
    ldr r5, lbl_08059cf4 @ =0x00000404
    b lbl_08059d00
    .align 2, 0
lbl_08059cf4: .4byte 0x00000404
lbl_08059cf8:
    movs r5, #0x80
    lsls r5, r5, #3
lbl_08059cfc:
    cmp r5, #0
    beq lbl_08059d8a
lbl_08059d00:
    ldr r2, lbl_08059d90 @ =gBGPointersAndDimensions
    ldrb r1, [r4, #4]
    ldrh r0, [r2, #0xc]
    muls r0, r1, r0
    ldrb r1, [r4, #3]
    adds r0, r0, r1
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    strh r5, [r0]
    ldr r0, lbl_08059d94 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r3, r0, #6
    subs r0, r3, #4
    ldrb r2, [r4, #4]
    cmp r0, r2
    bgt lbl_08059d8a
    adds r0, #0x11
    cmp r2, r0
    bgt lbl_08059d8a
    ldr r0, lbl_08059d98 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r3, r0, #6
    subs r0, r3, #4
    ldrb r1, [r4, #3]
    cmp r0, r1
    bgt lbl_08059d8a
    adds r0, #0x16
    cmp r1, r0
    bgt lbl_08059d8a
    ldr r4, lbl_08059d9c @ =0x06001000
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08059d48
    ldr r4, lbl_08059da0 @ =0x06001800
lbl_08059d48:
    movs r0, #0xf
    ands r1, r0
    lsls r3, r1, #1
    ands r2, r0
    lsls r0, r2, #6
    adds r0, r0, r3
    lsls r0, r0, #1
    adds r4, r4, r0
    lsls r3, r5, #2
    ldr r0, lbl_08059da4 @ =gTilemapAndClipPointers
    ldr r1, [r0]
    lsls r0, r5, #3
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4]
    adds r3, #1
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4, #2]
    adds r3, #1
    adds r2, r4, #0
    adds r2, #0x40
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
    adds r3, #1
    adds r2, #2
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
lbl_08059d8a:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059d90: .4byte gBGPointersAndDimensions
lbl_08059d94: .4byte gBG1YPosition
lbl_08059d98: .4byte gBG1XPosition
lbl_08059d9c: .4byte 0x06001000
lbl_08059da0: .4byte 0x06001800
lbl_08059da4: .4byte gTilemapAndClipPointers

    thumb_func_start store_broken_reform_block
store_broken_reform_block: @ 0x08059da8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov r8, r3
    movs r1, #0
    ldr r4, lbl_08059dcc @ =gBrokenBlocks
    movs r3, #0
    adds r7, r4, #0
    b lbl_08059de8
    .align 2, 0
lbl_08059dcc: .4byte gBrokenBlocks
lbl_08059dd0:
    movs r2, #0x80
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    bne lbl_08059de4
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_08059de4
    adds r1, r3, #0
    orrs r1, r2
lbl_08059de4:
    adds r3, #1
    adds r4, #8
lbl_08059de8:
    cmp r3, #0x2f
    bgt lbl_08059e02
    ldrb r0, [r4, #3]
    cmp r0, r6
    bne lbl_08059dd0
    ldrb r0, [r4, #4]
    cmp r0, r5
    bne lbl_08059dd0
    ldrb r0, [r4, #1]
    movs r1, #0
    cmp r0, #0
    bne lbl_08059e02
    movs r1, #1
lbl_08059e02:
    cmp r1, #0
    beq lbl_08059e48
    cmp r1, #1
    beq lbl_08059e0e
    movs r3, #0x7f
    ands r3, r1
lbl_08059e0e:
    lsls r0, r3, #3
    adds r4, r0, r7
    movs r0, #0
    movs r2, #1
    strb r2, [r4]
    mov r3, ip
    strb r3, [r4, #2]
    strh r0, [r4, #6]
    movs r0, #0x80
    ands r1, r0
    cmp r1, #0
    beq lbl_08059e2a
    strb r6, [r4, #3]
    strb r5, [r4, #4]
lbl_08059e2a:
    mov r0, r8
    cmp r0, #0
    bne lbl_08059e44
    movs r0, #2
    strb r0, [r4, #1]
    adds r0, r5, #0
    adds r1, r6, #0
    bl sub_0805a3e0
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059e46
lbl_08059e44:
    strb r2, [r4, #1]
lbl_08059e46:
    movs r1, #1
lbl_08059e48:
    adds r0, r1, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start store_broken_non_reform_block
store_broken_non_reform_block: @ 0x08059e54
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r8, r1
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    ldr r4, lbl_08059e90 @ =gBrokenBlocks
    movs r6, #0
    adds r2, r4, #0
lbl_08059e70:
    ldrb r1, [r4, #1]
    cmp r1, #0
    bne lbl_08059e94
    strb r1, [r4]
    movs r0, #2
    strb r0, [r4, #1]
    strb r7, [r4, #2]
    strh r1, [r4, #6]
    strb r3, [r4, #3]
    mov r0, r8
    strb r0, [r4, #4]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059eea
    .align 2, 0
lbl_08059e90: .4byte gBrokenBlocks
lbl_08059e94:
    adds r6, #1
    adds r4, #8
    cmp r6, #0x2f
    ble lbl_08059e70
    movs r1, #4
lbl_08059e9e:
    adds r4, r2, #0
    movs r6, #0
lbl_08059ea2:
    ldrb r5, [r4]
    cmp r5, #0
    bne lbl_08059edc
    ldrb r0, [r4, #1]
    cmp r0, r1
    blt lbl_08059edc
    ldrb r1, [r4, #4]
    ldrb r2, [r4, #3]
    movs r0, #0
    str r3, [sp]
    bl set_bg1_block_value
    strb r5, [r4]
    movs r0, #2
    strb r0, [r4, #1]
    strb r7, [r4, #2]
    strh r5, [r4, #6]
    ldr r3, [sp]
    strb r3, [r4, #3]
    mov r0, r8
    strb r0, [r4, #4]
    lsls r0, r6, #3
    ldr r1, lbl_08059ed8 @ =gBrokenBlocks
    adds r0, r0, r1
    bl breaking_reforming_block_anim
    b lbl_08059eea
    .align 2, 0
lbl_08059ed8: .4byte gBrokenBlocks
lbl_08059edc:
    adds r6, #1
    adds r4, #8
    cmp r6, #0x2f
    ble lbl_08059ea2
    asrs r1, r1, #1
    cmp r1, #0
    bne lbl_08059e9e
lbl_08059eea:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08059ef8
sub_08059ef8: @ 0x08059ef8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    movs r1, #0
    ldr r3, lbl_08059f6c @ =gBrokenBlocks
    movs r4, #0
    ldrb r0, [r3, #3]
    mov ip, r3
    cmp r0, r6
    bne lbl_08059f1a
    ldrb r0, [r3, #4]
    cmp r0, r5
    beq lbl_08059f62
lbl_08059f1a:
    movs r2, #0x80
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    bne lbl_08059f2e
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08059f2e
    adds r1, r4, #0
    orrs r1, r2
lbl_08059f2e:
    adds r4, #1
    adds r3, #8
    cmp r4, #0x2f
    bgt lbl_08059f44
    ldrb r0, [r3, #3]
    cmp r0, r6
    bne lbl_08059f1a
    ldrb r0, [r3, #4]
    cmp r0, r5
    bne lbl_08059f1a
    movs r1, #0
lbl_08059f44:
    cmp r1, #0
    beq lbl_08059f62
    movs r0, #0x7f
    ands r1, r0
    lsls r0, r1, #3
    mov r1, ip
    adds r3, r0, r1
    movs r0, #0
    strb r0, [r3]
    strb r0, [r3, #1]
    strb r7, [r3, #2]
    strh r0, [r3, #6]
    strb r6, [r3, #3]
    strb r5, [r3, #4]
    movs r1, #1
lbl_08059f62:
    adds r0, r1, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059f6c: .4byte gBrokenBlocks

    thumb_func_start check_samus_in_reforming_block
check_samus_in_reforming_block: @ 0x08059f70
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r6, #0
    ldr r1, lbl_08059fd8 @ =gSamusData
    ldrh r3, [r1, #0x12]
    ldr r2, lbl_08059fdc @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x6e
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r3, r0
    asrs r0, r0, #6
    cmp r0, r4
    bgt lbl_08059fa4
    adds r0, r2, #0
    adds r0, #0x72
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r3, r0
    asrs r0, r0, #6
    cmp r4, r0
    bgt lbl_08059fa4
    movs r6, #1
lbl_08059fa4:
    movs r3, #0
    ldrh r1, [r1, #0x14]
    adds r0, r2, #0
    adds r0, #0x70
    movs r4, #0
    ldrsh r0, [r0, r4]
    adds r0, r1, r0
    asrs r0, r0, #6
    cmp r0, r5
    bgt lbl_08059fca
    adds r0, r2, #0
    adds r0, #0x74
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r1, r0
    asrs r0, r0, #6
    cmp r5, r0
    bgt lbl_08059fca
    movs r3, #1
lbl_08059fca:
    movs r0, #0
    cmp r6, #0
    beq lbl_08059fd2
    adds r0, r3, #0
lbl_08059fd2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059fd8: .4byte gSamusData
lbl_08059fdc: .4byte gSamusPhysics

    thumb_func_start start_bomb_chain
start_bomb_chain: @ 0x08059fe0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov ip, r2
    movs r0, #0
    mov r8, r0
    movs r2, #3
    ldr r0, lbl_0805a04c @ =gBombchains
    movs r4, #7
    ands r4, r5
    movs r1, #8
    rsbs r1, r1, #0
    mov sl, r1
    ldr r6, lbl_0805a050 @ =gActiveBombChainTypes
    ldr r1, lbl_0805a054 @ =0x08345c28
    adds r3, r0, #0
    adds r3, #0xc
    lsls r0, r5, #2
    adds r7, r0, r1
lbl_0805a018:
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0805a058
    movs r0, #1
    strb r0, [r3]
    mov r0, sb
    strb r0, [r3, #1]
    mov r1, ip
    strb r1, [r3, #2]
    ldrb r0, [r3, #3]
    movs r1, #0x40
    orrs r0, r1
    movs r1, #0x80
    orrs r0, r1
    mov r1, sl
    ands r0, r1
    orrs r0, r4
    strb r0, [r3, #3]
    ldrb r0, [r6]
    ldrb r1, [r7]
    orrs r0, r1
    strb r0, [r6]
    movs r0, #1
    mov r8, r0
    b lbl_0805a066
    .align 2, 0
lbl_0805a04c: .4byte gBombchains
lbl_0805a050: .4byte gActiveBombChainTypes
lbl_0805a054: .4byte 0x08345c28
lbl_0805a058:
    subs r3, #4
    subs r2, #1
    cmp r2, #0
    bge lbl_0805a018
    mov r1, r8
    cmp r1, #0
    beq lbl_0805a07e
lbl_0805a066:
    ldr r2, lbl_0805a090 @ =gActiveBombChainTypes
    ldr r1, lbl_0805a094 @ =0x08345c28
    lsls r0, r5, #2
    adds r0, r0, r1
    ldrb r1, [r2]
    ldrb r0, [r0]
    cmp r1, r0
    bne lbl_0805a07e
    movs r0, #0x9b
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0805a07e:
    mov r0, r8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805a090: .4byte gActiveBombChainTypes
lbl_0805a094: .4byte 0x08345c28

    thumb_func_start process_bomb_chains
process_bomb_chains: @ 0x0805a098
    push {r4, r5, lr}
    sub sp, #8
    ldr r4, lbl_0805a150 @ =gBombchains
    ldr r0, lbl_0805a154 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    lsls r0, r0, #2
    adds r4, r0, r4
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0805a0b2
    b lbl_0805a320
lbl_0805a0b2:
    movs r3, #0
    ldr r0, [r4]
    lsls r2, r0, #5
    lsrs r0, r2, #0x1d
    cmp r0, #3
    bls lbl_0805a0c0
    movs r3, #1
lbl_0805a0c0:
    ldr r1, lbl_0805a158 @ =0x08345c28
    lsrs r0, r2, #0x1d
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrh r1, [r0, #2]
    ldr r0, lbl_0805a15c @ =0xffff0000
    mov r5, sp
    ldr r2, [sp, #4]
    ands r2, r0
    orrs r2, r1
    str r2, [sp, #4]
    ldrb r0, [r5, #4]
    subs r0, #0x10
    lsls r0, r0, #0x18
    lsrs r0, r0, #8
    ldr r1, lbl_0805a160 @ =0xff00ffff
    ands r1, r2
    orrs r1, r0
    str r1, [sp, #4]
    movs r0, #0
    str r0, [sp]
    cmp r3, #0
    beq lbl_0805a0f0
    b lbl_0805a1f4
lbl_0805a0f0:
    ldrb r3, [r4, #1]
    str r3, [sp]
    ldrb r1, [r4, #3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a18a
    ldrb r0, [r4, #2]
    ldrb r1, [r4]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    ldr r2, lbl_0805a164 @ =0x0000ffff
    ands r2, r3
    orrs r2, r0
    str r2, [sp]
    lsrs r0, r2, #0x10
    cmp r0, #1
    bls lbl_0805a144
    ldr r3, lbl_0805a168 @ =gBGPointersAndDimensions
    lsrs r2, r2, #0x10
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a16c @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a170
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a18a
lbl_0805a144:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a18a
    .align 2, 0
lbl_0805a150: .4byte gBombchains
lbl_0805a154: .4byte gFrameCounter8Bit
lbl_0805a158: .4byte 0x08345c28
lbl_0805a15c: .4byte 0xffff0000
lbl_0805a160: .4byte 0xff00ffff
lbl_0805a164: .4byte 0x0000ffff
lbl_0805a168: .4byte gBGPointersAndDimensions
lbl_0805a16c: .4byte gTilemapAndClipPointers
lbl_0805a170:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #0
    bl sub_0805a330
lbl_0805a18a:
    ldrb r1, [r4, #3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0805a196
    b lbl_0805a2e8
lbl_0805a196:
    ldrb r0, [r4, #2]
    ldrb r1, [r4]
    adds r0, r0, r1
    mov r5, sp
    strh r0, [r5, #2]
    ldrh r2, [r5, #2]
    ldr r3, lbl_0805a1ec @ =gBGPointersAndDimensions
    ldrh r0, [r3, #0x1e]
    subs r0, #2
    cmp r2, r0
    blt lbl_0805a1ae
    b lbl_0805a2be
lbl_0805a1ae:
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a1f0 @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0805a2b4
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #1
    bl sub_0805a330
    b lbl_0805a2e8
    .align 2, 0
lbl_0805a1ec: .4byte gBGPointersAndDimensions
lbl_0805a1f0: .4byte gTilemapAndClipPointers
lbl_0805a1f4:
    ldrb r0, [r4, #2]
    strh r0, [r5, #2]
    ldrb r1, [r4, #3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a272
    ldrb r0, [r4, #1]
    ldrb r1, [r4]
    subs r0, r0, r1
    mov r1, sp
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bls lbl_0805a244
    ldr r3, lbl_0805a250 @ =gBGPointersAndDimensions
    ldrh r2, [r5, #2]
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a254 @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a258
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a272
lbl_0805a244:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a272
    .align 2, 0
lbl_0805a250: .4byte gBGPointersAndDimensions
lbl_0805a254: .4byte gTilemapAndClipPointers
lbl_0805a258:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #2
    bl sub_0805a330
lbl_0805a272:
    ldrb r1, [r4, #3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a2e8
    ldrb r0, [r4, #1]
    ldrb r1, [r4]
    adds r0, r0, r1
    mov r1, sp
    strh r0, [r1]
    mov r0, sp
    ldrh r2, [r0]
    ldr r5, lbl_0805a2c8 @ =gBGPointersAndDimensions
    ldrh r1, [r5, #0x1c]
    subs r0, r1, #2
    cmp r2, r0
    bge lbl_0805a2be
    mov r3, sp
    ldrh r0, [r3, #2]
    muls r0, r1, r0
    adds r0, r0, r2
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a2cc @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r3, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a2d0
lbl_0805a2b4:
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a2e8
lbl_0805a2be:
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a2e8
    .align 2, 0
lbl_0805a2c8: .4byte gBGPointersAndDimensions
lbl_0805a2cc: .4byte gTilemapAndClipPointers
lbl_0805a2d0:
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r3, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #3
    bl sub_0805a330
lbl_0805a2e8:
    ldrb r0, [r4, #3]
    movs r1, #0xc0
    ands r1, r0
    cmp r1, #0
    beq lbl_0805a2fa
    ldrb r0, [r4]
    adds r0, #1
    strb r0, [r4]
    b lbl_0805a320
lbl_0805a2fa:
    strb r1, [r4]
    ldr r2, lbl_0805a328 @ =gActiveBombChainTypes
    ldr r1, lbl_0805a32c @ =0x08345c28
    ldr r0, [r4]
    lsls r0, r0, #5
    lsrs r0, r0, #0x1d
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r0]
    ldrb r0, [r2]
    bics r0, r1
    strb r0, [r2]
    cmp r0, #0
    bne lbl_0805a320
    movs r0, #0x9b
    lsls r0, r0, #1
    movs r1, #0xa
    bl SoundFade
lbl_0805a320:
    add sp, #8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a328: .4byte gActiveBombChainTypes
lbl_0805a32c: .4byte 0x08345c28

    thumb_func_start sub_0805a330
sub_0805a330: @ 0x0805a330
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov sb, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov r8, r2
    ldr r1, lbl_0805a3d4 @ =gCurrentClipdataAffectingAction
    movs r0, #0xf
    strb r0, [r1]
    ldr r4, lbl_0805a3d8 @ =gBGPointersAndDimensions
    ldrh r0, [r4, #0x1c]
    mov r1, r8
    muls r1, r0, r1
    adds r0, r1, #0
    add r0, sb
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    cmp r2, #0
    beq lbl_0805a370
    mov r0, r8
    mov r1, sb
    bl BlockApplyCCAA
lbl_0805a370:
    movs r6, #0
    mov sl, r4
    lsls r7, r5, #2
    ldr r2, lbl_0805a3dc @ =0x08345cde
    adds r5, r7, r2
lbl_0805a37a:
    lsls r0, r6, #1
    adds r1, r7, #1
    adds r0, r0, r1
    ldr r1, lbl_0805a3dc @ =0x08345cde
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov r2, r8
    adds r4, r2, r0
    mov r1, sl
    ldrh r0, [r1, #0x1c]
    muls r0, r4, r0
    movs r1, #0
    ldrsb r1, [r5, r1]
    mov r2, sb
    adds r3, r2, r1
    adds r0, r0, r3
    mov r2, sl
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    cmp r2, #0
    beq lbl_0805a3b8
    lsls r0, r4, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r3, #0x10
    lsrs r1, r1, #0x10
    bl BlockApplyCCAA
lbl_0805a3b8:
    adds r5, #2
    adds r6, #1
    cmp r6, #1
    ble lbl_0805a37a
    ldr r1, lbl_0805a3d4 @ =gCurrentClipdataAffectingAction
    movs r0, #0
    strb r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a3d4: .4byte gCurrentClipdataAffectingAction
lbl_0805a3d8: .4byte gBGPointersAndDimensions
lbl_0805a3dc: .4byte 0x08345cde

    thumb_func_start sub_0805a3e0
sub_0805a3e0: @ 0x0805a3e0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r6, r4, #0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    adds r7, r5, #0
    ldr r2, lbl_0805a46c @ =gBGPointersAndDimensions
    ldrh r0, [r2, #0x1c]
    adds r1, r4, #0
    muls r1, r0, r1
    adds r0, r1, #0
    adds r0, r5, r0
    lsls r0, r0, #0x10
    ldr r1, [r2, #0x18]
    lsrs r0, r0, #0xf
    adds r1, r0, r1
    movs r3, #0
    strh r3, [r1]
    ldr r1, [r2, #8]
    adds r0, r0, r1
    strh r3, [r0]
    ldr r0, lbl_0805a470 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r1, r0, #6
    subs r0, r1, #4
    cmp r0, r4
    bgt lbl_0805a466
    adds r0, #0x11
    cmp r4, r0
    bgt lbl_0805a466
    ldr r0, lbl_0805a474 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r1, r0, #6
    subs r0, r1, #4
    cmp r0, r5
    bgt lbl_0805a466
    adds r0, #0x16
    cmp r5, r0
    bgt lbl_0805a466
    ldr r3, lbl_0805a478 @ =0x06001000
    movs r0, #0x10
    ands r0, r5
    cmp r0, #0
    beq lbl_0805a43c
    ldr r3, lbl_0805a47c @ =0x06001800
lbl_0805a43c:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r3, r3, r0
    ldr r0, lbl_0805a480 @ =gTilemapAndClipPointers
    ldr r1, [r0]
    ldrh r0, [r1]
    strh r0, [r3]
    ldrh r0, [r1, #2]
    strh r0, [r3, #2]
    adds r2, r3, #0
    adds r2, #0x40
    ldrh r0, [r1, #4]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #6]
    strh r0, [r2]
lbl_0805a466:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a46c: .4byte gBGPointersAndDimensions
lbl_0805a470: .4byte gBG1YPosition
lbl_0805a474: .4byte gBG1XPosition
lbl_0805a478: .4byte 0x06001000
lbl_0805a47c: .4byte 0x06001800
lbl_0805a480: .4byte gTilemapAndClipPointers

    thumb_func_start mother_brain_update_glass
mother_brain_update_glass: @ 0x0805a484
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov ip, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r6, r2, #0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    adds r7, r3, #0
    ldr r0, lbl_0805a548 @ =gBGPointersAndDimensions
    lsls r1, r5, #3
    adds r1, r1, r0
    ldrh r0, [r1, #4]
    muls r0, r2, r0
    adds r0, r0, r3
    ldr r1, [r1]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, ip
    strh r1, [r0]
    ldr r0, lbl_0805a54c @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r2
    bgt lbl_0805a540
    adds r0, #0x11
    cmp r2, r0
    bgt lbl_0805a540
    ldr r0, lbl_0805a550 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r3
    bgt lbl_0805a540
    adds r0, #0x16
    cmp r3, r0
    bgt lbl_0805a540
    lsls r1, r5, #0xc
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r5, r1, r0
    movs r0, #0x10
    ands r0, r3
    cmp r0, #0
    beq lbl_0805a4ea
    ldr r0, lbl_0805a554 @ =0x06000800
    adds r5, r1, r0
lbl_0805a4ea:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r5, r5, r0
    mov r1, ip
    lsls r0, r1, #0x12
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    ldr r3, lbl_0805a558 @ =gTilemapAndClipPointers
    movs r0, #1
    orrs r4, r0
    adds r2, r4, #0
    ldr r3, [r3]
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1]
    strh r0, [r5]
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r3
    ldrh r0, [r2]
    strh r0, [r5, #2]
    adds r2, r5, #0
    adds r2, #0x40
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r1, [r1]
    strh r1, [r2]
    adds r1, r5, #0
    adds r1, #0x42
    lsrs r0, r0, #0xf
    adds r0, r0, r3
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0805a540:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a548: .4byte gBGPointersAndDimensions
lbl_0805a54c: .4byte gBG1YPosition
lbl_0805a550: .4byte gBG1XPosition
lbl_0805a554: .4byte 0x06000800
lbl_0805a558: .4byte gTilemapAndClipPointers

    thumb_func_start set_bg1_block_value
set_bg1_block_value: @ 0x0805a55c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    adds r6, r3, #0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r7, r2, #0
    ldr r1, lbl_0805a610 @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0xc]
    muls r0, r3, r0
    adds r0, r0, r2
    ldr r1, [r1, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, ip
    strh r1, [r0]
    ldr r0, lbl_0805a614 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r3
    bgt lbl_0805a608
    adds r0, #0x11
    cmp r3, r0
    bgt lbl_0805a608
    ldr r0, lbl_0805a618 @ =gBG1XPosition
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r2
    bgt lbl_0805a608
    adds r0, #0x16
    cmp r2, r0
    bgt lbl_0805a608
    ldr r5, lbl_0805a61c @ =0x06001000
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_0805a5b2
    ldr r5, lbl_0805a620 @ =0x06001800
lbl_0805a5b2:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r5, r5, r0
    mov r1, ip
    lsls r0, r1, #0x12
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    ldr r3, lbl_0805a624 @ =gTilemapAndClipPointers
    movs r0, #1
    orrs r4, r0
    adds r2, r4, #0
    ldr r3, [r3]
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1]
    strh r0, [r5]
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r3
    ldrh r0, [r2]
    strh r0, [r5, #2]
    adds r2, r5, #0
    adds r2, #0x40
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r1, [r1]
    strh r1, [r2]
    adds r1, r5, #0
    adds r1, #0x42
    lsrs r0, r0, #0xf
    adds r0, r0, r3
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0805a608:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a610: .4byte gBGPointersAndDimensions
lbl_0805a614: .4byte gBG1YPosition
lbl_0805a618: .4byte gBG1XPosition
lbl_0805a61c: .4byte 0x06001000
lbl_0805a620: .4byte 0x06001800
lbl_0805a624: .4byte gTilemapAndClipPointers

    thumb_func_start set_raw_bg1_block_value
set_raw_bg1_block_value: @ 0x0805a628
    push {r4, lr}
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldr r4, lbl_0805a648 @ =gBGPointersAndDimensions
    ldrh r3, [r4, #0xc]
    muls r1, r3, r1
    adds r1, r1, r2
    ldr r2, [r4, #8]
    lsls r1, r1, #1
    adds r1, r1, r2
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a648: .4byte gBGPointersAndDimensions

    thumb_func_start set_clipdata_block_value
set_clipdata_block_value: @ 0x0805a64c
    push {r4, lr}
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldr r4, lbl_0805a66c @ =gBGPointersAndDimensions
    ldrh r3, [r4, #0x1c]
    muls r1, r3, r1
    adds r1, r1, r2
    ldr r2, [r4, #0x18]
    lsls r1, r1, #1
    adds r1, r1, r2
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a66c: .4byte gBGPointersAndDimensions

    thumb_func_start check_special_clipdata
check_special_clipdata: @ 0x0805a670
    push {lr}
    movs r0, #0
    bl check_grabbing_crumble_block
    ldr r0, lbl_0805a688 @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1d
    bne lbl_0805a68c
    bl check_touching_transition_on_elevator
    b lbl_0805a6c0
    .align 2, 0
lbl_0805a688: .4byte gSamusData
lbl_0805a68c:
    ldr r0, lbl_0805a6a8 @ =gDisableDoorAndTanks
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805a6c0
    ldr r0, lbl_0805a6ac @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a6b0
    bl check_touching_transition_or_tank
    b lbl_0805a6bc
    .align 2, 0
lbl_0805a6a8: .4byte gDisableDoorAndTanks
lbl_0805a6ac: .4byte gFrameCounter8Bit
lbl_0805a6b0:
    ldr r0, lbl_0805a6c4 @ =gDisableClipdataChangingTransparency
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805a6bc
    bl apply_clipdata_changing_transparency
lbl_0805a6bc:
    bl check_walking_on_crumble_block
lbl_0805a6c0:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a6c4: .4byte gDisableClipdataChangingTransparency

    thumb_func_start apply_clipdata_changing_transparency
apply_clipdata_changing_transparency: @ 0x0805a6c8
    push {r4, r5, lr}
    ldr r0, lbl_0805a6f8 @ =gSamusData
    ldrh r2, [r0, #0x12]
    adds r5, r0, #0
    ldr r1, lbl_0805a6fc @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r4, r1, #0
    cmp r2, r0
    ble lbl_0805a6de
    adds r2, r0, #0
lbl_0805a6de:
    asrs r3, r2, #6
    ldr r0, lbl_0805a700 @ =gSamusPhysics
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r5, [r5, #0x14]
    adds r2, r0, r5
    cmp r2, #0
    bge lbl_0805a704
    movs r2, #0
    b lbl_0805a70e
    .align 2, 0
lbl_0805a6f8: .4byte gSamusData
lbl_0805a6fc: .4byte gBGPointersAndDimensions
lbl_0805a700: .4byte gSamusPhysics
lbl_0805a704:
    ldrh r0, [r4, #0x1e]
    lsls r0, r0, #6
    cmp r2, r0
    ble lbl_0805a70e
    adds r2, r0, #0
lbl_0805a70e:
    asrs r1, r2, #6
    ldr r2, lbl_0805a750 @ =gTilemapAndClipPointers
    ldrh r0, [r4, #0x1c]
    muls r0, r1, r0
    adds r0, r0, r3
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0805a76a
    adds r0, r1, #0
    bl check_clipdata_behavior_change_bldalpha
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0805a76a
    ldr r0, lbl_0805a754 @ =0x0000ffff
    cmp r1, r0
    bne lbl_0805a75c
    ldr r1, lbl_0805a758 @ =gDefaultTransparency
    ldrb r0, [r1, #3]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    b lbl_0805a76a
    .align 2, 0
lbl_0805a750: .4byte gTilemapAndClipPointers
lbl_0805a754: .4byte 0x0000ffff
lbl_0805a758: .4byte gDefaultTransparency
lbl_0805a75c:
    movs r0, #0xff
    ands r0, r1
    lsrs r1, r1, #8
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
lbl_0805a76a:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start check_clipdata_behavior_change_bldalpha
check_clipdata_behavior_change_bldalpha: @ 0x0805a770
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, r1, #0
    subs r2, #0x44
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xa
    bhi lbl_0805a790
    ldr r1, lbl_0805a78c @ =0x08345cc8
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    b lbl_0805a798
    .align 2, 0
lbl_0805a78c: .4byte 0x08345cc8
lbl_0805a790:
    movs r0, #0
    cmp r1, #0x4f
    bne lbl_0805a798
    ldr r0, lbl_0805a79c @ =0x0000ffff
lbl_0805a798:
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805a79c: .4byte 0x0000ffff

    thumb_func_start check_walking_on_crumble_block
check_walking_on_crumble_block: @ 0x0805a7a0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r5, lbl_0805a858 @ =gSamusData
    movs r1, #0x18
    ldrsh r0, [r5, r1]
    lsrs r3, r0, #0x1f
    ldr r4, lbl_0805a85c @ =gSamusPhysics
    adds r0, r4, #0
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_0805a7bc
    adds r3, #1
lbl_0805a7bc:
    cmp r3, #0
    bne lbl_0805a89e
    ldrh r1, [r5, #0x12]
    adds r0, r4, #0
    adds r0, #0x72
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r1, r0
    lsls r0, r3, #0xa
    lsrs r6, r0, #0x10
    ldr r2, lbl_0805a860 @ =gBGPointersAndDimensions
    ldrh r3, [r2, #0x1c]
    cmp r6, r3
    bls lbl_0805a7da
    ldrh r6, [r2, #0x1c]
lbl_0805a7da:
    adds r0, r4, #0
    adds r0, #0x6e
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r3, r1, r0
    cmp r3, #0
    bge lbl_0805a7ea
    movs r3, #0
lbl_0805a7ea:
    lsls r0, r3, #0xa
    lsrs r1, r0, #0x10
    adds r0, r4, #0
    adds r0, #0x74
    movs r3, #0
    ldrsh r0, [r0, r3]
    ldrh r5, [r5, #0x14]
    adds r3, r0, r5
    adds r0, r3, #2
    lsls r0, r0, #0xa
    lsrs r5, r0, #0x10
    ldrh r0, [r2, #0x1e]
    cmp r5, r0
    bls lbl_0805a808
    ldrh r5, [r2, #0x1e]
lbl_0805a808:
    adds r4, r1, #0
    cmp r4, r6
    bhi lbl_0805a89e
    ldr r1, lbl_0805a864 @ =gTilemapAndClipPointers
    mov r8, r1
    ldr r7, lbl_0805a868 @ =0x00000401
lbl_0805a814:
    ldr r1, lbl_0805a860 @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    muls r0, r5, r0
    adds r0, r0, r4
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r2, r8
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    cmp r3, #0x23
    bne lbl_0805a86c
    movs r3, #0
    ldr r1, lbl_0805a858 @ =gSamusData
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805a840
    cmp r0, #0x12
    bne lbl_0805a848
lbl_0805a840:
    ldrb r0, [r1, #5]
    cmp r0, #0
    beq lbl_0805a848
    movs r3, #1
lbl_0805a848:
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    movs r0, #4
    adds r1, r4, #0
    adds r2, r5, #0
    bl store_broken_reform_block
    b lbl_0805a894
    .align 2, 0
lbl_0805a858: .4byte gSamusData
lbl_0805a85c: .4byte gSamusPhysics
lbl_0805a860: .4byte gBGPointersAndDimensions
lbl_0805a864: .4byte gTilemapAndClipPointers
lbl_0805a868: .4byte 0x00000401
lbl_0805a86c:
    cmp r3, #0x2e
    bne lbl_0805a894
    movs r0, #5
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #1
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805a894
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_bg1_block_value
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
lbl_0805a894:
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, r6
    bls lbl_0805a814
lbl_0805a89e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start check_touching_transition_on_elevator
check_touching_transition_on_elevator: @ 0x0805a8a8
    push {r4, r5, r6, r7, lr}
    ldr r2, lbl_0805a8e4 @ =gSamusData
    ldrh r1, [r2, #0x10]
    movs r0, #0x40
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    ldrh r3, [r2, #0x12]
    ldr r1, lbl_0805a8e8 @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r6, r1, #0
    cmp r3, r0
    ble lbl_0805a8c8
    adds r3, r0, #0
lbl_0805a8c8:
    lsls r0, r3, #0xa
    lsrs r5, r0, #0x10
    cmp r7, #0
    bne lbl_0805a8f0
    ldr r0, lbl_0805a8ec @ =gSamusPhysics
    adds r0, #0x74
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    adds r3, r0, #0
    adds r3, #0x80
    b lbl_0805a900
    .align 2, 0
lbl_0805a8e4: .4byte gSamusData
lbl_0805a8e8: .4byte gBGPointersAndDimensions
lbl_0805a8ec: .4byte gSamusPhysics
lbl_0805a8f0:
    ldr r0, lbl_0805a90c @ =gSamusPhysics
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    adds r3, r0, #0
    subs r3, #0x80
lbl_0805a900:
    lsls r0, r3, #0x10
    lsrs r1, r0, #0x10
    cmp r3, #0
    bge lbl_0805a910
    movs r1, #0
    b lbl_0805a91c
    .align 2, 0
lbl_0805a90c: .4byte gSamusPhysics
lbl_0805a910:
    ldrh r2, [r6, #0x1e]
    lsls r0, r2, #6
    cmp r1, r0
    ble lbl_0805a91c
    lsls r0, r2, #0x16
    lsrs r1, r0, #0x10
lbl_0805a91c:
    lsrs r4, r1, #6
    ldrh r0, [r6, #0x1c]
    muls r0, r4, r0
    adds r0, r0, r5
    ldr r1, [r6, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    ldr r0, lbl_0805a944 @ =gTilemapAndClipPointers
    ldr r1, [r0, #8]
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    movs r3, #0
    cmp r7, #0
    bne lbl_0805a948
    cmp r1, #4
    bne lbl_0805a94e
    b lbl_0805a952
    .align 2, 0
lbl_0805a944: .4byte gTilemapAndClipPointers
lbl_0805a948:
    cmp r1, #5
    bne lbl_0805a94e
    movs r3, #1
lbl_0805a94e:
    cmp r3, #0
    beq lbl_0805a966
lbl_0805a952:
    adds r0, r4, #0
    adds r1, r5, #0
    bl check_area_connection
    cmp r0, #0
    bne lbl_0805a966
    adds r0, r4, #0
    adds r1, r5, #0
    bl check_enter_door
lbl_0805a966:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start check_touching_transition_or_tank
check_touching_transition_or_tank: @ 0x0805a96c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    ldr r2, lbl_0805a998 @ =gSamusPhysics
    adds r0, r2, #0
    adds r0, #0x72
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    ldr r1, lbl_0805a99c @ =gSamusData
    asrs r0, r0, #0x11
    ldrh r3, [r1, #0x12]
    adds r4, r0, r3
    adds r3, r2, #0
    adds r5, r1, #0
    cmp r4, #0
    bge lbl_0805a9a4
    movs r4, #0
    ldr r6, lbl_0805a9a0 @ =gBGPointersAndDimensions
    b lbl_0805a9b2
    .align 2, 0
lbl_0805a998: .4byte gSamusPhysics
lbl_0805a99c: .4byte gSamusData
lbl_0805a9a0: .4byte gBGPointersAndDimensions
lbl_0805a9a4:
    ldr r1, lbl_0805a9cc @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r6, r1, #0
    cmp r4, r0
    ble lbl_0805a9b2
    adds r4, r0, #0
lbl_0805a9b2:
    asrs r0, r4, #6
    str r0, [sp, #0x24]
    adds r0, r3, #0
    adds r0, #0x6e
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r1, [r5, #0x12]
    adds r4, r0, r1
    cmp r4, #0
    bge lbl_0805a9d0
    movs r4, #0
    b lbl_0805a9da
    .align 2, 0
lbl_0805a9cc: .4byte gBGPointersAndDimensions
lbl_0805a9d0:
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805a9da
    adds r4, r0, #0
lbl_0805a9da:
    add r1, sp, #0x24
    asrs r0, r4, #6
    str r0, [r1, #4]
    ldrh r4, [r5, #0x12]
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805a9ec
    adds r4, r0, #0
lbl_0805a9ec:
    asrs r0, r4, #6
    str r0, [sp, #0x2c]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r2, [r5, #0x14]
    adds r4, r0, r2
    cmp r4, #0
    bge lbl_0805aa06
    movs r4, #0
    b lbl_0805aa10
lbl_0805aa06:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa10
    adds r4, r0, #0
lbl_0805aa10:
    asrs r0, r4, #6
    str r0, [sp, #0x18]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    ldrh r1, [r5, #0x14]
    adds r4, r0, r1
    cmp r4, #0
    bge lbl_0805aa2a
    movs r4, #0
    b lbl_0805aa34
lbl_0805aa2a:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa34
    adds r4, r0, #0
lbl_0805aa34:
    add r2, sp, #0x18
    asrs r0, r4, #6
    str r0, [r2, #4]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r1, r0, #0x12
    asrs r0, r0, #0x11
    adds r1, r1, r0
    ldrh r5, [r5, #0x14]
    adds r4, r1, r5
    cmp r4, #0
    bge lbl_0805aa54
    movs r4, #0
    b lbl_0805aa5e
lbl_0805aa54:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa5e
    adds r4, r0, #0
lbl_0805aa5e:
    asrs r0, r4, #6
    str r0, [sp, #0x20]
    ldr r0, lbl_0805aaec @ =gBGPointersAndDimensions
    ldrh r2, [r0, #0x1c]
    mov r8, r2
    ldr r7, [r0, #0x18]
    ldr r0, lbl_0805aaf0 @ =gTilemapAndClipPointers
    ldr r3, [r0, #8]
    add r6, sp, #8
    add r2, sp, #0x24
    movs r5, #1
lbl_0805aa74:
    ldr r0, [sp, #0x18]
    mov r1, r8
    muls r1, r0, r1
    adds r0, r1, #0
    ldm r2!, {r1}
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r4, [r0]
    lsls r0, r4, #1
    adds r0, r0, r3
    ldrh r0, [r0]
    stm r6!, {r0}
    subs r5, #1
    cmp r5, #0
    bge lbl_0805aa74
    movs r5, #0
    ldr r0, lbl_0805aaec @ =gBGPointersAndDimensions
    ldrh r2, [r0, #0x1c]
    mov ip, r2
    ldr r0, [r0, #0x18]
    mov r8, r0
    ldr r0, lbl_0805aaf0 @ =gTilemapAndClipPointers
    ldr r6, [r0, #8]
    add r7, sp, #0x10
    add r3, sp, #0x1c
    add r2, sp, #0x24
lbl_0805aaaa:
    ldm r3!, {r0}
    mov r1, ip
    muls r1, r0, r1
    adds r0, r1, #0
    ldr r1, [r2, #8]
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, r8
    ldrh r4, [r0]
    lsls r0, r4, #1
    adds r0, r0, r6
    ldrh r0, [r0]
    stm r7!, {r0}
    adds r5, #1
    cmp r5, #1
    ble lbl_0805aaaa
    ldr r1, [sp, #8]
    ldr r2, [sp, #0xc]
    adds r0, r1, #0
    orrs r0, r2
    ldr r3, [sp, #0x10]
    orrs r0, r3
    ldr r5, [sp, #0x14]
    orrs r0, r5
    cmp r0, #0
    bne lbl_0805aae0
    b lbl_0805ad5e
lbl_0805aae0:
    movs r4, #1
    rsbs r4, r4, #0
    cmp r1, #3
    bne lbl_0805aaf4
    movs r4, #0
    b lbl_0805ab0a
    .align 2, 0
lbl_0805aaec: .4byte gBGPointersAndDimensions
lbl_0805aaf0: .4byte gTilemapAndClipPointers
lbl_0805aaf4:
    cmp r2, #3
    bne lbl_0805aafc
    movs r4, #1
    b lbl_0805ab0a
lbl_0805aafc:
    cmp r3, #4
    bne lbl_0805ab04
    movs r4, #2
    b lbl_0805ab0a
lbl_0805ab04:
    cmp r5, #5
    bne lbl_0805ab0a
    movs r4, #3
lbl_0805ab0a:
    adds r0, r4, #1
    cmp r0, #0
    beq lbl_0805ab4c
    ldr r1, lbl_0805ab48 @ =0x08345cee
    lsls r2, r4, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    lsls r0, r0, #2
    mov r5, sp
    adds r5, r5, r0
    adds r5, #0x18
    ldrh r0, [r5]
    adds r1, #1
    adds r2, r2, r1
    ldrb r1, [r2]
    lsls r1, r1, #2
    mov r4, sp
    adds r4, r4, r1
    adds r4, #0x24
    ldrh r1, [r4]
    bl check_enter_door
    cmp r0, #0
    beq lbl_0805ab3c
    b lbl_0805ad5e
lbl_0805ab3c:
    ldrh r0, [r5]
    ldrh r1, [r4]
    bl check_area_connection
    b lbl_0805ad5e
    .align 2, 0
lbl_0805ab48: .4byte 0x08345cee
lbl_0805ab4c:
    ldr r0, lbl_0805ac18 @ =gCollectingTank
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805ab5a
    b lbl_0805ad5e
lbl_0805ab5a:
    movs r2, #0
    mov sl, r2
    movs r4, #3
    add r3, sp, #0x14
    mov r8, r3
    ldr r0, lbl_0805ac1c @ =0x083459a0
    mov sb, r0
lbl_0805ab68:
    mov r1, r8
    ldr r0, [r1]
    cmp r0, #0
    bne lbl_0805ab72
    b lbl_0805ad50
lbl_0805ab72:
    subs r0, #0x34
    cmp r0, #0xb
    bls lbl_0805ab7a
    b lbl_0805ad50
lbl_0805ab7a:
    ldr r1, lbl_0805ac20 @ =0x08345c48
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r5, [r0]
    cmp r5, #0
    bne lbl_0805ab88
    b lbl_0805ad44
lbl_0805ab88:
    ldr r2, lbl_0805ac24 @ =0x08345cee
    lsls r1, r4, #1
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    lsls r0, r0, #2
    mov r7, sp
    adds r7, r7, r0
    adds r7, #0x24
    ldrb r0, [r7]
    adds r1, r1, r2
    ldrb r1, [r1]
    lsls r1, r1, #2
    mov r6, sp
    adds r6, r6, r1
    adds r6, #0x18
    ldrb r1, [r6]
    bl sub_0806cc68
    cmp r0, #0
    bne lbl_0805abb4
    b lbl_0805ad44
lbl_0805abb4:
    ldr r1, lbl_0805ac18 @ =gCollectingTank
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0805ac28 @ =gPreventMovementTimer
    movs r2, #0xfa
    lsls r2, r2, #2
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0805ac2c @ =gLastTankCollected
    mov r3, r8
    ldr r0, [r3]
    strh r0, [r1]
    ldr r0, [r7]
    strb r0, [r1, #2]
    ldr r0, [r6]
    strb r0, [r1, #3]
    cmp r5, #1
    bne lbl_0805ac40
    mov r0, sb
    ldrb r3, [r0, #0x1d]
    ldr r6, lbl_0805ac30 @ =0x083459c4
    ldr r5, lbl_0805ac34 @ =gDifficulty
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #1]
    ldr r1, lbl_0805ac38 @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldr r3, lbl_0805ac3c @ =gEquipment
    ldrh r1, [r3, #2]
    adds r2, r1, r2
    cmp r0, r2
    bge lbl_0805abfe
    b lbl_0805ad14
lbl_0805abfe:
    cmp r1, #0
    bne lbl_0805ac06
    movs r1, #1
    mov sl, r1
lbl_0805ac06:
    strh r2, [r3, #2]
    ldrb r1, [r5]
    lsls r1, r1, #2
    adds r1, r1, r6
    ldrh r0, [r3, #8]
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    strh r0, [r3, #8]
    b lbl_0805ad14
    .align 2, 0
lbl_0805ac18: .4byte gCollectingTank
lbl_0805ac1c: .4byte 0x083459a0
lbl_0805ac20: .4byte 0x08345c48
lbl_0805ac24: .4byte 0x08345cee
lbl_0805ac28: .4byte gPreventMovementTimer
lbl_0805ac2c: .4byte gLastTankCollected
lbl_0805ac30: .4byte 0x083459c4
lbl_0805ac34: .4byte gDifficulty
lbl_0805ac38: .4byte 0x083459c0
lbl_0805ac3c: .4byte gEquipment
lbl_0805ac40:
    cmp r5, #2
    bne lbl_0805ac80
    mov r2, sb
    ldrb r3, [r2, #0x1c]
    ldr r1, lbl_0805ac70 @ =0x083459c4
    ldr r0, lbl_0805ac74 @ =gDifficulty
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r2, [r0]
    ldr r0, lbl_0805ac78 @ =0x083459c0
    adds r1, r3, #0
    muls r1, r2, r1
    ldrb r0, [r0]
    adds r1, r1, r0
    ldr r3, lbl_0805ac7c @ =gEquipment
    ldrh r0, [r3]
    adds r0, r0, r2
    cmp r1, r0
    blt lbl_0805ad14
    strh r0, [r3]
    strh r0, [r3, #6]
    b lbl_0805ad14
    .align 2, 0
lbl_0805ac70: .4byte 0x083459c4
lbl_0805ac74: .4byte gDifficulty
lbl_0805ac78: .4byte 0x083459c0
lbl_0805ac7c: .4byte gEquipment
lbl_0805ac80:
    cmp r5, #3
    bne lbl_0805acd4
    mov r0, sb
    ldrb r3, [r0, #0x1e]
    ldr r6, lbl_0805acc4 @ =0x083459c4
    ldr r5, lbl_0805acc8 @ =gDifficulty
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #2]
    ldr r1, lbl_0805accc @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    ldr r3, lbl_0805acd0 @ =gEquipment
    ldrb r1, [r3, #4]
    adds r2, r1, r2
    cmp r0, r2
    blt lbl_0805ad14
    cmp r1, #0
    bne lbl_0805acb0
    movs r1, #1
    mov sl, r1
lbl_0805acb0:
    strb r2, [r3, #4]
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r0, [r0, #2]
    ldrb r2, [r3, #0xa]
    adds r0, r0, r2
    strb r0, [r3, #0xa]
    b lbl_0805ad14
    .align 2, 0
lbl_0805acc4: .4byte 0x083459c4
lbl_0805acc8: .4byte gDifficulty
lbl_0805accc: .4byte 0x083459c0
lbl_0805acd0: .4byte gEquipment
lbl_0805acd4:
    cmp r5, #4
    bne lbl_0805ad14
    mov r0, sb
    ldrb r3, [r0, #0x1f]
    ldr r6, lbl_0805ad70 @ =0x083459c4
    ldr r5, lbl_0805ad74 @ =gDifficulty
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #3]
    ldr r1, lbl_0805ad78 @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #3]
    adds r0, r0, r1
    ldr r3, lbl_0805ad7c @ =gEquipment
    ldrb r1, [r3, #5]
    adds r2, r1, r2
    cmp r0, r2
    blt lbl_0805ad14
    cmp r1, #0
    bne lbl_0805ad04
    movs r1, #1
    mov sl, r1
lbl_0805ad04:
    strb r2, [r3, #5]
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r0, [r0, #3]
    ldrb r2, [r3, #0xb]
    adds r0, r0, r2
    strb r0, [r3, #0xb]
lbl_0805ad14:
    ldr r1, lbl_0805ad80 @ =0x08345c48
    mov r3, r8
    ldr r0, [r3]
    subs r0, #0x34
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r0, [r0, #2]
    mov r1, sl
    adds r5, r0, r1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    beq lbl_0805ad44
    ldr r0, lbl_0805ad84 @ =gSamusData
    ldrh r3, [r0, #0x14]
    ldrh r0, [r0, #0x12]
    str r0, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x11
    adds r1, r5, #0
    movs r2, #6
    bl SpriteSpawnPrimary
lbl_0805ad44:
    ldr r0, lbl_0805ad88 @ =gCollectingTank
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805ad5e
lbl_0805ad50:
    movs r2, #4
    rsbs r2, r2, #0
    add r8, r2
    subs r4, #1
    cmp r4, #0
    blt lbl_0805ad5e
    b lbl_0805ab68
lbl_0805ad5e:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ad70: .4byte 0x083459c4
lbl_0805ad74: .4byte gDifficulty
lbl_0805ad78: .4byte 0x083459c0
lbl_0805ad7c: .4byte gEquipment
lbl_0805ad80: .4byte 0x08345c48
lbl_0805ad84: .4byte gSamusData
lbl_0805ad88: .4byte gCollectingTank

    thumb_func_start BGClipFinishCollectingTank
BGClipFinishCollectingTank: @ 0x0805ad8c
    push {r4, r5, r6, lr}
    ldr r1, lbl_0805addc @ =gCollectingTank
    movs r0, #0
    strb r0, [r1]
    ldr r4, lbl_0805ade0 @ =gLastTankCollected
    ldrh r0, [r4]
    subs r0, #0x34
    ldr r1, lbl_0805ade4 @ =0x08345c48
    lsls r0, r0, #3
    adds r5, r0, r1
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0805add6
    ldrb r0, [r5, #1]
    movs r6, #0
    cmp r0, #0
    beq lbl_0805adb0
    ldr r6, lbl_0805ade8 @ =0x0000043c
lbl_0805adb0:
    ldrb r1, [r4, #3]
    ldrb r2, [r4, #2]
    movs r0, #0
    bl set_bg1_block_value
    adds r0, r6, #0
    ldrb r1, [r4, #3]
    ldrb r2, [r4, #2]
    bl set_clipdata_block_value
    ldrb r0, [r4, #2]
    ldrb r1, [r4, #3]
    ldrb r2, [r5]
    bl set_item_as_collected
    ldrb r0, [r4, #2]
    ldrb r1, [r4, #3]
    bl update_minimap_square_for_collected_item
lbl_0805add6:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805addc: .4byte gCollectingTank
lbl_0805ade0: .4byte gLastTankCollected
lbl_0805ade4: .4byte 0x08345c48
lbl_0805ade8: .4byte 0x0000043c

    thumb_func_start finish_collecting_ability
finish_collecting_ability: @ 0x0805adec
    push {r4, lr}
    ldr r4, lbl_0805ae18 @ =gSamusData
    ldrh r0, [r4, #0x12]
    lsrs r0, r0, #6
    ldrh r1, [r4, #0x14]
    lsrs r1, r1, #6
    movs r2, #0x80
    bl set_item_as_collected
    ldrh r0, [r4, #0x12]
    lsrs r0, r0, #6
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrh r1, [r4, #0x14]
    lsrs r1, r1, #6
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl update_minimap_square_for_collected_item
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ae18: .4byte gSamusData

    thumb_func_start check_grabbing_crumble_block
check_grabbing_crumble_block: @ 0x0805ae1c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r0, lbl_0805aea0 @ =gSamusPhysics
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0805af0c
    movs r0, #0
    mov r8, r0
    subs r0, #0x6c
    mov sb, r0
    ldr r2, lbl_0805aea4 @ =gSamusData
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    movs r7, #0x20
    rsbs r7, r7, #0
    cmp r0, #0
    beq lbl_0805ae4c
    movs r7, #0x20
lbl_0805ae4c:
    ldrb r0, [r2]
    cmp r0, #0x15
    beq lbl_0805ae58
    cmp r0, #0x3d
    beq lbl_0805ae58
    rsbs r7, r7, #0
lbl_0805ae58:
    cmp r3, #0
    bne lbl_0805aede
    ldrh r0, [r2, #0x12]
    adds r0, r0, r7
    lsls r0, r0, #0xa
    lsrs r4, r0, #0x10
    adds r6, r4, #0
    ldrh r0, [r2, #0x14]
    add r0, sb
    lsls r0, r0, #0xa
    lsrs r3, r0, #0x10
    adds r5, r3, #0
    ldr r2, lbl_0805aea8 @ =gTilemapAndClipPointers
    ldr r1, lbl_0805aeac @ =gBGPointersAndDimensions
    ldrh r0, [r1, #0x1c]
    muls r0, r3, r0
    adds r0, r0, r4
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0x23
    bne lbl_0805aeb0
    movs r0, #4
    adds r1, r4, #0
    adds r2, r3, #0
    movs r3, #0
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805aede
    b lbl_0805af06
    .align 2, 0
lbl_0805aea0: .4byte gSamusPhysics
lbl_0805aea4: .4byte gSamusData
lbl_0805aea8: .4byte gTilemapAndClipPointers
lbl_0805aeac: .4byte gBGPointersAndDimensions
lbl_0805aeb0:
    cmp r0, #0x2e
    bne lbl_0805aede
    movs r0, #5
    adds r1, r6, #0
    adds r2, r5, #0
    movs r3, #1
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805aede
    ldr r4, lbl_0805af18 @ =0x00000401
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl set_bg1_block_value
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl set_clipdata_block_value
    movs r0, #0
    mov r8, r0
lbl_0805aede:
    mov r0, r8
    cmp r0, #0
    bne lbl_0805af06
    ldr r1, lbl_0805af1c @ =gSamusData
    ldrh r0, [r1, #0x14]
    add r0, sb
    ldrh r1, [r1, #0x12]
    adds r1, r1, r7
    bl sub_08057df8
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_0805af00
    movs r0, #1
    mov r8, r0
lbl_0805af00:
    mov r0, r8
    cmp r0, #0
    beq lbl_0805af0c
lbl_0805af06:
    movs r0, #0xfe
    bl SamusSetPose
lbl_0805af0c:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805af18: .4byte 0x00000401
lbl_0805af1c: .4byte gSamusData

    thumb_func_start check_opening_hatch
check_opening_hatch: @ 0x0805af20
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    movs r0, #0
    mov sl, r0
    ldr r3, lbl_0805afb8 @ =gHatchData
    adds r4, r3, #0
lbl_0805af40:
    ldrb r0, [r3]
    lsls r0, r0, #0x1f
    cmp r0, #0
    bne lbl_0805af4a
    b lbl_0805b07e
lbl_0805af4a:
    ldrb r0, [r3, #1]
    lsls r0, r0, #0x1e
    cmp r0, #0
    beq lbl_0805af54
    b lbl_0805b07e
lbl_0805af54:
    movs r1, #0
    mov r8, r1
    ldrb r0, [r3, #5]
    ldr r2, [sp]
    cmp r0, r2
    bne lbl_0805b008
    ldrb r0, [r3, #6]
    cmp r0, sb
    bhi lbl_0805b008
    adds r0, #3
    cmp sb, r0
    bgt lbl_0805b008
    ldr r0, lbl_0805afbc @ =0x08345ca8
    mov ip, r0
    ldrb r1, [r3, #3]
    lsls r1, r1, #2
    add r1, ip
    ldr r7, lbl_0805afc0 @ =0x083459d0
    ldr r6, lbl_0805afc4 @ =gCurrentClipdataAffectingAction
    ldrb r0, [r6]
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r1, [r1]
    ldrh r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b008
    ldrb r1, [r3, #2]
    lsrs r0, r1, #4
    adds r0, #1
    lsls r0, r0, #4
    movs r5, #0xf
    adds r2, r5, #0
    ands r2, r1
    orrs r2, r0
    strb r2, [r3, #2]
    movs r1, #1
    mov r8, r1
    ldrb r0, [r3, #3]
    cmp r0, #6
    bne lbl_0805afcc
    ldr r0, lbl_0805afc8 @ =gHatchesState
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b008
    movs r2, #2
    mov r8, r2
    b lbl_0805b00e
    .align 2, 0
lbl_0805afb8: .4byte gHatchData
lbl_0805afbc: .4byte 0x08345ca8
lbl_0805afc0: .4byte 0x083459d0
lbl_0805afc4: .4byte gCurrentClipdataAffectingAction
lbl_0805afc8: .4byte gHatchesState
lbl_0805afcc:
    cmp r0, #7
    bne lbl_0805afe8
    ldr r0, lbl_0805afe4 @ =gHatchesState
    ldrb r0, [r0, #1]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b008
    movs r0, #2
    mov r8, r0
    b lbl_0805b00e
    .align 2, 0
lbl_0805afe4: .4byte gHatchesState
lbl_0805afe8:
    cmp r0, #3
    bne lbl_0805b008
    ldrb r0, [r6]
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b008
    mov r1, ip
    ldrb r0, [r1, #0xe]
    lsls r0, r0, #4
    ands r2, r5
    orrs r2, r0
    strb r2, [r3, #2]
lbl_0805b008:
    mov r2, r8
    cmp r2, #0
    beq lbl_0805b07e
lbl_0805b00e:
    mov r0, r8
    cmp r0, #1
    bne lbl_0805b068
    ldrb r2, [r4, #2]
    ldr r1, lbl_0805b04c @ =0x08345ca8
    ldrb r0, [r4, #3]
    lsls r0, r0, #2
    adds r1, #2
    adds r0, r0, r1
    lsrs r2, r2, #4
    ldrh r0, [r0]
    cmp r2, r0
    blo lbl_0805b05a
    ldrb r1, [r4, #1]
    movs r0, #0xf
    ands r0, r1
    movs r2, #4
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r4, #1]
    ldrb r0, [r4, #3]
    cmp r0, #2
    bls lbl_0805b050
    ldrb r1, [r4, #7]
    movs r0, #1
    bl set_hatch_as_opened
    b lbl_0805b070
    .align 2, 0
lbl_0805b04c: .4byte 0x08345ca8
lbl_0805b050:
    ldrb r1, [r4, #7]
    movs r0, #2
    bl set_hatch_as_opened
    b lbl_0805b070
lbl_0805b05a:
    ldrb r0, [r4, #1]
    movs r1, #0xf
    ands r1, r0
    movs r0, #0x10
    orrs r1, r0
    strb r1, [r4, #1]
    b lbl_0805b070
lbl_0805b068:
    ldrb r1, [r4, #2]
    movs r0, #0xf
    ands r0, r1
    strb r0, [r4, #2]
lbl_0805b070:
    ldrb r0, [r4, #2]
    movs r2, #0x10
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    strb r0, [r4, #2]
    b lbl_0805b08e
lbl_0805b07e:
    adds r4, #8
    adds r3, #8
    movs r0, #1
    add sl, r0
    mov r1, sl
    cmp r1, #0xf
    bgt lbl_0805b08e
    b lbl_0805af40
lbl_0805b08e:
    mov r0, r8
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start set_item_as_collected
set_item_as_collected: @ 0x0805b0a0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    ldr r0, lbl_0805b104 @ =gCurrentArea
    ldrb r1, [r0]
    mov ip, r0
    cmp r1, #7
    bhi lbl_0805b0fe
    adds r3, r1, #0
    movs r4, #0x40
    movs r2, #1
    lsls r0, r3, #8
    ldr r3, lbl_0805b108 @ =0x02036c00
    adds r1, r0, r3
    movs r3, #0
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_0805b0e0
lbl_0805b0cc:
    adds r3, #1
    adds r1, #4
    cmp r3, r4
    bge lbl_0805b0dc
    ldrb r0, [r1]
    cmp r0, #0xff
    bne lbl_0805b0cc
    movs r2, #0
lbl_0805b0dc:
    cmp r2, #0
    bne lbl_0805b0fe
lbl_0805b0e0:
    ldr r0, lbl_0805b10c @ =gCurrentRoom
    ldrb r0, [r0]
    strb r0, [r1]
    adds r1, #1
    strb r5, [r1]
    adds r1, #1
    strb r6, [r1]
    strb r7, [r1, #1]
    ldr r0, lbl_0805b110 @ =gNumberOfItemsCollected
    mov r2, ip
    ldrb r1, [r2]
    adds r1, r1, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0805b0fe:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b104: .4byte gCurrentArea
lbl_0805b108: .4byte 0x02036c00
lbl_0805b10c: .4byte gCurrentRoom
lbl_0805b110: .4byte gNumberOfItemsCollected

    thumb_func_start remove_collected_tanks
remove_collected_tanks: @ 0x0805b114
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_0805b198 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b1c8
    ldr r1, lbl_0805b19c @ =gCurrentArea
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0805b1c8
    adds r6, r0, #0
    movs r0, #0x40
    mov sl, r0
    lsls r0, r6, #8
    ldr r1, lbl_0805b1a0 @ =0x02036c00
    adds r4, r0, r1
    movs r6, #0
    ldr r2, lbl_0805b1a4 @ =gTilemapAndClipPointers
    mov sb, r2
    ldr r7, lbl_0805b1a8 @ =gCurrentRoom
    mov r8, r7
    ldr r0, lbl_0805b1ac @ =gBGPointersAndDimensions
    mov ip, r0
lbl_0805b14c:
    ldrb r0, [r4]
    cmp r0, #0xff
    beq lbl_0805b1c8
    mov r1, r8
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0805b1c0
    movs r0, #1
    ldrsb r0, [r4, r0]
    cmp r0, #0
    blt lbl_0805b1c0
    mov r5, ip
    ldrh r1, [r5, #0x1c]
    ldrb r0, [r4, #3]
    muls r0, r1, r0
    ldrb r2, [r4, #2]
    adds r0, r0, r2
    ldr r1, [r5, #0x18]
    lsls r3, r0, #1
    adds r2, r3, r1
    ldrh r0, [r2]
    mov r7, sb
    ldr r1, [r7, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    subs r0, #0x3c
    cmp r0, #3
    bhi lbl_0805b1b4
    ldr r1, lbl_0805b1b0 @ =0x0000043c
    adds r0, r1, #0
    strh r0, [r2]
    ldr r0, [r5, #8]
    adds r0, r3, r0
    movs r2, #0
    strh r2, [r0]
    b lbl_0805b1c0
    .align 2, 0
lbl_0805b198: .4byte gPauseScreenFlag
lbl_0805b19c: .4byte gCurrentArea
lbl_0805b1a0: .4byte 0x02036c00
lbl_0805b1a4: .4byte gTilemapAndClipPointers
lbl_0805b1a8: .4byte gCurrentRoom
lbl_0805b1ac: .4byte gBGPointersAndDimensions
lbl_0805b1b0: .4byte 0x0000043c
lbl_0805b1b4:
    movs r7, #0
    strh r7, [r2]
    mov r1, ip
    ldr r0, [r1, #8]
    adds r0, r3, r0
    strh r7, [r0]
lbl_0805b1c0:
    adds r6, #1
    adds r4, #4
    cmp r6, sl
    blt lbl_0805b14c
lbl_0805b1c8:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start BGClipCallMotherBrainUpdateGlass
BGClipCallMotherBrainUpdateGlass: @ 0x0805b1d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r0, lbl_0805b240 @ =gCurrentArea
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0805b234
    ldr r0, lbl_0805b244 @ =gCurrentRoom
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0805b234
    movs r2, #0
    lsls r0, r1, #1
    ldr r1, lbl_0805b248 @ =0x08345cf6
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r8, r0
lbl_0805b1fe:
    movs r4, #0
    lsls r0, r2, #4
    adds r1, r2, #0
    adds r1, #0xd
    adds r7, r2, #1
    mov r2, r8
    adds r6, r2, r0
    lsls r5, r1, #0x10
lbl_0805b20e:
    adds r1, r4, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r3, r4, #4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    movs r0, #0
    lsrs r2, r5, #0x10
    bl mother_brain_update_glass
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #6
    bls lbl_0805b20e
    lsls r0, r7, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #4
    bls lbl_0805b1fe
lbl_0805b234:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b240: .4byte gCurrentArea
lbl_0805b244: .4byte gCurrentRoom
lbl_0805b248: .4byte 0x08345cf6

    thumb_func_start unk_5b24c
unk_5b24c: @ 0x0805b24c
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b27c @ =0x02035400
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b280 @ =0x05000200
    ldr r2, lbl_0805b284 @ =0x02035600
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b27c: .4byte 0x02035400
lbl_0805b280: .4byte 0x05000200
lbl_0805b284: .4byte 0x02035600

    thumb_func_start sub_0805b288
sub_0805b288: @ 0x0805b288
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b2b8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2bc @ =0x05000200
    ldr r2, lbl_0805b2c0 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2b8: .4byte 0x02035000
lbl_0805b2bc: .4byte 0x05000200
lbl_0805b2c0: .4byte 0x02035200

    thumb_func_start unk_5b2c4
unk_5b2c4: @ 0x0805b2c4
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b2f4 @ =0x02035400
    ldr r2, lbl_0805b2f8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2fc @ =0x02035600
    ldr r2, lbl_0805b300 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2f4: .4byte 0x02035400
lbl_0805b2f8: .4byte 0x02035000
lbl_0805b2fc: .4byte 0x02035600
lbl_0805b300: .4byte 0x02035200

    thumb_func_start unk_5b304
unk_5b304: @ 0x0805b304
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b334 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b338 @ =0x05000200
    ldr r2, lbl_0805b33c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b334: .4byte 0x02035800
lbl_0805b338: .4byte 0x05000200
lbl_0805b33c: .4byte 0x02035a00

    thumb_func_start unk_5b340
unk_5b340: @ 0x0805b340
    push {lr}
    bl unk_5b24c
    bl sub_0805b288
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0805b350
sub_0805b350: @ 0x0805b350
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b380 @ =0x02035400
    ldr r2, lbl_0805b384 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b388 @ =0x02035600
    ldr r2, lbl_0805b38c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b380: .4byte 0x02035400
lbl_0805b384: .4byte 0x02035800
lbl_0805b388: .4byte 0x02035600
lbl_0805b38c: .4byte 0x02035a00

    thumb_func_start sub_0805b390
sub_0805b390: @ 0x0805b390
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0805b3ec @ =gColorFading
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b3e4
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3c0
    ldr r1, lbl_0805b3f0 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3c0:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3e4
    ldr r1, lbl_0805b3f4 @ =0x02035200
    ldr r2, lbl_0805b3f8 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3e4:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b3ec: .4byte gColorFading
lbl_0805b3f0: .4byte 0x02035000
lbl_0805b3f4: .4byte 0x02035200
lbl_0805b3f8: .4byte 0x05000200

    thumb_func_start CheckTransferFadedPalette
CheckTransferFadedPalette: @ 0x0805b3fc
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805b45c @ =gGameModeSub1
    movs r1, #0
    ldrsh r4, [r0, r1]
    cmp r4, #2
    bne lbl_0805b470
    ldr r5, lbl_0805b460 @ =gColorFading
    ldrb r1, [r5, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b436
    ldr r1, lbl_0805b464 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #1
    eors r0, r1
    strb r0, [r5, #4]
lbl_0805b436:
    ldrb r0, [r5, #4]
    ands r4, r0
    cmp r4, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b468 @ =0x02035240
    ldr r2, lbl_0805b46c @ =0x05000240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #2
    eors r0, r1
    strb r0, [r5, #4]
    b lbl_0805b4c0
    .align 2, 0
lbl_0805b45c: .4byte gGameModeSub1
lbl_0805b460: .4byte gColorFading
lbl_0805b464: .4byte 0x02035000
lbl_0805b468: .4byte 0x02035240
lbl_0805b46c: .4byte 0x05000240
lbl_0805b470:
    ldr r4, lbl_0805b4c8 @ =gColorFading
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b49c
    ldr r1, lbl_0805b4cc @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b49c:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b4d0 @ =0x02035200
    ldr r2, lbl_0805b4d4 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b4c0:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b4c8: .4byte gColorFading
lbl_0805b4cc: .4byte 0x02035000
lbl_0805b4d0: .4byte 0x02035200
lbl_0805b4d4: .4byte 0x05000200

    thumb_func_start CallApplySpecialBackgroundFadingColor
CallApplySpecialBackgroundFadingColor: @ 0x0805b4d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r2, lbl_0805b508 @ =0x08345d00
    ldr r3, lbl_0805b50c @ =gColorFading
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    mov r8, r2
    adds r6, r3, #0
    cmp r0, #0
    beq lbl_0805b510
    ldrb r0, [r6, #5]
    movs r5, #3
    cmp r0, #0
    bne lbl_0805b51c
    movs r5, #1
    b lbl_0805b51c
    .align 2, 0
lbl_0805b508: .4byte 0x08345d00
lbl_0805b50c: .4byte gColorFading
lbl_0805b510:
    ldrb r1, [r6, #5]
    movs r5, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r5, r0
lbl_0805b51c:
    ldr r0, lbl_0805b574 @ =0x02035000
    str r0, [sp, #8]
    ldr r0, lbl_0805b578 @ =0x02035400
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x12]
    add r4, sp, #8
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, lbl_0805b57c @ =0x02035200
    str r0, [sp, #8]
    ldr r0, lbl_0805b580 @ =0x02035600
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x14]
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl ApplySpecialBackgroundFadingColor
    movs r0, #3
    strb r0, [r6, #4]
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b574: .4byte 0x02035000
lbl_0805b578: .4byte 0x02035400
lbl_0805b57c: .4byte 0x02035200
lbl_0805b580: .4byte 0x02035600

    thumb_func_start power_bomb_yellow_tint
power_bomb_yellow_tint: @ 0x0805b584
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, lbl_0805b618 @ =gAnimatedGraphicsEntry
    ldrb r0, [r0]
    movs r7, #0xf0
    cmp r0, #0
    bne lbl_0805b598
    adds r7, #0x10
lbl_0805b598:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r4, lbl_0805b61c @ =0x02035000
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    lsls r0, r6, #5
    adds r5, r0, r4
    lsls r4, r6, #4
    cmp r4, r7
    bge lbl_0805b604
    movs r0, #0xf8
    lsls r0, r0, #2
    mov ip, r0
    movs r6, #0xf8
    lsls r6, r6, #7
lbl_0805b5c2:
    movs r0, #0xf
    ands r0, r4
    cmp r0, #0
    beq lbl_0805b5fc
    ldrh r2, [r5]
    movs r3, #0x1f
    ands r3, r2
    mov r1, ip
    ands r1, r2
    adds r0, r6, #0
    ands r0, r2
    lsrs r0, r0, #0xa
    adds r3, #5
    lsls r1, r1, #0x13
    movs r2, #0xa0
    lsls r2, r2, #0x13
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    cmp r3, #0x1f
    bls lbl_0805b5ec
    movs r3, #0x1f
lbl_0805b5ec:
    cmp r1, #0x1f
    bls lbl_0805b5f2
    movs r1, #0x1f
lbl_0805b5f2:
    lsls r0, r0, #0xa
    lsls r1, r1, #5
    orrs r0, r1
    orrs r0, r3
    strh r0, [r5]
lbl_0805b5fc:
    adds r4, #1
    adds r5, #2
    cmp r4, r7
    blt lbl_0805b5c2
lbl_0805b604:
    ldr r2, lbl_0805b620 @ =gColorFading
    ldrb r1, [r2, #4]
    movs r0, #1
    orrs r0, r1
    strb r0, [r2, #4]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b618: .4byte gAnimatedGraphicsEntry
lbl_0805b61c: .4byte 0x02035000
lbl_0805b620: .4byte gColorFading

    thumb_func_start ApplyMonochromeToPalette
ApplyMonochromeToPalette: @ 0x0805b624
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    mov r8, r2
    movs r6, #0xff
lbl_0805b636:
    ldrh r2, [r5]
    movs r0, #0x1f
    ands r0, r2
    movs r3, #0xf8
    lsls r3, r3, #2
    adds r1, r3, #0
    adds r3, r2, #0
    ands r3, r1
    lsrs r3, r3, #5
    movs r7, #0xf8
    lsls r7, r7, #7
    adds r1, r7, #0
    ands r2, r1
    lsrs r2, r2, #0xa
    adds r0, r0, r3
    adds r0, r0, r2
    movs r1, #3
    bl __divsi3
    mov r1, r8
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_0805b668
    movs r2, #0
    b lbl_0805b66e
lbl_0805b668:
    cmp r2, #0x1f
    ble lbl_0805b66e
    movs r2, #0x1f
lbl_0805b66e:
    lsls r0, r2, #0xa
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r2
    strh r0, [r4]
    subs r6, #1
    adds r5, #2
    adds r4, #2
    cmp r6, #0
    bge lbl_0805b636
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ApplySmoothMonochromeToPalette
ApplySmoothMonochromeToPalette: @ 0x0805b68c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sl, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b6b8
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sl
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6b8:
    cmp r7, #0x1e
    bls lbl_0805b6d0
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6d0:
    movs r0, #0x1f
    mov sb, r0
    movs r1, #0xff
    str r1, [sp, #4]
lbl_0805b6d8:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sb
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sl
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sb
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b70a
    adds r0, #0x1f
lbl_0805b70a:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b71c
    adds r0, #0x1f
lbl_0805b71c:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b72e
    adds r0, #0x1f
lbl_0805b72e:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sl, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b6d8
lbl_0805b752:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start ApplySmoothPaletteTransition
ApplySmoothPaletteTransition: @ 0x0805b764
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b788
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sb
    b lbl_0805b796
lbl_0805b788:
    cmp r7, #0x1e
    bls lbl_0805b79e
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
lbl_0805b796:
    movs r3, #0x20
    bl DMATransfer
    b lbl_0805b820
lbl_0805b79e:
    movs r0, #0x1f
    mov sl, r0
    movs r1, #0x1f
    str r1, [sp, #4]
lbl_0805b7a6:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sl
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sb
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sl
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7d8
    adds r0, #0x1f
lbl_0805b7d8:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7ea
    adds r0, #0x1f
lbl_0805b7ea:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7fc
    adds r0, #0x1f
lbl_0805b7fc:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sb, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b7a6
lbl_0805b820:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start ApplySpecialBackgroundEffectColorOnBG
ApplySpecialBackgroundEffectColorOnBG: @ 0x0805b830
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    cmp r7, #0
    bne lbl_0805b880
    ldr r5, lbl_0805b878 @ =0x02035800
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r6, #0xf0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b87c @ =0x02035400
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805b94e
    .align 2, 0
lbl_0805b878: .4byte 0x02035800
lbl_0805b87c: .4byte 0x02035400
lbl_0805b880:
    ldr r1, lbl_0805b960 @ =0x02035800
    ldr r4, lbl_0805b964 @ =0x02035000
    movs r3, #0xf0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r5
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r5
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r5
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b8b0:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r4, r2, #1
    str r4, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805b93c
    lsls r3, r2, #4
    adds r1, r3, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805b93c
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r4, #0xf8
    lsls r4, r4, #7
    mov sb, r4
    lsls r0, r2, #5
    ldr r2, lbl_0805b964 @ =0x02035000
    adds r6, r0, r2
    subs r3, r1, r3
lbl_0805b8de:
    ldrh r1, [r6]
    movs r5, #0x1f
    ands r5, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r4, [sp, #8]
    subs r0, r4, r5
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b8fc
    adds r0, #0xf
lbl_0805b8fc:
    asrs r0, r0, #4
    adds r0, r5, r0
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    mov r4, r8
    subs r0, r4, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b910
    adds r0, #0xf
lbl_0805b910:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r4, ip
    subs r0, r4, r1
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b924
    adds r0, #0xf
lbl_0805b924:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r5
    strh r0, [r6]
    adds r6, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805b8de
lbl_0805b93c:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b8b0
    ldr r0, lbl_0805b968 @ =gColorFading
    ldrb r1, [r0, #4]
    movs r0, #1
    orrs r0, r1
    ldr r1, lbl_0805b968 @ =gColorFading
    strb r0, [r1, #4]
lbl_0805b94e:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b960: .4byte 0x02035800
lbl_0805b964: .4byte 0x02035000
lbl_0805b968: .4byte gColorFading

    thumb_func_start ApplySpecialBackgroundEffectColorOnOBJ
ApplySpecialBackgroundEffectColorOnOBJ: @ 0x0805b96c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r6, r2, #0x18
    cmp r6, #0
    bne lbl_0805b9bc
    ldr r5, lbl_0805b9b0 @ =0x02035a40
    ldr r2, lbl_0805b9b4 @ =0x05000240
    movs r6, #0xe0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b9b8 @ =0x02035640
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805ba8a
    .align 2, 0
lbl_0805b9b0: .4byte 0x02035a40
lbl_0805b9b4: .4byte 0x05000240
lbl_0805b9b8: .4byte 0x02035640
lbl_0805b9bc:
    ldr r1, lbl_0805ba9c @ =0x02035a40
    ldr r2, lbl_0805baa0 @ =0x02035240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r4
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r4
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r4
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b9ea:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r7, r2, #1
    str r7, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805ba78
    lsls r0, r2, #4
    adds r3, r0, #1
    adds r1, r0, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805ba78
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r2, #0xf8
    lsls r2, r2, #7
    mov sb, r2
    lsls r0, r3, #1
    ldr r7, lbl_0805baa4 @ =0x02035200
    adds r5, r0, r7
    subs r3, r1, r3
lbl_0805ba1a:
    ldrh r1, [r5]
    movs r4, #0x1f
    ands r4, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r7, [sp, #8]
    subs r0, r7, r4
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba38
    adds r0, #0xf
lbl_0805ba38:
    asrs r0, r0, #4
    adds r0, r4, r0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    mov r7, r8
    subs r0, r7, r2
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba4c
    adds r0, #0xf
lbl_0805ba4c:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r7, ip
    subs r0, r7, r1
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba60
    adds r0, #0xf
lbl_0805ba60:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r4
    strh r0, [r5]
    adds r5, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805ba1a
lbl_0805ba78:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b9ea
    ldr r0, lbl_0805baa8 @ =gColorFading
    ldrb r1, [r0, #4]
    movs r0, #2
    orrs r0, r1
    ldr r1, lbl_0805baa8 @ =gColorFading
    strb r0, [r1, #4]
lbl_0805ba8a:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ba9c: .4byte 0x02035a40
lbl_0805baa0: .4byte 0x02035240
lbl_0805baa4: .4byte 0x02035200
lbl_0805baa8: .4byte gColorFading

    thumb_func_start ApplySpecialBackgroundFadingColor
ApplySpecialBackgroundFadingColor: @ 0x0805baac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r2
    mov r8, r3
    ldr r2, [sp, #0x28]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp]
    movs r2, #0
lbl_0805bad0:
    ldr r0, [sp]
    asrs r0, r2
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0805baf2
    mov r1, sb
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    adds r2, #1
    str r2, [sp, #4]
    b lbl_0805bbcc
lbl_0805baf2:
    adds r2, #1
    str r2, [sp, #4]
    movs r6, #0x1f
    movs r0, #0xf
    mov sl, r0
lbl_0805bafc:
    mov r1, sb
    ldr r2, [r1]
    ldrh r1, [r2]
    adds r3, r6, #0
    ands r3, r1
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r5, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r4, r0, #0xa
    mov r0, ip
    cmp r0, #1
    beq lbl_0805bb4a
    cmp r0, #1
    bgt lbl_0805bb26
    cmp r0, #0
    beq lbl_0805bb32
    b lbl_0805bba4
lbl_0805bb26:
    mov r1, ip
    cmp r1, #2
    beq lbl_0805bb68
    cmp r1, #3
    beq lbl_0805bb86
    b lbl_0805bba4
lbl_0805bb32:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r3, r0, #5
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r5, r0, #5
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r4, r0, #5
    b lbl_0805bba2
lbl_0805bb4a:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r6, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r6, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r6, r0
    b lbl_0805bba2
lbl_0805bb68:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r5, r0
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    b lbl_0805bba2
lbl_0805bb86:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r5, r5, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r4, r4, r0
lbl_0805bba2:
    ands r4, r6
lbl_0805bba4:
    mov r0, r8
    ldr r1, [r0]
    lsls r0, r5, #5
    orrs r3, r0
    lsls r0, r4, #0xa
    orrs r3, r0
    strh r3, [r1]
    movs r1, #1
    rsbs r1, r1, #0
    add sl, r1
    adds r0, r2, #2
    mov r1, sb
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #2
    str r0, [r1]
    mov r0, sl
    cmp r0, #0
    bge lbl_0805bafc
lbl_0805bbcc:
    ldr r2, [sp, #4]
    cmp r2, #0xf
    bgt lbl_0805bbd4
    b lbl_0805bad0
lbl_0805bbd4:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0805bbe4
sub_0805bbe4: @ 0x0805bbe4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    mov ip, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    movs r7, #0x1f
    adds r3, r1, #0
    ands r3, r7
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r4, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r2, r0, #0xa
    cmp r6, #1
    beq lbl_0805bc3e
    cmp r6, #1
    bgt lbl_0805bc18
    cmp r6, #0
    beq lbl_0805bc24
    b lbl_0805bc9e
lbl_0805bc18:
    mov r0, ip
    cmp r0, #2
    beq lbl_0805bc5e
    cmp r0, #3
    beq lbl_0805bc7e
    b lbl_0805bc9e
lbl_0805bc24:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r3, r0, #5
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r4, r0, #5
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r2, r0, #5
    b lbl_0805bc9c
lbl_0805bc3e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    movs r1, #0x1f
    subs r3, r1, r0
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r1, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r1, r0
    b lbl_0805bc9c
lbl_0805bc5e:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r2, r0
    b lbl_0805bc9c
lbl_0805bc7e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r4, r4, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r2, r2, r0
lbl_0805bc9c:
    ands r2, r1
lbl_0805bc9e:
    lsls r0, r4, #5
    orrs r3, r0
    lsls r0, r2, #0xa
    orrs r3, r0
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
