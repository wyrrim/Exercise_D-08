#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <float.h>
#include <limits.h>

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

void arithmetic_sort_ascending(const int *x, const int n_arr);

#endif /*ARITHMETIC_H*/
