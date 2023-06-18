#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include "types.h"

/* All of these use a 1.7.8 fixed point representation */

s16 FixedMultiplication(s16 a, s16 b);
s16 FixedDivision(s16 a, s16 b);
s16 FixedInverse(s16 a);

#endif /* FIXED_POINT_H */
