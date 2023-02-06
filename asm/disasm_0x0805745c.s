    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start GadoraHatchUpdate
GadoraHatchUpdate: @ 0x0805790c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    rsbs r3, r2, #0
    orrs r3, r2
    lsrs r3, r3, #0x1f
    str r3, [sp]
    movs r6, #0
    movs r7, #0
    movs r4, #0
    lsrs r0, r0, #0x16
    lsls r0, r0, #0x10
    mov r8, r0
    lsrs r1, r1, #0x16
    lsls r1, r1, #0x10
    mov ip, r1
    mov sb, r3
    ldr r3, lbl_08057990 @ =0x0300545c
    movs r0, #2
    rsbs r0, r0, #0
    mov sl, r0
lbl_08057944:
    ldrb r0, [r3, #1]
    lsls r0, r0, #0x1e
    cmp r0, #0
    bne lbl_08057994
    ldrb r1, [r3, #5]
    adds r0, r1, r6
    mov r5, r8
    lsrs r2, r5, #0x10
    cmp r0, r2
    blt lbl_08057974
    subs r0, r1, r6
    cmp r0, r2
    bgt lbl_08057974
    ldrb r1, [r3, #6]
    adds r0, r1, #3
    mov r5, ip
    lsrs r2, r5, #0x10
    cmp r0, r2
    blt lbl_08057974
    movs r5, #0
    subs r0, r1, r5
    cmp r0, r2
    bgt lbl_08057974
    movs r7, #1
lbl_08057974:
    cmp r7, #0
    beq lbl_08057994
    ldrb r1, [r3]
    lsls r0, r1, #0x1f
    lsrs r0, r0, #0x1f
    ldr r2, [sp]
    cmp r0, r2
    beq lbl_080579a2
    mov r0, sl
    ands r0, r1
    mov r5, sb
    orrs r0, r5
    strb r0, [r3]
    b lbl_0805799c
    .align 2, 0
lbl_08057990: .4byte 0x0300545c
lbl_08057994:
    adds r3, #8
    adds r4, #1
    cmp r4, #0xf
    ble lbl_08057944
lbl_0805799c:
    adds r4, #1
    cmp r7, #0
    bne lbl_080579a4
lbl_080579a2:
    movs r4, #0
lbl_080579a4:
    adds r0, r4, #0
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start InGameTimerUpdate
InGameTimerUpdate: @ 0x080579b8
    push {lr}
    ldr r0, lbl_08057a1c @ =0x0300014c
    ldrb r2, [r0]
    adds r3, r0, #0
    cmp r2, #0
    bne lbl_08057a18
    ldr r1, lbl_08057a20 @ =0x03000150
    ldrb r0, [r1, #3]
    adds r0, #1
    strb r0, [r1, #3]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x3f
    bls lbl_08057a00
    strb r2, [r1, #3]
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x3b
    bls lbl_08057a00
    strb r2, [r1, #2]
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x3b
    bls lbl_08057a00
    strb r2, [r1, #1]
    ldrb r0, [r1]
    cmp r0, #0x63
    bhi lbl_08057a06
    adds r0, #1
    strb r0, [r1]
lbl_08057a00:
    ldrb r0, [r1]
    cmp r0, #0x63
    bls lbl_08057a18
lbl_08057a06:
    movs r0, #1
    strb r0, [r3]
    movs r0, #0x63
    strb r0, [r1]
    movs r0, #0x3b
    strb r0, [r1, #1]
    strb r0, [r1, #2]
    movs r0, #0x3f
    strb r0, [r1, #3]
lbl_08057a18:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057a1c: .4byte 0x0300014c
lbl_08057a20: .4byte 0x03000150

    thumb_func_start IOWriteRegisters
IOWriteRegisters: @ 0x08057a24
    push {r4, lr}
    ldr r2, lbl_08057ac0 @ =0x0300000a
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057a38
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057a38:
    ldr r2, lbl_08057ac4 @ =0x03000006
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057a48
    ldr r0, lbl_08057ac8 @ =0x04000052
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057a48:
    ldr r2, lbl_08057acc @ =0x03000012
    movs r0, #0
    ldrsb r0, [r2, r0]
    cmp r0, #0
    blt lbl_08057a62
    ldr r0, lbl_08057ad0 @ =0x04000054
    movs r1, #0
    ldrsb r1, [r2, r1]
    strh r1, [r0]
    movs r1, #1
    rsbs r1, r1, #0
    adds r0, r1, #0
    strb r0, [r2]
lbl_08057a62:
    ldr r2, lbl_08057ad4 @ =0x0300000e
    ldrb r1, [r2]
    cmp r1, #0
    beq lbl_08057a72
    ldr r0, lbl_08057ad8 @ =0x04000049
    strb r1, [r0]
    movs r0, #0
    strb r0, [r2]
lbl_08057a72:
    ldr r2, lbl_08057adc @ =0x0300000f
    ldrb r1, [r2]
    cmp r1, #0
    beq lbl_08057a82
    ldr r0, lbl_08057ae0 @ =0x0400004a
    strb r1, [r0]
    movs r0, #0
    strb r0, [r2]
lbl_08057a82:
    ldr r3, lbl_08057ae4 @ =0x03005448
    ldr r4, lbl_08057ae8 @ =0x0300544a
    ldrh r1, [r3]
    ldrh r2, [r4]
    adds r0, r2, #0
    orrs r0, r1
    cmp r0, #0
    beq lbl_08057aa0
    ldr r0, lbl_08057aec @ =0x04000042
    strh r1, [r0]
    adds r0, #4
    strh r2, [r0]
    movs r0, #0
    strh r0, [r3]
    strh r0, [r4]
lbl_08057aa0:
    ldr r2, lbl_08057af0 @ =0x0300544c
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057ab0
    ldr r0, lbl_08057af4 @ =0x04000050
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057ab0:
    bl sub_0805b3fc
    bl sub_0805dd5c
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057ac0: .4byte 0x0300000a
lbl_08057ac4: .4byte 0x03000006
lbl_08057ac8: .4byte 0x04000052
lbl_08057acc: .4byte 0x03000012
lbl_08057ad0: .4byte 0x04000054
lbl_08057ad4: .4byte 0x0300000e
lbl_08057ad8: .4byte 0x04000049
lbl_08057adc: .4byte 0x0300000f
lbl_08057ae0: .4byte 0x0400004a
lbl_08057ae4: .4byte 0x03005448
lbl_08057ae8: .4byte 0x0300544a
lbl_08057aec: .4byte 0x04000042
lbl_08057af0: .4byte 0x0300544c
lbl_08057af4: .4byte 0x04000050

    thumb_func_start IOWriteRegistersDuringTransition
IOWriteRegistersDuringTransition: @ 0x08057af8
    push {r4, lr}
    ldr r2, lbl_08057b98 @ =0x0300000a
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057b0c
    movs r0, #0x80
    lsls r0, r0, #0x13
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057b0c:
    ldr r2, lbl_08057b9c @ =0x03000006
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057b1c
    ldr r0, lbl_08057ba0 @ =0x04000052
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057b1c:
    ldr r2, lbl_08057ba4 @ =0x0300000e
    ldrb r1, [r2]
    cmp r1, #0
    beq lbl_08057b2c
    ldr r0, lbl_08057ba8 @ =0x04000049
    strb r1, [r0]
    movs r0, #0
    strb r0, [r2]
lbl_08057b2c:
    ldr r2, lbl_08057bac @ =0x0300000f
    ldrb r1, [r2]
    cmp r1, #0
    beq lbl_08057b3c
    ldr r0, lbl_08057bb0 @ =0x0400004a
    strb r1, [r0]
    movs r0, #0
    strb r0, [r2]
lbl_08057b3c:
    ldr r3, lbl_08057bb4 @ =0x03005448
    ldr r4, lbl_08057bb8 @ =0x0300544a
    ldrh r1, [r3]
    ldrh r2, [r4]
    adds r0, r2, #0
    orrs r0, r1
    cmp r0, #0
    beq lbl_08057b5a
    ldr r0, lbl_08057bbc @ =0x04000042
    strh r1, [r0]
    adds r0, #4
    strh r2, [r0]
    movs r0, #0
    strh r0, [r3]
    strh r0, [r4]
lbl_08057b5a:
    ldr r2, lbl_08057bc0 @ =0x0300544c
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057b6a
    ldr r0, lbl_08057bc4 @ =0x04000050
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057b6a:
    ldr r2, lbl_08057bc8 @ =0x03005512
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057b7a
    ldr r0, lbl_08057bcc @ =0x0400000a
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057b7a:
    ldr r2, lbl_08057bd0 @ =0x03005510
    ldrh r1, [r2]
    cmp r1, #0
    beq lbl_08057b8a
    ldr r0, lbl_08057bd4 @ =0x0400000e
    strh r1, [r0]
    movs r0, #0
    strh r0, [r2]
lbl_08057b8a:
    bl sub_0805b3fc
    bl sub_0805dd5c
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057b98: .4byte 0x0300000a
lbl_08057b9c: .4byte 0x03000006
lbl_08057ba0: .4byte 0x04000052
lbl_08057ba4: .4byte 0x0300000e
lbl_08057ba8: .4byte 0x04000049
lbl_08057bac: .4byte 0x0300000f
lbl_08057bb0: .4byte 0x0400004a
lbl_08057bb4: .4byte 0x03005448
lbl_08057bb8: .4byte 0x0300544a
lbl_08057bbc: .4byte 0x04000042
lbl_08057bc0: .4byte 0x0300544c
lbl_08057bc4: .4byte 0x04000050
lbl_08057bc8: .4byte 0x03005512
lbl_08057bcc: .4byte 0x0400000a
lbl_08057bd0: .4byte 0x03005510
lbl_08057bd4: .4byte 0x0400000e

    thumb_func_start update_dispcnt
update_dispcnt: @ 0x08057bd8
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    cmp r4, #0
    beq lbl_08057c46
    ldr r0, lbl_08057c08 @ =0x0300000a
    movs r1, #0x80
    lsls r1, r1, #0x13
    ldrh r1, [r1]
    strh r1, [r0]
    adds r5, r0, #0
    cmp r2, #0
    beq lbl_08057c14
    ldr r2, lbl_08057c0c @ =0x03000076
    ldr r3, lbl_08057c10 @ =0x03000088
    ldrh r1, [r3]
    adds r0, r4, #0
    orrs r0, r1
    strh r0, [r2]
    adds r6, r2, #0
    b lbl_08057c22
    .align 2, 0
lbl_08057c08: .4byte 0x0300000a
lbl_08057c0c: .4byte 0x03000076
lbl_08057c10: .4byte 0x03000088
lbl_08057c14:
    ldr r0, lbl_08057c34 @ =0x03000076
    ldr r2, lbl_08057c38 @ =0x03000088
    ldrh r1, [r2]
    bics r1, r4
    strh r1, [r0]
    adds r6, r0, #0
    adds r3, r2, #0
lbl_08057c22:
    ldrh r2, [r6]
    ldrh r1, [r3]
    cmp r2, r1
    beq lbl_08057c46
    ldrh r0, [r5]
    cmp r0, r1
    bne lbl_08057c3c
    strh r2, [r5]
    b lbl_08057c40
    .align 2, 0
lbl_08057c34: .4byte 0x03000076
lbl_08057c38: .4byte 0x03000088
lbl_08057c3c:
    movs r0, #0
    strh r0, [r5]
lbl_08057c40:
    ldrh r0, [r6]
    strh r0, [r3]
    strh r4, [r6]
lbl_08057c46:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    thumb_func_start process_pause_button_press
process_pause_button_press: @ 0x08057c4c
    push {r4, lr}
    movs r4, #1
    ldr r0, lbl_08057c78 @ =0x03000bf0
    movs r1, #0
    ldrsb r1, [r0, r1]
    adds r2, r0, #0
    cmp r1, #0
    beq lbl_08057c80
    ldr r0, lbl_08057c7c @ =0x03000130
    ldrb r1, [r0]
    ldrb r0, [r0, #0x10]
    orrs r0, r1
    cmp r0, #0
    beq lbl_08057c6a
    movs r4, #0
lbl_08057c6a:
    cmp r4, #1
    bne lbl_08057cf6
    bl sub_08060a48
    movs r0, #2
    b lbl_08057cec
    .align 2, 0
lbl_08057c78: .4byte 0x03000bf0
lbl_08057c7c: .4byte 0x03000130
lbl_08057c80:
    ldr r0, lbl_08057ccc @ =0x03001606
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08057caa
    ldr r0, lbl_08057cd0 @ =0x03000049
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_08057caa
    ldr r0, lbl_08057cd4 @ =0x0300004b
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08057caa
    ldr r1, lbl_08057cd8 @ =0x03000130
    ldrb r0, [r1]
    cmp r0, #0
    bne lbl_08057caa
    ldrb r0, [r1, #0x10]
    cmp r0, #0
    beq lbl_08057cac
lbl_08057caa:
    movs r4, #0
lbl_08057cac:
    cmp r4, #1
    bne lbl_08057cf6
    movs r0, #2
    strb r0, [r2]
    ldr r0, lbl_08057cdc @ =0x030013d2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08057ce4
    ldr r0, lbl_08057ce0 @ =0x0300137c
    ldrh r0, [r0]
    movs r1, #0xe
    cmp r0, #0
    beq lbl_08057cea
    movs r1, #0xd
    b lbl_08057cea
    .align 2, 0
lbl_08057ccc: .4byte 0x03001606
lbl_08057cd0: .4byte 0x03000049
lbl_08057cd4: .4byte 0x0300004b
lbl_08057cd8: .4byte 0x03000130
lbl_08057cdc: .4byte 0x030013d2
lbl_08057ce0: .4byte 0x0300137c
lbl_08057ce4:
    bl sub_08060a48
    movs r1, #2
lbl_08057cea:
    adds r0, r1, #0
lbl_08057cec:
    bl start_special_background_fading
    ldr r1, lbl_08057d00 @ =0x03000005
    movs r0, #0
    strb r0, [r1]
lbl_08057cf6:
    adds r0, r4, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08057d00: .4byte 0x03000005

    thumb_func_start load_room_cutscene_escape
load_room_cutscene_escape: @ 0x08057d04
    push {r4, lr}
    sub sp, #4
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    ldr r4, lbl_08057d9c @ =0x030013b4
    strh r2, [r4]
    ldr r4, lbl_08057da0 @ =0x030013b6
    strh r3, [r4]
    ldr r4, lbl_08057da4 @ =0x030013b8
    strh r2, [r4]
    ldr r4, lbl_08057da8 @ =0x030013ba
    strh r3, [r4]
    ldr r4, lbl_08057dac @ =0x030013bc
    strh r2, [r4]
    ldr r2, lbl_08057db0 @ =0x030013be
    strh r3, [r2]
    ldr r2, lbl_08057db4 @ =0x03000054
    strb r0, [r2]
    ldr r0, lbl_08057db8 @ =0x03000055
    subs r1, #1
    strb r1, [r0]
    bl load_room_entry
    bl load_tileset
    bl load_room_backgrounds
    bl remove_never_reform_blocks_and_collected_tank
    bl TransparencySetRoomEffectsTransparency
    bl ScrollBG3
    bl check_play_lightning_effect
    bl update_backgrounds_pos
    bl load_doors
    bl check_hatch_lock_events
    movs r0, #0
    bl sub_08056b28
    movs r0, #1
    bl sub_08056b28
    movs r0, #2
    bl sub_08056b28
    bl load_animated_graphics
    ldr r1, lbl_08057dbc @ =0x02007000
    ldr r2, lbl_08057dc0 @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_08057dc4 @ =0x04000008
    ldr r2, lbl_08057dc8 @ =0x03000088
    ldrh r0, [r2, #0xa]
    strh r0, [r1]
    adds r1, #6
    ldrh r0, [r2, #0x10]
    strh r0, [r1]
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08057d9c: .4byte 0x030013b4
lbl_08057da0: .4byte 0x030013b6
lbl_08057da4: .4byte 0x030013b8
lbl_08057da8: .4byte 0x030013ba
lbl_08057dac: .4byte 0x030013bc
lbl_08057db0: .4byte 0x030013be
lbl_08057db4: .4byte 0x03000054
lbl_08057db8: .4byte 0x03000055
lbl_08057dbc: .4byte 0x02007000
lbl_08057dc0: .4byte 0x06003000
lbl_08057dc4: .4byte 0x04000008
lbl_08057dc8: .4byte 0x03000088

    thumb_func_start setup_clipdata_code
setup_clipdata_code: @ 0x08057dcc
    ldr r1, lbl_08057de4 @ =0x040000d4
    ldr r0, lbl_08057de8 @ =sub_08057f7c
    str r0, [r1]
    ldr r2, lbl_08057dec @ =0x030016c4
    str r2, [r1, #4]
    ldr r0, lbl_08057df0 @ =0x80000140
    str r0, [r1, #8]
    ldr r0, [r1, #8]
    ldr r0, lbl_08057df4 @ =0x03005704
    adds r2, #1
    str r2, [r0]
    bx lr
    .align 2, 0
lbl_08057de4: .4byte 0x040000d4
lbl_08057de8: .4byte sub_08057f7c
lbl_08057dec: .4byte 0x030016c4
lbl_08057df0: .4byte 0x80000140
lbl_08057df4: .4byte 0x03005704

    thumb_func_start sub_08057df8
sub_08057df8: @ 0x08057df8
    push {r4, r5, r6, lr}
    sub sp, #0x14
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    mov r2, sp
    lsrs r0, r0, #0x16
    strh r0, [r2, #0x12]
    mov r0, sp
    lsrs r1, r1, #0x16
    strh r1, [r0, #0x10]
    ldr r4, lbl_08057e1c @ =0x0300009c
    ldrh r0, [r4, #0x1c]
    cmp r1, r0
    blo lbl_08057e24
    ldr r0, lbl_08057e20 @ =0x01000001
    b lbl_08057e72
    .align 2, 0
lbl_08057e1c: .4byte 0x0300009c
lbl_08057e20: .4byte 0x01000001
lbl_08057e24:
    mov r0, sp
    ldrh r0, [r0, #0x12]
    ldrh r1, [r4, #0x1e]
    cmp r0, r1
    bhs lbl_08057e70
    ldr r3, lbl_08057e68 @ =0x03005450
    ldrh r2, [r4, #0x1c]
    mov r0, sp
    ldrh r0, [r0, #0x12]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1, #0x10]
    adds r0, r0, r1
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    ldr r0, [r3, #4]
    adds r0, r0, r1
    ldrb r0, [r0]
    str r0, [sp]
    movs r0, #0x3f
    ands r5, r0
    str r5, [sp, #8]
    ands r6, r0
    str r6, [sp, #4]
    movs r0, #0
    str r0, [sp, #0xc]
    ldr r0, lbl_08057e6c @ =0x03005704
    ldr r1, [r0]
    mov r0, sp
    bl _call_via_r1
    b lbl_08057e72
    .align 2, 0
lbl_08057e68: .4byte 0x03005450
lbl_08057e6c: .4byte 0x03005704
lbl_08057e70:
    movs r0, #0
lbl_08057e72:
    add sp, #0x14
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ClipdataProcess
ClipdataProcess: @ 0x08057e7c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x14
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    mov r8, r2
    mov r2, sp
    lsrs r0, r0, #0x16
    movs r4, #0
    movs r3, #0
    strh r0, [r2, #0x12]
    mov r0, sp
    lsrs r1, r1, #0x16
    strh r1, [r0, #0x10]
    ldr r2, lbl_08057ec0 @ =0x0300009c
    ldrh r0, [r2, #0x1c]
    cmp r1, r0
    bhs lbl_08057eb0
    mov r0, sp
    ldrh r0, [r0, #0x12]
    ldrh r2, [r2, #0x1e]
    cmp r0, r2
    blo lbl_08057ecc
lbl_08057eb0:
    ldr r0, lbl_08057ec4 @ =0x030000dc
    strh r3, [r0]
    strh r3, [r0, #2]
    ldr r0, lbl_08057ec8 @ =0x03000079
    strb r4, [r0]
    movs r0, #0
    b lbl_08057f5e
    .align 2, 0
lbl_08057ec0: .4byte 0x0300009c
lbl_08057ec4: .4byte 0x030000dc
lbl_08057ec8: .4byte 0x03000079
lbl_08057ecc:
    ldr r2, lbl_08057ef0 @ =0x03000079
    ldrb r1, [r2]
    cmp r1, #0
    bne lbl_08057ef8
    movs r0, #2
    str r0, [sp, #0xc]
    ldr r0, lbl_08057ef4 @ =0x030000dc
    strh r1, [r0]
    strh r1, [r0, #2]
    mov r0, sp
    ldrh r1, [r0, #0x12]
    ldrh r2, [r0, #0x10]
    adds r0, r7, #0
    movs r3, #2
    bl check_current_affecting_hazard_and_very_special_clipdata
    b lbl_08057f0c
    .align 2, 0
lbl_08057ef0: .4byte 0x03000079
lbl_08057ef4: .4byte 0x030000dc
lbl_08057ef8:
    cmp r1, #5
    bls lbl_08057f08
    movs r0, #1
    str r0, [sp, #0xc]
    cmp r1, #6
    bne lbl_08057f0c
    strb r4, [r2]
    b lbl_08057f0c
lbl_08057f08:
    movs r0, #2
    str r0, [sp, #0xc]
lbl_08057f0c:
    ldr r2, lbl_08057f6c @ =0x0300009c
    mov r0, sp
    ldrh r5, [r0, #0x12]
    ldrh r0, [r2, #0x1c]
    muls r0, r5, r0
    mov r1, sp
    ldrh r3, [r1, #0x10]
    adds r0, r0, r3
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    ldr r6, lbl_08057f70 @ =0x03000079
    ldrb r0, [r6]
    cmp r0, #0
    beq lbl_08057f3a
    adds r2, r4, #0
    adds r0, r5, #0
    adds r1, r3, #0
    bl BlockApplyCCAA
    movs r0, #0
    strb r0, [r6]
lbl_08057f3a:
    ldr r0, lbl_08057f74 @ =0x03005450
    ldr r0, [r0, #4]
    adds r0, r0, r4
    ldrb r0, [r0]
    str r0, [sp]
    movs r1, #0x3f
    adds r0, r7, #0
    ands r0, r1
    str r0, [sp, #8]
    mov r0, r8
    ands r0, r1
    str r0, [sp, #4]
    ldr r0, lbl_08057f78 @ =0x03005704
    ldr r1, [r0]
    mov r0, sp
    bl _call_via_r1
    adds r4, r0, #0
lbl_08057f5e:
    add sp, #0x14
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08057f6c: .4byte 0x0300009c
lbl_08057f70: .4byte 0x03000079
lbl_08057f74: .4byte 0x03005450
lbl_08057f78: .4byte 0x03005704

    thumb_func_start sub_08057f7c
sub_08057f7c: @ 0x08057f7c
    push {lr}
    adds r2, r0, #0
    movs r1, #0
    ldr r0, [r2]
    cmp r0, #0xc
    bhi lbl_08058078
    lsls r0, r0, #2
    ldr r1, lbl_08057f94 @ =lbl_08057f98
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08057f94: .4byte lbl_08057f98
lbl_08057f98: @ jump table
    .4byte lbl_0805804a @ case 0
    .4byte lbl_08057fcc @ case 1
    .4byte lbl_08057fd4 @ case 2
    .4byte lbl_08057fe4 @ case 3
    .4byte lbl_08057ff8 @ case 4
    .4byte lbl_0805800a @ case 5
    .4byte lbl_0805801e @ case 6
    .4byte lbl_08058034 @ case 7
    .4byte lbl_0805804e @ case 8
    .4byte lbl_08058058 @ case 9
    .4byte lbl_08058062 @ case 10
    .4byte lbl_0805806e @ case 11
    .4byte lbl_0805804a @ case 12
lbl_08057fcc:
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057fd4:
    ldr r1, [r2, #8]
    ldr r0, [r2, #4]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057fe4:
    ldr r0, [r2, #4]
    movs r1, #0x3f
    subs r1, r1, r0
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08057ff8:
    ldr r0, [r2, #4]
    asrs r0, r0, #1
    ldr r1, [r2, #8]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805800a:
    ldr r0, [r2, #4]
    adds r0, #0x3f
    asrs r0, r0, #1
    ldr r1, [r2, #8]
    cmp r1, r0
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805801e:
    ldr r0, [r2, #4]
    asrs r0, r0, #1
    movs r1, #0x3f
    subs r1, r1, r0
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_08058034:
    ldr r0, [r2, #4]
    movs r1, #0x3f
    subs r1, r1, r0
    asrs r1, r1, #1
    ldr r0, [r2, #8]
    cmp r0, r1
    blt lbl_0805804a
    ldr r1, [r2]
    movs r0, #0x80
    lsls r0, r0, #0x11
    b lbl_08058076
lbl_0805804a:
    ldr r1, [r2]
    b lbl_08058078
lbl_0805804e:
    ldr r0, [r2, #0xc]
    cmp r0, #1
    ble lbl_0805806e
    movs r0, #0
    b lbl_08058068
lbl_08058058:
    ldr r0, [r2, #0xc]
    cmp r0, #1
    bgt lbl_0805806e
    movs r0, #0
    b lbl_08058068
lbl_08058062:
    ldr r0, [r2, #0xc]
    cmp r0, #0
    bne lbl_0805806e
lbl_08058068:
    str r0, [r2]
    movs r1, #0
    b lbl_08058078
lbl_0805806e:
    movs r0, #1
    str r0, [r2]
    movs r1, #0x80
    lsls r1, r1, #0x11
lbl_08058076:
    orrs r1, r0
lbl_08058078:
    adds r0, r1, #0
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start check_hazard_at_pos
check_hazard_at_pos: @ 0x08058080
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    ldr r3, lbl_080580a8 @ =0x030000dc
    movs r2, #0
    strh r2, [r3]
    strh r2, [r3, #2]
    lsrs r3, r0, #0x16
    lsrs r2, r1, #0x16
    ldr r0, lbl_080580ac @ =0x0300009c
    ldrh r1, [r0, #0x1e]
    cmp r3, r1
    bhs lbl_080580a2
    ldrh r0, [r0, #0x1c]
    cmp r2, r0
    blo lbl_080580b0
lbl_080580a2:
    movs r0, #0
    b lbl_080580ba
    .align 2, 0
lbl_080580a8: .4byte 0x030000dc
lbl_080580ac: .4byte 0x0300009c
lbl_080580b0:
    adds r0, r4, #0
    adds r1, r3, #0
    movs r3, #0
    bl check_current_affecting_hazard_and_very_special_clipdata
lbl_080580ba:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start check_current_affecting_hazard_and_very_special_clipdata
check_current_affecting_hazard_and_very_special_clipdata: @ 0x080580c0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r7, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r6, r3, #0x18
    ldr r4, lbl_08058100 @ =0x03005450
    ldr r3, lbl_08058104 @ =0x0300009c
    ldrh r0, [r3, #0x1c]
    muls r0, r1, r0
    adds r0, r0, r2
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r4, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r5, [r0]
    cmp r5, #0
    beq lbl_0805810c
    cmp r5, #0xf
    bgt lbl_0805810c
    ldr r1, lbl_08058108 @ =0x083458e4
    lsls r0, r5, #1
    adds r0, r0, r1
    ldrh r4, [r0]
    b lbl_0805810e
    .align 2, 0
lbl_08058100: .4byte 0x03005450
lbl_08058104: .4byte 0x0300009c
lbl_08058108: .4byte 0x083458e4
lbl_0805810c:
    movs r4, #0
lbl_0805810e:
    cmp r6, #0
    bne lbl_0805812c
    subs r0, r4, #1
    cmp r0, #1
    bhi lbl_0805812c
    ldr r0, lbl_08058144 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x1d
    beq lbl_0805812c
    adds r0, r4, #0
    bl check_cant_use_elevator
    cmp r0, #0
    beq lbl_0805812c
    movs r4, #0
lbl_0805812c:
    ldr r0, lbl_08058148 @ =0x030000dc
    strh r4, [r0]
    movs r4, #0
    adds r2, r5, #0
    subs r2, #0x40
    adds r5, r0, #0
    cmp r2, #3
    bhi lbl_08058150
    ldr r1, lbl_0805814c @ =0x08345924
    lsls r0, r2, #1
    adds r0, r0, r1
    b lbl_0805818a
    .align 2, 0
lbl_08058144: .4byte 0x030013d4
lbl_08058148: .4byte 0x030000dc
lbl_0805814c: .4byte 0x08345924
lbl_08058150:
    ldr r1, lbl_0805817c @ =0x030000bc
    ldrb r0, [r1, #1]
    cmp r0, #0
    beq lbl_0805818c
    ldrb r0, [r1, #0x14]
    cmp r0, #0
    beq lbl_0805818c
    cmp r0, #7
    bhi lbl_0805818c
    ldr r3, lbl_08058180 @ =0x08345904
    lsls r1, r0, #2
    adds r0, r3, #2
    adds r2, r1, r0
    ldrh r0, [r2]
    cmp r0, #0
    beq lbl_08058188
    ldr r0, lbl_08058184 @ =0x0300006c
    ldrh r0, [r0]
    cmp r0, r7
    bhi lbl_08058188
    ldrh r4, [r2]
    b lbl_0805818c
    .align 2, 0
lbl_0805817c: .4byte 0x030000bc
lbl_08058180: .4byte 0x08345904
lbl_08058184: .4byte 0x0300006c
lbl_08058188:
    adds r0, r1, r3
lbl_0805818a:
    ldrh r4, [r0]
lbl_0805818c:
    strh r4, [r5, #2]
    ldrh r0, [r5]
    lsls r0, r0, #0x10
    ldrh r1, [r5, #2]
    orrs r0, r1
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_cant_use_elevator
check_cant_use_elevator: @ 0x0805819c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r0, lbl_080581e0 @ =0x03000198
    movs r1, #0
    strb r1, [r0, #2]
    movs r2, #0
    strh r1, [r0]
    strb r2, [r0, #3]
    movs r4, #0
    movs r5, #8
    ldr r0, lbl_080581e4 @ =0x03000054
    mov sb, r0
    ldr r1, lbl_080581e8 @ =0x08345934
    mov r8, r1
    mov r6, r8
    adds r6, #0x44
    movs r7, #0x40
lbl_080581c2:
    ldr r0, lbl_080581e4 @ =0x03000054
    ldr r1, lbl_080581e8 @ =0x08345934
    adds r1, r7, r1
    ldrb r0, [r0]
    ldrb r2, [r1]
    cmp r0, r2
    bne lbl_080581f0
    ldr r0, lbl_080581ec @ =0x03000055
    ldrb r0, [r0]
    ldrb r1, [r1, #1]
    cmp r0, r1
    bne lbl_080581f0
    movs r4, #1
    b lbl_0805820c
    .align 2, 0
lbl_080581e0: .4byte 0x03000198
lbl_080581e4: .4byte 0x03000054
lbl_080581e8: .4byte 0x08345934
lbl_080581ec: .4byte 0x03000055
lbl_080581f0:
    mov r1, sb
    ldrb r0, [r1]
    ldrb r2, [r6]
    cmp r0, r2
    bne lbl_08058208
    ldr r0, lbl_08058228 @ =0x03000055
    ldrb r0, [r0]
    ldrb r1, [r6, #1]
    cmp r0, r1
    bne lbl_08058208
    movs r4, #1
    rsbs r4, r4, #0
lbl_08058208:
    cmp r4, #0
    beq lbl_08058240
lbl_0805820c:
    cmp r5, #8
    bne lbl_0805822e
    movs r0, #3
    movs r1, #0x41
    bl EventFunction
    cmp r0, #0
    beq lbl_0805822c
    mov r6, r8
    adds r6, #0x34
    movs r7, #0x30
    movs r5, #6
    b lbl_0805822e
    .align 2, 0
lbl_08058228: .4byte 0x03000055
lbl_0805822c:
    movs r4, #0
lbl_0805822e:
    cmp r4, #0
    beq lbl_08058240
    ldr r0, lbl_0805823c @ =0x03000198
    strb r5, [r0, #2]
    strb r4, [r0, #3]
    b lbl_0805824a
    .align 2, 0
lbl_0805823c: .4byte 0x03000198
lbl_08058240:
    subs r6, #8
    subs r7, #8
    subs r5, #1
    cmp r5, #0
    bgt lbl_080581c2
lbl_0805824a:
    movs r0, #0
    cmp r4, #0
    bne lbl_08058252
    movs r0, #1
lbl_08058252:
    adds r4, r0, #0
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start check_for_ground_effect_clipdata
check_for_ground_effect_clipdata: @ 0x08058260
    push {lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r3, r0, #0x16
    lsrs r1, r1, #0x16
    ldr r2, lbl_0805827c @ =0x0300009c
    ldrh r0, [r2, #0x1e]
    cmp r3, r0
    bge lbl_08058278
    ldrh r0, [r2, #0x1c]
    cmp r1, r0
    blt lbl_08058280
lbl_08058278:
    movs r0, #0
    b lbl_080582c0
    .align 2, 0
lbl_0805827c: .4byte 0x0300009c
lbl_08058280:
    muls r0, r3, r0
    adds r0, r0, r1
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    movs r0, #0x80
    lsls r0, r0, #3
    ands r0, r2
    cmp r0, #0
    beq lbl_0805829a
    movs r2, #0
    b lbl_080582a4
lbl_0805829a:
    ldr r0, lbl_080582b4 @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r2, [r0]
lbl_080582a4:
    adds r1, r2, #0
    subs r1, #0x50
    cmp r1, #4
    bhi lbl_080582bc
    ldr r0, lbl_080582b8 @ =0x0834592c
    adds r0, r1, r0
    ldrb r2, [r0]
    b lbl_080582be
    .align 2, 0
lbl_080582b4: .4byte 0x03005450
lbl_080582b8: .4byte 0x0834592c
lbl_080582bc:
    movs r2, #0
lbl_080582be:
    adds r0, r2, #0
lbl_080582c0:
    pop {r1}
    bx r1

    thumb_func_start process_scrolls
process_scrolls: @ 0x080582c4
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    bl update_gCurrentScrolls
    ldr r0, lbl_08058320 @ =0x03000144
    ldrh r7, [r0]
    ldrh r6, [r0, #2]
    ldr r4, lbl_08058324 @ =0x03000118
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_080582ee
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_x
    adds r7, r0, #0
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_y
    adds r6, r0, #0
lbl_080582ee:
    adds r4, #0xc
    ldrb r0, [r4]
    cmp r0, #0
    beq lbl_0805830e
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_x
    adds r0, r7, r0
    asrs r7, r0, #1
    adds r0, r4, #0
    adds r1, r5, #0
    bl process_scroll_y
    adds r0, r6, r0
    asrs r6, r0, #1
lbl_0805830e:
    lsls r0, r7, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r6, #0x10
    lsrs r1, r1, #0x10
    bl ScrollScreen
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058320: .4byte 0x03000144
lbl_08058324: .4byte 0x03000118

    thumb_func_start ScrollScreen
ScrollScreen: @ 0x08058328
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r2, r1, #0x10
    ldr r1, lbl_08058364 @ =0x03000144
    strh r4, [r1]
    strh r2, [r1, #2]
    ldr r0, lbl_08058368 @ =0x03000c72
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r5, r1, #0
    cmp r0, #0
    beq lbl_080583dc
    ldr r0, lbl_0805836c @ =0x030013ba
    adds r3, r0, #0
    ldrh r0, [r3]
    cmp r2, r0
    beq lbl_08058390
    ldrh r0, [r3]
    subs r1, r2, r0
    cmp r1, #0
    ble lbl_08058374
    ldr r0, lbl_08058370 @ =0x03005714
    movs r2, #6
    ldrsh r0, [r0, r2]
    cmp r0, r1
    bge lbl_08058380
    b lbl_0805837e
    .align 2, 0
lbl_08058364: .4byte 0x03000144
lbl_08058368: .4byte 0x03000c72
lbl_0805836c: .4byte 0x030013ba
lbl_08058370: .4byte 0x03005714
lbl_08058374:
    ldr r0, lbl_0805838c @ =0x03005714
    movs r2, #4
    ldrsh r0, [r0, r2]
    cmp r0, r1
    ble lbl_08058380
lbl_0805837e:
    adds r1, r0, #0
lbl_08058380:
    strb r1, [r5, #5]
    ldrh r0, [r3]
    adds r0, r0, r1
    strh r0, [r3]
    b lbl_08058394
    .align 2, 0
lbl_0805838c: .4byte 0x03005714
lbl_08058390:
    movs r0, #0
    strb r0, [r5, #5]
lbl_08058394:
    ldr r0, lbl_080583b4 @ =0x030013b8
    adds r2, r0, #0
    ldrh r3, [r2]
    cmp r4, r3
    beq lbl_080583d8
    ldrh r0, [r2]
    subs r1, r4, r0
    cmp r1, #0
    ble lbl_080583bc
    ldr r0, lbl_080583b8 @ =0x03005714
    movs r3, #2
    ldrsh r0, [r0, r3]
    cmp r0, r1
    bge lbl_080583c8
    b lbl_080583c6
    .align 2, 0
lbl_080583b4: .4byte 0x030013b8
lbl_080583b8: .4byte 0x03005714
lbl_080583bc:
    ldr r0, lbl_080583d4 @ =0x03005714
    movs r3, #0
    ldrsh r0, [r0, r3]
    cmp r0, r1
    ble lbl_080583c8
lbl_080583c6:
    adds r1, r0, #0
lbl_080583c8:
    strb r1, [r5, #4]
    ldrh r0, [r2]
    adds r0, r0, r1
    strh r0, [r2]
    b lbl_080583dc
    .align 2, 0
lbl_080583d4: .4byte 0x03005714
lbl_080583d8:
    movs r0, #0
    strb r0, [r5, #4]
lbl_080583dc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start process_scroll_x
process_scroll_x: @ 0x080583e4
    push {r4, lr}
    adds r3, r0, #0
    ldrh r1, [r1]
    ldrh r2, [r3, #4]
    movs r4, #0xf0
    lsls r4, r4, #1
    adds r0, r2, r4
    cmp r1, r0
    bge lbl_080583fa
    adds r0, r2, #0
    b lbl_08058418
lbl_080583fa:
    ldrh r2, [r3, #2]
    ldr r3, lbl_0805840c @ =0xfffffe20
    adds r0, r2, r3
    cmp r1, r0
    ble lbl_08058414
    ldr r4, lbl_08058410 @ =0xfffffc40
    adds r0, r2, r4
    b lbl_08058418
    .align 2, 0
lbl_0805840c: .4byte 0xfffffe20
lbl_08058410: .4byte 0xfffffc40
lbl_08058414:
    ldr r2, lbl_08058420 @ =0xfffffe20
    adds r0, r1, r2
lbl_08058418:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08058420: .4byte 0xfffffe20

    thumb_func_start process_scroll_y
process_scroll_y: @ 0x08058424
    push {r4, lr}
    adds r2, r0, #0
    ldrb r0, [r2]
    cmp r0, #2
    bne lbl_08058468
    ldrh r1, [r1, #2]
    ldrh r3, [r2, #6]
    movs r4, #0xc0
    lsls r4, r4, #1
    adds r0, r3, r4
    cmp r1, r0
    blt lbl_0805844e
    ldrh r2, [r2, #8]
    ldr r4, lbl_08058454 @ =0xffffff00
    adds r0, r2, r4
    cmp r1, r0
    ble lbl_0805845c
    ldr r1, lbl_08058458 @ =0xfffffd80
    adds r0, r2, r1
    cmp r0, r3
    bge lbl_0805846e
lbl_0805844e:
    adds r0, r3, #0
    b lbl_0805846e
    .align 2, 0
lbl_08058454: .4byte 0xffffff00
lbl_08058458: .4byte 0xfffffd80
lbl_0805845c:
    ldr r2, lbl_08058464 @ =0xfffffe80
    adds r0, r1, r2
    b lbl_0805846e
    .align 2, 0
lbl_08058464: .4byte 0xfffffe80
lbl_08058468:
    ldrh r0, [r2, #8]
    ldr r4, lbl_08058474 @ =0xfffffd80
    adds r0, r0, r4
lbl_0805846e:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08058474: .4byte 0xfffffd80

    thumb_func_start load_scrolls
load_scrolls: @ 0x08058478
    push {r4, r5, lr}
    ldr r1, lbl_0805849c @ =0x0875fd28
    ldr r0, lbl_080584a0 @ =0x03000054
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldr r2, [r0]
    ldr r3, [r2]
    ldr r0, lbl_080584a4 @ =0x03000055
    ldrb r1, [r3]
    adds r5, r0, #0
    ldr r4, lbl_080584a8 @ =0x03005708
    ldrb r0, [r5]
    cmp r1, r0
    bne lbl_080584b0
    str r3, [r4]
    b lbl_080584c6
    .align 2, 0
lbl_0805849c: .4byte 0x0875fd28
lbl_080584a0: .4byte 0x03000054
lbl_080584a4: .4byte 0x03000055
lbl_080584a8: .4byte 0x03005708
lbl_080584ac:
    str r1, [r4]
    b lbl_080584cc
lbl_080584b0:
    ldr r1, [r2]
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_080584ac
    adds r2, #4
    ldr r1, [r2]
    ldrb r0, [r1]
    ldrb r3, [r5]
    cmp r0, r3
    bne lbl_080584b0
    str r1, [r4]
lbl_080584c6:
    ldr r1, lbl_080584d4 @ =0x030000bc
    movs r0, #3
    strb r0, [r1, #5]
lbl_080584cc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080584d4: .4byte 0x030000bc

    thumb_func_start update_gCurrentScrolls
update_gCurrentScrolls: @ 0x080584d8
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #0x10
    ldr r2, lbl_08058554 @ =0x03000118
    movs r1, #0
    strb r1, [r2]
    strb r1, [r2, #0xc]
    ldrh r1, [r0]
    lsrs r1, r1, #6
    mov r8, r1
    ldrh r0, [r0, #2]
    subs r0, #1
    lsls r0, r0, #0xa
    lsrs r0, r0, #0x10
    mov ip, r0
    ldr r0, lbl_08058558 @ =0x03005708
    ldr r0, [r0]
    adds r0, #1
    ldrb r5, [r0]
    adds r4, r0, #1
    adds r7, r2, #0
    cmp r5, #0
    bne lbl_0805850c
    b lbl_08058616
lbl_0805850c:
    ldr r6, lbl_0805855c @ =0x0300009c
    mov sb, r7
lbl_08058510:
    mov r0, sb
    adds r0, #0x18
    cmp r2, r0
    bne lbl_0805851a
    b lbl_0805862c
lbl_0805851a:
    movs r0, #0
    str r0, [sp]
    movs r0, #1
    str r0, [sp, #4]
    movs r0, #2
    str r0, [sp, #8]
    movs r0, #3
    str r0, [sp, #0xc]
    ldrb r0, [r4, #4]
    cmp r0, #0xff
    beq lbl_08058560
    ldrb r0, [r4, #7]
    cmp r0, #0xff
    beq lbl_08058560
    ldrb r1, [r4, #5]
    ldrh r0, [r6, #0x1c]
    muls r0, r1, r0
    ldrb r1, [r4, #4]
    adds r3, r0, r1
    ldr r1, [r6, #0x18]
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08058586
    ldrb r0, [r4, #6]
    cmp r0, #0xff
    beq lbl_08058586
    b lbl_0805857c
    .align 2, 0
lbl_08058554: .4byte 0x03000118
lbl_08058558: .4byte 0x03005708
lbl_0805855c: .4byte 0x0300009c
lbl_08058560:
    ldr r0, lbl_0805863c @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x1d
    bne lbl_08058586
    ldrb r0, [r4, #7]
    cmp r0, #0xff
    beq lbl_08058586
    ldrb r0, [r4, #6]
    subs r0, #2
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_08058586
    ldrb r0, [r4, #6]
lbl_0805857c:
    lsls r0, r0, #2
    mov r3, sp
    adds r1, r3, r0
    movs r0, #7
    str r0, [r1]
lbl_08058586:
    ldr r0, [sp]
    adds r0, r4, r0
    ldrb r1, [r0]
    cmp r1, r8
    bhi lbl_0805860c
    ldr r0, [sp, #4]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp r8, r0
    bhi lbl_0805860c
    ldr r0, [sp, #8]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp r0, ip
    bhi lbl_0805860c
    ldr r0, [sp, #0xc]
    adds r0, r4, r0
    ldrb r0, [r0]
    cmp ip, r0
    bhi lbl_0805860c
    ldrb r0, [r2]
    cmp r0, #0
    bne lbl_0805860c
    lsls r0, r1, #6
    cmp r0, #0x80
    bge lbl_080585bc
    movs r0, #0x80
lbl_080585bc:
    strh r0, [r2, #4]
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    adds r3, r0, #0
    subs r3, #0x80
    ldr r0, [sp, #4]
    adds r0, r4, r0
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #6
    adds r1, r3, #0
    cmp r0, r3
    bge lbl_080585d8
    adds r1, r0, #0
lbl_080585d8:
    strh r1, [r2, #2]
    ldr r0, [sp, #8]
    adds r0, r4, r0
    ldrb r0, [r0]
    lsls r0, r0, #6
    cmp r0, #0x80
    bge lbl_080585e8
    movs r0, #0x80
lbl_080585e8:
    strh r0, [r2, #6]
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    adds r3, r0, #0
    subs r3, #0x80
    ldr r0, [sp, #0xc]
    adds r0, r4, r0
    ldrb r0, [r0]
    adds r0, #1
    lsls r0, r0, #6
    adds r1, r3, #0
    cmp r0, r3
    bge lbl_08058604
    adds r1, r0, #0
lbl_08058604:
    strh r1, [r2, #8]
    movs r0, #2
    strb r0, [r2]
    adds r2, #0xc
lbl_0805860c:
    adds r4, #8
    subs r5, #1
    cmp r5, #0
    beq lbl_08058616
    b lbl_08058510
lbl_08058616:
    ldrb r0, [r7]
    cmp r0, #0
    bne lbl_0805862c
    ldrb r0, [r7, #0xc]
    cmp r0, #0
    bne lbl_0805862c
    strb r0, [r7]
    strh r0, [r7, #2]
    strh r0, [r7, #4]
    strh r0, [r7, #6]
    strh r0, [r7, #8]
lbl_0805862c:
    add sp, #0x10
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805863c: .4byte 0x030013d4

    thumb_func_start ScrollProcessGeneral
ScrollProcessGeneral: @ 0x08058640
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805867c @ =0x03005520
    ldrb r0, [r0, #1]
    cmp r0, #0
    beq lbl_0805864e
    b lbl_0805881e
lbl_0805864e:
    ldr r0, lbl_08058680 @ =0x03000100
    ldrb r1, [r0]
    adds r4, r0, #0
    cmp r1, #0
    bne lbl_080586c8
    ldr r2, lbl_08058684 @ =0x030013d4
    ldrh r1, [r2, #0x14]
    adds r1, #1
    lsls r1, r1, #0x10
    ldrh r0, [r2, #0x12]
    orrs r0, r1
    str r0, [sp]
    ldrb r0, [r2]
    adds r1, r0, #0
    cmp r1, #0x15
    beq lbl_08058672
    cmp r1, #0x3d
    bne lbl_0805868c
lbl_08058672:
    ldr r1, lbl_08058688 @ =0x0300003e
    movs r0, #1
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_0805867c: .4byte 0x03005520
lbl_08058680: .4byte 0x03000100
lbl_08058684: .4byte 0x030013d4
lbl_08058688: .4byte 0x0300003e
lbl_0805868c:
    subs r0, #0x1a
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bhi lbl_080586a4
    ldr r1, lbl_080586a0 @ =0x0300003e
    movs r0, #8
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586a0: .4byte 0x0300003e
lbl_080586a4:
    cmp r1, #0x1c
    bne lbl_080586b4
    ldr r1, lbl_080586b0 @ =0x0300003e
    movs r0, #0x14
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586b0: .4byte 0x0300003e
lbl_080586b4:
    ldr r1, lbl_080586c4 @ =0x0300003e
    ldrh r0, [r1]
    cmp r0, #0
    beq lbl_080586f4
    subs r0, #1
    strh r0, [r1]
    b lbl_080586f4
    .align 2, 0
lbl_080586c4: .4byte 0x0300003e
lbl_080586c8:
    cmp r1, #1
    bne lbl_080586d8
    ldrh r1, [r4, #4]
    lsls r1, r1, #0x10
    ldrh r0, [r4, #2]
    orrs r0, r1
    str r0, [sp]
    b lbl_080586f4
lbl_080586d8:
    ldr r2, lbl_08058740 @ =0x030013d4
    ldrh r1, [r2, #0x12]
    ldrh r0, [r4, #2]
    adds r1, r1, r0
    ldrh r0, [r4, #4]
    adds r0, #1
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    lsls r0, r0, #0xf
    lsrs r0, r0, #0x10
    lsls r0, r0, #0x10
    lsrs r1, r1, #1
    orrs r1, r0
    str r1, [sp]
lbl_080586f4:
    ldr r2, [sp]
    lsrs r1, r2, #0x10
    movs r0, #0x80
    lsls r0, r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_08058708
    ldr r0, lbl_08058744 @ =0x0000ffff
    ands r2, r0
    str r2, [sp]
lbl_08058708:
    ldr r3, lbl_08058748 @ =0x03005714
    ldr r2, lbl_0805874c @ =0x08345988
    ldr r0, [r2]
    ldr r1, [r2, #4]
    str r0, [r3]
    str r1, [r3, #4]
    ldrb r0, [r4]
    adds r4, r3, #0
    cmp r0, #0
    bne lbl_080587a2
    ldr r0, lbl_08058750 @ =0x0300003e
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_0805879a
    ldr r2, lbl_08058740 @ =0x030013d4
    ldrh r1, [r2, #0x12]
    ldr r0, lbl_08058754 @ =0x03001600
    ldrh r0, [r0]
    subs r1, r1, r0
    cmp r1, #0
    ble lbl_08058758
    movs r5, #2
    ldrsh r0, [r3, r5]
    cmp r1, r0
    blt lbl_08058768
    adds r0, r1, #4
    strh r0, [r3, #2]
    b lbl_08058768
    .align 2, 0
lbl_08058740: .4byte 0x030013d4
lbl_08058744: .4byte 0x0000ffff
lbl_08058748: .4byte 0x03005714
lbl_0805874c: .4byte 0x08345988
lbl_08058750: .4byte 0x0300003e
lbl_08058754: .4byte 0x03001600
lbl_08058758:
    cmp r1, #0
    bge lbl_08058768
    movs r5, #0
    ldrsh r0, [r3, r5]
    cmp r1, r0
    bgt lbl_08058768
    subs r0, r1, #4
    strh r0, [r3]
lbl_08058768:
    ldrh r0, [r2, #0x14]
    ldr r1, lbl_08058784 @ =0x03001602
    ldrh r1, [r1]
    subs r1, r0, r1
    cmp r1, #0
    ble lbl_08058788
    movs r2, #6
    ldrsh r0, [r4, r2]
    cmp r1, r0
    blt lbl_080587a2
    adds r0, r1, #4
    strh r0, [r4, #6]
    b lbl_080587a2
    .align 2, 0
lbl_08058784: .4byte 0x03001602
lbl_08058788:
    cmp r1, #0
    bge lbl_080587a2
    movs r5, #4
    ldrsh r0, [r4, r5]
    cmp r1, r0
    bgt lbl_080587a2
    subs r0, r1, #4
    strh r0, [r4, #4]
    b lbl_080587a2
lbl_0805879a:
    ldr r0, [r2, #8]
    ldr r1, [r2, #0xc]
    str r0, [r3]
    str r1, [r3, #4]
lbl_080587a2:
    ldr r0, lbl_080587c4 @ =0x0300003d
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805881e
    ldr r0, lbl_080587c8 @ =0x0300007f
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_080587d0
    ldr r0, lbl_080587cc @ =0x03000c72
    movs r1, #0
    ldrsh r0, [r0, r1]
    cmp r0, #6
    bne lbl_080587d0
    mov r0, sp
    bl sub_08059008
    b lbl_080587ea
    .align 2, 0
lbl_080587c4: .4byte 0x0300003d
lbl_080587c8: .4byte 0x0300007f
lbl_080587cc: .4byte 0x03000c72
lbl_080587d0:
    ldr r0, lbl_080587e0 @ =0x030000bc
    ldrb r0, [r0, #5]
    cmp r0, #3
    bne lbl_080587e4
    mov r0, sp
    bl process_scrolls
    b lbl_080587ea
    .align 2, 0
lbl_080587e0: .4byte 0x030000bc
lbl_080587e4:
    mov r0, sp
    bl ScrollWithNoScrolls
lbl_080587ea:
    mov r0, sp
    bl ScrollBG2
    ldr r0, lbl_08058828 @ =0x030054f4
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_08058808
    ldr r0, lbl_0805882c @ =0x030000bc
    ldrb r1, [r0, #1]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_08058808
    bl automatic_scroll_bg0
lbl_08058808:
    mov r0, sp
    bl update_effect_and_haze_pos
    bl ScrollBG3
    ldr r0, lbl_08058830 @ =0x030054ec
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805881e
    bl automatic_scroll_bg3
lbl_0805881e:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058828: .4byte 0x030054f4
lbl_0805882c: .4byte 0x030000bc
lbl_08058830: .4byte 0x030054ec

    thumb_func_start ScrollWithNoScrolls
ScrollWithNoScrolls: @ 0x08058834
    push {r4, lr}
    adds r4, r0, #0
    bl ScrollWithNoScrollsX
    adds r0, r4, #0
    bl ScrollWithNoScrollsY
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start ScrollWithNoScrollsY
ScrollWithNoScrollsY: @ 0x08058848
    push {r4, lr}
    adds r4, r0, #0
    ldr r0, lbl_08058860 @ =0x03000100
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805886c
    ldr r2, lbl_08058864 @ =0x030013d4
    ldrh r1, [r2, #0x14]
    ldr r0, lbl_08058868 @ =0x03001602
    ldrh r0, [r0]
    subs r1, r1, r0
    b lbl_08058870
    .align 2, 0
lbl_08058860: .4byte 0x03000100
lbl_08058864: .4byte 0x030013d4
lbl_08058868: .4byte 0x03001602
lbl_0805886c:
    movs r1, #0
    ldr r2, lbl_08058898 @ =0x030013d4
lbl_08058870:
    ldrb r2, [r2]
    adds r0, r2, #0
    subs r0, #0x11
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #1
    bls lbl_08058882
    cmp r2, #0x1c
    bne lbl_080588a4
lbl_08058882:
    ldr r1, lbl_0805889c @ =0x03005515
    movs r0, #0
    ldrsb r0, [r1, r0]
    adds r0, #4
    adds r3, r1, #0
    cmp r0, #0x1f
    bgt lbl_080588a0
    ldrb r0, [r3]
    adds r0, #2
    b lbl_080588c6
    .align 2, 0
lbl_08058898: .4byte 0x030013d4
lbl_0805889c: .4byte 0x03005515
lbl_080588a0:
    movs r0, #0x20
    b lbl_080588c6
lbl_080588a4:
    ldr r3, lbl_080588c0 @ =0x03005515
    cmp r1, #0
    bge lbl_080588c8
    movs r0, #0
    ldrsb r0, [r3, r0]
    adds r0, r0, r1
    cmp r0, #0
    ble lbl_080588c4
    lsrs r0, r1, #0x1f
    adds r0, r1, r0
    asrs r0, r0, #1
    ldrb r1, [r3]
    adds r0, r0, r1
    b lbl_080588c6
    .align 2, 0
lbl_080588c0: .4byte 0x03005515
lbl_080588c4:
    movs r0, #0
lbl_080588c6:
    strb r0, [r3]
lbl_080588c8:
    ldrh r2, [r4, #2]
    movs r1, #0
    ldrsb r1, [r3, r1]
    movs r0, #0x80
    lsls r0, r0, #2
    subs r0, r0, r1
    cmp r2, r0
    bge lbl_080588dc
    movs r3, #0x80
    b lbl_080588fe
lbl_080588dc:
    ldr r0, lbl_080588f0 @ =0x0300009c
    ldrh r0, [r0, #0xe]
    lsls r0, r0, #6
    ldr r3, lbl_080588f4 @ =0xfffffe80
    adds r0, r0, r3
    subs r0, r0, r1
    cmp r2, r0
    ble lbl_080588f8
    adds r0, r0, r3
    b lbl_080588fc
    .align 2, 0
lbl_080588f0: .4byte 0x0300009c
lbl_080588f4: .4byte 0xfffffe80
lbl_080588f8:
    ldr r4, lbl_08058918 @ =0xfffffe80
    adds r0, r2, r4
lbl_080588fc:
    adds r3, r0, r1
lbl_080588fe:
    ldr r2, lbl_0805891c @ =0x03000144
    strh r3, [r2, #2]
    ldr r1, lbl_08058920 @ =0x030013ba
    ldrh r0, [r1]
    subs r3, r3, r0
    cmp r3, #0
    ble lbl_08058928
    ldr r0, lbl_08058924 @ =0x03005714
    movs r4, #6
    ldrsh r0, [r0, r4]
    cmp r0, r3
    bge lbl_08058934
    b lbl_08058932
    .align 2, 0
lbl_08058918: .4byte 0xfffffe80
lbl_0805891c: .4byte 0x03000144
lbl_08058920: .4byte 0x030013ba
lbl_08058924: .4byte 0x03005714
lbl_08058928:
    ldr r0, lbl_08058944 @ =0x03005714
    movs r4, #4
    ldrsh r0, [r0, r4]
    cmp r3, r0
    bge lbl_08058934
lbl_08058932:
    adds r3, r0, #0
lbl_08058934:
    strb r3, [r2, #5]
    ldrh r0, [r1]
    adds r0, r0, r3
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058944: .4byte 0x03005714

    thumb_func_start ScrollWithNoScrollsX
ScrollWithNoScrollsX: @ 0x08058948
    push {r4, lr}
    adds r2, r0, #0
    movs r3, #0
    ldr r0, lbl_08058970 @ =0x03000100
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08058988
    ldr r0, lbl_08058974 @ =0x03001588
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_08058988
    ldr r0, lbl_08058978 @ =0x030013d4
    ldrh r1, [r0, #0xe]
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_0805897c
    movs r3, #0x80
    b lbl_08058988
    .align 2, 0
lbl_08058970: .4byte 0x03000100
lbl_08058974: .4byte 0x03001588
lbl_08058978: .4byte 0x030013d4
lbl_0805897c:
    movs r0, #0x20
    ands r0, r1
    cmp r0, #0
    beq lbl_08058988
    movs r3, #0x80
    rsbs r3, r3, #0
lbl_08058988:
    ldr r0, lbl_080589a0 @ =0x03005516
    strh r3, [r0]
    ldrh r2, [r2]
    movs r3, #0
    ldrsh r1, [r0, r3]
    movs r0, #0x98
    lsls r0, r0, #2
    subs r0, r0, r1
    cmp r2, r0
    bge lbl_080589a4
    movs r3, #0x80
    b lbl_080589ce
    .align 2, 0
lbl_080589a0: .4byte 0x03005516
lbl_080589a4:
    ldr r0, lbl_080589bc @ =0x0300009c
    ldrh r0, [r0, #0xc]
    lsls r0, r0, #6
    ldr r4, lbl_080589c0 @ =0xfffffda0
    adds r0, r0, r4
    subs r0, r0, r1
    cmp r2, r0
    ble lbl_080589c8
    ldr r2, lbl_080589c4 @ =0xfffffe20
    adds r0, r0, r2
    b lbl_080589cc
    .align 2, 0
lbl_080589bc: .4byte 0x0300009c
lbl_080589c0: .4byte 0xfffffda0
lbl_080589c4: .4byte 0xfffffe20
lbl_080589c8:
    ldr r3, lbl_080589e8 @ =0xfffffe20
    adds r0, r2, r3
lbl_080589cc:
    adds r3, r0, r1
lbl_080589ce:
    ldr r2, lbl_080589ec @ =0x03000144
    strh r3, [r2]
    ldr r1, lbl_080589f0 @ =0x030013b8
    ldrh r0, [r1]
    subs r3, r3, r0
    cmp r3, #0
    ble lbl_080589f8
    ldr r0, lbl_080589f4 @ =0x03005714
    movs r4, #2
    ldrsh r0, [r0, r4]
    cmp r0, r3
    bge lbl_08058a04
    b lbl_08058a02
    .align 2, 0
lbl_080589e8: .4byte 0xfffffe20
lbl_080589ec: .4byte 0x03000144
lbl_080589f0: .4byte 0x030013b8
lbl_080589f4: .4byte 0x03005714
lbl_080589f8:
    ldr r0, lbl_08058a14 @ =0x03005714
    movs r4, #0
    ldrsh r0, [r0, r4]
    cmp r3, r0
    bge lbl_08058a04
lbl_08058a02:
    adds r3, r0, #0
lbl_08058a04:
    strb r3, [r2, #4]
    ldrh r0, [r1]
    adds r0, r0, r3
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058a14: .4byte 0x03005714

    thumb_func_start update_effect_and_haze_pos
update_effect_and_haze_pos: @ 0x08058a18
    push {r4, r5, r6, r7, lr}
    adds r4, r0, #0
    movs r7, #0
    ldr r1, lbl_08058a4c @ =0x030000bc
    ldrb r2, [r1, #1]
    movs r0, #0x10
    ands r0, r2
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    mov ip, r1
    cmp r3, #0
    beq lbl_08058a64
    cmp r2, #0x11
    beq lbl_08058a36
    b lbl_08058c4e
lbl_08058a36:
    ldr r1, lbl_08058a50 @ =0x030013b4
    ldr r0, lbl_08058a54 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r0, r0, #1
    strh r0, [r1]
    ldr r1, lbl_08058a58 @ =0x030013b6
    ldr r0, lbl_08058a5c @ =0x030013ba
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r6, lbl_08058a60 @ =0x0300006e
    b lbl_08058c64
    .align 2, 0
lbl_08058a4c: .4byte 0x030000bc
lbl_08058a50: .4byte 0x030013b4
lbl_08058a54: .4byte 0x030013b8
lbl_08058a58: .4byte 0x030013b6
lbl_08058a5c: .4byte 0x030013ba
lbl_08058a60: .4byte 0x0300006e
lbl_08058a64:
    mov r0, ip
    ldrh r1, [r0, #0x12]
    ldr r0, lbl_08058ab0 @ =0x0000ffff
    cmp r1, r0
    bne lbl_08058a70
    b lbl_08058b80
lbl_08058a70:
    ldr r1, lbl_08058ab4 @ =0x030013b4
    ldr r0, lbl_08058ab8 @ =0x030013b8
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r2, lbl_08058abc @ =0x0300006e
    movs r1, #0
    ldrsh r0, [r2, r1]
    mov r3, ip
    ldrh r3, [r3, #0x12]
    adds r0, r0, r3
    ldr r1, lbl_08058ac0 @ =0x030013ba
    ldrh r1, [r1]
    subs r0, r0, r1
    asrs r5, r0, #2
    ldr r0, lbl_08058ac4 @ =0x0300551c
    ldrb r1, [r0]
    adds r6, r2, #0
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058af8
    ldr r0, lbl_08058ac8 @ =0x03001606
    ldrh r0, [r0]
    ldr r3, lbl_08058acc @ =0x0875fd54
    cmp r0, #0
    bne lbl_08058aec
    ldrb r1, [r2, #2]
    movs r0, #2
    ldrsb r0, [r2, r0]
    cmp r0, #0
    beq lbl_08058ad0
    subs r0, r1, #1
    b lbl_08058aea
    .align 2, 0
lbl_08058ab0: .4byte 0x0000ffff
lbl_08058ab4: .4byte 0x030013b4
lbl_08058ab8: .4byte 0x030013b8
lbl_08058abc: .4byte 0x0300006e
lbl_08058ac0: .4byte 0x030013ba
lbl_08058ac4: .4byte 0x0300551c
lbl_08058ac8: .4byte 0x03001606
lbl_08058acc: .4byte 0x0875fd54
lbl_08058ad0:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #7
    bls lbl_08058ae0
    strb r7, [r2, #1]
lbl_08058ae0:
    ldrb r0, [r2, #1]
    lsls r0, r0, #1
    adds r1, r3, #1
    adds r0, r0, r1
    ldrb r0, [r0]
lbl_08058aea:
    strb r0, [r2, #2]
lbl_08058aec:
    ldrb r0, [r2, #1]
    lsls r0, r0, #1
    adds r0, r0, r3
    movs r1, #0
    ldrsb r1, [r0, r1]
    b lbl_08058afa
lbl_08058af8:
    movs r1, #0
lbl_08058afa:
    adds r0, r1, #0
    subs r0, #8
    lsls r0, r0, #2
    strb r0, [r2, #3]
    adds r5, r5, r1
    cmp r5, #0
    bge lbl_08058b3c
    ldr r2, lbl_08058b30 @ =0x03000088
    ldrh r3, [r2, #0x12]
    movs r4, #0xc0
    lsls r4, r4, #8
    adds r0, r4, #0
    ands r0, r3
    cmp r0, #0
    beq lbl_08058b62
    ldrh r1, [r2, #0xa]
    adds r0, r4, #0
    ands r0, r1
    cmp r0, #0
    beq lbl_08058b62
    ldr r0, lbl_08058b34 @ =0x00003fff
    ands r0, r3
    strh r0, [r2, #0x12]
    ldr r1, lbl_08058b38 @ =0x04000008
    strh r0, [r1]
    b lbl_08058b62
    .align 2, 0
lbl_08058b30: .4byte 0x03000088
lbl_08058b34: .4byte 0x00003fff
lbl_08058b38: .4byte 0x04000008
lbl_08058b3c:
    ldr r2, lbl_08058b74 @ =0x03000088
    ldrh r3, [r2, #0x12]
    movs r1, #0xc0
    lsls r1, r1, #8
    adds r0, r1, #0
    ands r0, r3
    cmp r0, #0
    bne lbl_08058b62
    ldrh r0, [r2, #0xa]
    ands r1, r0
    cmp r1, #0
    beq lbl_08058b62
    adds r0, r1, #0
    orrs r0, r3
    strh r0, [r2, #0x12]
    ldr r2, lbl_08058b78 @ =0x04000008
    ldrh r1, [r2]
    orrs r0, r1
    strh r0, [r2]
lbl_08058b62:
    movs r0, #0x80
    lsls r0, r0, #1
    cmp r5, r0
    ble lbl_08058b6c
    adds r5, r0, #0
lbl_08058b6c:
    ldr r1, lbl_08058b7c @ =0x030013b6
    rsbs r0, r5, #0
    lsls r0, r0, #2
    b lbl_08058c62
    .align 2, 0
lbl_08058b74: .4byte 0x03000088
lbl_08058b78: .4byte 0x04000008
lbl_08058b7c: .4byte 0x030013b6
lbl_08058b80:
    movs r7, #1
    mov r1, ip
    ldrb r0, [r1, #1]
    cmp r0, #0x43
    beq lbl_08058bb0
    cmp r0, #0x43
    bgt lbl_08058b94
    cmp r0, #0x41
    beq lbl_08058b9e
    b lbl_08058c4c
lbl_08058b94:
    cmp r0, #0x44
    beq lbl_08058bdc
    cmp r0, #0x45
    beq lbl_08058bb0
    b lbl_08058c4c
lbl_08058b9e:
    ldr r0, lbl_08058ba8 @ =0x030013b4
    strh r3, [r0]
    ldr r0, lbl_08058bac @ =0x030013b6
    strh r3, [r0]
    b lbl_08058c4e
    .align 2, 0
lbl_08058ba8: .4byte 0x030013b4
lbl_08058bac: .4byte 0x030013b6
lbl_08058bb0:
    ldr r2, lbl_08058bcc @ =0x030013b4
    ldr r0, lbl_08058bd0 @ =0x030013b8
    ldrh r0, [r0]
    ldrh r1, [r4]
    subs r0, r0, r1
    strh r0, [r2]
    ldr r2, lbl_08058bd4 @ =0x030013b6
    ldr r0, lbl_08058bd8 @ =0x030013ba
    ldrh r0, [r0]
    ldrh r1, [r4, #2]
    subs r0, r0, r1
    adds r0, #0x40
    strh r0, [r2]
    b lbl_08058c4e
    .align 2, 0
lbl_08058bcc: .4byte 0x030013b4
lbl_08058bd0: .4byte 0x030013b8
lbl_08058bd4: .4byte 0x030013b6
lbl_08058bd8: .4byte 0x030013ba
lbl_08058bdc:
    movs r5, #0
    ldr r6, lbl_08058c38 @ =0x030013b4
    ldr r0, lbl_08058c3c @ =0x030013b8
    ldr r3, lbl_08058c40 @ =0x030000f8
    ldrh r1, [r0]
    ldrh r0, [r3]
    subs r1, r1, r0
    movs r2, #0x80
    lsls r2, r2, #4
    adds r0, r1, r2
    strh r0, [r6]
    ldr r4, lbl_08058c44 @ =0x030013b6
    ldr r0, lbl_08058c48 @ =0x030013ba
    ldrh r2, [r0]
    ldrh r0, [r3, #2]
    subs r2, r2, r0
    movs r3, #0x88
    lsls r3, r3, #3
    adds r0, r2, r3
    strh r0, [r4]
    movs r0, #0xa0
    lsls r0, r0, #3
    adds r1, r1, r0
    lsls r1, r1, #0x10
    movs r0, #0xc0
    lsls r0, r0, #0x13
    cmp r1, r0
    bls lbl_08058c16
    movs r5, #1
lbl_08058c16:
    movs r1, #0xd0
    lsls r1, r1, #2
    adds r0, r2, r1
    lsls r0, r0, #0x10
    movs r1, #0xc0
    lsls r1, r1, #0x12
    cmp r0, r1
    bls lbl_08058c28
    movs r5, #1
lbl_08058c28:
    cmp r5, #0
    beq lbl_08058c4e
    movs r2, #0x80
    lsls r2, r2, #2
    adds r0, r2, #0
    strh r0, [r6]
    b lbl_08058c4e
    .align 2, 0
lbl_08058c38: .4byte 0x030013b4
lbl_08058c3c: .4byte 0x030013b8
lbl_08058c40: .4byte 0x030000f8
lbl_08058c44: .4byte 0x030013b6
lbl_08058c48: .4byte 0x030013ba
lbl_08058c4c:
    movs r7, #0
lbl_08058c4e:
    ldr r6, lbl_08058c78 @ =0x0300006e
    cmp r7, #0
    bne lbl_08058c64
    ldr r1, lbl_08058c7c @ =0x030013b6
    ldr r0, lbl_08058c80 @ =0x030013ba
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058c84 @ =0x030013b4
    ldr r0, lbl_08058c88 @ =0x030013b8
    ldrh r0, [r0]
lbl_08058c62:
    strh r0, [r1]
lbl_08058c64:
    mov r3, ip
    ldrh r1, [r3, #0x12]
    ldr r0, lbl_08058c8c @ =0x0000ffff
    cmp r1, r0
    bne lbl_08058c94
    ldr r1, lbl_08058c90 @ =0x0300006c
    movs r0, #0
    strh r0, [r1]
    strh r0, [r6]
    b lbl_08058cb2
    .align 2, 0
lbl_08058c78: .4byte 0x0300006e
lbl_08058c7c: .4byte 0x030013b6
lbl_08058c80: .4byte 0x030013ba
lbl_08058c84: .4byte 0x030013b4
lbl_08058c88: .4byte 0x030013b8
lbl_08058c8c: .4byte 0x0000ffff
lbl_08058c90: .4byte 0x0300006c
lbl_08058c94:
    ldr r0, lbl_08058cb8 @ =0x0300551c
    ldrb r0, [r0, #3]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov r1, ip
    ldrh r1, [r1, #0x12]
    adds r0, r0, r1
    movs r2, #0
    ldrsh r1, [r6, r2]
    adds r5, r0, r1
    cmp r5, #0
    bge lbl_08058cae
    movs r5, #0
lbl_08058cae:
    ldr r0, lbl_08058cbc @ =0x0300006c
    strh r5, [r0]
lbl_08058cb2:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058cb8: .4byte 0x0300551c
lbl_08058cbc: .4byte 0x0300006c

    thumb_func_start automatic_scroll_bg0
automatic_scroll_bg0: @ 0x08058cc0
    push {lr}
    ldr r0, lbl_08058cd4 @ =0x030054f4
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058cd8
    ldrb r1, [r2, #1]
    movs r0, #7
    b lbl_08058ce0
    .align 2, 0
lbl_08058cd4: .4byte 0x030054f4
lbl_08058cd8:
    cmp r1, #2
    bne lbl_08058cee
    ldrb r1, [r2, #1]
    movs r0, #3
lbl_08058ce0:
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
    b lbl_08058d16
lbl_08058cee:
    cmp r1, #3
    bne lbl_08058d02
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #6]
    adds r0, #1
    b lbl_08058d14
lbl_08058d02:
    cmp r1, #4
    bne lbl_08058d16
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058d16
    ldrh r0, [r2, #6]
    subs r0, #1
lbl_08058d14:
    strh r0, [r2, #6]
lbl_08058d16:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    pop {r0}
    bx r0

    thumb_func_start get_BG3Scrolling_values
get_BG3Scrolling_values: @ 0x08058d20
    push {lr}
    movs r3, #0
    movs r2, #0
    ldr r0, lbl_08058d38 @ =0x030000bc
    ldrb r0, [r0, #6]
    cmp r0, #0xa
    bhi lbl_08058d96
    lsls r0, r0, #2
    ldr r1, lbl_08058d3c @ =lbl_08058d40
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08058d38: .4byte 0x030000bc
lbl_08058d3c: .4byte lbl_08058d40
lbl_08058d40: @ jump table
    .4byte lbl_08058d96 @ case 0
    .4byte lbl_08058d6c @ case 1
    .4byte lbl_08058d70 @ case 2
    .4byte lbl_08058d76 @ case 3
    .4byte lbl_08058d7c @ case 4
    .4byte lbl_08058d82 @ case 5
    .4byte lbl_08058d88 @ case 6
    .4byte lbl_08058d92 @ case 7
    .4byte lbl_08058d92 @ case 8
    .4byte lbl_08058d8e @ case 9
    .4byte lbl_08058d88 @ case 10
lbl_08058d6c:
    movs r2, #2
    b lbl_08058d94
lbl_08058d70:
    movs r2, #0
    movs r3, #2
    b lbl_08058d96
lbl_08058d76:
    movs r2, #2
    movs r3, #2
    b lbl_08058d96
lbl_08058d7c:
    movs r2, #1
    movs r3, #2
    b lbl_08058d96
lbl_08058d82:
    movs r2, #2
    movs r3, #1
    b lbl_08058d96
lbl_08058d88:
    movs r2, #1
    movs r3, #1
    b lbl_08058d96
lbl_08058d8e:
    movs r2, #3
    b lbl_08058d94
lbl_08058d92:
    movs r2, #1
lbl_08058d94:
    movs r3, #0
lbl_08058d96:
    lsls r0, r3, #0x10
    orrs r0, r2
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start ScrollBG3
ScrollBG3: @ 0x08058da0
    push {lr}
    bl get_BG3Scrolling_values
    adds r3, r0, #0
    movs r0, #0xff
    ands r0, r3
    asrs r3, r3, #0x10
    cmp r0, #0
    beq lbl_08058df0
    cmp r0, #1
    bne lbl_08058dc8
    ldr r1, lbl_08058dc0 @ =0x030013c0
    ldr r0, lbl_08058dc4 @ =0x030013b8
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058dee
    .align 2, 0
lbl_08058dc0: .4byte 0x030013c0
lbl_08058dc4: .4byte 0x030013b8
lbl_08058dc8:
    cmp r0, #2
    bne lbl_08058de0
    ldr r1, lbl_08058dd8 @ =0x030013c0
    ldr r0, lbl_08058ddc @ =0x030013b8
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058dee
    .align 2, 0
lbl_08058dd8: .4byte 0x030013c0
lbl_08058ddc: .4byte 0x030013b8
lbl_08058de0:
    cmp r0, #3
    bne lbl_08058df0
    ldr r1, lbl_08058e20 @ =0x030013c0
    ldr r0, lbl_08058e24 @ =0x030013b8
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058dee:
    strh r0, [r1]
lbl_08058df0:
    ldr r1, lbl_08058e28 @ =0x030000bc
    ldrb r0, [r1, #0x1a]
    cmp r0, #0
    beq lbl_08058e6c
    ldr r0, lbl_08058e2c @ =0x0300009c
    ldrh r0, [r0, #0x1e]
    subs r0, #0xc
    lsls r2, r0, #6
    ldrb r1, [r1, #0x19]
    movs r0, #2
    ands r0, r1
    movs r1, #0x80
    lsls r1, r1, #3
    cmp r0, #0
    beq lbl_08058e12
    movs r1, #0x80
    lsls r1, r1, #4
lbl_08058e12:
    ldr r0, lbl_08058e30 @ =0xfffffd80
    adds r1, r1, r0
    cmp r3, #0
    bne lbl_08058e34
    movs r1, #0
    movs r2, #0
    b lbl_08058e4c
    .align 2, 0
lbl_08058e20: .4byte 0x030013c0
lbl_08058e24: .4byte 0x030013b8
lbl_08058e28: .4byte 0x030000bc
lbl_08058e2c: .4byte 0x0300009c
lbl_08058e30: .4byte 0xfffffd80
lbl_08058e34:
    cmp r3, #1
    bne lbl_08058e44
    ldr r0, lbl_08058e40 @ =0x030013ba
    ldrh r0, [r0]
    subs r2, r2, r0
    b lbl_08058e4c
    .align 2, 0
lbl_08058e40: .4byte 0x030013ba
lbl_08058e44:
    ldr r0, lbl_08058e58 @ =0x030013ba
    ldrh r0, [r0]
    subs r0, r2, r0
    asrs r2, r0, #2
lbl_08058e4c:
    subs r1, r1, r2
    cmp r1, #0
    ble lbl_08058e60
    ldr r0, lbl_08058e5c @ =0x030013c2
    strh r1, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e58: .4byte 0x030013ba
lbl_08058e5c: .4byte 0x030013c2
lbl_08058e60:
    ldr r1, lbl_08058e68 @ =0x030013c2
    movs r0, #0
    b lbl_08058eb6
    .align 2, 0
lbl_08058e68: .4byte 0x030013c2
lbl_08058e6c:
    cmp r3, #0
    bne lbl_08058e7c
    ldr r0, lbl_08058e78 @ =0x030013c2
    strh r3, [r0]
    b lbl_08058eb8
    .align 2, 0
lbl_08058e78: .4byte 0x030013c2
lbl_08058e7c:
    cmp r3, #1
    bne lbl_08058e94
    ldr r1, lbl_08058e8c @ =0x030013c2
    ldr r0, lbl_08058e90 @ =0x030013ba
    ldrh r0, [r0]
    subs r0, #0x80
    b lbl_08058eb6
    .align 2, 0
lbl_08058e8c: .4byte 0x030013c2
lbl_08058e90: .4byte 0x030013ba
lbl_08058e94:
    cmp r3, #2
    bne lbl_08058eac
    ldr r1, lbl_08058ea4 @ =0x030013c2
    ldr r0, lbl_08058ea8 @ =0x030013ba
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058eb6
    .align 2, 0
lbl_08058ea4: .4byte 0x030013c2
lbl_08058ea8: .4byte 0x030013ba
lbl_08058eac:
    ldr r1, lbl_08058ebc @ =0x030013c2
    ldr r0, lbl_08058ec0 @ =0x030013ba
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058eb6:
    strh r0, [r1]
lbl_08058eb8:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058ebc: .4byte 0x030013c2
lbl_08058ec0: .4byte 0x030013ba

    thumb_func_start sub_08058ec4
sub_08058ec4: @ 0x08058ec4
    push {lr}
    bl get_BG3Scrolling_values
    adds r1, r0, #0
    movs r0, #0xff
    ands r1, r0
    cmp r1, #0
    bne lbl_08058ee0
    ldr r0, lbl_08058edc @ =0x030013c0
    strh r1, [r0]
    b lbl_08058f08
    .align 2, 0
lbl_08058edc: .4byte 0x030013c0
lbl_08058ee0:
    cmp r1, #2
    bne lbl_08058ef8
    ldr r1, lbl_08058ef0 @ =0x030013c0
    ldr r0, lbl_08058ef4 @ =0x030013b8
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #1
    b lbl_08058f06
    .align 2, 0
lbl_08058ef0: .4byte 0x030013c0
lbl_08058ef4: .4byte 0x030013b8
lbl_08058ef8:
    cmp r1, #3
    bne lbl_08058f08
    ldr r1, lbl_08058f0c @ =0x030013c0
    ldr r0, lbl_08058f10 @ =0x030013b8
    ldrh r0, [r0]
    subs r0, #0x80
    asrs r0, r0, #2
lbl_08058f06:
    strh r0, [r1]
lbl_08058f08:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058f0c: .4byte 0x030013c0
lbl_08058f10: .4byte 0x030013b8

    thumb_func_start automatic_scroll_bg3
automatic_scroll_bg3: @ 0x08058f14
    push {lr}
    ldr r0, lbl_08058f3c @ =0x030054ec
    ldrb r1, [r0]
    adds r2, r0, #0
    cmp r1, #1
    bne lbl_08058f30
    ldrb r1, [r2, #1]
    movs r0, #7
    ands r0, r1
    cmp r0, #0
    bne lbl_08058f30
    ldrh r0, [r2, #4]
    adds r0, #1
    strh r0, [r2, #4]
lbl_08058f30:
    ldrb r0, [r2, #1]
    adds r0, #1
    strb r0, [r2, #1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_08058f3c: .4byte 0x030054ec

    thumb_func_start ScrollBG2
ScrollBG2: @ 0x08058f40
    push {lr}
    ldr r0, lbl_08058f78 @ =0x030000bc
    ldrb r2, [r0, #3]
    movs r0, #0x10
    ands r0, r2
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    cmp r1, #0
    beq lbl_08058ff4
    movs r0, #0x20
    ands r0, r2
    cmp r0, #0
    beq lbl_08058fd0
    lsls r0, r2, #0x18
    lsrs r0, r0, #0x18
    cmp r0, #0x31
    bne lbl_08058fd0
    ldr r2, lbl_08058f7c @ =0x030013b8
    ldr r1, lbl_08058f80 @ =0x030000fc
    movs r3, #0
    ldrsh r0, [r1, r3]
    ldrh r2, [r2]
    adds r2, r0, r2
    adds r3, r1, #0
    cmp r2, #0
    bge lbl_08058f84
    movs r2, #0
    b lbl_08058f92
    .align 2, 0
lbl_08058f78: .4byte 0x030000bc
lbl_08058f7c: .4byte 0x030013b8
lbl_08058f80: .4byte 0x030000fc
lbl_08058f84:
    ldr r0, lbl_08058fa8 @ =0x0300009c
    ldrh r0, [r0, #0x14]
    subs r0, #0xf
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058f92
    adds r2, r0, #0
lbl_08058f92:
    ldr r0, lbl_08058fac @ =0x030013bc
    strh r2, [r0]
    ldr r1, lbl_08058fb0 @ =0x030013ba
    movs r2, #2
    ldrsh r0, [r3, r2]
    ldrh r1, [r1]
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_08058fb4
    movs r2, #0
    b lbl_08058fc2
    .align 2, 0
lbl_08058fa8: .4byte 0x0300009c
lbl_08058fac: .4byte 0x030013bc
lbl_08058fb0: .4byte 0x030013ba
lbl_08058fb4:
    ldr r0, lbl_08058fc8 @ =0x0300009c
    ldrh r0, [r0, #0x16]
    subs r0, #0xa
    lsls r0, r0, #6
    cmp r0, r2
    bge lbl_08058fc2
    adds r2, r0, #0
lbl_08058fc2:
    ldr r0, lbl_08058fcc @ =0x030013be
    strh r2, [r0]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fc8: .4byte 0x0300009c
lbl_08058fcc: .4byte 0x030013be
lbl_08058fd0:
    ldr r1, lbl_08058fe4 @ =0x030013bc
    ldr r0, lbl_08058fe8 @ =0x030013b8
    ldrh r0, [r0]
    strh r0, [r1]
    ldr r1, lbl_08058fec @ =0x030013be
    ldr r0, lbl_08058ff0 @ =0x030013ba
    ldrh r0, [r0]
    strh r0, [r1]
    b lbl_08058ffc
    .align 2, 0
lbl_08058fe4: .4byte 0x030013bc
lbl_08058fe8: .4byte 0x030013b8
lbl_08058fec: .4byte 0x030013be
lbl_08058ff0: .4byte 0x030013ba
lbl_08058ff4:
    ldr r0, lbl_08059000 @ =0x030013bc
    strh r1, [r0]
    ldr r0, lbl_08059004 @ =0x030013be
    strh r1, [r0]
lbl_08058ffc:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059000: .4byte 0x030013bc
lbl_08059004: .4byte 0x030013be

    thumb_func_start sub_08059008
sub_08059008: @ 0x08059008
    push {r4, lr}
    adds r4, r0, #0
    ldrh r1, [r4]
    ldr r0, lbl_0805901c @ =0x000001df
    cmp r1, r0
    bhi lbl_08059024
    ldr r1, lbl_08059020 @ =0x030013b8
    movs r0, #0
    b lbl_08059052
    .align 2, 0
lbl_0805901c: .4byte 0x000001df
lbl_08059020: .4byte 0x030013b8
lbl_08059024:
    ldrh r3, [r4]
    ldr r0, lbl_0805903c @ =0x0300009c
    ldrh r0, [r0, #0xc]
    lsls r2, r0, #6
    ldr r1, lbl_08059040 @ =0xfffffe20
    adds r0, r2, r1
    cmp r3, r0
    ble lbl_0805904c
    ldr r1, lbl_08059044 @ =0x030013b8
    ldr r3, lbl_08059048 @ =0xfffffc40
    adds r0, r2, r3
    b lbl_08059052
    .align 2, 0
lbl_0805903c: .4byte 0x0300009c
lbl_08059040: .4byte 0xfffffe20
lbl_08059044: .4byte 0x030013b8
lbl_08059048: .4byte 0xfffffc40
lbl_0805904c:
    ldr r1, lbl_08059064 @ =0x030013b8
    ldr r2, lbl_08059068 @ =0xfffffe20
    adds r0, r3, r2
lbl_08059052:
    strh r0, [r1]
    ldrh r1, [r4, #2]
    ldr r0, lbl_0805906c @ =0x0000017f
    cmp r1, r0
    bhi lbl_08059074
    ldr r1, lbl_08059070 @ =0x030013ba
    movs r0, #0
    b lbl_0805909e
    .align 2, 0
lbl_08059064: .4byte 0x030013b8
lbl_08059068: .4byte 0xfffffe20
lbl_0805906c: .4byte 0x0000017f
lbl_08059070: .4byte 0x030013ba
lbl_08059074:
    ldrh r3, [r4, #2]
    ldr r0, lbl_0805908c @ =0x0300009c
    ldrh r0, [r0, #0xe]
    lsls r2, r0, #6
    adds r0, r2, #0
    subs r0, #0xc0
    cmp r3, r0
    ble lbl_08059098
    ldr r1, lbl_08059090 @ =0x030013ba
    ldr r3, lbl_08059094 @ =0xfffffdc0
    adds r0, r2, r3
    b lbl_0805909e
    .align 2, 0
lbl_0805908c: .4byte 0x0300009c
lbl_08059090: .4byte 0x030013ba
lbl_08059094: .4byte 0xfffffdc0
lbl_08059098:
    ldr r1, lbl_080590a8 @ =0x030013ba
    ldr r2, lbl_080590ac @ =0xfffffe80
    adds r0, r3, r2
lbl_0805909e:
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080590a8: .4byte 0x030013ba
lbl_080590ac: .4byte 0xfffffe80

    thumb_func_start sub_080590b0
sub_080590b0: @ 0x080590b0
    push {r4, r5, r6, r7, lr}
    adds r5, r0, #0
    movs r7, #0
    ldrh r1, [r5, #4]
    adds r0, r1, #0
    subs r0, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x2f
    bls lbl_080590c6
    b lbl_080591ec
lbl_080590c6:
    adds r0, r1, #0
    subs r0, #0x10
    strb r0, [r5, #6]
    ldr r3, lbl_080590ec @ =0x03000079
    ldrb r0, [r3]
    cmp r0, #0xd
    bne lbl_080590f4
    ldr r1, lbl_080590f0 @ =0x083459f0
    ldrb r2, [r5, #6]
    lsls r0, r2, #2
    adds r0, r0, r1
    ldrb r0, [r0, #3]
    lsls r0, r0, #0x1c
    cmp r0, #0
    bne lbl_080590e6
    b lbl_080591ec
lbl_080590e6:
    movs r0, #0xc
    strb r0, [r3]
    b lbl_08059108
    .align 2, 0
lbl_080590ec: .4byte 0x03000079
lbl_080590f0: .4byte 0x083459f0
lbl_080590f4:
    ldrb r2, [r5, #6]
    cmp r0, #0xf
    bne lbl_08059108
    ldr r0, lbl_0805911c @ =0x083459f0
    lsls r1, r2, #2
    adds r1, r1, r0
    ldrb r0, [r1, #3]
    lsrs r0, r0, #4
    cmp r0, #0
    beq lbl_080591ec
lbl_08059108:
    movs r4, #1
    movs r6, #0
    subs r0, r2, #2
    cmp r0, #0x1c
    bhi lbl_080591e8
    lsls r0, r0, #2
    ldr r1, lbl_08059120 @ =lbl_08059124
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805911c: .4byte 0x083459f0
lbl_08059120: .4byte lbl_08059124
lbl_08059124: @ jump table
    .4byte lbl_08059198 @ case 0
    .4byte lbl_080591a6 @ case 1
    .4byte lbl_080591a0 @ case 2
    .4byte lbl_080591e8 @ case 3
    .4byte lbl_080591e8 @ case 4
    .4byte lbl_08059198 @ case 5
    .4byte lbl_080591a6 @ case 6
    .4byte lbl_080591a0 @ case 7
    .4byte lbl_080591e8 @ case 8
    .4byte lbl_080591ae @ case 9
    .4byte lbl_080591ae @ case 10
    .4byte lbl_080591b8 @ case 11
    .4byte lbl_080591b8 @ case 12
    .4byte lbl_080591b8 @ case 13
    .4byte lbl_080591b8 @ case 14
    .4byte lbl_080591b8 @ case 15
    .4byte lbl_080591b8 @ case 16
    .4byte lbl_080591c2 @ case 17
    .4byte lbl_080591b8 @ case 18
    .4byte lbl_080591b8 @ case 19
    .4byte lbl_080591ca @ case 20
    .4byte lbl_080591ce @ case 21
    .4byte lbl_080591d2 @ case 22
    .4byte lbl_080591d6 @ case 23
    .4byte lbl_080591da @ case 24
    .4byte lbl_080591de @ case 25
    .4byte lbl_080591e2 @ case 26
    .4byte lbl_080591e6 @ case 27
    .4byte lbl_080591c2 @ case 28
lbl_08059198:
    ldrh r0, [r5]
    subs r0, #1
    strh r0, [r5]
    b lbl_080591e8
lbl_080591a0:
    ldrh r0, [r5]
    subs r0, #1
    strh r0, [r5]
lbl_080591a6:
    ldrh r0, [r5, #2]
    subs r0, #1
    strh r0, [r5, #2]
    b lbl_080591e8
lbl_080591ae:
    adds r0, r5, #0
    bl sub_080597f4
    adds r4, r0, #0
    b lbl_080591e8
lbl_080591b8:
    adds r0, r5, #0
    bl sub_08059770
    adds r4, r0, #0
    b lbl_080591e8
lbl_080591c2:
    adds r0, r5, #0
    bl sub_08059770
    b lbl_080591ec
lbl_080591ca:
    movs r6, #0
    b lbl_080591e8
lbl_080591ce:
    movs r6, #1
    b lbl_080591e8
lbl_080591d2:
    movs r6, #2
    b lbl_080591e8
lbl_080591d6:
    movs r6, #3
    b lbl_080591e8
lbl_080591da:
    movs r6, #4
    b lbl_080591e8
lbl_080591de:
    movs r6, #5
    b lbl_080591e8
lbl_080591e2:
    movs r6, #6
    b lbl_080591e8
lbl_080591e6:
    movs r6, #7
lbl_080591e8:
    cmp r4, #0
    bne lbl_080591f0
lbl_080591ec:
    movs r0, #0
    b lbl_080592b0
lbl_080591f0:
    ldr r1, lbl_08059208 @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r0]
    cmp r1, #2
    beq lbl_08059222
    cmp r1, #2
    bgt lbl_0805920c
    cmp r1, #1
    beq lbl_08059216
    b lbl_080592ae
    .align 2, 0
lbl_08059208: .4byte 0x083459f0
lbl_0805920c:
    cmp r1, #3
    beq lbl_08059234
    cmp r1, #4
    beq lbl_08059274
    b lbl_080592ae
lbl_08059216:
    adds r0, r5, #0
    bl sub_080592c4
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
lbl_08059222:
    ldrb r0, [r0, #2]
    ldrh r1, [r5]
    ldrh r2, [r5, #2]
    movs r3, #0
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
lbl_08059234:
    adds r0, r5, #0
    bl sub_080597f4
    cmp r0, #0
    beq lbl_080592ae
    ldr r2, lbl_0805926c @ =0x030056bc
    ldr r1, lbl_08059270 @ =0x08345c28
    lsls r0, r6, #2
    adds r0, r0, r1
    ldrb r1, [r2]
    ldrb r0, [r0]
    ands r0, r1
    cmp r0, #0
    bne lbl_080592ae
    adds r0, r6, #0
    ldrh r1, [r5]
    ldrh r2, [r5, #2]
    bl start_bomb_chain
    cmp r0, #0
    beq lbl_080592ae
    adds r0, r5, #0
    bl sub_080592c4
    cmp r0, #0
    beq lbl_080592ae
    b lbl_080592ac
    .align 2, 0
lbl_0805926c: .4byte 0x030056bc
lbl_08059270: .4byte 0x08345c28
lbl_08059274:
    ldr r1, lbl_080592b8 @ =0x083459d0
    ldr r0, lbl_080592bc @ =0x03000079
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    movs r0, #0x1f
    ands r0, r1
    cmp r0, #0
    beq lbl_080592ae
    ldr r1, lbl_080592c0 @ =0x08345c48
    ldrh r0, [r5, #4]
    subs r0, #0x34
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrh r4, [r0, #4]
    cmp r4, #0
    beq lbl_080592ae
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_bg1_block_value
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_clipdata_block_value
lbl_080592ac:
    movs r7, #1
lbl_080592ae:
    adds r0, r7, #0
lbl_080592b0:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080592b8: .4byte 0x083459d0
lbl_080592bc: .4byte 0x03000079
lbl_080592c0: .4byte 0x08345c48

    thumb_func_start sub_080592c4
sub_080592c4: @ 0x080592c4
    push {r4, r5, lr}
    adds r5, r0, #0
    movs r2, #0
    ldr r1, lbl_080592e4 @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r4, [r0, #1]
    cmp r4, #4
    bhi lbl_0805930c
    lsls r0, r4, #2
    ldr r1, lbl_080592e8 @ =lbl_080592ec
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080592e4: .4byte 0x083459f0
lbl_080592e8: .4byte lbl_080592ec
lbl_080592ec: @ jump table
    .4byte lbl_0805930e @ case 0
    .4byte lbl_0805930e @ case 1
    .4byte lbl_08059300 @ case 2
    .4byte lbl_08059300 @ case 3
    .4byte lbl_0805930e @ case 4
lbl_08059300:
    ldrh r0, [r5]
    ldrh r1, [r5, #2]
    bl sub_08059480
    adds r2, r0, #0
    b lbl_0805930e
lbl_0805930c:
    movs r2, #1
lbl_0805930e:
    cmp r2, #0
    bne lbl_08059328
    ldr r0, lbl_08059324 @ =0x0875fd64
    lsls r1, r4, #2
    adds r1, r1, r0
    ldr r1, [r1]
    adds r0, r5, #0
    bl _call_via_r1
    adds r2, r0, #0
    b lbl_0805932a
    .align 2, 0
lbl_08059324: .4byte 0x0875fd64
lbl_08059328:
    movs r0, #0
lbl_0805932a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_08059330
sub_08059330: @ 0x08059330
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    ldr r3, lbl_08059364 @ =0x083459f0
    ldrb r2, [r4, #6]
    lsls r2, r2, #2
    adds r2, r2, r3
    ldrb r2, [r2, #2]
    bl store_broken_non_reform_block
    ldr r2, lbl_08059368 @ =0x0300009c
    ldrh r1, [r4, #2]
    ldrh r0, [r2, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059364: .4byte 0x083459f0
lbl_08059368: .4byte 0x0300009c

    thumb_func_start destroy_single_breakable_block
destroy_single_breakable_block: @ 0x0805936c
    push {r4, lr}
    adds r4, r0, #0
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    ldr r3, lbl_080593a0 @ =0x083459f0
    ldrb r2, [r4, #6]
    lsls r2, r2, #2
    adds r2, r2, r3
    ldrb r2, [r2, #2]
    bl store_broken_non_reform_block
    ldr r2, lbl_080593a4 @ =0x0300009c
    ldrh r1, [r4, #2]
    ldrh r0, [r2, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    movs r0, #1
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080593a0: .4byte 0x083459f0
lbl_080593a4: .4byte 0x0300009c

    thumb_func_start destroy_square_block
destroy_square_block: @ 0x080593a8
    push {r4, r5, r6, lr}
    mov r6, r8
    push {r6}
    adds r4, r0, #0
    ldr r1, lbl_08059470 @ =0x083459f0
    ldrb r0, [r4, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r6, [r0, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldr r5, lbl_08059474 @ =0x0300009c
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    movs r1, #0
    strh r1, [r0]
    ldrh r0, [r4]
    adds r0, #1
    movs r1, #0
    mov r8, r1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    adds r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldrh r0, [r4, #2]
    subs r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r1, [r4]
    adds r0, r0, r1
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldrh r0, [r4]
    subs r0, #1
    strh r0, [r4]
    ldrh r0, [r4, #2]
    adds r0, #1
    strh r0, [r4, #2]
    ldrh r0, [r4]
    ldrh r1, [r4, #2]
    adds r2, r6, #0
    bl store_broken_non_reform_block
    ldrh r1, [r4, #2]
    ldrh r0, [r5, #0x1c]
    muls r0, r1, r0
    ldrh r4, [r4]
    adds r0, r0, r4
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, r8
    strh r1, [r0]
    ldr r0, lbl_08059478 @ =0x03000079
    ldrb r0, [r0]
    cmp r0, #0xc
    beq lbl_08059464
    ldr r0, lbl_0805947c @ =0x00000137
    bl SoundPlayNotAlreadyPlaying
lbl_08059464:
    movs r0, #1
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059470: .4byte 0x083459f0
lbl_08059474: .4byte 0x0300009c
lbl_08059478: .4byte 0x03000079
lbl_0805947c: .4byte 0x00000137

    thumb_func_start sub_08059480
sub_08059480: @ 0x08059480
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    ldr r1, lbl_080594a0 @ =0x03000054
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0805949a
    adds r0, r4, #0
    muls r0, r5, r0
    cmp r0, #0
    bne lbl_080594a4
lbl_0805949a:
    movs r0, #0
    b lbl_080594f6
    .align 2, 0
lbl_080594a0: .4byte 0x03000054
lbl_080594a4:
    movs r3, #1
    ldrb r0, [r1]
    lsls r1, r0, #9
    ldr r6, lbl_080594c8 @ =0x02035c00
    adds r2, r1, r6
    ldr r1, lbl_080594cc @ =0x0300005b
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r1, r0, #1
    ldr r0, lbl_080594d0 @ =0x000001fb
    cmp r1, r0
    bgt lbl_080594e6
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_080594d4
    movs r3, #0
    b lbl_080594ea
    .align 2, 0
lbl_080594c8: .4byte 0x02035c00
lbl_080594cc: .4byte 0x0300005b
lbl_080594d0: .4byte 0x000001fb
lbl_080594d4:
    adds r1, #2
    ldr r0, lbl_080594fc @ =0x000001fb
    cmp r1, r0
    bgt lbl_080594e6
    adds r0, r2, r1
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_080594d4
    movs r3, #0
lbl_080594e6:
    cmp r3, #0
    bne lbl_080594f4
lbl_080594ea:
    adds r0, r2, r1
    strb r4, [r0]
    adds r1, #1
    adds r0, r2, r1
    strb r5, [r0]
lbl_080594f4:
    adds r0, r3, #0
lbl_080594f6:
    pop {r4, r5, r6}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080594fc: .4byte 0x000001fb

    thumb_func_start remove_never_reform_blocks
remove_never_reform_blocks: @ 0x08059500
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_08059550 @ =0x03000bf0
    movs r1, #0
    ldrsb r1, [r0, r1]
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r6, r0, #0x1f
    ldr r1, lbl_08059554 @ =0x03000054
    ldrb r0, [r1]
    cmp r0, #7
    bls lbl_08059518
    movs r6, #1
lbl_08059518:
    cmp r6, #0
    bne lbl_08059578
    ldrb r0, [r1]
    lsls r1, r0, #9
    ldr r3, lbl_08059558 @ =0x02035c00
    adds r2, r1, r3
    ldr r1, lbl_0805955c @ =0x0300005b
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r7, r0, #1
    movs r5, #0
    cmp r6, r7
    bge lbl_08059578
    adds r4, r2, #0
lbl_08059534:
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0805953c
    movs r5, #1
lbl_0805953c:
    cmp r5, #1
    bne lbl_08059564
    ldr r1, lbl_08059560 @ =0x03000055
    ldrb r0, [r4, #1]
    movs r5, #0
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_08059570
    movs r5, #2
    b lbl_08059570
    .align 2, 0
lbl_08059550: .4byte 0x03000bf0
lbl_08059554: .4byte 0x03000054
lbl_08059558: .4byte 0x02035c00
lbl_0805955c: .4byte 0x0300005b
lbl_08059560: .4byte 0x03000055
lbl_08059564:
    cmp r5, #2
    bne lbl_08059570
    ldrb r0, [r4]
    ldrb r1, [r4, #1]
    bl remove_never_reform_block_in_clipdata_bg
lbl_08059570:
    adds r4, #2
    adds r6, #2
    cmp r6, r7
    blt lbl_08059534
lbl_08059578:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start remove_never_reform_block_in_clipdata_bg
remove_never_reform_block_in_clipdata_bg: @ 0x08059580
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r2, lbl_080595dc @ =0x0300009c
    mov ip, r2
    ldrh r2, [r2, #0x1c]
    muls r1, r2, r1
    adds r3, r1, r0
    ldr r1, lbl_080595e0 @ =0x03005450
    mov r0, ip
    ldr r7, [r0, #0x18]
    lsls r2, r3, #1
    adds r5, r2, r7
    ldrh r0, [r5]
    ldr r1, [r1, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    movs r4, #0
    strh r4, [r5]
    mov r1, ip
    ldr r6, [r1, #8]
    adds r2, r2, r6
    strh r4, [r2]
    cmp r0, #0x11
    bne lbl_080595d6
    strh r4, [r5, #2]
    strh r4, [r2, #2]
    ldrh r0, [r1, #0x1c]
    adds r3, r3, r0
    lsls r0, r3, #1
    adds r1, r0, r7
    strh r4, [r1]
    adds r0, r0, r6
    strh r4, [r0]
    adds r3, #1
    lsls r0, r3, #1
    adds r1, r0, r7
    strh r4, [r1]
    adds r0, r0, r6
    strh r4, [r0]
lbl_080595d6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_080595dc: .4byte 0x0300009c
lbl_080595e0: .4byte 0x03005450

    thumb_func_start sub_080595e4
sub_080595e4: @ 0x080595e4
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    ldr r0, lbl_08059668 @ =0x03000bf1
    mov sl, r0
    ldrb r0, [r0]
    lsls r1, r0, #9
    ldr r2, lbl_0805966c @ =0x02035c00
    adds r2, r2, r1
    mov r8, r2
    ldr r5, lbl_08059670 @ =0x0300005b
    mov sb, r5
    add r0, sb
    ldrb r0, [r0]
    lsls r0, r0, #1
    add r0, r8
    ldrb r0, [r0]
    cmp r0, #0xff
    bne lbl_08059612
    b lbl_08059752
lbl_08059612:
    movs r6, #0x80
    lsls r6, r6, #0x12
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    mov r1, r8
    adds r2, r6, #0
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_08059674 @ =0x0000ffff
    str r4, [sp]
    movs r0, #3
    mov r2, r8
    adds r3, r5, #0
    bl BitFill
    movs r2, #0
    movs r7, #0
    mov r1, sl
    ldrb r0, [r1]
    add r0, sb
    ldrb r0, [r0]
    movs r4, #0
    cmp r0, #0
    beq lbl_080596f8
    mov ip, sb
    mov sb, sl
    ldr r5, lbl_08059678 @ =0x03000055
    mov sl, r5
    mov r3, r8
lbl_08059654:
    adds r0, r6, r7
    ldrb r1, [r0]
    str r0, [sp, #4]
    cmp r1, #0
    bne lbl_0805968e
    cmp r2, #1
    bne lbl_0805967c
    movs r2, #0xa
    b lbl_0805968e
    .align 2, 0
lbl_08059668: .4byte 0x03000bf1
lbl_0805966c: .4byte 0x02035c00
lbl_08059670: .4byte 0x0300005b
lbl_08059674: .4byte 0x0000ffff
lbl_08059678: .4byte 0x03000055
lbl_0805967c:
    cmp r2, #0
    bne lbl_0805968e
    adds r0, r4, r6
    ldrb r0, [r0, #1]
    mov r1, sl
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0805968e
    movs r2, #1
lbl_0805968e:
    cmp r2, #9
    bgt lbl_080596aa
    ldr r5, [sp, #4]
    ldrb r0, [r5]
    strb r0, [r3]
    adds r7, #1
    adds r3, #1
    adds r0, r6, r7
    ldrb r0, [r0]
    strb r0, [r3]
    adds r7, #1
    adds r3, #1
    adds r4, #2
    b lbl_080596ea
lbl_080596aa:
    cmp r2, #0xa
    bne lbl_080596ea
    mov r1, sb
    ldrb r0, [r1]
    add r0, ip
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x12
    adds r6, r0, r1
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_080596e4
    mov r5, r8
    adds r1, r4, r5
lbl_080596ca:
    strb r2, [r1]
    adds r6, #1
    adds r1, #1
    ldrb r0, [r6]
    strb r0, [r1]
    adds r6, #1
    adds r1, #1
    adds r3, #2
    adds r4, #2
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    bne lbl_080596ca
lbl_080596e4:
    movs r2, #2
    movs r6, #0x80
    lsls r6, r6, #0x12
lbl_080596ea:
    mov r1, sb
    ldrb r0, [r1]
    add r0, ip
    ldrb r0, [r0]
    lsls r0, r0, #1
    cmp r7, r0
    blt lbl_08059654
lbl_080596f8:
    ldr r3, lbl_08059764 @ =0x03000bf1
    ldr r5, lbl_08059768 @ =0x0300005b
    cmp r2, #2
    beq lbl_0805974a
    cmp r2, #1
    beq lbl_08059718
    mov r2, r8
    adds r1, r2, r4
    movs r0, #0
    strb r0, [r1]
    adds r4, #1
    adds r1, r2, r4
    ldr r0, lbl_0805976c @ =0x03000055
    ldrb r0, [r0]
    strb r0, [r1]
    adds r4, #1
lbl_08059718:
    ldrb r0, [r3]
    adds r0, r0, r5
    ldrb r0, [r0]
    lsls r0, r0, #1
    movs r1, #0x80
    lsls r1, r1, #0x12
    adds r6, r0, r1
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    beq lbl_0805974a
    mov r0, r8
    adds r1, r4, r0
lbl_08059732:
    strb r2, [r1]
    adds r6, #1
    adds r1, #1
    ldrb r0, [r6]
    strb r0, [r1]
    adds r6, #1
    adds r1, #1
    adds r4, #2
    ldrb r2, [r6]
    adds r0, r2, #0
    cmp r0, #0xff
    bne lbl_08059732
lbl_0805974a:
    ldrb r0, [r3]
    adds r0, r0, r5
    asrs r1, r4, #1
    strb r1, [r0]
lbl_08059752:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059764: .4byte 0x03000bf1
lbl_08059768: .4byte 0x0300005b
lbl_0805976c: .4byte 0x03000055

    thumb_func_start sub_08059770
sub_08059770: @ 0x08059770
    push {r4, r5, lr}
    adds r5, r0, #0
    ldr r1, lbl_0805979c @ =0x083459f0
    ldrb r0, [r5, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r4, [r0, #2]
    ldr r2, lbl_080597a0 @ =0x083459d0
    ldr r0, lbl_080597a4 @ =0x03000079
    ldrb r3, [r0]
    lsls r1, r3, #1
    adds r1, r1, r2
    ldr r2, lbl_080597a8 @ =0x08345ab0
    lsls r0, r4, #1
    adds r0, r0, r2
    ldrh r1, [r1]
    ldrh r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_080597ac
    movs r0, #1
    b lbl_080597e4
    .align 2, 0
lbl_0805979c: .4byte 0x083459f0
lbl_080597a0: .4byte 0x083459d0
lbl_080597a4: .4byte 0x03000079
lbl_080597a8: .4byte 0x08345ab0
lbl_080597ac:
    adds r1, r3, #0
    cmp r1, #8
    beq lbl_080597be
    cmp r1, #0xb
    bne lbl_080597e2
    ldr r0, lbl_080597ec @ =0x03000130
    ldrb r0, [r0, #0x11]
    cmp r0, #0
    bne lbl_080597e2
lbl_080597be:
    ldr r0, lbl_080597f0 @ =0x08345adc
    lsls r1, r4, #1
    adds r1, r1, r0
    ldrh r0, [r5, #4]
    ldrh r2, [r1]
    cmp r0, r2
    beq lbl_080597e2
    ldrh r4, [r1]
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_bg1_block_value
    ldrh r1, [r5, #2]
    ldrh r2, [r5]
    adds r0, r4, #0
    bl set_clipdata_block_value
lbl_080597e2:
    movs r0, #0
lbl_080597e4:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080597ec: .4byte 0x03000130
lbl_080597f0: .4byte 0x08345adc

    thumb_func_start sub_080597f4
sub_080597f4: @ 0x080597f4
    push {r4, r5, lr}
    adds r4, r0, #0
    ldr r1, lbl_08059820 @ =0x083459f0
    ldrb r0, [r4, #6]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r3, [r0, #2]
    ldr r1, lbl_08059824 @ =0x083459d0
    ldr r0, lbl_08059828 @ =0x03000079
    ldrb r0, [r0]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldr r1, lbl_0805982c @ =0x08345ab0
    lsls r5, r3, #1
    adds r1, r5, r1
    ldrh r2, [r0]
    ldrh r0, [r1]
    ands r0, r2
    cmp r0, #0
    beq lbl_08059830
    movs r0, #1
    b lbl_08059870
    .align 2, 0
lbl_08059820: .4byte 0x083459f0
lbl_08059824: .4byte 0x083459d0
lbl_08059828: .4byte 0x03000079
lbl_0805982c: .4byte 0x08345ab0
lbl_08059830:
    movs r0, #0xd
    ands r0, r2
    cmp r0, #0
    beq lbl_0805986e
    ldr r0, lbl_08059878 @ =0x08345adc
    adds r1, r5, r0
    ldrh r0, [r4, #4]
    ldrh r2, [r1]
    cmp r0, r2
    beq lbl_0805986e
    movs r0, #1
    ldrh r5, [r1]
    cmp r3, #0xd
    ble lbl_08059856
    adds r0, r3, #0
    ldrh r1, [r4]
    ldrh r2, [r4, #2]
    bl sub_08059ef8
lbl_08059856:
    cmp r0, #0
    beq lbl_0805986e
    ldrh r1, [r4, #2]
    ldrh r2, [r4]
    adds r0, r5, #0
    bl set_bg1_block_value
    ldrh r1, [r4, #2]
    ldrh r2, [r4]
    adds r0, r5, #0
    bl set_clipdata_block_value
lbl_0805986e:
    movs r0, #0
lbl_08059870:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059878: .4byte 0x08345adc

    thumb_func_start BlockApplyCCAA
BlockApplyCCAA: @ 0x0805987c
    push {r4, r5, r6, r7, lr}
    sub sp, #8
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r7, r2, #0x10
    ldr r2, lbl_080598c0 @ =0xffff0000
    lsrs r5, r0, #0x10
    orrs r0, r4
    str r0, [sp]
    ldr r3, lbl_080598c4 @ =0x03005450
    ldr r1, [r3, #8]
    lsls r0, r7, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    ldr r0, [sp, #4]
    ands r0, r2
    orrs r0, r1
    ldr r1, lbl_080598c8 @ =0xff00ffff
    ands r0, r1
    str r0, [sp, #4]
    movs r6, #0
    ldr r0, lbl_080598cc @ =0x03000079
    ldrb r0, [r0]
    subs r0, #1
    cmp r0, #0xe
    bls lbl_080598b6
    b lbl_080599d2
lbl_080598b6:
    lsls r0, r0, #2
    ldr r1, lbl_080598d0 @ =lbl_080598d4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_080598c0: .4byte 0xffff0000
lbl_080598c4: .4byte 0x03005450
lbl_080598c8: .4byte 0xff00ffff
lbl_080598cc: .4byte 0x03000079
lbl_080598d0: .4byte lbl_080598d4
lbl_080598d4: @ jump table
    .4byte lbl_08059964 @ case 0
    .4byte lbl_08059980 @ case 1
    .4byte lbl_08059998 @ case 2
    .4byte lbl_080599b8 @ case 3
    .4byte lbl_08059958 @ case 4
    .4byte lbl_080599d2 @ case 5
    .4byte lbl_08059910 @ case 6
    .4byte lbl_08059910 @ case 7
    .4byte lbl_08059910 @ case 8
    .4byte lbl_08059910 @ case 9
    .4byte lbl_08059910 @ case 10
    .4byte lbl_0805992c @ case 11
    .4byte lbl_0805992c @ case 12
    .4byte lbl_08059940 @ case 13
    .4byte lbl_08059958 @ case 14
lbl_08059910:
    ldr r0, [r3, #4]
    adds r0, r0, r7
    ldrb r0, [r0]
    cmp r0, #0xb
    bne lbl_08059958
    mov r0, sp
    ldrh r0, [r0]
    ldr r1, [sp]
    lsrs r1, r1, #0x10
    bl check_opening_hatch
    cmp r0, #0
    bne lbl_08059950
    b lbl_08059958
lbl_0805992c:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    ldr r0, lbl_0805993c @ =0x00000135
    b lbl_0805994c
    .align 2, 0
lbl_0805993c: .4byte 0x00000135
lbl_08059940:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    ldr r0, lbl_08059954 @ =0x00000139
lbl_0805994c:
    bl SoundPlayNotAlreadyPlaying
lbl_08059950:
    movs r6, #1
    b lbl_080599d2
    .align 2, 0
lbl_08059954: .4byte 0x00000139
lbl_08059958:
    mov r0, sp
    bl sub_080590b0
    cmp r0, #0
    beq lbl_080599d2
    b lbl_08059950
lbl_08059964:
    movs r0, #0
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    cmp r0, #0
    bne lbl_0805997c
    movs r0, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_bg1_block_value
lbl_0805997c:
    movs r0, #0
    b lbl_080599aa
lbl_08059980:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_08059994 @ =0x0000043e
    b lbl_080599aa
    .align 2, 0
lbl_08059994: .4byte 0x0000043e
lbl_08059998:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_080599b4 @ =0x0000043d
lbl_080599aa:
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
    b lbl_080599d2
    .align 2, 0
lbl_080599b4: .4byte 0x0000043d
lbl_080599b8:
    movs r0, #1
    adds r1, r4, #0
    adds r2, r5, #0
    bl sub_080599e0
    adds r6, r0, #0
    cmp r6, #0
    beq lbl_080599d2
    ldr r0, lbl_080599dc @ =0x0000043f
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
lbl_080599d2:
    adds r0, r6, #0
    add sp, #8
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_080599dc: .4byte 0x0000043f

    thumb_func_start sub_080599e0
sub_080599e0: @ 0x080599e0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    movs r6, #0
    cmp r0, #0
    bne lbl_08059a3e
    ldr r0, lbl_08059a18 @ =0x02027780
    mov r8, r0
    movs r3, #0x3f
    movs r1, #0x7e
    add r1, r8
    mov ip, r1
    ldrh r2, [r1]
    lsls r1, r7, #8
    adds r0, r1, #0
    orrs r0, r5
    adds r4, r1, #0
    cmp r2, r0
    bne lbl_08059a1c
    mov r0, ip
    strh r6, [r0]
    b lbl_08059a88
    .align 2, 0
lbl_08059a18: .4byte 0x02027780
lbl_08059a1c:
    subs r3, #1
    cmp r3, #0
    ble lbl_08059a8a
    subs r3, #1
    lsls r0, r3, #1
    mov r1, r8
    adds r2, r0, r1
    ldrh r1, [r2]
    adds r0, r4, #0
    orrs r0, r5
    cmp r1, r0
    bne lbl_08059a1c
    movs r0, #0
    strh r0, [r2]
    b lbl_08059a88
lbl_08059a3a:
    movs r3, #0xff
    b lbl_08059a66
lbl_08059a3e:
    ldr r0, lbl_08059a48 @ =0x02027780
    mov r8, r0
    movs r3, #0x40
    lsls r4, r7, #8
    b lbl_08059a52
    .align 2, 0
lbl_08059a48: .4byte 0x02027780
lbl_08059a4c:
    subs r3, #1
    cmp r3, #0
    ble lbl_08059a66
lbl_08059a52:
    subs r3, #1
    lsls r0, r3, #1
    add r0, r8
    ldrh r1, [r0]
    adds r0, r4, #0
    orrs r0, r5
    cmp r1, r0
    beq lbl_08059a3a
    cmp r1, #0
    bne lbl_08059a4c
lbl_08059a66:
    movs r6, #0
    cmp r3, #0xff
    beq lbl_08059a8a
    ldr r1, lbl_08059a98 @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    muls r0, r5, r0
    adds r0, r0, r7
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0
    bne lbl_08059a8a
    lsls r0, r3, #1
    add r0, r8
    orrs r4, r5
    strh r4, [r0]
lbl_08059a88:
    movs r6, #1
lbl_08059a8a:
    adds r0, r6, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059a98: .4byte 0x0300009c

    thumb_func_start samus_apply_screw_speedbooster_damage_to_environment
samus_apply_screw_speedbooster_damage_to_environment: @ 0x08059a9c
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsrs r7, r0, #0x16
    lsrs r6, r1, #0x16
    ldr r0, lbl_08059ac8 @ =0x0300009c
    adds r2, r0, #0
    ldrh r0, [r2, #0x1c]
    cmp r7, r0
    bhs lbl_08059af4
    ldrh r1, [r2, #0x1e]
    cmp r6, r1
    bhs lbl_08059af4
    cmp r5, #1
    bne lbl_08059ad0
    ldr r1, lbl_08059acc @ =0x03000079
    movs r0, #0xc
    b lbl_08059afc
    .align 2, 0
lbl_08059ac8: .4byte 0x0300009c
lbl_08059acc: .4byte 0x03000079
lbl_08059ad0:
    cmp r5, #2
    bne lbl_08059ae0
    ldr r1, lbl_08059adc @ =0x03000079
    movs r0, #0xe
    b lbl_08059afc
    .align 2, 0
lbl_08059adc: .4byte 0x03000079
lbl_08059ae0:
    cmp r5, #3
    bne lbl_08059af0
    ldr r1, lbl_08059aec @ =0x03000079
    movs r0, #0xe
    b lbl_08059afc
    .align 2, 0
lbl_08059aec: .4byte 0x03000079
lbl_08059af0:
    cmp r5, #4
    beq lbl_08059af8
lbl_08059af4:
    movs r0, #0
    b lbl_08059b46
lbl_08059af8:
    ldr r1, lbl_08059b50 @ =0x03000079
    movs r0, #0xd
lbl_08059afc:
    strb r0, [r1]
    ldrh r0, [r2, #0x1c]
    adds r1, r6, #0
    muls r1, r0, r1
    adds r0, r1, #0
    adds r0, r7, r0
    lsls r0, r0, #0x10
    ldr r1, [r2, #0x18]
    lsrs r0, r0, #0xf
    adds r0, r0, r1
    ldrh r4, [r0]
    cmp r4, #0
    beq lbl_08059b3e
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl BlockApplyCCAA
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov r8, r0
    cmp r0, #0
    bne lbl_08059b3e
    cmp r5, #3
    bne lbl_08059b3e
    ldr r1, lbl_08059b50 @ =0x03000079
    movs r0, #0xc
    strb r0, [r1]
    adds r0, r6, #0
    adds r1, r7, #0
    adds r2, r4, #0
    bl BlockApplyCCAA
lbl_08059b3e:
    ldr r1, lbl_08059b50 @ =0x03000079
    movs r0, #0
    strb r0, [r1]
    mov r0, r8
lbl_08059b46:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059b50: .4byte 0x03000079

    thumb_func_start update_broken_blocks
update_broken_blocks: @ 0x08059b54
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    ldr r4, lbl_08059bb0 @ =0x03005528
    movs r0, #0x2f
    mov sb, r0
lbl_08059b62:
    ldrb r7, [r4, #1]
    adds r2, r7, #0
    cmp r2, #0
    beq lbl_08059c52
    ldrh r0, [r4, #6]
    adds r3, r0, #1
    movs r6, #0
    strh r3, [r4, #6]
    ldrb r5, [r4]
    cmp r5, #0
    beq lbl_08059c1e
    ldr r1, lbl_08059bb4 @ =0x08345b08
    mov r8, r1
    ldrb r0, [r4, #2]
    movs r7, #0xd
    adds r1, r0, #0
    muls r1, r7, r1
    ldrb r0, [r4, #1]
    adds r1, r1, r0
    add r1, r8
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_08059c52
    movs r5, #0
    strh r5, [r4, #6]
    cmp r2, #0xc
    bls lbl_08059bdc
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    bl check_samus_in_reforming_block
    cmp r0, #0
    beq lbl_08059bb8
    movs r0, #2
    strb r0, [r4, #1]
    b lbl_08059c0c
    .align 2, 0
lbl_08059bb0: .4byte 0x03005528
lbl_08059bb4: .4byte 0x08345b08
lbl_08059bb8:
    ldr r1, lbl_08059bd8 @ =0x08345adc
    ldrb r0, [r4, #2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldrb r1, [r4, #4]
    ldrb r2, [r4, #3]
    bl set_clipdata_block_value
    strb r6, [r4]
    strb r6, [r4, #1]
    strb r6, [r4, #2]
    strb r6, [r4, #3]
    strb r6, [r4, #4]
    b lbl_08059c0c
    .align 2, 0
lbl_08059bd8: .4byte 0x08345adc
lbl_08059bdc:
    cmp r2, #7
    bne lbl_08059bfe
    ldrb r0, [r4, #3]
    ldrb r1, [r4, #4]
    bl check_samus_in_reforming_block
    cmp r0, #0
    beq lbl_08059c10
    ldrb r0, [r4, #2]
    muls r0, r7, r0
    ldrb r1, [r4, #1]
    adds r0, r0, r1
    add r0, r8
    ldrb r0, [r0]
    lsrs r0, r0, #1
    strh r0, [r4, #6]
    b lbl_08059c0c
lbl_08059bfe:
    cmp r2, #1
    bne lbl_08059c0a
    ldrb r0, [r4, #4]
    ldrb r1, [r4, #3]
    bl sub_0805a3e0
lbl_08059c0a:
    movs r5, #1
lbl_08059c0c:
    cmp r5, #0
    beq lbl_08059c52
lbl_08059c10:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059c52
lbl_08059c1e:
    ldr r2, lbl_08059c70 @ =0x08345b08
    ldrb r1, [r4, #2]
    movs r0, #0xd
    muls r1, r0, r1
    ldrb r0, [r4, #1]
    adds r1, r1, r0
    adds r1, r1, r2
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    ldrb r1, [r1]
    cmp r0, r1
    blo lbl_08059c52
    strh r5, [r4, #6]
    adds r0, r7, #1
    strb r0, [r4, #1]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    ldrb r0, [r4, #1]
    cmp r0, #6
    bls lbl_08059c52
    strb r6, [r4]
    strb r6, [r4, #1]
    strb r6, [r4, #2]
    strb r6, [r4, #3]
    strb r6, [r4, #4]
lbl_08059c52:
    movs r1, #1
    rsbs r1, r1, #0
    add sb, r1
    adds r4, #8
    mov r0, sb
    cmp r0, #0
    blt lbl_08059c62
    b lbl_08059b62
lbl_08059c62:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059c70: .4byte 0x08345b08

    thumb_func_start breaking_reforming_block_anim
breaking_reforming_block_anim: @ 0x08059c74
    push {r4, r5, lr}
    adds r4, r0, #0
    movs r5, #0
    ldrb r0, [r4, #1]
    cmp r0, #0xd
    bhi lbl_08059cfc
    lsls r0, r0, #2
    ldr r1, lbl_08059c8c @ =lbl_08059c90
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_08059c8c: .4byte lbl_08059c90
lbl_08059c90: @ jump table
    .4byte lbl_08059cfc @ case 0
    .4byte lbl_08059cfc @ case 1
    .4byte lbl_08059cc8 @ case 2
    .4byte lbl_08059cd8 @ case 3
    .4byte lbl_08059ce0 @ case 4
    .4byte lbl_08059ce8 @ case 5
    .4byte lbl_08059cf0 @ case 6
    .4byte lbl_08059cf8 @ case 7
    .4byte lbl_08059cf0 @ case 8
    .4byte lbl_08059ce8 @ case 9
    .4byte lbl_08059ce0 @ case 10
    .4byte lbl_08059cd8 @ case 11
    .4byte lbl_08059cc8 @ case 12
    .4byte lbl_08059cfc @ case 13
lbl_08059cc8:
    ldr r1, lbl_08059cd4 @ =0x08345adc
    ldrb r0, [r4, #2]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r5, [r0]
    b lbl_08059cfc
    .align 2, 0
lbl_08059cd4: .4byte 0x08345adc
lbl_08059cd8:
    ldr r5, lbl_08059cdc @ =0x00000401
    b lbl_08059d00
    .align 2, 0
lbl_08059cdc: .4byte 0x00000401
lbl_08059ce0:
    ldr r5, lbl_08059ce4 @ =0x00000402
    b lbl_08059d00
    .align 2, 0
lbl_08059ce4: .4byte 0x00000402
lbl_08059ce8:
    ldr r5, lbl_08059cec @ =0x00000403
    b lbl_08059d00
    .align 2, 0
lbl_08059cec: .4byte 0x00000403
lbl_08059cf0:
    ldr r5, lbl_08059cf4 @ =0x00000404
    b lbl_08059d00
    .align 2, 0
lbl_08059cf4: .4byte 0x00000404
lbl_08059cf8:
    movs r5, #0x80
    lsls r5, r5, #3
lbl_08059cfc:
    cmp r5, #0
    beq lbl_08059d8a
lbl_08059d00:
    ldr r2, lbl_08059d90 @ =0x0300009c
    ldrb r1, [r4, #4]
    ldrh r0, [r2, #0xc]
    muls r0, r1, r0
    ldrb r1, [r4, #3]
    adds r0, r0, r1
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    strh r5, [r0]
    ldr r0, lbl_08059d94 @ =0x030013ba
    ldrh r0, [r0]
    lsrs r3, r0, #6
    subs r0, r3, #4
    ldrb r2, [r4, #4]
    cmp r0, r2
    bgt lbl_08059d8a
    adds r0, #0x11
    cmp r2, r0
    bgt lbl_08059d8a
    ldr r0, lbl_08059d98 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r3, r0, #6
    subs r0, r3, #4
    ldrb r1, [r4, #3]
    cmp r0, r1
    bgt lbl_08059d8a
    adds r0, #0x16
    cmp r1, r0
    bgt lbl_08059d8a
    ldr r4, lbl_08059d9c @ =0x06001000
    movs r0, #0x10
    ands r0, r1
    cmp r0, #0
    beq lbl_08059d48
    ldr r4, lbl_08059da0 @ =0x06001800
lbl_08059d48:
    movs r0, #0xf
    ands r1, r0
    lsls r3, r1, #1
    ands r2, r0
    lsls r0, r2, #6
    adds r0, r0, r3
    lsls r0, r0, #1
    adds r4, r4, r0
    lsls r3, r5, #2
    ldr r0, lbl_08059da4 @ =0x03005450
    ldr r1, [r0]
    lsls r0, r5, #3
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4]
    adds r3, #1
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r4, #2]
    adds r3, #1
    adds r2, r4, #0
    adds r2, #0x40
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
    adds r3, #1
    adds r2, #2
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    strh r0, [r2]
lbl_08059d8a:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08059d90: .4byte 0x0300009c
lbl_08059d94: .4byte 0x030013ba
lbl_08059d98: .4byte 0x030013b8
lbl_08059d9c: .4byte 0x06001000
lbl_08059da0: .4byte 0x06001800
lbl_08059da4: .4byte 0x03005450

    thumb_func_start store_broken_reform_block
store_broken_reform_block: @ 0x08059da8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    mov r8, r3
    movs r1, #0
    ldr r4, lbl_08059dcc @ =0x03005528
    movs r3, #0
    adds r7, r4, #0
    b lbl_08059de8
    .align 2, 0
lbl_08059dcc: .4byte 0x03005528
lbl_08059dd0:
    movs r2, #0x80
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    bne lbl_08059de4
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_08059de4
    adds r1, r3, #0
    orrs r1, r2
lbl_08059de4:
    adds r3, #1
    adds r4, #8
lbl_08059de8:
    cmp r3, #0x2f
    bgt lbl_08059e02
    ldrb r0, [r4, #3]
    cmp r0, r6
    bne lbl_08059dd0
    ldrb r0, [r4, #4]
    cmp r0, r5
    bne lbl_08059dd0
    ldrb r0, [r4, #1]
    movs r1, #0
    cmp r0, #0
    bne lbl_08059e02
    movs r1, #1
lbl_08059e02:
    cmp r1, #0
    beq lbl_08059e48
    cmp r1, #1
    beq lbl_08059e0e
    movs r3, #0x7f
    ands r3, r1
lbl_08059e0e:
    lsls r0, r3, #3
    adds r4, r0, r7
    movs r0, #0
    movs r2, #1
    strb r2, [r4]
    mov r3, ip
    strb r3, [r4, #2]
    strh r0, [r4, #6]
    movs r0, #0x80
    ands r1, r0
    cmp r1, #0
    beq lbl_08059e2a
    strb r6, [r4, #3]
    strb r5, [r4, #4]
lbl_08059e2a:
    mov r0, r8
    cmp r0, #0
    bne lbl_08059e44
    movs r0, #2
    strb r0, [r4, #1]
    adds r0, r5, #0
    adds r1, r6, #0
    bl sub_0805a3e0
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059e46
lbl_08059e44:
    strb r2, [r4, #1]
lbl_08059e46:
    movs r1, #1
lbl_08059e48:
    adds r0, r1, #0
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start store_broken_non_reform_block
store_broken_non_reform_block: @ 0x08059e54
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsrs r3, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov r8, r1
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    ldr r4, lbl_08059e90 @ =0x03005528
    movs r6, #0
    adds r2, r4, #0
lbl_08059e70:
    ldrb r1, [r4, #1]
    cmp r1, #0
    bne lbl_08059e94
    strb r1, [r4]
    movs r0, #2
    strb r0, [r4, #1]
    strb r7, [r4, #2]
    strh r1, [r4, #6]
    strb r3, [r4, #3]
    mov r0, r8
    strb r0, [r4, #4]
    adds r0, r4, #0
    bl breaking_reforming_block_anim
    b lbl_08059eea
    .align 2, 0
lbl_08059e90: .4byte 0x03005528
lbl_08059e94:
    adds r6, #1
    adds r4, #8
    cmp r6, #0x2f
    ble lbl_08059e70
    movs r1, #4
lbl_08059e9e:
    adds r4, r2, #0
    movs r6, #0
lbl_08059ea2:
    ldrb r5, [r4]
    cmp r5, #0
    bne lbl_08059edc
    ldrb r0, [r4, #1]
    cmp r0, r1
    blt lbl_08059edc
    ldrb r1, [r4, #4]
    ldrb r2, [r4, #3]
    movs r0, #0
    str r3, [sp]
    bl set_bg1_block_value
    strb r5, [r4]
    movs r0, #2
    strb r0, [r4, #1]
    strb r7, [r4, #2]
    strh r5, [r4, #6]
    ldr r3, [sp]
    strb r3, [r4, #3]
    mov r0, r8
    strb r0, [r4, #4]
    lsls r0, r6, #3
    ldr r1, lbl_08059ed8 @ =0x03005528
    adds r0, r0, r1
    bl breaking_reforming_block_anim
    b lbl_08059eea
    .align 2, 0
lbl_08059ed8: .4byte 0x03005528
lbl_08059edc:
    adds r6, #1
    adds r4, #8
    cmp r6, #0x2f
    ble lbl_08059ea2
    asrs r1, r1, #1
    cmp r1, #0
    bne lbl_08059e9e
lbl_08059eea:
    add sp, #4
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08059ef8
sub_08059ef8: @ 0x08059ef8
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r6, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r5, r2, #0x10
    movs r1, #0
    ldr r3, lbl_08059f6c @ =0x03005528
    movs r4, #0
    ldrb r0, [r3, #3]
    mov ip, r3
    cmp r0, r6
    bne lbl_08059f1a
    ldrb r0, [r3, #4]
    cmp r0, r5
    beq lbl_08059f62
lbl_08059f1a:
    movs r2, #0x80
    adds r0, r1, #0
    ands r0, r2
    cmp r0, #0
    bne lbl_08059f2e
    ldrb r0, [r3, #1]
    cmp r0, #0
    bne lbl_08059f2e
    adds r1, r4, #0
    orrs r1, r2
lbl_08059f2e:
    adds r4, #1
    adds r3, #8
    cmp r4, #0x2f
    bgt lbl_08059f44
    ldrb r0, [r3, #3]
    cmp r0, r6
    bne lbl_08059f1a
    ldrb r0, [r3, #4]
    cmp r0, r5
    bne lbl_08059f1a
    movs r1, #0
lbl_08059f44:
    cmp r1, #0
    beq lbl_08059f62
    movs r0, #0x7f
    ands r1, r0
    lsls r0, r1, #3
    mov r1, ip
    adds r3, r0, r1
    movs r0, #0
    strb r0, [r3]
    strb r0, [r3, #1]
    strb r7, [r3, #2]
    strh r0, [r3, #6]
    strb r6, [r3, #3]
    strb r5, [r3, #4]
    movs r1, #1
lbl_08059f62:
    adds r0, r1, #0
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059f6c: .4byte 0x03005528

    thumb_func_start check_samus_in_reforming_block
check_samus_in_reforming_block: @ 0x08059f70
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r5, r1, #0x18
    movs r6, #0
    ldr r1, lbl_08059fd8 @ =0x030013d4
    ldrh r3, [r1, #0x12]
    ldr r2, lbl_08059fdc @ =0x03001588
    adds r0, r2, #0
    adds r0, #0x6e
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r3, r0
    asrs r0, r0, #6
    cmp r0, r4
    bgt lbl_08059fa4
    adds r0, r2, #0
    adds r0, #0x72
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r3, r0
    asrs r0, r0, #6
    cmp r4, r0
    bgt lbl_08059fa4
    movs r6, #1
lbl_08059fa4:
    movs r3, #0
    ldrh r1, [r1, #0x14]
    adds r0, r2, #0
    adds r0, #0x70
    movs r4, #0
    ldrsh r0, [r0, r4]
    adds r0, r1, r0
    asrs r0, r0, #6
    cmp r0, r5
    bgt lbl_08059fca
    adds r0, r2, #0
    adds r0, #0x74
    movs r7, #0
    ldrsh r0, [r0, r7]
    adds r0, r1, r0
    asrs r0, r0, #6
    cmp r5, r0
    bgt lbl_08059fca
    movs r3, #1
lbl_08059fca:
    movs r0, #0
    cmp r6, #0
    beq lbl_08059fd2
    adds r0, r3, #0
lbl_08059fd2:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_08059fd8: .4byte 0x030013d4
lbl_08059fdc: .4byte 0x03001588

    thumb_func_start start_bomb_chain
start_bomb_chain: @ 0x08059fe0
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    mov ip, r2
    movs r0, #0
    mov r8, r0
    movs r2, #3
    ldr r0, lbl_0805a04c @ =0x030056ac
    movs r4, #7
    ands r4, r5
    movs r1, #8
    rsbs r1, r1, #0
    mov sl, r1
    ldr r6, lbl_0805a050 @ =0x030056bc
    ldr r1, lbl_0805a054 @ =0x08345c28
    adds r3, r0, #0
    adds r3, #0xc
    lsls r0, r5, #2
    adds r7, r0, r1
lbl_0805a018:
    ldrb r0, [r3]
    cmp r0, #0
    bne lbl_0805a058
    movs r0, #1
    strb r0, [r3]
    mov r0, sb
    strb r0, [r3, #1]
    mov r1, ip
    strb r1, [r3, #2]
    ldrb r0, [r3, #3]
    movs r1, #0x40
    orrs r0, r1
    movs r1, #0x80
    orrs r0, r1
    mov r1, sl
    ands r0, r1
    orrs r0, r4
    strb r0, [r3, #3]
    ldrb r0, [r6]
    ldrb r1, [r7]
    orrs r0, r1
    strb r0, [r6]
    movs r0, #1
    mov r8, r0
    b lbl_0805a066
    .align 2, 0
lbl_0805a04c: .4byte 0x030056ac
lbl_0805a050: .4byte 0x030056bc
lbl_0805a054: .4byte 0x08345c28
lbl_0805a058:
    subs r3, #4
    subs r2, #1
    cmp r2, #0
    bge lbl_0805a018
    mov r1, r8
    cmp r1, #0
    beq lbl_0805a07e
lbl_0805a066:
    ldr r2, lbl_0805a090 @ =0x030056bc
    ldr r1, lbl_0805a094 @ =0x08345c28
    lsls r0, r5, #2
    adds r0, r0, r1
    ldrb r1, [r2]
    ldrb r0, [r0]
    cmp r1, r0
    bne lbl_0805a07e
    movs r0, #0x9b
    lsls r0, r0, #1
    bl SoundPlayNotAlreadyPlaying
lbl_0805a07e:
    mov r0, r8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805a090: .4byte 0x030056bc
lbl_0805a094: .4byte 0x08345c28

    thumb_func_start process_bomb_chains
process_bomb_chains: @ 0x0805a098
    push {r4, r5, lr}
    sub sp, #8
    ldr r4, lbl_0805a150 @ =0x030056ac
    ldr r0, lbl_0805a154 @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #3
    ands r0, r1
    lsls r0, r0, #2
    adds r4, r0, r4
    ldrb r0, [r4]
    cmp r0, #0
    bne lbl_0805a0b2
    b lbl_0805a320
lbl_0805a0b2:
    movs r3, #0
    ldr r0, [r4]
    lsls r2, r0, #5
    lsrs r0, r2, #0x1d
    cmp r0, #3
    bls lbl_0805a0c0
    movs r3, #1
lbl_0805a0c0:
    ldr r1, lbl_0805a158 @ =0x08345c28
    lsrs r0, r2, #0x1d
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrh r1, [r0, #2]
    ldr r0, lbl_0805a15c @ =0xffff0000
    mov r5, sp
    ldr r2, [sp, #4]
    ands r2, r0
    orrs r2, r1
    str r2, [sp, #4]
    ldrb r0, [r5, #4]
    subs r0, #0x10
    lsls r0, r0, #0x18
    lsrs r0, r0, #8
    ldr r1, lbl_0805a160 @ =0xff00ffff
    ands r1, r2
    orrs r1, r0
    str r1, [sp, #4]
    movs r0, #0
    str r0, [sp]
    cmp r3, #0
    beq lbl_0805a0f0
    b lbl_0805a1f4
lbl_0805a0f0:
    ldrb r3, [r4, #1]
    str r3, [sp]
    ldrb r1, [r4, #3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a18a
    ldrb r0, [r4, #2]
    ldrb r1, [r4]
    subs r0, r0, r1
    lsls r0, r0, #0x10
    ldr r2, lbl_0805a164 @ =0x0000ffff
    ands r2, r3
    orrs r2, r0
    str r2, [sp]
    lsrs r0, r2, #0x10
    cmp r0, #1
    bls lbl_0805a144
    ldr r3, lbl_0805a168 @ =0x0300009c
    lsrs r2, r2, #0x10
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a16c @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a170
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a18a
lbl_0805a144:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a18a
    .align 2, 0
lbl_0805a150: .4byte 0x030056ac
lbl_0805a154: .4byte 0x03000c77
lbl_0805a158: .4byte 0x08345c28
lbl_0805a15c: .4byte 0xffff0000
lbl_0805a160: .4byte 0xff00ffff
lbl_0805a164: .4byte 0x0000ffff
lbl_0805a168: .4byte 0x0300009c
lbl_0805a16c: .4byte 0x03005450
lbl_0805a170:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #0
    bl sub_0805a330
lbl_0805a18a:
    ldrb r1, [r4, #3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    bne lbl_0805a196
    b lbl_0805a2e8
lbl_0805a196:
    ldrb r0, [r4, #2]
    ldrb r1, [r4]
    adds r0, r0, r1
    mov r5, sp
    strh r0, [r5, #2]
    ldrh r2, [r5, #2]
    ldr r3, lbl_0805a1ec @ =0x0300009c
    ldrh r0, [r3, #0x1e]
    subs r0, #2
    cmp r2, r0
    blt lbl_0805a1ae
    b lbl_0805a2be
lbl_0805a1ae:
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a1f0 @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    beq lbl_0805a2b4
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #1
    bl sub_0805a330
    b lbl_0805a2e8
    .align 2, 0
lbl_0805a1ec: .4byte 0x0300009c
lbl_0805a1f0: .4byte 0x03005450
lbl_0805a1f4:
    ldrb r0, [r4, #2]
    strh r0, [r5, #2]
    ldrb r1, [r4, #3]
    movs r0, #0x40
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a272
    ldrb r0, [r4, #1]
    ldrb r1, [r4]
    subs r0, r0, r1
    mov r1, sp
    strh r0, [r1]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #1
    bls lbl_0805a244
    ldr r3, lbl_0805a250 @ =0x0300009c
    ldrh r2, [r5, #2]
    ldrh r0, [r3, #0x1c]
    mov r1, sp
    muls r0, r2, r0
    ldrh r1, [r1]
    adds r0, r0, r1
    ldr r1, [r3, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a254 @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r5, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a258
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a272
lbl_0805a244:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a272
    .align 2, 0
lbl_0805a250: .4byte 0x0300009c
lbl_0805a254: .4byte 0x03005450
lbl_0805a258:
    ldrb r1, [r4, #3]
    movs r0, #0x41
    rsbs r0, r0, #0
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r5, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #2
    bl sub_0805a330
lbl_0805a272:
    ldrb r1, [r4, #3]
    movs r0, #0x80
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a2e8
    ldrb r0, [r4, #1]
    ldrb r1, [r4]
    adds r0, r0, r1
    mov r1, sp
    strh r0, [r1]
    mov r0, sp
    ldrh r2, [r0]
    ldr r5, lbl_0805a2c8 @ =0x0300009c
    ldrh r1, [r5, #0x1c]
    subs r0, r1, #2
    cmp r2, r0
    bge lbl_0805a2be
    mov r3, sp
    ldrh r0, [r3, #2]
    muls r0, r1, r0
    adds r0, r0, r2
    ldr r1, [r5, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    ldr r0, lbl_0805a2cc @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r1, [r3, #4]
    ldrh r0, [r0]
    cmp r1, r0
    bne lbl_0805a2d0
lbl_0805a2b4:
    mov r0, sp
    bl sub_080592c4
    cmp r0, #0
    bne lbl_0805a2e8
lbl_0805a2be:
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    b lbl_0805a2e8
    .align 2, 0
lbl_0805a2c8: .4byte 0x0300009c
lbl_0805a2cc: .4byte 0x03005450
lbl_0805a2d0:
    ldrb r1, [r4, #3]
    movs r0, #0x7f
    ands r0, r1
    strb r0, [r4, #3]
    mov r0, sp
    ldrb r1, [r0]
    ldrh r2, [r3, #2]
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    movs r0, #3
    bl sub_0805a330
lbl_0805a2e8:
    ldrb r0, [r4, #3]
    movs r1, #0xc0
    ands r1, r0
    cmp r1, #0
    beq lbl_0805a2fa
    ldrb r0, [r4]
    adds r0, #1
    strb r0, [r4]
    b lbl_0805a320
lbl_0805a2fa:
    strb r1, [r4]
    ldr r2, lbl_0805a328 @ =0x030056bc
    ldr r1, lbl_0805a32c @ =0x08345c28
    ldr r0, [r4]
    lsls r0, r0, #5
    lsrs r0, r0, #0x1d
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r1, [r0]
    ldrb r0, [r2]
    bics r0, r1
    strb r0, [r2]
    cmp r0, #0
    bne lbl_0805a320
    movs r0, #0x9b
    lsls r0, r0, #1
    movs r1, #0xa
    bl SoundFade
lbl_0805a320:
    add sp, #8
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a328: .4byte 0x030056bc
lbl_0805a32c: .4byte 0x08345c28

    thumb_func_start sub_0805a330
sub_0805a330: @ 0x0805a330
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    mov sb, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    mov r8, r2
    ldr r1, lbl_0805a3d4 @ =0x03000079
    movs r0, #0xf
    strb r0, [r1]
    ldr r4, lbl_0805a3d8 @ =0x0300009c
    ldrh r0, [r4, #0x1c]
    mov r1, r8
    muls r1, r0, r1
    adds r0, r1, #0
    add r0, sb
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    cmp r2, #0
    beq lbl_0805a370
    mov r0, r8
    mov r1, sb
    bl BlockApplyCCAA
lbl_0805a370:
    movs r6, #0
    mov sl, r4
    lsls r7, r5, #2
    ldr r2, lbl_0805a3dc @ =0x08345cde
    adds r5, r7, r2
lbl_0805a37a:
    lsls r0, r6, #1
    adds r1, r7, #1
    adds r0, r0, r1
    ldr r1, lbl_0805a3dc @ =0x08345cde
    adds r0, r0, r1
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    mov r2, r8
    adds r4, r2, r0
    mov r1, sl
    ldrh r0, [r1, #0x1c]
    muls r0, r4, r0
    movs r1, #0
    ldrsb r1, [r5, r1]
    mov r2, sb
    adds r3, r2, r1
    adds r0, r0, r3
    mov r2, sl
    ldr r1, [r2, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r2, [r0]
    cmp r2, #0
    beq lbl_0805a3b8
    lsls r0, r4, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r3, #0x10
    lsrs r1, r1, #0x10
    bl BlockApplyCCAA
lbl_0805a3b8:
    adds r5, #2
    adds r6, #1
    cmp r6, #1
    ble lbl_0805a37a
    ldr r1, lbl_0805a3d4 @ =0x03000079
    movs r0, #0
    strb r0, [r1]
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a3d4: .4byte 0x03000079
lbl_0805a3d8: .4byte 0x0300009c
lbl_0805a3dc: .4byte 0x08345cde

    thumb_func_start sub_0805a3e0
sub_0805a3e0: @ 0x0805a3e0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r6, r4, #0
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    adds r7, r5, #0
    ldr r2, lbl_0805a46c @ =0x0300009c
    ldrh r0, [r2, #0x1c]
    adds r1, r4, #0
    muls r1, r0, r1
    adds r0, r1, #0
    adds r0, r5, r0
    lsls r0, r0, #0x10
    ldr r1, [r2, #0x18]
    lsrs r0, r0, #0xf
    adds r1, r0, r1
    movs r3, #0
    strh r3, [r1]
    ldr r1, [r2, #8]
    adds r0, r0, r1
    strh r3, [r0]
    ldr r0, lbl_0805a470 @ =0x030013ba
    ldrh r0, [r0]
    lsrs r1, r0, #6
    subs r0, r1, #4
    cmp r0, r4
    bgt lbl_0805a466
    adds r0, #0x11
    cmp r4, r0
    bgt lbl_0805a466
    ldr r0, lbl_0805a474 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r1, r0, #6
    subs r0, r1, #4
    cmp r0, r5
    bgt lbl_0805a466
    adds r0, #0x16
    cmp r5, r0
    bgt lbl_0805a466
    ldr r3, lbl_0805a478 @ =0x06001000
    movs r0, #0x10
    ands r0, r5
    cmp r0, #0
    beq lbl_0805a43c
    ldr r3, lbl_0805a47c @ =0x06001800
lbl_0805a43c:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r3, r3, r0
    ldr r0, lbl_0805a480 @ =0x03005450
    ldr r1, [r0]
    ldrh r0, [r1]
    strh r0, [r3]
    ldrh r0, [r1, #2]
    strh r0, [r3, #2]
    adds r2, r3, #0
    adds r2, #0x40
    ldrh r0, [r1, #4]
    strh r0, [r2]
    adds r2, #2
    ldrh r0, [r1, #6]
    strh r0, [r2]
lbl_0805a466:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a46c: .4byte 0x0300009c
lbl_0805a470: .4byte 0x030013ba
lbl_0805a474: .4byte 0x030013b8
lbl_0805a478: .4byte 0x06001000
lbl_0805a47c: .4byte 0x06001800
lbl_0805a480: .4byte 0x03005450

    thumb_func_start mother_brain_update_glass
mother_brain_update_glass: @ 0x0805a484
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov ip, r1
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r6, r2, #0
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    adds r7, r3, #0
    ldr r0, lbl_0805a548 @ =0x0300009c
    lsls r1, r5, #3
    adds r1, r1, r0
    ldrh r0, [r1, #4]
    muls r0, r2, r0
    adds r0, r0, r3
    ldr r1, [r1]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, ip
    strh r1, [r0]
    ldr r0, lbl_0805a54c @ =0x030013ba
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r2
    bgt lbl_0805a540
    adds r0, #0x11
    cmp r2, r0
    bgt lbl_0805a540
    ldr r0, lbl_0805a550 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r3
    bgt lbl_0805a540
    adds r0, #0x16
    cmp r3, r0
    bgt lbl_0805a540
    lsls r1, r5, #0xc
    movs r0, #0xc0
    lsls r0, r0, #0x13
    adds r5, r1, r0
    movs r0, #0x10
    ands r0, r3
    cmp r0, #0
    beq lbl_0805a4ea
    ldr r0, lbl_0805a554 @ =0x06000800
    adds r5, r1, r0
lbl_0805a4ea:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r5, r5, r0
    mov r1, ip
    lsls r0, r1, #0x12
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    ldr r3, lbl_0805a558 @ =0x03005450
    movs r0, #1
    orrs r4, r0
    adds r2, r4, #0
    ldr r3, [r3]
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1]
    strh r0, [r5]
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r3
    ldrh r0, [r2]
    strh r0, [r5, #2]
    adds r2, r5, #0
    adds r2, #0x40
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r1, [r1]
    strh r1, [r2]
    adds r1, r5, #0
    adds r1, #0x42
    lsrs r0, r0, #0xf
    adds r0, r0, r3
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0805a540:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a548: .4byte 0x0300009c
lbl_0805a54c: .4byte 0x030013ba
lbl_0805a550: .4byte 0x030013b8
lbl_0805a554: .4byte 0x06000800
lbl_0805a558: .4byte 0x03005450

    thumb_func_start set_bg1_block_value
set_bg1_block_value: @ 0x0805a55c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    mov ip, r0
    lsls r1, r1, #0x10
    lsrs r3, r1, #0x10
    adds r6, r3, #0
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    adds r7, r2, #0
    ldr r1, lbl_0805a610 @ =0x0300009c
    ldrh r0, [r1, #0xc]
    muls r0, r3, r0
    adds r0, r0, r2
    ldr r1, [r1, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    mov r1, ip
    strh r1, [r0]
    ldr r0, lbl_0805a614 @ =0x030013ba
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r3
    bgt lbl_0805a608
    adds r0, #0x11
    cmp r3, r0
    bgt lbl_0805a608
    ldr r0, lbl_0805a618 @ =0x030013b8
    ldrh r0, [r0]
    lsrs r4, r0, #6
    subs r0, r4, #4
    cmp r0, r2
    bgt lbl_0805a608
    adds r0, #0x16
    cmp r2, r0
    bgt lbl_0805a608
    ldr r5, lbl_0805a61c @ =0x06001000
    movs r0, #0x10
    ands r0, r2
    cmp r0, #0
    beq lbl_0805a5b2
    ldr r5, lbl_0805a620 @ =0x06001800
lbl_0805a5b2:
    movs r1, #0xf
    ands r6, r1
    lsls r0, r6, #6
    ands r7, r1
    lsls r1, r7, #1
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r5, r5, r0
    mov r1, ip
    lsls r0, r1, #0x12
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    ldr r3, lbl_0805a624 @ =0x03005450
    movs r0, #1
    orrs r4, r0
    adds r2, r4, #0
    ldr r3, [r3]
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r0, [r1]
    strh r0, [r5]
    adds r0, r2, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r1, r4, #0
    lsls r2, r2, #1
    adds r2, r2, r3
    ldrh r0, [r2]
    strh r0, [r5, #2]
    adds r2, r5, #0
    adds r2, #0x40
    adds r0, r1, #1
    lsls r0, r0, #0x10
    lsls r1, r1, #1
    adds r1, r1, r3
    ldrh r1, [r1]
    strh r1, [r2]
    adds r1, r5, #0
    adds r1, #0x42
    lsrs r0, r0, #0xf
    adds r0, r0, r3
    ldrh r0, [r0]
    strh r0, [r1]
lbl_0805a608:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a610: .4byte 0x0300009c
lbl_0805a614: .4byte 0x030013ba
lbl_0805a618: .4byte 0x030013b8
lbl_0805a61c: .4byte 0x06001000
lbl_0805a620: .4byte 0x06001800
lbl_0805a624: .4byte 0x03005450

    thumb_func_start set_raw_bg1_block_value
set_raw_bg1_block_value: @ 0x0805a628
    push {r4, lr}
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldr r4, lbl_0805a648 @ =0x0300009c
    ldrh r3, [r4, #0xc]
    muls r1, r3, r1
    adds r1, r1, r2
    ldr r2, [r4, #8]
    lsls r1, r1, #1
    adds r1, r1, r2
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a648: .4byte 0x0300009c

    thumb_func_start set_clipdata_block_value
set_clipdata_block_value: @ 0x0805a64c
    push {r4, lr}
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    ldr r4, lbl_0805a66c @ =0x0300009c
    ldrh r3, [r4, #0x1c]
    muls r1, r3, r1
    adds r1, r1, r2
    ldr r2, [r4, #0x18]
    lsls r1, r1, #1
    adds r1, r1, r2
    strh r0, [r1]
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a66c: .4byte 0x0300009c

    thumb_func_start check_special_clipdata
check_special_clipdata: @ 0x0805a670
    push {lr}
    movs r0, #0
    bl check_grabbing_crumble_block
    ldr r0, lbl_0805a688 @ =0x030013d4
    ldrb r0, [r0]
    cmp r0, #0x1d
    bne lbl_0805a68c
    bl check_touching_transition_on_elevator
    b lbl_0805a6c0
    .align 2, 0
lbl_0805a688: .4byte 0x030013d4
lbl_0805a68c:
    ldr r0, lbl_0805a6a8 @ =0x03000048
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805a6c0
    ldr r0, lbl_0805a6ac @ =0x03000c77
    ldrb r1, [r0]
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805a6b0
    bl check_touching_transition_or_tank
    b lbl_0805a6bc
    .align 2, 0
lbl_0805a6a8: .4byte 0x03000048
lbl_0805a6ac: .4byte 0x03000c77
lbl_0805a6b0:
    ldr r0, lbl_0805a6c4 @ =0x0300004c
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_0805a6bc
    bl apply_clipdata_changing_transparency
lbl_0805a6bc:
    bl check_walking_on_crumble_block
lbl_0805a6c0:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805a6c4: .4byte 0x0300004c

    thumb_func_start apply_clipdata_changing_transparency
apply_clipdata_changing_transparency: @ 0x0805a6c8
    push {r4, r5, lr}
    ldr r0, lbl_0805a6f8 @ =0x030013d4
    ldrh r2, [r0, #0x12]
    adds r5, r0, #0
    ldr r1, lbl_0805a6fc @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r4, r1, #0
    cmp r2, r0
    ble lbl_0805a6de
    adds r2, r0, #0
lbl_0805a6de:
    asrs r3, r2, #6
    ldr r0, lbl_0805a700 @ =0x03001588
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r5, [r5, #0x14]
    adds r2, r0, r5
    cmp r2, #0
    bge lbl_0805a704
    movs r2, #0
    b lbl_0805a70e
    .align 2, 0
lbl_0805a6f8: .4byte 0x030013d4
lbl_0805a6fc: .4byte 0x0300009c
lbl_0805a700: .4byte 0x03001588
lbl_0805a704:
    ldrh r0, [r4, #0x1e]
    lsls r0, r0, #6
    cmp r2, r0
    ble lbl_0805a70e
    adds r2, r0, #0
lbl_0805a70e:
    asrs r1, r2, #6
    ldr r2, lbl_0805a750 @ =0x03005450
    ldrh r0, [r4, #0x1c]
    muls r0, r1, r0
    adds r0, r0, r3
    ldr r1, [r4, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    cmp r1, #0
    beq lbl_0805a76a
    adds r0, r1, #0
    bl check_clipdata_behavior_change_bldalpha
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    cmp r1, #0
    beq lbl_0805a76a
    ldr r0, lbl_0805a754 @ =0x0000ffff
    cmp r1, r0
    bne lbl_0805a75c
    ldr r1, lbl_0805a758 @ =0x030056c4
    ldrb r0, [r1, #3]
    ldrb r1, [r1, #2]
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
    b lbl_0805a76a
    .align 2, 0
lbl_0805a750: .4byte 0x03005450
lbl_0805a754: .4byte 0x0000ffff
lbl_0805a758: .4byte 0x030056c4
lbl_0805a75c:
    movs r0, #0xff
    ands r0, r1
    lsrs r1, r1, #8
    movs r2, #1
    movs r3, #1
    bl TransparencyUpdateBLDALPHA
lbl_0805a76a:
    pop {r4, r5}
    pop {r0}
    bx r0

    thumb_func_start check_clipdata_behavior_change_bldalpha
check_clipdata_behavior_change_bldalpha: @ 0x0805a770
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    adds r2, r1, #0
    subs r2, #0x44
    lsls r0, r2, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0xa
    bhi lbl_0805a790
    ldr r1, lbl_0805a78c @ =0x08345cc8
    lsls r0, r2, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    b lbl_0805a798
    .align 2, 0
lbl_0805a78c: .4byte 0x08345cc8
lbl_0805a790:
    movs r0, #0
    cmp r1, #0x4f
    bne lbl_0805a798
    ldr r0, lbl_0805a79c @ =0x0000ffff
lbl_0805a798:
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805a79c: .4byte 0x0000ffff

    thumb_func_start check_walking_on_crumble_block
check_walking_on_crumble_block: @ 0x0805a7a0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    ldr r5, lbl_0805a858 @ =0x030013d4
    movs r1, #0x18
    ldrsh r0, [r5, r1]
    lsrs r3, r0, #0x1f
    ldr r4, lbl_0805a85c @ =0x03001588
    adds r0, r4, #0
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #3
    bne lbl_0805a7bc
    adds r3, #1
lbl_0805a7bc:
    cmp r3, #0
    bne lbl_0805a89e
    ldrh r1, [r5, #0x12]
    adds r0, r4, #0
    adds r0, #0x72
    movs r2, #0
    ldrsh r0, [r0, r2]
    adds r3, r1, r0
    lsls r0, r3, #0xa
    lsrs r6, r0, #0x10
    ldr r2, lbl_0805a860 @ =0x0300009c
    ldrh r3, [r2, #0x1c]
    cmp r6, r3
    bls lbl_0805a7da
    ldrh r6, [r2, #0x1c]
lbl_0805a7da:
    adds r0, r4, #0
    adds r0, #0x6e
    movs r3, #0
    ldrsh r0, [r0, r3]
    adds r3, r1, r0
    cmp r3, #0
    bge lbl_0805a7ea
    movs r3, #0
lbl_0805a7ea:
    lsls r0, r3, #0xa
    lsrs r1, r0, #0x10
    adds r0, r4, #0
    adds r0, #0x74
    movs r3, #0
    ldrsh r0, [r0, r3]
    ldrh r5, [r5, #0x14]
    adds r3, r0, r5
    adds r0, r3, #2
    lsls r0, r0, #0xa
    lsrs r5, r0, #0x10
    ldrh r0, [r2, #0x1e]
    cmp r5, r0
    bls lbl_0805a808
    ldrh r5, [r2, #0x1e]
lbl_0805a808:
    adds r4, r1, #0
    cmp r4, r6
    bhi lbl_0805a89e
    ldr r1, lbl_0805a864 @ =0x03005450
    mov r8, r1
    ldr r7, lbl_0805a868 @ =0x00000401
lbl_0805a814:
    ldr r1, lbl_0805a860 @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    muls r0, r5, r0
    adds r0, r0, r4
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r2, r8
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    cmp r3, #0x23
    bne lbl_0805a86c
    movs r3, #0
    ldr r1, lbl_0805a858 @ =0x030013d4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805a840
    cmp r0, #0x12
    bne lbl_0805a848
lbl_0805a840:
    ldrb r0, [r1, #5]
    cmp r0, #0
    beq lbl_0805a848
    movs r3, #1
lbl_0805a848:
    lsls r3, r3, #0x18
    lsrs r3, r3, #0x18
    movs r0, #4
    adds r1, r4, #0
    adds r2, r5, #0
    bl store_broken_reform_block
    b lbl_0805a894
    .align 2, 0
lbl_0805a858: .4byte 0x030013d4
lbl_0805a85c: .4byte 0x03001588
lbl_0805a860: .4byte 0x0300009c
lbl_0805a864: .4byte 0x03005450
lbl_0805a868: .4byte 0x00000401
lbl_0805a86c:
    cmp r3, #0x2e
    bne lbl_0805a894
    movs r0, #5
    adds r1, r4, #0
    adds r2, r5, #0
    movs r3, #1
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805a894
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_bg1_block_value
    adds r0, r7, #0
    adds r1, r5, #0
    adds r2, r4, #0
    bl set_clipdata_block_value
lbl_0805a894:
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, r6
    bls lbl_0805a814
lbl_0805a89e:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start check_touching_transition_on_elevator
check_touching_transition_on_elevator: @ 0x0805a8a8
    push {r4, r5, r6, r7, lr}
    ldr r2, lbl_0805a8e4 @ =0x030013d4
    ldrh r1, [r2, #0x10]
    movs r0, #0x40
    eors r1, r0
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r7, r0, #0x1f
    ldrh r3, [r2, #0x12]
    ldr r1, lbl_0805a8e8 @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r6, r1, #0
    cmp r3, r0
    ble lbl_0805a8c8
    adds r3, r0, #0
lbl_0805a8c8:
    lsls r0, r3, #0xa
    lsrs r5, r0, #0x10
    cmp r7, #0
    bne lbl_0805a8f0
    ldr r0, lbl_0805a8ec @ =0x03001588
    adds r0, #0x74
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    adds r3, r0, #0
    adds r3, #0x80
    b lbl_0805a900
    .align 2, 0
lbl_0805a8e4: .4byte 0x030013d4
lbl_0805a8e8: .4byte 0x0300009c
lbl_0805a8ec: .4byte 0x03001588
lbl_0805a8f0:
    ldr r0, lbl_0805a90c @ =0x03001588
    adds r0, #0x70
    movs r1, #0
    ldrsh r0, [r0, r1]
    ldrh r2, [r2, #0x14]
    adds r0, r0, r2
    adds r3, r0, #0
    subs r3, #0x80
lbl_0805a900:
    lsls r0, r3, #0x10
    lsrs r1, r0, #0x10
    cmp r3, #0
    bge lbl_0805a910
    movs r1, #0
    b lbl_0805a91c
    .align 2, 0
lbl_0805a90c: .4byte 0x03001588
lbl_0805a910:
    ldrh r2, [r6, #0x1e]
    lsls r0, r2, #6
    cmp r1, r0
    ble lbl_0805a91c
    lsls r0, r2, #0x16
    lsrs r1, r0, #0x10
lbl_0805a91c:
    lsrs r4, r1, #6
    ldrh r0, [r6, #0x1c]
    muls r0, r4, r0
    adds r0, r0, r5
    ldr r1, [r6, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r3, [r0]
    ldr r0, lbl_0805a944 @ =0x03005450
    ldr r1, [r0, #8]
    lsls r0, r3, #1
    adds r0, r0, r1
    ldrh r1, [r0]
    movs r3, #0
    cmp r7, #0
    bne lbl_0805a948
    cmp r1, #4
    bne lbl_0805a94e
    b lbl_0805a952
    .align 2, 0
lbl_0805a944: .4byte 0x03005450
lbl_0805a948:
    cmp r1, #5
    bne lbl_0805a94e
    movs r3, #1
lbl_0805a94e:
    cmp r3, #0
    beq lbl_0805a966
lbl_0805a952:
    adds r0, r4, #0
    adds r1, r5, #0
    bl check_area_connection
    cmp r0, #0
    bne lbl_0805a966
    adds r0, r4, #0
    adds r1, r5, #0
    bl check_enter_door
lbl_0805a966:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start check_touching_transition_or_tank
check_touching_transition_or_tank: @ 0x0805a96c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    ldr r2, lbl_0805a998 @ =0x03001588
    adds r0, r2, #0
    adds r0, #0x72
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    ldr r1, lbl_0805a99c @ =0x030013d4
    asrs r0, r0, #0x11
    ldrh r3, [r1, #0x12]
    adds r4, r0, r3
    adds r3, r2, #0
    adds r5, r1, #0
    cmp r4, #0
    bge lbl_0805a9a4
    movs r4, #0
    ldr r6, lbl_0805a9a0 @ =0x0300009c
    b lbl_0805a9b2
    .align 2, 0
lbl_0805a998: .4byte 0x03001588
lbl_0805a99c: .4byte 0x030013d4
lbl_0805a9a0: .4byte 0x0300009c
lbl_0805a9a4:
    ldr r1, lbl_0805a9cc @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    lsls r0, r0, #6
    adds r6, r1, #0
    cmp r4, r0
    ble lbl_0805a9b2
    adds r4, r0, #0
lbl_0805a9b2:
    asrs r0, r4, #6
    str r0, [sp, #0x24]
    adds r0, r3, #0
    adds r0, #0x6e
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r1, [r5, #0x12]
    adds r4, r0, r1
    cmp r4, #0
    bge lbl_0805a9d0
    movs r4, #0
    b lbl_0805a9da
    .align 2, 0
lbl_0805a9cc: .4byte 0x0300009c
lbl_0805a9d0:
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805a9da
    adds r4, r0, #0
lbl_0805a9da:
    add r1, sp, #0x24
    asrs r0, r4, #6
    str r0, [r1, #4]
    ldrh r4, [r5, #0x12]
    ldrh r0, [r6, #0x1c]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805a9ec
    adds r4, r0, #0
lbl_0805a9ec:
    asrs r0, r4, #6
    str r0, [sp, #0x2c]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x11
    ldrh r2, [r5, #0x14]
    adds r4, r0, r2
    cmp r4, #0
    bge lbl_0805aa06
    movs r4, #0
    b lbl_0805aa10
lbl_0805aa06:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa10
    adds r4, r0, #0
lbl_0805aa10:
    asrs r0, r4, #6
    str r0, [sp, #0x18]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r0, r0, #0x12
    ldrh r1, [r5, #0x14]
    adds r4, r0, r1
    cmp r4, #0
    bge lbl_0805aa2a
    movs r4, #0
    b lbl_0805aa34
lbl_0805aa2a:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa34
    adds r4, r0, #0
lbl_0805aa34:
    add r2, sp, #0x18
    asrs r0, r4, #6
    str r0, [r2, #4]
    adds r0, r3, #0
    adds r0, #0x70
    ldrh r0, [r0]
    lsls r0, r0, #0x10
    asrs r1, r0, #0x12
    asrs r0, r0, #0x11
    adds r1, r1, r0
    ldrh r5, [r5, #0x14]
    adds r4, r1, r5
    cmp r4, #0
    bge lbl_0805aa54
    movs r4, #0
    b lbl_0805aa5e
lbl_0805aa54:
    ldrh r0, [r6, #0x1e]
    lsls r0, r0, #6
    cmp r4, r0
    ble lbl_0805aa5e
    adds r4, r0, #0
lbl_0805aa5e:
    asrs r0, r4, #6
    str r0, [sp, #0x20]
    ldr r0, lbl_0805aaec @ =0x0300009c
    ldrh r2, [r0, #0x1c]
    mov r8, r2
    ldr r7, [r0, #0x18]
    ldr r0, lbl_0805aaf0 @ =0x03005450
    ldr r3, [r0, #8]
    add r6, sp, #8
    add r2, sp, #0x24
    movs r5, #1
lbl_0805aa74:
    ldr r0, [sp, #0x18]
    mov r1, r8
    muls r1, r0, r1
    adds r0, r1, #0
    ldm r2!, {r1}
    adds r0, r0, r1
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r4, [r0]
    lsls r0, r4, #1
    adds r0, r0, r3
    ldrh r0, [r0]
    stm r6!, {r0}
    subs r5, #1
    cmp r5, #0
    bge lbl_0805aa74
    movs r5, #0
    ldr r0, lbl_0805aaec @ =0x0300009c
    ldrh r2, [r0, #0x1c]
    mov ip, r2
    ldr r0, [r0, #0x18]
    mov r8, r0
    ldr r0, lbl_0805aaf0 @ =0x03005450
    ldr r6, [r0, #8]
    add r7, sp, #0x10
    add r3, sp, #0x1c
    add r2, sp, #0x24
lbl_0805aaaa:
    ldm r3!, {r0}
    mov r1, ip
    muls r1, r0, r1
    adds r0, r1, #0
    ldr r1, [r2, #8]
    adds r0, r0, r1
    lsls r0, r0, #1
    add r0, r8
    ldrh r4, [r0]
    lsls r0, r4, #1
    adds r0, r0, r6
    ldrh r0, [r0]
    stm r7!, {r0}
    adds r5, #1
    cmp r5, #1
    ble lbl_0805aaaa
    ldr r1, [sp, #8]
    ldr r2, [sp, #0xc]
    adds r0, r1, #0
    orrs r0, r2
    ldr r3, [sp, #0x10]
    orrs r0, r3
    ldr r5, [sp, #0x14]
    orrs r0, r5
    cmp r0, #0
    bne lbl_0805aae0
    b lbl_0805ad5e
lbl_0805aae0:
    movs r4, #1
    rsbs r4, r4, #0
    cmp r1, #3
    bne lbl_0805aaf4
    movs r4, #0
    b lbl_0805ab0a
    .align 2, 0
lbl_0805aaec: .4byte 0x0300009c
lbl_0805aaf0: .4byte 0x03005450
lbl_0805aaf4:
    cmp r2, #3
    bne lbl_0805aafc
    movs r4, #1
    b lbl_0805ab0a
lbl_0805aafc:
    cmp r3, #4
    bne lbl_0805ab04
    movs r4, #2
    b lbl_0805ab0a
lbl_0805ab04:
    cmp r5, #5
    bne lbl_0805ab0a
    movs r4, #3
lbl_0805ab0a:
    adds r0, r4, #1
    cmp r0, #0
    beq lbl_0805ab4c
    ldr r1, lbl_0805ab48 @ =0x08345cee
    lsls r2, r4, #1
    adds r0, r2, r1
    ldrb r0, [r0]
    lsls r0, r0, #2
    mov r5, sp
    adds r5, r5, r0
    adds r5, #0x18
    ldrh r0, [r5]
    adds r1, #1
    adds r2, r2, r1
    ldrb r1, [r2]
    lsls r1, r1, #2
    mov r4, sp
    adds r4, r4, r1
    adds r4, #0x24
    ldrh r1, [r4]
    bl check_enter_door
    cmp r0, #0
    beq lbl_0805ab3c
    b lbl_0805ad5e
lbl_0805ab3c:
    ldrh r0, [r5]
    ldrh r1, [r4]
    bl check_area_connection
    b lbl_0805ad5e
    .align 2, 0
lbl_0805ab48: .4byte 0x08345cee
lbl_0805ab4c:
    ldr r0, lbl_0805ac18 @ =0x03000044
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805ab5a
    b lbl_0805ad5e
lbl_0805ab5a:
    movs r2, #0
    mov sl, r2
    movs r4, #3
    add r3, sp, #0x14
    mov r8, r3
    ldr r0, lbl_0805ac1c @ =0x083459a0
    mov sb, r0
lbl_0805ab68:
    mov r1, r8
    ldr r0, [r1]
    cmp r0, #0
    bne lbl_0805ab72
    b lbl_0805ad50
lbl_0805ab72:
    subs r0, #0x34
    cmp r0, #0xb
    bls lbl_0805ab7a
    b lbl_0805ad50
lbl_0805ab7a:
    ldr r1, lbl_0805ac20 @ =0x08345c48
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r5, [r0]
    cmp r5, #0
    bne lbl_0805ab88
    b lbl_0805ad44
lbl_0805ab88:
    ldr r2, lbl_0805ac24 @ =0x08345cee
    lsls r1, r4, #1
    adds r0, r2, #1
    adds r0, r1, r0
    ldrb r0, [r0]
    lsls r0, r0, #2
    mov r7, sp
    adds r7, r7, r0
    adds r7, #0x24
    ldrb r0, [r7]
    adds r1, r1, r2
    ldrb r1, [r1]
    lsls r1, r1, #2
    mov r6, sp
    adds r6, r6, r1
    adds r6, #0x18
    ldrb r1, [r6]
    bl sub_0806cc68
    cmp r0, #0
    bne lbl_0805abb4
    b lbl_0805ad44
lbl_0805abb4:
    ldr r1, lbl_0805ac18 @ =0x03000044
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0805ac28 @ =0x03001606
    movs r2, #0xfa
    lsls r2, r2, #2
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0805ac2c @ =0x030056a8
    mov r3, r8
    ldr r0, [r3]
    strh r0, [r1]
    ldr r0, [r7]
    strb r0, [r1, #2]
    ldr r0, [r6]
    strb r0, [r1, #3]
    cmp r5, #1
    bne lbl_0805ac40
    mov r0, sb
    ldrb r3, [r0, #0x1d]
    ldr r6, lbl_0805ac30 @ =0x083459c4
    ldr r5, lbl_0805ac34 @ =0x0300002c
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #1]
    ldr r1, lbl_0805ac38 @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    ldr r3, lbl_0805ac3c @ =0x03001530
    ldrh r1, [r3, #2]
    adds r2, r1, r2
    cmp r0, r2
    bge lbl_0805abfe
    b lbl_0805ad14
lbl_0805abfe:
    cmp r1, #0
    bne lbl_0805ac06
    movs r1, #1
    mov sl, r1
lbl_0805ac06:
    strh r2, [r3, #2]
    ldrb r1, [r5]
    lsls r1, r1, #2
    adds r1, r1, r6
    ldrh r0, [r3, #8]
    ldrb r1, [r1, #1]
    adds r0, r0, r1
    strh r0, [r3, #8]
    b lbl_0805ad14
    .align 2, 0
lbl_0805ac18: .4byte 0x03000044
lbl_0805ac1c: .4byte 0x083459a0
lbl_0805ac20: .4byte 0x08345c48
lbl_0805ac24: .4byte 0x08345cee
lbl_0805ac28: .4byte 0x03001606
lbl_0805ac2c: .4byte 0x030056a8
lbl_0805ac30: .4byte 0x083459c4
lbl_0805ac34: .4byte 0x0300002c
lbl_0805ac38: .4byte 0x083459c0
lbl_0805ac3c: .4byte 0x03001530
lbl_0805ac40:
    cmp r5, #2
    bne lbl_0805ac80
    mov r2, sb
    ldrb r3, [r2, #0x1c]
    ldr r1, lbl_0805ac70 @ =0x083459c4
    ldr r0, lbl_0805ac74 @ =0x0300002c
    ldrb r0, [r0]
    lsls r0, r0, #2
    adds r0, r0, r1
    ldrb r2, [r0]
    ldr r0, lbl_0805ac78 @ =0x083459c0
    adds r1, r3, #0
    muls r1, r2, r1
    ldrb r0, [r0]
    adds r1, r1, r0
    ldr r3, lbl_0805ac7c @ =0x03001530
    ldrh r0, [r3]
    adds r0, r0, r2
    cmp r1, r0
    blt lbl_0805ad14
    strh r0, [r3]
    strh r0, [r3, #6]
    b lbl_0805ad14
    .align 2, 0
lbl_0805ac70: .4byte 0x083459c4
lbl_0805ac74: .4byte 0x0300002c
lbl_0805ac78: .4byte 0x083459c0
lbl_0805ac7c: .4byte 0x03001530
lbl_0805ac80:
    cmp r5, #3
    bne lbl_0805acd4
    mov r0, sb
    ldrb r3, [r0, #0x1e]
    ldr r6, lbl_0805acc4 @ =0x083459c4
    ldr r5, lbl_0805acc8 @ =0x0300002c
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #2]
    ldr r1, lbl_0805accc @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #2]
    adds r0, r0, r1
    ldr r3, lbl_0805acd0 @ =0x03001530
    ldrb r1, [r3, #4]
    adds r2, r1, r2
    cmp r0, r2
    blt lbl_0805ad14
    cmp r1, #0
    bne lbl_0805acb0
    movs r1, #1
    mov sl, r1
lbl_0805acb0:
    strb r2, [r3, #4]
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r0, [r0, #2]
    ldrb r2, [r3, #0xa]
    adds r0, r0, r2
    strb r0, [r3, #0xa]
    b lbl_0805ad14
    .align 2, 0
lbl_0805acc4: .4byte 0x083459c4
lbl_0805acc8: .4byte 0x0300002c
lbl_0805accc: .4byte 0x083459c0
lbl_0805acd0: .4byte 0x03001530
lbl_0805acd4:
    cmp r5, #4
    bne lbl_0805ad14
    mov r0, sb
    ldrb r3, [r0, #0x1f]
    ldr r6, lbl_0805ad70 @ =0x083459c4
    ldr r5, lbl_0805ad74 @ =0x0300002c
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r2, [r0, #3]
    ldr r1, lbl_0805ad78 @ =0x083459c0
    adds r0, r3, #0
    muls r0, r2, r0
    ldrb r1, [r1, #3]
    adds r0, r0, r1
    ldr r3, lbl_0805ad7c @ =0x03001530
    ldrb r1, [r3, #5]
    adds r2, r1, r2
    cmp r0, r2
    blt lbl_0805ad14
    cmp r1, #0
    bne lbl_0805ad04
    movs r1, #1
    mov sl, r1
lbl_0805ad04:
    strb r2, [r3, #5]
    ldrb r0, [r5]
    lsls r0, r0, #2
    adds r0, r0, r6
    ldrb r0, [r0, #3]
    ldrb r2, [r3, #0xb]
    adds r0, r0, r2
    strb r0, [r3, #0xb]
lbl_0805ad14:
    ldr r1, lbl_0805ad80 @ =0x08345c48
    mov r3, r8
    ldr r0, [r3]
    subs r0, #0x34
    lsls r0, r0, #3
    adds r0, r0, r1
    ldrb r0, [r0, #2]
    mov r1, sl
    adds r5, r0, r1
    movs r0, #1
    rsbs r0, r0, #0
    cmp r5, r0
    beq lbl_0805ad44
    ldr r0, lbl_0805ad84 @ =0x030013d4
    ldrh r3, [r0, #0x14]
    ldrh r0, [r0, #0x12]
    str r0, [sp]
    movs r0, #0
    str r0, [sp, #4]
    movs r0, #0x11
    adds r1, r5, #0
    movs r2, #6
    bl SpriteSpawnPrimary
lbl_0805ad44:
    ldr r0, lbl_0805ad88 @ =0x03000044
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805ad5e
lbl_0805ad50:
    movs r2, #4
    rsbs r2, r2, #0
    add r8, r2
    subs r4, #1
    cmp r4, #0
    blt lbl_0805ad5e
    b lbl_0805ab68
lbl_0805ad5e:
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ad70: .4byte 0x083459c4
lbl_0805ad74: .4byte 0x0300002c
lbl_0805ad78: .4byte 0x083459c0
lbl_0805ad7c: .4byte 0x03001530
lbl_0805ad80: .4byte 0x08345c48
lbl_0805ad84: .4byte 0x030013d4
lbl_0805ad88: .4byte 0x03000044

    thumb_func_start BGClipFinishCollectingTank
BGClipFinishCollectingTank: @ 0x0805ad8c
    push {r4, r5, r6, lr}
    ldr r1, lbl_0805addc @ =0x03000044
    movs r0, #0
    strb r0, [r1]
    ldr r4, lbl_0805ade0 @ =0x030056a8
    ldrh r0, [r4]
    subs r0, #0x34
    ldr r1, lbl_0805ade4 @ =0x08345c48
    lsls r0, r0, #3
    adds r5, r0, r1
    ldrb r0, [r5]
    cmp r0, #0
    beq lbl_0805add6
    ldrb r0, [r5, #1]
    movs r6, #0
    cmp r0, #0
    beq lbl_0805adb0
    ldr r6, lbl_0805ade8 @ =0x0000043c
lbl_0805adb0:
    ldrb r1, [r4, #3]
    ldrb r2, [r4, #2]
    movs r0, #0
    bl set_bg1_block_value
    adds r0, r6, #0
    ldrb r1, [r4, #3]
    ldrb r2, [r4, #2]
    bl set_clipdata_block_value
    ldrb r0, [r4, #2]
    ldrb r1, [r4, #3]
    ldrb r2, [r5]
    bl set_item_as_collected
    ldrb r0, [r4, #2]
    ldrb r1, [r4, #3]
    bl update_minimap_square_for_collected_item
lbl_0805add6:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805addc: .4byte 0x03000044
lbl_0805ade0: .4byte 0x030056a8
lbl_0805ade4: .4byte 0x08345c48
lbl_0805ade8: .4byte 0x0000043c

    thumb_func_start finish_collecting_ability
finish_collecting_ability: @ 0x0805adec
    push {r4, lr}
    ldr r4, lbl_0805ae18 @ =0x030013d4
    ldrh r0, [r4, #0x12]
    lsrs r0, r0, #6
    ldrh r1, [r4, #0x14]
    lsrs r1, r1, #6
    movs r2, #0x80
    bl set_item_as_collected
    ldrh r0, [r4, #0x12]
    lsrs r0, r0, #6
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldrh r1, [r4, #0x14]
    lsrs r1, r1, #6
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    bl update_minimap_square_for_collected_item
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ae18: .4byte 0x030013d4

    thumb_func_start check_grabbing_crumble_block
check_grabbing_crumble_block: @ 0x0805ae1c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    ldr r0, lbl_0805aea0 @ =0x03001588
    adds r0, #0x56
    ldrb r0, [r0]
    cmp r0, #5
    bne lbl_0805af0c
    movs r0, #0
    mov r8, r0
    subs r0, #0x6c
    mov sb, r0
    ldr r2, lbl_0805aea4 @ =0x030013d4
    ldrh r1, [r2, #0xe]
    movs r0, #0x10
    ands r0, r1
    movs r7, #0x20
    rsbs r7, r7, #0
    cmp r0, #0
    beq lbl_0805ae4c
    movs r7, #0x20
lbl_0805ae4c:
    ldrb r0, [r2]
    cmp r0, #0x15
    beq lbl_0805ae58
    cmp r0, #0x3d
    beq lbl_0805ae58
    rsbs r7, r7, #0
lbl_0805ae58:
    cmp r3, #0
    bne lbl_0805aede
    ldrh r0, [r2, #0x12]
    adds r0, r0, r7
    lsls r0, r0, #0xa
    lsrs r4, r0, #0x10
    adds r6, r4, #0
    ldrh r0, [r2, #0x14]
    add r0, sb
    lsls r0, r0, #0xa
    lsrs r3, r0, #0x10
    adds r5, r3, #0
    ldr r2, lbl_0805aea8 @ =0x03005450
    ldr r1, lbl_0805aeac @ =0x0300009c
    ldrh r0, [r1, #0x1c]
    muls r0, r3, r0
    adds r0, r0, r4
    ldr r1, [r1, #0x18]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    ldr r1, [r2, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    cmp r0, #0x23
    bne lbl_0805aeb0
    movs r0, #4
    adds r1, r4, #0
    adds r2, r3, #0
    movs r3, #0
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805aede
    b lbl_0805af06
    .align 2, 0
lbl_0805aea0: .4byte 0x03001588
lbl_0805aea4: .4byte 0x030013d4
lbl_0805aea8: .4byte 0x03005450
lbl_0805aeac: .4byte 0x0300009c
lbl_0805aeb0:
    cmp r0, #0x2e
    bne lbl_0805aede
    movs r0, #5
    adds r1, r6, #0
    adds r2, r5, #0
    movs r3, #1
    bl store_broken_reform_block
    cmp r0, #0
    beq lbl_0805aede
    ldr r4, lbl_0805af18 @ =0x00000401
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl set_bg1_block_value
    adds r0, r4, #0
    adds r1, r5, #0
    adds r2, r6, #0
    bl set_clipdata_block_value
    movs r0, #0
    mov r8, r0
lbl_0805aede:
    mov r0, r8
    cmp r0, #0
    bne lbl_0805af06
    ldr r1, lbl_0805af1c @ =0x030013d4
    ldrh r0, [r1, #0x14]
    add r0, sb
    ldrh r1, [r1, #0x12]
    adds r1, r1, r7
    bl sub_08057df8
    movs r1, #0x80
    lsls r1, r1, #0x11
    ands r1, r0
    cmp r1, #0
    bne lbl_0805af00
    movs r0, #1
    mov r8, r0
lbl_0805af00:
    mov r0, r8
    cmp r0, #0
    beq lbl_0805af0c
lbl_0805af06:
    movs r0, #0xfe
    bl SamusSetPose
lbl_0805af0c:
    pop {r3, r4}
    mov r8, r3
    mov sb, r4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805af18: .4byte 0x00000401
lbl_0805af1c: .4byte 0x030013d4

    thumb_func_start check_opening_hatch
check_opening_hatch: @ 0x0805af20
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp]
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov sb, r1
    movs r0, #0
    mov sl, r0
    ldr r3, lbl_0805afb8 @ =0x0300545c
    adds r4, r3, #0
lbl_0805af40:
    ldrb r0, [r3]
    lsls r0, r0, #0x1f
    cmp r0, #0
    bne lbl_0805af4a
    b lbl_0805b07e
lbl_0805af4a:
    ldrb r0, [r3, #1]
    lsls r0, r0, #0x1e
    cmp r0, #0
    beq lbl_0805af54
    b lbl_0805b07e
lbl_0805af54:
    movs r1, #0
    mov r8, r1
    ldrb r0, [r3, #5]
    ldr r2, [sp]
    cmp r0, r2
    bne lbl_0805b008
    ldrb r0, [r3, #6]
    cmp r0, sb
    bhi lbl_0805b008
    adds r0, #3
    cmp sb, r0
    bgt lbl_0805b008
    ldr r0, lbl_0805afbc @ =0x08345ca8
    mov ip, r0
    ldrb r1, [r3, #3]
    lsls r1, r1, #2
    add r1, ip
    ldr r7, lbl_0805afc0 @ =0x083459d0
    ldr r6, lbl_0805afc4 @ =0x03000079
    ldrb r0, [r6]
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r1, [r1]
    ldrh r0, [r0]
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b008
    ldrb r1, [r3, #2]
    lsrs r0, r1, #4
    adds r0, #1
    lsls r0, r0, #4
    movs r5, #0xf
    adds r2, r5, #0
    ands r2, r1
    orrs r2, r0
    strb r2, [r3, #2]
    movs r1, #1
    mov r8, r1
    ldrb r0, [r3, #3]
    cmp r0, #6
    bne lbl_0805afcc
    ldr r0, lbl_0805afc8 @ =0x030054e4
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b008
    movs r2, #2
    mov r8, r2
    b lbl_0805b00e
    .align 2, 0
lbl_0805afb8: .4byte 0x0300545c
lbl_0805afbc: .4byte 0x08345ca8
lbl_0805afc0: .4byte 0x083459d0
lbl_0805afc4: .4byte 0x03000079
lbl_0805afc8: .4byte 0x030054e4
lbl_0805afcc:
    cmp r0, #7
    bne lbl_0805afe8
    ldr r0, lbl_0805afe4 @ =0x030054e4
    ldrb r0, [r0, #1]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b008
    movs r0, #2
    mov r8, r0
    b lbl_0805b00e
    .align 2, 0
lbl_0805afe4: .4byte 0x030054e4
lbl_0805afe8:
    cmp r0, #3
    bne lbl_0805b008
    ldrb r0, [r6]
    lsls r0, r0, #1
    adds r0, r0, r7
    ldrh r1, [r0]
    movs r0, #8
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b008
    mov r1, ip
    ldrb r0, [r1, #0xe]
    lsls r0, r0, #4
    ands r2, r5
    orrs r2, r0
    strb r2, [r3, #2]
lbl_0805b008:
    mov r2, r8
    cmp r2, #0
    beq lbl_0805b07e
lbl_0805b00e:
    mov r0, r8
    cmp r0, #1
    bne lbl_0805b068
    ldrb r2, [r4, #2]
    ldr r1, lbl_0805b04c @ =0x08345ca8
    ldrb r0, [r4, #3]
    lsls r0, r0, #2
    adds r1, #2
    adds r0, r0, r1
    lsrs r2, r2, #4
    ldrh r0, [r0]
    cmp r2, r0
    blo lbl_0805b05a
    ldrb r1, [r4, #1]
    movs r0, #0xf
    ands r0, r1
    movs r2, #4
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r4, #1]
    ldrb r0, [r4, #3]
    cmp r0, #2
    bls lbl_0805b050
    ldrb r1, [r4, #7]
    movs r0, #1
    bl set_hatch_as_opened
    b lbl_0805b070
    .align 2, 0
lbl_0805b04c: .4byte 0x08345ca8
lbl_0805b050:
    ldrb r1, [r4, #7]
    movs r0, #2
    bl set_hatch_as_opened
    b lbl_0805b070
lbl_0805b05a:
    ldrb r0, [r4, #1]
    movs r1, #0xf
    ands r1, r0
    movs r0, #0x10
    orrs r1, r0
    strb r1, [r4, #1]
    b lbl_0805b070
lbl_0805b068:
    ldrb r1, [r4, #2]
    movs r0, #0xf
    ands r0, r1
    strb r0, [r4, #2]
lbl_0805b070:
    ldrb r0, [r4, #2]
    movs r2, #0x10
    rsbs r2, r2, #0
    adds r1, r2, #0
    ands r0, r1
    strb r0, [r4, #2]
    b lbl_0805b08e
lbl_0805b07e:
    adds r4, #8
    adds r3, #8
    movs r0, #1
    add sl, r0
    mov r1, sl
    cmp r1, #0xf
    bgt lbl_0805b08e
    b lbl_0805af40
lbl_0805b08e:
    mov r0, r8
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start set_item_as_collected
set_item_as_collected: @ 0x0805b0a0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    ldr r0, lbl_0805b104 @ =0x03000054
    ldrb r1, [r0]
    mov ip, r0
    cmp r1, #7
    bhi lbl_0805b0fe
    adds r3, r1, #0
    movs r4, #0x40
    movs r2, #1
    lsls r0, r3, #8
    ldr r3, lbl_0805b108 @ =0x02036c00
    adds r1, r0, r3
    movs r3, #0
    ldrb r0, [r1]
    cmp r0, #0xff
    beq lbl_0805b0e0
lbl_0805b0cc:
    adds r3, #1
    adds r1, #4
    cmp r3, r4
    bge lbl_0805b0dc
    ldrb r0, [r1]
    cmp r0, #0xff
    bne lbl_0805b0cc
    movs r2, #0
lbl_0805b0dc:
    cmp r2, #0
    bne lbl_0805b0fe
lbl_0805b0e0:
    ldr r0, lbl_0805b10c @ =0x03000055
    ldrb r0, [r0]
    strb r0, [r1]
    adds r1, #1
    strb r5, [r1]
    adds r1, #1
    strb r6, [r1]
    strb r7, [r1, #1]
    ldr r0, lbl_0805b110 @ =0x03000063
    mov r2, ip
    ldrb r1, [r2]
    adds r1, r1, r0
    ldrb r0, [r1]
    adds r0, #1
    strb r0, [r1]
lbl_0805b0fe:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b104: .4byte 0x03000054
lbl_0805b108: .4byte 0x02036c00
lbl_0805b10c: .4byte 0x03000055
lbl_0805b110: .4byte 0x03000063

    thumb_func_start remove_collected_tanks
remove_collected_tanks: @ 0x0805b114
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    ldr r0, lbl_0805b198 @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805b1c8
    ldr r1, lbl_0805b19c @ =0x03000054
    ldrb r0, [r1]
    cmp r0, #7
    bhi lbl_0805b1c8
    adds r6, r0, #0
    movs r0, #0x40
    mov sl, r0
    lsls r0, r6, #8
    ldr r1, lbl_0805b1a0 @ =0x02036c00
    adds r4, r0, r1
    movs r6, #0
    ldr r2, lbl_0805b1a4 @ =0x03005450
    mov sb, r2
    ldr r7, lbl_0805b1a8 @ =0x03000055
    mov r8, r7
    ldr r0, lbl_0805b1ac @ =0x0300009c
    mov ip, r0
lbl_0805b14c:
    ldrb r0, [r4]
    cmp r0, #0xff
    beq lbl_0805b1c8
    mov r1, r8
    ldrb r1, [r1]
    cmp r0, r1
    bne lbl_0805b1c0
    movs r0, #1
    ldrsb r0, [r4, r0]
    cmp r0, #0
    blt lbl_0805b1c0
    mov r5, ip
    ldrh r1, [r5, #0x1c]
    ldrb r0, [r4, #3]
    muls r0, r1, r0
    ldrb r2, [r4, #2]
    adds r0, r0, r2
    ldr r1, [r5, #0x18]
    lsls r3, r0, #1
    adds r2, r3, r1
    ldrh r0, [r2]
    mov r7, sb
    ldr r1, [r7, #8]
    lsls r0, r0, #1
    adds r0, r0, r1
    ldrh r0, [r0]
    subs r0, #0x3c
    cmp r0, #3
    bhi lbl_0805b1b4
    ldr r1, lbl_0805b1b0 @ =0x0000043c
    adds r0, r1, #0
    strh r0, [r2]
    ldr r0, [r5, #8]
    adds r0, r3, r0
    movs r2, #0
    strh r2, [r0]
    b lbl_0805b1c0
    .align 2, 0
lbl_0805b198: .4byte 0x03000bf0
lbl_0805b19c: .4byte 0x03000054
lbl_0805b1a0: .4byte 0x02036c00
lbl_0805b1a4: .4byte 0x03005450
lbl_0805b1a8: .4byte 0x03000055
lbl_0805b1ac: .4byte 0x0300009c
lbl_0805b1b0: .4byte 0x0000043c
lbl_0805b1b4:
    movs r7, #0
    strh r7, [r2]
    mov r1, ip
    ldr r0, [r1, #8]
    adds r0, r3, r0
    strh r7, [r0]
lbl_0805b1c0:
    adds r6, #1
    adds r4, #4
    cmp r6, sl
    blt lbl_0805b14c
lbl_0805b1c8:
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start BGClipCallMotherBrainUpdateGlass
BGClipCallMotherBrainUpdateGlass: @ 0x0805b1d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x18
    lsrs r1, r0, #0x18
    ldr r0, lbl_0805b240 @ =0x03000054
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0805b234
    ldr r0, lbl_0805b244 @ =0x03000055
    ldrb r0, [r0]
    cmp r0, #4
    bne lbl_0805b234
    movs r2, #0
    lsls r0, r1, #1
    ldr r1, lbl_0805b248 @ =0x08345cf6
    adds r0, r0, r1
    ldrh r0, [r0]
    mov r8, r0
lbl_0805b1fe:
    movs r4, #0
    lsls r0, r2, #4
    adds r1, r2, #0
    adds r1, #0xd
    adds r7, r2, #1
    mov r2, r8
    adds r6, r2, r0
    lsls r5, r1, #0x10
lbl_0805b20e:
    adds r1, r4, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    adds r3, r4, #4
    lsls r3, r3, #0x10
    lsrs r3, r3, #0x10
    movs r0, #0
    lsrs r2, r5, #0x10
    bl mother_brain_update_glass
    adds r0, r4, #1
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    cmp r4, #6
    bls lbl_0805b20e
    lsls r0, r7, #0x10
    lsrs r2, r0, #0x10
    cmp r2, #4
    bls lbl_0805b1fe
lbl_0805b234:
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b240: .4byte 0x03000054
lbl_0805b244: .4byte 0x03000055
lbl_0805b248: .4byte 0x08345cf6

    thumb_func_start sub_0805b24c
sub_0805b24c: @ 0x0805b24c
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b27c @ =0x02035400
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b280 @ =0x05000200
    ldr r2, lbl_0805b284 @ =0x02035600
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b27c: .4byte 0x02035400
lbl_0805b280: .4byte 0x05000200
lbl_0805b284: .4byte 0x02035600

    thumb_func_start sub_0805b288
sub_0805b288: @ 0x0805b288
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b2b8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2bc @ =0x05000200
    ldr r2, lbl_0805b2c0 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2b8: .4byte 0x02035000
lbl_0805b2bc: .4byte 0x05000200
lbl_0805b2c0: .4byte 0x02035200

    thumb_func_start sub_0805b2c4
sub_0805b2c4: @ 0x0805b2c4
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b2f4 @ =0x02035400
    ldr r2, lbl_0805b2f8 @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b2fc @ =0x02035600
    ldr r2, lbl_0805b300 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b2f4: .4byte 0x02035400
lbl_0805b2f8: .4byte 0x02035000
lbl_0805b2fc: .4byte 0x02035600
lbl_0805b300: .4byte 0x02035200

    thumb_func_start sub_0805b304
sub_0805b304: @ 0x0805b304
    push {r4, r5, lr}
    sub sp, #4
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805b334 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b338 @ =0x05000200
    ldr r2, lbl_0805b33c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b334: .4byte 0x02035800
lbl_0805b338: .4byte 0x05000200
lbl_0805b33c: .4byte 0x02035a00

    thumb_func_start sub_0805b340
sub_0805b340: @ 0x0805b340
    push {lr}
    bl sub_0805b24c
    bl sub_0805b288
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0805b350
sub_0805b350: @ 0x0805b350
    push {r4, r5, lr}
    sub sp, #4
    ldr r1, lbl_0805b380 @ =0x02035400
    ldr r2, lbl_0805b384 @ =0x02035800
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805b388 @ =0x02035600
    ldr r2, lbl_0805b38c @ =0x02035a00
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b380: .4byte 0x02035400
lbl_0805b384: .4byte 0x02035800
lbl_0805b388: .4byte 0x02035600
lbl_0805b38c: .4byte 0x02035a00

    thumb_func_start sub_0805b390
sub_0805b390: @ 0x0805b390
    push {r4, lr}
    sub sp, #4
    ldr r4, lbl_0805b3ec @ =0x03005520
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b3e4
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3c0
    ldr r1, lbl_0805b3f0 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3c0:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b3e4
    ldr r1, lbl_0805b3f4 @ =0x02035200
    ldr r2, lbl_0805b3f8 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b3e4:
    add sp, #4
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b3ec: .4byte 0x03005520
lbl_0805b3f0: .4byte 0x02035000
lbl_0805b3f4: .4byte 0x02035200
lbl_0805b3f8: .4byte 0x05000200

    thumb_func_start sub_0805b3fc
sub_0805b3fc: @ 0x0805b3fc
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805b45c @ =0x03000c72
    movs r1, #0
    ldrsh r4, [r0, r1]
    cmp r4, #2
    bne lbl_0805b470
    ldr r5, lbl_0805b460 @ =0x03005520
    ldrb r1, [r5, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b436
    ldr r1, lbl_0805b464 @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #1
    eors r0, r1
    strb r0, [r5, #4]
lbl_0805b436:
    ldrb r0, [r5, #4]
    ands r4, r0
    cmp r4, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b468 @ =0x02035240
    ldr r2, lbl_0805b46c @ =0x05000240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r0, [r5, #4]
    movs r1, #2
    eors r0, r1
    strb r0, [r5, #4]
    b lbl_0805b4c0
    .align 2, 0
lbl_0805b45c: .4byte 0x03000c72
lbl_0805b460: .4byte 0x03005520
lbl_0805b464: .4byte 0x02035000
lbl_0805b468: .4byte 0x02035240
lbl_0805b46c: .4byte 0x05000240
lbl_0805b470:
    ldr r4, lbl_0805b4c8 @ =0x03005520
    ldrb r1, [r4, #4]
    cmp r1, #0
    beq lbl_0805b4c0
    movs r0, #1
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b49c
    ldr r1, lbl_0805b4cc @ =0x02035000
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfe
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b49c:
    ldrb r1, [r4, #4]
    movs r0, #2
    ands r0, r1
    cmp r0, #0
    beq lbl_0805b4c0
    ldr r1, lbl_0805b4d0 @ =0x02035200
    ldr r2, lbl_0805b4d4 @ =0x05000200
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldrb r1, [r4, #4]
    movs r0, #0xfd
    ands r0, r1
    strb r0, [r4, #4]
lbl_0805b4c0:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b4c8: .4byte 0x03005520
lbl_0805b4cc: .4byte 0x02035000
lbl_0805b4d0: .4byte 0x02035200
lbl_0805b4d4: .4byte 0x05000200

    thumb_func_start sub_0805b4d8
sub_0805b4d8: @ 0x0805b4d8
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0xc
    lsls r0, r0, #0x18
    lsrs r7, r0, #0x18
    ldr r2, lbl_0805b508 @ =0x08345d00
    ldr r3, lbl_0805b50c @ =0x03005520
    ldrb r1, [r3]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    mov r8, r2
    adds r6, r3, #0
    cmp r0, #0
    beq lbl_0805b510
    ldrb r0, [r6, #5]
    movs r5, #3
    cmp r0, #0
    bne lbl_0805b51c
    movs r5, #1
    b lbl_0805b51c
    .align 2, 0
lbl_0805b508: .4byte 0x08345d00
lbl_0805b50c: .4byte 0x03005520
lbl_0805b510:
    ldrb r1, [r6, #5]
    movs r5, #2
    rsbs r0, r1, #0
    orrs r0, r1
    asrs r0, r0, #0x1f
    ands r5, r0
lbl_0805b51c:
    ldr r0, lbl_0805b574 @ =0x02035000
    str r0, [sp, #8]
    ldr r0, lbl_0805b578 @ =0x02035400
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x12]
    add r4, sp, #8
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_0805baac
    ldr r0, lbl_0805b57c @ =0x02035200
    str r0, [sp, #8]
    ldr r0, lbl_0805b580 @ =0x02035600
    str r0, [sp, #4]
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    add r0, r8
    ldrh r0, [r0, #0x14]
    str r0, [sp]
    adds r0, r5, #0
    adds r1, r7, #0
    add r2, sp, #4
    adds r3, r4, #0
    bl sub_0805baac
    movs r0, #3
    strb r0, [r6, #4]
    add sp, #0xc
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b574: .4byte 0x02035000
lbl_0805b578: .4byte 0x02035400
lbl_0805b57c: .4byte 0x02035200
lbl_0805b580: .4byte 0x02035600

    thumb_func_start power_bomb_yellow_tint
power_bomb_yellow_tint: @ 0x0805b584
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, lbl_0805b618 @ =0x030056f4
    ldrb r0, [r0]
    movs r7, #0xf0
    cmp r0, #0
    bne lbl_0805b598
    adds r7, #0x10
lbl_0805b598:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r4, lbl_0805b61c @ =0x02035000
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    lsls r0, r6, #5
    adds r5, r0, r4
    lsls r4, r6, #4
    cmp r4, r7
    bge lbl_0805b604
    movs r0, #0xf8
    lsls r0, r0, #2
    mov ip, r0
    movs r6, #0xf8
    lsls r6, r6, #7
lbl_0805b5c2:
    movs r0, #0xf
    ands r0, r4
    cmp r0, #0
    beq lbl_0805b5fc
    ldrh r2, [r5]
    movs r3, #0x1f
    ands r3, r2
    mov r1, ip
    ands r1, r2
    adds r0, r6, #0
    ands r0, r2
    lsrs r0, r0, #0xa
    adds r3, #5
    lsls r1, r1, #0x13
    movs r2, #0xa0
    lsls r2, r2, #0x13
    adds r1, r1, r2
    lsrs r1, r1, #0x18
    cmp r3, #0x1f
    bls lbl_0805b5ec
    movs r3, #0x1f
lbl_0805b5ec:
    cmp r1, #0x1f
    bls lbl_0805b5f2
    movs r1, #0x1f
lbl_0805b5f2:
    lsls r0, r0, #0xa
    lsls r1, r1, #5
    orrs r0, r1
    orrs r0, r3
    strh r0, [r5]
lbl_0805b5fc:
    adds r4, #1
    adds r5, #2
    cmp r4, r7
    blt lbl_0805b5c2
lbl_0805b604:
    ldr r2, lbl_0805b620 @ =0x03005520
    ldrb r1, [r2, #4]
    movs r0, #1
    orrs r0, r1
    strb r0, [r2, #4]
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b618: .4byte 0x030056f4
lbl_0805b61c: .4byte 0x02035000
lbl_0805b620: .4byte 0x03005520

    thumb_func_start sub_0805b624
sub_0805b624: @ 0x0805b624
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    adds r5, r0, #0
    adds r4, r1, #0
    lsls r2, r2, #0x18
    asrs r2, r2, #0x18
    mov r8, r2
    movs r6, #0xff
lbl_0805b636:
    ldrh r2, [r5]
    movs r0, #0x1f
    ands r0, r2
    movs r3, #0xf8
    lsls r3, r3, #2
    adds r1, r3, #0
    adds r3, r2, #0
    ands r3, r1
    lsrs r3, r3, #5
    movs r7, #0xf8
    lsls r7, r7, #7
    adds r1, r7, #0
    ands r2, r1
    lsrs r2, r2, #0xa
    adds r0, r0, r3
    adds r0, r0, r2
    movs r1, #3
    bl __divsi3
    mov r1, r8
    adds r2, r0, r1
    cmp r2, #0
    bge lbl_0805b668
    movs r2, #0
    b lbl_0805b66e
lbl_0805b668:
    cmp r2, #0x1f
    ble lbl_0805b66e
    movs r2, #0x1f
lbl_0805b66e:
    lsls r0, r2, #0xa
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r2
    strh r0, [r4]
    subs r6, #1
    adds r5, #2
    adds r4, #2
    cmp r6, #0
    bge lbl_0805b636
    pop {r3}
    mov r8, r3
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0805b68c
sub_0805b68c: @ 0x0805b68c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sl, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b6b8
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sl
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6b8:
    cmp r7, #0x1e
    bls lbl_0805b6d0
    movs r3, #0x80
    lsls r3, r3, #2
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
    bl DMATransfer
    b lbl_0805b752
lbl_0805b6d0:
    movs r0, #0x1f
    mov sb, r0
    movs r1, #0xff
    str r1, [sp, #4]
lbl_0805b6d8:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sb
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sl
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sb
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b70a
    adds r0, #0x1f
lbl_0805b70a:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b71c
    adds r0, #0x1f
lbl_0805b71c:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b72e
    adds r0, #0x1f
lbl_0805b72e:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sl, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b6d8
lbl_0805b752:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_0805b764
sub_0805b764: @ 0x0805b764
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r0
    mov r8, r1
    mov ip, r2
    lsls r3, r3, #0x18
    lsrs r7, r3, #0x18
    cmp r7, #0
    bne lbl_0805b788
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, sb
    b lbl_0805b796
lbl_0805b788:
    cmp r7, #0x1e
    bls lbl_0805b79e
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    mov r1, r8
    mov r2, ip
lbl_0805b796:
    movs r3, #0x20
    bl DMATransfer
    b lbl_0805b820
lbl_0805b79e:
    movs r0, #0x1f
    mov sl, r0
    movs r1, #0x1f
    str r1, [sp, #4]
lbl_0805b7a6:
    mov r2, r8
    ldrh r1, [r2]
    adds r0, r1, #0
    mov r4, sl
    ands r0, r4
    asrs r1, r1, #5
    adds r5, r1, #0
    ands r5, r4
    asrs r6, r1, #5
    ands r6, r4
    mov r2, sb
    ldrh r1, [r2]
    adds r3, r1, #0
    ands r3, r4
    asrs r1, r1, #5
    adds r2, r1, #0
    ands r2, r4
    asrs r4, r1, #5
    mov r1, sl
    ands r4, r1
    subs r0, r0, r3
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7d8
    adds r0, #0x1f
lbl_0805b7d8:
    asrs r1, r0, #5
    adds r0, r3, r1
    lsls r0, r0, #0x18
    lsrs r3, r0, #0x18
    subs r0, r5, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7ea
    adds r0, #0x1f
lbl_0805b7ea:
    asrs r1, r0, #5
    adds r0, r2, r1
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    subs r0, r6, r4
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b7fc
    adds r0, #0x1f
lbl_0805b7fc:
    asrs r1, r0, #5
    adds r0, r4, r1
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r3
    mov r2, ip
    strh r0, [r2]
    ldr r4, [sp, #4]
    subs r4, #1
    str r4, [sp, #4]
    movs r0, #2
    add sb, r0
    add ip, r0
    add r8, r0
    cmp r4, #0
    bge lbl_0805b7a6
lbl_0805b820:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0805b830
sub_0805b830: @ 0x0805b830
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r5, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r7, r2, #0x18
    cmp r7, #0
    bne lbl_0805b880
    ldr r5, lbl_0805b878 @ =0x02035800
    movs r2, #0xa0
    lsls r2, r2, #0x13
    movs r6, #0xf0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b87c @ =0x02035400
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805b94e
    .align 2, 0
lbl_0805b878: .4byte 0x02035800
lbl_0805b87c: .4byte 0x02035400
lbl_0805b880:
    ldr r1, lbl_0805b960 @ =0x02035800
    ldr r4, lbl_0805b964 @ =0x02035000
    movs r3, #0xf0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r2, r4, #0
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r5
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r5
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r5
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b8b0:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r4, r2, #1
    str r4, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805b93c
    lsls r3, r2, #4
    adds r1, r3, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805b93c
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r4, #0xf8
    lsls r4, r4, #7
    mov sb, r4
    lsls r0, r2, #5
    ldr r2, lbl_0805b964 @ =0x02035000
    adds r6, r0, r2
    subs r3, r1, r3
lbl_0805b8de:
    ldrh r1, [r6]
    movs r5, #0x1f
    ands r5, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r4, [sp, #8]
    subs r0, r4, r5
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b8fc
    adds r0, #0xf
lbl_0805b8fc:
    asrs r0, r0, #4
    adds r0, r5, r0
    lsls r0, r0, #0x18
    lsrs r5, r0, #0x18
    mov r4, r8
    subs r0, r4, r2
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b910
    adds r0, #0xf
lbl_0805b910:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r4, ip
    subs r0, r4, r1
    muls r0, r7, r0
    cmp r0, #0
    bge lbl_0805b924
    adds r0, #0xf
lbl_0805b924:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r5
    strh r0, [r6]
    adds r6, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805b8de
lbl_0805b93c:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b8b0
    ldr r0, lbl_0805b968 @ =0x03005520
    ldrb r1, [r0, #4]
    movs r0, #1
    orrs r0, r1
    ldr r1, lbl_0805b968 @ =0x03005520
    strb r0, [r1, #4]
lbl_0805b94e:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805b960: .4byte 0x02035800
lbl_0805b964: .4byte 0x02035000
lbl_0805b968: .4byte 0x03005520

    thumb_func_start sub_0805b96c
sub_0805b96c: @ 0x0805b96c
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x10
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    str r0, [sp, #4]
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r6, r2, #0x18
    cmp r6, #0
    bne lbl_0805b9bc
    ldr r5, lbl_0805b9b0 @ =0x02035a40
    ldr r2, lbl_0805b9b4 @ =0x05000240
    movs r6, #0xe0
    lsls r6, r6, #1
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    ldr r2, lbl_0805b9b8 @ =0x02035640
    str r4, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r3, r6, #0
    bl DMATransfer
    b lbl_0805ba8a
    .align 2, 0
lbl_0805b9b0: .4byte 0x02035a40
lbl_0805b9b4: .4byte 0x05000240
lbl_0805b9b8: .4byte 0x02035640
lbl_0805b9bc:
    ldr r1, lbl_0805ba9c @ =0x02035a40
    ldr r2, lbl_0805baa0 @ =0x02035240
    movs r3, #0xe0
    lsls r3, r3, #1
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    movs r0, #0x1f
    ands r0, r4
    str r0, [sp, #8]
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r4
    lsrs r0, r0, #5
    mov r8, r0
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r4
    lsrs r0, r0, #0xa
    mov ip, r0
    movs r2, #0
lbl_0805b9ea:
    ldr r1, [sp, #4]
    asrs r1, r2
    movs r0, #1
    ands r1, r0
    adds r7, r2, #1
    str r7, [sp, #0xc]
    cmp r1, #0
    beq lbl_0805ba78
    lsls r0, r2, #4
    adds r3, r0, #1
    adds r1, r0, #0
    adds r1, #0x10
    cmp r3, r1
    bge lbl_0805ba78
    movs r0, #0xf8
    lsls r0, r0, #2
    mov sl, r0
    movs r2, #0xf8
    lsls r2, r2, #7
    mov sb, r2
    lsls r0, r3, #1
    ldr r7, lbl_0805baa4 @ =0x02035200
    adds r5, r0, r7
    subs r3, r1, r3
lbl_0805ba1a:
    ldrh r1, [r5]
    movs r4, #0x1f
    ands r4, r1
    mov r0, sl
    ands r0, r1
    lsrs r2, r0, #5
    mov r0, sb
    ands r0, r1
    lsrs r1, r0, #0xa
    ldr r7, [sp, #8]
    subs r0, r7, r4
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba38
    adds r0, #0xf
lbl_0805ba38:
    asrs r0, r0, #4
    adds r0, r4, r0
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    mov r7, r8
    subs r0, r7, r2
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba4c
    adds r0, #0xf
lbl_0805ba4c:
    asrs r0, r0, #4
    adds r0, r2, r0
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    mov r7, ip
    subs r0, r7, r1
    muls r0, r6, r0
    cmp r0, #0
    bge lbl_0805ba60
    adds r0, #0xf
lbl_0805ba60:
    asrs r0, r0, #4
    adds r0, r1, r0
    lsls r0, r0, #0x18
    lsrs r0, r0, #0xe
    lsls r1, r2, #5
    orrs r0, r1
    orrs r0, r4
    strh r0, [r5]
    adds r5, #2
    subs r3, #1
    cmp r3, #0
    bne lbl_0805ba1a
lbl_0805ba78:
    ldr r2, [sp, #0xc]
    cmp r2, #0xf
    ble lbl_0805b9ea
    ldr r0, lbl_0805baa8 @ =0x03005520
    ldrb r1, [r0, #4]
    movs r0, #2
    orrs r0, r1
    ldr r1, lbl_0805baa8 @ =0x03005520
    strb r0, [r1, #4]
lbl_0805ba8a:
    add sp, #0x10
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805ba9c: .4byte 0x02035a40
lbl_0805baa0: .4byte 0x02035240
lbl_0805baa4: .4byte 0x02035200
lbl_0805baa8: .4byte 0x03005520

    thumb_func_start sub_0805baac
sub_0805baac: @ 0x0805baac
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #8
    mov sb, r2
    mov r8, r3
    ldr r2, [sp, #0x28]
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov ip, r0
    lsls r1, r1, #0x18
    lsrs r7, r1, #0x18
    lsls r2, r2, #0x10
    lsrs r2, r2, #0x10
    str r2, [sp]
    movs r2, #0
lbl_0805bad0:
    ldr r0, [sp]
    asrs r0, r2
    movs r1, #1
    ands r0, r1
    cmp r0, #0
    bne lbl_0805baf2
    mov r1, sb
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #0x20
    str r0, [r1]
    adds r2, #1
    str r2, [sp, #4]
    b lbl_0805bbcc
lbl_0805baf2:
    adds r2, #1
    str r2, [sp, #4]
    movs r6, #0x1f
    movs r0, #0xf
    mov sl, r0
lbl_0805bafc:
    mov r1, sb
    ldr r2, [r1]
    ldrh r1, [r2]
    adds r3, r6, #0
    ands r3, r1
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r5, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r4, r0, #0xa
    mov r0, ip
    cmp r0, #1
    beq lbl_0805bb4a
    cmp r0, #1
    bgt lbl_0805bb26
    cmp r0, #0
    beq lbl_0805bb32
    b lbl_0805bba4
lbl_0805bb26:
    mov r1, ip
    cmp r1, #2
    beq lbl_0805bb68
    cmp r1, #3
    beq lbl_0805bb86
    b lbl_0805bba4
lbl_0805bb32:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r3, r0, #5
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r5, r0, #5
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r4, r0, #5
    b lbl_0805bba2
lbl_0805bb4a:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r6, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r6, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r6, r0
    b lbl_0805bba2
lbl_0805bb68:
    adds r0, r3, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    ands r3, r6
    adds r0, r5, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r5, r5, r0
    ands r5, r6
    adds r0, r4, #0
    muls r0, r7, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    b lbl_0805bba2
lbl_0805bb86:
    subs r0, r6, r3
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    ands r3, r6
    subs r0, r6, r5
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r5, r5, r0
    ands r5, r6
    subs r0, r6, r4
    muls r0, r7, r0
    asrs r0, r0, #5
    adds r4, r4, r0
lbl_0805bba2:
    ands r4, r6
lbl_0805bba4:
    mov r0, r8
    ldr r1, [r0]
    lsls r0, r5, #5
    orrs r3, r0
    lsls r0, r4, #0xa
    orrs r3, r0
    strh r3, [r1]
    movs r1, #1
    rsbs r1, r1, #0
    add sl, r1
    adds r0, r2, #2
    mov r1, sb
    str r0, [r1]
    mov r1, r8
    ldr r0, [r1]
    adds r0, #2
    str r0, [r1]
    mov r0, sl
    cmp r0, #0
    bge lbl_0805bafc
lbl_0805bbcc:
    ldr r2, [sp, #4]
    cmp r2, #0xf
    bgt lbl_0805bbd4
    b lbl_0805bad0
lbl_0805bbd4:
    add sp, #8
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

    thumb_func_start sub_0805bbe4
sub_0805bbe4: @ 0x0805bbe4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    mov ip, r6
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    lsls r2, r2, #0x18
    lsrs r5, r2, #0x18
    movs r7, #0x1f
    adds r3, r1, #0
    ands r3, r7
    movs r0, #0xf8
    lsls r0, r0, #2
    ands r0, r1
    lsrs r4, r0, #5
    movs r0, #0xf8
    lsls r0, r0, #7
    ands r0, r1
    lsrs r2, r0, #0xa
    cmp r6, #1
    beq lbl_0805bc3e
    cmp r6, #1
    bgt lbl_0805bc18
    cmp r6, #0
    beq lbl_0805bc24
    b lbl_0805bc9e
lbl_0805bc18:
    mov r0, ip
    cmp r0, #2
    beq lbl_0805bc5e
    cmp r0, #3
    beq lbl_0805bc7e
    b lbl_0805bc9e
lbl_0805bc24:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r3, r0, #5
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r4, r0, #5
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r2, r0, #5
    b lbl_0805bc9c
lbl_0805bc3e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    movs r1, #0x1f
    subs r3, r1, r0
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r1, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r1, r0
    b lbl_0805bc9c
lbl_0805bc5e:
    adds r0, r3, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    adds r0, r4, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r4, r4, r0
    ands r4, r1
    adds r0, r2, #0
    muls r0, r5, r0
    asrs r0, r0, #5
    subs r2, r2, r0
    b lbl_0805bc9c
lbl_0805bc7e:
    subs r0, r7, r3
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r3, r3, r0
    movs r1, #0x1f
    ands r3, r1
    subs r0, r7, r4
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r4, r4, r0
    ands r4, r1
    subs r0, r7, r2
    muls r0, r5, r0
    asrs r0, r0, #5
    adds r2, r2, r0
lbl_0805bc9c:
    ands r2, r1
lbl_0805bc9e:
    lsls r0, r4, #5
    orrs r3, r0
    lsls r0, r2, #0xa
    orrs r3, r0
    lsls r0, r3, #0x10
    lsrs r0, r0, #0x10
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_0805bcb0
sub_0805bcb0: @ 0x0805bcb0
    push {r4, r5, r6, r7, lr}
    ldr r0, lbl_0805bccc @ =0x03005520
    ldrb r1, [r0, #5]
    adds r6, r0, #0
    cmp r1, #0
    beq lbl_0805bcd4
    ldr r2, lbl_0805bcd0 @ =0x08345d00
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r3, [r0, #0x10]
    b lbl_0805bce2
    .align 2, 0
lbl_0805bccc: .4byte 0x03005520
lbl_0805bcd0: .4byte 0x08345d00
lbl_0805bcd4:
    ldr r2, lbl_0805bcf8 @ =0x08345d00
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r3, [r0, #8]
lbl_0805bce2:
    adds r7, r2, #0
    ldr r1, lbl_0805bcfc @ =0x08345fd0
    lsls r2, r3, #3
    adds r0, r2, r1
    ldrb r4, [r0, #4]
    ldrb r0, [r6, #2]
    cmp r0, #0
    bne lbl_0805bd00
    movs r5, #0
    b lbl_0805bd10
    .align 2, 0
lbl_0805bcf8: .4byte 0x08345d00
lbl_0805bcfc: .4byte 0x08345fd0
lbl_0805bd00:
    ldrb r0, [r6, #2]
    movs r5, #2
    cmp r0, r4
    beq lbl_0805bd10
    movs r5, #1
    cmp r0, r4
    ble lbl_0805bd10
    movs r5, #3
lbl_0805bd10:
    cmp r5, #1
    bgt lbl_0805bd20
    adds r0, r2, r1
    ldrb r1, [r6, #2]
    ldr r0, [r0]
    adds r0, r0, r1
    ldrb r4, [r0]
    b lbl_0805bd22
lbl_0805bd20:
    movs r4, #0
lbl_0805bd22:
    ldrb r1, [r6]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r7
    ldrb r3, [r0, #0x16]
    ldr r0, lbl_0805bd48 @ =0x0875fd78
    lsls r2, r3, #2
    adds r2, r2, r0
    adds r0, r5, #0
    adds r1, r4, #0
    ldr r2, [r2]
    bl _call_via_r2
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805bd4c
    movs r0, #0
    b lbl_0805bd52
    .align 2, 0
lbl_0805bd48: .4byte 0x0875fd78
lbl_0805bd4c:
    movs r0, #0
    strb r0, [r6, #2]
    movs r0, #1
lbl_0805bd52:
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

    thumb_func_start sub_0805bd58
sub_0805bd58: @ 0x0805bd58
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r0, #1
    beq lbl_0805bd88
    cmp r0, #1
    bgt lbl_0805bd72
    cmp r0, #0
    beq lbl_0805bd7c
    b lbl_0805bdc0
lbl_0805bd72:
    cmp r2, #2
    beq lbl_0805bda0
    cmp r2, #3
    beq lbl_0805bdb6
    b lbl_0805bdc0
lbl_0805bd7c:
    ldr r0, lbl_0805bd98 @ =0x03005520
    ldrb r2, [r0, #5]
    cmp r2, #0
    bne lbl_0805bd88
    ldr r0, lbl_0805bd9c @ =0x030013ae
    strh r2, [r0]
lbl_0805bd88:
    adds r0, r1, #0
    bl sub_0805b4d8
    ldr r1, lbl_0805bd98 @ =0x03005520
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_0805bdc0
    .align 2, 0
lbl_0805bd98: .4byte 0x03005520
lbl_0805bd9c: .4byte 0x030013ae
lbl_0805bda0:
    ldr r4, lbl_0805bdbc @ =0x03005520
    ldrb r0, [r4, #5]
    cmp r0, #0
    bne lbl_0805bdb0
    bl sub_0805b2c4
    movs r0, #3
    strb r0, [r4, #4]
lbl_0805bdb0:
    ldrb r0, [r4, #2]
    adds r0, #1
    strb r0, [r4, #2]
lbl_0805bdb6:
    movs r0, #1
    b lbl_0805bdc2
    .align 2, 0
lbl_0805bdbc: .4byte 0x03005520
lbl_0805bdc0:
    movs r0, #0
lbl_0805bdc2:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start sub_0805bdc8
sub_0805bdc8: @ 0x0805bdc8
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r0, #1
    beq lbl_0805bdf8
    cmp r0, #1
    bgt lbl_0805bde2
    cmp r0, #0
    beq lbl_0805bdec
    b lbl_0805be74
lbl_0805bde2:
    cmp r2, #2
    beq lbl_0805be10
    cmp r2, #3
    beq lbl_0805be6c
    b lbl_0805be74
lbl_0805bdec:
    ldr r0, lbl_0805be08 @ =0x03005520
    ldrb r2, [r0, #5]
    cmp r2, #0
    bne lbl_0805bdf8
    ldr r0, lbl_0805be0c @ =0x030013ae
    strh r2, [r0]
lbl_0805bdf8:
    adds r0, r1, #0
    bl sub_0805b4d8
    ldr r1, lbl_0805be08 @ =0x03005520
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_0805be74
    .align 2, 0
lbl_0805be08: .4byte 0x03005520
lbl_0805be0c: .4byte 0x030013ae
lbl_0805be10:
    ldr r4, lbl_0805be30 @ =0x03005520
    ldrb r0, [r4, #5]
    cmp r0, #0
    beq lbl_0805be5c
    ldr r2, lbl_0805be34 @ =0x08345d00
    ldrb r1, [r4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805be3c
    ldr r1, lbl_0805be38 @ =0x04000050
    movs r0, #0xbf
    b lbl_0805be40
    .align 2, 0
lbl_0805be30: .4byte 0x03005520
lbl_0805be34: .4byte 0x08345d00
lbl_0805be38: .4byte 0x04000050
lbl_0805be3c:
    ldr r1, lbl_0805be50 @ =0x04000050
    movs r0, #0xff
lbl_0805be40:
    strh r0, [r1]
    ldr r2, lbl_0805be54 @ =0x04000054
    ldr r1, lbl_0805be58 @ =0x030013ae
    movs r0, #0x10
    strh r0, [r1]
    strh r0, [r2]
    b lbl_0805be64
    .align 2, 0
lbl_0805be50: .4byte 0x04000050
lbl_0805be54: .4byte 0x04000054
lbl_0805be58: .4byte 0x030013ae
lbl_0805be5c:
    bl sub_0805b2c4
    movs r0, #3
    strb r0, [r4, #4]
lbl_0805be64:
    ldr r1, lbl_0805be70 @ =0x03005520
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
lbl_0805be6c:
    movs r0, #1
    b lbl_0805be76
    .align 2, 0
lbl_0805be70: .4byte 0x03005520
lbl_0805be74:
    movs r0, #0
lbl_0805be76:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start sub_0805be7c
sub_0805be7c: @ 0x0805be7c
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    adds r2, r0, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    cmp r0, #2
    beq lbl_0805beb0
    cmp r0, #2
    ble lbl_0805be96
    cmp r0, #3
    beq lbl_0805beb8
    b lbl_0805bec0
lbl_0805be96:
    cmp r2, #0
    blt lbl_0805bec0
    adds r0, r1, #0
    bl sub_0805b4d8
    ldr r1, lbl_0805beac @ =0x03005520
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
    b lbl_0805bec0
    .align 2, 0
lbl_0805beac: .4byte 0x03005520
lbl_0805beb0:
    ldr r1, lbl_0805bebc @ =0x03005520
    ldrb r0, [r1, #2]
    adds r0, #1
    strb r0, [r1, #2]
lbl_0805beb8:
    movs r0, #1
    b lbl_0805bec2
    .align 2, 0
lbl_0805bebc: .4byte 0x03005520
lbl_0805bec0:
    movs r0, #0
lbl_0805bec2:
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0805bec8
sub_0805bec8: @ 0x0805bec8
    movs r0, #1
    bx lr

    thumb_func_start transfer_faded_palette_on_transition
transfer_faded_palette_on_transition: @ 0x0805becc
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #4
    ldr r6, lbl_0805bfb8 @ =0x03005520
    movs r0, #0
    strb r0, [r6, #2]
    bl sub_0805b24c
    ldr r0, lbl_0805bfbc @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805bef2
    bl sub_0805b304
lbl_0805bef2:
    ldr r3, lbl_0805bfc0 @ =0x08345d00
    ldrb r0, [r6]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    adds r2, r1, r3
    ldrb r0, [r2]
    movs r1, #0
    cmp r0, #0
    beq lbl_0805bf08
    ldr r1, lbl_0805bfc4 @ =0x00007fff
lbl_0805bf08:
    adds r5, r1, #0
    ldrh r1, [r2, #0x12]
    ldrh r0, [r2, #0x14]
    orrs r0, r1
    cmp r0, #0
    beq lbl_0805bf84
    movs r4, #0
    mov sl, r6
    movs r0, #1
    mov sb, r0
    ldr r7, lbl_0805bfc8 @ =0x05000200
    movs r6, #0xa0
    lsls r6, r6, #0x13
    movs r1, #0x10
    mov r8, r1
lbl_0805bf26:
    mov r1, sl
    ldrb r0, [r1]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    ldr r0, lbl_0805bfc0 @ =0x08345d00
    adds r1, r1, r0
    ldrh r0, [r1, #0x12]
    asrs r0, r4
    mov r1, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0805bf50
    mov r0, r8
    str r0, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r2, r6, #0
    movs r3, #0x20
    bl BitFill
lbl_0805bf50:
    mov r1, sl
    ldrb r0, [r1]
    lsls r1, r0, #1
    adds r1, r1, r0
    lsls r1, r1, #3
    ldr r0, lbl_0805bfc0 @ =0x08345d00
    adds r1, r1, r0
    ldrh r0, [r1, #0x14]
    asrs r0, r4
    mov r1, sb
    ands r0, r1
    cmp r0, #0
    beq lbl_0805bf7a
    mov r0, r8
    str r0, [sp]
    movs r0, #3
    adds r1, r5, #0
    adds r2, r7, #0
    movs r3, #0x20
    bl BitFill
lbl_0805bf7a:
    adds r7, #0x20
    adds r6, #0x20
    adds r4, #1
    cmp r4, #0xf
    ble lbl_0805bf26
lbl_0805bf84:
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805bfcc @ =0x02035000
    movs r5, #0x80
    lsls r5, r5, #2
    movs r4, #0x10
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805bfc8 @ =0x05000200
    ldr r2, lbl_0805bfd0 @ =0x02035200
    str r4, [sp]
    movs r0, #3
    adds r3, r5, #0
    bl DMATransfer
    add sp, #4
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805bfb8: .4byte 0x03005520
lbl_0805bfbc: .4byte 0x03000bf0
lbl_0805bfc0: .4byte 0x08345d00
lbl_0805bfc4: .4byte 0x00007fff
lbl_0805bfc8: .4byte 0x05000200
lbl_0805bfcc: .4byte 0x02035000
lbl_0805bfd0: .4byte 0x02035200

    thumb_func_start start_effect_for_cutscene
start_effect_for_cutscene: @ 0x0805bfd4
    push {lr}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    subs r0, #1
    cmp r0, #7
    bhi lbl_0805c06c
    lsls r0, r0, #2
    ldr r1, lbl_0805bfec @ =lbl_0805bff0
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805bfec: .4byte lbl_0805bff0
lbl_0805bff0: @ jump table
    .4byte lbl_0805c010 @ case 0
    .4byte lbl_0805c02c @ case 1
    .4byte lbl_0805c034 @ case 2
    .4byte lbl_0805c03c @ case 3
    .4byte lbl_0805c044 @ case 4
    .4byte lbl_0805c04c @ case 5
    .4byte lbl_0805c054 @ case 6
    .4byte lbl_0805c05c @ case 7
lbl_0805c010:
    ldr r1, lbl_0805c024 @ =0x03000043
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0805c028 @ =0x03000c21
    movs r0, #0
    strb r0, [r1]
    bl sub_0805b340
    movs r0, #0xf
    b lbl_0805c062
    .align 2, 0
lbl_0805c024: .4byte 0x03000043
lbl_0805c028: .4byte 0x03000c21
lbl_0805c02c:
    bl sub_0805b340
    movs r0, #0xc
    b lbl_0805c062
lbl_0805c034:
    movs r0, #4
    bl start_special_background_effect
    b lbl_0805c06c
lbl_0805c03c:
    bl sub_0805b340
    movs r0, #0x11
    b lbl_0805c062
lbl_0805c044:
    bl sub_0805b340
    movs r0, #0x12
    b lbl_0805c062
lbl_0805c04c:
    bl sub_0805b340
    movs r0, #0x13
    b lbl_0805c062
lbl_0805c054:
    movs r0, #5
    bl start_special_background_effect
    b lbl_0805c06c
lbl_0805c05c:
    bl sub_0805b340
    movs r0, #0x16
lbl_0805c062:
    bl start_special_background_fading
    ldr r1, lbl_0805c070 @ =0x03000c72
    movs r0, #3
    strh r0, [r1]
lbl_0805c06c:
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c070: .4byte 0x03000c72

    thumb_func_start start_special_background_fading
start_special_background_fading: @ 0x0805c074
    ldr r1, lbl_0805c088 @ =0x03005520
    movs r2, #0
    strb r0, [r1]
    strb r2, [r1, #1]
    strb r2, [r1, #2]
    strb r2, [r1, #3]
    strb r2, [r1, #4]
    strb r2, [r1, #5]
    strh r2, [r1, #6]
    bx lr
    .align 2, 0
lbl_0805c088: .4byte 0x03005520

    thumb_func_start hide_screen_during_load
hide_screen_during_load: @ 0x0805c08c
    push {lr}
    ldr r0, lbl_0805c0d8 @ =0x03000c75
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c0be
    ldr r0, lbl_0805c0dc @ =0x03000bf0
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805c0be
    ldr r0, lbl_0805c0e0 @ =0x0300007d
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805c0be
    ldr r0, lbl_0805c0e4 @ =0x0300007e
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c108
lbl_0805c0be:
    ldr r2, lbl_0805c0e8 @ =0x08345d00
    ldr r0, lbl_0805c0ec @ =0x03005520
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805c0f4
    ldr r1, lbl_0805c0f0 @ =0x04000050
    movs r0, #0xbf
    b lbl_0805c0f8
    .align 2, 0
lbl_0805c0d8: .4byte 0x03000c75
lbl_0805c0dc: .4byte 0x03000bf0
lbl_0805c0e0: .4byte 0x0300007d
lbl_0805c0e4: .4byte 0x0300007e
lbl_0805c0e8: .4byte 0x08345d00
lbl_0805c0ec: .4byte 0x03005520
lbl_0805c0f0: .4byte 0x04000050
lbl_0805c0f4:
    ldr r1, lbl_0805c104 @ =0x04000050
    movs r0, #0xff
lbl_0805c0f8:
    strh r0, [r1]
    movs r1, #0x80
    lsls r1, r1, #0x13
    movs r0, #0
    b lbl_0805c146
    .align 2, 0
lbl_0805c104: .4byte 0x04000050
lbl_0805c108:
    ldr r2, lbl_0805c124 @ =0x08345d00
    ldr r0, lbl_0805c128 @ =0x03005520
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0]
    cmp r0, #0
    beq lbl_0805c130
    ldr r1, lbl_0805c12c @ =0x04000050
    movs r0, #0xa7
    b lbl_0805c134
    .align 2, 0
lbl_0805c124: .4byte 0x08345d00
lbl_0805c128: .4byte 0x03005520
lbl_0805c12c: .4byte 0x04000050
lbl_0805c130:
    ldr r1, lbl_0805c14c @ =0x04000050
    movs r0, #0xe7
lbl_0805c134:
    strh r0, [r1]
    ldr r1, lbl_0805c150 @ =0x0400000e
    ldr r2, lbl_0805c154 @ =0x00004604
    adds r0, r2, #0
    strh r0, [r1]
    subs r1, #0xe
    movs r2, #0xc0
    lsls r2, r2, #5
    adds r0, r2, #0
lbl_0805c146:
    strh r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c14c: .4byte 0x04000050
lbl_0805c150: .4byte 0x0400000e
lbl_0805c154: .4byte 0x00004604

    thumb_func_start bg30_fs_related
bg30_fs_related: @ 0x0805c158
    push {lr}
    ldr r2, lbl_0805c174 @ =0x08345d00
    ldr r0, lbl_0805c178 @ =0x03005520
    ldrb r1, [r0]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r2
    ldrb r0, [r0, #0x16]
    cmp r0, #1
    bne lbl_0805c180
    ldr r1, lbl_0805c17c @ =0x0300002a
    movs r0, #4
    b lbl_0805c184
    .align 2, 0
lbl_0805c174: .4byte 0x08345d00
lbl_0805c178: .4byte 0x03005520
lbl_0805c17c: .4byte 0x0300002a
lbl_0805c180:
    ldr r1, lbl_0805c18c @ =0x0300002a
    movs r0, #3
lbl_0805c184:
    strb r0, [r1]
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c18c: .4byte 0x0300002a

    thumb_func_start sub_0805c190
sub_0805c190: @ 0x0805c190
    push {r4, r5, lr}
    sub sp, #4
    ldr r0, lbl_0805c200 @ =0x030000e4
    ldrh r1, [r0, #0xe]
    movs r4, #0
    strh r1, [r0, #0x12]
    ldrh r1, [r0, #0xc]
    strh r1, [r0, #0x10]
    ldr r1, lbl_0805c204 @ =0x02007000
    ldr r2, lbl_0805c208 @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0805c20c @ =0x04000008
    ldr r5, lbl_0805c210 @ =0x03000088
    ldrh r0, [r5, #0x12]
    strh r0, [r1]
    adds r1, #6
    ldrh r0, [r5, #0x10]
    strh r0, [r1]
    ldr r0, lbl_0805c214 @ =0x0300007c
    strb r4, [r0]
    ldr r2, lbl_0805c218 @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0805c1d6
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #7]
lbl_0805c1d6:
    ldrh r1, [r5, #2]
    movs r0, #2
    bl TransparencyUpdateBLDCNT
    movs r1, #0x80
    lsls r1, r1, #0x13
    ldrh r0, [r5]
    strh r0, [r1]
    ldr r0, lbl_0805c21c @ =0x0300007b
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    bne lbl_0805c1f6
    bl lock_hatches_with_timer
lbl_0805c1f6:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c200: .4byte 0x030000e4
lbl_0805c204: .4byte 0x02007000
lbl_0805c208: .4byte 0x06003000
lbl_0805c20c: .4byte 0x04000008
lbl_0805c210: .4byte 0x03000088
lbl_0805c214: .4byte 0x0300007c
lbl_0805c218: .4byte 0x03000080
lbl_0805c21c: .4byte 0x0300007b

    thumb_func_start sub_0805c220
sub_0805c220: @ 0x0805c220
    push {r4, r5, lr}
    ldr r0, lbl_0805c264 @ =0x030000e4
    ldrh r1, [r0, #0xe]
    movs r5, #0
    strh r1, [r0, #0x12]
    ldrh r1, [r0, #0xc]
    strh r1, [r0, #0x10]
    bl sub_0805b340
    bl sub_080595e4
    bl sub_0805e760
    ldr r1, lbl_0805c268 @ =0x030013b0
    ldr r2, lbl_0805c26c @ =0x03000088
    ldrb r0, [r2, #4]
    strh r0, [r1]
    ldr r1, lbl_0805c270 @ =0x030013b2
    ldrb r0, [r2, #5]
    strh r0, [r1]
    ldr r4, lbl_0805c274 @ =0x03000030
    movs r0, #3
    ldrsb r0, [r4, r0]
    cmp r0, #0
    beq lbl_0805c258
    bl sub_080039c8
    strb r5, [r4, #3]
lbl_0805c258:
    ldr r0, lbl_0805c278 @ =0x03005520
    strb r5, [r0, #3]
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c264: .4byte 0x030000e4
lbl_0805c268: .4byte 0x030013b0
lbl_0805c26c: .4byte 0x03000088
lbl_0805c270: .4byte 0x030013b2
lbl_0805c274: .4byte 0x03000030
lbl_0805c278: .4byte 0x03005520

    thumb_func_start sub_0805c27c
sub_0805c27c: @ 0x0805c27c
    push {r4, r5, r6, lr}
    ldr r1, lbl_0805c2d4 @ =0x03000c77
    ldrb r1, [r1]
    ands r1, r0
    cmp r1, #0
    bne lbl_0805c2cc
    ldr r6, lbl_0805c2d8 @ =0x030013b2
    ldrh r3, [r6]
    lsls r0, r3, #8
    ldr r5, lbl_0805c2dc @ =0x030013b0
    ldrh r2, [r5]
    orrs r0, r2
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r1, lbl_0805c2e0 @ =0x0875fd88
    ldr r0, lbl_0805c2e4 @ =0x030000bc
    ldrb r0, [r0, #0x10]
    lsls r0, r0, #2
    adds r1, #3
    adds r0, r0, r1
    ldrb r0, [r0]
    cmp r0, #2
    bne lbl_0805c2cc
    cmp r4, #0
    beq lbl_0805c2cc
    cmp r3, #0
    beq lbl_0805c2b6
    subs r0, r3, #1
    strh r0, [r6]
lbl_0805c2b6:
    lsls r0, r2, #0x10
    cmp r0, #0
    beq lbl_0805c2c0
    subs r0, r2, #1
    strh r0, [r5]
lbl_0805c2c0:
    ldr r0, lbl_0805c2e8 @ =0x03000006
    ldrh r1, [r6]
    lsls r1, r1, #8
    ldrh r2, [r5]
    orrs r1, r2
    strh r1, [r0]
lbl_0805c2cc:
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c2d4: .4byte 0x03000c77
lbl_0805c2d8: .4byte 0x030013b2
lbl_0805c2dc: .4byte 0x030013b0
lbl_0805c2e0: .4byte 0x0875fd88
lbl_0805c2e4: .4byte 0x030000bc
lbl_0805c2e8: .4byte 0x03000006

    thumb_func_start sub_0805c2ec
sub_0805c2ec: @ 0x0805c2ec
    push {r4, r5, r6, lr}
    sub sp, #4
    bl sub_0805d09c
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r0, #0
    strh r0, [r1]
    movs r4, #0x80
    lsls r4, r4, #0x13
    ldrh r1, [r4]
    ldr r0, lbl_0805c360 @ =0x0000f0ff
    ands r0, r1
    strh r0, [r4]
    ldr r1, lbl_0805c364 @ =0x08364f80
    ldr r5, lbl_0805c368 @ =0x02007000
    movs r0, #0
    adds r2, r5, #0
    bl rle_decompress
    ldr r2, lbl_0805c36c @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r6, #0x10
    str r6, [sp]
    movs r0, #3
    adds r1, r5, #0
    bl DMATransfer
    ldr r1, lbl_0805c370 @ =0x0400000e
    ldr r2, lbl_0805c374 @ =0x00004604
    adds r0, r2, #0
    strh r0, [r1]
    ldr r1, lbl_0805c378 @ =0x030000e4
    movs r0, #0x40
    strh r0, [r1, #0xe]
    strh r0, [r1, #0x12]
    ldr r1, lbl_0805c37c @ =0x0400001e
    strh r0, [r1]
    ldrh r0, [r4]
    movs r2, #0x80
    lsls r2, r2, #4
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r4]
    ldr r0, lbl_0805c380 @ =0x0300002d
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0805c38c
    ldr r1, lbl_0805c384 @ =0x085e0040
    ldr r2, lbl_0805c388 @ =0x05000020
    str r6, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    b lbl_0805c39a
    .align 2, 0
lbl_0805c360: .4byte 0x0000f0ff
lbl_0805c364: .4byte 0x08364f80
lbl_0805c368: .4byte 0x02007000
lbl_0805c36c: .4byte 0x06003000
lbl_0805c370: .4byte 0x0400000e
lbl_0805c374: .4byte 0x00004604
lbl_0805c378: .4byte 0x030000e4
lbl_0805c37c: .4byte 0x0400001e
lbl_0805c380: .4byte 0x0300002d
lbl_0805c384: .4byte 0x085e0040
lbl_0805c388: .4byte 0x05000020
lbl_0805c38c:
    ldr r1, lbl_0805c3a4 @ =0x085dfe40
    ldr r2, lbl_0805c3a8 @ =0x05000020
    str r6, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
lbl_0805c39a:
    add sp, #4
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805c3a4: .4byte 0x085dfe40
lbl_0805c3a8: .4byte 0x05000020

    thumb_func_start unk_5c3ac
unk_5c3ac: @ 0x0805c3ac
    push {r4, r5, lr}
    ldr r4, lbl_0805c3e8 @ =0x03005520
    movs r0, #0
    strb r0, [r4, #5]
    ldr r5, lbl_0805c3ec @ =0x08345d00
    ldrb r1, [r4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r1, r5, #4
    adds r0, r0, r1
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_0805c458
    bl _call_via_r0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c458
    ldrb r1, [r4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r0, r0, r5
    ldrb r1, [r0, #0x16]
    cmp r1, #1
    beq lbl_0805c3f0
    cmp r1, #2
    beq lbl_0805c408
    b lbl_0805c418
    .align 2, 0
lbl_0805c3e8: .4byte 0x03005520
lbl_0805c3ec: .4byte 0x08345d00
lbl_0805c3f0:
    ldr r0, lbl_0805c404 @ =0x03000030
    ldrb r0, [r0, #4]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805c418
    bl check_play_new_music_track
    b lbl_0805c418
    .align 2, 0
lbl_0805c404: .4byte 0x03000030
lbl_0805c408:
    ldr r0, lbl_0805c444 @ =0x03000030
    ldrb r0, [r0, #2]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c418
    bl sub_08060ab8
lbl_0805c418:
    ldr r0, lbl_0805c444 @ =0x03000030
    movs r4, #0
    strb r4, [r0, #4]
    strb r4, [r0, #2]
    movs r0, #2
    bl start_special_background_fading
    ldr r2, lbl_0805c448 @ =0x04000054
    ldr r1, lbl_0805c44c @ =0x03000088
    ldrb r0, [r1, #6]
    strh r0, [r2]
    ldrh r1, [r1, #2]
    movs r0, #3
    bl TransparencyUpdateBLDCNT
    ldr r0, lbl_0805c450 @ =0x0300007c
    strb r4, [r0]
    ldr r0, lbl_0805c454 @ =0x03005520
    strb r4, [r0, #1]
    movs r0, #1
    b lbl_0805c45a
    .align 2, 0
lbl_0805c444: .4byte 0x03000030
lbl_0805c448: .4byte 0x04000054
lbl_0805c44c: .4byte 0x03000088
lbl_0805c450: .4byte 0x0300007c
lbl_0805c454: .4byte 0x03005520
lbl_0805c458:
    movs r0, #0
lbl_0805c45a:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start process_fading_effect
process_fading_effect: @ 0x0805c460
    push {r4, r5, lr}
    ldr r4, lbl_0805c498 @ =0x03005520
    movs r5, #0
    movs r0, #1
    strb r0, [r4, #5]
    ldrb r1, [r4, #3]
    adds r0, r1, #0
    cmp r0, #0xff
    beq lbl_0805c476
    adds r0, r1, #1
    strb r0, [r4, #3]
lbl_0805c476:
    ldr r2, lbl_0805c49c @ =0x08345d00
    ldrb r1, [r4]
    lsls r0, r1, #1
    adds r0, r0, r1
    lsls r0, r0, #3
    adds r2, #0xc
    adds r0, r0, r2
    ldr r0, [r0]
    cmp r0, #0
    beq lbl_0805c494
    bl _call_via_r0
    lsls r0, r0, #0x18
    cmp r0, #0
    bne lbl_0805c4a0
lbl_0805c494:
    movs r0, #0
    b lbl_0805c4b4
    .align 2, 0
lbl_0805c498: .4byte 0x03005520
lbl_0805c49c: .4byte 0x08345d00
lbl_0805c4a0:
    ldr r0, lbl_0805c4bc @ =0x03001382
    strb r5, [r0]
    bl HUDDraw
    bl ParticleProcessAll
    bl ResetFreeOAM
    strb r5, [r4, #1]
    movs r0, #1
lbl_0805c4b4:
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805c4bc: .4byte 0x03001382

    thumb_func_start sub_0805c4c0
sub_0805c4c0: @ 0x0805c4c0
    push {r4, lr}
    sub sp, #4
    ldr r0, lbl_0805c4dc @ =0x03005520
    ldrb r1, [r0, #1]
    adds r4, r0, #0
    cmp r1, #5
    bls lbl_0805c4d0
    b lbl_0805c71c
lbl_0805c4d0:
    lsls r0, r1, #2
    ldr r1, lbl_0805c4e0 @ =lbl_0805c4e4
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805c4dc: .4byte 0x03005520
lbl_0805c4e0: .4byte lbl_0805c4e4
lbl_0805c4e4: @ jump table
    .4byte lbl_0805c4fc @ case 0
    .4byte lbl_0805c502 @ case 1
    .4byte lbl_0805c52c @ case 2
    .4byte lbl_0805c5a0 @ case 3
    .4byte lbl_0805c6bc @ case 4
    .4byte lbl_0805c714 @ case 5
lbl_0805c4fc:
    bl sub_0805c220
    b lbl_0805c582
lbl_0805c502:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c51a
    ldr r1, lbl_0805c524 @ =0x0300007c
    movs r0, #1
    strb r0, [r1]
    ldr r1, lbl_0805c528 @ =0x03005520
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
lbl_0805c51a:
    movs r0, #0
    bl sub_0805c27c
    b lbl_0805c71c
    .align 2, 0
lbl_0805c524: .4byte 0x0300007c
lbl_0805c528: .4byte 0x03005520
lbl_0805c52c:
    bl sub_0805d09c
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r0, #0
    strh r0, [r1]
    ldr r0, lbl_0805c554 @ =0x0300002d
    ldrb r0, [r0]
    cmp r0, #1
    bne lbl_0805c560
    ldr r1, lbl_0805c558 @ =0x085e0040
    ldr r2, lbl_0805c55c @ =0x05000020
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
    b lbl_0805c570
    .align 2, 0
lbl_0805c554: .4byte 0x0300002d
lbl_0805c558: .4byte 0x085e0040
lbl_0805c55c: .4byte 0x05000020
lbl_0805c560:
    ldr r1, lbl_0805c58c @ =0x085dfe40
    ldr r2, lbl_0805c590 @ =0x05000020
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r3, #0x40
    bl DMATransfer
lbl_0805c570:
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldrh r1, [r2]
    ldr r0, lbl_0805c594 @ =0x0000b3ff
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0805c598 @ =0x0300002b
    movs r0, #0
    strb r0, [r1]
lbl_0805c582:
    ldr r1, lbl_0805c59c @ =0x03005520
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_0805c71c
    .align 2, 0
lbl_0805c58c: .4byte 0x085dfe40
lbl_0805c590: .4byte 0x05000020
lbl_0805c594: .4byte 0x0000b3ff
lbl_0805c598: .4byte 0x0300002b
lbl_0805c59c: .4byte 0x03005520
lbl_0805c5a0:
    ldr r1, lbl_0805c5d0 @ =0x08364f80
    ldr r4, lbl_0805c5d4 @ =0x02007000
    movs r0, #0
    adds r2, r4, #0
    bl rle_decompress
    ldr r2, lbl_0805c5d8 @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    adds r1, r4, #0
    bl DMATransfer
    ldr r0, lbl_0805c5dc @ =0x030054e0
    ldrh r0, [r0]
    cmp r0, #0
    beq lbl_0805c5e4
    ldr r1, lbl_0805c5e0 @ =0x030000e4
    movs r0, #0x98
    lsls r0, r0, #1
    b lbl_0805c5ea
    .align 2, 0
lbl_0805c5d0: .4byte 0x08364f80
lbl_0805c5d4: .4byte 0x02007000
lbl_0805c5d8: .4byte 0x06003000
lbl_0805c5dc: .4byte 0x030054e0
lbl_0805c5e0: .4byte 0x030000e4
lbl_0805c5e4:
    ldr r1, lbl_0805c674 @ =0x030000e4
    movs r0, #0x8c
    lsls r0, r0, #2
lbl_0805c5ea:
    strh r0, [r1, #0x10]
    adds r3, r1, #0
    ldr r0, lbl_0805c678 @ =0x030054e0
    ldrh r0, [r0, #2]
    lsls r0, r0, #6
    ldr r1, lbl_0805c67c @ =0x030013ba
    ldrh r1, [r1]
    subs r0, r0, r1
    movs r1, #0x80
    lsls r1, r1, #3
    subs r1, r1, r0
    asrs r1, r1, #2
    strh r1, [r3, #0x12]
    ldr r2, lbl_0805c680 @ =0x0400001c
    ldrh r0, [r3, #0x10]
    strh r0, [r2]
    ldr r0, lbl_0805c684 @ =0x0400001e
    strh r1, [r0]
    ldr r1, lbl_0805c688 @ =0x0300544c
    ldr r2, lbl_0805c68c @ =0x00003f48
    adds r0, r2, #0
    strh r0, [r1]
    ldr r0, lbl_0805c690 @ =0x030000bc
    ldrb r0, [r0, #1]
    subs r0, #0x43
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    ldr r3, lbl_0805c694 @ =0x030013b2
    ldr r1, lbl_0805c698 @ =0x030013b0
    cmp r0, #2
    bls lbl_0805c630
    movs r0, #0x10
    strh r0, [r3]
    movs r0, #0
    strh r0, [r1]
lbl_0805c630:
    ldr r2, lbl_0805c69c @ =0x03000006
    ldrh r0, [r3]
    lsls r0, r0, #8
    ldrh r1, [r1]
    orrs r0, r1
    strh r0, [r2]
    ldr r1, lbl_0805c6a0 @ =0x03005510
    ldr r3, lbl_0805c6a4 @ =0x00004604
    adds r0, r3, #0
    strh r0, [r1]
    ldr r2, lbl_0805c6a8 @ =0x03005512
    ldr r0, lbl_0805c6ac @ =0x0400000a
    ldrh r0, [r0]
    movs r1, #1
    orrs r0, r1
    strh r0, [r2]
    ldr r2, lbl_0805c6b0 @ =0x0300000a
    movs r0, #0x80
    lsls r0, r0, #0x13
    ldrh r0, [r0]
    movs r3, #0x80
    lsls r3, r3, #4
    adds r1, r3, #0
    orrs r0, r1
    ldr r1, lbl_0805c6b4 @ =0x0000feff
    ands r0, r1
    strh r0, [r2]
    ldr r1, lbl_0805c6b8 @ =0x03005520
    movs r0, #4
    strb r0, [r1, #1]
    movs r0, #0
    strb r0, [r1, #3]
    b lbl_0805c71c
    .align 2, 0
lbl_0805c674: .4byte 0x030000e4
lbl_0805c678: .4byte 0x030054e0
lbl_0805c67c: .4byte 0x030013ba
lbl_0805c680: .4byte 0x0400001c
lbl_0805c684: .4byte 0x0400001e
lbl_0805c688: .4byte 0x0300544c
lbl_0805c68c: .4byte 0x00003f48
lbl_0805c690: .4byte 0x030000bc
lbl_0805c694: .4byte 0x030013b2
lbl_0805c698: .4byte 0x030013b0
lbl_0805c69c: .4byte 0x03000006
lbl_0805c6a0: .4byte 0x03005510
lbl_0805c6a4: .4byte 0x00004604
lbl_0805c6a8: .4byte 0x03005512
lbl_0805c6ac: .4byte 0x0400000a
lbl_0805c6b0: .4byte 0x0300000a
lbl_0805c6b4: .4byte 0x0000feff
lbl_0805c6b8: .4byte 0x03005520
lbl_0805c6bc:
    ldr r2, lbl_0805c6f0 @ =0x030013b2
    ldrh r3, [r2]
    ldr r1, lbl_0805c6f4 @ =0x030013b0
    cmp r3, #0
    bne lbl_0805c6cc
    ldrh r0, [r1]
    cmp r0, #0xf
    bhi lbl_0805c6fc
lbl_0805c6cc:
    ldrh r0, [r2]
    subs r3, r0, #2
    cmp r3, #0
    bge lbl_0805c6d6
    movs r3, #0
lbl_0805c6d6:
    strh r3, [r2]
    ldrh r0, [r1]
    adds r2, r0, #2
    cmp r2, #0x10
    ble lbl_0805c6e2
    movs r2, #0x10
lbl_0805c6e2:
    strh r2, [r1]
    ldr r1, lbl_0805c6f8 @ =0x03000006
    lsls r0, r3, #8
    orrs r2, r0
    strh r2, [r1]
    b lbl_0805c71c
    .align 2, 0
lbl_0805c6f0: .4byte 0x030013b2
lbl_0805c6f4: .4byte 0x030013b0
lbl_0805c6f8: .4byte 0x03000006
lbl_0805c6fc:
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldrh r1, [r2]
    ldr r0, lbl_0805c710 @ =0x0000fdff
    ands r0, r1
    strh r0, [r2]
    strb r3, [r4, #3]
    movs r0, #5
    strb r0, [r4, #1]
    b lbl_0805c71c
    .align 2, 0
lbl_0805c710: .4byte 0x0000fdff
lbl_0805c714:
    movs r0, #0
    strb r0, [r4, #1]
    movs r0, #1
    b lbl_0805c71e
lbl_0805c71c:
    movs r0, #0
lbl_0805c71e:
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0805c728
sub_0805c728: @ 0x0805c728
    push {r4, lr}
    ldr r4, lbl_0805c73c @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805c752
    cmp r0, #1
    bgt lbl_0805c740
    cmp r0, #0
    beq lbl_0805c746
    b lbl_0805c772
    .align 2, 0
lbl_0805c73c: .4byte 0x03005520
lbl_0805c740:
    cmp r0, #2
    beq lbl_0805c76a
    b lbl_0805c772
lbl_0805c746:
    bl sub_0805c220
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805c772
lbl_0805c752:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c762
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805c762:
    movs r0, #0
    bl sub_0805c27c
    b lbl_0805c772
lbl_0805c76a:
    bl sub_0805c2ec
    movs r0, #1
    b lbl_0805c774
lbl_0805c772:
    movs r0, #0
lbl_0805c774:
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start escape_failed_fade
escape_failed_fade: @ 0x0805c77c
    push {r4, lr}
    ldr r4, lbl_0805c790 @ =0x03005520
    ldrb r1, [r4, #1]
    cmp r1, #1
    beq lbl_0805c7b8
    cmp r1, #1
    bgt lbl_0805c794
    cmp r1, #0
    beq lbl_0805c79e
    b lbl_0805c80c
    .align 2, 0
lbl_0805c790: .4byte 0x03005520
lbl_0805c794:
    cmp r1, #2
    beq lbl_0805c7c4
    cmp r1, #3
    beq lbl_0805c7e4
    b lbl_0805c80c
lbl_0805c79e:
    ldr r0, lbl_0805c7b4 @ =0x03000bf0
    strb r1, [r0]
    bl sub_0805c220
    movs r0, #0x3c
    bl sub_08002acc
    movs r0, #0x3c
    bl FadeMusic
    b lbl_0805c7d6
    .align 2, 0
lbl_0805c7b4: .4byte 0x03000bf0
lbl_0805c7b8:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c80c
    b lbl_0805c7d6
lbl_0805c7c4:
    bl sub_0805d09c
    movs r1, #0xa0
    lsls r1, r1, #0x13
    ldr r2, lbl_0805c7e0 @ =0x00007fff
    adds r0, r2, #0
    strh r0, [r1]
    movs r0, #0
    strh r0, [r4, #6]
lbl_0805c7d6:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805c80c
    .align 2, 0
lbl_0805c7e0: .4byte 0x00007fff
lbl_0805c7e4:
    ldrh r0, [r4, #6]
    adds r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x3c
    bls lbl_0805c80c
    ldr r1, lbl_0805c804 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0805c808 @ =0x03000c70
    movs r0, #6
    strh r0, [r1]
    movs r0, #1
    b lbl_0805c80e
    .align 2, 0
lbl_0805c804: .4byte 0x03000c72
lbl_0805c808: .4byte 0x03000c70
lbl_0805c80c:
    movs r0, #0
lbl_0805c80e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start before_chozodia_escape_fade
before_chozodia_escape_fade: @ 0x0805c814
    push {r4, lr}
    ldr r4, lbl_0805c828 @ =0x03005520
    ldrb r1, [r4, #1]
    cmp r1, #1
    beq lbl_0805c850
    cmp r1, #1
    bgt lbl_0805c82c
    cmp r1, #0
    beq lbl_0805c832
    b lbl_0805c890
    .align 2, 0
lbl_0805c828: .4byte 0x03005520
lbl_0805c82c:
    cmp r1, #2
    beq lbl_0805c880
    b lbl_0805c890
lbl_0805c832:
    movs r0, #0xa0
    lsls r0, r0, #0x13
    strh r1, [r0]
    ldr r2, lbl_0805c848 @ =0x0300000a
    movs r0, #0x80
    lsls r0, r0, #0x13
    ldrh r1, [r0]
    ldr r0, lbl_0805c84c @ =0x0000e0ff
    ands r0, r1
    strh r0, [r2]
    b lbl_0805c888
    .align 2, 0
lbl_0805c848: .4byte 0x0300000a
lbl_0805c84c: .4byte 0x0000e0ff
lbl_0805c850:
    bl sub_0805d09c
    ldr r0, lbl_0805c86c @ =0x03000bf0
    movs r1, #0
    strb r1, [r0]
    ldr r0, lbl_0805c870 @ =0x0300007d
    strb r1, [r0]
    ldr r0, lbl_0805c874 @ =0x03000c21
    strb r1, [r0]
    ldr r1, lbl_0805c878 @ =0x03000028
    ldr r0, lbl_0805c87c @ =0x03000024
    ldrb r0, [r0]
    strb r0, [r1]
    b lbl_0805c888
    .align 2, 0
lbl_0805c86c: .4byte 0x03000bf0
lbl_0805c870: .4byte 0x0300007d
lbl_0805c874: .4byte 0x03000c21
lbl_0805c878: .4byte 0x03000028
lbl_0805c87c: .4byte 0x03000024
lbl_0805c880:
    bl sub_080737cc
    cmp r0, #0
    beq lbl_0805c89c
lbl_0805c888:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805c89c
lbl_0805c890:
    ldr r1, lbl_0805c8a4 @ =0x03000c72
    movs r0, #0
    strh r0, [r1]
    ldr r1, lbl_0805c8a8 @ =0x03000c70
    movs r0, #7
    strh r0, [r1]
lbl_0805c89c:
    movs r0, #0
    pop {r4}
    pop {r1}
    bx r1
    .align 2, 0
lbl_0805c8a4: .4byte 0x03000c72
lbl_0805c8a8: .4byte 0x03000c70

    thumb_func_start sub_0805c8ac
sub_0805c8ac: @ 0x0805c8ac
    push {r4, lr}
    ldr r4, lbl_0805c8c0 @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805c8f4
    cmp r0, #1
    bgt lbl_0805c8c4
    cmp r0, #0
    beq lbl_0805c8ca
    b lbl_0805c91c
    .align 2, 0
lbl_0805c8c0: .4byte 0x03005520
lbl_0805c8c4:
    cmp r0, #2
    beq lbl_0805c90c
    b lbl_0805c91c
lbl_0805c8ca:
    bl sub_0805c220
    ldrb r0, [r4]
    cmp r0, #0xe
    bne lbl_0805c8e4
    ldr r2, lbl_0805c8f0 @ =0x03000038
    ldrb r1, [r2, #3]
    movs r0, #0x10
    rsbs r0, r0, #0
    ands r0, r1
    movs r1, #1
    orrs r0, r1
    strb r0, [r2, #3]
lbl_0805c8e4:
    bl sub_08060d38
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805c91c
    .align 2, 0
lbl_0805c8f0: .4byte 0x03000038
lbl_0805c8f4:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c904
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805c904:
    movs r0, #3
    bl sub_0805c27c
    b lbl_0805c91c
lbl_0805c90c:
    bl sub_0805d09c
    movs r1, #0xa0
    lsls r1, r1, #0x13
    movs r0, #0
    strh r0, [r1]
    movs r0, #1
    b lbl_0805c91e
lbl_0805c91c:
    movs r0, #0
lbl_0805c91e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start before_tourian_escape_fade
before_tourian_escape_fade: @ 0x0805c924
    push {r4, lr}
    ldr r4, lbl_0805c938 @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805c94c
    cmp r0, #1
    bgt lbl_0805c93c
    cmp r0, #0
    beq lbl_0805c946
    b lbl_0805c994
    .align 2, 0
lbl_0805c938: .4byte 0x03005520
lbl_0805c93c:
    cmp r0, #2
    beq lbl_0805c968
    cmp r0, #3
    beq lbl_0805c980
    b lbl_0805c994
lbl_0805c946:
    bl sub_0805c220
    b lbl_0805c95c
lbl_0805c94c:
    ldr r1, lbl_0805c964 @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805c958
    movs r0, #0
    strb r0, [r1]
lbl_0805c958:
    movs r0, #0
    strh r0, [r4, #6]
lbl_0805c95c:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805c994
    .align 2, 0
lbl_0805c964: .4byte 0x030056f4
lbl_0805c968:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c978
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805c978:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805c994
lbl_0805c980:
    bl sub_0805c2ec
    ldr r1, lbl_0805c990 @ =0x0300007e
    movs r0, #1
    strb r0, [r1]
    movs r0, #1
    b lbl_0805c996
    .align 2, 0
lbl_0805c990: .4byte 0x0300007e
lbl_0805c994:
    movs r0, #0
lbl_0805c996:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start before_getting_fully_powered_fade
before_getting_fully_powered_fade: @ 0x0805c99c
    push {r4, r5, lr}
    ldr r5, lbl_0805c9b0 @ =0x03005520
    ldrb r4, [r5, #1]
    cmp r4, #1
    beq lbl_0805c9c6
    cmp r4, #1
    bgt lbl_0805c9b4
    cmp r4, #0
    beq lbl_0805c9be
    b lbl_0805ca50
    .align 2, 0
lbl_0805c9b0: .4byte 0x03005520
lbl_0805c9b4:
    cmp r4, #2
    beq lbl_0805c9e4
    cmp r4, #3
    beq lbl_0805c9fc
    b lbl_0805ca50
lbl_0805c9be:
    bl sub_0805c220
    strb r4, [r5, #3]
    b lbl_0805c9d6
lbl_0805c9c6:
    ldr r1, lbl_0805c9e0 @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805c9d2
    movs r0, #0
    strb r0, [r1]
lbl_0805c9d2:
    movs r0, #0
    strb r0, [r5, #3]
lbl_0805c9d6:
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    b lbl_0805ca50
    .align 2, 0
lbl_0805c9e0: .4byte 0x030056f4
lbl_0805c9e4:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805c9f4
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
lbl_0805c9f4:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805ca50
lbl_0805c9fc:
    bl sub_0805c2ec
    ldr r1, lbl_0805ca44 @ =0x0300007d
    movs r0, #0xc
    strb r0, [r1]
    movs r0, #2
    bl start_special_background_fading
    ldr r1, lbl_0805ca48 @ =0x0300070c
    movs r0, #6
    strb r0, [r1, #0xf]
    movs r0, #1
    movs r1, #0xd
    bl EventFunction
    movs r0, #3
    movs r1, #0x13
    bl EventFunction
    cmp r0, #0
    bne lbl_0805ca36
    movs r0, #1
    movs r1, #0x13
    bl EventFunction
    movs r0, #1
    movs r1, #0x44
    bl EventFunction
lbl_0805ca36:
    ldr r0, lbl_0805ca4c @ =0x03001530
    ldrb r1, [r0, #0xe]
    movs r2, #0x10
    orrs r1, r2
    strb r1, [r0, #0xe]
    movs r0, #1
    b lbl_0805ca52
    .align 2, 0
lbl_0805ca44: .4byte 0x0300007d
lbl_0805ca48: .4byte 0x0300070c
lbl_0805ca4c: .4byte 0x03001530
lbl_0805ca50:
    movs r0, #0
lbl_0805ca52:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start before_ridley_spawn_fade
before_ridley_spawn_fade: @ 0x0805ca58
    push {r4, r5, lr}
    ldr r5, lbl_0805ca6c @ =0x03005520
    ldrb r4, [r5, #1]
    cmp r4, #1
    beq lbl_0805ca82
    cmp r4, #1
    bgt lbl_0805ca70
    cmp r4, #0
    beq lbl_0805ca7a
    b lbl_0805cad0
    .align 2, 0
lbl_0805ca6c: .4byte 0x03005520
lbl_0805ca70:
    cmp r4, #2
    beq lbl_0805caa0
    cmp r4, #3
    beq lbl_0805cab8
    b lbl_0805cad0
lbl_0805ca7a:
    bl sub_0805c220
    strb r4, [r5, #3]
    b lbl_0805ca92
lbl_0805ca82:
    ldr r1, lbl_0805ca9c @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805ca8e
    movs r0, #0
    strb r0, [r1]
lbl_0805ca8e:
    movs r0, #0
    strb r0, [r5, #3]
lbl_0805ca92:
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
    b lbl_0805cad0
    .align 2, 0
lbl_0805ca9c: .4byte 0x030056f4
lbl_0805caa0:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cab0
    ldrb r0, [r5, #1]
    adds r0, #1
    strb r0, [r5, #1]
lbl_0805cab0:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805cad0
lbl_0805cab8:
    bl sub_0805c2ec
    ldr r1, lbl_0805cacc @ =0x0300007d
    movs r0, #9
    strb r0, [r1]
    movs r0, #2
    bl start_special_background_fading
    movs r0, #1
    b lbl_0805cad2
    .align 2, 0
lbl_0805cacc: .4byte 0x0300007d
lbl_0805cad0:
    movs r0, #0
lbl_0805cad2:
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start before_statue_opening_fade
before_statue_opening_fade: @ 0x0805cad8
    push {r4, lr}
    ldr r4, lbl_0805caec @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805cb06
    cmp r0, #1
    bgt lbl_0805caf0
    cmp r0, #0
    beq lbl_0805cafa
    b lbl_0805cb70
    .align 2, 0
lbl_0805caec: .4byte 0x03005520
lbl_0805caf0:
    cmp r0, #2
    beq lbl_0805cb40
    cmp r0, #3
    beq lbl_0805cb58
    b lbl_0805cb70
lbl_0805cafa:
    bl sub_0805c220
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805cb70
lbl_0805cb06:
    ldr r0, lbl_0805cb34 @ =0x03000054
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0805cb12
    cmp r0, #3
    bne lbl_0805cb1c
lbl_0805cb12:
    movs r0, #0x3c
    movs r1, #0x1c
    movs r2, #0
    bl sub_08003b7c
lbl_0805cb1c:
    ldr r1, lbl_0805cb38 @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805cb28
    movs r0, #0
    strb r0, [r1]
lbl_0805cb28:
    ldr r1, lbl_0805cb3c @ =0x03005520
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_0805cb70
    .align 2, 0
lbl_0805cb34: .4byte 0x03000054
lbl_0805cb38: .4byte 0x030056f4
lbl_0805cb3c: .4byte 0x03005520
lbl_0805cb40:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cb50
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805cb50:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805cb70
lbl_0805cb58:
    bl sub_0805c2ec
    ldr r1, lbl_0805cb6c @ =0x0300007d
    movs r0, #6
    strb r0, [r1]
    movs r0, #2
    bl start_special_background_fading
    movs r0, #1
    b lbl_0805cb72
    .align 2, 0
lbl_0805cb6c: .4byte 0x0300007d
lbl_0805cb70:
    movs r0, #0
lbl_0805cb72:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start before_intro_text_fade
before_intro_text_fade: @ 0x0805cb78
    push {r4, lr}
    ldr r4, lbl_0805cb8c @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805cba0
    cmp r0, #1
    bgt lbl_0805cb90
    cmp r0, #0
    beq lbl_0805cb9a
    b lbl_0805cc14
    .align 2, 0
lbl_0805cb8c: .4byte 0x03005520
lbl_0805cb90:
    cmp r0, #2
    beq lbl_0805cbb4
    cmp r0, #3
    beq lbl_0805cbcc
    b lbl_0805cc14
lbl_0805cb9a:
    bl sub_0805c220
    b lbl_0805cc00
lbl_0805cba0:
    ldr r1, lbl_0805cbb0 @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805cc00
    movs r0, #0
    strb r0, [r1]
    b lbl_0805cc00
    .align 2, 0
lbl_0805cbb0: .4byte 0x030056f4
lbl_0805cbb4:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cbc4
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805cbc4:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805cc14
lbl_0805cbcc:
    ldr r0, lbl_0805cbf4 @ =0x0300007d
    movs r1, #1
    strb r1, [r0]
    bl sub_0805c2ec
    movs r0, #2
    bl start_special_background_fading
    ldr r0, lbl_0805cbf8 @ =0x0300002c
    ldrb r0, [r0]
    cmp r0, #1
    beq lbl_0805cc10
    cmp r0, #2
    bne lbl_0805cbfc
    movs r0, #1
    movs r1, #2
    bl EventFunction
    b lbl_0805cc10
    .align 2, 0
lbl_0805cbf4: .4byte 0x0300007d
lbl_0805cbf8: .4byte 0x0300002c
lbl_0805cbfc:
    cmp r0, #0
    beq lbl_0805cc08
lbl_0805cc00:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805cc14
lbl_0805cc08:
    movs r0, #1
    movs r1, #1
    bl EventFunction
lbl_0805cc10:
    movs r0, #1
    b lbl_0805cc16
lbl_0805cc14:
    movs r0, #0
lbl_0805cc16:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start sub_0805cc1c
sub_0805cc1c: @ 0x0805cc1c
    push {r4, lr}
    ldr r4, lbl_0805cc30 @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805cc44
    cmp r0, #1
    bgt lbl_0805cc34
    cmp r0, #0
    beq lbl_0805cc3e
    b lbl_0805cc8c
    .align 2, 0
lbl_0805cc30: .4byte 0x03005520
lbl_0805cc34:
    cmp r0, #2
    beq lbl_0805cc5c
    cmp r0, #3
    beq lbl_0805cc74
    b lbl_0805cc8c
lbl_0805cc3e:
    bl sub_0805c220
    b lbl_0805cc50
lbl_0805cc44:
    ldr r1, lbl_0805cc58 @ =0x030056f4
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805cc50
    movs r0, #0
    strb r0, [r1]
lbl_0805cc50:
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805cc8c
    .align 2, 0
lbl_0805cc58: .4byte 0x030056f4
lbl_0805cc5c:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cc6c
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
lbl_0805cc6c:
    movs r0, #7
    bl sub_0805c27c
    b lbl_0805cc8c
lbl_0805cc74:
    bl sub_0805c2ec
    ldr r1, lbl_0805cc88 @ =0x0300007d
    movs r0, #0xe
    strb r0, [r1]
    movs r0, #2
    bl start_special_background_fading
    movs r0, #1
    b lbl_0805cc8e
    .align 2, 0
lbl_0805cc88: .4byte 0x0300007d
lbl_0805cc8c:
    movs r0, #0
lbl_0805cc8e:
    pop {r4}
    pop {r1}
    bx r1

    thumb_func_start sub_0805cc94
sub_0805cc94: @ 0x0805cc94
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_0805ccac @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #1
    beq lbl_0805ccbc
    cmp r0, #1
    bgt lbl_0805ccb0
    cmp r0, #0
    beq lbl_0805ccb6
    b lbl_0805cce6
    .align 2, 0
lbl_0805ccac: .4byte 0x03005520
lbl_0805ccb0:
    cmp r0, #2
    beq lbl_0805ccd4
    b lbl_0805cce6
lbl_0805ccb6:
    bl sub_0805c190
    b lbl_0805ccca
lbl_0805ccbc:
    ldrh r0, [r4, #6]
    adds r0, #1
    strh r0, [r4, #6]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #0x3c
    bls lbl_0805cce6
lbl_0805ccca:
    strh r5, [r4, #6]
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805cce6
lbl_0805ccd4:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cce6
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    movs r5, #1
lbl_0805cce6:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start sub_0805ccf0
sub_0805ccf0: @ 0x0805ccf0
    push {r4, r5, lr}
    movs r5, #0
    ldr r4, lbl_0805cd08 @ =0x03005520
    ldrb r0, [r4, #1]
    cmp r0, #0
    bne lbl_0805cd0c
    bl sub_0805c190
    ldrb r0, [r4, #1]
    adds r0, #1
    strb r0, [r4, #1]
    b lbl_0805cd1c
    .align 2, 0
lbl_0805cd08: .4byte 0x03005520
lbl_0805cd0c:
    cmp r0, #1
    bne lbl_0805cd1c
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cd1c
    movs r5, #1
lbl_0805cd1c:
    adds r0, r5, #0
    pop {r4, r5}
    pop {r1}
    bx r1

    thumb_func_start sub_0805cd24
sub_0805cd24: @ 0x0805cd24
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    ldr r0, lbl_0805cd4c @ =0x03005520
    ldrb r2, [r0, #3]
    adds r1, r2, #0
    adds r3, r0, #0
    cmp r1, #0xff
    beq lbl_0805cd38
    adds r0, r2, #1
    strb r0, [r3, #3]
lbl_0805cd38:
    ldrb r0, [r3, #1]
    cmp r0, #6
    bls lbl_0805cd40
    b lbl_0805cf40
lbl_0805cd40:
    lsls r0, r0, #2
    ldr r1, lbl_0805cd50 @ =lbl_0805cd54
    adds r0, r0, r1
    ldr r0, [r0]
    mov pc, r0
    .align 2, 0
lbl_0805cd4c: .4byte 0x03005520
lbl_0805cd50: .4byte lbl_0805cd54
lbl_0805cd54: @ jump table
    .4byte lbl_0805cd70 @ case 0
    .4byte lbl_0805cdcc @ case 1
    .4byte lbl_0805ce18 @ case 2
    .4byte lbl_0805ce26 @ case 3
    .4byte lbl_0805cf04 @ case 4
    .4byte lbl_0805cf20 @ case 5
    .4byte lbl_0805cf38 @ case 6
lbl_0805cd70:
    ldr r0, lbl_0805cd88 @ =0x030000e4
    ldrh r0, [r0, #0x10]
    movs r1, #0x8c
    lsls r1, r1, #2
    cmp r0, r1
    bne lbl_0805cd90
    ldr r1, lbl_0805cd8c @ =0x030054e0
    movs r0, #0x98
    lsls r0, r0, #1
    strh r0, [r1]
    adds r2, r1, #0
    b lbl_0805cd96
    .align 2, 0
lbl_0805cd88: .4byte 0x030000e4
lbl_0805cd8c: .4byte 0x030054e0
lbl_0805cd90:
    ldr r0, lbl_0805cdc0 @ =0x030054e0
    strh r1, [r0]
    adds r2, r0, #0
lbl_0805cd96:
    ldrh r1, [r2, #2]
    lsls r1, r1, #6
    ldr r0, lbl_0805cdc4 @ =0x030013ba
    ldrh r0, [r0]
    subs r1, r1, r0
    asrs r1, r1, #2
    movs r3, #0x80
    lsls r3, r3, #1
    adds r0, r3, #0
    subs r0, r0, r1
    strh r0, [r2, #2]
    ldr r0, lbl_0805cdc8 @ =0x0300007b
    ldrb r0, [r0]
    lsls r0, r0, #0x18
    asrs r0, r0, #0x18
    cmp r0, #1
    beq lbl_0805cdba
    b lbl_0805cf2a
lbl_0805cdba:
    bl lock_hatches_with_timer
    b lbl_0805cf2a
    .align 2, 0
lbl_0805cdc0: .4byte 0x030054e0
lbl_0805cdc4: .4byte 0x030013ba
lbl_0805cdc8: .4byte 0x0300007b
lbl_0805cdcc:
    ldr r0, lbl_0805cdf0 @ =0x030054e0
    ldr r5, lbl_0805cdf4 @ =0x030000e4
    ldrh r4, [r0, #2]
    ldrh r0, [r5, #0x12]
    adds r2, r4, #0
    adds r1, r0, #0
    cmp r2, r1
    bls lbl_0805cdf8
    adds r0, #3
    strh r0, [r5, #0x12]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r2
    bhi lbl_0805cdea
    b lbl_0805cf40
lbl_0805cdea:
    strh r4, [r5, #0x12]
    b lbl_0805cf40
    .align 2, 0
lbl_0805cdf0: .4byte 0x030054e0
lbl_0805cdf4: .4byte 0x030000e4
lbl_0805cdf8:
    cmp r2, r1
    bhs lbl_0805ce0e
    subs r0, #3
    strh r0, [r5, #0x12]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, r2
    blo lbl_0805ce0a
    b lbl_0805cf40
lbl_0805ce0a:
    strh r4, [r5, #0x12]
    b lbl_0805cf40
lbl_0805ce0e:
    movs r0, #0
    strb r0, [r3, #3]
    movs r0, #2
    strb r0, [r3, #1]
    b lbl_0805cf40
lbl_0805ce18:
    ldrb r0, [r3, #3]
    cmp r0, #2
    bhi lbl_0805ce20
    b lbl_0805cf40
lbl_0805ce20:
    movs r0, #0
    strb r0, [r3, #3]
    b lbl_0805cf12
lbl_0805ce26:
    ldr r0, lbl_0805ce48 @ =0x030054e0
    ldr r4, lbl_0805ce4c @ =0x030000e4
    ldrh r3, [r0]
    ldrh r0, [r4, #0x10]
    adds r2, r3, #0
    adds r1, r0, #0
    cmp r2, r1
    bls lbl_0805ce50
    adds r0, #6
    strh r0, [r4, #0x10]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r2, r0
    blo lbl_0805ce44
    b lbl_0805cf40
lbl_0805ce44:
    strh r3, [r4, #0x10]
    b lbl_0805cf40
    .align 2, 0
lbl_0805ce48: .4byte 0x030054e0
lbl_0805ce4c: .4byte 0x030000e4
lbl_0805ce50:
    cmp r2, r1
    bhs lbl_0805ce64
    subs r0, #6
    strh r0, [r4, #0x10]
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r2, r0
    bls lbl_0805cf40
    strh r3, [r4, #0x10]
    b lbl_0805cf40
lbl_0805ce64:
    movs r6, #0x80
    lsls r6, r6, #0x13
    ldrh r0, [r6]
    movs r2, #0x80
    lsls r2, r2, #2
    adds r1, r2, #0
    orrs r0, r1
    strh r0, [r6]
    ldr r2, lbl_0805cedc @ =0x04000050
    ldrh r1, [r2]
    ldr r0, lbl_0805cee0 @ =0x0000fffd
    ands r0, r1
    strh r0, [r2]
    ldrh r1, [r6]
    ldr r0, lbl_0805cee4 @ =0x0000f7ff
    ands r0, r1
    strh r0, [r6]
    ldr r1, lbl_0805cee8 @ =0x02007000
    ldr r2, lbl_0805ceec @ =0x06003000
    movs r3, #0x80
    lsls r3, r3, #5
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    bl DMATransfer
    ldr r1, lbl_0805cef0 @ =0x04000008
    ldr r5, lbl_0805cef4 @ =0x03000088
    ldrh r0, [r5, #0x12]
    strh r0, [r1]
    adds r1, #6
    ldrh r0, [r5, #0x10]
    strh r0, [r1]
    ldrh r0, [r4, #0xe]
    movs r7, #0
    strh r0, [r4, #0x12]
    ldrh r0, [r4, #0xc]
    strh r0, [r4, #0x10]
    ldr r2, lbl_0805cef8 @ =0x03000080
    ldrb r1, [r2, #7]
    movs r0, #0x7f
    ands r0, r1
    cmp r0, #0
    beq lbl_0805cec2
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #7]
lbl_0805cec2:
    ldrh r1, [r5, #2]
    movs r0, #2
    bl TransparencyUpdateBLDCNT
    ldrh r0, [r5]
    strh r0, [r6]
    ldr r1, lbl_0805cefc @ =0x03005520
    strb r7, [r1, #3]
    ldr r0, lbl_0805cf00 @ =0x0300007c
    strb r7, [r0]
    movs r0, #5
    strb r0, [r1, #1]
    b lbl_0805cf40
    .align 2, 0
lbl_0805cedc: .4byte 0x04000050
lbl_0805cee0: .4byte 0x0000fffd
lbl_0805cee4: .4byte 0x0000f7ff
lbl_0805cee8: .4byte 0x02007000
lbl_0805ceec: .4byte 0x06003000
lbl_0805cef0: .4byte 0x04000008
lbl_0805cef4: .4byte 0x03000088
lbl_0805cef8: .4byte 0x03000080
lbl_0805cefc: .4byte 0x03005520
lbl_0805cf00: .4byte 0x0300007c
lbl_0805cf04:
    ldrb r0, [r3, #3]
    cmp r0, #0
    beq lbl_0805cf40
    movs r1, #0
    strb r1, [r3, #3]
    ldr r0, lbl_0805cf1c @ =0x0300007c
    strb r1, [r0]
lbl_0805cf12:
    ldrb r0, [r3, #1]
    adds r0, #1
    strb r0, [r3, #1]
    b lbl_0805cf40
    .align 2, 0
lbl_0805cf1c: .4byte 0x0300007c
lbl_0805cf20:
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cf40
lbl_0805cf2a:
    ldr r1, lbl_0805cf34 @ =0x03005520
    ldrb r0, [r1, #1]
    adds r0, #1
    strb r0, [r1, #1]
    b lbl_0805cf40
    .align 2, 0
lbl_0805cf34: .4byte 0x03005520
lbl_0805cf38:
    movs r0, #0
    strb r0, [r3, #1]
    movs r0, #1
    b lbl_0805cf42
lbl_0805cf40:
    movs r0, #0
lbl_0805cf42:
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0

    thumb_func_start apply_background_fading
apply_background_fading: @ 0x0805cf4c
    push {r4, r5, lr}
    ldr r5, lbl_0805cf8c @ =0x03000029
    ldrb r3, [r5]
    adds r2, r3, #0
    cmp r2, #0
    beq lbl_0805cfd4
    cmp r2, #0xff
    beq lbl_0805cfd4
    ldr r1, lbl_0805cf90 @ =0x03005520
    movs r0, #1
    strb r0, [r1, #5]
    movs r0, #0x80
    ands r0, r3
    lsls r0, r0, #0x18
    lsrs r4, r0, #0x18
    cmp r4, #0
    beq lbl_0805cf98
    bl sub_0805bcb0
    lsls r0, r0, #0x18
    cmp r0, #0
    beq lbl_0805cfd4
    movs r2, #0x80
    lsls r2, r2, #0x13
    ldrh r1, [r2]
    ldr r0, lbl_0805cf94 @ =0x0000f0ff
    ands r0, r1
    strh r0, [r2]
    movs r0, #0xff
    strb r0, [r5]
    b lbl_0805cfd4
    .align 2, 0
lbl_0805cf8c: .4byte 0x03000029
lbl_0805cf90: .4byte 0x03005520
lbl_0805cf94: .4byte 0x0000f0ff
lbl_0805cf98:
    cmp r2, #1
    bne lbl_0805cfb8
    movs r0, #0x18
    bl start_special_background_fading
    ldr r1, lbl_0805cfb4 @ =0x0300006b
    ldrb r0, [r1]
    cmp r0, #0
    beq lbl_0805cfc6
    strb r4, [r1]
    bl sub_0805d09c
    b lbl_0805cfc6
    .align 2, 0
lbl_0805cfb4: .4byte 0x0300006b
lbl_0805cfb8:
    cmp r2, #2
    bne lbl_0805cfc4
    movs r0, #0x17
    bl start_special_background_fading
    b lbl_0805cfc6
lbl_0805cfc4:
    strb r4, [r5]
lbl_0805cfc6:
    bl sub_0805b340
    ldr r0, lbl_0805cfdc @ =0x03000029
    ldrb r1, [r0]
    movs r2, #0x80
    orrs r1, r2
    strb r1, [r0]
lbl_0805cfd4:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0805cfdc: .4byte 0x03000029

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

    thumb_func_start sub_0805d09c
sub_0805d09c: @ 0x0805d09c
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
    bl start_special_background_fading
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

    thumb_func_start sub_0805e760
sub_0805e760: @ 0x0805e760
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
    bl start_special_background_fading
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
    bl start_special_background_fading
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

    thumb_func_start lock_hatches_with_timer
lock_hatches_with_timer: @ 0x0805f5b4
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
    bl sub_08002acc
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
    bl start_special_background_fading
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
    bl start_special_background_fading
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
    bl start_special_background_fading
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

    thumb_func_start sub_08060ab8
sub_08060ab8: @ 0x08060ab8
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

    thumb_func_start sub_08060d38
sub_08060d38: @ 0x08060d38
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
    bl sub_08002acc
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
    bl sub_08002acc
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
    bl start_special_background_fading
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
    bl sub_08002acc
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
    bl start_special_background_fading
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
    bl ClearGFXRAM
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
    bl sub_0805baac
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
    bl sub_0805baac
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
    bl sub_0805baac
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
    bl sub_0805baac
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
