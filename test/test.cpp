#include "../external/gtest/googletest/include/gtest/gtest.h"
#include "../src/lib/lib/foo.hpp"


TEST(test_case_name, test_name)
{
	float a = sum_two_float(11.5, 5.5);
	ASSERT_EQ(a, 17) << "1 is not equal 0";
}
