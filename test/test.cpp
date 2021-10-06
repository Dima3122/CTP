#include "../external/gtest/googletest/include/gtest/gtest.h"
#include "../src/lib/lib/calc.hpp"


TEST(test_case_name, test_name)
{
	const float a = 11.5;
	const float b = 5.5;
	const float result = SumTwoFloat(a,b);
	ASSERT_EQ(result, 17) << "1 is not equal 0";
}
