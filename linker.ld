MEMORY {
    ewram (rwx): ORIGIN = 0x02000000 LENGTH = 256K
    iwram (rwx): ORIGIN = 0x03000000 LENGTH = 32K
    rom    (rx): ORIGIN = 0x08000000 LENGTH = 32M
}

gNumMusicPlayers = 9;
gUnk_Audio0x64 = 0x64;
gUnk_Audio0x194F700 = 0x194F700;
gUnk_Audio0x50 = 0x50;

__nes_metroid_load_address = 0x87D8000;

SECTIONS {
    ewram 0x2000000 (NOLOAD) : ALIGN(4) {
        . = 0x00002000; gClipdataCollisionTypes = .;
        . = 0x00002400; gClipdataCollisionTypes_Tilemap = .;
        . = 0x00003000; gClipdataBehaviorTypes = .;
        . = 0x00003800; gClipdataBehaviorTypes_Tilemap = .;
        . = 0x00004000; gTilemap = .;
        . = 0x00006000; gCommonTilemap = .;
        . = 0x00007000; gDecompBg3Map = .;
        . = 0x00026300; gHazeValues = .;
        . = 0x00026d00; gPreviousHazeValues = .;
        . = 0x00027700; gCurrentCharacterGfx = .;
        . = 0x00027780; gMakeSolidBlocks = .;
        . = 0x00027800; gDecompClipdataMap = .;
        . = 0x0002a800; gDecompBg0Map = .;
        . = 0x0002d800; gDecompBg1Map = .;
        . = 0x00030800; gDecompBg2Map = .;
        . = 0x00033800; gMinimapTilesWithObtainedItems = .;
        . = 0x00034000; gDecompressedMinimapVisitedTiles = .;
        . = 0x00034800; gDecompressedMinimapData = .;
        . = 0x00035400; gUnk_02035400 = .;
        . = 0x00035c00; gNeverReformBlocks = .;
        . = 0x00036c00; gItemsCollected = .;
        . = 0x00037400; gVisitedMinimapTiles = .;
        . = 0x00037e00; gEventsTriggered = .;
        . = 0x00037e20; gMinimapTilesGfx = .;
        . = 0x00038000; gSram = .;

        . = 0x0003f080; gSramDemoInputData = .;
        . = 0x0003f280; gSramDemoInputDuration = .;
    } >ewram

    iwram 0x3000000 (NOLOAD) : ALIGN(4) {
        src/globals1.o(iwram_data);
        *libgcc.a:dp-bit.o(.bss);
        *libgcc.a:fp-bit.o(.bss);
        src/globals2.o(iwram_data);
        . = 0x00007ff8; gInterruptCheckFlag = .;
        . = 0x00007ffc; gIntrCodePointer = .;
        . = 0x00007ffc; gIntrVector = .;
    } >iwram

    .text : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        src/agbmain.o(.text);
        src/init_game.o(.text);
        src/soft_reset_input.o(.text);
        src/syscall_wrappers.o(.text);
        src/update_input.o(.text);
        src/init_helpers.o(.text);
        src/fixed_point.o(.text);
        src/callbacks.o(.text);
        src/sram_misc.o(.text);

        src/audio.o(.text);
        src/audio_wrappers.o(.text);
        src/dma.o(.text);
        src/music_wrappers.o(.text);

        asm/soundcode.o(.text);
        asm/audio_internal.o(.text);
        asm/syscalls.o(.text);

        src/sram/sram.o(.text);
        src/samus.o(.text);
        src/demo_input.o(.text);
        src/in_game.o(.text);
        src/sprite.o(.text);
        src/sprite_util.o(.text);
        src/sprite_debris.o(.text);
        src/location_text.o(.text);

        src/sprites_ai/chozo_statue_movement.o(.text);
        src/sprites_ai/water_drop.o(.text);
        src/sprites_ai/explosion_zebes_escape.o(.text);
        src/sprites_ai/enemy_drop.o(.text);
        src/sprites_ai/unused_sprites.o(.text);
        src/sprites_ai/morph_ball.o(.text);
        src/sprites_ai/power_grip.o(.text);
        src/sprites_ai/charge_beam.o(.text);
        src/sprites_ai/chozo_statue.o(.text);
        src/sprites_ai/unknown_item_chozo_statue.o(.text);
        src/sprites_ai/chozo_ball.o(.text);
        src/sprites_ai/zoomer.o(.text);
        src/sprites_ai/zeela.o(.text);
        src/sprites_ai/kraid.o(.text);
        src/sprites_ai/message_banner.o(.text);
        src/sprites_ai/ripper.o(.text);
        src/sprites_ai/ripper2.o(.text);
        src/sprites_ai/zeb.o(.text);
        src/sprites_ai/skree.o(.text);
        src/sprites_ai/reo.o(.text);
        src/sprites_ai/zipline.o(.text);
        src/sprites_ai/sova.o(.text);
        src/sprites_ai/multiviola.o(.text);
        src/sprites_ai/geruta.o(.text);
        src/sprites_ai/squeept.o(.text);
        src/sprites_ai/map_station.o(.text);
        src/sprites_ai/save_platform.o(.text);
        src/sprites_ai/dragon.o(.text);
        src/sprites_ai/deorem.o(.text);
        src/sprites_ai/dessgeega.o(.text);
        src/sprites_ai/waver.o(.text);
        src/sprites_ai/hive.o(.text);
        src/sprites_ai/imago_larva.o(.text);
        src/sprites_ai/morph_ball_launcher.o(.text);
        src/sprites_ai/imago_cocoon.o(.text);
        src/sprites_ai/elevator_pad.o(.text);
        src/sprites_ai/space_pirate.o(.text);
        src/sprites_ai/black_space_pirate.o(.text);
        src/sprites_ai/escape_ship_pirate.o(.text);
        src/sprites_ai/zipline_generator.o(.text);
        src/sprites_ai/gamet.o(.text);
        src/sprites_ai/security_gate.o(.text);
        src/sprites_ai/zebbo.o(.text);
        src/sprites_ai/worker_robot.o(.text);
        src/sprites_ai/parasite.o(.text);
        src/sprites_ai/piston.o(.text);
        src/sprites_ai/ridley.o(.text);
        src/sprites_ai/metroid.o(.text);
        src/sprites_ai/rinka.o(.text);
        src/sprites_ai/polyp.o(.text);
        src/sprites_ai/viola.o(.text);
        src/sprites_ai/security_laser.o(.text);
        src/sprites_ai/holtz.o(.text);
        src/sprites_ai/gekitai_machine.o(.text);
        src/sprites_ai/ruins_test.o(.text);
        src/sprites_ai/mella.o(.text);
        src/sprites_ai/atomic.o(.text);
        src/sprites_ai/area_banner.o(.text);
        src/sprites_ai/mother_brain.o(.text);
        src/sprites_ai/acid_worm.o(.text);
        src/sprites_ai/sidehopper.o(.text);
        src/sprites_ai/geron_norfair.o(.text);
        src/sprites_ai/geega.o(.text);
        src/sprites_ai/zebetite_and_cannon.o(.text);
        src/sprites_ai/imago_larva_right_side.o(.text);
        src/sprites_ai/tangle_vine.o(.text);
        src/sprites_ai/imago.o(.text);
        src/sprites_ai/crocomire.o(.text);
        src/sprites_ai/searchlight_eye.o(.text);
        src/sprites_ai/geron.o(.text);
        src/sprites_ai/gunship.o(.text);
        src/sprites_ai/glass_tube.o(.text);
        src/sprites_ai/save_platform_chozodia.o(.text);
        src/sprites_ai/baristute.o(.text);
        src/sprites_ai/elevator_statue.o(.text);
        src/sprites_ai/rising_chozo_pillar.o(.text);
        src/sprites_ai/skultera.o(.text);
        src/sprites_ai/boss_statues.o(.text);
        src/sprites_ai/searchlight.o(.text);
        src/sprites_ai/primary_sprite_b3.o(.text);
        src/sprites_ai/gadora.o(.text);
        src/sprites_ai/steam.o(.text);
        src/sprites_ai/unknown_item_block.o(.text);
        src/sprites_ai/escape_ship.o(.text);
        src/sprites_ai/space_pirate_carrying_power_bomb.o(.text);
        src/sprites_ai/falling_chozo_pillar.o(.text);
        src/sprites_ai/mecha_ridley.o(.text);
        src/sprites_ai/escape_gate.o(.text);

        src/projectile_util.o(.text);
        src/projectile.o(.text);
        src/hud.o(.text);
        src/escape.o(.text);
        src/hud_generic.o(.text);
        src/particle.o(.text);
        src/screen_shake.o(.text);
        src/transparency.o(.text);
        src/room.o(.text);
        src/power_bomb_explosion.o(.text);
        src/gadora_hatch.o(.text);
        src/in_game_timer.o(.text);
        src/display.o(.text);
        src/process_pause_press.o(.text);
        src/room_cutscene.o(.text);
        src/clipdata.o(.text);
        src/scroll.o(.text);
        src/block.o(.text);
        src/bg_clip.o(.text);
        src/color_effects.o(.text);
        src/color_fading.o(.text);
        src/haze.o(.text);
        src/animated_graphics.o(.text);
        src/connection.o(.text);
        src/in_game_cutscene.o(.text);
        src/event.o(.text);
        src/room_music.o(.text);
        src/demo.o(.text);

        src/cutscenes/cutscene_utils.o(.text);
        src/cutscenes/kraid_rising.o(.text);
        src/cutscenes/story_text_cutscene.o(.text);
        src/cutscenes/mother_brain_close_up.o(.text);
        src/cutscenes/ridley_in_space.o(.text);
        src/cutscenes/ridley_landing.o(.text);
        src/cutscenes/ridley_spawn.o(.text);
        src/cutscenes/mecha_sees_samus.o(.text);
        src/cutscenes/getting_fully_powered_suit.o(.text);
        src/cutscenes/before_ruins_test.o(.text);
        src/cutscenes/statue_opening.o(.text);
        src/cutscenes/enter_tourian.o(.text);
        src/cutscenes/samus_in_blue_ship.o(.text);

        src/oam_id.o(.text);
        src/menus/pause_screen.o(.text);
        src/minimap.o(.text);
        src/menus/pause_screen_map.o(.text);
        src/text.o(.text);
        src/menus/status_screen.o(.text);
        src/menus/pause_screen_sub_menus.o(.text);
        src/save_file.o(.text);
        src/save_file_load.o(.text);

#ifdef DEBUG
        src/menus/boot_debug.o(.text);
#endif

        src/menus/erase_sram.o(.text);
        src/menus/title_screen.o(.text);
        src/menus/game_over.o(.text);
        src/menus/file_select.o(.text);

        src/soft_reset.o(.text);
        src/time_attack.o(.text);
        src/complex_oam.o(.text);
        src/intro.o(.text);
        src/tourian_escape.o(.text);
        src/fusion_gallery.o(.text);
        src/ending_and_gallery.o(.text);
        src/chozodia_escape.o(.text);
        src/cable_link.o(.text);
        src/multiboot.o(.text);
        src/transfer.o(.text);
        src/link.o(.text);

        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_fixunsdfsi.o(.text);
        *libgcc.a:_modsi3.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        *libgcc.a:_umodsi3.o(.text);

        *libgcc.a:dp-bit.o(.text);
        *libgcc.a:fp-bit.o(.text);
        *libgcc.a:_lshrdi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_negdi2.o(.text);
        *libc.a:memcpy.o(.text);
    } >rom

    .rodata : ALIGN(2) {
        src/data/generic_data.o(.rodata);
        src/data/audio.o(.rodata);

        sound/voice_groups.o(.rodata);
        sound/programmable_wave_data.o(.rodata);

        src/data/music_track_data.o(.rodata);
        sound/sound_entries.o(.rodata);

        sound/tracks/track_0.o(.rodata);

        sound/direct_sound_data.o(.rodata);

        sound/track_data.o(.rodata);

        src/sram/sram.o(.rodata);

        src/data/samus/samus_empty_data.o(.rodata);
        src/data/samus/arm_cannon_data.o(.rodata);
        src/data/samus/samus_palette_data.o(.rodata);
        src/data/samus/samus_animation_pointers.o(.rodata);
        src/data/samus/samus_graphics.o(.rodata);

        src/data/sprite_data.o(.rodata);
        src/data/spriteset.o(.rodata);
        src/data/sprites/enemy_drop.o(.rodata);
        src/data/sprites/unused_sprites.o(.rodata);
        src/data/sprites/morph_ball.o(.rodata);
        src/data/sprites/power_grip.o(.rodata);
        src/data/sprites/charge_beam.o(.rodata);
        src/data/sprites/chozo_statue.o(.rodata);
        src/data/sprites/unknown_item_chozo_statue.o(.rodata);
        src/data/sprites/zoomer.o(.rodata);
        src/data/sprites/zeela.o(.rodata);
        src/data/sprites/kraid.o(.rodata);
        src/data/sprites/message_banner.o(.rodata);
        src/data/sprites/ripper.o(.rodata);
        src/data/sprites/ripper2.o(.rodata);
        src/data/sprites/zeb.o(.rodata);
        src/data/sprites/skree.o(.rodata);
        src/data/sprites/reo.o(.rodata);
        src/data/sprites/zipline.o(.rodata);
        src/data/sprites/sova.o(.rodata);
        src/data/sprites/multiviola.o(.rodata);
        src/data/sprites/geruta.o(.rodata);
        src/data/sprites/squeept.o(.rodata);
        src/data/sprites/map_station.o(.rodata);
        src/data/sprites/save_platform.o(.rodata);
        src/data/sprites/dragon.o(.rodata);
        src/data/sprites/deorem.o(.rodata);
        src/data/sprites/dessgeega.o(.rodata);
        src/data/sprites/waver.o(.rodata);
        src/data/sprites/hive.o(.rodata);
        src/data/sprites/imago_larva.o(.rodata);
        src/data/sprites/morph_ball_launcher.o(.rodata);
        src/data/sprites/imago_cocoon.o(.rodata);
        src/data/sprites/elevator_pad.o(.rodata);
        src/data/sprites/space_pirate.o(.rodata);
        src/data/sprites/zipline_generator.o(.rodata);
        src/data/sprites/gamet.o(.rodata);
        src/data/sprites/security_gate.o(.rodata);
        src/data/sprites/zebbo.o(.rodata);
        src/data/sprites/worker_robot.o(.rodata);
        src/data/sprites/parasite.o(.rodata);
        src/data/sprites/piston.o(.rodata);
        src/data/sprites/ridley.o(.rodata);
        src/data/sprites/metroid.o(.rodata);
        src/data/sprites/rinka.o(.rodata);
        src/data/sprites/polyp.o(.rodata);
        src/data/sprites/viola.o(.rodata);
        src/data/sprites/security_laser.o(.rodata);
        src/data/sprites/holtz.o(.rodata);
        src/data/sprites/gekitai_machine.o(.rodata);
        src/data/sprites/ruins_test.o(.rodata);
        src/data/sprites/mella.o(.rodata);
        src/data/sprites/atomic.o(.rodata);
        src/data/sprites/area_banner.o(.rodata);
        src/data/sprites/mother_brain.o(.rodata);
        src/data/sprites/acid_worm.o(.rodata);
        src/data/sprites/sidehopper.o(.rodata);
        src/data/sprites/geron_norfair.o(.rodata);
        src/data/sprites/geega.o(.rodata);
        src/data/sprites/zebetite_and_cannon.o(.rodata);
        src/data/sprites/imago_larva_right_side.o(.rodata);
        src/data/sprites/tangle_vine.o(.rodata);
        src/data/sprites/imago.o(.rodata);
        src/data/sprites/crocomire.o(.rodata);
        src/data/sprites/searchlight_eye.o(.rodata);
        src/data/sprites/geron.o(.rodata);
        src/data/sprites/gunship.o(.rodata);
        src/data/sprites/glass_tube.o(.rodata);
        src/data/sprites/save_platform_chozodia.o(.rodata);
        src/data/sprites/baristute.o(.rodata);
        src/data/sprites/elevator_statue.o(.rodata);
        src/data/sprites/rising_chozo_pillar.o(.rodata);
        src/data/sprites/skultera.o(.rodata);
        src/data/sprites/boss_statues.o(.rodata);
        src/data/sprites/searchlight.o(.rodata);
        src/data/sprites/gadora.o(.rodata);
        src/data/sprites/steam.o(.rodata);
        src/data/sprites/unknown_item_block.o(.rodata);
        src/data/sprites/escape_ship.o(.rodata);
        src/data/sprites/space_pirate_carrying_power_bomb.o(.rodata);
        src/data/sprites/falling_chozo_pillar.o(.rodata);
        src/data/sprites/mecha_ridley.o(.rodata);
        src/data/sprites/escape_gate.o(.rodata);
        src/data/projectile_data.o(.rodata);
        src/data/hud_data.o(.rodata);
        src/data/particle_data.o(.rodata);
        src/data/visual_effects_data.o(.rodata);
        src/data/rooms_data.o(.rodata);
        src/data/empty_datatypes.o(.rodata);
        src/data/clipdata_data.o(.rodata);
        src/data/block_data.o(.rodata);
        src/data/color_fading_data.o(.rodata);
        src/data/haze_data.o(.rodata);
        src/data/animated_graphics_data.o(.rodata);
        src/data/hatch_data.o(.rodata);
        src/data/in_game_cutscene_data.o(.rodata);
        src/data/demo_data.o(.rodata);
        src/data/default_background_data.o(.rodata);
        src/data/clipdata_types_tilemap.o(.rodata);
        src/data/rooms/test_rooms_data.o(.rodata);

        src/data/samus_close_up_data.o(.rodata);
        src/data/cutscenes/cutscenes_data.o(.rodata);
        src/data/cutscenes/kraid_rising_data.o(.rodata);
        src/data/cutscenes/story_text_cutscene_data.o(.rodata);
        src/data/cutscenes/mother_brain_close_up_data.o(.rodata);
        src/data/cutscenes/ridley_in_space_data.o(.rodata);
        src/data/cutscenes/ridley_landing_data.o(.rodata);
        src/data/cutscenes/ridley_spawn_data.o(.rodata);
        src/data/cutscenes/mecha_sees_samus_data.o(.rodata);
        src/data/cutscenes/getting_fully_powered_suit_data.o(.rodata);
        src/data/cutscenes/before_ruins_test_data.o(.rodata);
        src/data/cutscenes/statue_opening_data.o(.rodata);
        src/data/cutscenes/enter_tourian_data.o(.rodata);
        src/data/cutscenes/samus_in_blue_ship_data.o(.rodata);
        src/data/menus/pause_screen_data.o(.rodata);
        src/data/menus/status_screen_data.o(.rodata);
        src/data/menus/pause_screen_sub_menus_data.o(.rodata);
        src/data/menus/pause_screen_map_data.o(.rodata);
        src/data/save_file_data.o(.rodata);

#ifdef DEBUG
        src/data/menus/boot_debug_data.o(.rodata);
#endif

        src/data/menus/erase_sram_data.o(.rodata);
        src/data/text_data.o(.rodata);
        src/data/menus/title_screen_data.o(.rodata);
        src/data/menus/game_over_data.o(.rodata);
        src/data/menus/file_select_data.o(.rodata);

#ifdef REGION_EU
        src/data/menus/language_select_data.o(.rodata);
#endif

        src/data/intro_data.o(.rodata);
        src/data/tourian_escape_data.o(.rodata);
        src/data/fusion_gallery_data.o(.rodata);
        src/data/ending_and_gallery_data.o(.rodata);
        src/data/chozodia_escape_data.o(.rodata);
        src/data/io_transfer_data.o(.rodata);
        src/data/clipdata_types.o(.rodata);
        src/data/tilesets/tilesets_set0.o(.rodata);
        src/data/common_pals.o(.rodata);
        src/data/tilesets/tilesets_set1.o(.rodata);

        src/data/rooms/brinstar/brinstar_0.o(.rodata);
        src/data/rooms/brinstar/brinstar_1.o(.rodata);
        src/data/rooms/brinstar/brinstar_2.o(.rodata);
        src/data/rooms/brinstar/brinstar_3.o(.rodata);
        src/data/rooms/brinstar/brinstar_4.o(.rodata);
        src/data/rooms/brinstar/brinstar_5.o(.rodata);
        src/data/rooms/brinstar/brinstar_6.o(.rodata);
        src/data/rooms/brinstar/brinstar_7.o(.rodata);
        src/data/rooms/brinstar/brinstar_8.o(.rodata);
        src/data/rooms/brinstar/brinstar_9.o(.rodata);
        src/data/rooms/brinstar/brinstar_10.o(.rodata);
        src/data/rooms/brinstar/brinstar_11.o(.rodata);
        src/data/rooms/brinstar/brinstar_12.o(.rodata);
        src/data/rooms/brinstar/brinstar_13.o(.rodata);
        src/data/rooms/brinstar/brinstar_14.o(.rodata);
        src/data/rooms/brinstar/brinstar_15.o(.rodata);
        src/data/rooms/brinstar/brinstar_16.o(.rodata);
        src/data/rooms/brinstar/brinstar_17.o(.rodata);
        src/data/rooms/brinstar/brinstar_18.o(.rodata);
        src/data/rooms/brinstar/brinstar_19.o(.rodata);
        src/data/rooms/brinstar/brinstar_20.o(.rodata);
        src/data/rooms/brinstar/brinstar_21.o(.rodata);
        src/data/rooms/brinstar/brinstar_22.o(.rodata);
        src/data/rooms/brinstar/brinstar_23.o(.rodata);
        src/data/rooms/brinstar/brinstar_24.o(.rodata);
        src/data/rooms/brinstar/brinstar_25.o(.rodata);
        src/data/rooms/brinstar/brinstar_26.o(.rodata);
        src/data/rooms/brinstar/brinstar_27.o(.rodata);
        src/data/rooms/brinstar/brinstar_28.o(.rodata);
        src/data/rooms/brinstar/brinstar_29.o(.rodata);
        src/data/rooms/brinstar/brinstar_30.o(.rodata);
        src/data/rooms/brinstar/brinstar_31.o(.rodata);
        src/data/rooms/brinstar/brinstar_32.o(.rodata);
        src/data/rooms/brinstar/brinstar_33.o(.rodata);
        src/data/rooms/brinstar/brinstar_34.o(.rodata);
        src/data/rooms/brinstar/brinstar_35.o(.rodata);
        src/data/rooms/brinstar/brinstar_36.o(.rodata);
        src/data/rooms/brinstar/brinstar_37.o(.rodata);
        src/data/rooms/brinstar/brinstar_38.o(.rodata);
        src/data/rooms/brinstar/brinstar_39.o(.rodata);
        src/data/rooms/brinstar/brinstar_40.o(.rodata);
        src/data/rooms/brinstar/brinstar_41.o(.rodata);
        src/data/rooms/brinstar/bg3.o(.rodata);

        src/data/tilesets/tilesets_set2.o(.rodata);

        src/data/rooms/kraid/kraid_0.o(.rodata);
        src/data/rooms/kraid/kraid_1.o(.rodata);
        src/data/rooms/kraid/kraid_2.o(.rodata);
        src/data/rooms/kraid/kraid_3.o(.rodata);
        src/data/rooms/kraid/kraid_4.o(.rodata);
        src/data/rooms/kraid/kraid_5.o(.rodata);
        src/data/rooms/kraid/kraid_6.o(.rodata);
        src/data/rooms/kraid/kraid_7.o(.rodata);
        src/data/rooms/kraid/kraid_8.o(.rodata);
        src/data/rooms/kraid/kraid_9.o(.rodata);
        src/data/rooms/kraid/kraid_10.o(.rodata);
        src/data/rooms/kraid/kraid_11.o(.rodata);
        src/data/rooms/kraid/kraid_12.o(.rodata);
        src/data/rooms/kraid/kraid_13.o(.rodata);
        src/data/rooms/kraid/kraid_14.o(.rodata);
        src/data/rooms/kraid/kraid_15.o(.rodata);
        src/data/rooms/kraid/kraid_16.o(.rodata);
        src/data/rooms/kraid/kraid_17.o(.rodata);
        src/data/rooms/kraid/kraid_18.o(.rodata);
        src/data/rooms/kraid/kraid_19.o(.rodata);
        src/data/rooms/kraid/kraid_20.o(.rodata);
        src/data/rooms/kraid/kraid_21.o(.rodata);
        src/data/rooms/kraid/kraid_22.o(.rodata);
        src/data/rooms/kraid/kraid_23.o(.rodata);
        src/data/rooms/kraid/kraid_24.o(.rodata);
        src/data/rooms/kraid/kraid_25.o(.rodata);
        src/data/rooms/kraid/kraid_26.o(.rodata);
        src/data/rooms/kraid/kraid_27.o(.rodata);
        src/data/rooms/kraid/kraid_28.o(.rodata);
        src/data/rooms/kraid/kraid_29.o(.rodata);
        src/data/rooms/kraid/kraid_30.o(.rodata);
        src/data/rooms/kraid/kraid_31.o(.rodata);
        src/data/rooms/kraid/kraid_32.o(.rodata);
        src/data/rooms/kraid/kraid_33.o(.rodata);
        src/data/rooms/kraid/kraid_34.o(.rodata);
        src/data/rooms/kraid/kraid_35.o(.rodata);
        src/data/rooms/kraid/kraid_36.o(.rodata);
        src/data/rooms/kraid/kraid_37.o(.rodata);
        src/data/rooms/kraid/kraid_38.o(.rodata);
        src/data/rooms/kraid/kraid_39.o(.rodata);
        src/data/rooms/kraid/kraid_40.o(.rodata);
        src/data/rooms/kraid/kraid_41.o(.rodata);
        src/data/rooms/kraid/bg3.o(.rodata);

        src/data/tilesets/tilesets_set3.o(.rodata);

        src/data/rooms/norfair/norfair_0.o(.rodata);
        src/data/rooms/norfair/norfair_1.o(.rodata);
        src/data/rooms/norfair/norfair_2.o(.rodata);
        src/data/rooms/norfair/norfair_3.o(.rodata);
        src/data/rooms/norfair/norfair_4.o(.rodata);
        src/data/rooms/norfair/norfair_5.o(.rodata);
        src/data/rooms/norfair/norfair_6.o(.rodata);
        src/data/rooms/norfair/norfair_7.o(.rodata);
        src/data/rooms/norfair/norfair_8.o(.rodata);
        src/data/rooms/norfair/norfair_9.o(.rodata);
        src/data/rooms/norfair/norfair_10.o(.rodata);
        src/data/rooms/norfair/norfair_11.o(.rodata);
        src/data/rooms/norfair/norfair_12.o(.rodata);
        src/data/rooms/norfair/norfair_13.o(.rodata);
        src/data/rooms/norfair/norfair_14.o(.rodata);
        src/data/rooms/norfair/norfair_15.o(.rodata);
        src/data/rooms/norfair/norfair_16.o(.rodata);
        src/data/rooms/norfair/norfair_17.o(.rodata);
        src/data/rooms/norfair/norfair_18.o(.rodata);
        src/data/rooms/norfair/norfair_19.o(.rodata);
        src/data/rooms/norfair/norfair_20.o(.rodata);
        src/data/rooms/norfair/norfair_21.o(.rodata);
        src/data/rooms/norfair/norfair_22.o(.rodata);
        src/data/rooms/norfair/norfair_23.o(.rodata);
        src/data/rooms/norfair/norfair_24.o(.rodata);
        src/data/rooms/norfair/norfair_25.o(.rodata);
        src/data/rooms/norfair/norfair_26.o(.rodata);
        src/data/rooms/norfair/norfair_27.o(.rodata);
        src/data/rooms/norfair/norfair_28.o(.rodata);
        src/data/rooms/norfair/norfair_29.o(.rodata);
        src/data/rooms/norfair/norfair_30.o(.rodata);
        src/data/rooms/norfair/norfair_31.o(.rodata);
        src/data/rooms/norfair/norfair_32.o(.rodata);
        src/data/rooms/norfair/norfair_33.o(.rodata);
        src/data/rooms/norfair/norfair_34.o(.rodata);
        src/data/rooms/norfair/norfair_35.o(.rodata);
        src/data/rooms/norfair/norfair_36.o(.rodata);
        src/data/rooms/norfair/norfair_37.o(.rodata);
        src/data/rooms/norfair/norfair_38.o(.rodata);
        src/data/rooms/norfair/norfair_39.o(.rodata);
        src/data/rooms/norfair/norfair_40.o(.rodata);
        src/data/rooms/norfair/norfair_41.o(.rodata);
        src/data/rooms/norfair/norfair_42.o(.rodata);
        src/data/rooms/norfair/norfair_43.o(.rodata);
        src/data/rooms/norfair/norfair_44.o(.rodata);
        src/data/rooms/norfair/norfair_45.o(.rodata);
        src/data/rooms/norfair/norfair_46.o(.rodata);
        src/data/rooms/norfair/norfair_47.o(.rodata);
        src/data/rooms/norfair/norfair_48.o(.rodata);
        src/data/rooms/norfair/norfair_49.o(.rodata);
        src/data/rooms/norfair/norfair_50.o(.rodata);
        src/data/rooms/norfair/norfair_51.o(.rodata);
        src/data/rooms/norfair/norfair_52.o(.rodata);
        src/data/rooms/norfair/norfair_53.o(.rodata);
        src/data/rooms/norfair/norfair_54.o(.rodata);
        src/data/rooms/norfair/norfair_55.o(.rodata);
        src/data/rooms/norfair/norfair_56.o(.rodata);
        src/data/rooms/norfair/bg3.o(.rodata);

        src/data/tilesets/tilesets_set4.o(.rodata);

        src/data/rooms/ridley/ridley_0.o(.rodata);
        src/data/rooms/ridley/ridley_1.o(.rodata);
        src/data/rooms/ridley/ridley_2.o(.rodata);
        src/data/rooms/ridley/ridley_3.o(.rodata);
        src/data/rooms/ridley/ridley_4.o(.rodata);
        src/data/rooms/ridley/ridley_5.o(.rodata);
        src/data/rooms/ridley/ridley_6.o(.rodata);
        src/data/rooms/ridley/ridley_7.o(.rodata);
        src/data/rooms/ridley/ridley_8.o(.rodata);
        src/data/rooms/ridley/ridley_9.o(.rodata);
        src/data/rooms/ridley/ridley_10.o(.rodata);
        src/data/rooms/ridley/ridley_11.o(.rodata);
        src/data/rooms/ridley/ridley_12.o(.rodata);
        src/data/rooms/ridley/ridley_13.o(.rodata);
        src/data/rooms/ridley/ridley_14.o(.rodata);
        src/data/rooms/ridley/ridley_15.o(.rodata);
        src/data/rooms/ridley/ridley_16.o(.rodata);
        src/data/rooms/ridley/ridley_17.o(.rodata);
        src/data/rooms/ridley/ridley_18.o(.rodata);
        src/data/rooms/ridley/ridley_19.o(.rodata);
        src/data/rooms/ridley/ridley_20.o(.rodata);
        src/data/rooms/ridley/ridley_21.o(.rodata);
        src/data/rooms/ridley/ridley_22.o(.rodata);
        src/data/rooms/ridley/ridley_23.o(.rodata);
        src/data/rooms/ridley/ridley_24.o(.rodata);
        src/data/rooms/ridley/ridley_25.o(.rodata);
        src/data/rooms/ridley/ridley_26.o(.rodata);
        src/data/rooms/ridley/ridley_27.o(.rodata);
        src/data/rooms/ridley/ridley_28.o(.rodata);
        src/data/rooms/ridley/ridley_29.o(.rodata);
        src/data/rooms/ridley/ridley_30.o(.rodata);
        src/data/rooms/ridley/ridley_31.o(.rodata);
        src/data/rooms/ridley/ridley_32.o(.rodata);
        src/data/rooms/ridley/bg3.o(.rodata);

        src/data/tilesets/tilesets_set5.o(.rodata);

        src/data/rooms/tourian/tourian_0.o(.rodata);
        src/data/rooms/tourian/tourian_1.o(.rodata);
        src/data/rooms/tourian/tourian_2.o(.rodata);
        src/data/rooms/tourian/tourian_3.o(.rodata);
        src/data/rooms/tourian/tourian_4.o(.rodata);
        src/data/rooms/tourian/tourian_5.o(.rodata);
        src/data/rooms/tourian/tourian_6.o(.rodata);
        src/data/rooms/tourian/tourian_7.o(.rodata);
        src/data/rooms/tourian/tourian_8.o(.rodata);
        src/data/rooms/tourian/tourian_9.o(.rodata);
        src/data/rooms/tourian/tourian_10.o(.rodata);
        src/data/rooms/tourian/tourian_11.o(.rodata);
        src/data/rooms/tourian/tourian_12.o(.rodata);
        src/data/rooms/tourian/tourian_13.o(.rodata);
        src/data/rooms/tourian/tourian_14.o(.rodata);
        src/data/rooms/tourian/tourian_15.o(.rodata);
        src/data/rooms/tourian/tourian_16.o(.rodata);
        src/data/rooms/tourian/tourian_17.o(.rodata);
        src/data/rooms/tourian/tourian_18.o(.rodata);
        src/data/rooms/tourian/tourian_19.o(.rodata);
        src/data/rooms/tourian/bg3.o(.rodata);

        src/data/tilesets/tilesets_set6.o(.rodata);

        src/data/rooms/crateria/crateria_0.o(.rodata);
        src/data/rooms/crateria/crateria_1.o(.rodata);
        src/data/rooms/crateria/crateria_2.o(.rodata);
        src/data/rooms/crateria/crateria_3.o(.rodata);
        src/data/rooms/crateria/crateria_4.o(.rodata);
        src/data/rooms/crateria/crateria_5.o(.rodata);
        src/data/rooms/crateria/crateria_6.o(.rodata);
        src/data/rooms/crateria/crateria_7.o(.rodata);
        src/data/rooms/crateria/crateria_8.o(.rodata);
        src/data/rooms/crateria/crateria_9.o(.rodata);
        src/data/rooms/crateria/crateria_10.o(.rodata);
        src/data/rooms/crateria/crateria_11.o(.rodata);
        src/data/rooms/crateria/crateria_12.o(.rodata);
        src/data/rooms/crateria/crateria_13.o(.rodata);
        src/data/rooms/crateria/crateria_14.o(.rodata);
        src/data/rooms/crateria/crateria_15.o(.rodata);
        src/data/rooms/crateria/crateria_16.o(.rodata);
        src/data/rooms/crateria/crateria_17.o(.rodata);
        src/data/rooms/crateria/crateria_18.o(.rodata);
        src/data/rooms/crateria/crateria_19.o(.rodata);
        src/data/rooms/crateria/crateria_20.o(.rodata);
        src/data/rooms/crateria/crateria_21.o(.rodata);
        src/data/rooms/crateria/bg3.o(.rodata);

        src/data/tilesets/tilesets_set7.o(.rodata);

        src/data/rooms/chozodia/chozodia_0.o(.rodata);
        src/data/rooms/chozodia/chozodia_1.o(.rodata);
        src/data/rooms/chozodia/chozodia_2.o(.rodata);
        src/data/rooms/chozodia/chozodia_3.o(.rodata);
        src/data/rooms/chozodia/chozodia_4.o(.rodata);
        src/data/rooms/chozodia/chozodia_5.o(.rodata);
        src/data/rooms/chozodia/chozodia_6.o(.rodata);
        src/data/rooms/chozodia/chozodia_7.o(.rodata);
        src/data/rooms/chozodia/chozodia_8.o(.rodata);
        src/data/rooms/chozodia/chozodia_9.o(.rodata);
        src/data/rooms/chozodia/chozodia_10.o(.rodata);
        src/data/rooms/chozodia/chozodia_11.o(.rodata);
        src/data/rooms/chozodia/chozodia_12.o(.rodata);
        src/data/rooms/chozodia/chozodia_13.o(.rodata);
        src/data/rooms/chozodia/chozodia_14.o(.rodata);
        src/data/rooms/chozodia/chozodia_15.o(.rodata);
        src/data/rooms/chozodia/chozodia_16.o(.rodata);
        src/data/rooms/chozodia/chozodia_17.o(.rodata);
        src/data/rooms/chozodia/chozodia_18.o(.rodata);
        src/data/rooms/chozodia/chozodia_19.o(.rodata);
        src/data/rooms/chozodia/chozodia_20.o(.rodata);
        src/data/rooms/chozodia/chozodia_21.o(.rodata);
        src/data/rooms/chozodia/chozodia_22.o(.rodata);
        src/data/rooms/chozodia/chozodia_23.o(.rodata);
        src/data/rooms/chozodia/chozodia_24.o(.rodata);
        src/data/rooms/chozodia/chozodia_25.o(.rodata);
        src/data/rooms/chozodia/chozodia_26.o(.rodata);
        src/data/rooms/chozodia/chozodia_27.o(.rodata);
        src/data/rooms/chozodia/chozodia_28.o(.rodata);
        src/data/rooms/chozodia/chozodia_29.o(.rodata);
        src/data/rooms/chozodia/chozodia_30.o(.rodata);
        src/data/rooms/chozodia/chozodia_31.o(.rodata);
        src/data/rooms/chozodia/chozodia_32.o(.rodata);
        src/data/rooms/chozodia/chozodia_33.o(.rodata);
        src/data/rooms/chozodia/chozodia_34.o(.rodata);
        src/data/rooms/chozodia/chozodia_35.o(.rodata);
        src/data/rooms/chozodia/chozodia_36.o(.rodata);
        src/data/rooms/chozodia/chozodia_37.o(.rodata);
        src/data/rooms/chozodia/chozodia_38.o(.rodata);
        src/data/rooms/chozodia/chozodia_39.o(.rodata);
        src/data/rooms/chozodia/chozodia_40.o(.rodata);
        src/data/rooms/chozodia/chozodia_41.o(.rodata);
        src/data/rooms/chozodia/chozodia_42.o(.rodata);
        src/data/rooms/chozodia/chozodia_43.o(.rodata);
        src/data/rooms/chozodia/chozodia_44.o(.rodata);
        src/data/rooms/chozodia/chozodia_45.o(.rodata);
        src/data/rooms/chozodia/chozodia_46.o(.rodata);
        src/data/rooms/chozodia/chozodia_47.o(.rodata);
        src/data/rooms/chozodia/chozodia_48.o(.rodata);
        src/data/rooms/chozodia/chozodia_49.o(.rodata);
        src/data/rooms/chozodia/chozodia_50.o(.rodata);
        src/data/rooms/chozodia/chozodia_51.o(.rodata);
        src/data/rooms/chozodia/chozodia_52.o(.rodata);
        src/data/rooms/chozodia/chozodia_53.o(.rodata);
        src/data/rooms/chozodia/chozodia_54.o(.rodata);
        src/data/rooms/chozodia/chozodia_55.o(.rodata);
        src/data/rooms/chozodia/chozodia_56.o(.rodata);
        src/data/rooms/chozodia/chozodia_57.o(.rodata);
        src/data/rooms/chozodia/chozodia_58.o(.rodata);
        src/data/rooms/chozodia/chozodia_59.o(.rodata);
        src/data/rooms/chozodia/chozodia_60.o(.rodata);
        src/data/rooms/chozodia/chozodia_61.o(.rodata);
        src/data/rooms/chozodia/chozodia_62.o(.rodata);
        src/data/rooms/chozodia/chozodia_63.o(.rodata);
        src/data/rooms/chozodia/chozodia_64.o(.rodata);
        src/data/rooms/chozodia/chozodia_65.o(.rodata);
        src/data/rooms/chozodia/chozodia_66.o(.rodata);
        src/data/rooms/chozodia/chozodia_67.o(.rodata);
        src/data/rooms/chozodia/chozodia_68.o(.rodata);
        src/data/rooms/chozodia/chozodia_69.o(.rodata);
        src/data/rooms/chozodia/chozodia_70.o(.rodata);
        src/data/rooms/chozodia/chozodia_71.o(.rodata);
        src/data/rooms/chozodia/chozodia_72.o(.rodata);
        src/data/rooms/chozodia/chozodia_73.o(.rodata);
        src/data/rooms/chozodia/chozodia_74.o(.rodata);
        src/data/rooms/chozodia/chozodia_75.o(.rodata);
        src/data/rooms/chozodia/chozodia_76.o(.rodata);
        src/data/rooms/chozodia/chozodia_77.o(.rodata);
        src/data/rooms/chozodia/chozodia_78.o(.rodata);
        src/data/rooms/chozodia/chozodia_79.o(.rodata);
        src/data/rooms/chozodia/chozodia_80.o(.rodata);
        src/data/rooms/chozodia/chozodia_81.o(.rodata);
        src/data/rooms/chozodia/chozodia_82.o(.rodata);
        src/data/rooms/chozodia/chozodia_83.o(.rodata);
        src/data/rooms/chozodia/chozodia_84.o(.rodata);
        src/data/rooms/chozodia/chozodia_85.o(.rodata);
        src/data/rooms/chozodia/chozodia_86.o(.rodata);
        src/data/rooms/chozodia/chozodia_87.o(.rodata);
        src/data/rooms/chozodia/chozodia_88.o(.rodata);
        src/data/rooms/chozodia/chozodia_89.o(.rodata);
        src/data/rooms/chozodia/chozodia_90.o(.rodata);
        src/data/rooms/chozodia/chozodia_91.o(.rodata);
        src/data/rooms/chozodia/chozodia_92.o(.rodata);
        src/data/rooms/chozodia/chozodia_93.o(.rodata);
        src/data/rooms/chozodia/chozodia_94.o(.rodata);
        src/data/rooms/chozodia/chozodia_95.o(.rodata);
        src/data/rooms/chozodia/chozodia_96.o(.rodata);
        src/data/rooms/chozodia/chozodia_97.o(.rodata);
        src/data/rooms/chozodia/chozodia_98.o(.rodata);
        src/data/rooms/chozodia/bg3.o(.rodata);

        src/data/animated_tiles_data.o(.rodata);
        src/data/shortcut_pointers.o(.rodata);
        src/data/cable_link_data.o(.rodata);
        sTransferRom_After = .;
    } >rom

    .data : ALIGN(2) {
        src/samus.o(.data);
        src/sprite.o(.data);

        src/sprites_ai/chozo_statue.o(.data);
        src/sprites_ai/unknown_item_chozo_statue.o(.data);
        src/sprites_ai/kraid.o(.data);
        src/sprites_ai/imago_larva.o(.data);
        src/sprites_ai/imago_cocoon.o(.data);
        src/sprites_ai/ridley.o(.data);
        src/sprites_ai/atomic.o(.data);
        src/sprites_ai/mother_brain.o(.data);
        src/sprites_ai/tangle_vine.o(.data);
        src/sprites_ai/imago.o(.data);
        src/sprites_ai/crocomire.o(.data);
        src/sprites_ai/mecha_ridley.o(.data);

        src/projectile_util.o(.data);
        src/particle.o(.data);
        src/room.o(.data);
        src/scroll.o(.data);
        src/block.o(.data);
        src/color_fading.o(.data);
        src/haze.o(.data);
        src/animated_graphics.o(.data);
        src/connection.o(.data);
        src/demo.o(.data);

        src/cutscenes/cutscene_utils.o(.data);
        src/cutscenes/kraid_rising.o(.data);
        src/cutscenes/story_text_cutscene.o(.data);
        src/cutscenes/mother_brain_close_up.o(.data);
        src/cutscenes/ridley_in_space.o(.data);
        src/cutscenes/ridley_landing.o(.data);
        src/cutscenes/ridley_spawn.o(.data);
        src/cutscenes/mecha_sees_samus.o(.data);
        src/cutscenes/getting_fully_powered_suit.o(.data);
        src/cutscenes/before_ruins_test.o(.data);
        src/cutscenes/statue_opening.o(.data);
        src/cutscenes/enter_tourian.o(.data);
        src/cutscenes/samus_in_blue_ship.o(.data);

        src/menus/pause_screen.o(.data);
        src/minimap.o(.data);
        src/menus/pause_screen_map.o(.data);
        src/text.o(.data);
        src/menus/status_screen.o(.data);
        src/menus/pause_screen_sub_menus.o(.data);
        src/save_file.o(.data);

#ifdef DEBUG
        src/menus/boot_debug.o(.data);
#endif

        src/menus/erase_sram.o(.data);
        src/data/text_data.o(.data);
        src/menus/title_screen.o(.data);
        src/menus/game_over.o(.data);
        src/menus/file_select.o(.data);

        src/time_attack.o(.data);
        src/intro.o(.data);
        src/tourian_escape.o(.data);
        src/ending_and_gallery.o(.data);
        src/chozodia_escape.o(.data);
        src/cable_link.o(.data);
    } >rom

    nes_metroid_data __nes_metroid_load_address : ALIGN(2) {
        src/data/nes_metroid.o(.rodata);
    } >rom

    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */

    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }

    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }

    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }

    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
