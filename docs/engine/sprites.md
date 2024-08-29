# Sprites

A sprite refers broadly to entities during gameplay that aren't one of the following :
- Samus
- Samus projectiles
- Sprite debris
- Particles

They mostly consist of enemies, gimmicks or triggers placed in a room.\
Their AI can be found in the `sprites_AI` folders, both in `include` and `src`, with their data being in `include/data/sprites` and `src/data/sprites`.

- [Sprites](#sprites)
  - [Sprite data](#sprite-data)
  - [Status](#status)
  - [Properties](#properties)
  - [Poses](#poses)
  - [Samus collision](#samus-collision)
- [Difference between primary and secondary sprites](#difference-between-primary-and-secondary-sprites)
- [Creating a new sprite](#creating-a-new-sprite)
- [Spawning a new sprite](#spawning-a-new-sprite)


## Sprite data

`SpriteData` is a struct that contains everything needed for a sprite to work, it is located in [include/structs/sprite.h](../../include/structs/sprite.h#L42).

Here's a detailed explanation of each field :\
Note :
- A **bolded** field name indicates that it's used internally by the engine.
- An *italic* field name indicates that its usage may vary between sprite AI.

| Name    | Full name   | Type | Explanation |
|---------|-------------|------|-------------|
| **status** | Status | `u16` | A collection of bit flags that affect the behavior of sprite, or provide information on its current state. For more detail on each flag, view the [sprite status](#status) section.
| **yPosition** | Y Position | `u16` | Current Y position of the sprite.
| **xPosition** | X Position | `u16` | Current X position of the sprite.
| *yPositionSpawn* | Y Position Spawn | `u16` | The Y position of the sprite when it spawned.
| *xPositionSpawn* | X Position Spawn | `u16` | The X position of the sprite when it spawned.
| **hitboxTop** | Hitbox top offset | `s16` | How far from the Y position the hitbox extends upwards.
| **hitboxBottom** | Hitbox bottom offset | `s16` | How far from the Y position the hitbox extends downwards.
| **hitboxLeft** | Hitbox left offset | `s16` | How far from the X position the hitbox extends left.
| **hitboxRight** | Hitbox right offset | `s16` | How far from the X position the hitbox extends right.
| **scaling** | Oam scaling | `u16` | Oam scaling, uses Q8.8 fixed point format. Only used by the engine if scaling is enabled in any way, otherwise unused.
| **health** | Health | `u16` | Current health of the sprite.
| **currentAnimationFrame** | Current animation frame | `u16` | Current animation frame.
| **pOam** | Frame data pointer | `const struct FrameData*` | Pointer to the current animation.
| **animationDurationCounter** | Animation duration counter | `u8` | How long the current animation frame has been on.
| **spriteId** | Sprite ID | `u8` | Identifies which sprite this sprite data is, primary and secondary sprites use different enums.
| **roomSlot** | Room slot/part number | `u8` | If the sprite is one that spawns with the room, then this field contains the slot in which the sprite was (depends on the placement order). Otherwise it contains the part number, which is used to have the same sprite behave differently (boss parts, different movement patterns...).
| **spritesetGfxSlot** | Spriteset graphics slot | `u8` | On which graphics row the sprite graphics and palette begin.
| **paletteRow** | Palette row | `u8` | Which palette row should be used to draw the sprite.
| **bgPriority** | Background priority | `u8` | Determines the [hardware background priority](https://problemkaputt.de/gbatek.htm#lcdobjoamattributes).
| **drawOrder** | Draw order | `u8` | Determines the draw order between sprites, the minimum value is 1 and the maximum is 16. There also seems to be 2 groups (1 to 8 and 9 to 16), however it's unknown how that affects draw order.
| **primarySpriteRamSlot** | Primary sprite ram/array slot | `u8` | If the sprite is a primary sprite, then this field contains it's index in the global sprite table. If it's a secondary sprite, then it should contains the index in the global sprite table of the parent primary sprite.
| **pose** | Pose/behavior | `u8` | What behavior the sprite is currently on, some values have [special meaning](#poses), otherwise most are free.
| **samusCollision** | Samus collision type | `u8` | Determines how the collision between the sprite and Samus should behave, more details in the [Samus/sprite collision](#samus-collision) section.
| **ignoreSamusCollisionTimer** | Ignore samus collision timer | `u8` | Decrementing timer that makes the sprite ignore collision with Samus.
| **drawDistanceTop** | Draw distance top offset | `u8` | In pixels, how far the sprite extends visually upwards, used to determine whether it's on screen or not.
| **drawDistanceBottom** | Draw distance bottom offset | `u8` | In pixels, how far the sprite extends visually downwards, used to determine whether it's on screen or not.
| **drawDistanceHorizontal** | Draw distance horizontal offset | `u8` | In pixels, how far the sprite extends visually sidewards, used to determine whether it's on screen or not.
| **rotation** | Oam rotation | `u8` | Oam rotation, uses Q8.8 fixed point format (only the decimal part matters). Only used by the engine if rotation is enabled in any way, otherwise unused.
| **invincibilityStunFlashTimer** | Invincibility/stun/flash timer | `u8` | Invincibility/stun/flash timer for the sprite, special values can also be used to determine if the sprite was hit and was immune.
| ***work0*** | Work variable 0 | `u8` | Free slot variable, used by some generic sprite util functions (the movement ones), otherwise free to use.
| ***work1*** | Work variable 1 | `u8` | Free slot variable, used by some generic sprite util functions (the movement ones), otherwise free to use.
| ***work2*** | Work variable 2 | `u8` | Free slot variable, used by some generic sprite util functions (the movement ones), otherwise free to use.
| ***work3*** | Work variable 3 | `u8` | Free slot variable, used by some generic sprite util functions (the movement ones), otherwise free to use.
| **freezeTimer** | Freeze timer | `u8` | Timer for how long the sprite is freezed, it isn't automatically updated by the engine, sprite util functions need to be called by the AI.
| **standingOnSprite** | Samus standing on sprite status | `u8` | Whether samus is standing on the sprite or not.
| **properties** | Property flags | `u8` | A collection of bit flags that affect the behavior of sprite, or provide information on its current state. For more detail on each flag, view the [sprite properties](#properties) section.
| **frozenPaletteRowOffset** | Frozen/stunned palette row offset | `u8` | How much palette row to offset to determine the new row to use when the sprite is frozen/stunned.
| **absolutePaletteRow** | Absolute palette row | `u8` | Backup palette row to use when flickering during stun or freeze.

## Status

| Name    | Value | Explanation |
|---------|-------|-------------|
| SPRITE_STATUS_EXISTS | 1 << 0 | Whether the sprite exists or not.
| SPRITE_STATUS_ONSCREEN | 1 << 1 | Whether the sprite is currently visible on screen.
| SPRITE_STATUS_NOT_DRAWN | 1 << 2 | Whether the sprite should be drawn.
| SPRITE_STATUS_ROTATION_SCALING | 1 << 3 | Enables affine transformation when drawing the sprite.
| SPRITE_STATUS_UNKNOWN_10 | 1 << 4 | Unknown purpose, related to draw order.
| SPRITE_STATUS_MOSAIC | 1 << 5 | Whether mosaic is enabled, left over from fusion, doesn't seem to work properly.
| SPRITE_STATUS_X_FLIP | 1 << 6 | Whether the sprite is X-flipped when drawn.
| SPRITE_STATUS_UNKNOWN_80 | 1 << 7 | Unknown purpose, related to obj affine.
| SPRITE_STATUS_Y_FLIP | 1 << 8 | Whether the sprite is Y-flipped when drawn.
| SPRITE_STATUS_FACING_RIGHT | 1 << 9 | Whether the sprite is facing right, purely informative and only used in the engine in the movement functions.
| SPRITE_STATUS_FACING_DOWN | 1 << 10 | Whether the sprite is facing down, purely informative and only used in the engine in the movement functions.
| SPRITE_STATUS_SAMUS_COLLIDING | 1 << 11 | Whether the sprite is colliding with Samus, only used on some [sprite/samus collision](#samus-collision).
| SPRITE_STATUS_SAMUS_ON_TOP | 1 << 12 | Whether Samus is on top of the sprite.
| SPRITE_STATUS_ALPHA_BLENDING | 1 << 13 | Whether the sprite is flagged [semi transparent](https://problemkaputt.de/gbatek.htm#lcdobjoverview).
| SPRITE_STATUS_DOUBLE_SIZE | 1 << 14 | Whether the sprite is flagged [double size](https://problemkaputt.de/gbatek.htm#lcdobjoverview) is affine mode is enabled.
| SPRITE_STATUS_IGNORE_PROJECTILES | 1 << 15 | Whether the sprite ignores projectile collision.

## Properties

| Name    | Value | Explanation |
|---------|-------|-------------|
| SP_ALWAYS_ACTIVE | 1 << 0 | Whether the sprite is active even during periods when sprites aren't updated.
| SP_DAMAGED | 1 << 1 | Whether the sprite was damaged.
| SP_KILL_OFF_SCREEN | 1 << 2 | Whether the sprite should be destroyed if it reaches far enough off-screen.
| SP_SOLID_FOR_PROJECTILES | 1 << 3 | Whether the sprite is solid for projectiles.
| SP_DESTROYED | 1 << 4 | Whether the sprite is destroyed.
| SP_ABSOLUTE_POSITION | 1 << 5 | Whether the position of the sprite should ignore scrolling and be considered direct screen space coordinates.
| SP_IMMUNE_TO_PROJECTILES | 1 << 6 | Whether the sprite is immune to projectiles.
| SP_SECONDARY_SPRITE | 1 << 7 | Whether the sprite is a secondary sprite.

## Poses

Most of the pose values are free to use, however there are a few that have a particular meaning :

| Name    | Value | Explanation |
|---------|-------|-------------|
| SPRITE_POSE_UNINITIALIZED | 0 | The sprite was just created and hasn't been initialized yet.
| SPRITE_POSE_STOPPED | 0x42 | The sprite has come into contact with Samus and has a "XXX when hit" samus/sprite collision type.
| SPRITE_POSE_DESTROYED | 0x62 | The sprite has reached 0 health.
| SPRITE_POSE_SHINESPARK_DESTROYED | 0x63 | The sprite was killed with a shinespark.
| SPRITE_POSE_SPEEDBOOSTER_DESTROYED | 0x64 | The sprite was killed with speedbooster.
| SPRITE_POSE_SCREW_ATTACK_DESTROYED | 0x65 | The sprite was killed with screw attack.
| SPRITE_POSE_SUDO_SCREW_DESTROYED | 0x66 | The sprite was killed with sudo screw.

## Samus collision

| Name    | Value | Explanation |
|---------|-------|-------------|
| SSC_NONE | 0 | No collision.
| SSC_SOLID | 1 | Solid collision.
| SSC_CAN_STAND_ON_TOP | 2 | No collision, can stand on top.
| SSC_HURTS_SAMUS_CAN_STAND_ON_TOP | 3 | Hurts, except can stand on top.
| SSC_HURTS_SAMUS | 4 | Hurts.
| SSC_HURTS_SAMUS_A_LOT | 5 | Hurts, 5x damage multiplier and slightly more knockback.
| SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT | 6 | Hurts, sprite is set to the SPRITE_POSE_STOPPED pose.
| SSC_KNOCKS_BACK_SAMUS | 7 | Knocks back.
| SSC_8 | 8 | No collision, unused.
| SSC_HURTS_SAMUS_NO_KNOCKBACK | 9 | Hurts, no knockback.
| SSC_HURTS_KNOCKBACK_IF_INVINCIBLE | 10 | Hurts. If invincible, solid and knocks back.
| SSC_HURTS_SAMUS_SOLID | 11 | Hurts, solid.
| SSC_SOLID_SIDEWAYS | 12 | Solid from the side, pushes back from the top and bottom.
| SSC_HURTS_BIG_KNOCKBACK | 13 | Hurts, big knockback.
| SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_BIG_KNOCKBACK | 14 | Hurts, big knockback, sprite is set to the SPRITE_POSE_STOPPED pose.
| SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY | 15 | Hurts, ignore Samus' invincibility.
| SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK | 16 | Hurts, no knockback, sprite is set to the SPRITE_POSE_STOPPED pose.
| SSC_HURTS_SAMUS_NO_KNOCKBACK_NO_CONTACT_DAMAGE | 17 | Hurts, no knockback, contact damage from Samus isn't registered.
| SSC_MELLOW | 18 | Same as SSC_HURTS, simply used as a mellow identifier.
| SSC_SPACE_PIRATE_LASER | 19 | Same as SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT, simply used as a space pirate laster identifier.
| SSC_SPACE_PIRATE | 20 | Same as SSC_HURTS, simply used as a space pirate identifier.
| SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY_NO_CONTACT_DAMAGE | 21 | Hurts, ignore Samus' invincibility, contact damage from Samus isn't registered.
| SSC_ACID_WORM_MOUTH | 22 | Special collision that takes into account rotation and poses, only used by the acid worm mouth.
| SSC_PARASITE | 23 | Special collision used by parasites.
| SSC_METROID | 24 | Special collision used by metroids.
| SSC_HURTS_RIGHT_CAN_STAND_ON_TOP | 25 | Can stand on top, hurts from the right.
| SSC_ZIPLINE | 26 | Special collision used by ziplines.
| SSC_SOLID_CHECK_COLLIDING | 27 | Solid, sets the SPRITE_STATUS_SAMUS_COLLIDING flag.
| SSC_RIDLEY_CLAW | 28 | Special collision used by ridley's claw.
| SSC_MECHA_RIDLEY | 29 | Special collision used by mecha ridley.
| SSC_CHECK_COLLIDING | 30 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag.
| SSC_SMALL_ENERGY_DROP | 31 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by small energy drop only.
| SSC_LARGE_ENERGY_DROP | 32 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by large energy drop only.
| SSC_MISSILE_DROP | 33 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by missile drop only.
| SSC_SUPER_MISSILE_DROP | 34 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by super missile drop only.
| SSC_POWER_BOMB_DROP | 35 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by power bomb drop only.
| SSC_MULTIPLE_LARGE_ENERGY_DROP | 36 | Only sets the SPRITE_STATUS_SAMUS_COLLIDING flag, used by multiple large energy drop only.

# Difference between primary and secondary sprites

Primary and secondary sprites work mostly the same, however there are a few differences :

- Secondary sprites can only be spawned at runtime, they can't be placed in a room.
- Secondary sprites don't have dedicated graphics, they have to "borrow" it from their parent primary sprite.
- They use a different set of sprite id, meaning they also use a different set of AIs.

The main purpose of the secondary sprites is to complement a primary sprite, they mostly consist of either enemy projectiles, or parts to form a bigger sprite.

# Creating a new sprite

In order to create a new sprite, 3 components are necessary :

- A main AI, which should be have a signature like this : `void MySprite(void)`
- Graphics, LZ77 compressed.
- Palette, raw 16-bit gba colors.

It's also necessary to create a sprite id, simply adding an entry to the already existing enum ([PrimarySprite](../../include/constants/sprite.h#L30) or [SecondaySprite](../../include/constants/sprite.h#L241)) works, though there is an upper limit of 255 due to sprite id being stored in an `u8`.

Once created, the 3 components simply need to be added to their respective arrays, namely :

- [sPrimarySpritesAIPointers](../../src/data/samus_sprites_pointers.c#237) or [sSecondarySpritesAIPointers](../../src/data/samus_sprites_pointers.c#832)
- [sSpritesGraphicsPointers](../../src/data/samus_sprites_pointers.c#446)
- [sSpritesPalettePointers](../../src/data/samus_sprites_pointers.c#639)

# Spawning a new sprite

There are 3 functions used to spawn sprites at runtime, they are declared in `sprite.h` :

- `SpriteSpawnPrimary` : Spawns a primary sprite with the given parameters.
- `SpriteSpawnSecondary` : Spawns a secondary sprite with the given parameters.
- `SpriteSpawnDropFollowers` : Spawns a primary sprite with the given parameters.

The parameters for each functions are detailed in their headers.
Each function returns the slot in the global sprite array, or 0xFF if the array is already full.
