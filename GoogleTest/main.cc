#include <gtest/gtest.h>

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(cmake, dynamic_link_googletest)
{
    EXPECT_TRUE(3.14 > 0.0);
}