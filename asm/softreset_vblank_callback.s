    .include "asm/macros.inc"

    thumb_func_start softreset_vblank_callback
softreset_vblank_callback: @ 0x080007c4
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr
