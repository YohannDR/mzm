    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start SramRead_All
SramRead_All: @ 0x0807329c
    push {r4, r5, lr}
    movs r4, #3
    ldr r5, lbl_080732b8 @ =gSramCorruptFlag
lbl_080732a2:
    cmp r4, #0
    beq lbl_080732b2
    bl sub_08074304
    ldrb r0, [r5]
    subs r4, #1
    cmp r0, #0
    bne lbl_080732a2
lbl_080732b2:
    movs r4, #3
    b lbl_080732c2
    .align 2, 0
lbl_080732b8: .4byte gSramCorruptFlag
lbl_080732bc:
    subs r4, #1
    cmp r4, #0
    beq lbl_080732d2
lbl_080732c2:
    movs r0, #0xe
    bl DoSramOperation
    movs r0, #0x10
    bl DoSramOperation
    cmp r0, #0
    bne lbl_080732bc
lbl_080732d2:
    bl sub_08073394
    bl sub_080743a4
    bl sub_08074a7c
    bl sub_08075010
    bl sub_08074da4
    cmp r0, #0
    beq lbl_080732f4
    ldr r1, lbl_080732fc @ =gLanguage
    movs r0, #2
    strb r0, [r1]
    bl SramWrite_Language
lbl_080732f4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080732fc: .4byte gLanguage

    thumb_func_start SramWrite_FileScreenOptionsUnlocked
