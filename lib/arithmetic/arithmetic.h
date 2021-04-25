#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <float.h>
#include <limits.h>
#include <stdbool.h>

#define PUSH 1
#define POP 0
#define STACK_SIZE 10
#define EMPTY_STACK 1
#define KEEP_STACK 0

typedef struct
{
    int lo;
    int hi;
} range;

typedef bool (*compare_t)(int, int);

int arithmetic_add_int(const int x, const int y);

double arithmetic_add_double(const double x, const double y);

int arithmetic_subtract_int(const int x, const int y);

double arithmetic_subtract_double(const double x, const double y);

int arithmetic_mult_int(const int x, const int y);

double arithmetic_mult_double(const double x, const double y);

int arithmetic_div_int(const int x, const int y);

double arithmetic_div_double(const double x, const double y);

int arithmetic_max_int(const int x, const int y);

double arithmetic_max_double(const double x, const double y);

int arithmetic_min_int(const int x, const int y);

double arithmetic_min_double(const double x, const double y);

int arithmetic_average_int(const int x, const int y);

double arithmetic_average_double(const double x, const double y);

int arithmetic_average_int_arr(const int *x, const int n_arr);

void arithmetic_sort_ascending(int *x, const int n_arr);

void arithmetic_sort_descending(int *x, const int n_arr);

void swap_int(int *pnt1, int *pnt2);
bool compare_asc(int a, int b);
bool compare_desc(int a, int b);
int qs_split(int *arr, const int lo, const int hi, compare_t compare);
int push_pop(int push_not_pop, int *p_lo, int *p_hi, const int set_empty);
int quicksort(int *arr, const int n, compare_t compare);

#endif /*ARITHMETIC_H*/
