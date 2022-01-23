    .macro arm_func_start name
    .align 2, 0
    .global \name
    .arm
    .type \name, %function
    .endm

    .macro thumb_func_start name
    .align 2, 0
    .global \name
    .thumb
    .type \name, %function
    .endm

    .macro baserom_blob start end
    .incbin "baserom_us.gba", \start, (\end - \start)
    .endm
