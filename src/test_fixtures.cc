#include <gtest/gtest.h>
#include <vector>

class	VecTestFixtureClass: public ::testing::Test
{
	protected:
		virtual	void	SetUp() override
		{
			for (size_t i = 0; i < 10; ++i)
				vec.push_back(i);
		}

		virtual	void	TearDown() override
		{
			vec.clear();
		}
		std::vector<int>	vec;
};


TEST_F(VecTestFixtureClass, push_back)
{
	vec.push_back(10);
	EXPECT_EQ(vec.back(), 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
