#include <stdlib.h>
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

    return (average + (average > 0 ? n_arr : -n_arr) / 2) / n_arr;
}

void arithmetic_sort_ascending(int *x, const int n_arr)
{
    (void)quicksort(x, n_arr, compare_asc);
}

void arithmetic_sort_descending(int *x, const int n_arr)
{
    (void)quicksort(x, n_arr, compare_desc);
}

////////////////////////////////////////////////////////////////
void swap_int(int *pnt1, int *pnt2)
{
    int tmp = *pnt2;
    *pnt2 = *pnt1;
    *pnt1 = tmp;
}

bool compare_asc(int a, int b)
{
    return a <= b;
}

bool compare_desc(int a, int b)
{
    return a >= b;
}

int qs_split(int *arr, const int lo, const int hi, compare_t compare)
{
    while (1)
    {
        int pivot_val = *(arr + lo);
        int i = lo + 1;
        int j = hi;

        while (i <= j && compare(*(arr + i), pivot_val)) //less_or_eq(*(arr + i), pivot_val))
        {
            ++i;
        }
        while (j > i && compare(pivot_val, *(arr + j))) //greater_or_eq(*(arr + j), pivot_val))
        {
            --j;
        }
        if (i < j) // exchange of 2 elements
        {
            (void)swap_int(arr + i, arr + j);
        }
        else // setting the pivot (cxchange with the mid. elem.) & return
        {
            *(arr + lo) = *(arr + i - 1);
            *(arr + i - 1) = pivot_val;
            return i - 1; // new position of the pivot
        }
    }
}

int push_pop(int push_not_pop, int *p_lo, int *p_hi, const int set_empty)
{
    static range stack[STACK_SIZE];
    static int lvl = 0;

    if (set_empty)
    {
        lvl = 0;
    }
    else if (!(p_lo && p_hi))
    {
    }
    else if (push_not_pop)
    {
        *(stack + lvl++) = (range){*p_lo, *p_hi};
    }
    else
    {
        *p_lo = (*(stack + --lvl)).lo;
        *p_hi = (*(stack + lvl)).hi;
    }

    return lvl;
}

int quicksort(int *arr, const int n, compare_t compare)
{
    int lo = 0, hi = n - 1, pivot, xx;

    int lvl_max = 0; // max. stack level reached in the stack function: push_pop();
    int lvl;         // needed only for calc. of lvl_max

    while (1)
    {
        while (hi > lo)
        {
            pivot = qs_split(arr, lo, hi, compare);
            if ((pivot - lo) <= (hi - pivot))
            { // shorter LEFT part (to the left from pivot) is chosen, longer RIGHT part is PUSHed to STACK
                xx = pivot + 1;
                (void)push_pop(PUSH, &xx, &hi, KEEP_STACK);
                hi = pivot - 1;
            }
            else
            { // shorter RIGHT part (to the right from pivot) is chosen, longer LEFT part is PUSHed to STACK
                xx = pivot - 1;
                (void)push_pop(PUSH, &lo, &xx, KEEP_STACK);
                lo = pivot + 1;
            }
        }
        if ((lvl = push_pop(POP, &lo, &hi, KEEP_STACK)) < 0)
        {
            (void)push_pop(PUSH, NULL, NULL, EMPTY_STACK); // - to prepare stack for next function call
            return lvl_max + 1;                            // (considering that there was one more level occupied before the POP)
        }

        if (lvl > lvl_max)
        {
            lvl_max = lvl;
        }
    }
}
