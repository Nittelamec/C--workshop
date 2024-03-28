#pragma once

#include "is_prime.hh"

constexpr bool is_prime(unsigned n)
{
    if (n == 1)
        return false;
    for (unsigned i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
