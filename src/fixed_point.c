#include "fixed_point.h"

/**
 * @brief a4c | 1c | Fixed point multiplication
 * 
 * @param a A
 * @param b B
 * @return s16 Result
 */
s16 FixedMultiplication(s16 a, s16 b)
{
    s32 x = a;
    s32 y = b;
    s32 res = x;
    res *= y;
    res /= 0x100;
    return res;
}

/**
 * @brief a68 | 18 | Fixed point division
 * 
 * @param a A
 * @param b B
 * @return s16 Result
 */
s16 FixedDivision(s16 a, s16 b)
{
    s32 x = a;
    s32 y = b;

    return (x << 8) / y;
}

/**
 * @brief a80 | 18 | Fixed point inversion
 * 
 * @param a A
 * @return s16 Result
 */
s16 FixedInverse(s16 a)
{
    return 0x10000 / a;
}
