    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_08078228
sub_08078228: @ 0x08078228
    push {lr}
    ldr r0, lbl_08078248 @ =gStereoFlag
    ldrb r1, [r0]
    cmp r1, #1
    bhi lbl_08078242
    movs r0, #0x80
    lsls r0, r0, #0x11
    cmp r1, #0
    beq lbl_0807823e
    movs r0, #0x80
    lsls r0, r0, #0x12
lbl_0807823e:
    bl DoSoundAction
lbl_08078242:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08078248: .4byte gStereoFlag

    thumb_func_start file_select_menu_process_oam
file_select_menu_process_oam: @ 0x0807824c
    push {lr}
    ldr r0, lbl_08078278 @ =gNextOamSlot
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_0807827c @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #0
    blt lbl_08078266
    cmp r0, #8
    ble lbl_08078266
    cmp r0, #0xb
    ble lbl_08078288
lbl_08078266:
    ldr r0, lbl_08078280 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x74
    ldr r2, lbl_08078284 @ =0x0845f1dc
    movs r0, #0xf
    bl process_menu_oam
    b lbl_0807829a
    .align 2, 0
lbl_08078278: .4byte gNextOamSlot
lbl_0807827c: .4byte gGameModeSub1
lbl_08078280: .4byte sNonGameplayRamPointer
lbl_08078284: .4byte 0x0845f1dc
lbl_08078288:
    ldr r0, lbl_080782a4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r1, r0
    ldr r2, lbl_080782a8 @ =0x0845f31c
    movs r0, #0xb
    bl process_menu_oam
lbl_0807829a:
    bl ResetFreeOAM
    pop {r0}
    bx r0
    .align 2, 0
lbl_080782a4: .4byte sNonGameplayRamPointer
lbl_080782a8: .4byte 0x0845f31c

    thumb_func_start sub_080782ac
sub_080782ac: @ 0x080782ac
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080784e0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x74
    mov sb, r0
    ldr r4, lbl_080784e4 @ =0x08760b40
    ldr r0, lbl_080784e8 @ =0x0845f1bc
    mov r8, r0
    mov r2, sb
    movs r3, #0xe
