#ifndef __INPUT_REDIRECTION_TESTS_HPP__
#define __INPUT_REDIRECTION_TESTS_HPP__

#include "../header/base_commands.h"	
#include "../header/commented_commands.h" 
#include "../header/multiple_commands.h" 
#include "../header/single_commands.h"
TEST(Input_Redirection_Tests, TEST1) {
	std::string st = "< inputfile.txt | tr a-z A-Z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST2) {
	std::string st = "< inputfile.txt | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST3) {
	std::string st = "< inputfile.txt | tr -d l";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST4) {
	std::string st = "< inputfile.txt | tr you me";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Input_Redirection_Tests, TEST5) {
	std::string st = "< inputfile.txt | tr you OK";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST6) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr YO yo";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST7) {
	std::string st = "< inputfile.txt | tr A-Z a-z | tr yo YO";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Input_Redirection_Tests, TEST8) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr A-Z a-z";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST9) {
	std::string st = "< inputfile.txt | tr -d a";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST10) {
	std::string st = "< inputfile.txt | tr A-Z a-z | tr -d b";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


TEST(Input_Redirection_Tests, TEST11) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr -d B";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}

TEST(Input_Redirection_Tests, TEST12) {
	std::string st = "< inputfile.txt | tr a-z A-Z | tr A b";
	std::ofstream outfile("infile.txt");
	outfile<<st;
	outfile.close();
	Multiple_Commands* mc = new Multiple_Commands("infile.txt");
	EXPECT_TRUE(mc->do_commands());
}


#endif
