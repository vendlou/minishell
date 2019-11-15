#ifndef __COMMENTED_COMMANDS_TESTS_HPP__
#define __COMMENTED_COMMANDS_TESTS_HPP__

#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(commented_command_tests, TEST1) {
	Multiple_Commands* mc= new Multiple_Commands("integration_tests/commented_command_tests.sh");
	EXPECT_TRUE(mc->do_commands());
}

#endif

