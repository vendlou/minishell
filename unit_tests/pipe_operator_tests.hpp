#ifndef __PIPE_OPERATOR_TESTS_HPP__
#define __PIPE_OPERATOR_TESTS_HPP__

#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Pipe_Operator_Tests, TEST1) {
	std::string st = "echo hello | tr a-z A-Z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST2) {
	std::string st = "echo bye | tr a-z A-Z | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST3) {
	std::string st = "echo hello | tr -d l";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST4) {
	std::string st = "echo hello | tr el xy";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Pipe_Operator_Tests, TEST5) {
	std::string st = "echo hello | tr a-z A-Z | tr A-Z a-z | tr a-z A-Z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST6) {
	std::string st = "echo THANK | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST7) {
	std::string st = "echo THANK | tr -d A";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST8) {
	std::string st = "echo hello | tr a-z A-Z | tr -d L";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST9) {
	std::string st = "echo thank | tr an xy | tr a-z A-Z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Pipe_Operator_Tests, TEST10) {
	std::string st = "echo HELLO | tr HE XY | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}
TEST(Pipe_Operator_Tests, TEST11) {
	std::string st = "echo thank you | tr you me";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Pipe_Operator_Tests, TEST12) {
	std::string st = "echo thank you | tr a-z A-Z | tr YOU OK";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Pipe_Operator_Tests, TEST13) {
	std::string st = "echo hello ok | tr a-z A-Z | tr A-Z a-z | tr a-z A-Z | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}



#endif
