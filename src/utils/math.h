#ifndef MATH_H
#define MATH_H

/* Headers */
#include <stdint.h>

/* Greatest common divisor using Euclidean algorithm */
static inline int64_t gcd(int64_t a, int64_t b)
{
    while (b != 0)
    {
        int64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Least common multiple */
static inline int64_t lcm(int64_t a, int64_t b)
{
    return a / gcd(a, b) * b;
}

/* Modular exponentiation: calculates (base^exp) % mod efficiently */
static inline int64_t mod_pow(int64_t base, int64_t exp, int64_t mod)
{
    int64_t result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

/* Modular multiplicative inverse using extended Euclidean algorithm
   Returns -1 if no inverse exists */
static inline int64_t mod_inv(int64_t a, int64_t m)
{
    int64_t t = 0, new_t = 1;
    int64_t r = m, new_r = a;

    while (new_r != 0)
    {
        int64_t quotient = r / new_r;
        int64_t tmp;

        tmp = new_t;
        new_t = t - quotient * new_t;
        t = tmp;

        tmp = new_r;
        new_r = r - quotient * new_r;
        r = tmp;
    }

    if (r > 1)
        return -1; /* inverse does not exist */
    if (t < 0)
        t += m;
    return t;
}

#endif /* MATH_H */
