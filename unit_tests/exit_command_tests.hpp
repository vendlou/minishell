#ifndef __EXIT_COMMAND_TESTS_HPP__
#define __EXIT_COMMAND_TESTS_HPP__

#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Exit_Test, TEST1) {
	Multiple_Commands* cm= new Multiple_Commands("integration_tests/exit_command_tests.txt");
	EXPECT_TRUE(cm->do_commands());
}

#endif
