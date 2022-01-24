    .include "asm/macros.inc"
    .include "asm/constants.inc"

    thumb_func_start check_softreset
check_softreset: @ 0x080007d0
    push {lr}
    ldr r2, =game_mode
    movs r1, #0x00
    ldsh r0, [r2, r1]
    cmp r0, #GAMEMODE_START_SOFTRESET
    beq end
    ldr r0, =softreset_disabled
    ldrb r0, [r0]
    cmp r0, #0
    bne end
    ldr r0, =button_input
    ldrh r1, [r0]
    movs r0, #(KEY_A | KEY_B | KEY_START | KEY_SELECT)
    and r0, r1
    cmp r0, #(KEY_A | KEY_B | KEY_START | KEY_SELECT)
    bne end
    movs r0, #GAMEMODE_START_SOFTRESET
    strh r0, [r2]
end:
    pop {r0}
    bx r0
