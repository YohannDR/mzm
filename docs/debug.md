# Debug Features

Even though the final release of the game doesn't include any debug features, some beta versions of the game have been leaked with debug features intact. These have been extracted and can be included by compiling with the DEBUG flag (ex: `make us_debug`). Most of the features are in two different menus: the boot debug menu and the pause debug menu. There are some additional features that can be accessed outside of these menus, usually by pressing certain button combinations.

- [Boot Debug Menu](#boot-debug-menu)
  - [Section](#section)
  - [Mode](#mode)
  - [Save](#save)
  - [Samus](#samus)
  - [Sound](#sound)
  - [Demo](#demo)
  - [Etc](#etc)
  - [Boot](#boot)
  - [Erase](#erase)
- [Pause Debug Menu](#pause-debug-menu)
- [Additional Debug Features](#additional-debug-features)
  - [Title Screen](#title-screen)
  - [File Select](#file-select)
  - [No-clip Mode](#no-clip-mode)
  - [Pause Screen](#pause-screen)


## Boot Debug Menu

The boot debug menu consists of various sub-menus for changing settings or testing parts of the game. You can access the boot debug menu from the intro or title screen by pressing `R`. You can also return to the title screen by pressing `R`. Pressing `Start` will start the game in the area selected in the Section menu.

### Section

Pressing `A` on any of the areas will start you in the first room of that area. These are the area names:
- ブリンスタ - Brinstar
- クレイド - Kraid
- ノルフェア - Norfair
- リドリー - Ridley
- ツーリアン - Tourian
- クレテリア - Crateria
- ナンパセン - wrecked ship (Chozodia)

You can also go to the title, or load any save files with data.

If you press `Select` with an area selected, an interactive map will be displayed where you can choose the room or door to spawn at ("h" is short for 部屋 - *heya* - "room", "g" is short for "gate").

### Mode

You can change the language and difficulty from this menu. These settings only apply if you load straight into the game from the debug menu.

### Save

This menu affects items in the file select's options menu. "POSTER" refers to the gallery images, which you can toggle unlocked or locked. "ClearLevel" refers to which difficulties should be considered as having been completed. All difficulties unlock original Metroid, and hard mode unlocks sound test. Setting "Fusion" to "yes" will unlock the Metroid Fusion gallery. "ID" displays the time attack record ID if you've completed a time attack run.

If you change any of the options, they will only take effect if you select "SAVE".

### Samus

"GetMap" lets you set which area maps are downloaded. The areas are in reverse order (first is Chozodia, last is Brinstar). Pressing `L` clears all values, pressing `R` sets all values, and pressing `A` toggles a value.

"H-SHOT" and "ナナメ-SHOT" refer to the button assignments for arming missiles and diagonal aim ("H" likely refers to 発射 - *hassha* - "firing (a missile)", "ナナメ" means "diagonal"). You can press `L` or `R` to set that button, or `A` to swap the buttons.

"PAUSE" and "ミサイル" refer to the button assignments for the pause screen and swapping missiles ("ミサイル" means "missile"). You can press `Start` or `Select` to set that button, or `A` to swap the buttons.

### Sound

"BGM" lets you enable or disable background music during gameplay. "モノラル" and "ステレオ" refer to mono and stereo sound respectively. This is the same as the sound option on the file select screen. "TEST" lets you play all music and sounds in the game. Pressing `A` or `R` plays a sound, and pressing `L` stops a sound. Some sounds play indefinitely and can only be stopped with `L`. Not all numbers have a sound associated with them.

### Demo

This menu is for testing cutscenes and demos. The devs use "demo" to refer to cutscenes, and "auto demo" to refer to title screen demos.

"DEMO SW" likely means "demo switch", and seems to be an unused setting that would have disabled cutscenes. The following two options let you preview all the cutscenes in the game. While playing cutscenes, pressing `A` skips to the next part of the cutscene, pressing `Start` restarts the cutscene, and pressing `B` returns to the debug menu. "DEMO(A)" only has a single cutscene, while all others are part of "DEMO(B)". These are the cutscene names:
- ゲキツイ - Shooting down
- MONO スタート - Monologue start
- MONO ゲキツイ 1 - Monologue shooting down 1
- MONO ゲキツイ 2 - Monologue shooting down 2
- マザー ブレイン - Mother Brain
- クレイド - Kraid
- セキゾウ - Stone statue
- ヒキカエス ボカン - Returning mother ship
- チャクリク - Landing
- リドリー - Ridley
- メトロイド - Metroid
- ヘキガ - Mural
- パワードスーツ - Powered suit
- メカ リドリー - Mecha Ridley
- コガタテイ - Small ship

If you hold `L` while starting the Kraid or Ridley fight cutscene, Samus will have the Varia suit.

"オートデモMODE" and "オートデモNUM" are "auto demo mode" and "auto demo number". For the demo mode, "Free" puts you at the start of the demo and lets you move freely. "GetKey" will record your inputs (until you press `Start`) and save them to RAM. "RAMRUN" will play a demo recorded to RAM if you have recorded one. "ROMRUN" will play the demo that is already on the ROM (same as the demos in the final release). The demo number lets you change which demo to play or record.

### Etc

"Ending" will play the ending cutscene, starting from when you escape on the blue ship. "STAFF ROLL" will play the credits.

Turning "Main-End OBJ" on will display sprites at the edge of the screen related to VCOUNT while in-game (the name likely means "objects (sprites) displayed at the end of the main code loop"). The left side indicates the VCOUNT value at the end of the frame (essentially how many cycles the frame took). The closer it is to the bottom of the screen, the closer the game is to generating a lag frame. The right side indicates the difference in VCOUNT before and after the audio code runs (essentially how many cycles the audio code took), along with the max value it has reached in the current room.

"ゲート コウカ" is "gate effect". Turning this off will make all door transitions instant.

### Boot

Pressing `A` on this menu will attempt to connect with Metroid Fusion via the link cable. This is the same as "Metroid Fusion Link" from the file select's options menu, but with additional status and error messages.

### Erase

This menu lets you erase all SRAM, which does the same thing as the menu you get when you hold `L` + `R` while booting the game.


## Pause Debug Menu

TODO


## Additional Debug Features

### Title Screen

While on the title screen, pressing `L` will start playing demos. Pressing `Select` will hide the build info text. Holding `Select` and pressing `Left` or `Right` will switch between displaying the trademark symbol (™) and registered trademark symbol (®).

### File Select

While the cursor is on an existing save file, you can hold `Select` and press `L`, `Right`, or `Left` to mark the file as completed. Pressing `L` will treat it as being completed on easy mode, `Right` is normal mode, and `Left` is hard mode.

If you have the Metroid Fusion gallery unlocked, holding `L` while selecting the gallery will force an attempt to link with Metroid Fusion.

### No-clip Mode

While in-game, holding `L` + `B` and pressing `Start` will enable no-clip mode. In this mode, you can freely move around a room without interacting with collision. Holding `L` or `R` will let you move twice as fast. Pressing `Select` will switch the camera to be unaffected by scrolls and room boundaries. Pressing `Start` will turn off no-clip mode.

### Pause Screen

While in-game, holding `Select` while pressing `Start` will load the pause screen without the debug menu. This lets you view the normal status screen.

Holding `L` + `Select` while pressing `Start` will download the map for the current area.
