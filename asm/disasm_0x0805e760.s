    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start ConnectionUpdateHatches
ConnectionUpdateHatches: @ 0x0805e760
    push {r4, r5, r6, r7, lr}
    movs r7, #0
lbl_0805e764:
    ldr r0, lbl_0805e7a0 @ =gHatchData
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
lbl_0805e7a0: .4byte gHatchData
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
    ldr r2, lbl_0805e830 @ =gHatchData
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
lbl_0805e830: .4byte gHatchData
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
    ldr r0, lbl_0805e8f4 @ =gHatchData
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
lbl_0805e8f4: .4byte gHatchData

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
    ldr r0, lbl_0805e948 @ =gHatchData
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
lbl_0805e948: .4byte gHatchData
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
    ldr r4, lbl_0805e9bc @ =gHatchData
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    adds r0, r7, #0
    bl BgClipSetBg1BlockValue
    movs r0, #0x10
    adds r0, r0, r7
    mov r8, r0
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl BgClipSetBg1BlockValue
    adds r1, r7, #0
    adds r1, #0x20
    str r1, [sp]
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    ldr r0, [sp]
    bl BgClipSetBg1BlockValue
    adds r5, r7, #0
    adds r5, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    adds r0, r5, #0
    bl BgClipSetBg1BlockValue
    mov r6, r8
    ldr r3, [sp]
    mov r8, r3
    b lbl_0805ea04
    .align 2, 0
lbl_0805e9bc: .4byte gHatchData
lbl_0805e9c0:
    ldr r4, lbl_0805ea50 @ =gHatchData
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    adds r0, r7, #0
    bl BgClipSetRawBG1BlockValue
    movs r0, #0x10
    adds r0, r0, r7
    mov r8, r0
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl BgClipSetRawBG1BlockValue
    movs r1, #0x20
    adds r1, r1, r7
    mov sb, r1
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    mov r0, sb
    bl BgClipSetRawBG1BlockValue
    adds r5, r7, #0
    adds r5, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    adds r0, r5, #0
    bl BgClipSetRawBG1BlockValue
    mov r6, r8
    mov r8, sb
