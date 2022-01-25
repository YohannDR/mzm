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
        . = 0x03000c76; cleared_every_frame = .;
        . = 0x03000c78; vblank_request_flag = .;
        . = 0x03000c7c; intr_code = .;
        . = 0x0300137c; button_input = .;
        . = 0x0300137e; button_input_old = .;
        . = 0x03001380; buttons_changed = .;
        . = 0x03001cec; vblank_callback = .;
        . = 0x03001cf0; hblank_callback = .;
        . = 0x03001cf4; vcount_callback = .;
        . = 0x03001cf8; serial_callback = .;
        . = 0x03001cfc; timer3_callback = .;
        . = 0x03007e60; sp_sys = .;
        . = 0x03007fa0; sp_irq = .;
        . = 0x03007ff8; unk_03007ff8 = .;
        . = 0x03007ffc; intr_code_ptr = .;
        . = 0x03007ffc; intr_vector = .;
    }

    rom : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/intr_main.o(.text);
        asm/main.o(.text);
        asm/init_game.o(.text);
        asm/sub_080007c4.o(.text);
        asm/check_softreset.o(.text);
        asm/softreset.o(.text);
        asm/blob_0x0000090c-0x00000968.o(.text);
        asm/update_input.o(.text);
        src/clear_ram.o(.text);
        src/load_intr_code.o(.text);
        asm/blob_0x00000a18-0x00000a98.o(.text);
        src/callbacks.o(.text);
        asm/blob_0x00000c04-0x00002564.o(.text);
        asm/init_sound.o(.text);
        asm/blob_0x000027f8-0x000031e4.o(.text);
        asm/dma_transfer.o(.text);
        asm/bit_fill.o(.text);
        asm/blob_0x00003380-0x00004d48.o(.text);
        asm/unk_08004d48.o(.text);
        asm/blob_0x00004e10-0x00005190.o(.text);
        asm/syscalls.o(.text);
        asm/blob_0x000051d4-0x0008abf8.o(.text);
        asm/libgcc.o(.text);
        asm/blob_0x0008ac34-0x00800000.o(.text);
    } >rom

    /DISCARD/ : {
        *(*);
    }
}
