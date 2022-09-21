#include "fixed_point.h"

/**
 * @brief a4c | 1c | Fixed point multiplication
 * 
 * @param a A
 * @param b B
 * @return i16 Result
 */
i16 FixedMultiplication(i16 a, i16 b)
{
    i32 x = a;
    i32 y = b;
    i32 res = x;
    res *= y;
    res /= 0x100;
    return res;
}

/**
 * @brief a68 | 18 | Fixed point division
 * 
 * @param a A
 * @param b B
 * @return i16 Result
 */
i16 FixedDivision(i16 a, i16 b)
{
    i32 x = a;
    i32 y = b;

    return (x << 8) / y;
}

/**
 * @brief a80 | 18 | Fixed point inversion
 * 
 * @param a A
 * @return i16 Result
 */
i16 FixedInverse(i16 a)
{
    return 0x10000 / a;
}
