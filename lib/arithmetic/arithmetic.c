#include "arithmetic.h"

#include <stdio.h>

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

int arithmetic_max_int(const int x, const int y)
{
    return x > y ? x : y;
}

double arithmetic_max_double(const double x, const double y)
{
    return x > y ? x : y;
}

int arithmetic_min_int(const int x, const int y)
{
    return x < y ? x : y;
}

double arithmetic_min_double(const double x, const double y)
{
    return x < y ? x : y;
}

int arithmetic_average_int(const int x, const int y)
{
    return (x + y) / 2;
}

double arithmetic_average_double(const double x, const double y)
{
    return 0.5 * (x + y);
}

int arithmetic_average_int_arr(const int *x, const int n_arr)
{
    int average = 0;

    for (int i = 0; i < n_arr; ++i)
    {
        average += x[i];
    }

    if (average > 0)
    {
        return average % n_arr > n_arr / 2 ? average / n_arr + 1 : average / n_arr;
    }
    else
    {
        return -(-average % n_arr > n_arr / 2 ? -average / n_arr + 1 : -average / n_arr);
    }

    //return average % n_arr > n_arr / 2 ? average / n_arr + 1 : average / n_arr;
}