#ifndef __COMMENTED_TEST_HPP__
#define __COMMENTED_TEST_HPP__

#include "../header/base_commands.hpp"	
#include "../header/commented_commands.hpp" 
#include "../header/multiple_commands.hpp" 
#include "../header/single_commands.hpp"
TEST(DecoratorTest, StringifyTest) {
	Multiple_Commands cm= new Multiple_Commands("../integration_tests/commented_command_tests.sh");
	EXPECT_EQ(mc->do_command(),"How are you\nI am fine, thanks, and you?\nI am fine two");
}

#endif

