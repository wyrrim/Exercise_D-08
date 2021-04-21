//#define UNITY_INCLUDE_DOUBLE
//#undef UNITY_EXCLUDE_DOUBLE

//#include <float.h>
//#include <limits.h>

#include "unity.h"
#include "arithmetic.h"

void setUp() {}
void tearDown() {}

void test_add_int(void)
{
    TEST_ASSERT_EQUAL_INT(24, arithmetic_add_int(7, 17));
}

void test_add_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(149.1, arithmetic_add_double(13.e1, 19.1));
}

void test_subtract_int(void)
{
    TEST_ASSERT_EQUAL_INT(-6, arithmetic_subtract_int(23, 29));
}

void test_subtract_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(-177.1, arithmetic_subtract_double(13.1, 19.02e1));
}

void test_mult_int(void)
{
    TEST_ASSERT_EQUAL_INT(-39, arithmetic_mult_int(13, -3));
}

void test_mult_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(-3.5, arithmetic_mult_double(2.5, -1.4));
}

void test_div_int(void)
{
    TEST_ASSERT_EQUAL_INT(-6, arithmetic_div_int(20, -3));
    TEST_ASSERT_EQUAL_INT(INT_MAX, arithmetic_div_int(13, 0));
    TEST_ASSERT_EQUAL_INT(INT_MIN, arithmetic_div_int(-13, 0));
}

void test_div_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(-1.5625, arithmetic_div_double(2.5, -1.6));
    TEST_ASSERT_EQUAL_DOUBLE(DBL_MAX, arithmetic_div_double(2.5, 0.));
    TEST_ASSERT_EQUAL_DOUBLE(-DBL_MAX, arithmetic_div_double(-2.5, 0.));
}

void test_max_int(void)
{
    TEST_ASSERT_EQUAL_INT(13, arithmetic_max_int(13, -3));
}

void test_max_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(2.5, arithmetic_max_double(2.5, -1.4));
}

void test_min_int(void)
{
    TEST_ASSERT_EQUAL_INT(-13, arithmetic_min_int(-13, -3));
}

void test_min_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(-2.5, arithmetic_min_double(-2.5, -1.4));
}

void test_average_int(void)
{
    TEST_ASSERT_EQUAL_INT(-4, arithmetic_average_int(-13, 4));
}

void test_average_double(void)
{
    TEST_ASSERT_EQUAL_DOUBLE(-0.55, arithmetic_average_double(-2.5, 1.4));
}

void test_average_int_arr(void)
{
    int arr[] = {-3, 4, -2, 6, 9};
    int brr[] = {-3, 5, -2, 6, 9};
    int crr[] = {-3, 4, -1, 7, 9};
    TEST_ASSERT_EQUAL_INT(3, arithmetic_average_int_arr(arr, 5));
    TEST_ASSERT_EQUAL_INT(3, arithmetic_average_int_arr(brr, 5));
    TEST_ASSERT_EQUAL_INT(3, arithmetic_average_int_arr(crr, 5));
}

void test_average_int_arr_negative(void)
{
    int arr[] = {3, -4, 2, -6, -9};
    int brr[] = {3, -5, 2, -6, -9};
    int crr[] = {3, -4, 1, -7, -9};
    TEST_ASSERT_EQUAL_INT(-3, arithmetic_average_int_arr(arr, 5));
    TEST_ASSERT_EQUAL_INT(-3, arithmetic_average_int_arr(brr, 5));
    TEST_ASSERT_EQUAL_INT(-3, arithmetic_average_int_arr(crr, 5));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_add_int);
    RUN_TEST(test_add_double);
    RUN_TEST(test_subtract_int);
    RUN_TEST(test_subtract_double);
    RUN_TEST(test_mult_int);
    RUN_TEST(test_mult_double);
    RUN_TEST(test_div_int);
    RUN_TEST(test_div_double);
    RUN_TEST(test_max_int);
    RUN_TEST(test_max_double);
    RUN_TEST(test_min_int);
    RUN_TEST(test_min_double);
    RUN_TEST(test_average_int);
    RUN_TEST(test_average_double);
    RUN_TEST(test_average_int_arr);
    RUN_TEST(test_average_int_arr_negative);

    return UNITY_END();
}
