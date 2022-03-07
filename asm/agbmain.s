    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start agbmain
agbmain: @ 0x0800023c
    push {lr}
    bl init_game
    b lbl_08000678
lbl_08000244:
    bl update_input
    bl check_softreset
    ldr r1, lbl_08000274 @ =0x03000c77
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, lbl_08000278 @ =0x03000002
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r0, lbl_0800027c @ =0x03000c70
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #0x10
    bls lbl_08000268
    b lbl_0800065a
lbl_08000268:
    lsls r0, r0, #2
    ldr r1, lbl_08000280 @ =lbl_08000284
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08000274: .4byte 0x03000c77
lbl_08000278: .4byte 0x03000002
lbl_0800027c: .4byte 0x03000c70
lbl_08000280: .4byte lbl_08000284
lbl_08000284: @ jump table
    .4byte lbl_080002c8 @ case 0
    .4byte lbl_080002e0 @ case 1
    .4byte lbl_080002f8 @ case 2
    .4byte lbl_08000358 @ case 3
    .4byte lbl_080003cc @ case 4
    .4byte lbl_08000434 @ case 5
    .4byte lbl_080004c0 @ case 6
    .4byte lbl_080004dc @ case 7
    .4byte lbl_080004fc @ case 8
    .4byte lbl_0800051c @ case 9
    .4byte lbl_08000548 @ case 10
    .4byte lbl_0800057c @ case 11
    .4byte lbl_080005f4 @ case 12
    .4byte lbl_080005fa @ case 13
    .4byte lbl_08000618 @ case 14
    .4byte lbl_0800061e @ case 15
    .4byte lbl_08000658 @ case 16
lbl_080002c8:
    bl sub_0807ef9c
    cmp r0, #0
    bne lbl_080002d2
    b lbl_0800065a
lbl_080002d2:
    ldr r1, lbl_080002dc @ =0x03000c70
    movs r0, #1
    strh r0, [r1]
    b lbl_080004b4
    .align 2, 0
lbl_080002dc: .4byte 0x03000c70
lbl_080002e0:
    bl intro_subroutine
    cmp r0, #0
    bne lbl_080002ea
    b lbl_0800065a
lbl_080002ea:
    ldr r1, lbl_080002f4 @ =0x03000c70
    movs r0, #2
    strh r0, [r1]
    b lbl_080004b4
    .align 2, 0
lbl_080002f4: .4byte 0x03000c70
lbl_080002f8:
    bl title_screen_subroutine
    cmp r0, #0
    bne lbl_08000302
    b lbl_0800065a
lbl_08000302:
    ldr r0, lbl_08000314 @ =0x03000c74
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0800031c
    ldr r1, lbl_08000318 @ =0x03000c70
    movs r0, #3
    b lbl_08000334
    .align 2, 0
lbl_08000314: .4byte 0x03000c74
lbl_08000318: .4byte 0x03000c70
lbl_0800031c:
    cmp r0, #2
    bne lbl_08000330
    bl start_new_demo
    ldr r1, lbl_0800032c @ =0x03000c70
    movs r0, #0xb
    b lbl_08000334
    .align 2, 0
lbl_0800032c: .4byte 0x03000c70
lbl_08000330:
    ldr r1, lbl_08000348 @ =0x03000c70
    movs r0, #1
lbl_08000334:
    strh r0, [r1]
    ldr r0, lbl_0800034c @ =0x03000c72
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_08000350 @ =0x03000bf0
    strb r1, [r0]
    ldr r0, lbl_08000354 @ =0x03000c74
    strb r1, [r0]
    b lbl_0800065a
    .align 2, 0
lbl_08000348: .4byte 0x03000c70
lbl_0800034c: .4byte 0x03000c72
lbl_08000350: .4byte 0x03000bf0
lbl_08000354: .4byte 0x03000c74
lbl_08000358:
    bl file_select_menu_subroutine
    cmp r0, #0
    bne lbl_08000362
    b lbl_0800065a
lbl_08000362:
    ldr r0, lbl_08000374 @ =0x03000c74
    movs r1, #0
    ldrsb r1, [r0, r1]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_0800037c
    ldr r1, lbl_08000378 @ =0x03000c70
    movs r0, #4
    b lbl_080003b0
    .align 2, 0
lbl_08000374: .4byte 0x03000c74
lbl_08000378: .4byte 0x03000c70
lbl_0800037c:
    cmp r1, #2
    bne lbl_0800038c
    ldr r1, lbl_08000388 @ =0x03000c70
    movs r0, #4
    b lbl_080003b0
    .align 2, 0
lbl_08000388: .4byte 0x03000c70
lbl_0800038c:
    cmp r1, #4
    bne lbl_0800039c
    ldr r1, lbl_08000398 @ =0x03000c70
    movs r0, #0xd
    b lbl_080003b0
    .align 2, 0
lbl_08000398: .4byte 0x03000c70
lbl_0800039c:
    cmp r1, #5
    bne lbl_080003ac
    ldr r1, lbl_080003a8 @ =0x03000c70
    movs r0, #0xc
    b lbl_080003b0
    .align 2, 0
