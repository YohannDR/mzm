# Sprites

A sprite refers broadly to entities during gameplay that aren't one of the following :
- Samus
- Samus projectiles
- Sprite debris
- Particles

They mostly consist of enemies, gimmicks or triggers placed in a room.\
Their AI can be found in the `sprites_AI` folders, both in `include` and `src`, with their data being in `include/data/sprites` and `src/data/sprites`.

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
| **samusCollision** | Samus collision type | `u8` | Determines how the collision between the sprite and Samus should behave.
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
| SPRITE_STATUS_XFLIP | 1 << 6 | Whether the sprite is X-flipped when drawn.
| SPRITE_STATUS_UNKNOWN_80 | 1 << 7 | Unknown purpose, related to obj affine.
| SPRITE_STATUS_YFLIP | 1 << 8 | Whether the sprite is Y-flipped when drawn.
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

**TODO**
