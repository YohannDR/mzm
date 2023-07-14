    .include "asm/macros.inc"

    .syntax unified

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
    ldr r0, lbl_0805836c @ =gBg1YPosition
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
lbl_0805836c: .4byte gBg1YPosition
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
    ldr r0, lbl_080583b4 @ =gBg1XPosition
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
lbl_080583b4: .4byte gBg1XPosition
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
    ldr r6, lbl_0805855c @ =gBgPointersAndDimensions
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
lbl_0805855c: .4byte gBgPointersAndDimensions
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
    ldr r0, lbl_080588f0 @ =gBgPointersAndDimensions
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
lbl_080588f0: .4byte gBgPointersAndDimensions
lbl_080588f4: .4byte 0xfffffe80
lbl_080588f8:
    ldr r4, lbl_08058918 @ =0xfffffe80
    adds r0, r2, r4
lbl_080588fc:
    adds r3, r0, r1
lbl_080588fe:
    ldr r2, lbl_0805891c @ =gCamera
    strh r3, [r2, #2]
    ldr r1, lbl_08058920 @ =gBg1YPosition
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
lbl_08058920: .4byte gBg1YPosition
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
    ldr r0, lbl_080589bc @ =gBgPointersAndDimensions
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
lbl_080589bc: .4byte gBgPointersAndDimensions
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
    ldr r1, lbl_080589f0 @ =gBg1XPosition
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
lbl_080589f0: .4byte gBg1XPosition
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
    ldr r1, lbl_08058a50 @ =gBg0XPosition
    ldr r0, lbl_08058a54 @ =gBg1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #1
    strh r0, [r1]
    ldr r1, lbl_08058a58 @ =gBg0YPosition
    ldr r0, lbl_08058a5c @ =gBg1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r6, lbl_08058a60 @ =gEffectYPositionOffset
    b lbl_08058c64
    .align 2, 0
lbl_08058a4c: .4byte gCurrentRoomEntry
lbl_08058a50: .4byte gBg0XPosition
lbl_08058a54: .4byte gBg1XPosition
lbl_08058a58: .4byte gBg0YPosition
lbl_08058a5c: .4byte gBg1YPosition
lbl_08058a60: .4byte gEffectYPositionOffset
lbl_08058a64:
    mov r0, ip
    ldrh r1, [r0, #0x12]
    ldr r0, lbl_08058ab0 @ =0x0000ffff
    cmp r1, r0
    bne lbl_08058a70
    b lbl_08058b80
lbl_08058a70:
    ldr r1, lbl_08058ab4 @ =gBg0XPosition
    ldr r0, lbl_08058ab8 @ =gBg1XPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_08058abc @ =gEffectYPositionOffset
    movs r1, #0
    ldrsh r0, [r2, r1]
    mov r3, ip
    ldrh r3, [r3, #0x12]
    adds r0, r0, r3
    ldr r1, lbl_08058ac0 @ =gBg1YPosition
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
lbl_08058ab4: .4byte gBg0XPosition
lbl_08058ab8: .4byte gBg1XPosition
lbl_08058abc: .4byte gEffectYPositionOffset
lbl_08058ac0: .4byte gBg1YPosition
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
    ldr r1, lbl_08058b7c @ =gBg0YPosition
    rsbs r0, r5, #0
    lsls r0, r0, #2
    b lbl_08058c62
    .align 2, 0
lbl_08058b74: .4byte gIoRegistersBackup
lbl_08058b78: .4byte 0x04000008
lbl_08058b7c: .4byte gBg0YPosition
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
    ldr r0, lbl_08058ba8 @ =gBg0XPosition
    strh r3, [r0]
    ldr r0, lbl_08058bac @ =gBg0YPosition
    strh r3, [r0]
    b lbl_08058c4e
    .align 2, 0
lbl_08058ba8: .4byte gBg0XPosition
lbl_08058bac: .4byte gBg0YPosition
lbl_08058bb0:
    ldr r2, lbl_08058bcc @ =gBg0XPosition
    ldr r0, lbl_08058bd0 @ =gBg1XPosition
    ldrh r0, [r0]
    ldrh r1, [r4]
    subs r0, r0, r1
    strh r0, [r2]
    ldr r2, lbl_08058bd4 @ =gBg0YPosition
    ldr r0, lbl_08058bd8 @ =gBg1YPosition
    ldrh r0, [r0]
    ldrh r1, [r4, #2]
    subs r0, r0, r1
    adds r0, #0x40
    strh r0, [r2]
    b lbl_08058c4e
    .align 2, 0
lbl_08058bcc: .4byte gBg0XPosition
lbl_08058bd0: .4byte gBg1XPosition
lbl_08058bd4: .4byte gBg0YPosition
lbl_08058bd8: .4byte gBg1YPosition
lbl_08058bdc:
    movs r5, #0
    ldr r6, lbl_08058c38 @ =gBg0XPosition
    ldr r0, lbl_08058c3c @ =gBg1XPosition
    ldr r3, lbl_08058c40 @ =gWaitingSpacePiratesPosition
    ldrh r1, [r0]
    ldrh r0, [r3]
    subs r1, r1, r0
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r1, r2
    strh r0, [r6]
    ldr r4, lbl_08058c44 @ =gBg0YPosition
    ldr r0, lbl_08058c48 @ =gBg1YPosition
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
lbl_08058c38: .4byte gBg0XPosition
lbl_08058c3c: .4byte gBg1XPosition
lbl_08058c40: .4byte gWaitingSpacePiratesPosition
lbl_08058c44: .4byte gBg0YPosition
lbl_08058c48: .4byte gBg1YPosition
lbl_08058c4c:
    movs r7, #0
lbl_08058c4e:
    ldr r6, lbl_08058c78 @ =gEffectYPositionOffset
    cmp r7, #0
    bne lbl_08058c64
    ldr r1, lbl_08058c7c @ =gBg0YPosition
    ldr r0, lbl_08058c80 @ =gBg1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058c84 @ =gBg0XPosition
    ldr r0, lbl_08058c88 @ =gBg1XPosition
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
lbl_08058c7c: .4byte gBg0YPosition
lbl_08058c80: .4byte gBg1YPosition
lbl_08058c84: .4byte gBg0XPosition
lbl_08058c88: .4byte gBg1XPosition
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

    thumb_func_start get_Bg3Scrolling_values
get_Bg3Scrolling_values: @ 0x08058d20
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
    bl get_Bg3Scrolling_values
    adds r3, r0, #0
    movs r0, #0xff
    ands r0, r3
    asrs r3, r3, #0x10
    cmp r0, #0
    beq lbl_08058df0
    cmp r0, #1
    bne lbl_08058dc8
    ldr r1, lbl_08058dc0 @ =gBg3XPosition
    ldr r0, lbl_08058dc4 @ =gBg1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058dee
    .align 2, 0
lbl_08058dc0: .4byte gBg3XPosition
lbl_08058dc4: .4byte gBg1XPosition
lbl_08058dc8:
    cmp r0, #2
    bne lbl_08058de0
    ldr r1, lbl_08058dd8 @ =gBg3XPosition
    ldr r0, lbl_08058ddc @ =gBg1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058dee
    .align 2, 0
lbl_08058dd8: .4byte gBg3XPosition
lbl_08058ddc: .4byte gBg1XPosition
lbl_08058de0:
    cmp r0, #3
    bne lbl_08058df0
    ldr r1, lbl_08058e20 @ =gBg3XPosition
    ldr r0, lbl_08058e24 @ =gBg1XPosition
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
    ldr r0, lbl_08058e2c @ =gBgPointersAndDimensions
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
lbl_08058e20: .4byte gBg3XPosition
lbl_08058e24: .4byte gBg1XPosition
lbl_08058e28: .4byte gCurrentRoomEntry
lbl_08058e2c: .4byte gBgPointersAndDimensions
lbl_08058e30: .4byte 0xfffffd80
lbl_08058e34:
    cmp r3, #1
    bne lbl_08058e44
    ldr r0, lbl_08058e40 @ =gBg1YPosition
    ldrh r0, [r0]
    subs r2, r2, r0
    b lbl_08058e4c
    .align 2, 0
lbl_08058e40: .4byte gBg1YPosition
lbl_08058e44:
    ldr r0, lbl_08058e58 @ =gBg1YPosition
    ldrh r0, [r0]
    subs r0, r2, r0
    asrs r2, r0, #2
lbl_08058e4c:
    subs r1, r1, r2
    cmp r1, #0
    ble lbl_08058e60
    ldr r0, lbl_08058e5c @ =gBg3YPosition
    strh r1, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e58: .4byte gBg1YPosition
lbl_08058e5c: .4byte gBg3YPosition
lbl_08058e60:
    ldr r1, lbl_08058e68 @ =gBg3YPosition
    movs r0, #0
    b lbl_08058eb6
    .align 2, 0
lbl_08058e68: .4byte gBg3YPosition
lbl_08058e6c:
    cmp r3, #0
    bne lbl_08058e7c
    ldr r0, lbl_08058e78 @ =gBg3YPosition
    strh r3, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e78: .4byte gBg3YPosition
lbl_08058e7c:
    cmp r3, #1
    bne lbl_08058e94
    ldr r1, lbl_08058e8c @ =gBg3YPosition
    ldr r0, lbl_08058e90 @ =gBg1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058eb6
    .align 2, 0
lbl_08058e8c: .4byte gBg3YPosition
lbl_08058e90: .4byte gBg1YPosition
lbl_08058e94:
    cmp r3, #2
    bne lbl_08058eac
    ldr r1, lbl_08058ea4 @ =gBg3YPosition
    ldr r0, lbl_08058ea8 @ =gBg1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058eb6
    .align 2, 0
lbl_08058ea4: .4byte gBg3YPosition
lbl_08058ea8: .4byte gBg1YPosition
lbl_08058eac:
    ldr r1, lbl_08058ebc @ =gBg3YPosition
    ldr r0, lbl_08058ec0 @ =gBg1YPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058eb6:
    strh r0, [r1]
lbl_08058eb8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058ebc: .4byte gBg3YPosition
lbl_08058ec0: .4byte gBg1YPosition

    thumb_func_start sub_08058ec4
sub_08058ec4: @ 0x08058ec4
    push {lr}
    bl get_Bg3Scrolling_values
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #0
    bne lbl_08058ee0
    ldr r0, lbl_08058edc @ =gBg3XPosition
    strh r1, [r0]
    b lbl_08058f08
    .align 2, 0
lbl_08058edc: .4byte gBg3XPosition
lbl_08058ee0:
    cmp r1, #2
    bne lbl_08058ef8
    ldr r1, lbl_08058ef0 @ =gBg3XPosition
    ldr r0, lbl_08058ef4 @ =gBg1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058f06
    .align 2, 0
lbl_08058ef0: .4byte gBg3XPosition
lbl_08058ef4: .4byte gBg1XPosition
lbl_08058ef8:
    cmp r1, #3
    bne lbl_08058f08
    ldr r1, lbl_08058f0c @ =gBg3XPosition
    ldr r0, lbl_08058f10 @ =gBg1XPosition
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058f06:
    strh r0, [r1]
lbl_08058f08:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058f0c: .4byte gBg3XPosition
lbl_08058f10: .4byte gBg1XPosition

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
    ldr r2, lbl_08058f7c @ =gBg1XPosition
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
lbl_08058f7c: .4byte gBg1XPosition
lbl_08058f80: .4byte gBG2Movement
lbl_08058f84:
    ldr r0, lbl_08058fa8 @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0x14]
    subs r0, #0xf
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058f92
    adds r2, r0, #0
lbl_08058f92:
    ldr r0, lbl_08058fac @ =gBg2XPosition
    strh r2, [r0]
    ldr r1, lbl_08058fb0 @ =gBg1YPosition
    movs r2, #2
    ldrsh r0, [r3, r2]
    ldrh r1, [r1]
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_08058fb4
    movs r2, #0
    b lbl_08058fc2
    .align 2, 0
lbl_08058fa8: .4byte gBgPointersAndDimensions
lbl_08058fac: .4byte gBg2XPosition
lbl_08058fb0: .4byte gBg1YPosition
lbl_08058fb4:
    ldr r0, lbl_08058fc8 @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0x16]
    subs r0, #0xa
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058fc2
    adds r2, r0, #0
lbl_08058fc2:
    ldr r0, lbl_08058fcc @ =gBg2YPosition
    strh r2, [r0]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fc8: .4byte gBgPointersAndDimensions
lbl_08058fcc: .4byte gBg2YPosition
lbl_08058fd0:
    ldr r1, lbl_08058fe4 @ =gBg2XPosition
    ldr r0, lbl_08058fe8 @ =gBg1XPosition
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058fec @ =gBg2YPosition
    ldr r0, lbl_08058ff0 @ =gBg1YPosition
    ldrh r0, [r0]
    strh r0, [r1]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fe4: .4byte gBg2XPosition
lbl_08058fe8: .4byte gBg1XPosition
lbl_08058fec: .4byte gBg2YPosition
lbl_08058ff0: .4byte gBg1YPosition
lbl_08058ff4:
    ldr r0, lbl_08059000 @ =gBg2XPosition
    strh r1, [r0]
    ldr r0, lbl_08059004 @ =gBg2YPosition
    strh r1, [r0]
lbl_08058ffc:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059000: .4byte gBg2XPosition
lbl_08059004: .4byte gBg2YPosition

    thumb_func_start sub_08059008
sub_08059008: @ 0x08059008
    push {r4, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    ldr r0, lbl_0805901c @ =0x000001df
    cmp r1, r0
    bhi lbl_08059024
    ldr r1, lbl_08059020 @ =gBg1XPosition
    movs r0, #0
    b lbl_08059052
    .align 2, 0
lbl_0805901c: .4byte 0x000001df
lbl_08059020: .4byte gBg1XPosition
lbl_08059024:
    ldrh r3, [r4]
    ldr r0, lbl_0805903c @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0xc]
    lsls r2, r0, #6
    ldr r1, lbl_08059040 @ =0xfffffe20
    adds r0, r2, r1
    cmp r3, r0
    ble lbl_0805904c
    ldr r1, lbl_08059044 @ =gBg1XPosition
    ldr r3, lbl_08059048 @ =0xfffffc40
    adds r0, r2, r3
    b lbl_08059052
    .align 2, 0
lbl_0805903c: .4byte gBgPointersAndDimensions
lbl_08059040: .4byte 0xfffffe20
lbl_08059044: .4byte gBg1XPosition
lbl_08059048: .4byte 0xfffffc40
lbl_0805904c:
    ldr r1, lbl_08059064 @ =gBg1XPosition
    ldr r2, lbl_08059068 @ =0xfffffe20
    adds r0, r3, r2
lbl_08059052:
    strh r0, [r1]
    ldrh r1, [r4, #2]
    ldr r0, lbl_0805906c @ =0x0000017f
    cmp r1, r0
    bhi lbl_08059074
    ldr r1, lbl_08059070 @ =gBg1YPosition
    movs r0, #0
    b lbl_0805909e
    .align 2, 0
lbl_08059064: .4byte gBg1XPosition
lbl_08059068: .4byte 0xfffffe20
lbl_0805906c: .4byte 0x0000017f
lbl_08059070: .4byte gBg1YPosition
lbl_08059074:
    ldrh r3, [r4, #2]
    ldr r0, lbl_0805908c @ =gBgPointersAndDimensions
    ldrh r0, [r0, #0xe]
    lsls r2, r0, #6
    adds r0, r2, #0
    subs r0, #0xc0
    cmp r3, r0
    ble lbl_08059098
    ldr r1, lbl_08059090 @ =gBg1YPosition
    ldr r3, lbl_08059094 @ =0xfffffdc0
    adds r0, r2, r3
    b lbl_0805909e
    .align 2, 0
lbl_0805908c: .4byte gBgPointersAndDimensions
lbl_08059090: .4byte gBg1YPosition
lbl_08059094: .4byte 0xfffffdc0
lbl_08059098:
    ldr r1, lbl_080590a8 @ =gBg1YPosition
    ldr r2, lbl_080590ac @ =0xfffffe80
    adds r0, r3, r2
lbl_0805909e:
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080590a8: .4byte gBg1YPosition
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
    bl BlockStoreBrokenReformBlock
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
    bl BgClipSetBg1BlockValue
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl BgClipSetClipdataBlockValue
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
    ldr r2, lbl_08059368 @ =gBgPointersAndDimensions
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
lbl_08059368: .4byte gBgPointersAndDimensions

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
    ldr r2, lbl_080593a4 @ =gBgPointersAndDimensions
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
lbl_080593a4: .4byte gBgPointersAndDimensions

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
    ldr r5, lbl_08059474 @ =gBgPointersAndDimensions
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
lbl_08059474: .4byte gBgPointersAndDimensions
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
    ldr r2, lbl_080595dc @ =gBgPointersAndDimensions
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
lbl_080595dc: .4byte gBgPointersAndDimensions
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
    bl DmaTransfer
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
    bl BgClipSetBg1BlockValue
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl BgClipSetClipdataBlockValue
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
    bl BgClipSetBg1BlockValue
    ldrh r1, [r4, #2]
    ldrh r2, [r4]
    adds r0, r5, #0
    bl BgClipSetClipdataBlockValue
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
    bl BgClipCheckOpeningHatch
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
    bl BgClipSetBg1BlockValue
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
    bl BgClipSetClipdataBlockValue
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
    bl BgClipSetClipdataBlockValue
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
    ldr r1, lbl_08059a98 @ =gBgPointersAndDimensions
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
lbl_08059a98: .4byte gBgPointersAndDimensions

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
    ldr r0, lbl_08059ac8 @ =gBgPointersAndDimensions
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
lbl_08059ac8: .4byte gBgPointersAndDimensions
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
    bl BgClipSetClipdataBlockValue
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
    ldr r2, lbl_08059d90 @ =gBgPointersAndDimensions
    ldrb r1, [r4, #4]
    ldrh r0, [r2, #0xc]
    muls r0, r1, r0
    ldrb r1, [r4, #3]
    adds r0, r0, r1
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    strh r5, [r0]
    ldr r0, lbl_08059d94 @ =gBg1YPosition
    ldrh r0, [r0]
    lsrs r3, r0, #6
    subs r0, r3, #4
    ldrb r2, [r4, #4]
    cmp r0, r2
    bgt lbl_08059d8a
    adds r0, #0x11
    cmp r2, r0
    bgt lbl_08059d8a
    ldr r0, lbl_08059d98 @ =gBg1XPosition
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
lbl_08059d90: .4byte gBgPointersAndDimensions
lbl_08059d94: .4byte gBg1YPosition
lbl_08059d98: .4byte gBg1XPosition
lbl_08059d9c: .4byte 0x06001000
lbl_08059da0: .4byte 0x06001800
lbl_08059da4: .4byte gTilemapAndClipPointers

    thumb_func_start BlockStoreBrokenReformBlock
BlockStoreBrokenReformBlock: @ 0x08059da8
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
    bl BgClipSetBg1BlockValue
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
    ldr r0, lbl_0805a04c @ =gBombChains
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
lbl_0805a04c: .4byte gBombChains
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
    ldr r4, lbl_0805a150 @ =gBombChains
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
    ldr r3, lbl_0805a168 @ =gBgPointersAndDimensions
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
lbl_0805a150: .4byte gBombChains
lbl_0805a154: .4byte gFrameCounter8Bit
lbl_0805a158: .4byte 0x08345c28
lbl_0805a15c: .4byte 0xffff0000
lbl_0805a160: .4byte 0xff00ffff
lbl_0805a164: .4byte 0x0000ffff
lbl_0805a168: .4byte gBgPointersAndDimensions
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
    ldr r3, lbl_0805a1ec @ =gBgPointersAndDimensions
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
lbl_0805a1ec: .4byte gBgPointersAndDimensions
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
    ldr r3, lbl_0805a250 @ =gBgPointersAndDimensions
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
lbl_0805a250: .4byte gBgPointersAndDimensions
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
    ldr r5, lbl_0805a2c8 @ =gBgPointersAndDimensions
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
lbl_0805a2c8: .4byte gBgPointersAndDimensions
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
    ldr r4, lbl_0805a3d8 @ =gBgPointersAndDimensions
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
lbl_0805a3d8: .4byte gBgPointersAndDimensions
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
    ldr r2, lbl_0805a46c @ =gBgPointersAndDimensions
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
    ldr r0, lbl_0805a470 @ =gBg1YPosition
    ldrh r0, [r0]
    lsrs r1, r0, #6
    subs r0, r1, #4
    cmp r0, r4
    bgt lbl_0805a466
    adds r0, #0x11
    cmp r4, r0
    bgt lbl_0805a466
    ldr r0, lbl_0805a474 @ =gBg1XPosition
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
lbl_0805a46c: .4byte gBgPointersAndDimensions
lbl_0805a470: .4byte gBg1YPosition
lbl_0805a474: .4byte gBg1XPosition
lbl_0805a478: .4byte 0x06001000
lbl_0805a47c: .4byte 0x06001800
lbl_0805a480: .4byte gTilemapAndClipPointers
