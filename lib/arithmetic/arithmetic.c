#include "arithmetic.h"

int arithmetic_add_int(const int x, const int y)
{
    return x + y;
}

double arithmetic_add_double(const double x, const double y)
{
    return x + y;
}

int arithmetic_subtract_int(const int x, const int y)
{
    return x - y;
}

double arithmetic_subtract_double(const double x, const double y)
{
    return x - y;
}

int arithmetic_mult_int(const int x, const int y)
{
    return x * y;
}

double arithmetic_mult_double(const double x, const double y)
{
    return x * y;
}

int arithmetic_div_int(const int x, const int y)
{
    return y ? x / y : (x >= 0 ? INT_MAX : INT_MIN);
}

double arithmetic_div_double(const double x, const double y)
{
    return y ? x / y : (x >= 0 ? DBL_MAX : -DBL_MAX);
}