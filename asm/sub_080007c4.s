    .include "asm/macros.inc"

    @ possibly VBlank during a softreset
    thumb_func_start sub_080007c4
sub_080007c4: @ 0x080007c4
    sub sp, #4
    mov r1, sp
    movs r0, #0
    strb r0, [r1]
    add sp, #4
    bx lr
