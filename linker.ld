MEMORY {
    ewram : ORIGIN = 0x02000000 LENGTH = 256K
    iwram : ORIGIN = 0x03000000 LENGTH = 32K
    rom : ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {
        . = 0x00038000; unk_02038000 = .;
    } >ewram

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x00000000; debug_flag = .;
        . = 0x00000002; frame_counter_16bit = .;
        . = 0x00000004; stereo_enabled = .;
        . = 0x00000038; curr_demo = .;
        . = 0x0000003c; reset_game = .;
        . = 0x00000043; softreset_disabled = .;
        . = 0x0000007d; curr_cutscene = .;
        . = 0x0000007e; unk_0300007e = .;
        . = 0x00000bf0; pause_screen_flag = .;
        . = 0x00000c1c; unk_03000c1c = .;
        . = 0x00000c70; game_mode = .;
        . = 0x00000c72; game_submode1 = .;
        . = 0x00000c74; next_game_mode = .;
        . = 0x00000c75; unk_03000c75 = .;
        . = 0x00000c76; unk_03000c76 = .;
        . = 0x00000c77; frame_counter_8bit = .;
        . = 0x00000c78; vblank_request_flag = .;
        . = 0x00000c7c; intr_code = .;
        . = 0x00000e7c; oam_data = .;
        . = 0x0000137c; button_input = .;
        . = 0x0000137e; button_input_old = .;
        . = 0x00001380; buttons_changed = .;
        . = 0x00001382; next_oam_slot = .;
        . = 0x000013d2; unk_030013d2 = .;
        . = 0x00001cec; vblank_callback = .;
        . = 0x00001cf0; hblank_callback = .;
        . = 0x00001cf4; vcount_callback = .;
        . = 0x00001cf8; serial_comm_callback = .;
        . = 0x00001cfc; timer3_callback = .;
        . = 0x00001d00; music_info = .;
        . = 0x00002924; sound_data = .;
        . = 0x000058e0; src/libgcc/fp-bit-base.o(.bss);
        . = 0x000058f8; src/libgcc/float.o(.bss);
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
        src/agbmain.o(.text);
        src/init_game.o(.text);
        src/softreset.o(.text);
        src/syscall_wrappers.o(.text);
        src/update_input.o(.text);
        src/init_helpers.o(.text);
        src/fixed_point.o(.text);
        src/callbacks.o(.text);
        src/sub_08000c04.o(.text);
        asm/disasm_0x08000c48.o(.text);
        src/play_sound.o(.text);
        src/sub_08002a38.o(.text);
        asm/disasm_0x08002a58.o(.text);
        asm/syscalls.o(.text);
        src/sram/sram.o(.text);
        asm/disasm_0x08005368.o(.text);
        asm/libgcc.o(.text);
        asm/disasm_0x0808af18.o(.text);
        src/libgcc/fp-bit-base.o(.text);
        src/libgcc/float.o(.text);
        src/libgcc/libgcc.o(.text);
        asm/disasm_0x0808c6bc.o(.text);
        data/data_0x0808c71c.o(.text);
    } >rom

    /DISCARD/ : {
        *(*);
    }
}
