    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start mecha_ridley_sync_sub_sprites_pos
mecha_ridley_sync_sub_sprites_pos: @ 0x0804ba9c
    push {r4, lr}
    ldr r4, lbl_0804baf8 @ =0x0300070c
    ldrh r0, [r4, #4]
    ldr r1, [r4]
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r3, [r0]
    ldr r2, lbl_0804bafc @ =0x03000738
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0]
    ldr r1, lbl_0804bb00 @ =0x0875f878
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r1, [r2, #0x18]
    ldr r0, [r0]
    cmp r1, r0
    beq lbl_0804bace
    str r0, [r2, #0x18]
    movs r0, #0
    strb r0, [r2, #0x1c]
    strh r0, [r2, #0x16]
lbl_0804bace:
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #2]
    ldrh r1, [r4, #6]
    adds r0, r0, r1
    strh r0, [r2, #2]
    ldrb r1, [r2, #0x1e]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r3
    ldrh r0, [r0, #4]
    ldrh r4, [r4, #8]
    adds r0, r0, r4
    strh r0, [r2, #4]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804baf8: .4byte 0x0300070c
lbl_0804bafc: .4byte 0x03000738
lbl_0804bb00: .4byte 0x0875f878

    thumb_func_start MechaRidleyPartGreeGlow
MechaRidleyPartGreeGlow: @ 0x0804bb04
    push {r4, r5, lr}
    ldr r4, lbl_0804bb18 @ =0x03000738
    adds r5, r4, #0
    adds r5, #0x2c
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0804bb1c
    subs r0, #1
    strb r0, [r5]
    b lbl_0804bb6c
    .align 2, 0
lbl_0804bb18: .4byte 0x03000738
lbl_0804bb1c:
    movs r0, #0x2d
    adds r0, r0, r4
    mov ip, r0
    ldrb r0, [r0]
    adds r1, r0, #1
    mov r2, ip
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    ldr r1, lbl_0804bb74 @ =0x0831fce4
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrb r3, [r0]
    cmp r3, #0x80
    bne lbl_0804bb44
    movs r0, #1
    mov r2, ip
    strb r0, [r2]
    movs r2, #0
    ldrb r3, [r1]
lbl_0804bb44:
    lsls r0, r2, #1
    adds r1, #1
    adds r0, r0, r1
    ldrb r0, [r0]
    strb r0, [r5]
    ldr r2, lbl_0804bb78 @ =0x040000d4
    lsls r0, r3, #5
    ldr r1, lbl_0804bb7c @ =0x08323ac2
    adds r0, r0, r1
    str r0, [r2]
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r0, [r0]
    lsls r0, r0, #5
    ldr r1, lbl_0804bb80 @ =0x0500031a
    adds r0, r0, r1
    str r0, [r2, #4]
    ldr r0, lbl_0804bb84 @ =0x80000003
    str r0, [r2, #8]
    ldr r0, [r2, #8]
lbl_0804bb6c:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804bb74: .4byte 0x0831fce4
lbl_0804bb78: .4byte 0x040000d4
lbl_0804bb7c: .4byte 0x08323ac2
lbl_0804bb80: .4byte 0x0500031a
lbl_0804bb84: .4byte 0x80000003

    thumb_func_start sub_0804bb88
sub_0804bb88: @ 0x0804bb88
    push {r4, r5, lr}
    ldr r0, lbl_0804bc08 @ =0x0300080c
    ldrh r3, [r0, #0xa]
    cmp r3, #0
    bne lbl_0804bc02
    ldrh r0, [r0, #0xe]
    cmp r0, #0
    beq lbl_0804bc02
    ldr r1, lbl_0804bc0c @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2e
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #3
    bls lbl_0804bbb6
    strb r3, [r1]
lbl_0804bbb6:
    ldrb r2, [r1]
    ldr r1, lbl_0804bc10 @ =0x040000d4
    lsls r2, r2, #7
    ldr r3, lbl_0804bc14 @ =0x083225e8
    adds r0, r2, r3
    str r0, [r1]
    ldr r0, lbl_0804bc18 @ =0x06014280
    str r0, [r1, #4]
    ldr r4, lbl_0804bc1c @ =0x80000040
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r5, #0x80
    lsls r5, r5, #3
    adds r0, r3, r5
    adds r0, r2, r0
    str r0, [r1]
    ldr r0, lbl_0804bc20 @ =0x06014680
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r5, #0x80
    lsls r5, r5, #4
    adds r0, r3, r5
    adds r0, r2, r0
    str r0, [r1]
    ldr r0, lbl_0804bc24 @ =0x06014a80
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r3, r3, r0
    adds r2, r2, r3
    str r2, [r1]
    ldr r0, lbl_0804bc28 @ =0x06014e80
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
lbl_0804bc02:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804bc08: .4byte 0x0300080c
lbl_0804bc0c: .4byte 0x03000738
lbl_0804bc10: .4byte 0x040000d4
lbl_0804bc14: .4byte 0x083225e8
lbl_0804bc18: .4byte 0x06014280
lbl_0804bc1c: .4byte 0x80000040
lbl_0804bc20: .4byte 0x06014680
lbl_0804bc24: .4byte 0x06014a80
lbl_0804bc28: .4byte 0x06014e80

    thumb_func_start sub_0804bc2c
sub_0804bc2c: @ 0x0804bc2c
    push {r4, r5, lr}
    ldr r0, lbl_0804bcac @ =0x0300080c
    ldrh r3, [r0, #0xe]
    cmp r3, #0
    bne lbl_0804bca6
    ldrh r0, [r0, #0xa]
    cmp r0, #0
    beq lbl_0804bca6
    ldr r1, lbl_0804bcb0 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2e
    ldrb r0, [r2]
    adds r0, #1
    strb r0, [r2]
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #2
    bls lbl_0804bc5a
    strb r3, [r1]
lbl_0804bc5a:
    ldrb r2, [r1]
    ldr r1, lbl_0804bcb4 @ =0x040000d4
    lsls r2, r2, #7
    ldr r3, lbl_0804bcb8 @ =0x08322468
    adds r0, r2, r3
    str r0, [r1]
    ldr r0, lbl_0804bcbc @ =0x06014280
    str r0, [r1, #4]
    ldr r4, lbl_0804bcc0 @ =0x80000040
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r5, #0x80
    lsls r5, r5, #3
    adds r0, r3, r5
    adds r0, r2, r0
    str r0, [r1]
    ldr r0, lbl_0804bcc4 @ =0x06014680
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r5, #0x80
    lsls r5, r5, #4
    adds r0, r3, r5
    adds r0, r2, r0
    str r0, [r1]
    ldr r0, lbl_0804bcc8 @ =0x06014a80
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
    movs r0, #0xc0
    lsls r0, r0, #4
    adds r3, r3, r0
    adds r2, r2, r3
    str r2, [r1]
    ldr r0, lbl_0804bccc @ =0x06014e80
    str r0, [r1, #4]
    str r4, [r1, #8]
    ldr r0, [r1, #8]
lbl_0804bca6:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804bcac: .4byte 0x0300080c
lbl_0804bcb0: .4byte 0x03000738
lbl_0804bcb4: .4byte 0x040000d4
lbl_0804bcb8: .4byte 0x08322468
lbl_0804bcbc: .4byte 0x06014280
lbl_0804bcc0: .4byte 0x80000040
lbl_0804bcc4: .4byte 0x06014680
lbl_0804bcc8: .4byte 0x06014a80
lbl_0804bccc: .4byte 0x06014e80

    thumb_func_start sub_0804bcd0
sub_0804bcd0: @ 0x0804bcd0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    movs r5, #0
    ldr r4, lbl_0804bcf8 @ =0x0300070c
    ldr r0, [r4]
    ldr r1, lbl_0804bcfc @ =0x0831f78c
    mov r8, r1
    cmp r0, r8
    bne lbl_0804bd14
    ldr r0, lbl_0804bd00 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #1
    bne lbl_0804bd08
    ldr r0, lbl_0804bd04 @ =0x0831f9b4
lbl_0804bcee:
    str r0, [r4]
    strb r5, [r4, #0xc]
    strh r5, [r4, #4]
    b lbl_0804bde8
    .align 2, 0
lbl_0804bcf8: .4byte 0x0300070c
lbl_0804bcfc: .4byte 0x0831f78c
lbl_0804bd00: .4byte 0x0300080c
lbl_0804bd04: .4byte 0x0831f9b4
lbl_0804bd08:
    cmp r0, #2
    bne lbl_0804bdea
    ldr r0, lbl_0804bd10 @ =0x0831fa14
    b lbl_0804bcee
    .align 2, 0
lbl_0804bd10: .4byte 0x0831fa14
lbl_0804bd14:
    ldr r6, lbl_0804bd28 @ =0x0831f7c4
    cmp r0, r6
    bne lbl_0804bd4c
    ldr r6, lbl_0804bd2c @ =0x0300080c
    ldrh r0, [r6, #4]
    cmp r0, #2
    bne lbl_0804bd34
    ldr r0, lbl_0804bd30 @ =0x0831f9cc
    b lbl_0804bcee
    .align 2, 0
lbl_0804bd28: .4byte 0x0831f7c4
lbl_0804bd2c: .4byte 0x0300080c
lbl_0804bd30: .4byte 0x0831f9cc
lbl_0804bd34:
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804bdea
    ldrh r0, [r6, #4]
    cmp r0, #0
    bne lbl_0804bdea
    ldr r0, lbl_0804bd48 @ =0x0831f9fc
    b lbl_0804bcee
    .align 2, 0
lbl_0804bd48: .4byte 0x0831f9fc
lbl_0804bd4c:
    ldr r7, lbl_0804bd68 @ =0x0831f7fc
    cmp r0, r7
    bne lbl_0804bd80
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804bdea
    ldr r0, lbl_0804bd6c @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    bne lbl_0804bd74
    ldr r0, lbl_0804bd70 @ =0x0831fa3c
    b lbl_0804bcee
    .align 2, 0
lbl_0804bd68: .4byte 0x0831f7fc
lbl_0804bd6c: .4byte 0x0300080c
lbl_0804bd70: .4byte 0x0831fa3c
lbl_0804bd74:
    cmp r0, #1
    bne lbl_0804bdea
    ldr r0, lbl_0804bd7c @ =0x0831f9e4
    b lbl_0804bcee
    .align 2, 0
lbl_0804bd7c: .4byte 0x0831f9e4
lbl_0804bd80:
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804bde8
    ldr r1, [r4]
    ldr r0, lbl_0804bda0 @ =0x0831f9b4
    cmp r1, r0
    beq lbl_0804bd9c
    ldr r0, lbl_0804bda4 @ =0x0831f9cc
    cmp r1, r0
    beq lbl_0804bdc2
    ldr r0, lbl_0804bda8 @ =0x0831f9e4
    cmp r1, r0
    bne lbl_0804bdac
lbl_0804bd9c:
    str r6, [r4]
    b lbl_0804bdd6
    .align 2, 0
lbl_0804bda0: .4byte 0x0831f9b4
lbl_0804bda4: .4byte 0x0831f9cc
lbl_0804bda8: .4byte 0x0831f9e4
lbl_0804bdac:
    ldr r0, lbl_0804bdb8 @ =0x0831f9fc
    cmp r1, r0
    bne lbl_0804bdbc
    mov r0, r8
    str r0, [r4]
    b lbl_0804bdd6
    .align 2, 0
lbl_0804bdb8: .4byte 0x0831f9fc
lbl_0804bdbc:
    ldr r0, lbl_0804bdc8 @ =0x0831fa14
    cmp r1, r0
    bne lbl_0804bdcc
lbl_0804bdc2:
    str r7, [r4]
    b lbl_0804bdd6
    .align 2, 0
lbl_0804bdc8: .4byte 0x0831fa14
lbl_0804bdcc:
    ldr r0, lbl_0804bde0 @ =0x0831fa3c
    cmp r1, r0
    bne lbl_0804bdd6
    mov r1, r8
    str r1, [r4]
lbl_0804bdd6:
    ldr r1, lbl_0804bde4 @ =0x0300070c
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    b lbl_0804bdea
    .align 2, 0
lbl_0804bde0: .4byte 0x0831fa3c
lbl_0804bde4: .4byte 0x0300070c
lbl_0804bde8:
    movs r5, #1
lbl_0804bdea:
    adds r0, r5, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0804bdf8
sub_0804bdf8: @ 0x0804bdf8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    ldr r0, lbl_0804be54 @ =0x0300070c
    ldrb r3, [r0, #0x10]
    ldr r2, lbl_0804be58 @ =0x0300080c
    ldrh r1, [r0, #0xa]
    movs r7, #0
    movs r4, #0
    mov ip, r4
    strh r1, [r2, #0xc]
    ldr r2, [r0]
    ldr r1, lbl_0804be5c @ =0x0831f78c
    adds r6, r0, #0
    cmp r2, r1
    bne lbl_0804be74
    ldr r4, lbl_0804be60 @ =0x030001ac
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r3, r4, #0
    adds r3, #0x18
    adds r2, r0, r3
    ldr r1, lbl_0804be64 @ =0x08326064
    str r1, [r2]
    adds r0, r0, r4
    strb r7, [r0, #0x1c]
    mov r1, ip
    strh r1, [r0, #0x16]
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r3, r0, r3
    ldr r1, lbl_0804be68 @ =0x08326004
    str r1, [r3]
    adds r0, r0, r4
    strb r7, [r0, #0x1c]
    mov r4, ip
    strh r4, [r0, #0x16]
    ldr r0, lbl_0804be6c @ =0x0831fc3c
    str r0, [r6]
    ldr r0, lbl_0804be70 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x29
    b lbl_0804be98
    .align 2, 0
lbl_0804be54: .4byte 0x0300070c
lbl_0804be58: .4byte 0x0300080c
lbl_0804be5c: .4byte 0x0831f78c
lbl_0804be60: .4byte 0x030001ac
lbl_0804be64: .4byte 0x08326064
lbl_0804be68: .4byte 0x08326004
lbl_0804be6c: .4byte 0x0831fc3c
lbl_0804be70: .4byte 0x03000738
lbl_0804be74:
    ldr r0, lbl_0804be80 @ =0x0831f7c4
    cmp r2, r0
    bne lbl_0804be88
    ldr r0, lbl_0804be84 @ =0x0831f9fc
    b lbl_0804be90
    .align 2, 0
lbl_0804be80: .4byte 0x0831f7c4
lbl_0804be84: .4byte 0x0831f9fc
lbl_0804be88:
    ldr r0, lbl_0804bea8 @ =0x0831f7fc
    cmp r2, r0
    bne lbl_0804be9a
    ldr r0, lbl_0804beac @ =0x0831fa3c
lbl_0804be90:
    str r0, [r6]
    ldr r0, lbl_0804beb0 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x27
lbl_0804be98:
    strb r1, [r0]
lbl_0804be9a:
    movs r0, #0
    strb r0, [r6, #0xc]
    strh r0, [r6, #4]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804bea8: .4byte 0x0831f7fc
lbl_0804beac: .4byte 0x0831fa3c
lbl_0804beb0: .4byte 0x03000738

    thumb_func_start sub_0804beb4
sub_0804beb4: @ 0x0804beb4
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    ldr r1, lbl_0804bed8 @ =0x0300070c
    ldr r2, [r1]
    ldr r0, lbl_0804bedc @ =0x0831f7c4
    cmp r2, r0
    bne lbl_0804bee8
    ldr r0, lbl_0804bee0 @ =0x0831f9cc
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r2, lbl_0804bee4 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #6
    b lbl_0804bf18
    .align 2, 0
lbl_0804bed8: .4byte 0x0300070c
lbl_0804bedc: .4byte 0x0831f7c4
lbl_0804bee0: .4byte 0x0831f9cc
lbl_0804bee4: .4byte 0x03000738
lbl_0804bee8:
    ldr r0, lbl_0804bf04 @ =0x0831f78c
    cmp r2, r0
    bne lbl_0804bf10
    ldr r0, lbl_0804bf08 @ =0x0831fa14
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r2, lbl_0804bf0c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0xc
    b lbl_0804bf18
    .align 2, 0
lbl_0804bf04: .4byte 0x0831f78c
lbl_0804bf08: .4byte 0x0831fa14
lbl_0804bf0c: .4byte 0x03000738
lbl_0804bf10:
    ldr r2, lbl_0804bf58 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0
lbl_0804bf18:
    strb r0, [r1]
    adds r5, r2, #0
    ldr r3, lbl_0804bf5c @ =0x030001ac
    lsls r0, r4, #3
    subs r0, r0, r4
    lsls r0, r0, #3
    adds r1, r3, #0
    adds r1, #0x18
    adds r1, r0, r1
    ldr r2, lbl_0804bf60 @ =0x0832611c
    str r2, [r1]
    adds r0, r0, r3
    movs r1, #0
    strb r1, [r0, #0x1c]
    strh r1, [r0, #0x16]
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x22
    strb r0, [r1]
    ldrh r1, [r5]
    movs r2, #0x80
    lsls r2, r2, #3
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r5]
    ldr r1, lbl_0804bf64 @ =0x0300080c
    movs r0, #1
    strh r0, [r1, #6]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804bf58: .4byte 0x03000738
lbl_0804bf5c: .4byte 0x030001ac
lbl_0804bf60: .4byte 0x0832611c
lbl_0804bf64: .4byte 0x0300080c

    thumb_func_start MechaRidleyInit
MechaRidleyInit: @ 0x0804bf68
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    movs r0, #3
    movs r1, #0x4a
    bl EventFunction
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_0804bf90
    ldr r1, lbl_0804bf8c @ =0x03000738
    movs r0, #0
    strh r0, [r1]
    b lbl_0804c164
    .align 2, 0
lbl_0804bf8c: .4byte 0x03000738
lbl_0804bf90:
    ldr r1, lbl_0804c174 @ =0x0000384c
    movs r0, #1
    bl TransparencyUpdateBLDCNT
    movs r0, #0xa
    movs r1, #0
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
    ldr r4, lbl_0804c178 @ =0x03000738
    ldrh r1, [r4, #4]
    adds r1, #0x40
    movs r0, #0
    mov sl, r0
    strh r1, [r4, #4]
    ldr r5, lbl_0804c17c @ =0x0300080c
    ldrh r0, [r4, #2]
    strh r0, [r5]
    strh r1, [r5, #2]
    strh r6, [r5, #4]
    strh r6, [r5, #6]
    strh r6, [r5, #8]
    strh r6, [r5, #0xa]
    strh r6, [r5, #0xc]
    strh r6, [r5, #0xe]
    strh r6, [r5, #0x10]
    strh r6, [r5, #0x12]
    bl SpriteUtilGetCurrentCompletionPercentage
    strh r0, [r5, #0x14]
    movs r1, #0xb0
    lsls r1, r1, #2
    adds r2, r1, #0
    ldrh r3, [r4, #4]
    adds r2, r2, r3
    strh r2, [r4, #4]
    ldr r1, lbl_0804c180 @ =0x0300070c
    mov sb, r1
    ldrh r1, [r4, #2]
    mov r3, sb
    strh r1, [r3, #6]
    strh r2, [r3, #8]
    ldrh r7, [r3, #6]
    ldrh r1, [r3, #8]
    mov r8, r1
    adds r1, r4, #0
    adds r1, #0x27
    movs r2, #8
    strb r2, [r1]
    adds r1, #1
    strb r2, [r1]
    adds r1, #1
    strb r2, [r1]
    ldr r2, lbl_0804c184 @ =0x0000ffe0
    strh r2, [r4, #0xa]
    movs r1, #0x20
    strh r1, [r4, #0xc]
    strh r2, [r4, #0xe]
    strh r1, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x33
    movs r2, #5
    mov ip, r2
    mov r3, ip
    strb r3, [r1]
    adds r2, r4, #0
    adds r2, #0x22
    movs r1, #0xa
    strb r1, [r2]
    adds r1, r4, #0
    adds r1, #0x25
    mov r2, sl
    strb r2, [r1]
    ldr r3, lbl_0804c188 @ =0x082b0d68
    ldrb r2, [r4, #0x1d]
    lsls r1, r2, #3
    adds r1, r1, r2
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r1, [r1]
    strh r1, [r4, #0x14]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x64
    bne lbl_0804c044
    ldrh r1, [r4, #0x14]
    lsls r0, r1, #1
    adds r0, r0, r1
    strh r0, [r4, #0x14]
lbl_0804c044:
    ldrh r0, [r4, #0x14]
    strh r0, [r5, #0x10]
    ldrh r0, [r4]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    strh r0, [r4]
    movs r0, #0x96
    lsls r0, r0, #1
    strh r0, [r4, #6]
    ldr r0, lbl_0804c18c @ =0x0300083c
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x2f
    strb r0, [r1]
    adds r0, r4, #0
    adds r0, #0x2a
    mov r1, sl
    strb r1, [r0]
    ldr r0, lbl_0804c190 @ =0x0831f5ac
    mov r2, sb
    str r0, [r2]
    strb r1, [r2, #0xc]
    strh r6, [r2, #4]
    strb r1, [r2, #0xe]
    strb r1, [r2, #0xf]
    ldr r1, lbl_0804c194 @ =0x0300007b
    movs r0, #1
    strb r0, [r1]
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #1
    strb r0, [r1]
    mov r3, ip
    strb r3, [r4, #0x1e]
    ldrb r5, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r4, [r0]
    str r7, [sp]
    mov r0, r8
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #0
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r1, sb
    strb r0, [r1, #0x10]
    str r7, [sp]
    mov r2, r8
    str r2, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #1
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r3, r8
    str r3, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #2
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r0, r8
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #3
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r1, r8
    str r1, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #4
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r2, r8
    str r2, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #6
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r3, r8
    str r3, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #7
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r0, r8
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #8
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    mov r1, sb
    strb r0, [r1, #0x11]
    str r7, [sp]
    mov r2, r8
    str r2, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #9
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
    str r7, [sp]
    mov r3, r8
    str r3, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x44
    movs r1, #0xa
    adds r2, r5, #0
    adds r3, r4, #0
    bl SpriteSpawnSecondary
lbl_0804c164:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c174: .4byte 0x0000384c
lbl_0804c178: .4byte 0x03000738
lbl_0804c17c: .4byte 0x0300080c
lbl_0804c180: .4byte 0x0300070c
lbl_0804c184: .4byte 0x0000ffe0
lbl_0804c188: .4byte 0x082b0d68
lbl_0804c18c: .4byte 0x0300083c
lbl_0804c190: .4byte 0x0831f5ac
lbl_0804c194: .4byte 0x0300007b

    thumb_func_start MechaRidleyStartWalking
MechaRidleyStartWalking: @ 0x0804c198
    push {lr}
    ldr r0, lbl_0804c1c4 @ =0x03000738
    adds r0, #0x24
    movs r1, #2
    strb r1, [r0]
    ldr r0, lbl_0804c1c8 @ =0x000002b3
    bl SoundPlay
    ldr r1, lbl_0804c1cc @ =0x040000d4
    ldr r0, lbl_0804c1d0 @ =0x08323b68
    str r0, [r1]
    ldr r0, lbl_0804c1d4 @ =0x05000300
    str r0, [r1, #4]
    ldr r0, lbl_0804c1d8 @ =0x8000000d
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r1, lbl_0804c1dc @ =0x0000284c
    movs r0, #1
    bl TransparencyUpdateBLDCNT
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c1c4: .4byte 0x03000738
lbl_0804c1c8: .4byte 0x000002b3
lbl_0804c1cc: .4byte 0x040000d4
lbl_0804c1d0: .4byte 0x08323b68
lbl_0804c1d4: .4byte 0x05000300
lbl_0804c1d8: .4byte 0x8000000d
lbl_0804c1dc: .4byte 0x0000284c

    thumb_func_start MechaRidleyDelayBeforeCrawling
MechaRidleyDelayBeforeCrawling: @ 0x0804c1e0
    push {lr}
    ldr r1, lbl_0804c1fc @ =0x03000738
    ldrh r0, [r1, #6]
    subs r0, #1
    strh r0, [r1, #6]
    lsls r0, r0, #0x10
    cmp r0, #0
    bne lbl_0804c1f6
    adds r1, #0x24
    movs r0, #3
    strb r0, [r1]
lbl_0804c1f6:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c1fc: .4byte 0x03000738

    thumb_func_start MechaRidleyCrawling
MechaRidleyCrawling: @ 0x0804c200
    push {r4, r5, r6, lr}
    ldr r0, lbl_0804c248 @ =0x0300070c
    ldrb r3, [r0, #0x10]
    ldrb r5, [r0, #0x11]
    ldr r6, lbl_0804c24c @ =0x0300080c
    ldrh r2, [r0, #8]
    ldrh r1, [r6, #2]
    adds r4, r0, #0
    cmp r2, r1
    bhi lbl_0804c258
    movs r5, #0
    strh r1, [r4, #8]
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c29c
    ldr r2, lbl_0804c250 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #4
    strb r0, [r1]
    ldr r0, lbl_0804c254 @ =0x0831f78c
    str r0, [r4]
    strb r5, [r4, #0xc]
    movs r0, #0
    strh r0, [r4, #4]
    adds r0, r2, #0
    adds r0, #0x2c
    strb r5, [r0]
    adds r1, #9
    movs r0, #0x20
    strb r0, [r1]
    movs r0, #1
    strh r0, [r6, #6]
    b lbl_0804c29c
    .align 2, 0
lbl_0804c248: .4byte 0x0300070c
lbl_0804c24c: .4byte 0x0300080c
lbl_0804c250: .4byte 0x03000738
lbl_0804c254: .4byte 0x0831f78c
lbl_0804c258:
    ldr r1, lbl_0804c270 @ =0x030001ac
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #0x16]
    cmp r0, #6
    beq lbl_0804c274
    cmp r0, #7
    beq lbl_0804c278
    b lbl_0804c27c
    .align 2, 0
lbl_0804c270: .4byte 0x030001ac
lbl_0804c274:
    subs r0, r2, #4
    b lbl_0804c27a
lbl_0804c278:
    subs r0, r2, #2
lbl_0804c27a:
    strh r0, [r4, #8]
lbl_0804c27c:
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r0, [r0, #0x16]
    cmp r0, #0
    beq lbl_0804c290
    cmp r0, #1
    beq lbl_0804c296
    b lbl_0804c29c
lbl_0804c290:
    ldrh r0, [r4, #8]
    subs r0, #4
    b lbl_0804c29a
lbl_0804c296:
    ldrh r0, [r4, #8]
    subs r0, #2
lbl_0804c29a:
    strh r0, [r4, #8]
lbl_0804c29c:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MechaRidleyStartBattle
MechaRidleyStartBattle: @ 0x0804c2a4
    push {r4, r5, lr}
    ldr r2, lbl_0804c2e8 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    movs r3, #0xff
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_0804c320
    movs r0, #2
    strb r0, [r1]
    subs r1, #1
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ands r0, r3
    adds r4, r0, #0
    cmp r0, #6
    bls lbl_0804c2f0
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    movs r0, #0x41
    movs r1, #0
    bl MusicPlay
    ldr r0, lbl_0804c2ec @ =0x0300004d
    strb r5, [r0]
    b lbl_0804c320
    .align 2, 0
lbl_0804c2e8: .4byte 0x03000738
lbl_0804c2ec: .4byte 0x0300004d
lbl_0804c2f0:
    cmp r0, #1
    bne lbl_0804c2fa
    ldr r0, lbl_0804c328 @ =0x000002ad
    bl SoundPlay
lbl_0804c2fa:
    ldr r2, lbl_0804c32c @ =0x040000d4
    lsls r0, r4, #5
    ldr r1, lbl_0804c330 @ =0x08323b68
    adds r0, r0, r1
    str r0, [r2]
    ldr r0, lbl_0804c334 @ =0x05000300
    str r0, [r2, #4]
    ldr r0, lbl_0804c338 @ =0x8000000d
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    adds r0, r4, #0
    adds r0, #0xa
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    movs r1, #0
    movs r2, #0
    movs r3, #0x10
    bl TransparencySpriteUpdateBLDALPHA
lbl_0804c320:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c328: .4byte 0x000002ad
lbl_0804c32c: .4byte 0x040000d4
lbl_0804c330: .4byte 0x08323b68
lbl_0804c334: .4byte 0x05000300
lbl_0804c338: .4byte 0x8000000d

    thumb_func_start MechaRidleyCheckSamusOutOfAmmo
MechaRidleyCheckSamusOutOfAmmo: @ 0x0804c33c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r2, lbl_0804c370 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x2f
    ldrb r1, [r0]
    movs r0, #0x3f
    ands r0, r1
    cmp r0, #0
    bne lbl_0804c3c0
    ldrh r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r1
    cmp r0, #0
    bne lbl_0804c378
    ldr r0, lbl_0804c374 @ =0x0300083c
    ldrb r0, [r0]
    cmp r0, #7
    bhi lbl_0804c378
    adds r0, r3, #0
    bl sub_0804beb4
    b lbl_0804c3c0
    .align 2, 0
lbl_0804c370: .4byte 0x03000738
lbl_0804c374: .4byte 0x0300083c
lbl_0804c378:
    ldrh r1, [r2]
    ldr r0, lbl_0804c3ac @ =0x0000fbff
    ands r0, r1
    strh r0, [r2]
    ldr r0, lbl_0804c3b0 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    ldr r3, lbl_0804c3b4 @ =0x0300080c
    cmp r0, #1
    bne lbl_0804c3bc
    ldrh r0, [r3, #0xa]
    cmp r0, #0
    bne lbl_0804c3bc
    ldrh r0, [r3, #8]
    cmp r0, #0
    bne lbl_0804c3bc
    ldr r0, lbl_0804c3b8 @ =0x03001530
    ldrh r1, [r0, #8]
    ldrb r0, [r0, #0xa]
    cmn r1, r0
    beq lbl_0804c3bc
    adds r1, r2, #0
    adds r1, #0x24
    movs r0, #0x34
    strb r0, [r1]
    movs r0, #1
    b lbl_0804c3c2
    .align 2, 0
lbl_0804c3ac: .4byte 0x0000fbff
lbl_0804c3b0: .4byte 0x0300070c
lbl_0804c3b4: .4byte 0x0300080c
lbl_0804c3b8: .4byte 0x03001530
lbl_0804c3bc:
    movs r0, #2
    strh r0, [r3, #6]
lbl_0804c3c0:
    movs r0, #0
lbl_0804c3c2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0804c3c8
sub_0804c3c8: @ 0x0804c3c8
    push {r4, r5, lr}
    ldr r5, lbl_0804c3f8 @ =0x0300070c
    ldrb r4, [r5, #0x11]
    bl sub_0804bcd0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804c3e4
    adds r0, r4, #0
    bl MechaRidleyCheckSamusOutOfAmmo
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804c3f0
lbl_0804c3e4:
    ldrb r0, [r5, #0xe]
    cmp r0, #0xaa
    bne lbl_0804c3f0
    ldr r1, lbl_0804c3fc @ =0x0300080c
    movs r0, #1
    strh r0, [r1, #8]
lbl_0804c3f0:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c3f8: .4byte 0x0300070c
lbl_0804c3fc: .4byte 0x0300080c

    thumb_func_start ridley_claw_attack
ridley_claw_attack: @ 0x0804c400
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r1, lbl_0804c4bc @ =0x0300080c
    ldrh r0, [r1, #0x10]
    mov sb, r0
    ldr r0, lbl_0804c4c0 @ =0x03000738
    adds r2, r0, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    adds r5, r1, #0
    ldr r3, lbl_0804c4c4 @ =0x0300070c
    cmp r0, #0
    beq lbl_0804c432
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_0804c432
    ldr r0, lbl_0804c4c8 @ =0x0831f7fc
    str r0, [r3]
    strb r1, [r3, #0xc]
    strh r1, [r3, #4]
lbl_0804c432:
    ldrb r7, [r3, #0x11]
    ldrh r1, [r3, #8]
    ldrh r0, [r5, #2]
    subs r0, #0x40
    cmp r1, r0
    ble lbl_0804c46c
    ldr r0, lbl_0804c4cc @ =0x030001ac
    lsls r1, r7, #3
    subs r1, r1, r7
    lsls r1, r1, #3
    adds r1, r1, r0
    ldrh r2, [r1, #0x16]
    subs r0, r2, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #3
    bhi lbl_0804c46c
    cmp r2, #4
    bne lbl_0804c464
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0804c464
    ldr r0, lbl_0804c4d0 @ =0x0000029e
    bl SoundPlay
lbl_0804c464:
    ldr r1, lbl_0804c4c4 @ =0x0300070c
    ldrh r0, [r1, #8]
    subs r0, #4
    strh r0, [r1, #8]
lbl_0804c46c:
    adds r0, r7, #0
    bl SpriteUtilCheckEndSpriteAnim
    cmp r0, #0
    beq lbl_0804c51a
    ldr r3, lbl_0804c4c4 @ =0x0300070c
    ldr r5, lbl_0804c4bc @ =0x0300080c
    ldrh r0, [r5, #2]
    subs r0, #0x40
    movs r6, #0
    movs r1, #0
    mov r8, r1
    strh r0, [r3, #8]
    ldr r4, lbl_0804c4cc @ =0x030001ac
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r1, r4, #0
    adds r1, #0x18
    adds r1, r0, r1
    ldr r2, lbl_0804c4d4 @ =0x08325a94
    str r2, [r1]
    adds r0, r0, r4
    strb r6, [r0, #0x1c]
    mov r2, r8
    strh r2, [r0, #0x16]
    ldrb r0, [r3, #0xf]
    cmp r0, #1
    bls lbl_0804c504
    ldrh r1, [r3, #0xa]
    mov r2, sb
    lsrs r0, r2, #1
    cmp r1, r0
    bhs lbl_0804c4d8
    ldr r2, lbl_0804c4c0 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x28
    b lbl_0804c50c
    .align 2, 0
lbl_0804c4bc: .4byte 0x0300080c
lbl_0804c4c0: .4byte 0x03000738
lbl_0804c4c4: .4byte 0x0300070c
lbl_0804c4c8: .4byte 0x0831f7fc
lbl_0804c4cc: .4byte 0x030001ac
lbl_0804c4d0: .4byte 0x0000029e
lbl_0804c4d4: .4byte 0x08325a94
lbl_0804c4d8:
    ldrh r1, [r3, #0xa]
    mov r2, sb
    lsls r0, r2, #1
    add r0, sb
    asrs r0, r0, #2
    cmp r1, r0
    bge lbl_0804c4f4
    ldr r2, lbl_0804c4f0 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x50
    b lbl_0804c50c
    .align 2, 0
lbl_0804c4f0: .4byte 0x03000738
lbl_0804c4f4:
    ldr r2, lbl_0804c500 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0x78
    b lbl_0804c50c
    .align 2, 0
lbl_0804c500: .4byte 0x03000738
lbl_0804c504:
    ldr r2, lbl_0804c528 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    movs r0, #0xa0
lbl_0804c50c:
    strb r0, [r1]
    adds r0, r2, #0
    adds r0, #0x24
    movs r1, #0x23
    strb r1, [r0]
    ldrh r0, [r3, #0xa]
    strh r0, [r5, #0xc]
lbl_0804c51a:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c528: .4byte 0x03000738

    thumb_func_start MechaRidleyStandingUp
MechaRidleyStandingUp: @ 0x0804c52c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r0, lbl_0804c570 @ =0x0300070c
    mov r8, r0
    ldrb r5, [r0, #0x11]
    adds r7, r5, #0
    ldr r6, lbl_0804c574 @ =0x03000738
    adds r1, r6, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    adds r4, r0, #0
    cmp r4, #0
    beq lbl_0804c580
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0804c5c6
    ldr r3, lbl_0804c578 @ =0x030001ac
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r1, r3, #0
    adds r1, #0x18
    adds r1, r0, r1
    ldr r2, lbl_0804c57c @ =0x083259c4
    str r2, [r1]
    adds r0, r0, r3
    strb r4, [r0, #0x1c]
    strh r4, [r0, #0x16]
    b lbl_0804c5c6
    .align 2, 0
lbl_0804c570: .4byte 0x0300070c
lbl_0804c574: .4byte 0x03000738
lbl_0804c578: .4byte 0x030001ac
lbl_0804c57c: .4byte 0x083259c4
lbl_0804c580:
    adds r0, r5, #0
    bl SpriteUtilCheckEndSpriteAnim
    cmp r0, #0
    beq lbl_0804c5aa
    ldr r3, lbl_0804c5d0 @ =0x030001ac
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r1, r3, #0
    adds r1, #0x18
    adds r1, r0, r1
    ldr r2, lbl_0804c5d4 @ =0x08325a24
    str r2, [r1]
    adds r0, r0, r3
    strb r4, [r0, #0x1c]
    strh r4, [r0, #0x16]
    adds r1, r6, #0
    adds r1, #0x24
    movs r0, #0x25
    strb r0, [r1]
lbl_0804c5aa:
    bl sub_0804bcd0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804c5c6
    ldr r0, lbl_0804c5d8 @ =0x0300080c
    ldrh r0, [r0, #0xc]
    mov r1, r8
    ldrh r1, [r1, #0xa]
    cmp r0, r1
    bls lbl_0804c5c6
    adds r0, r7, #0
    bl sub_0804bdf8
lbl_0804c5c6:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c5d0: .4byte 0x030001ac
lbl_0804c5d4: .4byte 0x08325a24
lbl_0804c5d8: .4byte 0x0300080c

    thumb_func_start MechaRidleyCurledUp
MechaRidleyCurledUp: @ 0x0804c5dc
    push {r4, r5, r6, lr}
    ldr r5, lbl_0804c600 @ =0x0300070c
    ldrb r4, [r5, #0x11]
    adds r6, r4, #0
    bl sub_0804bcd0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804c614
    ldr r0, lbl_0804c604 @ =0x0300080c
    ldrh r0, [r0, #0xc]
    ldrh r5, [r5, #0xa]
    cmp r0, r5
    bls lbl_0804c608
    adds r0, r4, #0
    bl sub_0804bdf8
    b lbl_0804c614
    .align 2, 0
lbl_0804c600: .4byte 0x0300070c
lbl_0804c604: .4byte 0x0300080c
lbl_0804c608:
    adds r0, r6, #0
    bl MechaRidleyCheckSamusOutOfAmmo
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804c622
lbl_0804c614:
    ldr r0, lbl_0804c628 @ =0x0300070c
    ldrb r0, [r0, #0xe]
    cmp r0, #0xaa
    bne lbl_0804c622
    ldr r1, lbl_0804c62c @ =0x0300080c
    movs r0, #1
    strh r0, [r1, #8]
lbl_0804c622:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c628: .4byte 0x0300070c
lbl_0804c62c: .4byte 0x0300080c

    thumb_func_start MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded
MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded: @ 0x0804c630
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_0804c68c @ =0x0300070c
    ldrb r5, [r6, #0x10]
    ldrb r7, [r6, #0x11]
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c684
    ldr r4, lbl_0804c690 @ =0x030001ac
    lsls r0, r5, #3
    subs r0, r0, r5
    lsls r0, r0, #3
    adds r3, r4, #0
    adds r3, #0x18
    adds r2, r0, r3
    ldr r1, lbl_0804c694 @ =0x08326064
    str r1, [r2]
    adds r0, r0, r4
    movs r2, #0
    strb r2, [r0, #0x1c]
    movs r5, #0
    strh r2, [r0, #0x16]
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r3, r0, r3
    ldr r1, lbl_0804c698 @ =0x08326004
    str r1, [r3]
    adds r0, r0, r4
    strb r5, [r0, #0x1c]
    strh r2, [r0, #0x16]
    ldr r0, lbl_0804c69c @ =0x0831fc3c
    str r0, [r6]
    strb r5, [r6, #0xc]
    strh r2, [r6, #4]
    ldr r0, lbl_0804c6a0 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x29
    strb r1, [r0]
    ldr r0, lbl_0804c6a4 @ =0x0000029f
    bl SoundPlay
lbl_0804c684:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c68c: .4byte 0x0300070c
lbl_0804c690: .4byte 0x030001ac
lbl_0804c694: .4byte 0x08326064
lbl_0804c698: .4byte 0x08326004
lbl_0804c69c: .4byte 0x0831fc3c
lbl_0804c6a0: .4byte 0x03000738
lbl_0804c6a4: .4byte 0x0000029f

    thumb_func_start MechaRidleyMovingBack
MechaRidleyMovingBack: @ 0x0804c6a8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r4, lbl_0804c6c8 @ =0x0300070c
    ldrb r7, [r4, #0x10]
    ldrb r0, [r4, #0x11]
    mov r8, r0
    ldr r0, lbl_0804c6cc @ =0x0300080c
    ldrh r1, [r4, #8]
    ldrh r0, [r0, #2]
    cmp r1, r0
    bhs lbl_0804c6d0
    adds r0, r1, #1
    strh r0, [r4, #8]
    b lbl_0804c71a
    .align 2, 0
lbl_0804c6c8: .4byte 0x0300070c
lbl_0804c6cc: .4byte 0x0300080c
lbl_0804c6d0:
    movs r5, #0
    movs r6, #0
    strh r0, [r4, #8]
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c71a
    ldr r0, lbl_0804c724 @ =0x0831f78c
    str r0, [r4]
    strb r5, [r4, #0xc]
    strh r6, [r4, #4]
    ldr r0, lbl_0804c728 @ =0x03000738
    adds r0, #0x24
    movs r1, #9
    strb r1, [r0]
    ldr r4, lbl_0804c72c @ =0x030001ac
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r3, r4, #0
    adds r3, #0x18
    adds r2, r0, r3
    ldr r1, lbl_0804c730 @ =0x08325acc
    str r1, [r2]
    adds r0, r0, r4
    strb r5, [r0, #0x1c]
    strh r6, [r0, #0x16]
    mov r1, r8
    lsls r0, r1, #3
    subs r0, r0, r1
    lsls r0, r0, #3
    adds r3, r0, r3
    ldr r1, lbl_0804c734 @ =0x08325a24
    str r1, [r3]
    adds r0, r0, r4
    strb r5, [r0, #0x1c]
    strh r6, [r0, #0x16]
lbl_0804c71a:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c724: .4byte 0x0831f78c
lbl_0804c728: .4byte 0x03000738
lbl_0804c72c: .4byte 0x030001ac
lbl_0804c730: .4byte 0x08325acc
lbl_0804c734: .4byte 0x08325a24

    thumb_func_start MechaRidleyBeforeFireballs
MechaRidleyBeforeFireballs: @ 0x0804c738
    push {lr}
    ldr r2, lbl_0804c76c @ =0x0300070c
    ldr r1, [r2]
    ldr r0, lbl_0804c770 @ =0x0831f7c4
    cmp r1, r0
    bne lbl_0804c74e
    ldr r0, lbl_0804c774 @ =0x0831f9cc
    str r0, [r2]
    movs r0, #0
    strb r0, [r2, #0xc]
    strh r0, [r2, #4]
lbl_0804c74e:
    ldr r1, [r2]
    ldr r0, lbl_0804c778 @ =0x0831f78c
    cmp r1, r0
    bne lbl_0804c760
    ldr r0, lbl_0804c77c @ =0x0831fa14
    str r0, [r2]
    movs r0, #0
    strb r0, [r2, #0xc]
    strh r0, [r2, #4]
lbl_0804c760:
    ldr r0, lbl_0804c780 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x35
    strb r1, [r0]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c76c: .4byte 0x0300070c
lbl_0804c770: .4byte 0x0831f7c4
lbl_0804c774: .4byte 0x0831f9cc
lbl_0804c778: .4byte 0x0831f78c
lbl_0804c77c: .4byte 0x0831fa14
lbl_0804c780: .4byte 0x03000738

    thumb_func_start MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded
MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded: @ 0x0804c784
    push {lr}
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c7aa
    ldr r1, lbl_0804c7b0 @ =0x0300070c
    ldr r0, lbl_0804c7b4 @ =0x0831fb04
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r0, lbl_0804c7b8 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x37
    strb r1, [r0]
    movs r0, #0xaa
    lsls r0, r0, #2
    bl SoundPlay
lbl_0804c7aa:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c7b0: .4byte 0x0300070c
lbl_0804c7b4: .4byte 0x0831fb04
lbl_0804c7b8: .4byte 0x03000738

    thumb_func_start MechaRidleyCheckOpeningMouthAnimEnded
MechaRidleyCheckOpeningMouthAnimEnded: @ 0x0804c7bc
    push {lr}
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c7e2
    ldr r1, lbl_0804c7e8 @ =0x0300070c
    ldr r0, lbl_0804c7ec @ =0x0831fb1c
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r1, lbl_0804c7f0 @ =0x03000738
    adds r2, r1, #0
    adds r2, #0x2c
    movs r0, #0x80
    strb r0, [r2]
    adds r1, #0x24
    movs r0, #0x39
    strb r0, [r1]
lbl_0804c7e2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c7e8: .4byte 0x0300070c
lbl_0804c7ec: .4byte 0x0831fb1c
lbl_0804c7f0: .4byte 0x03000738

    thumb_func_start MechaRidleyFireballsAttack
MechaRidleyFireballsAttack: @ 0x0804c7f4
    push {r4, r5, lr}
    sub sp, #0xc
    ldr r3, lbl_0804c838 @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x2c
    ldrb r1, [r0]
    movs r4, #0xf
    ands r4, r1
    cmp r4, #0
    bne lbl_0804c86c
    movs r0, #0x10
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    beq lbl_0804c844
    ldrb r2, [r3, #0x1f]
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r1, lbl_0804c83c @ =0x0300070c
    ldrh r0, [r1, #6]
    ldr r5, lbl_0804c840 @ =0xffffff00
    adds r0, r0, r5
    str r0, [sp]
    ldrh r0, [r1, #8]
    subs r0, #0x40
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x49
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0804c866
    .align 2, 0
lbl_0804c838: .4byte 0x03000738
lbl_0804c83c: .4byte 0x0300070c
lbl_0804c840: .4byte 0xffffff00
lbl_0804c844:
    ldrb r2, [r3, #0x1f]
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldr r1, lbl_0804c89c @ =0x0300070c
    ldrh r0, [r1, #6]
    ldr r4, lbl_0804c8a0 @ =0xffffff00
    adds r0, r0, r4
    str r0, [sp]
    ldrh r0, [r1, #8]
    subs r0, #0x40
    str r0, [sp, #4]
    str r5, [sp, #8]
    movs r0, #0x49
    movs r1, #1
    bl SpriteSpawnSecondary
lbl_0804c866:
    ldr r0, lbl_0804c8a4 @ =0x000002a9
    bl SoundPlay
lbl_0804c86c:
    ldr r3, lbl_0804c8a8 @ =0x03000738
    adds r1, r3, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0804c892
    ldr r0, lbl_0804c89c @ =0x0300070c
    ldr r1, lbl_0804c8ac @ =0x0831fb3c
    str r1, [r0]
    strb r2, [r0, #0xc]
    strh r2, [r0, #4]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x3b
    strb r0, [r1]
lbl_0804c892:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c89c: .4byte 0x0300070c
lbl_0804c8a0: .4byte 0xffffff00
lbl_0804c8a4: .4byte 0x000002a9
lbl_0804c8a8: .4byte 0x03000738
lbl_0804c8ac: .4byte 0x0831fb3c

    thumb_func_start mecha_ridley_check_closing_mouth_anim_ended
mecha_ridley_check_closing_mouth_anim_ended: @ 0x0804c8b0
    push {lr}
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c8ce
    ldr r1, lbl_0804c8d4 @ =0x0300070c
    ldr r0, lbl_0804c8d8 @ =0x0831fa3c
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r0, lbl_0804c8dc @ =0x03000738
    adds r0, #0x24
    movs r1, #0x3d
    strb r1, [r0]
lbl_0804c8ce:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c8d4: .4byte 0x0300070c
lbl_0804c8d8: .4byte 0x0831fa3c
lbl_0804c8dc: .4byte 0x03000738

    thumb_func_start MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded
MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded: @ 0x0804c8e0
    push {lr}
    bl SpriteUtilCheckEndSubSprite1Anim
    cmp r0, #0
    beq lbl_0804c924
    ldr r1, lbl_0804c90c @ =0x0300070c
    ldr r0, lbl_0804c910 @ =0x0831f78c
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldrh r1, [r1, #8]
    ldr r0, lbl_0804c914 @ =0x0300080c
    ldrh r0, [r0, #2]
    subs r0, #0x40
    cmp r1, r0
    bne lbl_0804c91c
    ldr r0, lbl_0804c918 @ =0x03000738
    adds r0, #0x24
    movs r1, #0x25
    b lbl_0804c922
    .align 2, 0
lbl_0804c90c: .4byte 0x0300070c
lbl_0804c910: .4byte 0x0831f78c
lbl_0804c914: .4byte 0x0300080c
lbl_0804c918: .4byte 0x03000738
lbl_0804c91c:
    ldr r0, lbl_0804c928 @ =0x03000738
    adds r0, #0x24
    movs r1, #9
lbl_0804c922:
    strb r1, [r0]
lbl_0804c924:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c928: .4byte 0x03000738

    thumb_func_start MechaRidleyStartDying
MechaRidleyStartDying: @ 0x0804c92c
    push {lr}
    ldr r1, lbl_0804c984 @ =0x0300070c
    ldr r0, lbl_0804c988 @ =0x0831f684
    str r0, [r1]
    movs r0, #0
    strb r0, [r1, #0xc]
    strh r0, [r1, #4]
    ldr r2, lbl_0804c98c @ =0x03000738
    ldrh r0, [r2]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r1, r3, #0
    orrs r0, r1
    movs r1, #4
    orrs r0, r1
    strh r0, [r2]
    adds r1, r2, #0
    adds r1, #0x2b
    movs r0, #0x3c
    strb r0, [r1]
    movs r0, #1
    strh r0, [r2, #0x14]
    subs r1, #7
    movs r0, #0x67
    strb r0, [r1]
    ldr r1, lbl_0804c990 @ =0x0300080c
    movs r0, #4
    strh r0, [r1, #6]
    ldrh r0, [r2, #2]
    adds r0, #0x40
    ldrh r1, [r2, #4]
    movs r2, #0x27
    bl ParticleSet
    movs r0, #0xac
    lsls r0, r0, #2
    bl SoundPlay
    movs r0, #0x3c
    bl MusicFade
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804c984: .4byte 0x0300070c
lbl_0804c988: .4byte 0x0831f684
lbl_0804c98c: .4byte 0x03000738
lbl_0804c990: .4byte 0x0300080c

    thumb_func_start MechaRidleyDying
MechaRidleyDying: @ 0x0804c994
    push {r4, lr}
    ldr r0, lbl_0804c9d0 @ =0x0300083c
    ldrb r0, [r0]
    lsls r0, r0, #0x19
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    ldr r0, lbl_0804c9d4 @ =0x03000738
    mov ip, r0
    adds r0, #0x2b
    ldrb r1, [r0]
    adds r3, r1, #0
    cmp r3, #0
    beq lbl_0804c9f0
    movs r0, #0xf
    ands r0, r1
    cmp r0, #0
    bne lbl_0804ca1a
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0804c9d8
    mov r1, ip
    ldrh r0, [r1, #2]
    adds r1, r2, #0
    subs r1, #0x40
    subs r0, r0, r1
    mov r3, ip
    ldrh r1, [r3, #4]
    adds r1, r1, r2
    b lbl_0804c9e8
    .align 2, 0
lbl_0804c9d0: .4byte 0x0300083c
lbl_0804c9d4: .4byte 0x03000738
lbl_0804c9d8:
    adds r0, r4, #0
    adds r0, #0x40
    mov r1, ip
    ldrh r1, [r1, #2]
    adds r0, r0, r1
    mov r2, ip
    ldrh r1, [r2, #4]
    subs r1, r1, r4
lbl_0804c9e8:
    movs r2, #0x27
    bl ParticleSet
    b lbl_0804ca1a
lbl_0804c9f0:
    ldr r1, lbl_0804ca20 @ =0x0300070c
    ldr r0, lbl_0804ca24 @ =0x0831fbe4
    str r0, [r1]
    strb r3, [r1, #0xc]
    movs r2, #0
    strh r3, [r1, #4]
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x64
    strb r0, [r1]
    mov r0, ip
    adds r0, #0x2c
    strb r2, [r0]
    ldr r0, lbl_0804ca28 @ =0x000002ae
    bl SoundPlay
    ldr r1, lbl_0804ca2c @ =0x0300004d
    movs r3, #1
    rsbs r3, r3, #0
    adds r0, r3, #0
    strb r0, [r1]
lbl_0804ca1a:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804ca20: .4byte 0x0300070c
lbl_0804ca24: .4byte 0x0831fbe4
lbl_0804ca28: .4byte 0x000002ae
lbl_0804ca2c: .4byte 0x0300004d

    thumb_func_start MechaRidleyGlowFading
MechaRidleyGlowFading: @ 0x0804ca30
    push {lr}
    ldr r3, lbl_0804ca54 @ =0x03000738
    adds r2, r3, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    adds r1, r0, #1
    strb r1, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x10
    bls lbl_0804ca48
    b lbl_0804cba0
lbl_0804ca48:
    lsls r0, r0, #2
    ldr r1, lbl_0804ca58 @ =lbl_0804ca5c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804ca54: .4byte 0x03000738
lbl_0804ca58: .4byte lbl_0804ca5c
lbl_0804ca5c: @ jump table
    .4byte lbl_0804caa0 @ case 0
    .4byte lbl_0804cac0 @ case 1
    .4byte lbl_0804cae0 @ case 2
    .4byte lbl_0804cb00 @ case 3
    .4byte lbl_0804cb20 @ case 4
    .4byte lbl_0804cb40 @ case 5
    .4byte lbl_0804cb60 @ case 6
    .4byte lbl_0804cba0 @ case 7
    .4byte lbl_0804cb80 @ case 8
    .4byte lbl_0804cba0 @ case 9
    .4byte lbl_0804cba0 @ case 10
    .4byte lbl_0804cba0 @ case 11
    .4byte lbl_0804cba0 @ case 12
    .4byte lbl_0804cba0 @ case 13
    .4byte lbl_0804cba0 @ case 14
    .4byte lbl_0804cba0 @ case 15
    .4byte lbl_0804cb90 @ case 16
lbl_0804caa0:
    ldr r1, lbl_0804cab0 @ =0x040000d4
    ldr r0, lbl_0804cab4 @ =0x08323468
    str r0, [r1]
    ldr r0, lbl_0804cab8 @ =0x06015580
    str r0, [r1, #4]
    ldr r0, lbl_0804cabc @ =0x80000040
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cab0: .4byte 0x040000d4
lbl_0804cab4: .4byte 0x08323468
lbl_0804cab8: .4byte 0x06015580
lbl_0804cabc: .4byte 0x80000040
lbl_0804cac0:
    ldr r1, lbl_0804cad0 @ =0x040000d4
    ldr r0, lbl_0804cad4 @ =0x08323528
    str r0, [r1]
    ldr r0, lbl_0804cad8 @ =0x06015980
    str r0, [r1, #4]
    ldr r0, lbl_0804cadc @ =0x80000060
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cad0: .4byte 0x040000d4
lbl_0804cad4: .4byte 0x08323528
lbl_0804cad8: .4byte 0x06015980
lbl_0804cadc: .4byte 0x80000060
lbl_0804cae0:
    ldr r1, lbl_0804caf0 @ =0x040000d4
    ldr r0, lbl_0804caf4 @ =0x083235e8
    str r0, [r1]
    ldr r0, lbl_0804caf8 @ =0x06015d80
    str r0, [r1, #4]
    ldr r0, lbl_0804cafc @ =0x80000060
    b lbl_0804cb9c
    .align 2, 0
lbl_0804caf0: .4byte 0x040000d4
lbl_0804caf4: .4byte 0x083235e8
lbl_0804caf8: .4byte 0x06015d80
lbl_0804cafc: .4byte 0x80000060
lbl_0804cb00:
    ldr r1, lbl_0804cb10 @ =0x040000d4
    ldr r0, lbl_0804cb14 @ =0x083236a8
    str r0, [r1]
    ldr r0, lbl_0804cb18 @ =0x06016180
    str r0, [r1, #4]
    ldr r0, lbl_0804cb1c @ =0x80000060
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cb10: .4byte 0x040000d4
lbl_0804cb14: .4byte 0x083236a8
lbl_0804cb18: .4byte 0x06016180
lbl_0804cb1c: .4byte 0x80000060
lbl_0804cb20:
    ldr r1, lbl_0804cb30 @ =0x040000d4
    ldr r0, lbl_0804cb34 @ =0x08323768
    str r0, [r1]
    ldr r0, lbl_0804cb38 @ =0x06016580
    str r0, [r1, #4]
    ldr r0, lbl_0804cb3c @ =0x80000060
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cb30: .4byte 0x040000d4
lbl_0804cb34: .4byte 0x08323768
lbl_0804cb38: .4byte 0x06016580
lbl_0804cb3c: .4byte 0x80000060
lbl_0804cb40:
    ldr r1, lbl_0804cb50 @ =0x040000d4
    ldr r0, lbl_0804cb54 @ =0x08323868
    str r0, [r1]
    ldr r0, lbl_0804cb58 @ =0x060169c0
    str r0, [r1, #4]
    ldr r0, lbl_0804cb5c @ =0x80000040
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cb50: .4byte 0x040000d4
lbl_0804cb54: .4byte 0x08323868
lbl_0804cb58: .4byte 0x060169c0
lbl_0804cb5c: .4byte 0x80000040
lbl_0804cb60:
    ldr r1, lbl_0804cb70 @ =0x040000d4
    ldr r0, lbl_0804cb74 @ =0x08323928
    str r0, [r1]
    ldr r0, lbl_0804cb78 @ =0x06016dc0
    str r0, [r1, #4]
    ldr r0, lbl_0804cb7c @ =0x80000040
    b lbl_0804cb9c
    .align 2, 0
lbl_0804cb70: .4byte 0x040000d4
lbl_0804cb74: .4byte 0x08323928
lbl_0804cb78: .4byte 0x06016dc0
lbl_0804cb7c: .4byte 0x80000040
lbl_0804cb80:
    ldr r1, lbl_0804cb88 @ =0x040000d4
    ldr r0, lbl_0804cb8c @ =0x08323b42
    b lbl_0804cb94
    .align 2, 0
lbl_0804cb88: .4byte 0x040000d4
lbl_0804cb8c: .4byte 0x08323b42
lbl_0804cb90:
    ldr r1, lbl_0804cbc4 @ =0x040000d4
    ldr r0, lbl_0804cbc8 @ =0x08323b62
lbl_0804cb94:
    str r0, [r1]
    ldr r0, lbl_0804cbcc @ =0x0500039a
    str r0, [r1, #4]
    ldr r0, lbl_0804cbd0 @ =0x80000003
lbl_0804cb9c:
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0804cba0:
    adds r2, r3, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    cmp r0, #0xc8
    bls lbl_0804cbc0
    movs r1, #0
    movs r0, #0
    strh r0, [r3, #6]
    strb r1, [r2]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x68
    strb r0, [r1]
    ldr r1, lbl_0804cbd4 @ =0x0300080c
    movs r0, #5
    strh r0, [r1, #6]
lbl_0804cbc0:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804cbc4: .4byte 0x040000d4
lbl_0804cbc8: .4byte 0x08323b62
lbl_0804cbcc: .4byte 0x0500039a
lbl_0804cbd0: .4byte 0x80000003
lbl_0804cbd4: .4byte 0x0300080c

    thumb_func_start MechaRidleySpawnDrops
MechaRidleySpawnDrops: @ 0x0804cbd8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    ldr r2, lbl_0804cc38 @ =0x03000738
    ldrh r0, [r2, #2]
    subs r0, #0x64
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    ldr r1, lbl_0804cc3c @ =0xfffffe80
    adds r0, r1, #0
    ldrh r1, [r2, #4]
    adds r0, r0, r1
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    ldr r0, lbl_0804cc40 @ =0x0300083c
    ldrb r0, [r0]
    mov ip, r0
    lsls r0, r0, #0x1b
    lsrs r5, r0, #0x18
    movs r0, #3
    mov r1, ip
    ands r1, r0
    mov ip, r1
    adds r3, r2, #0
    adds r3, #0x2c
    ldrb r1, [r3]
    movs r0, #0xf
    ands r0, r1
    lsls r4, r0, #3
    movs r0, #0x35
    mov r8, r0
    adds r1, #1
    strb r1, [r3]
    ldrh r0, [r2, #6]
    adds r1, r0, #1
    strh r1, [r2, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r0, #1
    cmp r0, #0x26
    bls lbl_0804cc2e
    b lbl_0804cde2
lbl_0804cc2e:
    lsls r0, r0, #2
    ldr r1, lbl_0804cc44 @ =lbl_0804cc48
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804cc38: .4byte 0x03000738
lbl_0804cc3c: .4byte 0xfffffe80
lbl_0804cc40: .4byte 0x0300083c
lbl_0804cc44: .4byte lbl_0804cc48
lbl_0804cc48: @ jump table
    .4byte lbl_0804cce4 @ case 0
    .4byte lbl_0804cde2 @ case 1
    .4byte lbl_0804cde2 @ case 2
    .4byte lbl_0804cde2 @ case 3
    .4byte lbl_0804cde2 @ case 4
    .4byte lbl_0804ccf4 @ case 5
    .4byte lbl_0804cde2 @ case 6
    .4byte lbl_0804cde2 @ case 7
    .4byte lbl_0804cde2 @ case 8
    .4byte lbl_0804cde2 @ case 9
    .4byte lbl_0804cde2 @ case 10
    .4byte lbl_0804cd04 @ case 11
    .4byte lbl_0804cde2 @ case 12
    .4byte lbl_0804cde2 @ case 13
    .4byte lbl_0804cde2 @ case 14
    .4byte lbl_0804cde2 @ case 15
    .4byte lbl_0804cde2 @ case 16
    .4byte lbl_0804cde2 @ case 17
    .4byte lbl_0804cde2 @ case 18
    .4byte lbl_0804cde2 @ case 19
    .4byte lbl_0804cde2 @ case 20
    .4byte lbl_0804cde2 @ case 21
    .4byte lbl_0804cde2 @ case 22
    .4byte lbl_0804cde2 @ case 23
    .4byte lbl_0804cde2 @ case 24
    .4byte lbl_0804cde2 @ case 25
    .4byte lbl_0804cde2 @ case 26
    .4byte lbl_0804cde2 @ case 27
    .4byte lbl_0804cde2 @ case 28
    .4byte lbl_0804cd28 @ case 29
    .4byte lbl_0804cd3c @ case 30
    .4byte lbl_0804cd98 @ case 31
    .4byte lbl_0804cd50 @ case 32
    .4byte lbl_0804cd98 @ case 33
    .4byte lbl_0804cd68 @ case 34
    .4byte lbl_0804cd98 @ case 35
    .4byte lbl_0804cd80 @ case 36
    .4byte lbl_0804cd98 @ case 37
    .4byte lbl_0804cdc0 @ case 38
lbl_0804cce4:
    ldr r1, lbl_0804ccec @ =0x040000d4
    ldr r0, lbl_0804ccf0 @ =0x08323aaa
    b lbl_0804cd08
    .align 2, 0
lbl_0804ccec: .4byte 0x040000d4
lbl_0804ccf0: .4byte 0x08323aaa
lbl_0804ccf4:
    ldr r1, lbl_0804ccfc @ =0x040000d4
    ldr r0, lbl_0804cd00 @ =0x08323aca
    b lbl_0804cd08
    .align 2, 0
lbl_0804ccfc: .4byte 0x040000d4
lbl_0804cd00: .4byte 0x08323aca
lbl_0804cd04:
    ldr r1, lbl_0804cd18 @ =0x040000d4
    ldr r0, lbl_0804cd1c @ =0x08323aea
lbl_0804cd08:
    str r0, [r1]
    ldr r0, lbl_0804cd20 @ =0x05000322
    str r0, [r1, #4]
    ldr r0, lbl_0804cd24 @ =0x80000006
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    b lbl_0804cde2
    .align 2, 0
lbl_0804cd18: .4byte 0x040000d4
lbl_0804cd1c: .4byte 0x08323aea
lbl_0804cd20: .4byte 0x05000322
lbl_0804cd24: .4byte 0x80000006
lbl_0804cd28:
    ldr r0, lbl_0804cd38 @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    adds r0, r6, r5
    str r0, [sp]
    subs r0, r7, r4
    b lbl_0804cdaa
    .align 2, 0
lbl_0804cd38: .4byte 0x03000738
lbl_0804cd3c:
    ldr r0, lbl_0804cd4c @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    subs r0, r6, r5
    str r0, [sp]
    adds r0, r7, r4
    b lbl_0804cdaa
    .align 2, 0
lbl_0804cd4c: .4byte 0x03000738
lbl_0804cd50:
    ldr r0, lbl_0804cd64 @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    subs r0, r6, r5
    lsls r1, r4, #1
    adds r0, r0, r1
    str r0, [sp]
    adds r0, r7, r4
    adds r0, r0, r5
    b lbl_0804cdaa
    .align 2, 0
lbl_0804cd64: .4byte 0x03000738
lbl_0804cd68:
    ldr r0, lbl_0804cd7c @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    subs r0, r6, r5
    lsls r1, r4, #1
    adds r0, r0, r1
    str r0, [sp]
    adds r0, r7, r4
    adds r0, r0, r5
    b lbl_0804cdaa
    .align 2, 0
lbl_0804cd7c: .4byte 0x03000738
lbl_0804cd80:
    ldr r0, lbl_0804cd94 @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    subs r0, r6, r5
    lsls r1, r4, #1
    adds r0, r0, r1
    str r0, [sp]
    adds r0, r7, r4
    adds r0, r0, r5
    b lbl_0804cdaa
    .align 2, 0
lbl_0804cd94: .4byte 0x03000738
lbl_0804cd98:
    ldr r0, lbl_0804cdbc @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    adds r0, r6, r5
    lsls r1, r4, #1
    subs r0, r0, r1
    str r0, [sp]
    subs r0, r7, r4
    subs r0, r0, r5
lbl_0804cdaa:
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, r8
    mov r1, ip
    movs r2, #0
    bl SpriteSpawnDropFollowers
    b lbl_0804cde2
    .align 2, 0
lbl_0804cdbc: .4byte 0x03000738
lbl_0804cdc0:
    ldr r0, lbl_0804ce18 @ =0x03000738
    adds r0, #0x23
    ldrb r3, [r0]
    subs r0, r6, r5
    lsls r1, r4, #1
    adds r0, r0, r1
    str r0, [sp]
    adds r0, r7, r4
    adds r0, r0, r5
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    mov r0, r8
    mov r1, ip
    movs r2, #0
    bl SpriteSpawnDropFollowers
lbl_0804cde2:
    ldr r3, lbl_0804ce18 @ =0x03000738
    ldrh r1, [r3, #6]
    movs r0, #0xb4
    lsls r0, r0, #1
    cmp r1, r0
    bls lbl_0804ce0a
    adds r1, r3, #0
    adds r1, #0x2c
    movs r2, #0
    movs r0, #0x1e
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #2
    movs r0, #4
    strb r0, [r1]
    subs r1, #0xa
    movs r0, #0x69
    strb r0, [r1]
lbl_0804ce0a:
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804ce18: .4byte 0x03000738

    thumb_func_start MechaRidleyFirstEyeGlow
MechaRidleyFirstEyeGlow: @ 0x0804ce1c
    push {lr}
    ldr r2, lbl_0804ce4c @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    mov ip, r2
    cmp r3, #0
    bne lbl_0804ce6c
    movs r0, #4
    strb r0, [r1]
    mov r1, ip
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0804ce58
    strb r3, [r1]
    ldr r1, lbl_0804ce50 @ =0x040000d4
    ldr r0, lbl_0804ce54 @ =0x08323b0a
    b lbl_0804ce60
    .align 2, 0
lbl_0804ce4c: .4byte 0x03000738
lbl_0804ce50: .4byte 0x040000d4
lbl_0804ce54: .4byte 0x08323b0a
lbl_0804ce58:
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0804cea8 @ =0x040000d4
    ldr r0, lbl_0804ceac @ =0x08323b2a
lbl_0804ce60:
    str r0, [r1]
    ldr r0, lbl_0804ceb0 @ =0x05000322
    str r0, [r1, #4]
    ldr r0, lbl_0804ceb4 @ =0x80000006
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0804ce6c:
    mov r3, ip
    adds r3, #0x2c
    ldrb r0, [r3]
    subs r0, #1
    strb r0, [r3]
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    cmp r2, #0
    bne lbl_0804cea2
    mov r1, ip
    adds r1, #0x24
    movs r0, #0x6a
    strb r0, [r1]
    movs r0, #0xc8
    strb r0, [r3]
    mov r0, ip
    adds r0, #0x2d
    strb r2, [r0]
    adds r1, #0xa
    movs r0, #4
    strb r0, [r1]
    ldr r1, lbl_0804ceb8 @ =0x0300080c
    movs r0, #6
    strh r0, [r1, #6]
    ldr r0, lbl_0804cebc @ =0x000002b1
    bl SoundPlay
lbl_0804cea2:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804cea8: .4byte 0x040000d4
lbl_0804ceac: .4byte 0x08323b2a
lbl_0804ceb0: .4byte 0x05000322
lbl_0804ceb4: .4byte 0x80000006
lbl_0804ceb8: .4byte 0x0300080c
lbl_0804cebc: .4byte 0x000002b1

    thumb_func_start MechaRidleySecondEyeGlow
MechaRidleySecondEyeGlow: @ 0x0804cec0
    push {r4, r5, lr}
    sub sp, #8
    ldr r2, lbl_0804cef0 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2e
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    adds r5, r2, #0
    cmp r3, #0
    bne lbl_0804cf10
    movs r0, #4
    strb r0, [r1]
    adds r1, r5, #0
    adds r1, #0x2d
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0804cefc
    strb r3, [r1]
    ldr r1, lbl_0804cef4 @ =0x040000d4
    ldr r0, lbl_0804cef8 @ =0x08323b2a
    b lbl_0804cf04
    .align 2, 0
lbl_0804cef0: .4byte 0x03000738
lbl_0804cef4: .4byte 0x040000d4
lbl_0804cef8: .4byte 0x08323b2a
lbl_0804cefc:
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0804cf68 @ =0x040000d4
    ldr r0, lbl_0804cf6c @ =0x08323b4a
lbl_0804cf04:
    str r0, [r1]
    ldr r0, lbl_0804cf70 @ =0x05000322
    str r0, [r1, #4]
    ldr r0, lbl_0804cf74 @ =0x80000006
    str r0, [r1, #8]
    ldr r0, [r1, #8]
lbl_0804cf10:
    adds r1, r5, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0804cf5e
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    bne lbl_0804cf5e
    movs r0, #1
    movs r1, #0x4a
    bl EventFunction
    ldrh r3, [r5, #2]
    ldrh r0, [r5, #4]
    str r0, [sp]
    str r4, [sp, #4]
    movs r0, #0x11
    movs r1, #0x22
    movs r2, #0
    bl SpriteSpawnPrimary
    ldr r1, lbl_0804cf78 @ =0x03000184
    ldr r0, lbl_0804cf7c @ =0x03000150
    ldr r0, [r0]
    str r0, [r1, #0xc]
    ldr r1, lbl_0804cf80 @ =0x0300007b
    movs r2, #0x14
    rsbs r2, r2, #0
    adds r0, r2, #0
    strb r0, [r1]
    ldr r0, lbl_0804cf84 @ =0x0300004d
    strb r4, [r0]
    movs r0, #8
    movs r1, #0x40
    bl MusicPlay
lbl_0804cf5e:
    add sp, #8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804cf68: .4byte 0x040000d4
lbl_0804cf6c: .4byte 0x08323b4a
lbl_0804cf70: .4byte 0x05000322
lbl_0804cf74: .4byte 0x80000006
lbl_0804cf78: .4byte 0x03000184
lbl_0804cf7c: .4byte 0x03000150
lbl_0804cf80: .4byte 0x0300007b
lbl_0804cf84: .4byte 0x0300004d

    thumb_func_start MechaRidleyPartInit
MechaRidleyPartInit: @ 0x0804cf88
    push {r4, lr}
    ldr r3, lbl_0804cfc0 @ =0x03000738
    ldrh r0, [r3]
    ldr r1, lbl_0804cfc4 @ =0x0000fffb
    ands r1, r0
    movs r0, #1
    strh r0, [r3, #0x14]
    adds r2, r3, #0
    adds r2, #0x24
    movs r0, #0x61
    strb r0, [r2]
    adds r2, #1
    movs r0, #0x1d
    strb r0, [r2]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r1, r0
    strh r1, [r3]
    ldrb r0, [r3, #0x1e]
    cmp r0, #0xa
    bls lbl_0804cfb6
    b lbl_0804d2d4
lbl_0804cfb6:
    lsls r0, r0, #2
    ldr r1, lbl_0804cfc8 @ =lbl_0804cfcc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804cfc0: .4byte 0x03000738
lbl_0804cfc4: .4byte 0x0000fffb
lbl_0804cfc8: .4byte lbl_0804cfcc
lbl_0804cfcc: @ jump table
    .4byte lbl_0804cff8 @ case 0
    .4byte lbl_0804d078 @ case 1
    .4byte lbl_0804d0ae @ case 2
    .4byte lbl_0804d10c @ case 3
    .4byte lbl_0804d154 @ case 4
    .4byte lbl_0804d2d4 @ case 5
    .4byte lbl_0804d1c4 @ case 6
    .4byte lbl_0804d200 @ case 7
    .4byte lbl_0804d038 @ case 8
    .4byte lbl_0804d23c @ case 9
    .4byte lbl_0804d284 @ case 10
lbl_0804cff8:
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x18
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x38
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x58
    strb r0, [r1]
    ldr r1, lbl_0804d034 @ =0x0000fffc
    strh r1, [r3, #0xa]
    movs r0, #4
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #3
    strb r0, [r1]
    adds r1, #2
    movs r0, #8
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d034: .4byte 0x0000fffc
lbl_0804d038:
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x50
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x38
    strb r0, [r1]
    adds r1, #1
    movs r0, #0x70
    strb r0, [r1]
    ldr r1, lbl_0804d074 @ =0x0000fffc
    strh r1, [r3, #0xa]
    movs r0, #4
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xd
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x22
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d074: .4byte 0x0000fffc
lbl_0804d078:
    adds r0, r3, #0
    adds r0, #0x27
    movs r2, #0
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r0, #0
    strh r2, [r3, #0xa]
    strh r2, [r3, #0xc]
    strh r2, [r3, #0xe]
    strh r2, [r3, #0x10]
    adds r1, r3, #0
    adds r1, #0x25
    strb r0, [r1]
    subs r1, #3
    movs r0, #4
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x26
    strb r0, [r1]
    adds r1, #0xf
    movs r0, #1
    strb r0, [r1]
    b lbl_0804d2d8
lbl_0804d0ae:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x28
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x29
    movs r0, #0x38
    strb r0, [r1]
    movs r2, #0
    ldr r0, lbl_0804d104 @ =0x0000ffa0
    strh r0, [r3, #0xa]
    movs r0, #0x60
    strh r0, [r3, #0xc]
    ldr r0, lbl_0804d108 @ =0x0000ffe0
    strh r0, [r3, #0xe]
    movs r0, #0x20
    strh r0, [r3, #0x10]
    movs r0, #1
    strh r0, [r3, #0x14]
    movs r4, #0x32
    ldrb r1, [r4, r3]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r4, r3]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #5
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x2c
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2c
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d104: .4byte 0x0000ffa0
lbl_0804d108: .4byte 0x0000ffe0
lbl_0804d10c:
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x30
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x28
    movs r1, #0x20
    strb r1, [r0]
    movs r0, #0x29
    adds r0, r0, r3
    mov ip, r0
    movs r2, #0x40
    movs r0, #0x40
    mov r4, ip
    strb r0, [r4]
    ldr r0, lbl_0804d150 @ =0x0000ffe0
    strh r0, [r3, #0xa]
    strh r1, [r3, #0xc]
    strh r0, [r3, #0xe]
    strh r1, [r3, #0x10]
    movs r0, #1
    strh r0, [r3, #0x14]
    adds r1, r3, #0
    adds r1, #0x32
    ldrb r0, [r1]
    orrs r2, r0
    strb r2, [r1]
    subs r1, #0x10
    movs r0, #6
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x24
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d150: .4byte 0x0000ffe0
lbl_0804d154:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_0804d1b0 @ =0x0000ffd8
    strh r0, [r3, #0xa]
    movs r0, #0x30
    strh r0, [r3, #0xc]
    ldr r0, lbl_0804d1b4 @ =0x0000ffd0
    strh r0, [r3, #0xe]
    movs r0, #0x40
    strh r0, [r3, #0x10]
    ldr r2, lbl_0804d1b8 @ =0x082b1be4
    ldrb r1, [r3, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r3, #0x14]
    ldr r2, lbl_0804d1bc @ =0x0300080c
    ldrh r0, [r2, #0x14]
    cmp r0, #0x64
    bne lbl_0804d194
    ldrh r1, [r3, #0x14]
    lsls r0, r1, #1
    adds r0, r0, r1
    strh r0, [r3, #0x14]
lbl_0804d194:
    ldrh r0, [r3, #0x14]
    strh r0, [r2, #0x12]
    ldr r1, lbl_0804d1c0 @ =0x0300070c
    strh r0, [r1, #0xa]
    strh r0, [r2, #0xc]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #9
    strb r0, [r1]
    adds r1, #2
    movs r0, #0x2a
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d1b0: .4byte 0x0000ffd8
lbl_0804d1b4: .4byte 0x0000ffd0
lbl_0804d1b8: .4byte 0x082b1be4
lbl_0804d1bc: .4byte 0x0300080c
lbl_0804d1c0: .4byte 0x0300070c
lbl_0804d1c4:
    adds r1, r3, #0
    adds r1, #0x27
    movs r0, #0x28
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x28
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r0, lbl_0804d1fc @ =0x0000ffc0
    strh r0, [r3, #0xa]
    movs r1, #0x40
    strh r1, [r3, #0xc]
    adds r0, #0x30
    strh r0, [r3, #0xe]
    strh r1, [r3, #0x10]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xb
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d1fc: .4byte 0x0000ffc0
lbl_0804d200:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x18
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0804d238 @ =0x0000ffc0
    strh r1, [r3, #0xa]
    movs r0, #0x40
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    movs r0, #1
    strh r0, [r3, #0x14]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xc
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d238: .4byte 0x0000ffc0
lbl_0804d23c:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r1, r3, #0
    adds r1, #0x29
    movs r0, #0x30
    strb r0, [r1]
    ldr r0, lbl_0804d27c @ =0x0000ffc0
    strh r0, [r3, #0xa]
    movs r0, #0x40
    strh r0, [r3, #0xc]
    ldr r0, lbl_0804d280 @ =0x0000ff40
    strh r0, [r3, #0xe]
    movs r0, #0xc0
    strh r0, [r3, #0x10]
    movs r0, #1
    strh r0, [r3, #0x14]
    adds r2, r3, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r0, #0x40
    orrs r0, r1
    strb r0, [r2]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xe
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d27c: .4byte 0x0000ffc0
lbl_0804d280: .4byte 0x0000ff40
lbl_0804d284:
    adds r0, r3, #0
    adds r0, #0x27
    movs r1, #0x20
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    movs r2, #0
    ldr r1, lbl_0804d2d0 @ =0x0000ffa0
    strh r1, [r3, #0xa]
    movs r0, #0x60
    strh r0, [r3, #0xc]
    strh r1, [r3, #0xe]
    strh r0, [r3, #0x10]
    movs r0, #1
    strh r0, [r3, #0x14]
    movs r0, #0x32
    adds r0, r0, r3
    mov ip, r0
    ldrb r1, [r0]
    movs r0, #0x40
    orrs r0, r1
    mov r1, ip
    strb r0, [r1]
    adds r1, r3, #0
    adds r1, #0x22
    movs r0, #0xe
    strb r0, [r1]
    adds r0, r3, #0
    adds r0, #0x2e
    strb r2, [r0]
    adds r0, #1
    strb r2, [r0]
    adds r1, #2
    movs r0, #0x28
    strb r0, [r1]
    b lbl_0804d2d8
    .align 2, 0
lbl_0804d2d0: .4byte 0x0000ffa0
lbl_0804d2d4:
    movs r0, #0
    strh r0, [r3]
lbl_0804d2d8:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MechaRidleyPartGlows
MechaRidleyPartGlows: @ 0x0804d2e0
    push {lr}
    bl sub_0804bb88
    bl MechaRidleyPartGreeGlow
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0804d2f0
sub_0804d2f0: @ 0x0804d2f0
    push {r4, lr}
    ldr r4, lbl_0804d328 @ =0x03000738
    adds r0, r4, #0
    adds r0, #0x2b
    ldrb r1, [r0]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0x10
    bne lbl_0804d308
    ldr r0, lbl_0804d32c @ =0x000002af
    bl SoundPlay
lbl_0804d308:
    ldr r0, lbl_0804d330 @ =0x0300080c
    ldrh r1, [r0, #0x12]
    ldr r3, lbl_0804d334 @ =0x0300070c
    ldrh r0, [r4, #0x14]
    strh r0, [r3, #0xa]
    ldrh r2, [r3, #0xa]
    lsls r0, r1, #1
    adds r0, r0, r1
    asrs r0, r0, #2
    cmp r2, r0
    bge lbl_0804d322
    movs r0, #1
    strb r0, [r3, #0xf]
lbl_0804d322:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804d328: .4byte 0x03000738
lbl_0804d32c: .4byte 0x000002af
lbl_0804d330: .4byte 0x0300080c
lbl_0804d334: .4byte 0x0300070c

    thumb_func_start MechaRidleyPartCoreCoverExplosion
MechaRidleyPartCoreCoverExplosion: @ 0x0804d338
    push {lr}
    ldr r3, lbl_0804d38c @ =0x03000738
    adds r0, r3, #0
    adds r0, #0x23
    ldrb r0, [r0]
    ldr r2, lbl_0804d390 @ =0x030001ac
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    adds r1, r1, r2
    ldrh r2, [r1]
    ldr r0, lbl_0804d394 @ =0x00007fff
    ands r0, r2
    strh r0, [r1]
    ldr r2, lbl_0804d398 @ =0x0300070c
    ldr r1, lbl_0804d39c @ =0x0300080c
    ldrh r0, [r1, #0x10]
    strh r0, [r2, #0xa]
    strh r0, [r1, #0xc]
    movs r0, #2
    strb r0, [r2, #0xf]
    ldrh r1, [r3]
    movs r0, #4
    orrs r0, r1
    strh r0, [r3]
    adds r1, r3, #0
    adds r1, #0x24
    movs r0, #0x67
    strb r0, [r1]
    ldrh r0, [r3, #2]
    adds r0, #0xc
    ldrh r1, [r3, #4]
    subs r1, #0x10
    movs r2, #0x1e
    bl ParticleSet
    ldr r0, lbl_0804d3a0 @ =0x0000012f
    bl SoundPlay
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804d38c: .4byte 0x03000738
lbl_0804d390: .4byte 0x030001ac
lbl_0804d394: .4byte 0x00007fff
lbl_0804d398: .4byte 0x0300070c
lbl_0804d39c: .4byte 0x0300080c
lbl_0804d3a0: .4byte 0x0000012f

    thumb_func_start sub_0804d3a4
sub_0804d3a4: @ 0x0804d3a4
    push {r4, r5, lr}
    sub sp, #0xc
    bl sub_0804bc2c
    ldr r5, lbl_0804d3c0 @ =0x0300080c
    ldrh r0, [r5, #8]
    cmp r0, #2
    beq lbl_0804d420
    cmp r0, #2
    bgt lbl_0804d3c4
    cmp r0, #1
    beq lbl_0804d3d0
    b lbl_0804d524
    .align 2, 0
lbl_0804d3c0: .4byte 0x0300080c
lbl_0804d3c4:
    cmp r0, #3
    beq lbl_0804d44c
    cmp r0, #4
    bne lbl_0804d3ce
    b lbl_0804d50c
lbl_0804d3ce:
    b lbl_0804d524
lbl_0804d3d0:
    ldr r0, lbl_0804d404 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #1
    bhi lbl_0804d3e8
    ldr r2, lbl_0804d408 @ =0x03001530
    ldrh r0, [r2, #6]
    cmp r0, #0x95
    bls lbl_0804d3e8
    ldrh r1, [r2, #8]
    ldrb r0, [r2, #0xa]
    cmn r1, r0
    bne lbl_0804d41c
lbl_0804d3e8:
    ldr r1, lbl_0804d40c @ =0x03000738
    ldr r0, lbl_0804d410 @ =0x08325d7c
    str r0, [r1, #0x18]
    movs r2, #0
    movs r0, #0
    strh r0, [r1, #0x16]
    strb r2, [r1, #0x1c]
    ldr r1, lbl_0804d414 @ =0x0300080c
    movs r0, #2
    strh r0, [r1, #8]
    ldr r0, lbl_0804d418 @ =0x000002a6
    bl SoundPlay
    b lbl_0804d524
    .align 2, 0
lbl_0804d404: .4byte 0x0300070c
lbl_0804d408: .4byte 0x03001530
lbl_0804d40c: .4byte 0x03000738
lbl_0804d410: .4byte 0x08325d7c
lbl_0804d414: .4byte 0x0300080c
lbl_0804d418: .4byte 0x000002a6
lbl_0804d41c:
    movs r0, #0
    b lbl_0804d522
lbl_0804d420:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    bne lbl_0804d42a
    b lbl_0804d524
lbl_0804d42a:
    ldr r1, lbl_0804d444 @ =0x03000738
    ldr r0, lbl_0804d448 @ =0x08325dc4
    str r0, [r1, #0x18]
    movs r2, #0
    movs r0, #0
    strh r0, [r1, #0x16]
    strb r2, [r1, #0x1c]
    movs r2, #3
    movs r0, #3
    strh r0, [r5, #8]
    adds r1, #0x2c
    strb r2, [r1]
    b lbl_0804d524
    .align 2, 0
lbl_0804d444: .4byte 0x03000738
lbl_0804d448: .4byte 0x08325dc4
lbl_0804d44c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    adds r4, r0, #0
    cmp r4, #0
    beq lbl_0804d480
    ldr r2, lbl_0804d478 @ =0x03000738
    adds r1, r2, #0
    adds r1, #0x2c
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_0804d524
    ldr r0, lbl_0804d47c @ =0x08325ddc
    str r0, [r2, #0x18]
    movs r0, #0
    strh r1, [r2, #0x16]
    strb r0, [r2, #0x1c]
    movs r0, #4
    b lbl_0804d522
    .align 2, 0
lbl_0804d478: .4byte 0x03000738
lbl_0804d47c: .4byte 0x08325ddc
lbl_0804d480:
    ldr r1, lbl_0804d4b8 @ =0x03000738
    ldrh r0, [r1, #0x16]
    cmp r0, #1
    bne lbl_0804d524
    ldrb r0, [r1, #0x1c]
    cmp r0, #1
    bne lbl_0804d524
    adds r0, r1, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0804d4bc
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    subs r0, #0x40
    str r0, [sp]
    ldrh r0, [r1, #4]
    subs r0, #0x30
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x48
    movs r1, #0
    bl SpriteSpawnSecondary
    b lbl_0804d524
    .align 2, 0
lbl_0804d4b8: .4byte 0x03000738
lbl_0804d4bc:
    cmp r0, #2
    bne lbl_0804d4e0
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    subs r0, #0x34
    str r0, [sp]
    ldrh r0, [r1, #4]
    subs r0, #0x3c
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x48
    movs r1, #1
    bl SpriteSpawnSecondary
    b lbl_0804d524
lbl_0804d4e0:
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    subs r0, #0x34
    str r0, [sp]
    ldrh r0, [r1, #4]
    subs r0, #0x24
    str r0, [sp, #4]
    str r4, [sp, #8]
    movs r0, #0x48
    movs r1, #2
    bl SpriteSpawnSecondary
    ldr r0, lbl_0804d508 @ =0x000002a7
    bl SoundPlay
    b lbl_0804d524
    .align 2, 0
lbl_0804d508: .4byte 0x000002a7
lbl_0804d50c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0804d524
    ldr r1, lbl_0804d52c @ =0x03000738
    ldr r0, lbl_0804d530 @ =0x08325d6c
    str r0, [r1, #0x18]
    movs r2, #0
    movs r0, #0
    strh r0, [r1, #0x16]
    strb r2, [r1, #0x1c]
lbl_0804d522:
    strh r0, [r5, #8]
lbl_0804d524:
    add sp, #0xc
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804d52c: .4byte 0x03000738
lbl_0804d530: .4byte 0x08325d6c

    thumb_func_start sub_0804d534
sub_0804d534: @ 0x0804d534
    push {r4, r5, r6, lr}
    sub sp, #0xc
    ldr r0, lbl_0804d550 @ =0x0300083c
    ldrb r1, [r0]
    ldr r4, lbl_0804d554 @ =0x0300080c
    ldrh r3, [r4, #6]
    cmp r3, #2
    beq lbl_0804d580
    cmp r3, #2
    bgt lbl_0804d558
    cmp r3, #1
    beq lbl_0804d55e
    b lbl_0804d712
    .align 2, 0
lbl_0804d550: .4byte 0x0300083c
lbl_0804d554: .4byte 0x0300080c
lbl_0804d558:
    cmp r3, #3
    beq lbl_0804d5b8
    b lbl_0804d712
lbl_0804d55e:
    ldr r2, lbl_0804d578 @ =0x03000738
    ldr r0, [r2, #0x18]
    ldr r1, lbl_0804d57c @ =0x0832574c
    cmp r0, r1
    beq lbl_0804d56a
    str r1, [r2, #0x18]
lbl_0804d56a:
    movs r0, #0
    movs r1, #0
    strh r3, [r2, #0x16]
    strb r0, [r2, #0x1c]
    strh r1, [r4, #6]
    b lbl_0804d712
    .align 2, 0
lbl_0804d578: .4byte 0x03000738
lbl_0804d57c: .4byte 0x0832574c
lbl_0804d580:
    ldr r0, lbl_0804d590 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #1
    bhi lbl_0804d594
    movs r0, #0
    strh r0, [r4, #6]
    b lbl_0804d712
    .align 2, 0
lbl_0804d590: .4byte 0x0300070c
lbl_0804d594:
    ldr r1, lbl_0804d5b0 @ =0x03000738
    ldr r0, lbl_0804d5b4 @ =0x08325784
    str r0, [r1, #0x18]
    movs r2, #0
    movs r0, #0
    strh r0, [r1, #0x16]
    strb r2, [r1, #0x1c]
    adds r1, #0x2c
    movs r0, #0x28
    strb r0, [r1]
    movs r0, #3
    strh r0, [r4, #6]
    b lbl_0804d712
    .align 2, 0
lbl_0804d5b0: .4byte 0x03000738
lbl_0804d5b4: .4byte 0x08325784
lbl_0804d5b8:
    ldr r4, lbl_0804d5ec @ =0x03000738
    adds r2, r4, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_0804d63c
    subs r0, #1
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0804d5d4
    b lbl_0804d712
lbl_0804d5d4:
    movs r2, #0
    strh r0, [r4, #0x16]
    strb r2, [r4, #0x1c]
    cmp r1, #0xb
    bls lbl_0804d5f4
    ldr r0, lbl_0804d5f0 @ =0x083257ec
    str r0, [r4, #0x18]
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #1
    strb r0, [r1]
    b lbl_0804d62a
    .align 2, 0
lbl_0804d5ec: .4byte 0x03000738
lbl_0804d5f0: .4byte 0x083257ec
lbl_0804d5f4:
    cmp r1, #7
    bls lbl_0804d608
    ldr r0, lbl_0804d604 @ =0x0832586c
    str r0, [r4, #0x18]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r3, [r0]
    b lbl_0804d62a
    .align 2, 0
lbl_0804d604: .4byte 0x0832586c
lbl_0804d608:
    cmp r1, #3
    bls lbl_0804d620
    ldr r0, lbl_0804d61c @ =0x0832582c
    str r0, [r4, #0x18]
    adds r1, r4, #0
    adds r1, #0x2d
    movs r0, #2
    strb r0, [r1]
    b lbl_0804d62a
    .align 2, 0
lbl_0804d61c: .4byte 0x0832582c
lbl_0804d620:
    ldr r0, lbl_0804d634 @ =0x083257ac
    str r0, [r4, #0x18]
    adds r0, r4, #0
    adds r0, #0x2d
    strb r2, [r0]
lbl_0804d62a:
    ldr r0, lbl_0804d638 @ =0x000002aa
    bl SoundPlay
    b lbl_0804d712
    .align 2, 0
lbl_0804d634: .4byte 0x083257ac
lbl_0804d638: .4byte 0x000002aa
lbl_0804d63c:
    bl SpriteUtilCheckEndCurrentSpriteAnim
    cmp r0, #0
    beq lbl_0804d712
    adds r0, r4, #0
    adds r0, #0x2d
    ldrb r5, [r0]
    cmp r5, #2
    beq lbl_0804d682
    cmp r5, #2
    bgt lbl_0804d658
    cmp r5, #1
    beq lbl_0804d662
    b lbl_0804d6e2
lbl_0804d658:
    cmp r5, #3
    beq lbl_0804d6a2
    cmp r5, #4
    beq lbl_0804d6c2
    b lbl_0804d6e2
lbl_0804d662:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    adds r0, #0x40
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x6c
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x47
    movs r1, #1
    bl SpriteSpawnSecondary
    b lbl_0804d702
lbl_0804d682:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    adds r0, #0x60
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x60
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x47
    movs r1, #2
    bl SpriteSpawnSecondary
    b lbl_0804d702
lbl_0804d6a2:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0x40
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x6c
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x47
    movs r1, #3
    bl SpriteSpawnSecondary
    b lbl_0804d702
lbl_0804d6c2:
    ldrb r2, [r4, #0x1f]
    adds r0, r4, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r4, #2]
    subs r0, #0x60
    str r0, [sp]
    ldrh r0, [r4, #4]
    subs r0, #0x60
    str r0, [sp, #4]
    str r6, [sp, #8]
    movs r0, #0x47
    movs r1, #4
    bl SpriteSpawnSecondary
    b lbl_0804d702
lbl_0804d6e2:
    ldr r1, lbl_0804d71c @ =0x03000738
    ldrb r2, [r1, #0x1f]
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r3, [r0]
    ldrh r0, [r1, #2]
    str r0, [sp]
    ldrh r0, [r1, #4]
    subs r0, #0x80
    str r0, [sp, #4]
    movs r0, #0
    str r0, [sp, #8]
    movs r0, #0x47
    adds r1, r5, #0
    bl SpriteSpawnSecondary
lbl_0804d702:
    ldr r1, lbl_0804d71c @ =0x03000738
    ldr r0, lbl_0804d720 @ =0x0832574c
    str r0, [r1, #0x18]
    movs r0, #0
    strb r0, [r1, #0x1c]
    strh r0, [r1, #0x16]
    ldr r1, lbl_0804d724 @ =0x0300080c
    strh r0, [r1, #6]
lbl_0804d712:
    add sp, #0xc
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804d71c: .4byte 0x03000738
lbl_0804d720: .4byte 0x0832574c
lbl_0804d724: .4byte 0x0300080c

    thumb_func_start sub_0804d728
sub_0804d728: @ 0x0804d728
    push {r4, r5, r6, r7, lr}
    ldr r1, lbl_0804d74c @ =0x03000738
    adds r0, r1, #0
    adds r0, #0x23
    ldrb r7, [r0]
    movs r6, #0
    movs r5, #0
    movs r4, #0
    movs r3, #0
    ldr r2, [r1, #0x18]
    ldr r0, lbl_0804d750 @ =0x08325acc
    mov ip, r1
    cmp r2, r0
    bne lbl_0804d754
    movs r6, #0x80
    movs r5, #0xc0
    subs r4, #0xe8
    b lbl_0804d912
    .align 2, 0
lbl_0804d74c: .4byte 0x03000738
lbl_0804d750: .4byte 0x08325acc
lbl_0804d754:
    ldr r0, lbl_0804d77c @ =0x083259f4
    cmp r2, r0
    bne lbl_0804d780
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #0
    bne lbl_0804d764
    b lbl_0804d90a
lbl_0804d764:
    cmp r0, #0
    bge lbl_0804d76a
    b lbl_0804d914
lbl_0804d76a:
    cmp r0, #4
    ble lbl_0804d770
    b lbl_0804d914
lbl_0804d770:
    movs r6, #0x20
    movs r5, #0x80
    movs r4, #0xa0
    rsbs r4, r4, #0
    b lbl_0804d912
    .align 2, 0
lbl_0804d77c: .4byte 0x083259f4
lbl_0804d780:
    ldr r0, lbl_0804d79c @ =0x08325964
    cmp r2, r0
    bne lbl_0804d842
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #0xa
    bls lbl_0804d790
    b lbl_0804d914
lbl_0804d790:
    lsls r0, r0, #2
    ldr r1, lbl_0804d7a0 @ =lbl_0804d7a4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804d79c: .4byte 0x08325964
lbl_0804d7a0: .4byte lbl_0804d7a4
lbl_0804d7a4: @ jump table
    .4byte lbl_0804d7d0 @ case 0
    .4byte lbl_0804d808 @ case 1
    .4byte lbl_0804d812 @ case 2
    .4byte lbl_0804d820 @ case 3
    .4byte lbl_0804d820 @ case 4
    .4byte lbl_0804d820 @ case 5
    .4byte lbl_0804d82c @ case 6
    .4byte lbl_0804d838 @ case 7
    .4byte lbl_0804d838 @ case 8
    .4byte lbl_0804d838 @ case 9
    .4byte lbl_0804d838 @ case 10
lbl_0804d7d0:
    ldr r0, lbl_0804d7fc @ =0x03000738
    ldrb r0, [r0, #0x1c]
    cmp r0, #1
    bne lbl_0804d7f0
    ldr r0, lbl_0804d800 @ =0x030001ac
    lsls r1, r7, #3
    subs r1, r1, r7
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_0804d7f0
    ldr r0, lbl_0804d804 @ =0x000002b2
    bl SoundPlay
lbl_0804d7f0:
    movs r6, #0x40
    movs r5, #0xc0
    movs r4, #0xc0
    rsbs r4, r4, #0
    b lbl_0804d8e6
    .align 2, 0
lbl_0804d7fc: .4byte 0x03000738
lbl_0804d800: .4byte 0x030001ac
lbl_0804d804: .4byte 0x000002b2
lbl_0804d808:
    movs r6, #0x40
    movs r5, #0xc0
    movs r4, #0xe0
    rsbs r4, r4, #0
    b lbl_0804d912
lbl_0804d812:
    movs r6, #0x40
    movs r5, #0xa0
    ldr r4, lbl_0804d81c @ =0xfffffee0
    b lbl_0804d912
    .align 2, 0
lbl_0804d81c: .4byte 0xfffffee0
lbl_0804d820:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804d828 @ =0xfffffec0
    b lbl_0804d912
    .align 2, 0
lbl_0804d828: .4byte 0xfffffec0
lbl_0804d82c:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804d834 @ =0xfffffee0
    b lbl_0804d912
    .align 2, 0
lbl_0804d834: .4byte 0xfffffee0
lbl_0804d838:
    movs r6, #0x80
    movs r5, #0xc0
    movs r4, #0xe0
    rsbs r4, r4, #0
    b lbl_0804d912
lbl_0804d842:
    ldr r0, lbl_0804d85c @ =0x08326064
    cmp r2, r0
    bne lbl_0804d914
    mov r1, ip
    ldrh r0, [r1, #0x16]
    cmp r0, #0xa
    bhi lbl_0804d914
    lsls r0, r0, #2
    ldr r1, lbl_0804d860 @ =lbl_0804d864
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804d85c: .4byte 0x08326064
lbl_0804d860: .4byte lbl_0804d864
lbl_0804d864: @ jump table
    .4byte lbl_0804d890 @ case 0
    .4byte lbl_0804d890 @ case 1
    .4byte lbl_0804d890 @ case 2
    .4byte lbl_0804d89a @ case 3
    .4byte lbl_0804d8a8 @ case 4
    .4byte lbl_0804d8b4 @ case 5
    .4byte lbl_0804d8b4 @ case 6
    .4byte lbl_0804d8c0 @ case 7
    .4byte lbl_0804d900 @ case 8
    .4byte lbl_0804d90a @ case 9
    .4byte lbl_0804d890 @ case 10
lbl_0804d890:
    movs r6, #0x80
    movs r5, #0xc0
    movs r4, #0xe0
    rsbs r4, r4, #0
    b lbl_0804d912
lbl_0804d89a:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804d8a4 @ =0xfffffee0
    b lbl_0804d912
    .align 2, 0
lbl_0804d8a4: .4byte 0xfffffee0
lbl_0804d8a8:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804d8b0 @ =0xfffffea0
    b lbl_0804d912
    .align 2, 0
lbl_0804d8b0: .4byte 0xfffffea0
lbl_0804d8b4:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804d8bc @ =0xfffffea0
    b lbl_0804d912
    .align 2, 0
lbl_0804d8bc: .4byte 0xfffffea0
lbl_0804d8c0:
    ldr r0, lbl_0804d8f0 @ =0x03000738
    ldrb r0, [r0, #0x1c]
    cmp r0, #1
    bne lbl_0804d8e0
    ldr r0, lbl_0804d8f4 @ =0x030001ac
    lsls r1, r7, #3
    subs r1, r1, r7
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_0804d8e0
    ldr r0, lbl_0804d8f8 @ =0x000002b2
    bl SoundPlay
lbl_0804d8e0:
    movs r6, #0x40
    movs r5, #0xa0
    ldr r4, lbl_0804d8fc @ =0xfffffee0
lbl_0804d8e6:
    movs r3, #0x40
    ldr r0, lbl_0804d8f0 @ =0x03000738
    mov ip, r0
    b lbl_0804d914
    .align 2, 0
lbl_0804d8f0: .4byte 0x03000738
lbl_0804d8f4: .4byte 0x030001ac
lbl_0804d8f8: .4byte 0x000002b2
lbl_0804d8fc: .4byte 0xfffffee0
lbl_0804d900:
    movs r6, #0x40
    movs r5, #0xc0
    movs r4, #0xe0
    rsbs r4, r4, #0
    b lbl_0804d912
lbl_0804d90a:
    movs r6, #0x40
    movs r5, #0xc0
    movs r4, #0xc0
    rsbs r4, r4, #0
lbl_0804d912:
    movs r3, #0x40
lbl_0804d914:
    mov r1, ip
    strh r6, [r1, #0xa]
    strh r5, [r1, #0xc]
    strh r4, [r1, #0xe]
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    strh r0, [r1, #0x10]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start MechaRidleyPartUpdateFrontClawHitbox
MechaRidleyPartUpdateFrontClawHitbox: @ 0x0804d928
    push {r4, r5, r6, r7, lr}
    movs r6, #0
    movs r5, #0
    movs r4, #0
    movs r3, #0
    ldr r0, lbl_0804d944 @ =0x03000738
    ldr r2, [r0, #0x18]
    ldr r1, lbl_0804d948 @ =0x08325a24
    adds r7, r0, #0
    cmp r2, r1
    bne lbl_0804d94c
    movs r6, #0x20
    movs r5, #0x80
    b lbl_0804db14
    .align 2, 0
lbl_0804d944: .4byte 0x03000738
lbl_0804d948: .4byte 0x08325a24
lbl_0804d94c:
    ldr r0, lbl_0804d970 @ =0x08325a94
    cmp r2, r0
    bne lbl_0804d954
    b lbl_0804daa6
lbl_0804d954:
    ldr r0, lbl_0804d974 @ =0x0832611c
    cmp r2, r0
    beq lbl_0804d95c
    b lbl_0804da64
lbl_0804d95c:
    ldrh r0, [r7, #0x16]
    cmp r0, #9
    bls lbl_0804d964
    b lbl_0804db4c
lbl_0804d964:
    lsls r0, r0, #2
    ldr r1, lbl_0804d978 @ =lbl_0804d97c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804d970: .4byte 0x08325a94
lbl_0804d974: .4byte 0x0832611c
lbl_0804d978: .4byte lbl_0804d97c
lbl_0804d97c: @ jump table
    .4byte lbl_0804d9a4 @ case 0
    .4byte lbl_0804d9c0 @ case 1
    .4byte lbl_0804d9ce @ case 2
    .4byte lbl_0804d9d6 @ case 3
    .4byte lbl_0804d9f8 @ case 4
    .4byte lbl_0804da04 @ case 5
    .4byte lbl_0804da14 @ case 6
    .4byte lbl_0804da24 @ case 7
    .4byte lbl_0804da3c @ case 8
    .4byte lbl_0804da54 @ case 9
lbl_0804d9a4:
    ldr r7, lbl_0804d9bc @ =0x03000738
    ldrb r0, [r7, #0x1c]
    cmp r0, #1
    bne lbl_0804d9b4
    movs r0, #0xa9
    lsls r0, r0, #2
    bl SoundPlay
lbl_0804d9b4:
    movs r6, #0x40
    rsbs r6, r6, #0
    movs r5, #0x40
    b lbl_0804db20
    .align 2, 0
lbl_0804d9bc: .4byte 0x03000738
lbl_0804d9c0:
    movs r6, #0xa0
    rsbs r6, r6, #0
    movs r5, #0x40
    movs r4, #0x80
    rsbs r4, r4, #0
    movs r3, #0x40
    b lbl_0804db4c
lbl_0804d9ce:
    movs r6, #0xd0
    rsbs r6, r6, #0
    movs r5, #0
    b lbl_0804db20
lbl_0804d9d6:
    ldr r7, lbl_0804d9ec @ =0x03000738
    ldrb r0, [r7, #0x1c]
    cmp r0, #0x14
    bne lbl_0804d9e4
    ldr r0, lbl_0804d9f0 @ =0x000002a5
    bl SoundPlay
lbl_0804d9e4:
    ldr r6, lbl_0804d9f4 @ =0xfffffee0
    movs r5, #0
    b lbl_0804db20
    .align 2, 0
lbl_0804d9ec: .4byte 0x03000738
lbl_0804d9f0: .4byte 0x000002a5
lbl_0804d9f4: .4byte 0xfffffee0
lbl_0804d9f8:
    ldr r6, lbl_0804da00 @ =0xfffffee0
    movs r5, #0
    b lbl_0804db38
    .align 2, 0
lbl_0804da00: .4byte 0xfffffee0
lbl_0804da04:
    movs r6, #0x80
    rsbs r6, r6, #0
    movs r5, #0
    ldr r4, lbl_0804da10 @ =0xfffffe50
    movs r3, #0x40
    b lbl_0804db4c
    .align 2, 0
lbl_0804da10: .4byte 0xfffffe50
lbl_0804da14:
    movs r6, #0
    movs r5, #0x50
    ldr r4, lbl_0804da20 @ =0xfffffe40
    movs r3, #0x40
    b lbl_0804db4c
    .align 2, 0
lbl_0804da20: .4byte 0xfffffe40
lbl_0804da24:
    ldr r0, lbl_0804da4c @ =0x03000738
    ldrb r0, [r0, #0x1c]
    cmp r0, #1
    bne lbl_0804da3c
    movs r0, #0x14
    movs r1, #0x81
    bl ScreenShakeStartVertical
    movs r0, #0xa8
    lsls r0, r0, #2
    bl SoundPlay
lbl_0804da3c:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804da50 @ =0xfffffe80
    movs r3, #0xc0
    rsbs r3, r3, #0
    ldr r7, lbl_0804da4c @ =0x03000738
    b lbl_0804db4c
    .align 2, 0
lbl_0804da4c: .4byte 0x03000738
lbl_0804da50: .4byte 0xfffffe80
lbl_0804da54:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804da60 @ =0xfffffeb0
    movs r3, #0xc0
    rsbs r3, r3, #0
    b lbl_0804db4c
    .align 2, 0
lbl_0804da60: .4byte 0xfffffeb0
lbl_0804da64:
    ldr r0, lbl_0804da7c @ =0x083259c4
    cmp r2, r0
    bne lbl_0804dac2
    ldrh r0, [r7, #0x16]
    cmp r0, #4
    bhi lbl_0804db4c
    lsls r0, r0, #2
    ldr r1, lbl_0804da80 @ =lbl_0804da84
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804da7c: .4byte 0x083259c4
lbl_0804da80: .4byte lbl_0804da84
lbl_0804da84: @ jump table
    .4byte lbl_0804daa6 @ case 0
    .4byte lbl_0804da98 @ case 1
    .4byte lbl_0804db34 @ case 2
    .4byte lbl_0804dabc @ case 3
    .4byte lbl_0804dabc @ case 4
lbl_0804da98:
    ldr r7, lbl_0804dab0 @ =0x03000738
    ldrb r0, [r7, #0x1c]
    cmp r0, #8
    bne lbl_0804daa6
    ldr r0, lbl_0804dab4 @ =0x000002a3
    bl SoundPlay
lbl_0804daa6:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804dab8 @ =0xfffffec0
    movs r3, #0x40
    b lbl_0804db4c
    .align 2, 0
lbl_0804dab0: .4byte 0x03000738
lbl_0804dab4: .4byte 0x000002a3
lbl_0804dab8: .4byte 0xfffffec0
lbl_0804dabc:
    movs r6, #0
    movs r5, #0x80
    b lbl_0804db14
lbl_0804dac2:
    ldr r0, lbl_0804dad8 @ =0x08325904
    cmp r2, r0
    bne lbl_0804db4c
    ldrh r0, [r7, #0x16]
    cmp r0, #0xa
    bhi lbl_0804db4c
    lsls r0, r0, #2
    ldr r1, lbl_0804dadc @ =lbl_0804dae0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804dad8: .4byte 0x08325904
lbl_0804dadc: .4byte lbl_0804dae0
lbl_0804dae0: @ jump table
    .4byte lbl_0804db0c @ case 0
    .4byte lbl_0804db10 @ case 1
    .4byte lbl_0804db10 @ case 2
    .4byte lbl_0804db10 @ case 3
    .4byte lbl_0804db10 @ case 4
    .4byte lbl_0804db1c @ case 5
    .4byte lbl_0804db28 @ case 6
    .4byte lbl_0804db34 @ case 7
    .4byte lbl_0804db44 @ case 8
    .4byte lbl_0804db44 @ case 9
    .4byte lbl_0804db44 @ case 10
lbl_0804db0c:
    movs r6, #0x80
    b lbl_0804db36
lbl_0804db10:
    movs r6, #0x80
    movs r5, #0xc0
lbl_0804db14:
    movs r4, #0xe0
    rsbs r4, r4, #0
    movs r3, #0x40
    b lbl_0804db4c
lbl_0804db1c:
    movs r6, #0x40
    movs r5, #0xc0
lbl_0804db20:
    movs r4, #0xa0
    rsbs r4, r4, #0
    movs r3, #0x40
    b lbl_0804db4c
lbl_0804db28:
    movs r6, #0x40
    movs r5, #0xc0
    movs r4, #0xc0
    rsbs r4, r4, #0
    movs r3, #0x40
    b lbl_0804db4c
lbl_0804db34:
    movs r6, #0x40
lbl_0804db36:
    movs r5, #0xc0
lbl_0804db38:
    ldr r4, lbl_0804db40 @ =0xffffff00
    movs r3, #0x40
    b lbl_0804db4c
    .align 2, 0
lbl_0804db40: .4byte 0xffffff00
lbl_0804db44:
    movs r6, #0x80
    movs r5, #0xc0
    ldr r4, lbl_0804db5c @ =0xfffffec0
    movs r3, #0x20
lbl_0804db4c:
    strh r6, [r7, #0xa]
    strh r5, [r7, #0xc]
    strh r4, [r7, #0xe]
    strh r3, [r7, #0x10]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804db5c: .4byte 0xfffffec0

    thumb_func_start sub_0804db60
sub_0804db60: @ 0x0804db60
    push {r4, r5, r6, r7, lr}
    movs r5, #0
    movs r4, #0
    movs r3, #0
    movs r2, #0
    ldr r6, lbl_0804db98 @ =0x03000738
    ldr r1, [r6, #0x18]
    ldr r0, lbl_0804db9c @ =0x08325b6c
    adds r7, r6, #0
    cmp r1, r0
    bne lbl_0804db78
    b lbl_0804dd38
lbl_0804db78:
    ldr r0, lbl_0804dba0 @ =0x08325d3c
    cmp r1, r0
    bne lbl_0804db80
    b lbl_0804dd38
lbl_0804db80:
    ldr r0, lbl_0804dba4 @ =0x08325b7c
    cmp r1, r0
    beq lbl_0804db8c
    ldr r0, lbl_0804dba8 @ =0x08325d4c
    cmp r1, r0
    bne lbl_0804dbac
lbl_0804db8c:
    movs r5, #0x60
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
    .align 2, 0
lbl_0804db98: .4byte 0x03000738
lbl_0804db9c: .4byte 0x08325b6c
lbl_0804dba0: .4byte 0x08325d3c
lbl_0804dba4: .4byte 0x08325b7c
lbl_0804dba8: .4byte 0x08325d4c
lbl_0804dbac:
    ldr r0, lbl_0804dbc4 @ =0x08325b8c
    cmp r1, r0
    beq lbl_0804dbb8
    ldr r0, lbl_0804dbc8 @ =0x08325d5c
    cmp r1, r0
    bne lbl_0804dbcc
lbl_0804dbb8:
    movs r5, #0xa0
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x40
    rsbs r3, r3, #0
    b lbl_0804dd42
    .align 2, 0
lbl_0804dbc4: .4byte 0x08325b8c
lbl_0804dbc8: .4byte 0x08325d5c
lbl_0804dbcc:
    ldr r0, lbl_0804dbf0 @ =0x08325c8c
    cmp r1, r0
    bne lbl_0804dc04
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_0804dbf8
    ldrb r0, [r7, #0x1c]
    cmp r0, #1
    bne lbl_0804dbe4
    ldr r0, lbl_0804dbf4 @ =0x000002ab
    bl SoundPlay
lbl_0804dbe4:
    movs r5, #0x40
    rsbs r5, r5, #0
    movs r4, #0x40
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
    .align 2, 0
lbl_0804dbf0: .4byte 0x08325c8c
lbl_0804dbf4: .4byte 0x000002ab
lbl_0804dbf8:
    movs r5, #0x60
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dc04:
    ldr r0, lbl_0804dc1c @ =0x08325ca4
    cmp r1, r0
    bne lbl_0804dc30
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_0804dc24
    ldrb r0, [r7, #0x1c]
    cmp r0, #1
    bne lbl_0804dcf8
    ldr r0, lbl_0804dc20 @ =0x000002ab
    b lbl_0804dcf4
    .align 2, 0
lbl_0804dc1c: .4byte 0x08325ca4
lbl_0804dc20: .4byte 0x000002ab
lbl_0804dc24:
    movs r5, #0xa0
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x40
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dc30:
    ldr r0, lbl_0804dc48 @ =0x08325cbc
    cmp r1, r0
    bne lbl_0804dc58
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_0804dc4c
    ldrb r0, [r7, #0x1c]
    cmp r0, #1
    bne lbl_0804dcf8
    movs r0, #0xab
    lsls r0, r0, #2
    b lbl_0804dcf4
    .align 2, 0
lbl_0804dc48: .4byte 0x08325cbc
lbl_0804dc4c:
    movs r5, #0x40
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dc58:
    ldr r0, lbl_0804dc80 @ =0x08325cd4
    cmp r1, r0
    bne lbl_0804dc84
    ldrh r0, [r7, #0x16]
    cmp r0, #0
    bne lbl_0804dd38
    ldrb r0, [r7, #0x1c]
    cmp r0, #1
    bne lbl_0804dc72
    movs r0, #0xab
    lsls r0, r0, #2
    bl SoundPlay
lbl_0804dc72:
    movs r5, #0x40
    rsbs r5, r5, #0
    movs r4, #0x40
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd02
    .align 2, 0
lbl_0804dc80: .4byte 0x08325cd4
lbl_0804dc84:
    ldr r1, [r6, #0x18]
    ldr r0, lbl_0804dcac @ =0x08325cec
    cmp r1, r0
    bne lbl_0804dce0
    ldrh r0, [r6, #0x16]
    cmp r0, #0
    bne lbl_0804dcb4
    ldrb r0, [r6, #0x1c]
    cmp r0, #1
    bne lbl_0804dc9e
    ldr r0, lbl_0804dcb0 @ =0x000002a1
    bl SoundPlay
lbl_0804dc9e:
    movs r5, #0x40
    rsbs r5, r5, #0
    movs r4, #0x40
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd02
    .align 2, 0
lbl_0804dcac: .4byte 0x08325cec
lbl_0804dcb0: .4byte 0x000002a1
lbl_0804dcb4:
    cmp r0, #1
    bne lbl_0804dcc4
    movs r5, #0x60
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dcc4:
    cmp r0, #2
    bne lbl_0804dcd0
    movs r5, #0x80
    rsbs r5, r5, #0
    movs r4, #0
    b lbl_0804dd3e
lbl_0804dcd0:
    cmp r0, #3
    bne lbl_0804dd44
    movs r5, #0xa0
    rsbs r5, r5, #0
    movs r4, #0
    movs r3, #0x40
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dce0:
    ldr r0, lbl_0804dd08 @ =0x08325d14
    cmp r1, r0
    bne lbl_0804dd44
    ldrh r0, [r6, #0x16]
    cmp r0, #0
    bne lbl_0804dd14
    ldrb r0, [r6, #0x1c]
    cmp r0, #1
    bne lbl_0804dcf8
    ldr r0, lbl_0804dd0c @ =0x000002a2
lbl_0804dcf4:
    bl SoundPlay
lbl_0804dcf8:
    movs r5, #0x80
    rsbs r5, r5, #0
    movs r4, #0
    movs r3, #0x60
    rsbs r3, r3, #0
lbl_0804dd02:
    movs r2, #0x20
    ldr r7, lbl_0804dd10 @ =0x03000738
    b lbl_0804dd44
    .align 2, 0
lbl_0804dd08: .4byte 0x08325d14
lbl_0804dd0c: .4byte 0x000002a2
lbl_0804dd10: .4byte 0x03000738
lbl_0804dd14:
    cmp r0, #1
    bne lbl_0804dd24
    movs r5, #0x60
    rsbs r5, r5, #0
    movs r4, #0x10
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dd24:
    cmp r0, #2
    bne lbl_0804dd34
    movs r5, #0x40
    rsbs r5, r5, #0
    movs r4, #0x40
    movs r3, #0x80
    rsbs r3, r3, #0
    b lbl_0804dd42
lbl_0804dd34:
    cmp r0, #3
    bne lbl_0804dd44
lbl_0804dd38:
    movs r5, #0x20
    rsbs r5, r5, #0
    movs r4, #0x60
lbl_0804dd3e:
    movs r3, #0x60
    rsbs r3, r3, #0
lbl_0804dd42:
    movs r2, #0x20
lbl_0804dd44:
    strh r5, [r7, #0xa]
    strh r4, [r7, #0xc]
    strh r3, [r7, #0xe]
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    strh r0, [r7, #0x10]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MechaRidley
MechaRidley: @ 0x0804dd58
    push {r4, r5, lr}
    ldr r4, lbl_0804dda8 @ =0x03000738
    adds r2, r4, #0
    adds r2, #0x32
    ldrb r1, [r2]
    movs r5, #2
    adds r0, r5, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_0804dd78
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r2]
    ldr r0, lbl_0804ddac @ =0x000002af
    bl SoundPlay
lbl_0804dd78:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0804de12
    ldr r0, lbl_0804ddb0 @ =0x030013d4
    ldrh r1, [r0, #0x14]
    ldr r0, lbl_0804ddb4 @ =0x0300070c
    ldrh r0, [r0, #6]
    subs r0, #0x40
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r1, r0
    bls lbl_0804ddd4
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0804ddbc
    ldr r0, lbl_0804ddb8 @ =0x0300080c
    ldrh r0, [r0, #4]
    cmp r0, #0
    beq lbl_0804de12
    b lbl_0804ddfa
    .align 2, 0
lbl_0804dda8: .4byte 0x03000738
lbl_0804ddac: .4byte 0x000002af
lbl_0804ddb0: .4byte 0x030013d4
lbl_0804ddb4: .4byte 0x0300070c
lbl_0804ddb8: .4byte 0x0300080c
lbl_0804ddbc:
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    bne lbl_0804de12
    ldr r0, lbl_0804ddd0 @ =0x0300080c
    strh r1, [r0, #4]
    b lbl_0804de12
    .align 2, 0
lbl_0804ddd0: .4byte 0x0300080c
lbl_0804ddd4:
    subs r0, r0, r1
    cmp r0, #0xc0
    ble lbl_0804dde4
    ldr r0, lbl_0804dde0 @ =0x0300080c
    strh r5, [r0, #4]
    b lbl_0804de12
    .align 2, 0
lbl_0804dde0: .4byte 0x0300080c
lbl_0804dde4:
    ldr r3, lbl_0804de00 @ =0x0300080c
    ldrh r2, [r3, #4]
    cmp r2, #0
    beq lbl_0804de0e
    adds r1, r4, #0
    adds r1, #0x2a
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_0804de04
    cmp r2, #1
    beq lbl_0804de12
lbl_0804ddfa:
    movs r0, #0x78
    strb r0, [r1]
    b lbl_0804de12
    .align 2, 0
lbl_0804de00: .4byte 0x0300080c
lbl_0804de04:
    subs r0, #1
    strb r0, [r1]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0804de12
lbl_0804de0e:
    movs r0, #1
    strh r0, [r3, #4]
lbl_0804de12:
    ldr r0, lbl_0804de28 @ =0x03000738
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x6a
    bls lbl_0804de1e
    b lbl_0804e064
lbl_0804de1e:
    lsls r0, r0, #2
    ldr r1, lbl_0804de2c @ =lbl_0804de30
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804de28: .4byte 0x03000738
lbl_0804de2c: .4byte lbl_0804de30
lbl_0804de30: @ jump table
    .4byte lbl_0804dfdc @ case 0
    .4byte lbl_0804dfe2 @ case 1
    .4byte lbl_0804dfe8 @ case 2
    .4byte lbl_0804dfee @ case 3
    .4byte lbl_0804dff4 @ case 4
    .4byte lbl_0804e064 @ case 5
    .4byte lbl_0804e064 @ case 6
    .4byte lbl_0804e064 @ case 7
    .4byte lbl_0804e064 @ case 8
    .4byte lbl_0804dffa @ case 9
    .4byte lbl_0804e064 @ case 10
    .4byte lbl_0804e064 @ case 11
    .4byte lbl_0804e064 @ case 12
    .4byte lbl_0804e064 @ case 13
    .4byte lbl_0804e064 @ case 14
    .4byte lbl_0804e064 @ case 15
    .4byte lbl_0804e064 @ case 16
    .4byte lbl_0804e064 @ case 17
    .4byte lbl_0804e064 @ case 18
    .4byte lbl_0804e064 @ case 19
    .4byte lbl_0804e064 @ case 20
    .4byte lbl_0804e064 @ case 21
    .4byte lbl_0804e064 @ case 22
    .4byte lbl_0804e064 @ case 23
    .4byte lbl_0804e064 @ case 24
    .4byte lbl_0804e064 @ case 25
    .4byte lbl_0804e064 @ case 26
    .4byte lbl_0804e064 @ case 27
    .4byte lbl_0804e064 @ case 28
    .4byte lbl_0804e064 @ case 29
    .4byte lbl_0804e064 @ case 30
    .4byte lbl_0804e064 @ case 31
    .4byte lbl_0804e064 @ case 32
    .4byte lbl_0804e064 @ case 33
    .4byte lbl_0804e000 @ case 34
    .4byte lbl_0804e006 @ case 35
    .4byte lbl_0804e064 @ case 36
    .4byte lbl_0804e00c @ case 37
    .4byte lbl_0804e064 @ case 38
    .4byte lbl_0804e012 @ case 39
    .4byte lbl_0804e064 @ case 40
    .4byte lbl_0804e018 @ case 41
    .4byte lbl_0804e064 @ case 42
    .4byte lbl_0804e064 @ case 43
    .4byte lbl_0804e064 @ case 44
    .4byte lbl_0804e064 @ case 45
    .4byte lbl_0804e064 @ case 46
    .4byte lbl_0804e064 @ case 47
    .4byte lbl_0804e064 @ case 48
    .4byte lbl_0804e064 @ case 49
    .4byte lbl_0804e064 @ case 50
    .4byte lbl_0804e064 @ case 51
    .4byte lbl_0804e01e @ case 52
    .4byte lbl_0804e024 @ case 53
    .4byte lbl_0804e064 @ case 54
    .4byte lbl_0804e02a @ case 55
    .4byte lbl_0804e064 @ case 56
    .4byte lbl_0804e030 @ case 57
    .4byte lbl_0804e064 @ case 58
    .4byte lbl_0804e036 @ case 59
    .4byte lbl_0804e064 @ case 60
    .4byte lbl_0804e03c @ case 61
    .4byte lbl_0804e064 @ case 62
    .4byte lbl_0804e064 @ case 63
    .4byte lbl_0804e064 @ case 64
    .4byte lbl_0804e064 @ case 65
    .4byte lbl_0804e064 @ case 66
    .4byte lbl_0804e064 @ case 67
    .4byte lbl_0804e064 @ case 68
    .4byte lbl_0804e064 @ case 69
    .4byte lbl_0804e064 @ case 70
    .4byte lbl_0804e064 @ case 71
    .4byte lbl_0804e064 @ case 72
    .4byte lbl_0804e064 @ case 73
    .4byte lbl_0804e064 @ case 74
    .4byte lbl_0804e064 @ case 75
    .4byte lbl_0804e064 @ case 76
    .4byte lbl_0804e064 @ case 77
    .4byte lbl_0804e064 @ case 78
    .4byte lbl_0804e064 @ case 79
    .4byte lbl_0804e064 @ case 80
    .4byte lbl_0804e064 @ case 81
    .4byte lbl_0804e064 @ case 82
    .4byte lbl_0804e064 @ case 83
    .4byte lbl_0804e064 @ case 84
    .4byte lbl_0804e064 @ case 85
    .4byte lbl_0804e064 @ case 86
    .4byte lbl_0804e064 @ case 87
    .4byte lbl_0804e064 @ case 88
    .4byte lbl_0804e064 @ case 89
    .4byte lbl_0804e064 @ case 90
    .4byte lbl_0804e064 @ case 91
    .4byte lbl_0804e064 @ case 92
    .4byte lbl_0804e064 @ case 93
    .4byte lbl_0804e064 @ case 94
    .4byte lbl_0804e064 @ case 95
    .4byte lbl_0804e064 @ case 96
    .4byte lbl_0804e064 @ case 97
    .4byte lbl_0804e042 @ case 98
    .4byte lbl_0804e064 @ case 99
    .4byte lbl_0804e04e @ case 100
    .4byte lbl_0804e064 @ case 101
    .4byte lbl_0804e064 @ case 102
    .4byte lbl_0804e048 @ case 103
    .4byte lbl_0804e054 @ case 104
    .4byte lbl_0804e05a @ case 105
    .4byte lbl_0804e060 @ case 106
lbl_0804dfdc:
    bl MechaRidleyInit
    b lbl_0804e064
lbl_0804dfe2:
    bl MechaRidleyStartWalking
    b lbl_0804e064
lbl_0804dfe8:
    bl MechaRidleyDelayBeforeCrawling
    b lbl_0804e064
lbl_0804dfee:
    bl MechaRidleyCrawling
    b lbl_0804e064
lbl_0804dff4:
    bl MechaRidleyStartBattle
    b lbl_0804e064
lbl_0804dffa:
    bl sub_0804c3c8
    b lbl_0804e064
lbl_0804e000:
    bl ridley_claw_attack
    b lbl_0804e064
lbl_0804e006:
    bl MechaRidleyStandingUp
    b lbl_0804e064
lbl_0804e00c:
    bl MechaRidleyCurledUp
    b lbl_0804e064
lbl_0804e012:
    bl MechaRidleyCheckRetractingHeadBeforeMovingBackAnimEnded
    b lbl_0804e064
lbl_0804e018:
    bl MechaRidleyMovingBack
    b lbl_0804e064
lbl_0804e01e:
    bl MechaRidleyBeforeFireballs
    b lbl_0804e064
lbl_0804e024:
    bl MechaRidleyCheckExtendingHeadBeforeFireballsAnimEnded
    b lbl_0804e064
lbl_0804e02a:
    bl MechaRidleyCheckOpeningMouthAnimEnded
    b lbl_0804e064
lbl_0804e030:
    bl MechaRidleyFireballsAttack
    b lbl_0804e064
lbl_0804e036:
    bl mecha_ridley_check_closing_mouth_anim_ended
    b lbl_0804e064
lbl_0804e03c:
    bl MechaRidleyCheckRetractingHeadAfterFireballsAnimEnded
    b lbl_0804e064
lbl_0804e042:
    bl MechaRidleyStartDying
    b lbl_0804e064
lbl_0804e048:
    bl MechaRidleyDying
    b lbl_0804e064
lbl_0804e04e:
    bl MechaRidleyGlowFading
    b lbl_0804e064
lbl_0804e054:
    bl MechaRidleySpawnDrops
    b lbl_0804e064
lbl_0804e05a:
    bl MechaRidleyFirstEyeGlow
    b lbl_0804e064
lbl_0804e060:
    bl MechaRidleySecondEyeGlow
lbl_0804e064:
    ldr r0, lbl_0804e088 @ =0x0300070c
    ldrb r1, [r0, #0xf]
    ldr r5, lbl_0804e08c @ =0x03000738
    adds r3, r0, #0
    cmp r1, #1
    bls lbl_0804e0ae
    ldrh r0, [r5, #0x14]
    strh r0, [r3, #0xa]
    ldr r1, lbl_0804e090 @ =0x0300080c
    ldrh r1, [r1, #0x10]
    adds r4, r1, #0
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsrs r0, r1, #2
    cmp r2, r0
    bhs lbl_0804e094
    movs r0, #5
    b lbl_0804e0ac
    .align 2, 0
lbl_0804e088: .4byte 0x0300070c
lbl_0804e08c: .4byte 0x03000738
lbl_0804e090: .4byte 0x0300080c
lbl_0804e094:
    lsrs r0, r1, #1
    cmp r2, r0
    bhs lbl_0804e09e
    movs r0, #4
    b lbl_0804e0ac
lbl_0804e09e:
    ldrh r1, [r3, #0xa]
    lsls r0, r4, #1
    adds r0, r0, r4
    asrs r0, r0, #2
    cmp r1, r0
    bge lbl_0804e0ae
    movs r0, #3
lbl_0804e0ac:
    strb r0, [r3, #0xf]
lbl_0804e0ae:
    adds r1, r5, #0
    adds r1, #0x2f
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #9
    beq lbl_0804e0c6
    cmp r0, #0x25
    bne lbl_0804e0cc
lbl_0804e0c6:
    ldrb r0, [r3, #0xe]
    adds r0, #1
    strb r0, [r3, #0xe]
lbl_0804e0cc:
    bl SpriteUtilUpdateSubSprite1Anim
    bl mecha_ridley_sync_sub_sprites_pos
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MechaRidleyPart
MechaRidleyPart: @ 0x0804e0dc
    push {r4, r5, r6, r7, lr}
    ldr r2, lbl_0804e130 @ =0x03000738
    adds r0, r2, #0
    adds r0, #0x23
    ldrb r6, [r0]
    ldrb r3, [r2, #0x1e]
    adds r7, r3, #0
    ldr r0, lbl_0804e134 @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r5, r1, r0
    adds r0, r5, #0
    adds r0, #0x24
    ldrb r1, [r0]
    adds r4, r2, #0
    cmp r1, #0x61
    bhi lbl_0804e102
    b lbl_0804e1f4
lbl_0804e102:
    adds r1, r4, #0
    adds r1, #0x26
    movs r0, #1
    strb r0, [r1]
    ldrh r1, [r4]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r0, r2, #0
    orrs r0, r1
    strh r0, [r4]
    adds r0, r5, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x2b
    strb r0, [r1]
    cmp r3, #0xa
    bhi lbl_0804e1a8
    lsls r0, r3, #2
    ldr r1, lbl_0804e138 @ =lbl_0804e13c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804e130: .4byte 0x03000738
lbl_0804e134: .4byte 0x030001ac
lbl_0804e138: .4byte lbl_0804e13c
lbl_0804e13c: @ jump table
    .4byte lbl_0804e168 @ case 0
    .4byte lbl_0804e170 @ case 1
    .4byte lbl_0804e178 @ case 2
    .4byte lbl_0804e180 @ case 3
    .4byte lbl_0804e1a8 @ case 4
    .4byte lbl_0804e1a8 @ case 5
    .4byte lbl_0804e188 @ case 6
    .4byte lbl_0804e190 @ case 7
    .4byte lbl_0804e198 @ case 8
    .4byte lbl_0804e1a0 @ case 9
    .4byte lbl_0804e1a0 @ case 10
lbl_0804e168:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #9
    b lbl_0804e1a6
lbl_0804e170:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xa
    b lbl_0804e1a6
lbl_0804e178:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xb
    b lbl_0804e1a6
lbl_0804e180:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xc
    b lbl_0804e1a6
lbl_0804e188:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xd
    b lbl_0804e1a6
lbl_0804e190:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xe
    b lbl_0804e1a6
lbl_0804e198:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0xf
    b lbl_0804e1a6
lbl_0804e1a0:
    adds r1, r4, #0
    adds r1, #0x22
    movs r0, #0x10
lbl_0804e1a6:
    strb r0, [r1]
lbl_0804e1a8:
    cmp r7, #1
    beq lbl_0804e1ae
    b lbl_0804e42c
lbl_0804e1ae:
    ldr r2, lbl_0804e1c0 @ =0x0300080c
    ldrh r0, [r2, #6]
    cmp r0, #5
    beq lbl_0804e1d4
    cmp r0, #5
    bgt lbl_0804e1c4
    cmp r0, #4
    beq lbl_0804e1ca
    b lbl_0804e476
    .align 2, 0
lbl_0804e1c0: .4byte 0x0300080c
lbl_0804e1c4:
    cmp r0, #6
    beq lbl_0804e1dc
    b lbl_0804e476
lbl_0804e1ca:
    ldr r0, lbl_0804e1d0 @ =0x0832574c
    b lbl_0804e1de
    .align 2, 0
lbl_0804e1d0: .4byte 0x0832574c
lbl_0804e1d4:
    ldr r0, lbl_0804e1d8 @ =0x083258ec
    b lbl_0804e1de
    .align 2, 0
lbl_0804e1d8: .4byte 0x083258ec
lbl_0804e1dc:
    ldr r0, lbl_0804e1f0 @ =0x08326174
lbl_0804e1de:
    str r0, [r4, #0x18]
    movs r1, #0
    movs r0, #0
    strh r0, [r4, #0x16]
    strb r1, [r4, #0x1c]
    movs r0, #7
    strh r0, [r2, #6]
    b lbl_0804e476
    .align 2, 0
lbl_0804e1f0: .4byte 0x08326174
lbl_0804e1f4:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0804e26e
    ldrh r0, [r4, #0x14]
    cmp r0, #0
    beq lbl_0804e26e
    cmp r7, #1
    bne lbl_0804e224
    ldr r0, lbl_0804e220 @ =0x0300070c
    ldrb r0, [r0, #0xf]
    cmp r0, #1
    bls lbl_0804e26e
    adds r0, r5, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x2b
    strb r0, [r1]
    b lbl_0804e26e
    .align 2, 0
lbl_0804e220: .4byte 0x0300070c
lbl_0804e224:
    cmp r1, #2
    bls lbl_0804e22c
    bl BlackSpacePirateProjectileCollision
lbl_0804e22c:
    ldr r0, lbl_0804e254 @ =0x0300070c
    ldrb r2, [r0, #0xf]
    cmp r2, #1
    bls lbl_0804e26e
    adds r0, r5, #0
    adds r0, #0x2b
    ldrb r0, [r0]
    adds r1, r4, #0
    adds r1, #0x2b
    strb r0, [r1]
    adds r3, r4, #0
    adds r3, #0x20
    ldrb r0, [r3]
    cmp r0, #0xe
    beq lbl_0804e26e
    adds r0, r2, #0
    cmp r0, #4
    bls lbl_0804e258
    movs r1, #4
    b lbl_0804e266
    .align 2, 0
lbl_0804e254: .4byte 0x0300070c
lbl_0804e258:
    cmp r0, #3
    bls lbl_0804e260
    movs r1, #3
    b lbl_0804e266
lbl_0804e260:
    cmp r2, #2
    bls lbl_0804e26e
    movs r1, #2
lbl_0804e266:
    strb r1, [r3]
    adds r0, r4, #0
    adds r0, #0x34
    strb r1, [r0]
lbl_0804e26e:
    adds r0, r4, #0
    adds r0, #0x24
    ldrb r0, [r0]
    cmp r0, #0x67
    bls lbl_0804e27a
    b lbl_0804e494
lbl_0804e27a:
    lsls r0, r0, #2
    ldr r1, lbl_0804e284 @ =lbl_0804e288
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0804e284: .4byte lbl_0804e288
lbl_0804e288: @ jump table
    .4byte lbl_0804e428 @ case 0
    .4byte lbl_0804e494 @ case 1
    .4byte lbl_0804e494 @ case 2
    .4byte lbl_0804e494 @ case 3
    .4byte lbl_0804e494 @ case 4
    .4byte lbl_0804e494 @ case 5
    .4byte lbl_0804e494 @ case 6
    .4byte lbl_0804e494 @ case 7
    .4byte lbl_0804e432 @ case 8
    .4byte lbl_0804e494 @ case 9
    .4byte lbl_0804e494 @ case 10
    .4byte lbl_0804e494 @ case 11
    .4byte lbl_0804e494 @ case 12
    .4byte lbl_0804e494 @ case 13
    .4byte lbl_0804e498 @ case 14
    .4byte lbl_0804e494 @ case 15
    .4byte lbl_0804e494 @ case 16
    .4byte lbl_0804e494 @ case 17
    .4byte lbl_0804e494 @ case 18
    .4byte lbl_0804e494 @ case 19
    .4byte lbl_0804e494 @ case 20
    .4byte lbl_0804e494 @ case 21
    .4byte lbl_0804e494 @ case 22
    .4byte lbl_0804e494 @ case 23
    .4byte lbl_0804e494 @ case 24
    .4byte lbl_0804e494 @ case 25
    .4byte lbl_0804e494 @ case 26
    .4byte lbl_0804e494 @ case 27
    .4byte lbl_0804e494 @ case 28
    .4byte lbl_0804e494 @ case 29
    .4byte lbl_0804e494 @ case 30
    .4byte lbl_0804e494 @ case 31
    .4byte lbl_0804e494 @ case 32
    .4byte lbl_0804e494 @ case 33
    .4byte lbl_0804e450 @ case 34
    .4byte lbl_0804e494 @ case 35
    .4byte lbl_0804e46c @ case 36
    .4byte lbl_0804e494 @ case 37
    .4byte lbl_0804e472 @ case 38
    .4byte lbl_0804e494 @ case 39
    .4byte lbl_0804e47c @ case 40
    .4byte lbl_0804e494 @ case 41
    .4byte lbl_0804e482 @ case 42
    .4byte lbl_0804e494 @ case 43
    .4byte lbl_0804e48e @ case 44
    .4byte lbl_0804e494 @ case 45
    .4byte lbl_0804e494 @ case 46
    .4byte lbl_0804e494 @ case 47
    .4byte lbl_0804e494 @ case 48
    .4byte lbl_0804e494 @ case 49
    .4byte lbl_0804e494 @ case 50
    .4byte lbl_0804e494 @ case 51
    .4byte lbl_0804e494 @ case 52
    .4byte lbl_0804e494 @ case 53
    .4byte lbl_0804e494 @ case 54
    .4byte lbl_0804e494 @ case 55
    .4byte lbl_0804e494 @ case 56
    .4byte lbl_0804e494 @ case 57
    .4byte lbl_0804e494 @ case 58
    .4byte lbl_0804e494 @ case 59
    .4byte lbl_0804e494 @ case 60
    .4byte lbl_0804e494 @ case 61
    .4byte lbl_0804e494 @ case 62
    .4byte lbl_0804e494 @ case 63
    .4byte lbl_0804e494 @ case 64
    .4byte lbl_0804e494 @ case 65
    .4byte lbl_0804e498 @ case 66
    .4byte lbl_0804e498 @ case 67
    .4byte lbl_0804e494 @ case 68
    .4byte lbl_0804e494 @ case 69
    .4byte lbl_0804e494 @ case 70
    .4byte lbl_0804e494 @ case 71
    .4byte lbl_0804e494 @ case 72
    .4byte lbl_0804e494 @ case 73
    .4byte lbl_0804e494 @ case 74
    .4byte lbl_0804e494 @ case 75
    .4byte lbl_0804e494 @ case 76
    .4byte lbl_0804e494 @ case 77
    .4byte lbl_0804e494 @ case 78
    .4byte lbl_0804e494 @ case 79
    .4byte lbl_0804e494 @ case 80
    .4byte lbl_0804e494 @ case 81
    .4byte lbl_0804e494 @ case 82
    .4byte lbl_0804e494 @ case 83
    .4byte lbl_0804e494 @ case 84
    .4byte lbl_0804e494 @ case 85
    .4byte lbl_0804e494 @ case 86
    .4byte lbl_0804e494 @ case 87
    .4byte lbl_0804e494 @ case 88
    .4byte lbl_0804e494 @ case 89
    .4byte lbl_0804e494 @ case 90
    .4byte lbl_0804e494 @ case 91
    .4byte lbl_0804e494 @ case 92
    .4byte lbl_0804e494 @ case 93
    .4byte lbl_0804e494 @ case 94
    .4byte lbl_0804e494 @ case 95
    .4byte lbl_0804e494 @ case 96
    .4byte lbl_0804e494 @ case 97
    .4byte lbl_0804e488 @ case 98
    .4byte lbl_0804e494 @ case 99
    .4byte lbl_0804e494 @ case 100
    .4byte lbl_0804e494 @ case 101
    .4byte lbl_0804e494 @ case 102
    .4byte lbl_0804e498 @ case 103
lbl_0804e428:
    bl MechaRidleyPartInit
lbl_0804e42c:
    bl mecha_ridley_sync_sub_sprites_pos
    b lbl_0804e498
lbl_0804e432:
    bl sub_0804d728
    ldr r0, lbl_0804e44c @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_0804e42c
    b lbl_0804e476
    .align 2, 0
lbl_0804e44c: .4byte 0x030001ac
lbl_0804e450:
    bl MechaRidleyPartUpdateFrontClawHitbox
    ldr r0, lbl_0804e468 @ =0x030001ac
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    adds r1, r1, r0
    adds r1, #0x24
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_0804e42c
    b lbl_0804e476
    .align 2, 0
lbl_0804e468: .4byte 0x030001ac
lbl_0804e46c:
    bl sub_0804db60
    b lbl_0804e42c
lbl_0804e472:
    bl sub_0804d534
lbl_0804e476:
    bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
    b lbl_0804e498
lbl_0804e47c:
    bl sub_0804d3a4
    b lbl_0804e476
lbl_0804e482:
    bl sub_0804d2f0
    b lbl_0804e42c
lbl_0804e488:
    bl MechaRidleyPartCoreCoverExplosion
    b lbl_0804e498
lbl_0804e48e:
    bl MechaRidleyPartGlows
    b lbl_0804e42c
lbl_0804e494:
    bl mecha_ridley_sync_sub_sprites_pos
lbl_0804e498:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start MechaRidleyLaser
MechaRidleyLaser: @ 0x0804e4a0
    push {r4, r5, lr}
    ldr r0, lbl_0804e4fc @ =0x03000738
    adds r5, r0, #0
    adds r5, #0x24
    ldrb r3, [r5]
    adds r4, r0, #0
    cmp r3, #0
    bne lbl_0804e538
    ldrh r1, [r4]
    ldr r0, lbl_0804e500 @ =0x0000fffb
    ands r0, r1
    movs r2, #0
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #8
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0804e504 @ =0x0000ffe0
    strh r1, [r4, #0xa]
    movs r0, #0x20
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    adds r1, r4, #0
    adds r1, #0x25
    movs r0, #4
    strb r0, [r1]
    subs r1, #3
    movs r0, #3
    strb r0, [r1]
    movs r0, #9
    strb r0, [r5]
    strb r2, [r4, #0x1c]
    strh r3, [r4, #0x16]
    ldrb r0, [r4, #0x1e]
    cmp r0, #2
    beq lbl_0804e51c
    cmp r0, #2
    bgt lbl_0804e508
    cmp r0, #1
    beq lbl_0804e512
    b lbl_0804e534
    .align 2, 0
lbl_0804e4fc: .4byte 0x03000738
lbl_0804e500: .4byte 0x0000fffb
lbl_0804e504: .4byte 0x0000ffe0
lbl_0804e508:
    cmp r0, #3
    beq lbl_0804e524
    cmp r0, #4
    beq lbl_0804e52c
    b lbl_0804e534
lbl_0804e512:
    ldr r0, lbl_0804e518 @ =0x08325e7c
    b lbl_0804e536
    .align 2, 0
lbl_0804e518: .4byte 0x08325e7c
lbl_0804e51c:
    ldr r0, lbl_0804e520 @ =0x08325e9c
    b lbl_0804e536
    .align 2, 0
lbl_0804e520: .4byte 0x08325e9c
lbl_0804e524:
    ldr r0, lbl_0804e528 @ =0x08325ebc
    b lbl_0804e536
    .align 2, 0
lbl_0804e528: .4byte 0x08325ebc
lbl_0804e52c:
    ldr r0, lbl_0804e530 @ =0x08325edc
    b lbl_0804e536
    .align 2, 0
lbl_0804e530: .4byte 0x08325edc
lbl_0804e534:
    ldr r0, lbl_0804e548 @ =0x08325e5c
lbl_0804e536:
    str r0, [r4, #0x18]
lbl_0804e538:
    ldrb r0, [r4, #0x1e]
    cmp r0, #2
    beq lbl_0804e562
    cmp r0, #2
    bgt lbl_0804e54c
    cmp r0, #1
    beq lbl_0804e556
    b lbl_0804e586
    .align 2, 0
lbl_0804e548: .4byte 0x08325e5c
lbl_0804e54c:
    cmp r0, #3
    beq lbl_0804e56e
    cmp r0, #4
    beq lbl_0804e57a
    b lbl_0804e586
lbl_0804e556:
    ldrh r0, [r4, #2]
    adds r0, #6
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0x10
    b lbl_0804e58a
lbl_0804e562:
    ldrh r0, [r4, #2]
    adds r0, #0xf
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0xf
    b lbl_0804e58a
lbl_0804e56e:
    ldrh r0, [r4, #2]
    subs r0, #6
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0x10
    b lbl_0804e58a
lbl_0804e57a:
    ldrh r0, [r4, #2]
    subs r0, #0xf
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0xf
    b lbl_0804e58a
lbl_0804e586:
    ldrh r0, [r4, #4]
    subs r0, #0x14
lbl_0804e58a:
    strh r0, [r4, #4]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0804e5ac
    movs r0, #0
    strh r0, [r4]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x1f
    bl ParticleSet
    ldr r0, lbl_0804e5b4 @ =0x000002c1
    bl SoundPlay
lbl_0804e5ac:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804e5b4: .4byte 0x000002c1

    thumb_func_start MechaRidleyMissile
MechaRidleyMissile: @ 0x0804e5b8
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0804e5e0 @ =0x03000738
    adds r4, r0, #0
    adds r4, #0x24
    ldrb r3, [r4]
    adds r5, r0, #0
    cmp r3, #0x42
    bne lbl_0804e5cc
    b lbl_0804e750
lbl_0804e5cc:
    cmp r3, #0x42
    bgt lbl_0804e5ec
    cmp r3, #9
    beq lbl_0804e66c
    cmp r3, #9
    bgt lbl_0804e5e4
    cmp r3, #0
    beq lbl_0804e5f4
    b lbl_0804e79c
    .align 2, 0
lbl_0804e5e0: .4byte 0x03000738
lbl_0804e5e4:
    cmp r3, #0x23
    bne lbl_0804e5ea
    b lbl_0804e6f4
lbl_0804e5ea:
    b lbl_0804e79c
lbl_0804e5ec:
    cmp r3, #0x44
    bne lbl_0804e5f2
    b lbl_0804e778
lbl_0804e5f2:
    b lbl_0804e79c
lbl_0804e5f4:
    ldrh r1, [r5]
    movs r0, #0x80
    movs r2, #0
    orrs r0, r1
    strh r0, [r5]
    adds r0, r5, #0
    adds r0, #0x27
    movs r1, #0x10
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0804e65c @ =0x0000ffe0
    strh r1, [r5, #0xa]
    movs r0, #0x20
    strh r0, [r5, #0xc]
    strh r1, [r5, #0xe]
    strh r0, [r5, #0x10]
    ldr r0, lbl_0804e660 @ =0x08325e24
    str r0, [r5, #0x18]
    strb r2, [r5, #0x1c]
    strh r3, [r5, #0x16]
    ldr r2, lbl_0804e664 @ =0x082b1be4
    ldrb r1, [r5, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r5, #0x14]
    adds r1, r5, #0
    adds r1, #0x2a
    movs r0, #0xa0
    strb r0, [r1]
    adds r0, #0x60
    strh r0, [r5, #0x12]
    adds r1, #2
    movs r0, #0x1e
    strb r0, [r1]
    movs r0, #9
    strb r0, [r4]
    subs r1, #7
    movs r0, #6
    strb r0, [r1]
    subs r1, #3
    movs r0, #2
    strb r0, [r1]
    ldr r1, lbl_0804e668 @ =0x0300080c
    ldrh r0, [r1, #0xa]
    adds r0, #1
    b lbl_0804e7b2
    .align 2, 0
lbl_0804e65c: .4byte 0x0000ffe0
lbl_0804e660: .4byte 0x08325e24
lbl_0804e664: .4byte 0x082b1be4
lbl_0804e668: .4byte 0x0300080c
lbl_0804e66c:
    ldrh r1, [r5]
    ldr r0, lbl_0804e688 @ =0x0000fffb
    ands r0, r1
    strh r0, [r5]
    adds r0, r5, #0
    adds r0, #0x2c
    ldrb r0, [r0]
    lsrs r6, r0, #1
    ldrb r0, [r5, #0x1e]
    cmp r0, #1
    bne lbl_0804e68c
    subs r0, r6, #2
    b lbl_0804e692
    .align 2, 0
lbl_0804e688: .4byte 0x0000fffb
lbl_0804e68c:
    cmp r0, #2
    bne lbl_0804e696
    adds r0, r6, #2
lbl_0804e692:
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
lbl_0804e696:
    ldrh r0, [r5, #2]
    subs r0, r0, r6
    movs r7, #0
    strh r0, [r5, #2]
    ldrh r0, [r5, #4]
    subs r0, r0, r6
    strh r0, [r5, #4]
    cmp r6, #2
    bhi lbl_0804e6c2
    adds r6, r5, #0
    adds r6, #0x2a
    ldrb r0, [r6]
    ldr r2, lbl_0804e6f0 @ =0x030013d4
    ldrh r1, [r2, #0x14]
    subs r1, #0x40
    ldrh r2, [r2, #0x12]
    ldrh r3, [r5, #2]
    ldrh r4, [r5, #4]
    str r4, [sp]
    bl SpriteUtilMakeSpriteFaceSamusRotation
    strb r0, [r6]
lbl_0804e6c2:
    adds r2, r5, #0
    adds r2, #0x2c
    ldrb r0, [r2]
    subs r0, #2
    strb r0, [r2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_0804e7b4
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x23
    strb r0, [r1]
    adds r0, r5, #0
    adds r0, #0x2d
    strb r7, [r0]
    adds r0, #1
    movs r1, #1
    strb r1, [r0]
    strb r7, [r2]
    adds r0, #1
    strb r1, [r0]
    b lbl_0804e7b4
    .align 2, 0
lbl_0804e6f0: .4byte 0x030013d4
lbl_0804e6f4:
    ldrb r0, [r5, #0x1e]
    movs r6, #0x40
    cmp r0, #1
    beq lbl_0804e704
    movs r6, #0x20
    cmp r0, #2
    bne lbl_0804e704
    movs r6, #0x5c
lbl_0804e704:
    ldr r4, lbl_0804e748 @ =0x030013d4
    ldrh r0, [r4, #0x14]
    subs r0, #0x20
    ldrh r1, [r4, #0x12]
    movs r2, #2
    str r2, [sp]
    movs r2, #0x28
    movs r3, #0x28
    bl SpriteUtilMoveSpriteTowardsSamus
    ldr r5, lbl_0804e74c @ =0x03000738
    adds r7, r5, #0
    adds r7, #0x2a
    ldrb r0, [r7]
    ldrh r1, [r4, #0x14]
    subs r1, r1, r6
    ldrh r2, [r4, #0x12]
    ldrh r3, [r5, #2]
    ldrh r4, [r5, #4]
    str r4, [sp]
    bl SpriteUtilMakeSpriteFaceSamusRotation
    strb r0, [r7]
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0804e7b4
    adds r1, r5, #0
    adds r1, #0x24
    movs r0, #0x44
    strb r0, [r1]
    b lbl_0804e7b4
    .align 2, 0
lbl_0804e748: .4byte 0x030013d4
lbl_0804e74c: .4byte 0x03000738
lbl_0804e750:
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    movs r2, #0x1e
    bl ParticleSet
    movs r0, #0
    strh r0, [r5]
    ldr r1, lbl_0804e770 @ =0x0300080c
    ldrh r0, [r1, #0xa]
    subs r0, #1
    strh r0, [r1, #0xa]
    ldr r0, lbl_0804e774 @ =0x000002c2
    bl SoundPlay
    b lbl_0804e7b4
    .align 2, 0
lbl_0804e770: .4byte 0x0300080c
lbl_0804e774: .4byte 0x000002c2
lbl_0804e778:
    ldrh r0, [r5, #2]
    ldrh r1, [r5, #4]
    movs r2, #0x1f
    bl ParticleSet
    movs r0, #0
    strh r0, [r5]
    ldr r1, lbl_0804e798 @ =0x0300080c
    ldrh r0, [r1, #0xa]
    subs r0, #1
    strh r0, [r1, #0xa]
    movs r0, #0x96
    lsls r0, r0, #1
    bl SoundPlay
    b lbl_0804e7b4
    .align 2, 0
lbl_0804e798: .4byte 0x0300080c
lbl_0804e79c:
    ldrh r1, [r5, #2]
    ldrh r2, [r5, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    ldr r1, lbl_0804e7bc @ =0x0300080c
    ldrh r0, [r1, #0xa]
    subs r0, #1
lbl_0804e7b2:
    strh r0, [r1, #0xa]
lbl_0804e7b4:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804e7bc: .4byte 0x0300080c

    thumb_func_start MechaRidleyFireball
MechaRidleyFireball: @ 0x0804e7c0
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0804e7e4 @ =0x03000738
    adds r5, r0, #0
    adds r5, #0x24
    ldrb r2, [r5]
    adds r4, r0, #0
    cmp r2, #0x42
    beq lbl_0804e8be
    cmp r2, #0x42
    bgt lbl_0804e7f0
    cmp r2, #9
    beq lbl_0804e890
    cmp r2, #9
    bgt lbl_0804e7e8
    cmp r2, #0
    beq lbl_0804e7f6
    b lbl_0804e8ec
    .align 2, 0
lbl_0804e7e4: .4byte 0x03000738
lbl_0804e7e8:
    cmp r2, #0x23
    bne lbl_0804e7ee
    b lbl_0804e904
lbl_0804e7ee:
    b lbl_0804e8ec
lbl_0804e7f0:
    cmp r2, #0x44
    beq lbl_0804e8c6
    b lbl_0804e8ec
lbl_0804e7f6:
    ldrh r1, [r4]
    movs r3, #0x80
    lsls r3, r3, #8
    adds r0, r3, #0
    orrs r0, r1
    movs r1, #0x80
    orrs r0, r1
    movs r3, #0
    ldr r1, lbl_0804e86c @ =0x0000fffb
    ands r0, r1
    strh r0, [r4]
    adds r0, r4, #0
    adds r0, #0x27
    movs r1, #0x14
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    adds r0, #1
    strb r1, [r0]
    ldr r1, lbl_0804e870 @ =0x0000ffe4
    strh r1, [r4, #0xa]
    movs r0, #0x1c
    strh r0, [r4, #0xc]
    strh r1, [r4, #0xe]
    strh r0, [r4, #0x10]
    ldr r0, lbl_0804e874 @ =0x08325e34
    str r0, [r4, #0x18]
    strb r3, [r4, #0x1c]
    strh r2, [r4, #0x16]
    ldr r2, lbl_0804e878 @ =0x082b1be4
    ldrb r1, [r4, #0x1d]
    lsls r0, r1, #3
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r2
    ldrh r0, [r0]
    strh r0, [r4, #0x14]
    adds r1, r4, #0
    adds r1, #0x2c
    movs r0, #0x1e
    strb r0, [r1]
    movs r0, #9
    strb r0, [r5]
    subs r1, #7
    movs r0, #6
    strb r0, [r1]
    subs r1, #3
    movs r0, #2
    strb r0, [r1]
    adds r0, #0xfe
    strh r0, [r4, #0x12]
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    beq lbl_0804e87c
    adds r1, #8
    movs r0, #0x28
    strb r0, [r1]
    b lbl_0804e882
    .align 2, 0
lbl_0804e86c: .4byte 0x0000fffb
lbl_0804e870: .4byte 0x0000ffe4
lbl_0804e874: .4byte 0x08325e34
lbl_0804e878: .4byte 0x082b1be4
lbl_0804e87c:
    adds r0, r4, #0
    adds r0, #0x2a
    strb r3, [r0]
lbl_0804e882:
    ldr r1, lbl_0804e88c @ =0x0300080c
    ldrh r0, [r1, #0xe]
    adds r0, #1
    b lbl_0804e902
    .align 2, 0
lbl_0804e88c: .4byte 0x0300080c
lbl_0804e890:
    ldrb r0, [r4, #0x1e]
    cmp r0, #0
    beq lbl_0804e89c
    ldrh r0, [r4, #2]
    subs r0, #2
    b lbl_0804e8a0
lbl_0804e89c:
    ldrh r0, [r4, #2]
    adds r0, #0xc
lbl_0804e8a0:
    strh r0, [r4, #2]
    ldrh r0, [r4, #4]
    subs r0, #0xc
    strh r0, [r4, #4]
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    bl SpriteUtilGetCollisionAtPosition
    cmp r0, #0
    beq lbl_0804e904
    adds r1, r4, #0
    adds r1, #0x24
    movs r0, #0x44
    strb r0, [r1]
    b lbl_0804e904
lbl_0804e8be:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x1e
    b lbl_0804e8cc
lbl_0804e8c6:
    ldrh r0, [r4, #2]
    ldrh r1, [r4, #4]
    movs r2, #0x1f
lbl_0804e8cc:
    bl ParticleSet
    movs r0, #0
    strh r0, [r4]
    ldr r1, lbl_0804e8e8 @ =0x0300080c
    ldrh r0, [r1, #0xe]
    subs r0, #1
    strh r0, [r1, #0xe]
    movs r0, #0xad
    lsls r0, r0, #2
    bl SoundPlay
    b lbl_0804e904
    .align 2, 0
lbl_0804e8e8: .4byte 0x0300080c
lbl_0804e8ec:
    ldrh r1, [r4, #2]
    ldrh r2, [r4, #4]
    movs r0, #0x1f
    str r0, [sp]
    movs r0, #0
    movs r3, #1
    bl SpriteUtilSpriteDeath
    ldr r1, lbl_0804e90c @ =0x0300080c
    ldrh r0, [r1, #0xe]
    subs r0, #1
lbl_0804e902:
    strh r0, [r1, #0xe]
lbl_0804e904:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0804e90c: .4byte 0x0300080c
