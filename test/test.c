#include "unity.h"
#include "arithmetic.h"

void setUp() {}
void tearDown() {}

void test_add(void)
{
    TEST_ASSERT_EQUAL_INT(24, arithmetic_add(7, 17));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_add);

    return UNITY_END();
}
