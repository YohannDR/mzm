#include "fixed_point.h"

i16
fix_mul(i16 a, i16 b)
{
    i32 res;

    // XXX: super ugly sign extension
    i32 a32 = a << 0x10;
    i32 b32 = b;
    a32 >>= 0x10;

    res = a32 * b32;
    res /= 0x100;
    return res;
}

i16
fix_div(i16 a, i16 b)
{
    // XXX: super ugly sign extension
    i32 a32 = a << 0x10;
    i32 b32 = b;
    a32 >>= 8;

    return a32 / b32;
}

i16
fix_inverse(i16 a)
{
    return 0x10000 / a;
}
