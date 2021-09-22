#include "../external/gtest/googletest/include/gtest/gtest.h"
#include "../src/lib/lib/calc.hpp"


TEST(test_case_name, test_name)
{
	float a = 11.5;
	float b = 5.5;
	float result = sumTwoFloat(a,b);
	ASSERT_EQ(result, 17) << "1 is not equal 0";
}
