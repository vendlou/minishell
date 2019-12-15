#ifndef __TEST_SYMBOLIC_TESTS_HPP__
#define __TEST_SYMBOLIC_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(test_symbolic_tests, TEST1) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ]";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST2) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ] && echo path exit";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST3) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ] || echo path not exists";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST4) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ] && echo path exit || echo path not exists";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST5) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ] || echo path not exists && echo path exit ";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST6) {	
    std::string st = "[ -e integration_tests/test_symbolic_tests.txt ] && echo path exit && echo ok ";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(test_symbolic_tests, TEST7) {	
    std::string st = "[ -e integration_tests/commented_command_tests.txt ]";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST8) {	
    std::string st = "[ -e integration_tests/exit_command_tests.txt ]";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST9) {	
    std::string st = "[ -e integration_tests/multiple_commands_tests.txt ]";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST10) {	
    std::string st = "[ -e integration_tests/precedence_tests.txt ]";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST11) {	
    std::string st = "[ -e integration_tests/multiple_commands_tests.txt ] && echo path exit";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(test_symbolic_tests, TEST12) {	
    std::string st = "[ -e integration_tests/multiple_commands_tests.txt ] && echo path exit";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

#endif
