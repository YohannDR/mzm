    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start SoundPlay
SoundPlay: @ 0x08002a18
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #0
    bl QueueSound
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start SoundStop
SoundStop: @ 0x08002a28
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    movs r1, #0
    bl StopOrFadeSound
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start unk_2a38
unk_2a38: @ 0x08002a38
    push {lr}
    adds r2,r0,#0
    ldrb r1,[r2,#0x1E]
    movs r3,#1
    adds r0,r3,#0
    ands r0,r1
    cmp r0,#0
    bne lbl_08002a54
    ldrb r1,[r2,#0]
    movs r0,#2
    ands r0,r1
    cmp r0,#0
    beq lbl_08002a54
    strb r3,[r2,#0]
lbl_08002a54:
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start StopAllMusicsAndSounds
StopAllMusicsAndSounds: @ 0x08002a58
    push {r4,r5,lr}
    ldr r0, lbl_08002a84 @ =0x00000009
    lsls r0,r0,#0x10
    lsrs r0,r0,#0x10
    subs r4,r0,#1
    cmp r4,#0
    blt lbl_08002a7e
    ldr r1, lbl_08002a88 @ =sMusicTrackDataRom
    lsls r0,r4,#1
    adds r0,r0,r4
    lsls r0,r0,#2
    adds r5,r0,r1
lbl_08002a70:
    ldr r0,[r5,#0]
    bl stop_music_or_sound
    subs r5,#0xC
    subs r4,#1
    cmp r4,#0
    bge lbl_08002a70
lbl_08002a7e:
    pop {r4,r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002a84: .4byte 0x00000009
lbl_08002a88: .4byte sMusicTrackDataRom

    thumb_func_start sub_08002a8c
sub_08002a8c: @ 0x08002a8c
    push {r4, r5, lr}
    ldr r0, lbl_08002ac4 @ =0x00000009
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    subs r4, r0, #1
    cmp r4, #0
    blt lbl_08002abe
    ldr r1, lbl_08002ac8 @ =sMusicTrackDataRom
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
    bl stop_music_or_sound
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
lbl_08002ac8: .4byte sMusicTrackDataRom

    thumb_func_start FadeAllSounds
FadeAllSounds: @ 0x08002acc
    push {r4, r5, lr}
    adds r4, r0, #0
    lsls r4, r4, #0x10
    lsrs r4, r4, #0x10
    ldr r5, lbl_08002b1c @ =sMusicTrackDataRom
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
lbl_08002b1c: .4byte sMusicTrackDataRom

    thumb_func_start SoundPlayNotAlreadyPlaying
SoundPlayNotAlreadyPlaying: @ 0x08002b20
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    adds r4, r0, #0
    ldr r3, lbl_08002b5c @ =sMusicTrackDataRom
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
    bl QueueSound
lbl_08002b56:
    pop {r4}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08002b5c: .4byte sMusicTrackDataRom
lbl_08002b60: .4byte 0x0808f2c0

    thumb_func_start sub_08002b64
sub_08002b64: @ 0x08002b64
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r5, r4, #0
    ldr r2, lbl_08002ba4 @ =sMusicTrackDataRom
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
lbl_08002ba4: .4byte sMusicTrackDataRom
lbl_08002ba8: .4byte 0x0808f2c0
lbl_08002bac:
    ldr r1, [r3]
    ldr r0, [r2, #0x10]
    cmp r1, r0
    beq lbl_08002bcc
lbl_08002bb4:
    adds r0, r4, #0
    movs r1, #0
    bl QueueSound
    b lbl_08002bcc
lbl_08002bbe:
    lsls r0, r1, #0x18
    cmp r0, #0
    bne lbl_08002bcc
    adds r0, r5, #0
    movs r1, #0
    bl QueueSound
lbl_08002bcc:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start sub_08002bd4
sub_08002bd4: @ 0x08002bd4
    push {lr}
    lsls r0, r0, #0x10
    ldr r2, lbl_08002c08 @ =sMusicTrackDataRom
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
lbl_08002c08: .4byte sMusicTrackDataRom
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
    ldr r1, lbl_08002c7c @ =sMusicTrackDataRom
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
lbl_08002c7c: .4byte sMusicTrackDataRom

    thumb_func_start SoundFade
SoundFade: @ 0x08002c80
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl StopOrFadeSound
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
    bl stop_music_or_sound
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
    bl reset_track
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
    bl reset_track
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

    thumb_func_start PlayFadingSound
PlayFadingSound: @ 0x08002de8
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    bl QueueSound
    pop {r0}
    bx r0
    .align 2, 0

    thumb_func_start InitFadingMusic
InitFadingMusic: @ 0x08002dfc
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
    ldr r0, lbl_08002f88 @ =gMusicInfo
    ldrb r1, [r0, #1]
    mov sl, r0
    cmp r1, #0
    bne lbl_08003010
    movs r4, #1
    strb r4, [r0, #1]
    ldr r3, lbl_08002f8c @ =sMusicTrackDataRom
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
    bl reset_track
    b lbl_08003000
    .align 2, 0
lbl_08002f88: .4byte gMusicInfo
lbl_08002f8c: .4byte sMusicTrackDataRom
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
    bl reset_track
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
    ldr r0, lbl_08003024 @ =gMusicInfo
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
lbl_08003024: .4byte gMusicInfo

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

    thumb_func_start DmaTransfer
DmaTransfer: @ 0x080031e4
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

    thumb_func_start BitFill
BitFill: @ 0x080032b4
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

    thumb_func_start DMA2IntrCode
DMA2IntrCode: @ 0x08003380
    push {r4, lr}
    ldr r3, lbl_080033c8 @ =gMusicInfo
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
lbl_080033c8: .4byte gMusicInfo
lbl_080033cc: .4byte 0x040000c4
lbl_080033d0: .4byte 0x84400004
lbl_080033d4: .4byte 0x040000c6
lbl_080033d8: .4byte 0x040000d2

    thumb_func_start unk_33dc
unk_33dc: @ 0x080033dc
    push {r4, r5, lr}
    sub sp, #4
    ldr r5, lbl_08003440 @ =gMusicInfo
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
    bl CpuSet
    ldr r0, lbl_08003454 @ =0x04000084
    strb r4, [r0]
    strb r4, [r5, #1]
lbl_08003438:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003440: .4byte gMusicInfo
lbl_08003444: .4byte 0x04000064
lbl_08003448: .4byte 0x84400004
lbl_0800344c: .4byte 0x00000c24
lbl_08003450: .4byte 0x05000300
lbl_08003454: .4byte 0x04000084

    thumb_func_start sub_08003458
sub_08003458: @ 0x08003458
    push {r4, r5, lr}
    sub sp, #4
    ldr r5, lbl_08003498 @ =gMusicInfo
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
    bl CpuSet
    strb r4, [r5, #1]
lbl_08003490:
    add sp, #4
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003498: .4byte gMusicInfo
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
    ldr r0, lbl_08003530 @ =sMusicTrackDataRom
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
lbl_08003530: .4byte sMusicTrackDataRom
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
    ldr r7, lbl_080035cc @ =gSoundChannelBackup
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
lbl_080035cc: .4byte gSoundChannelBackup

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
    ldr r0, lbl_08003650 @ =sMusicTrackDataRom
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
lbl_08003650: .4byte sMusicTrackDataRom
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
    ldr r0, lbl_080036cc @ =gSoundChannelBackup
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
lbl_080036cc: .4byte gSoundChannelBackup

    thumb_func_start CheckSetNewMusicTrack
CheckSetNewMusicTrack: @ 0x080036d0
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r0, lbl_080036fc @ =gMusicInfo
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
lbl_080036fc: .4byte gMusicInfo
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
    ldr r6, lbl_08003780 @ =sMusicTrackDataRom
    ldr r0, [r6, #0x48]
    movs r1, #0xa
    bl sub_08002c94
    ldr r0, [r6, #0x60]
    movs r1, #0xa
    bl sub_08002c94
    ldr r3, lbl_08003784 @ =gSoundQueue
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
lbl_08003780: .4byte sMusicTrackDataRom
lbl_08003784: .4byte gSoundQueue
lbl_08003788: .4byte 0x0808f2c0

    thumb_func_start sub_0800378c
sub_0800378c: @ 0x0800378c
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r7, lbl_08003808 @ =gMusicInfo
    ldrb r6, [r7, #1]
    cmp r6, #0
    bne lbl_08003866
    movs r0, #1
    strb r0, [r7, #1]
    ldr r4, lbl_0800380c @ =sMusicTrackDataRom
    ldr r0, [r4, #0x48]
    movs r1, #0xa
    bl sub_08002c94
    ldr r0, [r4, #0x60]
    movs r1, #0xa
    bl sub_08002c94
    ldr r3, lbl_08003810 @ =gSoundQueue
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
lbl_08003808: .4byte gMusicInfo
lbl_0800380c: .4byte sMusicTrackDataRom
lbl_08003810: .4byte gSoundQueue
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
    ldr r0, lbl_0800386c @ =sMusicTrackDataRom
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
    ldr r0, lbl_08003874 @ =gMusicInfo
    strh r5, [r0, #0x22]
lbl_08003860:
    ldr r1, lbl_08003874 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003866:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800386c: .4byte sMusicTrackDataRom
lbl_08003870: .4byte 0x0808f2c0
lbl_08003874: .4byte gMusicInfo

    thumb_func_start CheckPlayTransitionMusicTrack
CheckPlayTransitionMusicTrack: @ 0x08003878
    push {r4, r5, lr}
    ldr r4, lbl_08003898 @ =gMusicInfo
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
lbl_08003898: .4byte gMusicInfo
lbl_0800389c:
    lsls r0, r1, #0x18
    lsrs r5, r0, #0x18
    cmp r5, #0
    bne lbl_080038c8
    ldrh r0, [r4, #0x22]
    cmp r0, #0
    beq lbl_080038c8
    ldr r0, lbl_080038d0 @ =sMusicTrackDataRom
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
lbl_080038d0: .4byte sMusicTrackDataRom
lbl_080038d4: .4byte 0x0808f2c0

    thumb_func_start sub_080038d8
sub_080038d8: @ 0x080038d8
    push {r4, r5, r6, r7, lr}
    ldr r6, lbl_08003924 @ =gMusicInfo
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
    ldr r0, lbl_08003928 @ =sMusicTrackDataRom
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
    ldr r1, lbl_08003924 @ =gMusicInfo
    movs r0, #0
    strh r0, [r1, #0x22]
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003924: .4byte gMusicInfo
lbl_08003928: .4byte sMusicTrackDataRom
lbl_0800392c: .4byte 0x0808f2c0

    thumb_func_start UpdateMusicAfterAlarmDisable
UpdateMusicAfterAlarmDisable: @ 0x08003930
    push {lr}
    ldr r1, lbl_08003950 @ =gMusicInfo
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
    bl FadeCurrentMusicAndQueueNextMusic
    b lbl_0800397a
    .align 2, 0
lbl_08003950: .4byte gMusicInfo
lbl_08003954:
    subs r0, #0x5a
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    cmp r0, #9
    bhi lbl_08003970
    ldr r0, lbl_0800396c @ =sMusicTrackDataRom
    ldr r0, [r0]
    movs r1, #5
    bl sub_08002c94
    b lbl_0800397a
    .align 2, 0
lbl_0800396c: .4byte sMusicTrackDataRom
lbl_08003970:
    movs r0, #5
    movs r1, #0x49
    movs r2, #0x20
    bl FadeCurrentMusicAndQueueNextMusic
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

    thumb_func_start unk_39c8
unk_39c8: @ 0x080039c8
    push {r4, lr}
    ldr r0, lbl_080039ec @ =gMusicInfo
    adds r0, #0x21
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_080039e6
    ldr r4, lbl_080039f0 @ =sMusicTrackDataRom
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
lbl_080039ec: .4byte gMusicInfo
lbl_080039f0: .4byte sMusicTrackDataRom

    thumb_func_start PlayMusic
PlayMusic: @ 0x080039f4
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r6, #0
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    ldr r3, lbl_08003a60 @ =gMusicInfo
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
    ldr r0, lbl_08003a68 @ =sMusicTrackDataRom
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
    ldr r1, lbl_08003a60 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003a58:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003a60: .4byte gMusicInfo
lbl_08003a64: .4byte 0x0808f2c0
lbl_08003a68: .4byte sMusicTrackDataRom

    thumb_func_start sub_08003a6c
sub_08003a6c: @ 0x08003a6c
    push {lr}
    ldr r0, lbl_08003a80 @ =gMusicInfo
    adds r0, #0x20
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08003a88
    ldr r0, lbl_08003a84 @ =sMusicTrackDataRom
    ldr r0, [r0]
    b lbl_08003a8c
    .align 2, 0
lbl_08003a80: .4byte gMusicInfo
lbl_08003a84: .4byte sMusicTrackDataRom
lbl_08003a88:
    ldr r0, lbl_08003a94 @ =sMusicTrackDataRom
    ldr r0, [r0, #0xc]
lbl_08003a8c:
    bl stop_music_or_sound
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003a94: .4byte sMusicTrackDataRom

    thumb_func_start FadeMusic
FadeMusic: @ 0x08003a98
    push {lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r1, lbl_08003ac8 @ =gMusicInfo
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
    ldr r0, lbl_08003acc @ =sMusicTrackDataRom
    ldr r0, [r0]
    cmp r2, #0
    beq lbl_08003ad0
    adds r1, r2, #0
    bl sub_08002c94
    b lbl_08003ad4
    .align 2, 0
lbl_08003ac8: .4byte gMusicInfo
lbl_08003acc: .4byte sMusicTrackDataRom
lbl_08003ad0:
    bl stop_music_or_sound
lbl_08003ad4:
    ldr r1, lbl_08003ae0 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003ada:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003ae0: .4byte gMusicInfo

    thumb_func_start FadeMusicForDemo
FadeMusicForDemo: @ 0x08003ae4
    push {lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    ldr r1, lbl_08003b14 @ =gMusicInfo
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
    ldr r0, lbl_08003b18 @ =sMusicTrackDataRom
    ldr r0, [r0]
    cmp r2, #0
    beq lbl_08003b1c
    adds r1, r2, #0
    bl sub_08002c94
    b lbl_08003b20
    .align 2, 0
lbl_08003b14: .4byte gMusicInfo
lbl_08003b18: .4byte sMusicTrackDataRom
lbl_08003b1c:
    bl stop_music_or_sound
lbl_08003b20:
    ldr r1, lbl_08003b2c @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003b26:
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003b2c: .4byte gMusicInfo

    thumb_func_start FadeCurrentMusicAndQueueNextMusic
FadeCurrentMusicAndQueueNextMusic: @ 0x08003b30
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
    ldr r0, lbl_08003b60 @ =gMusicInfo
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
    bl PlayMusic
    b lbl_08003b72
    .align 2, 0
lbl_08003b60: .4byte gMusicInfo
lbl_08003b64:
    ldr r0, lbl_08003b78 @ =sMusicTrackDataRom
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
lbl_08003b78: .4byte sMusicTrackDataRom

    thumb_func_start FadeCurrentInsertMusicQueueCurrent
FadeCurrentInsertMusicQueueCurrent: @ 0x08003b7c
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
    ldr r0, lbl_08003bac @ =gMusicInfo
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
    bl PlayMusic
    b lbl_08003bc6
    .align 2, 0
lbl_08003bac: .4byte gMusicInfo
lbl_08003bb0:
    ldr r0, lbl_08003bcc @ =sMusicTrackDataRom
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
lbl_08003bcc: .4byte sMusicTrackDataRom

    thumb_func_start unk_3bd0
unk_3bd0: @ 0x08003bd0
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r4, r1, #0x10
    ldr r0, lbl_08003c14 @ =gMusicInfo
    adds r0, #0x21
    ldrb r1, [r0]
    movs r0, #0x84
    ands r0, r1
    cmp r0, #0
    bne lbl_08003c0c
    ldr r3, lbl_08003c18 @ =sMusicTrackDataRom
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
lbl_08003c14: .4byte gMusicInfo
lbl_08003c18: .4byte sMusicTrackDataRom
lbl_08003c1c: .4byte 0x0808f2c0

    thumb_func_start CheckPlayFadingMusic
CheckPlayFadingMusic: @ 0x08003c20
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r6, r0, #0x10
    adds r7, r6, #0
    lsls r1, r1, #0x10
    lsrs r1, r1, #0x10
    mov ip, r1
    lsls r2, r2, #0x18
    lsrs r2, r2, #0x18
    ldr r3, lbl_08003c94 @ =gMusicInfo
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
    ldr r0, lbl_08003c9c @ =sMusicTrackDataRom
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
    bl InitFadingMusic
lbl_08003c86:
    ldr r1, lbl_08003c94 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003c8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003c94: .4byte gMusicInfo
lbl_08003c98: .4byte 0x0808f2c0
lbl_08003c9c: .4byte sMusicTrackDataRom

    thumb_func_start InsertMusicAndQueueCurrent
InsertMusicAndQueueCurrent: @ 0x08003ca0
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsrs r2, r0, #0x10
    lsls r1, r1, #0x18
    lsrs r3, r1, #0x18
    adds r6, r3, #0
    ldr r1, lbl_08003d00 @ =gMusicInfo
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
    ldr r2, lbl_08003d08 @ =sMusicTrackDataRom
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
    bl stop_music_or_sound
    movs r0, #1
    bl sub_080034ac
    bl sub_08002a8c
    adds r2, r4, #0
    adds r2, #0x28
    ldrb r0, [r2]
    b lbl_08003d1e
    .align 2, 0
lbl_08003d00: .4byte gMusicInfo
lbl_08003d04: .4byte 0x0808f2c0
lbl_08003d08: .4byte sMusicTrackDataRom
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
    ldr r3, lbl_08003d48 @ =gMusicInfo
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
    ldr r1, lbl_08003d48 @ =gMusicInfo
    movs r0, #0
    strb r0, [r1, #1]
lbl_08003d40:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08003d48: .4byte gMusicInfo

    thumb_func_start sub_08003d4c
sub_08003d4c: @ 0x08003d4c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    lsls r0, r0, #0x18
    lsrs r0, r0, #0x18
    mov r8, r0
    ldr r4, lbl_08003d98 @ =gMusicInfo
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
    ldr r0, lbl_08003d9c @ =sMusicTrackDataRom
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
lbl_08003d98: .4byte gMusicInfo
lbl_08003d9c: .4byte sMusicTrackDataRom
lbl_08003da0:
    ldrh r0, [r4, #0x1c]
lbl_08003da2:
    ldr r1, lbl_08003e10 @ =0x0808f2c0
    lsls r0, r0, #3
    adds r0, r0, r1
    ldr r1, [r0]
    ldr r7, lbl_08003e14 @ =gMusicInfo
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
    ldr r5, lbl_08003e18 @ =sMusicTrackDataRom
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
lbl_08003e14: .4byte gMusicInfo
lbl_08003e18: .4byte sMusicTrackDataRom
lbl_08003e1c: .4byte 0x0000ffff
lbl_08003e20: .4byte 0x00000050

    thumb_func_start sub_08003e24
sub_08003e24: @ 0x08003e24
    push {lr}
    lsls r0, r0, #0x10
    lsrs r1, r0, #0x10
    ldr r0, lbl_08003e3c @ =gMusicInfo
    adds r0, #0x20
    ldrb r0, [r0]
    cmp r0, #0
    bne lbl_08003e44
    ldr r0, lbl_08003e40 @ =sMusicTrackDataRom
    ldr r0, [r0]
    b lbl_08003e48
    .align 2, 0
lbl_08003e3c: .4byte gMusicInfo
lbl_08003e40: .4byte sMusicTrackDataRom
lbl_08003e44:
    ldr r0, lbl_08003e54 @ =sMusicTrackDataRom
    ldr r0, [r0, #0xc]
lbl_08003e48:
    cmp r1, #0
    beq lbl_08003e58
    bl sub_08002c94
    b lbl_08003e5c
    .align 2, 0
lbl_08003e54: .4byte sMusicTrackDataRom
lbl_08003e58:
    bl stop_music_or_sound
lbl_08003e5c:
    pop {r0}
    bx r0

    thumb_func_start UpdateMusicPriority
UpdateMusicPriority: @ 0x08003e60
    push {r4, lr}
    lsls r0, r0, #0x18
    lsrs r2, r0, #0x18
    adds r4, r2, #0
    ldr r1, lbl_08003e88 @ =gMusicInfo
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
lbl_08003e88: .4byte gMusicInfo
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

    thumb_func_start PlayCurrentMusicTrack
PlayCurrentMusicTrack: @ 0x08003eb8
    push {r4, r5, r6, lr}
    ldr r1, lbl_08003ef0 @ =gMusicInfo
    ldrb r2, [r1, #1]
    cmp r2, #0
    bne lbl_08003f12
    movs r0, #1
    strb r0, [r1, #1]
    ldr r0, lbl_08003ef4 @ =sMusicTrackDataRom
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
lbl_08003ef0: .4byte gMusicInfo
lbl_08003ef4: .4byte sMusicTrackDataRom
lbl_08003ef8: .4byte 0x0808f2c0
lbl_08003efc:
    ldr r1, lbl_08003f18 @ =0x0808f2c0
    lsls r0, r2, #3
    adds r0, r0, r1
lbl_08003f02:
    ldr r1, [r0]
    ldr r5, lbl_08003f1c @ =gMusicInfo
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
lbl_08003f1c: .4byte gMusicInfo

    thumb_func_start DecreaseMusicVolume
DecreaseMusicVolume: @ 0x08003f20
    push {r4, r5, r6, lr}
    movs r0, #0x63
    bl SoundPlay
    movs r0, #0
    bl sub_080034ac
    ldr r2, lbl_08003f5c @ =gMusicInfo
    ldrb r1, [r2, #0xb]
    movs r0, #0x80
    orrs r0, r1
    strb r0, [r2, #0xb]
    ldr r5, lbl_08003f60 @ =sMusicTrackDataRom
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
lbl_08003f5c: .4byte gMusicInfo
lbl_08003f60: .4byte sMusicTrackDataRom
lbl_08003f64: .4byte 0x0000ffff
lbl_08003f68: .4byte 0x00000050

    thumb_func_start ResetMusicVolume
ResetMusicVolume: @ 0x08003f6c
    push {r4, r5, r6, lr}
    ldr r4, lbl_08003fa0 @ =sMusicTrackDataRom
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
    ldr r2, lbl_08003fa8 @ =gMusicInfo
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
lbl_08003fa0: .4byte sMusicTrackDataRom
lbl_08003fa4: .4byte 0x0000ffff
lbl_08003fa8: .4byte gMusicInfo

    thumb_func_start QueueSound
QueueSound: @ 0x08003fac
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
    ldr r6, lbl_08003ff4 @ =gSoundQueue
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
lbl_08003ff4: .4byte gSoundQueue
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

    thumb_func_start StopOrFadeSound
StopOrFadeSound: @ 0x08004014
    push {r4, r5, r6, r7, lr}
    lsls r0, r0, #0x10
    lsls r1, r1, #0x10
    lsrs r7, r1, #0x10
    ldr r1, lbl_08004048 @ =0x0808f2c0
    lsrs r0, r0, #0xd
    adds r0, r0, r1
    ldrb r2, [r0, #4]
    ldr r6, [r0]
    ldr r5, lbl_0800404c @ =gSoundQueue
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
lbl_0800404c: .4byte gSoundQueue
lbl_08004050:
    ldr r0, lbl_08004070 @ =sMusicTrackDataRom
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
    bl stop_music_or_sound
    b lbl_0800407c
    .align 2, 0
lbl_08004070: .4byte sMusicTrackDataRom
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

    thumb_func_start BackupTrackData2SoundChannels
BackupTrackData2SoundChannels: @ 0x0800408c
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    sub sp, #4
    movs r7, #0
    ldr r0, lbl_080040c4 @ =sMusicTrackDataRom
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
lbl_080040c4: .4byte sMusicTrackDataRom
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
    ldr r3, lbl_0800414c @ =gSoundChannelTrack2Backup
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
lbl_0800414c: .4byte gSoundChannelTrack2Backup

    thumb_func_start RetrieveTrackData2SoundChannels
RetrieveTrackData2SoundChannels: @ 0x08004150
    push {r4, r5, r6, r7, lr}
    mov r7, sb
    mov r6, r8
    push {r6, r7}
    movs r6, #0
    ldr r0, lbl_080041e4 @ =sMusicTrackDataRom
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
    ldr r0, lbl_080041e8 @ =gSoundChannelTrack2Backup
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
lbl_080041e4: .4byte sMusicTrackDataRom
lbl_080041e8: .4byte gSoundChannelTrack2Backup

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

    thumb_func_start PlaySoundTest
PlaySoundTest: @ 0x08004228
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r0, lbl_08004258 @ =gMusicInfo
    ldrh r0, [r0, #0x1c]
    cmp r5, r0
    beq lbl_08004250
    ldr r0, lbl_0800425c @ =sMusicTrackDataRom
    ldr r4, [r0]
    adds r0, r4, #0
    bl stop_music_or_sound
    adds r0, r5, #0
    movs r1, #8
    bl PlayMusic
    adds r0, r4, #0
    movs r1, #0x1e
    bl sub_080041ec
lbl_08004250:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004258: .4byte gMusicInfo
lbl_0800425c: .4byte sMusicTrackDataRom

    thumb_func_start ReplaySoundTest
ReplaySoundTest: @ 0x08004260
    push {lr}
    lsls r0, r0, #0x10
    lsrs r0, r0, #0x10
    bl SoundPlay
    ldr r0, lbl_08004278 @ =sMusicTrackDataRom
    ldr r0, [r0]
    movs r1, #0x1e
    bl sub_080041ec
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004278: .4byte sMusicTrackDataRom

    thumb_func_start CheckReplayFileSelectMusic
CheckReplayFileSelectMusic: @ 0x0800427c
    push {r4, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    ldr r0, lbl_080042a4 @ =sMusicTrackDataRom
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
    bl UpdateMusicPriority
    b lbl_080042b6
    .align 2, 0
lbl_080042a4: .4byte sMusicTrackDataRom
lbl_080042a8: .4byte 0x0808f2c0
lbl_080042ac:
    adds r0, r4, #0
    movs r1, #9
    movs r2, #2
    bl FadeCurrentMusicAndQueueNextMusic
lbl_080042b6:
    pop {r4}
    pop {r0}
    bx r0

    thumb_func_start sub_080042bc
sub_080042bc: @ 0x080042bc
    push {r4, r5, r6, lr}
    lsls r0, r0, #0x10
    lsrs r5, r0, #0x10
    ldr r4, lbl_08004300 @ =gMusicInfo
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
    ldr r0, lbl_08004308 @ =sMusicTrackDataRom
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
lbl_08004300: .4byte gMusicInfo
lbl_08004304: .4byte 0x0000012b
lbl_08004308: .4byte sMusicTrackDataRom
lbl_0800430c: .4byte 0x0808f2c0

    