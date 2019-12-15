#ifndef __SINGLE_COMMAND_TESTS_HPP__
#define __SINGLE_COMMAND_TESTS_HPP__
#include "../header/base_commands.h"
#include "../header/commented_commands.h"
#include "../header/multiple_commands.h"
#include "../header/single_commands.h"
TEST(Single_command_tests, TEST1) {	
	std::string st = "echo hello world";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Single_command_tests, TEST2) {	
	std::string st = "echo hello";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Single_command_tests, TEST3) {	
	std::string st = "echo hello world!";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Single_command_tests, TEST4) {	
	std::string st = "ls -l";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Single_command_tests, TEST5) {	
	std::string st = "echo bye";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


#endif
