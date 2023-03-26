    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start mother_brain_close_up_looking_at_samus
mother_brain_close_up_looking_at_samus: @ 0x08063008
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_08063024 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #5
    bls lbl_08063018
    b lbl_08063222
lbl_08063018:
    lsls r0, r0, #2
    ldr r1, lbl_08063028 @ =lbl_0806302c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08063024: .4byte sNonGameplayRamPointer
lbl_08063028: .4byte lbl_0806302c
lbl_0806302c: @ jump table
    .4byte lbl_08063044 @ case 0
    .4byte lbl_0806312c @ case 1
    .4byte lbl_08063184 @ case 2
    .4byte lbl_080631ac @ case 3
    .4byte lbl_080631e8 @ case 4
    .4byte lbl_0806320c @ case 5
lbl_08063044:
    ldr r1, lbl_08063078 @ =0x08376144
    movs r4, #0xa0
    lsls r4, r4, #0x13
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0xa0
    bl DMATransfer
    movs r0, #0
    strh r0, [r4]
    ldr r0, lbl_0806307c @ =gEquipment
    ldrb r1, [r0, #0xf]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08063088
    ldr r1, lbl_08063080 @ =0x08376284
    ldr r2, lbl_08063084 @ =0x050000a0
    str r5, [sp]
    movs r0, #3
    movs r3, #0xa0
    bl DMATransfer
    b lbl_08063096
    .align 2, 0
lbl_08063078: .4byte 0x08376144
lbl_0806307c: .4byte gEquipment
lbl_08063080: .4byte 0x08376284
lbl_08063084: .4byte 0x050000a0
lbl_08063088:
    ldr r1, lbl_08063100 @ =0x083761e4
    ldr r2, lbl_08063104 @ =0x050000a0
    str r5, [sp]
    movs r0, #3
    movs r3, #0xa0
    bl DMATransfer
lbl_08063096:
    ldr r0, lbl_08063108 @ =0x0837b404
    ldr r5, lbl_0806310c @ =0x08375d20
    adds r1, r5, #0
    adds r1, #0x20
    ldrb r1, [r1]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063110 @ =0x08381e70
    ldrb r1, [r5, #0x19]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063114 @ =0x08382434
    adds r1, r5, #0
    adds r1, #0x21
    ldrb r1, [r1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r1, lbl_08063118 @ =0x08376364
    ldr r2, lbl_0806311c @ =0x05000200
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    ldr r0, lbl_08063120 @ =0x0837f498
    ldr r1, lbl_08063124 @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, [r5, #0x20]
    ldr r1, [r5, #0x24]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r5, #0x18]
    ldr r1, [r5, #0x1c]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    movs r0, #1
    bl sub_080636a8
    ldr r0, lbl_08063128 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_080631d2
    .align 2, 0
lbl_08063100: .4byte 0x083761e4
lbl_08063104: .4byte 0x050000a0
lbl_08063108: .4byte 0x0837b404
lbl_0806310c: .4byte 0x08375d20
lbl_08063110: .4byte 0x08381e70
lbl_08063114: .4byte 0x08382434
lbl_08063118: .4byte 0x08376364
lbl_0806311c: .4byte 0x05000200
lbl_08063120: .4byte 0x0837f498
lbl_08063124: .4byte 0x06010000
lbl_08063128: .4byte sNonGameplayRamPointer
lbl_0806312c:
    ldr r0, lbl_08063174 @ =0x08378e2c
    ldr r5, lbl_08063178 @ =0x08375d20
    ldrb r1, [r5, #0x18]
    lsls r1, r1, #0xe
    movs r2, #0xc0
    lsls r2, r2, #0x13
    adds r1, r1, r2
    bl CallLZ77UncompVRAM
    movs r0, #0xfd
    lsls r0, r0, #6
    movs r1, #1
    str r1, [sp]
    movs r1, #0xc
    movs r2, #0xc
    movs r3, #8
    bl CutsceneStartBackgroundEffect
    ldr r0, lbl_0806317c @ =0x08375d48
    ldr r0, [r0]
    ldrh r4, [r5, #0x24]
    adds r1, r4, #0
    bl CutsceneStartScreenShake
    ldr r0, lbl_08063180 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r0, [r5, #0x1c]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r1, r3, #0
    orrs r0, r1
    orrs r4, r0
    movs r0, #0
    strh r4, [r2, #0x1c]
    b lbl_080631f8
    .align 2, 0
lbl_08063174: .4byte 0x08378e2c
lbl_08063178: .4byte 0x08375d20
lbl_0806317c: .4byte 0x08375d48
lbl_08063180: .4byte sNonGameplayRamPointer
lbl_08063184:
    ldr r3, lbl_080631a8 @ =sNonGameplayRamPointer
    ldr r2, [r3]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08063222
    adds r1, r2, #0
    adds r1, #0xfd
    movs r2, #0
    movs r0, #1
    strb r0, [r1]
    ldr r1, [r3]
    strh r2, [r1, #2]
    b lbl_080631d6
    .align 2, 0
lbl_080631a8: .4byte sNonGameplayRamPointer
lbl_080631ac:
    ldr r4, lbl_080631e0 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_080631e4 @ =0x0875ff34
    ldrh r0, [r0, #2]
    ldrh r1, [r1]
    cmp r0, r1
    bls lbl_08063222
    movs r0, #0x8c
    lsls r0, r0, #2
    bl SoundPlay
    ldr r0, [r4]
    movs r1, #0x88
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #6
    bl UpdateCutsceneOamDataID
    ldr r1, [r4]
lbl_080631d2:
    movs r0, #0
    strh r0, [r1, #2]
lbl_080631d6:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063222
    .align 2, 0
lbl_080631e0: .4byte sNonGameplayRamPointer
lbl_080631e4: .4byte 0x0875ff34
lbl_080631e8:
    ldr r0, lbl_08063204 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldr r1, lbl_08063208 @ =0x0875ff34
    ldrh r0, [r2, #2]
    ldrh r1, [r1, #2]
    cmp r0, r1
    bls lbl_08063222
    movs r0, #0
lbl_080631f8:
    strh r0, [r2, #2]
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_08063222
    .align 2, 0
lbl_08063204: .4byte sNonGameplayRamPointer
lbl_08063208: .4byte 0x0875ff34
lbl_0806320c:
    bl unk_61f0c
    ldr r3, lbl_08063238 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063222:
    ldr r0, lbl_08063238 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xf0
    bl sub_0806323c
    movs r0, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063238: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0806323c
sub_0806323c: @ 0x0806323c
    push {r4, lr}
    adds r4, r0, #0
    ldrb r1, [r4, #0xd]
    adds r0, r1, #0
    cmp r0, #0
    beq lbl_0806327e
    cmp r0, #1
    bne lbl_08063254
    movs r0, #0x3c
    strh r0, [r4, #0x14]
    adds r0, r1, #1
    b lbl_0806327c
lbl_08063254:
    ldrh r0, [r4, #0x14]
    cmp r0, #0
    beq lbl_08063260
    subs r0, #1
    strh r0, [r4, #0x14]
    b lbl_0806327e
lbl_08063260:
    movs r0, #0x5a
    strh r0, [r4, #0x14]
    adds r0, r4, #0
    movs r1, #4
    bl UpdateCutsceneOamDataID
    ldrb r0, [r4, #0xd]
    adds r0, #1
    strb r0, [r4, #0xd]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #6
    bls lbl_0806327e
    movs r0, #0
lbl_0806327c:
    strb r0, [r4, #0xd]
lbl_0806327e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start mother_brain_close_up_eye_opening
mother_brain_close_up_eye_opening: @ 0x08063284
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r0, lbl_080632a0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #6
    bls lbl_08063294
    b lbl_08063472
lbl_08063294:
    lsls r0, r0, #2
    ldr r1, lbl_080632a4 @ =lbl_080632a8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080632a0: .4byte sNonGameplayRamPointer
lbl_080632a4: .4byte lbl_080632a8
lbl_080632a8: @ jump table
    .4byte lbl_080632c4 @ case 0
    .4byte lbl_080633a0 @ case 1
    .4byte lbl_080633c0 @ case 2
    .4byte lbl_080633e0 @ case 3
    .4byte lbl_0806341c @ case 4
    .4byte lbl_08063438 @ case 5
    .4byte lbl_0806345c @ case 6
lbl_080632c4:
    ldr r1, lbl_0806336c @ =0x08376084
    movs r5, #0xa0
    lsls r5, r5, #0x13
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0xc0
    bl DMATransfer
    movs r4, #0
    strh r4, [r5]
    ldr r0, lbl_08063370 @ =0x083763a4
    ldr r5, lbl_08063374 @ =0x08375d20
    ldrb r1, [r5, #0x10]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063378 @ =0x083818ac
    ldrb r1, [r5, #0x11]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806337c @ =0x083829f4
    ldrb r1, [r5, #9]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r1, lbl_08063380 @ =0x08376324
    ldr r2, lbl_08063384 @ =0x05000200
    str r6, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    ldr r0, lbl_08063388 @ =0x0837e2e0
    ldr r1, lbl_0806338c @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, [r5, #0x10]
    ldr r1, [r5, #0x14]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r5, #8]
    ldr r1, [r5, #0xc]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    movs r0, #0
    bl sub_080636a8
    ldrh r4, [r5, #0x14]
    movs r2, #0x80
    lsls r2, r2, #4
    movs r0, #3
    adds r1, r4, #0
    bl CutsceneSetBackgroundPosition
    ldr r1, lbl_08063390 @ =gWrittenToBLDALPHA_L
    movs r0, #6
    strh r0, [r1]
    ldr r1, lbl_08063394 @ =gWrittenToBLDALPHA_H
    movs r0, #0xc
    strh r0, [r1]
    ldr r0, lbl_08063398 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    movs r3, #0
    ldr r0, lbl_0806339c @ =0x00003844
    strh r0, [r2, #0x1e]
    ldrh r0, [r5, #0xc]
    movs r5, #0x80
    lsls r5, r5, #5
    adds r1, r5, #0
    orrs r0, r1
    orrs r4, r0
    strh r4, [r2, #0x1c]
    strh r3, [r2, #2]
    b lbl_0806344a
    .align 2, 0
lbl_0806336c: .4byte 0x08376084
lbl_08063370: .4byte 0x083763a4
lbl_08063374: .4byte 0x08375d20
lbl_08063378: .4byte 0x083818ac
lbl_0806337c: .4byte 0x083829f4
lbl_08063380: .4byte 0x08376324
lbl_08063384: .4byte 0x05000200
lbl_08063388: .4byte 0x0837e2e0
lbl_0806338c: .4byte 0x06010000
lbl_08063390: .4byte gWrittenToBLDALPHA_L
lbl_08063394: .4byte gWrittenToBLDALPHA_H
lbl_08063398: .4byte sNonGameplayRamPointer
lbl_0806339c: .4byte 0x00003844
lbl_080633a0:
    ldr r4, lbl_080633b8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_080633bc @ =0x0875ff38
    ldrh r0, [r0, #2]
    ldrh r1, [r1]
    cmp r0, r1
    bls lbl_08063472
    movs r0, #0
    bl sub_0806380c
    b lbl_08063402
    .align 2, 0
lbl_080633b8: .4byte sNonGameplayRamPointer
lbl_080633bc: .4byte 0x0875ff38
lbl_080633c0:
    ldr r4, lbl_080633d8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_080633dc @ =0x0875ff38
    ldrh r0, [r0, #2]
    ldrh r1, [r1, #2]
    cmp r0, r1
    bls lbl_08063472
    movs r0, #1
    bl sub_0806380c
    b lbl_08063402
    .align 2, 0
lbl_080633d8: .4byte sNonGameplayRamPointer
lbl_080633dc: .4byte 0x0875ff38
lbl_080633e0:
    ldr r4, lbl_08063410 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_08063414 @ =0x0875ff38
    ldrh r0, [r0, #2]
    ldrh r1, [r1, #4]
    cmp r0, r1
    bls lbl_08063472
    ldr r0, lbl_08063418 @ =0x0000022f
    bl SoundPlay
    ldr r0, [r4]
    movs r1, #0xe8
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #3
    bl UpdateCutsceneOamDataID
lbl_08063402:
    ldr r1, [r4]
    movs r0, #0
    strh r0, [r1, #2]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063472
    .align 2, 0
lbl_08063410: .4byte sNonGameplayRamPointer
lbl_08063414: .4byte 0x0875ff38
lbl_08063418: .4byte 0x0000022f
lbl_0806341c:
    ldr r0, lbl_08063430 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldr r5, lbl_08063434 @ =0x000001db
    adds r0, r2, r5
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08063472
    b lbl_08063446
    .align 2, 0
lbl_08063430: .4byte sNonGameplayRamPointer
lbl_08063434: .4byte 0x000001db
lbl_08063438:
    ldr r0, lbl_08063454 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldr r1, lbl_08063458 @ =0x0875ff38
    ldrh r0, [r2, #2]
    ldrh r1, [r1, #6]
    cmp r0, r1
    bls lbl_08063472
lbl_08063446:
    movs r0, #0
    strh r0, [r2, #2]
lbl_0806344a:
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_08063472
    .align 2, 0
lbl_08063454: .4byte sNonGameplayRamPointer
lbl_08063458: .4byte 0x0875ff38
lbl_0806345c:
    bl unk_61f0c
    ldr r3, lbl_080634b4 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063472:
    movs r4, #0
    movs r5, #0xf0
lbl_08063476:
    ldr r0, lbl_080634b4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    lsls r0, r4, #5
    adds r0, r1, r0
    adds r0, #0xfa
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806348c
    adds r0, r1, r5
    bl sub_080637b0
lbl_0806348c:
    adds r5, #0x20
    adds r4, #1
    cmp r4, #5
    ble lbl_08063476
    ldr r0, lbl_080634b8 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_080634aa
    ldr r0, lbl_080634bc @ =gWrittenToBLDALPHA_H
    ldrh r1, [r0]
    movs r2, #1
    eors r1, r2
    strh r1, [r0]
lbl_080634aa:
    movs r0, #0
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080634b4: .4byte sNonGameplayRamPointer
lbl_080634b8: .4byte gFrameCounter8Bit
lbl_080634bc: .4byte gWrittenToBLDALPHA_H

    thumb_func_start mother_brain_close_up_tank_view
mother_brain_close_up_tank_view: @ 0x080634c0
    push {r4, lr}
    ldr r1, lbl_080634d8 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #4]
    adds r4, r1, #0
    cmp r0, #4
    bhi lbl_08063576
    lsls r0, r0, #2
    ldr r1, lbl_080634dc @ =lbl_080634e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080634d8: .4byte sNonGameplayRamPointer
lbl_080634dc: .4byte lbl_080634e0
lbl_080634e0: @ jump table
    .4byte lbl_080634f4 @ case 0
    .4byte lbl_08063518 @ case 1
    .4byte lbl_08063530 @ case 2
    .4byte lbl_0806354c @ case 3
    .4byte lbl_08063560 @ case 4
lbl_080634f4:
    ldr r0, lbl_08063510 @ =0x0000022e
    bl SoundPlay
    ldr r4, lbl_08063514 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldrh r0, [r0, #0x1e]
    movs r1, #0xa
    movs r2, #0
    movs r3, #8
    bl CutsceneStartSpriteEffect
    ldr r1, [r4]
    b lbl_08063554
    .align 2, 0
lbl_08063510: .4byte 0x0000022e
lbl_08063514: .4byte sNonGameplayRamPointer
lbl_08063518:
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #0x1e
    bls lbl_08063576
    ldrh r0, [r1, #0x1e]
    movs r1, #0
    movs r2, #2
    movs r3, #1
    bl CutsceneStartSpriteEffect
    ldr r1, [r4]
    b lbl_08063554
lbl_08063530:
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08063576
    movs r0, #0
    strh r0, [r2, #2]
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_08063576
lbl_0806354c:
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #0x3c
    bls lbl_08063576
lbl_08063554:
    movs r0, #0
    strh r0, [r1, #2]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063576
lbl_08063560:
    bl unk_61f0c
    ldr r3, lbl_08063580 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063576:
    movs r0, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063580: .4byte sNonGameplayRamPointer

    thumb_func_start mother_brain_close_up_init
mother_brain_close_up_init: @ 0x08063584
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    bl unk_61f0c
    ldr r1, lbl_08063624 @ =0x08386e60
    movs r4, #0xa0
    lsls r4, r4, #0x13
    movs r3, #0x80
    lsls r3, r3, #1
    movs r0, #0x10
    mov r8, r0
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    movs r1, #0
    mov sb, r1
    strh r1, [r4]
    ldr r0, lbl_08063628 @ =0x08382b00
    ldr r4, lbl_0806362c @ =0x08375d20
    ldrb r1, [r4]
    lsls r1, r1, #0xe
    movs r5, #0xc0
    lsls r5, r5, #0x13
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063630 @ =0x083868a0
    ldrb r1, [r4, #1]
    lsls r1, r1, #0xb
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, [r4]
    ldr r1, [r4, #4]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    ldr r5, lbl_08063634 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    movs r6, #0
    movs r0, #0xff
    strh r0, [r1, #0x1e]
    ldr r0, lbl_08063638 @ =gWrittenToBLDY_NonGameplay
    mov r1, r8
    strh r1, [r0]
    ldrh r4, [r4, #4]
    movs r2, #0x80
    lsls r2, r2, #4
    movs r0, #3
    adds r1, r4, #0
    bl CutsceneSetBackgroundPosition
    movs r0, #0x48
    movs r1, #0
    bl PlayMusic
    ldr r1, [r5]
    strh r4, [r1, #0x1c]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    strh r6, [r0, #2]
    mov r1, sb
    strb r1, [r0, #4]
    movs r0, #0
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063624: .4byte 0x08386e60
lbl_08063628: .4byte 0x08382b00
lbl_0806362c: .4byte 0x08375d20
lbl_08063630: .4byte 0x083868a0
lbl_08063634: .4byte sNonGameplayRamPointer
lbl_08063638: .4byte gWrittenToBLDY_NonGameplay

    thumb_func_start mother_brain_close_up_subroutine
mother_brain_close_up_subroutine: @ 0x0806363c
    push {r4, lr}
    ldr r1, lbl_08063668 @ =0x0875ff40
    ldr r0, lbl_0806366c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    movs r0, #1
    bl CutsceneUpdateBackgroundsPosition
    bl sub_08063670
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063668: .4byte 0x0875ff40
lbl_0806366c: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08063670
sub_08063670: @ 0x08063670
    push {lr}
    ldr r1, lbl_08063698 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_0806369c @ =0x0875ff40
    ldr r0, lbl_080636a0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    adds r1, #0xf0
    ldr r2, lbl_080636a4 @ =0x08375d4c
    bl process_cutscene_oam
    bl ResetFreeOAM
    pop {r0}
    bx r0
    .align 2, 0
lbl_08063698: .4byte gNextOamSlot
lbl_0806369c: .4byte 0x0875ff40
lbl_080636a0: .4byte sNonGameplayRamPointer
lbl_080636a4: .4byte 0x08375d4c

    thumb_func_start sub_080636a8
sub_080636a8: @ 0x080636a8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    ldr r1, lbl_08063704 @ =sNonGameplayRamPointer
    mov ip, r1
    ldr r2, [r1]
    mov sb, r2
    mov r7, sb
    adds r7, #0xf0
    cmp r0, #0
    bne lbl_0806370c
    movs r2, #0xe8
    lsls r2, r2, #1
    add r2, sb
    movs r5, #0
    movs r0, #0xf0
    lsls r0, r0, #1
    strh r0, [r2, #2]
    subs r0, #0x80
    strh r0, [r2]
    ldr r0, lbl_08063708 @ =0x08375d20
    movs r4, #3
    ldrb r0, [r0, #0x12]
    ands r0, r4
    ldrb r3, [r2, #0xb]
    movs r1, #4
    rsbs r1, r1, #0
    ands r1, r3
    orrs r1, r0
    ldrb r3, [r2, #0xc]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r4
    strb r0, [r2, #0xc]
    strb r5, [r2, #0xa]
    movs r0, #0x3f
    ands r1, r0
    movs r0, #0x40
    orrs r1, r0
    strb r1, [r2, #0xb]
    b lbl_08063796
    .align 2, 0
lbl_08063704: .4byte sNonGameplayRamPointer
lbl_08063708: .4byte 0x08375d20
lbl_0806370c:
    movs r0, #0xf0
    lsls r0, r0, #1
    strh r0, [r7, #2]
    movs r1, #0xa2
    lsls r1, r1, #1
    mov sl, r1
    mov r2, sl
    strh r2, [r7]
    ldr r0, lbl_080637a8 @ =0x08375d20
    adds r0, #0x22
    movs r1, #3
    ldrb r3, [r0]
    ands r3, r1
    ldrb r0, [r7, #0xb]
    movs r4, #4
    rsbs r4, r4, #0
    adds r1, r4, #0
    ands r1, r0
    orrs r1, r3
    ldrb r2, [r7, #0xc]
    movs r6, #0x10
    rsbs r6, r6, #0
    adds r0, r6, #0
    ands r0, r2
    movs r2, #1
    orrs r0, r2
    strb r0, [r7, #0xc]
    movs r5, #0xd
    rsbs r5, r5, #0
    ands r1, r5
    movs r0, #4
    mov r8, r0
    mov r2, r8
    orrs r1, r2
    strb r1, [r7, #0xb]
    mov r1, ip
    ldr r0, [r1]
    movs r2, #0x88
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #5
    str r3, [sp]
    bl UpdateCutsceneOamDataID
    movs r0, #0xf0
    lsls r0, r0, #1
    strh r0, [r7, #0x22]
    mov r1, sl
    strh r1, [r7, #0x20]
    ldr r2, lbl_080637ac @ =0x0000011b
    add r2, sb
    ldrb r0, [r2]
    ands r4, r0
    ldr r3, [sp]
    orrs r4, r3
    strb r4, [r2]
    movs r1, #0x8e
    lsls r1, r1, #1
    add r1, sb
    ldrb r0, [r1]
    ands r6, r0
    movs r0, #1
    orrs r6, r0
    strb r6, [r1]
    ldrb r0, [r2]
    ands r5, r0
    mov r1, r8
    orrs r5, r1
    strb r5, [r2]
lbl_08063796:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080637a8: .4byte 0x08375d20
lbl_080637ac: .4byte 0x0000011b

    thumb_func_start sub_080637b0
sub_080637b0: @ 0x080637b0
    push {lr}
    adds r2, r0, #0
    ldrh r0, [r2]
    subs r0, #4
    strh r0, [r2]
    movs r1, #0
    ldrsh r0, [r2, r1]
    movs r1, #0x80
    lsls r1, r1, #4
    adds r0, r0, r1
    ldr r1, lbl_080637d8 @ =gBG3VOFS_NonGameplay
    ldrh r1, [r1]
    subs r1, r0, r1
    movs r0, #0x90
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_080637dc
    ldrb r1, [r2, #0xb]
    movs r0, #0x3f
    b lbl_08063802
    .align 2, 0
lbl_080637d8: .4byte gBG3VOFS_NonGameplay
lbl_080637dc:
    movs r0, #0xc0
    lsls r0, r0, #2
    cmp r1, r0
    ble lbl_080637f4
    ldrb r1, [r2, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    bne lbl_08063806
    movs r0, #0x20
    orrs r0, r1
    b lbl_08063804
lbl_080637f4:
    ldrb r1, [r2, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08063806
    movs r0, #0x21
    rsbs r0, r0, #0
lbl_08063802:
    ands r0, r1
lbl_08063804:
    strb r0, [r2, #0xb]
lbl_08063806:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0806380c
sub_0806380c: @ 0x0806380c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    movs r2, #0
    ldr r7, lbl_0806386c @ =sNonGameplayRamPointer
    ldr r6, lbl_08063870 @ =0x0875ff68
    lsrs r1, r0, #0x16
    adds r0, r6, #2
    adds r0, r0, r1
    mov ip, r0
lbl_0806381e:
    ldr r5, [r7]
    lsls r4, r2, #5
    adds r3, r5, r4
    adds r0, r3, #0
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r0, r0, #6
    cmp r0, #0
    bne lbl_08063874
    adds r0, r1, r6
    ldrh r0, [r0]
    adds r2, r3, #0
    adds r2, #0xf2
    strh r0, [r2]
    mov r0, ip
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xf0
    strh r1, [r0]
    adds r0, r4, #0
    adds r0, #0xf0
    adds r0, r5, r0
    movs r1, #1
    bl UpdateCutsceneOamDataID
    ldr r2, [r7]
    adds r2, r2, r4
    adds r2, #0xfc
    ldrb r1, [r2]
    movs r3, #0x10
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r1, r0
    movs r0, #3
    orrs r1, r0
    strb r1, [r2]
    movs r0, #0
    b lbl_0806387c
    .align 2, 0
lbl_0806386c: .4byte sNonGameplayRamPointer
lbl_08063870: .4byte 0x0875ff68
lbl_08063874:
    adds r2, #1
    cmp r2, #5
    ble lbl_0806381e
    movs r0, #1
lbl_0806387c:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ridley_in_space_ship_leaving
ridley_in_space_ship_leaving: @ 0x08063884
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r1, lbl_080638a8 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #4]
    adds r4, r1, #0
    cmp r0, #6
    bls lbl_0806389e
    b lbl_08063ae2
lbl_0806389e:
    lsls r0, r0, #2
    ldr r1, lbl_080638ac @ =lbl_080638b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080638a8: .4byte sNonGameplayRamPointer
lbl_080638ac: .4byte lbl_080638b0
lbl_080638b0: @ jump table
    .4byte lbl_080638cc @ case 0
    .4byte lbl_08063a38 @ case 1
    .4byte lbl_08063a60 @ case 2
    .4byte lbl_08063a74 @ case 3
    .4byte lbl_08063a90 @ case 4
    .4byte lbl_08063ab8 @ case 5
    .4byte lbl_08063acc @ case 6
lbl_080638cc:
    ldr r1, lbl_080639e8 @ =0x0839dcd0
    movs r5, #0xa0
    lsls r5, r5, #0x13
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0xa0
    bl DMATransfer
    movs r4, #0
    strh r4, [r5]
    ldr r0, lbl_080639ec @ =0x083981ec
    ldr r5, lbl_080639f0 @ =0x08386f70
    ldrb r1, [r5]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_080639f4 @ =0x0839fc2c
    ldrb r1, [r5, #1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r1, lbl_080639f8 @ =0x0839dc70
    ldr r2, lbl_080639fc @ =0x05000200
    str r6, [sp]
    movs r0, #3
    movs r3, #0x60
    bl DMATransfer
    ldr r0, lbl_08063a00 @ =0x08396a88
    ldr r1, lbl_08063a04 @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, [r5]
    ldr r1, [r5, #4]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    ldr r4, lbl_08063a08 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    ldr r1, lbl_08063a0c @ =0x0875ff70
    ldrh r0, [r1]
    movs r6, #0x99
    lsls r6, r6, #1
    adds r3, r2, r6
    strh r0, [r3]
    ldrh r1, [r1, #2]
    movs r3, #0x98
    lsls r3, r3, #1
    adds r0, r2, r3
    strh r1, [r0]
    movs r0, #0x9e
    lsls r0, r0, #1
    adds r2, r2, r0
    ldrb r0, [r2]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r4]
    adds r0, r0, r3
    movs r1, #4
    bl UpdateCutsceneOamDataID
    ldr r2, [r4]
    ldrh r0, [r5, #4]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2, #0x1c]
    movs r6, #3
    movs r0, #0
    mov sl, r0
    ldr r1, lbl_08063a10 @ =0x0808c99c
    mov r8, r1
    ldr r7, lbl_08063a14 @ =gFrameCounter8Bit
    movs r4, #0xa8
    lsls r4, r4, #1
    movs r2, #0xff
    mov sb, r2
lbl_08063978:
    ldr r3, lbl_08063a08 @ =sNonGameplayRamPointer
    ldr r0, [r3]
    lsls r1, r6, #5
    adds r0, r0, r1
    adds r0, #0xfd
    mov r2, sl
    strb r2, [r0]
    ldr r5, [r3]
    adds r3, r5, r1
    ldrb r0, [r7]
    ands r0, r6
    add r0, r8
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r1, r3, #0
    adds r1, #0xf2
    strh r0, [r1]
    ldrb r0, [r7]
    adds r0, r0, r6
    mov r1, sb
    ands r0, r1
    add r0, r8
    ldrb r1, [r0]
    lsls r2, r1, #2
    adds r0, r3, #0
    adds r0, #0xf0
    strh r2, [r0]
    adds r1, r2, #0
    ldr r2, lbl_08063a18 @ =0x0000027f
    cmp r1, r2
    bgt lbl_08063a24
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r3, r1
    mov r2, sl
    strh r2, [r0]
    ldrb r0, [r7]
    muls r0, r6, r0
    mov r1, sb
    ands r0, r1
    add r0, r8
    ldrb r1, [r0]
    movs r2, #0x81
    lsls r2, r2, #1
    adds r0, r3, r2
    strh r1, [r0]
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08063a1c
    adds r0, r5, r4
    movs r1, #9
    bl UpdateCutsceneOamDataID
    b lbl_08063a24
    .align 2, 0
lbl_080639e8: .4byte 0x0839dcd0
lbl_080639ec: .4byte 0x083981ec
lbl_080639f0: .4byte 0x08386f70
lbl_080639f4: .4byte 0x0839fc2c
lbl_080639f8: .4byte 0x0839dc70
lbl_080639fc: .4byte 0x05000200
lbl_08063a00: .4byte 0x08396a88
lbl_08063a04: .4byte 0x06010000
lbl_08063a08: .4byte sNonGameplayRamPointer
lbl_08063a0c: .4byte 0x0875ff70
lbl_08063a10: .4byte 0x0808c99c
lbl_08063a14: .4byte gFrameCounter8Bit
lbl_08063a18: .4byte 0x0000027f
lbl_08063a1c:
    adds r0, r5, r4
    movs r1, #0xa
    bl UpdateCutsceneOamDataID
lbl_08063a24:
    adds r4, #0x20
    adds r6, #1
    cmp r6, #0xc
    ble lbl_08063978
    ldr r0, lbl_08063a34 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08063ac0
    .align 2, 0
lbl_08063a34: .4byte sNonGameplayRamPointer
lbl_08063a38:
    ldr r0, [r4]
    ldrh r0, [r0, #2]
    cmp r0, #0x3c
    bls lbl_08063ae2
    ldr r0, lbl_08063a58 @ =0x0000028e
    bl SoundPlay
    ldr r0, [r4]
    ldr r3, lbl_08063a5c @ =0x0000013d
    adds r1, r0, r3
    movs r2, #0
    movs r0, #3
    strb r0, [r1]
    ldr r1, [r4]
    strh r2, [r1, #2]
    b lbl_08063ac4
    .align 2, 0
lbl_08063a58: .4byte 0x0000028e
lbl_08063a5c: .4byte 0x0000013d
lbl_08063a60:
    ldr r1, [r4]
    ldr r6, lbl_08063a70 @ =0x0000013d
    adds r0, r1, r6
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08063ae2
    b lbl_08063ac2
    .align 2, 0
lbl_08063a70: .4byte 0x0000013d
lbl_08063a74:
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #0x78
    bls lbl_08063ae2
    ldr r0, lbl_08063a8c @ =0x0000013d
    adds r1, r1, r0
    movs r2, #0
    movs r0, #0xc
    strb r0, [r1]
    ldr r1, [r4]
    strh r2, [r1, #2]
    b lbl_08063ac4
    .align 2, 0
lbl_08063a8c: .4byte 0x0000013d
lbl_08063a90:
    ldr r2, [r4]
    ldr r1, lbl_08063ab0 @ =0x0000013d
    adds r0, r2, r1
    ldrb r3, [r0]
    cmp r3, #0
    bne lbl_08063ae2
    ldrh r0, [r2, #0x1c]
    ldr r1, lbl_08063ab4 @ =0x0000e0ff
    ands r1, r0
    strh r1, [r2, #0x1c]
    strh r3, [r2, #2]
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_08063ae2
    .align 2, 0
lbl_08063ab0: .4byte 0x0000013d
lbl_08063ab4: .4byte 0x0000e0ff
lbl_08063ab8:
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #0x78
    bls lbl_08063ae2
lbl_08063ac0:
    movs r0, #0
lbl_08063ac2:
    strh r0, [r1, #2]
lbl_08063ac4:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063ae2
lbl_08063acc:
    bl unk_61f0c
    ldr r3, lbl_08063b14 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063ae2:
    bl sub_0806469c
    ldr r0, lbl_08063b18 @ =0x08386f70
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    ldrh r1, [r0]
    adds r1, #2
    strh r1, [r0]
    ldr r0, lbl_08063b14 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x98
    lsls r2, r2, #1
    adds r0, r0, r2
    bl sub_08063b1c
    movs r0, #0
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063b14: .4byte sNonGameplayRamPointer
lbl_08063b18: .4byte 0x08386f70

    thumb_func_start sub_08063b1c
sub_08063b1c: @ 0x08063b1c
    push {lr}
    adds r2, r0, #0
    ldrb r1, [r2, #0xd]
    movs r3, #3
    ands r3, r1
    cmp r3, #0
    beq lbl_08063b98
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08063b46
    ldrh r0, [r2, #2]
    adds r0, #8
    strh r0, [r2, #2]
    lsls r0, r0, #0x10
    movs r1, #0x9c
    lsls r1, r1, #0x13
    cmp r0, r1
    ble lbl_08063b46
    movs r0, #0
    strb r0, [r2, #0xd]
lbl_08063b46:
    ldrb r1, [r2, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08063b6c
    ldrh r0, [r2, #0x18]
    adds r0, #1
    strh r0, [r2, #0x18]
    ldr r1, lbl_08063b8c @ =0x0000fffd
    strh r1, [r2, #0x10]
    ldrh r0, [r2]
    adds r0, r0, r1
    strh r0, [r2]
    lsls r0, r0, #0x10
    ldr r1, lbl_08063b90 @ =0xff900000
    cmp r0, r1
    bge lbl_08063b6c
    movs r0, #0
    strb r0, [r2, #0xd]
lbl_08063b6c:
    ldrb r0, [r2, #0xd]
    cmp r0, #0
    bne lbl_08063bd2
    movs r0, #5
    strb r0, [r2, #0xa]
    ldr r1, lbl_08063b94 @ =gCurrentOamScaling
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    strh r0, [r1]
    movs r0, #0x98
    lsls r0, r0, #3
    strh r0, [r2, #2]
    movs r0, #0x78
    strh r0, [r2]
    b lbl_08063bd2
    .align 2, 0
lbl_08063b8c: .4byte 0x0000fffd
lbl_08063b90: .4byte 0xff900000
lbl_08063b94: .4byte gCurrentOamScaling
lbl_08063b98:
    movs r0, #0xc
    ands r0, r1
    cmp r0, #0
    beq lbl_08063bd2
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08063bae
    ldrh r0, [r2, #2]
    subs r0, #0x10
    strh r0, [r2, #2]
lbl_08063bae:
    strh r3, [r2, #0x10]
    ldr r1, lbl_08063bd8 @ =gCurrentOamScaling
    ldrh r0, [r1]
    ldr r3, lbl_08063bdc @ =0x000001ff
    cmp r0, r3
    bhi lbl_08063bc6
    adds r0, #8
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r3
    bls lbl_08063bd2
lbl_08063bc6:
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    strh r0, [r1]
    movs r0, #0
    strb r0, [r2, #0xd]
lbl_08063bd2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08063bd8: .4byte gCurrentOamScaling
lbl_08063bdc: .4byte 0x000001ff

    thumb_func_start ridley_in_space_ridley_suspicious
ridley_in_space_ridley_suspicious: @ 0x08063be0
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    ldr r1, lbl_08063c04 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    ldrb r0, [r0, #4]
    adds r4, r1, #0
    cmp r0, #5
    bls lbl_08063bf8
    b lbl_08063d7c
lbl_08063bf8:
    lsls r0, r0, #2
    ldr r1, lbl_08063c08 @ =lbl_08063c0c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08063c04: .4byte sNonGameplayRamPointer
lbl_08063c08: .4byte lbl_08063c0c
lbl_08063c0c: @ jump table
    .4byte lbl_08063c24 @ case 0
    .4byte lbl_08063d52 @ case 1
    .4byte lbl_08063d20 @ case 2
    .4byte lbl_08063d36 @ case 3
    .4byte lbl_08063d52 @ case 4
    .4byte lbl_08063d66 @ case 5
lbl_08063c24:
    ldr r1, lbl_08063cf4 @ =0x0839da90
    movs r5, #0xa0
    lsls r5, r5, #0x13
    movs r3, #0xf0
    lsls r3, r3, #1
    movs r0, #0x10
    mov sb, r0
    str r0, [sp]
    movs r0, #3
    adds r2, r5, #0
    bl DMATransfer
    movs r4, #0
    strh r4, [r5]
    ldr r0, lbl_08063cf8 @ =0x0839285c
    ldr r5, lbl_08063cfc @ =0x08386f70
    ldrb r1, [r5, #0x18]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063d00 @ =0x083909b8
    adds r1, r5, #0
    adds r1, #0x20
    ldrb r1, [r1]
    lsls r1, r1, #0xe
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063d04 @ =0x0839ed30
    adds r1, r5, #0
    adds r1, #0x21
    ldrb r1, [r1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063d08 @ =0x0839f1ac
    adds r1, r5, #0
    adds r1, #0x29
    ldrb r1, [r1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063d0c @ =0x0839f628
    ldrb r1, [r5, #0x19]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, [r5, #0x18]
    ldr r1, [r5, #0x1c]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r5, #0x20]
    ldr r1, [r5, #0x24]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r5, #0x28]
    ldr r1, [r5, #0x2c]
    bl CutsceneSetBGCNTPageData
    ldrh r6, [r5, #0x1c]
    movs r4, #0x80
    lsls r4, r4, #4
    movs r0, #3
    adds r1, r6, #0
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    ldrh r3, [r5, #0x24]
    mov r8, r3
    movs r0, #3
    mov r1, r8
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    ldrh r5, [r5, #0x2c]
    movs r0, #3
    adds r1, r5, #0
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    bl CutsceneReset
    ldr r0, lbl_08063d10 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r2, #0
    ldr r0, lbl_08063d14 @ =0x00002c42
    strh r0, [r1, #0x1e]
    ldr r0, lbl_08063d18 @ =gWrittenToBLDALPHA_H
    mov r3, sb
    strh r3, [r0]
    ldr r0, lbl_08063d1c @ =gWrittenToBLDALPHA_L
    strh r2, [r0]
    mov r0, r8
    orrs r6, r0
    orrs r5, r6
    strh r5, [r1, #0x1c]
    strh r2, [r1, #2]
    b lbl_08063d5e
    .align 2, 0
lbl_08063cf4: .4byte 0x0839da90
lbl_08063cf8: .4byte 0x0839285c
lbl_08063cfc: .4byte 0x08386f70
lbl_08063d00: .4byte 0x083909b8
lbl_08063d04: .4byte 0x0839ed30
lbl_08063d08: .4byte 0x0839f1ac
lbl_08063d0c: .4byte 0x0839f628
lbl_08063d10: .4byte sNonGameplayRamPointer
lbl_08063d14: .4byte 0x00002c42
lbl_08063d18: .4byte gWrittenToBLDALPHA_H
lbl_08063d1c: .4byte gWrittenToBLDALPHA_L
lbl_08063d20:
    ldr r0, [r4]
    ldrh r0, [r0, #0x1e]
    movs r1, #2
    str r1, [sp]
    movs r1, #0x10
    movs r2, #0
    movs r3, #2
    bl CutsceneStartBackgroundEffect
    ldr r1, [r4]
    b lbl_08063d5a
lbl_08063d36:
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08063d7c
    movs r0, #0
    strh r0, [r2, #2]
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_08063d7c
lbl_08063d52:
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #0x3c
    bls lbl_08063d7c
lbl_08063d5a:
    movs r0, #0
    strh r0, [r1, #2]
lbl_08063d5e:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063d7c
lbl_08063d66:
    bl unk_61f0c
    ldr r3, lbl_08063d8c @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063d7c:
    movs r0, #0
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063d8c: .4byte sNonGameplayRamPointer

    thumb_func_start ridley_in_space_red_alert
ridley_in_space_red_alert: @ 0x08063d90
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_08063db0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #5
    bls lbl_08063da4
    b lbl_08063f36
lbl_08063da4:
    lsls r0, r0, #2
    ldr r1, lbl_08063db4 @ =lbl_08063db8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08063db0: .4byte sNonGameplayRamPointer
lbl_08063db4: .4byte lbl_08063db8
lbl_08063db8: @ jump table
    .4byte lbl_08063dd0 @ case 0
    .4byte lbl_08063e90 @ case 1
    .4byte lbl_08063eac @ case 2
    .4byte lbl_08063ee4 @ case 3
    .4byte lbl_08063f04 @ case 4
    .4byte lbl_08063f20 @ case 5
lbl_08063dd0:
    ldr r1, lbl_08063e74 @ =0x0839d910
    movs r4, #0xa0
    lsls r4, r4, #0x13
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0xc0
    bl DMATransfer
    movs r0, #0
    strh r0, [r4]
    ldr r0, lbl_08063e78 @ =0x0839e474
    ldr r4, lbl_08063e7c @ =0x08386f70
    ldrb r1, [r4, #9]
    lsls r1, r1, #0xb
    movs r5, #0xc0
    lsls r5, r5, #0x13
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063e80 @ =0x0838c51c
    ldrb r1, [r4, #8]
    lsls r1, r1, #0xe
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063e84 @ =0x083888fc
    ldrb r1, [r4, #0x10]
    lsls r1, r1, #0xe
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08063e88 @ =0x0839dd70
    ldrb r1, [r4, #0x11]
    lsls r1, r1, #0xb
    adds r1, r1, r5
    bl CallLZ77UncompVRAM
    ldr r0, [r4, #8]
    ldr r1, [r4, #0xc]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r4, #0x10]
    ldr r1, [r4, #0x14]
    bl CutsceneSetBGCNTPageData
    ldrh r5, [r4, #0xc]
    movs r0, #0x80
    lsls r0, r0, #4
    mov r8, r0
    movs r0, #1
    adds r1, r5, #0
    mov r2, r8
    bl CutsceneSetBackgroundPosition
    movs r6, #0xa8
    lsls r6, r6, #4
    movs r0, #2
    adds r1, r5, #0
    adds r2, r6, #0
    bl CutsceneSetBackgroundPosition
    ldrh r4, [r4, #0x14]
    movs r0, #1
    adds r1, r4, #0
    mov r2, r8
    bl CutsceneSetBackgroundPosition
    movs r0, #2
    adds r1, r4, #0
    adds r2, r6, #0
    bl CutsceneSetBackgroundPosition
    bl CutsceneReset
    ldr r0, lbl_08063e8c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    orrs r5, r4
    movs r0, #0
    strh r5, [r1, #0x1c]
    b lbl_08063f10
    .align 2, 0
lbl_08063e74: .4byte 0x0839d910
lbl_08063e78: .4byte 0x0839e474
lbl_08063e7c: .4byte 0x08386f70
lbl_08063e80: .4byte 0x0838c51c
lbl_08063e84: .4byte 0x083888fc
lbl_08063e88: .4byte 0x0839dd70
lbl_08063e8c: .4byte sNonGameplayRamPointer
lbl_08063e90:
    ldr r0, lbl_08063ea4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r0, [r1, #2]
    cmp r0, #0x28
    bls lbl_08063f36
    ldr r0, lbl_08063ea8 @ =0x08386fa0
    ldr r0, [r0]
    str r0, [r1, #0xc]
    b lbl_08063f0e
    .align 2, 0
lbl_08063ea4: .4byte sNonGameplayRamPointer
lbl_08063ea8: .4byte 0x08386fa0
lbl_08063eac:
    ldr r7, lbl_08063ed8 @ =sNonGameplayRamPointer
    ldr r0, [r7]
    ldrh r0, [r0, #2]
    cmp r0, #0x3c
    bls lbl_08063f36
    ldr r0, lbl_08063edc @ =0x08386f60
    ldr r4, [r0]
    ldr r5, [r0, #4]
    ldr r6, lbl_08063ee0 @ =0x08386f70
    ldrh r2, [r6, #0xc]
    adds r1, r5, #0
    adds r0, r4, #0
    bl CutsceneStartBackgroundScrolling
    ldrh r2, [r6, #0x14]
    adds r1, r5, #0
    adds r0, r4, #0
    bl CutsceneStartBackgroundScrolling
    ldr r1, [r7]
    b lbl_08063f0e
    .align 2, 0
lbl_08063ed8: .4byte sNonGameplayRamPointer
lbl_08063edc: .4byte 0x08386f60
lbl_08063ee0: .4byte 0x08386f70
lbl_08063ee4:
    ldr r0, lbl_08063efc @ =0x08386f70
    ldrh r0, [r0, #0xc]
    bl CutsceneCheckBackgroundScrollingActive
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_08063f36
    ldr r0, lbl_08063f00 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    strh r2, [r1, #2]
    b lbl_08063f12
    .align 2, 0
lbl_08063efc: .4byte 0x08386f70
lbl_08063f00: .4byte sNonGameplayRamPointer
lbl_08063f04:
    ldr r0, lbl_08063f1c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r0, [r1, #2]
    cmp r0, #0x3c
    bls lbl_08063f36
lbl_08063f0e:
    movs r0, #0
lbl_08063f10:
    strh r0, [r1, #2]
lbl_08063f12:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08063f36
    .align 2, 0
lbl_08063f1c: .4byte sNonGameplayRamPointer
lbl_08063f20:
    bl unk_61f0c
    ldr r3, lbl_08063f50 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08063f36:
    ldr r0, lbl_08063f50 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xc
    bl sub_08063f54
    movs r0, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08063f50: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08063f54
sub_08063f54: @ 0x08063f54
    push {lr}
    sub sp, #4
    adds r2, r0, #0
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08063fa2
    ldrb r0, [r2, #1]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08063f72
    subs r0, #1
    strb r0, [r2, #1]
    b lbl_08063fa2
lbl_08063f72:
    ldrb r0, [r2, #3]
    strb r0, [r2, #1]
    ldrb r0, [r2, #2]
    adds r0, #1
    strb r0, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #9
    bls lbl_08063f86
    strb r1, [r2, #2]
lbl_08063f86:
    ldr r1, lbl_08063fa8 @ =0x08386fa4
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
    ldr r0, lbl_08063fac @ =0x0839d9d0
    adds r1, r1, r0
    ldr r2, lbl_08063fb0 @ =0x050000a0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_08063fa2:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_08063fa8: .4byte 0x08386fa4
lbl_08063fac: .4byte 0x0839d9d0
lbl_08063fb0: .4byte 0x050000a0

    thumb_func_start ridley_in_space_view_of_ship
ridley_in_space_view_of_ship: @ 0x08063fb4
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_08063fd0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #6
    bls lbl_08063fc4
    b lbl_08064112
lbl_08063fc4:
    lsls r0, r0, #2
    ldr r1, lbl_08063fd4 @ =lbl_08063fd8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08063fd0: .4byte sNonGameplayRamPointer
lbl_08063fd4: .4byte lbl_08063fd8
lbl_08063fd8: @ jump table
    .4byte lbl_08063ff4 @ case 0
    .4byte lbl_08064008 @ case 1
    .4byte lbl_08064028 @ case 2
    .4byte lbl_0806404c @ case 3
    .4byte lbl_08064074 @ case 4
    .4byte lbl_080640d4 @ case 5
    .4byte lbl_080640f4 @ case 6
lbl_08063ff4:
    ldr r0, lbl_08064004 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r0, [r1, #2]
    cmp r0, #0x1e
    bhi lbl_08064000
    b lbl_08064112
lbl_08064000:
    b lbl_08064016
    .align 2, 0
lbl_08064004: .4byte sNonGameplayRamPointer
lbl_08064008:
    bl unk_61f44
    cmp r0, #0
    bne lbl_08064012
    b lbl_08064112
lbl_08064012:
    ldr r0, lbl_08064024 @ =sNonGameplayRamPointer
    ldr r1, [r0]
lbl_08064016:
    movs r0, #0
    strh r0, [r1, #2]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08064112
    .align 2, 0
lbl_08064024: .4byte sNonGameplayRamPointer
lbl_08064028:
    ldr r3, lbl_08064048 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrh r0, [r1, #2]
    cmp r0, #0x3c
    bls lbl_08064112
    adds r1, #0xfd
    movs r2, #0
    movs r0, #3
    strb r0, [r1]
    ldr r1, [r3]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    ldr r0, [r3]
    b lbl_08064110
    .align 2, 0
lbl_08064048: .4byte sNonGameplayRamPointer
lbl_0806404c:
    ldr r3, lbl_0806406c @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrh r0, [r1, #2]
    cmp r0, #8
    bls lbl_08064112
    ldr r0, lbl_08064070 @ =0x0000011d
    adds r1, r1, r0
    movs r2, #0
    movs r0, #3
    strb r0, [r1]
    ldr r1, [r3]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    ldr r0, [r3]
    b lbl_08064110
    .align 2, 0
lbl_0806406c: .4byte sNonGameplayRamPointer
lbl_08064070: .4byte 0x0000011d
lbl_08064074:
    ldr r4, lbl_080640c8 @ =sNonGameplayRamPointer
    ldr r3, [r4]
    ldrh r0, [r3, #2]
    cmp r0, #0x78
    bls lbl_08064112
    adds r3, #0xfb
    ldrb r2, [r3]
    movs r1, #0xd
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r2, #4
    orrs r0, r2
    strb r0, [r3]
    ldr r0, [r4]
    ldr r5, lbl_080640cc @ =0x0000011b
    adds r3, r0, r5
    ldrb r0, [r3]
    ands r1, r0
    orrs r1, r2
    strb r1, [r3]
    movs r0, #0xe1
    lsls r0, r0, #6
    movs r1, #1
    str r1, [sp]
    movs r1, #0xe
    movs r2, #0
    movs r3, #0x20
    bl CutsceneStartBackgroundEffect
    ldr r0, [r4]
    ldr r2, lbl_080640d0 @ =0x0000013d
    adds r1, r0, r2
    movs r2, #0
    movs r0, #3
    strb r0, [r1]
    ldr r1, [r4]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    ldr r0, [r4]
    b lbl_08064110
    .align 2, 0
lbl_080640c8: .4byte sNonGameplayRamPointer
lbl_080640cc: .4byte 0x0000011b
lbl_080640d0: .4byte 0x0000013d
lbl_080640d4:
    ldr r3, lbl_080640ec @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldr r5, lbl_080640f0 @ =0x0000013d
    adds r0, r1, r5
    ldrb r2, [r0]
    cmp r2, #0
    bne lbl_08064112
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    ldr r0, [r3]
    b lbl_08064110
    .align 2, 0
lbl_080640ec: .4byte sNonGameplayRamPointer
lbl_080640f0: .4byte 0x0000013d
lbl_080640f4:
    ldr r4, lbl_0806415c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldrh r0, [r0, #2]
    cmp r0, #0x5a
    bls lbl_08064112
    bl unk_61f0c
    ldr r1, [r4]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r4]
    strb r2, [r0, #4]
lbl_08064110:
    strh r2, [r0, #2]
lbl_08064112:
    ldr r4, lbl_0806415c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xf0
    bl sub_0806424c
    ldr r0, [r4]
    movs r1, #0x88
    lsls r1, r1, #1
    adds r0, r0, r1
    bl sub_080641cc
    ldr r0, [r4]
    movs r2, #0x98
    lsls r2, r2, #1
    adds r0, r0, r2
    bl sub_08064168
    bl sub_08064498
    ldr r0, lbl_08064160 @ =gFrameCounter8Bit
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08064152
    ldr r0, lbl_08064164 @ =0x08386f70
    ldrh r0, [r0, #4]
    bl CutsceneGetBGVOFSPointer
    ldrh r1, [r0]
    subs r1, #1
    strh r1, [r0]
lbl_08064152:
    movs r0, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806415c: .4byte sNonGameplayRamPointer
lbl_08064160: .4byte gFrameCounter8Bit
lbl_08064164: .4byte 0x08386f70

    thumb_func_start sub_08064168
sub_08064168: @ 0x08064168
    push {lr}
    adds r3, r0, #0
    ldrb r1, [r3, #0xd]
    movs r2, #2
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806419c
    movs r1, #0
    ldrsh r0, [r3, r1]
    ldrh r1, [r3]
    cmp r0, #0x7f
    bgt lbl_08064186
    strh r2, [r3, #0x10]
    b lbl_0806418a
lbl_08064186:
    movs r0, #1
    strh r0, [r3, #0x10]
lbl_0806418a:
    ldrh r0, [r3, #0x10]
    adds r0, r1, r0
    strh r0, [r3]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0xdf
    ble lbl_0806419c
    movs r0, #0
    strb r0, [r3, #0xd]
lbl_0806419c:
    ldrh r0, [r3, #0x18]
    adds r1, r0, #1
    strh r1, [r3, #0x18]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    bne lbl_080641c2
    ldr r2, lbl_080641c8 @ =0x0875ff80
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x15
    movs r1, #7
    ands r0, r1
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r1, [r3]
    adds r0, r0, r1
    strh r0, [r3]
lbl_080641c2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080641c8: .4byte 0x0875ff80

    thumb_func_start sub_080641cc
sub_080641cc: @ 0x080641cc
    push {r4, lr}
    adds r3, r0, #0
    ldrb r1, [r3, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080641f6
    ldr r0, lbl_08064244 @ =0x0000fffe
    strh r0, [r3, #0xe]
    ldrh r1, [r3, #2]
    adds r1, r1, r0
    strh r1, [r3, #2]
    lsls r1, r1, #0x10
    movs r0, #0xb4
    lsls r0, r0, #0x12
    cmp r1, r0
    bgt lbl_080641f6
    movs r0, #0
    strb r0, [r3, #0xd]
    movs r0, #0
    strh r0, [r3, #0x18]
lbl_080641f6:
    ldrb r1, [r3, #0xd]
    movs r0, #2
    ands r0, r1
    ldrh r2, [r3, #0x18]
    cmp r0, #0
    beq lbl_0806421a
    movs r0, #1
    ands r0, r2
    movs r1, #0
    cmp r0, #0
    beq lbl_08064212
    movs r0, #1
    rsbs r0, r0, #0
    adds r1, r0, #0
lbl_08064212:
    strh r1, [r3, #0x10]
    ldrh r4, [r3]
    adds r0, r1, r4
    strh r0, [r3]
lbl_0806421a:
    adds r1, r2, #1
    strh r1, [r3, #0x18]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0806423e
    ldr r2, lbl_08064248 @ =0x0875ff80
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x14
    movs r1, #7
    ands r0, r1
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r1, [r3]
    adds r0, r0, r1
    strh r0, [r3]
lbl_0806423e:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08064244: .4byte 0x0000fffe
lbl_08064248: .4byte 0x0875ff80

    thumb_func_start sub_0806424c
sub_0806424c: @ 0x0806424c
    push {lr}
    adds r3, r0, #0
    ldrb r1, [r3, #0xd]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08064270
    movs r0, #2
    strh r0, [r3, #0xe]
    ldrh r0, [r3, #2]
    adds r0, #2
    strh r0, [r3, #2]
    lsls r0, r0, #0x10
    ldr r1, lbl_080642b0 @ =0x010f0000
    cmp r0, r1
    ble lbl_08064270
    movs r0, #0
    strb r0, [r3, #0xd]
lbl_08064270:
    ldrb r1, [r3, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08064284
    ldr r1, lbl_080642b4 @ =0x0000ffff
    strh r1, [r3, #0x10]
    ldrh r0, [r3]
    adds r0, r0, r1
    strh r0, [r3]
lbl_08064284:
    ldrh r0, [r3, #0x18]
    adds r1, r0, #1
    strh r1, [r3, #0x18]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_080642aa
    ldr r2, lbl_080642b8 @ =0x0875ff80
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x14
    movs r1, #7
    ands r0, r1
    adds r0, r0, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r1, [r3]
    adds r0, r0, r1
    strh r0, [r3]
lbl_080642aa:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080642b0: .4byte 0x010f0000
lbl_080642b4: .4byte 0x0000ffff
lbl_080642b8: .4byte 0x0875ff80

    thumb_func_start ridley_in_space_cutscene_init
ridley_in_space_cutscene_init: @ 0x080642bc
    push {r4, r5, r6, lr}
    mov r6, sl
    mov r5, sb
    mov r4, r8
    push {r4, r5, r6}
    sub sp, #4
    bl unk_61f0c
    ldr r1, lbl_080643e8 @ =0x0839dcd0
    movs r4, #0xa0
    lsls r4, r4, #0x13
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0xa0
    bl DMATransfer
    movs r0, #0
    mov sb, r0
    strh r0, [r4]
    ldr r0, lbl_080643ec @ =0x083981ec
    ldr r5, lbl_080643f0 @ =0x08386f70
    ldrb r1, [r5]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_080643f4 @ =0x0839fc2c
    ldrb r1, [r5, #1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r1, lbl_080643f8 @ =0x0839d8b0
    ldr r2, lbl_080643fc @ =0x05000200
    str r6, [sp]
    movs r0, #3
    movs r3, #0x60
    bl DMATransfer
    ldr r0, lbl_08064400 @ =0x08387088
    ldr r1, lbl_08064404 @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, [r5]
    ldr r1, [r5, #4]
    bl CutsceneSetBGCNTPageData
    ldrh r5, [r5, #4]
    mov r8, r5
    movs r2, #0x80
    lsls r2, r2, #4
    movs r0, #3
    mov r1, r8
    bl CutsceneSetBackgroundPosition
    bl CutsceneReset
    ldr r0, lbl_08064408 @ =gWrittenToBLDY_NonGameplay
    mov r1, sb
    strh r1, [r0]
    ldr r5, lbl_0806440c @ =sNonGameplayRamPointer
    ldr r2, [r5]
    mov ip, r2
    movs r3, #0
    mov sl, r3
    mov r4, sl
    strh r4, [r2, #0x1e]
    ldr r2, lbl_08064410 @ =0x0875ff74
    ldrh r0, [r2]
    mov r1, ip
    adds r1, #0xf2
    strh r0, [r1]
    ldrh r1, [r2, #2]
    mov r0, ip
    adds r0, #0xf0
    strh r1, [r0]
    ldrh r1, [r2, #4]
    movs r3, #0x89
    lsls r3, r3, #1
    add r3, ip
    strh r1, [r3]
    ldrh r3, [r2, #6]
    movs r6, #0x88
    lsls r6, r6, #1
    mov r4, ip
    adds r1, r4, r6
    strh r3, [r1]
    ldrh r1, [r2, #8]
    movs r3, #0x99
    lsls r3, r3, #1
    add r3, ip
    strh r1, [r3]
    ldrh r2, [r2, #0xa]
    movs r4, #0x98
    lsls r4, r4, #1
    mov r3, ip
    adds r1, r3, r4
    strh r2, [r1]
    movs r1, #1
    bl UpdateCutsceneOamDataID
    ldr r0, [r5]
    adds r0, r0, r6
    movs r1, #2
    bl UpdateCutsceneOamDataID
    ldr r0, [r5]
    adds r0, r0, r4
    movs r1, #3
    bl UpdateCutsceneOamDataID
    movs r0, #0x10
    movs r1, #0
    bl PlayMusic
    ldr r0, lbl_08064414 @ =0x0000028d
    bl SoundPlay
    movs r0, #2
    bl CutsceneStartBackgroundFading
    ldr r1, [r5]
    movs r4, #0x80
    lsls r4, r4, #5
    adds r0, r4, #0
    mov r2, r8
    orrs r2, r0
    strh r2, [r1, #0x1c]
    mov r3, sl
    strh r3, [r1, #2]
    mov r4, sb
    strb r4, [r1, #4]
    ldr r1, [r5]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080643e8: .4byte 0x0839dcd0
lbl_080643ec: .4byte 0x083981ec
lbl_080643f0: .4byte 0x08386f70
lbl_080643f4: .4byte 0x0839fc2c
lbl_080643f8: .4byte 0x0839d8b0
lbl_080643fc: .4byte 0x05000200
lbl_08064400: .4byte 0x08387088
lbl_08064404: .4byte 0x06010000
lbl_08064408: .4byte gWrittenToBLDY_NonGameplay
lbl_0806440c: .4byte sNonGameplayRamPointer
lbl_08064410: .4byte 0x0875ff74
lbl_08064414: .4byte 0x0000028d

    thumb_func_start ridley_in_space_subroutine
ridley_in_space_subroutine: @ 0x08064418
    push {r4, lr}
    ldr r1, lbl_08064444 @ =0x0875ff88
    ldr r0, lbl_08064448 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r0, [r0]
    bl _call_via_r0
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    movs r0, #1
    bl CutsceneUpdateBackgroundsPosition
    bl sub_0806444c
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08064444: .4byte 0x0875ff88
lbl_08064448: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0806444c
sub_0806444c: @ 0x0806444c
    push {lr}
    ldr r1, lbl_08064480 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_08064484 @ =0x0875ff88
    ldr r0, lbl_08064488 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    adds r1, #0xf0
    ldr r2, lbl_0806448c @ =0x08387030
    bl process_cutscene_oam
    bl ResetFreeOAM
    ldr r0, lbl_08064490 @ =gCurrentOamRotation
    ldrh r0, [r0]
    ldr r1, lbl_08064494 @ =gCurrentOamScaling
    ldrh r1, [r1]
    movs r2, #0
    bl CalculateOamPart4
    pop {r0}
    bx r0
    .align 2, 0
lbl_08064480: .4byte gNextOamSlot
lbl_08064484: .4byte 0x0875ff88
lbl_08064488: .4byte sNonGameplayRamPointer
lbl_0806448c: .4byte 0x08387030
lbl_08064490: .4byte gCurrentOamRotation
lbl_08064494: .4byte gCurrentOamScaling

    thumb_func_start sub_08064498
sub_08064498: @ 0x08064498
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r2, lbl_08064568 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldrh r1, [r0, #2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806457a
    movs r6, #3
    mov r8, r2
    ldr r0, lbl_0806456c @ =0x0808c99c
    mov sl, r0
    movs r1, #0xff
    mov sb, r1
lbl_080644bc:
    mov r3, r8
    ldr r0, [r3]
    lsls r7, r6, #5
    adds r1, r0, r7
    adds r0, r1, #0
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r5, r0, #6
    cmp r5, #0
    bne lbl_08064574
    adds r0, r1, #0
    adds r0, #0xfd
    strb r5, [r0]
    ldr r3, [r2]
    adds r0, r3, r7
    mov ip, r0
    ldr r0, lbl_08064570 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    adds r0, r0, r6
    mov r1, sb
    ands r0, r1
    add r0, sl
    ldrb r1, [r0]
    movs r0, #0x53
    ands r0, r1
    lsls r0, r0, #2
    mov r4, ip
    adds r4, #0xf2
    strh r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #1
    add r2, ip
    ldrh r0, [r2]
    adds r0, r0, r6
    mov r1, sb
    ands r0, r1
    add r0, sl
    ldrb r1, [r0]
    movs r0, #0x53
    ands r0, r1
    lsls r0, r0, #2
    mov r1, ip
    adds r1, #0xf0
    strh r0, [r1]
    strh r5, [r2]
    ldrb r1, [r3, #6]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806452c
    ldrh r1, [r4]
    movs r2, #0xf0
    lsls r2, r2, #2
    adds r0, r2, #0
    subs r0, r0, r1
    strh r0, [r4]
lbl_0806452c:
    mov r3, r8
    ldr r2, [r3]
    ldrb r1, [r2, #6]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806454a
    adds r0, r2, r7
    adds r0, #0xf0
    ldrh r2, [r0]
    movs r3, #0xa0
    lsls r3, r3, #2
    adds r1, r3, #0
    subs r1, r1, r2
    strh r1, [r0]
lbl_0806454a:
    adds r1, r7, #0
    adds r1, #0xf0
    mov r2, r8
    ldr r0, [r2]
    adds r0, r0, r1
    movs r1, #6
    bl UpdateCutsceneOamDataID
    mov r3, r8
    ldr r1, [r3]
    ldrb r0, [r1, #6]
    adds r0, #1
    strb r0, [r1, #6]
    b lbl_0806457a
    .align 2, 0
lbl_08064568: .4byte sNonGameplayRamPointer
lbl_0806456c: .4byte 0x0808c99c
lbl_08064570: .4byte gFrameCounter8Bit
lbl_08064574:
    adds r6, #1
    cmp r6, #0x1c
    ble lbl_080644bc
lbl_0806457a:
    movs r6, #3
    ldr r7, lbl_080645d8 @ =sNonGameplayRamPointer
    movs r5, #0xa8
    lsls r5, r5, #1
lbl_08064582:
    ldr r1, [r7]
    lsls r4, r6, #5
    adds r0, r1, r4
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r0, r0, #6
    cmp r0, #0
    beq lbl_080645c0
    adds r0, r1, r5
    bl sub_080645dc
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080645aa
    ldr r0, [r7]
    adds r0, r0, r5
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateCutsceneOamDataID
lbl_080645aa:
    ldr r1, [r7]
    adds r0, r1, r4
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r0, r0, #6
    cmp r0, #0
    bne lbl_080645c0
    adds r0, r1, r5
    movs r1, #0
    bl UpdateCutsceneOamDataID
lbl_080645c0:
    adds r5, #0x20
    adds r6, #1
    cmp r6, #0x1c
    ble lbl_08064582
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080645d8: .4byte sNonGameplayRamPointer

    thumb_func_start sub_080645dc
sub_080645dc: @ 0x080645dc
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    movs r7, #0
    ldrh r1, [r5, #0x14]
    strh r1, [r5, #0x12]
    ldrb r0, [r5, #0xd]
    cmp r0, #0
    bne lbl_0806461e
    movs r1, #2
    ldrsh r0, [r5, r1]
    subs r0, #0x78
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r0
    lsls r1, r1, #4
    strh r1, [r5, #0xe]
    movs r0, #0
    ldrsh r2, [r5, r0]
    subs r2, #0x50
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #3
    adds r0, r0, r2
    lsls r0, r0, #4
    strh r0, [r5, #0x10]
    orrs r1, r0
    lsls r1, r1, #0x10
    cmp r1, #0
    beq lbl_08064684
    movs r0, #1
    strb r0, [r5, #0xd]
    b lbl_0806468c
lbl_0806461e:
    lsls r0, r1, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x63
    bgt lbl_08064684
    cmp r0, #0x19
    beq lbl_08064632
    cmp r0, #0x32
    beq lbl_08064632
    cmp r0, #0x46
    bne lbl_08064634
lbl_08064632:
    movs r7, #8
lbl_08064634:
    movs r1, #0x12
    ldrsh r4, [r5, r1]
    rsbs r4, r4, #0
    adds r4, #0x64
    movs r1, #0xe
    ldrsh r0, [r5, r1]
    adds r1, r4, #0
    bl __divsi3
    adds r6, r0, #0
    movs r1, #0xf0
    lsls r1, r1, #1
    adds r0, r6, r1
    strh r0, [r5, #2]
    movs r1, #0x10
    ldrsh r0, [r5, r1]
    adds r1, r4, #0
    bl __divsi3
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r2, r0, r1
    strh r2, [r5]
    adds r1, #0xc0
    adds r0, r6, r1
    lsls r0, r0, #0x10
    movs r1, #0x80
    lsls r1, r1, #0x13
    cmp r0, r1
    bhi lbl_08064684
    lsls r0, r2, #0x10
    asrs r1, r0, #0x10
    movs r0, #0xa8
    lsls r0, r0, #2
    cmp r1, r0
    bgt lbl_08064684
    movs r0, #0x20
    rsbs r0, r0, #0
    cmp r1, r0
    bge lbl_0806468c
lbl_08064684:
    ldrb r1, [r5, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r5, #0xb]
lbl_0806468c:
    ldrh r0, [r5, #0x14]
    adds r0, #1
    strh r0, [r5, #0x14]
    adds r0, r7, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806469c
sub_0806469c: @ 0x0806469c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r2, lbl_08064734 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldrh r1, [r0, #2]
    movs r0, #1
    ands r0, r1
    adds r3, r2, #0
    cmp r0, #0
    bne lbl_0806474a
    movs r5, #3
    movs r6, #0
lbl_080646b8:
    ldr r0, [r3]
    lsls r4, r5, #5
    adds r1, r0, r4
    adds r0, r1, #0
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r2, r0, #6
    cmp r2, #0
    bne lbl_08064744
    adds r0, r1, #0
    adds r0, #0xfd
    strb r2, [r0]
    ldr r3, [r3]
    mov r8, r3
    mov r0, r8
    adds r0, r0, r4
    mov ip, r0
    mov r1, ip
    adds r1, #0xf2
    ldr r0, lbl_08064738 @ =0x0000ffa8
    strh r0, [r1]
    ldr r0, lbl_0806473c @ =0x0808c99c
    mov sb, r0
    ldr r7, lbl_08064740 @ =gFrameCounter8Bit
    ldrb r0, [r7]
    adds r0, r0, r5
    movs r6, #0xff
    ands r0, r6
    add r0, sb
    ldrb r3, [r0]
    cmp r3, #0x9f
    bgt lbl_0806474a
    lsls r1, r3, #2
    mov r0, ip
    adds r0, #0xf0
    strh r1, [r0]
    movs r0, #0x82
    lsls r0, r0, #1
    add r0, ip
    strh r2, [r0]
    ldrb r0, [r7]
    muls r0, r5, r0
    ands r0, r6
    add r0, sb
    ldrb r1, [r0]
    movs r0, #0x81
    lsls r0, r0, #1
    add r0, ip
    strh r1, [r0]
    movs r0, #1
    ands r1, r0
    movs r3, #0xa
    cmp r1, #0
    beq lbl_08064726
    movs r3, #9
lbl_08064726:
    adds r0, r4, #0
    adds r0, #0xf0
    add r0, r8
    adds r1, r3, #0
    bl UpdateCutsceneOamDataID
    b lbl_0806474a
    .align 2, 0
lbl_08064734: .4byte sNonGameplayRamPointer
lbl_08064738: .4byte 0x0000ffa8
lbl_0806473c: .4byte 0x0808c99c
lbl_08064740: .4byte gFrameCounter8Bit
lbl_08064744:
    adds r5, #1
    cmp r5, #0xe
    ble lbl_080646b8
lbl_0806474a:
    movs r5, #3
    ldr r7, lbl_08064794 @ =sNonGameplayRamPointer
    movs r6, #0xa8
    lsls r6, r6, #1
lbl_08064752:
    ldr r1, [r7]
    lsls r4, r5, #5
    adds r0, r1, r4
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r0, r0, #6
    cmp r0, #0
    beq lbl_0806477e
    adds r0, r1, r6
    bl sub_08064798
    ldr r1, [r7]
    adds r0, r1, r4
    adds r0, #0xfb
    ldrb r0, [r0]
    lsrs r0, r0, #6
    cmp r0, #0
    bne lbl_0806477e
    adds r0, r1, r6
    movs r1, #0
    bl UpdateCutsceneOamDataID
lbl_0806477e:
    adds r6, #0x20
    adds r5, #1
    cmp r5, #0xe
    ble lbl_08064752
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08064794: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08064798
sub_08064798: @ 0x08064798
    push {lr}
    adds r3, r0, #0
    ldrb r1, [r3, #0xd]
    cmp r1, #0
    bne lbl_080647b2
    ldrh r1, [r3, #0x12]
    movs r2, #7
    ands r2, r1
    adds r2, #2
    strh r2, [r3, #0xe]
    movs r1, #1
    strb r1, [r3, #0xd]
    b lbl_080647cc
lbl_080647b2:
    ldrh r1, [r3, #0xe]
    ldrh r2, [r3, #2]
    adds r1, r1, r2
    strh r1, [r3, #2]
    lsls r1, r1, #0x10
    movs r2, #0xf8
    lsls r2, r2, #0x12
    cmp r1, r2
    ble lbl_080647cc
    ldrb r2, [r3, #0xb]
    movs r1, #0x3f
    ands r1, r2
    strb r1, [r3, #0xb]
lbl_080647cc:
    pop {r1}
    bx r1
