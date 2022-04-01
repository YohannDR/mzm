    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start sub_08000c48
sub_08000c48: @ 0x08000c48
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r2, r1, #0
    movs r4, #0
    ldr r0, lbl_08000c68 @ =0x03000c1c
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08000cb8
    cmp r1, #0xe
    beq lbl_08000c6c
    cmp r1, #0xf
    beq lbl_08000c80
    b lbl_08000faa
    .align 2, 0
lbl_08000c68: .4byte 0x03000c1c
lbl_08000c6c:
    ldr r1, lbl_08000c78 @ =0x0000ffff
    ldr r2, lbl_08000c7c @ =0x02038000
    movs r3, #0x80
    lsls r3, r3, #8
    b lbl_08000c9e
    .align 2, 0
lbl_08000c78: .4byte 0x0000ffff
lbl_08000c7c: .4byte 0x02038000
lbl_08000c80:
    ldr r1, lbl_08000cac @ =0x0000ffff
    ldr r3, lbl_08000cb0 @ =0x08754bc8
    ldr r0, lbl_08000cb4 @ =0x03000c1e
    movs r2, #0
    ldrsb r2, [r0, r2]
    lsls r0, r2, #3
    adds r0, r0, r2
    lsls r0, r0, #4
    adds r0, r0, r2
    lsls r0, r0, #5
    adds r0, #0x80
    ldr r2, [r3]
    adds r2, r2, r0
    movs r3, #0x91
    lsls r3, r3, #5
lbl_08000c9e:
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl bit_fill
    b lbl_08000faa
    .align 2, 0
lbl_08000cac: .4byte 0x0000ffff
lbl_08000cb0: .4byte 0x08754bc8
lbl_08000cb4: .4byte 0x03000c1e
lbl_08000cb8:
    cmp r2, #0x10
    bls lbl_08000cbe
    b lbl_08000faa
lbl_08000cbe:
    lsls r0, r2, #2
    ldr r1, lbl_08000cc8 @ =lbl_08000ccc
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08000cc8: .4byte lbl_08000ccc
lbl_08000ccc: @ jump table
    .4byte lbl_08000d10 @ case 0
    .4byte lbl_08000d60 @ case 1
    .4byte lbl_08000d7c @ case 2
    .4byte lbl_08000da0 @ case 3
    .4byte lbl_08000dd8 @ case 4
    .4byte lbl_08000e14 @ case 5
    .4byte lbl_08000e34 @ case 6
    .4byte lbl_08000e58 @ case 7
    .4byte lbl_08000e78 @ case 8
    .4byte lbl_08000e9c @ case 9
    .4byte lbl_08000ec0 @ case 10
    .4byte lbl_08000ee4 @ case 11
    .4byte lbl_08000f20 @ case 12
    .4byte lbl_08000f34 @ case 13
    .4byte lbl_08000f4c @ case 14
    .4byte lbl_08000f60 @ case 15
    .4byte lbl_08000f98 @ case 16
