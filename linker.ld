MEMORY {
    ewram : ORIGIN = 0x02000000 LENGTH = 256K
    iwram : ORIGIN = 0x03000000 LENGTH = 32K
    rom : ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {}

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x03000043; softreset_disabled = .;
        . = 0x03000c70; game_mode = .;
        . = 0x0300137c; button_input = .;
        . = 0x0300137e; button_input_old = .;
        . = 0x03001380; buttons_changed = .;
        . = 0x03007e60; sp_sys = .;
        . = 0x03007fa0; sp_irq = .;
        . = 0x03007ffc; intr_vector = .;
    }

    rom : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/intr_main.o(.text);
        asm/blob_0x0000023c-0x000007d0.o(.text);
        asm/check_softreset.o(.text);
        asm/blob_0x00000804-0x00000968.o(.text);
        asm/update_input.o(.text);
        asm/blob_0x000009a0-0x00005190.o(.text);
        asm/syscalls.o(.text);
        asm/blob_0x000051d4-0x00800000.o(.text);
    } >rom

    /DISCARD/ : {
        *(*);
    }
}
