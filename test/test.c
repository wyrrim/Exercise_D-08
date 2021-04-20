//#define UNITY_INCLUDE_DOUBLE
//#undef UNITY_EXCLUDE_DOUBLE

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
    TEST_ASSERT_EQUAL_DOUBLE(149., arithmetic_add_double(13.e1, 19.));
}

void test_subtract_int(void)
{
    TEST_ASSERT_EQUAL_INT(-6, arithmetic_subtract_int(23, 29));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_add_int);
    RUN_TEST(test_add_double);
    RUN_TEST(test_subtract_int);

    return UNITY_END();
}
