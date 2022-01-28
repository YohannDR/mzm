MEMORY {
    ewram : ORIGIN = 0x02000000 LENGTH = 256K
    iwram : ORIGIN = 0x03000000 LENGTH = 32K
    rom : ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {
        . = 0x02037e00; events_triggered = .;
    }

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x00000043; softreset_disabled = .;
        . = 0x00000054; current_area = .;
        . = 0x00000055; current_room = .;
        . = 0x0000006C; effect_y_position = .;
        . = 0x00000078; spriteset = .;
        . = 0x0000007A; spriteset_entry_used = .;
        . = 0x0000007d; curr_cutscene = .;
        . = 0x0000007e; unk_0300007e = .;
        . = 0x000000BC; current_room_entry = .;
        . = 0x000000F8; waiting_space_pirates_position = .;
        . = 0x000001A8; alarm_timer = .;
        . = 0x000001AC; sprite_data = .;
        . = 0x000006EC; spriteset_sprite_id = .;
        . = 0x000006FB; spriteset_sprite_gfx_slots = .;
        . = 0x00000734; parasite_related = .;
        . = 0x00000770; sprite_debris = .;
        . = 0x000007F0; previous_vertical_collision_check = .;
        . = 0x000007F3; sprite_draw_order = .;
        . = 0x00000BF0; pause_screen_flag = .;
        . = 0x00000B1D; is_current_file_existing = .;
        . = 0x00000c70; game_mode = .;
        . = 0x00000c72; game_mode_sub1 = .;
        . = 0x00000c74; game_mode_sub2 = .;
        . = 0x00000c75; game_mode_sub3 = .;
        . = 0x00000c76; cleared_every_frame = .;
        . = 0x00000c78; vblank_request_flag = .;
        . = 0x00000c7c; intr_code = .;
        . = 0x0000137c; button_input = .;
        . = 0x0000137e; button_input_old = .;
        . = 0x00001380; buttons_changed = .;
        . = 0x000013B8; bg1_x_position = .;
        . = 0x000013BA; bg1_y_position = .;
        . = 0x000013d2; unk_030013d2 = .;
        . = 0x00001cec; vblank_callback = .;
        . = 0x00001cf0; hblank_callback = .;
        . = 0x00001cf4; vcount_callback = .;
        . = 0x00001cf8; serial_callback = .;
        . = 0x00001cfc; timer3_callback = .;
        . = 0x00007e60; sp_sys = .;
        . = 0x00007fa0; sp_irq = .;
        . = 0x00007ff8; unk_03007ff8 = .;
        . = 0x00007ffc; intr_code_ptr = .;
        . = 0x00007ffc; intr_vector = .;
    }

    rom : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/intr_main.o(.text);
        src/agbmain.o(.text);
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
