#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include "types.h"

// All of these use a 1.7.8 fixed point representation

i16 fix_mul(i16 a, i16 b);
i16 fix_div(i16 a, i16 b);
i16 fix_inverse(i16 a);

#endif /* FIXED_POINT_H */
