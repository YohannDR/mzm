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

    thumb_func_start unk_2a8c
unk_2a8c: @ 0x08002a8c
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
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x18]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x24]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x30]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x3c]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x48]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x54]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
    ldr r0, [r5, #0x60]
    adds r1, r4, #0
    bl ApplyMusicSoundFading
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
    ldr r0, lbl_08002b60 @ =sSoundDataEntries
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
lbl_08002b60: .4byte sSoundDataEntries

    thumb_func_start sub_08002b64
sub_08002b64: @ 0x08002b64
    push {r4, r5, lr}
    lsls r0, r0, #0x10
    lsrs r4, r0, #0x10
    adds r5, r4, #0
    ldr r2, lbl_08002ba4 @ =sMusicTrackDataRom
    ldr r1, lbl_08002ba8 @ =sSoundDataEntries
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
lbl_08002ba8: .4byte sSoundDataEntries
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
    ldr r1, lbl_08002c0c @ =sSoundDataEntries
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
lbl_08002c0c: .4byte sSoundDataEntries

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

    thumb_func_start ApplyMusicSoundFading
ApplyMusicSoundFading: @ 0x08002c94
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

    thumb_func_start ApplyRawMusicSoundFading
ApplyRawMusicSoundFading: @ 0x08002ce8
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
    bl InitTrack
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

    thumb_func_start unk_2e34
unk_2e34: @ 0x08002e34
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
    ldr r2, lbl_08002f90 @ =sSoundDataEntries
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
lbl_08002f90: .4byte sSoundDataEntries
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
    bl InitTrack
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

    thumb_func_start unk_3058
unk_3058: @ 0x08003058
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
