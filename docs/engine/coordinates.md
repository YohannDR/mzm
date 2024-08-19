# Coordinates system

The game uses a coordinates system that has 3 units, sub-pixel, pixel and block.
The following table describes the convertion between them :

| Sub pixel    | Pixel     | Block      |
|--------------|-----------|------------|
| 1            | 0.25      | 0.015625   |
| 4            | 1         | 0.0625     |
| 64           | 16        | 1          |

Conversions can be made between each unit with simple multiplication and division, however there are macros defined in [macros.h](../../include/macros.h#L165) that can be used to do the conversions.

Most of the coordinates used in the game are in sub-pixel units (position, hitboxes).
There are a few coordinates that are in block units (doors, hatches).
Only one uses pixel unit (sprite draw distances).

All coordinates use the same position for 0;0, which is the top left of the current context (room, cutscene...).
