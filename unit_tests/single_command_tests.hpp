#ifndef __SINGLE_COMMAND_TESTS_HPP__
#define __SINGLE_COMMAND_TESTS_HPP__
#include "../header/base_commands.h"
#include "../header/commented_commands.h"
#include "../header/multiple_commands.h"
#include "../header/single_commands.h"
TEST(Single_command_tests, TEST1) {	
	char* st="integration_tests/single_command_tests.sh";
	Multiple_Commands* mc=new Multiple_Commands(st);
	EXPECT_TRUE(mc->do_commands());
}
#endif
