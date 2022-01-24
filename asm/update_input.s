    .include "asm/constants.inc"
    .include "asm/macros.inc"

    @ void update_input(void)
    @ reads the keyboard input
    @ updates button_input, button_input_old, buttons_changed accordingly
    thumb_func_start update_input
update_input: @ 0x08000968
    push {r4, lr}
    ldr r0, =REG_KEY_INPUT
    ldrh r0, [r0]
    ldr r2, =KEY_MASK
    mov r1, r2
    bic r1, r0
    ldr r4, =buttons_changed
    ldr r3, =button_input_old
    ldrh r2, [r3]
    mov r0, r1
    bic r0, r2
    strh r0, [r4]
    ldr r0, =button_input
    strh r1, [r0]
    strh r1, [r3]
    pop {r4}
    pop {r0}
    bx r0
