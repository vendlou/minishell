#ifndef __PRECEDENCE_TESTS_HPP__
#define __PRECEDENCE_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Precedence_tests, TEST2) {	
	char* st="integration_tests/precedence_tests.txt";
	Multiple_Commands* mc=new Multiple_Commands(st);
	EXPECT_TRUE(mc->do_commands());
}
#endif