lbl_0805ea04:
    lsls r0, r7, #0x10
    lsrs r0, r0, #0x10
    ldr r4, lbl_0805ea50 @ =gHatchData
    add r4, sl
    ldrb r1, [r4, #6]
    ldrb r2, [r4, #5]
    bl BgClipSetClipdataBlockValue
    lsls r0, r6, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl BgClipSetClipdataBlockValue
    mov r3, r8
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    bl BgClipSetClipdataBlockValue
    lsls r0, r5, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    bl BgClipSetClipdataBlockValue
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ea50: .4byte gHatchData

    thumb_func_start sub_0805ea54
sub_0805ea54: @ 0x0805ea54
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r1, lbl_0805ea88 @ =gHatchData
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
lbl_0805ea88: .4byte gHatchData
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
    bl BgClipSetBg1BlockValue
    adds r0, r5, #0
    adds r0, #0x10
    ldrb r1, [r4, #6]
    adds r1, #1
    ldrb r2, [r4, #5]
    bl BgClipSetBg1BlockValue
    adds r0, r5, #0
    adds r0, #0x20
    ldrb r1, [r4, #6]
    adds r1, #2
    ldrb r2, [r4, #5]
    bl BgClipSetBg1BlockValue
    adds r0, r5, #0
    adds r0, #0x30
    ldrb r1, [r4, #6]
    adds r1, #3
    ldrb r2, [r4, #5]
    bl BgClipSetBg1BlockValue
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
    ldr r0, lbl_0805ebe8 @ =gHatchData
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
    bl BgClipSetBg1BlockValue
    adds r6, r4, #0
    adds r6, #0x10
    ldrb r1, [r5, #6]
    adds r1, #1
    ldrb r2, [r5, #5]
    adds r0, r6, #0
    bl BgClipSetBg1BlockValue
    movs r0, #0x20
    adds r0, r0, r4
    mov r8, r0
    ldrb r1, [r5, #6]
    adds r1, #2
    ldrb r2, [r5, #5]
    bl BgClipSetBg1BlockValue
    movs r0, #0x30
    adds r0, r0, r4
    mov sb, r0
    ldrb r1, [r5, #6]
    adds r1, #3
    ldrb r2, [r5, #5]
    bl BgClipSetBg1BlockValue
    ldrb r1, [r5, #6]
    ldrb r2, [r5, #5]
    adds r0, r4, #0
    bl BgClipSetClipdataBlockValue
    lsls r6, r6, #0x10
    lsrs r6, r6, #0x10
    ldrb r1, [r5, #6]
    adds r1, #1
    ldrb r2, [r5, #5]
    adds r0, r6, #0
    bl BgClipSetClipdataBlockValue
    mov r0, r8
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    ldrb r1, [r5, #6]
    adds r1, #2
    ldrb r2, [r5, #5]
    bl BgClipSetClipdataBlockValue
    mov r0, sb
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov sb, r0
    ldrb r1, [r5, #6]
    adds r1, #3
    ldrb r2, [r5, #5]
    bl BgClipSetClipdataBlockValue
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
lbl_0805ebe8: .4byte gHatchData
lbl_0805ebec: .4byte 0x083602c8

    thumb_func_start ConnectionCheckEnterDoor
ConnectionCheckEnterDoor: @ 0x0805ebf0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    ldr r0, lbl_0805ec10 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0805ec14
    movs r0, #0
    b lbl_0805ed84
    .align 2, 0
lbl_0805ec10: .4byte gGameModeSub1
lbl_0805ec14:
    movs r5, #0
    mov ip, r5
    ldr r0, lbl_0805ec9c @ =gHatchData
    ldr r2, lbl_0805eca0 @ =gCurrentArea
    mov sl, r2
    adds r3, r0, #7
    mov sb, r5
    ldr r0, lbl_0805eca4 @ =gLastDoorUsed
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
    ldr r1, lbl_0805ecb0 @ =gDoorPositionStart
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
lbl_0805ec9c: .4byte gHatchData
lbl_0805eca0: .4byte gCurrentArea
lbl_0805eca4: .4byte gLastDoorUsed
lbl_0805eca8: .4byte 0x08345868
lbl_0805ecac: .4byte 0x0875faa8
lbl_0805ecb0: .4byte gDoorPositionStart
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
    ldr r0, lbl_0805ed54 @ =gBg1XPosition
    ldrh r0, [r0]
    lsrs r0, r0, #6
    adds r0, #8
    ldr r2, lbl_0805ed58 @ =gDoorPositionStart
    cmp r1, r0
    ble lbl_0805ece0
    movs r0, #1
    strh r0, [r2]
lbl_0805ece0:
    ldrb r0, [r4, #4]
    strh r0, [r2, #2]
lbl_0805ece4:
    ldr r2, lbl_0805ed5c @ =gSamusDoorPositionOffset
    ldrb r0, [r4, #5]
    adds r0, #1
    lsls r0, r0, #6
    ldr r1, lbl_0805ed60 @ =gSamusData
    ldrh r1, [r1, #0x14]
    subs r0, r0, r1
    subs r0, #1
    strh r0, [r2]
    ldrb r0, [r4]
    bl process_door_type
    ldr r1, lbl_0805ed64 @ =gGameModeSub1
    movs r0, #3
    strh r0, [r1]
    ldr r0, lbl_0805ed68 @ =gHatchData
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
    bl CheckPlayRoomMusicTrack
    movs r5, #1
    b lbl_0805ed82
    .align 2, 0
lbl_0805ed54: .4byte gBg1XPosition
lbl_0805ed58: .4byte gDoorPositionStart
lbl_0805ed5c: .4byte gSamusDoorPositionOffset
lbl_0805ed60: .4byte gSamusData
lbl_0805ed64: .4byte gGameModeSub1
lbl_0805ed68: .4byte gHatchData
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

    thumb_func_start ConnectionCheckAreaConnection
ConnectionCheckAreaConnection: @ 0x0805ed94
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    ldr r0, lbl_0805ee20 @ =gGameModeSub1
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #2
    beq lbl_0805edb2
    b lbl_0805eeb4
lbl_0805edb2:
    movs r4, #0
    mov r8, r4
    ldr r1, lbl_0805ee24 @ =gHatchData
    ldr r0, lbl_0805ee28 @ =0x08345868
    ldrb r0, [r0, #7]
    mov ip, r0
    adds r3, r1, #7
    ldr r2, lbl_0805ee2c @ =gLastDoorUsed
    mov sb, r2
lbl_0805edc4:
    ldrb r0, [r3]
    cmp r0, ip
    beq lbl_0805ee4a
    ldr r2, lbl_0805ee30 @ =0x0875faa8
    ldr r0, lbl_0805ee34 @ =gCurrentArea
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
lbl_0805ee20: .4byte gGameModeSub1
lbl_0805ee24: .4byte gHatchData
lbl_0805ee28: .4byte 0x08345868
lbl_0805ee2c: .4byte gLastDoorUsed
lbl_0805ee30: .4byte 0x0875faa8
lbl_0805ee34: .4byte gCurrentArea
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
    ldr r3, lbl_0805eebc @ =gCurrentArea
    mov sb, r3
    ldrb r7, [r3]
    ldr r1, lbl_0805eec0 @ =gHatchData
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
    ldr r1, lbl_0805eec4 @ =gLastDoorUsed
    movs r0, #0
    strb r0, [r1]
lbl_0805eeb4:
    movs r0, #0
    b lbl_0805ef22
    .align 2, 0
lbl_0805eeb8: .4byte 0x08360274
lbl_0805eebc: .4byte gCurrentArea
lbl_0805eec0: .4byte gHatchData
lbl_0805eec4: .4byte gLastDoorUsed
lbl_0805eec8:
    ldr r2, lbl_0805eed8 @ =gSamusData
    ldrb r0, [r2]
    cmp r0, #0x1d
    bne lbl_0805eee0
    ldr r1, lbl_0805eedc @ =gSamusDoorPositionOffset
    movs r0, #0
    strh r0, [r1]
    b lbl_0805eef0
    .align 2, 0
lbl_0805eed8: .4byte gSamusData
lbl_0805eedc: .4byte gSamusDoorPositionOffset
lbl_0805eee0:
    ldr r0, lbl_0805ef30 @ =gSamusDoorPositionOffset
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
    ldr r1, lbl_0805ef34 @ =gGameModeSub1
    movs r0, #3
    strh r0, [r1]
    ldr r0, lbl_0805ef38 @ =0x0875faa8
    ldr r4, lbl_0805ef3c @ =gCurrentArea
    ldrb r1, [r4]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r0, lbl_0805ef40 @ =gLastDoorUsed
    ldrb r2, [r0]
    lsls r0, r2, #1
    adds r0, r0, r2
    lsls r0, r0, #2
    ldr r1, [r1]
    adds r5, r1, r0
    bl check_play_cutscene_during_elevator
    ldrb r0, [r4]
    ldrb r1, [r5, #1]
    bl CheckPlayRoomMusicTrack
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
lbl_0805ef30: .4byte gSamusDoorPositionOffset
lbl_0805ef34: .4byte gGameModeSub1
lbl_0805ef38: .4byte 0x0875faa8
lbl_0805ef3c: .4byte gCurrentArea
lbl_0805ef40: .4byte gLastDoorUsed

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
    ldr r1, lbl_0805ef74 @ =gUseMotherShipDoors
    movs r0, #0
    strb r0, [r1]
    b lbl_0805ef94
    .align 2, 0
lbl_0805ef74: .4byte gUseMotherShipDoors
lbl_0805ef78:
    ldr r1, lbl_0805ef80 @ =gUseMotherShipDoors
    movs r0, #1
    strb r0, [r1]
    b lbl_0805ef94
    .align 2, 0
lbl_0805ef80: .4byte gUseMotherShipDoors
lbl_0805ef84:
    ldr r1, lbl_0805efa0 @ =gWhichBGPositionIsWrittenToBG3OFS
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0805efa4 @ =gSkipDoorTransition
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
lbl_0805efa0: .4byte gWhichBGPositionIsWrittenToBG3OFS
lbl_0805efa4: .4byte gSkipDoorTransition

    thumb_func_start find_event_based_door_number
find_event_based_door_number: @ 0x0805efa8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    movs r5, #0x28
    ldr r0, lbl_0805efe8 @ =gCurrentArea
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
lbl_0805efe8: .4byte gCurrentArea
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

    thumb_func_start ConnectionSetHatchAsOpened
ConnectionSetHatchAsOpened: @ 0x0805f004
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r0, lbl_0805f078 @ =gCurrentArea
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
lbl_0805f078: .4byte gCurrentArea
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
    ldr r1, lbl_0805f0dc @ =gDoorUnlockTimer
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
    ldr r4, lbl_0805f0e0 @ =gHatchesState
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
lbl_0805f0dc: .4byte gDoorUnlockTimer
lbl_0805f0e0: .4byte gHatchesState

    thumb_func_start sub_0805f0e4
sub_0805f0e4: @ 0x0805f0e4
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r3, lbl_0805f11c @ =gHatchData
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
lbl_0805f11c: .4byte gHatchData

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
    ldr r2, lbl_0805f160 @ =gHatchesState
    movs r3, #1
    ldr r1, lbl_0805f164 @ =gHatchData
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
lbl_0805f160: .4byte gHatchesState
lbl_0805f164: .4byte gHatchData
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
    ldr r0, lbl_0805f1c8 @ =gHatchData
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
    ldr r1, lbl_0805f1cc @ =gLastDoorUsed
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
lbl_0805f1c8: .4byte gHatchData
lbl_0805f1cc: .4byte gLastDoorUsed
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
    ldr r4, lbl_0805f22c @ =gHatchData
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
    ldr r0, lbl_0805f230 @ =gHatchesState
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
lbl_0805f22c: .4byte gHatchData
lbl_0805f230: .4byte gHatchesState
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
    ldr r0, lbl_0805f260 @ =gHatchData
    add r0, r8
    ldr r1, lbl_0805f264 @ =gLastDoorUsed
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
lbl_0805f260: .4byte gHatchData
lbl_0805f264: .4byte gLastDoorUsed
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

    thumb_func_start ConnectionLoadDoors
ConnectionLoadDoors: @ 0x0805f294
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0805f3b8 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f2ae
    b lbl_0805f590
lbl_0805f2ae:
    ldr r1, lbl_0805f3bc @ =gHatchData
    ldr r6, lbl_0805f3c0 @ =0x0875faa8
    ldr r5, lbl_0805f3c4 @ =gCurrentArea
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
    ldr r1, lbl_0805f3cc @ =gNumberOfValidHatchesInRoom
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
    ldr r4, lbl_0805f3d0 @ =gHatchesState
    mov sb, r4
lbl_0805f2ec:
    ldr r0, lbl_0805f3d4 @ =gCurrentRoom
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
    ldr r2, lbl_0805f3d8 @ =gBgPointersAndDimensions
    ldrh r1, [r2, #0x1c]
    ldrb r0, [r6, #4]
    muls r0, r1, r0
    ldrb r4, [r6, #2]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r2, r0, r1
    ldrh r1, [r2, #2]
    ldr r3, lbl_0805f3dc @ =gTilemapAndClipPointers
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
    ldr r1, lbl_0805f3cc @ =gNumberOfValidHatchesInRoom
    ldrb r4, [r1]
    cmp r4, #0xf
    ble lbl_0805f35a
    b lbl_0805f462
lbl_0805f35a:
    lsls r0, r4, #3
    ldr r2, lbl_0805f3bc @ =gHatchData
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
    ldr r0, lbl_0805f3bc @ =gHatchData
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
lbl_0805f3b8: .4byte gPauseScreenFlag
lbl_0805f3bc: .4byte gHatchData
lbl_0805f3c0: .4byte 0x0875faa8
lbl_0805f3c4: .4byte gCurrentArea
lbl_0805f3c8: .4byte 0x08345868
lbl_0805f3cc: .4byte gNumberOfValidHatchesInRoom
lbl_0805f3d0: .4byte gHatchesState
lbl_0805f3d4: .4byte gCurrentRoom
lbl_0805f3d8: .4byte gBgPointersAndDimensions
lbl_0805f3dc: .4byte gTilemapAndClipPointers
lbl_0805f3e0: .4byte 0x08360130
lbl_0805f3e4:
    subs r0, #1
lbl_0805f3e6:
    strb r0, [r3, #5]
    ldr r2, lbl_0805f410 @ =gHatchData
    adds r0, r5, r2
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
    mov r1, r8
    strb r1, [r0, #7]
    adds r0, r4, #1
    ldr r2, lbl_0805f414 @ =gNumberOfValidHatchesInRoom
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
lbl_0805f410: .4byte gHatchData
lbl_0805f414: .4byte gNumberOfValidHatchesInRoom
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
    ldr r0, lbl_0805f474 @ =gLastDoorUsed
    ldrb r0, [r0]
    cmp r8, r0
    bne lbl_0805f49a
    mov sl, r4
    b lbl_0805f49a
    .align 2, 0
lbl_0805f474: .4byte gLastDoorUsed
lbl_0805f478:
    mov r2, r8
    strb r2, [r1, #7]
    b lbl_0805f49a
lbl_0805f47e:
    movs r4, #0xf
    ldr r1, lbl_0805f52c @ =gHatchData
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
    ldr r1, lbl_0805f52c @ =gHatchData
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
    bl ConnectionSetHatchAsOpened
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
    ldr r0, lbl_0805f534 @ =gGameModeSub3
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f590
    ldr r0, lbl_0805f52c @ =gHatchData
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
    ldr r1, lbl_0805f52c @ =gHatchData
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
lbl_0805f52c: .4byte gHatchData
lbl_0805f530: .4byte 0x08345868
lbl_0805f534: .4byte gGameModeSub3
lbl_0805f538:
    movs r2, #1
    rsbs r2, r2, #0
    add r8, r2
lbl_0805f53e:
    adds r0, r4, r1
    ldrb r4, [r0, #6]
    ldr r2, lbl_0805f5a0 @ =gTilemapAndClipPointers
    ldr r1, lbl_0805f5a4 @ =gBgPointersAndDimensions
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
    bl BgClipGetNewBldalphaValue
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
    ldr r2, lbl_0805f5a8 @ =gIoRegistersBackup
    ldr r1, lbl_0805f5ac @ =gBldalphaData1
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
lbl_0805f5a0: .4byte gTilemapAndClipPointers
lbl_0805f5a4: .4byte gBgPointersAndDimensions
lbl_0805f5a8: .4byte gIoRegistersBackup
lbl_0805f5ac: .4byte gBldalphaData1
lbl_0805f5b0: .4byte 0x04000052

    thumb_func_start ConnectionLockHatchesWithTimer
ConnectionLockHatchesWithTimer: @ 0x0805f5b4
    push {lr}
    ldr r1, lbl_0805f5cc @ =gHatchesState
    ldr r0, lbl_0805f5d0 @ =0x0000ffff
    strh r0, [r1, #2]
    movs r0, #0
    bl lock_hatches
    ldr r1, lbl_0805f5d4 @ =gDoorUnlockTimer
    movs r0, #2
    strb r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f5cc: .4byte gHatchesState
lbl_0805f5d0: .4byte 0x0000ffff
lbl_0805f5d4: .4byte gDoorUnlockTimer

    thumb_func_start ConnectionCheckHatchLockEvents
ConnectionCheckHatchLockEvents: @ 0x0805f5d8
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0805f6fc @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805f5e8
    b lbl_0805f73a
lbl_0805f5e8:
    ldr r3, lbl_0805f700 @ =gHatchesState
    strh r0, [r3, #4]
    strh r0, [r3, #6]
    ldr r1, lbl_0805f704 @ =gCurrentArea
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
    ldr r1, lbl_0805f710 @ =gCurrentRoom
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
lbl_0805f6fc: .4byte gPauseScreenFlag
lbl_0805f700: .4byte gHatchesState
lbl_0805f704: .4byte gCurrentArea
lbl_0805f708: .4byte 0x083602d8
lbl_0805f70c: .4byte 0x0875fde0
lbl_0805f710: .4byte gCurrentRoom
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
    ldr r0, lbl_0805f740 @ =gHatchesState
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
lbl_0805f740: .4byte gHatchesState

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
    ldr r1, lbl_0805f7a0 @ =gCurrentCutscene
    movs r0, #5
    b lbl_0805f7e8
    .align 2, 0
lbl_0805f7a0: .4byte gCurrentCutscene
lbl_0805f7a4:
    cmp r2, #0x2b
    bne lbl_0805f7c0
    movs r0, #3
    movs r1, #0x43
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f7ea
    ldr r1, lbl_0805f7bc @ =gCurrentCutscene
    movs r0, #0xb
    b lbl_0805f7e8
    .align 2, 0
lbl_0805f7bc: .4byte gCurrentCutscene
lbl_0805f7c0:
    cmp r2, #0xb
    bne lbl_0805f7ea
    movs r0, #3
    movs r1, #6
    bl EventFunction
    cmp r0, #0
    bne lbl_0805f7ea
    ldr r0, lbl_0805f7f0 @ =gRainSoundEffect
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805f7e4
    ldr r0, lbl_0805f7f4 @ =0x00000121
    movs r1, #0xa
    bl SoundFade
lbl_0805f7e4:
    ldr r1, lbl_0805f7f8 @ =gCurrentCutscene
    movs r0, #0xd
lbl_0805f7e8:
    strb r0, [r1]
lbl_0805f7ea:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805f7f0: .4byte gRainSoundEffect
lbl_0805f7f4: .4byte 0x00000121
lbl_0805f7f8: .4byte gCurrentCutscene

    thumb_func_start check_play_cutscene_during_elevator
check_play_cutscene_during_elevator: @ 0x0805f7fc
    push {lr}
    ldr r0, lbl_0805f814 @ =gLastElevatorUsed
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
lbl_0805f814: .4byte gLastElevatorUsed
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
    ldr r0, lbl_0805f850 @ =gCurrentCutscene
    movs r1, #4
    b lbl_0805f89c
    .align 2, 0
lbl_0805f850: .4byte gCurrentCutscene
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
    ldr r0, lbl_0805f880 @ =gCurrentCutscene
    movs r1, #7
    b lbl_0805f89c
    .align 2, 0
lbl_0805f880: .4byte gCurrentCutscene
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
    ldr r0, lbl_0805f8b8 @ =gCurrentCutscene
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
lbl_0805f8b8: .4byte gCurrentCutscene
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
    ldr r0, lbl_0805f8f0 @ =gCurrentCutscene
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
lbl_0805f8f0: .4byte gCurrentCutscene
