#include <gtest/gtest.h>
#include <index.h>
TEST(Sol2Tests, a_hello_lua)
{
	EXPECT_EQ(a_hello_lua::main(), EXIT_SUCCESS);
}