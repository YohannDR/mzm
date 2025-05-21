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
  - [Equipment](#equipment)
  - [Miscellaneous](#miscellaneous)
  - [Event List](#event-list)
- [Additional Debug Features](#additional-debug-features)
  - [Title Screen](#title-screen)
  - [File Select](#file-select)
  - [No-clip Mode](#no-clip-mode)


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
- MONOゲキツイ1 - Monologue shooting down 1
- MONOゲキツイ2 - Monologue shooting down 2
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

The pause debug menu lets you change Samus's equipment, triggered events, and a few other options. You can access the pause debug menu from the status screen while the game is paused. The game must be launched from the boot debug menu, otherwise the pause debug menu won't be enabled. Holding `Select` while loading the status screen will load the normal status screen. Similary, holding `Select` while pausing will disable the debug menu until you pause again. Holding `L` + `Select` while pausing will download the map for the current area.

The top of the debug status screen shows the current area, room ID ("HEYA"), and door ID ("GATE"). Pressing `Select` on this screen will load the [event list](#event-list).

### Equipment

Abilities can be toggled on or off. Selecting the left side of the item will give you the ability, while selecting anything to the right will activate the ability. "KADO" is power grip (角 - "corner" or "edge"). Under the "STATUS" section, you can change whether Samus's suit type is normal, fully powered, or suitless ("NAKED"). Changing the suit type will automatically update the activated abilities.

"SEVENT" is an unused leftover from the Fusion debug menu.

Selecting "EQUIP" and pressing `L` or `Select` will remove all abilities. Pressing `R` or `Start` will set all abilities and activate them based on the suit type. Selecting "TANK" and pressing `L` or `Select` will set all energy and ammo to their starting values. Pressing `R` or `Start` will set them all to their maximum values based on the current difficulty.

### Miscellaneous

"GET_MAP" lets you toggle area maps as downloaded. The test area maps cannot be toggled.

Selecting "SAVE" will immediately save the game. Reloading the file will skip the normal loading animation.

The four dashes below "SAVE" will display "SHUT" if the doors are locked. Selecting it will change the text to "OPEN" and unlock the doors.

"TIME" displays the current in-game timer as hours, minutes, and seconds. These can be changed to any value between 00:00:00 and 99:59:59.

"LANG" displays the current language and the game's region. The JP and US ROMs only contain Japanese and English, so changing the language to anything else won't actually change the language.

"LEVEL" displays the difficulty, which you can change to easy, normal, or hard.

Pressing `A` on the very top-right corner of the screen will display a "z" and play the Game Boy boot sound. This actually saves the RAM that demos use, but there's no in-game way to use this RAM.

### Event List

Pressing `Select` while on the debug status screen will bring up the event list, where you can toggle any event in the game on or off. Pressing `Left` or `Right` will move the cursor up or down by 10. When testing event changes, you may need to reload the room to see any differences.

The event names in this list can be difficult to figure out without knowing Japanese. You can look at the [Event enum](../include/constants/event.h) for some names that are easier to understand.


## Additional Debug Features

### Title Screen

While on the title screen, pressing `L` will start playing demos. Pressing `Select` will hide the build info text. Holding `Select` and pressing `Left` or `Right` will switch between displaying the trademark symbol (™) and registered trademark symbol (®).

### File Select

While the cursor is on an existing save file, you can hold `Select` and press `L`, `Right`, or `Left` to mark the file as completed. Pressing `L` will treat it as being completed on easy mode, `Right` is normal mode, and `Left` is hard mode.

If you have the Metroid Fusion gallery unlocked, holding `L` while selecting the gallery will force an attempt to link with Metroid Fusion.

### No-clip Mode

While in-game, holding `L` + `B` and pressing `Start` will enable no-clip mode. In this mode, you can freely move around a room without interacting with collision. Holding `L` or `R` will let you move twice as fast. Pressing `Select` will switch the camera to be unaffected by scrolls and room boundaries. Pressing `Start` will turn off no-clip mode.