lbl_08000d10:
    ldr r2, lbl_08000d4c @ =0x040000d4
    ldr r6, lbl_08000d50 @ =0x08754bc8
    ldr r0, [r6]
    str r0, [r2]
    ldr r3, lbl_08000d54 @ =0x00006d40
    adds r1, r0, r3
    str r1, [r2, #4]
    ldr r1, lbl_08000d58 @ =0x80000020
    str r1, [r2, #8]
    ldr r1, [r2, #8]
    ldr r5, lbl_08000d5c @ =0x08754bcc
    ldr r1, [r5]
    movs r2, #0x40
    bl sub_08005330
    adds r4, r0, #0
    cmp r4, #0
    beq lbl_08000d36
    b lbl_08000faa
lbl_08000d36:
    ldr r0, [r6]
    ldr r1, lbl_08000d54 @ =0x00006d40
    adds r0, r0, r1
    ldr r1, [r5]
    ldr r2, lbl_08000d54 @ =0x00006d40
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000d4c: .4byte 0x040000d4
lbl_08000d50: .4byte 0x08754bc8
lbl_08000d54: .4byte 0x00006d40
lbl_08000d58: .4byte 0x80000020
lbl_08000d5c: .4byte 0x08754bcc
lbl_08000d60:
    ldr r0, lbl_08000d74 @ =0x08754bc8
    ldr r0, [r0]
    adds r0, #0x40
    ldr r1, lbl_08000d78 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, #0x40
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000d74: .4byte 0x08754bc8
lbl_08000d78: .4byte 0x08754bcc
lbl_08000d7c:
    ldr r0, lbl_08000d94 @ =0x08754bc8
    ldr r0, [r0]
    ldr r2, lbl_08000d98 @ =0x00006d40
    adds r0, r0, r2
    ldr r1, lbl_08000d9c @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000d94: .4byte 0x08754bc8
lbl_08000d98: .4byte 0x00006d40
lbl_08000d9c: .4byte 0x08754bcc
lbl_08000da0:
    ldr r1, lbl_08000dcc @ =0x08754bc8
    ldr r0, lbl_08000dd0 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    adds r2, #0x80
    ldr r0, [r1]
    adds r0, r0, r2
    ldr r1, lbl_08000dd4 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x91
    lsls r2, r2, #5
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000dcc: .4byte 0x08754bc8
lbl_08000dd0: .4byte 0x03000c1e
lbl_08000dd4: .4byte 0x08754bcc
lbl_08000dd8:
    ldr r1, lbl_08000e04 @ =0x08754bc8
    ldr r0, lbl_08000e08 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    ldr r3, lbl_08000e0c @ =0x000036e0
    adds r2, r2, r3
    ldr r0, [r1]
    adds r0, r0, r2
    ldr r1, lbl_08000e10 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x91
    lsls r2, r2, #5
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000e04: .4byte 0x08754bc8
lbl_08000e08: .4byte 0x03000c1e
lbl_08000e0c: .4byte 0x000036e0
lbl_08000e10: .4byte 0x08754bcc
lbl_08000e14:
    ldr r0, lbl_08000e2c @ =0x08754bc8
    ldr r0, [r0]
    movs r2, #0xdb
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r1, lbl_08000e30 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000e2c: .4byte 0x08754bc8
lbl_08000e30: .4byte 0x08754bcc
lbl_08000e34:
    ldr r0, lbl_08000e4c @ =0x08754bc8
    ldr r0, [r0]
    ldr r2, lbl_08000e50 @ =0x00006dc0
    adds r0, r0, r2
    ldr r1, lbl_08000e54 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000e4c: .4byte 0x08754bc8
lbl_08000e50: .4byte 0x00006dc0
lbl_08000e54: .4byte 0x08754bcc
lbl_08000e58:
    ldr r0, lbl_08000e70 @ =0x08754bc8
    ldr r0, [r0]
    movs r2, #0xdc
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r1, lbl_08000e74 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000e70: .4byte 0x08754bc8
lbl_08000e74: .4byte 0x08754bcc
lbl_08000e78:
    ldr r0, lbl_08000e90 @ =0x08754bc8
    ldr r0, [r0]
    ldr r2, lbl_08000e94 @ =0x00006e40
    adds r0, r0, r2
    ldr r1, lbl_08000e98 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x40
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000e90: .4byte 0x08754bc8
lbl_08000e94: .4byte 0x00006e40
lbl_08000e98: .4byte 0x08754bcc
lbl_08000e9c:
    ldr r0, lbl_08000eb8 @ =0x08754bc8
    ldr r0, [r0]
    movs r2, #0xdd
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r1, lbl_08000ebc @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x80
    lsls r2, r2, #1
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000eb8: .4byte 0x08754bc8
lbl_08000ebc: .4byte 0x08754bcc
lbl_08000ec0:
    ldr r0, lbl_08000edc @ =0x08754bc8
    ldr r0, [r0]
    movs r2, #0xdf
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r1, lbl_08000ee0 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x80
    lsls r2, r2, #1
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000edc: .4byte 0x08754bc8
lbl_08000ee0: .4byte 0x08754bcc
lbl_08000ee4:
    ldr r6, lbl_08000f18 @ =0x08754bc8
    ldr r0, [r6]
    movs r2, #0xe1
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r5, lbl_08000f1c @ =0x08754bcc
    ldr r1, [r5]
    adds r1, r1, r2
    movs r7, #0x80
    lsls r7, r7, #2
    adds r2, r7, #0
    bl sub_08005330
    adds r4, r0, #0
    cmp r4, #0
    bne lbl_08000faa
    ldr r0, [r6]
    movs r2, #0xe5
    lsls r2, r2, #7
    adds r0, r0, r2
    ldr r1, [r5]
    adds r1, r1, r2
    adds r2, r7, #0
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000f18: .4byte 0x08754bc8
lbl_08000f1c: .4byte 0x08754bcc
lbl_08000f20:
    ldr r0, lbl_08000f2c @ =0x0203ff70
    ldr r1, lbl_08000f30 @ =0x0e007f70
    movs r2, #0x10
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000f2c: .4byte 0x0203ff70
lbl_08000f30: .4byte 0x0e007f70
lbl_08000f34:
    ldr r0, lbl_08000f44 @ =0x0203f800
    ldr r1, lbl_08000f48 @ =0x0e007800
    movs r2, #0xa0
    lsls r2, r2, #2
    bl sub_08005330
    b lbl_08000fa8
    .align 2, 0
lbl_08000f44: .4byte 0x0203f800
lbl_08000f48: .4byte 0x0e007800
lbl_08000f4c:
    movs r0, #0xe0
    lsls r0, r0, #0x14
    ldr r1, lbl_08000f5c @ =0x02038000
    movs r2, #0x80
    lsls r2, r2, #8
    bl sub_080051f8
    b lbl_08000faa
    .align 2, 0
lbl_08000f5c: .4byte 0x02038000
lbl_08000f60:
    ldr r1, lbl_08000f8c @ =0x08754bcc
    ldr r0, lbl_08000f90 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    adds r2, #0x80
    ldr r0, [r1]
    adds r0, r0, r2
    ldr r1, lbl_08000f94 @ =0x08754bc8
    ldr r1, [r1]
    adds r1, r1, r2
    movs r2, #0x91
    lsls r2, r2, #5
    bl sub_080051f8
    b lbl_08000faa
    .align 2, 0
lbl_08000f8c: .4byte 0x08754bcc
lbl_08000f90: .4byte 0x03000c1e
lbl_08000f94: .4byte 0x08754bc8
lbl_08000f98:
    ldr r0, lbl_08000fb4 @ =0x08754bcc
    ldr r0, [r0]
    ldr r1, lbl_08000fb8 @ =0x08754bc8
    ldr r1, [r1]
    movs r2, #0x80
    lsls r2, r2, #8
    bl sub_080052cc
lbl_08000fa8:
    adds r4, r0, #0
lbl_08000faa:
    adds r0, r4, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08000fb4: .4byte 0x08754bcc
lbl_08000fb8: .4byte 0x08754bc8

    thumb_func_start sub_08000fbc
sub_08000fbc: @ 0x08000fbc
    push {r4, r5, lr}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r2, r1, #0
    movs r5, #0x80
    lsls r5, r5, #2
    ldr r0, lbl_08000ff0 @ =0x03000c20
    ldrb r0, [r0]
    lsls r4, r0, #9
    movs r0, #0x91
    lsls r0, r0, #5
    cmp r4, r0
    ble lbl_08000fda
    ldr r0, lbl_08000ff4 @ =0xffffede0
    adds r5, r4, r0
lbl_08000fda:
    ldr r0, lbl_08000ff8 @ =0x03000c1c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0800108e
    cmp r1, #1
    beq lbl_08001024
    cmp r1, #1
    bgt lbl_08000ffc
    cmp r1, #0
    beq lbl_08001002
    b lbl_0800108e
    .align 2, 0
lbl_08000ff0: .4byte 0x03000c20
lbl_08000ff4: .4byte 0xffffede0
lbl_08000ff8: .4byte 0x03000c1c
lbl_08000ffc:
    cmp r2, #2
    beq lbl_08001064
    b lbl_0800108e
lbl_08001002:
    ldr r1, lbl_0800101c @ =0x08754bc8
    ldr r0, lbl_08001020 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    adds r2, #0x80
    b lbl_0800103c
    .align 2, 0
lbl_0800101c: .4byte 0x08754bc8
lbl_08001020: .4byte 0x03000c1e
lbl_08001024:
    ldr r1, lbl_08001054 @ =0x08754bc8
    ldr r0, lbl_08001058 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    ldr r0, lbl_0800105c @ =0x000036e0
    adds r2, r2, r0
lbl_0800103c:
    ldr r0, [r1]
    adds r0, r0, r2
    adds r0, r0, r4
    ldr r1, lbl_08001060 @ =0x08754bcc
    ldr r1, [r1]
    adds r1, r1, r2
    adds r1, r1, r4
    adds r2, r5, #0
    bl sub_08005330
    b lbl_0800108e
    .align 2, 0
lbl_08001054: .4byte 0x08754bc8
lbl_08001058: .4byte 0x03000c1e
lbl_0800105c: .4byte 0x000036e0
lbl_08001060: .4byte 0x08754bcc
lbl_08001064:
    ldr r1, lbl_080010b0 @ =0x08754bcc
    ldr r0, lbl_080010b4 @ =0x03000c1e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    lsls r2, r0, #3
    adds r2, r2, r0
    lsls r2, r2, #4
    adds r2, r2, r0
    lsls r2, r2, #5
    adds r2, #0x80
    ldr r0, [r1]
    adds r0, r0, r2
    adds r0, r0, r4
    ldr r1, lbl_080010b8 @ =0x08754bc8
    ldr r1, [r1]
    adds r1, r1, r2
    adds r1, r1, r4
    adds r2, r5, #0
    bl sub_080051f8
lbl_0800108e:
    movs r2, #0
    adds r1, r4, r5
    ldr r0, lbl_080010bc @ =0x0000121f
    cmp r1, r0
    bgt lbl_0800109a
    movs r2, #1
lbl_0800109a:
    ldr r1, lbl_080010c0 @ =0x03000c20
    ldrb r0, [r1]
    adds r0, r0, r2
    muls r0, r2, r0
    strb r0, [r1]
    movs r0, #1
    eors r2, r0
    adds r0, r2, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080010b0: .4byte 0x08754bcc
lbl_080010b4: .4byte 0x03000c1e
lbl_080010b8: .4byte 0x08754bc8
lbl_080010bc: .4byte 0x0000121f
lbl_080010c0: .4byte 0x03000c20

    thumb_func_start sub_080010c4
sub_080010c4: @ 0x080010c4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08001134 @ =0x03001d00
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
lbl_08001134: .4byte 0x03001d00
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
    ldr r6, lbl_08001204 @ =0x03002924
    mov r0, sl
    adds r1, r0, r6
    ldr r0, lbl_08001208 @ =0xfffff400
    adds r5, r6, r0
    ldr r0, lbl_0800120c @ =0x030041e8
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
lbl_08001204: .4byte 0x03002924
lbl_08001208: .4byte 0xfffff400
lbl_0800120c: .4byte 0x030041e8
lbl_08001210: .4byte 0xfffff3dc
lbl_08001214:
    movs r0, #0x34
    muls r0, r2, r0
    ldr r1, lbl_08001254 @ =0x03003524
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
lbl_08001254: .4byte 0x03003524
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
    bl sub_080020a4
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
    bl sub_080020a4
lbl_0800139a:
    strb r5, [r4, #0x10]
    lsls r1, r5, #0x10
    asrs r1, r1, #0x10
    ldr r2, lbl_08001440 @ =0x03001d00
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
    ldr r0, lbl_08001444 @ =0x03003b8c
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
    ldr r0, lbl_08001440 @ =0x03001d00
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
    ldr r4, lbl_0800144c @ =0x03002924
    mov r0, sl
    adds r1, r0, r4
    ldr r0, lbl_08001450 @ =0xfffff400
    adds r5, r4, r0
    ldr r6, lbl_08001454 @ =0x03004290
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
lbl_08001440: .4byte 0x03001d00
lbl_08001444: .4byte 0x03003b8c
lbl_08001448: .4byte 0x04000006
lbl_0800144c: .4byte 0x03002924
lbl_08001450: .4byte 0xfffff400
lbl_08001454: .4byte 0x03004290

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
    ldr r1, lbl_08001484 @ =0x03003794
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
lbl_08001484: .4byte 0x03003794
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
    ldr r0, lbl_0800179c @ =0x0808cc3d
    movs r1, #0x19
    ldrsb r1, [r4, r1]
    adds r1, r1, r0
    ldrb r0, [r1]
    strb r0, [r4, #0x12]
    b lbl_080017ae
    .align 2, 0
lbl_0800179c: .4byte 0x0808cc3d
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
    bl sub_080024c0
    b lbl_08001834
lbl_080017c0:
    lsls r0, r2, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_08001834
    adds r0, r4, #0
    mov r1, r8
    bl sub_080024c0
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
    ldr r0, lbl_0800181c @ =0x0808cc3d
    adds r0, r1, r0
    ldrb r0, [r0]
    b lbl_08001826
    .align 2, 0
lbl_0800181c: .4byte 0x0808cc3d
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
    ldr r1, lbl_08001a74 @ =0x0808cbd0
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
lbl_08001a74: .4byte 0x0808cbd0
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
    ldr r0, lbl_08001ae4 @ =0x0808cef8
    adds r1, r2, #0
    subs r1, #0xb1
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r4, #0
    bl _call_via_r1
    b lbl_08001b00
    .align 2, 0
lbl_08001ae4: .4byte 0x0808cef8
lbl_08001ae8:
    ldr r1, lbl_08001afc @ =0x0808cbd0
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
lbl_08001afc: .4byte 0x0808cbd0
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
    bl sub_080039f4
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
    bl play_sound1
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
    bl sub_08003d4c
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
    bl midikey2freq
    str r0, [r4, #0x1c]
    ldr r1, lbl_08001cb4 @ =0x03001d00
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_08001cb8
    movs r0, #0x80
    lsls r0, r0, #7
    b lbl_08001cbe
    .align 2, 0
lbl_08001cb4: .4byte 0x03001d00
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
    ldr r2, lbl_08001d04 @ =0x0808cc4d
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
lbl_08001d04: .4byte 0x0808cc4d
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
    bl midikey2freq
    str r0, [r4, #0x1c]
    ldr r1, lbl_08001dbc @ =0x03001d00
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_08001dc0
    movs r0, #0x80
    lsls r0, r0, #7
    b lbl_08001dc6
    .align 2, 0
lbl_08001dbc: .4byte 0x03001d00
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
    ldr r2, lbl_08001e58 @ =0x03001d00
    ldr r3, lbl_08001e5c @ =0x00001824
    adds r0, r2, r3
    adds r6, r1, r0
    b lbl_08001f14
    .align 2, 0
lbl_08001e58: .4byte 0x03001d00
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
    ldr r1, lbl_08001eb8 @ =0x03001d00
    ldrb r1, [r1, #5]
    cmp r6, r1
    bhs lbl_08001f10
    ldr r4, lbl_08001eb8 @ =0x03001d00
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
lbl_08001eb8: .4byte 0x03001d00
lbl_08001ebc: .4byte 0x0000184c
lbl_08001ec0: .4byte 0x00001824
lbl_08001ec4:
    mov r3, r8
    cmp r3, #0
    bne lbl_08001f04
lbl_08001eca:
    mov r3, ip
    muls r3, r2, r3
    ldr r1, lbl_08001f30 @ =0x03001d00
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
    ldr r1, lbl_08001f38 @ =0x03003524
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
lbl_08001f30: .4byte 0x03001d00
lbl_08001f34: .4byte 0x00001826
lbl_08001f38: .4byte 0x03003524

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
    ldr r0, lbl_08001fdc @ =0x0300376c
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
lbl_08001fdc: .4byte 0x0300376c

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
    ldr r0, lbl_0800202c @ =0x0300376c
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
lbl_0800202c: .4byte 0x0300376c

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

    thumb_func_start sub_080020a4
sub_080020a4: @ 0x080020a4
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
    ldr r1, lbl_0800211c @ =0x0808cad0
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
lbl_0800211c: .4byte 0x0808cad0
lbl_08002120:
    ldr r0, lbl_0800213c @ =0x0808cc01
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
lbl_0800213c: .4byte 0x0808cc01

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
    bl sub_080024c0
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
    bl sub_08002a38
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
    bl sub_080024c0
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
    bl sub_08002a38
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

    thumb_func_start sub_0800222c
sub_0800222c: @ 0x0800222c
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

    thumb_func_start sub_08002264
sub_08002264: @ 0x08002264
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
    bl sub_08005070
    b lbl_0800229e
lbl_08002280:
    subs r0, #1
    strb r0, [r2, #0xa]
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_08002292
    adds r0, r2, #0
    bl sub_0800222c
    b lbl_0800229e
lbl_08002292:
    ldr r0, [r2, #0x24]
    adds r0, #1
    str r0, [r2, #0x24]
    adds r0, r2, #0
    bl sub_08005070
lbl_0800229e:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080022a4
sub_080022a4: @ 0x080022a4
    ldr r2, [r0, #0x24]
    adds r1, r2, #1
    str r1, [r0, #0x24]
    ldrb r2, [r2, #1]
    strb r2, [r0, #0xb]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start sub_080022b4
sub_080022b4: @ 0x080022b4
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

    thumb_func_start sub_0800238c
sub_0800238c: @ 0x0800238c
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

    thumb_func_start sub_080023a0
sub_080023a0: @ 0x080023a0
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

    thumb_func_start sub_080023b4
sub_080023b4: @ 0x080023b4
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

    thumb_func_start sub_080023cc
sub_080023cc: @ 0x080023cc
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

    thumb_func_start sub_080023e0
sub_080023e0: @ 0x080023e0
    ldr r2, [r0, #0x24]
    ldrb r1, [r2]
    adds r1, #1
    asrs r1, r1, #1
    strb r1, [r0, #0x10]
    adds r2, #1
    str r2, [r0, #0x24]
    bx lr

    thumb_func_start sub_080023f0
sub_080023f0: @ 0x080023f0
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x14]
    strb r2, [r0, #0x15]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start sub_08002400
sub_08002400: @ 0x08002400
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x11]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start sub_0800240c
sub_0800240c: @ 0x0800240c
    ldr r1, [r0, #0x24]
    ldrb r2, [r1]
    strb r2, [r0, #0x12]
    adds r1, #1
    str r1, [r0, #0x24]
    bx lr

    thumb_func_start sub_08002418
sub_08002418: @ 0x08002418
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

    thumb_func_start sub_08002430
sub_08002430: @ 0x08002430
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

    thumb_func_start sub_08002460
sub_08002460: @ 0x08002460
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

    thumb_func_start sub_080024bc
sub_080024bc: @ 0x080024bc
    bx lr
    .align 2, 0

    thumb_func_start sub_080024c0
sub_080024c0: @ 0x080024c0
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

    thumb_func_start init_sound
init_sound: @ 0x08002564
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    ldr r5, lbl_0800276c @ =0x03001d00
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
    ldr r0, lbl_0800278c @ =0x03003b8c
    ldr r1, lbl_08002790 @ =0x03003b91
    str r1, [r0]
    adds r2, #0x4b
    ldr r0, lbl_08002794 @ =call_soundcode_a
    str r0, [r2]
    subs r1, #1
    str r1, [r2, #4]
    ldr r0, lbl_08002798 @ =0x8000032c
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_0800279c @ =0x030041e8
    ldr r0, lbl_080027a0 @ =0x030041ed
    str r0, [r1]
    ldr r1, lbl_080027a4 @ =call_soundcode_b
    str r1, [r2]
    subs r0, #1
    str r0, [r2, #4]
    ldr r0, lbl_080027a8 @ =0x80000052
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_080027ac @ =0x03004290
    ldr r0, lbl_080027b0 @ =0x03004295
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
    ldr r5, lbl_080027cc @ =0x03003794
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
    ldr r7, lbl_080027d8 @ =0x0808f254
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
    ldr r4, lbl_080027d8 @ =0x0808f254
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
    bl sub_080027f8
    movs r3, #0
    ldr r2, lbl_0800276c @ =0x03001d00
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
    ldr r1, lbl_0800276c @ =0x03001d00
    mov r8, r1
    ldr r2, lbl_080027c4 @ =0x00000009
    mov ip, r2
    mov r2, sp
    movs r6, #0
    ldr r1, lbl_080027d4 @ =0x040000d4
    ldr r5, lbl_080027e8 @ =0x03003834
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
    ldr r6, lbl_080027f0 @ =0x03003b44
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
lbl_0800276c: .4byte 0x03001d00
lbl_08002770: .4byte 0x04000200
lbl_08002774: .4byte 0x04000084
lbl_08002778: .4byte 0x04000082
lbl_0800277c: .4byte 0x0000a90e
lbl_08002780: .4byte 0x04000089
lbl_08002784: .4byte 0x04000063
lbl_08002788: .4byte 0x04000080
lbl_0800278c: .4byte 0x03003b8c
lbl_08002790: .4byte 0x03003b91
lbl_08002794: .4byte call_soundcode_a
lbl_08002798: .4byte 0x8000032c
lbl_0800279c: .4byte 0x030041e8
lbl_080027a0: .4byte 0x030041ed
lbl_080027a4: .4byte call_soundcode_b
lbl_080027a8: .4byte 0x80000052
lbl_080027ac: .4byte 0x03004290
lbl_080027b0: .4byte 0x03004295
lbl_080027b4: .4byte call_soundcode_c
lbl_080027b8: .4byte 0x80000058
lbl_080027bc: .4byte 0x8100000e
lbl_080027c0: .4byte 0x00000064
lbl_080027c4: .4byte 0x00000009
lbl_080027c8: .4byte 0x0194f700
lbl_080027cc: .4byte 0x03003794
lbl_080027d0: .4byte 0x81000014
lbl_080027d4: .4byte 0x040000d4
lbl_080027d8: .4byte 0x0808f254
lbl_080027dc: .4byte 0x81000016
lbl_080027e0: .4byte 0x00001824
lbl_080027e4: .4byte 0x8100001a
lbl_080027e8: .4byte 0x03003834
lbl_080027ec: .4byte 0x8100001c
lbl_080027f0: .4byte 0x03003b44
lbl_080027f4: .4byte 0x81000004

    thumb_func_start sub_080027f8
sub_080027f8: @ 0x080027f8
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    ldr r0, lbl_080028a8 @ =0x03001d00
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
    ldr r1, lbl_080028a8 @ =0x03001d00
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
lbl_080028a8: .4byte 0x03001d00
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
    ldr r1, lbl_080028f0 @ =0x03001d00
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
lbl_080028f0: .4byte 0x03001d00

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
    ldr r6, lbl_080029e8 @ =0x03002924
    ldr r2, lbl_080029ec @ =0x01000300
    mov r0, sp
    adds r1, r6, #0
    bl cpu_fast_set
    ldr r1, lbl_080029f0 @ =0xfffff3dc
    adds r4, r6, r1
    ldr r1, lbl_080029f4 @ =0x0808cc60
    ldrb r0, [r4, #7]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    strh r0, [r4, #0x12]
    ldr r1, lbl_080029f8 @ =0x0808cc94
    ldrb r0, [r4, #7]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r0, [r0]
    str r0, [r4, #0x18]
    ldr r1, lbl_080029fc @ =0x0808ccc8
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
lbl_080029e8: .4byte 0x03002924
lbl_080029ec: .4byte 0x01000300
lbl_080029f0: .4byte 0xfffff3dc
lbl_080029f4: .4byte 0x0808cc60
lbl_080029f8: .4byte 0x0808cc94
lbl_080029fc: .4byte 0x0808ccc8
lbl_08002a00: .4byte 0x040000bc
lbl_08002a04: .4byte 0x040000c0
lbl_08002a08: .4byte 0x04000102
lbl_08002a0c: .4byte 0x04000100
lbl_08002a10: .4byte 0x00044940
lbl_08002a14: .4byte 0x04000006

    thumb_func_start play_sound1
play_sound1: @ 0x08002a18
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #0
    bl sub_08003fac
    pop {r0}
    bx r0

    thumb_func_start play_sound2
play_sound2: @ 0x08002a28
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #0
    bl sub_08004014
    pop {r0}
    bx r0

    thumb_func_start sub_08002a38
sub_08002a38: @ 0x08002a38
    push {lr}
    adds r2, r0, #0
    ldrb r1, [r2, #0x1e]
    movs r3, #1
    adds r0, r3, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_08002a54
    ldrb r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08002a54
    strb r3, [r2]
lbl_08002a54:
    pop {r0}
    bx r0

    thumb_func_start sub_08002a58
sub_08002a58: @ 0x08002a58
    push {r4, r5, lr}
    ldr r0, lbl_08002a84 @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r4, r0, #1
    cmp r4, #0
    blt lbl_08002a7e
    ldr r1, lbl_08002a88 @ =0x0808f254
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    adds r5, r0, r1
lbl_08002a70:
    ldr r0, [r5]
    bl sub_08004c1c
    subs r5, #0xc
    subs r4, #1
    cmp r4, #0
    bge lbl_08002a70
lbl_08002a7e:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002a84: .4byte 0x00000009
lbl_08002a88: .4byte 0x0808f254

    thumb_func_start sub_08002a8c
sub_08002a8c: @ 0x08002a8c
    push {r4, r5, lr}
    ldr r0, lbl_08002ac4 @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r4, r0, #1
    cmp r4, #0
    blt lbl_08002abe
    ldr r1, lbl_08002ac8 @ =0x0808f254
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    adds r5, r0, r1
lbl_08002aa4:
    ldr r2, [r5]
    ldrb r1, [r2, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_08002ab6
    adds r0, r2, #0
    bl sub_08004c1c
lbl_08002ab6:
    subs r5, #0xc
    subs r4, #1
    cmp r4, #0
    bge lbl_08002aa4
lbl_08002abe:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002ac4: .4byte 0x00000009
lbl_08002ac8: .4byte 0x0808f254

    thumb_func_start sub_08002acc
sub_08002acc: @ 0x08002acc
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldr r5, lbl_08002b1c @ =0x0808f254
    ldr r0, [r5, #0xc]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x18]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x24]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x30]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x3c]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x48]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x54]
    adds r1, r4, #0
    bl sub_08002c94
    ldr r0, [r5, #0x60]
    adds r1, r4, #0
    bl sub_08002c94
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002b1c: .4byte 0x0808f254

    thumb_func_start sub_08002b20
sub_08002b20: @ 0x08002b20
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r4, r0, #0
    ldr r3, lbl_08002b5c @ =0x0808f254
    ldr r0, lbl_08002b60 @ =0x0808f2c0
    lsls r2, r4, #3
    adds r2, r2, r0
    ldrh r1, [r2, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r3, [r0]
    ldr r2, [r2]
    ldrb r1, [r3]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_08002b4e
    ldr r0, [r3, #0x10]
    cmp r2, r0
    beq lbl_08002b56
lbl_08002b4e:
    adds r0, r4, #0
    movs r1, #0
    bl sub_08003fac
lbl_08002b56:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002b5c: .4byte 0x0808f254
lbl_08002b60: .4byte 0x0808f2c0

    thumb_func_start sub_08002b64
sub_08002b64: @ 0x08002b64
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r5, r4, #0
    ldr r2, lbl_08002ba4 @ =0x0808f254
    ldr r1, lbl_08002ba8 @ =0x0808f2c0
    lsls r0, r4, #3
    adds r3, r0, r1
    ldrh r1, [r3, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r2
    ldr r2, [r0]
    ldrb r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08002bac
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08002bbe
    ldr r1, [r3]
    ldr r0, [r2, #0x10]
    cmp r1, r0
    bne lbl_08002bb4
    adds r0, r2, #0
    bl sub_08002c10
    b lbl_08002bcc
    .align 2, 0
lbl_08002ba4: .4byte 0x0808f254
lbl_08002ba8: .4byte 0x0808f2c0
lbl_08002bac:
    ldr r1, [r3]
    ldr r0, [r2, #0x10]
    cmp r1, r0
    beq lbl_08002bcc
lbl_08002bb4:
    adds r0, r4, #0
    movs r1, #0
    bl sub_08003fac
    b lbl_08002bcc
lbl_08002bbe:
    lsls r0, r1, #0x18
    cmp r0, #0
    bne lbl_08002bcc
    adds r0, r5, #0
    movs r1, #0
    bl sub_08003fac
lbl_08002bcc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08002bd4
sub_08002bd4: @ 0x08002bd4
    push {lr}
    lsls r0, r0, #0x10
    ldr r2, lbl_08002c08 @ =0x0808f254
    ldr r1, lbl_08002c0c @ =0x0808f2c0
    lsrs r0, r0, #0xd
    adds r3, r0, r1
    ldrh r1, [r3, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r2
    ldr r2, [r0]
    ldrb r1, [r2]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_08002c04
    ldr r1, [r3]
    ldr r0, [r2, #0x10]
    cmp r1, r0
    bne lbl_08002c04
    adds r0, r2, #0
    bl sub_08002c10
lbl_08002c04:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002c08: .4byte 0x0808f254
lbl_08002c0c: .4byte 0x0808f2c0

    thumb_func_start sub_08002c10
sub_08002c10: @ 0x08002c10
    push {r4, lr}
    adds r2, r0, #0
    ldrb r0, [r2, #0x1c]
    cmp r0, #0
    bne lbl_08002c46
    movs r0, #1
    strb r0, [r2, #0x1c]
    ldrb r1, [r2]
    ands r0, r1
    cmp r0, #0
    beq lbl_08002c42
    movs r0, #2
    strb r0, [r2]
    movs r1, #0
    ldr r0, [r2, #0x18]
    ldrb r3, [r2, #1]
    cmp r1, r3
    bge lbl_08002c42
    movs r3, #0x40
lbl_08002c36:
    strb r3, [r0, #5]
    adds r1, #1
    adds r0, #0x50
    ldrb r4, [r2, #1]
    cmp r1, r4
    blt lbl_08002c36
lbl_08002c42:
    movs r0, #0
    strb r0, [r2, #0x1c]
lbl_08002c46:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start sub_08002c4c
sub_08002c4c: @ 0x08002c4c
    push {r4, r5, lr}
    ldr r0, lbl_08002c78 @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r4, r0, #1
    cmp r4, #0
    blt lbl_08002c72
    ldr r1, lbl_08002c7c @ =0x0808f254
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    adds r5, r0, r1
lbl_08002c64:
    ldr r0, [r5]
    bl sub_08002c10
    subs r5, #0xc
    subs r4, #1
    cmp r4, #0
    bge lbl_08002c64
lbl_08002c72:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002c78: .4byte 0x00000009
lbl_08002c7c: .4byte 0x0808f254

    thumb_func_start sub_08002c80
sub_08002c80: @ 0x08002c80
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl sub_08004014
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08002c94
sub_08002c94: @ 0x08002c94
    push {r4, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    cmp r1, #0
    bne lbl_08002ca6
    bl sub_08004c1c
    b lbl_08002cde
lbl_08002ca6:
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08002cde
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldrb r2, [r4]
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_08002cda
    movs r0, #0xf8
    ands r0, r2
    cmp r0, #0
    beq lbl_08002cca
    adds r0, r4, #0
    bl sub_08004c94
    b lbl_08002cda
lbl_08002cca:
    movs r0, #8
    orrs r0, r2
    strb r0, [r4]
    ldr r0, lbl_08002ce4 @ =0x0000ffff
    strh r0, [r4, #6]
    bl __divsi3
    strh r0, [r4, #8]
lbl_08002cda:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_08002cde:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002ce4: .4byte 0x0000ffff

    thumb_func_start sub_08002ce8
sub_08002ce8: @ 0x08002ce8
    push {r4, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08002d20
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldrb r2, [r4]
    movs r0, #2
    ands r0, r2
    cmp r0, #0
    beq lbl_08002d1c
    movs r0, #0xf8
    ands r0, r2
    cmp r0, #0
    bne lbl_08002d1c
    movs r0, #0x10
    orrs r0, r2
    strb r0, [r4]
    ldr r0, lbl_08002d28 @ =0x0000ffff
    strh r0, [r4, #6]
    bl __divsi3
    strh r0, [r4, #8]
lbl_08002d1c:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_08002d20:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002d28: .4byte 0x0000ffff

    thumb_func_start sub_08002d2c
sub_08002d2c: @ 0x08002d2c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    ldr r3, [r4, #0x18]
    ldrh r1, [r4, #6]
    ldrh r0, [r4, #8]
    subs r1, r1, r0
    cmp r1, #0
    blt lbl_08002d9c
    strh r1, [r4, #6]
    ldrb r1, [r4]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08002d72
    ldrh r0, [r4, #0x26]
    ldrh r1, [r4, #0x24]
    adds r0, r0, r1
    strh r0, [r4, #0x24]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x1c
    cmp r0, #0
    beq lbl_08002d6a
    adds r1, r4, #0
    adds r1, #0x22
    ldrb r0, [r1]
    subs r0, #1
    strb r0, [r1]
    ldrh r1, [r4, #0x24]
    ldr r0, lbl_08002d98 @ =0x00000fff
    ands r0, r1
    strh r0, [r4, #0x24]
lbl_08002d6a:
    adds r1, r4, #0
    adds r1, #0x23
    movs r0, #0
    strb r0, [r1]
lbl_08002d72:
    ldrb r2, [r4, #1]
    cmp r2, #0
    ble lbl_08002de2
    movs r5, #4
lbl_08002d7a:
    ldrb r1, [r3]
    cmp r1, #0
    beq lbl_08002d8c
    ldrh r0, [r4, #6]
    lsrs r0, r0, #0xa
    strb r0, [r3, #5]
    adds r0, r1, #0
    orrs r0, r5
    strb r0, [r3]
lbl_08002d8c:
    subs r2, #1
    adds r3, #0x50
    cmp r2, #0
    bgt lbl_08002d7a
    b lbl_08002de2
    .align 2, 0
lbl_08002d98: .4byte 0x00000fff
lbl_08002d9c:
    adds r0, r4, #0
    bl sub_08004c94
    ldrb r1, [r4]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08002db0
    movs r0, #0
    b lbl_08002dba
lbl_08002db0:
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08002dbc
    movs r0, #1
lbl_08002dba:
    strb r0, [r4]
lbl_08002dbc:
    ldrh r1, [r4, #0x20]
    cmp r1, #0
    beq lbl_08002de2
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08002dd6
    adds r2, r4, #0
    adds r2, #0x28
    ldrb r1, [r2]
    movs r0, #4
    b lbl_08002dde
lbl_08002dd6:
    adds r2, r4, #0
    adds r2, #0x28
    ldrb r1, [r2]
    movs r0, #1
lbl_08002dde:
    orrs r0, r1
    strb r0, [r2]
lbl_08002de2:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_08002de8
sub_08002de8: @ 0x08002de8
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl sub_08003fac
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08002dfc
sub_08002dfc: @ 0x08002dfc
    push {r4, r5, r6, lr}
    adds r5, r0, #0
    lsls r2, r2, #0x10
    lsrs r6, r2, #0x10
    bl sub_08004b50
    cmp r6, #0
    beq lbl_08002e2a
    ldrb r1, [r5, #0x1c]
    cmp r1, #0
    bne lbl_08002e2a
    movs r0, #1
    strb r0, [r5, #0x1c]
    movs r0, #0x22
    strb r0, [r5]
    movs r4, #0
    strh r1, [r5, #6]
    ldr r0, lbl_08002e30 @ =0x0000ffff
    adds r1, r6, #0
    bl __divsi3
    strh r0, [r5, #8]
    strb r4, [r5, #0x1c]
lbl_08002e2a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002e30: .4byte 0x0000ffff

    thumb_func_start sub_08002e34
sub_08002e34: @ 0x08002e34
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    ldrb r5, [r4, #0x1c]
    cmp r5, #0
    bne lbl_08002e60
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldrb r1, [r4]
    ands r0, r1
    cmp r0, #0
    beq lbl_08002e5e
    movs r0, #0x22
    strb r0, [r4]
    strh r5, [r4, #6]
    ldr r0, lbl_08002e68 @ =0x0000ffff
    adds r1, r2, #0
    bl __divsi3
    strh r0, [r4, #8]
lbl_08002e5e:
    strb r5, [r4, #0x1c]
lbl_08002e60:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002e68: .4byte 0x0000ffff

    thumb_func_start sub_08002e6c
sub_08002e6c: @ 0x08002e6c
    push {r4, r5, r6, lr}
    adds r3, r0, #0
    ldr r2, [r3, #0x18]
    ldrh r0, [r3, #6]
    ldrh r1, [r3, #8]
    adds r1, r0, r1
    ldr r0, lbl_08002ed4 @ =0x0000ffff
    cmp r1, r0
    bgt lbl_08002edc
    strh r1, [r3, #6]
    ldrb r1, [r3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08002eb4
    ldrh r0, [r3, #0x26]
    ldrh r1, [r3, #0x24]
    adds r0, r0, r1
    strh r0, [r3, #0x24]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x1c
    cmp r0, #0
    beq lbl_08002eac
    adds r1, r3, #0
    adds r1, #0x22
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
    ldrh r1, [r3, #0x24]
    ldr r0, lbl_08002ed8 @ =0x00000fff
    ands r0, r1
    strh r0, [r3, #0x24]
lbl_08002eac:
    adds r1, r3, #0
    adds r1, #0x23
    movs r0, #0
    strb r0, [r1]
lbl_08002eb4:
    ldrb r1, [r3, #1]
    cmp r1, #0
    ble lbl_08002efa
    movs r4, #4
lbl_08002ebc:
    ldrh r0, [r3, #6]
    lsrs r0, r0, #0xa
    strb r0, [r2, #5]
    ldrb r0, [r2]
    orrs r0, r4
    strb r0, [r2]
    subs r1, #1
    adds r2, #0x50
    cmp r1, #0
    bgt lbl_08002ebc
    b lbl_08002efa
    .align 2, 0
lbl_08002ed4: .4byte 0x0000ffff
lbl_08002ed8: .4byte 0x00000fff
lbl_08002edc:
    ldrb r1, [r3, #1]
    cmp r1, #0
    ble lbl_08002ef6
    movs r5, #0x40
    movs r4, #4
lbl_08002ee6:
    strb r5, [r2, #5]
    ldrb r0, [r2]
    orrs r0, r4
    strb r0, [r2]
    subs r1, #1
    adds r2, #0x50
    cmp r1, #0
    bgt lbl_08002ee6
lbl_08002ef6:
    movs r0, #2
    strb r0, [r3]
lbl_08002efa:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_08002f00
sub_08002f00: @ 0x08002f00
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov sb, r2
    ldr r0, lbl_08002f88 @ =0x03001d00
    ldrb r1, [r0, #1]
    mov sl, r0
    cmp r1, #0
    bne lbl_08003010
    movs r4, #1
    strb r4, [r0, #1]
    ldr r3, lbl_08002f8c @ =0x0808f254
    ldr r2, lbl_08002f90 @ =0x0808f2c0
    lsls r0, r5, #3
    adds r0, r0, r2
    mov ip, r0
    ldrh r1, [r0, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r6, [r0]
    lsls r0, r7, #3
    adds r0, r0, r2
    ldrh r1, [r0, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r5, [r0]
    ldrb r0, [r6, #0x1c]
    cmp r0, #0
    bne lbl_0800300a
    ldrb r0, [r5, #0x1c]
    cmp r0, #0
    bne lbl_0800300a
    strb r4, [r6, #0x1c]
    strb r4, [r5, #0x1c]
    ldrb r1, [r5]
    movs r2, #2
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08003000
    movs r0, #0xf8
    mov r8, r0
    ands r0, r1
    mov r8, r0
    cmp r0, #0
    bne lbl_08003000
    mov r1, ip
    ldr r7, [r1]
    ldrb r0, [r7]
    cmp r0, #0
    bne lbl_08002f94
    adds r0, r6, #0
    bl sub_08004c94
    b lbl_08003000
    .align 2, 0
lbl_08002f88: .4byte 0x03001d00
lbl_08002f8c: .4byte 0x0808f254
lbl_08002f90: .4byte 0x0808f2c0
lbl_08002f94:
    ldrb r1, [r6]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08002fac
    ldrb r0, [r6, #3]
    ldrb r1, [r7, #2]
    cmp r0, r1
    bhi lbl_08003000
    adds r0, r6, #0
    bl sub_08004c94
lbl_08002fac:
    ldrb r0, [r5]
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r5]
    ldr r0, lbl_08003020 @ =0x0000ffff
    strh r0, [r5, #6]
    mov r1, sb
    bl __divsi3
    movs r4, #0
    strh r0, [r5, #8]
    mov r1, sl
    ldrb r0, [r1, #5]
    lsls r0, r0, #0xc
    mov r1, sb
    bl __divsi3
    strh r0, [r5, #0x26]
    mov r0, r8
    strh r0, [r5, #0x24]
    mov r1, sl
    ldrb r0, [r1, #5]
    adds r1, r5, #0
    adds r1, #0x22
    strb r0, [r1]
    adds r0, r6, #0
    adds r1, r7, #0
    bl sub_08004b50
    movs r0, #0x42
    strb r0, [r6]
    mov r0, r8
    strh r0, [r6, #6]
    ldrh r0, [r5, #8]
    strh r0, [r6, #8]
    ldrh r0, [r5, #0x26]
    strh r0, [r6, #0x26]
    mov r1, r8
    strh r1, [r6, #0x24]
    adds r0, r6, #0
    adds r0, #0x22
    strb r4, [r0]
lbl_08003000:
    movs r0, #0
    strb r0, [r6, #0x1c]
    strb r0, [r5, #0x1c]
    ldr r0, lbl_08003024 @ =0x03001d00
    mov sl, r0
lbl_0800300a:
    movs r0, #0
    mov r1, sl
    strb r0, [r1, #1]
lbl_08003010:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003020: .4byte 0x0000ffff
lbl_08003024: .4byte 0x03001d00

    thumb_func_start sub_08003028
sub_08003028: @ 0x08003028
    push {r4, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08003052
    movs r0, #1
    strb r0, [r4, #0x1c]
    lsrs r1, r1, #0x18
    ldrh r0, [r4, #0xa]
    adds r2, r0, #0
    muls r2, r1, r2
    adds r0, r2, #0
    lsls r0, r0, #0x10
    lsrs r0, r0, #8
    movs r1, #0x96
    bl __divsi3
    movs r1, #0
    strh r0, [r4, #0xc]
    strb r1, [r4, #0x1c]
lbl_08003052:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start sub_08003058
sub_08003058: @ 0x08003058
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_080030ac
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldrb r1, [r4]
    movs r0, #0xf8
    ands r0, r1
    cmp r0, #0
    bne lbl_080030a8
    ldr r3, [r4, #0x18]
    movs r0, #0xff
    lsls r0, r0, #2
    ands r0, r2
    lsrs r2, r0, #2
    ldrb r0, [r4, #1]
    subs r1, r0, #1
    cmp r1, #0
    blt lbl_080030a8
    movs r6, #1
    movs r5, #4
lbl_0800308e:
    adds r0, r7, #0
    asrs r0, r1
    ands r0, r6
    cmp r0, #0
    beq lbl_080030a0
    strb r2, [r3, #5]
    ldrb r0, [r3]
    orrs r0, r5
    strb r0, [r3]
lbl_080030a0:
    subs r1, #1
    adds r3, #0x50
    cmp r1, #0
    bge lbl_0800308e
lbl_080030a8:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_080030ac:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080030b4
sub_080030b4: @ 0x080030b4
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08003104
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldr r3, [r4, #0x18]
    ldrb r1, [r4, #1]
    cmp r1, #0
    ble lbl_08003100
    mov ip, r0
    lsls r0, r2, #0x10
    asrs r5, r0, #0x18
    movs r6, #8
lbl_080030e2:
    mov r0, sb
    asrs r0, r1
    mov r7, ip
    ands r0, r7
    cmp r0, #0
    beq lbl_080030f8
    strb r5, [r3, #0x1d]
    strb r2, [r3, #0x1f]
    ldrb r0, [r3]
    orrs r0, r6
    strb r0, [r3]
lbl_080030f8:
    subs r1, #1
    adds r3, #0x50
    cmp r1, #0
    bgt lbl_080030e2
lbl_08003100:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_08003104:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08003110
sub_08003110: @ 0x08003110
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08003154
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldr r3, [r4, #0x18]
    ldrb r1, [r4, #1]
    cmp r1, #0
    ble lbl_08003150
    movs r7, #1
    lsls r0, r2, #0x18
    asrs r2, r0, #0x19
    movs r5, #4
lbl_08003136:
    adds r0, r6, #0
    asrs r0, r1
    ands r0, r7
    cmp r0, #0
    beq lbl_08003148
    strb r2, [r3, #7]
    ldrb r0, [r3]
    orrs r0, r5
    strb r0, [r3]
lbl_08003148:
    subs r1, #1
    adds r3, #0x50
    cmp r1, #0
    bgt lbl_08003136
lbl_08003150:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_08003154:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0800315c
sub_0800315c: @ 0x0800315c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_08003198
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldr r1, [r4, #0x18]
    movs r0, #0x7f
    ands r2, r0
    ldrb r3, [r4, #1]
    cmp r3, #0
    ble lbl_08003194
    movs r5, #1
lbl_08003180:
    adds r0, r6, #0
    asrs r0, r3
    ands r0, r5
    cmp r0, #0
    beq lbl_0800318c
    strb r2, [r1, #0x11]
lbl_0800318c:
    subs r3, #1
    adds r1, #0x50
    cmp r3, #0
    bgt lbl_08003180
lbl_08003194:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_08003198:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_080031a0
sub_080031a0: @ 0x080031a0
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldrb r0, [r4, #0x1c]
    cmp r0, #0
    bne lbl_080031dc
    movs r0, #1
    strb r0, [r4, #0x1c]
    ldr r1, [r4, #0x18]
    movs r0, #0x7f
    ands r2, r0
    ldrb r3, [r4, #1]
    cmp r3, #0
    ble lbl_080031d8
    movs r5, #1
lbl_080031c4:
    adds r0, r6, #0
    asrs r0, r3
    ands r0, r5
    cmp r0, #0
    beq lbl_080031d0
    strb r2, [r1, #0x10]
lbl_080031d0:
    subs r3, #1
    adds r1, #0x50
    cmp r3, #0
    bgt lbl_080031c4
lbl_080031d8:
    movs r0, #0
    strb r0, [r4, #0x1c]
lbl_080031dc:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start dma_transfer
dma_transfer: @ 0x080031e4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    adds r5, r1, #0
    adds r6, r2, #0
    ldr r1, [sp, #0x24]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    ldr r7, lbl_08003214 @ =0x040000b0
    adds r2, r0, r7
    cmp r1, #0x20
    bne lbl_08003218
    movs r0, #0x80
    lsls r0, r0, #0x13
    b lbl_0800321a
    .align 2, 0
lbl_08003214: .4byte 0x040000b0
lbl_08003218:
    movs r0, #0
lbl_0800321a:
    str r0, [sp]
    lsls r0, r4, #1
    movs r7, #0x80
    lsls r7, r7, #4
    mov ip, r7
    lsrs r1, r1, #4
    mov sl, r1
    asrs r7, r1
    movs r1, #0x80
    lsls r1, r1, #0x18
    mov r8, r1
    orrs r7, r1
    adds r0, r0, r4
    lsls r0, r0, #2
    mov sb, r0
lbl_08003238:
    cmp r3, ip
    bls lbl_08003274
    str r5, [r2]
    str r6, [r2, #4]
    ldr r0, [sp]
    orrs r0, r7
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_0800326c @ =0x040000b0
    add r1, sb
    ldr r0, [r1, #8]
    mov r4, r8
    ands r0, r4
    cmp r0, #0
    beq lbl_08003262
    movs r4, #0x80
    lsls r4, r4, #0x18
lbl_0800325a:
    ldr r0, [r1, #8]
    ands r0, r4
    cmp r0, #0
    bne lbl_0800325a
lbl_08003262:
    ldr r0, lbl_08003270 @ =0xfffff800
    adds r3, r3, r0
    add r5, ip
    add r6, ip
    b lbl_08003238
    .align 2, 0
lbl_0800326c: .4byte 0x040000b0
lbl_08003270: .4byte 0xfffff800
lbl_08003274:
    str r5, [r2]
    str r6, [r2, #4]
    mov r1, sl
    lsrs r3, r1
    mov r4, r8
    orrs r3, r4
    ldr r0, [sp]
    orrs r0, r3
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    ldr r1, lbl_080032b0 @ =0x040000b0
    add r1, sb
    ldr r0, [r1, #8]
    ands r0, r4
    cmp r0, #0
    beq lbl_080032a0
    movs r2, #0x80
    lsls r2, r2, #0x18
lbl_08003298:
    ldr r0, [r1, #8]
    ands r0, r2
    cmp r0, #0
    bne lbl_08003298
lbl_080032a0:
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080032b0: .4byte 0x040000b0

    thumb_func_start bit_fill
bit_fill: @ 0x080032b4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    str r1, [sp, #4]
    adds r6, r2, #0
    ldr r1, [sp, #0x28]
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r0, r4, #1
    adds r0, r0, r4
    lsls r0, r0, #2
    ldr r5, lbl_080032e4 @ =0x040000b0
    adds r2, r0, r5
    cmp r1, #0x20
    bne lbl_080032e8
    movs r0, #0x80
    lsls r0, r0, #0x13
    b lbl_080032ea
    .align 2, 0
lbl_080032e4: .4byte 0x040000b0
lbl_080032e8:
    movs r0, #0
lbl_080032ea:
    str r0, [sp]
    lsls r0, r4, #1
    movs r5, #0x80
    lsls r5, r5, #4
    mov sb, r5
    add r7, sp, #4
    lsrs r1, r1, #4
    mov r8, r1
    asrs r5, r1
    movs r1, #0x81
    lsls r1, r1, #0x18
    orrs r5, r1
    adds r0, r0, r4
    lsls r0, r0, #2
    mov ip, r0
    ldr r4, lbl_08003328 @ =0x040000b0
    mov sl, r4
lbl_0800330c:
    cmp r3, sb
    bls lbl_08003340
    str r7, [r2]
    str r6, [r2, #4]
    ldr r0, [sp]
    orrs r0, r5
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r1, ip
    add r1, sl
    ldr r0, [r1, #8]
    movs r4, #0x80
    lsls r4, r4, #0x18
    b lbl_0800332e
    .align 2, 0
lbl_08003328: .4byte 0x040000b0
lbl_0800332c:
    ldr r0, [r1, #8]
lbl_0800332e:
    ands r0, r4
    cmp r0, #0
    bne lbl_0800332c
    ldr r0, lbl_0800333c @ =0xfffff800
    adds r3, r3, r0
    add r6, sb
    b lbl_0800330c
    .align 2, 0
lbl_0800333c: .4byte 0xfffff800
lbl_08003340:
    str r7, [r2]
    str r6, [r2, #4]
    mov r1, r8
    lsrs r3, r1
    movs r4, #0x81
    lsls r4, r4, #0x18
    orrs r3, r4
    ldr r0, [sp]
    orrs r0, r3
    str r0, [r2, #8]
    ldr r0, [r2, #8]
    mov r1, ip
    add r1, sl
    ldr r0, [r1, #8]
    movs r5, #0x80
    lsls r5, r5, #0x18
    ands r0, r5
    cmp r0, #0
    beq lbl_08003370
    adds r2, r5, #0
lbl_08003368:
    ldr r0, [r1, #8]
    ands r0, r2
    cmp r0, #0
    bne lbl_08003368
lbl_08003370:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08003380
sub_08003380: @ 0x08003380
    push {r4, lr}
    ldr r3, lbl_080033c8 @ =0x03001d00
    ldrb r0, [r3, #0x10]
    adds r0, #1
    strb r0, [r3, #0x10]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrb r1, [r3, #0xe]
    cmp r0, r1
    bne lbl_080033c0
    ldr r0, lbl_080033cc @ =0x040000c4
    ldr r1, lbl_080033d0 @ =0x84400004
    str r1, [r0]
    adds r0, #0xc
    str r1, [r0]
    ldr r2, lbl_080033d4 @ =0x040000c6
    movs r4, #0xa0
    lsls r4, r4, #3
    adds r0, r4, #0
    strh r0, [r2]
    ldr r1, lbl_080033d8 @ =0x040000d2
    strh r0, [r1]
    movs r4, #0xb6
    lsls r4, r4, #8
    adds r0, r4, #0
    strh r0, [r2]
    movs r2, #0xf6
    lsls r2, r2, #8
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #0
    strb r0, [r3, #0x10]
lbl_080033c0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080033c8: .4byte 0x03001d00
lbl_080033cc: .4byte 0x040000c4
lbl_080033d0: .4byte 0x84400004
lbl_080033d4: .4byte 0x040000c6
lbl_080033d8: .4byte 0x040000d2

    thumb_func_start sub_080033dc
sub_080033dc: @ 0x080033dc
    push {r4, r5, lr}
    sub sp, #4
    ldr r5, lbl_08003440 @ =0x03001d00
    ldrb r4, [r5, #1]
    cmp r4, #0
    bne lbl_08003438
    movs r0, #1
    strb r0, [r5, #1]
    ldr r0, lbl_08003444 @ =0x04000064
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    strh r1, [r0]
    adds r0, #5
    movs r2, #8
    strb r2, [r0]
    adds r0, #3
    strh r1, [r0]
    adds r0, #4
    strb r4, [r0]
    adds r0, #9
    strb r2, [r0]
    adds r0, #3
    strh r1, [r0]
    adds r0, #0x48
    ldr r1, lbl_08003448 @ =0x84400004
    str r1, [r0]
    adds r0, #0xc
    str r1, [r0]
    subs r0, #0xa
    movs r2, #0xa0
    lsls r2, r2, #3
    adds r1, r2, #0
    strh r1, [r0]
    adds r0, #0xc
    strh r1, [r0]
    str r4, [sp]
    ldr r0, lbl_0800344c @ =0x00000c24
    adds r1, r5, r0
    ldr r2, lbl_08003450 @ =0x05000300
    mov r0, sp
    bl cpu_set
    ldr r0, lbl_08003454 @ =0x04000084
    strb r4, [r0]
    strb r4, [r5, #1]
lbl_08003438:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003440: .4byte 0x03001d00
lbl_08003444: .4byte 0x04000064
lbl_08003448: .4byte 0x84400004
lbl_0800344c: .4byte 0x00000c24
lbl_08003450: .4byte 0x05000300
lbl_08003454: .4byte 0x04000084

    thumb_func_start sub_08003458
sub_08003458: @ 0x08003458
    push {r4, r5, lr}
    sub sp, #4
    ldr r5, lbl_08003498 @ =0x03001d00
    ldrb r4, [r5, #1]
    cmp r4, #0
    bne lbl_08003490
    movs r0, #1
    strb r0, [r5, #1]
    ldr r0, lbl_0800349c @ =0x040000c4
    ldr r1, lbl_080034a0 @ =0x84400004
    str r1, [r0]
    adds r0, #0xc
    str r1, [r0]
    subs r0, #0xa
    movs r2, #0xa0
    lsls r2, r2, #3
    adds r1, r2, #0
    strh r1, [r0]
    adds r0, #0xc
    strh r1, [r0]
    str r4, [sp]
    ldr r0, lbl_080034a4 @ =0x00000c24
    adds r1, r5, r0
    ldr r2, lbl_080034a8 @ =0x05000300
    mov r0, sp
    bl cpu_set
    strb r4, [r5, #1]
lbl_08003490:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003498: .4byte 0x03001d00
lbl_0800349c: .4byte 0x040000c4
lbl_080034a0: .4byte 0x84400004
lbl_080034a4: .4byte 0x00000c24
lbl_080034a8: .4byte 0x05000300

    thumb_func_start sub_080034ac
sub_080034ac: @ 0x080034ac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    movs r3, #0
    movs r0, #1
    ldr r1, [sp]
    cmp r1, #0
    bne lbl_080034ca
    movs r0, #2
lbl_080034ca:
    adds r2, r0, #0
    ldr r0, lbl_0800352c @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r2, r0
    bhs lbl_080035ba
    str r0, [sp, #4]
lbl_080034d8:
    cmp r2, #2
    bne lbl_080034e2
    ldr r0, [sp]
    cmp r0, #0
    beq lbl_080034f4
lbl_080034e2:
    movs r1, #0xa5
    lsls r1, r1, #1
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r0, r2, #1
    mov sl, r0
    cmp r1, #0
    beq lbl_080035ae
lbl_080034f4:
    ldr r0, lbl_08003530 @ =0x0808f254
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r6, [r1]
    ldrb r0, [r6, #0x1c]
    adds r2, #1
    mov sl, r2
    cmp r0, #0
    bne lbl_080035ae
    movs r2, #1
    strb r2, [r6, #0x1c]
    ldrb r1, [r6, #0x1e]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_080035aa
    ldrb r1, [r6]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080035aa
    strb r2, [r6, #0x1e]
    movs r1, #0
    ldr r4, [r6, #0x18]
    b lbl_080035a4
    .align 2, 0
lbl_0800352c: .4byte 0x00000009
lbl_08003530: .4byte 0x0808f254
lbl_08003534:
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r2, [r0]
    movs r0, #0xc0
    ands r0, r2
    adds r1, #1
    mov r8, r1
    movs r1, #0x50
    adds r1, r1, r4
    mov sb, r1
    cmp r0, #0
    bne lbl_0800359c
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_08003564
    movs r1, #7
    ands r1, r2
    subs r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    str r3, [sp, #8]
    bl sub_080024c0
    ldr r3, [sp, #8]
lbl_08003564:
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_0800359c
    adds r4, r0, #0
    ldr r7, lbl_080035cc @ =0x03003834
    movs r5, #0
lbl_08003570:
    lsls r0, r3, #3
    subs r0, r0, r3
    lsls r0, r0, #3
    adds r0, r0, r7
    stm r0!, {r4}
    adds r1, r4, #0
    movs r2, #0x34
    str r3, [sp, #8]
    bl memcpy
    ldr r3, [sp, #8]
    adds r0, r3, #1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    strb r5, [r4]
    str r5, [r4, #0x28]
    ldr r0, [r4, #0x30]
    str r5, [r4, #0x30]
    str r5, [r4, #0x2c]
    adds r4, r0, #0
    cmp r4, #0
    bne lbl_08003570
lbl_0800359c:
    mov r1, r8
    lsls r0, r1, #0x18
    lsrs r1, r0, #0x18
    mov r4, sb
lbl_080035a4:
    ldrb r0, [r6, #1]
    cmp r1, r0
    blo lbl_08003534
lbl_080035aa:
    movs r0, #0
    strb r0, [r6, #0x1c]
lbl_080035ae:
    mov r1, sl
    lsls r0, r1, #0x18
    lsrs r2, r0, #0x18
    ldr r0, [sp, #4]
    cmp r2, r0
    blo lbl_080034d8
lbl_080035ba:
    add sp, #0xc
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080035cc: .4byte 0x03003834

    thumb_func_start sub_080035d0
sub_080035d0: @ 0x080035d0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    str r0, [sp]
    movs r0, #0
    mov sb, r0
    movs r0, #1
    ldr r1, [sp]
    cmp r1, #0
    bne lbl_080035f0
    movs r0, #2
lbl_080035f0:
    adds r2, r0, #0
    ldr r0, lbl_0800364c @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r2, r0
    bhs lbl_080036ba
    str r0, [sp, #4]
lbl_080035fe:
    cmp r2, #2
    bne lbl_08003608
    ldr r0, [sp]
    cmp r0, #0
    beq lbl_0800361a
lbl_08003608:
    movs r0, #0xa5
    lsls r0, r0, #1
    asrs r0, r2
    movs r1, #1
    ands r0, r1
    adds r1, r2, #1
    mov sl, r1
    cmp r0, #0
    beq lbl_080036ae
lbl_0800361a:
    ldr r0, lbl_08003650 @ =0x0808f254
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r5, [r1]
    ldrb r0, [r5, #0x1c]
    adds r2, #1
    mov sl, r2
    cmp r0, #0
    bne lbl_080036ae
    movs r0, #1
    strb r0, [r5, #0x1c]
    ldrb r1, [r5, #0x1e]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_080036aa
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r5, #0x1e]
    movs r3, #0
    ldr r2, [r5, #0x18]
    b lbl_080036a4
    .align 2, 0
lbl_0800364c: .4byte 0x00000009
lbl_08003650: .4byte 0x0808f254
lbl_08003654:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #0xc0
    ands r0, r1
    adds r6, r3, #1
    adds r7, r2, #0
    adds r7, #0x50
    cmp r0, #0
    bne lbl_0800369e
    ldr r0, [r2, #0x48]
    cmp r0, #0
    beq lbl_0800369e
    adds r4, r0, #0
    ldr r0, lbl_080036cc @ =0x03003834
    mov r8, r0
lbl_08003674:
    adds r0, r4, #0
    bl sub_080020a4
    mov r0, sb
    lsls r1, r0, #3
    subs r1, r1, r0
    lsls r1, r1, #3
    add r1, r8
    adds r1, #4
    adds r0, r4, #0
    movs r2, #0x34
    bl memcpy
    mov r0, sb
    adds r0, #1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov sb, r0
    ldr r4, [r4, #0x30]
    cmp r4, #0
    bne lbl_08003674
lbl_0800369e:
    lsls r0, r6, #0x18
    lsrs r3, r0, #0x18
    adds r2, r7, #0
lbl_080036a4:
    ldrb r1, [r5, #1]
    cmp r3, r1
    blo lbl_08003654
lbl_080036aa:
    movs r0, #0
    strb r0, [r5, #0x1c]
lbl_080036ae:
    mov r1, sl
    lsls r0, r1, #0x18
    lsrs r2, r0, #0x18
    ldr r0, [sp, #4]
    cmp r2, r0
    blo lbl_080035fe
lbl_080036ba:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080036cc: .4byte 0x03003834

    thumb_func_start update_music_track
update_music_track: @ 0x080036d0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r0, lbl_080036fc @ =0x03001d00
    mov r8, r0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_08003776
    movs r0, #0x70
    ands r0, r1
    cmp r0, #0
    beq lbl_08003700
    adds r0, r4, #0
    bl sub_0800378c
    b lbl_08003776
    .align 2, 0
lbl_080036fc: .4byte 0x03001d00
lbl_08003700:
    lsls r0, r1, #0x18
    cmp r0, #0
    bne lbl_08003776
    mov r1, r8
    ldrb r5, [r1, #1]
    cmp r5, #0
    bne lbl_08003776
    movs r0, #1
    strb r0, [r1, #1]
    ldr r6, lbl_08003780 @ =0x0808f254
    ldr r0, [r6, #0x48]
    movs r1, #0xa
    bl sub_08002c94
    ldr r0, [r6, #0x60]
    movs r1, #0xa
    bl sub_08002c94
    ldr r3, lbl_08003784 @ =0x03003b44
    adds r2, r3, #0
    adds r2, #0x30
    ldrb r1, [r2]
    movs r7, #3
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08003738
    strb r5, [r2]
lbl_08003738:
    adds r2, r3, #0
    adds r2, #0x40
    ldrb r1, [r2]
    adds r0, r7, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08003748
    strb r5, [r2]
lbl_08003748:
    ldr r6, [r6]
    cmp r4, #0
    bne lbl_08003750
    movs r4, #0xa9
lbl_08003750:
    adds r0, r4, #0
    bl sub_08003980
    adds r4, r0, #0
    ldr r1, lbl_08003788 @ =0x0808f2c0
    lsls r0, r4, #3
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r0, [r6, #0x10]
    cmp r1, r0
    beq lbl_08003772
    adds r0, r6, #0
    movs r1, #0x1e
    bl sub_08002c94
    mov r0, r8
    strh r4, [r0, #0x22]
lbl_08003772:
    mov r1, r8
    strb r5, [r1, #1]
lbl_08003776:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003780: .4byte 0x0808f254
lbl_08003784: .4byte 0x03003b44
lbl_08003788: .4byte 0x0808f2c0

    thumb_func_start sub_0800378c
sub_0800378c: @ 0x0800378c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r7, lbl_08003808 @ =0x03001d00
    ldrb r6, [r7, #1]
    cmp r6, #0
    bne lbl_08003866
    movs r0, #1
    strb r0, [r7, #1]
    ldr r4, lbl_0800380c @ =0x0808f254
    ldr r0, [r4, #0x48]
    movs r1, #0xa
    bl sub_08002c94
    ldr r0, [r4, #0x60]
    movs r1, #0xa
    bl sub_08002c94
    ldr r3, lbl_08003810 @ =0x03003b44
    adds r2, r3, #0
    adds r2, #0x30
    ldrb r1, [r2]
    movs r4, #3
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080037c4
    strb r6, [r2]
lbl_080037c4:
    adds r2, r3, #0
    adds r2, #0x40
    ldrb r1, [r2]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_080037d4
    strb r6, [r2]
lbl_080037d4:
    adds r0, r7, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x30
    ands r0, r1
    cmp r0, #0
    beq lbl_08003822
    ldrh r0, [r7, #0x1c]
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003814
    adds r0, r5, #0
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bls lbl_0800383a
    movs r0, #0x10
    ands r0, r1
    movs r5, #0x49
    cmp r0, #0
    beq lbl_0800383a
    movs r5, #0x46
    b lbl_0800383a
    .align 2, 0
lbl_08003808: .4byte 0x03001d00
lbl_0800380c: .4byte 0x0808f254
lbl_08003810: .4byte 0x03003b44
lbl_08003814:
    adds r0, r5, #0
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bls lbl_0800383a
    b lbl_08003860
lbl_08003822:
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0800383a
    adds r0, r5, #0
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003860
    strh r5, [r7, #0x22]
    b lbl_08003860
lbl_0800383a:
    ldr r0, lbl_0800386c @ =0x0808f254
    ldr r6, [r0]
    ldr r4, lbl_08003870 @ =0x0808f2c0
    adds r0, r5, #0
    bl sub_08003980
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r4
    ldr r1, [r0]
    ldr r0, [r6, #0x10]
    cmp r1, r0
    beq lbl_08003860
    adds r0, r6, #0
    movs r1, #0x1e
    bl sub_08002c94
    ldr r0, lbl_08003874 @ =0x03001d00
    strh r5, [r0, #0x22]
lbl_08003860:
    ldr r1, lbl_08003874 @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003866:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800386c: .4byte 0x0808f254
lbl_08003870: .4byte 0x0808f2c0
lbl_08003874: .4byte 0x03001d00

    thumb_func_start check_play_new_music_track
check_play_new_music_track: @ 0x08003878
    push {r4, r5, lr}
    ldr r4, lbl_08003898 @ =0x03001d00
    adds r0, r4, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #4
    ands r0, r1
    cmp r0, #0
    bne lbl_080038c8
    movs r0, #0x70
    ands r0, r1
    cmp r0, #0
    beq lbl_0800389c
    bl sub_080038d8
    b lbl_080038c8
    .align 2, 0
lbl_08003898: .4byte 0x03001d00
lbl_0800389c:
    lsls r0, r1, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_080038c8
    ldrh r0, [r4, #0x22]
    cmp r0, #0
    beq lbl_080038c8
    ldr r0, lbl_080038d0 @ =0x0808f254
    ldr r0, [r0]
    ldr r2, lbl_080038d4 @ =0x0808f2c0
    ldrh r1, [r4, #0x22]
    lsls r1, r1, #3
    adds r1, r1, r2
    ldr r1, [r1]
    bl sub_08004b50
    adds r0, r4, #0
    adds r0, #0x20
    strb r5, [r0]
    ldrh r0, [r4, #0x22]
    strh r0, [r4, #0x1c]
    strh r5, [r4, #0x22]
lbl_080038c8:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080038d0: .4byte 0x0808f254
lbl_080038d4: .4byte 0x0808f2c0

    thumb_func_start sub_080038d8
sub_080038d8: @ 0x080038d8
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_08003924 @ =0x03001d00
    adds r0, r6, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x40
    ands r0, r1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    cmp r7, #0
    bne lbl_08003918
    ldrh r0, [r6, #0x22]
    cmp r0, #0
    beq lbl_08003918
    ldr r0, lbl_08003928 @ =0x0808f254
    ldr r5, [r0]
    ldr r4, lbl_0800392c @ =0x0808f2c0
    ldrh r0, [r6, #0x22]
    bl sub_08003980
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r4
    ldr r1, [r0]
    adds r0, r5, #0
    bl sub_08004b50
    adds r0, r6, #0
    adds r0, #0x20
    strb r7, [r0]
    ldrh r0, [r6, #0x22]
    strh r0, [r6, #0x1c]
lbl_08003918:
    ldr r1, lbl_08003924 @ =0x03001d00
    movs r0, #0
    strh r0, [r1, #0x22]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003924: .4byte 0x03001d00
lbl_08003928: .4byte 0x0808f254
lbl_0800392c: .4byte 0x0808f2c0

    thumb_func_start update_music_after_alarm_disable
update_music_after_alarm_disable: @ 0x08003930
    push {lr}
    ldr r1, lbl_08003950 @ =0x03001d00
    adds r2, r1, #0
    adds r2, #0x21
    movs r0, #0x20
    strb r0, [r2]
    ldrh r0, [r1, #0x22]
    cmp r0, #0
    bne lbl_08003954
    movs r0, #5
    movs r1, #0x49
    movs r2, #0x20
    bl sub_08003b30
    b lbl_0800397a
    .align 2, 0
lbl_08003950: .4byte 0x03001d00
lbl_08003954:
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003970
    ldr r0, lbl_0800396c @ =0x0808f254
    ldr r0, [r0]
    movs r1, #5
    bl sub_08002c94
    b lbl_0800397a
    .align 2, 0
lbl_0800396c: .4byte 0x0808f254
lbl_08003970:
    movs r0, #5
    movs r1, #0x49
    movs r2, #0x20
    bl sub_08003b30
lbl_0800397a:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08003980
sub_08003980: @ 0x08003980
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r1, r0, #0
    subs r1, #0x5a
    cmp r1, #4
    bhi lbl_080039c2
    lsls r0, r1, #2
    ldr r1, lbl_08003998 @ =lbl_0800399c
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08003998: .4byte lbl_0800399c
lbl_0800399c: @ jump table
    .4byte lbl_080039b0 @ case 0
    .4byte lbl_080039b4 @ case 1
    .4byte lbl_080039b8 @ case 2
    .4byte lbl_080039bc @ case 3
    .4byte lbl_080039c0 @ case 4
lbl_080039b0:
    movs r0, #0xe
    b lbl_080039c2
lbl_080039b4:
    movs r0, #0xc
    b lbl_080039c2
lbl_080039b8:
    movs r0, #3
    b lbl_080039c2
lbl_080039bc:
    movs r0, #0x17
    b lbl_080039c2
lbl_080039c0:
    movs r0, #0x46
lbl_080039c2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_080039c8
sub_080039c8: @ 0x080039c8
    push {r4, lr}
    ldr r0, lbl_080039ec @ =0x03001d00
    adds r0, #0x21
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080039e6
    ldr r4, lbl_080039f0 @ =0x0808f254
    ldr r0, [r4, #0x48]
    movs r1, #0xa
    bl sub_08002c94
    ldr r0, [r4, #0x60]
    movs r1, #0xa
    bl sub_08002c94
lbl_080039e6:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080039ec: .4byte 0x03001d00
lbl_080039f0: .4byte 0x0808f254

    thumb_func_start sub_080039f4
sub_080039f4: @ 0x080039f4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r6, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, lbl_08003a60 @ =0x03001d00
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08003a58
    movs r0, #1
    strb r0, [r3, #1]
    adds r5, r3, #0
    adds r5, #0x21
    ldrb r2, [r5]
    movs r4, #0x84
    ands r4, r2
    cmp r4, #0
    bne lbl_08003a52
    movs r0, #0x80
    ands r0, r2
    orrs r0, r1
    strb r0, [r5]
    ldr r1, lbl_08003a64 @ =0x0808f2c0
    lsls r0, r6, #3
    adds r0, r0, r1
    ldr r5, [r0]
    ldr r0, lbl_08003a68 @ =0x0808f254
    ldr r2, [r0]
    ldr r0, [r2, #0x10]
    cmp r5, r0
    bne lbl_08003a3e
    ldrb r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    bne lbl_08003a52
lbl_08003a3e:
    adds r0, r3, #0
    adds r0, #0x20
    strb r4, [r0]
    movs r0, #0
    strh r7, [r3, #0x1c]
    strb r0, [r3, #1]
    adds r0, r2, #0
    adds r1, r5, #0
    bl sub_08004b50
lbl_08003a52:
    ldr r1, lbl_08003a60 @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003a58:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003a60: .4byte 0x03001d00
lbl_08003a64: .4byte 0x0808f2c0
lbl_08003a68: .4byte 0x0808f254

    thumb_func_start sub_08003a6c
sub_08003a6c: @ 0x08003a6c
    push {lr}
    ldr r0, lbl_08003a80 @ =0x03001d00
    adds r0, #0x20
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08003a88
    ldr r0, lbl_08003a84 @ =0x0808f254
    ldr r0, [r0]
    b lbl_08003a8c
    .align 2, 0
lbl_08003a80: .4byte 0x03001d00
lbl_08003a84: .4byte 0x0808f254
lbl_08003a88:
    ldr r0, lbl_08003a94 @ =0x0808f254
    ldr r0, [r0, #0xc]
lbl_08003a8c:
    bl sub_08004c1c
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003a94: .4byte 0x0808f254

    thumb_func_start fade_music
fade_music: @ 0x08003a98
    push {lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r1, lbl_08003ac8 @ =0x03001d00
    ldrb r0, [r1, #1]
    cmp r0, #0
    bne lbl_08003ada
    movs r0, #1
    strb r0, [r1, #1]
    adds r0, r1, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003ad4
    ldr r0, lbl_08003acc @ =0x0808f254
    ldr r0, [r0]
    cmp r2, #0
    beq lbl_08003ad0
    adds r1, r2, #0
    bl sub_08002c94
    b lbl_08003ad4
    .align 2, 0
lbl_08003ac8: .4byte 0x03001d00
lbl_08003acc: .4byte 0x0808f254
lbl_08003ad0:
    bl sub_08004c1c
lbl_08003ad4:
    ldr r1, lbl_08003ae0 @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003ada:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003ae0: .4byte 0x03001d00

    thumb_func_start sub_08003ae4
sub_08003ae4: @ 0x08003ae4
    push {lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r1, lbl_08003b14 @ =0x03001d00
    ldrb r0, [r1, #1]
    cmp r0, #0
    bne lbl_08003b26
    movs r0, #1
    strb r0, [r1, #1]
    adds r0, r1, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_08003b20
    ldr r0, lbl_08003b18 @ =0x0808f254
    ldr r0, [r0]
    cmp r2, #0
    beq lbl_08003b1c
    adds r1, r2, #0
    bl sub_08002c94
    b lbl_08003b20
    .align 2, 0
lbl_08003b14: .4byte 0x03001d00
lbl_08003b18: .4byte 0x0808f254
lbl_08003b1c:
    bl sub_08004c1c
lbl_08003b20:
    ldr r1, lbl_08003b2c @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003b26:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003b2c: .4byte 0x03001d00

    thumb_func_start sub_08003b30
sub_08003b30: @ 0x08003b30
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r7, r4, #0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    adds r6, r3, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r5, r2, #0
    ldr r0, lbl_08003b60 @ =0x03001d00
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003b72
    cmp r4, #0
    bne lbl_08003b64
    adds r0, r3, #0
    adds r1, r2, #0
    bl sub_080039f4
    b lbl_08003b72
    .align 2, 0
lbl_08003b60: .4byte 0x03001d00
lbl_08003b64:
    ldr r0, lbl_08003b78 @ =0x0808f254
    ldr r0, [r0]
    strh r6, [r0, #0x20]
    strb r5, [r0, #0x1f]
    adds r1, r7, #0
    bl sub_08002c94
lbl_08003b72:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003b78: .4byte 0x0808f254

    thumb_func_start sub_08003b7c
sub_08003b7c: @ 0x08003b7c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    adds r7, r5, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    adds r3, r4, #0
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    adds r6, r2, #0
    ldr r0, lbl_08003bac @ =0x03001d00
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003bc6
    cmp r5, #0
    bne lbl_08003bb0
    adds r0, r4, #0
    adds r1, r2, #0
    bl sub_080039f4
    b lbl_08003bc6
    .align 2, 0
lbl_08003bac: .4byte 0x03001d00
lbl_08003bb0:
    ldr r0, lbl_08003bcc @ =0x0808f254
    ldr r0, [r0]
    movs r2, #0x80
    lsls r2, r2, #8
    adds r1, r2, #0
    orrs r3, r1
    strh r3, [r0, #0x20]
    strb r6, [r0, #0x1f]
    adds r1, r7, #0
    bl sub_08002ce8
lbl_08003bc6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003bcc: .4byte 0x0808f254

    thumb_func_start sub_08003bd0
sub_08003bd0: @ 0x08003bd0
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    ldr r0, lbl_08003c14 @ =0x03001d00
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003c0c
    ldr r3, lbl_08003c18 @ =0x0808f254
    ldr r0, lbl_08003c1c @ =0x0808f2c0
    lsls r2, r2, #3
    adds r2, r2, r0
    ldrh r1, [r2, #4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #2
    adds r0, r0, r3
    ldr r3, [r0]
    ldr r1, [r2]
    ldr r0, [r3, #0x10]
    cmp r1, r0
    bne lbl_08003c0c
    adds r0, r3, #0
    adds r1, r4, #0
    bl sub_08002e34
lbl_08003c0c:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003c14: .4byte 0x03001d00
lbl_08003c18: .4byte 0x0808f254
lbl_08003c1c: .4byte 0x0808f2c0

    thumb_func_start sub_08003c20
sub_08003c20: @ 0x08003c20
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r6, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov ip, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r3, lbl_08003c94 @ =0x03001d00
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08003c8c
    movs r0, #1
    strb r0, [r3, #1]
    adds r5, r3, #0
    adds r5, #0x21
    ldrb r1, [r5]
    movs r4, #0x84
    ands r4, r1
    cmp r4, #0
    bne lbl_08003c86
    movs r0, #0x80
    ands r0, r1
    orrs r0, r2
    strb r0, [r5]
    ldr r1, lbl_08003c98 @ =0x0808f2c0
    lsls r0, r6, #3
    adds r0, r0, r1
    ldr r5, [r0]
    ldr r0, lbl_08003c9c @ =0x0808f254
    ldr r2, [r0]
    ldrb r1, [r2]
    movs r0, #0x1a
    ands r0, r1
    cmp r0, #2
    bne lbl_08003c70
    ldr r0, [r2, #0x10]
    cmp r5, r0
    beq lbl_08003c86
lbl_08003c70:
    adds r0, r3, #0
    adds r0, #0x20
    strb r4, [r0]
    movs r0, #0
    strh r7, [r3, #0x1c]
    strb r0, [r3, #1]
    adds r0, r2, #0
    adds r1, r5, #0
    mov r2, ip
    bl sub_08002dfc
lbl_08003c86:
    ldr r1, lbl_08003c94 @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003c8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003c94: .4byte 0x03001d00
lbl_08003c98: .4byte 0x0808f2c0
lbl_08003c9c: .4byte 0x0808f254

    thumb_func_start sub_08003ca0
sub_08003ca0: @ 0x08003ca0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    adds r6, r3, #0
    ldr r1, lbl_08003d00 @ =0x03001d00
    ldrb r0, [r1, #1]
    cmp r0, #0
    bne lbl_08003d40
    movs r7, #0
    movs r0, #1
    strb r0, [r1, #1]
    adds r0, r1, #0
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003d3a
    ldr r1, lbl_08003d04 @ =0x0808f2c0
    lsls r0, r2, #3
    adds r0, r0, r1
    ldr r5, [r0]
    ldr r2, lbl_08003d08 @ =0x0808f254
    ldr r4, [r2]
    ldrb r1, [r4]
    movs r0, #0x1a
    ands r0, r1
    cmp r0, #2
    bne lbl_08003ce4
    ldr r0, [r4, #0x10]
    cmp r5, r0
    beq lbl_08003d3a
lbl_08003ce4:
    cmp r3, #0
    bne lbl_08003d0c
    ldr r0, [r2, #0x24]
    bl sub_08004c1c
    movs r0, #1
    bl sub_080034ac
    bl sub_08002a8c
    adds r2, r4, #0
    adds r2, #0x28
    ldrb r0, [r2]
    b lbl_08003d1e
    .align 2, 0
lbl_08003d00: .4byte 0x03001d00
lbl_08003d04: .4byte 0x0808f2c0
lbl_08003d08: .4byte 0x0808f254
lbl_08003d0c:
    cmp r6, #1
    bne lbl_08003d24
    bl sub_08002a8c
    adds r2, r4, #0
    adds r2, #0x28
    ldrb r0, [r2]
    movs r1, #0x40
    orrs r0, r1
lbl_08003d1e:
    movs r1, #0x80
    orrs r0, r1
    strb r0, [r2]
lbl_08003d24:
    ldr r3, lbl_08003d48 @ =0x03001d00
    adds r1, r3, #0
    adds r1, #0x20
    movs r2, #0
    movs r0, #1
    strb r0, [r1]
    strb r2, [r3, #1]
    adds r0, r4, #0
    adds r1, r5, #0
    bl sub_08004b50
lbl_08003d3a:
    ldr r1, lbl_08003d48 @ =0x03001d00
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003d40:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003d48: .4byte 0x03001d00

    thumb_func_start sub_08003d4c
sub_08003d4c: @ 0x08003d4c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldr r4, lbl_08003d98 @ =0x03001d00
    ldrb r5, [r4, #1]
    cmp r5, #0
    bne lbl_08003e02
    movs r0, #1
    strb r0, [r4, #1]
    movs r0, #0x40
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    bne lbl_08003d76
    movs r0, #1
    bl sub_080035d0
lbl_08003d76:
    ldr r0, lbl_08003d9c @ =0x0808f254
    ldr r6, [r0]
    adds r0, r4, #0
    adds r0, #0x20
    strb r5, [r0]
    ldrh r0, [r4, #0x1c]
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003da0
    ldrh r0, [r4, #0x1c]
    bl sub_08003980
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    b lbl_08003da2
    .align 2, 0
lbl_08003d98: .4byte 0x03001d00
lbl_08003d9c: .4byte 0x0808f254
lbl_08003da0:
    ldrh r0, [r4, #0x1c]
lbl_08003da2:
    ldr r1, lbl_08003e10 @ =0x0808f2c0
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r7, lbl_08003e14 @ =0x03001d00
    movs r0, #0
    mov sb, r0
    mov r0, sb
    strb r0, [r7, #1]
    adds r0, r6, #0
    bl sub_08004b50
    movs r0, #0x40
    mov r1, r8
    ands r0, r1
    cmp r0, #0
    beq lbl_08003dcc
    adds r0, r6, #0
    movs r1, #0x3c
    bl sub_080041ec
lbl_08003dcc:
    ldrb r1, [r7, #0xb]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_08003dfe
    ldr r5, lbl_08003e18 @ =0x0808f254
    ldr r0, [r5]
    ldr r6, lbl_08003e1c @ =0x0000ffff
    ldr r4, lbl_08003e20 @ =0x00000050
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    adds r1, r6, #0
    adds r2, r4, #0
    bl sub_08003058
    ldr r0, [r5, #0xc]
    adds r1, r6, #0
    adds r2, r4, #0
    bl sub_08003058
    ldr r0, [r5, #0x54]
    adds r1, r6, #0
    adds r2, r4, #0
    bl sub_08003058
lbl_08003dfe:
    mov r0, sb
    strb r0, [r7, #1]
lbl_08003e02:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003e10: .4byte 0x0808f2c0
lbl_08003e14: .4byte 0x03001d00
lbl_08003e18: .4byte 0x0808f254
lbl_08003e1c: .4byte 0x0000ffff
lbl_08003e20: .4byte 0x00000050

    thumb_func_start sub_08003e24
sub_08003e24: @ 0x08003e24
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_08003e3c @ =0x03001d00
    adds r0, #0x20
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08003e44
    ldr r0, lbl_08003e40 @ =0x0808f254
    ldr r0, [r0]
    b lbl_08003e48
    .align 2, 0
lbl_08003e3c: .4byte 0x03001d00
lbl_08003e40: .4byte 0x0808f254
lbl_08003e44:
    ldr r0, lbl_08003e54 @ =0x0808f254
    ldr r0, [r0, #0xc]
lbl_08003e48:
    cmp r1, #0
    beq lbl_08003e58
    bl sub_08002c94
    b lbl_08003e5c
    .align 2, 0
lbl_08003e54: .4byte 0x0808f254
lbl_08003e58:
    bl sub_08004c1c
lbl_08003e5c:
    pop {r0}
    bx r0

    thumb_func_start sub_08003e60
sub_08003e60: @ 0x08003e60
    push {r4, lr}
    lsls r0, r0, #0x18
lbl_08003e64:
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    ldr r1, lbl_08003e88 @ =0x03001d00
    ldrb r0, [r1, #1]
    adds r3, r1, #0
    cmp r0, #0
    bne lbl_08003eb0
    movs r0, #1
    strb r0, [r3, #1]
    cmp r2, #0x80
    bne lbl_08003e8c
    adds r4, r3, #0
    adds r4, #0x21
    ldrb r1, [r4]
    adds r0, r2, #0
    orrs r0, r1
    strb r0, [r4]
    b lbl_08003eac
    .align 2, 0
lbl_08003e88: .4byte 0x03001d00
lbl_08003e8c:
    cmp r2, #0xff
    bne lbl_08003e9e
    adds r2, r3, #0
    adds r2, #0x21
    ldrb r1, [r2]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r2]
    b lbl_08003eac
lbl_08003e9e:
    adds r2, r3, #0
    adds r2, #0x21
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    orrs r4, r0
    strb r4, [r2]
lbl_08003eac:
    movs r0, #0
    strb r0, [r3, #1]
lbl_08003eb0:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08003eb8
sub_08003eb8: @ 0x08003eb8
    push {r4, r5, r6, lr}
    ldr r1, lbl_08003ef0 @ =0x03001d00
    ldrb r2, [r1, #1]
    cmp r2, #0
    bne lbl_08003f12
    movs r0, #1
    strb r0, [r1, #1]
    ldr r0, lbl_08003ef4 @ =0x0808f254
    ldr r6, [r0]
    adds r0, r1, #0
    adds r0, #0x20
    strb r2, [r0]
    ldrh r2, [r1, #0x1c]
    adds r0, r2, #0
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003efc
    ldr r4, lbl_08003ef8 @ =0x0808f2c0
    adds r0, r2, #0
    bl sub_08003980
    lsls r0, r0, #0x10
    lsrs r0, r0, #0xd
    adds r0, r0, r4
    b lbl_08003f02
    .align 2, 0
lbl_08003ef0: .4byte 0x03001d00
lbl_08003ef4: .4byte 0x0808f254
lbl_08003ef8: .4byte 0x0808f2c0
lbl_08003efc:
    ldr r1, lbl_08003f18 @ =0x0808f2c0
    lsls r0, r2, #3
    adds r0, r0, r1
lbl_08003f02:
    ldr r1, [r0]
    ldr r5, lbl_08003f1c @ =0x03001d00
    movs r4, #0
    strb r4, [r5, #1]
    adds r0, r6, #0
    bl sub_08004b50
    strb r4, [r5, #1]
lbl_08003f12:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003f18: .4byte 0x0808f2c0
lbl_08003f1c: .4byte 0x03001d00

    thumb_func_start sub_08003f20
sub_08003f20: @ 0x08003f20
    push {r4, r5, r6, lr}
    movs r0, #0x63
    bl play_sound1
    movs r0, #0
    bl sub_080034ac
    ldr r2, lbl_08003f5c @ =0x03001d00
    ldrb r1, [r2, #0xb]
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #0xb]
    ldr r5, lbl_08003f60 @ =0x0808f254
    ldr r0, [r5]
    ldr r6, lbl_08003f64 @ =0x0000ffff
    ldr r4, lbl_08003f68 @ =0x00000050
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    adds r1, r6, #0
    adds r2, r4, #0
    bl sub_08003058
    ldr r0, [r5, #0xc]
    adds r1, r6, #0
    adds r2, r4, #0
    bl sub_08003058
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003f5c: .4byte 0x03001d00
lbl_08003f60: .4byte 0x0808f254
lbl_08003f64: .4byte 0x0000ffff
lbl_08003f68: .4byte 0x00000050

    thumb_func_start sub_08003f6c
sub_08003f6c: @ 0x08003f6c
    push {r4, r5, r6, lr}
    ldr r4, lbl_08003fa0 @ =0x0808f254
    ldr r0, [r4]
    ldr r5, lbl_08003fa4 @ =0x0000ffff
    movs r6, #0x80
    lsls r6, r6, #1
    adds r1, r5, #0
    adds r2, r6, #0
    bl sub_08003058
    ldr r0, [r4, #0xc]
    adds r1, r5, #0
    adds r2, r6, #0
    bl sub_08003058
    ldr r2, lbl_08003fa8 @ =0x03001d00
    ldrb r1, [r2, #0xb]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r2, #0xb]
    movs r0, #0
    bl sub_080035d0
lbl_08003f9a:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003fa0: .4byte 0x0808f254
lbl_08003fa4: .4byte 0x0000ffff
lbl_08003fa8: .4byte 0x03001d00

    thumb_func_start sub_08003fac
sub_08003fac: @ 0x08003fac
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    ldr r1, lbl_08003fec @ =0x0808f2c0
    lsrs r0, r0, #0xd
    adds r0, r0, r1
    ldrb r2, [r0, #4]
    ldr r5, [r0]
    ldr r0, lbl_08003ff0 @ =0x0808cee2
    adds r0, r2, r0
    ldrb r0, [r0]
    ldr r6, lbl_08003ff4 @ =0x03003b44
    cmp r0, #0
    beq lbl_08003fe0
    lsls r0, r2, #3
    adds r3, r0, r6
    ldrb r1, [r3]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08003fe0
    ldrb r0, [r3, #1]
    ldrb r1, [r5, #2]
    cmp r0, r1
    bhi lbl_0800400e
lbl_08003fe0:
    cmp r4, #0
    bne lbl_08003ff8
    lsls r2, r2, #3
    adds r1, r2, r6
    movs r0, #1
    b lbl_08003ffe
    .align 2, 0
lbl_08003fec: .4byte 0x0808f2c0
lbl_08003ff0: .4byte 0x0808cee2
lbl_08003ff4: .4byte 0x03003b44
lbl_08003ff8:
    lsls r2, r2, #3
    adds r1, r2, r6
    movs r0, #2
lbl_08003ffe:
    strb r0, [r1]
    strh r4, [r1, #2]
    adds r1, r2, r6
    ldrb r0, [r5, #2]
    strb r0, [r1, #1]
    adds r0, r6, #4
    adds r0, r2, r0
    str r5, [r0]
lbl_0800400e:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start sub_08004014
sub_08004014: @ 0x08004014
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    ldr r1, lbl_08004048 @ =0x0808f2c0
    lsrs r0, r0, #0xd
    adds r0, r0, r1
    ldrb r2, [r0, #4]
    ldr r6, [r0]
    ldr r5, lbl_0800404c @ =0x03003b44
    lsls r3, r2, #3
    adds r4, r3, r5
    ldrb r1, [r4]
    movs r0, #3
    ands r0, r1
    cmp r0, #0
    beq lbl_08004050
    adds r0, r5, #4
    adds r0, r3, r0
    ldr r0, [r0]
    cmp r6, r0
    bne lbl_08004050
    movs r0, #0
    strb r0, [r4]
    b lbl_0800407c
    .align 2, 0
lbl_08004048: .4byte 0x0808f2c0
lbl_0800404c: .4byte 0x03003b44
lbl_08004050:
    ldr r0, lbl_08004070 @ =0x0808f254
    lsls r1, r2, #1
    adds r1, r1, r2
    lsls r1, r1, #2
    adds r1, r1, r0
    ldr r1, [r1]
    ldr r0, [r1, #0x10]
    cmp r6, r0
    bne lbl_0800407c
    cmp r7, #0
    bne lbl_08004074
    adds r0, r1, #0
    bl sub_08004c1c
    b lbl_0800407c
    .align 2, 0
lbl_08004070: .4byte 0x0808f254
lbl_08004074:
    adds r0, r1, #0
    adds r1, r7, #0
    bl sub_08002c94
lbl_0800407c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004084:
    .byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00

    thumb_func_start sub_0800408c
sub_0800408c: @ 0x0800408c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    movs r7, #0
    ldr r0, lbl_080040c4 @ =0x0808f254
    ldr r6, [r0, #0x18]
    ldrb r0, [r6, #0x1c]
    cmp r0, #0
    bne lbl_0800413a
    movs r2, #1
    strb r2, [r6, #0x1c]
    ldrb r1, [r6, #0x1e]
    adds r0, r2, #0
    ands r0, r1
    cmp r0, #0
    bne lbl_0800413a
    ldrb r1, [r6]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0800413a
    strb r2, [r6, #0x1e]
    movs r1, #0
    ldr r4, [r6, #0x18]
    b lbl_08004134
    .align 2, 0
lbl_080040c4: .4byte 0x0808f254
lbl_080040c8:
    adds r0, r4, #0
    adds r0, #0x34
    ldrb r2, [r0]
    movs r0, #0xc0
    ands r0, r2
    adds r1, #1
    mov r8, r1
    movs r1, #0x50
    adds r1, r1, r4
    mov sb, r1
    cmp r0, #0
    bne lbl_0800412c
    ldr r0, [r4, #0x4c]
    cmp r0, #0
    beq lbl_080040f4
    movs r1, #7
    ands r1, r2
    subs r1, #1
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl sub_080024c0
lbl_080040f4:
    ldr r0, [r4, #0x48]
    cmp r0, #0
    beq lbl_0800412c
    adds r4, r0, #0
    ldr r3, lbl_0800414c @ =0x030039bc
    movs r5, #0
lbl_08004100:
    lsls r0, r7, #3
    subs r0, r0, r7
    lsls r0, r0, #3
    adds r0, r0, r3
    stm r0!, {r4}
    adds r1, r4, #0
    movs r2, #0x34
    str r3, [sp]
    bl memcpy
    adds r0, r7, #1
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    strb r5, [r4]
    str r5, [r4, #0x28]
    ldr r0, [r4, #0x30]
    str r5, [r4, #0x30]
    str r5, [r4, #0x2c]
    adds r4, r0, #0
    ldr r3, [sp]
    cmp r4, #0
    bne lbl_08004100
lbl_0800412c:
    mov r1, r8
    lsls r0, r1, #0x18
    lsrs r1, r0, #0x18
    mov r4, sb
lbl_08004134:
    ldrb r0, [r6, #1]
    cmp r1, r0
    blo lbl_080040c8
lbl_0800413a:
    movs r0, #0
    strb r0, [r6, #0x1c]
    add sp, #4
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800414c: .4byte 0x030039bc

    thumb_func_start sub_08004150
sub_08004150: @ 0x08004150
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r6, #0
    ldr r0, lbl_080041e4 @ =0x0808f254
    ldr r5, [r0, #0x18]
    ldrb r0, [r5, #0x1c]
    cmp r0, #0
    bne lbl_080041d2
    movs r0, #1
    strb r0, [r5, #0x1c]
    ldrb r1, [r5, #0x1e]
    ands r0, r1
    cmp r0, #0
    beq lbl_080041d2
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r5, #0x1e]
    movs r3, #0
    ldr r2, [r5, #0x18]
    ldrb r0, [r5, #1]
    cmp r3, r0
    bhs lbl_080041d2
lbl_08004180:
    adds r0, r2, #0
    adds r0, #0x34
    ldrb r1, [r0]
    movs r0, #0xc0
    ands r0, r1
    adds r7, r3, #1
    movs r1, #0x50
    adds r1, r1, r2
    mov r8, r1
    cmp r0, #0
    bne lbl_080041c6
    ldr r0, [r2, #0x48]
    cmp r0, #0
    beq lbl_080041c6
    adds r4, r0, #0
    ldr r0, lbl_080041e8 @ =0x030039bc
    mov sb, r0
lbl_080041a2:
    adds r0, r4, #0
    bl sub_080020a4
    lsls r1, r6, #3
    subs r1, r1, r6
    lsls r1, r1, #3
    add r1, sb
    adds r1, #4
    adds r0, r4, #0
    movs r2, #0x34
    bl memcpy
    adds r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r4, [r4, #0x30]
    cmp r4, #0
    bne lbl_080041a2
lbl_080041c6:
    lsls r0, r7, #0x18
    lsrs r3, r0, #0x18
    mov r2, r8
    ldrb r1, [r5, #1]
    cmp r3, r1
    blo lbl_08004180
lbl_080041d2:
    movs r0, #0
    strb r0, [r5, #0x1c]
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080041e4: .4byte 0x0808f254
lbl_080041e8: .4byte 0x030039bc

    thumb_func_start sub_080041ec
sub_080041ec: @ 0x080041ec
    push {r4, lr}
    adds r3, r0, #0
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    ldrb r0, [r3, #0x1c]
    cmp r0, #0
    bne lbl_0800421e
    movs r0, #1
    strb r0, [r3, #0x1c]
    movs r1, #0
    ldr r2, [r3, #0x18]
    b lbl_08004218
lbl_08004204:
    ldrb r0, [r2]
    cmp r0, #0
    beq lbl_08004210
    ldrb r0, [r2, #2]
    adds r0, r0, r4
    strb r0, [r2, #2]
lbl_08004210:
    adds r0, r1, #1
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    adds r2, #0x50
lbl_08004218:
    ldrb r0, [r3, #1]
    cmp r1, r0
    blo lbl_08004204
lbl_0800421e:
    movs r0, #0
    strb r0, [r3, #0x1c]
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start sub_08004228
sub_08004228: @ 0x08004228
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r0, lbl_08004258 @ =0x03001d00
    ldrh r0, [r0, #0x1c]
    cmp r5, r0
    beq lbl_08004250
    ldr r0, lbl_0800425c @ =0x0808f254
    ldr r4, [r0]
    adds r0, r4, #0
    bl sub_08004c1c
    adds r0, r5, #0
    movs r1, #8
    bl sub_080039f4
    adds r0, r4, #0
    movs r1, #0x1e
    bl sub_080041ec
lbl_08004250:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004258: .4byte 0x03001d00
lbl_0800425c: .4byte 0x0808f254

    thumb_func_start sub_08004260
sub_08004260: @ 0x08004260
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    bl play_sound1
    ldr r0, lbl_08004278 @ =0x0808f254
    ldr r0, [r0]
    movs r1, #0x1e
    bl sub_080041ec
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004278: .4byte 0x0808f254

    thumb_func_start sub_0800427c
sub_0800427c: @ 0x0800427c
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r0, lbl_080042a4 @ =0x0808f254
    ldr r2, [r0]
    ldr r0, lbl_080042a8 @ =0x0808f2c0
    ldr r3, [r0, #0x48]
    ldrb r1, [r2]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_080042ac
    ldr r0, [r2, #0x10]
    cmp r3, r0
    bne lbl_080042ac
    movs r0, #2
    bl sub_08003e60
    b lbl_080042b6
    .align 2, 0
lbl_080042a4: .4byte 0x0808f254
lbl_080042a8: .4byte 0x0808f2c0
lbl_080042ac:
    adds r0, r4, #0
    movs r1, #9
    movs r2, #2
    bl sub_08003b30
lbl_080042b6:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start sub_080042bc
sub_080042bc: @ 0x080042bc
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r4, lbl_08004300 @ =0x03001d00
    ldrb r6, [r4, #1]
    cmp r6, #0
    bne lbl_080042f8
    movs r0, #1
    strb r0, [r4, #1]
    adds r2, r4, #0
    adds r2, #0x21
    ldrb r1, [r2]
    movs r0, #0x80
    ands r0, r1
    strb r0, [r2]
    cmp r5, #0
    bne lbl_080042e0
    ldr r5, lbl_08004304 @ =0x0000012b
lbl_080042e0:
    ldr r0, lbl_08004308 @ =0x0808f254
    ldr r0, [r0]
    ldr r2, lbl_0800430c @ =0x0808f2c0
    lsls r1, r5, #3
    adds r1, r1, r2
    ldr r1, [r1]
    bl sub_08004b50
    adds r0, r4, #0
    adds r0, #0x20
    strb r6, [r0]
    strh r5, [r4, #0x1c]
lbl_080042f8:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004300: .4byte 0x03001d00
lbl_08004304: .4byte 0x0000012b
lbl_08004308: .4byte 0x0808f254
lbl_0800430c: .4byte 0x0808f2c0

    thumb_func_start call_soundcode_b
call_soundcode_b: @ 0x08004310
    push {r4, r5, r6, r7}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7, lr}
    add r4, pc, #0x0
    bx r4

    thumb_func_start soundcode_b
soundcode_b: @ 0x08004320
    lsls r0, r1
    b lbl_08003e64
lbl_08004324:
    .byte 0x04, 0xC0, 0xD4, 0xE5, 0x06, 0xEC, 0xA0, 0xE3, 0x01, 0x00, 0x00, 0xEA
    .byte 0x01, 0x30, 0x53, 0xE2, 0x19, 0x00, 0x00, 0x0A, 0xDE, 0x60, 0x90, 0xE1, 0xDE, 0x70, 0x91, 0xE1
    .byte 0xD1, 0x40, 0xD0, 0xE0, 0xD1, 0x50, 0xD1, 0xE0, 0xDE, 0xA0, 0x90, 0xE1, 0xDE, 0xB0, 0x91, 0xE1
    .byte 0xD1, 0x80, 0xD0, 0xE0, 0xD1, 0x90, 0xD1, 0xE0, 0x04, 0x60, 0x86, 0xE0, 0x05, 0x60, 0x86, 0xE0
    .byte 0x07, 0x60, 0x86, 0xE0, 0x09, 0x80, 0x88, 0xE0, 0x0A, 0x80, 0x88, 0xE0, 0x0B, 0x80, 0x88, 0xE0
    .byte 0x9C, 0x06, 0x06, 0xE0, 0x9C, 0x08, 0x08, 0xE0, 0xC6, 0x64, 0xB0, 0xE1, 0x01, 0x60, 0x86, 0x42
    .byte 0xC8, 0x84, 0xB0, 0xE1, 0x01, 0x80, 0x88, 0x42, 0x86, 0x63, 0xA0, 0xE1, 0x88, 0x83, 0xA0, 0xE1
    .byte 0x06, 0x70, 0xA0, 0xE1, 0x08, 0x90, 0xA0, 0xE1, 0xC0, 0x03, 0xA2, 0xE8, 0xE3, 0xFF, 0xFF, 0xEA
    .byte 0x02, 0x00, 0xA0, 0xE1, 0x00, 0x4F, 0xBD, 0xE8, 0xF0, 0x00, 0xBD, 0xE8, 0x1E, 0xFF, 0x2F, 0xE1
    .byte 0x00, 0x1D, 0x00, 0x03

    thumb_func_start call_soundcode_c
call_soundcode_c: @ 0x080043b4
    push {r4, r5, r6, r7}
    mov r4, r8
    mov r5, sb
    mov r6, sl
    mov r7, fp
    push {r4, r5, r6, r7, lr}
    add r4, pc, #0x0
    bx r4

    thumb_func_start soundcode_c
soundcode_c: @ 0x080043c4
    subs r4, #6
    b sub_08004b0a
lbl_080043c8:
    .byte 0x03, 0x30, 0x80, 0xE0, 0x00, 0xC0, 0xA0, 0xE3
    .byte 0x01, 0xC0, 0x4C, 0xE2, 0xAC, 0xCB, 0xA0, 0xE1, 0x80, 0xE0, 0x9F, 0xE5, 0x01, 0x00, 0x00, 0xEA
    .byte 0x01, 0x20, 0x52, 0xE2, 0x19, 0x00, 0x00, 0x0A, 0xF0, 0x0F, 0xB1, 0xE8, 0xA4, 0x43, 0x0C, 0xE0
    .byte 0xA5, 0x53, 0x0C, 0xE0, 0xA6, 0x63, 0x0C, 0xE0, 0xA7, 0x73, 0x0C, 0xE0, 0xA8, 0x83, 0x0C, 0xE0
    .byte 0xA9, 0x93, 0x0C, 0xE0, 0xAA, 0xA3, 0x0C, 0xE0, 0xAB, 0xB3, 0x0C, 0xE0, 0x04, 0x40, 0xDE, 0xE7
    .byte 0x05, 0x50, 0xDE, 0xE7, 0x06, 0x60, 0xDE, 0xE7, 0x07, 0x70, 0xDE, 0xE7, 0x08, 0x80, 0xDE, 0xE7
    .byte 0x09, 0x90, 0xDE, 0xE7, 0x0A, 0xA0, 0xDE, 0xE7, 0x0B, 0xB0, 0xDE, 0xE7, 0x06, 0x44, 0x84, 0xE1
    .byte 0x08, 0x48, 0x84, 0xE1, 0x0A, 0x4C, 0x84, 0xE1, 0x04, 0x40, 0x80, 0xE4, 0x07, 0x54, 0x85, 0xE1
    .byte 0x09, 0x58, 0x85, 0xE1, 0x0B, 0x5C, 0x85, 0xE1, 0x04, 0x50, 0x83, 0xE4, 0xE3, 0xFF, 0xFF, 0xEA
    .byte 0x01, 0x00, 0xA0, 0xE1, 0x00, 0x4F, 0xBD, 0xE8, 0xF0, 0x00, 0xBD, 0xE8, 0x1E, 0xFF, 0x2F, 0xE1
    .byte 0xE2, 0xCC, 0x08, 0x08

    thumb_func_start call_soundcode_a
call_soundcode_a: @ 0x08004464
    push {r4, r5, r6, r7}
    mov r3, r8
    mov r4, sb
    mov r5, sl
    mov r6, fp
    push {r3, r4, r5, r6, lr}
    add r4, pc, #0x0
    bx r4

    thumb_func_start soundcode_a
soundcode_a: @ 0x08004474
    stm r0!, {r3, r4}
    b lbl_08003f9a
lbl_08004478:
    .byte 0x11, 0xB0, 0xD0, 0xE5, 0x12, 0xA0, 0xD0, 0xE5
    .byte 0x24, 0x90, 0x90, 0xE5, 0x20, 0x30, 0x90, 0xE5, 0x0C, 0x80, 0x93, 0xE5, 0x01, 0x40, 0xD0, 0xE5
    .byte 0x20, 0x00, 0x54, 0xE3, 0x09, 0x01, 0x00, 0x0A, 0x08, 0x00, 0x54, 0xE3, 0xBC, 0x00, 0x00, 0x0A
    .byte 0x00, 0x70, 0xA0, 0xE3, 0x01, 0x70, 0x47, 0xE2, 0x27, 0x79, 0xA0, 0xE1, 0x1C, 0x60, 0x90, 0xE5
    .byte 0x01, 0x00, 0x2D, 0xE9, 0xB2, 0x00, 0xD3, 0xE1, 0x08, 0xE0, 0x93, 0xE5, 0x08, 0xE0, 0x4E, 0xE0
    .byte 0x01, 0x00, 0x00, 0xEA, 0x01, 0x20, 0x52, 0xE2, 0x76, 0x01, 0x00, 0x0A, 0x06, 0x41, 0x8C, 0xE0
    .byte 0x24, 0x47, 0x58, 0xE0, 0x7D, 0x00, 0x00, 0xCA, 0x2C, 0x57, 0xA0, 0xE1, 0x00, 0x00, 0x10, 0xE0
    .byte 0x34, 0x00, 0x00, 0x1A, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0x08, 0x00, 0x55, 0xE1, 0x5E, 0x01, 0x00, 0xAA, 0xD9, 0x30, 0xB5, 0xE1
    .byte 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0
    .byte 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0
    .byte 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0x08, 0x00, 0x55, 0xE1
    .byte 0x50, 0x01, 0x00, 0xAA, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0x08, 0x00, 0x55, 0xE1, 0x42, 0x01, 0x00, 0xAA, 0xD9, 0x30, 0xB5, 0xE1
    .byte 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0
    .byte 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0
    .byte 0x30, 0x00, 0xA1, 0xE8, 0x37, 0x01, 0x00, 0xEA, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0x08, 0x00, 0x55, 0xE1, 0x03, 0x00, 0x00, 0xBA
    .byte 0x07, 0x30, 0x0C, 0xE0, 0x0E, 0x50, 0x85, 0xE0, 0x05, 0xC7, 0x83, 0xE0, 0x3F, 0x00, 0x00, 0xEA
    .byte 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0
    .byte 0x95, 0x04, 0x04, 0xE0
lbl_08004614:
    adds r7, #0x24
    b lbl_08004720
lbl_08004618:
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1
    .byte 0x08, 0x00, 0x55, 0xE1, 0x03, 0x00, 0x00, 0xBA, 0x07, 0x30, 0x0C, 0xE0, 0x0E, 0x50, 0x85, 0xE0
    .byte 0x05, 0xC7, 0x83, 0xE0, 0x39, 0x00, 0x00, 0xEA, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0x08, 0x00, 0x55, 0xE1, 0x03, 0x00, 0x00, 0xBA
    .byte 0x07, 0x30, 0x0C, 0xE0, 0x0E, 0x50, 0x85, 0xE0, 0x05, 0xC7, 0x83, 0xE0, 0x33, 0x00, 0x00, 0xEA
    .byte 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0
    .byte 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1
    .byte 0x07, 0x30, 0x0C, 0xE0, 0x0E, 0x50, 0x85, 0xE0, 0x05, 0xC7, 0x83, 0xE0, 0x7C, 0xFF, 0xFF, 0xEA
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
lbl_08004720:
    ldr r3, lbl_08004970 @ =0xe1b530d9
    b lbl_0800476e
lbl_08004724:
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40
lbl_0800476e:
    b lbl_080047fa
lbl_08004770:
    .byte 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0
    .byte 0x4B, 0xFF, 0xFF, 0xEA, 0x01, 0x00, 0x2D, 0xE9, 0xB2, 0x70, 0xD3, 0xE1, 0x08, 0x60, 0x93, 0xE5
    .byte 0x01, 0x00, 0x00, 0xEA, 0x01, 0x20, 0x52, 0xE2, 0xBE, 0x00, 0x00, 0x0A, 0x04, 0x40, 0x8C, 0xE2
    .byte 0x08, 0x00, 0x54, 0xE1, 0x2C, 0x00, 0x00, 0xBA, 0xDC, 0x30, 0x99, 0xE1, 0x30, 0x00, 0x91, 0xE8
    .byte 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x01, 0xC0, 0x8C, 0xE2
    .byte 0x08, 0x00, 0x5C, 0xE1, 0x02, 0x00, 0x00, 0x1A, 0x07, 0x70, 0x17, 0xE0, 0xAD, 0x00, 0x00, 0x0A
    .byte 0x06, 0xC0, 0xA0, 0xE1, 0xDC, 0x30, 0x99, 0xE1, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x01, 0xC0
lbl_080047fa:
    b lbl_08004d16
lbl_080047fc:
    .byte 0x08, 0x00, 0x5C, 0xE1
    .byte 0x02, 0x00, 0x00, 0x1A, 0x07, 0x70, 0x17, 0xE0, 0xA2, 0x00, 0x00, 0x0A, 0x06, 0xC0, 0xA0, 0xE1
    .byte 0xDC, 0x30, 0x99, 0xE1, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0
    .byte 0x30, 0x00, 0xA1, 0xE8, 0x01, 0xC0, 0x8C, 0xE2, 0x08, 0x00, 0x5C, 0xE1, 0x02, 0x00, 0x00, 0x1A
    .byte 0x07, 0x70, 0x17, 0xE0, 0x97, 0x00, 0x00, 0x0A, 0x06, 0xC0, 0xA0, 0xE1, 0xDC, 0x30, 0x99, 0xE1
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x01, 0xC0, 0x8C, 0xE2, 0x08, 0x00, 0x5C, 0xE1, 0xD1, 0xFF, 0xFF, 0x1A, 0x07, 0x70, 0x17, 0xE0
    .byte 0x8C, 0x00, 0x00, 0x0A, 0x06, 0xC0, 0xA0, 0xE1, 0xCD, 0xFF, 0xFF, 0xEA, 0x38, 0x40, 0x91, 0xE8
    .byte 0xDC, 0x00, 0x99, 0xE1, 0x90, 0x3B, 0x23, 0xE0, 0x90, 0x4A, 0x24, 0xE0, 0x01, 0xC0, 0x8C, 0xE2
    .byte 0xDC, 0x00, 0x99, 0xE1, 0x90, 0x5B, 0x25, 0xE0, 0x90, 0xEA, 0x2E, 0xE0, 0x01, 0xC0, 0x8C, 0xE2
    .byte 0x38, 0x40, 0xA1, 0xE8, 0x38, 0x40, 0x91, 0xE8, 0xDC, 0x00, 0x99, 0xE1, 0x90, 0x3B, 0x23, 0xE0
    .byte 0x90, 0x4A, 0x24, 0xE0, 0x01, 0xC0, 0x8C, 0xE2, 0xDC, 0x00, 0x99, 0xE1, 0x90, 0x5B, 0x25, 0xE0
    .byte 0x90, 0xEA, 0x2E, 0xE0, 0x01, 0xC0, 0x8C, 0xE2, 0x38, 0x40, 0xA1, 0xE8, 0xB8, 0xFF, 0xFF, 0xEA
    .byte 0x00, 0x70, 0xA0, 0xE3, 0x01, 0x70, 0x47, 0xE2, 0x07, 0x40, 0xA0, 0xE1, 0x27, 0x79, 0xA0, 0xE1
    .byte 0x1C, 0x60, 0x90, 0xE5, 0x04, 0x60, 0x26, 0xE0, 0x01, 0x60, 0x86, 0xE2, 0x01, 0x00, 0x2D, 0xE9
    .byte 0xB2, 0x00, 0xD3, 0xE1, 0x01, 0x00, 0x00, 0xEA, 0x01, 0x20, 0x52, 0xE2, 0x6D, 0x00, 0x00, 0x0A
    .byte 0x06, 0x41, 0x8C, 0xE0, 0x44, 0x47, 0xB0, 0xE1, 0x35, 0x00, 0x00, 0xCA, 0x2C, 0x57, 0xA0, 0xE1
    .byte 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0
    .byte 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1
    .byte 0x00, 0x00, 0x55, 0xE3, 0x57, 0x00, 0x00, 0xDA, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0x00, 0x00, 0x55, 0xE3, 0x49, 0x00, 0x00, 0xDA
lbl_08004970: .4byte 0xe1b530d9
lbl_08004974:
    .byte 0xD1, 0x40, 0xD5, 0xE1, 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0
    .byte 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0, 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0
    .byte 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8, 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1
    .byte 0x00, 0x00, 0x55, 0xE3, 0x3B, 0x00, 0x00, 0xDA, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x30, 0x00, 0x00, 0xEA, 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x2C, 0x57, 0xA0, 0xE1, 0xD9, 0x30, 0xB5, 0xE1, 0xD1, 0x40, 0xD5, 0xE1
    .byte 0x03, 0x40, 0x44, 0xE0, 0x07, 0x50, 0x0C, 0xE0, 0x95, 0x04, 0x04, 0xE0, 0x24, 0x37, 0x83, 0xE0
    .byte 0x30, 0x00, 0x91, 0xE8, 0x93, 0x4B, 0x24, 0xE0, 0x93, 0x5A, 0x25, 0xE0, 0x30, 0x00, 0xA1, 0xE8
    .byte 0x06, 0xC0, 0x8C, 0xE0, 0x93, 0xFF, 0xFF, 0xEA, 0x01, 0x00, 0xBD, 0xE8, 0x00, 0x40, 0xA0, 0xE3
    .byte 0x00, 0x40, 0xC0, 0xE5, 0x01, 0x00, 0x00, 0xEA, 0x01, 0x00, 0xBD, 0xE8, 0x18, 0xC0, 0x80, 0xE5
    .byte 0x00, 0x4F, 0xBD, 0xE8, 0xF0, 0x00, 0xBD, 0xE8, 0x1E, 0xFF, 0x2F, 0xE1

    thumb_func_start sub_08004abc
sub_08004abc: @ 0x08004abc
    add r2, pc, #0x0 @ =sub_08004ac0
    bx r2

    arm_func_start sub_08004ac0
sub_08004ac0: @ 0x08004ac0
    umull r2, r3, r0, r1
    lsr r2, r2, #0x12
    lsl r3, r3, #0xe
    add r3, r3, r2
    add r0, r3, #0
    bx lr

    thumb_func_start sub_08004ad8
sub_08004ad8: @ 0x08004ad8
    add r0, pc, #0x0 @ =sub_08004adc
    bx r0

    arm_func_start sub_08004adc
sub_08004adc: @ 0x08004adc
    ldr r0, lbl_08004b44 @ =0x03001d00
    ldrb r1, [r0, #0x10]
    add r1, r1, #1
    ldrb r3, [r0, #0xe]
    cmp r1, r3
    bne sub_08004b3c
    ldr r3, lbl_08004b48 @ =0x0808ceec
    ldr r3, [r3]
    ldr ip, lbl_08004b4c @ =0x0808cef0
    ldr ip, [ip]
    str ip, [r3]
lbl_08004b08:
    .byte 0x0C, 0xC0

    non_word_aligned_thumb_func_start sub_08004b0a
sub_08004b0a: @ 0x08004b0a
    b lbl_08004614
lbl_08004b0c:
    .byte 0x00, 0x00, 0xA0, 0xE1
    .byte 0x50, 0xC0, 0xA0, 0xE3, 0x0C, 0xC2, 0xA0, 0xE1, 0xB2, 0xC0, 0xC3, 0xE1, 0xBE, 0xC0, 0xC3, 0xE1
    .byte 0xB6, 0xC0, 0xA0, 0xE3, 0x0C, 0xC4, 0xA0, 0xE1, 0xB2, 0xC0, 0xC3, 0xE1, 0xF6, 0xC0, 0xA0, 0xE3
    .byte 0x0C, 0xC4, 0xA0, 0xE1, 0xBE, 0xC0, 0xC3, 0xE1, 0x00, 0x10, 0xA0, 0xE3

    arm_func_start sub_08004b3c
sub_08004b3c: @ 0x08004b3c
    strb r1, [r0, #0x10]
    bx lr
    .align 2, 0
lbl_08004b44: .4byte 0x03001d00
lbl_08004b48: .4byte 0x0808ceec
lbl_08004b4c: .4byte 0x0808cef0

    thumb_func_start sub_08004b50
sub_08004b50: @ 0x08004b50
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    adds r4, r0, #0
    adds r5, r1, #0
    ldrb r6, [r4, #0x1c]
    cmp r6, #0
    bne lbl_08004c04
    movs r6, #1
    strb r6, [r4, #0x1c]
    ldrb r6, [r4, #0x1e]
    movs r7, #1
    ands r6, r7
    bne lbl_08004c00
    ldr r6, [r5]
    lsls r2, r6, #0x18
    lsrs r2, r2, #0x18
    bne lbl_08004b7c
    bl sub_08004c94
    movs r2, #0
    strb r2, [r4]
    b lbl_08004c00
lbl_08004b7c:
    ldr r7, [r4]
    movs r3, #2
    lsls r2, r7, #0x18
    lsrs r2, r2, #0x18
    ands r3, r2
    beq lbl_08004ba2
    movs r3, #0x1d
    ldrb r3, [r4, r3]
    cmp r3, #0
    beq lbl_08004b9c
    lsls r1, r6, #8
    lsrs r1, r1, #0x18
    lsrs r2, r7, #0x18
    cmp r2, r1
    ble lbl_08004b9c
    b lbl_08004c0e
lbl_08004b9c:
    adds r0, r4, #0
    bl sub_08004c94
lbl_08004ba2:
    movs r3, #2
    lsls r2, r6, #8
    orrs r2, r3
    ldr r0, [r5, #4]
    str r2, [r4]
    str r0, [r4, #0x14]
    str r5, [r4, #0x10]
    lsls r3, r3, #7
    strh r3, [r4, #0xc]
    lsrs r2, r6, #0x1f
    beq lbl_08004bbe
    lsrs r0, r6, #0x18
    bl sub_080027f8
lbl_08004bbe:
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    ldr r7, [r4, #0x18]
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r7, #0
    movs r3, #0x50
    muls r3, r6, r3
    bl bit_fill
    movs r0, #1
    movs r2, #0x40
    lsls r1, r2, #0x10
    lsls r2, r2, #8
    orrs r1, r2
    movs r3, #0xc
    lsls r3, r3, #8
    movs r2, #2
    orrs r2, r3
    adds r5, #8
    b lbl_08004bf4
lbl_08004bec:
    subs r6, #1
    beq lbl_08004c00
    adds r7, #0x50
    adds r5, #4
lbl_08004bf4:
    ldr r3, [r5]
    strb r0, [r7]
    strh r2, [r7, #0x1a]
    str r1, [r7, #4]
    str r3, [r7, #0x24]
    b lbl_08004bec
lbl_08004c00:
    movs r6, #0
    strb r6, [r4, #0x1c]
lbl_08004c04:
    movs r0, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
lbl_08004c0e:
    movs r6, #0
    strb r6, [r4, #0x1c]
    movs r0, #1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_08004c1c
sub_08004c1c: @ 0x08004c1c
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, #0x1c]
    cmp r6, #0
    bne lbl_08004c8c
    movs r6, #1
    strb r6, [r7, #0x1c]
    ldrb r6, [r7, #0x1e]
    movs r5, #1
    ands r5, r6
    bne lbl_08004c88
    ldrb r4, [r7]
    movs r5, #2
    ands r4, r5
    beq lbl_08004c88
    movs r4, #1
    strb r4, [r7]
    movs r4, #0
    strb r4, [r7, #4]
    ldrb r6, [r7, #1]
    ldr r5, [r7, #0x18]
    b lbl_08004c4e
lbl_08004c48:
    subs r6, #1
    beq lbl_08004c88
    adds r5, #0x50
lbl_08004c4e:
    ldr r4, [r5, #0x4c]
    cmp r4, #0
    beq lbl_08004c6a
    movs r3, #7
    movs r2, #0x34
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl sub_080024c0
    movs r3, #0
    strb r3, [r4]
    str r3, [r4, #0x24]
lbl_08004c6a:
    ldr r0, [r5, #0x48]
    movs r1, #0
lbl_08004c6e:
    cmp r0, #0
    beq lbl_08004c80
    ldr r2, [r0, #0x30]
    strb r1, [r0]
    str r1, [r0, #0x28]
    str r1, [r0, #0x30]
    str r1, [r0, #0x2c]
    adds r0, r2, #0
    b lbl_08004c6e
lbl_08004c80:
    movs r0, #0
    str r0, [r5, #0x4c]
    str r0, [r5, #0x48]
    b lbl_08004c48
lbl_08004c88:
    movs r6, #0
    strb r6, [r7, #0x1c]
lbl_08004c8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08004c94
sub_08004c94: @ 0x08004c94
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, #0x1e]
    movs r5, #1
    ands r5, r6
    bne lbl_08004cf6
    ldrb r4, [r7]
    movs r5, #2
    ands r4, r5
    beq lbl_08004cf6
    movs r4, #1
    strb r4, [r7]
    movs r4, #0
    strb r4, [r7, #4]
    ldrb r6, [r7, #1]
    ldr r5, [r7, #0x18]
    b lbl_08004cbc
lbl_08004cb6:
    subs r6, #1
    beq lbl_08004cf6
    adds r5, #0x50
lbl_08004cbc:
    ldr r4, [r5, #0x4c]
    cmp r4, #0
    beq lbl_08004cd8
    movs r3, #7
    movs r2, #0x34
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl sub_080024c0
    movs r3, #0
    strb r3, [r4]
    str r3, [r4, #0x24]
lbl_08004cd8:
    ldr r0, [r5, #0x48]
    movs r1, #0
lbl_08004cdc:
    cmp r0, #0
    beq lbl_08004cee
    ldr r2, [r0, #0x30]
    strb r1, [r0]
    str r1, [r0, #0x28]
    str r1, [r0, #0x30]
    str r1, [r0, #0x2c]
    adds r0, r2, #0
    b lbl_08004cdc
lbl_08004cee:
    movs r0, #0
    str r0, [r5, #0x4c]
    str r0, [r5, #0x48]
    b lbl_08004cb6
lbl_08004cf6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_08004cfc
sub_08004cfc: @ 0x08004cfc
    adds r3, r0, #0
    ldr r0, [r3, #0xc]
    lsls r1, r0, #0x10
    adds r1, r0, r1
    lsrs r1, r1, #0x10
    movs r2, #0xff
    lsls r0, r2, #8
    ands r0, r1
    beq lbl_08004d14
    lsrs r0, r1, #8
    ands r1, r2
    b lbl_08004d16
lbl_08004d14:
    movs r0, #0
lbl_08004d16:
    strh r1, [r3, #0xe]
    bx lr
    .align 2, 0

    thumb_func_start sub_08004d1c
sub_08004d1c: @ 0x08004d1c
    ldr r2, [r1, #0x24]
    ldrb r3, [r2, #1]
    adds r2, #2
    str r2, [r1, #0x24]
    lsls r2, r3, #1
    strh r2, [r0, #0xa]
    cmp r2, #0x96
    beq lbl_08004d3c
    movs r1, #0x1b
    movs r3, #0x4e
    lsls r1, r1, #8
    orrs r1, r3
    lsls r2, r2, #8
    muls r1, r2, r1
    lsrs r1, r1, #0x14
    b lbl_08004d40
lbl_08004d3c:
    movs r1, #1
    lsls r1, r1, #8
lbl_08004d40:
    movs r3, #0
    strh r1, [r0, #0xc]
    strh r3, [r0, #0xe]
    bx lr

    thumb_func_start sub_08004d48
sub_08004d48: @ 0x08004d48
    push {r4, r5, r6, lr}
    ldr r4, lbl_08004df4 @ =0x0808f254
    ldr r5, lbl_08004df8 @ =0x00000009
    ldr r6, lbl_08004dfc @ =0x03003b44
    b lbl_08004d5c
lbl_08004d52:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004d72
    adds r4, #0xc
    adds r6, #8
lbl_08004d5c:
    ldrb r3, [r6]
    cmp r3, #0
    beq lbl_08004d52
    ldr r0, [r4]
    ldr r1, [r6, #4]
    bl sub_08004b50
    movs r0, #0
    str r0, [r6]
    str r0, [r6, #4]
    b lbl_08004d52
lbl_08004d72:
    ldr r4, lbl_08004e00 @ =0x0808f254
    ldr r6, lbl_08004e04 @ =0x03001d00
    movs r0, #0x21
    ldrb r0, [r6, r0]
    movs r1, #0x80
    ands r1, r0
    beq lbl_08004d92
    movs r1, #0x7f
    ands r0, r1
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dd8
    adds r4, #0xc
    ldr r5, lbl_08004e08 @ =0x00000009
    subs r5, #1
    b lbl_08004da8
lbl_08004d92:
    movs r0, #0x21
    ldrb r0, [r6, r0]
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dbc
    ldr r5, lbl_08004e0c @ =0x00000009
    b lbl_08004da8
lbl_08004da0:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004dd8
    adds r4, #0xc
lbl_08004da8:
    ldr r0, [r4]
    cmp r0, #0
    beq lbl_08004da0
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004da0
    bl sub_08001850
    b lbl_08004da0
lbl_08004dbc:
    movs r0, #0x20
    ldrb r0, [r6, r0]
    movs r1, #0
    cmp r0, r1
    beq lbl_08004dc8
    movs r1, #0xc
lbl_08004dc8:
    adds r4, r4, r1
    ldr r0, [r4]
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004dd8
    bl sub_08001850
lbl_08004dd8:
    ldrb r5, [r6, #1]
    cmp r5, #0
    bne lbl_08004dea
    movs r5, #1
    strb r5, [r6, #1]
    bl sub_08001458
    bl sub_080010c4
lbl_08004dea:
    movs r0, #0
    strb r0, [r6, #1]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004df4: .4byte 0x0808f254
lbl_08004df8: .4byte 0x00000009
lbl_08004dfc: .4byte 0x03003b44
lbl_08004e00: .4byte 0x0808f254
lbl_08004e04: .4byte 0x03001d00
lbl_08004e08: .4byte 0x00000009
lbl_08004e0c: .4byte 0x00000009

    thumb_func_start sub_08004e10
sub_08004e10: @ 0x08004e10
    push {r4, r5, lr}
    ldr r1, [r0, #0x40]
    ldrb r2, [r0, #1]
    ldrb r3, [r0]
    movs r4, #0xf0
    ands r3, r4
    cmp r3, #0x80
    bne lbl_08004e40
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
    ldrb r2, [r1, #1]
    movs r3, #0x35
    strb r2, [r0, r3]
    ldrb r2, [r1, #3]
    cmp r2, #0
    bne lbl_08004e38
    movs r2, #0x40
    strb r2, [r0, #6]
    b lbl_08004e4c
lbl_08004e38:
    subs r2, #0x80
    bmi lbl_08004e4c
    strb r2, [r0, #6]
    b lbl_08004e4c
lbl_08004e40:
    ldr r3, [r0, #0x44]
    adds r3, r3, r2
    ldrb r3, [r3]
    movs r4, #0xc
    muls r3, r4, r3
    adds r1, r1, r3
lbl_08004e4c:
    ldr r2, [r1]
    lsls r3, r2, #0x18
    lsrs r3, r3, #0x18
    movs r4, #0x34
    strb r3, [r0, r4]
    lsls r4, r2, #8
    lsrs r4, r4, #0x18
    movs r5, #0x36
    strb r4, [r0, r5]
    movs r4, #7
    ands r3, r4
    bne lbl_08004e6a
    ldr r3, [r1, #4]
    str r3, [r0, #0x38]
    b lbl_08004eaa
lbl_08004e6a:
    cmp r3, #2
    bgt lbl_08004e88
    lsrs r3, r2, #0x18
    movs r4, #0x80
    ands r4, r3
    bne lbl_08004e7e
    movs r4, #0x70
    ands r4, r3
    beq lbl_08004e7e
    b lbl_08004e80
lbl_08004e7e:
    movs r3, #8
lbl_08004e80:
    movs r4, #0x37
    strb r3, [r0, r4]
    movs r4, #6
    b lbl_08004ea2
lbl_08004e88:
    cmp r3, #3
    bne lbl_08004e9c
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [r5, #4]
    bl sub_080050d0
    adds r0, r4, #0
    adds r1, r5, #0
    b lbl_08004eaa
lbl_08004e9c:
    cmp r3, #4
    bne lbl_08004eaa
    movs r4, #3
lbl_08004ea2:
    ldr r3, [r1, #4]
    lsls r3, r4
    movs r4, #0x38
    strb r3, [r0, r4]
lbl_08004eaa:
    ldr r2, [r1, #8]
    str r2, [r0, #0x3c]
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start sub_08004eb4
sub_08004eb4: @ 0x08004eb4
    movs r1, #0x19
    ldrsb r1, [r0, r1]
    cmp r1, #0
    ble lbl_08004ebe
    adds r1, #1
lbl_08004ebe:
    ldr r2, [r0, #0x1c]
    ldrb r3, [r0, #0x1a]
    muls r1, r3, r1
    lsls r1, r1, #2
    lsls r3, r2, #0x18
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #0x10
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #8
    asrs r3, r3, #0x16
    lsls r3, r3, #2
    adds r1, r1, r3
    lsrs r2, r2, #0x18
    adds r1, r1, r2
    movs r3, #0x10
    ldr r2, [r0, r3]
    movs r3, #0xff
    ands r3, r2
    beq lbl_08004f06
    movs r3, #0xff
    lsls r3, r3, #8
    ands r3, r2
    beq lbl_08004f06
    lsls r3, r2, #8
    lsrs r3, r3, #0x18
    cmp r3, #0
    bne lbl_08004f06
    asrs r2, r2, #0x18
    lsls r2, r2, #2
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
lbl_08004f06:
    asrs r2, r1, #8
    strb r2, [r0, #0x17]
    strb r1, [r0, #0x18]
    bx lr
    .align 2, 0

    thumb_func_start sub_08004f10
sub_08004f10: @ 0x08004f10
    push {r4}
    ldr r1, [r0, #4]
    lsls r2, r1, #0x18
    lsrs r2, r2, #0x18
    lsls r3, r1, #0x10
    lsrs r3, r3, #0x18
    muls r2, r3, r2
    lsrs r2, r2, #5
    ldrh r3, [r0, #0x12]
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #1
    bne lbl_08004f3a
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r4, #0x41
    muls r2, r4, r2
    asrs r2, r2, #6
    cmp r2, #0xff
    blt lbl_08004f3a
    movs r2, #0xff
lbl_08004f3a:
    lsls r4, r1, #8
    lsrs r4, r4, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r4
    subs r1, #0x40
    cmp r1, #0x3f
    blt lbl_08004f4c
    movs r1, #0x3f
    b lbl_08004f56
lbl_08004f4c:
    movs r4, #0x40
    rsbs r4, r4, #0
    cmp r1, r4
    bpl lbl_08004f56
    rsbs r1, r4, #0
lbl_08004f56:
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #2
    bne lbl_08004f74
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r1, r1, r4
    cmp r1, #0x3f
    blt lbl_08004f6c
    movs r1, #0x3f
    b lbl_08004f74
lbl_08004f6c:
    movs r4, #0x40
    adds r3, r1, r4
    bpl lbl_08004f74
    rsbs r1, r4, #0
lbl_08004f74:
    movs r4, #0x40
    adds r3, r1, r4
    muls r3, r2, r3
    lsrs r3, r3, #7
    subs r4, r4, r1
    muls r4, r2, r4
    lsrs r4, r4, #7
    lsls r4, r4, #8
    orrs r3, r4
    strh r3, [r0, #8]
    pop {r4}
    bx lr

    thumb_func_start sub_08004f8c
sub_08004f8c: @ 0x08004f8c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldrb r1, [r4, #0x13]
    movs r2, #2
    orrs r1, r2
    strb r1, [r4, #0x13]
    bl sub_080020a4
    ldr r0, [r5, #0x48]
    cmp r0, #0
    beq lbl_08004fa8
    str r4, [r0, #0x2c]
lbl_08004fa8:
    str r0, [r4, #0x30]
    movs r1, #0
    str r1, [r4, #0x2c]
    str r5, [r4, #0x28]
    str r4, [r5, #0x48]
    movs r1, #0x34
    ldrb r0, [r5, r1]
    ldrb r1, [r5, #6]
    lsls r0, r0, #8
    lsls r6, r6, #0x10
    lsls r1, r1, #0x18
    movs r2, #1
    orrs r0, r1
    orrs r0, r2
    orrs r0, r6
    str r0, [r4]
    ldr r0, [r5, #0x3c]
    str r0, [r4, #8]
    ldr r0, [r5, #0xc]
    str r0, [r4, #0xc]
    movs r1, #0x10
    movs r2, #0xc
    ldr r0, [r5, #0x38]
    adds r1, r1, r0
    adds r2, r2, r0
    str r0, [r4, #0x20]
    str r1, [r4, #0x24]
    str r2, [r4, #0x14]
    ldrh r1, [r5]
    lsrs r2, r1, #8
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    strb r2, [r4, #6]
    movs r3, #0xf0
    ands r1, r3
    cmp r1, #0x80
    bne lbl_08004ff6
    movs r3, #0x35
    ldrb r2, [r5, r3]
lbl_08004ff6:
    strb r2, [r4, #7]
    movs r3, #0x17
    ldrsb r1, [r5, r3]
    adds r1, r1, r2
    bmi lbl_08005008
    cmp r1, #0x7f
    ble lbl_0800500a
    movs r1, #0x7f
    b lbl_0800500a
lbl_08005008:
    movs r1, #0
lbl_0800500a:
    ldrb r2, [r5, #0x18]
    bl midikey2freq
    ldr r1, lbl_0800502c @ =0x03001d00
    ldrh r2, [r1, #0x12]
    cmp r0, r2
    bne lbl_0800501e
    movs r0, #0x40
    lsls r0, r0, #8
    b lbl_08005024
lbl_0800501e:
    ldr r1, [r1, #0x18]
    bl sub_08004abc
lbl_08005024:
    str r0, [r4, #0x1c]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800502c: .4byte 0x03001d00

    thumb_func_start sub_08005030
sub_08005030: @ 0x08005030
    ldr r1, [r0, #0x24]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_0800503e
    ldr r2, [r1]
    b lbl_0800506a
lbl_0800503e:
    movs r2, #1
    ands r2, r1
    bne lbl_08005050
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    b lbl_0800506a
lbl_08005050:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
lbl_0800506a:
    str r2, [r0, #0x24]
    bx lr
    .align 2, 0

    thumb_func_start sub_08005070
sub_08005070: @ 0x08005070
    ldr r1, [r0, #0x24]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_08005080
    ldr r2, [r1]
    adds r1, #4
    b lbl_080050b0
lbl_08005080:
    movs r2, #1
    ands r2, r1
    bne lbl_08005094
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #2
    b lbl_080050b0
lbl_08005094:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
    adds r1, #1
lbl_080050b0:
    str r2, [r0, #0x24]
    adds r0, #0x28
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    bne lbl_080050cc
lbl_080050ca:
    str r1, [r0]
lbl_080050cc:
    bx lr
    .align 2, 0

    thumb_func_start sub_080050d0
sub_080050d0: @ 0x080050d0
    ldr r3, lbl_080050fc @ =0x04000070
    movs r2, #0x40
    strb r2, [r3]
    ldr r1, lbl_08005100 @ =0x04000090
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    movs r2, #0
    strb r2, [r3]
    bx lr
    .align 2, 0
lbl_080050fc: .4byte 0x04000070
lbl_08005100: .4byte 0x04000090

    thumb_func_start sub_08005104
sub_08005104: @ 0x08005104
    push {r4, r5}
    ldr r4, [r0, #0x10]
    ldrh r5, [r0, #0x14]
    ldr r1, [r0, #0x24]
    movs r2, #0x34
    ldrb r1, [r1, r2]
    cmp r1, #8
    ble lbl_0800513e
    movs r2, #4
    movs r3, #0x89
    lsls r2, r2, #0x18
    orrs r2, r3
    ldrb r2, [r2]
    lsrs r2, r2, #6
    lsls r2, r2, #6
    movs r3, #0x40
    cmp r2, r3
    bge lbl_0800512c
    adds r5, #2
    b lbl_08005134
lbl_0800512c:
    movs r3, #0x80
    cmp r2, r3
    bge lbl_0800513e
    adds r5, #1
lbl_08005134:
    movs r2, #0xc7
    movs r3, #0xfe
    lsls r2, r2, #8
    orrs r2, r3
    ands r5, r2
lbl_0800513e:
    movs r2, #4
    movs r3, #0x60
    lsls r2, r2, #0x18
    orrs r2, r3
    movs r3, #7
    ands r1, r3
    lsls r3, r4, #8
    lsrs r3, r3, #0x10
    cmp r1, #1
    beq lbl_08005160
    cmp r1, #2
    beq lbl_08005172
    cmp r1, #3
    beq lbl_08005178
    cmp r1, #4
    beq lbl_08005180
    b lbl_08005184
lbl_08005160:
    strb r4, [r2]
    strh r3, [r2, #2]
    strh r5, [r2, #4]
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    strh r5, [r2, #4]
    b lbl_08005184
lbl_08005172:
    strh r3, [r2, #8]
    strh r5, [r2, #0xc]
    b lbl_08005184
lbl_08005178:
    strb r4, [r2, #0x10]
    strh r3, [r2, #0x12]
    strh r5, [r2, #0x14]
    b lbl_08005184
lbl_08005180:
    strh r3, [r2, #0x18]
    strh r5, [r2, #0x1c]
lbl_08005184:
    lsls r5, r5, #0x11
    lsrs r5, r5, #0x11
    strh r5, [r0, #0x14]
    pop {r4, r5}
    bx lr
    .align 2, 0
