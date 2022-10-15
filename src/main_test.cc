#include <gtest/gtest.h>
#include "main_test.h"

TEST(Math, normal)
{
	ASSERT_EQ(add(2, 3), 6);
	EXPECT_EQ(sub(2, 3), 1);
}


TEST(Fact, simple)
{
	EXPECT_EQ(fact(3), 6);
	EXPECT_EQ(fact(4), 24);
	EXPECT_EQ(fact(5), 24);
}

TEST(Fact, fact_edge_cases)
{
	EXPECT_EQ(fact(-1), -1);
	EXPECT_EQ(fact(-122), -1);
}
