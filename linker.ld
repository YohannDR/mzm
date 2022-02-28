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
        . = 0x03000002; sixteen_bit_frame_counter = .;
        . = 0x0300000A; written_to_dispcnt = .;
        . = 0x03000029; bg_fading = .;
        . = 0x0300002A; which_bg_position_is_written_to_bg30fs = .;
        . = 0x0300002B; samus_on_top_backgrounds = .;
        . = 0x0300002C; difficulty = .;
        . = 0x0300002D; use_mother_ship_doors = .;
        . = 0x0300003D; disable_scrolling = .;
        . = 0x03000042; skip_door_transition = .;
        . = 0x03000043; softreset_disabled = .;
        . = 0x03000049; disable_pause = .;
        . = 0x03000054; current_area = .;
        . = 0x03000055; current_room = .;
        . = 0x03000056; last_door_used = .;
        . = 0x03000058; bit_six_of_last_door_properties = .;
        . = 0x0300006C; effect_y_position = .;
        . = 0x03000071; screen_shake_x_related = .;
        . = 0x03000073; screen_shake_y_related = .;
        . = 0x03000074; screen_shake_related = .;
        . = 0x03000074; dispcnt_backup = .;
        . = 0x03000078; spriteset = .;
        . = 0x03000079; current_clipdata_affecting_action = .;
        . = 0x0300007A; spriteset_entry_used = .;
        . = 0x0300007B; door_ulock_timer = .;
        . = 0x03000088; io_registers_backup = .;
        . = 0x0300009C; bg_pointers_and_dimensions = .;
        . = 0x030000BC; current_room_entry = .;
        . = 0x030000DC; current_affecting_clipdata = .;
        . = 0x030000E4; background_positions = .;
        . = 0x030000F8; waiting_space_pirates_position = .;
        . = 0x03000110; screen_shake_y = .;
        . = 0x03000114; screen_shake_x = .;
        . = 0x03000118; current_scrolls = .;
        . = 0x03000130; current_power_bomb = .;
        . = 0x03000144; screen_position_and_velocity = .;
        . = 0x030001A0; unk_030001A0 = .;
        . = 0x030001A8; alarm_timer = .;
        . = 0x030001AC; sprite_data = .;
        . = 0x030006EC; spriteset_sprite_id = .;
        . = 0x030006FB; spriteset_sprite_gfx_slots = .;
        . = 0x0300070C; sub_sprite_data1 = .;
        . = 0x03000720; sub_sprite_data2 = .;
        . = 0x03000734; parasite_related = .;
        . = 0x03000738; current_sprite = .;
        . = 0x03000770; sprite_debris = .;
        . = 0x030007F0; previous_vertical_collision_check = .;
        . = 0x030007F1; previous_collision_check = .;
        . = 0x030007F1; collision_related = .;
        . = 0x030007F3; sprite_draw_order = .;
        . = 0x0300083C; sprite_rng = .;
        . = 0x03000840; particle_effects = .;
        . = 0x03000918; curr_particle_oam_frame_ptr = .;
        . = 0x0300095C; current_escape_status = .;
        . = 0x0300095D; escape_timer_counter = .;
        . = 0x0300095E; escape_timer_digits = .;
        . = 0x0300095E; particle_escape_oam_frames = .;
        . = 0x03000A2C; projectile_data = .;
        . = 0x03000BEC; arm_cannon_y = .;
        . = 0x03000BEE; arm_cannon_x = .;
        . = 0x03000BF0; pause_screen_flag = .;
        . = 0x03000B1D; is_current_file_existing = .;
        . = 0x03000c70; game_mode = .;
        . = 0x03000c72; game_mode_sub1 = .;
        . = 0x03000c74; game_mode_sub2 = .;
        . = 0x03000c75; game_mode_sub3 = .;
        . = 0x03000c76; cleared_every_frame = .;
        . = 0x03000c77; eight_bit_frame_counter = .;
        . = 0x03000c78; vblank_request_flag = .;
        . = 0x03000c7c; intr_code = .;
        . = 0x03000E7C; oam_data = .;
        . = 0x0300137c; button_input = .;
        . = 0x0300137e; button_input_old = .;
        . = 0x03001380; buttons_changed = .;
        . = 0x03001382; next_oam_slot = .;
        . = 0x030013B4; bg0_x_position = .;
        . = 0x030013B6; bg0_y_position = .;
        . = 0x030013B8; bg1_x_position = .;
        . = 0x030013BA; bg1_y_position = .;
        . = 0x030013BC; bg2_x_position = .;
        . = 0x030013BE; bg2_y_position = .;
        . = 0x030013C0; bg3_x_position = .;
        . = 0x030013C2; bg3_y_position = .;
        . = 0x030013D4; samus_data = .;
        . = 0x030013F4; samus_data_copy = .;
        . = 0x03001414; samus_weapon_info = .;
        . = 0x03001528; screw_speed_animation = .;
        . = 0x03001530; equipment = .;
        . = 0x03001530; samus_hazard_damage = .;
        . = 0x03001588; samus_physics = .;
        . = 0x03001600; previous_x_position = .;
        . = 0x03001602; previous_y_position = .;
        . = 0x03001606; prevent_movement_timer = .;
        . = 0x0300168C; button_assignments = .;
        . = 0x03001cec; vblank_callback = .;
        . = 0x03001cf0; hblank_callback = .;
        . = 0x03001cf4; vcount_callback = .;
        . = 0x03001cf8; serial_callback = .;
        . = 0x03001cfc; timer3_callback = .;
        . = 0x03004fc9; unk_03004fc9 = .;
        . = 0x030052E0; samus_palette = .;
        . = 0x0300545C; hatch_data = .;
        . = 0x030054E0; door_position_start = .;
        . = 0x030054EC; bg3_movement = .;
        . = 0x030054F4; bg0_movement = .;
        . = 0x0300550C; samus_door_position_offset = .;
        . = 0x03005708; current_room_scroll_data_pointer = .;
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
