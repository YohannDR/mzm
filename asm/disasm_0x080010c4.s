    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_080010c4
sub_080010c4: @ 0x080010c4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08001134 @ =gMusicInfo
    ldrb r1, [r0, #9]
    str r1, [sp]
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_080010ea
    ldr r0, lbl_08001138 @ =0x04000006
    ldrb r0, [r0]
    cmp r0, #0x9f
    bhi lbl_080010e6
    adds r0, #0xe4
lbl_080010e6:
    adds r1, r0, r1
    str r1, [sp]
lbl_080010ea:
    ldrb r1, [r2, #0x10]
    ldrb r3, [r2, #0x11]
    lsls r0, r3, #4
    mov sl, r0
    ldrb r0, [r2, #0xc]
    lsls r0, r0, #1
    adds r0, r1, r0
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldrb r0, [r2, #0xe]
    cmp r4, r0
    blo lbl_0800110a
    subs r0, r4, r0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
lbl_0800110a:
    movs r0, #0
    mov sb, r0
    cmp r1, r4
    bhi lbl_0800113c
    cmp r4, r3
    bhi lbl_0800113c
    ldrb r1, [r2, #0xc]
    subs r0, r4, r1
    adds r0, #1
    lsls r0, r0, #0x14
    lsrs r0, r0, #0x10
    mov sl, r0
    adds r7, r1, #0
    adds r0, r4, #1
    ldrb r1, [r2, #0xe]
    cmp r0, r1
    bne lbl_0800112e
    mov r0, sb
lbl_0800112e:
    strb r0, [r2, #0x11]
    b lbl_080011b4
    .align 2, 0
lbl_08001134: .4byte gMusicInfo
lbl_08001138: .4byte 0x04000006
lbl_0800113c:
    ldrb r0, [r2, #0x11]
    cmp r0, r1
    bhi lbl_08001160
    cmp r1, r4
    bhi lbl_08001160
    ldrb r1, [r2, #0xc]
    subs r0, r4, r1
    adds r0, #1
    lsls r0, r0, #0x14
    lsrs r0, r0, #0x10
    mov sl, r0
    adds r7, r1, #0
    adds r0, r4, #1
    ldrb r1, [r2, #0xe]
    cmp r0, r1
    bne lbl_0800112e
    movs r0, #0
    b lbl_0800112e
lbl_08001160:
    ldrb r0, [r2, #0x11]
    cmp r4, r0
    bhi lbl_08001170
    cmp r0, r1
    bhi lbl_08001170
    movs r0, #0
    mov sl, r0
    b lbl_080011ac
lbl_08001170:
    adds r3, r2, #0
    ldrb r1, [r3, #0x11]
    adds r0, r1, #0
    cmp r0, r4
    bhs lbl_08001190
    subs r0, r4, r1
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r4, #1
    ldrb r1, [r3, #0xe]
    cmp r0, r1
    bne lbl_0800118c
    movs r0, #0
lbl_0800118c:
    strb r0, [r3, #0x11]
    b lbl_080011b4
lbl_08001190:
    cmp r0, r4
    bls lbl_080011a8
    ldrb r0, [r3, #0xe]
    subs r0, r0, r1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    mov r0, sb
    b lbl_0800118c
lbl_080011a8:
    movs r1, #0
    mov sl, r1
lbl_080011ac:
    adds r0, r4, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    strb r7, [r2, #0x11]
lbl_080011b4:
    cmp r7, #0
    bne lbl_080011ba
    b lbl_08001430
lbl_080011ba:
    ldr r6, lbl_08001204 @ =gMusicInfo+0xC24
    mov r0, sl
    adds r1, r0, r6
    ldr r0, lbl_08001208 @ =0xfffff400
    adds r5, r6, r0
    ldr r0, lbl_0800120c @ =gSoundCodeBPointer
    mov r8, r0
    lsls r3, r7, #0x1b
    lsrs r3, r3, #0x18
    ldr r4, [r0]
    adds r0, r1, #0
    adds r2, r5, #0
    bl _call_via_r4
    adds r5, r0, #0
    mov r1, sb
    cmp r1, #0
    beq lbl_080011f2
    adds r1, r6, #0
    mov r0, sb
    lsls r3, r0, #0x1b
    lsrs r3, r3, #0x18
    mov r0, r8
    ldr r4, [r0]
    adds r0, r1, #0
    adds r2, r5, #0
    bl _call_via_r4
lbl_080011f2:
    ldr r0, lbl_08001210 @ =0xfffff3dc
    adds r1, r6, r0
    movs r0, #0
    strb r0, [r1, #0xa]
    movs r2, #0
    lsls r1, r7, #0x1a
    str r1, [sp, #4]
    b lbl_080013da
    .align 2, 0
lbl_08001204: .4byte gMusicInfo+0xC24
lbl_08001208: .4byte 0xfffff400
lbl_0800120c: .4byte gSoundCodeBPointer
lbl_08001210: .4byte 0xfffff3dc
lbl_08001214:
    movs r0, #0x34
    muls r0, r2, r0
    ldr r1, lbl_08001254 @ =gMusicInfo+0x1824
    adds r4, r0, r1
    ldrb r0, [r4]
    adds r2, #1
    mov r8, r2
    cmp r0, #0
    bne lbl_08001228
    b lbl_080013d4
lbl_08001228:
    ldr r0, lbl_08001258 @ =0xffffe7dc
    adds r1, r1, r0
    ldrb r0, [r1, #0xa]
    adds r0, #1
    strb r0, [r1, #0xa]
    ldr r5, [r4, #0x28]
    ldrb r1, [r4, #0x13]
    cmp r1, #0
    beq lbl_080012bc
    movs r6, #0
lbl_0800123c:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800126e
    ldrb r0, [r4, #1]
    cmp r0, #0x20
    bne lbl_0800125c
    ldr r0, [r4, #0x20]
    ldr r0, [r0, #0xc]
    lsls r0, r0, #0xe
    str r0, [r4, #0x18]
    b lbl_0800125e
    .align 2, 0
lbl_08001254: .4byte gMusicInfo+0x1824
lbl_08001258: .4byte 0xffffe7dc
lbl_0800125c:
    str r6, [r4, #0x18]
lbl_0800125e:
    strb r6, [r4, #0x10]
    ldrb r0, [r4, #0x13]
    movs r1, #0xfd
    ands r1, r0
    movs r0, #0x10
    orrs r1, r0
    strb r1, [r4, #0x13]
    b lbl_080012b6
lbl_0800126e:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0800127a
    movs r0, #0xfb
    b lbl_080012b2
lbl_0800127a:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080012b6
    ldrb r1, [r5]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08001296
    ldrb r0, [r4, #3]
    strb r0, [r5, #6]
    adds r0, r5, #0
    bl sub_08004f10
lbl_08001296:
    ldrb r1, [r5, #8]
    ldrb r0, [r4, #0xf]
    adds r0, #1
    muls r0, r1, r0
    asrs r0, r0, #7
    strb r0, [r4, #4]
    ldrb r1, [r5, #9]
    ldrb r0, [r4, #0xf]
    adds r0, #1
    muls r0, r1, r0
    asrs r0, r0, #7
    strb r0, [r4, #5]
    ldrb r1, [r4, #0x13]
    movs r0, #0xef
lbl_080012b2:
    ands r0, r1
    strb r0, [r4, #0x13]
lbl_080012b6:
    ldrb r1, [r4, #0x13]
    cmp r1, #0
    bne lbl_0800123c
lbl_080012bc:
    ldrb r5, [r4, #0x10]
    ldrb r0, [r4]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0xa
    bne lbl_080012ce
    movs r0, #0
    strb r0, [r4]
    b lbl_080013d4
lbl_080012ce:
    cmp r1, #1
    bne lbl_080012da
    ldrb r0, [r4, #8]
    cmp r0, #0xff
    bne lbl_0800130c
    b lbl_08001320
lbl_080012da:
    subs r0, r1, #2
    cmp r0, #6
    bhi lbl_0800139a
    lsls r0, r0, #2
    ldr r1, lbl_080012ec @ =lbl_080012f0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080012ec: .4byte lbl_080012f0
lbl_080012f0: @ jump table
    .4byte lbl_08001312 @ case 0
    .4byte lbl_0800132e @ case 1
    .4byte lbl_0800139a @ case 2
    .4byte lbl_08001350 @ case 3
    .4byte lbl_08001354 @ case 4
    .4byte lbl_0800139a @ case 5
    .4byte lbl_08001384 @ case 6
lbl_0800130c:
    movs r5, #0
    movs r0, #2
    strb r0, [r4]
lbl_08001312:
    ldrb r0, [r4, #8]
    adds r0, r0, r5
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0xfe
    ble lbl_0800139a
lbl_08001320:
    ldrb r0, [r4, #9]
    ldrb r1, [r4, #0xa]
    cmp r0, #0
    beq lbl_08001348
    movs r5, #0xff
    movs r0, #3
    strb r0, [r4]
lbl_0800132e:
    lsls r0, r5, #0x10
    asrs r0, r0, #0x10
    ldrb r1, [r4, #9]
    muls r0, r1, r0
    asrs r0, r0, #8
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    asrs r0, r0, #0x10
    ldrb r1, [r4, #0xa]
    cmp r0, r1
    bgt lbl_0800139a
    cmp r1, #0
    beq lbl_08001350
lbl_08001348:
    adds r5, r1, #0
    movs r0, #4
    strb r0, [r4]
    b lbl_0800139a
lbl_08001350:
    movs r0, #6
    strb r0, [r4]
lbl_08001354:
    lsls r0, r5, #0x10
    asrs r0, r0, #0x10
    ldrb r1, [r4, #0xb]
    muls r0, r1, r0
    asrs r0, r0, #8
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r0, #0
    bgt lbl_0800139a
    movs r0, #0
    strb r0, [r4]
    ldrb r0, [r4, #0xc]
    cmp r0, #0
    beq lbl_0800137c
    ldrb r0, [r4, #0xd]
    cmp r0, #0
    beq lbl_0800137c
    movs r0, #8
    strb r0, [r4]
    b lbl_080013d4
lbl_0800137c:
    adds r0, r4, #0
    bl unk_20a4
    b lbl_080013d4
lbl_08001384:
    ldrb r0, [r4, #0xd]
    subs r0, #1
    strb r0, [r4, #0xd]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0800139a
    strb r0, [r4]
    adds r0, r4, #0
    bl unk_20a4
lbl_0800139a:
    strb r5, [r4, #0x10]
    lsls r1, r5, #0x10
    asrs r1, r1, #0x10
    ldr r2, lbl_08001440 @ =gMusicInfo
    ldrb r0, [r2, #6]
    adds r0, #1
    muls r1, r0, r1
    lsls r1, r1, #0xc
    asrs r1, r1, #0x10
    ldrb r0, [r4, #4]
    muls r0, r1, r0
    asrs r0, r0, #8
    strb r0, [r4, #0x11]
    ldrb r0, [r4, #5]
    muls r0, r1, r0
    asrs r0, r0, #8
    strb r0, [r4, #0x12]
    adds r5, r2, #0
    adds r5, #0x24
    ldr r0, lbl_08001444 @ =gSoundCodeAPointer
    mov r1, sb
    adds r2, r7, r1
    lsls r2, r2, #0x1a
    lsrs r2, r2, #0x18
    ldr r3, [r0]
    adds r0, r4, #0
    adds r1, r5, #0
    bl _call_via_r3
lbl_080013d4:
    mov r1, r8
    lsls r0, r1, #0x10
    lsrs r2, r0, #0x10
lbl_080013da:
    ldr r0, lbl_08001440 @ =gMusicInfo
    ldrb r0, [r0, #5]
    cmp r2, r0
    bhs lbl_080013fc
    ldr r0, [sp]
    cmp r0, #0
    bne lbl_080013ea
    b lbl_08001214
lbl_080013ea:
    ldr r0, lbl_08001448 @ =0x04000006
    ldrb r0, [r0]
    cmp r0, #0x9f
    bhi lbl_080013f4
    adds r0, #0xe4
lbl_080013f4:
    ldr r1, [sp]
    cmp r0, r1
    bhs lbl_080013fc
    b lbl_08001214
lbl_080013fc:
    ldr r4, lbl_0800144c @ =gMusicInfo+0xC24
    mov r0, sl
    adds r1, r0, r4
    ldr r0, lbl_08001450 @ =0xfffff400
    adds r5, r4, r0
    ldr r6, lbl_08001454 @ =gSoundCodeCPointer
    ldr r0, [sp, #4]
    lsrs r2, r0, #0x18
    ldr r3, [r6]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r3
    adds r5, r0, #0
    mov r1, sb
    cmp r1, #0
    beq lbl_08001430
    adds r1, r4, #0
    mov r0, sb
    lsls r2, r0, #0x1a
    lsrs r2, r2, #0x18
    ldr r3, [r6]
    adds r0, r1, #0
    adds r1, r5, #0
    bl _call_via_r3
lbl_08001430:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08001440: .4byte gMusicInfo
lbl_08001444: .4byte gSoundCodeAPointer
lbl_08001448: .4byte 0x04000006
lbl_0800144c: .4byte gMusicInfo+0xC24
lbl_08001450: .4byte 0xfffff400
lbl_08001454: .4byte gSoundCodeCPointer

    thumb_func_start sub_08001458
sub_08001458: @ 0x08001458
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    movs r6, #0
    mov r8, r6
lbl_08001466:
    mov r1, r8
    lsls r0, r1, #2
    add r0, r8
    lsls r0, r0, #3
    ldr r1, lbl_08001484 @ =gPsgSounds
    adds r4, r0, r1
    ldrb r0, [r4]
    movs r2, #1
    add r2, r8
    mov sl, r2
    cmp r0, #0
    bne lbl_08001480
    b lbl_08001834
lbl_08001480:
    b lbl_080015ca
    .align 2, 0
lbl_08001484: .4byte gPsgSounds
lbl_08001488:
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_080014e4
    ldr r1, [r4, #0x24]
    ldrb r0, [r1, #0xf]
    strb r0, [r4, #0xa]
    ldrb r0, [r1, #4]
    strb r0, [r4, #0xb]
    ldrb r0, [r1, #0xc]
    strb r0, [r4, #0xd]
    ldrb r0, [r1, #0xd]
    strb r0, [r4, #0xe]
    adds r0, r1, #0
    adds r0, #0x36
    ldrb r0, [r0]
    strb r0, [r4, #0x1d]
    adds r0, r1, #0
    adds r0, #0x37
    ldrb r0, [r0]
    strb r0, [r4, #0x1e]
    ldr r0, [r1, #0x38]
    str r0, [r4, #0x20]
    adds r0, r1, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    strb r0, [r4, #4]
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    strb r0, [r4, #5]
    adds r0, r1, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    strb r0, [r4, #6]
    adds r0, r1, #0
    adds r0, #0x3f
    ldrb r0, [r0]
    strb r0, [r4, #7]
    ldrb r0, [r1, #0x12]
    strb r0, [r4, #0x1f]
    movs r0, #0xfd
    ands r0, r2
    movs r1, #0x10
    orrs r0, r1
    b lbl_080015c8
lbl_080014e4:
    movs r0, #4
    ands r0, r2
    cmp r0, #0
    beq lbl_080014fc
    ldrh r0, [r4, #8]
    strh r0, [r4, #0x14]
    adds r0, r4, #0
    bl sub_08005104
    ldrb r1, [r4, #0xf]
    movs r0, #0xfb
    b lbl_080015c6
lbl_080014fc:
    movs r0, #0x10
    mov sb, r0
    ands r0, r2
    cmp r0, #0
    beq lbl_080015a8
    ldr r2, [r4, #0x24]
    ldrb r1, [r4, #0xc]
    ldrb r0, [r2, #6]
    cmp r0, r1
    beq lbl_08001518
    strb r1, [r2, #6]
    ldr r0, [r4, #0x24]
    bl sub_08004f10
lbl_08001518:
    ldr r2, [r4, #0x24]
    ldrb r1, [r2, #8]
    ldrb r0, [r4, #0xa]
    adds r0, #1
    adds r3, r1, #0
    muls r3, r0, r3
    asrs r3, r3, #7
    strb r3, [r4, #2]
    ldrb r1, [r2, #9]
    ldrb r0, [r4, #0xa]
    adds r0, #1
    adds r2, r1, #0
    muls r2, r0, r2
    asrs r2, r2, #7
    strb r2, [r4, #3]
    ldrb r0, [r4, #2]
    ldrb r1, [r4, #3]
    adds r0, r0, r1
    asrs r0, r0, #4
    strb r0, [r4, #0x1a]
    ldrb r1, [r4, #0x1a]
    ldrb r0, [r4, #6]
    muls r0, r1, r0
    adds r0, #0xf
    asrs r0, r0, #4
    strb r0, [r4, #0x1b]
    ldr r7, lbl_08001578 @ =0x04000081
    movs r6, #0x11
    mov r1, r8
    lsls r6, r1
    ldrb r0, [r7]
    adds r1, r0, #0
    bics r1, r6
    lsls r3, r3, #0x18
    lsrs r5, r3, #0x18
    lsls r0, r2, #0x18
    lsrs r2, r0, #0x18
    cmp r5, r2
    blo lbl_0800157c
    lsrs r0, r3, #0x19
    cmp r0, r2
    bls lbl_0800158c
    movs r0, #1
    mov r2, r8
    lsls r0, r2
    orrs r1, r0
    b lbl_0800158e
    .align 2, 0
lbl_08001578: .4byte 0x04000081
lbl_0800157c:
    lsrs r0, r0, #0x19
    cmp r0, r5
    bls lbl_0800158c
    mov r0, sb
    mov r2, r8
    lsls r0, r2
    orrs r1, r0
    b lbl_0800158e
lbl_0800158c:
    orrs r1, r6
lbl_0800158e:
    strb r1, [r7]
    movs r0, #0
    strb r0, [r4, #0x12]
    ldrh r1, [r4, #0x14]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
    movs r6, #1
    ldrb r1, [r4, #0xf]
    movs r0, #0xef
    b lbl_080015c6
lbl_080015a8:
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_080015ca
    ldrh r1, [r4, #8]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
    adds r0, r4, #0
    bl sub_08005104
    ldrb r1, [r4, #0xf]
    movs r0, #0xdf
lbl_080015c6:
    ands r0, r1
lbl_080015c8:
    strb r0, [r4, #0xf]
lbl_080015ca:
    ldrb r2, [r4, #0xf]
    cmp r2, #0
    beq lbl_080015d2
    b lbl_08001488
lbl_080015d2:
    ldrb r0, [r4]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0xa
    bne lbl_080015de
    b lbl_080017b6
lbl_080015de:
    cmp r1, #1
    bne lbl_08001624
    mov r0, r8
    cmp r0, #0
    bne lbl_080015ec
    ldrb r0, [r4, #0x1e]
    b lbl_080015f4
lbl_080015ec:
    mov r1, r8
    cmp r1, #2
    bne lbl_080015f6
    movs r0, #0x80
lbl_080015f4:
    strb r0, [r4, #0x10]
lbl_080015f6:
    mov r2, r8
    cmp r2, #1
    bhi lbl_08001600
    ldr r0, [r4, #0x20]
    b lbl_08001602
lbl_08001600:
    movs r0, #0
lbl_08001602:
    strb r0, [r4, #0x11]
    ldrh r1, [r4, #8]
    movs r3, #0
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r1, r0
    orrs r1, r3
    strh r1, [r4, #0x14]
    ldrb r2, [r4, #0x1d]
    cmp r2, #0
    beq lbl_0800161c
    b lbl_080017d4
lbl_0800161c:
    ldrb r0, [r4, #4]
    cmp r0, #0
    bne lbl_08001664
    b lbl_08001690
lbl_08001624:
    ldrb r0, [r4, #0x18]
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_0800162e
    b lbl_08001804
lbl_0800162e:
    subs r0, r1, #2
    cmp r0, #7
    bls lbl_08001636
    b lbl_08001804
lbl_08001636:
    lsls r0, r0, #2
    ldr r1, lbl_08001640 @ =lbl_08001644
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08001640: .4byte lbl_08001644
lbl_08001644: @ jump table
    .4byte lbl_0800167e @ case 0
    .4byte lbl_080016ce @ case 1
    .4byte lbl_08001714 @ case 2
    .4byte lbl_08001728 @ case 3
    .4byte lbl_0800174e @ case 4
    .4byte lbl_08001804 @ case 5
    .4byte lbl_080017c0 @ case 6
    .4byte lbl_080017f0 @ case 7
lbl_08001664:
    strb r3, [r4, #0x19]
    mov r1, r8
    cmp r1, #2
    bne lbl_08001670
    strb r3, [r4, #0x12]
    b lbl_08001674
lbl_08001670:
    adds r0, #8
    strb r0, [r4, #0x12]
lbl_08001674:
    movs r0, #2
    strb r0, [r4]
    adds r0, r4, #0
    bl sub_08005104
lbl_0800167e:
    ldrb r0, [r4, #0x19]
    adds r0, #1
    movs r1, #0
    strb r0, [r4, #0x19]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrb r2, [r4, #0x1a]
    cmp r0, r2
    blt lbl_0800169a
lbl_08001690:
    ldrb r0, [r4, #5]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_080016f0
    b lbl_080016aa
lbl_0800169a:
    mov r0, r8
    cmp r0, #2
    bne lbl_080016a4
    strb r1, [r4, #0x12]
    movs r6, #1
lbl_080016a4:
    ldrb r0, [r4, #4]
    strb r0, [r4, #0x18]
    b lbl_08001804
lbl_080016aa:
    ldrb r0, [r4, #0x1a]
    movs r2, #0
    strb r0, [r4, #0x19]
    mov r0, r8
    cmp r0, #2
    bne lbl_080016ba
    strb r2, [r4, #0x12]
    b lbl_080016c8
lbl_080016ba:
    strb r1, [r4, #0x12]
    ldrh r1, [r4, #8]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_080016c8:
    movs r0, #3
    strb r0, [r4]
    movs r6, #1
lbl_080016ce:
    ldrb r0, [r4, #0x19]
    subs r0, #1
    movs r1, #0
    strb r0, [r4, #0x19]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    ldrb r2, [r4, #0x1b]
    cmp r0, r2
    ble lbl_080016f0
    mov r0, r8
    cmp r0, #2
    bne lbl_080016ea
    strb r1, [r4, #0x12]
    movs r6, #1
lbl_080016ea:
    ldrb r0, [r4, #5]
    strb r0, [r4, #0x18]
    b lbl_08001804
lbl_080016f0:
    ldrb r0, [r4, #0x1b]
    movs r1, #0
    strb r0, [r4, #0x19]
    mov r2, r8
    cmp r2, #2
    bne lbl_08001700
    strb r1, [r4, #0x12]
    b lbl_0800170e
lbl_08001700:
    strb r1, [r4, #0x12]
    ldrh r1, [r4, #8]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_0800170e:
    movs r0, #4
    strb r0, [r4]
    movs r6, #1
lbl_08001714:
    ldrb r0, [r4, #0x1b]
    strb r0, [r4, #0x19]
    ldrb r1, [r4]
    movs r0, #0xf
    ands r0, r1
    cmp r0, #4
    bne lbl_08001804
    movs r0, #1
    strb r0, [r4, #0x18]
    b lbl_08001804
lbl_08001728:
    ldrb r1, [r4, #7]
    cmp r1, #0
    beq lbl_0800176c
    ldrb r0, [r4, #0x1d]
    cmp r0, #0
    bne lbl_0800176c
    mov r0, r8
    cmp r0, #2
    beq lbl_08001748
    strb r1, [r4, #0x12]
    ldrh r1, [r4, #8]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_08001748:
    movs r0, #6
    strb r0, [r4]
    movs r6, #1
lbl_0800174e:
    ldrb r0, [r4, #0x19]
    subs r0, #1
    movs r1, #0
    strb r0, [r4, #0x19]
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_0800176c
    mov r0, r8
    cmp r0, #2
    bne lbl_08001766
    strb r1, [r4, #0x12]
    movs r6, #1
lbl_08001766:
    ldrb r0, [r4, #7]
    strb r0, [r4, #0x18]
    b lbl_08001804
lbl_0800176c:
    movs r3, #0
    strb r3, [r4]
    ldrb r0, [r4, #0xd]
    cmp r0, #0
    beq lbl_080017b6
    ldrb r2, [r4, #0xe]
    cmp r2, #0
    beq lbl_080017b6
    ldrb r1, [r4, #0x1a]
    muls r0, r1, r0
    adds r0, #0xff
    asrs r0, r0, #8
    strb r0, [r4, #0x19]
    strb r2, [r4, #0x18]
    mov r1, r8
    cmp r1, #2
    bne lbl_080017a0
    ldr r0, lbl_0800179c @ =gCgb3Vol
    movs r1, #0x19
    ldrsb r1, [r4, r1]
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0x12]
    b lbl_080017ae
    .align 2, 0
lbl_0800179c: .4byte gCgb3Vol
lbl_080017a0:
    strb r3, [r4, #0x12]
    ldrh r1, [r4, #8]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_080017ae:
    movs r0, #8
    strb r0, [r4]
    movs r6, #1
    b lbl_08001808
lbl_080017b6:
    adds r0, r4, #0
    mov r1, r8
    bl ClearRegistersForPsg
    b lbl_08001834
lbl_080017c0:
    lsls r0, r2, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_08001834
    adds r0, r4, #0
    mov r1, r8
    bl ClearRegistersForPsg
    strb r5, [r4]
    b lbl_08001834
lbl_080017d4:
    ldrb r0, [r4, #0x11]
    orrs r0, r2
    strb r0, [r4, #0x11]
    strb r3, [r4, #0x12]
    ldrb r0, [r4, #0x1b]
    strb r0, [r4, #0x19]
    movs r2, #0x80
    lsls r2, r2, #7
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r4, #0x14]
    movs r0, #9
    strb r0, [r4]
    movs r6, #1
lbl_080017f0:
    movs r0, #0xff
    strb r0, [r4, #0x18]
    cmp r6, #0
    beq lbl_0800182e
    ldrh r1, [r4, #0x14]
    movs r2, #0x80
    lsls r2, r2, #7
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4, #0x14]
lbl_08001804:
    cmp r6, #0
    beq lbl_0800182e
lbl_08001808:
    movs r6, #0
    ldrb r1, [r4, #0x19]
    mov r0, r8
    cmp r0, #2
    bne lbl_08001820
    ldr r0, lbl_0800181c @ =gCgb3Vol
    adds r0, r1, r0
    ldrb r0, [r0]
    b lbl_08001826
    .align 2, 0
lbl_0800181c: .4byte gCgb3Vol
lbl_08001820:
    lsls r0, r1, #4
    ldrb r1, [r4, #0x12]
    orrs r0, r1
lbl_08001826:
    strb r0, [r4, #0x12]
    adds r0, r4, #0
    bl sub_08005104
lbl_0800182e:
    ldrb r0, [r4, #0x18]
    subs r0, #1
    strb r0, [r4, #0x18]
lbl_08001834:
    mov r1, sl
    lsls r0, r1, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    cmp r0, #3
    bhi lbl_08001842
    b lbl_08001466
lbl_08001842:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08001850
sub_08001850: @ 0x08001850
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r5, r0, #0
    ldrb r0, [r5, #0x1c]
    cmp r0, #0
    beq lbl_08001864
    b lbl_08001be2
lbl_08001864:
    movs r0, #1
    strb r0, [r5, #0x1c]
    ldrb r1, [r5, #0x1e]
    ands r0, r1
    movs r1, #0x28
    adds r1, r1, r5
    mov sl, r1
    cmp r0, #0
    beq lbl_08001878
    b lbl_08001b84
lbl_08001878:
    ldrb r1, [r5]
    movs r0, #0xf8
    ands r0, r1
    cmp r0, #0
    beq lbl_08001898
    movs r0, #0x98
    ands r0, r1
    cmp r0, #0
    beq lbl_08001892
    adds r0, r5, #0
    bl sub_08002d2c
    b lbl_08001898
lbl_08001892:
    adds r0, r5, #0
    bl sub_08002e6c
lbl_08001898:
    ldrb r1, [r5]
    movs r0, #2
    ands r0, r1
    movs r2, #0x28
    adds r2, r2, r5
    mov sl, r2
    cmp r0, #0
    bne lbl_080018aa
    b lbl_08001b84
lbl_080018aa:
    adds r0, r5, #0
    bl sub_08004cfc
    lsls r0, r0, #0x18
    b lbl_08001b7c
lbl_080018b4:
    movs r6, #0
    ldr r4, [r5, #0x18]
    subs r0, #1
    mov sb, r0
    b lbl_08001b70
lbl_080018be:
    ldrb r0, [r4]
    adds r1, r6, #1
    mov r8, r1
    adds r7, r4, #0
    adds r7, #0x50
    cmp r0, #0
    bne lbl_080018ce
    b lbl_08001b68
lbl_080018ce:
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_080018da
    adds r0, r4, #0
    bl sub_08001bf0
lbl_080018da:
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_080018e6
    adds r0, r4, #0
    bl sub_08001c18
lbl_080018e6:
    ldrb r0, [r4, #2]
    cmp r0, #0
    beq lbl_080019ba
    subs r0, #1
    strb r0, [r4, #2]
    ldrb r0, [r4, #0x15]
    cmp r0, #0
    beq lbl_080018fc
    subs r0, #1
    strb r0, [r4, #0x15]
    b lbl_080019aa
lbl_080018fc:
    ldrb r1, [r4, #0x10]
    cmp r1, #0
    beq lbl_080019aa
    ldrb r0, [r4, #0x11]
    cmp r0, #0
    beq lbl_080019aa
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_08001950
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080019aa
    ldrb r2, [r4, #0x16]
    adds r0, r1, r2
    strb r0, [r4, #0x16]
    subs r0, #0x40
    lsls r0, r0, #0x18
    cmp r0, #0
    bge lbl_08001928
    movs r0, #0x16
    ldrsb r0, [r4, r0]
    b lbl_0800192e
lbl_08001928:
    ldrb r1, [r4, #0x16]
    movs r0, #0x80
    subs r0, r0, r1
lbl_0800192e:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    movs r0, #0x13
    ldrsb r0, [r4, r0]
    cmp r1, r0
    beq lbl_080019aa
    ldrb r0, [r4, #0x11]
    adds r0, #1
    muls r0, r1, r0
    asrs r0, r0, #7
    strb r0, [r4, #0x13]
    adds r0, r4, #0
    bl sub_08001c3c
    b lbl_080019aa
lbl_08001950:
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_080019aa
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080019aa
    ldrb r2, [r4, #0x16]
    adds r0, r1, r2
    strb r0, [r4, #0x16]
    subs r0, #0x40
    lsls r0, r0, #0x18
    cmp r0, #0
    bge lbl_08001984
    movs r0, #0x16
    ldrsb r0, [r4, r0]
    b lbl_0800198a
lbl_08001970:
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08002140
    b lbl_08001b08
lbl_0800197a:
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_080021b0
    b lbl_08001b08
lbl_08001984:
    ldrb r1, [r4, #0x16]
    movs r0, #0x80
    subs r0, r0, r1
lbl_0800198a:
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    movs r0, #0x13
    ldrsb r0, [r4, r0]
    cmp r1, r0
    beq lbl_080019aa
    ldrb r0, [r4, #0x11]
    adds r0, #1
    muls r0, r1, r0
    asrs r0, r0, #7
    strb r0, [r4, #0x13]
    adds r0, r4, #0
    bl sub_08001ccc
lbl_080019aa:
    ldrb r0, [r4, #2]
    adds r1, r6, #1
    mov r8, r1
    adds r7, r4, #0
    adds r7, #0x50
    cmp r0, #0
    beq lbl_080019ba
    b lbl_08001b08
lbl_080019ba:
    adds r6, #1
    mov r8, r6
    adds r7, r4, #0
    adds r7, #0x50
lbl_080019c2:
    ldr r1, [r4, #0x24]
    ldrb r2, [r1]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    blt lbl_080019d2
    ldrb r2, [r4, #3]
    b lbl_080019dc
lbl_080019d2:
    cmp r2, #0xbc
    bls lbl_080019dc
    strb r2, [r4, #3]
    adds r0, r1, #1
    str r0, [r4, #0x24]
lbl_080019dc:
    cmp r2, #0xce
    bls lbl_08001aa4
    ldrb r1, [r4]
    movs r0, #2
    orrs r0, r1
    strb r0, [r4]
    ldr r1, lbl_08001a74 @ =gClockTable
    adds r0, r2, #0
    subs r0, #0xcf
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r4, #0xe]
    ldr r3, [r4, #0x24]
    ldrb r2, [r3]
    ldrb r0, [r4, #0x14]
    cmp r0, #0
    beq lbl_08001a00
    strb r0, [r4, #0x15]
lbl_08001a00:
    lsls r0, r2, #0x18
    cmp r0, #0
    blt lbl_08001a30
    strb r2, [r4, #1]
    adds r1, r3, #1
    str r1, [r4, #0x24]
    ldrb r2, [r3, #1]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    blt lbl_08001a30
    strb r2, [r4, #0xf]
    adds r3, r1, #1
    str r3, [r4, #0x24]
    ldrb r2, [r1, #1]
    movs r0, #1
    ldrsb r0, [r1, r0]
    cmp r0, #0
    blt lbl_08001a30
    ldrb r0, [r4, #0xe]
    adds r0, r2, r0
    strb r0, [r4, #0xe]
    adds r0, r3, #1
    str r0, [r4, #0x24]
lbl_08001a30:
    ldrb r1, [r4]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x3f
    bls lbl_08001a40
    adds r0, r4, #0
    bl sub_08004e10
lbl_08001a40:
    movs r0, #0
    strb r0, [r4, #0x13]
    adds r0, r4, #0
    bl sub_08004eb4
    adds r0, r4, #0
    bl sub_08004f10
    ldrb r1, [r5]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08001a82
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    beq lbl_08001a78
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08001fe0
    b lbl_08001b00
    .align 2, 0
lbl_08001a74: .4byte gClockTable
lbl_08001a78:
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08001f3c
    b lbl_08001b00
lbl_08001a82:
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    beq lbl_08001a9a
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08001f90
    b lbl_08001b00
lbl_08001a9a:
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08001e2c
    b lbl_08001b00
lbl_08001aa4:
    cmp r2, #0xb0
    bls lbl_08001ae8
    cmp r2, #0xbb
    bne lbl_08001ab6
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_08004d1c
    b lbl_08001b00
lbl_08001ab6:
    cmp r2, #0xbd
    bne lbl_08001ac4
    adds r0, r5, #0
    adds r1, r4, #0
    bl sub_080022cc
    b lbl_08001b00
lbl_08001ac4:
    cmp r2, #0xb1
    bne lbl_08001aca
    b lbl_08001970
lbl_08001aca:
    cmp r2, #0xb6
    bne lbl_08001ad0
    b lbl_0800197a
lbl_08001ad0:
    ldr r0, lbl_08001ae4 @ =sMusicCommandFunctionPointers
    adds r1, r2, #0
    subs r1, #0xb1
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    bl _call_via_r1
    b lbl_08001b00
    .align 2, 0
lbl_08001ae4: .4byte sMusicCommandFunctionPointers
lbl_08001ae8:
    ldr r1, lbl_08001afc @ =gClockTable
    adds r0, r2, #0
    subs r0, #0x80
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r4, #2]
    ldr r0, [r4, #0x24]
    adds r0, #1
    str r0, [r4, #0x24]
    b lbl_08001b08
    .align 2, 0
lbl_08001afc: .4byte gClockTable
lbl_08001b00:
    ldrb r0, [r4, #2]
    cmp r0, #0
    bne lbl_08001b08
    b lbl_080019c2
lbl_08001b08:
    ldrb r1, [r4]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_08001b38
    adds r0, r4, #0
    bl sub_08004f10
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_08001b24
    adds r0, r4, #0
    bl sub_08001d5c
lbl_08001b24:
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_08001b30
    adds r0, r4, #0
    bl sub_08001ddc
lbl_08001b30:
    ldrb r1, [r4]
    movs r0, #0xfb
    ands r0, r1
    strb r0, [r4]
lbl_08001b38:
    ldrb r1, [r4]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08001b68
    adds r0, r4, #0
    bl sub_08004eb4
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_08001b54
    adds r0, r4, #0
    bl sub_08001d78
lbl_08001b54:
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_08001b60
    adds r0, r4, #0
    bl sub_08001de8
lbl_08001b60:
    ldrb r1, [r4]
    movs r0, #0xf7
    ands r0, r1
    strb r0, [r4]
lbl_08001b68:
    mov r2, r8
    lsls r0, r2, #0x18
    lsrs r6, r0, #0x18
    adds r4, r7, #0
lbl_08001b70:
    ldrb r0, [r5, #1]
    cmp r6, r0
    bhs lbl_08001b78
    b lbl_080018be
lbl_08001b78:
    mov r1, sb
    lsls r0, r1, #0x18
lbl_08001b7c:
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08001b84
    b lbl_080018b4
lbl_08001b84:
    movs r7, #0
    strb r7, [r5, #0x1c]
    mov r6, sl
    ldrb r1, [r6]
    adds r4, r1, #0
    cmp r4, #1
    bne lbl_08001b9e
    ldrh r0, [r5, #0x20]
    ldrb r1, [r5, #0x1f]
    bl PlayMusic
    strb r4, [r5, #0x1c]
    b lbl_08001bb8
lbl_08001b9e:
    movs r0, #4
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    beq lbl_08001bc8
    ldrh r1, [r5, #0x20]
    ldr r0, lbl_08001bc4 @ =0x00007fff
    ands r0, r1
    bl SoundPlay
    movs r0, #1
    strb r0, [r5, #0x1c]
lbl_08001bb8:
    movs r0, #0
    strh r7, [r5, #0x20]
    strb r0, [r5, #0x1f]
    strb r0, [r6]
    strb r0, [r5, #0x1c]
    b lbl_08001be2
    .align 2, 0
lbl_08001bc4: .4byte 0x00007fff
lbl_08001bc8:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08001be2
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08001bde
    ldrb r0, [r6]
    bl ReplayQueuedMusic
lbl_08001bde:
    mov r2, sl
    strb r4, [r2]
lbl_08001be2:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08001bf0
sub_08001bf0: @ 0x08001bf0
    push {lr}
    ldr r1, [r0, #0x48]
    cmp r1, #0
    beq lbl_08001c14
    movs r3, #0xff
    movs r2, #5
lbl_08001bfc:
    ldrb r0, [r1, #0xe]
    cmp r0, #0
    beq lbl_08001c0e
    subs r0, #1
    strb r0, [r1, #0xe]
    ands r0, r3
    cmp r0, #0
    bne lbl_08001c0e
    strb r2, [r1]
lbl_08001c0e:
    ldr r1, [r1, #0x30]
    cmp r1, #0
    bne lbl_08001bfc
lbl_08001c14:
    pop {r0}
    bx r0

    thumb_func_start sub_08001c18
sub_08001c18: @ 0x08001c18
    push {lr}
    adds r1, r0, #0
    ldr r2, [r1, #0x4c]
    ldrb r0, [r1, #0xe]
    cmp r0, #0
    beq lbl_08001c36
    subs r0, #1
    strb r0, [r1, #0xe]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_08001c36
    movs r0, #5
    strb r0, [r2]
    strb r1, [r2, #0x18]
lbl_08001c36:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08001c3c
sub_08001c3c: @ 0x08001c3c
    push {r4, r5, lr}
    adds r5, r0, #0
    ldr r4, [r5, #0x48]
    ldrb r0, [r5, #0x12]
    cmp r0, #0
    beq lbl_08001c6a
    cmp r0, #0
    blt lbl_08001cc6
    cmp r0, #2
    bgt lbl_08001cc6
    adds r0, r5, #0
    bl sub_08004f10
    cmp r4, #0
    beq lbl_08001cc6
    movs r1, #0x10
lbl_08001c5c:
    ldrb r0, [r4, #0x13]
    orrs r0, r1
    strb r0, [r4, #0x13]
    ldr r4, [r4, #0x30]
    cmp r4, #0
    bne lbl_08001c5c
    b lbl_08001cc6
lbl_08001c6a:
    adds r0, r5, #0
    bl sub_08004eb4
    ldrb r0, [r4, #1]
    cmp r0, #0
    beq lbl_08001cc2
    cmp r0, #0x20
    bne lbl_08001cc6
    b lbl_08001cc2
lbl_08001c7c:
    movs r0, #0x17
    ldrsb r0, [r5, r0]
    ldrb r1, [r4, #7]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x7f
    ble lbl_08001c92
    movs r1, #0x7f
    b lbl_08001c98
lbl_08001c92:
    cmp r0, #0
    bge lbl_08001c98
    movs r1, #0
lbl_08001c98:
    ldr r0, [r5, #0x38]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r5, #0x18]
    bl Midikey2Freq
    str r0, [r4, #0x1c]
    ldr r1, lbl_08001cb4 @ =gMusicInfo
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_08001cb8
    movs r0, #0x80
    lsls r0, r0, #7
    b lbl_08001cbe
    .align 2, 0
lbl_08001cb4: .4byte gMusicInfo
lbl_08001cb8:
    ldr r1, [r1, #0x18]
    bl sub_08004abc
lbl_08001cbe:
    str r0, [r4, #0x1c]
    ldr r4, [r4, #0x30]
lbl_08001cc2:
    cmp r4, #0
    bne lbl_08001c7c
lbl_08001cc6:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08001ccc
sub_08001ccc: @ 0x08001ccc
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    ldr r6, [r5, #0x4c]
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_08001d08
    adds r0, r5, #0
    bl sub_08004f10
    ldrb r4, [r6, #0x19]
    movs r0, #0x13
    ldrsb r0, [r5, r0]
    ldr r2, lbl_08001d04 @ =sUnk_808cc4d
    lsls r1, r7, #0x10
    asrs r1, r1, #0x10
    adds r1, r1, r2
    ldrb r1, [r1]
    bl __divsi3
    adds r4, r4, r0
    lsls r4, r4, #4
    strb r4, [r6, #0x12]
    ldrb r1, [r6, #0xf]
    movs r0, #0x20
    b lbl_08001d52
    .align 2, 0
lbl_08001d04: .4byte sUnk_808cc4d
lbl_08001d08:
    cmp r0, #0
    bne lbl_08001d44
    adds r0, r5, #0
    bl sub_08004eb4
    ldr r1, [r5, #0x4c]
    movs r0, #0x17
    ldrsb r0, [r5, r0]
    ldrb r1, [r1, #0x1c]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x7f
    ble lbl_08001d2a
    movs r1, #0x7f
    b lbl_08001d30
lbl_08001d2a:
    cmp r0, #0
    bge lbl_08001d30
    movs r1, #0
lbl_08001d30:
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r5, #0x18]
    adds r0, r5, #0
    bl sub_080020d4
    strh r0, [r6, #8]
    ldrb r1, [r6, #0xf]
    movs r0, #4
    b lbl_08001d52
lbl_08001d44:
    cmp r0, #2
    bne lbl_08001d56
    adds r0, r5, #0
    bl sub_08004f10
    ldrb r1, [r6, #0xf]
    movs r0, #0x10
lbl_08001d52:
    orrs r0, r1
    strb r0, [r6, #0xf]
lbl_08001d56:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08001d5c
sub_08001d5c: @ 0x08001d5c
    push {lr}
    ldr r1, [r0, #0x48]
    cmp r1, #0
    beq lbl_08001d72
    movs r2, #0x10
lbl_08001d66:
    ldrb r0, [r1, #0x13]
    orrs r0, r2
    strb r0, [r1, #0x13]
    ldr r1, [r1, #0x30]
    cmp r1, #0
    bne lbl_08001d66
lbl_08001d72:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08001d78
sub_08001d78: @ 0x08001d78
    push {r4, r5, lr}
    adds r5, r0, #0
    ldr r4, [r5, #0x48]
    cmp r4, #0
    beq lbl_08001dd6
lbl_08001d82:
    movs r0, #0x17
    ldrsb r0, [r5, r0]
    ldrb r1, [r4, #7]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x7f
    ble lbl_08001d98
    movs r1, #0x7f
    b lbl_08001d9e
lbl_08001d98:
    cmp r0, #0
    bge lbl_08001d9e
    movs r1, #0
lbl_08001d9e:
    ldr r0, [r4, #0x20]
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r5, #0x18]
    bl Midikey2Freq
    str r0, [r4, #0x1c]
    ldr r1, lbl_08001dbc @ =gMusicInfo
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_08001dc0
    movs r0, #0x80
    lsls r0, r0, #7
    b lbl_08001dc6
    .align 2, 0
lbl_08001dbc: .4byte gMusicInfo
lbl_08001dc0:
    ldr r1, [r1, #0x18]
    bl sub_08004abc
lbl_08001dc6:
    str r0, [r4, #0x1c]
    ldrb r1, [r4, #0x13]
    movs r0, #4
    orrs r0, r1
    strb r0, [r4, #0x13]
    ldr r4, [r4, #0x30]
    cmp r4, #0
    bne lbl_08001d82
lbl_08001dd6:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08001ddc
sub_08001ddc: @ 0x08001ddc
    ldr r2, [r0, #0x4c]
    ldrb r1, [r2, #0xf]
    movs r0, #0x10
    orrs r0, r1
    strb r0, [r2, #0xf]
    bx lr

    thumb_func_start sub_08001de8
sub_08001de8: @ 0x08001de8
    push {r4, lr}
    adds r4, r0, #0
    ldr r1, [r4, #0x4c]
    movs r0, #0x17
    ldrsb r0, [r4, r0]
    ldrb r1, [r1, #0x1c]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x7f
    ble lbl_08001e04
    movs r1, #0x7f
    b lbl_08001e0a
lbl_08001e04:
    cmp r0, #0
    bge lbl_08001e0a
    movs r1, #0
lbl_08001e0a:
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r4, #0x18]
    adds r0, r4, #0
    bl sub_080020d4
    ldr r1, [r4, #0x4c]
    strh r0, [r1, #8]
    ldr r2, [r4, #0x4c]
    ldrb r1, [r2, #0xf]
    movs r0, #4
    orrs r0, r1
    strb r0, [r2, #0xf]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08001e2c
sub_08001e2c: @ 0x08001e2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r1
    ldrb r1, [r0, #3]
    mov r2, sb
    ldrb r0, [r2, #0xb]
    adds r0, r1, r0
    cmp r0, #0xff
    ble lbl_08001e60
    movs r3, #0xff
    str r3, [sp]
    b lbl_08001e66
lbl_08001e4c:
    ldr r2, lbl_08001e58 @ =gMusicInfo
    ldr r3, lbl_08001e5c @ =0x00001824
    adds r0, r2, r3
    adds r6, r1, r0
    b lbl_08001f14
    .align 2, 0
lbl_08001e58: .4byte gMusicInfo
lbl_08001e5c: .4byte 0x00001824
lbl_08001e60:
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
lbl_08001e66:
    ldr r7, [sp]
    mov r5, sb
    movs r0, #0
    mov r8, r0
    movs r6, #0
    movs r2, #0
    ldr r1, lbl_08001eb8 @ =gMusicInfo
    ldrb r1, [r1, #5]
    cmp r6, r1
    bhs lbl_08001f10
    ldr r4, lbl_08001eb8 @ =gMusicInfo
    movs r3, #0x34
    mov ip, r3
    ldr r0, lbl_08001ebc @ =0x0000184c
    adds r0, r0, r4
    mov sl, r0
    ldrb r1, [r4, #5]
    str r1, [sp, #4]
lbl_08001e8a:
    mov r1, ip
    muls r1, r2, r1
    adds r0, r1, r4
    ldr r3, lbl_08001ec0 @ =0x00001824
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r3, r0, #0
    cmp r3, #0
    beq lbl_08001e4c
    subs r0, #5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_08001eaa
    cmp r3, #8
    bne lbl_08001ec4
lbl_08001eaa:
    mov r0, r8
    cmp r0, #0
    bne lbl_08001eca
    movs r1, #1
    mov r8, r1
    b lbl_08001eee
    .align 2, 0
lbl_08001eb8: .4byte gMusicInfo
lbl_08001ebc: .4byte 0x0000184c
lbl_08001ec0: .4byte 0x00001824
lbl_08001ec4:
    mov r3, r8
    cmp r3, #0
    bne lbl_08001f04
lbl_08001eca:
    mov r3, ip
    muls r3, r2, r3
    ldr r1, lbl_08001f30 @ =gMusicInfo
    adds r0, r3, r1
    ldr r1, lbl_08001f34 @ =0x00001826
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, r7
    blo lbl_08001eee
    cmp r0, r7
    bhi lbl_08001f04
    mov r1, sl
    adds r0, r3, r1
    ldr r0, [r0]
    cmp r0, r5
    bhi lbl_08001eee
    cmp r0, r5
    blo lbl_08001f04
lbl_08001eee:
    mov r0, ip
    muls r0, r2, r0
    adds r1, r0, r4
    ldr r3, lbl_08001f34 @ =0x00001826
    adds r1, r1, r3
    ldrb r7, [r1]
    mov r3, sl
    adds r1, r0, r3
    ldr r5, [r1]
    ldr r1, lbl_08001f38 @ =gMusicInfo+0x1824
    adds r6, r0, r1
lbl_08001f04:
    adds r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r3, [sp, #4]
    cmp r2, r3
    blo lbl_08001e8a
lbl_08001f10:
    cmp r6, #0
    beq lbl_08001f1e
lbl_08001f14:
    adds r0, r6, #0
    mov r1, sb
    ldr r2, [sp]
    bl sub_08004f8c
lbl_08001f1e:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08001f30: .4byte gMusicInfo
lbl_08001f34: .4byte 0x00001826
lbl_08001f38: .4byte gMusicInfo+0x1824

    thumb_func_start sub_08001f3c
sub_08001f3c: @ 0x08001f3c
    push {lr}
    adds r3, r0, #0
    ldrb r2, [r3]
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    beq lbl_08001f68
    adds r2, r3, #0
    adds r2, #0x23
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    subs r2, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r2, [r2]
    cmp r0, r2
    bhi lbl_08001f8c
    adds r0, r3, #0
    bl sub_08001e2c
    b lbl_08001f8c
lbl_08001f68:
    movs r0, #0x40
    ands r0, r2
    cmp r0, #0
    beq lbl_08001f8c
    adds r2, r3, #0
    adds r2, #0x23
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    subs r2, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r2, [r2]
    cmp r0, r2
    bhi lbl_08001f8c
    adds r0, r3, #0
    bl sub_08001e2c
lbl_08001f8c:
    pop {r0}
    bx r0

    thumb_func_start sub_08001f90
sub_08001f90: @ 0x08001f90
    push {lr}
    adds r3, r1, #0
    ldrb r1, [r0, #3]
    ldrb r0, [r3, #0xb]
    adds r0, r1, r0
    cmp r0, #0xff
    ble lbl_08001fa2
    movs r2, #0xff
    b lbl_08001fa6
lbl_08001fa2:
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08001fa6:
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    lsls r1, r0, #2
    adds r1, r1, r0
    lsls r1, r1, #3
    ldr r0, lbl_08001fdc @ =gUnk_300376c
    adds r1, r1, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08001fd0
    ldrb r0, [r1, #0x16]
    cmp r2, r0
    blo lbl_08001fd8
    cmp r2, r0
    bne lbl_08001fd0
    ldr r0, [r1, #0x24]
    cmp r3, r0
    bhi lbl_08001fd8
lbl_08001fd0:
    adds r0, r1, #0
    adds r1, r3, #0
    bl sub_08002030
lbl_08001fd8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08001fdc: .4byte gUnk_300376c

    thumb_func_start sub_08001fe0
sub_08001fe0: @ 0x08001fe0
    push {lr}
    adds r3, r1, #0
    ldrb r1, [r0, #3]
    ldrb r0, [r3, #0xb]
    adds r0, r1, r0
    cmp r0, #0xff
    ble lbl_08001ff2
    movs r2, #0xff
    b lbl_08001ff6
lbl_08001ff2:
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
lbl_08001ff6:
    adds r0, r3, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    lsls r1, r0, #2
    adds r1, r1, r0
    lsls r1, r1, #3
    ldr r0, lbl_0800202c @ =gUnk_300376c
    adds r1, r1, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08002020
    ldrb r0, [r1, #0x16]
    cmp r2, r0
    blo lbl_08002028
    cmp r2, r0
    bne lbl_08002020
    ldr r0, [r1, #0x24]
    cmp r3, r0
    bhi lbl_08002028
lbl_08002020:
    adds r0, r1, #0
    adds r1, r3, #0
    bl sub_08002030
lbl_08002028:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800202c: .4byte gUnk_300376c

    thumb_func_start sub_08002030
sub_08002030: @ 0x08002030
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    strb r2, [r4, #0x16]
    adds r0, r5, #0
    adds r0, #0x34
    ldrb r0, [r0]
    strb r0, [r4, #1]
    ldrb r0, [r5, #6]
    strb r0, [r4, #0xc]
    ldrb r2, [r5, #1]
    strb r2, [r4, #0x17]
    ldrb r1, [r5]
    movs r0, #0xf0
    ands r0, r1
    cmp r0, #0x80
    bne lbl_0800205c
    adds r0, r5, #0
    adds r0, #0x35
    ldrb r0, [r0]
    strb r0, [r4, #0x1c]
    b lbl_0800205e
lbl_0800205c:
    strb r2, [r4, #0x1c]
lbl_0800205e:
    movs r0, #0x17
    ldrsb r0, [r5, r0]
    ldrb r1, [r4, #0x1c]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0x7f
    ble lbl_08002074
    movs r1, #0x7f
    b lbl_0800207a
lbl_08002074:
    cmp r0, #0
    bge lbl_0800207a
    movs r1, #0
lbl_0800207a:
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldrb r2, [r5, #0x18]
    adds r0, r5, #0
    bl sub_080020d4
    movs r1, #0
    strh r0, [r4, #8]
    ldr r0, [r4, #0x24]
    str r1, [r0, #0x4c]
    str r5, [r4, #0x24]
    ldrb r1, [r4, #0xf]
    movs r0, #2
    orrs r0, r1
    strb r0, [r4, #0xf]
    movs r0, #1
    strb r0, [r4]
    str r4, [r5, #0x4c]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start unk_20a4
unk_20a4: @ 0x080020a4
    push {lr}
    adds r2, r0, #0
    ldr r0, [r2, #0x28]
    cmp r0, #0
    beq lbl_080020ce
    ldr r1, [r2, #0x30]
    cmp r1, #0
    beq lbl_080020b8
    ldr r0, [r2, #0x2c]
    str r0, [r1, #0x2c]
lbl_080020b8:
    ldr r1, [r2, #0x2c]
    cmp r1, #0
    beq lbl_080020c4
    ldr r0, [r2, #0x30]
    str r0, [r1, #0x30]
    b lbl_080020ca
lbl_080020c4:
    ldr r1, [r2, #0x28]
    ldr r0, [r2, #0x30]
    str r0, [r1, #0x48]
lbl_080020ca:
    movs r0, #0
    str r0, [r2, #0x28]
lbl_080020ce:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080020d4
sub_080020d4: @ 0x080020d4
    push {r4, r5, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r5, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #7
    ands r0, r1
    cmp r0, #3
    bhi lbl_08002120
    ldr r1, lbl_0800211c @ =sUnk_808cad0
    lsls r0, r4, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    cmp r2, #0
    beq lbl_08002132
    adds r0, r4, #1
    cmp r0, #0x7f
    ble lbl_08002102
    movs r4, #0x7f
lbl_08002102:
    adds r0, r4, #1
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    subs r0, r0, r3
    adds r1, r5, #1
    muls r0, r1, r0
    lsls r0, r0, #8
    lsrs r0, r0, #0x10
    adds r0, r3, r0
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    b lbl_08002132
    .align 2, 0
lbl_0800211c: .4byte sUnk_808cad0
lbl_08002120:
    ldr r0, lbl_0800213c @ =gNoiseTable
    adds r1, r4, #0
    subs r1, #0x15
    adds r1, r1, r0
    ldr r0, [r3, #0x38]
    ldrb r1, [r1]
    orrs r0, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
lbl_08002132:
    adds r0, r3, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0800213c: .4byte gNoiseTable

    thumb_func_start sub_08002140
sub_08002140: @ 0x08002140
    push {r4, r5, r6, lr}
    adds r6, r0, #0
    adds r4, r1, #0
    ldr r2, [r4, #0x4c]
    cmp r2, #0
    beq lbl_0800216c
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r0, [r0]
    movs r1, #7
    ands r1, r0
    subs r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r0, r2, #0
    bl ClearRegistersForPsg
    ldr r0, [r4, #0x4c]
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4, #0x4c]
    str r1, [r0, #0x24]
lbl_0800216c:
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_08002188
    adds r1, r0, #0
    movs r2, #0
    movs r3, #0xa
lbl_08002178:
    strb r3, [r1]
    str r2, [r1, #0x28]
    ldr r0, [r1, #0x30]
    str r2, [r1, #0x30]
    str r2, [r1, #0x2c]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08002178
lbl_08002188:
    movs r5, #0
    str r5, [r4, #0x4c]
    str r5, [r4, #0x48]
    ldrb r0, [r6, #4]
    adds r0, #1
    strb r0, [r6, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r6, #1]
    cmp r0, r1
    bne lbl_080021a8
    adds r0, r6, #0
    bl unk_2a38
    strb r5, [r6]
    strb r5, [r6, #4]
lbl_080021a8:
    strb r5, [r4]
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_080021b0
sub_080021b0: @ 0x080021b0
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    ldr r2, [r4, #0x4c]
    cmp r2, #0
    beq lbl_080021dc
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r0, [r0]
    movs r1, #7
    ands r1, r0
    subs r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r0, r2, #0
    bl ClearRegistersForPsg
    ldr r0, [r4, #0x4c]
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4, #0x4c]
    str r1, [r0, #0x24]
lbl_080021dc:
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_080021f8
    adds r1, r0, #0
    movs r2, #0
    movs r3, #0xa
lbl_080021e8:
    strb r3, [r1]
    str r2, [r1, #0x28]
    ldr r0, [r1, #0x30]
    str r2, [r1, #0x30]
    str r2, [r1, #0x2c]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_080021e8
lbl_080021f8:
    movs r6, #0
    str r6, [r4, #0x4c]
    str r6, [r4, #0x48]
    ldrb r0, [r5, #4]
    adds r0, #1
    strb r0, [r5, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r5, #1]
    cmp r0, r1
    bne lbl_08002224
    adds r0, r5, #0
    bl unk_2a38
    strb r6, [r5]
    strb r6, [r5, #4]
    adds r0, r5, #0
    adds r0, #0x28
    ldrb r1, [r0]
    movs r2, #2
    orrs r1, r2
    strb r1, [r0]
lbl_08002224:
    strb r6, [r4]
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start AudioCommand_PatternEnd
AudioCommand_PatternEnd: @ 0x0800222c
    push {r4, r5, lr}
    adds r3, r0, #0
    ldr r0, [r3, #0x24]
    adds r0, #1
    str r0, [r3, #0x24]
    movs r1, #2
    adds r4, r3, #0
    adds r4, #0x28
    movs r5, #0
lbl_0800223e:
    lsls r0, r1, #0x18
    asrs r2, r0, #0x18
    lsls r0, r2, #2
    adds r1, r4, r0
    ldr r0, [r1]
    cmp r0, #0
    beq lbl_08002252
    str r0, [r3, #0x24]
    str r5, [r1]
    b lbl_0800225c
lbl_08002252:
    subs r0, r2, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r0, #0
    bge lbl_0800223e
lbl_0800225c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AudioCommand_Repeat
AudioCommand_Repeat: @ 0x08002264
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #0xa]
    cmp r0, #0
    bne lbl_08002280
    ldr r0, [r2, #0x24]
    adds r1, r0, #1
    str r1, [r2, #0x24]
    ldrb r0, [r0, #1]
    strb r0, [r2, #0xa]
    adds r0, r2, #0
    bl AudioCommand_PatternPlay
    b lbl_0800229e
lbl_08002280:
    subs r0, #1
    strb r0, [r2, #0xa]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08002292
    adds r0, r2, #0
    bl AudioCommand_PatternEnd
    b lbl_0800229e
lbl_08002292:
    ldr r0, [r2, #0x24]
    adds r0, #1
    str r0, [r2, #0x24]
    adds r0, r2, #0
    bl AudioCommand_PatternPlay
lbl_0800229e:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AudioCommand_Priority
AudioCommand_Priority: @ 0x080022a4
    ldr r2, [r0, #0x24]
    adds r1, r2, #1
    str r1, [r0, #0x24]
    ldrb r2, [r2, #1]
    strb r2, [r0, #0xb]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_KeyShift
AudioCommand_KeyShift: @ 0x080022b4
    ldr r1, [r0, #0x24]
    adds r2, r1, #1
    str r2, [r0, #0x24]
    ldrb r1, [r1, #1]
    strb r1, [r0, #0x1c]
    ldrb r3, [r0]
    movs r1, #8
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start sub_080022cc
sub_080022cc: @ 0x080022cc
    push {r4, r5, lr}
    adds r4, r1, #0
    ldr r1, [r4, #0x24]
    ldrb r2, [r1]
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    ldr r0, [r0, #0x14]
    adds r5, r0, r1
    ldrb r0, [r5]
    adds r2, r4, #0
    adds r2, #0x34
    movs r1, #0
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x3f
    bls lbl_08002318
    cmp r0, #0x80
    bne lbl_08002302
    ldrb r0, [r4]
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r4]
    ldr r0, [r5, #4]
    str r0, [r4, #0x40]
    b lbl_0800237e
lbl_08002302:
    cmp r0, #0x40
    bne lbl_0800237e
    ldrb r0, [r4]
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4]
    ldr r0, [r5, #4]
    str r0, [r4, #0x40]
    ldr r0, [r5, #8]
    str r0, [r4, #0x44]
    b lbl_0800237e
lbl_08002318:
    ldrb r1, [r4]
    movs r0, #0xf
    ands r0, r1
    strb r0, [r4]
    ldrb r0, [r5, #2]
    adds r1, r4, #0
    adds r1, #0x36
    strb r0, [r1]
    ldrb r0, [r2]
    movs r1, #7
    ands r1, r0
    cmp r1, #0
    bne lbl_08002336
    ldr r0, [r5, #4]
    b lbl_08002378
lbl_08002336:
    cmp r1, #2
    bhi lbl_08002362
    ldrb r1, [r5, #3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08002354
    movs r0, #0x70
    ands r0, r1
    cmp r0, #0
    beq lbl_08002354
    adds r0, r4, #0
    adds r0, #0x37
    strb r1, [r0]
    b lbl_0800235c
lbl_08002354:
    adds r1, r4, #0
    adds r1, #0x37
    movs r0, #8
    strb r0, [r1]
lbl_0800235c:
    ldr r0, [r5, #4]
    lsls r0, r0, #0x1e
    b lbl_08002376
lbl_08002362:
    cmp r1, #3
    bne lbl_0800236e
    ldr r0, [r5, #4]
    bl sub_080050d0
    b lbl_0800237a
lbl_0800236e:
    cmp r1, #4
    bne lbl_0800237a
    ldr r0, [r5, #4]
    lsls r0, r0, #0x1b
lbl_08002376:
    lsrs r0, r0, #0x18
lbl_08002378:
    str r0, [r4, #0x38]
lbl_0800237a:
    ldr r0, [r5, #8]
    str r0, [r4, #0x3c]
lbl_0800237e:
    ldr r0, [r4, #0x24]
    adds r0, #1
    str r0, [r4, #0x24]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start AudioCommand_Volume
AudioCommand_Volume: @ 0x0800238c
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    strb r1, [r0, #4]
    ldrb r3, [r0]
    movs r1, #4
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_PanPot
AudioCommand_PanPot: @ 0x080023a0
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    strb r1, [r0, #6]
    ldrb r3, [r0]
    movs r1, #4
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_PitchBend
AudioCommand_PitchBend: @ 0x080023b4
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    subs r1, #0x40
    strb r1, [r0, #0x19]
    ldrb r3, [r0]
    movs r1, #8
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start AudioCommand_BendRange
AudioCommand_BendRange: @ 0x080023cc
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    strb r1, [r0, #0x1a]
    ldrb r3, [r0]
    movs r1, #8
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_LfoSpeed
AudioCommand_LfoSpeed: @ 0x080023e0
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    adds r1, #1
    asrs r1, r1, #1
    strb r1, [r0, #0x10]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_LfoDelay
AudioCommand_LfoDelay: @ 0x080023f0
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x14]
    strb r2, [r0, #0x15]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start AudioCommand_ModulationDepth
AudioCommand_ModulationDepth: @ 0x08002400
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x11]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_ModulationType
AudioCommand_ModulationType: @ 0x0800240c
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x12]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start AudioCommand_Tune
AudioCommand_Tune: @ 0x08002418
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    subs r1, #0x40
    strb r1, [r0, #0x1e]
    ldrb r3, [r0]
    movs r1, #8
    orrs r1, r3
    strb r1, [r0]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start AudioCommand_ExtendCommand
AudioCommand_ExtendCommand: @ 0x08002430
    push {lr}
    adds r2, r0, #0
    ldr r1, [r2, #0x24]
    ldrb r0, [r1]
    cmp r0, #8
    bne lbl_08002448
    adds r0, r1, #1
    str r0, [r2, #0x24]
    ldrb r1, [r1, #1]
    strb r1, [r2, #0xc]
    adds r0, #1
    str r0, [r2, #0x24]
lbl_08002448:
    ldr r1, [r2, #0x24]
    ldrb r0, [r1]
    cmp r0, #9
    bne lbl_0800245c
    adds r0, r1, #1
    str r0, [r2, #0x24]
    ldrb r1, [r1, #1]
    strb r1, [r2, #0xd]
    adds r0, #1
    str r0, [r2, #0x24]
lbl_0800245c:
    pop {r0}
    bx r0

    thumb_func_start AudioCommand_EndOfTie
AudioCommand_EndOfTie: @ 0x08002460
    push {r4, lr}
    adds r3, r0, #0
    ldr r1, [r3, #0x24]
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    blt lbl_08002478
    ldrb r4, [r1]
    strb r4, [r3, #1]
    adds r0, r1, #1
    str r0, [r3, #0x24]
    b lbl_0800247a
lbl_08002478:
    ldrb r4, [r3, #1]
lbl_0800247a:
    ldr r0, [r3, #0x48]
    cmp r0, #0
    beq lbl_080024a0
    adds r1, r0, #0
    b lbl_0800248a
lbl_08002484:
    ldr r1, [r1, #0x30]
    cmp r1, #0
    beq lbl_080024a0
lbl_0800248a:
    ldrb r0, [r1]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bhi lbl_08002484
    ldrb r0, [r1, #6]
    cmp r0, r4
    bne lbl_08002484
    movs r0, #5
    strb r0, [r1]
lbl_080024a0:
    ldr r2, [r3, #0x4c]
    cmp r2, #0
    beq lbl_080024b6
    ldrb r0, [r2, #0x17]
    cmp r0, r4
    bne lbl_080024b6
    movs r0, #0
    movs r1, #5
    strb r1, [r2]
    ldr r1, [r3, #0x4c]
    strb r0, [r1, #0x18]
lbl_080024b6:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start Music_EmptyCommand
Music_EmptyCommand: @ 0x080024bc
    bx lr
    .align 2, 0

    thumb_func_start ClearRegistersForPsg
ClearRegistersForPsg: @ 0x080024c0
    push {lr}
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    adds r0, r1, #0
    cmp r1, #1
    beq lbl_080024f0
    cmp r1, #1
    bgt lbl_080024d6
    cmp r1, #0
    beq lbl_080024e0
    b lbl_08002514
lbl_080024d6:
    cmp r0, #2
    beq lbl_080024f8
    cmp r0, #3
    beq lbl_08002504
    b lbl_08002514
lbl_080024e0:
    ldr r1, lbl_080024ec @ =0x04000063
    movs r0, #8
    strb r0, [r1]
    adds r1, #1
    b lbl_0800250c
    .align 2, 0
lbl_080024ec: .4byte 0x04000063
lbl_080024f0:
    ldr r1, lbl_080024f4 @ =0x04000069
    b lbl_08002506
    .align 2, 0
lbl_080024f4: .4byte 0x04000069
lbl_080024f8:
    ldr r1, lbl_08002500 @ =0x04000070
    movs r0, #0
    strb r0, [r1]
    b lbl_08002514
    .align 2, 0
lbl_08002500: .4byte 0x04000070
lbl_08002504:
    ldr r1, lbl_08002518 @ =0x04000079
lbl_08002506:
    movs r0, #8
    strb r0, [r1]
    adds r1, #3
lbl_0800250c:
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    strh r0, [r1]
lbl_08002514:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002518: .4byte 0x04000079

    thumb_func_start sub_0800251c
sub_0800251c: @ 0x0800251c
    push {lr}
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #1
    beq lbl_08002544
    cmp r1, #1
    bgt lbl_08002530
    cmp r1, #0
    beq lbl_0800253a
    b lbl_0800255a
lbl_08002530:
    cmp r1, #2
    beq lbl_0800254c
    cmp r1, #3
    beq lbl_08002554
    b lbl_0800255a
lbl_0800253a:
    ldr r0, lbl_08002540 @ =0x04000063
    strb r1, [r0]
    b lbl_0800255a
    .align 2, 0
lbl_08002540: .4byte 0x04000063
lbl_08002544:
    ldr r1, lbl_08002548 @ =0x04000069
    b lbl_08002556
    .align 2, 0
lbl_08002548: .4byte 0x04000069
lbl_0800254c:
    ldr r1, lbl_08002550 @ =0x04000070
    b lbl_08002556
    .align 2, 0
lbl_08002550: .4byte 0x04000070
lbl_08002554:
    ldr r1, lbl_08002560 @ =0x04000079
lbl_08002556:
    movs r0, #0
    strb r0, [r1]
lbl_0800255a:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002560: .4byte 0x04000079

    thumb_func_start InitializeAudio
InitializeAudio: @ 0x08002564
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r5, lbl_0800276c @ =gMusicInfo
    ldrb r4, [r5, #1]
    cmp r4, #0
    beq lbl_08002576
    b lbl_08002760
lbl_08002576:
    movs r0, #1
    strb r0, [r5, #1]
    ldr r2, lbl_08002770 @ =0x04000200
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #3
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r2]
    ldr r0, lbl_08002774 @ =0x04000084
    movs r3, #0x80
    strb r3, [r0]
    ldr r1, lbl_08002778 @ =0x04000082
    ldr r2, lbl_0800277c @ =0x0000a90e
    adds r0, r2, #0
    strh r0, [r1]
    ldr r2, lbl_08002780 @ =0x04000089
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r0, lbl_08002784 @ =0x04000063
    movs r1, #8
    strb r1, [r0]
    adds r0, #2
    strb r3, [r0]
    adds r0, #4
    strb r1, [r0]
    adds r0, #4
    strb r3, [r0]
    adds r0, #0xc
    strb r1, [r0]
    adds r0, #4
    strb r3, [r0]
    subs r0, #0xd
    strb r4, [r0]
    ldr r1, lbl_08002788 @ =0x04000080
    movs r0, #0x77
    strb r0, [r1]
    ldr r0, lbl_0800278c @ =gSoundCodeAPointer
    ldr r1, lbl_08002790 @ =gSoundCodeA+0x1
    str r1, [r0]
    adds r2, #0x4b
    ldr r0, lbl_08002794 @ =call_soundcode_a
    str r0, [r2]
    subs r1, #1
    str r1, [r2, #4]
    ldr r0, lbl_08002798 @ =0x8000032c
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_0800279c @ =gSoundCodeBPointer
    ldr r0, lbl_080027a0 @ =gSoundCodeB+0x1
    str r0, [r1]
    ldr r1, lbl_080027a4 @ =call_soundcode_b
    str r1, [r2]
    subs r0, #1
    str r0, [r2, #4]
    ldr r0, lbl_080027a8 @ =0x80000052
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_080027ac @ =gSoundCodeCPointer
    ldr r0, lbl_080027b0 @ =gSoundCodeC+0x1
    str r0, [r1]
    ldr r1, lbl_080027b4 @ =call_soundcode_c
    str r1, [r2]
    subs r0, #1
    str r0, [r2, #4]
    ldr r0, lbl_080027b8 @ =0x80000058
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r0, sp
    strh r4, [r0]
    str r0, [r2]
    str r5, [r2, #4]
    ldr r0, lbl_080027bc @ =0x8100000e
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r0, lbl_080027c0 @ =0x00000064
    strb r0, [r5, #9]
    movs r3, #0
    ldr r5, lbl_080027c4 @ =0x00000009
    mov ip, r5
    ldr r0, lbl_080027c8 @ =0x0194f700
    mov r8, r0
    mov r1, sp
    movs r6, #0
    ldr r5, lbl_080027cc @ =gPsgSounds
    ldr r4, lbl_080027d0 @ =0x81000014
lbl_0800262a:
    strh r6, [r1]
    mov r0, sp
    str r0, [r2]
    lsls r0, r3, #2
    adds r0, r0, r3
    lsls r0, r0, #3
    adds r0, r0, r5
    str r0, [r2, #4]
    str r4, [r2, #8]
    ldr r0, [r2, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #3
    bls lbl_0800262a
    movs r3, #0
    mov r1, ip
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r3, r0
    bhs lbl_08002680
    mov r4, sp
    ldr r1, lbl_080027d4 @ =0x040000d4
    ldr r7, lbl_080027d8 @ =sMusicTrackDataRom
    adds r2, r0, #0
    movs r6, #0
    ldr r5, lbl_080027dc @ =0x81000016
lbl_08002660:
    strh r6, [r4]
    mov r0, sp
    str r0, [r1]
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    str r0, [r1, #4]
    str r5, [r1, #8]
    ldr r0, [r1, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r2
    blo lbl_08002660
lbl_08002680:
    movs r3, #0
    mov r1, ip
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r3, r0
    bhs lbl_080026b6
    ldr r4, lbl_080027d8 @ =sMusicTrackDataRom
    adds r6, r4, #4
    adds r5, r0, #0
lbl_08002692:
    lsls r0, r3, #1
    adds r0, r0, r3
    lsls r0, r0, #2
    adds r2, r0, r4
    ldr r1, [r2]
    adds r0, r0, r6
    ldr r0, [r0]
    str r0, [r1, #0x18]
    ldrh r0, [r2, #8]
    strb r0, [r1, #5]
    ldr r1, [r2]
    ldrh r0, [r2, #0xa]
    strb r0, [r1, #0x1d]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r5
    blo lbl_08002692
lbl_080026b6:
    mov r0, r8
    bl DoSoundAction
    movs r3, #0
    ldr r2, lbl_0800276c @ =gMusicInfo
    ldrb r0, [r2, #5]
    cmp r3, r0
    bhs lbl_080026f6
    mov r4, sp
    movs r5, #0
    mov ip, r5
    ldr r1, lbl_080027d4 @ =0x040000d4
    ldr r5, lbl_080027e0 @ =0x00001824
    adds r7, r2, r5
    adds r2, r0, #0
    movs r6, #0x34
    ldr r5, lbl_080027e4 @ =0x8100001a
lbl_080026d8:
    mov r0, ip
    strh r0, [r4]
    mov r0, sp
    str r0, [r1]
    adds r0, r3, #0
    muls r0, r6, r0
    adds r0, r0, r7
    str r0, [r1, #4]
    str r5, [r1, #8]
    ldr r0, [r1, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r2
    blo lbl_080026d8
lbl_080026f6:
    movs r3, #0
    ldr r1, lbl_0800276c @ =gMusicInfo
    mov r8, r1
    ldr r2, lbl_080027c4 @ =0x00000009
    mov ip, r2
    mov r2, sp
    movs r6, #0
    ldr r1, lbl_080027d4 @ =0x040000d4
    ldr r5, lbl_080027e8 @ =gSoundChannelBackup
    ldr r4, lbl_080027ec @ =0x8100001c
lbl_0800270a:
    strh r6, [r2]
    mov r0, sp
    str r0, [r1]
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r0, r0, r5
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #6
    bls lbl_0800270a
    movs r3, #0
    mov r1, ip
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r3, r0
    bhs lbl_0800275a
    mov r4, sp
    movs r7, #0
    ldr r1, lbl_080027d4 @ =0x040000d4
    adds r2, r0, #0
    ldr r6, lbl_080027f0 @ =gSoundQueue
    ldr r5, lbl_080027f4 @ =0x81000004
lbl_08002740:
    strh r7, [r4]
    mov r0, sp
    str r0, [r1]
    lsls r0, r3, #3
    adds r0, r0, r6
    str r0, [r1, #4]
    str r5, [r1, #8]
    ldr r0, [r1, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, r2
    blo lbl_08002740
lbl_0800275a:
    movs r0, #0
    mov r1, r8
    strb r0, [r1, #1]
lbl_08002760:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800276c: .4byte gMusicInfo
lbl_08002770: .4byte 0x04000200
lbl_08002774: .4byte 0x04000084
lbl_08002778: .4byte 0x04000082
lbl_0800277c: .4byte 0x0000a90e
lbl_08002780: .4byte 0x04000089
lbl_08002784: .4byte 0x04000063
lbl_08002788: .4byte 0x04000080
lbl_0800278c: .4byte gSoundCodeAPointer
lbl_08002790: .4byte gSoundCodeA+0x1
lbl_08002794: .4byte call_soundcode_a
lbl_08002798: .4byte 0x8000032c
lbl_0800279c: .4byte gSoundCodeBPointer
lbl_080027a0: .4byte gSoundCodeB+0x1
lbl_080027a4: .4byte call_soundcode_b
lbl_080027a8: .4byte 0x80000052
lbl_080027ac: .4byte gSoundCodeCPointer
lbl_080027b0: .4byte gSoundCodeC+0x1
lbl_080027b4: .4byte call_soundcode_c
lbl_080027b8: .4byte 0x80000058
lbl_080027bc: .4byte 0x8100000e
lbl_080027c0: .4byte 0x00000064
lbl_080027c4: .4byte 0x00000009
lbl_080027c8: .4byte 0x0194f700
lbl_080027cc: .4byte gPsgSounds
lbl_080027d0: .4byte 0x81000014
lbl_080027d4: .4byte 0x040000d4
lbl_080027d8: .4byte sMusicTrackDataRom
lbl_080027dc: .4byte 0x81000016
lbl_080027e0: .4byte 0x00001824
lbl_080027e4: .4byte 0x8100001a
lbl_080027e8: .4byte gSoundChannelBackup
lbl_080027ec: .4byte 0x8100001c
lbl_080027f0: .4byte gSoundQueue
lbl_080027f4: .4byte 0x81000004

    thumb_func_start DoSoundAction
DoSoundAction: @ 0x080027f8
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldr r0, lbl_080028a8 @ =gMusicInfo
    ldrb r1, [r0, #1]
    adds r2, r0, #0
    cmp r1, #0
    bne lbl_080028de
    movs r0, #1
    strb r0, [r2, #1]
    movs r0, #0x80
    ands r0, r4
    cmp r0, #0
    beq lbl_08002818
    adds r0, r4, #0
    adds r0, #0x80
    strb r0, [r2, #4]
lbl_08002818:
    movs r0, #0xf0
    lsls r0, r0, #4
    ands r0, r4
    cmp r0, #0
    beq lbl_08002848
    lsrs r0, r0, #8
    strb r0, [r2, #5]
    movs r0, #0xb
    adds r7, r2, #0
    movs r6, #0x34
    ldr r5, lbl_080028ac @ =0x00001824
    movs r3, #0
lbl_08002830:
    lsls r1, r0, #0x18
    asrs r1, r1, #0x18
    adds r0, r1, #0
    muls r0, r6, r0
    adds r0, r0, r7
    adds r0, r0, r5
    strb r3, [r0]
    subs r1, #1
    lsls r1, r1, #0x18
    lsrs r0, r1, #0x18
    cmp r1, #0
    bge lbl_08002830
lbl_08002848:
    movs r0, #0xf0
    lsls r0, r0, #8
    ands r0, r4
    cmp r0, #0
    beq lbl_08002856
    lsrs r0, r0, #0xc
    strb r0, [r2, #6]
lbl_08002856:
    movs r0, #0xf0
    lsls r0, r0, #0xc
    ands r0, r4
    cmp r0, #0
    beq lbl_0800286e
    ldr r1, lbl_080028a8 @ =gMusicInfo
    lsrs r0, r0, #0x10
    strb r0, [r1, #7]
    cmp r0, #0
    beq lbl_0800286e
    bl sub_080028f4
lbl_0800286e:
    movs r3, #0xf0
    lsls r3, r3, #0x10
    ands r3, r4
    cmp r3, #0
    beq lbl_08002886
    ldr r2, lbl_080028b0 @ =0x04000089
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    lsrs r1, r3, #0xe
    orrs r0, r1
    strb r0, [r2]
lbl_08002886:
    movs r1, #0xf0
    lsls r1, r1, #0x14
    ands r1, r4
    cmp r1, #0
    beq lbl_080028d8
    movs r0, #0x80
    lsls r0, r0, #0x12
    cmp r1, r0
    bne lbl_080028bc
    ldr r2, lbl_080028b4 @ =0x04000082
    ldrh r1, [r2]
    ldr r0, lbl_080028b8 @ =0x0000e10d
    ands r0, r1
    strh r0, [r2]
    ldrh r0, [r2]
    movs r1, #1
    b lbl_080028d4
    .align 2, 0
lbl_080028a8: .4byte gMusicInfo
lbl_080028ac: .4byte 0x00001824
lbl_080028b0: .4byte 0x04000089
lbl_080028b4: .4byte 0x04000082
lbl_080028b8: .4byte 0x0000e10d
lbl_080028bc:
    movs r0, #0x80
    lsls r0, r0, #0x11
    cmp r1, r0
    bne lbl_080028d8
    ldr r2, lbl_080028e4 @ =0x04000082
    ldrh r1, [r2]
    ldr r0, lbl_080028e8 @ =0x0000fffe
    ands r0, r1
    strh r0, [r2]
    ldrh r0, [r2]
    ldr r3, lbl_080028ec @ =0x00003302
    adds r1, r3, #0
lbl_080028d4:
    orrs r0, r1
    strh r0, [r2]
lbl_080028d8:
    ldr r1, lbl_080028f0 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_080028de:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080028e4: .4byte 0x04000082
lbl_080028e8: .4byte 0x0000fffe
lbl_080028ec: .4byte 0x00003302
lbl_080028f0: .4byte gMusicInfo

    thumb_func_start sub_080028f4
sub_080028f4: @ 0x080028f4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_080029d8 @ =0x040000c4
    ldr r1, lbl_080029dc @ =0x84400004
    str r1, [r0]
    adds r0, #0xc
    str r1, [r0]
    ldr r7, lbl_080029e0 @ =0x040000c6
    movs r1, #0x80
    lsls r1, r1, #3
    adds r0, r1, #0
    strh r0, [r7]
    ldr r1, lbl_080029e4 @ =0x040000d2
    mov sb, r1
    strh r0, [r1]
    movs r0, #0
    mov sl, r0
    str r0, [sp]
    ldr r6, lbl_080029e8 @ =gMusicInfo+0xC24
    ldr r2, lbl_080029ec @ =0x01000300
    mov r0, sp
    adds r1, r6, #0
    bl CpuFastSet
    ldr r1, lbl_080029f0 @ =0xfffff3dc
    adds r4, r6, r1
    ldr r1, lbl_080029f4 @ =sNativeSampleRate
    ldrb r0, [r4, #7]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    strh r0, [r4, #0x12]
    ldr r1, lbl_080029f8 @ =sMusicPitchData
    ldrb r0, [r4, #7]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r4, #0x18]
    ldr r1, lbl_080029fc @ =sAudio_8ccc8
    ldrb r0, [r4, #7]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r8, r0
    str r0, [r4, #0x14]
    lsrs r5, r0, #4
    strb r5, [r4, #0xc]
    ldrb r1, [r4, #0xc]
    movs r0, #0x60
    bl __divsi3
    strb r0, [r4, #0xd]
    muls r0, r5, r0
    strb r0, [r4, #0xe]
    subs r0, #1
    strb r0, [r4, #0x10]
    lsls r5, r5, #1
    strb r5, [r4, #0x11]
    ldr r0, lbl_08002a00 @ =0x040000bc
    str r6, [r0]
    adds r0, #0xc
    movs r1, #0xc0
    lsls r1, r1, #3
    adds r6, r6, r1
    str r6, [r0]
    ldr r1, lbl_08002a04 @ =0x040000c0
    subs r0, #0x28
    str r0, [r1]
    adds r1, #0xc
    adds r0, #4
    str r0, [r1]
    movs r1, #0xb6
    lsls r1, r1, #8
    adds r0, r1, #0
    strh r0, [r7]
    movs r1, #0xf6
    lsls r1, r1, #8
    adds r0, r1, #0
    mov r1, sb
    strh r0, [r1]
    ldr r0, lbl_08002a08 @ =0x04000102
    mov r1, sl
    strh r1, [r0]
    ldr r4, lbl_08002a0c @ =0x04000100
    ldr r0, lbl_08002a10 @ =0x00044940
    mov r1, r8
    bl __udivsi3
    rsbs r0, r0, #0
    strh r0, [r4]
    ldr r1, lbl_08002a14 @ =0x04000006
lbl_080029b2:
    ldrb r0, [r1]
    cmp r0, #0x9f
    beq lbl_080029b2
    ldr r1, lbl_08002a14 @ =0x04000006
lbl_080029ba:
    ldrb r0, [r1]
    cmp r0, #0x9f
    bne lbl_080029ba
    ldr r1, lbl_08002a08 @ =0x04000102
    movs r0, #0x80
    strh r0, [r1]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080029d8: .4byte 0x040000c4
lbl_080029dc: .4byte 0x84400004
lbl_080029e0: .4byte 0x040000c6
lbl_080029e4: .4byte 0x040000d2
lbl_080029e8: .4byte gMusicInfo+0xC24
lbl_080029ec: .4byte 0x01000300
lbl_080029f0: .4byte 0xfffff3dc
lbl_080029f4: .4byte sNativeSampleRate
lbl_080029f8: .4byte sMusicPitchData
lbl_080029fc: .4byte gPcmSamplesPerVBlankTable
lbl_08002a00: .4byte 0x040000bc
lbl_08002a04: .4byte 0x040000c0
lbl_08002a08: .4byte 0x04000102
lbl_08002a0c: .4byte 0x04000100
lbl_08002a10: .4byte 0x00044940
lbl_08002a14: .4byte 0x04000006
