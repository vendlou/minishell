#ifndef __TEST_LITERAL_TESTS_HPP__
#define __TEST_LITERAL_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
#include "../header/test_commands.h"
TEST(Test_Literal_Tests, TEST1) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST2) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt || echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST3) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt && echo exist1 || echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST4) {	
	std::string st = "test -e integration_tests/commented_command_tests.txt && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST12) {	
	std::string st = "test -e integration_tests/multiple_commands_tests.txt && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST5) {	
	std::string st = "test -e integration_tests/precedence_tests.txt && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST6) {	
	std::string st = "test -e integration_tests/single_command_tests.txt && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST7) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt && echo exist1 && echo exist2";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST8) {	
	std::string st = "test -e integration_tests/test_symbolic_tests.txt || echo exist1 || echo exit2";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST11) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt && echo exist1 || echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST9) {	
	std::string st = "test -e integration_tests/test_literal_tests.txt || echo exist1 && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Test_Literal_Tests, TEST10) {	
	std::string st = "test -e integration_tests/single_command_tests.txt && echo exist1 && echo exist1";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}



#endif

