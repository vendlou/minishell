#ifndef __MULTIPLE_COMMANDS_TESTS_HPP__
#define __MULTIPLE_COMMANDS_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Multiple_commands_tests, TEST2) {	
	char* st="integration_tests/multiple_commands_tests.sh";
	Multiple_Commands* mc=new Multiple_Commands(st);
	EXPECT_TRUE(mc->do_commands());
}
#endif
