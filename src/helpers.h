#ifndef _HELPERS_H__
#define _HELPERS_H__

#include <stdbool.h>

/**
 * @brief Compares 2 double precision floating points numbers. Note that this
 *        function only compares teh first 5 digits.
 *
 * @param a The first number.
 * @param b The second number.
 *
 * @return `true` if `a` is equal to `b` and `false` otherwise.
 */
bool isEqual(double a, double b);

#endif // _HELPERS_H__