SramWrite_FileScreenOptionsUnlocked: @ 0x08073300
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073388 @ =0x08754bc8
    ldr r4, [r2]
    movs r0, #0x30
    strb r0, [r4, #8]
    movs r0, #0x31
    strb r0, [r4, #9]
    ldrh r0, [r4, #0xa]
    adds r0, #1
    strh r0, [r4, #0xa]
    ldr r1, lbl_0807338c @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1]
    strh r0, [r4, #0xc]
    ldrb r0, [r1, #4]
    strb r0, [r4, #0xe]
    movs r0, #2
    strb r0, [r4, #0xf]
    movs r0, #0x34
    strb r0, [r4, #0x10]
    ldrb r0, [r1, #5]
    strb r0, [r4, #0x11]
    ldrb r0, [r1, #6]
    strb r0, [r4, #0x12]
    ldrb r0, [r1, #7]
    strb r0, [r4, #0x13]
    ldrh r0, [r1, #2]
    strh r0, [r4, #0x14]
    ldr r0, [r1, #8]
    str r0, [r4, #0x18]
    movs r3, #0
    adds r6, r2, #0
    adds r2, r4, #0
    adds r2, #0x1c
    ldr r5, lbl_08073390 @ =0x08411468
lbl_08073344:
    adds r0, r2, r3
    adds r1, r3, r5
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073344
    movs r0, #0
    str r0, [r4]
    subs r0, #1
    str r0, [r4, #4]
    ldr r2, [r6]
    movs r1, #0
    movs r3, #3
lbl_08073360:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073360
    str r1, [r4]
    mvns r0, r1
    str r0, [r4, #4]
    movs r0, #0
    bl DoSramOperation
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073388: .4byte 0x08754bc8
lbl_0807338c: .4byte gFileScreenOptionsUnlocked
lbl_08073390: .4byte 0x08411468

    thumb_func_start sub_08073394
sub_08073394: @ 0x08073394
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #8
    movs r0, #0
    bl sub_080734e8
    adds r6, r0, #0
    movs r0, #1
    bl sub_080734e8
    mov r8, r0
    movs r0, #2
    bl sub_080734e8
    adds r7, r0, #0
    cmp r6, #0
    beq lbl_08073470
    add r0, sp, #4
    ldr r1, lbl_08073404 @ =0x0000ffff
    adds r5, r1, #0
    strh r5, [r0]
    ldr r1, lbl_08073408 @ =0x040000d4
    str r0, [r1]
    ldr r3, lbl_0807340c @ =0x08754bc8
    mov sb, r3
    ldr r2, [r3]
    str r2, [r1, #4]
    ldr r4, lbl_08073410 @ =0x81000020
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    cmp r7, #0
    beq lbl_08073432
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    ldr r3, lbl_08073414 @ =0x00006d40
    adds r0, r2, r3
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    adds r3, r2, #0
    mov r0, r8
    cmp r0, #0
    beq lbl_08073418
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    adds r0, r3, #0
    adds r0, #0x40
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_080734a4
    .align 2, 0
lbl_08073404: .4byte 0x0000ffff
lbl_08073408: .4byte 0x040000d4
lbl_0807340c: .4byte 0x08754bc8
lbl_08073410: .4byte 0x81000020
lbl_08073414: .4byte 0x00006d40
lbl_08073418:
    adds r1, r2, #0
    adds r1, #0x40
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    movs r6, #0
    movs r0, #0
    bl DoSramOperation
    b lbl_080734a4
lbl_08073432:
    ldr r3, lbl_0807346c @ =0x00006d40
    adds r1, r2, r3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    movs r6, #0
    movs r0, #0
    bl DoSramOperation
    mov r0, r8
    cmp r0, #0
    beq lbl_080734a4
    mov r3, sb
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0x40
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    movs r0, #1
    bl DoSramOperation
    b lbl_080734a4
    .align 2, 0
lbl_0807346c: .4byte 0x00006d40
lbl_08073470:
    ldr r4, lbl_080734b0 @ =0x08754bc8
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x40
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    movs r0, #1
    bl DoSramOperation
    cmp r7, #0
    beq lbl_080734a4
    ldr r1, [r4]
    ldr r0, lbl_080734b4 @ =0x00006d40
    adds r2, r1, r0
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    movs r0, #2
    bl DoSramOperation
lbl_080734a4:
    cmp r6, #0
    bne lbl_080734b8
    bl sub_08073584
    b lbl_080734d0
    .align 2, 0
lbl_080734b0: .4byte 0x08754bc8
lbl_080734b4: .4byte 0x00006d40
lbl_080734b8:
    bl EraseSram
    ldr r1, lbl_080734e0 @ =0x0841147c
    ldr r2, lbl_080734e4 @ =gFileScreenOptionsUnlocked
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0xc
    bl DmaTransfer
    bl SramWrite_FileScreenOptionsUnlocked
lbl_080734d0:
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080734e0: .4byte 0x0841147c
lbl_080734e4: .4byte gFileScreenOptionsUnlocked

    thumb_func_start sub_080734e8
sub_080734e8: @ 0x080734e8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r4, #0
    cmp r0, #2
    bne lbl_08073508
    ldr r0, lbl_08073500 @ =0x08754bc8
    ldr r0, [r0]
    ldr r1, lbl_08073504 @ =0x00006d40
    adds r0, r0, r1
    b lbl_0807351c
    .align 2, 0
lbl_08073500: .4byte 0x08754bc8
lbl_08073504: .4byte 0x00006d40
lbl_08073508:
    cmp r0, #1
    bne lbl_08073518
    ldr r0, lbl_08073514 @ =0x08754bc8
    ldr r0, [r0]
    adds r0, #0x40
    b lbl_0807351c
    .align 2, 0
lbl_08073514: .4byte 0x08754bc8
lbl_08073518:
    ldr r0, lbl_0807357c @ =0x08754bc8
    ldr r0, [r0]
lbl_0807351c:
    movs r2, #0
    adds r1, r0, #0
    ldr r7, [r1]
    adds r5, r1, #0
    adds r5, #0x1c
    ldr r0, [r1, #4]
    mov ip, r0
    movs r3, #3
lbl_0807352c:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_0807352c
    cmp r7, r2
    beq lbl_0807354a
    movs r0, #1
    orrs r4, r0
lbl_0807354a:
    movs r3, #0
    adds r2, r5, #0
    ldr r6, lbl_08073580 @ =0x08411468
    movs r5, #2
lbl_08073552:
    adds r0, r2, r3
    adds r1, r3, r6
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08073560
    orrs r4, r5
lbl_08073560:
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073552
    mov r1, ip
    mvns r0, r1
    cmp r7, r0
    beq lbl_08073572
    movs r0, #4
    orrs r4, r0
lbl_08073572:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807357c: .4byte 0x08754bc8
lbl_08073580: .4byte 0x08411468

    thumb_func_start sub_08073584
sub_08073584: @ 0x08073584
    ldr r0, lbl_080735a8 @ =0x08754bc8
    ldr r1, [r0]
    ldr r2, lbl_080735ac @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1, #0xc]
    strh r0, [r2]
    ldrb r0, [r1, #0xe]
    strb r0, [r2, #4]
    ldrb r0, [r1, #0x11]
    strb r0, [r2, #5]
    ldrb r0, [r1, #0x12]
    strb r0, [r2, #6]
    ldrb r0, [r1, #0x13]
    strb r0, [r2, #7]
    ldrh r0, [r1, #0x14]
    strh r0, [r2, #2]
    ldr r0, [r1, #0x18]
    str r0, [r2, #8]
    bx lr
    .align 2, 0
lbl_080735a8: .4byte 0x08754bc8
lbl_080735ac: .4byte gFileScreenOptionsUnlocked

    thumb_func_start SramProcessIntroSave
SramProcessIntroSave: @ 0x080735b0
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_080735d8 @ =gDisableSoftreset
    ldrb r0, [r1]
    ldr r2, lbl_080735dc @ =gSramOperationStage
    cmp r0, #0
    bne lbl_080735c4
    strb r0, [r2]
    movs r0, #1
    strb r0, [r1]
lbl_080735c4:
    ldrb r0, [r2]
    cmp r0, #4
    bls lbl_080735cc
    b lbl_080736bc
lbl_080735cc:
    lsls r0, r0, #2
    ldr r1, lbl_080735e0 @ =lbl_080735e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080735d8: .4byte gDisableSoftreset
lbl_080735dc: .4byte gSramOperationStage
lbl_080735e0: .4byte lbl_080735e4
lbl_080735e4: @ jump table
    .4byte lbl_080735f8 @ case 0
    .4byte lbl_08073658 @ case 1
    .4byte lbl_08073668 @ case 2
    .4byte lbl_08073674 @ case 3
    .4byte lbl_080736bc @ case 4
lbl_080735f8:
    ldr r5, lbl_08073648 @ =gGameCompletion
    movs r3, #1
    strb r3, [r5, #1]
    ldr r4, lbl_0807364c @ =gSaveFilesInfo
    ldr r2, lbl_08073650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    strb r3, [r0, #0x12]
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    ldrb r0, [r0, #0x11]
    strb r0, [r5]
    ldr r3, lbl_08073654 @ =0x08754bc8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r3]
    adds r2, r2, r0
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    b lbl_080736a2
    .align 2, 0
lbl_08073648: .4byte gGameCompletion
lbl_0807364c: .4byte gSaveFilesInfo
lbl_08073650: .4byte gMostRecentSaveFile
lbl_08073654: .4byte 0x08754bc8
lbl_08073658:
    bl sub_080736d8
    ldr r1, lbl_08073664 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    b lbl_080736a2
    .align 2, 0
lbl_08073664: .4byte gUnk_3000c20
lbl_08073668:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_080736c4
    b lbl_080736a2
lbl_08073674:
    ldr r2, lbl_080736ac @ =0x08754bc8
    ldr r0, lbl_080736b0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080736b4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_080736a2:
    ldr r1, lbl_080736b8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080736c4
    .align 2, 0
lbl_080736ac: .4byte 0x08754bc8
lbl_080736b0: .4byte gMostRecentSaveFile
lbl_080736b4: .4byte 0x000036e0
lbl_080736b8: .4byte gSramOperationStage
lbl_080736bc:
    ldr r1, lbl_080736d4 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r2]
lbl_080736c4:
    ldr r0, lbl_080736d4 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080736d4: .4byte gDisableSoftreset

    thumb_func_start sub_080736d8
sub_080736d8: @ 0x080736d8
    push {r4, lr}
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_080737ac @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_080737b0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r1, lbl_080737b4 @ =gGameCompletion
    ldrb r0, [r1, #1]
    strb r0, [r4, #0x19]
    ldrb r0, [r1]
    strb r0, [r4, #0x18]
    ldr r0, lbl_080737b8 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_080737bc @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3e
    strb r0, [r1]
    ldr r0, lbl_080737c0 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r4, #0x1a]
    ldr r2, lbl_080737c4 @ =gBestCompletionTimes
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_0807373e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_0807373e
    movs r1, #0x94
    lsls r1, r1, #2
    adds r0, r4, r1
    ldr r1, lbl_080737c8 @ =0x08411430
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073772:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073772
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080737a4: .4byte 0x08754bc8
lbl_080737a8: .4byte gMostRecentSaveFile
lbl_080737ac: .4byte 0x08411410
lbl_080737b0: .4byte 0x08411420
lbl_080737b4: .4byte gGameCompletion
lbl_080737b8: .4byte gDifficulty
lbl_080737bc: .4byte gTimeAttackFlag
lbl_080737c0: .4byte gLanguage
lbl_080737c4: .4byte gBestCompletionTimes
lbl_080737c8: .4byte 0x08411430

    thumb_func_start SramProcessEndingSave
SramProcessEndingSave: @ 0x080737cc
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_080737e8 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_080737de
    b lbl_080738e0
lbl_080737de:
    lsls r0, r1, #2
    ldr r1, lbl_080737ec @ =lbl_080737f0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080737e8: .4byte gSramOperationStage
lbl_080737ec: .4byte lbl_080737f0
lbl_080737f0: @ jump table
    .4byte lbl_08073808 @ case 0
    .4byte lbl_0807381c @ case 1
    .4byte lbl_08073828 @ case 2
    .4byte lbl_08073868 @ case 3
    .4byte lbl_08073898 @ case 4
    .4byte lbl_080738e0 @ case 5
lbl_08073808:
    ldr r1, lbl_08073818 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_080738e6
    .align 2, 0
lbl_08073818: .4byte gUnk_3000c20
lbl_0807381c:
    movs r0, #2
    bl unk_fbc
    cmp r0, #0
    beq lbl_080738e6
    b lbl_080738c6
lbl_08073828:
    movs r2, #1
    ldr r0, lbl_08073858 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073838
    movs r2, #8
lbl_08073838:
    ldr r1, lbl_0807385c @ =gGameCompletion
    ldr r0, lbl_08073860 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl check_set_new_best_completion_time
    bl sub_080739e8
    ldr r0, lbl_08073864 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_080738c6
    .align 2, 0
lbl_08073858: .4byte gLanguage
lbl_0807385c: .4byte gGameCompletion
lbl_08073860: .4byte gDifficulty
lbl_08073864: .4byte gUnk_3000c20
lbl_08073868:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_080738e6
    ldr r2, lbl_0807388c @ =gSaveFilesInfo
    ldr r0, lbl_08073890 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073894 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_080738c6
    .align 2, 0
lbl_0807388c: .4byte gSaveFilesInfo
lbl_08073890: .4byte gMostRecentSaveFile
lbl_08073894: .4byte gGameCompletion
lbl_08073898:
    ldr r2, lbl_080738d0 @ =0x08754bc8
    ldr r0, lbl_080738d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080738d8 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_080738c6:
    ldr r1, lbl_080738dc @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080738e6
    .align 2, 0
lbl_080738d0: .4byte 0x08754bc8
lbl_080738d4: .4byte gMostRecentSaveFile
lbl_080738d8: .4byte 0x000036e0
lbl_080738dc: .4byte gSramOperationStage
lbl_080738e0:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_080738e6:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start check_set_new_best_completion_time
check_set_new_best_completion_time: @ 0x080738f0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080739cc @ =0x083459a0
    mov r8, r0
    ldrb r4, [r0, #0x1c]
    ldr r7, lbl_080739d0 @ =gEquipment
    ldrh r0, [r7]
    ldr r2, lbl_080739d4 @ =0x083459c4
    ldr r1, lbl_080739d8 @ =gDifficulty
    ldrb r1, [r1]
    mov sb, r1
    lsls r1, r1, #2
    adds r6, r1, r2
    ldrb r1, [r6]
    bl __divsi3
    eors r0, r4
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    mov r2, r8
    ldrb r4, [r2, #0x1d]
    ldrh r0, [r7, #2]
    ldrb r1, [r6, #1]
    bl __divsi3
    cmp r4, r0
    beq lbl_08073930
    movs r0, #2
    orrs r5, r0
lbl_08073930:
    ldrb r0, [r7, #4]
    ldrb r1, [r6, #2]
    bl __udivsi3
    mov r3, r8
    ldrb r1, [r3, #0x1e]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073948
    movs r0, #4
    orrs r5, r0
lbl_08073948:
    ldrb r0, [r7, #5]
    ldrb r1, [r6, #3]
    bl __udivsi3
    mov r2, r8
    ldrb r1, [r2, #0x1f]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073960
    movs r0, #8
    orrs r5, r0
lbl_08073960:
    movs r0, #0
    cmp r5, #0
    bne lbl_08073968
    movs r0, #6
lbl_08073968:
    adds r5, r0, #0
    ldr r0, lbl_080739dc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08073978
    adds r5, #3
lbl_08073978:
    add r5, sb
    ldr r1, lbl_080739e0 @ =gBestCompletionTimes
    lsls r0, r5, #2
    adds r4, r0, r1
    ldrb r0, [r4]
    lsls r2, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #5
    adds r2, r2, r0
    lsls r2, r2, #4
    ldrb r1, [r4, #1]
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrb r3, [r4, #2]
    adds r2, r2, r3
    ldr r5, lbl_080739e4 @ =gInGameTimer
    ldrb r0, [r5]
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #5
    adds r1, r1, r0
    lsls r1, r1, #4
    ldrb r3, [r5, #1]
    lsls r0, r3, #4
    subs r0, r0, r3
    lsls r0, r0, #2
    adds r1, r1, r0
    ldrb r0, [r5, #2]
    adds r1, r1, r0
    cmp r2, r1
    ble lbl_080739be
    ldr r0, [r5]
    str r0, [r4]
lbl_080739be:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080739cc: .4byte 0x083459a0
lbl_080739d0: .4byte gEquipment
lbl_080739d4: .4byte 0x083459c4
lbl_080739d8: .4byte gDifficulty
lbl_080739dc: .4byte gLanguage
lbl_080739e0: .4byte gBestCompletionTimes
lbl_080739e4: .4byte gInGameTimer

    thumb_func_start sub_080739e8
sub_080739e8: @ 0x080739e8
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073a74 @ =0x08754bc8
    ldr r3, lbl_08073a78 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073a7c @ =gGameCompletion
    ldrb r0, [r0]
    strb r0, [r4, #0x18]
    adds r6, r2, #0
    adds r5, r3, #0
    ldr r2, lbl_08073a80 @ =gBestCompletionTimes
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_08073a1e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a1e
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r1, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #4
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r1, #0x80
    ldr r0, [r6]
    adds r2, r0, r1
    movs r1, #0
    movs r3, #0x90
lbl_08073a40:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a40
    str r1, [r4, #0x10]
    mvns r0, r1
    str r0, [r4, #0x14]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073a74: .4byte 0x08754bc8
lbl_08073a78: .4byte gMostRecentSaveFile
lbl_08073a7c: .4byte gGameCompletion
lbl_08073a80: .4byte gBestCompletionTimes

    thumb_func_start sub_08073a84
sub_08073a84: @ 0x08073a84
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_08073aa0 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_08073a96
    b lbl_08073b94
lbl_08073a96:
    lsls r0, r1, #2
    ldr r1, lbl_08073aa4 @ =lbl_08073aa8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073aa0: .4byte gSramOperationStage
lbl_08073aa4: .4byte lbl_08073aa8
lbl_08073aa8: @ jump table
    .4byte lbl_08073ac0 @ case 0
    .4byte lbl_08073ad4 @ case 1
    .4byte lbl_08073ae0 @ case 2
    .4byte lbl_08073b1c @ case 3
    .4byte lbl_08073b4c @ case 4
    .4byte lbl_08073b94 @ case 5
lbl_08073ac0:
    ldr r1, lbl_08073ad0 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_08073b9a
    .align 2, 0
lbl_08073ad0: .4byte gUnk_3000c20
lbl_08073ad4:
    movs r0, #2
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073b9a
    b lbl_08073b7a
lbl_08073ae0:
    movs r2, #1
    ldr r0, lbl_08073b0c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073af0
    movs r2, #8
lbl_08073af0:
    ldr r1, lbl_08073b10 @ =gGameCompletion
    ldr r0, lbl_08073b14 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl sub_080739e8
    ldr r0, lbl_08073b18 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b0c: .4byte gLanguage
lbl_08073b10: .4byte gGameCompletion
lbl_08073b14: .4byte gDifficulty
lbl_08073b18: .4byte gUnk_3000c20
lbl_08073b1c:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073b9a
    ldr r2, lbl_08073b40 @ =gSaveFilesInfo
    ldr r0, lbl_08073b44 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073b48 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b40: .4byte gSaveFilesInfo
lbl_08073b44: .4byte gMostRecentSaveFile
lbl_08073b48: .4byte gGameCompletion
lbl_08073b4c:
    ldr r2, lbl_08073b84 @ =0x08754bc8
    ldr r0, lbl_08073b88 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073b8c @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_08073b7a:
    ldr r1, lbl_08073b90 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08073b9a
    .align 2, 0
lbl_08073b84: .4byte 0x08754bc8
lbl_08073b88: .4byte gMostRecentSaveFile
lbl_08073b8c: .4byte 0x000036e0
lbl_08073b90: .4byte gSramOperationStage
lbl_08073b94:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_08073b9a:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start SramSaveFile
SramSaveFile: @ 0x08073ba4
    push {lr}
    sub sp, #4
    ldr r1, lbl_08073bd4 @ =gDisableSoftreset
    ldrb r2, [r1]
    ldr r3, lbl_08073bd8 @ =gSramOperationStage
    cmp r2, #0
    bne lbl_08073bc0
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_08073bdc @ =gHasSaved
    strb r0, [r1]
    strb r2, [r3]
    ldr r0, lbl_08073be0 @ =gUnk_3000c20
    strb r2, [r0]
lbl_08073bc0:
    ldrb r0, [r3]
    cmp r0, #5
    bls lbl_08073bc8
    b lbl_08073ccc
lbl_08073bc8:
    lsls r0, r0, #2
    ldr r1, lbl_08073be4 @ =lbl_08073be8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073bd4: .4byte gDisableSoftreset
lbl_08073bd8: .4byte gSramOperationStage
lbl_08073bdc: .4byte gHasSaved
lbl_08073be0: .4byte gUnk_3000c20
lbl_08073be4: .4byte lbl_08073be8
lbl_08073be8: @ jump table
    .4byte lbl_08073c00 @ case 0
    .4byte lbl_08073c18 @ case 1
    .4byte lbl_08073c34 @ case 2
    .4byte lbl_08073c50 @ case 3
    .4byte lbl_08073c84 @ case 4
    .4byte lbl_08073ccc @ case 5
lbl_08073c00:
    movs r0, #4
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r1, lbl_08073c14 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c14: .4byte gSramOperationStage
lbl_08073c18:
    bl write_sram_arrays
    ldr r1, lbl_08073c2c @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c30 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c2c: .4byte gUnk_3000c20
lbl_08073c30: .4byte gSramOperationStage
lbl_08073c34:
    bl write_sram
    ldr r1, lbl_08073c48 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c4c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c48: .4byte gUnk_3000c20
lbl_08073c4c: .4byte gSramOperationStage
lbl_08073c50:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r2, lbl_08073c78 @ =gSaveFilesInfo
    ldr r0, lbl_08073c7c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_08073c80 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c78: .4byte gSaveFilesInfo
lbl_08073c7c: .4byte gMostRecentSaveFile
lbl_08073c80: .4byte gSramOperationStage
lbl_08073c84:
    ldr r2, lbl_08073cbc @ =0x08754bc8
    ldr r0, lbl_08073cc0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073cc4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, lbl_08073cc8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073cbc: .4byte 0x08754bc8
lbl_08073cc0: .4byte gMostRecentSaveFile
lbl_08073cc4: .4byte 0x000036e0
lbl_08073cc8: .4byte gSramOperationStage
lbl_08073ccc:
    ldr r1, lbl_08073ce0 @ =gDisableSoftreset
    movs r0, #0
lbl_08073cd0:
    strb r0, [r1]
lbl_08073cd2:
    ldr r0, lbl_08073ce0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r1}
    bx r1
    .align 2, 0
lbl_08073ce0: .4byte gDisableSoftreset

    thumb_func_start write_sram
write_sram: @ 0x08073ce4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r3, lbl_08073f80 @ =gMusicInfo
    ldrh r1, [r3, #0x1c]
    ldr r0, lbl_08073f84 @ =0xffff0000
    ands r0, r5
    orrs r0, r1
    ldrh r1, [r3, #0x1e]
    lsls r1, r1, #0x10
    ldr r2, lbl_08073f88 @ =0x0000ffff
    ands r0, r2
    adds r5, r0, #0
    orrs r5, r1
    adds r0, r3, #0
    adds r0, #0x20
    ldrb r1, [r0]
    ldr r0, lbl_08073f8c @ =0xffffff00
    ands r0, r6
    orrs r0, r1
    adds r3, #0x21
    ldrb r1, [r3]
    lsls r1, r1, #8
    ldr r2, lbl_08073f90 @ =0xffff00ff
    ands r0, r2
    adds r6, r0, #0
    orrs r6, r1
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08073f9c @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_08073fa0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073fa4 @ =gGameCompletion
    ldr r0, [r0]
    str r0, [r4, #0x18]
    ldr r0, lbl_08073fa8 @ =gHasSaved
    ldrb r0, [r0]
    strb r0, [r4, #0x1c]
    ldr r0, lbl_08073fac @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r4, #0x1d]
    ldr r0, lbl_08073fb0 @ =gCurrentRoom
    ldrb r0, [r0]
    strb r0, [r4, #0x1e]
    ldr r0, lbl_08073fb4 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #0x1f]
    ldr r0, lbl_08073fb8 @ =gMinimapX
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x20
    strb r1, [r0]
    ldr r0, lbl_08073fbc @ =gMinimapY
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x21
    strb r0, [r1]
    ldr r0, lbl_08073fc0 @ =gCamera
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r0, lbl_08073fc4 @ =gBg0XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2c]
    ldr r0, lbl_08073fc8 @ =gBg0YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2e]
    ldr r0, lbl_08073fcc @ =gBg1XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x30]
    ldr r0, lbl_08073fd0 @ =gBg1YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x32]
    ldr r0, lbl_08073fd4 @ =gBg2XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x34]
    ldr r0, lbl_08073fd8 @ =gBg2YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x36]
    ldr r0, lbl_08073fdc @ =gBg3XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x38]
    ldr r0, lbl_08073fe0 @ =gBg3YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x3a]
    ldr r0, lbl_08073fe4 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_08073fe8 @ =gUseMotherShipDoors
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3d
    strb r0, [r1]
    ldr r0, lbl_08073fec @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, #1
    strb r0, [r1]
    movs r3, #0
    adds r2, r4, #0
    adds r2, #0x3f
    ldr r7, lbl_08073ff0 @ =gNumberOfNeverReformBlocks
lbl_08073de4:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073de4
    movs r3, #0
    ldr r0, lbl_08073ff4 @ =gSamusData
    mov sl, r0
    movs r2, #0x60
    adds r2, r2, r4
    mov ip, r2
    movs r7, #0x80
    adds r7, r7, r4
    mov r8, r7
    movs r0, #0x88
    adds r0, r0, r4
    mov sb, r0
    adds r2, r4, #0
    adds r2, #0x47
    ldr r7, lbl_08073ff8 @ =gNumberOfItemsCollected
lbl_08073e10:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073e10
    mov r1, ip
    mov r0, sl
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r7, lbl_08073ffc @ =gSamusWeaponInfo
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r2, r8
    str r0, [r2]
    str r1, [r2, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sb
    ldr r1, lbl_08074000 @ =gSamusEcho
    bl memcpy
    movs r3, #0xca
    lsls r3, r3, #1
    adds r2, r4, r3
    ldr r0, lbl_08074004 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r7, #0xce
    lsls r7, r7, #1
    adds r1, r4, r7
    ldr r0, lbl_08074008 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    movs r7, #0xd8
    lsls r7, r7, #1
    adds r2, r4, r7
    ldr r0, lbl_0807400c @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r0, #0xdc
    lsls r0, r0, #1
    adds r1, r4, r0
    ldr r0, lbl_08074010 @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xe2
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r3, #0xe8
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r7, #0xee
    lsls r7, r7, #1
    adds r1, r4, r7
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xf4
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldr r0, lbl_08074014 @ =gPreventMovementTimer
    ldrh r1, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r4, r3
    strh r1, [r0]
    ldr r0, lbl_08074018 @ =gDisableDrawingSamusAndScrolling
    ldrb r0, [r0]
    movs r7, #0xfb
    lsls r7, r7, #1
    adds r1, r4, r7
    strb r0, [r1]
    ldr r0, lbl_0807401c @ =gAlarmTimer
    ldrh r1, [r0]
    movs r2, #0xfc
    lsls r2, r2, #1
    adds r0, r4, r2
    strh r1, [r0]
    adds r3, #8
    adds r1, r4, r3
    ldr r0, lbl_08074020 @ =gInGameTimer
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, lbl_08074024 @ =gBestCompletionTimes
    adds r7, #0xa
    adds r1, r4, r7
    movs r3, #0xb
lbl_08073ee0:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ee0
    ldr r1, lbl_08074028 @ =0x08411430
    ldr r7, lbl_0807402c @ =gInGameTimerAtBosses
    movs r0, #0x8c
    lsls r0, r0, #2
    adds r2, r4, r0
    movs r3, #4
lbl_08073ef6:
    ldm r7!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ef6
    movs r2, #0x91
    lsls r2, r2, #2
    adds r0, r4, r2
    str r5, [r0]
    str r6, [r0, #4]
    ldr r5, lbl_08074030 @ =gInGameCutscenesTriggered
    movs r3, #0x93
    lsls r3, r3, #2
    adds r2, r4, r3
    movs r3, #0
lbl_08073f14:
    ldm r5!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f14
    movs r7, #0x94
    lsls r7, r7, #2
    adds r0, r4, r7
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073f46:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f46
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073f80: .4byte gMusicInfo
lbl_08073f84: .4byte 0xffff0000
lbl_08073f88: .4byte 0x0000ffff
lbl_08073f8c: .4byte 0xffffff00
lbl_08073f90: .4byte 0xffff00ff
lbl_08073f94: .4byte 0x08754bc8
lbl_08073f98: .4byte gMostRecentSaveFile
lbl_08073f9c: .4byte 0x08411410
lbl_08073fa0: .4byte 0x08411420
lbl_08073fa4: .4byte gGameCompletion
lbl_08073fa8: .4byte gHasSaved
lbl_08073fac: .4byte gCurrentArea
lbl_08073fb0: .4byte gCurrentRoom
lbl_08073fb4: .4byte gLastDoorUsed
lbl_08073fb8: .4byte gMinimapX
lbl_08073fbc: .4byte gMinimapY
lbl_08073fc0: .4byte gCamera
lbl_08073fc4: .4byte gBg0XPosition
lbl_08073fc8: .4byte gBg0YPosition
lbl_08073fcc: .4byte gBg1XPosition
lbl_08073fd0: .4byte gBg1YPosition
lbl_08073fd4: .4byte gBg2XPosition
lbl_08073fd8: .4byte gBg2YPosition
lbl_08073fdc: .4byte gBg3XPosition
lbl_08073fe0: .4byte gBg3YPosition
lbl_08073fe4: .4byte gDifficulty
lbl_08073fe8: .4byte gUseMotherShipDoors
lbl_08073fec: .4byte gTimeAttackFlag
lbl_08073ff0: .4byte gNumberOfNeverReformBlocks
lbl_08073ff4: .4byte gSamusData
lbl_08073ff8: .4byte gNumberOfItemsCollected
lbl_08073ffc: .4byte gSamusWeaponInfo
lbl_08074000: .4byte gSamusEcho
lbl_08074004: .4byte gScrewSpeedAnimation
lbl_08074008: .4byte gEquipment
lbl_0807400c: .4byte gSamusHazardDamage
lbl_08074010: .4byte gSamusEnvironmentalEffects
lbl_08074014: .4byte gPreventMovementTimer
lbl_08074018: .4byte gDisableDrawingSamusAndScrolling
lbl_0807401c: .4byte gAlarmTimer
lbl_08074020: .4byte gInGameTimer
lbl_08074024: .4byte gBestCompletionTimes
lbl_08074028: .4byte 0x08411430
lbl_0807402c: .4byte gInGameTimerAtBosses
lbl_08074030: .4byte gInGameCutscenesTriggered

    thumb_func_start load_sram_data
load_sram_data: @ 0x08074034
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r2, lbl_08074248 @ =0x08754bc8
    ldr r0, lbl_0807424c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08074250 @ =gGameCompletion
    ldr r0, [r4, #0x18]
    str r0, [r1]
    ldr r1, lbl_08074254 @ =gHasSaved
    ldrb r0, [r4, #0x1c]
    strb r0, [r1]
    ldr r1, lbl_08074258 @ =gCurrentArea
    ldrb r0, [r4, #0x1d]
    strb r0, [r1]
    ldr r1, lbl_0807425c @ =gCurrentRoom
    ldrb r0, [r4, #0x1e]
    strb r0, [r1]
    ldr r1, lbl_08074260 @ =gLastDoorUsed
    ldrb r0, [r4, #0x1f]
    strb r0, [r1]
    ldr r1, lbl_08074264 @ =gMinimapX
    adds r0, r4, #0
    adds r0, #0x20
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074268 @ =gMinimapY
    adds r0, r4, #0
    adds r0, #0x21
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r2, lbl_0807426c @ =gCamera
    ldr r0, [r4, #0x24]
    ldr r1, [r4, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08074270 @ =gBg0XPosition
    ldrh r0, [r4, #0x2c]
    strh r0, [r1]
    ldr r1, lbl_08074274 @ =gBg0YPosition
    ldrh r0, [r4, #0x2e]
    strh r0, [r1]
    ldr r1, lbl_08074278 @ =gBg1XPosition
    ldrh r0, [r4, #0x30]
    strh r0, [r1]
    ldr r1, lbl_0807427c @ =gBg1YPosition
    ldrh r0, [r4, #0x32]
    strh r0, [r1]
    ldr r1, lbl_08074280 @ =gBg2XPosition
    ldrh r0, [r4, #0x34]
    strh r0, [r1]
    ldr r1, lbl_08074284 @ =gBg2YPosition
    ldrh r0, [r4, #0x36]
    strh r0, [r1]
    ldr r1, lbl_08074288 @ =gBg3XPosition
    ldrh r0, [r4, #0x38]
    strh r0, [r1]
    ldr r1, lbl_0807428c @ =gBg3YPosition
    ldrh r0, [r4, #0x3a]
    strh r0, [r1]
    ldr r1, lbl_08074290 @ =gDifficulty
    adds r0, r4, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074294 @ =gUseMotherShipDoors
    adds r0, r4, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074298 @ =gTimeAttackFlag
    adds r0, r4, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    strb r0, [r1]
    movs r2, #0
    ldr r0, lbl_0807429c @ =gSamusData
    mov r8, r0
    ldr r1, lbl_080742a0 @ =gSamusWeaponInfo
    mov sb, r1
    ldr r3, lbl_080742a4 @ =gSamusEcho
    mov sl, r3
    ldr r5, lbl_080742a8 @ =gNumberOfNeverReformBlocks
    adds r3, r4, #0
    adds r3, #0x3f
lbl_080740f4:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_080740f4
    movs r2, #0
    adds r6, r4, #0
    adds r6, #0x60
    adds r7, r4, #0
    adds r7, #0x80
    movs r5, #0x88
    adds r5, r5, r4
    mov ip, r5
    ldr r5, lbl_080742ac @ =gNumberOfItemsCollected
    adds r3, r4, #0
    adds r3, #0x47
lbl_08074118:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_08074118
    mov r1, r8
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r5, sb
    str r0, [r5]
    str r1, [r5, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sl
    mov r1, ip
    bl memcpy
    ldr r2, lbl_080742b0 @ =gScrewSpeedAnimation
    movs r1, #0xca
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_080742b4 @ =gEquipment
    movs r2, #0xce
    lsls r2, r2, #1
    adds r0, r4, r2
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    ldr r2, lbl_080742b8 @ =gSamusHazardDamage
    movs r1, #0xd8
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_080742bc @ =gSamusEnvironmentalEffects
    movs r2, #0xdc
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xe2
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r5, #0xe8
    lsls r5, r5, #1
    adds r1, r4, r5
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r2, #0xee
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xf4
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, lbl_080742c0 @ =gPreventMovementTimer
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r4, r5
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742c4 @ =gDisableDrawingSamusAndScrolling
    movs r2, #0xfb
    lsls r2, r2, #1
    adds r0, r4, r2
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_080742c8 @ =gAlarmTimer
    movs r3, #0xfc
    lsls r3, r3, #1
    adds r0, r4, r3
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742cc @ =gInGameTimer
    adds r5, #8
    adds r0, r4, r5
    ldr r0, [r0]
    str r0, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742d0 @ =gBestCompletionTimes
    movs r2, #0xb
lbl_080741e8:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741e8
    ldr r7, lbl_080742d4 @ =gMusicInfo
    movs r2, #0x8c
    lsls r2, r2, #2
    adds r1, r4, r2
    ldr r3, lbl_080742d8 @ =gInGameTimerAtBosses
    movs r2, #4
lbl_080741fe:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741fe
    movs r3, #0x91
    lsls r3, r3, #2
    adds r0, r4, r3
    ldr r5, [r0]
    ldr r6, [r0, #4]
    movs r0, #0x93
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742dc @ =gInGameCutscenesTriggered
    movs r2, #0
lbl_0807421c:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_0807421c
    strh r5, [r7, #0x1c]
    lsrs r0, r5, #0x10
    strh r0, [r7, #0x1e]
    adds r0, r7, #0
    adds r0, #0x20
    strb r6, [r0]
    lsrs r1, r6, #8
    adds r0, #1
    strb r1, [r0]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074248: .4byte 0x08754bc8
lbl_0807424c: .4byte gMostRecentSaveFile
lbl_08074250: .4byte gGameCompletion
lbl_08074254: .4byte gHasSaved
lbl_08074258: .4byte gCurrentArea
lbl_0807425c: .4byte gCurrentRoom
lbl_08074260: .4byte gLastDoorUsed
lbl_08074264: .4byte gMinimapX
lbl_08074268: .4byte gMinimapY
lbl_0807426c: .4byte gCamera
lbl_08074270: .4byte gBg0XPosition
lbl_08074274: .4byte gBg0YPosition
lbl_08074278: .4byte gBg1XPosition
lbl_0807427c: .4byte gBg1YPosition
lbl_08074280: .4byte gBg2XPosition
lbl_08074284: .4byte gBg2YPosition
lbl_08074288: .4byte gBg3XPosition
lbl_0807428c: .4byte gBg3YPosition
lbl_08074290: .4byte gDifficulty
lbl_08074294: .4byte gUseMotherShipDoors
lbl_08074298: .4byte gTimeAttackFlag
lbl_0807429c: .4byte gSamusData
lbl_080742a0: .4byte gSamusWeaponInfo
lbl_080742a4: .4byte gSamusEcho
lbl_080742a8: .4byte gNumberOfNeverReformBlocks
lbl_080742ac: .4byte gNumberOfItemsCollected
lbl_080742b0: .4byte gScrewSpeedAnimation
lbl_080742b4: .4byte gEquipment
lbl_080742b8: .4byte gSamusHazardDamage
lbl_080742bc: .4byte gSamusEnvironmentalEffects
lbl_080742c0: .4byte gPreventMovementTimer
lbl_080742c4: .4byte gDisableDrawingSamusAndScrolling
lbl_080742c8: .4byte gAlarmTimer
lbl_080742cc: .4byte gInGameTimer
lbl_080742d0: .4byte gBestCompletionTimes
lbl_080742d4: .4byte gMusicInfo
lbl_080742d8: .4byte gInGameTimerAtBosses
lbl_080742dc: .4byte gInGameCutscenesTriggered

    thumb_func_start write_string
write_string: @ 0x080742e0
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r3, #0
    cmp r3, r2
    bge lbl_080742fe
lbl_080742f0:
    adds r0, r5, r3
    adds r1, r4, r3
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, r2
    blt lbl_080742f0
lbl_080742fe:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08074304
sub_08074304: @ 0x08074304
    push {r4, r5, lr}
    sub sp, #0x10
    movs r5, #0
    ldr r0, lbl_08074364 @ =gSramCorruptFlag
    strb r5, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    ldr r4, lbl_0807436c @ =0x0e007f80
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
lbl_0807432c:
    mov r0, sp
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r2, #1
    cmp r2, #0xf
    ble lbl_0807432c
    ldr r4, lbl_0807436c @ =0x0e007f80
    mov r0, sp
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    cmp r0, #0
    beq lbl_08074350
    movs r0, #2
    orrs r5, r0
lbl_08074350:
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
    mov r0, sp
    ldrb r1, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    b lbl_08074380
    .align 2, 0
lbl_08074364: .4byte gSramCorruptFlag
lbl_08074368: .4byte 0x08411400
lbl_0807436c: .4byte 0x0e007f80
lbl_08074370:
    adds r2, #1
    cmp r2, #0xf
    bgt lbl_0807438c
    mov r1, sp
    adds r0, r1, r2
    ldrb r1, [r0]
    ldr r0, lbl_0807439c @ =0x08411400
    adds r0, r2, r0
lbl_08074380:
    ldrb r0, [r0]
    adds r0, #1
    cmp r1, r0
    beq lbl_08074370
    movs r0, #4
    orrs r5, r0
lbl_0807438c:
    cmp r5, #0
    beq lbl_08074394
    ldr r0, lbl_080743a0 @ =gSramCorruptFlag
    strb r5, [r0]
lbl_08074394:
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807439c: .4byte 0x08411400
lbl_080743a0: .4byte gSramCorruptFlag

    thumb_func_start sub_080743a4
sub_080743a4: @ 0x080743a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08074440 @ =gMostRecentSaveFile
    mov r8, r0
    ldr r1, lbl_08074444 @ =gIsLoadingFile
    mov sb, r1
    ldr r3, lbl_08074448 @ =0x08760408
    ldr r2, lbl_0807444c @ =gSaveFilesInfo
    movs r5, #2
lbl_080743be:
    adds r1, r2, #0
    adds r0, r3, #0
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    adds r2, #0x18
    subs r5, #1
    cmp r5, #0
    bge lbl_080743be
    movs r0, #0
    mov r1, r8
    strb r0, [r1]
    mov r2, sb
    strb r0, [r2]
    movs r5, #0
    ldr r7, lbl_08074450 @ =0x08754bc8
    movs r6, #0x10
    ldr r3, lbl_0807444c @ =gSaveFilesInfo
    str r3, [sp, #4]
    ldr r4, lbl_08074454 @ =0x0000ffff
    mov sl, r4
    movs r0, #0x91
    lsls r0, r0, #5
    mov sb, r0
lbl_080743f0:
    mov r1, r8
    strb r5, [r1]
    bl sub_08074574
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r3, lbl_0807444c @ =gSaveFilesInfo
    adds r0, r0, r3
    ldrb r4, [r0, #1]
    cmp r4, #0
    bne lbl_0807445c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r7]
    adds r1, r2, r1
    ldr r4, lbl_08074458 @ =0x000036e0
    adds r0, r0, r4
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DmaTransfer
    movs r0, #4
    bl DoSramOperation
    movs r0, #1
    ldr r1, [sp, #4]
    strb r0, [r1]
    b lbl_0807454a
    .align 2, 0
lbl_08074440: .4byte gMostRecentSaveFile
lbl_08074444: .4byte gIsLoadingFile
lbl_08074448: .4byte 0x08760408
lbl_0807444c: .4byte gSaveFilesInfo
lbl_08074450: .4byte 0x08754bc8
lbl_08074454: .4byte 0x0000ffff
lbl_08074458: .4byte 0x000036e0
lbl_0807445c:
    cmp r4, #1
    bne lbl_0807448c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r2, lbl_08074488 @ =0x000036e0
    adds r1, r0, r2
    ldr r2, [r7]
    adds r1, r2, r1
    adds r0, #0x80
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DmaTransfer
    ldr r3, [sp, #4]
    strb r4, [r3]
    b lbl_0807454a
    .align 2, 0
lbl_08074488: .4byte 0x000036e0
lbl_0807448c:
    cmp r4, #2
    bne lbl_080744d8
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080744d4 @ =0x000036e0
    adds r0, r0, r1
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    b lbl_0807454a
    .align 2, 0
lbl_080744d4: .4byte 0x000036e0
lbl_080744d8:
    cmp r4, #2
    bls lbl_08074548
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #3
    bl DoSramOperation
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r3, lbl_08074540 @ =0x000036e0
    adds r0, r0, r3
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #4
    bl DoSramOperation
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r1, lbl_08074544 @ =gSaveFilesInfo
    adds r0, r0, r1
    movs r1, #0
    strb r1, [r0, #1]
    b lbl_0807454a
    .align 2, 0
lbl_08074540: .4byte 0x000036e0
lbl_08074544: .4byte gSaveFilesInfo
lbl_08074548:
    b lbl_08074548
lbl_0807454a:
    ldr r2, [sp, #4]
    adds r2, #0x18
    str r2, [sp, #4]
    adds r5, #1
    cmp r5, #2
    bgt lbl_08074558
    b lbl_080743f0
lbl_08074558:
    movs r1, #0
    ldr r0, lbl_08074570 @ =gMostRecentSaveFile
    strb r1, [r0]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074570: .4byte gMostRecentSaveFile

    thumb_func_start sub_08074574
sub_08074574: @ 0x08074574
    push {r4, r5, lr}
    movs r0, #0
    bl sub_08074624
    adds r4, r0, #0
    movs r0, #1
    bl sub_08074624
    adds r2, r0, #0
    cmp r4, #0
    bne lbl_080745a8
    ldr r2, lbl_080745a0 @ =gSaveFilesInfo
    ldr r0, lbl_080745a4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    strb r4, [r0, #1]
    b lbl_0807461c
    .align 2, 0
lbl_080745a0: .4byte gSaveFilesInfo
lbl_080745a4: .4byte gMostRecentSaveFile
lbl_080745a8:
    cmp r4, #1
    bne lbl_080745d8
    ldr r5, lbl_080745d0 @ =gSaveFilesInfo
    ldr r3, lbl_080745d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r5
    strb r4, [r0, #1]
    cmp r2, #0
    beq lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r5
    b lbl_08074618
    .align 2, 0
lbl_080745d0: .4byte gSaveFilesInfo
lbl_080745d4: .4byte gMostRecentSaveFile
lbl_080745d8:
    ldr r4, lbl_08074600 @ =gSaveFilesInfo
    ldr r3, lbl_08074604 @ =gMostRecentSaveFile
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #3
    strb r0, [r1, #1]
    cmp r2, #0
    bne lbl_08074608
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #1
    b lbl_0807461a
    .align 2, 0
lbl_08074600: .4byte gSaveFilesInfo
lbl_08074604: .4byte gMostRecentSaveFile
lbl_08074608:
    cmp r2, #1
    bne lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
lbl_08074618:
    movs r0, #2
lbl_0807461a:
    strb r0, [r1, #1]
lbl_0807461c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08074624
sub_08074624: @ 0x08074624
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08074654
    ldr r2, lbl_0807464c @ =0x08754bc8
    ldr r0, lbl_08074650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    b lbl_0807466a
    .align 2, 0
lbl_0807464c: .4byte 0x08754bc8
lbl_08074650: .4byte gMostRecentSaveFile
lbl_08074654:
    ldr r2, lbl_080746d8 @ =0x08754bc8
    ldr r0, lbl_080746dc @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080746e0 @ =0x000036e0
    adds r0, r0, r1
lbl_0807466a:
    ldr r1, [r2]
    adds r4, r1, r0
    adds r1, r4, #0
    movs r2, #0
    ldr r6, [r4, #0x10]
    mov ip, r6
    ldr r7, lbl_080746e4 @ =0x08411410
    ldrb r0, [r4]
    mov sb, r0
    ldr r6, lbl_080746e8 @ =0x08411420
    mov r8, r6
    adds r6, r4, #0
    adds r6, #0x4f
    ldr r0, lbl_080746ec @ =0x08411430
    mov sl, r0
    movs r0, #0x94
    lsls r0, r0, #2
    adds r0, r4, r0
    str r0, [sp, #4]
    movs r3, #0x90
lbl_08074692:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08074692
    movs r5, #0
    cmp ip, r2
    bne lbl_080746c6
    ldr r0, [r4, #0x14]
    mvns r0, r0
    cmp r2, r0
    beq lbl_080746c8
lbl_080746c6:
    movs r5, #1
lbl_080746c8:
    movs r2, #0
    movs r3, #0
    ldrb r0, [r7]
    cmp r0, sb
    beq lbl_080746f0
    movs r2, #1
    b lbl_08074706
    .align 2, 0
lbl_080746d8: .4byte 0x08754bc8
lbl_080746dc: .4byte gMostRecentSaveFile
lbl_080746e0: .4byte 0x000036e0
lbl_080746e4: .4byte 0x08411410
lbl_080746e8: .4byte 0x08411420
lbl_080746ec: .4byte 0x08411430
lbl_080746f0:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074706
    adds r0, r3, r7
    adds r1, r4, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080746f0
    movs r0, #1
    orrs r2, r0
lbl_08074706:
    movs r3, #0
    mov r1, r8
    ldrb r0, [r1]
    ldrb r1, [r6]
    b lbl_08074720
lbl_08074710:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074728
    mov r1, r8
    adds r0, r3, r1
    adds r1, r6, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
lbl_08074720:
    cmp r0, r1
    beq lbl_08074710
    movs r0, #2
    orrs r2, r0
lbl_08074728:
    movs r3, #0
    mov r6, sl
    ldrb r0, [r6]
    ldr r1, [sp, #4]
    b lbl_08074746
lbl_08074732:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074750
    mov r6, sl
    adds r0, r3, r6
    movs r6, #0x94
    lsls r6, r6, #2
    adds r1, r4, r6
    adds r1, r1, r3
    ldrb r0, [r0]
lbl_08074746:
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074732
    movs r0, #4
    orrs r2, r0
lbl_08074750:
    cmp r2, #0
    beq lbl_08074760
    cmp r2, #7
    bne lbl_0807475c
    movs r0, #2
    b lbl_0807475e
lbl_0807475c:
    movs r0, #1
lbl_0807475e:
    orrs r5, r0
lbl_08074760:
    cmp r5, #1
    ble lbl_08074776
    ldr r1, lbl_08074788 @ =0x0000ffff
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
lbl_08074776:
    adds r0, r5, #0
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074788: .4byte 0x0000ffff

    thumb_func_start sub_0807478c
sub_0807478c: @ 0x0807478c
    push {lr}
    ldr r0, lbl_080747a8 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_080747a2
    bl load_sram_data
    bl load_sram_arrays
lbl_080747a2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080747a8: .4byte gIsLoadingFile

    thumb_func_start sub_080747ac
sub_080747ac: @ 0x080747ac
    push {lr}
    bl load_sram_data
    bl load_sram_arrays
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start write_sram_arrays
write_sram_arrays: @ 0x080747bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_08074898 @ =0x08754bc8
    ldr r0, lbl_0807489c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r1, lbl_080748a0 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r2, r8
    bl DmaTransfer
    ldr r1, lbl_080748a4 @ =0x02037c00
    movs r0, #0x88
    lsls r0, r0, #5
    adds r2, r4, r0
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, lbl_080748a8 @ =0x02037e00
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    str r5, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0x20
    bl DmaTransfer
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748ac @ =0x02035c00
lbl_08074824:
    ldr r0, lbl_080748b0 @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08074848
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DmaTransfer
    adds r6, r6, r4
lbl_08074848:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074824
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748b4 @ =0x02036c00
lbl_0807485a:
    ldr r0, lbl_080748b8 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_0807487e
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DmaTransfer
    adds r6, r6, r4
lbl_0807487e:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807485a
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074898: .4byte 0x08754bc8
lbl_0807489c: .4byte gMostRecentSaveFile
lbl_080748a0: .4byte 0x02037400
lbl_080748a4: .4byte 0x02037c00
lbl_080748a8: .4byte 0x02037e00
lbl_080748ac: .4byte 0x02035c00
lbl_080748b0: .4byte gNumberOfNeverReformBlocks
lbl_080748b4: .4byte 0x02036c00
lbl_080748b8: .4byte gNumberOfItemsCollected

    thumb_func_start load_sram_arrays
load_sram_arrays: @ 0x080748bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_080749bc @ =0x08754bc8
    ldr r0, lbl_080749c0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r2, lbl_080749c4 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r1, r8
    bl DmaTransfer
    movs r0, #0x88
    lsls r0, r0, #5
    adds r1, r4, r0
    ldr r2, lbl_080749c8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DmaTransfer
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    ldr r2, lbl_080749cc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    movs r3, #0x20
    bl DmaTransfer
    ldr r4, lbl_080749d0 @ =0x0000ffff
    ldr r6, lbl_080749d4 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r2, r6, #0
    bl BitFill
    ldr r2, lbl_080749d8 @ =0x02036c00
    movs r3, #0x80
    lsls r3, r3, #4
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    movs r7, #0
    movs r5, #0
lbl_08074946:
    ldr r0, lbl_080749dc @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807496a
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DmaTransfer
    adds r7, r7, r4
lbl_0807496a:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074946
    movs r7, #0
    movs r5, #0
    ldr r6, lbl_080749d8 @ =0x02036c00
lbl_0807497c:
    ldr r0, lbl_080749e0 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_080749a0
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DmaTransfer
    adds r7, r7, r4
lbl_080749a0:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807497c
    bl load_minimap_tiles_with_obtained_items
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080749bc: .4byte 0x08754bc8
lbl_080749c0: .4byte gMostRecentSaveFile
lbl_080749c4: .4byte 0x02037400
lbl_080749c8: .4byte 0x02037c00
lbl_080749cc: .4byte 0x02037e00
lbl_080749d0: .4byte 0x0000ffff
lbl_080749d4: .4byte 0x02035c00
lbl_080749d8: .4byte 0x02036c00
lbl_080749dc: .4byte gNumberOfNeverReformBlocks
lbl_080749e0: .4byte gNumberOfItemsCollected

    thumb_func_start SramWrite_MostRecentSaveFile
SramWrite_MostRecentSaveFile: @ 0x080749e4
    push {r4, r5, lr}
    ldr r0, lbl_08074a68 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdb
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1e
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074a6c @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074a70 @ =gMostRecentSaveFile
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074a74 @ =0x08411488
    ldr r0, lbl_08074a78 @ =0x00006d86
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074a12:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a12
    movs r1, #0
    movs r4, #7
lbl_08074a28:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a28
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #5
    bl DoSramOperation
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074a68: .4byte 0x08754bc8
lbl_08074a6c: .4byte 0x0000ffff
lbl_08074a70: .4byte gMostRecentSaveFile
lbl_08074a74: .4byte 0x08411488
lbl_08074a78: .4byte 0x00006d86

    thumb_func_start sub_08074a7c
sub_08074a7c: @ 0x08074a7c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074b28 @ =0x08754bc8
    ldr r0, [r2]
    movs r1, #0xdb
    lsls r1, r1, #7
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1e
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074b2c @ =gMostRecentSaveFile
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074aa8:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074aa8
    cmp r5, r2
    beq lbl_08074adc
    movs r4, #2
lbl_08074adc:
    cmp r4, #0
    bne lbl_08074b34
    movs r3, #0
    ldr r0, lbl_08074b30 @ =0x08411488
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074b34
lbl_08074af0:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074b34
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074b1c
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074af0
    movs r4, #3
lbl_08074b1c:
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074b54
    .align 2, 0
lbl_08074b28: .4byte 0x08754bc8
lbl_08074b2c: .4byte gMostRecentSaveFile
lbl_08074b30: .4byte 0x08411488
lbl_08074b34:
    mov r1, sp
    ldr r2, lbl_08074b60 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074b64 @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    movs r2, #0xdb
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074b68 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074b54:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074b60: .4byte 0x0000ffff
lbl_08074b64: .4byte 0x040000d4
lbl_08074b68: .4byte 0x81000020

    thumb_func_start sub_08074b6c
sub_08074b6c: @ 0x08074b6c
    push {r4, r5, lr}
    ldr r0, lbl_08074bf0 @ =0x08754bc8
    ldr r2, [r0]
    ldr r0, lbl_08074bf4 @ =0x00006e40
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074bf8 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074bfc @ =gStereoFlag
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074c00 @ =0x084114a8
    ldr r0, lbl_08074c04 @ =0x00006e46
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074b98:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074b98
    movs r1, #0
    movs r4, #7
lbl_08074bae:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074bae
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #8
    bl DoSramOperation
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074bf0: .4byte 0x08754bc8
lbl_08074bf4: .4byte 0x00006e40
lbl_08074bf8: .4byte 0x0000ffff
lbl_08074bfc: .4byte gStereoFlag
lbl_08074c00: .4byte 0x084114a8
lbl_08074c04: .4byte 0x00006e46

    thumb_func_start sub_08074c08
sub_08074c08: @ 0x08074c08
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074cb0 @ =0x08754bc8
    ldr r0, [r2]
    ldr r1, lbl_08074cb4 @ =0x00006e40
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074cb8 @ =gStereoFlag
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074c32:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074c32
    cmp r5, r2
    beq lbl_08074c66
    movs r4, #2
lbl_08074c66:
    cmp r4, #0
    bne lbl_08074cc0
    movs r3, #0
    ldr r0, lbl_08074cbc @ =0x084114a8
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074cc0
lbl_08074c7a:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074cc0
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074ca6
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074c7a
    movs r4, #3
lbl_08074ca6:
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074cde
    .align 2, 0
lbl_08074cb0: .4byte 0x08754bc8
lbl_08074cb4: .4byte 0x00006e40
lbl_08074cb8: .4byte gStereoFlag
lbl_08074cbc: .4byte 0x084114a8
lbl_08074cc0:
    mov r1, sp
    ldr r2, lbl_08074ce8 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074cec @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    ldr r2, lbl_08074cf0 @ =0x00006e40
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074cf4 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074cde:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ce8: .4byte 0x0000ffff
lbl_08074cec: .4byte 0x040000d4
lbl_08074cf0: .4byte 0x00006e40
lbl_08074cf4: .4byte 0x81000020

    thumb_func_start SramWrite_Language
SramWrite_Language: @ 0x08074cf8
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074d88 @ =0x08754bc8
    ldr r4, [r0]
    ldr r0, lbl_08074d8c @ =0x00006dc0
    adds r5, r4, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074d90 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074d94 @ =gLanguage
    movs r2, #0
    ldrsb r2, [r0, r2]
    cmp r2, #6
    bls lbl_08074d22
    movs r2, #2
lbl_08074d22:
    strb r2, [r5, #0x16]
    movs r2, #0
    ldr r1, lbl_08074d98 @ =0x00006dc6
    adds r7, r4, r1
    ldr r0, lbl_08074d9c @ =0x00006dd7
    adds r6, r4, r0
    ldr r4, lbl_08074da0 @ =0x084114c8
lbl_08074d30:
    adds r1, r7, r2
    ldrb r0, [r4]
    strb r0, [r1]
    adds r1, r6, r2
    ldrb r0, [r4, #0x10]
    strb r0, [r1]
    adds r4, #1
    adds r2, #1
    cmp r2, #0xf
    ble lbl_08074d30
    movs r1, #0
    movs r2, #7
lbl_08074d48:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bge lbl_08074d48
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #6
    bl DoSramOperation
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074d88: .4byte 0x08754bc8
lbl_08074d8c: .4byte 0x00006dc0
lbl_08074d90: .4byte 0x0000ffff
lbl_08074d94: .4byte gLanguage
lbl_08074d98: .4byte 0x00006dc6
lbl_08074d9c: .4byte 0x00006dd7
lbl_08074da0: .4byte 0x084114c8

    thumb_func_start sub_08074da4
sub_08074da4: @ 0x08074da4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08074e2c @ =0x08754bc8
    mov sb, r1
    ldr r6, lbl_08074e30 @ =0x040000d4
    ldr r2, lbl_08074e34 @ =0x81000020
    mov sl, r2
lbl_08074dbe:
    mov r1, r8
    lsls r0, r1, #6
    ldr r2, lbl_08074e38 @ =0x00006dc0
    adds r0, r0, r2
    mov r2, sb
    ldr r1, [r2]
    adds r5, r1, r0
    adds r2, r5, #0
    ldrb r1, [r5]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    cmp r4, #0
    bne lbl_08074e6e
    movs r1, #0
    ldrh r7, [r5, #2]
    movs r3, #7
lbl_08074de4:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074de4
    cmp r7, r1
    beq lbl_08074e18
    movs r4, #2
lbl_08074e18:
    cmp r4, #0
    bne lbl_08074e6e
    movs r3, #0
    ldr r0, lbl_08074e3c @ =0x084114c8
    ldrb r1, [r5, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    beq lbl_08074e44
    b lbl_08074e6c
    .align 2, 0
lbl_08074e2c: .4byte 0x08754bc8
lbl_08074e30: .4byte 0x040000d4
lbl_08074e34: .4byte 0x81000020
lbl_08074e38: .4byte 0x00006dc0
lbl_08074e3c: .4byte 0x084114c8
lbl_08074e40:
    movs r4, #4
    b lbl_08074e6e
lbl_08074e44:
    adds r0, r5, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074e40
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074e6e
    adds r0, r5, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074e44
lbl_08074e6c:
    movs r4, #3
lbl_08074e6e:
    mov r1, r8
    cmp r1, #0
    bne lbl_08074ea0
    cmp r4, #0
    bne lbl_08074ee2
    mov r2, sb
    ldr r1, [r2]
    ldr r2, lbl_08074e98 @ =0x00006dc0
    adds r0, r1, r2
    str r0, [r6]
    movs r0, #0xdc
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r6, #4]
    ldr r0, lbl_08074e9c @ =0x80000020
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl DoSramOperation
    b lbl_08074eee
    .align 2, 0
lbl_08074e98: .4byte 0x00006dc0
lbl_08074e9c: .4byte 0x80000020
lbl_08074ea0:
    cmp r4, #0
    beq lbl_08074f04
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, lbl_08074efc @ =0x00006dc0
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #6
    bl DoSramOperation
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    movs r1, #0xdc
    lsls r1, r1, #7
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl DoSramOperation
lbl_08074ee2:
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #1
    bgt lbl_08074eee
    b lbl_08074dbe
lbl_08074eee:
    cmp r4, #0
    beq lbl_08074f3c
    ldr r1, lbl_08074f00 @ =gLanguage
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    b lbl_08074f44
    .align 2, 0
lbl_08074efc: .4byte 0x00006dc0
lbl_08074f00: .4byte gLanguage
lbl_08074f04:
    ldr r1, lbl_08074f2c @ =0x040000d4
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    movs r2, #0xdc
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    ldr r2, lbl_08074f34 @ =0x00006dc0
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074f38 @ =0x80000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #6
    bl DoSramOperation
    b lbl_08074eee
    .align 2, 0
lbl_08074f2c: .4byte 0x040000d4
lbl_08074f30: .4byte 0x08754bc8
lbl_08074f34: .4byte 0x00006dc0
lbl_08074f38: .4byte 0x80000020
lbl_08074f3c:
    ldr r1, lbl_08074f54 @ =gLanguage
    ldrb r0, [r5, #0x16]
    strb r0, [r1]
    movs r0, #0
lbl_08074f44:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074f54: .4byte gLanguage

    thumb_func_start SramWrite_TimeAttack
SramWrite_TimeAttack: @ 0x08074f58
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074ff4 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdd
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x40
    strb r0, [r5]
    ldrb r0, [r5, #0x16]
    adds r0, #1
    strb r0, [r5, #0x16]
    strh r1, [r5, #0x12]
    ldr r0, lbl_08074ff8 @ =0x0000ffff
    strh r0, [r5, #0x14]
    ldr r4, lbl_08074ffc @ =0x00006ea8
    adds r1, r2, r4
    ldr r0, lbl_08075000 @ =gTimeAttackRecord
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    movs r4, #0
    ldr r6, lbl_08075004 @ =0x00006e97
    adds r7, r2, r6
    ldr r0, lbl_08075008 @ =0x00006ed8
    adds r6, r2, r0
    ldr r2, lbl_0807500c @ =0x084114e8
lbl_08074f9a:
    adds r1, r7, r4
    ldrb r0, [r2]
    strb r0, [r1]
    adds r1, r6, r4
    ldrb r0, [r2, #0x10]
    strb r0, [r1]
    adds r2, #1
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08074f9a
    movs r1, #0
    movs r4, #0x1f
lbl_08074fb2:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r6, [r3]
    adds r0, r0, r6
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r7, [r3]
    adds r0, r0, r7
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074fb2
    strh r1, [r5, #0x12]
    mvns r0, r1
    strh r0, [r5, #0x14]
    movs r0, #9
    bl DoSramOperation
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ff4: .4byte 0x08754bc8
lbl_08074ff8: .4byte 0x0000ffff
lbl_08074ffc: .4byte 0x00006ea8
lbl_08075000: .4byte gTimeAttackRecord
lbl_08075004: .4byte 0x00006e97
lbl_08075008: .4byte 0x00006ed8
lbl_0807500c: .4byte 0x084114e8

    thumb_func_start sub_08075010
sub_08075010: @ 0x08075010
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08075098 @ =0x08754bc8
    mov sb, r1
    ldr r2, lbl_0807509c @ =0x040000d4
    mov sl, r2
lbl_08075028:
    mov r3, r8
    lsls r0, r3, #8
    movs r4, #0xdd
    lsls r4, r4, #7
    adds r0, r0, r4
    mov r2, sb
    ldr r1, [r2]
    adds r7, r1, r0
    adds r2, r7, #0
    ldrb r1, [r7]
    movs r0, #0x40
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    cmp r6, #0
    bne lbl_080750d4
    movs r1, #0
    ldrh r4, [r7, #0x12]
    movs r3, #0x1f
lbl_08075050:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08075050
    cmp r4, r1
    beq lbl_08075084
    movs r6, #2
lbl_08075084:
    cmp r6, #0
    bne lbl_080750d4
    movs r3, #0
    ldr r0, lbl_080750a0 @ =0x084114e8
    ldrb r1, [r7, #0x17]
    adds r2, r0, #0
    ldrb r4, [r2]
    cmp r1, r4
    beq lbl_080750a8
    b lbl_080750d2
    .align 2, 0
lbl_08075098: .4byte 0x08754bc8
lbl_0807509c: .4byte 0x040000d4
lbl_080750a0: .4byte 0x084114e8
lbl_080750a4:
    movs r6, #4
    b lbl_080750d4
lbl_080750a8:
    adds r0, r7, #0
    adds r0, #0x58
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080750a4
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_080750d4
    adds r0, r7, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080750a8
lbl_080750d2:
    movs r6, #3
lbl_080750d4:
    mov r0, r8
    cmp r0, #0
    bne lbl_08075108
    cmp r6, #0
    bne lbl_0807514a
    mov r2, sb
    ldr r1, [r2]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r1, r3
    mov r4, sl
    str r0, [r4]
    movs r0, #0xdf
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r4, #4]
    ldr r0, lbl_08075104 @ =0x80000080
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    movs r0, #0xa
    bl DoSramOperation
    b lbl_08075156
    .align 2, 0
lbl_08075104: .4byte 0x80000080
lbl_08075108:
    cmp r6, #0
    beq lbl_0807517c
    mov r1, sb
    ldr r2, [r1]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r5, #0x80
    lsls r5, r5, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #9
    bl DoSramOperation
    mov r0, sb
    ldr r2, [r0]
    movs r1, #0xdf
    lsls r1, r1, #7
    adds r2, r2, r1
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #0xa
    bl DoSramOperation
lbl_0807514a:
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #1
    bgt lbl_08075156
    b lbl_08075028
lbl_08075156:
    cmp r6, #0
    bne lbl_080751b0
    ldr r1, lbl_08075178 @ =gTimeAttackRecord
    adds r0, r7, #0
    adds r0, #0x28
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    b lbl_080751c0
    .align 2, 0
lbl_08075174: .4byte 0x0000ffff
lbl_08075178: .4byte gTimeAttackRecord
lbl_0807517c:
    ldr r1, lbl_080751a4 @ =0x040000d4
    ldr r4, lbl_080751a8 @ =0x08754bc8
    ldr r0, [r4]
    movs r2, #0xdf
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r0, [r4]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [r1, #4]
    ldr r0, lbl_080751ac @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #9
    bl DoSramOperation
    b lbl_08075156
    .align 2, 0
lbl_080751a4: .4byte 0x040000d4
lbl_080751a8: .4byte 0x08754bc8
lbl_080751ac: .4byte 0x80000080
lbl_080751b0:
    ldr r1, lbl_080751d0 @ =0x0000ffff
    ldr r2, lbl_080751d4 @ =gTimeAttackRecord
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x30
    bl BitFill
lbl_080751c0:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080751d0: .4byte 0x0000ffff
lbl_080751d4: .4byte gTimeAttackRecord

    thumb_func_start sub_080751d8
sub_080751d8: @ 0x080751d8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r1, lbl_08075314 @ =0x0000ffff
    ldr r4, lbl_08075318 @ =0x0203f800
    movs r3, #0xa0
    lsls r3, r3, #2
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
    ldr r5, lbl_0807531c @ =gCurrentArea
    ldrb r0, [r5]
    strb r0, [r4]
    ldr r0, lbl_08075320 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #1]
    adds r1, r4, #4
    ldr r0, lbl_08075324 @ =gSamusData
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, lbl_08075328 @ =gSamusWeaponInfo
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r1, lbl_0807532c @ =gSamusEcho
    adds r0, r4, #0
    adds r0, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    movs r2, #0x9c
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075330 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xa0
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_08075334 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r7}
    stm r1!, {r2, r7}
    movs r2, #0xaa
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075338 @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xae
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_0807533c @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xb4
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xba
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc0
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc6
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldrb r1, [r5]
    lsls r1, r1, #7
    ldr r3, lbl_08075340 @ =0x02037400
    adds r1, r1, r3
    movs r2, #0xcc
    lsls r2, r2, #1
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DmaTransfer
    ldrb r1, [r5]
    lsls r1, r1, #5
    ldr r7, lbl_08075344 @ =0x02037c00
    adds r1, r1, r7
    movs r2, #0x86
    lsls r2, r2, #2
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DmaTransfer
    movs r0, #0x8e
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r1, #0x41
    strb r1, [r0]
    ldr r0, lbl_08075348 @ =0x00000239
    adds r0, r4, r0
    movs r1, #0x54
    strb r1, [r0]
    ldr r0, lbl_0807534c @ =0x0000023a
    adds r0, r4, r0
    movs r1, #0x52
    strb r1, [r0]
    ldr r0, lbl_08075350 @ =0x0000023b
    adds r0, r4, r0
    movs r1, #0x55
    strb r1, [r0]
    movs r0, #0x8f
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r2, #0x4e
    strb r2, [r0]
    ldr r0, lbl_08075354 @ =0x0000023d
    adds r0, r4, r0
    movs r1, #0x45
    strb r1, [r0]
    ldr r0, lbl_08075358 @ =0x0000023e
    adds r0, r4, r0
    strb r2, [r0]
    ldr r0, lbl_0807535c @ =0x0000023f
    adds r0, r4, r0
    movs r1, #0x44
    strb r1, [r0]
    ldr r0, lbl_08075360 @ =gUseMotherShipDoors
    ldrb r1, [r0]
    movs r0, #0x90
    lsls r0, r0, #2
    adds r4, r4, r0
    strb r1, [r4]
    movs r0, #0xd
    bl DoSramOperation
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075314: .4byte 0x0000ffff
lbl_08075318: .4byte 0x0203f800
lbl_0807531c: .4byte gCurrentArea
lbl_08075320: .4byte gLastDoorUsed
lbl_08075324: .4byte gSamusData
lbl_08075328: .4byte gSamusWeaponInfo
lbl_0807532c: .4byte gSamusEcho
lbl_08075330: .4byte gScrewSpeedAnimation
lbl_08075334: .4byte gEquipment
lbl_08075338: .4byte gSamusHazardDamage
lbl_0807533c: .4byte gSamusEnvironmentalEffects
lbl_08075340: .4byte 0x02037400
lbl_08075344: .4byte 0x02037c00
lbl_08075348: .4byte 0x00000239
lbl_0807534c: .4byte 0x0000023a
lbl_08075350: .4byte 0x0000023b
lbl_08075354: .4byte 0x0000023d
lbl_08075358: .4byte 0x0000023e
lbl_0807535c: .4byte 0x0000023f
lbl_08075360: .4byte gUseMotherShipDoors

    thumb_func_start SramLoad_DemoRamValues
SramLoad_DemoRamValues: @ 0x08075364
    push {r4, r5, r6, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    ldr r0, lbl_080753c8 @ =0x0875fdfc
    lsrs r1, r1, #0x16
    adds r1, r1, r0
    ldr r6, [r1]
    cmp r2, #0
    bne lbl_080753e0
    ldr r4, lbl_080753cc @ =gCurrentArea
    ldrb r0, [r6]
    strb r0, [r4]
    ldr r1, lbl_080753d0 @ =gLastDoorUsed
    ldrb r0, [r6, #1]
    strb r0, [r1]
    ldr r1, lbl_080753d4 @ =gUseMotherShipDoors
    movs r2, #0x90
    lsls r2, r2, #2
    adds r0, r6, r2
    ldrb r0, [r0]
    strb r0, [r1]
    movs r3, #0xcc
    lsls r3, r3, #1
    adds r1, r6, r3
    ldrb r2, [r4]
    lsls r2, r2, #7
    ldr r0, lbl_080753d8 @ =0x02037400
    adds r2, r2, r0
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DmaTransfer
    movs r2, #0x86
    lsls r2, r2, #2
    adds r1, r6, r2
    ldrb r2, [r4]
    lsls r2, r2, #5
    ldr r3, lbl_080753dc @ =0x02037c00
    adds r2, r2, r3
    str r5, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DmaTransfer
    b lbl_08075470
    .align 2, 0
lbl_080753c8: .4byte 0x0875fdfc
lbl_080753cc: .4byte gCurrentArea
lbl_080753d0: .4byte gLastDoorUsed
lbl_080753d4: .4byte gUseMotherShipDoors
lbl_080753d8: .4byte 0x02037400
lbl_080753dc: .4byte 0x02037c00
lbl_080753e0:
    cmp r2, #1
    bne lbl_08075470
    ldr r1, lbl_08075478 @ =gSamusData
    adds r0, r6, #4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r4}
    stm r1!, {r2, r4}
    ldr r2, lbl_0807547c @ =gSamusWeaponInfo
    ldr r0, [r6, #0x24]
    ldr r1, [r6, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075480 @ =gSamusEcho
    adds r1, r6, #0
    adds r1, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    ldr r2, lbl_08075484 @ =gScrewSpeedAnimation
    movs r3, #0x9c
    lsls r3, r3, #1
    adds r0, r6, r3
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08075488 @ =gEquipment
    movs r4, #0xa0
    lsls r4, r4, #1
    adds r0, r6, r4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r2, lbl_0807548c @ =gSamusHazardDamage
    movs r4, #0xaa
    lsls r4, r4, #1
    adds r0, r6, r4
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075490 @ =gSamusEnvironmentalEffects
    movs r2, #0xae
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xb4
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r4, #0xba
    lsls r4, r4, #1
    adds r1, r6, r4
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r2, #0xc0
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xc6
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
lbl_08075470:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075478: .4byte gSamusData
lbl_0807547c: .4byte gSamusWeaponInfo
lbl_08075480: .4byte gSamusEcho
lbl_08075484: .4byte gScrewSpeedAnimation
lbl_08075488: .4byte gEquipment
lbl_0807548c: .4byte gSamusHazardDamage
lbl_08075490: .4byte gSamusEnvironmentalEffects

    thumb_func_start sub_08075494
sub_08075494: @ 0x08075494
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r5, lbl_080754c0 @ =0x02038000
    ldr r2, lbl_080754c4 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r4, lbl_080754c8 @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080754ae
    movs r0, #1
    strb r0, [r2]
    strb r1, [r4]
lbl_080754ae:
    ldrb r0, [r4]
    cmp r0, #4
    bhi lbl_08075588
    lsls r0, r0, #2
    ldr r1, lbl_080754cc @ =lbl_080754d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080754c0: .4byte 0x02038000
lbl_080754c4: .4byte gDisableSoftreset
lbl_080754c8: .4byte gSramOperationStage
lbl_080754cc: .4byte lbl_080754d0
lbl_080754d0: @ jump table
    .4byte lbl_080754e4 @ case 0
    .4byte lbl_08075530 @ case 1
    .4byte lbl_0807553c @ case 2
    .4byte lbl_08075568 @ case 3
    .4byte lbl_08075588 @ case 4
lbl_080754e4:
    ldr r0, lbl_08075520 @ =gSaveFilesInfo
    lsls r2, r3, #1
    adds r2, r2, r3
    lsls r2, r2, #3
    adds r2, r2, r0
    adds r1, r2, #0
    ldr r0, lbl_08075524 @ =0x08760408
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldr r0, lbl_08075528 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r2, #0x13]
    ldr r1, lbl_0807552c @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075520: .4byte gSaveFilesInfo
lbl_08075524: .4byte 0x08760408
lbl_08075528: .4byte gLanguage
lbl_0807552c: .4byte 0x0000ffff
lbl_08075530:
    ldr r0, lbl_08075538 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #0
    b lbl_0807556e
    .align 2, 0
lbl_08075538: .4byte gMostRecentSaveFile
lbl_0807553c:
    ldr r1, lbl_08075560 @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    ldr r0, lbl_08075564 @ =0x000036e0
    adds r2, r2, r0
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075560: .4byte 0x0000ffff
lbl_08075564: .4byte 0x000036e0
lbl_08075568:
    ldr r0, lbl_08075580 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #1
lbl_0807556e:
    bl unk_fbc
    cmp r0, #0
    beq lbl_08075590
lbl_08075576:
    ldr r1, lbl_08075584 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08075590
    .align 2, 0
lbl_08075580: .4byte gMostRecentSaveFile
lbl_08075584: .4byte gSramOperationStage
lbl_08075588:
    ldr r1, lbl_080755a0 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r4]
lbl_08075590:
    ldr r0, lbl_080755a0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080755a0: .4byte gDisableSoftreset

    thumb_func_start sub_080755a4
sub_080755a4: @ 0x080755a4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    ldr r6, lbl_080755d4 @ =0x02038000
    ldr r2, lbl_080755d8 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r5, lbl_080755dc @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080755c2
    movs r0, #1
    strb r0, [r2]
    strb r1, [r5]
lbl_080755c2:
    ldrb r0, [r5]
    cmp r0, #4
    bhi lbl_080756a4
    lsls r0, r0, #2
    ldr r1, lbl_080755e0 @ =lbl_080755e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080755d4: .4byte 0x02038000
lbl_080755d8: .4byte gDisableSoftreset
lbl_080755dc: .4byte gSramOperationStage
lbl_080755e0: .4byte lbl_080755e4
lbl_080755e4: @ jump table
    .4byte lbl_080755f8 @ case 0
    .4byte lbl_08075634 @ case 1
    .4byte lbl_08075640 @ case 2
    .4byte lbl_08075680 @ case 3
    .4byte lbl_080756a4 @ case 4
lbl_080755f8:
    ldr r2, lbl_08075630 @ =gSaveFilesInfo
    lsls r1, r3, #1
    adds r1, r1, r3
    lsls r1, r1, #3
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #3
    adds r1, r1, r2
    adds r0, r0, r2
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    adds r1, #0x80
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    b lbl_0807565c
    .align 2, 0
lbl_08075630: .4byte gSaveFilesInfo
lbl_08075634:
    ldr r5, lbl_0807563c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #0
    b lbl_08075686
    .align 2, 0
lbl_0807563c: .4byte gMostRecentSaveFile
lbl_08075640:
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    ldr r0, lbl_08075678 @ =0x000036e0
    adds r1, r1, r0
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, r2, r0
lbl_0807565c:
    adds r2, r6, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, lbl_0807567c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080756ac
    .align 2, 0
lbl_08075678: .4byte 0x000036e0
lbl_0807567c: .4byte gSramOperationStage
lbl_08075680:
    ldr r5, lbl_0807569c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #1
lbl_08075686:
    bl unk_fbc
    cmp r0, #0
    beq lbl_08075696
    ldr r1, lbl_080756a0 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08075696:
    strb r4, [r5]
    b lbl_080756ac
    .align 2, 0
lbl_0807569c: .4byte gMostRecentSaveFile
lbl_080756a0: .4byte gSramOperationStage
lbl_080756a4:
    ldr r1, lbl_080756bc @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r5]
lbl_080756ac:
    ldr r0, lbl_080756bc @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080756bc: .4byte gDisableSoftreset

    thumb_func_start sub_080756c0
sub_080756c0: @ 0x080756c0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0807574c @ =0x02038000
    movs r6, #0
    ldr r1, lbl_08075750 @ =gSaveFilesInfo
    adds r5, r0, #0
    adds r5, #0xbc
    adds r4, r0, #0
    adds r4, #0x98
    adds r3, r0, #0
    adds r3, #0x80
    movs r0, #0x91
    lsls r0, r0, #5
    mov ip, r0
    movs r7, #2
    mov r8, r7
lbl_080756e2:
    ldrb r0, [r4, #5]
    strb r0, [r1, #2]
    ldrb r2, [r1]
    cmp r2, #1
    bne lbl_08075756
    movs r7, #0xd1
    lsls r7, r7, #1
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #4]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #6]
    adds r7, #8
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #8]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    adds r7, #0x10
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xc]
    adds r7, #0x4e
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xd]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xe]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xf]
    ldrb r0, [r4, #4]
    strb r0, [r1, #0x10]
    ldrb r0, [r4]
    strb r0, [r1, #0x11]
    ldrb r0, [r4, #1]
    strb r0, [r1, #0x12]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_08075754
    strb r2, [r1, #0x14]
    b lbl_08075756
    .align 2, 0
lbl_0807574c: .4byte 0x02038000
lbl_08075750: .4byte gSaveFilesInfo
lbl_08075754:
    strb r0, [r1, #0x14]
lbl_08075756:
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08075762
    ldrb r0, [r1, #0x10]
    cmp r0, #0
    bne lbl_080757a4
lbl_08075762:
    strb r6, [r1]
    strb r6, [r1, #2]
    movs r2, #0
    strh r6, [r1, #4]
    strh r6, [r1, #6]
    strh r6, [r1, #8]
    strh r6, [r1, #0xa]
    strb r2, [r1, #0xc]
    strb r2, [r1, #0xd]
    strb r2, [r1, #0xe]
    strb r2, [r1, #0xf]
    ldr r0, lbl_080757c4 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r1, #0x13]
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_080757a4
    movs r0, #5
    strb r0, [r1, #2]
    movs r0, #0x63
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strb r2, [r1, #0x14]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_0807579a
    movs r0, #1
lbl_0807579a:
    strb r0, [r1, #0x14]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
lbl_080757a4:
    adds r1, #0x18
    add r5, ip
    add r4, ip
    add r3, ip
    movs r0, #1
    rsbs r0, r0, #0
    add r8, r0
    mov r7, r8
    cmp r7, #0
    bge lbl_080756e2
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080757c4: .4byte gLanguage

    thumb_func_start sub_080757c8
sub_080757c8: @ 0x080757c8
    push {r4, lr}
    ldr r1, lbl_080757f4 @ =gMostRecentSaveFile
    movs r4, #0
    ldrsb r4, [r1, r4]
    strb r0, [r1]
    ldr r2, lbl_080757f8 @ =gSaveFilesInfo
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #1]
    cmp r0, #4
    bhi lbl_08075828
    lsls r0, r0, #2
    ldr r1, lbl_080757fc @ =lbl_08075800
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080757f4: .4byte gMostRecentSaveFile
lbl_080757f8: .4byte gSaveFilesInfo
lbl_080757fc: .4byte lbl_08075800
lbl_08075800: @ jump table
    .4byte lbl_08075828 @ case 0
    .4byte lbl_08075814 @ case 1
    .4byte lbl_0807581c @ case 2
    .4byte lbl_08075828 @ case 3
    .4byte lbl_08075828 @ case 4
lbl_08075814:
    movs r0, #3
    bl DoSramOperation
    b lbl_08075828
lbl_0807581c:
    movs r0, #3
    bl DoSramOperation
    movs r0, #4
    bl DoSramOperation
lbl_08075828:
    ldr r3, lbl_08075844 @ =gSaveFilesInfo
    ldr r2, lbl_08075848 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    movs r1, #0
    strb r1, [r0, #1]
    strb r4, [r2]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075844: .4byte gSaveFilesInfo
lbl_08075848: .4byte gMostRecentSaveFile

    thumb_func_start unk_7584c
unk_7584c: @ 0x0807584c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_08075880 @ =gButtonAssignments
    ldr r0, lbl_08075884 @ =0x08411510
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r7, lbl_08075888 @ =gMaxInGameTimerFlag
    movs r1, #0
    strb r1, [r7]
    ldr r0, lbl_0807588c @ =gShipLandingFlag
    strb r1, [r0]
    ldr r0, lbl_08075890 @ =gColorFading
    movs r5, #0
    movs r6, #2
    strb r6, [r0]
    cmp r4, #1
    beq lbl_080758b4
    cmp r4, #1
    bgt lbl_08075894
    cmp r4, #0
    beq lbl_0807589e
    b lbl_08075918
    .align 2, 0
lbl_08075880: .4byte gButtonAssignments
lbl_08075884: .4byte 0x08411510
lbl_08075888: .4byte gMaxInGameTimerFlag
lbl_0807588c: .4byte gShipLandingFlag
lbl_08075890: .4byte gColorFading
lbl_08075894:
    cmp r4, #2
    beq lbl_08075918
    cmp r4, #3
    beq lbl_080758f4
    b lbl_08075918
lbl_0807589e:
    ldr r1, lbl_080758ac @ =gStartingInfo
    ldr r0, lbl_080758b0 @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl check_load_save_file
    b lbl_08075914
    .align 2, 0
lbl_080758ac: .4byte gStartingInfo
lbl_080758b0: .4byte 0x08411524
lbl_080758b4:
    ldr r1, lbl_080758d8 @ =gStartingInfo
    ldr r0, lbl_080758dc @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl init_save_file
    ldr r0, lbl_080758e0 @ =gCurrentRoom
    strb r5, [r0]
    ldr r0, lbl_080758e4 @ =gLastDoorUsed
    strb r5, [r0]
    strb r4, [r7]
    ldr r0, lbl_080758e8 @ =gSkipDoorTransition
    strb r5, [r0]
    ldr r0, lbl_080758ec @ =gDebugFlag
    strb r5, [r0]
    ldr r0, lbl_080758f0 @ =gLanguage
    strb r6, [r0]
    b lbl_08075914
    .align 2, 0
lbl_080758d8: .4byte gStartingInfo
lbl_080758dc: .4byte 0x08411524
lbl_080758e0: .4byte gCurrentRoom
lbl_080758e4: .4byte gLastDoorUsed
lbl_080758e8: .4byte gSkipDoorTransition
lbl_080758ec: .4byte gDebugFlag
lbl_080758f0: .4byte gLanguage
lbl_080758f4:
    ldr r3, lbl_08075940 @ =gIsLoadingFile
    ldr r2, lbl_08075944 @ =gSaveFilesInfo
    ldr r0, lbl_08075948 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08075914
    bl sub_0807478c
lbl_08075914:
    ldr r0, lbl_0807594c @ =gCurrentCutscene
    strb r5, [r0]
lbl_08075918:
    ldr r0, lbl_08075950 @ =gGameModeSub3
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08075954 @ =gMonochromeBgFading
    strb r1, [r0]
    ldr r0, lbl_08075958 @ =gDisableSoftreset
    strb r1, [r0]
    ldr r0, lbl_0807595c @ =gSubGameModeStage
    strb r1, [r0]
    ldr r0, lbl_08075960 @ =gPauseScreenFlag
    strb r1, [r0]
    ldr r0, lbl_08075964 @ =gDisablePause
    strb r1, [r0]
    ldr r1, lbl_08075968 @ =gSamusDoorPositionOffset
    movs r0, #0
    strh r0, [r1]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075940: .4byte gIsLoadingFile
lbl_08075944: .4byte gSaveFilesInfo
lbl_08075948: .4byte gMostRecentSaveFile
lbl_0807594c: .4byte gCurrentCutscene
lbl_08075950: .4byte gGameModeSub3
lbl_08075954: .4byte gMonochromeBgFading
lbl_08075958: .4byte gDisableSoftreset
lbl_0807595c: .4byte gSubGameModeStage
lbl_08075960: .4byte gPauseScreenFlag
lbl_08075964: .4byte gDisablePause
lbl_08075968: .4byte gSamusDoorPositionOffset

    thumb_func_start check_load_save_file
check_load_save_file: @ 0x0807596c
    push {r4, r5, r6, lr}
    ldr r2, lbl_08075a10 @ =gIsLoadingFile
    ldr r6, lbl_08075a14 @ =gSaveFilesInfo
    ldr r5, lbl_08075a18 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0]
    strb r0, [r2]
    lsls r0, r0, #0x18
    asrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_08075a4c
    bl init_save_file
    ldr r1, lbl_08075a1c @ =gColorFading
    movs r0, #0x15
    strb r0, [r1]
    ldr r0, lbl_08075a20 @ =gEquipment
    strb r4, [r0, #0x10]
    ldr r2, lbl_08075a24 @ =gCurrentArea
    ldr r0, lbl_08075a28 @ =gStartingInfo
    ldrb r1, [r0]
    strb r1, [r2]
    ldr r0, lbl_08075a2c @ =gAreaBeforeTransition
    strb r1, [r0]
    ldr r0, lbl_08075a30 @ =gCurrentRoom
    strb r4, [r0]
    ldr r0, lbl_08075a34 @ =gLastDoorUsed
    strb r4, [r0]
    ldr r2, lbl_08075a38 @ =gGameCompletion
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x11]
    strb r0, [r2]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x12]
    strb r0, [r2, #1]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x13]
    strb r0, [r2, #2]
    ldr r2, lbl_08075a3c @ =gDifficulty
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x14]
    strb r0, [r2]
    ldr r2, lbl_08075a40 @ =gTimeAttackFlag
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x15]
    strb r0, [r2]
    ldr r0, lbl_08075a44 @ =gUseMotherShipDoors
    strb r4, [r0]
    ldr r1, lbl_08075a48 @ =gShipLandingFlag
    movs r0, #1
    strb r0, [r1]
    b lbl_08075a50
    .align 2, 0
lbl_08075a10: .4byte gIsLoadingFile
lbl_08075a14: .4byte gSaveFilesInfo
lbl_08075a18: .4byte gMostRecentSaveFile
lbl_08075a1c: .4byte gColorFading
lbl_08075a20: .4byte gEquipment
lbl_08075a24: .4byte gCurrentArea
lbl_08075a28: .4byte gStartingInfo
lbl_08075a2c: .4byte gAreaBeforeTransition
lbl_08075a30: .4byte gCurrentRoom
lbl_08075a34: .4byte gLastDoorUsed
lbl_08075a38: .4byte gGameCompletion
lbl_08075a3c: .4byte gDifficulty
lbl_08075a40: .4byte gTimeAttackFlag
lbl_08075a44: .4byte gUseMotherShipDoors
lbl_08075a48: .4byte gShipLandingFlag
lbl_08075a4c:
    bl sub_0807478c
lbl_08075a50:
    ldr r3, lbl_08075a7c @ =gGameCompletion
    ldr r2, lbl_08075a80 @ =gSaveFilesInfo
    ldr r0, lbl_08075a84 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r0, #0x13]
    movs r2, #0
    strb r1, [r3, #2]
    ldr r0, lbl_08075a88 @ =gLanguage
    strb r1, [r0]
    ldr r0, lbl_08075a8c @ =gSkipDoorTransition
    strb r2, [r0]
    ldr r0, lbl_08075a90 @ =gDebugFlag
    strb r2, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075a7c: .4byte gGameCompletion
lbl_08075a80: .4byte gSaveFilesInfo
lbl_08075a84: .4byte gMostRecentSaveFile
lbl_08075a88: .4byte gLanguage
lbl_08075a8c: .4byte gSkipDoorTransition
lbl_08075a90: .4byte gDebugFlag

    thumb_func_start init_save_file
init_save_file: @ 0x08075a94
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r2, lbl_08075ba8 @ =0x02037400
    movs r6, #0x80
    lsls r6, r6, #4
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    ldr r4, lbl_08075bac @ =0x0000ffff
    ldr r2, lbl_08075bb0 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bb4 @ =0x02036c00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r3, r6, #0
    bl BitFill
    ldr r2, lbl_08075bb8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #2
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bbc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x20
    bl BitFill
    ldr r2, lbl_08075bc0 @ =0x02033800
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    movs r1, #0
    ldr r4, lbl_08075bc4 @ =gNumberOfNeverReformBlocks
    movs r2, #0
    ldr r3, lbl_08075bc8 @ =gNumberOfItemsCollected
lbl_08075b08:
    adds r0, r1, r4
    strb r2, [r0]
    adds r0, r1, r3
    strb r2, [r0]
    adds r1, #1
    cmp r1, #7
    ble lbl_08075b08
    ldr r1, lbl_08075bcc @ =gInGameTimer
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_08075bd4 @ =gDisableDrawingSamusAndScrolling
    mov r8, r0
    ldr r1, lbl_08075bd8 @ =gDifficulty
    mov sl, r1
    ldr r2, lbl_08075bdc @ =gIsLoadingFile
    mov sb, r2
    ldr r2, lbl_08075be0 @ =gBestCompletionTimes
    ldr r0, lbl_08075be4 @ =0x0841151c
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x2c
lbl_08075b34:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b34
    ldr r2, lbl_08075be8 @ =gInGameTimerAtBosses
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x10
lbl_08075b46:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b46
    movs r1, #0
    ldr r0, lbl_08075bec @ =0x083602e8
    mov ip, r0
    ldr r7, lbl_08075bf0 @ =gInGameCutscenesTriggered
lbl_08075b56:
    movs r3, #0
    movs r4, #0
    adds r6, r1, #1
    lsls r5, r1, #2
    lsls r0, r1, #8
    mov r1, ip
    adds r2, r0, r1
lbl_08075b64:
    ldrb r1, [r2]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    lsls r0, r3
    orrs r4, r0
    adds r2, #8
    adds r3, #1
    cmp r3, #0x1f
    ble lbl_08075b64
    adds r0, r5, r7
    str r4, [r0]
    adds r1, r6, #0
    cmp r1, #0
    ble lbl_08075b56
    movs r1, #0
    mov r2, r8
    strb r1, [r2]
    movs r0, #1
    mov r2, sl
    strb r0, [r2]
    ldr r0, lbl_08075bf4 @ =gTimeAttackFlag
    strb r1, [r0]
    mov r2, sb
    strb r1, [r2]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075ba8: .4byte 0x02037400
lbl_08075bac: .4byte 0x0000ffff
lbl_08075bb0: .4byte 0x02035c00
lbl_08075bb4: .4byte 0x02036c00
lbl_08075bb8: .4byte 0x02037c00
lbl_08075bbc: .4byte 0x02037e00
lbl_08075bc0: .4byte 0x02033800
lbl_08075bc4: .4byte gNumberOfNeverReformBlocks
lbl_08075bc8: .4byte gNumberOfItemsCollected
lbl_08075bcc: .4byte gInGameTimer
lbl_08075bd0: .4byte 0x08411518
lbl_08075bd4: .4byte gDisableDrawingSamusAndScrolling
lbl_08075bd8: .4byte gDifficulty
lbl_08075bdc: .4byte gIsLoadingFile
lbl_08075be0: .4byte gBestCompletionTimes
lbl_08075be4: .4byte 0x0841151c
lbl_08075be8: .4byte gInGameTimerAtBosses
lbl_08075bec: .4byte 0x083602e8
lbl_08075bf0: .4byte gInGameCutscenesTriggered
lbl_08075bf4: .4byte gTimeAttackFlag
lbl_08075bf8:
    .byte 0x81, 0xB0, 0x69, 0x46, 0x00, 0x20, 0x08, 0x70
    .byte 0x01, 0xB0, 0x70, 0x47

    thumb_func_start unk_75c04
unk_75c04: @ 0x08075c04
    push {r4, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r0, lbl_08075c28 @ =0x08075bf9
    bl CallbackSetVBlank
    adds r0, r4, #0
    bl unk_7584c
    ldr r0, lbl_08075c2c @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08075c28: .4byte 0x08075bf9
lbl_08075c2c: .4byte gIsLoadingFile
