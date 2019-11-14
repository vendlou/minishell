#ifndef __SINGLE_TEST_HPP__
#define __SINGLE_TEST_HPP__
#include "../header/base_commands.hpp"
#include "../header/commented_commands.hpp"
#include "../header/multiple_commands.hpp"
#include "../header/single_commands.hpp"
TEST(DecoratorTest, EvaluateTest) {	
	Multiple_Commands* mc=new Multiple_Commands("../integration_tests/single_command_tests.sh");
	EXPECT_EQ(mc->do_command(),"hello");   
}
#endif
