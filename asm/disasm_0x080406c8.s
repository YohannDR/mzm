    .include "asm/macros.inc"

    .syntax unified
    
    thumb_func_start Zebetite
Zebetite: @ 0x080406c8
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_080406f0 @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x24
    ldrb r0, [r0]
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_080406da
    b lbl_080407dc
lbl_080406da:
    movs r4, #0
    ldrh r1, [r5]
    ldr r0, lbl_080406f4 @ =0x0000fffb
    ands r0, r1
    strh r0, [r5]
    ldrb r0, [r5, #0x1d]
    cmp r0, #0x7d
    beq lbl_080406f8
    cmp r0, #0x87
    beq lbl_08040720
    b lbl_0804074a
    .align 2, 0
lbl_080406f0: .4byte 0x03000738
lbl_080406f4: .4byte 0x0000fffb
lbl_080406f8:
    movs r0, #3
    movs r1, #0x3d
    bl EventFunction
    cmp r0, #0
    beq lbl_08040744
    ldr r1, lbl_0804071c @ =0xfffffb00
    adds r0, r1, #0
    ldrh r1, [r5, #4]
    adds r0, r0, r1
    strh r0, [r5, #4]
    movs r0, #3
    movs r1, #0x3f
    bl EventFunction
    cmp r0, #0
    beq lbl_08040744
    b lbl_0804074a
    .align 2, 0
lbl_0804071c: .4byte 0xfffffb00
lbl_08040720:
    movs r0, #3
    movs r1, #0x3e
    bl EventFunction
    cmp r0, #0
    beq lbl_08040744
    ldr r1, lbl_08040750 @ =0xfffffb00
    adds r0, r1, #0
    ldrh r1, [r5, #4]
    adds r0, r0, r1
    strh r0, [r5, #4]
    movs r0, #3
    movs r1, #0x40
    bl EventFunction
    cmp r0, #0
    beq lbl_08040744
    movs r4, #1
lbl_08040744:
    ldr r5, lbl_08040754 @ =0x03000738
    cmp r4, #0
    beq lbl_08040758
lbl_0804074a:
    movs r0, #0
    strh r0, [r5]
    b lbl_080409ce
    .align 2, 0
lbl_08040750: .4byte 0xfffffb00
lbl_08040754: .4byte 0x03000738
lbl_08040758:
    adds r1, r5, #0
    adds r1, #0x27
    movs r0, #0x30
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x28
    strb r4, [r0]
    adds r1, #2
    movs r0, #8
    strb r0, [r1]
    movs r1, #0
    ldr r0, lbl_080407c4 @ =0x0000ff40
    strh r0, [r5, #0xa]
    strh r4, [r5, #0xc]
    adds r0, #0xa0
    strh r0, [r5, #0xe]
    movs r0, #0x20
    strh r0, [r5, #0x10]
    adds r2, r5, #0
    adds r2, #0x33
    movs r0, #1
    strb r0, [r2]
    subs r2, #0xe
    movs r0, #0xc
    strb r0, [r2]
    ldr r0, lbl_080407c8 @ =0x082fe974
    str r0, [r5, #0x18]
    strb r1, [r5, #0x1c]
    strh r4, [r5, #0x16]
    adds r1, r5, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r2, lbl_080407cc @ =0x082b0d68
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r5, #0x14]
    strh r0, [r5, #0x12]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #9
    strb r0, [r1]
    ldr r0, lbl_080407d0 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080407d4
    adds r1, #8
    movs r0, #0x3c
    b lbl_080407da
    .align 2, 0
lbl_080407c4: .4byte 0x0000ff40
lbl_080407c8: .4byte 0x082fe974
lbl_080407cc: .4byte 0x082b0d68
lbl_080407d0: .4byte 0x0300002c
lbl_080407d4:
    adds r1, r5, #0
    adds r1, #0x2c
    movs r0, #0x1e
lbl_080407da:
    strb r0, [r1]
lbl_080407dc:
    ldr r2, lbl_0804081c @ =0x082b0d68
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r6, [r0]
    ldrh r4, [r5, #0x14]
    subs r0, r6, r4
    movs r1, #0x14
    bl __divsi3
    adds r2, r0, #0
    ldrh r0, [r5, #0x12]
    cmp r4, r0
    bne lbl_08040820
    cmp r2, #0
    bne lbl_08040802
    b lbl_080409ce
lbl_08040802:
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_08040814
    b lbl_080409ce
lbl_08040814:
    ldrh r0, [r5, #0x14]
    adds r0, #0x14
    strh r0, [r5, #0x14]
    b lbl_080409ce
    .align 2, 0
lbl_0804081c: .4byte 0x082b0d68
lbl_08040820:
    cmp r4, r6
    bhs lbl_08040840
    ldr r0, lbl_08040834 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08040838
    adds r1, r5, #0
    adds r1, #0x2c
    movs r0, #0x3c
    b lbl_0804083e
    .align 2, 0
lbl_08040834: .4byte 0x0300002c
lbl_08040838:
    adds r1, r5, #0
    adds r1, #0x2c
    movs r0, #0x1e
lbl_0804083e:
    strb r0, [r1]
lbl_08040840:
    adds r4, r5, #0
    ldrh r0, [r4, #0x14]
    movs r7, #0
    movs r6, #0
    strh r0, [r4, #0x12]
    cmp r2, #6
    bls lbl_08040850
    b lbl_0804094c
lbl_08040850:
    lsls r0, r2, #2
    ldr r1, lbl_0804085c @ =lbl_08040860
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804085c: .4byte lbl_08040860
lbl_08040860: @ jump table
    .4byte lbl_0804087c @ case 0
    .4byte lbl_08040894 @ case 1
    .4byte lbl_08040894 @ case 2
    .4byte lbl_080408dc @ case 3
    .4byte lbl_080408dc @ case 4
    .4byte lbl_0804092c @ case 5
    .4byte lbl_0804092c @ case 6
lbl_0804087c:
    ldr r0, [r5, #0x18]
    ldr r4, lbl_0804088c @ =0x082fe974
    cmp r0, r4
    bne lbl_08040886
    b lbl_080409ce
lbl_08040886:
    ldr r0, lbl_08040890 @ =0x00000266
    b lbl_08040936
    .align 2, 0
lbl_0804088c: .4byte 0x082fe974
lbl_08040890: .4byte 0x00000266
lbl_08040894:
    ldr r1, [r5, #0x18]
    ldr r0, lbl_080408ac @ =0x082fe9ac
    cmp r1, r0
    bne lbl_0804089e
    b lbl_080409ce
lbl_0804089e:
    ldr r0, lbl_080408b0 @ =0x082fe974
    cmp r1, r0
    bne lbl_080408b8
    ldr r0, lbl_080408b4 @ =0x00000265
    bl SoundPlayNotAlreadyPlaying
    b lbl_080408c4
    .align 2, 0
lbl_080408ac: .4byte 0x082fe9ac
lbl_080408b0: .4byte 0x082fe974
lbl_080408b4: .4byte 0x00000265
lbl_080408b8:
    ldr r0, lbl_080408cc @ =0x082fe9e4
    cmp r1, r0
    bne lbl_080408c4
    ldr r0, lbl_080408d0 @ =0x00000266
    bl SoundPlayNotAlreadyPlaying
lbl_080408c4:
    ldr r0, lbl_080408d4 @ =0x03000738
    ldr r1, lbl_080408d8 @ =0x082fe9ac
    b lbl_08040910
    .align 2, 0
lbl_080408cc: .4byte 0x082fe9e4
lbl_080408d0: .4byte 0x00000266
lbl_080408d4: .4byte 0x03000738
lbl_080408d8: .4byte 0x082fe9ac
lbl_080408dc:
    ldr r1, [r5, #0x18]
    ldr r0, lbl_080408f4 @ =0x082fe9e4
    cmp r1, r0
    beq lbl_080409ce
    ldr r0, lbl_080408f8 @ =0x082fe9ac
    cmp r1, r0
    bne lbl_08040900
    ldr r0, lbl_080408fc @ =0x00000265
    bl SoundPlayNotAlreadyPlaying
    b lbl_0804090c
    .align 2, 0
lbl_080408f4: .4byte 0x082fe9e4
lbl_080408f8: .4byte 0x082fe9ac
lbl_080408fc: .4byte 0x00000265
lbl_08040900:
    ldr r0, lbl_0804091c @ =0x082fea1c
    cmp r1, r0
    bne lbl_0804090c
    ldr r0, lbl_08040920 @ =0x00000266
    bl SoundPlayNotAlreadyPlaying
lbl_0804090c:
    ldr r0, lbl_08040924 @ =0x03000738
    ldr r1, lbl_08040928 @ =0x082fe9e4
lbl_08040910:
    str r1, [r0, #0x18]
    movs r1, #0
    strb r1, [r0, #0x1c]
    strh r1, [r0, #0x16]
    b lbl_080409ce
    .align 2, 0
lbl_0804091c: .4byte 0x082fea1c
lbl_08040920: .4byte 0x00000266
lbl_08040924: .4byte 0x03000738
lbl_08040928: .4byte 0x082fe9e4
lbl_0804092c:
    ldr r0, [r5, #0x18]
    ldr r4, lbl_08040944 @ =0x082fea1c
    cmp r0, r4
    beq lbl_080409ce
    ldr r0, lbl_08040948 @ =0x00000265
lbl_08040936:
    bl SoundPlayNotAlreadyPlaying
    str r4, [r5, #0x18]
    movs r0, #0
    strb r0, [r5, #0x1c]
    strh r0, [r5, #0x16]
    b lbl_080409ce
    .align 2, 0
lbl_08040944: .4byte 0x082fea1c
lbl_08040948: .4byte 0x00000265
lbl_0804094c:
    ldrh r0, [r4, #2]
    subs r0, #0x48
    ldrh r1, [r4, #4]
    movs r2, #0x22
    bl ParticleSet
    ldr r0, lbl_0804096c @ =0x0000012f
    bl SoundPlay
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x7d
    beq lbl_08040970
    cmp r0, #0x87
    beq lbl_080409a0
    strh r6, [r4]
    b lbl_080409ce
    .align 2, 0
lbl_0804096c: .4byte 0x0000012f
lbl_08040970:
    movs r0, #3
    movs r1, #0x3d
    bl EventFunction
    cmp r0, #0
    bne lbl_08040994
    ldrh r0, [r4]
    movs r1, #4
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x24
    strb r7, [r0]
    movs r0, #1
    movs r1, #0x3d
    bl EventFunction
    b lbl_080409ce
lbl_08040994:
    strh r6, [r4]
    movs r0, #1
    movs r1, #0x3f
    bl EventFunction
    b lbl_080409ce
lbl_080409a0:
    movs r0, #3
    movs r1, #0x3e
    bl EventFunction
    cmp r0, #0
    bne lbl_080409c4
    ldrh r0, [r4]
    movs r1, #4
    orrs r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x24
    strb r7, [r0]
    movs r0, #1
    movs r1, #0x3e
    bl EventFunction
    b lbl_080409ce
lbl_080409c4:
    strh r6, [r5]
    movs r0, #1
    movs r1, #0x40
    bl EventFunction
lbl_080409ce:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start CannonFireBullet
CannonFireBullet: @ 0x080409d4
    push {r4, lr}
    sub sp, #0xc
    ldr r0, lbl_08040a1c @ =0x03000738
    mov ip, r0
    ldrh r1, [r0]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08040a14
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #1
    bne lbl_08040a14
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_08040a14
    mov r0, ip
    adds r0, #0x2d
    ldrb r1, [r0]
    mov r4, ip
    ldrb r2, [r4, #0x1f]
    subs r0, #0xa
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    str r0, [sp]
    ldrh r0, [r4, #4]
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x27
    bl SpriteSpawnSecondary
lbl_08040a14:
    add sp, #0xc
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08040a1c: .4byte 0x03000738

    thumb_func_start sub_08040a20
sub_08040a20: @ 0x08040a20
    push {r4, r5, r6, lr}
    ldr r0, lbl_08040a64 @ =0x0300083c
    ldrb r5, [r0]
    ldr r4, lbl_08040a68 @ =0x03000738
    lsls r0, r5, #3
    adds r0, #0xa
    adds r1, r4, #0
    adds r1, #0x2c
    movs r2, #0
    strb r0, [r1]
    strb r2, [r4, #0x1c]
    movs r6, #0
    strh r2, [r4, #0x16]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    adds r1, #0x40
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_08040a74
    ldrh r1, [r4]
    ldr r0, lbl_08040a6c @ =0x0000fdff
    ands r0, r1
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #2
    strb r0, [r1]
    adds r1, #2
    strb r0, [r1]
    ldr r0, lbl_08040a70 @ =0x082fea94
    str r0, [r4, #0x18]
    b lbl_08040afa
    .align 2, 0
lbl_08040a64: .4byte 0x0300083c
lbl_08040a68: .4byte 0x03000738
lbl_08040a6c: .4byte 0x0000fdff
lbl_08040a70: .4byte 0x082fea94
lbl_08040a74:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    subs r1, #0x40
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_08040aa8
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #6
    strb r0, [r1]
    adds r1, #2
    movs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08040aa4 @ =0x082feb14
    str r0, [r4, #0x18]
    b lbl_08040afa
    .align 2, 0
lbl_08040aa4: .4byte 0x082feb14
lbl_08040aa8:
    movs r0, #1
    ands r0, r5
    cmp r0, #0
    beq lbl_08040abc
    ldrh r1, [r4]
    ldr r0, lbl_08040ab8 @ =0x0000fdff
    ands r0, r1
    b lbl_08040ac6
    .align 2, 0
lbl_08040ab8: .4byte 0x0000fdff
lbl_08040abc:
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
lbl_08040ac6:
    strh r0, [r4]
    cmp r5, #7
    bls lbl_08040ae4
    ldr r0, lbl_08040adc @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x2d
    movs r1, #6
    strb r1, [r2]
    ldr r1, lbl_08040ae0 @ =0x082feb14
    b lbl_08040af0
    .align 2, 0
lbl_08040adc: .4byte 0x03000738
lbl_08040ae0: .4byte 0x082feb14
lbl_08040ae4:
    ldr r0, lbl_08040b00 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x2d
    movs r1, #2
    strb r1, [r2]
    ldr r1, lbl_08040b04 @ =0x082fea94
lbl_08040af0:
    str r1, [r0, #0x18]
    adds r1, r0, #0
    adds r1, #0x2f
    movs r0, #0
    strb r0, [r1]
lbl_08040afa:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08040b00: .4byte 0x03000738
lbl_08040b04: .4byte 0x082fea94

    thumb_func_start Cannon
Cannon: @ 0x08040b08
    push {r4, r5, r6, r7, lr}
    ldr r4, lbl_08040b3c @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x26
    movs r5, #1
    strb r5, [r0]
    movs r0, #3
    movs r1, #0x27
    bl EventFunction
    cmp r0, #0
    beq lbl_08040b40
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08040b34
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x1f
    bl ParticleSet
lbl_08040b34:
    movs r0, #0
    strh r0, [r4]
    b lbl_08041112
    .align 2, 0
lbl_08040b3c: .4byte 0x03000738
lbl_08040b40:
    ldr r0, lbl_08040ba4 @ =0x0300083c
    ldrb r7, [r0]
    adds r3, r4, #0
    adds r3, #0x24
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_08040bb0
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r2, #0
    ldr r1, lbl_08040ba8 @ =0x0000fffc
    strh r1, [r4, #0xa]
    movs r0, #4
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r0, r4, #0
    adds r0, #0x33
    strb r5, [r0]
    subs r0, #0xe
    strb r2, [r0]
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    ldr r0, lbl_08040bac @ =0x03000088
    ldrb r1, [r0, #0xc]
    movs r0, #3
    ands r0, r1
    adds r1, r4, #0
    adds r1, #0x21
    strb r0, [r1]
    movs r0, #9
    strb r0, [r3]
    ldrh r0, [r4, #2]
    subs r0, #0x20
    strh r0, [r4, #2]
    bl sub_08040a20
    ldrh r0, [r4, #2]
    strh r0, [r4, #6]
    ldrh r0, [r4, #4]
    strh r0, [r4, #8]
    b lbl_08041112
    .align 2, 0
lbl_08040ba4: .4byte 0x0300083c
lbl_08040ba8: .4byte 0x0000fffc
lbl_08040bac: .4byte 0x03000088
lbl_08040bb0:
    ldrh r6, [r4, #6]
    ldrh r2, [r4, #8]
    ldr r0, lbl_08040bc8 @ =0x030013d4
    ldrh r1, [r0, #0x12]
    ldrb r0, [r4, #0x1d]
    cmp r0, #0x88
    beq lbl_08040c24
    cmp r0, #0x88
    bgt lbl_08040bcc
    cmp r0, #0x7e
    beq lbl_08040bd2
    b lbl_08040d06
    .align 2, 0
lbl_08040bc8: .4byte 0x030013d4
lbl_08040bcc:
    cmp r0, #0x89
    beq lbl_08040c8c
    b lbl_08040d06
lbl_08040bd2:
    movs r5, #0x14
    ldrh r3, [r4]
    movs r6, #0x80
    lsls r6, r6, #4
    adds r0, r6, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08040c08
    ldr r6, lbl_08040c00 @ =0xfffffb00
    adds r0, r2, r6
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, r1
    bhs lbl_08040c80
    subs r1, r1, r2
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040c80
    ldr r0, lbl_08040c04 @ =0x0000f7ff
    ands r0, r3
    strh r0, [r4]
    ldrh r0, [r4, #8]
    b lbl_08040c72
    .align 2, 0
lbl_08040c00: .4byte 0xfffffb00
lbl_08040c04: .4byte 0x0000f7ff
lbl_08040c08:
    cmp r1, r2
    bhs lbl_08040c80
    subs r1, r2, r1
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040c80
    adds r0, r6, #0
    orrs r0, r3
    strh r0, [r4]
    ldr r1, lbl_08040c20 @ =0xfffffb00
    b lbl_08040c70
    .align 2, 0
lbl_08040c20: .4byte 0xfffffb00
lbl_08040c24:
    movs r5, #0x18
    ldrh r3, [r4]
    movs r6, #0x80
    lsls r6, r6, #4
    adds r0, r6, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08040c5c
    ldr r6, lbl_08040c54 @ =0xfffffa00
    adds r0, r2, r6
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    cmp r2, r1
    bhs lbl_08040c80
    subs r1, r1, r2
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040c80
    ldr r0, lbl_08040c58 @ =0x0000f7ff
    ands r0, r3
    strh r0, [r4]
    ldrh r0, [r4, #8]
    b lbl_08040c72
    .align 2, 0
lbl_08040c54: .4byte 0xfffffa00
lbl_08040c58: .4byte 0x0000f7ff
lbl_08040c5c:
    cmp r1, r2
    bhs lbl_08040c80
    subs r1, r2, r1
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040c80
    adds r0, r6, #0
    orrs r0, r3
    strh r0, [r4]
    ldr r1, lbl_08040c7c @ =0xfffffa00
lbl_08040c70:
    adds r0, r2, r1
lbl_08040c72:
    strh r0, [r4, #4]
    bl sub_08040a20
    b lbl_08040d06
    .align 2, 0
lbl_08040c7c: .4byte 0xfffffa00
lbl_08040c80:
    ldr r0, lbl_08040c88 @ =0x03000738
    strh r2, [r0, #4]
    b lbl_08040d06
    .align 2, 0
lbl_08040c88: .4byte 0x03000738
lbl_08040c8c:
    movs r5, #0x18
    ldrh r3, [r4]
    movs r0, #0x80
    lsls r0, r0, #4
    mov ip, r0
    ands r0, r3
    cmp r0, #0
    beq lbl_08040cd8
    ldr r0, lbl_08040cc0 @ =0xfffffa00
    adds r2, r2, r0
    lsls r0, r2, #0x10
    lsrs r2, r0, #0x10
    cmp r2, r1
    bhs lbl_08040cc8
    subs r1, r1, r2
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040cc8
    ldr r0, lbl_08040cc4 @ =0x0000f7ff
    ands r0, r3
    strh r0, [r4]
    ldrh r0, [r4, #8]
    strh r0, [r4, #4]
    ldrh r0, [r4, #6]
    b lbl_08040cf4
    .align 2, 0
lbl_08040cc0: .4byte 0xfffffa00
lbl_08040cc4: .4byte 0x0000f7ff
lbl_08040cc8:
    ldr r1, lbl_08040cd4 @ =0x03000738
    strh r2, [r1, #4]
    adds r0, r6, #0
    subs r0, #0x40
    strh r0, [r1, #2]
    b lbl_08040d06
    .align 2, 0
lbl_08040cd4: .4byte 0x03000738
lbl_08040cd8:
    cmp r1, r2
    bhs lbl_08040d00
    subs r1, r2, r1
    lsls r0, r5, #5
    cmp r1, r0
    ble lbl_08040d00
    mov r0, ip
    orrs r0, r3
    strh r0, [r4]
    ldr r1, lbl_08040cfc @ =0xfffffa00
    adds r0, r2, r1
    strh r0, [r4, #4]
    adds r0, r6, #0
    subs r0, #0x40
lbl_08040cf4:
    strh r0, [r4, #2]
    bl sub_08040a20
    b lbl_08040d06
    .align 2, 0
lbl_08040cfc: .4byte 0xfffffa00
lbl_08040d00:
    ldr r0, lbl_08040d1c @ =0x03000738
    strh r2, [r0, #4]
    strh r6, [r0, #2]
lbl_08040d06:
    ldr r0, lbl_08040d1c @ =0x03000738
    adds r0, #0x2d
    ldrb r0, [r0]
    cmp r0, #8
    bls lbl_08040d12
    b lbl_08041112
lbl_08040d12:
    lsls r0, r0, #2
    ldr r1, lbl_08040d20 @ =lbl_08040d24
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08040d1c: .4byte 0x03000738
lbl_08040d20: .4byte lbl_08040d24
lbl_08040d24: @ jump table
    .4byte lbl_08040d48 @ case 0
    .4byte lbl_08040db8 @ case 1
    .4byte lbl_08040e0c @ case 2
    .4byte lbl_08040e88 @ case 3
    .4byte lbl_08040edc @ case 4
    .4byte lbl_08040f70 @ case 5
    .4byte lbl_08040fc4 @ case 6
    .4byte lbl_0804104c @ case 7
    .4byte lbl_080410b0 @ case 8
lbl_08040d48:
    ldr r4, lbl_08040d68 @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08040d6c @ =0x082fea64
    cmp r1, r0
    bne lbl_08040d78
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08040d74
    ldr r0, lbl_08040d70 @ =0x082fea54
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08040d78
    .align 2, 0
lbl_08040d68: .4byte 0x03000738
lbl_08040d6c: .4byte 0x082fea64
lbl_08040d70: .4byte 0x082fea54
lbl_08040d74:
    bl CannonFireBullet
lbl_08040d78:
    ldr r2, lbl_08040db0 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08040d8e
    b lbl_08041112
lbl_08040d8e:
    movs r0, #0x42
    strb r0, [r3]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, lbl_08040db4 @ =0x082fea84
    str r0, [r2, #0x18]
    ldrh r1, [r2]
    movs r3, #0x80
    lsls r3, r3, #2
    adds r0, r3, #0
    orrs r0, r1
    b lbl_08041110
    .align 2, 0
lbl_08040db0: .4byte 0x03000738
lbl_08040db4: .4byte 0x082fea84
lbl_08040db8:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_08040dc2
    b lbl_08041112
lbl_08040dc2:
    ldr r2, lbl_08040ddc @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_08040df8
    cmp r7, #2
    bls lbl_08040de4
    ldr r0, lbl_08040de0 @ =0x082feaa4
    b lbl_08040de6
    .align 2, 0
lbl_08040ddc: .4byte 0x03000738
lbl_08040de0: .4byte 0x082feaa4
lbl_08040de4:
    ldr r0, lbl_08040df4 @ =0x082fea94
lbl_08040de6:
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #1
    b lbl_080410a0
    .align 2, 0
lbl_08040df4: .4byte 0x082fea94
lbl_08040df8:
    cmp r7, #0xa
    bls lbl_08040e04
    ldr r0, lbl_08040e00 @ =0x082fea64
    b lbl_08041096
    .align 2, 0
lbl_08040e00: .4byte 0x082fea64
lbl_08040e04:
    ldr r0, lbl_08040e08 @ =0x082fea54
    b lbl_08041096
    .align 2, 0
lbl_08040e08: .4byte 0x082fea54
lbl_08040e0c:
    ldr r4, lbl_08040e2c @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08040e30 @ =0x082feaa4
    cmp r1, r0
    bne lbl_08040e3c
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08040e38
    ldr r0, lbl_08040e34 @ =0x082fea94
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08040e3c
    .align 2, 0
lbl_08040e2c: .4byte 0x03000738
lbl_08040e30: .4byte 0x082feaa4
lbl_08040e34: .4byte 0x082fea94
lbl_08040e38:
    bl CannonFireBullet
lbl_08040e3c:
    ldr r2, lbl_08040e70 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08040e52
    b lbl_08041112
lbl_08040e52:
    movs r0, #0x42
    strb r0, [r3]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08040e74
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08040f64
    .align 2, 0
lbl_08040e70: .4byte 0x03000738
lbl_08040e74:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, lbl_08040e84 @ =0x082fea84
    str r0, [r2, #0x18]
    b lbl_08041112
    .align 2, 0
lbl_08040e84: .4byte 0x082fea84
lbl_08040e88:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_08040e92
    b lbl_08041112
lbl_08040e92:
    ldr r2, lbl_08040eac @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_08040ec8
    cmp r7, #4
    bls lbl_08040eb4
    ldr r0, lbl_08040eb0 @ =0x082feae4
    b lbl_08040eb6
    .align 2, 0
lbl_08040eac: .4byte 0x03000738
lbl_08040eb0: .4byte 0x082feae4
lbl_08040eb4:
    ldr r0, lbl_08040ec4 @ =0x082fead4
lbl_08040eb6:
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #1
    b lbl_080410a0
    .align 2, 0
lbl_08040ec4: .4byte 0x082fead4
lbl_08040ec8:
    cmp r7, #2
    bls lbl_08040ed4
    ldr r0, lbl_08040ed0 @ =0x082feaa4
    b lbl_08041096
    .align 2, 0
lbl_08040ed0: .4byte 0x082feaa4
lbl_08040ed4:
    ldr r0, lbl_08040ed8 @ =0x082fea94
    b lbl_08041096
    .align 2, 0
lbl_08040ed8: .4byte 0x082fea94
lbl_08040edc:
    ldr r4, lbl_08040efc @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08040f00 @ =0x082feae4
    cmp r1, r0
    bne lbl_08040f0c
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08040f08
    ldr r0, lbl_08040f04 @ =0x082fead4
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08040f0c
    .align 2, 0
lbl_08040efc: .4byte 0x03000738
lbl_08040f00: .4byte 0x082feae4
lbl_08040f04: .4byte 0x082fead4
lbl_08040f08:
    bl CannonFireBullet
lbl_08040f0c:
    ldr r2, lbl_08040f58 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08040f22
    b lbl_08041112
lbl_08040f22:
    movs r0, #0x42
    strb r0, [r3]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    adds r0, r2, #0
    adds r0, #0x2f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08040f40
    ldrh r0, [r2]
    movs r6, #0x80
    lsls r6, r6, #2
    adds r1, r6, #0
    eors r0, r1
    strh r0, [r2]
lbl_08040f40:
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08040f5c
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, #1
    b lbl_08041040
    .align 2, 0
lbl_08040f58: .4byte 0x03000738
lbl_08040f5c:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
lbl_08040f64:
    strb r0, [r1]
    ldr r0, lbl_08040f6c @ =0x082feac4
    str r0, [r2, #0x18]
    b lbl_08041112
    .align 2, 0
lbl_08040f6c: .4byte 0x082feac4
lbl_08040f70:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_08040f7a
    b lbl_08041112
lbl_08040f7a:
    ldr r2, lbl_08040f94 @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_08040fb0
    cmp r7, #2
    bls lbl_08040f9c
    ldr r0, lbl_08040f98 @ =0x082feb24
    b lbl_08040f9e
    .align 2, 0
lbl_08040f94: .4byte 0x03000738
lbl_08040f98: .4byte 0x082feb24
lbl_08040f9c:
    ldr r0, lbl_08040fac @ =0x082feb14
lbl_08040f9e:
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #1
    b lbl_080410a0
    .align 2, 0
lbl_08040fac: .4byte 0x082feb14
lbl_08040fb0:
    cmp r7, #4
    bls lbl_08040fbc
    ldr r0, lbl_08040fb8 @ =0x082feae4
    b lbl_08041096
    .align 2, 0
lbl_08040fb8: .4byte 0x082feae4
lbl_08040fbc:
    ldr r0, lbl_08040fc0 @ =0x082fead4
    b lbl_08041096
    .align 2, 0
lbl_08040fc0: .4byte 0x082fead4
lbl_08040fc4:
    ldr r4, lbl_08040fe4 @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_08040fe8 @ =0x082feb24
    cmp r1, r0
    bne lbl_08040ff4
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08040ff0
    ldr r0, lbl_08040fec @ =0x082feb14
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_08040ff4
    .align 2, 0
lbl_08040fe4: .4byte 0x03000738
lbl_08040fe8: .4byte 0x082feb24
lbl_08040fec: .4byte 0x082feb14
lbl_08040ff0:
    bl CannonFireBullet
lbl_08040ff4:
    ldr r2, lbl_08041030 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_0804100a
    b lbl_08041112
lbl_0804100a:
    movs r0, #0x42
    strb r0, [r3]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08041038
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldr r0, lbl_08041034 @ =0x082feb44
    str r0, [r2, #0x18]
    b lbl_08041112
    .align 2, 0
lbl_08041030: .4byte 0x03000738
lbl_08041034: .4byte 0x082feb44
lbl_08041038:
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
lbl_08041040:
    strb r0, [r1]
    ldr r0, lbl_08041048 @ =0x082feb04
    str r0, [r2, #0x18]
    b lbl_08041112
    .align 2, 0
lbl_08041048: .4byte 0x082feb04
lbl_0804104c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_08041112
    ldr r2, lbl_0804106c @ =0x03000738
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #2
    ands r0, r1
    adds r1, r2, #0
    cmp r0, #0
    beq lbl_08041088
    cmp r7, #0xa
    bls lbl_08041074
    ldr r0, lbl_08041070 @ =0x082feb64
    b lbl_08041076
    .align 2, 0
lbl_0804106c: .4byte 0x03000738
lbl_08041070: .4byte 0x082feb64
lbl_08041074:
    ldr r0, lbl_08041084 @ =0x082feb54
lbl_08041076:
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    adds r0, #1
    b lbl_080410a0
    .align 2, 0
lbl_08041084: .4byte 0x082feb54
lbl_08041088:
    cmp r7, #2
    bls lbl_08041094
    ldr r0, lbl_08041090 @ =0x082feb24
    b lbl_08041096
    .align 2, 0
lbl_08041090: .4byte 0x082feb24
lbl_08041094:
    ldr r0, lbl_080410ac @ =0x082feb14
lbl_08041096:
    str r0, [r1, #0x18]
    adds r2, r1, #0
    adds r2, #0x2d
    ldrb r0, [r2]
    subs r0, #1
lbl_080410a0:
    strb r0, [r2]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    b lbl_08041112
    .align 2, 0
lbl_080410ac: .4byte 0x082feb14
lbl_080410b0:
    ldr r4, lbl_080410d0 @ =0x03000738
    ldr r1, [r4, #0x18]
    ldr r0, lbl_080410d4 @ =0x082feb64
    cmp r1, r0
    bne lbl_080410e0
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_080410dc
    ldr r0, lbl_080410d8 @ =0x082feb54
    str r0, [r4, #0x18]
    movs r0, #0
    strb r0, [r4, #0x1c]
    strh r0, [r4, #0x16]
    b lbl_080410e0
    .align 2, 0
lbl_080410d0: .4byte 0x03000738
lbl_080410d4: .4byte 0x082feb64
lbl_080410d8: .4byte 0x082feb54
lbl_080410dc:
    bl CannonFireBullet
lbl_080410e0:
    ldr r2, lbl_08041118 @ =0x03000738
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_08041112
    movs r0, #0x42
    strb r0, [r3]
    strb r1, [r2, #0x1c]
    strh r1, [r2, #0x16]
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldr r0, lbl_0804111c @ =0x082feb44
    str r0, [r2, #0x18]
    ldrh r1, [r2]
    ldr r0, lbl_08041120 @ =0x0000fdff
    ands r0, r1
lbl_08041110:
    strh r0, [r2]
lbl_08041112:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08041118: .4byte 0x03000738
lbl_0804111c: .4byte 0x082feb44
lbl_08041120: .4byte 0x0000fdff

    thumb_func_start CannonBullet
CannonBullet: @ 0x08041124
    push {r4, r5, r6, lr}
    movs r0, #3
    movs r1, #0x27
    bl EventFunction
    adds r5, r0, #0
    cmp r5, #0
    beq lbl_08041136
    b lbl_08041296
lbl_08041136:
    ldr r4, lbl_08041168 @ =0x03000738
    adds r6, r4, #0
    adds r6, #0x24
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_0804116c
    cmp r0, #9
    bne lbl_08041148
    b lbl_08041238
lbl_08041148:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x1f
    bl ParticleSet
    ldrh r1, [r4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_0804115e
    b lbl_08041296
lbl_0804115e:
    movs r0, #0x96
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_08041296
    .align 2, 0
lbl_08041168: .4byte 0x03000738
lbl_0804116c:
    ldrh r1, [r4]
    ldr r0, lbl_080411cc @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    strh r0, [r4]
    adds r3, r4, #0
    adds r3, #0x32
    ldrb r1, [r3]
    movs r0, #4
    orrs r0, r1
    strb r0, [r3]
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #2
    strb r0, [r1]
    strh r5, [r4, #0x14]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_080411d0 @ =0x0000fffc
    strh r1, [r4, #0xa]
    movs r0, #4
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #6
    strb r0, [r1]
    movs r0, #9
    strb r0, [r6]
    strb r2, [r4, #0x1c]
    strh r5, [r4, #0x16]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    bne lbl_080411d8
    ldr r0, lbl_080411d4 @ =0x082feb84
    str r0, [r4, #0x18]
    ldrh r0, [r4, #4]
    subs r0, #0x40
    strh r0, [r4, #4]
    b lbl_0804129c
    .align 2, 0
lbl_080411cc: .4byte 0x0000fffb
lbl_080411d0: .4byte 0x0000fffc
lbl_080411d4: .4byte 0x082feb84
lbl_080411d8:
    cmp r0, #2
    bne lbl_080411f4
    ldr r0, lbl_080411f0 @ =0x082feb9c
    str r0, [r4, #0x18]
    ldrh r0, [r4, #2]
    adds r0, #0x30
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0x30
    strh r0, [r4, #4]
    b lbl_0804129c
    .align 2, 0
lbl_080411f0: .4byte 0x082feb9c
lbl_080411f4:
    cmp r0, #4
    bne lbl_08041208
    ldr r0, lbl_08041204 @ =0x082febb4
    str r0, [r4, #0x18]
    ldrh r0, [r4, #2]
    adds r0, #0x40
    strh r0, [r4, #2]
    b lbl_0804129c
    .align 2, 0
lbl_08041204: .4byte 0x082febb4
lbl_08041208:
    cmp r0, #6
    bne lbl_08041224
    ldr r0, lbl_08041220 @ =0x082febcc
    str r0, [r4, #0x18]
    ldrh r0, [r4, #2]
    adds r0, #0x30
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    adds r0, #0x30
    strh r0, [r4, #4]
    b lbl_0804129c
    .align 2, 0
lbl_08041220: .4byte 0x082febcc
lbl_08041224:
    cmp r0, #8
    bne lbl_08041292
    ldr r0, lbl_08041234 @ =0x082febe4
    str r0, [r4, #0x18]
    ldrh r0, [r4, #4]
    adds r0, #0x40
    strh r0, [r4, #4]
    b lbl_0804129c
    .align 2, 0
lbl_08041234: .4byte 0x082febe4
lbl_08041238:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0x11
    bne lbl_08041250
    movs r0, #0x42
    strb r0, [r6]
    adds r0, r4, #0
    adds r0, #0x25
    strb r5, [r0]
    b lbl_0804129c
lbl_08041250:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    bne lbl_0804125e
    ldrh r0, [r4, #4]
    subs r0, #5
    strh r0, [r4, #4]
    b lbl_0804129c
lbl_0804125e:
    cmp r0, #2
    bne lbl_08041268
    ldrh r0, [r4, #4]
    subs r0, #3
    b lbl_0804127c
lbl_08041268:
    cmp r0, #4
    bne lbl_08041274
    ldrh r0, [r4, #2]
    adds r0, #5
    strh r0, [r4, #2]
    b lbl_0804129c
lbl_08041274:
    cmp r0, #6
    bne lbl_08041286
    ldrh r0, [r4, #4]
    adds r0, #3
lbl_0804127c:
    strh r0, [r4, #4]
    ldrh r0, [r4, #2]
    adds r0, #3
    strh r0, [r4, #2]
    b lbl_0804129c
lbl_08041286:
    cmp r0, #8
    bne lbl_08041292
    ldrh r0, [r4, #4]
    adds r0, #5
    strh r0, [r4, #4]
    b lbl_0804129c
lbl_08041292:
    strh r5, [r4]
    b lbl_0804129c
lbl_08041296:
    ldr r1, lbl_080412a4 @ =0x03000738
    movs r0, #0
    strh r0, [r1]
lbl_0804129c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080412a4: .4byte 0x03000738