lbl_080782c6:
    adds r0, r2, #0
    mov r1, r8
    ldm r1!, {r5, r6, r7}
    stm r0!, {r5, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
    adds r2, #0x10
    subs r3, #1
    cmp r3, #0
    bge lbl_080782c6
    ldrh r0, [r4]
    mov r1, sb
    adds r1, #0x82
    strh r0, [r1]
    ldrh r1, [r4, #2]
    mov r0, sb
    adds r0, #0x80
    strh r1, [r0]
    ldrb r1, [r4, #4]
    bl UpdateMenuOamDataID
    mov r0, sb
    adds r0, #0x90
    ldrh r1, [r4, #8]
    strh r1, [r0, #2]
    ldrh r1, [r4, #0xa]
    strh r1, [r0]
    ldrb r1, [r4, #0xc]
    bl UpdateMenuOamDataID
    mov r0, sb
    adds r0, #0xa0
    ldrh r1, [r4, #0x10]
    strh r1, [r0, #2]
    ldrh r1, [r4, #0x12]
    strh r1, [r0]
    ldrb r1, [r4, #0x14]
    bl UpdateMenuOamDataID
    ldr r6, lbl_080784e0 @ =sNonGameplayRamPointer
    ldr r1, [r6]
    movs r0, #0x98
    lsls r0, r0, #1
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r3, #0x10
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r2
    movs r5, #1
    orrs r0, r5
    strb r0, [r1]
    ldr r0, [r6]
    ldr r1, lbl_080784ec @ =0x0000012f
    adds r2, r0, r1
    ldrb r1, [r2]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r6]
    adds r1, #0xc0
    ldrb r2, [r1]
    adds r0, r3, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0xbf
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x80
    ldrb r2, [r1]
    adds r0, r3, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x90
    ldrb r2, [r1]
    adds r0, r3, #0
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r6]
    adds r0, #0xa0
    ldrb r1, [r0]
    ands r3, r1
    strb r3, [r0]
    ldr r1, [r6]
    adds r1, #0x7f
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r6]
    adds r1, #0x8f
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r6]
    adds r0, #0x9f
    ldrb r1, [r0]
    ands r4, r1
    strb r4, [r0]
    ldr r1, [r6]
    ldr r7, lbl_080784f0 @ =0x0000013f
    adds r1, r1, r7
    ldrb r0, [r1]
    movs r2, #3
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r6]
    ldr r4, lbl_080784f4 @ =0x0000014f
    adds r1, r1, r4
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r6]
    ldr r5, lbl_080784f8 @ =0x0000015f
    adds r1, r1, r5
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r6]
    movs r2, #0x9f
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #0x21
    strb r1, [r0]
    ldr r0, [r6]
    movs r3, #0xa7
    lsls r3, r3, #1
    adds r0, r0, r3
    strb r1, [r0]
    ldr r0, [r6]
    adds r2, #0x20
    adds r0, r0, r2
    strb r1, [r0]
    ldr r3, lbl_080784fc @ =gSaveFilesInfo
    movs r0, #0x11
    ldrsb r0, [r3, r0]
    cmp r0, #0
    beq lbl_08078402
    ldr r0, [r6]
    adds r1, r7, #0
    adds r2, r0, r1
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_08078402:
    adds r0, r3, #0
    adds r0, #0x29
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08078420
    ldr r2, [r6]
    adds r2, r2, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_08078420:
    adds r0, r3, #0
    adds r0, #0x41
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807843e
    ldr r2, [r6]
    adds r2, r2, r5
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_0807843e:
    ldrb r0, [r3, #1]
    cmp r0, #0
    beq lbl_08078450
    ldr r0, [r6]
    adds r0, r0, r7
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_08078450:
    ldrb r0, [r3, #0x19]
    cmp r0, #0
    beq lbl_08078462
    ldr r0, [r6]
    adds r0, r0, r4
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_08078462:
    adds r0, r3, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08078478
    ldr r0, [r6]
    adds r0, r0, r5
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_08078478:
    ldr r2, [r6]
    movs r3, #0x9b
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r0, #0xe0
    lsls r0, r0, #2
    strh r0, [r1]
    movs r5, #0xa3
    lsls r5, r5, #1
    adds r1, r2, r5
    strh r0, [r1]
    movs r6, #0xab
    lsls r6, r6, #1
    adds r1, r2, r6
    strh r0, [r1]
    movs r7, #0x9a
    lsls r7, r7, #1
    adds r1, r2, r7
    movs r0, #0x80
    strh r0, [r1]
    adds r0, #0xc4
    adds r1, r2, r0
    movs r0, #0xe0
    strh r0, [r1]
    adds r3, #0x1e
    adds r1, r2, r3
    adds r0, #0x60
    strh r0, [r1]
    mov r4, r8
    adds r5, #0x6e
    adds r2, r2, r5
    movs r3, #0xa
lbl_080784b8:
    adds r0, r2, #0
    adds r1, r4, #0
    ldm r1!, {r5, r6, r7}
    stm r0!, {r5, r6, r7}
    ldr r1, [r1]
    str r1, [r0]
    adds r2, #0x10
    subs r3, #1
    cmp r3, #0
    bge lbl_080784b8
    ldr r0, lbl_08078500 @ =0x0000ffff
    bl sub_08078ca0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080784e0: .4byte sNonGameplayRamPointer
lbl_080784e4: .4byte 0x08760b40
lbl_080784e8: .4byte 0x0845f1bc
lbl_080784ec: .4byte 0x0000012f
lbl_080784f0: .4byte 0x0000013f
lbl_080784f4: .4byte 0x0000014f
lbl_080784f8: .4byte 0x0000015f
lbl_080784fc: .4byte gSaveFilesInfo
lbl_08078500: .4byte 0x0000ffff

    thumb_func_start sub_08078504
sub_08078504: @ 0x08078504
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    cmp r5, #2
    bhi lbl_08078524
    ldr r1, lbl_08078520 @ =gSaveFilesInfo
    lsls r0, r5, #1
    adds r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r3, [r0, #0xc]
    b lbl_08078526
    .align 2, 0
lbl_08078520: .4byte gSaveFilesInfo
lbl_08078524:
    movs r3, #0
lbl_08078526:
    ldr r0, lbl_08078544 @ =0x08760b40
    lsls r2, r5, #3
    adds r1, r3, r2
    adds r0, #5
    adds r1, r1, r0
    ldrb r3, [r1]
    adds r6, r2, #0
    cmp r4, #8
    bls lbl_0807853a
    b lbl_08078746
lbl_0807853a:
    lsls r0, r4, #2
    ldr r1, lbl_08078548 @ =lbl_0807854c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08078544: .4byte 0x08760b40
lbl_08078548: .4byte lbl_0807854c
lbl_0807854c: @ jump table
    .4byte lbl_08078570 @ case 0
    .4byte lbl_08078572 @ case 1
    .4byte lbl_080785f8 @ case 2
    .4byte lbl_08078746 @ case 3
    .4byte lbl_08078746 @ case 4
    .4byte lbl_08078608 @ case 5
    .4byte lbl_080786a8 @ case 6
    .4byte lbl_08078724 @ case 7
    .4byte lbl_0807873c @ case 8
lbl_08078570:
    adds r3, #1
lbl_08078572:
    ldr r4, lbl_080785b4 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xe4
    lsls r1, r3, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r2, [r4]
    ldr r4, lbl_080785b8 @ =0x08760b40
    adds r1, r6, r4
    ldrh r0, [r1]
    adds r3, r2, #0
    adds r3, #0xe6
    strh r0, [r3]
    ldrh r1, [r1, #2]
    adds r0, r2, #0
    adds r0, #0xe4
    strh r1, [r0]
    movs r3, #0x10
    cmp r5, #0
    beq lbl_0807859e
    ldrb r3, [r4, #4]
lbl_0807859e:
    adds r0, r2, #0
    adds r0, #0xf4
    lsls r1, r3, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    cmp r5, #1
    beq lbl_080785bc
    ldrb r3, [r4, #0xc]
    b lbl_080785be
    .align 2, 0
lbl_080785b4: .4byte sNonGameplayRamPointer
lbl_080785b8: .4byte 0x08760b40
lbl_080785bc:
    movs r3, #0x11
lbl_080785be:
    ldr r0, lbl_080785dc @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r0, r1
    lsls r1, r3, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    cmp r5, #2
    beq lbl_080785e4
    ldr r0, lbl_080785e0 @ =0x08760b40
    ldrb r3, [r0, #0x14]
    b lbl_080785e6
    .align 2, 0
lbl_080785dc: .4byte sNonGameplayRamPointer
lbl_080785e0: .4byte 0x08760b40
lbl_080785e4:
    movs r3, #0x12
lbl_080785e6:
    ldr r0, lbl_080785f4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r4, #0x8a
    lsls r4, r4, #1
    adds r0, r0, r4
    lsls r1, r3, #0x18
    b lbl_0807872e
    .align 2, 0
lbl_080785f4: .4byte sNonGameplayRamPointer
lbl_080785f8:
    ldr r0, lbl_08078604 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe4
    adds r1, r3, #2
    b lbl_0807872c
    .align 2, 0
lbl_08078604: .4byte sNonGameplayRamPointer
lbl_08078608:
    ldr r4, lbl_08078690 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xe4
    adds r1, r3, #2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    cmp r5, #0
    beq lbl_0807863e
    ldr r2, [r4]
    adds r2, #0xff
    ldrb r3, [r2]
    movs r1, #0xd
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r3
    movs r3, #4
    orrs r0, r3
    strb r0, [r2]
    ldr r0, [r4]
    ldr r6, lbl_08078694 @ =0x0000013f
    adds r2, r0, r6
    ldrb r0, [r2]
    ands r1, r0
    orrs r1, r3
    strb r1, [r2]
lbl_0807863e:
    cmp r5, #1
    beq lbl_08078666
    ldr r0, [r4]
    ldr r1, lbl_08078698 @ =0x0000010f
    adds r3, r0, r1
    ldrb r2, [r3]
    movs r1, #0xd
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r2, #4
    orrs r0, r2
    strb r0, [r3]
    ldr r0, [r4]
    ldr r6, lbl_0807869c @ =0x0000014f
    adds r3, r0, r6
    ldrb r0, [r3]
    ands r1, r0
    orrs r1, r2
    strb r1, [r3]
lbl_08078666:
    cmp r5, #2
    beq lbl_08078746
    ldr r0, [r4]
    ldr r1, lbl_080786a0 @ =0x0000011f
    adds r3, r0, r1
    ldrb r2, [r3]
    movs r1, #0xd
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r2, #4
    orrs r0, r2
    strb r0, [r3]
    ldr r0, [r4]
    ldr r4, lbl_080786a4 @ =0x0000015f
    adds r3, r0, r4
    ldrb r0, [r3]
    ands r1, r0
    orrs r1, r2
    strb r1, [r3]
    b lbl_08078746
    .align 2, 0
lbl_08078690: .4byte sNonGameplayRamPointer
lbl_08078694: .4byte 0x0000013f
lbl_08078698: .4byte 0x0000010f
lbl_0807869c: .4byte 0x0000014f
lbl_080786a0: .4byte 0x0000011f
lbl_080786a4: .4byte 0x0000015f
lbl_080786a8:
    ldr r4, lbl_08078710 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xe4
    adds r3, #1
    lsls r1, r3, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    adds r1, #0xff
    ldrb r3, [r1]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r0, r3
    strb r0, [r1]
    ldr r0, [r4]
    ldr r6, lbl_08078714 @ =0x0000010f
    adds r3, r0, r6
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r4]
    ldr r1, lbl_08078718 @ =0x0000011f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r4]
    adds r6, #0x30
    adds r3, r0, r6
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r4]
    ldr r1, lbl_0807871c @ =0x0000014f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r4]
    ldr r3, lbl_08078720 @ =0x0000015f
    adds r1, r0, r3
    ldrb r0, [r1]
    ands r2, r0
    strb r2, [r1]
    b lbl_08078746
    .align 2, 0
lbl_08078710: .4byte sNonGameplayRamPointer
lbl_08078714: .4byte 0x0000010f
lbl_08078718: .4byte 0x0000011f
lbl_0807871c: .4byte 0x0000014f
lbl_08078720: .4byte 0x0000015f
lbl_08078724:
    ldr r0, lbl_08078738 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xe4
    adds r1, r3, #5
lbl_0807872c:
    lsls r1, r1, #0x18
lbl_0807872e:
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    b lbl_08078746
    .align 2, 0
lbl_08078738: .4byte sNonGameplayRamPointer
lbl_0807873c:
    ldr r0, lbl_0807874c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r3, #4
    adds r0, #0xee
    strb r1, [r0]
lbl_08078746:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807874c: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08078750
sub_08078750: @ 0x08078750
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    cmp r5, #2
    bhi lbl_08078770
    ldr r1, lbl_0807876c @ =gSaveFilesInfo
    lsls r0, r5, #1
    adds r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r1, [r0, #0xc]
    b lbl_08078772
    .align 2, 0
lbl_0807876c: .4byte gSaveFilesInfo
lbl_08078770:
    movs r1, #0
lbl_08078772:
    ldr r6, lbl_08078790 @ =0x08760b40
    lsls r0, r5, #3
    adds r1, r1, r0
    adds r2, r6, #5
    adds r1, r1, r2
    ldrb r1, [r1]
    adds r7, r0, #0
    cmp r3, #1
    beq lbl_080787a2
    cmp r3, #1
    bgt lbl_08078794
    cmp r3, #0
    beq lbl_080787a0
    b lbl_080788c8
    .align 2, 0
lbl_08078790: .4byte 0x08760b40
lbl_08078794:
    cmp r3, #2
    bne lbl_0807879a
    b lbl_080788b8
lbl_0807879a:
    cmp r3, #3
    beq lbl_08078874
    b lbl_080788c8
lbl_080787a0:
    adds r1, #1
lbl_080787a2:
    ldr r4, lbl_08078868 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xd4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r4, [r4]
    ldr r3, lbl_0807886c @ =0x08760b40
    adds r1, r7, r3
    ldrh r0, [r1]
    adds r2, r4, #0
    adds r2, #0xd6
    strh r0, [r2]
    ldrh r1, [r1, #2]
    adds r0, r4, #0
    adds r0, #0xd4
    strh r1, [r0]
    adds r2, #0xa
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    ldrb r1, [r3, #4]
    cmp r5, #0
    bne lbl_080787ee
    ldr r2, lbl_08078870 @ =gSaveFilesInfo
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_080787ec
    movs r0, #0x12
    ldrsb r0, [r2, r0]
    cmp r0, #0
    beq lbl_080787ee
lbl_080787ec:
    movs r1, #0x10
lbl_080787ee:
    ldr r0, lbl_08078868 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xf4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r0, lbl_0807886c @ =0x08760b40
    ldrb r1, [r0, #0xc]
    cmp r5, #1
    bne lbl_0807881c
    ldr r2, lbl_08078870 @ =gSaveFilesInfo
    ldrb r0, [r2, #0x18]
    cmp r0, #0
    bne lbl_0807881a
    adds r0, r2, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807881c
lbl_0807881a:
    movs r1, #0x11
lbl_0807881c:
    ldr r0, lbl_08078868 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r0, r0, r2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r0, lbl_0807886c @ =0x08760b40
    ldrb r1, [r0, #0x14]
    cmp r5, #2
    bne lbl_08078852
    ldr r2, lbl_08078870 @ =gSaveFilesInfo
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08078850
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08078852
lbl_08078850:
    movs r1, #0x12
lbl_08078852:
    ldr r0, lbl_08078868 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    b lbl_080788c8
    .align 2, 0
lbl_08078868: .4byte sNonGameplayRamPointer
lbl_0807886c: .4byte 0x08760b40
lbl_08078870: .4byte gSaveFilesInfo
lbl_08078874:
    ldr r4, lbl_080788b4 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0xdf
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r4]
    adds r0, #0xde
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xf4
    ldrb r1, [r6, #4]
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r1, [r6, #0xc]
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    ldrb r1, [r6, #0x14]
    bl UpdateMenuOamDataID
    b lbl_080788c8
    .align 2, 0
lbl_080788b4: .4byte sNonGameplayRamPointer
lbl_080788b8:
    ldr r0, lbl_080788d0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xd4
    adds r1, #2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
lbl_080788c8:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080788d0: .4byte sNonGameplayRamPointer

    thumb_func_start sub_080788d4
sub_080788d4: @ 0x080788d4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    adds r6, r3, #0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r5, lbl_0807891c @ =sNonGameplayRamPointer
    ldr r2, [r5]
    ldr r7, lbl_08078920 @ =0x08760b40
    movs r0, #0x26
    adds r0, r0, r2
    mov ip, r0
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0xc6
    strh r0, [r1]
    mov r1, ip
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrh r1, [r0, #2]
    adds r0, r2, #0
    adds r0, #0xc4
    strh r1, [r0]
    cmp r3, #2
    bne lbl_08078910
    b lbl_08078a0c
lbl_08078910:
    cmp r3, #2
    ble lbl_08078924
    cmp r3, #3
    beq lbl_080789d0
    b lbl_08078a0c
    .align 2, 0
lbl_0807891c: .4byte sNonGameplayRamPointer
lbl_08078920: .4byte 0x08760b40
lbl_08078924:
    cmp r6, #0
    blt lbl_08078a0c
    adds r2, #0xd0
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    ldr r3, lbl_08078984 @ =0x08760b70
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x26
    ldrb r2, [r1]
    lsls r1, r2, #1
    adds r1, r1, r2
    adds r1, r4, r1
    adds r1, r1, r3
    adds r0, #0xc4
    ldrb r1, [r1]
    bl UpdateMenuOamDataID
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807896e
    movs r1, #0x13
    cmp r4, #0
    beq lbl_08078966
    ldrb r1, [r7, #4]
lbl_08078966:
    adds r0, r2, #0
    adds r0, #0xf4
    bl UpdateMenuOamDataID
lbl_0807896e:
    ldr r0, lbl_08078988 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x26
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_080789a0
    cmp r4, #1
    beq lbl_08078990
    ldr r0, lbl_0807898c @ =0x08760b40
    ldrb r1, [r0, #0xc]
    b lbl_08078992
    .align 2, 0
lbl_08078984: .4byte 0x08760b70
lbl_08078988: .4byte sNonGameplayRamPointer
lbl_0807898c: .4byte 0x08760b40
lbl_08078990:
    movs r1, #0x14
lbl_08078992:
    ldr r0, lbl_080789b8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r0, r0, r2
    bl UpdateMenuOamDataID
lbl_080789a0:
    ldr r0, lbl_080789b8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x26
    ldrb r1, [r1]
    adds r2, r0, #0
    cmp r1, #2
    beq lbl_08078a0c
    cmp r4, #2
    beq lbl_080789c0
    ldr r0, lbl_080789bc @ =0x08760b40
    ldrb r1, [r0, #0x14]
    b lbl_080789c2
    .align 2, 0
lbl_080789b8: .4byte sNonGameplayRamPointer
lbl_080789bc: .4byte 0x08760b40
lbl_080789c0:
    movs r1, #0x15
lbl_080789c2:
    ldr r0, [r2]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    bl UpdateMenuOamDataID
    b lbl_08078a0c
lbl_080789d0:
    adds r2, #0xcf
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    cmp r4, #0
    bne lbl_080789e8
    ldr r0, [r5]
    adds r0, #0xf4
    ldrb r1, [r7, #4]
    bl UpdateMenuOamDataID
lbl_080789e8:
    cmp r4, #1
    bne lbl_080789fa
    ldr r0, [r5]
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r1, [r7, #0xc]
    bl UpdateMenuOamDataID
lbl_080789fa:
    cmp r4, #2
    bne lbl_08078a0c
    ldr r0, [r5]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    ldrb r1, [r7, #0x14]
    bl UpdateMenuOamDataID
lbl_08078a0c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08078a14
sub_08078a14: @ 0x08078a14
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    cmp r5, #2
    bhi lbl_08078a34
    ldr r1, lbl_08078a30 @ =gSaveFilesInfo
    lsls r0, r5, #1
    adds r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r1, [r0, #0xc]
    b lbl_08078a36
    .align 2, 0
lbl_08078a30: .4byte gSaveFilesInfo
lbl_08078a34:
    movs r1, #0
lbl_08078a36:
    ldr r6, lbl_08078a54 @ =0x08760b40
    lsls r0, r5, #3
    adds r1, r1, r0
    adds r2, r6, #5
    adds r1, r1, r2
    ldrb r1, [r1]
    adds r7, r0, #0
    cmp r3, #1
    beq lbl_08078a66
    cmp r3, #1
    bgt lbl_08078a58
    cmp r3, #0
    beq lbl_08078a64
    b lbl_08078b8c
    .align 2, 0
lbl_08078a54: .4byte 0x08760b40
lbl_08078a58:
    cmp r3, #2
    bne lbl_08078a5e
    b lbl_08078b7c
lbl_08078a5e:
    cmp r3, #3
    beq lbl_08078b38
    b lbl_08078b8c
lbl_08078a64:
    adds r1, #1
lbl_08078a66:
    ldr r4, lbl_08078b2c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xd4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r4, [r4]
    ldr r3, lbl_08078b30 @ =0x08760b40
    adds r1, r7, r3
    ldrh r0, [r1]
    adds r2, r4, #0
    adds r2, #0xd6
    strh r0, [r2]
    ldrh r1, [r1, #2]
    adds r0, r4, #0
    adds r0, #0xd4
    strh r1, [r0]
    adds r2, #0xa
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    ldrb r1, [r3, #4]
    cmp r5, #0
    bne lbl_08078ab2
    ldr r2, lbl_08078b34 @ =gSaveFilesInfo
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_08078ab0
    movs r0, #0x12
    ldrsb r0, [r2, r0]
    cmp r0, #0
    beq lbl_08078ab2
lbl_08078ab0:
    movs r1, #0x10
lbl_08078ab2:
    ldr r0, lbl_08078b2c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xf4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r0, lbl_08078b30 @ =0x08760b40
    ldrb r1, [r0, #0xc]
    cmp r5, #1
    bne lbl_08078ae0
    ldr r2, lbl_08078b34 @ =gSaveFilesInfo
    ldrb r0, [r2, #0x18]
    cmp r0, #0
    bne lbl_08078ade
    adds r0, r2, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08078ae0
lbl_08078ade:
    movs r1, #0x11
lbl_08078ae0:
    ldr r0, lbl_08078b2c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r0, r0, r2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    ldr r0, lbl_08078b30 @ =0x08760b40
    ldrb r1, [r0, #0x14]
    cmp r5, #2
    bne lbl_08078b16
    ldr r2, lbl_08078b34 @ =gSaveFilesInfo
    adds r0, r2, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08078b14
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08078b16
lbl_08078b14:
    movs r1, #0x12
lbl_08078b16:
    ldr r0, lbl_08078b2c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
    b lbl_08078b8c
    .align 2, 0
lbl_08078b2c: .4byte sNonGameplayRamPointer
lbl_08078b30: .4byte 0x08760b40
lbl_08078b34: .4byte gSaveFilesInfo
lbl_08078b38:
    ldr r4, lbl_08078b78 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0xdf
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r4]
    adds r0, #0xde
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xf4
    ldrb r1, [r6, #4]
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r1, #0x82
    lsls r1, r1, #1
    adds r0, r0, r1
    ldrb r1, [r6, #0xc]
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x8a
    lsls r2, r2, #1
    adds r0, r0, r2
    ldrb r1, [r6, #0x14]
    bl UpdateMenuOamDataID
    b lbl_08078b8c
    .align 2, 0
lbl_08078b78: .4byte sNonGameplayRamPointer
lbl_08078b7c:
    ldr r0, lbl_08078b94 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xd4
    adds r1, #2
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl UpdateMenuOamDataID
lbl_08078b8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08078b94: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08078b98
sub_08078b98: @ 0x08078b98
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bhi lbl_08078c76
    lsls r0, r0, #2
    ldr r1, lbl_08078bac @ =lbl_08078bb0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08078bac: .4byte lbl_08078bb0
lbl_08078bb0: @ jump table
    .4byte lbl_08078bcc @ case 0
    .4byte lbl_08078bc4 @ case 1
    .4byte lbl_08078c54 @ case 2
    .4byte lbl_08078c30 @ case 3
    .4byte lbl_08078c5c @ case 4
lbl_08078bc4:
    movs r0, #0xfd
    lsls r0, r0, #1
    bl SoundPlay
lbl_08078bcc:
    ldr r5, lbl_08078c1c @ =sNonGameplayRamPointer
    ldr r3, [r5]
    ldr r2, lbl_08078c20 @ =0x08760b80
    ldr r4, lbl_08078c24 @ =gOptionsOptionSelected
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrh r1, [r0]
    ldr r6, lbl_08078c28 @ =0x00000206
    adds r0, r3, r6
    strh r1, [r0]
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r0, r0, #2
    adds r2, #2
    adds r0, r0, r2
    ldrh r1, [r0]
    movs r2, #0x81
    lsls r2, r2, #2
    adds r0, r3, r2
    strh r1, [r0]
    adds r6, #0xa
    adds r3, r3, r6
    ldrb r1, [r3]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r3]
    ldr r5, [r5]
    ldr r1, lbl_08078c2c @ =0x0000020e
    adds r0, r5, r1
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_08078c76
    adds r0, r5, r2
    b lbl_08078c44
    .align 2, 0
lbl_08078c1c: .4byte sNonGameplayRamPointer
lbl_08078c20: .4byte 0x08760b80
lbl_08078c24: .4byte gOptionsOptionSelected
lbl_08078c28: .4byte 0x00000206
lbl_08078c2c: .4byte 0x0000020e
lbl_08078c30:
    ldr r0, lbl_08078c4c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldr r2, lbl_08078c50 @ =0x0000020e
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_08078c76
    movs r6, #0x81
    lsls r6, r6, #2
    adds r0, r1, r6
lbl_08078c44:
    movs r1, #1
    bl UpdateMenuOamDataID
    b lbl_08078c76
    .align 2, 0
lbl_08078c4c: .4byte sNonGameplayRamPointer
lbl_08078c50: .4byte 0x0000020e
lbl_08078c54:
    movs r0, #0xfe
    lsls r0, r0, #1
    bl SoundPlay
lbl_08078c5c:
    ldr r0, lbl_08078c94 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldr r2, lbl_08078c98 @ =0x0000020e
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #2
    beq lbl_08078c76
    movs r6, #0x81
    lsls r6, r6, #2
    adds r0, r1, r6
    movs r1, #2
    bl UpdateMenuOamDataID
lbl_08078c76:
    ldr r0, lbl_08078c94 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldr r0, lbl_08078c9c @ =0x0000020f
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08078c94: .4byte sNonGameplayRamPointer
lbl_08078c98: .4byte 0x0000020e
lbl_08078c9c: .4byte 0x0000020f

    thumb_func_start sub_08078ca0
sub_08078ca0: @ 0x08078ca0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    movs r0, #3
    ands r0, r7
    cmp r0, #0
    beq lbl_08078d10
    movs r0, #1
    ands r0, r7
    movs r2, #3
    cmp r0, #0
    beq lbl_08078cbe
    movs r2, #2
lbl_08078cbe:
    ldr r0, lbl_08078d80 @ =sNonGameplayRamPointer
    mov r8, r0
    ldr r0, [r0]
    movs r6, #0x85
    lsls r6, r6, #2
    adds r0, r0, r6
    ldr r4, lbl_08078d84 @ =0x08760b9c
    lsls r2, r2, #1
    ldr r5, lbl_08078d88 @ =gStereoFlag
    ldrb r1, [r5]
    lsls r1, r1, #3
    adds r2, r2, r1
    adds r2, r2, r4
    ldrb r1, [r2]
    bl UpdateMenuOamDataID
    mov r1, r8
    ldr r2, [r1]
    ldrb r0, [r5]
    lsls r0, r0, #3
    adds r0, r0, r4
    ldrh r1, [r0]
    ldr r3, lbl_08078d8c @ =0x00000216
    adds r0, r2, r3
    strh r1, [r0]
    ldrb r0, [r5]
    lsls r0, r0, #3
    adds r4, #2
    adds r0, r0, r4
    ldrh r0, [r0]
    adds r6, r2, r6
    strh r0, [r6]
    ldr r6, lbl_08078d90 @ =0x0000021f
    adds r2, r2, r6
    ldrb r1, [r2]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
lbl_08078d10:
    movs r0, #4
    ands r0, r7
    cmp r0, #0
    beq lbl_08078d74
    ldr r5, lbl_08078d80 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    ldr r0, lbl_08078d94 @ =0x00000226
    adds r3, r1, r0
    adds r0, #0x7a
    strh r0, [r3]
    movs r6, #0x89
    lsls r6, r6, #2
    adds r4, r1, r6
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r4]
    ldrh r2, [r3]
    adds r6, #0x12
    adds r0, r1, r6
    strh r2, [r0]
    ldrh r2, [r4]
    subs r6, #2
    adds r0, r1, r6
    strh r2, [r0]
    ldrh r2, [r3]
    ldr r3, lbl_08078d98 @ =0x00000246
    adds r0, r1, r3
    strh r2, [r0]
    ldrh r2, [r4]
    adds r6, #0x10
    adds r0, r1, r6
    strh r2, [r0]
    ldr r0, lbl_08078d9c @ =0x0000022f
    adds r1, r1, r0
    ldrb r0, [r1]
    movs r2, #3
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    subs r3, #7
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    adds r6, #0xb
    adds r1, r1, r6
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
lbl_08078d74:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08078d80: .4byte sNonGameplayRamPointer
lbl_08078d84: .4byte 0x08760b9c
lbl_08078d88: .4byte gStereoFlag
lbl_08078d8c: .4byte 0x00000216
lbl_08078d90: .4byte 0x0000021f
lbl_08078d94: .4byte 0x00000226
lbl_08078d98: .4byte 0x00000246
lbl_08078d9c: .4byte 0x0000022f

    thumb_func_start sub_08078da0
sub_08078da0: @ 0x08078da0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #8
    ldr r1, lbl_08078dc4 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x34
    ldrb r0, [r0]
    mov ip, r1
    cmp r0, #6
    bls lbl_08078db8
    b lbl_080790be
lbl_08078db8:
    lsls r0, r0, #2
    ldr r1, lbl_08078dc8 @ =lbl_08078dcc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08078dc4: .4byte sNonGameplayRamPointer
lbl_08078dc8: .4byte lbl_08078dcc
lbl_08078dcc: @ jump table
    .4byte lbl_080790be @ case 0
    .4byte lbl_08078de8 @ case 1
    .4byte lbl_08078f8c @ case 2
    .4byte lbl_08078f8c @ case 3
    .4byte lbl_08078f8c @ case 4
    .4byte lbl_08078f8c @ case 5
    .4byte lbl_08079046 @ case 6
lbl_08078de8:
    ldr r2, lbl_08078e48 @ =gCurrentMessage
    adds r1, r2, #0
    ldr r0, lbl_08078e4c @ =0x0845f430
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldr r0, [r0]
    str r0, [r1]
    ldrb r0, [r2, #0xd]
    movs r6, #0
    cmp r0, #0
    beq lbl_08078e00
    subs r6, #1
lbl_08078e00:
    ldr r0, lbl_08078e50 @ =0x0845f3cc
    mov r8, r0
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    mov r7, r8
    adds r7, #1
    adds r0, r0, r7
    ldrb r0, [r0]
    cmp r0, #3
    beq lbl_08078e20
    cmp r0, #1
    bne lbl_08078e60
lbl_08078e20:
    add r0, sp, #4
    strh r6, [r0]
    ldr r2, lbl_08078e54 @ =0x040000d4
    str r0, [r2]
    ldr r3, lbl_08078e58 @ =0x08760bdc
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r0, [r0]
    str r0, [r2, #4]
    ldr r0, lbl_08078e5c @ =0x81000800
    b lbl_08078ed6
    .align 2, 0
lbl_08078e48: .4byte gCurrentMessage
lbl_08078e4c: .4byte 0x0845f430
lbl_08078e50: .4byte 0x0845f3cc
lbl_08078e54: .4byte 0x040000d4
lbl_08078e58: .4byte 0x08760bdc
lbl_08078e5c: .4byte 0x81000800
lbl_08078e60:
    cmp r0, #2
    bne lbl_08078eec
    add r3, sp, #4
    strh r6, [r3]
    ldr r2, lbl_08078edc @ =0x040000d4
    str r3, [r2]
    ldr r4, lbl_08078ee0 @ =0x08760bdc
    mov r5, ip
    ldr r0, [r5]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldr r0, [r0]
    str r0, [r2, #4]
    ldr r5, lbl_08078ee4 @ =0x81000100
    str r5, [r2, #8]
    ldr r0, [r2, #8]
    strh r6, [r3]
    str r3, [r2]
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldr r0, [r0]
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r0, r1
    str r0, [r2, #4]
    str r5, [r2, #8]
    ldr r0, [r2, #8]
    strh r6, [r3]
    str r3, [r2]
    mov r3, ip
    ldr r0, [r3]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldr r0, [r0]
    movs r4, #0xc0
    lsls r4, r4, #3
    adds r0, r0, r4
    str r0, [r2, #4]
    ldr r0, lbl_08078ee8 @ =0x81000400
lbl_08078ed6:
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    b lbl_08078f76
    .align 2, 0
lbl_08078edc: .4byte 0x040000d4
lbl_08078ee0: .4byte 0x08760bdc
lbl_08078ee4: .4byte 0x81000100
lbl_08078ee8: .4byte 0x81000400
lbl_08078eec:
    add r4, sp, #4
    strh r6, [r4]
    ldr r3, lbl_08078f7c @ =0x040000d4
    str r4, [r3]
    ldr r5, lbl_08078f80 @ =0x08760bdc
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r5
    ldr r0, [r0]
    str r0, [r3, #4]
    ldr r0, lbl_08078f84 @ =0x81000400
    str r0, [r3, #8]
    ldr r0, [r3, #8]
    mov r1, ip
    ldr r0, [r1]
    adds r2, r0, #0
    adds r2, #0x35
    ldrb r1, [r2]
    lsls r0, r1, #1
    adds r0, r0, r1
    mov r1, r8
    adds r1, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_08078f76
    strh r6, [r4]
    str r4, [r3]
    ldrb r1, [r2]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r5
    ldr r0, [r0]
    movs r1, #0x80
    lsls r1, r1, #4
    adds r0, r0, r1
    str r0, [r3, #4]
    ldr r2, lbl_08078f88 @ =0x81000100
    str r2, [r3, #8]
    ldr r0, [r3, #8]
    strh r6, [r4]
    str r4, [r3]
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r5
    ldr r0, [r0]
    movs r5, #0xc0
    lsls r5, r5, #4
    adds r0, r0, r5
    str r0, [r3, #4]
    str r2, [r3, #8]
    ldr r0, [r3, #8]
lbl_08078f76:
    mov r0, ip
    ldr r1, [r0]
    b lbl_0807901a
    .align 2, 0
lbl_08078f7c: .4byte 0x040000d4
lbl_08078f80: .4byte 0x08760bdc
lbl_08078f84: .4byte 0x81000400
lbl_08078f88: .4byte 0x81000100
lbl_08078f8c:
    ldr r4, lbl_08079024 @ =0x08760bdc
    ldr r2, lbl_08079028 @ =0x0845f3cc
    ldr r0, lbl_0807902c @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r2, #1
    adds r0, r0, r2
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r4
    ldr r4, [r0]
    adds r3, #0x34
    ldrb r0, [r3]
    subs r6, r0, #2
    movs r0, #2
    ands r0, r6
    cmp r0, #0
    beq lbl_08078fbe
    movs r3, #0x80
    lsls r3, r3, #4
    adds r4, r4, r3
lbl_08078fbe:
    movs r0, #1
    ands r6, r0
    cmp r6, #0
    beq lbl_08078fd6
    movs r5, #0x80
    lsls r5, r5, #2
    adds r4, r4, r5
    cmp r1, #2
    bne lbl_08078fd6
    movs r0, #0x80
    lsls r0, r0, #3
    adds r4, r4, r0
lbl_08078fd6:
    ldr r1, lbl_08079030 @ =gCurrentMessage
    movs r0, #0
    strh r0, [r1, #2]
    ldr r1, lbl_08079034 @ =0x0876079c
    mov r8, r1
    ldr r7, lbl_08079028 @ =0x0845f3cc
    ldr r5, lbl_0807902c @ =sNonGameplayRamPointer
lbl_08078fe4:
    ldr r0, lbl_08079038 @ =gLanguage
    movs r2, #0
    ldrsb r2, [r0, r2]
    lsls r2, r2, #2
    add r2, r8
    ldr r0, [r5]
    adds r0, #0x35
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    adds r0, r0, r7
    ldrb r0, [r0]
    ldr r1, [r2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r0, lbl_08079030 @ =gCurrentMessage
    adds r2, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #2
    beq lbl_0807903c
    cmp r6, #1
    bne lbl_08078fe4
    ldr r1, [r5]
lbl_0807901a:
    adds r1, #0x34
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080790be
    .align 2, 0
lbl_08079024: .4byte 0x08760bdc
lbl_08079028: .4byte 0x0845f3cc
lbl_0807902c: .4byte sNonGameplayRamPointer
lbl_08079030: .4byte gCurrentMessage
lbl_08079034: .4byte 0x0876079c
lbl_08079038: .4byte gLanguage
lbl_0807903c:
    ldr r0, [r5]
    adds r0, #0x34
    movs r1, #6
    strb r1, [r0]
    b lbl_080790be
lbl_08079046:
    mov r3, ip
    ldr r0, [r3]
    adds r0, #0x35
    movs r1, #0xff
    strb r1, [r0]
    movs r6, #0
    mov r1, sp
    movs r0, #1
    rsbs r0, r0, #0
    strb r0, [r1]
    adds r5, r0, #0
    adds r4, r5, #0
    strb r0, [r1, #1]
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x36
    ldrb r2, [r1]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_0807907a
    mov r0, sp
    strb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
    movs r6, #1
lbl_0807907a:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x37
    ldrb r2, [r1]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_08079094
    mov r3, sp
    adds r0, r3, r6
    strb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
lbl_08079094:
    mov r4, ip
    ldr r0, [r4]
    mov r1, sp
    ldrb r1, [r1]
    adds r0, #0x35
    strb r1, [r0]
    ldr r0, [r4]
    mov r1, sp
    ldrb r1, [r1, #1]
    adds r0, #0x36
    strb r1, [r0]
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0x35
    ldrb r0, [r0]
    movs r1, #0xff
    eors r0, r1
    rsbs r0, r0, #0
    lsrs r0, r0, #0x1f
    adds r2, #0x34
    strb r0, [r2]
lbl_080790be:
    add sp, #8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080790cc
sub_080790cc: @ 0x080790cc
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r3, r1, #0
    movs r5, #1
    cmp r0, #0
    bne lbl_08079116
    ldr r4, lbl_080790f8 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    adds r3, r2, #0
    adds r3, #0x35
    ldrb r0, [r3]
    cmp r0, #0xff
    bne lbl_080790fc
    strb r1, [r3]
    ldr r0, [r4]
    adds r0, #0x34
    strb r5, [r0]
    b lbl_0807916a
    .align 2, 0
lbl_080790f8: .4byte sNonGameplayRamPointer
lbl_080790fc:
    adds r3, r2, #0
    adds r3, #0x36
    ldrb r0, [r3]
    cmp r0, #0xff
    bne lbl_0807910a
    strb r1, [r3]
    b lbl_0807916a
lbl_0807910a:
    adds r2, #0x37
    ldrb r0, [r2]
    cmp r0, #0xff
    bne lbl_08079140
    strb r1, [r2]
    b lbl_0807916a
lbl_08079116:
    cmp r0, #1
    bne lbl_08079148
    ldr r0, lbl_08079144 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0x35
    ldrb r0, [r0]
    cmp r0, r1
    bne lbl_0807912a
    movs r5, #0
lbl_0807912a:
    adds r0, r2, #0
    adds r0, #0x36
    ldrb r0, [r0]
    cmp r0, r1
    bne lbl_08079136
    movs r5, #0
lbl_08079136:
    adds r0, r2, #0
    adds r0, #0x37
    ldrb r0, [r0]
    cmp r0, r3
    bne lbl_0807916a
lbl_08079140:
    movs r5, #0
    b lbl_0807916a
    .align 2, 0
lbl_08079144: .4byte sNonGameplayRamPointer
lbl_08079148:
    ldr r2, lbl_08079174 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x35
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x36
    movs r1, #1
    rsbs r1, r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x37
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x34
    movs r1, #0
    strb r1, [r0]
lbl_0807916a:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08079174: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08079178
sub_08079178: @ 0x08079178
    push {lr}
    movs r2, #1
    rsbs r2, r2, #0
    ldr r1, lbl_08079194 @ =gSaveFilesInfo
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807919c
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0807919c
    movs r2, #0
    ldr r3, lbl_08079198 @ =sNonGameplayRamPointer
    b lbl_08079200
    .align 2, 0
lbl_08079194: .4byte gSaveFilesInfo
lbl_08079198: .4byte sNonGameplayRamPointer
lbl_0807919c:
    ldrb r0, [r1, #0x18]
    cmp r0, #0
    bne lbl_080791bc
    adds r0, r1, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080791bc
    movs r2, #1
    ldr r3, lbl_080791b8 @ =sNonGameplayRamPointer
    b lbl_08079200
    .align 2, 0
lbl_080791b8: .4byte sNonGameplayRamPointer
lbl_080791bc:
    adds r0, r1, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080791d6
    adds r0, r1, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080791d6
    movs r2, #2
lbl_080791d6:
    ldr r3, lbl_0807920c @ =sNonGameplayRamPointer
    cmp r2, #0
    bge lbl_08079200
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x27
    ldrb r2, [r0]
    cmp r2, #0x80
    beq lbl_080791f0
    subs r0, #1
    ldrb r0, [r0]
    cmp r0, r2
    bne lbl_08079200
lbl_080791f0:
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r1, [r0]
    movs r2, #1
    eors r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r2, r0, #0x1f
lbl_08079200:
    ldr r0, [r3]
    adds r0, #0x27
    strb r2, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807920c: .4byte sNonGameplayRamPointer

    thumb_func_start sub_08079210
sub_08079210: @ 0x08079210
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    movs r7, #0
    ldr r2, lbl_0807923c @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r6, r2, #0
    cmp r0, #0xf
    bls lbl_08079230
    b lbl_08079794
lbl_08079230:
    lsls r0, r0, #2
    ldr r1, lbl_08079240 @ =lbl_08079244
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807923c: .4byte sNonGameplayRamPointer
lbl_08079240: .4byte lbl_08079244
lbl_08079244: @ jump table
    .4byte lbl_08079284 @ case 0
    .4byte lbl_080792d0 @ case 1
    .4byte lbl_080792e8 @ case 2
    .4byte lbl_08079300 @ case 3
    .4byte lbl_080793e8 @ case 4
    .4byte lbl_080794ec @ case 5
    .4byte lbl_08079510 @ case 6
    .4byte lbl_080795b2 @ case 7
    .4byte lbl_080795d4 @ case 8
    .4byte lbl_080795fc @ case 9
    .4byte lbl_0807961c @ case 10
    .4byte lbl_0807964c @ case 11
    .4byte lbl_08079686 @ case 12
    .4byte lbl_080796a0 @ case 13
    .4byte lbl_080796bc @ case 14
    .4byte lbl_08079780 @ case 15
lbl_08079284:
    movs r0, #0
    movs r1, #1
    bl sub_080790cc
    movs r0, #0
    movs r1, #2
    bl sub_080790cc
    ldr r4, lbl_080792c8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x26
    bl sub_0807d230
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078750
    movs r0, #0x12
    bl sub_0807e6d8
    ldr r1, [r4]
    ldr r0, lbl_080792cc @ =0x08760b38
    ldrb r0, [r0]
    adds r1, #0x2c
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r4]
    adds r0, #0x3a
    strb r2, [r0]
    ldr r1, [r4]
    b lbl_08079766
    .align 2, 0
lbl_080792c8: .4byte sNonGameplayRamPointer
lbl_080792cc: .4byte 0x08760b38
lbl_080792d0:
    movs r0, #0x13
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_080792dc
    b lbl_08079794
lbl_080792dc:
    ldr r0, lbl_080792e4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079766
    .align 2, 0
lbl_080792e4: .4byte sNonGameplayRamPointer
lbl_080792e8:
    movs r0, #1
    movs r1, #2
    bl sub_080790cc
    cmp r0, #0
    bne lbl_080792f6
    b lbl_08079794
lbl_080792f6:
    ldr r0, lbl_080792fc @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079766
    .align 2, 0
lbl_080792fc: .4byte sNonGameplayRamPointer
lbl_08079300:
    movs r4, #0
    ldr r5, lbl_08079320 @ =gChangedInput
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_08079354
    ldr r1, [r6]
    adds r1, #0x26
    movs r0, #1
    bl sub_0807d19c
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08079324
    movs r4, #1
    b lbl_0807935a
    .align 2, 0
lbl_08079320: .4byte gChangedInput
lbl_08079324:
    ldrh r1, [r5]
    movs r3, #2
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08079332
    b lbl_080796aa
lbl_08079332:
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08079354
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x3b
    ldrb r1, [r1]
    adds r0, #0x26
    ldrb r0, [r0]
    asrs r1, r0
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r4, r0, #0x1f
    ands r4, r3
lbl_08079354:
    cmp r4, #0
    bne lbl_0807935a
    b lbl_08079794
lbl_0807935a:
    cmp r4, #1
    bne lbl_08079378
    movs r0, #2
    bl FileSelectPlayMenuSound
    ldr r0, lbl_08079374 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #1
    bl sub_08078750
    b lbl_08079794
    .align 2, 0
lbl_08079374: .4byte sNonGameplayRamPointer
lbl_08079378:
    cmp r4, #2
    beq lbl_0807937e
    b lbl_08079794
lbl_0807937e:
    ldr r4, lbl_080793bc @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #2
    bl sub_08078750
    ldr r2, lbl_080793c0 @ =gSaveFilesInfo
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #0x15]
    cmp r0, #0
    beq lbl_080793c8
    ldr r0, lbl_080793c4 @ =0x00000209
    bl SoundPlay
    movs r0, #0
    movs r1, #4
    bl sub_080790cc
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #9
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_080793bc: .4byte sNonGameplayRamPointer
lbl_080793c0: .4byte gSaveFilesInfo
lbl_080793c4: .4byte 0x00000209
lbl_080793c8:
    movs r0, #8
    bl FileSelectPlayMenuSound
    bl sub_08079178
    ldr r0, [r4]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #0
    bl sub_080788d4
    movs r0, #0x1b
    bl sub_0807e6d8
    ldr r1, [r4]
    b lbl_08079766
lbl_080793e8:
    movs r4, #0
    ldr r5, lbl_08079408 @ =gChangedInput
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_08079420
    ldr r1, [r6]
    adds r1, #0x27
    movs r0, #2
    bl sub_0807d19c
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807940c
    movs r4, #1
    b lbl_08079460
    .align 2, 0
lbl_08079408: .4byte gChangedInput
lbl_0807940c:
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08079428
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08079420
    movs r4, #2
lbl_08079420:
    cmp r4, #0
    bne lbl_08079426
    b lbl_08079794
lbl_08079426:
    b lbl_08079460
lbl_08079428:
    ldr r0, lbl_08079458 @ =0x00000209
    bl SoundPlay
    ldr r4, lbl_0807945c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078750
    ldr r0, [r4]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #3
    bl sub_080788d4
    movs r0, #0x1a
    bl sub_0807e6d8
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #3
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_08079458: .4byte 0x00000209
lbl_0807945c: .4byte sNonGameplayRamPointer
lbl_08079460:
    cmp r4, #1
    bne lbl_08079480
    ldr r0, lbl_0807947c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #1
    bl sub_080788d4
    movs r0, #9
    bl FileSelectPlayMenuSound
    b lbl_08079794
    .align 2, 0
lbl_0807947c: .4byte sNonGameplayRamPointer
lbl_08079480:
    cmp r4, #2
    beq lbl_08079486
    b lbl_08079794
lbl_08079486:
    ldr r4, lbl_080794d4 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_080794d8 @ =0x08760b38
    ldrb r1, [r1]
    adds r0, #0x2c
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #2
    bl sub_080788d4
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x3b
    ldrb r1, [r1]
    adds r0, #0x27
    ldrb r0, [r0]
    asrs r1, r0
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_080794dc
    movs r0, #0
    movs r1, #3
    bl sub_080790cc
    movs r0, #0x16
    bl sub_0807e6d8
    movs r0, #8
    bl FileSelectPlayMenuSound
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #5
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_080794d4: .4byte sNonGameplayRamPointer
lbl_080794d8: .4byte 0x08760b38
lbl_080794dc:
    movs r0, #0xa
    bl FileSelectPlayMenuSound
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0xb
    strb r1, [r0]
    b lbl_08079794
lbl_080794ec:
    movs r0, #0x17
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_080794f8
    b lbl_08079794
lbl_080794f8:
    ldr r4, lbl_0807950c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x2c
    ldrb r1, [r0]
    movs r0, #4
    bl sub_0807e3fc
    ldr r1, [r4]
    b lbl_08079766
    .align 2, 0
lbl_0807950c: .4byte sNonGameplayRamPointer
lbl_08079510:
    movs r4, #0xff
    ldr r0, lbl_08079538 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_080795a0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807954e
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807953c
    adds r1, #0x40
    movs r0, #7
    strb r0, [r1]
    b lbl_080795a0
    .align 2, 0
lbl_08079538: .4byte gChangedInput
lbl_0807953c:
    movs r0, #0xa
    bl FileSelectPlayMenuSound
    movs r4, #0x80
    ldr r0, [r6]
    adds r0, #0x40
    movs r1, #0xb
    strb r1, [r0]
    b lbl_080795a0
lbl_0807954e:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08079560
    ldr r0, [r6]
    adds r0, #0x40
    movs r1, #7
    strb r1, [r0]
    b lbl_080795a0
lbl_08079560:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08079580
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_080795a0
    movs r4, #0
    strb r4, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_080795a0
lbl_08079580:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080795a0
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080795a0
    movs r4, #1
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_080795a0:
    adds r0, r4, #1
    cmp r0, #0
    bne lbl_080795a8
    b lbl_08079794
lbl_080795a8:
    adds r1, r4, #0
    movs r0, #4
    bl sub_0807e3fc
    b lbl_08079794
lbl_080795b2:
    ldr r0, lbl_080795cc @ =0x00000209
    bl SoundPlay
    movs r0, #4
    movs r1, #0x81
    bl sub_0807e3fc
    movs r0, #0x18
    bl sub_0807e6d8
    ldr r0, lbl_080795d0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079766
    .align 2, 0
lbl_080795cc: .4byte 0x00000209
lbl_080795d0: .4byte sNonGameplayRamPointer
lbl_080795d4:
    movs r0, #0x19
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_080795e0
    b lbl_08079794
lbl_080795e0:
    ldr r4, lbl_080795f8 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #0
    bl sub_080788d4
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #4
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_080795f8: .4byte sNonGameplayRamPointer
lbl_080795fc:
    movs r0, #1
    movs r1, #4
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807960a
    b lbl_08079794
lbl_0807960a:
    movs r0, #0x1c
    bl sub_0807e6d8
    ldr r0, lbl_08079618 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079766
    .align 2, 0
lbl_08079618: .4byte sNonGameplayRamPointer
lbl_0807961c:
    ldr r0, lbl_08079648 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0807962a
    b lbl_08079794
lbl_0807962a:
    ldr r0, [r6]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078750
    movs r0, #0x1a
    bl sub_0807e6d8
    ldr r0, [r6]
    adds r0, #0x40
    movs r1, #3
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_08079648: .4byte gChangedInput
lbl_0807964c:
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x26
    ldrb r0, [r0]
    adds r1, #0x27
    ldrb r1, [r1]
    bl sub_080755a4
    cmp r0, #0
    bne lbl_08079662
    b lbl_08079794
lbl_08079662:
    ldr r0, [r6]
    adds r0, #0x3a
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807967e
    adds r1, #0x40
    movs r0, #0xe
    strb r0, [r1]
    b lbl_08079794
lbl_0807967e:
    adds r1, #0x40
    movs r0, #0xc
    strb r0, [r1]
    b lbl_08079794
lbl_08079686:
    movs r0, #4
    movs r1, #0x81
    bl sub_0807e3fc
    movs r0, #0x18
    bl sub_0807e6d8
    ldr r0, lbl_0807969c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079766
    .align 2, 0
lbl_0807969c: .4byte sNonGameplayRamPointer
lbl_080796a0:
    movs r0, #0x19
    bl sub_0807e6d8
    cmp r0, #0
    beq lbl_08079794
lbl_080796aa:
    ldr r0, lbl_080796b8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #0xe
    strb r1, [r0]
    b lbl_08079794
    .align 2, 0
lbl_080796b8: .4byte sNonGameplayRamPointer
lbl_080796bc:
    adds r5, r6, #0
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x3a
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08079746
    adds r0, r1, #0
    adds r0, #0x27
    ldrb r0, [r0]
    bl display_save_file_health
    ldr r0, [r5]
    adds r0, #0x27
    ldrb r0, [r0]
    bl sub_0807cdc4
    ldr r0, [r5]
    adds r0, #0x27
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r4, lbl_08079770 @ =gSaveFilesInfo
    adds r0, r0, r4
    bl sub_0807cf98
    ldr r3, [r5]
    ldr r0, lbl_08079774 @ =0x08760b79
    adds r1, r3, #0
    adds r1, #0x27
    ldrb r2, [r1]
    lsls r1, r2, #1
    adds r0, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    lsls r0, r0, #4
    adds r3, r3, r0
    adds r1, r1, r2
    lsls r1, r1, #3
    adds r1, r1, r4
    ldrb r1, [r1, #0x11]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    movs r1, #2
    adds r3, #0x7f
    ands r1, r0
    lsls r1, r1, #6
    ldrb r2, [r3]
    movs r0, #0x3f
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    bl sub_0807d0b0
    ldr r0, lbl_08079778 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r1, r3
    ldr r2, lbl_0807977c @ =0x0600d800
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_08079746:
    ldr r0, [r6]
    adds r0, #0x26
    ldrb r1, [r0]
    movs r0, #3
    bl sub_08078750
    ldr r0, [r6]
    adds r0, #0x27
    ldrb r1, [r0]
    movs r0, #3
    bl sub_080788d4
    movs r0, #0x14
    bl sub_0807e6d8
    ldr r1, [r6]
lbl_08079766:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08079794
    .align 2, 0
lbl_08079770: .4byte gSaveFilesInfo
lbl_08079774: .4byte 0x08760b79
lbl_08079778: .4byte sEwramPointer
lbl_0807977c: .4byte 0x0600d800
lbl_08079780:
    movs r0, #0x15
    bl sub_0807e6d8
    cmp r0, #0
    beq lbl_08079794
    movs r0, #2
    movs r1, #0xff
    bl sub_080790cc
    movs r7, #1
lbl_08079794:
    adds r0, r7, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080797a0
sub_080797a0: @ 0x080797a0
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    movs r7, #0
    ldr r2, lbl_080797cc @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r5, r2, #0
    cmp r0, #0xb
    bls lbl_080797c0
    b lbl_08079b44
lbl_080797c0:
    lsls r0, r0, #2
    ldr r1, lbl_080797d0 @ =lbl_080797d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080797cc: .4byte sNonGameplayRamPointer
lbl_080797d0: .4byte lbl_080797d4
lbl_080797d4: @ jump table
    .4byte lbl_08079804 @ case 0
    .4byte lbl_08079840 @ case 1
    .4byte lbl_08079858 @ case 2
    .4byte lbl_08079900 @ case 3
    .4byte lbl_08079930 @ case 4
    .4byte lbl_080799d8 @ case 5
    .4byte lbl_080799fc @ case 6
    .4byte lbl_08079a24 @ case 7
    .4byte lbl_08079a46 @ case 8
    .4byte lbl_08079a60 @ case 9
    .4byte lbl_08079a7c @ case 10
    .4byte lbl_08079b30 @ case 11
lbl_08079804:
    movs r0, #0
    movs r1, #5
    bl sub_080790cc
    movs r0, #0
    movs r1, #6
    bl sub_080790cc
    ldr r4, lbl_0807983c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x28
    bl sub_0807d230
    ldr r0, [r4]
    adds r0, #0x28
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078a14
    movs r0, #0xa
    bl sub_0807e6d8
    ldr r0, [r4]
    adds r0, #0x3a
    movs r1, #0
    strb r1, [r0]
    b lbl_08079b10
    .align 2, 0
lbl_0807983c: .4byte sNonGameplayRamPointer
lbl_08079840:
    movs r0, #0xb
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807984c
    b lbl_08079b44
lbl_0807984c:
    ldr r0, lbl_08079854 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079b12
    .align 2, 0
lbl_08079854: .4byte sNonGameplayRamPointer
lbl_08079858:
    movs r4, #0
    ldr r6, lbl_08079878 @ =gChangedInput
    ldrh r0, [r6]
    cmp r0, #0
    beq lbl_080798ac
    ldr r1, [r5]
    adds r1, #0x28
    movs r0, #1
    bl sub_0807d19c
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807987c
    movs r4, #1
    b lbl_080798b2
    .align 2, 0
lbl_08079878: .4byte gChangedInput
lbl_0807987c:
    ldrh r1, [r6]
    movs r3, #2
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807988a
    b lbl_08079a6a
lbl_0807988a:
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080798ac
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x3b
    ldrb r1, [r1]
    adds r0, #0x28
    ldrb r0, [r0]
    asrs r1, r0
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r4, r0, #0x1f
    ands r4, r3
lbl_080798ac:
    cmp r4, #0
    bne lbl_080798b2
    b lbl_08079b44
lbl_080798b2:
    cmp r4, #1
    bne lbl_080798d0
    movs r0, #2
    bl FileSelectPlayMenuSound
    ldr r0, lbl_080798cc @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x28
    ldrb r1, [r0]
    movs r0, #1
    bl sub_08078a14
    b lbl_08079b44
    .align 2, 0
lbl_080798cc: .4byte sNonGameplayRamPointer
lbl_080798d0:
    cmp r4, #2
    beq lbl_080798d6
    b lbl_08079b44
lbl_080798d6:
    movs r0, #0x84
    lsls r0, r0, #2
    bl SoundPlay
    ldr r4, lbl_080798fc @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x28
    ldrb r1, [r0]
    movs r0, #2
    bl sub_08078a14
    movs r0, #0xe
    bl sub_0807e6d8
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #3
    strb r1, [r0]
    b lbl_08079b44
    .align 2, 0
lbl_080798fc: .4byte sNonGameplayRamPointer
lbl_08079900:
    movs r0, #0xf
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807990c
    b lbl_08079b44
lbl_0807990c:
    ldr r4, lbl_08079928 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_0807992c @ =0x08760b38
    ldrb r1, [r1, #1]
    adds r0, #0x2d
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x2d
    ldrb r1, [r0]
    movs r0, #3
    bl sub_0807e3fc
    b lbl_08079b10
    .align 2, 0
lbl_08079928: .4byte sNonGameplayRamPointer
lbl_0807992c: .4byte 0x08760b38
lbl_08079930:
    movs r4, #0xff
    ldr r0, lbl_08079958 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_080799c6
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08079974
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807995c
    adds r1, #0x40
    movs r0, #5
    strb r0, [r1]
    b lbl_080799c6
    .align 2, 0
lbl_08079958: .4byte gChangedInput
lbl_0807995c:
    movs r4, #0x80
    ldr r0, lbl_08079970 @ =0x0000020d
    bl SoundPlay
    ldr r0, [r5]
    adds r0, #0x40
    movs r1, #7
    strb r1, [r0]
    b lbl_080799c6
    .align 2, 0
lbl_08079970: .4byte 0x0000020d
lbl_08079974:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08079986
    ldr r0, [r5]
    adds r0, #0x40
    movs r1, #5
    strb r1, [r0]
    b lbl_080799c6
lbl_08079986:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_080799a6
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_080799c6
    movs r4, #0
    strb r4, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_080799c6
lbl_080799a6:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080799c6
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080799c6
    movs r4, #1
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_080799c6:
    adds r0, r4, #1
    cmp r0, #0
    bne lbl_080799ce
    b lbl_08079b44
lbl_080799ce:
    adds r1, r4, #0
    movs r0, #3
    bl sub_0807e3fc
    b lbl_08079b44
lbl_080799d8:
    ldr r0, lbl_080799f4 @ =0x00000209
    bl SoundPlay
    movs r0, #3
    movs r1, #0x81
    bl sub_0807e3fc
    movs r0, #0x10
    bl sub_0807e6d8
    ldr r0, lbl_080799f8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079b12
    .align 2, 0
lbl_080799f4: .4byte 0x00000209
lbl_080799f8: .4byte sNonGameplayRamPointer
lbl_080799fc:
    movs r0, #0x11
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_08079a08
    b lbl_08079b44
lbl_08079a08:
    ldr r4, lbl_08079a20 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x28
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078a14
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #2
    strb r1, [r0]
    b lbl_08079b44
    .align 2, 0
lbl_08079a20: .4byte sNonGameplayRamPointer
lbl_08079a24:
    ldr r0, [r5]
    adds r0, #0x28
    ldrb r0, [r0]
    bl sub_08075494
    cmp r0, #0
    bne lbl_08079a34
    b lbl_08079b44
lbl_08079a34:
    ldr r0, [r5]
    adds r0, #0x3a
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x40
    movs r1, #8
    strb r1, [r0]
    b lbl_08079b44
lbl_08079a46:
    movs r0, #3
    movs r1, #0x81
    bl sub_0807e3fc
    movs r0, #0x10
    bl sub_0807e6d8
    ldr r0, lbl_08079a5c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_08079b12
    .align 2, 0
lbl_08079a5c: .4byte sNonGameplayRamPointer
lbl_08079a60:
    movs r0, #0x11
    bl sub_0807e6d8
    cmp r0, #0
    beq lbl_08079b44
lbl_08079a6a:
    ldr r0, lbl_08079a78 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #0xa
    strb r1, [r0]
    b lbl_08079b44
    .align 2, 0
lbl_08079a78: .4byte sNonGameplayRamPointer
lbl_08079a7c:
    ldr r5, lbl_08079b1c @ =sNonGameplayRamPointer
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x3a
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08079afc
    adds r0, r1, #0
    adds r0, #0x28
    ldrb r0, [r0]
    bl display_save_file_health
    ldr r0, [r5]
    adds r0, #0x28
    ldrb r0, [r0]
    bl sub_0807cdc4
    ldr r0, [r5]
    adds r0, #0x28
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r4, lbl_08079b20 @ =gSaveFilesInfo
    adds r0, r0, r4
    bl sub_0807cf98
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x28
    ldrb r0, [r0]
    lsls r1, r0, #1
    adds r0, r1, r0
    lsls r0, r0, #3
    adds r0, r0, r4
    ldrb r0, [r0, #0x11]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08079ae2
    ldr r0, lbl_08079b24 @ =0x08760b79
    adds r0, #1
    adds r0, r1, r0
    ldrb r1, [r0]
    lsls r1, r1, #4
    adds r1, r2, r1
    adds r1, #0x7f
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
lbl_08079ae2:
    bl sub_0807d0b0
    ldr r0, lbl_08079b28 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r1, r3
    ldr r2, lbl_08079b2c @ =0x0600d800
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_08079afc:
    ldr r4, lbl_08079b1c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x28
    ldrb r1, [r0]
    movs r0, #3
    bl sub_08078a14
    movs r0, #0xc
    bl sub_0807e6d8
lbl_08079b10:
    ldr r1, [r4]
lbl_08079b12:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08079b44
    .align 2, 0
lbl_08079b1c: .4byte sNonGameplayRamPointer
lbl_08079b20: .4byte gSaveFilesInfo
lbl_08079b24: .4byte 0x08760b79
lbl_08079b28: .4byte sEwramPointer
lbl_08079b2c: .4byte 0x0600d800
lbl_08079b30:
    movs r0, #0xd
    bl sub_0807e6d8
    cmp r0, #0
    beq lbl_08079b44
    movs r0, #2
    movs r1, #0xff
    bl sub_080790cc
    movs r7, #1
lbl_08079b44:
    adds r0, r7, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08079b50
sub_08079b50: @ 0x08079b50
    push {r4, r5, lr}
    sub sp, #4
    ldr r2, lbl_08079b78 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #0xb
    bls lbl_08079b6e
    b lbl_08079ec0
lbl_08079b6e:
    lsls r0, r0, #2
    ldr r1, lbl_08079b7c @ =lbl_08079b80
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08079b78: .4byte sNonGameplayRamPointer
lbl_08079b7c: .4byte lbl_08079b80
lbl_08079b80: @ jump table
    .4byte lbl_08079bb0 @ case 0
    .4byte lbl_08079c5c @ case 1
    .4byte lbl_08079ce4 @ case 2
    .4byte lbl_08079cfc @ case 3
    .4byte lbl_08079d0c @ case 4
    .4byte lbl_08079d3c @ case 5
    .4byte lbl_08079d84 @ case 6
    .4byte lbl_08079d9c @ case 7
    .4byte lbl_08079e34 @ case 8
    .4byte lbl_08079e4c @ case 9
    .4byte lbl_08079e68 @ case 10
    .4byte lbl_08079e98 @ case 11
lbl_08079bb0:
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x46
    movs r0, #0
    strb r0, [r2]
    subs r2, #1
    strb r0, [r2]
    adds r1, #0x44
    strb r0, [r1]
    ldr r0, lbl_08079bd4 @ =gSaveFilesInfo
    ldrb r1, [r0, #1]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08079bd8
    ldr r0, [r4]
    adds r0, #0x44
    movs r1, #7
    b lbl_08079be2
    .align 2, 0
lbl_08079bd4: .4byte gSaveFilesInfo
lbl_08079bd8:
    cmp r1, #2
    bne lbl_08079be4
    ldr r0, [r4]
    adds r0, #0x44
    movs r1, #0xa
lbl_08079be2:
    strb r1, [r0]
lbl_08079be4:
    ldrb r0, [r2, #0x19]
    cmp r0, #1
    bne lbl_08079bf2
    ldr r0, [r4]
    adds r0, #0x45
    movs r1, #8
    b lbl_08079bfc
lbl_08079bf2:
    cmp r0, #2
    bne lbl_08079bfe
    ldr r0, [r4]
    adds r0, #0x45
    movs r1, #0xb
lbl_08079bfc:
    strb r1, [r0]
lbl_08079bfe:
    adds r0, r2, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_08079c10
    ldr r0, [r4]
    adds r0, #0x46
    movs r1, #9
    b lbl_08079c1a
lbl_08079c10:
    cmp r0, #2
    bne lbl_08079c1c
    ldr r0, [r4]
    adds r0, #0x46
    movs r1, #0xc
lbl_08079c1a:
    strb r1, [r0]
lbl_08079c1c:
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x44
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08079c30
    adds r1, r0, #0
    movs r0, #0
    bl sub_080790cc
lbl_08079c30:
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x45
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08079c44
    adds r1, r0, #0
    movs r0, #0
    bl sub_080790cc
lbl_08079c44:
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x46
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08079c58
    adds r1, r0, #0
    movs r0, #0
    bl sub_080790cc
lbl_08079c58:
    ldr r1, [r4]
    b lbl_08079e3e
lbl_08079c5c:
    movs r5, #0
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x44
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08079c7e
    adds r1, r0, #0
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    beq lbl_08079cc6
    ldr r0, [r4]
    adds r0, #0x47
    strb r5, [r0]
    b lbl_08079ccc
lbl_08079c7e:
    adds r2, r1, #0
    adds r2, #0x45
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08079c9e
    adds r1, r0, #0
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    beq lbl_08079cc6
    ldr r0, [r4]
    adds r0, #0x47
    movs r1, #1
    strb r1, [r0]
    b lbl_08079ccc
lbl_08079c9e:
    adds r2, r1, #0
    adds r2, #0x46
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08079cbe
    adds r1, r0, #0
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    beq lbl_08079cc6
    ldr r0, [r4]
    adds r0, #0x47
    movs r1, #2
    strb r1, [r0]
    b lbl_08079ccc
lbl_08079cbe:
    adds r1, #0x40
    movs r0, #0xa
    strb r0, [r1]
    b lbl_08079ec0
lbl_08079cc6:
    cmp r5, #0
    bne lbl_08079ccc
    b lbl_08079ec0
lbl_08079ccc:
    movs r0, #0x26
    bl sub_0807e6d8
    ldr r0, lbl_08079ce0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #2
    strb r1, [r0]
    b lbl_08079ec0
    .align 2, 0
lbl_08079ce0: .4byte sNonGameplayRamPointer
lbl_08079ce4:
    movs r0, #0x27
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_08079cf0
    b lbl_08079ec0
lbl_08079cf0:
    ldr r3, lbl_08079cf8 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    b lbl_08079e7e
    .align 2, 0
lbl_08079cf8: .4byte sNonGameplayRamPointer
lbl_08079cfc:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x1e
    bhi lbl_08079d0a
    b lbl_08079ec0
lbl_08079d0a:
    b lbl_08079e3e
lbl_08079d0c:
    ldr r0, lbl_08079d30 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08079d1a
    b lbl_08079ec0
lbl_08079d1a:
    ldr r1, lbl_08079d34 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_08079d38 @ =gMostRecentSaveFile
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x47
    ldrb r0, [r0]
    strb r0, [r2]
    b lbl_08079e3e
    .align 2, 0
lbl_08079d30: .4byte gChangedInput
lbl_08079d34: .4byte gUnk_3000c20
lbl_08079d38: .4byte gMostRecentSaveFile
lbl_08079d3c:
    movs r0, #0
    bl unk_fbc
    cmp r0, #0
    bne lbl_08079d48
    b lbl_08079ec0
lbl_08079d48:
    ldr r1, lbl_08079d74 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_08079d78 @ =gSaveFilesInfo
    ldr r0, lbl_08079d7c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r2
    ldrb r0, [r1, #1]
    cmp r0, #1
    bne lbl_08079e3a
    movs r0, #0
    strb r0, [r1, #1]
    ldr r0, lbl_08079d80 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #7
    strb r1, [r0]
    b lbl_08079ec0
    .align 2, 0
lbl_08079d74: .4byte gUnk_3000c20
lbl_08079d78: .4byte gSaveFilesInfo
lbl_08079d7c: .4byte gMostRecentSaveFile
lbl_08079d80: .4byte sNonGameplayRamPointer
lbl_08079d84:
    movs r0, #1
    bl unk_fbc
    cmp r0, #0
    bne lbl_08079d90
    b lbl_08079ec0
lbl_08079d90:
    ldr r1, lbl_08079d98 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    b lbl_08079e3a
    .align 2, 0
lbl_08079d98: .4byte gUnk_3000c20
lbl_08079d9c:
    ldr r0, [r4]
    adds r0, #0x47
    ldrb r0, [r0]
    bl display_save_file_health
    ldr r0, [r4]
    adds r0, #0x47
    ldrb r0, [r0]
    bl sub_0807cdc4
    ldr r0, [r4]
    adds r0, #0x47
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r2, lbl_08079ddc @ =gSaveFilesInfo
    adds r0, r0, r2
    bl sub_0807cf98
    bl sub_0807d0b0
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x47
    ldrb r3, [r3]
    cmp r3, #0
    bne lbl_08079de0
    adds r0, #0x44
    strb r3, [r0]
    b lbl_08079df2
    .align 2, 0
lbl_08079ddc: .4byte gSaveFilesInfo
lbl_08079de0:
    cmp r3, #1
    bne lbl_08079dea
    adds r1, r0, #0
    adds r1, #0x45
    b lbl_08079dee
lbl_08079dea:
    adds r1, r0, #0
    adds r1, #0x46
lbl_08079dee:
    movs r0, #0
    strb r0, [r1]
lbl_08079df2:
    ldr r0, lbl_08079e28 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r1, r3
    ldr r2, lbl_08079e2c @ =0x0600d800
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r3, lbl_08079e30 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x47
    ldrb r0, [r0]
    adds r0, #0xc
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, #0x7f
    ldrb r2, [r1]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    b lbl_08079e3e
    .align 2, 0
lbl_08079e28: .4byte sEwramPointer
lbl_08079e2c: .4byte 0x0600d800
lbl_08079e30: .4byte sNonGameplayRamPointer
lbl_08079e34:
    movs r0, #0x28
    bl sub_0807e6d8
lbl_08079e3a:
    ldr r0, lbl_08079e48 @ =sNonGameplayRamPointer
    ldr r1, [r0]
lbl_08079e3e:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08079ec0
    .align 2, 0
lbl_08079e48: .4byte sNonGameplayRamPointer
lbl_08079e4c:
    movs r0, #0x29
    bl sub_0807e6d8
    cmp r0, #0
    beq lbl_08079ec0
    ldr r0, lbl_08079e64 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #1
    strb r1, [r0]
    b lbl_08079ec0
    .align 2, 0
lbl_08079e64: .4byte sNonGameplayRamPointer
lbl_08079e68:
    movs r0, #2
    movs r1, #0xff
    bl sub_080790cc
    ldr r2, lbl_08079e90 @ =gMostRecentSaveFile
    ldr r3, lbl_08079e94 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    strb r0, [r2]
lbl_08079e7e:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    adds r0, #0x42
    strh r2, [r0]
    b lbl_08079ec0
    .align 2, 0
lbl_08079e90: .4byte gMostRecentSaveFile
lbl_08079e94: .4byte sNonGameplayRamPointer
lbl_08079e98:
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x10
    bls lbl_08079ec0
    adds r2, #0xef
    ldrb r1, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r4]
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078504
    movs r0, #1
    b lbl_08079ec2
lbl_08079ec0:
    movs r0, #0
lbl_08079ec2:
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08079ecc
sub_08079ecc: @ 0x08079ecc
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    sub sp, #4
    ldr r0, lbl_08079f9c @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xa2
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_08079fa0 @ =0x0600f000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r4, lbl_08079fa4 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    ldrh r0, [r1, #0x20]
    strh r0, [r1, #8]
    ldrh r2, [r1]
    movs r3, #0xa0
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    adds r1, #0xff
    ldrb r3, [r1]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r0, r3
    movs r5, #4
    orrs r0, r5
    strb r0, [r1]
    ldr r1, [r4]
    ldr r0, lbl_08079fa8 @ =0x0000010f
    mov r8, r0
    add r1, r8
    ldrb r3, [r1]
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1]
    ldr r1, [r4]
    ldr r6, lbl_08079fac @ =0x0000011f
    adds r1, r1, r6
    ldrb r3, [r1]
    adds r0, r2, #0
    ands r0, r3
    orrs r0, r5
    strb r0, [r1]
    ldr r0, [r4]
    adds r0, #0xef
    ldrb r1, [r0]
    ands r2, r1
    orrs r2, r5
    strb r2, [r0]
    ldr r0, [r4]
    ldr r2, lbl_08079fb0 @ =0x0000013f
    adds r1, r0, r2
    ldrb r0, [r1]
    movs r2, #0x20
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r4]
    ldr r3, lbl_08079fb4 @ =0x0000014f
    adds r1, r0, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r4]
    adds r3, #0x10
    adds r1, r0, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r4]
    adds r1, #0xff
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r4]
    add r1, r8
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r4]
    adds r1, r1, r6
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r4]
    adds r1, #0xef
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08079f9c: .4byte sEwramPointer
lbl_08079fa0: .4byte 0x0600f000
lbl_08079fa4: .4byte sNonGameplayRamPointer
lbl_08079fa8: .4byte 0x0000010f
lbl_08079fac: .4byte 0x0000011f
lbl_08079fb0: .4byte 0x0000013f
lbl_08079fb4: .4byte 0x0000014f

    thumb_func_start sub_08079fb8
sub_08079fb8: @ 0x08079fb8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0807a008 @ =0x0845e3ec
    ldr r1, lbl_0807a00c @ =sEwramPointer
    ldr r1, [r1]
    movs r2, #0xa2
    lsls r2, r2, #7
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    movs r5, #0
    ldr r1, lbl_0807a010 @ =sNonGameplayRamPointer
    movs r2, #0
    mov ip, r1
lbl_08079fd4:
    ldr r0, [r1]
    adds r0, #0x5c
    adds r0, r0, r5
    strb r2, [r0]
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #6
    bls lbl_08079fd4
    mov r3, ip
    ldr r1, [r3]
    adds r4, r1, #0
    adds r4, #0x5c
    movs r0, #1
    strb r0, [r4]
    adds r4, #1
    movs r5, #2
lbl_08079ff6:
    subs r0, r5, #2
    cmp r0, #5
    bls lbl_08079ffe
    b lbl_0807a11e
lbl_08079ffe:
    lsls r0, r0, #2
    ldr r1, lbl_0807a014 @ =lbl_0807a018
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807a008: .4byte 0x0845e3ec
lbl_0807a00c: .4byte sEwramPointer
lbl_0807a010: .4byte sNonGameplayRamPointer
lbl_0807a014: .4byte lbl_0807a018
lbl_0807a018: @ jump table
    .4byte lbl_0807a030 @ case 0
    .4byte lbl_0807a040 @ case 1
    .4byte lbl_0807a0a0 @ case 2
    .4byte lbl_0807a0f4 @ case 3
    .4byte lbl_0807a104 @ case 4
    .4byte lbl_0807a10c @ case 5
lbl_0807a030:
    ldr r0, lbl_0807a03c @ =gFileScreenOptionsUnlocked
    ldrb r1, [r0, #4]
    movs r0, #4
    ands r0, r1
    b lbl_0807a116
    .align 2, 0
lbl_0807a03c: .4byte gFileScreenOptionsUnlocked
lbl_0807a040:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x64
    movs r7, #0
    movs r3, #0
    strb r3, [r0]
    ldr r0, [r1]
    adds r0, #0x65
    strb r3, [r0]
    ldr r6, lbl_0807a09c @ =gTimeAttackRecord
    adds r0, r6, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #0xff
    beq lbl_0807a074
    ldr r2, [r1]
    adds r2, #0x64
    ldrb r0, [r2]
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0x65
    movs r1, #1
    strb r1, [r0]
lbl_0807a074:
    ldrb r0, [r6, #0x14]
    cmp r0, #0xff
    beq lbl_0807a090
    mov r0, ip
    ldr r2, [r0]
    adds r2, #0x64
    ldrb r0, [r2]
    movs r1, #1
    orrs r0, r1
    strb r0, [r2]
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x65
    strb r3, [r0]
lbl_0807a090:
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0x64
    ldrb r0, [r0]
    b lbl_0807a116
    .align 2, 0
lbl_0807a09c: .4byte gTimeAttackRecord
lbl_0807a0a0:
    ldr r1, lbl_0807a0e4 @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a11e
    strb r5, [r4]
    adds r4, #1
    ldrh r0, [r1]
    cmp r0, #0xff
    bne lbl_0807a11e
    ldr r1, lbl_0807a0e8 @ =sEwramPointer
    ldr r0, lbl_0807a0ec @ =0x08760bec
    ldrh r0, [r0, #8]
    lsls r0, r0, #1
    movs r3, #0xa2
    lsls r3, r3, #7
    adds r0, r0, r3
    ldr r1, [r1]
    adds r2, r1, r0
    ldr r7, lbl_0807a0f0 @ =0x00000fff
    movs r0, #0xe0
    lsls r0, r0, #8
    adds r6, r0, #0
    movs r3, #0x3f
lbl_0807a0ce:
    ldrh r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    orrs r0, r6
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bge lbl_0807a0ce
    b lbl_0807a11e
    .align 2, 0
lbl_0807a0e4: .4byte gFileScreenOptionsUnlocked
lbl_0807a0e8: .4byte sEwramPointer
lbl_0807a0ec: .4byte 0x08760bec
lbl_0807a0f0: .4byte 0x00000fff
lbl_0807a0f4:
    ldr r0, lbl_0807a100 @ =gFileScreenOptionsUnlocked
    ldrh r0, [r0, #2]
    cmp r0, #0
    beq lbl_0807a11e
    strb r5, [r4]
    b lbl_0807a11e
    .align 2, 0
lbl_0807a100: .4byte gFileScreenOptionsUnlocked
lbl_0807a104:
    ldrb r0, [r4]
    cmp r0, #5
    beq lbl_0807a11c
    b lbl_0807a11a
lbl_0807a10c:
    ldr r1, lbl_0807a198 @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1]
    cmp r0, #0
    bne lbl_0807a11a
    ldrb r0, [r1, #4]
lbl_0807a116:
    cmp r0, #0
    beq lbl_0807a11e
lbl_0807a11a:
    strb r5, [r4]
lbl_0807a11c:
    adds r4, #1
lbl_0807a11e:
    mov r2, ip
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x62
    cmp r4, r0
    bhs lbl_0807a136
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #7
    bhi lbl_0807a136
    b lbl_08079ff6
lbl_0807a136:
    movs r5, #0
    adds r0, r1, #0
    adds r0, #0x5c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807a190
    ldr r7, lbl_0807a19c @ =0x08760bec
    mov r4, ip
    ldr r6, lbl_0807a1a0 @ =sEwramPointer
lbl_0807a148:
    ldr r0, [r4]
    adds r0, #0x5c
    adds r0, r0, r5
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r1, r0, r7
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a17e
    adds r1, r0, #0
    lsls r1, r1, #1
    movs r3, #0xa2
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, [r6]
    adds r1, r2, r1
    lsls r0, r5, #7
    movs r3, #0xa4
    lsls r3, r3, #7
    adds r0, r0, r3
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DmaTransfer
lbl_0807a17e:
    adds r0, r5, #1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldr r0, [r4]
    adds r0, #0x5c
    adds r0, r0, r5
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807a148
lbl_0807a190:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807a198: .4byte gFileScreenOptionsUnlocked
lbl_0807a19c: .4byte 0x08760bec
lbl_0807a1a0: .4byte sEwramPointer

    thumb_func_start copy_time_attack_time
copy_time_attack_time: @ 0x0807a1a4
    push {r4, r5, r6, r7, lr}
    ldr r7, lbl_0807a2b4 @ =sNonGameplayRamPointer
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x64
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807a2ae
    adds r0, r1, #0
    adds r0, #0x48
    bl unk_7f60c
    ldr r6, lbl_0807a2b8 @ =gTimeAttackRecord
    ldrb r0, [r6, #0x14]
    movs r5, #0x63
    cmp r0, #0x62
    bhi lbl_0807a1c8
    adds r5, r0, #0
lbl_0807a1c8:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x50
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x51
    strb r0, [r4]
    ldrb r0, [r6, #0x15]
    movs r5, #0x3b
    cmp r0, #0x3a
    bhi lbl_0807a1ee
    adds r5, r0, #0
lbl_0807a1ee:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x52
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x53
    strb r0, [r4]
    ldrb r0, [r6, #0x16]
    movs r5, #0x3b
    cmp r0, #0x3a
    bhi lbl_0807a214
    adds r5, r0, #0
lbl_0807a214:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x54
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x55
    strb r0, [r4]
    adds r1, r6, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    movs r5, #0x63
    cmp r0, #0x62
    bhi lbl_0807a23e
    adds r5, r0, #0
lbl_0807a23e:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x56
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x57
    strb r0, [r4]
    adds r1, r6, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    movs r5, #0x3b
    cmp r0, #0x3a
    bhi lbl_0807a268
    adds r5, r0, #0
lbl_0807a268:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x58
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x59
    strb r0, [r4]
    adds r1, r6, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    movs r5, #0x3b
    cmp r0, #0x3a
    bhi lbl_0807a292
    adds r5, r0, #0
lbl_0807a292:
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, #0x5a
    strb r0, [r4]
    ldr r4, [r7]
    adds r0, r5, #0
    movs r1, #0xa
    bl __modsi3
    adds r4, #0x5b
    strb r0, [r4]
lbl_0807a2ae:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807a2b4: .4byte sNonGameplayRamPointer
lbl_0807a2b8: .4byte gTimeAttackRecord

    thumb_func_start sub_0807a2bc
sub_0807a2bc: @ 0x0807a2bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_0807a2ec @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r7, r2, #0
    cmp r0, #0xc
    bls lbl_0807a2e2
    b lbl_0807a7d4
lbl_0807a2e2:
    lsls r0, r0, #2
    ldr r1, lbl_0807a2f0 @ =lbl_0807a2f4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807a2ec: .4byte sNonGameplayRamPointer
lbl_0807a2f0: .4byte lbl_0807a2f4
lbl_0807a2f4: @ jump table
    .4byte lbl_0807a328 @ case 0
    .4byte lbl_0807a346 @ case 1
    .4byte lbl_0807a454 @ case 2
    .4byte lbl_0807a4d4 @ case 3
    .4byte lbl_0807a50c @ case 4
    .4byte lbl_0807a524 @ case 5
    .4byte lbl_0807a562 @ case 6
    .4byte lbl_0807a578 @ case 7
    .4byte lbl_0807a608 @ case 8
    .4byte lbl_0807a648 @ case 9
    .4byte lbl_0807a66c @ case 10
    .4byte lbl_0807a6e4 @ case 11
    .4byte lbl_0807a7a0 @ case 12
lbl_0807a328:
    cmp r4, #0
    beq lbl_0807a334
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #7
    b lbl_0807a33a
lbl_0807a334:
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #1
lbl_0807a33a:
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0x42
    movs r1, #0
    strh r1, [r0]
    b lbl_0807a7d4
lbl_0807a346:
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #9
    bhi lbl_0807a354
    b lbl_0807a7d4
lbl_0807a354:
    ldr r0, lbl_0807a42c @ =gWrittenToBLDALPHA_H
    movs r4, #0
    strh r4, [r0]
    ldr r1, lbl_0807a430 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    movs r0, #0
    mov r8, r0
    ldr r0, lbl_0807a434 @ =0x00003f42
    strh r0, [r2, #2]
    adds r4, r2, #0
    adds r4, #0xff
    ldrb r2, [r4]
    movs r1, #0xd
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r3, #4
    orrs r0, r3
    strb r0, [r4]
    ldr r0, [r7]
    ldr r2, lbl_0807a438 @ =0x0000010f
    adds r4, r0, r2
    ldrb r2, [r4]
    adds r0, r1, #0
    ands r0, r2
    orrs r0, r3
    strb r0, [r4]
    ldr r0, [r7]
    ldr r2, lbl_0807a43c @ =0x0000011f
    adds r4, r0, r2
    ldrb r2, [r4]
    adds r0, r1, #0
    ands r0, r2
    orrs r0, r3
    strb r0, [r4]
    ldr r0, [r7]
    adds r0, #0xef
    ldrb r2, [r0]
    ands r1, r2
    orrs r1, r3
    strb r1, [r0]
    ldr r0, [r7]
    ldr r3, lbl_0807a440 @ =0x0000013f
    adds r2, r0, r3
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r7]
    adds r3, #0x10
    adds r2, r0, r3
    ldrb r0, [r2]
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r7]
    adds r3, #0x10
    adds r2, r0, r3
    ldrb r0, [r2]
    orrs r0, r1
    strb r0, [r2]
    ldr r5, lbl_0807a444 @ =0x0600e000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    adds r3, r6, #0
    bl BitFill
    ldr r0, lbl_0807a448 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xa2
    lsls r0, r0, #7
    adds r1, r1, r0
    str r4, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0xc0
    bl DmaTransfer
    ldr r2, [r7]
    ldrh r0, [r2, #0x1e]
    strh r0, [r2, #4]
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_0807a44c @ =gBG0HOFS_NonGameplay
    strh r6, [r0]
    ldr r1, lbl_0807a450 @ =gBG0VOFS_NonGameplay
    movs r3, #0xc0
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x42
    mov r1, r8
    strh r1, [r0]
    adds r2, #0x40
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_0807a7d4
    .align 2, 0
lbl_0807a42c: .4byte gWrittenToBLDALPHA_H
lbl_0807a430: .4byte gWrittenToBLDALPHA_L
lbl_0807a434: .4byte 0x00003f42
lbl_0807a438: .4byte 0x0000010f
lbl_0807a43c: .4byte 0x0000011f
lbl_0807a440: .4byte 0x0000013f
lbl_0807a444: .4byte 0x0600e000
lbl_0807a448: .4byte sEwramPointer
lbl_0807a44c: .4byte gBG0HOFS_NonGameplay
lbl_0807a450: .4byte gBG0VOFS_NonGameplay
lbl_0807a454:
    movs r2, #1
    ldr r1, lbl_0807a46c @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a472
    movs r2, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807a470
    strh r2, [r1]
    b lbl_0807a472
    .align 2, 0
lbl_0807a46c: .4byte gWrittenToBLDALPHA_L
lbl_0807a470:
    strh r0, [r1]
lbl_0807a472:
    ldr r1, lbl_0807a4c8 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807a486
    movs r2, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807a484
    movs r0, #0x10
lbl_0807a484:
    strh r0, [r1]
lbl_0807a486:
    cmp r2, #0
    bne lbl_0807a48c
    b lbl_0807a7d4
lbl_0807a48c:
    ldr r1, [r7]
    adds r1, #0xff
    ldrb r0, [r1]
    movs r2, #0x20
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r7]
    ldr r3, lbl_0807a4cc @ =0x0000010f
    adds r1, r0, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r7]
    adds r3, #0x10
    adds r1, r0, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r7]
    adds r1, #0xef
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r7]
    ldrh r2, [r1]
    ldr r0, lbl_0807a4d0 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
    b lbl_0807a77e
    .align 2, 0
lbl_0807a4c8: .4byte gWrittenToBLDALPHA_H
lbl_0807a4cc: .4byte 0x0000010f
lbl_0807a4d0: .4byte 0x0000fdff
lbl_0807a4d4:
    ldr r1, lbl_0807a500 @ =gBG0VOFS_NonGameplay
    ldrh r0, [r1]
    ldr r2, lbl_0807a504 @ =0x000007ff
    cmp r0, r2
    bhi lbl_0807a4ec
    adds r0, #0x40
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r2
    bhi lbl_0807a4ec
    b lbl_0807a7d4
lbl_0807a4ec:
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    strh r0, [r1]
    bl sub_08079fb8
    ldr r0, lbl_0807a508 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_0807a77e
    .align 2, 0
lbl_0807a500: .4byte gBG0VOFS_NonGameplay
lbl_0807a504: .4byte 0x000007ff
lbl_0807a508: .4byte sNonGameplayRamPointer
lbl_0807a50c:
    bl sub_08079ecc
    ldr r0, lbl_0807a51c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldr r0, lbl_0807a520 @ =0x00003f54
    strh r0, [r1, #2]
    b lbl_0807a77e
    .align 2, 0
lbl_0807a51c: .4byte sNonGameplayRamPointer
lbl_0807a520: .4byte 0x00003f54
lbl_0807a524:
    movs r2, #1
    ldr r1, lbl_0807a550 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807a53a
    movs r2, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807a538
    movs r0, #0x10
lbl_0807a538:
    strh r0, [r1]
lbl_0807a53a:
    ldr r1, lbl_0807a554 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a55a
    movs r2, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807a558
    strh r2, [r1]
    b lbl_0807a55a
    .align 2, 0
lbl_0807a550: .4byte gWrittenToBLDALPHA_L
lbl_0807a554: .4byte gWrittenToBLDALPHA_H
lbl_0807a558:
    strh r0, [r1]
lbl_0807a55a:
    cmp r2, #0
    bne lbl_0807a560
    b lbl_0807a7d4
lbl_0807a560:
    b lbl_0807a77c
lbl_0807a562:
    ldr r1, [r7]
    ldrh r2, [r1]
    ldr r0, lbl_0807a574 @ =0x0000fcff
    ands r0, r2
    movs r2, #0
    strh r0, [r1]
    strh r2, [r1, #2]
    movs r0, #1
    b lbl_0807a7d6
    .align 2, 0
lbl_0807a574: .4byte 0x0000fcff
lbl_0807a578:
    ldr r0, [r7]
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #3
    bhi lbl_0807a584
    b lbl_0807a7d4
lbl_0807a584:
    ldr r6, lbl_0807a5e4 @ =0x0600e000
    movs r4, #0x80
    lsls r4, r4, #4
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r4, #0
    bl BitFill
    ldr r0, lbl_0807a5e8 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0xa2
    lsls r3, r3, #7
    adds r1, r1, r3
    str r5, [sp]
    movs r0, #3
    adds r2, r6, #0
    movs r3, #0xc0
    bl DmaTransfer
    ldr r1, lbl_0807a5ec @ =gBG0HOFS_NonGameplay
    ldr r0, lbl_0807a5f0 @ =gBG0VOFS_NonGameplay
    strh r4, [r0]
    strh r4, [r1]
    ldr r1, [r7]
    movs r2, #0
    ldr r0, lbl_0807a5f4 @ =0x00003f54
    strh r0, [r1, #2]
    ldr r0, lbl_0807a5f8 @ =gWrittenToBLDALPHA_H
    strh r2, [r0]
    ldr r0, lbl_0807a5fc @ =gWrittenToBLDALPHA_L
    strh r5, [r0]
    ldr r0, lbl_0807a600 @ =gBG1HOFS_NonGameplay
    strh r4, [r0]
    ldr r0, lbl_0807a604 @ =gBG1VOFS_NonGameplay
    strh r4, [r0]
    ldrh r0, [r1, #0x1e]
    strh r0, [r1, #4]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0807a77e
    .align 2, 0
lbl_0807a5e4: .4byte 0x0600e000
lbl_0807a5e8: .4byte sEwramPointer
lbl_0807a5ec: .4byte gBG0HOFS_NonGameplay
lbl_0807a5f0: .4byte gBG0VOFS_NonGameplay
lbl_0807a5f4: .4byte 0x00003f54
lbl_0807a5f8: .4byte gWrittenToBLDALPHA_H
lbl_0807a5fc: .4byte gWrittenToBLDALPHA_L
lbl_0807a600: .4byte gBG1HOFS_NonGameplay
lbl_0807a604: .4byte gBG1VOFS_NonGameplay
lbl_0807a608:
    movs r2, #1
    ldr r1, lbl_0807a620 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a626
    movs r2, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807a624
    strh r2, [r1]
    b lbl_0807a626
    .align 2, 0
lbl_0807a620: .4byte gWrittenToBLDALPHA_L
lbl_0807a624:
    strh r0, [r1]
lbl_0807a626:
    ldr r1, lbl_0807a644 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807a63a
    movs r2, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807a638
    movs r0, #0x10
lbl_0807a638:
    strh r0, [r1]
lbl_0807a63a:
    cmp r2, #0
    bne lbl_0807a640
    b lbl_0807a7d4
lbl_0807a640:
    b lbl_0807a77c
    .align 2, 0
lbl_0807a644: .4byte gWrittenToBLDALPHA_H
lbl_0807a648:
    ldr r2, lbl_0807a668 @ =gBG0VOFS_NonGameplay
    ldrh r0, [r2]
    movs r1, #0xc0
    lsls r1, r1, #3
    cmp r0, r1
    bls lbl_0807a662
    subs r0, #0x40
    strh r0, [r2]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_0807a662
    b lbl_0807a7d4
lbl_0807a662:
    strh r1, [r2]
    b lbl_0807a77c
    .align 2, 0
lbl_0807a668: .4byte gBG0VOFS_NonGameplay
lbl_0807a66c:
    ldr r0, [r7]
    adds r0, #0x3f
    movs r1, #5
    strb r1, [r0]
    ldr r1, [r7]
    ldrh r0, [r1, #0x18]
    strh r0, [r1, #6]
    ldrh r2, [r1]
    ldr r0, lbl_0807a6d4 @ =0x0000fbff
    ands r0, r2
    movs r3, #0x90
    lsls r3, r3, #5
    adds r2, r3, #0
    orrs r0, r2
    strh r0, [r1]
    adds r1, #0x3f
    ldrb r1, [r1]
    movs r0, #0
    bl sub_08078504
    ldr r1, [r7]
    adds r1, #0xff
    ldrb r3, [r1]
    movs r2, #0x21
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r0, r3
    strb r0, [r1]
    ldr r0, [r7]
    ldr r1, lbl_0807a6d8 @ =0x0000010f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r7]
    ldr r1, lbl_0807a6dc @ =0x0000011f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r7]
    adds r0, #0xef
    ldrb r1, [r0]
    ands r2, r1
    strb r2, [r0]
    ldr r1, [r7]
    ldr r0, lbl_0807a6e0 @ =0x00003f42
    strh r0, [r1, #2]
    b lbl_0807a77e
    .align 2, 0
lbl_0807a6d4: .4byte 0x0000fbff
lbl_0807a6d8: .4byte 0x0000010f
lbl_0807a6dc: .4byte 0x0000011f
lbl_0807a6e0: .4byte 0x00003f42
lbl_0807a6e4:
    movs r2, #1
    ldr r1, lbl_0807a6fc @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807a702
    movs r2, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807a700
    strh r2, [r1]
    b lbl_0807a702
    .align 2, 0
lbl_0807a6fc: .4byte gWrittenToBLDALPHA_H
lbl_0807a700:
    strh r0, [r1]
lbl_0807a702:
    ldr r1, lbl_0807a788 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807a716
    movs r2, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807a714
    movs r0, #0x10
lbl_0807a714:
    strh r0, [r1]
lbl_0807a716:
    cmp r2, #0
    beq lbl_0807a7d4
    ldr r1, [r7]
    adds r1, #0xff
    ldrb r3, [r1]
    movs r2, #0xd
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r0, r3
    strb r0, [r1]
    ldr r0, [r7]
    ldr r1, lbl_0807a78c @ =0x0000010f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r7]
    ldr r1, lbl_0807a790 @ =0x0000011f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r7]
    adds r0, #0xef
    ldrb r1, [r0]
    ands r2, r1
    strb r2, [r0]
    ldr r0, [r7]
    ldr r2, lbl_0807a794 @ =0x0000013f
    adds r3, r0, r2
    ldrb r2, [r3]
    movs r1, #0x21
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r7]
    ldr r2, lbl_0807a798 @ =0x0000014f
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r7]
    ldr r3, lbl_0807a79c @ =0x0000015f
    adds r2, r0, r3
    ldrb r0, [r2]
    ands r1, r0
    strb r1, [r2]
lbl_0807a77c:
    ldr r1, [r7]
lbl_0807a77e:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807a7d4
    .align 2, 0
lbl_0807a788: .4byte gWrittenToBLDALPHA_L
lbl_0807a78c: .4byte 0x0000010f
lbl_0807a790: .4byte 0x0000011f
lbl_0807a794: .4byte 0x0000013f
lbl_0807a798: .4byte 0x0000014f
lbl_0807a79c: .4byte 0x0000015f
lbl_0807a7a0:
    ldr r2, [r7]
    ldrh r1, [r2]
    ldr r0, lbl_0807a7c4 @ =0x0000feff
    ands r0, r1
    movs r3, #0
    strh r0, [r2]
    ldr r0, lbl_0807a7c8 @ =gBG0HOFS_NonGameplay
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_0807a7cc @ =gBG0VOFS_NonGameplay
    strh r1, [r0]
    ldr r0, lbl_0807a7d0 @ =gGameModeSub2
    strb r3, [r0]
    movs r0, #1
    b lbl_0807a7d6
    .align 2, 0
lbl_0807a7c4: .4byte 0x0000feff
lbl_0807a7c8: .4byte gBG0HOFS_NonGameplay
lbl_0807a7cc: .4byte gBG0VOFS_NonGameplay
lbl_0807a7d0: .4byte gGameModeSub2
lbl_0807a7d4:
    movs r0, #0
lbl_0807a7d6:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start settings_subroutine
settings_subroutine: @ 0x0807a7e4
    push {r4, r5, r6, lr}
    ldr r1, lbl_0807a800 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x3e
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #5
    bls lbl_0807a7f6
    b lbl_0807aa20
lbl_0807a7f6:
    lsls r0, r0, #2
    ldr r1, lbl_0807a804 @ =lbl_0807a808
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807a800: .4byte sNonGameplayRamPointer
lbl_0807a804: .4byte lbl_0807a808
lbl_0807a808: @ jump table
    .4byte lbl_0807a820 @ case 0
    .4byte lbl_0807a870 @ case 1
    .4byte lbl_0807a88a @ case 2
    .4byte lbl_0807a96c @ case 3
    .4byte lbl_0807a9f8 @ case 4
    .4byte lbl_0807aa14 @ case 5
lbl_0807a820:
    ldr r0, [r4]
    ldr r2, lbl_0807a868 @ =gOptionsOptionSelected
    movs r1, #0
    ldrsb r1, [r2, r1]
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807a840
    ldrb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    blt lbl_0807a840
    lsrs r0, r0, #0x18
    cmp r0, #6
    bls lbl_0807a844
lbl_0807a840:
    movs r0, #0
    strb r0, [r2]
lbl_0807a844:
    movs r0, #0
    bl sub_08078b98
    bl sub_0807b008
    ldr r0, lbl_0807a86c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    movs r3, #0xa0
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    adds r1, #0x3e
    movs r0, #2
    strb r0, [r1]
    b lbl_0807aa20
    .align 2, 0
lbl_0807a868: .4byte gOptionsOptionSelected
lbl_0807a86c: .4byte sNonGameplayRamPointer
lbl_0807a870:
    ldr r0, [r4]
    ldrh r0, [r0, #0x3c]
    cmp r0, #0x10
    bhi lbl_0807a87a
    b lbl_0807aa20
lbl_0807a87a:
    movs r0, #0
    bl sub_08078b98
    ldr r0, [r4]
    adds r0, #0x3e
    movs r1, #2
    strb r1, [r0]
    b lbl_0807aa20
lbl_0807a88a:
    bl CheckForMaintainedInput
    ldr r0, lbl_0807a8b8 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    bne lbl_0807a898
    b lbl_0807aa20
lbl_0807a898:
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0807a8c4
    ldr r0, lbl_0807a8bc @ =0x00000209
    bl SoundPlay
    ldr r0, lbl_0807a8c0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    movs r1, #4
    strb r1, [r0]
    b lbl_0807aa20
    .align 2, 0
lbl_0807a8b8: .4byte gChangedInput
lbl_0807a8bc: .4byte 0x00000209
lbl_0807a8c0: .4byte sNonGameplayRamPointer
lbl_0807a8c4:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807a918
    ldr r5, lbl_0807a910 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    ldr r1, lbl_0807a914 @ =gOptionsOptionSelected
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807a8e4
    b lbl_0807aa20
lbl_0807a8e4:
    movs r0, #2
    bl sub_08078b98
    ldr r0, [r5]
    adds r0, #0x40
    strb r4, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x42
    strh r4, [r0]
    adds r0, #0x26
    strh r4, [r0]
    adds r0, #2
    strh r4, [r0]
    bl reset_io_transfter_info
    ldr r0, [r5]
    adds r0, #0x3e
    movs r1, #3
    strb r1, [r0]
    b lbl_0807aa20
    .align 2, 0
lbl_0807a910: .4byte sNonGameplayRamPointer
lbl_0807a914: .4byte gOptionsOptionSelected
lbl_0807a918:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0807a938
    ldr r1, lbl_0807a934 @ =gOptionsOptionSelected
    ldrb r2, [r1]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0807a92e
    b lbl_0807aa20
lbl_0807a92e:
    subs r0, r2, #1
    strb r0, [r1]
    b lbl_0807a95a
    .align 2, 0
lbl_0807a934: .4byte gOptionsOptionSelected
lbl_0807a938:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0807aa20
    ldr r0, lbl_0807a964 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldr r2, lbl_0807a968 @ =gOptionsOptionSelected
    movs r1, #0
    ldrsb r1, [r2, r1]
    adds r0, r0, r1
    adds r0, #0x5d
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807aa20
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
lbl_0807a95a:
    movs r0, #1
    bl sub_08078b98
    b lbl_0807aa20
    .align 2, 0
lbl_0807a964: .4byte sNonGameplayRamPointer
lbl_0807a968: .4byte gOptionsOptionSelected
lbl_0807a96c:
    ldr r6, lbl_0807a9ac @ =0x08760bfc
    ldr r0, [r4]
    ldr r5, lbl_0807a9b0 @ =gOptionsOptionSelected
    movs r1, #0
    ldrsb r1, [r5, r1]
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldr r0, [r0]
    bl _call_via_r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807aa20
    cmp r0, #2
    bne lbl_0807a9b8
    ldr r2, lbl_0807a9b4 @ =gGameModeSub2
    ldr r0, [r4]
    movs r1, #0
    ldrsb r1, [r5, r1]
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    strb r0, [r2]
    adds r1, r2, #0
    b lbl_0807a9be
    .align 2, 0
lbl_0807a9ac: .4byte 0x08760bfc
lbl_0807a9b0: .4byte gOptionsOptionSelected
lbl_0807a9b4: .4byte gGameModeSub2
lbl_0807a9b8:
    ldr r1, lbl_0807a9d0 @ =gGameModeSub2
    movs r0, #0
    strb r0, [r1]
lbl_0807a9be:
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_0807a9d8
    ldr r0, lbl_0807a9d4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    movs r1, #5
    b lbl_0807a9e6
    .align 2, 0
lbl_0807a9d0: .4byte gGameModeSub2
lbl_0807a9d4: .4byte sNonGameplayRamPointer
lbl_0807a9d8:
    movs r0, #3
    bl sub_08078b98
    ldr r0, lbl_0807a9f4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    movs r1, #2
lbl_0807a9e6:
    strb r1, [r0]
    ldr r0, lbl_0807a9f4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0x3c]
    b lbl_0807aa20
    .align 2, 0
lbl_0807a9f4: .4byte sNonGameplayRamPointer
lbl_0807a9f8:
    ldr r0, [r4]
    adds r0, #0x63
    movs r4, #0
    strb r4, [r0]
    movs r0, #0xa
    bl sub_0800427c
    ldr r0, lbl_0807aa10 @ =gGameModeSub2
    strb r4, [r0]
    movs r0, #1
    b lbl_0807aa26
    .align 2, 0
lbl_0807aa10: .4byte gGameModeSub2
lbl_0807aa14:
    ldr r0, [r4]
    ldrh r0, [r0, #0x3c]
    cmp r0, #0xa
    bls lbl_0807aa20
    movs r0, #1
    b lbl_0807aa26
lbl_0807aa20:
    bl sub_08078da0
    movs r0, #0
lbl_0807aa26:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start reset_io_transfter_info
reset_io_transfter_info: @ 0x0807aa2c
    push {r4, r5, lr}
    ldr r0, lbl_0807aa60 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    ldr r1, lbl_0807aa64 @ =gOptionsOptionSelected
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #6
    bgt lbl_0807aa5a
    cmp r0, #5
    blt lbl_0807aa5a
    ldr r2, lbl_0807aa68 @ =gIoTransferInfo
    adds r1, r2, #0
    ldr r0, lbl_0807aa6c @ =0x085d914c
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldr r0, lbl_0807aa70 @ =file_select_menu_process_oam
    str r0, [r2]
lbl_0807aa5a:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807aa60: .4byte sNonGameplayRamPointer
lbl_0807aa64: .4byte gOptionsOptionSelected
lbl_0807aa68: .4byte gIoTransferInfo
lbl_0807aa6c: .4byte 0x085d914c
lbl_0807aa70: .4byte file_select_menu_process_oam

    thumb_func_start OptionsNesMetroidSubroutine
OptionsNesMetroidSubroutine: @ 0x0807aa74
    push {r4, r5, lr}
    ldr r2, lbl_0807aa9c @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #4
    bls lbl_0807aa90
    b lbl_0807abb0
lbl_0807aa90:
    lsls r0, r0, #2
    ldr r1, lbl_0807aaa0 @ =lbl_0807aaa4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807aa9c: .4byte sNonGameplayRamPointer
lbl_0807aaa0: .4byte lbl_0807aaa4
lbl_0807aaa4: @ jump table
    .4byte lbl_0807aab8 @ case 0
    .4byte lbl_0807aaf8 @ case 1
    .4byte lbl_0807ab30 @ case 2
    .4byte lbl_0807ab58 @ case 3
    .4byte lbl_0807ab98 @ case 4
lbl_0807aab8:
    ldr r0, lbl_0807aadc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    beq lbl_0807aae0
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    movs r2, #0
    movs r1, #0
    strh r1, [r3]
    adds r0, #0x40
    strb r2, [r0]
lbl_0807aad8:
    movs r0, #1
    b lbl_0807abb2
    .align 2, 0
lbl_0807aadc: .4byte gChangedInput
lbl_0807aae0:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0xa
    bls lbl_0807abb0
    adds r0, r1, #0
    adds r0, #0x40
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    b lbl_0807ab20
lbl_0807aaf8:
    movs r2, #0
    ldr r5, lbl_0807ab28 @ =0x087d80a0
    ldr r3, lbl_0807ab2c @ =0x0845f440
lbl_0807aafe:
    adds r0, r2, r5
    adds r1, r2, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0807aad8
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0x11
    bls lbl_0807aafe
    ldr r1, [r4]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
lbl_0807ab20:
    ldr r0, [r4]
    adds r0, #0x42
    strh r2, [r0]
    b lbl_0807abb0
    .align 2, 0
lbl_0807ab28: .4byte 0x087d80a0
lbl_0807ab2c: .4byte 0x0845f440
lbl_0807ab30:
    bl unk_33dc
    ldr r2, lbl_0807ab50 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    movs r3, #0
    movs r0, #0xff
    strh r0, [r1, #2]
    ldr r0, lbl_0807ab54 @ =gWrittenToBLDY_NonGameplay
    strh r3, [r0]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r2]
    b lbl_0807ab8a
    .align 2, 0
lbl_0807ab50: .4byte sNonGameplayRamPointer
lbl_0807ab54: .4byte gWrittenToBLDY_NonGameplay
lbl_0807ab58:
    ldr r2, lbl_0807ab90 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r2]
    adds r0, #2
    strh r0, [r2]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xf
    bls lbl_0807abb0
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r0, #0
    strh r0, [r1]
    ldr r1, [r4]
    movs r3, #0
    strh r3, [r1, #2]
    strh r3, [r2]
    ldrh r2, [r1]
    ldr r0, lbl_0807ab94 @ =0x0000e0ff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r4]
lbl_0807ab8a:
    adds r0, #0x42
    strh r3, [r0]
    b lbl_0807abb0
    .align 2, 0
lbl_0807ab90: .4byte gWrittenToBLDY_NonGameplay
lbl_0807ab94: .4byte 0x0000e0ff
lbl_0807ab98:
    ldr r1, lbl_0807abb8 @ =0x04000208
    movs r0, #0
    strh r0, [r1]
    subs r1, #6
    ldr r2, lbl_0807abbc @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #0x80
    lsls r0, r0, #0x14
    ldr r1, lbl_0807abc0 @ =0x087d8000
    bl _call_via_r1
lbl_0807abb0:
    movs r0, #0
lbl_0807abb2:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807abb8: .4byte 0x04000208
lbl_0807abbc: .4byte 0x0000ffff
lbl_0807abc0: .4byte 0x087d8000

    thumb_func_start OptionsSubMenu_Empty
OptionsSubMenu_Empty: @ 0x080OptionsSubMenu_Empty
    push {lr}
    ldr r0, lbl_0807abe8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x42
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r0, lbl_0807abec @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807abf0
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807abf0
    movs r0, #1
    b lbl_0807abf2
    .align 2, 0
lbl_0807abe8: .4byte sNonGameplayRamPointer
lbl_0807abec: .4byte gChangedInput
lbl_0807abf0:
    movs r0, #0
lbl_0807abf2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start unk_7abf8
unk_7abf8: @ 0x0807abf8
    push {r4, r5, r6, lr}
    ldr r0, lbl_0807ac28 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r1, r3, #0
    adds r1, #0x42
    ldrh r0, [r1]
    adds r5, r0, #1
    movs r6, #0
    strh r5, [r1]
    ldr r0, lbl_0807ac2c @ =gChangedInput
    ldrh r2, [r0]
    movs r0, #2
    ands r0, r2
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0807ac30
    movs r0, #0
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x40
    strb r6, [r0]
    movs r0, #1
    b lbl_0807ac4e
    .align 2, 0
lbl_0807ac28: .4byte sNonGameplayRamPointer
lbl_0807ac2c: .4byte gChangedInput
lbl_0807ac30:
    movs r0, #1
    ands r0, r2
    cmp r0, #0
    bne lbl_0807ac40
    lsls r0, r5, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xa
    bls lbl_0807ac4c
lbl_0807ac40:
    strh r4, [r1]
    adds r0, r3, #0
    adds r0, #0x40
    strb r6, [r0]
    movs r0, #2
    b lbl_0807ac4e
lbl_0807ac4c:
    movs r0, #0
lbl_0807ac4e:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start OptionsStereoSubroutine
OptionsStereoSubroutine: @ 0x0807ac54
    push {r4, r5, lr}
    ldr r4, lbl_0807ac70 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x40
    ldrb r2, [r3]
    cmp r2, #1
    beq lbl_0807ac86
    cmp r2, #1
    bgt lbl_0807ac74
    cmp r2, #0
    beq lbl_0807ac7e
    b lbl_0807ad08
    .align 2, 0
lbl_0807ac70: .4byte sNonGameplayRamPointer
lbl_0807ac74:
    cmp r2, #2
    beq lbl_0807ace4
    cmp r2, #3
    beq lbl_0807acfa
    b lbl_0807ad08
lbl_0807ac7e:
    movs r0, #2
    bl sub_08078ca0
    b lbl_0807acee
lbl_0807ac86:
    movs r5, #0
    ldr r0, lbl_0807aca4 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807ad08
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0807aca8
    movs r0, #0xfe
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0807acee
    .align 2, 0
lbl_0807aca4: .4byte gChangedInput
lbl_0807aca8:
    ldr r3, lbl_0807acbc @ =gStereoFlag
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0807acc0
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0807accc
    strb r2, [r3]
    b lbl_0807acd0
    .align 2, 0
lbl_0807acbc: .4byte gStereoFlag
lbl_0807acc0:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0807accc
    strb r5, [r3]
    movs r5, #1
lbl_0807accc:
    cmp r5, #0
    beq lbl_0807ad08
lbl_0807acd0:
    movs r0, #0xfd
    lsls r0, r0, #1
    bl SoundPlay
    movs r0, #2
    bl sub_08078ca0
    bl sub_08078228
    b lbl_0807ad08
lbl_0807ace4:
    movs r0, #1
    bl sub_08078ca0
    bl sub_08074b6c
lbl_0807acee:
    ldr r1, [r4]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807ad08
lbl_0807acfa:
    adds r0, #0x42
    movs r2, #0
    movs r1, #0
    strh r1, [r0]
    strb r2, [r3]
    movs r0, #1
    b lbl_0807ad0a
lbl_0807ad08:
    movs r0, #0
lbl_0807ad0a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start OptionsSoundTestSubroutine
OptionsSoundTestSubroutine: @ 0x0807ad10
    push {r4, r5, lr}
    ldr r2, lbl_0807ad38 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #8
    bls lbl_0807ad2c
    b lbl_0807b000
lbl_0807ad2c:
    lsls r0, r0, #2
    ldr r1, lbl_0807ad3c @ =lbl_0807ad40
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807ad38: .4byte sNonGameplayRamPointer
lbl_0807ad3c: .4byte lbl_0807ad40
lbl_0807ad40: @ jump table
    .4byte lbl_0807ad64 @ case 0
    .4byte lbl_0807add8 @ case 1
    .4byte lbl_0807ae1c @ case 2
    .4byte lbl_0807af08 @ case 3
    .4byte lbl_0807af30 @ case 4
    .4byte lbl_0807af6c @ case 5
    .4byte lbl_0807af80 @ case 6
    .4byte lbl_0807afcc @ case 7
    .4byte lbl_0807afec @ case 8
lbl_0807ad64:
    bl sub_0807b008
    cmp r0, #0
    beq lbl_0807ad80
    ldr r1, lbl_0807adc4 @ =0x08760bac
    ldr r0, lbl_0807adc8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x63
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    bl sub_08004228
lbl_0807ad80:
    bl sub_0807b094
    ldr r0, lbl_0807adcc @ =0x000001fd
    bl SoundPlay
    ldr r5, lbl_0807adc8 @ =sNonGameplayRamPointer
    ldr r0, [r5]
    movs r4, #0x95
    lsls r4, r4, #2
    adds r0, r0, r4
    movs r1, #0xe
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    ldr r2, lbl_0807add0 @ =0x00000226
    adds r0, r1, r2
    ldrh r2, [r0]
    ldr r3, lbl_0807add4 @ =0x00000256
    adds r0, r1, r3
    strh r2, [r0]
    movs r2, #0x89
    lsls r2, r2, #2
    adds r0, r1, r2
    ldrh r0, [r0]
    adds r4, r1, r4
    strh r0, [r4]
    adds r3, #9
    adds r1, r1, r3
    ldrb r0, [r1]
    movs r2, #3
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    b lbl_0807afde
    .align 2, 0
lbl_0807adc4: .4byte 0x08760bac
lbl_0807adc8: .4byte sNonGameplayRamPointer
lbl_0807adcc: .4byte 0x000001fd
lbl_0807add0: .4byte 0x00000226
lbl_0807add4: .4byte 0x00000256
lbl_0807add8:
    ldr r2, [r4]
    ldr r1, lbl_0807ae18 @ =0x0000025f
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807adea
    b lbl_0807b000
lbl_0807adea:
    movs r3, #0x89
    lsls r3, r3, #2
    adds r0, r2, r3
    movs r1, #7
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r1, #0x8d
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #9
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x91
    lsls r2, r2, #2
    adds r0, r0, r2
    movs r1, #0xb
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    b lbl_0807afde
    .align 2, 0
lbl_0807ae18: .4byte 0x0000025f
lbl_0807ae1c:
    movs r5, #0
    ldr r0, lbl_0807ae38 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807aed6
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807ae3c
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #6
    strb r1, [r0]
    b lbl_0807aed6
    .align 2, 0
lbl_0807ae38: .4byte gChangedInput
lbl_0807ae3c:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807ae6c
    ldr r1, lbl_0807ae68 @ =0x08760bac
    ldr r0, [r4]
    adds r0, #0x63
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    bl sub_08004260
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    strh r5, [r3]
    adds r0, #0x40
    movs r1, #5
    strb r1, [r0]
    b lbl_0807aed6
    .align 2, 0
lbl_0807ae68: .4byte 0x08760bac
lbl_0807ae6c:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0807aea0
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x63
    ldrb r0, [r1]
    cmp r0, #0x16
    bhi lbl_0807ae84
    adds r0, #1
    b lbl_0807ae86
lbl_0807ae84:
    movs r0, #1
lbl_0807ae86:
    strb r0, [r1]
    ldr r0, [r4]
    movs r3, #0x91
    lsls r3, r3, #2
    adds r0, r0, r3
    movs r1, #0xa
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #3
    strb r1, [r0]
    b lbl_0807aedc
lbl_0807aea0:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0807aed6
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0x63
    ldrb r0, [r1]
    cmp r0, #1
    bls lbl_0807aeb8
    subs r0, #1
    b lbl_0807aeba
lbl_0807aeb8:
    movs r0, #0x17
lbl_0807aeba:
    strb r0, [r1]
    ldr r0, [r4]
    movs r1, #0x8d
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #8
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #4
    strb r1, [r0]
    movs r5, #1
    rsbs r5, r5, #0
lbl_0807aed6:
    cmp r5, #0
    bne lbl_0807aedc
    b lbl_0807b000
lbl_0807aedc:
    ldr r0, lbl_0807aefc @ =0x0000020e
    bl SoundPlay
    ldr r1, lbl_0807af00 @ =0x08760bac
    ldr r0, lbl_0807af04 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x63
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    bl sub_08004228
    bl sub_0807b094
    b lbl_0807b000
    .align 2, 0
lbl_0807aefc: .4byte 0x0000020e
lbl_0807af00: .4byte 0x08760bac
lbl_0807af04: .4byte sNonGameplayRamPointer
lbl_0807af08:
    ldr r2, [r4]
    ldr r3, lbl_0807af28 @ =0x0000024e
    adds r0, r2, r3
    ldrb r0, [r0]
    cmp r0, #0xa
    beq lbl_0807b000
    movs r1, #0x8f
    lsls r1, r1, #2
    adds r0, r2, r1
    ldrb r1, [r0]
    subs r3, #2
    adds r0, r2, r3
    strb r1, [r0]
    ldr r0, [r4]
    ldr r2, lbl_0807af2c @ =0x0000023d
    b lbl_0807af4e
    .align 2, 0
lbl_0807af28: .4byte 0x0000024e
lbl_0807af2c: .4byte 0x0000023d
lbl_0807af30:
    ldr r2, [r4]
    ldr r1, lbl_0807af64 @ =0x0000023e
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #8
    beq lbl_0807b000
    movs r3, #0x93
    lsls r3, r3, #2
    adds r0, r2, r3
    ldrb r1, [r0]
    subs r3, #0x10
    adds r0, r2, r3
    strb r1, [r0]
    ldr r0, [r4]
    ldr r2, lbl_0807af68 @ =0x0000024d
lbl_0807af4e:
    adds r1, r0, r2
    ldrb r1, [r1]
    adds r3, #1
    adds r0, r0, r3
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #2
    strb r1, [r0]
    b lbl_0807b000
    .align 2, 0
lbl_0807af64: .4byte 0x0000023e
lbl_0807af68: .4byte 0x0000024d
lbl_0807af6c:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x1e
    bls lbl_0807b000
    adds r1, #0x40
    movs r0, #2
    strb r0, [r1]
    b lbl_0807b000
lbl_0807af80:
    movs r0, #0xff
    lsls r0, r0, #1
    bl SoundPlay
    ldr r4, lbl_0807afc4 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    movs r1, #0x89
    lsls r1, r1, #2
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x8d
    lsls r2, r2, #2
    adds r0, r0, r2
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r3, #0x91
    lsls r3, r3, #2
    adds r0, r0, r3
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    ldr r0, lbl_0807afc8 @ =0x0000025e
    adds r1, r1, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r4]
    b lbl_0807afde
    .align 2, 0
lbl_0807afc4: .4byte sNonGameplayRamPointer
lbl_0807afc8: .4byte 0x0000025e
lbl_0807afcc:
    ldr r2, [r4]
    ldr r1, lbl_0807afe8 @ =0x0000025f
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807b000
    adds r1, r2, #0
lbl_0807afde:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807b000
    .align 2, 0
lbl_0807afe8: .4byte 0x0000025f
lbl_0807afec:
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    movs r2, #0
    movs r1, #0
    strh r1, [r3]
    adds r0, #0x40
    strb r2, [r0]
    movs r0, #1
    b lbl_0807b002
lbl_0807b000:
    movs r0, #0
lbl_0807b002:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_0807b008
sub_0807b008: @ 0x0807b008
    push {r4, r5, r6, r7, lr}
    movs r7, #0
    ldr r4, lbl_0807b088 @ =gMusicInfo
    ldr r5, lbl_0807b08c @ =0x08760bac
    ldr r2, lbl_0807b090 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r3, r0, #0
    adds r3, #0x63
    ldrb r0, [r3]
    lsls r0, r0, #1
    adds r0, r0, r5
    ldrh r1, [r4, #0x1c]
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0807b06c
    movs r7, #1
    movs r0, #0x17
    strb r0, [r3]
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0x63
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807b076
    lsls r0, r0, #1
    adds r0, r0, r5
    ldrh r1, [r4, #0x1c]
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0807b06c
    adds r3, r2, #0
    adds r6, r4, #0
    adds r4, r5, #0
lbl_0807b04a:
    ldr r1, [r3]
    adds r1, #0x63
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x63
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807b076
    lsls r0, r0, #1
    adds r0, r0, r4
    ldrh r1, [r6, #0x1c]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0807b04a
lbl_0807b06c:
    ldr r0, [r2]
    adds r0, #0x63
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807b07e
lbl_0807b076:
    ldr r0, [r2]
    adds r0, #0x63
    movs r1, #1
    strb r1, [r0]
lbl_0807b07e:
    adds r0, r7, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807b088: .4byte gMusicInfo
lbl_0807b08c: .4byte 0x08760bac
lbl_0807b090: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0807b094
sub_0807b094: @ 0x0807b094
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    ldr r0, lbl_0807b12c @ =sNonGameplayRamPointer
    mov sb, r0
    ldr r0, [r0]
    adds r0, #0x63
    ldrb r0, [r0]
    movs r1, #0xa
    bl __udivsi3
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x13
    movs r1, #0xa0
    lsls r1, r1, #4
    adds r4, r4, r1
    ldr r5, lbl_0807b130 @ =0x08415460
    adds r1, r4, r5
    ldr r2, lbl_0807b134 @ =0x060103c0
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DmaTransfer
    movs r0, #0x80
    lsls r0, r0, #3
    adds r0, r0, r5
    mov r8, r0
    add r4, r8
    ldr r2, lbl_0807b138 @ =0x060107c0
    str r6, [sp]
    movs r0, #3
    adds r1, r4, #0
    movs r3, #0x20
    bl DmaTransfer
    mov r1, sb
    ldr r0, [r1]
    adds r0, #0x63
    ldrb r0, [r0]
    movs r1, #0xa
    bl __umodsi3
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x13
    movs r0, #0xa0
    lsls r0, r0, #4
    adds r4, r4, r0
    adds r5, r4, r5
    ldr r2, lbl_0807b13c @ =0x060103e0
    str r6, [sp]
    movs r0, #3
    adds r1, r5, #0
    movs r3, #0x20
    bl DmaTransfer
    add r4, r8
    ldr r2, lbl_0807b140 @ =0x060107e0
    str r6, [sp]
    movs r0, #3
    adds r1, r4, #0
    movs r3, #0x20
    bl DmaTransfer
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807b12c: .4byte sNonGameplayRamPointer
lbl_0807b130: .4byte 0x08415460
lbl_0807b134: .4byte 0x060103c0
lbl_0807b138: .4byte 0x060107c0
lbl_0807b13c: .4byte 0x060103e0
lbl_0807b140: .4byte 0x060107e0

    thumb_func_start OptionsTimeAttackRecordsSubroutine
OptionsTimeAttackRecordsSubroutine: @ 0x0807b144
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r2, lbl_0807b174 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r4, r2, #0
    cmp r0, #0xc
    bls lbl_0807b168
    b lbl_0807b70c
lbl_0807b168:
    lsls r0, r0, #2
    ldr r1, lbl_0807b178 @ =lbl_0807b17c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807b174: .4byte sNonGameplayRamPointer
lbl_0807b178: .4byte lbl_0807b17c
lbl_0807b17c: @ jump table
    .4byte lbl_0807b1b0 @ case 0
    .4byte lbl_0807b3bc @ case 1
    .4byte lbl_0807b3e8 @ case 2
    .4byte lbl_0807b40c @ case 3
    .4byte lbl_0807b412 @ case 4
    .4byte lbl_0807b436 @ case 5
    .4byte lbl_0807b43c @ case 6
    .4byte lbl_0807b478 @ case 7
    .4byte lbl_0807b594 @ case 8
    .4byte lbl_0807b5c0 @ case 9
    .4byte lbl_0807b66c @ case 10
    .4byte lbl_0807b6c4 @ case 11
    .4byte lbl_0807b6f8 @ case 12
lbl_0807b1b0:
    ldr r6, lbl_0807b338 @ =sNonGameplayRamPointer
    ldr r0, [r6]
    adds r0, #0x64
    ldrb r1, [r0]
    movs r4, #1
    movs r0, #1
    mov sb, r0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b1cc
    movs r0, #0
    movs r1, #0x1f
    bl sub_080790cc
lbl_0807b1cc:
    ldr r0, [r6]
    adds r0, #0x64
    ldrb r1, [r0]
    movs r5, #2
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b1e4
    movs r0, #0
    movs r1, #0x20
    bl sub_080790cc
lbl_0807b1e4:
    ldr r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r1, r2
    ldrb r2, [r1]
    movs r3, #0x10
    rsbs r3, r3, #0
    mov r8, r3
    mov r0, r8
    ands r0, r2
    orrs r0, r4
    strb r0, [r1]
    ldr r2, [r6]
    ldr r0, lbl_0807b33c @ =0x000001ff
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r7, #4
    rsbs r7, r7, #0
    adds r0, r7, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r6]
    movs r3, #0xfb
    lsls r3, r3, #1
    adds r1, r2, r3
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r1]
    adds r0, #0xb4
    adds r1, r2, r0
    movs r0, #0xc0
    strh r0, [r1]
    movs r1, #0xf8
    lsls r1, r1, #1
    adds r2, r2, r1
    ldrb r1, [r2]
    mov r0, r8
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    subs r3, #7
    adds r2, r0, r3
    ldrb r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    orrs r0, r4
    strb r0, [r2]
    ldr r2, [r6]
    movs r4, #0xf3
    lsls r4, r4, #1
    adds r1, r2, r4
    movs r0, #0x80
    lsls r0, r0, #1
    strh r0, [r1]
    adds r0, #0xe4
    adds r1, r2, r0
    movs r0, #0x80
    strh r0, [r1]
    ldr r1, lbl_0807b340 @ =gBG1HOFS_NonGameplay
    movs r2, #0xdb
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807b344 @ =gBG1VOFS_NonGameplay
    movs r3, #0xe0
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_0807b348 @ =gBG0HOFS_NonGameplay
    movs r4, #0xcc
    lsls r4, r4, #3
    adds r0, r4, #0
    strh r0, [r1]
    ldr r1, lbl_0807b34c @ =gBG0VOFS_NonGameplay
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0807b350 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x90
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0807b354 @ =0x0600e000
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, [r6]
    ldrh r0, [r1, #0x1e]
    strh r0, [r1, #4]
    ldrh r0, [r1, #0x1c]
    strh r0, [r1, #6]
    adds r0, r1, #0
    adds r0, #0x64
    ldrb r2, [r0]
    mov r0, sb
    ands r0, r2
    cmp r0, #0
    beq lbl_0807b360
    adds r0, r5, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0807b360
    movs r4, #0xe2
    lsls r4, r4, #1
    adds r0, r1, r4
    movs r1, #9
    bl UpdateMenuOamDataID
    ldr r1, [r6]
    movs r5, #0xe8
    lsls r5, r5, #1
    adds r1, r1, r5
    ldrb r2, [r1]
    mov r0, r8
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r6]
    ldr r1, lbl_0807b358 @ =0x000001cf
    adds r2, r0, r1
    ldrb r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    movs r3, #0xe3
    lsls r3, r3, #1
    adds r2, r0, r3
    movs r1, #0x5c
    strh r1, [r2]
    adds r4, r0, r4
    movs r5, #0x60
    strh r5, [r4]
    movs r4, #0xea
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #0xb
    bl UpdateMenuOamDataID
    ldr r1, [r6]
    movs r0, #0xf0
    lsls r0, r0, #1
    adds r1, r1, r0
    ldrb r2, [r1]
    mov r0, r8
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r6]
    ldr r1, lbl_0807b35c @ =0x000001df
    adds r2, r0, r1
    ldrb r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    movs r2, #0xeb
    lsls r2, r2, #1
    adds r3, r0, r2
    movs r1, #0xd2
    lsls r1, r1, #1
    strh r1, [r3]
    adds r0, r0, r4
    strh r5, [r0]
    b lbl_0807b37e
    .align 2, 0
lbl_0807b338: .4byte sNonGameplayRamPointer
lbl_0807b33c: .4byte 0x000001ff
lbl_0807b340: .4byte gBG1HOFS_NonGameplay
lbl_0807b344: .4byte gBG1VOFS_NonGameplay
lbl_0807b348: .4byte gBG0HOFS_NonGameplay
lbl_0807b34c: .4byte gBG0VOFS_NonGameplay
lbl_0807b350: .4byte sEwramPointer
lbl_0807b354: .4byte 0x0600e000
lbl_0807b358: .4byte 0x000001cf
lbl_0807b35c: .4byte 0x000001df
lbl_0807b360:
    ldr r4, lbl_0807b3b0 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    movs r3, #0xe2
    lsls r3, r3, #1
    adds r0, r0, r3
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r4, #0xea
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #0
    bl UpdateMenuOamDataID
lbl_0807b37e:
    ldr r2, lbl_0807b3b0 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldr r5, lbl_0807b3b4 @ =0x000001cf
    adds r3, r0, r5
    ldrb r0, [r3]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r3]
    ldr r0, [r2]
    ldr r4, lbl_0807b3b8 @ =0x000001df
    adds r3, r0, r4
    ldrb r0, [r3]
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r2]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    movs r3, #0
    strb r0, [r1]
    ldr r0, [r2]
    adds r0, #0x42
    strh r3, [r0]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b3b0: .4byte sNonGameplayRamPointer
lbl_0807b3b4: .4byte 0x000001cf
lbl_0807b3b8: .4byte 0x000001df
lbl_0807b3bc:
    movs r0, #1
    movs r1, #0x1f
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807b3ca
    b lbl_0807b70c
lbl_0807b3ca:
    movs r0, #1
    movs r1, #0x20
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807b3d8
    b lbl_0807b70c
lbl_0807b3d8:
    bl sub_0807b854
    ldr r0, lbl_0807b3e4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x40
    b lbl_0807b6e6
    .align 2, 0
lbl_0807b3e4: .4byte sNonGameplayRamPointer
lbl_0807b3e8:
    ldr r0, [r4]
    adds r0, #0x64
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b402
    movs r0, #0
    bl load_time_attack_password_for_record
    movs r0, #1
    bl load_time_attack_password_for_record
lbl_0807b402:
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #4
    strb r1, [r0]
    b lbl_0807b70c
lbl_0807b40c:
    ldr r1, [r4]
    adds r1, #0x40
    b lbl_0807b6e6
lbl_0807b412:
    ldr r0, [r4]
    adds r0, #0x64
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b42c
    movs r0, #2
    bl load_time_attack_password_for_record
    movs r0, #3
    bl load_time_attack_password_for_record
lbl_0807b42c:
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #6
    strb r1, [r0]
    b lbl_0807b70c
lbl_0807b436:
    ldr r1, [r4]
    adds r1, #0x40
    b lbl_0807b6e6
lbl_0807b43c:
    bl sub_0807b71c
    ldr r4, lbl_0807b470 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r0, r5
    movs r1, #0x14
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r1, #0xf2
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0x10
    bl UpdateMenuOamDataID
    ldr r0, lbl_0807b474 @ =0x000001fd
    bl SoundPlay
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #7
    strb r1, [r0]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b470: .4byte sNonGameplayRamPointer
lbl_0807b474: .4byte 0x000001fd
lbl_0807b478:
    movs r5, #0
    ldr r2, [r4]
    ldr r3, lbl_0807b4cc @ =0x000001ef
    adds r0, r2, r3
    ldrb r1, [r0]
    movs r4, #0x10
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b502
    ldr r1, lbl_0807b4d0 @ =0x000001ff
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b502
    adds r0, r2, #0
    adds r0, #0x65
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807b4dc
    movs r0, #1
    movs r1, #0x1e
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807b502
    ldr r0, lbl_0807b4d4 @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0x9c
    lsls r2, r2, #7
    adds r1, r1, r2
    ldr r2, lbl_0807b4d8 @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #2
    str r4, [sp]
    movs r0, #3
    bl DmaTransfer
    b lbl_0807b508
    .align 2, 0
lbl_0807b4cc: .4byte 0x000001ef
lbl_0807b4d0: .4byte 0x000001ff
lbl_0807b4d4: .4byte sEwramPointer
lbl_0807b4d8: .4byte 0x0600e800
lbl_0807b4dc:
    movs r0, #1
    movs r1, #0x1d
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807b502
    movs r5, #1
    ldr r0, lbl_0807b534 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x96
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0807b538 @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #2
    str r4, [sp]
    movs r0, #3
    bl DmaTransfer
lbl_0807b502:
    cmp r5, #0
    bne lbl_0807b508
    b lbl_0807b70c
lbl_0807b508:
    ldr r1, lbl_0807b53c @ =sNonGameplayRamPointer
    ldr r3, [r1]
    adds r0, r3, #0
    adds r0, #0x65
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_0807b548
    ldr r5, lbl_0807b540 @ =0x000001cf
    adds r2, r3, r5
    ldrb r1, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r4]
    ldr r1, lbl_0807b544 @ =0x000001df
    adds r2, r0, r1
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    b lbl_0807b562
    .align 2, 0
lbl_0807b534: .4byte sEwramPointer
lbl_0807b538: .4byte 0x0600e800
lbl_0807b53c: .4byte sNonGameplayRamPointer
lbl_0807b540: .4byte 0x000001cf
lbl_0807b544: .4byte 0x000001df
lbl_0807b548:
    ldr r5, lbl_0807b58c @ =0x000001cf
    adds r2, r3, r5
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r4]
    ldr r1, lbl_0807b590 @ =0x000001df
    adds r2, r0, r1
    ldrb r1, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r1
lbl_0807b562:
    strb r0, [r2]
    ldr r0, [r4]
    adds r0, #0x65
    ldrb r0, [r0]
    bl load_time_attack_time_for_record
    ldr r1, [r4]
    ldrh r2, [r1]
    movs r3, #0xc0
    lsls r3, r3, #2
    adds r0, r3, #0
    movs r3, #0
    orrs r0, r2
    strh r0, [r1]
    adds r0, r1, #0
    adds r0, #0x42
    strh r3, [r0]
    adds r1, #0x40
    movs r0, #8
    strb r0, [r1]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b58c: .4byte 0x000001cf
lbl_0807b590: .4byte 0x000001df
lbl_0807b594:
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x42
    ldrh r0, [r2]
    cmp r0, #0xa
    bls lbl_0807b5ac
    movs r0, #0
    strh r0, [r2]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0807b5ac:
    ldr r0, lbl_0807b5bc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0807b5ba
    b lbl_0807b70c
lbl_0807b5ba:
    b lbl_0807b5d2
    .align 2, 0
lbl_0807b5bc: .4byte gChangedInput
lbl_0807b5c0:
    ldr r0, lbl_0807b5dc @ =gChangedInput
    ldrh r3, [r0]
    cmp r3, #0
    bne lbl_0807b5ca
    b lbl_0807b70c
lbl_0807b5ca:
    movs r0, #2
    ands r0, r3
    cmp r0, #0
    beq lbl_0807b5e0
lbl_0807b5d2:
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0xa
    strb r1, [r0]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b5dc: .4byte gChangedInput
lbl_0807b5e0:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x64
    ldrb r0, [r0]
    cmp r0, #3
    beq lbl_0807b5ee
    b lbl_0807b70c
lbl_0807b5ee:
    movs r0, #0x30
    ands r0, r3
    cmp r0, #0
    bne lbl_0807b5f8
    b lbl_0807b70c
lbl_0807b5f8:
    movs r5, #0
    adds r1, #0x65
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807b60e
    movs r0, #0x20
    ands r0, r3
    cmp r0, #0
    beq lbl_0807b61c
    strb r5, [r1]
    b lbl_0807b620
lbl_0807b60e:
    movs r0, #0x10
    ands r0, r3
    cmp r0, #0
    beq lbl_0807b61c
    movs r0, #1
    strb r0, [r1]
    movs r5, #1
lbl_0807b61c:
    cmp r5, #0
    beq lbl_0807b70c
lbl_0807b620:
    bl sub_0807b71c
    ldr r4, lbl_0807b658 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r5, lbl_0807b65c @ =0x000001cf
    adds r2, r0, r5
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r4]
    ldr r3, lbl_0807b660 @ =0x000001df
    adds r2, r0, r3
    ldrb r0, [r2]
    orrs r0, r1
    strb r0, [r2]
    ldr r0, lbl_0807b664 @ =0x00000211
    bl SoundPlay
    ldr r1, [r4]
    ldrh r2, [r1]
    ldr r0, lbl_0807b668 @ =0x0000fcff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0x40
    movs r0, #7
    strb r0, [r1]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b658: .4byte sNonGameplayRamPointer
lbl_0807b65c: .4byte 0x000001cf
lbl_0807b660: .4byte 0x000001df
lbl_0807b664: .4byte 0x00000211
lbl_0807b668: .4byte 0x0000fcff
lbl_0807b66c:
    movs r4, #0xff
    lsls r4, r4, #1
    adds r0, r4, #0
    bl SoundPlay
    ldr r2, lbl_0807b6b8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    ldr r5, lbl_0807b6bc @ =0x000001cf
    adds r3, r0, r5
    ldrb r0, [r3]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r3]
    ldr r0, [r2]
    adds r5, #0x10
    adds r3, r0, r5
    ldrb r0, [r3]
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r2]
    adds r1, r1, r4
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r2]
    movs r3, #0xf7
    lsls r3, r3, #1
    adds r1, r0, r3
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r2]
    ldrh r2, [r1]
    ldr r0, lbl_0807b6c0 @ =0x0000fcff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0x40
    b lbl_0807b6e6
    .align 2, 0
lbl_0807b6b8: .4byte sNonGameplayRamPointer
lbl_0807b6bc: .4byte 0x000001cf
lbl_0807b6c0: .4byte 0x0000fcff
lbl_0807b6c4:
    ldr r2, [r4]
    ldr r4, lbl_0807b6f0 @ =0x000001ff
    adds r0, r2, r4
    ldrb r0, [r0]
    ldr r5, lbl_0807b6f4 @ =0x000001ef
    adds r1, r2, r5
    ldrb r1, [r1]
    orrs r0, r1
    lsrs r0, r0, #6
    cmp r0, #0
    bne lbl_0807b70c
    adds r1, r2, #0
    adds r1, #0x42
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    subs r1, #2
lbl_0807b6e6:
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807b70c
    .align 2, 0
lbl_0807b6f0: .4byte 0x000001ff
lbl_0807b6f4: .4byte 0x000001ef
lbl_0807b6f8:
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    movs r2, #0
    movs r1, #0
    strh r1, [r3]
    adds r0, #0x40
    strb r2, [r0]
    movs r0, #1
    b lbl_0807b70e
lbl_0807b70c:
    movs r0, #0
lbl_0807b70e:
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_0807b71c
sub_0807b71c: @ 0x0807b71c
    push {lr}
    ldr r0, lbl_0807b734 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x65
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807b738
    movs r0, #0
    movs r1, #0x1e
    bl sub_080790cc
    b lbl_0807b740
    .align 2, 0
lbl_0807b734: .4byte sNonGameplayRamPointer
lbl_0807b738:
    movs r0, #0
    movs r1, #0x1d
    bl sub_080790cc
lbl_0807b740:
    pop {r0}
    bx r0

    thumb_func_start load_time_attack_time_for_record
load_time_attack_time_for_record: @ 0x0807b744
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r1, lbl_0807b84c @ =0x0600e108
    mov ip, r1
    movs r3, #0xa0
    lsls r3, r3, #7
    ldr r1, lbl_0807b850 @ =sNonGameplayRamPointer
    ldr r7, [r1]
    lsls r6, r0, #1
    adds r6, r6, r0
    lsls r6, r6, #1
    adds r1, r7, #0
    adds r1, #0x50
    adds r1, r1, r6
    movs r2, #0xe6
    lsls r2, r2, #1
    adds r5, r2, #0
    ldrb r2, [r1]
    adds r0, r5, r2
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    adds r2, #0x40
    movs r0, #0xf6
    lsls r0, r0, #1
    adds r4, r0, #0
    ldrb r1, [r1]
    adds r0, r4, r1
    orrs r0, r3
    strh r0, [r2]
    adds r1, r7, #0
    adds r1, #0x51
    adds r1, r1, r6
    ldrb r2, [r1]
    adds r0, r5, r2
    orrs r0, r3
    mov r2, ip
    strh r0, [r2, #2]
    adds r2, #0x42
    ldrb r1, [r1]
    adds r0, r4, r1
    orrs r0, r3
    strh r0, [r2]
    movs r1, #0xe5
    lsls r1, r1, #1
    adds r0, r1, #0
    mov sb, r3
    mov r2, sb
    orrs r2, r0
    mov sb, r2
    mov r0, ip
    strh r2, [r0, #4]
    mov r1, ip
    adds r1, #0x44
    movs r2, #0xf5
    lsls r2, r2, #1
    adds r0, r2, #0
    mov r8, r3
    mov r2, r8
    orrs r2, r0
    mov r8, r2
    strh r2, [r1]
    adds r1, r7, #0
    adds r1, #0x52
    adds r1, r1, r6
    ldrb r2, [r1]
    adds r0, r5, r2
    orrs r0, r3
    mov r2, ip
    strh r0, [r2, #6]
    adds r2, #0x46
    ldrb r1, [r1]
    adds r0, r4, r1
    orrs r0, r3
    strh r0, [r2]
    adds r1, r7, #0
    adds r1, #0x53
    adds r1, r1, r6
    ldrb r2, [r1]
    adds r0, r5, r2
    orrs r0, r3
    mov r2, ip
    strh r0, [r2, #8]
    adds r2, #0x48
    ldrb r1, [r1]
    adds r0, r4, r1
    orrs r0, r3
    strh r0, [r2]
    mov r1, sb
    mov r0, ip
    strh r1, [r0, #0xa]
    adds r0, #0x4a
    mov r2, r8
    strh r2, [r0]
    adds r1, r7, #0
    adds r1, #0x54
    adds r1, r1, r6
    ldrb r2, [r1]
    adds r0, r5, r2
    orrs r0, r3
    mov r2, ip
    strh r0, [r2, #0xc]
    adds r2, #0x4c
    ldrb r1, [r1]
    adds r0, r4, r1
    orrs r0, r3
    strh r0, [r2]
    adds r0, r7, #0
    adds r0, #0x55
    adds r0, r0, r6
    ldrb r1, [r0]
    adds r5, r5, r1
    orrs r5, r3
    mov r2, ip
    strh r5, [r2, #0xe]
    mov r1, ip
    adds r1, #0x4e
    ldrb r0, [r0]
    adds r4, r4, r0
    orrs r4, r3
    strh r4, [r1]
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807b84c: .4byte 0x0600e108
lbl_0807b850: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0807b854
sub_0807b854: @ 0x0807b854
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0807b910 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x48
    mov sb, r0
    ldr r0, lbl_0807b914 @ =gFileScreenOptionsUnlocked
    ldr r0, [r0, #8]
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0807b878
    ldr r0, lbl_0807b918 @ =0x08760c44
    mov sb, r0
lbl_0807b878:
    movs r5, #0
    movs r1, #0x10
    mov sl, r1
    ldr r6, lbl_0807b91c @ =0x06006100
    ldr r0, lbl_0807b920 @ =0x06006500
    mov r8, r0
    adds r7, r6, #0
lbl_0807b886:
    mov r1, sb
    adds r0, r1, r5
    ldrb r1, [r0]
    cmp r1, #0x31
    bne lbl_0807b892
    movs r1, #0x3e
lbl_0807b892:
    lsrs r4, r1, #5
    lsls r4, r4, #0xb
    movs r0, #0x1f
    ands r1, r0
    lsls r0, r1, #5
    adds r4, r4, r0
    ldr r0, lbl_0807b924 @ =0x08415460
    adds r1, r4, r0
    mov r0, sl
    str r0, [sp]
    movs r0, #3
    adds r2, r7, #0
    movs r3, #0x20
    bl DmaTransfer
    ldr r1, lbl_0807b928 @ =0x08415860
    adds r4, r4, r1
    mov r0, sl
    str r0, [sp]
    movs r0, #3
    adds r1, r4, #0
    mov r2, r8
    movs r3, #0x20
    bl DmaTransfer
    movs r1, #0x20
    add r8, r1
    adds r7, #0x20
    adds r5, #1
    cmp r5, #7
    ble lbl_0807b886
    movs r2, #0x80
    lsls r2, r2, #5
    adds r2, r6, r2
    movs r5, #0x80
    lsls r5, r5, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DmaTransfer
    movs r1, #0x80
    lsls r1, r1, #3
    adds r1, r6, r1
    movs r2, #0xa0
    lsls r2, r2, #5
    adds r2, r6, r2
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DmaTransfer
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807b910: .4byte sNonGameplayRamPointer
lbl_0807b914: .4byte gFileScreenOptionsUnlocked
lbl_0807b918: .4byte 0x08760c44
lbl_0807b91c: .4byte 0x06006100
lbl_0807b920: .4byte 0x06006500
lbl_0807b924: .4byte 0x08415460
lbl_0807b928: .4byte 0x08415860

    thumb_func_start load_time_attack_password_for_record
load_time_attack_password_for_record: @ 0x0807b92c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #1
    bls lbl_0807b950
    ldr r7, lbl_0807b948 @ =0x000078c0
    ldr r0, lbl_0807b94c @ =gTimeAttackRecord+0x18
    b lbl_0807b954
    .align 2, 0
lbl_0807b948: .4byte 0x000078c0
lbl_0807b94c: .4byte gTimeAttackRecord+0x18
lbl_0807b950:
    ldr r7, lbl_0807b9d8 @ =0x000068c0
    ldr r0, lbl_0807b9dc @ =gTimeAttackRecord
lbl_0807b954:
    mov sb, r0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807b968
    movs r1, #0xa
    add sb, r1
    movs r0, #0x80
    lsls r0, r0, #2
    adds r7, r7, r0
lbl_0807b968:
    movs r1, #0xc0
    lsls r1, r1, #0x13
    adds r0, r7, r1
    movs r7, #0
    ldr r1, lbl_0807b9e0 @ =0x08415460
    mov sl, r1
    movs r1, #0x10
    mov r8, r1
    movs r1, #0x80
    lsls r1, r1, #3
    adds r6, r0, r1
    adds r5, r0, #0
lbl_0807b980:
    mov r1, sb
    adds r0, r1, r7
    ldrb r1, [r0]
    cmp r1, #0x31
    bne lbl_0807b98c
    movs r1, #0x3e
lbl_0807b98c:
    lsrs r4, r1, #5
    lsls r4, r4, #0xb
    movs r0, #0x1f
    ands r1, r0
    lsls r0, r1, #5
    adds r4, r4, r0
    mov r0, sl
    adds r1, r4, r0
    mov r0, r8
    str r0, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x20
    bl DmaTransfer
    ldr r1, lbl_0807b9e4 @ =0x08415860
    adds r4, r4, r1
    mov r0, r8
    str r0, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r2, r6, #0
    movs r3, #0x20
    bl DmaTransfer
    adds r6, #0x20
    adds r5, #0x20
    adds r7, #1
    cmp r7, #9
    ble lbl_0807b980
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807b9d8: .4byte 0x000068c0
lbl_0807b9dc: .4byte gTimeAttackRecord
lbl_0807b9e0: .4byte 0x08415460
lbl_0807b9e4: .4byte 0x08415860

    thumb_func_start OptionsMetroidFusionLinkSubroutine
OptionsMetroidFusionLinkSubroutine: @ 0x0807b9e8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0807ba10 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x42
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r1, lbl_0807ba14 @ =gIoTransferInfo
    ldrb r0, [r1, #8]
    cmp r0, #1
    bne lbl_0807ba18
    bl sub_08088ea0
    b lbl_0807ba26
    .align 2, 0
lbl_0807ba10: .4byte sNonGameplayRamPointer
lbl_0807ba14: .4byte gIoTransferInfo
lbl_0807ba18:
    cmp r0, #2
    bne lbl_0807ba22
    bl sub_08089e30
    b lbl_0807ba26
lbl_0807ba22:
    movs r0, #0
    strb r0, [r1, #0xb]
lbl_0807ba26:
    ldr r1, lbl_0807ba40 @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x40
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #0x17
    bls lbl_0807ba36
    b lbl_0807c110
lbl_0807ba36:
    lsls r0, r0, #2
    ldr r1, lbl_0807ba44 @ =lbl_0807ba48
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807ba40: .4byte sNonGameplayRamPointer
lbl_0807ba44: .4byte lbl_0807ba48
lbl_0807ba48: @ jump table
    .4byte lbl_0807baa8 @ case 0
    .4byte lbl_0807bbfc @ case 1
    .4byte lbl_0807bc38 @ case 2
    .4byte lbl_0807bd24 @ case 3
    .4byte lbl_0807bd8e @ case 4
    .4byte lbl_0807bdd8 @ case 5
    .4byte lbl_0807be40 @ case 6
    .4byte lbl_0807be50 @ case 7
    .4byte lbl_0807be70 @ case 8
    .4byte lbl_0807bea8 @ case 9
    .4byte lbl_0807bedc @ case 10
    .4byte lbl_0807beec @ case 11
    .4byte lbl_0807bf1c @ case 12
    .4byte lbl_0807bf3e @ case 13
    .4byte lbl_0807bf7c @ case 14
    .4byte lbl_0807bfb8 @ case 15
    .4byte lbl_0807bfdc @ case 16
    .4byte lbl_0807c00c @ case 17
    .4byte lbl_0807c01c @ case 18
    .4byte lbl_0807c054 @ case 19
    .4byte lbl_0807c078 @ case 20
    .4byte lbl_0807c094 @ case 21
    .4byte lbl_0807c0d8 @ case 22
    .4byte lbl_0807c0fc @ case 23
lbl_0807baa8:
    ldr r0, lbl_0807babc @ =gFileScreenOptionsUnlocked
    ldrh r0, [r0, #2]
    cmp r0, #0
    beq lbl_0807bac4
    ldr r0, lbl_0807bac0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #1
    b lbl_0807bbce
    .align 2, 0
lbl_0807babc: .4byte gFileScreenOptionsUnlocked
lbl_0807bac0: .4byte sNonGameplayRamPointer
lbl_0807bac4:
    ldr r5, lbl_0807bbdc @ =sNonGameplayRamPointer
    ldr r1, [r5]
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r4, #0x10
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    movs r2, #1
    mov r8, r2
    mov r3, r8
    orrs r0, r3
    strb r0, [r1]
    ldr r1, [r5]
    ldr r0, lbl_0807bbe0 @ =0x000001ff
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r3, #4
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r2
    movs r2, #2
    mov sb, r2
    mov r2, sb
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    movs r2, #0xfb
    lsls r2, r2, #1
    adds r0, r1, r2
    movs r6, #0xa0
    lsls r6, r6, #1
    strh r6, [r0]
    movs r0, #0xfa
    lsls r0, r0, #1
    mov sl, r0
    adds r2, r1, r0
    movs r0, #0xc0
    strh r0, [r2]
    movs r2, #0xe0
    lsls r2, r2, #1
    adds r1, r1, r2
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    mov r2, r8
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r5]
    ldr r1, lbl_0807bbe4 @ =0x000001bf
    adds r2, r0, r1
    ldrb r1, [r2]
    adds r0, r3, #0
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r5]
    movs r1, #0xdb
    lsls r1, r1, #1
    adds r0, r2, r1
    strh r6, [r0]
    movs r0, #0xda
    lsls r0, r0, #1
    adds r1, r2, r0
    movs r0, #0xe0
    strh r0, [r1]
    movs r0, #0xf8
    lsls r0, r0, #1
    adds r1, r2, r0
    ldrb r0, [r1]
    ands r4, r0
    strb r4, [r1]
    ldr r0, [r5]
    ldr r2, lbl_0807bbe8 @ =0x000001ef
    adds r1, r0, r2
    ldrb r0, [r1]
    ands r3, r0
    mov r4, sb
    orrs r3, r4
    strb r3, [r1]
    ldr r1, [r5]
    movs r0, #0xf3
    lsls r0, r0, #1
    adds r2, r1, r0
    subs r0, #0xe6
    strh r0, [r2]
    movs r4, #0xf2
    lsls r4, r4, #1
    adds r1, r1, r4
    movs r0, #0x80
    strh r0, [r1]
    movs r0, #0
    movs r1, #0x19
    bl sub_080790cc
    movs r0, #0
    movs r1, #0x15
    bl sub_080790cc
    ldr r0, [r5]
    add r0, sl
    movs r1, #0x14
    bl UpdateMenuOamDataID
    ldr r0, [r5]
    adds r0, r0, r4
    movs r1, #0x10
    bl UpdateMenuOamDataID
    ldr r1, lbl_0807bbec @ =gBG1HOFS_NonGameplay
    movs r2, #0xdb
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807bbf0 @ =gBG1VOFS_NonGameplay
    movs r3, #0xdf
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_0807bbf4 @ =gBG0HOFS_NonGameplay
    movs r4, #0xcc
    lsls r4, r4, #3
    adds r0, r4, #0
    strh r0, [r1]
    ldr r1, lbl_0807bbf8 @ =gBG0VOFS_NonGameplay
    movs r2, #0xfc
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, [r5]
    adds r0, #0x40
    movs r1, #2
lbl_0807bbce:
    strb r1, [r0]
    ldr r0, lbl_0807bbdc @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x42
    movs r1, #0
    strh r1, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807bbdc: .4byte sNonGameplayRamPointer
lbl_0807bbe0: .4byte 0x000001ff
lbl_0807bbe4: .4byte 0x000001bf
lbl_0807bbe8: .4byte 0x000001ef
lbl_0807bbec: .4byte gBG1HOFS_NonGameplay
lbl_0807bbf0: .4byte gBG1VOFS_NonGameplay
lbl_0807bbf4: .4byte gBG0HOFS_NonGameplay
lbl_0807bbf8: .4byte gBG0VOFS_NonGameplay
lbl_0807bbfc:
    ldr r0, lbl_0807bc34 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    beq lbl_0807bc0e
    b lbl_0807c0fc
lbl_0807bc0e:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bc22
    ldr r0, [r4]
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0xa
    bhi lbl_0807bc22
    b lbl_0807c110
lbl_0807bc22:
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    movs r1, #0
    strh r2, [r3]
    adds r0, #0x40
    strb r1, [r0]
    movs r0, #2
    b lbl_0807c112
    .align 2, 0
lbl_0807bc34: .4byte gChangedInput
lbl_0807bc38:
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r5, #0xc0
    lsls r5, r5, #2
    adds r0, r5, #0
    ands r0, r1
    cmp r0, r5
    bne lbl_0807bc58
    ldr r1, lbl_0807bc54 @ =gIoTransferInfo
    movs r0, #1
    strb r0, [r1, #8]
    adds r1, r2, #0
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bc54: .4byte gIoTransferInfo
lbl_0807bc58:
    movs r7, #0x80
    lsls r7, r7, #2
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bcb0
    ldr r3, lbl_0807bd0c @ =0x000001ff
    adds r0, r2, r3
    ldrb r1, [r0]
    movs r6, #0x10
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807bcb0
    movs r0, #1
    movs r1, #0x15
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807bcb0
    ldr r0, lbl_0807bd10 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xf0
    lsls r0, r0, #6
    adds r1, r1, r0
    ldr r2, lbl_0807bd14 @ =0x0600e800
    str r6, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DmaTransfer
    ldr r0, [r4]
    ldrh r1, [r0, #0x1c]
    strh r1, [r0, #6]
    ldrh r2, [r0]
    adds r1, r7, #0
    orrs r1, r2
    strh r1, [r0]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0xc
    bl UpdateMenuOamDataID
lbl_0807bcb0:
    ldr r5, lbl_0807bd18 @ =sNonGameplayRamPointer
    ldr r2, [r5]
    ldrh r1, [r2]
    movs r6, #0x80
    lsls r6, r6, #1
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807bcc4
    b lbl_0807c110
lbl_0807bcc4:
    ldr r3, lbl_0807bd1c @ =0x000001ef
    adds r0, r2, r3
    ldrb r1, [r0]
    movs r4, #0x10
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bcd6
    b lbl_0807c110
lbl_0807bcd6:
    movs r0, #1
    movs r1, #0x19
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807bce4
    b lbl_0807c110
lbl_0807bce4:
    ldr r0, lbl_0807bd10 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0x90
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0807bd20 @ =0x0600e000
    movs r3, #0xc0
    lsls r3, r3, #2
    str r4, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, [r5]
    ldrh r0, [r1, #0x1e]
    strh r0, [r1, #4]
    ldrh r2, [r1]
    adds r0, r6, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0807c110
    .align 2, 0
lbl_0807bd0c: .4byte 0x000001ff
lbl_0807bd10: .4byte sEwramPointer
lbl_0807bd14: .4byte 0x0600e800
lbl_0807bd18: .4byte sNonGameplayRamPointer
lbl_0807bd1c: .4byte 0x000001ef
lbl_0807bd20: .4byte 0x0600e000
lbl_0807bd24:
    ldr r0, lbl_0807bd3c @ =gIoTransferInfo
    ldrb r0, [r0, #0xb]
    subs r0, #1
    cmp r0, #4
    bls lbl_0807bd30
    b lbl_0807c110
lbl_0807bd30:
    lsls r0, r0, #2
    ldr r1, lbl_0807bd40 @ =lbl_0807bd44
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807bd3c: .4byte gIoTransferInfo
lbl_0807bd40: .4byte lbl_0807bd44
lbl_0807bd44: @ jump table
    .4byte lbl_0807bd58 @ case 0
    .4byte lbl_0807c084 @ case 1
    .4byte lbl_0807bd84 @ case 2
    .4byte lbl_0807bd70 @ case 3
    .4byte lbl_0807bd7a @ case 4
lbl_0807bd58:
    bl SramWrite_FileScreenOptionsUnlocked
    ldr r2, lbl_0807bd6c @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x40
    movs r3, #0
    movs r1, #8
    strb r1, [r0]
    ldr r0, [r2]
    b lbl_0807be32
    .align 2, 0
lbl_0807bd6c: .4byte sNonGameplayRamPointer
lbl_0807bd70:
    ldr r0, [r4]
    adds r0, #0x40
    movs r2, #0
    movs r1, #4
    b lbl_0807bf34
lbl_0807bd7a:
    ldr r0, [r4]
    adds r0, #0x40
    movs r2, #0
    movs r1, #0xe
    b lbl_0807bf34
lbl_0807bd84:
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0x12
    strb r1, [r0]
    b lbl_0807c110
lbl_0807bd8e:
    ldr r2, [r4]
    ldrh r1, [r2]
    ldr r0, lbl_0807bdd4 @ =0x0000fcff
    ands r0, r1
    strh r0, [r2]
    movs r0, #0
    movs r1, #0x17
    bl sub_080790cc
    movs r0, #0
    movs r1, #0x18
    bl sub_080790cc
    ldr r0, [r4]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    movs r2, #0xf7
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807bdd0
    movs r3, #0xf2
    lsls r3, r3, #1
    adds r0, r1, r3
    movs r1, #0x10
    bl UpdateMenuOamDataID
lbl_0807bdd0:
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bdd4: .4byte 0x0000fcff
lbl_0807bdd8:
    ldr r2, [r4]
    ldr r1, lbl_0807be38 @ =0x000001ff
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r3, #0x10
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bdec
    b lbl_0807c110
lbl_0807bdec:
    ldr r1, lbl_0807be3c @ =0x000001ef
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bdfc
    b lbl_0807c110
lbl_0807bdfc:
    movs r0, #1
    movs r1, #0x18
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807be0a
    b lbl_0807c110
lbl_0807be0a:
    movs r0, #1
    movs r1, #0x17
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807be18
    b lbl_0807c110
lbl_0807be18:
    ldr r1, [r4]
    ldrh r2, [r1]
    movs r3, #0xc0
    lsls r3, r3, #2
    adds r0, r3, #0
    movs r3, #0
    orrs r0, r2
    strh r0, [r1]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r4]
lbl_0807be32:
    adds r0, #0x42
    strh r3, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807be38: .4byte 0x000001ff
lbl_0807be3c: .4byte 0x000001ef
lbl_0807be40:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x1e
    bhi lbl_0807be4e
    b lbl_0807c110
lbl_0807be4e:
    b lbl_0807c0f2
lbl_0807be50:
    ldr r0, lbl_0807be68 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    bne lbl_0807be5e
    b lbl_0807c110
lbl_0807be5e:
    ldr r1, lbl_0807be6c @ =gMainGameMode
    movs r0, #0xe
    strh r0, [r1]
    b lbl_0807c110
    .align 2, 0
lbl_0807be68: .4byte gChangedInput
lbl_0807be6c: .4byte gMainGameMode
lbl_0807be70:
    ldr r0, [r4]
    ldrh r2, [r0]
    ldr r1, lbl_0807bea4 @ =0x0000fcff
    ands r1, r2
    strh r1, [r0]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0xf7
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807be98
    adds r0, #1
    strb r0, [r1]
lbl_0807be98:
    movs r0, #0
    movs r1, #0x1a
    bl sub_080790cc
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bea4: .4byte 0x0000fcff
lbl_0807bea8:
    movs r0, #1
    movs r1, #0x1a
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807beb6
    b lbl_0807c110
lbl_0807beb6:
    ldr r3, lbl_0807bed8 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrh r2, [r1]
    movs r4, #0x80
    lsls r4, r4, #2
    adds r0, r4, #0
    movs r4, #0
    orrs r0, r2
    strh r0, [r1]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r3]
    adds r0, #0x42
    strh r4, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807bed8: .4byte sNonGameplayRamPointer
lbl_0807bedc:
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x3c
    bhi lbl_0807beea
    b lbl_0807c110
lbl_0807beea:
    b lbl_0807c0f2
lbl_0807beec:
    ldr r0, lbl_0807bf14 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #9
    ands r0, r1
    cmp r0, #0
    bne lbl_0807befa
    b lbl_0807c110
lbl_0807befa:
    ldr r1, [r4]
    ldrh r2, [r1]
    ldr r0, lbl_0807bf18 @ =0x0000fcff
    ands r0, r2
    strh r0, [r1]
    movs r0, #0xff
    lsls r0, r0, #1
    adds r1, r1, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bf14: .4byte gChangedInput
lbl_0807bf18: .4byte 0x0000fcff
lbl_0807bf1c:
    ldr r1, [r4]
    movs r2, #0xff
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r2, [r0]
    cmp r2, #0
    beq lbl_0807bf2c
    b lbl_0807c110
lbl_0807bf2c:
    adds r0, r1, #0
    adds r0, #0x40
    ldrb r1, [r0]
    adds r1, #1
lbl_0807bf34:
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x42
    strh r2, [r0]
    b lbl_0807c110
lbl_0807bf3e:
    ldr r0, [r4]
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x1e
    bhi lbl_0807bf4a
    b lbl_0807c110
lbl_0807bf4a:
    bl sub_08079fb8
    ldr r0, lbl_0807bf74 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0xa2
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0807bf78 @ =0x0600f000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0x17
    strb r1, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807bf74: .4byte sEwramPointer
lbl_0807bf78: .4byte 0x0600f000
lbl_0807bf7c:
    ldr r0, [r4]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r2, [r4]
    ldrh r1, [r2]
    ldr r0, lbl_0807bfb4 @ =0x0000fcff
    ands r0, r1
    strh r0, [r2]
    movs r0, #0
    movs r1, #0x16
    bl sub_080790cc
    ldr r0, [r4]
    movs r2, #0xf7
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807bfae
    adds r0, #1
    strb r0, [r1]
lbl_0807bfae:
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bfb4: .4byte 0x0000fcff
lbl_0807bfb8:
    movs r0, #1
    movs r1, #0x16
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807bfc6
    b lbl_0807c110
lbl_0807bfc6:
    ldr r0, lbl_0807bfd8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807bfd8: .4byte sNonGameplayRamPointer
lbl_0807bfdc:
    ldr r2, lbl_0807bfec @ =gIoTransferInfo
    ldrb r1, [r2, #0xb]
    cmp r1, #4
    bne lbl_0807bff0
    ldr r0, [r4]
    adds r0, #0x40
    strb r1, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807bfec: .4byte gIoTransferInfo
lbl_0807bff0:
    ldr r0, lbl_0807c008 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #9
    ands r0, r1
    cmp r0, #0
    bne lbl_0807bffe
    b lbl_0807c110
lbl_0807bffe:
    movs r0, #0
    strb r0, [r2, #4]
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807c008: .4byte gChangedInput
lbl_0807c00c:
    ldr r0, lbl_0807c018 @ =gIoTransferInfo
    ldrb r0, [r0, #0xb]
    cmp r0, #4
    beq lbl_0807c016
    b lbl_0807c110
lbl_0807c016:
    b lbl_0807c084
    .align 2, 0
lbl_0807c018: .4byte gIoTransferInfo
lbl_0807c01c:
    ldr r0, [r4]
    ldrh r2, [r0]
    ldr r1, lbl_0807c050 @ =0x0000fcff
    ands r1, r2
    strh r1, [r0]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0xf7
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807c044
    adds r0, #1
    strb r0, [r1]
lbl_0807c044:
    movs r0, #0
    movs r1, #0x1b
    bl sub_080790cc
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807c050: .4byte 0x0000fcff
lbl_0807c054:
    movs r0, #1
    movs r1, #0x1b
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807c110
    ldr r0, lbl_0807c074 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807c074: .4byte sNonGameplayRamPointer
lbl_0807c078:
    ldr r0, lbl_0807c090 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #9
    ands r0, r1
    cmp r0, #0
    beq lbl_0807c110
lbl_0807c084:
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0x15
    strb r1, [r0]
    b lbl_0807c110
    .align 2, 0
lbl_0807c090: .4byte gChangedInput
lbl_0807c094:
    ldr r0, [r4]
    ldrh r2, [r0]
    ldr r1, lbl_0807c0d4 @ =0x0000fcff
    ands r1, r2
    strh r1, [r0]
    movs r1, #0xda
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0xff
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807c0bc
    adds r0, #1
    strb r0, [r1]
lbl_0807c0bc:
    ldr r0, [r4]
    movs r3, #0xf7
    lsls r3, r3, #1
    adds r1, r0, r3
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807c0ce
    adds r0, #1
    strb r0, [r1]
lbl_0807c0ce:
    ldr r1, [r4]
    b lbl_0807c0f2
    .align 2, 0
lbl_0807c0d4: .4byte 0x0000fcff
lbl_0807c0d8:
    ldr r1, [r4]
    movs r4, #0xff
    lsls r4, r4, #1
    adds r0, r1, r4
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807c110
    movs r2, #0xf7
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807c110
lbl_0807c0f2:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807c110
lbl_0807c0fc:
    ldr r0, [r4]
    adds r3, r0, #0
    adds r3, #0x42
    movs r2, #0
    movs r1, #0
    strh r1, [r3]
    adds r0, #0x40
    strb r2, [r0]
    movs r0, #1
    b lbl_0807c112
lbl_0807c110:
    movs r0, #0
lbl_0807c112:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start FileSelectMenuSubroutine
FileSelectMenuSubroutine: @ 0x0807c124
    push {lr}
    ldr r2, lbl_0807c148 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    ldrh r0, [r1, #0x3c]
    adds r0, #1
    strh r0, [r1, #0x3c]
    ldr r0, lbl_0807c14c @ =gGameModeSub1
    movs r3, #0
    ldrsh r1, [r0, r3]
    adds r3, r0, #0
    cmp r1, #0xb
    bls lbl_0807c13e
    b lbl_0807c2f6
lbl_0807c13e:
    lsls r0, r1, #2
    ldr r1, lbl_0807c150 @ =lbl_0807c154
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807c148: .4byte sNonGameplayRamPointer
lbl_0807c14c: .4byte gGameModeSub1
lbl_0807c150: .4byte lbl_0807c154
lbl_0807c154: @ jump table
    .4byte lbl_0807c184 @ case 0
    .4byte lbl_0807c1a8 @ case 1
    .4byte lbl_0807c1cc @ case 2
    .4byte lbl_0807c2a4 @ case 3
    .4byte lbl_0807c2b4 @ case 4
    .4byte lbl_0807c2dc @ case 5
    .4byte lbl_0807c2ec @ case 6
    .4byte lbl_0807c2b4 @ case 7
    .4byte lbl_0807c2ec @ case 8
    .4byte lbl_0807c1a8 @ case 9
    .4byte lbl_0807c24c @ case 10
    .4byte lbl_0807c2a4 @ case 11
lbl_0807c184:
    ldr r0, lbl_0807c19c @ =gGameModeSub2
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_0807c1a0 @ =gCutsceneToSkip
    strb r1, [r0]
    bl file_select_menu_init
    ldr r1, lbl_0807c1a4 @ =gGameModeSub1
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
    b lbl_0807c2f6
    .align 2, 0
lbl_0807c19c: .4byte gGameModeSub2
lbl_0807c1a0: .4byte gCutsceneToSkip
lbl_0807c1a4: .4byte gGameModeSub1
lbl_0807c1a8:
    bl sub_0807c568
    bl file_select_fading
    cmp r0, #0
    bne lbl_0807c1b6
    b lbl_0807c2f6
lbl_0807c1b6:
    ldr r1, lbl_0807c1c4 @ =gGameModeSub1
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r1, lbl_0807c1c8 @ =gGameModeSub2
    b lbl_0807c23c
    .align 2, 0
lbl_0807c1c4: .4byte gGameModeSub1
lbl_0807c1c8: .4byte gGameModeSub2
lbl_0807c1cc:
    bl sub_0807d27c
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0807c1d8
    b lbl_0807c2f6
lbl_0807c1d8:
    ldr r0, lbl_0807c1f4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0x3c]
    ldr r0, lbl_0807c1f8 @ =gGameModeSub2
    movs r2, #0
    ldrsb r2, [r0, r2]
    adds r3, r0, #0
    cmp r2, #1
    bne lbl_0807c200
    ldr r1, lbl_0807c1fc @ =gGameModeSub1
    movs r0, #7
    b lbl_0807c22a
    .align 2, 0
lbl_0807c1f4: .4byte sNonGameplayRamPointer
lbl_0807c1f8: .4byte gGameModeSub2
lbl_0807c1fc: .4byte gGameModeSub1
lbl_0807c200:
    cmp r2, #2
    bne lbl_0807c210
    ldr r1, lbl_0807c20c @ =gGameModeSub1
    movs r0, #4
    b lbl_0807c22a
    .align 2, 0
lbl_0807c20c: .4byte gGameModeSub1
lbl_0807c210:
    cmp r2, #3
    bne lbl_0807c220
    ldr r0, lbl_0807c21c @ =gGameModeSub1
    strh r2, [r0]
    b lbl_0807c22c
    .align 2, 0
lbl_0807c21c: .4byte gGameModeSub1
lbl_0807c220:
    adds r1, #0x3e
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_0807c244 @ =gGameModeSub1
    movs r0, #0xa
lbl_0807c22a:
    strh r0, [r1]
lbl_0807c22c:
    movs r0, #0
    ldrsb r0, [r3, r0]
    cmp r0, #0
    beq lbl_0807c2f6
    movs r0, #1
    bl sub_0807c4b0
    ldr r1, lbl_0807c248 @ =gOptionsOptionSelected
lbl_0807c23c:
    movs r0, #0
    strb r0, [r1]
    b lbl_0807c2f6
    .align 2, 0
lbl_0807c244: .4byte gGameModeSub1
lbl_0807c248: .4byte gOptionsOptionSelected
lbl_0807c24c:
    bl settings_subroutine
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807c2f6
    ldr r0, lbl_0807c270 @ =gGameModeSub2
    movs r3, #0
    ldrsb r3, [r0, r3]
    cmp r3, #0
    beq lbl_0807c278
    movs r0, #1
    bl sub_0807c4b0
    ldr r1, lbl_0807c274 @ =gGameModeSub1
    movs r0, #0xb
    strh r0, [r1]
    b lbl_0807c2f6
    .align 2, 0
lbl_0807c270: .4byte gGameModeSub2
lbl_0807c274: .4byte gGameModeSub1
lbl_0807c278:
    ldr r1, lbl_0807c29c @ =gGameModeSub1
    movs r0, #2
    strh r0, [r1]
    ldr r2, lbl_0807c2a0 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x3e
    movs r1, #6
    strb r1, [r0]
    ldr r0, [r2]
    movs r1, #0
    strh r3, [r0, #0x3c]
    adds r0, #0x40
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x42
    strh r3, [r0]
    b lbl_0807c2f6
    .align 2, 0
lbl_0807c29c: .4byte gGameModeSub1
lbl_0807c2a0: .4byte sNonGameplayRamPointer
lbl_0807c2a4:
    bl sub_0807c568
    bl file_select_fading
    cmp r0, #0
    beq lbl_0807c2f6
    movs r0, #1
    b lbl_0807c2fc
lbl_0807c2b4:
    bl sub_0807c568
    bl file_select_fading
    cmp r0, #0
    beq lbl_0807c2f6
    ldr r0, lbl_0807c2d4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0x3c]
    ldr r1, lbl_0807c2d8 @ =gGameModeSub1
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    b lbl_0807c2f6
    .align 2, 0
lbl_0807c2d4: .4byte sNonGameplayRamPointer
lbl_0807c2d8: .4byte gGameModeSub1
lbl_0807c2dc:
    ldr r0, [r2]
    ldrh r0, [r0, #0x3c]
    cmp r0, #0x1e
    bls lbl_0807c2f6
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    b lbl_0807c2f6
lbl_0807c2ec:
    movs r0, #0
    bl unk_75c04
    movs r0, #1
    b lbl_0807c2fc
lbl_0807c2f6:
    bl file_select_menu_process_oam
    movs r0, #0
lbl_0807c2fc:
    pop {r1}
    bx r1

    thumb_func_start file_select_fading
file_select_fading: @ 0x0807c300
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    movs r0, #0
    mov r8, r0
    ldr r7, lbl_0807c32c @ =sNonGameplayRamPointer
    ldr r1, [r7]
    ldrh r0, [r1, #0x10]
    adds r2, r0, #1
    movs r3, #0
    strh r2, [r1, #0x10]
    ldrb r0, [r1, #0xc]
    cmp r0, #1
    bne lbl_0807c320
    b lbl_0807c490
lbl_0807c320:
    cmp r0, #1
    bgt lbl_0807c330
    cmp r0, #0
    beq lbl_0807c33c
    b lbl_0807c4a0
    .align 2, 0
lbl_0807c32c: .4byte sNonGameplayRamPointer
lbl_0807c330:
    cmp r0, #2
    beq lbl_0807c3d8
    cmp r0, #3
    bne lbl_0807c33a
    b lbl_0807c490
lbl_0807c33a:
    b lbl_0807c4a0
lbl_0807c33c:
    ldrb r0, [r1, #0xe]
    cmp r0, #0
    beq lbl_0807c344
    b lbl_0807c4a0
lbl_0807c344:
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    ldrb r2, [r1, #0x13]
    cmp r0, r2
    bhs lbl_0807c350
    b lbl_0807c4a0
lbl_0807c350:
    ldrb r0, [r1, #0xd]
    cmp r0, #0x1f
    bhi lbl_0807c3bc
    ldr r4, lbl_0807c3b4 @ =sEwramPointer
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    str r0, [sp, #8]
    ldrb r1, [r1, #0xd]
    add r6, sp, #8
    ldr r5, lbl_0807c3b8 @ =0x0000ffff
    str r5, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r1, #0xc0
    lsls r1, r1, #3
    adds r0, r0, r1
    str r0, [sp, #8]
    ldr r0, [r7]
    ldrb r1, [r0, #0xd]
    str r5, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r1, [r7]
    movs r0, #1
    strb r0, [r1, #0xe]
    ldr r2, [r7]
    ldrb r0, [r2, #0xd]
    cmp r0, #0x1f
    beq lbl_0807c442
    ldrb r1, [r2, #0xd]
    ldrb r0, [r2, #0x12]
    adds r1, r1, r0
    cmp r1, #0x1f
    bgt lbl_0807c45a
    b lbl_0807c460
    .align 2, 0
lbl_0807c3b4: .4byte sEwramPointer
lbl_0807c3b8: .4byte 0x0000ffff
lbl_0807c3bc:
    ldr r0, lbl_0807c3d4 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r2, r1, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    b lbl_0807c47a
    .align 2, 0
lbl_0807c3d4: .4byte sEwramPointer
lbl_0807c3d8:
    ldrb r0, [r1, #0xe]
    cmp r0, #0
    bne lbl_0807c4a0
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    ldrb r2, [r1, #0x13]
    cmp r0, r2
    blo lbl_0807c4a0
    mov r0, r8
    strh r0, [r1, #0x10]
    ldrb r0, [r1, #0xd]
    cmp r0, #0x1f
    bhi lbl_0807c464
    ldr r4, lbl_0807c448 @ =sEwramPointer
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r0, r2
    str r0, [sp, #8]
    ldrb r1, [r1, #0xd]
    add r6, sp, #8
    ldr r5, lbl_0807c44c @ =0x0000ffff
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r1, #0xc0
    lsls r1, r1, #3
    adds r0, r0, r1
    str r0, [sp, #8]
    ldr r0, [r7]
    ldrb r1, [r0, #0xd]
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r1, [r7]
    movs r0, #1
    strb r0, [r1, #0xe]
    ldr r2, [r7]
    ldrb r0, [r2, #0xd]
    cmp r0, #0x1f
    bne lbl_0807c450
lbl_0807c442:
    adds r0, #1
    strb r0, [r2, #0xd]
    b lbl_0807c4a0
    .align 2, 0
lbl_0807c448: .4byte sEwramPointer
lbl_0807c44c: .4byte 0x0000ffff
lbl_0807c450:
    ldrb r1, [r2, #0xd]
    ldrb r0, [r2, #0x12]
    adds r1, r1, r0
    cmp r1, #0x1f
    ble lbl_0807c460
lbl_0807c45a:
    movs r0, #0x1f
    strb r0, [r2, #0xd]
    b lbl_0807c4a0
lbl_0807c460:
    strb r1, [r2, #0xd]
    b lbl_0807c4a0
lbl_0807c464:
    ldr r0, lbl_0807c48c @ =sEwramPointer
    ldr r2, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r2, r2, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
lbl_0807c47a:
    ldr r1, [r7]
    movs r0, #1
    strb r0, [r1, #0xe]
    ldr r1, [r7]
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    b lbl_0807c4a0
    .align 2, 0
lbl_0807c48c: .4byte sEwramPointer
lbl_0807c490:
    ldrb r0, [r1, #0xe]
    cmp r0, #0
    bne lbl_0807c4a0
    strb r3, [r1, #0xd]
    ldr r0, [r7]
    strb r3, [r0, #0xc]
    movs r2, #1
    mov r8, r2
lbl_0807c4a0:
    mov r0, r8
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0807c4b0
sub_0807c4b0: @ 0x0807c4b0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    ldr r7, lbl_0807c524 @ =sNonGameplayRamPointer
    ldr r1, [r7]
    movs r2, #0
    strb r2, [r1, #0xd]
    ldr r1, [r7]
    strb r2, [r1, #0xe]
    ldr r1, [r7]
    movs r3, #0
    mov sb, r3
    strh r2, [r1, #0x10]
    cmp r0, #0
    bne lbl_0807c52c
    movs r6, #0xa0
    lsls r6, r6, #0x13
    ldr r0, lbl_0807c528 @ =sEwramPointer
    mov r8, r0
    ldr r2, [r0]
    movs r5, #0x80
    lsls r5, r5, #3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DmaTransfer
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl BitFill
    mov r1, r8
    ldr r2, [r1]
    adds r2, r2, r5
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DmaTransfer
    ldr r0, [r7]
    mov r3, sb
    strb r3, [r0, #0xc]
    ldr r1, [r7]
    movs r0, #8
    strb r0, [r1, #0x12]
    ldr r0, [r7]
    strb r3, [r0, #0x13]
    b lbl_0807c554
    .align 2, 0
lbl_0807c524: .4byte sNonGameplayRamPointer
lbl_0807c528: .4byte sEwramPointer
lbl_0807c52c:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_0807c564 @ =sEwramPointer
    ldr r2, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, [r7]
    movs r0, #2
    strb r0, [r1, #0xc]
    ldr r1, [r7]
    movs r0, #8
    strb r0, [r1, #0x12]
    ldr r0, [r7]
    mov r1, sb
    strb r1, [r0, #0x13]
lbl_0807c554:
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807c564: .4byte sEwramPointer

    thumb_func_start sub_0807c568
sub_0807c568: @ 0x0807c568
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0807c59c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_0807c594
    ldr r0, lbl_0807c5a0 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r1, r3
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r1, [r4]
    movs r0, #0
    strb r0, [r1, #0xe]
lbl_0807c594:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807c59c: .4byte sNonGameplayRamPointer
lbl_0807c5a0: .4byte sEwramPointer

    thumb_func_start sub_0807c5a4
sub_0807c5a4: @ 0x0807c5a4
    push {r4, lr}
    movs r1, #0
    ldr r4, lbl_0807c5d8 @ =gLanguage
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r0, #2
    beq lbl_0807c5b8
    movs r0, #2
    strb r0, [r4]
    movs r1, #1
lbl_0807c5b8:
    cmp r1, #0
    beq lbl_0807c5c0
    bl SramWrite_Language
lbl_0807c5c0:
    adds r3, r4, #0
    ldr r2, lbl_0807c5dc @ =gSaveFilesInfo
    movs r1, #2
lbl_0807c5c6:
    ldrb r0, [r3]
    strb r0, [r2, #0x13]
    adds r2, #0x18
    subs r1, #1
    cmp r1, #0
    bge lbl_0807c5c6
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807c5d8: .4byte gLanguage
lbl_0807c5dc: .4byte gSaveFilesInfo

    thumb_func_start file_select_menu_init
file_select_menu_init: @ 0x0807c5e0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r0, lbl_0807c798 @ =sub_0807cb20
    bl CallbackSetVBlank
    ldr r2, lbl_0807c79c @ =gNonGameplayRAM
    movs r3, #0xc5
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r0, #0x80
    lsls r0, r0, #0x13
    ldr r7, lbl_0807c7a0 @ =sNonGameplayRamPointer
    ldr r3, [r7]
    movs r4, #0
    movs r1, #0
    mov r8, r1
    mov r2, r8
    strh r2, [r3]
    strh r2, [r0]
    ldr r2, lbl_0807c7a4 @ =0x04000054
    ldr r1, lbl_0807c7a8 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    ldr r1, lbl_0807c7ac @ =0x04000050
    movs r0, #0xff
    strh r0, [r3, #2]
    strh r0, [r1]
    ldr r0, lbl_0807c7b0 @ =gNextOamSlot
    strb r4, [r0]
    bl ClearGfxRam
    bl ResetFreeOAM
    ldr r1, lbl_0807c7b4 @ =gOamXOffset_NonGameplay
    ldr r0, lbl_0807c7b8 @ =gOamYOffset_NonGameplay
    strb r4, [r0]
    strb r4, [r1]
    ldr r0, lbl_0807c7bc @ =gSramErrorFlag
    strb r4, [r0]
    ldr r0, lbl_0807c7c0 @ =gDebugFlag
    strb r4, [r0]
    ldr r6, lbl_0807c7c4 @ =sEwramPointer
    ldr r2, [r6]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r2, r2, r3
    movs r0, #0x80
    lsls r0, r0, #4
    mov sb, r0
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, sb
    bl BitFill
    bl sub_080756c0
    bl sub_0807c5a4
    ldr r0, [r7]
    ldr r2, lbl_0807c7c8 @ =gMostRecentSaveFile
    ldrb r1, [r2]
    adds r0, #0x24
    strb r1, [r0]
    ldr r0, [r7]
    ldrb r1, [r2]
    adds r0, #0x25
    strb r1, [r0]
    ldr r0, [r7]
    ldrb r1, [r2]
    adds r0, #0x26
    strb r1, [r0]
    ldr r0, [r7]
    ldrb r1, [r2]
    adds r0, #0x27
    strb r1, [r0]
    ldr r0, [r7]
    ldrb r1, [r2]
    adds r0, #0x28
    strb r1, [r0]
    ldr r0, [r7]
    ldrb r1, [r2]
    adds r0, #0x3f
    strb r1, [r0]
    ldr r1, lbl_0807c7cc @ =0x08454818
    movs r4, #0xa0
    lsls r4, r4, #0x13
    str r5, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0xe0
    bl DmaTransfer
    ldr r1, lbl_0807c7d0 @ =0x084548f8
    ldr r2, lbl_0807c7d4 @ =0x050001c0
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DmaTransfer
    ldr r1, lbl_0807c7d8 @ =0x08454938
    ldr r2, lbl_0807c7dc @ =0x05000200
    str r5, [sp]
    movs r0, #3
    movs r3, #0xc0
    bl DmaTransfer
    mov r1, r8
    strh r1, [r4]
    ldr r0, lbl_0807c7e0 @ =0x08458e14
    ldr r4, lbl_0807c7e4 @ =0x06000400
    adds r1, r4, #0
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0807c7e8 @ =0x08455f70
    ldr r1, lbl_0807c7ec @ =0x06008000
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0807c7f0 @ =0x0845c0f4
    ldr r1, lbl_0807c7f4 @ =0x06010000
    bl CallLZ77UncompVRAM
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    mov r3, sb
    bl BitFill
    ldr r1, lbl_0807c7f8 @ =0x08760b24
    ldr r0, lbl_0807c7fc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    subs r0, #2
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0807c800 @ =0x06000c00
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0807c804 @ =0x0845dbdc
    ldr r1, lbl_0807c808 @ =0x0600f800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0807c80c @ =0x0845e19c
    ldr r1, [r6]
    add r1, sb
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0807c810 @ =0x0845e6dc
    ldr r1, [r6]
    movs r2, #0xa0
    lsls r2, r2, #6
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0807c814 @ =0x0845ea80
    ldr r1, [r6]
    movs r3, #0xc0
    lsls r3, r3, #5
    adds r1, r1, r3
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0807c818 @ =0x0845ee24
    ldr r1, [r6]
    movs r2, #0x80
    lsls r2, r2, #6
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    bl sub_08079fb8
    bl copy_time_attack_time
    bl display_save_file_info
    ldr r1, [r6]
    add r1, sb
    ldr r2, lbl_0807c81c @ =0x0600d800
    str r5, [sp]
    movs r0, #3
    mov r3, sb
    bl DmaTransfer
    bl sub_08074c08
    bl sub_08078228
    ldr r3, lbl_0807c820 @ =gGameModeSub1
    movs r0, #2
    strh r0, [r3]
    ldr r1, lbl_0807c824 @ =gSaveFilesInfo
    ldrb r0, [r1, #1]
    cmp r0, #0
    bne lbl_0807c78c
    ldrb r0, [r1, #0x19]
    cmp r0, #0
    bne lbl_0807c78c
    adds r0, r1, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807c828
lbl_0807c78c:
    ldr r0, lbl_0807c7a0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    movs r1, #4
    b lbl_0807c872
    .align 2, 0
lbl_0807c798: .4byte sub_0807cb20
lbl_0807c79c: .4byte gNonGameplayRAM
lbl_0807c7a0: .4byte sNonGameplayRamPointer
lbl_0807c7a4: .4byte 0x04000054
lbl_0807c7a8: .4byte gWrittenToBLDY_NonGameplay
lbl_0807c7ac: .4byte 0x04000050
lbl_0807c7b0: .4byte gNextOamSlot
lbl_0807c7b4: .4byte gOamXOffset_NonGameplay
lbl_0807c7b8: .4byte gOamYOffset_NonGameplay
lbl_0807c7bc: .4byte gSramErrorFlag
lbl_0807c7c0: .4byte gDebugFlag
lbl_0807c7c4: .4byte sEwramPointer
lbl_0807c7c8: .4byte gMostRecentSaveFile
lbl_0807c7cc: .4byte 0x08454818
lbl_0807c7d0: .4byte 0x084548f8
lbl_0807c7d4: .4byte 0x050001c0
lbl_0807c7d8: .4byte 0x08454938
lbl_0807c7dc: .4byte 0x05000200
lbl_0807c7e0: .4byte 0x08458e14
lbl_0807c7e4: .4byte 0x06000400
lbl_0807c7e8: .4byte 0x08455f70
lbl_0807c7ec: .4byte 0x06008000
lbl_0807c7f0: .4byte 0x0845c0f4
lbl_0807c7f4: .4byte 0x06010000
lbl_0807c7f8: .4byte 0x08760b24
lbl_0807c7fc: .4byte gLanguage
lbl_0807c800: .4byte 0x06000c00
lbl_0807c804: .4byte 0x0845dbdc
lbl_0807c808: .4byte 0x0600f800
lbl_0807c80c: .4byte 0x0845e19c
lbl_0807c810: .4byte 0x0845e6dc
lbl_0807c814: .4byte 0x0845ea80
lbl_0807c818: .4byte 0x0845ee24
lbl_0807c81c: .4byte 0x0600d800
lbl_0807c820: .4byte gGameModeSub1
lbl_0807c824: .4byte gSaveFilesInfo
lbl_0807c828:
    ldr r0, [r7]
    ldr r2, lbl_0807c858 @ =gOptionsOptionSelected
    movs r1, #0
    ldrsb r1, [r2, r1]
    adds r0, #0x5c
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807c85c
    ldrb r0, [r2]
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_0807c85c
    lsrs r0, r0, #0x18
    cmp r0, #6
    bhi lbl_0807c85c
    movs r0, #0xa
    strh r0, [r3]
    bl sub_0807b008
    ldr r0, [r7]
    adds r0, #0x3e
    movs r1, #1
    b lbl_0807c872
    .align 2, 0
lbl_0807c858: .4byte gOptionsOptionSelected
lbl_0807c85c:
    movs r0, #9
    movs r1, #2
    bl PlayMusic
    ldr r1, lbl_0807c968 @ =gOptionsOptionSelected
    movs r0, #0
    strb r0, [r1]
    ldr r0, lbl_0807c96c @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    movs r1, #0
lbl_0807c872:
    strb r1, [r0]
    ldr r2, lbl_0807c970 @ =gBG0HOFS_NonGameplay
    ldr r0, lbl_0807c974 @ =gBG0VOFS_NonGameplay
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r3, #0
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0807c978 @ =gBG1HOFS_NonGameplay
    ldr r0, lbl_0807c97c @ =gBG1VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0807c980 @ =gBG2HOFS_NonGameplay
    ldr r0, lbl_0807c984 @ =gBG2VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0807c988 @ =gBG3HOFS_NonGameplay
    ldr r0, lbl_0807c98c @ =gBG3VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r5, lbl_0807c96c @ =sNonGameplayRamPointer
    ldr r2, [r5]
    movs r6, #0
    movs r3, #0
    movs r0, #0xd0
    lsls r0, r0, #5
    strh r0, [r2]
    ldr r0, lbl_0807c990 @ =0x00001f0b
    strh r0, [r2, #0x14]
    ldr r1, lbl_0807c994 @ =0x00001e02
    strh r1, [r2, #0x16]
    ldr r0, lbl_0807c998 @ =0x00001b01
    strh r0, [r2, #0x18]
    adds r0, #1
    strh r0, [r2, #0x1a]
    ldr r0, lbl_0807c99c @ =0x00001d01
    strh r0, [r2, #0x1c]
    movs r0, #0xe0
    lsls r0, r0, #5
    strh r0, [r2, #0x1e]
    strh r1, [r2, #0x20]
    ldr r0, lbl_0807c9a0 @ =0x04000008
    strh r3, [r2, #4]
    strh r3, [r0]
    ldr r4, lbl_0807c9a4 @ =0x0400000a
    ldrh r3, [r2, #0x18]
    strh r3, [r2, #6]
    ldr r1, lbl_0807c9a8 @ =0x0000ffff
    adds r0, r1, #0
    ands r0, r3
    strh r0, [r4]
    adds r4, #2
    ldrh r3, [r2, #0x16]
    strh r3, [r2, #8]
    adds r0, r1, #0
    ands r0, r3
    strh r0, [r4]
    ldr r3, lbl_0807c9ac @ =0x0400000e
    ldrh r0, [r2, #0x14]
    strh r0, [r2, #0xa]
    ands r1, r0
    strh r1, [r3]
    ldr r0, lbl_0807c9b0 @ =0x08760b38
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2, #0x2c]
    str r1, [r2, #0x30]
    adds r2, #0x34
    strb r6, [r2]
    ldr r0, [r5]
    adds r0, #0x35
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x36
    movs r1, #1
    rsbs r1, r1, #0
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x37
    strb r1, [r0]
    bl sub_080782ac
    ldr r0, [r5]
    adds r0, #0x24
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078504
    ldr r0, lbl_0807c9b4 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0807c9b8
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0807c9da
    adds r2, #0xef
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0xfe
    movs r1, #0xd
    strb r1, [r0]
    ldr r0, [r5]
    movs r2, #0x87
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0xe
    strb r0, [r1]
    ldr r0, [r5]
    movs r3, #0x8f
    lsls r3, r3, #1
    adds r1, r0, r3
    movs r0, #0xf
    strb r0, [r1]
    b lbl_0807c9da
    .align 2, 0
lbl_0807c968: .4byte gOptionsOptionSelected
lbl_0807c96c: .4byte sNonGameplayRamPointer
lbl_0807c970: .4byte gBG0HOFS_NonGameplay
lbl_0807c974: .4byte gBG0VOFS_NonGameplay
lbl_0807c978: .4byte gBG1HOFS_NonGameplay
lbl_0807c97c: .4byte gBG1VOFS_NonGameplay
lbl_0807c980: .4byte gBG2HOFS_NonGameplay
lbl_0807c984: .4byte gBG2VOFS_NonGameplay
lbl_0807c988: .4byte gBG3HOFS_NonGameplay
lbl_0807c98c: .4byte gBG3VOFS_NonGameplay
lbl_0807c990: .4byte 0x00001f0b
lbl_0807c994: .4byte 0x00001e02
lbl_0807c998: .4byte 0x00001b01
lbl_0807c99c: .4byte 0x00001d01
lbl_0807c9a0: .4byte 0x04000008
lbl_0807c9a4: .4byte 0x0400000a
lbl_0807c9a8: .4byte 0x0000ffff
lbl_0807c9ac: .4byte 0x0400000e
lbl_0807c9b0: .4byte 0x08760b38
lbl_0807c9b4: .4byte gGameModeSub1
lbl_0807c9b8:
    bl sub_08079ecc
    movs r0, #0
    bl sub_08078b98
    movs r0, #4
    bl sub_08078b98
    ldr r2, [r5]
    ldrh r1, [r2]
    ldr r0, lbl_0807ca14 @ =0x0000fdff
    ands r0, r1
    movs r3, #0xa0
    lsls r3, r3, #5
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
lbl_0807c9da:
    bl file_select_menu_process_oam
    movs r0, #0
    bl sub_0807c4b0
    ldr r2, lbl_0807ca18 @ =0x04000054
    ldr r1, lbl_0807ca1c @ =gWrittenToBLDY_NonGameplay
    movs r0, #0
    strh r0, [r1]
    strh r0, [r2]
    subs r2, #4
    ldr r0, lbl_0807ca20 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #2]
    strh r0, [r2]
    bl sub_0807ca28
    ldr r0, lbl_0807ca24 @ =sub_0807ca28
    bl CallbackSetVBlank
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807ca14: .4byte 0x0000fdff
lbl_0807ca18: .4byte 0x04000054
lbl_0807ca1c: .4byte gWrittenToBLDY_NonGameplay
lbl_0807ca20: .4byte sNonGameplayRamPointer
lbl_0807ca24: .4byte sub_0807ca28

    thumb_func_start sub_0807ca28
sub_0807ca28: @ 0x0807ca28
    push {lr}
    ldr r0, lbl_0807cad8 @ =gIoTransferInfo
    ldrb r0, [r0, #4]
    cmp r0, #0
    beq lbl_0807ca36
    bl sub_0808a730
lbl_0807ca36:
    ldr r1, lbl_0807cadc @ =0x040000d4
    ldr r0, lbl_0807cae0 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0807cae4 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xc4
    ldr r0, lbl_0807cae8 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807caec @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807caf0 @ =gBG1HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807caf4 @ =gBG1VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807caf8 @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807cafc @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807cb00 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0807cb04 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1]
    subs r1, #0x1e
    ldr r0, lbl_0807cb08 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r0, [r2]
    strh r0, [r1]
    adds r1, #0x54
    ldr r0, lbl_0807cb0c @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_0807cb10 @ =0x04000052
    ldr r0, lbl_0807cb14 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0807cb18 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r3]
    ldr r1, lbl_0807cb1c @ =0x04000050
    ldrh r0, [r2, #2]
    strh r0, [r1]
    subs r1, #0x48
    ldrh r0, [r2, #4]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #6]
    strh r0, [r1]
    adds r1, #2
    ldrh r0, [r2, #8]
    strh r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807cad8: .4byte gIoTransferInfo
lbl_0807cadc: .4byte 0x040000d4
lbl_0807cae0: .4byte gOamData
lbl_0807cae4: .4byte 0x84000100
lbl_0807cae8: .4byte gBG0HOFS_NonGameplay
lbl_0807caec: .4byte gBG0VOFS_NonGameplay
lbl_0807caf0: .4byte gBG1HOFS_NonGameplay
lbl_0807caf4: .4byte gBG1VOFS_NonGameplay
lbl_0807caf8: .4byte gBG2HOFS_NonGameplay
lbl_0807cafc: .4byte gBG2VOFS_NonGameplay
lbl_0807cb00: .4byte gBG3HOFS_NonGameplay
lbl_0807cb04: .4byte gBG3VOFS_NonGameplay
lbl_0807cb08: .4byte sNonGameplayRamPointer
lbl_0807cb0c: .4byte gWrittenToBLDY_NonGameplay
lbl_0807cb10: .4byte 0x04000052
lbl_0807cb14: .4byte gWrittenToBLDALPHA_H
lbl_0807cb18: .4byte gWrittenToBLDALPHA_L
lbl_0807cb1c: .4byte 0x04000050

    thumb_func_start sub_0807cb20
sub_0807cb20: @ 0x0807cb20
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr

    thumb_func_start display_save_file_info
display_save_file_info: @ 0x0807cb2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    bl display_save_file_health
    movs r0, #0
    bl sub_0807cdc4
    ldr r4, lbl_0807cd48 @ =gSaveFilesInfo
    adds r0, r4, #0
    movs r1, #0
    bl sub_0807cf98
    movs r0, #1
    bl display_save_file_health
    movs r0, #1
    bl sub_0807cdc4
    adds r0, r4, #0
    adds r0, #0x18
    movs r1, #1
    bl sub_0807cf98
    movs r0, #2
    bl display_save_file_health
    movs r0, #2
    bl sub_0807cdc4
    adds r4, #0x30
    adds r0, r4, #0
    movs r1, #2
    bl sub_0807cf98
    bl sub_0807d0b0
    ldr r5, lbl_0807cd4c @ =sEwramPointer
    ldr r2, [r5]
    movs r6, #0xc0
    lsls r6, r6, #6
    adds r2, r2, r6
    movs r0, #0xc0
    lsls r0, r0, #2
    mov r8, r0
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0xcc
    lsls r0, r0, #6
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0xd8
    lsls r0, r0, #6
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0xc0
    lsls r0, r0, #5
    adds r1, r2, r0
    adds r2, r2, r6
    str r4, [sp]
    movs r0, #3
    movs r3, #0x80
    lsls r3, r3, #2
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xd0
    lsls r0, r0, #5
    adds r1, r2, r0
    movs r0, #0xcc
    lsls r0, r0, #6
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    mov r3, r8
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xe8
    lsls r0, r0, #5
    adds r1, r2, r0
    movs r0, #0xd8
    lsls r0, r0, #6
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    mov r3, r8
    bl DmaTransfer
    ldr r2, [r5]
    movs r6, #0xe4
    lsls r6, r6, #6
    adds r2, r2, r6
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0xf0
    lsls r0, r0, #6
    mov sb, r0
    add r2, sb
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0x80
    lsls r0, r0, #6
    adds r1, r2, r0
    adds r2, r2, r6
    movs r6, #0xa0
    lsls r6, r6, #2
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0x8a
    lsls r0, r0, #6
    adds r1, r2, r0
    add r2, sb
    str r4, [sp]
    movs r0, #3
    mov r3, r8
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xfc
    lsls r0, r0, #6
    mov sb, r0
    add r2, sb
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0x84
    lsls r0, r0, #7
    mov sl, r0
    add r2, sl
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r7, #0x8a
    lsls r7, r7, #7
    adds r2, r2, r7
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0xa0
    lsls r0, r0, #6
    adds r1, r2, r0
    add r2, sb
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xaa
    lsls r0, r0, #6
    adds r1, r2, r0
    add r2, sl
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xb4
    lsls r0, r0, #6
    adds r1, r2, r0
    adds r2, r2, r7
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DmaTransfer
    ldr r2, [r5]
    movs r6, #0x90
    lsls r6, r6, #7
    adds r2, r2, r6
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    mov r3, r8
    bl BitFill
    ldr r2, [r5]
    movs r0, #0x96
    lsls r0, r0, #6
    adds r1, r2, r0
    adds r2, r2, r6
    str r4, [sp]
    movs r0, #3
    movs r3, #0x80
    lsls r3, r3, #2
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xcc
    lsls r0, r0, #6
    adds r1, r2, r0
    movs r0, #0x96
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    mov r3, r8
    bl DmaTransfer
    ldr r2, [r5]
    movs r0, #0xd8
    lsls r0, r0, #6
    adds r1, r2, r0
    movs r0, #0x9c
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    mov r3, r8
    bl DmaTransfer
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807cd48: .4byte gSaveFilesInfo
lbl_0807cd4c: .4byte sEwramPointer

    thumb_func_start display_save_file_health
display_save_file_health: @ 0x0807cd50
    push {lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r3, #1
    cmp r2, #0
    beq lbl_0807cd66
    movs r3, #3
    cmp r2, #1
    bne lbl_0807cd66
    movs r3, #2
lbl_0807cd66:
    ldr r0, lbl_0807cd98 @ =gSaveFilesInfo
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #3
    adds r2, r1, r0
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0807cd7e
    movs r0, #0x12
    ldrsb r0, [r2, r0]
    cmp r0, #0
    beq lbl_0807cda0
lbl_0807cd7e:
    ldrb r0, [r2, #1]
    cmp r0, #0
    bne lbl_0807cda0
    ldr r0, lbl_0807cd9c @ =gEquipment
    ldrh r1, [r2, #4]
    strh r1, [r0, #6]
    ldrh r1, [r2, #6]
    strh r1, [r0]
    adds r0, r3, #0
    bl HudDrawEnergy
    b lbl_0807cdba
    .align 2, 0
lbl_0807cd98: .4byte gSaveFilesInfo
lbl_0807cd9c: .4byte gEquipment
lbl_0807cda0:
    subs r0, r3, #1
    lsls r2, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #5
    ldr r0, lbl_0807cdc0 @ =0x06000020
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0xe0
    bl BitFill
lbl_0807cdba:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807cdc0: .4byte 0x06000020

    thumb_func_start sub_0807cdc4
sub_0807cdc4: @ 0x0807cdc4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r0, lbl_0807cf18 @ =sEwramPointer
    ldr r0, [r0]
    movs r1, #0x80
    lsls r1, r1, #4
    adds r7, r0, r1
    movs r2, #1
    cmp r3, #0
    beq lbl_0807cdec
    movs r2, #3
    cmp r3, #1
    bne lbl_0807cdec
    movs r2, #2
lbl_0807cdec:
    subs r1, r2, #1
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #6
    adds r0, #0xdc
    adds r7, r7, r0
    ldr r1, lbl_0807cf1c @ =gSaveFilesInfo
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #3
    adds r5, r0, r1
    ldrb r0, [r5, #0x15]
    movs r1, #0xa0
    lsls r1, r1, #7
    cmp r0, #0
    beq lbl_0807ce10
    movs r1, #0xc0
    lsls r1, r1, #7
lbl_0807ce10:
    adds r6, r1, #0
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0807ce1a
    b lbl_0807cf20
lbl_0807ce1a:
    ldrb r0, [r5, #1]
    cmp r0, #0
    beq lbl_0807ce22
    b lbl_0807cf20
lbl_0807ce22:
    ldrb r0, [r5, #0xd]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r3, #0xe6
    lsls r3, r3, #1
    mov sl, r3
    mov r4, sl
    adds r0, r2, r4
    orrs r0, r6
    strh r0, [r7]
    adds r1, r7, #0
    adds r1, #0x40
    movs r0, #0xf6
    lsls r0, r0, #1
    mov sb, r0
    mov r3, sb
    adds r0, r2, r3
    orrs r0, r6
    strh r0, [r1]
    ldrb r0, [r5, #0xd]
    movs r1, #0xa
    bl __umodsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r0, r2, r4
    orrs r0, r6
    strh r0, [r7, #2]
    adds r1, r7, #0
    adds r1, #0x42
    mov r4, sb
    adds r0, r2, r4
    orrs r0, r6
    strh r0, [r1]
    movs r1, #0xe5
    lsls r1, r1, #1
    adds r0, r1, #0
    mov r8, r6
    mov r2, r8
    orrs r2, r0
    mov r8, r2
    strh r2, [r7, #4]
    adds r1, r7, #0
    adds r1, #0x44
    movs r3, #0xf5
    lsls r3, r3, #1
    adds r0, r3, #0
    adds r4, r6, #0
    orrs r4, r0
    strh r4, [r1]
    ldrb r0, [r5, #0xe]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r1, sl
    adds r0, r2, r1
    orrs r0, r6
    strh r0, [r7, #6]
    adds r1, r7, #0
    adds r1, #0x46
    mov r3, sb
    adds r0, r2, r3
    orrs r0, r6
    strh r0, [r1]
    ldrb r0, [r5, #0xe]
    movs r1, #0xa
    bl __umodsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r1, sl
    adds r0, r2, r1
    orrs r0, r6
    strh r0, [r7, #8]
    adds r1, r7, #0
    adds r1, #0x48
    mov r3, sb
    adds r0, r2, r3
    orrs r0, r6
    strh r0, [r1]
    mov r0, r8
    strh r0, [r7, #0xa]
    adds r0, r7, #0
    adds r0, #0x4a
    strh r4, [r0]
    ldrb r0, [r5, #0xf]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r1, sl
    adds r0, r2, r1
    orrs r0, r6
    strh r0, [r7, #0xc]
    adds r1, r7, #0
    adds r1, #0x4c
    mov r3, sb
    adds r0, r2, r3
    orrs r0, r6
    strh r0, [r1]
    ldrb r0, [r5, #0xf]
    movs r1, #0xa
    bl __umodsi3
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r4, sl
    adds r4, r2, r4
    str r4, [sp]
    orrs r4, r6
    strh r4, [r7, #0xe]
    adds r0, r7, #0
    adds r0, #0x4e
    add r2, sb
    orrs r2, r6
    strh r2, [r0]
    b lbl_0807cf7e
    .align 2, 0
lbl_0807cf18: .4byte sEwramPointer
lbl_0807cf1c: .4byte gSaveFilesInfo
lbl_0807cf20:
    ldr r2, lbl_0807cf90 @ =0x000001cb
    adds r0, r2, #0
    adds r2, r6, #0
    orrs r2, r0
    strh r2, [r7]
    adds r3, r7, #0
    adds r3, #0x40
    ldr r4, lbl_0807cf94 @ =0x000001eb
    adds r0, r4, #0
    adds r1, r6, #0
    orrs r1, r0
    strh r1, [r3]
    strh r2, [r7, #2]
    adds r0, r7, #0
    adds r0, #0x42
    strh r1, [r0]
    movs r3, #0xe5
    lsls r3, r3, #1
    adds r0, r3, #0
    adds r3, r6, #0
    orrs r3, r0
    strh r3, [r7, #4]
    adds r4, r7, #0
    adds r4, #0x44
    str r4, [sp, #8]
    movs r4, #0xf5
    lsls r4, r4, #1
    adds r0, r4, #0
    orrs r6, r0
    ldr r0, [sp, #8]
    strh r6, [r0]
    strh r2, [r7, #6]
    adds r0, r7, #0
    adds r0, #0x46
    strh r1, [r0]
    strh r2, [r7, #8]
    adds r0, #2
    strh r1, [r0]
    strh r3, [r7, #0xa]
    adds r0, #2
    strh r6, [r0]
    strh r2, [r7, #0xc]
    adds r0, #2
    strh r1, [r0]
    strh r2, [r7, #0xe]
    adds r0, #2
    strh r1, [r0]
lbl_0807cf7e:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807cf90: .4byte 0x000001cb
lbl_0807cf94: .4byte 0x000001eb

    thumb_func_start sub_0807cf98
sub_0807cf98: @ 0x0807cf98
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r0, r1, #0
    cmp r1, #2
    bne lbl_0807cfaa
    movs r1, #0xc0
    b lbl_0807cfba
lbl_0807cfaa:
    cmp r1, #1
    bne lbl_0807cfb2
    movs r1, #0x60
    b lbl_0807cfba
lbl_0807cfb2:
    cmp r0, #0
    beq lbl_0807cfb8
    b lbl_0807d0aa
lbl_0807cfb8:
    movs r1, #0
lbl_0807cfba:
    ldrb r3, [r5, #0x15]
    movs r0, #0xa0
    lsls r0, r0, #7
    cmp r3, #0
    beq lbl_0807cfc8
    movs r0, #0xc0
    lsls r0, r0, #7
lbl_0807cfc8:
    adds r6, r0, #0
    ldr r2, lbl_0807cff8 @ =sEwramPointer
    ldr r0, [r2]
    lsls r1, r1, #1
    adds r0, r1, r0
    ldr r7, lbl_0807cffc @ =0x000008cc
    adds r4, r0, r7
    ldrb r0, [r5]
    adds r7, r2, #0
    adds r2, r1, #0
    cmp r0, #0
    bne lbl_0807cfe8
    movs r0, #0x12
    ldrsb r0, [r5, r0]
    cmp r0, #0
    beq lbl_0807d028
lbl_0807cfe8:
    ldrb r0, [r5, #1]
    cmp r0, #0
    bne lbl_0807d028
    cmp r3, #0
    beq lbl_0807d004
    ldr r0, lbl_0807d000 @ =0x000001af
    b lbl_0807d010
    .align 2, 0
lbl_0807cff8: .4byte sEwramPointer
lbl_0807cffc: .4byte 0x000008cc
lbl_0807d000: .4byte 0x000001af
lbl_0807d004:
    ldrb r1, [r5, #0x14]
    lsls r0, r1, #2
    adds r0, r0, r1
    movs r1, #0xd0
    lsls r1, r1, #1
    adds r0, r0, r1
lbl_0807d010:
    movs r3, #4
lbl_0807d012:
    adds r1, r0, #0
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    orrs r1, r6
    strh r1, [r4]
    adds r4, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0807d012
    b lbl_0807d036
lbl_0807d028:
    movs r0, #0
    movs r3, #4
lbl_0807d02c:
    strh r0, [r4]
    adds r4, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0807d02c
lbl_0807d036:
    ldr r0, [r7]
    adds r0, r2, r0
    ldr r7, lbl_0807d04c @ =0x0000092c
    adds r4, r0, r7
    ldrb r0, [r5, #2]
    cmp r0, #0xb
    bls lbl_0807d050
    movs r3, #1
    rsbs r3, r3, #0
    b lbl_0807d05a
    .align 2, 0
lbl_0807d04c: .4byte 0x0000092c
lbl_0807d050:
    ldr r1, lbl_0807d098 @ =0x08760b18
    ldrb r0, [r5, #2]
    adds r0, r0, r1
    movs r3, #0
    ldrsb r3, [r0, r3]
lbl_0807d05a:
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_0807d068
    movs r0, #0x12
    ldrsb r0, [r5, r0]
    cmp r0, #0
    beq lbl_0807d09c
lbl_0807d068:
    cmp r3, #0
    blt lbl_0807d09c
    ldrb r0, [r5, #1]
    cmp r0, #0
    bne lbl_0807d09c
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #0x11
    movs r1, #0xbb
    lsls r1, r1, #0x11
    adds r0, r0, r1
    lsrs r0, r0, #0x10
    movs r3, #5
lbl_0807d082:
    adds r1, r0, #0
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    orrs r1, r6
    strh r1, [r4]
    adds r4, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0807d082
    b lbl_0807d0aa
    .align 2, 0
lbl_0807d098: .4byte 0x08760b18
lbl_0807d09c:
    movs r0, #0
    movs r3, #5
lbl_0807d0a0:
    strh r0, [r4]
    adds r4, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0807d0a0
lbl_0807d0aa:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0807d0b0
sub_0807d0b0: @ 0x0807d0b0
    push {r4, r5, r6, lr}
    ldr r2, lbl_0807d158 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x3b
    movs r1, #0
    strb r1, [r0]
    ldr r1, lbl_0807d15c @ =gSaveFilesInfo
    ldrb r0, [r1, #1]
    adds r6, r2, #0
    adds r3, r1, #0
    cmp r0, #0
    bne lbl_0807d0e2
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0807d0d6
    movs r0, #0x12
    ldrsb r0, [r3, r0]
    cmp r0, #0
    beq lbl_0807d0e2
lbl_0807d0d6:
    ldr r0, [r6]
    adds r0, #0x3b
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_0807d0e2:
    ldrb r0, [r3, #0x19]
    cmp r0, #0
    bne lbl_0807d108
    ldrb r0, [r3, #0x18]
    cmp r0, #0
    bne lbl_0807d0fc
    adds r0, r3, #0
    adds r0, #0x2a
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807d108
lbl_0807d0fc:
    ldr r0, [r6]
    adds r0, #0x3b
    ldrb r2, [r0]
    movs r1, #2
    orrs r1, r2
    strb r1, [r0]
lbl_0807d108:
    adds r0, r3, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807d136
    adds r0, r3, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807d12a
    adds r0, r3, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807d136
lbl_0807d12a:
    ldr r0, [r6]
    adds r0, #0x3b
    ldrb r2, [r0]
    movs r1, #4
    orrs r1, r2
    strb r1, [r0]
lbl_0807d136:
    ldr r0, lbl_0807d160 @ =sEwramPointer
    ldr r0, [r0]
    movs r1, #0xb4
    lsls r1, r1, #4
    adds r2, r0, r1
    ldr r0, [r6]
    adds r3, r0, #0
    adds r3, #0x3b
    ldrb r1, [r3]
    cmp r1, #0
    beq lbl_0807d164
    movs r0, #0x18
    orrs r0, r1
    strb r0, [r3]
    movs r4, #0
    b lbl_0807d166
    .align 2, 0
lbl_0807d158: .4byte sNonGameplayRamPointer
lbl_0807d15c: .4byte gSaveFilesInfo
lbl_0807d160: .4byte sEwramPointer
lbl_0807d164:
    movs r4, #1
lbl_0807d166:
    lsls r0, r4, #0x1c
    lsrs r4, r0, #0x10
    movs r3, #0
    ldr r5, lbl_0807d198 @ =0x00000fff
lbl_0807d16e:
    ldrh r0, [r2]
    adds r1, r5, #0
    ands r1, r0
    orrs r1, r4
    strh r1, [r2]
    adds r2, #2
    adds r0, r3, #1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0x7f
    bls lbl_0807d16e
    ldr r0, [r6]
    adds r0, #0x3b
    ldrb r2, [r0]
    movs r1, #0x20
    orrs r1, r2
    strb r1, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807d198: .4byte 0x00000fff

    thumb_func_start sub_0807d19c
sub_0807d19c: @ 0x0807d19c
    push {r4, r5, lr}
    adds r5, r1, #0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r0, lbl_0807d1b8 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d1bc
    movs r3, #1
    rsbs r3, r3, #0
    b lbl_0807d1ca
    .align 2, 0
lbl_0807d1b8: .4byte gChangedInput
lbl_0807d1bc:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0807d1c8
    movs r0, #0
    b lbl_0807d228
lbl_0807d1c8:
    movs r3, #1
lbl_0807d1ca:
    ldrb r2, [r5]
    ldr r0, lbl_0807d1e0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x3b
    ldrb r1, [r1]
    cmp r4, #0
    bne lbl_0807d1e4
    movs r0, #7
    orrs r1, r0
    b lbl_0807d206
    .align 2, 0
lbl_0807d1e0: .4byte sNonGameplayRamPointer
lbl_0807d1e4:
    cmp r4, #1
    bne lbl_0807d1f2
    movs r0, #7
    ands r1, r0
    b lbl_0807d206
lbl_0807d1ee:
    movs r3, #0
    b lbl_0807d224
lbl_0807d1f2:
    cmp r4, #2
    bne lbl_0807d206
    adds r0, #0x26
    movs r1, #1
    ldrb r0, [r0]
    lsls r1, r0
    movs r0, #7
    adds r4, r0, #0
    bics r4, r1
    adds r1, r4, #0
lbl_0807d206:
    movs r4, #1
lbl_0807d208:
    cmp r3, #0
    beq lbl_0807d224
    adds r0, r2, r3
    cmp r0, #5
    bhi lbl_0807d1ee
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r0, r1, #0
    asrs r0, r2
    ands r0, r4
    cmp r0, #0
    beq lbl_0807d208
    strb r2, [r5]
    movs r3, #1
lbl_0807d224:
    lsls r0, r3, #0x18
    lsrs r0, r0, #0x18
lbl_0807d228:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0807d230
sub_0807d230: @ 0x0807d230
    push {r4, r5, lr}
    adds r5, r0, #0
    ldr r0, lbl_0807d258 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3b
    ldrb r1, [r0]
    adds r3, r1, #0
    ldrb r2, [r5]
    adds r0, r1, #0
    asrs r0, r2
    movs r4, #1
    ands r0, r4
    cmp r0, #0
    bne lbl_0807d274
    adds r0, r1, #0
    ands r0, r4
    cmp r0, #0
    beq lbl_0807d25c
    movs r2, #0
    b lbl_0807d272
    .align 2, 0
lbl_0807d258: .4byte sNonGameplayRamPointer
lbl_0807d25c:
    movs r0, #2
    ands r1, r0
    cmp r1, #0
    beq lbl_0807d268
    movs r2, #1
    b lbl_0807d272
lbl_0807d268:
    movs r0, #4
    ands r3, r0
    cmp r3, #0
    beq lbl_0807d272
    movs r2, #2
lbl_0807d272:
    strb r2, [r5]
lbl_0807d274:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0807d27c
sub_0807d27c: @ 0x0807d27c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0807d298 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    ldrb r0, [r0]
    cmp r0, #6
    bls lbl_0807d28c
    b lbl_0807d576
lbl_0807d28c:
    lsls r0, r0, #2
    ldr r1, lbl_0807d29c @ =lbl_0807d2a0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807d298: .4byte sNonGameplayRamPointer
lbl_0807d29c: .4byte lbl_0807d2a0
lbl_0807d2a0: @ jump table
    .4byte lbl_0807d2bc @ case 0
    .4byte lbl_0807d42c @ case 1
    .4byte lbl_0807d4e4 @ case 2
    .4byte lbl_0807d504 @ case 3
    .4byte lbl_0807d524 @ case 4
    .4byte lbl_0807d544 @ case 5
    .4byte lbl_0807d560 @ case 6
lbl_0807d2bc:
    movs r4, #0
    bl CheckForMaintainedInput
    ldr r5, lbl_0807d2e0 @ =gChangedInput
    ldrh r0, [r5]
    cmp r0, #0
    beq lbl_0807d300
    ldr r0, lbl_0807d2e4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r1, #0x3f
    movs r0, #0
    bl sub_0807d19c
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807d2e8
    movs r4, #1
    b lbl_0807d306
    .align 2, 0
lbl_0807d2e0: .4byte gChangedInput
lbl_0807d2e4: .4byte sNonGameplayRamPointer
lbl_0807d2e8:
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d2f6
    movs r4, #2
    b lbl_0807d306
lbl_0807d2f6:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d300
    movs r4, #3
lbl_0807d300:
    cmp r4, #0
    bne lbl_0807d306
    b lbl_0807d576
lbl_0807d306:
    cmp r4, #1
    bne lbl_0807d338
    ldr r4, lbl_0807d32c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #1
    bl sub_08078504
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #2
    bhi lbl_0807d330
    movs r0, #2
    bl FileSelectPlayMenuSound
    b lbl_0807d576
    .align 2, 0
lbl_0807d32c: .4byte sNonGameplayRamPointer
lbl_0807d330:
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_0807d576
lbl_0807d338:
    cmp r4, #2
    bne lbl_0807d34c
    movs r0, #0
    bl FadeMusic
    ldr r1, lbl_0807d348 @ =gGameModeSub2
    movs r0, #3
    b lbl_0807d554
    .align 2, 0
lbl_0807d348: .4byte gGameModeSub2
lbl_0807d34c:
    cmp r4, #3
    beq lbl_0807d352
    b lbl_0807d576
lbl_0807d352:
    movs r4, #0
    ldr r1, lbl_0807d36c @ =sNonGameplayRamPointer
    ldr r0, [r1]
    adds r0, #0x3f
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #5
    bhi lbl_0807d404
    lsls r0, r0, #2
    ldr r1, lbl_0807d370 @ =lbl_0807d374
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807d36c: .4byte sNonGameplayRamPointer
lbl_0807d370: .4byte lbl_0807d374
lbl_0807d374: @ jump table
    .4byte lbl_0807d38c @ case 0
    .4byte lbl_0807d38c @ case 1
    .4byte lbl_0807d38c @ case 2
    .4byte lbl_0807d3a4 @ case 3
    .4byte lbl_0807d3c4 @ case 4
    .4byte lbl_0807d3e4 @ case 5
lbl_0807d38c:
    movs r0, #3
    bl FileSelectPlayMenuSound
    movs r6, #5
    movs r4, #1
    ldr r0, lbl_0807d3a0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3e
    strb r4, [r0]
    b lbl_0807d404
    .align 2, 0
lbl_0807d3a0: .4byte sNonGameplayRamPointer
lbl_0807d3a4:
    ldr r0, [r5]
    adds r0, #0x3b
    ldrb r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d404
    movs r0, #1
    bl FileSelectPlayMenuSound
    movs r6, #2
    movs r4, #1
    ldr r0, [r5]
    adds r0, #0x3e
    strb r6, [r0]
    b lbl_0807d404
lbl_0807d3c4:
    ldr r0, [r5]
    adds r0, #0x3b
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d404
    movs r0, #1
    bl FileSelectPlayMenuSound
    movs r6, #2
    movs r4, #1
    ldr r0, [r5]
    adds r0, #0x3e
    movs r1, #3
    b lbl_0807d402
lbl_0807d3e4:
    ldr r0, [r5]
    adds r0, #0x3b
    ldrb r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0807d404
    movs r0, #1
    bl FileSelectPlayMenuSound
    movs r6, #2
    movs r4, #1
    ldr r0, [r5]
    adds r0, #0x3e
    movs r1, #5
lbl_0807d402:
    strb r1, [r0]
lbl_0807d404:
    cmp r4, #0
    bne lbl_0807d40a
    b lbl_0807d576
lbl_0807d40a:
    ldr r4, lbl_0807d428 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    adds r0, r6, #0
    bl sub_08078504
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x42
    strh r1, [r0]
    b lbl_0807d576
    .align 2, 0
lbl_0807d428: .4byte sNonGameplayRamPointer
lbl_0807d42c:
    bl sub_0807d62c
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0807d43a
    b lbl_0807d576
lbl_0807d43a:
    cmp r4, #2
    bne lbl_0807d4cc
    ldr r3, lbl_0807d4bc @ =sNonGameplayRamPointer
    ldr r0, [r3]
    adds r0, #0x3a
    ldrb r0, [r0]
    ldr r5, lbl_0807d4c0 @ =gSaveFilesInfo
    ldr r4, lbl_0807d4c4 @ =gMostRecentSaveFile
    cmp r0, #0
    blt lbl_0807d496
    cmp r0, #1
    ble lbl_0807d496
    cmp r0, #4
    bgt lbl_0807d496
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r5
    movs r1, #0
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r5
    ldr r0, [r3]
    adds r0, #0x32
    ldrb r0, [r0]
    strb r0, [r1, #0x14]
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r5
    movs r2, #0
    ldr r0, [r3]
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0807d494
    movs r2, #1
lbl_0807d494:
    strb r2, [r1, #0x15]
lbl_0807d496:
    ldr r2, lbl_0807d4c8 @ =gGameModeSub2
    movs r0, #0
    ldrsb r0, [r4, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r5
    ldrb r0, [r1]
    movs r1, #2
    cmp r0, #0
    beq lbl_0807d4ae
    movs r1, #1
lbl_0807d4ae:
    strb r1, [r2]
    movs r0, #0x14
    bl FadeMusic
    movs r0, #1
    b lbl_0807d57c
    .align 2, 0
lbl_0807d4bc: .4byte sNonGameplayRamPointer
lbl_0807d4c0: .4byte gSaveFilesInfo
lbl_0807d4c4: .4byte gMostRecentSaveFile
lbl_0807d4c8: .4byte gGameModeSub2
lbl_0807d4cc:
    ldr r4, lbl_0807d4e0 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #6
    bl sub_08078504
    ldr r0, [r4]
    b lbl_0807d570
    .align 2, 0
lbl_0807d4e0: .4byte sNonGameplayRamPointer
lbl_0807d4e4:
    bl sub_08079210
    cmp r0, #0
    beq lbl_0807d576
    ldr r4, lbl_0807d500 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078504
    ldr r0, [r4]
    b lbl_0807d570
    .align 2, 0
lbl_0807d500: .4byte sNonGameplayRamPointer
lbl_0807d504:
    bl sub_080797a0
    cmp r0, #0
    beq lbl_0807d576
    ldr r4, lbl_0807d520 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078504
    ldr r0, [r4]
    b lbl_0807d570
    .align 2, 0
lbl_0807d520: .4byte sNonGameplayRamPointer
lbl_0807d524:
    bl sub_08079b50
    cmp r0, #0
    beq lbl_0807d576
    ldr r4, lbl_0807d540 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #0
    bl sub_08078504
    ldr r0, [r4]
    b lbl_0807d570
    .align 2, 0
lbl_0807d540: .4byte sNonGameplayRamPointer
lbl_0807d544:
    movs r0, #0
    bl sub_0807a2bc
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807d576
    ldr r1, lbl_0807d55c @ =gGameModeSub2
    movs r0, #0
lbl_0807d554:
    strb r0, [r1]
    movs r0, #1
    b lbl_0807d57c
    .align 2, 0
lbl_0807d55c: .4byte gGameModeSub2
lbl_0807d560:
    movs r0, #1
    bl sub_0807a2bc
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807d576
    ldr r0, lbl_0807d584 @ =sNonGameplayRamPointer
    ldr r0, [r0]
lbl_0807d570:
    adds r0, #0x3e
    movs r1, #0
    strb r1, [r0]
lbl_0807d576:
    bl sub_08078da0
    movs r0, #0
lbl_0807d57c:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807d584: .4byte sNonGameplayRamPointer

    thumb_func_start check_inputting_time_attack_code
check_inputting_time_attack_code: @ 0x0807d588
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0807d5ac @ =gChangedInput
    ldrh r2, [r0]
    adds r6, r2, #0
    ldr r5, lbl_0807d5b0 @ =sNonGameplayRamPointer
    ldr r1, [r5]
    adds r4, r1, #0
    adds r4, #0x6c
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0807d5d6
    adds r1, #0x6e
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807d5b4
    subs r0, #1
    strh r0, [r1]
    b lbl_0807d622
    .align 2, 0
lbl_0807d5ac: .4byte gChangedInput
lbl_0807d5b0: .4byte sNonGameplayRamPointer
lbl_0807d5b4:
    ldr r0, lbl_0807d5c8 @ =0x0845f452
    ldrh r0, [r0]
    cmp r2, r0
    bne lbl_0807d5cc
    movs r1, #1
    strb r1, [r4]
    ldr r0, [r5]
    adds r0, #0x6d
    strb r1, [r0]
    b lbl_0807d622
    .align 2, 0
lbl_0807d5c8: .4byte 0x0845f452
lbl_0807d5cc:
    cmp r2, #0
    beq lbl_0807d622
    movs r0, #0x1e
    strh r0, [r1]
    b lbl_0807d622
lbl_0807d5d6:
    ldr r7, lbl_0807d604 @ =0x0845f452
    adds r3, r1, #0
    adds r3, #0x6d
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r7
    ldrh r0, [r0]
    cmp r2, r0
    bne lbl_0807d60c
    adds r0, r1, #1
    strb r0, [r3]
    ldr r0, [r5]
    adds r0, #0x6d
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r1, [r0]
    ldr r0, lbl_0807d608 @ =0x0000ffff
    cmp r1, r0
    bne lbl_0807d622
    movs r0, #1
    b lbl_0807d624
    .align 2, 0
lbl_0807d604: .4byte 0x0845f452
lbl_0807d608: .4byte 0x0000ffff
lbl_0807d60c:
    cmp r6, #0
    beq lbl_0807d622
    movs r1, #0
    strb r1, [r4]
    ldr r0, [r5]
    adds r0, #0x6d
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x6e
    movs r1, #0x1e
    strh r1, [r0]
lbl_0807d622:
    movs r0, #0
lbl_0807d624:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0807d62c
sub_0807d62c: @ 0x0807d62c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov sl, r0
    ldr r2, lbl_0807d664 @ =sNonGameplayRamPointer
    ldr r1, [r2]
    adds r3, r1, #0
    adds r3, #0x42
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r7, r2, #0
    cmp r0, #0x2c
    bls lbl_0807d658
    bl lbl_0807e3e6
lbl_0807d658:
    lsls r0, r0, #2
    ldr r1, lbl_0807d668 @ =lbl_0807d66c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807d664: .4byte sNonGameplayRamPointer
lbl_0807d668: .4byte lbl_0807d66c
lbl_0807d66c: @ jump table
    .4byte lbl_0807d720 @ case 0
    .4byte lbl_0807d854 @ case 1
    .4byte lbl_0807d8ec @ case 2
    .4byte lbl_0807d922 @ case 3
    .4byte lbl_0807d978 @ case 4
    .4byte lbl_0807d986 @ case 5
    .4byte lbl_0807d9a4 @ case 6
    .4byte lbl_0807d9c8 @ case 7
    .4byte lbl_0807daa8 @ case 8
    .4byte lbl_0807db0a @ case 9
    .4byte lbl_0807db28 @ case 10
    .4byte lbl_0807db50 @ case 11
    .4byte lbl_0807dc1a @ case 12
    .4byte lbl_0807dc44 @ case 13
    .4byte lbl_0807dc66 @ case 14
    .4byte lbl_0807e3b6 @ case 15
    .4byte lbl_0807dc7c @ case 16
    .4byte lbl_0807dcac @ case 17
    .4byte lbl_0807dd78 @ case 18
    .4byte lbl_0807ddc4 @ case 19
    .4byte lbl_0807dde0 @ case 20
    .4byte lbl_0807ddfc @ case 21
    .4byte lbl_0807de56 @ case 22
    .4byte lbl_0807de68 @ case 23
    .4byte lbl_0807de8c @ case 24
    .4byte lbl_0807df38 @ case 25
    .4byte lbl_0807df78 @ case 26
    .4byte lbl_0807dfb0 @ case 27
    .4byte lbl_0807dfdc @ case 28
    .4byte lbl_0807dfec @ case 29
    .4byte lbl_0807e010 @ case 30
    .4byte lbl_0807e0da @ case 31
    .4byte lbl_0807e3e6 @ case 32
    .4byte lbl_0807e3e6 @ case 33
    .4byte lbl_0807e11e @ case 34
    .4byte lbl_0807e132 @ case 35
    .4byte lbl_0807e164 @ case 36
    .4byte lbl_0807e190 @ case 37
    .4byte lbl_0807e1a4 @ case 38
    .4byte lbl_0807e26a @ case 39
    .4byte lbl_0807e288 @ case 40
    .4byte lbl_0807e2c4 @ case 41
    .4byte lbl_0807e2ec @ case 42
    .4byte lbl_0807e34c @ case 43
    .4byte lbl_0807e3d8 @ case 44
lbl_0807d720:
    ldr r2, lbl_0807d824 @ =gMostRecentSaveFile
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r1, [r0]
    strb r1, [r2]
    ldrb r0, [r0]
    adds r0, #1
    lsls r4, r0, #1
    adds r4, r4, r0
    ldr r5, lbl_0807d828 @ =sEwramPointer
    ldr r2, [r5]
    movs r1, #0x86
    lsls r1, r1, #5
    adds r2, r2, r1
    movs r3, #0x90
    lsls r3, r3, #2
    movs r0, #0x10
    mov r8, r0
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    lsls r4, r4, #6
    movs r1, #0x80
    lsls r1, r1, #4
    mov sb, r1
    adds r1, r4, r1
    ldr r2, [r5]
    adds r1, r2, r1
    movs r6, #0x80
    lsls r6, r6, #5
    adds r4, r4, r6
    adds r2, r2, r4
    mov r3, r8
    str r3, [sp]
    movs r0, #3
    movs r3, #0xc0
    bl DmaTransfer
    ldr r1, [r5]
    adds r1, r1, r6
    ldr r2, lbl_0807d82c @ =0x0600f000
    mov r5, r8
    str r5, [sp]
    movs r0, #3
    mov r3, sb
    bl DmaTransfer
    ldr r2, [r7]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r0, r3, #0
    movs r4, #0
    movs r3, #0
    orrs r0, r1
    movs r5, #0x80
    lsls r5, r5, #6
    adds r1, r5, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0807d830 @ =0x04000040
    ldr r5, lbl_0807d834 @ =0x000046aa
    adds r0, r5, #0
    strh r0, [r1]
    adds r1, #4
    movs r0, #0x17
    strh r0, [r1]
    adds r1, #6
    movs r0, #0x3f
    strh r0, [r1]
    subs r1, #2
    movs r0, #0x1f
    strb r0, [r1]
    ldr r0, lbl_0807d838 @ =gWrittenToBLDALPHA_H
    strh r3, [r0]
    ldr r0, lbl_0807d83c @ =gWrittenToBLDALPHA_L
    mov r1, r8
    strh r1, [r0]
    ldr r0, lbl_0807d840 @ =0x00003f42
    strh r0, [r2, #2]
    adds r2, #0x3a
    strb r4, [r2]
    ldr r2, [r7]
    ldr r0, lbl_0807d844 @ =0x08760b38
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2, #0x2c]
    str r1, [r2, #0x30]
    adds r0, r2, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807d7ea
    ldr r3, lbl_0807d848 @ =0x0000013f
    adds r2, r2, r3
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
lbl_0807d7ea:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0807d802
    ldr r5, lbl_0807d84c @ =0x0000014f
    adds r2, r1, r5
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
lbl_0807d802:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0807d812
    bl lbl_0807e3b6
lbl_0807d812:
    ldr r0, lbl_0807d850 @ =0x0000015f
    adds r2, r1, r0
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    bl lbl_0807e3b6
    .align 2, 0
lbl_0807d824: .4byte gMostRecentSaveFile
lbl_0807d828: .4byte sEwramPointer
lbl_0807d82c: .4byte 0x0600f000
lbl_0807d830: .4byte 0x04000040
lbl_0807d834: .4byte 0x000046aa
lbl_0807d838: .4byte gWrittenToBLDALPHA_H
lbl_0807d83c: .4byte gWrittenToBLDALPHA_L
lbl_0807d840: .4byte 0x00003f42
lbl_0807d844: .4byte 0x08760b38
lbl_0807d848: .4byte 0x0000013f
lbl_0807d84c: .4byte 0x0000014f
lbl_0807d850: .4byte 0x0000015f
lbl_0807d854:
    movs r5, #1
    ldr r1, lbl_0807d86c @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807d872
    movs r5, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807d870
    strh r5, [r1]
    b lbl_0807d872
    .align 2, 0
lbl_0807d86c: .4byte gWrittenToBLDALPHA_L
lbl_0807d870:
    strh r0, [r1]
lbl_0807d872:
    ldr r1, lbl_0807d8e0 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807d886
    movs r5, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807d884
    movs r0, #0x10
lbl_0807d884:
    strh r0, [r1]
lbl_0807d886:
    cmp r5, #0
    bne lbl_0807d88e
    bl lbl_0807e3e6
lbl_0807d88e:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807d8a6
    adds r0, r1, #0
    adds r0, #0xff
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_0807d8a6:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0807d8be
    ldr r3, lbl_0807d8e4 @ =0x0000010f
    adds r2, r1, r3
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
lbl_0807d8be:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0807d8ce
    bl lbl_0807e3b6
lbl_0807d8ce:
    ldr r5, lbl_0807d8e8 @ =0x0000011f
    adds r2, r1, r5
    ldrb r0, [r2]
    movs r1, #0x20
    orrs r0, r1
    strb r0, [r2]
    bl lbl_0807e3b6
    .align 2, 0
lbl_0807d8e0: .4byte gWrittenToBLDALPHA_H
lbl_0807d8e4: .4byte 0x0000010f
lbl_0807d8e8: .4byte 0x0000011f
lbl_0807d8ec:
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #5
    movs r1, #0x80
    lsls r1, r1, #4
    adds r5, r0, r1
    ldr r1, lbl_0807d918 @ =gBG2VOFS_NonGameplay
    ldrh r0, [r1]
    cmp r5, r0
    beq lbl_0807d91c
    adds r0, #0xc
    cmp r0, r5
    ble lbl_0807d912
    bl sub_0807e2fe
lbl_0807d912:
    bl lbl_0807e30c
    .align 2, 0
lbl_0807d918: .4byte gBG2VOFS_NonGameplay
lbl_0807d91c:
    adds r1, r2, #0
    bl lbl_0807e3b8
lbl_0807d922:
    ldr r0, lbl_0807d96c @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r1, r2
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r0, [r0]
    lsls r2, r0, #1
    adds r2, r2, r0
    lsls r2, r2, #6
    ldr r3, lbl_0807d970 @ =0x0600f000
    adds r2, r2, r3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0xc0
    bl DmaTransfer
    ldr r2, [r7]
    ldrh r1, [r2]
    ldr r0, lbl_0807d974 @ =0x0000dfff
    ands r0, r1
    strh r0, [r2]
    movs r0, #0
    bl sub_0807e6d8
    movs r0, #0
    movs r1, #0
    bl sub_080790cc
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #4
    strb r1, [r0]
    bl lbl_0807e3e6
    .align 2, 0
lbl_0807d96c: .4byte sEwramPointer
lbl_0807d970: .4byte 0x0600f000
lbl_0807d974: .4byte 0x0000dfff
lbl_0807d978:
    movs r0, #1
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807d986
    bl lbl_0807e3e6
lbl_0807d986:
    ldr r4, lbl_0807d9a0 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x2e
    ldrb r1, [r0]
    movs r0, #0
    bl sub_0807e3fc
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #6
    strb r1, [r0]
    bl lbl_0807e3e6
    .align 2, 0
lbl_0807d9a0: .4byte sNonGameplayRamPointer
lbl_0807d9a4:
    ldr r0, [r7]
    adds r0, #0x6c
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0x6d
    strb r1, [r0]
    ldr r0, [r7]
    adds r3, r0, #0
    adds r3, #0x6e
    movs r2, #0
    strh r1, [r3]
    adds r0, #0x70
    strb r2, [r0]
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #7
    strb r1, [r0]
lbl_0807d9c8:
    movs r5, #0xff
    ldr r0, lbl_0807da18 @ =gChangedInput
    ldrh r1, [r0]
    movs r2, #1
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0807da2e
    movs r5, #0x80
    movs r0, #1
    bl FileSelectPlayMenuSound
    ldr r2, lbl_0807da1c @ =gSaveFilesInfo
    ldr r4, lbl_0807da20 @ =sNonGameplayRamPointer
    ldr r3, [r4]
    adds r0, r3, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r2
    movs r2, #0x11
    ldrsb r2, [r1, r2]
    cmp r2, #0
    bne lbl_0807da24
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807da0a
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_0807da24
lbl_0807da0a:
    adds r0, r3, #0
    adds r0, #0x3a
    strb r2, [r0]
    ldr r0, [r4]
    adds r0, #0x40
    movs r1, #0x22
    b lbl_0807da84
    .align 2, 0
lbl_0807da18: .4byte gChangedInput
lbl_0807da1c: .4byte gSaveFilesInfo
lbl_0807da20: .4byte sNonGameplayRamPointer
lbl_0807da24:
    adds r1, r3, #0
    adds r1, #0x40
    movs r0, #8
    strb r0, [r1]
    b lbl_0807da86
lbl_0807da2e:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807da40
    movs r5, #0x81
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x27
    b lbl_0807da84
lbl_0807da40:
    ldr r0, lbl_0807daa0 @ =gFileScreenOptionsUnlocked
    ldr r0, [r0, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0807da86
    ldr r2, lbl_0807daa4 @ =gSaveFilesInfo
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #0x11]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807da86
    bl check_inputting_time_attack_code
    cmp r0, #0
    beq lbl_0807da86
    movs r5, #0x80
    ldr r0, [r7]
    adds r0, #0x2f
    movs r1, #2
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0x70
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #8
lbl_0807da84:
    strb r1, [r0]
lbl_0807da86:
    adds r0, r5, #1
    cmp r0, #0
    bne lbl_0807da90
    bl lbl_0807e3e6
lbl_0807da90:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #0
    bl sub_0807e3fc
    bl lbl_0807e3e6
    .align 2, 0
lbl_0807daa0: .4byte gFileScreenOptionsUnlocked
lbl_0807daa4: .4byte gSaveFilesInfo
lbl_0807daa8:
    ldr r2, lbl_0807dae0 @ =gSaveFilesInfo
    ldr r3, [r7]
    adds r0, r3, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r1, r0, r2
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807dac8
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_0807daf6
lbl_0807dac8:
    ldrb r0, [r1, #0x15]
    cmp r0, #0
    bne lbl_0807dad8
    adds r0, r3, #0
    adds r0, #0x70
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807dae4
lbl_0807dad8:
    adds r1, r3, #0
    adds r1, #0x39
    movs r0, #0x10
    b lbl_0807daea
    .align 2, 0
lbl_0807dae0: .4byte gSaveFilesInfo
lbl_0807dae4:
    adds r1, r3, #0
    adds r1, #0x39
    movs r0, #0xf
lbl_0807daea:
    strb r0, [r1]
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #9
    strb r1, [r0]
    b lbl_0807dafe
lbl_0807daf6:
    adds r1, r3, #0
    adds r1, #0x40
    movs r0, #0x15
    strb r0, [r1]
lbl_0807dafe:
    ldr r0, [r7]
    adds r0, #0x42
    movs r1, #0
    strh r1, [r0]
    bl lbl_0807e3e6
lbl_0807db0a:
    ldr r0, [r7]
    adds r0, #0x39
    ldrb r1, [r0]
    movs r0, #0
    bl sub_080790cc
    movs r0, #0
    movs r1, #0x14
    bl sub_080790cc
    movs r0, #0x1d
    bl sub_0807e6d8
    bl lbl_0807e3b6
lbl_0807db28:
    movs r0, #0x1e
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807db36
    bl lbl_0807e3e6
lbl_0807db36:
    ldr r4, lbl_0807db4c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x2f
    ldrb r1, [r0]
    movs r0, #5
    bl sub_0807e3fc
    ldr r1, [r4]
    bl lbl_0807e3b8
    .align 2, 0
lbl_0807db4c: .4byte sNonGameplayRamPointer
lbl_0807db50:
    movs r5, #0xff
    ldr r0, lbl_0807db7c @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807dc02
    movs r4, #1
    ands r4, r1
    cmp r4, #0
    beq lbl_0807db80
    movs r5, #0x80
    ldr r0, [r7]
    adds r0, #0x42
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    bl FileSelectPlayMenuSound
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0xd
    strb r1, [r0]
    b lbl_0807dc02
    .align 2, 0
lbl_0807db7c: .4byte gChangedInput
lbl_0807db80:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dba8
    movs r0, #0x1f
    bl sub_0807e6d8
    movs r5, #0x81
    ldr r0, lbl_0807dba4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x42
    strh r4, [r1]
    adds r0, #0x40
    movs r1, #0xc
    strb r1, [r0]
    b lbl_0807dc02
    .align 2, 0
lbl_0807dba4: .4byte sNonGameplayRamPointer
lbl_0807dba8:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dbc0
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807dc02
    subs r0, #1
    b lbl_0807dbde
lbl_0807dbc0:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dc02
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x39
    ldrb r0, [r0]
    cmp r0, #0x10
    bne lbl_0807dbec
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #1
    bhi lbl_0807dc02
    adds r0, #1
lbl_0807dbde:
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_0807dc02
lbl_0807dbec:
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807dc02
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_0807dc02:
    adds r0, r5, #1
    cmp r0, #0
    bne lbl_0807dc0c
    bl lbl_0807e3e6
lbl_0807dc0c:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #5
    bl sub_0807e3fc
    bl lbl_0807e3e6
lbl_0807dc1a:
    movs r0, #0x20
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807dc28
    bl lbl_0807e3e6
lbl_0807dc28:
    ldr r2, lbl_0807dc40 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #2
    bne lbl_0807dc3a
    movs r0, #0
    strb r0, [r1]
lbl_0807dc3a:
    ldr r0, [r2]
    b lbl_0807e20a
    .align 2, 0
lbl_0807dc40: .4byte sNonGameplayRamPointer
lbl_0807dc44:
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x42
    movs r0, #0
    strh r0, [r2]
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807dc5e
    adds r1, #0x3a
    movs r0, #1
    b lbl_0807df94
lbl_0807dc5e:
    adds r1, #0x40
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0807e3e6
lbl_0807dc66:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0xa
    bhi lbl_0807dc74
    b lbl_0807e3e6
lbl_0807dc74:
    adds r1, #0x40
    movs r0, #0xf
    strb r0, [r1]
    b lbl_0807e3e6
lbl_0807dc7c:
    movs r0, #0x22
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807dc88
    b lbl_0807e3e6
lbl_0807dc88:
    ldr r4, lbl_0807dca4 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_0807dca8 @ =0x08760b38
    ldrb r1, [r1, #4]
    adds r0, #0x30
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0x30
    ldrb r1, [r0]
    movs r0, #6
    bl sub_0807e3fc
    ldr r1, [r4]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807dca4: .4byte sNonGameplayRamPointer
lbl_0807dca8: .4byte 0x08760b38
lbl_0807dcac:
    movs r5, #0xff
    ldr r0, lbl_0807dcdc @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807dd64
    movs r2, #1
    ands r2, r1
    cmp r2, #0
    beq lbl_0807dd00
    ldr r0, lbl_0807dce0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    adds r2, r1, #0
    adds r2, #0x42
    movs r0, #0
    strh r0, [r2]
    movs r5, #0x80
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807dce8
    ldr r0, lbl_0807dce4 @ =0x00000209
    bl SoundPlay
    b lbl_0807dcee
    .align 2, 0
lbl_0807dcdc: .4byte gChangedInput
lbl_0807dce0: .4byte sNonGameplayRamPointer
lbl_0807dce4: .4byte 0x00000209
lbl_0807dce8:
    movs r0, #1
    bl FileSelectPlayMenuSound
lbl_0807dcee:
    ldr r0, lbl_0807dcfc @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #0x12
    strb r1, [r0]
    b lbl_0807dd64
    .align 2, 0
lbl_0807dcfc: .4byte sNonGameplayRamPointer
lbl_0807dd00:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dd24
    ldr r0, [r7]
    adds r0, #0x42
    strh r2, [r0]
    movs r5, #0x81
    ldr r0, lbl_0807dd20 @ =0x00000209
    bl SoundPlay
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x13
    strb r1, [r0]
    b lbl_0807dd64
    .align 2, 0
lbl_0807dd20: .4byte 0x00000209
lbl_0807dd24:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dd44
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807dd64
    movs r5, #0
    strb r5, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_0807dd64
lbl_0807dd44:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dd64
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807dd64
    movs r5, #1
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_0807dd64:
    adds r0, r5, #1
    cmp r0, #0
    bne lbl_0807dd6c
    b lbl_0807e3e6
lbl_0807dd6c:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #6
    bl sub_0807e3fc
    b lbl_0807e3e6
lbl_0807dd78:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0xa
    bhi lbl_0807dd86
    b lbl_0807e3e6
lbl_0807dd86:
    adds r0, r1, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807dd98
    adds r1, #0x40
    movs r0, #0x13
    strb r0, [r1]
    b lbl_0807e3e6
lbl_0807dd98:
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    movs r2, #2
    cmp r0, r2
    beq lbl_0807ddbc
    movs r0, #6
    movs r1, #0x81
    bl sub_0807e3fc
    movs r0, #0x23
    bl sub_0807e6d8
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x14
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807ddbc:
    adds r0, r1, #0
    adds r0, #0x3a
    strb r2, [r0]
    b lbl_0807df96
lbl_0807ddc4:
    movs r0, #0x25
    bl sub_0807e6d8
    ldr r4, lbl_0807dddc @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x2f
    ldrb r1, [r0]
    movs r0, #5
    bl sub_0807e3fc
    ldr r0, [r4]
    b lbl_0807e220
    .align 2, 0
lbl_0807dddc: .4byte sNonGameplayRamPointer
lbl_0807dde0:
    movs r0, #0x24
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807ddec
    b lbl_0807e3e6
lbl_0807ddec:
    ldr r0, lbl_0807ddf8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x40
    movs r1, #0x15
    strb r1, [r0]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807ddf8: .4byte sNonGameplayRamPointer
lbl_0807ddfc:
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x1c
    strb r1, [r0]
    ldr r3, [r7]
    adds r0, r3, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0807de1a
    adds r1, r3, #0
    adds r1, #0x32
    movs r0, #1
    strb r0, [r1]
    b lbl_0807e3e6
lbl_0807de1a:
    ldr r2, lbl_0807de3c @ =gSaveFilesInfo
    adds r0, r3, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r0, #0x11]
    movs r0, #0x36
    ands r0, r1
    cmp r0, #0
    beq lbl_0807de40
    adds r1, r3, #0
    adds r1, #0x38
    movs r0, #0x13
    b lbl_0807de46
    .align 2, 0
lbl_0807de3c: .4byte gSaveFilesInfo
lbl_0807de40:
    adds r1, r3, #0
    adds r1, #0x38
    movs r0, #0x12
lbl_0807de46:
    strb r0, [r1]
    ldr r0, [r7]
    adds r0, #0x38
    ldrb r1, [r0]
    movs r0, #0
    bl sub_080790cc
    b lbl_0807e3e6
lbl_0807de56:
    movs r0, #2
    bl sub_0807e6d8
    ldr r0, lbl_0807de64 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807de64: .4byte sNonGameplayRamPointer
lbl_0807de68:
    movs r0, #3
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807de74
    b lbl_0807e3e6
lbl_0807de74:
    ldr r4, lbl_0807de88 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x31
    ldrb r1, [r0]
    movs r0, #1
    bl sub_0807e3fc
    ldr r1, [r4]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807de88: .4byte sNonGameplayRamPointer
lbl_0807de8c:
    movs r5, #0xff
    ldr r0, lbl_0807deb8 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807df24
    movs r4, #1
    ands r4, r1
    cmp r4, #0
    beq lbl_0807debc
    movs r5, #0x80
    ldr r0, [r7]
    adds r0, #0x42
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    bl FileSelectPlayMenuSound
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x1a
    strb r1, [r0]
    b lbl_0807df24
    .align 2, 0
lbl_0807deb8: .4byte gChangedInput
lbl_0807debc:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807dee4
    movs r0, #4
    bl sub_0807e6d8
    movs r5, #0x81
    ldr r0, lbl_0807dee0 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x42
    strh r4, [r1]
    adds r0, #0x40
    movs r1, #0x19
    strb r1, [r0]
    b lbl_0807df24
    .align 2, 0
lbl_0807dee0: .4byte sNonGameplayRamPointer
lbl_0807dee4:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0807df04
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807df24
    movs r5, #0
    strb r5, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_0807df24
lbl_0807df04:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0807df24
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807df24
    movs r5, #1
    movs r0, #1
    strb r0, [r1]
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_0807df24:
    adds r0, r5, #1
    cmp r0, #0
    bne lbl_0807df2c
    b lbl_0807e3e6
lbl_0807df2c:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #1
    bl sub_0807e3fc
    b lbl_0807e3e6
lbl_0807df38:
    movs r0, #5
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807df44
    b lbl_0807e3e6
lbl_0807df44:
    ldr r2, lbl_0807df70 @ =gSaveFilesInfo
    ldr r0, lbl_0807df74 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #0x11]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0807df64
    b lbl_0807e100
lbl_0807df64:
    adds r1, r3, #0
    adds r1, #0x40
    movs r0, #5
    strb r0, [r1]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807df70: .4byte gSaveFilesInfo
lbl_0807df74: .4byte sNonGameplayRamPointer
lbl_0807df78:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0xa
    bhi lbl_0807df86
    b lbl_0807e3e6
lbl_0807df86:
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0807dfa0
    adds r1, #0x3a
    movs r0, #3
lbl_0807df94:
    strb r0, [r1]
lbl_0807df96:
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x22
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807dfa0:
    movs r0, #4
    bl sub_0807e6d8
    movs r0, #1
    movs r1, #0x81
    bl sub_0807e3fc
    b lbl_0807e3b6
lbl_0807dfb0:
    movs r0, #5
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807dfbc
    b lbl_0807e3e6
lbl_0807dfbc:
    ldr r2, lbl_0807dfd8 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x40
    movs r1, #0x1c
    strb r1, [r0]
    ldr r2, [r2]
    adds r0, r2, #0
    adds r0, #0x31
    ldrb r0, [r0]
    movs r1, #1
    eors r0, r1
    adds r2, #0x32
    strb r0, [r2]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807dfd8: .4byte sNonGameplayRamPointer
lbl_0807dfdc:
    movs r0, #6
    bl sub_0807e6d8
    ldr r0, lbl_0807dfe8 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807dfe8: .4byte sNonGameplayRamPointer
lbl_0807dfec:
    movs r0, #7
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807dff8
    b lbl_0807e3e6
lbl_0807dff8:
    ldr r4, lbl_0807e00c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #2
    bl sub_0807e3fc
    ldr r1, [r4]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807e00c: .4byte sNonGameplayRamPointer
lbl_0807e010:
    movs r5, #0xff
    ldr r0, lbl_0807e040 @ =gChangedInput
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0807e0c6
    movs r4, #1
    ands r4, r1
    cmp r4, #0
    beq lbl_0807e044
    movs r5, #0x80
    ldr r1, [r7]
    adds r2, r1, #0
    adds r2, #0x42
    movs r0, #0
    strh r0, [r2]
    adds r1, #0x3a
    movs r0, #4
    strb r0, [r1]
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x22
    strb r1, [r0]
    b lbl_0807e0c6
    .align 2, 0
lbl_0807e040: .4byte gChangedInput
lbl_0807e044:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807e06c
    movs r0, #8
    bl sub_0807e6d8
    movs r5, #0x81
    ldr r0, lbl_0807e068 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x42
    strh r4, [r1]
    adds r0, #0x40
    movs r1, #0x1f
    strb r1, [r0]
    b lbl_0807e0c6
    .align 2, 0
lbl_0807e068: .4byte sNonGameplayRamPointer
lbl_0807e06c:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0807e084
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x32
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807e0c6
    subs r0, #1
    b lbl_0807e0a2
lbl_0807e084:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0807e0c6
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x38
    ldrb r0, [r0]
    cmp r0, #0x13
    bne lbl_0807e0b0
    adds r1, #0x32
    ldrb r0, [r1]
    cmp r0, #1
    bhi lbl_0807e0c6
    adds r0, #1
lbl_0807e0a2:
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r0, #0
    bl FileSelectPlayMenuSound
    b lbl_0807e0c6
lbl_0807e0b0:
    adds r1, #0x32
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807e0c6
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r0, #0
    bl FileSelectPlayMenuSound
lbl_0807e0c6:
    adds r0, r5, #1
    cmp r0, #0
    bne lbl_0807e0ce
    b lbl_0807e3e6
lbl_0807e0ce:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #2
    bl sub_0807e3fc
    b lbl_0807e3e6
lbl_0807e0da:
    movs r0, #9
    bl sub_0807e6d8
    cmp r0, #0
    bne lbl_0807e0e6
    b lbl_0807e3e6
lbl_0807e0e6:
    ldr r2, lbl_0807e10c @ =gSaveFilesInfo
    ldr r0, lbl_0807e110 @ =sNonGameplayRamPointer
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807e114
lbl_0807e100:
    adds r1, r3, #0
    adds r1, #0x40
    movs r0, #8
    strb r0, [r1]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807e10c: .4byte gSaveFilesInfo
lbl_0807e110: .4byte sNonGameplayRamPointer
lbl_0807e114:
    adds r1, r3, #0
    adds r1, #0x40
    movs r0, #6
    strb r0, [r1]
    b lbl_0807e3e6
lbl_0807e11e:
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #7
    bl sub_08078504
    movs r0, #4
    bl FileSelectPlayMenuSound
    b lbl_0807e3b6
lbl_0807e132:
    ldr r0, lbl_0807e160 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    bne lbl_0807e170
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0xef
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807e154
    b lbl_0807e3e6
lbl_0807e154:
    adds r0, r2, #0
    adds r0, #0x42
    strh r3, [r0]
    adds r1, r2, #0
    b lbl_0807e3b8
    .align 2, 0
lbl_0807e160: .4byte gChangedInput
lbl_0807e164:
    ldr r0, lbl_0807e17c @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807e180
lbl_0807e170:
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x25
    strb r1, [r0]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807e17c: .4byte gChangedInput
lbl_0807e180:
    ldr r0, [r7]
    adds r0, #0x42
    ldrh r0, [r0]
    cmp r0, #0x10
    bhi lbl_0807e18c
    b lbl_0807e3e6
lbl_0807e18c:
    movs r5, #2
    b lbl_0807e3e4
lbl_0807e190:
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r1, [r0]
    movs r0, #8
    bl sub_08078504
    movs r0, #7
    bl FileSelectPlayMenuSound
    b lbl_0807e3b6
lbl_0807e1a4:
    ldr r5, [r7]
    adds r0, r5, #0
    adds r0, #0xee
    ldrb r4, [r0]
    ldr r2, lbl_0807e1e8 @ =0x08760b40
    ldr r3, lbl_0807e1ec @ =gSaveFilesInfo
    subs r0, #0xaf
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    lsls r1, r1, #3
    ldrb r0, [r0, #0xc]
    adds r1, r1, r0
    adds r2, #5
    adds r1, r1, r2
    ldrb r0, [r1]
    adds r0, #3
    cmp r4, r0
    beq lbl_0807e1d0
    b lbl_0807e3e6
lbl_0807e1d0:
    adds r0, r5, #0
    adds r0, #0x3a
    ldrb r0, [r0]
    cmp r0, #4
    bls lbl_0807e1dc
    b lbl_0807e3e6
lbl_0807e1dc:
    lsls r0, r0, #2
    ldr r1, lbl_0807e1f0 @ =lbl_0807e1f4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807e1e8: .4byte 0x08760b40
lbl_0807e1ec: .4byte gSaveFilesInfo
lbl_0807e1f0: .4byte lbl_0807e1f4
lbl_0807e1f4: @ jump table
    .4byte lbl_0807e208 @ case 0
    .4byte lbl_0807e212 @ case 1
    .4byte lbl_0807e228 @ case 2
    .4byte lbl_0807e23e @ case 3
    .4byte lbl_0807e254 @ case 4
lbl_0807e208:
    ldr r0, [r7]
lbl_0807e20a:
    adds r0, #0x40
    movs r1, #5
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807e212:
    ldr r0, [r7]
    adds r0, #0x2f
    ldrb r1, [r0]
    movs r0, #5
    bl sub_0807e3fc
    ldr r0, [r7]
lbl_0807e220:
    adds r0, #0x40
    movs r1, #0xb
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807e228:
    ldr r0, [r7]
    adds r0, #0x30
    ldrb r1, [r0]
    movs r0, #6
    bl sub_0807e3fc
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x11
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807e23e:
    ldr r0, [r7]
    adds r0, #0x31
    ldrb r1, [r0]
    movs r0, #1
    bl sub_0807e3fc
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x18
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807e254:
    ldr r0, [r7]
    adds r0, #0x32
    ldrb r1, [r0]
    movs r0, #2
    bl sub_0807e3fc
    ldr r0, [r7]
    adds r0, #0x40
    movs r1, #0x1e
    strb r1, [r0]
    b lbl_0807e3e6
lbl_0807e26a:
    ldr r1, [r7]
    ldr r0, lbl_0807e284 @ =0x00003f42
    strh r0, [r1, #2]
    movs r0, #0x97
    lsls r0, r0, #1
    adds r1, r1, r0
    movs r0, #0x23
    strb r0, [r1]
    movs r0, #6
    bl FileSelectPlayMenuSound
    b lbl_0807e3b6
    .align 2, 0
lbl_0807e284: .4byte 0x00003f42
lbl_0807e288:
    ldr r2, [r7]
    movs r1, #0x97
    lsls r1, r1, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807e298
    b lbl_0807e3e6
lbl_0807e298:
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #6
    adds r0, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldrh r0, [r2, #0x18]
    strh r0, [r2, #6]
    ldr r0, lbl_0807e2bc @ =gBG1HOFS_NonGameplay
    movs r5, #0x80
    lsls r5, r5, #4
    adds r1, r5, #0
    strh r1, [r0]
    ldr r0, lbl_0807e2c0 @ =gBG1VOFS_NonGameplay
    strh r1, [r0]
    adds r1, r2, #0
    b lbl_0807e3b8
    .align 2, 0
lbl_0807e2bc: .4byte gBG1HOFS_NonGameplay
lbl_0807e2c0: .4byte gBG1VOFS_NonGameplay
lbl_0807e2c4:
    ldr r0, [r7]
    adds r0, #0x3f
    ldrb r0, [r0]
    lsls r2, r0, #1
    adds r2, r2, r0
    lsls r2, r2, #6
    ldr r0, lbl_0807e304 @ =0x0600f000
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0xc0
    bl BitFill
    ldr r1, [r7]
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0807e2ec:
    movs r5, #0x80
    lsls r5, r5, #4
    ldr r1, lbl_0807e308 @ =gBG2VOFS_NonGameplay
    ldrh r0, [r1]
    cmp r5, r0
    beq lbl_0807e310
    subs r0, #0xc
    cmp r0, r5
    bge lbl_0807e30c

    non_word_aligned_thumb_func_start sub_0807e2fe
sub_0807e2fe: @ 0x0807e2fe
    strh r5, [r1]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807e304: .4byte 0x0600f000
lbl_0807e308: .4byte gBG2VOFS_NonGameplay
lbl_0807e30c:
    strh r0, [r1]
    b lbl_0807e3e6
lbl_0807e310:
    ldr r4, lbl_0807e340 @ =sNonGameplayRamPointer
    ldr r1, [r4]
    adds r1, #0xff
    ldrb r3, [r1]
    movs r2, #0x21
    rsbs r2, r2, #0
    adds r0, r2, #0
    ands r0, r3
    strb r0, [r1]
    ldr r0, [r4]
    ldr r1, lbl_0807e344 @ =0x0000010f
    adds r3, r0, r1
    ldrb r1, [r3]
    adds r0, r2, #0
    ands r0, r1
    strb r0, [r3]
    ldr r0, [r4]
    ldr r3, lbl_0807e348 @ =0x0000011f
    adds r1, r0, r3
    ldrb r0, [r1]
    ands r2, r0
    strb r2, [r1]
    ldr r1, [r4]
    b lbl_0807e3b8
    .align 2, 0
lbl_0807e340: .4byte sNonGameplayRamPointer
lbl_0807e344: .4byte 0x0000010f
lbl_0807e348: .4byte 0x0000011f
lbl_0807e34c:
    movs r5, #1
    ldr r1, lbl_0807e364 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_0807e36a
    movs r5, #0
    subs r0, #2
    cmp r0, #0
    bge lbl_0807e368
    strh r5, [r1]
    b lbl_0807e36a
    .align 2, 0
lbl_0807e364: .4byte gWrittenToBLDALPHA_H
lbl_0807e368:
    strh r0, [r1]
lbl_0807e36a:
    ldr r1, lbl_0807e3c4 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0x10
    beq lbl_0807e37e
    movs r5, #0
    adds r0, #2
    cmp r0, #0x10
    ble lbl_0807e37c
    movs r0, #0x10
lbl_0807e37c:
    strh r0, [r1]
lbl_0807e37e:
    cmp r5, #0
    beq lbl_0807e3e6
    ldr r1, [r7]
    ldrh r2, [r1]
    ldr r0, lbl_0807e3c8 @ =0x0000fbff
    ands r0, r2
    strh r0, [r1]
    ldr r5, lbl_0807e3cc @ =0x0000013f
    adds r3, r1, r5
    ldrb r2, [r3]
    movs r1, #0x21
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r7]
    ldr r2, lbl_0807e3d0 @ =0x0000014f
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r7]
    ldr r3, lbl_0807e3d4 @ =0x0000015f
    adds r2, r0, r3
    ldrb r0, [r2]
    ands r1, r0
    strb r1, [r2]
lbl_0807e3b6:
    ldr r1, [r7]
lbl_0807e3b8:
    adds r1, #0x40
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0807e3e6
    .align 2, 0
lbl_0807e3c4: .4byte gWrittenToBLDALPHA_L
lbl_0807e3c8: .4byte 0x0000fbff
lbl_0807e3cc: .4byte 0x0000013f
lbl_0807e3d0: .4byte 0x0000014f
lbl_0807e3d4: .4byte 0x0000015f
lbl_0807e3d8:
    ldr r2, [r7]
    ldrh r1, [r2]
    ldr r0, lbl_0807e3f8 @ =0x0000dfff
    ands r0, r1
    strh r0, [r2]
    movs r5, #1
lbl_0807e3e4:
    mov sl, r5
lbl_0807e3e6:
    mov r0, sl
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807e3f8: .4byte 0x0000dfff

    thumb_func_start sub_0807e3fc
sub_0807e3fc: @ 0x0807e3fc
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    cmp r0, #6
    bls lbl_0807e40c
    b lbl_0807e6d2
lbl_0807e40c:
    lsls r0, r0, #2
    ldr r1, lbl_0807e418 @ =lbl_0807e41c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807e418: .4byte lbl_0807e41c
lbl_0807e41c: @ jump table
    .4byte lbl_0807e438 @ case 0
    .4byte lbl_0807e4b0 @ case 1
    .4byte lbl_0807e4fc @ case 2
    .4byte lbl_0807e554 @ case 3
    .4byte lbl_0807e554 @ case 4
    .4byte lbl_0807e5a6 @ case 5
    .4byte lbl_0807e614 @ case 6
lbl_0807e438:
    cmp r4, #0x80
    bne lbl_0807e448
    ldr r0, lbl_0807e444 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xd4
    b lbl_0807e61e
    .align 2, 0
lbl_0807e444: .4byte sNonGameplayRamPointer
lbl_0807e448:
    cmp r4, #0x81
    bne lbl_0807e460
    ldr r2, lbl_0807e45c @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xde
    movs r1, #0
    strb r1, [r0]
    ldr r1, [r2]
    adds r1, #0xdf
    b lbl_0807e63e
    .align 2, 0
lbl_0807e45c: .4byte sNonGameplayRamPointer
lbl_0807e460:
    cmp r4, #0
    beq lbl_0807e466
    b lbl_0807e6d2
lbl_0807e466:
    ldr r3, lbl_0807e4ac @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    movs r4, #1
    orrs r0, r4
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xe0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r4
    strb r0, [r1]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xd6
    movs r0, #0x80
    strh r0, [r2]
    subs r2, #2
    movs r0, #0x78
    strh r0, [r2]
    adds r0, r1, #0
    adds r0, #0xde
    ldrb r0, [r0]
    cmp r0, #0x17
    bne lbl_0807e4a6
    b lbl_0807e6d2
lbl_0807e4a6:
    adds r0, r2, #0
    b lbl_0807e60c
    .align 2, 0
lbl_0807e4ac: .4byte sNonGameplayRamPointer
lbl_0807e4b0:
    cmp r4, #0x80
    bne lbl_0807e4b6
    b lbl_0807e618
lbl_0807e4b6:
    cmp r4, #0x81
    bne lbl_0807e4bc
    b lbl_0807e630
lbl_0807e4bc:
    cmp r4, #1
    bls lbl_0807e4c2
    b lbl_0807e6d2
lbl_0807e4c2:
    ldr r3, lbl_0807e4f8 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xb0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xa6
    movs r0, #0x80
    strh r0, [r2]
    adds r5, r3, #0
    cmp r4, #0
    beq lbl_0807e4f2
    b lbl_0807e5f6
lbl_0807e4f2:
    adds r1, #0xa4
    movs r0, #0x98
    b lbl_0807e5fa
    .align 2, 0
lbl_0807e4f8: .4byte sNonGameplayRamPointer
lbl_0807e4fc:
    cmp r4, #0x80
    bne lbl_0807e502
    b lbl_0807e618
lbl_0807e502:
    cmp r4, #0x81
    bne lbl_0807e508
    b lbl_0807e630
lbl_0807e508:
    cmp r4, #2
    bls lbl_0807e50e
    b lbl_0807e6d2
lbl_0807e50e:
    ldr r3, lbl_0807e544 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xb0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xa6
    movs r0, #0x80
    strh r0, [r2]
    adds r5, r3, #0
    cmp r4, #0
    bne lbl_0807e548
    adds r1, #0xa4
    movs r0, #0x98
    b lbl_0807e5fa
    .align 2, 0
lbl_0807e544: .4byte sNonGameplayRamPointer
lbl_0807e548:
    cmp r4, #1
    beq lbl_0807e5f6
    adds r1, #0xa4
    movs r0, #0x8c
    lsls r0, r0, #1
    b lbl_0807e5fa
lbl_0807e554:
    cmp r4, #0x80
    beq lbl_0807e618
    cmp r4, #0x81
    beq lbl_0807e630
    cmp r4, #1
    bls lbl_0807e562
    b lbl_0807e6d2
lbl_0807e562:
    ldr r3, lbl_0807e598 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xb0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r2, [r3]
    adds r1, r2, #0
    adds r1, #0xa4
    movs r0, #0xd8
    strh r0, [r1]
    adds r5, r3, #0
    cmp r4, #0
    bne lbl_0807e59c
    adds r1, #2
    movs r0, #0xd0
    b lbl_0807e5fa
    .align 2, 0
lbl_0807e598: .4byte sNonGameplayRamPointer
lbl_0807e59c:
    adds r1, r2, #0
    adds r1, #0xa6
    movs r0, #0xb8
    lsls r0, r0, #1
    b lbl_0807e5fa
lbl_0807e5a6:
    cmp r4, #0x80
    beq lbl_0807e618
    cmp r4, #0x81
    beq lbl_0807e630
    cmp r4, #2
    bls lbl_0807e5b4
    b lbl_0807e6d2
lbl_0807e5b4:
    ldr r3, lbl_0807e5e8 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xb0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xa6
    movs r0, #0x6c
    strh r0, [r2]
    adds r5, r3, #0
    cmp r4, #0
    bne lbl_0807e5ec
    adds r1, #0xa4
    movs r0, #0x58
    b lbl_0807e5fa
    .align 2, 0
lbl_0807e5e8: .4byte sNonGameplayRamPointer
lbl_0807e5ec:
    cmp r4, #1
    bne lbl_0807e5f6
    adds r1, #0xa4
    movs r0, #0x98
    b lbl_0807e5fa
lbl_0807e5f6:
    adds r1, #0xa4
    movs r0, #0xd8
lbl_0807e5fa:
    strh r0, [r1]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xae
    ldrb r0, [r0]
    cmp r0, #0x17
    beq lbl_0807e6d2
    adds r0, r1, #0
    adds r0, #0xa4
lbl_0807e60c:
    movs r1, #0x17
    bl UpdateMenuOamDataID
    b lbl_0807e6d2
lbl_0807e614:
    cmp r4, #0x80
    bne lbl_0807e62c
lbl_0807e618:
    ldr r0, lbl_0807e628 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xa4
lbl_0807e61e:
    movs r1, #0x18
    bl UpdateMenuOamDataID
    b lbl_0807e6d2
    .align 2, 0
lbl_0807e628: .4byte sNonGameplayRamPointer
lbl_0807e62c:
    cmp r4, #0x81
    bne lbl_0807e64c
lbl_0807e630:
    ldr r2, lbl_0807e648 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0xae
    movs r1, #0
    strb r1, [r0]
    ldr r1, [r2]
    adds r1, #0xaf
lbl_0807e63e:
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    b lbl_0807e6d2
    .align 2, 0
lbl_0807e648: .4byte sNonGameplayRamPointer
lbl_0807e64c:
    cmp r4, #1
    bhi lbl_0807e6d2
    ldr r3, lbl_0807e688 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    adds r1, #0xaf
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xb0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r2, [r3]
    adds r1, r2, #0
    adds r1, #0xa4
    movs r0, #0x8c
    lsls r0, r0, #1
    strh r0, [r1]
    adds r5, r3, #0
    cmp r4, #0
    bne lbl_0807e68c
    adds r1, #2
    movs r0, #0xb8
    b lbl_0807e694
    .align 2, 0
lbl_0807e688: .4byte sNonGameplayRamPointer
lbl_0807e68c:
    adds r1, r2, #0
    adds r1, #0xa6
    movs r0, #0xb8
    lsls r0, r0, #1
lbl_0807e694:
    strh r0, [r1]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xae
    ldrb r0, [r0]
    cmp r0, #0x17
    beq lbl_0807e6ac
    adds r0, r1, #0
    adds r0, #0xa4
    movs r1, #0x17
    bl UpdateMenuOamDataID
lbl_0807e6ac:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x7e
    ldrb r0, [r0]
    cmp r0, #0x21
    beq lbl_0807e6d2
    adds r0, r1, #0
    adds r0, #0x74
    movs r1, #0x21
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    adds r2, r1, #0
    adds r2, #0x76
    movs r0, #0x78
    strh r0, [r2]
    adds r1, #0x74
    movs r0, #0xd0
    strh r0, [r1]
lbl_0807e6d2:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_0807e6d8
sub_0807e6d8: @ 0x0807e6d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r6, #1
    cmp r0, #0x29
    bls lbl_0807e6ee
    bl lbl_0807eec8
lbl_0807e6ee:
    lsls r0, r0, #2
    ldr r1, lbl_0807e6f8 @ =lbl_0807e6fc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807e6f8: .4byte lbl_0807e6fc
lbl_0807e6fc: @ jump table
    .4byte lbl_0807e7a4 @ case 0
    .4byte lbl_0807e800 @ case 1
    .4byte lbl_0807e838 @ case 2
    .4byte lbl_0807e888 @ case 3
    .4byte lbl_0807e8b0 @ case 4
    .4byte lbl_0807eeb8 @ case 5
    .4byte lbl_0807e8cc @ case 6
    .4byte lbl_0807e910 @ case 7
    .4byte lbl_0807e96c @ case 8
    .4byte lbl_0807eeb8 @ case 9
    .4byte lbl_0807e988 @ case 10
    .4byte lbl_0807ea0c @ case 11
    .4byte lbl_0807ea44 @ case 12
    .4byte lbl_0807eb98 @ case 13
    .4byte lbl_0807ea64 @ case 14
    .4byte lbl_0807ea90 @ case 15
    .4byte lbl_0807eaa0 @ case 16
    .4byte lbl_0807ebd0 @ case 17
    .4byte lbl_0807eabc @ case 18
    .4byte lbl_0807eb40 @ case 19
    .4byte lbl_0807eb78 @ case 20
    .4byte lbl_0807eb98 @ case 21
    .4byte lbl_0807ebe4 @ case 22
    .4byte lbl_0807ec10 @ case 23
    .4byte lbl_0807ec40 @ case 24
    .4byte lbl_0807ebd0 @ case 25
    .4byte lbl_0807ec5c @ case 26
    .4byte lbl_0807ec74 @ case 27
    .4byte lbl_0807ec8c @ case 28
    .4byte lbl_0807eca4 @ case 29
    .4byte lbl_0807ecf4 @ case 30
    .4byte lbl_0807ed34 @ case 31
    .4byte lbl_0807eeb8 @ case 32
    .4byte lbl_0807eec8 @ case 33
    .4byte lbl_0807ed50 @ case 34
    .4byte lbl_0807ed78 @ case 35
    .4byte lbl_0807eeb8 @ case 36
    .4byte lbl_0807edb0 @ case 37
    .4byte lbl_0807eddc @ case 38
    .4byte lbl_0807ee6c @ case 39
    .4byte lbl_0807ee94 @ case 40
    .4byte lbl_0807eeb8 @ case 41
lbl_0807e7a4:
    ldr r0, lbl_0807e7ec @ =sNonGameplayRamPointer
    ldr r2, [r0]
    movs r0, #0x93
    lsls r0, r0, #1
    adds r1, r2, r0
    subs r0, #0x26
    strh r0, [r1]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0x80
    strh r1, [r0]
    movs r1, #0x22
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807e7f0 @ =gBG1HOFS_NonGameplay
    movs r2, #0xf8
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807e7f4 @ =gBG1VOFS_NonGameplay
    movs r3, #0xed
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_0807e7f8 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xc0
    lsls r0, r0, #6
    adds r1, r1, r0
    ldr r2, lbl_0807e7fc @ =0x0600e800
    b lbl_0807ee54
    .align 2, 0
lbl_0807e7ec: .4byte sNonGameplayRamPointer
lbl_0807e7f0: .4byte gBG1HOFS_NonGameplay
lbl_0807e7f4: .4byte gBG1VOFS_NonGameplay
lbl_0807e7f8: .4byte sEwramPointer
lbl_0807e7fc: .4byte 0x0600e800
lbl_0807e800:
    ldr r4, lbl_0807e830 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_0807e834 @ =0x0000012f
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807e814
    b lbl_0807eec6
lbl_0807e814:
    movs r0, #1
    movs r1, #0
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807e822
    b lbl_0807eec6
lbl_0807e822:
    ldr r0, [r4]
    movs r1, #0
    strh r1, [r0, #2]
    ldrh r1, [r0, #0x1c]
    strh r1, [r0, #6]
    b lbl_0807eec8
    .align 2, 0
lbl_0807e830: .4byte sNonGameplayRamPointer
lbl_0807e834: .4byte 0x0000012f
lbl_0807e838:
    ldr r0, lbl_0807e878 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0xb6
    movs r1, #0xa0
    lsls r1, r1, #1
    strh r1, [r2]
    adds r0, #0xb4
    movs r1, #0xa0
    strh r1, [r0]
    movs r1, #0x26
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807e87c @ =gBG0HOFS_NonGameplay
    movs r2, #0xe0
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807e880 @ =gBG0VOFS_NonGameplay
    movs r3, #0xe4
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_0807e884 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xe4
    lsls r0, r0, #6
    adds r1, r1, r0
    b lbl_0807ee52
    .align 2, 0
lbl_0807e878: .4byte sNonGameplayRamPointer
lbl_0807e87c: .4byte gBG0HOFS_NonGameplay
lbl_0807e880: .4byte gBG0VOFS_NonGameplay
lbl_0807e884: .4byte sEwramPointer
lbl_0807e888:
    ldr r4, lbl_0807e8ac @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r0, #0xbf
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807e89a
    b lbl_0807eec6
lbl_0807e89a:
    movs r0, #1
    movs r1, #0x11
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807e8a8
    b lbl_0807ed1a
lbl_0807e8a8:
    b lbl_0807eec6
    .align 2, 0
lbl_0807e8ac: .4byte sNonGameplayRamPointer
lbl_0807e8b0:
    ldr r0, lbl_0807e8c4 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807e8c8 @ =0x0000feff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0xbe
    movs r0, #0x27
    strb r0, [r1]
    b lbl_0807ed9e
    .align 2, 0
lbl_0807e8c4: .4byte sNonGameplayRamPointer
lbl_0807e8c8: .4byte 0x0000feff
lbl_0807e8cc:
    ldr r0, lbl_0807e904 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0xb6
    movs r1, #0xa0
    lsls r1, r1, #1
    strh r1, [r2]
    adds r0, #0xb4
    movs r1, #0xc0
    strh r1, [r0]
    movs r1, #0x24
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807e908 @ =gBG0HOFS_NonGameplay
    movs r2, #0xe0
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807e90c @ =gBG0VOFS_NonGameplay
    movs r3, #0xe4
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    b lbl_0807eec8
    .align 2, 0
lbl_0807e904: .4byte sNonGameplayRamPointer
lbl_0807e908: .4byte gBG0HOFS_NonGameplay
lbl_0807e90c: .4byte gBG0VOFS_NonGameplay
lbl_0807e910:
    ldr r0, lbl_0807e960 @ =sNonGameplayRamPointer
    mov r8, r0
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r1, [r0]
    movs r7, #0x10
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807e928
    b lbl_0807eec6
lbl_0807e928:
    adds r0, r2, #0
    adds r0, #0x38
    ldrb r1, [r0]
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807e93a
    b lbl_0807eec6
lbl_0807e93a:
    ldr r5, lbl_0807e964 @ =sEwramPointer
    ldr r0, [r5]
    movs r4, #0xf0
    lsls r4, r4, #6
    adds r0, r0, r4
    bl sub_0807eedc
    ldr r1, [r5]
    adds r1, r1, r4
    ldr r2, lbl_0807e968 @ =0x0600e000
    movs r3, #0xc0
    lsls r3, r3, #2
    str r7, [sp]
    movs r0, #3
    bl DmaTransfer
    mov r2, r8
    ldr r1, [r2]
    b lbl_0807ed1c
    .align 2, 0
lbl_0807e960: .4byte sNonGameplayRamPointer
lbl_0807e964: .4byte sEwramPointer
lbl_0807e968: .4byte 0x0600e000
lbl_0807e96c:
    ldr r0, lbl_0807e980 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807e984 @ =0x0000feff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0xbe
    movs r0, #0x25
    strb r0, [r1]
    b lbl_0807ed9e
    .align 2, 0
lbl_0807e980: .4byte sNonGameplayRamPointer
lbl_0807e984: .4byte 0x0000feff
lbl_0807e988:
    ldr r4, lbl_0807e9f4 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    movs r0, #0x93
    lsls r0, r0, #1
    adds r1, r2, r0
    adds r0, #0x1a
    strh r0, [r1]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0xa0
    strh r1, [r0]
    movs r1, #0x26
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807e9f8 @ =gBG1HOFS_NonGameplay
    movs r2, #0xd9
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807e9fc @ =gBG1VOFS_NonGameplay
    movs r3, #0xd5
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_0807ea00 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xfc
    lsls r0, r0, #6
    adds r1, r1, r0
    ldr r2, lbl_0807ea04 @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r2, [r4]
    ldrh r0, [r2, #0x1c]
    strh r0, [r2, #6]
    ldrh r1, [r2]
    ldr r0, lbl_0807ea08 @ =0x0000fdff
    ands r0, r1
    ldrh r1, [r2, #0x1a]
    strh r1, [r2, #8]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    b lbl_0807ee8a
    .align 2, 0
lbl_0807e9f4: .4byte sNonGameplayRamPointer
lbl_0807e9f8: .4byte gBG1HOFS_NonGameplay
lbl_0807e9fc: .4byte gBG1VOFS_NonGameplay
lbl_0807ea00: .4byte sEwramPointer
lbl_0807ea04: .4byte 0x0600e800
lbl_0807ea08: .4byte 0x0000fdff
lbl_0807ea0c:
    ldr r4, lbl_0807ea3c @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_0807ea40 @ =0x0000012f
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807ea20
    b lbl_0807eec6
lbl_0807ea20:
    movs r0, #1
    movs r1, #5
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807ea2e
    b lbl_0807eec6
lbl_0807ea2e:
    ldr r1, [r4]
    ldrh r0, [r1, #0x1c]
    strh r0, [r1, #6]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    b lbl_0807ed26
    .align 2, 0
lbl_0807ea3c: .4byte sNonGameplayRamPointer
lbl_0807ea40: .4byte 0x0000012f
lbl_0807ea44:
    ldr r0, lbl_0807ea5c @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807ea60 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
    movs r0, #0x97
    lsls r0, r0, #1
    adds r1, r1, r0
    movs r0, #0x27
    strb r0, [r1]
    b lbl_0807ed9e
    .align 2, 0
lbl_0807ea5c: .4byte sNonGameplayRamPointer
lbl_0807ea60: .4byte 0x0000fdff
lbl_0807ea64:
    ldr r1, lbl_0807ea84 @ =gBG0HOFS_NonGameplay
    movs r3, #0xd9
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_0807ea88 @ =gBG0VOFS_NonGameplay
    movs r2, #0xd5
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0807ea8c @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x84
    lsls r3, r3, #7
    b lbl_0807ee50
    .align 2, 0
lbl_0807ea84: .4byte gBG0HOFS_NonGameplay
lbl_0807ea88: .4byte gBG0VOFS_NonGameplay
lbl_0807ea8c: .4byte sEwramPointer
lbl_0807ea90:
    movs r0, #1
    movs r1, #6
    bl sub_080790cc
    cmp r0, #0
    beq lbl_0807ea9e
    b lbl_0807ec1e
lbl_0807ea9e:
    b lbl_0807eec6
lbl_0807eaa0:
    ldr r0, lbl_0807eab4 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    ldr r0, lbl_0807eab8 @ =0x0000feff
    ands r0, r1
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    b lbl_0807ee8a
    .align 2, 0
lbl_0807eab4: .4byte sNonGameplayRamPointer
lbl_0807eab8: .4byte 0x0000feff
lbl_0807eabc:
    ldr r4, lbl_0807eb28 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    movs r0, #0x93
    lsls r0, r0, #1
    adds r1, r2, r0
    adds r0, #0x1a
    strh r0, [r1]
    movs r1, #0x92
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #0xa0
    strh r1, [r0]
    movs r1, #0x26
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807eb2c @ =gBG1HOFS_NonGameplay
    movs r2, #0xd9
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807eb30 @ =gBG1VOFS_NonGameplay
    movs r3, #0xd5
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_0807eb34 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xfc
    lsls r0, r0, #6
    adds r1, r1, r0
    ldr r2, lbl_0807eb38 @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    ldr r2, [r4]
    ldrh r0, [r2, #0x1c]
    strh r0, [r2, #6]
    ldrh r1, [r2]
    ldr r0, lbl_0807eb3c @ =0x0000fdff
    ands r0, r1
    ldrh r1, [r2, #0x1a]
    strh r1, [r2, #8]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    b lbl_0807ee8a
    .align 2, 0
lbl_0807eb28: .4byte sNonGameplayRamPointer
lbl_0807eb2c: .4byte gBG1HOFS_NonGameplay
lbl_0807eb30: .4byte gBG1VOFS_NonGameplay
lbl_0807eb34: .4byte sEwramPointer
lbl_0807eb38: .4byte 0x0600e800
lbl_0807eb3c: .4byte 0x0000fdff
lbl_0807eb40:
    ldr r4, lbl_0807eb70 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    ldr r1, lbl_0807eb74 @ =0x0000012f
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807eb54
    b lbl_0807eec6
lbl_0807eb54:
    movs r0, #1
    movs r1, #1
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807eb62
    b lbl_0807eec6
lbl_0807eb62:
    ldr r1, [r4]
    ldrh r0, [r1, #0x1c]
    strh r0, [r1, #6]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #2
    b lbl_0807ed26
    .align 2, 0
lbl_0807eb70: .4byte sNonGameplayRamPointer
lbl_0807eb74: .4byte 0x0000012f
lbl_0807eb78:
    ldr r0, lbl_0807eb90 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807eb94 @ =0x0000fdff
    ands r0, r2
    strh r0, [r1]
    movs r0, #0x97
    lsls r0, r0, #1
    adds r1, r1, r0
    movs r0, #0x27
    strb r0, [r1]
    b lbl_0807ed9e
    .align 2, 0
lbl_0807eb90: .4byte sNonGameplayRamPointer
lbl_0807eb94: .4byte 0x0000fdff
lbl_0807eb98:
    ldr r0, lbl_0807ebd4 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    movs r1, #0x97
    lsls r1, r1, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807ebaa
    b lbl_0807eec6
lbl_0807ebaa:
    ldrh r0, [r2, #0x18]
    strh r0, [r2, #6]
    ldrh r0, [r2, #0x16]
    strh r0, [r2, #8]
    ldrh r1, [r2]
    ldr r0, lbl_0807ebd8 @ =0x0000fbff
    ands r0, r1
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_0807ebdc @ =gBG1HOFS_NonGameplay
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r2, #0
    strh r1, [r0]
    ldr r0, lbl_0807ebe0 @ =gBG1VOFS_NonGameplay
    strh r1, [r0]
lbl_0807ebd0:
    movs r6, #1
    b lbl_0807eec8
    .align 2, 0
lbl_0807ebd4: .4byte sNonGameplayRamPointer
lbl_0807ebd8: .4byte 0x0000fbff
lbl_0807ebdc: .4byte gBG1HOFS_NonGameplay
lbl_0807ebe0: .4byte gBG1VOFS_NonGameplay
lbl_0807ebe4:
    ldr r1, lbl_0807ec04 @ =gBG0HOFS_NonGameplay
    movs r3, #0xd9
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_0807ec08 @ =gBG0VOFS_NonGameplay
    movs r2, #0xd5
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0807ec0c @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x84
    lsls r3, r3, #7
    b lbl_0807ee50
    .align 2, 0
lbl_0807ec04: .4byte gBG0HOFS_NonGameplay
lbl_0807ec08: .4byte gBG0VOFS_NonGameplay
lbl_0807ec0c: .4byte sEwramPointer
lbl_0807ec10:
    movs r0, #1
    movs r1, #3
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807ec1e
    b lbl_0807eec6
lbl_0807ec1e:
    ldr r0, lbl_0807ec38 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r0, [r2, #0x1e]
    strh r0, [r2, #4]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r1
    ldr r1, lbl_0807ec3c @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
    b lbl_0807eec8
    .align 2, 0
lbl_0807ec38: .4byte sNonGameplayRamPointer
lbl_0807ec3c: .4byte 0x0000fdff
lbl_0807ec40:
    ldr r0, lbl_0807ec54 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    ldrh r1, [r2]
    ldr r0, lbl_0807ec58 @ =0x0000feff
    ands r0, r1
    movs r3, #0x80
    lsls r3, r3, #2
    adds r1, r3, #0
    b lbl_0807ee8a
    .align 2, 0
lbl_0807ec54: .4byte sNonGameplayRamPointer
lbl_0807ec58: .4byte 0x0000feff
lbl_0807ec5c:
    ldr r0, lbl_0807ec6c @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xfc
    lsls r0, r0, #6
    adds r1, r1, r0
    ldr r2, lbl_0807ec70 @ =0x0600e800
    b lbl_0807ee54
    .align 2, 0
lbl_0807ec6c: .4byte sEwramPointer
lbl_0807ec70: .4byte 0x0600e800
lbl_0807ec74:
    ldr r0, lbl_0807ec84 @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0x8a
    lsls r2, r2, #7
    adds r1, r1, r2
    ldr r2, lbl_0807ec88 @ =0x0600e800
    b lbl_0807ee54
    .align 2, 0
lbl_0807ec84: .4byte sEwramPointer
lbl_0807ec88: .4byte 0x0600e800
lbl_0807ec8c:
    ldr r0, lbl_0807ec9c @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0x84
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0807eca0 @ =0x0600e800
    b lbl_0807ee54
    .align 2, 0
lbl_0807ec9c: .4byte sEwramPointer
lbl_0807eca0: .4byte 0x0600e800
lbl_0807eca4:
    ldr r0, lbl_0807ece4 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r2, r0, #0
    adds r2, #0xb6
    movs r1, #0xa0
    lsls r1, r1, #1
    strh r1, [r2]
    adds r0, #0xb4
    movs r1, #0xc0
    strh r1, [r0]
    movs r1, #0x24
    bl UpdateMenuOamDataID
    movs r0, #5
    bl FileSelectPlayMenuSound
    ldr r1, lbl_0807ece8 @ =gBG0HOFS_NonGameplay
    movs r2, #0xe0
    lsls r2, r2, #3
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0807ecec @ =gBG0VOFS_NonGameplay
    movs r3, #0xe4
    lsls r3, r3, #3
    adds r0, r3, #0
    strh r0, [r1]
    ldr r0, lbl_0807ecf0 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xcc
    lsls r0, r0, #6
    adds r1, r1, r0
    b lbl_0807ee52
    .align 2, 0
lbl_0807ece4: .4byte sNonGameplayRamPointer
lbl_0807ece8: .4byte gBG0HOFS_NonGameplay
lbl_0807ecec: .4byte gBG0VOFS_NonGameplay
lbl_0807ecf0: .4byte sEwramPointer
lbl_0807ecf4:
    ldr r4, lbl_0807ed30 @ =sNonGameplayRamPointer
    ldr r2, [r4]
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_0807ed08
    b lbl_0807eec6
lbl_0807ed08:
    adds r0, r2, #0
    adds r0, #0x39
    ldrb r1, [r0]
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807ed1a
    b lbl_0807eec6
lbl_0807ed1a:
    ldr r1, [r4]
lbl_0807ed1c:
    ldrh r0, [r1, #0x1e]
    strh r0, [r1, #4]
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
lbl_0807ed26:
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    b lbl_0807eec8
    .align 2, 0
lbl_0807ed30: .4byte sNonGameplayRamPointer
lbl_0807ed34:
    ldr r0, lbl_0807ed48 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807ed4c @ =0x0000feff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0xbe
    movs r0, #0x25
    strb r0, [r1]
    b lbl_0807ed9e
    .align 2, 0
lbl_0807ed48: .4byte sNonGameplayRamPointer
lbl_0807ed4c: .4byte 0x0000feff
lbl_0807ed50:
    ldr r0, lbl_0807ed70 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x39
    ldrb r1, [r0]
    movs r0, #1
    bl sub_080790cc
    cmp r0, #0
    bne lbl_0807ed64
    b lbl_0807eec6
lbl_0807ed64:
    ldr r0, lbl_0807ed74 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0xd8
    lsls r0, r0, #6
    adds r1, r1, r0
    b lbl_0807ee52
    .align 2, 0
lbl_0807ed70: .4byte sNonGameplayRamPointer
lbl_0807ed74: .4byte sEwramPointer
lbl_0807ed78:
    ldr r3, lbl_0807eda8 @ =sNonGameplayRamPointer
    ldr r1, [r3]
    ldrh r2, [r1]
    ldr r0, lbl_0807edac @ =0x0000feff
    ands r0, r2
    movs r2, #0
    strh r0, [r1]
    adds r1, #0x7e
    strb r2, [r1]
    ldr r1, [r3]
    adds r1, #0x7f
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r3]
    adds r0, #0xbe
    movs r1, #0x25
    strb r1, [r0]
lbl_0807ed9e:
    movs r0, #6
    bl FileSelectPlayMenuSound
    b lbl_0807eec8
    .align 2, 0
lbl_0807eda8: .4byte sNonGameplayRamPointer
lbl_0807edac: .4byte 0x0000feff
lbl_0807edb0:
    ldr r2, lbl_0807edd4 @ =sNonGameplayRamPointer
    ldr r0, [r2]
    adds r0, #0x7e
    movs r1, #0
    strb r1, [r0]
    ldr r1, [r2]
    adds r1, #0x7f
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    ldr r0, lbl_0807edd8 @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0xcc
    lsls r2, r2, #6
    adds r1, r1, r2
    b lbl_0807ee52
    .align 2, 0
lbl_0807edd4: .4byte sNonGameplayRamPointer
lbl_0807edd8: .4byte sEwramPointer
lbl_0807eddc:
    ldr r0, lbl_0807ee20 @ =0x000001fd
    bl SoundPlay
    ldr r4, lbl_0807ee24 @ =sNonGameplayRamPointer
    ldr r0, [r4]
    adds r2, r0, #0
    adds r2, #0xb6
    movs r1, #0xa0
    lsls r1, r1, #1
    strh r1, [r2]
    adds r0, #0xb4
    movs r1, #0xa0
    strh r1, [r0]
    movs r1, #0x26
    bl UpdateMenuOamDataID
    ldr r0, lbl_0807ee28 @ =gBG0HOFS_NonGameplay
    movs r3, #0xec
    lsls r3, r3, #3
    adds r1, r3, #0
    strh r1, [r0]
    ldr r0, lbl_0807ee2c @ =gBG0VOFS_NonGameplay
    strh r1, [r0]
    ldr r0, [r4]
    adds r0, #0x47
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0807ee34
    ldr r0, lbl_0807ee30 @ =sEwramPointer
    ldr r1, [r0]
    movs r0, #0x84
    lsls r0, r0, #7
    adds r1, r1, r0
    b lbl_0807ee52
    .align 2, 0
lbl_0807ee20: .4byte 0x000001fd
lbl_0807ee24: .4byte sNonGameplayRamPointer
lbl_0807ee28: .4byte gBG0HOFS_NonGameplay
lbl_0807ee2c: .4byte gBG0VOFS_NonGameplay
lbl_0807ee30: .4byte sEwramPointer
lbl_0807ee34:
    cmp r0, #2
    bne lbl_0807ee48
    ldr r0, lbl_0807ee44 @ =sEwramPointer
    ldr r1, [r0]
    movs r2, #0x8a
    lsls r2, r2, #7
    adds r1, r1, r2
    b lbl_0807ee52
    .align 2, 0
lbl_0807ee44: .4byte sEwramPointer
lbl_0807ee48:
    ldr r0, lbl_0807ee64 @ =sEwramPointer
    ldr r1, [r0]
    movs r3, #0xfc
    lsls r3, r3, #6
lbl_0807ee50:
    adds r1, r1, r3
lbl_0807ee52:
    ldr r2, lbl_0807ee68 @ =0x0600e000
lbl_0807ee54:
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DmaTransfer
    b lbl_0807eec8
    .align 2, 0
lbl_0807ee64: .4byte sEwramPointer
lbl_0807ee68: .4byte 0x0600e000
lbl_0807ee6c:
    ldr r0, lbl_0807ee90 @ =sNonGameplayRamPointer
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0xbf
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0807eec6
    ldrh r0, [r2, #0x1e]
    strh r0, [r2, #4]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
lbl_0807ee8a:
    orrs r0, r1
    strh r0, [r2]
    b lbl_0807eec8
    .align 2, 0
lbl_0807ee90: .4byte sNonGameplayRamPointer
lbl_0807ee94:
    movs r0, #0xff
    lsls r0, r0, #1
    bl SoundPlay
    ldr r0, lbl_0807eeb0 @ =sNonGameplayRamPointer
    ldr r1, [r0]
    ldrh r2, [r1]
    ldr r0, lbl_0807eeb4 @ =0x0000feff
    ands r0, r2
    strh r0, [r1]
    adds r1, #0xbe
    movs r0, #0x27
    strb r0, [r1]
    b lbl_0807eec8
    .align 2, 0
lbl_0807eeb0: .4byte sNonGameplayRamPointer
lbl_0807eeb4: .4byte 0x0000feff
lbl_0807eeb8:
    ldr r0, lbl_0807eed8 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0xbe
    ldrb r0, [r0]
    movs r6, #1
    cmp r0, #0
    beq lbl_0807eec8
lbl_0807eec6:
    movs r6, #0
lbl_0807eec8:
    adds r0, r6, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807eed8: .4byte sNonGameplayRamPointer

    thumb_func_start sub_0807eedc
sub_0807eedc: @ 0x0807eedc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    mov ip, r0
    ldr r2, lbl_0807ef70 @ =gSaveFilesInfo
    ldr r0, lbl_0807ef74 @ =sNonGameplayRamPointer
    ldr r0, [r0]
    adds r0, #0x3f
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r0, #0x11]
    movs r2, #7
    mov r8, r2
    ands r2, r1
    ldrb r0, [r0, #0x11]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x13
    movs r1, #7
    ands r0, r1
    orrs r2, r0
    mov r8, r2
    movs r0, #0x80
    lsls r0, r0, #1
    add ip, r0
    movs r2, #0
lbl_0807ef18:
    mov r1, r8
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    movs r0, #0xf0
    lsls r0, r0, #8
    cmp r1, #0
    beq lbl_0807ef2c
    movs r0, #0xe0
    lsls r0, r0, #8
lbl_0807ef2c:
    adds r5, r0, #0
    adds r7, r2, #1
    ldr r6, lbl_0807ef78 @ =0x000003ff
    lsls r1, r2, #7
    mov r2, ip
    adds r0, r2, r1
    adds r3, r0, #0
    adds r3, #0x44
    add r1, ip
    adds r2, r1, #4
    movs r4, #0xf
lbl_0807ef42:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    ldrh r1, [r3]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0807ef42
    adds r2, r7, #0
    cmp r2, #2
    ble lbl_0807ef18
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807ef70: .4byte gSaveFilesInfo
lbl_0807ef74: .4byte sNonGameplayRamPointer
lbl_0807ef78: .4byte 0x000003ff

    thumb_func_start FileSelectPlayMenuSound
FileSelectPlayMenuSound: @ 0x0807ef7c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0xc
    bhi lbl_0807ef92
    ldr r0, lbl_0807ef98 @ =0x08760c4c
    lsls r1, r1, #1
    adds r1, r1, r0
    ldrh r0, [r1]
    bl SoundPlay
lbl_0807ef92:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807ef98: .4byte 0x08760c4c