lbl_080003a8: .4byte 0x03000c70
lbl_080003ac:
    ldr r1, lbl_080003c0 @ =0x03000c70
    movs r0, #1
lbl_080003b0:
    strh r0, [r1]
    ldr r0, lbl_080003c4 @ =0x03000c72
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_080003c8 @ =0x03000c75
    strb r1, [r0]
    strb r1, [r2]
    b lbl_0800065a
    .align 2, 0
lbl_080003c0: .4byte 0x03000c70
lbl_080003c4: .4byte 0x03000c72
lbl_080003c8: .4byte 0x03000c75
lbl_080003cc:
    bl ingame_main
    cmp r0, #0
    bne lbl_080003d6
    b lbl_0800065a
lbl_080003d6:
    ldr r0, lbl_080003f8 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_080003e4
    b lbl_080005e8
lbl_080003e4:
    ldr r0, lbl_080003fc @ =0x0300007d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08000404
    ldr r1, lbl_08000400 @ =0x03000c70
    movs r0, #0xa
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_080003f8: .4byte 0x03000bf0
lbl_080003fc: .4byte 0x0300007d
lbl_08000400: .4byte 0x03000c70
lbl_08000404:
    ldr r0, lbl_08000418 @ =0x0300007e
    movs r2, #0
    ldrsb r2, [r0, r2]
    cmp r2, #0
    beq lbl_08000420
    ldr r1, lbl_0800041c @ =0x03000c70
    movs r0, #9
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_08000418: .4byte 0x0300007e
lbl_0800041c: .4byte 0x03000c70
lbl_08000420:
    ldr r0, lbl_0800042c @ =0x03000c70
    movs r1, #2
    strh r1, [r0]
    ldr r0, lbl_08000430 @ =0x03000c72
    strh r2, [r0]
    b lbl_0800065a
    .align 2, 0
lbl_0800042c: .4byte 0x03000c70
lbl_08000430: .4byte 0x03000c72
lbl_08000434:
    bl map_screen_subroutine
    cmp r0, #0
    bne lbl_0800043e
    b lbl_0800065a
lbl_0800043e:
    ldr r1, lbl_08000468 @ =0x03000c70
    ldr r2, lbl_0800046c @ =0x03000c74
    movs r0, #0
    ldrsb r0, [r2, r0]
    strh r0, [r1]
    movs r0, #0
    strb r0, [r2]
    ldr r1, lbl_08000470 @ =0x03000bf0
    ldrb r0, [r1]
    subs r0, #1
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r3, r1, #0
    cmp r0, #8
    bhi lbl_080004b4
    lsls r0, r0, #2
    ldr r1, lbl_08000474 @ =lbl_08000478
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08000468: .4byte 0x03000c70
lbl_0800046c: .4byte 0x03000c74
lbl_08000470: .4byte 0x03000bf0
lbl_08000474: .4byte lbl_08000478
lbl_08000478: @ jump table
    .4byte lbl_0800049c @ case 0
    .4byte lbl_080004b4 @ case 1
    .4byte lbl_080004b4 @ case 2
    .4byte lbl_080004b4 @ case 3
    .4byte lbl_080004b4 @ case 4
    .4byte lbl_080004b4 @ case 5
    .4byte lbl_080004a2 @ case 6
    .4byte lbl_080004b4 @ case 7
    .4byte lbl_080004ac @ case 8
lbl_0800049c:
    ldr r1, lbl_080004a8 @ =0x03000c75
    movs r0, #0
    strb r0, [r1]
lbl_080004a2:
    movs r0, #0
    strb r0, [r3]
    b lbl_080004b4
    .align 2, 0
lbl_080004a8: .4byte 0x03000c75
lbl_080004ac:
    movs r0, #0
    strb r0, [r3]
    movs r0, #1
    strb r0, [r2]
lbl_080004b4:
    ldr r1, lbl_080004bc @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_080004bc: .4byte 0x03000c72
lbl_080004c0:
    bl game_over_menu_subroutine
    cmp r0, #0
    bne lbl_080004ca
    b lbl_0800065a
lbl_080004ca:
    ldr r1, lbl_080004d4 @ =0x03000c70
    ldr r2, lbl_080004d8 @ =0x03000c74
    movs r0, #0
    ldrsb r0, [r2, r0]
    b lbl_08000644
    .align 2, 0
lbl_080004d4: .4byte 0x03000c70
lbl_080004d8: .4byte 0x03000c74
lbl_080004dc:
    bl chozodia_escape_subroutine
    cmp r0, #0
    bne lbl_080004e6
    b lbl_0800065a
lbl_080004e6:
    ldr r1, lbl_080004f4 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_080004f8 @ =0x03000c70
    movs r0, #8
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_080004f4: .4byte 0x03000c72
lbl_080004f8: .4byte 0x03000c70
lbl_080004fc:
    bl credits_subroutine
    cmp r0, #0
    bne lbl_08000506
    b lbl_0800065a
