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

    thumb_func_start check_disable_animated_palette_on_transition
check_disable_animated_palette_on_transition: @ 0x0805e424
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
