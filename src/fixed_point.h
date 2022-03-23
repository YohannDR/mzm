#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include "types.h"

// All of these use a 1.7.8 fixed point representation

i16 multiply_decimal(i16 a, i16 b);
i16 div_signed_multiply_unused(i16 a, i16 b);
i16 div_10000_by(i16 a);

#endif /* FIXED_POINT_H */
