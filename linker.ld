MEMORY {
    ewram : ORIGIN = 0x02000000 LENGTH = 256K
    iwram : ORIGIN = 0x03000000 LENGTH = 32K
    rom : ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {} >ewram

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x00000000; debug_flag = .;
        . = 0x00000004; stereo_enabled = .;
        . = 0x0000003c; reset_game = .;
        . = 0x00000043; softreset_disabled = .;
        . = 0x00000c70; game_mode = .;
        . = 0x00000c72; game_submode1 = .;
        . = 0x00000c74; game_submode2 = .;
        . = 0x00000c76; cleared_every_frame = .;
        . = 0x00000c78; vblank_request_flag = .;
        . = 0x00000c7c; intr_code = .;
        . = 0x0000137c; button_input = .;
        . = 0x0000137e; button_input_old = .;
        . = 0x00001380; buttons_changed = .;
        . = 0x00001cec; vblank_callback = .;
        . = 0x00001cf0; hblank_callback = .;
        . = 0x00001cf4; vcount_callback = .;
        . = 0x00001cf8; serial_comm_callback = .;
        . = 0x00001cfc; timer3_callback = .;
        . = 0x00007e60; sp_sys = .;
        . = 0x00007fa0; sp_irq = .;
        . = 0x00007ff8; unk_03007ff8 = .;
        . = 0x00007ffc; intr_code_ptr = .;
        . = 0x00007ffc; intr_vector = .;
    } >iwram

    rom : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/intr_main.o(.text);
        asm/agbmain.o(.text);
        src/init_game.o(.text);
        src/softreset.o(.text);
        src/syscall_wrappers.o(.text);
        src/update_input.o(.text);
        src/clear_ram.o(.text);
        src/load_intr_code.o(.text);
        asm/disasm_0x08000a18.o(.text);
        src/callbacks.o(.text);
        asm/disasm_0x08000c04.o(.text);
        asm/syscalls.o(.text);
        asm/disasm_0x080051d4.o(.text);
        asm/libgcc.o(.text);
        asm/disasm_0x0808af18.o(.text);
        asm/data_0x0808c71c.o(.text);
    } >rom

    /DISCARD/ : {
        *(*);
    }
}
