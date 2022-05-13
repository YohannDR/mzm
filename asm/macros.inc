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

    .macro non_word_aligned_thumb_func_start name
    .global \name
    .thumb
    .type \name, %function
    .endm
