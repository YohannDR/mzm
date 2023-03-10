    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start ScreenShakeStartVertical
ScreenShakeStartVertical: @ 0x08055344
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_08055370 @ =gScreenShakeY
    cmp r2, #0
    beq lbl_08055368
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_08055368
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r4, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_08055374 @ =gScreenShakeYOffset
    strb r1, [r0]
lbl_08055368:
    ldrb r0, [r3]
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08055370: .4byte gScreenShakeY
lbl_08055374: .4byte gScreenShakeYOffset

    thumb_func_start ScreenShakeStartHorizontal
ScreenShakeStartHorizontal: @ 0x08055378
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_080553a4 @ =gScreenShakeX
    cmp r2, #0
    beq lbl_0805539c
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_0805539c
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r4, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_080553a8 @ =gScreenShakeXOffset
    strb r1, [r0]
lbl_0805539c:
    ldrb r0, [r3]
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080553a4: .4byte gScreenShakeX
lbl_080553a8: .4byte gScreenShakeXOffset

    thumb_func_start ScreenShakeStartHorizontal_unused
ScreenShakeStartHorizontal_unused: @ 0x080553ac
    push {lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r3, lbl_080553d4 @ =gScreenShakeX
    cmp r2, #0
    beq lbl_080553cc
    ldrb r0, [r3]
    cmp r2, r0
    bls lbl_080553cc
    movs r1, #0
    strb r2, [r3]
    strb r1, [r3, #1]
    strb r1, [r3, #2]
    strb r1, [r3, #3]
    ldr r0, lbl_080553d8 @ =gScreenShakeXOffset
    strb r1, [r0]
lbl_080553cc:
    ldrb r0, [r3]
    pop {r1}
    bx r1
    .align 2, 0
lbl_080553d4: .4byte gScreenShakeX
lbl_080553d8: .4byte gScreenShakeXOffset

    thumb_func_start update_vertical_screen_shake
update_vertical_screen_shake: @ 0x080553dc
    push {r4, r5, r6, lr}
    movs r2, #0
    ldr r6, lbl_080553f4 @ =gScreenShakeYOffset
    strb r2, [r6]
    ldr r4, lbl_080553f8 @ =gScreenShakeY
    ldrb r0, [r4]
    adds r3, r4, #0
    cmp r0, #0
    bne lbl_080553fc
    movs r0, #0
    b lbl_0805543e
    .align 2, 0
lbl_080553f4: .4byte gScreenShakeYOffset
lbl_080553f8: .4byte gScreenShakeY
lbl_080553fc:
    subs r5, r0, #1
    strb r5, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #1
    bhi lbl_0805540e
    adds r0, #1
    strb r0, [r3, #1]
    movs r0, #0
    b lbl_0805543e
lbl_0805540e:
    strb r2, [r3, #1]
    ldrb r0, [r3, #2]
    movs r1, #0x7f
    ands r1, r0
    movs r2, #2
    rsbs r2, r2, #0
    ldrb r3, [r3, #3]
    cmp r3, #0
    beq lbl_0805542a
    movs r2, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r2, r0
lbl_0805542a:
    movs r0, #1
    eors r0, r3
    strb r0, [r4, #3]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bhi lbl_0805543a
    asrs r2, r2, #1
lbl_0805543a:
    strb r2, [r6]
    adds r0, r2, #0
lbl_0805543e:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start update_horizontal_screen_shake
update_horizontal_screen_shake: @ 0x08055444
    push {r4, r5, r6, lr}
    movs r2, #0
    ldr r6, lbl_0805545c @ =gScreenShakeXOffset
    strb r2, [r6]
    ldr r4, lbl_08055460 @ =gScreenShakeX
    ldrb r0, [r4]
    adds r3, r4, #0
    cmp r0, #0
    bne lbl_08055464
    movs r0, #0
    b lbl_080554a6
    .align 2, 0
lbl_0805545c: .4byte gScreenShakeXOffset
lbl_08055460: .4byte gScreenShakeX
lbl_08055464:
    subs r5, r0, #1
    strb r5, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #1
    bhi lbl_08055476
    adds r0, #1
    strb r0, [r3, #1]
    movs r0, #0
    b lbl_080554a6
lbl_08055476:
    strb r2, [r3, #1]
    ldrb r0, [r3, #2]
    movs r1, #0x7f
    ands r1, r0
    movs r2, #2
    rsbs r2, r2, #0
    ldrb r3, [r3, #3]
    cmp r3, #0
    beq lbl_08055492
    movs r2, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r2, r0
lbl_08055492:
    movs r0, #1
    eors r0, r3
    strb r0, [r4, #3]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bhi lbl_080554a2
    asrs r2, r2, #1
lbl_080554a2:
    strb r2, [r6]
    adds r0, r2, #0
lbl_080554a6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start TransparencySetRoomEffectsTransparency
TransparencySetRoomEffectsTransparency: @ 0x080554ac
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r0, lbl_08055524 @ =gPauseScreenFlag
    movs r1, #0
    ldrsb r1, [r0, r1]
    cmp r1, #0
    beq lbl_08055540
    ldr r0, lbl_08055528 @ =gInGameCutscene
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080554e0
    bl TransparencyCheckIsDarkRoom
    adds r3, r0, #0
    cmp r3, #0
    beq lbl_080554e0
    ldr r2, lbl_0805552c @ =gIoRegistersBackup
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r4, #0
    orrs r0, r1
    ands r0, r3
    strh r0, [r2]
lbl_080554e0:
    ldr r1, lbl_08055530 @ =0x0400000a
    ldr r3, lbl_0805552c @ =gIoRegistersBackup
    ldrh r0, [r3, #0xc]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r3, #0xe]
    strh r0, [r1]
    adds r1, #0x3e
    ldrb r0, [r3, #8]
    strb r0, [r1]
    subs r1, #1
    ldrb r0, [r3, #7]
    strb r0, [r1]
    ldr r4, lbl_08055534 @ =0x04000042
    ldr r2, lbl_08055538 @ =gSuitFlashEffect
    ldrb r1, [r2]
    lsls r1, r1, #8
    ldrb r0, [r2, #1]
    orrs r0, r1
    strh r0, [r4]
    adds r4, #4
    ldrb r1, [r2, #2]
    lsls r1, r1, #8
    ldrb r0, [r2, #3]
    orrs r0, r1
    strh r0, [r4]
    ldr r2, lbl_0805553c @ =0x04000052
    ldrb r1, [r3, #5]
    lsls r1, r1, #8
    ldrb r0, [r3, #4]
    orrs r0, r1
    strh r0, [r2]
    b lbl_080559de
    .align 2, 0
lbl_08055524: .4byte gPauseScreenFlag
lbl_08055528: .4byte gInGameCutscene
lbl_0805552c: .4byte gIoRegistersBackup
lbl_08055530: .4byte 0x0400000a
lbl_08055534: .4byte 0x04000042
lbl_08055538: .4byte gSuitFlashEffect
lbl_0805553c: .4byte 0x04000052
lbl_08055540:
    mov r0, sp
    movs r4, #0
    strh r1, [r0]
    strh r1, [r0, #2]
    strh r1, [r0, #4]
    strh r1, [r0, #6]
    ldr r0, lbl_0805559c @ =gSamusOnTopOfBackgrounds
    strb r4, [r0]
    ldr r2, lbl_080555a0 @ =gBldalphaData1
    ldr r0, lbl_080555a4 @ =0x083458cc
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080555a8 @ =gBldalphaData2
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080555ac @ =gDefaultTransparency
    ldr r0, lbl_080555b0 @ =0x083458dc
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080555b4 @ =gBLDYData1
    ldr r0, lbl_080555b8 @ =0x083458d4
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080555bc @ =gBLDYData2
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080555c0 @ =gCurrentRoomEntry
    ldrb r1, [r2, #1]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080555c4
    ldrb r0, [r2, #0x18]
    bl TransparencyGetBGSizeFlag
    mov r2, sp
    movs r1, #8
    orrs r0, r1
    strh r0, [r2]
    b lbl_080555ca
    .align 2, 0
lbl_0805559c: .4byte gSamusOnTopOfBackgrounds
lbl_080555a0: .4byte gBldalphaData1
lbl_080555a4: .4byte 0x083458cc
lbl_080555a8: .4byte gBldalphaData2
lbl_080555ac: .4byte gDefaultTransparency
lbl_080555b0: .4byte 0x083458dc
lbl_080555b4: .4byte gBLDYData1
lbl_080555b8: .4byte 0x083458d4
lbl_080555bc: .4byte gBLDYData2
lbl_080555c0: .4byte gCurrentRoomEntry
lbl_080555c4:
    mov r1, sp
    ldr r0, lbl_0805560c @ =0x00004004
    strh r0, [r1]
lbl_080555ca:
    mov r1, sp
    ldr r0, lbl_08055610 @ =0x00004204
    strh r0, [r1, #2]
    ldr r0, lbl_08055614 @ =0x00004404
    strh r0, [r1, #4]
    mov r0, sp
    ldr r3, lbl_08055618 @ =0x00000603
    strh r3, [r0, #6]
    ldr r0, lbl_0805561c @ =gCurrentRoomEntry
    ldrb r0, [r0, #4]
    mov r2, sp
    movs r1, #8
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2, #6]
    ldr r4, lbl_0805561c @ =gCurrentRoomEntry
    ldrb r0, [r4, #0x19]
    bl TransparencyGetBGSizeFlag
    mov r2, sp
    mov r1, sp
    ldrh r1, [r1, #6]
    orrs r0, r1
    strh r0, [r2, #6]
    ldrb r0, [r4, #7]
    cmp r0, #0x33
    bhi lbl_080556f4
    lsls r0, r0, #2
    ldr r1, lbl_08055620 @ =lbl_08055624
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805560c: .4byte 0x00004004
lbl_08055610: .4byte 0x00004204
lbl_08055614: .4byte 0x00004404
lbl_08055618: .4byte 0x00000603
lbl_0805561c: .4byte gCurrentRoomEntry
lbl_08055620: .4byte lbl_08055624
lbl_08055624: @ jump table
    .4byte lbl_080556f4 @ case 0
    .4byte lbl_080556f4 @ case 1
    .4byte lbl_080556f4 @ case 2
    .4byte lbl_080556f4 @ case 3
    .4byte lbl_080556f4 @ case 4
    .4byte lbl_0805570a @ case 5
    .4byte lbl_0805572a @ case 6
    .4byte lbl_08055754 @ case 7
    .4byte lbl_080556f4 @ case 8
    .4byte lbl_0805570a @ case 9
    .4byte lbl_0805572a @ case 10
    .4byte lbl_08055754 @ case 11
    .4byte lbl_080556f4 @ case 12
    .4byte lbl_0805570a @ case 13
    .4byte lbl_0805572a @ case 14
    .4byte lbl_08055754 @ case 15
    .4byte lbl_080556f4 @ case 16
    .4byte lbl_0805570a @ case 17
    .4byte lbl_0805572a @ case 18
    .4byte lbl_08055754 @ case 19
    .4byte lbl_080556f4 @ case 20
    .4byte lbl_0805570a @ case 21
    .4byte lbl_0805572a @ case 22
    .4byte lbl_08055754 @ case 23
    .4byte lbl_080556f4 @ case 24
    .4byte lbl_0805570a @ case 25
    .4byte lbl_0805572a @ case 26
    .4byte lbl_08055754 @ case 27
    .4byte lbl_080556f4 @ case 28
    .4byte lbl_0805570a @ case 29
    .4byte lbl_0805572a @ case 30
    .4byte lbl_08055754 @ case 31
    .4byte lbl_080556f4 @ case 32
    .4byte lbl_0805570a @ case 33
    .4byte lbl_0805572a @ case 34
    .4byte lbl_08055754 @ case 35
    .4byte lbl_080556f4 @ case 36
    .4byte lbl_0805570a @ case 37
    .4byte lbl_0805572a @ case 38
    .4byte lbl_08055754 @ case 39
    .4byte lbl_080556f4 @ case 40
    .4byte lbl_0805570a @ case 41
    .4byte lbl_0805572a @ case 42
    .4byte lbl_08055754 @ case 43
    .4byte lbl_080556f4 @ case 44
    .4byte lbl_0805570a @ case 45
    .4byte lbl_0805572a @ case 46
    .4byte lbl_08055754 @ case 47
    .4byte lbl_080556f4 @ case 48
    .4byte lbl_0805570a @ case 49
    .4byte lbl_0805572a @ case 50
    .4byte lbl_08055754 @ case 51
lbl_080556f4:
    mov r1, sp
    mov r0, sp
    ldrh r0, [r0]
    strh r0, [r1]
    mov r2, sp
    mov r0, sp
    ldrh r0, [r0, #2]
    movs r1, #1
    orrs r0, r1
    strh r0, [r2, #2]
    b lbl_0805571e
lbl_0805570a:
    mov r2, sp
    mov r0, sp
    ldrh r1, [r0]
    movs r0, #1
    orrs r0, r1
    strh r0, [r2]
    mov r1, sp
    mov r0, sp
    ldrh r0, [r0, #2]
    strh r0, [r1, #2]
lbl_0805571e:
    mov r0, sp
    ldrh r1, [r0, #4]
    movs r0, #2
    orrs r0, r1
    strh r0, [r2, #4]
    b lbl_08055776
lbl_0805572a:
    mov r1, sp
    mov r0, sp
    ldrh r0, [r0]
    movs r3, #1
    orrs r0, r3
    strh r0, [r1]
    mov r0, sp
    ldrh r0, [r0, #2]
    strh r0, [r1, #2]
    mov r2, sp
    mov r0, sp
    ldrh r1, [r0, #4]
    movs r0, #2
    orrs r0, r1
    strh r0, [r2, #4]
    ldr r0, lbl_08055750 @ =gSamusOnTopOfBackgrounds
    strb r3, [r0]
    b lbl_08055776
    .align 2, 0
lbl_08055750: .4byte gSamusOnTopOfBackgrounds
lbl_08055754:
    mov r2, sp
    mov r0, sp
    ldrh r1, [r0]
    movs r0, #2
    orrs r0, r1
    strh r0, [r2]
    mov r1, sp
    mov r0, sp
    ldrh r0, [r0, #2]
    strh r0, [r1, #2]
    mov r0, sp
    ldrh r0, [r0, #4]
    movs r1, #1
    orrs r0, r1
    strh r0, [r2, #4]
    ldr r0, lbl_08055790 @ =gSamusOnTopOfBackgrounds
    strb r1, [r0]
lbl_08055776:
    movs r2, #0
    movs r3, #0
    ldr r1, lbl_08055794 @ =gCurrentRoomEntry
    ldrb r0, [r1, #7]
    subs r0, #8
    mov r8, r1
    cmp r0, #0x2b
    bhi lbl_08055876
    lsls r0, r0, #2
    ldr r1, lbl_08055798 @ =lbl_0805579c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08055790: .4byte gSamusOnTopOfBackgrounds
lbl_08055794: .4byte gCurrentRoomEntry
lbl_08055798: .4byte lbl_0805579c
lbl_0805579c: @ jump table
    .4byte lbl_08055868 @ case 0
    .4byte lbl_08055868 @ case 1
    .4byte lbl_08055868 @ case 2
    .4byte lbl_08055868 @ case 3
    .4byte lbl_0805586c @ case 4
    .4byte lbl_0805586c @ case 5
    .4byte lbl_0805586c @ case 6
    .4byte lbl_0805586c @ case 7
    .4byte lbl_08055870 @ case 8
    .4byte lbl_08055870 @ case 9
    .4byte lbl_08055870 @ case 10
    .4byte lbl_08055870 @ case 11
    .4byte lbl_08055874 @ case 12
    .4byte lbl_08055874 @ case 13
    .4byte lbl_08055874 @ case 14
    .4byte lbl_08055874 @ case 15
    .4byte lbl_0805584c @ case 16
    .4byte lbl_0805584c @ case 17
    .4byte lbl_0805584c @ case 18
    .4byte lbl_0805584c @ case 19
    .4byte lbl_08055850 @ case 20
    .4byte lbl_08055850 @ case 21
    .4byte lbl_08055850 @ case 22
    .4byte lbl_08055850 @ case 23
    .4byte lbl_08055854 @ case 24
    .4byte lbl_08055854 @ case 25
    .4byte lbl_08055854 @ case 26
    .4byte lbl_08055854 @ case 27
    .4byte lbl_08055858 @ case 28
    .4byte lbl_08055858 @ case 29
    .4byte lbl_08055858 @ case 30
    .4byte lbl_08055858 @ case 31
    .4byte lbl_0805585c @ case 32
    .4byte lbl_0805585c @ case 33
    .4byte lbl_0805585c @ case 34
    .4byte lbl_0805585c @ case 35
    .4byte lbl_08055860 @ case 36
    .4byte lbl_08055860 @ case 37
    .4byte lbl_08055860 @ case 38
    .4byte lbl_08055860 @ case 39
    .4byte lbl_08055864 @ case 40
    .4byte lbl_08055864 @ case 41
    .4byte lbl_08055864 @ case 42
    .4byte lbl_08055864 @ case 43
lbl_0805584c:
    movs r3, #0
    b lbl_08055876
lbl_08055850:
    movs r3, #3
    b lbl_08055876
lbl_08055854:
    movs r3, #6
    b lbl_08055876
lbl_08055858:
    movs r3, #9
    b lbl_08055876
lbl_0805585c:
    movs r3, #0xb
    b lbl_08055876
lbl_08055860:
    movs r3, #0xd
    b lbl_08055876
lbl_08055864:
    movs r3, #0x10
    b lbl_08055876
lbl_08055868:
    movs r2, #7
    b lbl_08055894
lbl_0805586c:
    movs r2, #0xa
    b lbl_08055894
lbl_08055870:
    movs r2, #0xd
    b lbl_08055894
lbl_08055874:
    movs r2, #0x10
lbl_08055876:
    cmp r2, #0
    bne lbl_08055894
    ldr r0, lbl_0805588c @ =gIoRegistersBackup
    strb r3, [r0, #5]
    movs r1, #0x10
    subs r1, r1, r3
    strb r1, [r0, #4]
    ldr r0, lbl_08055890 @ =gDefaultTransparency
    strb r2, [r0, #1]
    mov ip, r0
    b lbl_080558a4
    .align 2, 0
lbl_0805588c: .4byte gIoRegistersBackup
lbl_08055890: .4byte gDefaultTransparency
lbl_08055894:
    ldr r1, lbl_0805594c @ =gIoRegistersBackup
    movs r0, #0x10
    strb r0, [r1, #5]
    strb r2, [r1, #4]
    ldr r1, lbl_08055950 @ =gDefaultTransparency
    movs r0, #1
    strb r0, [r1, #1]
    mov ip, r1
lbl_080558a4:
    ldr r2, lbl_0805594c @ =gIoRegistersBackup
    ldrb r3, [r2, #4]
    movs r4, #0
    mov r0, ip
    strb r3, [r0, #3]
    ldrb r1, [r2, #5]
    strb r1, [r0, #2]
    ldr r0, lbl_08055954 @ =gBldalphaData1
    strb r3, [r0, #4]
    strb r1, [r0, #3]
    ldr r3, lbl_08055958 @ =0x04000052
    ldrb r1, [r2, #5]
    lsls r1, r1, #8
    ldrb r0, [r2, #4]
    orrs r0, r1
    strh r0, [r3]
    ldr r0, lbl_0805595c @ =gWrittenToBLDALPHA
    movs r7, #0
    strh r4, [r0]
    ldr r1, lbl_08055960 @ =gWrittenToBLDY
    movs r3, #1
    rsbs r3, r3, #0
    adds r0, r3, #0
    strb r0, [r1]
    ldr r1, lbl_08055964 @ =gTransparencyRelated
    ldr r0, lbl_08055968 @ =0x083458c4
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_0805596c @ =gSuitFlashEffect
    strb r7, [r0]
    movs r6, #0xf0
    strb r6, [r0, #1]
    strb r7, [r0, #2]
    movs r5, #0xa0
    strb r5, [r0, #3]
    strb r7, [r0, #4]
    ldr r0, lbl_08055970 @ =0x04000048
    strb r7, [r0]
    subs r0, #8
    strh r4, [r0]
    adds r0, #4
    strh r4, [r0]
    movs r3, #0x3f
    strb r3, [r2, #7]
    movs r1, #0x20
    strb r1, [r2, #8]
    adds r0, #6
    strb r1, [r0]
    subs r0, #1
    strb r3, [r0]
    subs r0, #7
    strh r6, [r0]
    adds r0, #4
    strh r5, [r0]
    ldr r1, lbl_08055974 @ =0x0400000a
    mov r0, sp
    ldrh r0, [r0, #2]
    strh r0, [r1]
    adds r1, #2
    mov r0, sp
    ldrh r0, [r0, #4]
    strh r0, [r1]
    mov r0, sp
    ldrh r0, [r0]
    strh r0, [r2, #0xa]
    strh r0, [r2, #0x12]
    mov r0, sp
    ldrh r0, [r0, #2]
    strh r0, [r2, #0xc]
    mov r0, sp
    ldrh r0, [r0, #4]
    strh r0, [r2, #0xe]
    mov r0, sp
    ldrh r0, [r0, #6]
    strh r0, [r2, #0x10]
    mov r4, r8
    ldrb r0, [r4, #7]
    cmp r0, #7
    bhi lbl_08055978
    movs r0, #0xfd
    lsls r0, r0, #6
    mov r1, ip
    strh r0, [r1, #4]
    b lbl_0805597e
    .align 2, 0
lbl_0805594c: .4byte gIoRegistersBackup
lbl_08055950: .4byte gDefaultTransparency
lbl_08055954: .4byte gBldalphaData1
lbl_08055958: .4byte 0x04000052
lbl_0805595c: .4byte gWrittenToBLDALPHA
lbl_08055960: .4byte gWrittenToBLDY
lbl_08055964: .4byte gTransparencyRelated
lbl_08055968: .4byte 0x083458c4
lbl_0805596c: .4byte gSuitFlashEffect
lbl_08055970: .4byte 0x04000048
lbl_08055974: .4byte 0x0400000a
lbl_08055978:
    ldr r0, lbl_08055994 @ =0x00003e41
    mov r3, ip
    strh r0, [r3, #4]
lbl_0805597e:
    mov r4, r8
    ldrb r0, [r4, #0x10]
    cmp r0, #0xa
    bne lbl_08055998
    mov r0, ip
    ldrh r1, [r0, #4]
    movs r0, #8
    orrs r0, r1
    mov r1, ip
    strh r0, [r1, #4]
    b lbl_080559a6
    .align 2, 0
lbl_08055994: .4byte 0x00003e41
lbl_08055998:
    cmp r0, #0xb
    bne lbl_080559a6
    mov r3, ip
    ldrh r1, [r3, #4]
    movs r0, #4
    orrs r0, r1
    strh r0, [r3, #4]
lbl_080559a6:
    mov r4, r8
    ldrb r0, [r4, #1]
    cmp r0, #0x12
    bne lbl_080559ba
    mov r0, ip
    ldrh r1, [r0, #4]
    ldr r0, lbl_080559ec @ =0x0000fffe
    ands r0, r1
    mov r1, ip
    strh r0, [r1, #4]
lbl_080559ba:
    mov r3, ip
    ldrh r1, [r3, #4]
    movs r0, #0
    bl TransparencyUpdateBLDCNT
    ldr r1, lbl_080559f0 @ =gWrittenToBLDCNT
    movs r0, #0
    strh r0, [r1]
    movs r4, #0xbe
    lsls r4, r4, #7
    bl TransparencyCheckIsDarkRoom
    adds r3, r0, #0
    cmp r3, #0
    beq lbl_080559da
    ands r4, r3
lbl_080559da:
    ldr r0, lbl_080559f4 @ =gIoRegistersBackup
    strh r4, [r0]
lbl_080559de:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080559ec: .4byte 0x0000fffe
lbl_080559f0: .4byte gWrittenToBLDCNT
lbl_080559f4: .4byte gIoRegistersBackup

    thumb_func_start TransparencyGetBGSizeFlag
TransparencyGetBGSizeFlag: @ 0x080559f8
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r2, r0, #0
    movs r1, #0
    cmp r0, #1
    beq lbl_08055a14
    cmp r0, #1
    bgt lbl_08055a10
    cmp r0, #0
    beq lbl_08055a1e
    b lbl_08055a14
lbl_08055a10:
    cmp r2, #2
    beq lbl_08055a1a
lbl_08055a14:
    movs r1, #0x80
    lsls r1, r1, #7
    b lbl_08055a1e
lbl_08055a1a:
    movs r1, #0x80
    lsls r1, r1, #8
lbl_08055a1e:
    adds r0, r1, #0
    pop {r1}
    bx r1

    thumb_func_start TransparencyCheckIsDarkRoom
TransparencyCheckIsDarkRoom: @ 0x08055a24
    push {lr}
    movs r1, #0
    ldr r0, lbl_08055a38 @ =gCurrentRoomEntry
    ldrb r0, [r0, #1]
    cmp r0, #0x45
    bne lbl_08055a32
    ldr r1, lbl_08055a3c @ =0x0000ffff
lbl_08055a32:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_08055a38: .4byte gCurrentRoomEntry
lbl_08055a3c: .4byte 0x0000ffff

    thumb_func_start TransparencyUpdateBLDCNT
TransparencyUpdateBLDCNT: @ 0x08055a40
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r5, r1, #0
    movs r3, #0xc0
    ands r3, r1
    ldr r0, lbl_08055a68 @ =gIoRegistersBackup
    strh r1, [r0, #2]
    adds r6, r0, #0
    cmp r2, #1
    beq lbl_08055a90
    cmp r2, #1
    bgt lbl_08055a6c
    cmp r2, #0
    beq lbl_08055a76
    b lbl_08055acc
    .align 2, 0
lbl_08055a68: .4byte gIoRegistersBackup
lbl_08055a6c:
    cmp r4, #2
    beq lbl_08055aac
    cmp r4, #3
    beq lbl_08055ab0
    b lbl_08055acc
lbl_08055a76:
    cmp r3, #0x40
    bne lbl_08055a84
    ldr r0, lbl_08055a80 @ =gBldalphaData1
    strh r1, [r0]
    b lbl_08055ab8
    .align 2, 0
lbl_08055a80: .4byte gBldalphaData1
lbl_08055a84:
    ldr r0, lbl_08055a8c @ =gBLDYData1
    strh r1, [r0]
    b lbl_08055ab8
    .align 2, 0
lbl_08055a8c: .4byte gBLDYData1
lbl_08055a90:
    cmp r3, #0x40
    bne lbl_08055aa0
    ldr r0, lbl_08055a9c @ =gBldalphaData2
    strh r1, [r0]
    b lbl_08055ab8
    .align 2, 0
lbl_08055a9c: .4byte gBldalphaData2
lbl_08055aa0:
    ldr r0, lbl_08055aa8 @ =gBLDYData2
    strh r5, [r0]
    b lbl_08055ab8
    .align 2, 0
lbl_08055aa8: .4byte gBLDYData2
lbl_08055aac:
    cmp r3, #0x80
    beq lbl_08055acc
lbl_08055ab0:
    ldr r1, lbl_08055ab4 @ =0x04000050
    b lbl_08055ac8
    .align 2, 0
lbl_08055ab4: .4byte 0x04000050
lbl_08055ab8:
    ldr r0, lbl_08055ad4 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_08055ac6
    cmp r3, #0x80
    beq lbl_08055acc
lbl_08055ac6:
    ldr r1, lbl_08055ad8 @ =gWrittenToBLDCNT
lbl_08055ac8:
    ldrh r0, [r6, #2]
    strh r0, [r1]
lbl_08055acc:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055ad4: .4byte gGameModeSub1
lbl_08055ad8: .4byte gWrittenToBLDCNT

    thumb_func_start TransparencySpriteUpdateBLDY
TransparencySpriteUpdateBLDY: @ 0x08055adc
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r3, #0
    cmp r4, #0x10
    bls lbl_08055af4
    movs r3, #1
lbl_08055af4:
    cmp r3, #0
    beq lbl_08055b08
    ldr r2, lbl_08055b04 @ =gBLDYData2
    ldrb r1, [r2, #2]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r2, #2]
    b lbl_08055b1a
    .align 2, 0
lbl_08055b04: .4byte gBLDYData2
lbl_08055b08:
    ldr r0, lbl_08055b20 @ =gBLDYData2
    strb r1, [r0, #4]
    strb r2, [r0, #6]
    strb r4, [r0, #3]
    strb r3, [r0, #5]
    movs r1, #1
    strb r1, [r0, #2]
    bl TransparencyApplyNewEffects
lbl_08055b1a:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055b20: .4byte gBLDYData2

    thumb_func_start TransparencySpriteUpdateBLDALPHA
TransparencySpriteUpdateBLDALPHA: @ 0x08055b24
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r6, r1, #0
    lsls r2, r2, #0x18
    asrs r5, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    movs r0, #0
    cmp r4, #0x10
    bls lbl_08055b42
    movs r0, #1
lbl_08055b42:
    cmp r1, #0x10
    bls lbl_08055b48
    adds r0, #1
lbl_08055b48:
    cmp r0, #0
    beq lbl_08055b6c
    ldr r2, lbl_08055b64 @ =gDefaultTransparency
    ldr r1, lbl_08055b68 @ =gBldalphaData1
    ldrb r0, [r1, #4]
    ldrb r1, [r1, #3]
    adds r0, r0, r1
    movs r1, #0x10
    eors r0, r1
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r2, #1]
    b lbl_08055b8e
    .align 2, 0
lbl_08055b64: .4byte gDefaultTransparency
lbl_08055b68: .4byte gBldalphaData1
lbl_08055b6c:
    ldr r2, lbl_08055b94 @ =gBldalphaData2
    strb r5, [r2, #5]
    strb r3, [r2, #7]
    strb r4, [r2, #4]
    strb r6, [r2, #3]
    strb r0, [r2, #6]
    ldr r3, lbl_08055b98 @ =gDefaultTransparency
    adds r0, r4, r6
    movs r1, #0x10
    eors r0, r1
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r3, #1]
    movs r0, #1
    strb r0, [r2, #2]
    bl TransparencyApplyNewEffects
lbl_08055b8e:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055b94: .4byte gBldalphaData2
lbl_08055b98: .4byte gDefaultTransparency

    thumb_func_start TransparencyUpdateBLDY
TransparencyUpdateBLDY: @ 0x08055b9c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r3, #0
    cmp r4, #0x10
    bls lbl_08055bb4
    movs r3, #1
lbl_08055bb4:
    cmp r3, #0
    bne lbl_08055bc6
    ldr r0, lbl_08055bcc @ =gBLDYData1
    strb r1, [r0, #4]
    strb r2, [r0, #6]
    strb r4, [r0, #3]
    strb r3, [r0, #5]
    movs r1, #1
    strb r1, [r0, #2]
lbl_08055bc6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055bcc: .4byte gBLDYData1

    thumb_func_start TransparencyUpdateBLDALPHA
TransparencyUpdateBLDALPHA: @ 0x08055bd0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r6, r1, #0
    lsls r2, r2, #0x18
    asrs r5, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    movs r0, #0
    cmp r4, #0x10
    bls lbl_08055bee
    movs r0, #1
lbl_08055bee:
    cmp r1, #0x10
    bls lbl_08055bf4
    adds r0, #1
lbl_08055bf4:
    cmp r0, #0
    bne lbl_08055c16
    ldr r2, lbl_08055c1c @ =gBldalphaData1
    strb r5, [r2, #5]
    strb r3, [r2, #7]
    strb r4, [r2, #4]
    strb r6, [r2, #3]
    strb r0, [r2, #6]
    ldr r3, lbl_08055c20 @ =gDefaultTransparency
    adds r0, r4, r6
    movs r1, #0x10
    eors r0, r1
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    strb r0, [r3, #1]
    movs r0, #1
    strb r0, [r2, #2]
lbl_08055c16:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055c1c: .4byte gBldalphaData1
lbl_08055c20: .4byte gDefaultTransparency

    thumb_func_start TransparencyApplyNewEffects
TransparencyApplyNewEffects: @ 0x08055c24
    push {lr}
    ldr r0, lbl_08055c58 @ =gDefaultTransparency
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08055c6c
    ldr r3, lbl_08055c5c @ =gBLDYData2
    ldrb r2, [r3, #2]
    movs r1, #1
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3, #2]
    ldr r3, lbl_08055c60 @ =gBldalphaData2
    ldrb r2, [r3, #2]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3, #2]
    ldr r3, lbl_08055c64 @ =gBLDYData1
    ldrb r2, [r3, #2]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3, #2]
    ldr r2, lbl_08055c68 @ =gBldalphaData1
    ldrb r0, [r2, #2]
    ands r1, r0
    strb r1, [r2, #2]
    b lbl_08055cc2
    .align 2, 0
lbl_08055c58: .4byte gDefaultTransparency
lbl_08055c5c: .4byte gBLDYData2
lbl_08055c60: .4byte gBldalphaData2
lbl_08055c64: .4byte gBLDYData1
lbl_08055c68: .4byte gBldalphaData1
lbl_08055c6c:
    ldr r3, lbl_08055c90 @ =gBLDYData2
    ldrb r1, [r3, #2]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08055ca4
    ldr r3, lbl_08055c94 @ =gBldalphaData2
    ldrb r1, [r3, #2]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08055c98
    adds r0, r3, #0
    bl TransparencyApplyNewBLDALPHA
    b lbl_08055cc2
    .align 2, 0
lbl_08055c90: .4byte gBLDYData2
lbl_08055c94: .4byte gBldalphaData2
lbl_08055c98:
    ldr r3, lbl_08055cac @ =gBLDYData1
    ldrb r1, [r3, #2]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08055cb0
lbl_08055ca4:
    adds r0, r3, #0
    bl TransparencyApplyNewBLDY
    b lbl_08055cc2
    .align 2, 0
lbl_08055cac: .4byte gBLDYData1
lbl_08055cb0:
    ldr r3, lbl_08055cd4 @ =gBldalphaData1
    ldrb r1, [r3, #2]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08055cc2
    adds r0, r3, #0
    bl TransparencyApplyNewBLDALPHA
lbl_08055cc2:
    ldr r0, lbl_08055cd8 @ =gTransparencyRelated
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08055cce
    bl sub_08055e60
lbl_08055cce:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055cd4: .4byte gBldalphaData1
lbl_08055cd8: .4byte gTransparencyRelated

    thumb_func_start TransparencyApplyNewBLDALPHA
TransparencyApplyNewBLDALPHA: @ 0x08055cdc
    push {r4, r5, r6, r7, lr}
    adds r2, r0, #0
    movs r3, #0
    ldr r0, lbl_08055d14 @ =gWrittenToBLDALPHA
    ldrh r1, [r0]
    adds r7, r0, #0
    cmp r1, #0
    bne lbl_08055dae
    ldr r0, lbl_08055d18 @ =gCurrentPowerBomb
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08055dae
    ldrb r1, [r2, #2]
    movs r0, #0x80
    ands r0, r1
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_08055d02
    movs r3, #1
lbl_08055d02:
    cmp r3, #0
    bne lbl_08055dae
    ldrb r0, [r2, #6]
    cmp r0, #0
    beq lbl_08055d1c
    subs r0, #1
    strb r0, [r2, #6]
    b lbl_08055dae
    .align 2, 0
lbl_08055d14: .4byte gWrittenToBLDALPHA
lbl_08055d18: .4byte gCurrentPowerBomb
lbl_08055d1c:
    ldrb r0, [r2, #5]
    strb r0, [r2, #6]
    ldrb r0, [r2, #7]
    cmp r0, #0
    bne lbl_08055d2a
    movs r0, #1
    strb r0, [r2, #7]
lbl_08055d2a:
    ldr r0, lbl_08055d48 @ =gIoRegistersBackup
    ldrb r4, [r2, #4]
    ldrb r1, [r0, #4]
    adds r5, r0, #0
    cmp r4, r1
    beq lbl_08055d5c
    ldrb r3, [r2, #7]
    cmp r4, r1
    bhs lbl_08055d4c
    ldrb r0, [r5, #4]
    subs r3, r0, r3
    adds r0, r4, #0
    cmp r3, r0
    bge lbl_08055d58
    b lbl_08055d56
    .align 2, 0
lbl_08055d48: .4byte gIoRegistersBackup
lbl_08055d4c:
    ldrb r0, [r5, #4]
    adds r3, r3, r0
    ldrb r0, [r2, #4]
    cmp r3, r0
    ble lbl_08055d58
lbl_08055d56:
    adds r3, r0, #0
lbl_08055d58:
    strb r3, [r5, #4]
    movs r3, #1
lbl_08055d5c:
    ldrb r1, [r2, #3]
    ldrb r0, [r5, #5]
    cmp r1, r0
    beq lbl_08055d84
    ldrb r3, [r2, #7]
    cmp r1, r0
    bhs lbl_08055d74
    subs r3, r0, r3
    adds r0, r1, #0
    cmp r3, r0
    bge lbl_08055d80
    b lbl_08055d7e
lbl_08055d74:
    ldrb r0, [r5, #5]
    adds r3, r3, r0
    ldrb r0, [r2, #3]
    cmp r3, r0
    ble lbl_08055d80
lbl_08055d7e:
    adds r3, r0, #0
lbl_08055d80:
    strb r3, [r5, #5]
    movs r3, #1
lbl_08055d84:
    cmp r3, #0
    beq lbl_08055dac
    ldrb r0, [r5, #5]
    lsls r0, r0, #8
    ldrb r1, [r5, #4]
    orrs r1, r0
    strh r1, [r7]
    lsls r0, r6, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08055dae
    movs r0, #2
    orrs r0, r6
    strb r0, [r2, #2]
    ldr r1, lbl_08055da8 @ =gWrittenToBLDCNT
    ldrh r0, [r2]
    strh r0, [r1]
    b lbl_08055dae
    .align 2, 0
lbl_08055da8: .4byte gWrittenToBLDCNT
lbl_08055dac:
    strb r3, [r2, #2]
lbl_08055dae:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start TransparencyApplyNewBLDY
TransparencyApplyNewBLDY: @ 0x08055db4
    push {r4, r5, r6, r7, lr}
    adds r2, r0, #0
    movs r4, #0
    ldr r0, lbl_08055dec @ =gWrittenToBLDY
    movs r1, #0
    ldrsb r1, [r0, r1]
    adds r7, r0, #0
    cmp r1, #0
    bge lbl_08055e5a
    ldr r0, lbl_08055df0 @ =gCurrentPowerBomb
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08055e5a
    ldrb r1, [r2, #2]
    movs r0, #0x80
    ands r0, r1
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_08055ddc
    movs r4, #1
lbl_08055ddc:
    cmp r4, #0
    bne lbl_08055e5a
    ldrb r0, [r2, #5]
    cmp r0, #0
    beq lbl_08055df4
    subs r0, #1
    strb r0, [r2, #5]
    b lbl_08055e5a
    .align 2, 0
lbl_08055dec: .4byte gWrittenToBLDY
lbl_08055df0: .4byte gCurrentPowerBomb
lbl_08055df4:
    ldrb r0, [r2, #4]
    strb r0, [r2, #5]
    ldrb r0, [r2, #6]
    cmp r0, #0
    bne lbl_08055e02
    movs r0, #1
    strb r0, [r2, #6]
lbl_08055e02:
    ldr r0, lbl_08055e20 @ =gIoRegistersBackup
    ldrb r1, [r2, #3]
    ldrb r3, [r0, #6]
    adds r5, r0, #0
    cmp r1, r3
    beq lbl_08055e34
    ldrb r4, [r2, #6]
    cmp r1, r3
    bhs lbl_08055e24
    ldrb r0, [r5, #6]
    subs r4, r0, r4
    adds r0, r1, #0
    cmp r4, r0
    bge lbl_08055e30
    b lbl_08055e2e
    .align 2, 0
lbl_08055e20: .4byte gIoRegistersBackup
lbl_08055e24:
    ldrb r0, [r5, #6]
    adds r4, r4, r0
    ldrb r0, [r2, #3]
    cmp r4, r0
    ble lbl_08055e30
lbl_08055e2e:
    adds r4, r0, #0
lbl_08055e30:
    strb r4, [r5, #6]
    movs r4, #1
lbl_08055e34:
    cmp r4, #0
    beq lbl_08055e58
    ldrb r0, [r5, #6]
    strb r0, [r7]
    lsls r0, r6, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08055e5a
    movs r0, #2
    orrs r0, r6
    strb r0, [r2, #2]
    ldr r1, lbl_08055e54 @ =gWrittenToBLDCNT
    ldrh r0, [r2]
    strh r0, [r1]
    b lbl_08055e5a
    .align 2, 0
lbl_08055e54: .4byte gWrittenToBLDCNT
lbl_08055e58:
    strb r4, [r2, #2]
lbl_08055e5a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08055e60
sub_08055e60: @ 0x08055e60
    push {r4, lr}
    ldr r0, lbl_08055e8c @ =gCurrentPowerBomb
    ldrb r3, [r0]
    cmp r3, #0
    beq lbl_08055e9c
    cmp r3, #1
    bne lbl_08055f5e
    ldr r1, lbl_08055e90 @ =gTransparencyRelated
    movs r0, #0
    strb r0, [r1, #2]
    movs r0, #2
    strb r0, [r1, #1]
    ldr r0, lbl_08055e94 @ =gIoRegistersBackup
    ldrb r0, [r0, #5]
    adds r3, r0, #2
    ldr r2, lbl_08055e98 @ =gWrittenToBLDALPHA
    lsls r1, r3, #8
    movs r0, #0x10
    subs r0, r0, r3
    orrs r1, r0
    strh r1, [r2]
    b lbl_08055f5e
    .align 2, 0
lbl_08055e8c: .4byte gCurrentPowerBomb
lbl_08055e90: .4byte gTransparencyRelated
lbl_08055e94: .4byte gIoRegistersBackup
lbl_08055e98: .4byte gWrittenToBLDALPHA
lbl_08055e9c:
    ldr r2, lbl_08055ef0 @ =gTransparencyRelated
    ldrb r0, [r2, #2]
    adds r1, r0, #1
    strb r1, [r2, #2]
    ldrb r0, [r2]
    adds r4, r2, #0
    cmp r0, #2
    beq lbl_08055f06
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x13
    bls lbl_08055f5e
    strb r3, [r2, #2]
    ldrb r0, [r2, #1]
    adds r0, #1
    movs r1, #7
    ands r0, r1
    strb r0, [r2, #1]
    movs r3, #3
    ands r3, r0
    cmp r3, #0
    beq lbl_08055ed4
    movs r0, #1
    ands r0, r3
    movs r3, #2
    cmp r0, #0
    beq lbl_08055ed4
    movs r3, #1
lbl_08055ed4:
    ldrb r1, [r4, #1]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08055ee0
    rsbs r3, r3, #0
lbl_08055ee0:
    ldr r0, lbl_08055ef4 @ =gIoRegistersBackup
    ldrb r2, [r0, #4]
    ldrb r0, [r0, #5]
    adds r0, r0, r3
    cmp r0, #0
    bge lbl_08055ef8
    movs r0, #0
    b lbl_08055efe
    .align 2, 0
lbl_08055ef0: .4byte gTransparencyRelated
lbl_08055ef4: .4byte gIoRegistersBackup
lbl_08055ef8:
    cmp r0, #0x10
    ble lbl_08055efe
    movs r0, #0x10
lbl_08055efe:
    subs r2, r2, r3
    cmp r2, #0
    blt lbl_08055f4c
    b lbl_08055f50
lbl_08055f06:
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_08055f5e
    strb r3, [r2, #2]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bls lbl_08055f20
    strb r3, [r2, #1]
lbl_08055f20:
    ldrb r3, [r2, #1]
    cmp r3, #2
    bls lbl_08055f2a
    movs r0, #4
    subs r3, r0, r3
lbl_08055f2a:
    rsbs r3, r3, #0
    ldr r0, lbl_08055f3c @ =gIoRegistersBackup
    ldrb r2, [r0, #4]
    ldrb r0, [r0, #5]
    adds r0, r0, r3
    cmp r0, #0
    bge lbl_08055f40
    movs r0, #0
    b lbl_08055f46
    .align 2, 0
lbl_08055f3c: .4byte gIoRegistersBackup
lbl_08055f40:
    cmp r0, #0x10
    ble lbl_08055f46
    movs r0, #0x10
lbl_08055f46:
    subs r2, r2, r3
    cmp r2, #0
    bge lbl_08055f50
lbl_08055f4c:
    movs r2, #0
    b lbl_08055f56
lbl_08055f50:
    cmp r2, #0x10
    ble lbl_08055f56
    movs r2, #0x10
lbl_08055f56:
    ldr r1, lbl_08055f64 @ =gWrittenToBLDALPHA
    lsls r0, r0, #8
    orrs r0, r2
    strh r0, [r1]
lbl_08055f5e:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08055f64: .4byte gWrittenToBLDALPHA

    thumb_func_start unk_55f68
unk_55f68: @ 0x08055f68
    push {lr}
    bl UpdateAnimatedPaletteAfterTransitionOrReload
    bl ColorFadingTransferPaletteOnTransition
    bl CheckPlayLoadingJingle
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start RoomLoad
RoomLoad: @ 0x08055f7c
    push {r4, r5, lr}
    bl setup_clipdata_code
    bl reset_info_on_transition
    ldr r0, lbl_08055fa0 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08055fa4
    bl load_room_entry
    bl load_scrolls
    bl set_automatic_bg_scrolling
    b lbl_08056074
    .align 2, 0
lbl_08055fa0: .4byte gPauseScreenFlag
lbl_08055fa4:
    cmp r0, #6
    bne lbl_08056008
    ldr r0, lbl_08055ff0 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xe
    bne lbl_08056074
    ldr r2, lbl_08055ff4 @ =gEquipment
    ldrb r1, [r2, #0xf]
    movs r0, #0xef
    ands r0, r1
    strb r0, [r2, #0xf]
    movs r0, #0x1e
    bl SamusSetPose
    ldr r4, lbl_08055ff8 @ =gSamusData
    movs r5, #0
    movs r0, #0x9e
    lsls r0, r0, #2
    strh r0, [r4, #0x12]
    subs r0, #0x79
    strh r0, [r4, #0x14]
    ldr r1, lbl_08055ffc @ =gInGameCutscene
    strb r5, [r1, #2]
    movs r0, #9
    strb r0, [r1, #4]
    bl InGameCutsceneStart
    ldr r1, lbl_08056000 @ =gDisablePause
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08056004 @ =gSamusWeaponInfo
    strb r5, [r0, #5]
    movs r0, #1
    strh r0, [r4, #0xc]
    b lbl_08056074
    .align 2, 0
lbl_08055ff0: .4byte gCurrentItemBeingAcquired
lbl_08055ff4: .4byte gEquipment
lbl_08055ff8: .4byte gSamusData
lbl_08055ffc: .4byte gInGameCutscene
lbl_08056000: .4byte gDisablePause
lbl_08056004: .4byte gSamusWeaponInfo
lbl_08056008:
    cmp r0, #8
    bne lbl_08056068
    ldr r2, lbl_0805604c @ =gEquipment
    ldrb r1, [r2, #0xf]
    movs r0, #0xdf
    ands r0, r1
    strb r0, [r2, #0xf]
    movs r0, #0x1e
    bl SamusSetPose
    ldr r4, lbl_08056050 @ =gSamusData
    movs r5, #0
    movs r0, #0xc4
    lsls r0, r0, #3
    strh r0, [r4, #0x12]
    ldr r0, lbl_08056054 @ =0x000007bf
    strh r0, [r4, #0x14]
    ldr r1, lbl_08056058 @ =gInGameCutscene
    strb r5, [r1, #2]
    movs r0, #0xa
    strb r0, [r1, #4]
    bl InGameCutsceneStart
    ldr r1, lbl_0805605c @ =gDisablePause
    movs r0, #1
    strb r0, [r1]
    movs r0, #1
    strh r0, [r4, #0xc]
    ldr r1, lbl_08056060 @ =gCurrentItemBeingAcquired
    movs r0, #0xf
    strb r0, [r1]
    ldr r0, lbl_08056064 @ =gSamusWeaponInfo
    strb r5, [r0, #5]
    b lbl_08056074
    .align 2, 0
lbl_0805604c: .4byte gEquipment
lbl_08056050: .4byte gSamusData
lbl_08056054: .4byte 0x000007bf
lbl_08056058: .4byte gInGameCutscene
lbl_0805605c: .4byte gDisablePause
lbl_08056060: .4byte gCurrentItemBeingAcquired
lbl_08056064: .4byte gSamusWeaponInfo
lbl_08056068:
    cmp r0, #7
    bne lbl_08056074
    movs r0, #0xe
    movs r1, #0x10
    bl PlayMusic
lbl_08056074:
    bl load_tileset
    bl load_room_backgrounds
    bl remove_never_reform_blocks_and_collected_tank
    ldr r1, lbl_08056138 @ =gPreviousXPosition
    ldr r2, lbl_0805613c @ =gSamusData
    ldrh r0, [r2, #0x12]
    strh r0, [r1]
    ldr r1, lbl_08056140 @ =gPreviousYPosition
    ldrh r0, [r2, #0x14]
    strh r0, [r1]
    bl TransparencySetRoomEffectsTransparency
    bl InGameCutsceneCheckPlayOnTransition
    ldr r0, lbl_08056144 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080560c8
    ldr r0, lbl_08056148 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080560c8
    bl ScrollProcessGeneral
    ldr r1, lbl_0805614c @ =gBG1YPosition
    ldr r2, lbl_08056150 @ =gCamera
    ldrh r0, [r2, #2]
    strh r0, [r1]
    ldr r1, lbl_08056154 @ =gBG1XPosition
    ldrh r0, [r2]
    strh r0, [r1]
    bl sub_08058ec4
    bl ScrollProcessGeneral
lbl_080560c8:
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
    bl AnimatedGraphicsTanksAnimationReset
    bl SetBGHazeEffect
    bl ProcessHaze
    bl MinimapCheckOnTransition
    ldr r0, lbl_08056148 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08056168
    ldr r0, lbl_08056158 @ =gGameModeSub3
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08056168
    ldr r0, lbl_08056144 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08056168
    ldr r0, lbl_0805613c @ =gSamusData
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #0x1d
    bne lbl_08056168
    ldrh r0, [r2, #0x10]
    cmp r0, #0x40
    bne lbl_0805615c
    ldrh r0, [r2, #0x14]
    adds r0, #0xc0
    b lbl_08056160
    .align 2, 0
lbl_08056138: .4byte gPreviousXPosition
lbl_0805613c: .4byte gSamusData
lbl_08056140: .4byte gPreviousYPosition
lbl_08056144: .4byte gPauseScreenFlag
lbl_08056148: .4byte gIsLoadingFile
lbl_0805614c: .4byte gBG1YPosition
lbl_08056150: .4byte gCamera
lbl_08056154: .4byte gBG1XPosition
lbl_08056158: .4byte gGameModeSub3
lbl_0805615c:
    ldrh r0, [r2, #0x14]
    subs r0, #0xc0
lbl_08056160:
    strh r0, [r2, #0x14]
    ldr r1, lbl_080561a0 @ =gPreviousYPosition
    ldrh r0, [r2, #0x14]
    strh r0, [r1]
lbl_08056168:
    bl InGameCutsceneCheckStartQueried
    ldr r4, lbl_080561a4 @ =gRainSoundEffect
    ldrh r1, [r4]
    cmp r1, #0
    beq lbl_080561d4
    ldr r0, lbl_080561a8 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080561ca
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080561b4
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_080561ca
    ldr r0, lbl_080561ac @ =0x00000121
    movs r1, #0xa
    bl SoundFade
    ldrh r1, [r4]
    ldr r0, lbl_080561b0 @ =0x0000fffd
    ands r0, r1
    b lbl_080561c8
    .align 2, 0
lbl_080561a0: .4byte gPreviousYPosition
lbl_080561a4: .4byte gRainSoundEffect
lbl_080561a8: .4byte gPauseScreenFlag
lbl_080561ac: .4byte 0x00000121
lbl_080561b0: .4byte 0x0000fffd
lbl_080561b4:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080561ca
    ldr r0, lbl_080561dc @ =0x00000121
    bl SoundPlayNotAlreadyPlaying
    ldrh r0, [r4]
    movs r1, #2
    orrs r0, r1
lbl_080561c8:
    strh r0, [r4]
lbl_080561ca:
    ldr r2, lbl_080561e0 @ =gRainSoundEffect
    ldrh r1, [r2]
    ldr r0, lbl_080561e4 @ =0x0000fffe
    ands r0, r1
    strh r0, [r2]
lbl_080561d4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080561dc: .4byte 0x00000121
lbl_080561e0: .4byte gRainSoundEffect
lbl_080561e4: .4byte 0x0000fffe

    thumb_func_start load_tileset
load_tileset: @ 0x080561e8
    push {r4, r5, r6, lr}
    sub sp, #0x18
    ldr r2, lbl_08056250 @ =0x0833dfdc
    ldr r0, lbl_08056254 @ =gCurrentRoomEntry
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    lsls r0, r0, #2
    add r1, sp, #4
    adds r0, r0, r2
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, lbl_08056258 @ =gTilemapAndClipPointers
    ldr r2, lbl_0805625c @ =0x02004000
    str r2, [r0]
    ldr r5, lbl_08056260 @ =0x02002000
    str r5, [r0, #4]
    ldr r6, lbl_08056264 @ =0x02003000
    str r6, [r0, #8]
    ldr r1, [sp, #0x10]
    adds r1, #2
    movs r3, #0x80
    lsls r3, r3, #6
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_08056268 @ =gCurrentArea
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_08056274
    ldr r1, lbl_0805626c @ =0x08365c20
    movs r3, #0x80
    lsls r3, r3, #3
    str r4, [sp]
    movs r0, #3
    adds r2, r5, #0
    bl DMATransfer
    ldr r1, lbl_08056270 @ =0x08365cc0
    movs r3, #0x80
    lsls r3, r3, #4
    str r4, [sp]
    movs r0, #3
    adds r2, r6, #0
    bl DMATransfer
    b lbl_08056294
    .align 2, 0
lbl_08056250: .4byte 0x0833dfdc
lbl_08056254: .4byte gCurrentRoomEntry
lbl_08056258: .4byte gTilemapAndClipPointers
lbl_0805625c: .4byte 0x02004000
lbl_08056260: .4byte 0x02002000
lbl_08056264: .4byte 0x02003000
lbl_08056268: .4byte gCurrentArea
lbl_0805626c: .4byte 0x08365c20
lbl_08056270: .4byte 0x08365cc0
lbl_08056274:
    ldr r1, lbl_08056310 @ =0x085d91fc
    movs r3, #0x80
    lsls r3, r3, #3
    str r4, [sp]
    movs r0, #3
    adds r2, r5, #0
    bl DMATransfer
    ldr r1, lbl_08056314 @ =0x085d92ac
    movs r3, #0x80
    lsls r3, r3, #4
    str r4, [sp]
    movs r0, #3
    adds r2, r6, #0
    bl DMATransfer
lbl_08056294:
    ldr r1, lbl_08056318 @ =0x083655a0
    ldr r2, lbl_0805631c @ =0x02006000
    movs r5, #0x80
    lsls r5, r5, #5
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_08056320 @ =0x083654d0
    ldr r2, lbl_08056324 @ =0x02002400
    movs r3, #0x80
    lsls r3, r3, #2
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_08056328 @ =0x08365330
    ldr r2, lbl_0805632c @ =0x02003800
    movs r3, #0x80
    lsls r3, r3, #3
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, [sp, #4]
    ldr r1, lbl_08056330 @ =0x06005800
    bl CallLZ77UncompVRAM
    ldr r1, [sp, #8]
    adds r1, #0x20
    ldr r2, lbl_08056334 @ =0x05000060
    movs r3, #0xd0
    lsls r3, r3, #1
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_08056338 @ =gUseMotherShipDoors
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0805634c
    ldr r1, lbl_0805633c @ =0x085da40c
    ldr r2, lbl_08056340 @ =0x06004800
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_08056344 @ =0x085e0022
    ldr r2, lbl_08056348 @ =0x05000002
    str r4, [sp]
    movs r0, #3
    movs r3, #0x5e
    bl DMATransfer
    b lbl_08056368
    .align 2, 0
lbl_08056310: .4byte 0x085d91fc
lbl_08056314: .4byte 0x085d92ac
lbl_08056318: .4byte 0x083655a0
lbl_0805631c: .4byte 0x02006000
lbl_08056320: .4byte 0x083654d0
lbl_08056324: .4byte 0x02002400
lbl_08056328: .4byte 0x08365330
lbl_0805632c: .4byte 0x02003800
lbl_08056330: .4byte 0x06005800
lbl_08056334: .4byte 0x05000060
lbl_08056338: .4byte gUseMotherShipDoors
lbl_0805633c: .4byte 0x085da40c
lbl_08056340: .4byte 0x06004800
lbl_08056344: .4byte 0x085e0022
lbl_08056348: .4byte 0x05000002
lbl_0805634c:
    ldr r1, lbl_080563d8 @ =0x085d940c
    ldr r2, lbl_080563dc @ =0x06004800
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_080563e0 @ =0x085dfe22
    ldr r2, lbl_080563e4 @ =0x05000002
    str r4, [sp]
    movs r0, #3
    movs r3, #0x5e
    bl DMATransfer
lbl_08056368:
    ldr r2, lbl_080563e8 @ =gTilesetTransparentColor
    ldr r0, [sp, #8]
    ldrh r0, [r0]
    movs r1, #0
    strh r0, [r2]
    strh r1, [r2, #2]
    ldr r0, [sp, #0xc]
    ldrb r2, [r0, #2]
    lsls r2, r2, #8
    ldrb r1, [r0, #1]
    orrs r2, r1
    ldr r1, lbl_080563ec @ =0x0600fde0
    subs r1, r1, r2
    bl CallLZ77UncompVRAM
    ldr r2, lbl_080563f0 @ =0x0600ffe0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x20
    bl BitFill
    ldr r0, lbl_080563f4 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080563ce
    ldr r1, lbl_080563f8 @ =gCurrentRoomEntry
    ldr r2, lbl_080563fc @ =gAnimatedGraphicsEntry
    add r0, sp, #4
    ldrb r0, [r0, #0x10]
    strb r0, [r2, #1]
    strb r0, [r1, #0x1b]
    add r0, sp, #4
    ldrb r0, [r0, #0x11]
    strb r0, [r2]
    strb r0, [r1, #0x1c]
    ldrb r0, [r1, #3]
    cmp r0, #0x31
    bne lbl_080563ce
    ldr r2, lbl_08056400 @ =0x06002000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0x40
    bl BitFill
lbl_080563ce:
    add sp, #0x18
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080563d8: .4byte 0x085d940c
lbl_080563dc: .4byte 0x06004800
lbl_080563e0: .4byte 0x085dfe22
lbl_080563e4: .4byte 0x05000002
lbl_080563e8: .4byte gTilesetTransparentColor
lbl_080563ec: .4byte 0x0600fde0
lbl_080563f0: .4byte 0x0600ffe0
lbl_080563f4: .4byte gPauseScreenFlag
lbl_080563f8: .4byte gCurrentRoomEntry
lbl_080563fc: .4byte gAnimatedGraphicsEntry
lbl_08056400: .4byte 0x06002000

    thumb_func_start load_room_entry
load_room_entry: @ 0x08056404
    push {r4, r5, lr}
    sub sp, #0x3c
    ldr r1, lbl_08056480 @ =0x0875fac4
    ldr r0, lbl_08056484 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, lbl_08056488 @ =gCurrentRoom
    ldrb r2, [r1]
    ldr r0, [r0]
    lsls r1, r2, #4
    subs r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    mov r0, sp
    movs r2, #0x3c
    bl memcpy
    ldr r1, lbl_0805648c @ =gCurrentRoomEntry
    mov r0, sp
    ldrb r0, [r0]
    strb r0, [r1]
    mov r0, sp
    ldrb r0, [r0, #1]
    strb r0, [r1, #1]
    mov r0, sp
    ldrb r0, [r0, #2]
    strb r0, [r1, #2]
    mov r0, sp
    ldrb r0, [r0, #3]
    strb r0, [r1, #3]
    mov r0, sp
    ldrb r0, [r0, #4]
    strb r0, [r1, #4]
    mov r0, sp
    ldrb r0, [r0, #0x1c]
    strb r0, [r1, #6]
    mov r0, sp
    ldrb r0, [r0, #0x1d]
    strb r0, [r1, #7]
    mov r0, sp
    adds r0, #0x35
    ldrb r0, [r0]
    strb r0, [r1, #0xe]
    mov r0, sp
    adds r0, #0x36
    ldrb r0, [r0]
    strb r0, [r1, #0xf]
    mov r0, sp
    adds r0, #0x37
    ldrb r0, [r0]
    strb r0, [r1, #0x10]
    mov r0, sp
    ldrh r0, [r0, #0x3a]
    strh r0, [r1, #0x16]
    add r2, sp, #0x38
    ldrb r0, [r2]
    cmp r0, #0xff
    beq lbl_08056490
    lsls r2, r0, #6
    b lbl_08056494
    .align 2, 0
lbl_08056480: .4byte 0x0875fac4
lbl_08056484: .4byte gCurrentArea
lbl_08056488: .4byte gCurrentRoom
lbl_0805648c: .4byte gCurrentRoomEntry
lbl_08056490:
    ldr r0, lbl_08056554 @ =0x0000ffff
    adds r2, r0, #0
lbl_08056494:
    movs r0, #0
    strh r2, [r1, #0x12]
    ldr r5, lbl_08056558 @ =gSpritesetEntryUsed
    strb r0, [r5]
    ldr r4, lbl_0805655c @ =gCurrentRoomEntry
    mov r0, sp
    adds r0, #0x25
    ldrb r0, [r0]
    strb r0, [r4, #0xc]
    mov r0, sp
    adds r0, #0x2d
    ldrb r0, [r0]
    strb r0, [r4, #0xd]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_080564d0
    ldrb r1, [r4, #0xd]
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_080564d0
    ldr r0, [sp, #0x30]
    str r0, [r4, #8]
    ldr r1, lbl_08056560 @ =gSpriteset
    add r0, sp, #0x34
    ldrb r0, [r0]
    strb r0, [r1]
    movs r0, #2
    strb r0, [r5]
lbl_080564d0:
    ldr r0, lbl_0805655c @ =gCurrentRoomEntry
    ldrb r1, [r0, #0xc]
    adds r4, r0, #0
    cmp r1, #0
    beq lbl_08056500
    ldr r0, lbl_08056558 @ =gSpritesetEntryUsed
    ldrb r1, [r0]
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_08056518
    ldrb r1, [r4, #0xc]
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_08056500
    ldr r0, [sp, #0x28]
    str r0, [r4, #8]
    ldr r1, lbl_08056560 @ =gSpriteset
    add r0, sp, #0x2c
    ldrb r0, [r0]
    strb r0, [r1]
    movs r0, #1
    strb r0, [r5]
lbl_08056500:
    ldr r0, lbl_08056558 @ =gSpritesetEntryUsed
    ldrb r1, [r0]
    ldr r4, lbl_0805655c @ =gCurrentRoomEntry
    adds r5, r0, #0
    cmp r1, #0
    bne lbl_08056518
    ldr r0, [sp, #0x20]
    str r0, [r4, #8]
    ldr r1, lbl_08056560 @ =gSpriteset
    add r0, sp, #0x24
    ldrb r0, [r0]
    strb r0, [r1]
lbl_08056518:
    movs r0, #0
    movs r1, #2
    strb r1, [r4, #5]
    strb r0, [r4, #0x14]
    strb r0, [r4, #0x18]
    strb r0, [r4, #0x19]
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0805653a
    ldrb r0, [r4, #1]
    cmp r0, #0x44
    bne lbl_0805653a
    ldr r1, lbl_08056564 @ =gWaitingSpacePiratesPosition
    movs r0, #0x80
    lsls r0, r0, #8
    strh r0, [r1]
    strh r0, [r1, #2]
lbl_0805653a:
    movs r0, #0
    strb r0, [r4, #0x1a]
    ldrb r0, [r4, #4]
    cmp r0, #0x46
    bne lbl_0805654c
    movs r1, #1
    strb r1, [r4, #0x1a]
    ldr r0, lbl_08056568 @ =gBG0Movement
    strb r1, [r0]
lbl_0805654c:
    add sp, #0x3c
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056554: .4byte 0x0000ffff
lbl_08056558: .4byte gSpritesetEntryUsed
lbl_0805655c: .4byte gCurrentRoomEntry
lbl_08056560: .4byte gSpriteset
lbl_08056564: .4byte gWaitingSpacePiratesPosition
lbl_08056568: .4byte gBG0Movement

    thumb_func_start load_room_backgrounds
load_room_backgrounds: @ 0x0805656c
    push {r4, lr}
    sub sp, #0x40
    ldr r1, lbl_08056604 @ =0x0875fac4
    ldr r0, lbl_08056608 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, lbl_0805660c @ =gCurrentRoom
    ldrb r2, [r1]
    ldr r0, [r0]
    lsls r1, r2, #4
    subs r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    add r0, sp, #4
    movs r2, #0x3c
    bl memcpy
    ldr r2, lbl_08056610 @ =gCurrentRoomEntry
    ldr r1, [sp, #0x1c]
    ldrb r0, [r1]
    strb r0, [r2, #0x19]
    adds r3, r1, #4
    ldr r1, lbl_08056614 @ =0x02007000
    adds r0, r3, #0
    bl CallLZ77UncompWRAM
    ldr r0, lbl_08056618 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080566a4
    ldr r0, lbl_0805661c @ =gGameModeSub3
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_080565c6
    ldr r0, lbl_08056620 @ =gTourianEscapeCutsceneStage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_080565d8
lbl_080565c6:
    ldr r2, lbl_08056624 @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0x40
    bl BitFill
lbl_080565d8:
    ldr r2, lbl_08056610 @ =gCurrentRoomEntry
    ldrb r1, [r2, #1]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08056630
    ldr r3, [sp, #0xc]
    ldr r1, lbl_08056628 @ =gBGPointersAndDimensions
    ldr r2, lbl_0805662c @ =0x0202a800
    str r2, [r1]
    ldrb r0, [r3]
    strh r0, [r1, #4]
    adds r3, #1
    ldrb r0, [r3]
    strh r0, [r1, #6]
    adds r3, #1
    movs r0, #1
    adds r1, r3, #0
    bl RoomRLEDecompress
    b lbl_08056648
    .align 2, 0
lbl_08056604: .4byte 0x0875fac4
lbl_08056608: .4byte gCurrentArea
lbl_0805660c: .4byte gCurrentRoom
lbl_08056610: .4byte gCurrentRoomEntry
lbl_08056614: .4byte 0x02007000
lbl_08056618: .4byte gPauseScreenFlag
lbl_0805661c: .4byte gGameModeSub3
lbl_08056620: .4byte gTourianEscapeCutsceneStage
lbl_08056624: .4byte 0x06003000
lbl_08056628: .4byte gBGPointersAndDimensions
lbl_0805662c: .4byte 0x0202a800
lbl_08056630:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08056648
    ldr r3, [sp, #0xc]
    ldrb r0, [r3]
    strb r0, [r2, #0x18]
    adds r3, #4
    ldr r1, lbl_080566ac @ =0x0202a800
    adds r0, r3, #0
    bl CallLZ77UncompWRAM
lbl_08056648:
    ldr r3, [sp, #0x18]
    ldr r4, lbl_080566b0 @ =gBGPointersAndDimensions
    ldr r2, lbl_080566b4 @ =0x02027800
    str r2, [r4, #0x18]
    ldrb r0, [r3]
    strh r0, [r4, #0x1c]
    adds r3, #1
    ldrb r0, [r3]
    strh r0, [r4, #0x1e]
    adds r3, #1
    movs r0, #1
    adds r1, r3, #0
    bl RoomRLEDecompress
    ldr r3, [sp, #0x10]
    ldr r2, lbl_080566b8 @ =0x0202d800
    str r2, [r4, #8]
    ldrb r0, [r3]
    strh r0, [r4, #0xc]
    adds r3, #1
    ldrb r0, [r3]
    strh r0, [r4, #0xe]
    adds r3, #1
    movs r0, #1
    adds r1, r3, #0
    bl RoomRLEDecompress
    ldr r0, lbl_080566bc @ =gCurrentRoomEntry
    ldrb r1, [r0, #3]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080566a4
    ldr r3, [sp, #0x14]
    ldr r2, lbl_080566c0 @ =0x02030800
    str r2, [r4, #0x10]
    ldrb r0, [r3]
    strh r0, [r4, #0x14]
    adds r3, #1
    ldrb r0, [r3]
    strh r0, [r4, #0x16]
    adds r3, #1
    movs r0, #1
    adds r1, r3, #0
    bl RoomRLEDecompress
lbl_080566a4:
    add sp, #0x40
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080566ac: .4byte 0x0202a800
lbl_080566b0: .4byte gBGPointersAndDimensions
lbl_080566b4: .4byte 0x02027800
lbl_080566b8: .4byte 0x0202d800
lbl_080566bc: .4byte gCurrentRoomEntry
lbl_080566c0: .4byte 0x02030800

    thumb_func_start remove_never_reform_blocks_and_collected_tank
remove_never_reform_blocks_and_collected_tank: @ 0x080566c4
    push {lr}
    bl remove_never_reform_blocks
    bl remove_collected_tanks
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start reset_info_on_transition
reset_info_on_transition: @ 0x080566d4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_08056924 @ =gColorFading
    movs r2, #0
    strb r2, [r0, #3]
    strb r2, [r0, #2]
    strb r2, [r0, #4]
    strb r2, [r0, #1]
    movs r3, #0
    strh r2, [r0, #6]
    ldr r4, lbl_08056928 @ =gCurrentPowerBomb
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080566fe
    ldr r0, lbl_0805692c @ =gScreenShakeX
    ldr r1, lbl_08056930 @ =0x083458a4
    ldr r1, [r1]
    str r1, [r0]
lbl_080566fe:
    adds r1, r4, #0
    ldr r0, lbl_08056934 @ =0x08345890
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r4, r5}
    stm r1!, {r4, r5}
    ldr r0, lbl_08056938 @ =gWrittenToBLDCNT_Internal
    strh r2, [r0]
    ldr r0, lbl_0805693c @ =gScrollCounter
    strb r3, [r0]
    ldr r1, lbl_08056940 @ =gMusicTrackInfo
    strb r3, [r1, #3]
    ldr r0, lbl_08056944 @ =gGameModeSub3
    movs r2, #0
    ldrsb r2, [r0, r2]
    cmp r2, #0
    bne lbl_08056774
    strh r2, [r1]
    strb r3, [r1, #4]
    strb r3, [r1, #2]
    ldr r0, lbl_08056948 @ =gCurrentClipdataAffectingAction
    strb r3, [r0]
    ldr r1, lbl_0805694c @ =gAreaBeforeTransition
    movs r0, #0xff
    strb r0, [r1]
    ldr r0, lbl_08056950 @ =gDisableDoorAndTanks
    strb r3, [r0]
    ldr r0, lbl_08056954 @ =gCurrentCutscene
    strb r3, [r0]
    ldr r1, lbl_08056958 @ =gLastElevatorUsed
    ldr r0, lbl_0805695c @ =0x083458c8
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_08056960 @ =gRainSoundEffect
    strh r2, [r0]
    ldr r0, lbl_08056964 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08056762
    ldr r0, lbl_08056968 @ =gCurrentDemo
    ldrb r1, [r0, #2]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_08056762
    movs r0, #0
    bl unk_60cbc
lbl_08056762:
    ldr r1, lbl_0805696c @ =gDoorPositionStart
    movs r2, #0
    movs r0, #0
    strh r0, [r1]
    strh r0, [r1, #2]
    ldr r0, lbl_08056970 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    bl sub_080749e4
lbl_08056774:
    bl unk_5c158
    ldr r0, lbl_08056974 @ =gPauseScreenFlag
    movs r3, #0
    ldrsb r3, [r0, r3]
    cmp r3, #0
    beq lbl_08056784
    b lbl_08056aa0
lbl_08056784:
    ldr r0, lbl_08056978 @ =gDisableScrolling
    strb r3, [r0]
    ldr r0, lbl_0805697c @ =gSlowScrollingTimer
    movs r1, #0
    strh r3, [r0]
    ldr r0, lbl_08056980 @ =gCollectingTank
    strb r1, [r0]
    ldr r0, lbl_08056984 @ =gScreenShakeRelated
    strh r3, [r0]
    ldr r0, lbl_08056988 @ =gDisablePause
    strb r1, [r0]
    ldr r0, lbl_0805698c @ =gDisableClipdataChangingTransparency
    strb r1, [r0]
    ldr r0, lbl_08056990 @ =gWrittenTo0x05000000
    strh r3, [r0]
    ldr r0, lbl_08056994 @ =gScreenYOffset
    strb r1, [r0]
    ldr r0, lbl_08056998 @ =gScreenXOffset
    strh r3, [r0]
    ldr r0, lbl_0805699c @ =gDISPCNTBackup
    strh r3, [r0]
    ldr r0, lbl_080569a0 @ =gInGameCutscene
    strb r1, [r0, #3]
    strb r1, [r0, #4]
    ldr r0, lbl_080569a4 @ =gEffectYPosition
    strh r3, [r0]
    ldr r0, lbl_080569a8 @ =gHatchesState
    strb r1, [r0]
    strh r3, [r0, #2]
    strb r1, [r0, #1]
    strh r3, [r0, #4]
    strh r3, [r0, #6]
    ldr r0, lbl_080569ac @ =gDoorUnlockTimer
    strb r1, [r0]
    ldr r1, lbl_080569b0 @ =0x0875faa8
    ldr r0, lbl_080569b4 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r5, [r0]
    ldr r0, lbl_080569b8 @ =gLastDoorUsed
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r5, r5, r0
    ldr r1, lbl_080569bc @ =gCurrentRoom
    ldrb r0, [r5, #1]
    strb r0, [r1]
    ldr r1, lbl_080569c0 @ =gLastDoorProperties
    ldrb r0, [r5]
    strb r0, [r1]
    ldr r2, lbl_080569c4 @ =gDisplayLocationText
    ldrb r0, [r5]
    lsrs r0, r0, #6
    movs r1, #1
    ands r0, r1
    strb r0, [r2]
    ldr r1, lbl_0805696c @ =gDoorPositionStart
    ldrb r0, [r5, #2]
    strh r0, [r1]
    ldrb r0, [r5, #4]
    strh r0, [r1, #2]
    ldr r1, lbl_080569c8 @ =gWaitingSpacePiratesPosition
    ldr r0, lbl_080569cc @ =0x08345870
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, lbl_080569d0 @ =gLockScreen
    ldr r0, lbl_080569d4 @ =0x08345874
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080569d8 @ =gBackgroundEffect
    ldr r0, lbl_080569dc @ =0x0834587c
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_080569e0 @ =gWaterMovement
    ldr r0, lbl_080569e4 @ =0x083458c0
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_080569e8 @ =gEffectYPositionOffset
    strh r3, [r0]
    ldr r2, lbl_080569ec @ =gUnusedStruct_3005504
    ldr r0, lbl_080569f0 @ =0x083458b8
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r2, lbl_080569f4 @ =gBG0Movement
    ldr r0, lbl_080569f8 @ =0x083458a8
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_080569fc @ =gBG2Movement
    strh r3, [r0]
    strh r3, [r0, #2]
    ldr r6, lbl_08056930 @ =0x083458a4
    mov sl, r6
    ldr r6, lbl_08056a00 @ =gActiveBombChainTypes
    ldr r7, lbl_08056a04 @ =gDisableAnimatedGraphicsTimer
    ldr r0, lbl_08056a08 @ =gScreenShakeY
    mov ip, r0
    ldr r1, lbl_08056a0c @ =gScreenShakeXOffset
    mov r8, r1
    ldr r4, lbl_08056a10 @ =gScreenShakeYOffset
    mov sb, r4
    ldr r4, lbl_08056a14 @ =gBrokenBlocks
    ldr r0, lbl_08056a18 @ =0x08345884
    ldr r2, [r0]
    ldr r3, [r0, #4]
    movs r0, #0xbc
    lsls r0, r0, #1
    adds r1, r4, r0
lbl_0805686e:
    str r2, [r1]
    str r3, [r1, #4]
    subs r1, #8
    cmp r1, r4
    bge lbl_0805686e
    ldr r2, lbl_08056a1c @ =gBombchains
    ldr r0, lbl_08056a20 @ =0x0834588c
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0xc
lbl_08056882:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08056882
    movs r0, #0
    strb r0, [r6]
    strb r0, [r7]
    ldr r3, lbl_08056a24 @ =0x02027780
    movs r2, #0x40
    movs r1, #0
lbl_08056896:
    lsls r0, r2, #1
    adds r0, r0, r3
    subs r0, #2
    strh r1, [r0]
    subs r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    bne lbl_08056896
    mov r1, sl
    ldr r0, [r1]
    mov r4, ip
    str r0, [r4]
    ldr r6, lbl_0805692c @ =gScreenShakeX
    str r0, [r6]
    mov r0, r8
    strb r2, [r0]
    mov r1, sb
    strb r2, [r1]
    ldr r4, lbl_08056964 @ =gIsLoadingFile
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r0, #0
    beq lbl_080568c8
    b lbl_08056aa0
lbl_080568c8:
    ldr r0, lbl_08056a28 @ =gCamera
    movs r1, #0
    strh r2, [r0]
    strh r2, [r0, #2]
    strb r1, [r0, #4]
    strb r1, [r0, #5]
    ldrb r2, [r5, #2]
    ldrb r0, [r5, #5]
    adds r3, r0, #1
    ldr r4, lbl_08056a2c @ =gSamusData
    lsls r1, r2, #6
    movs r0, #7
    ldrsb r0, [r5, r0]
    adds r0, #8
    lsls r0, r0, #2
    adds r1, r1, r0
    strh r1, [r4, #0x12]
    lsls r1, r3, #6
    movs r0, #8
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r1, r1, r0
    subs r1, #1
    strh r1, [r4, #0x14]
    ldr r0, lbl_08056968 @ =gCurrentDemo
    ldrb r1, [r0, #2]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_0805690a
    movs r0, #1
    bl unk_60cbc
lbl_0805690a:
    ldr r2, lbl_080569c8 @ =gWaitingSpacePiratesPosition
    ldrh r1, [r4, #0x12]
    strh r1, [r2]
    ldrh r0, [r4, #0x14]
    strh r0, [r2, #2]
    movs r0, #7
    ldrsb r0, [r5, r0]
    cmp r0, #0
    bgt lbl_0805691e
    b lbl_08056a30
lbl_0805691e:
    adds r0, r1, #0
    subs r0, #0x20
    b lbl_08056a38
    .align 2, 0
lbl_08056924: .4byte gColorFading
lbl_08056928: .4byte gCurrentPowerBomb
lbl_0805692c: .4byte gScreenShakeX
lbl_08056930: .4byte 0x083458a4
lbl_08056934: .4byte 0x08345890
lbl_08056938: .4byte gWrittenToBLDCNT_Internal
lbl_0805693c: .4byte gScrollCounter
lbl_08056940: .4byte gMusicTrackInfo
lbl_08056944: .4byte gGameModeSub3
lbl_08056948: .4byte gCurrentClipdataAffectingAction
lbl_0805694c: .4byte gAreaBeforeTransition
lbl_08056950: .4byte gDisableDoorAndTanks
lbl_08056954: .4byte gCurrentCutscene
lbl_08056958: .4byte gLastElevatorUsed
lbl_0805695c: .4byte 0x083458c8
lbl_08056960: .4byte gRainSoundEffect
lbl_08056964: .4byte gIsLoadingFile
lbl_08056968: .4byte gCurrentDemo
lbl_0805696c: .4byte gDoorPositionStart
lbl_08056970: .4byte gCurrentItemBeingAcquired
lbl_08056974: .4byte gPauseScreenFlag
lbl_08056978: .4byte gDisableScrolling
lbl_0805697c: .4byte gSlowScrollingTimer
lbl_08056980: .4byte gCollectingTank
lbl_08056984: .4byte gScreenShakeRelated
lbl_08056988: .4byte gDisablePause
lbl_0805698c: .4byte gDisableClipdataChangingTransparency
lbl_08056990: .4byte gWrittenTo0x05000000
lbl_08056994: .4byte gScreenYOffset
lbl_08056998: .4byte gScreenXOffset
lbl_0805699c: .4byte gDISPCNTBackup
lbl_080569a0: .4byte gInGameCutscene
lbl_080569a4: .4byte gEffectYPosition
lbl_080569a8: .4byte gHatchesState
lbl_080569ac: .4byte gDoorUnlockTimer
lbl_080569b0: .4byte 0x0875faa8
lbl_080569b4: .4byte gCurrentArea
lbl_080569b8: .4byte gLastDoorUsed
lbl_080569bc: .4byte gCurrentRoom
lbl_080569c0: .4byte gLastDoorProperties
lbl_080569c4: .4byte gDisplayLocationText
lbl_080569c8: .4byte gWaitingSpacePiratesPosition
lbl_080569cc: .4byte 0x08345870
lbl_080569d0: .4byte gLockScreen
lbl_080569d4: .4byte 0x08345874
lbl_080569d8: .4byte gBackgroundEffect
lbl_080569dc: .4byte 0x0834587c
lbl_080569e0: .4byte gWaterMovement
lbl_080569e4: .4byte 0x083458c0
lbl_080569e8: .4byte gEffectYPositionOffset
lbl_080569ec: .4byte gUnusedStruct_3005504
lbl_080569f0: .4byte 0x083458b8
lbl_080569f4: .4byte gBG0Movement
lbl_080569f8: .4byte 0x083458a8
lbl_080569fc: .4byte gBG2Movement
lbl_08056a00: .4byte gActiveBombChainTypes
lbl_08056a04: .4byte gDisableAnimatedGraphicsTimer
lbl_08056a08: .4byte gScreenShakeY
lbl_08056a0c: .4byte gScreenShakeXOffset
lbl_08056a10: .4byte gScreenShakeYOffset
lbl_08056a14: .4byte gBrokenBlocks
lbl_08056a18: .4byte 0x08345884
lbl_08056a1c: .4byte gBombchains
lbl_08056a20: .4byte 0x0834588c
lbl_08056a24: .4byte 0x02027780
lbl_08056a28: .4byte gCamera
lbl_08056a2c: .4byte gSamusData
lbl_08056a30:
    cmp r0, #0
    bge lbl_08056a3a
    adds r0, r1, #0
    adds r0, #0x20
lbl_08056a38:
    strh r0, [r2]
lbl_08056a3a:
    ldr r0, lbl_08056a50 @ =gSamusDoorPositionOffset
    movs r5, #0
    ldrsh r3, [r0, r5]
    ldr r2, lbl_08056a54 @ =gSamusData
    adds r4, r0, #0
    cmp r3, #0
    beq lbl_08056a84
    cmp r3, #0
    bge lbl_08056a58
    movs r0, #0
    b lbl_08056a74
    .align 2, 0
lbl_08056a50: .4byte gSamusDoorPositionOffset
lbl_08056a54: .4byte gSamusData
lbl_08056a58:
    ldr r0, lbl_08056ab0 @ =gSamusPhysics
    adds r0, #0x70
    movs r6, #0
    ldrsh r0, [r0, r6]
    rsbs r0, r0, #0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    movs r1, #0
    ldrsh r0, [r4, r1]
    adds r0, r3, r0
    cmp r0, #0xff
    ble lbl_08056a76
    movs r0, #0xff
    subs r0, r0, r3
lbl_08056a74:
    strh r0, [r4]
lbl_08056a76:
    ldr r2, lbl_08056ab4 @ =gSamusData
    ldrh r0, [r2, #0x14]
    ldrh r1, [r4]
    subs r0, r0, r1
    movs r1, #0
    strh r0, [r2, #0x14]
    strh r1, [r4]
lbl_08056a84:
    ldrb r0, [r2, #1]
    cmp r0, #1
    bne lbl_08056a8e
    movs r0, #2
    strb r0, [r2, #1]
lbl_08056a8e:
    ldr r0, lbl_08056ab8 @ =gBG1YPosition
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08056abc @ =gBG1XPosition
    strh r1, [r0]
    ldr r0, lbl_08056ac0 @ =gBG0XPosition
    strh r1, [r0]
    ldr r0, lbl_08056ac4 @ =gBG0YPosition
    strh r1, [r0]
lbl_08056aa0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056ab0: .4byte gSamusPhysics
lbl_08056ab4: .4byte gSamusData
lbl_08056ab8: .4byte gBG1YPosition
lbl_08056abc: .4byte gBG1XPosition
lbl_08056ac0: .4byte gBG0XPosition
lbl_08056ac4: .4byte gBG0YPosition

    thumb_func_start set_automatic_bg_scrolling
set_automatic_bg_scrolling: @ 0x08056ac8
    push {lr}
    ldr r2, lbl_08056af8 @ =gBG3Movement
    ldr r0, lbl_08056afc @ =0x083458b0
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08056b00 @ =gCurrentRoomEntry
    ldrb r1, [r0, #6]
    adds r3, r0, #0
    cmp r1, #7
    blt lbl_08056aec
    cmp r1, #8
    ble lbl_08056ae8
    cmp r1, #0xa
    bne lbl_08056aec
lbl_08056ae8:
    movs r0, #1
    strb r0, [r2]
lbl_08056aec:
    ldrb r1, [r3, #0x10]
    cmp r1, #1
    bne lbl_08056b08
    ldr r0, lbl_08056b04 @ =gBG0Movement
    strb r1, [r0]
    b lbl_08056b16
    .align 2, 0
lbl_08056af8: .4byte gBG3Movement
lbl_08056afc: .4byte 0x083458b0
lbl_08056b00: .4byte gCurrentRoomEntry
lbl_08056b04: .4byte gBG0Movement
lbl_08056b08:
    cmp r1, #6
    beq lbl_08056b10
    cmp r1, #7
    bne lbl_08056b16
lbl_08056b10:
    ldr r1, lbl_08056b20 @ =gBG0Movement
    movs r0, #4
    strb r0, [r1]
lbl_08056b16:
    ldr r1, lbl_08056b24 @ =gInGameCutscene
    movs r0, #0
    strb r0, [r1, #4]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056b20: .4byte gBG0Movement
lbl_08056b24: .4byte gInGameCutscene

    thumb_func_start sub_08056b28
sub_08056b28: @ 0x08056b28
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    cmp r0, #0
    bne lbl_08056b58
    ldr r1, lbl_08056b4c @ =gCurrentRoomEntry
    ldrb r2, [r1, #1]
    ldr r0, lbl_08056b50 @ =gBG0YPosition
    ldrh r0, [r0]
    lsrs r6, r0, #6
    ldr r0, lbl_08056b54 @ =gBG0XPosition
    b lbl_08056b84
    .align 2, 0
lbl_08056b4c: .4byte gCurrentRoomEntry
lbl_08056b50: .4byte gBG0YPosition
lbl_08056b54: .4byte gBG0XPosition
lbl_08056b58:
    mov r0, sb
    cmp r0, #1
    bne lbl_08056b78
    ldr r1, lbl_08056b6c @ =gCurrentRoomEntry
    ldrb r2, [r1, #2]
    ldr r0, lbl_08056b70 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r6, r0, #6
    ldr r0, lbl_08056b74 @ =gBG1XPosition
    b lbl_08056b84
    .align 2, 0
lbl_08056b6c: .4byte gCurrentRoomEntry
lbl_08056b70: .4byte gBG1YPosition
lbl_08056b74: .4byte gBG1XPosition
lbl_08056b78:
    ldr r1, lbl_08056c94 @ =gCurrentRoomEntry
    ldrb r2, [r1, #3]
    ldr r0, lbl_08056c98 @ =gBG2YPosition
    ldrh r0, [r0]
    lsrs r6, r0, #6
    ldr r0, lbl_08056c9c @ =gBG2XPosition
lbl_08056b84:
    ldrh r0, [r0]
    lsrs r3, r0, #6
    movs r7, #0x10
    adds r0, r2, #0
    ands r0, r7
    cmp r0, #0
    bne lbl_08056b94
    b lbl_08056cac
lbl_08056b94:
    movs r1, #0x15
    str r1, [sp, #0xc]
    subs r4, r3, #3
    cmp r4, #0
    bge lbl_08056ba0
    movs r4, #0
lbl_08056ba0:
    ldr r1, lbl_08056ca0 @ =gBGPointersAndDimensions
    mov r2, sb
    lsls r0, r2, #3
    adds r5, r0, r1
    ldrh r1, [r5, #4]
    subs r0, r1, r4
    ldr r3, [sp, #0xc]
    cmp r3, r0
    ble lbl_08056bb8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0xc]
lbl_08056bb8:
    lsls r0, r4, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #8]
    movs r0, #0x10
    str r0, [sp, #0x10]
    subs r4, r6, #3
    cmp r4, #0
    bge lbl_08056bca
    movs r4, #0
lbl_08056bca:
    ldrh r0, [r5, #6]
    subs r0, r0, r4
    cmp r7, r0
    ble lbl_08056bd8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #0x10]
lbl_08056bd8:
    lsls r0, r4, #0x10
    lsrs r0, r0, #0x10
    muls r1, r0, r1
    ldr r2, [sp, #8]
    adds r1, r2, r1
    lsls r1, r1, #1
    ldr r2, [r5]
    adds r2, r2, r1
    str r2, [sp, #4]
    adds r1, r0, #0
    movs r2, #0
    ldr r3, [sp, #0x10]
    cmp r2, r3
    blt lbl_08056bf6
    b lbl_08056d02
lbl_08056bf6:
    str r5, [sp, #0x14]
lbl_08056bf8:
    ldr r3, [sp, #0x14]
    ldrh r0, [r3, #4]
    muls r0, r2, r0
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldr r5, [sp, #8]
    adds r2, #1
    str r2, [sp, #0x18]
    adds r0, r1, #1
    mov sl, r0
    ldr r2, [sp, #0xc]
    cmp r2, #0
    beq lbl_08056c82
    mov r3, sb
    lsls r3, r3, #0xc
    mov ip, r3
    movs r0, #0xf
    ands r1, r0
    lsls r1, r1, #6
    mov r8, r1
    adds r6, r2, #0
lbl_08056c22:
    movs r0, #0xc0
    lsls r0, r0, #0x13
    mov r1, ip
    adds r3, r1, r0
    movs r0, #0x10
    ands r0, r5
    cmp r0, #0
    beq lbl_08056c36
    ldr r3, lbl_08056ca4 @ =0x06000800
    add r3, ip
lbl_08056c36:
    adds r0, r5, #0
    movs r2, #0xf
    ands r0, r2
    lsls r0, r0, #1
    add r0, r8
    lsls r0, r0, #1
    adds r3, r3, r0
    lsls r0, r7, #1
    ldr r1, [sp, #4]
    adds r0, r0, r1
    ldrh r4, [r0]
    lsls r1, r4, #3
    ldr r2, lbl_08056ca8 @ =gTilemapAndClipPointers
    ldr r0, [r2]
    adds r0, r0, r1
    ldrh r1, [r0]
    strh r1, [r3]
    adds r0, #2
    ldrh r1, [r0]
    strh r1, [r3, #2]
    adds r0, #2
    adds r2, r3, #0
    adds r2, #0x40
    ldrh r1, [r0]
    strh r1, [r2]
    adds r1, r3, #0
    adds r1, #0x42
    ldrh r0, [r0, #2]
    strh r0, [r1]
    adds r0, r7, #1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    subs r6, #1
    adds r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r6, #0
    bne lbl_08056c22
lbl_08056c82:
    ldr r2, [sp, #0x18]
    mov r3, sl
    lsls r0, r3, #0x10
    lsrs r1, r0, #0x10
    ldr r0, [sp, #0x10]
    cmp r2, r0
    blt lbl_08056bf8
    b lbl_08056d02
    .align 2, 0
lbl_08056c94: .4byte gCurrentRoomEntry
lbl_08056c98: .4byte gBG2YPosition
lbl_08056c9c: .4byte gBG2XPosition
lbl_08056ca0: .4byte gBGPointersAndDimensions
lbl_08056ca4: .4byte 0x06000800
lbl_08056ca8: .4byte gTilemapAndClipPointers
lbl_08056cac:
    cmp r2, #0
    bne lbl_08056cca
    mov r1, sb
    lsls r2, r1, #0xc
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #5
    str r7, [sp]
    movs r0, #3
    movs r1, #0x40
    bl BitFill
    b lbl_08056d02
lbl_08056cca:
    movs r0, #0x40
    ands r2, r0
    cmp r2, #0
    beq lbl_08056d02
    mov r2, sb
    cmp r2, #0
    bne lbl_08056d02
    movs r4, #0x80
    lsls r4, r4, #4
    ldrb r1, [r1, #0x18]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08056ce8
    lsls r4, r4, #1
lbl_08056ce8:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08056cf2
    lsls r4, r4, #1
lbl_08056cf2:
    ldr r1, lbl_08056d14 @ =0x0202a800
    movs r2, #0xc0
    lsls r2, r2, #0x13
    str r7, [sp]
    movs r0, #3
    adds r3, r4, #0
    bl DMATransfer
lbl_08056d02:
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056d14: .4byte 0x0202a800

    thumb_func_start RoomRLEDecompress
RoomRLEDecompress: @ 0x08056d18
    push {r4, r5, r6, lr}
    sub sp, #4
    adds r4, r1, #0
    adds r5, r2, #0
    lsls r0, r0, #0x18
    movs r6, #0
    movs r3, #0xc0
    lsls r3, r3, #6
    cmp r0, #0
    bne lbl_08056d48
    ldrb r0, [r4]
    movs r6, #0x80
    lsls r6, r6, #4
    cmp r0, #0
    beq lbl_08056d42
    movs r6, #0x80
    lsls r6, r6, #5
    cmp r0, #3
    bne lbl_08056d42
    movs r6, #0x80
    lsls r6, r6, #6
lbl_08056d42:
    adds r4, #1
    movs r3, #0x80
    lsls r3, r3, #6
lbl_08056d48:
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    bl BitFill
    movs r3, #0
lbl_08056d58:
    adds r2, r5, #0
    cmp r3, #0
    beq lbl_08056d60
    adds r2, #1
lbl_08056d60:
    ldrb r0, [r4]
    adds r4, #1
    cmp r0, #1
    bne lbl_08056db6
    ldrb r1, [r4]
    adds r4, #1
    adds r3, #1
    cmp r1, #0
    beq lbl_08056e1a
lbl_08056d72:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08056da8
    movs r0, #0x7f
    ands r1, r0
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_08056d96
    cmp r1, #0
    beq lbl_08056d9a
lbl_08056d88:
    ldrb r0, [r4]
    strb r0, [r2]
    adds r2, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_08056d88
    b lbl_08056d9a
lbl_08056d96:
    lsls r0, r1, #1
    adds r2, r2, r0
lbl_08056d9a:
    adds r4, #1
    b lbl_08056dac
lbl_08056d9e:
    ldrb r0, [r4]
    strb r0, [r2]
    adds r4, #1
    adds r2, #2
    subs r1, #1
lbl_08056da8:
    cmp r1, #0
    bne lbl_08056d9e
lbl_08056dac:
    ldrb r1, [r4]
    adds r4, #1
    cmp r1, #0
    bne lbl_08056d72
    b lbl_08056e1a
lbl_08056db6:
    ldrb r1, [r4]
    adds r4, #1
    lsls r1, r1, #8
    ldrb r0, [r4]
    orrs r1, r0
    adds r4, #1
    adds r3, #1
    cmp r1, #0
    beq lbl_08056e1a
lbl_08056dc8:
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08056e06
    ldr r0, lbl_08056df0 @ =0x00007fff
    ands r1, r0
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_08056df4
    cmp r1, #0
    beq lbl_08056df8
lbl_08056de0:
    ldrb r0, [r4]
    strb r0, [r2]
    adds r2, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_08056de0
    b lbl_08056df8
    .align 2, 0
lbl_08056df0: .4byte 0x00007fff
lbl_08056df4:
    lsls r0, r1, #1
    adds r2, r2, r0
lbl_08056df8:
    adds r4, #1
    b lbl_08056e0a
lbl_08056dfc:
    ldrb r0, [r4]
    strb r0, [r2]
    adds r4, #1
    adds r2, #2
    subs r1, #1
lbl_08056e06:
    cmp r1, #0
    bne lbl_08056dfc
lbl_08056e0a:
    ldrb r1, [r4]
    adds r4, #1
    lsls r1, r1, #8
    ldrb r0, [r4]
    orrs r1, r0
    adds r4, #1
    cmp r1, #0
    bne lbl_08056dc8
lbl_08056e1a:
    cmp r3, #1
    ble lbl_08056d58
    adds r0, r6, #0
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start RoomUpdateGFXInfo
RoomUpdateGFXInfo: @ 0x08056e28
    push {lr}
    ldr r0, lbl_08056e40 @ =gSamusData
    ldrb r0, [r0]
    cmp r0, #0x1d
    beq lbl_08056e48
    ldr r2, lbl_08056e44 @ =gDisableDoorAndTanks
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r2]
    b lbl_08056e52
    .align 2, 0
lbl_08056e40: .4byte gSamusData
lbl_08056e44: .4byte gDisableDoorAndTanks
lbl_08056e48:
    ldr r0, lbl_08056e60 @ =gDisableDoorAndTanks
    ldrb r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strb r1, [r0]
lbl_08056e52:
    ldr r0, lbl_08056e64 @ =gMonochromeBgFading
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08056e68
    bl ColorFadingApplyMonochrome
    b lbl_08056e70
    .align 2, 0
lbl_08056e60: .4byte gDisableDoorAndTanks
lbl_08056e64: .4byte gMonochromeBgFading
lbl_08056e68:
    bl update_minimap
    bl TransparencyApplyNewEffects
lbl_08056e70:
    pop {r0}
    bx r0

    thumb_func_start RoomUpdateAnimatedGraphicsAndPalettes
RoomUpdateAnimatedGraphicsAndPalettes: @ 0x08056e74
    push {r4, lr}
    movs r2, #0
    movs r4, #0
    ldr r0, lbl_08056e8c @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #1
    beq lbl_08056e88
    cmp r0, #3
    bne lbl_08056e90
lbl_08056e88:
    movs r2, #1
    b lbl_08056e98
    .align 2, 0
lbl_08056e8c: .4byte gGameModeSub1
lbl_08056e90:
    cmp r0, #2
    beq lbl_08056e98
    movs r2, #1
    movs r4, #1
lbl_08056e98:
    ldr r0, lbl_08056ee4 @ =gPreventMovementTimer
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_08056ea2
    movs r4, #1
lbl_08056ea2:
    ldr r1, lbl_08056ee8 @ =gDisableAnimatedGraphicsTimer
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08056eb2
    subs r0, #1
    strb r0, [r1]
    movs r2, #1
    movs r4, #1
lbl_08056eb2:
    cmp r2, #0
    bne lbl_08056eca
    ldr r0, lbl_08056eec @ =gBackgroundEffect
    ldrb r0, [r0, #5]
    cmp r0, #0
    beq lbl_08056eca
    ldr r0, lbl_08056ef0 @ =gCurrentPowerBomb
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08056eca
    bl BackgroundEffectUpdate
lbl_08056eca:
    cmp r4, #0
    bne lbl_08056ede
    bl AnimatedGraphicsUpdate
    bl AnimatedGraphicsTanksAnimationUpdate
    bl AnimatedPaletteUpdate
    bl RoomUpdateHatchFlashingAnimation
lbl_08056ede:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056ee4: .4byte gPreventMovementTimer
lbl_08056ee8: .4byte gDisableAnimatedGraphicsTimer
lbl_08056eec: .4byte gBackgroundEffect
lbl_08056ef0: .4byte gCurrentPowerBomb

    thumb_func_start RoomUpdateHatchFlashingAnimation
RoomUpdateHatchFlashingAnimation: @ 0x08056ef4
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_08056fa8 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_08056fa0
    ldr r0, lbl_08056fac @ =gUseMotherShipDoors
    ldrb r0, [r0]
    ldr r4, lbl_08056fb0 @ =0x085e0420
    cmp r0, #0
    beq lbl_08056f0e
    ldr r4, lbl_08056fb4 @ =0x085e0220
lbl_08056f0e:
    ldr r0, lbl_08056fb8 @ =gHatchesState
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08056f58
    ldr r1, lbl_08056fbc @ =gHatchFlashingAnimation
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bls lbl_08056f58
    strb r2, [r1]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    ble lbl_08056f3e
    strb r2, [r1, #1]
lbl_08056f3e:
    ldrb r1, [r1, #1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r1, r1, #5
    adds r1, #0xc
    adds r1, r4, r1
    ldr r2, lbl_08056fc0 @ =0x0500002c
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #4
    bl DMATransfer
lbl_08056f58:
    ldr r0, lbl_08056fb8 @ =gHatchesState
    ldrb r0, [r0, #1]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08056fa0
    ldr r2, lbl_08056fbc @ =gHatchFlashingAnimation
    ldrb r0, [r2, #2]
    adds r0, #1
    movs r1, #0
    strb r0, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bls lbl_08056fa0
    strb r1, [r2, #2]
    ldrb r0, [r2, #3]
    adds r0, #1
    strb r0, [r2, #3]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    ble lbl_08056f88
    strb r1, [r2, #3]
lbl_08056f88:
    ldr r1, lbl_08056fc4 @ =0x040000d4
    movs r0, #3
    ldrsb r0, [r2, r0]
    lsls r0, r0, #5
    adds r0, #0xc
    adds r0, r4, r0
    str r0, [r1]
    ldr r0, lbl_08056fc8 @ =0x0500004c
    str r0, [r1, #4]
    ldr r0, lbl_08056fcc @ =0x80000002
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_08056fa0:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08056fa8: .4byte gGameModeSub1
lbl_08056fac: .4byte gUseMotherShipDoors
lbl_08056fb0: .4byte 0x085e0420
lbl_08056fb4: .4byte 0x085e0220
lbl_08056fb8: .4byte gHatchesState
lbl_08056fbc: .4byte gHatchFlashingAnimation
lbl_08056fc0: .4byte 0x0500002c
lbl_08056fc4: .4byte 0x040000d4
lbl_08056fc8: .4byte 0x0500004c
lbl_08056fcc: .4byte 0x80000002

    thumb_func_start RoomUpdate
RoomUpdate: @ 0x08056fd0
    push {r4, lr}
    ldr r0, lbl_08057094 @ =gDisableScrolling
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08057042
    ldr r0, lbl_08057098 @ =gColorFading
    ldrb r0, [r0, #1]
    cmp r0, #0
    bne lbl_08057042
    bl update_backgrounds_pos
    ldr r0, lbl_0805709c @ =gScrollCounter
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    bne lbl_08057008
    ldr r0, lbl_080570a0 @ =gCamera
    movs r1, #4
    ldrsb r1, [r0, r1]
    movs r0, #0x1c
    rsbs r0, r0, #0
    cmp r1, r0
    blt lbl_08057008
    cmp r1, #0x1c
    ble lbl_08057016
lbl_08057008:
    movs r0, #0x10
    bl sub_080572f8
    movs r0, #2
    rsbs r0, r0, #0
    bl sub_080572f8
lbl_08057016:
    ldr r0, lbl_0805709c @ =gScrollCounter
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08057034
    ldr r0, lbl_080570a0 @ =gCamera
    movs r1, #5
    ldrsb r1, [r0, r1]
    movs r0, #0x1c
    rsbs r0, r0, #0
    cmp r1, r0
    blt lbl_08057034
    cmp r1, #0x1c
    ble lbl_08057042
lbl_08057034:
    movs r0, #0xb
    bl sub_080571d4
    movs r0, #2
    rsbs r0, r0, #0
    bl sub_080571d4
lbl_08057042:
    ldr r4, lbl_080570a4 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #2
    bne lbl_0805706c
    bl check_special_clipdata
    movs r1, #0
    ldrsh r0, [r4, r1]
    cmp r0, #2
    bne lbl_0805706c
    bl update_broken_blocks
    bl process_bomb_chains
    bl InGameCutsceneProcess
    bl check_unlock_doors
    bl ConnectionUpdateHatches
lbl_0805706c:
    bl ProcessHaze
    cmp r0, #0
    beq lbl_0805708a
    bl ProcessHaze
    ldr r2, lbl_080570a8 @ =gHazeInfo
    ldrb r1, [r2, #7]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0805708a
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #7]
lbl_0805708a:
    bl PowerBombExplosionProcess
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057094: .4byte gDisableScrolling
lbl_08057098: .4byte gColorFading
lbl_0805709c: .4byte gScrollCounter
lbl_080570a0: .4byte gCamera
lbl_080570a4: .4byte gGameModeSub1
lbl_080570a8: .4byte gHazeInfo

    thumb_func_start update_backgrounds_pos
update_backgrounds_pos: @ 0x080570ac
    push {r4, r5, r6, lr}
    bl update_vertical_screen_shake
    adds r5, r0, #0
    bl update_horizontal_screen_shake
    adds r4, r0, #0
    ldr r0, lbl_0805711c @ =gBG1XPosition
    ldrh r1, [r0]
    lsrs r1, r1, #2
    ldr r0, lbl_08057120 @ =0x000001ff
    adds r3, r0, #0
    ands r1, r3
    ldr r0, lbl_08057124 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r3
    ldr r2, lbl_08057128 @ =gBackgroundPositions
    adds r1, r1, r4
    strh r1, [r2, #4]
    adds r0, r0, r5
    strh r0, [r2, #6]
    ldr r0, lbl_0805712c @ =gBG2XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r3
    adds r0, r0, r4
    strh r0, [r2, #8]
    ldr r0, lbl_08057130 @ =gBG2YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r3
    adds r0, r0, r5
    strh r0, [r2, #0xa]
    ldr r0, lbl_08057134 @ =gScreenShakeRelated
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08057144
    ldr r0, lbl_08057138 @ =gBG0XPosition
    ldrh r0, [r0]
    ldr r1, lbl_0805713c @ =gBG0Movement
    lsrs r0, r0, #2
    ldrh r6, [r1, #4]
    adds r0, r0, r6
    ands r0, r3
    strh r0, [r2]
    ldr r0, lbl_08057140 @ =gBG0YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldrh r1, [r1, #6]
    adds r0, r0, r1
    ands r0, r3
    b lbl_08057164
    .align 2, 0
lbl_0805711c: .4byte gBG1XPosition
lbl_08057120: .4byte 0x000001ff
lbl_08057124: .4byte gBG1YPosition
lbl_08057128: .4byte gBackgroundPositions
lbl_0805712c: .4byte gBG2XPosition
lbl_08057130: .4byte gBG2YPosition
lbl_08057134: .4byte gScreenShakeRelated
lbl_08057138: .4byte gBG0XPosition
lbl_0805713c: .4byte gBG0Movement
lbl_08057140: .4byte gBG0YPosition
lbl_08057144:
    ldr r0, lbl_08057198 @ =gBG0XPosition
    ldrh r0, [r0]
    ldr r1, lbl_0805719c @ =gBG0Movement
    lsrs r0, r0, #2
    ldrh r6, [r1, #4]
    adds r0, r0, r6
    ands r0, r3
    adds r0, r0, r4
    strh r0, [r2]
    ldr r0, lbl_080571a0 @ =gBG0YPosition
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldrh r1, [r1, #6]
    adds r0, r0, r1
    ands r0, r3
    adds r0, r0, r5
lbl_08057164:
    strh r0, [r2, #2]
    ldr r0, lbl_080571a4 @ =gBG3XPosition
    ldrh r0, [r0]
    ldr r1, lbl_080571a8 @ =gBG3Movement
    lsrs r0, r0, #2
    ldrh r1, [r1, #4]
    adds r3, r0, r1
    ldr r0, lbl_080571ac @ =0x000001ff
    adds r1, r0, #0
    ands r3, r1
    ldr r0, lbl_080571b0 @ =gBG3YPosition
    ldrh r0, [r0]
    lsrs r2, r0, #2
    ands r2, r1
    ldr r0, lbl_080571b4 @ =gScreenShakeRelated
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_080571bc
    ldr r0, lbl_080571b8 @ =gBackgroundPositions
    strh r3, [r0, #0xc]
    strh r2, [r0, #0xe]
    b lbl_080571ca
    .align 2, 0
lbl_08057198: .4byte gBG0XPosition
lbl_0805719c: .4byte gBG0Movement
lbl_080571a0: .4byte gBG0YPosition
lbl_080571a4: .4byte gBG3XPosition
lbl_080571a8: .4byte gBG3Movement
lbl_080571ac: .4byte 0x000001ff
lbl_080571b0: .4byte gBG3YPosition
lbl_080571b4: .4byte gScreenShakeRelated
lbl_080571b8: .4byte gBackgroundPositions
lbl_080571bc:
    ldr r0, lbl_080571d0 @ =gBackgroundPositions
    asrs r1, r4, #1
    adds r1, r3, r1
    strh r1, [r0, #0xc]
    asrs r1, r5, #1
    adds r1, r2, r1
    strh r1, [r0, #0xe]
lbl_080571ca:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080571d0: .4byte gBackgroundPositions

    thumb_func_start sub_080571d4
sub_080571d4: @ 0x080571d4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov sl, r0
    movs r7, #0
    ldr r0, lbl_080571fc @ =gCurrentRoomEntry
    mov sb, r0
lbl_080571ea:
    cmp r7, #0
    bne lbl_08057208
    mov r1, sb
    ldrb r4, [r1, #1]
    ldr r0, lbl_08057200 @ =gBG0YPosition
    ldrh r0, [r0]
    lsrs r2, r0, #6
    ldr r0, lbl_08057204 @ =gBG0XPosition
    b lbl_08057230
    .align 2, 0
lbl_080571fc: .4byte gCurrentRoomEntry
lbl_08057200: .4byte gBG0YPosition
lbl_08057204: .4byte gBG0XPosition
lbl_08057208:
    cmp r7, #1
    bne lbl_08057224
    mov r2, sb
    ldrb r4, [r2, #2]
    ldr r0, lbl_0805721c @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r2, r0, #6
    ldr r0, lbl_08057220 @ =gBG1XPosition
    b lbl_08057230
    .align 2, 0
lbl_0805721c: .4byte gBG1YPosition
lbl_08057220: .4byte gBG1XPosition
lbl_08057224:
    mov r0, sb
    ldrb r4, [r0, #3]
    ldr r0, lbl_080572e8 @ =gBG2YPosition
    ldrh r0, [r0]
    lsrs r2, r0, #6
    ldr r0, lbl_080572ec @ =gBG2XPosition
lbl_08057230:
    ldrh r0, [r0]
    lsrs r5, r0, #6
    movs r0, #0x10
    ands r0, r4
    adds r1, r7, #1
    mov r8, r1
    cmp r0, #0
    beq lbl_080572d4
    mov r0, sl
    adds r4, r2, r0
    cmp r4, #0
    blt lbl_080572d4
    lsls r0, r7, #3
    ldr r2, lbl_080572f0 @ =gBGPointersAndDimensions
    adds r1, r0, r2
    ldrh r0, [r1, #6]
    cmp r4, r0
    bgt lbl_080572d4
    lsls r0, r4, #0x10
    lsrs r2, r0, #0x10
    subs r4, r5, #2
    cmp r4, #0
    bge lbl_08057260
    movs r4, #0
lbl_08057260:
    lsls r0, r4, #0x10
    lsrs r5, r0, #0x10
    movs r3, #0x13
    ldrh r0, [r1, #4]
    cmp r0, #0x13
    bge lbl_0805726e
    adds r3, r0, #0
lbl_0805726e:
    muls r0, r2, r0
    adds r6, r0, r5
    lsls r0, r7, #0xc
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r7, r0, r4
    movs r0, #0xf
    ands r2, r0
    lsls r0, r2, #7
    adds r7, r7, r0
    cmp r3, #0
    beq lbl_080572d4
    ldr r0, lbl_080572f4 @ =gTilemapAndClipPointers
    ldr r1, [r1]
    ldr r0, [r0]
    mov ip, r0
    adds r4, r3, #0
    lsls r0, r6, #1
    adds r6, r0, r1
lbl_08057294:
    ldrh r0, [r6]
    lsls r0, r0, #3
    mov r1, ip
    adds r3, r1, r0
    movs r2, #0xf
    ands r2, r5
    movs r0, #0x10
    ands r0, r5
    cmp r0, #0
    beq lbl_080572ae
    movs r0, #0x80
    lsls r0, r0, #2
    adds r2, r2, r0
lbl_080572ae:
    lsls r2, r2, #2
    adds r2, r2, r7
    ldrh r1, [r3]
    ldrh r0, [r3, #2]
    lsls r0, r0, #0x10
    orrs r1, r0
    str r1, [r2]
    ldrh r1, [r3, #4]
    ldrh r0, [r3, #6]
    lsls r0, r0, #0x10
    orrs r1, r0
    str r1, [r2, #0x40]
    subs r4, #1
    adds r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r6, #2
    cmp r4, #0
    bne lbl_08057294
lbl_080572d4:
    mov r7, r8
    cmp r7, #2
    ble lbl_080571ea
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080572e8: .4byte gBG2YPosition
lbl_080572ec: .4byte gBG2XPosition
lbl_080572f0: .4byte gBGPointersAndDimensions
lbl_080572f4: .4byte gTilemapAndClipPointers

    thumb_func_start sub_080572f8
sub_080572f8: @ 0x080572f8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    str r0, [sp]
    movs r6, #0
lbl_0805730c:
    cmp r6, #0
    bne lbl_0805732c
    ldr r0, lbl_08057320 @ =gCurrentRoomEntry
    ldrb r4, [r0, #1]
    ldr r0, lbl_08057324 @ =gBG0YPosition
    ldrh r0, [r0]
    lsrs r5, r0, #6
    ldr r0, lbl_08057328 @ =gBG0XPosition
    b lbl_08057358
    .align 2, 0
lbl_08057320: .4byte gCurrentRoomEntry
lbl_08057324: .4byte gBG0YPosition
lbl_08057328: .4byte gBG0XPosition
lbl_0805732c:
    cmp r6, #1
    bne lbl_0805734c
    ldr r1, lbl_08057340 @ =gCurrentRoomEntry
    ldrb r4, [r1, #2]
    ldr r0, lbl_08057344 @ =gBG1YPosition
    ldrh r0, [r0]
    lsrs r5, r0, #6
    ldr r0, lbl_08057348 @ =gBG1XPosition
    b lbl_08057358
    .align 2, 0
lbl_08057340: .4byte gCurrentRoomEntry
lbl_08057344: .4byte gBG1YPosition
lbl_08057348: .4byte gBG1XPosition
lbl_0805734c:
    ldr r7, lbl_08057424 @ =gCurrentRoomEntry
    ldrb r4, [r7, #3]
    ldr r0, lbl_08057428 @ =gBG2YPosition
    ldrh r0, [r0]
    lsrs r5, r0, #6
    ldr r0, lbl_0805742c @ =gBG2XPosition
lbl_08057358:
    ldrh r0, [r0]
    lsrs r1, r0, #6
    movs r0, #0x10
    mov r8, r0
    ands r4, r0
    adds r7, r6, #1
    mov sl, r7
    cmp r4, #0
    beq lbl_0805740a
    ldr r0, [sp]
    adds r4, r1, r0
    cmp r4, #0
    blt lbl_0805740a
    lsls r0, r6, #3
    ldr r1, lbl_08057430 @ =gBGPointersAndDimensions
    adds r3, r0, r1
    ldrh r2, [r3, #4]
    cmp r4, r2
    bgt lbl_0805740a
    lsls r0, r4, #0x10
    lsrs r1, r0, #0x10
    subs r4, r5, #2
    cmp r4, #0
    bge lbl_0805738a
    movs r4, #0
lbl_0805738a:
    lsls r0, r4, #0x10
    lsrs r5, r0, #0x10
    movs r4, #0xe
    ldrh r0, [r3, #6]
    cmp r0, #0xe
    bge lbl_08057398
    adds r4, r0, #0
lbl_08057398:
    adds r0, r2, #0
    muls r0, r5, r0
    adds r0, r0, r1
    str r0, [sp, #4]
    lsls r2, r6, #0xc
    movs r7, #0xc0
    lsls r7, r7, #0x13
    adds r6, r2, r7
    adds r0, r1, #0
    mov r7, r8
    ands r0, r7
    cmp r0, #0
    beq lbl_080573b6
    ldr r0, lbl_08057434 @ =0x06000800
    adds r6, r2, r0
lbl_080573b6:
    movs r0, #0xf
    ands r1, r0
    lsls r0, r1, #2
    adds r6, r6, r0
    cmp r4, #0
    beq lbl_0805740a
    ldr r0, lbl_08057438 @ =gTilemapAndClipPointers
    mov ip, r3
    ldr r0, [r0]
    mov sb, r0
    ldr r1, [r3]
    mov r8, r1
lbl_080573ce:
    ldr r7, [sp, #4]
    lsls r0, r7, #1
    add r0, r8
    ldrh r2, [r0]
    lsls r2, r2, #3
    add r2, sb
    movs r3, #0xf
    ands r3, r5
    lsls r3, r3, #7
    adds r3, r3, r6
    ldrh r1, [r2]
    ldrh r0, [r2, #2]
    lsls r0, r0, #0x10
    orrs r1, r0
    str r1, [r3]
    ldrh r1, [r2, #4]
    ldrh r0, [r2, #6]
    lsls r0, r0, #0x10
    orrs r1, r0
    str r1, [r3, #0x40]
    mov r1, ip
    ldrh r0, [r1, #4]
    adds r7, r7, r0
    str r7, [sp, #4]
    adds r0, r5, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    subs r4, #1
    cmp r4, #0
    bne lbl_080573ce
lbl_0805740a:
    mov r6, sl
    cmp r6, #2
    bgt lbl_08057412
    b lbl_0805730c
lbl_08057412:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057424: .4byte gCurrentRoomEntry
lbl_08057428: .4byte gBG2YPosition
lbl_0805742c: .4byte gBG2XPosition
lbl_08057430: .4byte gBGPointersAndDimensions
lbl_08057434: .4byte 0x06000800
lbl_08057438: .4byte gTilemapAndClipPointers

    thumb_func_start check_dma3_ended
check_dma3_ended: @ 0x0805743c
    push {lr}
    ldr r2, lbl_08057458 @ =0x040000d4
    ldr r0, [r2, #8]
    movs r1, #0x80
    lsls r1, r1, #0x18
    cmp r0, #0
    bge lbl_08057452
lbl_0805744a:
    ldr r0, [r2, #8]
    ands r0, r1
    cmp r0, #0
    bne lbl_0805744a
lbl_08057452:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057458: .4byte 0x040000d4
