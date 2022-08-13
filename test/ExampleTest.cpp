#include <gtest/gtest.h>
#include <index.h>
TEST(Sol2Tests, a_opening_a_state)
{
	EXPECT_EQ(a_opening_a_state::main(), EXIT_SUCCESS);
}