#ifndef TANGLE_VINE_AI_H
#define TANGLE_VINE_AI_H

#define TANGLE_VINE_GERUTA_STATUS_VINE_DEAD 0x0
#define TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD 0x1
#define TANGLE_VINE_GERUTA_STATUS_FULL 0x2

#define TANGLE_VINE_GERUTA_PART_GRIP 0x0
#define TANGLE_VINE_GERUTA_PART_GERUTA 0x1
#define TANGLE_VINE_GERUTA_PART_ROOT 0x2

void TangleVineSyncSprites(void);
void TangleVineGeruta(void);
void TangleVineGerutaPart(void);
void TangleVineRedGeruta(void);
void TangleVineLarvaRight(void);
void TangleVineLarvaLeft(void);
void TangleVineTall(void);
void TangleVineMedium(void);
void TangleVineCurved(void);
void TangleVineShort(void);

#endif /* TANGLE_VINE_AI_H */