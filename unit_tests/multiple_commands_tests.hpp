#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__
#include "../header/base_commands.hpp"	
#include "../header/commented_commands.hpp" 
#include "../header/multiple_commands.hpp" 
#include "../header/single_commands.hpp"
TEST(DecoratorTest, StringifyTest) {	
	Commented_Commands* cm=new Commented_Commands("../integration_tests/multiple_commands_tests.sh");
	EXPECT_EQ(cm->do_commands,"hello world\nhi"); 
}
#endif
