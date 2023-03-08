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