lbl_08000506:
    ldr r1, lbl_08000514 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_08000518 @ =0x03000c70
    movs r0, #1
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_08000514: .4byte 0x03000c72
lbl_08000518: .4byte 0x03000c70
lbl_0800051c:
    bl tourian_escape_subroutine
    cmp r0, #0
    bne lbl_08000526
    b lbl_0800065a
lbl_08000526:
    ldr r1, lbl_0800053c @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_08000540 @ =0x03000c70
    ldr r0, lbl_08000544 @ =0x03000c74
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_0800053c: .4byte 0x03000c72
lbl_08000540: .4byte 0x03000c70
lbl_08000544: .4byte 0x03000c74
lbl_08000548:
    bl cutscene_subroutine
    cmp r0, #0
    bne lbl_08000552
    b lbl_0800065a
lbl_08000552:
    ldr r1, lbl_08000570 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_08000574 @ =0x03000bf0
    ldrb r0, [r0]
    subs r0, #7
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_080005e8
    ldr r1, lbl_08000578 @ =0x03000c70
    movs r0, #4
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_08000570: .4byte 0x03000c72
lbl_08000574: .4byte 0x03000bf0
lbl_08000578: .4byte 0x03000c70
lbl_0800057c:
    bl ingame_main
    cmp r0, #0
    beq lbl_0800065a
    ldr r2, lbl_080005bc @ =0x03000bf0
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r0, #2
    bne lbl_080005e8
    movs r1, #0
    strb r1, [r2]
    ldr r0, lbl_080005c0 @ =0x03000c75
    strb r1, [r0]
    ldr r1, lbl_080005c4 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_080005c8 @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080005d8
    ldr r1, lbl_080005cc @ =0x03000c70
    ldr r2, lbl_080005d0 @ =0x03000c74
    movs r0, #0
    ldrsb r0, [r2, r0]
    strh r0, [r1]
    ldr r0, lbl_080005d4 @ =0x03000038
    ldr r0, [r0]
    lsls r0, r0, #4
    lsrs r0, r0, #0x1c
    strb r0, [r2]
    b lbl_0800065a
    .align 2, 0
lbl_080005bc: .4byte 0x03000bf0
lbl_080005c0: .4byte 0x03000c75
lbl_080005c4: .4byte 0x03000c72
lbl_080005c8: .4byte 0x030013d2
lbl_080005cc: .4byte 0x03000c70
lbl_080005d0: .4byte 0x03000c74
lbl_080005d4: .4byte 0x03000038
lbl_080005d8:
    bl start_new_demo
    ldr r1, lbl_080005e4 @ =0x03000c70
    movs r0, #0xb
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_080005e4: .4byte 0x03000c70
lbl_080005e8:
    ldr r1, lbl_080005f0 @ =0x03000c70
    movs r0, #5
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_080005f0: .4byte 0x03000c70
lbl_080005f4:
    bl gallery_subroutine
    b lbl_080005fe
lbl_080005fa:
    bl fusion_gallery_subroutine
lbl_080005fe:
    cmp r0, #0
    beq lbl_0800065a
    ldr r1, lbl_08000610 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_08000614 @ =0x03000c70
    movs r0, #3
    strh r0, [r1]
    b lbl_0800065a
    .align 2, 0
lbl_08000610: .4byte 0x03000c72
lbl_08000614: .4byte 0x03000c70
lbl_08000618:
    bl softreset
    b lbl_0800065a
lbl_0800061e:
    bl erase_sram_menu_subroutine
    cmp r0, #0
    beq lbl_0800065a
    ldr r0, lbl_08000638 @ =0x03000c74
    movs r1, #0
    ldrsb r1, [r0, r1]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08000640
    ldr r0, lbl_0800063c @ =0x0300003c
    strb r1, [r0]
    b lbl_08000646
    .align 2, 0
lbl_08000638: .4byte 0x03000c74
lbl_0800063c: .4byte 0x0300003c
lbl_08000640:
    ldr r1, lbl_08000650 @ =0x03000c70
    movs r0, #0
lbl_08000644:
    strh r0, [r1]
lbl_08000646:
    ldr r1, lbl_08000654 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    strb r0, [r2]
    b lbl_0800065a
    .align 2, 0
lbl_08000650: .4byte 0x03000c70
lbl_08000654: .4byte 0x03000c72
lbl_08000658:
    b lbl_08000658
lbl_0800065a:
    ldr r2, lbl_08000690 @ =0x03000c78
    ldrh r1, [r2]
    ldr r0, lbl_08000694 @ =0x0000fffe
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_08000698 @ =0x03000c76
    movs r0, #1
    strb r0, [r1]
    movs r3, #1
lbl_0800066c:
    svc #2
    ldrh r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0800066c
lbl_08000678:
    ldr r1, lbl_08000698 @ =0x03000c76
    movs r0, #0
    strb r0, [r1]
    bl sub_08004d48
    ldr r0, lbl_0800069c @ =0x0300003c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800068c
    b lbl_08000244
lbl_0800068c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08000690: .4byte 0x03000c78
lbl_08000694: .4byte 0x0000fffe
lbl_08000698: .4byte 0x03000c76
lbl_0800069c: .4byte 0x0300003c
