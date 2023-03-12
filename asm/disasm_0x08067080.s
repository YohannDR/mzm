    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start enter_tourian_anim
enter_tourian_anim: @ 0x08067080
    push {r4, r5, r6, lr}
    ldr r0, lbl_08067098 @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #9
    bls lbl_0806708e
    b lbl_080672fe
lbl_0806708e:
    lsls r0, r0, #2
    ldr r1, lbl_0806709c @ =lbl_080670a0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08067098: .4byte 0x08754bc4
lbl_0806709c: .4byte lbl_080670a0
lbl_080670a0: @ jump table
    .4byte lbl_080670c8 @ case 0
    .4byte lbl_080670e0 @ case 1
    .4byte lbl_08067106 @ case 2
    .4byte lbl_0806712c @ case 3
    .4byte lbl_080671b8 @ case 4
    .4byte lbl_080671e0 @ case 5
    .4byte lbl_08067220 @ case 6
    .4byte lbl_0806723c @ case 7
    .4byte lbl_080672cc @ case 8
    .4byte lbl_080672e8 @ case 9
lbl_080670c8:
    bl unk_61f44
    cmp r0, #0
    bne lbl_080670d2
    b lbl_080672fe
lbl_080670d2:
    ldr r0, lbl_080670dc @ =0x00000295
    bl SoundPlay
    b lbl_080672d4
    .align 2, 0
lbl_080670dc: .4byte 0x00000295
lbl_080670e0:
    ldr r5, lbl_080670fc @ =0x08754bc4
    ldr r1, [r5]
    ldrb r4, [r1, #0xa]
    cmp r4, #0
    bne lbl_08067100
    ldrh r0, [r1, #0x1e]
    movs r1, #0
    movs r2, #8
    movs r3, #1
    bl CutsceneStartSpriteEffect
    ldr r1, [r5]
    strh r4, [r1, #2]
    b lbl_080672dc
    .align 2, 0
lbl_080670fc: .4byte 0x08754bc4
lbl_08067100:
    movs r0, #0
    strh r0, [r1, #2]
    b lbl_080672fe
lbl_08067106:
    ldr r0, lbl_08067128 @ =0x08754bc4
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0xa8
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0806711a
    b lbl_080672fe
lbl_0806711a:
    movs r0, #0
    strh r0, [r2, #2]
    ldrb r0, [r2, #4]
    adds r0, #1
    strb r0, [r2, #4]
    b lbl_080672fe
    .align 2, 0
lbl_08067128: .4byte 0x08754bc4
lbl_0806712c:
    ldr r4, lbl_0806714c @ =0x08754bc4
    ldr r1, [r4]
    ldrh r0, [r1, #2]
    cmp r0, #8
    bne lbl_08067158
    ldr r0, lbl_08067150 @ =0x0000011d
    adds r2, r1, r0
    ldrb r0, [r2]
    movs r1, #2
    orrs r1, r0
    strb r1, [r2]
    ldr r0, lbl_08067154 @ =0x00000296
    bl SoundPlay
    b lbl_080672fe
    .align 2, 0
lbl_0806714c: .4byte 0x08754bc4
lbl_08067150: .4byte 0x0000011d
lbl_08067154: .4byte 0x00000296
lbl_08067158:
    cmp r0, #0x5a
    bne lbl_08067170
    ldr r0, lbl_0806716c @ =0x0000015d
    adds r2, r1, r0
    ldrb r1, [r2]
    movs r0, #2
    orrs r0, r1
    strb r0, [r2]
    b lbl_080672fe
    .align 2, 0
lbl_0806716c: .4byte 0x0000015d
lbl_08067170:
    cmp r0, #0x64
    bne lbl_08067198
    ldr r0, lbl_08067190 @ =0x0000019d
    adds r1, r1, r0
    ldrb r0, [r1]
    movs r2, #2
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r4]
    ldr r1, lbl_08067194 @ =0x000001fd
    adds r0, r0, r1
    ldrb r1, [r0]
    orrs r2, r1
    strb r2, [r0]
    b lbl_080672fe
    .align 2, 0
lbl_08067190: .4byte 0x0000019d
lbl_08067194: .4byte 0x000001fd
lbl_08067198:
    cmp r0, #0x77
    bhi lbl_0806719e
    b lbl_080672fe
lbl_0806719e:
    ldr r0, lbl_080671b4 @ =0x000001dd
    adds r3, r1, r0
    ldrb r1, [r3]
    movs r0, #2
    movs r2, #0
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r4]
    strh r2, [r1, #2]
    b lbl_080672dc
    .align 2, 0
lbl_080671b4: .4byte 0x000001dd
lbl_080671b8:
    ldr r3, lbl_080671dc @ =0x08754bc4
    ldr r2, [r3]
    ldrh r1, [r2, #2]
    movs r0, #0x96
    lsls r0, r0, #1
    cmp r1, r0
    bhi lbl_080671c8
    b lbl_080672fe
lbl_080671c8:
    subs r0, #0x12
    adds r1, r2, r0
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r1, [r3]
    strh r2, [r1, #2]
    b lbl_080672dc
    .align 2, 0
lbl_080671dc: .4byte 0x08754bc4
lbl_080671e0:
    ldr r4, lbl_08067214 @ =0x08754bc4
    ldr r2, [r4]
    ldr r1, lbl_08067218 @ =0x0000011b
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    bne lbl_080671fe
    ldrh r1, [r2, #2]
    movs r0, #0x96
    lsls r0, r0, #1
    cmp r1, r0
    bhi lbl_080671fe
    b lbl_080672fe
lbl_080671fe:
    ldr r0, lbl_0806721c @ =0x0000011d
    adds r3, r2, r0
    ldrb r1, [r3]
    movs r0, #0xfb
    ands r0, r1
    movs r2, #0
    strb r0, [r3]
    ldr r1, [r4]
    strh r2, [r1, #2]
    b lbl_080672dc
    .align 2, 0
lbl_08067214: .4byte 0x08754bc4
lbl_08067218: .4byte 0x0000011b
lbl_0806721c: .4byte 0x0000011d
lbl_08067220:
    ldr r4, lbl_08067234 @ =0x08754bc4
    ldr r0, [r4]
    ldrh r0, [r0, #2]
    cmp r0, #0x3c
    bls lbl_080672fe
    ldr r0, lbl_08067238 @ =0x00000297
    bl SoundPlay
    ldr r1, [r4]
    b lbl_080672d8
    .align 2, 0
lbl_08067234: .4byte 0x08754bc4
lbl_08067238: .4byte 0x00000297
lbl_0806723c:
    ldr r4, lbl_080672a4 @ =gCurrentOamScaling
    ldrh r0, [r4]
    adds r0, #8
    strh r0, [r4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #0x80
    lsls r1, r1, #2
    cmp r0, r1
    bls lbl_08067266
    strh r1, [r4]
    movs r0, #8
    bl unk_61fa0
    ldr r0, lbl_080672a8 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #2]
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
lbl_08067266:
    ldr r3, lbl_080672a8 @ =0x08754bc4
    ldr r1, [r3]
    ldr r2, lbl_080672ac @ =0x00000119
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #6
    beq lbl_08067290
    movs r0, #0x8d
    lsls r0, r0, #1
    adds r1, r1, r0
    movs r0, #5
    strb r0, [r1]
    ldrh r1, [r4]
    movs r0, #0xd0
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_08067290
    ldr r0, [r3]
    adds r0, r0, r2
    movs r1, #6
    strb r1, [r0]
lbl_08067290:
    ldr r0, lbl_080672a4 @ =gCurrentOamScaling
    ldrh r1, [r0]
    lsls r2, r1, #0x10
    movs r0, #0xd8
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_080672b0
    movs r4, #6
    rsbs r4, r4, #0
    b lbl_080672b6
    .align 2, 0
lbl_080672a4: .4byte gCurrentOamScaling
lbl_080672a8: .4byte 0x08754bc4
lbl_080672ac: .4byte 0x00000119
lbl_080672b0:
    lsrs r1, r2, #0x16
    movs r0, #0x10
    subs r4, r0, r1
lbl_080672b6:
    ldr r0, lbl_080672c8 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0x88
    lsls r0, r0, #1
    adds r1, r1, r0
    ldrh r0, [r1]
    adds r0, r0, r4
    strh r0, [r1]
    b lbl_080672fe
    .align 2, 0
lbl_080672c8: .4byte 0x08754bc4
lbl_080672cc:
    bl unk_61f44
    cmp r0, #0
    beq lbl_080672fe
lbl_080672d4:
    ldr r0, lbl_080672e4 @ =0x08754bc4
    ldr r1, [r0]
lbl_080672d8:
    movs r0, #0
    strh r0, [r1, #2]
lbl_080672dc:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_080672fe
    .align 2, 0
lbl_080672e4: .4byte 0x08754bc4
lbl_080672e8:
    bl unk_61f0c
    ldr r3, lbl_0806733c @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_080672fe:
    bl sub_08067390
    movs r4, #1
    ldr r6, lbl_0806733c @ =0x08754bc4
    movs r5, #0x88
    lsls r5, r5, #1
lbl_0806730a:
    ldr r0, [r6]
    adds r0, r0, r5
    subs r1, r4, #1
    lsrs r2, r1, #0x1f
    adds r1, r1, r2
    asrs r1, r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl sub_080673e0
    adds r5, #0x40
    adds r4, #2
    cmp r4, #7
    ble lbl_0806730a
    movs r3, #0
    movs r4, #1
    ldr r2, lbl_0806733c @ =0x08754bc4
    ldr r0, [r2]
    ldr r1, lbl_08067340 @ =0x0000011d
    adds r0, r0, r1
    ldrb r1, [r0]
    adds r0, r4, #0
    ands r0, r1
    adds r5, r2, #0
    b lbl_08067358
    .align 2, 0
lbl_0806733c: .4byte 0x08754bc4
lbl_08067340: .4byte 0x0000011d
lbl_08067344:
    adds r4, #2
    cmp r4, #7
    bgt lbl_0806735e
    ldr r0, [r5]
    lsls r1, r4, #5
    adds r0, r0, r1
    adds r0, #0xfd
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
lbl_08067358:
    cmp r0, #0
    beq lbl_08067344
    movs r3, #1
lbl_0806735e:
    ldr r0, [r5]
    adds r0, #0xc
    adds r4, r3, #0
    adds r1, r4, #0
    bl sub_08067758
    ldr r0, [r5]
    ldr r1, lbl_0806738c @ =0x000001fd
    adds r0, r0, r1
    ldrb r1, [r0]
    orrs r4, r1
    strb r4, [r0]
    ldr r0, [r5]
    movs r1, #0xf8
    lsls r1, r1, #1
    adds r0, r0, r1
    bl sub_080677e4
    movs r0, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806738c: .4byte 0x000001fd

    thumb_func_start sub_08067390
sub_08067390: @ 0x08067390
    push {r4, lr}
    ldr r4, lbl_080673d8 @ =0x08754bc4
    ldr r0, [r4]
    ldrb r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_080673d2
    ldr r0, lbl_080673dc @ =0x083f0390
    ldrh r0, [r0, #0xc]
    bl CutsceneGetBGHOFSPointer
    adds r1, r0, #0
    ldrh r0, [r1]
    movs r2, #0xac
    lsls r2, r2, #3
    cmp r0, r2
    bls lbl_080673bc
    subs r0, #2
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r2
    bhi lbl_080673c2
lbl_080673bc:
    ldr r1, [r4]
    movs r0, #0
    strb r0, [r1, #0xa]
lbl_080673c2:
    ldr r0, lbl_080673dc @ =0x083f0390
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    adds r1, r0, #0
    ldrh r0, [r1]
    subs r0, #1
    strh r0, [r1]
lbl_080673d2:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080673d8: .4byte 0x08754bc4
lbl_080673dc: .4byte 0x083f0390

    thumb_func_start sub_080673e0
sub_080673e0: @ 0x080673e0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    adds r4, r0, #0
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    subs r0, #0x20
    str r0, [sp, #4]
    ldrb r1, [r4, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806741c
    adds r0, r4, #0
    movs r1, #3
    bl UpdateCutsceneOamDataID
    ldrb r1, [r4, #0xd]
    movs r0, #0xfe
    ands r0, r1
    movs r2, #0
    movs r1, #2
    eors r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r4, #0xd]
    strh r2, [r4, #0x14]
lbl_0806741c:
    ldrb r1, [r4, #0xd]
    movs r5, #1
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0806742a
    b lbl_0806751c
lbl_0806742a:
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_08067444 @ =0x0000ffff
    cmp r1, r0
    beq lbl_08067436
    adds r0, r1, #1
    strh r0, [r4, #0x14]
lbl_08067436:
    ldrh r0, [r4, #0x16]
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_08067448
    subs r0, #1
    b lbl_0806749c
    .align 2, 0
lbl_08067444: .4byte 0x0000ffff
lbl_08067448:
    ldrh r1, [r4, #0xe]
    movs r3, #0xe
    ldrsh r0, [r4, r3]
    cmp r0, #0
    beq lbl_08067464
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    strh r2, [r4, #0xe]
    ldr r2, lbl_08067460 @ =0x0808c99c
    ldrh r6, [r4, #0x14]
    b lbl_0806748c
    .align 2, 0
lbl_08067460: .4byte 0x0808c99c
lbl_08067464:
    ldr r2, lbl_080674ac @ =0x0808c99c
    ldrh r3, [r4, #0x14]
    adds r0, r3, r7
    movs r1, #0xff
    ands r0, r1
    adds r0, r0, r2
    ldrb r1, [r0]
    adds r0, r5, #0
    ands r0, r1
    movs r1, #4
    adds r6, r3, #0
    cmp r0, #0
    beq lbl_08067484
    movs r5, #4
    rsbs r5, r5, #0
    adds r1, r5, #0
lbl_08067484:
    strh r1, [r4, #0xe]
    ldrh r3, [r4, #2]
    adds r0, r1, r3
    strh r0, [r4, #2]
lbl_0806748c:
    subs r0, r6, r7
    movs r1, #0xff
    ands r0, r1
    adds r0, r0, r2
    ldrb r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    adds r0, #8
lbl_0806749c:
    strh r0, [r4, #0x16]
    ldrh r0, [r4, #0x18]
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_080674b0
    subs r0, #1
    strh r0, [r4, #0x18]
    b lbl_080676f4
    .align 2, 0
lbl_080674ac: .4byte 0x0808c99c
lbl_080674b0:
    ldrh r1, [r4, #0x10]
    movs r5, #0x10
    ldrsh r0, [r4, r5]
    cmp r0, #0
    beq lbl_080674cc
    ldrh r0, [r4]
    subs r0, r0, r1
    strh r0, [r4]
    strh r2, [r4, #0x10]
    ldr r2, lbl_080674c8 @ =0x0808c99c
    ldrh r6, [r4, #0x14]
    b lbl_080674f4
    .align 2, 0
lbl_080674c8: .4byte 0x0808c99c
lbl_080674cc:
    ldr r2, lbl_08067518 @ =0x0808c99c
    ldrh r3, [r4, #0x14]
    adds r0, r3, r7
    movs r1, #0xff
    ands r0, r1
    adds r0, r0, r2
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    movs r1, #4
    adds r6, r3, #0
    cmp r0, #0
    beq lbl_080674ec
    movs r0, #4
    rsbs r0, r0, #0
    adds r1, r0, #0
lbl_080674ec:
    strh r1, [r4, #0x10]
    ldrh r3, [r4]
    adds r0, r1, r3
    strh r0, [r4]
lbl_080674f4:
    subs r0, r6, r7
    movs r1, #0xff
    ands r0, r1
    adds r0, r0, r2
    ldrb r0, [r0]
    movs r1, #0x3f
    ands r1, r0
    adds r0, r1, #0
    adds r0, #8
    strh r0, [r4, #0x18]
    ldrh r5, [r4, #0x16]
    cmp r0, r5
    beq lbl_08067510
    b lbl_080676f4
lbl_08067510:
    adds r0, #0x10
    strh r0, [r4, #0x18]
    b lbl_080676f4
    .align 2, 0
lbl_08067518: .4byte 0x0808c99c
lbl_0806751c:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_08067526
    b lbl_080676f4
lbl_08067526:
    ldrh r1, [r4, #0x14]
    ldr r0, lbl_08067550 @ =0x0000ffff
    cmp r1, r0
    beq lbl_08067532
    adds r0, r1, #1
    strh r0, [r4, #0x14]
lbl_08067532:
    movs r6, #0x3c
    str r6, [sp]
    cmp r7, #0
    bne lbl_0806753e
    movs r0, #0xb4
    str r0, [sp]
lbl_0806753e:
    ldrh r6, [r4, #0x14]
    ldr r1, [sp]
    cmp r6, r1
    bge lbl_08067554
    movs r2, #1
    mov sl, r2
    movs r3, #2
    str r3, [sp]
    b lbl_0806755c
    .align 2, 0
lbl_08067550: .4byte 0x0000ffff
lbl_08067554:
    movs r5, #2
    mov sl, r5
    movs r0, #1
    str r0, [sp]
lbl_0806755c:
    ldrh r0, [r4, #0x16]
    adds r0, #1
    strh r0, [r4, #0x16]
    ldrh r2, [r4, #0xe]
    mov r1, sp
    strh r2, [r1, #8]
    movs r3, #0xe
    ldrsh r0, [r4, r3]
    cmp r0, #0
    bne lbl_080675d4
    ldr r2, lbl_080675c4 @ =0x087600b4
    lsls r3, r7, #2
    adds r0, r3, r2
    ldrh r1, [r0]
    ldrh r0, [r4, #2]
    subs r1, r1, r0
    mov ip, r1
    mov r5, ip
    strh r5, [r4, #0xe]
    ldr r0, lbl_080675c8 @ =0x0808c99c
    mov sl, r0
    adds r0, r6, #0
    muls r0, r7, r0
    movs r1, #0xff
    mov r8, r1
    ands r0, r1
    add r0, sl
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    movs r5, #1
    rsbs r5, r5, #0
    mov sb, r3
    cmp r0, #0
    beq lbl_080675a4
    movs r5, #1
lbl_080675a4:
    adds r0, r6, r7
    mov r2, r8
    ands r0, r2
    add r0, sl
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    muls r5, r0, r5
    mov r3, ip
    lsls r0, r3, #0x10
    cmp r0, #0
    ble lbl_080675cc
    lsls r0, r5, #2
    adds r0, #0x20
    strh r0, [r4, #0xe]
    b lbl_0806765a
    .align 2, 0
lbl_080675c4: .4byte 0x087600b4
lbl_080675c8: .4byte 0x0808c99c
lbl_080675cc:
    lsls r0, r5, #2
    subs r0, #0x20
    strh r0, [r4, #0xe]
    b lbl_0806765a
lbl_080675d4:
    cmp r0, #0
    ble lbl_08067618
    ldr r1, lbl_08067614 @ =0x087600b4
    lsls r2, r7, #2
    adds r0, r2, r1
    movs r3, #0
    ldrsh r5, [r0, r3]
    mov ip, r5
    movs r5, #2
    ldrsh r0, [r4, r5]
    ldrh r3, [r4, #2]
    mov r8, r3
    mov sb, r2
    cmp ip, r0
    bgt lbl_080675fa
    mov r5, sp
    ldrh r0, [r5, #8]
    subs r0, #2
    strh r0, [r4, #0xe]
lbl_080675fa:
    movs r1, #0xe
    ldrsh r0, [r4, r1]
    movs r1, #0xc
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    adds r5, r0, #1
    cmp r5, sl
    ble lbl_08067654
    mov r5, sl
    b lbl_08067654
    .align 2, 0
lbl_08067614: .4byte 0x087600b4
lbl_08067618:
    ldr r1, lbl_080676b4 @ =0x087600b4
    lsls r2, r7, #2
    adds r0, r2, r1
    movs r5, #0
    ldrsh r3, [r0, r5]
    mov ip, r3
    movs r3, #2
    ldrsh r0, [r4, r3]
    ldrh r5, [r4, #2]
    mov r8, r5
    mov sb, r2
    cmp ip, r0
    blt lbl_0806763a
    mov r1, sp
    ldrh r0, [r1, #8]
    adds r0, #2
    strh r0, [r4, #0xe]
lbl_0806763a:
    movs r2, #0xe
    ldrsh r0, [r4, r2]
    movs r1, #0xc
    bl __divsi3
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    subs r5, r0, #1
    mov r3, sl
    rsbs r0, r3, #0
    cmp r5, r0
    bge lbl_08067654
    adds r5, r0, #0
lbl_08067654:
    mov r1, r8
    adds r0, r1, r5
    strh r0, [r4, #2]
lbl_0806765a:
    ldrh r0, [r4, #0x18]
    adds r1, r0, #1
    strh r1, [r4, #0x18]
    ldrh r3, [r4, #0x10]
    movs r5, #0x10
    ldrsh r2, [r4, r5]
    cmp r2, #0
    bne lbl_080676c8
    ldr r3, lbl_080676b8 @ =0x0808c99c
    ldrb r0, [r4, #8]
    ldrb r1, [r4, #9]
    adds r0, r0, r1
    movs r2, #0xff
    ands r0, r2
    adds r0, r0, r3
    ldrb r1, [r0]
    movs r0, #2
    ands r0, r1
    movs r5, #1
    rsbs r5, r5, #0
    cmp r0, #0
    beq lbl_08067688
    movs r5, #1
lbl_08067688:
    adds r0, r6, r7
    ands r0, r2
    adds r0, r0, r3
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    muls r5, r0, r5
    ldr r0, lbl_080676b4 @ =0x087600b4
    adds r0, #2
    add r0, sb
    ldrh r2, [r0]
    movs r6, #0
    ldrsh r1, [r0, r6]
    ldrh r3, [r4]
    movs r6, #0
    ldrsh r0, [r4, r6]
    cmp r1, r0
    bge lbl_080676bc
    adds r0, r5, #4
    lsls r0, r0, #2
    subs r0, r2, r0
    b lbl_080676c2
    .align 2, 0
lbl_080676b4: .4byte 0x087600b4
lbl_080676b8: .4byte 0x0808c99c
lbl_080676bc:
    adds r0, r5, #4
    lsls r0, r0, #2
    adds r0, r2, r0
lbl_080676c2:
    subs r0, r0, r3
    strh r0, [r4, #0x10]
    b lbl_080676f4
lbl_080676c8:
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_080676f4
    cmp r2, #0
    ble lbl_080676d8
    subs r0, r3, #1
    b lbl_080676da
lbl_080676d8:
    adds r0, r3, #1
lbl_080676da:
    strh r0, [r4, #0x10]
    movs r0, #0
    ldrsh r1, [r4, r0]
    movs r2, #0x10
    ldrsh r0, [r4, r2]
    cmp r0, #0
    bgt lbl_080676ee
    ldr r3, [sp]
    subs r0, r1, r3
    b lbl_080676f2
lbl_080676ee:
    ldr r5, [sp]
    adds r0, r1, r5
lbl_080676f2:
    strh r0, [r4]
lbl_080676f4:
    ldrh r0, [r4]
    ldr r6, [sp, #4]
    strh r0, [r6]
    ldrh r0, [r4, #2]
    strh r0, [r6, #2]
    ldr r0, lbl_0806774c @ =0x083f0390
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    ldrh r1, [r0]
    movs r2, #2
    ldrsh r0, [r4, r2]
    subs r5, r1, r0
    ldr r3, lbl_08067750 @ =0x000007df
    adds r1, r5, r3
    ldr r0, lbl_08067754 @ =0x00000bde
    movs r5, #1
    cmp r1, r0
    bhi lbl_0806771c
    movs r5, #0
lbl_0806771c:
    movs r0, #1
    ands r5, r0
    lsls r3, r5, #5
    ldrb r2, [r4, #0xb]
    movs r1, #0x21
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    orrs r0, r3
    strb r0, [r4, #0xb]
    ldr r5, [sp, #4]
    ldrb r0, [r5, #0xb]
    ands r1, r0
    orrs r1, r3
    strb r1, [r5, #0xb]
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806774c: .4byte 0x083f0390
lbl_08067750: .4byte 0x000007df
lbl_08067754: .4byte 0x00000bde

    thumb_func_start sub_08067758
sub_08067758: @ 0x08067758
    push {lr}
    sub sp, #4
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r1, #1
    bne lbl_080677bc
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_0806777a
    movs r0, #0
    strb r1, [r2]
    strb r0, [r2, #1]
    strb r0, [r2, #2]
    movs r0, #0x20
    strb r0, [r2, #3]
    b lbl_080677d6
lbl_0806777a:
    ldrb r0, [r2, #1]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08067788
    subs r0, #1
    strb r0, [r2, #1]
    b lbl_080677d6
lbl_08067788:
    ldrb r0, [r2, #3]
    strb r0, [r2, #1]
    ldrb r0, [r2, #2]
    adds r0, #1
    strb r0, [r2, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #4
    bls lbl_0806779c
    strb r1, [r2, #2]
lbl_0806779c:
    ldrb r1, [r2, #2]
    lsls r1, r1, #5
    ldr r0, lbl_080677b4 @ =0x082ed988
    adds r1, r1, r0
    ldr r2, lbl_080677b8 @ =0x05000380
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_080677d6
    .align 2, 0
lbl_080677b4: .4byte 0x082ed988
lbl_080677b8: .4byte 0x05000380
lbl_080677bc:
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_080677d6
    movs r0, #0
    strb r0, [r2]
    ldr r1, lbl_080677dc @ =0x082edb08
    ldr r2, lbl_080677e0 @ =0x05000380
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_080677d6:
    add sp, #4
    pop {r0}
    bx r0
    .align 2, 0
lbl_080677dc: .4byte 0x082edb08
lbl_080677e0: .4byte 0x05000380

    thumb_func_start sub_080677e4
sub_080677e4: @ 0x080677e4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldrb r1, [r4, #0xd]
    movs r5, #1
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080678a0
    ldrh r0, [r4, #0x16]
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_08067800
    subs r0, #1
    b lbl_0806784c
lbl_08067800:
    ldrh r1, [r4, #0xe]
    movs r3, #0xe
    ldrsh r0, [r4, r3]
    cmp r0, #0
    beq lbl_08067820
    ldrh r0, [r4, #2]
    subs r0, r0, r1
    strh r0, [r4, #2]
    strh r2, [r4, #0xe]
    ldr r2, lbl_08067818 @ =0x0808c99c
    ldr r3, lbl_0806781c @ =gFrameCounter8Bit
    b lbl_08067842
    .align 2, 0
lbl_08067818: .4byte 0x0808c99c
lbl_0806781c: .4byte gFrameCounter8Bit
lbl_08067820:
    ldr r2, lbl_0806785c @ =0x0808c99c
    ldr r3, lbl_08067860 @ =gFrameCounter8Bit
    ldrb r0, [r3]
    adds r0, r0, r2
    ldrb r1, [r0]
    adds r0, r5, #0
    ands r0, r1
    movs r1, #4
    cmp r0, #0
    beq lbl_0806783a
    movs r5, #4
    rsbs r5, r5, #0
    adds r1, r5, #0
lbl_0806783a:
    strh r1, [r4, #0xe]
    ldrh r5, [r4, #2]
    adds r0, r1, r5
    strh r0, [r4, #2]
lbl_08067842:
    ldrb r0, [r3]
    subs r0, #1
    adds r0, r0, r2
    ldrb r0, [r0]
    adds r0, #8
lbl_0806784c:
    strh r0, [r4, #0x16]
    ldrh r0, [r4, #0x18]
    adds r2, r0, #0
    cmp r2, #0
    beq lbl_08067864
    subs r0, #1
    b lbl_0806789e
    .align 2, 0
lbl_0806785c: .4byte 0x0808c99c
lbl_08067860: .4byte gFrameCounter8Bit
lbl_08067864:
    ldrh r1, [r4, #0x10]
    movs r3, #0x10
    ldrsh r0, [r4, r3]
    cmp r0, #0
    beq lbl_08067878
    ldrh r0, [r4]
    subs r0, r0, r1
    strh r0, [r4]
    strh r2, [r4, #0x10]
    b lbl_08067882
lbl_08067878:
    ldr r1, lbl_08067928 @ =0x0000fffc
    strh r1, [r4, #0x10]
    ldrh r0, [r4]
    adds r0, r0, r1
    strh r0, [r4]
lbl_08067882:
    ldr r1, lbl_0806792c @ =0x0808c99c
    ldr r0, lbl_08067930 @ =gFrameCounter8Bit
    ldrb r0, [r0]
    adds r0, r0, r1
    ldrb r0, [r0]
    movs r1, #0x7f
    ands r1, r0
    adds r0, r1, #0
    adds r0, #8
    strh r0, [r4, #0x18]
    ldrh r5, [r4, #0x16]
    cmp r0, r5
    bne lbl_080678a0
    adds r0, #0x10
lbl_0806789e:
    strh r0, [r4, #0x18]
lbl_080678a0:
    ldrb r1, [r4, #0xd]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080678ea
    ldrh r0, [r4, #0x1a]
    adds r0, #1
    strh r0, [r4, #0x1a]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #4
    bls lbl_080678ea
    movs r0, #0
    strh r0, [r4, #0x1a]
    ldrh r3, [r4, #0x12]
    adds r3, #1
    strh r3, [r4, #0x12]
    ldr r0, lbl_08067934 @ =0x08754bb4
    ldr r1, [r0]
    movs r2, #0xa0
    lsls r2, r2, #2
    adds r0, r1, r2
    ldr r5, lbl_08067938 @ =0x00003aa0
    adds r1, r1, r5
    ldr r2, lbl_0806793c @ =0x05000280
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    bl sub_0805b764
    movs r1, #0x12
    ldrsh r0, [r4, r1]
    cmp r0, #0x1e
    ble lbl_080678ea
    ldrb r0, [r4, #0xd]
    movs r1, #2
    eors r0, r1
    strb r0, [r4, #0xd]
lbl_080678ea:
    ldrb r1, [r4, #0xd]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #0xd]
    ldr r0, lbl_08067940 @ =0x083f0390
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    ldrh r1, [r0]
    movs r2, #2
    ldrsh r0, [r4, r2]
    subs r2, r1, r0
    ldr r3, lbl_08067944 @ =0x000005df
    adds r1, r2, r3
    ldr r0, lbl_08067948 @ =0x000006de
    movs r2, #1
    cmp r1, r0
    bhi lbl_08067910
    movs r2, #0
lbl_08067910:
    movs r0, #1
    ands r2, r0
    lsls r2, r2, #5
    ldrb r1, [r4, #0xb]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #0xb]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08067928: .4byte 0x0000fffc
lbl_0806792c: .4byte 0x0808c99c
lbl_08067930: .4byte gFrameCounter8Bit
lbl_08067934: .4byte 0x08754bb4
lbl_08067938: .4byte 0x00003aa0
lbl_0806793c: .4byte 0x05000280
lbl_08067940: .4byte 0x083f0390
lbl_08067944: .4byte 0x000005df
lbl_08067948: .4byte 0x000006de

    thumb_func_start enter_tourian_init
enter_tourian_init: @ 0x0806794c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    bl unk_61f0c
    ldr r1, lbl_08067c94 @ =0x083f0410
    movs r5, #0xa0
    lsls r5, r5, #0x13
    movs r3, #0xa0
    lsls r3, r3, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r2, r5, #0
    bl DMATransfer
    movs r0, #0
    strh r0, [r5]
    ldr r1, lbl_08067c98 @ =0x083f0550
    ldr r2, lbl_08067c9c @ =0x05000200
    str r4, [sp]
    movs r0, #3
    movs r3, #0xc0
    bl DMATransfer
    ldr r1, lbl_08067ca0 @ =0x082ed8e8
    ldr r2, lbl_08067ca4 @ =0x05000300
    str r4, [sp]
    movs r0, #3
    movs r3, #0xa0
    bl DMATransfer
    ldr r0, lbl_08067ca8 @ =0x083f5d74
    ldr r1, lbl_08067cac @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cb0 @ =0x083f5e50
    ldr r1, lbl_08067cb4 @ =0x06010400
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cb8 @ =0x083f5f84
    ldr r1, lbl_08067cbc @ =0x06010800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cc0 @ =0x082ecc84
    ldr r1, lbl_08067cc4 @ =0x06014000
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cc8 @ =0x083f0610
    ldr r6, lbl_08067ccc @ =0x083f0390
    ldrb r1, [r6]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cd0 @ =0x083f36a8
    ldrb r1, [r6, #8]
    lsls r1, r1, #0xe
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cd4 @ =0x083f6004
    ldrb r1, [r6, #1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_08067cd8 @ =0x083f6608
    ldrb r1, [r6, #9]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, [r6]
    ldr r1, [r6, #4]
    bl CutsceneSetBGCNTPageData
    ldr r0, [r6, #8]
    ldr r1, [r6, #0xc]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    ldrh r0, [r6, #4]
    mov r8, r0
    movs r4, #0x80
    lsls r4, r4, #4
    movs r0, #2
    mov r1, r8
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    ldrh r5, [r6, #0xc]
    movs r0, #2
    adds r1, r5, #0
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    movs r2, #0x95
    lsls r2, r2, #4
    movs r0, #1
    mov r1, r8
    bl CutsceneSetBackgroundPosition
    movs r0, #1
    adds r1, r5, #0
    adds r2, r4, #0
    bl CutsceneSetBackgroundPosition
    ldr r2, lbl_08067cdc @ =0x08754bc4
    ldr r0, [r2]
    movs r3, #0x8d
    lsls r3, r3, #1
    adds r1, r0, r3
    movs r0, #6
    strb r0, [r1]
    ldr r1, [r2]
    ldr r4, lbl_08067ce0 @ =0x0000011b
    adds r1, r1, r4
    ldrb r3, [r1]
    movs r5, #0x3f
    mov r8, r5
    mov r0, r8
    ands r0, r3
    movs r7, #0x40
    orrs r0, r7
    strb r0, [r1]
    ldr r1, [r2]
    movs r0, #0x8e
    lsls r0, r0, #1
    mov ip, r0
    add r1, ip
    ldrb r3, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r3
    movs r3, #3
    mov sb, r3
    mov r5, sb
    orrs r0, r5
    strb r0, [r1]
    ldr r1, [r2]
    adds r1, r1, r4
    ldrb r6, [r6, #2]
    ands r6, r5
    ldrb r3, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r6
    strb r0, [r1]
    ldr r0, [r2]
    adds r7, #0xdd
    adds r0, r0, r7
    movs r1, #1
    mov sl, r1
    mov r3, sl
    strb r3, [r0]
    ldr r0, [r2]
    movs r3, #0x88
    lsls r3, r3, #1
    adds r4, #0x35
    adds r1, r0, r4
    adds r0, r0, r3
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r5, r7}
    stm r1!, {r5, r7}
    ldr r0, [r2]
    movs r4, #0xc8
    lsls r4, r4, #1
    adds r1, r0, r4
    adds r0, r0, r3
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r5, r7}
    stm r1!, {r5, r7}
    ldr r0, [r2]
    movs r4, #0xe8
    lsls r4, r4, #1
    adds r1, r0, r4
    adds r0, r0, r3
    ldm r0!, {r3, r5, r7}
    stm r1!, {r3, r5, r7}
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r3, r4}
    stm r1!, {r3, r4}
    ldr r1, [r2]
    add r1, ip
    ldrb r0, [r1]
    movs r3, #0x10
    orrs r0, r3
    strb r0, [r1]
    ldr r0, [r2]
    ldr r5, lbl_08067ce4 @ =0x00000159
    adds r0, r0, r5
    movs r1, #2
    strb r1, [r0]
    ldr r0, [r2]
    ldr r7, lbl_08067ce8 @ =0x00000199
    adds r7, r7, r0
    movs r0, #4
    strb r0, [r7]
    ldr r0, [r2]
    ldr r4, lbl_08067cec @ =0x000001d9
    adds r4, r4, r0
    movs r0, #8
    strb r0, [r4]
    ldr r0, [r2]
    adds r0, #0xfa
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xfb
    ldrb r1, [r0]
    mov r5, r8
    ands r5, r1
    movs r7, #0x40
    orrs r5, r7
    strb r5, [r0]
    ldr r0, [r2]
    adds r0, #0xfc
    ldrb r1, [r0]
    movs r5, #0x10
    rsbs r5, r5, #0
    ands r5, r1
    mov r1, sb
    orrs r5, r1
    strb r5, [r0]
    ldr r0, [r2]
    adds r0, #0xfb
    ldrb r1, [r0]
    movs r4, #4
    rsbs r4, r4, #0
    ands r4, r1
    orrs r4, r6
    strb r4, [r0]
    ldr r0, [r2]
    movs r4, #0x98
    lsls r4, r4, #1
    adds r1, r0, r4
    adds r0, #0xf0
    ldm r0!, {r5, r6, r7}
    stm r1!, {r5, r6, r7}
    ldm r0!, {r4, r5, r6}
    stm r1!, {r4, r5, r6}
    ldm r0!, {r4, r7}
    stm r1!, {r4, r7}
    ldr r0, [r2]
    movs r5, #0xb8
    lsls r5, r5, #1
    adds r1, r0, r5
    adds r0, #0xf0
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r5, r6, r7}
    stm r1!, {r5, r6, r7}
    ldm r0!, {r4, r5}
    stm r1!, {r4, r5}
    ldr r0, [r2]
    movs r6, #0xd8
    lsls r6, r6, #1
    adds r1, r0, r6
    adds r0, #0xf0
    ldm r0!, {r4, r5, r7}
    stm r1!, {r4, r5, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r5, r6}
    stm r1!, {r5, r6}
    ldr r1, [r2]
    adds r1, #0xfc
    ldrb r0, [r1]
    orrs r0, r3
    strb r0, [r1]
    ldr r0, [r2]
    ldr r7, lbl_08067cf0 @ =0x00000139
    adds r0, r0, r7
    mov r1, sl
    strb r1, [r0]
    ldr r0, [r2]
    ldr r3, lbl_08067cf4 @ =0x00000179
    adds r0, r0, r3
    strb r1, [r0]
    movs r4, #0
    adds r6, r2, #0
    ldr r5, lbl_08067cf8 @ =0x08760090
    adds r7, r5, #2
    mov r8, r7
    adds r7, r6, #0
lbl_08067ba2:
    ldr r2, [r6]
    lsls r0, r4, #5
    adds r2, r2, r0
    asrs r1, r4, #1
    lsls r1, r1, #2
    adds r0, r1, r5
    ldrh r0, [r0]
    adds r3, r2, #0
    adds r3, #0xf2
    strh r0, [r3]
    add r1, r8
    ldrh r0, [r1]
    adds r2, #0xf0
    strh r0, [r2]
    adds r4, #1
    cmp r4, #7
    ble lbl_08067ba2
    ldr r0, [r7]
    movs r4, #0xf8
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #1
    bl UpdateCutsceneOamDataID
    ldr r1, [r7]
    movs r0, #0xfe
    lsls r0, r0, #1
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r2
    movs r2, #3
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r7]
    ldr r5, lbl_08067ccc @ =0x083f0390
    ldr r1, lbl_08067cfc @ =0x000001fb
    adds r3, r0, r1
    ldrb r1, [r5, #2]
    ands r1, r2
    ldrb r2, [r3]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldr r0, [r7]
    ldr r3, lbl_08067d00 @ =0x000001fd
    adds r0, r0, r3
    movs r6, #0
    mov r8, r6
    movs r3, #1
    strb r3, [r0]
    ldr r2, [r7]
    ldr r1, lbl_08067cf8 @ =0x08760090
    ldrh r0, [r1, #0x10]
    movs r6, #0xf9
    lsls r6, r6, #1
    adds r6, r6, r2
    mov sb, r6
    movs r6, #0
    mov sl, r6
    mov r6, sb
    strh r0, [r6]
    ldrh r0, [r1, #0x12]
    adds r4, r2, r4
    strh r0, [r4]
    movs r0, #0xd0
    strh r0, [r2, #0x1e]
    ldr r1, lbl_08067d04 @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    strb r3, [r2, #0xa]
    movs r0, #0x44
    movs r1, #0
    bl PlayMusic
    ldr r1, lbl_08067c9c @ =0x05000200
    ldr r0, lbl_08067d08 @ =0x08754bb4
    ldr r2, [r0]
    movs r0, #0xe8
    lsls r0, r0, #6
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #3
    bl unk_61fa0
    ldr r2, [r7]
    ldrh r0, [r5, #4]
    movs r3, #0x80
    lsls r3, r3, #5
    adds r1, r3, #0
    orrs r0, r1
    ldrh r1, [r5, #0xc]
    orrs r0, r1
    strh r0, [r2, #0x1c]
    mov r4, r8
    strh r4, [r2, #2]
    mov r5, sl
    strb r5, [r2, #4]
    ldr r1, [r7]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
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
lbl_08067c94: .4byte 0x083f0410
lbl_08067c98: .4byte 0x083f0550
lbl_08067c9c: .4byte 0x05000200
lbl_08067ca0: .4byte 0x082ed8e8
lbl_08067ca4: .4byte 0x05000300
lbl_08067ca8: .4byte 0x083f5d74
lbl_08067cac: .4byte 0x06010000
lbl_08067cb0: .4byte 0x083f5e50
lbl_08067cb4: .4byte 0x06010400
lbl_08067cb8: .4byte 0x083f5f84
lbl_08067cbc: .4byte 0x06010800
lbl_08067cc0: .4byte 0x082ecc84
lbl_08067cc4: .4byte 0x06014000
lbl_08067cc8: .4byte 0x083f0610
lbl_08067ccc: .4byte 0x083f0390
lbl_08067cd0: .4byte 0x083f36a8
lbl_08067cd4: .4byte 0x083f6004
lbl_08067cd8: .4byte 0x083f6608
lbl_08067cdc: .4byte 0x08754bc4
lbl_08067ce0: .4byte 0x0000011b
lbl_08067ce4: .4byte 0x00000159
lbl_08067ce8: .4byte 0x00000199
lbl_08067cec: .4byte 0x000001d9
lbl_08067cf0: .4byte 0x00000139
lbl_08067cf4: .4byte 0x00000179
lbl_08067cf8: .4byte 0x08760090
lbl_08067cfc: .4byte 0x000001fb
lbl_08067d00: .4byte 0x000001fd
lbl_08067d04: .4byte gWrittenToBLDY_NonGameplay
lbl_08067d08: .4byte 0x08754bb4

    thumb_func_start enter_tourian_subroutine
enter_tourian_subroutine: @ 0x08067d0c
    push {r4, lr}
    ldr r1, lbl_08067d38 @ =0x087600c4
    ldr r0, lbl_08067d3c @ =0x08754bc4
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
    bl sub_08067d40
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08067d38: .4byte 0x087600c4
lbl_08067d3c: .4byte 0x08754bc4

    thumb_func_start sub_08067d40
sub_08067d40: @ 0x08067d40
    push {lr}
    ldr r1, lbl_08067d74 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_08067d78 @ =0x087600c4
    ldr r0, lbl_08067d7c @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    adds r1, #0xf0
    ldr r2, lbl_08067d80 @ =0x083f03b0
    bl process_cutscene_oam
    bl ResetFreeOAM
    ldr r0, lbl_08067d84 @ =gCurrentOamRotation
    ldrh r0, [r0]
    ldr r1, lbl_08067d88 @ =gCurrentOamScaling
    ldrh r1, [r1]
    movs r2, #0
    bl CalculateOamPart4
    pop {r0}
    bx r0
    .align 2, 0
lbl_08067d74: .4byte gNextOamSlot
lbl_08067d78: .4byte 0x087600c4
lbl_08067d7c: .4byte 0x08754bc4
lbl_08067d80: .4byte 0x083f03b0
lbl_08067d84: .4byte gCurrentOamRotation
lbl_08067d88: .4byte gCurrentOamScaling

    thumb_func_start samus_in_blue_ship_powering_up
samus_in_blue_ship_powering_up: @ 0x08067d8c
    push {r4, lr}
    ldr r0, lbl_08067da4 @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #4]
    cmp r0, #5
    bhi lbl_08067e66
    lsls r0, r0, #2
    ldr r1, lbl_08067da8 @ =lbl_08067dac
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08067da4: .4byte 0x08754bc4
lbl_08067da8: .4byte lbl_08067dac
lbl_08067dac: @ jump table
    .4byte lbl_08067dc4 @ case 0
    .4byte lbl_08067dd8 @ case 1
    .4byte lbl_08067df4 @ case 2
    .4byte lbl_08067e08 @ case 3
    .4byte lbl_08067e34 @ case 4
    .4byte lbl_08067e50 @ case 5
lbl_08067dc4:
    bl unk_61f44
    cmp r0, #0
    beq lbl_08067e66
    ldr r0, lbl_08067dd4 @ =0x08754bc4
    ldr r1, [r0]
    b lbl_08067e3e
    .align 2, 0
lbl_08067dd4: .4byte 0x08754bc4
lbl_08067dd8:
    ldr r3, lbl_08067df0 @ =0x08754bc4
    ldr r1, [r3]
    ldrh r0, [r1, #2]
    cmp r0, #0x1e
    bls lbl_08067e66
    adds r1, #0xfd
    movs r2, #0
    movs r0, #1
    strb r0, [r1]
    ldr r1, [r3]
    strh r2, [r1, #2]
    b lbl_08067e42
    .align 2, 0
lbl_08067df0: .4byte 0x08754bc4
lbl_08067df4:
    ldr r0, lbl_08067e04 @ =0x08754bc4
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xfd
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_08067e66
    b lbl_08067e3e
    .align 2, 0
lbl_08067e04: .4byte 0x08754bc4
lbl_08067e08:
    ldr r4, lbl_08067e30 @ =0x08754bc4
    ldr r0, [r4]
    ldrh r0, [r0, #2]
    cmp r0, #0x1e
    bls lbl_08067e66
    movs r0, #0x95
    lsls r0, r0, #2
    bl SoundPlay
    ldr r0, [r4]
    adds r0, #0xc0
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0xc4
    strh r2, [r0]
    strh r2, [r1, #2]
    b lbl_08067e42
    .align 2, 0
lbl_08067e30: .4byte 0x08754bc4
lbl_08067e34:
    ldr r0, lbl_08067e4c @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #2]
    cmp r0, #0x5a
    bls lbl_08067e66
lbl_08067e3e:
    movs r0, #0
    strh r0, [r1, #2]
lbl_08067e42:
    ldrb r0, [r1, #4]
    adds r0, #1
    strb r0, [r1, #4]
    b lbl_08067e66
    .align 2, 0
lbl_08067e4c: .4byte 0x08754bc4
lbl_08067e50:
    bl unk_61f0c
    ldr r3, lbl_08067e80 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
    strb r2, [r0, #4]
    strh r2, [r0, #2]
lbl_08067e66:
    ldr r4, lbl_08067e80 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xc0
    bl sub_08067e84
    ldr r0, [r4]
    adds r0, #0xf0
    bl sub_08067ed0
    movs r0, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08067e80: .4byte 0x08754bc4

    thumb_func_start sub_08067e84
sub_08067e84: @ 0x08067e84
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08067ec6
    ldrh r0, [r2, #4]
    adds r1, r0, #1
    strh r1, [r2, #4]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08067ec6
    movs r0, #2
    ands r1, r0
    cmp r1, #0
    beq lbl_08067eb8
    ldr r0, lbl_08067eb4 @ =0x083f6c0c
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    ldrh r1, [r0]
    adds r1, #4
    b lbl_08067ec4
    .align 2, 0
lbl_08067eb4: .4byte 0x083f6c0c
lbl_08067eb8:
    ldr r0, lbl_08067ecc @ =0x083f6c0c
    ldrh r0, [r0, #4]
    bl CutsceneGetBGHOFSPointer
    ldrh r1, [r0]
    subs r1, #4
lbl_08067ec4:
    strh r1, [r0]
lbl_08067ec6:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08067ecc: .4byte 0x083f6c0c

    thumb_func_start sub_08067ed0
sub_08067ed0: @ 0x08067ed0
    push {r4, lr}
    adds r4, r0, #0
    ldrb r0, [r4, #0xd]
    cmp r0, #4
    bhi lbl_08067f88
    lsls r0, r0, #2
    ldr r1, lbl_08067ee4 @ =lbl_08067ee8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08067ee4: .4byte lbl_08067ee8
lbl_08067ee8: @ jump table
    .4byte lbl_08067f88 @ case 0
    .4byte lbl_08067efc @ case 1
    .4byte lbl_08067f24 @ case 2
    .4byte lbl_08067f34 @ case 3
    .4byte lbl_08067f46 @ case 4
lbl_08067efc:
    adds r0, r4, #0
    movs r1, #2
    bl UpdateCutsceneOamDataID
    ldr r0, lbl_08067f18 @ =0x00000253
    bl SoundPlay
    ldr r1, lbl_08067f1c @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    ldr r1, lbl_08067f20 @ =gWrittenToBLDALPHA_H
    movs r0, #0
    strh r0, [r1]
    b lbl_08067f3e
    .align 2, 0
lbl_08067f18: .4byte 0x00000253
lbl_08067f1c: .4byte gWrittenToBLDALPHA_L
lbl_08067f20: .4byte gWrittenToBLDALPHA_H
lbl_08067f24:
    ldrb r1, [r4, #0xb]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08067f88
    movs r0, #0
    strh r0, [r4, #0x14]
    b lbl_08067f3e
lbl_08067f34:
    movs r1, #0
    strh r1, [r4, #0x1a]
    movs r0, #2
    strb r0, [r4, #0x1e]
    strh r1, [r4, #0x14]
lbl_08067f3e:
    ldrb r0, [r4, #0xd]
    adds r0, #1
    strb r0, [r4, #0xd]
    b lbl_08067f88
lbl_08067f46:
    ldrh r0, [r4, #0x1a]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08067f84
    ldrb r0, [r4, #0x1e]
    strh r0, [r4, #0x1a]
    ldrh r0, [r4, #0x14]
    adds r0, #1
    strh r0, [r4, #0x14]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08067f62
    strh r1, [r4, #0x14]
lbl_08067f62:
    ldr r2, lbl_08067f78 @ =gWrittenToBLDALPHA_L
    ldr r1, lbl_08067f7c @ =0x087600dc
    ldrh r0, [r4, #0x14]
    adds r0, r0, r1
    ldrb r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_08067f80 @ =gWrittenToBLDALPHA_H
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    b lbl_08067f88
    .align 2, 0
lbl_08067f78: .4byte gWrittenToBLDALPHA_L
lbl_08067f7c: .4byte 0x087600dc
lbl_08067f80: .4byte gWrittenToBLDALPHA_H
lbl_08067f84:
    subs r0, #1
    strh r0, [r4, #0x1a]
lbl_08067f88:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start samus_in_blue_ship_init
samus_in_blue_ship_init: @ 0x08067f90
    push {r4, r5, r6, lr}
    mov r6, sb
    mov r5, r8
    push {r5, r6}
    sub sp, #4
    bl unk_61f0c
    ldr r5, lbl_08068090 @ =0x083f7584
    ldr r2, lbl_08068094 @ =0x05000200
    movs r6, #0x90
    lsls r6, r6, #1
    movs r0, #0x10
    mov r8, r0
    str r0, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    movs r4, #0xa0
    lsls r4, r4, #0x13
    mov r1, r8
    str r1, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r2, r4, #0
    adds r3, r6, #0
    bl DMATransfer
    movs r2, #0
    mov sb, r2
    strh r2, [r4]
    ldr r0, lbl_08068098 @ =0x083f76a4
    ldr r5, lbl_0806809c @ =0x083f6c0c
    ldrb r1, [r5]
    lsls r1, r1, #0xe
    movs r4, #0xc0
    lsls r4, r4, #0x13
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_080680a0 @ =0x083fc930
    ldrb r1, [r5, #1]
    lsls r1, r1, #0xb
    adds r1, r1, r4
    bl CallLZ77UncompVRAM
    ldr r0, lbl_080680a4 @ =0x083faf88
    ldr r1, lbl_080680a8 @ =0x06010000
    bl CallLZ77UncompVRAM
    ldr r0, [r5]
    ldr r1, [r5, #4]
    bl CutsceneSetBGCNTPageData
    bl CutsceneReset
    ldr r4, lbl_080680ac @ =0x08754bc4
    ldr r1, [r4]
    movs r6, #0
    ldr r0, lbl_080680b0 @ =0x00003f50
    strh r0, [r1, #0x1e]
    ldr r0, lbl_080680b4 @ =gWrittenToBLDALPHA_L
    mov r1, r8
    strh r1, [r0]
    ldr r0, lbl_080680b8 @ =gWrittenToBLDALPHA_H
    strh r6, [r0]
    ldrh r5, [r5, #4]
    movs r2, #0x80
    lsls r2, r2, #4
    movs r0, #3
    adds r1, r5, #0
    bl CutsceneSetBackgroundPosition
    ldr r0, [r4]
    adds r0, #0xf0
    movs r1, #1
    bl UpdateCutsceneOamDataID
    ldr r2, [r4]
    adds r1, r2, #0
    adds r1, #0xf2
    movs r0, #0x9e
    lsls r0, r0, #4
    strh r0, [r1]
    subs r1, #2
    subs r0, #0xa4
    strh r0, [r1]
    adds r2, #0xfb
    ldrb r1, [r2]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r4]
    adds r2, #0xfc
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #3
    orrs r0, r1
    strb r0, [r2]
    movs r0, #2
    bl unk_61fa0
    ldr r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #5
    adds r0, r2, #0
    orrs r5, r0
    strh r5, [r1, #0x1c]
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r4]
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
lbl_08068090: .4byte 0x083f7584
lbl_08068094: .4byte 0x05000200
lbl_08068098: .4byte 0x083f76a4
lbl_0806809c: .4byte 0x083f6c0c
lbl_080680a0: .4byte 0x083fc930
lbl_080680a4: .4byte 0x083faf88
lbl_080680a8: .4byte 0x06010000
lbl_080680ac: .4byte 0x08754bc4
lbl_080680b0: .4byte 0x00003f50
lbl_080680b4: .4byte gWrittenToBLDALPHA_L
lbl_080680b8: .4byte gWrittenToBLDALPHA_H

    thumb_func_start samus_in_blue_ship_subroutine
samus_in_blue_ship_subroutine: @ 0x080680bc
    push {r4, lr}
    ldr r1, lbl_080680e8 @ =0x087600e0
    ldr r0, lbl_080680ec @ =0x08754bc4
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
    bl sub_080680f0
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080680e8: .4byte 0x087600e0
lbl_080680ec: .4byte 0x08754bc4

    thumb_func_start sub_080680f0
sub_080680f0: @ 0x080680f0
    push {lr}
    ldr r1, lbl_08068118 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r2, lbl_0806811c @ =0x087600e0
    ldr r0, lbl_08068120 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1]
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #4]
    adds r1, #0xf0
    ldr r2, lbl_08068124 @ =0x083f6c18
    bl process_cutscene_oam
    bl ResetFreeOAM
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068118: .4byte gNextOamSlot
lbl_0806811c: .4byte 0x087600e0
lbl_08068120: .4byte 0x08754bc4
lbl_08068124: .4byte 0x083f6c18

    thumb_func_start UpdateMenuOamDataID
UpdateMenuOamDataID: @ 0x08068128
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    strb r1, [r0, #0xa]
    rsbs r2, r1, #0
    orrs r2, r1
    asrs r2, r2, #0x1f
    movs r3, #2
    ands r3, r2
    lsls r3, r3, #6
    ldrb r2, [r0, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r3
    strb r1, [r0, #0xb]
    bx lr
    .align 2, 0

    thumb_func_start UpdateCutsceneOamDataID
UpdateCutsceneOamDataID: @ 0x08068148
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    strb r1, [r0, #0xa]
    rsbs r2, r1, #0
    orrs r2, r1
    asrs r2, r2, #0x1f
    movs r3, #2
    ands r3, r2
    lsls r3, r3, #6
    ldrb r2, [r0, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r3
    strb r1, [r0, #0xb]
    bx lr
    .align 2, 0

    thumb_func_start sub_08068168
sub_08068168: @ 0x08068168
    push {r4, r5, r6, r7, lr}
    lsls r7, r0, #0x10
    lsrs r4, r7, #0x10
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    ldr r5, lbl_080681bc @ =0x08754bc4
    ldr r0, [r5]
    adds r3, r0, #0
    adds r3, #0x7c
    ldrb r0, [r3]
    adds r6, r0, #0
    cmp r6, #0
    bne lbl_080681c0
    cmp r1, #0
    beq lbl_080681c0
    adds r0, #1
    strb r0, [r3]
    ldr r0, [r5]
    adds r0, #0x7d
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x7f
    strb r2, [r0]
    ldr r0, [r5]
    movs r1, #0x1f
    ands r4, r1
    adds r0, #0x80
    strb r4, [r0]
    ldr r2, [r5]
    lsrs r0, r7, #0x18
    movs r1, #0x1f
    ands r0, r1
    adds r2, #0x81
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0x7e
    strb r6, [r0]
    movs r0, #1
    b lbl_080681c2
    .align 2, 0
lbl_080681bc: .4byte 0x08754bc4
lbl_080681c0:
    movs r0, #0
lbl_080681c2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_080681c8
sub_080681c8: @ 0x080681c8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r0, #0
    mov sb, r0
    ldr r0, lbl_0806823c @ =0x08754bc4
    ldr r2, [r0]
    adds r1, r2, #0
    adds r1, #0x7c
    ldrb r1, [r1]
    mov r8, r0
    cmp r1, #0
    beq lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x7e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0x7f
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, #0x7e
    ldrb r2, [r0]
    cmp r1, r2
    bgt lbl_080682dc
    mov r3, sb
    strb r3, [r0]
    ldr r0, lbl_08068240 @ =gWrittenToBLDALPHA_L
    mov r1, r8
    ldr r2, [r1]
    adds r6, r2, #0
    adds r6, #0x80
    ldrb r3, [r6]
    ldrh r5, [r0]
    adds r4, r5, #0
    adds r1, r3, #0
    mov ip, r0
    cmp r4, r1
    beq lbl_08068264
    cmp r4, r1
    bls lbl_0806824a
    ldrh r4, [r0]
    subs r1, r4, r3
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    cmp r1, r0
    ble lbl_08068244
    subs r0, r4, r0
    mov r2, ip
    strh r0, [r2]
    b lbl_08068264
    .align 2, 0
lbl_0806823c: .4byte 0x08754bc4
lbl_08068240: .4byte gWrittenToBLDALPHA_L
lbl_08068244:
    mov r0, ip
    strh r3, [r0]
    b lbl_08068264
lbl_0806824a:
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    adds r0, r5, r0
    mov r1, ip
    strh r0, [r1]
    ldrb r1, [r6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_08068264
    mov r2, ip
    strh r1, [r2]
lbl_08068264:
    ldr r0, lbl_08068294 @ =gWrittenToBLDALPHA_H
    mov r3, r8
    ldr r2, [r3]
    adds r6, r2, #0
    adds r6, #0x81
    ldrb r3, [r6]
    ldrh r5, [r0]
    adds r4, r5, #0
    adds r1, r3, #0
    adds r7, r0, #0
    cmp r4, r1
    beq lbl_080682b2
    cmp r4, r1
    bls lbl_0806829c
    ldrh r4, [r7]
    subs r1, r4, r3
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    cmp r1, r0
    ble lbl_08068298
    subs r0, r4, r0
    strh r0, [r7]
    b lbl_080682b2
    .align 2, 0
lbl_08068294: .4byte gWrittenToBLDALPHA_H
lbl_08068298:
    strh r3, [r7]
    b lbl_080682b2
lbl_0806829c:
    adds r0, r2, #0
    adds r0, #0x7d
    ldrb r0, [r0]
    adds r0, r5, r0
    strh r0, [r7]
    ldrb r1, [r6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r1
    bls lbl_080682b2
    strh r1, [r7]
lbl_080682b2:
    mov r0, r8
    ldr r2, [r0]
    adds r1, r2, #0
    adds r1, #0x80
    mov r3, ip
    ldrh r0, [r3]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x81
    ldrh r0, [r7]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080682dc
    adds r1, r2, #0
    adds r1, #0x7c
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    mov sb, r0
lbl_080682dc:
    mov r0, sb
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080682ec
sub_080682ec: @ 0x080682ec
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r7, lbl_0806831c @ =0x08754bc4
    cmp r1, #0
    beq lbl_08068304
    ldr r0, [r7]
    adds r0, #0xbc
    strb r1, [r0]
lbl_08068304:
    ldr r0, [r7]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #5
    bls lbl_08068310
    b lbl_08068570
lbl_08068310:
    lsls r0, r0, #2
    ldr r1, lbl_08068320 @ =lbl_08068324
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806831c: .4byte 0x08754bc4
lbl_08068320: .4byte lbl_08068324
lbl_08068324: @ jump table
    .4byte lbl_08068570 @ case 0
    .4byte lbl_0806833c @ case 1
    .4byte lbl_08068358 @ case 2
    .4byte lbl_080683c0 @ case 3
    .4byte lbl_08068474 @ case 4
    .4byte lbl_080684b0 @ case 5
lbl_0806833c:
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0xbe
    ldrb r1, [r1]
    cmp r1, #0
    beq lbl_0806834a
    b lbl_0806857c
lbl_0806834a:
    adds r0, #0xbd
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xbc
    strb r1, [r0]
    movs r0, #1
    b lbl_080685a4
lbl_08068358:
    movs r6, #0xa0
    lsls r6, r6, #0x13
    ldr r0, lbl_080683b8 @ =0x08754bb4
    mov r8, r0
    ldr r2, [r0]
    movs r1, #0xd0
    lsls r1, r1, #7
    adds r2, r2, r1
    movs r5, #0x80
    lsls r5, r5, #3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl BitFill
    mov r3, r8
    ldr r2, [r3]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_080683bc @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xbd
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbc
    movs r1, #3
    b lbl_0806856e
    .align 2, 0
lbl_080683b8: .4byte 0x08754bb4
lbl_080683bc: .4byte 0x08754bc4
lbl_080683c0:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080683ce
    b lbl_0806857c
lbl_080683ce:
    adds r0, r1, #0
    adds r0, #0xbd
    ldrb r0, [r0]
    cmp r0, #0x1f
    bhi lbl_08068450
    ldr r5, lbl_08068448 @ =0x08754bb4
    ldr r0, [r5]
    movs r2, #0xd0
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r0, [r7]
    adds r0, #0xbd
    ldrb r1, [r0]
    add r6, sp, #8
    ldr r4, lbl_0806844c @ =0x0000ffff
    str r4, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r5]
    movs r2, #0xd4
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xdc
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    ldr r0, [r7]
    adds r0, #0xbd
    ldrb r1, [r0]
    str r4, [sp]
    movs r0, #0
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r7]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0xbd
    ldrb r0, [r1]
    cmp r0, #0x1f
    beq lbl_0806852c
    ldrb r0, [r1]
    adds r0, #2
    cmp r0, #0x1f
    ble lbl_08068444
    b lbl_08068544
lbl_08068444:
    b lbl_0806852e
    .align 2, 0
lbl_08068448: .4byte 0x08754bb4
lbl_0806844c: .4byte 0x0000ffff
lbl_08068450:
    ldr r0, lbl_08068470 @ =0x08754bb4
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r1, r2, r0
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_08068562
    .align 2, 0
lbl_08068470: .4byte 0x08754bb4
lbl_08068474:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_080684a8 @ =0x08754bb4
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_080684ac @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xbd
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbe
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0xbc
    movs r1, #5
    b lbl_0806856e
    .align 2, 0
lbl_080684a8: .4byte 0x08754bb4
lbl_080684ac: .4byte 0x08754bc4
lbl_080684b0:
    mov r8, r7
    mov r2, r8
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806857c
    adds r2, r1, #0
    adds r2, #0xbd
    ldrb r0, [r2]
    cmp r0, #0x1f
    bhi lbl_08068548
    ldr r4, lbl_08068534 @ =0x08754bb4
    ldr r0, [r4]
    movs r3, #0xd0
    lsls r3, r3, #7
    adds r1, r0, r3
    str r1, [sp, #4]
    movs r1, #0xd8
    lsls r1, r1, #7
    adds r0, r0, r1
    str r0, [sp, #8]
    ldrb r1, [r2]
    add r6, sp, #8
    ldr r5, lbl_08068538 @ =0x0000ffff
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    ldr r0, [r4]
    movs r2, #0xd4
    lsls r2, r2, #7
    adds r1, r0, r2
    str r1, [sp, #4]
    movs r3, #0xdc
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [sp, #8]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0xbd
    ldrb r1, [r0]
    str r5, [sp]
    movs r0, #2
    add r2, sp, #4
    adds r3, r6, #0
    bl ApplySpecialBackgroundFadingColor
    mov r2, r8
    ldr r0, [r2]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xbd
    ldrb r0, [r1]
    cmp r0, #0x1f
    bne lbl_0806853c
lbl_0806852c:
    adds r0, #1
lbl_0806852e:
    strb r0, [r1]
    b lbl_08068570
    .align 2, 0
lbl_08068534: .4byte 0x08754bb4
lbl_08068538: .4byte 0x0000ffff
lbl_0806853c:
    ldrb r0, [r1]
    adds r0, #2
    cmp r0, #0x1f
    ble lbl_0806852e
lbl_08068544:
    movs r0, #0x1f
    b lbl_0806852e
lbl_08068548:
    ldr r0, lbl_080685b0 @ =0x08754bb4
    ldr r2, [r0]
    movs r3, #0xd8
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
lbl_08068562:
    ldr r0, [r7]
    adds r0, #0xbe
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xbc
lbl_0806856e:
    strb r1, [r0]
lbl_08068570:
    ldr r0, lbl_080685b4 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080685a2
lbl_0806857c:
    ldr r0, lbl_080685b0 @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r1, r1, r0
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_080685b4 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbe
    movs r1, #0
    strb r1, [r0]
lbl_080685a2:
    movs r0, #0
lbl_080685a4:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080685b0: .4byte 0x08754bb4
lbl_080685b4: .4byte 0x08754bc4

    thumb_func_start sub_080685b8
sub_080685b8: @ 0x080685b8
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    sub sp, #4
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08068614
    movs r6, #0xa0
    lsls r6, r6, #0x13
    ldr r0, lbl_08068610 @ =0x08754bb4
    mov r8, r0
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r5, #0x80
    lsls r5, r5, #3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r6, #0
    adds r3, r5, #0
    bl BitFill
    mov r0, r8
    ldr r2, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    b lbl_08068630
    .align 2, 0
lbl_08068610: .4byte 0x08754bb4
lbl_08068614:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r0, lbl_08068648 @ =0x08754bb4
    ldr r2, [r0]
    movs r0, #0xd0
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_08068630:
    ldr r0, lbl_0806864c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbc
    movs r1, #0
    strb r1, [r0]
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068648: .4byte 0x08754bb4
lbl_0806864c: .4byte 0x08754bc4

    thumb_func_start sub_08068650
sub_08068650: @ 0x08068650
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0806868c @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xbe
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08068684
    ldr r0, lbl_08068690 @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0xd8
    lsls r0, r0, #7
    adds r1, r1, r0
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #3
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, [r4]
    adds r0, #0xbe
    movs r1, #0
    strb r1, [r0]
lbl_08068684:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806868c: .4byte 0x08754bc4
lbl_08068690: .4byte 0x08754bb4

    thumb_func_start sub_08068694
sub_08068694: @ 0x08068694
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_080687fc @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_080686a8
    b lbl_0806888e
lbl_080686a8:
    ldr r0, lbl_08068800 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r3, [r1, #4]
    movs r2, #1
    mov r8, r2
    adds r5, r0, #0
    cmp r3, #0
    beq lbl_080686cc
    movs r0, #0
    mov r8, r0
    cmp r3, #0xc
    bne lbl_080686c4
    movs r2, #2
    mov r8, r2
lbl_080686c4:
    mov r0, r8
    cmp r0, #0
    bne lbl_080686cc
    b lbl_0806880c
lbl_080686cc:
    ldr r2, [r5]
    movs r3, #0
    adds r1, r2, #0
    adds r1, #0x25
    adds r0, r2, #0
    adds r0, #0x28
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r1, r0
    ble lbl_080686ea
    movs r3, #1
lbl_080686ea:
    adds r0, r2, #0
    adds r0, #0x30
    strb r3, [r0]
    ldr r3, [r5]
    movs r4, #0
    adds r0, r3, #0
    adds r0, #0x29
    adds r2, r3, #0
    adds r2, #0x25
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806870a
    movs r4, #1
lbl_0806870a:
    adds r0, r3, #0
    adds r0, #0x31
    strb r4, [r0]
    ldr r3, [r5]
    movs r4, #0
    adds r0, r3, #0
    adds r0, #0x24
    adds r2, r3, #0
    adds r2, #0x27
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806872a
    movs r4, #1
lbl_0806872a:
    adds r0, r3, #0
    adds r0, #0x2f
    strb r4, [r0]
    ldr r2, [r5]
    movs r3, #0
    adds r1, r2, #0
    adds r1, #0x26
    adds r0, r2, #0
    adds r0, #0x24
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r1, r0
    ble lbl_0806874e
    movs r3, #1
lbl_0806874e:
    adds r0, r2, #0
    adds r0, #0x2e
    strb r3, [r0]
    ldr r1, [r5]
    ldr r2, lbl_08068804 @ =0x0840d0d0
    mov ip, r2
    ldrh r0, [r2]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0806876c
    movs r2, #1
lbl_0806876c:
    ldr r6, lbl_08068808 @ =0x00000473
    adds r3, r3, r6
    movs r4, #1
    lsls r2, r2, #5
    ldrb r1, [r3]
    movs r7, #0x21
    rsbs r7, r7, #0
    adds r0, r7, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #8]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08068798
    movs r2, #1
lbl_08068798:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #0x10]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x30
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080687c0
    movs r2, #1
lbl_080687c0:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    ldr r1, [r5]
    mov r2, ip
    ldrh r0, [r2, #0x18]
    lsls r0, r0, #4
    adds r3, r1, r0
    movs r2, #0
    adds r1, #0x31
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080687e8
    movs r2, #1
lbl_080687e8:
    adds r3, r3, r6
    adds r1, r4, #0
    ands r1, r2
    lsls r1, r1, #5
    ldrb r2, [r3]
    adds r0, r7, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r3]
    b lbl_08068850
    .align 2, 0
lbl_080687fc: .4byte gPauseScreenFlag
lbl_08068800: .4byte 0x08754bc4
lbl_08068804: .4byte 0x0840d0d0
lbl_08068808: .4byte 0x00000473
lbl_0806880c:
    ldr r4, lbl_08068874 @ =0x0840d0d0
    ldrh r0, [r4]
    lsls r0, r0, #4
    adds r0, r1, r0
    ldr r3, lbl_08068878 @ =0x00000473
    adds r0, r0, r3
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
    ldr r1, [r5]
    ldrh r0, [r4, #8]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r4, #0x10]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r4, #0x18]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r3
    ldrb r0, [r1]
    orrs r0, r2
    strb r0, [r1]
lbl_08068850:
    mov r0, r8
    cmp r0, #1
    bne lbl_08068880
    ldr r2, [r5]
    ldrb r1, [r2, #0x11]
    rsbs r1, r1, #0
    ldr r0, lbl_0806887c @ =0x00000453
    adds r2, r2, r0
    lsrs r1, r1, #0x1f
    lsls r1, r1, #5
    ldrb r3, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r3
    orrs r0, r1
    strb r0, [r2]
    b lbl_0806888e
    .align 2, 0
lbl_08068874: .4byte 0x0840d0d0
lbl_08068878: .4byte 0x00000473
lbl_0806887c: .4byte 0x00000453
lbl_08068880:
    ldr r0, [r5]
    ldr r1, lbl_08068898 @ =0x00000453
    adds r0, r0, r1
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_0806888e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068898: .4byte 0x00000453

    thumb_func_start sub_0806889c
sub_0806889c: @ 0x0806889c
    push {r4, r5, r6, lr}
    ldr r0, lbl_08068904 @ =0x08754bc4
    ldr r4, [r0]
    ldrb r1, [r4, #0x12]
    adds r6, r0, #0
    cmp r1, #6
    bhi lbl_0806894c
    ldr r5, lbl_08068908 @ =0x0840d200
    adds r0, r1, #0
    lsls r1, r0, #2
    adds r2, r1, r0
    adds r0, r2, r5
    ldrb r3, [r0]
    cmp r3, #0
    beq lbl_0806893a
    adds r0, r5, #2
    adds r0, r2, r0
    ldrb r1, [r0]
    lsls r1, r1, #5
    adds r0, r5, #4
    adds r0, r2, r0
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r1, r1, r0
    ldr r2, lbl_0806890c @ =0x0000040a
    adds r0, r4, r2
    strh r1, [r0]
    ldrb r1, [r4, #0x12]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r1, r5, #3
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #5
    subs r2, #2
    adds r1, r4, r2
    strh r0, [r1]
    adds r1, r3, #0
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_08068924
    ldr r1, [r6]
    ldrb r0, [r1, #0x12]
    cmp r0, #5
    beq lbl_08068914
    ldr r0, lbl_08068910 @ =0x00000412
    adds r1, r1, r0
    movs r0, #3
    strb r0, [r1]
    b lbl_08068938
    .align 2, 0
lbl_08068904: .4byte 0x08754bc4
lbl_08068908: .4byte 0x0840d200
lbl_0806890c: .4byte 0x0000040a
lbl_08068910: .4byte 0x00000412
lbl_08068914:
    ldr r2, lbl_08068920 @ =0x00000412
    adds r1, r1, r2
    movs r0, #0
    strb r0, [r1]
    movs r3, #0
    b lbl_0806893a
    .align 2, 0
lbl_08068920: .4byte 0x00000412
lbl_08068924:
    ldr r2, [r6]
    ldrb r1, [r2, #0x12]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r1, r5, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    ldr r1, lbl_08068954 @ =0x00000412
    adds r2, r2, r1
    strb r0, [r2]
lbl_08068938:
    movs r3, #2
lbl_0806893a:
    ldr r1, [r6]
    ldr r2, lbl_08068958 @ =0x00000413
    adds r1, r1, r2
    lsls r3, r3, #6
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    orrs r0, r3
    strb r0, [r1]
lbl_0806894c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068954: .4byte 0x00000412
lbl_08068958: .4byte 0x00000413

    thumb_func_start draw_pause_screen_info
draw_pause_screen_info: @ 0x0806895c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    movs r3, #0
    ldr r0, lbl_08068998 @ =gGameCompletion
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0806897a
    movs r3, #1
lbl_0806897a:
    ldr r5, lbl_0806899c @ =0x08754bc4
    ldr r2, [r5]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806898a
    movs r3, #1
lbl_0806898a:
    cmp r3, #0
    beq lbl_080689a0
    adds r1, r2, #0
    adds r1, #0x34
    movs r0, #0
    strb r0, [r1]
    b lbl_08068a42
    .align 2, 0
lbl_08068998: .4byte gGameCompletion
lbl_0806899c: .4byte 0x08754bc4
lbl_080689a0:
    cmp r4, #0
    bne lbl_08068a42
    bl count_tanks_in_area
    movs r0, #0
    movs r1, #0
    bl draw_in_game_time_and_tanks
    movs r0, #0
    movs r1, #1
    bl draw_in_game_time_and_tanks
    movs r6, #0
    ldr r0, lbl_08068a50 @ =0x08760190
    mov sl, r0
    ldr r2, lbl_08068a54 @ =0x00000113
    mov ip, r2
    movs r7, #3
    mov sb, r7
    mov r3, sl
    movs r4, #0
    movs r0, #4
    rsbs r0, r0, #0
    mov r8, r0
lbl_080689d0:
    ldr r1, [r5]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    mov r0, sl
    adds r0, #2
    adds r0, r4, r0
    ldrh r0, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r1, r1, r2
    strb r0, [r1]
    ldr r1, [r5]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    add r1, ip
    ldrb r2, [r1]
    mov r0, r8
    ands r0, r2
    mov r7, sb
    orrs r0, r7
    strb r0, [r1]
    ldr r2, [r5]
    ldrh r1, [r3]
    lsls r1, r1, #4
    adds r1, r2, r1
    mov r0, sl
    adds r0, #4
    adds r0, r4, r0
    ldrh r0, [r0]
    movs r7, #0x85
    lsls r7, r7, #1
    adds r1, r1, r7
    strh r0, [r1]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r0, r2, r0
    ldrh r1, [r3, #6]
    subs r7, #2
    adds r0, r0, r7
    strh r1, [r0]
    ldrh r0, [r3]
    lsls r0, r0, #4
    adds r2, r2, r0
    add r2, ip
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r3, #0xa
    adds r4, #0xa
    adds r6, #1
    cmp r6, #4
    bls lbl_080689d0
lbl_08068a42:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068a50: .4byte 0x08760190
lbl_08068a54: .4byte 0x00000113

    thumb_func_start sub_08068a58
sub_08068a58: @ 0x08068a58
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r3, r2, #0
    movs r4, #0
    ldr r0, lbl_08068a7c @ =gEquipment
    ldrb r1, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, #2
    bne lbl_08068a94
    cmp r2, #1
    beq lbl_08068a80
    cmp r2, #1
    bgt lbl_08068aea
    cmp r2, #0
    beq lbl_08068ae8
    b lbl_08068aea
    .align 2, 0
lbl_08068a7c: .4byte gEquipment
lbl_08068a80:
    ldr r0, lbl_08068a90 @ =0x08754bc4
    ldr r0, [r0]
    movs r2, #0xa1
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0x29
    strb r0, [r1]
    b lbl_08068ae8
    .align 2, 0
lbl_08068a90: .4byte 0x08754bc4
lbl_08068a94:
    cmp r3, #6
    bhi lbl_08068aea
    lsls r0, r3, #2
    ldr r1, lbl_08068aa4 @ =lbl_08068aa8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068aa4: .4byte lbl_08068aa8
lbl_08068aa8: @ jump table
    .4byte lbl_08068ae8 @ case 0
    .4byte lbl_08068ae8 @ case 1
    .4byte lbl_08068ac4 @ case 2
    .4byte lbl_08068ace @ case 3
    .4byte lbl_08068ae8 @ case 4
    .4byte lbl_08068adc @ case 5
    .4byte lbl_08068aea @ case 6
lbl_08068ac4:
    ldrh r1, [r5, #2]
    ldrb r0, [r5, #4]
    cmn r1, r0
    beq lbl_08068aea
    b lbl_08068ae8
lbl_08068ace:
    ldr r0, lbl_08068ad8 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xd1
    b lbl_08068ae2
    .align 2, 0
lbl_08068ad8: .4byte 0x08754bc4
lbl_08068adc:
    ldr r0, lbl_08068af4 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xcb
lbl_08068ae2:
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08068aea
lbl_08068ae8:
    movs r4, #2
lbl_08068aea:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08068af4: .4byte 0x08754bc4

    thumb_func_start sub_08068af8
sub_08068af8: @ 0x08068af8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08068b24 @ =0x08754bc4
    ldr r0, [r1]
    movs r2, #0x94
    lsls r2, r2, #1
    adds r4, r0, r2
    movs r6, #7
    adds r5, r1, #0
    cmp r3, #5
    bls lbl_08068b1a
    b lbl_08068d94
lbl_08068b1a:
    lsls r0, r3, #2
    ldr r1, lbl_08068b28 @ =lbl_08068b2c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068b24: .4byte 0x08754bc4
lbl_08068b28: .4byte lbl_08068b2c
lbl_08068b2c: @ jump table
    .4byte lbl_08068b44 @ case 0
    .4byte lbl_08068b9c @ case 1
    .4byte lbl_08068c20 @ case 2
    .4byte lbl_08068c74 @ case 3
    .4byte lbl_08068cc4 @ case 4
    .4byte lbl_08068d06 @ case 5
lbl_08068b44:
    movs r5, #0
    cmp r5, r6
    bge lbl_08068b8e
lbl_08068b4a:
    ldr r0, lbl_08068b98 @ =0x0840d10c
    lsls r1, r5, #4
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0xa]
    ldrh r0, [r1, #2]
    strh r0, [r4, #2]
    ldrh r0, [r1, #4]
    strh r0, [r4]
    movs r0, #3
    ldrb r2, [r1, #8]
    ands r2, r0
    lsls r2, r2, #2
    ldrb r0, [r4, #0xb]
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #0xb]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    bl sub_08068a58
    lsls r0, r0, #6
    ldrb r2, [r4, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r0
    strb r1, [r4, #0xb]
    adds r5, #1
    adds r4, #0x10
    cmp r5, r6
    blt lbl_08068b4a
lbl_08068b8e:
    movs r0, #0
    bl sub_08068dbc
    b lbl_08068d94
    .align 2, 0
lbl_08068b98: .4byte 0x0840d10c
lbl_08068b9c:
    movs r5, #0
    cmp r5, r6
    bge lbl_08068bea
lbl_08068ba2:
    ldr r0, lbl_08068c14 @ =0x0840d10c
    lsls r1, r5, #4
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0xa]
    ldrh r0, [r1, #6]
    ldrh r2, [r1, #2]
    adds r0, r0, r2
    strh r0, [r4, #2]
    ldrh r0, [r1, #4]
    strh r0, [r4]
    movs r0, #3
    ldrb r2, [r1, #8]
    ands r2, r0
    lsls r2, r2, #2
    ldrb r0, [r4, #0xb]
    movs r3, #0xd
    rsbs r3, r3, #0
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strb r0, [r4, #0xb]
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    bl sub_08068a58
    lsls r0, r0, #6
    ldrb r2, [r4, #0xb]
    movs r1, #0x3f
    ands r1, r2
    orrs r1, r0
    strb r1, [r4, #0xb]
    adds r5, #1
    adds r4, #0x10
    cmp r5, r6
    blt lbl_08068ba2
lbl_08068bea:
    movs r0, #1
    bl sub_08068dbc
    ldr r0, lbl_08068c18 @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x5c
    ldrh r2, [r3]
    movs r4, #0x80
    lsls r4, r4, #8
    adds r0, r4, #0
    orrs r0, r2
    strh r0, [r3]
    ldr r0, lbl_08068c1c @ =0x00000403
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    b lbl_08068d94
    .align 2, 0
lbl_08068c14: .4byte 0x0840d10c
lbl_08068c18: .4byte 0x08754bc4
lbl_08068c1c: .4byte 0x00000403
lbl_08068c20:
    movs r1, #1
    mov r8, r1
    movs r5, #0
    subs r7, r6, #1
    cmp r5, r7
    blt lbl_08068c2e
    b lbl_08068d94
lbl_08068c2e:
    ldr r6, lbl_08068c70 @ =0x0840d10c
lbl_08068c30:
    ldrb r1, [r4, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068c62
    ldrh r2, [r4, #2]
    movs r3, #2
    ldrsh r0, [r4, r3]
    ldrh r1, [r6, #2]
    mov ip, r1
    movs r3, #2
    ldrsh r1, [r6, r3]
    cmp r0, r1
    beq lbl_08068c62
    movs r0, #0
    mov r8, r0
    adds r0, r2, #0
    subs r0, #0x40
    strh r0, [r4, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, r1
    bge lbl_08068c62
    mov r1, ip
    strh r1, [r4, #2]
lbl_08068c62:
    adds r6, #0x10
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068c30
    b lbl_08068d94
    .align 2, 0
lbl_08068c70: .4byte 0x0840d10c
lbl_08068c74:
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r4, #0xb]
    adds r4, #0x10
    movs r5, #1
    subs r7, r6, #1
    cmp r5, r7
    blt lbl_08068c88
    b lbl_08068d94
lbl_08068c88:
    ldr r0, lbl_08068cc0 @ =0x0840d10c
    adds r2, r0, #0
    adds r2, #0x1a
    movs r3, #0xc0
lbl_08068c90:
    ldrb r1, [r4, #0xb]
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068cb2
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r4, #0xb]
    ldrb r0, [r4, #0xa]
    adds r0, #1
    strb r0, [r4, #0xa]
    ldrh r0, [r2]
    strh r0, [r4, #2]
    ldrh r0, [r2, #2]
    strh r0, [r4]
lbl_08068cb2:
    adds r2, #0x10
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068c90
    b lbl_08068d94
    .align 2, 0
lbl_08068cc0: .4byte 0x0840d10c
lbl_08068cc4:
    movs r5, #0
    subs r7, r6, #1
    cmp r5, r7
    bge lbl_08068d94
    movs r3, #0xd
    rsbs r3, r3, #0
    movs r2, #0
lbl_08068cd2:
    ldrb r1, [r4, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_08068cfc
    adds r0, r3, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r4, #0xb]
    cmp r5, #0
    beq lbl_08068cfc
    ldrb r0, [r4, #0xa]
    adds r0, #1
    strb r0, [r4, #0xa]
    strb r2, [r4, #8]
    ldrb r0, [r4, #9]
    cmp r0, #0
    beq lbl_08068cfc
    subs r0, #1
    strb r0, [r4, #9]
lbl_08068cfc:
    adds r5, #1
    adds r4, #0x10
    cmp r5, r7
    blt lbl_08068cd2
    b lbl_08068d94
lbl_08068d06:
    ldr r0, [r5]
    ldr r2, lbl_08068da0 @ =0x00000133
    adds r3, r0, r2
    ldrb r2, [r3]
    movs r1, #0x3f
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r4, lbl_08068da4 @ =0x00000143
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068da8 @ =0x00000153
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068dac @ =0x00000173
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    ldr r2, lbl_08068db0 @ =0x00000193
    adds r3, r0, r2
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r0, [r5]
    adds r4, #0x20
    adds r3, r0, r4
    ldrb r2, [r3]
    adds r0, r1, #0
    ands r0, r2
    strb r0, [r3]
    ldr r2, [r5]
    adds r4, r2, #0
    adds r4, #0x5c
    ldrh r3, [r4]
    ldr r0, lbl_08068db4 @ =0x00007fff
    ands r0, r3
    strh r0, [r4]
    ldr r0, lbl_08068db8 @ =0x00000403
    adds r2, r2, r0
    ldrb r0, [r2]
    ands r1, r0
    movs r0, #0x80
    orrs r1, r0
    strb r1, [r2]
lbl_08068d94:
    mov r0, r8
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08068da0: .4byte 0x00000133
lbl_08068da4: .4byte 0x00000143
lbl_08068da8: .4byte 0x00000153
lbl_08068dac: .4byte 0x00000173
lbl_08068db0: .4byte 0x00000193
lbl_08068db4: .4byte 0x00007fff
lbl_08068db8: .4byte 0x00000403

    thumb_func_start sub_08068dbc
sub_08068dbc: @ 0x08068dbc
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #2
    bne lbl_08068de0
    ldr r3, lbl_08068ddc @ =0x08754bc4
    ldr r2, [r3]
    ldrb r1, [r2, #0xc]
    cmp r1, #0
    bne lbl_08068eb0
    movs r0, #1
    strb r0, [r2, #0xc]
    ldr r0, [r3]
    strh r1, [r0, #0xe]
    b lbl_08068eb0
    .align 2, 0
lbl_08068ddc: .4byte 0x08754bc4
lbl_08068de0:
    ldr r0, lbl_08068e6c @ =gEquipment
    ldrb r2, [r0, #0x12]
    movs r1, #0x2c
    adds r4, r0, #0
    cmp r2, #0
    beq lbl_08068dfa
    movs r1, #0x2d
    cmp r2, #1
    beq lbl_08068dfa
    movs r1, #0x2c
    cmp r2, #2
    bne lbl_08068dfa
    movs r1, #0x2e
lbl_08068dfa:
    cmp r3, #0
    bne lbl_08068e0c
    ldr r0, lbl_08068e70 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08068e0c
    movs r1, #0x2e
lbl_08068e0c:
    ldr r2, lbl_08068e74 @ =0x08754bc4
    ldr r0, [r2]
    movs r3, #0xc9
    lsls r3, r3, #1
    adds r0, r0, r3
    strb r1, [r0]
    ldr r0, [r2]
    ldr r1, lbl_08068e78 @ =0x00000193
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    mov r5, ip
    strb r0, [r5]
    ldr r0, [r2]
    movs r6, #0xcc
    lsls r6, r6, #1
    adds r1, r0, r6
    movs r7, #0xc4
    lsls r7, r7, #1
    adds r0, r0, r7
    ldm r0!, {r5, r6, r7}
    stm r1!, {r5, r6, r7}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r2]
    ldr r1, lbl_08068e7c @ =0x000001a3
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #8
    orrs r0, r1
    mov r5, ip
    strb r0, [r5]
    movs r1, #0
    ldr r0, [r2]
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0x2e
    bne lbl_08068e80
    movs r1, #3
    b lbl_08068e98
    .align 2, 0
lbl_08068e6c: .4byte gEquipment
lbl_08068e70: .4byte gPauseScreenFlag
lbl_08068e74: .4byte 0x08754bc4
lbl_08068e78: .4byte 0x00000193
lbl_08068e7c: .4byte 0x000001a3
lbl_08068e80:
    ldrb r2, [r4, #0xf]
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_08068e8e
    movs r1, #2
    b lbl_08068e98
lbl_08068e8e:
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_08068e98
    movs r1, #1
lbl_08068e98:
    lsls r1, r1, #5
    ldr r0, lbl_08068eb8 @ =0x083fd310
    adds r1, r1, r0
    ldr r0, lbl_08068ebc @ =0x08754bbc
    ldr r2, [r0]
    adds r2, #0x80
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_08068eb0:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068eb8: .4byte 0x083fd310
lbl_08068ebc: .4byte 0x08754bbc

    thumb_func_start sub_08068ec0
sub_08068ec0: @ 0x08068ec0
    push {lr}
    ldr r2, lbl_08068ee0 @ =0x08754bc4
    ldr r1, [r2]
    ldrh r0, [r1, #0xe]
    adds r0, #1
    strh r0, [r1, #0xe]
    ldrb r0, [r1, #0xc]
    adds r3, r2, #0
    cmp r0, #6
    bls lbl_08068ed6
    b lbl_08068fc4
lbl_08068ed6:
    lsls r0, r0, #2
    ldr r1, lbl_08068ee4 @ =lbl_08068ee8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08068ee0: .4byte 0x08754bc4
lbl_08068ee4: .4byte lbl_08068ee8
lbl_08068ee8: @ jump table
    .4byte lbl_08068fc4 @ case 0
    .4byte lbl_08068f04 @ case 1
    .4byte lbl_08068f28 @ case 2
    .4byte lbl_08068f4c @ case 3
    .4byte lbl_08068f64 @ case 4
    .4byte lbl_08068f72 @ case 5
    .4byte lbl_08068fb0 @ case 6
lbl_08068f04:
    ldr r2, [r3]
    adds r3, r2, #0
    adds r3, #0x66
    ldrh r1, [r3]
    ldr r0, lbl_08068f20 @ =0x0000fffb
    ands r0, r1
    strh r0, [r3]
    ldr r1, lbl_08068f24 @ =0x0400004b
    movs r0, #0xd0
    strb r0, [r1]
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
    b lbl_08068fc4
    .align 2, 0
lbl_08068f20: .4byte 0x0000fffb
lbl_08068f24: .4byte 0x0400004b
lbl_08068f28:
    ldr r1, lbl_08068f44 @ =gWrittenToBLDALPHA_H
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08068f34
    adds r0, #2
    strh r0, [r1]
lbl_08068f34:
    ldrh r0, [r1]
    cmp r0, #0x10
    bls lbl_08068f3e
    movs r0, #0x10
    strh r0, [r1]
lbl_08068f3e:
    ldr r2, lbl_08068f48 @ =gWrittenToBLDALPHA_L
    b lbl_08068f8a
    .align 2, 0
lbl_08068f44: .4byte gWrittenToBLDALPHA_H
lbl_08068f48: .4byte gWrittenToBLDALPHA_L
lbl_08068f4c:
    movs r0, #1
    bl sub_08068dbc
    ldr r3, lbl_08068f60 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1, #0xc]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #0xc]
    b lbl_08068fa2
    .align 2, 0
lbl_08068f60: .4byte 0x08754bc4
lbl_08068f64:
    ldr r1, [r3]
    ldrb r0, [r1, #0xc]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #0xc]
    ldr r0, [r3]
    strh r2, [r0, #0xe]
lbl_08068f72:
    ldr r1, lbl_08068fa8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_08068f7e
    adds r0, #2
    strh r0, [r1]
lbl_08068f7e:
    ldrh r0, [r1]
    cmp r0, #0x10
    bls lbl_08068f88
    movs r0, #0x10
    strh r0, [r1]
lbl_08068f88:
    ldr r2, lbl_08068fac @ =gWrittenToBLDALPHA_H
lbl_08068f8a:
    ldrh r1, [r1]
    movs r0, #0x10
    subs r0, r0, r1
    strh r0, [r2]
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #0
    bne lbl_08068fc4
    ldr r0, [r3]
    ldrb r1, [r0, #0xc]
    adds r1, #1
    strb r1, [r0, #0xc]
lbl_08068fa2:
    ldr r0, [r3]
    strh r2, [r0, #0xe]
    b lbl_08068fc4
    .align 2, 0
lbl_08068fa8: .4byte gWrittenToBLDALPHA_L
lbl_08068fac: .4byte gWrittenToBLDALPHA_H
lbl_08068fb0:
    ldr r2, [r3]
    adds r1, r2, #0
    adds r1, #0x66
    movs r3, #0
    ldr r0, lbl_08068fc8 @ =0x00003c44
    strh r0, [r1]
    ldr r1, lbl_08068fcc @ =0x0400004b
    movs r0, #0x18
    strb r0, [r1]
    strb r3, [r2, #0xc]
lbl_08068fc4:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08068fc8: .4byte 0x00003c44
lbl_08068fcc: .4byte 0x0400004b

    thumb_func_start sub_08068fd0
sub_08068fd0: @ 0x08068fd0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #6
    bls lbl_08068fdc
    movs r4, #7
lbl_08068fdc:
    ldr r5, lbl_08069018 @ =0x08754bc4
    ldr r0, [r5]
    movs r1, #0x85
    lsls r1, r1, #3
    adds r0, r0, r1
    ldr r1, lbl_0806901c @ =0x0840d090
    lsls r4, r4, #3
    adds r4, r4, r1
    ldrb r1, [r4, #1]
    bl UpdateMenuOamDataID
    ldr r0, [r5]
    movs r6, #0x89
    lsls r6, r6, #3
    adds r0, r0, r6
    ldrb r1, [r4, #2]
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    ldrh r2, [r4, #4]
    ldr r3, lbl_08069020 @ =0x0000044a
    adds r0, r1, r3
    strh r2, [r0]
    ldrh r0, [r4, #6]
    adds r1, r1, r6
    strh r0, [r1]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069018: .4byte 0x08754bc4
lbl_0806901c: .4byte 0x0840d090
lbl_08069020: .4byte 0x0000044a

    thumb_func_start sub_08069024
sub_08069024: @ 0x08069024
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    cmp r0, #0
    bne lbl_08069124
    ldr r1, lbl_08069110 @ =0x08754bc4
    ldr r0, [r1]
    movs r2, #0x95
    lsls r2, r2, #3
    adds r3, r0, r2
    ldrb r0, [r3, #0xb]
    movs r5, #4
    rsbs r5, r5, #0
    adds r2, r5, #0
    ands r2, r0
    movs r0, #2
    orrs r2, r0
    strb r2, [r3, #0xb]
    ldr r0, lbl_08069114 @ =gEquipment
    ldrb r0, [r0, #0x12]
    movs r4, #0x10
    mov r8, r1
    cmp r0, #2
    bne lbl_08069060
    movs r4, #0x11
lbl_08069060:
    strb r4, [r3, #0xa]
    movs r0, #0x3f
    ands r2, r0
    movs r0, #0x40
    orrs r2, r0
    strb r2, [r3, #0xb]
    mov r7, r8
    ldr r0, [r7]
    movs r1, #0x97
    lsls r1, r1, #3
    adds r3, r0, r1
    ldr r2, lbl_08069118 @ =0x0840d188
    mov sb, r2
    ldr r7, lbl_0806911c @ =gCurrentArea
    mov sl, r7
    adds r6, r5, #0
    adds r2, #2
    movs r5, #2
    movs r4, #6
lbl_08069086:
    ldrh r0, [r2]
    strh r0, [r3, #2]
    ldrh r0, [r2, #2]
    strh r0, [r3]
    ldrb r1, [r3, #0xb]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strb r0, [r3, #0xb]
    adds r2, #8
    subs r4, #1
    adds r3, #0x10
    cmp r4, #0
    bge lbl_08069086
    mov r1, r8
    ldr r0, [r1]
    movs r2, #0xa5
    lsls r2, r2, #3
    adds r3, r0, r2
    movs r4, #0
    movs r6, #4
    rsbs r6, r6, #0
    ldr r5, lbl_08069120 @ =0x0840d1c0
lbl_080690b4:
    ldrh r0, [r5]
    strh r0, [r3, #2]
    ldrh r0, [r5, #2]
    strh r0, [r3]
    ldrb r0, [r3, #0xb]
    adds r2, r6, #0
    ands r2, r0
    movs r0, #2
    orrs r2, r0
    movs r0, #0x3f
    ands r2, r0
    strb r2, [r3, #0xb]
    mov r7, r8
    ldr r0, [r7]
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080690f2
    movs r0, #2
    ldrsh r1, [r3, r0]
    movs r7, #0
    ldrsh r0, [r3, r7]
    cmn r1, r0
    beq lbl_080690f2
    movs r1, #0x40
    adds r0, r2, #0
    orrs r0, r1
    strb r0, [r3, #0xb]
lbl_080690f2:
    ldrb r1, [r3, #0xb]
    movs r0, #0xc0
    ands r0, r1
    movs r1, #0
    cmp r0, #0
    beq lbl_08069100
    movs r1, #0xf
lbl_08069100:
    strb r1, [r3, #0xa]
    adds r5, #4
    adds r4, #1
    adds r3, #0x10
    cmp r4, #0xf
    ble lbl_080690b4
    b lbl_08069182
    .align 2, 0
lbl_08069110: .4byte 0x08754bc4
lbl_08069114: .4byte gEquipment
lbl_08069118: .4byte 0x0840d188
lbl_0806911c: .4byte gCurrentArea
lbl_08069120: .4byte 0x0840d1c0
lbl_08069124:
    ldr r0, lbl_08069164 @ =0x08754bc4
    mov r8, r0
    ldr r1, lbl_08069168 @ =0x0840d188
    mov sb, r1
    ldr r2, lbl_0806916c @ =gCurrentArea
    mov sl, r2
    mov r7, ip
    cmp r7, #2
    bne lbl_08069182
    ldr r0, [r0]
    movs r1, #0xa5
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r4, #0
    movs r2, #0x3f
    mov r5, r8
lbl_08069144:
    ldr r0, [r5]
    adds r0, #0x44
    ldrh r1, [r0]
    asrs r1, r4
    movs r0, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_08069170
    movs r0, #0xf
    strb r0, [r3, #0xa]
    ldrb r1, [r3, #0xb]
    adds r0, r2, #0
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    b lbl_08069178
    .align 2, 0
lbl_08069164: .4byte 0x08754bc4
lbl_08069168: .4byte 0x0840d188
lbl_0806916c: .4byte gCurrentArea
lbl_08069170:
    strb r1, [r3, #0xa]
    ldrb r1, [r3, #0xb]
    adds r0, r2, #0
    ands r0, r1
lbl_08069178:
    strb r0, [r3, #0xb]
    adds r4, #1
    adds r3, #0x10
    cmp r4, #0xf
    ble lbl_08069144
lbl_08069182:
    movs r7, #2
    mov r2, ip
    cmp r2, #0
    bne lbl_0806918c
    movs r7, #1
lbl_0806918c:
    mov r1, r8
    ldr r0, [r1]
    movs r2, #0x97
    lsls r2, r2, #3
    adds r3, r0, r2
    movs r4, #0
    mov r6, r8
    ldr r5, lbl_080691a8 @ =0x0840d188
lbl_0806919c:
    ldr r0, [r6]
    ldrb r0, [r0, #0x12]
    cmp r0, r4
    beq lbl_080691ac
    ldrb r0, [r5]
    b lbl_080691ae
    .align 2, 0
lbl_080691a8: .4byte 0x0840d188
lbl_080691ac:
    ldrb r0, [r5, #1]
lbl_080691ae:
    strb r0, [r3, #0xa]
    ldr r0, [r6]
    adds r0, #0xba
    ldrb r1, [r0]
    asrs r1, r4
    movs r0, #1
    ands r1, r0
    movs r2, #0
    cmp r1, #0
    beq lbl_080691c4
    adds r2, r7, #0
lbl_080691c4:
    lsls r2, r2, #6
    ldrb r1, [r3, #0xb]
    movs r0, #0x3f
    ands r0, r1
    orrs r0, r2
    strb r0, [r3, #0xb]
    adds r5, #8
    adds r4, #1
    adds r3, #0x10
    cmp r4, #6
    ble lbl_0806919c
    mov r7, r8
    ldr r0, [r7]
    movs r1, #0x95
    lsls r1, r1, #3
    adds r3, r0, r1
    mov r2, sl
    ldrb r0, [r2]
    lsls r0, r0, #3
    add r0, sb
    ldrh r0, [r0, #2]
    strh r0, [r3, #2]
    ldrb r0, [r2]
    lsls r0, r0, #3
    add r0, sb
    ldrh r0, [r0, #4]
    subs r0, #0x18
    strh r0, [r3]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0806920c
sub_0806920c: @ 0x0806920c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r1, lbl_080692a8 @ =0x08754bc4
    ldr r0, [r1]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r3, r0, r2
    adds r7, r1, #0
    ldr r4, lbl_080692ac @ =0x0840d028
    mov r8, r4
    movs r5, #0x16
lbl_08069224:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069224
    ldr r0, [r7]
    movs r6, #0x85
    lsls r6, r6, #3
    adds r3, r0, r6
    movs r5, #3
lbl_08069242:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069242
    ldr r0, [r7]
    movs r1, #0x8d
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r5, #3
lbl_08069260:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_08069260
    ldr r0, [r7]
    movs r1, #0x95
    lsls r1, r1, #3
    adds r3, r0, r1
    movs r5, #0x17
lbl_0806927e:
    adds r0, r3, #0
    mov r1, r8
    ldm r1!, {r2, r4, r6}
    stm r0!, {r2, r4, r6}
    ldr r1, [r1]
    str r1, [r0]
    subs r5, #1
    adds r3, #0x10
    cmp r5, #0
    bge lbl_0806927e
    ldr r2, [r7]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080692b0
    movs r0, #0
    bl sub_08068af8
    b lbl_08069578
    .align 2, 0
lbl_080692a8: .4byte 0x08754bc4
lbl_080692ac: .4byte 0x0840d028
lbl_080692b0:
    ldr r0, lbl_08069340 @ =gEquipment
    ldrb r0, [r0, #0x12]
    movs r1, #2
    cmp r0, #2
    beq lbl_080692bc
    movs r1, #1
lbl_080692bc:
    ldr r3, lbl_08069344 @ =0x00000402
    adds r0, r2, r3
    strb r1, [r0]
    ldr r2, [r7]
    ldr r4, lbl_08069348 @ =0x00000403
    adds r2, r2, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    ldr r0, lbl_0806934c @ =gMinimapX
    ldrb r0, [r0]
    lsls r0, r0, #5
    ldr r6, lbl_08069350 @ =0x000003fa
    adds r1, r2, r6
    strh r0, [r1]
    ldr r0, lbl_08069354 @ =gMinimapY
    ldrb r0, [r0]
    lsls r0, r0, #5
    subs r3, #0xa
    adds r1, r2, r3
    strh r0, [r1]
    adds r4, #1
    adds r2, r2, r4
    ldrb r3, [r2]
    movs r1, #0x10
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r3
    movs r4, #3
    orrs r0, r4
    strb r0, [r2]
    ldr r0, [r7]
    adds r6, #0x1a
    adds r0, r0, r6
    ldrb r2, [r0]
    ands r1, r2
    orrs r1, r4
    strb r1, [r0]
    ldr r3, [r7]
    ldrh r1, [r3]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806935c
    ldr r0, lbl_08069348 @ =0x00000403
    adds r3, r3, r0
    ldrb r2, [r3]
    movs r1, #4
    rsbs r1, r1, #0
    adds r0, r1, #0
    ands r0, r2
    movs r4, #1
    orrs r0, r4
    strb r0, [r3]
    ldr r0, [r7]
    ldr r2, lbl_08069358 @ =0x00000413
    adds r0, r0, r2
    ldrb r2, [r0]
    ands r1, r2
    orrs r1, r4
    strb r1, [r0]
    b lbl_08069372
    .align 2, 0
lbl_08069340: .4byte gEquipment
lbl_08069344: .4byte 0x00000402
lbl_08069348: .4byte 0x00000403
lbl_0806934c: .4byte gMinimapX
lbl_08069350: .4byte 0x000003fa
lbl_08069354: .4byte gMinimapY
lbl_08069358: .4byte 0x00000413
lbl_0806935c:
    ldr r6, lbl_080693fc @ =0x00000403
    adds r1, r3, r6
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
    ldr r1, [r7]
    ldr r0, lbl_08069400 @ =0x00000413
    adds r1, r1, r0
    ldrb r0, [r1]
    orrs r0, r4
    strb r0, [r1]
lbl_08069372:
    ldr r1, [r7]
    ldrb r0, [r1, #4]
    cmp r0, #1
    beq lbl_08069396
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    movs r1, #0
    strb r1, [r0]
    ldr r2, [r7]
    movs r3, #0x84
    lsls r3, r3, #1
    adds r0, r2, r3
    strh r1, [r0]
    movs r4, #0x85
    lsls r4, r4, #1
    adds r0, r2, r4
    strh r1, [r0]
lbl_08069396:
    ldr r2, [r7]
    ldrh r1, [r2]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08069418
    ldr r1, lbl_08069404 @ =0x0840d180
    ldrb r0, [r2, #0x12]
    adds r0, r0, r1
    ldrb r1, [r0]
    ldr r6, lbl_08069408 @ =0x00000432
    adds r0, r2, r6
    strb r1, [r0]
    ldr r1, [r7]
    ldr r3, lbl_0806940c @ =0x0840d17c
    ldrh r2, [r3, #2]
    movs r4, #0x85
    lsls r4, r4, #3
    adds r0, r1, r4
    strh r2, [r0]
    ldrh r2, [r3]
    subs r6, #8
    adds r0, r1, r6
    strh r2, [r0]
    ldr r3, lbl_08069410 @ =0x00000433
    adds r1, r1, r3
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    ldr r2, [r7]
    ldr r0, lbl_08069414 @ =0x00000434
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    b lbl_08069502
    .align 2, 0
lbl_080693fc: .4byte 0x00000403
lbl_08069400: .4byte 0x00000413
lbl_08069404: .4byte 0x0840d180
lbl_08069408: .4byte 0x00000432
lbl_0806940c: .4byte 0x0840d17c
lbl_08069410: .4byte 0x00000433
lbl_08069414: .4byte 0x00000434
lbl_08069418:
    movs r0, #0x20
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_08069474
    ldr r1, lbl_08069464 @ =gCurrentArea
    ldrb r0, [r1]
    movs r5, #7
    cmp r0, #6
    bhi lbl_08069430
    adds r5, r0, #0
lbl_08069430:
    movs r4, #0x85
    lsls r4, r4, #3
    adds r0, r2, r4
    ldr r2, lbl_08069468 @ =0x0840d090
    lsls r1, r5, #3
    adds r1, r1, r2
    ldrb r1, [r1]
    bl UpdateMenuOamDataID
    ldr r1, [r7]
    adds r4, r1, r4
    movs r0, #0xc
    strh r0, [r4]
    ldr r3, lbl_0806946c @ =0x0000042a
    adds r2, r1, r3
    movs r0, #0xe8
    lsls r0, r0, #1
    strh r0, [r2]
    ldr r4, lbl_08069470 @ =0x00000433
    adds r1, r1, r4
    ldrb r2, [r1]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r2
    strb r0, [r1]
    b lbl_08069502
    .align 2, 0
lbl_08069464: .4byte gCurrentArea
lbl_08069468: .4byte 0x0840d090
lbl_0806946c: .4byte 0x0000042a
lbl_08069470: .4byte 0x00000433
lbl_08069474:
    ldr r6, lbl_08069584 @ =0x00000442
    adds r0, r2, r6
    strb r1, [r0]
    ldr r1, [r7]
    movs r0, #0x87
    lsls r0, r0, #3
    adds r2, r1, r0
    movs r3, #0
    mov r8, r3
    movs r0, #0x18
    strh r0, [r2]
    ldr r4, lbl_08069588 @ =0x0000043a
    adds r0, r1, r4
    movs r6, #0xe8
    lsls r6, r6, #1
    strh r6, [r0]
    ldr r0, lbl_0806958c @ =0x00000443
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r2
    movs r5, #1
    orrs r0, r5
    strb r0, [r1]
    ldr r0, lbl_08069590 @ =gCurrentArea
    ldrb r0, [r0]
    bl sub_08068fd0
    ldr r1, [r7]
    movs r3, #0x85
    lsls r3, r3, #3
    adds r2, r1, r3
    movs r0, #0xc
    strh r0, [r2]
    ldr r2, lbl_08069594 @ =0x0000042a
    adds r0, r1, r2
    strh r6, [r0]
    adds r3, #0xb
    adds r1, r1, r3
    ldrb r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    orrs r0, r5
    strb r0, [r1]
    ldr r0, [r7]
    ldr r6, lbl_08069598 @ =0x00000453
    adds r0, r0, r6
    ldrb r1, [r0]
    ands r4, r1
    orrs r4, r5
    strb r4, [r0]
    ldr r0, [r7]
    ldr r1, lbl_0806959c @ =0x00000462
    adds r0, r0, r1
    mov r2, r8
    strb r2, [r0]
    ldr r1, [r7]
    adds r3, #0x25
    adds r2, r1, r3
    movs r0, #0xcc
    lsls r0, r0, #1
    strh r0, [r2]
    ldr r4, lbl_080695a0 @ =0x0000045a
    adds r1, r1, r4
    adds r0, #0x88
    strh r0, [r1]
    movs r0, #0
    bl sub_08069024
lbl_08069502:
    movs r0, #0
    bl draw_pause_screen_info
    ldr r7, lbl_080695a4 @ =0x08754bc4
    ldr r6, lbl_080695a8 @ =0x0840d0d0
    ldr r0, lbl_080695ac @ =0x00000473
    mov r8, r0
    ldr r1, lbl_080695b0 @ =gPauseScreenFlag
    mov ip, r1
    adds r4, r6, #0
    adds r4, #0x20
    movs r5, #0x20
lbl_0806951a:
    subs r4, #8
    subs r5, #8
    mov r2, ip
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r0, #2
    bne lbl_0806953e
    ldr r2, [r7]
    ldrh r0, [r4]
    lsls r0, r0, #4
    adds r2, r2, r0
    add r2, r8
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
lbl_0806953e:
    ldr r1, [r7]
    ldrh r3, [r4]
    lsls r3, r3, #4
    adds r1, r1, r3
    adds r0, r6, #2
    adds r0, r5, r0
    ldrh r0, [r0]
    ldr r2, lbl_080695b4 @ =0x00000472
    adds r1, r1, r2
    strb r0, [r1]
    ldr r2, [r7]
    adds r2, r2, r3
    adds r0, r6, #4
    adds r0, r5, r0
    ldrh r1, [r0]
    ldr r3, lbl_080695b8 @ =0x0000046a
    adds r0, r2, r3
    strh r1, [r0]
    ldrh r1, [r4, #6]
    subs r3, #2
    adds r0, r2, r3
    strh r1, [r0]
    add r2, r8
    ldrb r0, [r2]
    movs r1, #3
    orrs r0, r1
    strb r0, [r2]
    cmp r4, r6
    bgt lbl_0806951a
lbl_08069578:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069584: .4byte 0x00000442
lbl_08069588: .4byte 0x0000043a
lbl_0806958c: .4byte 0x00000443
lbl_08069590: .4byte gCurrentArea
lbl_08069594: .4byte 0x0000042a
lbl_08069598: .4byte 0x00000453
lbl_0806959c: .4byte 0x00000462
lbl_080695a0: .4byte 0x0000045a
lbl_080695a4: .4byte 0x08754bc4
lbl_080695a8: .4byte 0x0840d0d0
lbl_080695ac: .4byte 0x00000473
lbl_080695b0: .4byte gPauseScreenFlag
lbl_080695b4: .4byte 0x00000472
lbl_080695b8: .4byte 0x0000046a

    thumb_func_start sub_080695bc
sub_080695bc: @ 0x080695bc
    push {r4, lr}
    ldr r1, lbl_080695f0 @ =gNextOamSlot
    movs r0, #0
    strb r0, [r1]
    ldr r4, lbl_080695f4 @ =0x08754bc4
    ldr r1, [r4]
    movs r0, #0x85
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080695f8 @ =0x0840d3ec
    movs r0, #4
    bl process_menu_oam
    ldr r1, [r4]
    ldrb r0, [r1, #0x11]
    cmp r0, #0
    beq lbl_08069600
    movs r0, #0x95
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080695fc @ =0x0840d5dc
    movs r0, #0x18
    bl process_menu_oam
    b lbl_0806960e
    .align 2, 0
lbl_080695f0: .4byte gNextOamSlot
lbl_080695f4: .4byte 0x08754bc4
lbl_080695f8: .4byte 0x0840d3ec
lbl_080695fc: .4byte 0x0840d5dc
lbl_08069600:
    movs r0, #0x8d
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_08069690 @ =0x0840d4f4
    movs r0, #4
    bl process_menu_oam
lbl_0806960e:
    ldr r4, lbl_08069694 @ =0x08754bc4
    ldr r1, [r4]
    movs r0, #0x84
    lsls r0, r0, #1
    adds r1, r1, r0
    ldr r2, lbl_08069698 @ =0x0840d22c
    movs r0, #0x17
    bl process_menu_oam
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806963a
    movs r0, #0xea
    lsls r0, r0, #2
    adds r1, r2, r0
    ldr r2, lbl_0806969c @ =0x0840d55c
    movs r0, #5
    bl process_menu_oam
lbl_0806963a:
    ldr r2, [r4]
    ldrb r0, [r2, #0x11]
    cmp r0, #0
    bne lbl_08069684
    ldrh r1, [r2]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08069684
    ldr r1, lbl_080696a0 @ =gCurrentArea
    ldrb r0, [r2, #0x12]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08069664
    movs r0, #0xfe
    lsls r0, r0, #2
    adds r1, r2, r0
    ldr r2, lbl_080696a4 @ =0x0840d51c
    movs r0, #1
    bl process_menu_oam
lbl_08069664:
    ldr r1, [r4]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r1, r1, r0
    ldr r2, lbl_0806969c @ =0x0840d55c
    movs r0, #0xc
    bl process_menu_oam
    ldr r1, [r4]
    movs r0, #0x81
    lsls r0, r0, #3
    adds r1, r1, r0
    ldr r2, lbl_080696a8 @ =0x0840d534
    movs r0, #1
    bl process_menu_oam
lbl_08069684:
    bl ResetFreeOAM
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069690: .4byte 0x0840d4f4
lbl_08069694: .4byte 0x08754bc4
lbl_08069698: .4byte 0x0840d22c
lbl_0806969c: .4byte 0x0840d55c
lbl_080696a0: .4byte gCurrentArea
lbl_080696a4: .4byte 0x0840d51c
lbl_080696a8: .4byte 0x0840d534

    thumb_func_start process_menu_oam
process_menu_oam: @ 0x080696ac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    adds r3, r1, #0
    str r2, [sp, #4]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    ldr r0, lbl_08069740 @ =gOamData
    mov sb, r0
    ldr r1, lbl_08069744 @ =gNextOamSlot
    ldrb r2, [r1]
    str r2, [sp, #8]
    mov sl, r2
    lsls r0, r2, #3
    add sb, r0
    movs r0, #0
    str r0, [sp, #0xc]
    ldr r1, [sp]
    cmp r0, r1
    blt lbl_080696de
    b lbl_080699de
lbl_080696de:
    ldrb r0, [r3, #0xa]
    adds r6, r0, #0
    cmp r6, #0
    bne lbl_080696e8
    b lbl_080699ce
lbl_080696e8:
    ldrb r1, [r3, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_080696f4
    b lbl_080699ce
lbl_080696f4:
    cmp r0, #0x80
    bne lbl_08069708
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r3, #0xb]
    movs r0, #0
    strb r0, [r3, #8]
    strb r0, [r3, #9]
lbl_08069708:
    ldrb r1, [r3, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r3, #0xb]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #4]
    adds r4, r0, r2
    ldr r5, [r4]
    ldrb r2, [r3, #9]
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r1, [r3, #8]
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_0806972c
    b lbl_08069880
lbl_0806972c:
    ldrb r0, [r4, #4]
    cmp r0, #9
    bls lbl_08069734
    b lbl_08069880
lbl_08069734:
    lsls r0, r0, #2
    ldr r1, lbl_08069748 @ =lbl_0806974c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069740: .4byte gOamData
lbl_08069744: .4byte gNextOamSlot
lbl_08069748: .4byte lbl_0806974c
lbl_0806974c: @ jump table
    .4byte lbl_08069880 @ case 0
    .4byte lbl_08069774 @ case 1
    .4byte lbl_0806978e @ case 2
    .4byte lbl_08069794 @ case 3
    .4byte lbl_080697c2 @ case 4
    .4byte lbl_080697de @ case 5
    .4byte lbl_08069804 @ case 6
    .4byte lbl_0806981e @ case 7
    .4byte lbl_08069844 @ case 8
    .4byte lbl_0806985e @ case 9
lbl_08069774:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    strb r0, [r3, #9]
    b lbl_08069880
lbl_0806978e:
    movs r0, #0
    strb r0, [r3, #8]
    b lbl_08069880
lbl_08069794:
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    adds r0, r2, #1
    movs r4, #0
    strb r0, [r3, #9]
    ldrb r2, [r3, #9]
    lsls r0, r2, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_080697be
    subs r0, r2, #1
    strb r0, [r3, #9]
    subs r0, r1, #1
    strb r0, [r3, #8]
    ldrb r0, [r3, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r3, #0xb]
    b lbl_08069880
lbl_080697be:
    strb r4, [r3, #8]
    b lbl_08069880
lbl_080697c2:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    strb r0, [r3, #0xa]
    strb r0, [r3, #9]
    b lbl_08069854
lbl_080697de:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069880
    adds r0, r6, #1
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #4]
    adds r0, r0, r1
    b lbl_0806987e
lbl_08069804:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r1, [r3, #9]
    adds r0, r1, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069880
    adds r0, r6, #1
    b lbl_08069872
lbl_0806981e:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r0, #1
    strb r0, [r3, #9]
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069880
    subs r0, r6, #1
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #4]
    adds r0, r0, r1
    b lbl_0806987e
lbl_08069844:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_0806986a
    strb r1, [r3, #0xa]
    strb r1, [r3, #9]
lbl_08069854:
    ldrb r1, [r3, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r3, #0xb]
    b lbl_080699ce
lbl_0806985e:
    movs r0, #0
    strb r0, [r3, #8]
    ldrb r0, [r3, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069870
lbl_0806986a:
    subs r0, #1
    strb r0, [r3, #9]
    b lbl_08069880
lbl_08069870:
    subs r0, r6, #1
lbl_08069872:
    strb r0, [r3, #0xa]
    strb r1, [r3, #9]
    ldrb r0, [r3, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #4]
    adds r0, r0, r2
lbl_0806987e:
    ldr r5, [r0]
lbl_08069880:
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    ldrb r1, [r3, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069892
    b lbl_080699ce
lbl_08069892:
    ldrb r0, [r3, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_080698b4
    ldr r0, lbl_080698ac @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698b0 @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698ac: .4byte gBG0HOFS_NonGameplay
lbl_080698b0: .4byte gBG0VOFS_NonGameplay
lbl_080698b4:
    cmp r1, #1
    bne lbl_080698d0
    ldr r0, lbl_080698c8 @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698cc @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698c8: .4byte gBG1HOFS_NonGameplay
lbl_080698cc: .4byte gBG1VOFS_NonGameplay
lbl_080698d0:
    cmp r1, #2
    bne lbl_080698ec
    ldr r0, lbl_080698e4 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_080698e8 @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_080698e4: .4byte gBG2HOFS_NonGameplay
lbl_080698e8: .4byte gBG2VOFS_NonGameplay
lbl_080698ec:
    cmp r1, #3
    bne lbl_08069908
    ldr r0, lbl_08069900 @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r7, [r0, r1]
    ldr r0, lbl_08069904 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r6, [r0, r2]
    b lbl_0806990c
    .align 2, 0
lbl_08069900: .4byte gBG3HOFS_NonGameplay
lbl_08069904: .4byte gBG3VOFS_NonGameplay
lbl_08069908:
    movs r7, #0
    movs r6, #0
lbl_0806990c:
    ldrh r0, [r3]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r6, #2
    subs r0, r0, r1
    ldr r1, lbl_080699f8 @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r6, r1, r0
    ldrh r0, [r3, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_080699fc @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrb r0, [r3, #9]
    lsls r0, r0, #3
    adds r5, r5, r0
    ldr r4, [r5]
    ldrh r0, [r4]
    ldr r1, [sp, #8]
    adds r0, r1, r0
    cmp r0, #0x7f
    bgt lbl_080699de
    str r0, [sp, #8]
    adds r4, #2
    cmp sl, r0
    bge lbl_080699ce
    movs r2, #3
    mov ip, r2
    movs r0, #0xd
    rsbs r0, r0, #0
    mov r8, r0
    ldr r1, lbl_08069a00 @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r5, r0, r1
lbl_08069960:
    ldrh r1, [r4]
    adds r4, #2
    mov r0, sb
    strh r1, [r0]
    movs r2, #2
    add sb, r2
    adds r0, r1, r6
    strb r0, [r5]
    ldrh r1, [r4]
    adds r4, #2
    mov r0, sb
    strh r1, [r0]
    add sb, r2
    adds r1, r1, r7
    ldr r0, lbl_08069a04 @ =0x000001ff
    ands r1, r0
    ldrh r2, [r5, #2]
    ldr r0, lbl_08069a08 @ =0xfffffe00
    ands r0, r2
    orrs r0, r1
    strh r0, [r5, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    ldrb r1, [r3, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    mov r2, ip
    ands r1, r2
    lsls r1, r1, #2
    ldrb r2, [r5, #5]
    mov r0, r8
    ands r0, r2
    orrs r0, r1
    strb r0, [r5, #5]
    ldrb r1, [r3, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    mov r0, ip
    ands r1, r0
    lsls r1, r1, #2
    ldrb r2, [r5, #1]
    mov r0, r8
    ands r0, r2
    orrs r0, r1
    strb r0, [r5, #1]
    movs r1, #4
    add sb, r1
    adds r5, #8
    movs r2, #1
    add sl, r2
    ldr r0, [sp, #8]
    cmp sl, r0
    blt lbl_08069960
lbl_080699ce:
    ldr r1, [sp, #0xc]
    adds r1, #1
    str r1, [sp, #0xc]
    adds r3, #0x10
    ldr r2, [sp]
    cmp r1, r2
    bge lbl_080699de
    b lbl_080696de
lbl_080699de:
    mov r0, sp
    ldrb r1, [r0, #8]
    ldr r0, lbl_08069a0c @ =gNextOamSlot
    strb r1, [r0]
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080699f8: .4byte gOamYOffset_NonGameplay
lbl_080699fc: .4byte gOamXOffset_NonGameplay
lbl_08069a00: .4byte gOamData
lbl_08069a04: .4byte 0x000001ff
lbl_08069a08: .4byte 0xfffffe00
lbl_08069a0c: .4byte gNextOamSlot

    thumb_func_start sub_08069a10
sub_08069a10: @ 0x08069a10
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r5, r1, #0
    str r2, [sp, #0x10]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0xc]
    ldr r0, lbl_08069aa4 @ =gOamData
    mov sb, r0
    ldr r0, lbl_08069aa8 @ =gNextOamSlot
    ldrb r0, [r0]
    str r0, [sp, #0x14]
    mov sl, r0
    lsls r0, r0, #3
    add sb, r0
    movs r1, #0
    str r1, [sp, #0x18]
    ldr r2, [sp, #0xc]
    cmp r1, r2
    blt lbl_08069a42
    b lbl_08069da2
lbl_08069a42:
    ldrb r0, [r5, #0xa]
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_08069a4c
    b lbl_08069d92
lbl_08069a4c:
    ldrb r1, [r5, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_08069a58
    b lbl_08069d92
lbl_08069a58:
    cmp r0, #0x80
    bne lbl_08069a6c
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r5, #0xb]
    movs r0, #0
    strb r0, [r5, #8]
    strb r0, [r5, #9]
lbl_08069a6c:
    ldrb r1, [r5, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5, #0xb]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r3, r0, r1
    ldr r6, [r3]
    ldrb r2, [r5, #9]
    lsls r0, r2, #3
    adds r0, r0, r6
    ldrb r1, [r5, #8]
    adds r4, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_08069a92
    b lbl_08069be4
lbl_08069a92:
    ldrb r0, [r3, #4]
    cmp r0, #9
    bls lbl_08069a9a
    b lbl_08069be4
lbl_08069a9a:
    lsls r0, r0, #2
    ldr r1, lbl_08069aac @ =lbl_08069ab0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069aa4: .4byte gOamData
lbl_08069aa8: .4byte gNextOamSlot
lbl_08069aac: .4byte lbl_08069ab0
lbl_08069ab0: @ jump table
    .4byte lbl_08069be4 @ case 0
    .4byte lbl_08069ad8 @ case 1
    .4byte lbl_08069af2 @ case 2
    .4byte lbl_08069af8 @ case 3
    .4byte lbl_08069b26 @ case 4
    .4byte lbl_08069b42 @ case 5
    .4byte lbl_08069b5c @ case 6
    .4byte lbl_08069b82 @ case 7
    .4byte lbl_08069ba8 @ case 8
    .4byte lbl_08069bc2 @ case 9
lbl_08069ad8:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    strb r0, [r5, #9]
    b lbl_08069be4
lbl_08069af2:
    movs r0, #0
    strb r0, [r5, #8]
    b lbl_08069be4
lbl_08069af8:
    lsls r0, r4, #3
    adds r0, r0, r6
    ldrb r2, [r0, #4]
    adds r0, r4, #1
    movs r3, #0
    strb r0, [r5, #9]
    ldrb r1, [r5, #9]
    lsls r0, r1, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069b22
    subs r0, r1, #1
    strb r0, [r5, #9]
    subs r0, r2, #1
    strb r0, [r5, #8]
    ldrb r0, [r5, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069be4
lbl_08069b22:
    strb r3, [r5, #8]
    b lbl_08069be4
lbl_08069b26:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    strb r0, [r5, #0xa]
    strb r0, [r5, #9]
    b lbl_08069bb8
lbl_08069b42:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069be4
    adds r0, r7, #1
    b lbl_08069bd6
lbl_08069b5c:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r1, [r5, #9]
    adds r0, r1, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069be4
    adds r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r3, [sp, #0x10]
    adds r0, r0, r3
    b lbl_08069be2
lbl_08069b82:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069be4
    subs r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r0, r0, r1
    b lbl_08069be2
lbl_08069ba8:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08069bce
    strb r1, [r5, #0xa]
    strb r1, [r5, #9]
lbl_08069bb8:
    ldrb r1, [r5, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069d92
lbl_08069bc2:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069bd4
lbl_08069bce:
    subs r0, #1
    strb r0, [r5, #9]
    b lbl_08069be4
lbl_08069bd4:
    subs r0, r7, #1
lbl_08069bd6:
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #0x10]
    adds r0, r0, r2
lbl_08069be2:
    ldr r6, [r0]
lbl_08069be4:
    ldrb r0, [r5, #8]
    adds r0, #1
    strb r0, [r5, #8]
    ldrb r1, [r5, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069bf6
    b lbl_08069d92
lbl_08069bf6:
    ldrb r0, [r5, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_08069c18
    ldr r0, lbl_08069c10 @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c14 @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c10: .4byte gBG0HOFS_NonGameplay
lbl_08069c14: .4byte gBG0VOFS_NonGameplay
lbl_08069c18:
    cmp r1, #1
    bne lbl_08069c34
    ldr r0, lbl_08069c2c @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c30 @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c2c: .4byte gBG1HOFS_NonGameplay
lbl_08069c30: .4byte gBG1VOFS_NonGameplay
lbl_08069c34:
    cmp r1, #2
    bne lbl_08069c50
    ldr r0, lbl_08069c48 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c4c @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c48: .4byte gBG2HOFS_NonGameplay
lbl_08069c4c: .4byte gBG2VOFS_NonGameplay
lbl_08069c50:
    cmp r1, #3
    bne lbl_08069c6c
    ldr r0, lbl_08069c64 @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069c68 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_08069c72
    .align 2, 0
lbl_08069c64: .4byte gBG3HOFS_NonGameplay
lbl_08069c68: .4byte gBG3VOFS_NonGameplay
lbl_08069c6c:
    movs r3, #0
    mov r8, r3
    movs r7, #0
lbl_08069c72:
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_08069d0c @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrh r0, [r5, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    mov r2, r8
    asrs r1, r2, #2
    subs r0, r0, r1
    ldr r1, lbl_08069d10 @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r0
    mov r8, r1
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r6, r6, r0
    ldr r4, [r6]
    ldrh r0, [r4]
    ldr r3, [sp, #0x14]
    adds r0, r3, r0
    cmp r0, #0x7f
    bgt lbl_08069da2
    str r0, [sp, #0x14]
    adds r4, #2
    cmp sl, r0
    bge lbl_08069d92
    ldr r1, lbl_08069d14 @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r6, r0, r1
lbl_08069cc0:
    ldrb r1, [r5, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08069d20
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    movs r0, #2
    add sb, r0
    ldrh r2, [r4]
    adds r4, #2
    mov r1, sb
    strh r2, [r1]
    add sb, r0
    ldrh r0, [r4]
    mov r2, sb
    strh r0, [r2]
    adds r4, #2
    movs r3, #4
    add sb, r3
    ldr r0, lbl_08069d18 @ =gCurrentOamRotation
    ldrh r3, [r0]
    ldr r0, lbl_08069d1c @ =gCurrentOamScaling
    ldrh r0, [r0]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, sl
    mov r1, r8
    adds r2, r7, #0
    bl ProcessComplexOam
    b lbl_08069d58
    .align 2, 0
lbl_08069d0c: .4byte gOamYOffset_NonGameplay
lbl_08069d10: .4byte gOamXOffset_NonGameplay
lbl_08069d14: .4byte gOamData
lbl_08069d18: .4byte gCurrentOamRotation
lbl_08069d1c: .4byte gCurrentOamScaling
lbl_08069d20:
    ldrh r2, [r4]
    adds r4, #2
    mov r0, sb
    strh r2, [r0]
    movs r1, #2
    add sb, r1
    adds r0, r2, r7
    strb r0, [r6]
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    add sb, r1
    add r2, r8
    ldr r0, lbl_08069dbc @ =0x000001ff
    ands r2, r0
    ldrh r0, [r6, #2]
    ldr r3, lbl_08069dc0 @ =0xfffffe00
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r6, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    movs r2, #4
    add sb, r2
lbl_08069d58:
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    movs r3, #3
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #5]
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #1]
    adds r6, #8
    movs r0, #1
    add sl, r0
    ldr r1, [sp, #0x14]
    cmp sl, r1
    blt lbl_08069cc0
lbl_08069d92:
    ldr r2, [sp, #0x18]
    adds r2, #1
    str r2, [sp, #0x18]
    adds r5, #0x10
    ldr r3, [sp, #0xc]
    cmp r2, r3
    bge lbl_08069da2
    b lbl_08069a42
lbl_08069da2:
    ldr r0, lbl_08069dc4 @ =gNextOamSlot
    mov r1, sp
    ldrb r1, [r1, #0x14]
    strb r1, [r0]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08069dbc: .4byte 0x000001ff
lbl_08069dc0: .4byte 0xfffffe00
lbl_08069dc4: .4byte gNextOamSlot

    thumb_func_start process_cutscene_oam
process_cutscene_oam: @ 0x08069dc8
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x1c
    adds r5, r1, #0
    str r2, [sp, #0x10]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0xc]
    ldr r0, lbl_08069e5c @ =gOamData
    mov sb, r0
    ldr r0, lbl_08069e60 @ =gNextOamSlot
    ldrb r0, [r0]
    str r0, [sp, #0x14]
    mov sl, r0
    lsls r0, r0, #3
    add sb, r0
    movs r1, #0
    str r1, [sp, #0x18]
    ldr r2, [sp, #0xc]
    cmp r1, r2
    blt lbl_08069dfa
    b lbl_0806a15a
lbl_08069dfa:
    ldrb r0, [r5, #0xa]
    adds r7, r0, #0
    cmp r7, #0
    bne lbl_08069e04
    b lbl_0806a14a
lbl_08069e04:
    ldrb r1, [r5, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    bne lbl_08069e10
    b lbl_0806a14a
lbl_08069e10:
    cmp r0, #0x80
    bne lbl_08069e24
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r5, #0xb]
    movs r0, #0
    strb r0, [r5, #8]
    strb r0, [r5, #9]
lbl_08069e24:
    ldrb r1, [r5, #0xb]
    movs r0, #0x11
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r5, #0xb]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r3, r0, r1
    ldr r6, [r3]
    ldrb r2, [r5, #9]
    lsls r0, r2, #3
    adds r0, r0, r6
    ldrb r1, [r5, #8]
    adds r4, r2, #0
    ldrb r0, [r0, #4]
    cmp r1, r0
    bhs lbl_08069e4a
    b lbl_08069f9c
lbl_08069e4a:
    ldrb r0, [r3, #4]
    cmp r0, #9
    bls lbl_08069e52
    b lbl_08069f9c
lbl_08069e52:
    lsls r0, r0, #2
    ldr r1, lbl_08069e64 @ =lbl_08069e68
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08069e5c: .4byte gOamData
lbl_08069e60: .4byte gNextOamSlot
lbl_08069e64: .4byte lbl_08069e68
lbl_08069e68: @ jump table
    .4byte lbl_08069f9c @ case 0
    .4byte lbl_08069e90 @ case 1
    .4byte lbl_08069eaa @ case 2
    .4byte lbl_08069eb0 @ case 3
    .4byte lbl_08069ede @ case 4
    .4byte lbl_08069efa @ case 5
    .4byte lbl_08069f14 @ case 6
    .4byte lbl_08069f3a @ case 7
    .4byte lbl_08069f60 @ case 8
    .4byte lbl_08069f7a @ case 9
lbl_08069e90:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    strb r0, [r5, #9]
    b lbl_08069f9c
lbl_08069eaa:
    movs r0, #0
    strb r0, [r5, #8]
    b lbl_08069f9c
lbl_08069eb0:
    lsls r0, r4, #3
    adds r0, r0, r6
    ldrb r2, [r0, #4]
    adds r0, r4, #1
    movs r3, #0
    strb r0, [r5, #9]
    ldrb r1, [r5, #9]
    lsls r0, r1, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069eda
    subs r0, r1, #1
    strb r0, [r5, #9]
    subs r0, r2, #1
    strb r0, [r5, #8]
    ldrb r0, [r5, #0xb]
    movs r1, #0x10
    orrs r0, r1
    strb r0, [r5, #0xb]
    b lbl_08069f9c
lbl_08069eda:
    strb r3, [r5, #8]
    b lbl_08069f9c
lbl_08069ede:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    strb r0, [r5, #0xa]
    strb r0, [r5, #9]
    b lbl_08069f70
lbl_08069efa:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069f9c
    adds r0, r7, #1
    b lbl_08069f8e
lbl_08069f14:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r1, [r5, #9]
    adds r0, r1, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #4]
    cmp r0, #0
    bne lbl_08069f9c
    adds r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r3, [sp, #0x10]
    adds r0, r0, r3
    b lbl_08069f9a
lbl_08069f3a:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r0, #1
    strb r0, [r5, #9]
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r1, [r0, #4]
    cmp r1, #0
    bne lbl_08069f9c
    subs r0, r7, #1
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r1, [sp, #0x10]
    adds r0, r0, r1
    b lbl_08069f9a
lbl_08069f60:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    bne lbl_08069f86
    strb r1, [r5, #0xa]
    strb r1, [r5, #9]
lbl_08069f70:
    ldrb r1, [r5, #0xb]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r5, #0xb]
    b lbl_0806a14a
lbl_08069f7a:
    movs r0, #0
    strb r0, [r5, #8]
    ldrb r0, [r5, #9]
    adds r1, r0, #0
    cmp r1, #0
    beq lbl_08069f8c
lbl_08069f86:
    subs r0, #1
    strb r0, [r5, #9]
    b lbl_08069f9c
lbl_08069f8c:
    subs r0, r7, #1
lbl_08069f8e:
    strb r0, [r5, #0xa]
    strb r1, [r5, #9]
    ldrb r0, [r5, #0xa]
    lsls r0, r0, #3
    ldr r2, [sp, #0x10]
    adds r0, r0, r2
lbl_08069f9a:
    ldr r6, [r0]
lbl_08069f9c:
    ldrb r0, [r5, #8]
    adds r0, #1
    strb r0, [r5, #8]
    ldrb r1, [r5, #0xb]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08069fae
    b lbl_0806a14a
lbl_08069fae:
    ldrb r0, [r5, #0xc]
    movs r1, #0xf
    ands r1, r0
    cmp r1, #0
    bne lbl_08069fd0
    ldr r0, lbl_08069fc8 @ =gBG0HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069fcc @ =gBG0VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_08069fc8: .4byte gBG0HOFS_NonGameplay
lbl_08069fcc: .4byte gBG0VOFS_NonGameplay
lbl_08069fd0:
    cmp r1, #1
    bne lbl_08069fec
    ldr r0, lbl_08069fe4 @ =gBG1HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_08069fe8 @ =gBG1VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_08069fe4: .4byte gBG1HOFS_NonGameplay
lbl_08069fe8: .4byte gBG1VOFS_NonGameplay
lbl_08069fec:
    cmp r1, #2
    bne lbl_0806a008
    ldr r0, lbl_0806a000 @ =gBG2HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_0806a004 @ =gBG2VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_0806a000: .4byte gBG2HOFS_NonGameplay
lbl_0806a004: .4byte gBG2VOFS_NonGameplay
lbl_0806a008:
    cmp r1, #3
    bne lbl_0806a024
    ldr r0, lbl_0806a01c @ =gBG3HOFS_NonGameplay
    movs r1, #0
    ldrsh r3, [r0, r1]
    mov r8, r3
    ldr r0, lbl_0806a020 @ =gBG3VOFS_NonGameplay
    movs r2, #0
    ldrsh r7, [r0, r2]
    b lbl_0806a02a
    .align 2, 0
lbl_0806a01c: .4byte gBG3HOFS_NonGameplay
lbl_0806a020: .4byte gBG3VOFS_NonGameplay
lbl_0806a024:
    movs r3, #0
    mov r8, r3
    movs r7, #0
lbl_0806a02a:
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    asrs r1, r7, #2
    subs r0, r0, r1
    ldr r1, lbl_0806a0c4 @ =gOamYOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r7, r1, r0
    ldrh r0, [r5, #2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    mov r2, r8
    asrs r1, r2, #2
    subs r0, r0, r1
    ldr r1, lbl_0806a0c8 @ =gOamXOffset_NonGameplay
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r0
    mov r8, r1
    ldrb r0, [r5, #9]
    lsls r0, r0, #3
    adds r6, r6, r0
    ldr r4, [r6]
    ldrh r0, [r4]
    ldr r3, [sp, #0x14]
    adds r0, r3, r0
    cmp r0, #0x7f
    bgt lbl_0806a15a
    str r0, [sp, #0x14]
    adds r4, #2
    cmp sl, r0
    bge lbl_0806a14a
    ldr r1, lbl_0806a0cc @ =gOamData
    mov r2, sl
    lsls r0, r2, #3
    adds r6, r0, r1
lbl_0806a078:
    ldrb r1, [r5, #0xc]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a0d8
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    movs r0, #2
    add sb, r0
    ldrh r2, [r4]
    adds r4, #2
    mov r1, sb
    strh r2, [r1]
    add sb, r0
    ldrh r0, [r4]
    mov r2, sb
    strh r0, [r2]
    adds r4, #2
    movs r3, #4
    add sb, r3
    ldr r0, lbl_0806a0d0 @ =gCurrentOamRotation
    ldrh r3, [r0]
    ldr r0, lbl_0806a0d4 @ =gCurrentOamScaling
    ldrh r0, [r0]
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, sl
    mov r1, r8
    adds r2, r7, #0
    bl ProcessComplexOam
    b lbl_0806a110
    .align 2, 0
lbl_0806a0c4: .4byte gOamYOffset_NonGameplay
lbl_0806a0c8: .4byte gOamXOffset_NonGameplay
lbl_0806a0cc: .4byte gOamData
lbl_0806a0d0: .4byte gCurrentOamRotation
lbl_0806a0d4: .4byte gCurrentOamScaling
lbl_0806a0d8:
    ldrh r2, [r4]
    adds r4, #2
    mov r0, sb
    strh r2, [r0]
    movs r1, #2
    add sb, r1
    adds r0, r2, r7
    strb r0, [r6]
    ldrh r2, [r4]
    adds r4, #2
    mov r3, sb
    strh r2, [r3]
    add sb, r1
    add r2, r8
    ldr r0, lbl_0806a174 @ =0x000001ff
    ands r2, r0
    ldrh r0, [r6, #2]
    ldr r3, lbl_0806a178 @ =0xfffffe00
    adds r1, r3, #0
    ands r0, r1
    orrs r0, r2
    strh r0, [r6, #2]
    ldrh r0, [r4]
    mov r1, sb
    strh r0, [r1]
    adds r4, #2
    movs r2, #4
    add sb, r2
lbl_0806a110:
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1e
    lsrs r1, r1, #0x1e
    movs r3, #3
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #5]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #5]
    ldrb r1, [r5, #0xb]
    lsls r1, r1, #0x1c
    lsrs r1, r1, #0x1e
    ands r1, r3
    lsls r1, r1, #2
    ldrb r2, [r6, #1]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r2
    orrs r0, r1
    strb r0, [r6, #1]
    adds r6, #8
    movs r0, #1
    add sl, r0
    ldr r1, [sp, #0x14]
    cmp sl, r1
    blt lbl_0806a078
lbl_0806a14a:
    ldr r2, [sp, #0x18]
    adds r2, #1
    str r2, [sp, #0x18]
    adds r5, #0x20
    ldr r3, [sp, #0xc]
    cmp r2, r3
    bge lbl_0806a15a
    b lbl_08069dfa
lbl_0806a15a:
    ldr r0, lbl_0806a17c @ =gNextOamSlot
    mov r1, sp
    ldrb r1, [r1, #0x14]
    strb r1, [r0]
    add sp, #0x1c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806a174: .4byte 0x000001ff
lbl_0806a178: .4byte 0xfffffe00
lbl_0806a17c: .4byte gNextOamSlot

    thumb_func_start map_screen_main
map_screen_main: @ 0x0806a180
    push {r4, lr}
    movs r4, #0
    ldr r0, lbl_0806a19c @ =gSubGameModeStage
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #8
    bls lbl_0806a190
    b lbl_0806a2ee
lbl_0806a190:
    lsls r0, r1, #2
    ldr r1, lbl_0806a1a0 @ =lbl_0806a1a4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806a19c: .4byte gSubGameModeStage
lbl_0806a1a0: .4byte lbl_0806a1a4
lbl_0806a1a4: @ jump table
    .4byte lbl_0806a1c8 @ case 0
    .4byte lbl_0806a248 @ case 1
    .4byte lbl_0806a1f6 @ case 2
    .4byte lbl_0806a248 @ case 3
    .4byte lbl_0806a234 @ case 4
    .4byte lbl_0806a248 @ case 5
    .4byte lbl_0806a260 @ case 6
    .4byte lbl_0806a248 @ case 7
    .4byte lbl_0806a2e8 @ case 8
lbl_0806a1c8:
    ldr r0, lbl_0806a1e0 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806a1ec
    ldr r2, lbl_0806a1e4 @ =gButtonInput
    ldr r1, lbl_0806a1e8 @ =gChangedInput
    movs r0, #0
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #5
    b lbl_0806a1ee
    .align 2, 0
lbl_0806a1e0: .4byte gDemoState
lbl_0806a1e4: .4byte gButtonInput
lbl_0806a1e8: .4byte gChangedInput
lbl_0806a1ec:
    movs r0, #1
lbl_0806a1ee:
    strb r0, [r3]
    bl map_screen_init
    b lbl_0806a2ee
lbl_0806a1f6:
    movs r0, #0
    bl sub_080682ec
    bl sub_0806b240
    cmp r0, #0
    beq lbl_0806a212
    movs r0, #4
    bl sub_080682ec
    ldr r1, lbl_0806a22c @ =gSubGameModeStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806a212:
    ldr r0, lbl_0806a230 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806a222
    bl update_minimap_anim_palette
lbl_0806a222:
    bl sub_08068694
    bl sub_080695bc
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a22c: .4byte gSubGameModeStage
lbl_0806a230: .4byte 0x08754bc4
lbl_0806a234:
    movs r0, #0
    strb r0, [r3]
    ldr r1, lbl_0806a244 @ =gGameModeSub2
    movs r0, #4
    strb r0, [r1]
    movs r4, #1
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a244: .4byte gGameModeSub2
lbl_0806a248:
    movs r0, #0
    bl sub_080682ec
    cmp r0, #0
    beq lbl_0806a2ee
    ldr r1, lbl_0806a25c @ =gSubGameModeStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a25c: .4byte gSubGameModeStage
lbl_0806a260:
    movs r0, #0
    bl sub_080682ec
    ldr r2, lbl_0806a288 @ =gButtonInput
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_0806a294
    ldr r2, lbl_0806a28c @ =gCurrentDemo
    ldrb r1, [r2, #3]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #3]
    bl end_demo
    ldr r1, lbl_0806a290 @ =gPauseScreenFlag
    movs r0, #9
    b lbl_0806a2a6
    .align 2, 0
lbl_0806a288: .4byte gButtonInput
lbl_0806a28c: .4byte gCurrentDemo
lbl_0806a290: .4byte gPauseScreenFlag
lbl_0806a294:
    ldr r0, lbl_0806a2d8 @ =gChangedInput
    strh r1, [r0]
    strh r1, [r2]
    bl sub_0806b240
    cmp r0, #0
    beq lbl_0806a2b0
    ldr r1, lbl_0806a2dc @ =gGameModeSub2
    movs r0, #0xb
lbl_0806a2a6:
    strb r0, [r1]
    movs r4, #1
    ldr r1, lbl_0806a2e0 @ =gSubGameModeStage
    movs r0, #7
    strb r0, [r1]
lbl_0806a2b0:
    cmp r4, #0
    beq lbl_0806a2ba
    movs r0, #4
    bl sub_080682ec
lbl_0806a2ba:
    ldr r0, lbl_0806a2e4 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbc
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806a2ca
    bl update_minimap_anim_palette
lbl_0806a2ca:
    bl sub_08068694
    bl sub_080695bc
    movs r4, #0
    b lbl_0806a2ee
    .align 2, 0
lbl_0806a2d8: .4byte gChangedInput
lbl_0806a2dc: .4byte gGameModeSub2
lbl_0806a2e0: .4byte gSubGameModeStage
lbl_0806a2e4: .4byte 0x08754bc4
lbl_0806a2e8:
    movs r4, #1
    movs r0, #0
    strb r0, [r3]
lbl_0806a2ee:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806a2f8
sub_0806a2f8: @ 0x0806a2f8
    push {r4, lr}
    ldr r1, lbl_0806a3d8 @ =0x040000d4
    ldr r0, lbl_0806a3dc @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806a3e0 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    subs r1, #0xd4
    ldr r0, lbl_0806a3e4 @ =0x08754bc4
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x5c
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #0x54
    ldr r0, lbl_0806a3e8 @ =gWrittenToBLDY_NonGameplay
    ldrh r0, [r0]
    strh r0, [r1]
    subs r1, #8
    ldr r0, lbl_0806a3ec @ =gWrittenToMOSAIC_L
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_0806a3f0 @ =0x04000010
    ldr r0, lbl_0806a3f4 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldr r4, lbl_0806a3f8 @ =0x000001ff
    adds r1, r4, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a3fc @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a400 @ =gBG1HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a404 @ =gBG1VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a408 @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a40c @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a410 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806a414 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0806a418 @ =0x04000008
    adds r0, r3, #0
    adds r0, #0x5e
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x60
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x62
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r3, #0
    adds r0, #0x64
    ldrh r0, [r0]
    strh r0, [r1]
    adds r2, #0x34
    ldr r0, lbl_0806a41c @ =gWrittenToBLDALPHA_H
    ldrh r0, [r0]
    lsls r0, r0, #8
    ldr r1, lbl_0806a420 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0806a424 @ =0x04000050
    adds r0, r3, #0
    adds r0, #0x66
    ldrh r0, [r0]
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806a3d8: .4byte 0x040000d4
lbl_0806a3dc: .4byte gOamData
lbl_0806a3e0: .4byte 0x84000100
lbl_0806a3e4: .4byte 0x08754bc4
lbl_0806a3e8: .4byte gWrittenToBLDY_NonGameplay
lbl_0806a3ec: .4byte gWrittenToMOSAIC_L
lbl_0806a3f0: .4byte 0x04000010
lbl_0806a3f4: .4byte gBG0HOFS_NonGameplay
lbl_0806a3f8: .4byte 0x000001ff
lbl_0806a3fc: .4byte gBG0VOFS_NonGameplay
lbl_0806a400: .4byte gBG1HOFS_NonGameplay
lbl_0806a404: .4byte gBG1VOFS_NonGameplay
lbl_0806a408: .4byte gBG2HOFS_NonGameplay
lbl_0806a40c: .4byte gBG2VOFS_NonGameplay
lbl_0806a410: .4byte gBG3HOFS_NonGameplay
lbl_0806a414: .4byte gBG3VOFS_NonGameplay
lbl_0806a418: .4byte 0x04000008
lbl_0806a41c: .4byte gWrittenToBLDALPHA_H
lbl_0806a420: .4byte gWrittenToBLDALPHA_L
lbl_0806a424: .4byte 0x04000050

    thumb_func_start sub_0806a428
sub_0806a428: @ 0x0806a428
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr

    thumb_func_start map_screen_init
map_screen_init: @ 0x0806a434
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r0, lbl_0806a4f0 @ =sub_0806a428
    bl CallbackSetVBlank
    ldr r1, lbl_0806a4f4 @ =0x04000050
    movs r0, #0xff
    strh r0, [r1]
    ldr r2, lbl_0806a4f8 @ =0x04000054
    ldr r1, lbl_0806a4fc @ =gWrittenToBLDY_NonGameplay
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x13
    movs r1, #0
    strh r1, [r0]
    ldr r0, lbl_0806a500 @ =gNextOamSlot
    strb r1, [r0]
    ldr r2, lbl_0806a504 @ =gNonGameplayRAM
    movs r3, #0xc5
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    bl ResetFreeOAM
    ldr r1, lbl_0806a508 @ =0x040000d4
    ldr r0, lbl_0806a50c @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806a510 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r4, lbl_0806a514 @ =0x08754bc4
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x66
    movs r5, #0
    movs r0, #0xff
    strh r0, [r2]
    adds r1, #0x5c
    strh r5, [r1]
    ldr r0, lbl_0806a518 @ =gCurrentCutscene
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0806a4ba
    ldr r1, lbl_0806a51c @ =0x06010000
    ldr r2, lbl_0806a520 @ =0x0201e000
    movs r3, #0x80
    lsls r3, r3, #8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806a4ba:
    ldr r1, [r4]
    ldr r0, lbl_0806a524 @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r1, #0x12]
    ldr r1, [r4]
    ldr r0, lbl_0806a528 @ =gMinimapX
    ldrb r0, [r0]
    strb r0, [r1, #0x13]
    ldr r1, [r4]
    ldr r0, lbl_0806a52c @ =gMinimapY
    ldrb r0, [r0]
    strb r0, [r1, #0x14]
    ldr r0, [r4]
    strh r5, [r0]
    ldr r0, lbl_0806a530 @ =gPauseScreenFlag
    ldrb r0, [r0]
    subs r0, #3
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    bls lbl_0806a4e6
    b lbl_0806a5dc
lbl_0806a4e6:
    lsls r0, r0, #2
    ldr r1, lbl_0806a534 @ =lbl_0806a538
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806a4f0: .4byte sub_0806a428
lbl_0806a4f4: .4byte 0x04000050
lbl_0806a4f8: .4byte 0x04000054
lbl_0806a4fc: .4byte gWrittenToBLDY_NonGameplay
lbl_0806a500: .4byte gNextOamSlot
lbl_0806a504: .4byte gNonGameplayRAM
lbl_0806a508: .4byte 0x040000d4
lbl_0806a50c: .4byte gOamData
lbl_0806a510: .4byte 0x84000100
lbl_0806a514: .4byte 0x08754bc4
lbl_0806a518: .4byte gCurrentCutscene
lbl_0806a51c: .4byte 0x06010000
lbl_0806a520: .4byte 0x0201e000
lbl_0806a524: .4byte gCurrentArea
lbl_0806a528: .4byte gMinimapX
lbl_0806a52c: .4byte gMinimapY
lbl_0806a530: .4byte gPauseScreenFlag
lbl_0806a534: .4byte lbl_0806a538
lbl_0806a538: @ jump table
    .4byte lbl_0806a560 @ case 0
    .4byte lbl_0806a550 @ case 1
    .4byte lbl_0806a570 @ case 2
    .4byte lbl_0806a580 @ case 3
    .4byte lbl_0806a598 @ case 4
    .4byte lbl_0806a5cc @ case 5
lbl_0806a550:
    ldr r0, lbl_0806a55c @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x12
    b lbl_0806a58c
    .align 2, 0
lbl_0806a55c: .4byte 0x08754bc4
lbl_0806a560:
    ldr r0, lbl_0806a56c @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #8
    b lbl_0806a58c
    .align 2, 0
lbl_0806a56c: .4byte 0x08754bc4
lbl_0806a570:
    ldr r0, lbl_0806a57c @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x22
    b lbl_0806a58c
    .align 2, 0
lbl_0806a57c: .4byte 0x08754bc4
lbl_0806a580:
    ldr r0, lbl_0806a594 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r3, #0xc0
    lsls r3, r3, #1
    adds r0, r3, #0
lbl_0806a58c:
    orrs r0, r1
    strh r0, [r2]
    b lbl_0806a5dc
    .align 2, 0
lbl_0806a594: .4byte 0x08754bc4
lbl_0806a598:
    movs r0, #2
    bl update_suitType
    ldr r1, lbl_0806a5c0 @ =gSamusData
    movs r3, #0
    movs r0, #0x1e
    strb r0, [r1]
    movs r2, #0
    movs r0, #0x20
    strh r0, [r1, #0xe]
    strb r2, [r1, #0x1d]
    strh r3, [r1, #0xc]
    ldr r1, lbl_0806a5c4 @ =gCurrentItemBeingAcquired
    movs r0, #8
    strb r0, [r1]
    ldr r0, lbl_0806a5c8 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0xe0
    lsls r0, r0, #2
    b lbl_0806a5da
    .align 2, 0
lbl_0806a5c0: .4byte gSamusData
lbl_0806a5c4: .4byte gCurrentItemBeingAcquired
lbl_0806a5c8: .4byte 0x08754bc4
lbl_0806a5cc:
    movs r0, #1
    bl update_suitType
    ldr r0, lbl_0806a698 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0xb0
    lsls r0, r0, #3
lbl_0806a5da:
    strh r0, [r1]
lbl_0806a5dc:
    ldr r1, lbl_0806a69c @ =0x083fd050
    ldr r2, lbl_0806a6a0 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806a6a4 @ =0x08411360
    movs r2, #0xa0
    lsls r2, r2, #0x13
    str r4, [sp]
    movs r0, #3
    movs r3, #0xa0
    bl DMATransfer
    ldr r1, lbl_0806a6a8 @ =0x083fcef0
    ldr r2, lbl_0806a6ac @ =0x050000a0
    movs r3, #0xb0
    lsls r3, r3, #1
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_0806a6b0 @ =0x08754bb8
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0806a6b4 @ =0x0840e0c4
    ldr r2, lbl_0806a6b8 @ =0x06008000
    movs r3, #0xc0
    lsls r3, r3, #6
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806a6bc @ =0x0600a820
    ldr r2, lbl_0806a6c0 @ =0x0600ac20
    movs r3, #0xf8
    lsls r3, r3, #2
    movs r6, #0x20
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_0806a6c4 @ =0x08400e08
    ldr r1, lbl_0806a6c8 @ =0x06013000
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6cc @ =0x08760104
    ldr r5, lbl_0806a6d0 @ =gLanguage
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6d4 @ =0x06010800
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6d8 @ =0x0876013c
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6dc @ =0x06011400
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a6e0 @ =0x08760120
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a6e4 @ =0x06011800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a698 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r0, [r0]
    ands r4, r0
    cmp r4, #0
    beq lbl_0806a6f4
    ldr r0, lbl_0806a6e8 @ =0x084030b4
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a6ec @ =0x084110c4
    ldr r1, lbl_0806a6f0 @ =0x0600a800
    bl CallLZ77UncompVRAM
    b lbl_0806a744
    .align 2, 0
lbl_0806a698: .4byte 0x08754bc4
lbl_0806a69c: .4byte 0x083fd050
lbl_0806a6a0: .4byte 0x05000200
lbl_0806a6a4: .4byte 0x08411360
lbl_0806a6a8: .4byte 0x083fcef0
lbl_0806a6ac: .4byte 0x050000a0
lbl_0806a6b0: .4byte 0x08754bb8
lbl_0806a6b4: .4byte 0x0840e0c4
lbl_0806a6b8: .4byte 0x06008000
lbl_0806a6bc: .4byte 0x0600a820
lbl_0806a6c0: .4byte 0x0600ac20
lbl_0806a6c4: .4byte 0x08400e08
lbl_0806a6c8: .4byte 0x06013000
lbl_0806a6cc: .4byte 0x08760104
lbl_0806a6d0: .4byte gLanguage
lbl_0806a6d4: .4byte 0x06010800
lbl_0806a6d8: .4byte 0x0876013c
lbl_0806a6dc: .4byte 0x06011400
lbl_0806a6e0: .4byte 0x08760120
lbl_0806a6e4: .4byte 0x06011800
lbl_0806a6e8: .4byte 0x084030b4
lbl_0806a6ec: .4byte 0x084110c4
lbl_0806a6f0: .4byte 0x0600a800
lbl_0806a6f4:
    ldr r0, lbl_0806a794 @ =0x083feb60
    movs r1, #0xc0
    lsls r1, r1, #0x13
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a798 @ =0x083fefb8
    ldr r1, lbl_0806a79c @ =0x06001000
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a7a0 @ =0x084005a8
    ldr r1, lbl_0806a7a4 @ =0x06007400
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7a8 @ =0x08760158
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r4, lbl_0806a7ac @ =0x06006000
    adds r1, r4, #0
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7b0 @ =0x08760174
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    ldr r1, lbl_0806a7b4 @ =0x06000c00
    bl CallLZ77UncompVRAM
    ldr r2, lbl_0806a7b8 @ =0x06010000
    movs r3, #0x80
    lsls r3, r3, #4
    str r6, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl DMATransfer
lbl_0806a744:
    movs r1, #0x8a
    lsls r1, r1, #5
    ldr r2, lbl_0806a7bc @ =0x0600e800
    movs r3, #0xc0
    lsls r3, r3, #5
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    bl BitFill
    ldr r1, lbl_0806a7c0 @ =0x02034000
    ldr r2, lbl_0806a7c4 @ =0x0600e000
    movs r7, #0x80
    lsls r7, r7, #4
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl DMATransfer
    ldr r5, lbl_0806a7c8 @ =0x08754bc4
    mov r8, r5
    ldr r0, [r5]
    ldrh r1, [r0]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a7dc
    ldr r0, lbl_0806a7cc @ =0x08408e00
    ldr r1, lbl_0806a7d0 @ =0x0600b800
    bl CallLZ77UncompVRAM
    ldr r1, lbl_0806a7d4 @ =0x0000115f
    ldr r2, lbl_0806a7d8 @ =0x0600c000
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl BitFill
    b lbl_0806a8f6
    .align 2, 0
lbl_0806a794: .4byte 0x083feb60
lbl_0806a798: .4byte 0x083fefb8
lbl_0806a79c: .4byte 0x06001000
lbl_0806a7a0: .4byte 0x084005a8
lbl_0806a7a4: .4byte 0x06007400
lbl_0806a7a8: .4byte 0x08760158
lbl_0806a7ac: .4byte 0x06006000
lbl_0806a7b0: .4byte 0x08760174
lbl_0806a7b4: .4byte 0x06000c00
lbl_0806a7b8: .4byte 0x06010000
lbl_0806a7bc: .4byte 0x0600e800
lbl_0806a7c0: .4byte 0x02034000
lbl_0806a7c4: .4byte 0x0600e000
lbl_0806a7c8: .4byte 0x08754bc4
lbl_0806a7cc: .4byte 0x08408e00
lbl_0806a7d0: .4byte 0x0600b800
lbl_0806a7d4: .4byte 0x0000115f
lbl_0806a7d8: .4byte 0x0600c000
lbl_0806a7dc:
    ldr r0, lbl_0806a81c @ =0x08407ba8
    ldr r5, lbl_0806a820 @ =0x08754bb4
    ldr r1, [r5]
    movs r4, #0x90
    lsls r4, r4, #8
    adds r1, r1, r4
    bl CallLZ77UncompWRAM
    ldr r1, [r5]
    adds r1, r1, r4
    ldr r2, lbl_0806a824 @ =0x0600c800
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl DMATransfer
    movs r0, #2
    movs r1, #2
    bl sub_0806b00c
    mov r1, r8
    ldr r0, [r1]
    ldrh r1, [r0]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a828
    movs r0, #0xff
    bl sub_0806b718
    b lbl_0806a8f6
    .align 2, 0
lbl_0806a81c: .4byte 0x08407ba8
lbl_0806a820: .4byte 0x08754bb4
lbl_0806a824: .4byte 0x0600c800
lbl_0806a828:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a84e
    ldr r0, lbl_0806a88c @ =0x084078ec
    ldr r1, lbl_0806a890 @ =0x0600b000
    bl CallLZ77UncompVRAM
    movs r1, #0xf0
    lsls r1, r1, #8
    ldr r2, [r5]
    movs r3, #0xd0
    lsls r3, r3, #8
    adds r2, r2, r3
    str r6, [sp]
    movs r0, #3
    adds r3, r7, #0
    bl BitFill
lbl_0806a84e:
    ldr r0, lbl_0806a894 @ =0x084082bc
    ldr r1, [r5]
    movs r2, #0xf0
    lsls r2, r2, #7
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a898 @ =0x084089ec
    ldr r1, [r5]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r1, r3
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a89c @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0806a8a4
    ldr r1, [r5]
    movs r5, #0x80
    lsls r5, r5, #8
    adds r1, r1, r5
    ldr r2, lbl_0806a8a0 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806a8ba
    .align 2, 0
lbl_0806a88c: .4byte 0x084078ec
lbl_0806a890: .4byte 0x0600b000
lbl_0806a894: .4byte 0x084082bc
lbl_0806a898: .4byte 0x084089ec
lbl_0806a89c: .4byte gEquipment
lbl_0806a8a0: .4byte 0x0600c000
lbl_0806a8a4:
    ldr r1, [r5]
    movs r0, #0xf0
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806a948 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    str r6, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806a8ba:
    ldr r0, lbl_0806a94c @ =0x08407d90
    ldr r4, lbl_0806a950 @ =0x08754bb4
    ldr r1, [r4]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r1, r1, r2
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a954 @ =0x08407f84
    ldr r1, [r4]
    movs r3, #0xa0
    lsls r3, r3, #8
    adds r1, r1, r3
    bl CallLZ77UncompWRAM
    ldr r0, lbl_0806a958 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strb r0, [r1, #0x11]
    ldr r0, lbl_0806a95c @ =0x08408c90
    ldr r1, lbl_0806a960 @ =0x0600d800
    bl CallLZ77UncompVRAM
    ldr r0, lbl_0806a964 @ =0x084086dc
    ldr r1, [r4]
    movs r5, #0x88
    lsls r5, r5, #8
    adds r1, r1, r5
    bl CallLZ77UncompWRAM
lbl_0806a8f6:
    ldr r2, lbl_0806a968 @ =gBG0HOFS_NonGameplay
    ldr r0, lbl_0806a96c @ =gBG0VOFS_NonGameplay
    movs r1, #0
    strh r1, [r0]
    strh r1, [r2]
    ldr r0, lbl_0806a970 @ =gBG1HOFS_NonGameplay
    ldr r4, lbl_0806a974 @ =gBG1VOFS_NonGameplay
    strh r1, [r4]
    strh r1, [r0]
    ldr r2, lbl_0806a978 @ =gBG2HOFS_NonGameplay
    ldr r0, lbl_0806a97c @ =gBG2VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806a980 @ =gBG3HOFS_NonGameplay
    ldr r0, lbl_0806a984 @ =gBG3VOFS_NonGameplay
    strh r1, [r0]
    strh r1, [r2]
    ldr r2, lbl_0806a958 @ =0x08754bc4
    ldr r0, [r2]
    movs r3, #0
    strb r1, [r0, #8]
    ldr r1, [r2]
    strh r3, [r1, #0xa]
    adds r1, #4
    ldr r0, lbl_0806a988 @ =0x087600f8
    ldm r0!, {r3, r5, r6}
    stm r1!, {r3, r5, r6}
    movs r6, #0x80
    lsls r6, r6, #3
    adds r5, r6, #0
    strh r5, [r4]
    ldr r3, [r2]
    ldrh r1, [r3]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a98c
    movs r0, #0xf
    strb r0, [r3, #4]
    b lbl_0806a9f2
    .align 2, 0
lbl_0806a948: .4byte 0x0600c000
lbl_0806a94c: .4byte 0x08407d90
lbl_0806a950: .4byte 0x08754bb4
lbl_0806a954: .4byte 0x08407f84
lbl_0806a958: .4byte 0x08754bc4
lbl_0806a95c: .4byte 0x08408c90
lbl_0806a960: .4byte 0x0600d800
lbl_0806a964: .4byte 0x084086dc
lbl_0806a968: .4byte gBG0HOFS_NonGameplay
lbl_0806a96c: .4byte gBG0VOFS_NonGameplay
lbl_0806a970: .4byte gBG1HOFS_NonGameplay
lbl_0806a974: .4byte gBG1VOFS_NonGameplay
lbl_0806a978: .4byte gBG2HOFS_NonGameplay
lbl_0806a97c: .4byte gBG2VOFS_NonGameplay
lbl_0806a980: .4byte gBG3HOFS_NonGameplay
lbl_0806a984: .4byte gBG3VOFS_NonGameplay
lbl_0806a988: .4byte 0x087600f8
lbl_0806a98c:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9cc
    ldr r2, lbl_0806a9c0 @ =gEquipment
    ldr r4, lbl_0806a9c4 @ =gCurrentArea
    movs r0, #1
    ldrb r1, [r4]
    lsls r0, r1
    ldrb r1, [r2, #0x10]
    orrs r0, r1
    strb r0, [r2, #0x10]
    movs r0, #9
    strb r0, [r3, #4]
    ldrb r0, [r4]
    ldr r5, lbl_0806a9c8 @ =0x02034000
    adds r1, r5, #0
    bl get_minimap_data
    ldrb r0, [r4]
    adds r1, r5, #0
    bl minimap_set_downloaded_tiles
    bl sub_0806d334
    b lbl_0806a9f2
    .align 2, 0
lbl_0806a9c0: .4byte gEquipment
lbl_0806a9c4: .4byte gCurrentArea
lbl_0806a9c8: .4byte 0x02034000
lbl_0806a9cc:
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9da
    movs r0, #0x14
    strb r0, [r3, #4]
    b lbl_0806a9f2
lbl_0806a9da:
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806a9f2
    movs r0, #0x13
    strb r0, [r3, #4]
    ldr r0, lbl_0806aa38 @ =gCurrentItemBeingAcquired
    ldrb r1, [r0]
    movs r0, #1
    bl sub_08070020
lbl_0806a9f2:
    movs r0, #0xff
    bl get_all_minimap_data
    ldr r4, lbl_0806aa3c @ =0x08754bc4
    bl draw_status_screen_tanks_amounts
    movs r0, #0
    bl chozo_statue_hint_determine_path
    movs r0, #0
    bl sub_0806db58
    bl sub_0806facc
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806aa40
    adds r0, r2, #0
    adds r0, #0xb8
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xb9
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xba
    strb r1, [r0]
    ldr r0, [r4]
    adds r0, #0xbb
    strb r1, [r0]
    b lbl_0806aa6a
    .align 2, 0
lbl_0806aa38: .4byte gCurrentItemBeingAcquired
lbl_0806aa3c: .4byte 0x08754bc4
lbl_0806aa40:
    bl check_explored_areas
    bl check_non_explored_area_has_hint
    bl determine_maps_viewable
    bl sub_0806fe18
    ldr r0, lbl_0806aac8 @ =0x08754bb4
    ldr r1, [r0]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r1, r1, r2
    ldr r2, lbl_0806aacc @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806aa6a:
    ldr r2, lbl_0806aad0 @ =0x08754bc4
    ldr r0, [r2]
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    mov sl, r2
    ldr r3, lbl_0806aad4 @ =gBG1HOFS_NonGameplay
    mov ip, r3
    ldr r5, lbl_0806aad8 @ =gBG1VOFS_NonGameplay
    mov sb, r5
    cmp r0, #0
    beq lbl_0806aa88
    movs r0, #0x10
    strh r0, [r3]
    strh r0, [r5]
lbl_0806aa88:
    ldr r0, lbl_0806aadc @ =gWrittenToBLDY_NonGameplay
    ldr r2, lbl_0806aae0 @ =gWrittenToBLDALPHA_H
    movs r5, #0
    strh r5, [r2]
    strh r5, [r0]
    ldr r1, lbl_0806aae4 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
    mov r6, sl
    ldr r3, [r6]
    ldrh r4, [r3]
    movs r0, #0x10
    ands r0, r4
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r2, #0
    mov r8, r1
    cmp r6, #0
    beq lbl_0806aaf0
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806aae8 @ =0x00003f42
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0806aaec @ =0x00000709
    strh r0, [r1]
    movs r0, #7
    strh r0, [r7]
    movs r0, #9
    mov r1, r8
    strh r0, [r1]
    b lbl_0806ab30
    .align 2, 0
lbl_0806aac8: .4byte 0x08754bb4
lbl_0806aacc: .4byte 0x0600d000
lbl_0806aad0: .4byte 0x08754bc4
lbl_0806aad4: .4byte gBG1HOFS_NonGameplay
lbl_0806aad8: .4byte gBG1VOFS_NonGameplay
lbl_0806aadc: .4byte gWrittenToBLDY_NonGameplay
lbl_0806aae0: .4byte gWrittenToBLDALPHA_H
lbl_0806aae4: .4byte gWrittenToBLDALPHA_L
lbl_0806aae8: .4byte 0x00003f42
lbl_0806aaec: .4byte 0x00000709
lbl_0806aaf0:
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r4
    cmp r0, #0
    beq lbl_0806ab18
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806ab14 @ =0x00003c44
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0x68
    movs r1, #0x16
    strh r1, [r0]
    strh r6, [r7]
    mov r2, r8
    strh r1, [r2]
    b lbl_0806ab30
    .align 2, 0
lbl_0806ab14: .4byte 0x00003c44
lbl_0806ab18:
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806ac3c @ =0x00003844
    strh r0, [r1]
    adds r1, #2
    ldr r0, lbl_0806ac40 @ =0x0000060a
    strh r0, [r1]
    movs r0, #6
    strh r0, [r7]
    movs r0, #0xa
    mov r3, r8
    strh r0, [r3]
lbl_0806ab30:
    ldr r1, lbl_0806ac44 @ =0x0400004a
    movs r0, #0x3f
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x18
    strb r0, [r1]
    ldr r0, lbl_0806ac48 @ =gWrittenToMOSAIC_L
    movs r6, #0
    strh r6, [r0]
    ldr r2, lbl_0806ac4c @ =0x04000010
    ldr r0, lbl_0806ac50 @ =gBG0HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ldr r5, lbl_0806ac54 @ =0x000001ff
    adds r1, r5, #0
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac58 @ =gBG0VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    mov r3, ip
    ldrh r0, [r3]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    mov r5, sb
    ldrh r0, [r5]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac5c @ =gBG2HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac60 @ =gBG2VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac64 @ =gBG3HOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    adds r2, #2
    ldr r0, lbl_0806ac68 @ =gBG3VOFS_NonGameplay
    ldrh r0, [r0]
    lsrs r0, r0, #2
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_0806ac6c @ =0x0400004c
    strh r6, [r0]
    ldr r1, lbl_0806ac70 @ =0x04000050
    mov r0, sl
    ldr r4, [r0]
    adds r0, r4, #0
    adds r0, #0x66
    ldrh r0, [r0]
    strh r0, [r1]
    adds r2, #0x34
    ldrh r0, [r7]
    lsls r0, r0, #8
    mov r3, r8
    ldrh r1, [r3]
    orrs r0, r1
    strh r0, [r2]
    ldrh r1, [r4]
    movs r0, #0x10
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    cmp r5, #0
    beq lbl_0806ac80
    adds r1, r4, #0
    adds r1, #0x5c
    movs r2, #0
    movs r0, #0xf0
    lsls r0, r0, #5
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x6a
    strh r2, [r0]
    adds r0, #6
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    adds r0, #2
    strh r2, [r0]
    subs r0, #0xc
    strh r2, [r0]
    ldr r3, lbl_0806ac74 @ =0x0840d088
    ldrh r1, [r3, #2]
    ldr r5, lbl_0806ac78 @ =0x0000dc48
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    ldrh r0, [r3, #6]
    movs r6, #0xb8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x62
    strh r0, [r1]
    ldrh r0, [r3, #4]
    ldr r3, lbl_0806ac7c @ =0x00001808
    adds r1, r3, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x60
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x5e
    strh r2, [r0]
    b lbl_0806ae08
    .align 2, 0
lbl_0806ac3c: .4byte 0x00003844
lbl_0806ac40: .4byte 0x0000060a
lbl_0806ac44: .4byte 0x0400004a
lbl_0806ac48: .4byte gWrittenToMOSAIC_L
lbl_0806ac4c: .4byte 0x04000010
lbl_0806ac50: .4byte gBG0HOFS_NonGameplay
lbl_0806ac54: .4byte 0x000001ff
lbl_0806ac58: .4byte gBG0VOFS_NonGameplay
lbl_0806ac5c: .4byte gBG2HOFS_NonGameplay
lbl_0806ac60: .4byte gBG2VOFS_NonGameplay
lbl_0806ac64: .4byte gBG3HOFS_NonGameplay
lbl_0806ac68: .4byte gBG3VOFS_NonGameplay
lbl_0806ac6c: .4byte 0x0400004c
lbl_0806ac70: .4byte 0x04000050
lbl_0806ac74: .4byte 0x0840d088
lbl_0806ac78: .4byte 0x0000dc48
lbl_0806ac7c: .4byte 0x00001808
lbl_0806ac80:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806ad08
    adds r1, r4, #0
    adds r1, #0x5c
    movs r0, #0xf8
    lsls r0, r0, #5
    strh r0, [r1]
    adds r0, r4, #0
    adds r0, #0x6a
    strh r5, [r0]
    ldr r2, lbl_0806acfc @ =0x0840d088
    ldrh r0, [r2]
    movs r6, #0xc8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r3, r4, #0
    adds r3, #0x70
    strh r0, [r3]
    adds r0, r4, #0
    adds r0, #0x72
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    adds r0, #2
    strh r5, [r0]
    subs r0, #0xc
    strh r5, [r0]
    ldrh r1, [r2, #2]
    ldr r5, lbl_0806ad00 @ =0x0000dc48
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    ldrh r0, [r2, #6]
    movs r6, #0xb8
    lsls r6, r6, #5
    adds r1, r6, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x62
    strh r0, [r1]
    ldrh r0, [r2, #4]
    ldr r2, lbl_0806ad04 @ =0x00001808
    adds r1, r2, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x60
    strh r0, [r1]
    ldrh r1, [r3]
    adds r0, r4, #0
    adds r0, #0x5e
    b lbl_0806ae06
    .align 2, 0
lbl_0806acfc: .4byte 0x0840d088
lbl_0806ad00: .4byte 0x0000dc48
lbl_0806ad04: .4byte 0x00001808
lbl_0806ad08:
    adds r1, r4, #0
    adds r1, #0x5c
    movs r0, #0xf0
    lsls r0, r0, #5
    strh r0, [r1]
    ldr r3, lbl_0806ada0 @ =0x0840d088
    ldrh r0, [r3]
    ldr r5, lbl_0806ada4 @ =0x00001b04
    adds r1, r5, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x6a
    strh r0, [r1]
    ldrh r1, [r3, #6]
    ldr r2, lbl_0806ada8 @ =0x0000dc08
    adds r0, r2, #0
    adds r2, r1, #0
    orrs r2, r0
    adds r0, r4, #0
    adds r0, #0x6c
    strh r2, [r0]
    ldr r5, lbl_0806adac @ =0x00001f08
    adds r0, r5, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x6e
    strh r1, [r0]
    ldrh r0, [r3, #2]
    movs r2, #0xc8
    lsls r2, r2, #5
    adds r1, r2, #0
    orrs r0, r1
    adds r1, r4, #0
    adds r1, #0x70
    strh r0, [r1]
    ldrh r2, [r3, #4]
    movs r3, #0xd0
    lsls r3, r3, #5
    adds r0, r3, #0
    orrs r0, r2
    adds r3, r4, #0
    adds r3, #0x72
    strh r0, [r3]
    movs r5, #0xc0
    lsls r5, r5, #5
    adds r0, r5, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x74
    strh r1, [r0]
    ldrh r0, [r3]
    adds r1, r4, #0
    adds r1, #0x76
    strh r0, [r1]
    ldrh r0, [r4]
    movs r1, #1
    ands r1, r0
    cmp r1, #0
    beq lbl_0806adb4
    movs r6, #0xb0
    lsls r6, r6, #5
    adds r0, r6, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x78
    strh r1, [r0]
    ldr r1, lbl_0806adb0 @ =0x00001608
    adds r0, r1, #0
    adds r1, r2, #0
    orrs r1, r0
    adds r0, r4, #0
    adds r0, #0x7a
    b lbl_0806adbc
    .align 2, 0
lbl_0806ada0: .4byte 0x0840d088
lbl_0806ada4: .4byte 0x00001b04
lbl_0806ada8: .4byte 0x0000dc08
lbl_0806adac: .4byte 0x00001f08
lbl_0806adb0: .4byte 0x00001608
lbl_0806adb4:
    adds r0, r4, #0
    adds r0, #0x78
    strh r1, [r0]
    adds r0, #2
lbl_0806adbc:
    strh r1, [r0]
    mov r3, sl
    ldr r2, [r3]
    adds r0, r2, #0
    adds r0, #0x6c
    ldrh r1, [r0]
    subs r0, #8
    strh r1, [r0]
    adds r0, #0xc
    ldrh r1, [r0]
    subs r0, #0x10
    strh r1, [r0]
    adds r0, #0xa
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0x5e
    strh r0, [r1]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806adfe
    adds r1, r2, #0
    adds r1, #0x5c
    movs r0, #0x94
    lsls r0, r0, #8
    strh r0, [r1]
    adds r0, r2, #0
    adds r0, #0x74
    ldrh r1, [r0]
    subs r0, #0x12
    b lbl_0806ae06
lbl_0806adfe:
    adds r0, r2, #0
    adds r0, #0x72
    ldrh r1, [r0]
    subs r0, #0x10
lbl_0806ae06:
    strh r1, [r0]
lbl_0806ae08:
    ldr r1, lbl_0806aeac @ =0x04000008
    mov r5, sl
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x5e
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x60
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x62
    ldrh r0, [r0]
    strh r0, [r1]
    adds r1, #2
    adds r0, r2, #0
    adds r0, #0x64
    ldrh r0, [r0]
    strh r0, [r1]
    bl sub_0806920c
    ldr r0, lbl_0806aeb0 @ =gOamYOffset_NonGameplay
    movs r1, #4
    strb r1, [r0]
    ldr r0, lbl_0806aeb4 @ =gOamXOffset_NonGameplay
    strb r1, [r0]
    bl sub_08068694
    bl sub_0806889c
    ldr r2, [r5]
    ldrh r1, [r2]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806ae6c
    ldr r6, lbl_0806aeb8 @ =0x00000412
    adds r0, r2, r6
    ldrb r0, [r0]
    cmp r0, #3
    beq lbl_0806ae6c
    ldr r1, lbl_0806aebc @ =0x00000413
    adds r0, r2, r1
    ldrb r1, [r0]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0]
lbl_0806ae6c:
    bl sub_080695bc
    ldr r1, lbl_0806aec0 @ =0x040000d4
    ldr r0, lbl_0806aec4 @ =gOamData
    str r0, [r1]
    movs r0, #0xe0
    lsls r0, r0, #0x13
    str r0, [r1, #4]
    ldr r0, lbl_0806aec8 @ =0x84000100
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #2
    bl sub_080682ec
    ldr r0, lbl_0806aecc @ =sub_0806a2f8
    bl CallbackSetVBlank
    movs r1, #0x80
    lsls r1, r1, #0x13
    ldr r0, lbl_0806aed0 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x5c
    ldrh r0, [r0]
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
lbl_0806aeac: .4byte 0x04000008
lbl_0806aeb0: .4byte gOamYOffset_NonGameplay
lbl_0806aeb4: .4byte gOamXOffset_NonGameplay
lbl_0806aeb8: .4byte 0x00000412
lbl_0806aebc: .4byte 0x00000413
lbl_0806aec0: .4byte 0x040000d4
lbl_0806aec4: .4byte gOamData
lbl_0806aec8: .4byte 0x84000100
lbl_0806aecc: .4byte sub_0806a2f8
lbl_0806aed0: .4byte 0x08754bc4

    thumb_func_start determine_maps_viewable
determine_maps_viewable: @ 0x0806aed4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r3, lbl_0806aff8 @ =0x08754bc4
    ldr r0, [r3]
    ldr r1, lbl_0806affc @ =gEquipment
    ldrb r1, [r1, #0x10]
    adds r0, #0xba
    strb r1, [r0]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xba
    adds r1, #0xb8
    ldrb r0, [r2]
    ldrb r1, [r1]
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0xba
    adds r1, #0xb9
    ldrb r0, [r2]
    ldrb r1, [r1]
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0xba
    ldrb r2, [r0]
    movs r4, #1
    movs r0, #1
    ands r0, r2
    adds r1, #0xbb
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #1
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #2
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #3
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #4
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #5
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xbb
    adds r0, #0xba
    ldrb r1, [r0]
    lsrs r1, r1, #6
    ands r1, r4
    ldrb r0, [r2]
    adds r0, r0, r1
    strb r0, [r2]
    ldr r0, [r3]
    adds r0, #0xbb
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_0806afe2
    movs r5, #0x93
    lsls r5, r5, #2
    ldr r0, lbl_0806b000 @ =0x00000251
    mov sl, r0
    ldr r0, lbl_0806b004 @ =0x08754bb4
    mov sb, r0
    movs r7, #0
    ldr r6, lbl_0806b008 @ =0x000090d0
    movs r4, #0x9b
    lsls r4, r4, #3
    movs r0, #0x98
    lsls r0, r0, #8
    mov r8, r0
    movs r0, #0xa0
    lsls r0, r0, #8
    mov ip, r0
lbl_0806afbe:
    mov r0, sb
    ldr r2, [r0]
    lsls r3, r5, #1
    mov r0, r8
    adds r1, r2, r0
    adds r0, r1, r3
    strh r7, [r0]
    adds r1, r1, r4
    strh r7, [r1]
    add r2, ip
    adds r3, r2, r3
    strh r6, [r3]
    adds r2, r2, r4
    strh r6, [r2]
    adds r4, #2
    adds r5, #1
    cmp r5, sl
    ble lbl_0806afbe
lbl_0806afe2:
    movs r0, #1
    movs r1, #1
    bl sub_0806b00c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806aff8: .4byte 0x08754bc4
lbl_0806affc: .4byte gEquipment
lbl_0806b000: .4byte 0x00000251
lbl_0806b004: .4byte 0x08754bb4
lbl_0806b008: .4byte 0x000090d0

    thumb_func_start sub_0806b00c
sub_0806b00c: @ 0x0806b00c
    push {r4, r5, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r0, lbl_0806b074 @ =0x0600cc40
    mov ip, r0
    ldr r0, lbl_0806b078 @ =0x08754bb4
    ldr r0, [r0]
    movs r3, #0x97
    lsls r3, r3, #8
    adds r5, r0, r3
    movs r4, #1
    rsbs r4, r4, #0
    adds r3, r4, #0
    cmp r2, #0
    beq lbl_0806b042
    movs r3, #0
    cmp r2, #1
    bne lbl_0806b042
    ldr r0, lbl_0806b07c @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    bne lbl_0806b042
    movs r3, #0x16
lbl_0806b042:
    cmp r1, #0
    beq lbl_0806b05a
    movs r4, #0
    cmp r1, #1
    bne lbl_0806b05a
    ldr r0, lbl_0806b07c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xbb
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0806b05a
    movs r4, #0x2d
lbl_0806b05a:
    cmp r3, #0
    bne lbl_0806b080
    cmp r4, #0
    bne lbl_0806b080
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    mov r2, ip
    movs r3, #0x80
    bl BitFill
    b lbl_0806b0ee
    .align 2, 0
lbl_0806b074: .4byte 0x0600cc40
lbl_0806b078: .4byte 0x08754bb4
lbl_0806b07c: .4byte 0x08754bc4
lbl_0806b080:
    cmp r3, #0
    blt lbl_0806b0a6
    lsls r0, r3, #1
    adds r0, r0, r5
    ldrh r1, [r0]
    mov r2, ip
    strh r1, [r2, #0x2c]
    ldrh r1, [r0, #2]
    strh r1, [r2, #0x2e]
    adds r2, #0x6c
    adds r1, r0, #0
    adds r1, #0x40
    ldrh r1, [r1]
    strh r1, [r2]
    mov r1, ip
    adds r1, #0x6e
    adds r0, #0x42
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806b0a6:
    cmp r4, #0
    blt lbl_0806b0ee
    mov r3, ip
    adds r3, #0x5a
    adds r1, r4, #0
    adds r0, r1, #1
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    adds r2, r4, #0
    lsls r1, r1, #1
    adds r1, r1, r5
    ldrh r0, [r1]
    strh r0, [r3]
    adds r3, #2
    adds r0, r2, #1
    lsls r0, r0, #0x10
    asrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r5
    ldrh r0, [r2]
    strh r0, [r3]
    mov r2, ip
    adds r2, #0x5e
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r5
    ldrh r1, [r1]
    strh r1, [r2]
    mov r1, ip
    adds r1, #0x60
    asrs r0, r0, #0xf
    adds r0, r0, r5
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806b0ee:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start get_minimap_data
get_minimap_data: @ 0x0806b0f8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r7, r1, #0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldr r0, lbl_0806b174 @ =0x087601ec
    mov r1, r8
    lsls r4, r1, #2
    adds r0, r4, r0
    ldr r0, [r0]
    adds r1, r7, #0
    bl CallLZ77UncompWRAM
    mov r0, r8
    adds r1, r7, #0
    bl set_tiles_with_obtained_items
    ldr r6, lbl_0806b178 @ =0x0840d200
    mov r0, r8
    adds r5, r4, r0
    adds r0, r5, r6
    ldrb r4, [r0]
    cmp r4, #0
    beq lbl_0806b212
    adds r1, r4, #0
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_0806b212
    adds r0, r6, #2
    adds r0, r5, r0
    adds r1, r6, #3
    adds r1, r5, r1
    ldrb r1, [r1]
    lsls r1, r1, #5
    ldrb r0, [r0]
    adds r4, r1, r0
    mov r1, r8
    cmp r1, #5
    bne lbl_0806b184
    lsls r0, r4, #1
    adds r4, r0, r7
    ldrh r2, [r4]
    ldr r0, lbl_0806b17c @ =0x000003ff
    ldr r1, lbl_0806b180 @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1, #4]
    cmp r0, r1
    bne lbl_0806b212
    adds r1, r4, #0
    movs r3, #2
lbl_0806b164:
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b164
    b lbl_0806b212
    .align 2, 0
lbl_0806b174: .4byte 0x087601ec
lbl_0806b178: .4byte 0x0840d200
lbl_0806b17c: .4byte 0x000003ff
lbl_0806b180: .4byte 0x0840d224
lbl_0806b184:
    mov r0, r8
    cmp r0, #1
    bne lbl_0806b1d0
    lsls r0, r4, #1
    adds r3, r0, r7
    ldrh r2, [r3]
    ldr r0, lbl_0806b1c8 @ =0x000003ff
    ldr r1, lbl_0806b1cc @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1]
    cmp r0, r1
    bne lbl_0806b212
    adds r2, r3, #0
    movs r3, #1
lbl_0806b1a0:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1a0
    lsls r0, r4, #1
    adds r0, r0, r7
    adds r1, r0, #0
    adds r1, #0x40
    movs r3, #1
lbl_0806b1b8:
    ldrh r0, [r1]
    adds r0, #0x20
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1b8
    b lbl_0806b212
    .align 2, 0
lbl_0806b1c8: .4byte 0x000003ff
lbl_0806b1cc: .4byte 0x0840d224
lbl_0806b1d0:
    mov r1, r8
    cmp r1, #3
    bne lbl_0806b212
    lsls r0, r4, #1
    adds r3, r0, r7
    ldrh r2, [r3]
    ldr r0, lbl_0806b238 @ =0x000003ff
    ldr r1, lbl_0806b23c @ =0x0840d224
    ands r0, r2
    ldrh r1, [r1, #2]
    cmp r0, r1
    bne lbl_0806b212
    adds r2, r3, #0
    movs r3, #1
lbl_0806b1ec:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b1ec
    lsls r0, r4, #1
    adds r0, r0, r7
    adds r1, r0, #0
    adds r1, #0x40
    movs r3, #1
lbl_0806b204:
    ldrh r0, [r1]
    adds r0, #0x20
    strh r0, [r1]
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_0806b204
lbl_0806b212:
    mov r0, r8
    cmp r0, #0
    bne lbl_0806b22e
    movs r0, #3
    movs r1, #0x44
    bl EventFunction
    cmp r0, #0
    beq lbl_0806b22e
    adds r1, r7, #0
    adds r1, #0x9c
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
lbl_0806b22e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806b238: .4byte 0x000003ff
lbl_0806b23c: .4byte 0x0840d224

    thumb_func_start sub_0806b240
sub_0806b240: @ 0x0806b240
    push {r4, r5, r6, lr}
    movs r6, #0
    bl check_for_maintained_input
    ldr r0, lbl_0806b264 @ =0x08754bc4
    ldr r1, [r0]
    ldrh r0, [r1, #0xa]
    adds r0, #1
    strh r0, [r1, #0xa]
    ldrb r0, [r1, #4]
    cmp r0, #0x14
    bls lbl_0806b25a
    b lbl_0806b4f6
lbl_0806b25a:
    lsls r0, r0, #2
    ldr r1, lbl_0806b268 @ =lbl_0806b26c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806b264: .4byte 0x08754bc4
lbl_0806b268: .4byte lbl_0806b26c
lbl_0806b26c: @ jump table
    .4byte lbl_0806b2c0 @ case 0
    .4byte lbl_0806b2f0 @ case 1
    .4byte lbl_0806b31e @ case 2
    .4byte lbl_0806b328 @ case 3
    .4byte lbl_0806b358 @ case 4
    .4byte lbl_0806b398 @ case 5
    .4byte lbl_0806b37c @ case 6
    .4byte lbl_0806b398 @ case 7
    .4byte lbl_0806b3ac @ case 8
    .4byte lbl_0806b3c4 @ case 9
    .4byte lbl_0806b3dc @ case 10
    .4byte lbl_0806b3f4 @ case 11
    .4byte lbl_0806b418 @ case 12
    .4byte lbl_0806b430 @ case 13
    .4byte lbl_0806b45c @ case 14
    .4byte lbl_0806b430 @ case 15
    .4byte lbl_0806b478 @ case 16
    .4byte lbl_0806b498 @ case 17
    .4byte lbl_0806b44c @ case 18
    .4byte lbl_0806b4c6 @ case 19
    .4byte lbl_0806b4dc @ case 20
lbl_0806b2c0:
    ldr r2, lbl_0806b2e4 @ =gChangedInput
    ldr r0, lbl_0806b2e8 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #2
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b2dc
    ldr r0, lbl_0806b2ec @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806b324
lbl_0806b2dc:
    bl map_screen_check_input
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b2e4: .4byte gChangedInput
lbl_0806b2e8: .4byte gButtonAssignments
lbl_0806b2ec: .4byte 0x08754bc4
lbl_0806b2f0:
    ldr r0, lbl_0806b314 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b318
    adds r0, r2, #0
    adds r0, #0xd8
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806b30e
    movs r0, #1
    bl sub_0806b504
lbl_0806b30e:
    movs r6, #0
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b314: .4byte 0x08754bc4
lbl_0806b318:
    bl sub_08071800
    b lbl_0806b4f6
lbl_0806b31e:
    movs r0, #0xa0
    bl FadeMusic
lbl_0806b324:
    movs r6, #1
    b lbl_0806b4f6
lbl_0806b328:
    ldr r2, lbl_0806b34c @ =gChangedInput
    ldr r0, lbl_0806b350 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #3
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    bne lbl_0806b33c
    b lbl_0806b4f6
lbl_0806b33c:
    ldr r0, lbl_0806b354 @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806b348
    b lbl_0806b4f6
lbl_0806b348:
    b lbl_0806b324
    .align 2, 0
lbl_0806b34c: .4byte gChangedInput
lbl_0806b350: .4byte gButtonAssignments
lbl_0806b354: .4byte 0x08754bc4
lbl_0806b358:
    bl sub_08070fb0
    cmp r0, #0
    bne lbl_0806b362
    b lbl_0806b4f6
lbl_0806b362:
    movs r0, #4
    bl sub_08068af8
    ldr r0, lbl_0806b378 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r0, #5
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b378: .4byte 0x08754bc4
lbl_0806b37c:
    bl sub_0807142c
    cmp r0, #0
    bne lbl_0806b386
    b lbl_0806b4f6
lbl_0806b386:
    ldr r0, lbl_0806b394 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r0, #7
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b394: .4byte 0x08754bc4
lbl_0806b398:
    ldr r0, lbl_0806b3a8 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    cmp r0, #0xc
    bhi lbl_0806b3a4
    b lbl_0806b4f6
lbl_0806b3a4:
    b lbl_0806b324
    .align 2, 0
lbl_0806b3a8: .4byte 0x08754bc4
lbl_0806b3ac:
    bl chozo_statue_hint_subroutine
    cmp r0, #0
    bne lbl_0806b3b6
    b lbl_0806b4f6
lbl_0806b3b6:
    ldr r0, lbl_0806b3c0 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0xe
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3c0: .4byte 0x08754bc4
lbl_0806b3c4:
    bl sub_0806d448
    cmp r0, #0
    bne lbl_0806b3ce
    b lbl_0806b4f6
lbl_0806b3ce:
    ldr r0, lbl_0806b3d8 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0x12
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3d8: .4byte 0x08754bc4
lbl_0806b3dc:
    bl easy_sleep_menu_subroutine
    cmp r0, #0
    bne lbl_0806b3e6
    b lbl_0806b4f6
lbl_0806b3e6:
    ldr r0, lbl_0806b3f0 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0x11
    strb r0, [r1, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b3f0: .4byte 0x08754bc4
lbl_0806b3f4:
    ldr r5, lbl_0806b414 @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806b838
    cmp r0, #0
    bne lbl_0806b40a
    b lbl_0806b4f6
lbl_0806b40a:
    ldr r1, [r5]
    movs r0, #1
    strb r0, [r1, #4]
    b lbl_0806b4bc
    .align 2, 0
lbl_0806b414: .4byte 0x08754bc4
lbl_0806b418:
    ldr r5, lbl_0806b42c @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806ba34
    b lbl_0806b4b4
    .align 2, 0
lbl_0806b42c: .4byte 0x08754bc4
lbl_0806b430:
    ldr r1, lbl_0806b448 @ =0x08754bc4
    ldr r2, [r1]
    movs r3, #0
    movs r0, #8
    strb r0, [r2, #4]
    ldr r0, [r1]
    movs r2, #0
    strh r3, [r0, #0xa]
    strb r2, [r0, #8]
    ldr r0, [r1]
    strb r2, [r0, #8]
    b lbl_0806b4f2
    .align 2, 0
lbl_0806b448: .4byte 0x08754bc4
lbl_0806b44c:
    ldr r1, lbl_0806b458 @ =0x08754bc4
    ldr r2, [r1]
    movs r3, #0
    movs r0, #3
    b lbl_0806b4ec
    .align 2, 0
lbl_0806b458: .4byte 0x08754bc4
lbl_0806b45c:
    ldr r0, lbl_0806b474 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #2
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0
    beq lbl_0806b470
    movs r0, #2
lbl_0806b470:
    strb r0, [r2, #4]
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b474: .4byte 0x08754bc4
lbl_0806b478:
    ldr r5, lbl_0806b494 @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_0806b4a4
    bl sub_0806bc34
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, [r5]
    movs r0, #0xa
    strb r0, [r1, #4]
    b lbl_0806b4bc
    .align 2, 0
lbl_0806b494: .4byte 0x08754bc4
lbl_0806b498:
    ldr r5, lbl_0806b4ac @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0x7c
    ldrb r4, [r0]
    cmp r4, #0
    beq lbl_0806b4b0
lbl_0806b4a4:
    bl sub_080681c8
    b lbl_0806b4f6
    .align 2, 0
lbl_0806b4ac: .4byte 0x08754bc4
lbl_0806b4b0:
    bl sub_0806bf08
lbl_0806b4b4:
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r0, [r5]
    strb r4, [r0, #4]
lbl_0806b4bc:
    ldr r0, [r5]
    strb r4, [r0, #8]
    ldr r0, [r5]
    strh r4, [r0, #0xa]
    b lbl_0806b4f6
lbl_0806b4c6:
    bl sub_0806b778
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, lbl_0806b4d8 @ =0x08754bc4
    ldr r2, [r1]
    movs r3, #0
    movs r0, #4
    b lbl_0806b4ec
    .align 2, 0
lbl_0806b4d8: .4byte 0x08754bc4
lbl_0806b4dc:
    bl sub_0806b778
    cmp r0, #0
    beq lbl_0806b4f6
    ldr r1, lbl_0806b500 @ =0x08754bc4
    ldr r2, [r1]
    movs r3, #0
    movs r0, #6
lbl_0806b4ec:
    strb r0, [r2, #4]
    ldr r0, [r1]
    strb r3, [r0, #8]
lbl_0806b4f2:
    ldr r0, [r1]
    strh r3, [r0, #0xa]
lbl_0806b4f6:
    adds r0, r6, #0
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806b500: .4byte 0x08754bc4

    thumb_func_start sub_0806b504
sub_0806b504: @ 0x0806b504
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r4, lbl_0806b568 @ =0x08754bc4
    ldr r0, [r4]
    mov ip, r0
    movs r2, #0x84
    lsls r2, r2, #1
    add r2, ip
    ldrh r1, [r2]
    movs r3, #0x20
    rsbs r3, r3, #0
    adds r0, r3, #0
    ands r0, r1
    strh r0, [r2]
    movs r2, #0x85
    lsls r2, r2, #1
    add r2, ip
    ldrh r0, [r2]
    ands r3, r0
    strh r3, [r2]
    ldr r0, lbl_0806b56c @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    adds r7, r4, #0
    cmp r0, #0
    beq lbl_0806b53e
    b lbl_0806b666
lbl_0806b53e:
    mov r1, ip
    ldrb r5, [r1, #8]
    cmp r5, #0
    beq lbl_0806b548
    b lbl_0806b666
lbl_0806b548:
    cmp r6, #0
    bne lbl_0806b5cc
    ldr r1, lbl_0806b570 @ =gChangedInput
    ldrh r4, [r1]
    movs r0, #0x10
    ands r0, r4
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0806b578
    lsls r1, r3, #0x10
    ldr r0, lbl_0806b574 @ =0x039f0000
    cmp r1, r0
    bgt lbl_0806b58a
    adds r0, r3, #0
    adds r0, #0x20
    b lbl_0806b588
    .align 2, 0
lbl_0806b568: .4byte 0x08754bc4
lbl_0806b56c: .4byte gButtonInput
lbl_0806b570: .4byte gChangedInput
lbl_0806b574: .4byte 0x039f0000
lbl_0806b578:
    movs r0, #0x20
    ands r0, r4
    cmp r0, #0
    beq lbl_0806b58a
    cmp r3, #0
    beq lbl_0806b58a
    adds r0, r3, #0
    subs r0, #0x20
lbl_0806b588:
    strh r0, [r2]
lbl_0806b58a:
    ldrh r1, [r6]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b5a8
    ldr r0, [r7]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r4, r0, r2
    ldrh r1, [r4]
    movs r2, #0
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_0806b666
    b lbl_0806b62c
lbl_0806b5a8:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b666
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r2, [r4]
    movs r0, #0
    ldrsh r1, [r4, r0]
    ldr r0, lbl_0806b5c8 @ =0x0000025f
    cmp r1, r0
    bgt lbl_0806b666
    b lbl_0806b658
    .align 2, 0
lbl_0806b5c8: .4byte 0x0000025f
lbl_0806b5cc:
    ldr r1, lbl_0806b5e8 @ =gChangedInput
    ldrh r4, [r1]
    movs r0, #0x10
    ands r0, r4
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0806b5f4
    lsls r1, r3, #0x10
    ldr r0, lbl_0806b5ec @ =0x039f0000
    cmp r1, r0
    bgt lbl_0806b5f0
    adds r0, r3, #0
    adds r0, #0x20
    b lbl_0806b60a
    .align 2, 0
lbl_0806b5e8: .4byte gChangedInput
lbl_0806b5ec: .4byte 0x039f0000
lbl_0806b5f0:
    strh r5, [r2]
    b lbl_0806b60c
lbl_0806b5f4:
    movs r0, #0x20
    ands r0, r4
    cmp r0, #0
    beq lbl_0806b60c
    cmp r3, #0
    beq lbl_0806b606
    adds r0, r3, #0
    subs r0, #0x20
    b lbl_0806b60a
lbl_0806b606:
    movs r0, #0xe8
    lsls r0, r0, #2
lbl_0806b60a:
    strh r0, [r2]
lbl_0806b60c:
    ldrh r1, [r6]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    cmp r3, #0
    beq lbl_0806b63c
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r1, [r4]
    movs r2, #0
    ldrsh r0, [r4, r2]
    cmp r0, #0
    beq lbl_0806b634
lbl_0806b62c:
    adds r0, r1, #0
    subs r0, #0x20
    strh r0, [r4]
    b lbl_0806b666
lbl_0806b634:
    movs r0, #0x98
    lsls r0, r0, #2
    strh r0, [r4]
    b lbl_0806b666
lbl_0806b63c:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806b666
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r4, r0, r1
    ldrh r2, [r4]
    movs r0, #0
    ldrsh r1, [r4, r0]
    ldr r0, lbl_0806b660 @ =0x0000025f
    cmp r1, r0
    bgt lbl_0806b664
lbl_0806b658:
    adds r0, r2, #0
    adds r0, #0x20
    strh r0, [r4]
    b lbl_0806b666
    .align 2, 0
lbl_0806b660: .4byte 0x0000025f
lbl_0806b664:
    strh r3, [r4]
lbl_0806b666:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0806b66c
sub_0806b66c: @ 0x0806b66c
    push {r4, r5, lr}
    adds r2, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    movs r5, #0
    ldrh r3, [r2]
    movs r4, #1
    cmp r3, r1
    bls lbl_0806b680
    subs r4, #2
lbl_0806b680:
    ldr r0, lbl_0806b690 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    adds r0, #4
    cmp r0, #0x1f
    bgt lbl_0806b694
    muls r0, r4, r0
    b lbl_0806b696
    .align 2, 0
lbl_0806b690: .4byte 0x08754bc4
lbl_0806b694:
    lsls r0, r4, #5
lbl_0806b696:
    adds r0, r3, r0
    strh r0, [r2]
    cmp r4, #0
    ble lbl_0806b6a8
    ldrh r0, [r2]
    cmp r0, r1
    blo lbl_0806b6ba
    strh r1, [r2]
    b lbl_0806b6b8
lbl_0806b6a8:
    movs r3, #0
    ldrsh r0, [r2, r3]
    cmp r0, r1
    bgt lbl_0806b6ba
    subs r0, r1, r0
    ldrh r1, [r2]
    adds r0, r0, r1
    strh r0, [r2]
lbl_0806b6b8:
    movs r5, #1
lbl_0806b6ba:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806b6c4
sub_0806b6c4: @ 0x0806b6c4
    push {r4, r5, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    movs r5, #0
    ldrh r2, [r3]
    movs r1, #1
    cmp r2, r4
    bls lbl_0806b6d8
    subs r1, #2
lbl_0806b6d8:
    ldr r0, lbl_0806b6e8 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r0, [r0, #0xa]
    adds r0, #4
    cmp r0, #0x1f
    bgt lbl_0806b6ec
    muls r0, r1, r0
    b lbl_0806b6ee
    .align 2, 0
lbl_0806b6e8: .4byte 0x08754bc4
lbl_0806b6ec:
    lsls r0, r1, #5
lbl_0806b6ee:
    adds r0, r2, r0
    strh r0, [r3]
    cmp r1, #0
    ble lbl_0806b700
    ldrh r0, [r3]
    cmp r0, r4
    blo lbl_0806b70a
    movs r5, #1
    b lbl_0806b70e
lbl_0806b700:
    movs r1, #0
    ldrsh r0, [r3, r1]
    cmp r0, r4
    bgt lbl_0806b70a
    movs r5, #1
lbl_0806b70a:
    cmp r5, #0
    beq lbl_0806b710
lbl_0806b70e:
    strh r4, [r3]
lbl_0806b710:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_0806b718
sub_0806b718: @ 0x0806b718
    push {r4, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r4, r1, #0
    cmp r1, #0xff
    beq lbl_0806b734
    ldr r0, lbl_0806b76c @ =0x08754bc4
    ldr r0, [r0]
    movs r2, #0x87
    lsls r2, r2, #3
    adds r0, r0, r2
    bl UpdateMenuOamDataID
lbl_0806b734:
    movs r0, #1
    cmp r4, #0xf
    beq lbl_0806b748
    movs r0, #2
    cmp r4, #0x10
    beq lbl_0806b748
    movs r0, #3
    cmp r4, #0
    bne lbl_0806b748
    movs r0, #0
lbl_0806b748:
    ldr r1, lbl_0806b770 @ =0x08754bb4
    lsls r0, r0, #7
    movs r2, #0x95
    lsls r2, r2, #8
    adds r0, r0, r2
    ldr r1, [r1]
    adds r1, r1, r0
    ldr r2, lbl_0806b774 @ =0x0600c800
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806b76c: .4byte 0x08754bc4
lbl_0806b770: .4byte 0x08754bb4
lbl_0806b774: .4byte 0x0600c800

    thumb_func_start sub_0806b778
sub_0806b778: @ 0x0806b778
    push {r4, r5, lr}
    sub sp, #4
    movs r4, #0
    ldr r5, lbl_0806b794 @ =0x08754bc4
    ldr r1, [r5]
    ldrb r0, [r1, #8]
    cmp r0, #1
    beq lbl_0806b7a2
    cmp r0, #1
    bgt lbl_0806b798
    cmp r0, #0
    beq lbl_0806b7a8
    b lbl_0806b7fa
    .align 2, 0
lbl_0806b794: .4byte 0x08754bc4
lbl_0806b798:
    cmp r0, #2
    beq lbl_0806b7ae
    cmp r0, #3
    beq lbl_0806b7c0
    b lbl_0806b7fa
lbl_0806b7a2:
    movs r0, #3
    bl sub_08068af8
lbl_0806b7a8:
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b7fe
lbl_0806b7ae:
    ldrb r0, [r1, #0xa]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    bl draw_status_screen_item
    cmp r0, #0
    beq lbl_0806b7fa
    b lbl_0806b7a8
lbl_0806b7c0:
    ldr r0, lbl_0806b810 @ =gCurrentItemBeingAcquired
    ldrb r1, [r0]
    movs r0, #2
    bl sub_08070020
    ldr r1, [r5]
    adds r1, #0xc1
    strb r0, [r1]
    bl sub_08070f6c
    ldr r1, [r5]
    adds r1, #0x5c
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r2, lbl_0806b814 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806b7fa:
    cmp r4, #0
    ble lbl_0806b82a
lbl_0806b7fe:
    cmp r4, #0xff
    ble lbl_0806b81c
    ldr r2, lbl_0806b818 @ =0x08754bc4
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    adds r1, r2, #0
    b lbl_0806b822
    .align 2, 0
lbl_0806b810: .4byte gCurrentItemBeingAcquired
lbl_0806b814: .4byte 0x06007800
lbl_0806b818: .4byte 0x08754bc4
lbl_0806b81c:
    ldr r1, lbl_0806b834 @ =0x08754bc4
    ldr r0, [r1]
    strb r4, [r0, #8]
lbl_0806b822:
    ldr r1, [r1]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
lbl_0806b82a:
    adds r0, r4, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806b834: .4byte 0x08754bc4

    thumb_func_start sub_0806b838
sub_0806b838: @ 0x0806b838
    push {r4, lr}
    sub sp, #4
    movs r4, #0
    ldr r1, lbl_0806b858 @ =0x08754bc4
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #9
    bls lbl_0806b84c
    b lbl_0806b9d6
lbl_0806b84c:
    lsls r0, r0, #2
    ldr r1, lbl_0806b85c @ =lbl_0806b860
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806b858: .4byte 0x08754bc4
lbl_0806b85c: .4byte lbl_0806b860
lbl_0806b860: @ jump table
    .4byte lbl_0806b888 @ case 0
    .4byte lbl_0806b8e0 @ case 1
    .4byte lbl_0806b8f4 @ case 2
    .4byte lbl_0806b912 @ case 3
    .4byte lbl_0806b93c @ case 4
    .4byte lbl_0806b944 @ case 5
    .4byte lbl_0806b950 @ case 6
    .4byte lbl_0806b95c @ case 7
    .4byte lbl_0806b974 @ case 8
    .4byte lbl_0806b9ac @ case 9
lbl_0806b888:
    ldr r0, lbl_0806b8ac @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #2
    bne lbl_0806b8b8
    ldr r0, lbl_0806b8b0 @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806b8b4 @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806b8d2
    .align 2, 0
lbl_0806b8ac: .4byte gEquipment
lbl_0806b8b0: .4byte 0x08754bb4
lbl_0806b8b4: .4byte 0x0600c000
lbl_0806b8b8:
    ldr r0, lbl_0806b8d8 @ =0x08754bb4
    ldr r1, [r0]
    movs r3, #0xf0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806b8dc @ =0x0600c000
    movs r3, #0xa0
    lsls r3, r3, #3
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_0806b8d2:
    movs r4, #1
    b lbl_0806b9da
    .align 2, 0
lbl_0806b8d8: .4byte 0x08754bb4
lbl_0806b8dc: .4byte 0x0600c000
lbl_0806b8e0:
    movs r0, #0xf
    bl sub_0806b718
    movs r4, #0x80
    lsls r4, r4, #1
    movs r0, #0xfa
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0806b9d6
lbl_0806b8f4:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806b9d6
    movs r0, #2
    movs r1, #2
    bl sub_0806b00c
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b912:
    ldr r0, lbl_0806b934 @ =0x08754bc4
    ldr r2, [r0]
    ldrh r1, [r2]
    movs r0, #0x80
    orrs r0, r1
    strh r0, [r2]
    adds r0, r2, #0
    adds r0, #0x74
    ldrh r0, [r0]
    adds r1, r2, #0
    adds r1, #0x62
    strh r0, [r1]
    adds r1, #4
    ldr r0, lbl_0806b938 @ =0x00003c44
    strh r0, [r1]
    movs r0, #1
    b lbl_0806b952
    .align 2, 0
lbl_0806b934: .4byte 0x08754bc4
lbl_0806b938: .4byte 0x00003c44
lbl_0806b93c:
    movs r0, #2
    bl sub_08068af8
    b lbl_0806b96a
lbl_0806b944:
    movs r0, #0x10
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    b lbl_0806b96a
lbl_0806b950:
    movs r0, #3
lbl_0806b952:
    bl sub_08068af8
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b95c:
    ldr r0, [r2]
    ldrb r0, [r0, #0xa]
    subs r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    bl draw_status_screen_item
lbl_0806b96a:
    cmp r0, #0
    beq lbl_0806b9d6
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806b9da
lbl_0806b974:
    bl sub_08070f6c
    ldr r0, lbl_0806b9a4 @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0x5c
    ldrh r2, [r1]
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    orrs r0, r2
    strh r0, [r1]
    ldr r2, lbl_0806b9a8 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r4, #1
    rsbs r4, r4, #0
    b lbl_0806ba14
    .align 2, 0
lbl_0806b9a4: .4byte 0x08754bc4
lbl_0806b9a8: .4byte 0x06007800
lbl_0806b9ac:
    ldr r3, [r2]
    adds r0, r3, #0
    adds r0, #0x78
    ldrh r0, [r0]
    adds r1, r3, #0
    adds r1, #0x62
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    ldr r0, lbl_0806b9ec @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_0806b9f0 @ =0x00000433
    adds r2, r3, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806b9d6:
    cmp r4, #0
    ble lbl_0806ba10
lbl_0806b9da:
    cmp r4, #0xff
    ble lbl_0806b9f8
    ldr r2, lbl_0806b9f4 @ =0x08754bc4
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_0806ba00
    .align 2, 0
lbl_0806b9ec: .4byte 0x0000fdff
lbl_0806b9f0: .4byte 0x00000433
lbl_0806b9f4: .4byte 0x08754bc4
lbl_0806b9f8:
    ldr r1, lbl_0806ba0c @ =0x08754bc4
    ldr r0, [r1]
    strb r4, [r0, #8]
    adds r2, r1, #0
lbl_0806ba00:
    ldr r1, [r2]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
    b lbl_0806ba20
    .align 2, 0
lbl_0806ba0c: .4byte 0x08754bc4
lbl_0806ba10:
    cmp r4, #0
    bge lbl_0806ba20
lbl_0806ba14:
    ldr r1, lbl_0806ba2c @ =gWrittenToBLDALPHA_H
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0806ba30 @ =gWrittenToBLDALPHA_L
    movs r0, #0x10
    strh r0, [r1]
lbl_0806ba20:
    adds r0, r4, #0
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806ba2c: .4byte gWrittenToBLDALPHA_H
lbl_0806ba30: .4byte gWrittenToBLDALPHA_L

    thumb_func_start sub_0806ba34
sub_0806ba34: @ 0x0806ba34
    push {r4, r5, lr}
    movs r4, #0
    ldr r1, lbl_0806ba50 @ =0x08754bc4
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r5, r1, #0
    cmp r0, #8
    bls lbl_0806ba46
    b lbl_0806bbd0
lbl_0806ba46:
    lsls r0, r0, #2
    ldr r1, lbl_0806ba54 @ =lbl_0806ba58
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806ba50: .4byte 0x08754bc4
lbl_0806ba54: .4byte lbl_0806ba58
lbl_0806ba58: @ jump table
    .4byte lbl_0806ba7c @ case 0
    .4byte lbl_0806baa4 @ case 1
    .4byte lbl_0806bac8 @ case 2
    .4byte lbl_0806bad8 @ case 3
    .4byte lbl_0806bb18 @ case 4
    .4byte lbl_0806bb40 @ case 5
    .4byte lbl_0806bb76 @ case 6
    .4byte lbl_0806bb9c @ case 7
    .4byte lbl_0806bbc4 @ case 8
lbl_0806ba7c:
    ldr r0, lbl_0806ba9c @ =0x000001f5
    bl SoundPlay
    ldr r0, lbl_0806baa0 @ =0x08754bc4
    ldr r0, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0
    strb r0, [r1]
    bl sub_0806b718
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806ba9c: .4byte 0x000001f5
lbl_0806baa0: .4byte 0x08754bc4
lbl_0806baa4:
    movs r0, #4
    bl sub_08068af8
    ldr r0, lbl_0806bac0 @ =0x08754bc4
    ldr r0, [r0]
    ldr r4, lbl_0806bac4 @ =0x00000123
    adds r2, r0, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bac0: .4byte 0x08754bc4
lbl_0806bac4: .4byte 0x00000123
lbl_0806bac8:
    ldr r0, [r5]
    ldrh r0, [r0, #0xa]
    cmp r0, #0xc
    bhi lbl_0806bad2
    b lbl_0806bbd0
lbl_0806bad2:
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
lbl_0806bad8:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bbd0
    ldr r0, lbl_0806bb0c @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0x5c
    ldrh r2, [r3]
    ldr r0, lbl_0806bb10 @ =0x0000feff
    ands r0, r2
    strh r0, [r3]
    ldr r0, lbl_0806bb14 @ =0x00000463
    adds r1, r1, r0
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb0c: .4byte 0x08754bc4
lbl_0806bb10: .4byte 0x0000feff
lbl_0806bb14: .4byte 0x00000463
lbl_0806bb18:
    ldr r4, lbl_0806bb38 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0x66
    movs r5, #0
    ldr r1, lbl_0806bb3c @ =0x00003844
    strh r1, [r0]
    movs r0, #5
    bl sub_08068af8
    ldr r0, [r4]
    adds r0, #0x57
    strb r5, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb38: .4byte 0x08754bc4
lbl_0806bb3c: .4byte 0x00003844
lbl_0806bb40:
    ldr r1, lbl_0806bb8c @ =gWrittenToBLDALPHA_H
    movs r0, #0x10
    strh r0, [r1]
    ldr r1, lbl_0806bb90 @ =gWrittenToBLDALPHA_L
    movs r0, #0
    strh r0, [r1]
    ldr r2, [r5]
    adds r3, r2, #0
    adds r3, #0x5c
    ldrh r0, [r3]
    movs r4, #0x80
    lsls r4, r4, #2
    adds r1, r4, #0
    orrs r0, r1
    strh r0, [r3]
    ldr r0, lbl_0806bb94 @ =0x00000433
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r5]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
lbl_0806bb76:
    ldr r0, lbl_0806bb98 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x72
    ldrh r1, [r1]
    adds r0, #0x62
    strh r1, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bb8c: .4byte gWrittenToBLDALPHA_H
lbl_0806bb90: .4byte gWrittenToBLDALPHA_L
lbl_0806bb94: .4byte 0x00000433
lbl_0806bb98: .4byte 0x08754bc4
lbl_0806bb9c:
    ldr r0, [r5]
    adds r0, #0x68
    ldrh r0, [r0]
    movs r1, #2
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bbd0
    ldr r2, [r5]
    ldrh r1, [r2]
    ldr r0, lbl_0806bbc0 @ =0x0000ff7f
    ands r0, r1
    strh r0, [r2]
    movs r4, #0x80
    lsls r4, r4, #1
    b lbl_0806bbd4
    .align 2, 0
lbl_0806bbc0: .4byte 0x0000ff7f
lbl_0806bbc4:
    movs r0, #1
    movs r1, #1
    bl sub_0806b00c
    movs r4, #1
    rsbs r4, r4, #0
lbl_0806bbd0:
    cmp r4, #0
    ble lbl_0806bc04
lbl_0806bbd4:
    cmp r4, #0xff
    ble lbl_0806bbec
    ldr r2, lbl_0806bbe8 @ =0x08754bc4
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    adds r5, r2, #0
    b lbl_0806bbf4
    .align 2, 0
lbl_0806bbe8: .4byte 0x08754bc4
lbl_0806bbec:
    ldr r1, lbl_0806bc00 @ =0x08754bc4
    ldr r0, [r1]
    strb r4, [r0, #8]
    adds r5, r1, #0
lbl_0806bbf4:
    ldr r1, [r5]
    movs r0, #0
    strh r0, [r1, #0xa]
    movs r4, #0
    b lbl_0806bc1e
    .align 2, 0
lbl_0806bc00: .4byte 0x08754bc4
lbl_0806bc04:
    cmp r4, #0
    bge lbl_0806bc1e
    ldr r1, lbl_0806bc28 @ =gWrittenToBLDALPHA_H
    ldr r0, lbl_0806bc2c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x68
    ldrh r2, [r0]
    lsrs r0, r2, #8
    strh r0, [r1]
    ldr r1, lbl_0806bc30 @ =gWrittenToBLDALPHA_L
    movs r0, #0xff
    ands r0, r2
    strh r0, [r1]
lbl_0806bc1e:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806bc28: .4byte gWrittenToBLDALPHA_H
lbl_0806bc2c: .4byte 0x08754bc4
lbl_0806bc30: .4byte gWrittenToBLDALPHA_L

    thumb_func_start sub_0806bc34
sub_0806bc34: @ 0x0806bc34
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r4, lbl_0806bc60 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xe9
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    blt lbl_0806bc4c
    bl sub_0806fbb8
lbl_0806bc4c:
    ldr r0, [r4]
    ldrb r0, [r0, #8]
    cmp r0, #0xb
    bls lbl_0806bc56
    b lbl_0806bef0
lbl_0806bc56:
    lsls r0, r0, #2
    ldr r1, lbl_0806bc64 @ =lbl_0806bc68
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806bc60: .4byte 0x08754bc4
lbl_0806bc64: .4byte lbl_0806bc68
lbl_0806bc68: @ jump table
    .4byte lbl_0806bc98 @ case 0
    .4byte lbl_0806bc9e @ case 1
    .4byte lbl_0806bcc4 @ case 2
    .4byte lbl_0806bce8 @ case 3
    .4byte lbl_0806bd1c @ case 4
    .4byte lbl_0806bef0 @ case 5
    .4byte lbl_0806bd50 @ case 6
    .4byte lbl_0806bdbc @ case 7
    .4byte lbl_0806be04 @ case 8
    .4byte lbl_0806be58 @ case 9
    .4byte lbl_0806be7a @ case 10
    .4byte lbl_0806be9c @ case 11
lbl_0806bc98:
    movs r0, #0x80
    lsls r0, r0, #5
    b lbl_0806be7c
lbl_0806bc9e:
    movs r0, #2
    movs r1, #2
    bl sub_0806b00c
    movs r0, #0x10
    bl sub_0806b718
    ldr r0, lbl_0806bcbc @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0x5c
    ldrh r2, [r1]
    ldr r0, lbl_0806bcc0 @ =0x0000fbff
    ands r0, r2
    strh r0, [r1]
    b lbl_0806bef0
    .align 2, 0
lbl_0806bcbc: .4byte 0x08754bc4
lbl_0806bcc0: .4byte 0x0000fbff
lbl_0806bcc4:
    ldr r0, lbl_0806bce0 @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0x88
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806bce4 @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    b lbl_0806bef0
    .align 2, 0
lbl_0806bce0: .4byte 0x08754bb4
lbl_0806bce4: .4byte 0x0600d000
lbl_0806bce8:
    ldr r1, lbl_0806bd10 @ =0x06006000
    ldr r5, lbl_0806bd14 @ =0x08754bb4
    ldr r2, [r5]
    movs r3, #0xa8
    lsls r3, r3, #8
    adds r2, r2, r3
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0806bd18 @ =0x06006800
    ldr r2, [r5]
    movs r0, #0xb0
    lsls r0, r0, #8
    adds r2, r2, r0
    b lbl_0806be3c
    .align 2, 0
lbl_0806bd10: .4byte 0x06006000
lbl_0806bd14: .4byte 0x08754bb4
lbl_0806bd18: .4byte 0x06006800
lbl_0806bd1c:
    ldr r1, lbl_0806bd44 @ =0x06007000
    ldr r5, lbl_0806bd48 @ =0x08754bb4
    ldr r2, [r5]
    movs r3, #0xb8
    lsls r3, r3, #8
    adds r2, r2, r3
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, lbl_0806bd4c @ =0x06007800
    ldr r2, [r5]
    movs r0, #0xc0
    lsls r0, r0, #8
    adds r2, r2, r0
    b lbl_0806be3c
    .align 2, 0
lbl_0806bd44: .4byte 0x06007000
lbl_0806bd48: .4byte 0x08754bb4
lbl_0806bd4c: .4byte 0x06007800
lbl_0806bd50:
    ldr r0, lbl_0806bda8 @ =0x040000d4
    ldr r1, lbl_0806bdac @ =0x08754bb4
    ldr r2, [r1]
    movs r3, #0xc0
    lsls r3, r3, #7
    adds r1, r2, r3
    str r1, [r0]
    movs r4, #0x87
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    ldr r3, lbl_0806bdb0 @ =0x80000040
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    movs r4, #0xc8
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0]
    movs r4, #0x8f
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    ldr r4, lbl_0806bdb4 @ =0x000061c0
    adds r1, r2, r4
    str r1, [r0]
    movs r4, #0x97
    lsls r4, r4, #7
    adds r1, r2, r4
    str r1, [r0, #4]
    str r3, [r0, #8]
    ldr r1, [r0, #8]
    ldr r4, lbl_0806bdb8 @ =0x000065c0
    adds r1, r2, r4
    str r1, [r0]
    movs r1, #0x9f
    lsls r1, r1, #7
    adds r2, r2, r1
    str r2, [r0, #4]
    str r3, [r0, #8]
    ldr r0, [r0, #8]
    b lbl_0806bef0
    .align 2, 0
lbl_0806bda8: .4byte 0x040000d4
lbl_0806bdac: .4byte 0x08754bb4
lbl_0806bdb0: .4byte 0x80000040
lbl_0806bdb4: .4byte 0x000061c0
lbl_0806bdb8: .4byte 0x000065c0
lbl_0806bdbc:
    ldr r0, lbl_0806bdf4 @ =0x08754bc4
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xe9
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0806be8c
    ldr r5, lbl_0806bdf8 @ =0x08754bb4
    ldr r1, [r5]
    movs r3, #0x80
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806bdfc @ =0x06006000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0x90
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806be00 @ =0x06006800
    b lbl_0806be3c
    .align 2, 0
lbl_0806bdf4: .4byte 0x08754bc4
lbl_0806bdf8: .4byte 0x08754bb4
lbl_0806bdfc: .4byte 0x06006000
lbl_0806be00: .4byte 0x06006800
lbl_0806be04:
    ldr r0, lbl_0806be48 @ =0x08754bc4
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xe9
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bge lbl_0806be8c
    ldr r5, lbl_0806be4c @ =0x08754bb4
    ldr r1, [r5]
    movs r3, #0xa0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldr r2, lbl_0806be50 @ =0x06007000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xb0
    lsls r0, r0, #7
    adds r1, r1, r0
    ldr r2, lbl_0806be54 @ =0x06007800
lbl_0806be3c:
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0806bef0
    .align 2, 0
lbl_0806be48: .4byte 0x08754bc4
lbl_0806be4c: .4byte 0x08754bb4
lbl_0806be50: .4byte 0x06007000
lbl_0806be54: .4byte 0x06007800
lbl_0806be58:
    ldr r0, lbl_0806be94 @ =0x08754bc4
    ldr r3, [r0]
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806be98 @ =0x00003c44
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
lbl_0806be7a:
    movs r0, #0x10
lbl_0806be7c:
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    bne lbl_0806bef0
    ldr r0, lbl_0806be94 @ =0x08754bc4
    ldr r1, [r0]
lbl_0806be8c:
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    b lbl_0806bef0
    .align 2, 0
lbl_0806be94: .4byte 0x08754bc4
lbl_0806be98: .4byte 0x00003c44
lbl_0806be9c:
    ldr r5, lbl_0806bee8 @ =0x08754bc4
    ldr r0, [r5]
    movs r4, #0x8c
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #2
    bl UpdateMenuOamDataID
    ldr r1, [r5]
    movs r0, #0x8d
    lsls r0, r0, #1
    adds r6, r1, r0
    movs r2, #0
    movs r3, #0
    adds r0, #0xf6
    strh r0, [r6]
    adds r4, r1, r4
    movs r0, #0x88
    lsls r0, r0, #1
    strh r0, [r4]
    adds r0, #0x13
    adds r4, r1, r0
    ldrb r1, [r4]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r4]
    ldr r1, lbl_0806beec @ =gDisableSoftreset
    movs r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    strb r2, [r0, #8]
    ldr r0, [r5]
    strh r3, [r0, #0xa]
    movs r0, #1
    b lbl_0806befc
    .align 2, 0
lbl_0806bee8: .4byte 0x08754bc4
lbl_0806beec: .4byte gDisableSoftreset
lbl_0806bef0:
    ldr r0, lbl_0806bf04 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    movs r0, #0
lbl_0806befc:
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806bf04: .4byte 0x08754bc4

    thumb_func_start sub_0806bf08
sub_0806bf08: @ 0x0806bf08
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r1, lbl_0806bf24 @ =0x08754bc4
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #8
    bls lbl_0806bf1a
    b lbl_0806c0c8
lbl_0806bf1a:
    lsls r0, r0, #2
    ldr r1, lbl_0806bf28 @ =lbl_0806bf2c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806bf24: .4byte 0x08754bc4
lbl_0806bf28: .4byte lbl_0806bf2c
lbl_0806bf2c: @ jump table
    .4byte lbl_0806bf50 @ case 0
    .4byte lbl_0806bf66 @ case 1
    .4byte lbl_0806bf88 @ case 2
    .4byte lbl_0806bfc4 @ case 3
    .4byte lbl_0806bff0 @ case 4
    .4byte lbl_0806c024 @ case 5
    .4byte lbl_0806c064 @ case 6
    .4byte lbl_0806c084 @ case 7
    .4byte lbl_0806c0ac @ case 8
lbl_0806bf50:
    ldr r1, lbl_0806bf80 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    movs r0, #0
    bl sub_0806b718
    ldr r0, lbl_0806bf84 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
lbl_0806bf66:
    movs r0, #0x80
    lsls r0, r0, #5
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    beq lbl_0806bf78
    b lbl_0806c0c8
lbl_0806bf78:
    ldr r0, lbl_0806bf84 @ =0x08754bc4
    ldr r1, [r0]
    b lbl_0806c09a
    .align 2, 0
lbl_0806bf80: .4byte gDisableSoftreset
lbl_0806bf84: .4byte 0x08754bc4
lbl_0806bf88:
    ldr r4, lbl_0806bfb8 @ =0x08754bc4
    ldr r3, [r4]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    ldr r0, lbl_0806bfbc @ =0x0000fbff
    ands r0, r1
    strh r0, [r2]
    movs r1, #0x8c
    lsls r1, r1, #1
    adds r0, r3, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    ldr r4, lbl_0806bfc0 @ =0x00000123
    adds r2, r0, r4
    ldrb r1, [r2]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806bfb8: .4byte 0x08754bc4
lbl_0806bfbc: .4byte 0x0000fbff
lbl_0806bfc0: .4byte 0x00000123
lbl_0806bfc4:
    ldr r1, lbl_0806bfe0 @ =0x040000d4
    ldr r0, lbl_0806bfe4 @ =0x08754bb4
    ldr r0, [r0]
    movs r2, #0x98
    lsls r2, r2, #8
    adds r0, r0, r2
    str r0, [r1]
    ldr r0, lbl_0806bfe8 @ =0x0600d000
    str r0, [r1, #4]
    ldr r0, lbl_0806bfec @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806bfe0: .4byte 0x040000d4
lbl_0806bfe4: .4byte 0x08754bb4
lbl_0806bfe8: .4byte 0x0600d000
lbl_0806bfec: .4byte 0x80000400
lbl_0806bff0:
    ldr r5, lbl_0806c018 @ =0x08754bb4
    ldr r1, [r5]
    movs r4, #0xa8
    lsls r4, r4, #8
    adds r1, r1, r4
    ldr r2, lbl_0806c01c @ =0x06006000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xb0
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806c020 @ =0x06006800
    b lbl_0806c04a
    .align 2, 0
lbl_0806c018: .4byte 0x08754bb4
lbl_0806c01c: .4byte 0x06006000
lbl_0806c020: .4byte 0x06006800
lbl_0806c024:
    ldr r5, lbl_0806c058 @ =0x08754bb4
    ldr r1, [r5]
    movs r2, #0xb8
    lsls r2, r2, #8
    adds r1, r1, r2
    ldr r2, lbl_0806c05c @ =0x06007000
    movs r6, #0x80
    lsls r6, r6, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    ldr r1, [r5]
    movs r0, #0xc0
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806c060 @ =0x06007800
lbl_0806c04a:
    str r4, [sp]
    movs r0, #3
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0806c0c8
    .align 2, 0
lbl_0806c058: .4byte 0x08754bb4
lbl_0806c05c: .4byte 0x06007000
lbl_0806c060: .4byte 0x06007800
lbl_0806c064:
    ldr r3, [r2]
    adds r1, r3, #0
    adds r1, #0x66
    ldr r0, lbl_0806c0a4 @ =0x00003844
    strh r0, [r1]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r1, [r2]
    movs r4, #0x80
    lsls r4, r4, #3
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
lbl_0806c084:
    ldr r4, lbl_0806c0a8 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0x68
    ldrh r0, [r0]
    movs r1, #4
    movs r2, #0
    bl sub_08068168
    cmp r0, #0
    bne lbl_0806c0c8
    ldr r1, [r4]
lbl_0806c09a:
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    b lbl_0806c0c8
    .align 2, 0
lbl_0806c0a4: .4byte 0x00003844
lbl_0806c0a8: .4byte 0x08754bc4
lbl_0806c0ac:
    movs r0, #1
    movs r1, #1
    bl sub_0806b00c
    ldr r2, lbl_0806c0c4 @ =0x08754bc4
    ldr r0, [r2]
    movs r1, #0
    strb r1, [r0, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    movs r0, #1
    b lbl_0806c0d4
    .align 2, 0
lbl_0806c0c4: .4byte 0x08754bc4
lbl_0806c0c8:
    ldr r0, lbl_0806c0dc @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    movs r0, #0
lbl_0806c0d4:
    add sp, #4
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806c0dc: .4byte 0x08754bc4

    thumb_func_start check_for_maintained_input
check_for_maintained_input: @ 0x0806c0e0
    push {r4, lr}
    ldr r1, lbl_0806c104 @ =0x03005804
    ldr r2, lbl_0806c108 @ =gChangedInput
    ldrh r0, [r2]
    strh r0, [r1]
    ldr r1, lbl_0806c10c @ =gButtonInput
    ldrh r0, [r1]
    movs r3, #0xf0
    ands r3, r0
    adds r4, r1, #0
    cmp r3, #0
    beq lbl_0806c114
    ldr r1, lbl_0806c110 @ =0x03005800
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r3, r1, #0
    b lbl_0806c11c
    .align 2, 0
lbl_0806c104: .4byte 0x03005804
lbl_0806c108: .4byte gChangedInput
lbl_0806c10c: .4byte gButtonInput
lbl_0806c110: .4byte 0x03005800
lbl_0806c114:
    ldr r0, lbl_0806c14c @ =0x03005800
    strb r3, [r0]
    strb r3, [r0, #1]
    adds r3, r0, #0
lbl_0806c11c:
    ldr r0, lbl_0806c150 @ =0x0840d66c
    ldrb r1, [r3, #1]
    adds r1, r1, r0
    ldrb r0, [r3]
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806c144
    ldrh r1, [r4]
    movs r0, #0xf0
    ands r0, r1
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
    movs r0, #0
    strb r0, [r3]
    ldrb r0, [r3, #1]
    cmp r0, #5
    bhi lbl_0806c144
    adds r0, #1
    strb r0, [r3, #1]
lbl_0806c144:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c14c: .4byte 0x03005800
lbl_0806c150: .4byte 0x0840d66c

    thumb_func_start update_minimap
update_minimap: @ 0x0806c154
    push {lr}
    bl check_for_unexplored_minimap_tile
    ldr r0, lbl_0806c174 @ =gUpdateMinimapFlag
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_0806c16a
    bl set_minimap_tile_explored
    bl update_minimap_for_explored_tiles
lbl_0806c16a:
    bl draw_minimap
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c174: .4byte gUpdateMinimapFlag

    thumb_func_start set_minimap_tile_explored
set_minimap_tile_explored: @ 0x0806c178
    push {lr}
    ldr r0, lbl_0806c1ac @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806c1a8
    ldr r0, lbl_0806c1b0 @ =gCurrentArea
    ldrb r2, [r0]
    ldr r0, lbl_0806c1b4 @ =gMinimapY
    lsls r2, r2, #5
    ldrb r0, [r0]
    adds r2, r2, r0
    ldr r0, lbl_0806c1b8 @ =0x08754bc0
    ldr r0, [r0]
    lsls r2, r2, #2
    adds r2, r2, r0
    ldr r1, lbl_0806c1bc @ =0x08760218
    ldr r0, lbl_0806c1c0 @ =gMinimapX
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2]
    ldr r0, [r0]
    orrs r1, r0
    str r1, [r2]
lbl_0806c1a8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c1ac: .4byte gShipLandingFlag
lbl_0806c1b0: .4byte gCurrentArea
lbl_0806c1b4: .4byte gMinimapY
lbl_0806c1b8: .4byte 0x08754bc0
lbl_0806c1bc: .4byte 0x08760218
lbl_0806c1c0: .4byte gMinimapX

    thumb_func_start sub_0806c1c4
sub_0806c1c4: @ 0x0806c1c4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    ldr r0, lbl_0806c21c @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806c1e0
    b lbl_0806c372
lbl_0806c1e0:
    ldr r0, lbl_0806c220 @ =gLastAreaNameVisited
    ldrb r1, [r0]
    mov ip, r0
    cmp r1, #0
    bne lbl_0806c1ec
    b lbl_0806c372
lbl_0806c1ec:
    movs r4, #0
    movs r6, #0
    ldr r0, [sp]
    cmp r0, #1
    bne lbl_0806c236
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0806c2a6
    movs r6, #0x7f
    ands r6, r1
    ldr r1, lbl_0806c224 @ =0x0840d684
    lsls r0, r6, #1
    adds r0, r0, r6
    lsls r0, r0, #2
    adds r3, r0, r1
    ldr r0, lbl_0806c228 @ =gAreaBeforeTransition
    ldrb r1, [r3]
    ldrb r2, [r0]
    cmp r1, r2
    bne lbl_0806c22c
    movs r4, #1
    b lbl_0806c2a6
    .align 2, 0
lbl_0806c21c: .4byte gShipLandingFlag
lbl_0806c220: .4byte gLastAreaNameVisited
lbl_0806c224: .4byte 0x0840d684
lbl_0806c228: .4byte gAreaBeforeTransition
lbl_0806c22c:
    ldrb r0, [r3, #5]
    cmp r0, r2
    bne lbl_0806c2a6
    movs r4, #2
    b lbl_0806c2a6
lbl_0806c236:
    ldr r1, lbl_0806c264 @ =0x0840d684
    mov r8, r1
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_0806c294
    mov r5, ip
    ldrb r2, [r5, #1]
    movs r3, #0
lbl_0806c246:
    ldrb r0, [r1]
    cmp r0, r2
    bne lbl_0806c268
    mov r7, ip
    ldrb r0, [r7, #2]
    ldrb r7, [r1, #1]
    cmp r0, r7
    bne lbl_0806c280
    ldrb r0, [r5, #3]
    ldrb r7, [r1, #2]
    cmp r0, r7
    bne lbl_0806c280
    movs r4, #1
    b lbl_0806c298
    .align 2, 0
lbl_0806c264: .4byte 0x0840d684
lbl_0806c268:
    ldrb r0, [r1, #5]
    cmp r0, r2
    bne lbl_0806c280
    ldrb r0, [r5, #2]
    ldrb r7, [r1, #6]
    cmp r0, r7
    bne lbl_0806c280
    ldrb r0, [r5, #3]
    ldrb r7, [r1, #7]
    cmp r0, r7
    bne lbl_0806c280
    movs r4, #2
lbl_0806c280:
    cmp r4, #0
    bne lbl_0806c298
    adds r3, #0xc
    adds r1, #0xc
    adds r6, #1
    mov r7, r8
    adds r0, r3, r7
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_0806c246
lbl_0806c294:
    cmp r4, #0
    beq lbl_0806c2a6
lbl_0806c298:
    movs r0, #0x80
    rsbs r0, r0, #0
    adds r1, r0, #0
    adds r0, r6, #0
    orrs r0, r1
    mov r1, ip
    strb r0, [r1]
lbl_0806c2a6:
    cmp r4, #1
    bne lbl_0806c2cc
    ldr r0, lbl_0806c2c8 @ =0x0840d684
    lsls r1, r6, #1
    adds r1, r1, r6
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r5, [r1]
    ldrb r3, [r1, #1]
    movs r0, #3
    ldrsb r0, [r1, r0]
    adds r0, r3, r0
    subs r4, r0, #1
    ldrb r2, [r1, #2]
    movs r0, #4
    ldrsb r0, [r1, r0]
    b lbl_0806c2f4
    .align 2, 0
lbl_0806c2c8: .4byte 0x0840d684
lbl_0806c2cc:
    cmp r4, #2
    beq lbl_0806c2d8
    movs r0, #0
    mov r1, ip
    strb r0, [r1]
    b lbl_0806c372
lbl_0806c2d8:
    ldr r0, lbl_0806c384 @ =0x0840d684
    lsls r1, r6, #1
    adds r1, r1, r6
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r5, [r1, #5]
    ldrb r3, [r1, #6]
    movs r0, #8
    ldrsb r0, [r1, r0]
    adds r0, r3, r0
    subs r4, r0, #1
    ldrb r2, [r1, #7]
    movs r0, #9
    ldrsb r0, [r1, r0]
lbl_0806c2f4:
    adds r0, r2, r0
    subs r1, r0, #1
    subs r3, #1
    mov r7, ip
    strb r3, [r7, #2]
    subs r2, #1
    strb r2, [r7, #3]
    lsls r0, r1, #5
    adds r0, r4, r0
    lsls r0, r0, #1
    ldr r2, lbl_0806c388 @ =0x02034800
    adds r3, r0, r2
    lsls r0, r5, #5
    adds r5, r0, r1
    movs r6, #0
    mov sl, r0
    ldr r1, lbl_0806c38c @ =0x08760218
    lsls r0, r4, #2
    adds r7, r0, r1
    ldr r0, lbl_0806c390 @ =0xfffffebf
    mov sb, r0
    ldr r1, lbl_0806c394 @ =0x08754bc0
    mov r8, r1
lbl_0806c322:
    ldrh r0, [r3]
    ldr r4, lbl_0806c398 @ =0x000003ff
    ands r4, r0
    mov r2, sb
    adds r0, r4, r2
    cmp r0, #0x1d
    bhi lbl_0806c348
    mov r1, r8
    ldr r0, [r1]
    lsls r2, r5, #2
    adds r2, r2, r0
    ldr r0, [r2]
    ldm r7!, {r1}
    orrs r0, r1
    str r0, [r2]
    adds r6, #1
    adds r3, #2
    cmp r6, #0x1f
    ble lbl_0806c322
lbl_0806c348:
    ldr r2, [sp]
    cmp r2, #0
    beq lbl_0806c372
    mov r3, ip
    ldrb r0, [r3, #3]
    mov r7, sl
    adds r5, r7, r0
    ldr r0, lbl_0806c394 @ =0x08754bc0
    ldr r0, [r0]
    lsls r2, r5, #2
    adds r2, r2, r0
    ldr r1, lbl_0806c38c @ =0x08760218
    ldrb r0, [r3, #2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2]
    ldr r0, [r0]
    orrs r1, r0
    str r1, [r2]
    movs r0, #0
    strb r0, [r3]
lbl_0806c372:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c384: .4byte 0x0840d684
lbl_0806c388: .4byte 0x02034800
lbl_0806c38c: .4byte 0x08760218
lbl_0806c390: .4byte 0xfffffebf
lbl_0806c394: .4byte 0x08754bc0
lbl_0806c398: .4byte 0x000003ff

    thumb_func_start check_for_unexplored_minimap_tile
check_for_unexplored_minimap_tile: @ 0x0806c39c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806c3cc @ =gUpdateMinimapFlag
    ldrb r1, [r0]
    adds r6, r0, #0
    cmp r1, #0
    bne lbl_0806c45c
    ldr r1, lbl_0806c3d0 @ =gSamusData
    ldrh r3, [r1, #0x12]
    adds r0, r3, #0
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldrh r0, [r1, #0x14]
    subs r0, #0x80
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r4
    cmp r0, #0
    beq lbl_0806c3d4
    movs r4, #0
    b lbl_0806c3ec
    .align 2, 0
lbl_0806c3cc: .4byte gUpdateMinimapFlag
lbl_0806c3d0: .4byte gSamusData
lbl_0806c3d4:
    ldr r0, lbl_0806c3fc @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0x1c]
    lsls r0, r0, #0x16
    movs r2, #0xff
    lsls r2, r2, #0x18
    adds r0, r0, r2
    lsrs r2, r0, #0x10
    cmp r3, r2
    blo lbl_0806c3ec
    subs r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
lbl_0806c3ec:
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r5
    cmp r0, #0
    beq lbl_0806c400
    movs r5, #0
    b lbl_0806c41a
    .align 2, 0
lbl_0806c3fc: .4byte gBGPointersAndDimensions
lbl_0806c400:
    ldr r0, lbl_0806c464 @ =gBGPointersAndDimensions
    ldrh r0, [r0, #0x1e]
    lsls r0, r0, #0x16
    movs r2, #0xff
    lsls r2, r2, #0x18
    adds r0, r0, r2
    lsrs r2, r0, #0x10
    ldrh r0, [r1, #0x14]
    cmp r0, r2
    blo lbl_0806c41a
    subs r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
lbl_0806c41a:
    lsrs r4, r4, #6
    lsrs r5, r5, #6
    adds r0, r4, #0
    movs r1, #0xf
    bl __udivsi3
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r0, r5, #0
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r2, lbl_0806c468 @ =gMinimapX
    ldrb r1, [r2]
    ldr r3, lbl_0806c46c @ =gCurrentRoomEntry
    ldrb r0, [r3, #0xe]
    adds r0, r4, r0
    cmp r1, r0
    beq lbl_0806c44a
    strb r0, [r2]
    movs r0, #3
    strb r0, [r6]
lbl_0806c44a:
    ldr r2, lbl_0806c470 @ =gMinimapY
    ldrb r1, [r2]
    ldrb r0, [r3, #0xf]
    adds r0, r5, r0
    cmp r1, r0
    beq lbl_0806c45c
    strb r0, [r2]
    movs r0, #3
    strb r0, [r6]
lbl_0806c45c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c464: .4byte gBGPointersAndDimensions
lbl_0806c468: .4byte gMinimapX
lbl_0806c46c: .4byte gCurrentRoomEntry
lbl_0806c470: .4byte gMinimapY

    thumb_func_start MinimapCheckOnTransition
MinimapCheckOnTransition: @ 0x0806c474
    push {r4, r5, lr}
    ldr r5, lbl_0806c4f4 @ =gAreaBeforeTransition
    ldr r4, lbl_0806c4f8 @ =gCurrentArea
    ldrb r0, [r5]
    ldrb r1, [r4]
    cmp r0, r1
    beq lbl_0806c4bc
    movs r0, #0
    bl sub_0806c1c4
    ldrb r0, [r4]
    strb r0, [r5]
    ldrb r0, [r5]
    ldr r4, lbl_0806c4fc @ =0x02034800
    adds r1, r4, #0
    bl get_minimap_data
    ldr r1, lbl_0806c500 @ =0x040000d4
    str r4, [r1]
    ldr r4, lbl_0806c504 @ =0x02034000
    str r4, [r1, #4]
    ldr r0, lbl_0806c508 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #1
    bl sub_0806c1c4
    ldrb r0, [r5]
    adds r1, r4, #0
    bl minimap_set_downloaded_tiles
    ldr r0, lbl_0806c50c @ =gMinimapX
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, lbl_0806c510 @ =gMinimapY
    strb r1, [r0]
lbl_0806c4bc:
    ldr r4, lbl_0806c514 @ =gUpdateMinimapFlag
    movs r0, #0
    strb r0, [r4]
    bl check_for_unexplored_minimap_tile
    ldrb r0, [r4]
    cmp r0, #3
    bne lbl_0806c4d4
    bl set_minimap_tile_explored
    bl update_minimap_for_explored_tiles
lbl_0806c4d4:
    movs r0, #1
    strb r0, [r4]
    bl draw_minimap
    movs r0, #2
    strb r0, [r4]
    bl draw_minimap
    movs r0, #3
    strb r0, [r4]
    bl draw_minimap
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c4f4: .4byte gAreaBeforeTransition
lbl_0806c4f8: .4byte gCurrentArea
lbl_0806c4fc: .4byte 0x02034800
lbl_0806c500: .4byte 0x040000d4
lbl_0806c504: .4byte 0x02034000
lbl_0806c508: .4byte 0x80000400
lbl_0806c50c: .4byte gMinimapX
lbl_0806c510: .4byte gMinimapY
lbl_0806c514: .4byte gUpdateMinimapFlag

    thumb_func_start update_minimap_for_explored_tiles
update_minimap_for_explored_tiles: @ 0x0806c518
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0806c558 @ =gShipLandingFlag
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806c59c
    ldr r2, lbl_0806c55c @ =gMinimapX
    ldr r3, lbl_0806c560 @ =gMinimapY
    ldrb r0, [r3]
    lsls r0, r0, #5
    ldrb r1, [r2]
    adds r0, r0, r1
    lsls r5, r0, #1
    ldr r0, lbl_0806c564 @ =0x02034000
    adds r4, r5, r0
    ldrh r1, [r4]
    movs r6, #0xf0
    lsls r6, r6, #8
    adds r0, r6, #0
    ands r0, r1
    adds r7, r2, #0
    cmp r0, #0
    bne lbl_0806c59c
    ldr r1, lbl_0806c568 @ =0x02034800
    adds r2, r5, r1
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806c56c
    strh r1, [r4]
    b lbl_0806c576
    .align 2, 0
lbl_0806c558: .4byte gShipLandingFlag
lbl_0806c55c: .4byte gMinimapX
lbl_0806c560: .4byte gMinimapY
lbl_0806c564: .4byte 0x02034000
lbl_0806c568: .4byte 0x02034800
lbl_0806c56c:
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    strh r0, [r4]
lbl_0806c576:
    ldrh r1, [r2]
    ldr r0, lbl_0806c5a4 @ =0x000003ff
    ands r0, r1
    ldr r1, lbl_0806c5a8 @ =0xfffffebf
    adds r0, r0, r1
    cmp r0, #3
    bhi lbl_0806c59c
    ldr r1, lbl_0806c5ac @ =gLastAreaNameVisited
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0806c5b0 @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r1, #1]
    ldrb r0, [r7]
    adds r0, #1
    strb r0, [r1, #2]
    ldrb r0, [r3]
    adds r0, #1
    strb r0, [r1, #3]
lbl_0806c59c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c5a4: .4byte 0x000003ff
lbl_0806c5a8: .4byte 0xfffffebf
lbl_0806c5ac: .4byte gLastAreaNameVisited
lbl_0806c5b0: .4byte gCurrentArea

    thumb_func_start draw_minimap
draw_minimap: @ 0x0806c5b4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r3, lbl_0806c5e4 @ =gUpdateMinimapFlag
    ldrb r0, [r3]
    cmp r0, #0
    beq lbl_0806c690
    ldr r0, lbl_0806c5e8 @ =0x02034000
    mov r8, r0
    ldrb r2, [r3]
    subs r1, r2, #1
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_0806c5ec @ =0x02037e20
    adds r6, r0, r1
    cmp r2, #3
    bne lbl_0806c5f0
    movs r7, #1
    mov sb, r7
    b lbl_0806c60a
    .align 2, 0
lbl_0806c5e4: .4byte gUpdateMinimapFlag
lbl_0806c5e8: .4byte 0x02034000
lbl_0806c5ec: .4byte 0x02037e20
lbl_0806c5f0:
    cmp r2, #2
    bne lbl_0806c5fa
    movs r0, #0
    mov sb, r0
    b lbl_0806c60a
lbl_0806c5fa:
    cmp r2, #1
    beq lbl_0806c604
    movs r0, #0
    strb r0, [r3]
    b lbl_0806c690
lbl_0806c604:
    movs r1, #1
    rsbs r1, r1, #0
    mov sb, r1
lbl_0806c60a:
    movs r5, #1
    rsbs r5, r5, #0
    mov r4, sp
lbl_0806c610:
    ldr r0, lbl_0806c6a0 @ =gMinimapX
    ldrb r0, [r0]
    adds r1, r0, r5
    cmp r1, #0x1f
    bls lbl_0806c61e
    movs r1, #1
    rsbs r1, r1, #0
lbl_0806c61e:
    ldr r0, lbl_0806c6a4 @ =gMinimapY
    ldrb r0, [r0]
    add r0, sb
    cmp r0, #0x1f
    bls lbl_0806c62c
    movs r0, #1
    rsbs r0, r0, #0
lbl_0806c62c:
    cmp r0, #0
    blt lbl_0806c634
    cmp r1, #0
    bge lbl_0806c638
lbl_0806c634:
    movs r1, #0x1f
    movs r0, #0x1f
lbl_0806c638:
    lsls r0, r0, #5
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, r8
    movs r7, #0xc0
    lsls r7, r7, #4
    adds r2, r7, #0
    ldrh r1, [r0]
    adds r0, r1, #0
    ands r0, r2
    lsrs r3, r0, #0xa
    lsrs r2, r1, #0xc
    ldr r7, lbl_0806c6a8 @ =0x000003ff
    adds r0, r7, #0
    ands r1, r0
    strh r1, [r4]
    ldr r0, lbl_0806c6ac @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0806c672
    movs r0, #0xa0
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_0806c672
    adds r0, r1, #0
    adds r0, #0x20
    strh r0, [r4]
lbl_0806c672:
    ldrh r0, [r4]
    lsls r0, r0, #5
    strh r0, [r4]
    ldr r1, lbl_0806c6b0 @ =0x08760298
    lsls r0, r3, #2
    adds r0, r0, r1
    ldr r3, [r0]
    adds r0, r6, #0
    mov r1, sp
    bl _call_via_r3
    adds r5, #1
    adds r6, #0x20
    cmp r5, #1
    ble lbl_0806c610
lbl_0806c690:
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c6a0: .4byte gMinimapX
lbl_0806c6a4: .4byte gMinimapY
lbl_0806c6a8: .4byte 0x000003ff
lbl_0806c6ac: .4byte gLanguage
lbl_0806c6b0: .4byte 0x08760298

    thumb_func_start sub_0806c6b4
sub_0806c6b4: @ 0x0806c6b4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldr r0, lbl_0806c780 @ =0x0840e0c4
    mov r8, r0
    ldr r1, lbl_0806c784 @ =0x0840d74c
    mov ip, r1
    lsrs r4, r2, #0x14
    ldr r7, lbl_0806c788 @ =0x0840d6fc
    movs r6, #0xf
    movs r0, #7
    mov sb, r0
lbl_0806c6d6:
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r3, [r0]
    orrs r3, r1
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #8
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x10
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    ldrh r2, [r5]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r4
    add r1, ip
    ands r0, r6
    adds r0, r0, r4
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x18
    orrs r3, r0
    adds r2, #1
    strh r2, [r5]
    mov r0, sl
    adds r0, #4
    mov sl, r0
    subs r0, #4
    stm r0!, {r3}
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    mov r0, sb
    cmp r0, #0
    bge lbl_0806c6d6
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c780: .4byte 0x0840e0c4
lbl_0806c784: .4byte 0x0840d74c
lbl_0806c788: .4byte 0x0840d6fc

    thumb_func_start sub_0806c78c
sub_0806c78c: @ 0x0806c78c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    str r0, [sp]
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldr r0, lbl_0806c86c @ =0x0840e0c4
    mov sb, r0
    ldr r1, lbl_0806c870 @ =0x0840d74c
    mov r8, r1
    movs r3, #0xf
    mov ip, r3
    lsrs r6, r2, #0x14
    ldr r7, lbl_0806c874 @ =0x0840d6fc
    movs r0, #7
    mov sl, r0
lbl_0806c7b2:
    ldrh r0, [r5]
    adds r0, #3
    strh r0, [r5]
    ldrh r2, [r5]
    mov r1, sb
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r3, ip
    ands r0, r3
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r0, [r0]
    ldrb r4, [r1]
    orrs r4, r0
    subs r2, #1
    strh r2, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #8
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x10
    orrs r4, r0
    subs r0, r3, #1
    strh r0, [r5]
    ldrh r0, [r5]
    add r0, sb
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x18
    orrs r4, r0
    ldr r0, [sp]
    stm r0!, {r4}
    str r0, [sp]
    adds r3, #3
    strh r3, [r5]
    movs r1, #1
    rsbs r1, r1, #0
    add sl, r1
    mov r2, sl
    cmp r2, #0
    bge lbl_0806c7b2
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c86c: .4byte 0x0840e0c4
lbl_0806c870: .4byte 0x0840d74c
lbl_0806c874: .4byte 0x0840d6fc

    thumb_func_start sub_0806c878
sub_0806c878: @ 0x0806c878
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    ldrh r0, [r4]
    adds r0, #0x1c
    strh r0, [r4]
    ldr r0, lbl_0806c948 @ =0x0840e0c4
    mov r8, r0
    ldr r1, lbl_0806c94c @ =0x0840d74c
    mov ip, r1
    lsrs r5, r2, #0x14
    ldr r7, lbl_0806c950 @ =0x0840d6fc
    movs r6, #0xf
    movs r0, #7
    mov sb, r0
lbl_0806c8a0:
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r3, [r0]
    orrs r3, r1
    adds r2, #1
    strh r2, [r4]
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #8
    orrs r3, r0
    adds r2, #1
    strh r2, [r4]
    ldrh r2, [r4]
    mov r1, r8
    adds r0, r2, r1
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x10
    orrs r3, r0
    adds r0, r2, #1
    strh r0, [r4]
    ldrh r0, [r4]
    add r0, r8
    ldrb r0, [r0]
    lsrs r1, r0, #4
    adds r1, r1, r5
    add r1, ip
    ands r0, r6
    adds r0, r0, r5
    adds r0, r0, r7
    ldrb r1, [r1]
    ldrb r0, [r0]
    orrs r0, r1
    lsls r0, r0, #0x18
    orrs r3, r0
    mov r0, sl
    adds r0, #4
    mov sl, r0
    subs r0, #4
    stm r0!, {r3}
    subs r2, #6
    strh r2, [r4]
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    mov r0, sb
    cmp r0, #0
    bge lbl_0806c8a0
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806c948: .4byte 0x0840e0c4
lbl_0806c94c: .4byte 0x0840d74c
lbl_0806c950: .4byte 0x0840d6fc

    thumb_func_start sub_0806c954
sub_0806c954: @ 0x0806c954
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    str r0, [sp]
    adds r5, r1, #0
    lsls r2, r2, #0x18
    ldrh r0, [r5]
    adds r0, #0x1f
    strh r0, [r5]
    ldr r0, lbl_0806ca38 @ =0x0840e0c4
    mov sb, r0
    ldr r1, lbl_0806ca3c @ =0x0840d74c
    mov r8, r1
    movs r3, #0xf
    mov ip, r3
    lsrs r6, r2, #0x14
    ldr r7, lbl_0806ca40 @ =0x0840d6fc
    movs r0, #7
    mov sl, r0
lbl_0806c980:
    ldrh r2, [r5]
    mov r1, sb
    adds r0, r2, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r3, ip
    ands r0, r3
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r0, [r0]
    ldrb r4, [r1]
    orrs r4, r0
    subs r2, #1
    strh r2, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #8
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x10
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldrh r3, [r5]
    mov r1, sb
    adds r0, r3, r1
    ldrb r1, [r0]
    adds r0, r1, #0
    mov r2, ip
    ands r0, r2
    adds r0, r0, r6
    add r0, r8
    lsrs r1, r1, #4
    adds r1, r1, r6
    adds r1, r1, r7
    ldrb r2, [r0]
    ldrb r0, [r1]
    orrs r0, r2
    lsls r0, r0, #0x18
    orrs r4, r0
    subs r3, #1
    strh r3, [r5]
    ldr r3, [sp]
    stm r3!, {r4}
    str r3, [sp]
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    mov r1, sl
    cmp r1, #0
    bge lbl_0806c980
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806ca38: .4byte 0x0840e0c4
lbl_0806ca3c: .4byte 0x0840d74c
lbl_0806ca40: .4byte 0x0840d6fc

    thumb_func_start set_tiles_with_obtained_items
set_tiles_with_obtained_items: @ 0x0806ca44
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    mov ip, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_0806ca9e
    lsls r0, r0, #7
    ldr r1, lbl_0806caa8 @ =0x02033800
    adds r2, r0, r1
    movs r3, #0
    ldr r0, lbl_0806caac @ =0x08760218
    mov r8, r0
lbl_0806ca60:
    ldm r2!, {r0}
    adds r6, r3, #1
    adds r7, r2, #0
    cmp r0, #0
    beq lbl_0806ca96
    adds r4, r0, #0
    movs r5, #0
    lsls r0, r3, #6
    mov r1, ip
    adds r3, r0, r1
    mov r1, r8
lbl_0806ca76:
    ldr r2, [r1]
    adds r0, r4, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ca88
    eors r4, r2
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
lbl_0806ca88:
    adds r3, #2
    adds r1, #4
    adds r5, #1
    cmp r5, #0x1f
    bgt lbl_0806ca96
    cmp r4, #0
    bne lbl_0806ca76
lbl_0806ca96:
    adds r3, r6, #0
    adds r2, r7, #0
    cmp r3, #0x1f
    ble lbl_0806ca60
lbl_0806ca9e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806caa8: .4byte 0x02033800
lbl_0806caac: .4byte 0x08760218

    thumb_func_start minimap_set_downloaded_tiles
minimap_set_downloaded_tiles: @ 0x0806cab0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r2, r1, #0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r0, lbl_0806cb24 @ =0x08754bc0
    lsls r1, r4, #7
    ldr r0, [r0]
    adds r3, r0, r1
    ldr r0, lbl_0806cb28 @ =gEquipment
    ldrb r0, [r0, #0x10]
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cae4
    adds r0, r4, #0
    subs r0, #8
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bhi lbl_0806cb68
lbl_0806cae4:
    movs r1, #0
    movs r0, #0xf0
    lsls r0, r0, #8
    mov sl, r0
    ldr r5, lbl_0806cb2c @ =0x00002fff
    mov r8, r5
    movs r0, #0xc0
    lsls r0, r0, #6
    mov sb, r0
    ldr r5, lbl_0806cb30 @ =0x00000fff
    mov ip, r5
lbl_0806cafa:
    ldm r3!, {r0}
    adds r6, r1, #1
    adds r7, r3, #0
    str r0, [sp]
    ldr r3, lbl_0806cb34 @ =0x08760218
    movs r4, #0x1f
lbl_0806cb06:
    ldr r0, [r3]
    ldr r1, [sp]
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cb38
    ldrh r1, [r2]
    mov r0, sl
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cb54
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    b lbl_0806cb52
    .align 2, 0
lbl_0806cb24: .4byte 0x08754bc0
lbl_0806cb28: .4byte gEquipment
lbl_0806cb2c: .4byte 0x00002fff
lbl_0806cb30: .4byte 0x00000fff
lbl_0806cb34: .4byte 0x08760218
lbl_0806cb38:
    ldrh r1, [r2]
    cmp r1, r8
    bls lbl_0806cb46
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r1, #0
    b lbl_0806cb52
lbl_0806cb46:
    mov r0, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cb54
    mov r0, ip
    ands r0, r1
lbl_0806cb52:
    strh r0, [r2]
lbl_0806cb54:
    adds r3, #4
    subs r4, #1
    adds r2, #2
    cmp r4, #0
    bge lbl_0806cb06
    adds r1, r6, #0
    adds r3, r7, #0
    cmp r1, #0x1f
    ble lbl_0806cafa
    b lbl_0806cbc8
lbl_0806cb68:
    movs r1, #0
    ldr r5, lbl_0806cba0 @ =0x08760218
    mov r8, r5
    movs r0, #0xf0
    lsls r0, r0, #8
    mov ip, r0
lbl_0806cb74:
    ldm r3!, {r0}
    adds r6, r1, #1
    adds r7, r3, #0
    mov sb, r0
    mov r3, r8
    movs r4, #0x1f
lbl_0806cb80:
    ldr r0, [r3]
    mov r1, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cba4
    ldrh r1, [r2]
    mov r0, ip
    ands r0, r1
    cmp r0, #0
    bne lbl_0806cbb6
    movs r5, #0x80
    lsls r5, r5, #5
    adds r0, r5, #0
    orrs r0, r1
    b lbl_0806cbb4
    .align 2, 0
lbl_0806cba0: .4byte 0x08760218
lbl_0806cba4:
    ldrh r1, [r2]
    mov r0, ip
    ands r0, r1
    cmp r0, #0
    beq lbl_0806cbb6
    movs r1, #0xa0
    lsls r1, r1, #1
    adds r0, r1, #0
lbl_0806cbb4:
    strh r0, [r2]
lbl_0806cbb6:
    adds r3, #4
    subs r4, #1
    adds r2, #2
    cmp r4, #0
    bge lbl_0806cb80
    adds r1, r6, #0
    adds r3, r7, #0
    cmp r1, #0x1f
    ble lbl_0806cb74
lbl_0806cbc8:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start update_minimap_square_for_collected_item
update_minimap_square_for_collected_item: @ 0x0806cbd8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    ldr r7, lbl_0806cc4c @ =gCurrentArea
    ldrb r0, [r7]
    cmp r0, #7
    bhi lbl_0806cc44
    subs r0, r2, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldr r5, lbl_0806cc50 @ =gCurrentRoomEntry
    ldrb r0, [r5, #0xe]
    adds r4, r4, r0
    subs r0, r6, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r1, [r5, #0xf]
    adds r0, r0, r1
    ldrb r1, [r7]
    lsls r1, r1, #7
    ldr r2, lbl_0806cc54 @ =0x02033800
    adds r1, r1, r2
    lsls r3, r0, #2
    adds r3, r3, r1
    ldr r2, lbl_0806cc58 @ =0x08760218
    lsls r1, r4, #2
    adds r1, r1, r2
    ldr r2, [r3]
    ldr r1, [r1]
    orrs r2, r1
    str r2, [r3]
    lsls r0, r0, #5
    adds r4, r4, r0
    lsls r4, r4, #1
    ldr r0, lbl_0806cc5c @ =0x02034000
    adds r1, r4, r0
    ldrh r0, [r1]
    adds r0, #1
    strh r0, [r1]
    ldr r2, lbl_0806cc60 @ =0x02034800
    adds r4, r4, r2
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    ldr r1, lbl_0806cc64 @ =gUpdateMinimapFlag
    movs r0, #3
    strb r0, [r1]
    bl draw_minimap
lbl_0806cc44:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cc4c: .4byte gCurrentArea
lbl_0806cc50: .4byte gCurrentRoomEntry
lbl_0806cc54: .4byte 0x02033800
lbl_0806cc58: .4byte 0x08760218
lbl_0806cc5c: .4byte 0x02034000
lbl_0806cc60: .4byte 0x02034800
lbl_0806cc64: .4byte gUpdateMinimapFlag

    thumb_func_start sub_0806cc68
sub_0806cc68: @ 0x0806cc68
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    ldr r1, lbl_0806ccb4 @ =gCurrentArea
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0806ccc4
    adds r5, r0, #0
    lsls r5, r5, #5
    subs r0, r2, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldr r6, lbl_0806ccb8 @ =gCurrentRoomEntry
    ldrb r0, [r6, #0xe]
    adds r4, r4, r0
    subs r0, r7, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r1, [r6, #0xf]
    adds r0, r0, r1
    adds r0, r0, r5
    ldr r1, lbl_0806ccbc @ =0x08754bc0
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, lbl_0806ccc0 @ =0x08760218
    lsls r4, r4, #2
    adds r4, r4, r1
    ldr r0, [r0]
    ldr r1, [r4]
    ands r0, r1
    b lbl_0806ccc6
    .align 2, 0
lbl_0806ccb4: .4byte gCurrentArea
lbl_0806ccb8: .4byte gCurrentRoomEntry
lbl_0806ccbc: .4byte 0x08754bc0
lbl_0806ccc0: .4byte 0x08760218
lbl_0806ccc4:
    movs r0, #1
lbl_0806ccc6:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start load_minimap_tiles_with_obtained_items
load_minimap_tiles_with_obtained_items: @ 0x0806cccc
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    ldr r2, lbl_0806cd74 @ =0x02033800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    movs r2, #0
lbl_0806ccea:
    lsls r0, r2, #8
    ldr r1, lbl_0806cd78 @ =0x02036c00
    adds r5, r0, r1
    lsls r0, r2, #7
    ldr r1, lbl_0806cd74 @ =0x02033800
    adds r1, r1, r0
    mov r8, r1
    movs r6, #0
    ldrb r0, [r5]
    adds r1, r2, #1
    mov sb, r1
    cmp r0, #0xff
    beq lbl_0806cd5a
    ldr r1, lbl_0806cd7c @ =0x0875fac4
    lsls r0, r2, #2
    adds r0, r0, r1
    ldr r7, [r0]
lbl_0806cd0c:
    ldrb r0, [r5, #2]
    subs r0, #2
    movs r1, #0xf
    bl __divsi3
    adds r4, r0, #0
    ldrb r0, [r5, #3]
    subs r0, #2
    movs r1, #0xa
    bl __divsi3
    ldrb r2, [r5]
    lsls r1, r2, #4
    subs r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r7
    adds r2, r1, #0
    adds r2, #0x35
    ldrb r2, [r2]
    adds r4, r4, r2
    adds r1, #0x36
    ldrb r1, [r1]
    adds r0, r0, r1
    lsls r0, r0, #2
    add r0, r8
    ldr r1, lbl_0806cd80 @ =0x08760218
    lsls r4, r4, #2
    adds r4, r4, r1
    ldr r1, [r0]
    ldr r2, [r4]
    orrs r1, r2
    str r1, [r0]
    adds r6, #1
    adds r5, #4
    cmp r6, #0x3f
    bgt lbl_0806cd5a
    ldrb r0, [r5]
    cmp r0, #0xff
    bne lbl_0806cd0c
lbl_0806cd5a:
    mov r1, sb
    lsls r0, r1, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #7
    bls lbl_0806ccea
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cd74: .4byte 0x02033800
lbl_0806cd78: .4byte 0x02036c00
lbl_0806cd7c: .4byte 0x0875fac4
lbl_0806cd80: .4byte 0x08760218

    thumb_func_start MinimapUpdateChunk
MinimapUpdateChunk: @ 0x0806cd84
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r4, #0
    ldr r0, lbl_0806ce14 @ =0x0840d200
    adds r1, r0, #0
    ldrb r0, [r1]
    cmp r2, r0
    beq lbl_0806cda6
    adds r0, r1, #0
lbl_0806cd98:
    adds r0, #5
    adds r4, #1
    cmp r4, #6
    bhi lbl_0806cda6
    ldrb r3, [r0]
    cmp r2, r3
    bne lbl_0806cd98
lbl_0806cda6:
    cmp r4, #6
    ble lbl_0806cdac
    b lbl_0806ceec
lbl_0806cdac:
    ldr r0, lbl_0806ce18 @ =gCurrentArea
    ldrb r3, [r0]
    cmp r4, r3
    beq lbl_0806cdb6
    b lbl_0806ceec
lbl_0806cdb6:
    lsls r2, r4, #2
    adds r2, r2, r4
    adds r0, r1, #3
    adds r0, r2, r0
    ldrb r0, [r0]
    adds r1, #2
    adds r2, r2, r1
    lsls r0, r0, #5
    ldrb r2, [r2]
    adds r4, r0, r2
    lsls r0, r4, #1
    ldr r1, lbl_0806ce1c @ =0x02034800
    adds r5, r0, r1
    ldr r1, lbl_0806ce20 @ =0x02034000
    adds r6, r0, r1
    adds r0, r3, #0
    cmp r0, #5
    bne lbl_0806ce2c
    ldrh r0, [r5]
    ldr r1, lbl_0806ce24 @ =0x000003ff
    ldr r2, lbl_0806ce28 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2, #4]
    cmp r1, r2
    beq lbl_0806cdea
    b lbl_0806ceec
lbl_0806cdea:
    movs r7, #0xf0
    lsls r7, r7, #8
    adds r1, r6, #0
    adds r3, r5, #0
    movs r4, #2
lbl_0806cdf4:
    ldrh r0, [r3]
    adds r0, #1
    strh r0, [r3]
    ldrh r2, [r1]
    adds r0, r7, #0
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ce08
    adds r0, r2, #1
    strh r0, [r1]
lbl_0806ce08:
    adds r1, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806cdf4
    b lbl_0806cee2
    .align 2, 0
lbl_0806ce14: .4byte 0x0840d200
lbl_0806ce18: .4byte gCurrentArea
lbl_0806ce1c: .4byte 0x02034800
lbl_0806ce20: .4byte 0x02034000
lbl_0806ce24: .4byte 0x000003ff
lbl_0806ce28: .4byte 0x0840d224
lbl_0806ce2c:
    cmp r0, #1
    bne lbl_0806ce84
    ldrh r0, [r5]
    ldr r1, lbl_0806ce7c @ =0x000003ff
    ldr r2, lbl_0806ce80 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2]
    cmp r1, r2
    bne lbl_0806ceec
    adds r3, r6, #0
    adds r2, r5, #0
    movs r4, #1
lbl_0806ce44:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce44
    adds r3, r6, #0
    adds r3, #0x40
    adds r2, r5, #0
    adds r2, #0x40
    movs r4, #1
lbl_0806ce64:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce64
    b lbl_0806cee2
    .align 2, 0
lbl_0806ce7c: .4byte 0x000003ff
lbl_0806ce80: .4byte 0x0840d224
lbl_0806ce84:
    cmp r0, #3
    bne lbl_0806cede
    ldrh r0, [r5]
    ldr r1, lbl_0806ced4 @ =0x000003ff
    ldr r2, lbl_0806ced8 @ =0x0840d224
    ands r1, r0
    ldrh r2, [r2, #2]
    cmp r1, r2
    bne lbl_0806cedc
    adds r3, r6, #0
    adds r2, r5, #0
    movs r4, #1
lbl_0806ce9c:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806ce9c
    adds r3, r6, #0
    adds r3, #0x40
    adds r2, r5, #0
    adds r2, #0x40
    movs r4, #1
lbl_0806cebc:
    ldrh r0, [r2]
    adds r0, #0x20
    strh r0, [r2]
    ldrh r0, [r3]
    adds r0, #0x20
    strh r0, [r3]
    adds r3, #2
    adds r2, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_0806cebc
    b lbl_0806cee2
    .align 2, 0
lbl_0806ced4: .4byte 0x000003ff
lbl_0806ced8: .4byte 0x0840d224
lbl_0806cedc:
    movs r4, #1
lbl_0806cede:
    cmp r4, #0
    bne lbl_0806ceec
lbl_0806cee2:
    ldr r1, lbl_0806cef4 @ =gUpdateMinimapFlag
    movs r0, #3
    strb r0, [r1]
    bl draw_minimap
lbl_0806ceec:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806cef4: .4byte gUpdateMinimapFlag

    thumb_func_start count_tanks_in_area
count_tanks_in_area: @ 0x0806cef8
    push {r4, r5, lr}
    ldr r1, lbl_0806cf3c @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0x36
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0x38
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0x3a
    strb r2, [r0]
    ldr r0, [r1]
    adds r0, #0x3c
    strb r2, [r0]
    ldr r0, lbl_0806cf40 @ =gCurrentArea
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #7
    bls lbl_0806cf44
    ldr r0, [r5]
    adds r0, #0x35
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x37
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x39
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x3b
    strb r2, [r0]
    b lbl_0806cfd8
    .align 2, 0
lbl_0806cf3c: .4byte 0x08754bc4
lbl_0806cf40: .4byte gCurrentArea
lbl_0806cf44:
    ldr r1, [r5]
    ldr r2, lbl_0806cfa0 @ =0x083459a0
    ldrb r0, [r1, #0x12]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r0, [r0]
    adds r1, #0x35
    strb r0, [r1]
    ldr r1, [r5]
    ldrb r0, [r1, #0x12]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r0, [r0, #1]
    adds r1, #0x37
    strb r0, [r1]
    ldr r1, [r5]
    ldrb r0, [r1, #0x12]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r0, [r0, #2]
    adds r1, #0x39
    strb r0, [r1]
    ldr r1, [r5]
    ldrb r0, [r1, #0x12]
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r0, [r0, #3]
    adds r1, #0x3b
    strb r0, [r1]
    ldr r0, [r5]
    ldrb r0, [r0, #0x12]
    lsls r0, r0, #8
    ldr r1, lbl_0806cfa4 @ =0x02036c00
    adds r2, r0, r1
    movs r4, #0
    ldrb r0, [r2]
    cmp r0, #0xff
    beq lbl_0806cfd8
    adds r3, r5, #0
lbl_0806cf92:
    ldrb r0, [r2, #1]
    cmp r0, #1
    bne lbl_0806cfa8
    ldr r1, [r3]
    adds r1, #0x38
    b lbl_0806cfc4
    .align 2, 0
lbl_0806cfa0: .4byte 0x083459a0
lbl_0806cfa4: .4byte 0x02036c00
lbl_0806cfa8:
    cmp r0, #2
    bne lbl_0806cfb2
    ldr r1, [r3]
    adds r1, #0x36
    b lbl_0806cfc4
lbl_0806cfb2:
    cmp r0, #3
    bne lbl_0806cfbc
    ldr r1, [r3]
    adds r1, #0x3a
    b lbl_0806cfc4
lbl_0806cfbc:
    cmp r0, #4
    bne lbl_0806cfca
    ldr r1, [r3]
    adds r1, #0x3c
lbl_0806cfc4:
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806cfca:
    adds r4, #1
    adds r2, #4
    cmp r4, #0x3f
    bgt lbl_0806cfd8
    ldrb r0, [r2]
    cmp r0, #0xff
    bne lbl_0806cf92
lbl_0806cfd8:
    adds r3, r5, #0
    ldr r0, [r3]
    adds r0, #0x3d
    movs r1, #0
    strb r1, [r0]
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x36
    adds r2, r1, #0
    adds r2, #0x35
    ldrb r0, [r0]
    ldrb r2, [r2]
    cmp r0, r2
    blo lbl_0806d000
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_0806d000:
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x38
    adds r2, r1, #0
    adds r2, #0x37
    ldrb r0, [r0]
    ldrb r2, [r2]
    cmp r0, r2
    blo lbl_0806d01e
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r1, [r0]
    movs r2, #2
    orrs r1, r2
    strb r1, [r0]
lbl_0806d01e:
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x3a
    adds r2, r1, #0
    adds r2, #0x39
    ldrb r0, [r0]
    ldrb r2, [r2]
    cmp r0, r2
    blo lbl_0806d03c
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r1, [r0]
    movs r2, #4
    orrs r1, r2
    strb r1, [r0]
lbl_0806d03c:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x3c
    adds r2, r1, #0
    adds r2, #0x3b
    ldrb r0, [r0]
    ldrb r2, [r2]
    cmp r0, r2
    blo lbl_0806d05a
    adds r0, r1, #0
    adds r0, #0x3d
    ldrb r1, [r0]
    movs r2, #8
    orrs r1, r2
    strb r1, [r0]
lbl_0806d05a:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start draw_in_game_time_and_tanks
draw_in_game_time_and_tanks: @ 0x0806d060
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    cmp r1, #0
    beq lbl_0806d076
    b lbl_0806d1e8
lbl_0806d076:
    cmp r0, #0
    beq lbl_0806d0a0
    ldr r0, lbl_0806d090 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r0, #0
    adds r1, #0x34
    ldrb r0, [r1]
    cmp r0, #1
    bne lbl_0806d094
    movs r0, #2
    strb r0, [r1]
    b lbl_0806d0aa
    .align 2, 0
lbl_0806d090: .4byte 0x08754bc4
lbl_0806d094:
    cmp r0, #2
    beq lbl_0806d09a
    b lbl_0806d324
lbl_0806d09a:
    movs r0, #1
    strb r0, [r1]
    b lbl_0806d0aa
lbl_0806d0a0:
    ldr r0, lbl_0806d1d4 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x34
    movs r1, #2
    strb r1, [r0]
lbl_0806d0aa:
    ldr r5, lbl_0806d1d8 @ =gInGameTimer
    ldrb r0, [r5]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    ldr r4, lbl_0806d1dc @ =0x06017ea0
    adds r1, r1, r4
    ldr r0, lbl_0806d1e0 @ =0x0840d79c
    mov sb, r0
    ldr r6, [r0, #0x10]
    movs r7, #0x20
    str r7, [sp]
    movs r0, #3
    adds r2, r6, #0
    movs r3, #0x20
    bl DMATransfer
    ldrb r0, [r5]
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    adds r1, r1, r4
    adds r2, r6, #0
    adds r2, #0x20
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    ldrb r0, [r5, #1]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    adds r1, r1, r4
    adds r2, r6, #0
    adds r2, #0x60
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    ldrb r0, [r5, #1]
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    adds r1, r1, r4
    adds r2, r6, #0
    adds r2, #0x80
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    ldrb r0, [r5, #2]
    movs r1, #0xa
    bl __udivsi3
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    adds r1, r1, r4
    adds r2, r6, #0
    adds r2, #0xc0
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    ldrb r0, [r5, #2]
    movs r1, #0xa
    bl __umodsi3
    adds r1, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x13
    adds r1, r1, r4
    adds r2, r6, #0
    adds r2, #0xe0
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    ldr r1, lbl_0806d1d4 @ =0x08754bc4
    mov r8, r1
    ldr r0, [r1]
    adds r0, #0x36
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d198
    movs r0, #0x10
lbl_0806d198:
    lsls r1, r0, #5
    ldr r6, lbl_0806d1e4 @ =0x06017c00
    adds r1, r1, r6
    mov r0, sb
    ldr r5, [r0]
    str r7, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x35
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d1be
    movs r0, #0x10
lbl_0806d1be:
    lsls r1, r0, #5
    adds r1, r1, r6
    adds r2, r5, #0
    adds r2, #0x40
    str r7, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_0806d324
    .align 2, 0
lbl_0806d1d4: .4byte 0x08754bc4
lbl_0806d1d8: .4byte gInGameTimer
lbl_0806d1dc: .4byte 0x06017ea0
lbl_0806d1e0: .4byte 0x0840d79c
lbl_0806d1e4: .4byte 0x06017c00
lbl_0806d1e8:
    ldr r0, lbl_0806d2fc @ =0x08754bc4
    mov r8, r0
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x34
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806d1fa
    b lbl_0806d324
lbl_0806d1fa:
    adds r0, r1, #0
    adds r0, #0x38
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d208
    movs r0, #0x10
lbl_0806d208:
    lsls r1, r0, #5
    ldr r7, lbl_0806d300 @ =0x06017c00
    adds r1, r1, r7
    ldr r0, lbl_0806d304 @ =0x0840d79c
    mov sb, r0
    ldr r5, [r0, #4]
    movs r6, #0x20
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x37
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d232
    movs r0, #0x10
lbl_0806d232:
    lsls r1, r0, #5
    adds r1, r1, r7
    adds r2, r5, #0
    adds r2, #0x40
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x3a
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d254
    movs r0, #0x10
lbl_0806d254:
    lsls r1, r0, #5
    adds r1, r1, r7
    mov r0, sb
    ldr r5, [r0, #8]
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x39
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d278
    movs r0, #0x10
lbl_0806d278:
    lsls r1, r0, #5
    adds r1, r1, r7
    adds r2, r5, #0
    adds r2, #0x40
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x3c
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d29a
    movs r0, #0x10
lbl_0806d29a:
    lsls r1, r0, #5
    adds r1, r1, r7
    mov r0, sb
    ldr r5, [r0, #0xc]
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x20
    bl DMATransfer
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x3b
    ldrb r4, [r0]
    adds r0, r4, #0
    cmp r0, #0x10
    ble lbl_0806d2be
    movs r0, #0x10
lbl_0806d2be:
    lsls r1, r0, #5
    adds r1, r1, r7
    adds r2, r5, #0
    adds r2, #0x40
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    movs r4, #3
    movs r6, #0x20
    mov r5, sb
    adds r5, #0xc
lbl_0806d2d8:
    ldr r0, lbl_0806d2fc @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x3d
    ldrb r0, [r0]
    asrs r0, r4
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806d30c
    ldr r2, [r5]
    subs r2, #0x60
    str r6, [sp]
    movs r0, #3
    ldr r1, lbl_0806d308 @ =0x06017e00
    movs r3, #0x20
    bl DMATransfer
    b lbl_0806d31c
    .align 2, 0
lbl_0806d2fc: .4byte 0x08754bc4
lbl_0806d300: .4byte 0x06017c00
lbl_0806d304: .4byte 0x0840d79c
lbl_0806d308: .4byte 0x06017e00
lbl_0806d30c:
    ldr r2, [r5]
    subs r2, #0x60
    str r6, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x20
    bl BitFill
lbl_0806d31c:
    subs r5, #4
    subs r4, #1
    cmp r4, #0
    bge lbl_0806d2d8
lbl_0806d324:
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0806d334
sub_0806d334: @ 0x0806d334
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r2, lbl_0806d374 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x4c
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x4c
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0806d384
    movs r1, #0xf0
    lsls r1, r1, #1
    ldr r2, lbl_0806d378 @ =0x0600d800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl BitFill
    ldr r1, lbl_0806d37c @ =0x0840f4c4
    ldr r0, lbl_0806d380 @ =0x087602a8
    ldr r2, [r0]
    str r4, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_0806d3c6
    .align 2, 0
lbl_0806d374: .4byte 0x08754bc4
lbl_0806d378: .4byte 0x0600d800
lbl_0806d37c: .4byte 0x0840f4c4
lbl_0806d380: .4byte 0x087602a8
lbl_0806d384:
    cmp r0, #2
    bne lbl_0806d3c6
    movs r4, #0
    ldr r5, lbl_0806d424 @ =0x0600d800
    movs r6, #0x10
lbl_0806d38e:
    movs r0, #0xf0
    lsls r0, r0, #1
    adds r1, r4, r0
    str r6, [sp]
    movs r0, #3
    adds r2, r5, #0
    movs r3, #0x40
    bl BitFill
    adds r5, #0x40
    adds r4, #1
    cmp r4, #0x1f
    ble lbl_0806d38e
    movs r4, #0
    ldr r6, lbl_0806d428 @ =0x087602a8
    movs r5, #0x10
lbl_0806d3ae:
    lsls r0, r4, #5
    ldr r2, [r6]
    adds r2, r2, r0
    str r5, [sp]
    movs r0, #3
    ldr r1, lbl_0806d42c @ =0x0840f4c4
    movs r3, #0x20
    bl DMATransfer
    adds r4, #1
    cmp r4, #0x1f
    ble lbl_0806d3ae
lbl_0806d3c6:
    ldr r2, lbl_0806d430 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x4d
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x4e
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x50
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x4f
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x4c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806d41c
    ldr r3, lbl_0806d434 @ =0x0600e000
    ldr r2, lbl_0806d424 @ =0x0600d800
    ldr r5, lbl_0806d438 @ =0x000003ff
    movs r6, #0xc0
    adds r4, r5, #1
lbl_0806d3f6:
    ldrh r1, [r3]
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0xa0
    beq lbl_0806d402
    strh r6, [r2]
lbl_0806d402:
    subs r4, #1
    adds r2, #2
    adds r3, #2
    cmp r4, #0
    bne lbl_0806d3f6
    ldr r1, lbl_0806d43c @ =0x040000d4
    ldr r0, lbl_0806d440 @ =0x02034000
    str r0, [r1]
    ldr r0, lbl_0806d434 @ =0x0600e000
    str r0, [r1, #4]
    ldr r0, lbl_0806d444 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0806d41c:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806d424: .4byte 0x0600d800
lbl_0806d428: .4byte 0x087602a8
lbl_0806d42c: .4byte 0x0840f4c4
lbl_0806d430: .4byte 0x08754bc4
lbl_0806d434: .4byte 0x0600e000
lbl_0806d438: .4byte 0x000003ff
lbl_0806d43c: .4byte 0x040000d4
lbl_0806d440: .4byte 0x02034000
lbl_0806d444: .4byte 0x80000400

    thumb_func_start sub_0806d448
sub_0806d448: @ 0x0806d448
    push {lr}
    movs r1, #0
    ldr r0, lbl_0806d460 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x4c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0806d464
    bl sub_0806d680
    b lbl_0806d476
    .align 2, 0
lbl_0806d460: .4byte 0x08754bc4
lbl_0806d464:
    cmp r0, #1
    bne lbl_0806d46e
    bl sub_0806d480
    b lbl_0806d476
lbl_0806d46e:
    cmp r0, #2
    bne lbl_0806d478
    bl sub_0806d528
lbl_0806d476:
    adds r1, r0, #0
lbl_0806d478:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806d480
sub_0806d480: @ 0x0806d480
    push {r4, r5, r6, r7, lr}
    ldr r3, lbl_0806d494 @ =0x08754bc4
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x4f
    ldrb r0, [r0]
    cmp r0, #0xf
    bls lbl_0806d498
    movs r0, #1
    b lbl_0806d516
    .align 2, 0
lbl_0806d494: .4byte 0x08754bc4
lbl_0806d498:
    adds r1, #0x4d
    ldrb r0, [r1]
    adds r0, #1
    movs r4, #0
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0x4e
    ldrb r1, [r2]
    cmp r1, #0
    beq lbl_0806d4b4
    cmp r1, #1
    beq lbl_0806d4c8
    b lbl_0806d514
lbl_0806d4b4:
    adds r0, #0x4d
    ldrb r0, [r0]
    cmp r0, #0x10
    bls lbl_0806d514
    movs r0, #1
    strb r0, [r2]
    ldr r0, [r3]
    adds r0, #0x4d
    strb r4, [r0]
    b lbl_0806d514
lbl_0806d4c8:
    adds r1, r0, #0
    adds r1, #0x4d
    ldrb r0, [r1]
    cmp r0, #3
    bls lbl_0806d514
    strb r4, [r1]
    ldr r2, lbl_0806d51c @ =0x0840f4c4
    ldr r0, [r3]
    adds r0, #0x4f
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r0, [r3]
    adds r0, #0x4f
    ldrb r3, [r0]
    movs r4, #0
    cmp r3, #0
    beq lbl_0806d514
    ldr r7, lbl_0806d520 @ =0x087602a8
    ldr r5, lbl_0806d524 @ =0x087602b0
    adds r6, r2, #0
lbl_0806d4f2:
    adds r1, r3, #0
    cmp r3, #8
    ble lbl_0806d4fa
    movs r1, #8
lbl_0806d4fa:
    ldr r0, [r7]
    lsls r2, r4, #2
    adds r2, r2, r0
    lsls r0, r1, #2
    adds r0, r0, r5
    ldm r6!, {r1}
    ldr r0, [r0]
    ands r1, r0
    str r1, [r2]
    subs r3, #1
    adds r4, #1
    cmp r3, #0
    bne lbl_0806d4f2
lbl_0806d514:
    movs r0, #0
lbl_0806d516:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0806d51c: .4byte 0x0840f4c4
lbl_0806d520: .4byte 0x087602a8
lbl_0806d524: .4byte 0x087602b0

    thumb_func_start sub_0806d528
sub_0806d528: @ 0x0806d528
    push {r4, r5, r6, r7, lr}
    movs r6, #0
    ldr r5, lbl_0806d550 @ =0x08754bc4
    ldr r1, [r5]
    adds r1, #0x4d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    adds r3, r1, #0
    adds r3, #0x4e
    ldrb r0, [r3]
    cmp r0, #1
    beq lbl_0806d5f8
    cmp r0, #1
    bgt lbl_0806d554
    cmp r0, #0
    beq lbl_0806d560
    b lbl_0806d676
    .align 2, 0
lbl_0806d550: .4byte 0x08754bc4
lbl_0806d554:
    cmp r0, #2
    beq lbl_0806d640
    cmp r0, #3
    bne lbl_0806d55e
    b lbl_0806d664
lbl_0806d55e:
    b lbl_0806d676
lbl_0806d560:
    adds r0, r1, #0
    adds r0, #0x4d
    ldrb r0, [r0]
    cmp r0, #8
    bhi lbl_0806d56c
    b lbl_0806d676
lbl_0806d56c:
    movs r0, #0x99
    lsls r0, r0, #1
    adds r1, r1, r0
    movs r0, #0xb
    strb r0, [r1]
    ldr r0, [r5]
    movs r1, #0x98
    lsls r1, r1, #1
    adds r0, r0, r1
    strb r6, [r0]
    ldr r0, [r5]
    ldr r7, lbl_0806d5e4 @ =0x00000131
    adds r0, r0, r7
    strb r6, [r0]
    ldr r2, [r5]
    movs r0, #0x95
    lsls r0, r0, #1
    adds r1, r2, r0
    movs r4, #0
    adds r0, #0xa6
    strh r0, [r1]
    subs r7, #9
    adds r1, r2, r7
    ldr r0, lbl_0806d5e8 @ =0x0000ffe0
    strh r0, [r1]
    ldr r3, lbl_0806d5ec @ =0x00000133
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r5]
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r5]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r0, #0x4d
    strb r4, [r0]
    ldr r1, [r5]
    ldr r0, lbl_0806d5f0 @ =gBG3VOFS_NonGameplay
    ldrh r2, [r0]
    ldr r0, lbl_0806d5f4 @ =0x000003ff
    ands r0, r2
    lsrs r0, r0, #2
    adds r1, #0x50
    strb r0, [r1]
    b lbl_0806d676
    .align 2, 0
lbl_0806d5e4: .4byte 0x00000131
lbl_0806d5e8: .4byte 0x0000ffe0
lbl_0806d5ec: .4byte 0x00000133
lbl_0806d5f0: .4byte gBG3VOFS_NonGameplay
lbl_0806d5f4: .4byte 0x000003ff
lbl_0806d5f8:
    movs r4, #0x94
    lsls r4, r4, #1
    adds r0, r1, r4
    movs r7, #0
    ldrsh r2, [r0, r7]
    movs r0, #0xaa
    lsls r0, r0, #2
    cmp r2, r0
    ble lbl_0806d610
    movs r0, #2
    strb r0, [r3]
    b lbl_0806d676
lbl_0806d610:
    movs r0, #0x10
    rsbs r0, r0, #0
    cmp r2, r0
    blt lbl_0806d62e
    adds r2, r1, #0
    adds r2, #0x50
    ldrb r0, [r2]
    ldr r1, lbl_0806d63c @ =0x087602a8
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    str r6, [r0]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
lbl_0806d62e:
    ldr r1, [r5]
    adds r1, r1, r4
    ldrh r0, [r1]
    adds r0, #4
    strh r0, [r1]
    b lbl_0806d676
    .align 2, 0
lbl_0806d63c: .4byte 0x087602a8
lbl_0806d640:
    ldr r0, lbl_0806d660 @ =0x00000133
    adds r2, r1, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0x4d
    strb r6, [r0]
    ldr r1, [r5]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806d676
    .align 2, 0
lbl_0806d660: .4byte 0x00000133
lbl_0806d664:
    adds r1, #0x4d
    ldrb r0, [r1]
    cmp r0, #0x1d
    bls lbl_0806d676
    strb r6, [r1]
    ldr r0, [r5]
    adds r0, #0x4e
    strb r6, [r0]
    movs r6, #1
lbl_0806d676:
    adds r0, r6, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806d680
sub_0806d680: @ 0x0806d680
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    str r0, [sp]
    ldr r2, lbl_0806d6b4 @ =0x08754bc4
    ldr r1, [r2]
    adds r1, #0x4d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r2]
    adds r0, #0x4e
    ldrb r0, [r0]
    mov ip, r2
    cmp r0, #6
    bls lbl_0806d6aa
    b lbl_0806db44
lbl_0806d6aa:
    lsls r0, r0, #2
    ldr r1, lbl_0806d6b8 @ =lbl_0806d6bc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806d6b4: .4byte 0x08754bc4
lbl_0806d6b8: .4byte lbl_0806d6bc
lbl_0806d6bc: @ jump table
    .4byte lbl_0806d6d8 @ case 0
    .4byte lbl_0806d828 @ case 1
    .4byte lbl_0806d890 @ case 2
    .4byte lbl_0806da18 @ case 3
    .4byte lbl_0806da4c @ case 4
    .4byte lbl_0806da7c @ case 5
    .4byte lbl_0806db28 @ case 6
lbl_0806d6d8:
    mov r2, ip
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x4d
    ldrb r0, [r0]
    cmp r0, #8
    bhi lbl_0806d6e8
    b lbl_0806db44
lbl_0806d6e8:
    movs r4, #0x99
    lsls r4, r4, #1
    adds r2, r1, r4
    movs r1, #0
    movs r0, #0xb
    strb r0, [r2]
    mov r5, ip
    ldr r0, [r5]
    movs r2, #0x98
    lsls r2, r2, #1
    adds r0, r0, r2
    strb r1, [r0]
    ldr r0, [r5]
    subs r4, #1
    adds r0, r0, r4
    strb r1, [r0]
    ldr r2, [r5]
    movs r5, #0x95
    lsls r5, r5, #1
    adds r1, r2, r5
    movs r0, #0xe8
    lsls r0, r0, #1
    strh r0, [r1]
    movs r1, #0x94
    lsls r1, r1, #1
    adds r0, r2, r1
    ldr r5, lbl_0806d818 @ =0x0000ffe0
    strh r5, [r0]
    ldr r3, lbl_0806d81c @ =0x00000133
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r4, #4
    rsbs r4, r4, #0
    adds r0, r4, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2]
    mov r0, ip
    ldr r2, [r0]
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    movs r6, #3
    ldr r1, lbl_0806d820 @ =0x087602ac
    mov sb, r1
    mov r7, ip
    movs r2, #0
    mov r8, r2
    ldr r5, lbl_0806d824 @ =0x00000113
    mov sl, r4
lbl_0806d756:
    ldr r1, [r7]
    mov r4, sb
    adds r3, r6, r4
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    mov r4, r8
    strb r4, [r0]
    ldr r1, [r7]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    movs r0, #0x88
    lsls r0, r0, #1
    adds r1, r1, r0
    strb r4, [r1]
    ldr r1, [r7]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    subs r2, #1
    adds r0, r1, r2
    strb r4, [r0]
    ldr r2, [r7]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r0, r2, r0
    movs r4, #0x85
    lsls r4, r4, #1
    adds r1, r0, r4
    movs r0, #0xe8
    lsls r0, r0, #1
    strh r0, [r1]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r0, r2, r0
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r4, #0x20
    rsbs r4, r4, #0
    strh r4, [r0]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r2, r2, r0
    adds r2, r2, r5
    ldrb r1, [r2]
    mov r0, sl
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2]
    ldr r2, [r7]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r2, r2, r0
    adds r2, r2, r5
    ldrb r1, [r2]
    movs r0, #0xd
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #4
    orrs r0, r1
    strb r0, [r2]
    ldr r1, [r7]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r1, r1, r5
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    subs r6, #1
    cmp r6, #0
    bge lbl_0806d756
    mov r5, ip
    ldr r1, [r5]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r0, #0x4d
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x4f
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x51
    movs r1, #0x80
    strb r1, [r0]
    b lbl_0806db44
    .align 2, 0
lbl_0806d818: .4byte 0x0000ffe0
lbl_0806d81c: .4byte 0x00000133
lbl_0806d820: .4byte 0x087602ac
lbl_0806d824: .4byte 0x00000113
lbl_0806d828:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x50
    movs r1, #0
    strb r1, [r0]
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0x4f
    strb r1, [r0]
    ldr r3, lbl_0806d858 @ =gBG3VOFS_NonGameplay
    ldrh r1, [r3]
    ldr r0, lbl_0806d85c @ =0x000007ff
    cmp r1, r0
    bhi lbl_0806d860
    ldr r2, [r2]
    adds r0, #1
    subs r0, r0, r1
    asrs r0, r0, #5
    movs r1, #0x3f
    subs r1, r1, r0
    adds r2, #0x50
    strb r1, [r2]
    b lbl_0806d878
    .align 2, 0
lbl_0806d858: .4byte gBG3VOFS_NonGameplay
lbl_0806d85c: .4byte 0x000007ff
lbl_0806d860:
    movs r0, #0x80
    lsls r0, r0, #4
    cmp r1, r0
    bls lbl_0806d878
    mov r4, ip
    ldr r1, [r4]
    ldrh r0, [r3]
    ldr r5, lbl_0806d88c @ =0xfffff800
    adds r0, r0, r5
    asrs r0, r0, #5
    adds r1, #0x50
    strb r0, [r1]
lbl_0806d878:
    mov r0, ip
    ldr r1, [r0]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    mov r1, ip
    ldr r0, [r1]
    b lbl_0806da6c
    .align 2, 0
lbl_0806d88c: .4byte 0xfffff800
lbl_0806d890:
    movs r6, #1
    mov r2, ip
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x4d
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_0806d964
    adds r0, r1, #0
    adds r0, #0x4f
    ldrb r0, [r0]
    cmp r0, #0x14
    bhi lbl_0806d950
    adds r1, #0x50
    ldrb r0, [r1]
    cmp r0, #0x1f
    bhi lbl_0806d8d2
    ldr r2, lbl_0806d934 @ =0x040000d4
    lsls r0, r0, #6
    ldr r1, lbl_0806d938 @ =0x02034000
    adds r0, r0, r1
    str r0, [r2]
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0x50
    ldrb r0, [r0]
    lsls r0, r0, #6
    ldr r5, lbl_0806d93c @ =0x0600e000
    adds r0, r0, r5
    str r0, [r2, #4]
    ldr r0, lbl_0806d940 @ =0x80000020
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0806d8d2:
    mov r0, ip
    ldr r1, [r0]
    adds r1, #0x4f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    mov r2, ip
    ldr r1, [r2]
    adds r1, #0x50
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0x50
    ldrb r0, [r1]
    cmp r0, #0x3f
    bls lbl_0806d8fa
    movs r0, #0
    strb r0, [r1]
lbl_0806d8fa:
    mov r5, ip
    ldr r4, [r5]
    ldr r1, lbl_0806d944 @ =0x00000412
    adds r0, r4, r1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806d95a
    adds r0, r4, #0
    adds r0, #0x50
    ldrb r3, [r0]
    ldr r1, lbl_0806d948 @ =0x0840d200
    ldrb r2, [r4, #0x12]
    lsls r0, r2, #2
    adds r0, r0, r2
    adds r1, #3
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r0, #2
    cmp r3, r0
    bne lbl_0806d95a
    ldr r5, lbl_0806d94c @ =0x00000413
    adds r2, r4, r5
    ldrb r1, [r2]
    movs r0, #0x21
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2]
    b lbl_0806d95a
    .align 2, 0
lbl_0806d934: .4byte 0x040000d4
lbl_0806d938: .4byte 0x02034000
lbl_0806d93c: .4byte 0x0600e000
lbl_0806d940: .4byte 0x80000020
lbl_0806d944: .4byte 0x00000412
lbl_0806d948: .4byte 0x0840d200
lbl_0806d94c: .4byte 0x00000413
lbl_0806d950:
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r6, #0
lbl_0806d95a:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x4d
    movs r1, #0
    strb r1, [r0]
lbl_0806d964:
    cmp r6, #0
    bne lbl_0806d96a
    b lbl_0806db44
lbl_0806d96a:
    mov r2, ip
    ldr r1, [r2]
    adds r0, r1, #0
    adds r0, #0x4f
    ldrb r0, [r0]
    subs r0, #1
    adds r2, r1, #0
    adds r2, #0x4d
    lsls r0, r0, #3
    ldrb r2, [r2]
    adds r0, r0, r2
    lsls r0, r0, #2
    movs r5, #0x94
    lsls r5, r5, #1
    adds r2, r1, r5
    movs r4, #0
    strh r0, [r2]
    adds r1, #0x51
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0x51
    ldrb r0, [r1]
    cmp r0, #3
    bls lbl_0806d9a4
    strb r4, [r1]
lbl_0806d9a4:
    mov r0, ip
    ldr r2, [r0]
    adds r0, r2, #0
    adds r0, #0x51
    ldrb r6, [r0]
    ldr r3, lbl_0806da10 @ =0x087602ac
    adds r3, r6, r3
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r0, r2, r0
    adds r1, r2, r5
    ldrh r1, [r1]
    subs r1, #4
    movs r5, #0x84
    lsls r5, r5, #1
    adds r0, r0, r5
    strh r1, [r0]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r2, r2, r0
    movs r0, #0x89
    lsls r0, r0, #1
    adds r1, r2, r0
    movs r0, #0xa
    strb r0, [r1]
    mov r2, ip
    ldr r1, [r2]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r5, #8
    adds r1, r1, r5
    strb r4, [r1]
    ldr r1, [r2]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    ldr r2, lbl_0806da14 @ =0x00000111
    adds r0, r1, r2
    strb r4, [r0]
    mov r4, ip
    ldr r1, [r4]
    ldrb r0, [r3]
    lsls r0, r0, #4
    adds r1, r1, r0
    adds r5, #3
    adds r2, r1, r5
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r2]
    b lbl_0806db44
    .align 2, 0
lbl_0806da10: .4byte 0x087602ac
lbl_0806da14: .4byte 0x00000111
lbl_0806da18:
    ldr r1, lbl_0806da3c @ =0x040000d4
    ldr r0, lbl_0806da40 @ =0x02034000
    str r0, [r1]
    ldr r0, lbl_0806da44 @ =0x0600e000
    str r0, [r1, #4]
    ldr r0, lbl_0806da48 @ =0x80000400
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    mov r0, ip
    ldr r1, [r0]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    mov r1, ip
    ldr r0, [r1]
    b lbl_0806da6c
    .align 2, 0
lbl_0806da3c: .4byte 0x040000d4
lbl_0806da40: .4byte 0x02034000
lbl_0806da44: .4byte 0x0600e000
lbl_0806da48: .4byte 0x80000400
lbl_0806da4c:
    movs r6, #3
    ldr r4, lbl_0806da74 @ =gUpdateMinimapFlag
lbl_0806da50:
    strb r6, [r4]
    bl draw_minimap
    subs r6, #1
    cmp r6, #0
    bgt lbl_0806da50
    ldr r3, lbl_0806da78 @ =0x08754bc4
    ldr r1, [r3]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r3]
lbl_0806da6c:
    adds r0, #0x4d
    strb r2, [r0]
    b lbl_0806db44
    .align 2, 0
lbl_0806da74: .4byte gUpdateMinimapFlag
lbl_0806da78: .4byte 0x08754bc4
lbl_0806da7c:
    mov r2, ip
    ldr r0, [r2]
    movs r4, #0x99
    lsls r4, r4, #1
    adds r0, r0, r4
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    movs r5, #0x98
    lsls r5, r5, #1
    adds r0, r0, r5
    strb r1, [r0]
    ldr r0, [r2]
    ldr r2, lbl_0806db1c @ =0x00000131
    adds r0, r0, r2
    strb r1, [r0]
    mov r4, ip
    ldr r0, [r4]
    adds r5, #3
    adds r2, r0, r5
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    movs r6, #4
    ldr r0, lbl_0806db20 @ =0x087602ac
    mov sb, r0
    mov r3, ip
    movs r4, #0
lbl_0806dab6:
    subs r6, #1
    ldr r1, [r3]
    mov r5, sb
    adds r2, r6, r5
    ldrb r0, [r2]
    lsls r0, r0, #4
    adds r1, r1, r0
    movs r5, #0x89
    lsls r5, r5, #1
    adds r0, r1, r5
    strb r4, [r0]
    ldr r1, [r3]
    ldrb r0, [r2]
    lsls r0, r0, #4
    adds r1, r1, r0
    movs r0, #0x88
    lsls r0, r0, #1
    adds r1, r1, r0
    strb r4, [r1]
    ldr r1, [r3]
    ldrb r0, [r2]
    lsls r0, r0, #4
    adds r1, r1, r0
    subs r5, #1
    adds r0, r1, r5
    strb r4, [r0]
    ldr r1, [r3]
    ldrb r0, [r2]
    lsls r0, r0, #4
    adds r1, r1, r0
    ldr r0, lbl_0806db24 @ =0x00000113
    adds r2, r1, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    cmp r6, #0
    bgt lbl_0806dab6
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0x4d
    movs r1, #0
    strb r1, [r0]
    mov r2, ip
    ldr r1, [r2]
    adds r1, #0x4e
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806db44
    .align 2, 0
lbl_0806db1c: .4byte 0x00000131
lbl_0806db20: .4byte 0x087602ac
lbl_0806db24: .4byte 0x00000113
lbl_0806db28:
    mov r4, ip
    ldr r0, [r4]
    adds r2, r0, #0
    adds r2, #0x4d
    ldrb r0, [r2]
    cmp r0, #0x1d
    bls lbl_0806db44
    movs r1, #0
    strb r1, [r2]
    ldr r0, [r4]
    adds r0, #0x4e
    strb r1, [r0]
    movs r5, #1
    str r5, [sp]
lbl_0806db44:
    ldr r0, [sp]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806db58
sub_0806db58: @ 0x0806db58
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    adds r6, r4, #0
    ldr r5, lbl_0806dc14 @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0x2e
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x2f
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x30
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x31
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x27
    movs r1, #0x1f
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x28
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x26
    strb r2, [r0]
    ldr r0, [r5]
    adds r0, #0x29
    strb r2, [r0]
    bl sub_0806ddc0
    bl sub_0806ded0
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x27
    adds r2, r0, #0
    adds r2, #0x26
    ldrb r3, [r1]
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806dbba
    strb r3, [r2]
lbl_0806dbba:
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x28
    adds r2, r0, #0
    adds r2, #0x29
    ldrb r3, [r1]
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r1, r0
    ble lbl_0806dbd6
    strb r3, [r2]
lbl_0806dbd6:
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x26
    ldrb r1, [r1]
    adds r0, #0x2a
    strb r1, [r0]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x27
    ldrb r1, [r1]
    adds r0, #0x2b
    strb r1, [r0]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x28
    ldrb r1, [r1]
    adds r0, #0x2c
    strb r1, [r0]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x29
    ldrb r1, [r1]
    adds r0, #0x2d
    strb r1, [r0]
    cmp r4, #1
    bne lbl_0806dc18
    ldr r0, [r5]
    ldrb r6, [r0, #0x13]
    ldrb r4, [r0, #0x14]
    adds r7, r5, #0
    b lbl_0806dcc0
    .align 2, 0
lbl_0806dc14: .4byte 0x08754bc4
lbl_0806dc18:
    cmp r6, #2
    bne lbl_0806dc52
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x27
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r1, r2, #0
    adds r1, #0x26
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, r0, r1
    asrs r6, r0, #1
    adds r0, r2, #0
    adds r0, #0x28
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r1, r2, #0
    adds r1, #0x29
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, r0, r1
    asrs r4, r0, #1
    adds r7, r5, #0
    b lbl_0806dcc0
lbl_0806dc52:
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0x27
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r1, r3, #0
    adds r1, #0x26
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, r0, r1
    asrs r6, r0, #1
    adds r0, r3, #0
    adds r0, #0x28
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r1, r3, #0
    adds r1, #0x29
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    adds r0, r0, r1
    asrs r4, r0, #1
    adds r2, r4, #5
    subs r5, r4, #5
    ldrb r0, [r3, #0x14]
    cmp r2, r0
    bge lbl_0806dc94
    subs r0, r0, r2
    adds r4, r4, r0
    b lbl_0806dc9c
lbl_0806dc94:
    cmp r5, r0
    ble lbl_0806dc9c
    subs r0, r5, r0
    subs r4, r4, r0
lbl_0806dc9c:
    adds r2, r6, #6
    subs r5, r6, #6
    ldr r1, lbl_0806dcb4 @ =0x08754bc4
    ldr r0, [r1]
    ldrb r0, [r0, #0x13]
    adds r7, r1, #0
    cmp r2, r0
    bge lbl_0806dcb8
    subs r0, r0, r2
    adds r6, r6, r0
    b lbl_0806dcc0
    .align 2, 0
lbl_0806dcb4: .4byte 0x08754bc4
lbl_0806dcb8:
    cmp r5, r0
    ble lbl_0806dcc0
    subs r0, r5, r0
    subs r6, r6, r0
lbl_0806dcc0:
    ldr r0, [r7]
    adds r0, #0x24
    strb r6, [r0]
    ldr r0, [r7]
    adds r0, #0x25
    strb r4, [r0]
    ldr r0, [r7]
    adds r5, r0, #0
    adds r5, #0x29
    movs r4, #0
    ldrsb r4, [r5, r4]
    adds r1, r0, #0
    adds r1, #0x28
    movs r3, #0
    ldrsb r3, [r1, r3]
    subs r0, r4, r3
    asrs r0, r0, #1
    cmp r0, #5
    ble lbl_0806dcf6
    ldrb r0, [r1]
    adds r0, #5
    strb r0, [r1]
    ldr r1, [r7]
    adds r1, #0x29
    ldrb r0, [r1]
    subs r0, #5
    b lbl_0806dcfc
lbl_0806dcf6:
    adds r0, r4, r3
    asrs r0, r0, #1
    strb r0, [r5]
lbl_0806dcfc:
    strb r0, [r1]
    ldr r0, [r7]
    adds r5, r0, #0
    adds r5, #0x26
    movs r4, #0
    ldrsb r4, [r5, r4]
    adds r1, r0, #0
    adds r1, #0x27
    movs r3, #0
    ldrsb r3, [r1, r3]
    subs r0, r4, r3
    asrs r0, r0, #1
    cmp r0, #6
    ble lbl_0806dd28
    ldrb r0, [r1]
    adds r0, #6
    strb r0, [r1]
    ldr r1, [r7]
    adds r1, #0x26
    ldrb r0, [r1]
    subs r0, #6
    b lbl_0806dd2e
lbl_0806dd28:
    adds r0, r4, r3
    asrs r0, r0, #1
    strb r0, [r5]
lbl_0806dd2e:
    strb r0, [r1]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x24
    adds r3, r1, #0
    adds r3, #0x27
    ldrb r5, [r0]
    movs r4, #0
    ldrsb r4, [r0, r4]
    movs r0, #0
    ldrsb r0, [r3, r0]
    cmp r4, r0
    bge lbl_0806dd4c
    strb r5, [r3]
    b lbl_0806dd58
lbl_0806dd4c:
    adds r1, #0x26
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r4, r0
    ble lbl_0806dd58
    strb r5, [r1]
lbl_0806dd58:
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0x25
    adds r3, r1, #0
    adds r3, #0x28
    ldrb r5, [r0]
    movs r4, #0
    ldrsb r4, [r0, r4]
    movs r0, #0
    ldrsb r0, [r3, r0]
    cmp r4, r0
    bge lbl_0806dd74
    strb r5, [r3]
    b lbl_0806dd80
lbl_0806dd74:
    adds r1, #0x29
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r4, r0
    ble lbl_0806dd80
    strb r5, [r1]
lbl_0806dd80:
    ldr r3, lbl_0806ddb8 @ =gBG3HOFS_NonGameplay
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0xf
    subs r0, r0, r1
    lsls r0, r0, #3
    movs r1, #0x81
    lsls r1, r1, #2
    subs r0, r1, r0
    lsls r0, r0, #2
    strh r0, [r3]
    ldr r3, lbl_0806ddbc @ =gBG3VOFS_NonGameplay
    adds r2, #0x25
    ldrb r2, [r2]
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    movs r0, #0xa
    subs r0, r0, r2
    lsls r0, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #2
    strh r1, [r3]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806ddb8: .4byte gBG3HOFS_NonGameplay
lbl_0806ddbc: .4byte gBG3VOFS_NonGameplay

    thumb_func_start sub_0806ddc0
sub_0806ddc0: @ 0x0806ddc0
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_0806de00 @ =0x08754bc4
    ldr r2, [r4]
    ldrb r0, [r2, #0x12]
    movs r1, #7
    cmp r0, #6
    bhi lbl_0806ddd0
    adds r1, r0, #0
lbl_0806ddd0:
    movs r3, #0x82
    lsls r3, r3, #1
    adds r0, r2, r3
    lsls r1, r1, #0xb
    ldr r0, [r0]
    adds r6, r0, r1
    movs r5, #0
    movs r3, #0
    movs r0, #0xa0
    lsls r0, r0, #1
    mov ip, r0
    adds r7, r4, #0
lbl_0806dde8:
    movs r1, #0
    adds r4, r3, #1
    lsls r0, r3, #6
    adds r2, r0, r6
lbl_0806ddf0:
    ldrh r0, [r2]
    cmp r0, ip
    beq lbl_0806de04
    ldr r0, [r7]
    adds r0, #0x28
    strb r3, [r0]
    movs r5, #1
    b lbl_0806de0c
    .align 2, 0
lbl_0806de00: .4byte 0x08754bc4
lbl_0806de04:
    adds r2, #2
    adds r1, #1
    cmp r1, #0x1f
    ble lbl_0806ddf0
lbl_0806de0c:
    adds r3, r4, #0
    cmp r3, #0x1f
    bgt lbl_0806de16
    cmp r5, #0
    beq lbl_0806dde8
lbl_0806de16:
    movs r3, #0x1f
    movs r5, #0
    movs r0, #0xa0
    lsls r0, r0, #1
    mov ip, r0
    ldr r7, lbl_0806de3c @ =0x08754bc4
lbl_0806de22:
    movs r1, #0
    subs r4, r3, #1
    lsls r0, r3, #6
    adds r2, r0, r6
lbl_0806de2a:
    ldrh r0, [r2]
    cmp r0, ip
    beq lbl_0806de40
    ldr r0, [r7]
    adds r0, #0x29
    strb r3, [r0]
    movs r5, #1
    b lbl_0806de48
    .align 2, 0
lbl_0806de3c: .4byte 0x08754bc4
lbl_0806de40:
    adds r2, #2
    adds r1, #1
    cmp r1, #0x1f
    ble lbl_0806de2a
lbl_0806de48:
    adds r3, r4, #0
    cmp r3, #0
    blt lbl_0806de52
    cmp r5, #0
    beq lbl_0806de22
lbl_0806de52:
    movs r5, #0
    movs r3, #0
    movs r0, #0xa0
    lsls r0, r0, #1
    mov ip, r0
    ldr r7, lbl_0806de78 @ =0x08754bc4
lbl_0806de5e:
    movs r1, #0
    adds r4, r3, #1
    lsls r0, r3, #1
    adds r2, r0, r6
lbl_0806de66:
    ldrh r0, [r2]
    cmp r0, ip
    beq lbl_0806de7c
    ldr r0, [r7]
    adds r0, #0x27
    strb r3, [r0]
    movs r5, #1
    b lbl_0806de84
    .align 2, 0
lbl_0806de78: .4byte 0x08754bc4
lbl_0806de7c:
    adds r2, #0x40
    adds r1, #1
    cmp r1, #0x1f
    ble lbl_0806de66
lbl_0806de84:
    adds r3, r4, #0
    cmp r3, #0x1f
    bgt lbl_0806de8e
    cmp r5, #0
    beq lbl_0806de5e
lbl_0806de8e:
    movs r3, #0x1f
    movs r5, #0
    movs r0, #0xa0
    lsls r0, r0, #1
    mov ip, r0
    ldr r7, lbl_0806deb4 @ =0x08754bc4
lbl_0806de9a:
    movs r1, #0
    subs r4, r3, #1
    lsls r0, r3, #1
    adds r2, r0, r6
lbl_0806dea2:
    ldrh r0, [r2]
    cmp r0, ip
    beq lbl_0806deb8
    ldr r0, [r7]
    adds r0, #0x26
    strb r3, [r0]
    movs r5, #1
    b lbl_0806dec0
    .align 2, 0
lbl_0806deb4: .4byte 0x08754bc4
lbl_0806deb8:
    adds r2, #0x40
    adds r1, #1
    cmp r1, #0x1f
    ble lbl_0806dea2
lbl_0806dec0:
    adds r3, r4, #0
    cmp r3, #0
    blt lbl_0806deca
    cmp r5, #0
    beq lbl_0806de9a
lbl_0806deca:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0806ded0
sub_0806ded0: @ 0x0806ded0
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_0806defc @ =0x08754bc4
    ldr r0, [r1]
    movs r2, #0xba
    lsls r2, r2, #2
    adds r4, r0, r2
    mov ip, r1
    ldr r7, lbl_0806df00 @ =0x000003ff
    movs r6, #0xb
lbl_0806dee2:
    ldrb r1, [r4, #0xb]
    movs r0, #0xc0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806df72
    ldrh r0, [r4, #2]
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    cmp r1, #0
    bge lbl_0806df04
    movs r5, #0
    b lbl_0806df12
    .align 2, 0
lbl_0806defc: .4byte 0x08754bc4
lbl_0806df00: .4byte 0x000003ff
lbl_0806df04:
    cmp r1, r7
    ble lbl_0806df0c
    movs r5, #0x1f
    b lbl_0806df12
lbl_0806df0c:
    asrs r0, r0, #0x15
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
lbl_0806df12:
    ldrh r0, [r4]
    lsls r0, r0, #0x10
    asrs r1, r0, #0x10
    cmp r1, #0
    bge lbl_0806df20
    movs r2, #0
    b lbl_0806df2e
lbl_0806df20:
    cmp r1, r7
    ble lbl_0806df28
    movs r2, #0x1f
    b lbl_0806df2e
lbl_0806df28:
    asrs r0, r0, #0x15
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
lbl_0806df2e:
    mov r3, ip
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x28
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r2, r0
    bge lbl_0806df40
    strb r2, [r1]
lbl_0806df40:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x29
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r2, r0
    ble lbl_0806df50
    strb r2, [r1]
lbl_0806df50:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0x27
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r5, r0
    bge lbl_0806df60
    strb r5, [r1]
lbl_0806df60:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0x26
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r5, r0
    ble lbl_0806df72
    strb r5, [r1]
lbl_0806df72:
    subs r6, #1
    adds r4, #0x10
    cmp r6, #0
    bge lbl_0806dee2
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start get_all_minimap_data
get_all_minimap_data: @ 0x0806df80
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bls lbl_0806df98
    movs r6, #0
    movs r0, #8
    mov sb, r0
    b lbl_0806df9e
lbl_0806df98:
    adds r6, r0, #0
    adds r1, r6, #1
    mov sb, r1
lbl_0806df9e:
    ldr r3, lbl_0806dff0 @ =0x08754bc4
    ldr r0, [r3]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r0, r0, r2
    ldr r1, lbl_0806dff4 @ =0x08754bb4
    ldr r1, [r1]
    str r1, [r0]
    cmp r6, sb
    bge lbl_0806dfe4
    mov r8, r3
    adds r7, r2, #0
lbl_0806dfb6:
    ldr r0, lbl_0806dff8 @ =0x0840d674
    adds r0, r6, r0
    ldrb r5, [r0]
    mov r1, r8
    ldr r0, [r1]
    adds r0, r0, r7
    lsls r4, r6, #0xb
    ldr r1, [r0]
    adds r1, r1, r4
    adds r0, r5, #0
    bl get_minimap_data
    mov r1, r8
    ldr r0, [r1]
    adds r0, r0, r7
    ldr r1, [r0]
    adds r1, r1, r4
    adds r0, r5, #0
    bl minimap_set_downloaded_tiles
    adds r6, #1
    cmp r6, sb
    blt lbl_0806dfb6
lbl_0806dfe4:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806dff0: .4byte 0x08754bc4
lbl_0806dff4: .4byte 0x08754bb4
lbl_0806dff8: .4byte 0x0840d674

    thumb_func_start check_explored_areas
check_explored_areas: @ 0x0806dffc
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0806e030 @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0xb8
    movs r2, #0
    strb r2, [r1]
    movs r1, #0
    ldr r6, lbl_0806e034 @ =0x08754bc0
    movs r7, #1
    adds r5, r0, #0
lbl_0806e010:
    movs r3, #0
    adds r4, r1, #1
    adds r2, r7, #0
    lsls r2, r1
    lsls r1, r1, #7
lbl_0806e01a:
    ldr r0, [r6]
    adds r0, r1, r0
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_0806e038
    ldr r1, [r5]
    adds r1, #0xb8
    ldrb r0, [r1]
    orrs r2, r0
    strb r2, [r1]
    b lbl_0806e040
    .align 2, 0
lbl_0806e030: .4byte 0x08754bc4
lbl_0806e034: .4byte 0x08754bc0
lbl_0806e038:
    adds r1, #4
    adds r3, #1
    cmp r3, #0x1f
    ble lbl_0806e01a
lbl_0806e040:
    adds r1, r4, #0
    cmp r1, #6
    bls lbl_0806e010
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start map_screen_check_input
map_screen_check_input: @ 0x0806e04c
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806e064 @ =0x08754bc4
    ldr r3, [r0]
    adds r1, r3, #0
    adds r1, #0xb4
    ldrb r1, [r1]
    adds r5, r0, #0
    cmp r1, #0
    beq lbl_0806e068
    bl map_screen_change_map
    b lbl_0806e1ea
    .align 2, 0
lbl_0806e064: .4byte 0x08754bc4
lbl_0806e068:
    movs r4, #0
    ldr r0, lbl_0806e09c @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e078
    b lbl_0806e1a2
lbl_0806e078:
    ldr r1, lbl_0806e0a0 @ =gChangedInput
    ldrh r2, [r1]
    movs r0, #0x40
    ands r0, r2
    adds r6, r1, #0
    cmp r0, #0
    beq lbl_0806e0a4
    adds r0, r3, #0
    adds r0, #0x30
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806e0c2
    adds r1, r3, #0
    adds r1, #0x25
    ldrb r0, [r1]
    subs r0, #1
    b lbl_0806e0be
    .align 2, 0
lbl_0806e09c: .4byte gButtonInput
lbl_0806e0a0: .4byte gChangedInput
lbl_0806e0a4:
    movs r0, #0x80
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e0c2
    adds r0, r3, #0
    adds r0, #0x31
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806e0c2
    adds r1, r3, #0
    adds r1, #0x25
    ldrb r0, [r1]
    adds r0, #1
lbl_0806e0be:
    strb r0, [r1]
    movs r4, #1
lbl_0806e0c2:
    ldrh r1, [r6]
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e0e0
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806e0fe
    adds r1, #0x24
    ldrb r0, [r1]
    subs r0, #1
    b lbl_0806e0fa
lbl_0806e0e0:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e0fe
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x2e
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806e0fe
    adds r1, #0x24
    ldrb r0, [r1]
    adds r0, #1
lbl_0806e0fa:
    strb r0, [r1]
    movs r4, #1
lbl_0806e0fe:
    ldr r2, lbl_0806e144 @ =gBG3HOFS_NonGameplay
    ldr r0, [r5]
    mov ip, r0
    adds r0, #0x24
    movs r1, #0
    ldrsb r1, [r0, r1]
    movs r0, #0xf
    subs r0, r0, r1
    lsls r0, r0, #3
    movs r1, #0x81
    lsls r1, r1, #2
    subs r0, r1, r0
    lsls r0, r0, #2
    strh r0, [r2]
    ldr r3, lbl_0806e148 @ =gBG3VOFS_NonGameplay
    mov r0, ip
    adds r0, #0x25
    movs r2, #0
    ldrsb r2, [r0, r2]
    movs r0, #0xa
    subs r0, r0, r2
    lsls r0, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #2
    strh r1, [r3]
    cmp r4, #1
    bne lbl_0806e15a
    mov r1, ip
    ldrb r0, [r1, #0x11]
    cmp r0, #0
    beq lbl_0806e150
    ldr r0, lbl_0806e14c @ =0x00000201
    bl SoundPlay
    b lbl_0806e1a2
    .align 2, 0
lbl_0806e144: .4byte gBG3HOFS_NonGameplay
lbl_0806e148: .4byte gBG3VOFS_NonGameplay
lbl_0806e14c: .4byte 0x00000201
lbl_0806e150:
    movs r0, #0x80
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0806e1a2
lbl_0806e15a:
    cmp r4, #0
    bne lbl_0806e1ea
    ldrh r1, [r6]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e174
    movs r0, #0xb
    mov r1, ip
    strb r0, [r1, #4]
    movs r4, #2
    b lbl_0806e190
lbl_0806e174:
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e18c
    ldr r0, lbl_0806e1bc @ =0x00000205
    bl SoundPlay
    ldr r1, [r5]
    movs r0, #0x10
    strb r0, [r1, #4]
    movs r4, #2
lbl_0806e18c:
    cmp r4, #0
    beq lbl_0806e1a6
lbl_0806e190:
    ldr r0, lbl_0806e1c0 @ =0x08754bc4
    ldr r1, [r0]
    movs r2, #0
    movs r0, #0
    strh r0, [r1, #0xa]
    strb r2, [r1, #8]
    movs r0, #1
    bl sub_0806e1f4
lbl_0806e1a2:
    cmp r4, #0
    bne lbl_0806e1ea
lbl_0806e1a6:
    ldr r0, lbl_0806e1c4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e1c8
    movs r0, #0
    bl sub_0806e1f4
    b lbl_0806e1ea
    .align 2, 0
lbl_0806e1bc: .4byte 0x00000205
lbl_0806e1c0: .4byte 0x08754bc4
lbl_0806e1c4: .4byte gChangedInput
lbl_0806e1c8:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0806e1ea
    ldr r0, lbl_0806e1f0 @ =0x08754bc4
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0xbb
    ldrb r0, [r0]
    cmp r0, #1
    bls lbl_0806e1ea
    ldrb r0, [r1, #0x12]
    cmp r0, #6
    bhi lbl_0806e1ea
    adds r1, #0xb4
    movs r0, #1
    strb r0, [r1]
lbl_0806e1ea:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806e1f0: .4byte 0x08754bc4

    thumb_func_start sub_0806e1f4
sub_0806e1f4: @ 0x0806e1f4
    push {r4, r5, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_0806e210
    ldr r3, lbl_0806e20c @ =0x08754bc4
    ldr r2, [r3]
    ldrb r0, [r2, #0x11]
    movs r1, #1
    eors r0, r1
    b lbl_0806e21e
    .align 2, 0
lbl_0806e20c: .4byte 0x08754bc4
lbl_0806e210:
    ldr r0, lbl_0806e260 @ =0x08754bc4
    ldr r2, [r0]
    ldrb r1, [r2, #0x11]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_0806e2b2
    movs r0, #0
lbl_0806e21e:
    strb r0, [r2, #0x11]
    ldr r0, [r3]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806e278
    ldr r0, lbl_0806e264 @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0xa0
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806e268 @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806e26c @ =0x083fd252
    ldr r2, lbl_0806e270 @ =0x05000002
    str r4, [sp]
    movs r0, #3
    movs r3, #0x9e
    bl DMATransfer
    movs r0, #1
    bl sub_08069024
    ldr r0, lbl_0806e274 @ =0x00000202
    bl SoundPlay
    b lbl_0806e2aa
    .align 2, 0
lbl_0806e260: .4byte 0x08754bc4
lbl_0806e264: .4byte 0x08754bb4
lbl_0806e268: .4byte 0x0600d000
lbl_0806e26c: .4byte 0x083fd252
lbl_0806e270: .4byte 0x05000002
lbl_0806e274: .4byte 0x00000202
lbl_0806e278:
    ldr r0, lbl_0806e2bc @ =0x08754bb4
    ldr r1, [r0]
    movs r0, #0x98
    lsls r0, r0, #8
    adds r1, r1, r0
    ldr r2, lbl_0806e2c0 @ =0x0600d000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0806e2c4 @ =0x08411362
    ldr r2, lbl_0806e2c8 @ =0x05000002
    str r4, [sp]
    movs r0, #3
    movs r3, #0x9e
    bl DMATransfer
    cmp r5, #0
    bne lbl_0806e2aa
    ldr r0, lbl_0806e2cc @ =0x00000203
    bl SoundPlay
lbl_0806e2aa:
    movs r0, #1
    movs r1, #0
    bl sub_0806b00c
lbl_0806e2b2:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806e2bc: .4byte 0x08754bb4
lbl_0806e2c0: .4byte 0x0600d000
lbl_0806e2c4: .4byte 0x08411362
lbl_0806e2c8: .4byte 0x05000002
lbl_0806e2cc: .4byte 0x00000203

    thumb_func_start map_screen_change_map
map_screen_change_map: @ 0x0806e2d0
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r5, lbl_0806e2f0 @ =0x08754bc4
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0xb4
    ldrb r4, [r0]
    adds r7, r5, #0
    cmp r4, #2
    beq lbl_0806e39c
    cmp r4, #2
    bgt lbl_0806e2f4
    cmp r4, #1
    beq lbl_0806e302
    b lbl_0806e454
    .align 2, 0
lbl_0806e2f0: .4byte 0x08754bc4
lbl_0806e2f4:
    cmp r4, #3
    bne lbl_0806e2fa
    b lbl_0806e42c
lbl_0806e2fa:
    cmp r4, #4
    bne lbl_0806e300
    b lbl_0806e442
lbl_0806e300:
    b lbl_0806e454
lbl_0806e302:
    movs r3, #0
    ldr r1, lbl_0806e390 @ =0x0840d67c
    ldrb r0, [r2, #0x12]
    ldrb r2, [r1]
    cmp r0, r2
    beq lbl_0806e324
    adds r2, r5, #0
    adds r4, r1, #0
lbl_0806e312:
    adds r3, #1
    cmp r3, #6
    bhi lbl_0806e324
    ldr r0, [r2]
    adds r1, r3, r4
    ldrb r0, [r0, #0x12]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0806e312
lbl_0806e324:
    cmp r3, #6
    bhi lbl_0806e324
    ldr r6, lbl_0806e394 @ =0x08754bc4
    ldr r5, lbl_0806e390 @ =0x0840d67c
    movs r4, #1
lbl_0806e32e:
    adds r3, #1
    cmp r3, #6
    bls lbl_0806e336
    movs r3, #0
lbl_0806e336:
    ldr r2, [r6]
    adds r0, r2, #0
    adds r0, #0xba
    ldrb r1, [r0]
    adds r0, r3, r5
    ldrb r0, [r0]
    asrs r1, r0
    ands r1, r4
    cmp r1, #0
    beq lbl_0806e32e
    strb r0, [r2, #0x12]
    ldr r0, [r7]
    movs r1, #0xba
    lsls r1, r1, #2
    adds r2, r0, r1
    movs r4, #0x3f
    movs r3, #0xb
lbl_0806e358:
    ldrb r1, [r2, #0xb]
    adds r0, r4, #0
    ands r0, r1
    strb r0, [r2, #0xb]
    subs r3, #1
    adds r2, #0x10
    cmp r3, #0
    bge lbl_0806e358
    ldr r1, [r7]
    ldr r2, lbl_0806e398 @ =0x00000403
    adds r1, r1, r2
    ldrb r2, [r1]
    movs r0, #0x3f
    ands r0, r2
    strb r0, [r1]
    ldr r0, [r7]
    adds r1, r0, #0
    adds r1, #0x6e
    ldrh r1, [r1]
    adds r0, #0x64
    strh r1, [r0]
    movs r0, #0x81
    lsls r0, r0, #2
    bl SoundPlay
    ldr r1, [r7]
    b lbl_0806e414
    .align 2, 0
lbl_0806e390: .4byte 0x0840d67c
lbl_0806e394: .4byte 0x08754bc4
lbl_0806e398: .4byte 0x00000403
lbl_0806e39c:
    movs r0, #0x82
    lsls r0, r0, #1
    adds r1, r2, r0
    ldrb r0, [r2, #0x12]
    lsls r0, r0, #0xb
    ldr r1, [r1]
    adds r1, r1, r0
    ldr r2, lbl_0806e420 @ =0x0600e000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #1
    bl chozo_statue_hint_determine_path
    ldr r0, [r5]
    ldr r2, lbl_0806e424 @ =gCurrentArea
    ldrb r1, [r0, #0x12]
    ldrb r0, [r2]
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r0, r4
    bl sub_0806db58
    ldr r2, [r5]
    ldr r1, lbl_0806e428 @ =0x00000403
    adds r2, r2, r1
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    ldrb r0, [r0, #0x12]
    bl sub_08068fd0
    ldr r0, [r5]
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    beq lbl_0806e3fe
    movs r0, #1
    bl sub_08069024
lbl_0806e3fe:
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x6c
    ldrh r1, [r1]
    adds r0, #0x64
    strh r1, [r0]
    bl sub_0806fe18
    bl sub_0806889c
    ldr r1, [r5]
lbl_0806e414:
    adds r1, #0xb4
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806e454
    .align 2, 0
lbl_0806e420: .4byte 0x0600e000
lbl_0806e424: .4byte gCurrentArea
lbl_0806e428: .4byte 0x00000403
lbl_0806e42c:
    bl count_tanks_in_area
    movs r0, #0
    movs r1, #0
    bl draw_in_game_time_and_tanks
    ldr r1, [r5]
    adds r1, #0xb4
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806e442:
    movs r0, #0
    movs r1, #1
    bl draw_in_game_time_and_tanks
    ldr r0, lbl_0806e45c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xb4
    movs r1, #0
    strb r1, [r0]
lbl_0806e454:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806e45c: .4byte 0x08754bc4

    thumb_func_start get_chararcter_width
get_chararcter_width: @ 0x0806e460
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_0806e474 @ =0x0000049f
    cmp r1, r0
    bhi lbl_0806e47c
    ldr r0, lbl_0806e478 @ =0x0840d7b0
    adds r0, r1, r0
    ldrb r0, [r0]
    b lbl_0806e47e
    .align 2, 0
lbl_0806e474: .4byte 0x0000049f
lbl_0806e478: .4byte 0x0840d7b0
lbl_0806e47c:
    movs r0, #0xa
lbl_0806e47e:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start draw_character_for_text
draw_character_for_text: @ 0x0806e484
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x2c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e550 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov sl, r0
lbl_0806e4c4:
    ldr r5, lbl_0806e550 @ =0x02027700
    mov r1, sl
    cmp r1, #0
    beq lbl_0806e4ce
    adds r5, #0x40
lbl_0806e4ce:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, sl
    lsls r1, r3, #0xa
    adds r4, r0, r1
    ldr r0, lbl_0806e554 @ =0x08415460
    adds r6, r4, r0
    movs r0, #8
    str r0, [sp, #0x14]
    str r1, [sp, #0x24]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bls lbl_0806e4ec
    movs r2, #0x10
    str r2, [sp, #0x14]
lbl_0806e4ec:
    ldr r3, [sp, #0x10]
    cmp r3, #0
    bne lbl_0806e4f4
    b lbl_0806e614
lbl_0806e4f4:
    ldr r0, [sp, #0xc]
    lsrs r0, r0, #8
    mov ip, r0
    mov r1, sl
    adds r1, #1
    str r1, [sp, #0x28]
    ldr r2, [sp, #0x14]
    cmp r2, #0
    bgt lbl_0806e508
    b lbl_0806e632
lbl_0806e508:
    ldr r3, lbl_0806e558 @ =0x08760338
    mov r8, r3
    ldr r7, lbl_0806e55c @ =0x08760398
    mov sb, r2
lbl_0806e510:
    ldr r4, [r6]
    cmp r4, #0
    beq lbl_0806e600
    movs r1, #0
    movs r3, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e522
    adds r3, r0, #0
lbl_0806e522:
    mov r0, r8
    ldr r2, [r0]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e538
    ldr r0, [r7]
    ands r0, r2
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_0806e538
    adds r1, r3, #0
lbl_0806e538:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #4]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e562
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e560
    orrs r1, r3
    b lbl_0806e562
    .align 2, 0
lbl_0806e550: .4byte 0x02027700
lbl_0806e554: .4byte 0x08415460
lbl_0806e558: .4byte 0x08760338
lbl_0806e55c: .4byte 0x08760398
lbl_0806e560:
    orrs r1, r2
lbl_0806e562:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #8]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e57c
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e57a
    orrs r1, r3
    b lbl_0806e57c
lbl_0806e57a:
    orrs r1, r2
lbl_0806e57c:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0xc]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e596
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e594
    orrs r1, r3
    b lbl_0806e596
lbl_0806e594:
    orrs r1, r2
lbl_0806e596:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x10]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5b0
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5ae
    orrs r1, r3
    b lbl_0806e5b0
lbl_0806e5ae:
    orrs r1, r2
lbl_0806e5b0:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x14]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5ca
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5c8
    orrs r1, r3
    b lbl_0806e5ca
lbl_0806e5c8:
    orrs r1, r2
lbl_0806e5ca:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x18]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5e4
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5e2
    orrs r1, r3
    b lbl_0806e5e4
lbl_0806e5e2:
    orrs r1, r2
lbl_0806e5e4:
    lsls r3, r3, #4
    mov r0, r8
    ldr r2, [r0, #0x1c]
    ands r2, r4
    cmp r2, #0
    beq lbl_0806e5fe
    ldr r0, [r7, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806e5fc
    orrs r1, r3
    b lbl_0806e5fe
lbl_0806e5fc:
    orrs r1, r2
lbl_0806e5fe:
    str r1, [r5]
lbl_0806e600:
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    adds r5, #4
    adds r6, #4
    mov r2, sb
    cmp r2, #0
    beq lbl_0806e612
    b lbl_0806e510
lbl_0806e612:
    b lbl_0806e632
lbl_0806e614:
    ldr r0, [sp, #0x14]
    lsls r3, r0, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r2, r5, #0
    bl DMATransfer
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    mov ip, r1
    mov r2, sl
    adds r2, #1
    str r2, [sp, #0x28]
lbl_0806e632:
    movs r0, #0xff
    ldr r3, [sp, #0xc]
    ands r0, r3
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r1, [sp, #8]
    adds r0, r1, r0
    ldr r2, [sp, #0x24]
    adds r5, r0, r2
    mov r3, ip
    lsls r0, r3, #0xb
    adds r5, r5, r0
    ldr r6, lbl_0806e7f8 @ =0x02027700
    mov r0, sl
    cmp r0, #0
    beq lbl_0806e654
    adds r6, #0x40
lbl_0806e654:
    movs r3, #7
    ldr r1, [sp, #0xc]
    ands r3, r1
    cmp r3, #0
    bne lbl_0806e660
    b lbl_0806e89a
lbl_0806e660:
    lsls r4, r3, #2
    movs r0, #0x20
    subs r0, r0, r4
    str r0, [sp, #0x14]
    ldr r2, [sp, #0x18]
    adds r3, r3, r2
    str r3, [sp, #0x1c]
    cmp r3, #8
    bgt lbl_0806e674
    b lbl_0806e848
lbl_0806e674:
    ldr r2, [r6]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r3, [r5, #0x20]
    orrs r3, r2
    str r3, [r5, #0x20]
    ldr r2, [r6, #4]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r7, [r5, #0x24]
    orrs r7, r2
    str r7, [r5, #0x24]
    ldr r2, [r6, #8]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x28]
    mov ip, r0
    mov r1, ip
    orrs r1, r2
    mov ip, r1
    str r1, [r5, #0x28]
    ldr r2, [r6, #0xc]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x2c]
    mov r8, r1
    mov r0, r8
    orrs r0, r2
    mov r8, r0
    str r0, [r5, #0x2c]
    ldr r2, [r6, #0x10]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x30]
    mov sb, r0
    mov r1, sb
    orrs r1, r2
    mov sb, r1
    str r1, [r5, #0x30]
    ldr r2, [r6, #0x14]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r1, [r5, #0x34]
    mov sl, r1
    mov r0, sl
    orrs r0, r2
    mov sl, r0
    str r0, [r5, #0x34]
    ldr r2, [r6, #0x18]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x38]
    orrs r0, r2
    str r0, [sp, #0x20]
    str r0, [r5, #0x38]
    ldr r2, [r6, #0x1c]
    adds r1, r2, #0
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r1, [r5, #0x3c]
    orrs r1, r2
    str r1, [r5, #0x3c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bhi lbl_0806e746
    b lbl_0806e920
lbl_0806e746:
    ldr r0, [sp, #0x1c]
    cmp r0, #0x10
    ble lbl_0806e7fc
    ldr r2, [r6, #0x20]
    adds r0, r2, #0
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r5, #0x40]
    orrs r0, r2
    str r0, [r5, #0x40]
    ldr r2, [r6, #0x24]
    adds r0, r2, #0
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    lsrs r2, r3
    ldr r0, [r5, #0x44]
    orrs r0, r2
    str r0, [r5, #0x44]
    ldr r2, [r6, #0x28]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, ip
    orrs r3, r0
    str r3, [r5, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x48]
    orrs r0, r2
    str r0, [r5, #0x48]
    ldr r2, [r6, #0x2c]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x4c]
    orrs r0, r2
    str r0, [r5, #0x4c]
    ldr r2, [r6, #0x30]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sb
    orrs r3, r0
    str r3, [r5, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x50]
    orrs r0, r2
    str r0, [r5, #0x50]
    ldr r2, [r6, #0x34]
    adds r0, r2, #0
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x54]
    orrs r0, r2
    str r0, [r5, #0x54]
    ldr r2, [r6, #0x38]
    adds r0, r2, #0
    lsls r0, r4
    ldr r3, [sp, #0x20]
    orrs r3, r0
    str r3, [r5, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r5, #0x58]
    orrs r0, r2
    str r0, [r5, #0x58]
    ldr r2, [r6, #0x3c]
    adds r0, r2, #0
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r5, #0x5c]
    orrs r0, r2
    str r0, [r5, #0x5c]
    b lbl_0806e920
    .align 2, 0
lbl_0806e7f8: .4byte 0x02027700
lbl_0806e7fc:
    ldr r0, [r6, #0x20]
    lsls r0, r4
    orrs r3, r0
    str r3, [r5, #0x20]
    ldr r0, [r6, #0x24]
    lsls r0, r4
    orrs r7, r0
    str r7, [r5, #0x24]
    ldr r0, [r6, #0x28]
    lsls r0, r4
    mov r2, ip
    orrs r2, r0
    str r2, [r5, #0x28]
    ldr r0, [r6, #0x2c]
    lsls r0, r4
    mov r3, r8
    orrs r3, r0
    str r3, [r5, #0x2c]
    ldr r0, [r6, #0x30]
    lsls r0, r4
    mov r2, sb
    orrs r2, r0
    str r2, [r5, #0x30]
    ldr r0, [r6, #0x34]
    lsls r0, r4
    mov r3, sl
    orrs r3, r0
    str r3, [r5, #0x34]
    ldr r0, [r6, #0x38]
    lsls r0, r4
    ldr r2, [sp, #0x20]
    orrs r2, r0
    str r2, [r5, #0x38]
    ldr r0, [r6, #0x3c]
    lsls r0, r4
    orrs r1, r0
    str r1, [r5, #0x3c]
    b lbl_0806e920
lbl_0806e848:
    ldr r1, [r6]
    lsls r1, r4
    ldr r0, [r5]
    orrs r0, r1
    str r0, [r5]
    ldr r1, [r6, #4]
    lsls r1, r4
    ldr r0, [r5, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r1, [r6, #8]
    lsls r1, r4
    ldr r0, [r5, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r1, [r6, #0xc]
    lsls r1, r4
    ldr r0, [r5, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r1, [r6, #0x10]
    lsls r1, r4
    ldr r0, [r5, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r1, [r6, #0x14]
    lsls r1, r4
    ldr r0, [r5, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r1, [r6, #0x18]
    lsls r1, r4
    ldr r0, [r5, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r1, [r6, #0x1c]
    lsls r1, r4
    ldr r0, [r5, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    b lbl_0806e920
lbl_0806e89a:
    ldr r0, [r5]
    ldr r1, [r6]
    orrs r0, r1
    str r0, [r5]
    ldr r0, [r5, #4]
    ldr r1, [r6, #4]
    orrs r0, r1
    str r0, [r5, #4]
    ldr r0, [r5, #8]
    ldr r1, [r6, #8]
    orrs r0, r1
    str r0, [r5, #8]
    ldr r0, [r5, #0xc]
    ldr r1, [r6, #0xc]
    orrs r0, r1
    str r0, [r5, #0xc]
    ldr r0, [r5, #0x10]
    ldr r1, [r6, #0x10]
    orrs r0, r1
    str r0, [r5, #0x10]
    ldr r0, [r5, #0x14]
    ldr r1, [r6, #0x14]
    orrs r0, r1
    str r0, [r5, #0x14]
    ldr r0, [r5, #0x18]
    ldr r1, [r6, #0x18]
    orrs r0, r1
    str r0, [r5, #0x18]
    ldr r0, [r5, #0x1c]
    ldr r1, [r6, #0x1c]
    orrs r0, r1
    str r0, [r5, #0x1c]
    ldr r3, [sp, #0x18]
    cmp r3, #8
    bls lbl_0806e920
    ldr r0, [r5, #0x20]
    ldr r1, [r6, #0x20]
    orrs r0, r1
    str r0, [r5, #0x20]
    ldr r0, [r5, #0x24]
    ldr r1, [r6, #0x24]
    orrs r0, r1
    str r0, [r5, #0x24]
    ldr r0, [r5, #0x28]
    ldr r1, [r6, #0x28]
    orrs r0, r1
    str r0, [r5, #0x28]
    ldr r0, [r5, #0x2c]
    ldr r1, [r6, #0x2c]
    orrs r0, r1
    str r0, [r5, #0x2c]
    ldr r0, [r5, #0x30]
    ldr r1, [r6, #0x30]
    orrs r0, r1
    str r0, [r5, #0x30]
    ldr r0, [r5, #0x34]
    ldr r1, [r6, #0x34]
    orrs r0, r1
    str r0, [r5, #0x34]
    ldr r0, [r5, #0x38]
    ldr r1, [r6, #0x38]
    orrs r0, r1
    str r0, [r5, #0x38]
    ldr r0, [r5, #0x3c]
    ldr r1, [r6, #0x3c]
    orrs r0, r1
    str r0, [r5, #0x3c]
lbl_0806e920:
    ldr r0, [sp, #0x28]
    mov sl, r0
    cmp r0, #1
    bgt lbl_0806e92a
    b lbl_0806e4c4
lbl_0806e92a:
    add sp, #0x2c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start draw_character_for_message
draw_character_for_message: @ 0x0806e93c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x3c
    str r1, [sp, #8]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp, #0xc]
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #0x10]
    ldr r2, lbl_0806e9e8 @ =0x02027700
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x80
    bl BitFill
    ldr r0, [sp, #4]
    bl get_chararcter_width
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp, #0x18]
    movs r0, #0
    mov ip, r0
lbl_0806e97c:
    ldr r4, lbl_0806e9e8 @ =0x02027700
    mov r1, ip
    cmp r1, #0
    beq lbl_0806e986
    adds r4, #0x40
lbl_0806e986:
    ldr r2, [sp, #4]
    lsls r0, r2, #5
    mov r3, ip
    lsls r1, r3, #0xa
    adds r3, r0, r1
    ldr r0, lbl_0806e9ec @ =0x08415460
    adds r5, r3, r0
    movs r6, #8
    str r6, [sp, #0x14]
    str r1, [sp, #0x34]
    ldr r7, [sp, #0x18]
    cmp r7, #8
    bls lbl_0806e9a4
    movs r0, #0x10
    str r0, [sp, #0x14]
lbl_0806e9a4:
    ldr r1, [sp, #0xc]
    lsrs r1, r1, #8
    str r1, [sp, #0x30]
    mov r2, ip
    adds r2, #1
    str r2, [sp, #0x38]
    ldr r3, [sp, #0x14]
    cmp r3, #0
    bgt lbl_0806e9b8
    b lbl_0806eb28
lbl_0806e9b8:
    ldr r6, lbl_0806e9f0 @ =0x08760338
    mov sb, r6
    ldr r7, lbl_0806e9f4 @ =0x08760398
    mov r8, r7
    mov sl, r3
lbl_0806e9c2:
    ldr r6, [r5]
    movs r1, #4
    ldr r0, [sp, #0x10]
    cmp r0, #0
    beq lbl_0806e9ce
    adds r1, r0, #0
lbl_0806e9ce:
    mov r3, sb
    ldr r2, [r3]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806e9f8
    mov r7, r8
    ldr r0, [r7]
    ands r0, r2
    adds r3, r2, #0
    cmp r0, #0
    beq lbl_0806e9fc
    adds r3, r1, #0
    b lbl_0806e9fc
    .align 2, 0
lbl_0806e9e8: .4byte 0x02027700
lbl_0806e9ec: .4byte 0x08415460
lbl_0806e9f0: .4byte 0x08760338
lbl_0806e9f4: .4byte 0x08760398
lbl_0806e9f8:
    ldr r0, lbl_0806ea18 @ =0x087603b8
    ldr r3, [r0]
lbl_0806e9fc:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #4]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea20
    mov r7, r8
    ldr r0, [r7, #4]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea1c
    orrs r3, r1
    b lbl_0806ea26
    .align 2, 0
lbl_0806ea18: .4byte 0x087603b8
lbl_0806ea1c:
    orrs r3, r2
    b lbl_0806ea26
lbl_0806ea20:
    ldr r2, lbl_0806ea40 @ =0x087603b8
    ldr r0, [r2, #4]
    orrs r3, r0
lbl_0806ea26:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #8]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea48
    mov r7, r8
    ldr r0, [r7, #8]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea44
    orrs r3, r1
    b lbl_0806ea4e
    .align 2, 0
lbl_0806ea40: .4byte 0x087603b8
lbl_0806ea44:
    orrs r3, r2
    b lbl_0806ea4e
lbl_0806ea48:
    ldr r2, lbl_0806ea68 @ =0x087603b8
    ldr r0, [r2, #8]
    orrs r3, r0
lbl_0806ea4e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0xc]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea70
    mov r7, r8
    ldr r0, [r7, #0xc]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea6c
    orrs r3, r1
    b lbl_0806ea76
    .align 2, 0
lbl_0806ea68: .4byte 0x087603b8
lbl_0806ea6c:
    orrs r3, r2
    b lbl_0806ea76
lbl_0806ea70:
    ldr r2, lbl_0806ea90 @ =0x087603b8
    ldr r0, [r2, #0xc]
    orrs r3, r0
lbl_0806ea76:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x10]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806ea98
    mov r7, r8
    ldr r0, [r7, #0x10]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806ea94
    orrs r3, r1
    b lbl_0806ea9e
    .align 2, 0
lbl_0806ea90: .4byte 0x087603b8
lbl_0806ea94:
    orrs r3, r2
    b lbl_0806ea9e
lbl_0806ea98:
    ldr r2, lbl_0806eab8 @ =0x087603b8
    ldr r0, [r2, #0x10]
    orrs r3, r0
lbl_0806ea9e:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x14]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eac0
    mov r7, r8
    ldr r0, [r7, #0x14]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eabc
    orrs r3, r1
    b lbl_0806eac6
    .align 2, 0
lbl_0806eab8: .4byte 0x087603b8
lbl_0806eabc:
    orrs r3, r2
    b lbl_0806eac6
lbl_0806eac0:
    ldr r2, lbl_0806eae0 @ =0x087603b8
    ldr r0, [r2, #0x14]
    orrs r3, r0
lbl_0806eac6:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x18]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eae8
    mov r7, r8
    ldr r0, [r7, #0x18]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eae4
    orrs r3, r1
    b lbl_0806eaee
    .align 2, 0
lbl_0806eae0: .4byte 0x087603b8
lbl_0806eae4:
    orrs r3, r2
    b lbl_0806eaee
lbl_0806eae8:
    ldr r2, lbl_0806eb08 @ =0x087603b8
    ldr r0, [r2, #0x18]
    orrs r3, r0
lbl_0806eaee:
    lsls r1, r1, #4
    mov r7, sb
    ldr r2, [r7, #0x1c]
    ands r2, r6
    cmp r2, #0
    beq lbl_0806eb10
    mov r6, r8
    ldr r0, [r6, #0x1c]
    ands r0, r2
    cmp r0, #0
    beq lbl_0806eb0c
    orrs r3, r1
    b lbl_0806eb16
    .align 2, 0
lbl_0806eb08: .4byte 0x087603b8
lbl_0806eb0c:
    orrs r3, r2
    b lbl_0806eb16
lbl_0806eb10:
    ldr r7, lbl_0806ed90 @ =0x087603b8
    ldr r0, [r7, #0x1c]
    orrs r3, r0
lbl_0806eb16:
    stm r4!, {r3}
    movs r0, #1
    rsbs r0, r0, #0
    add sl, r0
    adds r5, #4
    mov r1, sl
    cmp r1, #0
    beq lbl_0806eb28
    b lbl_0806e9c2
lbl_0806eb28:
    movs r0, #0xff
    ldr r2, [sp, #0xc]
    ands r0, r2
    lsrs r0, r0, #3
    lsls r0, r0, #5
    ldr r3, [sp, #8]
    adds r0, r3, r0
    ldr r6, [sp, #0x34]
    adds r4, r0, r6
    ldr r7, [sp, #0x30]
    lsls r0, r7, #0xb
    adds r4, r4, r0
    ldr r5, lbl_0806ed94 @ =0x02027700
    mov r0, ip
    cmp r0, #0
    beq lbl_0806eb4a
    adds r5, #0x40
lbl_0806eb4a:
    movs r1, #7
    ldr r2, [sp, #0xc]
    ands r1, r2
    cmp r1, #0
    bne lbl_0806eb56
    b lbl_0806ee8c
lbl_0806eb56:
    lsls r3, r1, #2
    movs r0, #8
    subs r0, r0, r1
    mov sl, r0
    movs r0, #0x20
    subs r0, r0, r3
    str r0, [sp, #0x14]
    ldr r6, [sp, #0x18]
    adds r1, r1, r6
    str r1, [sp, #0x1c]
    cmp r1, #8
    bgt lbl_0806eb70
    b lbl_0806ee12
lbl_0806eb70:
    ldr r2, [r5]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, lbl_0806ed98 @ =0x087602f0
    adds r6, r3, r0
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r7, [sp, #0x14]
    lsrs r2, r7
    ldr r1, lbl_0806ed9c @ =0x08760314
    mov r7, sl
    lsls r0, r7, #2
    adds r7, r0, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x20]
    mov ip, r0
    mov r1, ip
    ands r1, r2
    mov ip, r1
    str r1, [r4, #0x20]
    ldr r2, [r5, #4]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x24]
    mov r8, r1
    mov r0, r8
    ands r0, r2
    mov r8, r0
    str r0, [r4, #0x24]
    ldr r2, [r5, #8]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x28]
    mov sb, r0
    mov r1, sb
    ands r1, r2
    mov sb, r1
    str r1, [r4, #0x28]
    ldr r2, [r5, #0xc]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r1, [r4, #0x2c]
    mov sl, r1
    mov r0, sl
    ands r0, r2
    mov sl, r0
    str r0, [r4, #0x2c]
    ldr r2, [r5, #0x10]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x30]
    ands r0, r2
    str r0, [sp, #0x20]
    str r0, [r4, #0x30]
    ldr r2, [r5, #0x14]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x34]
    ands r0, r2
    str r0, [sp, #0x24]
    str r0, [r4, #0x34]
    ldr r2, [r5, #0x18]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x38]
    ands r0, r2
    str r0, [sp, #0x28]
    str r0, [r4, #0x38]
    ldr r2, [r5, #0x1c]
    adds r1, r2, #0
    lsls r1, r3
    ldr r0, [r6]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r1, [sp, #0x14]
    lsrs r2, r1
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x3c]
    ands r0, r2
    str r0, [sp, #0x2c]
    str r0, [r4, #0x3c]
    ldr r1, [sp, #0x18]
    cmp r1, #8
    bhi lbl_0806ec94
    b lbl_0806ef12
lbl_0806ec94:
    ldr r2, [sp, #0x1c]
    cmp r2, #0x10
    bgt lbl_0806ec9c
    b lbl_0806eda0
lbl_0806ec9c:
    ldr r2, [r5, #0x20]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, ip
    ands r1, r0
    str r1, [r4, #0x20]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x40]
    ands r0, r2
    str r0, [r4, #0x40]
    ldr r2, [r5, #0x24]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x44]
    ands r0, r2
    str r0, [r4, #0x44]
    ldr r2, [r5, #0x28]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sb
    ands r1, r0
    str r1, [r4, #0x28]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x48]
    ands r0, r2
    str r0, [r4, #0x48]
    ldr r2, [r5, #0x2c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, sl
    ands r1, r0
    str r1, [r4, #0x2c]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x4c]
    ands r0, r2
    str r0, [r4, #0x4c]
    ldr r2, [r5, #0x30]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x50]
    ands r0, r2
    str r0, [r4, #0x50]
    ldr r2, [r5, #0x34]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x24]
    ands r1, r0
    str r1, [r4, #0x34]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x54]
    ands r0, r2
    str r0, [r4, #0x54]
    ldr r2, [r5, #0x38]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x28]
    ands r1, r0
    str r1, [r4, #0x38]
    ldr r0, [sp, #0x14]
    lsrs r2, r0
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x58]
    ands r0, r2
    str r0, [r4, #0x58]
    ldr r2, [r5, #0x3c]
    adds r0, r2, #0
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    ldr r3, [sp, #0x14]
    lsrs r2, r3
    ldr r0, [r7]
    orrs r2, r0
    ldr r0, [r4, #0x5c]
    ands r0, r2
    str r0, [r4, #0x5c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ed90: .4byte 0x087603b8
lbl_0806ed94: .4byte 0x02027700
lbl_0806ed98: .4byte 0x087602f0
lbl_0806ed9c: .4byte 0x08760314
lbl_0806eda0:
    ldr r0, [r5, #0x20]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, ip
    ands r7, r0
    str r7, [r4, #0x20]
    ldr r0, [r5, #0x24]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r1, r8
    ands r1, r0
    str r1, [r4, #0x24]
    ldr r0, [r5, #0x28]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r2, sb
    ands r2, r0
    str r2, [r4, #0x28]
    ldr r0, [r5, #0x2c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    mov r7, sl
    ands r7, r0
    str r7, [r4, #0x2c]
    ldr r0, [r5, #0x30]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x20]
    ands r1, r0
    str r1, [r4, #0x30]
    ldr r0, [r5, #0x34]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r2, [sp, #0x24]
    ands r2, r0
    str r2, [r4, #0x34]
    ldr r0, [r5, #0x38]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r7, [sp, #0x28]
    ands r7, r0
    str r7, [r4, #0x38]
    ldr r0, [r5, #0x3c]
    lsls r0, r3
    ldr r1, [r6]
    orrs r0, r1
    ldr r1, [sp, #0x2c]
    ands r1, r0
    str r1, [r4, #0x3c]
    b lbl_0806ef12
lbl_0806ee12:
    ldr r1, [r5]
    lsls r1, r3
    ldr r2, lbl_0806ee88 @ =0x087602f0
    adds r2, r3, r2
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4]
    ands r0, r1
    str r0, [r4]
    ldr r1, [r5, #4]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r1, [r5, #8]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r1, [r5, #0xc]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r1, [r5, #0x10]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r1, [r5, #0x14]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r1, [r5, #0x18]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r1, [r5, #0x1c]
    lsls r1, r3
    ldr r0, [r2]
    orrs r1, r0
    ldr r0, [r4, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    b lbl_0806ef12
    .align 2, 0
lbl_0806ee88: .4byte 0x087602f0
lbl_0806ee8c:
    ldr r0, [r4]
    ldr r1, [r5]
    ands r0, r1
    str r0, [r4]
    ldr r0, [r4, #4]
    ldr r1, [r5, #4]
    ands r0, r1
    str r0, [r4, #4]
    ldr r0, [r4, #8]
    ldr r1, [r5, #8]
    ands r0, r1
    str r0, [r4, #8]
    ldr r0, [r4, #0xc]
    ldr r1, [r5, #0xc]
    ands r0, r1
    str r0, [r4, #0xc]
    ldr r0, [r4, #0x10]
    ldr r1, [r5, #0x10]
    ands r0, r1
    str r0, [r4, #0x10]
    ldr r0, [r4, #0x14]
    ldr r1, [r5, #0x14]
    ands r0, r1
    str r0, [r4, #0x14]
    ldr r0, [r4, #0x18]
    ldr r1, [r5, #0x18]
    ands r0, r1
    str r0, [r4, #0x18]
    ldr r0, [r4, #0x1c]
    ldr r1, [r5, #0x1c]
    ands r0, r1
    str r0, [r4, #0x1c]
    ldr r2, [sp, #0x18]
    cmp r2, #8
    bls lbl_0806ef12
    ldr r0, [r4, #0x20]
    ldr r1, [r5, #0x20]
    ands r0, r1
    str r0, [r4, #0x20]
    ldr r0, [r4, #0x24]
    ldr r1, [r5, #0x24]
    ands r0, r1
    str r0, [r4, #0x24]
    ldr r0, [r4, #0x28]
    ldr r1, [r5, #0x28]
    ands r0, r1
    str r0, [r4, #0x28]
    ldr r0, [r4, #0x2c]
    ldr r1, [r5, #0x2c]
    ands r0, r1
    str r0, [r4, #0x2c]
    ldr r0, [r4, #0x30]
    ldr r1, [r5, #0x30]
    ands r0, r1
    str r0, [r4, #0x30]
    ldr r0, [r4, #0x34]
    ldr r1, [r5, #0x34]
    ands r0, r1
    str r0, [r4, #0x34]
    ldr r0, [r4, #0x38]
    ldr r1, [r5, #0x38]
    ands r0, r1
    str r0, [r4, #0x38]
    ldr r0, [r4, #0x3c]
    ldr r1, [r5, #0x3c]
    ands r0, r1
    str r0, [r4, #0x3c]
lbl_0806ef12:
    ldr r3, [sp, #0x38]
    mov ip, r3
    cmp r3, #1
    bgt lbl_0806ef1c
    b lbl_0806e97c
lbl_0806ef1c:
    add sp, #0x3c
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start draw_location_text_characters
draw_location_text_characters: @ 0x0806ef2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    adds r6, r1, #0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0806ef48
    movs r0, #0x80
    lsls r0, r0, #0x12
    mov sl, r0
    b lbl_0806ef72
lbl_0806ef48:
    cmp r0, #2
    bne lbl_0806f00a
    ldr r1, lbl_0806efa8 @ =0x02000800
    mov sl, r1
    ldr r2, [r6]
    ldrh r0, [r2]
    movs r1, #0xfe
    lsls r1, r1, #8
    cmp r0, r1
    beq lbl_0806ef6c
    adds r3, r1, #0
lbl_0806ef5e:
    adds r0, r2, #0
    adds r1, r0, #2
    adds r2, r1, #0
    ldrh r0, [r0, #2]
    cmp r0, r3
    bne lbl_0806ef5e
    str r1, [r6]
lbl_0806ef6c:
    ldr r0, [r6]
    adds r0, #2
    str r0, [r6]
lbl_0806ef72:
    movs r7, #0
    movs r0, #0
    mov r8, r0
    ldr r3, [r6]
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r3]
    cmp r1, ip
    beq lbl_0806f00a
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806f00a
    movs r0, #0xff
    mov sb, r0
lbl_0806ef92:
    movs r5, #1
    ldrh r2, [r3]
    mov r1, ip
    ands r1, r2
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efac
    mov r4, sb
    ands r4, r2
    b lbl_0806efec
    .align 2, 0
lbl_0806efa8: .4byte 0x02000800
lbl_0806efac:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efbc
    movs r4, #0
    mov r7, sb
    ands r7, r2
    b lbl_0806efec
lbl_0806efbc:
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806efd0
    movs r4, #0
    mov r8, sb
    mov r1, r8
    ands r1, r2
    mov r8, r1
    movs r5, #0
lbl_0806efd0:
    cmp r5, #0
    beq lbl_0806efec
    ldrh r0, [r3]
    bl get_chararcter_width
    adds r4, r0, #0
    ldr r0, [r6]
    ldrh r0, [r0]
    lsls r2, r7, #0x10
    lsrs r2, r2, #0x10
    mov r3, r8
    mov r1, sl
    bl draw_character_for_message
lbl_0806efec:
    ldr r0, [r6]
    adds r2, r0, #2
    str r2, [r6]
    adds r7, r7, r4
    movs r1, #0xff
    lsls r1, r1, #8
    mov ip, r1
    ldrh r1, [r0, #2]
    cmp r1, ip
    beq lbl_0806f00a
    adds r3, r2, #0
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    bne lbl_0806ef92
lbl_0806f00a:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start draw_location_text
draw_location_text: @ 0x0806f018
    push {r4, r5, r6, lr}
    sub sp, #8
    adds r4, r0, #0
    adds r5, r1, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    lsls r5, r5, #0x18
    lsrs r5, r5, #0x18
    ldr r1, lbl_0806f088 @ =0x0000ffff
    movs r6, #0x80
    lsls r6, r6, #0x12
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    bl BitFill
    ldr r1, lbl_0806f08c @ =0x08760764
    ldr r0, lbl_0806f090 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    lsls r4, r4, #2
    adds r4, r4, r0
    ldr r0, [r4]
    str r0, [sp, #4]
    movs r0, #1
    add r1, sp, #4
    bl draw_location_text_characters
    ldr r0, lbl_0806f094 @ =0x040000d4
    str r6, [r0]
    lsls r5, r5, #0xb
    ldr r2, lbl_0806f098 @ =0x06014000
    adds r1, r5, r2
    str r1, [r0, #4]
    ldr r2, lbl_0806f09c @ =0x840000e0
    str r2, [r0, #8]
    ldr r1, [r0, #8]
    ldr r1, lbl_0806f0a0 @ =0x02000400
    str r1, [r0]
    ldr r1, lbl_0806f0a4 @ =0x06014400
    adds r5, r5, r1
    str r5, [r0, #4]
    str r2, [r0, #8]
    ldr r0, [r0, #8]
    add sp, #8
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f088: .4byte 0x0000ffff
lbl_0806f08c: .4byte 0x08760764
lbl_0806f090: .4byte gLanguage
lbl_0806f094: .4byte 0x040000d4
lbl_0806f098: .4byte 0x06014000
lbl_0806f09c: .4byte 0x840000e0
lbl_0806f0a0: .4byte 0x02000400
lbl_0806f0a4: .4byte 0x06014400

    thumb_func_start sub_0806f0a8
sub_0806f0a8: @ 0x0806f0a8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov ip, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r7, lbl_0806f0ec @ =gCurrentMessage
    cmp r2, #0xf
    bne lbl_0806f0da
    adds r0, r7, #0
    ldr r1, lbl_0806f0f0 @ =0x0840dc50
    ldm r1!, {r4, r5, r6}
    stm r0!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r0]
    adds r0, r3, #0
    cmp r3, #0x23
    bls lbl_0806f0d4
    movs r0, #0x23
lbl_0806f0d4:
    strb r0, [r7, #0xa]
    mov r0, ip
    strb r0, [r7, #0xb]
lbl_0806f0da:
    ldrb r0, [r7, #0xc]
    cmp r0, #4
    bls lbl_0806f0e2
    b lbl_0806f23e
lbl_0806f0e2:
    lsls r0, r0, #2
    ldr r1, lbl_0806f0f4 @ =lbl_0806f0f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f0ec: .4byte gCurrentMessage
lbl_0806f0f0: .4byte 0x0840dc50
lbl_0806f0f4: .4byte lbl_0806f0f8
lbl_0806f0f8: @ jump table
    .4byte lbl_0806f10c @ case 0
    .4byte lbl_0806f13c @ case 1
    .4byte lbl_0806f180 @ case 2
    .4byte lbl_0806f218 @ case 3
    .4byte lbl_0806f23e @ case 4
lbl_0806f10c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f134 @ =0x06014000
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f138 @ =0x06014400
    b lbl_0806f160
    .align 2, 0
lbl_0806f134: .4byte 0x06014000
lbl_0806f138: .4byte 0x06014400
lbl_0806f13c:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f178 @ =0x06014800
    adds r2, r2, r3
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f17c @ =0x06014c00
lbl_0806f160:
    adds r2, r2, r0
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f24c
    .align 2, 0
lbl_0806f178: .4byte 0x06014800
lbl_0806f17c: .4byte 0x06014c00
lbl_0806f180:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f18e
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f196
lbl_0806f18e:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f196:
    cmp r2, #1
    bne lbl_0806f1a2
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f1a2:
    cmp r5, #0
    beq lbl_0806f24c
    ldr r4, lbl_0806f1e8 @ =gCurrentMessage
    ldr r6, lbl_0806f1ec @ =0x08760780
lbl_0806f1aa:
    ldr r0, lbl_0806f1f0 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f1f4 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f1fe
    cmp r0, #2
    bgt lbl_0806f1f8
    cmp r0, #1
    beq lbl_0806f204
    b lbl_0806f20a
    .align 2, 0
lbl_0806f1e8: .4byte gCurrentMessage
lbl_0806f1ec: .4byte 0x08760780
lbl_0806f1f0: .4byte gLanguage
lbl_0806f1f4: .4byte 0x06014000
lbl_0806f1f8:
    cmp r0, #4
    beq lbl_0806f204
    b lbl_0806f20a
lbl_0806f1fe:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f204:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f24c
lbl_0806f20a:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f24c
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f1aa
    b lbl_0806f24c
lbl_0806f218:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f234
    ldr r0, lbl_0806f248 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f234
    bl finish_collecting_ability
lbl_0806f234:
    ldr r1, lbl_0806f244 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f23e:
    ldrb r0, [r7, #7]
    b lbl_0806f24e
    .align 2, 0
lbl_0806f244: .4byte gCurrentMessage
lbl_0806f248: .4byte gCurrentItemBeingAcquired
lbl_0806f24c:
    movs r0, #0
lbl_0806f24e:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start start_message
start_message: @ 0x0806f258
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    ldr r3, lbl_0806f284 @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f288 @ =0x0840dc50
    ldm r1!, {r5, r6, r7}
    stm r2!, {r5, r6, r7}
    ldr r1, [r1]
    str r1, [r2]
    adds r1, r0, #0
    cmp r0, #0x23
    bls lbl_0806f278
    movs r1, #0x23
lbl_0806f278:
    strb r1, [r3, #0xa]
    strb r4, [r3, #0xb]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f284: .4byte gCurrentMessage
lbl_0806f288: .4byte 0x0840dc50

    thumb_func_start process_item_banner_text
process_item_banner_text: @ 0x0806f28c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f2a8 @ =gCurrentMessage
    ldrb r2, [r0, #0xc]
    adds r7, r0, #0
    cmp r2, #4
    bls lbl_0806f29c
    b lbl_0806f3ea
lbl_0806f29c:
    lsls r0, r2, #2
    ldr r1, lbl_0806f2ac @ =lbl_0806f2b0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f2a8: .4byte gCurrentMessage
lbl_0806f2ac: .4byte lbl_0806f2b0
lbl_0806f2b0: @ jump table
    .4byte lbl_0806f2c4 @ case 0
    .4byte lbl_0806f2f4 @ case 1
    .4byte lbl_0806f338 @ case 2
    .4byte lbl_0806f3c4 @ case 3
    .4byte lbl_0806f3ea @ case 4
lbl_0806f2c4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f2ec @ =0x06014000
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f2f0 @ =0x06014400
    b lbl_0806f318
    .align 2, 0
lbl_0806f2ec: .4byte 0x06014000
lbl_0806f2f0: .4byte 0x06014400
lbl_0806f2f4:
    movs r6, #1
    rsbs r6, r6, #0
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r0, lbl_0806f330 @ =0x06014800
    adds r2, r2, r0
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r2, [r7, #0xb]
    lsls r2, r2, #0xb
    ldr r3, lbl_0806f334 @ =0x06014c00
lbl_0806f318:
    adds r2, r2, r3
    str r4, [sp]
    movs r0, #3
    adds r1, r6, #0
    adds r3, r5, #0
    bl BitFill
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    b lbl_0806f3f8
    .align 2, 0
lbl_0806f330: .4byte 0x06014800
lbl_0806f334: .4byte 0x06014c00
lbl_0806f338:
    movs r5, #8
    ldrb r0, [r7, #7]
    cmp r0, #1
    bhi lbl_0806f346
    ldrb r0, [r7, #0xe]
    cmp r0, #0
    beq lbl_0806f34e
lbl_0806f346:
    ldrb r0, [r7, #0xc]
    adds r0, #1
    strb r0, [r7, #0xc]
    movs r5, #0
lbl_0806f34e:
    cmp r5, #0
    beq lbl_0806f3f8
    ldr r4, lbl_0806f394 @ =gCurrentMessage
    ldr r6, lbl_0806f398 @ =0x08760780
lbl_0806f356:
    ldr r0, lbl_0806f39c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldrb r2, [r4, #0xb]
    lsls r2, r2, #0xb
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    ldr r3, lbl_0806f3a0 @ =0x06014000
    adds r0, r0, r3
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f3aa
    cmp r0, #2
    bgt lbl_0806f3a4
    cmp r0, #1
    beq lbl_0806f3b0
    b lbl_0806f3b6
    .align 2, 0
lbl_0806f394: .4byte gCurrentMessage
lbl_0806f398: .4byte 0x08760780
lbl_0806f39c: .4byte gLanguage
lbl_0806f3a0: .4byte 0x06014000
lbl_0806f3a4:
    cmp r0, #4
    beq lbl_0806f3b0
    b lbl_0806f3b6
lbl_0806f3aa:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f3b0:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f3f8
lbl_0806f3b6:
    ldrb r0, [r4, #7]
    cmp r0, #1
    bhi lbl_0806f3f8
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f356
    b lbl_0806f3f8
lbl_0806f3c4:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #7]
    adds r0, #1
    strb r0, [r1, #7]
    ldrb r2, [r1, #0xa]
    adds r1, r2, #0
    cmp r1, #0x15
    bhi lbl_0806f3e0
    ldr r0, lbl_0806f3f4 @ =gCurrentItemBeingAcquired
    strb r2, [r0]
    cmp r1, #7
    bls lbl_0806f3e0
    bl finish_collecting_ability
lbl_0806f3e0:
    ldr r1, lbl_0806f3f0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    adds r7, r1, #0
lbl_0806f3ea:
    ldrb r0, [r7, #7]
    b lbl_0806f3fa
    .align 2, 0
lbl_0806f3f0: .4byte gCurrentMessage
lbl_0806f3f4: .4byte gCurrentItemBeingAcquired
lbl_0806f3f8:
    movs r0, #0
lbl_0806f3fa:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start TextStartStory
TextStartStory: @ 0x0806f404
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f41c @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f420 @ =0x0840dc60
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f41c: .4byte gCurrentMessage
lbl_0806f420: .4byte 0x0840dc60

    thumb_func_start TextProcessStory
TextProcessStory: @ 0x0806f424
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806f440 @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r6, r0, #0
    cmp r1, #4
    bls lbl_0806f434
    b lbl_0806f594
lbl_0806f434:
    lsls r0, r1, #2
    ldr r1, lbl_0806f444 @ =lbl_0806f448
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f440: .4byte gCurrentMessage
lbl_0806f444: .4byte lbl_0806f448
lbl_0806f448: @ jump table
    .4byte lbl_0806f45c @ case 0
    .4byte lbl_0806f49c @ case 1
    .4byte lbl_0806f4d4 @ case 2
    .4byte lbl_0806f588 @ case 3
    .4byte lbl_0806f594 @ case 4
lbl_0806f45c:
    ldrb r1, [r6, #0xa]
    cmp r1, #1
    bne lbl_0806f46a
    movs r0, #2
    strb r0, [r6, #0xc]
    strb r1, [r6, #0xb]
    b lbl_0806f598
lbl_0806f46a:
    ldr r2, lbl_0806f494 @ =0x06007000
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f498 @ =0x06007400
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    movs r0, #1
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f494: .4byte 0x06007000
lbl_0806f498: .4byte 0x06007400
lbl_0806f49c:
    ldr r2, lbl_0806f4c8 @ =0x06007800
    movs r5, #0xe0
    lsls r5, r5, #2
    movs r4, #0x20
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r2, lbl_0806f4cc @ =0x06007c00
    str r4, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r5, #0
    bl BitFill
    ldr r1, lbl_0806f4d0 @ =gCurrentMessage
    ldrb r0, [r1, #0xc]
    adds r0, #1
    strb r0, [r1, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f4c8: .4byte 0x06007800
lbl_0806f4cc: .4byte 0x06007c00
lbl_0806f4d0: .4byte gCurrentMessage
lbl_0806f4d4:
    movs r7, #6
    ldrb r0, [r6, #0xb]
    cmp r0, #0
    beq lbl_0806f4f4
    ldrb r0, [r6, #7]
    cmp r0, #9
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f4f0 @ =0x06013000
    b lbl_0806f506
    .align 2, 0
lbl_0806f4f0: .4byte 0x06013000
lbl_0806f4f4:
    ldrb r0, [r6, #7]
    cmp r0, #1
    bhi lbl_0806f50c
    ldrb r0, [r6, #0xe]
    cmp r0, #0
    bne lbl_0806f50c
    ldrb r0, [r6, #7]
    lsls r0, r0, #0xb
    ldr r1, lbl_0806f514 @ =0x06007000
lbl_0806f506:
    adds r5, r0, r1
    cmp r7, #0
    bne lbl_0806f518
lbl_0806f50c:
    movs r0, #3
    strb r0, [r6, #0xc]
    b lbl_0806f598
    .align 2, 0
lbl_0806f514: .4byte 0x06007000
lbl_0806f518:
    ldr r4, lbl_0806f54c @ =gCurrentMessage
    ldr r6, lbl_0806f550 @ =0x0875fee0
lbl_0806f51c:
    ldr r0, lbl_0806f554 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #2
    beq lbl_0806f55e
    cmp r1, #2
    bgt lbl_0806f558
    cmp r1, #1
    beq lbl_0806f564
    b lbl_0806f56a
    .align 2, 0
lbl_0806f54c: .4byte gCurrentMessage
lbl_0806f550: .4byte 0x0875fee0
lbl_0806f554: .4byte gLanguage
lbl_0806f558:
    cmp r1, #4
    beq lbl_0806f564
    b lbl_0806f56a
lbl_0806f55e:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f564:
    movs r0, #0
    strh r0, [r4, #2]
    b lbl_0806f598
lbl_0806f56a:
    ldr r2, lbl_0806f584 @ =gCurrentMessage
    ldrb r0, [r2, #0xb]
    movs r1, #2
    cmp r0, #0
    beq lbl_0806f576
    movs r1, #0xa
lbl_0806f576:
    ldrb r0, [r2, #7]
    cmp r0, r1
    bge lbl_0806f598
    subs r7, #1
    cmp r7, #0
    bne lbl_0806f51c
    b lbl_0806f598
    .align 2, 0
lbl_0806f584: .4byte gCurrentMessage
lbl_0806f588:
    ldrb r0, [r6, #7]
    adds r0, #1
    strb r0, [r6, #7]
    ldrb r0, [r6, #0xc]
    adds r0, #1
    strb r0, [r6, #0xc]
lbl_0806f594:
    ldrb r0, [r6, #7]
    b lbl_0806f59a
lbl_0806f598:
    movs r0, #0
lbl_0806f59a:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start start_file_screen_text
start_file_screen_text: @ 0x0806f5a4
    push {r4, r5, r6, lr}
    ldr r3, lbl_0806f5bc @ =gCurrentMessage
    adds r2, r3, #0
    ldr r1, lbl_0806f5c0 @ =0x0840dc70
    ldm r1!, {r4, r5, r6}
    stm r2!, {r4, r5, r6}
    ldr r1, [r1]
    str r1, [r2]
    strb r0, [r3, #0xa]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f5bc: .4byte gCurrentMessage
lbl_0806f5c0: .4byte 0x0840dc70

    thumb_func_start sub_0806f5c4
sub_0806f5c4: @ 0x0806f5c4
    push {r4, r5, r6, lr}
    ldr r0, lbl_0806f5ec @ =gCurrentMessage
    ldrb r1, [r0, #0xc]
    adds r2, r0, #0
    cmp r1, #1
    beq lbl_0806f668
    cmp r1, #1
    bgt lbl_0806f674
    cmp r1, #0
    bne lbl_0806f674
    movs r5, #8
    ldrb r0, [r2, #7]
    cmp r0, #3
    bhi lbl_0806f5e6
    ldrb r0, [r2, #0xe]
    cmp r0, #0
    beq lbl_0806f5f0
lbl_0806f5e6:
    movs r0, #1
    strb r0, [r2, #0xc]
    b lbl_0806f678
    .align 2, 0
lbl_0806f5ec: .4byte gCurrentMessage
lbl_0806f5f0:
    ldrb r0, [r2, #7]
    lsls r0, r0, #0xb
    movs r1, #0xc0
    lsls r1, r1, #0x13
    adds r6, r0, r1
lbl_0806f5fa:
    ldr r4, lbl_0806f630 @ =gCurrentMessage
    ldr r1, lbl_0806f634 @ =0x0876079c
    ldr r0, lbl_0806f638 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r4, #0xa]
    ldr r0, [r0]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    adds r2, r6, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    beq lbl_0806f642
    cmp r0, #2
    bgt lbl_0806f63c
    cmp r0, #1
    beq lbl_0806f648
    b lbl_0806f654
    .align 2, 0
lbl_0806f630: .4byte gCurrentMessage
lbl_0806f634: .4byte 0x0876079c
lbl_0806f638: .4byte gLanguage
lbl_0806f63c:
    cmp r0, #4
    beq lbl_0806f648
    b lbl_0806f654
lbl_0806f642:
    ldrb r0, [r4, #0xc]
    adds r0, #1
    strb r0, [r4, #0xc]
lbl_0806f648:
    ldr r1, lbl_0806f650 @ =gCurrentMessage
    movs r0, #0
    strh r0, [r1, #2]
    b lbl_0806f678
    .align 2, 0
lbl_0806f650: .4byte gCurrentMessage
lbl_0806f654:
    ldr r0, lbl_0806f664 @ =gCurrentMessage
    ldrb r0, [r0, #7]
    cmp r0, #3
    bhi lbl_0806f678
    subs r5, #1
    cmp r5, #0
    bne lbl_0806f5fa
    b lbl_0806f678
    .align 2, 0
lbl_0806f664: .4byte gCurrentMessage
lbl_0806f668:
    ldrb r0, [r2, #7]
    adds r0, #1
    strb r0, [r2, #7]
    ldrb r0, [r2, #0xc]
    adds r0, #1
    strb r0, [r2, #0xc]
lbl_0806f674:
    ldrb r0, [r2, #7]
    b lbl_0806f67a
lbl_0806f678:
    movs r0, #0
lbl_0806f67a:
    pop {r4, r5, r6}
    pop {r1}
    bx r1

    thumb_func_start sub_0806f680
sub_0806f680: @ 0x0806f680
    push {r4, r5, r6, lr}
    sub sp, #4
    ldr r1, lbl_0806f6e4 @ =0x08754bc4
    ldr r3, [r1]
    adds r0, r3, #0
    adds r0, #0x57
    adds r2, r3, #0
    adds r2, #0xc1
    ldrb r0, [r0]
    adds r6, r1, #0
    ldrb r2, [r2]
    cmp r0, r2
    beq lbl_0806f6cc
    ldr r0, lbl_0806f6e8 @ =0x00000123
    adds r2, r3, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
    ldr r0, [r6]
    adds r0, #0x56
    movs r2, #0
    strb r2, [r0]
    ldr r0, [r6]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    adds r0, #0x57
    strb r1, [r0]
    ldr r0, [r6]
    adds r0, #0x58
    strb r2, [r0]
    ldr r1, lbl_0806f6ec @ =gCurrentMessage
    ldr r0, lbl_0806f6f0 @ =0x0840dc80
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldr r0, [r0]
    str r0, [r1]
lbl_0806f6cc:
    ldr r0, [r6]
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #6
    bls lbl_0806f6d8
    b lbl_0806f974
lbl_0806f6d8:
    lsls r0, r0, #2
    ldr r1, lbl_0806f6f4 @ =lbl_0806f6f8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0806f6e4: .4byte 0x08754bc4
lbl_0806f6e8: .4byte 0x00000123
lbl_0806f6ec: .4byte gCurrentMessage
lbl_0806f6f0: .4byte 0x0840dc80
lbl_0806f6f4: .4byte lbl_0806f6f8
lbl_0806f6f8: @ jump table
    .4byte lbl_0806f714 @ case 0
    .4byte lbl_0806f758 @ case 1
    .4byte lbl_0806f794 @ case 2
    .4byte lbl_0806f87e @ case 3
    .4byte lbl_0806f8dc @ case 4
    .4byte lbl_0806f930 @ case 5
    .4byte lbl_0806f974 @ case 6
lbl_0806f714:
    ldr r0, [r6]
    adds r0, #0x57
    ldrb r0, [r0]
    bl get_current_equipment_selected
    ldr r1, [r6]
    adds r1, #0x58
    strb r0, [r1]
    ldr r2, lbl_0806f74c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r1, [r6]
    adds r0, r1, #0
    adds r0, #0x58
    ldrb r0, [r0]
    cmp r0, #0x12
    bhi lbl_0806f750
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806f974
    .align 2, 0
lbl_0806f74c: .4byte 0x06007800
lbl_0806f750:
    adds r1, #0x56
    movs r0, #0x80
    strb r0, [r1]
    b lbl_0806f974
lbl_0806f758:
    ldr r2, lbl_0806f78c @ =gCurrentMessage
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r5, [r2, #9]
    cmp r0, r5
    bhi lbl_0806f778
    ldr r0, lbl_0806f790 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f778
    b lbl_0806f974
lbl_0806f778:
    movs r0, #0
    strb r0, [r2, #9]
    ldr r1, [r6]
    adds r1, #0x56
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r0, #0
    strh r0, [r2, #4]
    b lbl_0806f974
    .align 2, 0
lbl_0806f78c: .4byte gCurrentMessage
lbl_0806f790: .4byte gChangedInput
lbl_0806f794:
    ldr r5, lbl_0806f7d4 @ =gCurrentMessage
    ldr r2, lbl_0806f7d8 @ =0x087602d4
    ldr r0, lbl_0806f7dc @ =gLanguage
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldr r0, [r6]
    adds r0, #0x58
    ldrb r0, [r0]
    ldr r1, [r1]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r2, lbl_0806f7e0 @ =0x06007800
    adds r0, r5, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #2
    bne lbl_0806f7f0
    ldrb r0, [r5, #7]
    cmp r0, #0
    beq lbl_0806f7e4
    movs r4, #5
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #4
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f7d4: .4byte gCurrentMessage
lbl_0806f7d8: .4byte 0x087602d4
lbl_0806f7dc: .4byte gLanguage
lbl_0806f7e0: .4byte 0x06007800
lbl_0806f7e4:
    movs r4, #0
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #6
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f7f0:
    cmp r4, #1
    bne lbl_0806f81a
    movs r4, #4
    movs r0, #0
    strh r0, [r5, #4]
    ldr r0, lbl_0806f80c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f810
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #5
    strb r1, [r0]
    b lbl_0806f81c
    .align 2, 0
lbl_0806f80c: .4byte gDemoState
lbl_0806f810:
    ldr r0, [r6]
    adds r0, #0x56
    movs r1, #3
    strb r1, [r0]
    b lbl_0806f81c
lbl_0806f81a:
    movs r4, #0
lbl_0806f81c:
    cmp r4, #0
    bne lbl_0806f822
    b lbl_0806f974
lbl_0806f822:
    ldr r1, lbl_0806f84c @ =0x08754bc4
    ldr r3, [r1]
    ldr r0, lbl_0806f850 @ =gCurrentMessage
    ldrh r0, [r0, #2]
    adds r0, #0xa
    lsls r0, r0, #2
    movs r5, #0x8d
    lsls r5, r5, #1
    adds r2, r3, r5
    strh r0, [r2]
    adds r6, r1, #0
    cmp r4, #4
    bne lbl_0806f854
    movs r0, #0x8c
    lsls r0, r0, #1
    adds r1, r3, r0
    movs r0, #0x90
    lsls r0, r0, #2
    strh r0, [r1]
    b lbl_0806f86e
    .align 2, 0
lbl_0806f84c: .4byte 0x08754bc4
lbl_0806f850: .4byte gCurrentMessage
lbl_0806f854:
    movs r2, #0x8c
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x89
    lsls r0, r0, #2
    strh r0, [r1]
    ldrh r1, [r3]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f86e
    movs r4, #0
lbl_0806f86e:
    ldr r0, [r6]
    movs r3, #0x8c
    lsls r3, r3, #1
    adds r0, r0, r3
    adds r1, r4, #0
    bl UpdateMenuOamDataID
    b lbl_0806f974
lbl_0806f87e:
    ldr r0, lbl_0806f8c4 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f892
    ldr r0, lbl_0806f8c8 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0806f974
lbl_0806f892:
    ldr r2, lbl_0806f8cc @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r3, lbl_0806f8d0 @ =0x08754bc4
    ldr r0, [r3]
    adds r0, #0x56
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, lbl_0806f8d4 @ =gCurrentMessage
    strh r2, [r0, #4]
    strh r2, [r0, #2]
    movs r1, #0xa
    strb r1, [r0, #9]
    ldr r0, [r3]
    ldr r4, lbl_0806f8d8 @ =0x00000123
    adds r2, r0, r4
    b lbl_0806f96c
    .align 2, 0
lbl_0806f8c4: .4byte gChangedInput
lbl_0806f8c8: .4byte gDemoState
lbl_0806f8cc: .4byte 0x06007800
lbl_0806f8d0: .4byte 0x08754bc4
lbl_0806f8d4: .4byte gCurrentMessage
lbl_0806f8d8: .4byte 0x00000123
lbl_0806f8dc:
    ldr r0, lbl_0806f918 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0806f974
    ldr r2, lbl_0806f91c @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f920 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_0806f924 @ =gCurrentMessage
    ldr r0, lbl_0806f928 @ =0x0840dc80
    ldm r0!, {r3, r4, r5}
    stm r1!, {r3, r4, r5}
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, [r2]
    ldr r5, lbl_0806f92c @ =0x00000123
    adds r2, r0, r5
    b lbl_0806f96c
    .align 2, 0
lbl_0806f918: .4byte gChangedInput
lbl_0806f91c: .4byte 0x06007800
lbl_0806f920: .4byte 0x08754bc4
lbl_0806f924: .4byte gCurrentMessage
lbl_0806f928: .4byte 0x0840dc80
lbl_0806f92c: .4byte 0x00000123
lbl_0806f930:
    ldr r4, lbl_0806f97c @ =gCurrentMessage
    ldrh r0, [r4, #4]
    adds r0, #1
    movs r5, #0
    strh r0, [r4, #4]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x1e
    bls lbl_0806f974
    ldr r2, lbl_0806f980 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r2, lbl_0806f984 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x56
    movs r1, #1
    strb r1, [r0]
    strh r5, [r4, #4]
    strh r5, [r4, #2]
    movs r0, #0xa
    strb r0, [r4, #9]
    ldr r0, [r2]
    ldr r1, lbl_0806f988 @ =0x00000123
    adds r2, r0, r1
lbl_0806f96c:
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    strb r0, [r2]
lbl_0806f974:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806f97c: .4byte gCurrentMessage
lbl_0806f980: .4byte 0x06007800
lbl_0806f984: .4byte 0x08754bc4
lbl_0806f988: .4byte 0x00000123

    thumb_func_start TextProcessCurrentMessage
TextProcessCurrentMessage: @ 0x0806f98c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    adds r6, r1, #0
    mov r8, r2
    movs r5, #1
    rsbs r5, r5, #0
    ldrh r0, [r4, #4]
    adds r2, r0, #1
    strh r2, [r4, #4]
    ldr r0, lbl_0806fa04 @ =gButtonInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0806f9c4
    ldrb r1, [r4, #9]
    lsls r0, r2, #0x10
    lsrs r2, r0, #0x10
    cmp r1, r2
    bls lbl_0806f9bc
    movs r5, #0
lbl_0806f9bc:
    ldrb r0, [r4, #8]
    cmp r0, r2
    bls lbl_0806f9c4
    movs r5, #0
lbl_0806f9c4:
    cmp r5, #0
    bge lbl_0806faba
    movs r0, #0
    strb r0, [r4, #9]
    strh r0, [r4, #4]
    ldrh r0, [r4]
    lsls r0, r0, #1
    adds r6, r6, r0
    movs r0, #0xff
    lsls r0, r0, #8
    mov sb, r0
lbl_0806f9da:
    movs r7, #0
    ldrh r2, [r6]
    mov r1, sb
    ands r1, r2
    movs r0, #0xe1
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa48
    cmp r1, r0
    bgt lbl_0806fa12
    movs r0, #0x81
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa44
    cmp r1, r0
    bgt lbl_0806fa08
    movs r0, #0x80
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa36
    b lbl_0806fa60
    .align 2, 0
lbl_0806fa04: .4byte gButtonInput
lbl_0806fa08:
    movs r0, #0x83
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa3c
    b lbl_0806fa60
lbl_0806fa12:
    movs r0, #0xfd
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa50
    cmp r1, r0
    bgt lbl_0806fa28
    movs r0, #0xfc
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa54
    b lbl_0806fa60
lbl_0806fa28:
    movs r0, #0xfe
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fa4c
    cmp r1, sb
    beq lbl_0806fa58
    b lbl_0806fa60
lbl_0806fa36:
    movs r7, #0xff
    ands r7, r2
    b lbl_0806fa6a
lbl_0806fa3c:
    movs r0, #0xff
    ands r0, r2
    strh r0, [r4, #2]
    b lbl_0806fa6a
lbl_0806fa44:
    strb r2, [r4, #6]
    b lbl_0806fa6a
lbl_0806fa48:
    strb r2, [r4, #9]
    b lbl_0806fa6a
lbl_0806fa4c:
    movs r5, #1
    b lbl_0806fa6a
lbl_0806fa50:
    movs r5, #4
    b lbl_0806fa6a
lbl_0806fa54:
    movs r5, #3
    b lbl_0806fa6a
lbl_0806fa58:
    movs r0, #1
    strb r0, [r4, #0xe]
    movs r5, #2
    b lbl_0806fa6a
lbl_0806fa60:
    ldrh r0, [r6]
    bl get_chararcter_width
    adds r7, r0, #0
    movs r5, #0
lbl_0806fa6a:
    ldrh r2, [r4, #2]
    adds r0, r2, r7
    cmp r0, #0xe0
    ble lbl_0806fa76
    movs r5, #1
    b lbl_0806faba
lbl_0806fa76:
    cmp r5, #0
    bge lbl_0806fa7e
    adds r6, #2
    b lbl_0806faaa
lbl_0806fa7e:
    cmp r5, #0
    bne lbl_0806faa0
    ldrb r0, [r4, #0xd]
    cmp r0, #0
    beq lbl_0806fa94
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_message
    b lbl_0806faaa
lbl_0806fa94:
    ldrh r0, [r6]
    ldrb r3, [r4, #6]
    mov r1, r8
    bl draw_character_for_text
    b lbl_0806faaa
lbl_0806faa0:
    cmp r5, #2
    beq lbl_0806faaa
    ldrb r0, [r4, #7]
    adds r0, #1
    strb r0, [r4, #7]
lbl_0806faaa:
    ldrh r0, [r4, #2]
    adds r0, r0, r7
    strh r0, [r4, #2]
    ldrh r0, [r4]
    adds r0, #1
    strh r0, [r4]
    cmp r5, #0
    blt lbl_0806f9da
lbl_0806faba:
    lsls r0, r5, #0x18
    lsrs r0, r0, #0x18
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0806facc
sub_0806facc: @ 0x0806facc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r1, lbl_0806fb48 @ =0x0000ffff
    ldr r0, lbl_0806fb4c @ =0x08754bb4
    ldr r2, [r0]
    movs r0, #0x80
    lsls r0, r0, #7
    adds r2, r2, r0
    movs r3, #0xa0
    lsls r3, r3, #6
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    ldr r0, lbl_0806fb50 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0
    strb r1, [r0]
    ldr r1, lbl_0806fb54 @ =0x08760780
    ldr r0, lbl_0806fb58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    adds r0, #0x98
    ldr r4, [r0]
    ldr r5, lbl_0806fb5c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r5, #0
    movs r3, #0x10
    bl BitFill
    ldrh r1, [r4]
    movs r0, #0xff
    lsls r0, r0, #8
    cmp r1, r0
    beq lbl_0806fba8
    movs r2, #0xfe
    lsls r2, r2, #8
    mov r8, r2
    adds r7, r0, #0
    movs r6, #0x81
    lsls r6, r6, #8
lbl_0806fb34:
    movs r2, #1
    cmp r1, r8
    bne lbl_0806fb60
    ldr r1, lbl_0806fb5c @ =gCurrentMessage
    ldrh r0, [r1, #2]
    cmp r0, #0x70
    bhi lbl_0806fba8
    movs r0, #0x70
    strh r0, [r1, #2]
    b lbl_0806fba0
    .align 2, 0
lbl_0806fb48: .4byte 0x0000ffff
lbl_0806fb4c: .4byte 0x08754bb4
lbl_0806fb50: .4byte 0x08754bc4
lbl_0806fb54: .4byte 0x08760780
lbl_0806fb58: .4byte gLanguage
lbl_0806fb5c: .4byte gCurrentMessage
lbl_0806fb60:
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0806fb7c
    movs r2, #0xff
    lsls r2, r2, #8
    adds r0, r2, #0
    ands r0, r1
    cmp r0, r6
    bne lbl_0806fb7a
    strb r1, [r5, #6]
lbl_0806fb7a:
    movs r2, #0
lbl_0806fb7c:
    cmp r2, #0
    beq lbl_0806fba0
    ldrh r0, [r4]
    ldr r1, lbl_0806fbb4 @ =0x08754bb4
    ldr r1, [r1]
    movs r3, #0xc0
    lsls r3, r3, #7
    adds r1, r1, r3
    ldrh r2, [r5, #2]
    ldrb r3, [r5, #6]
    bl draw_character_for_message
    ldrh r0, [r4]
    bl get_chararcter_width
    ldrh r1, [r5, #2]
    adds r1, r1, r0
    strh r1, [r5, #2]
lbl_0806fba0:
    adds r4, #2
    ldrh r1, [r4]
    cmp r1, r7
    bne lbl_0806fb34
lbl_0806fba8:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fbb4: .4byte 0x08754bb4

    thumb_func_start sub_0806fbb8
sub_0806fbb8: @ 0x0806fbb8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r5, lbl_0806fbd4 @ =0x08754bc4
    ldr r0, [r5]
    adds r0, #0xe9
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0806fc02
    cmp r0, #1
    bgt lbl_0806fbd8
    cmp r0, #0
    beq lbl_0806fbe2
    b lbl_0806fce8
    .align 2, 0
lbl_0806fbd4: .4byte 0x08754bc4
lbl_0806fbd8:
    cmp r0, #2
    beq lbl_0806fc80
    cmp r0, #3
    beq lbl_0806fca0
    b lbl_0806fce8
lbl_0806fbe2:
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fc02:
    movs r5, #3
    ldr r4, lbl_0806fc4c @ =gCurrentMessage
    ldr r7, lbl_0806fc50 @ =0x08760780
    ldr r6, lbl_0806fc54 @ =0x08754bb4
lbl_0806fc0a:
    ldr r0, lbl_0806fc58 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x90
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0x80
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fc40
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc5c
lbl_0806fc40:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fc0a
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc4c: .4byte gCurrentMessage
lbl_0806fc50: .4byte 0x08760780
lbl_0806fc54: .4byte 0x08754bb4
lbl_0806fc58: .4byte gLanguage
lbl_0806fc5c:
    ldr r0, lbl_0806fc6c @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc6c: .4byte 0x08754bc4
lbl_0806fc70:
    ldr r0, lbl_0806fc7c @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xe9
    movs r1, #0x80
    strb r1, [r0]
    b lbl_0806fce8
    .align 2, 0
lbl_0806fc7c: .4byte 0x08754bc4
lbl_0806fc80:
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r4, #0
    movs r3, #0x10
    bl BitFill
    movs r0, #1
    strb r0, [r4, #0xd]
    ldr r1, [r5]
    adds r1, #0xe9
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0806fca0:
    movs r5, #3
    ldr r4, lbl_0806fcf0 @ =gCurrentMessage
    ldr r7, lbl_0806fcf4 @ =0x08760780
    ldr r6, lbl_0806fcf8 @ =0x08754bb4
lbl_0806fca8:
    ldr r0, lbl_0806fcfc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r0, r0, #2
    adds r0, r0, r7
    ldr r0, [r0]
    adds r0, #0x94
    ldr r1, [r0]
    ldrb r0, [r4, #7]
    lsls r0, r0, #0xb
    movs r2, #0xa0
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r6]
    adds r2, r2, r0
    adds r0, r4, #0
    bl TextProcessCurrentMessage
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0806fcde
    movs r0, #0
    strh r0, [r4, #2]
    ldrb r0, [r4, #0xe]
    cmp r0, #0
    bne lbl_0806fc70
lbl_0806fcde:
    subs r5, #1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    bne lbl_0806fca8
lbl_0806fce8:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fcf0: .4byte gCurrentMessage
lbl_0806fcf4: .4byte 0x08760780
lbl_0806fcf8: .4byte 0x08754bb4
lbl_0806fcfc: .4byte gLanguage

    thumb_func_start update_minimap_anim_palette
update_minimap_anim_palette: @ 0x0806fd00
    push {r4, r5, lr}
    ldr r0, lbl_0806fdf4 @ =0x08754bc4
    ldr r3, [r0]
    ldrb r4, [r3, #0x11]
    adds r5, r0, #0
    cmp r4, #0
    bne lbl_0806fd86
    ldrh r0, [r3, #0x18]
    adds r0, #1
    strh r0, [r3, #0x18]
    ldr r2, lbl_0806fdf8 @ =0x0840dcf0
    movs r1, #0x1a
    ldrsb r1, [r3, r1]
    adds r1, r1, r2
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fd86
    strh r4, [r3, #0x18]
    ldrb r0, [r3, #0x1a]
    adds r0, #1
    strb r0, [r3, #0x1a]
    ldr r1, [r5]
    ldrb r0, [r1, #0x1a]
    cmp r0, #3
    bls lbl_0806fd3a
    movs r0, #0
    strb r0, [r1, #0x1a]
lbl_0806fd3a:
    ldr r1, lbl_0806fdfc @ =0x0840dcb0
    ldr r2, [r5]
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    mov ip, r0
    strh r3, [r0, #0x24]
    strh r3, [r0, #0x26]
    ldr r1, lbl_0806fe04 @ =0x0840dc90
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x64
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    ldr r1, lbl_0806fe08 @ =0x0840dcd0
    movs r0, #0x1a
    ldrsb r0, [r2, r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    mov r0, ip
    adds r0, #0x44
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
    adds r0, #0x3e
    strh r3, [r0]
    adds r0, #2
    strh r3, [r0]
lbl_0806fd86:
    adds r4, r5, #0
    ldr r2, [r4]
    ldrb r0, [r2, #0x12]
    cmp r0, #7
    bhi lbl_0806fdee
    ldrh r0, [r2, #0x1c]
    adds r0, #1
    strh r0, [r2, #0x1c]
    movs r3, #0x1e
    ldrsb r3, [r2, r3]
    cmp r3, #0
    bge lbl_0806fda0
    rsbs r3, r3, #0
lbl_0806fda0:
    ldr r1, lbl_0806fe0c @ =0x0840dcf4
    adds r1, r3, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_0806fdee
    movs r0, #0
    strh r0, [r2, #0x1c]
    ldrb r0, [r2, #0x1e]
    adds r0, #1
    strb r0, [r2, #0x1e]
    ldr r1, [r4]
    movs r0, #0x1e
    ldrsb r0, [r1, r0]
    cmp r0, #0x10
    blt lbl_0806fdc8
    movs r0, #0xe
    rsbs r0, r0, #0
    strb r0, [r1, #0x1e]
lbl_0806fdc8:
    ldr r0, [r5]
    movs r3, #0x1e
    ldrsb r3, [r0, r3]
    cmp r3, #0
    bge lbl_0806fdd4
    rsbs r3, r3, #0
lbl_0806fdd4:
    ldr r1, lbl_0806fe10 @ =0x0840dd04
    ldrb r0, [r0, #0x12]
    adds r0, r0, r1
    ldrb r1, [r0]
    ldr r0, lbl_0806fe00 @ =0x08754bb8
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r1, r1, r0
    ldr r2, lbl_0806fe14 @ =0x083fd2f0
    lsls r0, r3, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fdee:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fdf4: .4byte 0x08754bc4
lbl_0806fdf8: .4byte 0x0840dcf0
lbl_0806fdfc: .4byte 0x0840dcb0
lbl_0806fe00: .4byte 0x08754bb8
lbl_0806fe04: .4byte 0x0840dc90
lbl_0806fe08: .4byte 0x0840dcd0
lbl_0806fe0c: .4byte 0x0840dcf4
lbl_0806fe10: .4byte 0x0840dd04
lbl_0806fe14: .4byte 0x083fd2f0

    thumb_func_start sub_0806fe18
sub_0806fe18: @ 0x0806fe18
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0806fecc @ =0x083fcef0
    adds r0, #0x9e
    ldrh r1, [r0]
    ldr r3, lbl_0806fed0 @ =0x08754bb4
    ldr r0, lbl_0806fed4 @ =0x0840dd04
    ldrb r0, [r0, #8]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r2, [r3]
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl BitFill
    movs r3, #0
    ldr r0, lbl_0806fed8 @ =0x08754bc4
    mov ip, r0
    movs r5, #1
lbl_0806fe48:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xba
    ldrb r2, [r0]
    asrs r2, r3
    ands r2, r5
    ldr r4, lbl_0806fed0 @ =0x08754bb4
    ldr r6, lbl_0806fed4 @ =0x0840dd04
    cmp r2, #0
    bne lbl_0806fe6e
    ldr r0, [r4]
    adds r1, r3, r6
    ldrb r1, [r1]
    lsls r1, r1, #1
    movs r7, #0xd8
    lsls r7, r7, #7
    adds r0, r0, r7
    adds r0, r0, r1
    strh r2, [r0]
lbl_0806fe6e:
    adds r3, #1
    cmp r3, #6
    ble lbl_0806fe48
    ldr r2, lbl_0806fedc @ =gCurrentArea
    ldrb r0, [r2]
    cmp r0, #7
    bhi lbl_0806fe92
    ldr r1, [r4]
    adds r0, r0, r6
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r2, #0xd8
    lsls r2, r2, #7
    adds r1, r1, r2
    adds r1, r1, r0
    ldr r0, lbl_0806fee0 @ =0x083fd2f0
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0806fe92:
    ldr r1, [r4]
    ldrb r0, [r6, #7]
    lsls r0, r0, #1
    movs r4, #0xd8
    lsls r4, r4, #7
    adds r3, r1, r4
    adds r0, r3, r0
    movs r5, #0
    strh r5, [r0]
    ldrb r2, [r6, #8]
    lsls r2, r2, #1
    adds r3, r3, r2
    strh r5, [r3]
    adds r4, r2, r4
    adds r1, r1, r4
    movs r0, #0xa0
    lsls r0, r0, #0x13
    adds r2, r2, r0
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x12
    bl DMATransfer
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0806fecc: .4byte 0x083fcef0
lbl_0806fed0: .4byte 0x08754bb4
lbl_0806fed4: .4byte 0x0840dd04
lbl_0806fed8: .4byte 0x08754bc4
lbl_0806fedc: .4byte gCurrentArea
lbl_0806fee0: .4byte 0x083fd2f0

    thumb_func_start update_suitType
update_suitType: @ 0x0806fee4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r2, lbl_0806ff04 @ =gEquipment
    ldrb r0, [r2, #0x12]
    cmp r0, r1
    beq lbl_0806fef4
    strb r1, [r2, #0x12]
lbl_0806fef4:
    ldrb r0, [r2, #0x12]
    cmp r0, #1
    beq lbl_0806ff24
    cmp r0, #1
    bgt lbl_0806ff08
    cmp r0, #0
    beq lbl_0806ff0e
    b lbl_0806ff48
    .align 2, 0
lbl_0806ff04: .4byte gEquipment
lbl_0806ff08:
    cmp r0, #2
    beq lbl_0806ff3c
    b lbl_0806ff48
lbl_0806ff0e:
    ldrh r0, [r2]
    strh r0, [r2, #6]
    ldrb r1, [r2, #0xc]
    movs r0, #0xf7
    ands r0, r1
    strb r0, [r2, #0xd]
    ldrb r1, [r2, #0xe]
    movs r0, #0xdb
    ands r0, r1
    strb r0, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff24:
    ldrh r0, [r2]
    movs r1, #0
    strh r0, [r2, #6]
    ldrh r0, [r2, #2]
    strh r0, [r2, #8]
    ldrb r0, [r2, #4]
    strb r0, [r2, #0xa]
    ldrb r0, [r2, #5]
    strb r0, [r2, #0xb]
    strb r1, [r2, #0xd]
    strb r1, [r2, #0xf]
    b lbl_0806ff48
lbl_0806ff3c:
    movs r0, #0x63
    strh r0, [r2, #6]
    movs r0, #0x80
    strb r0, [r2, #0xf]
    movs r0, #0x11
    strb r0, [r2, #0xd]
lbl_0806ff48:
    pop {r0}
    bx r0

    thumb_func_start draw_status_screen_item
draw_status_screen_item: @ 0x0806ff4c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #7
    bls lbl_0806ff64
    movs r0, #1
    b lbl_0806fff4
lbl_0806ff64:
    movs r4, #0
    ldr r0, lbl_08070004 @ =0x087603d8
    mov sb, r0
    ldr r1, lbl_08070008 @ =0x0840de50
    mov sl, r1
lbl_0806ff6e:
    lsls r1, r4, #1
    cmp r7, #0
    bne lbl_0806ff80
    adds r0, r1, r4
    add r0, sb
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, #2
    beq lbl_0806ffe4
lbl_0806ff80:
    adds r2, r1, r4
    mov r3, sb
    adds r0, r2, r3
    ldrb r0, [r0]
    lsls r1, r0, #2
    adds r1, r1, r0
    mov r5, sl
    adds r0, r1, r5
    ldrb r0, [r0]
    adds r0, r0, r7
    ldr r3, lbl_0807000c @ =0x0840de52
    adds r1, r1, r3
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r3, r0, r1
    ldr r5, lbl_08070010 @ =0x087603d9
    adds r0, r2, r5
    ldrb r0, [r0]
    adds r6, r4, #1
    cmp r0, r7
    bls lbl_0806ffe4
    movs r4, #0
    ldr r1, lbl_08070014 @ =0x087603da
    adds r0, r2, r1
    ldrb r5, [r0]
    cmp r4, r5
    bge lbl_0806ffe4
    ldr r1, lbl_08070018 @ =0x08754bb4
    mov r8, r1
    movs r5, #0xe0
    lsls r5, r5, #7
    mov ip, r5
    str r0, [sp]
    lsls r0, r3, #1
    ldr r1, lbl_0807001c @ =0x0600c000
    adds r2, r0, r1
lbl_0806ffc8:
    lsls r0, r3, #1
    mov r5, r8
    ldr r1, [r5]
    add r1, ip
    adds r1, r1, r0
    ldrh r0, [r1]
    strh r0, [r2]
    adds r4, #1
    adds r2, #2
    adds r3, #1
    ldr r0, [sp]
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0806ffc8
lbl_0806ffe4:
    adds r4, r6, #0
    cmp r4, #5
    ble lbl_0806ff6e
    movs r4, #0
    cmp r7, #6
    bls lbl_0806fff2
    movs r4, #1
lbl_0806fff2:
    adds r0, r4, #0
lbl_0806fff4:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08070004: .4byte 0x087603d8
lbl_08070008: .4byte 0x0840de50
lbl_0807000c: .4byte 0x0840de52
lbl_08070010: .4byte 0x087603d9
lbl_08070014: .4byte 0x087603da
lbl_08070018: .4byte 0x08754bb4
lbl_0807001c: .4byte 0x0600c000

    thumb_func_start sub_08070020
sub_08070020: @ 0x08070020
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r2, r1, #0x18
    cmp r2, #0x15
    bhi lbl_08070062
    mov r0, ip
    cmp r0, #0
    bne lbl_0807004c
    ldr r0, lbl_08070048 @ =0x0840df0c
    lsls r1, r2, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    b lbl_08070172
    .align 2, 0
lbl_08070048: .4byte 0x0840df0c
lbl_0807004c:
    mov r0, ip
    cmp r0, #1
    bne lbl_0807006c
    ldr r1, lbl_08070068 @ =0x0840df0c
    lsls r2, r2, #2
    adds r0, r2, r1
    ldrb r0, [r0]
    mov sb, r1
    adds r7, r2, #0
    cmp r0, #1
    bhi lbl_08070084
lbl_08070062:
    movs r0, #0
    b lbl_08070172
    .align 2, 0
lbl_08070068: .4byte 0x0840df0c
lbl_0807006c:
    ldr r0, lbl_08070080 @ =0x0840df0c
    lsls r1, r2, #2
    adds r3, r1, r0
    ldrb r2, [r3]
    mov sb, r0
    adds r7, r1, #0
    cmp r2, #3
    beq lbl_08070084
    ldrb r0, [r3, #3]
    b lbl_08070172
    .align 2, 0
lbl_08070080: .4byte 0x0840df0c
lbl_08070084:
    movs r5, #0
    mov r0, sb
    adds r2, r7, r0
    ldrb r6, [r2, #3]
    ldrb r0, [r2, #1]
    cmp r0, #1
    beq lbl_080700c8
    cmp r0, #1
    bgt lbl_0807009c
    cmp r0, #0
    beq lbl_080700a6
    b lbl_08070120
lbl_0807009c:
    cmp r0, #2
    beq lbl_080700e8
    cmp r0, #3
    beq lbl_0807010c
    b lbl_08070120
lbl_080700a6:
    ldr r1, lbl_080700bc @ =0x0840d0f0
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700c0 @ =0x08754bc4
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc4
    ldr r2, lbl_080700c4 @ =0x0300153d
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_080700bc: .4byte 0x0840d0f0
lbl_080700c0: .4byte 0x08754bc4
lbl_080700c4: .4byte 0x0300153d
lbl_080700c8:
    ldr r1, lbl_080700dc @ =0x0840d0f5
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_080700e0 @ =0x08754bc4
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xd1
    ldr r0, lbl_080700e4 @ =0x0300153d
    b lbl_0807011e
    .align 2, 0
lbl_080700dc: .4byte 0x0840d0f5
lbl_080700e0: .4byte 0x08754bc4
lbl_080700e4: .4byte 0x0300153d
lbl_080700e8:
    ldr r1, lbl_08070100 @ =0x0840d0f6
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070104 @ =0x08754bc4
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xc9
    ldr r2, lbl_08070108 @ =0x0300153f
    mov r8, r2
    b lbl_08070120
    .align 2, 0
lbl_08070100: .4byte 0x0840d0f6
lbl_08070104: .4byte 0x08754bc4
lbl_08070108: .4byte 0x0300153f
lbl_0807010c:
    ldr r1, lbl_0807013c @ =0x0840d0f8
    ldrb r0, [r2, #2]
    adds r0, r0, r1
    ldrb r5, [r0]
    ldr r0, lbl_08070140 @ =0x08754bc4
    ldr r0, [r0]
    adds r4, r0, #0
    adds r4, #0xcb
    ldr r0, lbl_08070144 @ =0x0300153f
lbl_0807011e:
    mov r8, r0
lbl_08070120:
    mov r2, ip
    cmp r2, #1
    bne lbl_08070148
    mov r0, r8
    ldrb r2, [r0]
    adds r1, r5, #0
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    bics r2, r5
    mov r0, r8
    strb r2, [r0]
    b lbl_08070170
    .align 2, 0
lbl_0807013c: .4byte 0x0840d0f8
lbl_08070140: .4byte 0x08754bc4
lbl_08070144: .4byte 0x0300153f
lbl_08070148:
    movs r3, #0
    ldr r1, lbl_08070158 @ =0x0840d0fe
    mov r2, sb
    adds r0, r7, r2
    ldrb r0, [r0, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    b lbl_08070166
    .align 2, 0
lbl_08070158: .4byte 0x0840d0fe
lbl_0807015c:
    adds r4, #1
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    adds r3, #1
lbl_08070166:
    cmp r3, r1
    bge lbl_08070170
    ldrb r0, [r4]
    cmp r0, r5
    bne lbl_0807015c
lbl_08070170:
    adds r0, r6, #0
lbl_08070172:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start draw_status_screen_tanks_amounts
draw_status_screen_tanks_amounts: @ 0x08070180
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    ldr r6, lbl_080701e0 @ =gEquipment
    ldrb r0, [r6, #0x12]
    cmp r0, #2
    bne lbl_080701ec
    ldr r5, lbl_080701e4 @ =0x08754bb4
    ldr r2, [r5]
    movs r0, #0x80
    lsls r0, r0, #8
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r0, lbl_080701e8 @ =0x08754bc4
    ldr r2, [r0]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070324
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    b lbl_08070314
    .align 2, 0
lbl_080701e0: .4byte gEquipment
lbl_080701e4: .4byte 0x08754bb4
lbl_080701e8: .4byte 0x08754bc4
lbl_080701ec:
    ldr r5, lbl_0807031c @ =0x08754bb4
    ldr r2, [r5]
    movs r0, #0xf0
    lsls r0, r0, #7
    adds r1, r2, r0
    movs r4, #0xe0
    lsls r4, r4, #7
    adds r2, r2, r4
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    add r1, sp, #4
    ldr r7, lbl_08070320 @ =0x08754bc4
    ldr r2, [r7]
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0xc2
    ldrb r0, [r0]
    strb r0, [r1, #1]
    adds r0, r2, #0
    adds r0, #0xc3
    ldrb r0, [r0]
    strb r0, [r1, #2]
    adds r2, #0xc0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070534
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_080706a4
    ldr r0, [r5]
    adds r0, r0, r4
    bl set_status_screen_bomb_visibilty
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070810
    ldr r0, [r5]
    adds r0, r0, r4
    bl sub_08070c2c
    ldrh r1, [r6, #6]
    movs r0, #5
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6]
    movs r0, #6
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
    ldrh r0, [r6, #2]
    cmp r0, #0
    beq lbl_08070296
    ldrh r1, [r6, #8]
    movs r0, #7
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrh r1, [r6, #2]
    movs r0, #8
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_08070296:
    ldrb r0, [r6, #4]
    cmp r0, #0
    beq lbl_080702b4
    ldrb r1, [r6, #0xa]
    movs r0, #9
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #4]
    movs r0, #0xa
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702b4:
    ldrb r0, [r6, #5]
    cmp r0, #0
    beq lbl_080702d2
    ldrb r1, [r6, #0xb]
    movs r0, #0xb
    movs r2, #0xb
    movs r3, #0
    bl draw_status_screen_single_tank_amount
    ldrb r1, [r6, #5]
    movs r0, #0xc
    movs r2, #0xb
    movs r3, #1
    bl draw_status_screen_single_tank_amount
lbl_080702d2:
    add r0, sp, #4
    ldrb r0, [r0]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702e8
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1]
    adds r0, #0xc1
    strb r1, [r0]
lbl_080702e8:
    add r0, sp, #4
    ldrb r0, [r0, #1]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_080702fe
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #1]
    adds r0, #0xc2
    strb r1, [r0]
lbl_080702fe:
    add r0, sp, #4
    ldrb r0, [r0, #2]
    bl sub_08071a8c
    cmp r0, #0
    beq lbl_08070314
    ldr r0, [r7]
    add r1, sp, #4
    ldrb r1, [r1, #2]
    adds r0, #0xc3
    strb r1, [r0]
lbl_08070314:
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807031c: .4byte 0x08754bb4
lbl_08070320: .4byte 0x08754bc4

    thumb_func_start sub_08070324
sub_08070324: @ 0x08070324
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    mov r8, r0
    movs r0, #0
    mov ip, r0
    ldr r5, lbl_08070404 @ =0x08754bc4
    ldr r3, [r5]
    adds r3, #0xc4
    ldr r2, lbl_08070408 @ =0x0840de50
    ldrb r0, [r2]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r4, [r2, #2]
    adds r7, r0, r4
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldr r0, lbl_08070410 @ =0x087601dc
    ldr r0, [r0]
    ldrb r0, [r0]
    strb r0, [r3]
    ldrb r0, [r2, #3]
    subs r1, r0, r4
    mov sb, r5
    cmp r1, #0
    blt lbl_0807037a
    lsls r0, r6, #1
    mov r2, r8
    adds r3, r0, r2
    lsls r0, r7, #1
    adds r2, r0, r2
    adds r1, #1
lbl_0807036c:
    ldrh r0, [r3]
    strh r0, [r2]
    adds r3, #2
    adds r2, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_0807036c
lbl_0807037a:
    mov r5, sb
    ldr r0, [r5]
    ldrh r0, [r0]
    lsrs r0, r0, #9
    movs r6, #1
    mov r4, ip
    adds r4, #1
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    adds r2, r6, #0
    bics r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080703aa
    movs r0, #0x80
    strb r0, [r1]
lbl_080703aa:
    mov r3, sb
    ldr r0, [r3]
    adds r5, r0, #0
    adds r5, #0xc1
    ldrb r0, [r5]
    cmp r0, #0
    bne lbl_080703ba
    strb r6, [r5]
lbl_080703ba:
    ldr r2, lbl_08070408 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r4, [r2]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r7, r0, r3
    ldr r1, lbl_0807040c @ =0x0840de91
    ldrb r0, [r1]
    adds r0, #1
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r6, r0, r1
    ldrb r0, [r2, #3]
    subs r1, r0, r3
    cmp r1, #0
    blt lbl_080703f8
    lsls r0, r6, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r7, #1
    adds r4, r0, r3
    adds r1, #1
lbl_080703ea:
    ldrh r0, [r2]
    strh r0, [r4]
    adds r2, #2
    adds r4, #2
    subs r1, #1
    cmp r1, #0
    bne lbl_080703ea
lbl_080703f8:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070404: .4byte 0x08754bc4
lbl_08070408: .4byte 0x0840de50
lbl_0807040c: .4byte 0x0840de91
lbl_08070410: .4byte 0x087601dc

    thumb_func_start draw_status_screen_single_tank_amount
draw_status_screen_single_tank_amount: @ 0x08070414
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    str r1, [sp]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov sb, r2
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    str r3, [sp, #4]
    subs r0, r4, #5
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r1, lbl_080704c0 @ =0x0000b08c
    str r1, [sp, #8]
    cmp r0, #1
    bhi lbl_0807044a
    ldr r2, lbl_080704c4 @ =0x0000b2e0
    str r2, [sp, #8]
lbl_0807044a:
    ldr r0, lbl_080704c8 @ =0x08754bb4
    ldr r0, [r0]
    movs r3, #0xe0
    lsls r3, r3, #7
    adds r7, r0, r3
    ldr r3, lbl_080704cc @ =0x0840de50
    lsls r2, r4, #2
    adds r2, r2, r4
    adds r0, r2, r3
    ldrb r1, [r0]
    lsls r1, r1, #5
    adds r0, r3, #2
    adds r0, r2, r0
    ldrb r4, [r0]
    adds r1, r1, r4
    lsls r1, r1, #1
    adds r7, r7, r1
    adds r3, #3
    adds r2, r2, r3
    ldrb r0, [r2]
    subs r6, r0, r4
    ldr r1, lbl_080704d0 @ =0x0840d102
    lsls r0, r6, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    adds r6, #1
    movs r0, #0
    mov r8, r0
    movs r5, #0
    cmp r4, #0
    ble lbl_08070502
    ldr r2, lbl_080704d4 @ =0x00000fff
    adds r1, r2, #0
    ldr r0, [sp, #8]
    ands r0, r1
    lsls r0, r0, #0x10
    mov sl, r0
lbl_08070494:
    ldr r0, [sp]
    adds r1, r4, #0
    bl __divsi3
    movs r1, #0xa
    bl __modsi3
    adds r2, r0, #0
    cmp r2, #0
    bne lbl_080704d8
    movs r2, #0x80
    cmp r4, #1
    beq lbl_080704de
    mov r3, r8
    cmp r3, #0
    bne lbl_080704de
    ldr r0, [sp, #4]
    cmp r0, #0
    bne lbl_080704f0
    mov r1, sl
    lsrs r2, r1, #0x10
    b lbl_080704de
    .align 2, 0
lbl_080704c0: .4byte 0x0000b08c
lbl_080704c4: .4byte 0x0000b2e0
lbl_080704c8: .4byte 0x08754bb4
lbl_080704cc: .4byte 0x0840de50
lbl_080704d0: .4byte 0x0840d102
lbl_080704d4: .4byte 0x00000fff
lbl_080704d8:
    movs r3, #1
    mov r8, r3
    adds r2, #0x80
lbl_080704de:
    cmp r2, #0
    beq lbl_080704f0
    lsls r1, r5, #1
    adds r1, r1, r7
    mov r3, sb
    lsls r0, r3, #0xc
    orrs r0, r2
    strh r0, [r1]
    b lbl_080704f2
lbl_080704f0:
    subs r5, #1
lbl_080704f2:
    adds r0, r4, #0
    movs r1, #0xa
    bl __divsi3
    adds r4, r0, #0
    adds r5, #1
    cmp r4, #0
    bgt lbl_08070494
lbl_08070502:
    cmp r6, r5
    beq lbl_08070520
    ldr r1, lbl_08070530 @ =0x00000fff
    ldr r0, [sp, #8]
    ands r1, r0
    mov r2, sb
    lsls r0, r2, #0xc
    orrs r1, r0
    lsls r0, r5, #1
    adds r0, r0, r7
lbl_08070516:
    strh r1, [r0]
    adds r0, #2
    adds r5, #1
    cmp r6, r5
    bne lbl_08070516
lbl_08070520:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070530: .4byte 0x00000fff

    thumb_func_start sub_08070534
sub_08070534: @ 0x08070534
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_08070684 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xc4
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r1, [r0]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_08070562
    movs r2, #0
lbl_08070556:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_08070556
lbl_08070562:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3]
    cmp ip, r3
    bge lbl_08070612
lbl_0807056c:
    adds r3, r4, #0
    movs r7, #0
    ldr r0, lbl_0807068c @ =0x087601dc
    ldr r0, [r0]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_08070690 @ =gEquipment
    cmp r0, #8
    bne lbl_08070594
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_08070590
    ldr r0, lbl_08070694 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070594
lbl_08070590:
    movs r3, #9
    movs r7, #0xa
lbl_08070594:
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    adds r7, r7, r0
    ldr r3, lbl_0807069c @ =0x0840de50
    ldrb r0, [r3]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #2]
    adds r6, r0, r2
    ldr r1, lbl_0807068c @ =0x087601dc
    ldr r0, [r1]
    adds r0, r0, r4
    ldrb r1, [r5, #0xc]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070608
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #3]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_080705f2
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_080705e4:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080705e4
lbl_080705f2:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_080706a0 @ =0x0300153d
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #0
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070608:
    mov r4, r8
    ldr r0, lbl_08070688 @ =0x0840d0fe
    ldrb r0, [r0]
    cmp r4, r0
    blt lbl_0807056c
lbl_08070612:
    mov r4, ip
    cmp r4, #0
    beq lbl_08070676
    ldr r2, lbl_08070684 @ =0x08754bc4
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807062a
    movs r0, #0x80
    strb r0, [r1]
lbl_0807062a:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807063a
    movs r0, #1
    strb r0, [r1]
lbl_0807063a:
    ldr r2, lbl_0807069c @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #2]
    adds r6, r0, r3
    ldr r1, lbl_08070698 @ =0x0840de91
    ldrb r0, [r1, #1]
    lsls r0, r0, #5
    ldrb r1, [r1, #2]
    adds r7, r0, r1
    ldrb r0, [r2, #3]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_08070676
    lsls r0, r7, #1
    mov r1, sl
    adds r2, r0, r1
    lsls r0, r6, #1
    adds r1, r0, r1
    adds r3, #1
lbl_08070668:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_08070668
lbl_08070676:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070684: .4byte 0x08754bc4
lbl_08070688: .4byte 0x0840d0fe
lbl_0807068c: .4byte 0x087601dc
lbl_08070690: .4byte gEquipment
lbl_08070694: .4byte gPauseScreenFlag
lbl_08070698: .4byte 0x0840de91
lbl_0807069c: .4byte 0x0840de50
lbl_080706a0: .4byte 0x0300153d

    thumb_func_start sub_080706a4
sub_080706a4: @ 0x080706a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    mov sl, r0
    ldr r0, lbl_080707f0 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xc9
    mov sb, r0
    movs r4, #0
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r1, [r0, #2]
    adds r3, r0, #0
    cmp r1, #0
    beq lbl_080706d2
    movs r2, #0
lbl_080706c6:
    mov r5, sb
    adds r0, r5, r4
    strb r2, [r0]
    adds r4, #1
    cmp r4, r1
    blt lbl_080706c6
lbl_080706d2:
    movs r4, #0
    mov ip, r4
    ldrb r3, [r3, #2]
    cmp ip, r3
    bge lbl_0807077c
lbl_080706dc:
    adds r3, r4, #0
    ldr r0, lbl_080707f8 @ =0x087601dc
    ldr r0, [r0, #8]
    adds r0, r0, r3
    ldrb r0, [r0]
    ldr r5, lbl_080707fc @ =gEquipment
    cmp r0, #0x20
    bne lbl_08070700
    ldrb r0, [r5, #0x12]
    cmp r0, #1
    bne lbl_080706fe
    ldr r0, lbl_08070800 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070700
lbl_080706fe:
    movs r3, #3
lbl_08070700:
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xa]
    adds r0, r0, r3
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldr r3, lbl_08070808 @ =0x0840de50
    ldrb r0, [r3, #0xa]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r2, [r3, #0xc]
    adds r7, r0, r2
    ldr r1, lbl_080707f8 @ =0x087601dc
    ldr r0, [r1, #8]
    adds r0, r0, r4
    ldrb r1, [r5, #0xe]
    ldrb r0, [r0]
    ands r1, r0
    adds r4, #1
    mov r8, r4
    cmp r1, #0
    beq lbl_08070772
    mov r1, sb
    add r1, ip
    strb r0, [r1]
    ldrb r0, [r3, #0xd]
    subs r3, r0, r2
    adds r5, r1, #0
    mov r4, ip
    adds r4, #1
    cmp r3, #0
    blt lbl_0807075c
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_0807074e:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0807074e
lbl_0807075c:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_0807080c @ =0x0300153f
    ldrb r0, [r2]
    ldrb r2, [r5]
    ands r2, r0
    movs r0, #2
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_08070772:
    mov r4, r8
    ldr r0, lbl_080707f4 @ =0x0840d0fe
    ldrb r0, [r0, #2]
    cmp r4, r0
    blt lbl_080706dc
lbl_0807077c:
    mov r4, ip
    cmp r4, #0
    beq lbl_080707e0
    ldr r2, lbl_080707f0 @ =0x08754bc4
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070794
    movs r0, #0x82
    strb r0, [r1]
lbl_08070794:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_080707a4
    movs r0, #0xa
    strb r0, [r1]
lbl_080707a4:
    ldr r2, lbl_08070808 @ =0x0840de50
    mov r0, ip
    adds r0, #1
    ldrb r5, [r2, #0xa]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r3, [r2, #0xc]
    adds r7, r0, r3
    ldr r1, lbl_08070804 @ =0x0840de91
    ldrb r0, [r1, #0xb]
    lsls r0, r0, #5
    ldrb r1, [r1, #0xc]
    adds r6, r0, r1
    ldrb r0, [r2, #0xd]
    subs r3, r0, r3
    cmp r3, #0
    blt lbl_080707e0
    lsls r0, r6, #1
    mov r6, sl
    adds r2, r0, r6
    lsls r0, r7, #1
    adds r1, r0, r6
    adds r3, #1
lbl_080707d2:
    ldrh r0, [r2]
    strh r0, [r1]
    adds r2, #2
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_080707d2
lbl_080707e0:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080707f0: .4byte 0x08754bc4
lbl_080707f4: .4byte 0x0840d0fe
lbl_080707f8: .4byte 0x087601dc
lbl_080707fc: .4byte gEquipment
lbl_08070800: .4byte gPauseScreenFlag
lbl_08070804: .4byte 0x0840de91
lbl_08070808: .4byte 0x0840de50
lbl_0807080c: .4byte 0x0300153f

    thumb_func_start sub_08070810
sub_08070810: @ 0x08070810
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    mov sb, r0
    movs r3, #0
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r1, [r0, #3]
    adds r5, r0, #0
    cmp r3, r1
    bge lbl_0807083c
    ldr r4, lbl_080709a8 @ =0x08754bc4
    movs r2, #0
lbl_0807082e:
    ldr r0, [r4]
    adds r0, #0xcb
    adds r0, r0, r3
    strb r2, [r0]
    adds r3, #1
    cmp r3, r1
    blt lbl_0807082e
lbl_0807083c:
    movs r3, #0
    mov ip, r3
    ldrb r5, [r5, #3]
    cmp ip, r5
    bge lbl_080708f4
lbl_08070846:
    adds r2, r3, #1
    ldr r0, lbl_080709ac @ =0x087601dc
    ldr r0, [r0, #0xc]
    adds r0, r0, r3
    ldrb r0, [r0]
    str r2, [sp]
    ldr r1, lbl_080709b0 @ =gEquipment
    mov sl, r1
    cmp r0, #4
    bne lbl_08070870
    ldrb r0, [r1, #0x12]
    cmp r0, #1
    bne lbl_0807086c
    ldr r0, lbl_080709b4 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #8
    bne lbl_08070870
lbl_0807086c:
    movs r2, #1
    rsbs r2, r2, #0
lbl_08070870:
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    adds r0, r0, r2
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r5, r0, r1
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    adds r0, #1
    add r0, ip
    lsls r0, r0, #5
    ldrb r4, [r2, #0x11]
    adds r7, r0, r4
    ldr r1, lbl_080709ac @ =0x087601dc
    ldr r0, [r1, #0xc]
    adds r0, r0, r3
    mov r3, sl
    ldrb r1, [r3, #0xe]
    ldrb r3, [r0]
    ands r1, r3
    cmp r1, #0
    beq lbl_080708ea
    ldr r0, lbl_080709a8 @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0xcb
    add r1, ip
    strb r3, [r1]
    ldrb r1, [r2, #0x12]
    subs r2, r1, r4
    adds r6, r0, #0
    mov r4, ip
    adds r4, #1
    cmp r2, #0
    blt lbl_080708ce
    lsls r0, r5, #1
    mov r5, sb
    adds r1, r0, r5
    lsls r0, r7, #1
    adds r3, r0, r5
    adds r2, #1
lbl_080708c0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_080708c0
lbl_080708ce:
    lsls r1, r4, #0x18
    lsrs r1, r1, #0x18
    ldr r0, [r6]
    adds r0, #0xcb
    add r0, ip
    mov r2, sl
    ldrb r3, [r2, #0xf]
    ldrb r2, [r0]
    ands r2, r3
    movs r0, #3
    movs r3, #0
    bl sub_08070e1c
    mov ip, r4
lbl_080708ea:
    ldr r3, [sp]
    ldr r0, lbl_080709a4 @ =0x0840d0fe
    ldrb r0, [r0, #3]
    cmp r3, r0
    blt lbl_08070846
lbl_080708f4:
    mov r3, ip
    cmp r3, #0
    beq lbl_08070994
    ldr r2, lbl_080709a8 @ =0x08754bc4
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc0
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807090c
    movs r0, #0x83
    strb r0, [r1]
lbl_0807090c:
    ldr r0, [r2]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0807091c
    movs r0, #0xc
    strb r0, [r1]
lbl_0807091c:
    ldr r2, lbl_080709bc @ =0x0840de50
    ldrb r0, [r2, #0xf]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r7, r0, r3
    ldr r1, lbl_080709b8 @ =0x0840de91
    ldrb r0, [r1, #0xf]
    lsls r0, r0, #5
    ldrb r4, [r1, #0x11]
    adds r5, r0, r4
    ldrb r0, [r2, #0x12]
    subs r6, r0, r3
    mov sl, r1
    mov r8, r2
    mov r4, ip
    adds r4, #1
    cmp r6, #0
    blt lbl_0807095a
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, r6, #1
lbl_0807094c:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_0807094c
lbl_0807095a:
    mov r1, r8
    ldrb r0, [r1, #0xf]
    adds r0, r0, r4
    lsls r0, r0, #5
    ldrb r1, [r1, #0x11]
    adds r7, r0, r1
    mov r2, sl
    ldrb r0, [r2, #0x10]
    lsls r0, r0, #5
    ldrb r3, [r2, #0x11]
    adds r5, r0, r3
    mov r4, r8
    ldrb r0, [r4, #0x12]
    subs r2, r0, r1
    cmp r2, #0
    blt lbl_08070994
    lsls r0, r5, #1
    mov r5, sb
    adds r3, r0, r5
    lsls r0, r7, #1
    adds r1, r0, r5
    adds r2, #1
lbl_08070986:
    ldrh r0, [r3]
    strh r0, [r1]
    adds r3, #2
    adds r1, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070986
lbl_08070994:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080709a4: .4byte 0x0840d0fe
lbl_080709a8: .4byte 0x08754bc4
lbl_080709ac: .4byte 0x087601dc
lbl_080709b0: .4byte gEquipment
lbl_080709b4: .4byte gPauseScreenFlag
lbl_080709b8: .4byte 0x0840de91
lbl_080709bc: .4byte 0x0840de50

    thumb_func_start set_status_screen_bomb_visibilty
set_status_screen_bomb_visibilty: @ 0x080709c0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    str r0, [sp]
    str r0, [sp, #4]
    ldr r2, lbl_08070ae8 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xd1
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xd2
    strb r1, [r0]
    movs r7, #0
    ldr r3, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r3, #0xc]
    ldrb r0, [r0]
    ands r0, r1
    mov ip, r2
    cmp r0, #0
    beq lbl_08070a02
    movs r7, #2
    ldr r0, [r2]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a02:
    cmp r7, #0
    bne lbl_08070a08
    b lbl_08070bfe
lbl_08070a08:
    ldrb r0, [r3, #5]
    cmp r0, #0
    beq lbl_08070a1e
    movs r7, #3
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd2
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
lbl_08070a1e:
    movs r6, #0
    cmp r6, r7
    blt lbl_08070a26
    b lbl_08070ba6
lbl_08070a26:
    ldr r2, lbl_08070af4 @ =0x0840de50
    mov r8, r2
    ldrb r3, [r2, #7]
    mov sl, r3
    ldrb r0, [r2, #8]
    subs r3, r0, r3
    str r3, [sp, #0xc]
    ldr r4, lbl_08070af8 @ =0x0840de91
    ldrb r4, [r4, #7]
    str r4, [sp, #8]
lbl_08070a3a:
    mov r1, r8
    ldrb r0, [r1, #5]
    adds r0, r0, r6
    lsls r0, r0, #5
    mov r2, sl
    adds r5, r0, r2
    ldr r3, lbl_08070af8 @ =0x0840de91
    ldrb r1, [r3, #5]
    ldr r0, lbl_08070afc @ =0x087603ea
    adds r0, r6, r0
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r3, r1, #5
    ldr r4, [sp, #8]
    adds r3, r3, r4
    adds r0, r6, #1
    mov sb, r0
    ldr r1, [sp, #0xc]
    cmp r1, #0
    blt lbl_08070a86
    mov r2, r8
    ldrb r1, [r2, #8]
    ldrb r0, [r2, #7]
    subs r1, r1, r0
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r4, r0, r3
    lsls r0, r5, #1
    ldr r2, [sp]
    adds r3, r0, r2
    adds r2, r1, #1
lbl_08070a78:
    ldrh r0, [r4]
    strh r0, [r3]
    adds r4, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070a78
lbl_08070a86:
    movs r2, #0
    cmp r6, #1
    bne lbl_08070b00
    ldr r0, lbl_08070ae8 @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd1
    ldrb r2, [r3]
    adds r1, r6, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070ade
    ldr r4, lbl_08070aec @ =gEquipment
    ldr r0, lbl_08070af0 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ab6
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070ab6:
    mov r3, ip
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #4
    movs r3, #0
    orrs r0, r2
    strb r0, [r1]
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070ade
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd1
    ldrb r1, [r0]
    movs r2, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070ade:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd1
    b lbl_08070b60
    .align 2, 0
lbl_08070ae8: .4byte 0x08754bc4
lbl_08070aec: .4byte gEquipment
lbl_08070af0: .4byte 0x087601dc
lbl_08070af4: .4byte 0x0840de50
lbl_08070af8: .4byte 0x0840de91
lbl_08070afc: .4byte 0x087603ea
lbl_08070b00:
    cmp r6, #2
    bne lbl_08070b62
    ldr r0, lbl_08070c10 @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd2
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070b5a
    ldr r4, lbl_08070c14 @ =gEquipment
    ldr r0, lbl_08070c18 @ =0x087601dc
    ldr r0, [r0, #4]
    ldrb r1, [r4, #0xd]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b2e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070b2e:
    ldrb r0, [r4, #0xb]
    cmp r0, #0
    beq lbl_08070b42
    mov r2, ip
    ldr r0, [r2]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #4
    orrs r1, r2
    strb r1, [r0]
lbl_08070b42:
    ldrb r1, [r4, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08070b5a
    mov r3, ip
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r2, [r0]
    movs r1, #8
    orrs r1, r2
    strb r1, [r0]
lbl_08070b5a:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd2
lbl_08070b60:
    ldrb r2, [r0]
lbl_08070b62:
    cmp r2, #0
    beq lbl_08070b9e
    movs r0, #0
    cmp r2, #0xf
    bne lbl_08070b6e
    movs r0, #1
lbl_08070b6e:
    adds r2, r0, #0
    ldr r0, lbl_08070c1c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070b8e
    ldr r0, lbl_08070c20 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bne lbl_08070b8e
    cmp r6, #2
    bne lbl_08070b8e
    movs r2, #0
lbl_08070b8e:
    lsls r1, r6, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #1
    movs r3, #0
    bl sub_08070e1c
lbl_08070b9e:
    mov r6, sb
    cmp r6, r7
    bge lbl_08070ba6
    b lbl_08070a3a
lbl_08070ba6:
    ldr r2, lbl_08070c24 @ =0x0840de50
    ldrb r0, [r2, #5]
    adds r0, r0, r7
    lsls r0, r0, #5
    ldrb r4, [r2, #7]
    adds r5, r0, r4
    cmp r7, #2
    beq lbl_08070bb8
    adds r7, #1
lbl_08070bb8:
    ldr r0, lbl_08070c28 @ =0x0840de91
    ldrb r1, [r0, #5]
    adds r1, r1, r7
    lsls r1, r1, #5
    ldrb r0, [r0, #7]
    adds r3, r1, r0
    ldrb r0, [r2, #8]
    subs r2, r0, r4
    ldr r0, lbl_08070c10 @ =0x08754bc4
    mov ip, r0
    cmp r2, #0
    blt lbl_08070bec
    lsls r0, r3, #1
    ldr r3, [sp, #4]
    adds r1, r0, r3
    lsls r0, r5, #1
    ldr r4, [sp]
    adds r3, r0, r4
    adds r2, #1
lbl_08070bde:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bne lbl_08070bde
lbl_08070bec:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070bfe
    movs r0, #8
    strb r0, [r1]
lbl_08070bfe:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070c10: .4byte 0x08754bc4
lbl_08070c14: .4byte gEquipment
lbl_08070c18: .4byte 0x087601dc
lbl_08070c1c: .4byte gPauseScreenFlag
lbl_08070c20: .4byte gCurrentItemBeingAcquired
lbl_08070c24: .4byte 0x0840de50
lbl_08070c28: .4byte 0x0840de91

    thumb_func_start sub_08070c2c
sub_08070c2c: @ 0x08070c2c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov r8, r0
    movs r0, #0
    mov sl, r0
    ldr r3, lbl_08070d08 @ =gEquipment
    ldrh r0, [r3, #2]
    cmp r0, #0
    beq lbl_08070c58
    movs r1, #3
    mov sl, r1
    ldr r0, lbl_08070d0c @ =0x08754bc4
    ldr r1, [r0]
    adds r1, #0xd3
    ldrb r2, [r1]
    movs r0, #1
    orrs r0, r2
    strb r0, [r1]
lbl_08070c58:
    ldrb r0, [r3, #4]
    cmp r0, #0
    beq lbl_08070c7a
    movs r3, #5
    mov sl, r3
    ldr r3, lbl_08070d0c @ =0x08754bc4
    ldr r0, [r3]
    adds r0, #0xd4
    ldrb r1, [r0]
    movs r2, #1
    orrs r1, r2
    strb r1, [r0]
    ldr r0, [r3]
    adds r0, #0xd3
    ldrb r1, [r0]
    orrs r2, r1
    strb r2, [r0]
lbl_08070c7a:
    mov r4, sl
    cmp r4, #0
    bne lbl_08070c82
    b lbl_08070e00
lbl_08070c82:
    movs r5, #0
    cmp r5, sl
    blt lbl_08070c8a
    b lbl_08070db2
lbl_08070c8a:
    ldr r7, lbl_08070d10 @ =0x0840de50
    ldrb r0, [r7, #0x16]
    str r0, [sp]
    ldrb r0, [r7, #0x17]
    ldr r1, [sp]
    subs r0, r0, r1
    str r0, [sp, #4]
lbl_08070c98:
    ldrb r0, [r7, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldr r3, [sp]
    adds r6, r0, r3
    ldr r1, lbl_08070d14 @ =0x0840de91
    ldrb r0, [r1, #0x14]
    adds r0, r0, r5
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    adds r0, r5, #1
    mov sb, r0
    ldr r1, [sp, #4]
    cmp r1, #0
    blt lbl_08070cd8
    ldrb r1, [r7, #0x17]
    ldrb r0, [r7, #0x16]
    subs r1, r1, r0
    lsls r0, r4, #1
    mov r3, r8
    adds r2, r0, r3
    lsls r0, r6, #1
    adds r3, r0, r3
    adds r4, r1, #1
lbl_08070cca:
    ldrh r0, [r2]
    strh r0, [r3]
    adds r2, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070cca
lbl_08070cd8:
    movs r4, #0
    cmp r5, #1
    bne lbl_08070d18
    ldr r0, lbl_08070d0c @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd3
    ldrb r2, [r3]
    adds r1, r5, #0
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d00
    ldr r0, lbl_08070d08 @ =gEquipment
    ldrh r0, [r0, #8]
    cmp r0, #0
    beq lbl_08070d00
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d00:
    mov r4, ip
    ldr r0, [r4]
    adds r0, #0xd3
    b lbl_08070d44
    .align 2, 0
lbl_08070d08: .4byte gEquipment
lbl_08070d0c: .4byte 0x08754bc4
lbl_08070d10: .4byte 0x0840de50
lbl_08070d14: .4byte 0x0840de91
lbl_08070d18:
    cmp r5, #3
    bne lbl_08070d46
    ldr r0, lbl_08070d84 @ =0x08754bc4
    ldr r1, [r0]
    adds r3, r1, #0
    adds r3, #0xd4
    ldrb r2, [r3]
    movs r1, #1
    ands r1, r2
    mov ip, r0
    cmp r1, #0
    beq lbl_08070d3e
    ldr r0, lbl_08070d88 @ =gEquipment
    ldrb r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_08070d3e
    movs r0, #2
    orrs r0, r2
    strb r0, [r3]
lbl_08070d3e:
    mov r1, ip
    ldr r0, [r1]
    adds r0, #0xd4
lbl_08070d44:
    ldrb r4, [r0]
lbl_08070d46:
    cmp r4, #0
    beq lbl_08070daa
    movs r0, #0
    cmp r4, #3
    bne lbl_08070d52
    movs r0, #1
lbl_08070d52:
    adds r4, r0, #0
    ldr r0, lbl_08070d8c @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    bne lbl_08070d94
    cmp r5, #1
    bne lbl_08070d70
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #3
    beq lbl_08070d98
lbl_08070d70:
    cmp r5, #3
    bne lbl_08070d9a
    ldr r0, lbl_08070d90 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #5
    bne lbl_08070d9a
    b lbl_08070d98
    .align 2, 0
lbl_08070d84: .4byte 0x08754bc4
lbl_08070d88: .4byte gEquipment
lbl_08070d8c: .4byte gPauseScreenFlag
lbl_08070d90: .4byte gCurrentItemBeingAcquired
lbl_08070d94:
    cmp r0, #8
    bne lbl_08070d9a
lbl_08070d98:
    movs r4, #0
lbl_08070d9a:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r4, #0x18
    lsrs r2, r2, #0x18
    movs r0, #4
    movs r3, #0
    bl sub_08070e1c
lbl_08070daa:
    mov r5, sb
    cmp r5, sl
    bge lbl_08070db2
    b lbl_08070c98
lbl_08070db2:
    ldr r2, lbl_08070e10 @ =0x0840de50
    ldrb r0, [r2, #0x14]
    add r0, sl
    lsls r0, r0, #5
    ldrb r3, [r2, #0x16]
    adds r6, r0, r3
    ldr r1, lbl_08070e14 @ =0x0840de91
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #5
    ldrb r1, [r1, #0x16]
    adds r4, r0, r1
    ldrb r0, [r2, #0x17]
    subs r2, r0, r3
    ldr r3, lbl_08070e18 @ =0x08754bc4
    mov ip, r3
    cmp r2, #0
    blt lbl_08070dee
    lsls r0, r4, #1
    mov r4, r8
    adds r1, r0, r4
    lsls r0, r6, #1
    adds r3, r0, r4
    adds r4, r2, #1
lbl_08070de0:
    ldrh r0, [r1]
    strh r0, [r3]
    adds r1, #2
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bne lbl_08070de0
lbl_08070dee:
    mov r1, ip
    ldr r0, [r1]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08070e00
    movs r0, #6
    strb r0, [r1]
lbl_08070e00:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070e10: .4byte 0x0840de50
lbl_08070e14: .4byte 0x0840de91
lbl_08070e18: .4byte 0x08754bc4

    thumb_func_start sub_08070e1c
sub_08070e1c: @ 0x08070e1c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsls r2, r2, #0x18
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov ip, r3
    ldr r4, lbl_08070eac @ =0x0840de50
    lsls r3, r0, #2
    adds r3, r3, r0
    adds r0, r3, r4
    lsrs r1, r1, #0x18
    ldrb r0, [r0]
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r0, r4, #2
    adds r0, r3, r0
    ldrb r5, [r0]
    adds r1, r1, r5
    adds r4, #3
    adds r3, r3, r4
    ldrb r0, [r3]
    subs r4, r0, r5
    movs r0, #0xc0
    lsls r0, r0, #8
    cmp r2, #0
    beq lbl_08070e58
    movs r0, #0xb0
    lsls r0, r0, #8
lbl_08070e58:
    adds r5, r0, #0
    ldr r0, lbl_08070eb0 @ =0x08754bb4
    ldr r0, [r0]
    lsls r1, r1, #1
    adds r0, r1, r0
    ldr r3, lbl_08070eb4 @ =0x00007002
    adds r2, r0, r3
    adds r7, r1, #0
    cmp r4, #1
    ble lbl_08070e82
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e70:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e70
lbl_08070e82:
    mov r0, ip
    cmp r0, #0
    beq lbl_08070ea6
    ldr r3, lbl_08070ebc @ =0x0600c002
    adds r2, r7, r3
    cmp r4, #1
    ble lbl_08070ea6
    ldr r6, lbl_08070eb8 @ =0x00000fff
    subs r3, r4, #1
lbl_08070e94:
    ldrh r1, [r2]
    adds r0, r6, #0
    ands r0, r1
    orrs r0, r5
    strh r0, [r2]
    subs r3, #1
    adds r2, #2
    cmp r3, #0
    bne lbl_08070e94
lbl_08070ea6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070eac: .4byte 0x0840de50
lbl_08070eb0: .4byte 0x08754bb4
lbl_08070eb4: .4byte 0x00007002
lbl_08070eb8: .4byte 0x00000fff
lbl_08070ebc: .4byte 0x0600c002

    thumb_func_start sub_08070ec0
sub_08070ec0: @ 0x08070ec0
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r6, r1, #0x18
    cmp r4, #0
    beq lbl_08070eda
    cmp r4, #0
    blt lbl_08070ef8
    cmp r4, #3
    bgt lbl_08070ef8
    cmp r4, #2
    blt lbl_08070ef8
lbl_08070eda:
    ldr r2, lbl_08070ef4 @ =0x0840de91
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    subs r0, #1
    adds r2, #2
    adds r1, r1, r2
    lsls r0, r0, #5
    ldrb r1, [r1]
    adds r5, r0, r1
    b lbl_08070efa
    .align 2, 0
lbl_08070ef4: .4byte 0x0840de91
lbl_08070ef8:
    movs r5, #0
lbl_08070efa:
    cmp r5, #0
    beq lbl_08070f46
    ldr r3, lbl_08070f4c @ =0x0840de50
    lsls r1, r4, #2
    adds r1, r1, r4
    adds r0, r1, r3
    ldrb r2, [r0]
    adds r2, r2, r6
    lsls r2, r2, #5
    adds r0, r3, #2
    adds r0, r1, r0
    ldrb r4, [r0]
    adds r2, r2, r4
    adds r3, #3
    adds r1, r1, r3
    ldrb r0, [r1]
    subs r1, r0, r4
    lsls r0, r2, #1
    ldr r2, lbl_08070f50 @ =0x0600c002
    adds r3, r0, r2
    adds r5, #1
    cmp r1, #1
    ble lbl_08070f46
    ldr r6, lbl_08070f54 @ =0x08754bb4
    movs r4, #0xe0
    lsls r4, r4, #7
    subs r2, r1, #1
lbl_08070f30:
    ldr r0, [r6]
    lsls r1, r5, #1
    adds r0, r0, r4
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r3]
    subs r2, #1
    adds r3, #2
    adds r5, #1
    cmp r2, #0
    bne lbl_08070f30
lbl_08070f46:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070f4c: .4byte 0x0840de50
lbl_08070f50: .4byte 0x0600c002
lbl_08070f54: .4byte 0x08754bb4

    thumb_func_start check_select_pressed_on_status_screen
check_select_pressed_on_status_screen: @ 0x08070f58
    ldr r1, lbl_08070f68 @ =gChangedInput
    ldrh r1, [r1]
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    bx lr
    .align 2, 0
lbl_08070f68: .4byte gChangedInput

    thumb_func_start sub_08070f6c
sub_08070f6c: @ 0x08070f6c
    push {r4, lr}
    ldr r4, lbl_08070fac @ =0x08754bc4
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08070fa6
    bl sub_08071a3c
    ldr r2, [r4]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08070f9a
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
lbl_08070f9a:
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
lbl_08070fa6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08070fac: .4byte 0x08754bc4

    thumb_func_start sub_08070fb0
sub_08070fb0: @ 0x08070fb0
    push {r4, r5, lr}
    movs r5, #0
    ldr r0, lbl_08070fdc @ =0x08754bc4
    ldr r2, [r0]
    ldrb r1, [r2, #8]
    adds r4, r0, #0
    cmp r1, #5
    bls lbl_08070fca
    ldr r0, lbl_08070fe0 @ =0x03005804
    ldrh r1, [r0]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r5, r0, #0x1f
lbl_08070fca:
    cmp r5, #0
    beq lbl_08070fd0
    b lbl_080711c8
lbl_08070fd0:
    ldrb r0, [r2, #0xc]
    cmp r0, #0
    beq lbl_08070fe4
    bl sub_08068ec0
    b lbl_080711c8
    .align 2, 0
lbl_08070fdc: .4byte 0x08754bc4
lbl_08070fe0: .4byte 0x03005804
lbl_08070fe4:
    ldrb r0, [r2, #8]
    cmp r0, #7
    bls lbl_08070fec
    b lbl_080711c8
lbl_08070fec:
    lsls r0, r0, #2
    ldr r1, lbl_08070ff8 @ =lbl_08070ffc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08070ff8: .4byte lbl_08070ffc
lbl_08070ffc: @ jump table
    .4byte lbl_0807101c @ case 0
    .4byte lbl_08071098 @ case 1
    .4byte lbl_08071158 @ case 2
    .4byte lbl_0807117a @ case 3
    .4byte lbl_0807119a @ case 4
    .4byte lbl_080711a6 @ case 5
    .4byte lbl_080711c4 @ case 6
    .4byte lbl_080711c8 @ case 7
lbl_0807101c:
    ldr r2, [r4]
    ldrh r0, [r2, #0xa]
    cmp r0, #0x10
    bhi lbl_08071026
    b lbl_080711c8
lbl_08071026:
    adds r0, r2, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071080
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r2, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #2
    bl sub_08071b2c
    cmp r0, #0
    bge lbl_08071066
    ldr r0, lbl_0807105c @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071060
    ldr r1, [r4]
    movs r0, #3
    b lbl_0807106a
    .align 2, 0
lbl_0807105c: .4byte gDemoState
lbl_08071060:
    ldr r1, [r4]
    movs r0, #5
    b lbl_0807106a
lbl_08071066:
    ldr r1, [r4]
    movs r0, #1
lbl_0807106a:
    strb r0, [r1, #8]
    ldr r1, lbl_08071078 @ =gCurrentMessage
    movs r0, #0
    strb r0, [r1, #0xe]
    ldr r4, lbl_0807107c @ =0x08754bc4
    b lbl_0807108a
    .align 2, 0
lbl_08071078: .4byte gCurrentMessage
lbl_0807107c: .4byte 0x08754bc4
lbl_08071080:
    ldr r0, lbl_08071094 @ =gCurrentMessage
    movs r1, #1
    strb r1, [r0, #0xe]
    movs r0, #7
    strb r0, [r2, #8]
lbl_0807108a:
    ldr r1, [r4]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080711c8
    .align 2, 0
lbl_08071094: .4byte gCurrentMessage
lbl_08071098:
    ldr r1, [r4]
    ldrh r0, [r1, #0xa]
    cmp r0, #8
    bhi lbl_080710a2
    b lbl_080711c8
lbl_080710a2:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    ldr r0, lbl_080710c8 @ =gCurrentItemBeingAcquired
    ldrb r0, [r0]
    subs r0, #3
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0x11
    bhi lbl_0807113e
    lsls r0, r0, #2
    ldr r1, lbl_080710cc @ =lbl_080710d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080710c8: .4byte gCurrentItemBeingAcquired
lbl_080710cc: .4byte lbl_080710d0
lbl_080710d0: @ jump table
    .4byte lbl_08071124 @ case 0
    .4byte lbl_0807113e @ case 1
    .4byte lbl_08071124 @ case 2
    .4byte lbl_0807113e @ case 3
    .4byte lbl_08071124 @ case 4
    .4byte lbl_0807113e @ case 5
    .4byte lbl_0807113e @ case 6
    .4byte lbl_0807113e @ case 7
    .4byte lbl_0807113e @ case 8
    .4byte lbl_08071118 @ case 9
    .4byte lbl_0807113e @ case 10
    .4byte lbl_0807113e @ case 11
    .4byte lbl_08071118 @ case 12
    .4byte lbl_0807113e @ case 13
    .4byte lbl_0807113e @ case 14
    .4byte lbl_0807113e @ case 15
    .4byte lbl_0807113e @ case 16
    .4byte lbl_08071118 @ case 17
lbl_08071118:
    ldr r0, lbl_08071120 @ =0x0000020f
    bl SoundPlay
    b lbl_08071144
    .align 2, 0
lbl_08071120: .4byte 0x0000020f
lbl_08071124:
    ldr r2, lbl_0807114c @ =0x0840dec4
    ldr r0, lbl_08071150 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
lbl_0807113e:
    ldr r0, lbl_08071154 @ =0x000001f7
    bl SoundPlay
lbl_08071144:
    ldr r0, lbl_08071150 @ =0x08754bc4
    ldr r1, [r0]
    b lbl_08071184
    .align 2, 0
lbl_0807114c: .4byte 0x0840dec4
lbl_08071150: .4byte 0x08754bc4
lbl_08071154: .4byte 0x000001f7
lbl_08071158:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    bne lbl_080711c8
    strh r0, [r1, #0xa]
    ldr r0, lbl_08071170 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08071174
    movs r0, #3
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071170: .4byte gDemoState
lbl_08071174:
    movs r0, #5
    strb r0, [r1, #8]
    b lbl_080711c8
lbl_0807117a:
    ldr r0, lbl_08071190 @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_08071194
    ldr r1, [r4]
lbl_08071184:
    movs r0, #0
    strh r0, [r1, #0xa]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_08071190: .4byte gCurrentMessage
lbl_08071194:
    bl sub_0806f680
    b lbl_080711c8
lbl_0807119a:
    ldr r0, [r4]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x1e
    bls lbl_080711c8
    movs r5, #1
    b lbl_080711c8
lbl_080711a6:
    bl sub_0806f680
    ldr r0, lbl_080711bc @ =gCurrentMessage
    ldrb r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_080711c8
    ldr r0, lbl_080711c0 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #7
    strb r0, [r1, #8]
    b lbl_080711c8
    .align 2, 0
lbl_080711bc: .4byte gCurrentMessage
lbl_080711c0: .4byte 0x08754bc4
lbl_080711c4:
    bl sub_0806f680
lbl_080711c8:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_080711d0
sub_080711d0: @ 0x080711d0
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldr r3, lbl_080711e8 @ =0x08754bc4
lbl_080711d8:
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r0, [r2]
    cmp r0, #0x11
    bls lbl_080711ec
    movs r0, #2
    b lbl_0807128a
    .align 2, 0
lbl_080711e8: .4byte 0x08754bc4
lbl_080711ec:
    ldr r1, lbl_08071208 @ =0x0840dec4
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r4, r1, #0
    cmp r0, #4
    bhi lbl_08071256
    lsls r0, r0, #2
    ldr r1, lbl_0807120c @ =lbl_08071210
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071208: .4byte 0x0840dec4
lbl_0807120c: .4byte lbl_08071210
lbl_08071210: @ jump table
    .4byte lbl_08071224 @ case 0
    .4byte lbl_08071238 @ case 1
    .4byte lbl_08071242 @ case 2
    .4byte lbl_0807124c @ case 3
    .4byte lbl_0807122e @ case 4
lbl_08071224:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc4
    movs r2, #8
    b lbl_0807125a
lbl_0807122e:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd3
    movs r2, #0xff
    b lbl_0807125a
lbl_08071238:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xd1
    movs r2, #0xff
    b lbl_0807125a
lbl_08071242:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xc9
    movs r2, #0x20
    b lbl_0807125a
lbl_0807124c:
    ldr r0, [r3]
    adds r1, r0, #0
    adds r1, #0xcb
    movs r2, #4
    b lbl_0807125a
lbl_08071256:
    movs r0, #0
    b lbl_0807128a
lbl_0807125a:
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r4
    ldrb r0, [r0, #1]
    adds r0, r1, r0
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807127e
    cmp r5, #0
    bne lbl_0807127a
    cmp r0, r2
    beq lbl_0807127e
lbl_08071276:
    movs r0, #1
    b lbl_0807128a
lbl_0807127a:
    cmp r0, r2
    beq lbl_08071276
lbl_0807127e:
    ldr r1, [r3]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080711d8
lbl_0807128a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08071290
sub_08071290: @ 0x08071290
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    movs r6, #0
    ldr r5, lbl_080712b8 @ =0x08754bc4
    ldr r1, [r5]
    ldrh r0, [r1, #0x20]
    adds r3, r0, #1
    movs r7, #0
    strh r3, [r1, #0x20]
    cmp r2, #1
    beq lbl_080712d8
    cmp r2, #1
    bgt lbl_080712bc
    cmp r2, #0
    beq lbl_080712c8
    b lbl_08071414
    .align 2, 0
lbl_080712b8: .4byte 0x08754bc4
lbl_080712bc:
    cmp r4, #2
    beq lbl_08071368
    cmp r4, #3
    bne lbl_080712c6
    b lbl_080713c8
lbl_080712c6:
    b lbl_08071414
lbl_080712c8:
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    strb r7, [r0]
    ldr r0, [r5]
    adds r0, #0x23
    strb r7, [r0]
    b lbl_08071414
lbl_080712d8:
    movs r2, #0
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r0, [r0]
    cmp r0, #1
    bhi lbl_0807131c
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x22
    ldrb r0, [r0]
    cmp r0, #7
    bls lbl_08071314
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r1, [r0]
    adds r1, #1
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x22
    strb r7, [r0]
lbl_08071314:
    ldr r1, lbl_08071318 @ =0x0840df64
    b lbl_0807134c
    .align 2, 0
lbl_08071318: .4byte 0x0840df64
lbl_0807131c:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #2
    bls lbl_0807135c
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #5
    bls lbl_0807134a
    movs r0, #5
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x23
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    movs r6, #1
lbl_0807134a:
    ldr r1, lbl_08071364 @ =0x0840df6c
lbl_0807134c:
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r2, r0, #4
lbl_0807135c:
    cmp r2, #0
    beq lbl_08071414
    lsls r1, r2, #1
    b lbl_0807139e
    .align 2, 0
lbl_08071364: .4byte 0x0840df6c
lbl_08071368:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    movs r0, #0
    ldrsb r0, [r1, r0]
    cmp r0, #0
    bne lbl_0807138c
    strb r7, [r1]
    movs r6, #1
lbl_0807138c:
    ldr r1, lbl_080713bc @ =0x0840df6c
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
lbl_0807139e:
    ldr r0, lbl_080713c0 @ =0x0840dd10
    adds r1, r1, r0
    ldr r0, lbl_080713c4 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_08071414
    .align 2, 0
lbl_080713bc: .4byte 0x0840df6c
lbl_080713c0: .4byte 0x0840dd10
lbl_080713c4: .4byte 0x08754bbc
lbl_080713c8:
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bls lbl_08071414
    strh r6, [r1, #0x20]
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x22
    ldrb r0, [r1]
    cmp r0, #3
    bls lbl_080713e8
    strb r7, [r1]
lbl_080713e8:
    ldr r1, lbl_08071420 @ =0x0840df72
    ldr r0, [r5]
    adds r0, #0x22
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r1, r1, #5
    ldr r0, lbl_08071424 @ =0x0840ddd0
    adds r1, r1, r0
    ldr r0, lbl_08071428 @ =0x08754bbc
    ldr r2, [r0]
    movs r0, #0xc0
    lsls r0, r0, #1
    adds r2, r2, r0
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
lbl_08071414:
    adds r0, r6, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071420: .4byte 0x0840df72
lbl_08071424: .4byte 0x0840ddd0
lbl_08071428: .4byte 0x08754bbc

    thumb_func_start sub_0807142c
sub_0807142c: @ 0x0807142c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r0, lbl_08071448 @ =0x08754bc4
    ldr r2, [r0]
    ldrb r1, [r2, #0xc]
    adds r7, r0, #0
    cmp r1, #0
    beq lbl_0807144c
    bl sub_08068ec0
    b lbl_080717f0
    .align 2, 0
lbl_08071448: .4byte 0x08754bc4
lbl_0807144c:
    ldrb r0, [r2, #8]
    cmp r0, #0xb
    bls lbl_08071454
    b lbl_080717ec
lbl_08071454:
    lsls r0, r0, #2
    ldr r1, lbl_08071460 @ =lbl_08071464
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071460: .4byte lbl_08071464
lbl_08071464: @ jump table
    .4byte lbl_08071494 @ case 0
    .4byte lbl_080714ac @ case 1
    .4byte lbl_080714d2 @ case 2
    .4byte lbl_0807150c @ case 3
    .4byte lbl_0807159c @ case 4
    .4byte lbl_080715e4 @ case 5
    .4byte lbl_08071680 @ case 6
    .4byte lbl_08071724 @ case 7
    .4byte lbl_08071684 @ case 8
    .4byte lbl_08071744 @ case 9
    .4byte lbl_080717a6 @ case 10
    .4byte lbl_080717ec @ case 11
lbl_08071494:
    ldr r0, [r7]
    ldrh r0, [r0, #0xa]
    cmp r0, #0x32
    bhi lbl_0807149e
    b lbl_080717f0
lbl_0807149e:
    movs r0, #2
    bl sub_08068dbc
    ldr r1, [r7]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080714ca
lbl_080714ac:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #0x1e
    bhi lbl_080714b6
    b lbl_080717f0
lbl_080714b6:
    adds r0, r1, #0
    adds r0, #0xc1
    movs r2, #0
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r7]
    adds r0, #0xea
    strb r1, [r0]
    ldr r1, [r7]
    strh r2, [r1, #0xa]
lbl_080714ca:
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    b lbl_080717f0
lbl_080714d2:
    movs r0, #0
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #2
    bne lbl_080714fa
    ldr r2, lbl_08071504 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0xc1
    movs r1, #1
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080714fa
    ldr r0, lbl_08071508 @ =0x00000215
    movs r1, #0xf
    bl SoundFade
lbl_080714fa:
    ldr r3, lbl_08071504 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, r0, r5
    b lbl_08071736
    .align 2, 0
lbl_08071504: .4byte 0x08754bc4
lbl_08071508: .4byte 0x00000215
lbl_0807150c:
    ldr r1, [r7]
    ldrh r0, [r1, #0xa]
    cmp r0, #6
    bhi lbl_08071516
    b lbl_080717f0
lbl_08071516:
    ldr r2, lbl_08071558 @ =0x0840dec4
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl sub_08070e1c
    ldr r0, [r7]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r7]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0xd
    bl UpdateMenuOamDataID
    ldr r0, [r7]
    adds r2, r0, #0
    adds r2, #0xc1
    ldrb r1, [r2]
    cmp r1, #7
    bls lbl_0807155c
    adds r0, #0xc3
    b lbl_0807155e
    .align 2, 0
lbl_08071558: .4byte 0x0840dec4
lbl_0807155c:
    adds r0, #0xc2
lbl_0807155e:
    strb r1, [r0]
    ldr r4, lbl_08071594 @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xea
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807157a
    ldr r0, lbl_08071598 @ =0x00000215
    bl SoundPlay
    ldr r0, [r4]
    adds r0, #0xea
    movs r1, #0
    strb r1, [r0]
lbl_0807157a:
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    subs r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071594: .4byte 0x08754bc4
lbl_08071598: .4byte 0x00000215
lbl_0807159c:
    movs r0, #1
    bl sub_080711d0
    adds r5, r0, #0
    cmp r5, #1
    bne lbl_080715cc
    ldr r2, lbl_080715c4 @ =0x06007800
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    ldr r0, lbl_080715c8 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r1, #8]
    adds r0, #1
    b lbl_080715d2
    .align 2, 0
lbl_080715c4: .4byte 0x06007800
lbl_080715c8: .4byte 0x08754bc4
lbl_080715cc:
    ldr r0, lbl_080715e0 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0xa
lbl_080715d2:
    strb r0, [r1, #8]
    ldr r0, lbl_080715e0 @ =0x08754bc4
    ldr r1, [r0]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_080715e0: .4byte 0x08754bc4
lbl_080715e4:
    ldr r0, lbl_08071678 @ =0x0840dec4
    ldr r1, [r7]
    adds r1, #0xc1
    ldrb r1, [r1]
    lsls r1, r1, #2
    adds r1, r1, r0
    ldrb r0, [r1]
    movs r5, #0x2f
    cmp r0, #0
    beq lbl_08071600
    movs r5, #0x31
    cmp r0, #2
    bne lbl_08071600
    movs r5, #0x33
lbl_08071600:
    ldr r0, [r7]
    movs r4, #0xd4
    lsls r4, r4, #1
    adds r0, r0, r4
    adds r1, r5, #0
    bl UpdateMenuOamDataID
    ldr r5, [r7]
    ldr r3, lbl_0807167c @ =0x0840de50
    ldr r6, lbl_08071678 @ =0x0840dec4
    movs r2, #0xc1
    adds r2, r2, r5
    mov ip, r2
    ldrb r1, [r2]
    lsls r1, r1, #2
    adds r1, r1, r6
    ldrb r2, [r1]
    lsls r0, r2, #2
    adds r0, r0, r2
    adds r0, r0, r3
    ldrb r0, [r0]
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r4, r5, r4
    movs r1, #0
    mov r8, r1
    strh r0, [r4]
    mov r2, ip
    ldrb r0, [r2]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r1, [r0]
    lsls r0, r1, #2
    adds r0, r0, r1
    adds r3, #2
    adds r0, r0, r3
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #5
    movs r2, #0xd5
    lsls r2, r2, #1
    adds r1, r5, r2
    strh r0, [r1]
    movs r0, #0
    bl sub_08071290
    movs r0, #0x85
    lsls r0, r0, #2
    bl SoundPlay
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r7]
    mov r1, r8
    strh r1, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071678: .4byte 0x0840dec4
lbl_0807167c: .4byte 0x0840de50
lbl_08071680:
    movs r0, #1
    b lbl_08071726
lbl_08071684:
    ldr r2, lbl_080716c8 @ =0x0840dec4
    ldr r4, lbl_080716cc @ =0x08754bc4
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r1, [r0]
    lsls r1, r1, #2
    adds r1, r1, r2
    ldrb r0, [r1]
    ldrb r1, [r1, #2]
    bl sub_08070ec0
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    bl sub_08071a3c
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #6
    bl UpdateMenuOamDataID
    ldr r0, lbl_080716d0 @ =0x000001f7
    bl SoundPlay
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r1, [r1]
    cmp r1, #7
    bls lbl_080716d4
    adds r0, #0xc3
    b lbl_080716d6
    .align 2, 0
lbl_080716c8: .4byte 0x0840dec4
lbl_080716cc: .4byte 0x08754bc4
lbl_080716d0: .4byte 0x000001f7
lbl_080716d4:
    adds r0, #0xc2
lbl_080716d6:
    strb r1, [r0]
    ldr r3, lbl_08071718 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    movs r2, #0xd9
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, lbl_0807171c @ =0x0840dec4
    ldr r0, [r3]
    adds r0, #0xc1
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_080717f0
    ldr r0, lbl_08071720 @ =gEquipment
    ldrb r1, [r0, #0xf]
    movs r2, #0x20
    orrs r1, r2
    strb r1, [r0, #0xf]
    movs r0, #2
    bl sub_08068dbc
    b lbl_080717f0
    .align 2, 0
lbl_08071718: .4byte 0x08754bc4
lbl_0807171c: .4byte 0x0840dec4
lbl_08071720: .4byte gEquipment
lbl_08071724:
    movs r0, #2
lbl_08071726:
    bl sub_08071290
    cmp r0, #0
    beq lbl_080717f0
    ldr r3, lbl_08071740 @ =0x08754bc4
    ldr r1, [r3]
    ldrb r0, [r1, #8]
    adds r0, #1
lbl_08071736:
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    b lbl_080717f0
    .align 2, 0
lbl_08071740: .4byte 0x08754bc4
lbl_08071744:
    movs r0, #3
    bl sub_08071290
    ldr r3, lbl_08071794 @ =gCurrentMessage
    ldrb r0, [r3, #0xe]
    cmp r0, #0
    beq lbl_080717a0
    ldr r0, lbl_08071798 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080717f0
    ldr r4, lbl_0807179c @ =0x08754bc4
    ldr r1, [r4]
    adds r1, #0xc1
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    strb r2, [r3, #0xe]
    ldr r0, [r4]
    movs r1, #0xd4
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r0, [r4]
    movs r2, #0x84
    lsls r2, r2, #1
    adds r0, r0, r2
    movs r1, #0
    bl UpdateMenuOamDataID
    ldr r1, [r4]
    movs r0, #4
    strb r0, [r1, #8]
    b lbl_080717f0
    .align 2, 0
lbl_08071794: .4byte gCurrentMessage
lbl_08071798: .4byte gChangedInput
lbl_0807179c: .4byte 0x08754bc4
lbl_080717a0:
    bl sub_0806f680
    b lbl_080717f0
lbl_080717a6:
    ldr r0, lbl_080717c0 @ =gEquipment
    ldrb r1, [r0, #0xc]
    strb r1, [r0, #0xd]
    ldrb r1, [r0, #0xe]
    strb r1, [r0, #0xf]
    ldr r1, [r7]
    adds r0, r1, #0
    adds r0, #0xc3
    ldrb r2, [r0]
    cmp r2, #0
    beq lbl_080717c4
    subs r0, #2
    b lbl_080717da
    .align 2, 0
lbl_080717c0: .4byte gEquipment
lbl_080717c4:
    adds r0, r1, #0
    adds r0, #0xc2
    ldrb r3, [r0]
    adds r2, r3, #0
    cmp r2, #0
    beq lbl_080717d6
    subs r0, #1
    strb r3, [r0]
    b lbl_080717dc
lbl_080717d6:
    adds r0, r1, #0
    adds r0, #0xc1
lbl_080717da:
    strb r2, [r0]
lbl_080717dc:
    ldr r1, [r7]
    ldrb r0, [r1, #8]
    adds r0, #1
    movs r2, #0
    strb r0, [r1, #8]
    ldr r0, [r7]
    strh r2, [r0, #0xa]
    b lbl_080717f0
lbl_080717ec:
    movs r0, #1
    b lbl_080717f2
lbl_080717f0:
    movs r0, #0
lbl_080717f2:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08071800
sub_08071800: @ 0x08071800
    push {r4, lr}
    ldr r0, lbl_0807182c @ =gChangedInput
    ldrh r1, [r0]
    ldr r0, lbl_08071830 @ =0x00000302
    ands r0, r1
    ldr r4, lbl_08071834 @ =0x08754bc4
    cmp r0, #0
    beq lbl_08071838
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    cmp r0, #0
    bne lbl_08071838
    ldrb r2, [r1, #0xc]
    cmp r2, #0
    bne lbl_08071840
    movs r0, #0xc
    strb r0, [r1, #4]
    ldr r0, [r4]
    movs r1, #0
    strh r2, [r0, #0xa]
    strb r1, [r0, #8]
    b lbl_0807188e
    .align 2, 0
lbl_0807182c: .4byte gChangedInput
lbl_08071830: .4byte 0x00000302
lbl_08071834: .4byte 0x08754bc4
lbl_08071838:
    ldr r1, [r4]
    ldrb r0, [r1, #0xc]
    cmp r0, #0
    beq lbl_08071846
lbl_08071840:
    bl sub_08068ec0
    b lbl_0807188a
lbl_08071846:
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0807188a
    movs r0, #4
    bl check_select_pressed_on_status_screen
    cmp r0, #0
    beq lbl_08071886
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #1
    bl sub_08071b2c
    cmp r0, #1
    bne lbl_08071878
    ldr r0, lbl_08071874 @ =0x000001f7
    bl SoundPlay
    b lbl_0807188a
    .align 2, 0
lbl_08071874: .4byte 0x000001f7
lbl_08071878:
    cmp r0, #0
    bne lbl_0807188a
    movs r0, #0xfc
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0807188a
lbl_08071886:
    bl sub_08071dc0
lbl_0807188a:
    bl sub_0806f680
lbl_0807188e:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start get_current_equipment_selected
get_current_equipment_selected: @ 0x08071894
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    movs r3, #0x80
    lsrs r2, r0, #0x18
    movs r1, #0xff
    lsls r1, r1, #0x18
    adds r0, r0, r1
    lsrs r0, r0, #0x18
    cmp r0, #0x10
    bls lbl_080718ac
    movs r0, #0x80
    b lbl_08071a34
lbl_080718ac:
    ldr r0, lbl_080718d4 @ =gEquipment
    ldrb r1, [r0, #0x12]
    adds r5, r0, #0
    cmp r1, #2
    bne lbl_080718b8
    b lbl_08071a30
lbl_080718b8:
    ldr r0, lbl_080718d8 @ =0x0840dec4
    lsls r2, r2, #2
    adds r1, r2, r0
    ldrb r1, [r1]
    adds r4, r0, #0
    cmp r1, #4
    bls lbl_080718c8
    b lbl_08071a32
lbl_080718c8:
    lsls r0, r1, #2
    ldr r1, lbl_080718dc @ =lbl_080718e0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080718d4: .4byte gEquipment
lbl_080718d8: .4byte 0x0840dec4
lbl_080718dc: .4byte lbl_080718e0
lbl_080718e0: @ jump table
    .4byte lbl_080718f4 @ case 0
    .4byte lbl_08071970 @ case 1
    .4byte lbl_08071990 @ case 2
    .4byte lbl_080719c8 @ case 3
    .4byte lbl_08071950 @ case 4
lbl_080718f4:
    ldr r0, lbl_08071914 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc4
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    bne lbl_08071908
    b lbl_08071a32
lbl_08071908:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071918
    movs r3, #0
    b lbl_08071a32
    .align 2, 0
lbl_08071914: .4byte 0x08754bc4
lbl_08071918:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071924
    movs r3, #1
    b lbl_08071a32
lbl_08071924:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071930
    movs r3, #2
    b lbl_08071a32
lbl_08071930:
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    beq lbl_0807193c
    movs r3, #3
    b lbl_08071a32
lbl_0807193c:
    movs r0, #8
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #4
    b lbl_08071a32
lbl_08071950:
    ldr r0, lbl_0807196c @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd3
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #6
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #5
    b lbl_08071a32
    .align 2, 0
lbl_0807196c: .4byte 0x08754bc4
lbl_08071970:
    ldr r0, lbl_0807198c @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r2, r4
    ldrb r2, [r1, #1]
    adds r0, #0xd1
    adds r0, r0, r2
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r3, #8
    cmp r2, #0
    bne lbl_08071a32
    movs r3, #7
    b lbl_08071a32
    .align 2, 0
lbl_0807198c: .4byte 0x08754bc4
lbl_08071990:
    ldr r0, lbl_080719b0 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xc9
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_080719b4
    movs r3, #9
    b lbl_08071a32
    .align 2, 0
lbl_080719b0: .4byte 0x08754bc4
lbl_080719b4:
    movs r0, #0x20
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0xa
    b lbl_08071a32
lbl_080719c8:
    ldr r0, lbl_080719e8 @ =0x08754bc4
    ldr r0, [r0]
    adds r1, r2, r4
    adds r0, #0xcb
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #0
    beq lbl_08071a32
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_080719ec
    movs r3, #0xb
    b lbl_08071a32
    .align 2, 0
lbl_080719e8: .4byte 0x08754bc4
lbl_080719ec:
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_080719f8
    movs r3, #0xc
    b lbl_08071a32
lbl_080719f8:
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a04
    movs r3, #0xd
    b lbl_08071a32
lbl_08071a04:
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a10
    movs r3, #0xe
    b lbl_08071a32
lbl_08071a10:
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08071a1c
    movs r3, #0xf
    b lbl_08071a32
lbl_08071a1c:
    movs r0, #4
    ands r1, r0
    cmp r1, #0
    beq lbl_08071a32
    ldrb r0, [r5, #0x12]
    movs r3, #0x11
    cmp r0, #1
    bne lbl_08071a32
    movs r3, #0x10
    b lbl_08071a32
lbl_08071a30:
    movs r3, #0x12
lbl_08071a32:
    adds r0, r3, #0
lbl_08071a34:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_08071a3c
sub_08071a3c: @ 0x08071a3c
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    ldr r3, lbl_08071a80 @ =0x0840de50
    ldr r1, lbl_08071a84 @ =0x0840dec4
    lsrs r0, r0, #0x16
    adds r0, r0, r1
    ldrb r1, [r0]
    lsls r2, r1, #2
    adds r2, r2, r1
    adds r1, r2, r3
    ldrb r4, [r1]
    ldrb r0, [r0, #2]
    adds r4, r4, r0
    adds r3, #2
    adds r2, r2, r3
    ldrb r0, [r2]
    adds r0, #1
    ldr r1, lbl_08071a88 @ =0x08754bc4
    ldr r3, [r1]
    lsls r2, r4, #5
    movs r5, #0x84
    lsls r5, r5, #1
    adds r1, r3, r5
    strh r2, [r1]
    lsls r1, r0, #5
    adds r5, #2
    adds r2, r3, r5
    strh r1, [r2]
    lsls r0, r0, #0x10
    orrs r0, r4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071a80: .4byte 0x0840de50
lbl_08071a84: .4byte 0x0840dec4
lbl_08071a88: .4byte 0x08754bc4

    thumb_func_start sub_08071a8c
sub_08071a8c: @ 0x08071a8c
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    movs r4, #0
    ldr r1, lbl_08071aac @ =0x0840dec4
    lsls r0, r2, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    adds r3, r1, #0
    cmp r0, #4
    bhi lbl_08071b1e
    lsls r0, r0, #2
    ldr r1, lbl_08071ab0 @ =lbl_08071ab4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071aac: .4byte 0x0840dec4
lbl_08071ab0: .4byte lbl_08071ab4
lbl_08071ab4: @ jump table
    .4byte lbl_08071ac8 @ case 0
    .4byte lbl_08071ae8 @ case 1
    .4byte lbl_08071af8 @ case 2
    .4byte lbl_08071b08 @ case 3
    .4byte lbl_08071ad8 @ case 4
lbl_08071ac8:
    ldr r0, lbl_08071ad4 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc4
    b lbl_08071b12
    .align 2, 0
lbl_08071ad4: .4byte 0x08754bc4
lbl_08071ad8:
    ldr r0, lbl_08071ae4 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd3
    b lbl_08071b12
    .align 2, 0
lbl_08071ae4: .4byte 0x08754bc4
lbl_08071ae8:
    ldr r0, lbl_08071af4 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xd1
    b lbl_08071b12
    .align 2, 0
lbl_08071af4: .4byte 0x08754bc4
lbl_08071af8:
    ldr r0, lbl_08071b04 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xc9
    b lbl_08071b12
    .align 2, 0
lbl_08071b04: .4byte 0x08754bc4
lbl_08071b08:
    ldr r0, lbl_08071b28 @ =0x08754bc4
    ldr r1, [r0]
    lsls r0, r2, #2
    adds r0, r0, r3
    adds r1, #0xcb
lbl_08071b12:
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08071b1e
    movs r4, #1
lbl_08071b1e:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071b28: .4byte 0x08754bc4

    thumb_func_start sub_08071b2c
sub_08071b2c: @ 0x08071b2c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    movs r6, #0
    ldr r1, lbl_08071b58 @ =0x0840dec4
    lsls r0, r4, #2
    adds r0, r0, r1
    ldrb r0, [r0]
    mov ip, r1
    ldr r2, lbl_08071b5c @ =0x08754bc4
    cmp r0, #4
    bhi lbl_08071c1a
    lsls r0, r0, #2
    ldr r1, lbl_08071b60 @ =lbl_08071b64
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071b58: .4byte 0x0840dec4
lbl_08071b5c: .4byte 0x08754bc4
lbl_08071b60: .4byte lbl_08071b64
lbl_08071b64: @ jump table
    .4byte lbl_08071b78 @ case 0
    .4byte lbl_08071b9c @ case 1
    .4byte lbl_08071bc8 @ case 2
    .4byte lbl_08071bfc @ case 3
    .4byte lbl_08071c1a @ case 4
lbl_08071b78:
    ldr r2, lbl_08071b94 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc4
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071b98 @ =0x0300153d
    cmp r6, #8
    bne lbl_08071c1a
    ldrb r0, [r5, #5]
    b lbl_08071c14
    .align 2, 0
lbl_08071b94: .4byte 0x08754bc4
lbl_08071b98: .4byte 0x0300153d
lbl_08071b9c:
    ldr r2, lbl_08071bc0 @ =0x08754bc4
    cmp r4, #8
    bne lbl_08071c1a
    ldr r3, lbl_08071bc4 @ =gEquipment
    ldrb r1, [r3, #0xf]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071c1a
    ldrb r1, [r3, #0xd]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c1a
    movs r6, #0x80
    adds r5, r3, #0
    adds r5, #0xd
    b lbl_08071c1a
    .align 2, 0
lbl_08071bc0: .4byte 0x08754bc4
lbl_08071bc4: .4byte gEquipment
lbl_08071bc8:
    ldr r2, lbl_08071bf4 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xc9
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071bf8 @ =0x0300153f
    cmp r6, #0x20
    bne lbl_08071be6
    ldrb r0, [r5, #3]
    cmp r0, #1
    beq lbl_08071be6
    movs r6, #0
lbl_08071be6:
    cmp r6, #0
    beq lbl_08071c1a
    ldrb r0, [r5]
    ands r0, r6
    cmp r0, #0
    beq lbl_08071c1a
    b lbl_08071c18
    .align 2, 0
lbl_08071bf4: .4byte 0x08754bc4
lbl_08071bf8: .4byte 0x0300153f
lbl_08071bfc:
    ldr r2, lbl_08071c40 @ =0x08754bc4
    ldr r1, [r2]
    lsls r0, r4, #2
    add r0, ip
    adds r1, #0xcb
    ldrb r0, [r0, #1]
    adds r1, r1, r0
    ldrb r6, [r1]
    ldr r5, lbl_08071c44 @ =0x0300153f
    cmp r6, #4
    bne lbl_08071c1a
    ldrb r0, [r5, #3]
lbl_08071c14:
    cmp r0, #1
    beq lbl_08071c1a
lbl_08071c18:
    movs r6, #0
lbl_08071c1a:
    ldr r0, [r2]
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08071c36
    ldr r0, lbl_08071c48 @ =gPauseScreenFlag
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #6
    beq lbl_08071c36
    movs r6, #0
lbl_08071c36:
    cmp r6, #0
    bne lbl_08071c4c
    movs r3, #0
    movs r7, #0xff
    b lbl_08071d8a
    .align 2, 0
lbl_08071c40: .4byte 0x08754bc4
lbl_08071c44: .4byte 0x0300153f
lbl_08071c48: .4byte gPauseScreenFlag
lbl_08071c4c:
    cmp r7, #0
    beq lbl_08071c54
    cmp r7, #2
    bne lbl_08071c64
lbl_08071c54:
    ldrb r1, [r5]
    ands r1, r6
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r8, r4
    b lbl_08071d5a
lbl_08071c64:
    ldrb r1, [r5]
    adds r0, r6, #0
    eors r0, r1
    strb r0, [r5]
    adds r1, r6, #0
    ands r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    lsls r4, r4, #2
    mov r1, ip
    adds r0, r4, r1
    ldrb r5, [r0]
    ldrb r1, [r0, #2]
    adds r0, r5, #0
    adds r2, r7, #0
    movs r3, #1
    bl sub_08070e1c
    mov r8, r4
    cmp r5, #2
    beq lbl_08071cfc
    cmp r5, #2
    bgt lbl_08071c9a
    cmp r5, #1
    beq lbl_08071d04
    b lbl_08071d5a
lbl_08071c9a:
    cmp r5, #3
    bne lbl_08071d5a
    movs r0, #0x40
    ands r0, r6
    cmp r0, #0
    beq lbl_08071d5a
    movs r3, #0
    ldr r4, lbl_08071cf8 @ =0x08754bc4
lbl_08071caa:
    ldr r0, [r4]
    adds r0, #0xd1
    adds r2, r0, r3
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    adds r5, r3, #1
    cmp r0, #0
    beq lbl_08071cec
    movs r0, #7
    ands r0, r1
    strb r0, [r2]
    ldr r2, [r4]
    adds r2, #0xd1
    adds r2, r2, r3
    lsls r0, r7, #3
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
    movs r2, #0
    ldr r0, [r4]
    adds r0, #0xd1
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071ce0
    movs r2, #1
lbl_08071ce0:
    lsls r1, r5, #0x18
    lsrs r1, r1, #0x18
    movs r0, #1
    movs r3, #1
    bl sub_08070e1c
lbl_08071cec:
    lsls r0, r5, #0x18
    lsrs r3, r0, #0x18
    cmp r3, #1
    bls lbl_08071caa
    b lbl_08071d5a
    .align 2, 0
lbl_08071cf8: .4byte 0x08754bc4
lbl_08071cfc:
    movs r0, #2
    bl sub_08068dbc
    b lbl_08071d5a
lbl_08071d04:
    ldr r3, lbl_08071db4 @ =0x08754bc4
    ldr r1, [r3]
    adds r1, #0xd1
    ldrb r2, [r1]
    movs r0, #0xd
    mov ip, r0
    ands r0, r2
    strb r0, [r1]
    ldr r1, [r3]
    adds r1, #0xd1
    lsls r4, r7, #1
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    ldr r0, [r3]
    adds r2, r0, #0
    adds r2, #0xd2
    ldrb r1, [r2]
    ands r5, r1
    cmp r5, #0
    beq lbl_08071d5a
    mov r0, ip
    ands r0, r1
    strb r0, [r2]
    ldr r1, [r3]
    adds r1, #0xd2
    ldrb r2, [r1]
    adds r0, r4, #0
    orrs r0, r2
    strb r0, [r1]
    movs r2, #0
    ldr r0, [r3]
    adds r0, #0xd2
    ldrb r0, [r0]
    cmp r0, #0xf
    bne lbl_08071d50
    movs r2, #1
lbl_08071d50:
    movs r0, #1
    movs r1, #2
    movs r3, #1
    bl sub_08070e1c
lbl_08071d5a:
    ldr r0, lbl_08071db8 @ =0x0840dec4
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #1
    blt lbl_08071d7a
    cmp r0, #2
    ble lbl_08071d78
    cmp r0, #3
    bne lbl_08071d7a
    cmp r6, #4
    bne lbl_08071d7a
    ldr r0, lbl_08071dbc @ =gEquipment
    ldrb r0, [r0, #0x12]
    cmp r0, #1
    beq lbl_08071d7a
lbl_08071d78:
    movs r7, #0xff
lbl_08071d7a:
    movs r3, #0x11
    ldr r2, lbl_08071db4 @ =0x08754bc4
    cmp r7, #1
    beq lbl_08071d8a
    movs r3, #0
    cmp r7, #0
    bne lbl_08071d8a
    movs r3, #0x12
lbl_08071d8a:
    ldr r2, [r2]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071d9a
    movs r3, #0
lbl_08071d9a:
    movs r1, #0x8b
    lsls r1, r1, #3
    adds r0, r2, r1
    adds r1, r3, #0
    bl UpdateMenuOamDataID
    adds r0, r7, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08071db4: .4byte 0x08754bc4
lbl_08071db8: .4byte 0x0840dec4
lbl_08071dbc: .4byte gEquipment

    thumb_func_start sub_08071dc0
sub_08071dc0: @ 0x08071dc0
    push {r4, lr}
    ldr r0, lbl_08071dec @ =0x08754bc4
    ldr r1, [r0]
    movs r2, #0x89
    lsls r2, r2, #1
    adds r0, r1, r2
    ldrb r0, [r0]
    cmp r0, #6
    beq lbl_08071e70
    adds r0, r1, #0
    adds r0, #0xc1
    ldrb r2, [r0]
    ldr r0, lbl_08071df0 @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08071df4
    movs r3, #1
    rsbs r3, r3, #0
    b lbl_08071e26
    .align 2, 0
lbl_08071dec: .4byte 0x08754bc4
lbl_08071df0: .4byte gChangedInput
lbl_08071df4:
    movs r0, #0x80
    ands r0, r1
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    rsbs r0, r0, #0
    lsrs r3, r0, #0x1f
    cmp r3, #0
    bne lbl_08071e26
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bhi lbl_08071e18
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
    b lbl_08071e26
lbl_08071e18:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08071e22
    movs r3, #2
lbl_08071e22:
    cmp r3, #0
    beq lbl_08071e36
lbl_08071e26:
    ldr r0, lbl_08071e78 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xc1
    ldrb r1, [r0]
    adds r0, r3, #0
    bl sub_08071e7c
    adds r2, r0, #0
lbl_08071e36:
    ldr r4, lbl_08071e78 @ =0x08754bc4
    ldr r0, [r4]
    adds r1, r0, #0
    adds r1, #0xc1
    ldrb r0, [r1]
    cmp r0, r2
    beq lbl_08071e70
    strb r2, [r1]
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    bl sub_08071a3c
    ldr r0, [r4]
    adds r0, #0xc1
    ldrb r0, [r0]
    movs r1, #0
    bl sub_08071b2c
    ldr r0, [r4]
    movs r1, #0x84
    lsls r1, r1, #1
    adds r0, r0, r1
    movs r1, #6
    bl UpdateMenuOamDataID
    movs r0, #0xfb
    lsls r0, r0, #1
    bl SoundPlay
lbl_08071e70:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08071e78: .4byte 0x08754bc4

    thumb_func_start sub_08071e7c
sub_08071e7c: @ 0x08071e7c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x18
    asrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r4, r1, #0x18
    mov r8, r4
    cmp r5, #0
    beq lbl_08071f62
    cmp r5, #1
    ble lbl_08071f26
    cmp r4, #7
    bls lbl_08071ea8
    ldr r1, lbl_08071ea4 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xc3
    b lbl_08071eae
    .align 2, 0
lbl_08071ea4: .4byte 0x08754bc4
lbl_08071ea8:
    ldr r1, lbl_08071ed4 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0xc2
lbl_08071eae:
    strb r4, [r0]
    mov r0, r8
    cmp r0, #7
    bls lbl_08071edc
    ldr r0, [r1]
    adds r0, #0xc2
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #7
    movs r7, #1
    mov r0, r8
    cmp r0, #0xb
    bls lbl_08071ed8
    movs r4, #6
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
    .align 2, 0
lbl_08071ed4: .4byte 0x08754bc4
lbl_08071ed8:
    movs r4, #1
    b lbl_08071efa
lbl_08071edc:
    ldr r0, [r1]
    adds r0, #0xc3
    ldrb r4, [r0]
    cmp r4, #0
    bne lbl_08071f62
    movs r1, #0x11
    movs r7, #8
    mov r0, r8
    cmp r0, #5
    bls lbl_08071ef8
    movs r4, #0xc
    movs r5, #1
    rsbs r5, r5, #0
    b lbl_08071efc
lbl_08071ef8:
    movs r4, #8
lbl_08071efa:
    movs r5, #1
lbl_08071efc:
    adds r6, r4, #0
lbl_08071efe:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    bne lbl_08071f62
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f18
    adds r4, r1, #0
    b lbl_08071f1e
lbl_08071f18:
    cmp r4, r1
    ble lbl_08071f1e
    adds r4, r7, #0
lbl_08071f1e:
    cmp r4, r6
    bne lbl_08071efe
lbl_08071f22:
    mov r4, r8
    b lbl_08071f62
lbl_08071f26:
    cmp r4, #7
    bls lbl_08071f30
    movs r1, #0x11
    movs r7, #8
    b lbl_08071f34
lbl_08071f30:
    movs r1, #7
    movs r7, #1
lbl_08071f34:
    cmp r5, #1
    beq lbl_08071f3c
    movs r0, #1
    rsbs r0, r0, #0
lbl_08071f3c:
    adds r6, r4, #0
lbl_08071f3e:
    adds r4, r4, r5
    cmp r4, r7
    bge lbl_08071f48
    adds r4, r1, #0
    b lbl_08071f4e
lbl_08071f48:
    cmp r4, r1
    ble lbl_08071f4e
    adds r4, r7, #0
lbl_08071f4e:
    cmp r4, r6
    beq lbl_08071f22
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    str r1, [sp]
    bl sub_08071a8c
    ldr r1, [sp]
    cmp r0, #0
    beq lbl_08071f3e
lbl_08071f62:
    adds r0, r4, #0
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start easy_sleep_menu_subroutine
easy_sleep_menu_subroutine: @ 0x08071f70
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r7, #0
    ldr r1, lbl_08071f94 @ =0x08754bc4
    ldr r0, [r1]
    ldrb r0, [r0, #8]
    adds r2, r1, #0
    cmp r0, #5
    bls lbl_08071f88
    b lbl_08072110
lbl_08071f88:
    lsls r0, r0, #2
    ldr r1, lbl_08071f98 @ =lbl_08071f9c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08071f94: .4byte 0x08754bc4
lbl_08071f98: .4byte lbl_08071f9c
lbl_08071f9c: @ jump table
    .4byte lbl_08071fb4 @ case 0
    .4byte lbl_08072000 @ case 1
    .4byte lbl_08072068 @ case 2
    .4byte lbl_0807207e @ case 3
    .4byte lbl_08072094 @ case 4
    .4byte lbl_08072104 @ case 5
lbl_08071fb4:
    ldr r0, lbl_08071fcc @ =gChangedInput
    ldrh r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08071fd4
    ldr r0, lbl_08071fd0 @ =0x00000209
    bl SoundPlay
    movs r7, #2
    b lbl_08072114
    .align 2, 0
lbl_08071fcc: .4byte gChangedInput
lbl_08071fd0: .4byte 0x00000209
lbl_08071fd4:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08072058
    ldr r0, lbl_08071ff8 @ =0x00000207
    bl SoundPlay
    ldr r2, lbl_08071ffc @ =0x08754bc4
    ldr r1, [r2]
    movs r0, #1
    strb r0, [r1, #8]
    ldr r0, [r2]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0xd0
    strh r0, [r1]
    b lbl_08072110
    .align 2, 0
lbl_08071ff8: .4byte 0x00000207
lbl_08071ffc: .4byte 0x08754bc4
lbl_08072000:
    ldr r0, lbl_08072024 @ =gChangedInput
    ldrh r1, [r0]
    movs r4, #1
    ands r4, r1
    cmp r4, #0
    beq lbl_0807202c
    movs r0, #0x82
    lsls r0, r0, #2
    bl SoundPlay
    ldr r2, lbl_08072028 @ =0x08754bc4
    ldr r1, [r2]
    movs r3, #0
    movs r0, #2
    strb r0, [r1, #8]
    ldr r0, [r2]
    strh r3, [r0, #0xa]
    b lbl_08072110
    .align 2, 0
lbl_08072024: .4byte gChangedInput
lbl_08072028: .4byte 0x08754bc4
lbl_0807202c:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08072058
    ldr r0, lbl_08072050 @ =0x00000207
    bl SoundPlay
    ldr r1, lbl_08072054 @ =0x08754bc4
    ldr r0, [r1]
    strb r4, [r0, #8]
    ldr r0, [r1]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r0, r2
    movs r0, #0x84
    lsls r0, r0, #2
    strh r0, [r1]
    b lbl_08072110
    .align 2, 0
lbl_08072050: .4byte 0x00000207
lbl_08072054: .4byte 0x08754bc4
lbl_08072058:
    ldr r0, lbl_08072064 @ =0x00000302
    ands r0, r1
    cmp r0, #0
    beq lbl_08072110
    movs r7, #1
    b lbl_08072114
    .align 2, 0
lbl_08072064: .4byte 0x00000302
lbl_08072068:
    ldr r3, [r2]
    ldrh r0, [r3, #0xa]
    cmp r0, #0x1e
    bls lbl_08072110
    ldrb r0, [r3, #8]
    adds r0, #1
    movs r1, #0
    strb r0, [r3, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    b lbl_08072110
lbl_0807207e:
    ldr r2, [r2]
    adds r3, r2, #0
    adds r3, #0x5c
    ldrh r0, [r3]
    movs r1, #0x80
    eors r0, r1
    strh r0, [r3]
    ldrb r0, [r2, #8]
    adds r0, #1
    strb r0, [r2, #8]
    b lbl_08072110
lbl_08072094:
    ldr r1, lbl_080720f0 @ =0x04000132
    ldr r2, lbl_080720f4 @ =0x0000c304
    adds r0, r2, #0
    strh r0, [r1]
    ldr r6, lbl_080720f8 @ =0x04000208
    movs r0, #0
    mov sb, r0
    strh r0, [r6]
    ldr r5, lbl_080720fc @ =0x04000200
    ldrh r4, [r5]
    movs r1, #0xc0
    lsls r1, r1, #6
    adds r0, r1, #0
    strh r0, [r5]
    movs r2, #1
    mov r8, r2
    strh r2, [r6]
    bl SoundBias0
    svc #3
    bl SoundBias200
    mov r0, sb
    strh r0, [r6]
    strh r4, [r5]
    mov r1, r8
    strh r1, [r6]
    ldr r0, lbl_08072100 @ =0x08754bc4
    ldr r3, [r0]
    adds r2, r3, #0
    adds r2, #0x5c
    ldrh r0, [r2]
    movs r1, #0x80
    eors r0, r1
    strh r0, [r2]
    movs r2, #0x8d
    lsls r2, r2, #1
    adds r1, r3, r2
    movs r0, #0x84
    lsls r0, r0, #2
    strh r0, [r1]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    b lbl_08072110
    .align 2, 0
lbl_080720f0: .4byte 0x04000132
lbl_080720f4: .4byte 0x0000c304
lbl_080720f8: .4byte 0x04000208
lbl_080720fc: .4byte 0x04000200
lbl_08072100: .4byte 0x08754bc4
lbl_08072104:
    ldr r0, lbl_08072138 @ =gButtonInput
    ldrh r1, [r0]
    cmp r1, #0
    bne lbl_08072110
    ldr r0, [r2]
    strb r1, [r0, #8]
lbl_08072110:
    cmp r7, #0
    beq lbl_0807212a
lbl_08072114:
    ldr r2, lbl_0807213c @ =0x08754bc4
    ldr r0, [r2]
    movs r1, #0
    strb r1, [r0, #8]
    ldr r0, [r2]
    strh r1, [r0, #0xa]
    cmp r7, #1
    bne lbl_0807212a
    ldr r0, lbl_08072140 @ =0x00000206
    bl SoundPlay
lbl_0807212a:
    adds r0, r7, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08072138: .4byte gButtonInput
lbl_0807213c: .4byte 0x08754bc4
lbl_08072140: .4byte 0x00000206

    thumb_func_start sub_08072144
sub_08072144: @ 0x08072144
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    movs r7, #0xd
    ldrsb r7, [r4, r7]
    cmp r7, #0
    beq lbl_08072196
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #6]
    cmp r0, r1
    beq lbl_08072192
    movs r0, #0xa
    ldrsh r1, [r4, r0]
    ldrh r0, [r4, #0x10]
    muls r1, r0, r1
    ldrh r0, [r4, #0x12]
    muls r0, r1, r0
    lsls r0, r0, #8
    ldrh r1, [r4, #0xe]
    bl __divsi3
    adds r6, r0, #0
    ldrh r2, [r4, #2]
    cmp r6, #0
    bge lbl_08072176
    adds r0, #0xff
lbl_08072176:
    asrs r0, r0, #8
    movs r1, #0xd
    ldrsb r1, [r4, r1]
    muls r0, r1, r0
    adds r6, r2, r0
    cmp r7, #0
    ble lbl_0807218c
    ldrh r0, [r4, #6]
    cmp r0, r6
    bge lbl_08072196
    b lbl_08072192
lbl_0807218c:
    ldrh r0, [r4, #6]
    cmp r0, r6
    ble lbl_08072196
lbl_08072192:
    movs r0, #0
    strb r0, [r4, #0xd]
lbl_08072196:
    movs r7, #0xc
    ldrsb r7, [r4, r7]
    cmp r7, #0
    beq lbl_080721e4
    ldrh r0, [r4]
    ldrh r1, [r4, #4]
    cmp r0, r1
    beq lbl_080721e0
    movs r0, #8
    ldrsh r1, [r4, r0]
    ldrh r0, [r4, #0x10]
    muls r1, r0, r1
    ldrh r0, [r4, #0x12]
    muls r0, r1, r0
    lsls r0, r0, #8
    ldrh r1, [r4, #0xe]
    bl __divsi3
    adds r5, r0, #0
    ldrh r2, [r4]
    cmp r5, #0
    bge lbl_080721c4
    adds r0, #0xff
lbl_080721c4:
    asrs r0, r0, #8
    movs r1, #0xc
    ldrsb r1, [r4, r1]
    muls r0, r1, r0
    adds r5, r2, r0
    cmp r7, #0
    ble lbl_080721da
    ldrh r0, [r4, #4]
    cmp r0, r5
    bge lbl_080721e4
    b lbl_080721e0
lbl_080721da:
    ldrh r0, [r4, #4]
    cmp r0, r5
    ble lbl_080721e4
lbl_080721e0:
    movs r0, #0
    strb r0, [r4, #0xc]
lbl_080721e4:
    movs r0, #0xd
    ldrsb r0, [r4, r0]
    cmp r0, #0
    bne lbl_080721ee
    ldrh r6, [r4, #6]
lbl_080721ee:
    movs r0, #0xc
    ldrsb r0, [r4, r0]
    cmp r0, #0
    bne lbl_080721f8
    ldrh r5, [r4, #4]
lbl_080721f8:
    lsls r0, r5, #0x10
    orrs r0, r6
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start chozo_statue_hint_movement
chozo_statue_hint_movement: @ 0x08072204
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_08072220 @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0x47
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #6
    bls lbl_08072216
    b lbl_08072664
lbl_08072216:
    lsls r0, r0, #2
    ldr r1, lbl_08072224 @ =lbl_08072228
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08072220: .4byte 0x08754bc4
lbl_08072224: .4byte lbl_08072228
lbl_08072228: @ jump table
    .4byte lbl_08072664 @ case 0
    .4byte lbl_08072244 @ case 1
    .4byte lbl_080723f4 @ case 2
    .4byte lbl_08072414 @ case 3
    .4byte lbl_080725b0 @ case 4
    .4byte lbl_08072600 @ case 5
    .4byte lbl_0807262e @ case 6
lbl_08072244:
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r2, [r1]
    movs r0, #1
    orrs r0, r2
    strb r0, [r1]
    ldr r3, [r5]
    ldrb r0, [r3, #0x13]
    lsls r0, r0, #5
    adds r4, r3, #0
    adds r4, #0x8e
    strh r0, [r4]
    ldrb r0, [r3, #0x14]
    lsls r0, r0, #5
    adds r2, r3, #0
    adds r2, #0x8c
    strh r0, [r2]
    ldrb r0, [r3, #0x15]
    lsls r0, r0, #5
    adds r1, r3, #0
    adds r1, #0x92
    strh r0, [r1]
    ldrb r0, [r3, #0x16]
    lsls r0, r0, #5
    subs r1, #2
    strh r0, [r1]
    ldrh r1, [r2]
    movs r2, #0xea
    lsls r2, r2, #2
    adds r0, r3, r2
    strh r1, [r0]
    ldrh r1, [r4]
    ldr r4, lbl_080722cc @ =0x000003aa
    adds r0, r3, r4
    strh r1, [r0]
    ldr r2, lbl_080722d0 @ =0x0840df78
    adds r0, r3, #0
    adds r0, #0x40
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r2
    ldrb r1, [r0, #5]
    ldr r7, lbl_080722d4 @ =0x000003b2
    adds r0, r3, r7
    strb r1, [r0]
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0x92
    adds r1, r3, #0
    adds r1, #0x8e
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r2, r3, #0
    adds r2, #0x96
    strh r0, [r2]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_080722d8
    adds r1, r3, #0
    adds r1, #0x98
    movs r0, #0
    strb r0, [r1]
    b lbl_08072300
    .align 2, 0
lbl_080722cc: .4byte 0x000003aa
lbl_080722d0: .4byte 0x0840df78
lbl_080722d4: .4byte 0x000003b2
lbl_080722d8:
    movs r2, #1
    rsbs r2, r2, #0
    adds r1, r2, #0
    cmp r0, #0
    ble lbl_080722e4
    movs r1, #1
lbl_080722e4:
    adds r0, r3, #0
    adds r0, #0x99
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0x96
    adds r0, #0x99
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_08072300:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x90
    adds r1, r2, #0
    adds r1, #0x8c
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r1, r2, #0
    adds r1, #0x94
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072326
    adds r1, #4
    movs r0, #0
    strb r0, [r1]
    b lbl_0807234e
lbl_08072326:
    movs r4, #1
    rsbs r4, r4, #0
    adds r1, r4, #0
    cmp r0, #0
    ble lbl_08072332
    movs r1, #1
lbl_08072332:
    adds r0, r2, #0
    adds r0, #0x98
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0x94
    adds r0, #0x98
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r7, r0, #0
    muls r7, r1, r7
    adds r0, r7, #0
    strh r0, [r2]
lbl_0807234e:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x96
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r0, #0
    muls r3, r0, r3
    adds r0, r3, #0
    adds r1, #0x94
    movs r4, #0
    ldrsh r1, [r1, r4]
    adds r7, r1, #0
    muls r7, r1, r7
    adds r1, r7, #0
    adds r0, r0, r1
    lsls r0, r0, #2
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x12
    cmp r4, #0
    bne lbl_08072386
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x99
    strb r4, [r1]
    adds r0, #0x98
    strb r4, [r0]
lbl_08072386:
    ldr r0, [r5]
    mov ip, r0
    adds r0, #0x9a
    movs r3, #0
    movs r2, #0
    strh r4, [r0]
    mov r1, ip
    adds r1, #0x9c
    movs r0, #1
    strh r0, [r1]
    mov r0, ip
    adds r0, #0x9e
    strh r2, [r0]
    subs r0, #0x56
    strb r3, [r0]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bgt lbl_080723cc
    ldr r3, lbl_080723c8 @ =0x000003b3
    adds r2, r1, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    b lbl_080725ec
    .align 2, 0
lbl_080723c8: .4byte 0x000003b3
lbl_080723cc:
    adds r0, r1, #0
    adds r0, #0x41
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080723de
    adds r1, #0x47
    movs r0, #6
    strb r0, [r1]
    b lbl_08072664
lbl_080723de:
    ldr r4, lbl_080723f0 @ =0x000003b3
    adds r2, r1, r4
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    b lbl_080725ec
    .align 2, 0
lbl_080723f0: .4byte 0x000003b3
lbl_080723f4:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x3c
    bhi lbl_0807240c
    b lbl_08072664
lbl_0807240c:
    adds r1, #0x49
    movs r0, #1
    strb r0, [r1]
    b lbl_080725e4
lbl_08072414:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x92
    ldrh r1, [r0]
    ldr r7, lbl_08072470 @ =0x000003aa
    adds r0, r2, r7
    movs r3, #0
    ldrsh r0, [r0, r3]
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x99
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    adds r4, r1, #0
    muls r4, r0, r4
    adds r0, r2, #0
    adds r0, #0x90
    ldrh r1, [r0]
    subs r7, #2
    adds r0, r2, r7
    movs r3, #0
    ldrsh r0, [r0, r3]
    subs r1, r1, r0
    adds r0, r2, #0
    adds r0, #0x98
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    muls r1, r0, r1
    cmp r1, r4
    bge lbl_08072460
    adds r1, r4, #0
lbl_08072460:
    asrs r4, r1, #2
    cmp r4, #0x20
    bgt lbl_08072474
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #2
    b lbl_08072498
    .align 2, 0
lbl_08072470: .4byte 0x000003aa
lbl_08072474:
    cmp r4, #0x40
    bgt lbl_08072482
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #3
    b lbl_08072498
lbl_08072482:
    cmp r4, #0x60
    bgt lbl_08072490
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #4
    b lbl_08072498
lbl_08072490:
    adds r1, r2, #0
    adds r1, #0x9e
    ldrh r0, [r1]
    adds r0, #5
lbl_08072498:
    strh r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x48
    ldrb r1, [r0]
    movs r6, #7
    adds r0, r6, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0807253a
    lsrs r4, r1, #3
    movs r0, #3
    ands r4, r0
    adds r4, #1
    lsls r3, r4, #4
    adds r1, r2, r3
    movs r0, #0xea
    lsls r0, r0, #2
    adds r1, r1, r0
    adds r0, r2, r0
    ldm r0!, {r2, r4, r7}
    stm r1!, {r2, r4, r7}
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #7
    bgt lbl_080724fc
    adds r0, r2, r3
    ldr r4, lbl_080724f4 @ =0x000003b2
    adds r0, r0, r4
    strb r6, [r0]
    ldr r2, [r5]
    adds r2, r2, r3
    ldr r7, lbl_080724f8 @ =0x000003b3
    adds r2, r2, r7
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    b lbl_08072536
    .align 2, 0
lbl_080724f4: .4byte 0x000003b2
lbl_080724f8: .4byte 0x000003b3
lbl_080724fc:
    movs r1, #0xf
    cmp r0, #8
    bne lbl_08072504
    movs r1, #0xb
lbl_08072504:
    adds r0, r2, r3
    ldr r2, lbl_0807259c @ =0x000003b2
    adds r0, r0, r2
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, r0, r3
    movs r4, #0xec
    lsls r4, r4, #2
    adds r0, r0, r4
    movs r1, #3
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, r0, r3
    ldr r7, lbl_080725a0 @ =0x000003b1
    adds r0, r0, r7
    movs r1, #5
    strb r1, [r0]
    ldr r2, [r5]
    adds r2, r2, r3
    ldr r0, lbl_080725a4 @ =0x000003b3
    adds r2, r2, r0
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
lbl_08072536:
    orrs r0, r1
    strb r0, [r2]
lbl_0807253a:
    ldr r0, [r5]
    adds r0, #0x8c
    bl sub_08072144
    adds r4, r0, #0
    asrs r1, r4, #0x10
    ldr r0, lbl_080725a8 @ =0x0000ffff
    ands r4, r0
    ldr r2, [r5]
    movs r3, #0xea
    lsls r3, r3, #2
    adds r0, r2, r3
    movs r6, #0
    strh r1, [r0]
    ldr r7, lbl_080725ac @ =0x000003aa
    adds r0, r2, r7
    strh r4, [r0]
    movs r3, #0
    adds r0, r2, #0
    adds r0, #0x90
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0807256a
    movs r3, #1
lbl_0807256a:
    adds r1, r3, #0
    movs r3, #0
    adds r0, r2, #0
    adds r0, #0x92
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_0807257a
    movs r3, #1
lbl_0807257a:
    adds r4, r3, #0
    cmp r1, #0
    beq lbl_08072586
    adds r0, r2, #0
    adds r0, #0x98
    strb r6, [r0]
lbl_08072586:
    cmp r4, #0
    beq lbl_08072664
    ldr r0, [r5]
    adds r0, #0x99
    strb r6, [r0]
    cmp r1, #0
    beq lbl_08072664
    ldr r0, [r5]
    adds r0, #0x48
    strb r6, [r0]
    b lbl_080725ec
    .align 2, 0
lbl_0807259c: .4byte 0x000003b2
lbl_080725a0: .4byte 0x000003b1
lbl_080725a4: .4byte 0x000003b3
lbl_080725a8: .4byte 0x0000ffff
lbl_080725ac: .4byte 0x000003aa
lbl_080725b0:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x14
    bls lbl_08072664
    ldr r0, lbl_080725f8 @ =0x00000303
    adds r3, r3, r0
    ldrb r1, [r3]
    movs r2, #0x3f
    adds r0, r2, #0
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r3]
    ldr r0, [r5]
    ldr r1, lbl_080725fc @ =0x000003b3
    adds r0, r0, r1
    ldrb r1, [r0]
    ands r2, r1
    strb r2, [r0]
lbl_080725e4:
    ldr r0, [r5]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
lbl_080725ec:
    ldr r1, [r5]
    adds r1, #0x47
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08072664
    .align 2, 0
lbl_080725f8: .4byte 0x00000303
lbl_080725fc: .4byte 0x000003b3
lbl_08072600:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x48
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_08072664
    strb r2, [r1]
    ldr r0, [r5]
    adds r0, #0x47
    strb r2, [r0]
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r0, [r1]
    movs r2, #1
    eors r0, r2
    strb r0, [r1]
    b lbl_08072664
lbl_0807262e:
    ldr r1, [r5]
    adds r1, #0x48
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0x48
    ldrb r0, [r0]
    cmp r0, #0x3c
    bls lbl_08072664
    ldr r3, lbl_0807266c @ =0x000003b3
    adds r2, r2, r3
    ldrb r1, [r2]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
    ldr r0, [r5]
    adds r0, #0x48
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0x47
    movs r1, #2
    strb r1, [r0]
lbl_08072664:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807266c: .4byte 0x000003b3

    thumb_func_start chozo_statue_hint_scrolling
chozo_statue_hint_scrolling: @ 0x08072670
    push {r4, r5, r6, lr}
    ldr r1, lbl_0807268c @ =0x08754bc4
    ldr r0, [r1]
    adds r0, #0x49
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #4
    bls lbl_08072682
    b lbl_080728b0
lbl_08072682:
    lsls r0, r0, #2
    ldr r1, lbl_08072690 @ =lbl_08072694
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0807268c: .4byte 0x08754bc4
lbl_08072690: .4byte lbl_08072694
lbl_08072694: @ jump table
    .4byte lbl_080728b0 @ case 0
    .4byte lbl_080726a8 @ case 1
    .4byte lbl_080727e2 @ case 2
    .4byte lbl_08072806 @ case 3
    .4byte lbl_08072884 @ case 4
lbl_080726a8:
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r2, [r1]
    movs r0, #2
    orrs r0, r2
    strb r0, [r1]
    ldr r3, [r5]
    ldrb r1, [r3, #0x16]
    movs r0, #0xa
    subs r0, r0, r1
    lsls r0, r0, #3
    movs r2, #0x81
    lsls r2, r2, #2
    subs r0, r2, r0
    lsls r0, r0, #2
    adds r1, r3, #0
    adds r1, #0xa4
    strh r0, [r1]
    ldrb r1, [r3, #0x15]
    movs r0, #0xf
    subs r0, r0, r1
    lsls r0, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #2
    adds r4, r3, #0
    adds r4, #0xa6
    strh r2, [r4]
    ldr r0, lbl_0807270c @ =gBG3VOFS_NonGameplay
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xa0
    strh r1, [r0]
    ldr r0, lbl_08072710 @ =gBG3HOFS_NonGameplay
    ldrh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xa2
    strh r1, [r0]
    ldrh r0, [r4]
    subs r0, r0, r1
    adds r1, r3, #0
    adds r1, #0xaa
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072714
    adds r1, #2
    movs r0, #0
    strb r0, [r1]
    b lbl_0807273c
    .align 2, 0
lbl_0807270c: .4byte gBG3VOFS_NonGameplay
lbl_08072710: .4byte gBG3HOFS_NonGameplay
lbl_08072714:
    movs r2, #1
    rsbs r2, r2, #0
    adds r1, r2, #0
    cmp r0, #0
    ble lbl_08072720
    movs r1, #1
lbl_08072720:
    adds r0, r3, #0
    adds r0, #0xad
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xaa
    adds r0, #0xad
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_0807273c:
    ldr r2, [r5]
    adds r0, r2, #0
    adds r0, #0xa4
    adds r1, r2, #0
    adds r1, #0xa0
    ldrh r0, [r0]
    ldrh r1, [r1]
    subs r0, r0, r1
    adds r1, r2, #0
    adds r1, #0xa8
    strh r0, [r1]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x10
    cmp r0, #0
    bne lbl_08072762
    adds r1, #4
    movs r0, #0
    strb r0, [r1]
    b lbl_0807278a
lbl_08072762:
    movs r3, #1
    rsbs r3, r3, #0
    adds r1, r3, #0
    cmp r0, #0
    ble lbl_0807276e
    movs r1, #1
lbl_0807276e:
    adds r0, r2, #0
    adds r0, #0xac
    strb r1, [r0]
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xa8
    adds r0, #0xac
    movs r1, #0
    ldrsb r1, [r0, r1]
    ldrh r0, [r2]
    adds r3, r0, #0
    muls r3, r1, r3
    adds r0, r3, #0
    strh r0, [r2]
lbl_0807278a:
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xaa
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r0, #0
    muls r3, r0, r3
    adds r0, r3, #0
    adds r1, #0xa8
    movs r2, #0
    ldrsh r1, [r1, r2]
    adds r3, r1, #0
    muls r3, r1, r3
    adds r1, r3, #0
    adds r0, r0, r1
    lsls r0, r0, #2
    bl Sqrt
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x12
    cmp r4, #0
    bne lbl_080727c2
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0xad
    strb r4, [r1]
    adds r0, #0xac
    strb r4, [r0]
lbl_080727c2:
    ldr r3, [r5]
    adds r0, r3, #0
    adds r0, #0xae
    movs r2, #0
    strh r4, [r0]
    adds r1, r3, #0
    adds r1, #0xb0
    movs r0, #1
    strh r0, [r1]
    adds r0, r3, #0
    adds r0, #0xb2
    strh r2, [r0]
    subs r1, #0x67
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
lbl_080727e2:
    ldr r1, [r5]
    adds r1, #0x4a
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x4a
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_080728b0
    movs r0, #0
    strb r0, [r1]
    ldr r1, [r5]
    adds r1, #0x49
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
lbl_08072806:
    ldr r0, [r5]
    adds r2, r0, #0
    adds r2, #0xb2
    ldrh r1, [r2]
    adds r1, #4
    movs r6, #0
    strh r1, [r2]
    adds r0, #0xa0
    bl sub_08072144
    adds r4, r0, #0
    asrs r2, r4, #0x10
    ldr r0, lbl_08072878 @ =0x0000ffff
    ands r4, r0
    ldr r0, lbl_0807287c @ =gBG3VOFS_NonGameplay
    strh r2, [r0]
    ldr r0, lbl_08072880 @ =gBG3HOFS_NonGameplay
    strh r4, [r0]
    movs r3, #0
    ldr r1, [r5]
    adds r0, r1, #0
    adds r0, #0xa4
    ldrh r0, [r0]
    cmp r2, r0
    bne lbl_0807283a
    movs r3, #1
lbl_0807283a:
    adds r2, r3, #0
    movs r3, #0
    adds r0, r1, #0
    adds r0, #0xa6
    ldrh r0, [r0]
    cmp r4, r0
    bne lbl_0807284a
    movs r3, #1
lbl_0807284a:
    adds r4, r3, #0
    cmp r2, #0
    beq lbl_08072856
    adds r0, r1, #0
    adds r0, #0xac
    strb r6, [r0]
lbl_08072856:
    cmp r4, #0
    beq lbl_08072860
    ldr r0, [r5]
    adds r0, #0xad
    strb r6, [r0]
lbl_08072860:
    cmp r2, #0
    beq lbl_080728b0
    cmp r4, #0
    beq lbl_080728b0
    ldr r0, [r5]
    adds r0, #0x4a
    strb r6, [r0]
    ldr r1, [r5]
    adds r1, #0x49
    ldrb r0, [r1]
    adds r0, #1
    b lbl_080728ae
    .align 2, 0
lbl_08072878: .4byte 0x0000ffff
lbl_0807287c: .4byte gBG3VOFS_NonGameplay
lbl_08072880: .4byte gBG3HOFS_NonGameplay
lbl_08072884:
    ldr r1, [r5]
    adds r1, #0x4a
    ldrb r0, [r1]
    adds r0, #1
    movs r2, #0
    strb r0, [r1]
    ldr r0, [r5]
    adds r1, r0, #0
    adds r1, #0x4a
    ldrb r0, [r1]
    cmp r0, #0x14
    bls lbl_080728b0
    strb r2, [r1]
    ldr r0, [r5]
    adds r0, #0x49
    strb r2, [r0]
    ldr r1, [r5]
    adds r1, #0x46
    ldrb r0, [r1]
    movs r2, #2
    eors r0, r2
lbl_080728ae:
    strb r0, [r1]
lbl_080728b0:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start chozo_statue_hint_subroutine
chozo_statue_hint_subroutine: @ 0x080728b8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    bl chozo_statue_hint_movement
    bl chozo_statue_hint_scrolling
    ldr r0, lbl_080728e4 @ =0x08754bc4
    ldr r0, [r0]
    ldrb r0, [r0, #8]
    cmp r0, #9
    bls lbl_080728d8
    b lbl_08072afe
lbl_080728d8:
    lsls r0, r0, #2
    ldr r1, lbl_080728e8 @ =lbl_080728ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080728e4: .4byte 0x08754bc4
lbl_080728e8: .4byte lbl_080728ec
lbl_080728ec: @ jump table
    .4byte lbl_08072ab8 @ case 0
    .4byte lbl_08072914 @ case 1
    .4byte lbl_08072928 @ case 2
    .4byte lbl_0807294c @ case 3
    .4byte lbl_08072974 @ case 4
    .4byte lbl_080729a0 @ case 5
    .4byte lbl_080729e0 @ case 6
    .4byte lbl_08072a58 @ case 7
    .4byte lbl_08072ab8 @ case 8
    .4byte lbl_08072ad4 @ case 9
lbl_08072914:
    ldr r2, lbl_08072924 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x47
    movs r3, #0
    movs r1, #1
    strb r1, [r0]
    b lbl_080729ce
    .align 2, 0
lbl_08072924: .4byte 0x08754bc4
lbl_08072928:
    ldr r3, lbl_08072948 @ =0x08754bc4
    ldr r1, [r3]
    adds r0, r1, #0
    adds r0, #0x46
    ldrb r0, [r0]
    movs r2, #3
    ands r2, r0
    cmp r2, #0
    beq lbl_0807293c
    b lbl_08072afe
lbl_0807293c:
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r3]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072948: .4byte 0x08754bc4
lbl_0807294c:
    ldr r1, lbl_08072964 @ =0x08754bc4
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    blt lbl_08072968
    ldrb r0, [r2, #8]
    adds r0, #1
    b lbl_0807296a
    .align 2, 0
lbl_08072964: .4byte 0x08754bc4
lbl_08072968:
    movs r0, #8
lbl_0807296a:
    strb r0, [r2, #8]
    ldr r1, [r1]
    movs r0, #0
    strh r0, [r1, #0xa]
    b lbl_08072afe
lbl_08072974:
    ldr r5, lbl_0807299c @ =0x08754bc4
    ldr r3, [r5]
    ldrh r0, [r3, #0xa]
    cmp r0, #0x3c
    bhi lbl_08072980
    b lbl_08072afe
lbl_08072980:
    adds r4, r3, #0
    adds r4, #0x66
    ldrh r1, [r4]
    movs r0, #0x18
    movs r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldrb r0, [r3, #8]
    adds r0, #1
    strb r0, [r3, #8]
    ldr r0, [r5]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_0807299c: .4byte 0x08754bc4
lbl_080729a0:
    ldr r4, lbl_080729c4 @ =gWrittenToBLDALPHA_H
    ldrh r1, [r4]
    ldr r2, lbl_080729c8 @ =gWrittenToBLDALPHA_L
    ldrh r0, [r2]
    adds r3, r1, r0
    cmp r3, #0
    beq lbl_080729cc
    cmp r1, #0
    beq lbl_080729b6
    subs r0, r1, #1
    strh r0, [r4]
lbl_080729b6:
    ldrh r0, [r2]
    cmp r0, #0
    bne lbl_080729be
    b lbl_08072afe
lbl_080729be:
    subs r0, #1
    strh r0, [r2]
    b lbl_08072afe
    .align 2, 0
lbl_080729c4: .4byte gWrittenToBLDALPHA_H
lbl_080729c8: .4byte gWrittenToBLDALPHA_L
lbl_080729cc:
    ldr r2, lbl_080729dc @ =0x08754bc4
lbl_080729ce:
    ldr r1, [r2]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r2]
    strh r3, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_080729dc: .4byte 0x08754bc4
lbl_080729e0:
    ldr r4, lbl_08072a4c @ =0x08754bc4
    ldr r1, [r4]
    adds r1, #0x41
    ldrb r0, [r1]
    adds r0, #1
    movs r5, #0
    strb r0, [r1]
    ldr r1, [r4]
    adds r0, r1, #0
    adds r0, #0x42
    ldrb r0, [r0]
    strb r0, [r1, #0x12]
    ldr r0, [r4]
    movs r2, #0x82
    lsls r2, r2, #1
    adds r1, r0, r2
    ldrb r0, [r0, #0x12]
    lsls r0, r0, #0xb
    ldr r1, [r1]
    adds r1, r1, r0
    ldr r2, lbl_08072a50 @ =0x0600e000
    movs r3, #0x80
    lsls r3, r3, #4
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #1
    bl chozo_statue_hint_determine_path
    movs r0, #1
    bl sub_0806db58
    ldr r1, [r4]
    movs r2, #0x85
    lsls r2, r2, #3
    adds r0, r1, r2
    ldr r2, lbl_08072a54 @ =0x0840d180
    ldrb r1, [r1, #0x12]
    adds r1, r1, r2
    ldrb r1, [r1]
    bl UpdateMenuOamDataID
    bl sub_0806889c
    ldr r1, [r4]
    ldrb r0, [r1, #8]
    adds r0, #1
    strb r0, [r1, #8]
    ldr r0, [r4]
    strh r5, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072a4c: .4byte 0x08754bc4
lbl_08072a50: .4byte 0x0600e000
lbl_08072a54: .4byte 0x0840d180
lbl_08072a58:
    ldr r0, lbl_08072a8c @ =0x08754bc4
    mov ip, r0
    ldr r3, [r0]
    adds r6, r3, #0
    adds r6, #0x68
    ldrh r4, [r6]
    ldr r7, lbl_08072a90 @ =gWrittenToBLDALPHA_H
    ldrh r2, [r7]
    lsls r0, r2, #8
    ldr r5, lbl_08072a94 @ =gWrittenToBLDALPHA_L
    ldrh r1, [r5]
    orrs r0, r1
    cmp r4, r0
    beq lbl_08072a98
    lsrs r0, r4, #8
    cmp r0, r2
    bls lbl_08072a7e
    adds r0, r2, #1
    strh r0, [r7]
lbl_08072a7e:
    ldrh r1, [r5]
    ldrb r0, [r6]
    cmp r0, r1
    bls lbl_08072afe
    adds r0, r1, #1
    strh r0, [r5]
    b lbl_08072afe
    .align 2, 0
lbl_08072a8c: .4byte 0x08754bc4
lbl_08072a90: .4byte gWrittenToBLDALPHA_H
lbl_08072a94: .4byte gWrittenToBLDALPHA_L
lbl_08072a98:
    adds r4, r3, #0
    adds r4, #0x66
    ldrh r1, [r4]
    ldr r0, lbl_08072ab4 @ =0x0000ffe7
    ands r0, r1
    movs r1, #0
    movs r2, #0
    strh r0, [r4]
    strb r1, [r3, #8]
    mov r1, ip
    ldr r0, [r1]
    strh r2, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072ab4: .4byte 0x0000ffe7
lbl_08072ab8:
    ldr r3, lbl_08072ad0 @ =0x08754bc4
    ldr r2, [r3]
    ldrh r0, [r2, #0xa]
    cmp r0, #0x28
    bls lbl_08072afe
    ldrb r0, [r2, #8]
    adds r0, #1
    movs r1, #0
    strb r0, [r2, #8]
    ldr r0, [r3]
    strh r1, [r0, #0xa]
    b lbl_08072afe
    .align 2, 0
lbl_08072ad0: .4byte 0x08754bc4
lbl_08072ad4:
    ldr r0, lbl_08072ae4 @ =gDemoState
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08072ae8
    movs r2, #1
    mov r8, r2
    b lbl_08072afe
    .align 2, 0
lbl_08072ae4: .4byte gDemoState
lbl_08072ae8:
    ldr r2, lbl_08072b0c @ =gChangedInput
    ldr r0, lbl_08072b10 @ =gButtonAssignments
    ldrh r0, [r0, #4]
    movs r1, #1
    orrs r0, r1
    ldrh r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08072afe
    movs r0, #1
    mov r8, r0
lbl_08072afe:
    mov r0, r8
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08072b0c: .4byte gChangedInput
lbl_08072b10: .4byte gButtonAssignments

    thumb_func_start chozo_statue_hint_change_area
chozo_statue_hint_change_area: @ 0x08072b14
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    adds r6, r1, #0
    ldr r7, lbl_08072b70 @ =0x08345934
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    mov ip, r0
    ldr r0, lbl_08072b74 @ =0x08754bc4
    ldr r0, [r0]
    mov r5, ip
    ldrb r1, [r5]
    ldrb r5, [r0, #0x12]
    cmp r1, r5
    bne lbl_08072b78
    mov r5, ip
    ldrb r1, [r5, #4]
    adds r0, #0x42
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #2]
    strb r0, [r4]
    ldrb r0, [r4]
    lsls r0, r0, #5
    strh r0, [r2, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #3]
    strb r0, [r6]
    ldrb r0, [r6]
    adds r0, #4
    lsls r0, r0, #5
    strh r0, [r2]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072bae
    movs r0, #2
    b lbl_08072bb0
    .align 2, 0
lbl_08072b70: .4byte 0x08345934
lbl_08072b74: .4byte 0x08754bc4
lbl_08072b78:
    adds r0, #0x42
    strb r1, [r0]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #6]
    strb r0, [r4]
    ldrb r0, [r4]
    lsls r0, r0, #5
    strh r0, [r2, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r0, [r0, #7]
    strb r0, [r6]
    ldrb r0, [r6]
    subs r0, #3
    lsls r0, r0, #5
    strh r0, [r2]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072bae
    movs r0, #2
    b lbl_08072bb0
lbl_08072bae:
    movs r0, #3
lbl_08072bb0:
    strb r0, [r2, #0xa]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start chozo_statue_hint_determine_path
chozo_statue_hint_determine_path: @ 0x08072bb8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x14
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r1, lbl_08072bf4 @ =0x0840d038
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    add r2, sp, #4
    movs r3, #0x10
    bl DMATransfer
    ldr r0, lbl_08072bf8 @ =0x08754bc4
    ldr r0, [r0]
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08072bfc
    add r2, sp, #4
    ldrb r1, [r2, #0xb]
    movs r0, #4
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r2, #0xb]
    b lbl_08072c06
    .align 2, 0
lbl_08072bf4: .4byte 0x0840d038
lbl_08072bf8: .4byte 0x08754bc4
lbl_08072bfc:
    add r0, sp, #4
    ldrb r1, [r0, #0xb]
    movs r2, #3
    orrs r1, r2
    strb r1, [r0, #0xb]
lbl_08072c06:
    cmp r7, #0
    bne lbl_08072c80
    ldr r0, lbl_08072c74 @ =0x08754bc4
    ldr r0, [r0]
    movs r1, #0xba
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #0xb
lbl_08072c18:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c18
    ldr r0, lbl_08072c74 @ =0x08754bc4
    ldr r0, [r0]
    movs r1, #0xea
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #4
lbl_08072c3c:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c3c
    ldr r2, lbl_08072c74 @ =0x08754bc4
    ldr r0, [r2]
    adds r0, #0x41
    movs r1, #0
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x40
    movs r1, #0xff
    strb r1, [r0]
    ldr r0, [r2]
    adds r0, #0x42
    movs r1, #1
    rsbs r1, r1, #0
    strb r1, [r0]
    bl check_activated_targets
    b lbl_08072cc8
    .align 2, 0
lbl_08072c74: .4byte 0x08754bc4
lbl_08072c78:
    adds r0, r2, #0
    adds r0, #0x40
    strb r5, [r0]
    b lbl_08072d42
lbl_08072c80:
    ldr r0, lbl_08072d9c @ =0x08754bc4
    ldr r0, [r0]
    movs r1, #0xba
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #0xb
lbl_08072c8e:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072c8e
    ldr r0, lbl_08072d9c @ =0x08754bc4
    ldr r0, [r0]
    movs r1, #0xea
    lsls r1, r1, #2
    adds r4, r0, r1
    movs r6, #0x20
    movs r5, #4
lbl_08072cb2:
    str r6, [sp]
    movs r0, #3
    add r1, sp, #4
    adds r2, r4, #0
    movs r3, #0x10
    bl DMATransfer
    subs r5, #1
    adds r4, #0x10
    cmp r5, #0
    bge lbl_08072cb2
lbl_08072cc8:
    ldr r2, lbl_08072d9c @ =0x08754bc4
    ldr r3, [r2]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r4, r3, r0
    ldr r6, lbl_08072da0 @ =0x0840e02c
    ldrh r1, [r3]
    movs r0, #0x10
    ands r0, r1
    mov r8, r2
    cmp r0, #0
    bne lbl_08072ce2
    b lbl_08072e96
lbl_08072ce2:
    movs r1, #0xbe
    lsls r1, r1, #2
    adds r1, r1, r3
    mov sb, r1
    subs r6, #0xb4
    mov ip, r6
    cmp r7, #0
    bne lbl_08072d42
    movs r5, #0
    movs r0, #0xbe
    lsls r0, r0, #2
    adds r0, r0, r3
    mov sb, r0
    adds r2, r3, #0
    adds r0, r2, #0
    adds r0, #0x44
    ldrh r7, [r0]
    movs r3, #0
lbl_08072d06:
    adds r0, r7, #0
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08072d3a
    mov r1, ip
    adds r6, r3, r1
    ldrb r0, [r6]
    ldrb r1, [r2, #0x12]
    cmp r0, r1
    bne lbl_08072d3a
    ldrb r0, [r6, #3]
    ldrb r1, [r2, #0x14]
    cmp r0, r1
    bhi lbl_08072d3a
    ldrb r0, [r6, #4]
    cmp r1, r0
    bhi lbl_08072d3a
    ldrb r0, [r6, #1]
    ldrb r1, [r2, #0x13]
    cmp r0, r1
    bhi lbl_08072d3a
    ldrb r6, [r6, #2]
    cmp r1, r6
    bls lbl_08072c78
lbl_08072d3a:
    adds r3, #0xc
    adds r5, #1
    cmp r5, #0xf
    ble lbl_08072d06
lbl_08072d42:
    ldr r1, lbl_08072d9c @ =0x08754bc4
    mov r8, r1
    ldr r2, [r1]
    adds r0, r2, #0
    adds r0, #0x40
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    mov r1, ip
    adds r6, r0, r1
    ldrb r3, [r6]
    ldrb r0, [r6, #6]
    cmp r3, r0
    bne lbl_08072da4
    ldrb r0, [r2, #0x13]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r2, #0x14]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #5]
    strb r0, [r4, #0xa]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #7]
    strb r0, [r1, #0x15]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #8]
    strb r0, [r1, #0x16]
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r1, #0x15]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r1, #0x16]
    lsls r0, r0, #5
    strh r0, [r4]
    adds r4, #0x10
    b lbl_08072fda
    .align 2, 0
lbl_08072d9c: .4byte 0x08754bc4
lbl_08072da0: .4byte 0x0840e02c
lbl_08072da4:
    ldr r1, lbl_08072de4 @ =0x087603f0
    ldr r0, lbl_08072de8 @ =gCurrentArea
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r7, [r0]
    ldrb r1, [r6, #6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r7, r7, r0
    ldrb r0, [r2, #0x12]
    cmp r0, r3
    bne lbl_08072dec
    ldrb r0, [r2, #0x13]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r2, #0x14]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #5]
    strb r0, [r4, #0xa]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x15
    adds r1, #0x16
    adds r2, r4, #0
    adds r3, r7, #0
    b lbl_08072e8e
    .align 2, 0
lbl_08072de4: .4byte 0x087603f0
lbl_08072de8: .4byte gCurrentArea
lbl_08072dec:
    adds r0, r2, #0
    adds r0, #0x42
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, r1
    bne lbl_08072e50
    adds r0, r2, #0
    adds r0, #0x41
    ldrb r0, [r0]
    subs r0, #1
    lsls r5, r0, #1
    adds r0, r2, #0
    adds r0, #0x13
    adds r1, r2, #0
    adds r1, #0x14
    adds r3, r7, r5
    adds r2, r4, #0
    bl chozo_statue_hint_change_area
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #7]
    strb r0, [r1, #0x15]
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r6, #8]
    strb r0, [r1, #0x16]
    ldrb r0, [r6, #7]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r6, #8]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    adds r4, #0x10
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x42
    movs r1, #0xff
    strb r1, [r0]
    b lbl_08072fda
lbl_08072e50:
    adds r0, r2, #0
    adds r0, #0x41
    ldrb r0, [r0]
    subs r0, #1
    lsls r5, r0, #1
    adds r0, r2, #0
    adds r0, #0x13
    adds r1, r2, #0
    adds r1, #0x14
    adds r3, r7, r5
    adds r2, r4, #0
    bl chozo_statue_hint_change_area
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    mov r4, sb
    mov r0, r8
    ldr r1, [r0]
    adds r0, r1, #0
    adds r0, #0x41
    ldrb r0, [r0]
    lsls r5, r0, #1
    adds r0, r1, #0
    adds r0, #0x15
    adds r1, #0x16
    adds r3, r7, r5
    adds r2, r4, #0
lbl_08072e8e:
    bl chozo_statue_hint_change_area
    adds r4, #0x10
    b lbl_08072fda
lbl_08072e96:
    adds r2, r3, #0
    adds r2, #0x44
    ldrh r0, [r2]
    cmp r0, #0
    bne lbl_08072ea2
    b lbl_08072fda
lbl_08072ea2:
    ldr r3, lbl_08072f70 @ =gCurrentArea
    ldrb r0, [r3]
    cmp r0, #5
    bls lbl_08072eac
    b lbl_08072fda
lbl_08072eac:
    ldr r1, lbl_08072f74 @ =0x087603f0
    ldrb r0, [r3]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r7, [r0]
    cmp r7, #0
    bne lbl_08072ebc
    b lbl_08072fda
lbl_08072ebc:
    movs r5, #0
    ldrh r0, [r2]
    movs r1, #1
    ands r0, r1
    subs r6, #0xb4
    mov ip, r6
    cmp r0, #0
    beq lbl_08072ede
    ldr r6, lbl_08072f78 @ =0x0840e038
    ldrb r0, [r6]
    movs r3, #0
    cmp r0, #0
    beq lbl_08072f04
lbl_08072ed6:
    adds r0, r3, r6
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_08072f04
lbl_08072ede:
    adds r5, #1
    cmp r5, #0xe
    bgt lbl_08072f04
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08072ede
    ldr r6, lbl_08072f78 @ =0x0840e038
    lsls r0, r5, #1
    adds r1, r0, r6
    ldrb r1, [r1]
    adds r3, r0, #0
    cmp r1, #0
    bne lbl_08072ed6
lbl_08072f04:
    lsls r0, r5, #1
    adds r0, r0, r5
    lsls r0, r0, #2
    mov r1, ip
    adds r6, r0, r1
    ldrb r0, [r6, #6]
    cmp r0, #2
    bhi lbl_08072fda
    adds r1, r0, #0
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r7, r7, r0
    ldr r5, lbl_08072f7c @ =0x08345934
    mov ip, r5
    ldr r0, lbl_08072f80 @ =0x08754bc4
    mov r8, r0
    adds r3, r7, #0
    movs r1, #0x3f
    mov sb, r1
    movs r6, #0x40
lbl_08072f2e:
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    mov r1, ip
    adds r2, r0, r1
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r2]
    ldrb r1, [r1, #0x12]
    cmp r0, r1
    bne lbl_08072f8a
    ldrb r0, [r2, #2]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #3]
    adds r0, #4
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    mov r0, sb
    ands r0, r1
    orrs r0, r6
    strb r0, [r4, #0xb]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072f84
    movs r0, #2
    b lbl_08072f86
    .align 2, 0
lbl_08072f70: .4byte gCurrentArea
lbl_08072f74: .4byte 0x087603f0
lbl_08072f78: .4byte 0x0840e038
lbl_08072f7c: .4byte 0x08345934
lbl_08072f80: .4byte 0x08754bc4
lbl_08072f84:
    movs r0, #3
lbl_08072f86:
    strb r0, [r4, #0xa]
    adds r4, #0x10
lbl_08072f8a:
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    mov r1, ip
    adds r2, r0, r1
    mov r0, r8
    ldr r1, [r0]
    ldrb r0, [r2, #4]
    ldrb r1, [r1, #0x12]
    cmp r0, r1
    bne lbl_08072fd2
    ldrb r0, [r2, #6]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r0, [r0, #7]
    subs r0, #3
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    mov r0, sb
    ands r0, r1
    orrs r0, r6
    strb r0, [r4, #0xb]
    movs r0, #1
    ldrsb r0, [r3, r0]
    cmp r0, #0
    bge lbl_08072fcc
    movs r0, #2
    b lbl_08072fce
lbl_08072fcc:
    movs r0, #3
lbl_08072fce:
    strb r0, [r4, #0xa]
    adds r4, #0x10
lbl_08072fd2:
    adds r3, #2
    adds r0, r7, #5
    cmp r3, r0
    ble lbl_08072f2e
lbl_08072fda:
    movs r5, #0
    ldr r1, lbl_08073048 @ =0x08754bc4
    mov r8, r1
    movs r7, #0
lbl_08072fe2:
    mov r0, r8
    ldr r3, [r0]
    adds r0, r3, #0
    adds r0, #0x40
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r5, r0
    beq lbl_0807302e
    adds r0, r3, #0
    adds r0, #0x44
    ldrh r0, [r0]
    asrs r0, r5
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0807302e
    ldr r0, lbl_0807304c @ =0x0840df78
    adds r6, r7, r0
    ldrb r0, [r6, #6]
    ldrb r3, [r3, #0x12]
    cmp r0, r3
    bne lbl_0807302e
    ldrb r0, [r6, #9]
    strb r0, [r4, #0xa]
    ldrb r0, [r6, #7]
    lsls r0, r0, #5
    strh r0, [r4, #2]
    ldrb r0, [r6, #8]
    lsls r0, r0, #5
    strh r0, [r4]
    ldrb r1, [r4, #0xb]
    movs r0, #0x3f
    ands r0, r1
    movs r1, #0x40
    orrs r0, r1
    strb r0, [r4, #0xb]
    adds r4, #0x10
lbl_0807302e:
    adds r7, #0xc
    adds r5, #1
    cmp r5, #0xf
    ble lbl_08072fe2
    bl draw_boss_flames
    add sp, #0x14
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073048: .4byte 0x08754bc4
lbl_0807304c: .4byte 0x0840df78

    thumb_func_start chozo_statue_hint_check_events_flags
chozo_statue_hint_check_events_flags: @ 0x08073050
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    movs r4, #1
    rsbs r4, r4, #0
    ldr r0, lbl_08073080 @ =0x0840e058
    adds r0, r5, r0
    ldrb r1, [r0]
    movs r0, #3
    bl EventFunction
    cmp r0, #0
    beq lbl_080730c4
    ldr r3, lbl_08073084 @ =0x0840e038
    lsls r2, r5, #1
    adds r0, r2, r3
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0807308c
    ldr r1, lbl_08073088 @ =gEquipment
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r2, [r1, #0xc]
    b lbl_08073098
    .align 2, 0
lbl_08073080: .4byte 0x0840e058
lbl_08073084: .4byte 0x0840e038
lbl_08073088: .4byte gEquipment
lbl_0807308c:
    cmp r0, #1
    bne lbl_080730a8
    ldr r1, lbl_080730a4 @ =gEquipment
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r2, [r1, #0xe]
lbl_08073098:
    ldrb r1, [r0]
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    b lbl_080730bc
    .align 2, 0
lbl_080730a4: .4byte gEquipment
lbl_080730a8:
    cmp r0, #2
    bne lbl_080730bc
    adds r0, r3, #1
    adds r0, r2, r0
    ldrb r1, [r0]
    movs r0, #3
    bl EventFunction
    lsls r0, r0, #0x18
    asrs r4, r0, #0x18
lbl_080730bc:
    cmp r4, #0
    blt lbl_080730c4
    movs r0, #1
    eors r4, r0
lbl_080730c4:
    adds r0, r4, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start check_activated_targets
check_activated_targets: @ 0x080730cc
    push {r4, lr}
    ldr r0, lbl_08073104 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0x44
    movs r1, #0
    strh r1, [r0]
    movs r4, #0
lbl_080730da:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    bl chozo_statue_hint_check_events_flags
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_080730f8
    ldr r0, lbl_08073104 @ =0x08754bc4
    ldr r2, [r0]
    adds r2, #0x44
    movs r0, #1
    lsls r0, r4
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
lbl_080730f8:
    adds r4, #1
    cmp r4, #0xf
    ble lbl_080730da
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073104: .4byte 0x08754bc4

    thumb_func_start check_non_explored_area_has_hint
check_non_explored_area_has_hint: @ 0x08073108
    push {r4, r5, lr}
    ldr r0, lbl_08073148 @ =0x08754bc4
    ldr r0, [r0]
    adds r0, #0xb9
    movs r1, #0
    strb r1, [r0]
    movs r4, #0
    ldr r5, lbl_0807314c @ =0x0840df78
lbl_08073118:
    lsls r0, r4, #0x18
    lsrs r0, r0, #0x18
    bl chozo_statue_hint_check_events_flags
    lsls r0, r0, #0x18
    cmp r0, #0
    ble lbl_08073138
    ldr r0, lbl_08073148 @ =0x08754bc4
    ldr r2, [r0]
    adds r2, #0xb9
    movs r0, #1
    ldrb r1, [r5, #6]
    lsls r0, r1
    ldrb r1, [r2]
    orrs r0, r1
    strb r0, [r2]
lbl_08073138:
    adds r5, #0xc
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08073118
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073148: .4byte 0x08754bc4
lbl_0807314c: .4byte 0x0840df78

    thumb_func_start draw_boss_flames
draw_boss_flames: @ 0x08073150
    push {r4, r5, lr}
    sub sp, #4
    ldr r4, lbl_080731c4 @ =0x08754bc4
    ldr r2, [r4]
    adds r2, #0xec
    movs r0, #0x20
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x18
    bl BitFill
    ldr r1, [r4]
    ldrb r0, [r1, #0x12]
    adds r5, r4, #0
    cmp r0, #0
    bne lbl_0807323e
    adds r0, r1, #0
    adds r0, #0x44
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080731d6
    movs r1, #0
lbl_08073184:
    ldr r2, [r5]
    lsls r4, r1, #4
    adds r0, r2, r4
    ldr r3, lbl_080731c8 @ =0x000002f2
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xa
    bne lbl_080731d0
    adds r0, r2, #0
    adds r0, #0xef
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0xf1
    movs r1, #1
    strb r1, [r0]
    ldr r3, [r5]
    adds r2, r3, r4
    ldr r4, lbl_080731cc @ =0x000002ea
    adds r0, r2, r4
    ldrh r1, [r0]
    subs r1, #8
    strh r1, [r0]
    adds r0, r3, #0
    adds r0, #0xf4
    strh r1, [r0]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrh r0, [r2]
    adds r3, #0xf6
    strh r0, [r3]
    b lbl_080731d6
    .align 2, 0
lbl_080731c4: .4byte 0x08754bc4
lbl_080731c8: .4byte 0x000002f2
lbl_080731cc: .4byte 0x000002ea
lbl_080731d0:
    adds r1, #1
    cmp r1, #0xb
    ble lbl_08073184
lbl_080731d6:
    ldr r0, [r5]
    adds r0, #0x44
    ldrh r1, [r0]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0807323e
    movs r1, #0
lbl_080731e8:
    ldr r2, [r5]
    lsls r4, r1, #4
    adds r0, r2, r4
    ldr r3, lbl_08073230 @ =0x000002f2
    adds r0, r0, r3
    ldrb r0, [r0]
    cmp r0, #0xe
    bne lbl_08073238
    adds r0, r2, #0
    adds r0, #0xfb
    strb r1, [r0]
    ldr r0, [r5]
    adds r0, #0xfd
    movs r1, #1
    strb r1, [r0]
    ldr r3, [r5]
    adds r2, r3, r4
    ldr r4, lbl_08073234 @ =0x000002ea
    adds r0, r2, r4
    ldrh r1, [r0]
    adds r1, #8
    strh r1, [r0]
    movs r4, #0x80
    lsls r4, r4, #1
    adds r0, r3, r4
    strh r1, [r0]
    movs r0, #0xba
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrh r0, [r2]
    movs r2, #0x81
    lsls r2, r2, #1
    adds r1, r3, r2
    strh r0, [r1]
    b lbl_0807323e
    .align 2, 0
lbl_08073230: .4byte 0x000002f2
lbl_08073234: .4byte 0x000002ea
lbl_08073238:
    adds r1, #1
    cmp r1, #0xb
    ble lbl_080731e8
lbl_0807323e:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08073248
sub_08073248: @ 0x08073248
    push {lr}
    adds r2, r0, #0
    ldrb r0, [r2, #2]
    cmp r0, #0
    beq lbl_08073292
    movs r0, #5
    ldrsb r0, [r2, r0]
    ldrh r3, [r2]
    adds r1, r0, r3
    strh r1, [r2]
    ldrb r3, [r2, #5]
    cmp r0, #0
    ble lbl_0807326e
    lsls r0, r1, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x3e
    bls lbl_08073278
    movs r0, #0xff
    b lbl_08073276
lbl_0807326e:
    lsls r0, r1, #0x10
    cmp r0, #0
    bne lbl_08073278
    movs r0, #1
lbl_08073276:
    strb r0, [r2, #5]
lbl_08073278:
    ldr r0, lbl_08073298 @ =0x08754bc4
    ldr r1, [r0]
    ldrb r0, [r2, #3]
    lsls r0, r0, #4
    adds r1, r1, r0
    ldrh r0, [r2]
    lsrs r0, r0, #2
    ldrh r2, [r2, #0xa]
    adds r0, r0, r2
    movs r2, #0xba
    lsls r2, r2, #2
    adds r1, r1, r2
    strh r0, [r1]
lbl_08073292:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073298: .4byte 0x08754bc4

    thumb_func_start SramRead_All
SramRead_All: @ 0x0807329c
    push {r4, r5, lr}
    movs r4, #3
    ldr r5, lbl_080732b8 @ =gSramCorruptFlag
lbl_080732a2:
    cmp r4, #0
    beq lbl_080732b2
    bl sub_08074304
    ldrb r0, [r5]
    subs r4, #1
    cmp r0, #0
    bne lbl_080732a2
lbl_080732b2:
    movs r4, #3
    b lbl_080732c2
    .align 2, 0
lbl_080732b8: .4byte gSramCorruptFlag
lbl_080732bc:
    subs r4, #1
    cmp r4, #0
    beq lbl_080732d2
lbl_080732c2:
    movs r0, #0xe
    bl sub_08000c48
    movs r0, #0x10
    bl sub_08000c48
    cmp r0, #0
    bne lbl_080732bc
lbl_080732d2:
    bl sub_08073394
    bl sub_080743a4
    bl sub_08074a7c
    bl sub_08075010
    bl sub_08074da4
    cmp r0, #0
    beq lbl_080732f4
    ldr r1, lbl_080732fc @ =gLanguage
    movs r0, #2
    strb r0, [r1]
    bl SramWrite_Language
lbl_080732f4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080732fc: .4byte gLanguage

    thumb_func_start sub_08073300
sub_08073300: @ 0x08073300
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073388 @ =0x08754bc8
    ldr r4, [r2]
    movs r0, #0x30
    strb r0, [r4, #8]
    movs r0, #0x31
    strb r0, [r4, #9]
    ldrh r0, [r4, #0xa]
    adds r0, #1
    strh r0, [r4, #0xa]
    ldr r1, lbl_0807338c @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1]
    strh r0, [r4, #0xc]
    ldrb r0, [r1, #4]
    strb r0, [r4, #0xe]
    movs r0, #2
    strb r0, [r4, #0xf]
    movs r0, #0x34
    strb r0, [r4, #0x10]
    ldrb r0, [r1, #5]
    strb r0, [r4, #0x11]
    ldrb r0, [r1, #6]
    strb r0, [r4, #0x12]
    ldrb r0, [r1, #7]
    strb r0, [r4, #0x13]
    ldrh r0, [r1, #2]
    strh r0, [r4, #0x14]
    ldr r0, [r1, #8]
    str r0, [r4, #0x18]
    movs r3, #0
    adds r6, r2, #0
    adds r2, r4, #0
    adds r2, #0x1c
    ldr r5, lbl_08073390 @ =0x08411468
lbl_08073344:
    adds r0, r2, r3
    adds r1, r3, r5
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073344
    movs r0, #0
    str r0, [r4]
    subs r0, #1
    str r0, [r4, #4]
    ldr r2, [r6]
    movs r1, #0
    movs r3, #3
lbl_08073360:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073360
    str r1, [r4]
    mvns r0, r1
    str r0, [r4, #4]
    movs r0, #0
    bl sub_08000c48
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073388: .4byte 0x08754bc8
lbl_0807338c: .4byte gFileScreenOptionsUnlocked
lbl_08073390: .4byte 0x08411468

    thumb_func_start sub_08073394
sub_08073394: @ 0x08073394
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #8
    movs r0, #0
    bl sub_080734e8
    adds r6, r0, #0
    movs r0, #1
    bl sub_080734e8
    mov r8, r0
    movs r0, #2
    bl sub_080734e8
    adds r7, r0, #0
    cmp r6, #0
    beq lbl_08073470
    add r0, sp, #4
    ldr r1, lbl_08073404 @ =0x0000ffff
    adds r5, r1, #0
    strh r5, [r0]
    ldr r1, lbl_08073408 @ =0x040000d4
    str r0, [r1]
    ldr r3, lbl_0807340c @ =0x08754bc8
    mov sb, r3
    ldr r2, [r3]
    str r2, [r1, #4]
    ldr r4, lbl_08073410 @ =0x81000020
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    cmp r7, #0
    beq lbl_08073432
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    ldr r3, lbl_08073414 @ =0x00006d40
    adds r0, r2, r3
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    adds r3, r2, #0
    mov r0, r8
    cmp r0, #0
    beq lbl_08073418
    add r0, sp, #4
    strh r5, [r0]
    str r0, [r1]
    adds r0, r3, #0
    adds r0, #0x40
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_080734a4
    .align 2, 0
lbl_08073404: .4byte 0x0000ffff
lbl_08073408: .4byte 0x040000d4
lbl_0807340c: .4byte 0x08754bc8
lbl_08073410: .4byte 0x81000020
lbl_08073414: .4byte 0x00006d40
lbl_08073418:
    adds r1, r2, #0
    adds r1, #0x40
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r6, #0
    movs r0, #0
    bl sub_08000c48
    b lbl_080734a4
lbl_08073432:
    ldr r3, lbl_0807346c @ =0x00006d40
    adds r1, r2, r3
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r6, #0
    movs r0, #0
    bl sub_08000c48
    mov r0, r8
    cmp r0, #0
    beq lbl_080734a4
    mov r3, sb
    ldr r1, [r3]
    adds r2, r1, #0
    adds r2, #0x40
    str r4, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #1
    bl sub_08000c48
    b lbl_080734a4
    .align 2, 0
lbl_0807346c: .4byte 0x00006d40
lbl_08073470:
    ldr r4, lbl_080734b0 @ =0x08754bc8
    ldr r1, [r4]
    adds r2, r1, #0
    adds r2, #0x40
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #1
    bl sub_08000c48
    cmp r7, #0
    beq lbl_080734a4
    ldr r1, [r4]
    ldr r0, lbl_080734b4 @ =0x00006d40
    adds r2, r1, r0
    str r5, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    movs r0, #2
    bl sub_08000c48
lbl_080734a4:
    cmp r6, #0
    bne lbl_080734b8
    bl sub_08073584
    b lbl_080734d0
    .align 2, 0
lbl_080734b0: .4byte 0x08754bc8
lbl_080734b4: .4byte 0x00006d40
lbl_080734b8:
    bl EraseSram
    ldr r1, lbl_080734e0 @ =0x0841147c
    ldr r2, lbl_080734e4 @ =gFileScreenOptionsUnlocked
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0xc
    bl DMATransfer
    bl sub_08073300
lbl_080734d0:
    add sp, #8
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080734e0: .4byte 0x0841147c
lbl_080734e4: .4byte gFileScreenOptionsUnlocked

    thumb_func_start sub_080734e8
sub_080734e8: @ 0x080734e8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r4, #0
    cmp r0, #2
    bne lbl_08073508
    ldr r0, lbl_08073500 @ =0x08754bc8
    ldr r0, [r0]
    ldr r1, lbl_08073504 @ =0x00006d40
    adds r0, r0, r1
    b lbl_0807351c
    .align 2, 0
lbl_08073500: .4byte 0x08754bc8
lbl_08073504: .4byte 0x00006d40
lbl_08073508:
    cmp r0, #1
    bne lbl_08073518
    ldr r0, lbl_08073514 @ =0x08754bc8
    ldr r0, [r0]
    adds r0, #0x40
    b lbl_0807351c
    .align 2, 0
lbl_08073514: .4byte 0x08754bc8
lbl_08073518:
    ldr r0, lbl_0807357c @ =0x08754bc8
    ldr r0, [r0]
lbl_0807351c:
    movs r2, #0
    adds r1, r0, #0
    ldr r7, [r1]
    adds r5, r1, #0
    adds r5, #0x1c
    ldr r0, [r1, #4]
    mov ip, r0
    movs r3, #3
lbl_0807352c:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_0807352c
    cmp r7, r2
    beq lbl_0807354a
    movs r0, #1
    orrs r4, r0
lbl_0807354a:
    movs r3, #0
    adds r2, r5, #0
    ldr r6, lbl_08073580 @ =0x08411468
    movs r5, #2
lbl_08073552:
    adds r0, r2, r3
    adds r1, r3, r6
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08073560
    orrs r4, r5
lbl_08073560:
    adds r3, #1
    cmp r3, #0x13
    ble lbl_08073552
    mov r1, ip
    mvns r0, r1
    cmp r7, r0
    beq lbl_08073572
    movs r0, #4
    orrs r4, r0
lbl_08073572:
    adds r0, r4, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0807357c: .4byte 0x08754bc8
lbl_08073580: .4byte 0x08411468

    thumb_func_start sub_08073584
sub_08073584: @ 0x08073584
    ldr r0, lbl_080735a8 @ =0x08754bc8
    ldr r1, [r0]
    ldr r2, lbl_080735ac @ =gFileScreenOptionsUnlocked
    ldrh r0, [r1, #0xc]
    strh r0, [r2]
    ldrb r0, [r1, #0xe]
    strb r0, [r2, #4]
    ldrb r0, [r1, #0x11]
    strb r0, [r2, #5]
    ldrb r0, [r1, #0x12]
    strb r0, [r2, #6]
    ldrb r0, [r1, #0x13]
    strb r0, [r2, #7]
    ldrh r0, [r1, #0x14]
    strh r0, [r2, #2]
    ldr r0, [r1, #0x18]
    str r0, [r2, #8]
    bx lr
    .align 2, 0
lbl_080735a8: .4byte 0x08754bc8
lbl_080735ac: .4byte gFileScreenOptionsUnlocked

    thumb_func_start SramProcessIntroSave
SramProcessIntroSave: @ 0x080735b0
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_080735d8 @ =gDisableSoftreset
    ldrb r0, [r1]
    ldr r2, lbl_080735dc @ =gSramOperationStage
    cmp r0, #0
    bne lbl_080735c4
    strb r0, [r2]
    movs r0, #1
    strb r0, [r1]
lbl_080735c4:
    ldrb r0, [r2]
    cmp r0, #4
    bls lbl_080735cc
    b lbl_080736bc
lbl_080735cc:
    lsls r0, r0, #2
    ldr r1, lbl_080735e0 @ =lbl_080735e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080735d8: .4byte gDisableSoftreset
lbl_080735dc: .4byte gSramOperationStage
lbl_080735e0: .4byte lbl_080735e4
lbl_080735e4: @ jump table
    .4byte lbl_080735f8 @ case 0
    .4byte lbl_08073658 @ case 1
    .4byte lbl_08073668 @ case 2
    .4byte lbl_08073674 @ case 3
    .4byte lbl_080736bc @ case 4
lbl_080735f8:
    ldr r5, lbl_08073648 @ =gGameCompletion
    movs r3, #1
    strb r3, [r5, #1]
    ldr r4, lbl_0807364c @ =0x03000c24
    ldr r2, lbl_08073650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    strb r3, [r0, #0x12]
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r4
    ldrb r0, [r0, #0x11]
    strb r0, [r5]
    ldr r3, lbl_08073654 @ =0x08754bc8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r3]
    adds r2, r2, r0
    movs r3, #0xc0
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    bl BitFill
    b lbl_080736a2
    .align 2, 0
lbl_08073648: .4byte gGameCompletion
lbl_0807364c: .4byte 0x03000c24
lbl_08073650: .4byte gMostRecentSaveFile
lbl_08073654: .4byte 0x08754bc8
lbl_08073658:
    bl sub_080736d8
    ldr r1, lbl_08073664 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    b lbl_080736a2
    .align 2, 0
lbl_08073664: .4byte gUnk_3000c20
lbl_08073668:
    movs r0, #0
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_080736c4
    b lbl_080736a2
lbl_08073674:
    ldr r2, lbl_080736ac @ =0x08754bc8
    ldr r0, lbl_080736b0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080736b4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_080736a2:
    ldr r1, lbl_080736b8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080736c4
    .align 2, 0
lbl_080736ac: .4byte 0x08754bc8
lbl_080736b0: .4byte gMostRecentSaveFile
lbl_080736b4: .4byte 0x000036e0
lbl_080736b8: .4byte gSramOperationStage
lbl_080736bc:
    ldr r1, lbl_080736d4 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r2]
lbl_080736c4:
    ldr r0, lbl_080736d4 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080736d4: .4byte gDisableSoftreset

    thumb_func_start sub_080736d8
sub_080736d8: @ 0x080736d8
    push {r4, lr}
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_080737ac @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_080737b0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r1, lbl_080737b4 @ =gGameCompletion
    ldrb r0, [r1, #1]
    strb r0, [r4, #0x19]
    ldrb r0, [r1]
    strb r0, [r4, #0x18]
    ldr r0, lbl_080737b8 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_080737bc @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3e
    strb r0, [r1]
    ldr r0, lbl_080737c0 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r4, #0x1a]
    ldr r2, lbl_080737c4 @ =0x03000154
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_0807373e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_0807373e
    movs r1, #0x94
    lsls r1, r1, #2
    adds r0, r4, r1
    ldr r1, lbl_080737c8 @ =0x08411430
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_080737a4 @ =0x08754bc8
    ldr r0, lbl_080737a8 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073772:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073772
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080737a4: .4byte 0x08754bc8
lbl_080737a8: .4byte gMostRecentSaveFile
lbl_080737ac: .4byte 0x08411410
lbl_080737b0: .4byte 0x08411420
lbl_080737b4: .4byte gGameCompletion
lbl_080737b8: .4byte gDifficulty
lbl_080737bc: .4byte gTimeAttackFlag
lbl_080737c0: .4byte gLanguage
lbl_080737c4: .4byte 0x03000154
lbl_080737c8: .4byte 0x08411430

    thumb_func_start SramProcessEndingSave
SramProcessEndingSave: @ 0x080737cc
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_080737e8 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_080737de
    b lbl_080738e0
lbl_080737de:
    lsls r0, r1, #2
    ldr r1, lbl_080737ec @ =lbl_080737f0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080737e8: .4byte gSramOperationStage
lbl_080737ec: .4byte lbl_080737f0
lbl_080737f0: @ jump table
    .4byte lbl_08073808 @ case 0
    .4byte lbl_0807381c @ case 1
    .4byte lbl_08073828 @ case 2
    .4byte lbl_08073868 @ case 3
    .4byte lbl_08073898 @ case 4
    .4byte lbl_080738e0 @ case 5
lbl_08073808:
    ldr r1, lbl_08073818 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_080738e6
    .align 2, 0
lbl_08073818: .4byte gUnk_3000c20
lbl_0807381c:
    movs r0, #2
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_080738e6
    b lbl_080738c6
lbl_08073828:
    movs r2, #1
    ldr r0, lbl_08073858 @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073838
    movs r2, #8
lbl_08073838:
    ldr r1, lbl_0807385c @ =gGameCompletion
    ldr r0, lbl_08073860 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl check_set_new_best_completion_time
    bl sub_080739e8
    ldr r0, lbl_08073864 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_080738c6
    .align 2, 0
lbl_08073858: .4byte gLanguage
lbl_0807385c: .4byte gGameCompletion
lbl_08073860: .4byte gDifficulty
lbl_08073864: .4byte gUnk_3000c20
lbl_08073868:
    movs r0, #0
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_080738e6
    ldr r2, lbl_0807388c @ =0x03000c24
    ldr r0, lbl_08073890 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073894 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_080738c6
    .align 2, 0
lbl_0807388c: .4byte 0x03000c24
lbl_08073890: .4byte gMostRecentSaveFile
lbl_08073894: .4byte gGameCompletion
lbl_08073898:
    ldr r2, lbl_080738d0 @ =0x08754bc8
    ldr r0, lbl_080738d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_080738d8 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_080738c6:
    ldr r1, lbl_080738dc @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080738e6
    .align 2, 0
lbl_080738d0: .4byte 0x08754bc8
lbl_080738d4: .4byte gMostRecentSaveFile
lbl_080738d8: .4byte 0x000036e0
lbl_080738dc: .4byte gSramOperationStage
lbl_080738e0:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_080738e6:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start check_set_new_best_completion_time
check_set_new_best_completion_time: @ 0x080738f0
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080739cc @ =0x083459a0
    mov r8, r0
    ldrb r4, [r0, #0x1c]
    ldr r7, lbl_080739d0 @ =gEquipment
    ldrh r0, [r7]
    ldr r2, lbl_080739d4 @ =0x083459c4
    ldr r1, lbl_080739d8 @ =gDifficulty
    ldrb r1, [r1]
    mov sb, r1
    lsls r1, r1, #2
    adds r6, r1, r2
    ldrb r1, [r6]
    bl __divsi3
    eors r0, r4
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    mov r2, r8
    ldrb r4, [r2, #0x1d]
    ldrh r0, [r7, #2]
    ldrb r1, [r6, #1]
    bl __divsi3
    cmp r4, r0
    beq lbl_08073930
    movs r0, #2
    orrs r5, r0
lbl_08073930:
    ldrb r0, [r7, #4]
    ldrb r1, [r6, #2]
    bl __udivsi3
    mov r3, r8
    ldrb r1, [r3, #0x1e]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073948
    movs r0, #4
    orrs r5, r0
lbl_08073948:
    ldrb r0, [r7, #5]
    ldrb r1, [r6, #3]
    bl __udivsi3
    mov r2, r8
    ldrb r1, [r2, #0x1f]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r1, r0
    beq lbl_08073960
    movs r0, #8
    orrs r5, r0
lbl_08073960:
    movs r0, #0
    cmp r5, #0
    bne lbl_08073968
    movs r0, #6
lbl_08073968:
    adds r5, r0, #0
    ldr r0, lbl_080739dc @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_08073978
    adds r5, #3
lbl_08073978:
    add r5, sb
    ldr r1, lbl_080739e0 @ =0x03000154
    lsls r0, r5, #2
    adds r4, r0, r1
    ldrb r0, [r4]
    lsls r2, r0, #3
    subs r2, r2, r0
    lsls r2, r2, #5
    adds r2, r2, r0
    lsls r2, r2, #4
    ldrb r1, [r4, #1]
    lsls r0, r1, #4
    subs r0, r0, r1
    lsls r0, r0, #2
    adds r2, r2, r0
    ldrb r3, [r4, #2]
    adds r2, r2, r3
    ldr r5, lbl_080739e4 @ =gInGameTimer
    ldrb r0, [r5]
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #5
    adds r1, r1, r0
    lsls r1, r1, #4
    ldrb r3, [r5, #1]
    lsls r0, r3, #4
    subs r0, r0, r3
    lsls r0, r0, #2
    adds r1, r1, r0
    ldrb r0, [r5, #2]
    adds r1, r1, r0
    cmp r2, r1
    ble lbl_080739be
    ldr r0, [r5]
    str r0, [r4]
lbl_080739be:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080739cc: .4byte 0x083459a0
lbl_080739d0: .4byte gEquipment
lbl_080739d4: .4byte 0x083459c4
lbl_080739d8: .4byte gDifficulty
lbl_080739dc: .4byte gLanguage
lbl_080739e0: .4byte 0x03000154
lbl_080739e4: .4byte gInGameTimer

    thumb_func_start sub_080739e8
sub_080739e8: @ 0x080739e8
    push {r4, r5, r6, lr}
    ldr r2, lbl_08073a74 @ =0x08754bc8
    ldr r3, lbl_08073a78 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073a7c @ =gGameCompletion
    ldrb r0, [r0]
    strb r0, [r4, #0x18]
    adds r6, r2, #0
    adds r5, r3, #0
    ldr r2, lbl_08073a80 @ =0x03000154
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    movs r3, #0xb
lbl_08073a1e:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a1e
    movs r0, #0
    ldrsb r0, [r5, r0]
    lsls r1, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #4
    adds r1, r1, r0
    lsls r1, r1, #5
    adds r1, #0x80
    ldr r0, [r6]
    adds r2, r0, r1
    movs r1, #0
    movs r3, #0x90
lbl_08073a40:
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    ldm r2!, {r0}
    adds r1, r1, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073a40
    str r1, [r4, #0x10]
    mvns r0, r1
    str r0, [r4, #0x14]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073a74: .4byte 0x08754bc8
lbl_08073a78: .4byte gMostRecentSaveFile
lbl_08073a7c: .4byte gGameCompletion
lbl_08073a80: .4byte 0x03000154

    thumb_func_start sub_08073a84
sub_08073a84: @ 0x08073a84
    push {r4, r5, lr}
    sub sp, #4
    movs r5, #0
    ldr r0, lbl_08073aa0 @ =gSramOperationStage
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #5
    bls lbl_08073a96
    b lbl_08073b94
lbl_08073a96:
    lsls r0, r1, #2
    ldr r1, lbl_08073aa4 @ =lbl_08073aa8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073aa0: .4byte gSramOperationStage
lbl_08073aa4: .4byte lbl_08073aa8
lbl_08073aa8: @ jump table
    .4byte lbl_08073ac0 @ case 0
    .4byte lbl_08073ad4 @ case 1
    .4byte lbl_08073ae0 @ case 2
    .4byte lbl_08073b1c @ case 3
    .4byte lbl_08073b4c @ case 4
    .4byte lbl_08073b94 @ case 5
lbl_08073ac0:
    ldr r1, lbl_08073ad0 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    b lbl_08073b9a
    .align 2, 0
lbl_08073ad0: .4byte gUnk_3000c20
lbl_08073ad4:
    movs r0, #2
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08073b9a
    b lbl_08073b7a
lbl_08073ae0:
    movs r2, #1
    ldr r0, lbl_08073b0c @ =gLanguage
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_08073af0
    movs r2, #8
lbl_08073af0:
    ldr r1, lbl_08073b10 @ =gGameCompletion
    ldr r0, lbl_08073b14 @ =gDifficulty
    ldrb r0, [r0]
    lsls r2, r0
    ldrb r0, [r1]
    orrs r2, r0
    movs r4, #0
    strb r2, [r1]
    bl sub_080739e8
    ldr r0, lbl_08073b18 @ =gUnk_3000c20
    strb r4, [r0]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b0c: .4byte gLanguage
lbl_08073b10: .4byte gGameCompletion
lbl_08073b14: .4byte gDifficulty
lbl_08073b18: .4byte gUnk_3000c20
lbl_08073b1c:
    movs r0, #0
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08073b9a
    ldr r2, lbl_08073b40 @ =0x03000c24
    ldr r0, lbl_08073b44 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldr r1, lbl_08073b48 @ =gGameCompletion
    ldrb r1, [r1]
    strb r1, [r0, #0x11]
    b lbl_08073b7a
    .align 2, 0
lbl_08073b40: .4byte 0x03000c24
lbl_08073b44: .4byte gMostRecentSaveFile
lbl_08073b48: .4byte gGameCompletion
lbl_08073b4c:
    ldr r2, lbl_08073b84 @ =0x08754bc8
    ldr r0, lbl_08073b88 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073b8c @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
lbl_08073b7a:
    ldr r1, lbl_08073b90 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08073b9a
    .align 2, 0
lbl_08073b84: .4byte 0x08754bc8
lbl_08073b88: .4byte gMostRecentSaveFile
lbl_08073b8c: .4byte 0x000036e0
lbl_08073b90: .4byte gSramOperationStage
lbl_08073b94:
    movs r0, #0
    strb r0, [r2]
    movs r5, #1
lbl_08073b9a:
    adds r0, r5, #0
    add sp, #4
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start SramSaveFile
SramSaveFile: @ 0x08073ba4
    push {lr}
    sub sp, #4
    ldr r1, lbl_08073bd4 @ =gDisableSoftreset
    ldrb r2, [r1]
    ldr r3, lbl_08073bd8 @ =gSramOperationStage
    cmp r2, #0
    bne lbl_08073bc0
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_08073bdc @ =gHasSaved
    strb r0, [r1]
    strb r2, [r3]
    ldr r0, lbl_08073be0 @ =gUnk_3000c20
    strb r2, [r0]
lbl_08073bc0:
    ldrb r0, [r3]
    cmp r0, #5
    bls lbl_08073bc8
    b lbl_08073ccc
lbl_08073bc8:
    lsls r0, r0, #2
    ldr r1, lbl_08073be4 @ =lbl_08073be8
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08073bd4: .4byte gDisableSoftreset
lbl_08073bd8: .4byte gSramOperationStage
lbl_08073bdc: .4byte gHasSaved
lbl_08073be0: .4byte gUnk_3000c20
lbl_08073be4: .4byte lbl_08073be8
lbl_08073be8: @ jump table
    .4byte lbl_08073c00 @ case 0
    .4byte lbl_08073c18 @ case 1
    .4byte lbl_08073c34 @ case 2
    .4byte lbl_08073c50 @ case 3
    .4byte lbl_08073c84 @ case 4
    .4byte lbl_08073ccc @ case 5
lbl_08073c00:
    movs r0, #4
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r1, lbl_08073c14 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c14: .4byte gSramOperationStage
lbl_08073c18:
    bl write_sram_arrays
    ldr r1, lbl_08073c2c @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c30 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c2c: .4byte gUnk_3000c20
lbl_08073c30: .4byte gSramOperationStage
lbl_08073c34:
    bl write_sram
    ldr r1, lbl_08073c48 @ =gUnk_3000c20
    movs r0, #0
    strb r0, [r1]
    ldr r1, lbl_08073c4c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c48: .4byte gUnk_3000c20
lbl_08073c4c: .4byte gSramOperationStage
lbl_08073c50:
    movs r0, #0
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08073cd2
    ldr r2, lbl_08073c78 @ =0x03000c24
    ldr r0, lbl_08073c7c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    movs r1, #1
    strb r1, [r0]
    ldr r1, lbl_08073c80 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073c78: .4byte 0x03000c24
lbl_08073c7c: .4byte gMostRecentSaveFile
lbl_08073c80: .4byte gSramOperationStage
lbl_08073c84:
    ldr r2, lbl_08073cbc @ =0x08754bc8
    ldr r0, lbl_08073cc0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r2]
    adds r1, r2, r1
    ldr r3, lbl_08073cc4 @ =0x000036e0
    adds r0, r0, r3
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_08073cc8 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08073cd0
    .align 2, 0
lbl_08073cbc: .4byte 0x08754bc8
lbl_08073cc0: .4byte gMostRecentSaveFile
lbl_08073cc4: .4byte 0x000036e0
lbl_08073cc8: .4byte gSramOperationStage
lbl_08073ccc:
    ldr r1, lbl_08073ce0 @ =gDisableSoftreset
    movs r0, #0
lbl_08073cd0:
    strb r0, [r1]
lbl_08073cd2:
    ldr r0, lbl_08073ce0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r1}
    bx r1
    .align 2, 0
lbl_08073ce0: .4byte gDisableSoftreset

    thumb_func_start write_sram
write_sram: @ 0x08073ce4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r3, lbl_08073f80 @ =gMusicInfo
    ldrh r1, [r3, #0x1c]
    ldr r0, lbl_08073f84 @ =0xffff0000
    ands r0, r5
    orrs r0, r1
    ldrh r1, [r3, #0x1e]
    lsls r1, r1, #0x10
    ldr r2, lbl_08073f88 @ =0x0000ffff
    ands r0, r2
    adds r5, r0, #0
    orrs r5, r1
    adds r0, r3, #0
    adds r0, #0x20
    ldrb r1, [r0]
    ldr r0, lbl_08073f8c @ =0xffffff00
    ands r0, r6
    orrs r0, r1
    adds r3, #0x21
    ldrb r1, [r3]
    lsls r1, r1, #8
    ldr r2, lbl_08073f90 @ =0xffff00ff
    ands r0, r2
    adds r6, r0, #0
    orrs r6, r1
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08073f9c @ =0x08411410
    adds r0, r4, #0
    movs r2, #0x10
    bl write_string
    adds r0, r4, #0
    adds r0, #0x4f
    ldr r1, lbl_08073fa0 @ =0x08411420
    movs r2, #0x10
    bl write_string
    movs r0, #0
    str r0, [r4, #0x10]
    subs r0, #1
    str r0, [r4, #0x14]
    ldr r0, lbl_08073fa4 @ =gGameCompletion
    ldr r0, [r0]
    str r0, [r4, #0x18]
    ldr r0, lbl_08073fa8 @ =gHasSaved
    ldrb r0, [r0]
    strb r0, [r4, #0x1c]
    ldr r0, lbl_08073fac @ =gCurrentArea
    ldrb r0, [r0]
    strb r0, [r4, #0x1d]
    ldr r0, lbl_08073fb0 @ =gCurrentRoom
    ldrb r0, [r0]
    strb r0, [r4, #0x1e]
    ldr r0, lbl_08073fb4 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #0x1f]
    ldr r0, lbl_08073fb8 @ =gMinimapX
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x20
    strb r1, [r0]
    ldr r0, lbl_08073fbc @ =gMinimapY
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x21
    strb r0, [r1]
    ldr r0, lbl_08073fc0 @ =gCamera
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r0, lbl_08073fc4 @ =gBG0XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2c]
    ldr r0, lbl_08073fc8 @ =gBG0YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x2e]
    ldr r0, lbl_08073fcc @ =gBG1XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x30]
    ldr r0, lbl_08073fd0 @ =gBG1YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x32]
    ldr r0, lbl_08073fd4 @ =gBG2XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x34]
    ldr r0, lbl_08073fd8 @ =gBG2YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x36]
    ldr r0, lbl_08073fdc @ =gBG3XPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x38]
    ldr r0, lbl_08073fe0 @ =gBG3YPosition
    ldrh r0, [r0]
    strh r0, [r4, #0x3a]
    ldr r0, lbl_08073fe4 @ =gDifficulty
    ldrb r1, [r0]
    adds r0, r4, #0
    adds r0, #0x3c
    strb r1, [r0]
    ldr r0, lbl_08073fe8 @ =gUseMotherShipDoors
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x3d
    strb r0, [r1]
    ldr r0, lbl_08073fec @ =gTimeAttackFlag
    ldrb r0, [r0]
    adds r1, #1
    strb r0, [r1]
    movs r3, #0
    adds r2, r4, #0
    adds r2, #0x3f
    ldr r7, lbl_08073ff0 @ =gNumberOfNeverReformBlocks
lbl_08073de4:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073de4
    movs r3, #0
    ldr r0, lbl_08073ff4 @ =gSamusData
    mov sl, r0
    movs r2, #0x60
    adds r2, r2, r4
    mov ip, r2
    movs r7, #0x80
    adds r7, r7, r4
    mov r8, r7
    movs r0, #0x88
    adds r0, r0, r4
    mov sb, r0
    adds r2, r4, #0
    adds r2, #0x47
    ldr r7, lbl_08073ff8 @ =gNumberOfItemsCollected
lbl_08073e10:
    adds r0, r2, r3
    adds r1, r3, r7
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, #7
    ble lbl_08073e10
    mov r1, ip
    mov r0, sl
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r7, lbl_08073ffc @ =gSamusWeaponInfo
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r2, r8
    str r0, [r2]
    str r1, [r2, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sb
    ldr r1, lbl_08074000 @ =gSamusEcho
    bl memcpy
    movs r3, #0xca
    lsls r3, r3, #1
    adds r2, r4, r3
    ldr r0, lbl_08074004 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r7, #0xce
    lsls r7, r7, #1
    adds r1, r4, r7
    ldr r0, lbl_08074008 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    movs r7, #0xd8
    lsls r7, r7, #1
    adds r2, r4, r7
    ldr r0, lbl_0807400c @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r0, #0xdc
    lsls r0, r0, #1
    adds r1, r4, r0
    ldr r0, lbl_08074010 @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xe2
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r3, #0xe8
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r7, #0xee
    lsls r7, r7, #1
    adds r1, r4, r7
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r2, #0xf4
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldr r0, lbl_08074014 @ =gPreventMovementTimer
    ldrh r1, [r0]
    movs r3, #0xfa
    lsls r3, r3, #1
    adds r0, r4, r3
    strh r1, [r0]
    ldr r0, lbl_08074018 @ =gDisableDrawingSamusAndScrolling
    ldrb r0, [r0]
    movs r7, #0xfb
    lsls r7, r7, #1
    adds r1, r4, r7
    strb r0, [r1]
    ldr r0, lbl_0807401c @ =gAlarmTimer
    ldrh r1, [r0]
    movs r2, #0xfc
    lsls r2, r2, #1
    adds r0, r4, r2
    strh r1, [r0]
    adds r3, #8
    adds r1, r4, r3
    ldr r0, lbl_08074020 @ =gInGameTimer
    ldr r0, [r0]
    str r0, [r1]
    ldr r2, lbl_08074024 @ =0x03000154
    adds r7, #0xa
    adds r1, r4, r7
    movs r3, #0xb
lbl_08073ee0:
    ldm r2!, {r0}
    stm r1!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ee0
    ldr r1, lbl_08074028 @ =0x08411430
    ldr r7, lbl_0807402c @ =gInGameTimerAtBosses
    movs r0, #0x8c
    lsls r0, r0, #2
    adds r2, r4, r0
    movs r3, #4
lbl_08073ef6:
    ldm r7!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073ef6
    movs r2, #0x91
    lsls r2, r2, #2
    adds r0, r4, r2
    str r5, [r0]
    str r6, [r0, #4]
    ldr r5, lbl_08074030 @ =gInGameCutscenesTriggered
    movs r3, #0x93
    lsls r3, r3, #2
    adds r2, r4, r3
    movs r3, #0
lbl_08073f14:
    ldm r5!, {r0}
    stm r2!, {r0}
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f14
    movs r7, #0x94
    lsls r7, r7, #2
    adds r0, r4, r7
    movs r2, #0x10
    bl write_string
    ldr r2, lbl_08073f94 @ =0x08754bc8
    ldr r0, lbl_08073f98 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r1, r1, r0
    movs r2, #0
    movs r3, #0x90
lbl_08073f46:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08073f46
    str r2, [r4, #0x10]
    mvns r0, r2
    str r0, [r4, #0x14]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08073f80: .4byte gMusicInfo
lbl_08073f84: .4byte 0xffff0000
lbl_08073f88: .4byte 0x0000ffff
lbl_08073f8c: .4byte 0xffffff00
lbl_08073f90: .4byte 0xffff00ff
lbl_08073f94: .4byte 0x08754bc8
lbl_08073f98: .4byte gMostRecentSaveFile
lbl_08073f9c: .4byte 0x08411410
lbl_08073fa0: .4byte 0x08411420
lbl_08073fa4: .4byte gGameCompletion
lbl_08073fa8: .4byte gHasSaved
lbl_08073fac: .4byte gCurrentArea
lbl_08073fb0: .4byte gCurrentRoom
lbl_08073fb4: .4byte gLastDoorUsed
lbl_08073fb8: .4byte gMinimapX
lbl_08073fbc: .4byte gMinimapY
lbl_08073fc0: .4byte gCamera
lbl_08073fc4: .4byte gBG0XPosition
lbl_08073fc8: .4byte gBG0YPosition
lbl_08073fcc: .4byte gBG1XPosition
lbl_08073fd0: .4byte gBG1YPosition
lbl_08073fd4: .4byte gBG2XPosition
lbl_08073fd8: .4byte gBG2YPosition
lbl_08073fdc: .4byte gBG3XPosition
lbl_08073fe0: .4byte gBG3YPosition
lbl_08073fe4: .4byte gDifficulty
lbl_08073fe8: .4byte gUseMotherShipDoors
lbl_08073fec: .4byte gTimeAttackFlag
lbl_08073ff0: .4byte gNumberOfNeverReformBlocks
lbl_08073ff4: .4byte gSamusData
lbl_08073ff8: .4byte gNumberOfItemsCollected
lbl_08073ffc: .4byte gSamusWeaponInfo
lbl_08074000: .4byte gSamusEcho
lbl_08074004: .4byte gScrewSpeedAnimation
lbl_08074008: .4byte gEquipment
lbl_0807400c: .4byte gSamusHazardDamage
lbl_08074010: .4byte gSamusEnvironmentalEffects
lbl_08074014: .4byte gPreventMovementTimer
lbl_08074018: .4byte gDisableDrawingSamusAndScrolling
lbl_0807401c: .4byte gAlarmTimer
lbl_08074020: .4byte gInGameTimer
lbl_08074024: .4byte 0x03000154
lbl_08074028: .4byte 0x08411430
lbl_0807402c: .4byte gInGameTimerAtBosses
lbl_08074030: .4byte gInGameCutscenesTriggered

    thumb_func_start load_sram_data
load_sram_data: @ 0x08074034
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r2, lbl_08074248 @ =0x08754bc8
    ldr r0, lbl_0807424c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r1, [r2]
    adds r4, r1, r0
    ldr r1, lbl_08074250 @ =gGameCompletion
    ldr r0, [r4, #0x18]
    str r0, [r1]
    ldr r1, lbl_08074254 @ =gHasSaved
    ldrb r0, [r4, #0x1c]
    strb r0, [r1]
    ldr r1, lbl_08074258 @ =gCurrentArea
    ldrb r0, [r4, #0x1d]
    strb r0, [r1]
    ldr r1, lbl_0807425c @ =gCurrentRoom
    ldrb r0, [r4, #0x1e]
    strb r0, [r1]
    ldr r1, lbl_08074260 @ =gLastDoorUsed
    ldrb r0, [r4, #0x1f]
    strb r0, [r1]
    ldr r1, lbl_08074264 @ =gMinimapX
    adds r0, r4, #0
    adds r0, #0x20
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074268 @ =gMinimapY
    adds r0, r4, #0
    adds r0, #0x21
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r2, lbl_0807426c @ =gCamera
    ldr r0, [r4, #0x24]
    ldr r1, [r4, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08074270 @ =gBG0XPosition
    ldrh r0, [r4, #0x2c]
    strh r0, [r1]
    ldr r1, lbl_08074274 @ =gBG0YPosition
    ldrh r0, [r4, #0x2e]
    strh r0, [r1]
    ldr r1, lbl_08074278 @ =gBG1XPosition
    ldrh r0, [r4, #0x30]
    strh r0, [r1]
    ldr r1, lbl_0807427c @ =gBG1YPosition
    ldrh r0, [r4, #0x32]
    strh r0, [r1]
    ldr r1, lbl_08074280 @ =gBG2XPosition
    ldrh r0, [r4, #0x34]
    strh r0, [r1]
    ldr r1, lbl_08074284 @ =gBG2YPosition
    ldrh r0, [r4, #0x36]
    strh r0, [r1]
    ldr r1, lbl_08074288 @ =gBG3XPosition
    ldrh r0, [r4, #0x38]
    strh r0, [r1]
    ldr r1, lbl_0807428c @ =gBG3YPosition
    ldrh r0, [r4, #0x3a]
    strh r0, [r1]
    ldr r1, lbl_08074290 @ =gDifficulty
    adds r0, r4, #0
    adds r0, #0x3c
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074294 @ =gUseMotherShipDoors
    adds r0, r4, #0
    adds r0, #0x3d
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_08074298 @ =gTimeAttackFlag
    adds r0, r4, #0
    adds r0, #0x3e
    ldrb r0, [r0]
    strb r0, [r1]
    movs r2, #0
    ldr r0, lbl_0807429c @ =gSamusData
    mov r8, r0
    ldr r1, lbl_080742a0 @ =gSamusWeaponInfo
    mov sb, r1
    ldr r3, lbl_080742a4 @ =gSamusEcho
    mov sl, r3
    ldr r5, lbl_080742a8 @ =gNumberOfNeverReformBlocks
    adds r3, r4, #0
    adds r3, #0x3f
lbl_080740f4:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_080740f4
    movs r2, #0
    adds r6, r4, #0
    adds r6, #0x60
    adds r7, r4, #0
    adds r7, #0x80
    movs r5, #0x88
    adds r5, r5, r4
    mov ip, r5
    ldr r5, lbl_080742ac @ =gNumberOfItemsCollected
    adds r3, r4, #0
    adds r3, #0x47
lbl_08074118:
    adds r0, r2, r5
    adds r1, r3, r2
    ldrb r1, [r1]
    strb r1, [r0]
    adds r2, #1
    cmp r2, #7
    ble lbl_08074118
    mov r1, r8
    adds r0, r6, #0
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, [r7]
    ldr r1, [r7, #4]
    mov r5, sb
    str r0, [r5]
    str r1, [r5, #4]
    movs r2, #0x86
    lsls r2, r2, #1
    mov r0, sl
    mov r1, ip
    bl memcpy
    ldr r2, lbl_080742b0 @ =gScrewSpeedAnimation
    movs r1, #0xca
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_080742b4 @ =gEquipment
    movs r2, #0xce
    lsls r2, r2, #1
    adds r0, r4, r2
    ldm r0!, {r2, r3, r5}
    stm r1!, {r2, r3, r5}
    ldm r0!, {r3, r5}
    stm r1!, {r3, r5}
    ldr r2, lbl_080742b8 @ =gSamusHazardDamage
    movs r1, #0xd8
    lsls r1, r1, #1
    adds r0, r4, r1
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_080742bc @ =gSamusEnvironmentalEffects
    movs r2, #0xdc
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xe2
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r5, #0xe8
    lsls r5, r5, #1
    adds r1, r4, r5
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r2, #0xee
    lsls r2, r2, #1
    adds r1, r4, r2
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    movs r3, #0xf4
    lsls r3, r3, #1
    adds r1, r4, r3
    ldm r1!, {r2, r3, r5}
    stm r0!, {r2, r3, r5}
    ldr r1, lbl_080742c0 @ =gPreventMovementTimer
    movs r5, #0xfa
    lsls r5, r5, #1
    adds r0, r4, r5
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742c4 @ =gDisableDrawingSamusAndScrolling
    movs r2, #0xfb
    lsls r2, r2, #1
    adds r0, r4, r2
    ldrb r0, [r0]
    strb r0, [r1]
    ldr r1, lbl_080742c8 @ =gAlarmTimer
    movs r3, #0xfc
    lsls r3, r3, #1
    adds r0, r4, r3
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_080742cc @ =gInGameTimer
    adds r5, #8
    adds r0, r4, r5
    ldr r0, [r0]
    str r0, [r1]
    movs r0, #0x80
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742d0 @ =0x03000154
    movs r2, #0xb
lbl_080741e8:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741e8
    ldr r7, lbl_080742d4 @ =gMusicInfo
    movs r2, #0x8c
    lsls r2, r2, #2
    adds r1, r4, r2
    ldr r3, lbl_080742d8 @ =gInGameTimerAtBosses
    movs r2, #4
lbl_080741fe:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_080741fe
    movs r3, #0x91
    lsls r3, r3, #2
    adds r0, r4, r3
    ldr r5, [r0]
    ldr r6, [r0, #4]
    movs r0, #0x93
    lsls r0, r0, #2
    adds r1, r4, r0
    ldr r3, lbl_080742dc @ =gInGameCutscenesTriggered
    movs r2, #0
lbl_0807421c:
    ldm r1!, {r0}
    stm r3!, {r0}
    subs r2, #1
    cmp r2, #0
    bge lbl_0807421c
    strh r5, [r7, #0x1c]
    lsrs r0, r5, #0x10
    strh r0, [r7, #0x1e]
    adds r0, r7, #0
    adds r0, #0x20
    strb r6, [r0]
    lsrs r1, r6, #8
    adds r0, #1
    strb r1, [r0]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074248: .4byte 0x08754bc8
lbl_0807424c: .4byte gMostRecentSaveFile
lbl_08074250: .4byte gGameCompletion
lbl_08074254: .4byte gHasSaved
lbl_08074258: .4byte gCurrentArea
lbl_0807425c: .4byte gCurrentRoom
lbl_08074260: .4byte gLastDoorUsed
lbl_08074264: .4byte gMinimapX
lbl_08074268: .4byte gMinimapY
lbl_0807426c: .4byte gCamera
lbl_08074270: .4byte gBG0XPosition
lbl_08074274: .4byte gBG0YPosition
lbl_08074278: .4byte gBG1XPosition
lbl_0807427c: .4byte gBG1YPosition
lbl_08074280: .4byte gBG2XPosition
lbl_08074284: .4byte gBG2YPosition
lbl_08074288: .4byte gBG3XPosition
lbl_0807428c: .4byte gBG3YPosition
lbl_08074290: .4byte gDifficulty
lbl_08074294: .4byte gUseMotherShipDoors
lbl_08074298: .4byte gTimeAttackFlag
lbl_0807429c: .4byte gSamusData
lbl_080742a0: .4byte gSamusWeaponInfo
lbl_080742a4: .4byte gSamusEcho
lbl_080742a8: .4byte gNumberOfNeverReformBlocks
lbl_080742ac: .4byte gNumberOfItemsCollected
lbl_080742b0: .4byte gScrewSpeedAnimation
lbl_080742b4: .4byte gEquipment
lbl_080742b8: .4byte gSamusHazardDamage
lbl_080742bc: .4byte gSamusEnvironmentalEffects
lbl_080742c0: .4byte gPreventMovementTimer
lbl_080742c4: .4byte gDisableDrawingSamusAndScrolling
lbl_080742c8: .4byte gAlarmTimer
lbl_080742cc: .4byte gInGameTimer
lbl_080742d0: .4byte 0x03000154
lbl_080742d4: .4byte gMusicInfo
lbl_080742d8: .4byte gInGameTimerAtBosses
lbl_080742dc: .4byte gInGameCutscenesTriggered

    thumb_func_start write_string
write_string: @ 0x080742e0
    push {r4, r5, lr}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r3, #0
    cmp r3, r2
    bge lbl_080742fe
lbl_080742f0:
    adds r0, r5, r3
    adds r1, r4, r3
    ldrb r1, [r1]
    strb r1, [r0]
    adds r3, #1
    cmp r3, r2
    blt lbl_080742f0
lbl_080742fe:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08074304
sub_08074304: @ 0x08074304
    push {r4, r5, lr}
    sub sp, #0x10
    movs r5, #0
    ldr r0, lbl_08074364 @ =gSramCorruptFlag
    strb r5, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    ldr r4, lbl_0807436c @ =0x0e007f80
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    rsbs r1, r0, #0
    orrs r1, r0
    lsrs r5, r1, #0x1f
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
lbl_0807432c:
    mov r0, sp
    adds r1, r0, r2
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r2, #1
    cmp r2, #0xf
    ble lbl_0807432c
    ldr r4, lbl_0807436c @ =0x0e007f80
    mov r0, sp
    adds r1, r4, #0
    movs r2, #0x10
    bl SramWriteChecked
    cmp r0, #0
    beq lbl_08074350
    movs r0, #2
    orrs r5, r0
lbl_08074350:
    adds r0, r4, #0
    mov r1, sp
    movs r2, #0x10
    bl SramWriteUnchecked
    movs r2, #0
    mov r0, sp
    ldrb r1, [r0]
    ldr r0, lbl_08074368 @ =0x08411400
    b lbl_08074380
    .align 2, 0
lbl_08074364: .4byte gSramCorruptFlag
lbl_08074368: .4byte 0x08411400
lbl_0807436c: .4byte 0x0e007f80
lbl_08074370:
    adds r2, #1
    cmp r2, #0xf
    bgt lbl_0807438c
    mov r1, sp
    adds r0, r1, r2
    ldrb r1, [r0]
    ldr r0, lbl_0807439c @ =0x08411400
    adds r0, r2, r0
lbl_08074380:
    ldrb r0, [r0]
    adds r0, #1
    cmp r1, r0
    beq lbl_08074370
    movs r0, #4
    orrs r5, r0
lbl_0807438c:
    cmp r5, #0
    beq lbl_08074394
    ldr r0, lbl_080743a0 @ =gSramCorruptFlag
    strb r5, [r0]
lbl_08074394:
    add sp, #0x10
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0807439c: .4byte 0x08411400
lbl_080743a0: .4byte gSramCorruptFlag

    thumb_func_start sub_080743a4
sub_080743a4: @ 0x080743a4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08074440 @ =gMostRecentSaveFile
    mov r8, r0
    ldr r1, lbl_08074444 @ =gIsLoadingFile
    mov sb, r1
    ldr r3, lbl_08074448 @ =0x08760408
    ldr r2, lbl_0807444c @ =0x03000c24
    movs r5, #2
lbl_080743be:
    adds r1, r2, #0
    adds r0, r3, #0
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    adds r2, #0x18
    subs r5, #1
    cmp r5, #0
    bge lbl_080743be
    movs r0, #0
    mov r1, r8
    strb r0, [r1]
    mov r2, sb
    strb r0, [r2]
    movs r5, #0
    ldr r7, lbl_08074450 @ =0x08754bc8
    movs r6, #0x10
    ldr r3, lbl_0807444c @ =0x03000c24
    str r3, [sp, #4]
    ldr r4, lbl_08074454 @ =0x0000ffff
    mov sl, r4
    movs r0, #0x91
    lsls r0, r0, #5
    mov sb, r0
lbl_080743f0:
    mov r1, r8
    strb r5, [r1]
    bl sub_08074574
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r3, lbl_0807444c @ =0x03000c24
    adds r0, r0, r3
    ldrb r4, [r0, #1]
    cmp r4, #0
    bne lbl_0807445c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r1, r0, #0
    adds r1, #0x80
    ldr r2, [r7]
    adds r1, r2, r1
    ldr r4, lbl_08074458 @ =0x000036e0
    adds r0, r0, r4
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DMATransfer
    movs r0, #4
    bl sub_08000c48
    movs r0, #1
    ldr r1, [sp, #4]
    strb r0, [r1]
    b lbl_0807454a
    .align 2, 0
lbl_08074440: .4byte gMostRecentSaveFile
lbl_08074444: .4byte gIsLoadingFile
lbl_08074448: .4byte 0x08760408
lbl_0807444c: .4byte 0x03000c24
lbl_08074450: .4byte 0x08754bc8
lbl_08074454: .4byte 0x0000ffff
lbl_08074458: .4byte 0x000036e0
lbl_0807445c:
    cmp r4, #1
    bne lbl_0807448c
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r2, lbl_08074488 @ =0x000036e0
    adds r1, r0, r2
    ldr r2, [r7]
    adds r1, r2, r1
    adds r0, #0x80
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    movs r3, #0x91
    lsls r3, r3, #5
    bl DMATransfer
    ldr r3, [sp, #4]
    strb r4, [r3]
    b lbl_0807454a
    .align 2, 0
lbl_08074488: .4byte 0x000036e0
lbl_0807448c:
    cmp r4, #2
    bne lbl_080744d8
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080744d4 @ =0x000036e0
    adds r0, r0, r1
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    b lbl_0807454a
    .align 2, 0
lbl_080744d4: .4byte 0x000036e0
lbl_080744d8:
    cmp r4, #2
    bls lbl_08074548
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #3
    bl sub_08000c48
    mov r2, r8
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r3, lbl_08074540 @ =0x000036e0
    adds r0, r0, r3
    ldr r2, [r7]
    adds r2, r2, r0
    str r6, [sp]
    movs r0, #3
    mov r1, sl
    mov r3, sb
    bl BitFill
    movs r0, #4
    bl sub_08000c48
    mov r4, r8
    movs r1, #0
    ldrsb r1, [r4, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    ldr r1, lbl_08074544 @ =0x03000c24
    adds r0, r0, r1
    movs r1, #0
    strb r1, [r0, #1]
    b lbl_0807454a
    .align 2, 0
lbl_08074540: .4byte 0x000036e0
lbl_08074544: .4byte 0x03000c24
lbl_08074548:
    b lbl_08074548
lbl_0807454a:
    ldr r2, [sp, #4]
    adds r2, #0x18
    str r2, [sp, #4]
    adds r5, #1
    cmp r5, #2
    bgt lbl_08074558
    b lbl_080743f0
lbl_08074558:
    movs r1, #0
    ldr r0, lbl_08074570 @ =gMostRecentSaveFile
    strb r1, [r0]
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074570: .4byte gMostRecentSaveFile

    thumb_func_start sub_08074574
sub_08074574: @ 0x08074574
    push {r4, r5, lr}
    movs r0, #0
    bl sub_08074624
    adds r4, r0, #0
    movs r0, #1
    bl sub_08074624
    adds r2, r0, #0
    cmp r4, #0
    bne lbl_080745a8
    ldr r2, lbl_080745a0 @ =0x03000c24
    ldr r0, lbl_080745a4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    strb r4, [r0, #1]
    b lbl_0807461c
    .align 2, 0
lbl_080745a0: .4byte 0x03000c24
lbl_080745a4: .4byte gMostRecentSaveFile
lbl_080745a8:
    cmp r4, #1
    bne lbl_080745d8
    ldr r5, lbl_080745d0 @ =0x03000c24
    ldr r3, lbl_080745d4 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r3, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r5
    strb r4, [r0, #1]
    cmp r2, #0
    beq lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r5
    b lbl_08074618
    .align 2, 0
lbl_080745d0: .4byte 0x03000c24
lbl_080745d4: .4byte gMostRecentSaveFile
lbl_080745d8:
    ldr r4, lbl_08074600 @ =0x03000c24
    ldr r3, lbl_08074604 @ =gMostRecentSaveFile
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #3
    strb r0, [r1, #1]
    cmp r2, #0
    bne lbl_08074608
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
    movs r0, #1
    b lbl_0807461a
    .align 2, 0
lbl_08074600: .4byte 0x03000c24
lbl_08074604: .4byte gMostRecentSaveFile
lbl_08074608:
    cmp r2, #1
    bne lbl_0807461c
    movs r0, #0
    ldrsb r0, [r3, r0]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r4
lbl_08074618:
    movs r0, #2
lbl_0807461a:
    strb r0, [r1, #1]
lbl_0807461c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08074624
sub_08074624: @ 0x08074624
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08074654
    ldr r2, lbl_0807464c @ =0x08754bc8
    ldr r0, lbl_08074650 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    b lbl_0807466a
    .align 2, 0
lbl_0807464c: .4byte 0x08754bc8
lbl_08074650: .4byte gMostRecentSaveFile
lbl_08074654:
    ldr r2, lbl_080746d8 @ =0x08754bc8
    ldr r0, lbl_080746dc @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    ldr r1, lbl_080746e0 @ =0x000036e0
    adds r0, r0, r1
lbl_0807466a:
    ldr r1, [r2]
    adds r4, r1, r0
    adds r1, r4, #0
    movs r2, #0
    ldr r6, [r4, #0x10]
    mov ip, r6
    ldr r7, lbl_080746e4 @ =0x08411410
    ldrb r0, [r4]
    mov sb, r0
    ldr r6, lbl_080746e8 @ =0x08411420
    mov r8, r6
    adds r6, r4, #0
    adds r6, #0x4f
    ldr r0, lbl_080746ec @ =0x08411430
    mov sl, r0
    movs r0, #0x94
    lsls r0, r0, #2
    adds r0, r4, r0
    str r0, [sp, #4]
    movs r3, #0x90
lbl_08074692:
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    ldm r1!, {r0}
    adds r2, r2, r0
    subs r3, #1
    cmp r3, #0
    bge lbl_08074692
    movs r5, #0
    cmp ip, r2
    bne lbl_080746c6
    ldr r0, [r4, #0x14]
    mvns r0, r0
    cmp r2, r0
    beq lbl_080746c8
lbl_080746c6:
    movs r5, #1
lbl_080746c8:
    movs r2, #0
    movs r3, #0
    ldrb r0, [r7]
    cmp r0, sb
    beq lbl_080746f0
    movs r2, #1
    b lbl_08074706
    .align 2, 0
lbl_080746d8: .4byte 0x08754bc8
lbl_080746dc: .4byte gMostRecentSaveFile
lbl_080746e0: .4byte 0x000036e0
lbl_080746e4: .4byte 0x08411410
lbl_080746e8: .4byte 0x08411420
lbl_080746ec: .4byte 0x08411430
lbl_080746f0:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074706
    adds r0, r3, r7
    adds r1, r4, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080746f0
    movs r0, #1
    orrs r2, r0
lbl_08074706:
    movs r3, #0
    mov r1, r8
    ldrb r0, [r1]
    ldrb r1, [r6]
    b lbl_08074720
lbl_08074710:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074728
    mov r1, r8
    adds r0, r3, r1
    adds r1, r6, r3
    ldrb r0, [r0]
    ldrb r1, [r1]
lbl_08074720:
    cmp r0, r1
    beq lbl_08074710
    movs r0, #2
    orrs r2, r0
lbl_08074728:
    movs r3, #0
    mov r6, sl
    ldrb r0, [r6]
    ldr r1, [sp, #4]
    b lbl_08074746
lbl_08074732:
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074750
    mov r6, sl
    adds r0, r3, r6
    movs r6, #0x94
    lsls r6, r6, #2
    adds r1, r4, r6
    adds r1, r1, r3
    ldrb r0, [r0]
lbl_08074746:
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074732
    movs r0, #4
    orrs r2, r0
lbl_08074750:
    cmp r2, #0
    beq lbl_08074760
    cmp r2, #7
    bne lbl_0807475c
    movs r0, #2
    b lbl_0807475e
lbl_0807475c:
    movs r0, #1
lbl_0807475e:
    orrs r5, r0
lbl_08074760:
    cmp r5, #1
    ble lbl_08074776
    ldr r1, lbl_08074788 @ =0x0000ffff
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
lbl_08074776:
    adds r0, r5, #0
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074788: .4byte 0x0000ffff

    thumb_func_start sub_0807478c
sub_0807478c: @ 0x0807478c
    push {lr}
    ldr r0, lbl_080747a8 @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_080747a2
    bl load_sram_data
    bl load_sram_arrays
lbl_080747a2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_080747a8: .4byte gIsLoadingFile

    thumb_func_start sub_080747ac
sub_080747ac: @ 0x080747ac
    push {lr}
    bl load_sram_data
    bl load_sram_arrays
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start write_sram_arrays
write_sram_arrays: @ 0x080747bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_08074898 @ =0x08754bc8
    ldr r0, lbl_0807489c @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r1, lbl_080748a0 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r2, r8
    bl DMATransfer
    ldr r1, lbl_080748a4 @ =0x02037c00
    movs r0, #0x88
    lsls r0, r0, #5
    adds r2, r4, r0
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_080748a8 @ =0x02037e00
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    str r5, [sp]
    movs r0, #3
    adds r2, r4, #0
    movs r3, #0x20
    bl DMATransfer
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748ac @ =0x02035c00
lbl_08074824:
    ldr r0, lbl_080748b0 @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08074848
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r6, r6, r4
lbl_08074848:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074824
    movs r6, #0
    movs r5, #0
    ldr r7, lbl_080748b4 @ =0x02036c00
lbl_0807485a:
    ldr r0, lbl_080748b8 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_0807487e
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r2, r6, r0
    add r2, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r7, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r6, r6, r4
lbl_0807487e:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r7, r7, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807485a
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074898: .4byte 0x08754bc8
lbl_0807489c: .4byte gMostRecentSaveFile
lbl_080748a0: .4byte 0x02037400
lbl_080748a4: .4byte 0x02037c00
lbl_080748a8: .4byte 0x02037e00
lbl_080748ac: .4byte 0x02035c00
lbl_080748b0: .4byte gNumberOfNeverReformBlocks
lbl_080748b4: .4byte 0x02036c00
lbl_080748b8: .4byte gNumberOfItemsCollected

    thumb_func_start load_sram_arrays
load_sram_arrays: @ 0x080748bc
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r2, lbl_080749bc @ =0x08754bc8
    ldr r0, lbl_080749c0 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #4
    adds r0, r0, r1
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r4, [r2]
    adds r4, r4, r0
    movs r0, #0xc0
    lsls r0, r0, #2
    adds r0, r0, r4
    mov r8, r0
    ldr r2, lbl_080749c4 @ =0x02037400
    movs r3, #0x80
    lsls r3, r3, #3
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    mov r1, r8
    bl DMATransfer
    movs r0, #0x88
    lsls r0, r0, #5
    adds r1, r4, r0
    ldr r2, lbl_080749c8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #1
    str r5, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #0x90
    lsls r0, r0, #5
    adds r4, r4, r0
    ldr r2, lbl_080749cc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    movs r3, #0x20
    bl DMATransfer
    ldr r4, lbl_080749d0 @ =0x0000ffff
    ldr r6, lbl_080749d4 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r2, r6, #0
    bl BitFill
    ldr r2, lbl_080749d8 @ =0x02036c00
    movs r3, #0x80
    lsls r3, r3, #4
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    movs r7, #0
    movs r5, #0
lbl_08074946:
    ldr r0, lbl_080749dc @ =gNumberOfNeverReformBlocks
    adds r1, r5, r0
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0807496a
    lsls r4, r0, #1
    movs r0, #0x80
    lsls r0, r0, #3
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r7, r7, r4
lbl_0807496a:
    movs r0, #0x80
    lsls r0, r0, #2
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_08074946
    movs r7, #0
    movs r5, #0
    ldr r6, lbl_080749d8 @ =0x02036c00
lbl_0807497c:
    ldr r0, lbl_080749e0 @ =gNumberOfItemsCollected
    adds r0, r5, r0
    ldrb r0, [r0]
    lsls r4, r0, #2
    cmp r4, #0
    beq lbl_080749a0
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r1, r7, r0
    add r1, r8
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r6, #0
    adds r3, r4, #0
    bl DMATransfer
    adds r7, r7, r4
lbl_080749a0:
    movs r0, #0x80
    lsls r0, r0, #1
    adds r6, r6, r0
    adds r5, #1
    cmp r5, #7
    ble lbl_0807497c
    bl load_minimap_tiles_with_obtained_items
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080749bc: .4byte 0x08754bc8
lbl_080749c0: .4byte gMostRecentSaveFile
lbl_080749c4: .4byte 0x02037400
lbl_080749c8: .4byte 0x02037c00
lbl_080749cc: .4byte 0x02037e00
lbl_080749d0: .4byte 0x0000ffff
lbl_080749d4: .4byte 0x02035c00
lbl_080749d8: .4byte 0x02036c00
lbl_080749dc: .4byte gNumberOfNeverReformBlocks
lbl_080749e0: .4byte gNumberOfItemsCollected

    thumb_func_start sub_080749e4
sub_080749e4: @ 0x080749e4
    push {r4, r5, lr}
    ldr r0, lbl_08074a68 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdb
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1e
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074a6c @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074a70 @ =gMostRecentSaveFile
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074a74 @ =0x08411488
    ldr r0, lbl_08074a78 @ =0x00006d86
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074a12:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a12
    movs r1, #0
    movs r4, #7
lbl_08074a28:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074a28
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #5
    bl sub_08000c48
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074a68: .4byte 0x08754bc8
lbl_08074a6c: .4byte 0x0000ffff
lbl_08074a70: .4byte gMostRecentSaveFile
lbl_08074a74: .4byte 0x08411488
lbl_08074a78: .4byte 0x00006d86

    thumb_func_start sub_08074a7c
sub_08074a7c: @ 0x08074a7c
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074b28 @ =0x08754bc8
    ldr r0, [r2]
    movs r1, #0xdb
    lsls r1, r1, #7
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1e
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074b2c @ =gMostRecentSaveFile
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074aa8:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074aa8
    cmp r5, r2
    beq lbl_08074adc
    movs r4, #2
lbl_08074adc:
    cmp r4, #0
    bne lbl_08074b34
    movs r3, #0
    ldr r0, lbl_08074b30 @ =0x08411488
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074b34
lbl_08074af0:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074b34
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074b1c
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074af0
    movs r4, #3
lbl_08074b1c:
    cmp r4, #0
    bne lbl_08074b34
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074b54
    .align 2, 0
lbl_08074b28: .4byte 0x08754bc8
lbl_08074b2c: .4byte gMostRecentSaveFile
lbl_08074b30: .4byte 0x08411488
lbl_08074b34:
    mov r1, sp
    ldr r2, lbl_08074b60 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074b64 @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    movs r2, #0xdb
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074b68 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074b54:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074b60: .4byte 0x0000ffff
lbl_08074b64: .4byte 0x040000d4
lbl_08074b68: .4byte 0x81000020

    thumb_func_start sub_08074b6c
sub_08074b6c: @ 0x08074b6c
    push {r4, r5, lr}
    ldr r0, lbl_08074bf0 @ =0x08754bc8
    ldr r2, [r0]
    ldr r0, lbl_08074bf4 @ =0x00006e40
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074bf8 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074bfc @ =gStereoFlag
    ldrb r0, [r0]
    strb r0, [r5, #0x16]
    ldr r1, lbl_08074c00 @ =0x084114a8
    ldr r0, lbl_08074c04 @ =0x00006e46
    adds r2, r2, r0
    movs r4, #0xf
lbl_08074b98:
    ldrb r0, [r1]
    strb r0, [r2]
    ldrb r0, [r1, #0x10]
    strb r0, [r2, #0x11]
    adds r1, #1
    adds r2, #1
    subs r4, #1
    cmp r4, #0
    bge lbl_08074b98
    movs r1, #0
    movs r4, #7
lbl_08074bae:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074bae
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #8
    bl sub_08000c48
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074bf0: .4byte 0x08754bc8
lbl_08074bf4: .4byte 0x00006e40
lbl_08074bf8: .4byte 0x0000ffff
lbl_08074bfc: .4byte gStereoFlag
lbl_08074c00: .4byte 0x084114a8
lbl_08074c04: .4byte 0x00006e46

    thumb_func_start sub_08074c08
sub_08074c08: @ 0x08074c08
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r2, lbl_08074cb0 @ =0x08754bc8
    ldr r0, [r2]
    ldr r1, lbl_08074cb4 @ =0x00006e40
    adds r1, r1, r0
    mov ip, r1
    ldrb r1, [r1]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    adds r7, r2, #0
    ldr r6, lbl_08074cb8 @ =gStereoFlag
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    movs r2, #0
    ldrh r5, [r1, #2]
    movs r3, #7
lbl_08074c32:
    ldrh r0, [r1]
    adds r0, r2, r0
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    adds r1, #2
    lsrs r0, r0, #0x10
    ldrh r2, [r1]
    adds r0, r0, r2
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    adds r1, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074c32
    cmp r5, r2
    beq lbl_08074c66
    movs r4, #2
lbl_08074c66:
    cmp r4, #0
    bne lbl_08074cc0
    movs r3, #0
    ldr r0, lbl_08074cbc @ =0x084114a8
    mov r2, ip
    ldrb r1, [r2, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    bne lbl_08074cc0
lbl_08074c7a:
    mov r0, ip
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074cc0
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074ca6
    mov r0, ip
    adds r0, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074c7a
    movs r4, #3
lbl_08074ca6:
    cmp r4, #0
    bne lbl_08074cc0
    mov r1, ip
    ldrb r0, [r1, #0x16]
    b lbl_08074cde
    .align 2, 0
lbl_08074cb0: .4byte 0x08754bc8
lbl_08074cb4: .4byte 0x00006e40
lbl_08074cb8: .4byte gStereoFlag
lbl_08074cbc: .4byte 0x084114a8
lbl_08074cc0:
    mov r1, sp
    ldr r2, lbl_08074ce8 @ =0x0000ffff
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_08074cec @ =0x040000d4
    mov r0, sp
    str r0, [r1]
    ldr r0, [r7]
    ldr r2, lbl_08074cf0 @ =0x00006e40
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074cf4 @ =0x81000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0
lbl_08074cde:
    strb r0, [r6]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ce8: .4byte 0x0000ffff
lbl_08074cec: .4byte 0x040000d4
lbl_08074cf0: .4byte 0x00006e40
lbl_08074cf4: .4byte 0x81000020

    thumb_func_start SramWrite_Language
SramWrite_Language: @ 0x08074cf8
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074d88 @ =0x08754bc8
    ldr r4, [r0]
    ldr r0, lbl_08074d8c @ =0x00006dc0
    adds r5, r4, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x1f
    strb r0, [r5]
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    strh r1, [r5, #2]
    ldr r0, lbl_08074d90 @ =0x0000ffff
    strh r0, [r5, #4]
    ldr r0, lbl_08074d94 @ =gLanguage
    movs r2, #0
    ldrsb r2, [r0, r2]
    cmp r2, #6
    bls lbl_08074d22
    movs r2, #2
lbl_08074d22:
    strb r2, [r5, #0x16]
    movs r2, #0
    ldr r1, lbl_08074d98 @ =0x00006dc6
    adds r7, r4, r1
    ldr r0, lbl_08074d9c @ =0x00006dd7
    adds r6, r4, r0
    ldr r4, lbl_08074da0 @ =0x084114c8
lbl_08074d30:
    adds r1, r7, r2
    ldrb r0, [r4]
    strb r0, [r1]
    adds r1, r6, r2
    ldrb r0, [r4, #0x10]
    strb r0, [r1]
    adds r4, #1
    adds r2, #1
    cmp r2, #0xf
    ble lbl_08074d30
    movs r1, #0
    movs r2, #7
lbl_08074d48:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r2, #1
    cmp r2, #0
    bge lbl_08074d48
    strh r1, [r5, #2]
    mvns r0, r1
    strh r0, [r5, #4]
    movs r0, #6
    bl sub_08000c48
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074d88: .4byte 0x08754bc8
lbl_08074d8c: .4byte 0x00006dc0
lbl_08074d90: .4byte 0x0000ffff
lbl_08074d94: .4byte gLanguage
lbl_08074d98: .4byte 0x00006dc6
lbl_08074d9c: .4byte 0x00006dd7
lbl_08074da0: .4byte 0x084114c8

    thumb_func_start sub_08074da4
sub_08074da4: @ 0x08074da4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08074e2c @ =0x08754bc8
    mov sb, r1
    ldr r6, lbl_08074e30 @ =0x040000d4
    ldr r2, lbl_08074e34 @ =0x81000020
    mov sl, r2
lbl_08074dbe:
    mov r1, r8
    lsls r0, r1, #6
    ldr r2, lbl_08074e38 @ =0x00006dc0
    adds r0, r0, r2
    mov r2, sb
    ldr r1, [r2]
    adds r5, r1, r0
    adds r2, r5, #0
    ldrb r1, [r5]
    movs r0, #0x1f
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r4, r0, #0x1f
    cmp r4, #0
    bne lbl_08074e6e
    movs r1, #0
    ldrh r7, [r5, #2]
    movs r3, #7
lbl_08074de4:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08074de4
    cmp r7, r1
    beq lbl_08074e18
    movs r4, #2
lbl_08074e18:
    cmp r4, #0
    bne lbl_08074e6e
    movs r3, #0
    ldr r0, lbl_08074e3c @ =0x084114c8
    ldrb r1, [r5, #6]
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r1, r0
    beq lbl_08074e44
    b lbl_08074e6c
    .align 2, 0
lbl_08074e2c: .4byte 0x08754bc8
lbl_08074e30: .4byte 0x040000d4
lbl_08074e34: .4byte 0x81000020
lbl_08074e38: .4byte 0x00006dc0
lbl_08074e3c: .4byte 0x084114c8
lbl_08074e40:
    movs r4, #4
    b lbl_08074e6e
lbl_08074e44:
    adds r0, r5, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08074e40
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_08074e6e
    adds r0, r5, #6
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_08074e44
lbl_08074e6c:
    movs r4, #3
lbl_08074e6e:
    mov r1, r8
    cmp r1, #0
    bne lbl_08074ea0
    cmp r4, #0
    bne lbl_08074ee2
    mov r2, sb
    ldr r1, [r2]
    ldr r2, lbl_08074e98 @ =0x00006dc0
    adds r0, r1, r2
    str r0, [r6]
    movs r0, #0xdc
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r6, #4]
    ldr r0, lbl_08074e9c @ =0x80000020
    str r0, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl sub_08000c48
    b lbl_08074eee
    .align 2, 0
lbl_08074e98: .4byte 0x00006dc0
lbl_08074e9c: .4byte 0x80000020
lbl_08074ea0:
    cmp r4, #0
    beq lbl_08074f04
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    ldr r1, lbl_08074efc @ =0x00006dc0
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #6
    bl sub_08000c48
    mov r0, sp
    movs r1, #0
    strh r1, [r0]
    str r0, [r6]
    mov r2, sb
    ldr r0, [r2]
    movs r1, #0xdc
    lsls r1, r1, #7
    adds r0, r0, r1
    str r0, [r6, #4]
    mov r2, sl
    str r2, [r6, #8]
    ldr r0, [r6, #8]
    movs r0, #7
    bl sub_08000c48
lbl_08074ee2:
    movs r0, #1
    add r8, r0
    mov r1, r8
    cmp r1, #1
    bgt lbl_08074eee
    b lbl_08074dbe
lbl_08074eee:
    cmp r4, #0
    beq lbl_08074f3c
    ldr r1, lbl_08074f00 @ =gLanguage
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    b lbl_08074f44
    .align 2, 0
lbl_08074efc: .4byte 0x00006dc0
lbl_08074f00: .4byte gLanguage
lbl_08074f04:
    ldr r1, lbl_08074f2c @ =0x040000d4
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    movs r2, #0xdc
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r2, lbl_08074f30 @ =0x08754bc8
    ldr r0, [r2]
    ldr r2, lbl_08074f34 @ =0x00006dc0
    adds r0, r0, r2
    str r0, [r1, #4]
    ldr r0, lbl_08074f38 @ =0x80000020
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #6
    bl sub_08000c48
    b lbl_08074eee
    .align 2, 0
lbl_08074f2c: .4byte 0x040000d4
lbl_08074f30: .4byte 0x08754bc8
lbl_08074f34: .4byte 0x00006dc0
lbl_08074f38: .4byte 0x80000020
lbl_08074f3c:
    ldr r1, lbl_08074f54 @ =gLanguage
    ldrb r0, [r5, #0x16]
    strb r0, [r1]
    movs r0, #0
lbl_08074f44:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08074f54: .4byte gLanguage

    thumb_func_start backup_time_attack_for_sram
backup_time_attack_for_sram: @ 0x08074f58
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08074ff4 @ =0x08754bc8
    ldr r2, [r0]
    movs r0, #0xdd
    lsls r0, r0, #7
    adds r5, r2, r0
    adds r3, r5, #0
    movs r1, #0
    movs r0, #0x40
    strb r0, [r5]
    ldrb r0, [r5, #0x16]
    adds r0, #1
    strb r0, [r5, #0x16]
    strh r1, [r5, #0x12]
    ldr r0, lbl_08074ff8 @ =0x0000ffff
    strh r0, [r5, #0x14]
    ldr r4, lbl_08074ffc @ =0x00006ea8
    adds r1, r2, r4
    ldr r0, lbl_08075000 @ =gTimeAttackRecord
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    movs r4, #0
    ldr r6, lbl_08075004 @ =0x00006e97
    adds r7, r2, r6
    ldr r0, lbl_08075008 @ =0x00006ed8
    adds r6, r2, r0
    ldr r2, lbl_0807500c @ =0x084114e8
lbl_08074f9a:
    adds r1, r7, r4
    ldrb r0, [r2]
    strb r0, [r1]
    adds r1, r6, r4
    ldrb r0, [r2, #0x10]
    strb r0, [r1]
    adds r2, #1
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08074f9a
    movs r1, #0
    movs r4, #0x1f
lbl_08074fb2:
    ldrh r0, [r3]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r3]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r6, [r3]
    adds r0, r0, r6
    lsls r0, r0, #0x10
    adds r3, #2
    lsrs r0, r0, #0x10
    ldrh r7, [r3]
    adds r0, r0, r7
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r3, #2
    subs r4, #1
    cmp r4, #0
    bge lbl_08074fb2
    strh r1, [r5, #0x12]
    mvns r0, r1
    strh r0, [r5, #0x14]
    movs r0, #9
    bl sub_08000c48
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08074ff4: .4byte 0x08754bc8
lbl_08074ff8: .4byte 0x0000ffff
lbl_08074ffc: .4byte 0x00006ea8
lbl_08075000: .4byte gTimeAttackRecord
lbl_08075004: .4byte 0x00006e97
lbl_08075008: .4byte 0x00006ed8
lbl_0807500c: .4byte 0x084114e8

    thumb_func_start sub_08075010
sub_08075010: @ 0x08075010
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    movs r0, #0
    mov r8, r0
    ldr r1, lbl_08075098 @ =0x08754bc8
    mov sb, r1
    ldr r2, lbl_0807509c @ =0x040000d4
    mov sl, r2
lbl_08075028:
    mov r3, r8
    lsls r0, r3, #8
    movs r4, #0xdd
    lsls r4, r4, #7
    adds r0, r0, r4
    mov r2, sb
    ldr r1, [r2]
    adds r7, r1, r0
    adds r2, r7, #0
    ldrb r1, [r7]
    movs r0, #0x40
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    cmp r6, #0
    bne lbl_080750d4
    movs r1, #0
    ldrh r4, [r7, #0x12]
    movs r3, #0x1f
lbl_08075050:
    ldrh r0, [r2]
    adds r0, r1, r0
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    adds r2, #2
    lsrs r0, r0, #0x10
    ldrh r1, [r2]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, #2
    subs r3, #1
    cmp r3, #0
    bge lbl_08075050
    cmp r4, r1
    beq lbl_08075084
    movs r6, #2
lbl_08075084:
    cmp r6, #0
    bne lbl_080750d4
    movs r3, #0
    ldr r0, lbl_080750a0 @ =0x084114e8
    ldrb r1, [r7, #0x17]
    adds r2, r0, #0
    ldrb r4, [r2]
    cmp r1, r4
    beq lbl_080750a8
    b lbl_080750d2
    .align 2, 0
lbl_08075098: .4byte 0x08754bc8
lbl_0807509c: .4byte 0x040000d4
lbl_080750a0: .4byte 0x084114e8
lbl_080750a4:
    movs r6, #4
    b lbl_080750d4
lbl_080750a8:
    adds r0, r7, #0
    adds r0, #0x58
    adds r0, r0, r3
    adds r1, r2, #0
    adds r1, #0x10
    adds r1, r3, r1
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_080750a4
    adds r3, #1
    cmp r3, #0xf
    bgt lbl_080750d4
    adds r0, r7, #0
    adds r0, #0x17
    adds r0, r0, r3
    adds r1, r3, r2
    ldrb r0, [r0]
    ldrb r1, [r1]
    cmp r0, r1
    beq lbl_080750a8
lbl_080750d2:
    movs r6, #3
lbl_080750d4:
    mov r0, r8
    cmp r0, #0
    bne lbl_08075108
    cmp r6, #0
    bne lbl_0807514a
    mov r2, sb
    ldr r1, [r2]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r1, r3
    mov r4, sl
    str r0, [r4]
    movs r0, #0xdf
    lsls r0, r0, #7
    adds r1, r1, r0
    str r1, [r4, #4]
    ldr r0, lbl_08075104 @ =0x80000080
    str r0, [r4, #8]
    ldr r0, [r4, #8]
    movs r0, #0xa
    bl sub_08000c48
    b lbl_08075156
    .align 2, 0
lbl_08075104: .4byte 0x80000080
lbl_08075108:
    cmp r6, #0
    beq lbl_0807517c
    mov r1, sb
    ldr r2, [r1]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r2, r2, r3
    movs r5, #0x80
    lsls r5, r5, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #9
    bl sub_08000c48
    mov r0, sb
    ldr r2, [r0]
    movs r1, #0xdf
    lsls r1, r1, #7
    adds r2, r2, r1
    str r4, [sp]
    movs r0, #3
    ldr r1, lbl_08075174 @ =0x0000ffff
    adds r3, r5, #0
    bl BitFill
    movs r0, #0xa
    bl sub_08000c48
lbl_0807514a:
    movs r2, #1
    add r8, r2
    mov r3, r8
    cmp r3, #1
    bgt lbl_08075156
    b lbl_08075028
lbl_08075156:
    cmp r6, #0
    bne lbl_080751b0
    ldr r1, lbl_08075178 @ =gTimeAttackRecord
    adds r0, r7, #0
    adds r0, #0x28
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    b lbl_080751c0
    .align 2, 0
lbl_08075174: .4byte 0x0000ffff
lbl_08075178: .4byte gTimeAttackRecord
lbl_0807517c:
    ldr r1, lbl_080751a4 @ =0x040000d4
    ldr r4, lbl_080751a8 @ =0x08754bc8
    ldr r0, [r4]
    movs r2, #0xdf
    lsls r2, r2, #7
    adds r0, r0, r2
    str r0, [r1]
    ldr r0, [r4]
    movs r3, #0xdd
    lsls r3, r3, #7
    adds r0, r0, r3
    str r0, [r1, #4]
    ldr r0, lbl_080751ac @ =0x80000080
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #9
    bl sub_08000c48
    b lbl_08075156
    .align 2, 0
lbl_080751a4: .4byte 0x040000d4
lbl_080751a8: .4byte 0x08754bc8
lbl_080751ac: .4byte 0x80000080
lbl_080751b0:
    ldr r1, lbl_080751d0 @ =0x0000ffff
    ldr r2, lbl_080751d4 @ =gTimeAttackRecord
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x30
    bl BitFill
lbl_080751c0:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080751d0: .4byte 0x0000ffff
lbl_080751d4: .4byte gTimeAttackRecord

    thumb_func_start sub_080751d8
sub_080751d8: @ 0x080751d8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r1, lbl_08075314 @ =0x0000ffff
    ldr r4, lbl_08075318 @ =0x0203f800
    movs r3, #0xa0
    lsls r3, r3, #2
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl BitFill
    ldr r5, lbl_0807531c @ =gCurrentArea
    ldrb r0, [r5]
    strb r0, [r4]
    ldr r0, lbl_08075320 @ =gLastDoorUsed
    ldrb r0, [r0]
    strb r0, [r4, #1]
    adds r1, r4, #4
    ldr r0, lbl_08075324 @ =gSamusData
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r0, lbl_08075328 @ =gSamusWeaponInfo
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r4, #0x24]
    str r1, [r4, #0x28]
    ldr r1, lbl_0807532c @ =gSamusEcho
    adds r0, r4, #0
    adds r0, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    movs r2, #0x9c
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075330 @ =gScrewSpeedAnimation
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xa0
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_08075334 @ =gEquipment
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldm r0!, {r2, r7}
    stm r1!, {r2, r7}
    movs r2, #0xaa
    lsls r2, r2, #1
    adds r2, r4, r2
    ldr r0, lbl_08075338 @ =gSamusHazardDamage
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    movs r1, #0xae
    lsls r1, r1, #1
    orrs r1, r4
    ldr r0, lbl_0807533c @ =gSamusEnvironmentalEffects
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xb4
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xba
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc0
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    movs r1, #0xc6
    lsls r1, r1, #1
    orrs r1, r4
    ldm r0!, {r2, r3, r7}
    stm r1!, {r2, r3, r7}
    ldrb r1, [r5]
    lsls r1, r1, #7
    ldr r3, lbl_08075340 @ =0x02037400
    adds r1, r1, r3
    movs r2, #0xcc
    lsls r2, r2, #1
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    ldrb r1, [r5]
    lsls r1, r1, #5
    ldr r7, lbl_08075344 @ =0x02037c00
    adds r1, r1, r7
    movs r2, #0x86
    lsls r2, r2, #2
    adds r2, r4, r2
    str r6, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    movs r0, #0x8e
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r1, #0x41
    strb r1, [r0]
    ldr r0, lbl_08075348 @ =0x00000239
    adds r0, r4, r0
    movs r1, #0x54
    strb r1, [r0]
    ldr r0, lbl_0807534c @ =0x0000023a
    adds r0, r4, r0
    movs r1, #0x52
    strb r1, [r0]
    ldr r0, lbl_08075350 @ =0x0000023b
    adds r0, r4, r0
    movs r1, #0x55
    strb r1, [r0]
    movs r0, #0x8f
    lsls r0, r0, #2
    adds r0, r4, r0
    movs r2, #0x4e
    strb r2, [r0]
    ldr r0, lbl_08075354 @ =0x0000023d
    adds r0, r4, r0
    movs r1, #0x45
    strb r1, [r0]
    ldr r0, lbl_08075358 @ =0x0000023e
    adds r0, r4, r0
    strb r2, [r0]
    ldr r0, lbl_0807535c @ =0x0000023f
    adds r0, r4, r0
    movs r1, #0x44
    strb r1, [r0]
    ldr r0, lbl_08075360 @ =gUseMotherShipDoors
    ldrb r1, [r0]
    movs r0, #0x90
    lsls r0, r0, #2
    adds r4, r4, r0
    strb r1, [r4]
    movs r0, #0xd
    bl sub_08000c48
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075314: .4byte 0x0000ffff
lbl_08075318: .4byte 0x0203f800
lbl_0807531c: .4byte gCurrentArea
lbl_08075320: .4byte gLastDoorUsed
lbl_08075324: .4byte gSamusData
lbl_08075328: .4byte gSamusWeaponInfo
lbl_0807532c: .4byte gSamusEcho
lbl_08075330: .4byte gScrewSpeedAnimation
lbl_08075334: .4byte gEquipment
lbl_08075338: .4byte gSamusHazardDamage
lbl_0807533c: .4byte gSamusEnvironmentalEffects
lbl_08075340: .4byte 0x02037400
lbl_08075344: .4byte 0x02037c00
lbl_08075348: .4byte 0x00000239
lbl_0807534c: .4byte 0x0000023a
lbl_08075350: .4byte 0x0000023b
lbl_08075354: .4byte 0x0000023d
lbl_08075358: .4byte 0x0000023e
lbl_0807535c: .4byte 0x0000023f
lbl_08075360: .4byte gUseMotherShipDoors

    thumb_func_start load_demo_ram_values
load_demo_ram_values: @ 0x08075364
    push {r4, r5, r6, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x18
    ldr r0, lbl_080753c8 @ =0x0875fdfc
    lsrs r1, r1, #0x16
    adds r1, r1, r0
    ldr r6, [r1]
    cmp r2, #0
    bne lbl_080753e0
    ldr r4, lbl_080753cc @ =gCurrentArea
    ldrb r0, [r6]
    strb r0, [r4]
    ldr r1, lbl_080753d0 @ =gLastDoorUsed
    ldrb r0, [r6, #1]
    strb r0, [r1]
    ldr r1, lbl_080753d4 @ =gUseMotherShipDoors
    movs r2, #0x90
    lsls r2, r2, #2
    adds r0, r6, r2
    ldrb r0, [r0]
    strb r0, [r1]
    movs r3, #0xcc
    lsls r3, r3, #1
    adds r1, r6, r3
    ldrb r2, [r4]
    lsls r2, r2, #7
    ldr r0, lbl_080753d8 @ =0x02037400
    adds r2, r2, r0
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r3, #0x80
    bl DMATransfer
    movs r2, #0x86
    lsls r2, r2, #2
    adds r1, r6, r2
    ldrb r2, [r4]
    lsls r2, r2, #5
    ldr r3, lbl_080753dc @ =0x02037c00
    adds r2, r2, r3
    str r5, [sp]
    movs r0, #3
    movs r3, #0x20
    bl DMATransfer
    b lbl_08075470
    .align 2, 0
lbl_080753c8: .4byte 0x0875fdfc
lbl_080753cc: .4byte gCurrentArea
lbl_080753d0: .4byte gLastDoorUsed
lbl_080753d4: .4byte gUseMotherShipDoors
lbl_080753d8: .4byte 0x02037400
lbl_080753dc: .4byte 0x02037c00
lbl_080753e0:
    cmp r2, #1
    bne lbl_08075470
    ldr r1, lbl_08075478 @ =gSamusData
    adds r0, r6, #4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r4}
    stm r1!, {r2, r4}
    ldr r2, lbl_0807547c @ =gSamusWeaponInfo
    ldr r0, [r6, #0x24]
    ldr r1, [r6, #0x28]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075480 @ =gSamusEcho
    adds r1, r6, #0
    adds r1, #0x2c
    movs r2, #0x86
    lsls r2, r2, #1
    bl memcpy
    ldr r2, lbl_08075484 @ =gScrewSpeedAnimation
    movs r3, #0x9c
    lsls r3, r3, #1
    adds r0, r6, r3
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r1, lbl_08075488 @ =gEquipment
    movs r4, #0xa0
    lsls r4, r4, #1
    adds r0, r6, r4
    ldm r0!, {r2, r3, r4}
    stm r1!, {r2, r3, r4}
    ldm r0!, {r2, r3}
    stm r1!, {r2, r3}
    ldr r2, lbl_0807548c @ =gSamusHazardDamage
    movs r4, #0xaa
    lsls r4, r4, #1
    adds r0, r6, r4
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r0, lbl_08075490 @ =gSamusEnvironmentalEffects
    movs r2, #0xae
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xb4
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r4, #0xba
    lsls r4, r4, #1
    adds r1, r6, r4
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r2, #0xc0
    lsls r2, r2, #1
    adds r1, r6, r2
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
    movs r3, #0xc6
    lsls r3, r3, #1
    adds r1, r6, r3
    ldm r1!, {r2, r3, r4}
    stm r0!, {r2, r3, r4}
lbl_08075470:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075478: .4byte gSamusData
lbl_0807547c: .4byte gSamusWeaponInfo
lbl_08075480: .4byte gSamusEcho
lbl_08075484: .4byte gScrewSpeedAnimation
lbl_08075488: .4byte gEquipment
lbl_0807548c: .4byte gSamusHazardDamage
lbl_08075490: .4byte gSamusEnvironmentalEffects

    thumb_func_start sub_08075494
sub_08075494: @ 0x08075494
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r5, lbl_080754c0 @ =0x02038000
    ldr r2, lbl_080754c4 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r4, lbl_080754c8 @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080754ae
    movs r0, #1
    strb r0, [r2]
    strb r1, [r4]
lbl_080754ae:
    ldrb r0, [r4]
    cmp r0, #4
    bhi lbl_08075588
    lsls r0, r0, #2
    ldr r1, lbl_080754cc @ =lbl_080754d0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080754c0: .4byte 0x02038000
lbl_080754c4: .4byte gDisableSoftreset
lbl_080754c8: .4byte gSramOperationStage
lbl_080754cc: .4byte lbl_080754d0
lbl_080754d0: @ jump table
    .4byte lbl_080754e4 @ case 0
    .4byte lbl_08075530 @ case 1
    .4byte lbl_0807553c @ case 2
    .4byte lbl_08075568 @ case 3
    .4byte lbl_08075588 @ case 4
lbl_080754e4:
    ldr r0, lbl_08075520 @ =0x03000c24
    lsls r2, r3, #1
    adds r2, r2, r3
    lsls r2, r2, #3
    adds r2, r2, r0
    adds r1, r2, #0
    ldr r0, lbl_08075524 @ =0x08760408
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldm r0!, {r4, r6, r7}
    stm r1!, {r4, r6, r7}
    ldr r0, lbl_08075528 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r2, #0x13]
    ldr r1, lbl_0807552c @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075520: .4byte 0x03000c24
lbl_08075524: .4byte 0x08760408
lbl_08075528: .4byte gLanguage
lbl_0807552c: .4byte 0x0000ffff
lbl_08075530:
    ldr r0, lbl_08075538 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #0
    b lbl_0807556e
    .align 2, 0
lbl_08075538: .4byte gMostRecentSaveFile
lbl_0807553c:
    ldr r1, lbl_08075560 @ =0x0000ffff
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    ldr r0, lbl_08075564 @ =0x000036e0
    adds r2, r2, r0
    adds r2, r5, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl BitFill
    b lbl_08075576
    .align 2, 0
lbl_08075560: .4byte 0x0000ffff
lbl_08075564: .4byte 0x000036e0
lbl_08075568:
    ldr r0, lbl_08075580 @ =gMostRecentSaveFile
    strb r3, [r0]
    movs r0, #1
lbl_0807556e:
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08075590
lbl_08075576:
    ldr r1, lbl_08075584 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_08075590
    .align 2, 0
lbl_08075580: .4byte gMostRecentSaveFile
lbl_08075584: .4byte gSramOperationStage
lbl_08075588:
    ldr r1, lbl_080755a0 @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r4]
lbl_08075590:
    ldr r0, lbl_080755a0 @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080755a0: .4byte gDisableSoftreset

    thumb_func_start sub_080755a4
sub_080755a4: @ 0x080755a4
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    ldr r6, lbl_080755d4 @ =0x02038000
    ldr r2, lbl_080755d8 @ =gDisableSoftreset
    ldrb r1, [r2]
    ldr r5, lbl_080755dc @ =gSramOperationStage
    cmp r1, #0
    bne lbl_080755c2
    movs r0, #1
    strb r0, [r2]
    strb r1, [r5]
lbl_080755c2:
    ldrb r0, [r5]
    cmp r0, #4
    bhi lbl_080756a4
    lsls r0, r0, #2
    ldr r1, lbl_080755e0 @ =lbl_080755e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080755d4: .4byte 0x02038000
lbl_080755d8: .4byte gDisableSoftreset
lbl_080755dc: .4byte gSramOperationStage
lbl_080755e0: .4byte lbl_080755e4
lbl_080755e4: @ jump table
    .4byte lbl_080755f8 @ case 0
    .4byte lbl_08075634 @ case 1
    .4byte lbl_08075640 @ case 2
    .4byte lbl_08075680 @ case 3
    .4byte lbl_080756a4 @ case 4
lbl_080755f8:
    ldr r2, lbl_08075630 @ =0x03000c24
    lsls r1, r3, #1
    adds r1, r1, r3
    lsls r1, r1, #3
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #3
    adds r1, r1, r2
    adds r0, r0, r2
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    ldm r0!, {r2, r5, r7}
    stm r1!, {r2, r5, r7}
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    adds r1, #0x80
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, #0x80
    b lbl_0807565c
    .align 2, 0
lbl_08075630: .4byte 0x03000c24
lbl_08075634:
    ldr r5, lbl_0807563c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #0
    b lbl_08075686
    .align 2, 0
lbl_0807563c: .4byte gMostRecentSaveFile
lbl_08075640:
    lsls r1, r4, #3
    adds r1, r1, r4
    lsls r1, r1, #4
    adds r1, r1, r4
    lsls r1, r1, #5
    ldr r0, lbl_08075678 @ =0x000036e0
    adds r1, r1, r0
    adds r1, r6, r1
    lsls r2, r3, #3
    adds r2, r2, r3
    lsls r2, r2, #4
    adds r2, r2, r3
    lsls r2, r2, #5
    adds r2, r2, r0
lbl_0807565c:
    adds r2, r6, r2
    movs r3, #0x91
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0807567c @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    b lbl_080756ac
    .align 2, 0
lbl_08075678: .4byte 0x000036e0
lbl_0807567c: .4byte gSramOperationStage
lbl_08075680:
    ldr r5, lbl_0807569c @ =gMostRecentSaveFile
    strb r3, [r5]
    movs r0, #1
lbl_08075686:
    bl sub_08000fbc
    cmp r0, #0
    beq lbl_08075696
    ldr r1, lbl_080756a0 @ =gSramOperationStage
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_08075696:
    strb r4, [r5]
    b lbl_080756ac
    .align 2, 0
lbl_0807569c: .4byte gMostRecentSaveFile
lbl_080756a0: .4byte gSramOperationStage
lbl_080756a4:
    ldr r1, lbl_080756bc @ =gDisableSoftreset
    movs r0, #0
    strb r0, [r1]
    strb r0, [r5]
lbl_080756ac:
    ldr r0, lbl_080756bc @ =gDisableSoftreset
    ldrb r1, [r0]
    movs r0, #1
    eors r0, r1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080756bc: .4byte gDisableSoftreset

    thumb_func_start sub_080756c0
sub_080756c0: @ 0x080756c0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0807574c @ =0x02038000
    movs r6, #0
    ldr r1, lbl_08075750 @ =0x03000c24
    adds r5, r0, #0
    adds r5, #0xbc
    adds r4, r0, #0
    adds r4, #0x98
    adds r3, r0, #0
    adds r3, #0x80
    movs r0, #0x91
    lsls r0, r0, #5
    mov ip, r0
    movs r7, #2
    mov r8, r7
lbl_080756e2:
    ldrb r0, [r4, #5]
    strb r0, [r1, #2]
    ldrb r2, [r1]
    cmp r2, #1
    bne lbl_08075756
    movs r7, #0xd1
    lsls r7, r7, #1
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #4]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #6]
    adds r7, #8
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #8]
    subs r7, #6
    adds r0, r3, r7
    ldrh r0, [r0]
    strh r0, [r1, #0xa]
    adds r7, #0x10
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xc]
    adds r7, #0x4e
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xd]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xe]
    adds r7, #1
    adds r0, r3, r7
    ldrb r0, [r0]
    strb r0, [r1, #0xf]
    ldrb r0, [r4, #4]
    strb r0, [r1, #0x10]
    ldrb r0, [r4]
    strb r0, [r1, #0x11]
    ldrb r0, [r4, #1]
    strb r0, [r1, #0x12]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_08075754
    strb r2, [r1, #0x14]
    b lbl_08075756
    .align 2, 0
lbl_0807574c: .4byte 0x02038000
lbl_08075750: .4byte 0x03000c24
lbl_08075754:
    strb r0, [r1, #0x14]
lbl_08075756:
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_08075762
    ldrb r0, [r1, #0x10]
    cmp r0, #0
    bne lbl_080757a4
lbl_08075762:
    strb r6, [r1]
    strb r6, [r1, #2]
    movs r2, #0
    strh r6, [r1, #4]
    strh r6, [r1, #6]
    strh r6, [r1, #8]
    strh r6, [r1, #0xa]
    strb r2, [r1, #0xc]
    strb r2, [r1, #0xd]
    strb r2, [r1, #0xe]
    strb r2, [r1, #0xf]
    ldr r0, lbl_080757c4 @ =gLanguage
    ldrb r0, [r0]
    strb r0, [r1, #0x13]
    movs r0, #0x12
    ldrsb r0, [r1, r0]
    cmp r0, #0
    beq lbl_080757a4
    movs r0, #5
    strb r0, [r1, #2]
    movs r0, #0x63
    strh r0, [r1, #4]
    strh r0, [r1, #6]
    strb r2, [r1, #0x14]
    ldrb r0, [r5]
    cmp r0, #2
    bls lbl_0807579a
    movs r0, #1
lbl_0807579a:
    strb r0, [r1, #0x14]
    ldrb r0, [r4, #2]
    strb r0, [r1, #0x13]
    ldrb r0, [r5, #2]
    strb r0, [r1, #0x15]
lbl_080757a4:
    adds r1, #0x18
    add r5, ip
    add r4, ip
    add r3, ip
    movs r0, #1
    rsbs r0, r0, #0
    add r8, r0
    mov r7, r8
    cmp r7, #0
    bge lbl_080756e2
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080757c4: .4byte gLanguage

    thumb_func_start sub_080757c8
sub_080757c8: @ 0x080757c8
    push {r4, lr}
    ldr r1, lbl_080757f4 @ =gMostRecentSaveFile
    movs r4, #0
    ldrsb r4, [r1, r4]
    strb r0, [r1]
    ldr r2, lbl_080757f8 @ =0x03000c24
    ldrb r1, [r1]
    lsls r1, r1, #0x18
    asrs r1, r1, #0x18
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #1]
    cmp r0, #4
    bhi lbl_08075828
    lsls r0, r0, #2
    ldr r1, lbl_080757fc @ =lbl_08075800
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080757f4: .4byte gMostRecentSaveFile
lbl_080757f8: .4byte 0x03000c24
lbl_080757fc: .4byte lbl_08075800
lbl_08075800: @ jump table
    .4byte lbl_08075828 @ case 0
    .4byte lbl_08075814 @ case 1
    .4byte lbl_0807581c @ case 2
    .4byte lbl_08075828 @ case 3
    .4byte lbl_08075828 @ case 4
lbl_08075814:
    movs r0, #3
    bl sub_08000c48
    b lbl_08075828
lbl_0807581c:
    movs r0, #3
    bl sub_08000c48
    movs r0, #4
    bl sub_08000c48
lbl_08075828:
    ldr r3, lbl_08075844 @ =0x03000c24
    ldr r2, lbl_08075848 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r2, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r3
    movs r1, #0
    strb r1, [r0, #1]
    strb r4, [r2]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075844: .4byte 0x03000c24
lbl_08075848: .4byte gMostRecentSaveFile

    thumb_func_start sub_0807584c
sub_0807584c: @ 0x0807584c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r2, lbl_08075880 @ =gButtonAssignments
    ldr r0, lbl_08075884 @ =0x08411510
    ldr r1, [r0, #4]
    ldr r0, [r0]
    str r0, [r2]
    str r1, [r2, #4]
    ldr r7, lbl_08075888 @ =gMaxInGameTimerFlag
    movs r1, #0
    strb r1, [r7]
    ldr r0, lbl_0807588c @ =gShipLandingFlag
    strb r1, [r0]
    ldr r0, lbl_08075890 @ =gColorFading
    movs r5, #0
    movs r6, #2
    strb r6, [r0]
    cmp r4, #1
    beq lbl_080758b4
    cmp r4, #1
    bgt lbl_08075894
    cmp r4, #0
    beq lbl_0807589e
    b lbl_08075918
    .align 2, 0
lbl_08075880: .4byte gButtonAssignments
lbl_08075884: .4byte 0x08411510
lbl_08075888: .4byte gMaxInGameTimerFlag
lbl_0807588c: .4byte gShipLandingFlag
lbl_08075890: .4byte gColorFading
lbl_08075894:
    cmp r4, #2
    beq lbl_08075918
    cmp r4, #3
    beq lbl_080758f4
    b lbl_08075918
lbl_0807589e:
    ldr r1, lbl_080758ac @ =0x03000c6c
    ldr r0, lbl_080758b0 @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl check_load_save_file
    b lbl_08075914
    .align 2, 0
lbl_080758ac: .4byte 0x03000c6c
lbl_080758b0: .4byte 0x08411524
lbl_080758b4:
    ldr r1, lbl_080758d8 @ =0x03000c6c
    ldr r0, lbl_080758dc @ =0x08411524
    ldr r0, [r0]
    str r0, [r1]
    bl init_save_file
    ldr r0, lbl_080758e0 @ =gCurrentRoom
    strb r5, [r0]
    ldr r0, lbl_080758e4 @ =gLastDoorUsed
    strb r5, [r0]
    strb r4, [r7]
    ldr r0, lbl_080758e8 @ =gSkipDoorTransition
    strb r5, [r0]
    ldr r0, lbl_080758ec @ =gDebugFlag
    strb r5, [r0]
    ldr r0, lbl_080758f0 @ =gLanguage
    strb r6, [r0]
    b lbl_08075914
    .align 2, 0
lbl_080758d8: .4byte 0x03000c6c
lbl_080758dc: .4byte 0x08411524
lbl_080758e0: .4byte gCurrentRoom
lbl_080758e4: .4byte gLastDoorUsed
lbl_080758e8: .4byte gSkipDoorTransition
lbl_080758ec: .4byte gDebugFlag
lbl_080758f0: .4byte gLanguage
lbl_080758f4:
    ldr r3, lbl_08075940 @ =gIsLoadingFile
    ldr r2, lbl_08075944 @ =0x03000c24
    ldr r0, lbl_08075948 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    strb r0, [r3]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08075914
    bl sub_0807478c
lbl_08075914:
    ldr r0, lbl_0807594c @ =gCurrentCutscene
    strb r5, [r0]
lbl_08075918:
    ldr r0, lbl_08075950 @ =gGameModeSub3
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_08075954 @ =gMonochromeBgFading
    strb r1, [r0]
    ldr r0, lbl_08075958 @ =gDisableSoftreset
    strb r1, [r0]
    ldr r0, lbl_0807595c @ =gSubGameModeStage
    strb r1, [r0]
    ldr r0, lbl_08075960 @ =gPauseScreenFlag
    strb r1, [r0]
    ldr r0, lbl_08075964 @ =gDisablePause
    strb r1, [r0]
    ldr r1, lbl_08075968 @ =gSamusDoorPositionOffset
    movs r0, #0
    strh r0, [r1]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075940: .4byte gIsLoadingFile
lbl_08075944: .4byte 0x03000c24
lbl_08075948: .4byte gMostRecentSaveFile
lbl_0807594c: .4byte gCurrentCutscene
lbl_08075950: .4byte gGameModeSub3
lbl_08075954: .4byte gMonochromeBgFading
lbl_08075958: .4byte gDisableSoftreset
lbl_0807595c: .4byte gSubGameModeStage
lbl_08075960: .4byte gPauseScreenFlag
lbl_08075964: .4byte gDisablePause
lbl_08075968: .4byte gSamusDoorPositionOffset

    thumb_func_start check_load_save_file
check_load_save_file: @ 0x0807596c
    push {r4, r5, r6, lr}
    ldr r2, lbl_08075a10 @ =gIsLoadingFile
    ldr r6, lbl_08075a14 @ =0x03000c24
    ldr r5, lbl_08075a18 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0]
    strb r0, [r2]
    lsls r0, r0, #0x18
    asrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_08075a4c
    bl init_save_file
    ldr r1, lbl_08075a1c @ =gColorFading
    movs r0, #0x15
    strb r0, [r1]
    ldr r0, lbl_08075a20 @ =gEquipment
    strb r4, [r0, #0x10]
    ldr r2, lbl_08075a24 @ =gCurrentArea
    ldr r0, lbl_08075a28 @ =0x03000c6c
    ldrb r1, [r0]
    strb r1, [r2]
    ldr r0, lbl_08075a2c @ =gAreaBeforeTransition
    strb r1, [r0]
    ldr r0, lbl_08075a30 @ =gCurrentRoom
    strb r4, [r0]
    ldr r0, lbl_08075a34 @ =gLastDoorUsed
    strb r4, [r0]
    ldr r2, lbl_08075a38 @ =gGameCompletion
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x11]
    strb r0, [r2]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x12]
    strb r0, [r2, #1]
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x13]
    strb r0, [r2, #2]
    ldr r2, lbl_08075a3c @ =gDifficulty
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x14]
    strb r0, [r2]
    ldr r2, lbl_08075a40 @ =gTimeAttackFlag
    movs r1, #0
    ldrsb r1, [r5, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r6
    ldrb r0, [r0, #0x15]
    strb r0, [r2]
    ldr r0, lbl_08075a44 @ =gUseMotherShipDoors
    strb r4, [r0]
    ldr r1, lbl_08075a48 @ =gShipLandingFlag
    movs r0, #1
    strb r0, [r1]
    b lbl_08075a50
    .align 2, 0
lbl_08075a10: .4byte gIsLoadingFile
lbl_08075a14: .4byte 0x03000c24
lbl_08075a18: .4byte gMostRecentSaveFile
lbl_08075a1c: .4byte gColorFading
lbl_08075a20: .4byte gEquipment
lbl_08075a24: .4byte gCurrentArea
lbl_08075a28: .4byte 0x03000c6c
lbl_08075a2c: .4byte gAreaBeforeTransition
lbl_08075a30: .4byte gCurrentRoom
lbl_08075a34: .4byte gLastDoorUsed
lbl_08075a38: .4byte gGameCompletion
lbl_08075a3c: .4byte gDifficulty
lbl_08075a40: .4byte gTimeAttackFlag
lbl_08075a44: .4byte gUseMotherShipDoors
lbl_08075a48: .4byte gShipLandingFlag
lbl_08075a4c:
    bl sub_0807478c
lbl_08075a50:
    ldr r3, lbl_08075a7c @ =gGameCompletion
    ldr r2, lbl_08075a80 @ =0x03000c24
    ldr r0, lbl_08075a84 @ =gMostRecentSaveFile
    movs r1, #0
    ldrsb r1, [r0, r1]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r1, [r0, #0x13]
    movs r2, #0
    strb r1, [r3, #2]
    ldr r0, lbl_08075a88 @ =gLanguage
    strb r1, [r0]
    ldr r0, lbl_08075a8c @ =gSkipDoorTransition
    strb r2, [r0]
    ldr r0, lbl_08075a90 @ =gDebugFlag
    strb r2, [r0]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075a7c: .4byte gGameCompletion
lbl_08075a80: .4byte 0x03000c24
lbl_08075a84: .4byte gMostRecentSaveFile
lbl_08075a88: .4byte gLanguage
lbl_08075a8c: .4byte gSkipDoorTransition
lbl_08075a90: .4byte gDebugFlag

    thumb_func_start init_save_file
init_save_file: @ 0x08075a94
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r2, lbl_08075ba8 @ =0x02037400
    movs r6, #0x80
    lsls r6, r6, #4
    movs r5, #0x10
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    ldr r4, lbl_08075bac @ =0x0000ffff
    ldr r2, lbl_08075bb0 @ =0x02035c00
    movs r3, #0x80
    lsls r3, r3, #5
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bb4 @ =0x02036c00
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    adds r3, r6, #0
    bl BitFill
    ldr r2, lbl_08075bb8 @ =0x02037c00
    movs r3, #0x80
    lsls r3, r3, #2
    str r5, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl BitFill
    ldr r2, lbl_08075bbc @ =0x02037e00
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    movs r3, #0x20
    bl BitFill
    ldr r2, lbl_08075bc0 @ =0x02033800
    str r5, [sp]
    movs r0, #3
    movs r1, #0
    adds r3, r6, #0
    bl BitFill
    movs r1, #0
    ldr r4, lbl_08075bc4 @ =gNumberOfNeverReformBlocks
    movs r2, #0
    ldr r3, lbl_08075bc8 @ =gNumberOfItemsCollected
lbl_08075b08:
    adds r0, r1, r4
    strb r2, [r0]
    adds r0, r1, r3
    strb r2, [r0]
    adds r1, #1
    cmp r1, #7
    ble lbl_08075b08
    ldr r1, lbl_08075bcc @ =gInGameTimer
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    str r0, [r1]
    ldr r0, lbl_08075bd4 @ =gDisableDrawingSamusAndScrolling
    mov r8, r0
    ldr r1, lbl_08075bd8 @ =gDifficulty
    mov sl, r1
    ldr r2, lbl_08075bdc @ =gIsLoadingFile
    mov sb, r2
    ldr r2, lbl_08075be0 @ =0x03000154
    ldr r0, lbl_08075be4 @ =0x0841151c
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x2c
lbl_08075b34:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b34
    ldr r2, lbl_08075be8 @ =gInGameTimerAtBosses
    ldr r0, lbl_08075bd0 @ =0x08411518
    ldr r0, [r0]
    adds r1, r2, #0
    adds r1, #0x10
lbl_08075b46:
    str r0, [r1]
    subs r1, #4
    cmp r1, r2
    bge lbl_08075b46
    movs r1, #0
    ldr r0, lbl_08075bec @ =0x083602e8
    mov ip, r0
    ldr r7, lbl_08075bf0 @ =gInGameCutscenesTriggered
lbl_08075b56:
    movs r3, #0
    movs r4, #0
    adds r6, r1, #1
    lsls r5, r1, #2
    lsls r0, r1, #8
    mov r1, ip
    adds r2, r0, r1
lbl_08075b64:
    ldrb r1, [r2]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
    lsls r0, r3
    orrs r4, r0
    adds r2, #8
    adds r3, #1
    cmp r3, #0x1f
    ble lbl_08075b64
    adds r0, r5, r7
    str r4, [r0]
    adds r1, r6, #0
    cmp r1, #0
    ble lbl_08075b56
    movs r1, #0
    mov r2, r8
    strb r1, [r2]
    movs r0, #1
    mov r2, sl
    strb r0, [r2]
    ldr r0, lbl_08075bf4 @ =gTimeAttackFlag
    strb r1, [r0]
    mov r2, sb
    strb r1, [r2]
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08075ba8: .4byte 0x02037400
lbl_08075bac: .4byte 0x0000ffff
lbl_08075bb0: .4byte 0x02035c00
lbl_08075bb4: .4byte 0x02036c00
lbl_08075bb8: .4byte 0x02037c00
lbl_08075bbc: .4byte 0x02037e00
lbl_08075bc0: .4byte 0x02033800
lbl_08075bc4: .4byte gNumberOfNeverReformBlocks
lbl_08075bc8: .4byte gNumberOfItemsCollected
lbl_08075bcc: .4byte gInGameTimer
lbl_08075bd0: .4byte 0x08411518
lbl_08075bd4: .4byte gDisableDrawingSamusAndScrolling
lbl_08075bd8: .4byte gDifficulty
lbl_08075bdc: .4byte gIsLoadingFile
lbl_08075be0: .4byte 0x03000154
lbl_08075be4: .4byte 0x0841151c
lbl_08075be8: .4byte gInGameTimerAtBosses
lbl_08075bec: .4byte 0x083602e8
lbl_08075bf0: .4byte gInGameCutscenesTriggered
lbl_08075bf4: .4byte gTimeAttackFlag
lbl_08075bf8:
    .byte 0x81, 0xB0, 0x69, 0x46, 0x00, 0x20, 0x08, 0x70
    .byte 0x01, 0xB0, 0x70, 0x47

    thumb_func_start sub_08075c04
sub_08075c04: @ 0x08075c04
    push {r4, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x18
    lsrs r4, r4, #0x18
    ldr r0, lbl_08075c28 @ =0x08075bf9
    bl CallbackSetVBlank
    adds r0, r4, #0
    bl sub_0807584c
    ldr r0, lbl_08075c2c @ =gIsLoadingFile
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08075c28: .4byte 0x08075bf9
lbl_08075c2c: .4byte gIsLoadingFile
