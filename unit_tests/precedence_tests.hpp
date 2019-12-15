#ifndef __TEST_LITERAL_TESTS_HPP__
#define __TEST_LITERAL_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
#include "../header/test_commands.h"
TEST(Test_Literal_Tests, TEST2) {	
	char* st="integration_tests/precedence_tests.txt";
	Multiple_Commands* mc=new Multiple_Commands(st);
	EXPECT_TRUE(mc->do_commands());
}
#endif
