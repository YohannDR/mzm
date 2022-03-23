#include "fixed_point.h"

i16
fix_mul(i16 a, i16 b)
{
    i32 x   = a;
    i32 y   = b;
    i32 res = x;
    res *= y;
    res /= 0x100;
    return res;
}

i16
fix_div(i16 a, i16 b)
{
    i32 x = a;
    i32 y = b;

    return (x << 8) / y;
}

i16
fix_inverse(i16 a)
{
    return 0x10000 / a;
}
