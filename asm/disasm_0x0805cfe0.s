    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start SetBGHazeEffect
SetBGHazeEffect: @ 0x0805cfe0
    push {r4, r5, lr}
    bl reset_haze_loops
    ldr r5, lbl_0805d024 @ =0x0300006b
    ldr r4, lbl_0805d028 @ =0x0875fd88
    ldr r3, lbl_0805d02c @ =0x030000bc
    ldrb r0, [r3, #0x10]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0]
    strb r0, [r5]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805d016
    ldrb r0, [r3, #0x10]
    lsls r0, r0, #2
    adds r1, r4, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r3, #0x14]
    ldr r2, lbl_0805d030 @ =0x0300551c
    ldrb r0, [r3, #0x10]
    lsls r0, r0, #2
    adds r1, r4, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r2]
lbl_0805d016:
    ldrb r0, [r5]
    bl SetupHazeCode
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d024: .4byte 0x0300006b
lbl_0805d028: .4byte 0x0875fd88
lbl_0805d02c: .4byte 0x030000bc
lbl_0805d030: .4byte 0x0300551c

    thumb_func_start sub_0805d034
sub_0805d034: @ 0x0805d034
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r6, lbl_0805d088 @ =0x03000080
    ldrb r7, [r6, #7]
    movs r0, #0x80
    ands r0, r7
    cmp r0, #0
    beq lbl_0805d07e
    ldr r2, lbl_0805d08c @ =0x040000b0
    ldr r5, lbl_0805d090 @ =0x02026300
    str r5, [r2]
    ldr r4, [r6]
    str r4, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    ldr r1, lbl_0805d094 @ =0x80600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r3, sp
    ldr r0, lbl_0805d098 @ =0x08345ff8
    ldrb r1, [r0]
    strb r1, [r3]
    mov r0, sp
    strb r1, [r0]
    str r5, [r2]
    str r4, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    movs r1, #0xc0
    lsls r1, r1, #0xf
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    movs r0, #0x7f
    ands r0, r7
    strb r0, [r6, #7]
lbl_0805d07e:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d088: .4byte 0x03000080
lbl_0805d08c: .4byte 0x040000b0
lbl_0805d090: .4byte 0x02026300
lbl_0805d094: .4byte 0x80600000
lbl_0805d098: .4byte 0x08345ff8

    thumb_func_start unk_5d09c
unk_5d09c: @ 0x0805d09c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r6, lbl_0805d0fc @ =0x03000080
    ldrb r7, [r6, #7]
    movs r0, #0x80
    ands r0, r7
    cmp r0, #0
    beq lbl_0805d0f4
    ldr r2, lbl_0805d100 @ =0x040000b0
    ldr r5, lbl_0805d104 @ =0x02026300
    str r5, [r2]
    ldr r4, [r6]
    str r4, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    ldr r1, lbl_0805d108 @ =0x80600000
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r3, sp
    ldr r0, lbl_0805d10c @ =0x08345ff8
    ldrb r1, [r0]
    strb r1, [r3]
    mov r0, sp
    strb r1, [r0]
    str r5, [r2]
    str r4, [r2, #4]
    ldrb r0, [r6, #6]
    lsrs r0, r0, #1
    movs r1, #0xc0
    lsls r1, r1, #0xf
    orrs r0, r1
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    movs r0, #0x7f
    ands r0, r7
    strb r0, [r6, #7]
    movs r1, #0
    movs r0, #2
    strb r0, [r6, #6]
    ldr r0, lbl_0805d110 @ =0x02026d00
    str r0, [r6]
    ldr r0, lbl_0805d114 @ =0x0300006b
    strb r1, [r0]
lbl_0805d0f4:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d0fc: .4byte 0x03000080
lbl_0805d100: .4byte 0x040000b0
lbl_0805d104: .4byte 0x02026300
lbl_0805d108: .4byte 0x80600000
lbl_0805d10c: .4byte 0x08345ff8
lbl_0805d110: .4byte 0x02026d00
lbl_0805d114: .4byte 0x0300006b

    thumb_func_start SetupHazeCode
SetupHazeCode: @ 0x0805d118
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0805d144 @ =0x0300006b
    strb r0, [r4]
    ldr r2, lbl_0805d148 @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x80
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2, #7]
    bl sub_0805d034
    ldrb r0, [r4]
    subs r0, #1
    cmp r0, #9
    bls lbl_0805d13a
    b lbl_0805d3ca
lbl_0805d13a:
    lsls r0, r0, #2
    ldr r1, lbl_0805d14c @ =lbl_0805d150
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805d144: .4byte 0x0300006b
lbl_0805d148: .4byte 0x03000080
lbl_0805d14c: .4byte lbl_0805d150
lbl_0805d150: @ jump table
    .4byte lbl_0805d178 @ case 0
    .4byte lbl_0805d1a4 @ case 1
    .4byte lbl_0805d1ac @ case 2
    .4byte lbl_0805d1b4 @ case 3
    .4byte lbl_0805d204 @ case 4
    .4byte lbl_0805d254 @ case 5
    .4byte lbl_0805d2a4 @ case 6
    .4byte lbl_0805d378 @ case 7
    .4byte lbl_0805d3c4 @ case 8
    .4byte lbl_0805d3c4 @ case 9
lbl_0805d178:
    bl gradient_related
    ldr r2, lbl_0805d1a0 @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x80
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #7]
    movs r0, #2
    strb r0, [r2, #6]
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r2, #4]
    movs r0, #0xa0
    lsls r0, r0, #0x13
    str r0, [r2]
    b lbl_0805d3ca
    .align 2, 0
lbl_0805d1a0: .4byte 0x03000080
lbl_0805d1a4:
    ldr r1, lbl_0805d1a8 @ =haze_bg3
    b lbl_0805d1b6
    .align 2, 0
lbl_0805d1a8: .4byte haze_bg3
lbl_0805d1ac:
    ldr r1, lbl_0805d1b0 @ =haze_bg3_strong_effect_weak_outside
    b lbl_0805d1b6
    .align 2, 0
lbl_0805d1b0: .4byte haze_bg3_strong_effect_weak_outside
lbl_0805d1b4:
    ldr r1, lbl_0805d1f0 @ =haze_bg3_none_effect_weak_outside
lbl_0805d1b6:
    ldr r4, lbl_0805d1f4 @ =0x03001944
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805d1f8 @ =0x0300572c
    adds r4, #1
    str r4, [r0]
    ldr r2, lbl_0805d1fc @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x80
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #7]
    movs r0, #2
    strb r0, [r2, #6]
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r2, #4]
    ldr r0, lbl_0805d200 @ =0x0400001c
    str r0, [r2]
    b lbl_0805d3ca
    .align 2, 0
lbl_0805d1f0: .4byte haze_bg3_none_effect_weak_outside
lbl_0805d1f4: .4byte 0x03001944
lbl_0805d1f8: .4byte 0x0300572c
lbl_0805d1fc: .4byte 0x03000080
lbl_0805d200: .4byte 0x0400001c
lbl_0805d204:
    ldr r1, lbl_0805d240 @ =haze_bg3_bg2_strong_effect_weak_outside_medium_everywhere
    ldr r4, lbl_0805d244 @ =0x03001944
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805d248 @ =0x0300572c
    adds r4, #1
    str r4, [r0]
    ldr r2, lbl_0805d24c @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x80
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #7]
    movs r0, #8
    strb r0, [r2, #6]
    movs r0, #0xa0
    lsls r0, r0, #3
    strh r0, [r2, #4]
    ldr r0, lbl_0805d250 @ =0x04000018
    str r0, [r2]
    b lbl_0805d3ca
    .align 2, 0
lbl_0805d240: .4byte haze_bg3_bg2_strong_effect_weak_outside_medium_everywhere
lbl_0805d244: .4byte 0x03001944
lbl_0805d248: .4byte 0x0300572c
lbl_0805d24c: .4byte 0x03000080
lbl_0805d250: .4byte 0x04000018
lbl_0805d254:
    ldr r1, lbl_0805d290 @ =sub_0805da40
    ldr r4, lbl_0805d294 @ =0x03001944
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805d298 @ =0x0300572c
    adds r4, #1
    str r4, [r0]
    ldr r2, lbl_0805d29c @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x80
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #7]
    movs r0, #0xc
    strb r0, [r2, #6]
    movs r0, #0xf0
    lsls r0, r0, #3
    strh r0, [r2, #4]
    ldr r0, lbl_0805d2a0 @ =0x04000014
    str r0, [r2]
    b lbl_0805d3ca
    .align 2, 0
lbl_0805d290: .4byte sub_0805da40
lbl_0805d294: .4byte 0x03001944
lbl_0805d298: .4byte 0x0300572c
lbl_0805d29c: .4byte 0x03000080
lbl_0805d2a0: .4byte 0x04000014
lbl_0805d2a4:
    ldr r1, lbl_0805d338 @ =0x0300000e
    movs r0, #0x1f
    strb r0, [r1]
    ldr r1, lbl_0805d33c @ =0x0300000f
    movs r0, #0x37
    strb r0, [r1]
    ldr r1, lbl_0805d340 @ =0x0300544c
    movs r0, #0xcf
    strh r0, [r1]
    ldr r1, lbl_0805d344 @ =0x04000054
    movs r0, #0xc
    strh r0, [r1]
    ldr r1, lbl_0805d348 @ =0x0300544a
    movs r0, #0xa0
    strh r0, [r1]
    ldr r1, lbl_0805d34c @ =0x03005448
    movs r0, #0
    strh r0, [r1]
    movs r0, #0
    bl power_bomb_yellow_tint
    ldr r0, lbl_0805d350 @ =0x03000088
    ldrh r1, [r0]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0805d2f4
    ldr r0, lbl_0805d354 @ =0x030000bc
    ldrb r0, [r0, #1]
    cmp r0, #0x12
    beq lbl_0805d2f4
    ldr r2, lbl_0805d358 @ =0x0300000a
    movs r0, #0x80
    lsls r0, r0, #0x13
    ldrh r1, [r0]
    adds r0, r3, #0
    eors r0, r1
    strh r0, [r2]
lbl_0805d2f4:
    ldr r1, lbl_0805d35c @ =0x03000010
    ldr r2, lbl_0805d360 @ =0x00007fff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0805d364 @ =haze_power_bomb_expanding
    ldr r4, lbl_0805d368 @ =0x03001944
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805d36c @ =0x0300572c
    adds r4, #1
    str r4, [r0]
    ldr r2, lbl_0805d370 @ =0x03000080
    ldrb r0, [r2, #7]
    movs r1, #0x80
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    strb r1, [r2, #7]
    movs r0, #2
    strb r0, [r2, #6]
    movs r0, #0xa0
    lsls r0, r0, #1
    strh r0, [r2, #4]
    ldr r0, lbl_0805d374 @ =0x04000042
    str r0, [r2]
    b lbl_0805d3a2
    .align 2, 0
lbl_0805d338: .4byte 0x0300000e
lbl_0805d33c: .4byte 0x0300000f
lbl_0805d340: .4byte 0x0300544c
lbl_0805d344: .4byte 0x04000054
lbl_0805d348: .4byte 0x0300544a
lbl_0805d34c: .4byte 0x03005448
lbl_0805d350: .4byte 0x03000088
lbl_0805d354: .4byte 0x030000bc
lbl_0805d358: .4byte 0x0300000a
lbl_0805d35c: .4byte 0x03000010
lbl_0805d360: .4byte 0x00007fff
lbl_0805d364: .4byte haze_power_bomb_expanding
lbl_0805d368: .4byte 0x03001944
lbl_0805d36c: .4byte 0x0300572c
lbl_0805d370: .4byte 0x03000080
lbl_0805d374: .4byte 0x04000042
lbl_0805d378:
    ldr r1, lbl_0805d3b4 @ =haze_power_bomb_retracting
    ldr r4, lbl_0805d3b8 @ =0x03001944
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805d3bc @ =0x0300572c
    adds r4, #1
    str r4, [r0]
    ldr r2, lbl_0805d3c0 @ =0x03000080
    ldrb r0, [r2, #7]
    movs r1, #0x80
    rsbs r1, r1, #0
    ands r1, r0
    movs r0, #1
    orrs r1, r0
    strb r1, [r2, #7]
lbl_0805d3a2:
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0805d3ca
    movs r0, #0x80
    orrs r1, r0
    strb r1, [r2, #7]
    b lbl_0805d3ca
    .align 2, 0
lbl_0805d3b4: .4byte haze_power_bomb_retracting
lbl_0805d3b8: .4byte 0x03001944
lbl_0805d3bc: .4byte 0x0300572c
lbl_0805d3c0: .4byte 0x03000080
lbl_0805d3c4:
    ldr r1, lbl_0805d3d4 @ =0x0300006b
    movs r0, #0
    strb r0, [r1]
lbl_0805d3ca:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d3d4: .4byte 0x0300006b

    thumb_func_start reset_haze_loops
reset_haze_loops: @ 0x0805d3d8
    push {lr}
    ldr r0, lbl_0805d400 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805d3f2
    ldr r1, lbl_0805d404 @ =0x0300571c
    ldr r0, lbl_0805d408 @ =0x0835f944
    ldr r0, [r0]
    str r0, [r1]
    str r0, [r1, #4]
    str r0, [r1, #8]
lbl_0805d3f2:
    ldr r0, lbl_0805d40c @ =0x03005728
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_0805d410 @ =0x03005729
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d400: .4byte 0x03000bf0
lbl_0805d404: .4byte 0x0300571c
lbl_0805d408: .4byte 0x0835f944
lbl_0805d40c: .4byte 0x03005728
lbl_0805d410: .4byte 0x03005729

    thumb_func_start gradient_related
gradient_related: @ 0x0805d414
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x28
    ldr r0, lbl_0805d434 @ =0x02026d00
    str r0, [sp]
    movs r3, #0
lbl_0805d426:
    movs r7, #0
    cmp r3, #4
    bgt lbl_0805d43c
    ldr r1, lbl_0805d438 @ =0x050001c0
    ldrh r7, [r1]
    b lbl_0805d444
    .align 2, 0
lbl_0805d434: .4byte 0x02026d00
lbl_0805d438: .4byte 0x050001c0
lbl_0805d43c:
    cmp r3, #0x9a
    ble lbl_0805d444
    ldr r1, lbl_0805d5b8 @ =0x050001c0
    ldrh r7, [r1, #0x1e]
lbl_0805d444:
    strh r7, [r0]
    adds r0, #2
    adds r3, #1
    cmp r3, #0x9f
    ble lbl_0805d426
    ldr r0, [sp]
    adds r0, #0xa
    str r0, [sp]
    movs r3, #0
lbl_0805d456:
    lsls r2, r3, #1
    ldr r1, lbl_0805d5b8 @ =0x050001c0
    adds r2, r2, r1
    ldrh r1, [r2]
    movs r6, #0x1f
    ands r6, r1
    movs r5, #0xf8
    lsls r5, r5, #2
    ands r5, r1
    lsrs r5, r5, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r0, r0, #0xa
    str r0, [sp, #4]
    ldrh r1, [r2, #2]
    movs r4, #0x1f
    ands r4, r1
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r0, r0, #5
    mov sl, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r0, r0, #0xa
    mov r8, r0
    subs r4, r4, r6
    mov r0, sl
    subs r0, r0, r5
    mov sl, r0
    mov r1, r8
    ldr r0, [sp, #4]
    subs r1, r1, r0
    mov r8, r1
    movs r7, #0
    adds r3, #1
    str r3, [sp, #0x18]
    adds r0, r4, #0
    movs r1, #0xa
    bl __divsi3
    str r0, [sp, #8]
    adds r0, r4, #0
    movs r1, #0xa
    bl __modsi3
    str r0, [sp, #0xc]
    movs r1, #0
    str r1, [sp, #0x1c]
    lsls r6, r6, #0x18
    str r6, [sp, #0x20]
    adds r0, r4, #0
    movs r1, #0x64
    bl __modsi3
    str r0, [sp, #0x10]
    mov r0, sl
    movs r1, #0xa
    bl __divsi3
    str r0, [sp, #0x14]
    lsls r5, r5, #0x18
    mov sb, r5
    movs r0, #0
    str r0, [sp, #0x24]
lbl_0805d4dc:
    ldr r1, [sp, #0x20]
    lsrs r6, r1, #0x18
    ldr r0, [sp, #0x1c]
    movs r1, #0xa
    bl __divsi3
    adds r6, r6, r0
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    ldr r0, [sp, #0x24]
    movs r1, #0x64
    bl __divsi3
    adds r6, r6, r0
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    mov r0, sb
    lsrs r5, r0, #0x18
    mov r0, sl
    movs r1, #0xa
    bl __modsi3
    muls r0, r7, r0
    movs r1, #0xa
    bl __divsi3
    adds r5, r5, r0
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    mov r0, sl
    movs r1, #0x64
    bl __modsi3
    muls r0, r7, r0
    movs r1, #0x64
    bl __divsi3
    adds r5, r5, r0
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    mov r0, r8
    movs r1, #0xa
    bl __divsi3
    adds r4, r7, #0
    muls r4, r0, r4
    ldr r1, [sp, #4]
    adds r4, r1, r4
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    mov r0, r8
    movs r1, #0xa
    bl __modsi3
    muls r0, r7, r0
    movs r1, #0xa
    bl __divsi3
    adds r4, r4, r0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    mov r0, r8
    movs r1, #0x64
    bl __modsi3
    muls r0, r7, r0
    movs r1, #0x64
    bl __divsi3
    adds r4, r4, r0
    lsls r4, r4, #0x18
    lsls r5, r5, #5
    orrs r6, r5
    lsrs r4, r4, #0xe
    orrs r6, r4
    ldr r0, [sp]
    strh r6, [r0]
    adds r0, #2
    str r0, [sp]
    ldr r1, [sp, #0x1c]
    ldr r0, [sp, #0xc]
    adds r1, r1, r0
    str r1, [sp, #0x1c]
    ldr r1, [sp, #8]
    lsls r0, r1, #0x18
    ldr r1, [sp, #0x20]
    adds r1, r1, r0
    str r1, [sp, #0x20]
    ldr r1, [sp, #0x14]
    lsls r0, r1, #0x18
    add sb, r0
    ldr r0, [sp, #0x24]
    ldr r1, [sp, #0x10]
    adds r0, r0, r1
    str r0, [sp, #0x24]
    adds r7, #1
    cmp r7, #9
    ble lbl_0805d4dc
    ldr r3, [sp, #0x18]
    cmp r3, #0xe
    bgt lbl_0805d5a8
    b lbl_0805d456
lbl_0805d5a8:
    add sp, #0x28
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d5b8: .4byte 0x050001c0

    thumb_func_start ProcessHaze
ProcessHaze: @ 0x0805d5bc
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_0805d5d4 @ =0x0300006b
    ldrb r0, [r0]
    cmp r0, #8
    bls lbl_0805d5ca
    b lbl_0805d748
lbl_0805d5ca:
    lsls r0, r0, #2
    ldr r1, lbl_0805d5d8 @ =lbl_0805d5dc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805d5d4: .4byte 0x0300006b
lbl_0805d5d8: .4byte lbl_0805d5dc
lbl_0805d5dc: @ jump table
    .4byte lbl_0805d748 @ case 0
    .4byte lbl_0805d748 @ case 1
    .4byte lbl_0805d600 @ case 2
    .4byte lbl_0805d600 @ case 3
    .4byte lbl_0805d600 @ case 4
    .4byte lbl_0805d600 @ case 5
    .4byte lbl_0805d744 @ case 6
    .4byte lbl_0805d610 @ case 7
    .4byte lbl_0805d6b8 @ case 8
lbl_0805d600:
    ldr r0, lbl_0805d60c @ =0x0300572c
    ldr r0, [r0]
    bl _call_via_r0
    b lbl_0805d748
    .align 2, 0
lbl_0805d60c: .4byte 0x0300572c
lbl_0805d610:
    ldr r0, lbl_0805d648 @ =0x0300572c
    ldr r0, [r0]
    bl _call_via_r0
    cmp r0, #0
    bne lbl_0805d61e
    b lbl_0805d748
lbl_0805d61e:
    ldr r1, lbl_0805d64c @ =0x0300006b
    movs r0, #8
    strb r0, [r1]
    movs r0, #8
    bl SetupHazeCode
    ldr r1, lbl_0805d650 @ =0x03000130
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0805d654 @ =0x030056f4
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805d668
    ldr r1, lbl_0805d658 @ =0x040000d4
    ldr r0, lbl_0805d65c @ =0x02009000
    str r0, [r1]
    ldr r0, lbl_0805d660 @ =0x02035000
    str r0, [r1, #4]
    ldr r0, lbl_0805d664 @ =0x80000100
    b lbl_0805d674
    .align 2, 0
lbl_0805d648: .4byte 0x0300572c
lbl_0805d64c: .4byte 0x0300006b
lbl_0805d650: .4byte 0x03000130
lbl_0805d654: .4byte 0x030056f4
lbl_0805d658: .4byte 0x040000d4
lbl_0805d65c: .4byte 0x02009000
lbl_0805d660: .4byte 0x02035000
lbl_0805d664: .4byte 0x80000100
lbl_0805d668:
    ldr r1, lbl_0805d698 @ =0x040000d4
    ldr r0, lbl_0805d69c @ =0x02009000
    str r0, [r1]
    ldr r0, lbl_0805d6a0 @ =0x02035000
    str r0, [r1, #4]
    ldr r0, lbl_0805d6a4 @ =0x800000f0
lbl_0805d674:
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r2, lbl_0805d6a8 @ =0x03005520
    ldrb r1, [r2, #4]
    movs r0, #1
    movs r3, #0
    orrs r0, r1
    strb r0, [r2, #4]
    ldr r1, lbl_0805d6ac @ =0x0300000e
    movs r0, #0x37
    strb r0, [r1]
    ldr r1, lbl_0805d6b0 @ =0x0300000f
    movs r0, #0x1f
    strb r0, [r1]
    ldr r0, lbl_0805d6b4 @ =0x03000010
    strh r3, [r0]
    b lbl_0805d748
    .align 2, 0
lbl_0805d698: .4byte 0x040000d4
lbl_0805d69c: .4byte 0x02009000
lbl_0805d6a0: .4byte 0x02035000
lbl_0805d6a4: .4byte 0x800000f0
lbl_0805d6a8: .4byte 0x03005520
lbl_0805d6ac: .4byte 0x0300000e
lbl_0805d6b0: .4byte 0x0300000f
lbl_0805d6b4: .4byte 0x03000010
lbl_0805d6b8:
    ldr r0, lbl_0805d6f0 @ =0x0300572c
    ldr r0, [r0]
    bl _call_via_r0
    cmp r0, #0
    beq lbl_0805d748
    ldr r0, lbl_0805d6f4 @ =0x03000088
    ldrh r1, [r0, #0xa]
    movs r2, #0
    strh r1, [r0, #0x12]
    ldr r1, lbl_0805d6f8 @ =0x03000130
    movs r0, #5
    strb r0, [r1]
    strb r2, [r1, #1]
    movs r0, #9
    bl SetupHazeCode
    ldr r0, lbl_0805d6fc @ =0x030056f4
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805d710
    ldr r1, lbl_0805d700 @ =0x040000d4
    ldr r0, lbl_0805d704 @ =0x02009000
    str r0, [r1]
    ldr r0, lbl_0805d708 @ =0x02035000
    str r0, [r1, #4]
    ldr r0, lbl_0805d70c @ =0x80000100
    b lbl_0805d71c
    .align 2, 0
lbl_0805d6f0: .4byte 0x0300572c
lbl_0805d6f4: .4byte 0x03000088
lbl_0805d6f8: .4byte 0x03000130
lbl_0805d6fc: .4byte 0x030056f4
lbl_0805d700: .4byte 0x040000d4
lbl_0805d704: .4byte 0x02009000
lbl_0805d708: .4byte 0x02035000
lbl_0805d70c: .4byte 0x80000100
lbl_0805d710:
    ldr r1, lbl_0805d730 @ =0x040000d4
    ldr r0, lbl_0805d734 @ =0x02009000
    str r0, [r1]
    ldr r0, lbl_0805d738 @ =0x02035000
    str r0, [r1, #4]
    ldr r0, lbl_0805d73c @ =0x800000f0
lbl_0805d71c:
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r2, lbl_0805d740 @ =0x03005520
    ldrb r1, [r2, #4]
    movs r0, #1
    orrs r0, r1
    strb r0, [r2, #4]
    movs r4, #1
    b lbl_0805d74c
    .align 2, 0
lbl_0805d730: .4byte 0x040000d4
lbl_0805d734: .4byte 0x02009000
lbl_0805d738: .4byte 0x02035000
lbl_0805d73c: .4byte 0x800000f0
lbl_0805d740: .4byte 0x03005520
lbl_0805d744:
    bl sub_0805da40
lbl_0805d748:
    cmp r4, #0
    beq lbl_0805d75a
lbl_0805d74c:
    bl SetBGHazeEffect
    ldr r0, lbl_0805d764 @ =0x0300006b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805d75a
    movs r4, #0
lbl_0805d75a:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805d764: .4byte 0x0300006b

    thumb_func_start haze_bg3
haze_bg3: @ 0x0805d768
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_0805d7b4 @ =0x02026d00
    movs r3, #0
    ldr r2, lbl_0805d7b8 @ =0x0300571c
    strb r3, [r2, #0xb]
    strb r3, [r2, #7]
    ldr r0, lbl_0805d7bc @ =0x0834607c
    mov ip, r0
    movs r7, #0xf
    strb r3, [r2, #3]
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #5
    ble lbl_0805d790
    movs r0, #1
    strb r0, [r2, #3]
    strh r3, [r2]
lbl_0805d790:
    ldr r1, lbl_0805d7c0 @ =0x03005728
    ldrb r0, [r2, #3]
    ldrb r2, [r1]
    adds r0, r0, r2
    strb r0, [r1]
    ldr r0, lbl_0805d7c4 @ =0x0300006c
    ldrh r1, [r0]
    lsrs r1, r1, #2
    ldr r0, lbl_0805d7c8 @ =0x030013ba
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    subs r1, #1
    cmp r1, #0xa0
    ble lbl_0805d7cc
    movs r1, #0xa0
    b lbl_0805d7d2
    .align 2, 0
lbl_0805d7b4: .4byte 0x02026d00
lbl_0805d7b8: .4byte 0x0300571c
lbl_0805d7bc: .4byte 0x0834607c
lbl_0805d7c0: .4byte 0x03005728
lbl_0805d7c4: .4byte 0x0300006c
lbl_0805d7c8: .4byte 0x030013ba
lbl_0805d7cc:
    cmp r1, #0
    bge lbl_0805d7d2
    movs r1, #0
lbl_0805d7d2:
    movs r3, #0
    cmp r3, r1
    bge lbl_0805d7ec
    ldr r4, lbl_0805d820 @ =0x030000e4
    adds r2, r6, #0
    adds r3, r1, #0
lbl_0805d7de:
    ldrh r0, [r4, #0xc]
    strh r0, [r2]
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805d7de
    adds r3, r1, #0
lbl_0805d7ec:
    cmp r3, #0x9f
    bgt lbl_0805d81a
    ldr r5, lbl_0805d824 @ =0x03005728
    ldr r4, lbl_0805d820 @ =0x030000e4
    lsls r0, r3, #1
    adds r2, r0, r6
lbl_0805d7f8:
    ldrh r0, [r4, #0xe]
    adds r0, r0, r3
    ldrb r6, [r5]
    adds r1, r0, r6
    ands r1, r7
    mov r6, ip
    adds r0, r6, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r1, [r4, #0xc]
    adds r0, r0, r1
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x9f
    ble lbl_0805d7f8
lbl_0805d81a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d820: .4byte 0x030000e4
lbl_0805d824: .4byte 0x03005728

    thumb_func_start haze_bg3_strong_effect_weak_outside
haze_bg3_strong_effect_weak_outside: @ 0x0805d828
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_0805d8a4 @ =0x02026d00
    mov ip, r0
    movs r3, #0
    ldr r2, lbl_0805d8a8 @ =0x0300571c
    strb r3, [r2, #0xb]
    ldr r5, lbl_0805d8ac @ =0x0834607c
    mov sb, r5
    movs r7, #0xf
    mov r8, r7
    strb r3, [r2, #3]
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #5
    ble lbl_0805d85a
    movs r0, #1
    strb r0, [r2, #3]
    strh r3, [r2]
lbl_0805d85a:
    ldr r0, lbl_0805d8b0 @ =0x0835f914
    mov sl, r0
    movs r6, #0xf
    movs r0, #0
    strb r0, [r2, #7]
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0xb
    ble lbl_0805d878
    movs r0, #1
    strb r0, [r2, #7]
    strh r3, [r2, #4]
lbl_0805d878:
    ldr r1, lbl_0805d8b4 @ =0x03005728
    ldrb r0, [r2, #3]
    ldrb r3, [r1]
    adds r0, r0, r3
    strb r0, [r1]
    ldr r1, lbl_0805d8b8 @ =0x03005729
    ldrb r0, [r2, #7]
    ldrb r5, [r1]
    adds r0, r0, r5
    strb r0, [r1]
    ldr r0, lbl_0805d8bc @ =0x0300006c
    ldrh r1, [r0]
    lsrs r1, r1, #2
    ldr r0, lbl_0805d8c0 @ =0x030013ba
    ldrh r0, [r0]
    lsrs r0, r0, #2
    subs r1, r1, r0
    subs r1, #1
    cmp r1, #0xa0
    ble lbl_0805d8c4
    movs r1, #0xa0
    b lbl_0805d8ca
    .align 2, 0
lbl_0805d8a4: .4byte 0x02026d00
lbl_0805d8a8: .4byte 0x0300571c
lbl_0805d8ac: .4byte 0x0834607c
lbl_0805d8b0: .4byte 0x0835f914
lbl_0805d8b4: .4byte 0x03005728
lbl_0805d8b8: .4byte 0x03005729
lbl_0805d8bc: .4byte 0x0300006c
lbl_0805d8c0: .4byte 0x030013ba
lbl_0805d8c4:
    cmp r1, #0
    bge lbl_0805d8ca
    movs r1, #0
lbl_0805d8ca:
    movs r3, #0
    cmp r3, r1
    bge lbl_0805d8f6
    ldr r5, lbl_0805d934 @ =0x03005729
    ldr r4, lbl_0805d938 @ =0x030000e4
    mov r2, ip
lbl_0805d8d6:
    ldrh r0, [r4, #0xe]
    adds r0, r0, r3
    ldrb r7, [r5]
    adds r0, r0, r7
    ands r0, r6
    add r0, sl
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r4, #0xc]
    adds r0, r0, r7
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, r1
    blt lbl_0805d8d6
lbl_0805d8f6:
    cmp r3, #0x9f
    bgt lbl_0805d926
    ldr r4, lbl_0805d93c @ =0x03005728
    ldr r2, lbl_0805d938 @ =0x030000e4
    lsls r0, r3, #1
    mov r5, ip
    adds r1, r0, r5
lbl_0805d904:
    ldrh r0, [r2, #0xe]
    adds r0, r0, r3
    ldrb r7, [r4]
    adds r0, r0, r7
    mov r5, r8
    ands r0, r5
    add r0, sb
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r2, #0xc]
    adds r0, r0, r7
    strh r0, [r1]
    adds r1, #2
    adds r3, #1
    cmp r3, #0x9f
    ble lbl_0805d904
lbl_0805d926:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d934: .4byte 0x03005729
lbl_0805d938: .4byte 0x030000e4
lbl_0805d93c: .4byte 0x03005728

    thumb_func_start haze_bg3_none_effect_weak_outside
haze_bg3_none_effect_weak_outside: @ 0x0805d940
    push {r4, r5, r6, r7, lr}
    movs r3, #0
    ldr r2, lbl_0805d99c @ =0x0300571c
    strb r3, [r2, #0xb]
    strb r3, [r2, #7]
    ldr r6, lbl_0805d9a0 @ =0x0835f924
    movs r5, #0x1f
    strb r3, [r2, #3]
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #5
    ble lbl_0805d964
    movs r0, #1
    strb r0, [r2, #3]
    strh r3, [r2]
lbl_0805d964:
    ldr r1, lbl_0805d9a4 @ =0x03005728
    ldrb r0, [r2, #3]
    ldrb r2, [r1]
    adds r0, r0, r2
    strb r0, [r1]
    adds r4, r1, #0
    ldr r1, lbl_0805d9a8 @ =0x030000e4
    ldr r2, lbl_0805d9ac @ =0x02026d00
lbl_0805d974:
    ldrh r0, [r1, #0xe]
    adds r0, r0, r3
    ldrb r7, [r4]
    adds r0, r0, r7
    ands r0, r5
    adds r0, r6, r0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r1, #0xc]
    adds r0, r0, r7
    strh r0, [r2]
    adds r2, #2
    adds r3, #1
    cmp r3, #0x9f
    ble lbl_0805d974
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805d99c: .4byte 0x0300571c
lbl_0805d9a0: .4byte 0x0835f924
lbl_0805d9a4: .4byte 0x03005728
lbl_0805d9a8: .4byte 0x030000e4
lbl_0805d9ac: .4byte 0x02026d00

    thumb_func_start haze_bg3_bg2_strong_effect_weak_outside_medium_everywhere
haze_bg3_bg2_strong_effect_weak_outside_medium_everywhere: @ 0x0805d9b0
    push {r4, r5, r6, r7, lr}
    movs r4, #0
    ldr r2, lbl_0805da2c @ =0x0300571c
    strb r4, [r2, #7]
    ldr r6, lbl_0805da30 @ =0x0835f924
    movs r5, #0x1f
    strb r4, [r2, #3]
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #5
    ble lbl_0805d9d2
    movs r0, #1
    strb r0, [r2, #3]
    strh r4, [r2]
lbl_0805d9d2:
    ldr r1, lbl_0805da34 @ =0x03005728
    ldrb r0, [r2, #3]
    ldrb r2, [r1]
    adds r0, r0, r2
    strb r0, [r1]
    ldr r2, lbl_0805da38 @ =0x02026d00
    ldr r3, lbl_0805da3c @ =0x030000e4
lbl_0805d9e0:
    ldrh r0, [r3, #0xa]
    adds r0, r0, r4
    ldrb r7, [r1]
    adds r0, r0, r7
    ands r0, r5
    adds r0, r6, r0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r3, #8]
    adds r0, r0, r7
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xa]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xe]
    adds r0, r0, r4
    ldrb r7, [r1]
    adds r0, r0, r7
    ands r0, r5
    adds r0, r6, r0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r3, #0xc]
    adds r0, r0, r7
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xe]
    strh r0, [r2]
    adds r2, #2
    adds r4, #1
    cmp r4, #0x9f
    ble lbl_0805d9e0
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805da2c: .4byte 0x0300571c
lbl_0805da30: .4byte 0x0835f924
lbl_0805da34: .4byte 0x03005728
lbl_0805da38: .4byte 0x02026d00
lbl_0805da3c: .4byte 0x030000e4

    thumb_func_start sub_0805da40
sub_0805da40: @ 0x0805da40
    push {r4, r5, r6, r7, lr}
    movs r5, #0
    ldr r1, lbl_0805da6c @ =0x0300571c
    ldrh r0, [r1, #8]
    adds r2, r0, #1
    strh r2, [r1, #8]
    ldr r0, lbl_0805da70 @ =0x03005514
    ldrb r0, [r0]
    adds r3, r1, #0
    cmp r0, #1
    bne lbl_0805da74
    lsls r0, r2, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0xf
    ble lbl_0805da88
    strh r5, [r3, #8]
    ldrb r0, [r3, #0xb]
    cmp r0, #3
    bhi lbl_0805da88
    adds r0, #1
    b lbl_0805da86
    .align 2, 0
lbl_0805da6c: .4byte 0x0300571c
lbl_0805da70: .4byte 0x03005514
lbl_0805da74:
    lsls r0, r2, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0xf
    ble lbl_0805da88
    strh r5, [r3, #8]
    ldrb r0, [r3, #0xb]
    cmp r0, #0
    beq lbl_0805da88
    subs r0, #1
lbl_0805da86:
    strb r0, [r3, #0xb]
lbl_0805da88:
    adds r2, r3, #0
    ldrb r0, [r2, #0xb]
    lsls r0, r0, #5
    ldr r1, lbl_0805db1c @ =0x0835f7f4
    adds r4, r0, r1
    movs r0, #0x1f
    mov ip, r0
    movs r1, #0
    strb r1, [r2, #3]
    ldrh r0, [r2]
    adds r0, #1
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #7
    ble lbl_0805daae
    movs r0, #1
    strb r0, [r2, #3]
    strh r1, [r2]
lbl_0805daae:
    ldr r0, lbl_0805db20 @ =0x03005728
    ldrb r1, [r0]
    ldrb r2, [r3, #3]
    subs r1, r1, r2
    strb r1, [r0]
    ldr r2, lbl_0805db24 @ =0x02026d00
    movs r5, #0
    adds r6, r0, #0
    ldr r3, lbl_0805db28 @ =0x030000e4
lbl_0805dac0:
    ldrh r0, [r3, #6]
    adds r0, r0, r5
    ldrb r7, [r6]
    adds r1, r0, r7
    mov r0, ip
    ands r1, r0
    adds r0, r4, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r7, [r3, #4]
    adds r1, r0, r7
    strh r1, [r2]
    adds r2, #2
    ldrh r0, [r3, #6]
    strh r0, [r2]
    adds r2, #2
    strh r1, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xa]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xe]
    adds r0, r0, r5
    ldrb r7, [r6]
    adds r1, r0, r7
    mov r0, ip
    ands r1, r0
    adds r0, r4, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrh r1, [r3, #0xc]
    adds r0, r0, r1
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r3, #0xe]
    strh r0, [r2]
    adds r2, #2
    adds r5, #1
    cmp r5, #0x9f
    ble lbl_0805dac0
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805db1c: .4byte 0x0835f7f4
lbl_0805db20: .4byte 0x03005728
lbl_0805db24: .4byte 0x02026d00
lbl_0805db28: .4byte 0x030000e4

    thumb_func_start haze_power_bomb_expanding
haze_power_bomb_expanding: @ 0x0805db2c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0805db84 @ =0x03000130
    ldrb r1, [r0, #0x12]
    mov ip, r0
    cmp r1, #0
    beq lbl_0805db3e
    b lbl_0805dc38
lbl_0805db3e:
    ldr r2, lbl_0805db88 @ =0x0835f570
    mov r0, ip
    ldrb r1, [r0, #2]
    lsls r0, r1, #2
    adds r0, r0, r2
    ldr r0, [r0]
    mov r8, r0
    adds r7, r1, #0
    mov r1, ip
    ldrh r0, [r1, #4]
    ldr r1, lbl_0805db8c @ =0x030013b8
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r6, r0, #2
    mov r2, ip
    ldrh r0, [r2, #6]
    ldr r1, lbl_0805db90 @ =0x030013ba
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r2, r0, #2
    ldr r5, lbl_0805db94 @ =0x02026d00
    movs r0, #0
    movs r4, #0x9f
lbl_0805db6c:
    strh r0, [r5]
    subs r4, #1
    adds r5, #2
    cmp r4, #0
    bge lbl_0805db6c
    adds r0, r2, r7
    adds r1, r0, #1
    cmp r1, #0x9f
    ble lbl_0805db98
    movs r1, #0x9f
    b lbl_0805db9e
    .align 2, 0
lbl_0805db84: .4byte 0x03000130
lbl_0805db88: .4byte 0x0835f570
lbl_0805db8c: .4byte 0x030013b8
lbl_0805db90: .4byte 0x030013ba
lbl_0805db94: .4byte 0x02026d00
lbl_0805db98:
    cmp r1, #0
    bge lbl_0805db9e
    movs r1, #0
lbl_0805db9e:
    movs r3, #0
    subs r4, r2, r7
    cmp r4, #0
    bge lbl_0805dbac
    rsbs r3, r4, #0
    movs r4, #0
    b lbl_0805dbb2
lbl_0805dbac:
    cmp r4, #0x9f
    ble lbl_0805dbb2
    movs r4, #0x9f
lbl_0805dbb2:
    lsls r0, r4, #1
    ldr r2, lbl_0805dbe4 @ =0x02026d00
    adds r5, r0, r2
    cmp r4, r1
    bge lbl_0805dc0c
    subs r4, r1, r4
    lsls r0, r3, #2
    mov r1, r8
    adds r3, r0, r1
lbl_0805dbc4:
    movs r2, #2
    ldrsh r0, [r3, r2]
    lsls r0, r0, #1
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    movs r1, #0
    ldrsh r0, [r3, r1]
    lsls r0, r0, #1
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    cmp r2, #0
    bge lbl_0805dbe8
    movs r2, #0
    b lbl_0805dbee
    .align 2, 0
lbl_0805dbe4: .4byte 0x02026d00
lbl_0805dbe8:
    cmp r2, #0xf0
    ble lbl_0805dbee
    movs r2, #0xf0
lbl_0805dbee:
    cmp r1, #0xf0
    ble lbl_0805dbf6
    movs r1, #0xf0
    b lbl_0805dbfc
lbl_0805dbf6:
    cmp r1, #0
    bge lbl_0805dbfc
    movs r1, #0
lbl_0805dbfc:
    lsls r0, r2, #8
    orrs r1, r0
    strh r1, [r5]
    subs r4, #1
    adds r3, #4
    adds r5, #2
    cmp r4, #0
    bne lbl_0805dbc4
lbl_0805dc0c:
    mov r1, ip
    ldrb r0, [r1, #2]
    cmp r0, #0x9e
    bls lbl_0805dc26
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bls lbl_0805dc38
    movs r0, #1
    b lbl_0805dc3a
lbl_0805dc26:
    adds r0, #3
    mov r2, ip
    strb r0, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x9f
    bls lbl_0805dc38
    movs r0, #0x9f
    strb r0, [r2, #2]
lbl_0805dc38:
    movs r0, #0
lbl_0805dc3a:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start haze_power_bomb_retracting
haze_power_bomb_retracting: @ 0x0805dc44
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0805dc9c @ =0x03000130
    ldrb r1, [r0, #0x12]
    mov ip, r0
    cmp r1, #0
    beq lbl_0805dc56
    b lbl_0805dd50
lbl_0805dc56:
    ldr r2, lbl_0805dca0 @ =0x0835f570
    mov r0, ip
    ldrb r1, [r0, #2]
    lsls r0, r1, #2
    adds r0, r0, r2
    ldr r0, [r0]
    mov r8, r0
    adds r7, r1, #0
    mov r1, ip
    ldrh r0, [r1, #4]
    ldr r1, lbl_0805dca4 @ =0x030013b8
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r6, r0, #2
    mov r2, ip
    ldrh r0, [r2, #6]
    ldr r1, lbl_0805dca8 @ =0x030013ba
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r2, r0, #2
    ldr r5, lbl_0805dcac @ =0x02026d00
    movs r0, #0
    movs r4, #0x9f
lbl_0805dc84:
    strh r0, [r5]
    subs r4, #1
    adds r5, #2
    cmp r4, #0
    bge lbl_0805dc84
    adds r0, r2, r7
    adds r1, r0, #1
    cmp r1, #0x9f
    ble lbl_0805dcb0
    movs r1, #0x9f
    b lbl_0805dcb6
    .align 2, 0
lbl_0805dc9c: .4byte 0x03000130
lbl_0805dca0: .4byte 0x0835f570
lbl_0805dca4: .4byte 0x030013b8
lbl_0805dca8: .4byte 0x030013ba
lbl_0805dcac: .4byte 0x02026d00
lbl_0805dcb0:
    cmp r1, #0
    bge lbl_0805dcb6
    movs r1, #0
lbl_0805dcb6:
    movs r3, #0
    subs r4, r2, r7
    cmp r4, #0
    bge lbl_0805dcc4
    rsbs r3, r4, #0
    movs r4, #0
    b lbl_0805dcca
lbl_0805dcc4:
    cmp r4, #0x9f
    ble lbl_0805dcca
    movs r4, #0x9f
lbl_0805dcca:
    lsls r0, r4, #1
    ldr r2, lbl_0805dcfc @ =0x02026d00
    adds r5, r0, r2
    cmp r4, r1
    bge lbl_0805dd24
    subs r4, r1, r4
    lsls r0, r3, #2
    mov r1, r8
    adds r3, r0, r1
lbl_0805dcdc:
    movs r2, #2
    ldrsh r0, [r3, r2]
    lsls r0, r0, #1
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r2, r0, #0x10
    movs r1, #0
    ldrsh r0, [r3, r1]
    lsls r0, r0, #1
    adds r0, r6, r0
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    cmp r2, #0
    bge lbl_0805dd00
    movs r2, #0
    b lbl_0805dd06
    .align 2, 0
lbl_0805dcfc: .4byte 0x02026d00
lbl_0805dd00:
    cmp r2, #0xf0
    ble lbl_0805dd06
    movs r2, #0xf0
lbl_0805dd06:
    cmp r1, #0xf0
    ble lbl_0805dd0e
    movs r1, #0xf0
    b lbl_0805dd14
lbl_0805dd0e:
    cmp r1, #0
    bge lbl_0805dd14
    movs r1, #0
lbl_0805dd14:
    lsls r0, r2, #8
    orrs r1, r0
    strh r1, [r5]
    subs r4, #1
    adds r3, #4
    adds r5, #2
    cmp r4, #0
    bne lbl_0805dcdc
lbl_0805dd24:
    mov r1, ip
    ldrb r0, [r1, #2]
    cmp r0, #4
    bhi lbl_0805dd3e
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bls lbl_0805dd50
    movs r0, #1
    b lbl_0805dd52
lbl_0805dd3e:
    subs r0, #3
    mov r2, ip
    strb r0, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bhi lbl_0805dd50
    movs r0, #4
    strb r0, [r2, #2]
lbl_0805dd50:
    movs r0, #0
lbl_0805dd52:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_0805dd5c
sub_0805dd5c: @ 0x0805dd5c
    push {r4, r5, lr}
    ldr r5, lbl_0805df30 @ =0x03000046
    ldrh r1, [r5]
    cmp r1, #0
    bne lbl_0805dd68
    b lbl_0805df28
lbl_0805dd68:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805dd80
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df38 @ =0x0201b000
    str r0, [r1]
    ldr r0, lbl_0805df3c @ =0x06004000
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805dd80:
    ldrh r1, [r5]
    movs r0, #2
    ands r0, r1
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_0805dd9c
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df44 @ =0x0201b080
    str r0, [r1]
    ldr r0, lbl_0805df48 @ =0x06004080
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805dd9c:
    movs r0, #4
    ands r0, r4
    cmp r0, #0
    beq lbl_0805ddb4
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df4c @ =0x0201b100
    str r0, [r1]
    ldr r0, lbl_0805df50 @ =0x06004100
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805ddb4:
    movs r0, #8
    ands r0, r4
    cmp r0, #0
    beq lbl_0805ddcc
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df54 @ =0x0201b180
    str r0, [r1]
    ldr r0, lbl_0805df58 @ =0x06004180
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805ddcc:
    movs r0, #0x10
    ands r0, r4
    cmp r0, #0
    beq lbl_0805dde4
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df5c @ =0x0201b200
    str r0, [r1]
    ldr r0, lbl_0805df60 @ =0x06004200
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805dde4:
    movs r0, #0x20
    ands r0, r4
    cmp r0, #0
    beq lbl_0805ddfc
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df64 @ =0x0201b280
    str r0, [r1]
    ldr r0, lbl_0805df68 @ =0x06004280
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805ddfc:
    movs r0, #0x40
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de14
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df6c @ =0x0201b300
    str r0, [r1]
    ldr r0, lbl_0805df70 @ =0x06004300
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de14:
    movs r0, #0x80
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de2c
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df74 @ =0x0201b380
    str r0, [r1]
    ldr r0, lbl_0805df78 @ =0x06004380
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de2c:
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de46
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df7c @ =0x0201b400
    str r0, [r1]
    ldr r0, lbl_0805df80 @ =0x06004400
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de46:
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de60
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df84 @ =0x0201b480
    str r0, [r1]
    ldr r0, lbl_0805df88 @ =0x06004480
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de60:
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de7a
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df8c @ =0x0201b500
    str r0, [r1]
    ldr r0, lbl_0805df90 @ =0x06004500
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de7a:
    movs r0, #0x80
    lsls r0, r0, #4
    ands r0, r4
    cmp r0, #0
    beq lbl_0805de94
    ldr r1, lbl_0805df34 @ =0x040000d4
    ldr r0, lbl_0805df94 @ =0x0201b580
    str r0, [r1]
    ldr r0, lbl_0805df98 @ =0x06004580
    str r0, [r1, #4]
    ldr r0, lbl_0805df40 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0805de94:
    movs r0, #0x80
    lsls r0, r0, #5
    ands r0, r4
    cmp r0, #0
    beq lbl_0805deb8
    ldr r0, lbl_0805df34 @ =0x040000d4
    ldr r3, lbl_0805df9c @ =0x0201b600
    str r3, [r0]
    ldr r1, lbl_0805dfa0 @ =0x06004600
    str r1, [r0, #4]
    ldr r2, lbl_0805df40 @ =0x80000040
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0805dfa4 @ =0x0600fde0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_0805deb8:
    movs r0, #0x80
    lsls r0, r0, #6
    ands r0, r4
    cmp r0, #0
    beq lbl_0805dedc
    ldr r0, lbl_0805df34 @ =0x040000d4
    ldr r3, lbl_0805dfa8 @ =0x0201b680
    str r3, [r0]
    ldr r1, lbl_0805dfac @ =0x06004680
    str r1, [r0, #4]
    ldr r2, lbl_0805df40 @ =0x80000040
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0805dfb0 @ =0x0600fe60
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_0805dedc:
    movs r0, #0x80
    lsls r0, r0, #7
    ands r0, r4
    cmp r0, #0
    beq lbl_0805df00
    ldr r0, lbl_0805df34 @ =0x040000d4
    ldr r3, lbl_0805dfb4 @ =0x0201b700
    str r3, [r0]
    ldr r1, lbl_0805dfb8 @ =0x06004700
    str r1, [r0, #4]
    ldr r2, lbl_0805df40 @ =0x80000040
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0805dfbc @ =0x0600fee0
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_0805df00:
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r4
    cmp r0, #0
    beq lbl_0805df24
    ldr r0, lbl_0805df34 @ =0x040000d4
    ldr r3, lbl_0805dfc0 @ =0x0201b780
    str r3, [r0]
    ldr r1, lbl_0805dfc4 @ =0x06004780
    str r1, [r0, #4]
    ldr r2, lbl_0805df40 @ =0x80000040
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    str r3, [r0]
    ldr r1, lbl_0805dfc8 @ =0x0600ff60
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
lbl_0805df24:
    movs r0, #0
    strh r0, [r5]
lbl_0805df28:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805df30: .4byte 0x03000046
lbl_0805df34: .4byte 0x040000d4
lbl_0805df38: .4byte 0x0201b000
lbl_0805df3c: .4byte 0x06004000
lbl_0805df40: .4byte 0x80000040
lbl_0805df44: .4byte 0x0201b080
lbl_0805df48: .4byte 0x06004080
lbl_0805df4c: .4byte 0x0201b100
lbl_0805df50: .4byte 0x06004100
lbl_0805df54: .4byte 0x0201b180
lbl_0805df58: .4byte 0x06004180
lbl_0805df5c: .4byte 0x0201b200
lbl_0805df60: .4byte 0x06004200
lbl_0805df64: .4byte 0x0201b280
lbl_0805df68: .4byte 0x06004280
lbl_0805df6c: .4byte 0x0201b300
lbl_0805df70: .4byte 0x06004300
lbl_0805df74: .4byte 0x0201b380
lbl_0805df78: .4byte 0x06004380
lbl_0805df7c: .4byte 0x0201b400
lbl_0805df80: .4byte 0x06004400
lbl_0805df84: .4byte 0x0201b480
lbl_0805df88: .4byte 0x06004480
lbl_0805df8c: .4byte 0x0201b500
lbl_0805df90: .4byte 0x06004500
lbl_0805df94: .4byte 0x0201b580
lbl_0805df98: .4byte 0x06004580
lbl_0805df9c: .4byte 0x0201b600
lbl_0805dfa0: .4byte 0x06004600
lbl_0805dfa4: .4byte 0x0600fde0
lbl_0805dfa8: .4byte 0x0201b680
lbl_0805dfac: .4byte 0x06004680
lbl_0805dfb0: .4byte 0x0600fe60
lbl_0805dfb4: .4byte 0x0201b700
lbl_0805dfb8: .4byte 0x06004700
lbl_0805dfbc: .4byte 0x0600fee0
lbl_0805dfc0: .4byte 0x0201b780
lbl_0805dfc4: .4byte 0x06004780
lbl_0805dfc8: .4byte 0x0600ff60

    thumb_func_start update_animated_graphics
update_animated_graphics: @ 0x0805dfcc
    push {r4, r5, r6, lr}
    ldr r3, lbl_0805dfe8 @ =0x03005730
    movs r5, #0
lbl_0805dfd2:
    movs r4, #0
    ldrb r0, [r3]
    cmp r0, #6
    bls lbl_0805dfdc
    b lbl_0805e0d6
lbl_0805dfdc:
    lsls r0, r0, #2
    ldr r1, lbl_0805dfec @ =lbl_0805dff0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805dfe8: .4byte 0x03005730
lbl_0805dfec: .4byte lbl_0805dff0
lbl_0805dff0: @ jump table
    .4byte lbl_0805e0d6 @ case 0
    .4byte lbl_0805e00c @ case 1
    .4byte lbl_0805e0d6 @ case 2
    .4byte lbl_0805e036 @ case 3
    .4byte lbl_0805e05e @ case 4
    .4byte lbl_0805e08a @ case 5
    .4byte lbl_0805e0ae @ case 6
lbl_0805e00c:
    ldrb r0, [r3, #2]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r2, [r3, #1]
    cmp r0, r2
    bne lbl_0805e0d6
    movs r4, #1
    strb r1, [r3, #2]
    ldrb r0, [r3, #4]
    adds r0, #1
    strb r0, [r3, #4]
    movs r0, #4
    ldrsb r0, [r3, r0]
    ldrb r6, [r3, #3]
    cmp r0, r6
    bne lbl_0805e0d6
    strb r1, [r3, #4]
    b lbl_0805e0d6
lbl_0805e036:
    movs r1, #4
    ldrsb r1, [r3, r1]
    ldrb r0, [r3, #3]
    subs r0, #1
    cmp r1, r0
    beq lbl_0805e0d6
    ldrb r0, [r3, #2]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r2, [r3, #1]
    cmp r0, r2
    bne lbl_0805e0d6
    movs r4, #1
    strb r1, [r3, #2]
    ldrb r0, [r3, #4]
    adds r0, #1
    b lbl_0805e0d4
lbl_0805e05e:
    ldrb r0, [r3, #2]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r6, [r3, #1]
    cmp r0, r6
    bne lbl_0805e0d6
    movs r4, #1
    strb r1, [r3, #2]
    ldrb r0, [r3, #4]
    adds r0, #1
    strb r0, [r3, #4]
    movs r1, #4
    ldrsb r1, [r3, r1]
    ldrb r0, [r3, #3]
    cmp r1, r0
    bne lbl_0805e0d6
    movs r0, #2
    subs r0, r0, r1
    b lbl_0805e0d4
lbl_0805e08a:
    ldrb r1, [r3, #4]
    movs r0, #4
    ldrsb r0, [r3, r0]
    cmp r0, #0
    beq lbl_0805e0d6
    ldrb r0, [r3, #2]
    adds r0, #1
    movs r2, #0
    strb r0, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r6, [r3, #1]
    cmp r0, r6
    bne lbl_0805e0d6
    movs r4, #1
    strb r2, [r3, #2]
    subs r0, r1, #1
    b lbl_0805e0d4
lbl_0805e0ae:
    ldrb r0, [r3, #2]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r2, [r3, #1]
    cmp r0, r2
    bne lbl_0805e0d6
    movs r4, #1
    strb r1, [r3, #2]
    ldrb r0, [r3, #4]
    subs r0, #1
    strb r0, [r3, #4]
    lsls r0, r0, #0x18
    cmp r0, #0
    bge lbl_0805e0d6
    ldrb r0, [r3, #3]
    subs r0, #1
lbl_0805e0d4:
    strb r0, [r3, #4]
lbl_0805e0d6:
    cmp r4, #0
    beq lbl_0805e110
    movs r1, #4
    ldrsb r1, [r3, r1]
    adds r0, r1, #0
    cmp r0, #0
    bge lbl_0805e0ec
    mvns r0, r1
    adds r0, #1
    lsls r0, r0, #0x18
    asrs r1, r0, #0x18
lbl_0805e0ec:
    lsls r1, r1, #7
    ldr r0, [r3, #8]
    adds r0, r0, r1
    ldr r1, lbl_0805e120 @ =0x040000d4
    str r0, [r1]
    lsls r0, r5, #7
    ldr r6, lbl_0805e124 @ =0x0201b000
    adds r0, r0, r6
    str r0, [r1, #4]
    ldr r0, lbl_0805e128 @ =0x80000040
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r2, lbl_0805e12c @ =0x03000046
    movs r0, #1
    lsls r0, r5
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
lbl_0805e110:
    adds r5, #1
    adds r3, #0xc
    cmp r5, #0xf
    bgt lbl_0805e11a
    b lbl_0805dfd2
lbl_0805e11a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e120: .4byte 0x040000d4
lbl_0805e124: .4byte 0x0201b000
lbl_0805e128: .4byte 0x80000040
lbl_0805e12c: .4byte 0x03000046

    thumb_func_start load_animated_graphics
load_animated_graphics: @ 0x0805e130
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r1, lbl_0805e1f0 @ =0x03000046
    movs r0, #0
    strh r0, [r1]
    ldr r3, lbl_0805e1f4 @ =0x03005730
    movs r5, #0
    ldr r0, lbl_0805e1f8 @ =0x0835f948
    mov sl, r0
    ldr r1, lbl_0805e1fc @ =0x03000bf0
    mov sb, r1
    ldr r2, lbl_0805e200 @ =0x0835fa78
    mov r8, r2
    mov ip, r5
    ldr r4, lbl_0805e204 @ =0x040000d4
    ldr r7, lbl_0805e208 @ =0x03005518
    movs r6, #0
lbl_0805e158:
    ldr r0, lbl_0805e20c @ =0x030056f4
    ldrb r1, [r0, #1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r6, r0
    add r0, r8
    ldrb r0, [r0]
    strb r0, [r3, #5]
    ldrb r1, [r3, #5]
    lsls r1, r1, #3
    add r1, sl
    ldrb r0, [r1]
    strb r0, [r3]
    ldrb r0, [r1, #1]
    strb r0, [r3, #1]
    ldrb r2, [r1, #2]
    strb r2, [r3, #3]
    mov r0, ip
    strb r0, [r3, #2]
    strb r0, [r3, #4]
    ldr r0, [r1, #4]
    str r0, [r3, #8]
    ldrb r0, [r3]
    cmp r0, #3
    beq lbl_0805e190
    cmp r0, #6
    bne lbl_0805e194
lbl_0805e190:
    subs r0, r2, #1
    strb r0, [r3, #4]
lbl_0805e194:
    movs r0, #4
    ldrsb r0, [r3, r0]
    lsls r0, r0, #7
    ldr r1, [r3, #8]
    adds r1, r1, r0
    lsls r0, r5, #7
    ldr r2, lbl_0805e210 @ =0x06004000
    adds r0, r0, r2
    str r1, [r4]
    str r0, [r4, #4]
    ldr r0, lbl_0805e214 @ =0x80000040
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    mov r1, sb
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0805e1c6
    ldrb r0, [r3, #5]
    cmp r0, #0xd
    bne lbl_0805e1c6
    ldrh r0, [r7]
    movs r1, #1
    orrs r0, r1
    strh r0, [r7]
lbl_0805e1c6:
    adds r6, #3
    adds r5, #1
    adds r3, #0xc
    cmp r5, #0xf
    ble lbl_0805e158
    ldr r1, lbl_0805e204 @ =0x040000d4
    ldr r0, lbl_0805e218 @ =0x06004600
    str r0, [r1]
    ldr r0, lbl_0805e21c @ =0x0600fde0
    str r0, [r1, #4]
    ldr r0, lbl_0805e220 @ =0x80000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e1f0: .4byte 0x03000046
lbl_0805e1f4: .4byte 0x03005730
lbl_0805e1f8: .4byte 0x0835f948
lbl_0805e1fc: .4byte 0x03000bf0
lbl_0805e200: .4byte 0x0835fa78
lbl_0805e204: .4byte 0x040000d4
lbl_0805e208: .4byte 0x03005518
lbl_0805e20c: .4byte 0x030056f4
lbl_0805e210: .4byte 0x06004000
lbl_0805e214: .4byte 0x80000040
lbl_0805e218: .4byte 0x06004600
lbl_0805e21c: .4byte 0x0600fde0
lbl_0805e220: .4byte 0x80000100

    thumb_func_start ResetTanksAnimation
ResetTanksAnimation: @ 0x0805e224
    ldr r0, lbl_0805e244 @ =0x030057f0
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    strb r2, [r0, #1]
    movs r1, #2
    strb r1, [r0, #4]
    strb r2, [r0, #5]
    movs r1, #3
    strb r1, [r0, #8]
    strb r2, [r0, #9]
    movs r1, #4
    strb r1, [r0, #0xc]
    strb r2, [r0, #0xd]
    bx lr
    .align 2, 0
lbl_0805e244: .4byte 0x030057f0

    thumb_func_start update_tanks_animation
update_tanks_animation: @ 0x0805e248
    push {r4, r5, lr}
    movs r3, #3
    ldr r0, lbl_0805e2a0 @ =0x030057f0
    movs r5, #0
    ldr r4, lbl_0805e2a4 @ =0x040000d4
    adds r2, r0, #0
    adds r2, #0xc
lbl_0805e256:
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bls lbl_0805e292
    strb r5, [r2]
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bls lbl_0805e276
    strb r5, [r2, #1]
lbl_0805e276:
    lsls r1, r3, #9
    ldrb r0, [r2, #1]
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r0, lbl_0805e2a8 @ =0x08752ab4
    adds r1, r1, r0
    str r1, [r4]
    lsls r0, r3, #7
    ldr r1, lbl_0805e2ac @ =0x06004820
    adds r0, r0, r1
    str r0, [r4, #4]
    ldr r0, lbl_0805e2b0 @ =0x80000040
    str r0, [r4, #8]
    ldr r0, [r4, #8]
lbl_0805e292:
    subs r2, #4
    subs r3, #1
    cmp r3, #0
    bge lbl_0805e256
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e2a0: .4byte 0x030057f0
lbl_0805e2a4: .4byte 0x040000d4
lbl_0805e2a8: .4byte 0x08752ab4
lbl_0805e2ac: .4byte 0x06004820
lbl_0805e2b0: .4byte 0x80000040

    thumb_func_start update_animated_palette
update_animated_palette: @ 0x0805e2b4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_0805e310 @ =0x030056f4
    ldrb r1, [r0]
    mov sb, r0
    cmp r1, #0
    bne lbl_0805e2ca
    b lbl_0805e408
lbl_0805e2ca:
    ldr r0, lbl_0805e314 @ =0x03000130
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805e2d4
    b lbl_0805e408
lbl_0805e2d4:
    ldr r0, lbl_0805e318 @ =0x0300004d
    mov r8, r0
    movs r1, #0
    ldrsb r1, [r0, r1]
    mov ip, r1
    cmp r1, #0
    ble lbl_0805e2e4
    b lbl_0805e408
lbl_0805e2e4:
    movs r7, #0
    ldr r1, lbl_0805e31c @ =0x030056ec
    ldrb r0, [r1]
    adds r6, r0, #1
    strb r6, [r1]
    ldr r2, lbl_0805e320 @ =0x0835fbfc
    mov r3, sb
    ldrb r0, [r3]
    lsls r0, r0, #3
    adds r3, r0, r2
    ldrb r4, [r3]
    adds r5, r1, #0
    mov sl, r2
    cmp r4, #1
    beq lbl_0805e324
    cmp r4, #1
    ble lbl_0805e3aa
    cmp r4, #2
    beq lbl_0805e34e
    cmp r4, #3
    beq lbl_0805e38a
    b lbl_0805e3aa
    .align 2, 0
lbl_0805e310: .4byte 0x030056f4
lbl_0805e314: .4byte 0x03000130
lbl_0805e318: .4byte 0x0300004d
lbl_0805e31c: .4byte 0x030056ec
lbl_0805e320: .4byte 0x0835fbfc
lbl_0805e324:
    ldrb r1, [r3, #1]
    lsls r0, r6, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhi lbl_0805e3aa
    strb r7, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    ldrb r1, [r3, #2]
    movs r0, #1
    ldrsb r0, [r5, r0]
    cmp r1, r0
    bgt lbl_0805e386
    strb r7, [r5, #1]
    mov r0, ip
    cmp r0, #0
    bge lbl_0805e386
    mov r1, r8
    strb r4, [r1]
    b lbl_0805e386
lbl_0805e34e:
    ldrb r1, [r3, #1]
    lsls r0, r6, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhi lbl_0805e3aa
    strb r7, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    ldrb r1, [r3, #2]
    movs r0, #1
    ldrsb r0, [r5, r0]
    cmp r1, r0
    bgt lbl_0805e370
    subs r0, r1, #1
    rsbs r0, r0, #0
    strb r0, [r5, #1]
lbl_0805e370:
    mov r3, r8
    movs r0, #0
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_0805e386
    movs r0, #1
    ldrsb r0, [r5, r0]
    cmp r0, #0
    bne lbl_0805e386
    movs r0, #1
    strb r0, [r3]
lbl_0805e386:
    adds r7, #1
    b lbl_0805e3aa
lbl_0805e38a:
    ldrb r1, [r3, #1]
    lsls r0, r6, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    bhi lbl_0805e3aa
    strb r7, [r5]
    ldrb r0, [r5, #1]
    subs r0, #1
    strb r0, [r5, #1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bge lbl_0805e3a8
    ldrb r0, [r3, #2]
    subs r0, #1
    strb r0, [r5, #1]
lbl_0805e3a8:
    movs r7, #1
lbl_0805e3aa:
    cmp r7, #0
    beq lbl_0805e408
    movs r3, #1
    ldrsb r3, [r5, r3]
    cmp r3, #0
    bge lbl_0805e3b8
    rsbs r3, r3, #0
lbl_0805e3b8:
    ldr r0, lbl_0805e3dc @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    bne lbl_0805e3e8
    ldr r2, lbl_0805e3e0 @ =0x040000d4
    mov r1, sb
    ldrb r0, [r1]
    lsls r0, r0, #3
    mov r1, sl
    adds r1, #4
    adds r0, r0, r1
    lsls r1, r3, #5
    ldr r0, [r0]
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0805e3e4 @ =0x050001e0
    b lbl_0805e400
    .align 2, 0
lbl_0805e3dc: .4byte 0x03000c72
lbl_0805e3e0: .4byte 0x040000d4
lbl_0805e3e4: .4byte 0x050001e0
lbl_0805e3e8:
    ldr r2, lbl_0805e418 @ =0x040000d4
    mov r1, sb
    ldrb r0, [r1]
    lsls r0, r0, #3
    mov r1, sl
    adds r1, #4
    adds r0, r0, r1
    lsls r1, r3, #5
    ldr r0, [r0]
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0805e41c @ =0x020355e0
lbl_0805e400:
    str r0, [r2, #4]
    ldr r0, lbl_0805e420 @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0805e408:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e418: .4byte 0x040000d4
lbl_0805e41c: .4byte 0x020355e0
lbl_0805e420: .4byte 0x80000010

    thumb_func_start sub_0805e424
sub_0805e424: @ 0x0805e424
    push {r4, lr}
    ldr r2, lbl_0805e46c @ =0x030056ec
    ldr r0, lbl_0805e470 @ =0x0835fbf8
    ldr r1, [r0]
    str r1, [r2]
    ldr r0, lbl_0805e474 @ =0x030056f0
    str r1, [r0]
    ldr r1, lbl_0805e478 @ =0x0300004d
    movs r0, #0
    strb r0, [r1]
    ldr r3, lbl_0805e47c @ =0x030056f4
    ldrb r0, [r3]
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_0805e4f4
    ldr r2, lbl_0805e480 @ =0x040000d4
    ldr r1, lbl_0805e484 @ =0x0835fbfc
    lsls r0, r0, #3
    adds r1, #4
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r2]
    ldr r0, lbl_0805e488 @ =0x050001e0
    str r0, [r2, #4]
    ldr r0, lbl_0805e48c @ =0x80000010
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldrb r0, [r3]
    subs r0, #3
    cmp r0, #0xe
    bhi lbl_0805e4f4
    lsls r0, r0, #2
    ldr r1, lbl_0805e490 @ =lbl_0805e494
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805e46c: .4byte 0x030056ec
lbl_0805e470: .4byte 0x0835fbf8
lbl_0805e474: .4byte 0x030056f0
lbl_0805e478: .4byte 0x0300004d
lbl_0805e47c: .4byte 0x030056f4
lbl_0805e480: .4byte 0x040000d4
lbl_0805e484: .4byte 0x0835fbfc
lbl_0805e488: .4byte 0x050001e0
lbl_0805e48c: .4byte 0x80000010
lbl_0805e490: .4byte lbl_0805e494
lbl_0805e494: @ jump table
    .4byte lbl_0805e4d0 @ case 0
    .4byte lbl_0805e4e8 @ case 1
    .4byte lbl_0805e4f4 @ case 2
    .4byte lbl_0805e4e8 @ case 3
    .4byte lbl_0805e4f4 @ case 4
    .4byte lbl_0805e4e8 @ case 5
    .4byte lbl_0805e4e8 @ case 6
    .4byte lbl_0805e4e8 @ case 7
    .4byte lbl_0805e4e8 @ case 8
    .4byte lbl_0805e4e8 @ case 9
    .4byte lbl_0805e4f4 @ case 10
    .4byte lbl_0805e4f4 @ case 11
    .4byte lbl_0805e4f4 @ case 12
    .4byte lbl_0805e4e8 @ case 13
    .4byte lbl_0805e4e8 @ case 14
lbl_0805e4d0:
    movs r0, #3
    movs r1, #0x2e
    bl EventFunction
    cmp r0, #0
    bne lbl_0805e4f4
    ldr r1, lbl_0805e4e4 @ =0x0300004d
    movs r0, #1
    strb r0, [r1]
    b lbl_0805e4f4
    .align 2, 0
lbl_0805e4e4: .4byte 0x0300004d
lbl_0805e4e8:
    ldr r0, lbl_0805e4fc @ =0x030001a8
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0805e4f4
    movs r0, #1
    strb r0, [r4]
lbl_0805e4f4:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e4fc: .4byte 0x030001a8

    thumb_func_start check_play_lightning_effect
check_play_lightning_effect: @ 0x0805e500
    push {lr}
    movs r1, #0
    ldr r0, lbl_0805e538 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805e534
    ldr r0, lbl_0805e53c @ =0x030056f8
    ldrb r0, [r0, #5]
    cmp r0, #0
    bne lbl_0805e534
    ldr r0, lbl_0805e540 @ =0x03000054
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0805e52a
    ldr r0, lbl_0805e544 @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0805e52a
    movs r1, #1
lbl_0805e52a:
    cmp r1, #0
    beq lbl_0805e534
    adds r0, r1, #0
    bl start_special_background_effect
lbl_0805e534:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e538: .4byte 0x03000bf0
lbl_0805e53c: .4byte 0x030056f8
lbl_0805e540: .4byte 0x03000054
lbl_0805e544: .4byte 0x03000055

    thumb_func_start check_apply_background_effect_color
check_apply_background_effect_color: @ 0x0805e548
    push {r4, r5, r6, lr}
    ldr r5, lbl_0805e570 @ =0x030056f8
    ldrh r0, [r5, #2]
    adds r0, #1
    strh r0, [r5, #2]
    bl process_special_background_effect
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #0
    beq lbl_0805e5b8
    cmp r4, #2
    bne lbl_0805e578
    ldr r1, lbl_0805e574 @ =0x0835fc8c
    ldrb r0, [r5, #5]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #4]
    b lbl_0805e582
    .align 2, 0
lbl_0805e570: .4byte 0x030056f8
lbl_0805e574: .4byte 0x0835fc8c
lbl_0805e578:
    ldr r1, lbl_0805e5c0 @ =0x0835fc8c
    ldrb r0, [r5, #5]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #2]
lbl_0805e582:
    adds r6, r1, #0
    adds r4, r0, #0
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r4
    cmp r0, #0
    bne lbl_0805e5b8
    ldr r5, lbl_0805e5c4 @ =0x030056f8
    ldrb r0, [r5, #5]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrh r0, [r0]
    ldrb r2, [r5, #4]
    adds r1, r4, #0
    bl sub_0805b830
    ldrb r0, [r5, #5]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #6]
    cmp r0, #0
    beq lbl_0805e5b8
    ldr r0, lbl_0805e5c8 @ =0x0000fffc
    ldrb r2, [r5, #4]
    adds r1, r4, #0
    bl sub_0805b96c
lbl_0805e5b8:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e5c0: .4byte 0x0835fc8c
lbl_0805e5c4: .4byte 0x030056f8
lbl_0805e5c8: .4byte 0x0000fffc

    thumb_func_start process_special_background_effect
process_special_background_effect: @ 0x0805e5cc
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_0805e5f8 @ =0x0875fdbc
    ldr r3, lbl_0805e5fc @ =0x030056f8
    ldrb r1, [r3, #5]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r2, [r3, #6]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #1
    ldr r1, [r1]
    adds r4, r1, r0
    ldrh r0, [r4]
    cmp r0, #9
    bls lbl_0805e5ee
    b lbl_0805e6ec
lbl_0805e5ee:
    lsls r0, r0, #2
    ldr r1, lbl_0805e600 @ =lbl_0805e604
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805e5f8: .4byte 0x0875fdbc
lbl_0805e5fc: .4byte 0x030056f8
lbl_0805e600: .4byte lbl_0805e604
lbl_0805e604: @ jump table
    .4byte lbl_0805e64c @ case 0
    .4byte lbl_0805e62c @ case 1
    .4byte lbl_0805e656 @ case 2
    .4byte lbl_0805e66c @ case 3
    .4byte lbl_0805e688 @ case 4
    .4byte lbl_0805e6a4 @ case 5
    .4byte lbl_0805e6c0 @ case 6
    .4byte lbl_0805e6c4 @ case 7
    .4byte lbl_0805e6cc @ case 8
    .4byte lbl_0805e6d8 @ case 9
lbl_0805e62c:
    ldrh r2, [r3, #2]
    ldrh r1, [r4, #2]
    ldr r0, lbl_0805e644 @ =0x03000c77
    ldrb r0, [r0]
    adds r1, r1, r0
    ldr r0, lbl_0805e648 @ =0x03000002
    ldrh r0, [r0]
    lsrs r0, r0, #4
    adds r1, r1, r0
    cmp r2, r1
    ble lbl_0805e6ec
    b lbl_0805e660
    .align 2, 0
lbl_0805e644: .4byte 0x03000c77
lbl_0805e648: .4byte 0x03000002
lbl_0805e64c:
    ldrh r0, [r3, #2]
    ldrh r4, [r4, #2]
    cmp r0, r4
    bls lbl_0805e6ec
    b lbl_0805e660
lbl_0805e656:
    ldrh r1, [r3, #2]
    ldrh r0, [r4, #2]
    subs r0, #1
    cmp r1, r0
    blt lbl_0805e6ec
lbl_0805e660:
    ldrb r0, [r3, #6]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #6]
    strh r1, [r3, #2]
    b lbl_0805e6ec
lbl_0805e66c:
    ldr r0, lbl_0805e684 @ =0x03005520
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_0805e6ec
    ldrh r0, [r4, #4]
    strb r0, [r3, #4]
    ldrb r0, [r3, #6]
    adds r0, #1
    strb r0, [r3, #6]
    strh r1, [r3, #2]
    movs r5, #1
    b lbl_0805e6ec
    .align 2, 0
lbl_0805e684: .4byte 0x03005520
lbl_0805e688:
    ldr r0, lbl_0805e6a0 @ =0x03005520
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_0805e6ec
    ldrh r0, [r4, #4]
    strb r0, [r3, #4]
    ldrb r0, [r3, #6]
    adds r0, #1
    strb r0, [r3, #6]
    strh r1, [r3, #2]
    movs r5, #2
    b lbl_0805e6ec
    .align 2, 0
lbl_0805e6a0: .4byte 0x03005520
lbl_0805e6a4:
    ldrh r0, [r4, #4]
    cmp r0, #0
    beq lbl_0805e6ae
    bl SoundPlay
lbl_0805e6ae:
    ldr r0, lbl_0805e6bc @ =0x030056f8
    ldrb r1, [r0, #6]
    adds r1, #1
    movs r2, #0
    strb r1, [r0, #6]
    strh r2, [r0, #2]
    b lbl_0805e6ec
    .align 2, 0
lbl_0805e6bc: .4byte 0x030056f8
lbl_0805e6c0:
    movs r0, #0
    strb r0, [r3, #5]
lbl_0805e6c4:
    movs r0, #0
    strb r0, [r3, #6]
    strh r0, [r3, #2]
    b lbl_0805e6ec
lbl_0805e6cc:
    movs r0, #0
    strb r0, [r3, #5]
    strb r0, [r3, #6]
    strh r0, [r3, #2]
    movs r0, #0x10
    b lbl_0805e6e2
lbl_0805e6d8:
    movs r0, #0
    strb r0, [r3, #5]
    strb r0, [r3, #6]
    strh r0, [r3, #2]
    movs r0, #0x14
lbl_0805e6e2:
    bl ColorFadingStart
    ldr r1, lbl_0805e6f4 @ =0x03000c72
    movs r0, #3
    strh r0, [r1]
lbl_0805e6ec:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805e6f4: .4byte 0x03000c72

    thumb_func_start start_special_background_effect
start_special_background_effect: @ 0x0805e6f8
    push {r4, r5, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r2, lbl_0805e740 @ =0x030056f8
    ldrb r1, [r2, #5]
    cmp r1, #0
    bne lbl_0805e754
    cmp r0, #0xff
    beq lbl_0805e754
    strb r0, [r2, #5]
    strb r1, [r2, #4]
    strb r1, [r2, #6]
    movs r0, #0
    strh r1, [r2, #2]
    strb r0, [r2, #7]
    ldr r1, lbl_0805e744 @ =0x02035400
    ldr r2, lbl_0805e748 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805e74c @ =0x02035600
    ldr r2, lbl_0805e750 @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    movs r0, #1
    b lbl_0805e756
    .align 2, 0
lbl_0805e740: .4byte 0x030056f8
lbl_0805e744: .4byte 0x02035400
lbl_0805e748: .4byte 0x02035800
lbl_0805e74c: .4byte 0x02035600
lbl_0805e750: .4byte 0x02035a00
lbl_0805e754:
    movs r0, #0
lbl_0805e756:
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ConnectionUpdateHatches
ConnectionUpdateHatches: @ 0x0805e760
    push {r4, r5, r6, r7, lr}
    movs r7, #0
lbl_0805e764:
    ldr r0, lbl_0805e7a0 @ =0x0300545c
    lsls r2, r7, #3
    adds r3, r2, r0
    ldrb r1, [r3]
    lsls r1, r1, #0x1f
    adds r4, r0, #0
    adds r6, r2, #0
    cmp r1, #0
    bne lbl_0805e778
    b lbl_0805e8e6
lbl_0805e778:
    ldrb r2, [r3, #1]
    lsls r1, r2, #0x1e
    lsrs r0, r1, #0x1e
    cmp r0, #1
    beq lbl_0805e7a4
    cmp r0, #3
    beq lbl_0805e7a4
    lsrs r0, r2, #4
    cmp r0, #0
    bne lbl_0805e78e
    b lbl_0805e8e6
lbl_0805e78e:
    ldrb r0, [r3, #3]
    cmp r0, #3
    beq lbl_0805e796
    b lbl_0805e8e6
lbl_0805e796:
    lsls r0, r7, #0x18
    lsrs r0, r0, #0x18
    bl sub_0805ea54
    b lbl_0805e8e6
    .align 2, 0
lbl_0805e7a0: .4byte 0x0300545c
lbl_0805e7a4:
    adds r5, r6, r4
    ldrb r1, [r5]
    lsls r2, r1, #0x1c
    lsrs r0, r2, #0x1d
    cmp r0, #0
    bne lbl_0805e834
    ldrb r0, [r5, #1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    bne lbl_0805e7c4
    movs r0, #0x86
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0805e80a
lbl_0805e7c4:
    ldrb r0, [r5, #3]
    cmp r0, #7
    bhi lbl_0805e804
    lsls r0, r0, #2
    ldr r1, lbl_0805e7d4 @ =lbl_0805e7d8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805e7d4: .4byte lbl_0805e7d8
lbl_0805e7d8: @ jump table
    .4byte lbl_0805e804 @ case 0
    .4byte lbl_0805e804 @ case 1
    .4byte lbl_0805e804 @ case 2
    .4byte lbl_0805e804 @ case 3
    .4byte lbl_0805e804 @ case 4
    .4byte lbl_0805e804 @ case 5
    .4byte lbl_0805e7f8 @ case 6
    .4byte lbl_0805e7f8 @ case 7
lbl_0805e7f8:
    ldr r0, lbl_0805e800 @ =0x00000117
    bl SoundPlay
    b lbl_0805e80a
    .align 2, 0
lbl_0805e800: .4byte 0x00000117
lbl_0805e804:
    ldr r0, lbl_0805e82c @ =0x0000010d
    bl SoundPlay
lbl_0805e80a:
    ldr r2, lbl_0805e830 @ =0x0300545c
    adds r2, r6, r2
    movs r0, #0
    strb r0, [r2, #4]
    ldrb r3, [r2]
    lsls r1, r3, #0x1c
    lsrs r1, r1, #0x1d
    adds r1, #1
    movs r0, #7
    ands r1, r0
    lsls r1, r1, #1
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    b lbl_0805e8e6
    .align 2, 0
lbl_0805e82c: .4byte 0x0000010d
lbl_0805e830: .4byte 0x0300545c
lbl_0805e834:
    lsrs r0, r2, #0x1d
    cmp r0, #7
    bne lbl_0805e870
    ldrb r0, [r5, #1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    bne lbl_0805e8e6
    movs r4, #0xf
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r5]
    movs r0, #1
    adds r1, r7, #0
    bl update_hatch_anim
    ldrb r1, [r5, #1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #2
    orrs r0, r1
    strb r0, [r5, #1]
    ldrb r0, [r5]
    ands r4, r0
    strb r4, [r5]
    b lbl_0805e8e6
lbl_0805e870:
    ldr r1, lbl_0805e884 @ =0x083602c2
    lsrs r0, r2, #0x1d
    adds r0, r0, r1
    ldrb r1, [r5, #4]
    ldrb r0, [r0]
    cmp r1, r0
    bhs lbl_0805e888
    adds r0, r1, #1
    strb r0, [r5, #4]
    b lbl_0805e8e6
    .align 2, 0
lbl_0805e884: .4byte 0x083602c2
lbl_0805e888:
    movs r0, #0
    strb r0, [r5, #4]
    movs r0, #1
    adds r1, r7, #0
    bl update_hatch_anim
    ldrb r2, [r5]
    lsls r1, r2, #0x1c
    lsrs r1, r1, #0x1d
    adds r1, #1
    movs r0, #7
    ands r1, r0
    lsls r1, r1, #1
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r5]
    lsls r0, r0, #0x1c
    lsrs r0, r0, #0x1d
    cmp r0, #5
    bne lbl_0805e8e6
    ldrb r2, [r5, #1]
    lsls r1, r2, #0x1e
    lsrs r0, r1, #0x1e
    cmp r0, #1
    bne lbl_0805e8ca
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    movs r1, #2
    orrs r0, r1
    b lbl_0805e8d6
lbl_0805e8ca:
    lsrs r0, r1, #0x1e
    cmp r0, #3
    bne lbl_0805e8d8
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
lbl_0805e8d6:
    strb r0, [r5, #1]
lbl_0805e8d8:
    ldr r0, lbl_0805e8f4 @ =0x0300545c
    adds r0, r6, r0
    ldrb r2, [r0]
    movs r1, #0xf
    rsbs r1, r1, #0
    ands r1, r2
    strb r1, [r0]
lbl_0805e8e6:
    adds r7, #1
    cmp r7, #0xf
    bgt lbl_0805e8ee
    b lbl_0805e764
lbl_0805e8ee:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805e8f4: .4byte 0x0300545c

    thumb_func_start update_hatch_anim
update_hatch_anim: @ 0x0805e8f8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r5, r1, #0
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, lbl_0805e948 @ =0x0300545c
    lsls r4, r5, #3
    adds r1, r4, r0
    ldrb r2, [r1]
    lsls r3, r2, #0x1b
    ldr r7, lbl_0805e94c @ =0x00000411
    mov r8, r0
    cmp r3, #0
    bge lbl_0805e91e
    adds r7, #5
lbl_0805e91e:
    lsls r0, r2, #0x1c
    lsrs r0, r0, #0x1d
    subs r2, r0, #1
    ldrb r0, [r1, #1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #3
    bne lbl_0805e95e
    movs r0, #2
    subs r2, r0, r2
    cmp r2, #0
    bge lbl_0805e954
    movs r2, #0
    ldr r0, lbl_0805e950 @ =0x083602c8
    ldrb r1, [r1, #3]
    lsls r1, r1, #1
    adds r1, r1, r0
    lsrs r0, r3, #0x1f
    ldrh r1, [r1]
    adds r7, r0, r1
    b lbl_0805e95e
    .align 2, 0
lbl_0805e948: .4byte 0x0300545c
lbl_0805e94c: .4byte 0x00000411
lbl_0805e950: .4byte 0x083602c8
lbl_0805e954:
    ldrb r0, [r1, #3]
    mov sl, r4
    cmp r0, #0
    beq lbl_0805e96c
    adds r2, #0x40
lbl_0805e95e:
    lsls r0, r5, #3
    mov r3, r8
    adds r1, r0, r3
    ldrb r1, [r1, #3]
    mov sl, r0
    cmp r1, #0
    bne lbl_0805e96e
lbl_0805e96c:
    adds r2, #0x80
lbl_0805e96e:
    adds r7, r7, r2
    cmp r6, #0
    beq lbl_0805e9c0
    ldr r4, lbl_0805e9bc @ =0x0300545c
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    adds r0, r7, #0
    bl set_bg1_block_value
    movs r0, #0x10
    adds r0, r0, r7
    mov r8, r0
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl set_bg1_block_value
    adds r1, r7, #0
    adds r1, #0x20
    str r1, [sp]
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    ldr r0, [sp]
    bl set_bg1_block_value
    adds r5, r7, #0
    adds r5, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    adds r0, r5, #0
    bl set_bg1_block_value
    mov r6, r8
    ldr r3, [sp]
    mov r8, r3
    b lbl_0805ea04
    .align 2, 0
lbl_0805e9bc: .4byte 0x0300545c
lbl_0805e9c0:
    ldr r4, lbl_0805ea50 @ =0x0300545c
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    adds r0, r7, #0
    bl set_raw_bg1_block_value
    movs r0, #0x10
    adds r0, r0, r7
    mov r8, r0
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl set_raw_bg1_block_value
    movs r1, #0x20
    adds r1, r1, r7
    mov sb, r1
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    mov r0, sb
    bl set_raw_bg1_block_value
    adds r5, r7, #0
    adds r5, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    adds r0, r5, #0
    bl set_raw_bg1_block_value
    mov r6, r8
    mov r8, sb
lbl_0805ea04:
    lsls r0, r7, #0x10
    lsrs r0, r0, #0x10
    ldr r4, lbl_0805ea50 @ =0x0300545c
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    bl set_clipdata_block_value
    lsls r0, r6, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl set_clipdata_block_value
    mov r3, r8
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    bl set_clipdata_block_value
    lsls r0, r5, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    bl set_clipdata_block_value
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ea50: .4byte 0x0300545c

    thumb_func_start sub_0805ea54
sub_0805ea54: @ 0x0805ea54
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r1, lbl_0805ea88 @ =0x0300545c
    lsls r0, r4, #3
    adds r3, r0, r1
    ldrb r2, [r3, #2]
    lsls r0, r2, #0x1c
    adds r6, r1, #0
    cmp r0, #0
    bne lbl_0805ea90
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    movs r1, #4
    orrs r0, r1
    strb r0, [r3, #2]
    ldrb r1, [r3, #1]
    lsrs r1, r1, #4
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805eaa4
    ldr r5, lbl_0805ea8c @ =0x0000049a
    b lbl_0805eaae
    .align 2, 0
lbl_0805ea88: .4byte 0x0300545c
lbl_0805ea8c: .4byte 0x0000049a
lbl_0805ea90:
    lsrs r0, r0, #0x1c
    subs r0, #1
    movs r1, #0xf
    ands r0, r1
    movs r1, #0x10
    rsbs r1, r1, #0
    ands r1, r2
    orrs r1, r0
    strb r1, [r3, #2]
    b lbl_0805eb12
lbl_0805eaa4:
    ldr r1, lbl_0805eb00 @ =0x083602c8
    ldrb r0, [r3, #3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r5, [r0]
lbl_0805eaae:
    lsls r0, r4, #3
    adds r4, r0, r6
    ldrb r0, [r4]
    lsls r0, r0, #0x1b
    cmp r0, #0
    bge lbl_0805eabc
    adds r5, #1
lbl_0805eabc:
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    adds r0, r5, #0
    bl set_bg1_block_value
    adds r0, r5, #0
    adds r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl set_bg1_block_value
    adds r0, r5, #0
    adds r0, #0x20
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    bl set_bg1_block_value
    adds r0, r5, #0
    adds r0, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    bl set_bg1_block_value
    ldrb r2, [r4, #1]
    lsls r1, r2, #0x18
    lsrs r0, r1, #0x1c
    cmp r0, #3
    bls lbl_0805eb04
    movs r0, #0xf
    ands r0, r2
    b lbl_0805eb10
    .align 2, 0
lbl_0805eb00: .4byte 0x083602c8
lbl_0805eb04:
    lsrs r1, r1, #0x1c
    adds r1, #1
    lsls r1, r1, #4
    movs r0, #0xf
    ands r0, r2
    orrs r0, r1
lbl_0805eb10:
    strb r0, [r4, #1]
lbl_0805eb12:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_0805eb18
sub_0805eb18: @ 0x0805eb18
    push {r4, r5, r6, lr}
    mov r6, sl
    mov r5, sb
    mov r4, r8
    push {r4, r5, r6}
    adds r5, r0, #0
    lsls r5, r5, #0x18
    ldr r0, lbl_0805ebe8 @ =0x0300545c
    lsrs r5, r5, #0x15
    adds r5, r5, r0
    movs r0, #0
    mov sl, r0
    strb r1, [r5, #3]
    ldr r1, lbl_0805ebec @ =0x083602c8
    ldrb r0, [r5, #3]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrb r4, [r5]
    lsls r4, r4, #0x1b
    lsrs r4, r4, #0x1f
    ldrh r0, [r0]
    adds r4, r4, r0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldrb r1, [r5, #6]
    ldrb r2, [r5, #5]
    adds r0, r4, #0
    bl set_bg1_block_value
    adds r6, r4, #0
    adds r6, #0x10
    ldrb r1, [r5, #6]
    adds r1, #1
    ldrb r2, [r5, #5]
    adds r0, r6, #0
    bl set_bg1_block_value
    movs r0, #0x20
    adds r0, r0, r4
    mov r8, r0
    ldrb r1, [r5, #6]
    adds r1, #2
    ldrb r2, [r5, #5]
    bl set_bg1_block_value
    movs r0, #0x30
    adds r0, r0, r4
    mov sb, r0
    ldrb r1, [r5, #6]
    adds r1, #3
    ldrb r2, [r5, #5]
    bl set_bg1_block_value
    ldrb r1, [r5, #6]
    ldrb r2, [r5, #5]
    adds r0, r4, #0
    bl set_clipdata_block_value
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    ldrb r1, [r5, #6]
    adds r1, #1
    ldrb r2, [r5, #5]
    adds r0, r6, #0
    bl set_clipdata_block_value
    mov r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrb r1, [r5, #6]
    adds r1, #2
    ldrb r2, [r5, #5]
    bl set_clipdata_block_value
    mov r0, sb
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrb r1, [r5, #6]
    adds r1, #3
    ldrb r2, [r5, #5]
    bl set_clipdata_block_value
    ldrb r1, [r5, #1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5, #1]
    ldrb r1, [r5]
    movs r0, #0xf
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5]
    mov r0, sl
    strb r0, [r5, #4]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ebe8: .4byte 0x0300545c
lbl_0805ebec: .4byte 0x083602c8

    thumb_func_start check_enter_door
check_enter_door: @ 0x0805ebf0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    ldr r0, lbl_0805ec10 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0805ec14
    movs r0, #0
    b lbl_0805ed84
    .align 2, 0
lbl_0805ec10: .4byte 0x03000c72
lbl_0805ec14:
    movs r5, #0
    mov ip, r5
    ldr r0, lbl_0805ec9c @ =0x0300545c
    ldr r2, lbl_0805eca0 @ =0x03000054
    mov sl, r2
    adds r3, r0, #7
    mov sb, r5
    ldr r0, lbl_0805eca4 @ =0x03000056
    mov r8, r0
lbl_0805ec26:
    ldrb r0, [r3]
    ldr r1, lbl_0805eca8 @ =0x08345868
    ldrb r1, [r1, #7]
    cmp r0, r1
    bne lbl_0805ec32
    b lbl_0805ed70
lbl_0805ec32:
    mov r0, sl
    ldrb r2, [r0]
    lsls r2, r2, #2
    ldr r1, lbl_0805ecac @ =0x0875faa8
    adds r2, r2, r1
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    ldr r1, [r2]
    adds r4, r1, r0
    ldrb r1, [r4]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #1
    bhi lbl_0805ec54
    b lbl_0805ed70
lbl_0805ec54:
    ldrb r0, [r4, #2]
    cmp r0, r6
    bls lbl_0805ec5c
    b lbl_0805ed70
lbl_0805ec5c:
    ldrb r2, [r4, #3]
    cmp r6, r2
    bls lbl_0805ec64
    b lbl_0805ed70
lbl_0805ec64:
    ldrb r0, [r4, #4]
    cmp r0, r7
    bls lbl_0805ec6c
    b lbl_0805ed70
lbl_0805ec6c:
    ldrb r0, [r4, #5]
    cmp r7, r0
    bls lbl_0805ec74
    b lbl_0805ed70
lbl_0805ec74:
    ldr r1, lbl_0805ecb0 @ =0x030054e0
    movs r0, #0
    strh r0, [r1]
    strh r0, [r1, #2]
    ldrb r1, [r4]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0805ecbc
    ldrb r0, [r3]
    bl find_event_based_door_number
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0xff
    beq lbl_0805ecb4
    mov r1, r8
    strb r5, [r1]
    b lbl_0805ecc2
    .align 2, 0
lbl_0805ec9c: .4byte 0x0300545c
lbl_0805eca0: .4byte 0x03000054
lbl_0805eca4: .4byte 0x03000056
lbl_0805eca8: .4byte 0x08345868
lbl_0805ecac: .4byte 0x0875faa8
lbl_0805ecb0: .4byte 0x030054e0
lbl_0805ecb4:
    ldrb r0, [r4, #6]
    mov r2, r8
    strb r0, [r2]
    b lbl_0805ecc2
lbl_0805ecbc:
    ldrb r0, [r4, #6]
    mov r1, r8
    strb r0, [r1]
lbl_0805ecc2:
    ldrb r1, [r4]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #2
    bls lbl_0805ece4
    ldrb r1, [r4, #2]
    ldr r0, lbl_0805ed54 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r0, r0, #6
    adds r0, #8
    ldr r2, lbl_0805ed58 @ =0x030054e0
    cmp r1, r0
    ble lbl_0805ece0
    movs r0, #1
    strh r0, [r2]
lbl_0805ece0:
    ldrb r0, [r4, #4]
    strh r0, [r2, #2]
lbl_0805ece4:
    ldr r2, lbl_0805ed5c @ =0x0300550c
    ldrb r0, [r4, #5]
    adds r0, #1
    lsls r0, r0, #6
    ldr r1, lbl_0805ed60 @ =0x030013d4
    ldrh r1, [r1, #0x14]
    subs r0, r0, r1
    subs r0, #1
    strh r0, [r2]
    ldrb r0, [r4]
    bl process_door_type
    ldr r1, lbl_0805ed64 @ =0x03000c72
    movs r0, #3
    strh r0, [r1]
    ldr r0, lbl_0805ed68 @ =0x0300545c
    mov r2, sb
    adds r1, r2, r0
    ldrb r2, [r1]
    lsls r0, r2, #0x1f
    cmp r0, #0
    beq lbl_0805ed20
    ldrb r0, [r1, #1]
    lsls r0, r0, #0x1e
    lsrs r0, r0, #0x1e
    cmp r0, #1
    bne lbl_0805ed20
    movs r0, #0xe
    orrs r0, r2
    strb r0, [r1]
lbl_0805ed20:
    mov r1, sl
    ldrb r0, [r1]
    lsls r3, r0, #2
    ldr r2, lbl_0805ed6c @ =0x0875faa8
    adds r3, r3, r2
    mov r1, r8
    ldrb r2, [r1]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    ldr r2, [r3]
    adds r4, r2, r1
    ldrb r1, [r4, #1]
    adds r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl check_play_cutscene_during_transition
    mov r2, sl
    ldrb r0, [r2]
    ldrb r1, [r4, #1]
    bl check_play_room_music_track
    movs r5, #1
    b lbl_0805ed82
    .align 2, 0
lbl_0805ed54: .4byte 0x030013b8
lbl_0805ed58: .4byte 0x030054e0
lbl_0805ed5c: .4byte 0x0300550c
lbl_0805ed60: .4byte 0x030013d4
lbl_0805ed64: .4byte 0x03000c72
lbl_0805ed68: .4byte 0x0300545c
lbl_0805ed6c: .4byte 0x0875faa8
lbl_0805ed70:
    adds r3, #8
    movs r0, #8
    add sb, r0
    movs r1, #1
    add ip, r1
    mov r2, ip
    cmp r2, #0xf
    bgt lbl_0805ed82
    b lbl_0805ec26
lbl_0805ed82:
    adds r0, r5, #0
lbl_0805ed84:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_area_connection
check_area_connection: @ 0x0805ed94
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    ldr r0, lbl_0805ee20 @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0805edb2
    b lbl_0805eeb4
lbl_0805edb2:
    movs r4, #0
    mov r8, r4
    ldr r1, lbl_0805ee24 @ =0x0300545c
    ldr r0, lbl_0805ee28 @ =0x08345868
    ldrb r0, [r0, #7]
    mov ip, r0
    adds r3, r1, #7
    ldr r2, lbl_0805ee2c @ =0x03000056
    mov sb, r2
lbl_0805edc4:
    ldrb r0, [r3]
    cmp r0, ip
    beq lbl_0805ee4a
    ldr r2, lbl_0805ee30 @ =0x0875faa8
    ldr r0, lbl_0805ee34 @ =0x03000054
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r2, [r3]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r1, [r1]
    adds r5, r1, r0
    ldrb r1, [r5]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #1
    bne lbl_0805ee4a
    ldrb r0, [r5, #2]
    cmp r0, r6
    bhi lbl_0805ee4a
    ldrb r0, [r5, #3]
    cmp r6, r0
    bhi lbl_0805ee4a
    ldrb r0, [r5, #4]
    cmp r0, r7
    bhi lbl_0805ee4a
    ldrb r0, [r5, #5]
    cmp r7, r0
    bhi lbl_0805ee4a
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0805ee40
    adds r0, r2, #0
    bl find_event_based_door_number
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0xff
    beq lbl_0805ee38
    mov r1, sb
    strb r4, [r1]
    b lbl_0805ee46
    .align 2, 0
lbl_0805ee20: .4byte 0x03000c72
lbl_0805ee24: .4byte 0x0300545c
lbl_0805ee28: .4byte 0x08345868
lbl_0805ee2c: .4byte 0x03000056
lbl_0805ee30: .4byte 0x0875faa8
lbl_0805ee34: .4byte 0x03000054
lbl_0805ee38:
    ldrb r0, [r5, #6]
    mov r2, sb
    strb r0, [r2]
    b lbl_0805ee46
lbl_0805ee40:
    ldrb r0, [r5, #6]
    mov r3, sb
    strb r0, [r3]
lbl_0805ee46:
    movs r4, #1
    b lbl_0805ee6c
lbl_0805ee4a:
    adds r3, #8
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #0xf
    ble lbl_0805edc4
    cmp r4, #0
    bne lbl_0805ee6c
    b lbl_0805eeb4
lbl_0805ee5c:
    mov r0, sl
    adds r0, #2
    adds r0, r1, r0
    ldrb r0, [r0]
    mov r2, sb
    strb r0, [r2]
    movs r4, #2
    b lbl_0805eeaa
lbl_0805ee6c:
    ldr r2, lbl_0805eeb8 @ =0x08360274
    ldrb r0, [r2]
    mov ip, r2
    cmp r0, #0xff
    beq lbl_0805eeaa
    mov sl, r2
    ldr r3, lbl_0805eebc @ =0x03000054
    mov sb, r3
    ldrb r7, [r3]
    ldr r1, lbl_0805eec0 @ =0x0300545c
    mov r3, r8
    lsls r0, r3, #3
    adds r6, r0, r1
    movs r1, #0
    adds r3, r2, #0
lbl_0805ee8a:
    ldrb r0, [r3]
    cmp r0, r7
    bne lbl_0805ee9c
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    ldrb r2, [r6, #7]
    cmp r0, r2
    beq lbl_0805ee5c
lbl_0805ee9c:
    adds r1, #3
    adds r3, #3
    mov r2, ip
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_0805ee8a
lbl_0805eeaa:
    cmp r4, #2
    beq lbl_0805eec8
    ldr r1, lbl_0805eec4 @ =0x03000056
    movs r0, #0
    strb r0, [r1]
lbl_0805eeb4:
    movs r0, #0
    b lbl_0805ef22
    .align 2, 0
lbl_0805eeb8: .4byte 0x08360274
lbl_0805eebc: .4byte 0x03000054
lbl_0805eec0: .4byte 0x0300545c
lbl_0805eec4: .4byte 0x03000056
lbl_0805eec8:
    ldr r2, lbl_0805eed8 @ =0x030013d4
    ldrb r0, [r2]
    cmp r0, #0x1d
    bne lbl_0805eee0
    ldr r1, lbl_0805eedc @ =0x0300550c
    movs r0, #0
    strh r0, [r1]
    b lbl_0805eef0
    .align 2, 0
lbl_0805eed8: .4byte 0x030013d4
lbl_0805eedc: .4byte 0x0300550c
lbl_0805eee0:
    ldr r0, lbl_0805ef30 @ =0x0300550c
    ldrb r1, [r5, #5]
    adds r1, #1
    lsls r1, r1, #6
    ldrh r2, [r2, #0x14]
    subs r1, r1, r2
    subs r1, #1
    strh r1, [r0]
lbl_0805eef0:
    movs r0, #6
    bl ColorFadingStart
    ldr r1, lbl_0805ef34 @ =0x03000c72
    movs r0, #3
    strh r0, [r1]
    ldr r0, lbl_0805ef38 @ =0x0875faa8
    ldr r4, lbl_0805ef3c @ =0x03000054
    ldrb r1, [r4]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, lbl_0805ef40 @ =0x03000056
    ldrb r2, [r0]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r1, [r1]
    adds r5, r1, r0
    bl check_play_cutscene_during_elevator
    ldrb r0, [r4]
    ldrb r1, [r5, #1]
    bl check_play_room_music_track
    movs r0, #1
lbl_0805ef22:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805ef30: .4byte 0x0300550c
lbl_0805ef34: .4byte 0x03000c72
lbl_0805ef38: .4byte 0x0875faa8
lbl_0805ef3c: .4byte 0x03000054
lbl_0805ef40: .4byte 0x03000056

    thumb_func_start process_door_type
process_door_type: @ 0x0805ef44
    push {lr}
    lsls r0, r0, #0x18
    movs r2, #6
    movs r1, #0xf0
    lsls r1, r1, #0x14
    ands r1, r0
    lsrs r1, r1, #0x18
    cmp r1, #5
    beq lbl_0805ef6a
    cmp r1, #5
    bgt lbl_0805ef64
    cmp r1, #2
    bgt lbl_0805ef84
    cmp r1, #1
    blt lbl_0805ef84
    b lbl_0805ef94
lbl_0805ef64:
    cmp r1, #6
    beq lbl_0805ef78
    b lbl_0805ef84
lbl_0805ef6a:
    ldr r1, lbl_0805ef74 @ =0x0300002d
    movs r0, #0
    strb r0, [r1]
    b lbl_0805ef94
    .align 2, 0
lbl_0805ef74: .4byte 0x0300002d
lbl_0805ef78:
    ldr r1, lbl_0805ef80 @ =0x0300002d
    movs r0, #1
    strb r0, [r1]
    b lbl_0805ef94
    .align 2, 0
lbl_0805ef80: .4byte 0x0300002d
lbl_0805ef84:
    ldr r1, lbl_0805efa0 @ =0x0300002a
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0805efa4 @ =0x03000042
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805ef94
    movs r2, #4
lbl_0805ef94:
    adds r0, r2, #0
    bl ColorFadingStart
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805efa0: .4byte 0x0300002a
lbl_0805efa4: .4byte 0x03000042

    thumb_func_start find_event_based_door_number
find_event_based_door_number: @ 0x0805efa8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    movs r5, #0x28
    ldr r0, lbl_0805efe8 @ =0x03000054
    mov r8, r0
    ldr r6, lbl_0805efec @ =0x083601d0
    adds r4, r6, #0
    adds r4, #0xa0
lbl_0805efbe:
    lsls r1, r5, #2
    mov r2, r8
    ldrb r0, [r2]
    ldrb r2, [r4]
    cmp r0, r2
    bne lbl_0805eff0
    adds r0, r6, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r7, r0
    bne lbl_0805eff0
    adds r0, r6, #2
    adds r0, r1, r0
    ldrb r1, [r0]
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_0805eff0
    ldrb r0, [r4, #3]
    b lbl_0805effa
    .align 2, 0
lbl_0805efe8: .4byte 0x03000054
lbl_0805efec: .4byte 0x083601d0
lbl_0805eff0:
    subs r4, #4
    subs r5, #1
    cmp r5, #0
    bge lbl_0805efbe
    movs r0, #0xff
lbl_0805effa:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start set_hatch_as_opened
set_hatch_as_opened: @ 0x0805f004
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_0805f078 @ =0x03000054
    mov ip, r0
    ldrb r0, [r0]
    lsls r0, r0, #5
    ldr r2, lbl_0805f07c @ =0x02037c00
    adds r5, r0, r2
    movs r7, #0
    lsrs r1, r1, #0x1d
    movs r3, #0x1f
    mov r8, r3
    adds r3, r4, #0
    mov r0, r8
    ands r3, r0
    cmp r6, #0
    beq lbl_0805f084
    lsls r2, r1, #2
    adds r2, r2, r5
    movs r1, #1
    lsls r1, r3
    ldr r0, [r2]
    bics r0, r1
    str r0, [r2]
    cmp r6, #1
    bne lbl_0805f096
    ldr r1, lbl_0805f080 @ =0x0875faa8
    mov r2, ip
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r2, [r0]
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    mov r1, sp
    adds r0, r0, r2
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    mov r0, sp
    ldrb r0, [r0, #6]
    lsrs r1, r0, #5
    mov r3, r8
    ands r0, r3
    lsls r2, r1, #2
    adds r2, r2, r5
    adds r1, r6, #0
    lsls r1, r0
    ldr r0, [r2]
    bics r0, r1
    str r0, [r2]
    b lbl_0805f096
    .align 2, 0
lbl_0805f078: .4byte 0x03000054
lbl_0805f07c: .4byte 0x02037c00
lbl_0805f080: .4byte 0x0875faa8
lbl_0805f084:
    lsls r1, r1, #2
    adds r1, r1, r5
    movs r0, #1
    lsls r0, r3
    ldr r7, [r1]
    ands r7, r0
    cmp r7, #0
    beq lbl_0805f096
    movs r7, #1
lbl_0805f096:
    adds r0, r7, #0
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_unlock_doors
check_unlock_doors: @ 0x0805f0a4
    push {r4, lr}
    ldr r1, lbl_0805f0dc @ =0x0300007b
    ldrb r2, [r1]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bge lbl_0805f0d6
    adds r0, r2, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805f0d6
    ldr r4, lbl_0805f0e0 @ =0x030054e4
    ldrh r0, [r4, #2]
    cmp r0, #0
    bne lbl_0805f0ca
    ldrh r0, [r4, #6]
    cmp r0, #0
    beq lbl_0805f0d6
lbl_0805f0ca:
    movs r0, #0x8b
    lsls r0, r0, #1
    bl SoundPlay
    movs r0, #1
    strb r0, [r4]
lbl_0805f0d6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f0dc: .4byte 0x0300007b
lbl_0805f0e0: .4byte 0x030054e4

    thumb_func_start sub_0805f0e4
sub_0805f0e4: @ 0x0805f0e4
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r3, lbl_0805f11c @ =0x0300545c
    lsls r4, r1, #3
    adds r4, r4, r3
    movs r3, #3
    ands r2, r3
    ldrb r5, [r4, #1]
    subs r3, #7
    ands r3, r5
    orrs r3, r2
    strb r3, [r4, #1]
    ldrb r3, [r4]
    movs r2, #0xf
    rsbs r2, r2, #0
    ands r2, r3
    strb r2, [r4]
    bl update_hatch_anim
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f11c: .4byte 0x0300545c

    thumb_func_start lock_hatches
lock_hatches: @ 0x0805f120
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r5, #0
    movs r7, #0
    ldr r2, lbl_0805f160 @ =0x030054e4
    movs r3, #1
    ldr r1, lbl_0805f164 @ =0x0300545c
lbl_0805f138:
    ldrb r0, [r1]
    lsls r0, r0, #0x1f
    cmp r0, #0
    beq lbl_0805f14a
    adds r0, r3, #0
    lsls r0, r5
    orrs r0, r7
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
lbl_0805f14a:
    adds r1, #8
    adds r5, #1
    cmp r5, #0xf
    ble lbl_0805f138
    cmp r4, #0
    bne lbl_0805f168
    ldrh r0, [r2, #2]
    ands r0, r7
    strh r0, [r2, #2]
    b lbl_0805f174
    .align 2, 0
lbl_0805f160: .4byte 0x030054e4
lbl_0805f164: .4byte 0x0300545c
lbl_0805f168:
    ldrh r0, [r2, #4]
    ands r0, r7
    strh r0, [r2, #4]
    ldrh r0, [r2, #6]
    ands r0, r7
    strh r0, [r2, #6]
lbl_0805f174:
    cmp r4, #0
    bne lbl_0805f1e8
    ldrh r0, [r2, #4]
    ldrh r1, [r2, #6]
    orrs r0, r1
    ldrh r1, [r2, #2]
    bics r1, r0
    strh r1, [r2, #2]
    adds r7, r1, #0
    movs r5, #0
    movs r4, #0
lbl_0805f18a:
    adds r0, r7, #0
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805f1da
    ldr r0, lbl_0805f1c8 @ =0x0300545c
    lsls r2, r5, #3
    adds r2, r2, r0
    ldrb r1, [r2, #1]
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r1, r0
    movs r0, #4
    orrs r1, r0
    strb r1, [r2, #1]
    movs r0, #6
    strb r0, [r2, #3]
    ldr r1, lbl_0805f1cc @ =0x03000056
    ldrb r0, [r2, #7]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_0805f1d0
    lsrs r1, r4, #0x18
    movs r0, #1
    movs r2, #0
    bl sub_0805f0e4
    b lbl_0805f1da
    .align 2, 0
lbl_0805f1c8: .4byte 0x0300545c
lbl_0805f1cc: .4byte 0x03000056
lbl_0805f1d0:
    lsrs r1, r4, #0x18
    movs r0, #1
    movs r2, #3
    bl sub_0805f0e4
lbl_0805f1da:
    movs r0, #0x80
    lsls r0, r0, #0x11
    adds r4, r4, r0
    adds r5, #1
    cmp r5, #0xf
    ble lbl_0805f18a
    b lbl_0805f284
lbl_0805f1e8:
    ldrh r1, [r2, #4]
    ldrh r0, [r2, #6]
    adds r7, r0, #0
    orrs r7, r1
    movs r5, #0
    movs r1, #1
    mov sl, r1
    mov r8, r5
    ldr r4, lbl_0805f22c @ =0x0300545c
    movs r3, #0xd
    rsbs r3, r3, #0
    mov sb, r3
    movs r6, #0
lbl_0805f202:
    adds r0, r7, #0
    asrs r0, r5
    mov r1, sl
    ands r0, r1
    cmp r0, #0
    beq lbl_0805f272
    ldr r0, lbl_0805f230 @ =0x030054e4
    ldrh r0, [r0, #6]
    asrs r0, r5
    ands r0, r1
    cmp r0, #0
    beq lbl_0805f234
    ldrb r0, [r4, #1]
    mov r3, sb
    ands r0, r3
    movs r1, #4
    orrs r0, r1
    strb r0, [r4, #1]
    movs r0, #6
    b lbl_0805f242
    .align 2, 0
lbl_0805f22c: .4byte 0x0300545c
lbl_0805f230: .4byte 0x030054e4
lbl_0805f234:
    ldrb r0, [r4, #1]
    mov r1, sb
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    strb r0, [r4, #1]
    movs r0, #7
lbl_0805f242:
    strb r0, [r4, #3]
    ldr r0, lbl_0805f260 @ =0x0300545c
    add r0, r8
    ldr r1, lbl_0805f264 @ =0x03000056
    ldrb r0, [r0, #7]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_0805f268
    lsrs r1, r6, #0x18
    movs r0, #1
    movs r2, #0
    bl sub_0805f0e4
    b lbl_0805f272
    .align 2, 0
lbl_0805f260: .4byte 0x0300545c
lbl_0805f264: .4byte 0x03000056
lbl_0805f268:
    lsrs r1, r6, #0x18
    movs r0, #1
    movs r2, #3
    bl sub_0805f0e4
lbl_0805f272:
    movs r3, #8
    add r8, r3
    adds r4, #8
    movs r0, #0x80
    lsls r0, r0, #0x11
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #0xf
    ble lbl_0805f202
lbl_0805f284:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start load_doors
load_doors: @ 0x0805f294
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0805f3b8 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f2ae
    b lbl_0805f590
lbl_0805f2ae:
    ldr r1, lbl_0805f3bc @ =0x0300545c
    ldr r6, lbl_0805f3c0 @ =0x0875faa8
    ldr r5, lbl_0805f3c4 @ =0x03000054
    ldr r0, lbl_0805f3c8 @ =0x08345868
    ldr r3, [r0]
    ldr r4, [r0, #4]
    adds r2, r1, #0
    adds r2, #0x78
lbl_0805f2be:
    str r3, [r2]
    str r4, [r2, #4]
    subs r2, #8
    cmp r2, r1
    bge lbl_0805f2be
    movs r0, #0xff
    mov sl, r0
    movs r0, #0
    ldr r1, lbl_0805f3cc @ =0x030054dc
    strb r0, [r1]
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldr r6, [r0]
    movs r2, #0
    str r2, [sp]
    mov r8, r2
    ldrb r1, [r6]
    cmp r1, #0
    bne lbl_0805f2e8
    b lbl_0805f4ae
lbl_0805f2e8:
    ldr r4, lbl_0805f3d0 @ =0x030054e4
    mov sb, r4
lbl_0805f2ec:
    ldr r0, lbl_0805f3d4 @ =0x03000055
    ldrb r0, [r0]
    ldrb r2, [r6, #1]
    cmp r0, r2
    beq lbl_0805f2f8
    b lbl_0805f4a0
lbl_0805f2f8:
    movs r0, #0xf
    ands r0, r1
    subs r0, #3
    cmp r0, #1
    bls lbl_0805f304
    b lbl_0805f47e
lbl_0805f304:
    ldr r2, lbl_0805f3d8 @ =0x0300009c
    ldrh r1, [r2, #0x1c]
    ldrb r0, [r6, #4]
    muls r0, r1, r0
    ldrb r4, [r6, #2]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r2, r0, r1
    ldrh r1, [r2, #2]
    ldr r3, lbl_0805f3dc @ =0x03005450
    ldr r0, [r3, #4]
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r4, #1
    mov ip, r4
    cmp r0, #0xb
    beq lbl_0805f330
    movs r0, #0
    mov ip, r0
    subs r0, r2, #2
    ldrh r1, [r0]
lbl_0805f330:
    ldr r0, [r3, #8]
    lsls r1, r1, #1
    adds r1, r1, r0
    ldrh r1, [r1]
    adds r0, r1, #0
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r7, #0
    cmp r0, #4
    bhi lbl_0805f34a
    adds r7, r1, #0
    subs r7, #0x7f
lbl_0805f34a:
    ldr r0, lbl_0805f3e0 @ =0x08360130
    adds r0, r7, r0
    ldrb r7, [r0]
    ldr r1, lbl_0805f3cc @ =0x030054dc
    ldrb r4, [r1]
    cmp r4, #0xf
    ble lbl_0805f35a
    b lbl_0805f462
lbl_0805f35a:
    lsls r0, r4, #3
    ldr r2, lbl_0805f3bc @ =0x0300545c
    adds r1, r0, r2
    ldrb r1, [r1]
    lsls r1, r1, #0x1f
    adds r5, r0, #0
    cmp r1, #0
    beq lbl_0805f384
    adds r0, r2, #0
    adds r1, r5, #0
    adds r2, r1, r0
lbl_0805f370:
    adds r1, #8
    adds r2, #8
    adds r4, #1
    cmp r4, #0xf
    bgt lbl_0805f462
    ldrb r0, [r2]
    lsls r0, r0, #0x1f
    adds r5, r1, #0
    cmp r0, #0
    bne lbl_0805f370
lbl_0805f384:
    cmp r4, #0xf
    bgt lbl_0805f462
    ldr r0, lbl_0805f3bc @ =0x0300545c
    adds r3, r5, r0
    strb r7, [r3, #3]
    cmp r7, #1
    ble lbl_0805f42a
    mov r1, ip
    movs r2, #1
    ands r1, r2
    lsls r1, r1, #4
    ldrb r2, [r3]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldrb r0, [r6, #4]
    strb r0, [r3, #6]
    ldrb r0, [r6, #2]
    strb r0, [r3, #5]
    mov r1, ip
    cmp r1, #0
    beq lbl_0805f3e4
    adds r0, #1
    b lbl_0805f3e6
    .align 2, 0
lbl_0805f3b8: .4byte 0x03000bf0
lbl_0805f3bc: .4byte 0x0300545c
lbl_0805f3c0: .4byte 0x0875faa8
lbl_0805f3c4: .4byte 0x03000054
lbl_0805f3c8: .4byte 0x08345868
lbl_0805f3cc: .4byte 0x030054dc
lbl_0805f3d0: .4byte 0x030054e4
lbl_0805f3d4: .4byte 0x03000055
lbl_0805f3d8: .4byte 0x0300009c
lbl_0805f3dc: .4byte 0x03005450
lbl_0805f3e0: .4byte 0x08360130
lbl_0805f3e4:
    subs r0, #1
lbl_0805f3e6:
    strb r0, [r3, #5]
    ldr r2, lbl_0805f410 @ =0x0300545c
    adds r0, r5, r2
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
    mov r1, r8
    strb r1, [r0, #7]
    adds r0, r4, #1
    ldr r2, lbl_0805f414 @ =0x030054dc
    strb r0, [r2]
    cmp r7, #6
    bne lbl_0805f418
    movs r0, #1
    lsls r0, r4
    mov r2, sb
    ldrh r1, [r2, #2]
    orrs r0, r1
    strh r0, [r2, #2]
    b lbl_0805f45c
    .align 2, 0
lbl_0805f410: .4byte 0x0300545c
lbl_0805f414: .4byte 0x030054dc
lbl_0805f418:
    cmp r7, #7
    bne lbl_0805f45c
    movs r0, #1
    lsls r0, r4
    mov r2, sb
    ldrh r1, [r2, #4]
    orrs r0, r1
    strh r0, [r2, #4]
    b lbl_0805f45c
lbl_0805f42a:
    ldrb r0, [r6, #4]
    strb r0, [r3, #6]
    ldrb r2, [r6, #2]
    strb r2, [r3, #5]
    ldrb r0, [r3]
    movs r1, #1
    orrs r1, r0
    strb r1, [r3]
    mov r0, r8
    strb r0, [r3, #7]
    movs r0, #7
    ldrsb r0, [r6, r0]
    cmp r0, #0
    ble lbl_0805f450
    adds r0, r2, #1
    strb r0, [r3, #5]
    movs r0, #0x10
    orrs r1, r0
    b lbl_0805f45a
lbl_0805f450:
    subs r0, r2, #1
    strb r0, [r3, #5]
    movs r2, #0x11
    rsbs r2, r2, #0
    ands r1, r2
lbl_0805f45a:
    strb r1, [r3]
lbl_0805f45c:
    ldr r0, [sp]
    adds r0, #1
    str r0, [sp]
lbl_0805f462:
    mov r1, sl
    cmp r1, #0xff
    bne lbl_0805f49a
    ldr r0, lbl_0805f474 @ =0x03000056
    ldrb r0, [r0]
    cmp r8, r0
    bne lbl_0805f49a
    mov sl, r4
    b lbl_0805f49a
    .align 2, 0
lbl_0805f474: .4byte 0x03000056
lbl_0805f478:
    mov r2, r8
    strb r2, [r1, #7]
    b lbl_0805f49a
lbl_0805f47e:
    movs r4, #0xf
    ldr r1, lbl_0805f52c @ =0x0300545c
    ldr r0, lbl_0805f530 @ =0x08345868
    ldrb r2, [r0, #7]
    adds r1, #0x78
    movs r3, #1
    rsbs r3, r3, #0
lbl_0805f48c:
    ldrb r0, [r1, #7]
    cmp r0, r2
    beq lbl_0805f478
    subs r1, #8
    subs r4, #1
    cmp r4, r3
    bgt lbl_0805f48c
lbl_0805f49a:
    ldr r4, [sp]
    cmp r4, #0xf
    bgt lbl_0805f4ae
lbl_0805f4a0:
    adds r6, #0xc
    movs r0, #1
    add r8, r0
    ldrb r1, [r6]
    cmp r1, #0
    beq lbl_0805f4ae
    b lbl_0805f2ec
lbl_0805f4ae:
    movs r4, #0
lbl_0805f4b0:
    ldr r1, lbl_0805f52c @ =0x0300545c
    lsls r0, r4, #3
    adds r1, r0, r1
    ldrb r0, [r1]
    lsls r0, r0, #0x1f
    cmp r0, #0
    beq lbl_0805f4da
    ldrb r0, [r1, #3]
    cmp r0, #1
    bls lbl_0805f4da
    ldrb r1, [r1, #7]
    movs r0, #0
    bl set_hatch_as_opened
    cmp r0, #0
    bne lbl_0805f4da
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    movs r1, #2
    bl sub_0805eb18
lbl_0805f4da:
    adds r4, #1
    cmp r4, #0xf
    ble lbl_0805f4b0
    mov r1, sl
    cmp r1, #0xff
    beq lbl_0805f590
    ldr r0, lbl_0805f534 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f590
    ldr r0, lbl_0805f52c @ =0x0300545c
    lsls r1, r1, #3
    adds r2, r1, r0
    ldrb r0, [r2]
    lsls r0, r0, #0x1f
    adds r4, r1, #0
    cmp r0, #0
    beq lbl_0805f516
    ldrb r0, [r2, #3]
    cmp r0, #0
    beq lbl_0805f516
    mov r2, sl
    lsls r1, r2, #0x18
    lsrs r1, r1, #0x18
    movs r0, #0
    movs r2, #3
    bl sub_0805f0e4
lbl_0805f516:
    ldr r1, lbl_0805f52c @ =0x0300545c
    adds r0, r4, r1
    ldrb r2, [r0, #5]
    mov r8, r2
    ldrb r0, [r0]
    lsls r0, r0, #0x1b
    cmp r0, #0
    bge lbl_0805f538
    movs r0, #1
    add r8, r0
    b lbl_0805f53e
    .align 2, 0
lbl_0805f52c: .4byte 0x0300545c
lbl_0805f530: .4byte 0x08345868
lbl_0805f534: .4byte 0x03000c75
lbl_0805f538:
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
lbl_0805f53e:
    adds r0, r4, r1
    ldrb r4, [r0, #6]
    ldr r2, lbl_0805f5a0 @ =0x03005450
    ldr r1, lbl_0805f5a4 @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    muls r0, r4, r0
    add r0, r8
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    adds r0, r1, #0
    bl check_clipdata_behavior_change_bldalpha
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0805f590
    movs r0, #0xff
    ands r0, r1
    lsrs r1, r1, #8
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    ldr r2, lbl_0805f5a8 @ =0x03000088
    ldr r1, lbl_0805f5ac @ =0x030056cc
    ldrb r0, [r1, #3]
    strb r0, [r2, #5]
    ldrb r0, [r1, #4]
    strb r0, [r2, #4]
    ldr r3, lbl_0805f5b0 @ =0x04000052
    ldrb r1, [r2, #5]
    lsls r1, r1, #8
    ldrb r0, [r2, #4]
    orrs r0, r1
    strh r0, [r3]
lbl_0805f590:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f5a0: .4byte 0x03005450
lbl_0805f5a4: .4byte 0x0300009c
lbl_0805f5a8: .4byte 0x03000088
lbl_0805f5ac: .4byte 0x030056cc
lbl_0805f5b0: .4byte 0x04000052

    thumb_func_start ConnectionLockHatchesWithTimer
ConnectionLockHatchesWithTimer: @ 0x0805f5b4
    push {lr}
    ldr r1, lbl_0805f5cc @ =0x030054e4
    ldr r0, lbl_0805f5d0 @ =0x0000ffff
    strh r0, [r1, #2]
    movs r0, #0
    bl lock_hatches
    ldr r1, lbl_0805f5d4 @ =0x0300007b
    movs r0, #2
    strb r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f5cc: .4byte 0x030054e4
lbl_0805f5d0: .4byte 0x0000ffff
lbl_0805f5d4: .4byte 0x0300007b

    thumb_func_start check_hatch_lock_events
check_hatch_lock_events: @ 0x0805f5d8
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0805f6fc @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f5e8
    b lbl_0805f73a
lbl_0805f5e8:
    ldr r3, lbl_0805f700 @ =0x030054e4
    strh r0, [r3, #4]
    strh r0, [r3, #6]
    ldr r1, lbl_0805f704 @ =0x03000054
    ldrb r0, [r1]
    cmp r0, #6
    bls lbl_0805f5f8
    b lbl_0805f73a
lbl_0805f5f8:
    ldr r2, lbl_0805f708 @ =0x083602d8
    adds r1, r0, #0
    lsls r0, r1, #1
    adds r0, r0, r2
    ldrh r2, [r0]
    ldr r0, lbl_0805f70c @ =0x0875fde0
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r5, [r1]
    cmp r2, #0
    bne lbl_0805f610
    b lbl_0805f72c
lbl_0805f610:
    adds r6, r3, #0
    adds r7, r2, #0
lbl_0805f614:
    movs r4, #0
    ldr r1, lbl_0805f710 @ =0x03000055
    ldrb r0, [r5]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0805f6ea
    ldrb r1, [r5, #1]
    movs r0, #3
    bl EventFunction
    adds r1, r0, #0
    ldrb r0, [r5, #2]
    cmp r0, #1
    beq lbl_0805f636
    cmp r0, #3
    bne lbl_0805f638
    movs r0, #1
lbl_0805f636:
    eors r1, r0
lbl_0805f638:
    cmp r1, #0
    beq lbl_0805f6ea
    ldrb r1, [r5, #3]
    lsls r0, r1, #0x1f
    lsrs r0, r0, #0x1f
    orrs r4, r0
    movs r0, #2
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    movs r0, #4
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    movs r0, #8
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0x10
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0x20
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    movs r0, #0x40
    ands r0, r1
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsrs r1, r1, #7
    lsls r1, r1, #7
    orrs r4, r1
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    ldrb r1, [r5, #4]
    lsls r0, r1, #0x1f
    lsrs r0, r0, #0x1f
    lsls r0, r0, #8
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x1e
    lsrs r0, r0, #0x1f
    lsls r0, r0, #9
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x1d
    lsrs r0, r0, #0x1f
    lsls r0, r0, #0xa
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x1c
    lsrs r0, r0, #0x1f
    lsls r0, r0, #0xb
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x1b
    lsrs r0, r0, #0x1f
    lsls r0, r0, #0xc
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x1a
    lsrs r0, r0, #0x1f
    lsls r0, r0, #0xd
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsls r0, r1, #0x19
    lsrs r0, r0, #0x1f
    lsls r0, r0, #0xe
    orrs r4, r0
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
    lsrs r1, r1, #7
    lsls r1, r1, #0xf
    orrs r4, r1
    lsls r0, r4, #0x10
    lsrs r4, r0, #0x10
lbl_0805f6ea:
    ldrb r0, [r5, #2]
    cmp r0, #0
    beq lbl_0805f6f4
    cmp r0, #1
    bne lbl_0805f714
lbl_0805f6f4:
    ldrh r0, [r6, #4]
    orrs r4, r0
    strh r4, [r6, #4]
    b lbl_0805f722
    .align 2, 0
lbl_0805f6fc: .4byte 0x03000bf0
lbl_0805f700: .4byte 0x030054e4
lbl_0805f704: .4byte 0x03000054
lbl_0805f708: .4byte 0x083602d8
lbl_0805f70c: .4byte 0x0875fde0
lbl_0805f710: .4byte 0x03000055
lbl_0805f714:
    cmp r0, #2
    beq lbl_0805f71c
    cmp r0, #3
    bne lbl_0805f722
lbl_0805f71c:
    ldrh r0, [r6, #6]
    orrs r4, r0
    strh r4, [r6, #6]
lbl_0805f722:
    subs r7, #1
    adds r5, #8
    cmp r7, #0
    beq lbl_0805f72c
    b lbl_0805f614
lbl_0805f72c:
    ldr r0, lbl_0805f740 @ =0x030054e4
    ldr r0, [r0, #4]
    cmp r0, #0
    beq lbl_0805f73a
    movs r0, #1
    bl lock_hatches
lbl_0805f73a:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f740: .4byte 0x030054e4

    thumb_func_start check_play_cutscene_during_transition
check_play_cutscene_during_transition: @ 0x0805f744
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r2, r1, #0x18
    cmp r0, #6
    bhi lbl_0805f7ea
    lsls r0, r0, #2
    ldr r1, lbl_0805f75c @ =lbl_0805f760
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805f75c: .4byte lbl_0805f760
lbl_0805f760: @ jump table
    .4byte lbl_0805f7ea @ case 0
    .4byte lbl_0805f77c @ case 1
    .4byte lbl_0805f7ea @ case 2
    .4byte lbl_0805f7ea @ case 3
    .4byte lbl_0805f7ea @ case 4
    .4byte lbl_0805f7ea @ case 5
    .4byte lbl_0805f7a4 @ case 6
lbl_0805f77c:
    cmp r2, #0x1f
    bne lbl_0805f7ea
    movs r0, #3
    movs r1, #0x1e
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f7ea
    movs r0, #0xa
    bl FadeMusic
    movs r0, #0xa
    bl FadeAllSounds
    ldr r1, lbl_0805f7a0 @ =0x0300007d
    movs r0, #5
    b lbl_0805f7e8
    .align 2, 0
lbl_0805f7a0: .4byte 0x0300007d
lbl_0805f7a4:
    cmp r2, #0x2b
    bne lbl_0805f7c0
    movs r0, #3
    movs r1, #0x43
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f7ea
    ldr r1, lbl_0805f7bc @ =0x0300007d
    movs r0, #0xb
    b lbl_0805f7e8
    .align 2, 0
lbl_0805f7bc: .4byte 0x0300007d
lbl_0805f7c0:
    cmp r2, #0xb
    bne lbl_0805f7ea
    movs r0, #3
    movs r1, #6
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f7ea
    ldr r0, lbl_0805f7f0 @ =0x03005518
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805f7e4
    ldr r0, lbl_0805f7f4 @ =0x00000121
    movs r1, #0xa
    bl SoundFade
lbl_0805f7e4:
    ldr r1, lbl_0805f7f8 @ =0x0300007d
    movs r0, #0xd
lbl_0805f7e8:
    strb r0, [r1]
lbl_0805f7ea:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f7f0: .4byte 0x03005518
lbl_0805f7f4: .4byte 0x00000121
lbl_0805f7f8: .4byte 0x0300007d

    thumb_func_start check_play_cutscene_during_elevator
check_play_cutscene_during_elevator: @ 0x0805f7fc
    push {lr}
    ldr r0, lbl_0805f814 @ =0x03000198
    ldrb r1, [r0, #2]
    adds r2, r0, #0
    cmp r1, #5
    bhi lbl_0805f8ec
    lsls r0, r1, #2
    ldr r1, lbl_0805f818 @ =lbl_0805f81c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805f814: .4byte 0x03000198
lbl_0805f818: .4byte lbl_0805f81c
lbl_0805f81c: @ jump table
    .4byte lbl_0805f8ec @ case 0
    .4byte lbl_0805f8ec @ case 1
    .4byte lbl_0805f834 @ case 2
    .4byte lbl_0805f854 @ case 3
    .4byte lbl_0805f884 @ case 4
    .4byte lbl_0805f8bc @ case 5
lbl_0805f834:
    movs r0, #3
    ldrsb r0, [r2, r0]
    cmp r0, #1
    bne lbl_0805f8ec
    movs r0, #3
    movs r1, #3
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f8ec
    ldr r0, lbl_0805f850 @ =0x0300007d
    movs r1, #4
    b lbl_0805f89c
    .align 2, 0
lbl_0805f850: .4byte 0x0300007d
lbl_0805f854:
    movs r1, #3
    ldrsb r1, [r2, r1]
    movs r0, #1
    rsbs r0, r0, #0
    cmp r1, r0
    bne lbl_0805f8ec
    movs r0, #3
    movs r1, #0x1e
    bl EventFunction
    cmp r0, #0
    beq lbl_0805f8ec
    movs r0, #3
    movs r1, #4
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f8ec
    ldr r0, lbl_0805f880 @ =0x0300007d
    movs r1, #7
    b lbl_0805f89c
    .align 2, 0
lbl_0805f880: .4byte 0x0300007d
lbl_0805f884:
    movs r0, #3
    ldrsb r0, [r2, r0]
    cmp r0, #1
    bne lbl_0805f8ec
    movs r0, #3
    movs r1, #5
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f8ec
    ldr r0, lbl_0805f8b8 @ =0x0300007d
    movs r1, #8
lbl_0805f89c:
    strb r1, [r0]
    movs r0, #2
    bl ColorFadingStart
    movs r0, #0x87
    lsls r0, r0, #1
    movs r1, #0xa
    bl SoundFade
    movs r0, #0xa
    bl FadeMusic
    b lbl_0805f8ec
    .align 2, 0
lbl_0805f8b8: .4byte 0x0300007d
lbl_0805f8bc:
    movs r0, #3
    ldrsb r0, [r2, r0]
    cmp r0, #1
    bne lbl_0805f8ec
    movs r0, #3
    movs r1, #7
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f8ec
    ldr r0, lbl_0805f8f0 @ =0x0300007d
    movs r1, #0xa
    strb r1, [r0]
    movs r0, #2
    bl ColorFadingStart
    movs r0, #0x87
    lsls r0, r0, #1
    movs r1, #0xa
    bl SoundFade
    movs r0, #0xa
    bl FadeMusic
lbl_0805f8ec:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f8f0: .4byte 0x0300007d

    thumb_func_start samus_close_up
samus_close_up: @ 0x0805f8f4
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_0805f918 @ =0x0300019c
    ldrb r1, [r0, #2]
    adds r2, r0, #0
    cmp r1, #0xe
    bls lbl_0805f90c
    b lbl_0805fd3e
lbl_0805f90c:
    lsls r0, r1, #2
    ldr r1, lbl_0805f91c @ =lbl_0805f920
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805f918: .4byte 0x0300019c
lbl_0805f91c: .4byte lbl_0805f920
lbl_0805f920: @ jump table
    .4byte lbl_0805f95c @ case 0
    .4byte lbl_0805f970 @ case 1
    .4byte lbl_0805f97a @ case 2
    .4byte lbl_0805f998 @ case 3
    .4byte lbl_0805f9a4 @ case 4
    .4byte lbl_0805f98c @ case 5
    .4byte lbl_0805faa8 @ case 6
    .4byte lbl_0805f98c @ case 7
    .4byte lbl_0805fbac @ case 8
    .4byte lbl_0805f998 @ case 9
    .4byte lbl_0805fcc4 @ case 10
    .4byte lbl_0805fcd4 @ case 11
    .4byte lbl_0805fcec @ case 12
    .4byte lbl_0805fd14 @ case 13
    .4byte lbl_0805fd24 @ case 14
lbl_0805f95c:
    ldrh r0, [r2]
    cmp r0, #0
    bne lbl_0805f964
    b lbl_0805fd3e
lbl_0805f964:
    movs r5, #1
    movs r0, #1
    movs r1, #4
    bl sub_0806087c
    b lbl_0805fd3e
lbl_0805f970:
    movs r0, #0x10
    movs r1, #0
    movs r2, #7
    movs r3, #1
    b lbl_0805fccc
lbl_0805f97a:
    ldr r0, lbl_0805f988 @ =0x03000088
    ldrh r0, [r0, #4]
    cmp r0, #0x10
    beq lbl_0805f984
    b lbl_0805fd3e
lbl_0805f984:
    movs r5, #1
    b lbl_0805fd3e
    .align 2, 0
lbl_0805f988: .4byte 0x03000088
lbl_0805f98c:
    ldrh r0, [r2]
    cmp r0, #2
    bhi lbl_0805f994
    b lbl_0805fd3e
lbl_0805f994:
    movs r5, #1
    b lbl_0805fd3e
lbl_0805f998:
    ldrh r0, [r2]
    cmp r0, #0x66
    bhi lbl_0805f9a0
    b lbl_0805fd3e
lbl_0805f9a0:
    movs r5, #1
    b lbl_0805fd3e
lbl_0805f9a4:
    ldr r5, lbl_0805fa60 @ =0x08369e20
    ldr r2, lbl_0805fa64 @ =0x0600b940
    movs r6, #0xa0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fa68 @ =0x0202b000
    ldr r2, lbl_0805fa6c @ =0x06000294
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r5, r0
    ldr r2, lbl_0805fa70 @ =0x0600bd40
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fa74 @ =0x0202b040
    ldr r2, lbl_0805fa78 @ =0x060002d4
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fa7c @ =0x0600c140
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fa80 @ =0x0202b080
    ldr r2, lbl_0805fa84 @ =0x06000314
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fa88 @ =0x0600c540
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fa8c @ =0x0202b0c0
    ldr r2, lbl_0805fa90 @ =0x06000354
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #5
    adds r1, r5, r0
    ldr r2, lbl_0805fa94 @ =0x0600c940
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fa98 @ =0x0202b100
    ldr r2, lbl_0805fa9c @ =0x06000394
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xa0
    lsls r0, r0, #5
    adds r5, r5, r0
    ldr r2, lbl_0805faa0 @ =0x0600cd40
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805faa4 @ =0x0202b140
    b lbl_0805fc66
    .align 2, 0
lbl_0805fa60: .4byte 0x08369e20
lbl_0805fa64: .4byte 0x0600b940
lbl_0805fa68: .4byte 0x0202b000
lbl_0805fa6c: .4byte 0x06000294
lbl_0805fa70: .4byte 0x0600bd40
lbl_0805fa74: .4byte 0x0202b040
lbl_0805fa78: .4byte 0x060002d4
lbl_0805fa7c: .4byte 0x0600c140
lbl_0805fa80: .4byte 0x0202b080
lbl_0805fa84: .4byte 0x06000314
lbl_0805fa88: .4byte 0x0600c540
lbl_0805fa8c: .4byte 0x0202b0c0
lbl_0805fa90: .4byte 0x06000354
lbl_0805fa94: .4byte 0x0600c940
lbl_0805fa98: .4byte 0x0202b100
lbl_0805fa9c: .4byte 0x06000394
lbl_0805faa0: .4byte 0x0600cd40
lbl_0805faa4: .4byte 0x0202b140
lbl_0805faa8:
    ldr r5, lbl_0805fb6c @ =0x08369f60
    ldr r2, lbl_0805fb70 @ =0x0600b940
    movs r6, #0xa0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r0, lbl_0805fb74 @ =0x0202b014
    mov r8, r0
    ldr r0, lbl_0805fb78 @ =0x06000294
    mov sb, r0
    str r4, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, sb
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r5, r0
    ldr r2, lbl_0805fb7c @ =0x0600bd40
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    str r4, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, sb
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fb80 @ =0x0600c140
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fb84 @ =0x0202b094
    ldr r2, lbl_0805fb88 @ =0x06000314
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fb8c @ =0x0600c540
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fb90 @ =0x0202b0d4
    ldr r2, lbl_0805fb94 @ =0x06000354
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #5
    adds r1, r5, r0
    ldr r2, lbl_0805fb98 @ =0x0600c940
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fb9c @ =0x0202b114
    ldr r2, lbl_0805fba0 @ =0x06000394
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xa0
    lsls r0, r0, #5
    adds r5, r5, r0
    ldr r2, lbl_0805fba4 @ =0x0600cd40
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fba8 @ =0x0202b154
    b lbl_0805fc66
    .align 2, 0
lbl_0805fb6c: .4byte 0x08369f60
lbl_0805fb70: .4byte 0x0600b940
lbl_0805fb74: .4byte 0x0202b014
lbl_0805fb78: .4byte 0x06000294
lbl_0805fb7c: .4byte 0x0600bd40
lbl_0805fb80: .4byte 0x0600c140
lbl_0805fb84: .4byte 0x0202b094
lbl_0805fb88: .4byte 0x06000314
lbl_0805fb8c: .4byte 0x0600c540
lbl_0805fb90: .4byte 0x0202b0d4
lbl_0805fb94: .4byte 0x06000354
lbl_0805fb98: .4byte 0x0600c940
lbl_0805fb9c: .4byte 0x0202b114
lbl_0805fba0: .4byte 0x06000394
lbl_0805fba4: .4byte 0x0600cd40
lbl_0805fba8: .4byte 0x0202b154
lbl_0805fbac:
    ldr r5, lbl_0805fc78 @ =0x0836a0a0
    ldr r2, lbl_0805fc7c @ =0x0600b940
    movs r6, #0xa0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fc80 @ =0x0202b028
    ldr r2, lbl_0805fc84 @ =0x06000294
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r5, r0
    ldr r2, lbl_0805fc88 @ =0x0600bd40
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fc8c @ =0x0202b068
    ldr r2, lbl_0805fc90 @ =0x060002d4
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fc94 @ =0x0600c140
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fc98 @ =0x0202b0a8
    ldr r2, lbl_0805fc9c @ =0x06000314
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r5, r0
    ldr r2, lbl_0805fca0 @ =0x0600c540
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fca4 @ =0x0202b0e8
    ldr r2, lbl_0805fca8 @ =0x06000354
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0x80
    lsls r0, r0, #5
    adds r1, r5, r0
    ldr r2, lbl_0805fcac @ =0x0600c940
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fcb0 @ =0x0202b128
    ldr r2, lbl_0805fcb4 @ =0x06000394
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r0, #0xa0
    lsls r0, r0, #5
    adds r5, r5, r0
    ldr r2, lbl_0805fcb8 @ =0x0600cd40
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0805fcbc @ =0x0202b168
lbl_0805fc66:
    ldr r2, lbl_0805fcc0 @ =0x060003d4
    str r4, [sp]
    movs r0, #3
    movs r3, #0x14
    bl DMATransfer
    movs r5, #1
    b lbl_0805fd3e
    .align 2, 0
lbl_0805fc78: .4byte 0x0836a0a0
lbl_0805fc7c: .4byte 0x0600b940
lbl_0805fc80: .4byte 0x0202b028
lbl_0805fc84: .4byte 0x06000294
lbl_0805fc88: .4byte 0x0600bd40
lbl_0805fc8c: .4byte 0x0202b068
lbl_0805fc90: .4byte 0x060002d4
lbl_0805fc94: .4byte 0x0600c140
lbl_0805fc98: .4byte 0x0202b0a8
lbl_0805fc9c: .4byte 0x06000314
lbl_0805fca0: .4byte 0x0600c540
lbl_0805fca4: .4byte 0x0202b0e8
lbl_0805fca8: .4byte 0x06000354
lbl_0805fcac: .4byte 0x0600c940
lbl_0805fcb0: .4byte 0x0202b128
lbl_0805fcb4: .4byte 0x06000394
lbl_0805fcb8: .4byte 0x0600cd40
lbl_0805fcbc: .4byte 0x0202b168
lbl_0805fcc0: .4byte 0x060003d4
lbl_0805fcc4:
    movs r0, #0
    movs r1, #0x10
    movs r2, #0
    movs r3, #0x10
lbl_0805fccc:
    bl TransparencyUpdateBLDALPHA
    movs r5, #1
    b lbl_0805fd3e
lbl_0805fcd4:
    ldr r0, lbl_0805fce4 @ =0x03000088
    ldrh r1, [r0, #4]
    movs r0, #0x80
    lsls r0, r0, #5
    cmp r1, r0
    bne lbl_0805fd3e
    ldr r1, lbl_0805fce8 @ =0x0300004a
    b lbl_0805fd00
    .align 2, 0
lbl_0805fce4: .4byte 0x03000088
lbl_0805fce8: .4byte 0x0300004a
lbl_0805fcec:
    ldr r1, lbl_0805fd08 @ =0x0201e000
    ldr r2, lbl_0805fd0c @ =0x06009000
    movs r3, #0x80
    lsls r3, r3, #6
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0805fd10 @ =0x03000c21
lbl_0805fd00:
    movs r0, #0
    strb r0, [r1]
    movs r5, #1
    b lbl_0805fd3e
    .align 2, 0
lbl_0805fd08: .4byte 0x0201e000
lbl_0805fd0c: .4byte 0x06009000
lbl_0805fd10: .4byte 0x03000c21
lbl_0805fd14:
    bl sub_080735b0
    cmp r0, #0
    beq lbl_0805fd3e
    bl sub_08074cf8
    movs r5, #1
    b lbl_0805fd3e
lbl_0805fd24:
    ldr r6, lbl_0805fd50 @ =0x03001606
    ldrh r4, [r6]
    cmp r4, #0
    bne lbl_0805fd3e
    movs r0, #1
    movs r1, #4
    bl sub_0806087c
    movs r1, #0
    strh r4, [r6]
    ldr r0, lbl_0805fd54 @ =0x03000049
    strb r1, [r0]
    movs r5, #5
lbl_0805fd3e:
    adds r0, r5, #0
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805fd50: .4byte 0x03001606
lbl_0805fd54: .4byte 0x03000049

    thumb_func_start sub_0805fd58
sub_0805fd58: @ 0x0805fd58
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_0805fdc0 @ =0x0202aa94
    mov sb, r0
    ldr r1, lbl_0805fdc4 @ =0x0202b000
    mov r8, r1
    movs r0, #0
    ldr r1, lbl_0805fdc8 @ =0x00000fff
    mov ip, r1
    movs r6, #0xf0
    lsls r6, r6, #8
lbl_0805fd72:
    movs r5, #0
    adds r7, r0, #1
    lsls r0, r0, #6
    mov r1, r8
    adds r3, r0, r1
    mov r1, sb
    adds r4, r0, r1
lbl_0805fd80:
    ldrh r0, [r4]
    mov r1, ip
    ands r1, r0
    ldrh r2, [r3]
    adds r0, r6, #0
    ands r0, r2
    orrs r0, r1
    strh r0, [r3]
    ldrh r2, [r3, #0x14]
    adds r0, r6, #0
    ands r0, r2
    orrs r0, r1
    strh r0, [r3, #0x14]
    ldrh r2, [r3, #0x28]
    adds r0, r6, #0
    ands r0, r2
    orrs r1, r0
    strh r1, [r3, #0x28]
    adds r3, #2
    adds r4, #2
    adds r5, #1
    cmp r5, #9
    ble lbl_0805fd80
    adds r0, r7, #0
    cmp r0, #5
    ble lbl_0805fd72
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805fdc0: .4byte 0x0202aa94
lbl_0805fdc4: .4byte 0x0202b000
lbl_0805fdc8: .4byte 0x00000fff

    thumb_func_start sub_0805fdcc
sub_0805fdcc: @ 0x0805fdcc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov sl, r0
    movs r6, #0
    ldr r2, lbl_0805fdf0 @ =0x030013d4
    ldrh r1, [r2, #0x12]
    ldr r0, lbl_0805fdf4 @ =0x030013b8
    ldrh r0, [r0]
    subs r1, r1, r0
    cmp r1, #0
    bge lbl_0805fdf8
    mov r8, r6
    b lbl_0805fe08
    .align 2, 0
lbl_0805fdf0: .4byte 0x030013d4
lbl_0805fdf4: .4byte 0x030013b8
lbl_0805fdf8:
    movs r0, #0xee
    lsls r0, r0, #2
    asrs r3, r1, #2
    mov r8, r3
    cmp r1, r0
    ble lbl_0805fe08
    movs r0, #0xee
    mov r8, r0
lbl_0805fe08:
    movs r1, #2
    add r1, r8
    mov sb, r1
    ldrh r0, [r2, #0x14]
    adds r5, r0, #0
    subs r5, #0x60
    ldr r0, lbl_0805fe24 @ =0x030013ba
    ldrh r0, [r0]
    subs r1, r5, r0
    cmp r1, #0
    bge lbl_0805fe28
    movs r7, #0
    b lbl_0805fe34
    .align 2, 0
lbl_0805fe24: .4byte 0x030013ba
lbl_0805fe28:
    movs r0, #0x9e
    lsls r0, r0, #2
    asrs r7, r1, #2
    cmp r1, r0
    ble lbl_0805fe34
    movs r7, #0x9e
lbl_0805fe34:
    adds r5, r7, #2
    ldr r0, lbl_0805fe60 @ =0x03000108
    ldrb r3, [r0, #4]
    adds r1, r3, #0
    mov ip, r0
    cmp r1, #0xff
    beq lbl_0805fe48
    adds r0, r3, #1
    mov r3, ip
    strb r0, [r3, #4]
lbl_0805fe48:
    ldr r0, lbl_0805fe64 @ =0x0300019c
    ldrb r3, [r0, #2]
    adds r4, r0, #0
    cmp r3, #0x13
    bls lbl_0805fe54
    b lbl_08060314
lbl_0805fe54:
    lsls r0, r3, #2
    ldr r1, lbl_0805fe68 @ =lbl_0805fe6c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805fe60: .4byte 0x03000108
lbl_0805fe64: .4byte 0x0300019c
lbl_0805fe68: .4byte lbl_0805fe6c
lbl_0805fe6c: @ jump table
    .4byte lbl_0805febc @ case 0
    .4byte lbl_0805fee4 @ case 1
    .4byte lbl_0805ff0c @ case 2
    .4byte lbl_0805ff58 @ case 3
    .4byte lbl_0805ff94 @ case 4
    .4byte lbl_08060318 @ case 5
    .4byte lbl_08060318 @ case 6
    .4byte lbl_0805ffc0 @ case 7
    .4byte lbl_0806004c @ case 8
    .4byte lbl_0806008a @ case 9
    .4byte lbl_080600fc @ case 10
    .4byte lbl_080600c8 @ case 11
    .4byte lbl_080600fc @ case 12
    .4byte lbl_08060106 @ case 13
    .4byte lbl_08060168 @ case 14
    .4byte lbl_080601d0 @ case 15
    .4byte lbl_08060238 @ case 16
    .4byte lbl_08060268 @ case 17
    .4byte lbl_0806027c @ case 18
    .4byte lbl_080602f0 @ case 19
lbl_0805febc:
    ldr r0, lbl_0805fedc @ =0x03000bf2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xe
    bne lbl_0805feca
    b lbl_08060318
lbl_0805feca:
    cmp r0, #0xf
    beq lbl_0805fed0
    b lbl_08060314
lbl_0805fed0:
    ldr r0, lbl_0805fee0 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #7
    beq lbl_0805feda
    b lbl_08060314
lbl_0805feda:
    b lbl_08060318
    .align 2, 0
lbl_0805fedc: .4byte 0x03000bf2
lbl_0805fee0: .4byte 0x0300070c
lbl_0805fee4:
    ldr r1, lbl_0805fefc @ =0x030056c4
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0805ff00 @ =0x030013b2
    ldr r2, lbl_0805ff04 @ =0x03000088
    ldrb r0, [r2, #5]
    strh r0, [r1]
    ldr r1, lbl_0805ff08 @ =0x030013b0
    ldrb r0, [r2, #4]
    strh r0, [r1]
    b lbl_08060318
    .align 2, 0
lbl_0805fefc: .4byte 0x030056c4
lbl_0805ff00: .4byte 0x030013b2
lbl_0805ff04: .4byte 0x03000088
lbl_0805ff08: .4byte 0x030013b0
lbl_0805ff0c:
    ldrh r1, [r4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805ff18
    b lbl_08060314
lbl_0805ff18:
    ldr r0, lbl_0805ff34 @ =0x030013b2
    ldrh r2, [r0]
    adds r5, r0, #0
    cmp r2, #0x10
    beq lbl_0805ff38
    adds r0, r2, #1
    strh r0, [r5]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x10
    bls lbl_0805ff3a
    movs r0, #0x10
    strh r0, [r5]
    b lbl_0805ff3a
    .align 2, 0
lbl_0805ff34: .4byte 0x030013b2
lbl_0805ff38:
    adds r6, #1
lbl_0805ff3a:
    ldr r0, lbl_0805ff54 @ =0x030013b0
    ldrh r1, [r0]
    adds r4, r0, #0
    cmp r1, #0
    bne lbl_0805ff46
    b lbl_080602d8
lbl_0805ff46:
    ldrh r0, [r4]
    subs r0, #1
    cmp r0, #0
    blt lbl_0805ff50
    b lbl_080602c8
lbl_0805ff50:
    movs r0, #0
    b lbl_080602c8
    .align 2, 0
lbl_0805ff54: .4byte 0x030013b0
lbl_0805ff58:
    ldr r2, lbl_0805ff78 @ =0x0300000a
    ldr r0, lbl_0805ff7c @ =0x03000088
    ldrh r1, [r0]
    ldr r0, lbl_0805ff80 @ =0x0000feff
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0805ff84 @ =0x040000d4
    ldr r0, lbl_0805ff88 @ =0x06000800
    str r0, [r1]
    ldr r0, lbl_0805ff8c @ =0x0201e000
    str r0, [r1, #4]
    ldr r0, lbl_0805ff90 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_08060318
    .align 2, 0
lbl_0805ff78: .4byte 0x0300000a
lbl_0805ff7c: .4byte 0x03000088
lbl_0805ff80: .4byte 0x0000feff
lbl_0805ff84: .4byte 0x040000d4
lbl_0805ff88: .4byte 0x06000800
lbl_0805ff8c: .4byte 0x0201e000
lbl_0805ff90: .4byte 0x80000400
lbl_0805ff94:
    ldr r1, lbl_0805ffb4 @ =0x000090c0
    ldr r2, lbl_0805ffb8 @ =0x06000800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r1, lbl_0805ffbc @ =0x04000008
    movs r2, #0x82
    lsls r2, r2, #1
    adds r0, r2, #0
    strh r0, [r1]
    b lbl_08060318
    .align 2, 0
lbl_0805ffb4: .4byte 0x000090c0
lbl_0805ffb8: .4byte 0x06000800
lbl_0805ffbc: .4byte 0x04000008
lbl_0805ffc0:
    ldr r1, lbl_0806000c @ =0x0300000a
    ldr r0, lbl_08060010 @ =0x03000088
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08060014 @ =0x0300000e
    movs r0, #0x3f
    strb r0, [r1]
    ldr r1, lbl_08060018 @ =0x0300000f
    movs r0, #0x1e
    strb r0, [r1]
    ldr r1, lbl_0806001c @ =0x03000006
    ldr r3, lbl_08060020 @ =0x0000100d
    adds r0, r3, #0
    strh r0, [r1]
    ldr r1, lbl_08060024 @ =0x0300544c
    ldr r2, lbl_08060028 @ =0x00003f41
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0806002c @ =0x03000108
    movs r1, #0
    mov r3, r8
    strb r3, [r0]
    mov r2, sb
    strb r2, [r0, #1]
    strb r7, [r0, #2]
    strb r5, [r0, #3]
    strb r1, [r0, #4]
    ldr r0, lbl_08060030 @ =0x03000bf2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xe
    bne lbl_08060038
    ldr r0, lbl_08060034 @ =0x00000222
    bl SoundPlay
    b lbl_08060318
    .align 2, 0
lbl_0806000c: .4byte 0x0300000a
lbl_08060010: .4byte 0x03000088
lbl_08060014: .4byte 0x0300000e
lbl_08060018: .4byte 0x0300000f
lbl_0806001c: .4byte 0x03000006
lbl_08060020: .4byte 0x0000100d
lbl_08060024: .4byte 0x0300544c
lbl_08060028: .4byte 0x00003f41
lbl_0806002c: .4byte 0x03000108
lbl_08060030: .4byte 0x03000bf2
lbl_08060034: .4byte 0x00000222
lbl_08060038:
    cmp r0, #0xf
    beq lbl_0806003e
    b lbl_08060318
lbl_0806003e:
    ldr r0, lbl_08060048 @ =0x00000223
    bl SoundPlay
    b lbl_08060318
    .align 2, 0
lbl_08060048: .4byte 0x00000223
lbl_0806004c:
    movs r1, #4
    mov r3, ip
    ldrb r0, [r3, #2]
    cmp r0, #0
    beq lbl_08060068
    cmp r0, #4
    ble lbl_08060060
    subs r0, #4
    strb r0, [r3, #2]
    b lbl_0806006a
lbl_08060060:
    movs r0, #0
    mov r2, ip
    strb r0, [r2, #2]
    b lbl_0806006a
lbl_08060068:
    adds r6, #1
lbl_0806006a:
    mov r3, ip
    ldrb r0, [r3, #3]
    cmp r0, #0x9f
    bhi lbl_08060086
    adds r0, r0, r1
    strb r0, [r3, #3]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xa0
    bhi lbl_08060080
    b lbl_080602e6
lbl_08060080:
    movs r0, #0xa0
    strb r0, [r3, #3]
    b lbl_080602e6
lbl_08060086:
    adds r6, #1
    b lbl_080602e6
lbl_0806008a:
    movs r1, #7
    mov r2, ip
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_080600a6
    cmp r0, #7
    ble lbl_0806009e
    subs r0, #7
    strb r0, [r2]
    b lbl_080600a8
lbl_0806009e:
    movs r0, #0
    mov r3, ip
    strb r0, [r3]
    b lbl_080600a8
lbl_080600a6:
    adds r6, #1
lbl_080600a8:
    mov r2, ip
    ldrb r0, [r2, #1]
    cmp r0, #0xef
    bhi lbl_080600c4
    adds r0, r0, r1
    strb r0, [r2, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf0
    bhi lbl_080600be
    b lbl_080602e6
lbl_080600be:
    movs r0, #0xf0
    strb r0, [r2, #1]
    b lbl_080602e6
lbl_080600c4:
    adds r6, #1
    b lbl_080602e6
lbl_080600c8:
    ldr r0, lbl_080600dc @ =0x03000bf2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xe
    bne lbl_080600e4
    ldr r2, lbl_080600e0 @ =0x03001530
    ldrb r1, [r2, #0xf]
    movs r0, #0x10
    b lbl_080600f0
    .align 2, 0
lbl_080600dc: .4byte 0x03000bf2
lbl_080600e0: .4byte 0x03001530
lbl_080600e4:
    cmp r0, #0xf
    beq lbl_080600ea
    b lbl_08060318
lbl_080600ea:
    ldr r2, lbl_080600f8 @ =0x03001530
    ldrb r1, [r2, #0xf]
    movs r0, #0x20
lbl_080600f0:
    orrs r0, r1
    strb r0, [r2, #0xf]
    b lbl_08060318
    .align 2, 0
lbl_080600f8: .4byte 0x03001530
lbl_080600fc:
    ldrh r0, [r4]
    cmp r0, #5
    bhi lbl_08060104
    b lbl_08060314
lbl_08060104:
    b lbl_08060318
lbl_08060106:
    ldr r4, lbl_0806013c @ =0x03000108
    ldrb r1, [r4, #2]
    subs r1, r7, r1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r4, #3]
    subs r2, r2, r5
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #3
    bl sub_08060374
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0xff
    ands r2, r0
    lsrs r0, r0, #8
    ldrb r1, [r4, #2]
    cmp r1, r7
    bge lbl_08060140
    adds r0, r1, r0
    strb r0, [r4, #2]
    ldrb r0, [r4, #2]
    cmp r0, r7
    ble lbl_08060142
    strb r7, [r4, #2]
    b lbl_08060142
    .align 2, 0
lbl_0806013c: .4byte 0x03000108
lbl_08060140:
    adds r6, #1
lbl_08060142:
    ldr r0, lbl_08060160 @ =0x03000108
    ldrb r1, [r0, #3]
    mov ip, r0
    cmp r1, r5
    ble lbl_08060164
    subs r0, r1, r2
    mov r3, ip
    strb r0, [r3, #3]
    ldrb r0, [r3, #3]
    cmp r0, r5
    blt lbl_0806015a
    b lbl_080602e6
lbl_0806015a:
    strb r5, [r3, #3]
    b lbl_080602e6
    .align 2, 0
lbl_08060160: .4byte 0x03000108
lbl_08060164:
    adds r6, #1
    b lbl_080602e6
lbl_08060168:
    ldr r4, lbl_080601a4 @ =0x03000108
    ldrb r1, [r4]
    mov r0, r8
    subs r1, r0, r1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r4, #1]
    mov r3, sb
    subs r2, r2, r3
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #9
    bl sub_08060374
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r2, #0xff
    ands r2, r0
    lsrs r0, r0, #8
    ldrb r1, [r4]
    cmp r1, r8
    bge lbl_080601a8
    adds r0, r1, r0
    strb r0, [r4]
    ldrb r0, [r4]
    cmp r0, r8
    ble lbl_080601aa
    mov r0, r8
    strb r0, [r4]
    b lbl_080601aa
    .align 2, 0
lbl_080601a4: .4byte 0x03000108
lbl_080601a8:
    adds r6, #1
lbl_080601aa:
    ldr r0, lbl_080601c8 @ =0x03000108
    ldrb r1, [r0, #1]
    mov ip, r0
    cmp r1, sb
    ble lbl_080601cc
    subs r0, r1, r2
    mov r1, ip
    strb r0, [r1, #1]
    ldrb r0, [r1, #1]
    cmp r0, sb
    blt lbl_080601c2
    b lbl_080602e6
lbl_080601c2:
    mov r2, sb
    strb r2, [r1, #1]
    b lbl_080602e6
    .align 2, 0
lbl_080601c8: .4byte 0x03000108
lbl_080601cc:
    adds r6, #1
    b lbl_080602e6
lbl_080601d0:
    ldr r3, lbl_08060210 @ =0x0300000a
    ldr r2, lbl_08060214 @ =0x03000088
    ldrh r1, [r2]
    ldr r0, lbl_08060218 @ =0x0000feff
    ands r0, r1
    strh r0, [r3]
    ldr r1, lbl_0806021c @ =0x0300000f
    ldrb r0, [r2, #8]
    strb r0, [r1]
    ldr r1, lbl_08060220 @ =0x0300000e
    ldrb r0, [r2, #7]
    strb r0, [r1]
    ldr r3, lbl_08060224 @ =0x03000006
    ldr r0, lbl_08060228 @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0806022c @ =0x030013b0
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r3]
    ldr r1, lbl_08060230 @ =0x0300544c
    ldrh r0, [r2, #2]
    strh r0, [r1]
    ldr r1, lbl_08060234 @ =0x03000108
    movs r2, #0
    strb r2, [r1]
    movs r0, #0xf0
    strb r0, [r1, #1]
    strb r2, [r1, #2]
    movs r0, #0xa0
    strb r0, [r1, #3]
    b lbl_08060318
    .align 2, 0
lbl_08060210: .4byte 0x0300000a
lbl_08060214: .4byte 0x03000088
lbl_08060218: .4byte 0x0000feff
lbl_0806021c: .4byte 0x0300000f
lbl_08060220: .4byte 0x0300000e
lbl_08060224: .4byte 0x03000006
lbl_08060228: .4byte 0x030013b2
lbl_0806022c: .4byte 0x030013b0
lbl_08060230: .4byte 0x0300544c
lbl_08060234: .4byte 0x03000108
lbl_08060238:
    ldr r1, lbl_08060254 @ =0x040000d4
    ldr r0, lbl_08060258 @ =0x0201e000
    str r0, [r1]
    ldr r0, lbl_0806025c @ =0x06000800
    str r0, [r1, #4]
    ldr r0, lbl_08060260 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xcc
    ldr r0, lbl_08060264 @ =0x03000088
    ldrh r0, [r0, #0xa]
    strh r0, [r1]
    b lbl_08060318
    .align 2, 0
lbl_08060254: .4byte 0x040000d4
lbl_08060258: .4byte 0x0201e000
lbl_0806025c: .4byte 0x06000800
lbl_08060260: .4byte 0x80000400
lbl_08060264: .4byte 0x03000088
lbl_08060268:
    ldr r0, lbl_08060274 @ =0x0300000a
    ldr r1, lbl_08060278 @ =0x03000088
    ldrh r1, [r1]
    strh r1, [r0]
    b lbl_08060318
    .align 2, 0
lbl_08060274: .4byte 0x0300000a
lbl_08060278: .4byte 0x03000088
lbl_0806027c:
    ldrh r1, [r4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08060314
    ldr r0, lbl_080602a0 @ =0x030013b2
    ldr r1, lbl_080602a4 @ =0x03000088
    ldrh r4, [r0]
    adds r3, r4, #0
    ldrb r2, [r1, #5]
    adds r5, r0, #0
    cmp r3, r2
    beq lbl_080602b2
    cmp r3, r2
    bls lbl_080602a8
    subs r0, r4, #1
    strh r0, [r5]
    b lbl_080602b4
    .align 2, 0
lbl_080602a0: .4byte 0x030013b2
lbl_080602a4: .4byte 0x03000088
lbl_080602a8:
    cmp r3, r2
    bhs lbl_080602b4
    adds r0, r4, #1
    strh r0, [r5]
    b lbl_080602b4
lbl_080602b2:
    adds r6, #1
lbl_080602b4:
    ldr r0, lbl_080602cc @ =0x030013b0
    ldrh r2, [r0]
    adds r3, r2, #0
    ldrb r1, [r1, #4]
    adds r4, r0, #0
    cmp r3, r1
    beq lbl_080602d8
    cmp r3, r1
    bls lbl_080602d0
    subs r0, r2, #1
lbl_080602c8:
    strh r0, [r4]
    b lbl_080602da
    .align 2, 0
lbl_080602cc: .4byte 0x030013b0
lbl_080602d0:
    cmp r3, r1
    bhs lbl_080602da
    adds r0, r2, #1
    b lbl_080602c8
lbl_080602d8:
    adds r6, #1
lbl_080602da:
    ldr r0, lbl_080602ec @ =0x03000006
    ldrh r1, [r5]
    lsls r1, r1, #8
    ldrh r2, [r4]
    orrs r1, r2
    strh r1, [r0]
lbl_080602e6:
    asrs r6, r6, #1
    b lbl_08060314
    .align 2, 0
lbl_080602ec: .4byte 0x03000006
lbl_080602f0:
    ldr r0, lbl_08060354 @ =0x03000bf2
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0xf
    bne lbl_08060302
    ldr r1, lbl_08060358 @ =0x0300070c
    movs r0, #8
    strb r0, [r1, #0xf]
lbl_08060302:
    movs r1, #0
    movs r0, #0
    strh r0, [r2, #0xc]
    ldr r0, lbl_0806035c @ =0x03000049
    strb r1, [r0]
    ldr r0, lbl_08060360 @ =0x030056c4
    strb r1, [r0]
    movs r3, #1
    mov sl, r3
lbl_08060314:
    cmp r6, #0
    beq lbl_08060328
lbl_08060318:
    ldr r0, lbl_08060364 @ =0x0300019c
    ldrb r1, [r0, #2]
    adds r1, #1
    movs r2, #0
    strb r1, [r0, #2]
    strh r2, [r0]
    ldr r0, lbl_08060368 @ =0x03000108
    mov ip, r0
lbl_08060328:
    ldr r2, lbl_0806036c @ =0x03005448
    mov r3, ip
    ldrb r1, [r3]
    lsls r1, r1, #8
    ldrb r0, [r3, #1]
    orrs r0, r1
    strh r0, [r2]
    ldr r2, lbl_08060370 @ =0x0300544a
    ldrb r1, [r3, #2]
    lsls r1, r1, #8
    ldrb r0, [r3, #3]
    orrs r0, r1
    strh r0, [r2]
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
lbl_08060354: .4byte 0x03000bf2
lbl_08060358: .4byte 0x0300070c
lbl_0806035c: .4byte 0x03000049
lbl_08060360: .4byte 0x030056c4
lbl_08060364: .4byte 0x0300019c
lbl_08060368: .4byte 0x03000108
lbl_0806036c: .4byte 0x03005448
lbl_08060370: .4byte 0x0300544a

    thumb_func_start sub_08060374
sub_08060374: @ 0x08060374
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r7, r4, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r3, r1, #0
    lsls r2, r2, #0x18
    lsrs r0, r2, #0x18
    adds r5, r0, #0
    movs r6, #0
    movs r2, #0
    cmp r1, r0
    bls lbl_080603a0
    subs r1, r1, r4
    cmp r0, r1
    ble lbl_0806039c
    subs r0, r0, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_0806039c:
    adds r6, r4, #0
    b lbl_080603b8
lbl_080603a0:
    cmp r3, r5
    bhs lbl_080603b4
    subs r0, r5, r4
    cmp r3, r0
    ble lbl_080603b0
    subs r0, r3, r0
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
lbl_080603b0:
    adds r2, r4, #0
    b lbl_080603b8
lbl_080603b4:
    adds r2, r7, #0
    adds r6, r2, #0
lbl_080603b8:
    lsls r0, r6, #8
    orrs r0, r2
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start make_background_flash
make_background_flash: @ 0x080603c4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r1, r0, #0
    cmp r0, #1
    beq lbl_080603f4
    cmp r0, #1
    bgt lbl_080603da
    cmp r0, #0
    beq lbl_080603e4
    b lbl_08060416
lbl_080603da:
    cmp r1, #2
    beq lbl_080603ec
    cmp r1, #3
    beq lbl_08060410
    b lbl_08060416
lbl_080603e4:
    movs r0, #2
    bl start_special_background_effect
    b lbl_08060416
lbl_080603ec:
    movs r0, #3
    bl start_special_background_effect
    b lbl_08060416
lbl_080603f4:
    ldr r1, lbl_0806040c @ =0x030056c4
    ldrb r0, [r1, #3]
    ldrb r1, [r1, #2]
    movs r2, #2
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    movs r0, #1
    movs r1, #7
    bl sub_0806087c
    b lbl_08060416
    .align 2, 0
lbl_0806040c: .4byte 0x030056c4
lbl_08060410:
    movs r0, #6
    bl start_special_background_effect
lbl_08060416:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0806041c
sub_0806041c: @ 0x0806041c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r2, lbl_08060430 @ =0x0300019c
    ldrb r0, [r2, #3]
    cmp r0, #0
    bne lbl_0806042c
    strb r1, [r2, #3]
lbl_0806042c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060430: .4byte 0x0300019c

    thumb_func_start sub_08060434
sub_08060434: @ 0x08060434
    push {r4, lr}
    ldr r4, lbl_08060478 @ =0x0300019c
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    ldrb r1, [r4, #3]
    cmp r1, #0
    beq lbl_080604d8
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080604d4
    ldr r2, [r4, #8]
    cmp r2, #0
    beq lbl_080604d8
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_080604d8
    bl _call_via_r2
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08060468
    movs r0, #0
    strh r0, [r4]
lbl_08060468:
    subs r0, r1, #1
    cmp r0, #4
    bhi lbl_080604d8
    lsls r0, r0, #2
    ldr r1, lbl_0806047c @ =lbl_08060480
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08060478: .4byte 0x0300019c
lbl_0806047c: .4byte lbl_08060480
lbl_08060480: @ jump table
    .4byte lbl_08060494 @ case 0
    .4byte lbl_080604a4 @ case 1
    .4byte lbl_080604b4 @ case 2
    .4byte lbl_080604d8 @ case 3
    .4byte lbl_080604c4 @ case 4
lbl_08060494:
    ldr r1, lbl_080604a0 @ =0x0300019c
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_080604d8
    .align 2, 0
lbl_080604a0: .4byte 0x0300019c
lbl_080604a4:
    ldr r1, lbl_080604b0 @ =0x0300019c
    ldrb r0, [r1, #2]
    subs r0, #1
    strb r0, [r1, #2]
    b lbl_080604d8
    .align 2, 0
lbl_080604b0: .4byte 0x0300019c
lbl_080604b4:
    ldr r1, lbl_080604c0 @ =0x0300019c
    ldrb r0, [r1, #2]
    subs r0, #3
    strb r0, [r1, #2]
    b lbl_080604d8
    .align 2, 0
lbl_080604c0: .4byte 0x0300019c
lbl_080604c4:
    ldr r0, lbl_080604d0 @ =0x0300019c
    movs r2, #0
    movs r1, #0x80
    strb r1, [r0, #3]
    strb r2, [r0, #2]
    b lbl_080604d8
    .align 2, 0
lbl_080604d0: .4byte 0x0300019c
lbl_080604d4:
    bl sub_080604e0
lbl_080604d8:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080604e0
sub_080604e0: @ 0x080604e0
    push {lr}
    movs r3, #0
    ldr r0, lbl_080604f8 @ =0x0300019c
    ldrb r1, [r0, #3]
    adds r2, r0, #0
    cmp r1, #6
    beq lbl_08060528
    cmp r1, #6
    bgt lbl_080604fc
    cmp r1, #4
    beq lbl_08060518
    b lbl_08060532
    .align 2, 0
lbl_080604f8: .4byte 0x0300019c
lbl_080604fc:
    cmp r1, #0xa
    bgt lbl_08060532
    cmp r1, #9
    blt lbl_08060532
    ldr r1, lbl_08060514 @ =0x03000130
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08060532
    ldrb r0, [r1, #0x10]
    cmp r0, #0
    bne lbl_08060532
    b lbl_08060530
    .align 2, 0
lbl_08060514: .4byte 0x03000130
lbl_08060518:
    ldr r1, lbl_08060524 @ =0x03001606
    movs r3, #0xb4
    lsls r3, r3, #1
    adds r0, r3, #0
    strh r0, [r1]
    b lbl_08060536
    .align 2, 0
lbl_08060524: .4byte 0x03001606
lbl_08060528:
    ldrh r0, [r2]
    cmp r0, #0x3c
    bls lbl_08060532
    b lbl_08060536
lbl_08060530:
    movs r3, #1
lbl_08060532:
    cmp r3, #0
    beq lbl_08060552
lbl_08060536:
    movs r0, #0
    strb r0, [r2, #2]
    strh r0, [r2]
    ldr r1, lbl_08060558 @ =0x083602e8
    ldrb r0, [r2, #3]
    lsls r0, r0, #3
    adds r1, #4
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r2, #8]
    ldrb r1, [r2, #3]
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #3]
lbl_08060552:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060558: .4byte 0x083602e8

    thumb_func_start LoadFirstRoom
LoadFirstRoom: @ 0x0806055c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_0806058c @ =0x0300019c
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080605c4
    movs r4, #0
lbl_0806056e:
    movs r0, #0x1f
    ands r0, r4
    cmp r0, #0
    bne lbl_08060594
    ldr r1, lbl_08060590 @ =0x03000050
    asrs r0, r4, #5
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    movs r0, #1
    rsbs r0, r0, #0
    cmp r1, r0
    bne lbl_08060594
    adds r4, #0x20
    b lbl_080605be
    .align 2, 0
lbl_0806058c: .4byte 0x0300019c
lbl_08060590: .4byte 0x03000050
lbl_08060594:
    lsls r0, r4, #0x18
    lsrs r5, r0, #0x18
    movs r0, #0
    adds r1, r5, #0
    bl sub_0806087c
    cmp r0, #0
    beq lbl_080605be
    ldr r1, lbl_080605d4 @ =0x083602e8
    lsls r0, r4, #3
    adds r0, r0, r1
    ldr r1, lbl_080605d8 @ =0x03000054
    ldrb r0, [r0, #1]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080605be
    adds r0, r5, #0
    bl sub_08060760
    cmp r0, #0
    bne lbl_080605c4
lbl_080605be:
    adds r4, #1
    cmp r4, #0x1f
    ble lbl_0806056e
lbl_080605c4:
    ldr r0, lbl_080605dc @ =0x0300019c
    ldrb r7, [r0, #4]
    cmp r7, #4
    beq lbl_080605e0
    cmp r7, #7
    bne lbl_080605d2
    b lbl_0806071c
lbl_080605d2:
    b lbl_08060746
    .align 2, 0
lbl_080605d4: .4byte 0x083602e8
lbl_080605d8: .4byte 0x03000054
lbl_080605dc: .4byte 0x0300019c
lbl_080605e0:
    ldr r0, lbl_080606b8 @ =0x03000bf0
    movs r6, #0
    ldrsb r6, [r0, r6]
    cmp r6, #0
    beq lbl_080605ec
    b lbl_08060746
lbl_080605ec:
    ldr r0, lbl_080606bc @ =0x03000049
    movs r1, #1
    mov r8, r1
    strb r1, [r0]
    ldr r0, lbl_080606c0 @ =0x03000058
    strb r6, [r0]
    movs r0, #1
    movs r1, #0
    bl PlayMusic
    movs r0, #0x36
    movs r1, #1
    bl InsertMusicAndQueueCurrent
    movs r0, #0x1e
    bl SamusSetPose
    ldr r2, lbl_080606c4 @ =0x030013d4
    ldr r0, lbl_080606c8 @ =0x03001602
    ldr r3, lbl_080606cc @ =0x0000077f
    adds r1, r3, #0
    strh r1, [r0]
    movs r5, #0
    strh r1, [r2, #0x14]
    ldr r4, lbl_080606d0 @ =0x06009000
    ldr r2, lbl_080606d4 @ =0x0201e000
    movs r3, #0x80
    lsls r3, r3, #6
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl DMATransfer
    ldr r0, lbl_080606d8 @ =0x083679e4
    adds r1, r4, #0
    bl CallLZ77UncompVRAM
    ldr r0, lbl_080606dc @ =0x0836b620
    ldr r1, lbl_080606e0 @ =0x0202a800
    bl CallLZ77UncompWRAM
    ldr r0, lbl_080606e4 @ =0x0836bc24
    ldr r1, lbl_080606e8 @ =0x0202b000
    bl CallLZ77UncompWRAM
    ldr r1, lbl_080606ec @ =0x040000d4
    ldr r0, lbl_080606f0 @ =0x08367924
    str r0, [r1]
    ldr r0, lbl_080606f4 @ =0x050000e0
    str r0, [r1, #4]
    ldr r0, lbl_080606f8 @ =0x80000060
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    bl sub_0805fd58
    ldr r1, lbl_080606fc @ =0x030000bc
    movs r0, #0x41
    strb r0, [r1, #1]
    strb r5, [r1, #0x18]
    ldr r0, lbl_08060700 @ =0x030013b4
    strh r6, [r0]
    ldr r0, lbl_08060704 @ =0x030013b6
    strh r6, [r0]
    ldr r4, lbl_08060708 @ =0x03000088
    ldr r1, lbl_0806070c @ =0x030056c4
    strb r7, [r1, #3]
    strb r7, [r4, #4]
    movs r0, #0xc
    strb r0, [r1, #2]
    strb r0, [r4, #5]
    ldr r1, lbl_08060710 @ =0x04000052
    lsls r0, r0, #8
    orrs r7, r0
    strh r7, [r1]
    movs r0, #4
    movs r1, #0xc
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    ldr r1, lbl_08060714 @ =0x00003e41
    strh r1, [r4, #2]
    movs r0, #0
    bl TransparencyUpdateBLDCNT
    movs r0, #8
    strh r0, [r4, #0xa]
    strh r0, [r4, #0x12]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #1
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    movs r0, #8
    bl ColorFadingStart
    ldr r0, lbl_08060718 @ =0x0300004a
    mov r3, r8
    strb r3, [r0]
    b lbl_08060746
    .align 2, 0
lbl_080606b8: .4byte 0x03000bf0
lbl_080606bc: .4byte 0x03000049
lbl_080606c0: .4byte 0x03000058
lbl_080606c4: .4byte 0x030013d4
lbl_080606c8: .4byte 0x03001602
lbl_080606cc: .4byte 0x0000077f
lbl_080606d0: .4byte 0x06009000
lbl_080606d4: .4byte 0x0201e000
lbl_080606d8: .4byte 0x083679e4
lbl_080606dc: .4byte 0x0836b620
lbl_080606e0: .4byte 0x0202a800
lbl_080606e4: .4byte 0x0836bc24
lbl_080606e8: .4byte 0x0202b000
lbl_080606ec: .4byte 0x040000d4
lbl_080606f0: .4byte 0x08367924
lbl_080606f4: .4byte 0x050000e0
lbl_080606f8: .4byte 0x80000060
lbl_080606fc: .4byte 0x030000bc
lbl_08060700: .4byte 0x030013b4
lbl_08060704: .4byte 0x030013b6
lbl_08060708: .4byte 0x03000088
lbl_0806070c: .4byte 0x030056c4
lbl_08060710: .4byte 0x04000052
lbl_08060714: .4byte 0x00003e41
lbl_08060718: .4byte 0x0300004a
lbl_0806071c:
    ldr r0, lbl_08060754 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08060746
    ldr r4, lbl_08060758 @ =0x03000088
    strb r0, [r4, #5]
    movs r0, #0x10
    strb r0, [r4, #4]
    movs r1, #0
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    ldr r2, lbl_0806075c @ =0x04000052
    ldrb r1, [r4, #5]
    lsls r1, r1, #8
    ldrb r0, [r4, #4]
    orrs r0, r1
    strh r0, [r2]
lbl_08060746:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060754: .4byte 0x03000bf0
lbl_08060758: .4byte 0x03000088
lbl_0806075c: .4byte 0x04000052

    thumb_func_start sub_08060760
sub_08060760: @ 0x08060760
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    movs r2, #0
    cmp r1, #6
    beq lbl_080607d0
    cmp r1, #6
    bgt lbl_08060776
    cmp r1, #4
    beq lbl_0806077c
    b lbl_080607ea
lbl_08060776:
    cmp r1, #7
    beq lbl_080607e0
    b lbl_080607ea
lbl_0806077c:
    ldr r0, lbl_080607b8 @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080607ea
    ldr r0, lbl_080607bc @ =0x03000056
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080607ea
    ldr r0, lbl_080607c0 @ =0x03000c1d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080607ea
    ldr r0, lbl_080607c4 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_080607ea
    ldr r0, lbl_080607c8 @ =0x03000000
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080607ea
    ldr r0, lbl_080607cc @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080607ea
    movs r2, #1
    b lbl_080607ee
    .align 2, 0
lbl_080607b8: .4byte 0x03000055
lbl_080607bc: .4byte 0x03000056
lbl_080607c0: .4byte 0x03000c1d
lbl_080607c4: .4byte 0x03000c75
lbl_080607c8: .4byte 0x03000000
lbl_080607cc: .4byte 0x030013d2
lbl_080607d0:
    ldr r0, lbl_080607dc @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_080607ea
    movs r2, #1
    b lbl_080607ee
    .align 2, 0
lbl_080607dc: .4byte 0x03000055
lbl_080607e0:
    ldr r0, lbl_080607f8 @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_080607ea
    movs r2, #1
lbl_080607ea:
    cmp r2, #0
    beq lbl_080607f2
lbl_080607ee:
    ldr r0, lbl_080607fc @ =0x0300019c
    strb r1, [r0, #4]
lbl_080607f2:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_080607f8: .4byte 0x03000055
lbl_080607fc: .4byte 0x0300019c

    thumb_func_start sub_08060800
sub_08060800: @ 0x08060800
    push {lr}
    ldr r0, lbl_08060820 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0806081c
    ldr r1, lbl_08060824 @ =0x0300019c
    strb r0, [r1, #2]
    ldrb r0, [r1, #4]
    cmp r0, #0
    beq lbl_0806081c
    bl sub_0806041c
lbl_0806081c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060820: .4byte 0x03000bf0
lbl_08060824: .4byte 0x0300019c

    thumb_func_start update_animated_palette_after_transition_or_reload
update_animated_palette_after_transition_or_reload: @ 0x08060828
    push {lr}
    ldr r0, lbl_08060850 @ =0x03000bf0
    movs r1, #0
    ldrsb r1, [r0, r1]
    cmp r1, #0
    beq lbl_08060868
    ldr r0, lbl_08060854 @ =0x030056f4
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08060872
    ldr r1, lbl_08060858 @ =0x040000d4
    ldr r0, lbl_0806085c @ =0x020355e0
    str r0, [r1]
    ldr r0, lbl_08060860 @ =0x050001e0
    str r0, [r1, #4]
    ldr r0, lbl_08060864 @ =0x80000010
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_08060872
    .align 2, 0
lbl_08060850: .4byte 0x03000bf0
lbl_08060854: .4byte 0x030056f4
lbl_08060858: .4byte 0x040000d4
lbl_0806085c: .4byte 0x020355e0
lbl_08060860: .4byte 0x050001e0
lbl_08060864: .4byte 0x80000010
lbl_08060868:
    ldr r0, lbl_08060878 @ =0x0300019c
    strb r1, [r0, #2]
    strh r1, [r0]
    bl sub_0805e424
lbl_08060872:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060878: .4byte 0x0300019c

    thumb_func_start sub_0806087c
sub_0806087c: @ 0x0806087c
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x18
    movs r0, #0xf8
    lsls r0, r0, #0x15
    ands r0, r1
    lsrs r0, r0, #0x18
    lsrs r1, r1, #0x1d
    movs r4, #0
    ldr r2, lbl_080608b8 @ =0x03000050
    lsls r1, r1, #2
    adds r1, r1, r2
    movs r3, #1
    lsls r3, r0
    ldr r2, [r1]
    adds r0, r2, #0
    ands r0, r3
    cmp r0, #0
    bne lbl_080608ae
    movs r4, #1
    cmp r5, #0
    beq lbl_080608ae
    orrs r2, r3
    str r2, [r1]
lbl_080608ae:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080608b8: .4byte 0x03000050

    thumb_func_start EventFunction
EventFunction: @ 0x080608bc
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    movs r2, #0xff
    lsls r2, r2, #0x18
    adds r0, r1, r2
    lsrs r0, r0, #0x18
    cmp r0, #0x4d
    bls lbl_080608d6
    movs r0, #0
    b lbl_08060922
lbl_080608d6:
    ldr r5, lbl_08060904 @ =0x02037e00
    lsrs r0, r1, #0x1d
    lsls r0, r0, #2
    adds r5, r0, r5
    movs r0, #0x1f
    ands r3, r0
    movs r6, #1
    adds r2, r6, #0
    lsls r2, r3
    ldr r1, [r5]
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_080608f4
    movs r0, #1
lbl_080608f4:
    cmp r4, #1
    beq lbl_08060914
    cmp r4, #1
    bgt lbl_08060908
    cmp r4, #0
    beq lbl_0806090e
    b lbl_08060922
    .align 2, 0
lbl_08060904: .4byte 0x02037e00
lbl_08060908:
    cmp r4, #2
    beq lbl_0806091c
    b lbl_08060922
lbl_0806090e:
    bics r1, r2
    str r1, [r5]
    b lbl_08060922
lbl_08060914:
    orrs r1, r2
    str r1, [r5]
    eors r0, r6
    b lbl_08060922
lbl_0806091c:
    eors r1, r2
    str r1, [r5]
    eors r0, r6
lbl_08060922:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start check_play_room_music_track
check_play_room_music_track: @ 0x08060928
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r2, lbl_0806095c @ =0x03000030
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
    ldr r0, lbl_08060964 @ =0x03000bf1
    ldrb r0, [r0]
    adds r5, r2, #0
    cmp r0, #2
    beq lbl_08060968
    cmp r0, #6
    beq lbl_08060976
    b lbl_08060994
    .align 2, 0
lbl_0806095c: .4byte 0x03000030
lbl_08060960: .4byte 0x0875fac4
lbl_08060964: .4byte 0x03000bf1
lbl_08060968:
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x5f
    bne lbl_08060994
    movs r0, #1
    strb r0, [r5, #4]
    b lbl_08060994
lbl_08060976:
    ldr r0, lbl_080609d0 @ =0x03001530
    ldrb r2, [r0, #0x12]
    cmp r2, #1
    bne lbl_08060994
    ldr r0, lbl_080609d4 @ =0x030001a8
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
    ldr r1, lbl_080609d8 @ =0x0300007d
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
    ldr r0, lbl_080609e0 @ =0x0300550e
    strb r4, [r0]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080609d0: .4byte 0x03001530
lbl_080609d4: .4byte 0x030001a8
lbl_080609d8: .4byte 0x0300007d
lbl_080609dc: .4byte 0x0836bdac
lbl_080609e0: .4byte 0x0300550e

    thumb_func_start check_play_loading_jingle
check_play_loading_jingle: @ 0x080609e4
    push {lr}
    ldr r1, lbl_08060a2c @ =0x03000030
    ldr r0, lbl_08060a30 @ =0x030000bc
    ldrh r0, [r0, #0x16]
    strh r0, [r1]
    ldr r0, lbl_08060a34 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08060a28
    ldr r0, lbl_08060a38 @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08060a28
    ldr r0, lbl_08060a3c @ =0x03000c1d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08060a28
    bl sub_08003eb8
    ldr r0, lbl_08060a40 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x2c
    bne lbl_08060a28
    ldr r1, lbl_08060a44 @ =0x03000049
    movs r0, #1
    strb r0, [r1]
    movs r0, #0x36
    movs r1, #1
    bl InsertMusicAndQueueCurrent
lbl_08060a28:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060a2c: .4byte 0x03000030
lbl_08060a30: .4byte 0x030000bc
lbl_08060a34: .4byte 0x03000c75
lbl_08060a38: .4byte 0x030013d2
lbl_08060a3c: .4byte 0x03000c1d
lbl_08060a40: .4byte 0x030013d4
lbl_08060a44: .4byte 0x03000049

    thumb_func_start sub_08060a48
sub_08060a48: @ 0x08060a48
    push {lr}
    ldr r2, lbl_08060a6c @ =0x03000030
    movs r0, #0
    strb r0, [r2, #2]
    ldr r1, lbl_08060a70 @ =0x03000bf0
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
lbl_08060a6c: .4byte 0x03000030
lbl_08060a70: .4byte 0x03000bf0
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
    ldr r0, lbl_08060aa8 @ =0x03000030
    ldr r1, lbl_08060aac @ =0x03000bf0
    ldrb r1, [r1]
    strb r1, [r0, #2]
    b lbl_08060ab4
    .align 2, 0
lbl_08060aa8: .4byte 0x03000030
lbl_08060aac: .4byte 0x03000bf0
lbl_08060ab0:
    ldrb r0, [r3]
    strb r0, [r2, #2]
lbl_08060ab4:
    pop {r0}
    bx r0

    thumb_func_start update_music_after_unpause
update_music_after_unpause: @ 0x08060ab8
    push {lr}
    ldr r0, lbl_08060ad4 @ =0x03000030
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
lbl_08060ad4: .4byte 0x03000030
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

    thumb_func_start sub_08060b14
sub_08060b14: @ 0x08060b14
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr

    thumb_func_start start_new_demo
start_new_demo: @ 0x08060b20
    push {lr}
    ldr r3, lbl_08060b6c @ =0x03000038
    ldrb r2, [r3, #3]
    movs r1, #0xf
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3, #3]
    ldrb r2, [r3, #2]
    ands r1, r2
    cmp r1, #0
    bne lbl_08060b5e
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    movs r1, #1
    orrs r0, r1
    strb r0, [r3, #2]
    ldr r2, lbl_08060b70 @ =0x03000c77
    ldr r0, lbl_08060b74 @ =0x03000002
    ldrh r1, [r0]
    lsrs r1, r1, #8
    ldrb r2, [r2]
    adds r1, r1, r2
    movs r0, #1
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    movs r1, #8
    ands r0, r1
    strb r0, [r3]
lbl_08060b5e:
    ldr r1, lbl_08060b78 @ =0x030013d2
    movs r0, #3
    strb r0, [r1]
    bl init_new_demo
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060b6c: .4byte 0x03000038
lbl_08060b70: .4byte 0x03000c77
lbl_08060b74: .4byte 0x03000002
lbl_08060b78: .4byte 0x030013d2

    thumb_func_start init_new_demo
init_new_demo: @ 0x08060b7c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r0, lbl_08060b9c @ =sub_08060b14
    bl CallbackSetVBlank
    ldr r5, lbl_08060ba0 @ =0x03000038
    ldrb r0, [r5, #3]
    movs r1, #0xf0
    ands r1, r0
    cmp r1, #0
    beq lbl_08060ba4
    ldrb r7, [r5]
    b lbl_08060bb4
    .align 2, 0
lbl_08060b9c: .4byte sub_08060b14
lbl_08060ba0: .4byte 0x03000038
lbl_08060ba4:
    ldrb r0, [r5]
    cmp r0, #0xf
    bls lbl_08060bac
    strb r1, [r5]
lbl_08060bac:
    ldr r1, lbl_08060c0c @ =0x08363ce8
    ldrb r0, [r5]
    adds r0, r0, r1
    ldrb r7, [r0]
lbl_08060bb4:
    movs r0, #1
    bl sub_0807584c
    movs r0, #0
    adds r1, r7, #0
    bl load_demo_ram_values
    ldr r0, lbl_08060c10 @ =0x030013d2
    mov sb, r0
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_08060bfe
    ldr r4, lbl_08060c14 @ =0x08363be8
    lsls r5, r7, #4
    adds r6, r5, r4
    ldr r1, [r6]
    ldr r2, lbl_08060c18 @ =0x03004fca
    ldrh r3, [r6, #4]
    movs r0, #0x10
    mov r8, r0
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    adds r4, #8
    adds r5, r5, r4
    ldr r1, [r5]
    ldr r2, lbl_08060c1c @ =0x030051ca
    ldrh r3, [r6, #0xc]
    mov r0, r8
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #2
    mov r1, sb
    strb r0, [r1]
lbl_08060bfe:
    cmp r7, #7
    beq lbl_08060c44
    cmp r7, #7
    bgt lbl_08060c20
    cmp r7, #6
    beq lbl_08060c2a
    b lbl_08060c66
    .align 2, 0
lbl_08060c0c: .4byte 0x08363ce8
lbl_08060c10: .4byte 0x030013d2
lbl_08060c14: .4byte 0x08363be8
lbl_08060c18: .4byte 0x03004fca
lbl_08060c1c: .4byte 0x030051ca
lbl_08060c20:
    cmp r7, #0xa
    beq lbl_08060c56
    cmp r7, #0xb
    beq lbl_08060c60
    b lbl_08060c66
lbl_08060c2a:
    movs r0, #1
    movs r1, #0x2e
    bl EventFunction
    movs r0, #1
    movs r1, #0x16
    bl EventFunction
    movs r0, #1
    movs r1, #0x1e
    bl EventFunction
    b lbl_08060c66
lbl_08060c44:
    movs r0, #1
    movs r1, #0x1e
    bl EventFunction
    movs r0, #1
    movs r1, #0x10
    bl EventFunction
    b lbl_08060c66
lbl_08060c56:
    movs r0, #1
    movs r1, #0x2e
    bl EventFunction
    b lbl_08060c66
lbl_08060c60:
    ldr r1, lbl_08060ca4 @ =0x0203383c
    movs r0, #1
    str r0, [r1]
lbl_08060c66:
    ldr r0, lbl_08060ca8 @ =0x030053ca
    movs r4, #0
    strh r4, [r0]
    ldr r2, lbl_08060cac @ =0x03000038
    ldrb r1, [r2, #2]
    movs r0, #0xf
    ands r0, r1
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r2, #2]
    movs r3, #0
    movs r0, #1
    strb r0, [r2, #1]
    ldrb r1, [r2, #3]
    subs r0, #0x11
    ands r0, r1
    strb r0, [r2, #3]
    ldr r0, lbl_08060cb0 @ =0x03000c77
    strb r4, [r0]
    ldr r0, lbl_08060cb4 @ =0x03000002
    strh r3, [r0]
    ldr r0, lbl_08060cb8 @ =sub_08060b14
    bl CallbackSetVBlank
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060ca4: .4byte 0x0203383c
lbl_08060ca8: .4byte 0x030053ca
lbl_08060cac: .4byte 0x03000038
lbl_08060cb0: .4byte 0x03000c77
lbl_08060cb4: .4byte 0x03000002
lbl_08060cb8: .4byte sub_08060b14

    thumb_func_start sub_08060cbc
sub_08060cbc: @ 0x08060cbc
    push {lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r2, lbl_08060cd4 @ =0x03000038
    ldrb r1, [r2, #3]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0
    beq lbl_08060cd8
    ldrb r1, [r2]
    b lbl_08060ce0
    .align 2, 0
lbl_08060cd4: .4byte 0x03000038
lbl_08060cd8:
    ldr r1, lbl_08060cec @ =0x08363ce8
    ldrb r0, [r2]
    adds r0, r0, r1
    ldrb r1, [r0]
lbl_08060ce0:
    cmp r3, #0
    bne lbl_08060cf4
    ldr r0, lbl_08060cf0 @ =0x03000055
    strb r3, [r0]
    b lbl_08060d22
    .align 2, 0
lbl_08060cec: .4byte 0x08363ce8
lbl_08060cf0: .4byte 0x03000055
lbl_08060cf4:
    movs r0, #1
    bl load_demo_ram_values
    ldr r2, lbl_08060d28 @ =0x03000038
    ldrb r1, [r2, #2]
    movs r3, #0xf
    adds r0, r3, #0
    ands r0, r1
    strb r0, [r2, #2]
    ldr r1, lbl_08060d2c @ =0x03000c77
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08060d30 @ =0x03000002
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_08060d34 @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08060d22
    ldrb r1, [r2, #3]
    adds r0, r3, #0
    ands r0, r1
    strb r0, [r2, #3]
lbl_08060d22:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08060d28: .4byte 0x03000038
lbl_08060d2c: .4byte 0x03000c77
lbl_08060d30: .4byte 0x03000002
lbl_08060d34: .4byte 0x030013d2

    thumb_func_start end_demo
end_demo: @ 0x08060d38
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08060d78 @ =0x03000038
    movs r7, #0
    strb r7, [r0, #1]
    ldr r1, lbl_08060d7c @ =0x030013d2
    ldrb r2, [r1]
    adds r3, r0, #0
    adds r5, r1, #0
    cmp r2, #1
    bne lbl_08060d9c
    ldr r0, lbl_08060d80 @ =0x040000d4
    ldr r1, lbl_08060d84 @ =0x03004fca
    str r1, [r0]
    ldr r1, lbl_08060d88 @ =0x0203f080
    str r1, [r0, #4]
    ldr r2, lbl_08060d8c @ =0x80000100
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_08060d90 @ =0x030051ca
    str r1, [r0]
    ldr r1, lbl_08060d94 @ =0x0203f280
    str r1, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    movs r0, #0xb
    bl sub_08000c48
    ldr r1, lbl_08060d98 @ =0x03000c74
    movs r0, #0x10
    strb r0, [r1]
    strb r7, [r5]
    b lbl_08060e22
    .align 2, 0
lbl_08060d78: .4byte 0x03000038
lbl_08060d7c: .4byte 0x030013d2
lbl_08060d80: .4byte 0x040000d4
lbl_08060d84: .4byte 0x03004fca
lbl_08060d88: .4byte 0x0203f080
lbl_08060d8c: .4byte 0x80000100
lbl_08060d90: .4byte 0x030051ca
lbl_08060d94: .4byte 0x0203f280
lbl_08060d98: .4byte 0x03000c74
lbl_08060d9c:
    ldr r6, lbl_08060db0 @ =0x03000c74
    movs r0, #0xb
    strb r0, [r6]
    ldrb r0, [r3, #3]
    movs r4, #0xf0
    ands r4, r0
    cmp r4, #0
    beq lbl_08060db4
    strb r7, [r5]
    b lbl_08060dfe
    .align 2, 0
lbl_08060db0: .4byte 0x03000c74
lbl_08060db4:
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    beq lbl_08060de0
    ldrb r0, [r3]
    adds r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bls lbl_08060dcc
    strb r4, [r3]
lbl_08060dcc:
    movs r0, #0xa
    bl FadeAllSounds
    movs r0, #0xa
    bl sub_08003ae4
    strb r4, [r5]
    movs r0, #2
    strb r0, [r6]
    b lbl_08060e22
lbl_08060de0:
    ldrb r0, [r3]
    adds r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0xf
    bls lbl_08060df8
    strb r1, [r5]
    strb r1, [r3]
    movs r0, #1
    strb r0, [r6]
    b lbl_08060e08
lbl_08060df8:
    cmp r0, #8
    bne lbl_08060e04
    strb r1, [r5]
lbl_08060dfe:
    movs r0, #2
    strb r0, [r6]
    b lbl_08060e08
lbl_08060e04:
    movs r0, #3
    strb r0, [r5]
lbl_08060e08:
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_08060e22
    ldrb r1, [r3, #3]
    movs r0, #0xf
    ands r0, r1
    strb r0, [r3, #3]
    movs r0, #0
    bl FadeAllSounds
    movs r0, #0
    bl sub_08003ae4
lbl_08060e22:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start return_one
return_one: @ 0x08060e28
    movs r0, #1
    bx lr

    thumb_func_start tourian_escape_main
tourian_escape_main: @ 0x08060e2c
    push {r4, r5, lr}
    movs r4, #0
    ldr r1, lbl_08060e94 @ =0x0875fe3c
    ldr r5, lbl_08060e98 @ =0x0300007e
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
    ldr r0, lbl_08060e9c @ =0x03000005
    strb r1, [r0]
    ldr r0, lbl_08060ea0 @ =0x03000c72
    strh r4, [r0]
    ldr r1, lbl_08060ea4 @ =0x03000c74
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
    ldr r1, lbl_08060ea8 @ =0x03000054
    movs r0, #6
    strb r0, [r1]
    ldr r0, lbl_08060eac @ =0x03000055
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08060eb0 @ =0x03000056
    strb r1, [r0]
    ldr r1, lbl_08060eb4 @ =0x0300007d
    movs r0, #3
    strb r0, [r1]
    ldr r1, lbl_08060ea4 @ =0x03000c74
    movs r0, #0xa
    strb r0, [r1]
lbl_08060e8e:
    movs r0, #1
    b lbl_08060eba
    .align 2, 0
lbl_08060e94: .4byte 0x0875fe3c
lbl_08060e98: .4byte 0x0300007e
lbl_08060e9c: .4byte 0x03000005
lbl_08060ea0: .4byte 0x03000c72
lbl_08060ea4: .4byte 0x03000c74
lbl_08060ea8: .4byte 0x03000054
lbl_08060eac: .4byte 0x03000055
lbl_08060eb0: .4byte 0x03000056
lbl_08060eb4: .4byte 0x0300007d
lbl_08060eb8:
    movs r0, #0
lbl_08060eba:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08060ec0
sub_08060ec0: @ 0x08060ec0
    push {lr}
    ldr r0, lbl_08060ed4 @ =0x0300007d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    beq lbl_08060ed8
    cmp r0, #9
    beq lbl_08060ee2
    b lbl_08060eea
    .align 2, 0
lbl_08060ed4: .4byte 0x0300007d
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
    ldr r0, lbl_08060f10 @ =0x0300007d
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
lbl_08060f10: .4byte 0x0300007d
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
    ldr r0, lbl_08060f74 @ =0x03000054
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08060f78 @ =0x03000055
    strb r1, [r0]
    ldr r0, lbl_08060f7c @ =0x03000056
    strb r1, [r0]
    ldr r0, lbl_08060f80 @ =0x03000c75
    strb r1, [r0]
    ldr r0, lbl_08060f84 @ =0x0300004b
    strb r1, [r0]
    b lbl_08060fda
    .align 2, 0
lbl_08060f74: .4byte 0x03000054
lbl_08060f78: .4byte 0x03000055
lbl_08060f7c: .4byte 0x03000056
lbl_08060f80: .4byte 0x03000c75
lbl_08060f84: .4byte 0x0300004b
lbl_08060f88:
    ldr r1, lbl_08060f90 @ =0x03000bf0
    movs r0, #8
    strb r0, [r1]
    b lbl_08060fda
    .align 2, 0
lbl_08060f90: .4byte 0x03000bf0
lbl_08060f94:
    ldr r1, lbl_08060fa4 @ =0x03000bf0
    movs r0, #7
    strb r0, [r1]
    ldr r1, lbl_08060fa8 @ =0x03000030
    movs r0, #7
    strb r0, [r1, #2]
    b lbl_08060fda
    .align 2, 0
lbl_08060fa4: .4byte 0x03000bf0
lbl_08060fa8: .4byte 0x03000030
lbl_08060fac:
    ldr r0, lbl_08060fc4 @ =0x03000054
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
lbl_08060fc4: .4byte 0x03000054
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
    ldr r4, lbl_0806103c @ =0x0300007d
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
    ldr r0, lbl_08061040 @ =0x03000030
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
lbl_0806103c: .4byte 0x0300007d
lbl_08061040: .4byte 0x03000030

    thumb_func_start cutscene_main
cutscene_main: @ 0x08061044
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_0806105c @ =0x03000005
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
lbl_0806105c: .4byte 0x03000005
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
    ldr r0, lbl_080610a8 @ =0x0300007d
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
    ldr r1, lbl_080610ac @ =0x03000005
    movs r0, #2
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_080610a0: .4byte sub_080612d4
lbl_080610a4: .4byte 0x0836bdac
lbl_080610a8: .4byte 0x0300007d
lbl_080610ac: .4byte 0x03000005
lbl_080610b0:
    ldr r1, lbl_080610b8 @ =0x03000005
    movs r0, #1
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_080610b8: .4byte 0x03000005
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
    ldr r4, lbl_08061148 @ =0x0300007d
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
    ldr r0, lbl_0806114c @ =0x0300002f
    ldrb r1, [r0]
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r1, r0
    bne lbl_0806112a
    ldr r0, lbl_08061150 @ =0x03001380
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
    ldr r1, lbl_08061154 @ =0x03000005
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806121c
    .align 2, 0
lbl_08061140: .4byte 0x08754bc4
lbl_08061144: .4byte 0x0836bdac
lbl_08061148: .4byte 0x0300007d
lbl_0806114c: .4byte 0x0300002f
lbl_08061150: .4byte 0x03001380
lbl_08061154: .4byte 0x03000005
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
    ldr r2, lbl_08061210 @ =0x0300007d
    movs r0, #0
    ldrsb r0, [r2, r0]
    lsls r0, r0, #4
    adds r0, r0, r3
    ldrb r0, [r0, #1]
    lsrs r0, r0, #6
    cmp r0, #0
    beq lbl_080611ee
    ldr r1, lbl_08061214 @ =0x0300002f
    ldrb r0, [r2]
    strb r0, [r1]
lbl_080611ee:
    ldr r1, lbl_08061218 @ =0x03000005
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
lbl_08061210: .4byte 0x0300007d
lbl_08061214: .4byte 0x0300002f
lbl_08061218: .4byte 0x03000005
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
    ldr r0, lbl_080612b4 @ =0x03000e7c
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
    ldr r0, lbl_080612c0 @ =0x030013ae
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r3, lbl_080612c4 @ =0x04000052
    ldr r0, lbl_080612c8 @ =0x030013b2
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_080612cc @ =0x030013b0
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
lbl_080612b4: .4byte 0x03000e7c
lbl_080612b8: .4byte 0x84000100
lbl_080612bc: .4byte 0x08754bc4
lbl_080612c0: .4byte 0x030013ae
lbl_080612c4: .4byte 0x04000052
lbl_080612c8: .4byte 0x030013b2
lbl_080612cc: .4byte 0x030013b0
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
    ldr r2, lbl_080613c4 @ =0x030016c4
    movs r3, #0xc5
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_080613c8 @ =0x03005806
    ldr r1, lbl_080613cc @ =0x03005807
    movs r0, #0
    strb r0, [r1]
    strb r0, [r2]
    ldr r1, lbl_080613d0 @ =0x03001382
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
    ldr r1, lbl_080613e0 @ =0x030013ae
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r4, [r3, #0x1c]
    strh r4, [r0]
    ldr r1, lbl_080613e4 @ =0x0836bdac
    ldr r0, lbl_080613e8 @ =0x0300007d
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
    ldr r0, lbl_080613ec @ =0x03000bf0
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
    ldr r2, lbl_080613f8 @ =0x0300002f
    ldrb r1, [r2]
    ldr r4, lbl_080613e8 @ =0x0300007d
    movs r0, #0
    ldrsb r0, [r4, r0]
    cmp r1, r0
    beq lbl_08061370
    movs r0, #0
    strb r0, [r2]
lbl_08061370:
    bl ClearGfxRam
    ldr r2, lbl_080613fc @ =0x03000bf4
    ldr r0, lbl_08061400 @ =0x03000bf6
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r3, #0
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_08061404 @ =0x03000bf8
    ldr r0, lbl_08061408 @ =0x03000bfa
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806140c @ =0x03000bfc
    ldr r0, lbl_08061410 @ =0x03000bfe
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_08061414 @ =0x03000c00
    ldr r0, lbl_08061418 @ =0x03000c02
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
lbl_080613c4: .4byte 0x030016c4
lbl_080613c8: .4byte 0x03005806
lbl_080613cc: .4byte 0x03005807
lbl_080613d0: .4byte 0x03001382
lbl_080613d4: .4byte 0x04000050
lbl_080613d8: .4byte 0x08754bc4
lbl_080613dc: .4byte 0x04000054
lbl_080613e0: .4byte 0x030013ae
lbl_080613e4: .4byte 0x0836bdac
lbl_080613e8: .4byte 0x0300007d
lbl_080613ec: .4byte 0x03000bf0
lbl_080613f0: .4byte 0x06010000
lbl_080613f4: .4byte 0x0201e000
lbl_080613f8: .4byte 0x0300002f
lbl_080613fc: .4byte 0x03000bf4
lbl_08061400: .4byte 0x03000bf6
lbl_08061404: .4byte 0x03000bf8
lbl_08061408: .4byte 0x03000bfa
lbl_0806140c: .4byte 0x03000bfc
lbl_08061410: .4byte 0x03000bfe
lbl_08061414: .4byte 0x03000c00
lbl_08061418: .4byte 0x03000c02

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
    ldr r0, lbl_080614f8 @ =0x03000bf4
    b lbl_08061526
    .align 2, 0
lbl_080614f8: .4byte 0x03000bf4
lbl_080614fc:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_0806150c
    ldr r0, lbl_08061508 @ =0x03000bf8
    b lbl_08061526
    .align 2, 0
lbl_08061508: .4byte 0x03000bf8
lbl_0806150c:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_0806151c
    ldr r0, lbl_08061518 @ =0x03000bfc
    b lbl_08061526
    .align 2, 0
lbl_08061518: .4byte 0x03000bfc
lbl_0806151c:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bne lbl_08061528
    ldr r0, lbl_0806153c @ =0x03000c00
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
    ldr r0, lbl_08061540 @ =0x03000bf6
    b lbl_0806156e
    .align 2, 0
lbl_0806153c: .4byte 0x03000c00
lbl_08061540: .4byte 0x03000bf6
lbl_08061544:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_08061554
    ldr r0, lbl_08061550 @ =0x03000bfa
    b lbl_0806156e
    .align 2, 0
lbl_08061550: .4byte 0x03000bfa
lbl_08061554:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_08061564
    ldr r0, lbl_08061560 @ =0x03000bfe
    b lbl_0806156e
    .align 2, 0
lbl_08061560: .4byte 0x03000bfe
lbl_08061564:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bne lbl_08061570
    ldr r0, lbl_08061574 @ =0x03000c02
lbl_0806156e:
    strh r2, [r0]
lbl_08061570:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08061574: .4byte 0x03000c02

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
    ldr r2, lbl_08061590 @ =0x03000bf4
    b lbl_080615be
    .align 2, 0
lbl_08061590: .4byte 0x03000bf4
lbl_08061594:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_080615a4
    ldr r2, lbl_080615a0 @ =0x03000bf8
    b lbl_080615be
    .align 2, 0
lbl_080615a0: .4byte 0x03000bf8
lbl_080615a4:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_080615b4
    ldr r2, lbl_080615b0 @ =0x03000bfc
    b lbl_080615be
    .align 2, 0
lbl_080615b0: .4byte 0x03000bfc
lbl_080615b4:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r3, r0
    bne lbl_080615be
    ldr r2, lbl_080615c4 @ =0x03000c00
lbl_080615be:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_080615c4: .4byte 0x03000c00

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
    ldr r2, lbl_080615e0 @ =0x03000bf6
    b lbl_0806160e
    .align 2, 0
lbl_080615e0: .4byte 0x03000bf6
lbl_080615e4:
    movs r0, #0x80
    lsls r0, r0, #2
    cmp r1, r0
    bne lbl_080615f4
    ldr r2, lbl_080615f0 @ =0x03000bfa
    b lbl_0806160e
    .align 2, 0
lbl_080615f0: .4byte 0x03000bfa
lbl_080615f4:
    movs r0, #0x80
    lsls r0, r0, #3
    cmp r1, r0
    bne lbl_08061604
    ldr r2, lbl_08061600 @ =0x03000bfe
    b lbl_0806160e
    .align 2, 0
lbl_08061600: .4byte 0x03000bfe
lbl_08061604:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r3, r0
    bne lbl_0806160e
    ldr r2, lbl_08061614 @ =0x03000c02
lbl_0806160e:
    adds r0, r2, #0
    pop {r1}
    bx r1
    .align 2, 0
lbl_08061614: .4byte 0x03000c02

    thumb_func_start CutsceneStartBackgroundScrolling
CutsceneStartBackgroundScrolling: @ 0x0CutsceneStartBackgroundScrolling
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
    ldr r0, lbl_080617a0 @ =0x03000bf4
    b lbl_0806185c
    .align 2, 0
lbl_0806179c: .4byte 0x08754bc4
lbl_080617a0: .4byte 0x03000bf4
lbl_080617a4:
    ldr r2, lbl_080617b8 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617bc @ =0x03000bf6
    b lbl_0806185c
    .align 2, 0
lbl_080617b8: .4byte 0x08754bc4
lbl_080617bc: .4byte 0x03000bf6
lbl_080617c0:
    ldr r2, lbl_080617d4 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617d8 @ =0x03000bf8
    b lbl_0806185c
    .align 2, 0
lbl_080617d4: .4byte 0x08754bc4
lbl_080617d8: .4byte 0x03000bf8
lbl_080617dc:
    ldr r2, lbl_080617f0 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_080617f4 @ =0x03000bfa
    b lbl_0806185c
    .align 2, 0
lbl_080617f0: .4byte 0x08754bc4
lbl_080617f4: .4byte 0x03000bfa
lbl_080617f8:
    ldr r2, lbl_0806180c @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_08061810 @ =0x03000bfc
    b lbl_0806185c
    .align 2, 0
lbl_0806180c: .4byte 0x08754bc4
lbl_08061810: .4byte 0x03000bfc
lbl_08061814:
    ldr r2, lbl_08061828 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_0806182c @ =0x03000bfe
    b lbl_0806185c
    .align 2, 0
lbl_08061828: .4byte 0x08754bc4
lbl_0806182c: .4byte 0x03000bfe
lbl_08061830:
    ldr r2, lbl_08061844 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_08061848 @ =0x03000c00
    b lbl_0806185c
    .align 2, 0
lbl_08061844: .4byte 0x08754bc4
lbl_08061848: .4byte 0x03000c00
lbl_0806184c:
    ldr r2, lbl_08061888 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r1, #0x38
    adds r1, r1, r0
    ldr r0, lbl_0806188c @ =0x03000c02
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
lbl_0806188c: .4byte 0x03000c02
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
    ldr r0, lbl_08061a68 @ =0x03000bf4
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x30]
    ldr r0, lbl_08061a6c @ =0x03000bf6
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x28]
    ldr r0, lbl_08061a70 @ =0x03000bf8
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x32]
    ldr r0, lbl_08061a74 @ =0x03000bfa
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x2a]
    ldr r0, lbl_08061a78 @ =0x03000bfc
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x34]
    ldr r0, lbl_08061a7c @ =0x03000bfe
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x2c]
    ldr r0, lbl_08061a80 @ =0x03000c00
    ldrh r0, [r0]
    lsrs r0, r0, #2
    strh r0, [r1, #0x36]
    ldr r0, lbl_08061a84 @ =0x03000c02
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
lbl_08061a68: .4byte 0x03000bf4
lbl_08061a6c: .4byte 0x03000bf6
lbl_08061a70: .4byte 0x03000bf8
lbl_08061a74: .4byte 0x03000bfa
lbl_08061a78: .4byte 0x03000bfc
lbl_08061a7c: .4byte 0x03000bfe
lbl_08061a80: .4byte 0x03000c00
lbl_08061a84: .4byte 0x03000c02

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
    ldr r0, lbl_08061c4c @ =0x030013ae
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
lbl_08061c4c: .4byte 0x030013ae
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
    ldr r0, lbl_08061ce0 @ =0x030013b0
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
lbl_08061ce0: .4byte 0x030013b0
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
    ldr r0, lbl_08061d1c @ =0x030013b2
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
lbl_08061d1c: .4byte 0x030013b2
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
    ldr r0, lbl_08061ef0 @ =0x030013ae
    movs r2, #0
    strh r2, [r0]
    ldr r1, lbl_08061ef4 @ =0x030013b0
    movs r0, #0x10
    strh r0, [r1]
    ldr r0, lbl_08061ef8 @ =0x030013b2
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
    ldr r0, lbl_08061f00 @ =0x03000c04
    mov r8, r0
    ldr r1, lbl_08061f04 @ =0x03000c06
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
lbl_08061ef0: .4byte 0x030013ae
lbl_08061ef4: .4byte 0x030013b0
lbl_08061ef8: .4byte 0x030013b2
lbl_08061efc: .4byte 0x08754bc4
lbl_08061f00: .4byte 0x03000c04
lbl_08061f04: .4byte 0x03000c06
lbl_08061f08: .4byte 0x0840d058

    thumb_func_start unk_61f0c
unk_61f0c: @ 0x08061f0c
    ldr r0, lbl_08061f20 @ =0x08754bc4
    ldr r2, [r0]
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldr r1, lbl_08061f24 @ =0x030013ae
    movs r0, #0x10
    strh r0, [r1]
    movs r0, #0xff
    strh r0, [r2, #0x1e]
    bx lr
    .align 2, 0
lbl_08061f20: .4byte 0x08754bc4
lbl_08061f24: .4byte 0x030013ae

    thumb_func_start unk_61f28
unk_61f28: @ 0x08061f28
    ldr r0, lbl_08061f3c @ =0x08754bc4
    ldr r2, [r0]
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldr r1, lbl_08061f40 @ =0x030013ae
    movs r0, #0x10
    strh r0, [r1]
    movs r0, #0xbf
    strh r0, [r2, #0x1e]
    bx lr
    .align 2, 0
lbl_08061f3c: .4byte 0x08754bc4
lbl_08061f40: .4byte 0x030013ae

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
