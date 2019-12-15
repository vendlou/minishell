#ifndef __MULTIPLE_COMMANDS_TESTS_HPP__
#define __MULTIPLE_COMMANDS_TESTS_HPP__
#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Multiple_commands_tests, TEST1) {	
	std::string st = "echo hello world && echo hi || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST2) {	
	std::string st = "echo hello world && echo hi && echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST3) {	
	std::string st = "echo hello world || echo hi || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST4) {	
	std::string st = "echo hello world || echo hi || echo bye || echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST5) {	
	std::string st = "echo hello world && echo hi || echo bye && echo isright || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST6) {	
	std::string st = "echo hello world || echo hi && echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST7) {	
	std::string st = "echo hello world || echo hi && echo bye || echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST8) {	
	std::string st = "echo hello world || echo hi && echo bye || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST9) {	
	std::string st = "echo hello world && echo hi || echo bye && echo hi || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST10) {	
	std::string st = "echo hello world && echo hi && echo hi || echo bye || echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST11) {	
	std::string st = "echo hello world && echo hi || echo bye && echo isright || echo hi || echo bye";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());

}

TEST(Multiple_commands_tests, TEST12) {	
	std::string st = "echo hello world && echo hi || echo hi || echo bye && echo bye && echo isright";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

#endif
