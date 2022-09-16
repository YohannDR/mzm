#ifndef TANGLE_VINE_AI_H
#define TANGLE_VINE_AI_H

#define TANGLE_VINE_GERUTA_STATUS_VINE_DEAD 0x0
#define TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD 0x1
#define TANGLE_VINE_GERUTA_STATUS_FULL 0x2

#define TANGLE_VINE_GERUTA_PART_GRIP 0x0
#define TANGLE_VINE_GERUTA_PART_GERUTA 0x1
#define TANGLE_VINE_GERUTA_PART_ROOT 0x2

extern const struct FrameData sTangleVineTallOAM_OnGround[5];
extern const struct FrameData sTangleVineMediumOAM_OnGround[5];
extern const struct FrameData sTangleVineShortOAM_OnGround[5];
extern const struct FrameData sTangleVineCurvedOAM_OnGround[7];
extern const struct FrameData sTangleVineTallOAM_OnCeiling[5];
extern const struct FrameData sTangleVineMediumOAM_OnCeiling[5];
extern const struct FrameData sTangleVineShortOAM_OnCeiling[5];
extern const struct FrameData sTangleVineCurvedOAM_OnCeiling[5];
extern const struct FrameData sTangleVineGerutaPartOAM_Grip[9];
extern const struct FrameData sTangleVineGerutaOAM_Root[9];
extern const struct FrameData sTangleVineGerutaOAM_Full[5];
extern const struct FrameData sTangleVineRedGerutaOAM[5];
extern const struct FrameData sTangleVineGerutaPartOAM_Geruta[9];
extern const struct FrameData sTangleVineLarvaRightOAM[5];
extern const struct FrameData sTangleVineLarvaLeftOAM[5];


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