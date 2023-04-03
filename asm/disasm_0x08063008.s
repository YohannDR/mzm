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
